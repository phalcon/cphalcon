
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
/**
 * Phalcon_Controller_Front
 *
 * Phalcon_Controller_Front implements a "Front Controller" pattern used in "Model-View-Controller" (MVC) applications.
 * Its purpose is to initialize the request environment, route the incoming request, and then dispatch
 * any discovered actions; it aggregates any responses and returns them when the process is complete
 *
 *
 */

/**
 * Private Phalcon_Controller_Front constructor for singleton
 */
PHP_METHOD(Phalcon_Controller_Front, __construct){


	PHALCON_MM_GROW();
	
	PHALCON_MM_RESTORE();
}

/**
 * Modifies multiple general settings using a Phalcon_Config object or a stdClass filled with parameters
 *
 * 
 *
 * @param stdClass $config
 */
PHP_METHOD(Phalcon_Controller_Front, setConfig){

	zval *config = NULL, *phalcon = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(config) == IS_OBJECT) {
		eval_int = phalcon_isset_property(config, SL("database") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t0);
			phalcon_read_property(&t0, config, SL("database"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_STATIC_PARAMS_1_NORETURN("phalcon_db_pool", "setdefaultdescriptor", t0);
		}
		eval_int = phalcon_isset_property(config, SL("phalcon") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, config, SL("phalcon"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(phalcon, t1);
			eval_int = phalcon_isset_property(phalcon, SL("controllersDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t2);
				phalcon_read_property(&t2, phalcon, SL("controllersDir"), PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_controllersDir"), t2 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, SL("modelsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, phalcon, SL("modelsDir"), PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_modelsDir"), t3 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, SL("viewsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t4);
				phalcon_read_property(&t4, phalcon, SL("viewsDir"), PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_viewsDir"), t4 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, SL("baseUri") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t5);
				phalcon_read_property(&t5, phalcon, SL("baseUri"), PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_baseUri"), t5 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, SL("basePath") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t6);
				phalcon_read_property(&t6, phalcon, SL("basePath"), PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_basePath"), t6 TSRMLS_CC);
			}
		}
		
		eval_int = phalcon_isset_property(config, SL("models") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t7);
			phalcon_read_property(&t7, config, SL("models"), PHALCON_NOISY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_modelsConfig"), t7 TSRMLS_CC);
		}
		
		eval_int = phalcon_isset_property(config, SL("views") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t8);
			phalcon_read_property(&t8, config, SL("views"), PHALCON_NOISY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_viewsConfig"), t8 TSRMLS_CC);
		}
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Config parameter should be an object");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the database default settings
 *
 * @param stdClass $database
 */
PHP_METHOD(Phalcon_Controller_Front, setDatabaseConfig){

	zval *database = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &database) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_STATIC_PARAMS_1_NORETURN("phalcon_db_pool", "setdefaultdescriptor", database);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets controllers directory. Depending of your platform, always add a trailing slash or backslash
 *
 * 
 *
 * @param string $controllersDir
 */
PHP_METHOD(Phalcon_Controller_Front, setControllersDir){

	zval *controllers_dir = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controllers_dir) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_controllersDir"), controllers_dir TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets models directory. Depending of your platform, always add a trailing slash or backslash
*
 * 
 *
 * @param string $modelsDir
 */
PHP_METHOD(Phalcon_Controller_Front, setModelsDir){

	zval *models_dir = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &models_dir) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_modelsDir"), models_dir TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * 
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_Controller_Front, setViewsDir){

	zval *views_dir = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &views_dir) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_viewsDir"), views_dir TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Replaces the default router with a predefined object
 *
 * 
 *
 * @param Phalcon_Router $router
 */
PHP_METHOD(Phalcon_Controller_Front, setRouter){

	zval *router = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &router) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_router"), router TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Return active router
 *
 * @return Phalcon_Router
 */
PHP_METHOD(Phalcon_Controller_Front, getRouter){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_router"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Replaces the default dispatcher with a predefined object
 *
 * @param Phalcon_Dispatcher $dispatcher
 */
PHP_METHOD(Phalcon_Controller_Front, setDispatcher){

	zval *dispatcher = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dispatcher) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dispatcher"), dispatcher TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Return active Dispatcher
 *
 * @return Phalcon_Dispatcher
 */
PHP_METHOD(Phalcon_Controller_Front, getDispatcher){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dispatcher"), PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_dispatcher"), PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(t1);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Dispatch process has not started yet");
	return;
}

/**
 * Sets external uri which app is executed
 *
 * @param string $baseUri
 */
PHP_METHOD(Phalcon_Controller_Front, setBaseUri){

	zval *base_uri = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets external uri where app is executed
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getBaseUri){

	zval *base_uri = NULL, *slash = NULL, *uri = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_baseUri"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(base_uri, t0);
	if (!zend_is_true(base_uri)) {
		PHALCON_INIT_VAR(slash);
		ZVAL_STRING(slash, "/", 1);
		phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
		eval_int = phalcon_array_isset_string(g0, SL("PHP_SELF")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, g0, SL("PHP_SELF"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "dirname", r0);
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_explode(r2, slash, r1 TSRMLS_CC);
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_INIT_VAR(t2);
			ZVAL_LONG(t2, 1);
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, -1);
			PHALCON_ALLOC_ZVAL_MM(r3);
			mul_function(r3, t1, t2 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_FUNC_PARAMS_3(r4, "array_slice", r2, c0, r3);
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_fast_join(r5, slash, r4 TSRMLS_CC);
			PHALCON_CPY_WRT(uri, r5);
		} else {
			PHALCON_INIT_VAR(uri);
			ZVAL_STRING(uri, "", 1);
		}
		
		if (!zend_is_true(uri)) {
			PHALCON_CPY_WRT(base_uri, slash);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_VVV(r6, slash, uri, slash);
			PHALCON_CPY_WRT(base_uri, r6);
		}
		
		phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	}
	
	
	RETURN_CHECK_CTOR(base_uri);
}

/**
 * Sets local path where app/ directory is located. Depending of your platform, always add a trailing slash or backslash
 *
  * @param string $basePath
 */
PHP_METHOD(Phalcon_Controller_Front, setBasePath){

	zval *base_path = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets local path where app/ directory is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getBasePath){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_basePath"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Overwrites request object default object
 *
 * @param Phalcon_Request $request
 */
PHP_METHOD(Phalcon_Controller_Front, setRequest){

	zval *request = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &request) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_request"), request TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Overwrites response object default object
  *
 * @param Phalcon_Response $response
 */
PHP_METHOD(Phalcon_Controller_Front, setResponse){

	zval *response = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &response) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_response"), response TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Overwrites models manager default object
 *
 * @param Phalcon_Model_Manager $model
 */
PHP_METHOD(Phalcon_Controller_Front, setModelComponent){

	zval *model = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_model"), model TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets the models manager
 *
 * @return Phalcon_Model_Manager
 */
PHP_METHOD(Phalcon_Controller_Front, getModelComponent){

	zval *model = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_model"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(model, t0);
	if (!zend_is_true(model)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_manager_ce);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_modelsConfig"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", t1, PHALCON_CHECK);
		PHALCON_CPY_WRT(model, i0);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_modelsDir"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setmodelsdir", t2, PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_model"), model TSRMLS_CC);
	}
	
	
	RETURN_CHECK_CTOR(model);
}

/**
 * Sets view component
 *
 * @param Phalcon_View $view
 */
PHP_METHOD(Phalcon_Controller_Front, setViewComponent){

	zval *view = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &view) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_view"), view TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets the views part manager
 *
 * @return Phalcon_View
 */
PHP_METHOD(Phalcon_Controller_Front, getViewComponent){

	zval *view = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_view"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(view, t0);
	if (!zend_is_true(view)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_view_ce);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_viewsConfig"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", t1, PHALCON_CHECK);
		PHALCON_CPY_WRT(view, i0);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_viewsDir"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "setviewsdir", t2, PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_view"), view TSRMLS_CC);
	}
	
	
	RETURN_CHECK_CTOR(view);
}

/**
 * Executes the dispatch loop
 *
 * @return Phalcon_View
 */
PHP_METHOD(Phalcon_Controller_Front, dispatchLoop){

	zval *dispatcher = NULL, *router = NULL, *base_path = NULL, *view = NULL, *model = NULL;
	zval *response = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dispatcher"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_dispatcher_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(dispatcher, i0);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_controllersDir"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollersdir", t1, PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_dispatcher"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(dispatcher, t2);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_request"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t3)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_request", "getinstance");
		phalcon_update_property_zval(this_ptr, SL("_request"), r0 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, SL("_response"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_response", "getinstance");
		phalcon_update_property_zval(this_ptr, SL("_response"), r1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, SL("_router"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t5)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_router_rewrite_ce);
		PHALCON_CALL_METHOD_NORETURN(i1, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(router, i1);
		PHALCON_CALL_METHOD_NORETURN(router, "handle", PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_read_property(&t6, this_ptr, SL("_router"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(router, t6);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_read_property(&t7, this_ptr, SL("_basePath"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(base_path, t7);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, this_ptr, "getviewcomponent", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(view, r2);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "setbasepath", base_path, PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(view, "start", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "getmodelcomponent", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(model, r3);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setbasepath", base_path, PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setbasepath", base_path, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, router, "getcontrollername", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollername", r4, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, router, "getactionname", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setactionname", r5, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, router, "getparams", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setparams", r6, PHALCON_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_dispatcher"), dispatcher TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_router"), router TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, this_ptr, SL("_response"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(response, t8);
	
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, this_ptr, SL("_request"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_4_NORETURN(dispatcher, "dispatch", t9, response, view, model, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, dispatcher, "getcontrollername", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, dispatcher, "getactionname", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, dispatcher, "getparams", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(view, "render", r7, r8, r9, PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(view, "finish", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CALL_METHOD(r10, view, "getcontent", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(response, "setcontent", r10, PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(response, "sendheaders", PHALCON_NO_CHECK);
	
	RETURN_CHECK_CTOR(response);
}

/**
 * Gets Phalcon_Controller_Front singleton instance
 *
 * @return Phalcon_Controller_Front
 */
PHP_METHOD(Phalcon_Controller_Front, getInstance){

	zval *instance = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Controller_Front"), SL("_instance") TSRMLS_CC);
	PHALCON_CPY_WRT(instance, t0);
	if (!zend_is_true(instance)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_controller_front_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(instance, i0);
		phalcon_update_static_property(SL("Phalcon_Controller_Front"), SL("_instance"), instance TSRMLS_CC);
	}
	
	
	RETURN_CHECK_CTOR(instance);
}

/**
 * Resets the internal singleton
 */
PHP_METHOD(Phalcon_Controller_Front, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	phalcon_update_static_property(SL("Phalcon_Controller_Front"), SL("_instance"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

