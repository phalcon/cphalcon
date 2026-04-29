
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
 * RedisCluster adapter
 *
 * @property array $options
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_RedisCluster)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, RedisCluster, phalcon, storage_adapter_rediscluster, phalcon_storage_adapter_redis_ce, phalcon_storage_adapter_rediscluster_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_rediscluster_ce, SL("prefix"), "ph-redc-", ZEND_ACC_PROTECTED);
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
 * @param SerializerFactory $factory
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
 * @throws \Phalcon\Support\Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _4;
	zval *factory, factory_sub, *options_param = NULL, _0, _1, _2, _3, _5, _6, _7, _8, _9, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_4);
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
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "name");
	ZVAL_NULL(&_2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("name"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "127.0.0.1:6379");
	zephir_array_fast_append(&_4, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "hosts");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getarrval", NULL, 0, &options, &_1, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("hosts"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "timeout");
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("timeout"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "readTimeout");
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("readTimeout"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "persistent");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "bool");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2, &_8);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("persistent"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "auth");
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getarrval", NULL, 0, &options, &_1, &_8);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("auth"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "context");
	ZVAL_NULL(&_2);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("context"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_rediscluster_ce, getThis(), "__construct", NULL, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Flushes/clears the cache
 *
 * @return bool
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, clear)
{
	zval adapter, master, _0, *_1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&master);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&adapter, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &adapter, "_masters", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Storage/Adapter/RedisCluster.zep", 100);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&master);
			ZVAL_COPY(&master, _1);
			ZEPHIR_CALL_METHOD(NULL, &adapter, "flushall", &_3, 0, &master);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&master, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &adapter, "flushall", &_4, 0, &master);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&master);
	RETURN_MM_BOOL(1);
}

/**
 * Returns the already connected adapter or connects to the Redis
 * Cluster server(s)
 *
 * @return mixed|\RedisCluster
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, getAdapter)
{
	zval connection, ex, options, _0, _1$$3, _9$$3, _13$$3, _2$$4, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _10$$5, _11$$5, _12$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_13$$3);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&options, &_1$$3);

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&connection);
			object_init_ex(&connection, zephir_get_internal_ce(SL("rediscluster")));
			zephir_array_fetch_string(&_2$$4, &options, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 119);
			zephir_array_fetch_string(&_3$$4, &options, SL("hosts"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 120);
			zephir_array_fetch_string(&_4$$4, &options, SL("timeout"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 121);
			zephir_array_fetch_string(&_5$$4, &options, SL("readTimeout"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 122);
			zephir_array_fetch_string(&_6$$4, &options, SL("persistent"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 123);
			zephir_array_fetch_string(&_7$$4, &options, SL("auth"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 124);
			zephir_array_fetch_string(&_8$$4, &options, SL("context"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 126);
			ZEPHIR_CALL_METHOD(NULL, &connection, "__construct", NULL, 0, &_2$$4, &_3$$4, &_4$$4, &_5$$4, &_6$$4, &_7$$4, &_8$$4);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_9$$3);
			ZVAL_OBJ(&_9$$3, EG(exception));
			Z_ADDREF_P(&_9$$3);
			if (zephir_is_instance_of(&_9$$3, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&ex, &_9$$3);
				ZEPHIR_INIT_VAR(&_10$$5);
				object_init_ex(&_10$$5, phalcon_storage_exception_ce);
				ZEPHIR_CALL_METHOD(&_11$$5, &ex, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_12$$5);
				ZEPHIR_CONCAT_SV(&_12$$5, "Could not connect to the Redis Cluster server due to: ", &_11$$5);
				ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 32, &_12$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$5, "phalcon/Storage/Adapter/RedisCluster.zep", 130);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_13$$3, 2);
		ZEPHIR_CALL_METHOD(NULL, &connection, "setoption", NULL, 0, &_13$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setserializer", NULL, 121, &connection);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), &connection);
	}
	RETURN_MM_MEMBER(getThis(), "adapter");
}

/**
 * Checks the serializer. If it is a supported one it is set, otherwise
 * the custom one is set.
 *
 * @param \RedisCluster $connection
 */
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, setSerializer)
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
	ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 74, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\Redis::SERIALIZER_IGBINARY");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "constant", NULL, 75, &_2$$3);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_igbinary"), &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_MSGPACK");
	ZEPHIR_CALL_FUNCTION(&_4, "defined", NULL, 74, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "\\Redis::SERIALIZER_MSGPACK");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "constant", NULL, 75, &_5$$4);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_msgpack"), &_6$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_JSON");
	ZEPHIR_CALL_FUNCTION(&_7, "defined", NULL, 74, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "\\Redis::SERIALIZER_JSON");
		ZEPHIR_CALL_FUNCTION(&_9$$5, "constant", NULL, 75, &_8$$5);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("redis_json"), &_9$$5, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serializer);
	zephir_fast_strtolower(&serializer, &_10);
	if (1 == zephir_array_isset(&map, &serializer)) {
		ZEPHIR_INIT_VAR(&_11$$6);
		ZEPHIR_INIT_NVAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "");
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultSerializer"), &_11$$6);
		zephir_array_fetch(&_12$$6, &map, &serializer, PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/RedisCluster.zep", 178);
		ZVAL_LONG(&_13$$6, 1);
		ZEPHIR_CALL_METHOD(NULL, connection, "setoption", NULL, 0, &_13$$6, &_12$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

