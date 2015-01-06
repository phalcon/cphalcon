
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "filter.h"
#include "filterinterface.h"
#include "filter/exception.h"

#include <Zend/zend_closures.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/filter.h"
#include "kernel/concat.h"

/**
 * Phalcon\Filter
 *
 * The Phalcon\Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension. Also allows the developer to
 * define his/her own filters
 *
 *<code>
 *	$filter = new Phalcon\Filter();
 *	$filter->sanitize("some(one)@exa\\mple.com", "email"); // returns "someone@example.com"
 *	$filter->sanitize("hello<<", "string"); // returns "hello"
 *	$filter->sanitize("!100a019", "int"); // returns "100019"
 *	$filter->sanitize("!100a019.01a", "float"); // returns "100019.01"
 *</code>
 */
zend_class_entry *phalcon_filter_ce;

PHP_METHOD(Phalcon_Filter, add);
PHP_METHOD(Phalcon_Filter, sanitize);
PHP_METHOD(Phalcon_Filter, _sanitize);
PHP_METHOD(Phalcon_Filter, getFilters);

static const zend_function_entry phalcon_filter_method_entry[] = {
	PHP_ME(Phalcon_Filter, add, arginfo_phalcon_filterinterface_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, sanitize, arginfo_phalcon_filterinterface_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, _sanitize, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
 * Adds a user-defined filter
 *
 * @param string $name
 * @param callable $handler
 * @return Phalcon\Filter
 */
PHP_METHOD(Phalcon_Filter, add){

	zval **name, **handler;

	phalcon_fetch_params_ex(2, 0, &name, &handler);

	PHALCON_ENSURE_IS_STRING(name);
	
	if (Z_TYPE_PP(handler) != IS_OBJECT && !phalcon_is_callable(*handler TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_filter_exception_ce, "Filter must be an object or callable");
		return;
	}
	
	phalcon_update_property_array(this_ptr, SL("_filters"), *name, *handler TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sanitizes a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  mixed $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize){

	zval *value, *filters, *norecursive = NULL, *new_value = NULL, *filter = NULL, *array_value = NULL;
	zval *item_value = NULL, *item_key = NULL, *filter_value = NULL, *sanizited_value = NULL;
	zval *key = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &value, &filters, &norecursive);

	if (!norecursive) {
		norecursive = PHALCON_GLOBAL(z_false);
	}
	
	/** 
	 * Apply an array of filters
	 */
	if (Z_TYPE_P(filters) == IS_ARRAY) { 
		PHALCON_CPY_WRT(new_value, value);
		if (Z_TYPE_P(value) != IS_NULL) {
	
			phalcon_is_iterable(filters, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(filter);
	
				/** 
				 * If the value to filter is an array we apply the filters recursively
				 */
				if (Z_TYPE_P(new_value) == IS_ARRAY && !zend_is_true(norecursive)) { 
	
					PHALCON_INIT_NVAR(array_value);
					array_init(array_value);
	
					phalcon_is_iterable(new_value, &ah1, &hp1, 0, 0);
	
					while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
						PHALCON_GET_HKEY(item_key, ah1, hp1);
						PHALCON_GET_HVALUE(item_value);
	
						PHALCON_CALL_METHOD(&filter_value, this_ptr, "_sanitize", item_value, filter);
						phalcon_array_update_zval(&array_value, item_key, filter_value, PH_COPY | PH_SEPARATE);
	
						zend_hash_move_forward_ex(ah1, &hp1);
					}
	
					PHALCON_CPY_WRT(new_value, array_value);
				} else {
					PHALCON_CALL_METHOD(&filter_value, this_ptr, "_sanitize", new_value, filter);
					PHALCON_CPY_WRT(new_value, filter_value);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	
		RETURN_CCTOR(new_value);
	}
	
	/** 
	 * Apply a single filter value
	 */
	if (Z_TYPE_P(value) == IS_ARRAY && !zend_is_true(norecursive)) { 

		PHALCON_INIT_VAR(sanizited_value);
		array_init(sanizited_value);
	
		phalcon_is_iterable(value, &ah2, &hp2, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah2, hp2);
			PHALCON_GET_HVALUE(item_value);
	
			PHALCON_CALL_METHOD(&filter_value, this_ptr, "_sanitize", item_value, filters);
			phalcon_array_update_zval(&sanizited_value, key, filter_value, PH_COPY);
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
	} else {
		PHALCON_CALL_METHOD(&sanizited_value, this_ptr, "_sanitize", value, filters);
	}
	
	RETURN_CCTOR(sanizited_value);
}

/**
 * Internal sanitize wrapper to filter_var
 *
 * @param  mixed $value
 * @param  string $filter
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *value, *filter, *filters, *filter_object;
	zval *arguments, *type = NULL, *quote, *empty_str, *escaped;
	zval *filtered = NULL, *allow_fraction, *options, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &value, &filter);
	
	PHALCON_OBS_VAR(filters);
	phalcon_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&filter_object, filters, filter) && (Z_TYPE_P(filter_object) == IS_OBJECT || phalcon_is_callable(filter_object TSRMLS_CC))) {
	
		/** 
		 * If the filter is a closure we call it in the PHP userland
		 */
		if (phalcon_is_callable(filter_object TSRMLS_CC)) {
			PHALCON_INIT_VAR(arguments);
			array_init_size(arguments, 1);
			phalcon_array_append(&arguments, value, 0);
			PHALCON_CALL_USER_FUNC_ARRAY(return_value, filter_object, arguments);
			RETURN_MM();
		}

		if (instanceof_function(Z_OBJCE_P(filter_object), zend_ce_closure TSRMLS_CC)) {
			PHALCON_INIT_VAR(arguments);
			array_init_size(arguments, 1);
			phalcon_array_append(&arguments, value, 0);
			PHALCON_CALL_USER_FUNC_ARRAY(return_value, filter_object, arguments);
			RETURN_MM();
		}
	
		PHALCON_RETURN_CALL_METHOD(filter_object, "filter", value);
		RETURN_MM();
	}
	
	
	if (PHALCON_IS_STRING(filter, "email")) {
		/** 
		 * The 'email' filter uses the filter extension
		 */
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 517); /* FILTER_SANITIZE_EMAIL */
	
		PHALCON_INIT_VAR(quote);
		ZVAL_STRING(quote, "'", 1);
	
		PHALCON_INIT_VAR(empty_str);
		ZVAL_STRING(empty_str, "", 1);
	
		PHALCON_INIT_VAR(escaped);
		phalcon_fast_str_replace(escaped, quote, empty_str, value);
	
		PHALCON_CALL_FUNCTION(&filtered, "filter_var", escaped, type);
		goto ph_end_0;
	}
	
	if (PHALCON_IS_STRING(filter, "int")) {
		/** 
		 * 'int' filter sanitizes a numeric input
		 */
		PHALCON_INIT_NVAR(type);
		ZVAL_LONG(type, 519); /* FILTER_SANITIZE_NUMBER_INT */
	
		PHALCON_CALL_FUNCTION(&filtered, "filter_var", value, type);
		goto ph_end_0;
	}
	
	if (PHALCON_IS_STRING(filter, "string")) {
		PHALCON_INIT_NVAR(type);
		ZVAL_LONG(type, 513); /* FILTER_SANITIZE_STRING */
	
		PHALCON_CALL_FUNCTION(&filtered, "filter_var", value, type);
		goto ph_end_0;
	}
	
	if (PHALCON_IS_STRING(filter, "float")) {
		/** 
		 * The 'float' filter uses the filter extension
		 */
		PHALCON_INIT_VAR(allow_fraction);
		ZVAL_LONG(allow_fraction, 4096);
	
		PHALCON_INIT_VAR(options);
		array_init_size(options, 1);
		phalcon_array_update_string(&options, SL("flags"), allow_fraction, PH_COPY);
	
		PHALCON_INIT_NVAR(type);
		ZVAL_LONG(type, 520);
	
		PHALCON_CALL_FUNCTION(&filtered, "filter_var", value, type, options);
		goto ph_end_0;
	}
	
	if (PHALCON_IS_STRING(filter, "alphanum")) {
		PHALCON_INIT_NVAR(filtered);
		phalcon_filter_alphanum(filtered, value);
		goto ph_end_0;
	}
	
	if (PHALCON_IS_STRING(filter, "trim")) {
		PHALCON_INIT_NVAR(filtered);
		phalcon_fast_trim(filtered, value, PHALCON_TRIM_BOTH TSRMLS_CC);
		goto ph_end_0;
	}
	
	if (PHALCON_IS_STRING(filter, "striptags")) {
		PHALCON_INIT_NVAR(filtered);
		phalcon_fast_strip_tags(filtered, value);
		goto ph_end_0;
	}
	
	if (PHALCON_IS_STRING(filter, "lower")) {
		if (phalcon_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS) {
			/** 
			 * 'lower' checks for the mbstring extension to make a correct lowercase
			 * transformation
			 */
			PHALCON_CALL_FUNCTION(&filtered, "mb_strtolower", value);
		} else {
			PHALCON_INIT_NVAR(filtered);
			phalcon_fast_strtolower(filtered, value);
		}
		goto ph_end_0;
	}
	
	if (PHALCON_IS_STRING(filter, "upper")) {
		if (phalcon_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS) {
			/** 
			 * 'upper' checks for the mbstring extension to make a correct lowercase
			 * transformation
			 */
			PHALCON_CALL_FUNCTION(&filtered, "mb_strtoupper", value);
		} else {
			PHALCON_INIT_NVAR(filtered);
			phalcon_fast_strtoupper(filtered, value);
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
