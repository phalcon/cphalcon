
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
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * RedisCluster adapter
 *
 * Capabilities (in addition to Redis):
 * - Counters: native atomic (incrBy()/decrBy()).
 * - getKeys(): blocking KEYS across all master nodes (per-node SCAN is left to
 *   the redesign); clear() flushes every master.
 * - Serializers: Phalcon-side, or backend-native via OPT_SERIALIZER.
 *
 * @phpstan-import-type storage_keys from StorageTypes
 * @phpstan-import-type storage_options from StorageTypes
 * @phpstan-import-type storage_rediscluster_options from StorageTypes
 * @phpstan-import-type storage_rediscluster_settings from StorageTypes
 *
 * @phpstan-property RedisService|null $adapter
 * @phpstan-property storage_rediscluster_settings $options
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_RedisCluster)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, RedisCluster, phalcon, storage_adapter_rediscluster, phalcon_storage_adapter_redis_ce, phalcon_storage_adapter_rediscluster_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "ph-redc-", sizeof("ph-redc-") - 1);
		zephir_declare_typed_property(phalcon_storage_adapter_rediscluster_ce, SL("prefix"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * You can create and connect to a cluster either by passing it one or more
 * 'seed' nodes, or by defining these in redis.ini as a 'named' cluster.
 *
 * If you are connecting with the cluster by offering a name, that is
 * configured in redis.ini:
 *
 *      ```
 *      # In redis.ini
 *      redis.clusters.seeds = "mycluster[]=localhost:7000&test[]=localhost:7001"
 *      redis.clusters.timeout = "mycluster=5"
 *      redis.clusters.read_timeout = "mycluster=10"
 *      redis.clusters.auth = "mycluster=password"
 *      ```
 * you can use `$options = ["name" => "mycluster"]`.
 *
 * If you don't have cluster seeds configured in your redis.ini,
 * you should pass hosts as an array,
 * eg. `$options = ["hosts" => ["a-host:7000", "b-host:7001"]]`.
 *
 * You can provide authentication data offering a string `user=password`
 * or array `["user" => "name", "password" => "secret"]`.
 *
 * The `timeout` is the amount of time library will wait when connecting
 * or writing to the cluster. `readTimeout` is the amount of time library
 * will wait for a result from the cluster.
 *
 * The `context` is an array of values used for ssl/tls stream context
 * options eg `["verify_peer" => 0, "local_cert" => "file:///path/to/cert.pem"]`
 *
 * @param array             $options = [
 *     "name"        => null,
 *     "hosts"       => ["127.0.0.1:6379"],
 *     "timeout"     => 0,
 *     "readTimeout" => 0,
 *     "persistent"  => false,
 *     "auth"        => "",
 *     "context"     => null,
 * ]
 *
 * @phpstan-param storage_rediscluster_options $options
 *
 * @throws SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL;

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&options);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_storage_adapter_rediscluster_ce, getThis(), "__construct", &_zephir_call_cache[0], factory, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Flushes/clears the cache
 *
 * @return bool
 * @throws ClusterConnectionFailed|SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, clear)
{
	zend_bool _5;
	zval adapter, master, _0, *_1, _2, *_3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&master);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&adapter, this_ptr, "getAdapter", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_0, &adapter, "_masters", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Storage/Adapter/RedisCluster.zep", 107);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&master);
			ZVAL_COPY(&master, _3);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &adapter, "flushAll", &_zephir_call_cache[2], &master);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[4]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, _1, "valid", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&master, _1, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, &adapter, "flushAll", &_zephir_call_cache[7], &master);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&master);
	RETURN_MM_BOOL(1);
}

/**
 * Returns the already connected adapter or connects to the Redis
 * server(s)
 *
 * @return RedisService
 * @throws ClusterConnectionFailed|SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, getAdapter)
{
	zval connection, ex, options, _0, _1$$3, _9$$3, _14$$3, _2$$4, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _10$$5, _11$$5, _12$$5, _13$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("prefix", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 331, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&options, &_1$$3);

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&connection);
			object_init_ex(&connection, zephir_get_internal_ce(SL("rediscluster")));
			zephir_memory_observe(&_2$$4);
			zephir_array_fetch_string(&_2$$4, &options, SL("name"), PH_NOISY, "phalcon/Storage/Adapter/RedisCluster.zep", 126);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_memory_observe(&_3$$4);
			zephir_array_fetch_string(&_3$$4, &options, SL("hosts"), PH_NOISY, "phalcon/Storage/Adapter/RedisCluster.zep", 127);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_memory_observe(&_4$$4);
			zephir_array_fetch_string(&_4$$4, &options, SL("timeout"), PH_NOISY, "phalcon/Storage/Adapter/RedisCluster.zep", 128);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_memory_observe(&_5$$4);
			zephir_array_fetch_string(&_5$$4, &options, SL("readTimeout"), PH_NOISY, "phalcon/Storage/Adapter/RedisCluster.zep", 129);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_memory_observe(&_6$$4);
			zephir_array_fetch_string(&_6$$4, &options, SL("persistent"), PH_NOISY, "phalcon/Storage/Adapter/RedisCluster.zep", 130);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_memory_observe(&_7$$4);
			zephir_array_fetch_string(&_7$$4, &options, SL("auth"), PH_NOISY, "phalcon/Storage/Adapter/RedisCluster.zep", 131);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_memory_observe(&_8$$4);
			zephir_array_fetch_string(&_8$$4, &options, SL("context"), PH_NOISY, "phalcon/Storage/Adapter/RedisCluster.zep", 133);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "__construct", &_zephir_call_cache[0], &_2$$4, &_3$$4, &_4$$4, &_5$$4, &_6$$4, &_7$$4, &_8$$4);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_9$$3);
			ZVAL_OBJ(&_9$$3, EG(exception));
			Z_ADDREF_P(&_9$$3);
			if (zephir_is_instance_of(&_9$$3, SL("Throwable"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&ex, &_9$$3);
				ZEPHIR_INIT_VAR(&_10$$5);
				object_init_ex(&_10$$5, phalcon_storage_exceptions_clusterconnectionfailed_ce);
				ZEPHIR_CALL_METHOD_CACHED(&_11$$5, &ex, "getMessage", &_zephir_call_cache[1]);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_12$$5);
				ZEPHIR_CONCAT_SV(&_12$$5, "Could not connect to the Redis Cluster server due to: ", &_11$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_LONG(&_13$$5, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$5, "__construct", &_zephir_call_cache[2], &_12$$5, &_13$$5, &ex);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$5, "phalcon/Storage/Adapter/RedisCluster.zep", 140);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_2, 332, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_14$$3, 2);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "setOption", &_zephir_call_cache[3], &_14$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setSerializer", &_zephir_call_cache[4], &connection);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 330, &connection);
	}
	RETURN_MM_MEMBER(getThis(), "adapter");
}

/**
 * Returns all the keys stored
 *
 * RedisCluster::scan() iterates one node at a time, so the blocking KEYS
 * command is retained here (phpredis routes it across the masters). The
 * per-node SCAN migration is left to the storage redesign.
 *
 * @phpstan-return storage_keys
 *
 * @throws ClusterConnectionFailed|SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, getKeys)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix_zv, keys, _0, _1;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getAdapter", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "*");
	ZEPHIR_CALL_METHOD_CACHED(&keys, &_0, "keys", &_zephir_call_cache[1], &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getFilteredKeys", &_zephir_call_cache[2], &keys, &prefix_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-param storage_options $options
 *
 * @phpstan-return storage_options
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, getDefaultOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "name");
	ZVAL_NULL(&_2);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getArrVal", &_zephir_call_cache[0], &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("name"), &_0, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "hosts");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "127.0.0.1:6379");
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getArrVal", &_zephir_call_cache[1], &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("hosts"), &_3, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "timeout");
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "getArrVal", &_zephir_call_cache[2], &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("timeout"), &_5, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "readTimeout");
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_6, this_ptr, "getArrVal", &_zephir_call_cache[3], &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("readTimeout"), &_6, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "persistent");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "bool");
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "getArrVal", &_zephir_call_cache[4], &options, &_1, &_2, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("persistent"), &_7, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "auth");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "");
	ZEPHIR_CALL_METHOD_CACHED(&_8, this_ptr, "getArrVal", &_zephir_call_cache[5], &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("auth"), &_8, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "context");
	ZVAL_NULL(&_2);
	ZEPHIR_CALL_METHOD_CACHED(&_9, this_ptr, "getArrVal", &_zephir_call_cache[6], &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("context"), &_9, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&options);
}

/**
 * Checks the serializer. If it is a supported one it is set, otherwise
 * the custom one is set.
 *
 * @throws SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, setSerializer)
{
	zend_bool _13;
	zval map;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zval *connection, connection_sub, serializer, _0, _1, _6, _9, _12, _3$$3, _4$$3, _7$$4, _8$$4, _10$$5, _11$$5, _14$$6, _15$$6, _16$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&map);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultSerializer", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("rediscluster")))
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
	ZEPHIR_CALL_FUNCTION(&_1, "defined", &_2, 39, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "\\Redis::SERIALIZER_IGBINARY");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "constant", &_5, 40, &_3$$3);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_igbinary"), &_4$$3, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_MSGPACK");
	ZEPHIR_CALL_FUNCTION(&_6, "defined", &_2, 39, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "\\Redis::SERIALIZER_MSGPACK");
		ZEPHIR_CALL_FUNCTION(&_8$$4, "constant", &_5, 40, &_7$$4);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_msgpack"), &_8$$4, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_JSON");
	ZEPHIR_CALL_FUNCTION(&_9, "defined", &_2, 39, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "\\Redis::SERIALIZER_JSON");
		ZEPHIR_CALL_FUNCTION(&_11$$5, "constant", &_5, 40, &_10$$5);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_json"), &_11$$5, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_0, 333, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&serializer);
	zephir_fast_strtolower(&serializer, &_12);
	_13 = zephir_array_isset_value(&map, &serializer);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 == _13) {
		ZEPHIR_INIT_VAR(&_14$$6);
		ZEPHIR_INIT_NVAR(&_14$$6);
		ZVAL_STRING(&_14$$6, "");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 333, &_14$$6);
		zephir_array_fetch(&_15$$6, &map, &serializer, PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 230);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_16$$6, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, connection, "setOption", &_zephir_call_cache[0], &_16$$6, &_15$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "initSerializer", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

