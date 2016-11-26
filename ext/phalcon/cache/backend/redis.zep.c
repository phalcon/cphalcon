
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *frontend, frontend_sub, *options = NULL, options_sub, __$false, __$null, _0$$4, _1$$5, _2$$6, _3$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_CPY_WRT(options, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	if (!(zephir_array_isset_string(options, SL("host")))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "127.0.0.1");
		zephir_array_update_string(options, SL("host"), &_0$$4, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("port")))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_LONG(&_1$$5, 6379);
		zephir_array_update_string(options, SL("port"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("index")))) {
		ZEPHIR_INIT_VAR(&_2$$6);
		ZVAL_LONG(&_2$$6, 0);
		zephir_array_update_string(options, SL("index"), &_2$$6, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("persistent")))) {
		zephir_array_update_string(options, SL("persistent"), &__$false, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("statsKey")))) {
		ZEPHIR_INIT_VAR(&_3$$8);
		ZVAL_STRING(&_3$$8, "");
		zephir_array_update_string(options, SL("statsKey"), &_3$$8, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_redis_ce, this_ptr, "__construct", &_4, 113, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to redis
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect) {

	zend_bool _0, _1, _4;
	zval options, redis, persistent, success, host, port, auth, index, _2$$6, _3$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&redis);
	object_init_ex(&redis, zephir_get_internal_ce(SL("redis")));
	if (zephir_has_constructor(&redis TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &redis, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&host);
	_0 = !(zephir_array_isset_string_fetch(&host, &options, SL("host"), 0));
	if (!(_0)) {
		ZEPHIR_OBS_VAR(&port);
		_0 = !(zephir_array_isset_string_fetch(&port, &options, SL("port"), 0));
	}
	_1 = _0;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(&persistent);
		_1 = !(zephir_array_isset_string_fetch(&persistent, &options, SL("persistent"), 0));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 114);
		return;
	}
	if (zephir_is_true(&persistent)) {
		ZEPHIR_CALL_METHOD(&success, &redis, "pconnect", NULL, 0, &host, &port);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, &redis, "connect", NULL, 0, &host, &port);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&success))) {
		ZEPHIR_INIT_VAR(&_2$$6);
		object_init_ex(&_2$$6, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$6);
		ZEPHIR_CONCAT_SVSV(&_3$$6, "Could not connect to the Redisd server ", &host, ":", &port);
		ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 9, &_3$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$6, "phalcon/cache/backend/redis.zep", 124 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&auth);
	if (zephir_array_isset_string_fetch(&auth, &options, SL("auth"), 0)) {
		ZEPHIR_CALL_METHOD(&success, &redis, "auth", NULL, 0, &auth);
		zephir_check_call_status();
		if (!(zephir_is_true(&success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed to authenticate with the Redisd server", "phalcon/cache/backend/redis.zep", 131);
			return;
		}
	}
	ZEPHIR_OBS_VAR(&index);
	_4 = zephir_array_isset_string_fetch(&index, &options, SL("index"), 0);
	if (_4) {
		_4 = ZEPHIR_GT_LONG(&index, 0);
	}
	if (_4) {
		ZEPHIR_CALL_METHOD(&success, &redis, "select", NULL, 0, &index);
		zephir_check_call_status();
		if (!(zephir_is_true(&success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Redis server selected database failed", "phalcon/cache/backend/redis.zep", 139);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("_redis"), &redis);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, get) {

	int lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, redis, frontend, prefix, lastKey, cachedContent;
	zval keyName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&cachedContent);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&prefix);
	zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&lastKey);
	ZEPHIR_CONCAT_SVV(&lastKey, "_PHCR", &prefix, &keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	ZEPHIR_CALL_METHOD(&cachedContent, &redis, "get", NULL, 0, &lastKey);
	zephir_check_call_status();
	if (!(zephir_is_true(&cachedContent))) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(&cachedContent)) {
		RETURN_CCTOR(cachedContent);
	}
	ZEPHIR_RETURN_CALL_METHOD(&frontend, "afterretrieve", NULL, 0, &cachedContent);
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
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, prefixedKey, lastKey, frontend, redis, cachedContent, preparedContent, tmp, tt1, success, options, specialKey, isBuffering, _0$$3, _1$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&preparedContent);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tt1);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!content) {
		content = &content_sub;
		content = &__$null;
	}
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
		ZVAL_LONG(&_0$$3, 5);
		ZEPHIR_INIT_VAR(&prefixedKey);
		zephir_substr(&prefixedKey, &lastKey, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&prefixedKey);
		ZEPHIR_CONCAT_VV(&prefixedKey, &_1$$4, keyName);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SV(&lastKey, "_PHCR", &prefixedKey);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/redis.zep", 199);
		return;
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&cachedContent, &frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&cachedContent, content);
	}
	if (!(zephir_is_numeric(&cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, &frontend, "beforestore", NULL, 0, &cachedContent);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&preparedContent, &cachedContent);
	}
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_VAR(&tmp);
		zephir_read_property(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(&tmp))) {
			ZEPHIR_CALL_METHOD(&tt1, &frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&tt1, &tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(&tt1, lifetime);
	}
	ZEPHIR_CALL_METHOD(&success, &redis, "set", NULL, 0, &lastKey, &preparedContent);
	zephir_check_call_status();
	if (!(zephir_is_true(&success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing the data in redis", "phalcon/cache/backend/redis.zep", 243);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, &redis, "settimeout", NULL, 0, &lastKey, &tt1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 251);
		return;
	}
	if (!ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_CALL_METHOD(NULL, &redis, "sadd", NULL, 0, &specialKey, &prefixedKey);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&isBuffering, &frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, &frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&isBuffering)) {
		zend_print_zval(&cachedContent, 0);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
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
	zval *keyName, keyName_sub, redis, prefix, prefixedKey, lastKey, options, specialKey, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&prefix);
	zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &prefix, keyName);
	ZEPHIR_INIT_VAR(&lastKey);
	ZEPHIR_CONCAT_SV(&lastKey, "_PHCR", &prefixedKey);
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 294);
		return;
	}
	if (!ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_CALL_METHOD(NULL, &redis, "srem", NULL, 0, &specialKey, &prefixedKey);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, &redis, "delete", NULL, 0, &lastKey);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_0));

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys) {

	zend_bool _3$$7;
	zend_string *_2$$6;
	zend_ulong _1$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, prefix_sub, __$null, redis, options, keys, specialKey, key, value, *_0$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&prefix_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = &prefix_sub;
		prefix = &__$null;
	}


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 326);
		return;
	}
	if (ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/redis.zep", 330);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, &redis, "smembers", NULL, 0, &specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		zephir_is_iterable(&keys, 1, "phalcon/cache/backend/redis.zep", 344);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _1$$6, _2$$6, _0$$6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$6 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$6);
			} else {
				ZVAL_LONG(&key, _1$$6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$6);
			_3$$7 = zephir_is_true(prefix);
			if (_3$$7) {
				_3$$7 = !(zephir_start_with(&value, prefix, NULL));
			}
			if (_3$$7) {
				zephir_array_unset(&keys, &key, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
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
	zval *keyName = NULL, keyName_sub, *lifetime = NULL, lifetime_sub, __$null, lastKey, redis, prefix, _0$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCR", &prefix, keyName);
	}
	if (zephir_is_true(&lastKey)) {
		ZEPHIR_OBS_VAR(&redis);
		zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
		if (Z_TYPE_P(&redis) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&redis);
			zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(&_0$$5, &redis, "get", NULL, 0, &lastKey);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0$$5))) {
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
	zval *keyName = NULL, keyName_sub, *value = NULL, value_sub, __$null, redis, prefix, lastKey;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&lastKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCR", &prefix, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(&redis, "incrby", NULL, 0, &lastKey, value);
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
	zval *keyName = NULL, keyName_sub, *value = NULL, value_sub, __$null, redis, prefix, lastKey;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&lastKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCR", &prefix, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(&redis, "decrby", NULL, 0, &lastKey, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush) {

	zval options, specialKey, redis, keys, key, lastKey, *_0$$6;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lastKey);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 458);
		return;
	}
	ZEPHIR_OBS_VAR(&redis);
	zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&redis);
		zephir_read_property(&redis, this_ptr, SL("_redis"), PH_NOISY_CC);
	}
	if (ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/redis.zep", 469);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, &redis, "smembers", NULL, 0, &specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		zephir_is_iterable(&keys, 0, "phalcon/cache/backend/redis.zep", 479);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0$$6)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _0$$6);
			ZEPHIR_INIT_NVAR(&lastKey);
			ZEPHIR_CONCAT_SV(&lastKey, "_PHCR", &key);
			ZEPHIR_CALL_METHOD(NULL, &redis, "srem", &_1, 0, &specialKey, &key);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &redis, "delete", &_2, 0, &lastKey);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&key);
	}
	RETURN_MM_BOOL(1);

}

