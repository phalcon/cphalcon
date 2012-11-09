
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
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
 * $cache = new Phalcon\Cache\Backend\File($frontCache, array(
 *		'host' => 'localhost',
 *		'port' => 11211,
 *  	'persistent' => false
 * ));
 *
 * //Cache arbitrary data
 * $cache->store('my-data', array(1, 2, 3, 4, 5));
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memcache, cache_backend_memcache, "phalcon\\cache\\backend", phalcon_cache_backend_memcache_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Backend\Adapter\Memcache constructor
 *
 * @param mixed $frontendObject
 * @param array $backendOptions
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct){

	zval *frontend_object, *backend_options = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &frontend_object, &backend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!backend_options) {
		PHALCON_INIT_NVAR(backend_options);
		array_init(backend_options);
	} else {
		PHALCON_SEPARATE_PARAM(backend_options);
	}
	
	eval_int = phalcon_array_isset_string(backend_options, SS("host"));
	if (!eval_int) {
		phalcon_array_update_string_string(&backend_options, SL("host"), SL("127.0.0.1"), PH_SEPARATE TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(backend_options, SS("port"));
	if (!eval_int) {
		phalcon_array_update_string_string(&backend_options, SL("port"), SL("11211"), PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(backend_options, SS("persistent"));
	if (!eval_int) {
		phalcon_array_update_string_bool(&backend_options, SL("persistent"), 0, PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(backend_options, SS("statsKey"));
	if (!eval_int) {
		phalcon_array_update_string_string(&backend_options, SL("statsKey"), SL("_PHCM"), PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Cache\\Backend\\Memcache", "__construct", frontend_object, backend_options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect){

	zval *backend_options, *memcache, *host, *port;
	zval *persistent, *success = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(backend_options);
	phalcon_read_property(&backend_options, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	ce0 = zend_fetch_class(SL("Memcache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(memcache);
	object_init_ex(memcache, ce0);
	PHALCON_CALL_METHOD_NORETURN(memcache, "__construct", PH_CHECK);
	
	PHALCON_INIT_VAR(host);
	phalcon_array_fetch_string(&host, backend_options, SL("host"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(port);
	phalcon_array_fetch_string(&port, backend_options, SL("port"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(persistent);
	phalcon_array_fetch_string(&persistent, backend_options, SL("persistent"), PH_NOISY_CC);
	if (zend_is_true(persistent)) {
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD_PARAMS_2(success, memcache, "connect", host, port, PH_NO_CHECK);
	} else {
		PHALCON_INIT_NVAR(success);
		PHALCON_CALL_METHOD_PARAMS_2(success, memcache, "pconnect", host, port, PH_NO_CHECK);
	}
	
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server");
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_memcache"), memcache TSRMLS_CC);
	
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

	zval *key_name, *lifetime = NULL, *memcache = NULL, *backend;
	zval *front_end, *prefix, *prefixed_key, *cached_content;
	zval *content;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!lifetime) {
		PHALCON_INIT_NVAR(lifetime);
	}
	
	PHALCON_INIT_VAR(memcache);
	phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(memcache);
		phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(backend);
	phalcon_read_property(&backend, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(front_end);
	phalcon_read_property(&front_end, this_ptr, SL("_frontendObject"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefix);
	phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_zval(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_INIT_VAR(cached_content);
	PHALCON_CALL_METHOD_PARAMS_1(cached_content, memcache, "get", prefixed_key, PH_NO_CHECK);
	if (PHALCON_IS_FALSE(cached_content)) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_INIT_VAR(content);
	PHALCON_CALL_METHOD_PARAMS_1(content, front_end, "afterretrieve", cached_content, PH_NO_CHECK);
	
	RETURN_CCTOR(content);
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
	zval *last_key = NULL, *prefix, *front_end, *backend_options;
	zval *memcache = NULL, *cached_content = NULL, *prepared_content;
	zval *ttl = NULL, *flags, *success, *special_key, *keys = NULL, *is_buffering;
	int eval_int;

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
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_INIT_VAR(front_end);
	phalcon_read_property(&front_end, this_ptr, SL("_frontendObject"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(backend_options);
	phalcon_read_property(&backend_options, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(memcache);
	phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(memcache);
		phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	
	if (Z_TYPE_P(content) == IS_NULL) {
		PHALCON_INIT_VAR(cached_content);
		PHALCON_CALL_METHOD(cached_content, front_end, "getcontent", PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_INIT_VAR(prepared_content);
	PHALCON_CALL_METHOD_PARAMS_1(prepared_content, front_end, "beforestore", cached_content, PH_NO_CHECK);
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		PHALCON_INIT_VAR(ttl);
		PHALCON_CALL_METHOD(ttl, front_end, "getlifetime", PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(ttl, lifetime);
	}
	
	PHALCON_INIT_VAR(flags);
	ZVAL_LONG(flags, 0);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_4(success, memcache, "set", last_key, prepared_content, flags, ttl, PH_NO_CHECK);
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Failed storing data in memcached");
		return;
	}
	
	PHALCON_INIT_VAR(special_key);
	phalcon_array_fetch_string(&special_key, backend_options, SL("statsKey"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(keys);
	PHALCON_CALL_METHOD_PARAMS_1(keys, memcache, "get", special_key, PH_NO_CHECK);
	if (Z_TYPE_P(keys) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(keys);
		array_init(keys);
	}
	
	eval_int = phalcon_array_isset(keys, last_key);
	if (!eval_int) {
		phalcon_array_update_zval(&keys, last_key, &ttl, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(memcache, "set", special_key, keys, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(is_buffering);
	PHALCON_CALL_METHOD(is_buffering, front_end, "isbuffering", PH_NO_CHECK);
	if (PHALCON_IS_TRUE(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "stop", PH_NO_CHECK);
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete){

	zval *key_name, *memcache = NULL, *prefix, *prefixed_key;
	zval *backend_options, *special_key, *keys, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(memcache);
	phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(memcache);
		phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(prefix);
	phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	
	PHALCON_INIT_VAR(backend_options);
	phalcon_read_property(&backend_options, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(special_key);
	phalcon_array_fetch_string(&special_key, backend_options, SL("statsKey"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(keys);
	PHALCON_CALL_METHOD_PARAMS_1(keys, memcache, "get", special_key, PH_NO_CHECK);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		PHALCON_SEPARATE(keys);
		phalcon_array_unset(keys, prefixed_key);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(memcache, "set", special_key, keys, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, memcache, "delete", prefixed_key, PH_NO_CHECK);
	
	RETURN_CCTOR(success);
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys){

	zval *prefix = NULL, *memcache = NULL, *backend_options, *special_key;
	zval *keys, *prefixed_keys, *ttl = NULL, *key = NULL, *empty_arr;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &prefix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!prefix) {
		PHALCON_INIT_NVAR(prefix);
	}
	
	PHALCON_INIT_VAR(memcache);
	phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(memcache);
		phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(backend_options);
	phalcon_read_property(&backend_options, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(special_key);
	phalcon_array_fetch_string(&special_key, backend_options, SL("statsKey"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(keys);
	PHALCON_CALL_METHOD_PARAMS_1(keys, memcache, "get", special_key, PH_NO_CHECK);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		PHALCON_INIT_VAR(prefixed_keys);
		array_init(prefixed_keys);
	
		if (!phalcon_valid_foreach(keys TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(keys);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(ttl);
	
			if (zend_is_true(prefix)) {
				if (!phalcon_start_with(key, prefix)) {
					zend_hash_move_forward_ex(ah0, &hp0);
					goto ph_cycle_start_0;
				}
			}
			phalcon_array_append(&prefixed_keys, key, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
	
	
		RETURN_CTOR(prefixed_keys);
	}
	
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	
	RETURN_CTOR(empty_arr);
}

/**
 * Checks if cache exists.
 *
 * @param string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, exists){

	zval *key_name = NULL, *last_key = NULL, *prefix, *memcache = NULL, *cache_exists;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_NVAR(key_name);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_INIT_VAR(last_key);
		phalcon_read_property(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(prefix);
		phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	if (zend_is_true(last_key)) {
		PHALCON_INIT_VAR(memcache);
		phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		if (Z_TYPE_P(memcache) != IS_OBJECT) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PH_NO_CHECK);
	
			PHALCON_INIT_NVAR(memcache);
			phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		}
	
		PHALCON_INIT_VAR(cache_exists);
		PHALCON_CALL_METHOD_PARAMS_1(cache_exists, memcache, "get", last_key, PH_NO_CHECK);
		if (PHALCON_IS_NOT_FALSE(cache_exists)) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Destructs the backend closing the memcached connection
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, __destruct){

	zval *memcache, *backend_options, *persistent;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(memcache);
	phalcon_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) == IS_OBJECT) {
		PHALCON_INIT_VAR(backend_options);
		phalcon_read_property(&backend_options, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(persistent);
		phalcon_array_fetch_string(&persistent, backend_options, SL("persistent"), PH_NOISY_CC);
		if (!zend_is_true(persistent)) {
			PHALCON_CALL_METHOD_NORETURN(memcache, "close", PH_NO_CHECK);
		}
	}
	
	PHALCON_MM_RESTORE();
}

