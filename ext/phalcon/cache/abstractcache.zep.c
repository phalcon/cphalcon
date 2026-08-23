
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This component offers caching capabilities for your application.
 *
 * Event layering: cache operations can emit `cache:*` events from two layers.
 * This facade fires `cache:before*`/`cache:after*` around each operation, and
 * the underlying `Storage` adapter (whose `eventType` is `"cache"`) also fires
 * `cache:before*`/`cache:after*` for the same operation. If an events manager
 * is wired into both the facade and the adapter, a single call emits the event
 * twice (once from each object). Wire the manager into one layer only; the
 * facade is the supported source for cache-level events (it also emits the
 * multi-key `cache:*Multiple` events).
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_AbstractCache)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache, AbstractCache, phalcon, cache_abstractcache, phalcon_cache_abstractcache_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_cache_abstractcache_ce, SL("adapter"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Cache\\Adapter\\AdapterInterface"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_cache_abstractcache_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	zend_class_implements(phalcon_cache_abstractcache_ce, 1, phalcon_cache_cacheinterface_ce);
	zend_class_implements(phalcon_cache_abstractcache_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Constructor.
 *
 * @param AdapterInterface $adapter The cache adapter
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, __construct)
{
	zval *adapter, adapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_cache_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &adapter);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 265, adapter);
}

/**
 * Fetches a value from the cache.
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, get)
{
}

/**
 * Returns the current adapter
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, getAdapter)
{

	RETURN_MEMBER(getThis(), "adapter");
}

/**
 * Persists data in the cache, uniquely referenced by a key with an
 * optional expiration TTL time.
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, set)
{
}

/**
 * Checks the key. If it contains invalid characters an exception is thrown
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, checkKey)
{
	zend_class_entry *_7$$3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, exceptionClass, _1, _2, _3, _4, _5$$3, _6$$3, _8$$3;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	_0 = ZEPHIR_IS_STRING_IDENTICAL(&key_zv, "");
	if (!(_0)) {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "/[^A-Za-z0-9-_.]/");
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "/[^A-Za-z0-9-_.]/");
		zephir_preg_match(&_3, &_4, &key_zv, &_1, 0, 0 , 0 );
		_0 = zephir_is_true(&_3);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&exceptionClass, this_ptr, "getexceptionclass", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_fetch_safe_class(&_6$$3, &exceptionClass);
		_7$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6$$3), Z_STRLEN_P(&_6$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_7$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_5$$3, _7$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_5$$3);
		zephir_check_call_status();
		if (zephir_has_constructor(&_5$$3)) {
			ZEPHIR_INIT_VAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "The key contains invalid characters");
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 0, &_8$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_5$$3, "phalcon/Cache/AbstractCache.zep", 84);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks the key. If it contains invalid characters an exception is thrown
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, checkKeys)
{
	zend_class_entry *_3$$3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys, keys_sub, exceptionClass, _1$$3, _2$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(keys)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &keys);
	_0 = Z_TYPE_P(keys) == IS_ARRAY;
	if (!(_0)) {
		_0 = zephir_zval_is_traversable(keys);
	}
	if (!(_0)) {
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
			ZVAL_STRING(&_4$$3, "The keys need to be an array or instance of Traversable");
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_4$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_1$$3, "phalcon/Cache/AbstractCache.zep", 100);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Wipes clean the entire cache's keys.
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, doClear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 265, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "clear", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Delete an item from the cache by its unique key.
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, doDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, result, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache:beforeDelete");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &key_zv);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 265, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_1, "delete", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "cache:afterDelete");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &key_zv);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Deletes multiple cache items in a single operation.
 *
 * @phpstan-param iterable<array-key, string> $keys
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, doDeleteMultiple)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys, keys_sub, key, keysArray, result, _0, *_1, _3, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keysArray);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(keys)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &keys);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkeys", NULL, 0, keys);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache:beforeDeleteMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, keys);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&keysArray);
	array_init(&keysArray);
	zephir_is_iterable(keys, 0, "phalcon/Cache/AbstractCache.zep", 149);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_2, 0, &key);
			zephir_check_call_status();
			zephir_array_append(&keysArray, &key, PH_SEPARATE, "phalcon/Cache/AbstractCache.zep", 146);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, keys, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, keys, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, keys, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_2, 0, &key);
				zephir_check_call_status();
				zephir_array_append(&keysArray, &key, PH_SEPARATE, "phalcon/Cache/AbstractCache.zep", 146);
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 265, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_5, "deletemultiple", NULL, 0, &keysArray);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "cache:afterDeleteMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, keys);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Fetches a value from the cache.
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, doGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, __$null, result, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache:beforeGet");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &key_zv);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 265, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_1, "get", NULL, 0, &key_zv, defaultValue);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "cache:afterGet");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &key_zv);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Obtains multiple cache items by their unique keys.
 *
 * @phpstan-param iterable<array-key, string> $keys
 *
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, doGetMultiple)
{
	zend_bool _4$$3, _11$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys, keys_sub, *defaultValue = NULL, defaultValue_sub, __$null, adapterClass, connection, element, keysArray, results, serializer, _0, *_1$$3, _3$$3, _5$$3, _6$$3, *_7$$6, _10$$6, _8$$7, _12$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&adapterClass);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&keysArray);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_12$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(keys)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &keys, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkeys", NULL, 0, keys);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache:beforeGetMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, keys);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	zephir_memory_observe(&adapterClass);
	zephir_read_property_cached(&adapterClass, this_ptr, _zephir_prop_0, 265, PH_NOISY_CC);
	if (zephir_instance_of_ev(&adapterClass, phalcon_cache_adapter_redis_ce)) {
		ZEPHIR_INIT_VAR(&keysArray);
		array_init(&keysArray);
		zephir_is_iterable(keys, 0, "phalcon/Cache/AbstractCache.zep", 209);
		if (Z_TYPE_P(keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_COPY(&element, _1$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_2, 0, &element);
				zephir_check_call_status();
				zephir_array_append(&keysArray, &element, PH_SEPARATE, "phalcon/Cache/AbstractCache.zep", 206);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, keys, "rewind", NULL, 0);
			zephir_check_call_status();
			_4$$3 = 1;
			while (1) {
				if (_4$$3) {
					_4$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, keys, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_3$$3, keys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&element, keys, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_2, 0, &element);
					zephir_check_call_status();
					zephir_array_append(&keysArray, &element, PH_SEPARATE, "phalcon/Cache/AbstractCache.zep", 206);
			}
		}
		ZEPHIR_INIT_NVAR(&element);
		ZEPHIR_CALL_METHOD(&serializer, &adapterClass, "getserializer", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&connection, &adapterClass, "getadapter", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&results, &connection, "mget", NULL, 0, &keysArray);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		zephir_create_closure_ex(&_5$$3, NULL, phalcon_1__closure_ce, SL("__invoke"));
		zephir_update_static_property_ce(phalcon_1__closure_ce, ZEND_STRL("serializer"), &serializer);
		zephir_update_static_property_ce(phalcon_1__closure_ce, ZEND_STRL("defaultValue"), defaultValue);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "array_map", NULL, 20, &_5$$3, &results);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&results, &_6$$3);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "array_combine", NULL, 251, &keysArray, &results);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&results, &_6$$3);
	} else {
		zephir_is_iterable(keys, 0, "phalcon/Cache/AbstractCache.zep", 245);
		if (Z_TYPE_P(keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _7$$6)
			{
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_COPY(&element, _7$$6);
				ZEPHIR_CALL_METHOD(&_8$$7, this_ptr, "get", &_9, 0, &element, defaultValue);
				zephir_check_call_status();
				zephir_array_update_zval(&results, &element, &_8$$7, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, keys, "rewind", NULL, 0);
			zephir_check_call_status();
			_11$$6 = 1;
			while (1) {
				if (_11$$6) {
					_11$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, keys, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_10$$6, keys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&element, keys, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "get", &_9, 0, &element, defaultValue);
					zephir_check_call_status();
					zephir_array_update_zval(&results, &element, &_12$$8, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&element);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "cache:afterGetMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, keys);
	zephir_check_call_status();
	RETURN_CCTOR(&results);
}

/**
 * Determines whether an item is present in the cache.
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, doHas)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, result, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache:beforeHas");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &key_zv);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 265, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_1, "has", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "cache:afterHas");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &key_zv);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Persists data in the cache, uniquely referenced by a key with an optional
 * expiration TTL time.
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, doSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub, *ttl = NULL, ttl_sub, __$null, result, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache:beforeSet");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &key_zv);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 265, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_1, "set", NULL, 0, &key_zv, value, ttl);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "cache:afterSet");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &key_zv);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Persists a set of key => value pairs in the cache, with an optional TTL.
 *
 * @phpstan-param iterable<string, mixed> $values
 * @phpstan-param DateInterval|int|null   $ttl
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, doSetMultiple)
{
	zend_string *_5;
	zend_ulong _4;
	zend_bool result = 0, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values, values_sub, *ttl = NULL, ttl_sub, __$null, key, keys, value, *_0, _2, *_3, _8, _6$$4, _10$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(ttl)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &values, &ttl);
	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkeys", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, values);
	zephir_is_iterable(&keys, 0, "phalcon/Cache/AbstractCache.zep", 306);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_1, 0, &key);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "cache:beforeSetMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_2, &keys);
	zephir_check_call_status();
	result = 1;
	zephir_is_iterable(values, 0, "phalcon/Cache/AbstractCache.zep", 315);
	if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(values), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "set", &_7, 0, &key, &value, ttl);
			zephir_check_call_status();
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&_6$$4)) {
				result = 0;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, values, "rewind", NULL, 0);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_8, values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "set", &_7, 0, &key, &value, ttl);
				zephir_check_call_status();
				if (!ZEPHIR_IS_TRUE_IDENTICAL(&_10$$6)) {
					result = 0;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "cache:afterSetMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_2, &keys);
	zephir_check_call_status();
	RETURN_MM_BOOL(result);
}

/**
 * Returns the exception class that will be used for exceptions thrown
 *
 * @return class-string<Throwable>
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, getExceptionClass)
{
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, setEventsManager)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0, _1, _3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eventsManager);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "container");
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 10, this_ptr, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		zephir_memory_observe(&_3);
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC);
		_2 = Z_TYPE_P(&_3) != IS_NULL;
	}
	if (_2) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "eventsManager");
		ZVAL_BOOL(&_6$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "set", NULL, 0, &_5$$3, eventsManager, &_6$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 267, eventsManager);
	ZEPHIR_MM_RESTORE();
}

/**
 * Helper method to fire an event
 * 
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Cache_AbstractCache, fireManagerEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancellable;
	zval eventName_zv, *data = NULL, data_sub, *cancellable_param = NULL, __$null, _0, _1$$3, _2$$3;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cancellable_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancellable_param) {
		cancellable = 1;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 267, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 267, PH_NOISY_CC | PH_READONLY);
		if (cancellable) {
			ZVAL_BOOL(&_2$$3, 1);
		} else {
			ZVAL_BOOL(&_2$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "fire", NULL, 0, &eventName_zv, this_ptr, data, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

