
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/time.h"
#include "kernel/iterator.h"
#include "ext/spl/spl_directory.h"


/**
 * Phalcon\Cache\Backend\File
 *
 * Allows to cache output fragments using a file backend
 *
 *<code>
 * use Phalcon\Cache\Backend\File;
 * use Phalcon\Cache\Frontend\Output as FrontOutput;
 *
 * // Cache the file for 2 days
 * $frontendOptions = [
 *     "lifetime" => 172800,
 * ];
 *
 * // Create an output cache
 * $frontCache = FrontOutput($frontOptions);
 *
 * // Set the cache directory
 * $backendOptions = [
 *     "cacheDir" => "../app/cache/",
 * ];
 *
 * // Create the File backend
 * $cache = new File($frontCache, $backendOptions);
 *
 * $content = $cache->start("my-cache");
 *
 * if ($content === null) {
 *     echo "<h1>", time(), "</h1>";
 *
 *     $cache->save();
 * } else {
 *     echo $content;
 * }
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

	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\File constructor
 */
PHP_METHOD(Phalcon_Cache_Backend_File, __construct) {

	zend_bool _1$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *options = NULL;
	zval *frontend, *options_param = NULL, *prefix = NULL, *safekey = NULL, *_0$$6, *_2$$6, *_3$$6, _4$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &frontend, &options_param);

	zephir_get_arrval(options, options_param);


	if (!(zephir_array_isset_string(options, SS("cacheDir")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory must be specified with the option cacheDir", "phalcon/cache/backend/file.zep", 79);
		return;
	}
	ZEPHIR_OBS_VAR(safekey);
	if (zephir_array_isset_string_fetch(&safekey, options, SS("safekey"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(safekey) != IS_BOOL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "safekey option should be a boolean.", "phalcon/cache/backend/file.zep", 84);
			return;
		}
		zephir_update_property_this(getThis(), SL("_useSafeKey"), safekey TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(prefix);
	if (zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 0 TSRMLS_CC)) {
		_0$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_useSafeKey"), PH_NOISY_CC);
		_1$$6 = zephir_is_true(_0$$6);
		if (_1$$6) {
			ZEPHIR_INIT_VAR(_2$$6);
			ZEPHIR_INIT_VAR(_3$$6);
			ZEPHIR_SINIT_VAR(_4$$6);
			ZVAL_STRING(&_4$$6, "/[^a-zA-Z0-9_.-]+/", 0);
			zephir_preg_match(_3$$6, &_4$$6, prefix, _2$$6, 0, 0 , 0  TSRMLS_CC);
			_1$$6 = zephir_is_true(_3$$6);
		}
		if (_1$$6) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "FileCache prefix should only use alphanumeric characters.", "phalcon/cache/backend/file.zep", 93);
			return;
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_file_ce, getThis(), "__construct", &_5, 124, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_File, get) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS, ttl = 0, modifiedTime = 0;
	zval *keyName_param = NULL, *lifetime_param = NULL, *prefixedKey = NULL, *cacheDir = NULL, *cacheFile = NULL, *frontend = NULL, *lastLifetime = NULL, *cachedContent = NULL, *ret = NULL, *_0, *_1 = NULL, *_2, *_3$$6 = NULL, *_4$$4, *_5$$4, *_6$$10, *_7$$10;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, _1);
	zephir_update_property_this(getThis(), SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_OBS_VAR(cacheDir);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _2, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 111);
		return;
	}
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, cacheDir, prefixedKey);
	if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS) == 1) {
		ZEPHIR_OBS_VAR(frontend);
		zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		if (!(lifetime)) {
			ZEPHIR_OBS_VAR(lastLifetime);
			zephir_read_property_this(&lastLifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
			if (!(zephir_is_true(lastLifetime))) {
				ZEPHIR_CALL_METHOD(&_3$$6, frontend, "getlifetime", NULL, 0);
				zephir_check_call_status();
				ttl = zephir_get_intval(_3$$6);
			} else {
				ttl = zephir_get_intval(lastLifetime);
			}
		} else {
			ttl = lifetime;
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 125, ZEPHIR_GLOBAL(global_true), cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$4);
		zephir_filemtime(_4$$4, cacheFile TSRMLS_CC);
		modifiedTime = zephir_get_intval(_4$$4);
		ZEPHIR_INIT_VAR(_5$$4);
		zephir_time(_5$$4);
		if (ZEPHIR_LT_LONG(_5$$4, (modifiedTime + ttl))) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_file_get_contents(cachedContent, cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
				ZEPHIR_INIT_VAR(_6$$10);
				object_init_ex(_6$$10, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_7$$10);
				ZEPHIR_CONCAT_SVS(_7$$10, "Cache file ", cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, _6$$10, "__construct", NULL, 9, _7$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6$$10, "phalcon/cache/backend/file.zep", 148 TSRMLS_CC);
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
	RETURN_MM_NULL();

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend = NULL, *cacheDir = NULL, *isBuffering = NULL, *cacheFile = NULL, *cachedContent = NULL, *preparedContent = NULL, *status = NULL, *_2, *_0$$4, *_1$$4 = NULL, *_3$$11, *_4$$11;

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
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getkey", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0$$4, _1$$4);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/file.zep", 186);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cacheDir);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _2, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 192);
		return;
	}
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, cacheDir, lastKey);
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
	ZEPHIR_INIT_VAR(status);
	zephir_file_put_contents(status, cacheFile, preparedContent TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
		ZEPHIR_INIT_VAR(_3$$11);
		object_init_ex(_3$$11, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(_4$$11);
		ZEPHIR_CONCAT_SVS(_4$$11, "Cache file ", cacheFile, " could not be written");
		ZEPHIR_CALL_METHOD(NULL, _3$$11, "__construct", NULL, 9, _4$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$11, "phalcon/cache/backend/file.zep", 215 TSRMLS_CC);
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
	if (0) {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(status));

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_File, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *cacheFile = NULL, *cacheDir = NULL, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(cacheDir);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 243);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VVV(cacheFile, cacheDir, _1, _2);
	if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 126, cacheFile);
		zephir_check_call_status();
		RETURN_MM();
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
PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys) {

	zend_object_iterator *_3;
	zval *keys;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *item = NULL, *key = NULL, *cacheDir = NULL, *prefixedKey = NULL, *_0, *_4, *_1$$4, *_2$$4 = NULL, *_5$$5 = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_OBS_VAR(cacheDir);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 270);
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(prefix))) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getkey", NULL, 0, prefix);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(prefixedKey);
		ZEPHIR_CONCAT_VV(prefixedKey, _1$$4, _2$$4);
	}
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, spl_ce_DirectoryIterator);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 127, cacheDir);
	zephir_check_call_status();
	_3 = zephir_get_iterator(_4 TSRMLS_CC);
	_3->funcs->rewind(_3 TSRMLS_CC);
	for (;_3->funcs->valid(_3 TSRMLS_CC) == SUCCESS && !EG(exception); _3->funcs->move_forward(_3 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_3->funcs->get_current_data(_3, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_CALL_METHOD(&_5$$5, item, "isdir", NULL, 0);
		zephir_check_call_status();
		if (EXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(_5$$5))) {
			ZEPHIR_CALL_METHOD(&key, item, "getfilename", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(prefix))) {
				if (zephir_start_with(key, prefixedKey, NULL)) {
					zephir_array_append(&keys, key, PH_SEPARATE, "phalcon/cache/backend/file.zep", 285);
				}
			} else {
				zephir_array_append(&keys, key, PH_SEPARATE, "phalcon/cache/backend/file.zep", 288);
			}
		}
	}
	_3->funcs->dtor(_3 TSRMLS_CC);
	RETURN_CTOR(keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string|int keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_File, exists) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS, ttl = 0, modifiedTime = 0;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey = NULL, *prefix = NULL, *cacheFile = NULL, *_0$$4 = NULL, *_1$$5, *_2$$5, *_3$$7, *_4$$7 = NULL, *_5$$6, *_6$$6;

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
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "getkey", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, _0$$4);
	}
	if (zephir_is_true(lastKey)) {
		_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		zephir_array_fetch_string(&_2$$5, _1$$5, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 315 TSRMLS_CC);
		ZEPHIR_INIT_VAR(cacheFile);
		ZEPHIR_CONCAT_VV(cacheFile, _2$$5, lastKey);
		if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS)) {
			if (!(lifetime)) {
				_3$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_4$$7, _3$$7, "getlifetime", NULL, 0);
				zephir_check_call_status();
				ttl = zephir_get_intval(_4$$7);
			} else {
				ttl = lifetime;
			}
			ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 125, ZEPHIR_GLOBAL(global_true), cacheFile);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_5$$6);
			zephir_filemtime(_5$$6, cacheFile TSRMLS_CC);
			modifiedTime = zephir_get_intval(_5$$6);
			ZEPHIR_INIT_VAR(_6$$6);
			zephir_time(_6$$6);
			if (ZEPHIR_LT_LONG(_6$$6, (modifiedTime + ttl))) {
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
 */
PHP_METHOD(Phalcon_Cache_Backend_File, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS, modifiedTime = 0;
	zval *keyName = NULL, *value_param = NULL, *prefixedKey = NULL, *cacheFile = NULL, *frontend = NULL, *lifetime = NULL, *ttl = NULL, *cachedContent = NULL, *result = NULL, *_0, *_1 = NULL, *_2, *_3, *_4$$3, *_5$$3, *_6$$7, *_7$$7, *_8$$8;

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
	zephir_update_property_this(getThis(), SL("_lastKey"), prefixedKey TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 352 TSRMLS_CC);
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, _3, prefixedKey);
	if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBS_VAR(frontend);
		zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(lifetime);
		zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(lifetime))) {
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 125, ZEPHIR_GLOBAL(global_true), cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_filemtime(_4$$3, cacheFile TSRMLS_CC);
		modifiedTime = zephir_get_intval(_4$$3);
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_time(_5$$3);
		if (ZEPHIR_LT_LONG(_5$$3, (modifiedTime + zephir_get_numberval(ttl)))) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_file_get_contents(cachedContent, cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
				ZEPHIR_INIT_VAR(_6$$7);
				object_init_ex(_6$$7, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_7$$7);
				ZEPHIR_CONCAT_SVS(_7$$7, "Cache file ", cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, _6$$7, "__construct", NULL, 9, _7$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6$$7, "phalcon/cache/backend/file.zep", 383 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(cachedContent)) {
				ZEPHIR_INIT_VAR(result);
				ZVAL_LONG(result, (zephir_get_numberval(cachedContent) + value));
				ZEPHIR_INIT_VAR(_8$$8);
				zephir_file_put_contents(_8$$8, cacheFile, result TSRMLS_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_8$$8)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory could not be written", "phalcon/cache/backend/file.zep", 390);
					return;
				}
				RETURN_CCTOR(result);
			}
		}
	}
	RETURN_MM_NULL();

}

/**
 * Decrement of a given key, by number $value
 *
 * @param string|int keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_File, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS, modifiedTime = 0;
	zval *keyName = NULL, *value_param = NULL, *prefixedKey = NULL, *cacheFile = NULL, *lifetime = NULL, *ttl = NULL, *cachedContent = NULL, *result = NULL, *_0, *_1 = NULL, *_2, *_3, *_4$$4, *_5$$3, *_6$$3, *_7$$7, *_8$$7, *_9$$8;

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
	zephir_update_property_this(getThis(), SL("_lastKey"), prefixedKey TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 412 TSRMLS_CC);
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, _3, prefixedKey);
	if ((zephir_file_exists(cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBS_VAR(lifetime);
		zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(lifetime))) {
			_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&ttl, _4$$4, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 125, ZEPHIR_GLOBAL(global_true), cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_filemtime(_5$$3, cacheFile TSRMLS_CC);
		modifiedTime = zephir_get_intval(_5$$3);
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_time(_6$$3);
		if (ZEPHIR_LT_LONG(_6$$3, (modifiedTime + zephir_get_numberval(ttl)))) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_file_get_contents(cachedContent, cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
				ZEPHIR_INIT_VAR(_7$$7);
				object_init_ex(_7$$7, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_8$$7);
				ZEPHIR_CONCAT_SVS(_8$$7, "Cache file ", cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, _7$$7, "__construct", NULL, 9, _8$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7$$7, "phalcon/cache/backend/file.zep", 441 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(cachedContent)) {
				ZEPHIR_INIT_VAR(result);
				ZVAL_LONG(result, (zephir_get_numberval(cachedContent) - value));
				ZEPHIR_INIT_VAR(_9$$8);
				zephir_file_put_contents(_9$$8, cacheFile, result TSRMLS_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_9$$8)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory can't be written", "phalcon/cache/backend/file.zep", 448);
					return;
				}
				RETURN_CCTOR(result);
			}
		}
	}
	RETURN_MM_NULL();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_File, flush) {

	zend_bool _4$$5;
	zend_object_iterator *_1;
	zval *prefix = NULL, *cacheDir = NULL, *item = NULL, *key = NULL, *cacheFile = NULL, *_0, *_2, *_3$$4 = NULL, *_5$$6 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cacheDir);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 469);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, spl_ce_DirectoryIterator);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 127, cacheDir);
	zephir_check_call_status();
	_1 = zephir_get_iterator(_2 TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_1->funcs->get_current_data(_1, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_CALL_METHOD(&_3$$4, item, "isfile", NULL, 0);
		zephir_check_call_status();
		if (EXPECTED(ZEPHIR_IS_TRUE(_3$$4))) {
			ZEPHIR_CALL_METHOD(&key, item, "getfilename", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&cacheFile, item, "getpathname", NULL, 0);
			zephir_check_call_status();
			_4$$5 = ZEPHIR_IS_EMPTY(prefix);
			if (!(_4$$5)) {
				_4$$5 = zephir_start_with(key, prefix, NULL);
			}
			if (_4$$5) {
				ZEPHIR_CALL_FUNCTION(&_5$$6, "unlink", &_6, 126, cacheFile);
				zephir_check_call_status();
				if (!(zephir_is_true(_5$$6))) {
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
 */
PHP_METHOD(Phalcon_Cache_Backend_File, useSafeKey) {

	zval *useSafeKey_param = NULL;
	zend_bool useSafeKey;

	zephir_fetch_params(0, 1, 0, &useSafeKey_param);

	useSafeKey = zephir_get_boolval(useSafeKey_param);


	if (useSafeKey) {
		zephir_update_property_this(getThis(), SL("_useSafeKey"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_useSafeKey"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

