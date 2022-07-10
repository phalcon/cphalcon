
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
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
/**
 * @property mixed $data
 * @property bool  $isSuccess
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_AbstractSerializer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Storage\\Serializer, AbstractSerializer, phalcon, storage_serializer_abstractserializer, phalcon_storage_serializer_abstractserializer_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_storage_serializer_abstractserializer_ce, SL("data"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_storage_serializer_abstractserializer_ce, SL("isSuccess"), 1, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_storage_serializer_abstractserializer_ce, 1, phalcon_storage_serializer_serializerinterface_ce);
	return SUCCESS;
}

/**
 * AbstractSerializer constructor.
 *
 * @param mixed|null $data
 */
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Serialize data
 */
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, __serialize)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	array_init(return_value);
	RETURN_MM();
}

/**
 * Unserialize data
 */
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, __unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, getData)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "data");
}

/**
 * Returns `true` if the serialize/unserialize operation was successful;
 * `false` otherwise
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, isSuccess)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "isSuccess");
}

/**
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, setData)
{
	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &data);


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
}

/**
 * If this returns true, then the data is returned as is
 *
 * @param mixed $data
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, isSerializable)
{
	zend_bool _0, _1;
	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &data);


	_0 = Z_TYPE_P(data) == IS_NULL;
	if (!(_0)) {
		_0 = 1 == (Z_TYPE_P(data) == IS_TRUE || Z_TYPE_P(data) == IS_FALSE);
	}
	_1 = _0;
	if (!(_1)) {
		_1 = 1 == zephir_is_numeric(data);
	}
	RETURN_BOOL(!(_1));
}

