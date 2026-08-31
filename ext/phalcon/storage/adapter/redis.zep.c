
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


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
 * Capabilities:
 * - Counters: native atomic (incrBy()/decrBy()).
 * - getKeys(): non-blocking SCAN iteration.
 * - Serializers: Phalcon-side, or backend-native via OPT_SERIALIZER. Native
 *   serializers change the bytes at rest and are not interchangeable with
 *   Phalcon-side serializers.
 *
 * @phpstan-import-type storage_keys from StorageTypes
 * @phpstan-import-type storage_options from StorageTypes
 * @phpstan-import-type storage_redis_context from StorageTypes
 * @phpstan-import-type storage_redis_options from StorageTypes
 * @phpstan-import-type storage_redis_settings from StorageTypes
 *
 * @phpstan-property RedisService|null $adapter
 * @phpstan-property storage_redis_settings $options
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Redis)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Redis, phalcon, storage_adapter_redis, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_redis_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "ph-reds-", sizeof("ph-reds-") - 1);
		zephir_declare_typed_property(phalcon_storage_adapter_redis_ce, SL("prefix"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Redis constructor.
 *
 * @param SerializerFactory $factory
 * @param array             $options = [
 *     "host"           => "127.0.0.1",
 *     "port"           => 6379,
 *     "index"          => 0,
 *     "timeout"        => 0,
 *     "persistent"     => false,
 *     "persistentId"   => "",
 *     "auth"           => "",
 *     "socket"         => "",
 *     "connectTimeout" => 0,
 *     "retryInterval"  => 0,
 *     "readTimeout"    => 0,
 *     "ssl"            => [],
 * ]
 *
 * @phpstan-param storage_redis_options $options
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, localOptions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&localOptions);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_storage_serializerfactory_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &factory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_METHOD(&localOptions, this_ptr, "getdefaultoptions", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_redis_ce, getThis(), "__construct", NULL, 0, factory, &localOptions);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
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
	zend_bool _7;
	zval strippedKeys;
	zval adapter, keys, key, _0, *_1, _2, *_3, _6, _10, _4$$4, _5$$4, _8$$5, _9$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, prefixLength = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&strippedKeys);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&strippedKeys);
	array_init(&strippedKeys);
	ZEPHIR_CALL_METHOD(&keys, this_ptr, "getkeys", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&keys)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 126, PH_NOISY_CC | PH_READONLY);
	prefixLength = zephir_fast_strlen_ev(&_0);
	if (Z_TYPE_P(&keys) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &keys);
		_1 = &_2;
	} else {
		_1 = &keys;
	}
	zephir_is_iterable(_1, 0, "phalcon/Storage/Adapter/Redis.zep", 105);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _3);
			ZVAL_LONG(&_4$$4, prefixLength);
			ZEPHIR_INIT_NVAR(&_5$$4);
			zephir_substr(&_5$$4, &key, zephir_get_intval(&_4$$4), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_array_append(&strippedKeys, &_5$$4, PH_SEPARATE, "phalcon/Storage/Adapter/Redis.zep", 101);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_8$$5, prefixLength);
				ZEPHIR_INIT_NVAR(&_9$$5);
				zephir_substr(&_9$$5, &key, zephir_get_intval(&_8$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				zephir_array_append(&strippedKeys, &_9$$5, PH_SEPARATE, "phalcon/Storage/Adapter/Redis.zep", 101);
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, &adapter, "del", NULL, 0, &strippedKeys);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_10));
}

/**
 * Returns the already connected adapter or connects to the Redis
 * server(s)
 *
 * The return type is deliberately left wide: RedisCluster extends this
 * adapter and hands back a `RedisCluster` client, which is not a `Redis`.
 * Callers inside this class narrow it to `RedisService` locally.
 *
 * @return mixed|RedisService
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("prefix", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 127, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&connection);
		object_init_ex(&connection, zephir_get_internal_ce(SL("redis")));
		ZEPHIR_CALL_METHOD(NULL, &connection, "__construct", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "checkconnect", NULL, 141, &connection);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "checkauth", NULL, 142, &connection);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "checkindex", NULL, 143, &connection);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_1, 126, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 2);
		ZEPHIR_CALL_METHOD(NULL, &connection, "setoption", NULL, 0, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setserializer", NULL, 144, &connection);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 127, &connection);
	}
	RETURN_MM_MEMBER(getThis(), "adapter");
}

/**
 * Returns all the keys stored
 *
 * SCAN replaces the blocking KEYS command. SCAN_NOPREFIX keeps the prefix
 * handling explicit: the physical prefix is matched and returned unchanged,
 * so getFilteredKeys() sees exactly what KEYS produced.
 *
 * @phpstan-return storage_keys
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getKeys)
{
	zend_bool _7$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix_zv, adapter, cursor, keys, pattern, result, scanKeys, _0, _1$$3, _2$$3, _3$$3, _4$$3, _6$$7;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&cursor);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&scanKeys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$7);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!prefix) {
		prefix = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&prefix_zv);
		ZVAL_STR(&prefix_zv, prefix);
	} else {
		zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	}
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&keys);
	array_init(&keys);
	ZEPHIR_INIT_VAR(&cursor);
	ZVAL_STRING(&cursor, "0");
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 126, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_VS(&pattern, &_0, "*");
	while (1) {
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "scan");
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "MATCH");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "COUNT");
		ZVAL_LONG(&_4$$3, 100);
		ZEPHIR_CALL_METHOD(&result, &adapter, "rawcommand", &_5, 0, &_1$$3, &cursor, &_2$$3, &pattern, &_3$$3, &_4$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&result) != IS_ARRAY) {
			break;
		}
		ZEPHIR_OBS_NVAR(&cursor);
		if (!(zephir_array_isset_long_fetch(&cursor, &result, 0, 0))) {
			break;
		}
		ZEPHIR_OBS_NVAR(&scanKeys);
		if (zephir_array_isset_long_fetch(&scanKeys, &result, 1, 0)) {
			if (Z_TYPE_P(&scanKeys) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_6$$7);
				zephir_fast_array_merge(&_6$$7, &keys, &scanKeys);
				ZEPHIR_CPY_WRT(&keys, &_6$$7);
			}
		}
		_7$$3 = ZEPHIR_IS_STRING_IDENTICAL(&cursor, "0");
		if (!(_7$$3)) {
			_7$$3 = ZEPHIR_IS_LONG_IDENTICAL(&cursor, 0);
		}
		if (_7$$3) {
			break;
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfilteredkeys", NULL, 0, &keys, &prefix_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Stores data in the adapter forever. The key needs to manually deleted
 * from the adapter.
 *
 * @throws StorageException
 * @throws RedisException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, setForever)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data, data_sub, adapter, result, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(key_param)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &key_param, &data);
	zephir_get_strval(&key, key_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getkeywithoutprefix", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &adapter, "set", NULL, 0, &key, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	if (((Z_TYPE_P(&result) == IS_TRUE || Z_TYPE_P(&result) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&_2, &result);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_BOOL(&_2, 0);
	}
	RETURN_CCTOR(&_2);
}

/**
 * Decrements a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @throws RedisException
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doDecrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value_param = NULL, adapter, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		value_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, value);
	ZEPHIR_RETURN_CALL_METHOD(&adapter, "decrby", NULL, 0, &key_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Deletes data from the adapter
 *
 * @throws RedisException
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, adapter, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &adapter, "unlink", NULL, 0, &key_zv);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_0));
}

/**
 * Deletes multiple keys from Redis using a single unlink call
 *
 * @phpstan-param storage_keys $keys
 *
 * @throws RedisException
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doDeleteMultiple)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, adapter, result;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(keys, keys_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &keys_param);
	zephir_get_arrval(&keys, keys_param);
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &adapter, "unlink", NULL, 0, &keys);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&result) == IS_LONG;
	if (_0) {
		_0 = ZEPHIR_IS_LONG_IDENTICAL(&result, zephir_fast_count_int(&keys));
	}
	RETURN_MM_BOOL(_0);
}

/**
 * Checks if an element exists in the cache
 *
 * @throws RedisException
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doHas)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, adapter, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &adapter, "exists", NULL, 0, &key_zv);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_0));
}

/**
 * Increments a stored number
 *
 * @throws RedisException
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doIncrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value_param = NULL, adapter, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		value_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, value);
	ZEPHIR_RETURN_CALL_METHOD(&adapter, "incrby", NULL, 0, &key_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Stores data in the adapter. If the TTL is `null` (default) or not defined
 * then the default TTL will be used, as set in this adapter. If the TTL
 * is `0` or a negative number, a `delete()` will be issued, since this
 * item has expired. If you need to set this key forever, you should use
 * the `setForever()` method.
 *
 * @param string                $key
 * @param mixed                 $value
 * @param DateInterval|int|null $ttl
 *
 * @return bool
 * @throws BaseException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doSet)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub, *ttl = NULL, ttl_sub, __$null, adapter, result, _1, _2;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(ttl)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		ttl = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}
	_0 = Z_TYPE_P(ttl) == IS_LONG;
	if (_0) {
		_0 = ZEPHIR_LT_LONG(ttl, 1);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "delete", NULL, 0, &key_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &adapter, "set", NULL, 0, &key_zv, &_1, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * The parameter is the raw, user supplied options array; `RedisCluster`
 * overrides this method with its own set of keys, so the two signatures
 * have to agree on the wider type.
 *
 * @phpstan-param storage_options $options
 *
 * @phpstan-return storage_options
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getDefaultOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
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
	ZVAL_UNDEF(&_15);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
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
	array_init(&_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "auth");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getarrval", NULL, 0, &options, &_2, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("auth"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "socket");
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "getarrval", NULL, 0, &options, &_2, &_9);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("socket"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "connectTimeout");
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getarrval", NULL, 0, &options, &_2, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("connectTimeout"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "retryInterval");
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "getarrval", NULL, 0, &options, &_2, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("retryInterval"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "readTimeout");
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "getarrval", NULL, 0, &options, &_2, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("readTimeout"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "ssl");
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "getarrval", NULL, 0, &options, &_9, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("ssl"), &_15, PH_COPY | PH_SEPARATE);
	RETURN_CTOR(&options);
}

/**
 * @param RedisService $connection
 *
 * @throws AuthenticationFailed
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkAuth)
{
	zend_bool error = 0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, auth, _0, _3, _4, _2$$3, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("redis")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &connection);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 128, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&auth);
	zephir_array_fetch_string(&auth, &_0, SL("auth"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 383);

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
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, phalcon_storage_exceptions_authenticationfailed_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 145);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "phalcon/Storage/Adapter/Redis.zep", 392);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * @throws ConnectionFailed
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkConnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, auth, connectionOptions, ex, host, method, options, parameter, persistentId, port, retryInterval, readTimeout, result, ssl, timeout, _0, _1, _4, _2$$6, _3$$6, _5$$8, _6$$8, _7$$9, _8$$9, _9$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&connectionOptions);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&persistentId);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&retryInterval);
	ZVAL_UNDEF(&readTimeout);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&ssl);
	ZVAL_UNDEF(&timeout);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("redis")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &connection);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 128, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	zephir_memory_observe(&host);
	zephir_array_fetch_string(&host, &options, SL("host"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 407);
	zephir_memory_observe(&port);
	zephir_array_fetch_string(&port, &options, SL("port"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 408);
	zephir_memory_observe(&timeout);
	zephir_array_fetch_string(&timeout, &options, SL("timeout"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 409);
	zephir_memory_observe(&retryInterval);
	zephir_array_fetch_string(&retryInterval, &options, SL("retryInterval"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 410);
	zephir_memory_observe(&readTimeout);
	zephir_array_fetch_string(&readTimeout, &options, SL("readTimeout"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 411);
	zephir_memory_observe(&auth);
	zephir_array_fetch_string(&auth, &options, SL("auth"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 412);
	zephir_memory_observe(&ssl);
	zephir_array_fetch_string(&ssl, &options, SL("ssl"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 413);
	ZEPHIR_INIT_VAR(&connectionOptions);
	array_init(&connectionOptions);
	if (1 != ZEPHIR_IS_EMPTY(&auth)) {
		zephir_array_update_string(&connectionOptions, SL("auth"), &auth, PH_COPY | PH_SEPARATE);
	}
	if (1 != ZEPHIR_IS_EMPTY(&ssl)) {
		zephir_array_update_string(&connectionOptions, SL("stream"), &ssl, PH_COPY | PH_SEPARATE);
	}
	zephir_array_fetch_string(&_1, &options, SL("persistent"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Redis.zep", 423);
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_INIT_VAR(&parameter);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZVAL_STRING(&method, "connect");
		ZVAL_NULL(&parameter);
	} else {
		ZVAL_STRING(&method, "pconnect");
		zephir_read_property_cached(&_2$$6, this_ptr, _zephir_prop_0, 128, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&persistentId);
		zephir_array_fetch_string(&persistentId, &_2$$6, SL("persistentId"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 428);
		if (!(ZEPHIR_IS_EMPTY(&persistentId))) {
			ZEPHIR_CPY_WRT(&parameter, &persistentId);
		} else {
			zephir_array_fetch_string(&_3$$6, &options, SL("index"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Redis.zep", 429);
			ZEPHIR_CONCAT_SV(&parameter, "persistentId", &_3$$6);
		}
	}

	/* try_start_1: */

		ZEPHIR_CALL_METHOD_ZVAL(&result, connection, &method, NULL, 0, &host, &port, &timeout, &parameter, &retryInterval, &readTimeout, &connectionOptions);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_OBJ(&_4, EG(exception));
		Z_ADDREF_P(&_4);
		if (zephir_is_instance_of(&_4, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_4);
			ZEPHIR_INIT_VAR(&_5$$8);
			object_init_ex(&_5$$8, phalcon_storage_exceptions_connectionfailed_ce);
			ZEPHIR_CALL_METHOD(&_6$$8, &ex, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_5$$8, "__construct", NULL, 9, &_6$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$8, "phalcon/Storage/Adapter/Redis.zep", 444);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (!(zephir_is_true(&result))) {
		ZEPHIR_INIT_VAR(&_7$$9);
		object_init_ex(&_7$$9, phalcon_storage_exceptions_connectionfailed_ce);
		ZEPHIR_INIT_VAR(&_8$$9);
		ZVAL_STRING(&_8$$9, "Could not connect to the Redis server [%s:%s]");
		ZEPHIR_CALL_FUNCTION(&_9$$9, "sprintf", NULL, 146, &_8$$9, &host, &port);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$9, "__construct", NULL, 9, &_9$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$9, "phalcon/Storage/Adapter/Redis.zep", 454);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * @throws DatabaseSelectionFailed
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkIndex)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, index, _0, _2, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("redis")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &connection);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 128, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&index);
	zephir_array_fetch_string(&index, &_0, SL("index"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 467);
	_1 = ZEPHIR_GT_LONG(&index, 0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, connection, "select", NULL, 0, &index);
		zephir_check_call_status();
		_1 = !ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_storage_exceptions_databaseselectionfailed_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 147);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Storage/Adapter/Redis.zep", 470);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Checks the serializer. If it is a supported one it is set, otherwise
 * the custom one is set.
 *
 * @throws BaseException
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultSerializer", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("redis")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &connection);
	ZEPHIR_INIT_VAR(&map);
	zephir_create_array(&map, 2, 0);
	add_assoc_long_ex(&map, SL("redis_none"), 0);
	add_assoc_long_ex(&map, SL("redis_php"), 1);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_IGBINARY");
	ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 148, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\Redis::SERIALIZER_IGBINARY");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "constant", NULL, 149, &_2$$3);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_igbinary"), &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_MSGPACK");
	ZEPHIR_CALL_FUNCTION(&_4, "defined", NULL, 148, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "\\Redis::SERIALIZER_MSGPACK");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "constant", NULL, 149, &_5$$4);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_msgpack"), &_6$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_JSON");
	ZEPHIR_CALL_FUNCTION(&_7, "defined", NULL, 148, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "\\Redis::SERIALIZER_JSON");
		ZEPHIR_CALL_FUNCTION(&_9$$5, "constant", NULL, 149, &_8$$5);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_json"), &_9$$5, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_0, 129, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serializer);
	zephir_fast_strtolower(&serializer, &_10);
	if (1 == zephir_array_isset_value(&map, &serializer)) {
		ZEPHIR_INIT_VAR(&_11$$6);
		ZEPHIR_INIT_NVAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 129, &_11$$6);
		zephir_array_fetch(&_12$$6, &map, &serializer, PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Redis.zep", 512);
		ZVAL_LONG(&_13$$6, 1);
		ZEPHIR_CALL_METHOD(NULL, connection, "setoption", NULL, 0, &_13$$6, &_12$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

