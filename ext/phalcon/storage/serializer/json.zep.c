
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, Json, phalcon, storage_serializer_json, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_json_method_entry, 0);

	return SUCCESS;

}

/**
 * Serializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Json, serialize) {

	zend_bool _1;
	zval _0, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC);
	_1 = Z_TYPE_P(&_0) == IS_OBJECT;
	if (_1) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, SL("data"), PH_NOISY_CC);
		_1 = !(zephir_is_instance_of(&_2, SL("JsonSerializable")));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data for JSON serializer cannot be of type object without implementing JsonSerializable", "phalcon/Storage/Serializer/Json.zep", 26);
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "isserializable", NULL, 0, &_4);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	zephir_read_property(&_5, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_json_encode(return_value, &_5, 0 );
	RETURN_MM();

}

/**
 * Unserializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Json, unserialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&_0);
	zephir_json_decode(&_0, data, 0 );
	zephir_update_property_zval(this_ptr, SL("data"), &_0);
	ZEPHIR_MM_RESTORE();

}

