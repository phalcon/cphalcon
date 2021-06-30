
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Redis)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Redis, phalcon, storage_adapter_redis, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_redis_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_redis_ce, SL("options"), ZEND_ACC_PROTECTED);
	phalcon_storage_adapter_redis_ce->create_object = zephir_init_properties_Phalcon_Storage_Adapter_Redis;

	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'host' => '127.0.0.1',
 *     'port' => 6379,
 *     'index' => 0,
 *     'persistent' => false,
 *     'auth' => '',
 *     'socket' => '',
 *     'connectionTimeout' => 0,
 *     'retryInterval' => null,
 *     'readTimeout' => 0,
 *     'defaultSerializer' => 'Php',
 *     'lifetime' => 3600,
 *     'serializer' => null,
 *     'prefix' => ''
 * ]
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_14 = NULL;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
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


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "host");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "127.0.0.1");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "string");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("host"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "port");
	ZVAL_LONG(&_6, 6379);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "int");
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_6, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("port"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "index");
	ZVAL_LONG(&_6, 0);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "int");
	ZEPHIR_CALL_CE_STATIC(&_7, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_6, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("index"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "persistent");
	ZVAL_BOOL(&_6, 0);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "bool");
	ZEPHIR_CALL_CE_STATIC(&_8, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_6, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("persistent"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "auth");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "string");
	ZEPHIR_CALL_CE_STATIC(&_9, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("auth"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "socket");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "string");
	ZEPHIR_CALL_CE_STATIC(&_10, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("socket"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "connectionTimeout");
	ZVAL_LONG(&_6, 0);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "int");
	ZEPHIR_CALL_CE_STATIC(&_11, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_6, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("connectionTimeout"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "retryInterval");
	ZVAL_NULL(&_6);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "int");
	ZEPHIR_CALL_CE_STATIC(&_12, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_6, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("retryInterval"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "readTimeout");
	ZVAL_LONG(&_6, 0);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "int");
	ZEPHIR_CALL_CE_STATIC(&_13, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_6, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("readTimeout"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ph-reds-");
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_redis_ce, getThis(), "__construct", &_14, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Flushes/clears the cache
 *
 * @return bool
 * @throws Exception
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
 * @throws Exception
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
 * @throws Exception
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
 * @param string $key
 * @param mixed|null defaultValue
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(defaultValue)
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(&_0)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getunserializeddata", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the already connected adapter or connects to the Redis
 * server(s)
 *
 * @return mixed|\Redis
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getAdapter)
{
	zend_bool _4$$3, _6$$3;
	zval auth, connection, connectionTimeout, host, index, options, port, readTimeout, reserved, result, retryInterval, persistent, persistentid, _0, _1$$3, _5$$3, _7$$3, _8$$3, _2$$6, _3$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&connectionTimeout);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&readTimeout);
	ZVAL_UNDEF(&reserved);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&retryInterval);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&persistentid);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&options, &_1$$3);
		ZEPHIR_INIT_VAR(&connection);
		object_init_ex(&connection, zephir_get_internal_ce(SL("redis")));
		ZEPHIR_CALL_METHOD(NULL, &connection, "__construct", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&auth);
		zephir_array_fetch_string(&auth, &options, SL("auth"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 140);
		ZEPHIR_OBS_VAR(&index);
		zephir_array_fetch_string(&index, &options, SL("index"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 141);
		ZEPHIR_OBS_VAR(&persistent);
		zephir_array_fetch_string(&persistent, &options, SL("persistent"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 142);
		ZEPHIR_OBS_VAR(&host);
		zephir_array_fetch_string(&host, &options, SL("host"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 143);
		ZEPHIR_OBS_VAR(&port);
		zephir_array_fetch_string(&port, &options, SL("port"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 144);
		ZEPHIR_OBS_VAR(&connectionTimeout);
		zephir_array_fetch_string(&connectionTimeout, &options, SL("connectionTimeout"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 145);
		ZEPHIR_OBS_VAR(&retryInterval);
		zephir_array_fetch_string(&retryInterval, &options, SL("retryInterval"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 146);
		ZEPHIR_OBS_VAR(&readTimeout);
		zephir_array_fetch_string(&readTimeout, &options, SL("readTimeout"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 147);
		ZEPHIR_INIT_VAR(&reserved);
		ZVAL_NULL(&reserved);
		if (!(zephir_is_true(&persistent))) {
			ZEPHIR_CALL_METHOD(&result, &connection, "connect", NULL, 0, &host, &port, &connectionTimeout, &reserved, &retryInterval, &readTimeout);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&persistentid);
			ZEPHIR_CONCAT_SV(&persistentid, "persistentid_", &index);
			ZEPHIR_CALL_METHOD(&result, &connection, "pconnect", NULL, 0, &host, &port, &connectionTimeout, &persistentid, &retryInterval, &readTimeout);
			zephir_check_call_status();
		}
		if (!(zephir_is_true(&result))) {
			ZEPHIR_INIT_VAR(&_2$$6);
			object_init_ex(&_2$$6, phalcon_storage_exception_ce);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZEPHIR_CONCAT_SVSVS(&_3$$6, "Could not connect to the Redisd server [", &host, ":", &port, "]");
			ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 8, &_3$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$6, "phalcon/Storage/Adapter/Redis.zep", 175);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_4$$3 = !(ZEPHIR_IS_EMPTY(&auth));
		if (_4$$3) {
			ZEPHIR_CALL_METHOD(&_5$$3, &connection, "auth", NULL, 0, &auth);
			zephir_check_call_status();
			_4$$3 = !zephir_is_true(&_5$$3);
		}
		if (_4$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Failed to authenticate with the Redis server", "phalcon/Storage/Adapter/Redis.zep", 179);
			return;
		}
		_6$$3 = ZEPHIR_GT_LONG(&index, 0);
		if (_6$$3) {
			ZEPHIR_CALL_METHOD(&_7$$3, &connection, "select", NULL, 0, &index);
			zephir_check_call_status();
			_6$$3 = !zephir_is_true(&_7$$3);
		}
		if (_6$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Redis server selected database failed", "phalcon/Storage/Adapter/Redis.zep", 183);
			return;
		}
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_8$$3, 2);
		ZEPHIR_CALL_METHOD(NULL, &connection, "setoption", NULL, 0, &_8$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setserializer", NULL, 126, &connection);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), &connection);
	}
	RETURN_MM_MEMBER(getThis(), "adapter");
}

/**
 * Gets the keys from the adapter. Accepts an optional prefix which will
 * filter the keys returned
 *
 * @return array
 * @throws Exception
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
 * @throws Exception
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
 * @return bool|int
 * @throws Exception
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
 * @param string $key
 * @param mixed  $value
 * @param \DateInterval|int|null ttl
 *
 * @return bool
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *ttl = NULL, ttl_sub, __$null, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(ttl)
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "set", NULL, 0, &key, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
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
	zval *connection, connection_sub, serializer, _0, _1, _4, _7, _2$$3, _3$$3, _5$$4, _6$$4, _8$$5, _9$$5, _10$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&map);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(connection)
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
	ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 127, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\Redis::SERIALIZER_IGBINARY");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "constant", NULL, 128, &_2$$3);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("igbinary"), &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_MSGPACK");
	ZEPHIR_CALL_FUNCTION(&_4, "defined", NULL, 127, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "\\Redis::SERIALIZER_MSGPACK");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "constant", NULL, 128, &_5$$4);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("msgpack"), &_6$$4, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serializer);
	zephir_fast_strtolower(&serializer, &_7);
	if (zephir_array_isset(&map, &serializer)) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZEPHIR_INIT_NVAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "");
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultSerializer"), &_8$$5);
		zephir_array_fetch(&_9$$5, &map, &serializer, PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Redis.zep", 288);
		ZVAL_LONG(&_10$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, connection, "setoption", NULL, 0, &_10$$5, &_9$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Redis(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

