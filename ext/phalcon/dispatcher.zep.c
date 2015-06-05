
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\CLI\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own dispatchers
 */
ZEPHIR_INIT_CLASS(Phalcon_Dispatcher) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Dispatcher, phalcon, dispatcher, phalcon_dispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

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

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousHandlerName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousActionName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_NO_DI"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_CYCLIC_ROUTING"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_HANDLER_NOT_FOUND"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_INVALID_HANDLER"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_INVALID_PARAMS"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_ACTION_NOT_FOUND"), 5 TSRMLS_CC);

	zend_class_implements(phalcon_dispatcher_ce TSRMLS_CC, 1, phalcon_dispatcherinterface_ce);
	zend_class_implements(phalcon_dispatcher_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_dispatcher_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Dispatcher constructor
 */
PHP_METHOD(Phalcon_Dispatcher, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_params"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Dispatcher, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Dispatcher, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher, setActionSuffix) {

	zval *actionSuffix_param = NULL;
	zval *actionSuffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	zephir_get_strval(actionSuffix, actionSuffix_param);


	zephir_update_property_this(this_ptr, SL("_actionSuffix"), actionSuffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the module where the controller is (only informative)
 */
PHP_METHOD(Phalcon_Dispatcher, setModuleName) {

	zval *moduleName_param = NULL;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(moduleName, moduleName_param);


	zephir_update_property_this(this_ptr, SL("_moduleName"), moduleName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the module where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher, getModuleName) {


	RETURN_MEMBER(this_ptr, "_moduleName");

}

/**
 * Sets the namespace where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName) {

	zval *namespaceName_param = NULL;
	zval *namespaceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	zephir_get_strval(namespaceName, namespaceName_param);


	zephir_update_property_this(this_ptr, SL("_namespaceName"), namespaceName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets a namespace to be prepended to the current handler name
 */
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName) {


	RETURN_MEMBER(this_ptr, "_namespaceName");

}

/**
 * Sets the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace) {

	zval *namespaceName_param = NULL;
	zval *namespaceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	zephir_get_strval(namespaceName, namespaceName_param);


	zephir_update_property_this(this_ptr, SL("_defaultNamespace"), namespaceName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace) {


	RETURN_MEMBER(this_ptr, "_defaultNamespace");

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction) {

	zval *actionName_param = NULL;
	zval *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(actionName, actionName_param);


	zephir_update_property_this(this_ptr, SL("_defaultAction"), actionName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the action name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName) {

	zval *actionName_param = NULL;
	zval *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(actionName, actionName_param);


	zephir_update_property_this(this_ptr, SL("_actionName"), actionName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the latest dispatched action name
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName) {


	RETURN_MEMBER(this_ptr, "_actionName");

}

/**
 * Sets action params to be dispatched
 *
 * @param array params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);



	if (Z_TYPE_P(params) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "Parameters must be an Array", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets action params
 */
PHP_METHOD(Phalcon_Dispatcher, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed param
 * @param  mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setParam) {

	zval *param, *value;

	zephir_fetch_params(0, 2, 0, &param, &value);



	zephir_update_property_array(this_ptr, SL("_params"), param, value TSRMLS_CC);

}

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed param
 * @param  string|array filters
 * @param  mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getParam) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param, *filters = NULL, *defaultValue = NULL, *params, *filter = NULL, *paramValue, *dependencyInjector, *_0 = NULL, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &param, &filters, &defaultValue);

	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(params);
	zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(paramValue);
	if (!(zephir_array_isset_fetch(&paramValue, params, param, 0 TSRMLS_CC))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) == IS_NULL) {
		RETURN_CCTOR(paramValue);
	}
	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "A dependency injection object is required to access the 'filter' service", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, _0, _1);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "filter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(filter, _2);
	ZEPHIR_RETURN_CALL_METHOD(filter, "sanitize", NULL, 0, paramValue, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the current method to be/executed in the dispatcher
 */
PHP_METHOD(Phalcon_Dispatcher, getActiveMethod) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VV(return_value, _0, _1);
	return;

}

/**
 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
 */
PHP_METHOD(Phalcon_Dispatcher, isFinished) {


	RETURN_MEMBER(this_ptr, "_finished");

}

/**
 * Sets the latest returned value by an action manually
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setReturnedValue) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_this(this_ptr, SL("_returnedValue"), value TSRMLS_CC);

}

/**
 * Returns value returned by the lastest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue) {


	RETURN_MEMBER(this_ptr, "_returnedValue");

}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch) {

	zval *_23 = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_10 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_18 = NULL, *_19 = NULL, *_21 = NULL, *_22 = NULL, *_24 = NULL, *_25 = NULL, *_26 = NULL;
	zval *value, *handler = NULL, *dependencyInjector = NULL, *namespaceName = NULL, *handlerName = NULL, *actionName = NULL, *params = NULL, *eventsManager = NULL, *handlerSuffix, *actionSuffix, *handlerClass = NULL, *status = NULL, *actionMethod = NULL, *e = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_8, *_9 = NULL, *_11 = NULL, *_17 = NULL, *_20;
	int numberDispatches, ZEPHIR_LAST_CALL_STATUS;
	zend_bool hasService, wasFresh = 0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "A dependency injection container is required to access related dispatching services", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, _1, _2);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "dispatch:beforeDispatchLoop", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, eventsManager, "fire", NULL, 0, _1, this_ptr);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(value);
	ZVAL_NULL(value);
	ZEPHIR_INIT_VAR(handler);
	ZVAL_NULL(handler);
	numberDispatches = 0;
	ZEPHIR_OBS_VAR(handlerSuffix);
	zephir_read_property_this(&handlerSuffix, this_ptr, SL("_handlerSuffix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(actionSuffix);
	zephir_read_property_this(&actionSuffix, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_finished"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_0)))) {
			break;
		}
		numberDispatches++;
		if (numberDispatches == 256) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "Dispatcher has detected a cyclic routing causing stability problems", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", &_4, 0, _1, _2);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			break;
		}
		zephir_update_property_this(this_ptr, SL("_finished"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", &_5, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(namespaceName);
		zephir_read_property_this(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(handlerName);
		zephir_read_property_this(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("_actionName"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_6, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "dispatch:beforeDispatch", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3, eventsManager, "fire", &_7, 0, _1, this_ptr);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				continue;
			}
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_9, dependencyInjector, "has", &_10, 0, handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(_9);
		if (!(hasService)) {
			hasService = zephir_class_exists(handlerClass, 1 TSRMLS_CC);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_VS(_11, handlerClass, " handler class cannot be loaded");
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_12, 0, _11, _1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
					continue;
				}
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, dependencyInjector, "getshared", &_13, 0, handlerClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9, dependencyInjector, "wasfreshinstance", &_14, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_9)) {
			wasFresh = 1;
		}
		if (Z_TYPE_P(handler) != IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "Invalid handler returned from the services container", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_15, 0, _1, _2);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
					continue;
				}
			}
			break;
		}
		zephir_update_property_this(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
		ZEPHIR_OBS_NVAR(params);
		zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "Action parameters must be an Array", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_16, 0, _1, _2);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
					continue;
				}
			}
			break;
		}
		ZEPHIR_INIT_NVAR(actionMethod);
		ZEPHIR_CONCAT_VV(actionMethod, actionName, actionSuffix);
		if (!((zephir_method_exists(handler, actionMethod TSRMLS_CC)  == SUCCESS))) {
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_STRING(_1, "dispatch:beforeNotFoundAction", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_17, eventsManager, "fire", &_18, 0, _1, this_ptr);
				zephir_check_temp_parameter(_1);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_17)) {
					continue;
				}
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
					continue;
				}
			}
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SVSVS(_11, "Action '", actionName, "' was not found on handler '", handlerName, "'");
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_19, 0, _11, _1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				_20 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_20)) {
					continue;
				}
			}
			break;
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "dispatch:beforeExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_17, eventsManager, "fire", &_21, 0, _1, this_ptr);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_17)) {
				continue;
			}
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(handler, SS("beforeexecuteroute") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_17, handler, "beforeexecuteroute", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_17)) {
				continue;
			}
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
				continue;
			}
		}
		if (wasFresh == 1) {
			if ((zephir_method_exists_ex(handler, SS("initialize") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(NULL, handler, "initialize", NULL, 0);
				zephir_check_call_status();
			}
			if (zephir_is_true(eventsManager)) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_STRING(_1, "dispatch:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_17, eventsManager, "fire", &_22, 0, _1, this_ptr);
				zephir_check_temp_parameter(_1);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_17)) {
					continue;
				}
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
					continue;
				}
			}
		}

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_NVAR(_23);
			zephir_create_array(_23, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_23, handler);
			zephir_array_fast_append(_23, actionMethod);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_1, _23, params);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("_returnedValue"), _1 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_lastHandler"), handler TSRMLS_CC);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(&_17, this_ptr, "_handleexception", &_24, 0, e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_17)) {
					_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
					if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
						continue;
					}
				} else {
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 519 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "dispatch:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_17, eventsManager, "fire", &_25, 0, _2, this_ptr, value);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_17)) {
				continue;
			}
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "dispatch:afterDispatch", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_26, 0, _2, this_ptr);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		if ((zephir_method_exists_ex(handler, SS("afterexecuteroute") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_17, handler, "afterexecuteroute", NULL, 0, this_ptr, value);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_17)) {
				continue;
			}
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
				continue;
			}
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "dispatch:afterDispatchLoop", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _1, this_ptr);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	RETURN_CCTOR(handler);

}

/**
 * Forwards the execution flow to another controller/action
 * Dispatchers are unique per module. Forwarding between modules is not allowed
 *
 *<code>
 *  $this->dispatcher->forward(array("controller" => "posts", "action" => "index"));
 *</code>
 *
 * @param array forward
 */
PHP_METHOD(Phalcon_Dispatcher, forward) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *forward, *namespaceName, *controllerName, *params, *actionName, *taskName, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	if (Z_TYPE_P(forward) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "Forward parameter must be an Array", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	if (zephir_array_isset_string_fetch(&namespaceName, forward, SS("namespace"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_namespaceName"), namespaceName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&controllerName, forward, SS("controller"), 1 TSRMLS_CC)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_previousHandlerName"), _1 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_handlerName"), controllerName TSRMLS_CC);
	} else {
		if (zephir_array_isset_string_fetch(&taskName, forward, SS("task"), 1 TSRMLS_CC)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_previousHandlerName"), _1 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_handlerName"), taskName TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string_fetch(&actionName, forward, SS("action"), 1 TSRMLS_CC)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_previousActionName"), _1 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_actionName"), actionName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&params, forward, SS("params"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_finished"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_forwarded"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if the current executed action was forwarded by another one
 */
PHP_METHOD(Phalcon_Dispatcher, wasForwarded) {


	RETURN_MEMBER(this_ptr, "_forwarded");

}

/**
 * Possible class name that will be located to dispatch the request
 */
PHP_METHOD(Phalcon_Dispatcher, getHandlerClass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *handlerSuffix, *handlerName, *namespaceName, *camelizedClass = NULL, *handlerClass = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(handlerSuffix);
	zephir_read_property_this(&handlerSuffix, this_ptr, SL("_handlerSuffix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(handlerName);
	zephir_read_property_this(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(namespaceName);
	zephir_read_property_this(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
	if (!(zephir_memnstr_str(handlerName, SL("\\"), "phalcon/dispatcher.zep", 633))) {
		ZEPHIR_INIT_VAR(camelizedClass);
		zephir_camelize(camelizedClass, handlerName);
	} else {
		ZEPHIR_CPY_WRT(camelizedClass, handlerName);
	}
	if (zephir_is_true(namespaceName)) {
		ZEPHIR_INIT_VAR(handlerClass);
		if (zephir_end_with_str(namespaceName, SL("\\"))) {
			ZEPHIR_CONCAT_VVV(handlerClass, namespaceName, camelizedClass, handlerSuffix);
		} else {
			ZEPHIR_CONCAT_VSVV(handlerClass, namespaceName, "\\", camelizedClass, handlerSuffix);
		}
	} else {
		ZEPHIR_INIT_NVAR(handlerClass);
		ZEPHIR_CONCAT_VV(handlerClass, camelizedClass, handlerSuffix);
	}
	RETURN_CCTOR(handlerClass);

}

/**
 * Set empty properties to their defaults (where defaults are available)
 */
PHP_METHOD(Phalcon_Dispatcher, _resolveEmptyProperties) {

	zval *_0, *_1, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaceName"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_namespaceName"), _1 TSRMLS_CC);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_handlerName"), _2 TSRMLS_CC);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_actionName"), _2 TSRMLS_CC);
	}

}

