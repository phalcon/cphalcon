
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Redis) {

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
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_11 = NULL;
	zval options;
	zval *factory = NULL, factory_sub, *options_param = NULL, __$null, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
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
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &factory, &options_param);

	if (!factory) {
		factory = &factory_sub;
		factory = &__$null;
	}
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
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 15, &options, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("host"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "port");
	ZVAL_LONG(&_5, 6379);
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_helper_arr_ce, "get", &_1, 15, &options, &_2, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, zephir_get_intval(&_4));
	zephir_array_update_string(&options, SL("port"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "index");
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_helper_arr_ce, "get", &_1, 15, &options, &_3, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("index"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "persistent");
	ZVAL_BOOL(&_5, 0);
	ZEPHIR_CALL_CE_STATIC(&_7, phalcon_helper_arr_ce, "get", &_1, 15, &options, &_3, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("persistent"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "auth");
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "");
	ZEPHIR_CALL_CE_STATIC(&_8, phalcon_helper_arr_ce, "get", &_1, 15, &options, &_3, &_9);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("auth"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "socket");
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "");
	ZEPHIR_CALL_CE_STATIC(&_10, phalcon_helper_arr_ce, "get", &_1, 15, &options, &_3, &_9);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("socket"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "ph-reds-");
	zephir_update_property_zval(this_ptr, SL("prefix"), &_3);
	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_redis_ce, getThis(), "__construct", &_11, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flushes/clears the cache
 *
 * @return bool
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, clear) {

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
PHP_METHOD(Phalcon_Storage_Adapter_Redis, decrement) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
		ZVAL_EMPTY_STRING(&key);
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
PHP_METHOD(Phalcon_Storage_Adapter_Redis, delete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
		ZVAL_EMPTY_STRING(&key);
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
 * @param null   $defaultValue
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, get) {

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
		ZVAL_EMPTY_STRING(&key);
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
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getAdapter) {

	zend_bool _6$$3, _8$$3;
	zval auth, connection, host, index, options, port, result, persistent, persistentid, _0, _1$$3, _7$$3, _9$$3, _10$$3, _2$$4, _3$$5, _4$$6, _5$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&persistentid);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("adapter"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&options, &_1$$3);
		ZEPHIR_INIT_VAR(&connection);
		object_init_ex(&connection, zephir_get_internal_ce(SL("redis")));
		if (zephir_has_constructor(&connection)) {
			ZEPHIR_CALL_METHOD(NULL, &connection, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&auth);
		zephir_array_fetch_string(&auth, &options, SL("auth"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 118);
		ZEPHIR_OBS_VAR(&host);
		zephir_array_fetch_string(&host, &options, SL("host"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 119);
		ZEPHIR_OBS_VAR(&port);
		zephir_array_fetch_string(&port, &options, SL("port"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 120);
		ZEPHIR_OBS_VAR(&index);
		zephir_array_fetch_string(&index, &options, SL("index"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 121);
		ZEPHIR_OBS_VAR(&persistent);
		zephir_array_fetch_string(&persistent, &options, SL("persistent"), PH_NOISY, "phalcon/Storage/Adapter/Redis.zep", 122);
		if (!(zephir_is_true(&persistent))) {
			zephir_read_property(&_2$$4, this_ptr, SL("lifetime"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&result, &connection, "connect", NULL, 0, &host, &port, &_2$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&persistentid);
			ZEPHIR_CONCAT_SV(&persistentid, "persistentid_", &index);
			zephir_read_property(&_3$$5, this_ptr, SL("lifetime"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&result, &connection, "pconnect", NULL, 0, &host, &port, &_3$$5, &persistentid);
			zephir_check_call_status();
		}
		if (!(zephir_is_true(&result))) {
			ZEPHIR_INIT_VAR(&_4$$6);
			object_init_ex(&_4$$6, phalcon_storage_exception_ce);
			ZEPHIR_INIT_VAR(&_5$$6);
			ZEPHIR_CONCAT_SVSVS(&_5$$6, "Could not connect to the Redisd server [", &host, ":", &port, "]");
			ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 6, &_5$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$6, "phalcon/Storage/Adapter/Redis.zep", 134);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_6$$3 = !(ZEPHIR_IS_EMPTY(&auth));
		if (_6$$3) {
			ZEPHIR_CALL_METHOD(&_7$$3, &connection, "auth", NULL, 0, &auth);
			zephir_check_call_status();
			_6$$3 = !zephir_is_true(&_7$$3);
		}
		if (_6$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Failed to authenticate with the Redis server", "phalcon/Storage/Adapter/Redis.zep", 138);
			return;
		}
		_8$$3 = ZEPHIR_GT_LONG(&index, 0);
		if (_8$$3) {
			ZEPHIR_CALL_METHOD(&_9$$3, &connection, "select", NULL, 0, &index);
			zephir_check_call_status();
			_8$$3 = !zephir_is_true(&_9$$3);
		}
		if (_8$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Redis server selected database failed", "phalcon/Storage/Adapter/Redis.zep", 142);
			return;
		}
		zephir_read_property(&_1$$3, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_10$$3, 2);
		ZEPHIR_CALL_METHOD(NULL, &connection, "setoption", NULL, 0, &_10$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setserializer", NULL, 112, &connection);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("adapter"), &connection);
	}
	RETURN_MM_MEMBER(getThis(), "adapter");

}

/**
 * Stores data in the adapter
 *
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getKeys) {

	zval results;
	zval key, keys, _0, _1, _2, *_3, _4, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$5, _11$$5, _12$$5, _13$$5, _14$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&results);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "*");
	ZEPHIR_CALL_METHOD(&keys, &_0, "keys", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	if (!(zephir_is_true(&keys))) {
		ZEPHIR_INIT_NVAR(&_2);
		array_init(&_2);
	} else {
		ZEPHIR_CPY_WRT(&_2, &keys);
	}
	ZEPHIR_CPY_WRT(&keys, &_2);
	zephir_is_iterable(&keys, 0, "phalcon/Storage/Adapter/Redis.zep", 175);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _3);
			zephir_read_property(&_5$$3, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_6$$3, 0);
			ZVAL_LONG(&_7$$3, zephir_fast_strlen_ev(&_5$$3));
			ZEPHIR_INIT_NVAR(&_8$$3);
			zephir_substr(&_8$$3, &key, 0 , zephir_get_intval(&_7$$3), 0);
			zephir_read_property(&_9$$3, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_IDENTICAL(&_8$$3, &_9$$3)) {
				zephir_array_append(&results, &key, PH_SEPARATE, "phalcon/Storage/Adapter/Redis.zep", 171);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_10$$5, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_11$$5, 0);
				ZVAL_LONG(&_12$$5, zephir_fast_strlen_ev(&_10$$5));
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_substr(&_13$$5, &key, 0 , zephir_get_intval(&_12$$5), 0);
				zephir_read_property(&_14$$5, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_IDENTICAL(&_13$$5, &_14$$5)) {
					zephir_array_append(&results, &key, PH_SEPARATE, "phalcon/Storage/Adapter/Redis.zep", 171);
				}
			ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&results);

}

/**
 * Checks if an element exists in the cache
 *
 * @param string $key
 *
 * @return bool
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
		ZVAL_EMPTY_STRING(&key);
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
PHP_METHOD(Phalcon_Storage_Adapter_Redis, increment) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
		ZVAL_EMPTY_STRING(&key);
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
 * @param null   $ttl
 *
 * @return bool
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Redis, set) {

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
		ZVAL_EMPTY_STRING(&key);
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
PHP_METHOD(Phalcon_Storage_Adapter_Redis, setSerializer) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	ZEPHIR_INIT_VAR(&map);
	zephir_create_array(&map, 2, 0);
	add_assoc_long_ex(&map, SL("none"), 0);
	add_assoc_long_ex(&map, SL("php"), 1);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_IGBINARY");
	ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 113, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\Redis::SERIALIZER_IGBINARY");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "constant", NULL, 114, &_2$$3);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("igbinary"), &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\Redis::SERIALIZER_MSGPACK");
	ZEPHIR_CALL_FUNCTION(&_4, "defined", NULL, 113, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "\\Redis::SERIALIZER_MSGPACK");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "constant", NULL, 114, &_5$$4);
		zephir_check_call_status();
		zephir_array_update_string(&map, SL("msgpack"), &_6$$4, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_7, this_ptr, SL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serializer);
	zephir_fast_strtolower(&serializer, &_7);
	if (zephir_array_isset(&map, &serializer)) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZEPHIR_INIT_NVAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "");
		zephir_update_property_zval(this_ptr, SL("defaultSerializer"), &_8$$5);
		zephir_array_fetch(&_9$$5, &map, &serializer, PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Redis.zep", 256);
		ZVAL_LONG(&_10$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, connection, "setoption", NULL, 0, &_10$$5, &_9$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Redis(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

