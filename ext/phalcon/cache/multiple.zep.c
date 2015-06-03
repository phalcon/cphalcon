
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Phalcon\Cache\Multiple
 *
 * Allows to read to chained backend adapters writing to multiple backends
 *
 *<code>
 *   use Phalcon\Cache\Frontend\Data as DataFrontend,
 *       Phalcon\Cache\Multiple,
 *       Phalcon\Cache\Backend\Apc as ApcCache,
 *       Phalcon\Cache\Backend\Memcache as MemcacheCache,
 *       Phalcon\Cache\Backend\File as FileCache;
 *
 *   $ultraFastFrontend = new DataFrontend(array(
 *       "lifetime" => 3600
 *   ));
 *
 *   $fastFrontend = new DataFrontend(array(
 *       "lifetime" => 86400
 *   ));
 *
 *   $slowFrontend = new DataFrontend(array(
 *       "lifetime" => 604800
 *   ));
 *
 *   //Backends are registered from the fastest to the slower
 *   $cache = new Multiple(array(
 *       new ApcCache($ultraFastFrontend, array(
 *           "prefix" => 'cache',
 *       )),
 *       new MemcacheCache($fastFrontend, array(
 *           "prefix" => 'cache',
 *           "host" => "localhost",
 *           "port" => "11211"
 *       )),
 *       new FileCache($slowFrontend, array(
 *           "prefix" => 'cache',
 *           "cacheDir" => "../app/cache/"
 *       ))
 *   ));
 *
 *   //Save, saves in every backend
 *   $cache->save('my-key', $data);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Multiple) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache, Multiple, phalcon, cache_multiple, phalcon_cache_multiple_method_entry, 0);

	zend_declare_property_null(phalcon_cache_multiple_ce, SL("_backends"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Multiple constructor
 *
 * @param	Phalcon\Cache\BackendInterface[] backends
 */
PHP_METHOD(Phalcon_Cache_Multiple, __construct) {

	zval *backends = NULL;

	zephir_fetch_params(0, 0, 1, &backends);

	if (!backends) {
		backends = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(backends) != IS_NULL) {
		if (Z_TYPE_P(backends) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_cache_exception_ce, "The backends must be an array", "phalcon/cache/multiple.zep", 83);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_backends"), backends TSRMLS_CC);
	}

}

/**
 * Adds a backend
 */
PHP_METHOD(Phalcon_Cache_Multiple, push) {

	zval *backend;

	zephir_fetch_params(0, 1, 0, &backend);



	zephir_update_property_array_append(this_ptr, SL("_backends"), backend TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns a cached content reading the internal backends
 *
 * @param 	string|int keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Multiple, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *keyName, *lifetime = NULL, *backend = NULL, *content = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cache/multiple.zep", 116);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		ZEPHIR_CALL_METHOD(&content, backend, "get", NULL, 0, keyName, lifetime);
		zephir_check_call_status();
		if (Z_TYPE_P(content) != IS_NULL) {
			RETURN_CCTOR(content);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Starts every backend
 *
 * @param string|int keyName
 * @param long lifetime
 */
PHP_METHOD(Phalcon_Cache_Multiple, start) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *keyName, *lifetime = NULL, *backend = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cache/multiple.zep", 132);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		ZEPHIR_CALL_METHOD(NULL, backend, "start", NULL, 0, keyName, lifetime);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Stores cached content into all backends and stops the frontend
 *
 * @param string keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Multiple, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *backend = NULL, *_0, **_3;

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
		stopBuffer = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cache/multiple.zep", 149);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		ZEPHIR_CALL_METHOD(NULL, backend, "save", NULL, 0, keyName, content, lifetime, stopBuffer);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from each backend
 *
 * @param string|int keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Multiple, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *keyName, *backend = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cache/multiple.zep", 165);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		ZEPHIR_CALL_METHOD(NULL, backend, "delete", NULL, 0, keyName);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Checks if cache exists in at least one backend
 *
 * @param  string|int keyName
 * @param  long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Multiple, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *keyName = NULL, *lifetime = NULL, *backend = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cache/multiple.zep", 185);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		ZEPHIR_CALL_METHOD(&_4, backend, "exists", NULL, 0, keyName, lifetime);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE(_4)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

