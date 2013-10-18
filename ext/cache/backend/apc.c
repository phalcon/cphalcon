
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"

/**
 * Phalcon\Cache\Backend\Apc
 *
 * Allows to cache output fragments, PHP data and raw data using an APC backend
 *
 *<code>
 *	//Cache data for 2 days
 *	$frontCache = new Phalcon\Cache\Frontend\Data(array(
 *		'lifetime' => 172800
 *	));
 *
 *  $cache = new Phalcon\Cache\Backend\Apc($frontCache, array(
 *      'prefix' => 'app-data'
 *  ));
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
 *</code>
 */

static int phalcon_cache_backend_is_apcu = -1;

/**
 * Phalcon\Cache\Backend\Apc initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Apc){

	if (-1 == phalcon_cache_backend_is_apcu) {
		phalcon_cache_backend_is_apcu = zend_hash_exists(&module_registry, SS("apcu"));
		if (phalcon_cache_backend_is_apcu) {
			zend_constant *c;
			if (zend_hash_find(EG(zend_constants), SS("APCU_APC_FULL_BC"), (void**)&c) == SUCCESS) {
				phalcon_cache_backend_is_apcu = !zend_is_true(&c->value);
			}
		}
	}

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Apc, cache_backend_apc, phalcon_cache_backend_ce, phalcon_cache_backend_apc_method_entry, 0);

	zend_class_implements(phalcon_cache_backend_apc_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;
}

/**
 * Returns a cached content
 *
 * @param 	string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, get){

	zval *key_name, *lifetime = NULL, *prefixed_key;
	zval *cached_content = NULL;
	zval *frontend, *prefix;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SVV(prefixed_key, "_PHCA", prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_OBS_VAR(cached_content);
	phalcon_call_func_p1_ex(cached_content, &cached_content, "apc_fetch", prefixed_key);
	if (PHALCON_IS_FALSE(cached_content)) {
		RETURN_MM_NULL();
	}

	if (phalcon_is_numeric(cached_content)) {
		RETURN_CCTOR(cached_content);
	} else {
		phalcon_return_call_method_p1(frontend, "afterretrieve", cached_content);
	}
	
	RETURN_MM();
}

/**
 * Stores cached content into the APC backend and stops the frontend
 *
 * @param string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *cached_content;
	zval *prepared_content, *ttl = NULL, *is_buffering;
	zval *last_key, *prefix, *frontend;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCA", prefix, key_name);
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
	
	if (!phalcon_is_numeric(cached_content)) {
		PHALCON_OBS_VAR(prepared_content);
		phalcon_call_method_p1_ex(prepared_content, &prepared_content, frontend, "beforestore", cached_content);
	}
	
	/** 
	 * Take the lifetime from the frontend or read it from the set in start()
	 */
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		zval *last_lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);

		if (Z_TYPE_P(last_lifetime) == IS_NULL) {
			PHALCON_OBS_VAR(ttl);
			phalcon_call_method_p0_ex(ttl, &ttl, frontend, "getlifetime");
		}
		else {
			ttl = last_lifetime;
		}
	} else {
		ttl = lifetime;
	}
	
	/** 
	 * Call apc_store in the PHP userland since most of the time it isn't available at
	 * compile time
	 */
	if (phalcon_is_numeric(cached_content)) {
		phalcon_call_func_p3_noret("apc_store", last_key, cached_content, ttl);
	} else {
		phalcon_call_func_p3_noret("apc_store", last_key, prepared_content, ttl);
	}
	
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
 * Increment of a given key, by number $value
 * 
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, increment){

	zval *key_name, *value = NULL, *prefixed_key;
	zval *cached_content = NULL, *function_name;
	zval *prefix;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(function_name);
	ZVAL_STRING(function_name, "apc_inc", 1);

	phalcon_fetch_params(1, 1, 1, &key_name, &value);

	if (!value) {
		PHALCON_INIT_VAR(value);
	}
	
	if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1);
	}

	if (Z_TYPE_P(value) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(value);
		convert_to_long_ex(&value);
	}
	
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SVV(prefixed_key, "_PHCA", prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	if (phalcon_function_exists(function_name TSRMLS_CC)) { 
		phalcon_call_func_p1(return_value, "apc_inc", value);
	} else {
		PHALCON_OBS_VAR(cached_content);
		phalcon_call_func_p1_ex(cached_content, &cached_content, "apc_fetch", prefixed_key);

		if (Z_TYPE_P(cached_content) != IS_LONG) {
			PHALCON_SEPARATE_PARAM(cached_content);
			convert_to_long_ex(&cached_content);
		}

		if (phalcon_is_numeric(cached_content)) {
			add_function(return_value, cached_content, value TSRMLS_CC);

			phalcon_call_method_p2_noret(this_ptr, "save", key_name, return_value);
		}
	}
	
	RETURN_MM();
}

/**
 * Decrement of a given key, by number $value
 * 
 * @param  string $keyName
 * @param  long $value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, decrement){

	zval *key_name, *value = NULL, *prefixed_key;
	zval *cached_content = NULL, *function_name;
	zval *prefix;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(function_name);
	ZVAL_STRING(function_name, "apc_dec", 1);

	phalcon_fetch_params(1, 1, 1, &key_name, &value);

	if (!value) {
		PHALCON_INIT_VAR(value);
	}
	
	if (Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1);
	}

	if (Z_TYPE_P(value) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(value);
		convert_to_long_ex(&value);
	}
	
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SVV(prefixed_key, "_PHCA", prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	if (phalcon_function_exists(function_name TSRMLS_CC)) { 
		phalcon_call_func_p1(return_value, "apc_dec", value);
	} else {
		PHALCON_OBS_VAR(cached_content);
		phalcon_call_func_p1_ex(cached_content, &cached_content, "apc_fetch", prefixed_key);

		if (Z_TYPE_P(cached_content) != IS_LONG) {
			PHALCON_SEPARATE_PARAM(cached_content);
			convert_to_long_ex(&cached_content);
		}

		if (phalcon_is_numeric(cached_content)) {
			sub_function(return_value, cached_content, value TSRMLS_CC);

			phalcon_call_method_p2_noret(this_ptr, "save", key_name, return_value);
		}
	}
	
	RETURN_MM();
}

/**
 * Deletes a value from the cache by its key
 *
 * @param string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, delete){

	zval *key_name, *prefix, *key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_SVV(key, "_PHCA", prefix, key_name);
	
	phalcon_return_call_func_p1("apc_delete", key);
	PHALCON_MM_RESTORE();
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, queryKeys){

	zval *prefix = NULL, *type, *prefix_pattern, *iterator;
	zval *key = NULL;
	zend_class_entry *apciterator_ce;
#if PHP_VERSION_ID < 50500
	char *str_key;
	uint str_key_len;
	ulong int_key;
	int key_type;
#else
	zval *itkey = NULL;
#endif
	zend_object_iterator *it;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	PHALCON_INIT_VAR(prefix_pattern);
	if (!prefix) {
		ZVAL_STRING(prefix_pattern, "/^_PHCA/", 1);
	}
	else {
		PHALCON_CONCAT_SVS(prefix_pattern, "/^_PHCA", prefix, "/");
	}
	
	array_init(return_value);
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "user", 1);
	
	apciterator_ce = zend_fetch_class(SL("APCIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(iterator);
	object_init_ex(iterator, apciterator_ce);
	assert(phalcon_has_constructor(iterator TSRMLS_CC));
	if (!phalcon_cache_backend_is_apcu) {
		phalcon_call_method_p2_noret(iterator, "__construct", type, prefix_pattern);
	}
	else {
		phalcon_call_method_p1_noret(iterator, "__construct", prefix_pattern);
	}

	/* APCIterator implements Iterator */
	assert(instanceof_function_ex(apciterator_ce, zend_ce_iterator, 1 TSRMLS_CC));

	it = apciterator_ce->get_iterator(apciterator_ce, iterator, 0 TSRMLS_CC);

	/* APCIterator is an iterator */
	assert(it != NULL);

	/* APCIterator has key() method */
	assert(it->funcs->get_current_key != NULL);

	/* APCIterator has rewind() method */
	assert(it->funcs->rewind != NULL);

	it->funcs->rewind(it TSRMLS_CC);
	while (it->funcs->valid(it TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_NVAR(key);
#if PHP_VERSION_ID < 50500
		key_type = it->funcs->get_current_key(it, &str_key, &str_key_len, &int_key TSRMLS_CC);
		if (likely(key_type == HASH_KEY_IS_STRING)) {
			/**
			 * Note that str_key_len includes the trailing zero.
			 * Remove the _PHCA prefix.
			 */
			ZVAL_STRINGL(key, str_key + 5, str_key_len - 5 - 1, 1);
			efree(str_key);

			phalcon_array_append(&return_value, key, PH_COPY);
		}
#else
		PHALCON_INIT_NVAR(itkey);
		it->funcs->get_current_key(it, itkey TSRMLS_CC);
		if (likely(Z_TYPE_P(itkey) == IS_STRING)) {
			ZVAL_STRINGL(key, Z_STRVAL_P(itkey) + 5, Z_STRLEN_P(itkey) - 5, 1);
			phalcon_array_append(&return_value, key, PH_COPY);
		}
#endif

		it->funcs->move_forward(it TSRMLS_CC);
	}
	
	it->funcs->dtor(it TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string $keyName
 * @param  long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, exists){

	zval *key_name = NULL, *lifetime = NULL, *cache_exists;
	zval *last_key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_SVV(last_key, "_PHCA", prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		PHALCON_OBS_VAR(cache_exists);
		phalcon_call_func_p1_ex(cache_exists, &cache_exists, "apc_exists", last_key);
		if (PHALCON_IS_NOT_FALSE(cache_exists)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Immediately invalidates all existing items.
 * 
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, flush){

	zval *type, *prefix_pattern, *iterator;
	zval *key = NULL;
	zend_class_entry *apciterator_ce;
#if PHP_VERSION_ID < 50500
	char *str_key;
	uint str_key_len;
	ulong int_key;
	int key_type;
#else
	zval *itkey = NULL;
#endif
	zend_object_iterator *it;

	PHALCON_MM_GROW();
	
	PHALCON_INIT_VAR(prefix_pattern);	
	ZVAL_STRING(prefix_pattern, "/^_PHCA/", 1);	
	
	array_init(return_value);
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "user", 1);
	
	apciterator_ce = zend_fetch_class(SL("APCIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(iterator);
	object_init_ex(iterator, apciterator_ce);
	assert(phalcon_has_constructor(iterator TSRMLS_CC));
	if (!phalcon_cache_backend_is_apcu) {
		phalcon_call_method_p2_noret(iterator, "__construct", type, prefix_pattern);
	}
	else {
		phalcon_call_method_p1_noret(iterator, "__construct", prefix_pattern);
	}

	/* APCIterator implements Iterator */
	assert(instanceof_function_ex(apciterator_ce, zend_ce_iterator, 1 TSRMLS_CC));

	it = apciterator_ce->get_iterator(apciterator_ce, iterator, 0 TSRMLS_CC);

	/* APCIterator is an iterator */
	assert(it != NULL);

	/* APCIterator has key() method */
	assert(it->funcs->get_current_key != NULL);

	/* APCIterator has rewind() method */
	assert(it->funcs->rewind != NULL);

	it->funcs->rewind(it TSRMLS_CC);
	while (it->funcs->valid(it TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_NVAR(key);
#if PHP_VERSION_ID < 50500
		key_type = it->funcs->get_current_key(it, &str_key, &str_key_len, &int_key TSRMLS_CC);
		if (likely(key_type == HASH_KEY_IS_STRING)) {
			/**
			 * Note that str_key_len includes the trailing zero.
			 * Remove the _PHCA prefix.
			 */
			ZVAL_STRINGL(key, str_key + 5, str_key_len - 5 - 1, 1);
			efree(str_key);

			phalcon_call_func_p1_noret("apc_delete", key);
		}
#else
		PHALCON_INIT_NVAR(itkey);
		it->funcs->get_current_key(it, itkey TSRMLS_CC);
		if (likely(Z_TYPE_P(itkey) == IS_STRING)) {
			ZVAL_STRINGL(key, Z_STRVAL_P(itkey) + 5, Z_STRLEN_P(itkey) - 5, 1);
			phalcon_call_func_p1_noret("apc_delete", key);
		}
#endif

		it->funcs->move_forward(it TSRMLS_CC);
	}
	
	it->funcs->dtor(it TSRMLS_CC);

	RETURN_MM_TRUE;
}
