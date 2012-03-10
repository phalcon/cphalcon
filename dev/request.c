
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
 * Phalcon_Request
 *
 * Encapsulates request information for easily and secure access from application controllers.
 *
 * The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.
 *
 * 
 *
 */

PHP_METHOD(Phalcon_Request, __construct){


	phalcon_step_into_entry("Phalcon_Request", "__construct", 0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::__construct (Method) File=/Request Line=34");
}

/**
 * Gets the singleton instance of Phalcon_Request
 *
 * @return Phalcon_Request
 */
PHP_METHOD(Phalcon_Request, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "getInstance", 0);
	phalcon_step_over("Phalcon_Request::getInstance (If) File=/Request Line=35");
	t0 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Request::getInstance (Block) File=/Request Line=35");
		phalcon_step_over("Phalcon_Request::getInstance (Assignment) File=/Request Line=36");
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
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getInstance (Method) File=/Request Line=46");
}

/**
 * Overwrittes Phalcon_Filter object used to sanitize input data
 *
 * @param Phalcon_Filter $filter
 */
PHP_METHOD(Phalcon_Request, setFilter){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Request", "setFilter", 0);
	phalcon_step_over("Phalcon_Request::setFilter (Assignment) File=/Request Line=47");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::setFilter (Method) File=/Request Line=55");
}

/**
 * Returns active filter object used to sanitize input data
 *
 * @return Phalcon_Filter
 */
PHP_METHOD(Phalcon_Request, getFilter){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "getFilter", 0);
	phalcon_step_over("Phalcon_Request::getFilter (If) File=/Request Line=56");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_filter", sizeof("_filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Request::getFilter (Block) File=/Request Line=56");
		phalcon_step_over("Phalcon_Request::getFilter (Assignment) File=/Request Line=57");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_filter_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_filter", sizeof("_filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getFilter (Method) File=/Request Line=69");
}

/**
 * Gets variable from $_POST superglobal applying filters if needed
 *
 * @param string $name
 * @param string|array $filters
 * @return mixed
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
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Request", "getPost", 0);
	phalcon_step_over("Phalcon_Request::getPost (If) File=/Request Line=70");
	phalcon_init_global("_POST" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset(a0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getPost (Block) File=/Request Line=70");
		phalcon_step_over("Phalcon_Request::getPost (If) File=/Request Line=71");
		if (zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Request::getPost (Block) File=/Request Line=71");
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "getfilter" TSRMLS_CC);
			PHALCON_CALL_METHOD(r1, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(r1, "sanitize" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch(r2, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r2);
			p0[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
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
			phalcon_step_over("Phalcon_Request::getPost (Block) File=/Request Line=73");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			PHALCON_RETURN_CTOR(r3);
		}
	} else {
		phalcon_step_over("Phalcon_Request::getPost (Block) File=/Request Line=76");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getPost (Method) File=/Request Line=88");
}

/**
 * Gets variable from $_GET superglobal applying filters if needed
 *
 * @param string $name
 * @param string|array $filters
 * @return mixed
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
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Request", "getQuery", 0);
	phalcon_step_over("Phalcon_Request::getQuery (If) File=/Request Line=89");
	phalcon_init_global("_GET" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_GET", sizeof("_GET"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset(a0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getQuery (Block) File=/Request Line=89");
		phalcon_step_over("Phalcon_Request::getQuery (If) File=/Request Line=90");
		if (zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Request::getQuery (Block) File=/Request Line=90");
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "getfilter" TSRMLS_CC);
			PHALCON_CALL_METHOD(r1, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(r1, "sanizite" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch(r2, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r2);
			p0[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
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
			phalcon_step_over("Phalcon_Request::getQuery (Block) File=/Request Line=92");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			PHALCON_RETURN_CTOR(r3);
		}
	} else {
		phalcon_step_over("Phalcon_Request::getQuery (Block) File=/Request Line=95");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getQuery (Method) File=/Request Line=106");
}

/**
 * Gets variable from $_SERVER superglobal
 *
 * @param string $name
 * @return mixed
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
	phalcon_step_over("Phalcon_Request::getServer (If) File=/Request Line=107");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset(a0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getServer (Block) File=/Request Line=107");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::getServer (Block) File=/Request Line=109");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getServer (Method) File=/Request Line=120");
}

/**
 * Gets HTTP header from request data
 *
 * @param string $header
 * @return string
 */
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
	phalcon_step_over("Phalcon_Request::getHeader (If) File=/Request Line=121");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset(a0, v0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getHeader (Block) File=/Request Line=121");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::getHeader (Block) File=/Request Line=123");
		phalcon_step_over("Phalcon_Request::getHeader (If) File=/Request Line=124");
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CONCAT_LEFT(r1, "HTTP_", v0);
		eval_int = phalcon_array_isset(a0, r1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::getHeader (Block) File=/Request Line=124");
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_CONCAT_LEFT(r2, "HTTP_", v0);
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			PHALCON_RETURN_CTOR(r3);
		} else {
			phalcon_step_over("Phalcon_Request::getHeader (Block) File=/Request Line=126");
			phalcon_step_out_entry();
			RETURN_STRING("", 1);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getHeader (Method) File=/Request Line=137");
}

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getScheme){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "getScheme", 0);
	phalcon_step_over("Phalcon_Request::getScheme (If) File=/Request Line=138");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_HTTPS", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(r0, "on")) {
		phalcon_step_over("Phalcon_Request::getScheme (Block) File=/Request Line=138");
		phalcon_step_out_entry();
		RETURN_STRING("https", 1);
	} else {
		phalcon_step_over("Phalcon_Request::getScheme (Block) File=/Request Line=140");
		phalcon_step_out_entry();
		RETURN_STRING("http", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getScheme (Method) File=/Request Line=150");
}

/**
 * Checks whether request has been made using ajax
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isAjax){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "isAjax", 0);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getheader" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_X_REQUESTED_WITH", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getheader", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "XMLHttpRequest", 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Request::isAjax (Method) File=/Request Line=159");
}

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isSoapRequested){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL };
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "isSoapRequested", 0);
	phalcon_step_over("Phalcon_Request::isSoapRequested (If) File=/Request Line=160");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset_string(a0, "HTTP_SOAPACTION", strlen("HTTP_SOAPACTION")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::isSoapRequested (Block) File=/Request Line=160");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isSoapRequested (Block) File=/Request Line=162");
		phalcon_step_over("Phalcon_Request::isSoapRequested (If) File=/Request Line=163");
		eval_int = phalcon_array_isset_string(a0, "CONTENT_TYPE", strlen("CONTENT_TYPE")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::isSoapRequested (Block) File=/Request Line=163");
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, a0, "CONTENT_TYPE", strlen("CONTENT_TYPE"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p0[0] = r1;
			phalcon_debug_param(r1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p0[1]);
			ZVAL_STRING(p0[1], "application/soap+xml", 1);
			PHALCON_CALL_FUNC_PARAMS(r0, "strpos", 2, p0);
			phalcon_debug_vdump("strpos > ", r0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_BOOL(t0, 0);
			PHALCON_ALLOC_ZVAL(r2);
			is_not_identical_function(r2, t0, r0 TSRMLS_CC);
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
			phalcon_step_over("Phalcon_Request::isSoapRequested (Block) File=/Request Line=165");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isSoapRequested (Method) File=/Request Line=176");
}

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isSecureRequest){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isSecureRequest", 0);
	phalcon_step_over("Phalcon_Request::isSecureRequest (If) File=/Request Line=177");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getscheme" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "https", 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_identical_function(r1, t0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Request::isSecureRequest (Block) File=/Request Line=177");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isSecureRequest (Block) File=/Request Line=179");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isSecureRequest (Method) File=/Request Line=189");
}

/**
 * Gets HTTP raws request body
 *
 * @return string
 */
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
	phalcon_step_over("Phalcon_Request::getRawBody (Method) File=/Request Line=198");
}

/**
 * Gets active server address IP
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getServerAddress){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getServerAddress", 0);
	phalcon_step_over("Phalcon_Request::getServerAddress (If) File=/Request Line=199");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset_string(a0, "SERVER_ADDR", strlen("SERVER_ADDR")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getServerAddress (Block) File=/Request Line=199");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "SERVER_ADDR", strlen("SERVER_ADDR"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::getServerAddress (Block) File=/Request Line=201");
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
	phalcon_step_over("Phalcon_Request::getServerAddress (Method) File=/Request Line=211");
}

/**
 * Gets active server name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getServerName){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getServerName", 0);
	phalcon_step_over("Phalcon_Request::getServerName (If) File=/Request Line=212");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset_string(a0, "SERVER_NAME", strlen("SERVER_NAME")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getServerName (Block) File=/Request Line=212");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "SERVER_NAME", strlen("SERVER_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::getServerName (Block) File=/Request Line=214");
		phalcon_step_out_entry();
		RETURN_STRING("localhost", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getServerName (Method) File=/Request Line=224");
}

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getHttpHost){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "getHttpHost", 0);
	phalcon_step_over("Phalcon_Request::getHttpHost (Assignment) File=/Request Line=225");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getscheme" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	phalcon_debug_assign("$scheme", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getHttpHost (Assignment) File=/Request Line=226");
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "HTTP_SERVER_NAME", 1);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "getserver", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r1);
	phalcon_debug_assign("$name", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getHttpHost (Assignment) File=/Request Line=227");
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p2[0]);
	ZVAL_STRING(p2[0], "HTTP_SERVER_PORT", 1);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getserver", 1, p2, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r2);
	phalcon_debug_assign("$port", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getHttpHost (If) File=/Request Line=228");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "http", 1);
	PHALCON_ALLOC_ZVAL(r3);
	is_equal_function(r3, v0, t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 80);
	PHALCON_ALLOC_ZVAL(r4);
	is_equal_function(r4, v2, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	phalcon_and_function(r5, r3, r4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, "https", 1);
	PHALCON_ALLOC_ZVAL(r6);
	is_equal_function(r6, v0, t2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 443);
	PHALCON_ALLOC_ZVAL(r7);
	is_equal_function(r7, v2, t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r8);
	phalcon_and_function(r8, r6, r7 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r9);
	ZVAL_BOOL(r9, zend_is_true(r5) || zend_is_true(r8));
	if (zend_is_true(r9)) {
		phalcon_step_over("Phalcon_Request::getHttpHost (Block) File=/Request Line=228");
		phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(v1);
	} else {
		phalcon_step_over("Phalcon_Request::getHttpHost (Block) File=/Request Line=230");
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
	phalcon_step_over("Phalcon_Request::getHttpHost (Method) File=/Request Line=240");
}

/**
 * Gets most possibly client IPv4 Address
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getClientAddress){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getClientAddress", 0);
	phalcon_step_over("Phalcon_Request::getClientAddress (If) File=/Request Line=241");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset_string(a0, "HTTP_X_FORWARDED_FOR", strlen("HTTP_X_FORWARDED_FOR")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getClientAddress (Block) File=/Request Line=241");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_X_FORWARDED_FOR", strlen("HTTP_X_FORWARDED_FOR"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::getClientAddress (Block) File=/Request Line=243");
		phalcon_step_over("Phalcon_Request::getClientAddress (If) File=/Request Line=244");
		eval_int = phalcon_array_isset_string(a0, "REMOTE_ADDR", strlen("REMOTE_ADDR")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::getClientAddress (Block) File=/Request Line=244");
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, a0, "REMOTE_ADDR", strlen("REMOTE_ADDR"), PHALCON_NOISY_FETCH TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
			phalcon_step_out_entry();
			PHALCON_RETURN_CTOR(r1);
		} else {
			phalcon_step_over("Phalcon_Request::getClientAddress (Block) File=/Request Line=246");
			phalcon_step_out_entry();
			RETURN_STRING("", 1);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getClientAddress (Method) File=/Request Line=257");
}

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getMethod){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getMethod", 0);
	phalcon_step_over("Phalcon_Request::getMethod (If) File=/Request Line=258");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset_string(a0, "REQUEST_METHOD", strlen("REQUEST_METHOD")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getMethod (Block) File=/Request Line=258");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "REQUEST_METHOD", strlen("REQUEST_METHOD"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::getMethod (Block) File=/Request Line=260");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getMethod (Method) File=/Request Line=270");
}

/**
 * Gets HTTP user agent used to made the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getUserAgent){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getUserAgent", 0);
	phalcon_step_over("Phalcon_Request::getUserAgent (If) File=/Request Line=271");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset_string(a0, "HTTP_USER_AGENT", strlen("HTTP_USER_AGENT")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getUserAgent (Block) File=/Request Line=271");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_USER_AGENT", strlen("HTTP_USER_AGENT"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::getUserAgent (Block) File=/Request Line=273");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getUserAgent (Method) File=/Request Line=283");
}

/**
 * Checks whether HTTP method is POST
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isPost){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isPost", 0);
	phalcon_step_over("Phalcon_Request::isPost (If) File=/Request Line=284");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(r0, "POST")) {
		phalcon_step_over("Phalcon_Request::isPost (Block) File=/Request Line=284");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isPost (Block) File=/Request Line=286");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isPost (Method) File=/Request Line=296");
}

/**
 * Checks whether HTTP method is GET
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isGet){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isGet", 0);
	phalcon_step_over("Phalcon_Request::isGet (If) File=/Request Line=297");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(r0, "GET")) {
		phalcon_step_over("Phalcon_Request::isGet (Block) File=/Request Line=297");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isGet (Block) File=/Request Line=299");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isGet (Method) File=/Request Line=309");
}

/**
 * Checks whether HTTP method is PUT
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isPut){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isPut", 0);
	phalcon_step_over("Phalcon_Request::isPut (If) File=/Request Line=310");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(r0, "PUT")) {
		phalcon_step_over("Phalcon_Request::isPut (Block) File=/Request Line=310");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isPut (Block) File=/Request Line=312");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isPut (Method) File=/Request Line=322");
}

/**
 * Checks whether HTTP method is HEAD
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isHead){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isHead", 0);
	phalcon_step_over("Phalcon_Request::isHead (If) File=/Request Line=323");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(r0, "HEAD")) {
		phalcon_step_over("Phalcon_Request::isHead (Block) File=/Request Line=323");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isHead (Block) File=/Request Line=325");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isHead (Method) File=/Request Line=335");
}

/**
 * Checks whether HTTP method is DELETE
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isDelete){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isDelete", 0);
	phalcon_step_over("Phalcon_Request::isDelete (If) File=/Request Line=336");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(r0, "DELETE")) {
		phalcon_step_over("Phalcon_Request::isDelete (Block) File=/Request Line=336");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isDelete (Block) File=/Request Line=338");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isDelete (Method) File=/Request Line=348");
}

/**
 * Checks whether HTTP method is OPTIONS
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isOptions){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Request", "isOptions", 0);
	phalcon_step_over("Phalcon_Request::isOptions (If) File=/Request Line=349");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmethod" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(r0, "OPTIONS")) {
		phalcon_step_over("Phalcon_Request::isOptions (Block) File=/Request Line=349");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Request::isOptions (Block) File=/Request Line=351");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::isOptions (Method) File=/Request Line=361");
}

/**
 * Checks whether request include attached files
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, hasFiles){

	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval **gv0;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Request", "hasFiles", 0);
	phalcon_step_over("Phalcon_Request::hasFiles (If) File=/Request Line=362");
	phalcon_init_global("_FILES" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_FILES", sizeof("_FILES"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	if (zend_is_true(a0)) {
		phalcon_step_over("Phalcon_Request::hasFiles (Block) File=/Request Line=362");
		PHALCON_ALLOC_ZVAL(r1);
		p0[0] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "count", 1, p0);
		phalcon_debug_vdump("count > ", r1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_ALLOC_ZVAL(r2);
		is_smaller_function(r2, t0, r1 TSRMLS_CC);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL(t1);
			ZVAL_BOOL(t1, 1);
			r0 = t1;
		} else {
			PHALCON_ALLOC_ZVAL(t2);
			ZVAL_BOOL(t2, 0);
			r0 = t2;
		}
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::hasFiles (Block) File=/Request Line=364");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::hasFiles (Method) File=/Request Line=374");
}

/**
 * Gets attached files as Phalcon_UploadFile clases
 *
 * @return array
 */
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
	phalcon_step_over("Phalcon_Request::getUploadedFiles (If) File=/Request Line=375");
	phalcon_init_global("_FILES" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_FILES", sizeof("_FILES"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	if (zend_is_true(a0)) {
		phalcon_step_over("Phalcon_Request::getUploadedFiles (Block) File=/Request Line=375");
		phalcon_step_over("Phalcon_Request::getUploadedFiles (Assignment) File=/Request Line=376");
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		PHALCON_CPY_WRT_PARAM(v0, a1);
		phalcon_debug_assign("$files", a1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Request::getUploadedFiles (Foreach) File=/Request Line=377");
		FOREACH_V(a0, ac0, fes2, fee2, ah0, hp0, v1)
			phalcon_step_over("Phalcon_Request::getUploadedFiles (Block) File=/Request Line=377");
			phalcon_step_over("Phalcon_Request::getUploadedFiles (Assignment) File=/Request Line=378");
			ce0 = zend_fetch_class("phalcon_uploadfile", strlen("phalcon_uploadfile"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
			if (!i0) {
				PHALCON_ALLOC_ZVAL(i0);
			} else {
				if (Z_REFCOUNT_P(i0) > 1) {
					PHALCON_SEPARATE(i0);
				} else {
					FREE_ZVAL(i0);
					PHALCON_ALLOC_ZVAL(i0);
				}
			}
			object_init_ex(i0, ce0);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			Z_ADDREF_P(v1);
			p0[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
			PHALCON_CPY_WRT(v2, i0);
			phalcon_debug_assign("$controllerFile", i0 TSRMLS_CC);
			phalcon_step_over("Phalcon_Request::getUploadedFiles (Assignment) File=/Request Line=379");
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				PHALCON_SEPARATE_PARAM(v0);
				phalcon_array_append(v0, copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes2, fee2, ah0, hp0);
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
		phalcon_step_over("Phalcon_Request::getUploadedFiles (Block) File=/Request Line=382");
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
	phalcon_step_over("Phalcon_Request::getUploadedFiles (Method) File=/Request Line=392");
}

/**
 * Gets web page which refers active request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getHTTPReferer){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Request", "getHTTPReferer", 0);
	phalcon_step_over("Phalcon_Request::getHTTPReferer (If) File=/Request Line=393");
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset_string(a0, "HTTP_REFERER", strlen("HTTP_REFERER")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Request::getHTTPReferer (Block) File=/Request Line=393");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_REFERER", strlen("HTTP_REFERER"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r0);
	} else {
		phalcon_step_over("Phalcon_Request::getHTTPReferer (Block) File=/Request Line=395");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Request::getHTTPReferer (Method) File=/Request Line=405");
}

/**
 * Gets array with mime/types and their quality accepted by the browser/client.
 *
 * @return array
 */
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
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=/Request Line=406");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_ACCEPT", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	phalcon_debug_assign("$httpAccept", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=/Request Line=407");
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "/,\\s*/", 1);
	p1[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "preg_split", 2, p1);
	phalcon_debug_vdump("preg_split > ", r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r1);
	phalcon_debug_assign("$accepted", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=/Request Line=408");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	phalcon_debug_assign("$returnedAccept", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Foreach) File=/Request Line=409");
	FOREACH_V(v1, ac0, fes3, fee3, ah0, hp0, v3)
		phalcon_step_over("Phalcon_Request::getAcceptableContent (Block) File=/Request Line=409");
		phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=/Request Line=410");
		if (!r2) {
			PHALCON_ALLOC_ZVAL(r2);
		} else {
			if (Z_REFCOUNT_P(r2) > 1) {
				PHALCON_SEPARATE(r2);
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
		p2[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r2, "explode", 2, p2);
		phalcon_debug_vdump("explode > ", r2 TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r2);
		phalcon_debug_assign("$acceptParts", r2 TSRMLS_CC);
		phalcon_step_over("Phalcon_Request::getAcceptableContent (If) File=/Request Line=411");
		eval_int = phalcon_array_isset_long(v4, 1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::getAcceptableContent (Block) File=/Request Line=411");
			phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=/Request Line=412");
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					PHALCON_SEPARATE(r3);
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					PHALCON_SEPARATE(r4);
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
			PHALCON_CPY_WRT(v5, r3);
			phalcon_debug_assign("$quality", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Request::getAcceptableContent (Block) File=/Request Line=413");
			phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=/Request Line=414");
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
		phalcon_step_over("Phalcon_Request::getAcceptableContent (Assignment) File=/Request Line=416");
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
		if (!r5) {
			PHALCON_ALLOC_ZVAL(r5);
		} else {
			if (Z_REFCOUNT_P(r5) > 1) {
				PHALCON_SEPARATE(r5);
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
			PHALCON_SEPARATE(a1);
			add_assoc_zval(a1, "accept", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(a1);
			add_assoc_zval(a1, "quality", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, a1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE(v2);
			phalcon_array_append(v2, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes3, fee3, ah0, hp0);
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
	phalcon_step_over("Phalcon_Request::getAcceptableContent (Method) File=/Request Line=429");
}

/**
 * Gets best mime/type accepted by the browser/client.
 *
 * @return array
 */
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
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=/Request Line=430");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=/Request Line=431");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=/Request Line=432");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Foreach) File=/Request Line=433");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getacceptablecontent" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getacceptablecontent", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	FOREACH_V(r0, ac0, fes4, fee4, ah0, hp0, v3)
		phalcon_step_over("Phalcon_Request::getBestQualityAccept (Block) File=/Request Line=433");
		phalcon_step_over("Phalcon_Request::getBestQualityAccept (If) File=/Request Line=434");
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
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
				PHALCON_SEPARATE(r1);
			}
		}
		is_equal_function(r1, v0, t0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (Block) File=/Request Line=434");
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=/Request Line=435");
			if (!r2) {
				PHALCON_ALLOC_ZVAL(r2);
			} else {
				if (Z_REFCOUNT_P(r2) > 1) {
					PHALCON_SEPARATE(r2);
				} else {
					FREE_ZVAL(r2);
					PHALCON_ALLOC_ZVAL(r2);
				}
			}
			phalcon_array_fetch_string(r2, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r2);
			phalcon_debug_assign("$selectedAcceptQuality", r2 TSRMLS_CC);
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=/Request Line=436");
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					PHALCON_SEPARATE(r3);
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			phalcon_array_fetch_string(r3, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r3);
			phalcon_debug_assign("$selectedAcceptName", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (Block) File=/Request Line=437");
			phalcon_step_over("Phalcon_Request::getBestQualityAccept (If) File=/Request Line=438");
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					PHALCON_SEPARATE(r4);
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			phalcon_array_fetch_string(r4, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!r5) {
				PHALCON_ALLOC_ZVAL(r5);
			} else {
				if (Z_REFCOUNT_P(r5) > 1) {
					SEPARATE_ZVAL(&r5);
				} else {
					if (Z_TYPE_P(r5) != IS_BOOL) {
						FREE_ZVAL(r5);
						PHALCON_ALLOC_ZVAL(r5);
					}
				}
			}
			is_smaller_function(r5, v1, r4 TSRMLS_CC);
			if (zend_is_true(r5)) {
				phalcon_step_over("Phalcon_Request::getBestQualityAccept (Block) File=/Request Line=438");
				phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=/Request Line=439");
				if (!r6) {
					PHALCON_ALLOC_ZVAL(r6);
				} else {
					if (Z_REFCOUNT_P(r6) > 1) {
						PHALCON_SEPARATE(r6);
					} else {
						FREE_ZVAL(r6);
						PHALCON_ALLOC_ZVAL(r6);
					}
				}
				phalcon_array_fetch_string(r6, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v1, r6);
				phalcon_debug_assign("$selectedAcceptQuality", r6 TSRMLS_CC);
				phalcon_step_over("Phalcon_Request::getBestQualityAccept (Assignment) File=/Request Line=440");
				if (!r7) {
					PHALCON_ALLOC_ZVAL(r7);
				} else {
					if (Z_REFCOUNT_P(r7) > 1) {
						PHALCON_SEPARATE(r7);
					} else {
						FREE_ZVAL(r7);
						PHALCON_ALLOC_ZVAL(r7);
					}
				}
				phalcon_array_fetch_string(r7, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v2, r7);
				phalcon_debug_assign("$selectedAcceptName", r7 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Request::getBestQualityAccept (PreIncDecOp) File=/Request Line=443");
		PHALCON_SEPARATE_PARAM(v0);
		increment_function(v0);
		phalcon_debug_vdump("PreIncrementing $i", v0);
	END_FOREACH(ac0, fes4, fee4, ah0, hp0);
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Request::getBestQualityAccept (Method) File=/Request Line=453");
}

/**
 * Gets charsets array and their quality accepted by the browser/client.
 *
 * @return array
 */
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
	phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=/Request Line=454");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getserver" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_ACCEPT_CHARSET", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	phalcon_debug_assign("$httpAcceptCharset", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=/Request Line=455");
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "/,\\s*/", 1);
	p1[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "preg_split", 2, p1);
	phalcon_debug_vdump("preg_split > ", r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r1);
	phalcon_debug_assign("$accepted", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=/Request Line=456");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	phalcon_debug_assign("$returnedAccept", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Request::getClientCharsets (Foreach) File=/Request Line=457");
	FOREACH_V(v1, ac0, fes5, fee5, ah0, hp0, v3)
		phalcon_step_over("Phalcon_Request::getClientCharsets (Block) File=/Request Line=457");
		phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=/Request Line=458");
		if (!r2) {
			PHALCON_ALLOC_ZVAL(r2);
		} else {
			if (Z_REFCOUNT_P(r2) > 1) {
				PHALCON_SEPARATE(r2);
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
		p2[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r2, "explode", 2, p2);
		phalcon_debug_vdump("explode > ", r2 TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r2);
		phalcon_debug_assign("$acceptParts", r2 TSRMLS_CC);
		phalcon_step_over("Phalcon_Request::getClientCharsets (If) File=/Request Line=459");
		eval_int = phalcon_array_isset_long(v4, 1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Request::getClientCharsets (Block) File=/Request Line=459");
			phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=/Request Line=460");
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					PHALCON_SEPARATE(r3);
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					PHALCON_SEPARATE(r4);
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
			PHALCON_CPY_WRT(v5, r3);
			phalcon_debug_assign("$quality", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Request::getClientCharsets (Block) File=/Request Line=461");
			phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=/Request Line=462");
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
		phalcon_step_over("Phalcon_Request::getClientCharsets (Assignment) File=/Request Line=464");
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
		if (!r5) {
			PHALCON_ALLOC_ZVAL(r5);
		} else {
			if (Z_REFCOUNT_P(r5) > 1) {
				PHALCON_SEPARATE(r5);
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
			PHALCON_SEPARATE(a1);
			add_assoc_zval(a1, "accept", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(a1);
			add_assoc_zval(a1, "quality", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, a1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE(v2);
			phalcon_array_append(v2, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes5, fee5, ah0, hp0);
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
	phalcon_step_over("Phalcon_Request::getClientCharsets (Method) File=/Request Line=477");
}

/**
 * Gets best charset accepted by the browser/client.
 *
 * @return string
 */
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
	phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=/Request Line=478");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=/Request Line=479");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=/Request Line=480");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	phalcon_step_over("Phalcon_Request::getBestQualityCharset (Foreach) File=/Request Line=481");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getclientcharsets" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getclientcharsets", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Request" TSRMLS_CC);
	FOREACH_V(r0, ac0, fes6, fee6, ah0, hp0, v3)
		phalcon_step_over("Phalcon_Request::getBestQualityCharset (Block) File=/Request Line=481");
		phalcon_step_over("Phalcon_Request::getBestQualityCharset (If) File=/Request Line=482");
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
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
				PHALCON_SEPARATE(r1);
			}
		}
		is_equal_function(r1, v0, t0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (Block) File=/Request Line=482");
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=/Request Line=483");
			if (!r2) {
				PHALCON_ALLOC_ZVAL(r2);
			} else {
				if (Z_REFCOUNT_P(r2) > 1) {
					PHALCON_SEPARATE(r2);
				} else {
					FREE_ZVAL(r2);
					PHALCON_ALLOC_ZVAL(r2);
				}
			}
			phalcon_array_fetch_string(r2, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r2);
			phalcon_debug_assign("$selectedCharsetQuality", r2 TSRMLS_CC);
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=/Request Line=484");
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					PHALCON_SEPARATE(r3);
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			phalcon_array_fetch_string(r3, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r3);
			phalcon_debug_assign("$selectedCharsetName", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (Block) File=/Request Line=485");
			phalcon_step_over("Phalcon_Request::getBestQualityCharset (If) File=/Request Line=486");
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					PHALCON_SEPARATE(r4);
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			phalcon_array_fetch_string(r4, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!r5) {
				PHALCON_ALLOC_ZVAL(r5);
			} else {
				if (Z_REFCOUNT_P(r5) > 1) {
					SEPARATE_ZVAL(&r5);
				} else {
					if (Z_TYPE_P(r5) != IS_BOOL) {
						FREE_ZVAL(r5);
						PHALCON_ALLOC_ZVAL(r5);
					}
				}
			}
			is_smaller_function(r5, v1, r4 TSRMLS_CC);
			if (zend_is_true(r5)) {
				phalcon_step_over("Phalcon_Request::getBestQualityCharset (Block) File=/Request Line=486");
				phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=/Request Line=487");
				if (!r6) {
					PHALCON_ALLOC_ZVAL(r6);
				} else {
					if (Z_REFCOUNT_P(r6) > 1) {
						PHALCON_SEPARATE(r6);
					} else {
						FREE_ZVAL(r6);
						PHALCON_ALLOC_ZVAL(r6);
					}
				}
				phalcon_array_fetch_string(r6, v3, "quality", strlen("quality"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v1, r6);
				phalcon_debug_assign("$selectedCharsetQuality", r6 TSRMLS_CC);
				phalcon_step_over("Phalcon_Request::getBestQualityCharset (Assignment) File=/Request Line=488");
				if (!r7) {
					PHALCON_ALLOC_ZVAL(r7);
				} else {
					if (Z_REFCOUNT_P(r7) > 1) {
						PHALCON_SEPARATE(r7);
					} else {
						FREE_ZVAL(r7);
						PHALCON_ALLOC_ZVAL(r7);
					}
				}
				phalcon_array_fetch_string(r7, v3, "accept", strlen("accept"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v2, r7);
				phalcon_debug_assign("$selectedCharsetName", r7 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Request::getBestQualityCharset (PreIncDecOp) File=/Request Line=491");
		PHALCON_SEPARATE_PARAM(v0);
		increment_function(v0);
		phalcon_debug_vdump("PreIncrementing $i", v0);
	END_FOREACH(ac0, fes6, fee6, ah0, hp0);
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v2);
	phalcon_step_out_entry();
}

