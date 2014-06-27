
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

#include "cache/backend/redis.h"
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
 * Phalcon\Cache\Backend\Redis
 *
 * Allows to cache output fragments, PHP data or raw data to a redis backend
 *
 * This adapter uses the special redisd key "_PHCR" to store all the keys internally used by the adapter
 *
 *<code>
 *
 * // Cache data for 2 days
 * $frontCache = new Phalcon\Cache\Frontend\Data(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting redisd connection options
 * $cache = new Phalcon\Cache\Backend\Redis($frontCache, array(
 *		'host' => 'localhost',
 *		'port' => 6379,
 *		'auth' => 'foobared',
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
zend_class_entry *phalcon_cache_backend_redis_ce;

PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect);
PHP_METHOD(Phalcon_Cache_Backend_Redis, get);
PHP_METHOD(Phalcon_Cache_Backend_Redis, save);
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete);
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Redis, exists);
PHP_METHOD(Phalcon_Cache_Backend_Redis, increment);
PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush);
PHP_METHOD(Phalcon_Cache_Backend_Redis, getTrackingKey);
PHP_METHOD(Phalcon_Cache_Backend_Redis, setTrackingKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_settrackingkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cache_backend_redis_method_entry[] = {
	PHP_ME(Phalcon_Cache_Backend_Redis, __construct, arginfo_phalcon_cache_backend_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Redis, _connect, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_Backend_Redis, get, arginfo_phalcon_cache_backendinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, save, arginfo_phalcon_cache_backendinterface_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, delete, arginfo_phalcon_cache_backendinterface_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, queryKeys, arginfo_phalcon_cache_backendinterface_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, exists, arginfo_phalcon_cache_backendinterface_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, increment, arginfo_phalcon_cache_backendinterface_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, decrement, arginfo_phalcon_cache_backendinterface_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, getTrackingKey, arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, setTrackingKey, arginfo_phalcon_cache_backend_redis_settrackingkey, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Cache\Backend\Redis initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Redis)
{
	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Redis, cache_backend_redis, phalcon_cache_backend_ce, phalcon_cache_backend_redis_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_redis_ce, SL("_redis"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_redis_ce, SL("_auth"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_redis_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Backend\Redis constructor
 *
 * @param Phalcon\Cache\FrontendInterface $frontend
 * @param array $options
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct){

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
		phalcon_array_update_string_string(&options, SL("host"), SL("127.0.0.1"), 0);
	}
	
	if (!phalcon_array_isset_string(options, SS("port"))) {
		phalcon_array_update_string_long(&options, SL("port"), 6379, 0);
	}
	
	if (!phalcon_array_isset_string(options, SS("persistent"))) {
		phalcon_array_update_string_bool(&options, SL("persistent"), 0, 0);
	}
	
	if (!phalcon_array_isset_string(options, SS("statsKey"))) {
		phalcon_array_update_string_string(&options, SL("statsKey"), SL("_PHCR"), 0);
	}
	
	PHALCON_CALL_PARENT(NULL, phalcon_cache_backend_redis_ce, this_ptr, "__construct", frontend, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Create internal connection to redisd
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect)
{
	zval *options, *redis, *host, *port, *persistent;
	zval *success = NULL, *auth;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	ce0 = zend_fetch_class(SL("Redis"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(redis);
	object_init_ex(redis, ce0);
	if (phalcon_has_constructor(redis TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, redis, "__construct");
	}
	
	if (
		   !phalcon_array_isset_string_fetch(&host, options, SS("host"))
		|| !phalcon_array_isset_string_fetch(&port, options, SS("port"))
		|| !phalcon_array_isset_string_fetch(&persistent, options, SS("persistent"))
	) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	if (zend_is_true(persistent)) {
		PHALCON_CALL_METHOD(&success, redis, "pconnect", host, port);
	} else {
		PHALCON_CALL_METHOD(&success, redis, "connect", host, port);
	}
	
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cannot connect to Redisd server");
		return;
	}
	
	if (phalcon_array_isset_string_fetch(&auth, options, SS("auth"))) {
		PHALCON_CALL_METHOD(&success, redis, "auth", auth);

		if (!zend_is_true(success)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Redisd server is authentication failed");
			return;
		}
	}

	phalcon_update_property_this(this_ptr, SL("_redis"), redis TSRMLS_CC);
	RETURN_CTOR(redis);
}

/**
 * Returns a cached content
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, get){

	zval *key_name, *lifetime = NULL, *redis, *frontend;
	zval *prefix, *prefixed_key, *cached_content = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	redis = phalcon_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		redis = NULL;
		PHALCON_CALL_METHOD(&redis, this_ptr, "_connect");
	}
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SVV(prefixed_key, "_PHCR", prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&cached_content, redis, "get", prefixed_key);
	if (PHALCON_IS_FALSE(cached_content)) {
		RETURN_MM_NULL();
	}

	if (phalcon_is_numeric(cached_content)) {
		RETURN_CCTOR(cached_content);
	}
	
	PHALCON_RETURN_CALL_METHOD(frontend, "afterretrieve", cached_content);
	RETURN_MM();
}

/**
 * Stores cached content into the Redisd backend and stops the frontend
 *
 * @param int|string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *cached_content = NULL, *prepared_content = NULL, *success = NULL;
	zval *ttl = NULL, *is_buffering = NULL;
	zval *prefixed_key, *last_key, *frontend, *redis, *options, *special_key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(prefixed_key);
		ZVAL_STRINGL(prefixed_key, Z_STRVAL_P(last_key)+5, Z_STRLEN_P(last_key)-5, 1);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(prefixed_key);
		PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_SV(last_key, "_PHCR", prefixed_key);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	/** 
	 * Check if a connection is created or make a new one
	 */
	redis = phalcon_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		redis = NULL;
		PHALCON_CALL_METHOD(&redis, this_ptr, "_connect");
	}

	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		PHALCON_CALL_METHOD(&cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}
	
	/** 
	 * Prepare the content in the frontend
	 */
	PHALCON_CALL_METHOD(&prepared_content, frontend, "beforestore", cached_content);

	/** 
	 * Take the lifetime from the frontend or read it from the set in start()
	 */
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		zval *last_lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY TSRMLS_CC);

		if (Z_TYPE_P(last_lifetime) == IS_NULL) {
			PHALCON_CALL_METHOD(&ttl, frontend, "getlifetime");
		}
		else {
			ttl = last_lifetime;
		}
	} else {
		ttl = lifetime;
	}
	
	if (phalcon_is_numeric(cached_content)) {
		PHALCON_CALL_METHOD(&success, redis, "set", last_key, cached_content);
	} else {
		PHALCON_CALL_METHOD(&success, redis, "set", last_key, prepared_content);
	}

	PHALCON_CALL_METHOD(&success, redis, "settimeout", last_key, ttl);

	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Failed to store data in redisd");
		return;
	}
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	if (Z_TYPE_P(special_key) != IS_NULL) {
		PHALCON_CALL_METHOD(NULL, redis, "sadd", special_key, prefixed_key);
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
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete){

	zval *key_name, *redis, *prefix, *prefixed_key, *last_key;
	zval *options, *special_key;
	zval *ret = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	redis = phalcon_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		redis = NULL;
		PHALCON_CALL_METHOD(&redis, this_ptr, "_connect");
	}
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);

	PHALCON_INIT_VAR(last_key);
	PHALCON_CONCAT_SV(last_key, "_PHCR", prefixed_key);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}

	if (Z_TYPE_P(special_key) != IS_NULL) {
		PHALCON_CALL_METHOD(NULL, redis, "srem", special_key, prefixed_key);
	}
	
	/* Delete the key from redisd */
	PHALCON_CALL_METHOD(&ret, redis, "delete", last_key);
	if (zend_is_true(ret)) {
		RETURN_MM_TRUE;
	}

	RETURN_MM_FALSE;
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys){

	zval *prefix = NULL, *redis, *options, *special_key;
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

	redis = phalcon_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		redis = NULL;
		PHALCON_CALL_METHOD(&redis, this_ptr, "_connect");
	}
	
	/* Get the key from redisd */
	PHALCON_CALL_METHOD(&keys, redis, "smembers", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		HashPosition pos;
		zval **value;

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(keys), &pos);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(keys), (void**)&value, &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(keys), &pos)
		) {
	
			if (!prefix || !zend_is_true(prefix) || phalcon_start_with(*value, prefix, NULL)) {
				PHALCON_INIT_NVAR(real_key);
				ZVAL_STRINGL(real_key, Z_STRVAL_PP(value), Z_STRLEN_PP(value), 1);
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
PHP_METHOD(Phalcon_Cache_Backend_Redis, exists){

	zval *key_name = NULL, *lifetime = NULL, *value = NULL;
	zval *last_key, *redis;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCR", prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		redis = phalcon_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(redis) != IS_OBJECT) {
			redis = NULL;
			PHALCON_CALL_METHOD(&redis, this_ptr, "_connect");
		}
	
		PHALCON_CALL_METHOD(&value, redis, "get", last_key);
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
PHP_METHOD(Phalcon_Cache_Backend_Redis, increment){

	zval *key_name = NULL, *value = NULL, *redis = NULL;
	zval *last_key, *prefix;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &value);

	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCR", prefix, key_name);
	}

	if (!value) {
		PHALCON_INIT_VAR(value);
		ZVAL_LONG(value, 1); 
	} else if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1); 
	} else if (Z_TYPE_P(value) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(value);
		convert_to_long_ex(&value);
	}

	redis = phalcon_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		redis = NULL;
		PHALCON_CALL_METHOD(&redis, this_ptr, "_connect");
	}

	PHALCON_RETURN_CALL_METHOD(redis, "incrby", last_key, value);
	PHALCON_MM_RESTORE();
}

/**
 * Atomic decrement of a given key, by number $value
 * 
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement){

	zval *key_name = NULL, *value = NULL, *redis = NULL;
	zval *last_key, *prefix;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &value);

	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCR", prefix, key_name);
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

	redis = phalcon_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		redis = NULL;
		PHALCON_CALL_METHOD(&redis, this_ptr, "_connect");
	}

	PHALCON_RETURN_CALL_METHOD(redis, "decrby", last_key, value);
	PHALCON_MM_RESTORE();
}

/**
 * Immediately invalidates all existing items.
 * 
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush){

	zval *redis, *options, *special_key;
	zval *keys = NULL, *real_key = NULL, *last_key = NULL;
	zval **value;
	HashPosition pos;

	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	
	if (unlikely(!phalcon_array_isset_string_fetch(&special_key, options, SS("statsKey")))) {
		zend_throw_exception_ex(phalcon_cache_exception_ce, 0 TSRMLS_CC, "Unexpected inconsistency in options");
		return;
	}

	if (Z_TYPE_P(special_key) == IS_NULL) {
		RETURN_FALSE;
	}

	PHALCON_MM_GROW();

	redis = phalcon_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		redis = NULL;
		PHALCON_CALL_METHOD(&redis, this_ptr, "_connect");
	}
	
	/* Get the key from redisd */
	PHALCON_CALL_METHOD(&keys, redis, "smembers", special_key);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(keys), &pos);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(keys), (void**)&value, &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(keys), &pos)
		) {
			PHALCON_INIT_NVAR(real_key);
			ZVAL_STRINGL(real_key, Z_STRVAL_PP(value), Z_STRLEN_PP(value), 1);

			PHALCON_INIT_NVAR(last_key);
			PHALCON_CONCAT_SV(last_key, "_PHCR", real_key);

			PHALCON_CALL_METHOD(NULL, redis, "delete", last_key);	
			PHALCON_CALL_METHOD(NULL, redis, "srem", special_key, real_key);
		}
		
		zend_hash_clean(Z_ARRVAL_P(keys));
	}
	
	RETURN_MM_TRUE;
}

PHP_METHOD(Phalcon_Cache_Backend_Redis, getTrackingKey)
{
	zval *stats_key;
	zval *options = phalcon_fetch_nproperty_this(getThis(), SL("_options"), PH_NOISY TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&stats_key, options, SS("statsKey"))) {
		RETURN_NULL();
	}

	RETURN_ZVAL(stats_key, 1, 0);
}

PHP_METHOD(Phalcon_Cache_Backend_Redis, setTrackingKey)
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
