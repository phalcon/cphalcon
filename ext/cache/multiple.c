
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &backends) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!backends) {
		PHALCON_INIT_VAR(backends);
	}
	
	if (Z_TYPE_P(backends) != IS_NULL) {
		if (Z_TYPE_P(backends) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backends must be an array");
			return;
		}
		phalcon_update_property_zval(this_ptr, SL("_backends"), backends TSRMLS_CC);
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

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &backend) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(backend) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend is not valid");
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_backends"), backend TSRMLS_CC);
	
	RETURN_THIS();
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	if (!phalcon_is_iterable(backends, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(backend);
	
		PHALCON_INIT_NVAR(content);
		PHALCON_CALL_METHOD_PARAMS_2(content, backend, "get", key_name, lifetime);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	if (!phalcon_is_iterable(backends, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(backend);
	
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(backend, "start", key_name, lifetime);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzzz", &key_name, &content, &lifetime, &stop_buffer) == FAILURE) {
		RETURN_MM_NULL();
	}

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
	
	if (!phalcon_is_iterable(backends, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(backend);
	
		PHALCON_CALL_METHOD_PARAMS_4_NORETURN(backend, "save", key_name, content, lifetime, stop_buffer);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	if (!phalcon_is_iterable(backends, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(backend);
	
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(backend, "delete", key_name);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &key_name, &lifetime) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
	}
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	PHALCON_OBS_VAR(backends);
	phalcon_read_property_this(&backends, this_ptr, SL("_backends"), PH_NOISY_CC);
	
	if (!phalcon_is_iterable(backends, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(backend);
	
		PHALCON_INIT_NVAR(exists);
		PHALCON_CALL_METHOD_PARAMS_2(exists, backend, "exists", key_name, lifetime);
		if (zend_is_true(exists)) {
			RETURN_MM_TRUE;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_MM_FALSE;
}

