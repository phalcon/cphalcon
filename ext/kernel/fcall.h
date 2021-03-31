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
		zephir_fcall_cache_entry **cache_entry_ = cache; \
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

#define ZEPHIR_BACKUP_SCOPE() \
	zend_class_entry *old_scope = EG(fake_scope); \
	zend_execute_data *old_call = execute_data; \
	zend_execute_data *old_execute_data = EG(current_execute_data), new_execute_data; \
	if (!EG(current_execute_data)) { \
		memset(&new_execute_data, 0, sizeof(zend_execute_data)); \
		execute_data = EG(current_execute_data) = &new_execute_data; \
	} else { \
		new_execute_data = *EG(current_execute_data); \
		new_execute_data.prev_execute_data = EG(current_execute_data); \
		new_execute_data.call = NULL; \
		new_execute_data.opline = NULL; \
		new_execute_data.func = NULL; \
		execute_data = EG(current_execute_data) = &new_execute_data; \
	}

#define ZEPHIR_RESTORE_SCOPE() \
	EG(fake_scope) = old_scope; \
	execute_data = old_call; \
	EG(current_execute_data) = old_execute_data;

#define ZEPHIR_SET_SCOPE(_scope, _scope_called) \
	EG(fake_scope) = _scope; \
	zephir_set_called_scope(EG(current_execute_data), _scope_called); \

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

#define ZEPHIR_RETURN_CALL_METHOD_ZVAL(object, method, cache, cache_slot, ...) \
	do { \
		char *method_name; \
		int method_len; \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		if (Z_TYPE_P(method) == IS_STRING) { \
			method_len = Z_STRLEN_P(method); \
			method_name = zend_str_tolower_dup(Z_STRVAL_P(method), method_len); \
		} else { \
			method_len = 0; \
			method_name = zend_str_tolower_dup("", 0); \
		} \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, method_name, method_len, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		efree(method_name); \
	} while (0)

#define ZEPHIR_CALL_METHOD_ZVAL(return_value_ptr, object, method, cache, cache_slot, ...) \
	do { \
		char *method_name; \
		int method_len; \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		if (Z_TYPE_P(method) == IS_STRING) { \
			method_len = Z_STRLEN_P(method); \
			method_name = zend_str_tolower_dup(Z_STRVAL_P(method), method_len); \
		} else { \
			method_len = 0; \
			method_name = zend_str_tolower_dup("", 0); \
		} \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, zephir_fcall_method, object, method_name, method_len, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		efree(method_name); \
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

#if PHP_VERSION_ID >= 80000
#define ZEPHIR_RETURN_CALL_STATIC(method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, (getThis() ? Z_OBJCE_P(getThis()) : NULL), zephir_fcall_static, getThis(), method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)
#else
#define ZEPHIR_RETURN_CALL_STATIC(method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, NULL, zephir_fcall_static, NULL, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)
#endif

#define ZEPHIR_RETURN_CALL_PARENT(class_entry, this_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, class_entry, zephir_fcall_parent, this_ptr, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)

#if PHP_VERSION_ID >= 80000
#define ZEPHIR_CALL_SELF(return_value_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, (getThis() ? Z_OBJCE_P(getThis()) : NULL), zephir_fcall_self, getThis(), method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)
#else
#define ZEPHIR_CALL_SELF(return_value_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, NULL, zephir_fcall_self, NULL, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)
#endif

#if PHP_VERSION_ID >= 80000
#define ZEPHIR_RETURN_CALL_SELF(method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, (getThis() ? Z_OBJCE_P(getThis()) : NULL), zephir_fcall_self, getThis(), method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)
#else
#define ZEPHIR_RETURN_CALL_SELF(method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, NULL, zephir_fcall_self, NULL, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)
#endif

#if PHP_VERSION_ID >= 80000
#define ZEPHIR_CALL_STATIC(return_value_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, (getThis() ? Z_OBJCE_P(getThis()) : NULL), zephir_fcall_static, getThis(), method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)
#else
#define ZEPHIR_CALL_STATIC(return_value_ptr, method, cache, cache_slot, ...) \
	do { \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, NULL, zephir_fcall_static, NULL, method, strlen(method), cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
	} while (0)
#endif

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

#define ZEPHIR_CALL_CE_STATIC_ZVAL(return_value_ptr, class_entry, method, cache, cache_slot, ...) \
	do { \
		char *method_name; \
		int method_len; \
		zval *params_[] = {ZEPHIR_FETCH_VA_ARGS __VA_ARGS__}; \
		if (Z_TYPE(method) == IS_STRING) { \
			method_len = Z_STRLEN(method); \
			method_name = zend_str_tolower_dup(Z_STRVAL(method), method_len); \
		} else { \
			method_len = 0; \
			method_name = zend_str_tolower_dup("", 0); \
		} \
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_class_method_aparams(return_value_ptr, class_entry, zephir_fcall_ce, NULL, method_name, method_len, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		efree(method_name); \
	} while (0)

#define ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(class_entry, method, cache, cache_slot, ...) \
	do { \
		char *method_name; \
		int method_len; \
		zval *params_[] = { ZEPHIR_FETCH_VA_ARGS __VA_ARGS__ }; \
		if (Z_TYPE(method) == IS_STRING) { \
			method_len = Z_STRLEN(method); \
			method_name = zend_str_tolower_dup(Z_STRVAL(method), method_len); \
		} else { \
			method_len = 0; \
			method_name = zend_str_tolower_dup("", 0); \
		} \
		ZEPHIR_LAST_CALL_STATUS = zephir_return_call_class_method(return_value, class_entry, zephir_fcall_ce, NULL, method_name, method_len, cache, cache_slot, ZEPHIR_CALL_NUM_PARAMS(params_), ZEPHIR_PASS_CALL_PARAMS(params_)); \
		efree(method_name); \
	} while (0)

/** Use these functions to call functions in the PHP userland using an arbitrary zval as callable */
#define ZEPHIR_CALL_USER_FUNC(return_value, handler) ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, handler, NULL)
#define ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, handler, params) \
	do { \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_user_func_array(return_value, handler, params); \
	} while (0)

#define ZEPHIR_CALL_USER_FUNC_ARRAY_NOEX(return_value, handler, params) \
	do { \
		ZEPHIR_LAST_CALL_STATUS = zephir_call_user_func_array_noex(return_value, handler, params); \
	} while (0)

int zephir_call_func_aparams(zval *return_value_ptr, const char *func_name, uint32_t func_length,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint32_t param_count, zval **params);

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

ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_return_call_function(zval *return_value,
	const char *func, uint32_t func_len, zephir_fcall_cache_entry **cache_entry, int cache_slot, uint32_t param_count, zval **params)
{
	zval rv, *rvp = return_value ? return_value : &rv;
	int status;

	if (return_value) {
		zval_ptr_dtor(return_value);
		ZVAL_UNDEF(return_value);
	}

	status = zephir_call_func_aparams(rvp, func, func_len, cache_entry, cache_slot, param_count, params);

	if (status == FAILURE) {
		if (return_value && EG(exception)) {
			ZVAL_NULL(return_value);
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

	if (return_value) {
		zval_ptr_dtor(return_value);
		ZVAL_UNDEF(return_value);
	}

	status = zephir_call_zval_func_aparams(rvp, func, cache_entry, cache_slot, param_count, params);

	if (status == FAILURE) {
		if (return_value && EG(exception)) {
			ZVAL_NULL(return_value);
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
		if (return_value && EG(exception)) {
			ZVAL_NULL(return_value);
		}

		return FAILURE;
	}

	if (!return_value) {
		zval_ptr_dtor(&rv);
	}

	return SUCCESS;
}

/** Fast call_user_func_array/call_user_func */
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params) ZEPHIR_ATTR_WARN_UNUSED_RESULT;

/**
 * Replaces call_user_func_array avoiding function lookup
 */
ZEPHIR_ATTR_WARN_UNUSED_RESULT static inline int zephir_call_user_func_array(zval *return_value, zval *handler, zval *params)
{
	int status = zephir_call_user_func_array_noex(return_value, handler, params);
	return (EG(exception)) ? FAILURE : status;
}

int zephir_has_constructor_ce(const zend_class_entry *ce) ZEPHIR_ATTR_PURE ZEPHIR_ATTR_NONNULL;

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

static inline void zephir_set_called_scope(zend_execute_data *ex, zend_class_entry *called_scope)
{
	while (ex) {
		if (Z_TYPE(ex->This) == IS_OBJECT) {
			Z_OBJCE(ex->This) = called_scope;
			return;
		}else if (ex->func) {
			if (ex->func->type != ZEND_INTERNAL_FUNCTION || ex->func->common.scope) {
				return;
			}
		} else {
			Z_CE(ex->This) = called_scope;
			return;
		}
		ex = ex->prev_execute_data;
	}
}

#endif /* ZEPHIR_KERNEL_FCALL_H */
