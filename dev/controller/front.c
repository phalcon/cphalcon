
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
 *
 *
 */

/**
 * Private Php_Controller_Front constructor for singleton
 */
PHP_METHOD(Phalcon_Controller_Front, __construct){


	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(r0);
	t0 = zend_read_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	Z_ADDREF_P(t0);
	p0[0] = t0;
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_controller_front_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		zend_update_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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

/**
 * Modifies multipe general settings using a Php_Config object or a stdClass filled with parameters
 *
 * 
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

	if (Z_TYPE_P(v0) == IS_OBJECT) {
		eval_int = phalcon_isset_property(v0, "database", strlen("database") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(t0);
			phalcon_read_property(t0, v0, "database", sizeof("database")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t0);
			Z_ADDREF_P(t0);
			p0[0] = t0;
			PHALCON_CALL_STATIC_PARAMS_NORETURN("phalcon_db_pool", "setdefaultdescriptor", 1, p0);
		}
		eval_int = phalcon_isset_property(v0, "phalcon", strlen("phalcon") TSRMLS_CC);
		if (eval_int) {
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
			eval_int = phalcon_isset_property(v1, "controllersDir", strlen("controllersDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(t2);
				phalcon_read_property(t2, v1, "controllersDir", sizeof("controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t2);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t2, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), copy TSRMLS_CC);
				}
			}
			eval_int = phalcon_isset_property(v1, "modelsDir", strlen("modelsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(t3);
				phalcon_read_property(t3, v1, "modelsDir", sizeof("modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t3);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t3, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), copy TSRMLS_CC);
				}
			}
			eval_int = phalcon_isset_property(v1, "viewsDir", strlen("viewsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(t4);
				phalcon_read_property(t4, v1, "viewsDir", sizeof("viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t4);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t4, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), copy TSRMLS_CC);
				}
			}
			eval_int = phalcon_isset_property(v1, "baseUri", strlen("baseUri") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(t5);
				phalcon_read_property(t5, v1, "baseUri", sizeof("baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t5);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, t5, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), copy TSRMLS_CC);
				}
			}
			eval_int = phalcon_isset_property(v1, "basePath", strlen("basePath") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(t6);
				phalcon_read_property(t6, v1, "basePath", sizeof("basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t6);
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
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "Config parameter should be an Object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

/**
 * Sets the database default settings
 *
 * @param stdClass $database
 */
PHP_METHOD(Phalcon_Controller_Front, setDatabaseConfig){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS_NORETURN("phalcon_db_pool", "setdefaultdescriptor", 1, p0);
	RETURN_NULL();
}

/**
 * Sets controllers directory
 *
 * 
 *
 * @param string $controllersDir
 */
PHP_METHOD(Phalcon_Controller_Front, setControllersDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Sets models directory
     *
 * 
 *
 * @param string $modelsDir
 */
PHP_METHOD(Phalcon_Controller_Front, setModelsDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Sets views directory
 *
 * 
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_Controller_Front, setViewsDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Replaces the default router with a predefined object
 *
 * 
 *
 * @param Php_Router $router
 */
PHP_METHOD(Phalcon_Controller_Front, setRouter){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Return active router
 *
 * @return Php_Router
 */
PHP_METHOD(Phalcon_Controller_Front, getRouter){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
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

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), copy TSRMLS_CC);
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
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
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "Dispatch process has not started yet", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

/**
 * Sets external uri which app is executed
 *
 * @param string $baseUri
 */
PHP_METHOD(Phalcon_Controller_Front, setBaseUri){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), copy TSRMLS_CC);
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_baseUri", sizeof("_baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	Z_ADDREF_P(t0);
	p0[0] = t0;
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	if (zend_is_true(r0)) {
		phalcon_init_global("_SERVER" TSRMLS_CC);
		if (&EG(symbol_table)) {
			if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
				if(Z_TYPE_PP(gv0)==IS_ARRAY){
					a0 = *gv0;
				} else {
					PHALCON_INIT_ARRAY(a0);
				}
			}
		} else {
			PHALCON_INIT_ARRAY(a0);
		}
		eval_int = phalcon_array_isset_string(a0, "PHP_SELF", strlen("PHP_SELF")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_ALLOC_ZVAL(r3);
			PHALCON_ALLOC_ZVAL(p3[0]);
			ZVAL_STRING(p3[0], "/", 1);
			PHALCON_ALLOC_ZVAL(r4);
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_array_fetch_string(r5, a0, "PHP_SELF", strlen("PHP_SELF"), PHALCON_NOISY_FETCH TSRMLS_CC);
			p4[0] = r5;
			PHALCON_CALL_FUNC_PARAMS(r4, "dirname", 1, p4);
			p3[1] = r4;
			PHALCON_CALL_FUNC_PARAMS(r3, "explode", 2, p3);
			p2[0] = r3;
			PHALCON_PARAM_LONG(p2[1], 1);
			PHALCON_ALLOC_ZVAL(t2);
			ZVAL_LONG(t2, 1);
			PHALCON_ALLOC_ZVAL(t1);
			ZVAL_LONG(t1, -1);
			PHALCON_MUL_FUNCTION(r6, t1, t2);
			p2[2] = r6;
			PHALCON_CALL_FUNC_PARAMS(r2, "array_slice", 3, p2);
			p1[0] = r2;
			PHALCON_ALLOC_ZVAL(p1[1]);
			ZVAL_STRING(p1[1], "/", 1);
			PHALCON_CALL_FUNC_PARAMS(r1, "join", 2, p1);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(r1);
			v0 = r1;
		} else {
			PHALCON_ALLOC_ZVAL(v0);
			ZVAL_STRING(v0, "", 0);
		}
		if (phalcon_compare_strict_string(v0, "")) {
			phalcon_update_property_string(this_ptr, "_baseUri", strlen("_baseUri"), "/" TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL(r7);
			phalcon_concat_both(r7,  "/", v0, "/" TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r7, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), copy TSRMLS_CC);
			}
		}
	}
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_baseUri", sizeof("_baseUri")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
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
}

/**
 * Sets local path where app/ directory is located
 *
  * @param string $basePath
 */
PHP_METHOD(Phalcon_Controller_Front, setBasePath){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Gets local path where app/ directory is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getBasePath){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
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

/**
 * Overwrittes request object default object
 *
 * @param Php_Request $response
 */
PHP_METHOD(Phalcon_Controller_Front, setRequest){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_request", strlen("_request"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Overwrittes response object default object
  *
 * @param Php_Response $response
 */
PHP_METHOD(Phalcon_Controller_Front, setResponse){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_response", strlen("_response"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Overwrittes models manager default object
 *
 * @param Php_Model_Manager $model
 */
PHP_METHOD(Phalcon_Controller_Front, setModelComponent){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_manager_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(i0);
		v0 = i0;
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		Z_ADDREF_P(t1);
		p1[0] = t1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setmodelsdir", 1, p1, PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
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
}

/**
 * Sets view component
 *
 * @param Php_View $view
 */
PHP_METHOD(Phalcon_Controller_Front, setViewComponent){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), copy TSRMLS_CC);
	}
	RETURN_NULL();
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_view_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), copy TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		Z_ADDREF_P(t2);
		p1[0] = t2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "setviewsdir", 1, p1, PHALCON_CALL_DEFAULT);
	}
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_dispatcher_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(i0);
		v0 = i0;
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		Z_ADDREF_P(t1);
		p1[0] = t1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setbasepath", 1, p1, PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		Z_ADDREF_P(t2);
		p2[0] = t2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setcontrollersdir", 1, p2, PHALCON_CALL_DEFAULT);
	} else {
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
	}
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, this_ptr, "_request", sizeof("_request")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t4);
	if (!zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_request", "getinstance");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_request", strlen("_request"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t5);
	phalcon_read_property(t5, this_ptr, "_response", sizeof("_response")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t5);
	if (!zend_is_true(t5)) {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_response", "getinstance");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_response", strlen("_response"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t6);
	phalcon_read_property(t6, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t6);
	if (!zend_is_true(t6)) {
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_router_rewrite_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i1, "__construct", PHALCON_CALL_CHECK);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(i1);
		v1 = i1;
		PHALCON_CALL_METHOD_NORETURN(v1, "handle", PHALCON_CALL_DEFAULT);
	} else {
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
	}
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_METHOD(r2, this_ptr, "getviewcomponent", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r2);
	v2 = r2;
	PHALCON_CALL_METHOD_NORETURN(v2, "start", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "getmodelcomponent", PHALCON_CALL_DEFAULT);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r3);
	v3 = r3;
	PHALCON_ALLOC_ZVAL(r4);
	PHALCON_CALL_METHOD(r4, v1, "getcontrollername", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r4);
	p10[0] = r4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setcontrollername", 1, p10, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r5);
	PHALCON_CALL_METHOD(r5, v1, "getactionname", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r5);
	p12[0] = r5;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setactionname", 1, p12, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r6);
	PHALCON_CALL_METHOD(r6, v1, "getparams", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r6);
	p14[0] = r6;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setparams", 1, p14, PHALCON_CALL_DEFAULT);
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
		phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t8);
	phalcon_read_property(t8, this_ptr, "_request", sizeof("_request")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t8);
	Z_ADDREF_P(t8);
	p16[0] = t8;
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, this_ptr, "_response", sizeof("_response")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	Z_ADDREF_P(t9);
	p16[1] = t9;
	Z_ADDREF_P(v2);
	p16[2] = v2;
	Z_ADDREF_P(v3);
	p16[3] = v3;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "dispatch", 4, p16, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r7);
	PHALCON_CALL_METHOD(r7, v0, "getcontrollername", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r7);
	p17[0] = r7;
	PHALCON_ALLOC_ZVAL(r8);
	PHALCON_CALL_METHOD(r8, v0, "getactionname", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r8);
	p17[1] = r8;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "render", 2, p17, PHALCON_CALL_DEFAULT);
	PHALCON_CALL_METHOD_NORETURN(v2, "finish", PHALCON_CALL_DEFAULT);
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
}

