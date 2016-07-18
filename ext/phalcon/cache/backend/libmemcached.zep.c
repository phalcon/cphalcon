
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
#include "kernel/hash.h"
#include "kernel/string.h"


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
 * $frontCache = new FrontData([
 *     'lifetime' => 172800
 * ]);
 *
 * // Create the Cache setting memcached connection options
 * $cache = new Libmemcached($frontCache, [
 *     'servers' => [
 *         [
 *             'host' => 'localhost',
 *             'port' => 11211,
 *             'weight' => 1
 *         ],
 *     ],
 *     'client' => [
 *         \Memcached::OPT_HASH => Memcached::HASH_MD5,
 *         \Memcached::OPT_PREFIX_KEY => 'prefix.',
 *     ]
 * ]);
 *
 * // Cache arbitrary data
 * $cache->save('my-data', [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get('my-data');
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

	zval *_0$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *frontend, *options = NULL, *servers = NULL, *_1$$5;

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
	if (!(zephir_array_isset_string(options, SS("servers")))) {
		ZEPHIR_INIT_VAR(servers);
		zephir_create_array(servers, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$4);
		zephir_create_array(_0$$4, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_0$$4, SS("host"), SL("127.0.0.1"), 1);
		add_assoc_long_ex(_0$$4, SS("port"), 11211);
		add_assoc_long_ex(_0$$4, SS("weight"), 1);
		zephir_array_update_long(&servers, 0, &_0$$4, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
		zephir_array_update_string(&options, SL("servers"), &servers, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_STRING(_1$$5, "", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_libmemcached_ce, this_ptr, "__construct", &_2, 113, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, _connect) {

	zval *options = NULL, *memcache = NULL, *client = NULL, *servers = NULL, *persistentId = NULL, *_0 = NULL, *_1$$4 = NULL, *_2$$4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(persistentId);
	if (!(zephir_array_isset_string_fetch(&persistentId, options, SS("persistent_id"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(persistentId);
		ZVAL_STRING(persistentId, "phalcon_cache", 1);
	}
	ZEPHIR_INIT_VAR(memcache);
	object_init_ex(memcache, zephir_get_internal_ce(SS("memcached") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, memcache, "__construct", NULL, 0, persistentId);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, memcache, "getserverlist", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_OBS_VAR(servers);
		if (!(zephir_array_isset_string_fetch(&servers, options, SS("servers"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Servers must be an array", "phalcon/cache/backend/libmemcached.zep", 116);
			return;
		}
		if (Z_TYPE_P(servers) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Servers must be an array", "phalcon/cache/backend/libmemcached.zep", 120);
			return;
		}
		ZEPHIR_OBS_VAR(client);
		if (!(zephir_array_isset_string_fetch(&client, options, SS("client"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(client);
			array_init(client);
		}
		if (Z_TYPE_P(client) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Client options must be instance of array", "phalcon/cache/backend/libmemcached.zep", 128);
			return;
		}
		ZEPHIR_CALL_METHOD(&_1$$4, memcache, "setoptions", NULL, 0, client);
		zephir_check_call_status();
		if (!(zephir_is_true(_1$$4))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cannot set to Memcached options", "phalcon/cache/backend/libmemcached.zep", 132);
			return;
		}
		ZEPHIR_CALL_METHOD(&_2$$4, memcache, "addservers", NULL, 0, servers);
		zephir_check_call_status();
		if (!(zephir_is_true(_2$$4))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server", "phalcon/cache/backend/libmemcached.zep", 136);
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_memcache"), memcache TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, get) {

	int lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, *memcache = NULL, *prefixedKey = NULL, *cachedContent = NULL, *_0, *_1$$6;
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
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&cachedContent, memcache, "get", NULL, 0, prefixedKey);
	zephir_check_call_status();
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	} else {
		_1$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_1$$6, "afterretrieve", NULL, 0, cachedContent);
		zephir_check_call_status();
		RETURN_MM();
	}

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
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend = NULL, *memcache = NULL, *cachedContent = NULL, *preparedContent = NULL, *tmp = NULL, *tt1 = NULL, *success = NULL, *options = NULL, *specialKey = NULL, *keys = NULL, *isBuffering = NULL, *_0$$4, *_1$$16, *_2$$16 = NULL, *_3$$16;

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
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/libmemcached.zep", 191);
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
		ZEPHIR_CALL_METHOD(&success, memcache, "set", NULL, 0, lastKey, cachedContent, tt1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, memcache, "set", NULL, 0, lastKey, preparedContent, tt1);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_INIT_VAR(_1$$16);
		object_init_ex(_1$$16, phalcon_cache_exception_ce);
		ZEPHIR_CALL_METHOD(&_2$$16, memcache, "getresultcode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$16);
		ZEPHIR_CONCAT_SV(_3$$16, "Failed storing data in memcached, error code: ", _2$$16);
		ZEPHIR_CALL_METHOD(NULL, _1$$16, "__construct", NULL, 9, _3$$16);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$16, "phalcon/cache/backend/libmemcached.zep", 237 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, options, SS("statsKey"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 243);
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
			zephir_array_update_zval(&keys, lastKey, &tt1, PH_COPY | PH_SEPARATE);
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
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 296);
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
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, queryKeys) {

	zend_bool _4$$7;
	HashTable *_2$$6;
	HashPosition _1$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *memcache = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *key = NULL, *_0$$6, **_3$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 334);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/libmemcached.zep", 338);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$6);
		zephir_array_keys(_0$$6, keys TSRMLS_CC);
		ZEPHIR_CPY_WRT(keys, _0$$6);
		zephir_is_iterable(keys, &_2$$6, &_1$$6, 1, 0, "phalcon/cache/backend/libmemcached.zep", 352);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$6, (void**) &_3$$6, &_1$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$6, &_1$$6)
		) {
			ZEPHIR_GET_HVALUE(key, _3$$6);
			_4$$7 = zephir_is_true(prefix);
			if (_4$$7) {
				_4$$7 = !(zephir_start_with(key, prefix, NULL));
			}
			if (_4$$7) {
				zephir_array_unset(&keys, key, PH_SEPARATE);
			}
		}
		zend_hash_destroy(_2$$6);
		FREE_HASHTABLE(_2$$6);
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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *memcache = NULL, *value = NULL, *_0$$4;

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
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0$$4, keyName);
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
		ZEPHIR_CALL_METHOD(&value, memcache, "get", NULL, 0, lastKey);
		zephir_check_call_status();
		if (!(zephir_is_true(value))) {
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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, increment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *memcache = NULL, *prefix = NULL, *lastKey = NULL;

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
		zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(memcache, "increment", NULL, 0, lastKey, value);
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
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, decrement) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value = NULL, *memcache = NULL, *prefix = NULL, *lastKey = NULL;

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
		zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	}
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(memcache, "decrement", NULL, 0, lastKey, value);
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
 * $cache = new \Phalcon\Cache\Backend\Libmemcached($frontCache, ["statsKey" => "_PHCM"]);
 * $cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 * //'my-data' and all other used keys are deleted
 * $cache->flush();
 *</code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, flush) {

	HashTable *_2$$6;
	HashPosition _1$$6;
	zval *memcache = NULL, *options = NULL, *keys = NULL, *specialKey = NULL, *key = NULL, *_0$$6, **_3$$6;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/libmemcached.zep", 484);
		return;
	}
	if (ZEPHIR_IS_STRING(specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/libmemcached.zep", 488);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, memcache, "get", NULL, 0, specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$6);
		zephir_array_keys(_0$$6, keys TSRMLS_CC);
		zephir_is_iterable(_0$$6, &_2$$6, &_1$$6, 0, 0, "phalcon/cache/backend/libmemcached.zep", 499);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$6, (void**) &_3$$6, &_1$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$6, &_1$$6)
		) {
			ZEPHIR_GET_HVALUE(key, _3$$6);
			ZEPHIR_CALL_METHOD(NULL, memcache, "delete", &_4, 0, key);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, memcache, "set", NULL, 0, specialKey, keys);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

