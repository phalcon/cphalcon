
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

#include "ext/spl/spl_directory.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
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

	zval *frontend, *options = NULL;

	phalcon_fetch_params(0, 1, 1, &frontend, &options);
	
	if (!options || !phalcon_array_isset_string(options, SS("cacheDir"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory must be specified with the option cacheDir");
		return;
	}

	PHALCON_MM_GROW();
	phalcon_call_parent_p2_noret(this_ptr, phalcon_cache_backend_file_ce, "__construct", frontend, options);
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

	zval *key_name, *lifetime = NULL;
	zval *options, *prefix, *prefixed_key, *cache_dir, *frontend;
	zval *cache_file, *tmp;
	zval *modified_time;
	zval *cached_content, *exception_message;
	long int now, ttl, mtime, diff;
	int expired;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&cache_dir, options, SS("cacheDir")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, prefixed_key);
	
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
	
		frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	
		/** 
		 * Check if the file has expired
		 */
		now = (long int)time(NULL);
	
		/** 
		 * Take the lifetime from the frontend or read it from the set in start()
		 */
		if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
			zval *last_lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);

			if (Z_TYPE_P(last_lifetime) == IS_NULL) {
				PHALCON_OBS_VAR(tmp);
				phalcon_call_method_p0_ex(tmp, &tmp, frontend, "getlifetime");
				ttl = phalcon_get_intval(tmp);
			} else {
				ttl = phalcon_get_intval(last_lifetime);
			}
		} else {
			ttl = phalcon_get_intval(lifetime);
		}
	
		PHALCON_INIT_VAR(modified_time);
		phalcon_filemtime(modified_time, cache_file TSRMLS_CC);
		if (unlikely(Z_TYPE_P(modified_time) != IS_LONG)) {
			convert_to_long(modified_time);
		}

		mtime   = Z_LVAL_P(modified_time);
		diff    = now - ttl;
		expired = diff > mtime;

		/** 
		 * The content is only retrieved if the content has not expired
		 */
		if (!expired) {
	
			/** 
			 * Use file-get-contents to control that the openbase_dir can't be skipped
			 */
			PHALCON_INIT_VAR(cached_content);
			phalcon_file_get_contents(cached_content, cache_file TSRMLS_CC);
			if (PHALCON_IS_FALSE(cached_content)) {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Cache file ", cache_file, " could not be opened");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_cache_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Use the frontend to process the content of the cache
			 */
			phalcon_call_method_p1_ex(return_value, return_value_ptr, frontend, "afterretrieve", cached_content);
			RETURN_MM();
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
	zval *cache_file, *cached_content, *prepared_content, *status, *is_buffering;
	zval *last_key, *frontend, *options, *cache_dir;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	options  = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&cache_dir, options, SS("cacheDir")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);

	if (!content || !zend_is_true(content)) {
		PHALCON_OBS_VAR(cached_content);
		phalcon_call_method_p0_ex(cached_content, &cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}
	
	PHALCON_OBS_VAR(prepared_content);
	phalcon_call_method_p1_ex(prepared_content, &prepared_content, frontend, "beforestore", cached_content);
	
	/** 
	 * We use file_put_contents to respect open-base-dir directive
	 */
	PHALCON_INIT_VAR(status);
	phalcon_file_put_contents(status, cache_file, prepared_content TSRMLS_CC);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory is not writable");
		return;
	}
	
	PHALCON_OBS_VAR(is_buffering);
	phalcon_call_method_p0_ex(is_buffering, &is_buffering, frontend, "isbuffering");
	if (!stop_buffer || PHALCON_IS_TRUE(stop_buffer)) {
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

	zval *key_name, *prefixed_key, *cache_file;
	zval *options, *prefix, *cache_dir;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&cache_dir, options, SS("cacheDir")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, prefixed_key);
	
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		phalcon_unlink(return_value, cache_file TSRMLS_CC);
		RETURN_MM();
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

	zval *prefix = NULL, *options, *cache_dir, *iterator;
	zval **item, *is_directory = NULL, *key = NULL;
	zend_object_iterator *it;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	array_init(return_value);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&cache_dir, options, SS("cacheDir")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	
	/** 
	 * We use a directory iterator to traverse the cache dir directory
	 */
	PHALCON_INIT_VAR(iterator);
	object_init_ex(iterator, spl_ce_DirectoryIterator);
	assert(phalcon_has_constructor(iterator TSRMLS_CC));
	phalcon_call_method_p1_noret(iterator, "__construct", cache_dir);

	/* DirectoryIterator implements Iterator */
	assert(instanceof_function_ex(spl_ce_DirectoryIterator, zend_ce_iterator, 1 TSRMLS_CC));

	it = spl_ce_DirectoryIterator->get_iterator(spl_ce_DirectoryIterator, iterator, 0 TSRMLS_CC);

	/* DirectoryIterator is an iterator */
	assert(it != NULL);

	/* DirectoryIterator has rewind() method */
	assert(it->funcs->rewind != NULL);

	it->funcs->rewind(it TSRMLS_CC);
	while (it->funcs->valid(it TSRMLS_CC) == SUCCESS && !EG(exception)) {
		it->funcs->get_current_data(it, &item TSRMLS_CC);

		PHALCON_OBS_NVAR(is_directory);
		phalcon_call_method_params(is_directory, &is_directory, *item, SL("isdir"), zend_inline_hash_func(SS("isdir")) TSRMLS_CC, 0);

		if (!EG(exception) && PHALCON_IS_FALSE(is_directory)) {
			PHALCON_OBS_NVAR(key);
			phalcon_call_method_params(key, &key, *item, SL("getfilename"), zend_inline_hash_func(SS("getfilename")) TSRMLS_CC, 0);

			if (!EG(exception) && (!prefix || phalcon_start_with(key, prefix, NULL))) {
				phalcon_array_append(&return_value, key, 0);
			}
		}
	
		it->funcs->move_forward(it TSRMLS_CC);
	}

	it->funcs->dtor(it TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string $keyName
 * @param   long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, exists){

	zval *key_name = NULL, *lifetime = NULL, *last_key, *options;
	zval *cache_dir, *cache_file, *frontend, *timestamp;
	zval *ttl = NULL, *modified_time, *difference, *not_expired;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);

		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(cache_dir);
		phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY);
	
		PHALCON_INIT_VAR(cache_file);
		PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);
	
		if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
			frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	
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
			phalcon_filemtime(modified_time, cache_file TSRMLS_CC);
	
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
