
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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
 * use Phalcon\Cache\Backend\Redis;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData([
 *     'lifetime' => 172800
 * ]);
 *
 * // Create the Cache setting redis connection options
 * $cache = new Redis($frontCache, [
 *     'host' => 'localhost',
 *     'port' => 6379,
 *     'auth' => 'foobared',
 *     'persistent' => false
 *     'index' => 0,
 * ]);
 *
 * // Cache arbitrary data
 * $cache->save('my-data', [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get('my-data');
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
	zephir_fcall_cache_entry *_4 = NULL;
	zval *frontend, *options = NULL, *_0$$4, *_1$$5, *_2$$6, *_3$$8;

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
		ZEPHIR_INIT_VAR(_0$$4);
		ZVAL_STRING(_0$$4, "127.0.0.1", 1);
		zephir_array_update_string(&options, SL("host"), &_0$$4, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("port")))) {
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_LONG(_1$$5, 6379);
		zephir_array_update_string(&options, SL("port"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("index")))) {
		ZEPHIR_INIT_VAR(_2$$6);
		ZVAL_LONG(_2$$6, 0);
		zephir_array_update_string(&options, SL("index"), &_2$$6, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		zephir_array_update_string(&options, SL("persistent"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_3$$8);
		ZVAL_STRING(_3$$8, "", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_3$$8, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_redis_ce, this_ptr, "__construct", &_4, 113, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to redis
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect) {

	zend_bool _0, _1;
	zval *options = NULL, *redis = NULL, *persistent = NULL, *success = NULL, *host = NULL, *port = NULL, *auth = NULL, *index = NULL, *_2$$6, *_3$$6;
	int ZEPHIR_LAST_CALL_STATUS;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 110);
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
		ZEPHIR_INIT_VAR(_2$$6);
		object_init_ex(_2$$6, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(_3$$6);
		ZEPHIR_CONCAT_SVSV(_3$$6, "Could not connect to the Redisd server ", host, ":", port);
		ZEPHIR_CALL_METHOD(NULL, _2$$6, "__construct", NULL, 9, _3$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$6, "phalcon/cache/backend/redis.zep", 120 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(auth);
	if (zephir_array_isset_string_fetch(&auth, options, SS("auth"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&success, redis, "auth", NULL, 0, auth);
		zephir_check_call_status();
		if (!(zephir_is_true(success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed to authenticate with the Redisd server", "phalcon/cache/backend/redis.zep", 127);
			return;
		}
	}
	ZEPHIR_OBS_VAR(index);
	if (zephir_array_isset_string_fetch(&index, options, SS("index"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&success, redis, "select", NULL, 0, index);
		zephir_check_call_status();
		if (!(zephir_is_true(success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Redisd server selected database failed", "phalcon/cache/backend/redis.zep", 135);
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_redis"), redis TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, get) {

	int lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, *redis = NULL, *frontend = NULL, *prefix = NULL, *lastKey = NULL, *cachedContent = NULL;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
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
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *prefixedKey = NULL, *lastKey = NULL, *prefix = NULL, *frontend = NULL, *redis = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp = NULL, *tt1 = NULL, *success = NULL, *options = NULL, *specialKey = NULL, *isBuffering = NULL, _0$$3;

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


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, 5);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/redis.zep", 195);
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
	if (Z_TYPE_P(content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, 0, cachedContent);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(lifetime) == IS_NULL) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing the data in redis", "phalcon/cache/backend/redis.zep", 241);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, redis, "settimeout", NULL, 0, lastKey, tt1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 249);
		return;
	}
	if (!ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_CALL_METHOD(NULL, redis, "sadd", NULL, 0, specialKey, prefixedKey);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(isBuffering)) {
		zend_print_zval(cachedContent, 0);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_CCTOR(success);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *redis = NULL, *prefix = NULL, *prefixedKey = NULL, *lastKey = NULL, *options = NULL, *specialKey = NULL, *_0 = NULL;

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
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 292);
		return;
	}
	if (!ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_CALL_METHOD(NULL, redis, "srem", NULL, 0, specialKey, prefixedKey);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, redis, "delete", NULL, 0, lastKey);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(_0));

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys) {

	zend_bool _3$$7;
	HashTable *_1$$6;
	HashPosition _0$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *redis = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *key = NULL, *value = NULL, **_2$$6;

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
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 324);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/redis.zep", 328);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, redis, "smembers", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1$$6, &_0$$6, 1, 0, "phalcon/cache/backend/redis.zep", 342);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$6, (void**) &_2$$6, &_0$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$6, &_0$$6)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$6, _0$$6);
			ZEPHIR_GET_HVALUE(value, _2$$6);
			_3$$7 = zephir_is_true(prefix);
			if (_3$$7) {
				_3$$7 = !(zephir_start_with(value, prefix, NULL));
			}
			if (_3$$7) {
				zephir_array_unset(&keys, key, PH_SEPARATE);
			}
		}
		zend_hash_destroy(_1$$6);
		FREE_HASHTABLE(_1$$6);
		RETURN_CCTOR(keys);
	}
	array_init(return_value);
	RETURN_MM();

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
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *redis = NULL, *prefix = NULL, *_0$$5 = NULL;

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
		ZEPHIR_CALL_METHOD(&_0$$5, redis, "get", NULL, 0, lastKey);
		zephir_check_call_status();
		if (!(zephir_is_true(_0$$5))) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Increment of given $keyName by $value
 *
 * @param string keyName
 * @param long value
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, increment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *redis = NULL, *prefix = NULL, *lastKey = NULL;

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
 * @param string keyName
 * @param long value
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *redis = NULL, *prefix = NULL, *lastKey = NULL;

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

	HashTable *_1$$6;
	HashPosition _0$$6;
	zval *options = NULL, *specialKey = NULL, *redis = NULL, *keys = NULL, *key = NULL, **_2$$6;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 456);
		return;
	}
	ZEPHIR_OBS_VAR(redis);
	zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(redis);
		zephir_read_property_this(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/redis.zep", 467);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, redis, "smembers", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1$$6, &_0$$6, 0, 0, "phalcon/cache/backend/redis.zep", 476);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$6, (void**) &_2$$6, &_0$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$6, &_0$$6)
		) {
			ZEPHIR_GET_HVALUE(key, _2$$6);
			ZEPHIR_CALL_METHOD(NULL, redis, "srem", &_3, 0, specialKey, key);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, redis, "delete", &_4, 0, key);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(1);

}

