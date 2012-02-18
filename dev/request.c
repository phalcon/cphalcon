
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
 * Php_Request
 *
 * Encapsulates request information for easily and secure access from application controllers
 */

PHP_METHOD(Phalcon_Request, __construct){


	phalcon_step_into_entry("Phalcon_Request", "__construct", 0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::__construct (Method) File=Library/Phalcon/Request.php Line=18");
}

PHP_METHOD(Phalcon_Request, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	phalcon_step_over("Phalcon_Request::getInstance (ClassVariables) File=Library/Phalcon/Request.php Line=10");
	phalcon_step_over("Phalcon_Request::getInstance (ClassVariables) File=Library/Phalcon/Request.php Line=12");
	phalcon_step_over("Phalcon_Request::getInstance (Method) File=Library/Phalcon/Request.php Line=14");
	phalcon_step_into_entry("Phalcon_Request", "getInstance", 0);
	phalcon_step_over("Phalcon_Request::getInstance (If) File=Library/Phalcon/Request.php Line=19");
	t0 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Request::getInstance (Block) File=Library/Phalcon/Request.php Line=19");
		phalcon_step_over("Phalcon_Request::getInstance (Assignment) File=Library/Phalcon/Request.php Line=20");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_request_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
		zend_update_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getInstance (Method) File=Library/Phalcon/Request.php Line=25");
}

PHP_METHOD(Phalcon_Request, setFilter){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Request", "setFilter", 0);
	phalcon_step_over("Phalcon_Request::setFilter (Assignment) File=Library/Phalcon/Request.php Line=26");
	//$filter
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::setFilter (Method) File=Library/Phalcon/Request.php Line=29");
}

PHP_METHOD(Phalcon_Request, getFilter){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "getFilter", 0);
	phalcon_step_over("Phalcon_Request::getFilter (If) File=Library/Phalcon/Request.php Line=30");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_filter", sizeof("_filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Request::getFilter (Block) File=Library/Phalcon/Request.php Line=30");
		phalcon_step_over("Phalcon_Request::getFilter (Assignment) File=Library/Phalcon/Request.php Line=31");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_filter_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), copy TSRMLS_CC);
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_filter", sizeof("_filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getFilter (Method) File=Library/Phalcon/Request.php Line=39");
}

/**
 * Gets variable from $_POST superglobal applying filters if needed
 */
PHP_METHOD(Phalcon_Request, getPost){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_INIT_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Request", "getPost", 0);
	phalcon_step_over("Phalcon_Request::getPost (If) File=Library/Phalcon/Request.php Line=40");
	//$name
	//$_POST
	PHALCON_GET_GLOBAL(a0, "_POST", gv0);
	eval_int = phalcon_array_isset(a0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getPost (Block) File=Library/Phalcon/Request.php Line=40");
		phalcon_step_over("Phalcon_Request::getPost (If) File=Library/Phalcon/Request.php Line=41");
		//$filters
		if (zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Request::getPost (Block) File=Library/Phalcon/Request.php Line=41");
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "getfilter" TSRMLS_CC);
			PHALCON_CALL_METHOD(r1, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(r1, "sanitize" TSRMLS_CC);
			//$name
			//$_POST
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch(r2, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r2);
			p0[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
			//$filters
			Z_ADDREF_P(v1);
			p0[1] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r0, r1, "sanitize", 2, p0, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r0, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Request::getPost (Block) File=Library/Phalcon/Request.php Line=43");
			//$name
			//$_POST
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			if (Z_TYPE_P(r3) > IS_BOOL) {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(r3);
					zval_copy_ctor(return_value);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			} else {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(r3);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			}
			return;
		}
	} else {
		phalcon_step_over("Phalcon_Request::getPost (Block) File=Library/Phalcon/Request.php Line=46");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getPost (Method) File=Library/Phalcon/Request.php Line=54");
}

/**
 * Gets variable from $_GET applying filters if needed
 */
PHP_METHOD(Phalcon_Request, getQuery){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_INIT_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Request", "getQuery", 0);
	phalcon_step_over("Phalcon_Request::getQuery (If) File=Library/Phalcon/Request.php Line=55");
	//$name
	//$_GET
	PHALCON_GET_GLOBAL(a0, "_GET", gv0);
	eval_int = phalcon_array_isset(a0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getQuery (Block) File=Library/Phalcon/Request.php Line=55");
		phalcon_step_over("Phalcon_Request::getQuery (If) File=Library/Phalcon/Request.php Line=56");
		//$filters
		if (zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Request::getQuery (Block) File=Library/Phalcon/Request.php Line=56");
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "getfilter" TSRMLS_CC);
			PHALCON_CALL_METHOD(r1, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(r1, "sanizite" TSRMLS_CC);
			//$name
			//$_GET
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch(r2, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r2);
			p0[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
			//$filters
			Z_ADDREF_P(v1);
			p0[1] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r0, r1, "sanizite", 2, p0, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r0, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Request::getQuery (Block) File=Library/Phalcon/Request.php Line=58");
			//$name
			//$_GET
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			if (Z_TYPE_P(r3) > IS_BOOL) {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(r3);
					zval_copy_ctor(return_value);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			} else {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(r3);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			}
			return;
		}
	} else {
		phalcon_step_over("Phalcon_Request::getQuery (Block) File=Library/Phalcon/Request.php Line=61");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getQuery (Method) File=Library/Phalcon/Request.php Line=69");
}

/**
 * Gets variable from $_SERVER applying filters if needed
 */
PHP_METHOD(Phalcon_Request, getServer){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Request", "getServer", 0);
	phalcon_step_over("Phalcon_Request::getServer (If) File=Library/Phalcon/Request.php Line=70");
	//$name
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset(a0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getServer (Block) File=Library/Phalcon/Request.php Line=70");
		//$name
		//$_SERVER
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getServer (Block) File=Library/Phalcon/Request.php Line=72");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getServer (Method) File=Library/Phalcon/Request.php Line=77");
}

PHP_METHOD(Phalcon_Request, getHeader){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Request", "getHeader", 0);
	phalcon_step_over("Phalcon_Request::getHeader (If) File=Library/Phalcon/Request.php Line=78");
	//$header
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset(a0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getHeader (Block) File=Library/Phalcon/Request.php Line=78");
		//$header
		//$_SERVER
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getHeader (Block) File=Library/Phalcon/Request.php Line=80");
		phalcon_step_over("Phalcon_Request::getHeader (If) File=Library/Phalcon/Request.php Line=81");
		//$header
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_concat_left(r1, "HTTP_", v0 TSRMLS_CC);
		//$_SERVER
		eval_int = phalcon_array_isset(a0, r1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::getHeader (Block) File=Library/Phalcon/Request.php Line=81");
			//$header
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_concat_left(r2, "HTTP_", v0 TSRMLS_CC);
			//$_SERVER
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			if (Z_TYPE_P(r3) > IS_BOOL) {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(r3);
					zval_copy_ctor(return_value);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			} else {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(r3);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			}
			return;
		} else {
			phalcon_step_over("Phalcon_Request::getHeader (Block) File=Library/Phalcon/Request.php Line=83");
			phalcon_step_out_entry();
			RETURN_STRING("", 1);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getHeader (Method) File=Library/Phalcon/Request.php Line=89");
}

PHP_METHOD(Phalcon_Request, getScheme){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "getScheme", 0);
	phalcon_step_over("Phalcon_Request::getScheme (If) File=Library/Phalcon/Request.php Line=90");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_HTTPS", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (phalcon_compare_strict_string(r0, "on")) {
		phalcon_step_over("Phalcon_Request::getScheme (Block) File=Library/Phalcon/Request.php Line=90");
		phalcon_step_out_entry();
		RETURN_STRING("https", 1);
	} else {
		phalcon_step_over("Phalcon_Request::getScheme (Block) File=Library/Phalcon/Request.php Line=92");
		phalcon_step_out_entry();
		RETURN_STRING("http", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getScheme (Method) File=Library/Phalcon/Request.php Line=97");
}

PHP_METHOD(Phalcon_Request, isAjax){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "isAjax", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getheader" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_X_REQUESTED_WITH", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getheader", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "XMLHttpRequest", 1);
	PHALCON_EQUAL_FUNCTION(r1, r0, t0);
	phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r1);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::isAjax (Method) File=Library/Phalcon/Request.php Line=101");
}

PHP_METHOD(Phalcon_Request, isSoapRequested){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "isSoapRequested", 0);
	phalcon_step_over("Phalcon_Request::isSoapRequested (If) File=Library/Phalcon/Request.php Line=102");
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset_string(a0, "HTTP_SOAPACTION", strlen("HTTP_SOAPACTION")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::isSoapRequested (Block) File=Library/Phalcon/Request.php Line=102");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isSoapRequested (Block) File=Library/Phalcon/Request.php Line=104");
		phalcon_step_over("Phalcon_Request::isSoapRequested (If) File=Library/Phalcon/Request.php Line=105");
		//$_SERVER
		eval_int = phalcon_array_isset_string(a0, "CONTENT_TYPE", strlen("CONTENT_TYPE")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::isSoapRequested (Block) File=Library/Phalcon/Request.php Line=105");
			PHALCON_ALLOC_ZVAL(r0);
			//$_SERVER
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, a0, "CONTENT_TYPE", strlen("CONTENT_TYPE"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p0[0] = r1;
			phalcon_debug_param(r1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p0[1]);
			ZVAL_STRING(p0[1], "application/soap+xml", 1);
			PHALCON_CALL_FUNC_PARAMS(r0, "strpos", 2, p0);
			phalcon_debug_vdump("strpos > ", r0 TSRMLS_CC);
			PHALCON_INIT_FALSE(t0);
			PHALCON_NOT_IDENTICAL_FUNCTION(r2, r0, t0);
			phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
			phalcon_step_out_entry();
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r2);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		} else {
			phalcon_step_over("Phalcon_Request::isSoapRequested (Block) File=Library/Phalcon/Request.php Line=107");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isSoapRequested (Method) File=Library/Phalcon/Request.php Line=113");
}

PHP_METHOD(Phalcon_Request, isSecureRequest){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isSecureRequest", 0);
	phalcon_step_over("Phalcon_Request::isSecureRequest (If) File=Library/Phalcon/Request.php Line=114");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getscheme" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "https", 1);
	PHALCON_IDENTICAL_FUNCTION(r1, r0, t0);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Request::isSecureRequest (Block) File=Library/Phalcon/Request.php Line=114");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isSecureRequest (Block) File=Library/Phalcon/Request.php Line=116");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isSecureRequest (Method) File=Library/Phalcon/Request.php Line=121");
}

PHP_METHOD(Phalcon_Request, getRawBody){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "getRawBody", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "php://input", 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "file_get_contents", 1, p0);
	phalcon_debug_vdump("file_get_contents > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getRawBody (Method) File=Library/Phalcon/Request.php Line=125");
}

PHP_METHOD(Phalcon_Request, getServerAddress){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getServerAddress", 0);
	phalcon_step_over("Phalcon_Request::getServerAddress (If) File=Library/Phalcon/Request.php Line=126");
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset_string(a0, "SERVER_ADDR", strlen("SERVER_ADDR")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getServerAddress (Block) File=Library/Phalcon/Request.php Line=126");
		//$_SERVER
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "SERVER_ADDR", strlen("SERVER_ADDR"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getServerAddress (Block) File=Library/Phalcon/Request.php Line=128");
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "localhost", 1);
		PHALCON_CALL_FUNC_PARAMS(r1, "gethostbyname", 1, p0);
		phalcon_debug_vdump("gethostbyname > ", r1 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r1, 1, 0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getServerAddress (Method) File=Library/Phalcon/Request.php Line=133");
}

PHP_METHOD(Phalcon_Request, getServerName){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getServerName", 0);
	phalcon_step_over("Phalcon_Request::getServerName (If) File=Library/Phalcon/Request.php Line=134");
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset_string(a0, "SERVER_NAME", strlen("SERVER_NAME")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getServerName (Block) File=Library/Phalcon/Request.php Line=134");
		//$_SERVER
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "SERVER_NAME", strlen("SERVER_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getServerName (Block) File=Library/Phalcon/Request.php Line=136");
		phalcon_step_out_entry();
		RETURN_STRING("localhost", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getServerName (Method) File=Library/Phalcon/Request.php Line=141");
}

PHP_METHOD(Phalcon_Request, getHttpHost){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "getHttpHost", 0);
	phalcon_step_over("Phalcon_Request::getHttpHost (Assignment) File=Library/Phalcon/Request.php Line=142");
	//$scheme
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getscheme" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$scheme", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getHttpHost (Assignment) File=Library/Phalcon/Request.php Line=143");
	//$name
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "HTTP_SERVER_NAME", 1);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "getserver", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r1);
	v1 = r1;
	phalcon_debug_assign("$name", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getHttpHost (Assignment) File=Library/Phalcon/Request.php Line=144");
	//$port
	PHALCON_ALLOC_ZVAL(r2);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p2[0]);
	ZVAL_STRING(p2[0], "HTTP_SERVER_PORT", 1);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getserver", 1, p2, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r2);
	v2 = r2;
	phalcon_debug_assign("$port", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getHttpHost (If) File=Library/Phalcon/Request.php Line=145");
	//$scheme
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "http", 1);
	PHALCON_EQUAL_FUNCTION(r3, v0, t0);
	//$port
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 80);
	PHALCON_EQUAL_FUNCTION(r4, v2, t1);
	PHALCON_AND_FUNCTION(r5, r3, r4);
	//$scheme
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, "https", 1);
	PHALCON_EQUAL_FUNCTION(r6, v0, t2);
	//$port
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 443);
	PHALCON_EQUAL_FUNCTION(r7, v2, t3);
	PHALCON_AND_FUNCTION(r8, r6, r7);
	PHALCON_OR_FUNCTION(r9, r5, r8);
	if (zend_is_true(r9)) {
		phalcon_step_over("Phalcon_Request::getHttpHost (Block) File=Library/Phalcon/Request.php Line=145");
		//$name
		phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v1) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v1);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getHttpHost (Block) File=Library/Phalcon/Request.php Line=147");
		//$name
		//$port
		PHALCON_ALLOC_ZVAL(r10);
		phalcon_concat_vboth(r10, v1, ":", v2 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r10 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r10);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getHttpHost (Method) File=Library/Phalcon/Request.php Line=152");
}

PHP_METHOD(Phalcon_Request, getClientAddress){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getClientAddress", 0);
	phalcon_step_over("Phalcon_Request::getClientAddress (If) File=Library/Phalcon/Request.php Line=153");
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset_string(a0, "HTTP_X_FORWARDED_FOR", strlen("HTTP_X_FORWARDED_FOR")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getClientAddress (Block) File=Library/Phalcon/Request.php Line=153");
		//$_SERVER
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_X_FORWARDED_FOR", strlen("HTTP_X_FORWARDED_FOR"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getClientAddress (Block) File=Library/Phalcon/Request.php Line=155");
		phalcon_step_over("Phalcon_Request::getClientAddress (If) File=Library/Phalcon/Request.php Line=156");
		//$_SERVER
		eval_int = phalcon_array_isset_string(a0, "REMOTE_ADDR", strlen("REMOTE_ADDR")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::getClientAddress (Block) File=Library/Phalcon/Request.php Line=156");
			//$_SERVER
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, a0, "REMOTE_ADDR", strlen("REMOTE_ADDR"), PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
			phalcon_step_out_entry();
			if (Z_TYPE_P(r1) > IS_BOOL) {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(r1);
					zval_copy_ctor(return_value);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			} else {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(r1);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			}
			return;
		} else {
			phalcon_step_over("Phalcon_Request::getClientAddress (Block) File=Library/Phalcon/Request.php Line=158");
			phalcon_step_out_entry();
			RETURN_STRING("", 1);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getClientAddress (Method) File=Library/Phalcon/Request.php Line=164");
}

PHP_METHOD(Phalcon_Request, getMethod){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getMethod", 0);
	phalcon_step_over("Phalcon_Request::getMethod (If) File=Library/Phalcon/Request.php Line=165");
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset_string(a0, "REQUEST_METHOD", strlen("REQUEST_METHOD")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getMethod (Block) File=Library/Phalcon/Request.php Line=165");
		//$_SERVER
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "REQUEST_METHOD", strlen("REQUEST_METHOD"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getMethod (Block) File=Library/Phalcon/Request.php Line=167");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getMethod (Method) File=Library/Phalcon/Request.php Line=172");
}

PHP_METHOD(Phalcon_Request, getUserAgent){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getUserAgent", 0);
	phalcon_step_over("Phalcon_Request::getUserAgent (If) File=Library/Phalcon/Request.php Line=173");
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset_string(a0, "HTTP_USER_AGENT", strlen("HTTP_USER_AGENT")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getUserAgent (Block) File=Library/Phalcon/Request.php Line=173");
		//$_SERVER
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_USER_AGENT", strlen("HTTP_USER_AGENT"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getUserAgent (Block) File=Library/Phalcon/Request.php Line=175");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getUserAgent (Method) File=Library/Phalcon/Request.php Line=180");
}

PHP_METHOD(Phalcon_Request, isPost){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isPost", 0);
	phalcon_step_over("Phalcon_Request::isPost (If) File=Library/Phalcon/Request.php Line=181");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (phalcon_compare_strict_string(r0, "POST")) {
		phalcon_step_over("Phalcon_Request::isPost (Block) File=Library/Phalcon/Request.php Line=181");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isPost (Block) File=Library/Phalcon/Request.php Line=183");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isPost (Method) File=Library/Phalcon/Request.php Line=188");
}

PHP_METHOD(Phalcon_Request, isGet){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isGet", 0);
	phalcon_step_over("Phalcon_Request::isGet (If) File=Library/Phalcon/Request.php Line=189");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (phalcon_compare_strict_string(r0, "GET")) {
		phalcon_step_over("Phalcon_Request::isGet (Block) File=Library/Phalcon/Request.php Line=189");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isGet (Block) File=Library/Phalcon/Request.php Line=191");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isGet (Method) File=Library/Phalcon/Request.php Line=196");
}

PHP_METHOD(Phalcon_Request, isPut){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isPut", 0);
	phalcon_step_over("Phalcon_Request::isPut (If) File=Library/Phalcon/Request.php Line=197");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (phalcon_compare_strict_string(r0, "PUT")) {
		phalcon_step_over("Phalcon_Request::isPut (Block) File=Library/Phalcon/Request.php Line=197");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isPut (Block) File=Library/Phalcon/Request.php Line=199");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isPut (Method) File=Library/Phalcon/Request.php Line=204");
}

PHP_METHOD(Phalcon_Request, isHead){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isHead", 0);
	phalcon_step_over("Phalcon_Request::isHead (If) File=Library/Phalcon/Request.php Line=205");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (phalcon_compare_strict_string(r0, "HEAD")) {
		phalcon_step_over("Phalcon_Request::isHead (Block) File=Library/Phalcon/Request.php Line=205");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isHead (Block) File=Library/Phalcon/Request.php Line=207");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isHead (Method) File=Library/Phalcon/Request.php Line=212");
}

PHP_METHOD(Phalcon_Request, isDelete){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isDelete", 0);
	phalcon_step_over("Phalcon_Request::isDelete (If) File=Library/Phalcon/Request.php Line=213");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (phalcon_compare_strict_string(r0, "DELETE")) {
		phalcon_step_over("Phalcon_Request::isDelete (Block) File=Library/Phalcon/Request.php Line=213");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isDelete (Block) File=Library/Phalcon/Request.php Line=215");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isDelete (Method) File=Library/Phalcon/Request.php Line=220");
}

PHP_METHOD(Phalcon_Request, isOptions){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isOptions", 0);
	phalcon_step_over("Phalcon_Request::isOptions (If) File=Library/Phalcon/Request.php Line=221");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (phalcon_compare_strict_string(r0, "OPTIONS")) {
		phalcon_step_over("Phalcon_Request::isOptions (Block) File=Library/Phalcon/Request.php Line=221");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isOptions (Block) File=Library/Phalcon/Request.php Line=223");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isOptions (Method) File=Library/Phalcon/Request.php Line=228");
}

PHP_METHOD(Phalcon_Request, hasFiles){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "hasFiles", 0);
	phalcon_step_over("Phalcon_Request::hasFiles (If) File=Library/Phalcon/Request.php Line=229");
	//$_FILES
	PHALCON_GET_GLOBAL(a0, "_FILES", gv0);
	if (zend_is_true(a0)) {
		phalcon_step_over("Phalcon_Request::hasFiles (Block) File=Library/Phalcon/Request.php Line=229");
		PHALCON_ALLOC_ZVAL(r1);
		//$_FILES
		p0[0] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "count", 1, p0);
		phalcon_debug_vdump("count > ", r1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_SMALLER_FUNCTION(r2, t0, r1);
		if (zend_is_true(r2)) {
			PHALCON_INIT_TRUE(t1);
			r0 = t1;
		} else {
			PHALCON_INIT_FALSE(t2);
			r0 = t2;
		}
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::hasFiles (Block) File=Library/Phalcon/Request.php Line=231");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::hasFiles (Method) File=Library/Phalcon/Request.php Line=236");
}

PHP_METHOD(Phalcon_Request, getUploadedFiles){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *i0 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	zend_class_entry *ce0;

	phalcon_step_into_entry("Phalcon_Request", "getUploadedFiles", 0);
	phalcon_step_over("Phalcon_Request::getUploadedFiles (If) File=Library/Phalcon/Request.php Line=237");
	//$_FILES
	PHALCON_GET_GLOBAL(a0, "_FILES", gv0);
	if (zend_is_true(a0)) {
		phalcon_step_over("Phalcon_Request::getUploadedFiles (Block) File=Library/Phalcon/Request.php Line=237");
		phalcon_step_over("Phalcon_Request::getUploadedFiles (Assignment) File=Library/Phalcon/Request.php Line=238");
		//$files
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a1);
		v0 = a1;
		phalcon_debug_assign("$files", a1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Request::getUploadedFiles (Foreach) File=Library/Phalcon/Request.php Line=239");
		//$_FILES
		//$file
		FOREACH_V(a0, ac0, fes2, fee2, ah0, hp0, v1)
			phalcon_step_over("Phalcon_Request::getUploadedFiles (Block) File=Library/Phalcon/Request.php Line=239");
			phalcon_step_over("Phalcon_Request::getUploadedFiles (Assignment) File=Library/Phalcon/Request.php Line=240");
			//$controllerFile
			ce0 = zend_fetch_class("controlleruploadfile", strlen("controlleruploadfile"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			if (!i0) {
				PHALCON_ALLOC_ZVAL(i0);
			} else {
				if (Z_REFCOUNT_P(i0) > 1) {
					{
						zval *orig_ptr = i0;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(i0);
							*i0 = *orig_ptr;
							zval_copy_ctor(i0);
							Z_SET_REFCOUNT_P(i0, 1);
							Z_UNSET_ISREF_P(i0);
						}
					}
				} else {
					FREE_ZVAL(i0);
					PHALCON_ALLOC_ZVAL(i0);
				}
			}
			object_init_ex(i0, ce0);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			//$file
			Z_ADDREF_P(v1);
			p0[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(i0);
			v2 = i0;
			phalcon_debug_assign("$controllerFile", i0 TSRMLS_CC);
			phalcon_step_over("Phalcon_Request::getUploadedFiles (Assignment) File=Library/Phalcon/Request.php Line=241");
			//$controllerFile
			//$files
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = v0;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						ALLOC_ZVAL(v0);
						*v0 = *orig_ptr;
						zval_copy_ctor(v0);
						Z_SET_REFCOUNT_P(v0, 1);
						Z_UNSET_ISREF_P(v0);
					}
				}
				phalcon_array_append(v0, copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes2, fee2, ah0, hp0);
		//$files
		phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getUploadedFiles (Block) File=Library/Phalcon/Request.php Line=244");
		PHALCON_ALLOC_ZVAL(a2);
		array_init(a2);
		phalcon_debug_vdump("Returning > ", a2 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(a2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getUploadedFiles (Method) File=Library/Phalcon/Request.php Line=249");
}

PHP_METHOD(Phalcon_Request, getHTTPReferer){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getHTTPReferer", 0);
	phalcon_step_over("Phalcon_Request::getHTTPReferer (If) File=Library/Phalcon/Request.php Line=250");
	//$_SERVER
	PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
	eval_int = phalcon_array_isset_string(a0, "HTTP_REFERER", strlen("HTTP_REFERER")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getHTTPReferer (Block) File=Library/Phalcon/Request.php Line=250");
		//$_SERVER
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_REFERER", strlen("HTTP_REFERER"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Request::getHTTPReferer (Block) File=Library/Phalcon/Request.php Line=252");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getHTTPReferer (Method) File=Library/Phalcon/Request.php Line=257");
}

PHP_METHOD(Phalcon_Request, getAcceptableContent){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getAcceptableContent", 0);
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=Library/Phalcon/Request.php Line=258");
	//$httpAccept
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_ACCEPT", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$httpAccept", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=Library/Phalcon/Request.php Line=259");
	//$accepted
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "/,\\s*/", 1);
	//$httpAccept
	p1[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "preg_split", 2, p1);
	phalcon_debug_vdump("preg_split > ", r1 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r1);
	v1 = r1;
	phalcon_debug_assign("$accepted", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=Library/Phalcon/Request.php Line=260");
	//$returnedAccept
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(a0);
	v2 = a0;
	phalcon_debug_assign("$returnedAccept", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Foreach) File=Library/Phalcon/Request.php Line=261");
	//$accepted
	//$accept
	FOREACH_V(v1, ac0, fes3, fee3, ah0, hp0, v3)
		phalcon_step_over("Phalcon_Request::getAcceptableContent (Block) File=Library/Phalcon/Request.php Line=261");
		phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=Library/Phalcon/Request.php Line=262");
		//$acceptParts
		if (!r2) {
			PHALCON_ALLOC_ZVAL(r2);
		} else {
			if (Z_REFCOUNT_P(r2) > 1) {
				{
					zval *orig_ptr = r2;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r2);
						*r2 = *orig_ptr;
						zval_copy_ctor(r2);
						Z_SET_REFCOUNT_P(r2, 1);
						Z_UNSET_ISREF_P(r2);
					}
				}
			} else {
				FREE_ZVAL(r2);
				PHALCON_ALLOC_ZVAL(r2);
			}
		}
		if (!p2[0]) {
			PHALCON_ALLOC_ZVAL(p2[0]);
		} else {
			if (Z_REFCOUNT_P(p2[0]) > 1) {
				SEPARATE_ZVAL(&p2[0]);
			} else {
				if (Z_TYPE_P(p2[0]) != IS_STRING) {
					FREE_ZVAL(p2[0]);
					PHALCON_ALLOC_ZVAL(p2[0]);
				}
			}
		}
		ZVAL_STRING(p2[0], ";", 1);
		//$accept
		p2[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r2, "explode", 2, p2);
		phalcon_debug_vdump("explode > ", r2 TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r2);
		v4 = r2;
		phalcon_debug_assign("$acceptParts", r2 TSRMLS_CC);
		phalcon_step_over("Phalcon_Request::getAcceptableContent (If) File=Library/Phalcon/Request.php Line=263");
		//$acceptParts
		eval_int = phalcon_array_isset_long(v4, 1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::getAcceptableContent (Block) File=Library/Phalcon/Request.php Line=263");
			phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=Library/Phalcon/Request.php Line=264");
			//$quality
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					{
						zval *orig_ptr = r3;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r3);
							*r3 = *orig_ptr;
							zval_copy_ctor(r3);
							Z_SET_REFCOUNT_P(r3, 1);
							Z_UNSET_ISREF_P(r3);
						}
					}
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			//$acceptParts
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					{
						zval *orig_ptr = r4;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r4);
							*r4 = *orig_ptr;
							zval_copy_ctor(r4);
							Z_SET_REFCOUNT_P(r4, 1);
							Z_UNSET_ISREF_P(r4);
						}
					}
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			phalcon_array_fetch_long(r4, v4, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r4);
			p3[0] = r4;
			phalcon_debug_param(r4 TSRMLS_CC);
			PHALCON_PARAM_LONG(p3[1], 2);
			PHALCON_CALL_FUNC_PARAMS(r3, "substr", 2, p3);
			phalcon_debug_vdump("substr > ", r3 TSRMLS_CC);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r3);
			v5 = r3;
			phalcon_debug_assign("$quality", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Request::getAcceptableContent (Block) File=Library/Phalcon/Request.php Line=265");
			phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=Library/Phalcon/Request.php Line=266");
			//$quality
			if (!v5) {
				PHALCON_ALLOC_ZVAL(v5);
			} else {
				if (Z_REFCOUNT_P(v5) > 1) {
					SEPARATE_ZVAL(&v5);
				} else {
					if (Z_TYPE_P(v5) != IS_DOUBLE) {
						FREE_ZVAL(v5);
						PHALCON_ALLOC_ZVAL(v5);
					}
				}
			}
			ZVAL_DOUBLE(v5, 1);
		}
		phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=Library/Phalcon/Request.php Line=268");
		if (!a1) {
			PHALCON_ALLOC_ZVAL(a1);
		} else {
			if (Z_REFCOUNT_P(a1) > 1) {
				SEPARATE_ZVAL(&a1);
			} else {
				if (Z_TYPE_P(a1) != IS_ARRAY) {
					FREE_ZVAL(a1);
					PHALCON_ALLOC_ZVAL(a1);
				}
			}
		}
		array_init(a1);
		//$acceptParts
		if (!r5) {
			PHALCON_ALLOC_ZVAL(r5);
		} else {
			if (Z_REFCOUNT_P(r5) > 1) {
				{
					zval *orig_ptr = r5;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r5);
						*r5 = *orig_ptr;
						zval_copy_ctor(r5);
						Z_SET_REFCOUNT_P(r5, 1);
						Z_UNSET_ISREF_P(r5);
					}
				}
			} else {
				FREE_ZVAL(r5);
				PHALCON_ALLOC_ZVAL(r5);
			}
		}
		phalcon_array_fetch_long(r5, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "accept", copy);
		}
		//$quality
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "quality", copy);
		}
		//$returnedAccept
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, a1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			{
				zval *orig_ptr = v2;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v2);
					*v2 = *orig_ptr;
					zval_copy_ctor(v2);
					Z_SET_REFCOUNT_P(v2, 1);
					Z_UNSET_ISREF_P(v2);
				}
			}
			phalcon_array_append(v2, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes3, fee3, ah0, hp0);
	//$returnedAccept
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Method) File=Library/Phalcon/Request.php Line=276");
}

PHP_METHOD(Phalcon_Request, getBestQualityAccept){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Request", "getBestQualityAccept", 0);
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=Library/Phalcon/Request.php Line=277");
	//$i
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=Library/Phalcon/Request.php Line=278");
	//$selectedAcceptQuality
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=Library/Phalcon/Request.php Line=279");
	//$selectedAcceptName
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Foreach) File=Library/Phalcon/Request.php Line=280");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getacceptablecontent" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getacceptablecontent", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	//$accept
	FOREACH_V(r0, ac0, fes4, fee4, ah0, hp0, v3)
		phalcon_step_over("Phalcon_Request::getBestQualityAccept (Block) File=Library/Phalcon/Request.php Line=280");
		phalcon_step_over("Phalcon_Request::getBestQualityAccept (If) File=Library/Phalcon/Request.php Line=281");
		//$i
		if (!t0) {
			PHALCON_ALLOC_ZVAL(t0);
		} else {
			if (Z_REFCOUNT_P(t0) > 1) {
				SEPARATE_ZVAL(&t0);
			} else {
				if (Z_TYPE_P(t0) != IS_LONG) {
					FREE_ZVAL(t0);
					PHALCON_ALLOC_ZVAL(t0);
				}
			}
		}
		ZVAL_LONG(t0, 0);
		PHALCON_EQUAL_FUNCTION(r1, v0, t0);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (Block) File=Library/Phalcon/Request.php Line=281");
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=Library/Phalcon/Request.php Line=282");
			//$selectedAcceptQuality
			//$accept
			if (!r2) {
				PHALCON_ALLOC_ZVAL(r2);
			} else {
				if (Z_REFCOUNT_P(r2) > 1) {
					{
						zval *orig_ptr = r2;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r2);
							*r2 = *orig_ptr;
							zval_copy_ctor(r2);
							Z_SET_REFCOUNT_P(r2, 1);
							Z_UNSET_ISREF_P(r2);
						}
					}
				} else {
					FREE_ZVAL(r2);
					PHALCON_ALLOC_ZVAL(r2);
				}
			}
			phalcon_array_fetch_string(r2, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r2);
			v1 = r2;
			phalcon_debug_assign("$selectedAcceptQuality", r2 TSRMLS_CC);
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=Library/Phalcon/Request.php Line=283");
			//$selectedAcceptName
			//$accept
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					{
						zval *orig_ptr = r3;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r3);
							*r3 = *orig_ptr;
							zval_copy_ctor(r3);
							Z_SET_REFCOUNT_P(r3, 1);
							Z_UNSET_ISREF_P(r3);
						}
					}
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			phalcon_array_fetch_string(r3, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r3);
			v2 = r3;
			phalcon_debug_assign("$selectedAcceptName", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (Block) File=Library/Phalcon/Request.php Line=284");
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (If) File=Library/Phalcon/Request.php Line=285");
			//$accept
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					{
						zval *orig_ptr = r4;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r4);
							*r4 = *orig_ptr;
							zval_copy_ctor(r4);
							Z_SET_REFCOUNT_P(r4, 1);
							Z_UNSET_ISREF_P(r4);
						}
					}
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			phalcon_array_fetch_string(r4, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			//$selectedAcceptQuality
			PHALCON_SMALLER_FUNCTION(r5, v1, r4);
			if (zend_is_true(r5)) {
				phalcon_step_over("Phalcon_Request::getBestQualityAccept (Block) File=Library/Phalcon/Request.php Line=285");
				phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=Library/Phalcon/Request.php Line=286");
				//$selectedAcceptQuality
				//$accept
				if (!r6) {
					PHALCON_ALLOC_ZVAL(r6);
				} else {
					if (Z_REFCOUNT_P(r6) > 1) {
						{
							zval *orig_ptr = r6;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r6);
								*r6 = *orig_ptr;
								zval_copy_ctor(r6);
								Z_SET_REFCOUNT_P(r6, 1);
								Z_UNSET_ISREF_P(r6);
							}
						}
					} else {
						FREE_ZVAL(r6);
						PHALCON_ALLOC_ZVAL(r6);
					}
				}
				phalcon_array_fetch_string(r6, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (v1) {
					Z_DELREF_P(v1);
					if (!Z_REFCOUNT_P(v1)) {
						FREE_ZVAL(v1);
					}
				}
				Z_ADDREF_P(r6);
				v1 = r6;
				phalcon_debug_assign("$selectedAcceptQuality", r6 TSRMLS_CC);
				phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=Library/Phalcon/Request.php Line=287");
				//$selectedAcceptName
				//$accept
				if (!r7) {
					PHALCON_ALLOC_ZVAL(r7);
				} else {
					if (Z_REFCOUNT_P(r7) > 1) {
						{
							zval *orig_ptr = r7;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r7);
								*r7 = *orig_ptr;
								zval_copy_ctor(r7);
								Z_SET_REFCOUNT_P(r7, 1);
								Z_UNSET_ISREF_P(r7);
							}
						}
					} else {
						FREE_ZVAL(r7);
						PHALCON_ALLOC_ZVAL(r7);
					}
				}
				phalcon_array_fetch_string(r7, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (v2) {
					Z_DELREF_P(v2);
					if (!Z_REFCOUNT_P(v2)) {
						FREE_ZVAL(v2);
					}
				}
				Z_ADDREF_P(r7);
				v2 = r7;
				phalcon_debug_assign("$selectedAcceptName", r7 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Request::getBestQualityAccept (PreIncDecOp) File=Library/Phalcon/Request.php Line=290");
		//$i
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		increment_function(v0);
		phalcon_debug_vdump("PreIncrementing $i", v0);
	END_FOREACH(ac0, fes4, fee4, ah0, hp0);
	//$selectedAcceptName
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Method) File=Library/Phalcon/Request.php Line=295");
}

PHP_METHOD(Phalcon_Request, getClientCharsets){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getClientCharsets", 0);
	phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=Library/Phalcon/Request.php Line=296");
	//$httpAcceptCharset
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_ACCEPT_CHARSET", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$httpAcceptCharset", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=Library/Phalcon/Request.php Line=297");
	//$accepted
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "/,\\s*/", 1);
	//$httpAcceptCharset
	p1[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "preg_split", 2, p1);
	phalcon_debug_vdump("preg_split > ", r1 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r1);
	v1 = r1;
	phalcon_debug_assign("$accepted", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=Library/Phalcon/Request.php Line=298");
	//$returnedAccept
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(a0);
	v2 = a0;
	phalcon_debug_assign("$returnedAccept", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getClientCharsets (Foreach) File=Library/Phalcon/Request.php Line=299");
	//$accepted
	//$accept
	FOREACH_V(v1, ac0, fes5, fee5, ah0, hp0, v3)
		phalcon_step_over("Phalcon_Request::getClientCharsets (Block) File=Library/Phalcon/Request.php Line=299");
		phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=Library/Phalcon/Request.php Line=300");
		//$acceptParts
		if (!r2) {
			PHALCON_ALLOC_ZVAL(r2);
		} else {
			if (Z_REFCOUNT_P(r2) > 1) {
				{
					zval *orig_ptr = r2;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r2);
						*r2 = *orig_ptr;
						zval_copy_ctor(r2);
						Z_SET_REFCOUNT_P(r2, 1);
						Z_UNSET_ISREF_P(r2);
					}
				}
			} else {
				FREE_ZVAL(r2);
				PHALCON_ALLOC_ZVAL(r2);
			}
		}
		if (!p2[0]) {
			PHALCON_ALLOC_ZVAL(p2[0]);
		} else {
			if (Z_REFCOUNT_P(p2[0]) > 1) {
				SEPARATE_ZVAL(&p2[0]);
			} else {
				if (Z_TYPE_P(p2[0]) != IS_STRING) {
					FREE_ZVAL(p2[0]);
					PHALCON_ALLOC_ZVAL(p2[0]);
				}
			}
		}
		ZVAL_STRING(p2[0], ";", 1);
		//$accept
		p2[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r2, "explode", 2, p2);
		phalcon_debug_vdump("explode > ", r2 TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r2);
		v4 = r2;
		phalcon_debug_assign("$acceptParts", r2 TSRMLS_CC);
		phalcon_step_over("Phalcon_Request::getClientCharsets (If) File=Library/Phalcon/Request.php Line=301");
		//$acceptParts
		eval_int = phalcon_array_isset_long(v4, 1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::getClientCharsets (Block) File=Library/Phalcon/Request.php Line=301");
			phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=Library/Phalcon/Request.php Line=302");
			//$quality
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					{
						zval *orig_ptr = r3;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r3);
							*r3 = *orig_ptr;
							zval_copy_ctor(r3);
							Z_SET_REFCOUNT_P(r3, 1);
							Z_UNSET_ISREF_P(r3);
						}
					}
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			//$acceptParts
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					{
						zval *orig_ptr = r4;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r4);
							*r4 = *orig_ptr;
							zval_copy_ctor(r4);
							Z_SET_REFCOUNT_P(r4, 1);
							Z_UNSET_ISREF_P(r4);
						}
					}
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			phalcon_array_fetch_long(r4, v4, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r4);
			p3[0] = r4;
			phalcon_debug_param(r4 TSRMLS_CC);
			PHALCON_PARAM_LONG(p3[1], 2);
			PHALCON_CALL_FUNC_PARAMS(r3, "substr", 2, p3);
			phalcon_debug_vdump("substr > ", r3 TSRMLS_CC);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r3);
			v5 = r3;
			phalcon_debug_assign("$quality", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Request::getClientCharsets (Block) File=Library/Phalcon/Request.php Line=303");
			phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=Library/Phalcon/Request.php Line=304");
			//$quality
			if (!v5) {
				PHALCON_ALLOC_ZVAL(v5);
			} else {
				if (Z_REFCOUNT_P(v5) > 1) {
					SEPARATE_ZVAL(&v5);
				} else {
					if (Z_TYPE_P(v5) != IS_DOUBLE) {
						FREE_ZVAL(v5);
						PHALCON_ALLOC_ZVAL(v5);
					}
				}
			}
			ZVAL_DOUBLE(v5, 1);
		}
		phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=Library/Phalcon/Request.php Line=306");
		if (!a1) {
			PHALCON_ALLOC_ZVAL(a1);
		} else {
			if (Z_REFCOUNT_P(a1) > 1) {
				SEPARATE_ZVAL(&a1);
			} else {
				if (Z_TYPE_P(a1) != IS_ARRAY) {
					FREE_ZVAL(a1);
					PHALCON_ALLOC_ZVAL(a1);
				}
			}
		}
		array_init(a1);
		//$acceptParts
		if (!r5) {
			PHALCON_ALLOC_ZVAL(r5);
		} else {
			if (Z_REFCOUNT_P(r5) > 1) {
				{
					zval *orig_ptr = r5;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r5);
						*r5 = *orig_ptr;
						zval_copy_ctor(r5);
						Z_SET_REFCOUNT_P(r5, 1);
						Z_UNSET_ISREF_P(r5);
					}
				}
			} else {
				FREE_ZVAL(r5);
				PHALCON_ALLOC_ZVAL(r5);
			}
		}
		phalcon_array_fetch_long(r5, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "accept", copy);
		}
		//$quality
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a1);
					*a1 = *orig_ptr;
					zval_copy_ctor(a1);
					Z_SET_REFCOUNT_P(a1, 1);
					Z_UNSET_ISREF_P(a1);
				}
			}
			add_assoc_zval(a1, "quality", copy);
		}
		//$returnedAccept
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, a1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			{
				zval *orig_ptr = v2;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v2);
					*v2 = *orig_ptr;
					zval_copy_ctor(v2);
					Z_SET_REFCOUNT_P(v2, 1);
					Z_UNSET_ISREF_P(v2);
				}
			}
			phalcon_array_append(v2, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes5, fee5, ah0, hp0);
	//$returnedAccept
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getClientCharsets (Method) File=Library/Phalcon/Request.php Line=314");
}

PHP_METHOD(Phalcon_Request, getBestQualityCharset){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Request", "getBestQualityCharset", 0);
	phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=Library/Phalcon/Request.php Line=315");
	//$i
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=Library/Phalcon/Request.php Line=316");
	//$selectedCharsetQuality
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=Library/Phalcon/Request.php Line=317");
	//$selectedCharsetName
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	phalcon_step_over("Phalcon_Request::getBestQualityCharset (Foreach) File=Library/Phalcon/Request.php Line=318");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getclientcharsets" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getclientcharsets", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	//$charset
	FOREACH_V(r0, ac0, fes6, fee6, ah0, hp0, v3)
		phalcon_step_over("Phalcon_Request::getBestQualityCharset (Block) File=Library/Phalcon/Request.php Line=318");
		phalcon_step_over("Phalcon_Request::getBestQualityCharset (If) File=Library/Phalcon/Request.php Line=319");
		//$i
		if (!t0) {
			PHALCON_ALLOC_ZVAL(t0);
		} else {
			if (Z_REFCOUNT_P(t0) > 1) {
				SEPARATE_ZVAL(&t0);
			} else {
				if (Z_TYPE_P(t0) != IS_LONG) {
					FREE_ZVAL(t0);
					PHALCON_ALLOC_ZVAL(t0);
				}
			}
		}
		ZVAL_LONG(t0, 0);
		PHALCON_EQUAL_FUNCTION(r1, v0, t0);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (Block) File=Library/Phalcon/Request.php Line=319");
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=Library/Phalcon/Request.php Line=320");
			//$selectedCharsetQuality
			//$charset
			if (!r2) {
				PHALCON_ALLOC_ZVAL(r2);
			} else {
				if (Z_REFCOUNT_P(r2) > 1) {
					{
						zval *orig_ptr = r2;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r2);
							*r2 = *orig_ptr;
							zval_copy_ctor(r2);
							Z_SET_REFCOUNT_P(r2, 1);
							Z_UNSET_ISREF_P(r2);
						}
					}
				} else {
					FREE_ZVAL(r2);
					PHALCON_ALLOC_ZVAL(r2);
				}
			}
			phalcon_array_fetch_string(r2, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r2);
			v1 = r2;
			phalcon_debug_assign("$selectedCharsetQuality", r2 TSRMLS_CC);
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=Library/Phalcon/Request.php Line=321");
			//$selectedCharsetName
			//$charset
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					{
						zval *orig_ptr = r3;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r3);
							*r3 = *orig_ptr;
							zval_copy_ctor(r3);
							Z_SET_REFCOUNT_P(r3, 1);
							Z_UNSET_ISREF_P(r3);
						}
					}
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			phalcon_array_fetch_string(r3, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r3);
			v2 = r3;
			phalcon_debug_assign("$selectedCharsetName", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (Block) File=Library/Phalcon/Request.php Line=322");
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (If) File=Library/Phalcon/Request.php Line=323");
			//$charset
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					{
						zval *orig_ptr = r4;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r4);
							*r4 = *orig_ptr;
							zval_copy_ctor(r4);
							Z_SET_REFCOUNT_P(r4, 1);
							Z_UNSET_ISREF_P(r4);
						}
					}
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			phalcon_array_fetch_string(r4, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			//$selectedCharsetQuality
			PHALCON_SMALLER_FUNCTION(r5, v1, r4);
			if (zend_is_true(r5)) {
				phalcon_step_over("Phalcon_Request::getBestQualityCharset (Block) File=Library/Phalcon/Request.php Line=323");
				phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=Library/Phalcon/Request.php Line=324");
				//$selectedCharsetQuality
				//$charset
				if (!r6) {
					PHALCON_ALLOC_ZVAL(r6);
				} else {
					if (Z_REFCOUNT_P(r6) > 1) {
						{
							zval *orig_ptr = r6;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r6);
								*r6 = *orig_ptr;
								zval_copy_ctor(r6);
								Z_SET_REFCOUNT_P(r6, 1);
								Z_UNSET_ISREF_P(r6);
							}
						}
					} else {
						FREE_ZVAL(r6);
						PHALCON_ALLOC_ZVAL(r6);
					}
				}
				phalcon_array_fetch_string(r6, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (v1) {
					Z_DELREF_P(v1);
					if (!Z_REFCOUNT_P(v1)) {
						FREE_ZVAL(v1);
					}
				}
				Z_ADDREF_P(r6);
				v1 = r6;
				phalcon_debug_assign("$selectedCharsetQuality", r6 TSRMLS_CC);
				phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=Library/Phalcon/Request.php Line=325");
				//$selectedCharsetName
				//$charset
				if (!r7) {
					PHALCON_ALLOC_ZVAL(r7);
				} else {
					if (Z_REFCOUNT_P(r7) > 1) {
						{
							zval *orig_ptr = r7;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r7);
								*r7 = *orig_ptr;
								zval_copy_ctor(r7);
								Z_SET_REFCOUNT_P(r7, 1);
								Z_UNSET_ISREF_P(r7);
							}
						}
					} else {
						FREE_ZVAL(r7);
						PHALCON_ALLOC_ZVAL(r7);
					}
				}
				phalcon_array_fetch_string(r7, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (v2) {
					Z_DELREF_P(v2);
					if (!Z_REFCOUNT_P(v2)) {
						FREE_ZVAL(v2);
					}
				}
				Z_ADDREF_P(r7);
				v2 = r7;
				phalcon_debug_assign("$selectedCharsetName", r7 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Request::getBestQualityCharset (PreIncDecOp) File=Library/Phalcon/Request.php Line=328");
		//$i
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		increment_function(v0);
		phalcon_debug_vdump("PreIncrementing $i", v0);
	END_FOREACH(ac0, fes6, fee6, ah0, hp0);
	//$selectedCharsetName
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
}

