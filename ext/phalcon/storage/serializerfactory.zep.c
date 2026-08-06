
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


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
	ZEPHIR_REGISTER_CLASS(Phalcon\\Storage, SerializerFactory, phalcon, storage_serializerfactory, phalcon_storage_serializerfactory_method_entry, 0);

	/**
	 * @var array<string, object>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_storage_serializerfactory_ce, SL("instances"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var string[]
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_storage_serializerfactory_ce, SL("mapper"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * SerializerFactory constructor.
 *
 * @param string[] $services
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(services, services_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
		zephir_get_arrval(&services, services_param);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @param string name
 *
 * @return SerializerInterface
 * @throws BaseException
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcachedinstance", NULL, 0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return class-string<Throwable>
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Storage\\Exception");
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, getServices)
{

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

/**
 * Return an object from the instances pool. If it does not exist, create it
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, getCachedInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, arguments, definition, _0, _2, _3, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("instances", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, -1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&arguments);
	zephir_get_args_from(&arguments, 1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1338, PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset_value(&_0, &name_zv)) {
		ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_1$$3, &definition, &arguments);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("instances"), &name_zv, &_1$$3);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1338, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Traits/Factory/FactoryTrait.zep", 46);
	RETURN_CTOR(&_3);
}

/**
 * Returns a service based on the name; throws exception if it does not
 * exist
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, getService)
{
	zval _4$$3;
	zend_class_entry *_3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, exceptionClass, _0, _5, _6, _1$$3, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mapper", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1339, PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset_value(&_0, &name_zv)) {
		ZEPHIR_CALL_METHOD(&exceptionClass, this_ptr, "getexceptionclass", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fetch_safe_class(&_2$$3, &exceptionClass);
		_3$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$3), Z_STRLEN_P(&_2$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_3$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_1$$3, _3$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_1$$3);
		zephir_check_call_status();
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_4$$3);
			ZEPHIR_CONCAT_SVS(&_4$$3, "Service ", &name_zv, " is not registered");
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_4$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_1$$3, "phalcon/Traits/Factory/FactoryTrait.zep", 70);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 1339, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Traits/Factory/FactoryTrait.zep", 73);
	RETURN_CTOR(&_6);
}

/**
 * Initializes services
 *
 * @param string[] $services
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, init)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL, _0, _1;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mapper", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(services, services_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
		zephir_get_arrval(&services, services_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getservices", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &services);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1339, &_0);
	ZEPHIR_MM_RESTORE();
}

