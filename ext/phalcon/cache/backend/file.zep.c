
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/time.h"
#include "kernel/iterator.h"
#include "ext/spl/spl_directory.h"


/**
 * Phalcon\Cache\Backend\File
 *
 * Allows to cache output fragments using a file backend
 *
 *<code>
 *	//Cache the file for 2 days
 *	$frontendOptions = array(
 *		'lifetime' => 172800
 *	);
 *
 *  //Create a output cache
 *  $frontCache = \Phalcon\Cache\Frontend\Output($frontOptions);
 *
 *	//Set the cache directory
 *	$backendOptions = array(
 *		'cacheDir' => '../app/cache/'
 *	);
 *
 *  //Create the File backend
 *  $cache = new \Phalcon\Cache\Backend\File($frontCache, $backendOptions);
 *
 *	$content = $cache->start('my-cache');
 *	if ($content === null) {
 *  	echo '<h1>', time(), '</h1>';
 *  	$cache->save();
 *	} else {
 *		echo $content;
 *	}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_File) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, File, phalcon, cache_backend_file, phalcon_cache_backend_ce, phalcon_cache_backend_file_method_entry, 0);

	/**
	 * Default to false for backwards compatibility
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_cache_backend_file_ce, SL("_useSafeKey"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_file_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\File constructor
 *
 * @param	Phalcon\Cache\FrontendInterface frontend
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_File, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_bool _1;
	zval *frontend, *options = NULL, *prefix, *safekey, *_0, *_2, *_3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_array_isset_string(options, SS("cacheDir")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory must be specified with the option cacheDir", "phalcon/cache/backend/file.zep", 78);
		return;
	}
	ZEPHIR_OBS_VAR(safekey);
	if (zephir_array_isset_string_fetch(&safekey, options, SS("safekey"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(safekey) != IS_BOOL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "safekey option should be a boolean.", "phalcon/cache/backend/file.zep", 83);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_useSafeKey"), safekey TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(prefix);
	if (zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 0 TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_useSafeKey"), PH_NOISY_CC);
		_1 = zephir_is_true(_0);
		if (_1) {
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_SINIT_VAR(_4);
			ZVAL_STRING(&_4, "/[^a-zA-Z0-9_.-]+/", 0);
			zephir_preg_match(_3, &_4, prefix, _2, 0, 0 , 0  TSRMLS_CC);
			_1 = zephir_is_true(_3);
		}
		if (_1) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "FileCache prefix should only use alphanumeric characters.", "phalcon/cache/backend/file.zep", 92);
			return;
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_file_ce, this_ptr, "__construct", &_5, 36, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 *
 * @param int|string keyName
 * @param   int lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, get) {

	int ttl, modifiedTime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *lifetime = NULL, *prefixedKey, *cacheDir, *cacheFile, *frontend, *lastLifetime, *cachedContent, *ret = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, _1);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_OBS_VAR(cacheDir);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _2, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 115);
		return;
	}
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, cacheDir, prefixedKey);
	if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS) == 1) {
		ZEPHIR_OBS_VAR(frontend);
		zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		if (!(zephir_is_true(lifetime))) {
			ZEPHIR_OBS_VAR(lastLifetime);
			zephir_read_property_this(&lastLifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
			if (!(zephir_is_true(lastLifetime))) {
				ZEPHIR_CALL_METHOD(&_3, frontend, "getlifetime", NULL, 0);
				zephir_check_call_status();
				ttl = zephir_get_intval(_3);
			} else {
				ttl = zephir_get_intval(lastLifetime);
			}
		} else {
			ttl = zephir_get_intval(lifetime);
		}
		ZEPHIR_INIT_VAR(_4);
		zephir_filemtime(_4, cacheFile TSRMLS_CC);
		modifiedTime = zephir_get_intval(_4);
		ZEPHIR_INIT_VAR(_5);
		zephir_time(_5);
		if (!((zephir_get_numberval(_5) - ttl) > modifiedTime)) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_file_get_contents(cachedContent, cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
				ZEPHIR_INIT_VAR(_6);
				object_init_ex(_6, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_7);
				ZEPHIR_CONCAT_SVS(_7, "Cache file ", cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 2, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6, "phalcon/cache/backend/file.zep", 151 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(cachedContent)) {
				RETURN_CCTOR(cachedContent);
			} else {
				ZEPHIR_CALL_METHOD(&ret, frontend, "afterretrieve", NULL, 0, cachedContent);
				zephir_check_call_status();
				RETURN_CCTOR(ret);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param int lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_File, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend, *cacheDir, *isBuffering = NULL, *cacheFile, *cachedContent = NULL, *preparedContent = NULL, *status = NULL, *_0, *_1 = NULL, *_2, *_3;

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
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkey", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0, _1);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/file.zep", 186);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cacheDir);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 192);
		return;
	}
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, cacheDir, lastKey);
	if (!(zephir_is_true(content))) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, 0, cachedContent);
	zephir_check_call_status();
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_INIT_VAR(status);
		zephir_file_put_contents(status, cacheFile, preparedContent TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(status);
		zephir_file_put_contents(status, cacheFile, cachedContent TSRMLS_CC);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "Cache file ", cacheFile, " could not be written");
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 2, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "phalcon/cache/backend/file.zep", 215 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
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
	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *cacheFile, *cacheDir, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(cacheDir);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 242);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VVV(cacheFile, cacheDir, _1, _2);
	if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 37, cacheFile);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Query the existing cached keys
 *
 * @param string|int prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_object_iterator *_1;
	zval *keys;
	zval *prefix = NULL, *item = NULL, *key = NULL, *cacheDir, *_0, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);


	ZEPHIR_OBS_VAR(cacheDir);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 265);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, spl_ce_DirectoryIterator);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 38, cacheDir);
	zephir_check_call_status();
	_1 = zephir_get_iterator(_2 TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_1->funcs->get_current_data(_1, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_CALL_METHOD(&_3, item, "isdir", NULL, 0);
		zephir_check_call_status();
		if (likely(ZEPHIR_IS_FALSE_IDENTICAL(_3))) {
			ZEPHIR_CALL_METHOD(&key, item, "getfilename", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(prefix) != IS_NULL) {
				if (zephir_start_with(key, prefix, NULL)) {
					zephir_array_append(&keys, key, PH_SEPARATE, "phalcon/cache/backend/file.zep", 277);
				}
			} else {
				zephir_array_append(&keys, key, PH_SEPARATE, "phalcon/cache/backend/file.zep", 280);
			}
		}
	}
	_1->funcs->dtor(_1 TSRMLS_CC);
	RETURN_CTOR(keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string|int keyName
 * @param   int lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, exists) {

	int lifetime, ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey = NULL, *prefix, *cacheFile, *_0 = NULL, *_1, *_2, *_3, *_4, *_5;

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
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getkey", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, _0);
	}
	if (zephir_is_true(lastKey)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		zephir_array_fetch_string(&_2, _1, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 309 TSRMLS_CC);
		ZEPHIR_INIT_VAR(cacheFile);
		ZEPHIR_CONCAT_VV(cacheFile, _2, lastKey);
		if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS)) {
			if (!(lifetime)) {
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_0, _3, "getlifetime", NULL, 0);
				zephir_check_call_status();
				ttl = zephir_get_intval(_0);
			} else {
				ttl = lifetime;
			}
			ZEPHIR_INIT_VAR(_4);
			zephir_filemtime(_4, cacheFile TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5);
			zephir_time(_5);
			if (ZEPHIR_LT_LONG(_5, (zephir_get_numberval(_4) + ttl))) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Increment of a given key, by number $value
 *
 * @param  string|int keyName
 * @param  int value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, increment) {

	int value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *prefixedKey, *cacheFile, *frontend, *timestamp, *lifetime, *ttl = NULL, *cachedContent, *result, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6 = NULL, *_7;

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, _1);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 345 TSRMLS_CC);
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, _3, prefixedKey);
	if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBS_VAR(frontend);
		zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(timestamp);
		zephir_time(timestamp);
		ZEPHIR_OBS_VAR(lifetime);
		zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(lifetime))) {
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
		}
		ZEPHIR_INIT_VAR(_4);
		sub_function(_4, timestamp, ttl TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		zephir_filemtime(_5, cacheFile TSRMLS_CC);
		if (ZEPHIR_LT(_4, _5)) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_file_get_contents(cachedContent, cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
				ZEPHIR_INIT_VAR(_6);
				object_init_ex(_6, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_7);
				ZEPHIR_CONCAT_SVS(_7, "Cache file ", cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 2, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6, "phalcon/cache/backend/file.zep", 377 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(cachedContent)) {
				ZEPHIR_INIT_VAR(result);
				ZVAL_LONG(result, (zephir_get_numberval(cachedContent) + value));
				ZEPHIR_INIT_NVAR(_6);
				zephir_file_put_contents(_6, cacheFile, result TSRMLS_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory could not be written", "phalcon/cache/backend/file.zep", 384);
					return;
				}
				RETURN_CCTOR(result);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Decrement of a given key, by number $value
 *
 * @param  string|int keyName
 * @param  int value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, decrement) {

	int value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *prefixedKey, *cacheFile, *timestamp, *lifetime, *ttl = NULL, *cachedContent, *result, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6, *_7 = NULL, *_8;

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, _1);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 406 TSRMLS_CC);
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, _3, prefixedKey);
	if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(timestamp);
		zephir_time(timestamp);
		ZEPHIR_OBS_VAR(lifetime);
		zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(lifetime))) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&ttl, _4, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
		}
		ZEPHIR_INIT_VAR(_5);
		sub_function(_5, timestamp, ttl TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		zephir_filemtime(_6, cacheFile TSRMLS_CC);
		if (ZEPHIR_LT(_5, _6)) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_file_get_contents(cachedContent, cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
				ZEPHIR_INIT_VAR(_7);
				object_init_ex(_7, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_8);
				ZEPHIR_CONCAT_SVS(_8, "Cache file ", cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 2, _8);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7, "phalcon/cache/backend/file.zep", 436 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(cachedContent)) {
				ZEPHIR_INIT_VAR(result);
				ZVAL_LONG(result, (zephir_get_numberval(cachedContent) - value));
				ZEPHIR_INIT_NVAR(_7);
				zephir_file_put_contents(_7, cacheFile, result TSRMLS_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_7)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory can't be written", "phalcon/cache/backend/file.zep", 443);
					return;
				}
				RETURN_CCTOR(result);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_File, flush) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_object_iterator *_1;
	zval *prefix, *cacheDir, *item = NULL, *key = NULL, *cacheFile = NULL, *_0, *_2, *_3 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cacheDir);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 462);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, spl_ce_DirectoryIterator);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 38, cacheDir);
	zephir_check_call_status();
	_1 = zephir_get_iterator(_2 TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_1->funcs->get_current_data(_1, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_CALL_METHOD(&_3, item, "isfile", NULL, 0);
		zephir_check_call_status();
		if (likely(ZEPHIR_IS_TRUE(_3))) {
			ZEPHIR_CALL_METHOD(&key, item, "getfilename", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&cacheFile, item, "getpathname", NULL, 0);
			zephir_check_call_status();
			_4 = ZEPHIR_IS_EMPTY(prefix);
			if (!(_4)) {
				_4 = zephir_start_with(key, prefix, NULL);
			}
			if (_4) {
				ZEPHIR_CALL_FUNCTION(&_5, "unlink", &_6, 37, cacheFile);
				zephir_check_call_status();
				if (!(zephir_is_true(_5))) {
					RETURN_MM_BOOL(0);
				}
			}
		}
	}
	_1->funcs->dtor(_1 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

/**
 * Return a file-system safe identifier for a given key
 */
PHP_METHOD(Phalcon_Cache_Backend_File, getKey) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_useSafeKey"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		zephir_md5(return_value, key);
		return;
	}
	RETVAL_ZVAL(key, 1, 0);
	return;

}

/**
 * Set whether to use the safekey or not
 *
 * @return this
 */
PHP_METHOD(Phalcon_Cache_Backend_File, useSafeKey) {

	zval *useSafeKey_param = NULL;
	zend_bool useSafeKey;

	zephir_fetch_params(0, 1, 0, &useSafeKey_param);

	useSafeKey = zephir_get_boolval(useSafeKey_param);


	zephir_update_property_this(this_ptr, SL("_useSafeKey"), useSafeKey ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

