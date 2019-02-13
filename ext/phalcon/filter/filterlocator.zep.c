
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\TagLocator
 *
 * Lazy loads, stores and exposes sanitizer objects
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterLocator) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter, FilterLocator, phalcon, filter_filterlocator, phalcon_service_locator_ce, phalcon_filter_filterlocator_method_entry, 0);

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_ABSINT"), "absint");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_ALNUM"), "alnum");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_ALPHA"), "alpha");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_BOOL"), "bool");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_EMAIL"), "email");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_FLOAT"), "float");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_INT"), "int");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_LOWER"), "lower");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_LOWERFIRST"), "lowerFirst");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_REGEX"), "regex");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_REMOVE"), "remove");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_REPLACE"), "replace");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_SPECIAL"), "special");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_SPECIALFULL"), "specialFull");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_STRING"), "string");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_STRIPTAGS"), "striptags");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_TRIM"), "trim");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_UPPER"), "upper");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_UPPERFIRST"), "upperFirst");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_UPPERWORDS"), "upperWords");

	zephir_declare_class_constant_string(phalcon_filter_filterlocator_ce, SL("FILTER_URL"), "url");

	return SUCCESS;

}

/**
 * Sanitizes a value with a specified single or set of sanitizers
 */
PHP_METHOD(Phalcon_Filter_FilterLocator, sanitize) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool noRecursive, _8, _3$$5;
	zval *value = NULL, value_sub, *sanitizers, sanitizers_sub, *noRecursive_param = NULL, sanitizer, sanitizerKey, sanitizerName, sanitizerParams, *_0$$3, _4$$8, _6$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizers_sub);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&sanitizerKey);
	ZVAL_UNDEF(&sanitizerName);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &value, &sanitizers, &noRecursive_param);

	ZEPHIR_SEPARATE_PARAM(value);
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (Z_TYPE_P(sanitizers) == IS_ARRAY) {
		if (Z_TYPE_P(value) == IS_NULL) {
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
		zephir_is_iterable(sanitizers, 0, "phalcon/filter/filterlocator.zep", 119);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(sanitizers), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&sanitizerKey);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&sanitizerKey, _2$$3);
			} else {
				ZVAL_LONG(&sanitizerKey, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&sanitizer);
			ZVAL_COPY(&sanitizer, _0$$3);
			if (Z_TYPE_P(&sanitizer) == IS_ARRAY) {
				ZEPHIR_CPY_WRT(&sanitizerName, &sanitizerKey);
				ZEPHIR_CPY_WRT(&sanitizerParams, &sanitizer);
			} else {
				ZEPHIR_CPY_WRT(&sanitizerName, &sanitizer);
				ZEPHIR_INIT_NVAR(&sanitizerParams);
				array_init(&sanitizerParams);
			}
			_3$$5 = Z_TYPE_P(value) == IS_ARRAY;
			if (_3$$5) {
				_3$$5 = !noRecursive;
			}
			if (_3$$5) {
				ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "processarrayvalues", &_5, 198, value, &sanitizerName, &sanitizerParams);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, &_4$$8);
			} else {
				ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "sanitizer", &_7, 199, value, &sanitizerName, &sanitizerParams);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, &_6$$9);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&sanitizer);
		ZEPHIR_INIT_NVAR(&sanitizerKey);
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	_8 = Z_TYPE_P(value) == IS_ARRAY;
	if (_8) {
		_8 = !noRecursive;
	}
	if (_8) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processarrayvalues", &_5, 198, value, sanitizers);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sanitizer", &_7, 199, value, sanitizers);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Filter_FilterLocator, processArrayValues) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sanitizerName;
	zval *values_param = NULL, *sanitizerName_param = NULL, *sanitizerParams_param = NULL, arrayValue, itemKey, itemValue, *_0, _3$$3;
	zval values, sanitizerParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&arrayValue);
	ZVAL_UNDEF(&itemKey);
	ZVAL_UNDEF(&itemValue);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&sanitizerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &values_param, &sanitizerName_param, &sanitizerParams_param);

	zephir_get_arrval(&values, values_param);
	zephir_get_strval(&sanitizerName, sanitizerName_param);
	if (!sanitizerParams_param) {
		ZEPHIR_INIT_VAR(&sanitizerParams);
		array_init(&sanitizerParams);
	} else {
		zephir_get_arrval(&sanitizerParams, sanitizerParams_param);
	}


	ZEPHIR_INIT_VAR(&arrayValue);
	array_init(&arrayValue);
	zephir_is_iterable(&values, 0, "phalcon/filter/filterlocator.zep", 144);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&itemKey);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&itemKey, _2);
		} else {
			ZVAL_LONG(&itemKey, _1);
		}
		ZEPHIR_INIT_NVAR(&itemValue);
		ZVAL_COPY(&itemValue, _0);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "sanitizer", &_4, 199, &itemValue, &sanitizerName, &sanitizerParams);
		zephir_check_call_status();
		zephir_array_update_zval(&arrayValue, &itemKey, &_3$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&itemValue);
	ZEPHIR_INIT_NVAR(&itemKey);
	RETURN_CCTOR(&arrayValue);

}

/**
 * Internal sanitize wrapper for recursion
 */
PHP_METHOD(Phalcon_Filter_FilterLocator, sanitizer) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sanitizerParams, _1$$3;
	zval sanitizerName;
	zval *value, value_sub, *sanitizerName_param = NULL, *sanitizerParams_param = NULL, sanitizerObject, params, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizerObject);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&sanitizerName);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &value, &sanitizerName_param, &sanitizerParams_param);

	if (UNEXPECTED(Z_TYPE_P(sanitizerName_param) != IS_STRING && Z_TYPE_P(sanitizerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sanitizerName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sanitizerName_param) == IS_STRING)) {
		zephir_get_strval(&sanitizerName, sanitizerName_param);
	} else {
		ZEPHIR_INIT_VAR(&sanitizerName);
		ZVAL_EMPTY_STRING(&sanitizerName);
	}
	if (!sanitizerParams_param) {
		ZEPHIR_INIT_VAR(&sanitizerParams);
		array_init(&sanitizerParams);
	} else {
		zephir_get_arrval(&sanitizerParams, sanitizerParams_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &sanitizerName);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD(&sanitizerObject, this_ptr, "get", NULL, 0, &sanitizerName);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$3, value);
		ZEPHIR_INIT_VAR(&params);
		zephir_fast_array_merge(&params, &_1$$3, &sanitizerParams TSRMLS_CC);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &sanitizerObject, &params);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

