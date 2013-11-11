
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
ZEPHIR_INIT_CLASS(Phalcon_Filter) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Filter, phalcon, filter, phalcon_filter_method_entry, 0);

	zend_declare_property_null(phalcon_filter_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_filter_ce TSRMLS_CC, 1, phalcon_filterinterface_ce);

	return SUCCESS;

}

/**
 * Adds a user-defined filter
 *
 * @param string name
 * @param callable handler
 * @return Phalcon\Filter
 */
PHP_METHOD(Phalcon_Filter, add) {

	zval *name_param = NULL, *handler;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &handler);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	if ((Z_TYPE_P(handler) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_filter_exception_ce, "Filter must be an object");
		return;
	}
	zephir_update_property_array(this_ptr, SL("_filters"), name, handler TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sanitizes a value with a specified single or set of filters
 *
 * @param  value
 * @param  filters
 * @param  noRecursive
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize) {

	zend_function *_7 = NULL, *_8 = NULL, *_12 = NULL;
	HashTable *_1, *_4, *_10;
	HashPosition _0, _3, _9;
	zend_bool noRecursive;
	zval *value, *filters, *noRecursive_param = NULL, *filter = NULL, *arrayValue = NULL, *itemKey = NULL, *itemValue = NULL, *sanitizedValue, **_2, **_5, *_6 = NULL, **_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &value, &filters, &noRecursive_param);

	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if ((Z_TYPE_P(filters) == IS_ARRAY)) {
		if ((Z_TYPE_P(value) != IS_NULL)) {
			zephir_is_iterable(filters, &_1, &_0, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
				; zend_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HVALUE(filter, _2);
				if (((Z_TYPE_P(value) == IS_ARRAY) && !noRecursive)) {
					ZEPHIR_INIT_NVAR(arrayValue);
					array_init(arrayValue);
					zephir_is_iterable(value, &_4, &_3, 0, 0);
					for (
						; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
						; zend_hash_move_forward_ex(_4, &_3)
					) {
						ZEPHIR_GET_HMKEY(itemKey, _4, _3);
						ZEPHIR_GET_HVALUE(itemValue, _5);
						ZEPHIR_INIT_NVAR(_6);
						zephir_call_method_p2_cache(_6, this_ptr, "_sanitize", &_7, itemValue, filter);
						zephir_array_update_zval(&arrayValue, itemKey, &_6, PH_COPY | PH_SEPARATE);
					}
					RETURN_CCTOR(arrayValue);
				}
				zephir_call_method_p2_cache(return_value, this_ptr, "_sanitize", &_8, value, filter);
				RETURN_MM();
			}
		}
		RETURN_MM_NULL();
	}
	if ((Z_TYPE_P(value) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(sanitizedValue);
		array_init(sanitizedValue);
		zephir_is_iterable(value, &_10, &_9, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
			; zend_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HMKEY(itemKey, _10, _9);
			ZEPHIR_GET_HVALUE(itemValue, _11);
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_method_p2_cache(_6, this_ptr, "_sanitize", &_12, itemValue, filters);
			zephir_array_update_zval(&sanitizedValue, itemKey, &_6, PH_COPY | PH_SEPARATE);
		}
		RETURN_CCTOR(sanitizedValue);
	}
	zephir_call_method_p2(return_value, this_ptr, "_sanitize", value, filters);
	RETURN_MM();

}

/**
 * Internal sanitize wrapper to filter_var
 *
 * @param  mixed $value
 * @param  string $filter
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize) {

	zval *filter = NULL;
	zval *value, *filter_param = NULL, *filterObject, *_0, *_1 = NULL, _2 = zval_used_for_init, _3, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filter_param);

		if (Z_TYPE_P(filter_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filter' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		filter = filter_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&filterObject, _0, filter, 1 TSRMLS_CC)) {
		if (zephir_is_instance_of(filterObject, SL("Closure") TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_array_fast_append(_1, value);
			zephir_call_func_p2(return_value, "call_user_func_array", filterObject, _1);
			RETURN_MM();
		}
		zephir_call_method_p1(return_value, filterObject, "filter", value);
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(filter, "email")) {
			ZEPHIR_SINIT_VAR(_2);
			ZVAL_STRING(&_2, "'", 0);
			ZEPHIR_SINIT_VAR(_3);
			ZVAL_STRING(&_3, "", 0);
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_func_p3(_1, "str_replace", &_2, &_3, value);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 517);
			zephir_call_func_p2(return_value, "filter_var", _1, &_2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "int")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 519);
			zephir_call_func_p2(return_value, "filter_var", value, &_2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "string")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 513);
			zephir_call_func_p2(return_value, "filter_var", value, &_2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "float")) {
			ZEPHIR_INIT_VAR(_4);
			array_init(_4);
			add_assoc_long_ex(_4, SS("flags"), 4096);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 520);
			zephir_call_func_p3(return_value, "filter_var", value, &_2, _4);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "alphanum")) {
			zephir_call_func_p1(return_value, "phalcon_filter_alphanum", value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "trim")) {
			zephir_call_func_p1(return_value, "trim", value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "striptags")) {
			zephir_call_func_p1(return_value, "strip_tags", value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "lower")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "mb_strtolower", 0);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_func_p1(_4, "function_exists", &_2);
			if (zephir_is_true(_4)) {
				zephir_call_func_p1(return_value, "mb_strtolower", value);
				RETURN_MM();
			}
			zephir_fast_strtolower(return_value, value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "upper")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "mb_strtoupper", 0);
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_func_p1(_1, "function_exists", &_2);
			if (zephir_is_true(_1)) {
				zephir_call_func_p1(return_value, "mb_strtoupper", value);
				RETURN_MM();
			}
			zephir_call_func_p1(return_value, "strtoupper", value);
			RETURN_MM();
		}
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_filter_exception_ce);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "Sanitize filter '", filter, "' is not supported");
		zephir_call_method_p1_noret(_1, "__construct", _5);
		zephir_throw_exception(_1 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Return the user-defined filters in the instance
 *
 * @return object[]
 */
PHP_METHOD(Phalcon_Filter, getFilters) {


	RETURN_MEMBER(this_ptr, "_filters");

}

