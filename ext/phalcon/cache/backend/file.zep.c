
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
	 * @var bool
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
	zephir_fcall_cache_entry *_6 = NULL;
	zval options;
	zval *frontend, frontend_sub, *options_param = NULL, prefix, safekey, _0$$6, _2$$6, _3$$6, _4$$6, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&safekey);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &frontend, &options_param);

	zephir_get_arrval(&options, options_param);


	if (!(zephir_array_isset_string(&options, SL("cacheDir")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory must be specified with the option cacheDir", "phalcon/cache/backend/file.zep", 70);
		return;
	}
	ZEPHIR_OBS_VAR(&safekey);
	if (zephir_array_isset_string_fetch(&safekey, &options, SL("safekey"), 0)) {
		if (((Z_TYPE_P(&safekey) == IS_TRUE || Z_TYPE_P(&safekey) == IS_FALSE) != 1)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "safekey option should be a bool.", "phalcon/cache/backend/file.zep", 75);
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
			ZVAL_STRING(&_3$$6, "/[^a-zA-Z0-9_.-]+/");
			ZEPHIR_INIT_VAR(&_4$$6);
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/[^a-zA-Z0-9_.-]+/");
			zephir_preg_match(&_4$$6, &_5$$6, &prefix, &_2$$6, 0, 0 , 0  TSRMLS_CC);
			_1$$6 = zephir_is_true(&_4$$6);
		}
		if (_1$$6) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "FileCache prefix should only use alphanumeric characters.", "phalcon/cache/backend/file.zep", 84);
			return;
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_file_ce, getThis(), "__construct", &_6, 0, frontend, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_File, get) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS, createdTime = 0, ttl = 0;
	zval *keyName_param = NULL, *lifetime = NULL, lifetime_sub, __$true, __$null, prefixedKey, cacheDir, cacheFile, frontend, lastLifetime, cachedContent, ret, _1, _2, _3, _4$$5, _9$$5, _10$$5, _5$$6, _6$$6, _7$$7, _8$$9, _11$$12, _12$$13, _13$$14, _14$$14, _15$$16, _16$$17, _17$$17;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cacheDir);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&lastLifetime);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime);

	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	_0 = Z_TYPE_P(lifetime) != IS_NULL;
	if (_0) {
		_0 = ZEPHIR_LT_LONG(lifetime, 1);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The lifetime must be at least 1 second", "phalcon/cache/backend/file.zep", 100);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getkey", NULL, 0, &keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_1, &_2);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZEPHIR_OBS_VAR(&cacheDir);
	zephir_read_property(&_3, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&cacheDir, &_3, SL("cacheDir"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 107);
		return;
	}
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VV(&cacheFile, &cacheDir, &prefixedKey);
	if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS) == 1) {
		ZEPHIR_OBS_VAR(&frontend);
		zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_file_get_contents(&_4$$5, &cacheFile TSRMLS_CC);
		ZEPHIR_INIT_VAR(&cachedContent);
		zephir_json_decode(&cachedContent, &_4$$5, zephir_get_intval(&__$true) );
		if (!(zephir_is_true(lifetime))) {
			ZEPHIR_OBS_VAR(&lastLifetime);
			zephir_read_property(&lastLifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "lifetime");
			ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_6$$6);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$6)) {
				ZEPHIR_OBS_VAR(&_7$$7);
				zephir_array_fetch_string(&_7$$7, &cachedContent, SL("lifetime"), PH_NOISY, "phalcon/cache/backend/file.zep", 125 TSRMLS_CC);
				ttl = zephir_get_intval(&_7$$7);
			} else {
				ZEPHIR_OBS_NVAR(&lastLifetime);
				zephir_read_property(&lastLifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
				if (!(zephir_is_true(&lastLifetime))) {
					ZEPHIR_CALL_METHOD(&_8$$9, &frontend, "getlifetime", NULL, 0);
					zephir_check_call_status();
					ttl = zephir_get_intval(&_8$$9);
				} else {
					ttl = zephir_get_intval(&lastLifetime);
				}
			}
		} else {
			ttl = zephir_get_intval(lifetime);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 101, &__$true, &cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "created");
		ZEPHIR_CALL_METHOD(&_9$$5, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_10$$5);
		zephir_check_call_status();
		if (!(zephir_is_true(&_9$$5))) {
			ZEPHIR_INIT_VAR(&_11$$12);
			zephir_filemtime(&_11$$12, &cacheFile TSRMLS_CC);
			createdTime = zephir_get_intval(&_11$$12);
		} else {
			ZEPHIR_OBS_VAR(&_12$$13);
			zephir_array_fetch_string(&_12$$13, &cachedContent, SL("created"), PH_NOISY, "phalcon/cache/backend/file.zep", 142 TSRMLS_CC);
			createdTime = zephir_get_intval(&_12$$13);
		}
		ZEPHIR_INIT_NVAR(&_10$$5);
		zephir_time(&_10$$5);
		if (!((zephir_get_numberval(&_10$$5) - ttl) > createdTime)) {
			ZEPHIR_INIT_VAR(&_14$$14);
			ZVAL_STRING(&_14$$14, "content");
			ZEPHIR_CALL_METHOD(&_13$$14, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_14$$14);
			zephir_check_call_status();
			if (!(zephir_is_true(&_13$$14))) {
				ZEPHIR_INIT_NVAR(&cachedContent);
				zephir_file_get_contents(&cachedContent, &cacheFile TSRMLS_CC);
			} else {
				zephir_array_fetch_string(&_15$$16, &cachedContent, SL("content"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 157 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&cachedContent, &_15$$16);
			}
			if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
				ZEPHIR_INIT_VAR(&_16$$17);
				object_init_ex(&_16$$17, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(&_17$$17);
				ZEPHIR_CONCAT_SVS(&_17$$17, "Cache file ", &cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, &_16$$17, "__construct", NULL, 4, &_17$$17);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_16$$17, "phalcon/cache/backend/file.zep", 160 TSRMLS_CC);
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
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, &keyName);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	} else {
		RETURN_MM_NULL();
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

	zval _5$$16, _7$$17;
	zend_long ZEPHIR_LAST_CALL_STATUS, ttl = 0;
	zend_bool stopBuffer, _0;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastKey, frontend, cacheDir, isBuffering, cacheFile, cachedContent, preparedContent, status, finalContent, lastLifetime, _3, _1$$5, _2$$5, _4$$13, _6$$16, _8$$17, _9$$18, _10$$18;
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
	ZVAL_UNDEF(&finalContent);
	ZVAL_UNDEF(&lastLifetime);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$13);
	ZVAL_UNDEF(&_6$$16);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&_9$$18);
	ZVAL_UNDEF(&_10$$18);
	ZVAL_UNDEF(&_5$$16);
	ZVAL_UNDEF(&_7$$17);

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


	_0 = Z_TYPE_P(lifetime) != IS_NULL;
	if (_0) {
		_0 = ZEPHIR_LT_LONG(lifetime, 1);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The lifetime must be at least 1 second", "phalcon/cache/backend/file.zep", 201);
		return;
	}
	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_1$$5, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$5, this_ptr, "getkey", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &_1$$5, &_2$$5);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/file.zep", 212);
		return;
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&cacheDir);
	zephir_read_property(&_3, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&cacheDir, &_3, SL("cacheDir"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 218);
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
	ZEPHIR_CALL_METHOD(&preparedContent, &frontend, "beforestore", NULL, 0, &cachedContent);
	zephir_check_call_status();
	if (!(zephir_is_true(lifetime))) {
		ZEPHIR_OBS_VAR(&lastLifetime);
		zephir_read_property(&lastLifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(&lastLifetime))) {
			ZEPHIR_CALL_METHOD(&_4$$13, &frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
			ttl = zephir_get_intval(&_4$$13);
		} else {
			ttl = zephir_get_intval(&lastLifetime);
		}
	} else {
		ttl = zephir_get_intval(lifetime);
	}
	ZEPHIR_INIT_VAR(&status);
	zephir_file_put_contents(&status, &cacheFile, &preparedContent TSRMLS_CC);
	if (!(zephir_is_numeric(&cachedContent))) {
		ZEPHIR_INIT_VAR(&_5$$16);
		zephir_create_array(&_5$$16, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$16);
		zephir_time(&_6$$16);
		zephir_array_update_string(&_5$$16, SL("created"), &_6$$16, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_6$$16);
		ZVAL_LONG(&_6$$16, ttl);
		zephir_array_update_string(&_5$$16, SL("lifetime"), &_6$$16, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_5$$16, SL("content"), &preparedContent, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&finalContent);
		zephir_json_encode(&finalContent, &_5$$16, 0 );
	} else {
		ZEPHIR_INIT_VAR(&_7$$17);
		zephir_create_array(&_7$$17, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_8$$17);
		zephir_time(&_8$$17);
		zephir_array_update_string(&_7$$17, SL("created"), &_8$$17, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_8$$17);
		ZVAL_LONG(&_8$$17, ttl);
		zephir_array_update_string(&_7$$17, SL("lifetime"), &_8$$17, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_7$$17, SL("content"), &cachedContent, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&finalContent);
		zephir_json_encode(&finalContent, &_7$$17, 0 );
	}
	ZEPHIR_INIT_NVAR(&status);
	zephir_file_put_contents(&status, &cacheFile, &finalContent TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
		ZEPHIR_INIT_VAR(&_9$$18);
		object_init_ex(&_9$$18, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(&_10$$18);
		ZEPHIR_CONCAT_SVS(&_10$$18, "Cache file ", &cacheFile, " could not be written");
		ZEPHIR_CALL_METHOD(NULL, &_9$$18, "__construct", NULL, 4, &_10$$18);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$18, "phalcon/cache/backend/file.zep", 258 TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 286);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getkey", NULL, 0, keyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VVV(&cacheFile, &cacheDir, &_1, &_2);
	if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 102, &cacheFile);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 313);
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
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 103, &cacheDir);
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
					zephir_array_append(&keys, &key, PH_SEPARATE, "phalcon/cache/backend/file.zep", 328);
				}
			} else {
				zephir_array_append(&keys, &key, PH_SEPARATE, "phalcon/cache/backend/file.zep", 331);
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

	zend_bool cacheFileExists = 0, _11$$6;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS, ttl = 0;
	zval *keyName = NULL, keyName_sub, *lifetime_param = NULL, __$true, __$null, lastKey, prefix, cacheFile, cachedContent, _0$$4, _1$$5, _2$$5, _3$$6, _9$$6, _10$$6, _12$$6, _4$$7, _5$$7, _6$$8, _7$$9, _8$$9, _13$$12, _14$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);

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
		zephir_array_fetch_string(&_2$$5, &_1$$5, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 360 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&cacheFile);
		ZEPHIR_CONCAT_VV(&cacheFile, &_2$$5, &lastKey);
		cacheFileExists = (zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS);
		if (cacheFileExists) {
			ZEPHIR_INIT_VAR(&_3$$6);
			zephir_file_get_contents(&_3$$6, &cacheFile TSRMLS_CC);
			ZEPHIR_INIT_VAR(&cachedContent);
			zephir_json_decode(&cachedContent, &_3$$6, zephir_get_intval(&__$true) );
			if (!(lifetime)) {
				ZEPHIR_INIT_VAR(&_5$$7);
				ZVAL_STRING(&_5$$7, "lifetime");
				ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_5$$7);
				zephir_check_call_status();
				if (zephir_is_true(&_4$$7)) {
					ZEPHIR_OBS_VAR(&_6$$8);
					zephir_array_fetch_string(&_6$$8, &cachedContent, SL("lifetime"), PH_NOISY, "phalcon/cache/backend/file.zep", 372 TSRMLS_CC);
					ttl = zephir_get_intval(&_6$$8);
				} else {
					zephir_read_property(&_7$$9, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_8$$9, &_7$$9, "getlifetime", NULL, 0);
					zephir_check_call_status();
					ttl = zephir_get_intval(&_8$$9);
				}
			} else {
				ttl = lifetime;
			}
			ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 101, &__$true, &cacheFile);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "created");
			ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_10$$6);
			zephir_check_call_status();
			_11$$6 = !zephir_is_true(&_9$$6);
			if (_11$$6) {
				ZEPHIR_INIT_NVAR(&_10$$6);
				zephir_filemtime(&_10$$6, &cacheFile TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_12$$6);
				zephir_time(&_12$$6);
				_11$$6 = ZEPHIR_LT_LONG(&_12$$6, (zephir_get_numberval(&_10$$6) + ttl));
			}
			if (_11$$6) {
				RETURN_MM_BOOL(1);
			} else {
				zephir_array_fetch_string(&_13$$12, &cachedContent, SL("created"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 384 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_14$$12);
				zephir_time(&_14$$12);
				if (ZEPHIR_LT_LONG(&_14$$12, (zephir_get_numberval(&_13$$12) + ttl))) {
					RETURN_MM_BOOL(1);
				}
			}
		}
	}
	if (cacheFileExists) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, keyName);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Check if given variable is array, containing the key $cacheKey
 *
 * @param array|null cachedContent
 * @param string|null cacheKey
 * @return bool
 */
PHP_METHOD(Phalcon_Cache_Backend_File, isValidArray) {

	zend_bool _0;
	zval *cachedContent = NULL, cachedContent_sub, *cacheKey = NULL, cacheKey_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cachedContent_sub);
	ZVAL_UNDEF(&cacheKey_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 2, &cachedContent, &cacheKey);

	if (!cachedContent) {
		cachedContent = &cachedContent_sub;
		cachedContent = &__$null;
	}
	if (!cacheKey) {
		cacheKey = &cacheKey_sub;
		cacheKey = &__$null;
	}


	_0 = Z_TYPE_P(cachedContent) == IS_ARRAY;
	if (_0) {
		_0 = zephir_array_key_exists(cachedContent, cacheKey TSRMLS_CC);
	}
	RETURN_BOOL(_0);

}

/**
 * Increment of a given key, by number $value
 *
 * @param  string|int keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_File, increment) {

	zval _17$$14;
	zend_long value, ZEPHIR_LAST_CALL_STATUS, modifiedTime = 0, ttl = 0;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$true, __$null, prefixedKey, cacheFile, frontend, cachedContent, result, lastLifetime, newValue, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3, _9$$3, _7$$4, _8$$6, _10$$8, _11$$9, _12$$10, _13$$10, _14$$12, _15$$13, _16$$13, _18$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&lastLifetime);
	ZVAL_UNDEF(&newValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_17$$14);

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
	zephir_array_fetch_string(&_3, &_2, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 426 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VV(&cacheFile, &_3, &prefixedKey);
	if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBS_VAR(&frontend);
		zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_file_get_contents(&_4$$3, &cacheFile TSRMLS_CC);
		ZEPHIR_INIT_VAR(&cachedContent);
		zephir_json_decode(&cachedContent, &_4$$3, zephir_get_intval(&__$true) );
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "lifetime");
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_6$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$3)) {
			ZEPHIR_OBS_VAR(&_7$$4);
			zephir_array_fetch_string(&_7$$4, &cachedContent, SL("lifetime"), PH_NOISY, "phalcon/cache/backend/file.zep", 442 TSRMLS_CC);
			ttl = zephir_get_intval(&_7$$4);
		} else {
			ZEPHIR_OBS_VAR(&lastLifetime);
			zephir_read_property(&lastLifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
			if (!(zephir_is_true(&lastLifetime))) {
				ZEPHIR_CALL_METHOD(&_8$$6, &frontend, "getlifetime", NULL, 0);
				zephir_check_call_status();
				ttl = zephir_get_intval(&_8$$6);
			} else {
				ttl = zephir_get_intval(&lastLifetime);
			}
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 101, &__$true, &cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "created");
		ZEPHIR_CALL_METHOD(&_9$$3, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_6$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_9$$3))) {
			ZEPHIR_INIT_VAR(&_10$$8);
			zephir_filemtime(&_10$$8, &cacheFile TSRMLS_CC);
			modifiedTime = zephir_get_intval(&_10$$8);
		} else {
			ZEPHIR_OBS_VAR(&_11$$9);
			zephir_array_fetch_string(&_11$$9, &cachedContent, SL("created"), PH_NOISY, "phalcon/cache/backend/file.zep", 457 TSRMLS_CC);
			modifiedTime = zephir_get_intval(&_11$$9);
		}
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_time(&_6$$3);
		if (!((zephir_get_numberval(&_6$$3) - ttl) > modifiedTime)) {
			ZEPHIR_INIT_VAR(&_13$$10);
			ZVAL_STRING(&_13$$10, "content");
			ZEPHIR_CALL_METHOD(&_12$$10, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_13$$10);
			zephir_check_call_status();
			if (!(zephir_is_true(&_12$$10))) {
				ZEPHIR_INIT_NVAR(&cachedContent);
				zephir_file_get_contents(&cachedContent, &cacheFile TSRMLS_CC);
			} else {
				zephir_array_fetch_string(&_14$$12, &cachedContent, SL("content"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 472 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&cachedContent, &_14$$12);
			}
			if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
				ZEPHIR_INIT_VAR(&_15$$13);
				object_init_ex(&_15$$13, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(&_16$$13);
				ZEPHIR_CONCAT_SVS(&_16$$13, "Cache file ", &cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, &_15$$13, "__construct", NULL, 4, &_16$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_15$$13, "phalcon/cache/backend/file.zep", 476 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(&cachedContent)) {
				ZEPHIR_INIT_VAR(&newValue);
				ZVAL_LONG(&newValue, (zephir_get_numberval(&cachedContent) + value));
				ZEPHIR_INIT_VAR(&_17$$14);
				zephir_create_array(&_17$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_18$$14);
				zephir_time(&_18$$14);
				zephir_array_update_string(&_17$$14, SL("created"), &_18$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_18$$14);
				ZVAL_LONG(&_18$$14, ttl);
				zephir_array_update_string(&_17$$14, SL("lifetime"), &_18$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_17$$14, SL("content"), &newValue, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_VAR(&result);
				zephir_json_encode(&result, &_17$$14, 0 );
				ZEPHIR_INIT_NVAR(&_18$$14);
				zephir_file_put_contents(&_18$$14, &cacheFile, &result TSRMLS_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_18$$14)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory could not be written", "phalcon/cache/backend/file.zep", 484);
					return;
				}
				RETURN_CCTOR(&newValue);
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache value is not numeric, therefore could not be incremented", "phalcon/cache/backend/file.zep", 489);
				return;
			}
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, keyName);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		RETURN_MM_NULL();
	}
	RETURN_MM_NULL();

}

/**
 * Decrement of a given key, by number $value
 *
 * @param string|int keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_File, decrement) {

	zval _19$$16;
	zend_long value, ZEPHIR_LAST_CALL_STATUS, ttl = 0, modifiedTime = 0, lifetime = 0;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$true, __$null, prefixedKey, cacheFile, cachedContent, result, lastLifetime, newValue, _0, _1, _2, _3, _4$$3, _10$$3, _11$$3, _5$$4, _6$$4, _7$$5, _8$$7, _9$$7, _12$$10, _13$$11, _14$$12, _15$$12, _16$$14, _17$$15, _18$$15, _20$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cacheFile);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&lastLifetime);
	ZVAL_UNDEF(&newValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_19$$16);

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
	zephir_array_fetch_string(&_3, &_2, SL("cacheDir"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 516 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&cacheFile);
	ZEPHIR_CONCAT_VV(&cacheFile, &_3, &prefixedKey);
	if ((zephir_file_exists(&cacheFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_file_get_contents(&_4$$3, &cacheFile TSRMLS_CC);
		ZEPHIR_INIT_VAR(&cachedContent);
		zephir_json_decode(&cachedContent, &_4$$3, zephir_get_intval(&__$true) );
		if (!(lifetime)) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "lifetime");
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_6$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$4)) {
				ZEPHIR_OBS_VAR(&_7$$5);
				zephir_array_fetch_string(&_7$$5, &cachedContent, SL("lifetime"), PH_NOISY, "phalcon/cache/backend/file.zep", 531 TSRMLS_CC);
				ttl = zephir_get_intval(&_7$$5);
			} else {
				ZEPHIR_OBS_VAR(&lastLifetime);
				zephir_read_property(&lastLifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
				if (!(zephir_is_true(&lastLifetime))) {
					zephir_read_property(&_8$$7, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_9$$7, &_8$$7, "getlifetime", NULL, 0);
					zephir_check_call_status();
					ttl = zephir_get_intval(&_9$$7);
				} else {
					ttl = zephir_get_intval(&lastLifetime);
				}
			}
		} else {
			ttl = lifetime;
		}
		ZEPHIR_INIT_VAR(&_11$$3);
		ZVAL_STRING(&_11$$3, "created");
		ZEPHIR_CALL_METHOD(&_10$$3, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_11$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_10$$3))) {
			ZEPHIR_INIT_VAR(&_12$$10);
			zephir_filemtime(&_12$$10, &cacheFile TSRMLS_CC);
			modifiedTime = zephir_get_intval(&_12$$10);
			ttl = lifetime;
		} else {
			ZEPHIR_OBS_VAR(&_13$$11);
			zephir_array_fetch_string(&_13$$11, &cachedContent, SL("created"), PH_NOISY, "phalcon/cache/backend/file.zep", 548 TSRMLS_CC);
			modifiedTime = zephir_get_intval(&_13$$11);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 101, &__$true, &cacheFile);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_11$$3);
		zephir_time(&_11$$3);
		if (!((zephir_get_numberval(&_11$$3) - ttl) > modifiedTime)) {
			ZEPHIR_INIT_VAR(&_15$$12);
			ZVAL_STRING(&_15$$12, "content");
			ZEPHIR_CALL_METHOD(&_14$$12, this_ptr, "isvalidarray", NULL, 100, &cachedContent, &_15$$12);
			zephir_check_call_status();
			if (!(zephir_is_true(&_14$$12))) {
				ZEPHIR_INIT_NVAR(&cachedContent);
				zephir_file_get_contents(&cachedContent, &cacheFile TSRMLS_CC);
			} else {
				zephir_array_fetch_string(&_16$$14, &cachedContent, SL("content"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/file.zep", 565 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&cachedContent, &_16$$14);
			}
			if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
				ZEPHIR_INIT_VAR(&_17$$15);
				object_init_ex(&_17$$15, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(&_18$$15);
				ZEPHIR_CONCAT_SVS(&_18$$15, "Cache file ", &cacheFile, " could not be opened");
				ZEPHIR_CALL_METHOD(NULL, &_17$$15, "__construct", NULL, 4, &_18$$15);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_17$$15, "phalcon/cache/backend/file.zep", 569 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(&cachedContent)) {
				ZEPHIR_INIT_VAR(&newValue);
				ZVAL_LONG(&newValue, (zephir_get_numberval(&cachedContent) - value));
				ZEPHIR_INIT_VAR(&_19$$16);
				zephir_create_array(&_19$$16, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_20$$16);
				zephir_time(&_20$$16);
				zephir_array_update_string(&_19$$16, SL("created"), &_20$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_20$$16);
				ZVAL_LONG(&_20$$16, ttl);
				zephir_array_update_string(&_19$$16, SL("lifetime"), &_20$$16, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_19$$16, SL("content"), &newValue, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_VAR(&result);
				zephir_json_encode(&result, &_19$$16, 0 );
				ZEPHIR_INIT_NVAR(&_20$$16);
				zephir_file_put_contents(&_20$$16, &cacheFile, &result TSRMLS_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_20$$16)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache directory can't be written", "phalcon/cache/backend/file.zep", 576);
					return;
				}
				RETURN_CCTOR(&newValue);
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache value is not numeric, therefore could not decrement it", "phalcon/cache/backend/file.zep", 581);
				return;
			}
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, keyName);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		RETURN_MM_NULL();
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/file.zep", 606);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, spl_ce_DirectoryIterator);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 103, &cacheDir);
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
				ZEPHIR_CALL_FUNCTION(&_5$$6, "unlink", &_6, 102, &cacheFile);
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

