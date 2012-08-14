
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/exception.h"

/**
 * Phalcon\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 * 
 */

PHP_METHOD(Phalcon_Dispatcher, __construct){

	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_dispatcher_ce, this_ptr, SL("_controllers"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_dispatcher_ce, this_ptr, SL("_params"), a1 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets default controllers directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $controllersDir
 */
PHP_METHOD(Phalcon_Dispatcher, setControllersDir){

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
 * Gets active controllers directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getControllersDir){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_controllersDir"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Sets base path for controllers dir. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_Dispatcher, setBasePath){

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
 * Gets base path for controllers dir
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getBasePath){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultController){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultController"), controller_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default action name
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction){

	zval *action_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the controller name to be dispatched
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Dispatcher, setControllerName){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getControllerName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_controllerName"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName){

	zval *action_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets last dispatched action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_actionName"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Sets action params to be dispatched
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams){

	zval *params = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets action params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getParams){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed $param
 * @param  mixed $value 
 */
PHP_METHOD(Phalcon_Dispatcher, setParam){

	zval *param = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &param, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PH_NOISY_CC);
	phalcon_array_update(&t0, param, &value, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_params"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed $param
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getParam){

	zval *param = NULL, *params = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(params, param);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, params, param, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Dispatches a controller action taking into account the routing parameters
 *
 * @param Phalcon_Request $request
 * @param Phalcon_Response $response
 * @param Phalcon_View $view
 * @param Phalcon_Model_Manager $model
 * @return Phalcon_Controller
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch){

	zval *request = NULL, *response = NULL, *view = NULL, *model = NULL, *controllers_dir = NULL;
	zval *value = NULL, *controller = NULL, *number_dispatches = NULL;
	zval *controller_name = NULL, *controllers = NULL, *controller_class = NULL;
	zval *controller_path = NULL, *params = NULL, *action_name = NULL;
	zval *action_method = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &request, &response, &view, &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!view) {
		PHALCON_ALLOC_ZVAL_MM(view);
		ZVAL_NULL(view);
	}
	
	if (!model) {
		PHALCON_ALLOC_ZVAL_MM(model);
		ZVAL_NULL(model);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_basePath"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_controllersDir"), PH_NOISY_CC);
	PHALCON_INIT_VAR(controllers_dir);
	PHALCON_CONCAT_VV(controllers_dir, t0, t1);
	
	PHALCON_INIT_VAR(value);
	ZVAL_NULL(value);
	
	PHALCON_INIT_VAR(controller);
	ZVAL_NULL(controller);
	
	PHALCON_INIT_VAR(number_dispatches);
	ZVAL_LONG(number_dispatches, 0);
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	ws_e10f_0:
		
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, SL("_finished"), PH_NOISY_CC);
		if (zend_is_true(t2)) {
			goto we_e10f_0;
		}
		phalcon_update_property_bool(this_ptr, SL("_finished"), 1 TSRMLS_CC);
		
		PHALCON_INIT_VAR(controller_name);
		phalcon_read_property(&controller_name, this_ptr, SL("_controllerName"), PH_NOISY_CC);
		if (!zend_is_true(controller_name)) {
			PHALCON_INIT_VAR(controller_name);
			phalcon_read_property(&controller_name, this_ptr, SL("_defaultController"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(controllers);
		phalcon_read_property(&controllers, this_ptr, SL("_controllers"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon\\text", "camelize", controller_name);
		
		PHALCON_INIT_VAR(controller_class);
		PHALCON_CONCAT_VS(controller_class, r0, "Controller");
		eval_int = phalcon_array_isset(controllers, controller_class);
		if (!eval_int) {
			PHALCON_INIT_VAR(c0);
			ZVAL_BOOL(c0, 0);
			PHALCON_INIT_VAR(r1);
			PHALCON_CALL_FUNC_PARAMS_2(r1, "class_exists", controller_class, c0);
			if (!zend_is_true(r1)) {
				PHALCON_INIT_VAR(controller_path);
				PHALCON_CONCAT_VVS(controller_path, controllers_dir, controller_class, ".php");
				if (phalcon_file_exists(controller_path TSRMLS_CC) == SUCCESS) {
					if (phalcon_require(controller_path TSRMLS_CC) == FAILURE) {
						return;
					}
				} else {
					PHALCON_INIT_VAR(r2);
					PHALCON_CONCAT_SVS(r2, "File for controller class ", controller_class, " doesn't exist");
					PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", response, r2, PH_NO_CHECK);
				}
				
				PHALCON_INIT_VAR(c1);
				ZVAL_BOOL(c1, 0);
				
				PHALCON_INIT_VAR(r3);
				PHALCON_CALL_FUNC_PARAMS_2(r3, "class_exists", controller_class, c1);
				if (!zend_is_true(r3)) {
					PHALCON_INIT_VAR(r4);
					PHALCON_CONCAT_SVS(r4, "Class ", controller_class, " was not found on controller file");
					PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", response, r4, PH_NO_CHECK);
				}
			}
			ce0 = phalcon_fetch_class(controller_class TSRMLS_CC);
			
			PHALCON_INIT_VAR(controller);
			object_init_ex(controller, ce0);
			p0[0] = this_ptr;
			p0[1] = request;
			p0[2] = response;
			p0[3] = view;
			p0[4] = model;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(controller, "__construct", 5, p0, PH_CHECK);
			if (phalcon_method_exists_ex(controller, SL("initialize") TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_METHOD_NORETURN(controller, "initialize", PH_NO_CHECK);
			}
			
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, SL("_controllers"), PH_NOISY_CC);
			phalcon_array_update(&t3, controller_class, &controller, PH_COPY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_controllers"), t3 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(controller);
			phalcon_array_fetch(&controller, controllers, controller_class, PH_NOISY_CC);
		}
		
		PHALCON_INIT_VAR(params);
		phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(action_name);
		phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
		if (!zend_is_true(action_name)) {
			PHALCON_INIT_VAR(action_name);
			phalcon_read_property(&action_name, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
		}
		
		if (phalcon_method_exists_ex(controller, SL("beforedispatch") TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(r5);
			PHALCON_CALL_METHOD_PARAMS_3(r5, controller, "beforedispatch", controller_name, action_name, params, PH_NO_CHECK);
			if (Z_TYPE_P(r5) == IS_BOOL && !Z_BVAL_P(r5)) {
				PHALCON_INIT_VAR(value);
				ZVAL_BOOL(value, 0);
				goto we_e10f_0;
			}
		}
		
		PHALCON_INIT_VAR(action_method);
		PHALCON_CONCAT_VS(action_method, action_name, "Action");
		if (phalcon_method_exists(controller, action_method TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			phalcon_array_append(&a0, controller, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&a0, action_method, PH_SEPARATE TSRMLS_CC);
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_FUNC_PARAMS_2(value, "call_user_func_array", a0, params);
		} else {
			if (phalcon_method_exists_ex(controller, SL("notfoundaction") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_VAR(a1);
				array_init(a1);
				phalcon_array_append(&a1, controller, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(a1, SL("notFoundAction"), 1);
				PHALCON_INIT_VAR(value);
				PHALCON_CALL_FUNC_PARAMS_2(value, "call_user_func_array", a1, params);
			} else {
				PHALCON_INIT_VAR(r6);
				PHALCON_CONCAT_SVSVS(r6, "Action '", action_name, "' was not found on controller '", controller_name, "'");
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", response, r6, PH_NO_CHECK);
			}
		}
		
		if (phalcon_method_exists_ex(controller, SL("afterdispatch") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(controller, "afterdispatch", controller_name, action_name, params, PH_NO_CHECK);
		}
		
		PHALCON_SEPARATE(number_dispatches);
		increment_function(number_dispatches);
		
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 256);
		
		PHALCON_INIT_VAR(r7);
		is_smaller_function(r7, t4, number_dispatches TSRMLS_CC);
		if (zend_is_true(r7)) {
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "Dispatcher has detected a cyclic routing causing stability problems", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", response, c2, PH_NO_CHECK);
		}
		goto ws_e10f_0;
	we_e10f_0:
	phalcon_update_property_zval(this_ptr, SL("_returnedValue"), value TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_lastController"), controller TSRMLS_CC);
	
	RETURN_CCTOR(controller);
}

/**
 * Throws an internal exception
 *
 * @param Phalcon_Response $response
 * @param string $message
 */
PHP_METHOD(Phalcon_Dispatcher, _throwDispatchException){

	zval *response = NULL, *message = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &response, &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 404);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "Not Found", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(response, "setstatuscode", c0, c1, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_dispatcher_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", message, PH_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

/**
 * Routes to a controller/action using a string or array uri
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Dispatcher, forward){

	zval *uri = NULL, *parts = NULL, *params = NULL, *value = NULL, *key = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(uri) == IS_ARRAY) { 
		PHALCON_CPY_WRT(parts, uri);
	} else {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/", 1);
		PHALCON_INIT_VAR(parts);
		phalcon_fast_explode(parts, c0, uri TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_long(parts, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_long(&r0, parts, 0, PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_filter_alphanum(r1, r0);
		phalcon_update_property_zval(this_ptr, SL("_controllerName"), r1 TSRMLS_CC);
		PHALCON_SEPARATE(parts);
		phalcon_array_unset_long(parts, 0);
	} else {
		eval_int = phalcon_array_isset_string(parts, SL("controller")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_string(&r2, parts, SL("controller"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_filter_alphanum(r3, r2);
			phalcon_update_property_zval(this_ptr, SL("_controllerName"), r3 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "getcontrollername", PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("_controllerName"), r4 TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_long(parts, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_long(&r5, parts, 1, PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_filter_alphanum(r6, r5);
		phalcon_update_property_zval(this_ptr, SL("_actionName"), r6 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_long(&r7, parts, 1, PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_actionName"), r7 TSRMLS_CC);
		PHALCON_SEPARATE(parts);
		phalcon_array_unset_long(parts, 1);
	} else {
		eval_int = phalcon_array_isset_string(parts, SL("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r8);
			phalcon_array_fetch_string(&r8, parts, SL("action"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r9);
			phalcon_filter_alphanum(r9, r8);
			phalcon_update_property_zval(this_ptr, SL("_actionName"), r9 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r10);
			PHALCON_CALL_METHOD(r10, this_ptr, "getactionname", PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("_actionName"), r10 TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(params);
	array_init(params);
	if (phalcon_valid_foreach(parts TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(parts);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e10f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_e10f_1;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) == IS_LONG) {
			PHALCON_INIT_VAR(r11);
			phalcon_array_fetch(&r11, parts, key, PH_NOISY_CC);
			phalcon_array_append(&params, r11, PH_SEPARATE TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_e10f_1;
		fee_e10f_1:
		if(0){}
	} else {
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the dispatch loop is finished or have more pendent controller to disptach
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Dispatcher, isFinished){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_finished"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns all instantiated controllers whitin the dispatcher
 *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getControllers){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_controllers"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon_Controller
 */
PHP_METHOD(Phalcon_Dispatcher, getLastController){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_lastController"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns value returned by the lastest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_returnedValue"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

