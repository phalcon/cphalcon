
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
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

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_finished"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_isControllerInitialize"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zval *params;

	zephir_fetch_params(0, 1, 0, &params);



	if (Z_TYPE_P(params) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Parameters must be an Array", "phalcon/dispatcher.zep", 233);
		return;
	}
	zephir_update_property_this(getThis(), SL("_params"), params TSRMLS_CC);

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
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 74, cache);
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
 * Process the results of the router by calling into the appropriate controller action(s)
 * including any routing data or injected parameters.
 *
 * @return object|false Returns the dispatched handler class (the Controller for Mvc dispatching or a Task
 *                      for CLI dispatching) or <tt>false</tt> if an exception occurred and the operation was
 *                      stopped by returning <tt>false</tt> in the exception handler.
 *
 * @throws \Exception if any uncaught or unhandled exception occurs during the dispatcher process.
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch) {

	zval *_44$$10 = NULL;
	zval *value = NULL, *handler = NULL, *dependencyInjector = NULL, *namespaceName = NULL, *handlerName = NULL, *actionName = NULL, *params = NULL, *eventsManager = NULL, *actionSuffix = NULL, *handlerClass = NULL, *status = NULL, *actionMethod = NULL, *modelBinder = NULL, *bindCacheKey = NULL, *wasFresh = NULL, *e = NULL, *_0, *_1$$3, *_2$$3, *_3$$5 = NULL, *_4$$5, *_6$$5, *_7$$4, *_8$$7, *_9$$11 = NULL, *_10$$11 = NULL, *_13$$13 = NULL, *_14$$13 = NULL, *_17$$13, *_18$$12 = NULL, *_19$$15 = NULL, *_22$$15, *_24$$10 = NULL, *_91$$10, *_102$$10 = NULL, *_26$$18 = NULL, *_27$$18 = NULL, *_30$$18, *_33$$20 = NULL, *_34$$20 = NULL, *_37$$20, *_38$$22 = NULL, *_39$$22 = NULL, *_42$$22, *_45$$25 = NULL, *_46$$25 = NULL, *_48$$25, *_49$$24 = NULL, *_50$$24 = NULL, *_53$$24, *_54$$30 = NULL, *_55$$30 = NULL, *_58$$30, *_60$$29 = NULL, *_61$$32 = NULL, *_64$$32, *_66$$35 = NULL, *_68$$35, *_70$$34 = NULL, *_71$$37 = NULL, *_74$$37, *_76$$40 = NULL, *_77$$42 = NULL, *_80$$42, *_81$$45 = NULL, *_82$$45 = NULL, *_85$$45, *_86$$44 = NULL, *_87$$47 = NULL, *_90$$47, *_92$$49 = NULL, *_93$$50 = NULL, *_94$$50 = NULL, *_96$$50, *_97$$53 = NULL, *_98$$53, *_99$$56 = NULL, *_101$$56, *_103$$58 = NULL, *_106$$58, *_107$$61 = NULL, *_108$$61 = NULL, *_111$$61, *_112$$60 = NULL, *_113$$63 = NULL, *_116$$63, *_117$$66 = NULL, *_119$$66, *_120$$65 = NULL, *_121$$68 = NULL, *_124$$68, *_125$$71 = NULL, *_127$$70 = NULL, *_128$$72 = NULL, *_131$$72, *_132$$75, *_133$$74, *_134$$76 = NULL;
	zend_bool hasService = 0, hasEventsManager = 0, _5$$5, _16$$13, _21$$15, _29$$18, _36$$20, _41$$22, _52$$24, _57$$30, _63$$32, _67$$35, _73$$37, _79$$42, _84$$45, _89$$47, _105$$58, _110$$61, _115$$63, _118$$66, _123$$68, _130$$72;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_15 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_28 = NULL, *_31 = NULL, *_32 = NULL, *_35 = NULL, *_40 = NULL, *_43 = NULL, *_47 = NULL, *_51 = NULL, *_56 = NULL, *_59 = NULL, *_62 = NULL, *_65 = NULL, *_69 = NULL, *_72 = NULL, *_75 = NULL, *_78 = NULL, *_83 = NULL, *_88 = NULL, *_95 = NULL, *_100 = NULL, *_104 = NULL, *_109 = NULL, *_114 = NULL, *_122 = NULL, *_126 = NULL, *_129 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberDispatches = 0;

	ZEPHIR_MM_GROW();

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
	hasEventsManager = Z_TYPE_P(eventsManager) == IS_OBJECT;
	if (1) {
		zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (hasEventsManager) {

		/* try_start_1: */

			ZEPHIR_INIT_VAR(_4$$5);
			ZVAL_STRING(_4$$5, "dispatch:beforeDispatchLoop", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3$$5, eventsManager, "fire", NULL, 0, _4$$5, this_ptr);
			zephir_check_temp_parameter(_4$$5);
			zephir_check_call_status_or_jump(try_end_1);
			_5$$5 = ZEPHIR_IS_FALSE_IDENTICAL(_3$$5);
			if (_5$$5) {
				_6$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				_5$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(_6$$5);
			}
			if (_5$$5) {
				RETURN_MM_BOOL(0);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(_7$$4);
			ZEPHIR_CPY_WRT(_7$$4, EG(exception));
			if (zephir_instance_of_ev(_7$$4, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(e, _7$$4);
				ZEPHIR_CALL_METHOD(&status, this_ptr, "_handleexception", NULL, 0, e);
				zephir_check_call_status();
				_8$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (!ZEPHIR_IS_FALSE_IDENTICAL(_8$$7)) {
					if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
						RETURN_MM_BOOL(0);
					}
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 461 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
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
			ZEPHIR_INIT_NVAR(_9$$11);
			ZVAL_STRING(_9$$11, "Dispatcher has detected a cyclic routing causing stability problems", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_10$$11);
			ZVAL_LONG(_10$$11, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", &_11, 0, _9$$11, _10$$11);
			zephir_check_temp_parameter(_9$$11);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", &_12, 0);
		zephir_check_call_status();
		if (hasEventsManager) {

			/* try_start_2: */

				ZEPHIR_INIT_NVAR(_14$$13);
				ZVAL_STRING(_14$$13, "dispatch:beforeDispatch", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_13$$13, eventsManager, "fire", &_15, 0, _14$$13, this_ptr);
				zephir_check_temp_parameter(_14$$13);
				zephir_check_call_status_or_jump(try_end_2);
				_16$$13 = ZEPHIR_IS_FALSE_IDENTICAL(_13$$13);
				if (!(_16$$13)) {
					_17$$13 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
					_16$$13 = ZEPHIR_IS_FALSE_IDENTICAL(_17$$13);
				}
				if (_16$$13) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(_18$$12);
				ZEPHIR_CPY_WRT(_18$$12, EG(exception));
				if (zephir_instance_of_ev(_18$$12, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(e, _18$$12);
					ZEPHIR_CALL_METHOD(&_19$$15, this_ptr, "_handleexception", &_20, 0, e);
					zephir_check_call_status();
					_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(_19$$15);
					if (!(_21$$15)) {
						_22$$15 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
						_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(_22$$15);
					}
					if (_21$$15) {
						continue;
					}
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 497 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_23, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_24$$10, dependencyInjector, "has", &_25, 0, handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(_24$$10);
		if (!(hasService)) {
			hasService = zephir_class_exists(handlerClass, 1 TSRMLS_CC);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_LNVAR(_26$$18);
			ZEPHIR_CONCAT_VS(_26$$18, handlerClass, " handler class cannot be loaded");
			ZEPHIR_INIT_NVAR(_27$$18);
			ZVAL_LONG(_27$$18, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_28, 0, _26$$18, _27$$18);
			zephir_check_call_status();
			_29$$18 = ZEPHIR_IS_FALSE_IDENTICAL(status);
			if (_29$$18) {
				_30$$18 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				_29$$18 = ZEPHIR_IS_FALSE_IDENTICAL(_30$$18);
			}
			if (_29$$18) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, dependencyInjector, "getshared", &_31, 0, handlerClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&wasFresh, dependencyInjector, "wasfreshinstance", &_32, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(handler) != IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_33$$20);
			ZVAL_STRING(_33$$20, "Invalid handler returned from the services container", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_34$$20);
			ZVAL_LONG(_34$$20, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_35, 0, _33$$20, _34$$20);
			zephir_check_temp_parameter(_33$$20);
			zephir_check_call_status();
			_36$$20 = ZEPHIR_IS_FALSE_IDENTICAL(status);
			if (_36$$20) {
				_37$$20 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				_36$$20 = ZEPHIR_IS_FALSE_IDENTICAL(_37$$20);
			}
			if (_36$$20) {
				continue;
			}
			break;
		}
		zephir_update_property_this(getThis(), SL("_activeHandler"), handler TSRMLS_CC);
		ZEPHIR_OBS_NVAR(namespaceName);
		zephir_read_property_this(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(handlerName);
		zephir_read_property_this(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("_actionName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(params);
		zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_38$$22);
			ZVAL_STRING(_38$$22, "Action parameters must be an Array", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_39$$22);
			ZVAL_LONG(_39$$22, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_40, 0, _38$$22, _39$$22);
			zephir_check_temp_parameter(_38$$22);
			zephir_check_call_status();
			_41$$22 = ZEPHIR_IS_FALSE_IDENTICAL(status);
			if (_41$$22) {
				_42$$22 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				_41$$22 = ZEPHIR_IS_FALSE_IDENTICAL(_42$$22);
			}
			if (_41$$22) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_43, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_44$$10);
		zephir_create_array(_44$$10, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_44$$10, handler);
		zephir_array_fast_append(_44$$10, actionMethod);
		if (!(zephir_is_callable(_44$$10 TSRMLS_CC))) {
			if (hasEventsManager) {
				ZEPHIR_INIT_NVAR(_46$$25);
				ZVAL_STRING(_46$$25, "dispatch:beforeNotFoundAction", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_45$$25, eventsManager, "fire", &_47, 0, _46$$25, this_ptr);
				zephir_check_temp_parameter(_46$$25);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_45$$25)) {
					continue;
				}
				_48$$25 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				if (ZEPHIR_IS_FALSE_IDENTICAL(_48$$25)) {
					continue;
				}
			}
			ZEPHIR_INIT_LNVAR(_49$$24);
			ZEPHIR_CONCAT_SVSVS(_49$$24, "Action '", actionName, "' was not found on handler '", handlerName, "'");
			ZEPHIR_INIT_NVAR(_50$$24);
			ZVAL_LONG(_50$$24, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_51, 0, _49$$24, _50$$24);
			zephir_check_call_status();
			_52$$24 = ZEPHIR_IS_FALSE_IDENTICAL(status);
			if (_52$$24) {
				_53$$24 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
				_52$$24 = ZEPHIR_IS_FALSE_IDENTICAL(_53$$24);
			}
			if (_52$$24) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(_55$$30);
				ZVAL_STRING(_55$$30, "dispatch:beforeExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_54$$30, eventsManager, "fire", &_56, 0, _55$$30, this_ptr);
				zephir_check_temp_parameter(_55$$30);
				zephir_check_call_status_or_jump(try_end_3);
				_57$$30 = ZEPHIR_IS_FALSE_IDENTICAL(_54$$30);
				if (!(_57$$30)) {
					_58$$30 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
					_57$$30 = ZEPHIR_IS_FALSE_IDENTICAL(_58$$30);
				}
				if (_57$$30) {
					ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "remove", &_59, 0, handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(_60$$29);
				ZEPHIR_CPY_WRT(_60$$29, EG(exception));
				if (zephir_instance_of_ev(_60$$29, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(e, _60$$29);
					ZEPHIR_CALL_METHOD(&_61$$32, this_ptr, "_handleexception", &_62, 0, e);
					zephir_check_call_status();
					_63$$32 = ZEPHIR_IS_FALSE_IDENTICAL(_61$$32);
					if (!(_63$$32)) {
						_64$$32 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
						_63$$32 = ZEPHIR_IS_FALSE_IDENTICAL(_64$$32);
					}
					if (_63$$32) {
						ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "remove", &_65, 0, handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 591 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(handler, SS("beforeexecuteroute") TSRMLS_CC) == SUCCESS)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_66$$35, handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_67$$35 = ZEPHIR_IS_FALSE_IDENTICAL(_66$$35);
				if (!(_67$$35)) {
					_68$$35 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
					_67$$35 = ZEPHIR_IS_FALSE_IDENTICAL(_68$$35);
				}
				if (_67$$35) {
					ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "remove", &_69, 0, handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(_70$$34);
				ZEPHIR_CPY_WRT(_70$$34, EG(exception));
				if (zephir_instance_of_ev(_70$$34, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(e, _70$$34);
					ZEPHIR_CALL_METHOD(&_71$$37, this_ptr, "_handleexception", &_72, 0, e);
					zephir_check_call_status();
					_73$$37 = ZEPHIR_IS_FALSE_IDENTICAL(_71$$37);
					if (!(_73$$37)) {
						_74$$37 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
						_73$$37 = ZEPHIR_IS_FALSE_IDENTICAL(_74$$37);
					}
					if (_73$$37) {
						ZEPHIR_CALL_METHOD(NULL, dependencyInjector, "remove", &_75, 0, handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 608 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(wasFresh)) {
			if ((zephir_method_exists_ex(handler, SS("initialize") TSRMLS_CC) == SUCCESS)) {

				/* try_start_5: */

					if (1) {
						zephir_update_property_this(getThis(), SL("_isControllerInitialize"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
					} else {
						zephir_update_property_this(getThis(), SL("_isControllerInitialize"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
					}
					ZEPHIR_CALL_METHOD(NULL, handler, "initialize", NULL, 0);
					zephir_check_call_status_or_jump(try_end_5);

				try_end_5:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(_76$$40);
					ZEPHIR_CPY_WRT(_76$$40, EG(exception));
					if (zephir_instance_of_ev(_76$$40, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(e, _76$$40);
						if (0) {
							zephir_update_property_this(getThis(), SL("_isControllerInitialize"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
						} else {
							zephir_update_property_this(getThis(), SL("_isControllerInitialize"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
						}
						ZEPHIR_CALL_METHOD(&_77$$42, this_ptr, "_handleexception", &_78, 0, e);
						zephir_check_call_status();
						_79$$42 = ZEPHIR_IS_FALSE_IDENTICAL(_77$$42);
						if (!(_79$$42)) {
							_80$$42 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
							_79$$42 = ZEPHIR_IS_FALSE_IDENTICAL(_80$$42);
						}
						if (_79$$42) {
							continue;
						}
						zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 641 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			if (0) {
				zephir_update_property_this(getThis(), SL("_isControllerInitialize"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(getThis(), SL("_isControllerInitialize"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			if (zephir_is_true(eventsManager)) {

				/* try_start_6: */

					ZEPHIR_INIT_NVAR(_82$$45);
					ZVAL_STRING(_82$$45, "dispatch:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_81$$45, eventsManager, "fire", &_83, 0, _82$$45, this_ptr);
					zephir_check_temp_parameter(_82$$45);
					zephir_check_call_status_or_jump(try_end_6);
					_84$$45 = ZEPHIR_IS_FALSE_IDENTICAL(_81$$45);
					if (!(_84$$45)) {
						_85$$45 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
						_84$$45 = ZEPHIR_IS_FALSE_IDENTICAL(_85$$45);
					}
					if (_84$$45) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(_86$$44);
					ZEPHIR_CPY_WRT(_86$$44, EG(exception));
					if (zephir_instance_of_ev(_86$$44, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(e, _86$$44);
						ZEPHIR_CALL_METHOD(&_87$$47, this_ptr, "_handleexception", &_88, 0, e);
						zephir_check_call_status();
						_89$$47 = ZEPHIR_IS_FALSE_IDENTICAL(_87$$47);
						if (!(_89$$47)) {
							_90$$47 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
							_89$$47 = ZEPHIR_IS_FALSE_IDENTICAL(_90$$47);
						}
						if (_89$$47) {
							continue;
						}
						zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 658 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		_91$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_modelBinding"), PH_NOISY_CC);
		if (zephir_is_true(_91$$10)) {
			ZEPHIR_OBS_NVAR(modelBinder);
			zephir_read_property_this(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(bindCacheKey);
			ZEPHIR_CONCAT_SVSV(bindCacheKey, "_PHMB_", handlerClass, "_", actionMethod);
			ZEPHIR_CALL_METHOD(&_92$$49, modelBinder, "bindtohandler", NULL, 0, handler, params, bindCacheKey, actionMethod);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(params, _92$$49);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(_94$$50);
			ZVAL_STRING(_94$$50, "dispatch:afterBinding", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_93$$50, eventsManager, "fire", &_95, 0, _94$$50, this_ptr);
			zephir_check_temp_parameter(_94$$50);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_93$$50)) {
				continue;
			}
			_96$$50 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_96$$50)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(handler, SS("afterbinding") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_97$$53, handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_97$$53)) {
				continue;
			}
			_98$$53 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_98$$53)) {
				continue;
			}
		}
		zephir_update_property_this(getThis(), SL("_lastHandler"), handler TSRMLS_CC);

		/* try_start_7: */

			ZEPHIR_CALL_METHOD(&_99$$56, this_ptr, "callactionmethod", &_100, 0, handler, actionMethod, params);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_this(getThis(), SL("_returnedValue"), _99$$56 TSRMLS_CC);
			_101$$56 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_101$$56)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(_102$$10);
			ZEPHIR_CPY_WRT(_102$$10, EG(exception));
			if (zephir_instance_of_ev(_102$$10, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(e, _102$$10);
				ZEPHIR_CALL_METHOD(&_103$$58, this_ptr, "_handleexception", &_104, 0, e);
				zephir_check_call_status();
				_105$$58 = ZEPHIR_IS_FALSE_IDENTICAL(_103$$58);
				if (!(_105$$58)) {
					_106$$58 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
					_105$$58 = ZEPHIR_IS_FALSE_IDENTICAL(_106$$58);
				}
				if (_105$$58) {
					continue;
				}
				zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 708 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(_108$$61);
				ZVAL_STRING(_108$$61, "dispatch:afterExecuteRoute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_107$$61, eventsManager, "fire", &_109, 0, _108$$61, this_ptr, value);
				zephir_check_temp_parameter(_108$$61);
				zephir_check_call_status_or_jump(try_end_8);
				_110$$61 = ZEPHIR_IS_FALSE_IDENTICAL(_107$$61);
				if (!(_110$$61)) {
					_111$$61 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
					_110$$61 = ZEPHIR_IS_FALSE_IDENTICAL(_111$$61);
				}
				if (_110$$61) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(_112$$60);
				ZEPHIR_CPY_WRT(_112$$60, EG(exception));
				if (zephir_instance_of_ev(_112$$60, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(e, _112$$60);
					ZEPHIR_CALL_METHOD(&_113$$63, this_ptr, "_handleexception", &_114, 0, e);
					zephir_check_call_status();
					_115$$63 = ZEPHIR_IS_FALSE_IDENTICAL(_113$$63);
					if (!(_115$$63)) {
						_116$$63 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
						_115$$63 = ZEPHIR_IS_FALSE_IDENTICAL(_116$$63);
					}
					if (_115$$63) {
						continue;
					}
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 722 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(handler, SS("afterexecuteroute") TSRMLS_CC) == SUCCESS)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_117$$66, handler, "afterexecuteroute", NULL, 0, this_ptr, value);
				zephir_check_call_status_or_jump(try_end_9);
				_118$$66 = ZEPHIR_IS_FALSE_IDENTICAL(_117$$66);
				if (!(_118$$66)) {
					_119$$66 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
					_118$$66 = ZEPHIR_IS_FALSE_IDENTICAL(_119$$66);
				}
				if (_118$$66) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(_120$$65);
				ZEPHIR_CPY_WRT(_120$$65, EG(exception));
				if (zephir_instance_of_ev(_120$$65, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(e, _120$$65);
					ZEPHIR_CALL_METHOD(&_121$$68, this_ptr, "_handleexception", &_122, 0, e);
					zephir_check_call_status();
					_123$$68 = ZEPHIR_IS_FALSE_IDENTICAL(_121$$68);
					if (!(_123$$68)) {
						_124$$68 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
						_123$$68 = ZEPHIR_IS_FALSE_IDENTICAL(_124$$68);
					}
					if (_123$$68) {
						continue;
					}
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 737 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(_125$$71);
				ZVAL_STRING(_125$$71, "dispatch:afterDispatch", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_126, 0, _125$$71, this_ptr, value);
				zephir_check_temp_parameter(_125$$71);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(_127$$70);
				ZEPHIR_CPY_WRT(_127$$70, EG(exception));
				if (zephir_instance_of_ev(_127$$70, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(e, _127$$70);
					ZEPHIR_CALL_METHOD(&_128$$72, this_ptr, "_handleexception", &_129, 0, e);
					zephir_check_call_status();
					_130$$72 = ZEPHIR_IS_FALSE_IDENTICAL(_128$$72);
					if (!(_130$$72)) {
						_131$$72 = zephir_fetch_nproperty_this(this_ptr, SL("_finished"), PH_NOISY_CC);
						_130$$72 = ZEPHIR_IS_FALSE_IDENTICAL(_131$$72);
					}
					if (_130$$72) {
						continue;
					}
					zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 751 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(_132$$75);
			ZVAL_STRING(_132$$75, "dispatch:afterDispatchLoop", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _132$$75, this_ptr);
			zephir_check_temp_parameter(_132$$75);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(_133$$74);
			ZEPHIR_CPY_WRT(_133$$74, EG(exception));
			if (zephir_instance_of_ev(_133$$74, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(e, _133$$74);
				ZEPHIR_CALL_METHOD(&_134$$76, this_ptr, "_handleexception", NULL, 0, e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_134$$76)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(e, "phalcon/dispatcher.zep", 768 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
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
 *
 * @throws \Phalcon\Exception
 */
PHP_METHOD(Phalcon_Dispatcher, forward) {

	zval *forward, *namespaceName = NULL, *controllerName = NULL, *params = NULL, *actionName = NULL, *taskName = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_isControllerInitialize"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Forwarding inside a controller's initialize() method is forbidden", "phalcon/dispatcher.zep", 799);
		return;
	}
	if (Z_TYPE_P(forward) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Forward parameter must be an Array", "phalcon/dispatcher.zep", 807);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_namespaceName"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_previousNamespaceName"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_handlerName"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_previousHandlerName"), _2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_actionName"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_previousActionName"), _3 TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&namespaceName, forward, SS("namespace"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_namespaceName"), namespaceName TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(taskName);
	if (zephir_array_isset_string_fetch(&controllerName, forward, SS("controller"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_handlerName"), controllerName TSRMLS_CC);
	} else if (zephir_array_isset_string_fetch(&taskName, forward, SS("task"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_handlerName"), taskName TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&actionName, forward, SS("action"), 1 TSRMLS_CC)) {
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
	if (!(zephir_memnstr_str(handlerName, SL("\\"), "phalcon/dispatcher.zep", 864))) {
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

