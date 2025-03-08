
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Json)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, Json, phalcon, storage_serializer_json, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_json_method_entry, 0);

	/**
	 * @var Decode
	 */
	zend_declare_property_null(phalcon_storage_serializer_json_ce, SL("decode"), ZEND_ACC_PRIVATE);
	/**
	 * @var Encode
	 */
	zend_declare_property_null(phalcon_storage_serializer_json_ce, SL("encode"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * AbstractSerializer constructor.
 *
 * @param mixed|null $data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Json, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_helper_json_encode_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("encode"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_support_helper_json_decode_ce);
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("decode"), &_1);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_serializer_json_ce, getThis(), "__construct", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Serializes data
 *
 * @return JsonSerializable|mixed|string
 */
PHP_METHOD(Phalcon_Storage_Serializer_Json, serialize)
{
	zval _4$$3;
	zend_bool _1;
	zval _0, _2, _5, _6, _7, _8, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	_1 = Z_TYPE_P(&_0) == IS_OBJECT;
	if (_1) {
		zephir_memory_observe(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
		_1 = !(zephir_is_instance_of(&_2, SL("JsonSerializable")));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SS(&_4$$3, "Data for the JSON serializer cannot be of type 'object' ", "without implementing 'JsonSerializable'");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 201, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Storage/Serializer/Json.zep", 54);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "isserializable", NULL, 0, &_6);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_5)) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("encode"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_7, "__invoke", NULL, 0, &_8);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserializes data
 *
 * @param mixed $data
 *
 * @return void
 */
PHP_METHOD(Phalcon_Storage_Serializer_Json, unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_sub, _0, _1$$4, _2$$4;
	zval *data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, data);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
	} else {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("decode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "__invoke", NULL, 0, data);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_2$$4);
	}
	ZEPHIR_MM_RESTORE();
}

