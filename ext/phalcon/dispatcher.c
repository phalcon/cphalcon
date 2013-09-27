
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
#include "kernel/string.h"


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
/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\CLI\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own dispatchers
 */
ZEPHIR_INIT_CLASS(Phalcon_Dispatcher) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Dispatcher, phalcon, dispatcher, phalcon_dispatcher_method_entry, 0);

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
 *
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
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Dispatcher, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Dispatcher, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Dispatcher, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Dispatcher, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets the default action suffix
 *
 * @param string actionSuffix
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
 *
 * @param string moduleName
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
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getModuleName) {


	RETURN_MEMBER(this_ptr, "_moduleName");

}

/**
 * Sets the namespace where the controller class is
 *
 * @param string namespaceName
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
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName) {


	RETURN_MEMBER(this_ptr, "_namespaceName");

}

/**
 * Sets the default namespace
 *
 * @param string namespaceName
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
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace) {


	RETURN_MEMBER(this_ptr, "_defaultNamespace");

}

/**
 * Sets the default action name
 *
 * @param string actionName
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
 *
 * @param string actionName
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
 * Gets the lastest dispatched action name
 *
 * @return string
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

	zval *params, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);



	if ((Z_TYPE_P(params) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "Parameters must be an Array", 1);
		zephir_call_method_p1_noret(this_ptr, "_throwdispatchexception", _0);
		RETURN_MM_NULL();
	}
	zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets action params
 *
 * @return array
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

	zval *param, *filters = NULL, *defaultValue = NULL, *params, *filter = NULL, *paramValue, *dependencyInjector, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &param, &filters, &defaultValue);

	if (!filters) {
		ZEPHIR_CPY_WRT(filters, ZEPHIR_GLOBAL(global_null));
	}
	if (!defaultValue) {
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(params);
	zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset(params, param)) {
		ZEPHIR_OBS_VAR(paramValue);
		zephir_array_fetch(&paramValue, params, param, PH_NOISY TSRMLS_CC);
		if ((Z_TYPE_P(filters) != IS_NULL)) {
			ZEPHIR_OBS_VAR(dependencyInjector);
			zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(_0);
				ZVAL_STRING(_0, "A dependency injection object is required to access the 'filter' service", 1);
				ZEPHIR_INIT_VAR(_1);
				ZVAL_LONG(_1, 0);
				zephir_call_method_p2_noret(this_ptr, "_throwdispatchexception", _0, _1);
			}
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "filter", 1);
			zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
			ZEPHIR_CPY_WRT(filter, _0);
			zephir_call_method_p2(return_value, filter, "sanitize", paramValue, filters);
			RETURN_MM();
		} else {
			RETURN_CCTOR(paramValue);
		}
	}
	RETURN_CCTOR(defaultValue);

}

/**
 * Returns the current method to be/executed in the dispatcher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Dispatcher, getActiveMethod) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_actionName"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	concat_function(return_value, _0, _1 TSRMLS_CC);
	RETURN_MM();

}

/**
 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
 *
 * @return boolean
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

	zval *value, *handler = NULL, *dependencyInjector = NULL, *namespaceName = NULL, *handlerName = NULL, *actionName = NULL, *camelizedClass = NULL, *params = NULL, *eventsManager = NULL, *handlerSuffix, *actionSuffix, *handlerClass = NULL, *status = NULL, *actionMethod = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11, *_12 = NULL, *_13 = NULL;
	int numberDispatches;
	zend_bool hasService;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "A dependency injection container is required to access related dispatching services", 1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 0);
		zephir_call_method_p2_noret(this_ptr, "_throwdispatchexception", _1, _2);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "dispatch:beforeDispatchLoop", 1);
		zephir_call_method_p2(_1, eventsManager, "fire", _2, this_ptr);
		if (ZEPHIR_IS_FALSE(_1)) {
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
	zephir_update_property_this(this_ptr, SL("_finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_3)))) {
			break;
		}
		numberDispatches++;
		if ((numberDispatches == 256)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "Dispatcher has detected a cyclic routing causing stability problems", 1);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 1);
			zephir_call_method_p2_noret(this_ptr, "_throwdispatchexception", _1, _2);
			break;
		}
		zephir_update_property_this(this_ptr, SL("_finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		ZEPHIR_OBS_NVAR(namespaceName);
		zephir_read_property_this(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		if (!(zephir_is_true(namespaceName))) {
			ZEPHIR_OBS_NVAR(namespaceName);
			zephir_read_property_this(&namespaceName, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_namespaceName"), namespaceName TSRMLS_CC);
		}
		ZEPHIR_OBS_NVAR(handlerName);
		zephir_read_property_this(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		if (!(zephir_is_true(handlerName))) {
			ZEPHIR_OBS_NVAR(handlerName);
			zephir_read_property_this(&handlerName, this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_handlerName"), handlerName TSRMLS_CC);
		}
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("_actionName"), PH_NOISY_CC);
		if (!(zephir_is_true(actionName))) {
			ZEPHIR_OBS_NVAR(actionName);
			zephir_read_property_this(&actionName, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_actionName"), actionName TSRMLS_CC);
		}
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "dispatch:beforeDispatch", 1);
			zephir_call_method_p2(_1, eventsManager, "fire", _2, this_ptr);
			if (ZEPHIR_IS_FALSE(_1)) {
				continue;
			}
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE(_4)) {
				continue;
			}
		}
		if (!(zephir_memnstr_str(handlerName, SL("\\"), "phalcon/dispatcher.zep", 430))) {
			ZEPHIR_INIT_NVAR(camelizedClass);
			zephir_camelize(camelizedClass, handlerName);
		} else {
			ZEPHIR_CPY_WRT(camelizedClass, handlerName);
		}
		if (zephir_is_true(namespaceName)) {
			ZEPHIR_INIT_NVAR(handlerClass);
			if (zephir_end_with_str(namespaceName, SL("\\"))) {
				ZEPHIR_INIT_LNVAR(_5);
				concat_function(_5, namespaceName, camelizedClass TSRMLS_CC);
				concat_function(handlerClass, _5, handlerSuffix TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_VS(_5, namespaceName, "\\");
				ZEPHIR_INIT_LNVAR(_6);
				concat_function(_6, _5, camelizedClass TSRMLS_CC);
				concat_function(handlerClass, _6, handlerSuffix TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_NVAR(handlerClass);
			concat_function(handlerClass, camelizedClass, handlerSuffix TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method_p1(_2, dependencyInjector, "has", handlerClass);
		hasService = (zephir_get_boolval(_2)) ? 1 : 0;
		if (!(hasService)) {
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_func_p1(_7, "class_exists", handlerClass);
			hasService = (zephir_get_boolval(_7)) ? 1 : 0;
		}
		if (!(hasService)) {
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_VS(_5, handlerClass, " handler class cannot be loaded");
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 2);
			ZEPHIR_INIT_NVAR(status);
			zephir_call_method_p2(status, this_ptr, "_throwdispatchexception", _5, _7);
			if (ZEPHIR_IS_FALSE(status)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE(_4)) {
					continue;
				}
			}
			break;
		}
		ZEPHIR_INIT_NVAR(handler);
		zephir_call_method_p1(handler, dependencyInjector, "getshared", handlerClass);
		if ((Z_TYPE_P(handler) != IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "Invalid handler returned from the services container", 1);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, 3);
			ZEPHIR_INIT_NVAR(status);
			zephir_call_method_p2(status, this_ptr, "_throwdispatchexception", _7, _8);
			if (ZEPHIR_IS_FALSE(status)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE(_4)) {
					continue;
				}
			}
			break;
		}
		zephir_update_property_this(this_ptr, SL("_activeHandler"), handler TSRMLS_CC);
		ZEPHIR_OBS_NVAR(params);
		zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if ((Z_TYPE_P(params) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "Action parameters must be an Array", 1);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, 4);
			ZEPHIR_INIT_NVAR(status);
			zephir_call_method_p2(status, this_ptr, "_throwdispatchexception", _7, _8);
			if (ZEPHIR_IS_FALSE(status)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE(_4)) {
					continue;
				}
			}
			break;
		}
		ZEPHIR_INIT_NVAR(actionMethod);
		concat_function(actionMethod, actionName, actionSuffix TSRMLS_CC);
		if (!(zephir_method_exists(handler, actionMethod TSRMLS_CC))) {
			if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(_7);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_STRING(_8, "dispatch:beforeNotFoundAction", 1);
				zephir_call_method_p2(_7, eventsManager, "fire", _8, this_ptr);
				if (ZEPHIR_IS_FALSE(_7)) {
					continue;
				}
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE(_4)) {
					continue;
				}
			}
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SV(_5, "Action '", actionName);
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_VS(_6, _5, "' was not found on handler '");
			ZEPHIR_INIT_LNVAR(_9);
			concat_function(_9, _6, handlerName TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_VS(_10, _9, "'");
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, 5);
			ZEPHIR_INIT_NVAR(status);
			zephir_call_method_p2(status, this_ptr, "_throwdispatchexception", _10, _8);
			if (ZEPHIR_IS_FALSE(status)) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE(_11)) {
					continue;
				}
			}
			break;
		}
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(_7);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_STRING(_8, "dispatch:beforeExecuteRoute", 1);
			zephir_call_method_p2(_7, eventsManager, "fire", _8, this_ptr);
			if (ZEPHIR_IS_FALSE(_7)) {
				continue;
			}
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE(_4)) {
				continue;
			}
		}
		if (zephir_method_exists_str(handler, SS("beforeExecuteRoute") TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_p1(_7, handler, "beforeexecuteroute", this_ptr);
			if (ZEPHIR_IS_FALSE(_7)) {
				continue;
			}
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE(_4)) {
				continue;
			}
		}
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_method_cache(_7, dependencyInjector, "wasfreshinstance");
		if (ZEPHIR_IS_TRUE(_7)) {
			if (zephir_method_exists_str(handler, SS("initialize") TSRMLS_CC)) {
				zephir_call_method_cache_noret(handler, "initialize");
			}
		}
		ZEPHIR_INIT_NVAR(_7);
		array_init(_7);
		zephir_array_append(&_7, handler, 0);
		zephir_array_append(&_7, actionMethod, 0);
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_func_p2(_8, "call_user_func_array", _7, params);
		zephir_update_property_this(this_ptr, SL("_returnedValue"), _8 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_lastHandler"), handler TSRMLS_CC);
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(_12);
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "dispatch:afterExecuteRoute", 1);
			zephir_call_method_p3(_12, eventsManager, "fire", _13, this_ptr, value);
			if (ZEPHIR_IS_FALSE(_12)) {
				continue;
			}
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE(_4)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "dispatch:afterDispatch", 1);
			zephir_call_method_p2_noret(eventsManager, "fire", _13, this_ptr);
		}
		if (zephir_method_exists_str(handler, SS("afterExecuteRoute") TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_p2(_7, handler, "afterexecuteroute", this_ptr, value);
			if (ZEPHIR_IS_FALSE(_7)) {
				continue;
			}
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE(_4)) {
				continue;
			}
		}
	}
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "dispatch:afterDispatchLoop", 1);
		zephir_call_method_p2_noret(eventsManager, "fire", _1, this_ptr);
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

	zval *forward, *namespaceName, *controllerName, *params, *actionName, *taskName, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	if ((Z_TYPE_P(forward) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "Forward parameter must be an Array", 1);
		zephir_call_method_p1_noret(this_ptr, "_throwdispatchexception", _0);
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(namespaceName);
	if (zephir_array_isset_string_fetch(&namespaceName, forward, SS("namespace") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_namespaceName"), namespaceName TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(controllerName);
	if (zephir_array_isset_string_fetch(&controllerName, forward, SS("controller") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_handlerName"), controllerName TSRMLS_CC);
	} else {
		ZEPHIR_OBS_VAR(taskName);
		if (zephir_array_isset_string_fetch(&taskName, forward, SS("task") TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_handlerName"), taskName TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(actionName);
	if (zephir_array_isset_string_fetch(&actionName, forward, SS("action") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_actionName"), actionName TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(params);
	if (zephir_array_isset_string_fetch(&params, forward, SS("params") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_forwarded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if the current executed action was forwarded by another one
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Dispatcher, wasForwarded) {


	RETURN_MEMBER(this_ptr, "_forwarded");

}

