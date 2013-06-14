
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/string.h"

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


/**
 * Phalcon\Cache\Backend\File initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_File){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, File, cache_backend_file, "phalcon\\cache\\backend", phalcon_cache_backend_file_method_entry, 0);

	zend_class_implements(phalcon_cache_backend_file_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Backend\File constructor
 *
 * @param Phalcon\Cache\FrontendInterface $frontend
 * @param array $options
 */
PHP_METHOD(Phalcon_Cache_Backend_File, __construct){

	zval *frontend, *options = NULL, *cache_dir;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &frontend, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (phalcon_array_isset_string(options, SS("cacheDir"))) {
		PHALCON_OBS_VAR(cache_dir);
		phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
		PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Cache\\Backend\\File", "__construct", frontend, options);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory must be specified with the option cacheDir");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a cached content
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, get){

	zval *key_name, *lifetime = NULL, *options, *prefix, *prefixed_key;
	zval *cache_dir, *cache_file, *frontend, *timestamp;
	zval *ttl = NULL, *modified_time, *difference, *not_expired;
	zval *cached_content, *exception_message;
	zval *processed;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	} else {
		PHALCON_SEPARATE_PARAM(lifetime);
	}
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_OBS_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, prefixed_key);
	
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
	
		PHALCON_OBS_VAR(frontend);
		phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
		/** 
		 * Check if the file has expired
		 */
		PHALCON_INIT_VAR(timestamp);
		ZVAL_LONG(timestamp, (long) time(NULL));
	
		/** 
		 * Take the lifetime from the frontend or read it from the set in start()
		 */
		if (Z_TYPE_P(lifetime) == IS_NULL) {
	
			PHALCON_OBS_NVAR(lifetime);
			phalcon_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
			if (Z_TYPE_P(lifetime) == IS_NULL) {
				PHALCON_INIT_VAR(ttl);
				phalcon_call_method(ttl, frontend, "getlifetime");
			} else {
				PHALCON_CPY_WRT(ttl, lifetime);
			}
		} else {
			PHALCON_CPY_WRT(ttl, lifetime);
		}
	
		PHALCON_INIT_VAR(modified_time);
		phalcon_call_func_p1(modified_time, "filemtime", cache_file);
	
		PHALCON_INIT_VAR(difference);
		sub_function(difference, timestamp, ttl TSRMLS_CC);
	
		PHALCON_INIT_VAR(not_expired);
		is_smaller_function(not_expired, difference, modified_time TSRMLS_CC);
	
		/** 
		 * The content is only retrieved if the content has not expired
		 */
		if (PHALCON_IS_TRUE(not_expired)) {
	
			/** 
			 * Use file-get-contents to control that the openbase_dir can't be skipped
			 */
			PHALCON_INIT_VAR(cached_content);
			phalcon_call_func_p1(cached_content, "file_get_contents", cache_file);
			if (PHALCON_IS_FALSE(cached_content)) {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Cache file ", cache_file, " could not be opened");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_cache_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Use the frontend to process the content of the cache
			 */
			PHALCON_INIT_VAR(processed);
			phalcon_call_method_p1(processed, frontend, "afterretrieve", cached_content);
	
			RETURN_CCTOR(processed);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_File, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key = NULL, *prefix, *frontend, *options, *cache_dir;
	zval *cache_file, *cached_content = NULL, *prepared_content;
	zval *status, *is_buffering;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
	}
	
	if (!content) {
		PHALCON_INIT_VAR(content);
	}
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	if (!stop_buffer) {
		PHALCON_INIT_VAR(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_OBS_VAR(last_key);
		phalcon_read_property_this(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_OBS_VAR(prefix);
		phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_OBS_VAR(frontend);
	phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);
	if (!zend_is_true(content)) {
		PHALCON_INIT_VAR(cached_content);
		phalcon_call_method(cached_content, frontend, "getcontent");
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_INIT_VAR(prepared_content);
	phalcon_call_method_p1(prepared_content, frontend, "beforestore", cached_content);
	
	/** 
	 * We use file_put_contents to respect open-base-dir directive
	 */
	PHALCON_INIT_VAR(status);
	phalcon_call_func_p2(status, "file_put_contents", cache_file, prepared_content);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory can't be written");
		return;
	}
	
	PHALCON_INIT_VAR(is_buffering);
	phalcon_call_method(is_buffering, frontend, "isbuffering");
	if (PHALCON_IS_TRUE(stop_buffer)) {
		phalcon_call_method_noret(frontend, "stop");
	}
	
	if (PHALCON_IS_TRUE(is_buffering)) {
		zend_print_zval(cached_content, 0);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, delete){

	zval *key_name, *options, *prefix, *prefixed_key;
	zval *cache_dir, *cache_file, *success;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	
	PHALCON_OBS_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, prefixed_key);
	
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(success);
		phalcon_call_func_p1(success, "unlink", cache_file);
		RETURN_CCTOR(success);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys){

	zval *prefix = NULL, *keys, *options, *cache_dir, *iterator;
	zval *item = NULL, *is_directory = NULL, *key = NULL;
	zval *r0 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
	}
	
	PHALCON_INIT_VAR(keys);
	array_init(keys);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
	/** 
	 * We use a directory iterator to traverse the cache dir directory
	 */
	ce0 = zend_fetch_class(SL("DirectoryIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(iterator);
	object_init_ex(iterator, ce0);
	if (phalcon_has_constructor(iterator TSRMLS_CC)) {
		phalcon_call_method_p1_noret(iterator, "__construct", cache_dir);
	}
	phalcon_call_method_noret(iterator, "rewind");
	
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		phalcon_call_method(r0, iterator, "valid");
		if (zend_is_true(r0)) {
		} else {
			break;
		}
	
		PHALCON_INIT_NVAR(item);
		phalcon_call_method(item, iterator, "current");
	
		PHALCON_INIT_NVAR(is_directory);
		phalcon_call_method(is_directory, item, "isdir");
		if (PHALCON_IS_FALSE(is_directory)) {
	
			PHALCON_INIT_NVAR(key);
			phalcon_call_method(key, item, "getfilename");
			if (zend_is_true(prefix)) {
				if (!phalcon_start_with(key, prefix, NULL)) {
					continue;
				}
			}
	
			phalcon_array_append(&keys, key, PH_SEPARATE TSRMLS_CC);
		}
	
		phalcon_call_method_noret(iterator, "next");
	}
	
	RETURN_CTOR(keys);
}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string $keyName
 * @param   long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, exists){

	zval *key_name = NULL, *lifetime = NULL, *last_key = NULL, *prefix, *options;
	zval *cache_dir, *cache_file, *frontend, *timestamp;
	zval *ttl = NULL, *modified_time, *difference, *not_expired;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
	}
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_OBS_VAR(last_key);
		phalcon_read_property_this(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_OBS_VAR(prefix);
		phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	if (zend_is_true(last_key)) {
	
		PHALCON_OBS_VAR(options);
		phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(cache_dir);
		phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(cache_file);
		PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);
	
		if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
	
			PHALCON_OBS_VAR(frontend);
			phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
			/** 
			 * Check if the file has expired
			 */
			PHALCON_INIT_VAR(timestamp);
			ZVAL_LONG(timestamp, (long) time(NULL));
			if (Z_TYPE_P(lifetime) == IS_NULL) {
				PHALCON_INIT_VAR(ttl);
				phalcon_call_method(ttl, frontend, "getlifetime");
			} else {
				PHALCON_CPY_WRT(ttl, lifetime);
			}
	
			PHALCON_INIT_VAR(modified_time);
			phalcon_call_func_p1(modified_time, "filemtime", cache_file);
	
			PHALCON_INIT_VAR(difference);
			sub_function(difference, timestamp, ttl TSRMLS_CC);
	
			PHALCON_INIT_VAR(not_expired);
			is_smaller_function(not_expired, difference, modified_time TSRMLS_CC);
			if (PHALCON_IS_TRUE(not_expired)) {
				/** 
				 * We only return true if the file exists and it did not expired
				 */
				RETURN_MM_TRUE;
			}
		}
	}
	
	RETURN_MM_FALSE;
}

