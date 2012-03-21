
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
#include "kernel/debug.h"
#include "kernel/memory.h"
#include "zend_API.h"
#include "zend_exceptions.h"

/**
 * Current fcall pointer
 */
int phalcon_fcall_pointer = 0;

/**
 * Global zend_fcall_info_cache for current execution
 */
zend_fcall_info_cache *phalcon_fcall_cache[PHALCON_FCALL_MAX_CACHE];

/**
 * Initializes fcall cache
 */
int phalcon_init_fcall_cache(){
	register int i;
	for(i=0;i<PHALCON_FCALL_MAX_CACHE;i++){
		phalcon_fcall_cache[i] = NULL;
	}
	return SUCCESS;
}

/**
 * Frees fcall cache
 */
int phalcon_free_fcall_cache(){
	register int i;
	for(i=0;i<PHALCON_FCALL_MAX_CACHE;i++){
		if(phalcon_fcall_cache[i]){
			efree(phalcon_fcall_cache[i]);
		}
	}
	return SUCCESS;
}

/**
 * Lookups a function call and caches its zend_fcall_info_cache for further calls
 */
int phalcon_cache_lookup_function(zval *fn, int fcache_pointer){
	if(!phalcon_fcall_cache[fcache_pointer]){
		{
			char *callable_name;
			char *error = NULL;

			phalcon_fcall_cache[fcache_pointer] = emalloc(sizeof(zend_fcall_info_cache));
			if (!zend_is_callable_ex(fn, NULL, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, phalcon_fcall_cache[fcache_pointer], &error TSRMLS_CC)) {
				if (error) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid callback %s, %s", callable_name, error);
					efree(error);
					return FAILURE;
				}
			}

			efree(callable_name);
		}
	}
	return SUCCESS;
}

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
 * Find function scope on parent classes
 */
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, int active_class_len, char *method_name, int method_len TSRMLS_DC){
	char *lcname = zend_str_tolower_dup(method_name, method_len);
	while (ce) {
		if (!zend_binary_strcasecmp(ce->name, ce->name_length, active_class, active_class_len)) {
			if (zend_hash_exists(&ce->function_table, lcname, method_len+1)) {
				EG(scope) = ce;
				efree(lcname);
				return SUCCESS;
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
 * Call single function which not requires parameters
 */
int phalcon_call_func(zval *return_value, char *func_name, int func_length, int noreturn, int fcache_pointer TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zval *local_retval_ptr = NULL;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 1);

	/*status = phalcon_cache_lookup_function(fn, fcache_pointer);
	if (status == FAILURE) {
		return FAILURE;
	}*/

	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	//status = phalcon_call_user_function_ex(CG(function_table), NULL, fn, &local_retval_ptr, 0, NULL, 1, NULL, phalcon_fcall_cache[fcache_pointer] TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single function which requires arbitrary number of parameters
 */
int phalcon_call_func_params(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn, int fcache_pointer TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	//zval ***params_array;
	zval *local_retval_ptr = NULL;
	//int i;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 1);

	/*status = phalcon_cache_lookup_function(fn, fcache_pointer);
	if (status == FAILURE) {
		return FAILURE;
	}*/

	/*if(param_count){
		params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
		for (i=0; i<param_count; i++) {
			params_array[i] = &params[i];
		}
	} else {
		params_array = NULL;
	}*/

	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	//status = phalcon_call_user_function_ex(CG(function_table), NULL, fn, &local_retval_ptr, param_count, params_array, 1, NULL, phalcon_fcall_cache[fcache_pointer] TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (local_retval_ptr) {
		COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	/*if (params_array) {
		efree(params_array);
	}*/

	return status;
}

/**
 * Call single function which requires only 1 parameter
 */
int phalcon_call_func_one_param(zval *return_value, char *func_name, int func_length, zval *param1, int noreturn, int fcache_pointer TSRMLS_DC){
	zval *params[] = { param1 };
	return phalcon_call_func_params(return_value, func_name, func_length, 1, params, noreturn, fcache_pointer TSRMLS_CC);
}

/**
 * Call single function which requires only 2 parameters
 */
int phalcon_call_func_two_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, int noreturn, int fcache_pointer TSRMLS_DC){
	zval *params[] = { param1, param2 };
	return phalcon_call_func_params(return_value, func_name, func_length, 2, params, noreturn, fcache_pointer TSRMLS_CC);
}

/**
 * Call method on an object which not requires parameters
 *
 */
int phalcon_call_method(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, strlen(method_name)+1)) {
			return FAILURE;
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
		status = call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, 0, NULL TSRMLS_CC);
		if (status == FAILURE) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s()", Z_STRVAL_P(fn));
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call method on an object which requires parameters
 *
 */
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, method_len+1)) {
			return FAILURE;
		}
	}

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, method_name, method_len, 1);

	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name, method_len TSRMLS_CC);
		status = call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, param_count, params TSRMLS_CC);
		if (status == FAILURE) {
			EG(scope) = active_scope;
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s() on class %s", Z_STRVAL_P(fn), Z_OBJCE_P(object)->name);
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
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
 * Call parent static function which requires parameters
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
	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function on a zval which not requires parameters
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
	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function not-callable::%s()", method_name);
		}
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function which requires parameters
 */
int phalcon_call_static_func_params(zval *return_value, char *class_name, int class_length, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_stringl(fn, class_name, class_length, 1);
	add_next_index_stringl(fn, method_name, method_len, 1);

	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	zval_ptr_dtor(&fn);

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function direct on a zend_class_entry which requires parameters
 */
int phalcon_call_static_ce_func_params(zval *return_value, zend_class_entry *ce, char *method_name, int method_len, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_stringl(fn, ce->name, ce->name_length, 0);
	add_next_index_stringl(fn, method_name, method_len, 0);
	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", ce->name, method_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;

}

/**
 * Call single function on zval which requires parameters
 */
int phalcon_call_static_func_zval_params(zval *return_value, zval *mixed_name, char *method_name, zend_uint param_count, zval *params[], int noreturn TSRMLS_DC){

	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	status = call_user_function(CG(function_table), NULL, mixed_name, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		if(Z_TYPE_P(mixed_name) == IS_STRING) {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", Z_STRVAL_P(mixed_name), method_name);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", method_name);
		}
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Executes zend_function with a prepared fci_cache
 */
int phalcon_call_user_function_ex(HashTable *function_table, zval **object_pp, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], int no_separation, HashTable *symbol_table, zend_fcall_info_cache *fci_cache TSRMLS_DC){

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

	return zend_call_function(&fci, fci_cache TSRMLS_CC);
}