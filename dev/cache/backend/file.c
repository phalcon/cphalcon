
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
		phalcon_array_fetch_string(&r0, backend_options, SL("cacheDir"), PHALCON_NOISY TSRMLS_CC);
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
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon_Cache_Backend_File", "__construct", frontend_object, backend_options);
	
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
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_NULL(lifetime);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_frontendObject"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("prefix"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_filter_alphanum(r1, key_name);
	PHALCON_CONCAT_VV(r0, t2, r1);
	PHALCON_CPY_WRT(prefixed_key, r0);
	phalcon_update_property_zval(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, backend, SL("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VV(r2, r3, prefixed_key);
	PHALCON_CPY_WRT(cache_file, r2);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(time);
		PHALCON_CALL_FUNC(time, "time");
		if (Z_TYPE_P(lifetime) == IS_NULL) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, front_end, "getlifetime", PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(ttl, r4);
		} else {
			PHALCON_CPY_WRT(ttl, lifetime);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		sub_function(r5, time, ttl TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_FUNC_PARAMS_1(r6, "filemtime", cache_file);
		
		PHALCON_INIT_VAR(r7);
		is_smaller_function(r7, r5, r6 TSRMLS_CC);
		if (zend_is_true(r7)) {
			PHALCON_INIT_VAR(cached_content);
			PHALCON_CALL_FUNC_PARAMS_1(cached_content, "file_get_contents", cache_file);
			
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CALL_METHOD_PARAMS_1(r8, front_end, "afterretrieve", cached_content, PHALCON_NO_CHECK);
			RETURN_DZVAL(r8);
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
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzzz", &key_name, &content, &lifetime, &stop_buffer) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
		ZVAL_NULL(key_name);
	}
	
	if (!content) {
		PHALCON_INIT_VAR(content);
		ZVAL_NULL(content);
	}
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_NULL(lifetime);
	}
	
	if (!stop_buffer) {
		PHALCON_INIT_VAR(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_lastKey"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(last_key, t0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_prefix"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_filter_alphanum(r1, key_name);
		PHALCON_CONCAT_VV(r0, t1, r1);
		PHALCON_CPY_WRT(last_key, r0);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_frontendObject"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t2);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t3);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, backend, SL("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(cache_dir, r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "is_writable", cache_dir);
	if (!zend_is_true(r3)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache file is not writable");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VV(r4, cache_dir, last_key);
	PHALCON_CPY_WRT(cache_file, r4);
	if (!zend_is_true(content)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_METHOD(r5, front_end, "getcontent", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(cached_content, r5);
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD_PARAMS_1(r6, front_end, "beforestore", cached_content, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(prepared_content, r6);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", cache_file, prepared_content);
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, front_end, "isbuffering", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(is_buffering, r7);
	if (zend_is_true(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "stop", PHALCON_NO_CHECK);
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
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_prefix"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_filter_alphanum(r1, key_name);
	PHALCON_CONCAT_VV(r0, t1, r1);
	PHALCON_CPY_WRT(prefixed_key, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, backend, SL("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VV(r2, r3, prefixed_key);
	PHALCON_CPY_WRT(cache_file, r2);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_FUNC_PARAMS_1(r4, "unlink", cache_file);
		RETURN_DZVAL(r4);
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
	zval *a0 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &prefix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
		ZVAL_NULL(prefix);
	}
	
	PHALCON_INIT_VAR(start);
	ZVAL_LONG(start, 0);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(keys, a0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_INIT_VAR(prefix_length);
	PHALCON_CALL_FUNC_PARAMS_1(prefix_length, "strlen", prefix);
	ce0 = zend_fetch_class("DirectoryIterator", strlen("DirectoryIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, backend, SL("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PHALCON_CHECK);
	PHALCON_CPY_WRT(iterator, i0);
	PHALCON_CALL_METHOD_NORETURN(iterator, "rewind", PHALCON_NO_CHECK);
	ws_469d_0:
		
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, iterator, "valid", PHALCON_NO_CHECK);
		if (!zend_is_true(r1)) {
			goto we_469d_0;
		}
		PHALCON_INIT_VAR(r2);
		PHALCON_CALL_METHOD(r2, iterator, "current", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(item, r2);
		
		PHALCON_INIT_VAR(r3);
		PHALCON_CALL_METHOD(r3, item, "isdir", PHALCON_NO_CHECK);
		if (!zend_is_true(r3)) {
			PHALCON_INIT_VAR(r4);
			PHALCON_CALL_METHOD(r4, item, "getfilename", PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(key, r4);
			if (zend_is_true(prefix)) {
				PHALCON_INIT_VAR(r5);
				PHALCON_CALL_FUNC_PARAMS_3(r5, "substr", key, start, prefix_length);
				PHALCON_INIT_VAR(r6);
				is_not_equal_function(r6, r5, prefix TSRMLS_CC);
				if (zend_is_true(r6)) {
					goto ws_469d_0;
				}
			}
			
			phalcon_array_append(&keys, key, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
		
		PHALCON_CALL_METHOD_NORETURN(iterator, "next", PHALCON_NO_CHECK);
		goto ws_469d_0;
	we_469d_0:
	
	RETURN_CTOR(keys);
}

