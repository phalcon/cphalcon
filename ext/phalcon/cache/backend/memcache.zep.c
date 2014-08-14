
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


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
/**
 * Phalcon\Cache\Backend\Memcache
 *
 * Allows to cache output fragments, PHP data or raw data to a memcache backend
 *
 * This adapter uses the special memcached key "_PHCM" to store all the keys internally used by the adapter
 *
 *<code>
 *
 * // Cache data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting memcached connection options
 * $cache = new \Phalcon\Cache\Backend\Memcache($frontCache, array(
 *		'host' => 'localhost',
 *		'port' => 11211,
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
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memcache) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memcache, phalcon, cache_backend_memcache, phalcon_cache_backend_ce, phalcon_cache_backend_memcache_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_memcache_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Memcache constructor
 *
 * @param	Phalcon\Cache\FrontendInterface frontend
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *frontend, *options = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (!(zephir_instance_of_ev(frontend, phalcon_cache_frontendinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'frontend' must be an instance of 'Phalcon\\Cache\\FrontendInterface'", "", 0);
		return;
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
		ZVAL_LONG(_0, 11211);
		zephir_array_update_string(&options, SL("port"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		zephir_array_update_string(&options, SL("persistent"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "_PHCM", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_memcache_ce, this_ptr, "__construct", &_1, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect) {

	zend_bool _1, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zval *options, *memcache, *persistent, *success = NULL, *host, *port;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(memcache);
	_0 = zend_fetch_class(SL("Memcache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(memcache, _0);
	if (zephir_has_constructor(memcache TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, memcache, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(host);
	_1 = !zephir_array_isset_string_fetch(&host, options, SS("host"), 0 TSRMLS_CC);
	if (!(_1)) {
		ZEPHIR_OBS_VAR(port);
		_1 = !zephir_array_isset_string_fetch(&port, options, SS("port"), 0 TSRMLS_CC);
	}
	_2 = _1;
	if (!(_2)) {
		ZEPHIR_OBS_VAR(persistent);
		_2 = !zephir_array_isset_string_fetch(&persistent, options, SS("persistent"), 0 TSRMLS_CC);
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 100);
		return;
	}
	if (zephir_is_true(persistent)) {
		ZEPHIR_CALL_METHOD(&success, memcache, "pconnect", NULL, host, port);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, memcache, "connect", NULL, host, port);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server", "phalcon/cache/backend/memcache.zep", 110);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_memcache"), memcache TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 *
 * @param int|string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *lifetime = NULL, *memcache = NULL, *prefixedKey, *cachedContent = NULL, *retrieve = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&cachedContent, memcache, "get", NULL, prefixedKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&retrieve, _1, "afterretrieve", NULL, cachedContent);
	zephir_check_call_status();
	RETURN_CCTOR(retrieve);

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastKey = NULL, *frontend, *memcache = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp, *ttl = NULL, *success = NULL, *options, *specialKey, *keys = NULL, *isBuffering = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer) {
		stopBuffer = ZEPHIR_GLOBAL(global_true);
	}


	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/memcache.zep", 169);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent",  NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, cachedContent);
	zephir_check_call_status();
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_VAR(tmp);
		zephir_read_property_this(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime",  NULL);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	if (zephir_is_numeric(cachedContent)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_CALL_METHOD(&success, memcache, "set", NULL, lastKey, cachedContent, _1, ttl);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_CALL_METHOD(&success, memcache, "set", NULL, lastKey, preparedContent, _1, ttl);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in memcached", "phalcon/cache/backend/memcache.zep", 216);
		return;
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 222);
		return;
	}
	ZEPHIR_OBS_VAR(specialKey);
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY, "phalcon/cache/backend/memcache.zep", 224 TSRMLS_CC);
	if (Z_TYPE_P(specialKey) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, specialKey);
		zephir_check_call_status();
		if (Z_TYPE_P(keys) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(keys);
			array_init(keys);
		}
		if (!(zephir_array_isset(keys, lastKey))) {
			zephir_array_update_zval(&keys, lastKey, &ttl, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, memcache, "set", NULL, specialKey, keys);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering",  NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(stopBuffer)) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE(isBuffering)) {
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *memcache = NULL, *prefixedKey, *options, *keys = NULL, *specialKey, *ret = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 274);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_array_unset(&keys, prefixedKey, PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, memcache, "set", NULL, specialKey, keys);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&ret, memcache, "delete", NULL, prefixedKey);
	zephir_check_call_status();
	RETURN_CCTOR(ret);

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys) {

	zend_bool _3;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *memcache = NULL, *options, *keys = NULL, *specialKey, *key = NULL, *value = NULL, *realKey, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 311);
		return;
	}
	ZEPHIR_INIT_VAR(realKey);
	array_init(realKey);
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1, &_0, 0, 0, "phalcon/cache/backend/memcache.zep", 325);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			_3 = !zephir_is_true(prefix);
			if (!(_3)) {
				_3 = zephir_start_with(key, prefix, NULL);
			}
			if (_3) {
				zephir_array_append(&realKey, key, PH_SEPARATE, "phalcon/cache/backend/memcache.zep", 322);
			}
		}
	}
	RETURN_CCTOR(realKey);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param   long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *memcache = NULL, *prefix, *_0 = NULL;

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
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_OBS_VAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		if (Z_TYPE_P(memcache) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(memcache);
			zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(&_0, memcache, "get", NULL, lastKey);
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, increment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *memcache = NULL, *prefix, *lastKey = NULL;

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


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL);
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
		zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(memcache, "increment", NULL, lastKey, value);
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, decrement) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *memcache = NULL, *prefix, *lastKey = NULL;

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


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL);
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
		zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(memcache, "decrement", NULL, lastKey, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, flush) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *memcache = NULL, *options, *keys = NULL, *specialKey, *key = NULL, **_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 450);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1, &_0, 0, 0, "phalcon/cache/backend/memcache.zep", 461);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(key, _2);
			ZEPHIR_CALL_METHOD(NULL, memcache, "delete", NULL, key);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, memcache, "set", NULL, specialKey, keys);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

