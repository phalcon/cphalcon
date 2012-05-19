
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
#include "Zend/zend_API.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_execute.h"

/**
 * Initializes fcall cache
 */
int phalcon_init_fcall_cache(TSRMLS_D){
	register int i;
	for(i=0;i<PHALCON_FCALL_MAX_CACHE;i++){
		PHALCON_GLOBAL(phalcon_fcall_cache[i]) = NULL;
	}
	return SUCCESS;
}

/**
 * Frees fcall cache
 */
int phalcon_free_fcall_cache(TSRMLS_D){
	register int i;
	for(i=0;i<PHALCON_FCALL_MAX_CACHE;i++){
		if(PHALCON_GLOBAL(phalcon_fcall_cache)[i]){
			efree(PHALCON_GLOBAL(phalcon_fcall_cache)[i]);
		}
	}
	return SUCCESS;
}

/**
 * Lookups a function call and caches its zend_fcall_info_cache for further calls
 */
int phalcon_cache_lookup_function(char *func_name, int func_name_length, int fcache_pointer TSRMLS_DC){
	if(!PHALCON_GLOBAL(phalcon_fcall_cache)[fcache_pointer]){
		{
			zend_fcall_info_cache *fcc;

			fcc = emalloc(sizeof(zend_fcall_info_cache));
			fcc->initialized = 0;
			fcc->calling_scope = NULL;
			fcc->called_scope = NULL;
			fcc->function_handler = NULL;
			fcc->calling_scope = NULL;
			fcc->object_ptr = NULL;

			if (zend_hash_find(EG(function_table), func_name, func_name_length+1, (void**)&fcc->function_handler) == SUCCESS) {
				PHALCON_GLOBAL(phalcon_fcall_cache)[fcache_pointer] = fcc;
			} else {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid function %s", func_name);
				return FAILURE;
			}
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
 * Find out function scope on parent classes
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
 * This is a function to call PHP functions in a old-style secure way
 */
inline int phalcon_call_func_normal(zval *return_value, char *func_name, int func_length, int noreturn, int fcache_pointer TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zval *local_retval_ptr = NULL;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 1);

	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
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
 * This is an experimental way to call PHP functions in a faster way
 */
inline int phalcon_call_func_fast(zval *return_value, char *func_name, int func_length, int noreturn, int fcache_pointer TSRMLS_DC){

	int status;
	zval *local_retval_ptr = NULL;

	status = phalcon_cache_lookup_function(func_name, func_length, fcache_pointer TSRMLS_CC);
	if (status == FAILURE) {
		return FAILURE;
	}

	status = phalcon_call_user_function_ex(CG(function_table), &local_retval_ptr, 0, NULL, PHALCON_GLOBAL(phalcon_fcall_cache)[fcache_pointer] TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	if (local_retval_ptr) {
		if (noreturn) {
			COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
		}
		//zval_ptr_dtor(&local_retval_ptr);
	}

	return status;
}

/**
 * Call single function which not requires parameters
 */
int phalcon_call_func(zval *return_value, char *func_name, int func_length, int noreturn, int fcache_pointer TSRMLS_DC){
#if PHALCON_EXPERIMENTAL_CALL
	return phalcon_call_func_fast(return_value, func_name, func_length, noreturn, fcache_pointer TSRMLS_CC);
#else
	return phalcon_call_func_normal(return_value, func_name, func_length, noreturn, fcache_pointer TSRMLS_CC);
#endif
}

/**
 * This is an experimental function to call PHP functions that requires parameters in a faster way
 */
inline int phalcon_call_func_params_fast(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn, int fcache_pointer TSRMLS_DC){

	int status;
	zval ***params_array;
	zval *local_retval_ptr = NULL;
	register int i;

	status = phalcon_cache_lookup_function(func_name, func_length, fcache_pointer TSRMLS_CC);
	if (status == FAILURE) {
		return FAILURE;
	}

	params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
	for (i=0; i<param_count; i++) {
		params_array[i] = &params[i];
	}

	status = phalcon_call_user_function_ex(CG(function_table), &local_retval_ptr, param_count, params_array, PHALCON_GLOBAL(phalcon_fcall_cache)[fcache_pointer] TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
	}

	if (local_retval_ptr) {
		if (noreturn) {
			COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
		}
		//zval_ptr_dtor(&local_retval_ptr);
	}

	if (params_array) {
		efree(params_array);
	}

	return status;
}

/**
 * This is an experimental function to call PHP functions that requires parameters in a faster way
 */
inline int phalcon_call_func_params_normal(zval *return_value, char *func_name, int func_length, zend_uint param_count, zval *params[], int noreturn, int fcache_pointer TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zval *local_retval_ptr = NULL;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_ALLOC_ZVAL(fn);
	ZVAL_STRINGL(fn, func_name, func_length, 1);

	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
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
#if PHALCON_EXPERIMENTAL_CALL
	return phalcon_call_func_params_fast(return_value, func_name, func_length, param_count, params, noreturn, fcache_pointer TSRMLS_CC);
#else
	return phalcon_call_func_params_normal(return_value, func_name, func_length, param_count, params, noreturn, fcache_pointer TSRMLS_CC);
#endif
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
 * Call single function which requires only 3 parameters
 */
int phalcon_call_func_three_params(zval *return_value, char *func_name, int func_length, zval *param1, zval *param2, zval *param3, int noreturn, int fcache_pointer TSRMLS_DC){
	zval *params[] = { param1, param2, param3 };
	return phalcon_call_func_params(return_value, func_name, func_length, 3, params, noreturn, fcache_pointer TSRMLS_CC);
}

/**
 * This function implements a secure old-style way to call functions
 */
inline int phalcon_call_method_normal(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC){

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
 * This function implements a experimental way to call functions in a faster way
 */
inline int phalcon_call_method_fast(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC){

	int status;
	zval *local_retval_ptr = NULL;
	zend_class_entry *active_scope = NULL;
	HashTable *function_table;
	zend_fcall_info_cache local_fcache;
	zend_fcall_info_cache *fcc = NULL;
	zend_class_entry *obj_ce;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", method_name);
		return FAILURE;
	}

	obj_ce = Z_OBJCE_P(object);
	function_table = &obj_ce->function_table;

	fcc = &local_fcache;
	fcc->initialized = 0;
	fcc->calling_scope = obj_ce;
	fcc->called_scope = obj_ce;
	fcc->function_handler = NULL;
	fcc->object_ptr = object;

	if (zend_hash_find(function_table, method_name, method_len+1, (void**)&fcc->function_handler) != SUCCESS) {
		if (check) {
			return FAILURE;
		}
	}

	active_scope = EG(scope);
	phalcon_find_scope(obj_ce, method_name, method_len TSRMLS_CC);
	status = phalcon_call_user_method_ex(function_table, &object, method_name, method_len, &local_retval_ptr, 0, NULL, fcc TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s() on class %s", method_name, obj_ce->name);
	}
	EG(scope) = active_scope;

	if (local_retval_ptr) {
		if (noreturn) {
			COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
		}
		//zval_ptr_dtor(&local_retval_ptr);
	}

	return status;
}

/**
 * Call method on an object that not requires parameters
 *
 */
int phalcon_call_method(zval *return_value, zval *object, char *method_name, int method_len, int check, int noreturn TSRMLS_DC){
#if PHALCON_EXPERIMENTAL_CALL
	return phalcon_call_method_fast(return_value, object, method_name, method_len, check, noreturn TSRMLS_CC);
#else
	return phalcon_call_method_normal(return_value, object, method_name, method_len, check, noreturn TSRMLS_CC);
#endif
}

/**
 * Call methods that require parameters in a old-style secure way
 */
inline int phalcon_call_method_params_normal(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC){

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
 * This is an experimental method to call methods that requires parameters in a faster way
 */
inline int phalcon_call_method_params_fast(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC){

	int status;
	zend_class_entry *active_scope = NULL;
	zval ***params_array;
	zend_uint i;
	zval *local_retval_ptr = NULL;
	HashTable *function_table;
	zend_fcall_info_cache local_fcache;
	zend_fcall_info_cache *fcc = NULL;
	zend_class_entry *obj_ce;

	if (Z_TYPE_P(object) != IS_OBJECT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", method_name);
		return FAILURE;
	}

	obj_ce = Z_OBJCE_P(object);
	function_table = &obj_ce->function_table;

	fcc = &local_fcache;
	fcc->initialized = 0;
	fcc->calling_scope = obj_ce;
	fcc->called_scope = obj_ce;
	fcc->function_handler = NULL;
	fcc->object_ptr = object;

	if (zend_hash_find(function_table, method_name, method_len+1, (void**)&fcc->function_handler) != SUCCESS) {
		if (check) {
			return FAILURE;
		}
	}

	params_array = (zval ***) emalloc(sizeof(zval **)*param_count);
	for (i=0; i<param_count; i++) {
		params_array[i] = &params[i];
	}

	active_scope = EG(scope);
	phalcon_find_scope(obj_ce, method_name, method_len TSRMLS_CC);

	status = phalcon_call_user_method_ex(function_table, &object, method_name, method_len, &local_retval_ptr, param_count, params_array, fcc TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s() on class %s", method_name, obj_ce->name);
	}

	EG(scope) = active_scope;
	if (local_retval_ptr) {
		if (noreturn) {
			COPY_PZVAL_TO_ZVAL(*return_value, local_retval_ptr);
		}
		//zval_ptr_dtor(&local_retval_ptr);
	}

	if(params_array){
		efree(params_array);
	}

	return status;
}

/**
 * Call method on an object that requires an arbitrary number of parameters
 *
 */
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int method_len, zend_uint param_count, zval *params[], int check, int noreturn TSRMLS_DC){
#if PHALCON_EXPERIMENTAL_CALL
	return phalcon_call_method_params_fast(return_value, object, method_name, method_len, param_count, params, check, noreturn TSRMLS_CC);
#else
	return phalcon_call_method_params_normal(return_value, object, method_name, method_len, param_count, params, check, noreturn TSRMLS_CC);
#endif
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
	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
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
 * Executes zend_function with a prepared fci_cache (even cached)
 */
int phalcon_call_user_function_ex(HashTable *function_table, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], zend_fcall_info_cache *fci_cache TSRMLS_DC){

	zend_fcall_info fci;

	fci.size = sizeof(fci);
	fci.function_table = function_table;
	fci.object_ptr = NULL;
	fci.function_name = NULL;
	fci.retval_ptr_ptr = retval_ptr_ptr;
	fci.param_count = param_count;
	fci.params = params;
	fci.no_separation = 1;
	fci.symbol_table = NULL;

	if (fci_cache->function_handler->type == ZEND_INTERNAL_FUNCTION) {
		return phalcon_call_internal_function(&fci, fci_cache TSRMLS_CC);
	} else {
		return zend_call_function(&fci, fci_cache TSRMLS_CC);
	}

}

/**
 * This is poor copy of the Zend Engine's function zend_call_function
 * We adapted it to avoid some overhead and btw it's only working with zend internal functions
 */
int phalcon_call_internal_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC){

	zend_uint i;
	zend_class_entry *current_scope;
	zend_class_entry *current_called_scope;
	zend_class_entry *calling_scope = NULL;
	zend_class_entry *called_scope = NULL;
	zend_execute_data execute_data;

	*fci->retval_ptr_ptr = NULL;

	if (EG(exception)) {
		return FAILURE;
	}

	if (EG(current_execute_data)) {
		execute_data = *EG(current_execute_data);
		EX(op_array) = NULL;
		EX(opline) = NULL;
		EX(object) = NULL;
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = fci_cache->calling_scope;
	called_scope = fci_cache->called_scope;

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i=0; i<fci->param_count; i++) {
		zval *param;
		Z_ADDREF_PP(fci->params[i]);
		param = *fci->params[i];
		zend_vm_stack_push_nocheck(param TSRMLS_CC);
	}

	EX(function_state).arguments = zend_vm_stack_top(TSRMLS_C);
	zend_vm_stack_push_nocheck((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);

	current_scope = EG(scope);
	EG(scope) = calling_scope;

	current_called_scope = EG(called_scope);
	if (called_scope) {
		EG(called_scope) = called_scope;
	}

	EX(prev_execute_data) = EG(current_execute_data);
	EG(current_execute_data) = &execute_data;

	int call_via_handler = (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
	ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
	if (EX(function_state).function->common.scope) {
		EG(scope) = EX(function_state).function->common.scope;
	}

	((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
	if (EG(exception) && fci->retval_ptr_ptr) {
		zval_ptr_dtor(fci->retval_ptr_ptr);
		*fci->retval_ptr_ptr = NULL;
	}
	if (call_via_handler) {
		fci_cache->initialized = 0;
	}
	zend_vm_stack_clear_multiple(TSRMLS_C);

	EG(called_scope) = current_called_scope;
	EG(scope) = current_scope;
	EG(current_execute_data) = EX(prev_execute_data);

	if (EG(exception)) {
		zend_throw_exception_internal(NULL TSRMLS_CC);
	}

	return SUCCESS;
}

/**
 * Executes a zend internal method without fci
 */
int phalcon_call_user_method_ex(HashTable *function_table, zval **object_pp, char *method_name, int method_len, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], zend_fcall_info_cache *fcc TSRMLS_DC){

	zend_fcall_info fci;
	zval *function_name;
	int status;

	fci.size = sizeof(fci);
	fci.function_table = function_table;
	fci.object_ptr = *object_pp;
	fci.function_name = NULL;
	fci.retval_ptr_ptr = retval_ptr_ptr;
	fci.param_count = param_count;
	fci.params = params;
	fci.no_separation = 1;
	fci.symbol_table = NULL;

	if (fcc && fcc->function_handler->type == ZEND_INTERNAL_FUNCTION) {
		return phalcon_call_internal_method(method_name, method_len, &fci, fcc TSRMLS_CC);
	} else {
		/* Overloaded and user functions are called in a standard way */
		ALLOC_INIT_ZVAL(function_name);
		ZVAL_STRINGL(function_name, method_name, method_len, 1);
		fci.function_name = function_name;
		status = zend_call_function(&fci, fcc TSRMLS_CC);
		zval_ptr_dtor(&function_name);
		return status;
	}
}

int phalcon_is_callable_check_method(char *method_name, int method_len, zend_fcall_info_cache *fcc TSRMLS_DC){

	int retval = 0;

	if (!fcc->calling_scope) {
		return 0;
	}

	fcc->function_handler = NULL;
	if (zend_hash_find(&fcc->calling_scope->function_table, method_name, method_len+1, (void**)&fcc->function_handler) == SUCCESS) {
		retval = 1;
	} else {
		if (Z_OBJ_HT_P(fcc->object_ptr)->get_method) {
			fcc->function_handler = Z_OBJ_HT_P(fcc->object_ptr)->get_method(&fcc->object_ptr, method_name, method_len TSRMLS_CC);
			if (fcc->function_handler) {
				retval = 1;
			}
		}
	}

	if (retval) {
		fcc->initialized = 1;
	}

	return retval;
}

int phalcon_is_callable_ex(char *method_name, int method_len, zval *object_ptr, zend_fcall_info_cache *fcc TSRMLS_DC) {
	if(!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(object_ptr)].valid) {
		return 0;
	}
	return phalcon_is_callable_check_method(method_name, method_len, fcc TSRMLS_CC);
}

int phalcon_call_internal_method(char *method_name, int method_len, zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC) {

	zend_uint i;
	zend_class_entry *current_scope;
	zend_class_entry *current_called_scope;
	zend_class_entry *calling_scope = NULL;
	zend_class_entry *called_scope = NULL;
	zval *current_this;
	zend_execute_data execute_data;

	*fci->retval_ptr_ptr = NULL;

	if (EG(exception)) {
		return FAILURE;
	}

	if (EG(current_execute_data)) {
		execute_data = *EG(current_execute_data);
		EX(op_array) = NULL;
		EX(opline) = NULL;
		EX(object) = NULL;
	}

	if (!fci) {
		if (!phalcon_is_callable_ex(method_name, method_len, fci->object_ptr, fci_cache TSRMLS_CC)) {
			return FAILURE;
		}
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = fci_cache->calling_scope;
	called_scope = fci_cache->called_scope;
	fci->object_ptr = fci_cache->object_ptr;

	EX(object) = fci->object_ptr;
	if ((!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
		return FAILURE;
	}

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i=0; i<fci->param_count; i++) {
		zval *param;
		Z_ADDREF_PP(fci->params[i]);
		param = *fci->params[i];
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
		EG(called_scope) = NULL;
	}

	EG(This) = fci->object_ptr;

	if (!PZVAL_IS_REF(EG(This))) {
		Z_ADDREF_P(EG(This));
	} else {
		zval *this_ptr;
		ALLOC_ZVAL(this_ptr);
		*this_ptr = *EG(This);
		INIT_PZVAL(this_ptr);
		zval_copy_ctor(this_ptr);
		EG(This) = this_ptr;
	}

	EX(prev_execute_data) = EG(current_execute_data);
	EG(current_execute_data) = &execute_data;

	int call_via_handler = (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
	ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
	if (EX(function_state).function->common.scope) {
		EG(scope) = EX(function_state).function->common.scope;
	}

	((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
	if (EG(exception) && fci->retval_ptr_ptr) {
		zval_ptr_dtor(fci->retval_ptr_ptr);
		*fci->retval_ptr_ptr = NULL;
	}

	if (call_via_handler) {
		fci_cache->initialized = 0;
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
		zend_throw_exception_internal(NULL TSRMLS_CC);
	}

	return SUCCESS;
}
