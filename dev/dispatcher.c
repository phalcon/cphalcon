
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
 * Phalcon_Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 * 
 */

PHP_METHOD(Phalcon_Dispatcher, __construct){

	zval *a0 = NULL, *a1 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "::__construct", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_dispatcher_class_entry, this_ptr, "_controllers", strlen("_controllers"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	zend_update_property(phalcon_dispatcher_class_entry, this_ptr, "_params", strlen("_params"), a1 TSRMLS_CC);
}

/**
 * Sets default controllers directory
 *
 * @param string $controllersDir
 */
PHP_METHOD(Phalcon_Dispatcher, setControllersDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Dispatcher", "setControllersDir", 0);
	phalcon_step_over("Phalcon_Dispatcher::setControllersDir (Assignment) File=/Dispatcher Line=57");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Dispatcher::setControllersDir (Method) File=/Dispatcher Line=65");
}

/**
 * Gets active controllers directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getControllersDir){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "getControllersDir", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Dispatcher::getControllersDir (Method) File=/Dispatcher Line=74");
}

/**
 * Sets base path for controllers dir
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_Dispatcher, setBasePath){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Dispatcher", "setBasePath", 0);
	phalcon_step_over("Phalcon_Dispatcher::setBasePath (Assignment) File=/Dispatcher Line=75");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Dispatcher::setBasePath (Method) File=/Dispatcher Line=83");
}

/**
 * Gets base path for controllers dir
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getBasePath){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "getBasePath", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Dispatcher::getBasePath (Method) File=/Dispatcher Line=90");
}

/**
 * Sets the controller name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher, setControllerName){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Dispatcher", "setControllerName", 0);
	phalcon_step_over("Phalcon_Dispatcher::setControllerName (Assignment) File=/Dispatcher Line=91");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Dispatcher::setControllerName (Method) File=/Dispatcher Line=99");
}

/**
 * Gets last dispacthed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getControllerName){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "getControllerName", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Dispatcher::getControllerName (Method) File=/Dispatcher Line=108");
}

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Dispatcher", "setActionName", 0);
	phalcon_step_over("Phalcon_Dispatcher::setActionName (Assignment) File=/Dispatcher Line=109");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Dispatcher::setActionName (Method) File=/Dispatcher Line=117");
}

/**
 * Gets last dispacthed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "getActionName", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Dispatcher::getActionName (Method) File=/Dispatcher Line=126");
}

/**
 * Sets action params to be dispatch
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Dispatcher", "setParams", 0);
	phalcon_step_over("Phalcon_Dispatcher::setParams (Assignment) File=/Dispatcher Line=127");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Dispatcher::setParams (Method) File=/Dispatcher Line=135");
}

/**
 * Gets action params
     *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getParams){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "getParams", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Dispatcher::getParams (Method) File=/Dispatcher Line=148");
}

/**
 * Dispatchs a action controller taking care of routing
 *
 * @param Phalcon_Request $request
 * @param Phalcon_Response $response
 * @param Phalcon_View $view
 * @param Phalcon_Model_Manager $model
 * @return Phalcon_Controller
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL, NULL, NULL, NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL }, *p11[] = { NULL };
	int eval_int;
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	if (!v2) {
		PHALCON_INIT_NULL(v2);
	}
	if (!v3) {
		PHALCON_INIT_NULL(v3);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Dispatcher", "dispatch", 0);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=150");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r0);
	v4 = r0;
	phalcon_debug_assign("$controllersDir", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=152");
	PHALCON_INIT_NULL(v5);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=153");
	PHALCON_INIT_NULL(v6);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=154");
	PHALCON_ALLOC_ZVAL(v7);
	ZVAL_LONG(v7, 0);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=155");
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (While) File=/Dispatcher Line=156");
	ws0:
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_finished", sizeof("_finished")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_BOOLEAN_NOT_FUNCTION(r1, t2);
	if (!zend_is_true(r1)) {
		goto we0;
	}
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=156");
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=158");
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=160");
	if (!t3) {
		PHALCON_ALLOC_ZVAL(t3);
	} else {
		if (Z_REFCOUNT_P(t3) > 1) {
			{
				zval *orig_ptr = t3;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t3);
					*t3 = *orig_ptr;
					zval_copy_ctor(t3);
					Z_SET_REFCOUNT_P(t3, 1);
					Z_UNSET_ISREF_P(t3);
				}
			}
		} else {
			FREE_ZVAL(t3);
			PHALCON_ALLOC_ZVAL(t3);
		}
	}
	phalcon_read_property(t3, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v8) {
		Z_DELREF_P(v8);
		if (!Z_REFCOUNT_P(v8)) {
			FREE_ZVAL(v8);
		}
	}
	Z_ADDREF_P(t3);
	v8 = t3;
	phalcon_debug_assign("$controllerName", t3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=161");
	if (!zend_is_true(v8)) {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=161");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=162");
		if (!t4) {
			PHALCON_ALLOC_ZVAL(t4);
		} else {
			if (Z_REFCOUNT_P(t4) > 1) {
				{
					zval *orig_ptr = t4;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(t4);
						*t4 = *orig_ptr;
						zval_copy_ctor(t4);
						Z_SET_REFCOUNT_P(t4, 1);
						Z_UNSET_ISREF_P(t4);
					}
				}
			} else {
				FREE_ZVAL(t4);
				PHALCON_ALLOC_ZVAL(t4);
			}
		}
		phalcon_read_property(t4, this_ptr, "_defaultController", sizeof("_defaultController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v8) {
			Z_DELREF_P(v8);
			if (!Z_REFCOUNT_P(v8)) {
				FREE_ZVAL(v8);
			}
		}
		Z_ADDREF_P(t4);
		v8 = t4;
		phalcon_debug_assign("$controllerName", t4 TSRMLS_CC);
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=163");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=166");
	if (!t5) {
		PHALCON_ALLOC_ZVAL(t5);
	} else {
		if (Z_REFCOUNT_P(t5) > 1) {
			{
				zval *orig_ptr = t5;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t5);
					*t5 = *orig_ptr;
					zval_copy_ctor(t5);
					Z_SET_REFCOUNT_P(t5, 1);
					Z_UNSET_ISREF_P(t5);
				}
			}
		} else {
			FREE_ZVAL(t5);
			PHALCON_ALLOC_ZVAL(t5);
		}
	}
	phalcon_read_property(t5, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v9) {
		Z_DELREF_P(v9);
		if (!Z_REFCOUNT_P(v9)) {
			FREE_ZVAL(v9);
		}
	}
	Z_ADDREF_P(t5);
	v9 = t5;
	phalcon_debug_assign("$controllers", t5 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=167");
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
	Z_ADDREF_P(v8);
	p0[0] = v8;
	phalcon_debug_param(v8 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_utils", "camelize", 1, p0);
	phalcon_debug_vdump("StaticReturn > ", r2 TSRMLS_CC);
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
	phalcon_concat_right(r3, r2, "Controller" TSRMLS_CC);
	if (v10) {
		Z_DELREF_P(v10);
		if (!Z_REFCOUNT_P(v10)) {
			FREE_ZVAL(v10);
		}
	}
	Z_ADDREF_P(r3);
	v10 = r3;
	phalcon_debug_assign("$controllerClass", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=168");
	eval_int = phalcon_array_isset(v9, v10);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=168");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=171");
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
		concat_function(r4, v4, v10 TSRMLS_CC);
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
		phalcon_concat_right(r5, r4, ".php" TSRMLS_CC);
		if (v11) {
			Z_DELREF_P(v11);
			if (!Z_REFCOUNT_P(v11)) {
				FREE_ZVAL(v11);
			}
		}
		Z_ADDREF_P(r5);
		v11 = r5;
		phalcon_debug_assign("$controllerPath", r5 TSRMLS_CC);
		phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=172");
		phalcon_debug_vdump("FileExists? > ", v11 TSRMLS_CC);
		if (phalcon_file_exists(v11 TSRMLS_CC) == SUCCESS) {
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=172");
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Require) File=/Dispatcher Line=173");
			phalcon_debug_vdump("Requiring File > ", v11 TSRMLS_CC);
			phalcon_require(v11 TSRMLS_CC);
			if (EG(exception) || EG(exit_status) == 255) {
				return;
			}
		} else {
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=174");
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Throw) File=/Dispatcher Line=175");
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
			object_init_ex(i0, phalcon_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
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
			phalcon_concat_both(r6,  "File for controller class ", v10, " doesn't exists" TSRMLS_CC);
			Z_ADDREF_P(r6);
			p1[0] = r6;
			phalcon_debug_param(r6 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
		phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=178");
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
		Z_ADDREF_P(v10);
		p2[0] = v10;
		phalcon_debug_param(v10 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p2[1], 0);
		PHALCON_CALL_FUNC_PARAMS(r7, "class_exists", strlen("class_exists"), 2, p2);
		phalcon_debug_vdump("class_exists > ", r7 TSRMLS_CC);
		if (!zend_is_true(r7)) {
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=178");
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Throw) File=/Dispatcher Line=179");
			if (!i1) {
				PHALCON_ALLOC_ZVAL(i1);
			} else {
				if (Z_REFCOUNT_P(i1) > 1) {
					{
						zval *orig_ptr = i1;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(i1);
							*i1 = *orig_ptr;
							zval_copy_ctor(i1);
							Z_SET_REFCOUNT_P(i1, 1);
							Z_UNSET_ISREF_P(i1);
						}
					}
				} else {
					FREE_ZVAL(i1);
					PHALCON_ALLOC_ZVAL(i1);
				}
			}
			object_init_ex(i1, phalcon_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
			if (!r8) {
				PHALCON_ALLOC_ZVAL(r8);
			} else {
				if (Z_REFCOUNT_P(r8) > 1) {
					{
						zval *orig_ptr = r8;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r8);
							*r8 = *orig_ptr;
							zval_copy_ctor(r8);
							Z_SET_REFCOUNT_P(r8, 1);
							Z_UNSET_ISREF_P(r8);
						}
					}
				} else {
					FREE_ZVAL(r8);
					PHALCON_ALLOC_ZVAL(r8);
				}
			}
			phalcon_concat_both(r8,  "Class ", v10, " was not found on controller file" TSRMLS_CC);
			Z_ADDREF_P(r8);
			p3[0] = r8;
			phalcon_debug_param(r8 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			zend_throw_exception_object(i1 TSRMLS_CC);
			Z_ADDREF_P(i1);
			return;
		}
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=182");
		ce0 = zend_fetch_class(Z_STRVAL_P(v10), Z_STRLEN_P(v10), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		if (!i2) {
			PHALCON_ALLOC_ZVAL(i2);
		} else {
			if (Z_REFCOUNT_P(i2) > 1) {
				{
					zval *orig_ptr = i2;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(i2);
						*i2 = *orig_ptr;
						zval_copy_ctor(i2);
						Z_SET_REFCOUNT_P(i2, 1);
						Z_UNSET_ISREF_P(i2);
					}
				}
			} else {
				FREE_ZVAL(i2);
				PHALCON_ALLOC_ZVAL(i2);
			}
		}
		object_init_ex(i2, ce0);
		phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
		phalcon_debug_method_call(i2, "__construct" TSRMLS_CC);
		Z_ADDREF_P(this_ptr);
		p4[0] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		Z_ADDREF_P(v0);
		p4[1] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		Z_ADDREF_P(v1);
		p4[2] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		Z_ADDREF_P(v2);
		p4[3] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		Z_ADDREF_P(v3);
		p4[4] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 5, p4, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(i2);
		v6 = i2;
		phalcon_debug_assign("$controller", i2 TSRMLS_CC);
		phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=183");
		if (!t6) {
			PHALCON_ALLOC_ZVAL(t6);
		} else {
			if (Z_REFCOUNT_P(t6) > 1) {
				SEPARATE_ZVAL(&t6);
			} else {
				if (Z_TYPE_P(t6) != IS_STRING) {
					FREE_ZVAL(t6);
					PHALCON_ALLOC_ZVAL(t6);
				}
			}
		}
		ZVAL_STRING(t6, "initialize", 0);
		if (phalcon_method_exists(v6, t6 TSRMLS_CC) == SUCCESS) {
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=183");
			phalcon_step_over("Phalcon_Dispatcher::dispatch (MethodCall) File=/Dispatcher Line=184");
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			phalcon_debug_method_call(v6, "initialize" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v6, "initialize", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=187");
		if (!t7) {
			PHALCON_ALLOC_ZVAL(t7);
		} else {
			if (Z_REFCOUNT_P(t7) > 1) {
				{
					zval *orig_ptr = t7;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(t7);
						*t7 = *orig_ptr;
						zval_copy_ctor(t7);
						Z_SET_REFCOUNT_P(t7, 1);
						Z_UNSET_ISREF_P(t7);
					}
				}
			} else {
				FREE_ZVAL(t7);
				PHALCON_ALLOC_ZVAL(t7);
			}
		}
		phalcon_read_property(t7, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v6, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = t7;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t7);
					*t7 = *orig_ptr;
					zval_copy_ctor(t7);
					Z_SET_REFCOUNT_P(t7, 1);
					Z_UNSET_ISREF_P(t7);
				}
			}
			phalcon_array_update(t7, v10, copy TSRMLS_CC);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t7, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_controllers", strlen("_controllers"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=189");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=190");
		if (!r9) {
			PHALCON_ALLOC_ZVAL(r9);
		} else {
			if (Z_REFCOUNT_P(r9) > 1) {
				{
					zval *orig_ptr = r9;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r9);
						*r9 = *orig_ptr;
						zval_copy_ctor(r9);
						Z_SET_REFCOUNT_P(r9, 1);
						Z_UNSET_ISREF_P(r9);
					}
				}
			} else {
				FREE_ZVAL(r9);
				PHALCON_ALLOC_ZVAL(r9);
			}
		}
		phalcon_array_fetch(r9, v9, v10, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(r9);
		v6 = r9;
		phalcon_debug_assign("$controller", r9 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=193");
	if (!t8) {
		PHALCON_ALLOC_ZVAL(t8);
	} else {
		if (Z_REFCOUNT_P(t8) > 1) {
			{
				zval *orig_ptr = t8;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t8);
					*t8 = *orig_ptr;
					zval_copy_ctor(t8);
					Z_SET_REFCOUNT_P(t8, 1);
					Z_UNSET_ISREF_P(t8);
				}
			}
		} else {
			FREE_ZVAL(t8);
			PHALCON_ALLOC_ZVAL(t8);
		}
	}
	phalcon_read_property(t8, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v12) {
		Z_DELREF_P(v12);
		if (!Z_REFCOUNT_P(v12)) {
			FREE_ZVAL(v12);
		}
	}
	Z_ADDREF_P(t8);
	v12 = t8;
	phalcon_debug_assign("$params", t8 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=195");
	if (!t9) {
		PHALCON_ALLOC_ZVAL(t9);
	} else {
		if (Z_REFCOUNT_P(t9) > 1) {
			{
				zval *orig_ptr = t9;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t9);
					*t9 = *orig_ptr;
					zval_copy_ctor(t9);
					Z_SET_REFCOUNT_P(t9, 1);
					Z_UNSET_ISREF_P(t9);
				}
			}
		} else {
			FREE_ZVAL(t9);
			PHALCON_ALLOC_ZVAL(t9);
		}
	}
	phalcon_read_property(t9, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v13) {
		Z_DELREF_P(v13);
		if (!Z_REFCOUNT_P(v13)) {
			FREE_ZVAL(v13);
		}
	}
	Z_ADDREF_P(t9);
	v13 = t9;
	phalcon_debug_assign("$actionName", t9 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=196");
	if (!zend_is_true(v13)) {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=196");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=197");
		if (!t10) {
			PHALCON_ALLOC_ZVAL(t10);
		} else {
			if (Z_REFCOUNT_P(t10) > 1) {
				{
					zval *orig_ptr = t10;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(t10);
						*t10 = *orig_ptr;
						zval_copy_ctor(t10);
						Z_SET_REFCOUNT_P(t10, 1);
						Z_UNSET_ISREF_P(t10);
					}
				}
			} else {
				FREE_ZVAL(t10);
				PHALCON_ALLOC_ZVAL(t10);
			}
		}
		phalcon_read_property(t10, this_ptr, "_defaultAction", sizeof("_defaultAction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v13) {
			Z_DELREF_P(v13);
			if (!Z_REFCOUNT_P(v13)) {
				FREE_ZVAL(v13);
			}
		}
		Z_ADDREF_P(t10);
		v13 = t10;
		phalcon_debug_assign("$actionName", t10 TSRMLS_CC);
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=198");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v13, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=201");
	if (!t11) {
		PHALCON_ALLOC_ZVAL(t11);
	} else {
		if (Z_REFCOUNT_P(t11) > 1) {
			SEPARATE_ZVAL(&t11);
		} else {
			if (Z_TYPE_P(t11) != IS_STRING) {
				FREE_ZVAL(t11);
				PHALCON_ALLOC_ZVAL(t11);
			}
		}
	}
	ZVAL_STRING(t11, "beforeDispatch", 0);
	if (phalcon_method_exists(v6, t11 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=201");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=202");
		if (!r10) {
			PHALCON_ALLOC_ZVAL(r10);
		} else {
			if (Z_REFCOUNT_P(r10) > 1) {
				{
					zval *orig_ptr = r10;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r10);
						*r10 = *orig_ptr;
						zval_copy_ctor(r10);
						Z_SET_REFCOUNT_P(r10, 1);
						Z_UNSET_ISREF_P(r10);
					}
				}
			} else {
				FREE_ZVAL(r10);
				PHALCON_ALLOC_ZVAL(r10);
			}
		}
		phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
		phalcon_debug_method_call(v6, "beforedispatch" TSRMLS_CC);
		PHALCON_CALL_METHOD(r10, v6, "beforedispatch", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r10 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
		if (Z_TYPE_P(r10) == IS_BOOL && !Z_BVAL_P(r10)) {
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=202");
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=203");
			if (!v5) {
				PHALCON_ALLOC_ZVAL(v5);
			} else {
				if (Z_REFCOUNT_P(v5) > 1) {
					SEPARATE_ZVAL(&v5);
				} else {
					if (Z_TYPE_P(v5) != IS_BOOL) {
						FREE_ZVAL(v5);
						PHALCON_ALLOC_ZVAL(v5);
					}
				}
			}
			ZVAL_BOOL(v5, 0);
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Break) File=/Dispatcher Line=204");
			goto we0;
		}
	}
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=208");
	if (!r11) {
		PHALCON_ALLOC_ZVAL(r11);
	} else {
		if (Z_REFCOUNT_P(r11) > 1) {
			{
				zval *orig_ptr = r11;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r11);
					*r11 = *orig_ptr;
					zval_copy_ctor(r11);
					Z_SET_REFCOUNT_P(r11, 1);
					Z_UNSET_ISREF_P(r11);
				}
			}
		} else {
			FREE_ZVAL(r11);
			PHALCON_ALLOC_ZVAL(r11);
		}
	}
	phalcon_concat_right(r11, v13, "Action" TSRMLS_CC);
	if (v14) {
		Z_DELREF_P(v14);
		if (!Z_REFCOUNT_P(v14)) {
			FREE_ZVAL(v14);
		}
	}
	Z_ADDREF_P(r11);
	v14 = r11;
	phalcon_debug_assign("$actionMethod", r11 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=209");
	if (phalcon_method_exists(v6, v14 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=209");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=210");
		if (!r12) {
			PHALCON_ALLOC_ZVAL(r12);
		} else {
			if (Z_REFCOUNT_P(r12) > 1) {
				{
					zval *orig_ptr = r12;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r12);
						*r12 = *orig_ptr;
						zval_copy_ctor(r12);
						Z_SET_REFCOUNT_P(r12, 1);
						Z_UNSET_ISREF_P(r12);
					}
				}
			} else {
				FREE_ZVAL(r12);
				PHALCON_ALLOC_ZVAL(r12);
			}
		}
		if (!a0) {
			PHALCON_ALLOC_ZVAL(a0);
		} else {
			if (Z_REFCOUNT_P(a0) > 1) {
				SEPARATE_ZVAL(&a0);
			} else {
				if (Z_TYPE_P(a0) != IS_ARRAY) {
					FREE_ZVAL(a0);
					PHALCON_ALLOC_ZVAL(a0);
				}
			}
		}
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v6, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v14, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		Z_ADDREF_P(a0);
		p7[0] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		Z_ADDREF_P(v12);
		p7[1] = v12;
		phalcon_debug_param(v12 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r12, "call_user_func_array", strlen("call_user_func_array"), 2, p7);
		phalcon_debug_vdump("call_user_func_array > ", r12 TSRMLS_CC);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r12);
		v5 = r12;
		phalcon_debug_assign("$value", r12 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=211");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=212");
		if (!t12) {
			PHALCON_ALLOC_ZVAL(t12);
		} else {
			if (Z_REFCOUNT_P(t12) > 1) {
				SEPARATE_ZVAL(&t12);
			} else {
				if (Z_TYPE_P(t12) != IS_STRING) {
					FREE_ZVAL(t12);
					PHALCON_ALLOC_ZVAL(t12);
				}
			}
		}
		ZVAL_STRING(t12, "notFoundAction", 0);
		if (phalcon_method_exists(v6, t12 TSRMLS_CC) == SUCCESS) {
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=212");
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=213");
			if (!r13) {
				PHALCON_ALLOC_ZVAL(r13);
			} else {
				if (Z_REFCOUNT_P(r13) > 1) {
					{
						zval *orig_ptr = r13;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r13);
							*r13 = *orig_ptr;
							zval_copy_ctor(r13);
							Z_SET_REFCOUNT_P(r13, 1);
							Z_UNSET_ISREF_P(r13);
						}
					}
				} else {
					FREE_ZVAL(r13);
					PHALCON_ALLOC_ZVAL(r13);
				}
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
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v6, 1, 0);
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
				add_next_index_zval(a1, copy);
			}
			add_next_index_string(a1, "notFoundAction", 1);
			Z_ADDREF_P(a1);
			p8[0] = a1;
			phalcon_debug_param(a1 TSRMLS_CC);
			Z_ADDREF_P(v12);
			p8[1] = v12;
			phalcon_debug_param(v12 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r13, "call_user_func_array", strlen("call_user_func_array"), 2, p8);
			phalcon_debug_vdump("call_user_func_array > ", r13 TSRMLS_CC);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r13);
			v5 = r13;
			phalcon_debug_assign("$value", r13 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=214");
			phalcon_step_over("Phalcon_Dispatcher::dispatch (Throw) File=/Dispatcher Line=215");
			if (!i3) {
				PHALCON_ALLOC_ZVAL(i3);
			} else {
				if (Z_REFCOUNT_P(i3) > 1) {
					{
						zval *orig_ptr = i3;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(i3);
							*i3 = *orig_ptr;
							zval_copy_ctor(i3);
							Z_SET_REFCOUNT_P(i3, 1);
							Z_UNSET_ISREF_P(i3);
						}
					}
				} else {
					FREE_ZVAL(i3);
					PHALCON_ALLOC_ZVAL(i3);
				}
			}
			object_init_ex(i3, phalcon_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			phalcon_debug_method_call(i3, "__construct" TSRMLS_CC);
			if (!r15) {
				PHALCON_ALLOC_ZVAL(r15);
			} else {
				if (Z_REFCOUNT_P(r15) > 1) {
					{
						zval *orig_ptr = r15;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r15);
							*r15 = *orig_ptr;
							zval_copy_ctor(r15);
							Z_SET_REFCOUNT_P(r15, 1);
							Z_UNSET_ISREF_P(r15);
						}
					}
				} else {
					FREE_ZVAL(r15);
					PHALCON_ALLOC_ZVAL(r15);
				}
			}
			phalcon_concat_left(r15, "Action '", v13 TSRMLS_CC);
			if (!r14) {
				PHALCON_ALLOC_ZVAL(r14);
			} else {
				if (Z_REFCOUNT_P(r14) > 1) {
					{
						zval *orig_ptr = r14;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r14);
							*r14 = *orig_ptr;
							zval_copy_ctor(r14);
							Z_SET_REFCOUNT_P(r14, 1);
							Z_UNSET_ISREF_P(r14);
						}
					}
				} else {
					FREE_ZVAL(r14);
					PHALCON_ALLOC_ZVAL(r14);
				}
			}
			phalcon_concat_vboth(r14, r15, "' was not found on controller '", v8 TSRMLS_CC);
			if (!r16) {
				PHALCON_ALLOC_ZVAL(r16);
			} else {
				if (Z_REFCOUNT_P(r16) > 1) {
					{
						zval *orig_ptr = r16;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r16);
							*r16 = *orig_ptr;
							zval_copy_ctor(r16);
							Z_SET_REFCOUNT_P(r16, 1);
							Z_UNSET_ISREF_P(r16);
						}
					}
				} else {
					FREE_ZVAL(r16);
					PHALCON_ALLOC_ZVAL(r16);
				}
			}
			phalcon_concat_right(r16, r14, "'" TSRMLS_CC);
			Z_ADDREF_P(r16);
			p9[0] = r16;
			phalcon_debug_param(r16 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p9, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			zend_throw_exception_object(i3 TSRMLS_CC);
			Z_ADDREF_P(i3);
			return;
		}
	}
	phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=219");
	if (!t13) {
		PHALCON_ALLOC_ZVAL(t13);
	} else {
		if (Z_REFCOUNT_P(t13) > 1) {
			SEPARATE_ZVAL(&t13);
		} else {
			if (Z_TYPE_P(t13) != IS_STRING) {
				FREE_ZVAL(t13);
				PHALCON_ALLOC_ZVAL(t13);
			}
		}
	}
	ZVAL_STRING(t13, "afterDispatch", 0);
	if (phalcon_method_exists(v6, t13 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=219");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (MethodCall) File=/Dispatcher Line=220");
		phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
		phalcon_debug_method_call(v6, "afterdispatch" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(v6, "afterdispatch", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Dispatcher::dispatch (PostIncDecOp) File=/Dispatcher Line=223");
	{
		zval *orig_ptr = v7;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(v7);
			*v7 = *orig_ptr;
			zval_copy_ctor(v7);
			Z_SET_REFCOUNT_P(v7, 1);
			Z_UNSET_ISREF_P(v7);
		}
	}
	increment_function(v7);
	phalcon_debug_vdump("PostIncrementing $numberDispatches", v7);
	phalcon_step_over("Phalcon_Dispatcher::dispatch (If) File=/Dispatcher Line=224");
	if (!t14) {
		PHALCON_ALLOC_ZVAL(t14);
	} else {
		if (Z_REFCOUNT_P(t14) > 1) {
			SEPARATE_ZVAL(&t14);
		} else {
			if (Z_TYPE_P(t14) != IS_LONG) {
				FREE_ZVAL(t14);
				PHALCON_ALLOC_ZVAL(t14);
			}
		}
	}
	ZVAL_LONG(t14, 256);
	PHALCON_SMALLER_FUNCTION(r17, t14, v7);
	if (zend_is_true(r17)) {
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Block) File=/Dispatcher Line=224");
		phalcon_step_over("Phalcon_Dispatcher::dispatch (Throw) File=/Dispatcher Line=225");
		if (!i4) {
			PHALCON_ALLOC_ZVAL(i4);
		} else {
			if (Z_REFCOUNT_P(i4) > 1) {
				{
					zval *orig_ptr = i4;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(i4);
						*i4 = *orig_ptr;
						zval_copy_ctor(i4);
						Z_SET_REFCOUNT_P(i4, 1);
						Z_UNSET_ISREF_P(i4);
					}
				}
			} else {
				FREE_ZVAL(i4);
				PHALCON_ALLOC_ZVAL(i4);
			}
		}
		object_init_ex(i4, phalcon_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
		phalcon_debug_method_call(i4, "__construct" TSRMLS_CC);
		if (!p11[0]) {
			PHALCON_ALLOC_ZVAL(p11[0]);
		} else {
			if (Z_REFCOUNT_P(p11[0]) > 1) {
				SEPARATE_ZVAL(&p11[0]);
			} else {
				if (Z_TYPE_P(p11[0]) != IS_STRING) {
					FREE_ZVAL(p11[0]);
					PHALCON_ALLOC_ZVAL(p11[0]);
				}
			}
		}
		ZVAL_STRING(p11[0], "Dispatcher has detected a cyclic routing causing stability problems", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 1, p11, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
		zend_throw_exception_object(i4 TSRMLS_CC);
		Z_ADDREF_P(i4);
		return;
	}
	goto ws0;
	we0:
	r1 = NULL;
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=230");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v5, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_returnedValue", strlen("_returnedValue"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Assignment) File=/Dispatcher Line=231");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v6, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_lastController", strlen("_lastController"), copy TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", v6 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v6) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v6);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v6);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Dispatcher::dispatch (Method) File=/Dispatcher Line=241");
}

/**
 * Routes to a controller/action using a string or array uri
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Dispatcher, forward){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Dispatcher", "forward", 0);
	phalcon_step_over("Phalcon_Dispatcher::forward (If) File=/Dispatcher Line=242");
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=242");
		phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=243");
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(v0);
		v1 = v0;
		phalcon_debug_assign("$parts", v0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=244");
		phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=245");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "/", 1);
		p0[1] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r0, "explode", strlen("explode"), 2, p0);
		phalcon_debug_vdump("explode > ", r0 TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r0);
		v1 = r0;
		phalcon_debug_assign("$parts", r0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Dispatcher::forward (If) File=/Dispatcher Line=247");
	eval_int = phalcon_array_isset_long(v1, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=247");
		phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=248");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		p1[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		phalcon_filter_alphanum(&r2, p1[0]);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Dispatcher::forward (Unset) File=/Dispatcher Line=249");
		{
			zval *orig_ptr = v1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(v1);
				*v1 = *orig_ptr;
				zval_copy_ctor(v1);
				Z_SET_REFCOUNT_P(v1, 1);
				Z_UNSET_ISREF_P(v1);
			}
		}
		phalcon_array_unset_long(v1, 0);
	} else {
		phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=250");
		phalcon_step_over("Phalcon_Dispatcher::forward (If) File=/Dispatcher Line=251");
		eval_int = phalcon_array_isset_string(v1, "controller", strlen("controller")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=251");
			phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=252");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v1, "controller", strlen("controller"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p2[0] = r3;
			phalcon_debug_param(r3 TSRMLS_CC);
			phalcon_filter_alphanum(&r4, p2[0]);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=253");
			phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=254");
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "getcontrollername" TSRMLS_CC);
			PHALCON_CALL_METHOD(r5, this_ptr, "getcontrollername", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r5 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r5, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
			}
		}
	}
	phalcon_step_over("Phalcon_Dispatcher::forward (If) File=/Dispatcher Line=257");
	eval_int = phalcon_array_isset_long(v1, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=257");
		phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=258");
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		p4[0] = r6;
		phalcon_debug_param(r6 TSRMLS_CC);
		phalcon_filter_alphanum(&r7, p4[0]);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r7, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=259");
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_array_fetch_long(r8, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Dispatcher::forward (Unset) File=/Dispatcher Line=260");
		{
			zval *orig_ptr = v1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(v1);
				*v1 = *orig_ptr;
				zval_copy_ctor(v1);
				Z_SET_REFCOUNT_P(v1, 1);
				Z_UNSET_ISREF_P(v1);
			}
		}
		phalcon_array_unset_long(v1, 1);
	} else {
		phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=261");
		phalcon_step_over("Phalcon_Dispatcher::forward (If) File=/Dispatcher Line=262");
		eval_int = phalcon_array_isset_string(v1, "action", strlen("action")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=262");
			phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=263");
			PHALCON_ALLOC_ZVAL(r9);
			phalcon_array_fetch_string(r9, v1, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p5[0] = r9;
			phalcon_debug_param(r9 TSRMLS_CC);
			phalcon_filter_alphanum(&r10, p5[0]);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r10, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=264");
			phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=265");
			PHALCON_ALLOC_ZVAL(r11);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "getactionname" TSRMLS_CC);
			PHALCON_CALL_METHOD(r11, this_ptr, "getactionname", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r11 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Dispatcher" TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r11, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
			}
		}
	}
	phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=268");
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
	phalcon_debug_assign("$params", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Dispatcher::forward (Foreach) File=/Dispatcher Line=269");
	FOREACH_KV(v1, ac0, fes1, fee1, ah0, hp0, v4, v3)
		phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=269");
		phalcon_step_over("Phalcon_Dispatcher::forward (If) File=/Dispatcher Line=270");
		if (Z_TYPE_P(v4) == IS_LONG) {
			phalcon_step_over("Phalcon_Dispatcher::forward (Block) File=/Dispatcher Line=270");
			phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=271");
			if (!r12) {
				PHALCON_ALLOC_ZVAL(r12);
			} else {
				if (Z_REFCOUNT_P(r12) > 1) {
					{
						zval *orig_ptr = r12;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r12);
							*r12 = *orig_ptr;
							zval_copy_ctor(r12);
							Z_SET_REFCOUNT_P(r12, 1);
							Z_UNSET_ISREF_P(r12);
						}
					}
				} else {
					FREE_ZVAL(r12);
					PHALCON_ALLOC_ZVAL(r12);
				}
			}
			phalcon_array_fetch(r12, v1, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r12, 1, 0);
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
		}
	END_FOREACH(ac0, fes1, fee1, ah0, hp0);
	phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=274");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Dispatcher::forward (Assignment) File=/Dispatcher Line=275");
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Dispatcher::forward (Method) File=/Dispatcher Line=283");
}

/**
 * Returns all instantiated controllers whitin the dispatcher
 *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getControllers){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "getControllers", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Dispatcher::getControllers (Method) File=/Dispatcher Line=292");
}

/**
 * Returns last dispatched controller
 *
 * @return Phalcon_Controller
 */
PHP_METHOD(Phalcon_Dispatcher, getLastController){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "getLastController", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_lastController", sizeof("_lastController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Dispatcher::getLastController (Method) File=/Dispatcher Line=301");
}

/**
 * Returns value returned by last dispacthed action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Dispatcher", "getReturnedValue", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_returnedValue", sizeof("_returnedValue")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
}

