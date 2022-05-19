
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Igbinary)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, Igbinary, phalcon, storage_serializer_igbinary, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_igbinary_method_entry, 0);

	return SUCCESS;
}

/**
 * Serializes data
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Serializer_Igbinary, serialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, result, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "doserialize", NULL, 0, &_2);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&result) == IS_NULL)) {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isSuccess"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isSuccess"), &__$false);
		}
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_STRING(&result, "");
	}
	RETURN_CCTOR(&result);
}

/**
 * Unserializes data
 *
 * @param string $data
 *
 * @return void
 */
PHP_METHOD(Phalcon_Storage_Serializer_Igbinary, unserialize)
{
	zend_bool _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, __$false, __$true, result, version, _0, _1$$4, _2$$4, _3$$4, _4$$5, _5$$5, _6$$6, _7$$6;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_strval(&data, data_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, &data);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	} else {
		ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 127);
		zephir_check_call_status();
		ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "8.0");
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, ">=");
		ZEPHIR_CALL_FUNCTION(&_3$$4, "version_compare", NULL, 128, &version, &_1$$4, &_2$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$4)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_INIT_NVAR(&_4$$5);
			zephir_create_closure_ex(&_4$$5, NULL, phalcon_3__closure_ce, SL("__invoke"));
			ZVAL_LONG(&_5$$5, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 129, &_4$$5, &_5$$5);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_INIT_NVAR(&_6$$6);
			zephir_create_closure_ex(&_6$$6, NULL, phalcon_4__closure_ce, SL("__invoke"));
			ZVAL_LONG(&_7$$6, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 129, &_6$$6, &_7$$6);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dounserialize", NULL, 0, &data);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 130);
		zephir_check_call_status();
		_8$$4 = ZEPHIR_GLOBAL(warning).enable;
		if (!(_8$$4)) {
			_8$$4 = ZEPHIR_IS_FALSE_IDENTICAL(&result);
		}
		if (UNEXPECTED(_8$$4)) {
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("isSuccess"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("isSuccess"), &__$false);
			}
			ZEPHIR_INIT_NVAR(&result);
			ZVAL_STRING(&result, "");
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &result);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Wrapper for `igbinary_serialize`
 *
 * @param mixed $value
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Storage_Serializer_Igbinary, phpIgbinarySerialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);


	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_serialize", NULL, 135, value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Serialize
 *
 * @param mixed $value
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Storage_Serializer_Igbinary, doSerialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpigbinaryserialize", NULL, 0, value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserialize
 *
 * @param string $value
 *
 * @return mixed|false
 */
PHP_METHOD(Phalcon_Storage_Serializer_Igbinary, doUnserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);


	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_unserialize", NULL, 136, value);
	zephir_check_call_status();
	RETURN_MM();
}

