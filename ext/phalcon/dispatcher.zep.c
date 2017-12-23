
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
	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_NO_DI"), 0);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_CYCLIC_ROUTING"), 1);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_HANDLER_NOT_FOUND"), 2);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_INVALID_HANDLER"), 3);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_INVALID_PARAMS"), 4);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_ACTION_NOT_FOUND"), 5);

	zend_class_implements(phalcon_dispatcher_ce TSRMLS_CC, 1, phalcon_dispatcherinterface_ce);
	zend_class_implements(phalcon_dispatcher_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_dispatcher_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Dispatcher, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Dispatcher, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Sets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher, setActionSuffix) {

	zval *actionSuffix_param = NULL;
	zval actionSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	zephir_get_strval(&actionSuffix, actionSuffix_param);


	zephir_update_property_zval(this_ptr, SL("_actionSuffix"), &actionSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher, getActionSuffix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_actionSuffix");

}

/**
 * Sets the module where the controller is (only informative)
 */
PHP_METHOD(Phalcon_Dispatcher, setModuleName) {

	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(&moduleName, moduleName_param);


	zephir_update_property_zval(this_ptr, SL("_moduleName"), &moduleName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the module where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher, getModuleName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_moduleName");

}

/**
 * Sets the namespace where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName) {

	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	zephir_get_strval(&namespaceName, namespaceName_param);


	zephir_update_property_zval(this_ptr, SL("_namespaceName"), &namespaceName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets a namespace to be prepended to the current handler name
 */
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_namespaceName");

}

/**
 * Sets the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace) {

	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	zephir_get_strval(&namespaceName, namespaceName_param);


	zephir_update_property_zval(this_ptr, SL("_defaultNamespace"), &namespaceName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_defaultNamespace");

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction) {

	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, SL("_defaultAction"), &actionName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the action name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName) {

	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, SL("_actionName"), &actionName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the latest dispatched action name
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_actionName");

}

/**
 * Sets action params to be dispatched
 *
 * @param array params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams) {

	zval *params, params_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);

	zephir_fetch_params(0, 1, 0, &params);



	if (Z_TYPE_P(params) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Parameters must be an Array", "phalcon/dispatcher.zep", 233);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_params"), params);

}

/**
 * Gets action params
 */
PHP_METHOD(Phalcon_Dispatcher, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed param
 * @param  mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setParam) {

	zval *param, param_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&value_sub);

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
	zval *param, param_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null, params, filter, paramValue, dependencyInjector, _2, _3, _0$$5, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &param, &filters, &defaultValue);

	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_OBS_VAR(&params);
	zephir_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&paramValue);
	if (!(zephir_array_isset_fetch(&paramValue, &params, param, 0 TSRMLS_CC))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) == IS_NULL) {
		RETURN_CCTOR(&paramValue);
	}
	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$5);
		ZVAL_STRING(&_0$$5, "A dependency injection object is required to access the 'filter' service");
		ZVAL_LONG(&_1$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, &_0$$5, &_1$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "filter");
	ZEPHIR_CALL_METHOD(&_2, &dependencyInjector, "getshared", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filter, &_2);
	ZEPHIR_RETURN_CALL_METHOD(&filter, "sanitize", NULL, 0, &paramValue, filters);
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

	zval *param, param_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &param);



	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, param));

}

/**
 * Returns the current method to be/executed in the dispatcher
 */
PHP_METHOD(Phalcon_Dispatcher, getActiveMethod) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_actionSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &_1);
	return;

}

/**
 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
 */
PHP_METHOD(Phalcon_Dispatcher, isFinished) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_finished");

}

/**
 * Sets the latest returned value by an action manually
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setReturnedValue) {

	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_zval(this_ptr, SL("_returnedValue"), value);

}

/**
 * Returns value returned by the latest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue) {

	zval *this_ptr = getThis();


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
	zval *value_param = NULL, *cache = NULL, cache_sub, __$true, __$false, __$null, dependencyInjector, _0$$3, _1$$4;
	zend_bool value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &cache);

	value = zephir_get_boolval(value_param);
	if (!cache) {
		cache = &cache_sub;
		ZEPHIR_CPY_WRT(cache, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_OBS_VAR(&dependencyInjector);
		zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_0$$3);
	}
	if (value) {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$false);
	}
	if (value) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_binder_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 68, cache);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_modelBinder"), &_1$$4);
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
	zval *modelBinder, modelBinder_sub, *cache = NULL, cache_sub, __$true, __$false, __$null, dependencyInjector, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelBinder, &cache);

	if (!cache) {
		cache = &cache_sub;
		ZEPHIR_CPY_WRT(cache, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_OBS_VAR(&dependencyInjector);
		zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_0$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("_modelBinder"), modelBinder);
	RETURN_THIS();

}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Dispatcher, getModelBinder) {

	zval *this_ptr = getThis();


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

	zval _41$$10;
	zend_bool hasService = 0, hasEventsManager = 0, _5$$5, _16$$13, _21$$15, _29$$18, _35$$20, _39$$22, _49$$24, _53$$30, _59$$32, _63$$35, _69$$37, _75$$42, _80$$45, _85$$47, _101$$58, _106$$61, _111$$63, _114$$66, _119$$68, _126$$72;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_15 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_28 = NULL, *_30 = NULL, *_31 = NULL, *_34 = NULL, *_38 = NULL, *_40 = NULL, *_44 = NULL, *_48 = NULL, *_52 = NULL, *_55 = NULL, *_58 = NULL, *_61 = NULL, *_65 = NULL, *_68 = NULL, *_71 = NULL, *_74 = NULL, *_79 = NULL, *_84 = NULL, *_91 = NULL, *_96 = NULL, *_100 = NULL, *_105 = NULL, *_110 = NULL, *_118 = NULL, *_122 = NULL, *_125 = NULL;
	zval __$true, __$false, value, handler, dependencyInjector, namespaceName, handlerName, actionName, params, eventsManager, actionSuffix, handlerClass, status, actionMethod, modelBinder, bindCacheKey, wasFresh, e, _0, _1$$3, _2$$3, _3$$5, _4$$5, _6$$5, _7$$4, _8$$7, _9$$11, _10$$11, _13$$13, _14$$13, _17$$13, _18$$12, _19$$15, _22$$15, _24$$10, _87$$10, _98$$10, _26$$18, _27$$18, _32$$20, _33$$20, _36$$22, _37$$22, _42$$25, _43$$25, _45$$25, _46$$24, _47$$24, _50$$30, _51$$30, _54$$30, _56$$29, _57$$32, _60$$32, _62$$35, _64$$35, _66$$34, _67$$37, _70$$37, _72$$40, _73$$42, _76$$42, _77$$45, _78$$45, _81$$45, _82$$44, _83$$47, _86$$47, _88$$49, _89$$50, _90$$50, _92$$50, _93$$53, _94$$53, _95$$56, _97$$56, _99$$58, _102$$58, _103$$61, _104$$61, _107$$61, _108$$60, _109$$63, _112$$63, _113$$66, _115$$66, _116$$65, _117$$68, _120$$68, _121$$71, _123$$70, _124$$72, _127$$72, _128$$75, _129$$74, _130$$76;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberDispatches = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&handlerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&actionSuffix);
	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&wasFresh);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_87$$10);
	ZVAL_UNDEF(&_98$$10);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_42$$25);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_45$$25);
	ZVAL_UNDEF(&_46$$24);
	ZVAL_UNDEF(&_47$$24);
	ZVAL_UNDEF(&_50$$30);
	ZVAL_UNDEF(&_51$$30);
	ZVAL_UNDEF(&_54$$30);
	ZVAL_UNDEF(&_56$$29);
	ZVAL_UNDEF(&_57$$32);
	ZVAL_UNDEF(&_60$$32);
	ZVAL_UNDEF(&_62$$35);
	ZVAL_UNDEF(&_64$$35);
	ZVAL_UNDEF(&_66$$34);
	ZVAL_UNDEF(&_67$$37);
	ZVAL_UNDEF(&_70$$37);
	ZVAL_UNDEF(&_72$$40);
	ZVAL_UNDEF(&_73$$42);
	ZVAL_UNDEF(&_76$$42);
	ZVAL_UNDEF(&_77$$45);
	ZVAL_UNDEF(&_78$$45);
	ZVAL_UNDEF(&_81$$45);
	ZVAL_UNDEF(&_82$$44);
	ZVAL_UNDEF(&_83$$47);
	ZVAL_UNDEF(&_86$$47);
	ZVAL_UNDEF(&_88$$49);
	ZVAL_UNDEF(&_89$$50);
	ZVAL_UNDEF(&_90$$50);
	ZVAL_UNDEF(&_92$$50);
	ZVAL_UNDEF(&_93$$53);
	ZVAL_UNDEF(&_94$$53);
	ZVAL_UNDEF(&_95$$56);
	ZVAL_UNDEF(&_97$$56);
	ZVAL_UNDEF(&_99$$58);
	ZVAL_UNDEF(&_102$$58);
	ZVAL_UNDEF(&_103$$61);
	ZVAL_UNDEF(&_104$$61);
	ZVAL_UNDEF(&_107$$61);
	ZVAL_UNDEF(&_108$$60);
	ZVAL_UNDEF(&_109$$63);
	ZVAL_UNDEF(&_112$$63);
	ZVAL_UNDEF(&_113$$66);
	ZVAL_UNDEF(&_115$$66);
	ZVAL_UNDEF(&_116$$65);
	ZVAL_UNDEF(&_117$$68);
	ZVAL_UNDEF(&_120$$68);
	ZVAL_UNDEF(&_121$$71);
	ZVAL_UNDEF(&_123$$70);
	ZVAL_UNDEF(&_124$$72);
	ZVAL_UNDEF(&_127$$72);
	ZVAL_UNDEF(&_128$$75);
	ZVAL_UNDEF(&_129$$74);
	ZVAL_UNDEF(&_130$$76);
	ZVAL_UNDEF(&_41$$10);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "A dependency injection container is required to access related dispatching services");
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	hasEventsManager = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
	}
	if (hasEventsManager) {

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "dispatch:beforeDispatchLoop");
			ZEPHIR_CALL_METHOD(&_3$$5, &eventsManager, "fire", NULL, 0, &_4$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			_5$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&_3$$5);
			if (_5$$5) {
				zephir_read_property(&_6$$5, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_5$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(&_6$$5);
			}
			if (_5$$5) {
				RETURN_MM_BOOL(0);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_OBJ(&_7$$4, EG(exception));
			Z_ADDREF_P(&_7$$4);
			if (zephir_instance_of_ev(&_7$$4, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_7$$4);
				ZEPHIR_CALL_METHOD(&status, this_ptr, "_handleexception", NULL, 0, &e);
				zephir_check_call_status();
				zephir_read_property(&_8$$7, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_8$$7)) {
					if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
						RETURN_MM_BOOL(0);
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 461 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	ZEPHIR_INIT_VAR(&handler);
	ZVAL_NULL(&handler);
	numberDispatches = 0;
	ZEPHIR_OBS_VAR(&actionSuffix);
	zephir_read_property(&actionSuffix, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
	}
	while (1) {
		zephir_read_property(&_0, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
		if (!(!(zephir_is_true(&_0)))) {
			break;
		}
		numberDispatches++;
		if (numberDispatches == 256) {
			ZEPHIR_INIT_NVAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "Dispatcher has detected a cyclic routing causing stability problems");
			ZVAL_LONG(&_10$$11, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", &_11, 0, &_9$$11, &_10$$11);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", &_12, 0);
		zephir_check_call_status();
		if (hasEventsManager) {

			/* try_start_2: */

				ZEPHIR_INIT_NVAR(&_14$$13);
				ZVAL_STRING(&_14$$13, "dispatch:beforeDispatch");
				ZEPHIR_CALL_METHOD(&_13$$13, &eventsManager, "fire", &_15, 0, &_14$$13, this_ptr);
				zephir_check_call_status_or_jump(try_end_2);
				_16$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_13$$13);
				if (!(_16$$13)) {
					zephir_read_property(&_17$$13, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_16$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_17$$13);
				}
				if (_16$$13) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_18$$12);
				ZVAL_OBJ(&_18$$12, EG(exception));
				Z_ADDREF_P(&_18$$12);
				if (zephir_instance_of_ev(&_18$$12, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_18$$12);
					ZEPHIR_CALL_METHOD(&_19$$15, this_ptr, "_handleexception", &_20, 0, &e);
					zephir_check_call_status();
					_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_19$$15);
					if (!(_21$$15)) {
						zephir_read_property(&_22$$15, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_22$$15);
					}
					if (_21$$15) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 497 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_23, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_24$$10, &dependencyInjector, "has", &_25, 0, &handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(&_24$$10);
		if (!(hasService)) {
			hasService = zephir_class_exists(&handlerClass, 1 TSRMLS_CC);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_LNVAR(_26$$18);
			ZEPHIR_CONCAT_VS(&_26$$18, &handlerClass, " handler class cannot be loaded");
			ZVAL_LONG(&_27$$18, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_28, 0, &_26$$18, &_27$$18);
			zephir_check_call_status();
			_29$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_29$$18) {
				zephir_read_property(&_27$$18, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_29$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&_27$$18);
			}
			if (_29$$18) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, &dependencyInjector, "getshared", &_30, 0, &handlerClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&wasFresh, &dependencyInjector, "wasfreshinstance", &_31, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&handler) != IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_32$$20);
			ZVAL_STRING(&_32$$20, "Invalid handler returned from the services container");
			ZVAL_LONG(&_33$$20, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_34, 0, &_32$$20, &_33$$20);
			zephir_check_call_status();
			_35$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_35$$20) {
				zephir_read_property(&_33$$20, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_35$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&_33$$20);
			}
			if (_35$$20) {
				continue;
			}
			break;
		}
		zephir_update_property_zval(this_ptr, SL("_activeHandler"), &handler);
		ZEPHIR_OBS_NVAR(&namespaceName);
		zephir_read_property(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&handlerName);
		zephir_read_property(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, SL("_actionName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&params);
		zephir_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_36$$22);
			ZVAL_STRING(&_36$$22, "Action parameters must be an Array");
			ZVAL_LONG(&_37$$22, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_38, 0, &_36$$22, &_37$$22);
			zephir_check_call_status();
			_39$$22 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_39$$22) {
				zephir_read_property(&_37$$22, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_39$$22 = ZEPHIR_IS_FALSE_IDENTICAL(&_37$$22);
			}
			if (_39$$22) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_40, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_41$$10);
		zephir_create_array(&_41$$10, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_41$$10, &handler);
		zephir_array_fast_append(&_41$$10, &actionMethod);
		if (!(zephir_is_callable(&_41$$10 TSRMLS_CC))) {
			if (hasEventsManager) {
				ZEPHIR_INIT_NVAR(&_43$$25);
				ZVAL_STRING(&_43$$25, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD(&_42$$25, &eventsManager, "fire", &_44, 0, &_43$$25, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_42$$25)) {
					continue;
				}
				zephir_read_property(&_45$$25, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_45$$25)) {
					continue;
				}
			}
			ZEPHIR_INIT_LNVAR(_46$$24);
			ZEPHIR_CONCAT_SVSVS(&_46$$24, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_47$$24, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_48, 0, &_46$$24, &_47$$24);
			zephir_check_call_status();
			_49$$24 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_49$$24) {
				zephir_read_property(&_47$$24, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_49$$24 = ZEPHIR_IS_FALSE_IDENTICAL(&_47$$24);
			}
			if (_49$$24) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_51$$30);
				ZVAL_STRING(&_51$$30, "dispatch:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_50$$30, &eventsManager, "fire", &_52, 0, &_51$$30, this_ptr);
				zephir_check_call_status_or_jump(try_end_3);
				_53$$30 = ZEPHIR_IS_FALSE_IDENTICAL(&_50$$30);
				if (!(_53$$30)) {
					zephir_read_property(&_54$$30, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_53$$30 = ZEPHIR_IS_FALSE_IDENTICAL(&_54$$30);
				}
				if (_53$$30) {
					ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_55, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_56$$29);
				ZVAL_OBJ(&_56$$29, EG(exception));
				Z_ADDREF_P(&_56$$29);
				if (zephir_instance_of_ev(&_56$$29, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_56$$29);
					ZEPHIR_CALL_METHOD(&_57$$32, this_ptr, "_handleexception", &_58, 0, &e);
					zephir_check_call_status();
					_59$$32 = ZEPHIR_IS_FALSE_IDENTICAL(&_57$$32);
					if (!(_59$$32)) {
						zephir_read_property(&_60$$32, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_59$$32 = ZEPHIR_IS_FALSE_IDENTICAL(&_60$$32);
					}
					if (_59$$32) {
						ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_61, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 591 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, SL("beforeexecuteroute") TSRMLS_CC) == SUCCESS)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_62$$35, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_63$$35 = ZEPHIR_IS_FALSE_IDENTICAL(&_62$$35);
				if (!(_63$$35)) {
					zephir_read_property(&_64$$35, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_63$$35 = ZEPHIR_IS_FALSE_IDENTICAL(&_64$$35);
				}
				if (_63$$35) {
					ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_65, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_66$$34);
				ZVAL_OBJ(&_66$$34, EG(exception));
				Z_ADDREF_P(&_66$$34);
				if (zephir_instance_of_ev(&_66$$34, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_66$$34);
					ZEPHIR_CALL_METHOD(&_67$$37, this_ptr, "_handleexception", &_68, 0, &e);
					zephir_check_call_status();
					_69$$37 = ZEPHIR_IS_FALSE_IDENTICAL(&_67$$37);
					if (!(_69$$37)) {
						zephir_read_property(&_70$$37, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_69$$37 = ZEPHIR_IS_FALSE_IDENTICAL(&_70$$37);
					}
					if (_69$$37) {
						ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_71, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 608 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&wasFresh)) {
			if ((zephir_method_exists_ex(&handler, SL("initialize") TSRMLS_CC) == SUCCESS)) {

				/* try_start_5: */

					if (1) {
						zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$false);
					}
					ZEPHIR_CALL_METHOD(NULL, &handler, "initialize", NULL, 0);
					zephir_check_call_status_or_jump(try_end_5);

				try_end_5:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_72$$40);
					ZVAL_OBJ(&_72$$40, EG(exception));
					Z_ADDREF_P(&_72$$40);
					if (zephir_instance_of_ev(&_72$$40, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&e, &_72$$40);
						if (0) {
							zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$true);
						} else {
							zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$false);
						}
						ZEPHIR_CALL_METHOD(&_73$$42, this_ptr, "_handleexception", &_74, 0, &e);
						zephir_check_call_status();
						_75$$42 = ZEPHIR_IS_FALSE_IDENTICAL(&_73$$42);
						if (!(_75$$42)) {
							zephir_read_property(&_76$$42, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
							_75$$42 = ZEPHIR_IS_FALSE_IDENTICAL(&_76$$42);
						}
						if (_75$$42) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 641 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			if (0) {
				zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$false);
			}
			if (zephir_is_true(&eventsManager)) {

				/* try_start_6: */

					ZEPHIR_INIT_NVAR(&_78$$45);
					ZVAL_STRING(&_78$$45, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD(&_77$$45, &eventsManager, "fire", &_79, 0, &_78$$45, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_80$$45 = ZEPHIR_IS_FALSE_IDENTICAL(&_77$$45);
					if (!(_80$$45)) {
						zephir_read_property(&_81$$45, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_80$$45 = ZEPHIR_IS_FALSE_IDENTICAL(&_81$$45);
					}
					if (_80$$45) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_82$$44);
					ZVAL_OBJ(&_82$$44, EG(exception));
					Z_ADDREF_P(&_82$$44);
					if (zephir_instance_of_ev(&_82$$44, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&e, &_82$$44);
						ZEPHIR_CALL_METHOD(&_83$$47, this_ptr, "_handleexception", &_84, 0, &e);
						zephir_check_call_status();
						_85$$47 = ZEPHIR_IS_FALSE_IDENTICAL(&_83$$47);
						if (!(_85$$47)) {
							zephir_read_property(&_86$$47, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
							_85$$47 = ZEPHIR_IS_FALSE_IDENTICAL(&_86$$47);
						}
						if (_85$$47) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 658 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property(&_87$$10, this_ptr, SL("_modelBinding"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_87$$10)) {
			ZEPHIR_OBS_NVAR(&modelBinder);
			zephir_read_property(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			ZEPHIR_CALL_METHOD(&_88$$49, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&params, &_88$$49);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_90$$50);
			ZVAL_STRING(&_90$$50, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD(&_89$$50, &eventsManager, "fire", &_91, 0, &_90$$50, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_89$$50)) {
				continue;
			}
			zephir_read_property(&_92$$50, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_92$$50)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(&handler, SL("afterbinding") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_93$$53, &handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_93$$53)) {
				continue;
			}
			zephir_read_property(&_94$$53, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_94$$53)) {
				continue;
			}
		}
		zephir_update_property_zval(this_ptr, SL("_lastHandler"), &handler);

		/* try_start_7: */

			ZEPHIR_CALL_METHOD(&_95$$56, this_ptr, "callactionmethod", &_96, 0, &handler, &actionMethod, &params);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval(this_ptr, SL("_returnedValue"), &_95$$56);
			zephir_read_property(&_97$$56, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_97$$56)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_98$$10);
			ZVAL_OBJ(&_98$$10, EG(exception));
			Z_ADDREF_P(&_98$$10);
			if (zephir_instance_of_ev(&_98$$10, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_98$$10);
				ZEPHIR_CALL_METHOD(&_99$$58, this_ptr, "_handleexception", &_100, 0, &e);
				zephir_check_call_status();
				_101$$58 = ZEPHIR_IS_FALSE_IDENTICAL(&_99$$58);
				if (!(_101$$58)) {
					zephir_read_property(&_102$$58, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_101$$58 = ZEPHIR_IS_FALSE_IDENTICAL(&_102$$58);
				}
				if (_101$$58) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 708 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_104$$61);
				ZVAL_STRING(&_104$$61, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(&_103$$61, &eventsManager, "fire", &_105, 0, &_104$$61, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_106$$61 = ZEPHIR_IS_FALSE_IDENTICAL(&_103$$61);
				if (!(_106$$61)) {
					zephir_read_property(&_107$$61, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_106$$61 = ZEPHIR_IS_FALSE_IDENTICAL(&_107$$61);
				}
				if (_106$$61) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_108$$60);
				ZVAL_OBJ(&_108$$60, EG(exception));
				Z_ADDREF_P(&_108$$60);
				if (zephir_instance_of_ev(&_108$$60, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_108$$60);
					ZEPHIR_CALL_METHOD(&_109$$63, this_ptr, "_handleexception", &_110, 0, &e);
					zephir_check_call_status();
					_111$$63 = ZEPHIR_IS_FALSE_IDENTICAL(&_109$$63);
					if (!(_111$$63)) {
						zephir_read_property(&_112$$63, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_111$$63 = ZEPHIR_IS_FALSE_IDENTICAL(&_112$$63);
					}
					if (_111$$63) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 722 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, SL("afterexecuteroute") TSRMLS_CC) == SUCCESS)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_113$$66, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_114$$66 = ZEPHIR_IS_FALSE_IDENTICAL(&_113$$66);
				if (!(_114$$66)) {
					zephir_read_property(&_115$$66, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_114$$66 = ZEPHIR_IS_FALSE_IDENTICAL(&_115$$66);
				}
				if (_114$$66) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_116$$65);
				ZVAL_OBJ(&_116$$65, EG(exception));
				Z_ADDREF_P(&_116$$65);
				if (zephir_instance_of_ev(&_116$$65, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_116$$65);
					ZEPHIR_CALL_METHOD(&_117$$68, this_ptr, "_handleexception", &_118, 0, &e);
					zephir_check_call_status();
					_119$$68 = ZEPHIR_IS_FALSE_IDENTICAL(&_117$$68);
					if (!(_119$$68)) {
						zephir_read_property(&_120$$68, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_119$$68 = ZEPHIR_IS_FALSE_IDENTICAL(&_120$$68);
					}
					if (_119$$68) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 737 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_121$$71);
				ZVAL_STRING(&_121$$71, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_122, 0, &_121$$71, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_123$$70);
				ZVAL_OBJ(&_123$$70, EG(exception));
				Z_ADDREF_P(&_123$$70);
				if (zephir_instance_of_ev(&_123$$70, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_123$$70);
					ZEPHIR_CALL_METHOD(&_124$$72, this_ptr, "_handleexception", &_125, 0, &e);
					zephir_check_call_status();
					_126$$72 = ZEPHIR_IS_FALSE_IDENTICAL(&_124$$72);
					if (!(_126$$72)) {
						zephir_read_property(&_127$$72, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_126$$72 = ZEPHIR_IS_FALSE_IDENTICAL(&_127$$72);
					}
					if (_126$$72) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 751 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_128$$75);
			ZVAL_STRING(&_128$$75, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_128$$75, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_129$$74);
			ZVAL_OBJ(&_129$$74, EG(exception));
			Z_ADDREF_P(&_129$$74);
			if (zephir_instance_of_ev(&_129$$74, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_129$$74);
				ZEPHIR_CALL_METHOD(&_130$$76, this_ptr, "_handleexception", NULL, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_130$$76)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 768 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_CCTOR(&handler);

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

	zval *forward, forward_sub, __$true, __$false, namespaceName, controllerName, params, actionName, taskName, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&forward_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&taskName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	zephir_read_property(&_0, this_ptr, SL("_isControllerInitialize"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Forwarding inside a controller's initialize() method is forbidden", "phalcon/dispatcher.zep", 799);
		return;
	}
	if (Z_TYPE_P(forward) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Forward parameter must be an Array", "phalcon/dispatcher.zep", 807);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_namespaceName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_previousNamespaceName"), &_1);
	zephir_read_property(&_2, this_ptr, SL("_handlerName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_previousHandlerName"), &_2);
	zephir_read_property(&_3, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_previousActionName"), &_3);
	if (zephir_array_isset_string_fetch(&namespaceName, forward, SL("namespace"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_namespaceName"), &namespaceName);
	}
	ZEPHIR_OBS_VAR(&taskName);
	if (zephir_array_isset_string_fetch(&controllerName, forward, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_handlerName"), &controllerName);
	} else if (zephir_array_isset_string_fetch(&taskName, forward, SL("task"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_handlerName"), &taskName);
	}
	if (zephir_array_isset_string_fetch(&actionName, forward, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_actionName"), &actionName);
	}
	if (zephir_array_isset_string_fetch(&params, forward, SL("params"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_params"), &params);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_forwarded"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_forwarded"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if the current executed action was forwarded by another one
 */
PHP_METHOD(Phalcon_Dispatcher, wasForwarded) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_forwarded");

}

/**
 * Possible class name that will be located to dispatch the request
 */
PHP_METHOD(Phalcon_Dispatcher, getHandlerClass) {

	zval handlerSuffix, handlerName, namespaceName, camelizedClass, handlerClass;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerSuffix);
	ZVAL_UNDEF(&handlerName);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&camelizedClass);
	ZVAL_UNDEF(&handlerClass);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&handlerSuffix);
	zephir_read_property(&handlerSuffix, this_ptr, SL("_handlerSuffix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&handlerName);
	zephir_read_property(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&namespaceName);
	zephir_read_property(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/dispatcher.zep", 864))) {
		ZEPHIR_INIT_VAR(&camelizedClass);
		zephir_camelize(&camelizedClass, &handlerName, NULL  );
	} else {
		ZEPHIR_CPY_WRT(&camelizedClass, &handlerName);
	}
	if (zephir_is_true(&namespaceName)) {
		ZEPHIR_INIT_VAR(&handlerClass);
		if (zephir_end_with_str(&namespaceName, SL("\\"))) {
			ZEPHIR_CONCAT_VVV(&handlerClass, &namespaceName, &camelizedClass, &handlerSuffix);
		} else {
			ZEPHIR_CONCAT_VSVV(&handlerClass, &namespaceName, "\\", &camelizedClass, &handlerSuffix);
		}
	} else {
		ZEPHIR_INIT_NVAR(&handlerClass);
		ZEPHIR_CONCAT_VV(&handlerClass, &camelizedClass, &handlerSuffix);
	}
	RETURN_CCTOR(&handlerClass);

}

PHP_METHOD(Phalcon_Dispatcher, callActionMethod) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _0;
	zval actionMethod;
	zval *handler, handler_sub, *actionMethod_param = NULL, *params_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &handler, &actionMethod_param, &params_param);

	zephir_get_strval(&actionMethod, actionMethod_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, handler);
	zephir_array_fast_append(&_0, &actionMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &params);
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

	zval modelBinder;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&modelBinder);
	zephir_read_property(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
	if (Z_TYPE_P(&modelBinder) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(&modelBinder, "getboundmodels", NULL, 0);
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

	zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);


	zephir_read_property(&_0, this_ptr, SL("_namespaceName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_namespaceName"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("_handlerName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_3$$4, this_ptr, SL("_defaultHandler"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_handlerName"), &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_4))) {
		zephir_read_property(&_5$$5, this_ptr, SL("_defaultAction"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_actionName"), &_5$$5);
	}

}

zend_object *zephir_init_properties_Phalcon_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_params"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

