
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

#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

/**
 * Phalcon\Cache\Backend\Memory
 *
 * Stores content in memory. Data is lost when the request is finished
 *
 *<code>
 *	//Cache data
 *	$frontCache = new Phalcon\Cache\Frontend\Data();
 *
 *  $cache = new Phalcon\Cache\Backend\Memory($frontCache);
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
 *</code>
 */


/**
 * Phalcon\Cache\Backend\Memory initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Memory){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memory, cache_backend_memory, "phalcon\\cache\\backend", phalcon_cache_backend_memory_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_memory_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_memory_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;
}

/**
 * Returns a cached content
 *
 * @param 	string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, get){

	zval *key_name, *lifetime = NULL, *last_key = NULL, *prefix, *data;
	zval *cached_content, *frontend, *processed;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_OBS_VAR(last_key);
		phalcon_read_property_this(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_OBS_VAR(prefix);
		phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	
	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (!phalcon_array_isset(data, last_key)) {
		RETURN_MM_NULL();
	}
	
	PHALCON_OBS_VAR(cached_content);
	phalcon_array_fetch(&cached_content, data, last_key, PH_NOISY_CC);
	if (Z_TYPE_P(cached_content) == IS_NULL) {
		RETURN_MM_NULL();
	}
	
	PHALCON_OBS_VAR(frontend);
	phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(processed);
	phalcon_call_method_p1(processed, frontend, "afterretrieve", cached_content);
	
	RETURN_CCTOR(processed);
}

/**
 * Stores cached content into the APC backend and stops the frontend
 *
 * @param string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key = NULL, *prefix, *frontend, *cached_content = NULL;
	zval *prepared_content, *is_buffering;

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
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_OBS_VAR(last_key);
		phalcon_read_property_this(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_OBS_VAR(prefix);
		phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_OBS_VAR(frontend);
	phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (Z_TYPE_P(content) == IS_NULL) {
		PHALCON_INIT_VAR(cached_content);
		phalcon_call_method(cached_content, frontend, "getcontent");
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_INIT_VAR(prepared_content);
	phalcon_call_method_p1(prepared_content, frontend, "beforestore", cached_content);
	phalcon_update_property_array(this_ptr, SL("_data"), last_key, prepared_content TSRMLS_CC);
	
	PHALCON_INIT_VAR(is_buffering);
	phalcon_call_method(is_buffering, frontend, "isbuffering");
	if (PHALCON_IS_TRUE(stop_buffer)) {
		phalcon_call_method_noret(frontend, "stop");
	}
	
	if (PHALCON_IS_TRUE(is_buffering)) {
		zend_print_zval(cached_content, 0);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes a value from the cache by its key
 *
 * @param string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, delete){

	zval *key_name, *prefix, *key, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, prefix, key_name);
	
	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset(data, key)) {
		phalcon_unset_property_array(this_ptr, SL("_data"), key TSRMLS_CC);
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, queryKeys){

	zval *prefix = NULL, *keys;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	}
	
	PHALCON_INIT_VAR(keys);
	array_init(keys);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string $keyName
 * @param  long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, exists){

	zval *key_name = NULL, *lifetime = NULL, *last_key = NULL, *prefix, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
	}
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_OBS_VAR(last_key);
		phalcon_read_property_this(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_OBS_VAR(prefix);
		phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	if (zend_is_true(last_key)) {
	
		PHALCON_OBS_VAR(data);
		phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
		if (phalcon_array_isset(data, last_key)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

