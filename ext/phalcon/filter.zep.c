
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Lazy loads, stores and exposes sanitizer objects
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Filter, phalcon, filter, phalcon_filter_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_ce, SL("mapper"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_ce, SL("services"), ZEND_ACC_PROTECTED);

	phalcon_filter_ce->create_object = zephir_init_properties_Phalcon_Filter;
	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ABSINT"), "absint");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ALNUM"), "alnum");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ALPHA"), "alpha");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_BOOL"), "bool");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_EMAIL"), "email");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT"), "float");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT"), "int");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_LOWER"), "lower");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_LOWERFIRST"), "lowerFirst");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_REGEX"), "regex");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_REMOVE"), "remove");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_REPLACE"), "replace");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_SPECIAL"), "special");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_SPECIALFULL"), "specialFull");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRING"), "string");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRIPTAGS"), "striptags");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_TRIM"), "trim");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_UPPER"), "upper");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_UPPERFIRST"), "upperFirst");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_UPPERWORDS"), "upperWords");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_URL"), "url");

	zend_class_implements(phalcon_filter_ce, 1, phalcon_filter_filterinterface_ce);
	return SUCCESS;

}

/**
 * Key value pairs with name as the key and a callable as the value for
 * the service object
 */
PHP_METHOD(Phalcon_Filter, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mapper_param = NULL;
	zval mapper;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mapper);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mapper_param);

	if (!mapper_param) {
		ZEPHIR_INIT_VAR(&mapper);
		array_init(&mapper);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&mapper, mapper_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &mapper);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a service. If it is not in the mapper array, create a new object,
 * set it and then return it.
 */
PHP_METHOD(Phalcon_Filter, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition, _0, _3, _6, _7, _1$$3, _4$$4, _5$$5;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset(&_0, &name)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_filter_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "The service ", &name, " has not been found in the locator");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 6, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Filter.zep", 74);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &name))) {
		zephir_read_property(&_4$$4, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&definition);
		zephir_array_fetch(&definition, &_4$$4, &name, PH_NOISY, "phalcon/Filter.zep", 78);
		if (Z_TYPE_P(&definition) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_5$$5, &definition);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("services"), &name, &_5$$5);
		} else {
			zephir_update_property_array(this_ptr, SL("services"), &name, &definition);
		}
	}
	zephir_read_property(&_6, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_7, &_6, &name, PH_NOISY | PH_READONLY, "phalcon/Filter.zep", 86);
	RETURN_CTOR(&_7);

}

/**
 * Checks if a service exists in the map array
 */
PHP_METHOD(Phalcon_Filter, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * Sanitizes a value with a specified single or set of sanitizers
 */
PHP_METHOD(Phalcon_Filter, sanitize) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool noRecursive, _12, _4$$5, _9$$10;
	zval *value = NULL, value_sub, *sanitizers, sanitizers_sub, *noRecursive_param = NULL, sanitizer, sanitizerKey, sanitizerName, sanitizerParams, *_0$$3, _1$$3, _5$$8, _7$$9, _10$$13, _11$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizers_sub);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&sanitizerKey);
	ZVAL_UNDEF(&sanitizerName);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$14);

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
		zephir_is_iterable(sanitizers, 0, "phalcon/Filter.zep", 180);
		if (Z_TYPE_P(sanitizers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(sanitizers), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&sanitizerKey);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&sanitizerKey, _3$$3);
				} else {
					ZVAL_LONG(&sanitizerKey, _2$$3);
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
				_4$$5 = Z_TYPE_P(value) == IS_ARRAY;
				if (_4$$5) {
					_4$$5 = !noRecursive;
				}
				if (_4$$5) {
					ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "processarrayvalues", &_6, 228, value, &sanitizerName, &sanitizerParams);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(value, &_5$$8);
				} else {
					ZEPHIR_CALL_METHOD(&_7$$9, this_ptr, "sanitizer", &_8, 229, value, &sanitizerName, &sanitizerParams);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(value, &_7$$9);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, sanitizers, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, sanitizers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&sanitizerKey, sanitizers, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&sanitizer, sanitizers, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&sanitizer) == IS_ARRAY) {
						ZEPHIR_CPY_WRT(&sanitizerName, &sanitizerKey);
						ZEPHIR_CPY_WRT(&sanitizerParams, &sanitizer);
					} else {
						ZEPHIR_CPY_WRT(&sanitizerName, &sanitizer);
						ZEPHIR_INIT_NVAR(&sanitizerParams);
						array_init(&sanitizerParams);
					}
					_9$$10 = Z_TYPE_P(value) == IS_ARRAY;
					if (_9$$10) {
						_9$$10 = !noRecursive;
					}
					if (_9$$10) {
						ZEPHIR_CALL_METHOD(&_10$$13, this_ptr, "processarrayvalues", &_6, 228, value, &sanitizerName, &sanitizerParams);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(value, &_10$$13);
					} else {
						ZEPHIR_CALL_METHOD(&_11$$14, this_ptr, "sanitizer", &_8, 229, value, &sanitizerName, &sanitizerParams);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(value, &_11$$14);
					}
				ZEPHIR_CALL_METHOD(NULL, sanitizers, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&sanitizer);
		ZEPHIR_INIT_NVAR(&sanitizerKey);
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	_12 = Z_TYPE_P(value) == IS_ARRAY;
	if (_12) {
		_12 = !noRecursive;
	}
	if (_12) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processarrayvalues", &_6, 228, value, sanitizers);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sanitizer", &_8, 229, value, sanitizers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set a new service to the mapper array
 */
PHP_METHOD(Phalcon_Filter, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *service, service_sub, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &service);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("mapper"), &name, service);
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Loads the objects in the internal mapper array
 */
PHP_METHOD(Phalcon_Filter, init) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mapper_param = NULL, name, service, *_0, _1;
	zval mapper;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mapper);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mapper_param);

	ZEPHIR_OBS_COPY_OR_DUP(&mapper, mapper_param);


	zephir_is_iterable(&mapper, 0, "phalcon/Filter.zep", 217);
	if (Z_TYPE_P(&mapper) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&mapper), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &name, &service);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &mapper, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &mapper, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &mapper, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, &mapper, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &name, &service);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &mapper, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();

}

/**
 * Processes the array values with the relevant sanitizers
 */
PHP_METHOD(Phalcon_Filter, processArrayValues) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sanitizerName;
	zval *values_param = NULL, *sanitizerName_param = NULL, *sanitizerParams_param = NULL, itemKey, itemValue, *_0, _1, _4$$3, _6$$4;
	zval values, sanitizerParams, arrayValue;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&arrayValue);
	ZVAL_UNDEF(&itemKey);
	ZVAL_UNDEF(&itemValue);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
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
	zephir_is_iterable(&values, 0, "phalcon/Filter.zep", 241);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&itemKey);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&itemKey, _3);
			} else {
				ZVAL_LONG(&itemKey, _2);
			}
			ZEPHIR_INIT_NVAR(&itemValue);
			ZVAL_COPY(&itemValue, _0);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "sanitizer", &_5, 229, &itemValue, &sanitizerName, &sanitizerParams);
			zephir_check_call_status();
			zephir_array_update_zval(&arrayValue, &itemKey, &_4$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&itemKey, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&itemValue, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "sanitizer", &_5, 229, &itemValue, &sanitizerName, &sanitizerParams);
				zephir_check_call_status();
				zephir_array_update_zval(&arrayValue, &itemKey, &_6$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&itemValue);
	ZEPHIR_INIT_NVAR(&itemKey);
	RETURN_CTOR(&arrayValue);

}

/**
 * Internal sanitize wrapper for recursion
 */
PHP_METHOD(Phalcon_Filter, sanitizer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sanitizerParams, _1;
	zval sanitizerName;
	zval *value, value_sub, *sanitizerName_param = NULL, *sanitizerParams_param = NULL, sanitizerObject, params, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizerObject);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&sanitizerName);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &value, &sanitizerName_param, &sanitizerParams_param);

	if (UNEXPECTED(Z_TYPE_P(sanitizerName_param) != IS_STRING && Z_TYPE_P(sanitizerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sanitizerName' must be of the type string"));
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
	if (!(zephir_is_true(&_0))) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&sanitizerObject, this_ptr, "get", NULL, 0, &sanitizerName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_array_fast_append(&_1, value);
	ZEPHIR_INIT_VAR(&params);
	zephir_fast_array_merge(&params, &_1, &sanitizerParams);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &sanitizerObject, &params);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Filter(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("services"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("mapper"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

