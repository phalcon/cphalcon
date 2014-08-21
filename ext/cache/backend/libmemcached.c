
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

#include "cache/backend/libmemcached.h"
#include "cache/backend.h"
#include "cache/backendinterface.h"
#include "cache/exception.h"

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

#include "internal/arginfo.h"

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
zend_class_entry *phalcon_cache_backend_libmemcached_ce;

PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, _connect);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, get);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, save);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, delete);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, exists);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, increment);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, flush);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, getTrackingKey);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, setTrackingKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_settrackingkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cache_backend_libmemcached_method_entry[] = {
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, __construct, arginfo_phalcon_cache_backend_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, _connect, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, get, arginfo_phalcon_cache_backendinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, save, arginfo_phalcon_cache_backendinterface_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, delete, arginfo_phalcon_cache_backendinterface_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, queryKeys, arginfo_phalcon_cache_backendinterface_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, exists, arginfo_phalcon_cache_backendinterface_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, increment, arginfo_phalcon_cache_backendinterface_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, decrement, arginfo_phalcon_cache_backendinterface_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, getTrackingKey, arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, setTrackingKey, arginfo_phalcon_cache_backend_libmemcached_settrackingkey, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Cache\Backend\Libmemcached initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Libmemcached){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Libmemcached, cache_backend_libmemcached, phalcon_cache_backend_ce, phalcon_cache_backend_libmemcached_method_entry, 0);

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

	zval *frontend, *options = NULL, *server, *servers;

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
		PHALCON_INIT_VAR(servers);
		array_init_size(servers, 1);

		PHALCON_INIT_VAR(server);
		array_init_size(server, 3);

		phalcon_array_update_string_string(&server, SL("host"), SL("127.0.0.1"), 0);
		phalcon_array_update_string_long(&server, SL("port"), 11211, 0);
		phalcon_array_update_string_long(&server, SL("weight"), 1, 0);

		phalcon_array_append(&servers, server, 0);

		phalcon_array_update_string(&options, SL("servers"), servers, PH_COPY);
	}

	if (!phalcon_array_isset_string(options, SS("statsKey"))) {
		phalcon_array_update_string_string(&options, SL("statsKey"), SL("_PHCM"), 0);
	}

	PHALCON_CALL_PARENT(NULL, phalcon_cache_backend_libmemcached_ce, this_ptr, "__construct", frontend, options);

	PHALCON_MM_RESTORE();
}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, _connect){

	zval *options, *memcache, *servers, *client = NULL, *res = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	ce0 = zend_fetch_class(SL("Memcached"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(memcache);
	object_init_ex(memcache, ce0);
	if (phalcon_has_constructor(memcache TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, memcache, "__construct");
	}

	if (!phalcon_array_isset_string_fetch(&servers, options, SS("servers")) || Z_TYPE_P(servers) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Servers must be an array");
		return;
	}

	phalcon_array_isset_string_fetch(&client, options, SS("client"));

	PHALCON_RETURN_CALL_METHOD(memcache, "addservers", servers);
	if (return_value_ptr) {
		return_value = *return_value_ptr;
	}

	if (!zend_is_true(return_value)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server");
		return;
	}

	if (client && Z_TYPE_P(client) == IS_ARRAY) {
		HashPosition hp;
		zval **hd;

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(client), &hp);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(client), (void**)&hd, &hp) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(client), &hp)
		) {
			zval option = phalcon_get_current_key_w(Z_ARRVAL_P(client), &hp);

			if (Z_TYPE(option) == IS_STRING) {
				PHALCON_INIT_NVAR(res);
				if (zend_get_constant(Z_STRVAL(option), Z_STRLEN(option), res TSRMLS_CC)) {
					PHALCON_CALL_METHOD(NULL, memcache, "setoption", res, *hd);
				}
			} else {
				PHALCON_CALL_METHOD(NULL, memcache, "setoption", &option, *hd);
			}
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

	zval *key_name, *lifetime = NULL, *memcache, *frontend, *prefix;
	zval *prefixed_key, *cached_content = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);

	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	}

	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);

	PHALCON_CALL_METHOD(&cached_content, memcache, "get", prefixed_key);
	if (PHALCON_IS_FALSE(cached_content)) {
		RETURN_MM_NULL();
	}

	if (phalcon_is_numeric(cached_content)) {
		RETURN_CCTOR(cached_content);
	} else {
		PHALCON_RETURN_CALL_METHOD(frontend, "afterretrieve", cached_content);
	}

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
	zval *last_key, *frontend, *memcache, *cached_content = NULL;
	zval *prepared_content = NULL, *ttl = NULL, *success = NULL;
	zval *options, *special_key, *keys = NULL, *is_buffering = NULL;

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

	/** 
	 * Check if a connection is created or make a new one
	 */
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	}

	if (!content || Z_TYPE_P(content) == IS_NULL) {
		PHALCON_CALL_METHOD(&cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}

	/** 
	 * Prepare the content in the frontend
	 */
	if (!phalcon_is_numeric(cached_content)) {
		PHALCON_CALL_METHOD(&prepared_content, frontend, "beforestore", cached_content);
	}

	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		zval *tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY TSRMLS_CC);

		if (Z_TYPE_P(tmp) == IS_NULL) {
			PHALCON_CALL_METHOD(&ttl, frontend, "getlifetime");
		}
		else {
			ttl = tmp;
		}
	} else {
		ttl = lifetime;
	}

	if (!prepared_content) {
		PHALCON_CALL_METHOD(&success, memcache, "set", last_key, cached_content, ttl);
	} else {
		PHALCON_CALL_METHOD(&success, memcache, "set", last_key, prepared_content, ttl);
	}

	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Failed storing data in memcached");
		return;
	}

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	if (Z_TYPE_P(special_key) != IS_NULL) {
		/* Update the stats key */
		PHALCON_CALL_METHOD(&keys, memcache, "get", special_key);
		if (Z_TYPE_P(keys) != IS_ARRAY) {
			PHALCON_INIT_NVAR(keys);
			array_init(keys);
		}

		if (!phalcon_array_isset(keys, last_key)) {
			phalcon_array_update_zval(&keys, last_key, ttl, PH_COPY);
			PHALCON_CALL_METHOD(NULL, memcache, "set", special_key, keys);
		}
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
 * Increment of a given key, by number $value
 * 
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, increment){
	zval *key_name, *value = NULL, *memcache, *prefix;
	zval *prefixed_key, *cached_content = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &value);

	if (!value) {
		PHALCON_INIT_VAR(value);
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1);
	}

	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	}

	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);

	PHALCON_CALL_METHOD(&cached_content, memcache, "increment", prefixed_key, value);
	if (PHALCON_IS_FALSE(cached_content)) {
		RETURN_MM_NULL();
	}

	RETURN_CCTOR(cached_content);
}

/**
 * Decrement of a given key, by number $value
 * 
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, decrement){
	zval *key_name, *value = NULL, *memcache, *prefix;
	zval *prefixed_key, *cached_content = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &value);

	if (!value) {
		PHALCON_INIT_VAR(value);
	}

	if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1);
	}

	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	}

	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);

	PHALCON_CALL_METHOD(&cached_content, memcache, "decrement", prefixed_key, value);
	if (PHALCON_IS_FALSE(cached_content)) {
		RETURN_MM_NULL();
	}

	RETURN_CCTOR(cached_content);
}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, delete){

	zval *key_name, *memcache, *prefix, *prefixed_key;
	zval *options, *special_key, *keys = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);

	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	}

	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	if (Z_TYPE_P(special_key) != IS_NULL) {
		PHALCON_CALL_METHOD(&keys, memcache, "get", special_key);
		if (Z_TYPE_P(keys) == IS_ARRAY) {
			phalcon_array_unset(&keys, prefixed_key, 0);
			PHALCON_CALL_METHOD(NULL, memcache, "set", special_key, keys);
		}
	}

	/* Delete the key from memcached */
	PHALCON_RETURN_CALL_METHOD(memcache, "delete", prefixed_key);
	RETURN_MM();
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, queryKeys){

	zval *prefix = NULL, *memcache, *options, *special_key;
	zval *keys = NULL, *real_key = NULL;

	phalcon_fetch_params(0, 0, 1, &prefix);

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		zend_throw_exception_ex(phalcon_cache_exception_ce, 0 TSRMLS_CC, "Unexpected inconsistency in options");
		return;
	}

	array_init(return_value);
	if (Z_TYPE_P(special_key) == IS_NULL) {
		return;
	}

	PHALCON_MM_GROW();

	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	}

	/* Get the key from memcached */
	PHALCON_CALL_METHOD(&keys, memcache, "get", special_key);
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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, exists){

	zval *key_name = NULL, *lifetime = NULL, *value = NULL;
	zval *last_key, *memcache;

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
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(memcache) != IS_OBJECT) {
			PHALCON_CALL_METHOD(NULL, this_ptr, "_connect");
			memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
		}

		PHALCON_CALL_METHOD(&value, memcache, "get", last_key);
		RETVAL_BOOL(PHALCON_IS_NOT_FALSE(value));
	}
	else {
		RETVAL_FALSE;
	}

	PHALCON_MM_RESTORE();
}

/**
 * Immediately invalidates all existing items.
 * 
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, flush){

	zval *memcache, *options, *special_key;
	zval *keys = NULL;
	HashPosition pos;
	zval **value;

	PHALCON_MM_GROW();

	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "_connect");
		memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);
	}

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	/* Get the key from memcached */
	if (Z_TYPE_P(special_key) != IS_NULL) {
		PHALCON_CALL_METHOD(&keys, memcache, "get", special_key);
		if (Z_TYPE_P(keys) == IS_ARRAY) {

			for (
				zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(keys), &pos);
				zend_hash_get_current_data_ex(Z_ARRVAL_P(keys), (void**)&value, &pos) == SUCCESS;
				zend_hash_move_forward_ex(Z_ARRVAL_P(keys), &pos)
			) {
				zval key = phalcon_get_current_key_w(Z_ARRVAL_P(keys), &pos);
				
				PHALCON_CALL_METHOD(NULL, memcache, "delete", &key);
			}
			
			zend_hash_clean(Z_ARRVAL_P(keys));
			PHALCON_CALL_METHOD(NULL, memcache, "set", special_key, keys);
		}		
	} else {
		PHALCON_CALL_METHOD(&keys, memcache, "flush");
	}

	RETURN_MM_TRUE;
}

PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, getTrackingKey)
{
	zval *stats_key;
	zval *options = phalcon_fetch_nproperty_this(getThis(), SL("_options"), PH_NOISY TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&stats_key, options, SS("statsKey"))) {
		RETURN_NULL();
	}

	RETURN_ZVAL(stats_key, 1, 0);
}

PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, setTrackingKey)
{
	zval **key, *options;
	int separated;

	phalcon_fetch_params_ex(1, 0, &key);

	options   = phalcon_fetch_nproperty_this(getThis(), SL("_options"), PH_NOISY TSRMLS_CC);
	separated = phalcon_maybe_separate_zval(&options);
	phalcon_array_update_string(&options, SL("statsKey"), *key, PH_COPY);

	if (separated) {
		Z_DELREF_P(options);
		phalcon_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);
	}

	RETURN_ZVAL(getThis(), 1, 0);
}
