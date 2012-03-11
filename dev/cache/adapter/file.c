
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
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL };
	int eval_int;

	phalcon_step_into_entry("Phalcon_Cache_Adapter_File", "::__construct", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_cache_adapter_file_class_entry, this_ptr, "_frontendOptions", strlen("_frontendOptions"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	zend_update_property(phalcon_cache_adapter_file_class_entry, this_ptr, "_backendOptions", strlen("_backendOptions"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Cache_Adapter_File", "__construct", 0);
	phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (Assignment) File=/Cache/Adapter/File Line=24");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_frontendOptions", strlen("_frontendOptions"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (Assignment) File=/Cache/Adapter/File Line=25");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_backendOptions", strlen("_backendOptions"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (If) File=/Cache/Adapter/File Line=26");
	eval_int = phalcon_array_isset_string(v1, "cacheDir", strlen("cacheDir")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (Block) File=/Cache/Adapter/File Line=26");
		phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (If) File=/Cache/Adapter/File Line=27");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_string(r1, v1, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r0, "is_writable", 1, p0);
		phalcon_debug_vdump("is_writable > ", r0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (Block) File=/Cache/Adapter/File Line=27");
			phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (Throw) File=/Cache/Adapter/File Line=28");
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_cache_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Cache_Adapter_File" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "The cache directory does not exist or is not writable", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Cache_Adapter_File" TSRMLS_CC);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	} else {
		phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (Block) File=/Cache/Adapter/File Line=30");
		phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (Throw) File=/Cache/Adapter/File Line=31");
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_cache_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Cache_Adapter_File" TSRMLS_CC);
		phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], "You must specify the cache directory with the option cachesDir", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Cache_Adapter_File" TSRMLS_CC);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Cache_Adapter_File::__construct (Method) File=/Cache/Adapter/File Line=41");
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
	zval *p1[] = { NULL }, *p2[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Cache_Adapter_File", "start", 0);
	phalcon_step_over("Phalcon_Cache_Adapter_File::start (Assignment) File=/Cache/Adapter/File Line=42");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	phalcon_debug_assign("$backend", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache_Adapter_File::start (Assignment) File=/Cache/Adapter/File Line=43");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v1, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$cacheDir", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache_Adapter_File::start (Assignment) File=/Cache/Adapter/File Line=44");
	PHALCON_ALLOC_ZVAL(r1);
	concat_function(r1, v2, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r1);
	phalcon_debug_assign("$cacheFile", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache_Adapter_File::start (If) File=/Cache/Adapter/File Line=45");
	phalcon_debug_vdump("FileExists? > ", v3 TSRMLS_CC);
	if (phalcon_file_exists(v3 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_Cache_Adapter_File::start (Block) File=/Cache/Adapter/File Line=45");
		phalcon_step_over("Phalcon_Cache_Adapter_File::start (Assignment) File=/Cache/Adapter/File Line=46");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_frontendOptions", sizeof("_frontendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, t1);
		phalcon_debug_assign("$frontend", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Cache_Adapter_File::start (Assignment) File=/Cache/Adapter/File Line=47");
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_CALL_FUNC(r2, "time");
		phalcon_debug_vdump("time > ", r2 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r2);
		phalcon_debug_assign("$time", r2 TSRMLS_CC);
		phalcon_step_over("Phalcon_Cache_Adapter_File::start (Assignment) File=/Cache/Adapter/File Line=48");
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_array_fetch_string(r3, v4, "lifetime", strlen("lifetime"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r3);
		phalcon_debug_assign("$lifetime", r3 TSRMLS_CC);
		phalcon_step_over("Phalcon_Cache_Adapter_File::start (If) File=/Cache/Adapter/File Line=49");
		PHALCON_ALLOC_ZVAL(r4);
		sub_function(r4, v5, v6 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r5);
		Z_ADDREF_P(v3);
		p1[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r5, "filemtime", 1, p1);
		phalcon_debug_vdump("filemtime > ", r5 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r6);
		is_smaller_function(r6, r4, r5 TSRMLS_CC);
		if (zend_is_true(r6)) {
			phalcon_step_over("Phalcon_Cache_Adapter_File::start (Block) File=/Cache/Adapter/File Line=49");
			PHALCON_ALLOC_ZVAL(r7);
			p2[0] = v3;
			phalcon_debug_param(v3 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r7, "file_get_contents", 1, p2);
			phalcon_debug_vdump("file_get_contents > ", r7 TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r7 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r7, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Cache_Adapter_File::start (Block) File=/Cache/Adapter/File Line=51");
			phalcon_step_over("Phalcon_Cache_Adapter_File::start (Assignment) File=/Cache/Adapter/File Line=52");
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v0, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Cache_Adapter_File::start (FunctionCall) File=/Cache/Adapter/File Line=53");
			PHALCON_CALL_FUNC_NORETURN("ob_start");
			phalcon_step_out_entry();
			RETURN_NULL();
		}
	} else {
		phalcon_step_over("Phalcon_Cache_Adapter_File::start (Block) File=/Cache/Adapter/File Line=56");
		phalcon_step_over("Phalcon_Cache_Adapter_File::start (Assignment) File=/Cache/Adapter/File Line=57");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Cache_Adapter_File::start (FunctionCall) File=/Cache/Adapter/File Line=58");
		PHALCON_CALL_FUNC_NORETURN("ob_start");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Cache_Adapter_File::start (Method) File=/Cache/Adapter/File Line=68");
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
	zval *p0[] = { NULL }, *p2[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_BOOL(v0, 1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Cache_Adapter_File", "save", 0);
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (Assignment) File=/Cache/Adapter/File Line=69");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_lastKey", sizeof("_lastKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	phalcon_debug_assign("$keyName", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (If) File=/Cache/Adapter/File Line=70");
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Cache_Adapter_File::save (Block) File=/Cache/Adapter/File Line=70");
		phalcon_step_over("Phalcon_Cache_Adapter_File::save (Throw) File=/Cache/Adapter/File Line=71");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_cache_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Cache_Adapter_File" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "Cache must be started first", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Cache_Adapter_File" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (Assignment) File=/Cache/Adapter/File Line=73");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t1);
	phalcon_debug_assign("$backend", t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (Assignment) File=/Cache/Adapter/File Line=74");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v2, "cacheDir", strlen("cacheDir"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r0);
	phalcon_debug_assign("$cacheDir", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (Assignment) File=/Cache/Adapter/File Line=75");
	PHALCON_ALLOC_ZVAL(r1);
	concat_function(r1, v3, v1 TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r1);
	phalcon_debug_assign("$cacheFile", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (Assignment) File=/Cache/Adapter/File Line=76");
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_FUNC(r2, "ob_get_contents");
	phalcon_debug_vdump("ob_get_contents > ", r2 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r2);
	phalcon_debug_assign("$cachedContent", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (FunctionCall) File=/Cache/Adapter/File Line=77");
	Z_ADDREF_P(v4);
	p2[0] = v4;
	phalcon_debug_param(v4 TSRMLS_CC);
	Z_ADDREF_P(v5);
	p2[1] = v5;
	phalcon_debug_param(v5 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("file_put_contents", 2, p2);
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (If) File=/Cache/Adapter/File Line=78");
	if (zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Cache_Adapter_File::save (Block) File=/Cache/Adapter/File Line=78");
		phalcon_step_over("Phalcon_Cache_Adapter_File::save (FunctionCall) File=/Cache/Adapter/File Line=79");
		PHALCON_CALL_FUNC_NORETURN("ob_end_clean");
	}
	phalcon_step_over("Phalcon_Cache_Adapter_File::save (Echo) File=/Cache/Adapter/File Line=81");
	zend_print_zval(v5, 0);
	phalcon_step_out_entry();
	RETURN_NULL();
}

