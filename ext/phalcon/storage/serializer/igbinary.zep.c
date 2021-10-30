
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
	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_serialize", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, __$false, __$null, version, _0, _1, _2, _7, _3$$3, _4$$3, _5$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);


	ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 87);
	zephir_check_call_status();
	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "8.0");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ">=");
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 88, &version, &_0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_create_closure_ex(&_3$$3, NULL, phalcon_10__closure_ce, SL("__invoke"));
		ZVAL_LONG(&_4$$3, 2);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 89, &_3$$3, &_4$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_INIT_NVAR(&_5$$4);
		zephir_create_closure_ex(&_5$$4, NULL, phalcon_11__closure_ce, SL("__invoke"));
		ZVAL_LONG(&_6$$4, 2);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 89, &_5$$4, &_6$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_7, "igbinary_unserialize", NULL, 0, data);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_7);
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 91);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_GLOBAL(warning).enable)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &__$null);
	}
	ZEPHIR_MM_RESTORE();
}

