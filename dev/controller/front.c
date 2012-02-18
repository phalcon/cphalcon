
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
 * Php_Controller_Front
 *
 * Php_Controller_Front implements a "Front Controller" pattern used in "Model-View-Controller" (MVC) applications.
 * Its purpose is to initialize the request environment, route the incoming request, and then dispatch
 * any discovered actions; it aggregates any responses and returns them when the process is complete
 */

/**
 * Private Php_Controller_Front constructor for singleton
 */
PHP_METHOD(Phalcon_Controller_Front, __construct){


	phalcon_step_into_entry("Phalcon_Controller_Front", "__construct", 0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::__construct (Method) File=Library/Phalcon/Controller/Front.php Line=79");
}

/**
 * Gets Php_Controller_Front singleton instance
 *
 * @return Php_Controller_Front
 */
PHP_METHOD(Phalcon_Controller_Front, getInstance){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Controller_Front", "getInstance", 0);
	phalcon_step_over("Phalcon_Controller_Front::getInstance (If) File=Library/Phalcon/Controller/Front.php Line=80");
	PHALCON_ALLOC_ZVAL(r0);
	t0 = zend_read_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	Z_ADDREF_P(t0);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	phalcon_debug_vdump("is_null > ", r0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Controller_Front::getInstance (Block) File=Library/Phalcon/Controller/Front.php Line=80");
		phalcon_step_over("Phalcon_Controller_Front::getInstance (Assignment) File=Library/Phalcon/Controller/Front.php Line=81");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_controller_front_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		zend_update_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Controller_Front::getInstance (Method) File=Library/Phalcon/Controller/Front.php Line=91");
}

/**
 * Modifies multipe general settings using
 *
 * @param stdClass $config
 */
PHP_METHOD(Phalcon_Controller_Front, setConfig){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setConfig", 0);
	phalcon_step_over("Phalcon_Controller_Front::setConfig (If) File=Library/Phalcon/Controller/Front.php Line=92");
	//$config
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=92");
		phalcon_step_over("Phalcon_Controller_Front::setConfig (If) File=Library/Phalcon/Controller/Front.php Line=93");
		//$config
		eval_int = phalcon_isset_property(v0, "database", strlen("database") TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=93");
			phalcon_step_over("Phalcon_Controller_Front::setConfig (StaticMethodCall) File=Library/Phalcon/Controller/Front.php Line=94");
			//$config
			PHALCON_ALLOC_ZVAL(t0);
			phalcon_read_property(t0, v0, "database", sizeof("database")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t0);
			Z_ADDREF_P(t0);
			p0[0] = t0;
			phalcon_debug_param(t0 TSRMLS_CC);
			PHALCON_CALL_STATIC_PARAMS_NORETURN("phalcon_db_pool", "setdefaultdescriptor", 1, p0);
		}
		phalcon_step_over("Phalcon_Controller_Front::setConfig (If) File=Library/Phalcon/Controller/Front.php Line=96");
		//$config
		eval_int = phalcon_isset_property(v0, "phalcon", strlen("phalcon") TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=96");
			phalcon_step_over("Phalcon_Controller_Front::setConfig (Assignment) File=Library/Phalcon/Controller/Front.php Line=97");
			//$phalcon
			//$config
			PHALCON_ALLOC_ZVAL(t1);
			phalcon_read_property(t1, v0, "phalcon", sizeof("phalcon")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t1);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(t1);
			v1 = t1;
			phalcon_debug_assign("$phalcon", t1 TSRMLS_CC);
			phalcon_step_over("Phalcon_Controller_Front::setConfig (If) File=Library/Phalcon/Controller/Front.php Line=98");
			//$phalcon
			eval_int = phalcon_isset_property(v1, "controllersDir", strlen("controllersDir") TSRMLS_CC);
			if (eval_int) {
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=98");
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Assignment) File=Library/Phalcon/Controller/Front.php Line=99");
				//$phalcon
				PHALCON_ALLOC_ZVAL(t2);
				phalcon_read_property(t2, v1, "controllersDir", sizeof("controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t2);
				//$this
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t2, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), copy TSRMLS_CC);
				}
			}
			phalcon_step_over("Phalcon_Controller_Front::setConfig (If) File=Library/Phalcon/Controller/Front.php Line=101");
			//$phalcon
			eval_int = phalcon_isset_property(v1, "modelsDir", strlen("modelsDir") TSRMLS_CC);
			if (eval_int) {
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=101");
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Assignment) File=Library/Phalcon/Controller/Front.php Line=102");
				//$phalcon
				PHALCON_ALLOC_ZVAL(t3);
				phalcon_read_property(t3, v1, "modelsDir", sizeof("modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t3);
				//$this
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t3, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), copy TSRMLS_CC);
				}
			}
			phalcon_step_over("Phalcon_Controller_Front::setConfig (If) File=Library/Phalcon/Controller/Front.php Line=104");
			//$phalcon
			eval_int = phalcon_isset_property(v1, "viewsDir", strlen("viewsDir") TSRMLS_CC);
			if (eval_int) {
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=104");
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Assignment) File=Library/Phalcon/Controller/Front.php Line=105");
				//$phalcon
				PHALCON_ALLOC_ZVAL(t4);
				phalcon_read_property(t4, v1, "viewsDir", sizeof("viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t4);
				//$this
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t4, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), copy TSRMLS_CC);
				}
			}
			phalcon_step_over("Phalcon_Controller_Front::setConfig (If) File=Library/Phalcon/Controller/Front.php Line=107");
			//$phalcon
			eval_int = phalcon_isset_property(v1, "baseUri", strlen("baseUri") TSRMLS_CC);
			if (eval_int) {
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=107");
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Assignment) File=Library/Phalcon/Controller/Front.php Line=108");
				//$phalcon
				PHALCON_ALLOC_ZVAL(t5);
				phalcon_read_property(t5, v1, "baseUri", sizeof("baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t5);
				//$this
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t5, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), copy TSRMLS_CC);
				}
			}
			phalcon_step_over("Phalcon_Controller_Front::setConfig (If) File=Library/Phalcon/Controller/Front.php Line=110");
			//$phalcon
			eval_int = phalcon_isset_property(v1, "basePath", strlen("basePath") TSRMLS_CC);
			if (eval_int) {
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=110");
				phalcon_step_over("Phalcon_Controller_Front::setConfig (Assignment) File=Library/Phalcon/Controller/Front.php Line=111");
				//$phalcon
				PHALCON_ALLOC_ZVAL(t6);
				phalcon_read_property(t6, v1, "basePath", sizeof("basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t6);
				//$this
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t6, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), copy TSRMLS_CC);
				}
			}
		}
	} else {
		phalcon_step_over("Phalcon_Controller_Front::setConfig (Block) File=Library/Phalcon/Controller/Front.php Line=114");
		phalcon_step_over("Phalcon_Controller_Front::setConfig (Throw) File=Library/Phalcon/Controller/Front.php Line=115");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "Config parameter should be an Object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setConfig (Method) File=Library/Phalcon/Controller/Front.php Line=124");
}

/**
 * Sets controllers directory
 *
 * @param string $controllersDir
 */
PHP_METHOD(Phalcon_Controller_Front, setControllerDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setControllerDir", 0);
	phalcon_step_over("Phalcon_Controller_Front::setControllerDir (Assignment) File=Library/Phalcon/Controller/Front.php Line=125");
	//$controllersDir
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setControllerDir (Method) File=Library/Phalcon/Controller/Front.php Line=133");
}

/**
 * Sets models directory
 *
 * @param string $modelsDir
 */
PHP_METHOD(Phalcon_Controller_Front, setModelsDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setModelsDir", 0);
	phalcon_step_over("Phalcon_Controller_Front::setModelsDir (Assignment) File=Library/Phalcon/Controller/Front.php Line=134");
	//$modelsDir
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setModelsDir (Method) File=Library/Phalcon/Controller/Front.php Line=142");
}

/**
 * Sets views directory
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_Controller_Front, setViewsDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setViewsDir", 0);
	phalcon_step_over("Phalcon_Controller_Front::setViewsDir (Assignment) File=Library/Phalcon/Controller/Front.php Line=143");
	//$viewsDir
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setViewsDir (Method) File=Library/Phalcon/Controller/Front.php Line=150");
}

/**
 * Replaces the default router with a predefined object
 * 
 */
PHP_METHOD(Phalcon_Controller_Front, setRouter){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setRouter", 0);
	phalcon_step_over("Phalcon_Controller_Front::setRouter (Assignment) File=Library/Phalcon/Controller/Front.php Line=151");
	//$router
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setRouter (Method) File=Library/Phalcon/Controller/Front.php Line=159");
}

/**
 * Return active router
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getRouter){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Controller_Front", "getRouter", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Controller_Front::getRouter (Method) File=Library/Phalcon/Controller/Front.php Line=168");
}

/**
 * Replaces the default dispatcher with a predefined object
 * 
 * @param Php_Dispatcher $dispatcher
 */
PHP_METHOD(Phalcon_Controller_Front, setDispatcher){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setDispatcher", 0);
	phalcon_step_over("Phalcon_Controller_Front::setDispatcher (Assignment) File=Library/Phalcon/Controller/Front.php Line=169");
	//$dispatcher
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setDispatcher (Method) File=Library/Phalcon/Controller/Front.php Line=177");
}

/**
 * Return active Dispatcher
 *
 * @return Php_Dispatcher
 */
PHP_METHOD(Phalcon_Controller_Front, getDispatcher){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Controller_Front", "getDispatcher", 0);
	phalcon_step_over("Phalcon_Controller_Front::getDispatcher (If) File=Library/Phalcon/Controller/Front.php Line=178");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Controller_Front::getDispatcher (Block) File=Library/Phalcon/Controller/Front.php Line=178");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	} else {
		phalcon_step_over("Phalcon_Controller_Front::getDispatcher (Block) File=Library/Phalcon/Controller/Front.php Line=180");
		phalcon_step_over("Phalcon_Controller_Front::getDispatcher (Throw) File=Library/Phalcon/Controller/Front.php Line=181");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "Dispatch process has not started yet", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::getDispatcher (Method) File=Library/Phalcon/Controller/Front.php Line=190");
}

/**
 * Sets external uri which app is executed
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, setBaseUri){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setBaseUri", 0);
	phalcon_step_over("Phalcon_Controller_Front::setBaseUri (Assignment) File=Library/Phalcon/Controller/Front.php Line=191");
	//$baseUri
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setBaseUri (Method) File=Library/Phalcon/Controller/Front.php Line=199");
}

/**
 * Gets external uri where app is executed
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getBaseUri){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	zval *v0 = NULL;
	zval **gv0;
	zval *p0[] = { NULL }, *p4[] = { NULL }, *p3[] = { NULL, NULL }, *p2[] = { NULL, NULL, NULL }, *p1[] = { NULL, NULL };
	int eval_int;

	phalcon_step_into_entry("Phalcon_Controller_Front", "getBaseUri", 0);
	phalcon_step_over("Phalcon_Controller_Front::getBaseUri (If) File=Library/Phalcon/Controller/Front.php Line=200");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_baseUri", sizeof("_baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	Z_ADDREF_P(t0);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	phalcon_debug_vdump("is_null > ", r0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Block) File=Library/Phalcon/Controller/Front.php Line=200");
		phalcon_step_over("Phalcon_Controller_Front::getBaseUri (If) File=Library/Phalcon/Controller/Front.php Line=201");
		//$_SERVER
		PHALCON_GET_GLOBAL(a0, "_SERVER", gv0);
		eval_int = phalcon_array_isset_string(a0, "PHP_SELF", strlen("PHP_SELF")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Block) File=Library/Phalcon/Controller/Front.php Line=201");
			phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Assignment) File=Library/Phalcon/Controller/Front.php Line=202");
			//$uri
			PHALCON_ALLOC_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_ALLOC_ZVAL(r3);
			PHALCON_ALLOC_ZVAL(p3[0]);
			ZVAL_STRING(p3[0], "/", 1);
			PHALCON_ALLOC_ZVAL(r4);
			//$_SERVER
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_array_fetch_string(r5, a0, "PHP_SELF", strlen("PHP_SELF"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p4[0] = r5;
			phalcon_debug_param(r5 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r4, "dirname", 1, p4);
			phalcon_debug_vdump("dirname > ", r4 TSRMLS_CC);
			p3[1] = r4;
			phalcon_debug_param(r4 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r3, "explode", 2, p3);
			phalcon_debug_vdump("explode > ", r3 TSRMLS_CC);
			p2[0] = r3;
			phalcon_debug_param(r3 TSRMLS_CC);
			PHALCON_PARAM_LONG(p2[1], 1);
			PHALCON_ALLOC_ZVAL(t2);
			ZVAL_LONG(t2, 1);
			PHALCON_ALLOC_ZVAL(t1);
			ZVAL_LONG(t1, -1);
			PHALCON_MUL_FUNCTION(r6, t1, t2);
			p2[2] = r6;
			phalcon_debug_param(r6 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r2, "array_slice", 3, p2);
			phalcon_debug_vdump("array_slice > ", r2 TSRMLS_CC);
			p1[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p1[1]);
			ZVAL_STRING(p1[1], "/", 1);
			PHALCON_CALL_FUNC_PARAMS(r1, "join", 2, p1);
			phalcon_debug_vdump("join > ", r1 TSRMLS_CC);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(r1);
			v0 = r1;
			phalcon_debug_assign("$uri", r1 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Block) File=Library/Phalcon/Controller/Front.php Line=203");
			phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Assignment) File=Library/Phalcon/Controller/Front.php Line=204");
			//$uri
			PHALCON_ALLOC_ZVAL(v0);
			ZVAL_STRING(v0, "", 0);
		}
		phalcon_step_over("Phalcon_Controller_Front::getBaseUri (If) File=Library/Phalcon/Controller/Front.php Line=206");
		//$uri
		if (phalcon_compare_strict_string(v0, "")) {
			phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Block) File=Library/Phalcon/Controller/Front.php Line=206");
			phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Assignment) File=Library/Phalcon/Controller/Front.php Line=207");
			//$this
			phalcon_update_property_string(this_ptr, "_baseUri", strlen("_baseUri"), "/" TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Block) File=Library/Phalcon/Controller/Front.php Line=208");
			phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Assignment) File=Library/Phalcon/Controller/Front.php Line=209");
			//$uri
			PHALCON_ALLOC_ZVAL(r7);
			phalcon_concat_both(r7,  "/", v0, "/" TSRMLS_CC);
			//$this
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r7, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), copy TSRMLS_CC);
			}
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_baseUri", sizeof("_baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
	phalcon_debug_vdump("Returning > ", t3 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t3) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t3);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Controller_Front::getBaseUri (Method) File=Library/Phalcon/Controller/Front.php Line=218");
}

/**
 * Sets local path where app/ directory is located
 */
PHP_METHOD(Phalcon_Controller_Front, setBasePath){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setBasePath", 0);
	phalcon_step_over("Phalcon_Controller_Front::setBasePath (Assignment) File=Library/Phalcon/Controller/Front.php Line=219");
	//$basePath
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setBasePath (Method) File=Library/Phalcon/Controller/Front.php Line=227");
}

/**
 * Gets local path where app/ directory is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getBasePath){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Controller_Front", "getBasePath", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Controller_Front::getBasePath (Method) File=Library/Phalcon/Controller/Front.php Line=234");
}

/**
 * Sets request object
 */
PHP_METHOD(Phalcon_Controller_Front, setRequest){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setRequest", 0);
	phalcon_step_over("Phalcon_Controller_Front::setRequest (Assignment) File=Library/Phalcon/Controller/Front.php Line=235");
	//$request
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_request", strlen("_request"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setRequest (Method) File=Library/Phalcon/Controller/Front.php Line=241");
}

/**
 * Sets request object
 */
PHP_METHOD(Phalcon_Controller_Front, setResponse){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setResponse", 0);
	phalcon_step_over("Phalcon_Controller_Front::setResponse (Assignment) File=Library/Phalcon/Controller/Front.php Line=242");
	//$response
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_response", strlen("_response"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setResponse (Method) File=Library/Phalcon/Controller/Front.php Line=248");
}

/**
* Sets the models manager 
 */
PHP_METHOD(Phalcon_Controller_Front, setModelComponent){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setModelComponent", 0);
	phalcon_step_over("Phalcon_Controller_Front::setModelComponent (Assignment) File=Library/Phalcon/Controller/Front.php Line=249");
	//$model
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setModelComponent (Method) File=Library/Phalcon/Controller/Front.php Line=257");
}

/**
 * Gets the models manager
 *
 * @return Php_Model_Manager
 */
PHP_METHOD(Phalcon_Controller_Front, getModelComponent){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	phalcon_step_into_entry("Phalcon_Controller_Front", "getModelComponent", 0);
	phalcon_step_over("Phalcon_Controller_Front::getModelComponent (If) File=Library/Phalcon/Controller/Front.php Line=258");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Controller_Front::getModelComponent (Block) File=Library/Phalcon/Controller/Front.php Line=258");
		phalcon_step_over("Phalcon_Controller_Front::getModelComponent (Assignment) File=Library/Phalcon/Controller/Front.php Line=259");
		//$model
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_manager_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(i0);
		v0 = i0;
		phalcon_debug_assign("$model", i0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Controller_Front::getModelComponent (MethodCall) File=Library/Phalcon/Controller/Front.php Line=260");
		//$model
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(v0, "setmodelsdir" TSRMLS_CC);
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		Z_ADDREF_P(t1);
		p1[0] = t1;
		phalcon_debug_param(t1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setmodelsdir", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_step_over("Phalcon_Controller_Front::getModelComponent (Assignment) File=Library/Phalcon/Controller/Front.php Line=261");
		//$model
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Controller_Front::getModelComponent (Method) File=Library/Phalcon/Controller/Front.php Line=269");
}

/**
 * Sets view component
 */
PHP_METHOD(Phalcon_Controller_Front, setViewComponent){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Controller_Front", "setViewComponent", 0);
	phalcon_step_over("Phalcon_Controller_Front::setViewComponent (Assignment) File=Library/Phalcon/Controller/Front.php Line=270");
	//$view
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Controller_Front::setViewComponent (Method) File=Library/Phalcon/Controller/Front.php Line=278");
}

/**
 * Gets the views part manager
 *
 * @return Php_View
 */
PHP_METHOD(Phalcon_Controller_Front, getViewComponent){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	phalcon_step_into_entry("Phalcon_Controller_Front", "getViewComponent", 0);
	phalcon_step_over("Phalcon_Controller_Front::getViewComponent (If) File=Library/Phalcon/Controller/Front.php Line=279");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Controller_Front::getViewComponent (Block) File=Library/Phalcon/Controller/Front.php Line=279");
		phalcon_step_over("Phalcon_Controller_Front::getViewComponent (Assignment) File=Library/Phalcon/Controller/Front.php Line=280");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_view_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Controller_Front::getViewComponent (MethodCall) File=Library/Phalcon/Controller/Front.php Line=281");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(t1, "setviewsdir" TSRMLS_CC);
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		Z_ADDREF_P(t2);
		p1[0] = t2;
		phalcon_debug_param(t2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "setviewsdir", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
	phalcon_debug_vdump("Returning > ", t3 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t3) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t3);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Controller_Front::getViewComponent (Method) File=Library/Phalcon/Controller/Front.php Line=291");
}

/**
 * Executes the dispatch loop
 *
 * @return Php_View
 */
PHP_METHOD(Phalcon_Controller_Front, dispatchLoop){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p10[] = { NULL }, *p12[] = { NULL }, *p14[] = { NULL }, *p16[] = { NULL, NULL, NULL, NULL }, *p17[] = { NULL, NULL };

	phalcon_step_into_entry("Phalcon_Controller_Front", "dispatchLoop", 0);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (If) File=Library/Phalcon/Controller/Front.php Line=293");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Block) File=Library/Phalcon/Controller/Front.php Line=293");
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=294");
		//$dispatcher
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_dispatcher_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(i0);
		v0 = i0;
		phalcon_debug_assign("$dispatcher", i0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=295");
		//$dispatcher
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(v0, "setbasepath" TSRMLS_CC);
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		Z_ADDREF_P(t1);
		p1[0] = t1;
		phalcon_debug_param(t1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setbasepath", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=296");
		//$dispatcher
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(v0, "setcontrollersdir" TSRMLS_CC);
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		Z_ADDREF_P(t2);
		p2[0] = t2;
		phalcon_debug_param(t2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setcontrollersdir", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Block) File=Library/Phalcon/Controller/Front.php Line=297");
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=298");
		//$dispatcher
		//$this
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(t3);
		v0 = t3;
		phalcon_debug_assign("$dispatcher", t3 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (If) File=Library/Phalcon/Controller/Front.php Line=301");
	//$this
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, this_ptr, "_request", sizeof("_request")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t4);
	if (!zend_is_true(t4)) {
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Block) File=Library/Phalcon/Controller/Front.php Line=301");
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=302");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_request", "getinstance");
		phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_request", strlen("_request"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (If) File=Library/Phalcon/Controller/Front.php Line=304");
	//$this
	PHALCON_ALLOC_ZVAL(t5);
	phalcon_read_property(t5, this_ptr, "_response", sizeof("_response")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t5);
	if (!zend_is_true(t5)) {
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Block) File=Library/Phalcon/Controller/Front.php Line=304");
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=305");
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_response", "getinstance");
		phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_response", strlen("_response"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (If) File=Library/Phalcon/Controller/Front.php Line=308");
	//$this
	PHALCON_ALLOC_ZVAL(t6);
	phalcon_read_property(t6, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t6);
	if (!zend_is_true(t6)) {
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Block) File=Library/Phalcon/Controller/Front.php Line=308");
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=309");
		//$router
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_router_rewrite_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i1, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(i1);
		v1 = i1;
		phalcon_debug_assign("$router", i1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=310");
		//$router
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
		phalcon_debug_method_call(v1, "handle" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(v1, "handle", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Block) File=Library/Phalcon/Controller/Front.php Line=311");
		phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=312");
		//$router
		//$this
		PHALCON_ALLOC_ZVAL(t7);
		phalcon_read_property(t7, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t7);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(t7);
		v1 = t7;
		phalcon_debug_assign("$router", t7 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=315");
	//$view
	PHALCON_ALLOC_ZVAL(r2);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getviewcomponent" TSRMLS_CC);
	PHALCON_CALL_METHOD(r2, this_ptr, "getviewcomponent", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r2);
	v2 = r2;
	phalcon_debug_assign("$view", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=316");
	//$view
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v2, "start" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(v2, "start", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=318");
	//$model
	PHALCON_ALLOC_ZVAL(r3);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getmodelcomponent" TSRMLS_CC);
	PHALCON_CALL_METHOD(r3, this_ptr, "getmodelcomponent", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r3);
	v3 = r3;
	phalcon_debug_assign("$model", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=320");
	//$dispatcher
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v0, "setcontrollername" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r4);
	//$router
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v1, "getcontrollername" TSRMLS_CC);
	PHALCON_CALL_METHOD(r4, v1, "getcontrollername", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	Z_ADDREF_P(r4);
	p10[0] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setcontrollername", 1, p10, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=321");
	//$dispatcher
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v0, "setactionname" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	//$router
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v1, "getactionname" TSRMLS_CC);
	PHALCON_CALL_METHOD(r5, v1, "getactionname", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r5 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	Z_ADDREF_P(r5);
	p12[0] = r5;
	phalcon_debug_param(r5 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setactionname", 1, p12, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=322");
	//$dispatcher
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v0, "setparams" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r6);
	//$router
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v1, "getparams" TSRMLS_CC);
	PHALCON_CALL_METHOD(r6, v1, "getparams", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r6 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	Z_ADDREF_P(r6);
	p14[0] = r6;
	phalcon_debug_param(r6 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setparams", 1, p14, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=324");
	//$dispatcher
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (Assignment) File=Library/Phalcon/Controller/Front.php Line=325");
	//$router
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=327");
	//$dispatcher
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v0, "dispatch" TSRMLS_CC);
	//$this
	PHALCON_ALLOC_ZVAL(t8);
	phalcon_read_property(t8, this_ptr, "_request", sizeof("_request")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t8);
	Z_ADDREF_P(t8);
	p16[0] = t8;
	phalcon_debug_param(t8 TSRMLS_CC);
	//$this
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, this_ptr, "_response", sizeof("_response")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	Z_ADDREF_P(t9);
	p16[1] = t9;
	phalcon_debug_param(t9 TSRMLS_CC);
	//$view
	Z_ADDREF_P(v2);
	p16[2] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	//$model
	Z_ADDREF_P(v3);
	p16[3] = v3;
	phalcon_debug_param(v3 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "dispatch", 4, p16, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=329");
	//$view
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v2, "render" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r7);
	//$dispatcher
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getcontrollername" TSRMLS_CC);
	PHALCON_CALL_METHOD(r7, v0, "getcontrollername", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r7 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	Z_ADDREF_P(r7);
	p17[0] = r7;
	phalcon_debug_param(r7 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r8);
	//$dispatcher
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getactionname" TSRMLS_CC);
	PHALCON_CALL_METHOD(r8, v0, "getactionname", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r8 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	Z_ADDREF_P(r8);
	p17[1] = r8;
	phalcon_debug_param(r8 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "render", 2, p17, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_step_over("Phalcon_Controller_Front::dispatchLoop (MethodCall) File=Library/Phalcon/Controller/Front.php Line=330");
	//$view
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	phalcon_debug_method_call(v2, "finish" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(v2, "finish", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Controller_Front" TSRMLS_CC);
	//$view
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

