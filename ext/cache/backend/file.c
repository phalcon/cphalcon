
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/file.h"
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
 *	//Set the cache directory
 *	$backendOptions = array(
 *		'cacheDir' => '../app/cache/'
 *	);
 *
 *	$cache = Phalcon_Cache::factory('Output', 'File', $frontendOptions, $backendOptions);
 *
 *	$content = $cache->start('my-cache');
 *	if($content===null){
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

	zval *frontend, *options = NULL, *cache_dir, *is_writable;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &frontend, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	
	eval_int = phalcon_array_isset_string(options, SS("cacheDir"));
	if (eval_int) {
		PHALCON_INIT_VAR(cache_dir);
		phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
		/** 
		 * Prod mode?
		 */
		PHALCON_INIT_VAR(is_writable);
		PHALCON_CALL_FUNC_PARAMS_1(is_writable, "is_writable", cache_dir);
		if (PHALCON_IS_FALSE(is_writable)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache directory does not exist or is not writable");
			return;
		}
	
		PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Cache\\Backend\\File", "__construct", frontend, options);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "You must specify the cache directory with the option cacheDir");
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

	zval *key_name, *lifetime = NULL, *options, *prefix, *filtered;
	zval *prefixed_key, *cache_dir, *cache_file;
	zval *frontend, *time, *ttl = NULL, *modified_time, *difference;
	zval *not_expired, *cached_content, *processed;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!lifetime) {
		PHALCON_INIT_NVAR(lifetime);
	}
	
	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefix);
	phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(filtered);
	phalcon_filter_alphanum(filtered, key_name);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, filtered);
	phalcon_update_property_zval(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_INIT_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, prefixed_key);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(frontend);
		phalcon_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
		/** 
		 * Check if the file has expired
		 */
		PHALCON_INIT_VAR(time);
		PHALCON_CALL_FUNC(time, "time");
		if (Z_TYPE_P(lifetime) == IS_NULL) {
			PHALCON_INIT_VAR(ttl);
			PHALCON_CALL_METHOD(ttl, frontend, "getlifetime", PH_NO_CHECK);
		} else {
			PHALCON_CPY_WRT(ttl, lifetime);
		}
	
		PHALCON_INIT_VAR(modified_time);
		PHALCON_CALL_FUNC_PARAMS_1(modified_time, "filemtime", cache_file);
	
		PHALCON_INIT_VAR(difference);
		sub_function(difference, time, ttl TSRMLS_CC);
	
		PHALCON_INIT_VAR(not_expired);
		is_smaller_function(not_expired, difference, modified_time TSRMLS_CC);
	
		/** 
		 * The content is only retrieved if the content has not expired
		 */
		if (PHALCON_IS_TRUE(not_expired)) {
			PHALCON_INIT_VAR(cached_content);
			PHALCON_CALL_FUNC_PARAMS_1(cached_content, "file_get_contents", cache_file);
	
			PHALCON_INIT_VAR(processed);
			PHALCON_CALL_METHOD_PARAMS_1(processed, frontend, "afterretrieve", cached_content, PH_NO_CHECK);
	
			RETURN_CCTOR(processed);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	zval *last_key = NULL, *prefix, *filtered, *frontend, *options;
	zval *cache_dir, *cache_file, *cached_content = NULL;
	zval *prepared_content, *is_buffering;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzzz", &key_name, &content, &lifetime, &stop_buffer) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_NVAR(key_name);
	}
	
	if (!content) {
		PHALCON_INIT_NVAR(content);
	}
	
	if (!lifetime) {
		PHALCON_INIT_NVAR(lifetime);
	}
	
	if (!stop_buffer) {
		PHALCON_INIT_NVAR(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_INIT_VAR(last_key);
		phalcon_read_property(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(prefix);
		phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(filtered);
		phalcon_filter_alphanum(filtered, key_name);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, filtered);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_INIT_VAR(frontend);
	phalcon_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);
	if (!zend_is_true(content)) {
		PHALCON_INIT_VAR(cached_content);
		PHALCON_CALL_METHOD(cached_content, frontend, "getcontent", PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	/** 
	 * We use file_put_contents to repect open-base-dir directive
	 */
	PHALCON_INIT_VAR(prepared_content);
	PHALCON_CALL_METHOD_PARAMS_1(prepared_content, frontend, "beforestore", cached_content, PH_NO_CHECK);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", cache_file, prepared_content);
	
	PHALCON_INIT_VAR(is_buffering);
	PHALCON_CALL_METHOD(is_buffering, frontend, "isbuffering", PH_NO_CHECK);
	if (PHALCON_IS_TRUE(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(frontend, "stop", PH_NO_CHECK);
	}
	
	if (PHALCON_IS_TRUE(is_buffering)) {
		zend_print_zval(cached_content, 1);
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

	zval *key_name, *options, *prefix, *filtered, *prefixed_key;
	zval *cache_dir, *cache_file, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefix);
	phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(filtered);
	phalcon_filter_alphanum(filtered, key_name);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, filtered);
	
	PHALCON_INIT_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, prefixed_key);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_FUNC_PARAMS_1(success, "unlink", cache_file);
	
		RETURN_CCTOR(success);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &prefix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!prefix) {
		PHALCON_INIT_NVAR(prefix);
	}
	
	PHALCON_INIT_VAR(keys);
	array_init(keys);
	
	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
	/** 
	 * We use a directory iterator to traverse the cache dir directory
	 */
	ce0 = zend_fetch_class(SL("DirectoryIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(iterator);
	object_init_ex(iterator, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(iterator, "__construct", cache_dir, PH_CHECK);
	PHALCON_CALL_METHOD_NORETURN(iterator, "rewind", PH_NO_CHECK);
	ph_cycle_start_0:
	
		PHALCON_INIT_NVAR(r0);
		PHALCON_CALL_METHOD(r0, iterator, "valid", PH_NO_CHECK);
		if (!zend_is_true(r0)) {
			goto ph_cycle_end_0;
		}
		PHALCON_INIT_NVAR(item);
		PHALCON_CALL_METHOD(item, iterator, "current", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(is_directory);
		PHALCON_CALL_METHOD(is_directory, item, "isdir", PH_NO_CHECK);
		if (PHALCON_IS_FALSE(is_directory)) {
			PHALCON_INIT_NVAR(key);
			PHALCON_CALL_METHOD(key, item, "getfilename", PH_NO_CHECK);
			if (zend_is_true(prefix)) {
				if (!phalcon_start_with(key, prefix)) {
					goto ph_cycle_start_0;
				}
			}
	
			phalcon_array_append(&keys, key, PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_CALL_METHOD_NORETURN(iterator, "next", PH_NO_CHECK);
		goto ph_cycle_start_0;
	ph_cycle_end_0:
	
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

	zval *key_name = NULL, *lifetime = NULL, *last_key = NULL, *prefix, *filtered;
	zval *options, *cache_dir, *cache_file, *frontend;
	zval *time, *ttl = NULL, *modified_time, *difference, *not_expired;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &key_name, &lifetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_NVAR(key_name);
	}
	
	if (!lifetime) {
		PHALCON_INIT_NVAR(lifetime);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_INIT_VAR(last_key);
		phalcon_read_property(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(prefix);
		phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(filtered);
		phalcon_filter_alphanum(filtered, key_name);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, filtered);
	}
	if (zend_is_true(last_key)) {
		PHALCON_INIT_VAR(options);
		phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(cache_dir);
		phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(cache_file);
		PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);
		if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(frontend);
			phalcon_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
			/** 
			 * Check if the file has expired
			 */
			PHALCON_INIT_VAR(time);
			PHALCON_CALL_FUNC(time, "time");
			if (Z_TYPE_P(lifetime) == IS_NULL) {
				PHALCON_INIT_VAR(ttl);
				PHALCON_CALL_METHOD(ttl, frontend, "getlifetime", PH_NO_CHECK);
			} else {
				PHALCON_CPY_WRT(ttl, lifetime);
			}
	
			PHALCON_INIT_VAR(modified_time);
			PHALCON_CALL_FUNC_PARAMS_1(modified_time, "filemtime", cache_file);
	
			PHALCON_INIT_VAR(difference);
			sub_function(difference, time, ttl TSRMLS_CC);
	
			PHALCON_INIT_VAR(not_expired);
			is_smaller_function(not_expired, difference, modified_time TSRMLS_CC);
			if (PHALCON_IS_TRUE(not_expired)) {
				/** 
				 * We only return true if the file exists and it did not expired
				 */
				PHALCON_MM_RESTORE();
				RETURN_TRUE;
			}
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

