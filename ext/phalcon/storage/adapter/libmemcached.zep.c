
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
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
 * Libmemcached adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Libmemcached)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Libmemcached, phalcon, storage_adapter_libmemcached, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_libmemcached_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_libmemcached_ce, SL("prefix"), "ph-memc-", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Libmemcached constructor.
 *
 * @param SerializerFactory $factory
 * @param array             $options
 *
 * @throws SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _0$$3, _1$$3;
	zval *factory, factory_sub, *options_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
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
	if (!(zephir_array_isset_string(&options, SL("servers")))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 3, 0);
		add_assoc_stringl_ex(&_1$$3, SL("host"), SL("127.0.0.1"));
		add_assoc_long_ex(&_1$$3, SL("port"), 11211);
		add_assoc_long_ex(&_1$$3, SL("weight"), 1);
		zephir_array_update_long(&_0$$3, 0, &_1$$3, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
		zephir_array_update_string(&options, SL("servers"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_libmemcached_ce, getThis(), "__construct", NULL, 0, factory, &options);
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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "flush", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the already connected adapter or connects to the Memcached
 * server(s)
 *
 * @return \Memcached|null
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, getAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, client, connection, failover, options, persistentId, sasl, saslUser, saslPass, serverList, servers, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&failover);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&persistentId);
	ZVAL_UNDEF(&sasl);
	ZVAL_UNDEF(&saslUser);
	ZVAL_UNDEF(&saslPass);
	ZVAL_UNDEF(&serverList);
	ZVAL_UNDEF(&servers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&options, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "persistentId");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "ph-mcid-");
		ZEPHIR_CALL_METHOD(&persistentId, this_ptr, "getarrval", NULL, 0, &options, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		array_init(&_2$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "saslAuthData");
		ZEPHIR_CALL_METHOD(&sasl, this_ptr, "getarrval", NULL, 0, &options, &_3$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&connection);
		object_init_ex(&connection, zephir_get_internal_ce(SL("memcached")));
		ZEPHIR_CALL_METHOD(NULL, &connection, "__construct", NULL, 0, &persistentId);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&serverList, &connection, "getserverlist", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, -1002);
		ZEPHIR_CALL_METHOD(NULL, &connection, "setoption", NULL, 0, &_4$$3, &_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&serverList)) {
			ZEPHIR_INIT_VAR(&_5$$4);
			array_init(&_5$$4);
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "servers");
			ZEPHIR_CALL_METHOD(&servers, this_ptr, "getarrval", NULL, 0, &options, &_6$$4, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_6$$4);
			array_init(&_6$$4);
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "client");
			ZEPHIR_CALL_METHOD(&client, this_ptr, "getarrval", NULL, 0, &options, &_7$$4, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "user");
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "");
			ZEPHIR_CALL_METHOD(&saslUser, this_ptr, "getarrval", NULL, 0, &sasl, &_7$$4, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "pass");
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "");
			ZEPHIR_CALL_METHOD(&saslPass, this_ptr, "getarrval", NULL, 0, &sasl, &_7$$4, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&failover);
			zephir_create_array(&failover, 5, 0);
			add_index_long(&failover, 14, 50);
			add_index_long(&failover, 9, 1);
			add_index_long(&failover, 21, 2);
			zephir_array_update_long(&failover, 35, &__$true, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
			add_index_long(&failover, 15, 1);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "array_replace", NULL, 116, &failover, &client);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&client, &_9$$4);
			ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "setoptions", NULL, 117, &connection, &client);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10$$4, &_9$$4, "setservers", NULL, 118, &connection, &servers);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_10$$4, "setsasl", NULL, 119, &connection, &saslUser, &saslPass);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setserializer", NULL, 120, &connection);
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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, getKeys)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix_zv, _0, _1;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!prefix) {
		prefix = zend_string_init(ZEND_STRL(""), 0);
		ZVAL_STR(&prefix_zv, prefix);
	} else {
	ZVAL_STR_COPY(&prefix_zv, prefix);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "getallkeys", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfilteredkeys", NULL, 0, &_1, &prefix_zv);
	zephir_check_call_status();
	RETURN_MM();
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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setForever)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub, result, _0, _1, _2, _3;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(&result, &_0, "set", NULL, 0, &key_zv, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	if (((Z_TYPE_P(&result) == IS_TRUE || Z_TYPE_P(&result) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&_3, &result);
	} else {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_BOOL(&_3, 0);
	}
	RETURN_CCTOR(&_3);
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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doDecrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value_param = NULL, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	ZVAL_STR_COPY(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "decrement", NULL, 0, &key_zv, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Deletes data from the adapter
 *
 * @param string $key
 *
 * @return bool
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "delete", NULL, 0, &key_zv, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Deletes multiple keys from Memcached using a single deleteMulti call
 *
 * @param array $keys
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doDeleteMultiple)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, result, value, _0, *_1, _2;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(keys, keys_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &keys_param);
	zephir_get_arrval(&keys, keys_param);
	if (ZEPHIR_IS_EMPTY(&keys)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &_0, "deletemulti", NULL, 0, &keys);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	zephir_is_iterable(&result, 0, "phalcon/Storage/Adapter/Libmemcached.zep", 204);
	if (Z_TYPE_P(&result) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&result), _1)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &result, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &result, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &result, "current", NULL, 0);
			zephir_check_call_status();
				if (!ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
					RETURN_MM_BOOL(0);
				}
			ZEPHIR_CALL_METHOD(NULL, &result, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_BOOL(1);
}

/**
 * Checks if an element exists in the cache
 *
 * @param string $key
 *
 * @return bool
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doHas)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, connection, code;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&code);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "get", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&code, &connection, "getresultcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG_IDENTICAL(&code, 16));
}

/**
 * Increments a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doIncrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value_param = NULL, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	ZVAL_STR_COPY(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "increment", NULL, 0, &key_zv, &_1);
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
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doSet)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub, *ttl = NULL, ttl_sub, __$null, result, _1, _2, _3, _4;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &_1, "set", NULL, 0, &key_zv, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	if (((Z_TYPE_P(&result) == IS_TRUE || Z_TYPE_P(&result) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&_4, &result);
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_BOOL(&_4, 0);
	}
	RETURN_CCTOR(&_4);
}

/**
 * @param \Memcached $connection
 * @param array      $client
 *
 * @return Libmemcached
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval client;
	zval *connection, connection_sub, *client_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&client);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("memcached")))
		ZEPHIR_Z_PARAM_ARRAY(client, client_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &connection, &client_param);
	zephir_get_arrval(&client, client_param);
	ZEPHIR_CALL_METHOD(&_0, connection, "setoptions", NULL, 0, &client);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Cannot set Memcached client options", "phalcon/Storage/Adapter/Libmemcached.zep", 286);
		return;
	}
	RETURN_THIS();
}

/**
 * @param \Memcached $connection
 * @param string     $saslUser
 * @param string     $saslPass
 *
 * @return Libmemcached
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setSasl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *saslUser = NULL, *saslPass = NULL;
	zval *connection, connection_sub, saslUser_zv, saslPass_zv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&saslUser_zv);
	ZVAL_UNDEF(&saslPass_zv);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("memcached")))
		Z_PARAM_STR(saslUser)
		Z_PARAM_STR(saslPass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	connection = ZEND_CALL_ARG(execute_data, 1);
	ZVAL_STR_COPY(&saslUser_zv, saslUser);
	ZVAL_STR_COPY(&saslPass_zv, saslPass);
	if (1 != ZEPHIR_IS_EMPTY(&saslUser_zv)) {
		ZEPHIR_CALL_METHOD(NULL, connection, "setsaslauthdata", NULL, 0, &saslUser_zv, &saslPass_zv);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Checks the serializer. If it is a supported one it is set, otherwise
 * the custom one is set.
 *
 * @param \Memcached $connection
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setSerializer)
{
	zval map;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, serializer, _0, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&map);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("memcached")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &connection);
	ZEPHIR_INIT_VAR(&map);
	zephir_create_array(&map, 3, 0);
	add_assoc_long_ex(&map, SL("memcached_igbinary"), 2);
	add_assoc_long_ex(&map, SL("memcached_json"), 3);
	add_assoc_long_ex(&map, SL("memcached_php"), 1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serializer);
	zephir_fast_strtolower(&serializer, &_0);
	if (zephir_array_isset(&map, &serializer)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "");
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultSerializer"), &_1$$3);
		zephir_array_fetch(&_2$$3, &map, &serializer, PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Libmemcached.zep", 332);
		ZVAL_LONG(&_3$$3, -1003);
		ZEPHIR_CALL_METHOD(NULL, connection, "setoption", NULL, 0, &_3$$3, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @param \Memcached $connection
 * @param array      $servers
 *
 * @return Libmemcached
 * @throws StorageException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setServers)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval servers;
	zval *connection, connection_sub, *servers_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&servers);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(connection, zephir_get_internal_ce(SL("memcached")))
		ZEPHIR_Z_PARAM_ARRAY(servers, servers_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &connection, &servers_param);
	zephir_get_arrval(&servers, servers_param);
	ZEPHIR_CALL_METHOD(&_0, connection, "addservers", NULL, 0, &servers);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Cannot connect to the Memcached server(s)", "phalcon/Storage/Adapter/Libmemcached.zep", 350);
		return;
	}
	RETURN_THIS();
}

