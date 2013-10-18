
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
#include "kernel/fcall.h"
#include "kernel/operators.h"


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
 * Phalcon\Cache\Multiple
 *
 * Allows to read to chained backends writing to multiple backends
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


	if ((Z_TYPE_P(backends) != IS_NULL)) {
		if ((Z_TYPE_P(backends) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STRW(phalcon_cache_exception_ce, "The backends must be an array");
			return;
		}
		zephir_update_property_this(this_ptr, SL("_backends"), backends TSRMLS_CC);
	}

}

/**
 * Adds a backend
 *
 * @param Phalcon\Cache\BackendInterface $backend
 * @return Phalcon\Cache\Multiple
 */
PHP_METHOD(Phalcon_Cache_Multiple, push) {

	zval *backend;

	zephir_fetch_params(0, 1, 0, &backend);



	if ((Z_TYPE_P(backend) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_cache_exception_ce, "The backend is not valid");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_backends"), backend TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns a cached content reading the internal backends
 *
 * @param 	string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Multiple, get) {

	zend_function *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *keyName, *lifetime = NULL, *backend = NULL, *content = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		ZEPHIR_INIT_NVAR(content);
		zephir_call_method_p2_cache(content, backend, "get", &_4, keyName, lifetime);
		if ((Z_TYPE_P(content) != IS_NULL)) {
			RETURN_CCTOR(content);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Starts every backend
 *
 * @param int|string keyName
 * @param   long lifetime
 */
PHP_METHOD(Phalcon_Cache_Multiple, start) {

	zend_function *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *keyName, *lifetime = NULL, *backend = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		zephir_call_method_p2_cache_noret(backend, "start", &_4, keyName, lifetime);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Stores cached content into all backends and stops the frontend
 *
 * @param string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Multiple, save) {

	zend_function *_4 = NULL;
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
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		zephir_call_method_p4_cache_noret(backend, "save", &_4, keyName, content, lifetime, stopBuffer);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from each backend
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Multiple, delete) {

	zend_function *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *keyName_param = NULL, *backend = NULL, *_0, **_3;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName_param);

		zephir_get_strval(keyName, keyName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		zephir_call_method_p1_cache_noret(backend, "delete", &_4, keyName);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Checks if cache exists in at least one backend
 *
 * @param  string keyName
 * @param  long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Multiple, exists) {

	zend_function *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *keyName_param = NULL, *lifetime = NULL, *backend = NULL, *_0, **_3, *_4 = NULL;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName_param, &lifetime);

	if (!keyName_param) {
		ZEPHIR_INIT_VAR(keyName);
		ZVAL_EMPTY_STRING(keyName);
	} else {
		zephir_get_strval(keyName, keyName_param);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(backend, _3);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method_p2_cache(_4, backend, "exists", &_5, keyName, lifetime);
		if (ZEPHIR_IS_TRUE(_4)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

