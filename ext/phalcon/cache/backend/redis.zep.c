
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
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the Cache setting redis connection options
 * $cache = new Redis(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "index"      => 0,
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Redis, phalcon, cache_backend_redis, phalcon_cache_backend_ce, phalcon_cache_backend_redis_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_redis_ce, SL("_redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Redis constructor
 *
 * @param	Phalcon\Cache\FrontendInterface frontend
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *frontend, *options = NULL, *_0$$4, *_1$$5, *_2$$6, *_3$$8, *_4$$9, *_5$$10;

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
	if (!(zephir_array_isset_string(options, SS("auth")))) {
		ZEPHIR_INIT_VAR(_4$$9);
		ZVAL_STRING(_4$$9, "", 1);
		zephir_array_update_string(&options, SL("auth"), &_4$$9, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("timeout")))) {
		ZEPHIR_INIT_VAR(_5$$10);
		ZVAL_LONG(_5$$10, 0);
		zephir_array_update_string(&options, SL("timeout"), &_5$$10, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_redis_ce, getThis(), "__construct", &_6, 124, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to redis
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect) {

	zend_bool _0, _1, _2, _5, _7;
	zval *options = NULL, *redis = NULL, *persistent = NULL, *success = NULL, *host = NULL, *port = NULL, *auth = NULL, *index = NULL, *timeout = NULL, *_6, *_3$$6, *_4$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(redis);
	object_init_ex(redis, zephir_get_internal_ce(SS("redis") TSRMLS_CC));
	if (zephir_has_constructor(redis TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, redis, "__construct", NULL, 0);
		zephir_check_call_status();
	}
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
	_2 = _1;
	if (!(_2)) {
		ZEPHIR_OBS_VAR(timeout);
		_2 = !(zephir_array_isset_string_fetch(&timeout, options, SS("timeout"), 0 TSRMLS_CC));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 120);
		return;
	}
	if (zephir_is_true(persistent)) {
		ZEPHIR_CALL_METHOD(&success, redis, "pconnect", NULL, 0, host, port, timeout);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, redis, "connect", NULL, 0, host, port, timeout);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_INIT_VAR(_3$$6);
		object_init_ex(_3$$6, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(_4$$6);
		ZEPHIR_CONCAT_SVSV(_4$$6, "Could not connect to the Redisd server ", host, ":", port);
		ZEPHIR_CALL_METHOD(NULL, _3$$6, "__construct", NULL, 9, _4$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$6, "phalcon/cache/backend/redis.zep", 130 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(auth);
	_5 = zephir_array_isset_string_fetch(&auth, options, SS("auth"), 0 TSRMLS_CC);
	if (_5) {
		zephir_array_fetch_string(&_6, options, SL("auth"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/redis.zep", 133 TSRMLS_CC);
		_5 = !(ZEPHIR_IS_EMPTY(_6));
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&success, redis, "auth", NULL, 0, auth);
		zephir_check_call_status();
		if (!(zephir_is_true(success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed to authenticate with the Redisd server", "phalcon/cache/backend/redis.zep", 137);
			return;
		}
	}
	ZEPHIR_OBS_VAR(index);
	_7 = zephir_array_isset_string_fetch(&index, options, SS("index"), 0 TSRMLS_CC);
	if (_7) {
		_7 = ZEPHIR_GT_LONG(index, 0);
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&success, redis, "select", NULL, 0, index);
		zephir_check_call_status();
		if (!(zephir_is_true(success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Redis server selected database failed", "phalcon/cache/backend/redis.zep", 145);
			return;
		}
	}
	zephir_update_property_this(getThis(), SL("_redis"), redis TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, get) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
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
	zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&cachedContent, redis, "get", NULL, 0, lastKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
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
 * <code>
 * $cache->save("my-key", $data);
 *
 * // Save data termlessly
 * $cache->save("my-key", $data, -1);
 * </code>
 *
 * @param int|string keyName
 * @param string content
 * @param int lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *prefixedKey = NULL, *lastKey = NULL, *frontend = NULL, *redis = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp = NULL, *tt1 = NULL, *success = NULL, *options = NULL, *specialKey = NULL, *isBuffering = NULL, _0$$3, *_1$$4;

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
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(prefixedKey);
		ZEPHIR_CONCAT_VV(prefixedKey, _1$$4, keyName);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SV(lastKey, "_PHCR", prefixedKey);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/redis.zep", 212);
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
	} else {
		ZEPHIR_CPY_WRT(preparedContent, cachedContent);
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
	ZEPHIR_CALL_METHOD(&success, redis, "set", NULL, 0, lastKey, preparedContent);
	zephir_check_call_status();
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing the data in redis", "phalcon/cache/backend/redis.zep", 256);
		return;
	}
	if (ZEPHIR_GE_LONG(tt1, 1)) {
		ZEPHIR_CALL_METHOD(NULL, redis, "settimeout", NULL, 0, lastKey, tt1);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 267);
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
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_CCTOR(success);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 310);
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
 * Query the existing cached keys.
 *
 * <code>
 * $cache->save("users-ids", [1, 2, 3]);
 * $cache->save("projects-ids", [4, 5, 6]);
 *
 * var_dump($cache->queryKeys("users")); // ["users-ids"]
 * </code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys) {

	zend_bool _3$$7;
	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *redis = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *key = NULL, *idx = NULL, **_2;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 347);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!", "phalcon/cache/backend/redis.zep", 351);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, redis, "smembers", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_is_iterable(keys, &_1, &_0, 1, 0, "phalcon/cache/backend/redis.zep", 368);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(idx, _1, _0);
		ZEPHIR_GET_HVALUE(key, _2);
		_3$$7 = !(ZEPHIR_IS_EMPTY(prefix));
		if (_3$$7) {
			_3$$7 = !(zephir_start_with(key, prefix, NULL));
		}
		if (_3$$7) {
			zephir_array_unset(&keys, idx, PH_SEPARATE);
		}
	}
	zend_hash_destroy(_1);
	FREE_HASHTABLE(_1);
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, exists) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey = NULL, *redis = NULL, *prefix = NULL, *_0$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
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
		ZEPHIR_CALL_METHOD(&_0$$5, redis, "exists", NULL, 0, lastKey);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_get_boolval(_0$$5));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Increment of given $keyName by $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *redis = NULL, *prefix = NULL, *lastKey = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
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
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, value);
	ZEPHIR_RETURN_CALL_METHOD(redis, "incrby", NULL, 0, lastKey, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrement of $keyName by given $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *redis = NULL, *prefix = NULL, *lastKey = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
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
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, value);
	ZEPHIR_RETURN_CALL_METHOD(redis, "decrby", NULL, 0, lastKey, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush) {

	HashTable *_1$$6;
	HashPosition _0$$6;
	zval *options = NULL, *specialKey = NULL, *redis = NULL, *keys = NULL, *key = NULL, *lastKey = NULL, **_2$$6;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 465);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!", "phalcon/cache/backend/redis.zep", 476);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, redis, "smembers", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1$$6, &_0$$6, 0, 0, "phalcon/cache/backend/redis.zep", 486);
		for (
		  ; zend_hash_get_current_data_ex(_1$$6, (void**) &_2$$6, &_0$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$6, &_0$$6)
		) {
			ZEPHIR_GET_HVALUE(key, _2$$6);
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

