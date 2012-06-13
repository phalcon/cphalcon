
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_cache_backend_file_ce, this_ptr, "_backendOptions", strlen("_backendOptions"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &frontend_object, &backend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_frontendObject", strlen("_frontendObject"), frontend_object TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_backendOptions", strlen("_backendOptions"), backend_options TSRMLS_CC);
	eval_int = phalcon_array_isset_string(backend_options, "cacheDir", strlen("cacheDir")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, backend_options, "cacheDir", strlen("cacheDir"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "is_writable", r1, 0x017);
		if (!zend_is_true(r0)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache directory does not exist or is not writable");
			return;
		}
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "You must specify the cache directory with the option cachesDir");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Starts a cache. The $keyname allow to identify the created fragment
 *
 * @param string $keyName
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, start){

	zval *key_name = NULL, *backend = NULL, *front_end = NULL, *existing_cache = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "get", key_name, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(existing_cache, r0);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_NULL(t2);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, existing_cache, t2 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "start", PHALCON_NO_CHECK);
	}
	
	
	PHALCON_RETURN_CHECK_CTOR(existing_cache);
}

/**
 * Returns a cached content
 *
 * @param string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, get){

	zval *key_name = NULL, *lifetime = NULL, *backend = NULL, *front_end = NULL;
	zval *sanitize_key = NULL, *cache_file = NULL, *time = NULL, *ttl = NULL, *cached_content = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;

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
	phalcon_read_property(&t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_filter_alphanum(r0, key_name);
	PHALCON_CPY_WRT(sanitize_key, r0);
	phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), sanitize_key TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, backend, "cacheDir", strlen("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VV(r1, r2, sanitize_key);
	PHALCON_CPY_WRT(cache_file, r1);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_FUNC(r3, "time", 0x018);
		PHALCON_CPY_WRT(time, r3);
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
		PHALCON_CALL_FUNC_PARAMS_1(r6, "filemtime", cache_file, 0x019);
		
		PHALCON_INIT_VAR(r7);
		is_smaller_function(r7, r5, r6 TSRMLS_CC);
		if (zend_is_true(r7)) {
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CALL_FUNC_PARAMS_1(r8, "file_get_contents", cache_file, 0x01A);
			PHALCON_CPY_WRT(cached_content, r8);
			
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CALL_METHOD_PARAMS_1(r9, front_end, "afterretrieve", cached_content, PHALCON_NO_CHECK);
			PHALCON_RETURN_DZVAL(r9);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Stores cached content into the file backend
 *
 * @param string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_File, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key = NULL, *front_end = NULL, *backend = NULL, *cache_dir = NULL;
	zval *cache_file = NULL, *cached_content = NULL, *prepared_content = NULL;
	zval *is_buffering = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;

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
		phalcon_read_property(&t0, this_ptr, "_lastKey", sizeof("_lastKey")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(last_key, t0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_filter_alphanum(r0, key_name);
		PHALCON_CPY_WRT(last_key, r0);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t2);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, backend, "cacheDir", strlen("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(cache_dir, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "is_writable", cache_dir, 0x017);
	if (!zend_is_true(r2)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache file is not writable");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_VV(r3, cache_dir, last_key);
	PHALCON_CPY_WRT(cache_file, r3);
	if (!zend_is_true(content)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, front_end, "getcontent", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(cached_content, r4);
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD_PARAMS_1(r5, front_end, "beforestore", cached_content, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(prepared_content, r5);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", cache_file, prepared_content, 0x01B);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, front_end, "isbuffering", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(is_buffering, r6);
	if (zend_is_true(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "stop", PHALCON_NO_CHECK);
	}
	
	if (zend_is_true(is_buffering)) {
		zend_print_zval(cached_content, 1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes a value from the cache by its key
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_File, delete){

	zval *key_name = NULL, *backend = NULL, *sanitize_key = NULL, *cache_file = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_filter_alphanum(r0, key_name);
	PHALCON_CPY_WRT(sanitize_key, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, backend, "cacheDir", strlen("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VV(r1, r2, sanitize_key);
	PHALCON_CPY_WRT(cache_file, r1);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_FUNC_PARAMS_1(r3, "unlink", cache_file, 0x028);
		PHALCON_RETURN_DZVAL(r3);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Returns front-end instance adapter related to the back-end
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, getFrontend){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

