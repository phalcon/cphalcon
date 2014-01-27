
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
#include <Zend/zend_hash.h>
#include <Zend/zend.h>

/**
 * @addtogroup callfuncs Calling Functions
 * @{
 */

/**
 * @brief Invokes a function @a func_name and returns if the function fails due to an error or exception.
 * @param[out] return_value_ptr function return value (<tt>zval**</tt>); can be @c NULL (in this case it is assumed that the caller is not interested in the return value)
 * @param[in] func_name name of the function to call (<tt>const char*</tt>)
 * @param arguments function arguments (<tt>zval*</tt>)
 * @note If the call fails or an exception occurs, the memory frame is @em not restored.
 * In this case if @c return_value_ptr is not @c NULL, <tt>*return_value_ptr</tt> is set to @c NULL
 */
#define PHALCON_CALL_FUNCTIONW(return_value_ptr, func_name, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(func_name)) { \
			RETURN_ON_FAILURE(phalcon_call_func_aparams(return_value_ptr, func_name, sizeof(func_name)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_call_func_aparams(return_value_ptr, func_name, strlen(func_name), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

/**
 * @brief Invokes a function @a func_name and returns if the function fails due to an error or exception.
 * @param[out] return_value_ptr function return value (<tt>zval**</tt>); can be @c NULL (in this case it is assumed that the caller is not interested in the return value)
 * @param[in] func_name name of the function to call (<tt>const char*</tt>)
 * @param arguments function arguments (<tt>zval*</tt>)
 * @note If the call fails or an exception occurs, the memory frame is restored.
 * In this case if @c return_value_ptr is not @c NULL, <tt>*return_value_ptr</tt> is set to @c NULL
 */
#define PHALCON_CALL_FUNCTION(return_value_ptr, func_name, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(func_name)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_func_aparams(return_value_ptr, func_name, sizeof(func_name)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_func_aparams(return_value_ptr, func_name, strlen(func_name), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

/**
 * @brief Invokes a function @a func_name and returns if the function fails due to an error or exception.
 * @param[in] func_name name of the function to call (<tt>const char*</tt>)
 * @param arguments function arguments (<tt>zval*</tt>)
 * @note If the call fails or an exception occurs, the memory frame is restored.
 * In this case if @c return_value_ptr is not @c NULL, <tt>*return_value_ptr</tt> is set to @c NULL
 * @details This is equivalent to <tt>PHALCON_CALL_FUNCTION(NULL, func_name, parameters)</tt>
 */
#define PHALCON_CALL_FUNCTION_NORET(func_name, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(func_name)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_func_aparams(NULL, func_name, sizeof(func_name)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_func_aparams(NULL, func_name, strlen(func_name), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

/**
 * @brief Invokes a function @a func_name passing @c return_value and @c return_value_ptr
 * as return value address; returns if the function fails due to an error or exception.
 * @param[in] func_name name of the function to call (<tt>const char*</tt>)
 * @param arguments function arguments (<tt>zval*</tt>)
 * @note If the call fails or an exception occurs, the memory frame is @em not restored.
 * @li if @c return_value_ptr is not @c NULL, @c *return_value_ptr is initialized with @c ALLOC_INIT_ZVAL
 * @li otherwise, if @c return_value is not @c NULL, @c return_value and @c *return_value are not changed
 */
#define PHALCON_RETURN_CALL_FUNCTIONW(func_name, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(func_name)) { \
			RETURN_ON_FAILURE(phalcon_return_call_function(return_value, return_value_ptr, func_name, sizeof(func_name)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_return_call_function(return_value, return_value_ptr, func_name, strlen(func_name), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

/**
 * @brief Invokes a function @a func_name passing @c return_value and @c return_value_ptr
 * as return value address; returns if the function fails due to an error or exception.
 * @param[in] func_name name of the function to call (<tt>const char*</tt>)
 * @param arguments function arguments (<tt>zval*</tt>)
 * @note If the call fails or an exception occurs, the memory frame is restored.
 * @li if @c return_value_ptr is not @c NULL, @c *return_value_ptr is initialized with @c ALLOC_INIT_ZVAL
 * @li otherwise, if @c return_value is not @c NULL, @c return_value and @c *return_value are not changed
 */
#define PHALCON_RETURN_CALL_FUNCTION(func_name, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(func_name)) { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_function(return_value, return_value_ptr, func_name, sizeof(func_name)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_function(return_value, return_value_ptr, func_name, strlen(func_name), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

/**
 * @}
 */

#define PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method, key_, nparams, ...) \
	do { \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_method_params(return_value, return_value_ptr, object, method, sizeof(method)-1, key_ TSRMLS_CC, nparams, __VA_ARGS__)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_method_params(return_value, return_value_ptr, object, method, strlen(method), key_ TSRMLS_CC, nparams, __VA_ARGS__)); \
		} \
	} while (0)

#define PHALCON_RETURN_CALL_METHOD(object, method, key_, nparams, ...) \
	do { \
		if (__builtin_constant_p(method)) { \
			if (phalcon_call_method_params(return_value, return_value_ptr, object, method, sizeof(method)-1, key_ TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				if (return_value_ptr && EG(exception)) { \
					ALLOC_INIT_ZVAL(*return_value_ptr); \
				} \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
		else { \
			if (phalcon_call_method_params(return_value, return_value_ptr, object, method, strlen(method), key_ TSRMLS_CC, nparams, __VA_ARGS__) == FAILURE) { \
				if (return_value_ptr && EG(exception)) { \
					ALLOC_INIT_ZVAL(*return_value_ptr); \
				} \
				PHALCON_MM_RESTORE(); \
				return; \
			} \
		} \
	} while (0)

#define PHALCON_CALL_PARENTW(return_value_ptr, class_entry, this_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_ON_FAILURE(phalcon_call_parent_func_aparams(return_value_ptr, class_entry, this_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_call_parent_func_aparams(return_value_ptr, class_entry, this_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_PARENT(return_value_ptr, class_entry, this_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_parent_func_aparams(return_value_ptr, class_entry, this_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_parent_func_aparams(return_value_ptr, class_entry, this_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_PARENT_NORET(class_entry, this_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_parent_func_aparams(NULL, class_entry, this_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_parent_func_aparams(NULL, class_entry, this_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_RETURN_CALL_PARENTW(class_entry, this_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_ON_FAILURE(phalcon_return_call_parent_func(return_value, return_value_ptr, class_entry, this_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_return_call_parent_func(return_value, return_value_ptr, class_entry, this_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_RETURN_CALL_PARENT(class_entry, this_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_parent_func(return_value, return_value_ptr, class_entry, this_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_parent_func(return_value, return_value_ptr, class_entry, this_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_SELFW(return_value_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_ON_FAILURE(phalcon_call_self_func_aparams(return_value_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_call_self_func_aparams(return_value_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_SELF(return_value_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_self_func_aparams(return_value_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_self_func_aparams(return_value_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_SELF_NORET(method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_self_func_aparams(NULL, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_self_func_aparams(NULL, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_RETURN_CALL_SELFW(method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_ON_FAILURE(phalcon_return_call_self_func(return_value, return_value_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_return_call_self_func(return_value, return_value_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_RETURN_CALL_SELF(method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_self_func(return_value, return_value_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_self_func(return_value, return_value_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_STATICW(return_value_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_ON_FAILURE(phalcon_call_static_func_aparams(return_value_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_call_static_func_aparams(return_value_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_STATIC(return_value_ptr, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_static_func_aparams(return_value_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_static_func_aparams(return_value_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_STATIC_NORET(method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_self_func_aparams(NULL, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_self_func_aparams(NULL, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_RETURN_CALL_STATICW(method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_ON_FAILURE(phalcon_return_call_static_func(return_value, return_value_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_return_call_static_func(return_value, return_value_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_RETURN_STATIC_SELF(method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_static_func(return_value, return_value_ptr, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_static_func(return_value, return_value_ptr, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_CE_STATICW(return_value_ptr, class_entry, method, ...) \
	do { \
		zval *params[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, class_entry, NULL, method, sizeof(method)-1, sizeof(params)/sizeof(zval*), params TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, class_entry, NULL, method, strlen(method), sizeof(params)/sizeof(zval*), params TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_CE_STATIC(return_value_ptr, class_entry, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, class_entry, NULL, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(return_value_ptr, class_entry, NULL, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_CALL_CE_STATIC_NORET(class_entry, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(NULL, class_entry, NULL, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_call_class_method_aparams(NULL, class_entry, NULL, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_RETURN_CALL_CE_STATICW(class_entry, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, class_entry, NULL, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, class_entry, NULL, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
	} while (0)

#define PHALCON_RETURN_CALL_CE_STATIC(class_entry, method, ...) \
	do { \
		zval *params_[] = {__VA_ARGS__}; \
		if (__builtin_constant_p(method)) { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, class_entry, NULL, method, sizeof(method)-1, sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
		else { \
			RETURN_MM_ON_FAILURE(phalcon_return_call_class_method(return_value, return_value_ptr, class_entry, NULL, method, strlen(method), sizeof(params_)/sizeof(zval*), params_ TSRMLS_CC)); \
		} \
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

/** Macros to call methods in the PHP userland */
#define phalcon_call_method_p0_key_ex(return_value, return_value_ptr, object, method_name, key) \
	do { \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 0, NULL); \
	} while (0)

#define phalcon_call_method_p1_key_ex(return_value, return_value_ptr, object, method_name, key, p1) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 1, p1); \
	} while (0)

#define phalcon_call_method_p2_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 2, p1, p2); \
	} while (0)

#define phalcon_call_method_p3_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 3, p1, p2, p3); \
	} while (0)

#define phalcon_call_method_p4_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3, p4) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 4, p1, p2, p3, p4); \
	} while (0)

#define phalcon_call_method_p5_key_ex(return_value, return_value_ptr, object, method_name, key, p1, p2, p3, p4, p5) \
	do { \
		if (0) { \
			if (Z_TYPE_P(p1)) {} \
			if (Z_TYPE_P(p2)) {} \
			if (Z_TYPE_P(p3)) {} \
			if (Z_TYPE_P(p4)) {} \
			if (Z_TYPE_P(p5)) {} \
		} \
		PHALCON_CALL_METHOD(return_value, return_value_ptr, object, method_name, key, 5, p1, p2, p3, p4, p5); \
	} while (0)

#define phalcon_return_call_method_p0_key(object, method_name, key)                               PHALCON_RETURN_CALL_METHOD(object, method_name, key, 0, NULL)
#define phalcon_return_call_method_p1_key(object, method_name, key, p1)                           PHALCON_RETURN_CALL_METHOD(object, method_name, key, 1, p1)
#define phalcon_return_call_method_p2_key(object, method_name, key, p1, p2)                       PHALCON_RETURN_CALL_METHOD(object, method_name, key, 2, p1, p2)
#define phalcon_return_call_method_p3_key(object, method_name, key, p1, p2, p3)                   PHALCON_RETURN_CALL_METHOD(object, method_name, key, 3, p1, p2, p3)
#define phalcon_return_call_method_p4_key(object, method_name, key, p1, p2, p3, p4)               PHALCON_RETURN_CALL_METHOD(object, method_name, key, 4, p1, p2, p3, p4)
#define phalcon_return_call_method_p5_key(object, method_name, key, p1, p2, p3, p4, p5)           PHALCON_RETURN_CALL_METHOD(object, method_name, key, 5, p1, p2, p3, p4, p5)

#define phalcon_return_call_method_p0(object, method_name)                                        phalcon_return_call_method_p0_key(object, method_name, 0)
#define phalcon_return_call_method_p1(object, method_name, p1)                                    phalcon_return_call_method_p1_key(object, method_name, 0, p1)
#define phalcon_return_call_method_p2(object, method_name, p1, p2)                                phalcon_return_call_method_p2_key(object, method_name, 0, p1, p2)
#define phalcon_return_call_method_p3(object, method_name, p1, p2, p3)                            phalcon_return_call_method_p3_key(object, method_name, 0, p1, p2, p3)
#define phalcon_return_call_method_p4(object, method_name, p1, p2, p3, p4)                        phalcon_return_call_method_p4_key(object, method_name, 0, p1, p2, p3, p4)
#define phalcon_return_call_method_p5(object, method_name, p1, p2, p3, p4, p5)                    phalcon_return_call_method_p5_key(object, method_name, 0, p1, p2, p3, p4, p5)

#define phalcon_call_method_p0_ex(return_value, return_value_ptr, object, method_name)                               phalcon_call_method_p0_key_ex(return_value, return_value_ptr, object, method_name, 0)
#define phalcon_call_method_p1_ex(return_value, return_value_ptr, object, method_name, p1)                           phalcon_call_method_p1_key_ex(return_value, return_value_ptr, object, method_name, 0, p1)
#define phalcon_call_method_p2_ex(return_value, return_value_ptr, object, method_name, p1, p2)                       phalcon_call_method_p2_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2)
#define phalcon_call_method_p3_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3)                   phalcon_call_method_p3_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3)
#define phalcon_call_method_p4_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3, p4)               phalcon_call_method_p4_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3, p4)
#define phalcon_call_method_p5_ex(return_value, return_value_ptr, object, method_name, p1, p2, p3, p4, p5)           phalcon_call_method_p5_key_ex(return_value, return_value_ptr, object, method_name, 0, p1, p2, p3, p4, p5)

#define phalcon_call_method(return_value, object, method_name)                                                       phalcon_call_method_p0_ex(return_value, NULL, object, method_name)
#define phalcon_call_method_p1(return_value, object, method_name, p1)                                                phalcon_call_method_p1_ex(return_value, NULL, object, method_name, p1)
#define phalcon_call_method_p2(return_value, object, method_name, p1, p2)                                            phalcon_call_method_p2_ex(return_value, NULL, object, method_name, p1, p2)
#define phalcon_call_method_p3(return_value, object, method_name, p1, p2, p3)                                        phalcon_call_method_p3_ex(return_value, NULL, object, method_name, p1, p2, p3)
#define phalcon_call_method_p4(return_value, object, method_name, p1, p2, p3, p4)                                    phalcon_call_method_p4_ex(return_value, NULL, object, method_name, p1, p2, p3, p4)
#define phalcon_call_method_p5(return_value, object, method_name, p1, p2, p3, p4, p5)                                phalcon_call_method_p5_ex(return_value, NULL, object, method_name, p1, p2, p3, p4, p5)

#define phalcon_call_method_noret(object, method_name)                                                               phalcon_call_method_p0_ex(NULL, NULL, object, method_name)
#define phalcon_call_method_p1_noret(object, method_name, p1)                                                        phalcon_call_method_p1_ex(NULL, NULL, object, method_name, p1)
#define phalcon_call_method_p2_noret(object, method_name, p1, p2)                                                    phalcon_call_method_p2_ex(NULL, NULL, object, method_name, p1, p2)
#define phalcon_call_method_p3_noret(object, method_name, p1, p2, p3)                                                phalcon_call_method_p3_ex(NULL, NULL, object, method_name, p1, p2, p3)
#define phalcon_call_method_p4_noret(object, method_name, p1, p2, p3, p4)                                            phalcon_call_method_p4_ex(NULL, NULL, object, method_name, p1, p2, p3, p4)
#define phalcon_call_method_p5_noret(object, method_name, p1, p2, p3, p4, p5)                                        phalcon_call_method_p5_ex(NULL, NULL, object, method_name, p1, p2, p3, p4, p5)

#define phalcon_call_method_key(return_value, object, method_name, key)                                              phalcon_call_method_p0_key_ex(return_value, NULL, object, method_name, key)
#define phalcon_call_method_p1_key(return_value, object, method_name, key, p1)                                       phalcon_call_method_p1_key_ex(return_value, NULL, object, method_name, key, p1)
#define phalcon_call_method_p2_key(return_value, object, method_name, key, p1, p2)                                   phalcon_call_method_p2_key_ex(return_value, NULL, object, method_name, key, p1, p2)
#define phalcon_call_method_p3_key(return_value, object, method_name, key, p1, p2, p3)                               phalcon_call_method_p3_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3)
#define phalcon_call_method_p4_key(return_value, object, method_name, key, p1, p2, p3, p4)                           phalcon_call_method_p4_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3, p4)
#define phalcon_call_method_p5_key(return_value, object, method_name, key, p1, p2, p3, p4, p5)                       phalcon_call_method_p5_key_ex(return_value, NULL, object, method_name, key, p1, p2, p3, p4, p5)

int phalcon_call_func_params(zval **return_value_ptr, const char *func_name, uint func_length TSRMLS_DC, int param_count, ...) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_call_func_vparams(zval **return_value_ptr, const char *func_name, uint func_length, int param_count, va_list ap TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_call_func_aparams(zval **return_value_ptr, const char *func_name, uint func_length, uint param_count, zval **params TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;

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
		zval_ptr_dtor(return_value_ptr);
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

int phalcon_call_class_method_aparams(zval **return_value_ptr, const zend_class_entry *ce, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_call_class_method_vparams(zval **return_value_ptr, const zend_class_entry *ce, zval *object, const char *method_name, uint method_len, int param_count, va_list ap TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_call_class_method_params(zval **return_value_ptr, const zend_class_entry *ce, zval *object, const char *method_name, uint method_len TSRMLS_DC, int param_count, ...) PHALCON_ATTR_WARN_UNUSED_RESULT;

PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_return_call_class_method(zval *return_value, zval **return_value_ptr, const zend_class_entry *ce, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	int status;

	if (return_value_ptr) {
		zval_ptr_dtor(return_value_ptr);
		*return_value_ptr = NULL;
	}

	status = phalcon_call_class_method_aparams(rvp, ce, object, method_name, method_len, param_count, params TSRMLS_CC);

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

PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_call_parent_func_aparams(zval **return_value_ptr, zend_class_entry *ce, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	if (!ce) {
		ce = EG(scope);
		if (!ce) {
			zend_error(E_ERROR, "Cannot access parent:: when no class scope is active");
			return FAILURE;
		}
	}

	ce = ce->parent;
	if (!ce) {
		zend_error(E_ERROR, "Cannot access parent:: when current class scope has no parent");
		return FAILURE;
	}

	return phalcon_call_class_method_aparams(return_value_ptr, ce, object, method_name, method_len, param_count, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_return_call_parent_func(zval *return_value, zval **return_value_ptr, zend_class_entry *ce, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	if (!ce) {
		ce = EG(scope);
		if (!ce) {
			zend_error(E_ERROR, "Cannot access parent:: when no class scope is active");
			return FAILURE;
		}
	}

	ce = ce->parent;
	if (!ce) {
		zend_error(E_ERROR, "Cannot access parent:: when current class scope has no parent");
		return FAILURE;
	}

	return phalcon_return_call_class_method(return_value, return_value_ptr, ce, object, method_name, method_len, param_count, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_call_self_func_aparams(zval **return_value_ptr, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	if (!EG(scope)) {
		zend_error(E_ERROR, "Cannot access self:: when no class scope is active");
		return FAILURE;
	}

	return phalcon_call_class_method_aparams(return_value_ptr, EG(scope), NULL, method_name, method_len, param_count, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_return_call_self_func(zval *return_value, zval **return_value_ptr, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	if (!EG(scope)) {
		zend_error(E_ERROR, "Cannot access self:: when no class scope is active");
		return FAILURE;
	}

	return phalcon_return_call_class_method(return_value, return_value_ptr, EG(scope), NULL, method_name, method_len, param_count, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_call_static_func_aparams(zval **return_value_ptr, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	if (!EG(called_scope)) {
		zend_error(E_ERROR, "Cannot access static:: when no class scope is active");
		return FAILURE;
	}

	return phalcon_call_class_method_aparams(return_value_ptr, EG(scope), NULL, method_name, method_len, param_count, params TSRMLS_CC);
}

PHALCON_ATTR_WARN_UNUSED_RESULT static inline int phalcon_return_call_static_func(zval *return_value, zval **return_value_ptr, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	if (!EG(called_scope)) {
		zend_error(E_ERROR, "Cannot access static:: when no class scope is active");
		return FAILURE;
	}

	return phalcon_return_call_class_method(return_value, return_value_ptr, EG(scope), NULL, method_name, method_len, param_count, params TSRMLS_CC);
}

int phalcon_call_method_vparams(zval *return_value, zval **return_value_ptr, zval *object, const char *method_name, uint method_len, ulong method_key TSRMLS_DC, int param_count, va_list ap) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_call_method_params(zval *return_value, zval **return_value_ptr, zval *object, const char *method_name, uint method_len, ulong method_key TSRMLS_DC, int param_count, ...) PHALCON_ATTR_WARN_UNUSED_RESULT;

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
#define PHALCON_ZEND_CALL_FUNCTION_WRAPPER zend_call_function
#endif

#ifndef zend_error_noreturn
#define zend_error_noreturn zend_error
#endif

#endif /* PHALCON_KERNEL_FCALL_H */
