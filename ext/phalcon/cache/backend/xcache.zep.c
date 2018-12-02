
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * Phalcon\Cache\Backend\Xcache
 *
 * Allows to cache output fragments, PHP data and raw data using an XCache backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Xcache;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *        "lifetime" => 172800,
 *     ]
 * );
 *
 * $cache = new Xcache(
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
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Xcache) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Xcache, phalcon, cache_backend_xcache, phalcon_cache_backend_ce, phalcon_cache_backend_xcache_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Xcache constructor
 *
 * @param \Phalcon\Cache\FrontendInterface frontend
 * @param array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *frontend, *options = NULL, *_0$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_0$$4);
		ZVAL_STRING(_0$$4, "", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_0$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_xcache_ce, getThis(), "__construct", &_1, 124, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, get) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, *frontend = NULL, *prefixedKey = NULL, *cachedContent = NULL, *_0;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCX", _0, keyName);
	zephir_update_property_this(getThis(), SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&cachedContent, "xcache_get", NULL, 94, prefixedKey);
	zephir_check_call_status();
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	} else {
		ZEPHIR_RETURN_CALL_METHOD(frontend, "afterretrieve", NULL, 0, cachedContent);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param int lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp = NULL, *tt1 = NULL, *success = NULL, *isBuffering = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *_0$$4, *_1$$17;

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
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0$$4, keyName);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/xcache.zep", 123);
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
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_VAR(tmp);
		zephir_read_property_this(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_CALL_METHOD(&tt1, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(tt1, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(tt1, lifetime);
	}
	ZEPHIR_CALL_FUNCTION(&success, "xcache_set", NULL, 95, lastKey, preparedContent, tt1);
	zephir_check_call_status();
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing the data in xcache", "phalcon/cache/backend/xcache.zep", 156);
		return;
	}
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
	if (zephir_is_true(success)) {
		ZEPHIR_OBS_VAR(options);
		zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(specialKey);
		_1$$17 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if (!(zephir_array_isset_string_fetch(&specialKey, _1$$17, SS("statsKey"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/xcache.zep", 175);
			return;
		}
		if (!ZEPHIR_IS_STRING(specialKey, "")) {
			ZEPHIR_CALL_FUNCTION(&keys, "xcache_get", NULL, 94, specialKey);
			zephir_check_call_status();
			if (Z_TYPE_P(keys) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(keys);
				array_init(keys);
			}
			zephir_array_update_zval(&keys, lastKey, &tt1, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 95, specialKey, keys);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(success);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *prefixedKey = NULL, *specialKey = NULL, *keys = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCX", _0, keyName);
	ZEPHIR_OBS_VAR(specialKey);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&specialKey, _1, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/xcache.zep", 209);
		return;
	}
	if (!ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_CALL_FUNCTION(&keys, "xcache_get", NULL, 94, specialKey);
		zephir_check_call_status();
		if (Z_TYPE_P(keys) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(keys);
			array_init(keys);
		}
		zephir_array_unset(&keys, prefixedKey, PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 95, specialKey, keys);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phalcon_Cache_Backend_Xcache, queryKeys) {

	HashTable *_4;
	HashPosition _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *options = NULL, *prefixed = NULL, *specialKey = NULL, *keys = NULL, *retval = NULL, *key = NULL, *realKey = NULL, *_1, *_2 = NULL, **_5, _6$$9 = zval_used_for_init;
	zval *prefix = NULL, *_0$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(prefixed);
	if (!(!(!prefix) && Z_STRLEN_P(prefix))) {
		ZVAL_STRING(prefixed, "_PHCX", 1);
	} else {
		ZEPHIR_INIT_VAR(_0$$4);
		ZEPHIR_CONCAT_SV(_0$$4, "_PHCX", prefix);
		ZEPHIR_CPY_WRT(prefixed, _0$$4);
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&specialKey, _1, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/xcache.zep", 247);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCX')!", "phalcon/cache/backend/xcache.zep", 251);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&keys, "xcache_get", NULL, 94, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(retval);
	array_init(retval);
	ZEPHIR_INIT_VAR(_2);
	zephir_is_iterable(keys, &_4, &_3, 0, 0, "phalcon/cache/backend/xcache.zep", 272);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(_2, _5);
		if (zephir_start_with(key, prefixed, NULL)) {
			ZEPHIR_SINIT_NVAR(_6$$9);
			ZVAL_LONG(&_6$$9, 5);
			ZEPHIR_INIT_NVAR(realKey);
			zephir_substr(realKey, key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_array_append(&retval, realKey, PH_SEPARATE, "phalcon/cache/backend/xcache.zep", 268);
		}
	}
	RETURN_CCTOR(retval);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, exists) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey = NULL, *_0$$4;

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


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0$$4, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_RETURN_CALL_FUNCTION("xcache_isset", NULL, 130, lastKey);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Atomic increment of a given key, by number $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *value_param = NULL, *lastKey = NULL, *newVal = NULL, *origVal = NULL, *_0$$4, _1$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value_param);

	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0$$4, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/xcache.zep", 313);
		return;
	}
	if ((zephir_function_exists_ex(SS("xcache_inc") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_1$$6);
		ZVAL_LONG(&_1$$6, value);
		ZEPHIR_CALL_FUNCTION(&newVal, "xcache_inc", NULL, 131, lastKey, &_1$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&origVal, "xcache_get", NULL, 94, lastKey);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(newVal);
		ZVAL_LONG(newVal, (zephir_get_numberval(origVal) - value));
		ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 95, lastKey, newVal);
		zephir_check_call_status();
	}
	RETURN_CCTOR(newVal);

}

/**
 * Atomic decrement of a given key, by number $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *value_param = NULL, *lastKey = NULL, *newVal = NULL, *origVal = NULL, *success = NULL, *_0$$4, _1$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value_param);

	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0$$4, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/xcache.zep", 343);
		return;
	}
	if ((zephir_function_exists_ex(SS("xcache_dec") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_1$$6);
		ZVAL_LONG(&_1$$6, value);
		ZEPHIR_CALL_FUNCTION(&newVal, "xcache_dec", NULL, 132, lastKey, &_1$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&origVal, "xcache_get", NULL, 94, lastKey);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(newVal);
		ZVAL_LONG(newVal, (zephir_get_numberval(origVal) - value));
		ZEPHIR_CALL_FUNCTION(&success, "xcache_set", NULL, 95, lastKey, newVal);
		zephir_check_call_status();
	}
	RETURN_CCTOR(newVal);

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, flush) {

	HashTable *_3$$5;
	HashPosition _2$$5;
	zval *options = NULL, *specialKey = NULL, *keys = NULL, *key = NULL, *_0, *_1$$5 = NULL, **_4$$5;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&specialKey, _0, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/xcache.zep", 367);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/xcache.zep", 371);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&keys, "xcache_get", NULL, 94, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1$$5);
		zephir_is_iterable(keys, &_3$$5, &_2$$5, 1, 0, "phalcon/cache/backend/xcache.zep", 381);
		for (
		  ; zend_hash_get_current_data_ex(_3$$5, (void**) &_4$$5, &_2$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$5, &_2$$5)
		) {
			ZEPHIR_GET_HMKEY(key, _3$$5, _2$$5);
			ZEPHIR_GET_HVALUE(_1$$5, _4$$5);
			zephir_array_unset(&keys, key, PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(NULL, "xcache_unset", &_5, 133, key);
			zephir_check_call_status();
		}
		zend_hash_destroy(_3$$5);
		FREE_HASHTABLE(_3$$5);
		ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 95, specialKey, keys);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

