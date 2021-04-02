
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Libmemcached) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Libmemcached, phalcon, storage_adapter_libmemcached, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_libmemcached_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_libmemcached_ce, SL("options"), ZEND_ACC_PROTECTED);

	phalcon_storage_adapter_libmemcached_ce->create_object = zephir_init_properties_Phalcon_Storage_Adapter_Libmemcached;

	return SUCCESS;

}

/**
 * Libmemcached constructor.
 *
 * @param array options = [
 *     'servers' => [
 *         [
 *             'host' => '127.0.0.1',
 *             'port' => 11211,
 *             'weight' => 1
 *         ]
 *     ],
 *     'defaultSerializer' => 'Php',
 *     'lifetime' => 3600,
 *     'serializer' => null,
 *     'prefix' => ''
 * ]
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval options, _0$$3, _1$$3;
	zval *factory, factory_sub, *options_param = NULL, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
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
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ph-memc-");
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_libmemcached_ce, getThis(), "__construct", &_3, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flushes/clears the cache
 *
 * @return bool
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, clear) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "flush", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrements a stored number
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, decrement) {

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
	ZEPHIR_RETURN_CALL_METHOD(&_0, "decrement", NULL, 0, &key, &_1);
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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, delete) {

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
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "delete", NULL, 0, &key, &_1);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, get) {

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
		ZVAL_EMPTY_STRING(&key);
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
 * Returns the already connected adapter or connects to the Memcached
 * server(s)
 *
 * @return \Memcached
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, getAdapter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, client, connection, failover, options, persistentId, sasl, saslPass, saslUser, servers, serverList, _0, _1$$3, _3$$3, _4$$3, _5$$3, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&failover);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&persistentId);
	ZVAL_UNDEF(&sasl);
	ZVAL_UNDEF(&saslPass);
	ZVAL_UNDEF(&saslUser);
	ZVAL_UNDEF(&servers);
	ZVAL_UNDEF(&serverList);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&options, &_1$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "persistentId");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "ph-mcid-");
		ZEPHIR_CALL_CE_STATIC(&persistentId, phalcon_helper_arr_ce, "get", &_2, 16, &options, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		array_init(&_3$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "saslAuthData");
		ZEPHIR_CALL_CE_STATIC(&sasl, phalcon_helper_arr_ce, "get", &_2, 16, &options, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&connection);
		object_init_ex(&connection, zephir_get_internal_ce(SL("memcached")));
		ZEPHIR_CALL_METHOD(NULL, &connection, "__construct", NULL, 0, &persistentId);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&serverList, &connection, "getserverlist", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_5$$3, -1002);
		ZEPHIR_CALL_METHOD(NULL, &connection, "setoption", NULL, 0, &_5$$3, &_1$$3);
		zephir_check_call_status();
		if (zephir_fast_count_int(&serverList) < 1) {
			ZEPHIR_INIT_VAR(&_6$$4);
			array_init(&_6$$4);
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "servers");
			ZEPHIR_CALL_CE_STATIC(&servers, phalcon_helper_arr_ce, "get", &_2, 16, &options, &_7$$4, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$4);
			array_init(&_7$$4);
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "client");
			ZEPHIR_CALL_CE_STATIC(&client, phalcon_helper_arr_ce, "get", &_2, 16, &options, &_8$$4, &_7$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "user");
			ZEPHIR_INIT_VAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "");
			ZEPHIR_CALL_CE_STATIC(&saslUser, phalcon_helper_arr_ce, "get", &_2, 16, &sasl, &_8$$4, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "pass");
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "");
			ZEPHIR_CALL_CE_STATIC(&saslPass, phalcon_helper_arr_ce, "get", &_2, 16, &sasl, &_8$$4, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&failover);
			zephir_create_array(&failover, 5, 0);
			add_index_long(&failover, 14, 10);
			add_index_long(&failover, 9, 1);
			add_index_long(&failover, 21, 2);
			zephir_array_update_long(&failover, 35, &__$true, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
			add_index_long(&failover, 15, 1);
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_fast_array_merge(&_8$$4, &failover, &client);
			ZEPHIR_CPY_WRT(&client, &_8$$4);
			ZEPHIR_CALL_METHOD(&_10$$4, &connection, "setoptions", NULL, 0, &client);
			zephir_check_call_status();
			if (!(zephir_is_true(&_10$$4))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Cannot set Memcached client options", "phalcon/Storage/Adapter/Libmemcached.zep", 150);
				return;
			}
			ZEPHIR_CALL_METHOD(&_11$$4, &connection, "addservers", NULL, 0, &servers);
			zephir_check_call_status();
			if (!(zephir_is_true(&_11$$4))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "Cannot connect to the Memcached server(s)", "phalcon/Storage/Adapter/Libmemcached.zep", 154);
				return;
			}
			if (!(ZEPHIR_IS_EMPTY(&saslUser))) {
				ZEPHIR_CALL_METHOD(NULL, &connection, "setsaslauthdata", NULL, 0, &saslUser, &saslPass);
				zephir_check_call_status();
			}
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setserializer", NULL, 126, &connection);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), &connection);
	}
	RETURN_MM_MEMBER(getThis(), "adapter");

}

/**
 * Stores data in the adapter
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, getKeys) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, _0, _1;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
		ZVAL_EMPTY_STRING(&prefix);
	}
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "getallkeys", NULL, 0);
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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, connection, result, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
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
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &connection, "get", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &connection, "getresultcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG_IDENTICAL(&_0, 16));

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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, increment) {

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
	ZEPHIR_RETURN_CALL_METHOD(&_0, "increment", NULL, 0, &key, &_1);
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
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, set) {

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
 * @param \Memcached $connection
 */
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setSerializer) {

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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(connection)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	ZEPHIR_INIT_VAR(&map);
	zephir_create_array(&map, 3, 0);
	add_assoc_long_ex(&map, SL("php"), 1);
	add_assoc_long_ex(&map, SL("json"), 3);
	add_assoc_long_ex(&map, SL("igbinary"), 2);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serializer);
	zephir_fast_strtolower(&serializer, &_0);
	if (zephir_array_isset(&map, &serializer)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "");
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultSerializer"), &_1$$3);
		zephir_array_fetch(&_2$$3, &map, &serializer, PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Libmemcached.zep", 255);
		ZVAL_LONG(&_3$$3, -1003);
		ZEPHIR_CALL_METHOD(NULL, connection, "setoption", NULL, 0, &_3$$3, &_2$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Libmemcached(zend_class_entry *class_type) {

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

