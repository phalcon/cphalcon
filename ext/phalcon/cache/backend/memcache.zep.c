
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
#include "kernel/hash.h"
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
 * $frontCache = new FrontData([
 *     'lifetime' => 172800
 * ]);
 *
 * // Create the Cache setting memcached connection options
 * $cache = new Memcache($frontCache, [
 *     'host' => 'localhost',
 *     'port' => 11211,
 *     'persistent' => false
 * ]);
 *
 * // Cache arbitrary data
 * $cache->save('my-data', [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get('my-data');
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
	zephir_fcall_cache_entry *_3 = NULL;
	zval *frontend, frontend_sub, *options = NULL, options_sub, __$false, __$null, _0$$4, _1$$5, _2$$7;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);

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
		ZVAL_LONG(&_1$$5, 11211);
		zephir_array_update_string(options, SL("port"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("persistent")))) {
		zephir_array_update_string(options, SL("persistent"), &__$false, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("statsKey")))) {
		ZEPHIR_INIT_VAR(&_2$$7);
		ZVAL_STRING(&_2$$7, "");
		zephir_array_update_string(options, SL("statsKey"), &_2$$7, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_memcache_ce, this_ptr, "__construct", &_3, 113, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect) {

	zend_bool _0, _1;
	zval options, memcache, persistent, success, host, port;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&memcache);
	object_init_ex(&memcache, zephir_get_internal_ce(SL("memcache")));
	if (zephir_has_constructor(&memcache TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &memcache, "__construct", NULL, 0);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 105);
		return;
	}
	if (zephir_is_true(&persistent)) {
		ZEPHIR_CALL_METHOD(&success, &memcache, "pconnect", NULL, 0, &host, &port);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, &memcache, "connect", NULL, 0, &host, &port);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server", "phalcon/cache/backend/memcache.zep", 115);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_memcache"), &memcache);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add servers to memcache pool
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, addServers) {

	zend_bool persistent;
	int port, ZEPHIR_LAST_CALL_STATUS;
	zval *host_param = NULL, *port_param = NULL, *persistent_param = NULL, memcache, success, _0, _1;
	zval host;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &host_param, &port_param, &persistent_param);

	if (unlikely(Z_TYPE_P(host_param) != IS_STRING && Z_TYPE_P(host_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'host' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(host_param) == IS_STRING)) {
		zephir_get_strval(&host, host_param);
	} else {
		ZEPHIR_INIT_VAR(&host);
		ZVAL_EMPTY_STRING(&host);
	}
	port = zephir_get_intval(port_param);
	if (!persistent_param) {
		persistent = 0;
	} else {
		persistent = zephir_get_boolval(persistent_param);
	}


	ZEPHIR_OBS_VAR(&memcache);
	zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	if (Z_TYPE_P(&memcache) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_connect", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&memcache);
		zephir_read_property(&memcache, this_ptr, SL("_memcache"), PH_NOISY_CC);
	}
	ZVAL_LONG(&_0, port);
	if (persistent) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(&success, &memcache, "addserver", NULL, 0, &host, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_memcache"), &memcache);
	RETURN_CCTOR(success);

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
	zval *keyName, keyName_sub, *lifetime = NULL, lifetime_sub, __$null, memcache, prefixedKey, cachedContent, retrieve, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&retrieve);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

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
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZEPHIR_CALL_METHOD(&cachedContent, &memcache, "get", NULL, 0, &prefixedKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(&cachedContent)) {
		RETURN_CCTOR(cachedContent);
	}
	zephir_read_property(&_1, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&retrieve, &_1, "afterretrieve", NULL, 0, &cachedContent);
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
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastKey, frontend, memcache, cachedContent, preparedContent, tmp, ttl, success, options, specialKey, keys, isBuffering, _0$$4, _1$$13, _2$$14;
	ZEPHIR_INIT_THIS();

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
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$13);
	ZVAL_UNDEF(&_2$$14);

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
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/memcache.zep", 193);
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
	ZEPHIR_CALL_METHOD(&preparedContent, &frontend, "beforestore", NULL, 0, &cachedContent);
	zephir_check_call_status();
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
	if (zephir_is_numeric(&cachedContent)) {
		ZVAL_LONG(&_1$$13, 0);
		ZEPHIR_CALL_METHOD(&success, &memcache, "set", NULL, 0, &lastKey, &cachedContent, &_1$$13, &ttl);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_2$$14, 0);
		ZEPHIR_CALL_METHOD(&success, &memcache, "set", NULL, 0, &lastKey, &preparedContent, &_2$$14, &ttl);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in memcached", "phalcon/cache/backend/memcache.zep", 240);
		return;
	}
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&specialKey);
	if (!(zephir_array_isset_string_fetch(&specialKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 246);
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
			zephir_array_update_zval(&keys, &lastKey, &ttl, PH_COPY | PH_SEPARATE);
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
	RETURN_CCTOR(success);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, memcache, prefixedKey, options, keys, specialKey, ret, _0;
	ZEPHIR_INIT_THIS();

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 299);
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
	RETURN_CCTOR(ret);

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys) {

	zend_bool _4$$7;
	zend_string *_3$$6;
	zend_ulong _2$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, prefix_sub, __$null, memcache, options, keys, specialKey, key, realKey, _0$$6, *_1$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&prefix_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&realKey);
	ZVAL_UNDEF(&_0$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = &prefix_sub;
		prefix = &__$null;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 338);
		return;
	}
	if (ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/memcache.zep", 342);
		return;
	}
	ZEPHIR_INIT_VAR(&realKey);
	array_init(&realKey);
	ZEPHIR_CALL_METHOD(&keys, &memcache, "get", NULL, 0, &specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$6);
		zephir_is_iterable(&keys, 0, "phalcon/cache/backend/memcache.zep", 356);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _2$$6, _3$$6, _1$$6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3$$6 != NULL) { 
				ZVAL_STR_COPY(&key, _3$$6);
			} else {
				ZVAL_LONG(&key, _2$$6);
			}
			ZEPHIR_INIT_NVAR(&_0$$6);
			ZVAL_COPY(&_0$$6, _1$$6);
			_4$$7 = !zephir_is_true(prefix);
			if (!(_4$$7)) {
				_4$$7 = zephir_start_with(&key, prefix, NULL);
			}
			if (_4$$7) {
				zephir_array_append(&realKey, &key, PH_SEPARATE, "phalcon/cache/backend/memcache.zep", 353);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_0$$6);
		ZEPHIR_INIT_NVAR(&key);
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
	zval *keyName = NULL, keyName_sub, *lifetime = NULL, lifetime_sub, __$null, lastKey, memcache, prefix, _0$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&memcache);
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
		ZEPHIR_CONCAT_VV(&lastKey, &prefix, keyName);
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
		ZEPHIR_CALL_METHOD(&_0$$5, &memcache, "get", NULL, 0, &lastKey);
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
 * @param  string keyName
 * @param  long value
 * @return long
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, increment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value = NULL, value_sub, __$null, memcache, prefix, lastKey;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&memcache);
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
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(&memcache, "increment", NULL, 0, &lastKey, value);
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
	zval *keyName = NULL, keyName_sub, *value = NULL, value_sub, __$null, memcache, prefix, lastKey;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&memcache);
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
	if (!(zephir_is_true(value))) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_LONG(value, 1);
	}
	ZEPHIR_RETURN_CALL_METHOD(&memcache, "decrement", NULL, 0, &lastKey, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, flush) {

	zend_string *_3$$6;
	zend_ulong _2$$6;
	zval memcache, options, keys, specialKey, key, _0$$6, *_1$$6;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&memcache);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&specialKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0$$6);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options", "phalcon/cache/backend/memcache.zep", 479);
		return;
	}
	if (ZEPHIR_IS_STRING(&specialKey, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!", "phalcon/cache/backend/memcache.zep", 483);
		return;
	}
	ZEPHIR_CALL_METHOD(&keys, &memcache, "get", NULL, 0, &specialKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$6);
		zephir_is_iterable(&keys, 0, "phalcon/cache/backend/memcache.zep", 494);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _2$$6, _3$$6, _1$$6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3$$6 != NULL) { 
				ZVAL_STR_COPY(&key, _3$$6);
			} else {
				ZVAL_LONG(&key, _2$$6);
			}
			ZEPHIR_INIT_NVAR(&_0$$6);
			ZVAL_COPY(&_0$$6, _1$$6);
			ZEPHIR_CALL_METHOD(NULL, &memcache, "delete", &_4, 0, &key);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_0$$6);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_CALL_METHOD(NULL, &memcache, "set", NULL, 0, &specialKey, &keys);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

