
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cache\Backend\Redis
 *
 * Allows to cache output fragments, PHP data or raw data to a redis backend
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
 * // Create the Cache setting redis connection options with statsKey
 * $cache = new Redis(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "index"      => 0,
 *         "statsKey"   => "_PHCR_",
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

	zend_declare_property_null(phalcon_cache_backend_redis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cache_backend_redis_ce, SL("statsKey"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Redis constructor
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL;
	zval options;
	zval *frontend, frontend_sub, *options_param = NULL, __$false, _0$$4, _1$$5, _2$$6, _3$$8, _4$$9, _5$$10, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (1 != 1) {
		ZEPHIR_INIT_NVAR(&options);
		array_init(&options);
	}
	if (!(zephir_array_isset_string(&options, SL("host")))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "127.0.0.1");
		zephir_array_update_string(&options, SL("host"), &_0$$4, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&options, SL("port")))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_LONG(&_1$$5, 6379);
		zephir_array_update_string(&options, SL("port"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&options, SL("index")))) {
		ZEPHIR_INIT_VAR(&_2$$6);
		ZVAL_LONG(&_2$$6, 0);
		zephir_array_update_string(&options, SL("index"), &_2$$6, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&options, SL("persistent")))) {
		zephir_array_update_string(&options, SL("persistent"), &__$false, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&options, SL("statsKey")))) {
		ZEPHIR_INIT_VAR(&_3$$8);
		ZVAL_STRING(&_3$$8, "");
		zephir_array_update_string(&options, SL("statsKey"), &_3$$8, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&options, SL("auth")))) {
		ZEPHIR_INIT_VAR(&_4$$9);
		ZVAL_STRING(&_4$$9, "");
		zephir_array_update_string(&options, SL("auth"), &_4$$9, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&options, SL("timeout")))) {
		ZEPHIR_INIT_VAR(&_5$$10);
		ZVAL_LONG(&_5$$10, 0);
		zephir_array_update_string(&options, SL("timeout"), &_5$$10, PH_COPY | PH_SEPARATE);
	}
	zephir_array_fetch_string(&_6, &options, SL("statsKey"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/redis.zep", 111 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("statsKey"), &_6);
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_redis_ce, getThis(), "__construct", &_7, 0, frontend, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to redis
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, connect) {

	zend_bool _0, _1, _2, _5, _7;
	zval options, redis, persistent, success, host, port, auth, index, timeout, _6, _3$$6, _4$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&timeout);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);

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
	_2 = _1;
	if (!(_2)) {
		ZEPHIR_OBS_VAR(&timeout);
		_2 = !(zephir_array_isset_string_fetch(&timeout, &options, SL("timeout"), 0));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/redis.zep", 126);
		return;
	}
	if (zephir_is_true(&persistent)) {
		ZEPHIR_CALL_METHOD(&success, &redis, "pconnect", NULL, 0, &host, &port, &timeout);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, &redis, "connect", NULL, 0, &host, &port, &timeout);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&success))) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_cache_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVSV(&_4$$6, "Could not connect to the Redisd server ", &host, ":", &port);
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 4, &_4$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "phalcon/cache/backend/redis.zep", 136 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&auth);
	_5 = zephir_array_isset_string_fetch(&auth, &options, SL("auth"), 0);
	if (_5) {
		zephir_array_fetch_string(&_6, &options, SL("auth"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/redis.zep", 139 TSRMLS_CC);
		_5 = !(ZEPHIR_IS_EMPTY(&_6));
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&success, &redis, "auth", NULL, 0, &auth);
		zephir_check_call_status();
		if (!(zephir_is_true(&success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed to authenticate with the Redisd server", "phalcon/cache/backend/redis.zep", 143);
			return;
		}
	}
	ZEPHIR_OBS_VAR(&index);
	_7 = zephir_array_isset_string_fetch(&index, &options, SL("index"), 0);
	if (_7) {
		_7 = ZEPHIR_GT_LONG(&index, 0);
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&success, &redis, "select", NULL, 0, &index);
		zephir_check_call_status();
		if (!(zephir_is_true(&success))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Redis server selected database failed", "phalcon/cache/backend/redis.zep", 151);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("redis"), &redis);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime = NULL, lifetime_sub, __$null, redis, frontend, cachedContent, _0, _2, _1$$3;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime);

	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&redis, &_0);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&redis, &_1$$3);
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstorekey", NULL, 106, &keyName);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &_2);
	zephir_read_property(&_0, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&cachedContent, &redis, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(&cachedContent)) {
		RETURN_CCTOR(&cachedContent);
	}
	ZEPHIR_RETURN_CALL_METHOD(&frontend, "afterretrieve", NULL, 0, &cachedContent);
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
 * @param bool stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, prefixedKey, frontend, redis, cachedContent, preparedContent, tmp, ttl, success, isBuffering, _4, _5, _8, _0$$3, _1$$3, _2$$3, _3$$4, _6$$6, _7$$16, _9$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&preparedContent);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$16);
	ZVAL_UNDEF(&_9$$17);

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
		zephir_read_property(&_0$$3, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, zephir_fast_strlen_ev(&_1$$3));
		ZEPHIR_INIT_VAR(&prefixedKey);
		zephir_substr(&prefixedKey, &_0$$3, zephir_get_intval(&_2$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else {
		ZEPHIR_CALL_METHOD(&prefixedKey, this_ptr, "getprefixedkey", NULL, 107, keyName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getstorekey", NULL, 106, keyName);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_4))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/redis.zep", 214);
		return;
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	zephir_read_property(&_5, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&redis, &_5);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_6$$6, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&redis, &_6$$6);
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
			ZEPHIR_CALL_METHOD(&ttl, &frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&ttl, &tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(&ttl, lifetime);
	}
	zephir_read_property(&_5, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&success, &redis, "set", NULL, 0, &_5, &preparedContent);
	zephir_check_call_status();
	if (!(zephir_is_true(&success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing the data in redis", "phalcon/cache/backend/redis.zep", 257);
		return;
	}
	if (ZEPHIR_GE_LONG(&ttl, 1)) {
		zephir_read_property(&_7$$16, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &redis, "settimeout", NULL, 0, &_7$$16, &ttl);
		zephir_check_call_status();
	}
	zephir_read_property(&_8, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING(&_8, "")) {
		zephir_read_property(&_9$$17, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &redis, "sadd", NULL, 0, &_9$$17, &prefixedKey);
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
	RETURN_CCTOR(&success);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, redis, prefixedKey, _0, _2, _4, _5, _1$$3, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&redis, &_0);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&redis, &_1$$3);
	}
	ZEPHIR_CALL_METHOD(&prefixedKey, this_ptr, "getprefixedkey", NULL, 107, keyName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstorekey", NULL, 106, keyName);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &_2);
	zephir_read_property(&_0, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING(&_0, "")) {
		zephir_read_property(&_3$$4, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &redis, "srem", NULL, 0, &_3$$4, &prefixedKey);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &redis, "delete", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_4));

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

	zend_bool _7$$6, _8$$8;
	zend_string *_6;
	zend_ulong _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, redis, keys, key, idx, _0, _2, *_3, _4, _1$$3;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&redis, &_0);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&redis, &_1$$3);
	}
	zephir_read_property(&_0, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_0, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!", "phalcon/cache/backend/redis.zep", 333);
		return;
	}
	zephir_read_property(&_2, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&keys, &redis, "smembers", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_is_iterable(&keys, 1, "phalcon/cache/backend/redis.zep", 350);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&idx);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&idx, _6);
			} else {
				ZVAL_LONG(&idx, _5);
			}
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _3);
			_7$$6 = !(ZEPHIR_IS_EMPTY(&prefix));
			if (_7$$6) {
				_7$$6 = !(zephir_start_with(&key, &prefix, NULL));
			}
			if (_7$$6) {
				zephir_array_unset(&keys, &idx, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &keys, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
			zephir_check_call_status();
				_8$$8 = !(ZEPHIR_IS_EMPTY(&prefix));
				if (_8$$8) {
					_8$$8 = !(zephir_start_with(&key, &prefix, NULL));
				}
				if (_8$$8) {
					zephir_array_unset(&keys, &idx, PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CCTOR(&keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, exists) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *lifetime_param = NULL, __$null, redis, _1, _0$$3, _2$$4, _4$$4, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (zephir_is_true(keyName)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getstorekey", NULL, 106, keyName);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &_0$$3);
	}
	zephir_read_property(&_1, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2$$4, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&redis, &_2$$4);
		if (Z_TYPE_P(&redis) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_3$$5, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&redis, &_3$$5);
		}
		zephir_read_property(&_2$$4, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$4, &redis, "exists", NULL, 0, &_2$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_get_boolval(&_4$$4));
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
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, redis, _0, _3, _1$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&redis, &_0);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&redis, &_1$$3);
	}
	if (zephir_is_true(keyName)) {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getstorekey", NULL, 106, keyName);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &_2$$4);
	}
	zephir_read_property(&_0, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, value);
	ZEPHIR_RETURN_CALL_METHOD(&redis, "incrby", NULL, 0, &_0, &_3);
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
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, redis, _0, _3, _1$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&redis, &_0);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&redis, &_1$$3);
	}
	if (zephir_is_true(keyName)) {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getstorekey", NULL, 106, keyName);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &_2$$4);
	}
	zephir_read_property(&_0, this_ptr, SL("_lastKey"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, value);
	ZEPHIR_RETURN_CALL_METHOD(&redis, "decrby", NULL, 0, &_0, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush) {

	zval redis, keys, key, lastKey, _0, _1, _2$$4, *_3$$5, _4$$5, _5$$6, _6$$6, _9$$7, _10$$7;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_0, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!", "phalcon/cache/backend/redis.zep", 432);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&redis, &_1);
	if (Z_TYPE_P(&redis) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_2$$4, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&redis, &_2$$4);
	}
	zephir_read_property(&_1, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&keys, &redis, "smembers", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		zephir_is_iterable(&keys, 0, "phalcon/cache/backend/redis.zep", 448);
		if (Z_TYPE_P(&keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _3$$5)
			{
				ZEPHIR_INIT_NVAR(&key);
				ZVAL_COPY(&key, _3$$5);
				zephir_read_property(&_5$$6, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&lastKey);
				ZEPHIR_CONCAT_VV(&lastKey, &_5$$6, &key);
				zephir_read_property(&_6$$6, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &redis, "srem", &_7, 0, &_6$$6, &key);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &redis, "delete", &_8, 0, &lastKey);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$5, &keys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property(&_9$$7, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&lastKey);
					ZEPHIR_CONCAT_VV(&lastKey, &_9$$7, &key);
					zephir_read_property(&_10$$7, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &redis, "srem", &_11, 0, &_10$$7, &key);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &redis, "delete", &_12, 0, &lastKey);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&key);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns the key with its prefix
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, getPrefixedKey) {

	zval *keyName_param = NULL, _0;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName_param);

	zephir_get_strval(&keyName, keyName_param);


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &keyName);
	RETURN_MM();

}

/**
 * Returns the store key with the special key and prefix
 */
PHP_METHOD(Phalcon_Cache_Backend_Redis, getStoreKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, _0, _1;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName_param);

	zephir_get_strval(&keyName, keyName_param);


	zephir_read_property(&_0, this_ptr, SL("statsKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedkey", NULL, 107, &keyName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_1);
	RETURN_MM();

}

