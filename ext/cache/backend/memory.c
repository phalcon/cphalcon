
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memory, cache_backend_memory, phalcon_cache_backend_ce, phalcon_cache_backend_memory_method_entry, 0);

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

	zval *key_name, *lifetime = NULL;
	zval *data, *cached_content, *frontend, *last_key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&cached_content, data, last_key)) {
		if (Z_TYPE_P(cached_content) != IS_NULL) {
			frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
			phalcon_call_method_p1_ex(return_value, return_value_ptr, frontend, "afterretrieve", cached_content);
		}
	}

	PHALCON_MM_RESTORE();
}

/**
 * Stores cached content into the backend and stops the frontend
 *
 * @param string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *cached_content, *prepared_content, *is_buffering;
	zval *last_key, *frontend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		PHALCON_OBS_VAR(cached_content);
		phalcon_call_method_p0_ex(cached_content, &cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}
	
	PHALCON_OBS_VAR(prepared_content);
	phalcon_call_method_p1_ex(prepared_content, &prepared_content, frontend, "beforestore", cached_content);
	phalcon_update_property_array(this_ptr, SL("_data"), last_key, prepared_content TSRMLS_CC);
	
	PHALCON_OBS_VAR(is_buffering);
	phalcon_call_method_p0_ex(is_buffering, &is_buffering, frontend, "isbuffering");

	if (!stop_buffer || PHALCON_IS_TRUE(stop_buffer)) {
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
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, prefix, key_name);
	
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
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

	zval *prefix = NULL;
	zval *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	if (prefix && unlikely(Z_TYPE_P(prefix) != IS_STRING)) {
		PHALCON_SEPARATE_PARAM(prefix);
		convert_to_string(prefix);
	}

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);

	if (likely(Z_TYPE_P(data) == IS_ARRAY)) {
		if (!prefix) {
			phalcon_array_keys(return_value, data);
		}
		else {
			HashPosition pos;
			char *str_index;
			uint str_index_len;
			ulong num_index;
			int type;

			for (
				zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(data), &pos);
				(type = zend_hash_get_current_key_ex(Z_ARRVAL_P(data), &str_index, &str_index_len, &num_index, 0, &pos)) != HASH_KEY_NON_EXISTANT;
				zend_hash_move_forward_ex(Z_ARRVAL_P(data), &pos)
			) {
				if (type == HASH_KEY_IS_STRING && str_index_len > Z_STRLEN_P(prefix) && !memcmp(Z_STRVAL_P(prefix), str_index, str_index_len-1)) {
					add_next_index_stringl(return_value, str_index, str_index_len-1, 1);
				}
				else if (unlikely(type == HASH_KEY_IS_LONG)) {
					char buf[8*sizeof(ulong)+2];
					int size;
					size = sprintf(buf, "%ld", (long)num_index);
					if (size >= Z_STRLEN_P(prefix) && !memcmp(Z_STRVAL_P(prefix), buf, size)) {
						add_next_index_long(return_value, (long)num_index);
					}
				}
			}
		}
	}
	
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

	zval *key_name = NULL, *lifetime = NULL;
	zval *last_key, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		if (phalcon_array_isset(data, last_key)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}
