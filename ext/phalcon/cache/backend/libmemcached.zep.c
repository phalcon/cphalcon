
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
 * Phalcon\Cache\Backend\Libmemcached
 *
 * Allows to cache output fragments, PHP data or raw data to a libmemcached backend.
 * Per default persistent memcached connection pools are used.
 *
 *<code>
 * use Phalcon\Cache\Backend\Libmemcached;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the Cache setting memcached connection options
 * $cache = new Libmemcached(
 *     $frontCache,
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "127.0.0.1",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *             \Memcached::OPT_HASH       => \Memcached::HASH_MD5,
 *             \Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
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
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Libmemcached) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Libmemcached, phalcon, cache_backend_libmemcached, phalcon_cache_backend_ce, phalcon_cache_backend_libmemcached_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_libmemcached_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Memcache constructor
 *
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, __construct) {

	zval _0$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *frontend, frontend_sub, *options = NULL, options_sub, __$null, servers, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&servers);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_0$$4);

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
	if (!(zephir_array_isset_string(options, SL("servers")))) {
		ZEPHIR_INIT_VAR(&servers);
		zephir_create_array(&servers, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_create_array(&_0$$4, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_0$$4, SL("host"), SL("127.0.0.1"));
		add_assoc_long_ex(&_0$$4, SL("port"), 11211);
		add_assoc_long_ex(&_0$$4, SL("weight"), 1);
		zephir_array_update_long(&servers, 0, &_0$$4, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
		zephir_array_update_string(options, SL("servers"), &servers, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("statsKey")))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "");
		zephir_array_update_string(options, SL("statsKey"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_libmemcached_ce, getThis(), "__construct", &_2, 0, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, _connect) {

	zval options, memcache, client, servers, persistentId, _0, _1$$4, _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&servers);
	ZVAL_UNDEF(&persistentId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&persistentId);
	if (!(zephir_array_isset_string_fetch(&persistentId, &options, SL("persistent_id"), 0))) {
		ZEPHIR_INIT_NVAR(&persistentId);
		ZVAL_STRING(&persistentId, "phalcon_cache");
	}
	ZEPHIR_INIT_VAR(&memcache);
	object_init_ex(&memcache, zephir_get_internal_ce(SL("memcached")));
	ZEPHIR_CALL_METHOD(NULL, &memcache, "__construct", NULL, 0, &persistentId);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &memcache, "getserverlist", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_OBS_VAR(&servers);
		if (!(zephir_array_isset_string_fetch(&servers, &options, SL("servers"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Servers must be an array", "phalcon/cache/backend/libmemcached.zep", 110);
			return;
		}
		if (Z_TYPE_P(&servers) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Servers must be an array", "phalcon/cache/backend/libmemcached.zep", 114);
			return;
		}
		ZEPHIR_OBS_VAR(&client);
		if (!(zephir_array_isset_string_fetch(&client, &options, SL("client"), 0))) {
			ZEPHIR_INIT_NVAR(&client);
			array_init(&client);
		}
		if (Z_TYPE_P(&client) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Client options must be instance of array", "phalcon/cache/backend/libmemcached.zep", 122);
			return;
		}
		ZEPHIR_CALL_METHOD(&_1$$4, &memcache, "setoptions", NULL, 0, &client);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1$$4))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cannot set to Memcached options", "phalcon/cache/backend/libmemcached.zep", 126);
			return;
		}
		ZEPHIR_CALL_METHOD(&_2$$4, &memcache, "addservers", NULL, 0, &servers);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2$$4))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server", "phalcon/cache/backend/libmemcached.zep", 130);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("_memcache"), &memcache);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime = NULL, lifetime_sub, __$null, memcache, prefixedKey, cachedContent, _0, _1, _2;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime);

	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	ZEPHIR_OBS_VAR(&memcache);
	zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(&memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, &keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZEPHIR_CALL_METHOD(&cachedContent, &memcache, "get", NULL, 0, &prefixedKey);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &memcache, "getresultcode", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&_1, 16)) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(&cachedContent)) {
		RETURN_CCTOR(&cachedContent);
	}
	zephir_read_property(&_2, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "afterretrieve", NULL, 0, &cachedContent);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastKey, frontend, memcache, cachedContent, preparedContent, tmp, tt1, success, options, specialKey, keys, isBuffering, _0$$4, _1$$15, _2$$15, _3$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&preparedContent);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tt1);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$15);
	ZVAL_UNDEF(&_2$$15);
	ZVAL_UNDEF(&_3$$15);

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
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &_0$$4, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/libmemcached.zep", 186);
		return;
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&memcache);
	zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(&memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
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
	ZEPHIR_CALL_METHOD(&success, &memcache, "set", NULL, 0, &lastKey, &preparedContent, &tt1);
	zephir_check_call_status();
	if (!(zephir_is_true(&success))) {
		ZEPHIR_INIT_VAR(&_1$$15);
		object_init_ex(&_1$$15, phalcon_cache_exception_ce);
		ZEPHIR_CALL_METHOD(&_2$$15, &memcache, "getresultcode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$15);
		ZEPHIR_CONCAT_SV(&_3$$15, "Failed storing data in memcached, error code: ", &_2$$15);
		ZEPHIR_CALL_METHOD(NULL, &_1$$15, "__construct", NULL, 4, &_3$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$15, "phalcon/cache/backend/libmemcached.zep", 230 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 236);
		return;
	}
	if (!ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_CALL_METHOD(&keys, &memcache, "get", NULL, 0, &specialKey);
		zephir_check_call_status();
		if (Z_TYPE_P(&keys) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&keys);
			array_init(&keys);
		}
		if (!(zephir_array_isset(&keys, &lastKey))) {
			zephir_array_update_zval(&keys, &lastKey, &tt1, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &memcache, "set", NULL, 0, &specialKey, &keys);
			zephir_check_call_status();
		}
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
 * @return bool
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, memcache, prefixedKey, options, keys, specialKey, ret, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(&memcache);
	zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(&memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, keyName);
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 289);
		return;
	}
	if (!ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_CALL_METHOD(&keys, &memcache, "get", NULL, 0, &specialKey);
		zephir_check_call_status();
		if (Z_TYPE_P(&keys) == IS_ARRAY) {
			zephir_array_unset(&keys, &prefixedKey, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &memcache, "set", NULL, 0, &specialKey, &keys);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&ret, &memcache, "delete", NULL, 0, &prefixedKey);
	zephir_check_call_status();
	RETURN_CCTOR(&ret);

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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, queryKeys) {

	zend_bool _5$$7, _6$$9;
	zend_string *_4;
	zend_ulong _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, memcache, options, keys, specialKey, key, idx, _0, *_1, _2;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	ZEPHIR_OBS_VAR(&memcache);
	zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(&memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 331);
		return;
	}
	if (ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/libmemcached.zep", 335);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, &memcache, "get", NULL, 0, &specialKey);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&keys) != IS_ARRAY)) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, &keys TSRMLS_CC);
	ZEPHIR_CPY_WRT(&keys, &_0);
	zephir_is_iterable(&keys, 1, "phalcon/cache/backend/libmemcached.zep", 353);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&idx);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&idx, _4);
			} else {
				ZVAL_LONG(&idx, _3);
			}
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _1);
			_5$$7 = !(ZEPHIR_IS_EMPTY(&prefix));
			if (_5$$7) {
				_5$$7 = !(zephir_start_with(&key, &prefix, NULL));
			}
			if (_5$$7) {
				zephir_array_unset(&keys, &idx, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &keys, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
			zephir_check_call_status();
				_6$$9 = !(ZEPHIR_IS_EMPTY(&prefix));
				if (_6$$9) {
					_6$$9 = !(zephir_start_with(&key, &prefix, NULL));
				}
				if (_6$$9) {
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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, exists) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *lifetime_param = NULL, __$null, lastKey, memcache, value, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$4);

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


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &_0$$4, keyName);
	}
	if (zephir_is_true(&lastKey)) {
		ZEPHIR_OBS_VAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		if (Z_TYPE_P(&memcache) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&memcache);
			zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(&value, &memcache, "get", NULL, 0, &lastKey);
		zephir_check_call_status();
		if (!(zephir_is_true(&value))) {
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
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, memcache, prefix, lastKey, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0);

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


	ZEPHIR_OBS_VAR(&memcache);
	zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(&memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &prefix, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	ZVAL_LONG(&_0, value);
	ZEPHIR_RETURN_CALL_METHOD(&memcache, "increment", NULL, 0, &lastKey, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrement of $keyName by given $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, memcache, prefix, lastKey, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0);

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


	ZEPHIR_OBS_VAR(&memcache);
	zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(&memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(&prefix);
		zephir_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &prefix, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	}
	ZVAL_LONG(&_0, value);
	ZEPHIR_RETURN_CALL_METHOD(&memcache, "decrement", NULL, 0, &lastKey, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 *
 * Memcached does not support flush() per default. If you require flush() support, set $config["statsKey"].
 * All modified keys are stored in "statsKey". Note: statsKey has a negative performance impact.
 *
 *<code>
 * $cache = new \Phalcon\Cache\Backend\Libmemcached(
 *     $frontCache,
 *     [
 *         "statsKey" => "_PHCM",
 *     ]
 * );
 *
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // 'my-data' and all other used keys are deleted
 * $cache->flush();
 *</code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, flush) {

	zend_string *_4;
	zend_ulong _3;
	zval memcache, options, keys, specialKey, key, _0, *_1, _2;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&memcache);
	zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(&memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 476);
		return;
	}
	if (ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/libmemcached.zep", 480);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, &memcache, "get", NULL, 0, &specialKey);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&keys) != IS_ARRAY)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(&keys, 0, "phalcon/cache/backend/libmemcached.zep", 495);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&_0);
			ZVAL_COPY(&_0, _1);
			ZEPHIR_CALL_METHOD(NULL, &memcache, "delete", &_5, 0, &key);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &keys, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_0, &keys, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &memcache, "delete", &_6, 0, &key);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(NULL, &memcache, "delete", NULL, 0, &specialKey);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

