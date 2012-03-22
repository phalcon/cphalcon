
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Cache_Adapter_File
 *
 * Lets to cache output fragments using a file backend
 *
 */

/**
 * Phalcon_Cache_Adapter_File constructor
 *
 * @paramarray $frontendOptions
 * @paramarray $backendOptions
 */
PHP_METHOD(Phalcon_Cache_Adapter_File, __construct){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_cache_adapter_file_class_entry, this_ptr, "_frontendOptions", strlen("_frontendOptions"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_cache_adapter_file_class_entry, this_ptr, "_backendOptions", strlen("_backendOptions"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_frontendOptions", strlen("_frontendOptions"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_backendOptions", strlen("_backendOptions"), v1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(v1, "cacheDir", strlen("cacheDir")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v1, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "is_writable", r1, 0x014);
		Z_DELREF_P(r1);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_cache_exception_class_entry);
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "The cache directory does not exist or is not writable", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			PHALCON_MM_RESTORE();
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_cache_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "You must specify the cache directory with the option cachesDir", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Starts a cache. The $keyname lets us to identity the created fragment
 *
 * @param string $keyName
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Adapter_File, start){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v1, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, v2, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r1);
	if (phalcon_file_exists(v3 TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_frontendOptions", sizeof("_frontendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, t1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_FUNC(r2, "time", 0x015);
		PHALCON_CPY_WRT(v5, r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v4, "lifetime", strlen("lifetime"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		sub_function(r4, v5, v6 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r5);
		Z_ADDREF_P(v3);
		PHALCON_CALL_FUNC_PARAMS_1(r5, "filemtime", v3, 0x016);
		Z_DELREF_P(v3);
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, r4, r5 TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CALL_FUNC_PARAMS_1(r7, "file_get_contents", v3, 0x006);
			PHALCON_RETURN_DZVAL(r7);
		} else {
			phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), v0 TSRMLS_CC);
			PHALCON_CALL_FUNC_NORETURN("ob_start", 0x00F);
			PHALCON_MM_RESTORE();
			RETURN_NULL();
		}
	} else {
		phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_NORETURN("ob_start", 0x00F);
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Stores a cache
 * 
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Adapter_File, save){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_lastKey", sizeof("_lastKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_cache_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Cache must be started first", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v2, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, v3, v1 TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC(r2, "ob_get_contents", 0x010);
	PHALCON_CPY_WRT(v5, r2);
	Z_ADDREF_P(v4);
	Z_ADDREF_P(v5);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", v4, v5, 0x017);
	Z_DELREF_P(v4);
	Z_DELREF_P(v5);
	if (zend_is_true(v0)) {
		PHALCON_CALL_FUNC_NORETURN("ob_end_clean", 0x012);
	}
	zend_print_zval(v5, 0);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

