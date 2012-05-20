
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

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
 * @param Phalcon_Cache_Backend_Output $frontendObject
 * @param array $backendOptions
 */
PHP_METHOD(Phalcon_Cache_Backend_File, __construct){

	zval *frontend_object = NULL, *backend_options = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
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
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_cache_exception_ce);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "The cache directory does not exist or is not writable", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_cache_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "You must specify the cache directory with the option cachesDir", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Starts a cache. The $keyname lets us to identity the created fragment
 *
 * @param string $keyName
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_File, start){

	zval *key_name = NULL, *backend = NULL, *cache_file = NULL, *front_end = NULL;
	zval *time = NULL, *lifetime = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, backend, "cacheDir", strlen("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, r0, key_name TSRMLS_CC);
	PHALCON_CPY_WRT(cache_file, r1);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	if (phalcon_file_exists(cache_file TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_FUNC(r2, "time", 0x018);
		PHALCON_CPY_WRT(time, r2);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, front_end, "getlifetime", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(lifetime, r3);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		sub_function(r4, time, lifetime TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_FUNC_PARAMS_1(r5, "filemtime", cache_file, 0x019);
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, r4, r5 TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CALL_FUNC_PARAMS_1(r7, "file_get_contents", cache_file, 0x01A);
			PHALCON_RETURN_DZVAL(r7);
		} else {
			phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), key_name TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(front_end, "start", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_NULL();
		}
	} else {
		phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), key_name TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(front_end, "start", PHALCON_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Stores cached content into file backend
 *
 * @param string $keyName
 * @param string $cachedContent
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_File, save){

	zval *key_name = NULL, *cached_content = NULL, *stop_buffer = NULL;
	zval *front_end = NULL, *backend = NULL, *cache_file = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &key_name, &cached_content, &stop_buffer) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
		ZVAL_NULL(key_name);
	} else {
		PHALCON_SEPARATE_PARAM(key_name);
	}
	
	if (!cached_content) {
		PHALCON_INIT_VAR(cached_content);
		ZVAL_NULL(cached_content);
	} else {
		PHALCON_SEPARATE_PARAM(cached_content);
	}
	
	if (!stop_buffer) {
		PHALCON_INIT_VAR(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	if (!zend_is_true(key_name)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_lastKey", sizeof("_lastKey")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(key_name, t0);
	}
	if (!zend_is_true(key_name)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_cache_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Cache must be started first", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t2);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, backend, "cacheDir", strlen("cacheDir"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, r0, key_name TSRMLS_CC);
	PHALCON_CPY_WRT(cache_file, r1);
	if (!zend_is_true(cached_content)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, front_end, "getcontent", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(cached_content, r2);
	}
	
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", cache_file, cached_content, 0x01B);
	if (zend_is_true(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "stop", PHALCON_NO_CHECK);
	}
	
	zend_print_zval(cached_content, 0);
	
	PHALCON_MM_RESTORE();
}

