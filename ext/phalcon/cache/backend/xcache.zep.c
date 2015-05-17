
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
#include "kernel/hash.h"
#include "kernel/string.h"


/**
 * Phalcon\Cache\Backend\Xcache
 *
 * Allows to cache output fragments, PHP data and raw data using an XCache backend
 *
 *<code>
 *	//Cache data for 2 days
 *	$frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *		'lifetime' => 172800
 *	));
 *
 *  $cache = new \Phalcon\Cache\Backend\Xcache($frontCache, array(
 *      'prefix' => 'app-data'
 *  ));
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Xcache) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Xcache, phalcon, cache_backend_xcache, phalcon_cache_backend_ce, phalcon_cache_backend_xcache_method_entry, 0);

	zend_class_implements(phalcon_cache_backend_xcache_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Xcache constructor
 *
 * @param Phalcon\Cache\FrontendInterface frontend
 * @param array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *frontend, *options = NULL, *_0;

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
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "_PHCX", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_xcache_ce, this_ptr, "__construct", &_1, 36, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 *
 * @param int|string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *lifetime = NULL, *frontend, *prefixedKey, *cachedContent = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCX", _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&cachedContent, "xcache_get", NULL, 9, prefixedKey);
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
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, save) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend, *cachedContent = NULL, *preparedContent = NULL, *tmp, *tt1 = NULL, *success = NULL, *isBuffering = NULL, *options, *keys = NULL, *specialKey, *_0;

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


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/xcache.zep", 119);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (!(zephir_is_true(content))) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, 0, cachedContent);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(lifetime))) {
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
	if (zephir_is_numeric(cachedContent)) {
		ZEPHIR_CALL_FUNCTION(&success, "xcache_set", &_1, 12, lastKey, cachedContent, tt1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&success, "xcache_set", &_1, 12, lastKey, preparedContent, tt1);
		zephir_check_call_status();
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
	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	if (zephir_is_true(success)) {
		ZEPHIR_OBS_VAR(options);
		zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(specialKey);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if (!(zephir_array_isset_string_fetch(&specialKey, _0, SS("statsKey"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/xcache.zep", 169);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&keys, "xcache_get", NULL, 9, specialKey);
		zephir_check_call_status();
		if (Z_TYPE_P(keys) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(keys);
			array_init(keys);
		}
		zephir_array_update_zval(&keys, lastKey, &tt1, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", &_1, 12, specialKey, keys);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *prefixedKey, *specialKey, *keys = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCX", _0, keyName);
	ZEPHIR_OBS_VAR(specialKey);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&specialKey, _1, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/xcache.zep", 199);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&keys, "xcache_get", NULL, 9, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(keys);
		array_init(keys);
	}
	zephir_array_unset(&keys, prefixedKey, PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 12, specialKey, keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, queryKeys) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *options, *prefixed, *specialKey, *keys = NULL, *retval, *key = NULL, *realKey = NULL, *_0, *_1 = NULL, **_4, _5 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(prefixed);
	if (!(zephir_is_true(prefix))) {
		ZVAL_STRING(prefixed, "_PHCX", 1);
	} else {
		ZEPHIR_CONCAT_SV(prefixed, "_PHCX", prefix);
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&specialKey, _0, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/xcache.zep", 231);
		return;
	}
	ZEPHIR_INIT_VAR(retval);
	array_init(retval);
	ZEPHIR_CALL_FUNCTION(&keys, "xcache_get", NULL, 9, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		zephir_is_iterable(keys, &_3, &_2, 0, 0, "phalcon/cache/backend/xcache.zep", 248);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(key, _3, _2);
			ZEPHIR_GET_HVALUE(_1, _4);
			if (zephir_start_with(key, prefixed, NULL)) {
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, 5);
				ZEPHIR_INIT_NVAR(realKey);
				zephir_substr(realKey, key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				zephir_array_append(&retval, realKey, PH_SEPARATE, "phalcon/cache/backend/xcache.zep", 245);
			}
		}
	}
	RETURN_CCTOR(retval);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param   long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_RETURN_CALL_FUNCTION("xcache_isset", NULL, 41, lastKey);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Atomic increment of a given key, by number $value
 *
 * @param  string keyName
 * @param  long value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, increment) {

	int ZEPHIR_LAST_CALL_STATUS;
	long value;
	zval *keyName, *value_param = NULL, *lastKey = NULL, *newVal = NULL, *origVal = NULL, *_0, _1;

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
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/xcache.zep", 294);
		return;
	}
	if ((zephir_function_exists_ex(SS("xcache_inc") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, value);
		ZEPHIR_CALL_FUNCTION(&newVal, "xcache_inc", NULL, 42, lastKey, &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&origVal, "xcache_get", NULL, 9, lastKey);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(newVal);
		ZVAL_LONG(newVal, (zephir_get_numberval(origVal) - value));
		ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 12, lastKey, newVal);
		zephir_check_call_status();
	}
	RETURN_CCTOR(newVal);

}

/**
 * Atomic decrement of a given key, by number $value
 *
 * @param  string keyName
 * @param  long value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, decrement) {

	int ZEPHIR_LAST_CALL_STATUS;
	long value;
	zval *keyName, *value_param = NULL, *lastKey = NULL, *newVal = NULL, *origVal = NULL, *success = NULL, *_0, _1;

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
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/xcache.zep", 326);
		return;
	}
	if ((zephir_function_exists_ex(SS("xcache_dec") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, value);
		ZEPHIR_CALL_FUNCTION(&newVal, "xcache_dec", NULL, 43, lastKey, &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&origVal, "xcache_get", NULL, 9, lastKey);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(newVal);
		ZVAL_LONG(newVal, (zephir_get_numberval(origVal) - value));
		ZEPHIR_CALL_FUNCTION(&success, "xcache_set", NULL, 12, lastKey, newVal);
		zephir_check_call_status();
	}
	RETURN_CCTOR(newVal);

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, flush) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options, *specialKey, *keys = NULL, *key = NULL, *_0, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&specialKey, _0, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/xcache.zep", 350);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&keys, "xcache_get", NULL, 9, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		zephir_is_iterable(keys, &_3, &_2, 1, 0, "phalcon/cache/backend/xcache.zep", 360);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(key, _3, _2);
			ZEPHIR_GET_HVALUE(_1, _4);
			zephir_array_unset(&keys, key, PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(NULL, "xcache_unset", &_5, 44, key);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 12, specialKey, keys);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

