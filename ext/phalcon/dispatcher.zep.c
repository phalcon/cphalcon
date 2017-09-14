
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\Cli\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own dispatchers.
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

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousNamespaceName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousHandlerName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousActionName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_modelBinding"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_modelBinder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_dispatcher_ce->create_object = zephir_init_properties_Phalcon_Dispatcher;
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
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Dispatcher, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(getThis(), SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Dispatcher, getEventsManager) {

	

	RETURN_MEMBER(getThis(), "_eventsManager");

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


	zephir_update_property_this(getThis(), SL("_actionSuffix"), actionSuffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher, getActionSuffix) {

	

	RETURN_MEMBER(getThis(), "_actionSuffix");

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


	zephir_update_property_this(getThis(), SL("_moduleName"), moduleName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the module where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher, getModuleName) {

	

	RETURN_MEMBER(getThis(), "_moduleName");

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


	zephir_update_property_this(getThis(), SL("_namespaceName"), namespaceName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets a namespace to be prepended to the current handler name
 */
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName) {

	

	RETURN_MEMBER(getThis(), "_namespaceName");

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


	zephir_update_property_this(getThis(), SL("_defaultNamespace"), namespaceName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace) {

	

	RETURN_MEMBER(getThis(), "_defaultNamespace");

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


	zephir_update_property_this(getThis(), SL("_defaultAction"), actionName TSRMLS_CC);
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


	zephir_update_property_this(getThis(), SL("_actionName"), actionName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the latest dispatched action name
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName) {

	

	RETURN_MEMBER(getThis(), "_actionName");

}

/**
 * Sets action params to be dispatched
 *
 * @param array params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);



	if (Z_TYPE_P(params) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "Parameters must be an Array", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, _0$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	zephir_update_property_this(getThis(), SL("_params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets action params
 */
PHP_METHOD(Phalcon_Dispatcher, getParams) {

	

	RETURN_MEMBER(getThis(), "_params");

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, *filters = NULL, *defaultValue = NULL, *params = NULL, *filter = NULL, *paramValue = NULL, *dependencyInjector = NULL, *_2 = NULL, *_3, *_0$$5, *_1$$5;

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
		ZEPHIR_INIT_VAR(_0$$5);
		ZVAL_STRING(_0$$5, "A dependency injection object is required to access the 'filter' service", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_LONG(_1$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, _0$$5, _1$$5);
		zephir_check_temp_parameter(_0$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "filter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "getshared", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(filter, _2);
	ZEPHIR_RETURN_CALL_METHOD(filter, "sanitize", NULL, 0, paramValue, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a param exists
 *
 * @param  mixed param
 * @return boolean
 */
PHP_METHOD(Phalcon_Dispatcher, hasParam) {

	zval *param, *_0;

	zephir_fetch_params(0, 1, 0, &param);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, param));

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

	

	RETURN_MEMBER(getThis(), "_finished");

}

/**
 * Sets the latest returned value by an action manually
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setReturnedValue) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_this(getThis(), SL("_returnedValue"), value TSRMLS_CC);

}

/**
 * Returns value returned by the latest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue) {

	

	RETURN_MEMBER(getThis(), "_returnedValue");

}

/**
 * Enable/Disable model binding during dispatch
 *
 * <code>
 * $di->set('dispatcher', function() {
 *     $dispatcher = new Dispatcher();
 *
 *     $dispatcher->setModelBinding(true, 'cache');
 *     return $dispatcher;
 * });
 * </code>
 *
 * @deprecated 3.1.0 Use setModelBinder method
 * @see Phalcon\Dispatcher::setModelBinder()
 */
PHP_METHOD(Phalcon_Dispatcher, setModelBinding) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *cache = NULL, *dependencyInjector = NULL, *_0$$3 = NULL, *_1$$4;
	zend_bool value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &cache);

	value = zephir_get_boolval(value_param);
	if (!cache) {
		ZEPHIR_CPY_WRT(cache, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$3, dependencyInjector, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, _0$$3);
	}
	if (value) {
		zephir_update_property_this(getThis(), SL("_modelBinding"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_modelBinding"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (value) {
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, phalcon_mvc_model_binder_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 72, cache);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_modelBinder"), _1$$4 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Enable model binding during dispatch
 *
 * <code>
 * $di->set('dispatcher', function() {
 *     $dispatcher = new Dispatcher();
 *
 *     $dispatcher->setModelBinder(new Binder(), 'cache');
 *     return $dispatcher;
 * });
 * </code>
 */
PHP_METHOD(Phalcon_Dispatcher, setModelBinder) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelBinder, *cache = NULL, *dependencyInjector = NULL, *_0$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelBinder, &cache);

	if (!cache) {
		ZEPHIR_CPY_WRT(cache, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$3, dependencyInjector, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, _0$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_this(getThis(), SL("_modelBinding"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_modelBinding"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_modelBinder"), modelBinder TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Dispatcher, getModelBinder) {

	

	RETURN_MEMBER(getThis(), "_modelBinder");

}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch) {

	zval *handler = NULL, *e = NULL, *_0, *_1$$4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&handler, this_ptr, "_dispatch", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CPY_WRT(_0, EG(exception));
		if (zephir_instance_of_ev(_0, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(e, _0);
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "_handleexception", NULL, 0, e);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$4)) {
				RETURN_MM_BOOL(0);
			}
			zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 413 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(handler);

}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
PHP_METHOD(Phalcon_Dispatcher, _dispatch) {

	zval *_31$$6 = NULL;
	zval *value = NULL, *handler = NULL, *dependencyInjector = NULL, *namespaceName = NULL, *handlerName = NULL, *actionName = NULL, *params = NULL, *eventsManager = NULL, *actionSuffix = NULL, *handlerClass = NULL, *status = NULL, *actionMethod = NULL, *modelBinder = NULL, *e = NULL, *bindCacheKey = NULL, *_0, *_1$$3, *_2$$3, *_3$$4 = NULL, *_4$$4, *_5$$7 = NULL, *_6$$7 = NULL, *_10$$8 = NULL, *_11$$8 = NULL, *_13$$8, *_14$$6 = NULL, *_50$$6, *_60$$6 = NULL, *_16$$12 = NULL, *_17$$12 = NULL, *_19$$13, *_22$$16 = NULL, *_23$$16 = NULL, *_25$$17, *_26$$19 = NULL, *_27$$19 = NULL, *_29$$20, *_32$$23 = NULL, *_33$$23 = NULL, *_35$$23, *_36$$22 = NULL, *_37$$22 = NULL, *_39$$26, *_40$$28 = NULL, *_41$$28 = NULL, *_43$$28, *_44$$31 = NULL, *_45$$31, *_46$$36 = NULL, *_47$$36 = NULL, *_49$$36, *_51$$39 = NULL, *_52$$40 = NULL, *_53$$40 = NULL, *_55$$40, *_56$$43 = NULL, *_57$$43, *_58$$46 = NULL, *_61$$47 = NULL, *_63$$48, *_64$$51 = NULL, *_65$$51 = NULL, *_67$$51, *_69$$54 = NULL, *_70$$54, *_71$$57;
	zend_bool hasService = 0, wasFresh;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_9 = NULL, *_12 = NULL, *_15 = NULL, *_18 = NULL, *_20 = NULL, *_21 = NULL, *_24 = NULL, *_28 = NULL, *_30 = NULL, *_34 = NULL, *_38 = NULL, *_42 = NULL, *_48 = NULL, *_54 = NULL, *_59 = NULL, *_62 = NULL, *_66 = NULL, *_68 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberDispatches = 0;

	ZEPHIR_MM_GROW();

	wasFresh = 0;
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "A dependency injection container is required to access related dispatching services", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, _1$$3, _2$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_STRING(_4$$4, "dispatch:beforeDispatchLoop", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$4, eventsManager, "fire", NULL, 0, _4$$4, this_ptr);
		zephir_check_temp_parameter(_4$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(value);
	ZVAL_NULL(value);
	ZEPHIR_INIT_VAR(handler);
	ZVAL_NULL(handler);
	numberDispatches = 0;
	ZEPHIR_OBS_VAR(actionSuffix);
	zephir_read_property_this(&actionSuffix, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	if (0) {
		zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_0)))) {
			break;
		}
		numberDispatches++;
		if (numberDispatches == 256) {
			ZEPHIR_INIT_NVAR(_5$$7);
			ZVAL_STRING(_5$$7, "Dispatcher has detected a cyclic routing causing stability problems", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_6$$7);
			ZVAL_LONG(_6$$7, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", &_7, 0, _5$$7, _6$$7);
			zephir_check_temp_parameter(_5$$7);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", &_8, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(namespaceName);
		zephir_read_property_this(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(handlerName);
		zephir_read_property_this(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("_actionName"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_9, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_11$$8);
			ZVAL_STRING(_11$$8, "dispatch:beforeDispatch", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_10$$8, eventsManager, "fire", &_12, 0, _11$$8, this_ptr);
			zephir_check_temp_parameter(_11$$8);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_10$$8)) {
				continue;
			}
			_13$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_13$$8)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_14$$6, dependencyInjector, "has", &_15, 0, handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(_14$$6);
		if (!(hasService)) {
			hasService = zephir_class_exists(handlerClass, 1 TSRMLS_CC);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_LNVAR(_16$$12);
			ZEPHIR_CONCAT_VS(_16$$12, handlerClass, " handler class cannot be loaded");
			ZEPHIR_INIT_NVAR(_17$$12);
			ZVAL_LONG(_17$$12, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_18, 0, _16$$12, _17$$12);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				_19$$13 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_19$$13)) {
					continue;
				}
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, dependencyInjector, "getshared", &_20, 0, handlerClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_14$$6, dependencyInjector, "wasfreshinstance", &_21, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_14$$6)) {
			wasFresh = 1;
		}
		if (Z_TYPE_P(handler) != IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_22$$16);
			ZVAL_STRING(_22$$16, "Invalid handler returned from the services container", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_23$$16);
			ZVAL_LONG(_23$$16, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_24, 0, _22$$16, _23$$16);
			zephir_check_temp_parameter(_22$$16);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				_25$$17 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_25$$17)) {
					continue;
				}
			}
			break;
		}
		zephir_update_property_this(getThis(), SL("_activeHandler"), handler TSRMLS_CC);
		ZEPHIR_OBS_NVAR(params);
		zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_26$$19);
			ZVAL_STRING(_26$$19, "Action parameters must be an Array", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_27$$19);
			ZVAL_LONG(_27$$19, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_28, 0, _26$$19, _27$$19);
			zephir_check_temp_parameter(_26$$19);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				_29$$20 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_29$$20)) {
					continue;
				}
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_30, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_31$$6);
		zephir_create_array(_31$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_31$$6, handler);
		zephir_array_fast_append(_31$$6, actionMethod);
		if (!(zephir_is_callable(_31$$6 TSRMLS_CC))) {
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_33$$23);
				ZVAL_STRING(_33$$23, "dispatch:beforeNotFoundAction", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_32$$23, eventsManager, "fire", &_34, 0, _33$$23, this_ptr);
				zephir_check_temp_parameter(_33$$23);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_32$$23)) {
					continue;
				}
				_35$$23 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_35$$23)) {
					continue;
				}
			}
			ZEPHIR_INIT_LNVAR(_36$$22);
			ZEPHIR_CONCAT_SVSVS(_36$$22, "Action '", actionName, "' was not found on handler '", handlerName, "'");
			ZEPHIR_INIT_NVAR(_37$$22);
			ZVAL_LONG(_37$$22, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_38, 0, _36$$22, _37$$22);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
				_39$$26 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_39$$26)) {
					continue;
				}
			}
			break;
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_41$$28);
			ZVAL_STRING(_41$$28, "dispatch:beforeExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_40$$28, eventsManager, "fire", &_42, 0, _41$$28, this_ptr);
			zephir_check_temp_parameter(_41$$28);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_40$$28)) {
				continue;
			}
			_43$$28 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_43$$28)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(handler, SS("beforeexecuteroute") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_44$$31, handler, "beforeexecuteroute", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_44$$31)) {
				continue;
			}
			_45$$31 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_45$$31)) {
				continue;
			}
		}
		if (wasFresh == 1) {
			if ((zephir_method_exists_ex(handler, SS("initialize") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(NULL, handler, "initialize", NULL, 0);
				zephir_check_call_status();
			}
			if (zephir_is_true(eventsManager)) {
				ZEPHIR_INIT_NVAR(_47$$36);
				ZVAL_STRING(_47$$36, "dispatch:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_46$$36, eventsManager, "fire", &_48, 0, _47$$36, this_ptr);
				zephir_check_temp_parameter(_47$$36);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_46$$36)) {
					continue;
				}
				_49$$36 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_49$$36)) {
					continue;
				}
			}
		}
		_50$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_modelBinding"), PH_NOISY_CC);
		if (zephir_is_true(_50$$6)) {
			ZEPHIR_OBS_NVAR(modelBinder);
			zephir_read_property_this(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(bindCacheKey);
			ZEPHIR_CONCAT_SVSV(bindCacheKey, "_PHMB_", handlerClass, "_", actionMethod);
			ZEPHIR_CALL_METHOD(&_51$$39, modelBinder, "bindtohandler", NULL, 0, handler, params, bindCacheKey, actionMethod);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(params, _51$$39);
		}
		zephir_update_property_this(getThis(), SL("_lastHandler"), handler TSRMLS_CC);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_53$$40);
			ZVAL_STRING(_53$$40, "dispatch:afterBinding", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_52$$40, eventsManager, "fire", &_54, 0, _53$$40, this_ptr);
			zephir_check_temp_parameter(_53$$40);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_52$$40)) {
				continue;
			}
			_55$$40 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_55$$40)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(handler, SS("afterbinding") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_56$$43, handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_56$$43)) {
				continue;
			}
			_57$$43 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_57$$43)) {
				continue;
			}
		}

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&_58$$46, this_ptr, "callactionmethod", &_59, 0, handler, actionMethod, params);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(getThis(), SL("_returnedValue"), _58$$46 TSRMLS_CC);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(_60$$6);
			ZEPHIR_CPY_WRT(_60$$6, EG(exception));
			if (zephir_instance_of_ev(_60$$6, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(e, _60$$6);
				ZEPHIR_CALL_METHOD(&_61$$47, this_ptr, "_handleexception", &_62, 0, e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_61$$47)) {
					_63$$48 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
					if (ZEPHIR_IS_FALSE_IDENTICAL(_63$$48)) {
						continue;
					}
				} else {
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 661 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_65$$51);
			ZVAL_STRING(_65$$51, "dispatch:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_64$$51, eventsManager, "fire", &_66, 0, _65$$51, this_ptr, value);
			zephir_check_temp_parameter(_65$$51);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_64$$51)) {
				continue;
			}
			_67$$51 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_67$$51)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(_65$$51);
			ZVAL_STRING(_65$$51, "dispatch:afterDispatch", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_68, 0, _65$$51, this_ptr);
			zephir_check_temp_parameter(_65$$51);
			zephir_check_call_status();
		}
		if ((zephir_method_exists_ex(handler, SS("afterexecuteroute") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_69$$54, handler, "afterexecuteroute", NULL, 0, this_ptr, value);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_69$$54)) {
				continue;
			}
			_70$$54 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_70$$54)) {
				continue;
			}
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_71$$57);
		ZVAL_STRING(_71$$57, "dispatch:afterDispatchLoop", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _71$$57, this_ptr);
		zephir_check_temp_parameter(_71$$57);
		zephir_check_call_status();
	}
	RETURN_CCTOR(handler);

}

/**
 * Forwards the execution flow to another controller/action.
 *
 * <code>
 * $this->dispatcher->forward(
 *     [
 *         "controller" => "posts",
 *         "action"     => "index",
 *     ]
 * );
 * </code>
 *
 * @param array forward
 */
PHP_METHOD(Phalcon_Dispatcher, forward) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *forward, *namespaceName = NULL, *controllerName = NULL, *params = NULL, *actionName = NULL, *taskName = NULL, *_0$$3, *_1$$4, *_2$$5, *_3$$7, *_4$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	if (Z_TYPE_P(forward) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "Forward parameter must be an Array", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, _0$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	if (zephir_array_isset_string_fetch(&namespaceName, forward, SS("namespace"), 1 TSRMLS_CC)) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("_previousNamespaceName"), _1$$4 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_namespaceName"), namespaceName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&controllerName, forward, SS("controller"), 1 TSRMLS_CC)) {
		_2$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("_previousHandlerName"), _2$$5 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_handlerName"), controllerName TSRMLS_CC);
	} else {
		if (zephir_array_isset_string_fetch(&taskName, forward, SS("task"), 1 TSRMLS_CC)) {
			_3$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY_CC);
			zephir_update_property_this(getThis(), SL("_previousHandlerName"), _3$$7 TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_handlerName"), taskName TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string_fetch(&actionName, forward, SS("action"), 1 TSRMLS_CC)) {
		_4$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("_previousActionName"), _4$$8 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_actionName"), actionName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&params, forward, SS("params"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_params"), params TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (1) {
		zephir_update_property_this(getThis(), SL("_forwarded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_forwarded"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if the current executed action was forwarded by another one
 */
PHP_METHOD(Phalcon_Dispatcher, wasForwarded) {

	

	RETURN_MEMBER(getThis(), "_forwarded");

}

/**
 * Possible class name that will be located to dispatch the request
 */
PHP_METHOD(Phalcon_Dispatcher, getHandlerClass) {

	zval *handlerSuffix = NULL, *handlerName = NULL, *namespaceName = NULL, *camelizedClass = NULL, *handlerClass = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(handlerSuffix);
	zephir_read_property_this(&handlerSuffix, this_ptr, SL("_handlerSuffix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(handlerName);
	zephir_read_property_this(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(namespaceName);
	zephir_read_property_this(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
	if (!(zephir_memnstr_str(handlerName, SL("\\"), "phalcon/dispatcher.zep", 779))) {
		ZEPHIR_INIT_VAR(camelizedClass);
		zephir_camelize(camelizedClass, handlerName, NULL  );
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

PHP_METHOD(Phalcon_Dispatcher, callActionMethod) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, *_0;
	zval *actionMethod = NULL;
	zval *handler, *actionMethod_param = NULL, *params_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &handler, &actionMethod_param, &params_param);

	zephir_get_strval(actionMethod, actionMethod_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
	params = params_param;
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, handler);
	zephir_array_fast_append(_0, actionMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, params);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns bound models from binder instance
 *
 * <code>
 * class UserController extends Controller
 * {
 *     public function showAction(User $user)
 *     {
 *         $boundModels = $this->dispatcher->getBoundModels(); // return array with $user
 *     }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Dispatcher, getBoundModels) {

	zval *modelBinder = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(modelBinder);
	zephir_read_property_this(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
	if (Z_TYPE_P(modelBinder) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(modelBinder, "getboundmodels", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Set empty properties to their defaults (where defaults are available)
 */
PHP_METHOD(Phalcon_Dispatcher, _resolveEmptyProperties) {

	zval *_0, *_2, *_4, *_1$$3, *_3$$4, *_5$$5;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaceName"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("_namespaceName"), _1$$3 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY_CC);
	if (!(zephir_is_true(_2))) {
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("_handlerName"), _3$$4 TSRMLS_CC);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY_CC);
	if (!(zephir_is_true(_4))) {
		_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("_actionName"), _5$$5 TSRMLS_CC);
	}

}

zend_object_value zephir_init_properties_Phalcon_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_params"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

