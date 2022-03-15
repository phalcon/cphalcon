
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


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

	return SUCCESS;
}

/**
 * Serializes data
 *
 * @return string
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


	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 15, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserializes data
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, unserialize)
{
	zend_bool _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, __$false, __$true, result, version, _0, _1$$4, _2$$4, _3$$4, _4$$6, _5$$6, _6$$7, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, data);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
	} else {
		if (Z_TYPE_P(data) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data for the unserializer must of type string", "phalcon/Storage/Serializer/Php.zep", 46);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 87);
		zephir_check_call_status();
		ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "8.0");
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, ">=");
		ZEPHIR_CALL_FUNCTION(&_3$$4, "version_compare", NULL, 88, &version, &_1$$4, &_2$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$4)) {
			ZEPHIR_INIT_VAR(&_4$$6);
			ZEPHIR_INIT_NVAR(&_4$$6);
			zephir_create_closure_ex(&_4$$6, NULL, phalcon_13__closure_ce, SL("__invoke"));
			ZVAL_LONG(&_5$$6, 8);
			ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 89, &_4$$6, &_5$$6);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_6$$7);
			ZEPHIR_INIT_NVAR(&_6$$7);
			zephir_create_closure_ex(&_6$$7, NULL, phalcon_14__closure_ce, SL("__invoke"));
			ZVAL_LONG(&_7$$7, 8);
			ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 89, &_6$$7, &_7$$7);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&result, this_ptr, "phpunserialize", NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 91);
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
 * @param string $data
 * @param array  $options
 *
 * @return mixed|false
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, phpUnserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *data_param = NULL, *options_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &options_param);
	zephir_get_strval(&data, data_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 16, &data, &options);
	zephir_check_call_status();
	RETURN_MM();
}

