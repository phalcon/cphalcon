
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
 * @param stdClass $config
 */
PHP_METHOD(Phalcon_Controller_Front, setConfig){

	zval *config = NULL, *phalcon = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
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
			phalcon_read_property(&t0, config, SL("database"), PH_NOISY_CC);
			PHALCON_CALL_STATIC_PARAMS_1_NORETURN("phalcon\\db\\pool", "setdefaultdescriptor", t0);
		}
		eval_int = phalcon_isset_property(config, SL("phalcon") TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_VAR(phalcon);
			phalcon_read_property(&phalcon, config, SL("phalcon"), PH_NOISY_CC);
			eval_int = phalcon_isset_property(phalcon, SL("controllersDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t1);
				phalcon_read_property(&t1, phalcon, SL("controllersDir"), PH_NOISY_CC);
				phalcon_update_property_zval(this_ptr, SL("_controllersDir"), t1 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, SL("modelsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t2);
				phalcon_read_property(&t2, phalcon, SL("modelsDir"), PH_NOISY_CC);
				phalcon_update_property_zval(this_ptr, SL("_modelsDir"), t2 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, SL("viewsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, phalcon, SL("viewsDir"), PH_NOISY_CC);
				phalcon_update_property_zval(this_ptr, SL("_viewsDir"), t3 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, SL("baseUri") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t4);
				phalcon_read_property(&t4, phalcon, SL("baseUri"), PH_NOISY_CC);
				phalcon_update_property_zval(this_ptr, SL("_baseUri"), t4 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, SL("basePath") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t5);
				phalcon_read_property(&t5, phalcon, SL("basePath"), PH_NOISY_CC);
				phalcon_update_property_zval(this_ptr, SL("_basePath"), t5 TSRMLS_CC);
			}
		}
		
		eval_int = phalcon_isset_property(config, SL("models") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_read_property(&t6, config, SL("models"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_modelsConfig"), t6 TSRMLS_CC);
		}
		
		eval_int = phalcon_isset_property(config, SL("views") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t7);
			phalcon_read_property(&t7, config, SL("views"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_viewsConfig"), t7 TSRMLS_CC);
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

	PHALCON_CALL_STATIC_PARAMS_1_NORETURN("phalcon\\db\\pool", "setdefaultdescriptor", database);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets controllers directory. Depending of your platform, always add a trailing slash or backslash
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
	phalcon_read_property(&t0, this_ptr, SL("_router"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_dispatcher"), PH_NOISY_CC);
		
		RETURN_CCTOR(t1);
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
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(base_uri);
	phalcon_read_property(&base_uri, this_ptr, SL("_baseUri"), PH_NOISY_CC);
	if (!zend_is_true(base_uri)) {
		PHALCON_INIT_VAR(slash);
		ZVAL_STRING(slash, "/", 1);
		phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
		eval_int = phalcon_array_isset_string(g0, SL("PHP_SELF")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, g0, SL("PHP_SELF"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "dirname", r0);
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_fast_explode(r2, slash, r1 TSRMLS_CC);
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, 1);
			PHALCON_INIT_VAR(t0);
			ZVAL_LONG(t0, -1);
			PHALCON_ALLOC_ZVAL_MM(r3);
			mul_function(r3, t0, t1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_FUNC_PARAMS_3(r4, "array_slice", r2, c0, r3);
			PHALCON_INIT_VAR(uri);
			phalcon_fast_join(uri, slash, r4 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(uri);
			ZVAL_STRING(uri, "", 1);
		}
		
		if (!zend_is_true(uri)) {
			PHALCON_CPY_WRT(base_uri, slash);
		} else {
			PHALCON_INIT_VAR(base_uri);
			PHALCON_CONCAT_VVV(base_uri, slash, uri, slash);
		}
		
		phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(base_uri);
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
	phalcon_read_property(&t0, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(model);
	phalcon_read_property(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (!zend_is_true(model)) {
		PHALCON_INIT_VAR(model);
		object_init_ex(model, phalcon_model_manager_ce);
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_modelsConfig"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "__construct", t0, PH_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_modelsDir"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setmodelsdir", t1, PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_model"), model TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(model);
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
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(view);
	phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	if (!zend_is_true(view)) {
		PHALCON_INIT_VAR(view);
		object_init_ex(view, phalcon_view_ce);
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_viewsConfig"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "__construct", t0, PH_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_viewsDir"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "setviewsdir", t1, PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_view"), view TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(view);
}

/**
 * Executes the dispatch loop
 *
 * @return Phalcon_View
 */
PHP_METHOD(Phalcon_Controller_Front, dispatchLoop){

	zval *dispatcher = NULL, *router = NULL, *base_path = NULL, *view = NULL, *model = NULL;
	zval *response = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	if (!zend_is_true(t0)) {
		PHALCON_INIT_VAR(dispatcher);
		object_init_ex(dispatcher, phalcon_dispatcher_ce);
		PHALCON_CALL_METHOD_NORETURN(dispatcher, "__construct", PH_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_controllersDir"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollersdir", t1, PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(dispatcher);
		phalcon_read_property(&dispatcher, this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_request"), PH_NOISY_CC);
	if (!zend_is_true(t2)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon\\request", "getinstance");
		phalcon_update_property_zval(this_ptr, SL("_request"), r0 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_response"), PH_NOISY_CC);
	if (!zend_is_true(t3)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_STATIC(r1, "phalcon\\response", "getinstance");
		phalcon_update_property_zval(this_ptr, SL("_response"), r1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, SL("_router"), PH_NOISY_CC);
	if (!zend_is_true(t4)) {
		PHALCON_INIT_VAR(router);
		object_init_ex(router, phalcon_router_rewrite_ce);
		PHALCON_CALL_METHOD_NORETURN(router, "__construct", PH_CHECK);
		PHALCON_CALL_METHOD_NORETURN(router, "handle", PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(router);
		phalcon_read_property(&router, this_ptr, SL("_router"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(base_path);
	phalcon_read_property(&base_path, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(view);
	PHALCON_CALL_METHOD(view, this_ptr, "getviewcomponent", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "setbasepath", base_path, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(view, "start", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_METHOD(model, this_ptr, "getmodelcomponent", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setbasepath", base_path, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setbasepath", base_path, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, router, "getcontrollername", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollername", r2, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, router, "getactionname", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setactionname", r3, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, router, "getparams", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setparams", r4, PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_dispatcher"), dispatcher TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_router"), router TSRMLS_CC);
	
	PHALCON_INIT_VAR(response);
	phalcon_read_property(&response, this_ptr, SL("_response"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, SL("_request"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_4_NORETURN(dispatcher, "dispatch", t5, response, view, model, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, dispatcher, "getcontrollername", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, dispatcher, "getactionname", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, dispatcher, "getparams", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(view, "render", r5, r6, r7, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(view, "finish", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, view, "getcontent", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(response, "setcontent", r8, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(response, "sendheaders", PH_NO_CHECK);
	
	RETURN_CCTOR(response);
}

/**
 * Gets Phalcon_Controller_Front singleton instance
 *
 * @return Phalcon_Controller_Front
 */
PHP_METHOD(Phalcon_Controller_Front, getInstance){

	zval *instance = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(instance);
	phalcon_read_static_property(&instance, SL("phalcon\\controller\\front"), SL("_instance") TSRMLS_CC);
	if (!zend_is_true(instance)) {
		PHALCON_INIT_VAR(instance);
		object_init_ex(instance, phalcon_controller_front_ce);
		PHALCON_CALL_METHOD_NORETURN(instance, "__construct", PH_CHECK);
		phalcon_update_static_property(SL("phalcon\\controller\\front"), SL("_instance"), instance TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(instance);
}

/**
 * Resets the internal singleton
 */
PHP_METHOD(Phalcon_Controller_Front, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	phalcon_update_static_property(SL("phalcon\\controller\\front"), SL("_instance"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

