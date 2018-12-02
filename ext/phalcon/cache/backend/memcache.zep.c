
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Cache\Backend\Memcache
 *
 * Allows to cache output fragments, PHP data or raw data to a memcache backend
 *
 * This adapter uses the special memcached key "_PHCM" to store all the keys internally used by the adapter
 *
 *<code>
 * use Phalcon\Cache\Backend\Memcache;
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
 * $cache = new Memcache(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 11211,
 *         "persistent" => false,
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
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memcache) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memcache, phalcon, cache_backend_memcache, phalcon_cache_backend_ce, phalcon_cache_backend_memcache_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Memcache constructor
 *
 * @param	Phalcon\Cache\FrontendInterface frontend
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *frontend, *options = NULL, *_0$$4, *_1$$5, *_2$$7;

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
		ZVAL_LONG(_1$$5, 11211);
		zephir_array_update_string(&options, SL("port"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		zephir_array_update_string(&options, SL("persistent"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_2$$7);
		ZVAL_STRING(_2$$7, "", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_2$$7, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_memcache_ce, getThis(), "__construct", &_3, 124, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect) {

	zend_bool _0, _1;
	zval *options = NULL, *memcache = NULL, *persistent = NULL, *success = NULL, *host = NULL, *port = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(memcache);
	object_init_ex(memcache, zephir_get_internal_ce(SS("memcache") TSRMLS_CC));
	if (zephir_has_constructor(memcache TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, memcache, "__construct", NULL, 0);
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
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 109);
		return;
	}
	if (zephir_is_true(persistent)) {
		ZEPHIR_CALL_METHOD(&success, memcache, "pconnect", NULL, 0, host, port);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, memcache, "connect", NULL, 0, host, port);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server", "phalcon/cache/backend/memcache.zep", 119);
		return;
	}
	zephir_update_property_this(getThis(), SL("_memcache"), memcache TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add servers to memcache pool
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, addServers) {

	zend_bool persistent;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval *host_param = NULL, *port_param = NULL, *persistent_param = NULL, *memcache = NULL, *success = NULL, *_0, *_1;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &host_param, &port_param, &persistent_param);

	if (UNEXPECTED(Z_TYPE_P(host_param) != IS_STRING && Z_TYPE_P(host_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'host' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(host_param) == IS_STRING)) {
		zephir_get_strval(host, host_param);
	} else {
		ZEPHIR_INIT_VAR(host);
		ZVAL_EMPTY_STRING(host);
	}
	port = zephir_get_intval(port_param);
	if (!persistent_param) {
		persistent = 0;
	} else {
		persistent = zephir_get_boolval(persistent_param);
	}


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, port);
	ZEPHIR_INIT_VAR(_1);
	if (persistent) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(&success, memcache, "addserver", NULL, 0, host, _0, _1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_memcache"), memcache TSRMLS_CC);
	RETURN_CCTOR(success);

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, get) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, *memcache = NULL, *prefixedKey = NULL, *cachedContent = NULL, *retrieve = NULL, *_0, *_1;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, keyName);
	zephir_update_property_this(getThis(), SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&cachedContent, memcache, "get", NULL, 0, prefixedKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&retrieve, _1, "afterretrieve", NULL, 0, cachedContent);
	zephir_check_call_status();
	RETURN_CCTOR(retrieve);

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param int lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend = NULL, *memcache = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp = NULL, *ttl = NULL, *success = NULL, *options = NULL, *specialKey = NULL, *keys = NULL, *isBuffering = NULL, *_1, *_0$$4;

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
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0$$4, keyName);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/memcache.zep", 194);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
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
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(&success, memcache, "set", NULL, 0, lastKey, preparedContent, _1, ttl);
	zephir_check_call_status();
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in memcached", "phalcon/cache/backend/memcache.zep", 241);
		return;
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 247);
		return;
	}
	if (!ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, 0, specialKey);
		zephir_check_call_status();
		if (Z_TYPE_P(keys) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(keys);
			array_init(keys);
		}
		if (!(zephir_array_isset(keys, lastKey))) {
			zephir_array_update_zval(&keys, lastKey, &ttl, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, memcache, "set", NULL, 0, specialKey, keys);
			zephir_check_call_status();
		}
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
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *memcache = NULL, *prefixedKey = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *ret = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, keyName);
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 300);
		return;
	}
	if (!ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, 0, specialKey);
		zephir_check_call_status();
		if (Z_TYPE_P(keys) == IS_ARRAY) {
			zephir_array_unset(&keys, prefixedKey, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, memcache, "set", NULL, 0, specialKey, keys);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&ret, memcache, "delete", NULL, 0, prefixedKey);
	zephir_check_call_status();
	RETURN_CCTOR(ret);

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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys) {

	zend_bool _4$$7;
	HashTable *_2;
	HashPosition _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *memcache = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *key = NULL, *idx = NULL, *_0, **_3;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 343);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/memcache.zep", 347);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, 0, specialKey);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(keys) != IS_ARRAY)) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_array_keys(_0, keys TSRMLS_CC);
	ZEPHIR_CPY_WRT(keys, _0);
	zephir_is_iterable(keys, &_2, &_1, 1, 0, "phalcon/cache/backend/memcache.zep", 365);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(idx, _2, _1);
		ZEPHIR_GET_HVALUE(key, _3);
		_4$$7 = !(ZEPHIR_IS_EMPTY(prefix));
		if (_4$$7) {
			_4$$7 = !(zephir_start_with(key, prefix, NULL));
		}
		if (_4$$7) {
			zephir_array_unset(&keys, idx, PH_SEPARATE);
		}
	}
	zend_hash_destroy(_2);
	FREE_HASHTABLE(_2);
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, exists) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey = NULL, *memcache = NULL, *prefix = NULL, *_0$$5 = NULL;

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
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_OBS_VAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		if (Z_TYPE_P(memcache) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(memcache);
			zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(&_0$$5, memcache, "get", NULL, 0, lastKey);
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
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *memcache = NULL, *prefix = NULL, *lastKey = NULL, *_0;

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


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, value);
	ZEPHIR_RETURN_CALL_METHOD(memcache, "increment", NULL, 0, lastKey, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrement of $keyName by given $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *memcache = NULL, *prefix = NULL, *lastKey = NULL, *_0;

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


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
		zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, value);
	ZEPHIR_RETURN_CALL_METHOD(memcache, "decrement", NULL, 0, lastKey, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, flush) {

	HashTable *_2;
	HashPosition _1;
	zval *memcache = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *key = NULL, *_0 = NULL, **_3;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 473);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/memcache.zep", 477);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, 0, specialKey);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(keys) != IS_ARRAY)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(keys, &_2, &_1, 0, 0, "phalcon/cache/backend/memcache.zep", 492);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(_0, _3);
		ZEPHIR_CALL_METHOD(NULL, memcache, "delete", &_4, 0, key);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, memcache, "delete", NULL, 0, specialKey);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

