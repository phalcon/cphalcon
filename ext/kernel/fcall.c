
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"

#include "Zend/zend_API.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_execute.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

#include "kernel/alternative/fcall.h"

/**
 * Finds the correct scope to execute the function
 */
int phalcon_find_scope(zend_class_entry *ce, char *method_name, int method_len, int lower, ulong hash TSRMLS_DC){

	char *lcname;

	if (lower) {
		lcname = method_name;
	} else {
		lcname = zend_str_tolower_dup(method_name, method_len);
	}

	if (!hash) {
		hash = zend_inline_hash_func(lcname, method_len + 1);
	}

	while (ce) {
		if (phalcon_hash_quick_exists(&ce->function_table, lcname, method_len + 1, hash)) {
			EG(scope) = ce;
			if (!lower) {
				efree(lcname);
			}
			return SUCCESS;
		}
		ce = ce->parent;
	}

	if (!lower) {
		efree(lcname);
	}

	return FAILURE;
}

/**
 * Find out the function scope on parent classes
 */
static inline int phalcon_find_parent_scope(zend_class_entry *ce, const char *active_class, int active_class_len, char *method_name, int method_len TSRMLS_DC){

	char *lcname = zend_str_tolower_dup(method_name, method_len);
	ulong hash = zend_inline_hash_func(lcname, method_len + 1);

	while (ce) {
		if (ce->name_length == active_class_len) {
			if (!zend_binary_strcasecmp(ce->name, ce->name_length, active_class, active_class_len)) {
				if (phalcon_hash_quick_exists(&ce->function_table, lcname, method_len + 1, hash)) {
					EG(scope) = ce;
					efree(lcname);
					return SUCCESS;
				}
			}
		}
		ce = ce->parent;
	}

	efree(lcname);
	return FAILURE;
}

/**
 * Check if an object has a constructor
 */
int phalcon_has_constructor(const zval *object TSRMLS_DC){

	zend_class_entry *ce = Z_OBJCE_P(object);

	while (ce) {
		if (ce->constructor) {
			return 1;
		}
		ce = ce->parent;
	}

	return 0;
}

/**
 * @brief Calls function @a func_name which accepts @a param_count arguments @a params
 * @param[out] Return value; set to @c NULL if the return value is not needed
 * @param func_name Function name
 * @param func_length Length of the function name
 * @param param_count Number of arguments
 * @param params Arguments
 * @return Whether the call succeeded
 * @retval @c SUCCESS
 * @retval @c FAILURE
 * @note @c phalcon_memory_restore_stack() is NOT called upon failure
 */
int phalcon_call_func_params_w(zval *return_value, const char *func_name, int func_length, zend_uint param_count, zval *params[] TSRMLS_DC){
	zval *fn = NULL;
	int status;
	int caller_wants_result = 1;

	if (!return_value) {
		ALLOC_INIT_ZVAL(return_value);
		caller_wants_result = 0;
	}
#ifndef PHALCON_RELEASE
	else {
		int valid_return_value = 1;

		if (Z_REFCOUNT_P(return_value) > 1) {
			valid_return_value = 0;
			fprintf(stderr, "%s: return_value has %d references, expect crashes!\n", __func__, Z_REFCOUNT_P(return_value));
		} else if (Z_TYPE_P(return_value) > IS_BOOL) {
			valid_return_value = 0;
			fprintf(stderr, "%s: return_value is of complex type (%d), expect memory leaks!\n", __func__, Z_TYPE_P(return_value));
		}

		if (!valid_return_value) {
			phalcon_print_backtrace();
		}
	}
#endif

	ALLOC_INIT_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 0);

	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
	}

	ZVAL_NULL(fn);
	zval_ptr_dtor(&fn);

	if (!caller_wants_result) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)) {
		status = FAILURE;
	}

	return status;
}

/**
 * Call single function which requires arbitrary number of parameters
 */
int phalcon_call_func_params(zval *return_value, const char *func_name, int func_length, zend_uint param_count, zval *params[] TSRMLS_DC){

	int status = phalcon_call_func_params_w(return_value, func_name, func_length, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call single function which requires only 1 parameter
 */
int phalcon_call_func_one_param(zval *return_value, const char *func_name, int func_length, zval *param1 TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_func_params(return_value, func_name, func_length, 1, params TSRMLS_CC);
}

/**
 * Call single function which requires only 2 parameters
 */
int phalcon_call_func_two_params(zval *return_value, const char *func_name, int func_length, zval *param1, zval *param2 TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_func_params(return_value, func_name, func_length, 2, params TSRMLS_CC);
}

/**
 * Call single function which requires only 3 parameters
 */
int phalcon_call_func_three_params(zval *return_value, const char *func_name, int func_length, zval *param1, zval *param2, zval *param3 TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_func_params(return_value, func_name, func_length, 3, params TSRMLS_CC);
}

/**
 * Call single function which requires only 4 parameters
 */
int phalcon_call_func_four_params(zval *return_value, const char *func_name, int func_length, zval *param1, zval *param2, zval *param3, zval *param4 TSRMLS_DC){
	zval *params[] = { param1, param2, param3, param4 };
	return phalcon_call_func_params(return_value, func_name, func_length, 4, params TSRMLS_CC);
}

/**
 * Call single function which requires only 5 parameters
 */
int phalcon_call_func_five_params(zval *return_value, const char *func_name, int func_length, zval *param1, zval *param2, zval *param3, zval *param4, zval *param5 TSRMLS_DC){
	zval *params[] = { param1, param2, param3, param4, param5 };
	return phalcon_call_func_params(return_value, func_name, func_length, 5, params TSRMLS_CC);
}


/**
 * @brief Calls methid @a method_name from @a object which accepts @a param_count arguments @a params
 * @param[out] Return value; set to @c NULL if the return value is not needed
 * @param object Object
 * @param method_name Method name
 * @param method_length Length of the method name
 * @param param_count Number of arguments
 * @param params Arguments
 * @return Whether the call succeeded
 * @retval @c SUCCESS
 * @retval @c FAILURE
 * @note @c phalcon_memory_restore_stack() is NOT called upon failure
 */
int phalcon_call_method_params_w(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], ulong method_key, int lower TSRMLS_DC){

	int status;
	int caller_wants_result = 1;
	zend_class_entry *ce, *active_scope = NULL;

	if (unlikely(Z_TYPE_P(object) != IS_OBJECT)) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", method_name);
		return FAILURE;
	}

	if (!return_value) {
		ALLOC_INIT_ZVAL(return_value);
		caller_wants_result = 0;
	}
#ifndef PHALCON_RELEASE
	else {
		int valid_return_value = 1;

		if (Z_REFCOUNT_P(return_value) > 1) {
			valid_return_value = 0;
			fprintf(stderr, "%s: return_value has %d references, expect crashes!\n", __func__, Z_REFCOUNT_P(return_value));
		} if (Z_TYPE_P(return_value) > IS_BOOL) {
			valid_return_value = 0;
			fprintf(stderr, "%s: return_value is of complex type (%d), expect memory leaks!\n", __func__, Z_TYPE_P(return_value));
		}

		if (!valid_return_value) {
			phalcon_print_backtrace();
		}
	}
#endif

	active_scope = EG(scope);

	/* Find class_entry scope */
	ce = Z_OBJCE_P(object);
	if (ce->parent) {
		phalcon_find_scope(ce, method_name, method_len, lower, method_key TSRMLS_CC);
	} else {
		EG(scope) = ce;
	}

	status = phalcon_alt_call_user_method(ce, &object, method_name, method_len, return_value, param_count, params, method_key TSRMLS_CC);
	if (status == FAILURE) {
		EG(scope) = active_scope;
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s() on class %s", method_name, ce->name);
		status = FAILURE;
	}
	EG(scope) = active_scope;

	if (!caller_wants_result) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)) {
		status = FAILURE;
	}

	return status;
}

/**
 * Call method on an object that requires an arbitrary number of parameters
 */
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], ulong method_key, int lower TSRMLS_DC){

	int status = phalcon_call_method_params_w(return_value, object, method_name, method_len, param_count, params, method_key, lower TSRMLS_CC);
	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

int phalcon_call_method_zval_params(zval *return_value, zval *object, zval *method, zend_uint param_count, zval *params[] TSRMLS_DC){
	if (likely(Z_TYPE_P(method) == IS_STRING)) {
		return phalcon_call_method_params(return_value, object, Z_STRVAL_P(method), Z_STRLEN_P(method), param_count, params, 0, 1 TSRMLS_CC);
	}
	php_error_docref(NULL TSRMLS_CC, E_ERROR, "Method name must be string");
	phalcon_memory_restore_stack(TSRMLS_C);
	return FAILURE;
}


/**
 * Call method on an object that requires only 1 parameter
 */
int phalcon_call_method_one_param(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, ulong method_key, int lower TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 1, params, method_key, lower TSRMLS_CC);
}

/**
 * Call method on an object that requires only 2 parameters
 */
int phalcon_call_method_two_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, ulong method_key, int lower TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 2, params, method_key, lower TSRMLS_CC);
}

/**
 * Call method on an object that requires only 3 parameters
 */
int phalcon_call_method_three_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, ulong method_key, int lower TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 3, params, method_key, lower TSRMLS_CC);
}

/**
 * Call method on an object that requires only 4 parameters
 */
int phalcon_call_method_four_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, ulong method_key, int lower TSRMLS_DC){
	zval *params[] = { param1, param2, param3, param4 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 4, params, method_key, lower TSRMLS_CC);
}

/**
 * Call method on an object that requires only 5 parameters
 */
int phalcon_call_method_five_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, zval *param5, ulong method_key, int lower TSRMLS_DC){
	zval *params[] = { param1, param2, param3, param4, param5 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 5, params, method_key, lower TSRMLS_CC);
}

/**
 * Call single static function that requires an arbitrary number of parameters
 */
int phalcon_call_static_func_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_length, zend_uint param_count, zval *params[] TSRMLS_DC){

	zval cls;
	int result;

	INIT_ZVAL(cls);
	ZVAL_STRINGL(&cls, class_name, class_length, 0);
	result = phalcon_call_static_zval_str_func_params(return_value, &cls, method_name, method_length, param_count, params TSRMLS_CC);
	assert(!Z_ISREF_P(&cls));
	assert(Z_REFCOUNT_P(&cls) == 1);
	return result;
}

/**
 * Call parent static function that requires an arbitrary number of parameters
 */
int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zend_uint param_count, zval *params[] TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, active_class_len, method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, SL("parent"), method_name, method_len, param_count, params TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call parent static function that requires one parameter
 */
int phalcon_call_parent_func_one_param(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zval *param1 TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_parent_func_params(return_value, object, active_class, active_class_len, method_name, method_len, 1, params TSRMLS_CC);
}

/**
 * Call parent static function that requires two parameters
 */
int phalcon_call_parent_func_two_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zval *param1, zval *param2 TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_parent_func_params(return_value, object, active_class, active_class_len, method_name, method_len, 2, params TSRMLS_CC);
}

/**
 * Call self-class static function which requires parameters
 */
int phalcon_call_self_func_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[] TSRMLS_DC){

	int success;
	zend_class_entry *ce, *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		ce = Z_OBJCE_P(object);
		if (ce->parent) {
			phalcon_find_scope(ce, method_name, method_len, 0, 0 TSRMLS_CC);
		}
	}

	success = phalcon_call_static_func_params(return_value, SL("self"), method_name, method_len, param_count, params TSRMLS_CC);
	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

int phalcon_call_self_func_one_param(zval *return_value, zval *object, char *method_name, int method_len, zval *param1 TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_self_func_params(return_value, object, method_name, method_len, 1, params TSRMLS_CC);
}

int phalcon_call_self_func_two_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2 TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_self_func_params(return_value, object, method_name, method_len, 2, params TSRMLS_CC);
}

int phalcon_call_self_func_three_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3 TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_self_func_params(return_value, object, method_name, method_len, 3, params TSRMLS_CC);
}

int phalcon_call_self_func_four_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4 TSRMLS_DC){
	zval *params[] = { param1, param2, param3, param4 };
	return phalcon_call_self_func_params(return_value, object, method_name, method_len, 4, params TSRMLS_CC);
}

/**
 * Call single static function that requires one parameter
 */
int phalcon_call_static_func_one_param(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zval *param1 TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_static_func_params(return_value, class_name, class_length, method_name, method_len, 1, params TSRMLS_CC);
}

/**
 * Call single static function that requires two parameters
 */
int phalcon_call_static_func_two_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zval *param1, zval *param2 TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_static_func_params(return_value, class_name, class_length, method_name, method_len, 2, params TSRMLS_CC);
}

/**
 * Call single static function that requires three parameters
 */
int phalcon_call_static_func_three_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zval *param1, zval *param2, zval *param3 TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_static_func_params(return_value, class_name, class_length, method_name, method_len, 3, params TSRMLS_CC);
}

/**
 * Call single static function that requires five parameters
 */
int phalcon_call_static_func_five_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, zval *param5 TSRMLS_DC){
	zval *params[] = { param1, param2, param3, param4, param5 };
	return phalcon_call_static_func_params(return_value, class_name, class_length, method_name, method_len, 5, params TSRMLS_CC);
}

/**
 * Call single static function on a zval which requires parameters
 */
int phalcon_call_static_zval_str_func_params(zval *return_value, zval *mixed_name, char *method_name, int method_len, zend_uint param_count, zval *params[] TSRMLS_DC){

	zval *fn;
	int status;
	int caller_wants_result = 1;

	if (!return_value) {
		ALLOC_INIT_ZVAL(return_value);
		caller_wants_result = 0;
	}
#ifndef PHALCON_RELEASE
	else {
		int valid_return_value = 1;

		if (Z_REFCOUNT_P(return_value) > 1) {
			valid_return_value = 0;
			fprintf(stderr, "%s: return_value has %d references, expect crashes!\n", __func__, Z_REFCOUNT_P(return_value));
		} else if (Z_TYPE_P(return_value) > IS_BOOL) {
			valid_return_value = 0;
			fprintf(stderr, "%s: return_value is of complex type (%d), expect memory leaks!\n", __func__, Z_TYPE_P(return_value));
		}

		if (!valid_return_value) {
			PHALCON_INIT_NVAR(return_value);
			phalcon_print_backtrace();
		}
	}
#endif

	Z_ADDREF_P(mixed_name);

	ALLOC_INIT_ZVAL(fn);
	array_init_size(fn, 2);
	add_next_index_zval(fn, mixed_name);
	add_next_index_stringl(fn, method_name, method_len, 1);

	status = phalcon_call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		if (Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::%s()", method_name);
		}
	}

	zval_ptr_dtor(&fn);

	if (!caller_wants_result) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)) {
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call single static function on a zval which requires parameters
 */
int phalcon_call_static_zval_func_params(zval *return_value, zval *mixed_name, zval *method, zend_uint param_count, zval *params[] TSRMLS_DC){

	if (Z_TYPE_P(method) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::not-callable()");
		phalcon_memory_restore_stack(TSRMLS_C);
		return FAILURE;
	}

	return phalcon_call_static_zval_str_func_params(return_value, mixed_name, Z_STRVAL_P(method), Z_STRLEN_P(method), param_count, params TSRMLS_CC);
}

/**
 * Call single static function on a zval that requires one parameter
 */
int phalcon_call_static_zval_str_func_one_param(zval *return_value, zval *mixed_name, char *method_name, int method_len, zval *param1 TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_static_zval_str_func_params(return_value, mixed_name, method_name, method_len, 1, params TSRMLS_CC);
}

int phalcon_call_static_ce_func_params(zval *return_value, zend_class_entry *ce, char *method_name, int method_len, zend_uint param_count, zval *params[] TSRMLS_DC)
{
	return phalcon_call_static_func_params(return_value, (char*)ce->name, ce->name_length, method_name, method_len, param_count, params TSRMLS_CC);
}

/**
 * Replaces call_user_func_array avoiding function lookup
 */
int phalcon_call_user_func_array(zval *return_value, zval *handler, zval *params TSRMLS_DC){

	int status = phalcon_call_user_func_array_noex(return_value, handler, params TSRMLS_CC);

	if (status == SUCCESS && EG(exception)) {
		status = FAILURE;
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Replaces call_user_func_array avoiding function lookup
 * This function does not return FAILURE if an exception has ocurred
 */
int phalcon_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC){

	zval *retval_ptr = NULL;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	int status = FAILURE;

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for phalcon_call_user_func_array_noex()");
		phalcon_memory_restore_stack(TSRMLS_C);
		return FAILURE;
	}

	if (zend_fcall_info_init(handler, 0, &fci, &fci_cache, NULL, &is_callable_error TSRMLS_CC) == SUCCESS) {
		if (is_callable_error) {
			zend_error(E_STRICT, "%s", is_callable_error);
			efree(is_callable_error);
		}
		status = SUCCESS;
	} else {
		if (is_callable_error) {
			zend_error(E_WARNING, "%s", is_callable_error);
			efree(is_callable_error);
		} else {
			status = SUCCESS;
		}
	}

	if (status == SUCCESS) {

		zend_fcall_info_args(&fci, params TSRMLS_CC);
		fci.retval_ptr_ptr = &retval_ptr;

		if (zend_call_function(&fci, &fci_cache TSRMLS_CC) == SUCCESS && fci.retval_ptr_ptr && *fci.retval_ptr_ptr) {
			COPY_PZVAL_TO_ZVAL(*return_value, *fci.retval_ptr_ptr);
		}

		if (fci.params) {
			efree(fci.params);
		}
	}

	if (EG(exception)) {
		status = SUCCESS;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Replaces call_user_func avoiding function lookup, this function does not accept parameters
 */
int phalcon_call_user_func(zval *return_value, zval *handler TSRMLS_DC){

	return phalcon_call_user_func_array(return_value, handler, NULL TSRMLS_CC);
}

/**
 * Calls a function/method in the PHP userland
 */
int phalcon_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC) {

	zval ***params_array = NULL;
	zval **static_params_array[5];
	zval ***params_ptr;
	zend_uint i;
	int ex_retval;
	zval *local_retval_ptr = NULL;
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;

	phalcon_globals_ptr->recursive_lock++;

	if (unlikely(phalcon_globals_ptr->recursive_lock > 2048)) {
		ex_retval = FAILURE;
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Maximum recursion depth exceeded");
	} else {

		if (param_count) {
			if (param_count > 5) {
				params_array = (zval ***) emalloc(sizeof(zval **) * param_count);
				for (i = 0; i < param_count; i++) {
					params_array[i] = &params[i];
				}
			} else {
				for (i = 0; i < param_count; i++) {
					static_params_array[i] = &params[i];
				}
			}
		}

		if (unlikely(param_count > 5)) {
			params_ptr = params_array;
		} else {
			params_ptr = static_params_array;
		}

		ex_retval = PHALCON_CALL_USER_FUNCTION_EX(function_table, object_pp, function_name, &local_retval_ptr, param_count, params_ptr, 1, NULL TSRMLS_CC);
	}

	phalcon_globals_ptr->recursive_lock--;

	if (local_retval_ptr) {
		if (Z_TYPE_P(local_retval_ptr) == IS_NULL) {
			zval_ptr_dtor(&local_retval_ptr);
		} else {
			COPY_PZVAL_TO_ZVAL(*retval_ptr, local_retval_ptr);
		}
	} else {
		INIT_ZVAL(*retval_ptr);
	}

	if (params_array) {
		efree(params_array);
	}

	return ex_retval;
}

#if PHP_VERSION_ID <= 50309

/**
 * These functions are based on the ones in PHP 5.3.21, versions lower than 5.3.9 have problems with closures
 */
int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table TSRMLS_DC) {

	zend_fcall_info fci;

	fci.size = sizeof(fci);
	fci.function_table = function_table;
	fci.object_ptr = object_pp ? *object_pp : NULL;
	fci.function_name = function_name;
	fci.retval_ptr_ptr = retval_ptr_ptr;
	fci.param_count = param_count;
	fci.params = params;
	fci.no_separation = (zend_bool) no_separation;
	fci.symbol_table = symbol_table;

	return phalcon_call_function(&fci, NULL TSRMLS_CC);
}

int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC) {

	zend_uint i;
	zval **original_return_value;
	HashTable *calling_symbol_table;
	zend_op_array *original_op_array;
	zend_op **original_opline_ptr;
	zend_class_entry *current_scope;
	zend_class_entry *current_called_scope;
	zend_class_entry *calling_scope = NULL;
	zend_class_entry *called_scope = NULL;
	zval *current_this;
	zend_execute_data execute_data;

	*fci->retval_ptr_ptr = NULL;

	if (!EG(active)) {
		return FAILURE; /* executor is already inactive */
	}

	if (EG(exception)) {
		return FAILURE; /* we would result in an instable executor otherwise */
	}

	switch (fci->size) {
		case sizeof(zend_fcall_info):
			break; /* nothing to do currently */
		default:
			zend_error(E_ERROR, "Corrupted fcall_info provided to phalcon_call_function()");
			break;
	}

	/* Initialize execute_data */
	if (EG(current_execute_data)) {
		execute_data = *EG(current_execute_data);
		EX(op_array) = NULL;
		EX(opline) = NULL;
		EX(object) = NULL;
	} else {
		/* This only happens when we're called outside any execute()'s
		 * It shouldn't be strictly necessary to NULL execute_data out,
		 * but it may make bugs easier to spot
		 */
		memset(&execute_data, 0, sizeof(zend_execute_data));
	}

	if (!fci_cache || !fci_cache->initialized) {

		zend_fcall_info_cache fci_cache_local;
		char *callable_name;
		char *error = NULL;

		if (!fci_cache) {
			fci_cache = &fci_cache_local;
		}

		if (!zend_is_callable_ex(fci->function_name, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, fci_cache, &error TSRMLS_CC)) {
			if (error) {
				zend_error(E_WARNING, "Invalid callback %s, %s", callable_name, error);
				efree(error);
			}
			if (callable_name) {
				efree(callable_name);
			}
			return FAILURE;
		} else {
			if (error) {
				/* Capitalize the first latter of the error message */
				if (error[0] >= 'a' && error[0] <= 'z') {
					error[0] += ('A' - 'a');
				}
				zend_error(E_STRICT, "%s", error);
				efree(error);
			}
		}
		efree(callable_name);
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = fci_cache->calling_scope;
	called_scope = fci_cache->called_scope;
	fci->object_ptr = fci_cache->object_ptr;
	EX(object) = fci->object_ptr;
	if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT &&
		(!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
		return FAILURE;
	}

	if (EX(function_state).function->common.fn_flags & ZEND_ACC_ABSTRACT) {
		zend_error_noreturn(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
		return FAILURE;
	}

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i = 0; i < fci->param_count; i++) {
		zval *param;

		if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION
			&& (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0
			&& !ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& PZVAL_IS_REF(*fci->params[i])) {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
			zval_copy_ctor(param);
		} else if (ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& !PZVAL_IS_REF(*fci->params[i])) {

			if (Z_REFCOUNT_PP(fci->params[i]) > 1) {
				zval *new_zval;

				if (fci->no_separation &&
					!ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
					if (i || UNEXPECTED(ZEND_VM_STACK_ELEMETS(EG(argument_stack)) == EG(argument_stack)->top)) {
						/* hack to clean up the stack */
						zend_vm_stack_push_nocheck((void *) (zend_uintptr_t)i TSRMLS_CC);
						#if PHP_VERSION_ID <= 50500
						zend_vm_stack_clear_multiple(TSRMLS_C);
						#else
						zend_vm_stack_clear_multiple(0 TSRMLS_C);
						#endif
					}

					zend_error(E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
						i+1,
						EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
						EX(function_state).function->common.scope ? "::" : "",
						EX(function_state).function->common.function_name);
					return FAILURE;
				}

				ALLOC_ZVAL(new_zval);
				*new_zval = **fci->params[i];
				zval_copy_ctor(new_zval);
				Z_SET_REFCOUNT_P(new_zval, 1);
				Z_DELREF_PP(fci->params[i]);
				*fci->params[i] = new_zval;
			}
			Z_ADDREF_PP(fci->params[i]);
			Z_SET_ISREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else if (*fci->params[i] != &EG(uninitialized_zval)) {
			Z_ADDREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
		}
		zend_vm_stack_push_nocheck(param TSRMLS_CC);
	}

	EX(function_state).arguments = zend_vm_stack_top(TSRMLS_C);
	zend_vm_stack_push_nocheck((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);

	current_scope = EG(scope);
	EG(scope) = calling_scope;

	current_this = EG(This);

	current_called_scope = EG(called_scope);
	if (called_scope) {
		EG(called_scope) = called_scope;
	} else {
		if (EX(function_state).function->type != ZEND_INTERNAL_FUNCTION) {
			EG(called_scope) = NULL;
		}
	}

	if (fci->object_ptr) {
		if ((EX(function_state).function->common.fn_flags & ZEND_ACC_STATIC)) {
			EG(This) = NULL;
		} else {
			EG(This) = fci->object_ptr;

			if (!PZVAL_IS_REF(EG(This))) {
				Z_ADDREF_P(EG(This)); /* For $this pointer */
			} else {
				zval *this_ptr;

				ALLOC_ZVAL(this_ptr);
				*this_ptr = *EG(This);
				INIT_PZVAL(this_ptr);
				zval_copy_ctor(this_ptr);
				EG(This) = this_ptr;
			}
		}
	} else {
		EG(This) = NULL;
	}

	EX(prev_execute_data) = EG(current_execute_data);
	EG(current_execute_data) = &execute_data;

	if (EX(function_state).function->type == ZEND_USER_FUNCTION) {
		calling_symbol_table = EG(active_symbol_table);
		EG(scope) = EX(function_state).function->common.scope;
		if (fci->symbol_table) {
			EG(active_symbol_table) = fci->symbol_table;
		} else {
			EG(active_symbol_table) = NULL;
		}

		original_return_value = EG(return_value_ptr_ptr);
		original_op_array = EG(active_op_array);
		EG(return_value_ptr_ptr) = fci->retval_ptr_ptr;
		EG(active_op_array) = (zend_op_array *) EX(function_state).function;
		original_opline_ptr = EG(opline_ptr);
		zend_execute(EG(active_op_array) TSRMLS_CC);
		if (!fci->symbol_table && EG(active_symbol_table)) {
			if (EG(symtable_cache_ptr)>=EG(symtable_cache_limit)) {
				zend_hash_destroy(EG(active_symbol_table));
				FREE_HASHTABLE(EG(active_symbol_table));
			} else {
				/* clean before putting into the cache, since clean
				   could call dtors, which could use cached hash */
				zend_hash_clean(EG(active_symbol_table));
				*(++EG(symtable_cache_ptr)) = EG(active_symbol_table);
			}
		}
		EG(active_symbol_table) = calling_symbol_table;
		EG(active_op_array) = original_op_array;
		EG(return_value_ptr_ptr)=original_return_value;
		EG(opline_ptr) = original_opline_ptr;
	} else if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION) {
		int call_via_handler = (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
		if (EX(function_state).function->common.scope) {
			EG(scope) = EX(function_state).function->common.scope;
		}
		((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		/*  We shouldn't fix bad extensions here,
			because it can break proper ones (Bug #34045)
		if (!EX(function_state).function->common.return_reference)
		{
			INIT_PZVAL(*fci->retval_ptr_ptr);
		}*/
		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}

		if (call_via_handler) {
			/* We must re-initialize function again */
			fci_cache->initialized = 0;
		}
	} else {
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);

		if (fci->object_ptr) {
			Z_OBJ_HT_P(fci->object_ptr)->call_method(EX(function_state).function->common.function_name, fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		} else {
			zend_error_noreturn(E_ERROR, "Cannot call overloaded function for non-object");
			return FAILURE;
		}

		if (EX(function_state).function->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
			efree(EX(function_state).function->common.function_name);
		}
		efree(EX(function_state).function);

		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}
	}
	#if PHP_VERSION_ID <= 50500
	zend_vm_stack_clear_multiple(TSRMLS_C);
	#else
	zend_vm_stack_clear_multiple(0 TSRMLS_C);
	#endif

	if (EG(This)) {
		zval_ptr_dtor(&EG(This));
	}
	EG(called_scope) = current_called_scope;
	EG(scope) = current_scope;
	EG(This) = current_this;
	EG(current_execute_data) = EX(prev_execute_data);

	if (EG(exception)) {
		phalcon_throw_exception_internal(NULL TSRMLS_CC);
	}
	return SUCCESS;
}

#endif
