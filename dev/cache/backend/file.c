
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"

/**
 * Phalcon_Cache_Backend_File
 *
 * Allows to cache output fragments using a file backend
 *
 *
 */

/**
 * Phalcon_Backend_Adapter_File constructor
 *
 * @param mixed $frontendObject
 * @param array $backendOptions
 */
PHP_METHOD(Phalcon_Cache_Backend_File, __construct){

	zval *frontend_object = NULL, *backend_options = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &frontend_object, &backend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(backend_options, SL("cacheDir")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, backend_options, SL("cacheDir"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "is_writable", r0);
		if (!zend_is_true(r1)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache directory does not exist or is not writable");
			return;
		}
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "You must specify the cache directory with the option cacheDir");
		return;
	}
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Cache\\Backend\\File", "__construct", frontend_object, backend_options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a cached content
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, get){

	zval *key_name = NULL, *lifetime = NULL, *backend = NULL, *front_end = NULL;
	zval *prefixed_key = NULL, *cache_file = NULL, *time = NULL, *ttl = NULL, *cached_content = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!lifetime) {
		PHALCON_ALLOC_ZVAL_MM(lifetime);
		ZVAL_NULL(lifetime);
	}
	
	PHALCON_INIT_VAR(backend);
	phalcon_read_property(&backend, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(front_end);
	phalcon_read_property(&front_end, this_ptr, SL("_frontendObject"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("prefix"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_filter_alphanum(r0, key_name);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, t0, r0);
	phalcon_update_property_zval(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, backend, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, r1, prefixed_key);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(time);
		PHALCON_CALL_FUNC(time, "time");
		if (Z_TYPE_P(lifetime) == IS_NULL) {
			PHALCON_INIT_VAR(ttl);
			PHALCON_CALL_METHOD(ttl, front_end, "getlifetime", PH_NO_CHECK);
		} else {
			PHALCON_CPY_WRT(ttl, lifetime);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		sub_function(r2, time, ttl TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_FUNC_PARAMS_1(r3, "filemtime", cache_file);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		is_smaller_function(r4, r2, r3 TSRMLS_CC);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(cached_content);
			PHALCON_CALL_FUNC_PARAMS_1(cached_content, "file_get_contents", cache_file);
			
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD_PARAMS_1(r5, front_end, "afterretrieve", cached_content, PH_NO_CHECK);
			RETURN_CTOR(r5);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Stores cached content into the file backend
 *
 * @param int|string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_File, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key = NULL, *front_end = NULL, *backend = NULL, *cache_dir = NULL;
	zval *cache_file = NULL, *cached_content = NULL, *prepared_content = NULL;
	zval *is_buffering = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzzz", &key_name, &content, &lifetime, &stop_buffer) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_ALLOC_ZVAL_MM(key_name);
		ZVAL_NULL(key_name);
	}
	
	if (!content) {
		PHALCON_ALLOC_ZVAL_MM(content);
		ZVAL_NULL(content);
	}
	
	if (!lifetime) {
		PHALCON_ALLOC_ZVAL_MM(lifetime);
		ZVAL_NULL(lifetime);
	}
	
	if (!stop_buffer) {
		PHALCON_ALLOC_ZVAL_MM(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_INIT_VAR(last_key);
		phalcon_read_property(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_prefix"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_filter_alphanum(r0, key_name);
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, t0, r0);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_INIT_VAR(front_end);
	phalcon_read_property(&front_end, this_ptr, SL("_frontendObject"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(backend);
	phalcon_read_property(&backend, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_dir);
	phalcon_array_fetch_string(&cache_dir, backend, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "is_writable", cache_dir);
	if (!zend_is_true(r1)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache file is not writable");
		return;
	}
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, cache_dir, last_key);
	if (!zend_is_true(content)) {
		PHALCON_INIT_VAR(cached_content);
		PHALCON_CALL_METHOD(cached_content, front_end, "getcontent", PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_INIT_VAR(prepared_content);
	PHALCON_CALL_METHOD_PARAMS_1(prepared_content, front_end, "beforestore", cached_content, PH_NO_CHECK);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", cache_file, prepared_content);
	
	PHALCON_INIT_VAR(is_buffering);
	PHALCON_CALL_METHOD(is_buffering, front_end, "isbuffering", PH_NO_CHECK);
	if (zend_is_true(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "stop", PH_NO_CHECK);
	}
	
	if (zend_is_true(is_buffering)) {
		zend_print_zval(cached_content, 1);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, delete){

	zval *key_name = NULL, *backend = NULL, *prefixed_key = NULL, *cache_file = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(backend);
	phalcon_read_property(&backend, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_filter_alphanum(r0, key_name);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, t0, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, backend, SL("cacheDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(cache_file);
	PHALCON_CONCAT_VV(cache_file, r1, prefixed_key);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_FUNC_PARAMS_1(r2, "unlink", cache_file);
		RETURN_CTOR(r2);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys){

	zval *prefix = NULL, *start = NULL, *keys = NULL, *backend = NULL, *prefix_length = NULL;
	zval *iterator = NULL, *item = NULL, *key = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &prefix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!prefix) {
		PHALCON_ALLOC_ZVAL_MM(prefix);
		ZVAL_NULL(prefix);
	}
	
	PHALCON_INIT_VAR(start);
	ZVAL_LONG(start, 0);
	
	PHALCON_INIT_VAR(keys);
	array_init(keys);
	
	PHALCON_INIT_VAR(backend);
	phalcon_read_property(&backend, this_ptr, SL("_backendOptions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefix_length);
	PHALCON_CALL_FUNC_PARAMS_1(prefix_length, "strlen", prefix);
	ce0 = zend_fetch_class(SL("DirectoryIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(iterator);
	object_init_ex(iterator, ce0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, backend, SL("cacheDir"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(iterator, "__construct", r0, PH_CHECK);
	PHALCON_CALL_METHOD_NORETURN(iterator, "rewind", PH_NO_CHECK);
	ws_469d_0:
		
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, iterator, "valid", PH_NO_CHECK);
		if (!zend_is_true(r1)) {
			goto we_469d_0;
		}
		PHALCON_INIT_VAR(item);
		PHALCON_CALL_METHOD(item, iterator, "current", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r2);
		PHALCON_CALL_METHOD(r2, item, "isdir", PH_NO_CHECK);
		if (!zend_is_true(r2)) {
			PHALCON_INIT_VAR(key);
			PHALCON_CALL_METHOD(key, item, "getfilename", PH_NO_CHECK);
			if (zend_is_true(prefix)) {
				PHALCON_INIT_VAR(r3);
				PHALCON_CALL_FUNC_PARAMS_3(r3, "substr", key, start, prefix_length);
				PHALCON_INIT_VAR(r4);
				is_not_equal_function(r4, r3, prefix TSRMLS_CC);
				if (zend_is_true(r4)) {
					goto ws_469d_0;
				}
			}
			
			phalcon_array_append(&keys, key, PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_CALL_METHOD_NORETURN(iterator, "next", PH_NO_CHECK);
		goto ws_469d_0;
	we_469d_0:
	
	RETURN_CTOR(keys);
}

