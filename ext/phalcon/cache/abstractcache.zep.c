
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 266, adapter);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC | PH_READONLY);
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
	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys, keys_sub, key, keysArray, result, _0, *_1, *_2, _4, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keysArray);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
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
	if (Z_TYPE_P(keys) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, keys);
		_1 = &_0;
	} else {
		_1 = keys;
	}
	zephir_is_iterable(_1, 0, "phalcon/Cache/AbstractCache.zep", 149);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _2);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_3, 0, &key);
			zephir_check_call_status();
			zephir_array_append(&keysArray, &key, PH_SEPARATE, "phalcon/Cache/AbstractCache.zep", 146);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_3, 0, &key);
				zephir_check_call_status();
				zephir_array_append(&keysArray, &key, PH_SEPARATE, "phalcon/Cache/AbstractCache.zep", 146);
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_6, "deletemultiple", NULL, 0, &keysArray);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "cache:afterDeleteMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_7, keys);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC | PH_READONLY);
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
	zend_bool _6$$3, _16$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys, keys_sub, *defaultValue = NULL, defaultValue_sub, __$null, adapterClass, connection, element, keysArray, results, serializer, _0, *_1$$3, _2$$3, *_3$$3, _5$$3, _7$$3, _8$$3, _9$$3, *_10$$6, _11$$6, *_12$$6, _15$$6, _13$$7, _17$$8;
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
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_17$$8);
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
	zephir_read_property_cached(&adapterClass, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC);
	if (zephir_instance_of_ev(&adapterClass, phalcon_cache_adapter_redis_ce)) {
		ZEPHIR_INIT_VAR(&keysArray);
		array_init(&keysArray);
		if (Z_TYPE_P(keys) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_string_to_char_array(&_2$$3, keys);
			_1$$3 = &_2$$3;
		} else {
			_1$$3 = keys;
		}
		zephir_is_iterable(_1$$3, 0, "phalcon/Cache/AbstractCache.zep", 209);
		if (Z_TYPE_P(_1$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$3), _3$$3)
			{
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_COPY(&element, _3$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_4, 0, &element);
				zephir_check_call_status();
				zephir_array_append(&keysArray, &element, PH_SEPARATE, "phalcon/Cache/AbstractCache.zep", 206);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _1$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_6$$3 = 1;
			while (1) {
				if (_6$$3) {
					_6$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _1$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_5$$3, _1$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&element, _1$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_4, 0, &element);
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
		ZEPHIR_INIT_VAR(&_7$$3);
		object_init_ex(&_7$$3, phalcon_1__closure_ce);
		zephir_update_property_zval(&_7$$3, SL("serializer"), &serializer);
		zephir_update_property_zval(&_7$$3, SL("defaultValue"), defaultValue);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_INIT_NVAR(&_8$$3);
		zephir_create_closure_bound(&_8$$3, &_7$$3, NULL, phalcon_1__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(&_9$$3, "array_map", NULL, 20, &_8$$3, &results);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&results, &_9$$3);
		ZEPHIR_CALL_FUNCTION(&_9$$3, "array_combine", NULL, 256, &keysArray, &results);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&results, &_9$$3);
	} else {
		if (Z_TYPE_P(keys) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_11$$6);
			zephir_string_to_char_array(&_11$$6, keys);
			_10$$6 = &_11$$6;
		} else {
			_10$$6 = keys;
		}
		zephir_is_iterable(_10$$6, 0, "phalcon/Cache/AbstractCache.zep", 245);
		if (Z_TYPE_P(_10$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$6), _12$$6)
			{
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_COPY(&element, _12$$6);
				ZEPHIR_CALL_METHOD(&_13$$7, this_ptr, "get", &_14, 0, &element, defaultValue);
				zephir_check_call_status();
				zephir_array_update_zval(&results, &element, &_13$$7, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _10$$6, "rewind", NULL, 0);
			zephir_check_call_status();
			_16$$6 = 1;
			while (1) {
				if (_16$$6) {
					_16$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _10$$6, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_15$$6, _10$$6, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_15$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&element, _10$$6, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_17$$8, this_ptr, "get", &_14, 0, &element, defaultValue);
					zephir_check_call_status();
					zephir_array_update_zval(&results, &element, &_17$$8, PH_COPY | PH_SEPARATE);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 266, PH_NOISY_CC | PH_READONLY);
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
	zend_string *_8;
	zend_ulong _7;
	zend_bool result = 0, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values, values_sub, *ttl = NULL, ttl_sub, __$null, key, keys, value, *_0, _1, *_2, _4, *_5, *_6, _11, _14, _9$$4, _13$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_13$$6);
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
	if (Z_TYPE_P(&keys) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &keys);
		_0 = &_1;
	} else {
		_0 = &keys;
	}
	zephir_is_iterable(_0, 0, "phalcon/Cache/AbstractCache.zep", 306);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", &_3, 0, &key);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "cache:beforeSetMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_4, &keys);
	zephir_check_call_status();
	result = 1;
	if (Z_TYPE_P(values) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_4);
		zephir_string_to_char_array(&_4, values);
		_5 = &_4;
	} else {
		_5 = values;
	}
	zephir_is_iterable(_5, 0, "phalcon/Cache/AbstractCache.zep", 315);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&key, _8);
			} else {
				ZVAL_LONG(&key, _7);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _6);
			ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "set", &_10, 0, &key, &value, ttl);
			zephir_check_call_status();
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&_9$$4)) {
				result = 0;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _5, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _5, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "set", &_10, 0, &key, &value, ttl);
				zephir_check_call_status();
				if (!ZEPHIR_IS_TRUE_IDENTICAL(&_13$$6)) {
					result = 0;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "cache:afterSetMultiple");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_14, &keys);
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
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 267, PH_NOISY_CC);
		_2 = Z_TYPE_P(&_3) != IS_NULL;
	}
	if (_2) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 267, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "eventsManager");
		ZVAL_BOOL(&_6$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "set", NULL, 0, &_5$$3, eventsManager, &_6$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 268, eventsManager);
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
	zend_bool cancellable, stopOnFalse, _1$$3;
	zval eventName_zv, *data = NULL, data_sub, *cancellable_param = NULL, *stopOnFalse_param = NULL, __$null, _0, _2$$3, _6$$3, _7$$3, _3$$4, _4$$4, _5$$4;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
		Z_PARAM_BOOL(stopOnFalse)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cancellable_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		stopOnFalse_param = ZEND_CALL_ARG(execute_data, 4);
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
	if (!stopOnFalse_param) {
		stopOnFalse = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		_1$$3 = stopOnFalse;
		if (_1$$3) {
			zephir_memory_observe(&_2$$3);
			zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC);
			_1$$3 = zephir_instance_of_ev(&_2$$3, phalcon_events_manager_ce);
		}
		if (_1$$3) {
			zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC | PH_READONLY);
			if (cancellable) {
				ZVAL_BOOL(&_4$$4, 1);
			} else {
				ZVAL_BOOL(&_4$$4, 0);
			}
			ZVAL_BOOL(&_5$$4, 1);
			ZEPHIR_RETURN_CALL_METHOD(&_3$$4, "fire", NULL, 0, &eventName_zv, this_ptr, data, &_4$$4, &_5$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC | PH_READONLY);
		if (cancellable) {
			ZVAL_BOOL(&_7$$3, 1);
		} else {
			ZVAL_BOOL(&_7$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_6$$3, "fire", NULL, 0, &eventName_zv, this_ptr, data, &_7$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

