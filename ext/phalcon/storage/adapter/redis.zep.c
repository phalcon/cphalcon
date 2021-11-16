
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Redis adapter
 *
 * @property array $options
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Redis)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Redis, phalcon, storage_adapter_redis, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_redis_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_redis_ce, SL("prefix"), "ph-reds-", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Redis constructor.
 *
 * @param SerializerFactory $factory
 * @param array             $options
 *
 * @throws SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_storage_serializerfactory_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "host");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "127.0.0.1");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("host"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "port");
	ZVAL_LONG(&_4, 6379);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "int");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("port"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "index");
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("index"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "timeout");
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("timeout"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "persistent");
	ZVAL_BOOL(&_4, 0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "bool");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("persistent"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "persistentId");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "string");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2, &_9);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("persistentId"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "auth");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("auth"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "socket");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("socket"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "connectTimeout");
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("connectTimeout"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "retryInterval");
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("retryInterval"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "readTimeout");
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("readTimeout"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_redis_ce, getThis(), "__construct", &_15, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Flushes/clears the cache
 *
 * @return bool
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "flushdb", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Decrements a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, decrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "decrby", NULL, 0, &key, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Reads data from the adapter
 *
 * @param string $key
 *
 * @return bool
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "del", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_1));
}

/**
 * Reads data from the adapter
 *
 * @param string     $key
 * @param mixed|null $defaultValue
 *
 * @return mixed|null
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getunserializeddata", NULL, 0, &_1, defaultValue);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the already connected adapter or connects to the Redis
 * server(s)
 *
 * @return mixed|\Redis
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getAdapter)
{
	zval connection, _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&connection);
		object_init_ex(&connection, zephir_get_internal_ce(SL("redis")));
		ZEPHIR_CALL_METHOD(NULL, &connection, "__construct", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "checkconnect", NULL, 137, &connection);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "checkauth", NULL, 138, &connection);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "checkindex", NULL, 139, &connection);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 2);
		ZEPHIR_CALL_METHOD(NULL, &connection, "setoption", NULL, 0, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setserializer", NULL, 140, &connection);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), &connection);
	}
	RETURN_MM_MEMBER(getThis(), "adapter");
}

/**
 * Stores data in the adapter
 *
 * @param string $prefix
 *
 * @return array
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getKeys)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, _0, _1, _2;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
	}
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "*");
	ZEPHIR_CALL_METHOD(&_1, &_0, "keys", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfilteredkeys", NULL, 0, &_1, &prefix);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks if an element exists in the cache
 *
 * @param string $key
 *
 * @return bool
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "exists", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_1));
}

/**
 * Increments a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|false|int
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, increment)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "incrby", NULL, 0, &key, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Stores data in the adapter
 *
 * @param string                 $key
 * @param mixed                  $value
 * @param \DateInterval|int|null $ttl
 *
 * @return bool
 * @throws BaseException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, set)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *ttl = NULL, ttl_sub, __$null, result, _1, _2, _3, _4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(ttl)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &ttl);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}


	_0 = Z_TYPE_P(ttl) == IS_LONG;
	if (_0) {
		_0 = ZEPHIR_LT_LONG(ttl, 1);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "delete", NULL, 0, &key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &_1, "set", NULL, 0, &key, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	if (((Z_TYPE_P(&result) == IS_TRUE || Z_TYPE_P(&result) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&_4, &result);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	RETURN_CCTOR(&_4);
}

/**
 * Stores data in the adapter forever. The key needs to manually deleted
 * from the adapter.
 *
 * @param string $key
 * @param mixed  $value
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, setForever)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, result, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &_0, "set", NULL, 0, &key, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	if (((Z_TYPE_P(&result) == IS_TRUE || Z_TYPE_P(&result) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&_2, &result);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	RETURN_CCTOR(&_2);
}

/**
 * @param \Redis $connection
 *
 * @return Redis
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkAuth)
{
	zend_bool error = 0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, auth, _0, _3, _4, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("redis")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&auth);
	zephir_array_fetch_string(&auth, &_0, SL("auth"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 244);

	/* try_start_1: */

		_1$$3 = 1 != ZEPHIR_IS_EMPTY(&auth);
		if (_1$$3) {
			ZEPHIR_CALL_METHOD(&_2$$3, connection, "auth", NULL, 0, &auth);
			zephir_check_call_status_or_jump(try_end_1);
			_1$$3 = !ZEPHIR_IS_TRUE_IDENTICAL(&_2$$3);
		}
		error = _1$$3;

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		ZEPHIR_INIT_VAR(&_4);
		if (zephir_is_instance_of(&_3, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_4, &_3);
			error = 1;
		}
	}
	if (error) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Failed to authenticate with the Redis server", "phalcon/Storage/Adapter/Redis.zep", 255);
		return;
	}
	RETURN_THIS();
}

/**
 * @param \Redis $connection
 *
 * @return Redis
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkConnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, host, method, options, parameter, persistentId, port, retryInterval, readTimeout, result, timeout, _0, _1, _2$$4, _3$$4, _4$$5, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&persistentId);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&retryInterval);
	ZVAL_UNDEF(&readTimeout);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&timeout);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("redis")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_OBS_VAR(&host);
	zephir_array_fetch_string(&host, &options, SL("host"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 273);
	ZEPHIR_OBS_VAR(&port);
	zephir_array_fetch_string(&port, &options, SL("port"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 274);
	ZEPHIR_OBS_VAR(&timeout);
	zephir_array_fetch_string(&timeout, &options, SL("timeout"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 275);
	ZEPHIR_OBS_VAR(&retryInterval);
	zephir_array_fetch_string(&retryInterval, &options, SL("retryInterval"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 276);
	ZEPHIR_OBS_VAR(&readTimeout);
	zephir_array_fetch_string(&readTimeout, &options, SL("readTimeout"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 277);
	zephir_array_fetch_string(&_1, &options, SL("persistent"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Redis.zep", 279);
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_INIT_VAR(&parameter);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZVAL_STRING(&method, "connect");
		ZVAL_NULL(&parameter);
	} else {
		ZVAL_STRING(&method, "pconnect");
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&persistentId);
		zephir_array_fetch_string(&persistentId, &_2$$4, SL("persistentId"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 284);
		if (!(ZEPHIR_IS_EMPTY(&persistentId))) {
			ZEPHIR_CPY_WRT(&parameter, &persistentId);
		} else {
			zephir_array_fetch_string(&_3$$4, &options, SL("index"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Redis.zep", 285);
			ZEPHIR_CONCAT_SV(&parameter, "persistentId", &_3$$4);
		}
	}
	ZEPHIR_CALL_METHOD_ZVAL(&result, connection, &method, NULL, 0, &host, &port, &timeout, &parameter, &retryInterval, &readTimeout);
	zephir_check_call_status();
	if (!(zephir_is_true(&result))) {
		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, phalcon_storage_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "Could not connect to the Redisd server [%s:%s]");
		ZEPHIR_CALL_FUNCTION(&_6$$5, "sprintf", NULL, 141, &_5$$5, &host, &port);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 8, &_6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$5, "phalcon/Storage/Adapter/Redis.zep", 304);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * @param \Redis $connection
 *
 * @return Redis
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkIndex)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, index, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("redis")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&index);
	zephir_array_fetch_string(&index, &_0, SL("index"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 320);
	_1 = ZEPHIR_GT_LONG(&index, 0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, connection, "select", NULL, 0, &index);
		zephir_check_call_status();
		_1 = !ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Redis server selected database failed", "phalcon/Storage/Adapter/Redis.zep", 325);
		return;
	}
	RETURN_THIS();
}

/**
 * Checks the serializer. If it is a supported one it is set, otherwise
 * the custom one is set.
 *
 * @param \Redis $connection
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, setSerializer)
{
	zval map;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, serializer, _0, _1, _4, _7, _10, _2$$3, _3$$3, _5$$4, _6$$4, _8$$5, _9$$5, _11$$6, _12$$6, _13$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&map);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("redis")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);


	ZEPHIR_INIT_VAR(&map);
	zephir_create_array(&map, 2, 0);
	add_assoc_long_ex(&map, SL("none"), 0);
	add_assoc_long_ex(&map, SL("php"), 1);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_IGBINARY");
	ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 142, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\Redis::SERIALIZER_IGBINARY");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "constant", NULL, 143, &_2$$3);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("igbinary"), &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_MSGPACK");
	ZEPHIR_CALL_FUNCTION(&_4, "defined", NULL, 142, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "\\Redis::SERIALIZER_MSGPACK");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "constant", NULL, 143, &_5$$4);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("msgpack"), &_6$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_JSON");
	ZEPHIR_CALL_FUNCTION(&_7, "defined", NULL, 142, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "\\Redis::SERIALIZER_JSON");
		ZEPHIR_CALL_FUNCTION(&_9$$5, "constant", NULL, 143, &_8$$5);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("json"), &_9$$5, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serializer);
	zephir_fast_strtolower(&serializer, &_10);
	if (1 == zephir_array_isset(&map, &serializer)) {
		ZEPHIR_INIT_VAR(&_11$$6);
		ZEPHIR_INIT_NVAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "");
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultSerializer"), &_11$$6);
		zephir_array_fetch(&_12$$6, &map, &serializer, PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Redis.zep", 367);
		ZVAL_LONG(&_13$$6, 1);
		ZEPHIR_CALL_METHOD(NULL, connection, "setoption", NULL, 0, &_13$$6, &_12$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

