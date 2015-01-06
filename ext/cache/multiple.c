
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

#include "cache/backend.h"
#include "cache/backendinterface.h"
#include "cache/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

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
zend_class_entry *phalcon_cache_multiple_ce;

PHP_METHOD(Phalcon_Cache_Multiple, __construct);
PHP_METHOD(Phalcon_Cache_Multiple, push);
PHP_METHOD(Phalcon_Cache_Multiple, get);
PHP_METHOD(Phalcon_Cache_Multiple, start);
PHP_METHOD(Phalcon_Cache_Multiple, save);
PHP_METHOD(Phalcon_Cache_Multiple, delete);
PHP_METHOD(Phalcon_Cache_Multiple, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, backends)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_push, 0, 0, 1)
	ZEND_ARG_INFO(0, backend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cache_multiple_method_entry[] = {
	PHP_ME(Phalcon_Cache_Multiple, __construct, arginfo_phalcon_cache_multiple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Multiple, push, arginfo_phalcon_cache_multiple_push, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, get, arginfo_phalcon_cache_multiple_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, start, arginfo_phalcon_cache_multiple_start, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, save, arginfo_phalcon_cache_multiple_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, delete, arginfo_phalcon_cache_multiple_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, exists, arginfo_phalcon_cache_multiple_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Cache\Multiple initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Multiple){

	PHALCON_REGISTER_CLASS(Phalcon\\Cache, Multiple, cache_multiple, phalcon_cache_multiple_method_entry, 0);

	zend_declare_property_null(phalcon_cache_multiple_ce, SL("_backends"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Cache\Multiple constructor
 *
 * @param Phalcon\Cache\BackendInterface[] $backends
 */
PHP_METHOD(Phalcon_Cache_Multiple, __construct){

	zval *backends = NULL;

	phalcon_fetch_params(0, 0, 1, &backends);
	
	if (!backends) {
		backends = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(backends) != IS_NULL) {
		if (Z_TYPE_P(backends) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STRW(phalcon_cache_exception_ce, "The backends must be an array");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_backends"), backends TSRMLS_CC);
	}
}

/**
 * Adds a backend
 *
 * @param Phalcon\Cache\BackendInterface $backend
 * @return Phalcon\Cache\Multiple
 */
PHP_METHOD(Phalcon_Cache_Multiple, push){

	zval *backend;

	phalcon_fetch_params(0, 1, 0, &backend);
	
	PHALCON_VERIFY_INTERFACE_EX(backend, phalcon_cache_backendinterface_ce, phalcon_cache_exception_ce, 0)
	phalcon_update_property_array_append(this_ptr, SL("_backends"), backend TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns a cached content reading the internal backends
 *
 * @param 	string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Multiple, get){

	zval *key_name, *lifetime = NULL, *backends;
	zval *content = NULL;
	HashPosition hp0;
	zval **backend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (!lifetime) {
		lifetime = PHALCON_GLOBAL(z_null);
	}
	
	backends = phalcon_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(backends) == IS_ARRAY) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(backends), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(backends), (void**)&backend, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(backends), &hp0)
		) {
			PHALCON_CALL_METHOD(&content, *backend, "get", key_name, lifetime);
			if (Z_TYPE_P(content) != IS_NULL) {
				RETURN_CCTOR(content);
			}
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Starts every backend
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Multiple, start){

	zval *key_name, *lifetime = NULL, *backends;
	HashPosition hp0;
	zval **backend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (!lifetime) {
		lifetime = PHALCON_GLOBAL(z_null);
	}
	
	backends = phalcon_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(backends) == IS_ARRAY) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(backends), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(backends), (void**)&backend, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(backends), &hp0)
		) {
			PHALCON_CALL_METHOD(NULL, *backend, "start", key_name, lifetime);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Stores cached content into all backends and stops the frontend
 *
 * @param string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Multiple, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *backends;
	HashPosition hp0;
	zval **backend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name) {
		key_name = PHALCON_GLOBAL(z_null);
	}
	
	if (!content) {
		content = PHALCON_GLOBAL(z_null);
	}
	
	if (!lifetime) {
		lifetime = PHALCON_GLOBAL(z_null);
	}
	
	if (!stop_buffer) {
		stop_buffer = PHALCON_GLOBAL(z_true);
	}
	
	backends = phalcon_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(backends) == IS_ARRAY) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(backends), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(backends), (void**)&backend, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(backends), &hp0)
		) {
			PHALCON_CALL_METHOD(NULL, *backend, "save", key_name, content, lifetime, stop_buffer);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes a value from each backend
 *
 * @param int|string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Multiple, delete){

	zval *key_name, *backends;
	HashPosition hp0;
	zval **backend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	backends = phalcon_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(backends) == IS_ARRAY) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(backends), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(backends), (void**)&backend, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(backends), &hp0)
		) {
			PHALCON_CALL_METHOD(NULL, *backend, "delete", key_name);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if cache exists in at least one backend
 *
 * @param  string $keyName
 * @param  long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Multiple, exists){

	zval *key_name = NULL, *lifetime = NULL, *backends;
	zval *exists = NULL;
	HashPosition hp0;
	zval **backend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name) {
		key_name = PHALCON_GLOBAL(z_null);
	}
	
	if (!lifetime) {
		lifetime = PHALCON_GLOBAL(z_null);
	}
	
	backends = phalcon_fetch_nproperty_this(this_ptr, SL("_backends"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(backends) == IS_ARRAY) {
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(backends), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(backends), (void**)&backend, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(backends), &hp0)
		) {
			PHALCON_CALL_METHOD(&exists, *backend, "exists", key_name, lifetime);
			if (zend_is_true(exists)) {
				RETURN_MM_TRUE;
			}
		}
	}

	RETURN_MM_FALSE;
}
