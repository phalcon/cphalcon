
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
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
 *	$filter = new \Phalcon\Filter();
 *	$filter->sanitize("some(one)@exa\\mple.com", "email"); // returns "someone@example.com"
 *	$filter->sanitize("hello<<", "string"); // returns "hello"
 *	$filter->sanitize("!100a019", "int"); // returns "100019"
 *	$filter->sanitize("!100a019.01a", "float"); // returns "100019.01"
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Filter, phalcon, filter, phalcon_filter_method_entry, 0);

	zend_declare_property_null(phalcon_filter_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_EMAIL"), "email" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ABSINT"), "absint" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT"), "int" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT_CAST"), "int!" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRING"), "string" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT"), "float" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT_CAST"), "float!" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ALPHANUM"), "alphanum" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_TRIM"), "trim" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRIPTAGS"), "striptags" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_LOWER"), "lower" TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_UPPER"), "upper" TSRMLS_CC);

	zend_class_implements(phalcon_filter_ce TSRMLS_CC, 1, phalcon_filterinterface_ce);
	return SUCCESS;

}

/**
 * Adds a user-defined filter
 */
PHP_METHOD(Phalcon_Filter, add) {

	zend_bool _0;
	zval *name_param = NULL, *handler;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &handler);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = Z_TYPE_P(handler) != IS_OBJECT;
	if (_0) {
		_0 = !(zephir_is_callable(handler TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_exception_ce, "Filter must be an object or callable", "phalcon/filter.zep", 74);
		return;
	}
	zephir_update_property_array(this_ptr, SL("_filters"), name, handler TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sanitizes a value with a specified single or set of filters
 */
PHP_METHOD(Phalcon_Filter, sanitize) {

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_5, *_10;
	HashPosition _0, _4, _9;
	zend_bool noRecursive, _3;
	zval *value = NULL, *filters, *noRecursive_param = NULL, *filter = NULL, *arrayValue = NULL, *itemKey = NULL, *itemValue = NULL, *sanitizedValue, **_2, **_6, *_7 = NULL, **_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &value, &filters, &noRecursive_param);

	ZEPHIR_SEPARATE_PARAM(value);
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (Z_TYPE_P(filters) == IS_ARRAY) {
		if (Z_TYPE_P(value) != IS_NULL) {
			zephir_is_iterable(filters, &_1, &_0, 0, 0, "phalcon/filter.zep", 107);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HVALUE(filter, _2);
				_3 = Z_TYPE_P(value) == IS_ARRAY;
				if (_3) {
					_3 = !noRecursive;
				}
				if (_3) {
					ZEPHIR_INIT_NVAR(arrayValue);
					array_init(arrayValue);
					zephir_is_iterable(value, &_5, &_4, 0, 0, "phalcon/filter.zep", 102);
					for (
					  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
					  ; zephir_hash_move_forward_ex(_5, &_4)
					) {
						ZEPHIR_GET_HMKEY(itemKey, _5, _4);
						ZEPHIR_GET_HVALUE(itemValue, _6);
						ZEPHIR_CALL_METHOD(&_7, this_ptr, "_sanitize", &_8, 0, itemValue, filter);
						zephir_check_call_status();
						zephir_array_update_zval(&arrayValue, itemKey, &_7, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_CPY_WRT(value, arrayValue);
				} else {
					ZEPHIR_CALL_METHOD(&_7, this_ptr, "_sanitize", &_8, 0, value, filter);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(value, _7);
				}
			}
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	_3 = Z_TYPE_P(value) == IS_ARRAY;
	if (_3) {
		_3 = !noRecursive;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(sanitizedValue);
		array_init(sanitizedValue);
		zephir_is_iterable(value, &_10, &_9, 0, 0, "phalcon/filter.zep", 119);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HMKEY(itemKey, _10, _9);
			ZEPHIR_GET_HVALUE(itemValue, _11);
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "_sanitize", &_8, 0, itemValue, filters);
			zephir_check_call_status();
			zephir_array_update_zval(&sanitizedValue, itemKey, &_7, PH_COPY | PH_SEPARATE);
		}
		RETURN_CCTOR(sanitizedValue);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_sanitize", &_8, 0, value, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Internal sanitize wrapper to filter_var
 */
PHP_METHOD(Phalcon_Filter, _sanitize) {

	zephir_fcall_cache_entry *_8 = NULL;
	zval *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1;
	zval *filter = NULL, *_10;
	zval *value, *filter_param = NULL, *filterObject, *_0, *_3 = NULL, _4 = zval_used_for_init, _5, _6, *_7 = NULL, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filter_param);

	if (unlikely(Z_TYPE_P(filter_param) != IS_STRING && Z_TYPE_P(filter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filter_param) == IS_STRING)) {
		zephir_get_strval(filter, filter_param);
	} else {
		ZEPHIR_INIT_VAR(filter);
		ZVAL_EMPTY_STRING(filter);
	}


	ZEPHIR_OBS_VAR(filterObject);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&filterObject, _0, filter, 0 TSRMLS_CC)) {
		_1 = zephir_instance_of_ev(filterObject, zend_ce_closure TSRMLS_CC);
		if (!(_1)) {
			_1 = zephir_is_callable(filterObject TSRMLS_CC);
		}
		if (_1) {
			ZEPHIR_INIT_VAR(_2);
			zephir_create_array(_2, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_2, value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, filterObject, _2);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(filterObject, "filter", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(filter, "email")) {
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_SINIT_VAR(_4);
			ZVAL_STRING(&_4, "'", 0);
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_STRING(&_5, "", 0);
			zephir_fast_str_replace(&_3, &_4, &_5, value TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_6);
			ZVAL_STRING(&_6, "FILTER_SANITIZE_EMAIL", 0);
			ZEPHIR_CALL_FUNCTION(&_7, "constant", NULL, 164, &_6);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_8, 165, _3, _7);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "int")) {
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, 519);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_8, 165, value, &_4);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "int!")) {
			RETURN_MM_LONG(zephir_get_intval(value));
		}
		if (ZEPHIR_IS_STRING(filter, "absint")) {
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, zephir_get_intval(value));
			ZEPHIR_RETURN_CALL_FUNCTION("abs", NULL, 166, &_4);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "string")) {
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, 513);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_8, 165, value, &_4);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "float")) {
			ZEPHIR_INIT_NVAR(_2);
			zephir_create_array(_2, 1, 0 TSRMLS_CC);
			add_assoc_long_ex(_2, SS("flags"), 4096);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, 520);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_8, 165, value, &_4, _2);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "float!")) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(value));
		}
		if (ZEPHIR_IS_STRING(filter, "alphanum")) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "/[^A-Za-z0-9]/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_9);
			ZVAL_STRING(_9, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 82, _3, _9, value);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "trim")) {
			zephir_fast_trim(return_value, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "striptags")) {
			ZEPHIR_RETURN_CALL_FUNCTION("strip_tags", NULL, 167, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "lower")) {
			if ((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 168, value);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_fast_strtolower(return_value, value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "upper")) {
			if ((zephir_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 169, value);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_fast_strtoupper(return_value, value);
			RETURN_MM();
		}
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, phalcon_filter_exception_ce);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_SVS(_10, "Sanitize filter '", filter, "' is not supported");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 2, _10);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalcon/filter.zep", 213 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Return the user-defined filters in the instance
 */
PHP_METHOD(Phalcon_Filter, getFilters) {


	RETURN_MEMBER(this_ptr, "_filters");

}

