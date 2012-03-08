
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
#include "zend_exceptions.h"

/**
 * Finds the correct scope to execute the function
 */
int phalcon_find_scope(zend_class_entry *ce, char *method_name TSRMLS_DC){

	int method_len = strlen(method_name);

	#if PHP_VERSION_ID >= 50400
	char *lcname = zend_str_tolower_dup(method_name, method_len);
	#else
	const zend_function_entry *functions;
	#endif

	while (ce) {
		#if PHP_VERSION_ID < 50400
		if (ce->builtin_functions) {			
			functions = ce->builtin_functions;
			while (functions->fname) {
				if (!zend_binary_strcasecmp(functions->fname, strlen(functions->fname), method_name, method_len)) {
					EG(scope) = ce;
					return SUCCESS;
				}
				functions++;
			}
		}
		#else				
		if (zend_hash_exists(&ce->function_table, lcname, method_len+1)) {				
			EG(scope) = ce;
			efree(lcname);
			return SUCCESS;
		}		
		#endif
		ce = ce->parent;
	}	

	#if PHP_VERSION_ID >= 50400
	if (lcname) {
		efree(lcname);
	}
	#endif
	return FAILURE;
}

/**
 * Find function scope on parent classes
 */
int phalcon_find_parent_scope(zend_class_entry *ce, char *active_class, char *method_name TSRMLS_DC){

	int method_len = strlen(method_name);	
	int active_class_len = strlen(active_class);

	#if PHP_VERSION_ID >= 50400
	char *lcname = zend_str_tolower_dup(method_name, method_len);
	#else
	const zend_function_entry *functions;
	#endif

	while (ce) {			
		if (!zend_binary_strcasecmp(ce->name, ce->name_length, active_class, active_class_len)) {
			#if PHP_VERSION_ID < 50400
			if (ce->builtin_functions) {			
				functions = ce->builtin_functions;
				while (functions->fname) {						
					if (!zend_binary_strcasecmp(functions->fname, strlen(functions->fname), method_name, method_len)) {
						EG(scope) = ce;
						return SUCCESS;
					}
					functions++;
				}
			}
			#else			
			if (zend_hash_exists(&ce->function_table, lcname, method_len+1)) {				
				EG(scope) = ce;
				efree(lcname);
				return SUCCESS;
			}
			#endif			
		}
		ce = ce->parent;
	}

	#if PHP_VERSION_ID >= 50400
	if (lcname) {
		efree(lcname);
	}
	#endif
	return FAILURE;
}

/**
 * Call single function which not requires parameters
 */
int phalcon_call_func(zval *return_value, char *func_name, int func_length, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRINGL(fn, func_name, func_length, 0);
	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single function which requires parameters
 */
int phalcon_call_func_params(zval *return_value, char *func_name, int func_length, int param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRINGL(fn, func_name, func_length, 0);
	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s()", func_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call method on an object which not requires parameters
 *
 */
int phalcon_call_method(zval *return_value, zval *object, char *method_name, int check, int noreturn TSRMLS_DC){

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

	PHALCON_SET_STRING(fn, method_name, 0);
	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
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

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call method on an object which requires parameters
 *
 */
int phalcon_call_method_params(zval *return_value, zval *object, char *method_name, int param_count, zval *params[], int check, int noreturn TSRMLS_DC){

	zval *fn = NULL;
	int status = FAILURE;
	zend_class_entry *active_scope = NULL;

	if (check) {
		if (!zend_hash_exists(&Z_OBJCE_P(object)->function_table, method_name, strlen(method_name)+1)) {
			return FAILURE;
		}
	}

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	PHALCON_SET_STRING(fn, method_name, 1);
	if (Z_TYPE_P(object) == IS_OBJECT) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
		status = call_user_function(&Z_OBJCE_P(object)->function_table, &object, fn, return_value, param_count, params TSRMLS_CC);
		if(status==FAILURE){
			EG(scope) = active_scope;
			php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined method %s() on class %s", Z_STRVAL_P(fn), Z_OBJCE_P(object)->name);
			return FAILURE;
		}
		EG(scope) = active_scope;
	} else {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to method %s() on a non object", Z_STRVAL_P(fn));
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call parent static function which not requires parameters
 */
int phalcon_call_parent_func(zval *return_value, zval *object, char *active_class, char *method_name, int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, method_name TSRMLS_CC);
	}

	success = phalcon_call_static_func(return_value, "parent", method_name, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call parent static function which requires parameters
 */
int phalcon_call_parent_func_params(zval *return_value, zval *object, char *active_class, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_parent_scope(Z_OBJCE_P(object), active_class, method_name TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, "parent", method_name, param_count, params, noreturn TSRMLS_CC);
	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call self-class static function which not requires parameters
 */
int phalcon_call_self_func(zval *return_value, zval *object, char *method_name, int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
	}

	success = phalcon_call_static_func(return_value, "self", method_name, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call self-class static function which requires parameters
 */
int phalcon_call_self_func_params(zval *return_value, zval *object, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	int success;
	zend_class_entry *active_scope = NULL;

	if (object) {
		active_scope = EG(scope);
		phalcon_find_scope(Z_OBJCE_P(object), method_name TSRMLS_CC);
	}

	success = phalcon_call_static_func_params(return_value, "self", method_name, param_count, params, noreturn TSRMLS_CC);

	if (object) {
		EG(scope) = active_scope;
	}

	return success;
}

/**
 * Call single static function which not requires parameters
 */
int phalcon_call_static_func(zval *return_value, char *class_name, char *method_name, int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_string(fn, class_name, 0);
	add_next_index_string(fn, method_name, 0);
	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status==FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
		return FAILURE;
	}

	if (!noreturn) {
		zval_ptr_dtor(&return_value);
	}

	return status;
}

/**
 * Call single static function on a zval which not requires parameters
 */
int phalcon_call_static_zval_func(zval *return_value, zval *mixed_name, char *method_name, int noreturn TSRMLS_DC){
	
	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}
	
	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_zval(fn, mixed_name);
	add_next_index_string(fn, method_name, 0);
	status = call_user_function(CG(function_table), NULL, fn, return_value, 0, NULL TSRMLS_CC);
	if (status==FAILURE) {
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
 * Call single function which requires parameters
 */
int phalcon_call_static_func_params(zval *return_value, char *class_name, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	zval *fn;
	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}

	ALLOC_INIT_ZVAL(fn);
	array_init(fn);
	add_next_index_string(fn, class_name, 0);
	add_next_index_string(fn, method_name, 0);
	status = call_user_function(CG(function_table), NULL, fn, return_value, param_count, params TSRMLS_CC);
	if (status==FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Call to undefined function %s::%s()", class_name, method_name);
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
int phalcon_call_static_func_zval_params(zval *return_value, zval *mixed_name, char *method_name, int param_count, zval *params[], int noreturn TSRMLS_DC){

	int status = FAILURE;

	if (!noreturn) {
		ALLOC_INIT_ZVAL(return_value);
	}
	
	status = call_user_function(CG(function_table), NULL, mixed_name, return_value, param_count, params TSRMLS_CC);
	if (status==FAILURE) {
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

