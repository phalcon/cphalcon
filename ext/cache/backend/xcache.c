
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Xcache, cache_backend_xcache, phalcon_cache_backend_ce, phalcon_cache_backend_xcache_method_entry, 0);

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
		phalcon_array_update_string_string(&options, SL("statsKey"), SL("_PHCX"), 0);
	}
	
	phalcon_call_parent_p2_noret(this_ptr, phalcon_cache_backend_xcache_ce, "__construct", frontend, options);
	
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
	zval *cached_content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SVV(prefixed_key, "_PHCX", prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_OBS_VAR(cached_content);
	phalcon_call_func_p1_ex(cached_content, &cached_content, "xcache_get", prefixed_key);
	if (Z_TYPE_P(cached_content) == IS_NULL) {
		RETURN_MM_NULL();
	}

	if (phalcon_is_numeric(cached_content)) {
		RETURN_CCTOR(cached_content);
	} else {
		phalcon_return_call_method_p1(frontend, "afterretrieve", cached_content);
	}
	
	RETURN_MM();
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
	zval *cached_content,  *keys, *last_key, *frontend;
	zval *prepared_content, *ttl, *success, *is_buffering;
	zval *prefix, *options, *special_key, *z_zero, *tmp;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCX", prefix, key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		PHALCON_OBS_VAR(cached_content);
		phalcon_call_method_p0_ex(cached_content, &cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}
	
	if (!phalcon_is_numeric(cached_content)) {
		PHALCON_OBS_VAR(prepared_content);
		phalcon_call_method_p1_ex(prepared_content, &prepared_content, frontend, "beforestore", cached_content);
	}
	
	/** 
	 * Take the lifetime from the frontend or read it from the set in start()
	 */
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);

		if (Z_TYPE_P(tmp) == IS_NULL) {
			PHALCON_OBS_VAR(ttl);
			phalcon_call_method_p0_ex(ttl, &ttl, frontend, "getlifetime");
		}
		else {
			ttl = tmp;
		}
	} else {
		ttl = lifetime;
	}
	
	PHALCON_OBS_VAR(success);

	if (phalcon_is_numeric(cached_content)) {
		phalcon_call_func_p3_ex(success, &success, "xcache_set", last_key, cached_content, ttl);
	} else {
		phalcon_call_func_p3_ex(success, &success, "xcache_set", last_key, prepared_content, ttl);
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
	
	if (zend_is_true(success)) {
	
		options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
		if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
			return;
		}
	
		/** 
		 * xcache_list() is available only to the administrator (unless XCache was
		 * patched). We have to update the list of the stored keys.
		 */
		PHALCON_OBS_VAR(keys);
		phalcon_call_func_p1_ex(keys, &keys, "xcache_get", special_key);
		if (Z_TYPE_P(keys) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(keys);
			array_init(keys);
		}
	
		z_zero = PHALCON_GLOBAL(z_zero);
		phalcon_array_update_zval(&keys, last_key, &ttl, PH_COPY);	
		phalcon_call_func_p3_noret("xcache_set", special_key, keys, z_zero);
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

	zval *key_name, *prefix, *prefixed_key;
	zval *options, *special_key, *keys;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SVV(prefixed_key, "_PHCX", prefix, key_name);
	
	phalcon_return_call_func_p1("xcache_unset", prefixed_key);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	PHALCON_OBS_VAR(keys);
	phalcon_call_func_p1_ex(keys, &keys, "xcache_get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		zval *z_zero = PHALCON_GLOBAL(z_zero);
		phalcon_array_unset(&keys, prefixed_key, 0);
		phalcon_call_func_p3_noret("xcache_set", special_key, keys, z_zero);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, queryKeys){

	zval *prefix = NULL, *prefixed, *options, *special_key;
	zval *keys, *real_key = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);

	PHALCON_INIT_VAR(prefixed);
	if (!prefix) {
		ZVAL_STRING(prefixed, "_PHCX", 1);
	}
	else {
		PHALCON_CONCAT_SV(prefixed, "_PHCX", prefix);
	}
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	
	array_init(return_value);

	/** 
	 * Get the key from XCache (we cannot use xcache_list() as it is available only to
	 * the administrator)
	 */
	PHALCON_OBS_VAR(keys);
	phalcon_call_func_p1_ex(keys, &keys, "xcache_get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		HashPosition pos;
		zval **value;

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(keys), &pos);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(keys), (void**)&value, &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(keys), &pos)
		) {
			zval key = phalcon_get_current_key_w(Z_ARRVAL_P(keys), &pos);
	
			if (Z_TYPE(key) == IS_STRING && phalcon_memnstr(&key, prefixed)) {
				PHALCON_INIT_NVAR(real_key);
				phalcon_substr(real_key, &key, 5, 0);
				phalcon_array_append(&return_value, real_key, 0);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the cache entry exists and has not expired
 *
 * @param string $keyName
 * @param long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, exists){

	zval *key_name = NULL, *lifetime = NULL, *last_key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCX", prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		phalcon_return_call_func_p1("xcache_isset", last_key);
	}
	else {
		RETVAL_FALSE;
	}

	PHALCON_MM_RESTORE();
}

/**
 * Atomic increment of a given key, by number $value
 *
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, increment){
	
	zval **key_name = NULL, **value = NULL, *last_key = NULL;
	zval *origVal;
	
	phalcon_fetch_params_ex(1, 1, &key_name, &value);

	if (!value || Z_TYPE_PP(value) == IS_NULL) {
		value = &PHALCON_GLOBAL(z_one);
	}
	else {
		PHALCON_ENSURE_IS_LONG(value);
	}

	PHALCON_MM_GROW();
	
	if (Z_TYPE_PP(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCX", prefix, *key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}

	if (phalcon_function_exists_ex(SS("xcache_inc") TSRMLS_CC) == SUCCESS) {
		phalcon_return_call_func_p2("xcache_inc", last_key, *value);
	} else {
		PHALCON_INIT_VAR(origVal);
		phalcon_call_func_p1(origVal, "xcache_get", last_key);
		add_function(return_value, origVal, *value TSRMLS_CC);
		phalcon_call_method_p2_noret(this_ptr, "save", *key_name, return_value);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Atomic decrement of a given key, by number $value
 *
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, decrement){
	
	zval **key_name = NULL, **value = NULL, *last_key = NULL;
	zval *origVal;
	
	phalcon_fetch_params_ex(1, 1, &key_name, &value);

	if (!value || Z_TYPE_PP(value) == IS_NULL) {
		value = &PHALCON_GLOBAL(z_one);
	}
	else {
		PHALCON_ENSURE_IS_LONG(value);
	}

	PHALCON_MM_GROW();
	
	if (Z_TYPE_PP(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCX", prefix, *key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}

	if (phalcon_function_exists_ex(SS("xcache_inc") TSRMLS_CC) == SUCCESS) {
		phalcon_return_call_func_p2("xcache_inc", last_key, *value);
	} else {
		PHALCON_INIT_VAR(origVal);
		phalcon_call_func_p1(origVal, "xcache_get", last_key);
		sub_function(return_value, origVal, *value TSRMLS_CC);
		phalcon_call_method_p2_noret(this_ptr, "save", *key_name, return_value);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Immediately invalidates all existing items.
 * 
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, flush){

	zval *prefixed, *options, *special_key, *z_zero;
	zval *keys, *real_key = NULL;
	HashPosition pos;
	zval **value;

	PHALCON_MM_GROW();

	z_zero = PHALCON_GLOBAL(z_zero);

	PHALCON_INIT_VAR(prefixed);
	ZVAL_STRING(prefixed, "_PHCX", 1);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	PHALCON_OBS_VAR(keys);
	phalcon_call_func_p1_ex(keys, &keys, "xcache_get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(keys), &pos);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(keys), (void**)&value, &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(keys), &pos)
		) {
			zval key = phalcon_get_current_key_w(Z_ARRVAL_P(keys), &pos);

			PHALCON_INIT_NVAR(real_key);
			ZVAL_STRINGL(real_key, Z_STRVAL(key), Z_STRLEN(key), 1);
	
			phalcon_call_func_p1_noret("xcache_unset", real_key);
		}

		zend_hash_clean(Z_ARRVAL_P(keys));
		phalcon_call_func_p3_noret("xcache_set", special_key, keys, z_zero);
	}
	
	RETURN_MM_TRUE;
}
