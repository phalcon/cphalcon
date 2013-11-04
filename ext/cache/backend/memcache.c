
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"

/**
 * Phalcon\Cache\Backend\Memcache
 *
 * Allows to cache output fragments, PHP data or raw data to a memcache backend
 *
 * This adapter uses the special memcached key "_PHCM" to store all the keys internally used by the adapter
 *
 *<code>
 *
 * // Cache data for 2 days
 * $frontCache = new Phalcon\Cache\Frontend\Data(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting memcached connection options
 * $cache = new Phalcon\Cache\Backend\Memcache($frontCache, array(
 *		'host' => 'localhost',
 *		'port' => 11211,
 *  	'persistent' => false
 * ));
 *
 * //Cache arbitrary data
 * $cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 * //Get data
 * $data = $cache->get('my-data');
 *
 *</code>
 */


/**
 * Phalcon\Cache\Backend\Memcache initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Memcache){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memcache, cache_backend_memcache, phalcon_cache_backend_ce, phalcon_cache_backend_memcache_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_memcache_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Backend\Memcache constructor
 *
 * @param Phalcon\Cache\FrontendInterface $frontend
 * @param array $options
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct){

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
		array_init_size(options, 4);
	}

	if (!phalcon_array_isset_string(options, SS("host"))) {
		phalcon_array_update_string_string(&options, SL("host"), SL("127.0.0.1"), PH_SEPARATE);
	}
	
	if (!phalcon_array_isset_string(options, SS("port"))) {
		phalcon_array_update_string_long(&options, SL("port"), 11211, PH_SEPARATE);
	}
	
	if (!phalcon_array_isset_string(options, SS("persistent"))) {
		phalcon_array_update_string_bool(&options, SL("persistent"), 0, PH_SEPARATE);
	}
	
	if (!phalcon_array_isset_string(options, SS("statsKey"))) {
		phalcon_array_update_string_string(&options, SL("statsKey"), SL("_PHCM"), PH_SEPARATE);
	}
	
	phalcon_call_parent_p2_noret(this_ptr, phalcon_cache_backend_memcache_ce, "__construct", frontend, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect){

	zval *options, *memcache, *host, *port, *persistent;
	zval *success;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	ce0 = zend_fetch_class(SL("Memcache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(memcache);
	object_init_ex(memcache, ce0);
	if (phalcon_has_constructor(memcache TSRMLS_CC)) {
		phalcon_call_method_noret(memcache, "__construct");
	}
	
	if (
		   !phalcon_array_isset_string_fetch(&host, options, SS("host"))
		|| !phalcon_array_isset_string_fetch(&port, options, SS("port"))
		|| !phalcon_array_isset_string_fetch(&persistent, options, SS("persistent"))
	) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	PHALCON_OBS_VAR(success);
	if (zend_is_true(persistent)) {
		phalcon_call_method_p2_ex(success, &success, memcache, "pconnect", host, port);
	} else {
		phalcon_call_method_p2_ex(success, &success, memcache, "connect", host, port);
	}
	
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_memcache"), memcache TSRMLS_CC);
	PHALCON_MM_RESTORE();
}

/**
 * Returns a cached content
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, get){

	zval *key_name, *lifetime = NULL, *memcache, *frontend;
	zval *prefix, *prefixed_key, *cached_content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");
	
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_OBS_VAR(cached_content);
	phalcon_call_method_p1_ex(cached_content, &cached_content, memcache, "get", prefixed_key);
	if (PHALCON_IS_FALSE(cached_content)) {
		RETURN_MM_NULL();
	}

	if (phalcon_is_numeric(cached_content)) {
		RETURN_CCTOR(cached_content);
	}
	
	phalcon_return_call_method_p1(frontend, "afterretrieve", cached_content);
	RETURN_MM();
}

/**
 * Stores cached content into the Memcached backend and stops the frontend
 *
 * @param int|string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *cached_content, *prepared_content, *ttl = NULL, *flags, *success;
	zval *keys, *is_buffering;
	zval *last_key, *frontend, *memcache, *options, *special_key;

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
	
	/** 
	 * Check if a connection is created or make a new one
	 */
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	}

	if (!content || Z_TYPE_P(content) == IS_NULL) {
		PHALCON_OBS_VAR(cached_content);
		phalcon_call_method_p0_ex(cached_content, &cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}
	
	/** 
	 * Prepare the content in the frontend
	 */
	PHALCON_OBS_VAR(prepared_content);
	phalcon_call_method_p1_ex(prepared_content, &prepared_content, frontend, "beforestore", cached_content);

	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		zval *tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);

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
	
	PHALCON_INIT_VAR(flags);
	ZVAL_LONG(flags, 0);
	
	/** 
	 * We store without flags
	 */
	PHALCON_OBS_VAR(success);
	if(phalcon_is_numeric(cached_content)) {
		phalcon_call_method_p4_ex(success, &success, memcache, "set", last_key, cached_content, flags, ttl);
	} else {
		phalcon_call_method_p4_ex(success, &success, memcache, "set", last_key, prepared_content, flags, ttl);
	}
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Failed to store data in memcached");
		return;
	}
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);

	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	/** 
	 * Update the stats key
	 */
	PHALCON_OBS_VAR(keys);
	phalcon_call_method_p1_ex(keys, &keys, memcache, "get", special_key);
	if (Z_TYPE_P(keys) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(keys);
		array_init(keys);
	}
	
	if (!phalcon_array_isset(keys, last_key)) {
		phalcon_array_update_zval(&keys, last_key, &ttl, PH_COPY);
		phalcon_call_method_p2_noret(memcache, "set", special_key, keys);
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete){

	zval *key_name, *memcache, *prefix, *prefixed_key;
	zval *options, *special_key, *keys;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	
	PHALCON_OBS_VAR(keys);
	phalcon_call_method_p1_ex(keys, &keys, memcache, "get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		phalcon_array_unset(&keys, prefixed_key, 0);
		phalcon_call_method_p2_noret(memcache, "set", special_key, keys);
	}
	
	/** 
	 * Delete the key from memcached
	 */
	phalcon_return_call_method_p1(memcache, "delete", prefixed_key);
	RETURN_MM();
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys){

	zval *prefix = NULL, *memcache, *options, *special_key;
	zval *keys, *real_key = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	array_init(return_value);
	
	/** 
	 * Get the key from memcached
	 */
	PHALCON_OBS_VAR(keys);
	phalcon_call_method_p1_ex(keys, &keys, memcache, "get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		HashPosition pos;
		zval **value;

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(keys), &pos);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(keys), (void**)&value, &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(keys), &pos)
		) {
			zval key = phalcon_get_current_key_w(Z_ARRVAL_P(keys), &pos);
	
			if (!prefix || !zend_is_true(prefix) || phalcon_start_with(&key, prefix, NULL)) {
				PHALCON_INIT_NVAR(real_key);
				ZVAL_STRINGL(real_key, Z_STRVAL(key), Z_STRLEN(key), 1);
				phalcon_array_append(&return_value, real_key, 0);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string $keyName
 * @param  long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, exists){

	zval *key_name = NULL, *lifetime = NULL, *value;
	zval *last_key, *memcache;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
		if (Z_TYPE_P(memcache) != IS_OBJECT) {
			phalcon_call_method_noret(this_ptr, "_connect");
			memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
		}
	
		PHALCON_OBS_VAR(value);
		phalcon_call_method_p1_ex(value, &value, memcache, "get", last_key);
		RETVAL_BOOL(PHALCON_IS_NOT_FALSE(value));
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, increment){
    
	zval *key_name = NULL, *value = NULL, *memcache = NULL;
	zval *newVal;
    
	PHALCON_MM_GROW();
    
	phalcon_fetch_params(1, 0, 2, &key_name, &value);
    
	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
	}   
    
	if (!value) {
		PHALCON_INIT_VAR(value);
	}   
    
	if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1); 
	}   
    
	if (Z_TYPE_P(value) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(value);
		convert_to_long_ex(&value);
	}   
    
	PHALCON_OBS_VAR(memcache);
	phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
    
	PHALCON_INIT_VAR(newVal);
	phalcon_call_method_p2(newVal, memcache, "increment", key_name, value);
    
	RETURN_CTOR(newVal);
}

/**
 * Atomic decrement of a given key, by number $value
 * 
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, decrement){

	zval *key_name = NULL, *value = NULL, *memcache = NULL;
	zval *newVal;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &value);

	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
	}

	if (!value) {
		PHALCON_INIT_VAR(value);
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1);
	}

	if (Z_TYPE_P(value) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(value);
		convert_to_long_ex(&value);
	}

	PHALCON_OBS_VAR(memcache);
	phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);

	PHALCON_INIT_VAR(newVal);
	phalcon_call_method_p2(newVal, memcache, "decrement", key_name, value);

	RETURN_CTOR(newVal);
}

/**
 * Immediately invalidates all existing items.
 * 
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, flush){

	zval *memcache, *options, *special_key;
	zval *keys;
	HashPosition pos;
	zval **value;

	PHALCON_MM_GROW();
	
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	
	/** 
	 * Get the key from memcached
	 */
	PHALCON_OBS_VAR(keys);
	phalcon_call_method_p1_ex(keys, &keys, memcache, "get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(keys), &pos);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(keys), (void**)&value, &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(keys), &pos)
		) {
			zval key = phalcon_get_current_key_w(Z_ARRVAL_P(keys), &pos);
	
			phalcon_call_method_p1_noret(memcache, "delete", &key);
		}
		
		zend_hash_clean(Z_ARRVAL_P(keys));
		phalcon_call_method_p2_noret(memcache, "set", special_key, keys);
	}
	
	RETURN_MM_TRUE;
}
