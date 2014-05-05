
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
#include "kernel/hash.h"
#include "kernel/concat.h"
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
 * Phalcon\Cache\Backend\Libmemcached
 *
 * Allows to cache output fragments, PHP data or raw data to a libmemcached backend
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
 * $cache = new \Phalcon\Cache\Backend\Libmemcached($frontCache, array(
 *     "servers" => array(
 *         array('host' => 'localhost',
 *               'port' => 11211,
 *               'weight' => 1),
 *     ),
 *     "client" => array(
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
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Libmemcached) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Libmemcached, phalcon, cache_backend_libmemcached, phalcon_cache_backend_ce, phalcon_cache_backend_libmemcached_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_libmemcached_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_libmemcached_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Memcache constructor
 *
 * @param	Phalcon\Cache\FrontendInterface frontend
 * @param	array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0;
	zval *frontend, *options = NULL, *servers, *_1;

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
	if (!(zephir_array_isset_string(options, SS("servers")))) {
		ZEPHIR_INIT_VAR(servers);
		array_init_size(servers, 2);
		ZEPHIR_INIT_VAR(_0);
		array_init_size(_0, 5);
		add_assoc_stringl_ex(_0, SS("host"), SL("127.0.0.1"), 1);
		add_assoc_long_ex(_0, SS("port"), 11211);
		add_assoc_long_ex(_0, SS("weigth"), 1);
		zephir_array_update_long(&servers, 0, &_0, PH_COPY, "phalcon/cache/backend/libmemcached.zep", 77);
		zephir_array_update_string(&options, SL("servers"), &servers, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "_PHCM", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_1, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_libmemcached_ce, this_ptr, "__construct", &_2, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, _connect) {

	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zval *options, *memcache, *client, *servers, *option = NULL, *res = NULL, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(memcache);
	_0 = zend_fetch_class(SL("Memcached"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(memcache, _0);
	ZEPHIR_CALL_METHOD(NULL, memcache, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(servers);
	if (!(zephir_array_isset_string_fetch(&servers, options, SS("servers"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Servers must be an array", "phalcon/cache/backend/libmemcached.zep", 100);
		return;
	}
	if (Z_TYPE_P(servers) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Servers must be an array", "phalcon/cache/backend/libmemcached.zep", 104);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, memcache, "addservers", NULL, servers);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server", "phalcon/cache/backend/libmemcached.zep", 108);
		return;
	}
	ZEPHIR_OBS_VAR(client);
	zephir_array_fetch_string(&client, options, SL("client"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(client) == IS_ARRAY) {
		zephir_is_iterable(client, &_3, &_2, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(option, _4);
			if (Z_TYPE_P(option) == IS_STRING) {
				ZEPHIR_CALL_FUNCTION(&res, "constant", &_5, option);
				zephir_check_call_status();
				if (zephir_is_true(res)) {
					ZEPHIR_CALL_METHOD(NULL, memcache, "setoption", &_6, res);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CALL_METHOD(NULL, memcache, "setoption", &_7, option);
				zephir_check_call_status();
			}
		}
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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *lifetime = NULL, *memcache = NULL, *prefixedKey, *cachedContent = NULL, *_0, *_1;

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
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "afterretrieve", NULL, cachedContent);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastKey = NULL, *frontend, *memcache = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp, *tt1 = NULL, *success = NULL, *options, *specialKey, *keys = NULL, *isBuffering = NULL, *_0;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/libmemcached.zep", 180);
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
	if (!(zephir_is_true(content))) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent",  NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, cachedContent);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(lifetime))) {
		ZEPHIR_OBS_VAR(tmp);
		zephir_read_property_this(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_CALL_METHOD(&tt1, frontend, "getlifetime",  NULL);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(tt1, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(tt1, lifetime);
	}
	if (zephir_is_numeric(cachedContent)) {
		ZEPHIR_CALL_METHOD(&success, memcache, "set", NULL, lastKey, cachedContent, tt1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, memcache, "set", NULL, lastKey, preparedContent, tt1);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in memcached", "phalcon/cache/backend/libmemcached.zep", 226);
		return;
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 232);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		ZEPHIR_INIT_BNVAR(keys);
		array_init(keys);
	}
	if (!(zephir_array_isset(keys, lastKey))) {
		zephir_array_update_zval(&keys, lastKey, &tt1, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, memcache, "set", NULL, specialKey, keys);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(stopBuffer))) {
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
 * Increment of a given key, by number $value
 *
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, increment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *memcache = NULL, *prefixedKey, *cachedContent = NULL, *_0;

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


	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
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
	ZEPHIR_CALL_METHOD(&cachedContent, memcache, "increment", NULL, prefixedKey, value);
	zephir_check_call_status();
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(cachedContent);

}

/**
 * Decrement of a given key, by number $value
 *
 * @param  string keyName
 * @param  long value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, decrement) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *memcache = NULL, *prefixedKey, *cachedContent = NULL, *_0;

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


	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
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
	ZEPHIR_CALL_METHOD(&cachedContent, memcache, "decrement", NULL, prefixedKey, value);
	zephir_check_call_status();
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(cachedContent);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *memcache = NULL, *prefixedKey, *options, *keys = NULL, *specialKey, *_0;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 345);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_array_unset(&keys, prefixedKey, PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, memcache, "set", NULL, specialKey, keys);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, memcache, "delete", NULL, prefixedKey);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, queryKeys) {

	zend_bool _3;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *memcache = NULL, *options, *keys = NULL, *specialKey, *key = NULL, **_2;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 380);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1, &_0, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(key, _2);
			_3 = !zephir_is_true(prefix);
			if (!(_3)) {
				_3 = zephir_start_with(key, prefix, 0);
			}
			if (_3) {
				RETURN_CCTOR(key);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param   long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *memcache = NULL, *value = NULL, *_0;

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
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0, keyName);
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
		ZEPHIR_CALL_METHOD(&value, memcache, "get", NULL, lastKey);
		zephir_check_call_status();
		if (!(zephir_is_true(value))) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Immediately invalidates all existing items.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, flush) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 448);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		zephir_is_iterable(keys, &_1, &_0, 0, 0);
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

