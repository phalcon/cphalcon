
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
	zval options;
	zval *frontend, frontend_sub, *options_param = NULL, prefix, safekey, _0$$6, _2$$6, _3$$6, _4$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&safekey);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &frontend, &options_param);

	zephir_get_arrval(&options, options_param);


	if (!(zephir_array_isset_string(&options, SL("cacheDir")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory must be specified with the option cacheDir", "phalcon/cache/backend/file.zep", 79);
		return;
	}
	ZEPHIR_OBS_VAR(&safekey);
	if (zephir_array_isset_string_fetch(&safekey, &options, SL("safekey"), 0)) {
		if (((Z_TYPE_P(&safekey) == IS_TRUE || Z_TYPE_P(&safekey) == IS_FALSE) != 1)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "safekey option should be a boolean.", "phalcon/cache/backend/file.zep", 84);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_useSafeKey"), &safekey);
	}
	ZEPHIR_OBS_VAR(&prefix);
	if (zephir_array_isset_string_fetch(&prefix, &options, SL("prefix"), 0)) {
		zephir_read_property(&_0$$6, this_ptr, SL("_useSafeKey"), PH_NOISY_CC | PH_READONLY);
		_1$$6 = zephir_is_true(&_0$$6);
		if (_1$$6) {
			ZEPHIR_INIT_VAR(&_2$$6);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZEPHIR_INIT_VAR(&_4$$6);
			ZVAL_STRING(&_4$$6, "/[^a-zA-Z0-9_.-]+/");
			zephir_preg_match(&_3$$6, &_4$$6, &prefix, &_2$$6, 0, 0 , 0  TSRMLS_CC);
			_1$$6 = zephir_is_true(&_3$$6);
		}
		if (_1$$6) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "FileCache prefix should only use alphanumeric characters.", "phalcon/cache/backend/file.zep", 93);
			return;
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_file_ce, getThis(), "__construct", &_5, 0, frontend, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_File, get) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS, ttl = 0, modifiedTime = 0;
	zval *keyName_param = NULL, *lifetime_param = NULL, __$true, prefixedKey, cacheDir, cacheFile, frontend, lastLifetime, cachedContent, ret, _0, _1, _2, _3$$6, _4$$4, _5$$4, _6$$10, _7$$10;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cacheDir);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&lastLifetime);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkey", NULL, 0, &keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZEPHIR_OBS_VAR(&cacheDir);
	zephir_read_property(&_2, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&cacheDir, &_2, SL("cacheDir"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 111);
		return;
	}
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VV(&cacheFile, &cacheDir, &prefixedKey);
	if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS) == 1) {
		ZEPHIR_OBS_VAR(&frontend);
		zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		if (!(lifetime)) {
			ZEPHIR_OBS_VAR(&lastLifetime);
			zephir_read_property(&lastLifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
			if (!(zephir_is_true(&lastLifetime))) {
				ZEPHIR_CALL_METHOD(&_3$$6, &frontend, "getlifetime", NULL, 0);
				zephir_check_call_status();
				ttl = zephir_get_intval(&_3$$6);
			} else {
				ttl = zephir_get_intval(&lastLifetime);
			}
		} else {
			ttl = lifetime;
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 110, &__$true, &cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_filemtime(&_4$$4, &cacheFile TSRMLS_CC);
		modifiedTime = zephir_get_intval(&_4$$4);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_time(&_5$$4);
		if (ZEPHIR_LT_LONG(&_5$$4, (modifiedTime + ttl))) {
			ZEPHIR_INIT_VAR(&cachedContent);
			zephir_file_get_contents(&cachedContent, &cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
				ZEPHIR_INIT_VAR(&_6$$10);
				object_init_ex(&_6$$10, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(&_7$$10);
				ZEPHIR_CONCAT_SVS(&_7$$10, "Cache file ", &cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, &_6$$10, "__construct", NULL, 4, &_7$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$10, "phalcon/cache/backend/file.zep", 148 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(&cachedContent)) {
				RETURN_CCTOR(&cachedContent);
			} else {
				ZEPHIR_CALL_METHOD(&ret, &frontend, "afterretrieve", NULL, 0, &cachedContent);
				zephir_check_call_status();
				RETURN_CCTOR(&ret);
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
 */
PHP_METHOD(Phalcon_Cache_Backend_File, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastKey, frontend, cacheDir, isBuffering, cacheFile, cachedContent, preparedContent, status, _2, _0$$4, _1$$4, _3$$11, _4$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&cacheDir);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&preparedContent);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$11);

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
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getkey", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &_0$$4, &_1$$4);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/file.zep", 185);
		return;
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&cacheDir);
	zephir_read_property(&_2, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&cacheDir, &_2, SL("cacheDir"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 191);
		return;
	}
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VV(&cacheFile, &cacheDir, &lastKey);
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
	ZEPHIR_INIT_VAR(&status);
	zephir_file_put_contents(&status, &cacheFile, &preparedContent TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
		ZEPHIR_INIT_VAR(&_3$$11);
		object_init_ex(&_3$$11, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$11);
		ZEPHIR_CONCAT_SVS(&_4$$11, "Cache file ", &cacheFile, " could not be written");
		ZEPHIR_CALL_METHOD(NULL, &_3$$11, "__construct", NULL, 4, &_4$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$11, "phalcon/cache/backend/file.zep", 214 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
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
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&status));

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_File, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, cacheFile, cacheDir, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&cacheDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(&cacheDir);
	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&cacheDir, &_0, SL("cacheDir"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 242);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VVV(&cacheFile, &cacheDir, &_1, &_2);
	if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 111, &cacheFile);
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
	zval keys;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, item, key, cacheDir, prefixedKey, _0, _4, _1$$4, _2$$4, _5$$5;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&cacheDir);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&keys);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(&keys);
	array_init(&keys);
	ZEPHIR_OBS_VAR(&cacheDir);
	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&cacheDir, &_0, SL("cacheDir"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 269);
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(&prefix))) {
		zephir_read_property(&_1$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getkey", NULL, 0, &prefix);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&prefixedKey);
		ZEPHIR_CONCAT_VV(&prefixedKey, &_1$$4, &_2$$4);
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, spl_ce_DirectoryIterator);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 112, &cacheDir);
	zephir_check_call_status();
	_3 = zephir_get_iterator(&_4 TSRMLS_CC);
	_3->funcs->rewind(_3 TSRMLS_CC);
	for (;_3->funcs->valid(_3 TSRMLS_CC) == SUCCESS && !EG(exception); _3->funcs->move_forward(_3 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _3);
		}
		ZEPHIR_CALL_METHOD(&_5$$5, &item, "isdir", NULL, 0);
		zephir_check_call_status();
		if (EXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_5$$5))) {
			ZEPHIR_CALL_METHOD(&key, &item, "getfilename", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&prefix))) {
				if (zephir_start_with(&key, &prefixedKey, NULL)) {
					zephir_array_append(&keys, &key, PH_SEPARATE, "phalcon/cache/backend/file.zep", 284);
				}
			} else {
				zephir_array_append(&keys, &key, PH_SEPARATE, "phalcon/cache/backend/file.zep", 287);
			}
		}
	}
	zend_iterator_dtor(_3);
	RETURN_CTOR(&keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string|int keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_File, exists) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS, ttl = 0, modifiedTime = 0;
	zval *keyName = NULL, keyName_sub, *lifetime_param = NULL, __$true, __$null, lastKey, prefix, cacheFile, _0$$4, _1$$5, _2$$5, _3$$7, _4$$7, _5$$6, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);

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


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "getkey", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &prefix, &_0$$4);
	}
	if (zephir_is_true(&lastKey)) {
		zephir_read_property(&_1$$5, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$5, &_1$$5, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 314 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&cacheFile);
		ZEPHIR_CONCAT_VV(&cacheFile, &_2$$5, &lastKey);
		if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS)) {
			if (!(lifetime)) {
				zephir_read_property(&_3$$7, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_4$$7, &_3$$7, "getlifetime", NULL, 0);
				zephir_check_call_status();
				ttl = zephir_get_intval(&_4$$7);
			} else {
				ttl = lifetime;
			}
			ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 110, &__$true, &cacheFile);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$6);
			zephir_filemtime(&_5$$6, &cacheFile TSRMLS_CC);
			modifiedTime = zephir_get_intval(&_5$$6);
			ZEPHIR_INIT_VAR(&_6$$6);
			zephir_time(&_6$$6);
			if (ZEPHIR_LT_LONG(&_6$$6, (modifiedTime + ttl))) {
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
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$true, __$null, prefixedKey, cacheFile, frontend, lifetime, ttl, cachedContent, result, _0, _1, _2, _3, _4$$3, _5$$3, _6$$7, _7$$7, _8$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);

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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	zephir_read_property(&_2, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &_2, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 351 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VV(&cacheFile, &_3, &prefixedKey);
	if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBS_VAR(&frontend);
		zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&lifetime);
		zephir_read_property(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(&lifetime))) {
			ZEPHIR_CALL_METHOD(&ttl, &frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&ttl, &lifetime);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 110, &__$true, &cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_filemtime(&_4$$3, &cacheFile TSRMLS_CC);
		modifiedTime = zephir_get_intval(&_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_time(&_5$$3);
		if (ZEPHIR_LT_LONG(&_5$$3, (modifiedTime + zephir_get_numberval(&ttl)))) {
			ZEPHIR_INIT_VAR(&cachedContent);
			zephir_file_get_contents(&cachedContent, &cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
				ZEPHIR_INIT_VAR(&_6$$7);
				object_init_ex(&_6$$7, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(&_7$$7);
				ZEPHIR_CONCAT_SVS(&_7$$7, "Cache file ", &cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 4, &_7$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$7, "phalcon/cache/backend/file.zep", 382 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(&cachedContent)) {
				ZEPHIR_INIT_VAR(&result);
				ZVAL_LONG(&result, (zephir_get_numberval(&cachedContent) + value));
				ZEPHIR_INIT_VAR(&_8$$8);
				zephir_file_put_contents(&_8$$8, &cacheFile, &result TSRMLS_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$8)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory could not be written", "phalcon/cache/backend/file.zep", 389);
					return;
				}
				RETURN_CCTOR(&result);
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
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$true, __$null, prefixedKey, cacheFile, lifetime, ttl, cachedContent, result, _0, _1, _2, _3, _4$$4, _5$$3, _6$$3, _7$$7, _8$$7, _9$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);

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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	zephir_read_property(&_2, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &_2, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 411 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VV(&cacheFile, &_3, &prefixedKey);
	if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBS_VAR(&lifetime);
		zephir_read_property(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(&lifetime))) {
			zephir_read_property(&_4$$4, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&ttl, &_4$$4, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&ttl, &lifetime);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 110, &__$true, &cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_filemtime(&_5$$3, &cacheFile TSRMLS_CC);
		modifiedTime = zephir_get_intval(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_time(&_6$$3);
		if (ZEPHIR_LT_LONG(&_6$$3, (modifiedTime + zephir_get_numberval(&ttl)))) {
			ZEPHIR_INIT_VAR(&cachedContent);
			zephir_file_get_contents(&cachedContent, &cacheFile TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
				ZEPHIR_INIT_VAR(&_7$$7);
				object_init_ex(&_7$$7, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(&_8$$7);
				ZEPHIR_CONCAT_SVS(&_8$$7, "Cache file ", &cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 4, &_8$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$7, "phalcon/cache/backend/file.zep", 440 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(&cachedContent)) {
				ZEPHIR_INIT_VAR(&result);
				ZVAL_LONG(&result, (zephir_get_numberval(&cachedContent) - value));
				ZEPHIR_INIT_VAR(&_9$$8);
				zephir_file_put_contents(&_9$$8, &cacheFile, &result TSRMLS_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$8)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory can't be written", "phalcon/cache/backend/file.zep", 447);
					return;
				}
				RETURN_CCTOR(&result);
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
	zval prefix, cacheDir, item, key, cacheFile, _0, _2, _3$$4, _5$$6;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&cacheDir);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&prefix);
	zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&cacheDir);
	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&cacheDir, &_0, SL("cacheDir"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 468);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, spl_ce_DirectoryIterator);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 112, &cacheDir);
	zephir_check_call_status();
	_1 = zephir_get_iterator(&_2 TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _1);
		}
		ZEPHIR_CALL_METHOD(&_3$$4, &item, "isfile", NULL, 0);
		zephir_check_call_status();
		if (EXPECTED(ZEPHIR_IS_TRUE(&_3$$4))) {
			ZEPHIR_CALL_METHOD(&key, &item, "getfilename", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&cacheFile, &item, "getpathname", NULL, 0);
			zephir_check_call_status();
			_4$$5 = ZEPHIR_IS_EMPTY(&prefix);
			if (!(_4$$5)) {
				_4$$5 = zephir_start_with(&key, &prefix, NULL);
			}
			if (_4$$5) {
				ZEPHIR_CALL_FUNCTION(&_5$$6, "unlink", &_6, 111, &cacheFile);
				zephir_check_call_status();
				if (!(zephir_is_true(&_5$$6))) {
					RETURN_MM_BOOL(0);
				}
			}
		}
	}
	zend_iterator_dtor(_1);
	RETURN_MM_BOOL(1);

}

/**
 * Return a file-system safe identifier for a given key
 */
PHP_METHOD(Phalcon_Cache_Backend_File, getKey) {

	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &key);



	zephir_read_property(&_0, this_ptr, SL("_useSafeKey"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
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

	zval *useSafeKey_param = NULL, __$true, __$false;
	zend_bool useSafeKey;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &useSafeKey_param);

	useSafeKey = zephir_get_boolval(useSafeKey_param);


	if (useSafeKey) {
		zephir_update_property_zval(this_ptr, SL("_useSafeKey"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_useSafeKey"), &__$false);
	}
	RETURN_THISW();

}

