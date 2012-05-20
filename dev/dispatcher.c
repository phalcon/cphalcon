
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
#include "kernel/operators.h"
#include "kernel/memory.h"

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

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_dispatcher_ce, this_ptr, "_controllers", strlen("_controllers"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_dispatcher_ce, this_ptr, "_params", strlen("_params"), a1 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets default controllers directory
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

	phalcon_update_property_zval(this_ptr, "_controllersDir", strlen("_controllersDir"), controllers_dir TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets base path for controllers dir
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

	phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), base_path TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets the controller name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher, setControllerName){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), controller_name TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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

	phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), action_name TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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

	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), params TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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

	zval *request = NULL, *response = NULL, *view = NULL, *model = NULL, *controllers_dir = NULL;
	zval *value = NULL, *controller = NULL, *number_dispatches = NULL;
	zval *controller_name = NULL, *controllers = NULL, *controller_class = NULL;
	zval *controller_path = NULL, *params = NULL, *action_name = NULL;
	zval *action_method = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p5[] = { NULL, NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &request, &response, &view, &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!view) {
		PHALCON_INIT_VAR(view);
		ZVAL_NULL(view);
	}
	
	if (!model) {
		PHALCON_INIT_VAR(model);
		ZVAL_NULL(model);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_controllersDir", sizeof("_controllersDir")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(controllers_dir, r0);
	PHALCON_INIT_VAR(value);
	ZVAL_NULL(value);
	PHALCON_INIT_VAR(controller);
	ZVAL_NULL(controller);
	PHALCON_INIT_VAR(number_dispatches);
	ZVAL_LONG(number_dispatches, 0);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 0 TSRMLS_CC);
	ws_e10f_0:
		
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, "_finished", sizeof("_finished")-1, PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(t2)) {
			goto we_e10f_0;
		}
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 1 TSRMLS_CC);
		
		PHALCON_INIT_VAR(t3);
		phalcon_read_property(&t3, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(controller_name, t3);
		if (!zend_is_true(controller_name)) {
			PHALCON_INIT_VAR(t4);
			phalcon_read_property(&t4, this_ptr, "_defaultController", sizeof("_defaultController")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(controller_name, t4);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), controller_name TSRMLS_CC);
		}
		
		
		PHALCON_INIT_VAR(t5);
		phalcon_read_property(&t5, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(controllers, t5);
		
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_STATIC_PARAMS_1(r1, "phalcon_text", "camelize", controller_name);
		
		PHALCON_INIT_VAR(r2);
		PHALCON_CONCAT_RIGHT(r2, r1, "Controller");
		PHALCON_CPY_WRT(controller_class, r2);
		eval_int = phalcon_array_isset(controllers, controller_class);
		if (!eval_int) {
			PHALCON_INIT_VAR(r3);
			PHALCON_INIT_VAR(c0);
			ZVAL_BOOL(c0, 0);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "class_exists", controller_class, c0, 0x012);
			if (!zend_is_true(r3)) {
				PHALCON_INIT_VAR(r4);
				concat_function(r4, controllers_dir, controller_class TSRMLS_CC);
				PHALCON_INIT_VAR(r5);
				PHALCON_CONCAT_RIGHT(r5, r4, ".php");
				PHALCON_CPY_WRT(controller_path, r5);
				if (phalcon_file_exists(controller_path TSRMLS_CC) == SUCCESS) {
					if (phalcon_require(controller_path TSRMLS_CC) == FAILURE) {
						return;
					}
				} else {
					PHALCON_INIT_VAR(i0);
					object_init_ex(i0, phalcon_exception_ce);
					PHALCON_INIT_VAR(r6);
					PHALCON_CONCAT_BOTH(r6,  "File for controller class ", controller_class, " doesn't exist");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r6, PHALCON_CHECK);
					phalcon_throw_exception(i0 TSRMLS_CC);
					return;
				}
				
				
				PHALCON_INIT_VAR(r7);
				PHALCON_INIT_VAR(c1);
				ZVAL_BOOL(c1, 0);
				PHALCON_CALL_FUNC_PARAMS_2(r7, "class_exists", controller_class, c1, 0x012);
				if (!zend_is_true(r7)) {
					PHALCON_INIT_VAR(i1);
					object_init_ex(i1, phalcon_exception_ce);
					PHALCON_INIT_VAR(r8);
					PHALCON_CONCAT_BOTH(r8,  "Class ", controller_class, " was not found on controller file");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r8, PHALCON_CHECK);
					phalcon_throw_exception(i1 TSRMLS_CC);
					return;
				}
			}
			ce0 = phalcon_fetch_class(controller_class TSRMLS_CC);
			
			PHALCON_INIT_VAR(i2);
			object_init_ex(i2, ce0);
			p5[0] = this_ptr;
			p5[1] = request;
			p5[2] = response;
			p5[3] = view;
			p5[4] = model;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 5, p5, PHALCON_CHECK);
			PHALCON_CPY_WRT(controller, i2);
			if (phalcon_method_exists_ex(controller, "initialize", strlen("initialize") TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_METHOD_NORETURN(controller, "initialize", PHALCON_NO_CHECK);
			}
			
			
			PHALCON_INIT_VAR(t6);
			phalcon_read_property(&t6, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update(&t6, controller_class, &controller, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_controllers", strlen("_controllers"), t6 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(r9);
			phalcon_array_fetch(&r9, controllers, controller_class, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(controller, r9);
		}
		
		
		PHALCON_INIT_VAR(t7);
		phalcon_read_property(&t7, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(params, t7);
		
		PHALCON_INIT_VAR(t8);
		phalcon_read_property(&t8, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(action_name, t8);
		if (!zend_is_true(action_name)) {
			PHALCON_INIT_VAR(t9);
			phalcon_read_property(&t9, this_ptr, "_defaultAction", sizeof("_defaultAction")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(action_name, t9);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), action_name TSRMLS_CC);
		}
		
		if (phalcon_method_exists_ex(controller, "beforedispatch", strlen("beforedispatch") TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(r10);
			PHALCON_CALL_METHOD_PARAMS_3(r10, controller, "beforedispatch", controller_name, action_name, params, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r10) == IS_BOOL && !Z_BVAL_P(r10)) {
				PHALCON_INIT_VAR(value);
				ZVAL_BOOL(value, 0);
				goto we_e10f_0;
			}
		}
		
		
		PHALCON_INIT_VAR(r11);
		PHALCON_CONCAT_RIGHT(r11, action_name, "Action");
		PHALCON_CPY_WRT(action_method, r11);
		if (phalcon_method_exists(controller, action_method TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(r12);
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			phalcon_array_append(&a0, controller, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a0, action_method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_2(r12, "call_user_func_array", a0, params, 0x013);
			PHALCON_CPY_WRT(value, r12);
		} else {
			if (phalcon_method_exists_ex(controller, "notfoundaction", strlen("notfoundaction") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_VAR(r13);
				PHALCON_INIT_VAR(a1);
				array_init(a1);
				phalcon_array_append(&a1, controller, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				add_next_index_stringl(a1, "notFoundAction", strlen("notFoundAction"), 1);
				PHALCON_CALL_FUNC_PARAMS_2(r13, "call_user_func_array", a1, params, 0x013);
				PHALCON_CPY_WRT(value, r13);
			} else {
				PHALCON_INIT_VAR(c2);
				ZVAL_LONG(c2, 404);
				PHALCON_INIT_VAR(c3);
				ZVAL_STRING(c3, "Not Found", 1);
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(response, "setstatuscode", c2, c3, PHALCON_NO_CHECK);
				
				PHALCON_INIT_VAR(i3);
				object_init_ex(i3, phalcon_exception_ce);
				
				PHALCON_INIT_VAR(r15);
				PHALCON_CONCAT_LEFT(r15, "Action '", action_name);
				
				PHALCON_INIT_VAR(r14);
				PHALCON_CONCAT_VBOTH(r14, r15, "' was not found on controller '", controller_name);
				
				PHALCON_INIT_VAR(r16);
				PHALCON_CONCAT_RIGHT(r16, r14, "'");
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i3, "__construct", r16, PHALCON_CHECK);
				phalcon_throw_exception(i3 TSRMLS_CC);
				return;
			}
		}
		
		if (phalcon_method_exists_ex(controller, "afterdispatch", strlen("afterdispatch") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(controller, "afterdispatch", controller_name, action_name, params, PHALCON_NO_CHECK);
		}
		
		PHALCON_SEPARATE(number_dispatches);
		increment_function(number_dispatches);
		PHALCON_INIT_VAR(t10);
		ZVAL_LONG(t10, 256);
		PHALCON_INIT_VAR(r17);
		is_smaller_function(r17, t10, number_dispatches TSRMLS_CC);
		if (zend_is_true(r17)) {
			PHALCON_INIT_VAR(i4);
			object_init_ex(i4, phalcon_exception_ce);
			PHALCON_INIT_VAR(c4);
			ZVAL_STRING(c4, "Dispatcher has detected a cyclic routing causing stability problems", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i4, "__construct", c4, PHALCON_CHECK);
			phalcon_throw_exception(i4 TSRMLS_CC);
			return;
		}
		goto ws_e10f_0;
	we_e10f_0:
	if(0) { };
	phalcon_update_property_zval(this_ptr, "_returnedValue", strlen("_returnedValue"), value TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_lastController", strlen("_lastController"), controller TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(controller);
}

/**
 * Routes to a controller/action using a string or array uri
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Dispatcher, forward){

	zval *uri = NULL, *parts = NULL, *params = NULL, *value = NULL, *key = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "explode", c0, uri, 0x009);
		PHALCON_CPY_WRT(parts, r0);
	}
	eval_int = phalcon_array_isset_long(parts, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_long(&r1, parts, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_filter_alphanum(r2, r1);
		phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), r2 TSRMLS_CC);
		PHALCON_SEPARATE(parts);
		phalcon_array_unset_long(parts, 0);
	} else {
		eval_int = phalcon_array_isset_string(parts, "controller", strlen("controller")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, parts, "controller", strlen("controller"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_filter_alphanum(r4, r3);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), r4 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, this_ptr, "getcontrollername", PHALCON_NO_CHECK);
			phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), r5 TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_long(parts, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_long(&r6, parts, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_filter_alphanum(r7, r6);
		phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), r7 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_long(&r8, parts, 1, PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), r8 TSRMLS_CC);
		PHALCON_SEPARATE(parts);
		phalcon_array_unset_long(parts, 1);
	} else {
		eval_int = phalcon_array_isset_string(parts, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r9);
			phalcon_array_fetch_string(&r9, parts, "action", strlen("action"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r10);
			phalcon_filter_alphanum(r10, r9);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), r10 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_CALL_METHOD(r11, this_ptr, "getactionname", PHALCON_NO_CHECK);
			phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), r11 TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(params, a0);
	if (phalcon_valid_foreach(parts TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(parts);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e10f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_e10f_1;
		} else {
			PHALCON_INIT_VAR(key);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(key, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(key, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) == IS_LONG) {
			PHALCON_INIT_VAR(r12);
			phalcon_array_fetch(&r12, parts, key, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_append(&params, r12, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_e10f_1;
		fee_e10f_1:
		if(0){ };
	}
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), params TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_finished", strlen("_finished"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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
	phalcon_read_property(&t0, this_ptr, "_controllers", sizeof("_controllers")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns last dispatched controller
 *
 * @return Phalcon_Controller
 */
PHP_METHOD(Phalcon_Dispatcher, getLastController){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_lastController", sizeof("_lastController")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns value returned by last dispacthed action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_returnedValue", sizeof("_returnedValue")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

