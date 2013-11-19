
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


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * $frontCache = new Phalcon\Cache\Frontend\Data(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting memcached connection options
 * $cache = new Phalcon\Cache\Backend\Memcache($frontCache, array(
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

	zval *frontend, *options = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(options);


	if ((Z_TYPE_P(options) != IS_ARRAY)) {
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
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 0);
		zephir_array_update_string(&options, SL("persistent"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "_PHCM", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_0, PH_COPY | PH_SEPARATE);
	}
	zephir_call_parent_p2_noret(this_ptr, phalcon_cache_backend_memcache_ce, "__construct", frontend, options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect) {

	zend_class_entry *_0;
	zval *options, *memcache, *persistent, *success, *host, *port;

	ZEPHIR_MM_GROW();

	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(memcache);
	_0 = zend_fetch_class(SL("Memcache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(memcache, _0);
	if (((!zephir_array_isset_string(options, SS("host")) || !zephir_array_isset_string(options, SS("port"))) || !zephir_array_isset_string(options, SS("persistent")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	zephir_array_fetch_string(&host, options, SL("host"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&port, options, SL("port"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&persistent, options, SL("persistent"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(success);
	if (zephir_is_true(persistent)) {
		zephir_call_method_p2(success, memcache, "pconnect", host, port);
	} else {
		zephir_call_method_p2(success, memcache, "connect", host, port);
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server");
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

	zval *keyName, *lifetime = NULL, *memcache = NULL, *frontend, *prefix, *prefixedKey, *cachedContent;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if ((Z_TYPE_P(memcache) != IS_OBJECT)) {
		zephir_call_method_noret(this_ptr, "_connect");
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_INIT_VAR(cachedContent);
	zephir_call_method_p1(cachedContent, memcache, "get", prefixedKey);
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	}
	zephir_call_method_p1_noret(frontend, "afterretrieve", cachedContent);
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, save) {

	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastKey, *prefix, *frontend, *memcache = NULL, *cachedContent = NULL, *preparedContent, *tmp, *tt1 = NULL, *success, *options, *specialKey, *keys, *isBuffering;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer);

	if (!keyName || Z_TYPE_P(keyName) == IS_NULL) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer || Z_TYPE_P(stopBuffer) == IS_NULL) {
		stopBuffer = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if (!(zephir_is_true(keyName))) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if ((Z_TYPE_P(memcache) != IS_OBJECT)) {
		zephir_call_method_noret(this_ptr, "_connect");
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	if (!(zephir_is_true(content))) {
		ZEPHIR_INIT_VAR(cachedContent);
		zephir_call_method(cachedContent, frontend, "getcontent");
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_INIT_VAR(preparedContent);
		zephir_call_method_p1(preparedContent, frontend, "beforestore", cachedContent);
	}
	if (!(zephir_is_true(lifetime))) {
		tmp = zephir_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_INIT_VAR(tt1);
			zephir_call_method(tt1, frontend, "getlifetime");
		} else {
			ZEPHIR_CPY_WRT(tt1, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(tt1, lifetime);
	}
	ZEPHIR_INIT_VAR(success);
	if (zephir_is_numeric(cachedContent)) {
		zephir_call_method_p3(success, memcache, "set", lastKey, cachedContent, tt1);
	} else {
		zephir_call_method_p3(success, memcache, "set", lastKey, preparedContent, tt1);
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Failed storing data in memcached");
		return;
	}
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(keys);
	zephir_call_method_p1(keys, memcache, "get", specialKey);
	if ((Z_TYPE_P(keys) != IS_ARRAY)) {
		ZEPHIR_INIT_BNVAR(keys);
		array_init(keys);
	}
	if (!(zephir_array_isset(keys, lastKey))) {
		zephir_array_update_zval(&keys, lastKey, &tt1, PH_COPY | PH_SEPARATE);
		zephir_call_method_p2_noret(memcache, "set", specialKey, keys);
	}
	ZEPHIR_INIT_VAR(isBuffering);
	zephir_call_method(isBuffering, frontend, "isbuffering");
	if (!(zephir_is_true(stopBuffer))) {
		zephir_call_method_noret(frontend, "stop");
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

	zval *keyName, *memcache = NULL, *prefix, *prefixedKey, *options, *keys, *specialKey;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if ((Z_TYPE_P(memcache) != IS_OBJECT)) {
		zephir_call_method_noret(this_ptr, "_connect");
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(keys);
	zephir_call_method_p1(keys, memcache, "get", specialKey);
	if ((Z_TYPE_P(keys) == IS_ARRAY)) {
		zephir_call_method_p2_noret(memcache, "set", specialKey, keys);
	}
	zephir_call_method_p1_noret(memcache, "delete", prefixedKey);
	ZEPHIR_MM_RESTORE();

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys) {

	HashTable *_1;
	HashPosition _0;
	zval *prefix = NULL, *memcache = NULL, *options, *keys, *specialKey, *key = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix || Z_TYPE_P(prefix) == IS_NULL) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(memcache);
	zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if ((Z_TYPE_P(memcache) != IS_OBJECT)) {
		zephir_call_method_noret(this_ptr, "_connect");
		ZEPHIR_OBS_NVAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(keys);
	zephir_call_method_p1(keys, memcache, "get", specialKey);
	if ((Z_TYPE_P(keys) == IS_ARRAY)) {
		zephir_is_iterable(keys, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(key, _2);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_func_p2(_3, "start_with", key, prefix);
			if ((!zephir_is_true(prefix) || zephir_is_true(_3))) {
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, exists) {

	zval *keyName = NULL, *lifetime = NULL, *lastKey, *memcache = NULL, *value, *prefix;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName || Z_TYPE_P(keyName) == IS_NULL) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if (!(zephir_is_true(keyName))) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VV(lastKey, prefix, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_OBS_VAR(memcache);
		zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		if ((Z_TYPE_P(memcache) != IS_OBJECT)) {
			zephir_call_method_noret(this_ptr, "_connect");
			ZEPHIR_OBS_NVAR(memcache);
			zephir_read_property_this(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
		}
		ZEPHIR_INIT_VAR(value);
		zephir_call_method_p1(value, memcache, "get", lastKey);
		if (!(zephir_is_true(value))) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

