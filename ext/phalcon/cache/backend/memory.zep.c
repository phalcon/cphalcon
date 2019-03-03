
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cache\Backend\Memory
 *
 * Stores content in memory. Data is lost when the request is finished
 *
 *<code>
 * use Phalcon\Cache\Backend\Memory;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data
 * $frontCache = new FrontData();
 *
 * $cache = new Memory($frontCache);
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memory, phalcon, cache_backend_memory, phalcon_cache_backend_ce, phalcon_cache_backend_memory_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_memory_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_memory_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime = NULL, lifetime_sub, __$null, lastKey, cachedContent, _1, _2, _0$$4;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime);

	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&keyName, "")) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &_0$$4, &keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	ZEPHIR_OBS_VAR(&cachedContent);
	zephir_read_property(&_1, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&cachedContent, &_1, &lastKey, 0 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&cachedContent) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_2, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "afterretrieve", NULL, 0, &cachedContent);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores cached content into the backend and stops the frontend
 *
 * @param string keyName
 * @param string content
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastKey, frontend, cachedContent, preparedContent, isBuffering, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&preparedContent);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!content) {
		content = &content_sub;
		content = &__$null;
	}
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &_0$$4, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/memory.zep", 85);
		return;
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (Z_TYPE_P(content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&cachedContent, &frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&cachedContent, content);
	}
	if (!(zephir_is_numeric(&cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, &frontend, "beforestore", NULL, 0, &cachedContent);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&preparedContent, &cachedContent);
	}
	zephir_update_property_array(this_ptr, SL("_data"), &lastKey, &preparedContent);
	ZEPHIR_CALL_METHOD(&isBuffering, &frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, &frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&isBuffering)) {
		zend_print_zval(&cachedContent, 0);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, delete) {

	zval *keyName, keyName_sub, key, data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_VV(&key, &_0, keyName);
	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (zephir_array_isset(&data, &key)) {
		zephir_array_unset(&data, &key, PH_SEPARATE);
		zephir_update_property_zval(this_ptr, SL("_data"), &data);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Query the existing cached keys.
 *
 * <code>
 * $cache->save("users-ids", [1, 2, 3]);
 * $cache->save("projects-ids", [4, 5, 6]);
 *
 * var_dump($cache->queryKeys("users")); // ["users-ids"]
 * </code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, queryKeys) {

	zend_bool _4$$4, _5$$6;
	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, data, keys, key, idx, *_0, _1;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, &data TSRMLS_CC);
	zephir_is_iterable(&keys, 1, "phalcon/cache/backend/memory.zep", 166);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&idx);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&idx, _3);
			} else {
				ZVAL_LONG(&idx, _2);
			}
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _0);
			_4$$4 = !(ZEPHIR_IS_EMPTY(&prefix));
			if (_4$$4) {
				_4$$4 = !(zephir_start_with(&key, &prefix, NULL));
			}
			if (_4$$4) {
				zephir_array_unset(&keys, &idx, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &keys, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
			zephir_check_call_status();
				_5$$6 = !(ZEPHIR_IS_EMPTY(&prefix));
				if (_5$$6) {
					_5$$6 = !(zephir_start_with(&key, &prefix, NULL));
				}
				if (_5$$6) {
					zephir_array_unset(&keys, &idx, PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CCTOR(&keys);

}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param string|int keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, exists) {

	zend_long lifetime;
	zval *keyName = NULL, keyName_sub, *lifetime_param = NULL, __$null, lastKey, _0$$4, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &_0$$4, keyName);
	}
	if (zephir_is_true(&lastKey)) {
		zephir_read_property(&_1$$5, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_1$$5, &lastKey)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Increment of given $keyName by $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, increment) {

	zend_long value;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, lastKey, prefix, cachedContent, result, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &prefix, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&cachedContent, &_0, &lastKey, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	if (!(zephir_is_true(&cachedContent))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&result, (zephir_get_numberval(&cachedContent) + value));
	zephir_update_property_array(this_ptr, SL("_data"), &lastKey, &result);
	RETURN_CCTOR(&result);

}

/**
 * Decrement of $keyName by given $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, decrement) {

	zend_long value;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, lastKey, prefix, cachedContent, result, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &prefix, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&cachedContent, &_0, &lastKey, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	if (!(zephir_is_true(&cachedContent))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&result, (zephir_get_numberval(&cachedContent) - value));
	zephir_update_property_array(this_ptr, SL("_data"), &lastKey, &result);
	RETURN_CCTOR(&result);

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, flush) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("_data"), &__$null);
	RETURN_BOOL(1);

}

/**
 * Required for interface \Serializable
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, serialize) {

	zval _1;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_frontend"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("frontend"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 50, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Required for interface \Serializable
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, unserialized, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&unserialized);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&unserialized, "unserialize", NULL, 51, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&unserialized) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unserialized data must be an array", "phalcon/cache/backend/memory.zep", 284);
		return;
	}
	zephir_array_fetch_string(&_0, &unserialized, SL("frontend"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/memory.zep", 287 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_frontend"), &_0);
	ZEPHIR_MM_RESTORE();

}

