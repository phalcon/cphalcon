
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
 * Php_Controller
 *
 * Every application controller should extends this class that encapsulates all the controller functionality
 */

/**
 * Constructor for Php_Controller
 *
 * @param Php_Dispatcher $dispatcher
 * @param Php_Request $request
 * @param Php_Response $response
 * @param Php_View $view
 * @param Php_Model_Manager $model
 */
PHP_METHOD(Phalcon_Controller, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;

	phalcon_step_over("Phalcon_Controller::__construct (ClassVariables) File=Library/Phalcon/Controller.php Line=10");
	phalcon_step_over("Phalcon_Controller::__construct (ClassVariables) File=Library/Phalcon/Controller.php Line=12");
	phalcon_step_over("Phalcon_Controller::__construct (ClassVariables) File=Library/Phalcon/Controller.php Line=14");
	phalcon_step_over("Phalcon_Controller::__construct (ClassVariables) File=Library/Phalcon/Controller.php Line=16");
	phalcon_step_over("Phalcon_Controller::__construct (ClassVariables) File=Library/Phalcon/Controller.php Line=18");
	phalcon_step_over("Phalcon_Controller::__construct (Method) File=Library/Phalcon/Controller.php Line=29");
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		RETURN_NULL();
	}

	if (!v3) {
		PHALCON_INIT_NULL(v3);
	}
	if (!v4) {
		PHALCON_INIT_NULL(v4);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v4 > ", v4 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller", "__construct", 0);
	phalcon_step_over("Phalcon_Controller::__construct (Assignment) File=Library/Phalcon/Controller.php Line=30");
	//$dispatcher
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Controller::__construct (Assignment) File=Library/Phalcon/Controller.php Line=31");
	//$request
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "request", strlen("request"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Controller::__construct (Assignment) File=Library/Phalcon/Controller.php Line=32");
	//$response
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "response", strlen("response"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Controller::__construct (Assignment) File=Library/Phalcon/Controller.php Line=33");
	//$view
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v3, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "view", strlen("view"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Controller::__construct (Assignment) File=Library/Phalcon/Controller.php Line=34");
	//$model
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v4, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller::__construct (Method) File=Library/Phalcon/Controller.php Line=42");
}

/**
 * Forwards execution flow to another controller/action
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller", "_forward", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
	phalcon_debug_method_call(t0, "forward" TSRMLS_CC);
	//$uri
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, t0, "forward", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Controller::_forward (Method) File=Library/Phalcon/Controller.php Line=51");
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller", "__get", 0);
	phalcon_step_over("Phalcon_Controller::__get (If) File=Library/Phalcon/Controller.php Line=52");
	//$propertyName
	if (phalcon_compare_strict_string(v0, "view")) {
		phalcon_step_over("Phalcon_Controller::__get (Block) File=Library/Phalcon/Controller.php Line=52");
		phalcon_step_over("Phalcon_Controller::__get (Assignment) File=Library/Phalcon/Controller.php Line=53");
		PHALCON_ALLOC_ZVAL(r0);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_getviewcomponent" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, this_ptr, "_getviewcomponent", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "view", strlen("view"), copy TSRMLS_CC);
		}
		//$this
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, this_ptr, "view", sizeof("view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t0);
		phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
		phalcon_step_out_entry();
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
	phalcon_step_over("Phalcon_Controller::__get (If) File=Library/Phalcon/Controller.php Line=56");
	//$propertyName
	if (phalcon_compare_strict_string(v0, "filter")) {
		phalcon_step_over("Phalcon_Controller::__get (Block) File=Library/Phalcon/Controller.php Line=56");
		phalcon_step_over("Phalcon_Controller::__get (Assignment) File=Library/Phalcon/Controller.php Line=57");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_filter_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "filter", strlen("filter"), copy TSRMLS_CC);
		}
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "filter", sizeof("filter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	}
	phalcon_step_over("Phalcon_Controller::__get (If) File=Library/Phalcon/Controller.php Line=60");
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	if (zend_is_true(t2)) {
		phalcon_step_over("Phalcon_Controller::__get (Block) File=Library/Phalcon/Controller.php Line=60");
		phalcon_step_over("Phalcon_Controller::__get (If) File=Library/Phalcon/Controller.php Line=61");
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
		phalcon_debug_method_call(t3, "ismodel" TSRMLS_CC);
		//$propertyName
		Z_ADDREF_P(v0);
		p2[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, t3, "ismodel", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Controller::__get (Block) File=Library/Phalcon/Controller.php Line=61");
			PHALCON_ALLOC_ZVAL(r2);
			//$this
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t4);
			phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
			phalcon_debug_method_call(t4, "getmodel" TSRMLS_CC);
			//$propertyName
			Z_ADDREF_P(v0);
			p3[0] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r2, t4, "getmodel", 1, p3, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Controller" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r2, 1, 0);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_out_entry();
}

