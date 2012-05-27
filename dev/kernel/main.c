
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
#include "ext/standard/php_string.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Initialize globals on each request or each thread started
 */
void php_phalcon_init_globals(zend_phalcon_globals *phalcon_globals TSRMLS_DC){
    phalcon_globals->phalcon_memory_stack = 0;
    phalcon_globals->start_memory = NULL;
	phalcon_globals->active_memory = NULL;
	#ifndef PHALCON_RELEASE
	phalcon_globals->phalcon_stack_stats = 0;
	phalcon_globals->phalcon_fcall_stats = 0;
	#endif
}

/**
 * Initilializes super global variables if doesn't
 */
int phalcon_init_global(char *global, int global_length TSRMLS_DC){
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
int phalcon_get_global(zval **arr, char *global, int global_length TSRMLS_DC){

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
 * Throws an zval object as exception
 */
void phalcon_throw_exception(zval *object TSRMLS_DC){
	Z_ADDREF_P(object);
	zend_throw_exception_object(object TSRMLS_CC);
	phalcon_clean_restore_stack(TSRMLS_C);
}

/**
 * Makes fast count on implicit array types
 */
void phalcon_fast_count(zval *result, zval *array TSRMLS_DC){
	if (Z_TYPE_P(array) == IS_ARRAY) {
		ZVAL_LONG(result, zend_hash_num_elements(Z_ARRVAL_P(array)));
		return;
	} else {
		if (Z_TYPE_P(array) == IS_OBJECT) {

			#ifdef HAVE_SPL
			zval *retval;
			#endif

			if (Z_OBJ_HT_P(array)->count_elements) {
				ZVAL_LONG(result, 1);
				if (SUCCESS == Z_OBJ_HT(*array)->count_elements(array, &Z_LVAL_P(result) TSRMLS_CC)) {
					return;
				}
			}

			#ifdef HAVE_SPL
			if (Z_OBJ_HT_P(array)->get_class_entry && instanceof_function(Z_OBJCE_P(array), spl_ce_Countable TSRMLS_CC)) {
    			zend_call_method_with_0_params(&array, NULL, NULL, "count", &retval);
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
			if (Z_TYPE_P(array) == IS_NULL) {
				ZVAL_LONG(result, 0);
				return;
			}
		}
	}
	ZVAL_LONG(result, 1);
}

/**
 * Fast call to join php function
 */
void phalcon_fast_join(zval *result, zval *glue, zval *pieces TSRMLS_DC){

	if (Z_TYPE_P(glue) != IS_STRING || Z_TYPE_P(pieces) != IS_ARRAY){
		ZVAL_NULL(result);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for join()");
		return;
	}

	php_implode(glue, pieces, result TSRMLS_CC);
}

void phalcon_fast_explode(zval *result, zval *delimiter, zval *str TSRMLS_DC){

	if (Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(delimiter) != IS_STRING){
		ZVAL_NULL(result);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for explode()");
		return;
	}

	array_init(result);
	php_explode(delimiter, str, result, LONG_MAX);
}

/**
 * Inmediate function resolution for addslaches function
 */
void phalcon_fast_addslashes(zval *return_value, zval *param TSRMLS_DC){

	if (Z_TYPE_P(param) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for explode()");
		return;
	}

	//php_addslashes_ex(Z_STRVAL_P(param), Z_STRLEN_P(param), return_value, 0 TSRMLS_CC)

	return;
}

/**
 * Checks if a file exists
 *
 */
int phalcon_file_exists(zval *filename TSRMLS_DC){

	if (Z_TYPE_P(filename) != IS_STRING) {
		return FAILURE;
	}

	if (VCWD_ACCESS(Z_STRVAL_P(filename), F_OK) == 0) {
		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Filter alphanum string
 */
int phalcon_filter_alphanum(zval *result, zval *param){

	int i, ch, alloc = 0;
	char temp[255];

	if (Z_TYPE_P(param) == IS_STRING) {
		for(i=0; i < Z_STRLEN_P(param) && i < 255;i++){
			ch = Z_STRVAL_P(param)[i];
			if((ch>96&&ch<123)||(ch>64&&ch<91)||(ch>47&&ch<58)){
				temp[alloc] = ch;
				alloc++;
			}
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

	return SUCCESS;
}

/**
 * Exports symbols to the active symbol table
 */
int phalcon_set_symbol(zval *key_name, zval *value TSRMLS_DC){

	int use_symbol_table = 0;
	HashTable *old_symbol_table;

	if (!EG(active_symbol_table)) {
		old_symbol_table = EG(active_symbol_table);
		EG(active_symbol_table) = &EG(symbol_table);
		use_symbol_table = 1;
	}

	if (EG(active_symbol_table)) {
		if (Z_TYPE_P(key_name) == IS_STRING){
			Z_ADDREF_P(value);
			zend_hash_update(EG(active_symbol_table), Z_STRVAL_P(key_name), Z_STRLEN_P(key_name)+1, &value, sizeof(zval *), NULL);
			if (EG(exception)) {
				return FAILURE;
			}
		}
	}

	if (use_symbol_table) {
		EG(active_symbol_table) = old_symbol_table;
	}

	return SUCCESS;
}

/**
 * Generates error when foreach is invalid
 */
int phalcon_valid_foreach(zval *arr TSRMLS_DC){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		return 0;
	}
	return 1;
}

/**
 * Generates error when inherited class isn't found
 */
void phalcon_inherit_not_found(char *class_name, char *inherit_name){
	fprintf(stderr, "Phalcon Error: Extended class '%s' not found when registering class '%s'", class_name, inherit_name);
}