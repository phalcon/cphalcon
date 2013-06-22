
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &backends);
	
	if (!backends) {
		PHALCON_INIT_VAR(backends);
	}
	
	if (Z_TYPE_P(backends) != IS_NULL) {
		if (Z_TYPE_P(backends) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backends must be an array");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_backends"), backends TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
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
	
	if (Z_TYPE_P(backend) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend is not valid");
		return;
	}
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

	zval *key_name, *lifetime = NULL, *backends, *backend = NULL;
	zval *content = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	phalcon_is_iterable(backends, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(backend);
	
		PHALCON_INIT_NVAR(content);
		phalcon_call_method_p2(content, backend, "get", key_name, lifetime);
		if (Z_TYPE_P(content) != IS_NULL) {
			RETURN_CCTOR(content);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
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

	zval *key_name, *lifetime = NULL, *backends, *backend = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	phalcon_is_iterable(backends, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(backend);
	
		phalcon_call_method_p2_noret(backend, "start", key_name, lifetime);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Stores cached content into the APC backend and stops the frontend
 *
 * @param string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Multiple, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *backends, *backend = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
	}
	
	if (!content) {
		PHALCON_INIT_VAR(content);
	}
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	if (!stop_buffer) {
		PHALCON_INIT_VAR(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	phalcon_is_iterable(backends, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(backend);
	
		phalcon_call_method_p4_noret(backend, "save", key_name, content, lifetime, stop_buffer);
	
		zend_hash_move_forward_ex(ah0, &hp0);
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

	zval *key_name, *backends, *backend = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	phalcon_is_iterable(backends, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(backend);
	
		phalcon_call_method_p1_noret(backend, "delete", key_name);
	
		zend_hash_move_forward_ex(ah0, &hp0);
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

	zval *key_name = NULL, *lifetime = NULL, *backends, *backend = NULL;
	zval *exists = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
	}
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	phalcon_is_iterable(backends, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(backend);
	
		PHALCON_INIT_NVAR(exists);
		phalcon_call_method_p2(exists, backend, "exists", key_name, lifetime);
		if (zend_is_true(exists)) {
			RETURN_MM_TRUE;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_MM_FALSE;
}

