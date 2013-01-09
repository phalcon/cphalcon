
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

	/* Memory options */
	phalcon_globals->start_memory = NULL;
	phalcon_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	phalcon_globals->symbol_tables = NULL;

	/* Cache options */
	phalcon_globals->function_cache = NULL;

	/* Stats options */
	#ifndef PHALCON_RELEASE
	phalcon_globals->phalcon_stack_stats = 0;
	phalcon_globals->phalcon_number_grows = 0;
	#endif

	/* ORM options*/
	phalcon_globals->orm.events = 1;
	phalcon_globals->orm.virtual_foreign_keys = 1;
	phalcon_globals->orm.column_renaming = 1;
	phalcon_globals->orm.not_null_validations = 1;

	/* DB options */
	phalcon_globals->db.escape_identifiers = 1;
}

/**
 * Initializes internal interface with extends
 */
zend_class_entry *phalcon_register_internal_interface_ex(zend_class_entry *orig_class_entry, char *parent_name TSRMLS_DC){

	zend_class_entry *ce, **pce;

	if (zend_hash_find(CG(class_table), parent_name, strlen(parent_name)+1, (void **) &pce) == FAILURE) {
		return NULL;
	}

	ce = zend_register_internal_interface(orig_class_entry TSRMLS_CC);
	if (*pce) {
		zend_do_inheritance(ce, *pce TSRMLS_CC);
	}

	return ce;
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
 * Checks if a zval is callable
 */
int phalcon_is_callable(zval *var TSRMLS_DC){

	char *error = NULL;
	zend_bool retval;

	retval = zend_is_callable_ex(var, NULL, 0, NULL, NULL, NULL, &error TSRMLS_CC);
	if (error) {
		efree(error);
	}

	return (int) retval;
}

/**
 * Creates virtual symbol tables dinamically
 */
void phalcon_create_symbol_table(TSRMLS_D) {

	if (!PHALCON_GLOBAL(symbol_tables)) {
		PHALCON_GLOBAL(symbol_tables) = emalloc(sizeof(HashTable **) * 4);
		PHALCON_GLOBAL(number_symbol_tables) = 1;
	} else {
		if ((PHALCON_GLOBAL(number_symbol_tables) % 4) == 0) {
			PHALCON_GLOBAL(symbol_tables) = erealloc(PHALCON_GLOBAL(symbol_tables), sizeof(HashTable **) * 4 + PHALCON_GLOBAL(number_symbol_tables));
		}
		PHALCON_GLOBAL(number_symbol_tables)++;
	}

	PHALCON_GLOBAL(symbol_tables)[PHALCON_GLOBAL(number_symbol_tables) - 1] = EG(active_symbol_table);
	EG(active_symbol_table) = NULL;
}

/**
 * Restores a virtual symbol table
 */
void phalcon_restore_symbol_table(TSRMLS_D) {

	if (PHALCON_GLOBAL(symbol_tables)) {

		EG(active_symbol_table) = PHALCON_GLOBAL(symbol_tables)[PHALCON_GLOBAL(number_symbol_tables) - 1];

		PHALCON_GLOBAL(number_symbol_tables)--;

		if (PHALCON_GLOBAL(number_symbol_tables) == 0) {
			efree(PHALCON_GLOBAL(symbol_tables));
			PHALCON_GLOBAL(symbol_tables) = NULL;
		}
	}
}

/**
 * Restores all the virtual symbol tables
 */
void phalcon_clean_symbol_tables(TSRMLS_D) {

	unsigned int i;

	if (PHALCON_GLOBAL(symbol_tables)) {
		for (i = PHALCON_GLOBAL(number_symbol_tables); i > 0; i--) {
			EG(active_symbol_table) = PHALCON_GLOBAL(symbol_tables)[i - 1];
		}
		efree(PHALCON_GLOBAL(symbol_tables));
		PHALCON_GLOBAL(symbol_tables) = NULL;
	}
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
