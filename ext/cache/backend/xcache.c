
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
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>              |
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
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"

/**
 * Phalcon\Cache\Backend\Xcache
 *
 * Allows to cache output fragments, PHP data and raw data using an XCache backend
 *
 *<code>
 *	//Cache data for 2 days
 *	$frontCache = new Phalcon\Cache\Frontend\Data(array(
 *		'lifetime' => 172800
 *	));
 *
 *  $cache = new Phalcon\Cache\Backend\Xcache($frontCache, array(
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


/**
 * Phalcon\Cache\Backend\Xcache initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Xcache){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Xcache, cache_backend_xcache, "phalcon\\cache\\backend", phalcon_cache_backend_xcache_method_entry, 0);

	zend_class_implements(phalcon_cache_backend_xcache_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Backend\Xcache constructor
 *
 * @param Phalcon\Cache\FrontendInterface $frontend
 * @param array $options
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, __construct){

	zval *frontend, *options = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &frontend, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
	} else {
		PHALCON_SEPARATE_PARAM(options);
	}
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	if (!phalcon_array_isset_string(options, SS("statsKey"))) {
		phalcon_array_update_string_string(&options, SL("statsKey"), SL("_PHCX"), PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Cache\\Backend\\Xcache", "__construct", frontend, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns cached content
 *
 * @param string $keyName
 * @param long $lifetime
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, get){

	zval *key_name, *lifetime = NULL, *frontend, *prefix, *prefixed_key;
	zval *cached_content, *processed;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	PHALCON_OBS_VAR(frontend);
	phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SVV(prefixed_key, "_PHCX", prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_INIT_VAR(cached_content);
	phalcon_call_func_p1(cached_content, "xcache_get", prefixed_key);
	if (Z_TYPE_P(cached_content) == IS_NULL) {
		RETURN_MM_NULL();
	}
	
	PHALCON_INIT_VAR(processed);
	phalcon_call_method_p1(processed, frontend, "afterretrieve", cached_content);
	
	RETURN_CCTOR(processed);
}

/**
 * Stores cached content into the XCache backend and stops the frontend
 *
 * @param string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key = NULL, *prefix, *frontend, *cached_content = NULL;
	zval *prepared_content, *ttl = NULL, *success, *is_buffering;
	zval *options, *special_key, *keys = NULL, *zero;

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
	} else {
		PHALCON_SEPARATE_PARAM(lifetime);
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
		PHALCON_CONCAT_SVV(last_key, "_PHCX", prefix, key_name);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_OBS_VAR(frontend);
	phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (Z_TYPE_P(content) == IS_NULL) {
		PHALCON_INIT_VAR(cached_content);
		phalcon_call_method(cached_content, frontend, "getcontent");
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_INIT_VAR(prepared_content);
	phalcon_call_method_p1(prepared_content, frontend, "beforestore", cached_content);
	
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
	
	/** 
	 * Call apc_store in the PHP userland since most of the time it isn't available at
	 * compile time
	 */
	PHALCON_INIT_VAR(success);
	phalcon_call_func_p3(success, "xcache_set", last_key, prepared_content, ttl);
	
	PHALCON_INIT_VAR(is_buffering);
	phalcon_call_method(is_buffering, frontend, "isbuffering");
	if (PHALCON_IS_TRUE(stop_buffer)) {
		phalcon_call_method_noret(frontend, "stop");
	}
	
	if (PHALCON_IS_TRUE(is_buffering)) {
		zend_print_zval(cached_content, 0);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	
	/** 
	 * xcache_set() could fail because of Out of Memory condition. I don't think it is
	 * appropriate to throw an exception here (like
	 * Phalcon\Cache\Backend\Memcache::save() does): first, to be consistent with
	 * Phalcon\Cache\Backend\Apc::save(), second, because xCache is usually given much
	 * less RAM than memcached
	 */
	if (zend_is_true(success)) {
	
		PHALCON_OBS_VAR(options);
		phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(special_key);
		phalcon_array_fetch_string(&special_key, options, SL("statsKey"), PH_NOISY_CC);
	
		/** 
		 * xcache_list() is available only to the administrator (unless XCache was
		 * patched). We have to update the list of the stored keys.
		 */
		PHALCON_INIT_VAR(keys);
		phalcon_call_func_p1(keys, "xcache_get", special_key);
		if (Z_TYPE_P(keys) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(keys);
			array_init(keys);
		}
	
		if (!zend_is_true(keys)) {
			phalcon_array_update_zval(&keys, last_key, &ttl, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_VAR(zero);
			ZVAL_LONG(zero, 0);
			phalcon_call_func_p3_noret("xcache_set", special_key, keys, zero);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes a value from the cache by its key
 *
 * @param string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, delete){

	zval *key_name, *prefix, *prefixed_key, *success;
	zval *options, *special_key, *keys, *zero;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SVV(prefixed_key, "_PHCX", prefix, key_name);
	
	PHALCON_INIT_VAR(success);
	phalcon_call_func_p1(success, "xcache_unset", prefixed_key);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(special_key);
	phalcon_array_fetch_string(&special_key, options, SL("statsKey"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(keys);
	phalcon_call_func_p1(keys, "xcache_get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		PHALCON_INIT_VAR(zero);
		ZVAL_LONG(zero, 0);
		phalcon_array_unset(&keys, special_key, PH_SEPARATE);
		phalcon_call_func_p3_noret("xcache_set", special_key, keys, zero);
	}
	
	RETURN_CCTOR(success);
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, queryKeys){

	zval *prefix = NULL, *prefixed, *options, *special_key;
	zval *keys, *prefixed_keys, *ttl = NULL, *key = NULL, *real_key = NULL;
	zval *empty_arr;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	}
	
	PHALCON_INIT_VAR(prefixed);
	PHALCON_CONCAT_SV(prefixed, "_PHCX", prefix);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(special_key);
	phalcon_array_fetch_string(&special_key, options, SL("statsKey"), PH_NOISY_CC);
	
	/** 
	 * Get the key from XCache (we cannot use xcache_list() as it is available only to
	 * the administrator)
	 */
	PHALCON_INIT_VAR(keys);
	phalcon_call_func_p1(keys, "xcache_get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(prefixed_keys);
		array_init(prefixed_keys);
	
		phalcon_is_iterable(keys, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(ttl);
	
			if (!phalcon_memnstr(key, prefix TSRMLS_CC)) {
				zend_hash_move_forward_ex(ah0, &hp0);
				continue;
			}
	
			PHALCON_INIT_NVAR(real_key);
			phalcon_substr(real_key, key, 0, 5 TSRMLS_CC);
			phalcon_array_append(&prefixed_keys, real_key, PH_SEPARATE TSRMLS_CC);
	
			RETURN_CTOR(prefixed_keys);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	
	RETURN_CTOR(empty_arr);
}

/**
 * Checks if the cache entry exists and has not expired
 *
 * @param string $keyName
 * @param long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, exists){

	zval *key_name = NULL, *lifetime = NULL, *last_key = NULL, *prefix, *cache_exists;

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
		PHALCON_CONCAT_SVV(last_key, "_PHCX", prefix, key_name);
	}
	if (zend_is_true(last_key)) {
	
		PHALCON_INIT_VAR(cache_exists);
		phalcon_call_func_p1(cache_exists, "xcache_isset", last_key);
		if (PHALCON_IS_NOT_FALSE(cache_exists)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

