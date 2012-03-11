
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


	RETURN_NULL();
}

/**
 * Gets the singleton instance of Phalcon_Request
 *
 * @return Phalcon_Request
 */
PHP_METHOD(Phalcon_Request, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	t0 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_request_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		zend_update_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CTOR(t1);
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

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Returns active filter object used to sanitize input data
 *
 * @return Phalcon_Filter
 */
PHP_METHOD(Phalcon_Request, getFilter){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_filter", sizeof("_filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_filter_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			phalcon_update_property_zval(this_ptr, "_filter", strlen("_filter"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_filter", sizeof("_filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CTOR(t1);
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
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			PHALCON_CALL_METHOD(r1, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch(r2, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r2);
			p0[0] = r2;
			Z_ADDREF_P(v1);
			p0[1] = v1;
			PHALCON_CALL_METHOD_PARAMS(r0, r1, "sanitize", 2, p0, PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r0, 1, 0);
		} else {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CTOR(r3);
		}
	} else {
		RETURN_NULL();
	}
	RETURN_NULL();
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
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			PHALCON_CALL_METHOD(r1, this_ptr, "getfilter", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch(r2, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r2);
			p0[0] = r2;
			Z_ADDREF_P(v1);
			p0[1] = v1;
			PHALCON_CALL_METHOD_PARAMS(r0, r1, "sanizite", 2, p0, PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r0, 1, 0);
		} else {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CTOR(r3);
		}
	} else {
		RETURN_NULL();
	}
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CTOR(r0);
	} else {
		RETURN_NULL();
	}
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch(r0, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CTOR(r0);
	} else {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CONCAT_LEFT(r1, "HTTP_", v0);
		eval_int = phalcon_array_isset(a0, r1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_CONCAT_LEFT(r2, "HTTP_", v0);
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch(r3, a0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CTOR(r3);
		} else {
			RETURN_STRING("", 1);
		}
	}
	RETURN_NULL();
}

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getScheme){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_HTTPS", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "on")) {
		RETURN_STRING("https", 1);
	} else {
		RETURN_STRING("http", 1);
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_X_REQUESTED_WITH", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getheader", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "XMLHttpRequest", 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r1);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
		RETURN_TRUE;
	} else {
		eval_int = phalcon_array_isset_string(a0, "CONTENT_TYPE", strlen("CONTENT_TYPE")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, a0, "CONTENT_TYPE", strlen("CONTENT_TYPE"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p0[0] = r1;
			PHALCON_ALLOC_ZVAL(p0[1]);
			ZVAL_STRING(p0[1], "application/soap+xml", 1);
			PHALCON_CALL_FUNC_PARAMS(r0, "strpos", 2, p0);
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_BOOL(t0, 0);
			PHALCON_ALLOC_ZVAL(r2);
			is_not_identical_function(r2, t0, r0 TSRMLS_CC);
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r2);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		} else {
			RETURN_FALSE;
		}
	}
	RETURN_NULL();
}

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isSecureRequest){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "https", 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_identical_function(r1, t0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Gets HTTP raws request body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request, getRawBody){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "php://input", 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "file_get_contents", 1, p0);
	RETURN_ZVAL(r0, 1, 0);
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
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "SERVER_ADDR", strlen("SERVER_ADDR"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CTOR(r0);
	} else {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "localhost", 1);
		PHALCON_CALL_FUNC_PARAMS(r1, "gethostbyname", 1, p0);
		RETURN_ZVAL(r1, 1, 0);
	}
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "SERVER_NAME", strlen("SERVER_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CTOR(r0);
	} else {
		RETURN_STRING("localhost", 1);
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getscheme", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "HTTP_SERVER_NAME", 1);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "getserver", 1, p1, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_ALLOC_ZVAL(p2[0]);
	ZVAL_STRING(p2[0], "HTTP_SERVER_PORT", 1);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getserver", 1, p2, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r2);
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
		PHALCON_RETURN_CTOR(v1);
	} else {
		PHALCON_ALLOC_ZVAL(r10);
		phalcon_concat_vboth(r10, v1, ":", v2 TSRMLS_CC);
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
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_X_FORWARDED_FOR", strlen("HTTP_X_FORWARDED_FOR"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CTOR(r0);
	} else {
		eval_int = phalcon_array_isset_string(a0, "REMOTE_ADDR", strlen("REMOTE_ADDR")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, a0, "REMOTE_ADDR", strlen("REMOTE_ADDR"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CTOR(r1);
		} else {
			RETURN_STRING("", 1);
		}
	}
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "REQUEST_METHOD", strlen("REQUEST_METHOD"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CTOR(r0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_USER_AGENT", strlen("HTTP_USER_AGENT"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CTOR(r0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is POST
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isPost){

	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "POST")) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is GET
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isGet){

	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "GET")) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is PUT
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isPut){

	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "PUT")) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is HEAD
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isHead){

	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "HEAD")) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is DELETE
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isDelete){

	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "DELETE")) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Checks whether HTTP method is OPTIONS
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Request, isOptions){

	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getmethod", PHALCON_CALL_DEFAULT);
	if (PHALCON_COMPARE_STRING(r0, "OPTIONS")) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(r1);
		p0[0] = a0;
		PHALCON_CALL_FUNC_PARAMS(r1, "count", 1, p0);
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
		PHALCON_RETURN_CTOR(r0);
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		PHALCON_CPY_WRT_PARAM(v0, a1);
		FOREACH_V(a0, ac0, fes2, fee2, ah0, hp0, v1)
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
			Z_ADDREF_P(v1);
			p0[0] = v1;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
			PHALCON_CPY_WRT(v2, i0);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE_PARAM(v0);
				phalcon_array_append(v0, copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes2, fee2, ah0, hp0);
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
		PHALCON_ALLOC_ZVAL(a2);
		array_init(a2);
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
	RETURN_NULL();
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
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "HTTP_REFERER", strlen("HTTP_REFERER"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CTOR(r0);
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_ACCEPT", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "/,\\s*/", 1);
	p1[1] = v0;
	PHALCON_CALL_FUNC_PARAMS(r1, "preg_split", 2, p1);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	FOREACH_V(v1, ac0, fes3, fee3, ah0, hp0, v3)
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
		PHALCON_CALL_FUNC_PARAMS(r2, "explode", 2, p2);
		PHALCON_CPY_WRT(v4, r2);
		eval_int = phalcon_array_isset_long(v4, 1);
		if (eval_int) {
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
			PHALCON_PARAM_LONG(p3[1], 2);
			PHALCON_CALL_FUNC_PARAMS(r3, "substr", 2, p3);
			PHALCON_CPY_WRT(v5, r3);
		} else {
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
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a1);
			add_assoc_zval(a1, "accept", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a1);
			add_assoc_zval(a1, "quality", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, a1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(v2);
			phalcon_array_append(v2, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes3, fee3, ah0, hp0);
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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

	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getacceptablecontent", PHALCON_CALL_DEFAULT);
	FOREACH_V(r0, ac0, fes4, fee4, ah0, hp0, v3)
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
		} else {
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
			}
		}
		PHALCON_SEPARATE_PARAM(v0);
		increment_function(v0);
	END_FOREACH(ac0, fes4, fee4, ah0, hp0);
	PHALCON_RETURN_CTOR(v2);
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

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "HTTP_ACCEPT_CHARSET", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "getserver", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "/,\\s*/", 1);
	p1[1] = v0;
	PHALCON_CALL_FUNC_PARAMS(r1, "preg_split", 2, p1);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	FOREACH_V(v1, ac0, fes5, fee5, ah0, hp0, v3)
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
		PHALCON_CALL_FUNC_PARAMS(r2, "explode", 2, p2);
		PHALCON_CPY_WRT(v4, r2);
		eval_int = phalcon_array_isset_long(v4, 1);
		if (eval_int) {
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
			PHALCON_PARAM_LONG(p3[1], 2);
			PHALCON_CALL_FUNC_PARAMS(r3, "substr", 2, p3);
			PHALCON_CPY_WRT(v5, r3);
		} else {
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
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a1);
			add_assoc_zval(a1, "accept", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a1);
			add_assoc_zval(a1, "quality", copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, a1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(v2);
			phalcon_array_append(v2, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes5, fee5, ah0, hp0);
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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

	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getclientcharsets", PHALCON_CALL_DEFAULT);
	FOREACH_V(r0, ac0, fes6, fee6, ah0, hp0, v3)
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
		} else {
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
			}
		}
		PHALCON_SEPARATE_PARAM(v0);
		increment_function(v0);
	END_FOREACH(ac0, fes6, fee6, ah0, hp0);
	PHALCON_RETURN_CTOR(v2);
}

