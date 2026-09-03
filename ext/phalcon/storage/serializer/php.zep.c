
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Php)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, Php, phalcon, storage_serializer_php, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_php_method_entry, 0);

	/**
	 * Classes that unserialize() may instantiate: true (any class, the PHP
	 * default), false (none) or a list of class names. Stored bytes that
	 * try to build another class are rejected on read.
	 *
	 * @var mixed
	 */
	zend_declare_property_bool(phalcon_storage_serializer_php_ce, SL("allowedClasses"), 1, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @return bool|array<int, string>
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, getAllowedClasses)
{

	RETURN_MEMBER(getThis(), "allowedClasses");
}

/**
 * Serializes data
 *
 * @return bool|float|int|string|null
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, serialize)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1341, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1341, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpserialize", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Restricts the classes that unserialize() may instantiate (see the
 * "allowed_classes" option of unserialize()).
 *
 * @param bool|array<int, string> $allowedClasses
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, setAllowedClasses)
{
	zval *allowedClasses, allowedClasses_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&allowedClasses_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("allowedClasses", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(allowedClasses)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &allowedClasses);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1342, allowedClasses);
	RETURN_THISW();
}

/**
 * Unserializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, unserialize)
{
	zend_bool _7, _8, _9;
	zval _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_sub, __$false, __$true, result, _0, _1, _3, _4, _6, _10, _2$$4;
	zval *data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("allowedClasses", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("isSuccess", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, data);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1341, data);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_gettype(&_1, data);
	if (UNEXPECTED(!ZEPHIR_IS_STRING(&_1, "string"))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_storage_serializer_exceptions_invalidunserializationinput_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Storage/Serializer/Php.zep", 78);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_closure_ex(&_3, NULL, phalcon_100__closure_ce, SL("__invoke"));
	ZVAL_LONG(&_4, (8 | 2));
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 303, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	zephir_memory_observe(&_6);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_1, 1342, PH_NOISY_CC);
	zephir_array_update_string(&_5, SL("allowed_classes"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "phpunserialize", NULL, 0, data, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 304);
	zephir_check_call_status();
	_7 = ZEPHIR_GLOBAL(warning).enable;
	if (!(_7)) {
		_7 = ZEPHIR_IS_FALSE_IDENTICAL(&result);
	}
	_8 = _7;
	if (!(_8)) {
		_9 = Z_TYPE_P(&result) == IS_OBJECT;
		if (_9) {
			ZEPHIR_INIT_VAR(&_10);
			zephir_get_class(&_10, &result, 0);
			_9 = ZEPHIR_IS_STRING_IDENTICAL(&_10, "__PHP_Incomplete_Class");
		}
		_8 = _9;
	}
	if (UNEXPECTED(_8)) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1343, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1343, &__$false);
		}
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_STRING(&result, "");
	} else {
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1343, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1343, &__$false);
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1341, &result);
	ZEPHIR_MM_RESTORE();
}

/**
 * @param mixed $value
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.serialize.php
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, phpSerialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;

	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 22, value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $data
 * @param array  $options
 *
 * @return mixed
 *
 * @link https://php.net/manual/en/function.unserialize.php
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, phpUnserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval data_zv, *options_param = NULL;
	zend_string *data = NULL;

	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 27, &data_zv, &options);
	zephir_check_call_status();
	RETURN_MM();
}

