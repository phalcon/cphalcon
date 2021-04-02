
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
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
 * This component offers caching capabilities for your application.
 * Phalcon\Cache implements PSR-16.
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Cache, phalcon, cache, phalcon_cache_method_entry, 0);

	/**
	 * The adapter
	 *
	 * @var AdapterInterface
	 */
	zend_declare_property_null(phalcon_cache_ce, SL("adapter"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_cache_ce, 1, zephir_get_internal_ce(SL("psr\\simplecache\\cacheinterface")));
	return SUCCESS;

}

/**
 * The adapter
 */
PHP_METHOD(Phalcon_Cache, getAdapter) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "adapter");

}

/**
 * Constructor.
 *
 * @param AdapterInterface  adapter The cache adapter
 */
PHP_METHOD(Phalcon_Cache, __construct) {

	zval *adapter, adapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_cache_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &adapter);



	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), adapter);

}

/**
 * Wipes clean the entire cache's keys.
 *
 * @return bool True on success and false on failure.
 */
PHP_METHOD(Phalcon_Cache, clear) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "clear", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Delete an item from the cache by its unique key.
 *
 * @param string $key The unique cache key of the item to delete.
 *
 * @return bool True if the item was successfully removed. False if there was an error.
 *
 * @throws InvalidArgumentException MUST be thrown if the $key string is not a legal value.
 */
PHP_METHOD(Phalcon_Cache, delete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", NULL, 0, key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "delete", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes multiple cache items in a single operation.
 *
 * @param iterable $keys A list of string-based keys to be deleted.
 *
 * @return bool True if the items were successfully removed. False if there was an error.
 *
 * @throws InvalidArgumentException MUST be thrown if $keys is neither an array nor a Traversable, or if any of the $keys are not a legal value.
 */
PHP_METHOD(Phalcon_Cache, deleteMultiple) {

	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys, keys_sub, key, *_0, _1, _2$$3, _3$$3, _4$$5, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(keys)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkeys", NULL, 0, keys);
	zephir_check_call_status();
	result = 1;
	zephir_is_iterable(keys, 0, "phalcon/Cache.zep", 91);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _0);
			zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_3$$3, &_2$$3, "delete", NULL, 0, &key);
			zephir_check_call_status();
			if (!(zephir_is_true(&_3$$3))) {
				result = 0;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, keys, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_5$$5, &_4$$5, "delete", NULL, 0, &key);
				zephir_check_call_status();
				if (!(zephir_is_true(&_5$$5))) {
					result = 0;
				}
			ZEPHIR_CALL_METHOD(NULL, keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(result);

}

/**
 * Fetches a value from the cache.
 *
 * @param string $key          The unique key of this item in the cache.
 * @param mixed  $defaultValue Default value to return if the key does not exist.
 *
 * @return mixed The value of the item from the cache, or $default in case of cache miss.
 *
 * @throws InvalidArgumentException MUST be thrown if the $key string is not a legal value.
 */
PHP_METHOD(Phalcon_Cache, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", NULL, 0, key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, key, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Obtains multiple cache items by their unique keys.
 *
 * @param iterable $keys         A list of keys that can obtained in a single operation.
 * @param mixed    $defaultValue Default value to return for keys that do not exist.
 *
 * @return iterable A list of key => value pairs. Cache keys that do not exist or are stale will have $default as value.
 *
 * @throws InvalidArgumentException MUST be thrown if $keys is neither an array nor a Traversable, or if any of the $keys are not a legal value.
 */
PHP_METHOD(Phalcon_Cache, getMultiple) {

	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys, keys_sub, *defaultValue = NULL, defaultValue_sub, __$null, element, *_0, _1, _2$$3, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&results);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(keys)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keys, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkeys", NULL, 0, keys);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	zephir_is_iterable(keys, 0, "phalcon/Cache.zep", 133);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _0)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "get", &_3, 0, &element, defaultValue);
			zephir_check_call_status();
			zephir_array_update_zval(&results, &element, &_2$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, keys, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "get", &_3, 0, &element, defaultValue);
				zephir_check_call_status();
				zephir_array_update_zval(&results, &element, &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	RETURN_CTOR(&results);

}

/**
 * Determines whether an item is present in the cache.
 *
 * @param string $key The cache item key.
 *
 * @return bool
 *
 * @throws InvalidArgumentException MUST be thrown if the $key string is not a legal value.
 */
PHP_METHOD(Phalcon_Cache, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", NULL, 0, key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Persists data in the cache, uniquely referenced by a key with an optional expiration TTL time.
 *
 * @param string                 $key   The key of the item to store.
 * @param mixed                  $value The value of the item to store. Must be serializable.
 * @param null|int|\DateInterval $ttl   Optional. The TTL value of this item. If no value is sent and
 *                                      the driver supports TTL then the library may set a default value
 *                                      for it or let the driver take care of that.
 *
 * @return bool True on success and false on failure.
 *
 * @throws InvalidArgumentException MUST be thrown if the $key string is not a legal value.
 */
PHP_METHOD(Phalcon_Cache, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *value, value_sub, *ttl = NULL, ttl_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(ttl)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &value, &ttl);

	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkey", NULL, 0, key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "set", NULL, 0, key, value, ttl);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Persists a set of key => value pairs in the cache, with an optional TTL.
 *
 * @param iterable               $values A list of key => value pairs for a multiple-set operation.
 * @param null|int|\DateInterval $ttl    Optional. The TTL value of this item. If no value is sent and
 *                                       the driver supports TTL then the library may set a default value
 *                                       for it or let the driver take care of that.
 *
 * @return bool True on success and false on failure.
 *
 * @throws InvalidArgumentException MUST be thrown if $values is neither an array nor a Traversable, or if any of the $values are not a legal value.
 */
PHP_METHOD(Phalcon_Cache, setMultiple) {

	zend_string *_3;
	zend_ulong _2;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values, values_sub, *ttl = NULL, ttl_sub, __$null, key, value, *_0, _1, _4$$3, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(ttl)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values, &ttl);

	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkkeys", NULL, 0, values);
	zephir_check_call_status();
	result = 1;
	zephir_is_iterable(values, 0, "phalcon/Cache.zep", 198);
	if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(values), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "set", &_5, 0, &key, &value, ttl);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$3))) {
				result = 0;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "set", &_5, 0, &key, &value, ttl);
				zephir_check_call_status();
				if (!(zephir_is_true(&_6$$5))) {
					result = 0;
				}
			ZEPHIR_CALL_METHOD(NULL, values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(result);

}

/**
 * Checks the key. If it contains invalid characters an exception is thrown
 */
PHP_METHOD(Phalcon_Cache, checkKey) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key = NULL, key_sub, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	zephir_get_strval(&_0, key);
	ZEPHIR_CPY_WRT(key, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/[^A-Za-z0-9-_.]/");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/[^A-Za-z0-9-_.]/");
	zephir_preg_match(&_3, &_4, key, &_1, 0, 0 , 0 );
	if (zephir_is_true(&_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_invalidargumentexception_ce, "The key contains invalid characters", "phalcon/Cache.zep", 211);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks the key. If it contains invalid characters an exception is thrown
 */
PHP_METHOD(Phalcon_Cache, checkKeys) {

	zend_bool _0;
	zval *keys, keys_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(keys)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &keys);



	_0 = Z_TYPE_P(keys) == IS_ARRAY;
	if (!(_0)) {
		_0 = zephir_zval_is_traversable(keys);
	}
	if (!(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_cache_exception_invalidargumentexception_ce, "The keys need to be an array or instance of Traversable", "phalcon/Cache.zep", 223);
		return;
	}

}

