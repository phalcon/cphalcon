
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
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, Json, phalcon, storage_serializer_json, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_json_method_entry, 0);

	return SUCCESS;

}

/**
 * Serializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Json, serialize) {

	zval _4$$3;
	zend_bool _1;
	zval _0, _2, _5, _6, _8, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

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
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SS(&_4$$3, "Data for the JSON serializer cannot be of type 'object' ", "without implementing 'JsonSerializable'");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 39, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Storage/Serializer/Json.zep", 28);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "isserializable", NULL, 0, &_6);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	zephir_read_property(&_8, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_json_ce, "encode", &_7, 13, &_8);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Json, unserialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_json_ce, "decode", &_1, 167, data);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("data"), &_0);
	ZEPHIR_MM_RESTORE();

}

