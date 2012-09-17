
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"

#include "Zend/zend_API.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_execute.h"

/**
 * Finds the correct scope to execute the function
 */
int phalcon_find_scope(zend_class_entry *ce, char *method_name, int method_len TSRMLS_DC){
	char *lcname = zend_str_tolower_dup(method_name, method_len);
	while (ce) {
		if (zend_hash_exists(&ce->function_table, lcname, method_len+1)) {
			EG(scope) = ce;
			efree(lcname);
			return SUCCESS;
		}
		ce = ce->parent;
	}
	if (lcname) {
		efree(lcname);
	}
	return FAILURE;
}

/**
 * Find out the function scope on parent classes
 */
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, int active_class_len, char *method_name, int method_len TSRMLS_DC){
	char *lcname = zend_str_tolower_dup(method_name, method_len);
	while (ce) {
		if (ce->name_length == active_class_len) {
			if (!zend_binary_strcasecmp(ce->name, ce->name_length, active_class, active_class_len)) {
				if (zend_hash_exists(&ce->function_table, lcname, method_len+1)) {
					EG(scope) = ce;
					efree(lcname);
					return SUCCESS;
				}
			}
		}
		ce = ce->parent;
	}
	if (lcname) {
		efree(lcname);
	}
	return FAILURE;
}

/**
 * This is a function to call PHP functions in a old-style secure way
 */
static inline int phalcon_call_func_normal(zval *return_value, char *func_name, int func_length, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zval *local_retval_ptr = NULL;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 1);

	status = PHALCON_CALL_USER_FUNCTION(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
	}

	zval_ptr_dtor(&fn);

	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)){
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call single function which not requires parameters
 */
int phalcon_call_func(zval *return_value, char *func_name, int func_length, int noreturn TSRMLS_DC){
	return phalcon_call_func_normal(return_value, func_name, func_length, noreturn TSRMLS_CC);
}

/**
 * This is an experimental function to call PHP functions that requires parameters in a faster way
 */
static inline int phalcon_call_func_params_normal(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zval *local_retval_ptr = NULL;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 1);

	status = PHALCON_CALL_USER_FUNCTION(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
	}

	zval_ptr_dtor(&fn);

	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)){
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call single function which requires arbitrary number of parameters
 */
int phalcon_call_func_params(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){
	return phalcon_call_func_params_normal(return_value, func_name, func_length, param_count, params, noreturn TSRMLS_CC);
}

/**
 * Call single function which requires only 1 parameter
 */
int phalcon_call_func_one_param(zval *return_value, char *func_name, int func_length, zval *param1, int noreturn TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_func_params(return_value, func_name, func_length, 1, params, noreturn TSRMLS_CC);
}

/**
 * Call single function which requires only 2 parameters
 */
int phalcon_call_func_two_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_func_params(return_value, func_name, func_length, 2, params, noreturn TSRMLS_CC);
}

/**
 * Call single function which requires only 3 parameters
 */
int phalcon_call_func_three_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_func_params(return_value, func_name, func_length, 3, params, noreturn TSRMLS_CC);
}

/**
 * This function implements a secure old-style way to call functions
 */
static inline int phalcon_call_method_normal(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, strlen(method_name)+1)) {
			return SUCCESS;
		}
	}

	if(!noreturn){
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, method_name, method_len, 1);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name, method_len TSRMLS_CC);
		status = PHALCON_CALL_USER_FUNCTION(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, 0, NULL TSRMLS_CC);
		if (status == FAILURE) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s()", Z_STRVAL_P(fn));
		}
		EG(scope) = active_scope;
	} else {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		status = FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)){
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call method on an object that not requires parameters
 *
 */
int phalcon_call_method(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC){
	return phalcon_call_method_normal(return_value, object, method_name, method_len, check, noreturn TSRMLS_CC);
}

/**
 * Call methods that require parameters in a old-style secure way
 */
static inline int phalcon_call_method_params_normal(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *ce, *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, method_len+1)) {
			return SUCCESS;
		}
	}

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, method_name, method_len, 1);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		ce = Z_OBJCE_P(object);
		phalcon_find_scope(ce, method_name, method_len TSRMLS_CC);
		status = PHALCON_CALL_USER_FUNCTION(&ce->function_table, &object, fn, return_value, param_count, params TSRMLS_CC);
		if (status == FAILURE) {
			EG(scope) = active_scope;
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s() on class %s", Z_STRVAL_P(fn), Z_OBJCE_P(object)->name);
			status = FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		status = FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
		return_value = NULL;
	}

	if (EG(exception)){
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call method on an object that requires an arbitrary number of parameters
 *
 */
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC){
	return phalcon_call_method_params_normal(return_value, object, method_name, method_len, param_count, params, check, noreturn TSRMLS_CC);
}

/**
 * Call method on an object that requires only 1 parameter
 *
 */
int phalcon_call_method_one_param(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, int check, int noreturn TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 1, params, check, noreturn TSRMLS_CC);
}

/**
 * Call method on an object that requires only 2 parameters
 *
 */
int phalcon_call_method_two_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, int check, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 2, params, check, noreturn TSRMLS_CC);
}

/**
 * Call method on an object that requires only 3 parameters
 *
 */
int phalcon_call_method_three_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int check, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 3, params, check, noreturn TSRMLS_CC);
}

/**
 * Call method on an object that requires only 4 parameters
 *
 */
int phalcon_call_method_four_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, int check, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2, param3, param4 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 4, params, check, noreturn TSRMLS_CC);
}

/**
 * Call method on an object that requires only 5 parameters
 *
 */
int phalcon_call_method_five_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, zval *param4, zval *param5, int check, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2, param3, param4, param5 };
	return phalcon_call_method_params(return_value, object, method_name, method_len, 5, params, check, noreturn TSRMLS_CC);
}

/**
 * Call parent static function which not requires parameters
 */
int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, active_class_len, method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func(return_value, "parent", strlen("parent"), method_name, method_len, noreturn TSRMLS_CC);
	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call parent static function that requires an arbitrary number of parameters
 */
int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, active_class_len, method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, "parent", strlen("parent"), method_name, method_len, param_count, params, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call parent static function that requires one parameter
 */
int phalcon_call_parent_func_one_param(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zval *param1, int noreturn TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_parent_func_params(return_value, object, active_class, active_class_len, method_name, method_len, 1, params, noreturn TSRMLS_CC);
}

/**
 * Call parent static function that requires two parameters
 */
int phalcon_call_parent_func_two_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zval *param1, zval *param2, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_parent_func_params(return_value, object, active_class, active_class_len, method_name, method_len, 2, params, noreturn TSRMLS_CC);
}

/**
 * Call parent static function that requires two parameters
 */
int phalcon_call_parent_func_three_params(zval *return_value, zval *object, char *active_class, int active_class_len, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_parent_func_params(return_value, object, active_class, active_class_len, method_name, method_len, 3, params, noreturn TSRMLS_CC);
}

/**
 * Call self-class static function which not requires parameters
 */
int phalcon_call_self_func(zval *return_value, zval *object, char *method_name, int method_len, int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func(return_value, "self", strlen("self"), method_name, method_len, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call self-class static function which requires parameters
 */
int phalcon_call_self_func_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name, method_len TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, "self", strlen("self"), method_name, method_len, param_count, params, noreturn TSRMLS_CC);
	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

int phalcon_call_self_func_one_param(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, int noreturn TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_self_func_params(return_value, object, method_name, method_len, 1, params, noreturn TSRMLS_CC);
}

int phalcon_call_self_func_two_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_self_func_params(return_value, object, method_name, method_len, 2, params, noreturn TSRMLS_CC);
}

int phalcon_call_self_func_three_params(zval *return_value, zval *object, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_self_func_params(return_value, object, method_name, method_len, 3, params, noreturn TSRMLS_CC);
}

/**
 * Call single static function which not requires parameters
 */
int phalcon_call_static_func(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_stringl(fn, class_name, class_length, 1);
	add_next_index_stringl(fn, method_name, method_len, 1);
	status = PHALCON_CALL_USER_FUNCTION(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)){
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call single static function that requires an arbitrary number of parameters
 */
int phalcon_call_static_func_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_stringl(fn, class_name, class_length, 1);
	add_next_index_stringl(fn, method_name, method_len, 1);

	status = PHALCON_CALL_USER_FUNCTION(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)){
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call single static function that requires one parameter
 */
int phalcon_call_static_func_one_param(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zval *param1, int noreturn TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_static_func_params(return_value, class_name, class_length, method_name, method_len, 1, params, noreturn TSRMLS_CC);
}

/**
 * Call single static function that requires two parameters
 */
int phalcon_call_static_func_two_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zval *param1, zval *param2, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_static_func_params(return_value, class_name, class_length, method_name, method_len, 2, params, noreturn TSRMLS_CC);
}

/**
 * Call single static function that requires three parameters
 */
int phalcon_call_static_func_three_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_static_func_params(return_value, class_name, class_length, method_name, method_len, 3, params, noreturn TSRMLS_CC);
}

/**
 * Call single static function on a zval which not requires any parameter
 */
int phalcon_call_static_zval_func(zval *return_value, zval *mixed_name, char *method_name, int method_len, int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_zval(fn, mixed_name);
	add_next_index_stringl(fn, method_name, method_len, 1);
	status = PHALCON_CALL_USER_FUNCTION(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::%s()", method_name);
		}
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)){
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
int phalcon_call_static_zval_func_params(zval *return_value, zval *mixed_name, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_zval(fn, mixed_name);
	add_next_index_stringl(fn, method_name, method_len, 1);
	status = PHALCON_CALL_USER_FUNCTION(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::%s()", method_name);
		}
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)){
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}

/**
 * Call single static function on a zval that requires one parameter
 */
int phalcon_call_static_zval_func_one_param(zval *return_value, zval *mixed_name, char *method_name, int method_len, zval *param1, int noreturn TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_static_zval_func_params(return_value, mixed_name, method_name, method_len, 1, params, noreturn TSRMLS_CC);
}

/**
 * Call single static function on a zval that requires one parameter
 */
int phalcon_call_static_zval_func_two_params(zval *return_value, zval *mixed_name, char *method_name, int method_len, zval *param1, zval *param2, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_static_zval_func_params(return_value, mixed_name, method_name, method_len, 2, params, noreturn TSRMLS_CC);
}

/**
 * Call single static function on a zval that requires one parameter
 */
int phalcon_call_static_zval_func_three_params(zval *return_value, zval *mixed_name, char *method_name, int method_len, zval *param1, zval *param2, zval *param3, int noreturn TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_static_zval_func_params(return_value, mixed_name, method_name, method_len, 3, params, noreturn TSRMLS_CC);
}

/**
 * Call single static function direct on a zend_class_entry which requires parameters
 */
int phalcon_call_static_ce_func_params(zval *return_value, zend_class_entry *ce, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_stringl(fn, ce->name, ce->name_length, 0);
	add_next_index_stringl(fn, method_name, method_len, 0);
	status = PHALCON_CALL_USER_FUNCTION(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", ce->name, method_name);
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	if (EG(exception)){
		status = FAILURE;
	}

	if (status == FAILURE) {
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;

}

#if PHP_VERSION_ID <= 50308

int phalcon_call_user_function(HashTable *function_table, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[] TSRMLS_DC) {
	zval ***params_array;
	zend_uint i;
	int ex_retval;
	zval *local_retval_ptr = NULL;

	if (param_count) {
		params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
		for (i=0; i<param_count; i++) {
			params_array[i] = &params[i];
		}
	} else {
		params_array = NULL;
	}

	ex_retval = phalcon_call_user_function_ex(function_table, object_pp, function_name, &local_retval_ptr, param_count, params_array, 1, NULL TSRMLS_CC);
	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*retval_ptr, local_retval_ptr);
	} else {
		INIT_ZVAL(*retval_ptr);
	}
	if (params_array) {
		efree(params_array);
	}
	return ex_retval;
}

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
		} else if (error) {
			/* Capitalize the first latter of the error message */
			if (error[0] >= 'a' && error[0] <= 'z') {
				error[0] += ('A' - 'a');
			}
			zend_error(E_STRICT, "%s", error);
			efree(error);
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

	if (EX(function_state).function->common.fn_flags & (ZEND_ACC_ABSTRACT|ZEND_ACC_DEPRECATED)) {
		if (EX(function_state).function->common.fn_flags & ZEND_ACC_ABSTRACT) {
			zend_error_noreturn(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
		}
		if (EX(function_state).function->common.fn_flags & ZEND_ACC_DEPRECATED) {
 			zend_error(E_DEPRECATED, "Function %s%s%s() is deprecated",
				EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
				EX(function_state).function->common.scope ? "::" : "",
				EX(function_state).function->common.function_name);
		}
	}

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i=0; i<fci->param_count; i++) {
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
						zend_vm_stack_clear_multiple(TSRMLS_C);
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
	} else if (EX(function_state).function->type != ZEND_INTERNAL_FUNCTION) {
		EG(called_scope) = NULL;
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
	} else { /* ZEND_OVERLOADED_FUNCTION */
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);

		/* Not sure what should be done here if it's a static method */
		if (fci->object_ptr) {
			Z_OBJ_HT_P(fci->object_ptr)->call_method(EX(function_state).function->common.function_name, fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		} else {
			zend_error_noreturn(E_ERROR, "Cannot call overloaded function for non-object");
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
	zend_vm_stack_clear_multiple(TSRMLS_C);

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

int phalcon_lookup_class_ex(const char *name, int name_length, int use_autoload, zend_class_entry ***ce TSRMLS_DC){

	zval **args[1];
	zval autoload_function;
	zval *class_name_ptr;
	zval *retval_ptr = NULL;
	int retval, lc_length;
	char *lc_name;
	char *lc_free;
	zend_fcall_info fcall_info;
	zend_fcall_info_cache fcall_cache;
	char dummy = 1;
	ulong hash;
	ALLOCA_FLAG(use_heap)

	if (name == NULL || !name_length) {
		return FAILURE;
	}

	lc_free = lc_name = do_alloca(name_length + 1, use_heap);
	zend_str_tolower_copy(lc_name, name, name_length);
	lc_length = name_length + 1;

	if (lc_name[0] == '\\') {
		lc_name += 1;
		lc_length -= 1;
	}

	hash = zend_inline_hash_func(lc_name, lc_length);

	if (zend_hash_quick_find(EG(class_table), lc_name, lc_length, hash, (void **) ce) == SUCCESS) {
		free_alloca(lc_free, use_heap);
		return SUCCESS;
	}

	/* The compiler is not-reentrant. Make sure we __autoload() only during run-time
	 * (doesn't impact fuctionality of __autoload()
	*/
	if (!use_autoload || zend_is_compiling(TSRMLS_C)) {
		free_alloca(lc_free, use_heap);
		return FAILURE;
	}

	if (EG(in_autoload) == NULL) {
		ALLOC_HASHTABLE(EG(in_autoload));
		zend_hash_init(EG(in_autoload), 0, NULL, NULL, 0);
	}

	if (zend_hash_quick_add(EG(in_autoload), lc_name, lc_length, hash, (void**)&dummy, sizeof(char), NULL) == FAILURE) {
		free_alloca(lc_free, use_heap);
		return FAILURE;
	}

	ZVAL_STRINGL(&autoload_function, ZEND_AUTOLOAD_FUNC_NAME, sizeof(ZEND_AUTOLOAD_FUNC_NAME) - 1, 0);

	ALLOC_ZVAL(class_name_ptr);
	INIT_PZVAL(class_name_ptr);
	if (name[0] == '\\') {
		ZVAL_STRINGL(class_name_ptr, name+1, name_length-1, 1);
	} else {
		ZVAL_STRINGL(class_name_ptr, name, name_length, 1);
	}

	args[0] = &class_name_ptr;

	fcall_info.size = sizeof(fcall_info);
	fcall_info.function_table = EG(function_table);
	fcall_info.function_name = &autoload_function;
	fcall_info.symbol_table = NULL;
	fcall_info.retval_ptr_ptr = &retval_ptr;
	fcall_info.param_count = 1;
	fcall_info.params = args;
	fcall_info.object_ptr = NULL;
	fcall_info.no_separation = 1;

	fcall_cache.initialized = EG(autoload_func) ? 1 : 0;
	fcall_cache.function_handler = EG(autoload_func);
	fcall_cache.calling_scope = NULL;
	fcall_cache.called_scope = NULL;
	fcall_cache.object_ptr = NULL;

	zend_exception_save(TSRMLS_C);
	retval = phalcon_call_function(&fcall_info, &fcall_cache TSRMLS_CC);
	zend_exception_restore(TSRMLS_C);

	EG(autoload_func) = fcall_cache.function_handler;

	zval_ptr_dtor(&class_name_ptr);

	zend_hash_quick_del(EG(in_autoload), lc_name, lc_length, hash);

	if (retval_ptr) {
		zval_ptr_dtor(&retval_ptr);
	}

	if (retval == FAILURE) {
		free_alloca(lc_free, use_heap);
		return FAILURE;
	}

	retval = zend_hash_quick_find(EG(class_table), lc_name, lc_length, hash, (void **) ce);
	free_alloca(lc_free, use_heap);
	return retval;
}

int phalcon_lookup_class(const char *name, int name_length, zend_class_entry ***ce TSRMLS_DC){
	return phalcon_lookup_class_ex(name, name_length, 1, ce TSRMLS_CC);
}

#endif
