
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_SerializerFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage, SerializerFactory, phalcon, storage_serializerfactory, phalcon_factory_abstractfactory_ce, phalcon_storage_serializerfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * SerializerFactory constructor.
 *
 * @param array services
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @param string name
 *
 * @return SerializerInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, &definition);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, getExceptionClass)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Phalcon\\Storage\\Exception");
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, getServices)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 14, 0);
	add_assoc_stringl_ex(return_value, SL("base64"), SL("Phalcon\\Storage\\Serializer\\Base64"));
	add_assoc_stringl_ex(return_value, SL("igbinary"), SL("Phalcon\\Storage\\Serializer\\Igbinary"));
	add_assoc_stringl_ex(return_value, SL("json"), SL("Phalcon\\Storage\\Serializer\\Json"));
	add_assoc_stringl_ex(return_value, SL("memcached_igbinary"), SL("Phalcon\\Storage\\Serializer\\MemcachedIgbinary"));
	add_assoc_stringl_ex(return_value, SL("memcached_json"), SL("Phalcon\\Storage\\Serializer\\MemcachedJson"));
	add_assoc_stringl_ex(return_value, SL("memcached_php"), SL("Phalcon\\Storage\\Serializer\\MemcachedPhp"));
	add_assoc_stringl_ex(return_value, SL("msgpack"), SL("Phalcon\\Storage\\Serializer\\Msgpack"));
	add_assoc_stringl_ex(return_value, SL("none"), SL("Phalcon\\Storage\\Serializer\\None"));
	add_assoc_stringl_ex(return_value, SL("php"), SL("Phalcon\\Storage\\Serializer\\Php"));
	add_assoc_stringl_ex(return_value, SL("redis_igbinary"), SL("Phalcon\\Storage\\Serializer\\RedisIgbinary"));
	add_assoc_stringl_ex(return_value, SL("redis_json"), SL("Phalcon\\Storage\\Serializer\\RedisJson"));
	add_assoc_stringl_ex(return_value, SL("redis_msgpack"), SL("Phalcon\\Storage\\Serializer\\RedisMsgpack"));
	add_assoc_stringl_ex(return_value, SL("redis_none"), SL("Phalcon\\Storage\\Serializer\\RedisNone"));
	add_assoc_stringl_ex(return_value, SL("redis_php"), SL("Phalcon\\Storage\\Serializer\\RedisPhp"));
	return;
}

