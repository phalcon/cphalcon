
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

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, *lastKey = NULL, *cachedContent = NULL, *_1, *_2, *_0$$4;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(keyName, "")) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0$$4, keyName);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(cachedContent);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&cachedContent, _1, lastKey, 0 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(cachedContent) == IS_NULL) {
		RETURN_MM_NULL();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_2, "afterretrieve", NULL, 0, cachedContent);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores cached content into the backend and stops the frontend
 *
 * @param string keyName
 * @param string content
 * @param int lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend = NULL, *cachedContent = NULL, *preparedContent = NULL, *isBuffering = NULL, *_0$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0$$4, keyName);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/memory.zep", 95);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (Z_TYPE_P(content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, 0, cachedContent);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(preparedContent, cachedContent);
	}
	zephir_update_property_array(this_ptr, SL("_data"), lastKey, preparedContent TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(isBuffering)) {
		zend_print_zval(cachedContent, 0);
	}
	if (0) {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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

	zval *keyName, *key = NULL, *data = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VV(key, _0, keyName);
	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (zephir_array_isset(data, key)) {
		zephir_array_unset(&data, key, PH_SEPARATE);
		zephir_update_property_this(getThis(), SL("_data"), data TSRMLS_CC);
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

	zend_bool _3$$4;
	HashTable *_1;
	HashPosition _0;
	zval *prefix_param = NULL, *data = NULL, *keys = NULL, *key = NULL, *idx = NULL, **_2;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(data) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(keys);
	zephir_array_keys(keys, data TSRMLS_CC);
	zephir_is_iterable(keys, &_1, &_0, 1, 0, "phalcon/cache/backend/memory.zep", 177);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(idx, _1, _0);
		ZEPHIR_GET_HVALUE(key, _2);
		_3$$4 = !(ZEPHIR_IS_EMPTY(prefix));
		if (_3$$4) {
			_3$$4 = !(zephir_start_with(key, prefix, NULL));
		}
		if (_3$$4) {
			zephir_array_unset(&keys, idx, PH_SEPARATE);
		}
	}
	zend_hash_destroy(_1);
	FREE_HASHTABLE(_1);
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param string|int keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, exists) {

	zend_long lifetime;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey = NULL, *_0$$4, *_1$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0$$4, keyName);
	}
	if (zephir_is_true(lastKey)) {
		_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		if (zephir_array_isset(_1$$5, lastKey)) {
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
	zval *keyName = NULL, *value_param = NULL, *lastKey = NULL, *prefix = NULL, *cachedContent = NULL, *result = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&cachedContent, _0, lastKey, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(result);
	ZVAL_LONG(result, (zephir_get_numberval(cachedContent) + value));
	zephir_update_property_array(this_ptr, SL("_data"), lastKey, result TSRMLS_CC);
	RETURN_CCTOR(result);

}

/**
 * Decrement of $keyName by given $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, decrement) {

	zend_long value;
	zval *keyName = NULL, *value_param = NULL, *lastKey = NULL, *prefix = NULL, *cachedContent = NULL, *result = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&cachedContent, _0, lastKey, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(result);
	ZVAL_LONG(result, (zephir_get_numberval(cachedContent) - value));
	zephir_update_property_array(this_ptr, SL("_data"), lastKey, result TSRMLS_CC);
	RETURN_CCTOR(result);

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, flush) {

	

	zephir_update_property_this(getThis(), SL("_data"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_BOOL(1);

}

/**
 * Required for interface \Serializable
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, serialize) {

	zval *_1;
	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_frontend"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("frontend"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 68, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Required for interface \Serializable
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, *unserialized = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&unserialized, "unserialize", NULL, 69, data);
	zephir_check_call_status();
	if (Z_TYPE_P(unserialized) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Unserialized data must be an array", "phalcon/cache/backend/memory.zep", 295);
		return;
	}
	zephir_array_fetch_string(&_0, unserialized, SL("frontend"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/memory.zep", 298 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_frontend"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

