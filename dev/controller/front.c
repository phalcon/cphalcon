
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

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
 * Gets Phalcon_Controller_Front singleton instance
 *
 * @return Phalcon_Controller_Front
 */
PHP_METHOD(Phalcon_Controller_Front, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_controller_front_ce, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_controller_front_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		zend_update_static_property(phalcon_controller_front_ce, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_controller_front_ce, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Modifies multipe general settings using a Phalcon_Config object or a stdClass filled with parameters
 *
 * 
 *
 * @param stdClass $config
 */
PHP_METHOD(Phalcon_Controller_Front, setConfig){

	zval *config = NULL, *phalcon = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(config) == IS_OBJECT) {
		eval_int = phalcon_isset_property(config, "database", strlen("database") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t0);
			phalcon_read_property(&t0, config, "database", sizeof("database")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_STATIC_PARAMS_1_NORETURN("phalcon_db_pool", "setdefaultdescriptor", t0);
		}
		eval_int = phalcon_isset_property(config, "phalcon", strlen("phalcon") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, config, "phalcon", sizeof("phalcon")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(phalcon, t1);
			eval_int = phalcon_isset_property(phalcon, "controllersDir", strlen("controllersDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t2);
				phalcon_read_property(&t2, phalcon, "controllersDir", sizeof("controllersDir")-1, PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), t2 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, "modelsDir", strlen("modelsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, phalcon, "modelsDir", sizeof("modelsDir")-1, PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), t3 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, "viewsDir", strlen("viewsDir") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t4);
				phalcon_read_property(&t4, phalcon, "viewsDir", sizeof("viewsDir")-1, PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), t4 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, "baseUri", strlen("baseUri") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t5);
				phalcon_read_property(&t5, phalcon, "baseUri", sizeof("baseUri")-1, PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), t5 TSRMLS_CC);
			}
			
			eval_int = phalcon_isset_property(phalcon, "basePath", strlen("basePath") TSRMLS_CC);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(t6);
				phalcon_read_property(&t6, phalcon, "basePath", sizeof("basePath")-1, PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), t6 TSRMLS_CC);
			}
			
		}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Config parameter should be an Object", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
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
 * Sets controllers directory
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

	
	phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), controllers_dir TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets models directory
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

	
	phalcon_update_property_zval(this_ptr, "_modelsDir", strlen("_modelsDir"), models_dir TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets views directory
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

	
	phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), views_dir TSRMLS_CC);
	
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

	
	phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), router TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
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

	
	phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), dispatcher TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Return active Dispatcher
 *
 * @return Phalcon_Dispatcher
 */
PHP_METHOD(Phalcon_Controller_Front, getDispatcher){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Dispatch process has not started yet", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	
	PHALCON_MM_RESTORE();
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

	
	phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), base_uri TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets external uri where app is executed
 *
 * @return string
 */
PHP_METHOD(Phalcon_Controller_Front, getBaseUri){

	zval *uri = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_baseUri", sizeof("_baseUri")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_get_global(&g0, "_SERVER", sizeof("_SERVER") TSRMLS_CC);
		eval_int = phalcon_array_isset_string(g0, "PHP_SELF", strlen("PHP_SELF")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "/", 1);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_string(&r4, g0, "PHP_SELF", strlen("PHP_SELF"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_1(r3, "dirname", r4, 0x048);
			PHALCON_CALL_FUNC_PARAMS_2(r2, "explode", c0, r3, 0x005);
			PHALCON_INIT_VAR(c1);
			ZVAL_LONG(c1, 1);
			PHALCON_INIT_VAR(t2);
			ZVAL_LONG(t2, 1);
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, -1);
			PHALCON_ALLOC_ZVAL_MM(r5);
			mul_function(r5, t1, t2 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_3(r1, "array_slice", r2, c1, r5, 0x01B);
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "/", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r0, "join", r1, c2, 0x00C);
			PHALCON_CPY_WRT(uri, r0);
		} else {
			PHALCON_INIT_VAR(uri);
			ZVAL_STRING(uri, "", 1);
		}
		if (!zend_is_true(uri)) {
			phalcon_update_property_string(this_ptr, "_baseUri", strlen("_baseUri"), "/" TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_BOTH(r6,  "/", uri, "/");
			phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), r6 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_baseUri", sizeof("_baseUri")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t3);
}

/**
 * Sets local path where app/ directory is located
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

	
	phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), base_path TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Overwrites request object default object
 *
 * @param Phalcon_Request $response
 */
PHP_METHOD(Phalcon_Controller_Front, setRequest){

	zval *request = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &request) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_request", strlen("_request"), request TSRMLS_CC);
	
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

	
	phalcon_update_property_zval(this_ptr, "_response", strlen("_response"), response TSRMLS_CC);
	
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

	
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), model TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_manager_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(model, i0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_modelsDir", sizeof("_modelsDir")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setmodelsdir", t1, PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), model TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
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

	
	phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), view TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets the views part manager
 *
 * @return Phalcon_View
 */
PHP_METHOD(Phalcon_Controller_Front, getViewComponent){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_view_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), i0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t1, "setviewsdir", t2, PHALCON_NO_CHECK);
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t3);
}

/**
 * Executes the dispatch loop
 *
 * @return Phalcon_View
 */
PHP_METHOD(Phalcon_Controller_Front, dispatchLoop){

	zval *dispatcher = NULL, *router = NULL, *view = NULL, *model = NULL, *response = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *p16[] = { NULL, NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_dispatcher_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(dispatcher, i0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setbasepath", t1, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollersdir", t2, PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(dispatcher, t3);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_request", sizeof("_request")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_request", "getinstance");
		phalcon_update_property_zval(this_ptr, "_request", strlen("_request"), r0 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_response", sizeof("_response")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t5)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_response", "getinstance");
		phalcon_update_property_zval(this_ptr, "_response", strlen("_response"), r1 TSRMLS_CC);
	}
	
	eval_int = phalcon_isset_property(this_ptr, "_router", strlen("_router") TSRMLS_CC);
	PHALCON_INIT_VAR(r2);
	ZVAL_BOOL(r2, !eval_int);
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_read_property(&t6, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	boolean_not_function(r3, t6 TSRMLS_CC);
	PHALCON_INIT_VAR(r4);
	ZVAL_BOOL(r4, zend_is_true(r2) || zend_is_true(r3));
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_router_rewrite_ce);
		PHALCON_CALL_METHOD_NORETURN(i1, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(router, i1);
		PHALCON_CALL_METHOD_NORETURN(router, "handle", PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_read_property(&t7, this_ptr, "_router", sizeof("_router")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(router, t7);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, this_ptr, "getviewcomponent", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(view, r5);
	PHALCON_CALL_METHOD_NORETURN(view, "start", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, this_ptr, "getmodelcomponent", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(model, r6);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, router, "getcontrollername", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollername", r7, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, router, "getactionname", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setactionname", r8, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, router, "getparams", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setparams", r9, PHALCON_NO_CHECK);
	phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), dispatcher TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_router", strlen("_router"), router TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, this_ptr, "_response", sizeof("_response")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(response, t8);
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, this_ptr, "_request", sizeof("_request")-1, PHALCON_NOISY TSRMLS_CC);
	p16[0] = t9;
	p16[1] = response;
	p16[2] = view;
	p16[3] = model;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(dispatcher, "dispatch", 4, p16, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CALL_METHOD(r10, dispatcher, "getcontrollername", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, dispatcher, "getactionname", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(view, "render", r10, r11, PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(view, "finish", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r12);
	PHALCON_CALL_METHOD(r12, view, "getcontent", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(response, "setcontent", r12, PHALCON_NO_CHECK);
	PHALCON_RETURN_CHECK_CTOR(response);
}

