
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
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_AbstractSerializer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Storage\\Serializer, AbstractSerializer, phalcon, storage_serializer_abstractserializer, phalcon_storage_serializer_abstractserializer_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_storage_serializer_abstractserializer_ce, SL("data"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_storage_serializer_abstractserializer_ce, 1, phalcon_storage_serializer_serializerinterface_ce);
	return SUCCESS;
}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, __construct)
{
	zval *data = NULL, data_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &data);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
}

/**
 * If this returns true, then the data returns back as is
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


	_0 = ZEPHIR_IS_EMPTY(data);
	if (!(_0)) {
		_0 = ((Z_TYPE_P(data) == IS_TRUE || Z_TYPE_P(data) == IS_FALSE) == 1);
	}
	_1 = _0;
	if (!(_1)) {
		_1 = zephir_is_numeric(data);
	}
	RETURN_BOOL(!(_1));
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

