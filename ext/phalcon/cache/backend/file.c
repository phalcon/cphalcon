
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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

	zval *frontend, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_array_isset_string(options, SS("cacheDir")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory must be specified with the option cacheDir");
		return;
	}
	zephir_call_parent_p2_noret(this_ptr, phalcon_cache_backend_file_ce, "__construct", frontend, options);
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

	int ttl, modifiedTime;
	zval *keyName, *lifetime = NULL, *options, *prefix, *prefixedKey, *cacheDir, *cacheFile, *frontend, *now, *lastLifetime, *tmp, *cachedContent, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&cacheDir, options, SS("cacheDir"), 1 TSRMLS_CC)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, cacheDir, prefixedKey);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "file_exists", cacheFile);
	if (ZEPHIR_IS_TRUE(_0)) {
		frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(now);
		zephir_call_func(now, "time");
		if (!(zephir_is_true(lifetime))) {
			lastLifetime = zephir_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
			if (!(zephir_is_true(lastLifetime))) {
				ZEPHIR_INIT_VAR(tmp);
				zephir_call_method(tmp, frontend, "getlifetime");
				ttl = zephir_get_intval(tmp);
			} else {
				ttl = zephir_get_intval(lastLifetime);
			}
		} else {
			ttl = zephir_get_intval(lifetime);
		}
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "filemtime", cacheFile);
		modifiedTime = zephir_get_intval(_1);
		if (!(((zephir_get_numberval(now) - ttl) > modifiedTime))) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_call_func_p1(cachedContent, "get_file_contents", cacheFile);
			if (!(zephir_is_true(cachedContent))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_2);
				ZEPHIR_CONCAT_SVS(_2, "Cache file ", cacheFile, " could not be opened");
				zephir_call_method_p1_noret(_1, "__construct", _2);
				zephir_throw_exception(_1 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(cachedContent)) {
				RETURN_CCTOR(cachedContent);
			} else {
				zephir_call_method_p1(return_value, frontend, "afterretrieve", cachedContent);
				RETURN_MM();
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

	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastKey, *lastPrefix, *frontend, *cacheDir, *isBuffering, *cacheFile, *cachedContent = NULL, *preparedContent, *status, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer) {
		stopBuffer = ZEPHIR_GLOBAL(global_true);
	}


	if (!(zephir_is_true(keyName))) {
		lastKey = zephir_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(lastPrefix);
		ZEPHIR_CONCAT_VV(lastPrefix, _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, cacheDir, lastKey);
	if (!(zephir_is_true(content))) {
		ZEPHIR_INIT_VAR(cachedContent);
		zephir_call_method(cachedContent, frontend, "getcontent");
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	ZEPHIR_INIT_VAR(preparedContent);
	zephir_call_method_p1(preparedContent, frontend, "beforestore", cachedContent);
	ZEPHIR_INIT_VAR(status);
	if (!(zephir_is_numeric(cachedContent))) {
		zephir_call_func_p2(status, "file_put_contents", cacheFile, preparedContent);
	} else {
		zephir_call_func_p2(status, "file_put_contents", cacheFile, cachedContent);
	}
	if (!(zephir_is_true(status))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory is not writable");
		return;
	}
	ZEPHIR_INIT_VAR(isBuffering);
	zephir_call_method(isBuffering, frontend, "isbuffering");
	if (!(zephir_is_true(stopBuffer))) {
		zephir_call_method_noret(frontend, "stop");
	}
	if (zephir_is_true(isBuffering)) {
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

	zval *keyName, *prefix, *prefixedKey, *cacheFile, *cacheDir, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, cacheDir, prefixedKey);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "file_exists", cacheFile);
	if (zephir_is_true(_1)) {
		zephir_call_func_p1(return_value, "unlink", cacheFile);
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

	zend_function *_8 = NULL, *_9 = NULL;
	HashTable *_5;
	HashPosition _4;
	zend_class_entry *_2;
	zval *prefix = NULL, *item = NULL, *key = NULL, *ret, *cacheDir, *_0, *_1, *_3, **_6, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&cacheDir, _0, SS("cacheDir"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	ZEPHIR_INIT_VAR(ret);
	array_init(ret);
	ZEPHIR_INIT_VAR(_1);
	_2 = zend_fetch_class(SL("DirectoryIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_1, _2);
	zephir_call_method_p1_noret(_1, "__construct", cacheDir);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "iterator", _1);
	zephir_is_iterable(_3, &_5, &_4, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(item, _6);
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_method_cache(_7, item, "isdir", &_8);
		if (ZEPHIR_IS_FALSE(_7)) {
			ZEPHIR_INIT_NVAR(key);
			zephir_call_method_cache(key, item, "getfilename", &_9);
			if (zephir_start_with(key, prefix)) {
				zephir_array_append(&ret, key, PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(ret);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string|int keyName
 * @param   int lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, exists) {

	int lifetime, ttl;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey, *prefix, *cacheDir, *cacheFile, *_0, *_1, *_2, *_3 = NULL, *_4;

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


	ZEPHIR_INIT_VAR(lastKey);
	if (!(zephir_is_true(keyName))) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
	}
	if (zephir_is_true(lastKey)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		zephir_array_fetch_string(&cacheDir, _0, SL("cacheDir"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(cacheFile);
		ZEPHIR_CONCAT_VV(cacheFile, cacheDir, lastKey);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "file_exists", cacheFile);
		if (zephir_is_true(_1)) {
			if (!(lifetime)) {
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_3);
				zephir_call_method(_3, _2, "getlifetime");
				ttl = zephir_get_intval(_3);
			} else {
				ttl = zephir_get_intval(lifetime);
			}
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_func_p1(_3, "filemtime", cacheFile);
			ZEPHIR_INIT_VAR(_4);
			zephir_call_func(_4, "time");
			if (ZEPHIR_IS_LONG(_4, (zephir_get_numberval(_3) + ttl))) {
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

	int value;
	zval *keyName = NULL, *value_param = NULL, *prefixedKey, *cacheFile, *frontend, *timestamp, *lifetime, *ttl = NULL, *cachedContent, *result, *_0, *_1, *_2, *_3, *_4, *_5, *_6 = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value_param) {
		value = 0;
	} else {
		value = zephir_get_intval(value_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("cacheDir"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, _2, prefixedKey);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "file_exists", cacheFile);
	if (zephir_is_true(_3)) {
		frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(timestamp);
		zephir_call_func(timestamp, "time");
		lifetime = zephir_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(lifetime))) {
			ZEPHIR_INIT_VAR(ttl);
			zephir_call_method(ttl, frontend, "getlifetime");
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
		}
		ZEPHIR_INIT_VAR(_4);
		sub_function(_4, timestamp, ttl TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		zephir_call_func_p1(_5, "filemtime", cacheFile);
		if (ZEPHIR_LS(_4, _5)) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_call_func_p1(cachedContent, "file_get_contents", cacheFile);
			if (!(zephir_is_true(cachedContent))) {
				ZEPHIR_INIT_VAR(_6);
				object_init_ex(_6, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_7);
				ZEPHIR_CONCAT_SVS(_7, "Cache file ", cacheFile, " could not be opened");
				zephir_call_method_p1_noret(_6, "__construct", _7);
				zephir_throw_exception(_6 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(cachedContent)) {
				ZEPHIR_INIT_VAR(result);
				ZVAL_LONG(result, (value + zephir_get_numberval(cachedContent)));
				ZEPHIR_INIT_NVAR(_6);
				zephir_call_func_p2(_6, "file_put_contents", cacheFile, result);
				if (!(zephir_is_true(_6))) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory can't be written");
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

	int value;
	zval *keyName = NULL, *value_param = NULL, *prefixedKey, *cacheFile, *timestamp, *lifetime, *ttl = NULL, *cachedContent, *status, *result, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value_param) {
		value = 0;
	} else {
		value = zephir_get_intval(value_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("cacheDir"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(cacheFile);
	ZEPHIR_CONCAT_VV(cacheFile, _2, prefixedKey);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "file_exists", cacheFile);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(timestamp);
		zephir_call_func(timestamp, "time");
		lifetime = zephir_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(lifetime))) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(ttl);
			zephir_call_method(ttl, _4, "getlifetime");
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
		}
		ZEPHIR_INIT_VAR(_5);
		sub_function(_5, timestamp, ttl TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		zephir_call_func_p1(_6, "filemtime", cacheFile);
		if (ZEPHIR_LS(_5, _6)) {
			ZEPHIR_INIT_VAR(cachedContent);
			zephir_call_func_p1(cachedContent, "file_get_contents", cacheFile);
			if (!(zephir_is_true(cachedContent))) {
				ZEPHIR_INIT_VAR(_7);
				object_init_ex(_7, phalcon_cache_exception_ce);
				ZEPHIR_INIT_VAR(_8);
				ZEPHIR_CONCAT_SVS(_8, "Cache file ", cacheFile, " could not be opened");
				zephir_call_method_p1_noret(_7, "__construct", _8);
				zephir_throw_exception(_7 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_numeric(cachedContent)) {
				ZEPHIR_INIT_VAR(result);
				ZVAL_LONG(result, (value - zephir_get_numberval(cachedContent)));
				ZEPHIR_INIT_VAR(status);
				zephir_call_func_p2(status, "file_put_contents", cacheFile, result);
				if (!(zephir_is_true(status))) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory can't be written");
					return;
				}
				RETURN_CCTOR(result);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

