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

#include <php.h>
#include "php_ext.h"

#include <Zend/zend_API.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_execute.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"
#include "kernel/variables.h"

/* See the declaration in kernel/fcall.h for what the frame stands in for. */
void zephir_init_internal_frame(zend_internal_function *frame, zend_class_entry *scope, const char *name, size_t name_length)
{
	memset(frame, 0, sizeof(zend_internal_function));
	frame->type          = ZEND_INTERNAL_FUNCTION;
	frame->function_name = zend_string_init_interned(name, name_length, 1);
	frame->scope         = scope;
}

int zephir_has_constructor_ce(const zend_class_entry *ce)
{
	do {
		if (ce->constructor != NULL) {
			return 1;
		}

		ce = ce->parent;
	} while (ce);

	return 0;
}

/**
 * Creates a unique key to cache the current method/function call address for the current scope
 */
static int zephir_make_fcall_key(zend_string* s, zephir_call_type type, zend_class_entry *ce, zval *function, const zend_class_entry* called_scope)
{
	const zend_class_entry *calling_scope;
	unsigned char t;

	/* `self` and `parent` are keyed by the class populate_fcic() searches,
	 * which is the class the call is written in or its parent: the executed
	 * scope is not that class inside an internal call or a generator (#2734). */
	switch (type) {
		case zephir_fcall_parent:
			if (UNEXPECTED(!ce || !ce->parent)) {
				return FAILURE;
			}

			calling_scope = ce->parent;
			break;

		case zephir_fcall_static:
			calling_scope = called_scope;
			if (UNEXPECTED(!calling_scope)) {
				return FAILURE;
			}

			break;

		case zephir_fcall_self:
			if (UNEXPECTED(!ce)) {
				return FAILURE;
			}

			calling_scope = ce;
			break;

		case zephir_fcall_function:
			/* Only a plain function name resolves the same from every scope:
			 * a cached `[obj, "m"]` would lose its object and a cached
			 * "C::m" its visibility check (#2734). */
			if (Z_TYPE_P(function) != IS_STRING || memchr(Z_STRVAL_P(function), ':', Z_STRLEN_P(function))) {
				return FAILURE;
			}

			calling_scope = NULL;
			called_scope  = NULL;
			break;

		case zephir_fcall_ce:
			calling_scope = ce;
			called_scope  = ce;
			break;

		case zephir_fcall_method:
			if (Z_TYPE_P(function) == IS_OBJECT) {
				return FAILURE;
			}

			calling_scope = ce;
			called_scope  = ce;
			break;

		default:
			return FAILURE;
	}

	if (called_scope == calling_scope) {
	/* Calls within the same scope, this won't trigger magic methods or failures due to restricted visibility */
		t = 0;
	}
	else if (called_scope && calling_scope && (instanceof_function(called_scope, calling_scope) || instanceof_function(calling_scope, called_scope))) {
	/* Calls within the same chain of inheritance; can call protected methods */
		t = 1;
	}
	else {
		/* Can safely call only public methods */
		t = 2;
	}

	{
		char* cls      = calling_scope ? ZSTR_VAL(calling_scope->name) : "";
		size_t cls_len = calling_scope ? ZSTR_LEN(calling_scope->name) : 0;
		char* mth      = NULL;
		size_t mth_len = 0;
		char* buf;

		if (Z_TYPE_P(function) == IS_STRING) {
			mth     = Z_STRVAL_P(function);
			mth_len = Z_STRLEN_P(function);
		} else if (Z_TYPE_P(function) == IS_ARRAY) {
			zval *method;
			HashTable *function_hash = Z_ARRVAL_P(function);

			if (
				function_hash->nNumOfElements == 2 &&
				((method = zend_hash_index_find(function_hash, 1)) != NULL) &&
				Z_TYPE_P(method) == IS_STRING
			) {
				mth     = Z_STRVAL_P(method);
				mth_len = Z_STRLEN_P(method);
			}
		}

		if (cls_len + 1 + mth_len + sizeof(unsigned char) > 255) {
			return FAILURE;
		}

		ZSTR_LEN(s) = cls_len + 1 + mth_len + sizeof(unsigned char);
		buf = ZSTR_VAL(s);
		zend_str_tolower_copy(buf, cls, cls_len + 1);
		zend_str_tolower_copy(buf + cls_len + 1, mth, mth_len);
		buf[cls_len + 1 + mth_len] = t;
		buf[cls_len + 1 + mth_len + sizeof(t)] = '\0';
	}

	ZSTR_H(s) = zend_hash_func(ZSTR_VAL(s), ZSTR_LEN(s));
	return SUCCESS;
}

/**
 * Builds the callable zend_call_function() falls back to when no handler was
 * resolved up front: a magic `__call()` / `__callStatic()` dispatch.
 *
 * `self`, `parent` and `static` are written as the class they stand for
 * whenever the call knows it. As keywords the engine resolves them against
 * the nearest userland frame, which an extension method never is, so they
 * named the caller's class instead, and PHP 8.2+ deprecates them in callables.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2723
 */
static void resolve_callable(zval* retval, zephir_call_type type, zend_class_entry *ce, zval *object, zval *function)
{
	if (type == zephir_fcall_function || IS_ARRAY == Z_TYPE_P(function) || IS_OBJECT == Z_TYPE_P(function)) {
		ZVAL_COPY(retval, function);
		return;
	}

	array_init_size(retval, 2);
	zend_hash_real_init(Z_ARRVAL_P(retval), 1);
	ZEND_HASH_FILL_PACKED(Z_ARRVAL_P(retval)) {
		zval q;
		switch (type) {
			case zephir_fcall_parent:
				if (ce && ce->parent) {
					ZVAL_STR_COPY(&q, ce->parent->name);
				} else {
					ZVAL_STR_COPY(&q, i_parent);
				}
				ZEND_HASH_FILL_ADD(&q);
				break;

			case zephir_fcall_self:
				ZVAL_STR_COPY(&q, ce ? ce->name : i_self);
				ZEND_HASH_FILL_ADD(&q);
				break;

			case zephir_fcall_static:
				ZVAL_STR_COPY(&q, ce ? ce->name : i_static);
				ZEND_HASH_FILL_ADD(&q);
				break;

			case zephir_fcall_ce:
				assert(ce);
				zend_string_addref(ce->name);
				ZVAL_STR(&q, ce->name);
				ZEND_HASH_FILL_ADD(&q);
				break;

			default:
				assert(object);
				Z_TRY_ADDREF_P(object);
				ZEND_HASH_FILL_ADD(object);
				break;
		}

		Z_TRY_ADDREF_P(function);
		ZEND_HASH_FILL_ADD(function);
	} ZEND_HASH_FILL_END();
}

/**
 * Fills the fcall info cache (scopes, object, handler) for a call.
 *
 * When `cached_handler` is non-NULL the already-resolved function is reused
 * instead of re-running the `zend_hash_find_ptr` method-table lookups: the
 * scope assignments are unchanged, only the redundant resolution is skipped.
 * See the FastCall investigation: https://github.com/zephir-lang/zephir/issues/1510
 */
/**
 * Resolves the handler a call will use, so the engine can skip its own lookup.
 *
 * `func` carries the method name as it was written at the call site, while
 * `function_table` is keyed by the lower-cased name, so every lookup here has
 * to fold the case the way PHP folds it: `zend_std_get_method()` lower-cases
 * for the table and keeps the original only for the `__call()` trampoline, and
 * `zend_is_callable_check_method()` uses this very function.
 *
 * At most one of the lookups below runs per call, and none of them runs once a
 * handler has been cached, so the fold costs one `zend_string_tolower()` per
 * cache miss.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2715
 */
static void populate_fcic(zend_fcall_info_cache* fcic, zephir_call_type type, zend_class_entry* ce, zval *this_ptr, zval *func, zend_class_entry* called_scope, zend_function* cached_handler)
{
	zend_class_entry* calling_scope;

	fcic->function_handler = NULL;

	if (type == zephir_fcall_function && Z_TYPE_P(func) == IS_STRING) {
		fcic->called_scope  = NULL;
		fcic->calling_scope = NULL;
		fcic->object        = NULL;
		return;
	}

	fcic->called_scope = called_scope;
	calling_scope = zephir_get_called_scope(EG(current_execute_data));
	fcic->object = this_ptr ? Z_OBJ_P(this_ptr) : NULL;
	switch (type) {
		case zephir_fcall_parent:
			if (ce && Z_TYPE_P(func) == IS_STRING) {
				fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&ce->parent->function_table, Z_STR_P(func));
				/* The declaring class's parent, not the parent of whatever class
				 * the object is: an undefined method and the __call() check both
				 * have to name the class PHP names (#2723). */
				fcic->calling_scope = ce->parent;
				break;
			} else if (EXPECTED(calling_scope && calling_scope->parent)) {
				if (Z_TYPE_P(func) == IS_STRING) {
					fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&calling_scope->parent->function_table, Z_STR_P(func));
				}
				fcic->calling_scope = calling_scope->parent;
			} else {
				return;
			}

			if (UNEXPECTED(!calling_scope || !calling_scope->parent)) {
				return;
			}

			fcic->calling_scope = calling_scope->parent;
			break;

		case zephir_fcall_static:
			if (ce && Z_TYPE_P(func) == IS_STRING) {
				fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&ce->function_table, Z_STR_P(func));
				fcic->calling_scope = ce;
			} else if (calling_scope && Z_TYPE_P(func) == IS_STRING) {
				fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&calling_scope->function_table, Z_STR_P(func));
				fcic->calling_scope = called_scope;
			}

			break;

		case zephir_fcall_self:
			if (ce && Z_TYPE_P(func) == IS_STRING) {
				fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&ce->function_table, Z_STR_P(func));
				fcic->calling_scope = ce;
			} else if (calling_scope && Z_TYPE_P(func) == IS_STRING) {
				fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&calling_scope->function_table, Z_STR_P(func));
				// TODO: Review when error will be enabled in zend_is_callable_ex() calls
				//fcic->object = zend_get_this_object(EG(current_execute_data));
				//fcic->called_scope = zend_get_called_scope(EG(current_execute_data));
				fcic->calling_scope = calling_scope;
			}
			break;

		case zephir_fcall_ce:
			/**
			 * @see https://github.com/zephir-lang/zephir/issues/2321
			 * Set the calling/called scope up-front so the engine resolves
			 * visibility against the class entry we were asked to use, even
			 * when no function handler can be found in the PHP 8 fast path.
			 */
			fcic->calling_scope = ce;
			fcic->called_scope  = ce;

#if PHP_VERSION_ID >= 80000
			if (Z_TYPE_P(func) == IS_STRING) {
				if (ce) {
					fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&ce->function_table, Z_STR_P(func));
				} else if (calling_scope) {
					fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&calling_scope->function_table, Z_STR_P(func));
					fcic->calling_scope = calling_scope;
				}
			}
#endif
			break;

		case zephir_fcall_function:
		case zephir_fcall_method:
			if (Z_TYPE_P(func) == IS_OBJECT) {
				/**
				 * @see https://github.com/zephir-lang/zephir/issues/2321
				 * Seed `calling_scope` from `this_ptr` first so that closures
				 * bound to the enclosing instance retain access to its
				 * private/protected members. `get_closure` may overwrite the
				 * scope when the value is itself a Closure.
				 */
				if (Z_TYPE_P(this_ptr) == IS_OBJECT) {
					fcic->calling_scope = Z_OBJCE_P(this_ptr);
				}

#if PHP_VERSION_ID >= 80000
				if (
					Z_OBJ_HANDLER_P(func, get_closure)
					&& Z_OBJ_HANDLER_P(func, get_closure)(Z_OBJ_P(func), &fcic->calling_scope, &fcic->function_handler, &fcic->object, 1) == SUCCESS
				) {
#else
				if (
					Z_OBJ_HANDLER_P(func, get_closure)
					&& Z_OBJ_HANDLER_P(func, get_closure)(func, &fcic->calling_scope, &fcic->function_handler, &fcic->object) == SUCCESS
				) {
#endif
					fcic->called_scope = fcic->calling_scope;
					break;
				}
			} else if (Z_TYPE_P(func) == IS_STRING) {
				/**
				 * @see https://github.com/zephir-lang/zephir/issues/2321
				 * `[this, 'methodName']` style callback. When `ce` is set,
				 * pin the calling scope to it so the engine permits access
				 * to private/protected methods declared on `ce`.
				 *
				 * If `ce` is NULL we still need to leave `fcic` in a
				 * well-defined state — `fcic` is stack-allocated by the
				 * caller and not zeroed, so skipping the writes here would
				 * leak whatever a prior `zend_is_callable_at_frame()` left
				 * behind (or stack garbage on its failure path) into
				 * `zend_call_function()`. Derive scope from `this_ptr`,
				 * matching the pre-#2321 fallback.
				 */
				if (ce) {
					fcic->calling_scope = ce;

#if PHP_VERSION_ID >= 80000
					fcic->function_handler = cached_handler ? cached_handler : zend_hash_find_ptr_lc(&ce->function_table, Z_STR_P(func));
#endif
				} else {
					fcic->calling_scope = this_ptr ? Z_OBJCE_P(this_ptr) : NULL;
				}

				fcic->called_scope = fcic->calling_scope;
			}

			break;
	}
}

/* zend_visibility_string() is not exported. */
static const char *zephir_visibility_string(uint32_t fn_flags)
{
	if (fn_flags & ZEND_ACC_PUBLIC) {
		return "public";
	}

	return (fn_flags & ZEND_ACC_PRIVATE) ? "private" : "protected";
}

/* zend_bad_method_call(), exported only from PHP 8.5 on. */
static void zephir_bad_method_call(const zend_function *fbc, const zend_string *method_name, const zend_class_entry *scope)
{
	zend_throw_error(
		NULL,
		"Call to %s method %s::%s() from %s%s",
		zephir_visibility_string(fbc->common.fn_flags),
		ZEND_FN_SCOPE_NAME(fbc),
		ZSTR_VAL(method_name),
		scope ? "scope " : "global scope",
		scope ? ZSTR_VAL(scope->name) : ""
	);
}

/* zend_abstract_method_call(), exported only from PHP 8.5 on. */
static void zephir_abstract_method_call(const zend_function *fbc)
{
	zend_throw_error(
		NULL,
		"Cannot call abstract method %s::%s()",
		ZSTR_VAL(fbc->common.scope->name),
		ZSTR_VAL(fbc->common.function_name)
	);
}

/**
 * Whether a call written as `X::__construct()` names the constructor, with `X`
 * a class or `parent`, `self` or `static`. PHP calls the class's constructor
 * for it without looking the method up (see zephir_call_constructor()); a name
 * held in a variable is looked up like any other method.
 */
static zend_always_inline bool zephir_is_constructor_call(zephir_call_type type, const char *method_name, uint32_t method_len)
{
	return type != zephir_fcall_method
		&& method_len == sizeof("__construct") - 1
		&& zend_binary_strcasecmp(method_name, method_len, "__construct", sizeof("__construct") - 1) == 0;
}

/* From PHP 8.6 on, zend_get_call_trampoline_func() takes the magic method. */
static zend_function *zephir_call_trampoline(zend_class_entry *ce, zend_string *method_name, bool is_static)
{
#if PHP_VERSION_ID >= 80600
	return zend_get_call_trampoline_func(is_static ? ce->__callstatic : ce->__call, method_name);
#else
	return zend_get_call_trampoline_func(ce, method_name, is_static);
#endif
}

/**
 * zend_check_method_accessible(), exported only from PHP 8.5 on, with
 * zend_check_protected() inlined: it runs on every call to an inherited
 * protected method, so the walk that usually answers it, from the calling
 * class up to the method's root class, comes first.
 */
static zend_always_inline bool zephir_is_method_accessible(const zend_function *fbc, const zend_class_entry *scope)
{
	const zend_class_entry *root;
	const zend_class_entry *ce;

	if ((fbc->common.fn_flags & ZEND_ACC_PUBLIC) || fbc->common.scope == scope) {
		return 1;
	}

	if (fbc->common.fn_flags & ZEND_ACC_PRIVATE) {
		return 0;
	}

	root = zend_get_function_root_class(fbc);

	for (ce = scope; ce; ce = ce->parent) {
		if (ce == root) {
			return 1;
		}
	}

	for (ce = root; ce; ce = ce->parent) {
		if (ce == scope) {
			return 1;
		}
	}

	return 0;
}

/**
 * Checks that `new` may construct the object it has just initialized, as
 * ZEND_NEW does before the arguments are evaluated, and releases the object
 * when it may not, as PHP frees it before any `catch` runs.
 *
 * The engine's get_constructor handler decides, so each PHP version keeps its
 * own rules, messages and destructor behavior, except in the global scope:
 * Zephir code without a class, a function or a closure written in one, runs
 * there, while the handler would walk up to the class of its caller (see
 * zephir_get_calling_scope()).
 *
 * A non-object means object_init_ex() refused the class, such as an abstract
 * class reached through `new static()`, and threw.
 *
 * @see https://github.com/zephir-lang/zephir/issues/882
 * @see https://github.com/zephir-lang/zephir/issues/2802
 */
int zephir_check_constructor_access(zval *object)
{
	zend_object *obj;
	zend_function *constructor;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		return EG(exception) ? FAILURE : SUCCESS;
	}

	obj         = Z_OBJ_P(object);
	constructor = obj->ce->constructor;

	if (constructor
		&& !(constructor->common.fn_flags & ZEND_ACC_PUBLIC)
		&& obj->handlers->get_constructor == zend_std_get_constructor
		&& !zephir_get_calling_scope()
	) {
		zend_throw_error(
			NULL,
			"Call to %s %s::%s() from global scope",
			zephir_visibility_string(constructor->common.fn_flags),
			ZSTR_VAL(constructor->common.scope->name),
			ZSTR_VAL(constructor->common.function_name)
		);
		/* GH-14456: from these versions on, a refused object is freed without its destructor. */
#if PHP_VERSION_ID >= 80309 || (PHP_VERSION_ID >= 80221 && PHP_VERSION_ID < 80300)
		zend_object_store_ctor_failed(obj);
#endif
	} else {
		obj->handlers->get_constructor(obj);
	}

	if (!EG(exception)) {
		return SUCCESS;
	}

	zval_ptr_dtor(object);
	ZVAL_NULL(object);

	return FAILURE;
}

/* zend_get_parent_private_method(), static in the engine. */
static zend_function *zephir_get_parent_private_method(const zend_class_entry *scope, const zend_class_entry *ce, zend_string *method_name)
{
	const zend_class_entry *parent = ce->parent;
	zend_function *fbc;

	if (!scope || scope == ce) {
		return NULL;
	}

	while (parent && parent != scope) {
		parent = parent->parent;
	}

	if (!parent) {
		return NULL;
	}

	fbc = zend_hash_find_ptr_lc(&scope->function_table, method_name);
	if (fbc && (fbc->common.fn_flags & ZEND_ACC_PRIVATE) && fbc->common.scope == scope) {
		return fbc;
	}

	return NULL;
}

/**
 * The method PHP runs for a call, once the class the calling code belongs to
 * is known, or NULL with PHP's Error thrown.
 *
 * Mirrors the access checks of zend_std_get_method() for `obj->m()` and of
 * zend_std_get_static_method() for every static form: a private method of
 * the calling class wins over a same-named one of a subclass (instance calls
 * only), an inaccessible method goes to `__call()` or `__callStatic()`, and
 * anything else is an Error.
 *
 * `fcic` arrives filled by populate_fcic(), whose `calling_scope` is the
 * class the method was looked up in. A static call that falls back to
 * `__call()` runs it on `$this`, as the engine does.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2734
 */
static zend_function *zephir_resolve_visible_method(zend_fcall_info_cache *fcic, zephir_call_type type, zend_string *method_name)
{
	zend_function *fbc = fcic->function_handler;
	zend_class_entry *scope;
	zend_class_entry *ce;

	if (EXPECTED(!(fbc->common.fn_flags & (ZEND_ACC_CHANGED | ZEND_ACC_PRIVATE | ZEND_ACC_PROTECTED)))) {
		return fbc;
	}

	scope = zephir_get_calling_scope();
	if (fbc->common.scope == scope) {
		return fbc;
	}

	if (type == zephir_fcall_method && fcic->object) {
		ce = fcic->object->ce;

		if (fbc->common.fn_flags & ZEND_ACC_CHANGED) {
			zend_function *updated = zephir_get_parent_private_method(scope, ce, method_name);

			if (updated) {
				return updated;
			}

			if (fbc->common.fn_flags & ZEND_ACC_PUBLIC) {
				return fbc;
			}
		}

		if (zephir_is_method_accessible(fbc, scope)) {
			return fbc;
		}

		if (ce->__call) {
			return zephir_call_trampoline(ce, method_name, 0);
		}

		zephir_bad_method_call(fbc, method_name, scope);
		return NULL;
	}

	if (zephir_is_method_accessible(fbc, scope)) {
		return fbc;
	}

	ce = fcic->calling_scope;

#if PHP_VERSION_ID >= 80100
	/* get_static_method_fallback(); PHP 8.0 knew only __callStatic() here. */
	if (ce && ce->__call) {
		zend_object *object = zend_get_this_object(EG(current_execute_data));

		if (object && instanceof_function(object->ce, ce)) {
			fcic->object       = object;
			fcic->called_scope = object->ce;

			return zephir_call_trampoline(object->ce, method_name, 0);
		}
	}
#endif

	if (ce && ce->__callstatic) {
		fcic->object       = NULL;
		fcic->called_scope = ce;

		return zephir_call_trampoline(ce, method_name, 1);
	}

	zephir_bad_method_call(fbc, method_name, scope);
	return NULL;
}

/**
 * Throws PHP's Error and returns FAILURE when the object's __clone() is not
 * accessible from the calling class, as the `clone` operator checks it.
 *
 * PHP 8.5 words it as the method call it became; earlier versions leave
 * out "method".
 *
 * @see https://github.com/zephir-lang/zephir/issues/2734
 */
int zephir_check_clone_access(const zval *object)
{
	zend_function *clone = Z_OBJCE_P(object)->clone;
	zend_class_entry *scope;

	if (!clone || (clone->common.fn_flags & ZEND_ACC_PUBLIC)) {
		return SUCCESS;
	}

	scope = zephir_get_calling_scope();
	if (zephir_is_method_accessible(clone, scope)) {
		return SUCCESS;
	}

#if PHP_VERSION_ID >= 80500
	zephir_bad_method_call(clone, clone->common.function_name, scope);
#else
	zend_throw_error(
		NULL,
		"Call to %s %s::__clone() from %s%s",
		zephir_visibility_string(clone->common.fn_flags),
		ZSTR_VAL(clone->common.scope->name),
		scope ? "scope " : "global scope",
		scope ? ZSTR_VAL(scope->name) : ""
	);
#endif

	return FAILURE;
}

/**
 * Copies the arguments into the array zend_call_function() reads, and makes
 * the call.
 */
static int zephir_invoke(zend_fcall_info *fci, zend_fcall_info_cache *fcic, uint32_t param_count, zval **params)
{
	int status;
	uint32_t i;

#ifdef _MSC_VER
	zval *p = emalloc(sizeof(zval) * (param_count + 1));
#else
	zval p[param_count];
#endif

	/**
	 * zend_call_function() leaves this check to zend_is_callable(), which a
	 * resolved handler skips, and would run a non-static method without an
	 * object. PHP throws instead, e.g. for `self::m()` in a static method.
	 *
	 * @see https://github.com/zephir-lang/zephir/issues/2825
	 */
	if (
		fcic->function_handler
		&& !fcic->object
		&& fcic->function_handler->common.scope
		&& !(fcic->function_handler->common.fn_flags & (ZEND_ACC_STATIC | ZEND_ACC_CLOSURE))
	) {
		zend_throw_error(
			NULL,
			"Non-static method %s::%s() cannot be called statically",
			ZSTR_VAL(fcic->function_handler->common.scope->name),
			ZSTR_VAL(fcic->function_handler->common.function_name)
		);

#ifdef _MSC_VER
		efree(p);
#endif

		return FAILURE;
	}

	for (i = 0; i < param_count; ++i) {
		ZVAL_COPY_VALUE(&p[i], params[i]);
	}

	fci->param_count = param_count;
	fci->params      = p;
#if PHP_VERSION_ID >= 80600
	/* Every argument is copied; a set bit would move it out of `p` unreferenced. */
	fci->consumed_args = 0;
#endif

	status = zend_call_function(fci, fcic);

#ifdef _MSC_VER
	efree(p);
#endif

	return status;
}

/**
 * Leaves the return value of a call the way every Zephir call leaves it:
 * NULL after a failure or an exception, and an array separated.
 */
static void zephir_finish_call(zval *retval_ptr, zval *local_retval_ptr, int status)
{
	if (!retval_ptr) {
		zval_ptr_dtor(local_retval_ptr);
	} else if (FAILURE == status || EG(exception)) {
		ZVAL_NULL(retval_ptr);
	} else if (Z_TYPE_P(retval_ptr) == IS_ARRAY) {
		SEPARATE_ARRAY(retval_ptr);
	}
}

/**
 * Calls a function/method in the PHP userland
 *
 * `site`, when given, is the inline cache of the call site, filled once the
 * method is resolved (#2790).
 */
static int zephir_call_user_function(
    zval *object_pp,
    zend_class_entry *obj_ce,
    zephir_call_type type,
	zval *function_name,
	zval *retval_ptr,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	zephir_method_cache *site,
	uint32_t param_count,
	zval *params[],
	HashTable *named_params
) {
	zval local_retval_ptr;
	int status;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	char fcall_key[sizeof(zend_string) + 256];
	int key_ok = FAILURE;
	zephir_fcall_cache_entry *temp_cache_entry = NULL;
	zephir_fcall_cache_entry *cache_entry_temp;
	zend_function *raw_handler;
	bool raw_is_trampoline;
	zval callable;
	zend_class_entry* called_scope = zephir_get_called_scope(EG(current_execute_data));

	assert(obj_ce || !object_pp);
	ZVAL_UNDEF(&callable);
	ZVAL_UNDEF(&local_retval_ptr);

	if ((!cache_entry || !*cache_entry) && zephir_globals_ptr->cache_enabled) {
		int reload_cache = 1;
		if (cache_slot > 0 && zephir_globals_ptr->scache[cache_slot]) {
			reload_cache = 0;
			temp_cache_entry = zephir_globals_ptr->scache[cache_slot];
			if (cache_entry) {
				*cache_entry = temp_cache_entry;
			}
		}

		if (reload_cache) {
			key_ok = zephir_make_fcall_key((zend_string*)fcall_key, type, (object_pp && type == zephir_fcall_method ? Z_OBJCE_P(object_pp) : obj_ce), function_name, called_scope);
			if (SUCCESS == key_ok) {
				zend_string* zs = (zend_string*)fcall_key;

				GC_SET_REFCOUNT(zs, 1);
				GC_TYPE_INFO(zs) = IS_STRING;

				temp_cache_entry = zend_hash_find_ptr(zephir_globals_ptr->fcache, zs);
				if (temp_cache_entry) {
					cache_entry = &temp_cache_entry;
				}
			}
		}
	}

	fci.size        = sizeof(fci);
	fci.object      = object_pp ? Z_OBJ_P(object_pp) : NULL;
	ZVAL_COPY_VALUE(&fci.function_name, function_name);
	fci.retval      = retval_ptr ? retval_ptr : &local_retval_ptr;
	fci.param_count = param_count;
	fci.named_params = named_params;

	if (cache_entry && *cache_entry) {
		/* We have a cache record: reuse the resolved handler and skip the
		 * redundant method-table lookup while still setting up the scopes. */
		populate_fcic(&fcic, type, obj_ce, object_pp, function_name, called_scope, *cache_entry);
		if (!fcic.function_handler) {
			fcic.function_handler = *cache_entry;
		}

		ZVAL_UNDEF(&fci.function_name);
	} else if ((cache_entry && !*cache_entry) || zephir_globals_ptr->cache_enabled) {
		/* The caller is interested in caching OR we have the call cache enabled */
		/* A method call resolves on the object; every static form on the class
		 * the call names, which `self`, `parent` and `static` need (#2723). */
		resolve_callable(&callable, type, (object_pp && type == zephir_fcall_method ? Z_OBJCE_P(object_pp) : obj_ce), object_pp, function_name);

		char *is_callable_error = NULL;
		zend_execute_data *frame = EG(current_execute_data);
#if PHP_VERSION_ID >= 80200
		if (obj_ce || !zend_is_callable_at_frame(&callable, fci.object, frame, IS_CALLABLE_SUPPRESS_DEPRECATIONS, &fcic, &is_callable_error)) {
#else
		if (obj_ce || !zend_is_callable_at_frame(&callable, fci.object, frame, 0, &fcic, &is_callable_error)) {
#endif
			if (is_callable_error) {
				/* zend_is_callable_ex() fills this in to explain the failure to
				 * whoever throws; PHP itself raises no diagnostic before the
				 * error, so neither do we. The caller turns this FAILURE into
				 * the same Error PHP would throw (#2712). */
				efree(is_callable_error);

				/* resolve_callable() built this; the tail that releases it is
				 * below this early return. */
				if (Z_TYPE(callable) != IS_UNDEF) {
					zval_ptr_dtor(&callable);
				}

				return FAILURE;
			}

			populate_fcic(&fcic, type, obj_ce, object_pp, function_name, called_scope, NULL);

			/**
			 * PHP reports a method the class does not have as
			 * "Call to undefined method C::m()". Left to zend_call_function(),
			 * the very same condition arrives as "Invalid callback ...",
			 * because that path cannot tell a missing method apart from any
			 * other value that is not callable.
			 *
			 * populate_fcic() has just looked the method up in the scope PHP
			 * would name, so throw here and let every other failure, visibility
			 * included, keep flowing through the engine. A class with __call()
			 * or __callStatic() never reaches "undefined" at all, so it is left
			 * to dispatch as before.
			 *
			 * @see https://github.com/zephir-lang/zephir/issues/2712
			 */
			if (
				!fcic.function_handler
				&& type != zephir_fcall_function
				&& Z_TYPE_P(function_name) == IS_STRING
				&& fcic.calling_scope
				&& !fcic.calling_scope->__call
				&& !fcic.calling_scope->__callstatic
			) {
				zend_throw_error(
					NULL,
					"Call to undefined method %s::%s()",
					ZSTR_VAL(fcic.calling_scope->name),
					Z_STRVAL_P(function_name)
				);

				if (Z_TYPE(callable) != IS_UNDEF) {
					zval_ptr_dtor(&callable);
				}

				return FAILURE;
			}
		}
	}

	/**
	 * PHP checks visibility on every call, against the class the calling code
	 * belongs to. No cache key holds that class, so a handler that came from a
	 * cache is checked as well. Only the handler found in the class is ever
	 * cached, never the one this check settles on, and never a trampoline,
	 * which the engine frees once it has run (#2734).
	 */
	raw_handler = fcic.function_handler;
	raw_is_trampoline = raw_handler && (raw_handler->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE);

	if (raw_handler && type != zephir_fcall_function && Z_TYPE_P(function_name) == IS_STRING) {
		zend_function *resolved = zephir_resolve_visible_method(&fcic, type, Z_STR_P(function_name));

		/**
		 * PHP refuses an abstract method once visibility is settled, before it
		 * checks whether the method is static, and before the handler, an empty
		 * body or none at all for an interface, could run (#2789). A constructor
		 * named literally never gets here: zephir_call_constructor() takes it.
		 */
		if (resolved && UNEXPECTED(resolved->common.fn_flags & ZEND_ACC_ABSTRACT)) {
			zephir_abstract_method_call(resolved);
			resolved = NULL;
		}

		if (UNEXPECTED(!resolved)) {
			if (Z_TYPE(callable) != IS_UNDEF) {
				zval_ptr_dtor(&callable);
			}

			if (retval_ptr) {
				ZVAL_NULL(retval_ptr);
			}

			return FAILURE;
		}

		fcic.function_handler = resolved;
	}

	/**
	 * The method found in the class, settled for the calling class, is all a
	 * call site's cache keeps. A trampoline is never kept: the engine frees
	 * it once it has run, and which one a call gets depends on more than the
	 * two classes (#2790).
	 */
	if (
		site
		&& obj_ce
		&& raw_handler
		&& !raw_is_trampoline
		&& !(fcic.function_handler->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE)
	) {
		site->ce      = obj_ce;
		site->scope   = zephir_get_calling_scope();
		site->func    = fcic.function_handler;
		site->request = zephir_globals_ptr->request_number;
	}

	if (!fcic.function_handler) {
		ZVAL_COPY_VALUE(&fci.function_name, &callable);
	}

	status = zephir_invoke(&fci, &fcic, param_count, params);

	if (Z_TYPE(callable) != IS_UNDEF) {
		zval_ptr_dtor(&callable);
	}

	/**
	 * Skip caching IF:
	 * call failed OR there was an exception (to be safe) OR cache key is not defined OR
	 * fcall cache was de-initialized OR we have a slot cache
	 */
	int initialized = 1;

	if (raw_handler) {
		cache_entry_temp = raw_is_trampoline ? NULL : raw_handler;
	} else {
		/* Resolved by zend_call_function(), which drops a trampoline. */
		cache_entry_temp = fcic.function_handler;
	}

	if (EXPECTED(status != FAILURE) && !EG(exception) && SUCCESS == key_ok && initialized && !temp_cache_entry && cache_entry_temp) {
		if (cache_entry) {
			*cache_entry = cache_entry_temp;
			if (cache_slot > 0) {
				zephir_globals_ptr->scache[cache_slot] = *cache_entry;
			}
		}

		if (zephir_globals_ptr->cache_enabled) {
			zend_string *zs = (zend_string*)fcall_key;
			zend_hash_str_add_ptr(zephir_globals_ptr->fcache, ZSTR_VAL(zs), ZSTR_LEN(zs), cache_entry_temp);
		}
	}

	zephir_finish_call(retval_ptr, &local_retval_ptr, status);

	return status;
}

/**
 * The call a call site makes when its cache holds the method: the object and
 * scopes populate_fcic() gives the same call, with no name to copy, no key to
 * build, no lookup and no visibility check (#2790).
 */
static int zephir_call_cached_method(
	zval *retval_ptr,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	zend_function *func,
	uint32_t param_count,
	zval **params
) {
	zval local_retval_ptr;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	int status;

	ZVAL_UNDEF(&local_retval_ptr);

	fcic.function_handler = func;
	fcic.object           = object ? Z_OBJ_P(object) : NULL;

	switch (type) {
		case zephir_fcall_parent:
			fcic.calling_scope = ce->parent;
			fcic.called_scope  = zephir_get_called_scope(EG(current_execute_data));
			break;

		case zephir_fcall_self:
		case zephir_fcall_static:
			fcic.calling_scope = ce;
			fcic.called_scope  = zephir_get_called_scope(EG(current_execute_data));
			break;

		default:
			fcic.calling_scope = ce;
			fcic.called_scope  = ce;
			break;
	}

	fci.size         = sizeof(fci);
	fci.object       = fcic.object;
	fci.retval       = retval_ptr ? retval_ptr : &local_retval_ptr;
	fci.named_params = NULL;
	ZVAL_UNDEF(&fci.function_name);

	status = zephir_invoke(&fci, &fcic, param_count, params);
	zephir_finish_call(retval_ptr, &local_retval_ptr, status);

	return status;
}

static int zephir_call_func_ex(
	zval *return_value_ptr,
	const char *func_name,
	uint32_t func_length,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params,
	HashTable *named_params
) {
	int status;
	zval rv, *rvp = return_value_ptr ? return_value_ptr : &rv;

	ZVAL_UNDEF(&rv);

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr != NULL && Z_TYPE_P(return_value_ptr) > IS_NULL) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	zval f;
	ZVAL_STRINGL(&f, func_name, func_length);
	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, &f, rvp, cache_entry, cache_slot, NULL, param_count, params, named_params);
	zval_ptr_dtor(&f);

	if (status == FAILURE && !EG(exception)) {
		/* PHP throws Error here, not an SPL exception (#2712). */
		zend_throw_error(NULL, "Call to undefined function %s()", func_name);
	} else if (EG(exception)) {
		status = FAILURE;
	}

	if (!return_value_ptr) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int zephir_call_func_aparams(
	zval *return_value_ptr,
	const char *func_name,
	uint32_t func_length,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params
) {
	return zephir_call_func_ex(return_value_ptr, func_name, func_length, cache_entry, cache_slot, param_count, params, NULL);
}

int zephir_call_func_named(
	zval *return_value_ptr,
	const char *func_name,
	uint32_t func_length,
	HashTable *named_params,
	uint32_t param_count,
	zval **params
) {
	return zephir_call_func_ex(return_value_ptr, func_name, func_length, NULL, 0, param_count, params, named_params);
}

/**
 * Throws the Error PHP throws for `$f()` when $f names method `method` of class
 * `ce` and zend_is_callable() refused it, checking what INIT_DYNAMIC_CALL
 * checks, in its order: the method exists, is visible from the calling class,
 * is not abstract, and is static when no object goes with it. Getting here
 * means zend_is_callable() raised no exception of its own, so a `__call()` or
 * `__callStatic()` fallback is no longer in play.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2734
 * @see https://github.com/zephir-lang/zephir/issues/2789
 */
static void zephir_throw_method_callback_error(zend_class_entry *ce, zend_string *method, bool without_object)
{
	zend_class_entry *scope;
	zend_function *fbc = zend_hash_find_ptr_lc(&ce->function_table, method);

	if (!fbc) {
		zend_throw_error(NULL, "Call to undefined method %s::%s()", ZSTR_VAL(ce->name), ZSTR_VAL(method));
		return;
	}

	scope = zephir_get_calling_scope();
	if (!zephir_is_method_accessible(fbc, scope)) {
		zephir_bad_method_call(fbc, method, scope);
		return;
	}

	if (fbc->common.fn_flags & ZEND_ACC_ABSTRACT) {
		zephir_abstract_method_call(fbc);
		return;
	}

	if (without_object && !(fbc->common.fn_flags & ZEND_ACC_STATIC)) {
		zend_throw_error(
			NULL,
			"Non-static method %s::%s() cannot be called statically",
			ZSTR_VAL(fbc->common.scope->name),
			ZSTR_VAL(fbc->common.function_name)
		);
		return;
	}

	zend_throw_error(NULL, "Call to undefined function undefined()");
}

/**
 * The Error for an array callback, as zend_init_dynamic_call_array() words it.
 */
static void zephir_throw_array_callback_error(zval *callback)
{
	HashTable *ht = Z_ARRVAL_P(callback);
	zval *target;
	zval *method;
	zend_class_entry *ce;

	if (zend_hash_num_elements(ht) != 2) {
		zend_throw_error(NULL, "Array callback must have exactly two elements");
		return;
	}

	target = zend_hash_index_find(ht, 0);
	method = zend_hash_index_find(ht, 1);
	if (!target || !method) {
		zend_throw_error(NULL, "Array callback has to contain indices 0 and 1");
		return;
	}

	ZVAL_DEREF(target);
	if (Z_TYPE_P(target) != IS_STRING && Z_TYPE_P(target) != IS_OBJECT) {
		zend_throw_error(NULL, "First array member is not a valid class name or object");
		return;
	}

	ZVAL_DEREF(method);
	if (Z_TYPE_P(method) != IS_STRING) {
		zend_throw_error(NULL, "Second array member is not a valid method");
		return;
	}

	if (Z_TYPE_P(target) == IS_OBJECT) {
		ce = Z_OBJCE_P(target);
	} else {
		ce = zend_fetch_class_by_name(Z_STR_P(target), NULL, ZEND_FETCH_CLASS_DEFAULT | ZEND_FETCH_CLASS_EXCEPTION);
		if (!ce) {
			return;
		}
	}

	zephir_throw_method_callback_error(ce, Z_STR_P(method), Z_TYPE_P(target) == IS_STRING);
}

/**
 * The Error for a string callback, as zend_init_dynamic_call_string() words
 * it: a "Class::method" string is split at its last "::", any other string
 * names a function.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2789
 */
static void zephir_throw_string_callback_error(zval *callback)
{
	const char *name = Z_STRVAL_P(callback);
	size_t length = Z_STRLEN_P(callback);
	const char *colon = zend_memrchr(name, ':', length);
	zend_string *class_name;
	zend_string *method;
	zend_class_entry *ce;

	if (!colon || colon == name || *(colon - 1) != ':') {
		zend_throw_error(NULL, "Call to undefined function %s()", name);
		return;
	}

	class_name = zend_string_init(name, colon - name - 1, 0);
	ce = zend_fetch_class_by_name(class_name, NULL, ZEND_FETCH_CLASS_DEFAULT | ZEND_FETCH_CLASS_EXCEPTION);
	zend_string_release(class_name);
	if (!ce) {
		return;
	}

	method = zend_string_init(colon + 1, length - (size_t) (colon + 1 - name), 0);
	zephir_throw_method_callback_error(ce, method, 1);
	zend_string_release(method);
}

static int zephir_call_zval_func_ex(
	zval *return_value_ptr,
	zval *func_name,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params,
	HashTable *named_params
) {
	int status;
	zval rv, *rvp = return_value_ptr ? return_value_ptr : &rv;

	ZVAL_UNDEF(&rv);

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr != NULL && Z_TYPE_P(return_value_ptr) > IS_NULL) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func_name, rvp, cache_entry, cache_slot, NULL, param_count, params, named_params);

	if (status == FAILURE && !EG(exception) && Z_TYPE_P(func_name) == IS_ARRAY) {
		zephir_throw_array_callback_error(func_name);
	} else if (status == FAILURE && !EG(exception) && Z_TYPE_P(func_name) == IS_STRING) {
		zephir_throw_string_callback_error(func_name);
	} else if (status == FAILURE && !EG(exception)) {
		/* PHP throws Error here, not an SPL exception (#2712). */
		zend_throw_error(NULL, "Call to undefined function undefined()");
	} else if (EG(exception)) {
		status = FAILURE;
	}

	if (!return_value_ptr) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int zephir_call_zval_func_aparams(
	zval *return_value_ptr,
	zval *func_name,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params
) {
	return zephir_call_zval_func_ex(return_value_ptr, func_name, cache_entry, cache_slot, param_count, params, NULL);
}

int zephir_call_zval_func_named(
	zval *return_value_ptr,
	zval *func_name,
	HashTable *named_params,
	uint32_t param_count,
	zval **params
) {
	return zephir_call_zval_func_ex(return_value_ptr, func_name, NULL, 0, param_count, params, named_params);
}

/**
 * Whether a call site's cache was filled in this request, for code of the
 * class that is calling now.
 */
static zend_always_inline bool zephir_method_cache_is_current(const zephir_method_cache *site)
{
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	return site->request == zephir_globals_ptr->request_number && site->scope == zephir_get_calling_scope();
}

/**
 * Calls a method by a name known at compile time, through the call site's
 * inline cache when it has one (#2790).
 */
static int zephir_call_class_method_site(
	zval *return_value,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	const char *method_name,
	uint32_t method_len,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	zephir_method_cache *site,
	uint32_t param_count,
	zval **params,
	HashTable *named_params
) {
	int status;

#ifndef ZEPHIR_RELEASE
	if (return_value != NULL && Z_TYPE_P(return_value) > IS_NULL) {
		fprintf(stderr, "%s: *return_value must be IS_NULL or IS_UNDEF\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	/**
	 * A method named through a class runs on `$this` when `$this` is an
	 * instance of that class, and without an object otherwise, which
	 * zephir_invoke() refuses for a non-static method, as
	 * ZEND_INIT_STATIC_METHOD_CALL does (#2854).
	 */
	if (type == zephir_fcall_ce && object && (Z_TYPE_P(object) != IS_OBJECT || !ce || !instanceof_function(Z_OBJCE_P(object), ce))) {
		object = NULL;
	}

	if (object && Z_TYPE_P(object) != IS_OBJECT) {
		/**
		 * Same sentence and same throwable as zend_invalid_method_call(). The
		 * tail is the value name from 8.3 on and the type name before it, so
		 * `true` reads as "on true" there and "on bool" here (#2712).
		 */
		zend_throw_error(
			NULL,
			"Call to a member function %s() on %s",
			method_name,
#if PHP_VERSION_ID >= 80300
			zend_zval_value_name(object)
#else
			zend_zval_type_name(object)
#endif
		);
		if (return_value) {
			ZVAL_NULL(return_value);
		}
		return FAILURE;
	}

	if (site && ce && site->ce == ce && zephir_method_cache_is_current(site)) {
		status = zephir_call_cached_method(return_value, ce, type, object, site->func, param_count, params);
	} else {
		zval method;
		ZVAL_STRINGL(&method, method_name, method_len);
		status = zephir_call_user_function(object, ce, type, &method, return_value, cache_entry, cache_slot, site, param_count, params, named_params);
		zval_ptr_dtor(&method);
	}

	if (status == FAILURE && !EG(exception)) {
		/**
		 * PHP never names the keyword, it names the class the lookup actually
		 * used: `parent::` reports the parent, `self::` and `static::` report
		 * the resolved class. Mirror the scope populate_fcic() looks in, and
		 * throw the Error PHP throws (#2712).
		 */
		zend_class_entry *scope;

		switch (type) {
			case zephir_fcall_parent:
				scope = ce ? ce->parent : NULL;
				break;

			case zephir_fcall_static:
				scope = zephir_get_called_scope(EG(current_execute_data));
				if (!scope) {
					scope = ce;
				}
				break;

			default:
				scope = ce;
				break;
		}

		if (scope) {
			zend_throw_error(NULL, "Call to undefined method %s::%s()", ZSTR_VAL(scope->name), method_name);
		} else {
			zend_throw_error(NULL, "Call to undefined method %s()", method_name);
		}
	} else if (EG(exception)) {
		status = FAILURE;
	}

	return status;
}

/**
 * `X::__construct()` with the name written out, for `X` a class or `parent`,
 * `self` or `static`. PHP compiles that call without the method's name
 * (ZEND_INIT_STATIC_METHOD_CALL with no method operand): when it runs, it takes
 * the constructor of the class the call names, with no visibility check, no
 * abstract check and no __call() fallback, and throws
 *
 * - "Cannot call constructor" when the class has none (#2852);
 * - "Cannot call private X::__construct()", naming the class the call names,
 *   when the constructor is private and `$this` is an object of another class
 *   than the one declaring it (#2853);
 * - "Non-static method X::__construct() cannot be called statically" when
 *   `$this` is not an instance of the class the call names (#2854), which
 *   zephir_invoke() does for a call without an object.
 */
static int zephir_call_constructor(
	zval *return_value,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	uint32_t param_count,
	zval **params,
	HashTable *named_params
) {
	zend_class_entry *scope = type == zephir_fcall_parent ? (ce ? ce->parent : NULL) : ce;
	zend_function *constructor = scope ? scope->constructor : NULL;
	zval local_retval_ptr;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	int status;

	if (object && Z_TYPE_P(object) != IS_OBJECT) {
		object = NULL;
	}

	if (!constructor) {
		zend_throw_error(NULL, "Cannot call constructor");
	} else if (
		object
		&& Z_OBJCE_P(object) != constructor->common.scope
		&& (constructor->common.fn_flags & ZEND_ACC_PRIVATE)
	) {
		zend_throw_error(NULL, "Cannot call private %s::__construct()", ZSTR_VAL(scope->name));
	}

	if (EG(exception)) {
		if (return_value) {
			ZVAL_NULL(return_value);
		}

		return FAILURE;
	}

	if (object && !instanceof_function(Z_OBJCE_P(object), scope)) {
		object = NULL;
	}

	/**
	 * An interface registers its methods without a body, where the abstract
	 * method PHP runs here has an empty one (#2789). Without an object,
	 * zephir_invoke() throws before it would reach the body.
	 */
	if (object && constructor->type == ZEND_INTERNAL_FUNCTION && !constructor->internal_function.handler) {
		if (return_value) {
			ZVAL_NULL(return_value);
		}

		return SUCCESS;
	}

	ZVAL_UNDEF(&local_retval_ptr);

	fcic.function_handler = constructor;
	fcic.object           = object ? Z_OBJ_P(object) : NULL;
	fcic.calling_scope    = scope;
	fcic.called_scope     = object ? Z_OBJCE_P(object) : scope;

	fci.size         = sizeof(fci);
	fci.object       = fcic.object;
	fci.retval       = return_value ? return_value : &local_retval_ptr;
	fci.named_params = named_params;
	ZVAL_UNDEF(&fci.function_name);

	status = zephir_invoke(&fci, &fcic, param_count, params);
	zephir_finish_call(return_value, &local_retval_ptr, status);

	return EG(exception) ? FAILURE : status;
}

int zephir_call_class_method_aparams(
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
	if (zephir_is_constructor_call(type, method_name, method_len)) {
		return zephir_call_constructor(return_value, ce, type, object, param_count, params, NULL);
	}

	return zephir_call_class_method_site(return_value, ce, type, object, method_name, method_len, cache_entry, cache_slot, NULL, param_count, params, NULL);
}

int zephir_call_class_method_cached(
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
	if (zephir_is_constructor_call(type, method_name, method_len)) {
		return zephir_call_constructor(return_value, ce, type, object, param_count, params, NULL);
	}

	return zephir_call_class_method_site(return_value, ce, type, object, method_name, method_len, NULL, 0, cache, param_count, params, NULL);
}

/**
 * The class of the object a method call is made on, which the call site
 * leaves to the kernel; every other call names its class.
 */
static zend_always_inline zend_class_entry *zephir_named_call_ce(zend_class_entry *ce, zephir_call_type type, zval *object)
{
	if (!ce && type == zephir_fcall_method && object && Z_TYPE_P(object) == IS_OBJECT) {
		return Z_OBJCE_P(object);
	}

	return ce;
}

int zephir_call_class_method_named(
	zval *return_value,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	const char *method_name,
	uint32_t method_len,
	HashTable *named_params,
	uint32_t param_count,
	zval **params
) {
	if (zephir_is_constructor_call(type, method_name, method_len)) {
		return zephir_call_constructor(return_value, ce, type, object, param_count, params, named_params);
	}

	return zephir_call_class_method_site(
		return_value,
		zephir_named_call_ce(ce, type, object),
		type,
		object,
		method_name,
		method_len,
		NULL,
		0,
		NULL,
		param_count,
		params,
		named_params
	);
}

/**
 * Calls a method whose name is held in a zval: `obj->{name}()` and every
 * `X::{name}()` form.
 *
 * Mirrors the checks PHP's INIT_METHOD_CALL and INIT_STATIC_METHOD_CALL run
 * before the call, in their order:
 *
 * - a static call whose class could not be fetched stops there; the fetch has
 *   thrown already;
 * - the name must be a string once a reference is unwrapped, and nothing else
 *   is converted: "Method name must be a string";
 * - a static call reaching a non-static method runs it with the current `$this`
 *   when that is an instance of the class the method was looked up in, and
 *   throws otherwise, rather than run the body without an object.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2723
 */
static int zephir_call_class_method_zval_ex(
	zval *return_value,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	zval *method,
	zephir_fcall_cache_entry **cache_entry,
	int cache_slot,
	uint32_t param_count,
	zval **params,
	HashTable *named_params
) {
	zval *name = method;

	if (type != zephir_fcall_method && !ce) {
		if (!EG(exception)) {
			zend_throw_error(NULL, "Class name must be a valid object or a string");
		}

		return FAILURE;
	}

	ZVAL_DEREF(name);

	if (Z_TYPE_P(name) != IS_STRING) {
		zend_throw_error(NULL, "Method name must be a string");

		return FAILURE;
	}

	if (type != zephir_fcall_method) {
		zend_class_entry *scope = type == zephir_fcall_parent ? ce->parent : ce;
		zend_function *function;

		if (object && (Z_TYPE_P(object) != IS_OBJECT || !scope || !instanceof_function(Z_OBJCE_P(object), scope))) {
			object = NULL;
		}

		/* PHP settles visibility, and with it any __call()/__callStatic()
		 * fallback, before it looks at whether the method is abstract (#2789),
		 * then static (#2734). A name held here is always looked up, so an
		 * abstract constructor is refused as well. */
		function = scope ? zend_hash_find_ptr_lc(&scope->function_table, Z_STR_P(name)) : NULL;
		if (function && zephir_is_method_accessible(function, zephir_get_calling_scope())) {
			if (function->common.fn_flags & ZEND_ACC_ABSTRACT) {
				zephir_abstract_method_call(function);

				return FAILURE;
			}

			if (!(function->common.fn_flags & ZEND_ACC_STATIC) && !object) {
				zend_throw_error(
					NULL,
					"Non-static method %s::%s() cannot be called statically",
					ZSTR_VAL(function->common.scope->name),
					ZSTR_VAL(function->common.function_name)
				);

				return FAILURE;
			}
		}
	}

	return zephir_call_class_method_site(
		return_value,
		ce,
		type,
		object,
		Z_STRVAL_P(name),
		(uint32_t) Z_STRLEN_P(name),
		cache_entry,
		cache_slot,
		NULL,
		param_count,
		params,
		named_params
	);
}

int zephir_call_class_method_zval(
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
	return zephir_call_class_method_zval_ex(return_value, ce, type, object, method, cache_entry, cache_slot, param_count, params, NULL);
}

int zephir_call_class_method_zval_named(
	zval *return_value,
	zend_class_entry *ce,
	zephir_call_type type,
	zval *object,
	zval *method,
	HashTable *named_params,
	uint32_t param_count,
	zval **params
) {
	return zephir_call_class_method_zval_ex(
		return_value,
		zephir_named_call_ce(ce, type, object),
		type,
		object,
		method,
		NULL,
		0,
		param_count,
		params,
		named_params
	);
}

/**
 * call_user_func() and call_user_func_array(), named by `caller` in the errors.
 *
 * The callback is resolved in the class whose code is running, as PHP resolves
 * it in a method. PHP's own functions resolve it at the nearest PHP frame
 * instead, which is the caller of the Zephir method, and an internal method or
 * a generator step runs on a borrowed frame of no class: a private method of
 * the class would not be callable from either. A string key in `params` names
 * an argument, as call_user_func_array() takes it.
 *
 * Like PHP, a callback or an argument list it cannot use throws a TypeError.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2824
 */
int zephir_call_user_func(zval *return_value, const char *caller, zval *handler, zval *params)
{
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	zend_execute_data *frame = EG(current_execute_data);
	zend_execute_data scoped_frame;
	zend_internal_function scoped_func;
	zend_class_entry *scope = zephir_get_calling_scope();

	/* A frame of the calling class, for the callable check only: its scope
	 * is the one thing read off a function the check never calls. */
	if (frame && (!frame->func || frame->func->common.scope != scope)) {
		memset(&scoped_func, 0, sizeof(scoped_func));
		scoped_func.type  = ZEND_INTERNAL_FUNCTION;
		scoped_func.scope = scope;

		scoped_frame      = *frame;
		scoped_frame.func = (zend_function *) &scoped_func;
		frame             = &scoped_frame;
	}

#if PHP_VERSION_ID >= 80200
	if (!zend_is_callable_at_frame(handler, NULL, frame, IS_CALLABLE_SUPPRESS_DEPRECATIONS, &fci_cache, &is_callable_error)) {
#else
	if (!zend_is_callable_at_frame(handler, NULL, frame, 0, &fci_cache, &is_callable_error)) {
#endif
		zend_type_error(
			"%s(): Argument #1 ($callback) must be a valid callback, %s",
			caller,
			is_callable_error ? is_callable_error : "no array or string given"
		);

		if (is_callable_error) {
			efree(is_callable_error);
		}

		ZVAL_NULL(return_value);

		return FAILURE;
	}

	if (is_callable_error) {
		efree(is_callable_error);
	}

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		zend_type_error(
			"%s(): Argument #2 ($args) must be of type array, %s given",
			caller,
#if PHP_VERSION_ID >= 80300
			zend_zval_value_name(params)
#else
			zend_zval_type_name(params)
#endif
		);
		ZVAL_NULL(return_value);

		return FAILURE;
	}

	fci.size = sizeof(fci);
	fci.object = fci_cache.object;
	/* We have an FCC so no need to copy the callable */
	ZVAL_UNDEF(&fci.function_name);
	fci.param_count = 0;
	fci.params = NULL;
#if PHP_VERSION_ID >= 80600
	fci.consumed_args = 0;
#endif
	fci.retval = return_value;
	fci.named_params = params ? Z_ARRVAL_P(params) : NULL;

	return zend_call_function(&fci, &fci_cache);
}

/**
 * call_user_func_array() that does not return FAILURE for an exception thrown
 * by the callback.
 */
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params)
{
	return zephir_call_user_func(return_value, "call_user_func_array", handler, params);
}

/**
 * If a retval_ptr is specified, PHP's implementation of zend_eval_stringl
 * simply prepends a "return " which causes only the first statement to be executed
 */
void zephir_eval_php(zval *str, zval *retval_ptr, char *context)
{
	zval local_retval;
	zend_op_array *new_op_array = NULL;
	uint32_t original_compiler_options;

	ZVAL_UNDEF(&local_retval);

	original_compiler_options = CG(compiler_options);
	CG(compiler_options) = ZEND_COMPILE_DEFAULT_FOR_EVAL;
#if PHP_VERSION_ID >= 80200
	new_op_array = zend_compile_string(Z_STR_P(str), context, ZEND_COMPILE_POSITION_AFTER_OPEN_TAG);
#else
	new_op_array = zend_compile_string(Z_STR_P(str), context);
#endif

	CG(compiler_options) = original_compiler_options;

	if (new_op_array) {
		EG(no_extensions) = 1;
		zend_try {
			zend_execute(new_op_array, &local_retval);
		} zend_catch {
			destroy_op_array(new_op_array);
			efree_size(new_op_array, sizeof(zend_op_array));
			zend_bailout();
		} zend_end_try();
		EG(no_extensions) = 0;

		if (Z_TYPE(local_retval) != IS_UNDEF) {
			if (retval_ptr) {
				ZVAL_COPY_VALUE(retval_ptr, &local_retval);
			} else {
				zval_ptr_dtor(&local_retval);
			}
		} else if (retval_ptr) {
			ZVAL_NULL(retval_ptr);
		}

		destroy_op_array(new_op_array);
		efree_size(new_op_array, sizeof(zend_op_array));
	}
}
