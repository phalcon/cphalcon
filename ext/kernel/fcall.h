
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_KERNEL_FCALL_H
#define PHALCON_KERNEL_FCALL_H

#include "php_phalcon.h"
#include "kernel/main.h"
#include "kernel/memory.h"

#include <Zend/zend_hash.h>
#include <Zend/zend.h>

typedef enum _phalcon_call_type {
	phalcon_fcall_parent,
	phalcon_fcall_self,
	phalcon_fcall_static,
	phalcon_fcall_ce,
	phalcon_fcall_method,
	phalcon_fcall_function
} phalcon_call_type;

#ifndef PHALCON_RELEASE

typedef struct _phalcon_fcall_cache_entry {
	zend_function *f;
	zend_uint times;
} phalcon_fcall_cache_entry;

#else

typedef zend_function phalcon_fcall_cache_entry;

#endif

/**
 * @addtogroup callfuncs Calling Functions
 * @{
 */
#define PHALCON_FUNC_STRLEN(x) (__builtin_constant_p(x) ? (sizeof(x)-1) : strlen(x))

#if defined(_MSC_VER)
#define PHALCON_PASS_CALL_PARAMS(x) x + 1
#define PHALCON_CALL_NUM_PARAMS(x) ((sizeof(x) - sizeof(x[0]))/sizeof(x[0]))
#define PHALCON_FETCH_VA_ARGS NULL,
#else
#define PHALCON_PASS_CALL_PARAMS(x) x
#define PHALCON_CALL_NUM_PARAMS(x) sizeof(x)/sizeof(zval*)
#define PHALCON_FETCH_VA_ARGS
#endif

#define PHALCON_CALL_FUNCTIONW(return_value_ptr, func_name, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_call_func_aparams(return_value_ptr, func_name, PHALCON_FUNC_STRLEN(func_name), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)


#define PHALCON_CALL_FUNCTION(return_value_ptr, func_name, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_func_aparams(return_value_ptr, func_name, PHALCON_FUNC_STRLEN(func_name), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_ZVAL_FUNCTIONW(return_value_ptr, func_name, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_call_zval_func_aparams(return_value_ptr, func_name, PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_ZVAL_FUNCTION(return_value_ptr, func_name, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_zval_func_aparams(return_value_ptr, func_name, PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_FUNCTIONW(func_name, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_return_call_function(return_value, return_value_ptr, func_name, PHALCON_FUNC_STRLEN(func_name), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_FUNCTION(func_name, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_MM_ON_FAILURE(phalcon_return_call_function(return_value, return_value_ptr, func_name, PHALCON_FUNC_STRLEN(func_name), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_ZVAL_FUNCTIONW(func_name, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_return_call_zval_function(return_value, return_value_ptr, func_name, PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_ZVAL_FUNCTION(func_name, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		RETURN_MM_ON_FAILURE(phalcon_return_call_zval_function(return_value, return_value_ptr, func_name, PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_METHODW(return_value_ptr, object, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, Z_OBJCE_P(object), phalcon_fcall_method, object, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_METHOD(return_value_ptr, object, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, Z_OBJCE_P(object), phalcon_fcall_method, object, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_METHOD_ARRAYW(return_value_ptr, object, method, params) \
	do { \
		RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, Z_OBJCE_P(object), phalcon_fcall_method, object, method, PHALCON_FUNC_STRLEN(method), sizeof(params)/sizeof(zval*), params TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_METHOD_ARRAY(return_value_ptr, object, method, params) \
	do { \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, Z_OBJCE_P(object), phalcon_fcall_method, object, method, PHALCON_FUNC_STRLEN(method), sizeof(params)/sizeof(zval*), params TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_METHODW(object, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, Z_OBJCE_P(object), phalcon_fcall_method, object, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_METHOD(object, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_MM_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, Z_OBJCE_P(object), phalcon_fcall_method, object, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_ZVAL_METHODW(return_value_ptr, object, method, ...) \
	do { \
		char *method_name; \
		int method_len; \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		if (Z_TYPE_P(method) == IS_STRING) { \
			method_len = Z_STRLEN_P(method); \
			method_name = zend_str_tolower_dup(Z_STRVAL_P(method), method_len); \
		} else { \
			method_len = 0; \
			method_name = zend_str_tolower_dup("", 0); \
		} \
		RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, phalcon_fcall_method, object, method_name, method_len, PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
		efree(method_name); \
	} while (0)

#define PHALCON_CALL_ZVAL_METHOD(return_value_ptr, object, method, ...) \
	do { \
		char *method_name; \
		int method_len; \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		if (Z_TYPE_P(method) == IS_STRING) { \
			method_len = Z_STRLEN_P(method); \
			method_name = zend_str_tolower_dup(Z_STRVAL_P(method), method_len); \
		} else { \
			method_len = 0; \
			method_name = zend_str_tolower_dup("", 0); \
		} \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, phalcon_fcall_method, object, method_name, method_len, PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
		efree(method_name); \
	} while (0)

#define PHALCON_RETURN_CALL_ZVAL_METHODW(object, method, ...) \
	do { \
		char *method_name; \
		int method_len; \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		if (Z_TYPE_P(method) == IS_STRING) { \
			method_len = Z_STRLEN_P(method); \
			method_name = zend_str_tolower_dup(Z_STRVAL_P(method), method_len); \
		} else { \
			method_len = 0; \
			method_name = zend_str_tolower_dup("", 0); \
		} \
		RETURN_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, phalcon_fcall_method, object, method_name, method_len, PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
		efree(method_name); \
	} while (0)

#define PHALCON_RETURN_CALL_ZVAL_METHOD(object, method, ...) \
	do { \
		char *method_name; \
		int method_len; \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		if (Z_TYPE_P(method) == IS_STRING) { \
			method_len = Z_STRLEN_P(method); \
			method_name = zend_str_tolower_dup(Z_STRVAL_P(method), method_len); \
		} else { \
			method_len = 0; \
			method_name = zend_str_tolower_dup("", 0); \
		} \
		RETURN_MM_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, Z_TYPE_P(object) == IS_OBJECT ? Z_OBJCE_P(object) : NULL, phalcon_fcall_method, object, method_name, method_len, PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
		efree(method_name); \
	} while (0)

#define PHALCON_CALL_PARENTW(return_value_ptr, class_entry, object, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, class_entry, phalcon_fcall_parent, object, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_PARENT(return_value_ptr, class_entry, object, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, class_entry, phalcon_fcall_parent, object, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_PARENTW(class_entry, object, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, class_entry, phalcon_fcall_parent, object, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_PARENT(class_entry, object, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_MM_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, class_entry, phalcon_fcall_parent, object, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)


#define PHALCON_CALL_SELFW(return_value_ptr, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, NULL, phalcon_fcall_self, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_SELF(return_value_ptr, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, NULL, phalcon_fcall_self, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_SELFW(method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, NULL, phalcon_fcall_self, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_SELF(method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_MM_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, NULL, phalcon_fcall_self, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)


#define PHALCON_CALL_STATICW(return_value_ptr, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, NULL, phalcon_fcall_static, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_STATIC(return_value_ptr, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, NULL, phalcon_fcall_static, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_STATICW(method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, NULL, phalcon_fcall_static, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_STATIC(method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_MM_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, NULL, phalcon_fcall_static, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_CE_STATICW(return_value_ptr, class_entry, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, class_entry, phalcon_fcall_ce, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)


#define PHALCON_CALL_CE_STATIC(return_value_ptr, class_entry, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		PHALCON_OBSERVE_OR_NULLIFY_PPZV(return_value_ptr); \
		RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, class_entry, phalcon_fcall_ce, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_CE_STATICW(class_entry, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, class_entry, phalcon_fcall_ce, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

#define PHALCON_RETURN_CALL_CE_STATIC(class_entry, method, ...) \
	do { \
		zval *params_[] = {PHALCON_FETCH_VA_ARGS __VA_ARGS__}; \
		RETURN_MM_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, class_entry, phalcon_fcall_ce, NULL, method, PHALCON_FUNC_STRLEN(method), PHALCON_CALL_NUM_PARAMS(params_), PHALCON_PASS_CALL_PARAMS(params_) TSRMLS_CC)); \
	} while (0)

/** Use these functions to call functions in the PHP userland using an arbitrary zval as callable */
#define PHALCON_CALL_USER_FUNC(return_value, handler) PHALCON_CALL_USER_FUNC_ARRAY(return_value, handler, NULL)
#define PHALCON_CALL_USER_FUNC_ARRAY(return_value, handler, params) \
	do { \
		RETURN_MM_ON_FAILURE(phalcon_call_user_func_array(return_value, handler, params TSRMLS_CC)); \
	} while (0)

#define PHALCON_CALL_USER_FUNC_ARRAY_NOEX(return_value, handler, params) \
	do { \
		RETURN_MM_ON_FAILURE(phalcon_call_user_func_array_noex(return_value, handler, params TSRMLS_CC)); \
	} while (0)

int phalcon_call_func_aparams(zval **return_value_ptr, const char *func_name, uint func_length, uint param_count, zval **params TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;

int phalcon_call_zval_func_aparams(zval **return_value_ptr, zval *func_name, uint param_count, zval **params TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;

/**
 * @ingroup callfuncs
 * @brief Calls a function @a func
 * @param return_value Calling function's @c return_value
 * @param return_value_ptr Calling function's @c return_value_ptr
 * @param func Function name
 * @param func_len Length of @a func (<tt>strlen(func)</tt>)
 * @param param_count Number of parameters
 */
PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_return_call_function(zval *return_value, zval **return_value_ptr, const char *func, uint func_len, uint param_count, zval **params TSRMLS_DC)
{
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	int status;

	if (return_value_ptr) {
		phalcon_ptr_dtor(return_value_ptr);
		*return_value_ptr = NULL;
	}

	status = phalcon_call_func_aparams(rvp, func, func_len, param_count, params TSRMLS_CC);

	if (status == FAILURE) {
		if (return_value_ptr && EG(exception)) {
			ALLOC_INIT_ZVAL(*return_value_ptr);
		}

		return FAILURE;
	}

	if (!return_value_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, rv);
	}

	return SUCCESS;
}

/**
 * @ingroup callfuncs
 * @brief Calls a function @a func
 * @param return_value Calling function's @c return_value
 * @param return_value_ptr Calling function's @c return_value_ptr
 * @param func Function name
 * @param func_len Length of @a func (<tt>strlen(func)</tt>)
 * @param param_count Number of parameters
 */
PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_return_call_zval_function(zval *return_value, zval **return_value_ptr, zval *func, uint param_count, zval **params TSRMLS_DC)
{
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	int status;

	if (return_value_ptr) {
		phalcon_ptr_dtor(return_value_ptr);
		*return_value_ptr = NULL;
	}

	status = phalcon_call_zval_func_aparams(rvp, func, param_count, params TSRMLS_CC);

	if (status == FAILURE) {
		if (return_value_ptr && EG(exception)) {
			ALLOC_INIT_ZVAL(*return_value_ptr);
		}

		return FAILURE;
	}

	if (!return_value_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, rv);
	}

	return SUCCESS;
}

int phalcon_call_class_method_aparams(zval **return_value_ptr, zend_class_entry *ce, phalcon_call_type type, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;

PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_return_call_class_method(zval *return_value, zval **return_value_ptr, zend_class_entry *ce, phalcon_call_type type, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	int status;

	if (return_value_ptr) {
		phalcon_ptr_dtor(return_value_ptr);
		*return_value_ptr = NULL;
	}

	status = phalcon_call_class_method_aparams(rvp, ce, type, object, method_name, method_len, param_count, params TSRMLS_CC);

	if (status == FAILURE) {
		if (return_value_ptr && EG(exception)) {
			ALLOC_INIT_ZVAL(*return_value_ptr);
		}

		return FAILURE;
	}

	if (!return_value_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, rv);
	}

	return SUCCESS;
}

/**
 * @brief $object->$method()
 */
PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL2(2, 3)
static inline int phalcon_call_method(zval **return_value_ptr, zval *object, const char *method, uint nparams, zval **params TSRMLS_DC)
{
	return phalcon_call_class_method_aparams(return_value_ptr, Z_OBJCE_P(object), phalcon_fcall_method, object, method, strlen(method), nparams, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL3(1, 3, 4)
static inline int phalcon_return_call_method(zval *return_value, zval **return_value_ptr, zval *object, const char *method, uint nparams, zval **params TSRMLS_DC)
{
	return phalcon_return_call_class_method(return_value, return_value_ptr, Z_OBJCE_P(object), phalcon_fcall_method, object, method, strlen(method), nparams, params TSRMLS_CC);
}

/**
 * @brief static::$method()
 */
PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL1(2)
static inline int phalcon_call_static(zval **return_value_ptr, const char *method, uint nparams, zval **params TSRMLS_DC)
{
	return phalcon_call_class_method_aparams(return_value_ptr, NULL, phalcon_fcall_static, NULL, method, strlen(method), nparams, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL2(1, 3)
static inline int phalcon_return_call_static(zval *return_value, zval **return_value_ptr, const char *method, uint nparams, zval **params TSRMLS_DC)
{
	return phalcon_return_call_class_method(return_value, return_value_ptr, NULL, phalcon_fcall_static, NULL, method, strlen(method), nparams, params TSRMLS_CC);
}

/**
 * @brief self::$method()
 */
PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL1(2)
static inline int phalcon_call_self(zval **return_value_ptr, const char *method, uint nparams, zval **params TSRMLS_DC)
{
	return phalcon_call_class_method_aparams(return_value_ptr, NULL, phalcon_fcall_self, NULL, method, strlen(method), nparams, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL2(1, 3)
static inline int phalcon_return_call_self(zval *return_value, zval **return_value_ptr, const char *method, uint nparams, zval **params TSRMLS_DC)
{
	return phalcon_return_call_class_method(return_value, return_value_ptr, NULL, phalcon_fcall_self, NULL, method, strlen(method), nparams, params TSRMLS_CC);
}

/**
 * @brief $ce::$method()
 */
PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL2(2, 3)
static inline int phalcon_call_ce(zval **return_value_ptr, zend_class_entry *ce, const char *method, uint nparams, zval **params TSRMLS_DC)
{
	return phalcon_call_class_method_aparams(return_value_ptr, ce, phalcon_fcall_ce, NULL, method, strlen(method), nparams, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL3(1, 3, 4)
static inline int phalcon_return_call_ce(zval *return_value, zval **return_value_ptr, zend_class_entry *ce, const char *method, uint nparams, zval **params TSRMLS_DC)
{
	return phalcon_return_call_class_method(return_value, return_value_ptr, ce, phalcon_fcall_ce, NULL, method, strlen(method), nparams, params TSRMLS_CC);
}

/** Fast call_user_func_array/call_user_func */
int phalcon_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;

/**
 * Replaces call_user_func_array avoiding function lookup
 */
PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_call_user_func_array(zval *return_value, zval *handler, zval *params TSRMLS_DC)
{
	int status = phalcon_call_user_func_array_noex(return_value, handler, params TSRMLS_CC);
	return (EG(exception)) ? FAILURE : status;
}

#ifndef PHALCON_RELEASE
void phalcon_fcall_cache_dtor(void *pData);
#endif

int phalcon_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key);

/**
 * @brief Checks if the class defines a constructor
 * @param ce Class entry
 * @return Whether the class defines a constructor
 */
int phalcon_has_constructor_ce(const zend_class_entry *ce) PHALCON_ATTR_PURE PHALCON_ATTR_NONNULL;

/**
 * @brief Checks if an object has a constructor
 * @param object Object to check
 * @return Whether @a object has a constructor
 * @retval 0 @a object is not an object or does not have a constructor
 * @retval 1 @a object has a constructor
 */
PHALCON_ATTR_WARN_UNUSED_RESULT PHALCON_ATTR_NONNULL static inline int phalcon_has_constructor(const zval *object TSRMLS_DC)
{
	return Z_TYPE_P(object) == IS_OBJECT ? phalcon_has_constructor_ce(Z_OBJCE_P(object)) : 0;
}

/** PHP < 5.3.9 has problems with closures */
#if PHP_VERSION_ID <= 50309
int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC);
#define PHALCON_ZEND_CALL_FUNCTION_WRAPPER phalcon_call_function
#else

#if PHP_VERSION_ID >= 50600
int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC);
#define PHALCON_ZEND_CALL_FUNCTION_WRAPPER phalcon_call_function
#else
#define PHALCON_ZEND_CALL_FUNCTION_WRAPPER zend_call_function
#endif

#endif

#ifndef zend_error_noreturn
#define zend_error_noreturn zend_error
#endif

void phalcon_eval_php(zval *str, zval *retval_ptr, char *context TSRMLS_DC);

#endif /* PHALCON_KERNEL_FCALL_H */
