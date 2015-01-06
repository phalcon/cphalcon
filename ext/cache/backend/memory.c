
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

#include "cache/backend/memory.h"
#include "cache/backend.h"
#include "cache/backendinterface.h"
#include "cache/exception.h"

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
zend_class_entry *phalcon_cache_backend_memory_ce;

PHP_METHOD(Phalcon_Cache_Backend_Memory, get);
PHP_METHOD(Phalcon_Cache_Backend_Memory, save);
PHP_METHOD(Phalcon_Cache_Backend_Memory, delete);
PHP_METHOD(Phalcon_Cache_Backend_Memory, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Memory, exists);
PHP_METHOD(Phalcon_Cache_Backend_Memory, increment);
PHP_METHOD(Phalcon_Cache_Backend_Memory, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Memory, flush);

static const zend_function_entry phalcon_cache_backend_memory_method_entry[] = {
	PHP_ME(Phalcon_Cache_Backend_Memory, get, arginfo_phalcon_cache_backendinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, save, arginfo_phalcon_cache_backendinterface_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, delete, arginfo_phalcon_cache_backendinterface_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, queryKeys, arginfo_phalcon_cache_backendinterface_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, exists, arginfo_phalcon_cache_backendinterface_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, increment, arginfo_phalcon_cache_backendinterface_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, decrement, arginfo_phalcon_cache_backendinterface_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
		phalcon_update_property_this(this_ptr, SL("_lastKey"), last_key TSRMLS_CC);
	}

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&cached_content, data, last_key)) {
		if (Z_TYPE_P(cached_content) != IS_NULL) {
			if (phalcon_is_numeric(cached_content)) {
				RETVAL_ZVAL(cached_content, 1, 0);
			} else {
				frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
				PHALCON_RETURN_CALL_METHOD(frontend, "afterretrieve", cached_content);
			}
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
	zval *cached_content = NULL, *prepared_content = NULL, *is_buffering = NULL;
	zval *last_key, *frontend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);

	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}

	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		PHALCON_CALL_METHOD(&cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}

	if (phalcon_is_numeric(cached_content))	{
		phalcon_update_property_array(this_ptr, SL("_data"), last_key, cached_content TSRMLS_CC);
	} else {
		PHALCON_CALL_METHOD(&prepared_content, frontend, "beforestore", cached_content);
		phalcon_update_property_array(this_ptr, SL("_data"), last_key, prepared_content TSRMLS_CC);
	}

	PHALCON_CALL_METHOD(&is_buffering, frontend, "isbuffering");

	if (!stop_buffer || PHALCON_IS_TRUE(stop_buffer)) {
		PHALCON_CALL_METHOD(NULL, frontend, "stop");
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

	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, prefix, key_name);

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
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

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);

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
				if (type == HASH_KEY_IS_STRING && str_index_len > (uint)(Z_STRLEN_P(prefix)) && !memcmp(Z_STRVAL_P(prefix), str_index, str_index_len-1)) {
					add_next_index_stringl(return_value, str_index, str_index_len - 1, 1);
				}
				else if (unlikely(type == HASH_KEY_IS_LONG)) {
					char buf[8 * sizeof(ulong) + 2];
                    int buflength = 8 * sizeof(ulong) + 2;
					int size;
					size = snprintf(buf, buflength, "%ld", (long) num_index);
					if (size >= Z_STRLEN_P(prefix) && !memcmp(Z_STRVAL_P(prefix), buf, size)) {
						add_next_index_long(return_value, (long) num_index);
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
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
		if (phalcon_array_isset(data, last_key)) {
			RETURN_MM_TRUE;
		}
	}

	RETURN_MM_FALSE;
}

/**
 * Increment of given $keyName by $value
 *
 * @param  string $keyName
 * @param  long $lifetime
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, increment){

	zval **key_name, **value = NULL, *last_key, *data;
	zval *cached_content;

	phalcon_fetch_params_ex(1, 1, &key_name, &value);

	if (!value || Z_TYPE_PP(value) == IS_NULL) {
		value = &PHALCON_GLOBAL(z_one);
	}
	else {
		PHALCON_ENSURE_IS_LONG(value);
	}

	PHALCON_MM_GROW();

	if (Z_TYPE_PP(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, *key_name);
	}

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&cached_content, data, last_key)) {
		RETVAL_FALSE;
		RETURN_MM();
	}


	add_function(return_value, cached_content, *value TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_data"), last_key, return_value TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Decrement of $keyName by given $value
 *
 * @param  string $keyName
 * @param  long $value
 * @return long
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, decrement){

	zval **key_name, **value = NULL, *last_key, *data;
	zval *cached_content;

	phalcon_fetch_params_ex(1, 1, &key_name, &value);

	if (!value || Z_TYPE_PP(value) == IS_NULL) {
		value = &PHALCON_GLOBAL(z_one);
	}
	else {
		PHALCON_ENSURE_IS_LONG(value);
	}

	PHALCON_MM_GROW();

	if (Z_TYPE_PP(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, *key_name);
	}

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&cached_content, data, last_key)) {
		RETVAL_FALSE;
		RETURN_MM();
	}

	sub_function(return_value, cached_content, *value TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_data"), last_key, return_value TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Immediately invalidates all existing items.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memory, flush){

	phalcon_update_property_null(this_ptr, SL("_data") TSRMLS_CC);

	RETURN_TRUE;
}
