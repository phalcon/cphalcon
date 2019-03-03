
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/iterator.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cache\Backend\Apcu
 *
 * Allows to cache output fragments, PHP data and raw data using an APCu backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Apcu;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * $cache = new Apcu(
 *     $frontCache,
 *     [
 *         "prefix" => "app-data",
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Apcu) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Apcu, phalcon, cache_backend_apcu, phalcon_cache_backend_ce, phalcon_cache_backend_apcu_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime = NULL, lifetime_sub, __$null, prefixedKey, cachedContent, _0, _1;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime);

	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_SVV(&prefixedKey, "_PHCA", &_0, &keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZEPHIR_CALL_FUNCTION(&cachedContent, "apcu_fetch", NULL, 77, &prefixedKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "afterretrieve", NULL, 0, &cachedContent);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores cached content into the APCu backend and stops the frontend
 *
 * @param string|int keyName
 * @param string content
 * @param int lifetime
 * @param bool stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastKey, frontend, cachedContent, preparedContent, ttl, isBuffering, success, _0$$4;
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
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&success);
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
		ZEPHIR_CPY_WRT(lifetime, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(lifetime);
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
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCA", &_0$$4, keyName);
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/apcu.zep", 86);
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
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_NVAR(lifetime);
		zephir_read_property(lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (Z_TYPE_P(lifetime) == IS_NULL) {
			ZEPHIR_CALL_METHOD(&ttl, &frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&ttl, lifetime);
			zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
		}
	} else {
		ZEPHIR_CPY_WRT(&ttl, lifetime);
	}
	ZEPHIR_CALL_FUNCTION(&success, "apcu_store", NULL, 78, &lastKey, &preparedContent, &ttl);
	zephir_check_call_status();
	if (!(zephir_is_true(&success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in APCu", "phalcon/cache/backend/apcu.zep", 123);
		return;
	}
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
	RETURN_CCTOR(&success);

}

/**
 * Increment of a given key, by number $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, prefixedKey, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_SVV(&prefixedKey, "_PHCA", &_0, keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_inc", NULL, 96, &prefixedKey, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrement of a given key, by number $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, lastKey, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&lastKey);
	ZEPHIR_CONCAT_SVV(&lastKey, "_PHCA", &_0, keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_dec", NULL, 97, &lastKey, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes a value from the cache by its key
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVV(&_1, "_PHCA", &_0, keyName);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_delete", NULL, 98, &_1);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Cache_Backend_Apcu, queryKeys) {

	zend_object_iterator *_4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, prefixPattern, apc, keys, key, _1, _2, _5, _3$$6, _6$$8, _7$$8;
	zval prefix, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&prefixPattern);
	ZVAL_UNDEF(&apc);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(&prefixPattern);
	if (ZEPHIR_IS_EMPTY(&prefix)) {
		ZVAL_STRING(&prefixPattern, "/^_PHCA/");
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_CONCAT_SVS(&_0$$4, "/^_PHCA", &prefix, "/");
		ZEPHIR_CPY_WRT(&prefixPattern, &_0$$4);
	}
	ZEPHIR_INIT_VAR(&keys);
	array_init(&keys);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "APCUIterator");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "APCIterator");
	if (zephir_class_exists(&_1, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&apc);
		object_init_ex(&apc, zephir_get_internal_ce(SL("apcuiterator")));
		ZEPHIR_CALL_METHOD(NULL, &apc, "__construct", NULL, 0, &prefixPattern);
		zephir_check_call_status();
	} else if (zephir_class_exists(&_2, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&apc);
		object_init_ex(&apc, zephir_get_internal_ce(SL("apciterator")));
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "user");
		ZEPHIR_CALL_METHOD(NULL, &apc, "__construct", NULL, 0, &_3$$6, &prefixPattern);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&apc) != IS_OBJECT) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_5);
	_4 = zephir_get_iterator(&apc TSRMLS_CC);
	_4->funcs->rewind(_4 TSRMLS_CC);
	for (;_4->funcs->valid(_4 TSRMLS_CC) == SUCCESS && !EG(exception); _4->funcs->move_forward(_4 TSRMLS_CC)) {
		ZEPHIR_GET_IMKEY(key, _4);
		{
			ZEPHIR_ITERATOR_COPY(&_5, _4);
		}
		ZVAL_LONG(&_6$$8, 5);
		ZEPHIR_INIT_NVAR(&_7$$8);
		zephir_substr(&_7$$8, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&keys, &_7$$8, PH_SEPARATE, "phalcon/cache/backend/apcu.zep", 213);
	}
	zend_iterator_dtor(_4);
	RETURN_CCTOR(&keys);

}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string|int keyName
 * @param  int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, exists) {

	zval _1$$3;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *lifetime_param = NULL, __$null, lastKey, _0$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_1$$3);

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


	ZEPHIR_INIT_VAR(&lastKey);
	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, SL("_lastKey"), PH_NOISY_CC);
		zephir_get_strval(&_1$$3, &_0$$3);
		ZEPHIR_CPY_WRT(&lastKey, &_1$$3);
	} else {
		zephir_read_property(&_2$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCA", &_2$$4, keyName);
	}
	if (ZEPHIR_IS_EMPTY(&lastKey)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_exists", NULL, 99, &lastKey);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 *
 * <code>
 * use Phalcon\Cache\Backend\Apcu;
 *
 * $cache = new Apcu($frontCache, ["prefix" => "app-data"]);
 *
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // 'my-data' and all other used keys are deleted
 * $cache->flush();
 * </code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, flush) {

	zend_object_iterator *_4;
	zval item, prefixPattern, apc, _0, _1, _2, _3$$4, _5$$6;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&prefixPattern);
	ZVAL_UNDEF(&apc);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&apc);
	ZVAL_NULL(&apc);
	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixPattern);
	ZEPHIR_CONCAT_SVS(&prefixPattern, "/^_PHCA", &_0, "/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "APCUIterator");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "APCIterator");
	if (zephir_class_exists(&_1, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&apc);
		object_init_ex(&apc, zephir_get_internal_ce(SL("apcuiterator")));
		ZEPHIR_CALL_METHOD(NULL, &apc, "__construct", NULL, 0, &prefixPattern);
		zephir_check_call_status();
	} else if (zephir_class_exists(&_2, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&apc);
		object_init_ex(&apc, zephir_get_internal_ce(SL("apciterator")));
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "user");
		ZEPHIR_CALL_METHOD(NULL, &apc, "__construct", NULL, 0, &_3$$4, &prefixPattern);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&apc) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	_4 = zephir_get_iterator(&apc TSRMLS_CC);
	_4->funcs->rewind(_4 TSRMLS_CC);
	for (;_4->funcs->valid(_4 TSRMLS_CC) == SUCCESS && !EG(exception); _4->funcs->move_forward(_4 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _4);
		}
		zephir_array_fetch_string(&_5$$6, &item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/apcu.zep", 274 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "apcu_delete", &_6, 98, &_5$$6);
		zephir_check_call_status();
	}
	zend_iterator_dtor(_4);
	RETURN_MM_BOOL(1);

}

