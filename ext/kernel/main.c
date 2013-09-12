
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "php_main.h"
#include "ext/spl/spl_exceptions.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Initialize globals on each request or each thread started
 */
void php_zephir_init_globals(zend_zephir_globals *zephir_globals TSRMLS_DC) {

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache options */
	zephir_globals->function_cache = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;
}

/**
 * Initializes internal interface with extends
 */
zend_class_entry *zephir_register_internal_interface_ex(zend_class_entry *orig_ce, zend_class_entry *parent_ce TSRMLS_DC) {

	zend_class_entry *ce;

	ce = zend_register_internal_interface(orig_ce TSRMLS_CC);
	if (parent_ce) {
		zend_do_inheritance(ce, parent_ce TSRMLS_CC);
	}

	return ce;
}

/**
 * Initilializes super global variables if doesn't
 */
int zephir_init_global(char *global, unsigned int global_length TSRMLS_DC) {

	#if PHP_VERSION_ID < 50400
	zend_bool jit_initialization = (PG(auto_globals_jit) && !PG(register_globals) && !PG(register_long_arrays));
	if (jit_initialization) {
		return zend_is_auto_global(global, global_length - 1 TSRMLS_CC);
	}
	#else
	if (PG(auto_globals_jit)) {
		return zend_is_auto_global(global, global_length - 1 TSRMLS_CC);
	}
	#endif

	return SUCCESS;
}

/**
 * Gets the global zval into PG macro
 */
int zephir_get_global(zval **arr, const char *global, unsigned int global_length TSRMLS_DC) {

	zval **gv;

	zend_bool jit_initialization = PG(auto_globals_jit);
	if (jit_initialization) {
		zend_is_auto_global(global, global_length - 1 TSRMLS_CC);
	}

	if (&EG(symbol_table)) {
		if (zend_hash_find(&EG(symbol_table), global, global_length, (void **) &gv) == SUCCESS) {
			if (Z_TYPE_PP(gv) == IS_ARRAY) {
				*arr = *gv;
				if (!*arr) {
					ZEPHIR_INIT_VAR(*arr);
					array_init(*arr);
				}
			} else {
				ZEPHIR_INIT_VAR(*arr);
				array_init(*arr);
			}
			return SUCCESS;
		}
	}

	ZEPHIR_INIT_VAR(*arr);
	array_init(*arr);

	return SUCCESS;
}

/**
 * Makes fast count on implicit array types
 */
void zephir_fast_count(zval *result, zval *value TSRMLS_DC) {

	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_LONG(result, zend_hash_num_elements(Z_ARRVAL_P(value)));
		return;
	}

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
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(result, 0);
		return;
	}

	ZVAL_LONG(result, 1);
}

/**
 * Makes fast count on implicit array types without creating a return zval value
 */
int zephir_fast_count_ev(zval *value TSRMLS_DC) {

	long count = 0;

	if (Z_TYPE_P(value) == IS_ARRAY) {
		return (int) zend_hash_num_elements(Z_ARRVAL_P(value)) > 0;
	}

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
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		return 0;
	}

	return 1;
}

/**
 * Makes fast count on implicit array types without creating a return zval value
 */
int zephir_fast_count_int(zval *value TSRMLS_DC) {

	long count = 0;

	if (Z_TYPE_P(value) == IS_ARRAY) {
		return (int) zend_hash_num_elements(Z_ARRVAL_P(value));
	}

	if (Z_TYPE_P(value) == IS_OBJECT) {

		#ifdef HAVE_SPL
		zval *retval = NULL;
		#endif

		if (Z_OBJ_HT_P(value)->count_elements) {
			Z_OBJ_HT(*value)->count_elements(value, &count TSRMLS_CC);
			return (int) count;
		}

		#ifdef HAVE_SPL
		if (Z_OBJ_HT_P(value)->get_class_entry && instanceof_function(Z_OBJCE_P(value), spl_ce_Countable TSRMLS_CC)) {
			zend_call_method_with_0_params(&value, NULL, NULL, "count", &retval);
			if (retval) {
				convert_to_long_ex(&retval);
				count = Z_LVAL_P(retval);
				zval_ptr_dtor(&retval);
				return (int) count;
			}
			return 0;
		}
		#endif

		return 0;
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		return 0;
	}

	return 1;
}

/**
 * Check if a function exists
 */
int zephir_function_exists(const zval *function_name TSRMLS_DC) {

	return zephir_function_quick_exists_ex(
		Z_STRVAL_P(function_name),
		Z_STRLEN_P(function_name) + 1,
		zend_inline_hash_func(Z_STRVAL_P(function_name), Z_STRLEN_P(function_name) + 1) TSRMLS_CC
	);
}

/**
 * Check if a function exists using explicit char param
 *
 * @param function_name
 * @param function_len strlen(function_name)+1
 */
int zephir_function_exists_ex(const char *function_name, unsigned int function_len TSRMLS_DC) {

	return zephir_function_quick_exists_ex(function_name, function_len, zend_inline_hash_func(function_name, function_len) TSRMLS_CC);
}

/**
 * Check if a function exists using explicit char param (using precomputed hash key)
 */
int zephir_function_quick_exists_ex(const char *method_name, unsigned int method_len, unsigned long key TSRMLS_DC) {

	if (zend_hash_quick_exists(CG(function_table), method_name, method_len, key)) {
		return SUCCESS;
	}

	return FAILURE;
}

/**
 * Checks if a zval is callable
 */
int zephir_is_callable(zval *var TSRMLS_DC) {

	char *error = NULL;
	zend_bool retval;

	retval = zend_is_callable_ex(var, NULL, 0, NULL, NULL, NULL, &error TSRMLS_CC);
	if (error) {
		efree(error);
	}

	return (int) retval;
}

/**
 * Initialize an array to start an iteration over it
 */
int zephir_is_iterable_ex(zval *arr, HashTable **arr_hash, HashPosition *hash_position, int duplicate, int reverse) {

	if (unlikely(Z_TYPE_P(arr) != IS_ARRAY)) {
		return 0;
	}

	if (duplicate) {
		ALLOC_HASHTABLE(*arr_hash);
		zend_hash_init(*arr_hash, 0, NULL, NULL, 0);
		zend_hash_copy(*arr_hash, Z_ARRVAL_P(arr), NULL, NULL, sizeof(zval*));
	} else {
		*arr_hash = Z_ARRVAL_P(arr);
	}

	if (reverse) {
		zend_hash_internal_pointer_end_ex(*arr_hash, hash_position);
	} else {
		zend_hash_internal_pointer_reset_ex(*arr_hash, hash_position);
	}

	return 1;
}

void zephir_safe_zval_ptr_dtor(zval *pzval)
{
	if (pzval) {
		zval_ptr_dtor(&pzval);
	}
}

/**
 * Parses method parameters with minimum overhead
 */
int zephir_fetch_parameters(int num_args TSRMLS_DC, int required_args, int optional_args, ...)
{
	va_list va;
	int arg_count = (int) (zend_uintptr_t) *(zend_vm_stack_top(TSRMLS_C) - 1);
	zval **arg, **p;
	int i;

	if (num_args < required_args || (num_args > (required_args + optional_args))) {
		zephir_throw_exception_string(spl_ce_BadMethodCallException, SL("Wrong number of parameters") TSRMLS_CC);
		return FAILURE;
	}

	if (num_args > arg_count) {
		zephir_throw_exception_string(spl_ce_BadMethodCallException, SL("Could not obtain parameters for parsing") TSRMLS_CC);
		return FAILURE;
	}

	if (!num_args) {
		return SUCCESS;
	}

	va_start(va, optional_args);

	i = 0;
	while (num_args-- > 0) {

		arg = (zval **) (zend_vm_stack_top(TSRMLS_C) - 1 - (arg_count - i));

		p = va_arg(va, zval **);
		*p = *arg;

		i++;
	}

	va_end(va);

	return SUCCESS;
}
