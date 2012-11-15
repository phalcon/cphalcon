
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
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"

/**
 * Phalcon\Filter
 *
 * The Phalcon\Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension. Also allows the developer to
 * define his/her own filters
 *
 *<code>
 *$filter = new Phalcon\Filter();
 *$filter->sanitize("some(one)@exa\\mple.com", "email"); // returns "someone@example.com"
 *$filter->sanitize("hello<<", "string"); // returns "hello"
 *$filter->sanitize("!100a019", "int"); // returns "100019"
 *$filter->sanitize("!100a019.01a", "float"); // returns "100019.01"
 *</code>
 *
 */


/**
 * Phalcon\Filter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Filter){

	PHALCON_REGISTER_CLASS(Phalcon, Filter, filter, phalcon_filter_method_entry, 0);

	zend_declare_property_null(phalcon_filter_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_filter_ce TSRMLS_CC, 1, phalcon_filterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Filter constructor
 */
PHP_METHOD(Phalcon_Filter, __construct){


	phalcon_update_property_empty_array(phalcon_filter_ce, this_ptr, SL("_filters") TSRMLS_CC);
	
}

/**
 * Adds a user-defined filter
 *
 * @param string $name
 * @param callable $handler
 * @return Phalcon\Filter
 */
PHP_METHOD(Phalcon_Filter, add){

	zval *name, *handler;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &handler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_filter_exception_ce, "Filter name must be string");
		return;
	}
	if (Z_TYPE_P(handler) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_filter_exception_ce, "Filter must be an object");
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_filters"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, name, &handler, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_filters"), t0 TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Sanizites a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  mixed $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize){

	zval *value, *filters, *new_value = NULL, *filter = NULL, *filter_value = NULL;
	zval *sanizited_value;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &value, &filters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(filters) == IS_ARRAY) { 
		PHALCON_CPY_WRT(new_value, value);
		if (Z_TYPE_P(value) != IS_NULL) {
	
			if (!phalcon_valid_foreach(filters TSRMLS_CC)) {
				return;
			}
	
			ah0 = Z_ARRVAL_P(filters);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
			ph_cycle_start_0:
	
				if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
					goto ph_cycle_end_0;
				}
	
				PHALCON_GET_FOREACH_VALUE(filter);
	
				PHALCON_INIT_NVAR(filter_value);
				PHALCON_CALL_METHOD_PARAMS_2(filter_value, this_ptr, "_sanitize", new_value, filter, PH_NO_CHECK);
				PHALCON_CPY_WRT(new_value, filter_value);
	
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
	
			ph_cycle_end_0:
			if(0){}
	
		}
	
	
		RETURN_CCTOR(new_value);
	}
	
	PHALCON_INIT_VAR(sanizited_value);
	PHALCON_CALL_METHOD_PARAMS_2(sanizited_value, this_ptr, "_sanitize", value, filters, PH_NO_CHECK);
	
	RETURN_CCTOR(sanizited_value);
}

/**
 * Internal sanizite wrapper to filter_var
 *
 * @param  mixed $value
 * @param  string $filter
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *value, *filter, *filters, *filter_object;
	zval *arguments, *filtered = NULL, *type = NULL, *quote, *empty_str;
	zval *escaped, *allow_fraction, *options, *exception_message;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &value, &filter) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(filters);
	phalcon_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(filters, filter);
	if (eval_int) {
		PHALCON_INIT_VAR(filter_object);
		phalcon_array_fetch(&filter_object, filters, filter, PH_NOISY_CC);
		if (phalcon_is_instance_of(filter_object, SL("Closure") TSRMLS_CC)) {
			PHALCON_INIT_VAR(arguments);
			array_init(arguments);
			phalcon_array_append(&arguments, value, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_VAR(filtered);
			PHALCON_CALL_USER_FUNC_ARRAY(filtered, filter_object, arguments);
		} else {
			PHALCON_INIT_NVAR(filtered);
			PHALCON_CALL_METHOD_PARAMS_1(filtered, filter_object, "filter", value, PH_NO_CHECK);
		}
	
	
		RETURN_CCTOR(filtered);
	}
	
	PHALCON_INIT_NVAR(filtered);
	
	if (PHALCON_COMPARE_STRING(filter, "email")) {
		/** 
		 * The 'email' filter uses the filter extension
		 */
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 517);
	
		PHALCON_INIT_VAR(quote);
		ZVAL_STRING(quote, "'", 1);
	
		PHALCON_INIT_VAR(empty_str);
		ZVAL_STRING(empty_str, "", 1);
	
		PHALCON_INIT_VAR(escaped);
		phalcon_fast_str_replace(escaped, quote, empty_str, value TSRMLS_CC);
	
		PHALCON_INIT_NVAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", escaped, type);
		goto ph_end_0;
	}
	
	if (PHALCON_COMPARE_STRING(filter, "int")) {
		/** 
		 * 'int' filter sanitizes a numeric input
		 */
		PHALCON_INIT_NVAR(type);
		ZVAL_LONG(type, 519);
	
		PHALCON_INIT_NVAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, type);
		goto ph_end_0;
	}
	
	if (PHALCON_COMPARE_STRING(filter, "string")) {
		PHALCON_INIT_NVAR(type);
		ZVAL_LONG(type, 513);
	
		PHALCON_INIT_NVAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, type);
		goto ph_end_0;
	}
	
	if (PHALCON_COMPARE_STRING(filter, "float")) {
		/** 
		 * The 'float' filter uses the filter extension
		 */
		PHALCON_INIT_VAR(allow_fraction);
		ZVAL_LONG(allow_fraction, 4096);
	
		PHALCON_INIT_VAR(options);
		array_init(options);
		phalcon_array_update_string(&options, SL("flags"), &allow_fraction, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(type);
		ZVAL_LONG(type, 520);
	
		PHALCON_INIT_NVAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_3(filtered, "filter_var", value, type, options);
		goto ph_end_0;
	}
	
	if (PHALCON_COMPARE_STRING(filter, "alphanum")) {
		PHALCON_INIT_NVAR(filtered);
		phalcon_filter_alphanum(filtered, value);
		goto ph_end_0;
	}
	
	if (PHALCON_COMPARE_STRING(filter, "trim")) {
		PHALCON_INIT_NVAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "trim", value);
		goto ph_end_0;
	}
	
	if (PHALCON_COMPARE_STRING(filter, "striptags")) {
		PHALCON_INIT_NVAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "strip_tags", value);
		goto ph_end_0;
	}
	
	if (PHALCON_COMPARE_STRING(filter, "lower")) {
		if (phalcon_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS) {
			/** 
			 * 'lower' checks for the mbstring extension to make a correct lowercase
			 * transformation
			 */
			PHALCON_INIT_NVAR(filtered);
			PHALCON_CALL_FUNC_PARAMS_1(filtered, "mb_strtolower", value);
		} else {
			PHALCON_INIT_NVAR(filtered);
			PHALCON_CALL_FUNC_PARAMS_1(filtered, "strtolower", value);
		}
		goto ph_end_0;
	}
	
	if (PHALCON_COMPARE_STRING(filter, "upper")) {
		if (phalcon_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS) {
			/** 
			 * 'upper' checks for the mbstring extension to make a correct lowercase
			 * transformation
			 */
			PHALCON_INIT_NVAR(filtered);
			PHALCON_CALL_FUNC_PARAMS_1(filtered, "mb_strtoupper", value);
		} else {
			PHALCON_INIT_NVAR(filtered);
			PHALCON_CALL_FUNC_PARAMS_1(filtered, "strtoupper", value);
		}
		goto ph_end_0;
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "Sanitize filter ", filter, " is not supported");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_filter_exception_ce, exception_message);
	return;
	
	ph_end_0:
	
	RETURN_CCTOR(filtered);
}

/**
 * Return the user-defined filters in the instance
 *
 * @return object[]
 */
PHP_METHOD(Phalcon_Filter, getFilters){


	RETURN_MEMBER(this_ptr, "_filters");
}

