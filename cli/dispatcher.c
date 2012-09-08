
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
  |          Rack Lin <racklin@gmail.com>                                  |
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\CLI\Dispatcher
 *
 * Dispatching is the process of taking the command-line arguments, extracting the module name,
 * task name, action name, and optional parameters contained in it, and then
 * instantiating a task and calling an action of that task.
 *
 *<code>
 *
 *	$di = new Phalcon\DI();
 *
 *	$dispatcher = new Phalcon\CLI\Dispatcher();
 *
 *  $dispatcher->setDI($di);
 *
 *	$dispatcher->setControllerName('posts');
 *	$dispatcher->setActionName('index');
 *	$dispatcher->setParams(array());
 *
 *	$controller = $dispatcher->dispatch();
 *
 *</code>
 */

PHP_METHOD(Phalcon_CLI_Dispatcher, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_cli_dispatcher_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\Manager $eventsManager
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setEventsManager){

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getEventsManager){

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	RETURN_CCTOR(events_manager);
}

/**
 * Sets the default namespace
 *
 * @param string $namespace
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setDefaultNamespace){

	zval *namespace = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &namespace) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultNamespace"), namespace TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default task name
 *
 * @param string $taskName
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setDefaultTask){

	zval *task_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &task_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultTask"), task_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default action name
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setDefaultAction){

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
 * Sets the task name to be dispatched
 *
 * @param string $taskName
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskName){

	zval *task_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &task_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_taskName"), task_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets last dispatched task name
 *
 * @return string
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getTaskName){

	zval *task_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(task_name);
	phalcon_read_property(&task_name, this_ptr, SL("_taskName"), PH_NOISY_CC);
	
	RETURN_CCTOR(task_name);
}

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setActionName){

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
PHP_METHOD(Phalcon_CLI_Dispatcher, getActionName){

	zval *action_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(action_name);
	phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
	
	RETURN_CCTOR(action_name);
}

/**
 * Sets action params to be dispatched
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setParams){

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
PHP_METHOD(Phalcon_CLI_Dispatcher, getParams){

	zval *params = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(params);
}

/**
 * Dispatches a controller action taking into account the routing parameters
 *
 * @return Phalcon\Mvc\Controller
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, dispatch){

	zval *dependency_injector = NULL, *events_manager = NULL;
	zval *event_name = NULL, *status = NULL, *value = NULL, *task = NULL;
	zval *number_dispatches = NULL, *maximum_routes = NULL;
	zval *default_namespace = NULL, *finished = NULL, *task_name = NULL;
	zval *has_namespace = NULL, *camelized_class = NULL, *task_class = NULL;
	zval *has_service = NULL, *exception_message = NULL, *action_name = NULL;
	zval *action_method = NULL, *params = NULL, *call_object = NULL, *cyclic_routing = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cli_dispatcher_exception_ce, "A dependency injection container is required to access related dispatching services");
		return;
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeDispatchLoop", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(value);
	ZVAL_NULL(value);
	
	PHALCON_INIT_VAR(task);
	ZVAL_NULL(task);
	
	PHALCON_INIT_VAR(number_dispatches);
	ZVAL_LONG(number_dispatches, 0);
	
	PHALCON_INIT_VAR(maximum_routes);
	ZVAL_LONG(maximum_routes, 256);
	
	PHALCON_INIT_VAR(default_namespace);
	phalcon_read_property(&default_namespace, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	ws_1d57_0:
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_finished"), PH_NOISY_CC);
		PHALCON_CPY_WRT(finished, t0);
		if (zend_is_true(finished)) {
			goto we_1d57_0;
		}
		phalcon_update_property_bool(this_ptr, SL("_finished"), 1 TSRMLS_CC);
		
		PHALCON_INIT_VAR(task_name);
		phalcon_read_property(&task_name, this_ptr, SL("_taskName"), PH_NOISY_CC);
		if (!zend_is_true(task_name)) {
			PHALCON_INIT_VAR(task_name);
			phalcon_read_property(&task_name, this_ptr, SL("_defaultTask"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_taskName"), task_name TSRMLS_CC);
		}
		
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "dispatch:beforeDispatch", 1);
			
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				goto ws_1d57_0;
			}
			
			PHALCON_INIT_VAR(finished);
			phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
			if (Z_TYPE_P(finished) == IS_BOOL && !Z_BVAL_P(finished)) {
				goto ws_1d57_0;
			}
		}
		
		PHALCON_INIT_VAR(has_namespace);
		phalcon_fast_strpos_str(has_namespace, task_name, SL("\\") TSRMLS_CC);
		if (Z_TYPE_P(has_namespace) == IS_BOOL && !Z_BVAL_P(has_namespace)) {
			PHALCON_INIT_VAR(camelized_class);
			PHALCON_CALL_STATIC_PARAMS_1(camelized_class, "phalcon\\text", "camelize", task_name);
		} else {
			PHALCON_CPY_WRT(camelized_class, task_name);
		}
		
		PHALCON_INIT_VAR(task_class);
		PHALCON_CONCAT_VVS(task_class, default_namespace, camelized_class, "Task");
		
		PHALCON_INIT_VAR(has_service);
		PHALCON_CALL_METHOD_PARAMS_1(has_service, dependency_injector, "has", task_class, PH_NO_CHECK);
		if (!zend_is_true(has_service)) {
			PHALCON_INIT_VAR(has_service);
			PHALCON_CALL_FUNC_PARAMS_1(has_service, "class_exists", task_class);
		}
		
		if (!zend_is_true(has_service)) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_VS(exception_message, task_class, " task class cannot be loaded");
            PHALCON_THROW_EXCEPTION_STR(phalcon_cli_dispatcher_exception_ce, Z_STRVAL_P(exception_message));
            return;
		}
		
		PHALCON_INIT_VAR(task);
		PHALCON_CALL_METHOD_PARAMS_1(task, dependency_injector, "getshared", task_class, PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_activeTask"), task TSRMLS_CC);
		if (phalcon_method_exists_ex(task, SL("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(task, "initialize", PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(action_name);
		phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
		if (!zend_is_true(action_name)) {
			PHALCON_INIT_VAR(action_name);
			phalcon_read_property(&action_name, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(action_method);
		PHALCON_CONCAT_VS(action_method, action_name, "Action");
		if (phalcon_method_exists(task, action_method TSRMLS_CC) == SUCCESS) {
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "dispatch:beforeExecuteRoute", 1);
				
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
					goto ws_1d57_0;
				}
				
				PHALCON_INIT_VAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (Z_TYPE_P(finished) == IS_BOOL && !Z_BVAL_P(finished)) {
					goto ws_1d57_0;
				}
			}
			
			PHALCON_INIT_VAR(params);
			phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(call_object);
			array_init(call_object);
			phalcon_array_append(&call_object, task, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&call_object, action_method, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_FUNC_PARAMS_2(value, "call_user_func_array", call_object, params);
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "dispatch:afterExecuteRoute", 1);
				
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
					goto ws_1d57_0;
				}
				
				PHALCON_INIT_VAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (Z_TYPE_P(finished) == IS_BOOL && !Z_BVAL_P(finished)) {
					goto ws_1d57_0;
				}
			}
		} else {
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "dispatch:beforeNotFoundAction", 1);
				
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
					goto ws_1d57_0;
				}
				
				PHALCON_INIT_VAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (Z_TYPE_P(finished) == IS_BOOL && !Z_BVAL_P(finished)) {
					goto ws_1d57_0;
				}
			}
			if (phalcon_method_exists_ex(task, SL("notfoundaction") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_VAR(call_object);
				array_init(call_object);
				phalcon_array_append(&call_object, task, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(call_object, SL("notFoundAction"), 1);
				
				PHALCON_INIT_VAR(value);
				PHALCON_CALL_FUNC_PARAMS_2(value, "call_user_func_array", call_object, params);
			} else {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Action '", action_name, "' was not found on task '", task_name, "'");
                PHALCON_THROW_EXCEPTION_STR(phalcon_cli_dispatcher_exception_ce, Z_STRVAL_P(exception_message));
                return;                
			}
		}
		
		PHALCON_SEPARATE(number_dispatches);
		increment_function(number_dispatches);
		
		PHALCON_INIT_VAR(cyclic_routing);
		is_smaller_function(cyclic_routing, maximum_routes, number_dispatches TSRMLS_CC);
		if (Z_TYPE_P(cyclic_routing) == IS_BOOL && Z_BVAL_P(cyclic_routing)) {
            PHALCON_THROW_EXCEPTION_STR(phalcon_cli_dispatcher_exception_ce, "Dispatcher has detected a cyclic routing causing stability problems");
            return;
		}
		
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "dispatch:afterDispatch", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		}
		goto ws_1d57_0;
	we_1d57_0:
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:afterDispatchLoop", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_returnedValue"), value TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_lastTask"), task TSRMLS_CC);
	
	RETURN_CCTOR(task);
}

/**
 * @param array $forward
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, forward){

	zval *forward = NULL, *task_name = NULL, *action_name = NULL;
	zval *params = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &forward) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(forward) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_cli_dispatcher_exception_ce, "$forward parameter must be an Array");
		return;
	}
	eval_int = phalcon_array_isset_string(forward, SL("task")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(task_name);
		phalcon_array_fetch_string(&task_name, forward, SL("task"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_taskName"), task_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(forward, SL("action")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(action_name);
		phalcon_array_fetch_string(&action_name, forward, SL("action"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(forward, SL("params")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(params);
		phalcon_array_fetch_string(&params, forward, SL("params"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the dispatch loop is finished or have more pendent controller to disptach
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, isFinished){

	zval *finished = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(finished);
	phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
	
	RETURN_CCTOR(finished);
}

/**
 * Returns the lastest dispatched task
 *
 * @return Phalcon\CLI\Task
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getLastTask){

	zval *last_task = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(last_task);
	phalcon_read_property(&last_task, this_ptr, SL("_lastTask"), PH_NOISY_CC);
	
	RETURN_CCTOR(last_task);
}

/**
 * Returns value returned by the lastest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getReturnedValue){

	zval *returned_value = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(returned_value);
	phalcon_read_property(&returned_value, this_ptr, SL("_returnedValue"), PH_NOISY_CC);
	
	RETURN_CCTOR(returned_value);
}

/**
 * Returns the active task in the dispatcher
 *
 * @return Phalcon\CLI\Task
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getActiveTask){

	zval *task = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(task);
	phalcon_read_property(&task, this_ptr, SL("_activeTask"), PH_NOISY_CC);
	
	RETURN_CCTOR(task);
}

