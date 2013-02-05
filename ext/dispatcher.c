
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"

/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\CLI\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own dispatchers
 */


/**
 * Phalcon\Dispatcher initializer
 */
PHALCON_INIT_CLASS(Phalcon_Dispatcher){

	PHALCON_REGISTER_CLASS(Phalcon, Dispatcher, dispatcher, phalcon_dispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_activeHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_finished"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_namespaceName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_handlerName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_actionName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_returnedValue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_lastHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_defaultNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_defaultHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_defaultAction"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_handlerSuffix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_actionSuffix"), "Action", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_NO_DI"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_CYCLIC_ROUTING"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_HANDLER_NOT_FOUND"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_INVALID_HANDLER"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_INVALID_PARAMS"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_ACTION_NOT_FOUND"), 5 TSRMLS_CC);

	zend_class_implements(phalcon_dispatcher_ce TSRMLS_CC, 3, phalcon_dispatcherinterface_ce, phalcon_di_injectionawareinterface_ce, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Dispatcher constructor
 */
PHP_METHOD(Phalcon_Dispatcher, __construct){


	phalcon_update_property_empty_array(phalcon_dispatcher_ce, this_ptr, SL("_params") TSRMLS_CC);
	
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
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
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Dispatcher, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
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
 * @return Phalcon\Events\ManagerInterface
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
 * Sets a namespace to be prepended to the handler name
 *
 * @param string $namespaceName
 */
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName){

	zval *namespace_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &namespace_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_namespaceName"), namespace_name TSRMLS_CC);
	
}

/**
 * Gets a namespace to be prepended to the current handler name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName){


	RETURN_MEMBER(this_ptr, "_namespaceName");
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
 * Returns the default namespace
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace){


	RETURN_MEMBER(this_ptr, "_defaultNamespace");
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
 * Gets the lastest dispatched action name
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

	zval *params, *exception_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &params) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(params) != IS_ARRAY) { 
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "Parameters must be an Array", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_throwdispatchexception", exception_message);
		RETURN_MM_NULL();
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &param, &value) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_array(this_ptr, SL("_params"), param, value TSRMLS_CC);
	
}

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed $param
 * @param  string|array $filters
 * @param  mixed $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getParam){

	zval *param, *filters = NULL, *default_value = NULL, *params;
	zval *param_value, *dependency_injector, *exception_code;
	zval *exception_message, *service, *filter, *sanitized_value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &param, &filters, &default_value) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!filters) {
		PHALCON_INIT_VAR(filters);
	}
	
	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset(params, param)) {
	
		PHALCON_OBS_VAR(param_value);
		phalcon_array_fetch(&param_value, params, param, PH_NOISY_CC);
		if (Z_TYPE_P(filters) != IS_NULL) {
	
			PHALCON_OBS_VAR(dependency_injector);
			phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_INIT_VAR(exception_code);
				ZVAL_LONG(exception_code, 0);
	
				PHALCON_INIT_VAR(exception_message);
				ZVAL_STRING(exception_message, "A dependency injection object is required to access the 'filter' service", 1);
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", exception_message, exception_code);
			}
	
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "filter", 1);
	
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service);
	
			PHALCON_INIT_VAR(sanitized_value);
			PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", param_value, filters);
	
			RETURN_CCTOR(sanitized_value);
		} else {
			RETURN_CCTOR(param_value);
		}
	}
	
	
	RETURN_CCTOR(default_value);
}

/**
 * Returns the current method to be/executed in the dispatcher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getActiveMethod){

	zval *suffix, *action_name, *method_name;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(suffix);
	phalcon_read_property(&suffix, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(action_name);
	phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(method_name);
	PHALCON_CONCAT_VV(method_name, action_name, suffix);
	RETURN_CTOR(method_name);
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
 * Sets the latest returned value by an action manually
 *
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Dispatcher, setReturnedValue){

	zval *value;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &value) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_returnedValue"), value TSRMLS_CC);
	
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
	zval *handler_suffix, *action_suffix, *_finished = NULL;
	zval *namespace_name = NULL, *handler_name = NULL, *action_name = NULL;
	zval *finished = NULL, *camelized_class = NULL, *handler_class = NULL;
	zval *has_service = NULL, *was_fresh = NULL, *params = NULL, *action_method = NULL;
	zval *call_object = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(exception_code);
		ZVAL_LONG(exception_code, 0);
	
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "A dependency injection container is required to access related dispatching services", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", exception_message, exception_code);
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Calling beforeDispatchLoop
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeDispatchLoop", 1);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(value);
	
	PHALCON_INIT_VAR(handler);
	
	PHALCON_INIT_VAR(number_dispatches);
	ZVAL_LONG(number_dispatches, 0);
	
	PHALCON_OBS_VAR(handler_suffix);
	phalcon_read_property(&handler_suffix, this_ptr, SL("_handlerSuffix"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(action_suffix);
	phalcon_read_property(&action_suffix, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	
	while (1) {
	
		PHALCON_OBS_NVAR(_finished);
		phalcon_read_property(&_finished, this_ptr, SL("_finished"), PH_NOISY_CC);
		if (!zend_is_true(_finished)) {
		} else {
			break;
		}
	
		PHALCON_SEPARATE(number_dispatches);
		increment_function(number_dispatches);
	
		/** 
		 * Throw an exception after 256 consecutive forwards
		 */
		if (PHALCON_IS_LONG(number_dispatches, 256)) {
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 1);
	
			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Dispatcher has detected a cyclic routing causing stability problems", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "_throwdispatchexception", exception_message, exception_code);
			break;
		}
	
		phalcon_update_property_bool(this_ptr, SL("_finished"), 1 TSRMLS_CC);
	
		/** 
		 * If the current namespace is null we used the set in this_ptr::_defaultNamespace
		 */
		PHALCON_OBS_NVAR(namespace_name);
		phalcon_read_property(&namespace_name, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		if (!zend_is_true(namespace_name)) {
			PHALCON_OBS_NVAR(namespace_name);
			phalcon_read_property(&namespace_name, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_namespaceName"), namespace_name TSRMLS_CC);
		}
	
		/** 
		 * If the handler is null we use the set in this_ptr::_defaultHandler
		 */
		PHALCON_OBS_NVAR(handler_name);
		phalcon_read_property(&handler_name, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		if (!zend_is_true(handler_name)) {
			PHALCON_OBS_NVAR(handler_name);
			phalcon_read_property(&handler_name, this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_handlerName"), handler_name TSRMLS_CC);
		}
	
		/** 
		 * If the action is null we use the set in this_ptr::_defaultAction
		 */
		PHALCON_OBS_NVAR(action_name);
		phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
		if (!zend_is_true(action_name)) {
			PHALCON_OBS_NVAR(action_name);
			phalcon_read_property(&action_name, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
		}
	
		/** 
		 * Calling beforeDispatch
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "dispatch:beforeDispatch", 1);
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr);
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}
	
			/** 
			 * Check if the user made a forward in the listener
			 */
			PHALCON_OBS_NVAR(finished);
			phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
			if (PHALCON_IS_FALSE(finished)) {
				continue;
			}
		}
	
		/** 
		 * We don't camelize the classes if they are in namespaces
		 */
		if (!phalcon_memnstr_str(handler_name, SL("\\") TSRMLS_CC)) {
			PHALCON_INIT_NVAR(camelized_class);
			phalcon_camelize(camelized_class, handler_name TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(camelized_class, handler_name);
		}
	
		/** 
		 * Create the complete controller class name prepending the namespace
		 */
		if (zend_is_true(namespace_name)) {
			if (phalcon_end_with_str(namespace_name, SL("\\"))) {
				PHALCON_INIT_NVAR(handler_class);
				PHALCON_CONCAT_VVV(handler_class, namespace_name, camelized_class, handler_suffix);
			} else {
				PHALCON_INIT_NVAR(handler_class);
				PHALCON_CONCAT_VSVV(handler_class, namespace_name, "\\", camelized_class, handler_suffix);
			}
		} else {
			PHALCON_INIT_NVAR(handler_class);
			PHALCON_CONCAT_VV(handler_class, camelized_class, handler_suffix);
		}
	
		/** 
		 * Handlers are retrieved as shared instances from the Service Container
		 */
		PHALCON_INIT_NVAR(has_service);
		PHALCON_CALL_METHOD_PARAMS_1(has_service, dependency_injector, "has", handler_class);
		if (!zend_is_true(has_service)) {
			/** 
			 * DI doesn't have a service with that name, try to load it using an autoloader
			 */
			PHALCON_INIT_NVAR(has_service);
			PHALCON_CALL_FUNC_PARAMS_1(has_service, "class_exists", handler_class);
		}
	
		/** 
		 * If the service can be loaded we throw an exception
		 */
		if (!zend_is_true(has_service)) {
	
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 2);
	
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_VS(exception_message, handler_class, " handler class cannot be loaded");
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			if (PHALCON_IS_FALSE(status)) {
	
				/** 
				 * Check if the user made a forward in the listener
				 */
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
	
			break;
		}
	
		/** 
		 * Handlers must be only objects
		 */
		PHALCON_INIT_NVAR(handler);
		PHALCON_CALL_METHOD_PARAMS_1(handler, dependency_injector, "getshared", handler_class);
		if (Z_TYPE_P(handler) != IS_OBJECT) {
	
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 3);
	
			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Invalid handler returned from the services container", 1);
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			if (PHALCON_IS_FALSE(status)) {
	
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
	
			break;
		}
	
		phalcon_update_property_zval(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
	
		/** 
		 * If the object was recently created in the DI we initialize it
		 */
		PHALCON_INIT_NVAR(was_fresh);
		PHALCON_CALL_METHOD(was_fresh, dependency_injector, "wasfreshinstance");
		if (PHALCON_IS_TRUE(was_fresh)) {
			if (phalcon_method_exists_ex(handler, SS("initialize") TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_METHOD_NORETURN(handler, "initialize");
			}
		}
	
		/** 
		 * Check if the params is an array
		 */
		PHALCON_OBS_NVAR(params);
		phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(params) != IS_ARRAY) { 
	
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 4);
	
			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Action parameters must be an Array", 1);
	
			/** 
			 * An invalid parameter variable was passed throw an exception
			 */
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			if (PHALCON_IS_FALSE(status)) {
	
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
	
			break;
		}
	
		/** 
		 * Check if the method exists in the handler
		 */
		PHALCON_INIT_NVAR(action_method);
		PHALCON_CONCAT_VV(action_method, action_name, action_suffix);
		if (phalcon_method_exists(handler, action_method TSRMLS_CC) == SUCCESS) {
	
			/** 
			 * Calling beforeExecuteRoute as callback and event
			 */
			if (phalcon_method_exists_ex(handler, SS("beforeexecuteroute") TSRMLS_CC) == SUCCESS) {
	
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_1(status, handler, "beforeexecuteroute", this_ptr);
				if (PHALCON_IS_FALSE(status)) {
					continue;
				}
	
				/** 
				 * Check if the user made a forward in the listener
				 */
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
	
			/** 
			 * Calling beforeExecuteRoute
			 */
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "dispatch:beforeExecuteRoute", 1);
	
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr);
				if (PHALCON_IS_FALSE(status)) {
					continue;
				}
	
				/** 
				 * Check if the user made a forward in the listener
				 */
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
	
			/** 
			 * Create a call handler
			 */
			PHALCON_INIT_NVAR(call_object);
			array_init_size(call_object, 2);
			phalcon_array_append(&call_object, handler, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&call_object, action_method, PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Call the function in the PHP userland
			 */
			PHALCON_INIT_NVAR(value);
			PHALCON_CALL_USER_FUNC_ARRAY(value, call_object, params);
	
			/** 
			 * Calling afterExecuteRoute as callback and event
			 */
			if (phalcon_method_exists_ex(handler, SS("afterexecuteroute") TSRMLS_CC) == SUCCESS) {
	
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, handler, "afterexecuteroute", this_ptr, value);
				if (PHALCON_IS_FALSE(status)) {
					continue;
				}
	
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
	
			/** 
			 * Calling afterExecuteRoute
			 */
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "dispatch:afterExecuteRoute", 1);
	
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, value);
				if (PHALCON_IS_FALSE(status)) {
					continue;
				}
	
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
		} else {
			/** 
			 * Call beforeNotFoundAction
			 */
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "dispatch:beforeNotFoundAction", 1);
	
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr);
				if (PHALCON_IS_FALSE(status)) {
					continue;
				}
	
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
	
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 5);
	
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSVS(exception_message, "Action '", action_name, "' was not found on handler '", handler_name, "'");
	
			/** 
			 * Try to throw an exception when an action isn't defined on the object
			 */
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			if (PHALCON_IS_FALSE(status)) {
	
				PHALCON_OBS_NVAR(finished);
				phalcon_read_property(&finished, this_ptr, SL("_finished"), PH_NOISY_CC);
				if (PHALCON_IS_FALSE(finished)) {
					continue;
				}
			}
	
			break;
		}
	
		/** 
		 * Call afterDispatch
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "dispatch:afterDispatch", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr);
		}
	}
	
	/** 
	 * Call afterDispatchLoop
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "dispatch:afterDispatchLoop", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr);
	}
	
	/** 
	 * We update the latest value produced by the latest handler
	 */
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

	zval *forward, *exception_message, *namespace_name;
	zval *controller_name, *task_name, *action_name;
	zval *params;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &forward) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(forward) != IS_ARRAY) { 
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "Forward parameter must be an Array", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_throwdispatchexception", exception_message);
		RETURN_MM_NULL();
	}
	
	/** 
	 * Check if we need to forward to another namespace
	 */
	if (phalcon_array_isset_string(forward, SS("namespace"))) {
		PHALCON_OBS_VAR(namespace_name);
		phalcon_array_fetch_string(&namespace_name, forward, SL("namespace"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_namespaceName"), namespace_name TSRMLS_CC);
	}
	
	/** 
	 * Check if we need to forward to another controller
	 */
	if (phalcon_array_isset_string(forward, SS("controller"))) {
		PHALCON_OBS_VAR(controller_name);
		phalcon_array_fetch_string(&controller_name, forward, SL("controller"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_handlerName"), controller_name TSRMLS_CC);
	} else {
		if (phalcon_array_isset_string(forward, SS("task"))) {
			PHALCON_OBS_VAR(task_name);
			phalcon_array_fetch_string(&task_name, forward, SL("task"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_handlerName"), task_name TSRMLS_CC);
		}
	}
	
	/** 
	 * Check if we need to forward to another action
	 */
	if (phalcon_array_isset_string(forward, SS("action"))) {
		PHALCON_OBS_VAR(action_name);
		phalcon_array_fetch_string(&action_name, forward, SL("action"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	}
	
	/** 
	 * Check if we need to forward changing the current parameters
	 */
	if (phalcon_array_isset_string(forward, SS("params"))) {
		PHALCON_OBS_VAR(params);
		phalcon_array_fetch_string(&params, forward, SL("params"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_finished"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

