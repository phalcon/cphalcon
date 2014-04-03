
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "dispatcher.h"
#include "dispatcherinterface.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "events/eventsawareinterface.h"
#include "exception.h"
#include "filterinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"

#include "interned-strings.h"

/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\CLI\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own dispatchers
 */
zend_class_entry *phalcon_dispatcher_ce;

PHP_METHOD(Phalcon_Dispatcher, __construct);
PHP_METHOD(Phalcon_Dispatcher, setDI);
PHP_METHOD(Phalcon_Dispatcher, getDI);
PHP_METHOD(Phalcon_Dispatcher, setEventsManager);
PHP_METHOD(Phalcon_Dispatcher, getEventsManager);
PHP_METHOD(Phalcon_Dispatcher, setActionSuffix);
PHP_METHOD(Phalcon_Dispatcher, setModuleName);
PHP_METHOD(Phalcon_Dispatcher, getModuleName);
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName);
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName);
PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace);
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace);
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction);
PHP_METHOD(Phalcon_Dispatcher, setActionName);
PHP_METHOD(Phalcon_Dispatcher, getActionName);
PHP_METHOD(Phalcon_Dispatcher, setParams);
PHP_METHOD(Phalcon_Dispatcher, getParams);
PHP_METHOD(Phalcon_Dispatcher, setParam);
PHP_METHOD(Phalcon_Dispatcher, getParam);
PHP_METHOD(Phalcon_Dispatcher, getActiveMethod);
PHP_METHOD(Phalcon_Dispatcher, isFinished);
PHP_METHOD(Phalcon_Dispatcher, setReturnedValue);
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue);
PHP_METHOD(Phalcon_Dispatcher, dispatch);
PHP_METHOD(Phalcon_Dispatcher, forward);
PHP_METHOD(Phalcon_Dispatcher, wasForwarded);
PHP_METHOD(Phalcon_Dispatcher, getHandlerClass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setmodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setnamespacename, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setreturnedvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_dispatcher_method_entry[] = {
	PHP_ME(Phalcon_Dispatcher, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Dispatcher, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getEventsManager, arginfo_phalcon_events_eventsawareinterface_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setActionSuffix, arginfo_phalcon_dispatcherinterface_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setModuleName, arginfo_phalcon_dispatcher_setmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setNamespaceName, arginfo_phalcon_dispatcher_setnamespacename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getNamespaceName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setDefaultNamespace, arginfo_phalcon_dispatcherinterface_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setDefaultAction, arginfo_phalcon_dispatcherinterface_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setActionName, arginfo_phalcon_dispatcherinterface_setactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setParams, arginfo_phalcon_dispatcherinterface_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setParam, arginfo_phalcon_dispatcherinterface_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getParam, arginfo_phalcon_dispatcherinterface_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getActiveMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, isFinished, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setReturnedValue, arginfo_phalcon_dispatcher_setreturnedvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getReturnedValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, forward, arginfo_phalcon_dispatcherinterface_forward, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, wasForwarded, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getHandlerClass, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Dispatcher initializer
 */
PHALCON_INIT_CLASS(Phalcon_Dispatcher){

	PHALCON_REGISTER_CLASS(Phalcon, Dispatcher, dispatcher, phalcon_dispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_activeHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_finished"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_forwarded"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_moduleName"), ZEND_ACC_PROTECTED TSRMLS_CC);
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
	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_isExactHandler"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousHandlerName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousActionName"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	phalcon_update_property_empty_array(this_ptr, SL("_params") TSRMLS_CC);
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Dispatcher, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
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

	phalcon_fetch_params(0, 1, 0, &events_manager);

	phalcon_update_property_this(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);

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

	phalcon_fetch_params(0, 1, 0, &action_suffix);

	phalcon_update_property_this(this_ptr, SL("_actionSuffix"), action_suffix TSRMLS_CC);

}

/**
 * Sets the module where the controller is (only informative)
 *
 * @param string $moduleName
 */
PHP_METHOD(Phalcon_Dispatcher, setModuleName){

	zval *module_name;

	phalcon_fetch_params(0, 1, 0, &module_name);

	phalcon_update_property_this(this_ptr, SL("_moduleName"), module_name TSRMLS_CC);

}

/**
 * Gets the module where the controller class is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getModuleName){


	RETURN_MEMBER(this_ptr, "_moduleName");
}

/**
 * Sets the namespace where the controller class is
 *
 * @param string $namespaceName
 */
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName){

	zval *namespace_name;

	phalcon_fetch_params(0, 1, 0, &namespace_name);

	phalcon_update_property_this(this_ptr, SL("_namespaceName"), namespace_name TSRMLS_CC);

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

	phalcon_fetch_params(0, 1, 0, &namespace);

	phalcon_update_property_this(this_ptr, SL("_defaultNamespace"), namespace TSRMLS_CC);

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

	phalcon_fetch_params(0, 1, 0, &action_name);

	phalcon_update_property_this(this_ptr, SL("_defaultAction"), action_name TSRMLS_CC);

}

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName){

	zval *action_name;

	phalcon_fetch_params(0, 1, 0, &action_name);

	phalcon_update_property_this(this_ptr, SL("_actionName"), action_name TSRMLS_CC);

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

	phalcon_fetch_params(0, 1, 0, &params);

	if (Z_TYPE_P(params) != IS_ARRAY) {
		PHALCON_MM_GROW();
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "Parameters must be an Array", 1);
		PHALCON_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", exception_message);
		RETURN_MM_NULL();
	}

	phalcon_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
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

	phalcon_fetch_params(0, 2, 0, &param, &value);

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

	zval *param, *filters = NULL, *default_value = NULL;
	zval *exception_code;
	zval *exception_message, *service, *filter = NULL;
	zval *params, *param_value, *dependency_injector;

	phalcon_fetch_params(0, 1, 2, &param, &filters, &default_value);

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&param_value, params, param)) {

		if (filters && Z_TYPE_P(filters) != IS_NULL) {
			PHALCON_MM_GROW();
			dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_INIT_VAR(exception_code);
				ZVAL_LONG(exception_code, 0);

				PHALCON_INIT_VAR(exception_message);
				ZVAL_STRING(exception_message, "A dependency injection object is required to access the 'filter' service", 1);
				PHALCON_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", exception_message, exception_code);
				RETURN_MM();
			}

			PHALCON_INIT_VAR(service);
			PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);

			PHALCON_CALL_METHOD(&filter, dependency_injector, "getshared", service);
			PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
			PHALCON_RETURN_CALL_METHOD(filter, "sanitize", param_value, filters);
			RETURN_MM();
		} else {
			RETURN_ZVAL(param_value, 1, 0);
		}
	}

	if (default_value) {
		RETURN_ZVAL(default_value, 1, 0);
	}

	RETURN_NULL();
}

/**
 * Returns the current method to be/executed in the dispatcher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getActiveMethod){

	zval *suffix, *action_name;

	suffix      = phalcon_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY TSRMLS_CC);
	action_name = phalcon_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY TSRMLS_CC);

	PHALCON_CONCAT_VV(return_value, action_name, suffix);
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

	phalcon_fetch_params(0, 1, 0, &value);

	phalcon_update_property_this(this_ptr, SL("_returnedValue"), value TSRMLS_CC);

}

/**
 * Returns value returned by the lastest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue){


	RETURN_MEMBER(this_ptr, "_returnedValue");
}

static int phalcon_dispatcher_fire_event(zval **return_value_ptr, zval *mgr, const char *event, zval *source, zval *data TSRMLS_DC)
{
	if (mgr) {
		zval *event_name;
		int status, status2;
		zend_uint nparams = (data ? 3 : 2);
		zval *params[3];

		MAKE_STD_ZVAL(event_name);
		ZVAL_STRING(event_name, event, 0);

		params[0] = event_name;
		params[1] = source;
		params[2] = data;

		status = phalcon_call_method(return_value_ptr, mgr, "fire", nparams, params TSRMLS_CC);

		if (EG(exception)) {
			zval *exception = EG(exception);
			Z_ADDREF_P(exception);

			zend_clear_exception(TSRMLS_C);

			assert(Z_REFCOUNT_P(exception) == 1);
			/* exception will be destroyed automatically after return from _handleexception */
			Z_DELREF_P(exception);

			/* source == this_ptr */
			assert(Z_TYPE_P(source) == IS_OBJECT && instanceof_function_ex(Z_OBJCE_P(source), phalcon_dispatcherinterface_ce, 1 TSRMLS_CC));
			if (is_phalcon_class(Z_OBJCE_P(source))) {
				zval *params[] = { event_name, source, exception };
				/* Shortcut, save one method call */
				ZVAL_STRING(event_name, "dispatch:beforeException", 0);
				status2 = phalcon_call_method(NULL, mgr, "fire", 3, params TSRMLS_CC);
			}
			else {
				zval *params[] = { exception };
				status2 = phalcon_call_method(NULL, source, "_handleexception", 1, params TSRMLS_CC);
			}

			if (FAILURE == status2) {
				status = FAILURE;
			}
		}

		ZVAL_NULL(event_name);
		zval_ptr_dtor(&event_name);
		return status;
	}
	else if (return_value_ptr) {
		MAKE_STD_ZVAL(*return_value_ptr);
		ZVAL_TRUE(*return_value_ptr);
	}

	return SUCCESS;
}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch){

	zval *exception_code = NULL;
	zval *exception_message = NULL;
	zval *status = NULL, *value = NULL, *handler = NULL;
	zval *camelized_class = NULL, *handler_class = NULL, *has_service = NULL;
	zval *was_fresh = NULL, *action_method = NULL, *params = NULL, *call_object = NULL;
	zval *exception = NULL;
	zval *dependency_injector, *events_manager, *tmp;
	zval *handler_suffix, *action_suffix, *namespace_name, *handler_name, *action_name;
	int number_dispatches = 0;

	PHALCON_MM_GROW();

	dependency_injector = phalcon_fetch_property_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (!dependency_injector || Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(exception_code);
		ZVAL_LONG(exception_code, 0);

		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "A dependency injection container is required to access related dispatching services", 1);
		PHALCON_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", exception_message, exception_code);
		RETURN_MM();
	}

	events_manager = phalcon_fetch_property_this(this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (events_manager && Z_TYPE_P(events_manager) != IS_OBJECT) {
		events_manager = NULL;
	}

	/**
	 * Calling beforeDispatchLoop
	 */
	PHALCON_OBSERVE_OR_NULLIFY_VAR(status);
	RETURN_MM_ON_FAILURE(phalcon_dispatcher_fire_event(&status, events_manager, "dispatch:beforeDispatchLoop", this_ptr, NULL TSRMLS_CC));
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	PHALCON_INIT_VAR(value);

	PHALCON_INIT_VAR(handler);

	handler_suffix = phalcon_fetch_nproperty_this(this_ptr, SL("_handlerSuffix"), PH_NOISY TSRMLS_CC);
	action_suffix  = phalcon_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY TSRMLS_CC);

	/**
	 * Do at least one dispatch
	 */
	phalcon_update_property_this(this_ptr, SL("_finished"), PHALCON_GLOBAL(z_false) TSRMLS_CC);

	while (1) {

		/**
		 * Loop until finished is false
		 */
		tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
		if (zend_is_true(tmp)) {
			break;
		}

		++number_dispatches;

		/**
		 * Throw an exception after 256 consecutive forwards
		 */
		if (number_dispatches == 256) {
			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 1);

			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Dispatcher has detected a cyclic routing causing stability problems", 1);
			PHALCON_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			break;
		}

		phalcon_update_property_this(this_ptr, SL("_finished"), PHALCON_GLOBAL(z_true) TSRMLS_CC);

		/**
		 * If the current namespace is null we used the set in this_ptr::_defaultNamespace
		 */
		namespace_name = phalcon_fetch_nproperty_this(this_ptr, SL("_namespaceName"), PH_NOISY TSRMLS_CC);
		if (!zend_is_true(namespace_name)) {
			namespace_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_namespaceName"), namespace_name TSRMLS_CC);
		}

		/**
		 * If the handler is null we use the set in this_ptr::_defaultHandler
		 */
		handler_name = phalcon_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY TSRMLS_CC);
		if (!zend_is_true(handler_name)) {
			handler_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultHandler"), PH_NOISY TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_handlerName"), handler_name TSRMLS_CC);
		}

		/**
		 * If the action is null we use the set in this_ptr::_defaultAction
		 */
		action_name = phalcon_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY TSRMLS_CC);
		if (!zend_is_true(action_name)) {
			action_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
		}

		/**
		 * Calling beforeDispatch
		 */
		if (events_manager) {
			PHALCON_OBSERVE_OR_NULLIFY_VAR(status);
			RETURN_MM_ON_FAILURE(phalcon_dispatcher_fire_event(&status, events_manager, "dispatch:beforeDispatch", this_ptr, NULL TSRMLS_CC));
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}

			/**
			 * Check if the user made a forward in the listener
			 */
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
			if (PHALCON_IS_FALSE(tmp)) {
				continue;
			}
		}

		/**
		 * We don't camelize the classes if they are in namespaces
		 */
		if (!phalcon_memnstr_str(handler_name, SL("\\"))) {
			PHALCON_INIT_NVAR(camelized_class);
			phalcon_camelize(camelized_class, handler_name);
		} else if (phalcon_start_with_str(handler_name, SL("\\"))) {
			PHALCON_INIT_NVAR(camelized_class);
			ZVAL_STRINGL(camelized_class, Z_STRVAL_P(handler_name)+1, Z_STRLEN_P(handler_name)-1, 1);
		} else {
			camelized_class = handler_name;
		}

		/**
		 * Create the complete controller class name prepending the namespace
		 */
		PHALCON_INIT_NVAR(handler_class);
		if (zend_is_true(namespace_name)) {
			if (phalcon_end_with_str(namespace_name, SL("\\"))) {
				PHALCON_CONCAT_VVV(handler_class, namespace_name, camelized_class, handler_suffix);
			} else {
				PHALCON_CONCAT_VSVV(handler_class, namespace_name, "\\", camelized_class, handler_suffix);
			}
		} else {
			PHALCON_CONCAT_VV(handler_class, camelized_class, handler_suffix);
		}

		/**
		 * Handlers are retrieved as shared instances from the Service Container
		 */
		PHALCON_CALL_METHOD(&has_service, dependency_injector, "has", handler_class);
		if (!zend_is_true(has_service)) {
			/**
			 * DI doesn't have a service with that name, try to load it using an autoloader
			 */
			PHALCON_INIT_NVAR(has_service);
			assert(Z_TYPE_P(handler_class) == IS_STRING);
			ZVAL_LONG(has_service, phalcon_class_exists(Z_STRVAL_P(handler_class), Z_STRLEN_P(handler_class), 1 TSRMLS_CC));
		}

		/**
		 * If the service cannot be loaded we throw an exception
		 */
		if (!zend_is_true(has_service)) {

			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 2);

			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_VS(exception_message, handler_class, " handler class cannot be loaded");

			PHALCON_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			if (PHALCON_IS_FALSE(status)) {

				/**
				 * Check if the user made a forward in the listener
				 */
				tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
				if (PHALCON_IS_FALSE(tmp)) {
					continue;
				}
			}

			break;
		}

		/**
		 * Handlers must be only objects
		 */
		PHALCON_CALL_METHOD(&handler, dependency_injector, "getshared", handler_class);
		if (Z_TYPE_P(handler) != IS_OBJECT) {

			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 3);

			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Invalid handler returned from the services container", 1);

			PHALCON_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			if (PHALCON_IS_FALSE(status)) {

				tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
				if (PHALCON_IS_FALSE(tmp)) {
					continue;
				}
			}

			break;
		}

		/**
		 * If the object was recently created in the DI we initialize it
		 */
		PHALCON_CALL_METHOD(&was_fresh, dependency_injector, "wasfreshinstance");

		/**
		 * Update the active handler making it available for events
		 */
		phalcon_update_property_this(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);

		/**
		 * Check if the method exists in the handler
		 */
		PHALCON_INIT_NVAR(action_method);
		PHALCON_CONCAT_VV(action_method, action_name, action_suffix);
		if (phalcon_method_exists(handler, action_method TSRMLS_CC) == FAILURE) {

			/**
			 * Call beforeNotFoundAction
			 */
			if (events_manager) {
				PHALCON_OBSERVE_OR_NULLIFY_VAR(status);
				RETURN_MM_ON_FAILURE(phalcon_dispatcher_fire_event(&status, events_manager, "dispatch:beforeNotFoundAction", this_ptr, NULL TSRMLS_CC));
				if (PHALCON_IS_FALSE(status)) {
					continue;
				}

				tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
				if (PHALCON_IS_FALSE(tmp)) {
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
			PHALCON_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			if (PHALCON_IS_FALSE(status)) {

				tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
				if (PHALCON_IS_FALSE(tmp)) {
					continue;
				}
			}

			break;
		}

		/**
		 * Calling beforeExecuteRoute
		 */
		if (events_manager) {
			PHALCON_OBSERVE_OR_NULLIFY_VAR(status);
			RETURN_MM_ON_FAILURE(phalcon_dispatcher_fire_event(&status, events_manager, "dispatch:beforeExecuteRoute", this_ptr, NULL TSRMLS_CC));
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}

			/**
			 * Check if the user made a forward in the listener
			 */
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
			if (PHALCON_IS_FALSE(tmp)) {
				continue;
			}
		}

		/**
		 * Calling beforeExecuteRoute as callback and event
		 */
		if (phalcon_method_exists_ex(handler, SS("beforeexecuteroute") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD(&status, handler, "beforeexecuteroute", this_ptr);
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}

			/**
			 * Check if the user made a forward in the listener
			 */
			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
			if (PHALCON_IS_FALSE(tmp)) {
				continue;
			}
		}

		/**
		 * Call the 'initialize' method just once per request
		 */
		if (PHALCON_IS_TRUE(was_fresh)) {
			if (phalcon_method_exists_ex(handler, SS("initialize") TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_METHOD(NULL, handler, "initialize");
			}

			/**
			 * Calling afterInitialize
			 */
			if (events_manager) {
				PHALCON_OBSERVE_OR_NULLIFY_VAR(status);
				RETURN_MM_ON_FAILURE(phalcon_dispatcher_fire_event(&status, events_manager, "dispatch:afterInitialize", this_ptr, NULL TSRMLS_CC));
				if (PHALCON_IS_FALSE(status)) {
					continue;
				}

				/**
				 * Check if the user made a forward in the listener
				 */
				tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
				if (PHALCON_IS_FALSE(tmp)) {
					continue;
				}
			}
		}

		/**
		 * Check if the params is an array
		 */
		PHALCON_OBS_NVAR(params);
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(params) != IS_ARRAY) {

			PHALCON_INIT_NVAR(exception_code);
			ZVAL_LONG(exception_code, 4);

			PHALCON_INIT_NVAR(exception_message);
			ZVAL_STRING(exception_message, "Action parameters must be an Array", 1);

			/**
			 * An invalid parameter variable was passed throw an exception
			 */
			PHALCON_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", exception_message, exception_code);
			if (PHALCON_IS_FALSE(status)) {

				tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
				if (PHALCON_IS_FALSE(tmp)) {
					continue;
				}
			}

			break;
		}

		/**
		 * Create a call handler
		 */
		PHALCON_INIT_NVAR(call_object);
		array_init_size(call_object, 2);
		phalcon_array_append(&call_object, handler, 0);
		phalcon_array_append(&call_object, action_method, 0);

		PHALCON_INIT_NVAR(value);
		/* Call the method allowing exceptions */
		PHALCON_CALL_USER_FUNC_ARRAY_NOEX(value, call_object, params);

		/* Check if an exception has ocurred */
		if (EG(exception)) {
			/* Copy the exception to rethrow it later if needed */
			PHALCON_CPY_WRT(exception, EG(exception));

			/* Clear the exception  */
			zend_clear_exception(TSRMLS_C);

			/* Try to handle the exception */
			PHALCON_CALL_METHOD(&status, this_ptr, "_handleexception", exception);
			if (PHALCON_IS_FALSE(status)) {
				tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
				if (PHALCON_IS_FALSE(tmp)) {
					continue;
				}
			}
			else {
				/* Exception was not handled, rethrow it */
				phalcon_throw_exception(exception TSRMLS_CC);
				RETURN_MM();
			}
		} else {
			/* Update the latest value produced by the latest handler */
			phalcon_update_property_this(this_ptr, SL("_returnedValue"), value TSRMLS_CC);
		}

		phalcon_update_property_this(this_ptr, SL("_lastHandler"), handler TSRMLS_CC);

		if (events_manager) {
			/**
			 * Call afterExecuteRoute
			 */
			PHALCON_OBSERVE_OR_NULLIFY_VAR(status);
			RETURN_MM_ON_FAILURE(phalcon_dispatcher_fire_event(&status, events_manager, "dispatch:afterExecuteRoute", this_ptr, value TSRMLS_CC));
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}

			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
			if (PHALCON_IS_FALSE(tmp)) {
				continue;
			}

			/**
			 * Call afterDispatch
			 */
			RETURN_MM_ON_FAILURE(phalcon_dispatcher_fire_event(NULL, events_manager, "dispatch:afterDispatch", this_ptr, NULL TSRMLS_CC));
		}

		/**
		 * Calling afterExecuteRoute as callback and event
		 */
		if (phalcon_method_exists_ex(handler, SS("afterexecuteroute") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD(&status, handler, "afterexecuteroute", this_ptr, value);
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}

			tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY TSRMLS_CC);
			if (PHALCON_IS_FALSE(tmp)) {
				continue;
			}
		}
	}

	/**
	 * Call afterDispatchLoop
	 */
	RETURN_MM_ON_FAILURE(phalcon_dispatcher_fire_event(NULL, events_manager, "dispatch:afterDispatchLoop", this_ptr, NULL TSRMLS_CC));
	RETURN_CCTOR(handler);
}

/**
 * Forwards the execution flow to another controller/action
 * Dispatchers are unique per module. Forwarding between modules is not allowed
 *
 *<code>
 *  $this->dispatcher->forward(array('controller' => 'posts', 'action' => 'index'));
 *</code>
 *
 * @param array $forward
 */
PHP_METHOD(Phalcon_Dispatcher, forward){

	zval *forward, *exception_message;
	zval *namespace_name, *controller_name, *task_name, *action_name, *params, *previous_controller_name, *previous_action_name;

	phalcon_fetch_params(0, 1, 0, &forward);

	if (Z_TYPE_P(forward) != IS_ARRAY) {
		PHALCON_MM_GROW();
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "Forward parameter must be an Array", 1);
		PHALCON_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", exception_message);
		RETURN_MM_NULL();
	}

	previous_controller_name = phalcon_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_previousHandlerName"), previous_controller_name TSRMLS_CC);

	previous_action_name = phalcon_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_previousActionName"), previous_action_name TSRMLS_CC);

	/**
	 * Check if we need to forward to another namespace
	 */
	if (phalcon_array_isset_string_fetch(&namespace_name, forward, SS("namespace"))) {
		phalcon_update_property_this(this_ptr, SL("_namespaceName"), namespace_name TSRMLS_CC);
	}

	/**
	 * Check if we need to forward to another controller
	 */
	if (phalcon_array_isset_string_fetch(&controller_name, forward, SS("controller"))) {
		phalcon_update_property_this(this_ptr, SL("_handlerName"), controller_name TSRMLS_CC);
	} else {
		if (phalcon_array_isset_string_fetch(&task_name, forward, SS("task"))) {
			phalcon_update_property_this(this_ptr, SL("_handlerName"), task_name TSRMLS_CC);
		}
	}

	/**
	 * Check if we need to forward to another action
	 */
	if (phalcon_array_isset_string_fetch(&action_name, forward, SS("action"))) {
		phalcon_update_property_this(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	}

	/**
	 * Check if we need to forward changing the current parameters
	 */
	if (phalcon_array_isset_string_fetch(&params, forward, SS("params"))) {
		phalcon_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	}

	phalcon_update_property_this(this_ptr, SL("_finished"), PHALCON_GLOBAL(z_false) TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_forwarded"), PHALCON_GLOBAL(z_true) TSRMLS_CC);
}

/**
 * Check if the current executed action was forwarded by another one
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Dispatcher, wasForwarded){


	RETURN_MEMBER(this_ptr, "_forwarded");
}

/**
 * Possible class name that will be located to dispatch the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getHandlerClass){

	zval *camelized_class = NULL;
	zval *handler_suffix, *namespace_name, *handler_name;

	PHALCON_MM_GROW();

	/**
	 * The handler suffix
	 */
	handler_suffix = phalcon_fetch_nproperty_this(this_ptr, SL("_handlerSuffix"), PH_NOISY TSRMLS_CC);

	/**
	 * If the current namespace is null we used the set in this_ptr::_defaultNamespace
	 */
	namespace_name = phalcon_fetch_nproperty_this(this_ptr, SL("_namespaceName"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(namespace_name)) {
		namespace_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_namespaceName"), namespace_name TSRMLS_CC);
	}

	/**
	 * If the handler is null we use the set in this_ptr::_defaultHandler
	 */
	handler_name = phalcon_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(handler_name)) {
		handler_name = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultHandler"), PH_NOISY TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_handlerName"), handler_name TSRMLS_CC);
	}

	/**
	 * We don't camelize the classes if they are in namespaces
	 */
	if (!phalcon_memnstr_str(handler_name, SL("\\"))) {
		PHALCON_INIT_VAR(camelized_class);
		phalcon_camelize(camelized_class, handler_name);
	} else if (phalcon_start_with_str(handler_name, SL("\\"))) {
		PHALCON_INIT_VAR(camelized_class);
		ZVAL_STRINGL(camelized_class, Z_STRVAL_P(handler_name)+1, Z_STRLEN_P(handler_name)-1, 1);
	} else {
		camelized_class = handler_name;
	}

	/**
	 * Create the complete controller class name prepending the namespace
	 */
	if (zend_is_true(namespace_name)) {
		if (phalcon_end_with_str(namespace_name, SL("\\"))) {
			PHALCON_CONCAT_VVV(return_value, namespace_name, camelized_class, handler_suffix);
		} else {
			PHALCON_CONCAT_VSVV(return_value, namespace_name, "\\", camelized_class, handler_suffix);
		}
	} else {
		PHALCON_CONCAT_VV(return_value, camelized_class, handler_suffix);
	}

	phalcon_update_property_this(this_ptr, SL("_isExactHandler"), PHALCON_GLOBAL(z_false) TSRMLS_CC);

	PHALCON_MM_RESTORE();
}
