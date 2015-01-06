
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "cache/backend/file.h"
#include "cache/backend.h"
#include "cache/backendinterface.h"
#include "cache/exception.h"

#include <ext/spl/spl_directory.h>

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
zend_class_entry *phalcon_cache_backend_file_ce;

PHP_METHOD(Phalcon_Cache_Backend_File, __construct);
PHP_METHOD(Phalcon_Cache_Backend_File, get);
PHP_METHOD(Phalcon_Cache_Backend_File, save);
PHP_METHOD(Phalcon_Cache_Backend_File, delete);
PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_File, exists);
PHP_METHOD(Phalcon_Cache_Backend_File, increment);
PHP_METHOD(Phalcon_Cache_Backend_File, decrement);
PHP_METHOD(Phalcon_Cache_Backend_File, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cache_backend_file_method_entry[] = {
	PHP_ME(Phalcon_Cache_Backend_File, __construct, arginfo_phalcon_cache_backend_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_File, get, arginfo_phalcon_cache_backendinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, save, arginfo_phalcon_cache_backendinterface_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, delete, arginfo_phalcon_cache_backendinterface_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, queryKeys, arginfo_phalcon_cache_backendinterface_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, exists, arginfo_phalcon_cache_backendinterface_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, increment, arginfo_phalcon_cache_backendinterface_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, decrement, arginfo_phalcon_cache_backendinterface_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Cache\Backend\File initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_File){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, File, cache_backend_file, phalcon_cache_backend_ce, phalcon_cache_backend_file_method_entry, 0);

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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &frontend, &options);

	if (!options || !phalcon_array_isset_string(options, SS("cacheDir"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory must be specified with the option cacheDir");
		return;
	}

	PHALCON_CALL_PARENT(NULL, phalcon_cache_backend_file_ce, this_ptr, "__construct", frontend, options);
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
	zval *options, *prefix, *prefixed_key, *cache_dir;
	zval *cache_file, *tmp = NULL;
	zval *modified_time;
	zval *cached_content, *exception_message;
	long int now, ttl, mtime, diff;
	int expired;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

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

		zval *frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);

		/**
		 * Check if the file has expired
		 */
		now = (long int)time(NULL);

		/**
		 * Take the lifetime from the frontend or read it from the set in start()
		 */
		if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
			zval *last_lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY TSRMLS_CC);

			if (Z_TYPE_P(last_lifetime) == IS_NULL) {
				PHALCON_CALL_METHOD(&tmp, frontend, "getlifetime");
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

			if (phalcon_is_numeric(cached_content)) {
				RETURN_CCTOR(cached_content);
			} else {
				/**
				 * Use the frontend to process the content of the cache
				 */
				PHALCON_RETURN_CALL_METHOD(frontend, "afterretrieve", cached_content);
			}

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
	zval *cache_file, *cached_content = NULL, *prepared_content = NULL, *status, *is_buffering = NULL;
	zval *last_key, *frontend, *options, *cache_dir;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);

	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}

	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	options  = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

	if (unlikely(!phalcon_array_isset_string_fetch(&cache_dir, options, SS("cacheDir")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);

	if (!content || !zend_is_true(content)) {
		PHALCON_CALL_METHOD(&cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}

	PHALCON_CALL_METHOD(&prepared_content, frontend, "beforestore", cached_content);

	/**
	 * We use file_put_contents to respect open-base-dir directive
	 */
	PHALCON_INIT_VAR(status);
	if (!phalcon_is_numeric(cached_content)) {
		phalcon_file_put_contents(status, cache_file, prepared_content TSRMLS_CC);
	} else {
		phalcon_file_put_contents(status, cache_file, cached_content TSRMLS_CC);
	}
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory is not writable");
		return;
	}

	PHALCON_CALL_METHOD(&is_buffering, frontend, "isbuffering");
	if (!stop_buffer || PHALCON_IS_TRUE(stop_buffer)) {
		PHALCON_CALL_METHOD(NULL, frontend, "stop");
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

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

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

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

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
	PHALCON_CALL_METHOD(NULL, iterator, "__construct", cache_dir);

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

		PHALCON_OBSERVE_OR_NULLIFY_VAR(is_directory);
		if (FAILURE == phalcon_call_method(&is_directory, *item, "isdir", 0, NULL TSRMLS_CC)) {
			break;
		}

		if (!EG(exception) && PHALCON_IS_FALSE(is_directory)) {
			PHALCON_OBSERVE_OR_NULLIFY_VAR(key);
			if (FAILURE == phalcon_call_method(&key, *item, "getfilename", 0, NULL TSRMLS_CC)) {
				break;
			}

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
	zval *cache_dir, *cache_file, *frontend;
	zval *tmp = NULL, *modified_time;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);

	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

		PHALCON_OBS_VAR(cache_dir);
		phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY);

		PHALCON_INIT_VAR(cache_file);
		PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);

		if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
			long int mtime, ttl;

			frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);

			/**
			 * Check if the file has expired
			 */
			if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
				PHALCON_CALL_METHOD(&tmp, frontend, "getlifetime");

				ttl = likely(Z_TYPE_P(tmp) == IS_LONG) ? Z_LVAL_P(tmp) : phalcon_get_intval(tmp);
			} else {
				ttl = likely(Z_TYPE_P(lifetime) == IS_LONG) ? Z_LVAL_P(lifetime) : phalcon_get_intval(lifetime);
			}

			PHALCON_INIT_VAR(modified_time);
			phalcon_filemtime(modified_time, cache_file TSRMLS_CC);
			mtime = likely(Z_TYPE_P(modified_time) == IS_LONG) ? Z_LVAL_P(modified_time) : phalcon_get_intval(modified_time);

			if (mtime + ttl > (long int)time(NULL)) {
				RETURN_MM_TRUE;
			}
		}
	}

	RETURN_MM_FALSE;
}

/**
 * Increment of a given key, by number $value
 *
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, increment){

	zval **key_name, **value = NULL, *lifetime = NULL, *options, *prefix, *prefixed_key, *status;
	zval *cache_dir, *cache_file;
	zval *modified_time;
	zval *cached_content, *tmp = NULL;
	long int now, ttl, mtime, diff;
	int expired;

	phalcon_fetch_params_ex(1, 1, &key_name, &value);
	if (!value || Z_TYPE_PP(value) == IS_NULL) {
		value = &PHALCON_GLOBAL(z_one);
	}
	else {
		PHALCON_ENSURE_IS_LONG(value);
	}

	PHALCON_MM_GROW();

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, *key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);

	PHALCON_OBS_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY);

	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, prefixed_key);
	assert(Z_TYPE_P(cache_file) == IS_STRING);

	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {

		zval *frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
		/**
		 * Check if the file has expired
		 */
		now = (long int)time(NULL);

		/**
		 * Take the lifetime from the frontend or read it from the set in start()
		 */
		if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
			zval *last_lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY TSRMLS_CC);

			if (Z_TYPE_P(last_lifetime) == IS_NULL) {
				PHALCON_CALL_METHOD(&tmp, frontend, "getlifetime");
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
				zend_throw_exception_ex(phalcon_cache_exception_ce, 0 TSRMLS_CC, "Failed to open cache file %s", Z_STRVAL_P(cache_file));
				RETURN_MM();
			}

			add_function(return_value, *value, cached_content TSRMLS_CC);

			PHALCON_INIT_VAR(status);
			phalcon_file_put_contents(status, cache_file, return_value TSRMLS_CC);

			if (PHALCON_IS_FALSE(status)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory can't be written");
				return;
			}

			RETURN_MM();
		}
	}

	RETVAL_FALSE;
	PHALCON_MM_RESTORE();
}

/**
 * Decrement of a given key, by number $value
 *
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, decrement){

	zval **key_name, **value = NULL, *lifetime = NULL, *options, *prefix, *prefixed_key, *status;
	zval *cache_dir, *cache_file;
	zval *modified_time;
	zval *cached_content, *tmp = NULL;
	long int now, ttl, mtime, diff;
	int expired;

	phalcon_fetch_params_ex(1, 1, &key_name, &value);
	if (!value || Z_TYPE_PP(value) == IS_NULL) {
		value = &PHALCON_GLOBAL(z_one);
	}
	else {
		PHALCON_ENSURE_IS_LONG(value);
	}

	PHALCON_MM_GROW();

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, *key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);

	PHALCON_OBS_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, options, SL("cacheDir"), PH_NOISY);

	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, prefixed_key);
	assert(Z_TYPE_P(cache_file) == IS_STRING);

	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {

		zval *frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
		/**
		 * Check if the file has expired
		 */
		now = (long int)time(NULL);

		/**
		 * Take the lifetime from the frontend or read it from the set in start()
		 */
		if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
			zval *last_lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY TSRMLS_CC);

			if (Z_TYPE_P(last_lifetime) == IS_NULL) {
				PHALCON_CALL_METHOD(&tmp, frontend, "getlifetime");
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
				zend_throw_exception_ex(phalcon_cache_exception_ce, 0 TSRMLS_CC, "Failed to open cache file %s", Z_STRVAL_P(cache_file));
				RETURN_MM();
			}

			sub_function(return_value, cached_content, *value TSRMLS_CC);

			PHALCON_INIT_VAR(status);
			phalcon_file_put_contents(status, cache_file, return_value TSRMLS_CC);

			if (PHALCON_IS_FALSE(status)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cache directory can't be written");
				return;
			}

			RETURN_MM();
		}
	}

	RETVAL_FALSE;
	PHALCON_MM_RESTORE();
}

/**
 * Immediately invalidates all existing items.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, flush){

	zval *options, *prefix, *cache_dir, *iterator;
	zval **item, *is_file = NULL, *key = NULL, *cache_file = NULL;
	zend_object_iterator *it;

	PHALCON_MM_GROW();

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	if (unlikely(!phalcon_array_isset_string_fetch(&cache_dir, options, SS("cacheDir")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	PHALCON_INIT_VAR(iterator);
	object_init_ex(iterator, spl_ce_DirectoryIterator);
	assert(phalcon_has_constructor(iterator TSRMLS_CC));
	PHALCON_CALL_METHOD(NULL, iterator, "__construct", cache_dir);

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

		PHALCON_OBSERVE_OR_NULLIFY_VAR(is_file);
		if (FAILURE == phalcon_call_method(&is_file, *item, "isfile", 0, NULL TSRMLS_CC)) {
			break;
		}

		if (PHALCON_IS_TRUE(is_file)) {
			PHALCON_OBSERVE_OR_NULLIFY_VAR(key);
			if (FAILURE == phalcon_call_method(&key, *item, "getfilename", 0, NULL TSRMLS_CC)) {
				break;
			}

			PHALCON_OBSERVE_OR_NULLIFY_VAR(cache_file);
			if (FAILURE == phalcon_call_method(&cache_file, *item, "getpathname", 0, NULL TSRMLS_CC)) {
				break;
			}

			if (PHALCON_IS_EMPTY(prefix) || phalcon_start_with(key, prefix, NULL)) {
				phalcon_unlink(return_value, cache_file TSRMLS_CC);
			}
		}

		it->funcs->move_forward(it TSRMLS_CC);
	}

	it->funcs->dtor(it TSRMLS_CC);

	RETURN_MM_TRUE;
}
