
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
 * Phalcon_Controller
 *
 * Every application controller should extends this class that encapsulates all the controller functionality
 *
 * Controllers provide the “flow” between models and views. Controllers are responsible
 * for processing the incoming requests from the web browser, interrogating the models for data,
 * and passing that data on to the views for presentation.
 *
 *
 */

/**
 * Constructor for Phalcon_Controller
 *
 * @param Phalcon_Dispatcher $dispatcher
 * @param Phalcon_Request $request
 * @param Phalcon_Response $response
 * @param Phalcon_View $view
 * @param Phalcon_Model_Manager $model
 */
PHP_METHOD(Phalcon_Controller, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		RETURN_NULL();
	}

	if (!v3) {
		PHALCON_INIT_NULL(v3);
	}
	if (!v4) {
		PHALCON_INIT_NULL(v4);
	}
	
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), copy TSRMLS_CC);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "request", strlen("request"), copy TSRMLS_CC);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "response", strlen("response"), copy TSRMLS_CC);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v3, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "view", strlen("view"), copy TSRMLS_CC);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v4, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Forwards execution flow to another controller/action.
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Controller, _forward){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, t0, "forward", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_Controller, __get){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (phalcon_compare_strict_string(v0, "view")) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "_getviewcomponent", PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "view", strlen("view"), copy TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, this_ptr, "view", sizeof("view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	}
	if (phalcon_compare_strict_string(v0, "filter")) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_filter_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "filter", strlen("filter"), copy TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "filter", sizeof("filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t2)) {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p2[0] = v0;
		PHALCON_CALL_METHOD_PARAMS(r1, t3, "ismodel", 1, p2, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v0);
			p3[0] = v0;
			PHALCON_CALL_METHOD_PARAMS(r2, t4, "getmodel", 1, p3, PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r2, 1, 0);
		}
	}
	RETURN_NULL();
}

