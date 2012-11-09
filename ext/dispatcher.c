
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"

/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\CLI\Dispatcher
 */


PHP_METHOD(Phalcon_Dispatcher, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_dispatcher_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Dispatcher, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Dispatcher, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\Manager $eventsManager
 */
PHP_METHOD(Phalcon_Dispatcher, setEventsManager){

	zval *events_manager;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_Dispatcher, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Sets the default action suffix
 *
 * @param string $actionSuffix
 */
PHP_METHOD(Phalcon_Dispatcher, setActionSuffix){

	zval *action_suffix;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_suffix) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_actionSuffix"), action_suffix TSRMLS_CC);
	
}

/**
 * Sets the default namespace
 *
 * @param string $namespace
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace){

	zval *namespace;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &namespace) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultNamespace"), namespace TSRMLS_CC);
	
}

/**
 * Sets the default action name
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction){

	zval *action_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);
	
}

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName){

	zval *action_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &action_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	
}

/**
 * Gets last dispatched action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName){


	RETURN_MEMBER(this_ptr, "_actionName");
}

/**
 * Sets action params to be dispatched
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams){

	zval *params;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &params) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	
}

/**
 * Gets action params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Dispatcher, getParams){


	RETURN_MEMBER(this_ptr, "_params");
}

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed $param
 * @param  mixed $value
 */
PHP_METHOD(Phalcon_Dispatcher, setParam){

	zval *param, *value;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &param, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, param, &value, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_params"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed $param
 * @param  string|array $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getParam){

	zval *param, *filters = NULL, *params, *param_value, *dependency_injector;
	zval *exception_code, *exception_message;
	zval *service, *filter, *sanitized_value;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &param, &filters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!filters) {
		PHALCON_INIT_NVAR(filters);
	}
	
	PHALCON_INIT_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(params, param);
	if (eval_int) {
		PHALCON_INIT_VAR(param_value);
		phalcon_array_fetch(&param_value, params, param, PH_NOISY_CC);
		if (Z_TYPE_P(filters) != IS_NULL) {
			PHALCON_INIT_VAR(dependency_injector);
			phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_INIT_VAR(exception_code);
				ZVAL_LONG(exception_code, 0);
				
				PHALCON_INIT_VAR(exception_message);
				ZVAL_STRING(exception_message, "A dependency injection object is required to access the 'filter' service", 1);
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", exception_message, exception_code, PH_NO_CHECK);
			}
			
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "filter", 1);
			
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(sanitized_value);
			PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", param_value, filters, PH_NO_CHECK);
			
			RETURN_CCTOR(sanitized_value);
		} else {
			
			RETURN_CCTOR(param_value);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to disptach
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Dispatcher, isFinished){


	RETURN_MEMBER(this_ptr, "_finished");
}

/**
 * Returns value returned by the lastest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue){


	RETURN_MEMBER(this_ptr, "_returnedValue");
}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch){

	zval *dependency_injector, *exception_code = NULL;
	zval *exception_message = NULL, *events_manager;
	zval *event_name = NULL, *status = NULL, *value = NULL, *handler = NULL, *number_dispatches;
	zval *handler_suffix, *action_suffix, *default_namespace;
	zval *finished = NULL, *handler_name = NULL, *action_name = NULL;
	zval *camelized_class = NULL, *handler_class = NULL, *has_service = NULL;
	zval *was_fresh = NULL, *params = NULL, *action_method = NULL, *call_object = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(exception_code);
		ZVAL_LONG(exception_code, 0);
		
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "A dependency injection container is required to access related dispatching services", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", exception_message, exception_code, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeDispatchLoop", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(value);
	
	PHALCON_INIT_VAR(handler);
	
	PHALCON_INIT_VAR(number_dispatches);
	ZVAL_LONG(number_dispatches, 0);
	
	PHALCON_INIT_VAR(handler_suffix);
	phalcon_read_property(&handler_suffix, this_ptr, SL("_handlerSuffix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(action_suffix);
	phalcon_read_property(&action_suffix, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(default_namespace);
	phalcon_read_property(&default_namespace, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	ph_cycle_start_0:
		
		PHALCON_INIT_NVAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_finished"), PH_NOISY_CC);
		PHALCON_CPY_WRT(finished, t0);
		if (zend_is_true(finished)) {
			goto ph_cycle_end_0;
		}
		PHALCON_SEPARATE(number_dispatches);
		increment_function(number_dispatches);
		if (phalcon_compare_strict_long(number_dispatches, 256 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 1);
			
			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Dispatcher has detected a cyclic routing causing stability problems", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", exception_message, exception_code, PH_NO_CHECK);
			goto ph_cycle_end_0;
		}
		
		phalcon_update_property_bool(this_ptr, SL("_finished"), 1 TSRMLS_CC);
		
		PHALCON_INIT_NVAR(handler_name);
		phalcon_read_property(&handler_name, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		if (!zend_is_true(handler_name)) {
			PHALCON_INIT_NVAR(handler_name);
			phalcon_read_property(&handler_name, this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_handlerName"), handler_name TSRMLS_CC);
		}
		
		PHALCON_INIT_NVAR(action_name);
		phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
		if (!zend_is_true(action_name)) {
			PHALCON_INIT_NVAR(action_name);
			phalcon_read_property(&action_name, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
		}
		
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "dispatch:beforeDispatch", 1);
			
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
			if (PHALCON_IS_FALSE(status)) {
				goto ph_cycle_start_0;
			}
			
			PHALCON_INIT_NVAR(finished);
			phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
			if (PHALCON_IS_FALSE(finished)) {
				goto ph_cycle_start_0;
			}
		}
		
		if (!phalcon_memnstr_str(handler_name, SL("\\") TSRMLS_CC)) {
			PHALCON_INIT_NVAR(camelized_class);
			phalcon_camelize(camelized_class, handler_name TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(camelized_class, handler_name);
		}
		
		PHALCON_INIT_NVAR(handler_class);
		PHALCON_CONCAT_VVV(handler_class, default_namespace, camelized_class, handler_suffix);
		/** 
		 * Handlers are retrieved as shared instances from the Services Container
		 */
		PHALCON_INIT_NVAR(has_service);
		PHALCON_CALL_METHOD_PARAMS_1(has_service, dependency_injector, "has", handler_class, PH_NO_CHECK);
		if (!zend_is_true(has_service)) {
			PHALCON_INIT_NVAR(has_service);
			PHALCON_CALL_FUNC_PARAMS_1(has_service, "class_exists", handler_class);
		}
		
		if (!zend_is_true(has_service)) {
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 2);
			
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_VS(exception_message, handler_class, " handler class cannot be loaded");
			
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_throwdispatchexception", exception_message, exception_code, PH_NO_CHECK);
			if (PHALCON_IS_FALSE(status)) {
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
			
			goto ph_cycle_end_0;
		}
		
		/** 
		 * Handlers must be only objects
		 */
		PHALCON_INIT_NVAR(handler);
		PHALCON_CALL_METHOD_PARAMS_1(handler, dependency_injector, "getshared", handler_class, PH_NO_CHECK);
		if (Z_TYPE_P(handler) != IS_OBJECT) {
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 3);
			
			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Invalid handler returned from the services container", 1);
			
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_throwdispatchexception", exception_message, exception_code, PH_NO_CHECK);
			if (PHALCON_IS_FALSE(status)) {
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
			
			goto ph_cycle_end_0;
		}
		
		phalcon_update_property_zval(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
		
		PHALCON_INIT_NVAR(was_fresh);
		PHALCON_CALL_METHOD(was_fresh, dependency_injector, "wasfreshinstance", PH_NO_CHECK);
		if (PHALCON_IS_TRUE(was_fresh)) {
			if (phalcon_method_exists_ex(handler, SS("initialize") TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_METHOD_NORETURN(handler, "initialize", PH_NO_CHECK);
			}
		}
		
		PHALCON_INIT_NVAR(params);
		phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(params) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 4);
			
			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Action parameters must be an Array", 1);
			
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_throwdispatchexception", exception_message, exception_code, PH_NO_CHECK);
			if (PHALCON_IS_FALSE(status)) {
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
			
			goto ph_cycle_end_0;
		}
		
		PHALCON_INIT_NVAR(action_method);
		PHALCON_CONCAT_VV(action_method, action_name, action_suffix);
		if (phalcon_method_exists(handler, action_method TSRMLS_CC) == SUCCESS) {
			/** 
			 * Calling beforeExecuteRoute as callback and event
			 */
			if (phalcon_method_exists_ex(handler, SS("beforeexecuteroute") TSRMLS_CC) == SUCCESS) {
				/** 
				 * Calling beforeExecuteRoute as callback and event
				 */
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_1(status, handler, "beforeexecuteroute", this_ptr, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
					goto ph_cycle_start_0;
				}
				
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "dispatch:beforeExecuteRoute", 1);
				
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
					goto ph_cycle_start_0;
				}
				
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
			
			PHALCON_INIT_NVAR(call_object);
			array_init(call_object);
			phalcon_array_append(&call_object, handler, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&call_object, action_method, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_NVAR(value);
			PHALCON_CALL_USER_FUNC_ARRAY(value, call_object, params);
			/** 
			 * Calling afterExecuteRoute as callback and event
			 */
			if (phalcon_method_exists_ex(handler, SS("afterexecuteroute") TSRMLS_CC) == SUCCESS) {
				/** 
				 * Calling afterExecuteRoute as callback and event
				 */
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, handler, "afterexecuteroute", this_ptr, value, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
					goto ph_cycle_start_0;
				}
				
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
			
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "dispatch:afterExecuteRoute", 1);
				
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, value, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
					goto ph_cycle_start_0;
				}
				
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
		} else {
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "dispatch:beforeNotFoundAction", 1);
				
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
					goto ph_cycle_start_0;
				}
				
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
			
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 5);
			
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSVS(exception_message, "Action '", action_name, "' was not found on handler '", handler_name, "'");
			
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_throwdispatchexception", exception_message, exception_code, PH_NO_CHECK);
			if (PHALCON_IS_FALSE(status)) {
				PHALCON_INIT_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					goto ph_cycle_start_0;
				}
			}
			
			goto ph_cycle_end_0;
		}
		
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "dispatch:afterDispatch", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		}
		goto ph_cycle_start_0;
	ph_cycle_end_0:
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "dispatch:afterDispatchLoop", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_returnedValue"), value TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_lastHandler"), handler TSRMLS_CC);
	
	RETURN_CCTOR(handler);
}

/**
 * Forwards the execution flow to another controller/action
 *
 * @param array $forward
 */
PHP_METHOD(Phalcon_Dispatcher, forward){

	zval *forward, *exception_message, *controller_name;
	zval *task_name, *action_name, *params;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &forward) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(forward) != IS_ARRAY) { 
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "Forward parameter must be an Array", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_throwdispatchexception", exception_message, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	eval_int = phalcon_array_isset_string(forward, SS("controller"));
	if (eval_int) {
		PHALCON_INIT_VAR(controller_name);
		phalcon_array_fetch_string(&controller_name, forward, SL("controller"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_handlerName"), controller_name TSRMLS_CC);
	} else {
		eval_int = phalcon_array_isset_string(forward, SS("task"));
		if (eval_int) {
			PHALCON_INIT_VAR(task_name);
			phalcon_array_fetch_string(&task_name, forward, SL("task"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_handlerName"), task_name TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(forward, SS("action"));
	if (eval_int) {
		PHALCON_INIT_VAR(action_name);
		phalcon_array_fetch_string(&action_name, forward, SL("action"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(forward, SS("params"));
	if (eval_int) {
		PHALCON_INIT_VAR(params);
		phalcon_array_fetch_string(&params, forward, SL("params"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

