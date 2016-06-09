
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
#include "kernel/hash.h"


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
 * $cache->save('my-data', [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get('my-data');
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memory, phalcon, cache_backend_memory, phalcon_cache_backend_ce, phalcon_cache_backend_memory_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_memory_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_memory_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	zend_class_implements(phalcon_cache_backend_memory_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Returns a cached content
 *
 * @param 	string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, *lifetime = NULL, lifetime_sub, __$null, lastKey, cachedContent, _1, _2, _0$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
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
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastKey, frontend, cachedContent, preparedContent, isBuffering, _0$$4;
	ZEPHIR_INIT_THIS();

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
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/memory.zep", 99);
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
	ZEPHIR_CALL_METHOD(&preparedContent, &frontend, "beforestore", NULL, 0, &cachedContent);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_data"), &lastKey, &preparedContent TSRMLS_CC);
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
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, delete) {

	zval *keyName, keyName_sub, key, _0, _1, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_VV(&key, &_0, keyName);
	zephir_read_property(&_1, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &key)) {
		zephir_read_property(&_2$$3, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_2$$3, &key, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Query the existing cached keys
 *
 * @param string|int prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, queryKeys) {

	zend_string *_5$$5;
	zend_ulong _4$$5;
	zval _1$$4;
	zval *prefix = NULL, prefix_sub, __$null, data, index, keys, _0$$4, _2$$5, *_3$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&prefix_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = &prefix_sub;
		prefix = &__$null;
	}


	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&keys);
		if (!(zephir_is_true(prefix))) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_array_keys(&_0$$4, &data TSRMLS_CC);
			zephir_get_arrval(&_1$$4, &_0$$4);
			ZEPHIR_CPY_WRT(&keys, &_1$$4);
		} else {
			array_init(&keys);
			ZEPHIR_INIT_VAR(&_2$$5);
			zephir_is_iterable(&data, 0, "phalcon/cache/backend/memory.zep", 166);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _4$$5, _5$$5, _3$$5)
			{
				ZEPHIR_INIT_NVAR(&index);
				if (_5$$5 != NULL) { 
					ZVAL_STR_COPY(&index, _5$$5);
				} else {
					ZVAL_LONG(&index, _4$$5);
				}
				ZEPHIR_INIT_NVAR(&_2$$5);
				ZVAL_COPY(&_2$$5, _3$$5);
				zephir_array_append(&keys, &index, PH_SEPARATE, "phalcon/cache/backend/memory.zep", 164);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&_2$$5);
			ZEPHIR_INIT_NVAR(&index);
		}
	}
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string|int keyName
 * @param  long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, exists) {

	zval *keyName = NULL, keyName_sub, *lifetime = NULL, lifetime_sub, __$null, lastKey, _0$$4, _1$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
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
 * @param  string keyName
 * @param  long lifetime
 * @return long
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, increment) {

	zval *keyName = NULL, keyName_sub, *value = NULL, value_sub, __$null, lastKey, prefix, cachedContent, result, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
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
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_INIT_VAR(&result);
	zephir_add_function(&result, &cachedContent, value);
	zephir_update_property_array(this_ptr, SL("_data"), &lastKey, &result TSRMLS_CC);
	RETURN_CCTOR(result);

}

/**
 * Decrement of $keyName by given $value
 *
 * @param  string keyName
 * @param  long value
 * @return long
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, decrement) {

	zval *keyName = NULL, keyName_sub, *value = NULL, value_sub, __$null, lastKey, prefix, cachedContent, result, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
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
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_INIT_VAR(&result);
	zephir_sub_function(&result, &cachedContent, value);
	zephir_update_property_array(this_ptr, SL("_data"), &lastKey, &result TSRMLS_CC);
	RETURN_CCTOR(result);

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, flush) {

	zval __$null;
	ZEPHIR_INIT_THIS();

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
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_frontend"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("frontend"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 65, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Required for interface \Serializable
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, unserialized, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&unserialized);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&unserialized, "unserialize", NULL, 66, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&unserialized) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Unserialized data must be an array", "phalcon/cache/backend/memory.zep", 299);
		return;
	}
	zephir_array_fetch_string(&_0, &unserialized, SL("frontend"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/memory.zep", 302 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_frontend"), &_0);
	ZEPHIR_MM_RESTORE();

}

