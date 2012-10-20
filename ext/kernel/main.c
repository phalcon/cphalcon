
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
#include "php_main.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Initialize globals on each request or each thread started
 */
void php_phalcon_init_globals(zend_phalcon_globals *phalcon_globals TSRMLS_DC){
    phalcon_globals->start_memory = NULL;
	phalcon_globals->active_memory = NULL;
	#ifndef PHALCON_RELEASE
	phalcon_globals->phalcon_stack_stats = 0;
	phalcon_globals->phalcon_number_grows = 0;
	#endif
}

/**
 * Initilializes super global variables if doesn't
 */
int phalcon_init_global(char *global, unsigned int global_length TSRMLS_DC){
	#if PHP_VERSION_ID < 50400
	zend_bool jit_initialization = (PG(auto_globals_jit) && !PG(register_globals) && !PG(register_long_arrays));
	if (jit_initialization) {
		return zend_is_auto_global(global, global_length-1 TSRMLS_CC);
	}
	#else
	if (PG(auto_globals_jit)) {
		return zend_is_auto_global(global, global_length-1 TSRMLS_CC);
	}
	#endif
	return SUCCESS;
}

/**
 * Gets the global zval into PG macro
 */
int phalcon_get_global(zval **arr, char *global, unsigned int global_length TSRMLS_DC){

	zval **gv;

	zend_bool jit_initialization = PG(auto_globals_jit);
	if (jit_initialization) {
		zend_is_auto_global(global, global_length-1 TSRMLS_CC);
	}

	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), global, global_length, (void **) &gv) == SUCCESS) {
			if (Z_TYPE_PP(gv) == IS_ARRAY) {
				*arr = *gv;
			} else {
				PHALCON_INIT_VAR(*arr);
				array_init(*arr);
			}
		}
	}

	if (!*arr) {
		PHALCON_INIT_VAR(*arr);
		array_init(*arr);
	}

	return SUCCESS;
}

/**
 * Makes fast count on implicit array types
 */
void phalcon_fast_count(zval *result, zval *value TSRMLS_DC){
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_LONG(result, zend_hash_num_elements(Z_ARRVAL_P(value)));
		return;
	} else {
		if (Z_TYPE_P(value) == IS_OBJECT) {

			#ifdef HAVE_SPL
			zval *retval = NULL;
			#endif

			if (Z_OBJ_HT_P(value)->count_elements) {
				ZVAL_LONG(result, 1);
				if (SUCCESS == Z_OBJ_HT(*value)->count_elements(value, &Z_LVAL_P(result) TSRMLS_CC)) {
					return;
				}
			}

			#ifdef HAVE_SPL
			if (Z_OBJ_HT_P(value)->get_class_entry && instanceof_function(Z_OBJCE_P(value), spl_ce_Countable TSRMLS_CC)) {
				zend_call_method_with_0_params(&value, NULL, NULL, "count", &retval);
				if (retval) {
					convert_to_long_ex(&retval);
					ZVAL_LONG(result, Z_LVAL_P(retval));
					zval_ptr_dtor(&retval);
				}
				return;
			}
			#endif

			ZVAL_LONG(result, 0);
			return;

		} else {
			if (Z_TYPE_P(value) == IS_NULL) {
				ZVAL_LONG(result, 0);
				return;
			}
		}
	}
	ZVAL_LONG(result, 1);
}

/**
 * Makes fast count on implicit array types without creating a return zval value
 */
int phalcon_fast_count_ev(zval *value TSRMLS_DC){

	long count = 0;

	if (Z_TYPE_P(value) == IS_ARRAY) {
		return (int) zend_hash_num_elements(Z_ARRVAL_P(value)) > 0;
	} else {
		if (Z_TYPE_P(value) == IS_OBJECT) {

			#ifdef HAVE_SPL
			zval *retval = NULL;
			#endif

			if (Z_OBJ_HT_P(value)->count_elements) {
				Z_OBJ_HT(*value)->count_elements(value, &count TSRMLS_CC);
				return (int) count > 0;
			}

			#ifdef HAVE_SPL
			if (Z_OBJ_HT_P(value)->get_class_entry && instanceof_function(Z_OBJCE_P(value), spl_ce_Countable TSRMLS_CC)) {
				zend_call_method_with_0_params(&value, NULL, NULL, "count", &retval);
				if (retval) {
					convert_to_long_ex(&retval);
					count = Z_LVAL_P(retval);
					zval_ptr_dtor(&retval);
					return (int) count > 0;
				}
				return 0;
			}
			#endif

			return 0;
		} else {
			if (Z_TYPE_P(value) == IS_NULL) {
				return 0;
			}
		}
	}
	return 1;
}

/**
 * Check if method exists on certain object using explicit char param
 */
int phalcon_function_exists_ex(char *method_name, unsigned int method_len TSRMLS_DC){

	if (zend_hash_exists(CG(function_table), method_name, method_len)) {
		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Filter alphanum string
 */
int phalcon_filter_alphanum(zval *result, zval *param){

	int i, ch, alloc = 0;
	char temp[2048];
	zval copy;
	int use_copy = 0;

	if (Z_TYPE_P(param) != IS_STRING) {
		zend_make_printable_zval(param, &copy, &use_copy);
		if (use_copy) {
			param = &copy;
		}
	}

	for (i=0; i < Z_STRLEN_P(param) && i < 2048; i++) {
		ch = Z_STRVAL_P(param)[i];
		if ((ch>96 && ch<123)||(ch>64 && ch<91)||(ch>47 && ch<58)) {
			temp[alloc] = ch;
			alloc++;
		}
	}

	if (alloc > 0) {
		Z_TYPE_P(result) = IS_STRING;
		Z_STRLEN_P(result) = alloc;
		Z_STRVAL_P(result) = (char *) emalloc(alloc+1);
		memcpy(Z_STRVAL_P(result), temp, alloc);
		Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	} else {
		ZVAL_STRING(result, "", 1);
	}

	if (use_copy) {
		zval_dtor(param);
	}

	return SUCCESS;
}

/**
 * Filter identifiers string like variables or database columns/tables
 */
int phalcon_filter_identifier(zval *result, zval *param){

	int i, ch, alloc = 0;
	char temp[2048];
	zval copy;
	int use_copy = 0;

	if (Z_TYPE_P(param) != IS_STRING) {
		zend_make_printable_zval(param, &copy, &use_copy);
		if (use_copy) {
			param = &copy;
		}
	}

	for (i=0; i < Z_STRLEN_P(param) && i < 2048; i++) {
		ch = Z_STRVAL_P(param)[i];
		if ((ch>96 && ch<123) || (ch>64 && ch<91) || (ch>47 && ch<58) || ch==95) {
			temp[alloc] = ch;
			alloc++;
		}
	}

	if (alloc > 0) {
		Z_TYPE_P(result) = IS_STRING;
		Z_STRLEN_P(result) = alloc;
		Z_STRVAL_P(result) = (char *) emalloc(alloc+1);
		memcpy(Z_STRVAL_P(result), temp, alloc);
		Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	} else {
		ZVAL_STRING(result, "", 1);
	}

	if (use_copy) {
		zval_dtor(param);
	}

	return SUCCESS;
}

/**
 * Exports symbols to the active symbol table
 */
int phalcon_set_symbol(zval *key_name, zval *value TSRMLS_DC){

	if (!EG(active_symbol_table)) {
		zend_rebuild_symbol_table(TSRMLS_C);
	}

	if (EG(active_symbol_table)) {
		if (Z_TYPE_P(key_name) == IS_STRING) {
			Z_ADDREF_P(value);
			zend_hash_update(EG(active_symbol_table), Z_STRVAL_P(key_name), Z_STRLEN_P(key_name)+1, &value, sizeof(zval *), NULL);
			if (EG(exception)) {
				return FAILURE;
			}
		}
	}

	return SUCCESS;
}

/**
 * Exports a string symbol to the active symbol table
 */
int phalcon_set_symbol_str(char *key_name, unsigned int key_length, zval *value TSRMLS_DC){

	if (!EG(active_symbol_table)) {
		zend_rebuild_symbol_table(TSRMLS_C);
	}

	if (&EG(symbol_table)) {
		Z_ADDREF_P(value);
		zend_hash_update(&EG(symbol_table), key_name, key_length, &value, sizeof(zval *), NULL);
		if (EG(exception)) {
			return FAILURE;
		}
	}

	return SUCCESS;
}

/**
 * Generates error when foreach is invalid
 */
int phalcon_valid_foreach(zval *arr TSRMLS_DC){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid argument supplied for foreach()");
		phalcon_memory_restore_stack(TSRMLS_C);
		return 0;
	}
	return 1;
}

/**
 * Generates error when inherited class isn't found
 */
void phalcon_inherit_not_found(char *class_name, char *inherit_name){
	fprintf(stderr, "Phalcon Error: Class to extend '%s' was not found when registering class '%s'\n", class_name, inherit_name);
}
