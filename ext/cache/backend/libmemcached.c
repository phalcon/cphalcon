
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
 * Phalcon\Cache\Backend\Libmemcached
 *
 * Allows to cache output fragments, PHP data or raw data to a libmemcached backend
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
 * $cache = new Phalcon\Cache\Backend\Libmemcached($frontCache, array(
 *     'servers' => array(
 *         array('host' => 'localhost',
 *               'port' => 11211,
 *               'weight' => 1),
 *     ),
 *     'client' => array(
 *         Memcached::OPT_HASH => Memcached::HASH_MD5,
 *         Memcached::OPT_PREFIX_KEY => 'prefix.',
 *     )
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
 * Phalcon\Cache\Backend\Libmemcached initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Libmemcached){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Libmemcached, cache_backend_libmemcached, "phalcon\\cache\\backend", phalcon_cache_backend_libmemcached_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_libmemcached_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_libmemcached_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Backend\Libmemcached constructor
 *
 * @param Phalcon\Cache\FrontendInterface $frontend
 * @param array $options
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, __construct){

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

	if (!phalcon_array_isset_string(options, SS("servers"))) {
		zval *server = NULL, *servers = NULL;
		PHALCON_INIT_NVAR(servers);
		PHALCON_INIT_NVAR(server);
		array_init(servers);
		array_init(server);

		phalcon_array_update_string_string(&server, SL("host"), SL("127.0.0.1"), PH_SEPARATE);
		phalcon_array_update_string_string(&server, SL("port"), SL("11211"), PH_SEPARATE);
		phalcon_array_update_string_string(&server, SL("weight"), SL("1"), PH_SEPARATE);

		phalcon_array_update_long(&servers, 0, &server, PH_COPY);

		phalcon_array_update_string(&options, SL("servers"), &servers, PH_COPY);
	}

	if (!phalcon_array_isset_string(options, SS("statsKey"))) {
		phalcon_array_update_string_string(&options, SL("statsKey"), SL("_PHCM"), PH_SEPARATE);
	}

	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Cache\\Backend\\Libmemcached", "__construct", frontend, options);

	PHALCON_MM_RESTORE();
}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, _connect){

	zval *options, *memcache, *servers, *client;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ce0 = zend_fetch_class(SL("Memcached"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(memcache);
	object_init_ex(memcache, ce0);
	if (phalcon_has_constructor(memcache TSRMLS_CC)) {
		phalcon_call_method_noret(memcache, "__construct");
	}

	PHALCON_OBS_VAR(servers);
	phalcon_array_fetch_string(&servers, options, SL("servers"), PH_NOISY);
	if (Z_TYPE_P(servers) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The servers to validate must be an array");
	}

	if (phalcon_array_isset_string(options, SS("client"))) {
		PHALCON_OBS_VAR(client);
		phalcon_array_fetch_string(&client, options, SL("client"), PH_NOISY);
	} else {
		client = NULL;
	}

	phalcon_call_method_p1(return_value, memcache, "addServers", servers);
	if (!zend_is_true(return_value)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server");
		return;
	}

	if (client && Z_TYPE_P(client) == IS_ARRAY) {
		HashTable *ah;
		HashPosition hp;
		zval **hd;
		zval *option = NULL, *value = NULL, *res = NULL;

		phalcon_is_iterable(client, &ah, &hp, 0, 0);
		while (zend_hash_get_current_data_ex(ah, (void**) &hd, &hp) == SUCCESS) {

			PHALCON_GET_HKEY(option, ah, hp);
			PHALCON_GET_HVALUE(value);

			if (Z_TYPE_P(option) == IS_STRING) {
				PHALCON_INIT_NVAR(res);
				if (zend_get_constant(Z_STRVAL_P(option), Z_STRLEN_P(option), res TSRMLS_CC)) {
					phalcon_call_method_p2_noret(memcache, "setOption", res, value);
				}
			} else {
				phalcon_call_method_p2_noret(memcache, "setOption", option, value);
			}

			zend_hash_move_forward_ex(ah, &hp);
		}
	}

	phalcon_update_property_this(this_ptr, SL("_memcache"), memcache TSRMLS_CC);

	RETURN_MM();
}

/**
 * Returns a cached content
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, get){

	zval *key_name, *lifetime = NULL, *memcache = NULL, *frontend;
	zval *prefix, *prefixed_key, *cached_content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);

	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}

	PHALCON_OBS_VAR(memcache);
	phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");
		PHALCON_OBS_NVAR(memcache);
		phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}

	PHALCON_OBS_VAR(frontend);
	phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);

	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);

	PHALCON_INIT_VAR(cached_content);
	phalcon_call_method_p1(cached_content, memcache, "get", prefixed_key);
	if (PHALCON_IS_FALSE(cached_content)) {
		RETURN_MM_NULL();
	}

	phalcon_call_method_p1(return_value, frontend, "afterretrieve", cached_content);
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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key = NULL, *prefix, *frontend, *memcache = NULL, *cached_content = NULL;
	zval *prepared_content, *ttl = NULL, *success;
	zval *options, *special_key, *keys = NULL, *is_buffering;

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

	/** 
	 * Check if a connection is created or make a new one
	 */
	PHALCON_OBS_VAR(memcache);
	phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");

		PHALCON_OBS_NVAR(memcache);
		phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}

	if (Z_TYPE_P(content) == IS_NULL) {
		PHALCON_INIT_VAR(cached_content);
		phalcon_call_method(cached_content, frontend, "getcontent");
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}

	/** 
	 * Prepare the content in the frontend
	 */
	PHALCON_INIT_VAR(prepared_content);
	phalcon_call_method_p1(prepared_content, frontend, "beforestore", cached_content);
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		PHALCON_INIT_VAR(ttl);
		phalcon_call_method(ttl, frontend, "getlifetime");
	} else {
		PHALCON_CPY_WRT(ttl, lifetime);
	}

	PHALCON_INIT_VAR(success);
	phalcon_call_method_p3(success, memcache, "set", last_key, prepared_content, ttl);
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Failed storing data in memcached");
		return;
	}

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);

	PHALCON_OBS_VAR(special_key);
	phalcon_array_fetch_string(&special_key, options, SL("statsKey"), PH_NOISY);

	/** 
	 * Update the stats key
	 */
	PHALCON_INIT_VAR(keys);
	phalcon_call_method_p1(keys, memcache, "get", special_key);
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		PHALCON_INIT_NVAR(keys);
		array_init(keys);
	}

	if (!phalcon_array_isset(keys, last_key)) {
		phalcon_array_update_zval(&keys, last_key, &ttl, PH_COPY | PH_SEPARATE);
		phalcon_call_method_p2_noret(memcache, "set", special_key, keys);
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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, delete){

	zval *key_name, *memcache = NULL, *prefix, *prefixed_key;
	zval *options, *special_key, *keys;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);

	PHALCON_OBS_VAR(memcache);
	phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");

		PHALCON_OBS_NVAR(memcache);
		phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}

	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);

	PHALCON_OBS_VAR(special_key);
	phalcon_array_fetch_string(&special_key, options, SL("statsKey"), PH_NOISY);

	PHALCON_INIT_VAR(keys);
	phalcon_call_method_p1(keys, memcache, "get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		phalcon_array_unset(&keys, prefixed_key, PH_SEPARATE);
		phalcon_call_method_p2_noret(memcache, "set", special_key, keys);
	}

	/** 
	 * Delete the key from memcached
	 */
	phalcon_call_method_p1(return_value, memcache, "delete", prefixed_key);
	RETURN_MM();
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, queryKeys){

	zval *prefix = NULL, *memcache = NULL, *options, *special_key;
	zval *keys, *prefixed_keys, *ttl = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
	}

	PHALCON_OBS_VAR(memcache);
	phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		phalcon_call_method_noret(this_ptr, "_connect");

		PHALCON_OBS_NVAR(memcache);
		phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);

	PHALCON_OBS_VAR(special_key);
	phalcon_array_fetch_string(&special_key, options, SL("statsKey"), PH_NOISY);

	/** 
	 * Get the key from memcached
	 */
	PHALCON_INIT_VAR(keys);
	phalcon_call_method_p1(keys, memcache, "get", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) {

		PHALCON_INIT_VAR(prefixed_keys);
		array_init(prefixed_keys);

		phalcon_is_iterable(keys, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(ttl);

			if (zend_is_true(prefix)) {
				if (!phalcon_start_with(key, prefix, NULL)) {
					zend_hash_move_forward_ex(ah0, &hp0);
					continue;
				}
			}
			phalcon_array_append(&prefixed_keys, key, PH_SEPARATE);

			zend_hash_move_forward_ex(ah0, &hp0);
		}

		RETURN_CTOR(prefixed_keys);
	}

	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string $keyName
 * @param  long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, exists){

	zval *key_name = NULL, *lifetime = NULL, *last_key = NULL, *prefix, *memcache = NULL;
	zval *cache_exists;

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

		PHALCON_OBS_VAR(memcache);
		phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		if (Z_TYPE_P(memcache) != IS_OBJECT) {
			phalcon_call_method_noret(this_ptr, "_connect");

			PHALCON_OBS_NVAR(memcache);
			phalcon_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		}

		PHALCON_INIT_VAR(cache_exists);
		phalcon_call_method_p1(cache_exists, memcache, "get", last_key);
		if (PHALCON_IS_NOT_FALSE(cache_exists)) {
			RETURN_MM_TRUE;
		}
	}

	RETURN_MM_FALSE;
}
