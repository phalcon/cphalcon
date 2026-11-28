/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_KERNEL_FCALL_H
#define ZEPHIR_KERNEL_FCALL_H

#include "php_ext.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall_internal.h"

#include <Zend/zend_closures.h>
#include <Zend/zend_hash.h>
#include <Zend/zend.h>

typedef enum _zephir_call_type {
	zephir_fcall_parent,
	zephir_fcall_self,
	zephir_fcall_static,
	zephir_fcall_ce,
	zephir_fcall_method,
	zephir_fcall_function
} zephir_call_type;

/**
 * The class whose code is running, which PHP reads from `EX(func)->op_array.scope`
 * to decide visibility and what `self` means.
 *
 * A C-to-C internal call and a generator step run on a frame that is not
 * their own, so they declare their class in EG(fake_scope). Everything else
 * runs on its own frame. Frames are not walked: a function has no class,
 * which PHP calls the global scope, where zend_get_executed_scope() would
 * answer with the class of the caller.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2734
 */
static zend_always_inline zend_class_entry *zephir_get_calling_scope(void)
{
	zend_execute_data *ex;
	zend_class_entry *scope;

	if (EG(fake_scope)) {
		scope = (zend_class_entry *) EG(fake_scope);
	} else {
		ex    = EG(current_execute_data);
		scope = ex && ex->func ? ex->func->common.scope : NULL;
	}

	/* A closure written in a function binds its capture carrier as $this,
	 * and the engine gives a bound closure without a class the Closure class
	 * as a stand-in scope. PHP's own closure there has no scope at all. A
	 * function body runs in the same stand-in (ZEPHIR_RUN_FUNCTION_BODY). */
	return scope == zend_ce_closure ? NULL : scope;
}

/**
 * The called scope of the running code, what `static` names in it.
 *
 * A closure keeps the called scope of the code that created it. Its frame
 * does not say so when the closure binds its capture carrier as $this, so it
 * is read off the closure object itself, as PHP's own closure handler finds
 * that object.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2825
 */
static zend_always_inline zend_class_entry *zephir_get_called_scope(zend_execute_data *ex)
{
	if (ex && ex->func && ex->func->type == ZEND_INTERNAL_FUNCTION && (ex->func->common.fn_flags & ZEND_ACC_CLOSURE)) {
		zend_object *closure = ZEND_CLOSURE_OBJECT(ex->func);
		zend_class_entry *called_scope = NULL;
		zend_function *function = NULL;
		zend_object *object = NULL;

		if (closure->handlers->get_closure && closure->handlers->get_closure(closure, &called_scope, &function, &object, 1) == SUCCESS) {
			return called_scope;
		}
	}

	return zend_get_called_scope(ex);
}

/**
 * Whether a C-to-C call of a method's copy (`internal-call-transformation`)
 * may run here instead of PHP's call. From PHP 8.6 zend_call_function() throws
 * once the stack limit is reached; the copy then leaves the call to it.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2791
 */
static zend_always_inline bool zephir_has_stack_for_direct_call(void)
{
#if PHP_VERSION_ID >= 80600 && defined(ZEND_CHECK_STACK_LIMIT)
	return !zend_call_stack_overflowed(EG(stack_limit));
#else
	return 1;
#endif
}

/**
 * Whether the method PHP calls on `object` at this call site is the Zephir
 * method whose handler is `handler`, declared in `scope`, so that its C copy
 * can run instead (`internal-call-transformation`).
 *
 * The site's inline cache holds the method resolved for the object's class
 * from the calling class, visibility and private methods of the calling class
 * included, and is only ever filled by PHP's call. Comparing the handler tells
 * an override apart, in Zephir or in PHP, and comparing the class tells apart
 * a PHP class that copied the method from a Zephir trait.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2791
 */
static zend_always_inline bool zephir_cached_method_is(const zephir_method_cache *site, const zval *object, zif_handler handler, const zend_class_entry *scope)
{
	const zend_function *func;

	if (Z_TYPE_P(object) != IS_OBJECT || site->ce != Z_OBJCE_P(object)) {
		return 0;
	}

	if (site->request != ZEPHIR_GLOBAL(request_number) || site->scope != zephir_get_calling_scope()) {
		return 0;
	}

	func = site->func;

	return func->type == ZEND_INTERNAL_FUNCTION
		&& func->internal_function.handler == handler
		&& func->common.scope == scope
		&& zephir_has_stack_for_direct_call();
}

/**
 * An argument left out of a call to a method's C copy. The copy then takes the
 * parameter's default, as the method does when PHP's call leaves it out.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2791
 */
#define ZEPHIR_NO_ARG ((zval *) NULL)

/**
 * The argument slots of a call to a method's C copy (the generated
 * ZEPHIR_*CALL_INTERNAL_METHOD_P* macros). Like the slots of PHP's call frame,
 * a slot holds its own reference to the dereferenced argument and is released
 * after the call, so the copy may separate or overwrite its parameter. The
 * copy gets NULL for an argument left out.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2791
 */
static zend_always_inline zval *zephir_internal_arg(zval *slot, zval *arg)
{
	if (arg == NULL) {
		return NULL;
	}

	ZVAL_COPY_DEREF(slot, arg);

	return slot;
}

static zend_always_inline void zephir_internal_arg_release(zval *slot)
{
	if (slot != NULL) {
		zval_ptr_dtor(slot);
	}
}

/**
 * @addtogroup callfuncs Calling Functions
 * @{
 */
#if defined(_MSC_VER)
#define ZEPHIR_PASS_CALL_PARAMS(x) x + 1
#define ZEPHIR_CALL_NUM_PARAMS(x) ((sizeof(x) - sizeof(x[0]))/sizeof(x[0]))
#define ZEPHIR_FETCH_VA_ARGS NULL,
#else
#define ZEPHIR_PASS_CALL_PARAMS(x) x
#define ZEPHIR_CALL_NUM_PARAMS(x) sizeof(x)/sizeof(zval*)
#define ZEPHIR_FETCH_VA_ARGS
#endif

#define ZEPHIR_CALL_FUNCTION(return_value_ptr, func_name, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_func_aparams(return_value_ptr, func_name, strlen(func_name), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_ZVAL_FUNCTION(return_value_ptr, func_name, cache, cache_slot, ...) \
	do { \
        	zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
        	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
        	ZEPHIR_LAST_CALL_STATUS = zephir_call_zval_func_aparams(return_value_ptr, func_name, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_SET_THIS(zv) ZEPHIR_SET_THIS_OBJ((zv ? Z_OBJ_P(zv) : NULL))
#define ZEPHIR_SET_THIS_EXPLICIT_NULL() \
 	ZVAL_NULL(&EG(current_execute_data)->This); \
	Z_OBJ(EG(current_execute_data)->This) = NULL;

#define ZEPHIR_SET_THIS_OBJ(obj) \
	if (obj) { \
		ZVAL_OBJ(&EG(current_execute_data)->This, obj); \
	} \
	else { ZEPHIR_SET_THIS_EXPLICIT_NULL(); } \

/**
 * Sets up `func` of the frame ZEPHIR_BACKUP_SCOPE() installs for a C-to-C call
 * to an internal method, or to the C copy `internal-call-transformation` makes
 * of a method. Each such method has its own, `zephir_frame_<C function>`, set
 * up once when its class registers and read-only afterwards, so safe under ZTS.
 *
 * To the engine, a frame with `func == NULL` is a generator placeholder frame,
 * and zend_fetch_debug_backtrace() dereferences what it resolves to, so any
 * backtrace taken while the method ran crashed (#2639). An internal function
 * without a name crashed as well: a warning raised in the method's own code is
 * prefixed with get_active_function_name(), which reads the name unchecked
 * (#2791). Named after the method and scoped to its class, the frame gives the
 * warning the prefix the method's own call gives it, and shows in a backtrace
 * as that call does, without the arguments: it has no slots for them.
 */
void zephir_init_internal_frame(zend_internal_function *frame, zend_class_entry *scope, const char *name, size_t name_length);

#define ZEPHIR_BACKUP_SCOPE(frame) \
	const zend_class_entry *old_scope = EG(fake_scope); \
	zend_execute_data *old_call = execute_data; \
	zend_execute_data *old_execute_data = EG(current_execute_data), new_execute_data; \
	if (!EG(current_execute_data)) { \
		memset(&new_execute_data, 0, sizeof(zend_execute_data)); \
	} else { \
		new_execute_data = *EG(current_execute_data); \
		new_execute_data.prev_execute_data = EG(current_execute_data); \
		new_execute_data.call = NULL; \
		new_execute_data.opline = NULL; \
	} \
	new_execute_data.func = (zend_function *) (frame); \
	/* Drop the copied frame's call flags and argument count. ZEND_CALL_INFO() \
	 * is Z_TYPE_INFO(This) and ZEND_CALL_NUM_ARGS() is This.u2.num_args, so a \
	 * frame copied from the caller would claim the caller's arguments -- and \
	 * this frame is a bare struct with no VAR/CV slots behind it, so reading \
	 * them (debug_backtrace() does) runs off the end of it. The immediately \
	 * following ZEPHIR_SET_THIS() writes the real `This`; neither ZVAL_OBJ nor \
	 * ZVAL_NULL touches u2, so num_args stays 0. */ \
	Z_TYPE_INFO(new_execute_data.This) = IS_UNDEF; \
	ZEND_CALL_NUM_ARGS(&new_execute_data) = 0; \
	execute_data = EG(current_execute_data) = &new_execute_data;

#define ZEPHIR_RESTORE_SCOPE() \
	EG(fake_scope) = (zend_class_entry *) old_scope; \
	execute_data = old_call; \
	EG(current_execute_data) = old_execute_data;

/* Runs right after ZEPHIR_BACKUP_SCOPE() and ZEPHIR_SET_THIS*(), so the
 * current frame is the one they installed. With `This` an object the called
 * class is its class; a static call keeps the called class in `This`, as the
 * engine's frame of a static method does. */
#define ZEPHIR_SET_SCOPE(_scope, _scope_called) \
	EG(fake_scope) = _scope; \
	if (Z_TYPE(EG(current_execute_data)->This) != IS_OBJECT) { \
		Z_CE(EG(current_execute_data)->This) = _scope_called; \
	}

/* End internal calls */

#define ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(func_name, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_zval_function(return_value, func_name, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_FUNCTION(func_name, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_function(return_value, func_name, strlen(func_name), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_METHOD_WITHOUT_OBSERVE(return_value_ptr, object, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_METHOD(return_value_ptr, object, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

/**
 * The `_ZVAL` macros take the method name from a variable, and pass it on as it
 * was spelled: `__call()` is defined to receive the name as written, and the
 * lookup that dispatches the call folds the case itself (see populate_fcic()
 * in kernel/fcall.c). They used to lower-case it into a copy on every call.
 *
 * The variable arrives as the `zval *` the backend hands out for any variable
 * kind: a local, a parameter, the companion zval of a native string. It is
 * copied before the result is cleared, because in `let name = obj->{name}()`
 * the variable naming the method is the very one the call writes to.
 * zephir_call_class_method_zval() then requires a string, as PHP does.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2715
 * @see https://github.com/zephir-lang/zephir/issues/2723
 */
#define ZEPHIR_RETURN_CALL_METHOD_ZVAL(object, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_zval(return_value, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, method, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_METHOD_ZVAL(return_value_ptr, object, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval(return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, &method_name_, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_CALL_PARENT(return_value_ptr, class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, class_entry, zephir_fcall_parent, this_ptr, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_METHOD(object, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_STATIC(method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, getThis(), method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_PARENT(class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, class_entry, zephir_fcall_parent, this_ptr, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_SELF(return_value_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, zephir_get_calling_scope(), zephir_fcall_self, getThis(), method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_SELF(method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, zephir_get_calling_scope(), zephir_fcall_self, getThis(), method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_STATIC(return_value_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, getThis(), method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_CE_STATIC(return_value_ptr, class_entry, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, class_entry, zephir_fcall_ce, NULL, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_CE_STATIC(class_entry, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, class_entry, zephir_fcall_ce, NULL, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

/**
 * The `_CACHED` forms of the calls above, for a call site whose method name is
 * known at compile time. `cache` is the site's own record, declared in the
 * function that holds the site: a later call on the same class from the same
 * class runs the method it holds without looking it up.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2790
 */
#define ZEPHIR_CALL_METHOD_CACHED(return_value_ptr, object, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_cached(return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_METHOD_CACHED(object, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_cached(return_value, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_PARENT_CACHED(return_value_ptr, class_entry, this_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_cached(return_value_ptr, class_entry, zephir_fcall_parent, this_ptr, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_PARENT_CACHED(class_entry, this_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_cached(return_value, class_entry, zephir_fcall_parent, this_ptr, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_SELF_CACHED(return_value_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_cached(return_value_ptr, zephir_get_calling_scope(), zephir_fcall_self, getThis(), method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_SELF_CACHED(method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_cached(return_value, zephir_get_calling_scope(), zephir_fcall_self, getThis(), method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_STATIC_CACHED(return_value_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_cached(return_value_ptr, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, getThis(), method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_STATIC_CACHED(method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_cached(return_value, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, getThis(), method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_CE_STATIC_CACHED(return_value_ptr, class_entry, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_cached(return_value_ptr, class_entry, zephir_fcall_ce, NULL, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_CE_STATIC_CACHED(class_entry, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_cached(return_value, class_entry, zephir_fcall_ce, NULL, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

/**
 * `Class::method()` for a method that may not be static: a constructor, a
 * non-static method or one only known at run time. PHP runs a non-static
 * method on the current `$this` when that is an instance of the class the call
 * names, so `this_ptr` goes along; the kernel drops it otherwise.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2854
 */
#define ZEPHIR_CALL_CE_STATIC_THIS_CACHED(return_value_ptr, class_entry, this_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_cached(return_value_ptr, class_entry, zephir_fcall_ce, this_ptr, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_CE_STATIC_THIS_CACHED(class_entry, this_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_cached(return_value, class_entry, zephir_fcall_ce, this_ptr, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

/**
 * Static calls whose method name is a variable: `{cls}::{name}()`,
 * `Cls::{name}()`, `self::{name}()`, `parent::{name}()` and
 * `static::{name}()`. Each passes the class PHP looks the method up in, and the
 * current `$this`, which a non-static method runs with when it is an instance
 * of that class. `self::` is the declaring class, as `class_entry` spells it,
 * and `static::` the called one.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2723
 */
#define ZEPHIR_CALL_CE_STATIC_ZVAL(return_value_ptr, class_entry, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval(return_value_ptr, class_entry, zephir_fcall_ce, getThis(), &method_name_, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(class_entry, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_zval(return_value, class_entry, zephir_fcall_ce, getThis(), method, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_SELF_ZVAL(return_value_ptr, class_entry, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval(return_value_ptr, class_entry, zephir_fcall_self, getThis(), &method_name_, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_RETURN_CALL_SELF_ZVAL(class_entry, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_zval(return_value, class_entry, zephir_fcall_self, getThis(), method, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_PARENT_ZVAL(return_value_ptr, class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval(return_value_ptr, class_entry, zephir_fcall_parent, this_ptr, &method_name_, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_RETURN_CALL_PARENT_ZVAL(class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_zval(return_value, class_entry, zephir_fcall_parent, this_ptr, method, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_STATIC_ZVAL(return_value_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval(return_value_ptr, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, getThis(), &method_name_, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_RETURN_CALL_STATIC_ZVAL(method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_zval(return_value, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, getThis(), method, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

/**
 * The `self::` and `static::` calls above for a closure, which passes on the
 * object it was created with: its own $this may be its capture carrier.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2825
 */
#define ZEPHIR_CALL_SELF_THIS_CACHED(return_value_ptr, this_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_cached(return_value_ptr, zephir_get_calling_scope(), zephir_fcall_self, this_ptr, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_SELF_THIS_CACHED(this_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_cached(return_value, zephir_get_calling_scope(), zephir_fcall_self, this_ptr, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_STATIC_THIS_CACHED(return_value_ptr, this_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_cached(return_value_ptr, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, this_ptr, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_STATIC_THIS_CACHED(this_ptr, method, cache, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_cached(return_value, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, this_ptr, method, strlen(method), cache, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_SELF_THIS_ZVAL(return_value_ptr, class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval(return_value_ptr, class_entry, zephir_fcall_self, this_ptr, &method_name_, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_RETURN_CALL_SELF_THIS_ZVAL(class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_zval(return_value, class_entry, zephir_fcall_self, this_ptr, method, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_CALL_STATIC_THIS_ZVAL(return_value_ptr, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval(return_value_ptr, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, this_ptr, &method_name_, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_RETURN_CALL_STATIC_THIS_ZVAL(this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_zval(return_value, zephir_get_called_scope(EG(current_execute_data)), zephir_fcall_static, this_ptr, method, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

/* `Class::{name}()` and `{cls}::{name}()` in a closure (#2854). */
#define ZEPHIR_CALL_CE_STATIC_THIS_ZVAL(return_value_ptr, class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval(return_value_ptr, class_entry, zephir_fcall_ce, this_ptr, &method_name_, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_RETURN_CALL_CE_STATIC_THIS_ZVAL(class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method_zval(return_value, class_entry, zephir_fcall_ce, this_ptr, method, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

/** Use these functions to call functions in the PHP userland using an arbitrary zval as callable */
#define ZEPHIR_CALL_USER_FUNC(return_value, handler) ZEPHIR_CALL_USER_FUNC_ARGS(return_value, handler, NULL)
#define ZEPHIR_CALL_USER_FUNC_ARGS(return_value, handler, args) \
	do { \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_user_func_checked(return_value, "call_user_func", handler, args); \
	} while (0)
#define ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, handler, params) \
	do { \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_user_func_checked(return_value, "call_user_func_array", handler, params); \
	} while (0)

#define ZEPHIR_CALL_USER_FUNC_ARRAY_NOEX(return_value, handler, params) \
	do { \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_user_func_array_noex(return_value, handler, params); \
	} while (0)

int zephir_call_func_aparams(zval *return_value_ptr, const char *func_name, uint32_t func_length,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint32_t param_count, zval **params);

/**
 * The calls with named arguments: `params` are the positional ones and
 * `named_params` the rest by name. The engine binds them as PHP does, by the
 * parameter names of the function or method actually called, with the declared
 * default for one skipped. A method call passes no class entry, and the class
 * of its object is used.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2824
 */
int zephir_call_func_named(zval *return_value_ptr, const char *func_name, uint32_t func_length,
	HashTable *named_params, uint32_t param_count, zval **params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

int zephir_call_zval_func_named(zval *return_value_ptr, zval *func_name,
	HashTable *named_params, uint32_t param_count, zval **params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

int zephir_call_class_method_named(
	zval *return_value_ptr,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	const char *method_name,
	uint32_t method_len,
	HashTable *named_params,
	uint32_t param_count,
	zval **params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

int zephir_call_class_method_zval_named(
	zval *return_value_ptr,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	zval *method,
	HashTable *named_params,
	uint32_t param_count,
	zval **params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

/**
 * Bracket a call that writes `return_value`, as the zephir_return_call_*()
 * functions do: release what it held, and leave NULL when the call throws.
 */
static zend_always_inline void zephir_return_call_begin(zval *return_value)
{
	zval_ptr_dtor(return_value);
	ZVAL_UNDEF(return_value);
}

static zend_always_inline int zephir_return_call_end(zval *return_value, int status)
{
	if (status == FAILURE && EG(exception)) {
		ZVAL_NULL(return_value);
	}

	return status;
}

#define ZEPHIR_CALL_FUNCTION_NAMED(return_value_ptr, func_name, named, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_func_named(return_value_ptr, func_name, strlen(func_name), named, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_FUNCTION_NAMED(func_name, named, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zephir_return_call_begin(return_value); \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_end(return_value, zephir_call_func_named(return_value, func_name, strlen(func_name), named, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_))); \
	} while (0)

#define ZEPHIR_CALL_ZVAL_FUNCTION_NAMED(return_value_ptr, func_name, named, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_zval_func_named(return_value_ptr, func_name, named, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_ZVAL_FUNCTION_NAMED(func_name, named, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zephir_return_call_begin(return_value); \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_end(return_value, zephir_call_zval_func_named(return_value, func_name, named, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_))); \
	} while (0)

#define ZEPHIR_CALL_CLASS_METHOD_NAMED(return_value_ptr, type, class_entry, object, method, named, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_named(return_value_ptr, class_entry, type, object, method, strlen(method), named, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#define ZEPHIR_RETURN_CALL_CLASS_METHOD_NAMED(type, class_entry, object, method, named, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zephir_return_call_begin(return_value); \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_end(return_value, zephir_call_class_method_named(return_value, class_entry, type, object, method, strlen(method), named, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_))); \
	} while (0)

#define ZEPHIR_CALL_CLASS_METHOD_ZVAL_NAMED(return_value_ptr, type, class_entry, object, method, named, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_zval_named(return_value_ptr, class_entry, type, object, &method_name_, named, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

#define ZEPHIR_RETURN_CALL_CLASS_METHOD_ZVAL_NAMED(type, class_entry, object, method, named, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		zval method_name_; \
		ZVAL_COPY(&method_name_, method); \
		zephir_return_call_begin(return_value); \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_end(return_value, zephir_call_class_method_zval_named(return_value, class_entry, type, object, &method_name_, named, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_))); \
		zval_ptr_dtor(&method_name_); \
	} while (0)

int zephir_call_zval_func_aparams(zval *return_value_ptr, zval *func_name,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint32_t param_count, zval **params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

int zephir_call_class_method_aparams(
    zval *return_value_ptr,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	const char *method_name,
	uint32_t method_len,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

int zephir_call_class_method_zval(
	zval *return_value_ptr,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	zval *method,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

int zephir_call_class_method_cached(
	zval *return_value_ptr,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	const char *method_name,
	uint32_t method_len,
	zephir_method_cache *cache,
	uint32_t param_count,
	zval **params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_return_call_function(
	zval *return_value,
	const char *func,
	uint32_t func_len,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params
) {
	zval rv, *rvp = return_value ? return_value : &rv;
	int status;

	ZVAL_UNDEF(&rv);

	if (return_value) {
		zval_ptr_dtor(return_value);
		ZVAL_UNDEF(return_value);
	}

	status = zephir_call_func_aparams(rvp, func, func_len, cache_entry, cache_slot, param_count, params);

	if (status == FAILURE) {
		if (return_value) {
			if (EG(exception)) {
				ZVAL_NULL(return_value);
			}
		} else {
			zval_ptr_dtor(&rv);
		}

		return FAILURE;
	}

	if (!return_value) {
		zval_ptr_dtor(&rv);
	}

	return SUCCESS;
}

ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_return_call_zval_function(zval *return_value,
	zval *func, zephir_fcall_cache_entry **cache_entry, int cache_slot, uint32_t param_count, zval **params)
{
	zval rv, *rvp = return_value ? return_value : &rv;
	int status;

	ZVAL_UNDEF(&rv);

	if (return_value) {
		zval_ptr_dtor(return_value);
		ZVAL_UNDEF(return_value);
	}

	status = zephir_call_zval_func_aparams(rvp, func, cache_entry, cache_slot, param_count, params);

	if (status == FAILURE) {
		if (return_value) {
			if (EG(exception)) {
				ZVAL_NULL(return_value);
			}
		} else {
			zval_ptr_dtor(&rv);
		}

		return FAILURE;
	}

	if (!return_value) {
		zval_ptr_dtor(&rv);
	}

	return SUCCESS;
}

ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_return_call_class_method(
	zval *return_value,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	const char *method_name,
	uint32_t method_len,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params
) {
	zval rv, *rvp = return_value ? return_value : &rv;
	int status;

	ZVAL_UNDEF(&rv);

	if (return_value) {
		zval_ptr_dtor(return_value);
		ZVAL_UNDEF(return_value);
	}

	status = zephir_call_class_method_aparams(rvp, ce, type, object, method_name, method_len, cache_entry, cache_slot, param_count, params);

	if (status == FAILURE) {
		if (return_value) {
			if (EG(exception)) {
				ZVAL_NULL(return_value);
			}
		} else {
			zval_ptr_dtor(&rv);
		}

		return FAILURE;
	}

	if (!return_value) {
		zval_ptr_dtor(&rv);
	}

	return SUCCESS;
}

ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_return_call_class_method_cached(
	zval *return_value,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	const char *method_name,
	uint32_t method_len,
	zephir_method_cache *cache,
	uint32_t param_count,
	zval **params
) {
	zval rv, *rvp = return_value ? return_value : &rv;
	int status;

	ZVAL_UNDEF(&rv);

	if (return_value) {
		zval_ptr_dtor(return_value);
		ZVAL_UNDEF(return_value);
	}

	status = zephir_call_class_method_cached(rvp, ce, type, object, method_name, method_len, cache, param_count, params);

	if (status == FAILURE) {
		if (return_value) {
			if (EG(exception)) {
				ZVAL_NULL(return_value);
			}
		} else {
			zval_ptr_dtor(&rv);
		}

		return FAILURE;
	}

	if (!return_value) {
		zval_ptr_dtor(&rv);
	}

	return SUCCESS;
}

ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_return_call_class_method_zval(
	zval *return_value,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	zval *method,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params
) {
	zval rv, *rvp = return_value ? return_value : &rv;
	int status;

	ZVAL_UNDEF(&rv);

	if (return_value) {
		zval_ptr_dtor(return_value);
		ZVAL_UNDEF(return_value);
	}

	status = zephir_call_class_method_zval(rvp, ce, type, object, method, cache_entry, cache_slot, param_count, params);

	if (status == FAILURE) {
		if (return_value) {
			if (EG(exception)) {
				ZVAL_NULL(return_value);
			}
		} else {
			zval_ptr_dtor(&rv);
		}

		return FAILURE;
	}

	if (!return_value) {
		zval_ptr_dtor(&rv);
	}

	return SUCCESS;
}

/** Fast call_user_func_array/call_user_func */
int zephir_call_user_func(zval *return_value, const char *caller, zval *handler, zval *params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

/**
 * Replaces call_user_func_array avoiding function lookup
 */
ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_call_user_func_checked(zval *return_value, const char *caller, zval *handler, zval *params)
{
	int status = zephir_call_user_func(return_value, caller, handler, params);
	return (EG(exception)) ? FAILURE : status;
}

ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_call_user_func_array(zval *return_value, zval *handler, zval *params)
{
	return zephir_call_user_func_checked(return_value, "call_user_func_array", handler, params);
}

int zephir_has_constructor_ce(const zend_class_entry *ce) ZEPHIR_ATTR_PURE ZEPHIR_ATTR_NONNULL;

/**
 * Throws an Error, releases the object and returns FAILURE when `new` may not
 * construct it from the calling scope, mirroring PHP's "new" operator.
 *
 * @see https://github.com/zephir-lang/zephir/issues/882
 * @see https://github.com/zephir-lang/zephir/issues/2802
 */
int zephir_check_constructor_access(zval *object) ZEPHIR_ATTR_NONNULL;

/**
 * `new` evaluates the arguments and runs the constructor with the object
 * marked as destructed, and lifts the mark once they return. An exception
 * leaves the mark, so an object that was never constructed is freed without
 * its destructor, as PHP's cleanup of an unfinished `new` marks it. A
 * non-object is one object_init_ex() refused, and has nothing to mark.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2802
 */
static zend_always_inline void zephir_constructor_start(zval *object)
{
	if (EXPECTED(Z_TYPE_P(object) == IS_OBJECT)) {
		GC_ADD_FLAGS(Z_OBJ_P(object), IS_OBJ_DESTRUCTOR_CALLED);
	}
}

static zend_always_inline void zephir_constructor_finish(zval *object)
{
	if (EXPECTED(Z_TYPE_P(object) == IS_OBJECT)) {
		GC_DEL_FLAGS(Z_OBJ_P(object), IS_OBJ_DESTRUCTOR_CALLED);
	}
}

/**
 * Throws an Error and returns FAILURE when the object's __clone() is not
 * accessible from the calling class, mirroring PHP's "clone" operator.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2734
 */
int zephir_check_clone_access(const zval *object) ZEPHIR_ATTR_NONNULL;

ZEPHIR_ATTR_WARN_UNUSED_RESULT ZEPHIR_ATTR_NONNULL static inline int zephir_has_constructor(const zval *object)
{
	return Z_TYPE_P(object) == IS_OBJECT ? zephir_has_constructor_ce(Z_OBJCE_P(object)) : 0;
}

#define zephir_check_call_status() \
	do { \
		if (ZEPHIR_LAST_CALL_STATUS == FAILURE) { \
			ZEPHIR_MM_RESTORE(); \
			return; \
		} \
	} while(0)

#define zephir_check_call_status_or_jump(label) \
	do { \
		if (ZEPHIR_LAST_CALL_STATUS == FAILURE) { \
			if (EG(exception)) { \
				goto label; \
			} else { \
				ZEPHIR_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#ifdef ZEPHIR_RELEASE
#define ZEPHIR_TEMP_PARAM_COPY 0
#define zephir_check_temp_parameter(param) do { if (Z_REFCOUNT(param) > 1) zval_copy_ctor(&param); else ZVAL_NULL(&param); } while(0)
#else
#define ZEPHIR_TEMP_PARAM_COPY 1
#define zephir_check_temp_parameter(param)
#endif

void zephir_eval_php(zval *str, zval *retval_ptr, char *context);

#endif /* ZEPHIR_KERNEL_FCALL_H */
