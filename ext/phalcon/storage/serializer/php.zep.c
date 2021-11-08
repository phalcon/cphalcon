
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
	if (!(zephir_is_true(&_0))) {
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processserializable", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processnotserializable", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, processSerializable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, __$false, __$null, version, _0, _1$$3, _2$$3, _3$$3, _8$$3, _4$$5, _5$$5, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
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
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		if (Z_TYPE_P(data) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data for the unserializer must of type string", "phalcon/Storage/Serializer/Php.zep", 54);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 89);
		zephir_check_call_status();
		ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "8.0");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, ">=");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "version_compare", NULL, 90, &version, &_1$$3, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_INIT_NVAR(&_4$$5);
			zephir_create_closure_ex(&_4$$5, NULL, phalcon_12__closure_ce, SL("__invoke"));
			ZVAL_LONG(&_5$$5, 8);
			ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 91, &_4$$5, &_5$$5);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_INIT_NVAR(&_6$$6);
			zephir_create_closure_ex(&_6$$6, NULL, phalcon_13__closure_ce, SL("__invoke"));
			ZVAL_LONG(&_7$$6, 8);
			ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 91, &_6$$6, &_7$$6);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(&_8$$3, "unserialize", NULL, 17, data);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_8$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 93);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_GLOBAL(warning).enable)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &__$null);
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, processNotSerializable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
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
	}
	ZEPHIR_MM_RESTORE();
}

