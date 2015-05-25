
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"


/**
 * Phalcon\Cache\Backend\Redis
 *
 * Allows to cache output fragments, PHP data or raw data to a redis backend
 *
 * This adapter uses the special redis key "_PHCR" to store all the keys internally used by the adapter
 *
 *<code>
 *
 * // Cache data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting redis connection options
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
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Redis, phalcon, cache_backend_redis, phalcon_cache_backend_ce, phalcon_cache_backend_redis_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_redis_ce, SL("_redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_redis_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Redis constructor
 *
 * @param	Phalcon\Cache\FrontendInterface frontend
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_bool _1;
	zval *frontend, *options = NULL, *_0 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	if (!(zephir_array_isset_string(options, SS("host")))) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "127.0.0.1", 1);
		zephir_array_update_string(&options, SL("host"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("port")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 6379);
		zephir_array_update_string(&options, SL("port"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("index")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 0);
		zephir_array_update_string(&options, SL("index"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		zephir_array_update_string(&options, SL("persistent"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	_1 = !(zephir_array_isset_string(options, SS("statsKey")));
	if (!(_1)) {
		zephir_array_fetch_string(&_2, options, SL("statsKey"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/redis.zep", 90 TSRMLS_CC);
		_1 = ZEPHIR_IS_EMPTY(_2);
	}
	if (_1) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "_PHCR", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_redis_ce, this_ptr, "__construct", &_3, 36, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to redis
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect) {

	zend_bool _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options, *redis, *persistent, *success = NULL, *host, *port, *auth, *index, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(redis);
	object_init_ex(redis, zephir_get_internal_ce(SS("redis") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, redis, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(host);
	_0 = !(zephir_array_isset_string_fetch(&host, options, SS("host"), 0 TSRMLS_CC));
	if (!(_0)) {
		ZEPHIR_OBS_VAR(port);
		_0 = !(zephir_array_isset_string_fetch(&port, options, SS("port"), 0 TSRMLS_CC));
	}
	_1 = _0;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(persistent);
		_1 = !(zephir_array_isset_string_fetch(&persistent, options, SS("persistent"), 0 TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 108);
		return;
	}
	if (zephir_is_true(persistent)) {
		ZEPHIR_CALL_METHOD(&success, redis, "pconnect", NULL, 0, host, port);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, redis, "connect", NULL, 0, host, port);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVSV(_3, "Could not connect to the Redisd server ", host, ":", port);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 2, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "phalcon/cache/backend/redis.zep", 118 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(auth);
	if (zephir_array_isset_string_fetch(&auth, options, SS("auth"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&success, redis, "auth", NULL, 0, auth);
		zephir_check_call_status();
		if (!(zephir_is_true(success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed to authenticate with the Redisd server", "phalcon/cache/backend/redis.zep", 125);
			return;
		}
	}
	ZEPHIR_OBS_VAR(index);
	if (zephir_array_isset_string_fetch(&index, options, SS("index"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&success, redis, "select", NULL, 0, index);
		zephir_check_call_status();
		if (!(zephir_is_true(success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Redisd server selected database failed", "phalcon/cache/backend/redis.zep", 133);
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_redis"), redis TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 *
 * @param int|string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *lifetime = NULL, *redis = NULL, *frontend, *prefix, *lastKey, *cachedContent = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(lastKey);
	ZEPHIR_CONCAT_SVV(lastKey, "_PHCR", prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&cachedContent, redis, "get", NULL, 0, lastKey);
	zephir_check_call_status();
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	}
	ZEPHIR_RETURN_CALL_METHOD(frontend, "afterretrieve", NULL, 0, cachedContent);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *prefixedKey = NULL, *lastKey = NULL, *prefix, *frontend, *redis = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp, *tt1 = NULL, *success = NULL, *options, *specialKey, *isBuffering = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 5);
		ZEPHIR_INIT_VAR(prefixedKey);
		zephir_substr(prefixedKey, lastKey, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(prefixedKey);
		ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SV(lastKey, "_PHCR", prefixedKey);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/redis.zep", 197);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(content))) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, 0, cachedContent);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(lifetime))) {
		ZEPHIR_OBS_VAR(tmp);
		zephir_read_property_this(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_CALL_METHOD(&tt1, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(tt1, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(tt1, lifetime);
	}
	if (zephir_is_numeric(cachedContent)) {
		ZEPHIR_CALL_METHOD(&success, redis, "set", NULL, 0, lastKey, cachedContent);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, redis, "set", NULL, 0, lastKey, preparedContent);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing the data in redis", "phalcon/cache/backend/redis.zep", 243);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, redis, "settimeout", NULL, 0, lastKey, tt1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 251);
		return;
	}
	ZEPHIR_OBS_VAR(specialKey);
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY, "phalcon/cache/backend/redis.zep", 254 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, redis, "sadd", NULL, 0, specialKey, prefixedKey);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(isBuffering)) {
		zend_print_zval(cachedContent, 0);
	}
	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *redis = NULL, *prefix, *prefixedKey, *lastKey, *options, *specialKey;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	ZEPHIR_INIT_VAR(lastKey);
	ZEPHIR_CONCAT_SV(lastKey, "_PHCR", prefixedKey);
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 293);
		return;
	}
	ZEPHIR_OBS_VAR(specialKey);
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY, "phalcon/cache/backend/redis.zep", 296 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, redis, "srem", NULL, 0, specialKey, prefixedKey);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(redis, "delete", NULL, 0, lastKey);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys) {

	zend_bool _3;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *redis = NULL, *options, *keys = NULL, *specialKey, *key = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 326);
		return;
	}
	ZEPHIR_OBS_VAR(specialKey);
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY, "phalcon/cache/backend/redis.zep", 329 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&keys, redis, "smembers", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1, &_0, 1, 0, "phalcon/cache/backend/redis.zep", 341);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			_3 = zephir_is_true(prefix);
			if (_3) {
				_3 = !(zephir_start_with(value, prefix, NULL));
			}
			if (_3) {
				zephir_array_unset(&keys, key, PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param   long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *redis = NULL, *prefix, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCR", prefix, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_OBS_VAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
		if (Z_TYPE_P(redis) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(redis);
			zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(&_0, redis, "get", NULL, 0, lastKey);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Increment of given $keyName by $value
 *
 * @param  string keyName
 * @param  long lifetime
 * @return long
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, increment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *redis = NULL, *prefix, *lastKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value) {
		ZEPHIR_CPY_WRT(value, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCR", prefix, keyName);
		zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(redis, "incrby", NULL, 0, lastKey, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrement of $keyName by given $value
 *
 * @param  string keyName
 * @param  long value
 * @return long
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *redis = NULL, *prefix, *lastKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value) {
		ZEPHIR_CPY_WRT(value, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCR", prefix, keyName);
		zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(redis, "decrby", NULL, 0, lastKey, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush) {

	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options, *specialKey, *redis = NULL, *keys = NULL, *key = NULL, *lastKey = NULL, **_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 456);
		return;
	}
	ZEPHIR_OBS_VAR(specialKey);
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY, "phalcon/cache/backend/redis.zep", 459 TSRMLS_CC);
	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_METHOD(&keys, redis, "smembers", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1, &_0, 0, 0, "phalcon/cache/backend/redis.zep", 475);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(key, _2);
			ZEPHIR_INIT_NVAR(lastKey);
			ZEPHIR_CONCAT_SV(lastKey, "_PHCR", key);
			ZEPHIR_CALL_METHOD(NULL, redis, "srem", &_3, 0, specialKey, key);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, redis, "delete", &_4, 0, lastKey);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(1);

}

