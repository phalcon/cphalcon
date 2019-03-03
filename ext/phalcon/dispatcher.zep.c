
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_activeMethodMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_camelCaseMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousNamespaceName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousHandlerName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousActionName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_modelBinding"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_modelBinder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_isControllerInitialize"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_handlerHashes"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Parameters must be an Array", "phalcon/dispatcher.zep", 230);
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
 */
PHP_METHOD(Phalcon_Dispatcher, setParam) {

	zval *param, param_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &param, &value);



	zephir_update_property_array(this_ptr, SL("_params"), param, value);

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

	zval activeMethodName, _0, _1, _5, _2$$3, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&activeMethodName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&activeMethodName);
	zephir_read_property(&_0, this_ptr, SL("_activeMethodMap"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&activeMethodName, &_0, &_1, 0 TSRMLS_CC))) {
		zephir_read_property(&_3$$3, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "tocamelcase", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&activeMethodName, "lcfirst", NULL, 53, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, SL("_actionName"), PH_NOISY_CC);
		zephir_update_property_array(this_ptr, SL("_activeMethodMap"), &_4$$3, &activeMethodName);
	}
	zephir_read_property(&_5, this_ptr, SL("_actionSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &activeMethodName, &_5);
	RETURN_MM();

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
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_returnedValue");

}

/**
 * Sets the default suffix for the handler
 */
PHP_METHOD(Phalcon_Dispatcher, setHandlerSuffix) {

	zval *handlerSuffix_param = NULL;
	zval handlerSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerSuffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handlerSuffix_param);

	zephir_get_strval(&handlerSuffix, handlerSuffix_param);


	zephir_update_property_zval(this_ptr, SL("_handlerSuffix"), &handlerSuffix);
	ZEPHIR_MM_RESTORE();

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
 * Gets the default handler suffix
 */
PHP_METHOD(Phalcon_Dispatcher, getHandlerSuffix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_handlerSuffix");

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

	zval _42$$10;
	zend_bool hasService = 0, hasEventsManager = 0, _5$$5, _16$$13, _21$$15, _29$$18, _34$$20, _40$$23, _50$$25, _54$$31, _60$$33, _64$$36, _70$$38, _76$$43, _81$$46, _86$$48, _102$$59, _107$$62, _112$$64, _115$$67, _120$$69, _127$$73;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_15 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_28 = NULL, *_30 = NULL, *_33 = NULL, *_35 = NULL, *_39 = NULL, *_41 = NULL, *_45 = NULL, *_49 = NULL, *_53 = NULL, *_56 = NULL, *_59 = NULL, *_62 = NULL, *_66 = NULL, *_69 = NULL, *_72 = NULL, *_75 = NULL, *_80 = NULL, *_85 = NULL, *_92 = NULL, *_97 = NULL, *_101 = NULL, *_106 = NULL, *_111 = NULL, *_119 = NULL, *_123 = NULL, *_126 = NULL;
	zval __$true, __$false, value, handler, dependencyInjector, namespaceName, handlerName, actionName, params, eventsManager, actionSuffix, handlerClass, status, actionMethod, modelBinder, bindCacheKey, isNewHandler, handlerHash, e, _0, _1$$3, _2$$3, _3$$5, _4$$5, _6$$5, _7$$4, _8$$7, _9$$11, _10$$11, _13$$13, _14$$13, _17$$13, _18$$12, _19$$15, _22$$15, _24$$10, _36$$10, _88$$10, _99$$10, _26$$18, _27$$18, _31$$20, _32$$20, _37$$23, _38$$23, _43$$26, _44$$26, _46$$26, _47$$25, _48$$25, _51$$31, _52$$31, _55$$31, _57$$30, _58$$33, _61$$33, _63$$36, _65$$36, _67$$35, _68$$38, _71$$38, _73$$41, _74$$43, _77$$43, _78$$46, _79$$46, _82$$46, _83$$45, _84$$48, _87$$48, _89$$50, _90$$51, _91$$51, _93$$51, _94$$54, _95$$54, _96$$57, _98$$57, _100$$59, _103$$59, _104$$62, _105$$62, _108$$62, _109$$61, _110$$64, _113$$64, _114$$67, _116$$67, _117$$66, _118$$69, _121$$69, _122$$72, _124$$71, _125$$73, _128$$73, _129$$76, _130$$75, _131$$77;
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
	ZVAL_UNDEF(&isNewHandler);
	ZVAL_UNDEF(&handlerHash);
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
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_88$$10);
	ZVAL_UNDEF(&_99$$10);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_43$$26);
	ZVAL_UNDEF(&_44$$26);
	ZVAL_UNDEF(&_46$$26);
	ZVAL_UNDEF(&_47$$25);
	ZVAL_UNDEF(&_48$$25);
	ZVAL_UNDEF(&_51$$31);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_57$$30);
	ZVAL_UNDEF(&_58$$33);
	ZVAL_UNDEF(&_61$$33);
	ZVAL_UNDEF(&_63$$36);
	ZVAL_UNDEF(&_65$$36);
	ZVAL_UNDEF(&_67$$35);
	ZVAL_UNDEF(&_68$$38);
	ZVAL_UNDEF(&_71$$38);
	ZVAL_UNDEF(&_73$$41);
	ZVAL_UNDEF(&_74$$43);
	ZVAL_UNDEF(&_77$$43);
	ZVAL_UNDEF(&_78$$46);
	ZVAL_UNDEF(&_79$$46);
	ZVAL_UNDEF(&_82$$46);
	ZVAL_UNDEF(&_83$$45);
	ZVAL_UNDEF(&_84$$48);
	ZVAL_UNDEF(&_87$$48);
	ZVAL_UNDEF(&_89$$50);
	ZVAL_UNDEF(&_90$$51);
	ZVAL_UNDEF(&_91$$51);
	ZVAL_UNDEF(&_93$$51);
	ZVAL_UNDEF(&_94$$54);
	ZVAL_UNDEF(&_95$$54);
	ZVAL_UNDEF(&_96$$57);
	ZVAL_UNDEF(&_98$$57);
	ZVAL_UNDEF(&_100$$59);
	ZVAL_UNDEF(&_103$$59);
	ZVAL_UNDEF(&_104$$62);
	ZVAL_UNDEF(&_105$$62);
	ZVAL_UNDEF(&_108$$62);
	ZVAL_UNDEF(&_109$$61);
	ZVAL_UNDEF(&_110$$64);
	ZVAL_UNDEF(&_113$$64);
	ZVAL_UNDEF(&_114$$67);
	ZVAL_UNDEF(&_116$$67);
	ZVAL_UNDEF(&_117$$66);
	ZVAL_UNDEF(&_118$$69);
	ZVAL_UNDEF(&_121$$69);
	ZVAL_UNDEF(&_122$$72);
	ZVAL_UNDEF(&_124$$71);
	ZVAL_UNDEF(&_125$$73);
	ZVAL_UNDEF(&_128$$73);
	ZVAL_UNDEF(&_129$$76);
	ZVAL_UNDEF(&_130$$75);
	ZVAL_UNDEF(&_131$$77);
	ZVAL_UNDEF(&_42$$10);

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
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 438 TSRMLS_CC);
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
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 474 TSRMLS_CC);
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
		if (Z_TYPE_P(&handler) != IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_31$$20);
			ZVAL_STRING(&_31$$20, "Invalid handler returned from the services container");
			ZVAL_LONG(&_32$$20, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_33, 0, &_31$$20, &_32$$20);
			zephir_check_call_status();
			_34$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_34$$20) {
				zephir_read_property(&_32$$20, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_34$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&_32$$20);
			}
			if (_34$$20) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_FUNCTION(&handlerHash, "spl_object_hash", &_35, 56, &handler);
		zephir_check_call_status();
		zephir_read_property(&_36$$10, this_ptr, SL("_handlerHashes"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_36$$10, &handlerHash)) {
			ZEPHIR_INIT_NVAR(&isNewHandler);
			ZVAL_BOOL(&isNewHandler, 0);
		} else {
			ZEPHIR_INIT_NVAR(&isNewHandler);
			ZVAL_BOOL(&isNewHandler, 1);
		}
		if (zephir_is_true(&isNewHandler)) {
			zephir_update_property_array(this_ptr, SL("_handlerHashes"), &handlerHash, &__$true);
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
			ZEPHIR_INIT_NVAR(&_37$$23);
			ZVAL_STRING(&_37$$23, "Action parameters must be an Array");
			ZVAL_LONG(&_38$$23, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_39, 0, &_37$$23, &_38$$23);
			zephir_check_call_status();
			_40$$23 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_40$$23) {
				zephir_read_property(&_38$$23, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_40$$23 = ZEPHIR_IS_FALSE_IDENTICAL(&_38$$23);
			}
			if (_40$$23) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_41, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_42$$10);
		zephir_create_array(&_42$$10, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_42$$10, &handler);
		zephir_array_fast_append(&_42$$10, &actionMethod);
		if (!(zephir_is_callable(&_42$$10 TSRMLS_CC))) {
			if (hasEventsManager) {
				ZEPHIR_INIT_NVAR(&_44$$26);
				ZVAL_STRING(&_44$$26, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD(&_43$$26, &eventsManager, "fire", &_45, 0, &_44$$26, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_43$$26)) {
					continue;
				}
				zephir_read_property(&_46$$26, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_46$$26)) {
					continue;
				}
			}
			ZEPHIR_INIT_LNVAR(_47$$25);
			ZEPHIR_CONCAT_SVSVS(&_47$$25, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_48$$25, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_49, 0, &_47$$25, &_48$$25);
			zephir_check_call_status();
			_50$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_50$$25) {
				zephir_read_property(&_48$$25, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_50$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&_48$$25);
			}
			if (_50$$25) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_52$$31);
				ZVAL_STRING(&_52$$31, "dispatch:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_51$$31, &eventsManager, "fire", &_53, 0, &_52$$31, this_ptr);
				zephir_check_call_status_or_jump(try_end_3);
				_54$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_51$$31);
				if (!(_54$$31)) {
					zephir_read_property(&_55$$31, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_54$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_55$$31);
				}
				if (_54$$31) {
					ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_56, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_57$$30);
				ZVAL_OBJ(&_57$$30, EG(exception));
				Z_ADDREF_P(&_57$$30);
				if (zephir_instance_of_ev(&_57$$30, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_57$$30);
					ZEPHIR_CALL_METHOD(&_58$$33, this_ptr, "_handleexception", &_59, 0, &e);
					zephir_check_call_status();
					_60$$33 = ZEPHIR_IS_FALSE_IDENTICAL(&_58$$33);
					if (!(_60$$33)) {
						zephir_read_property(&_61$$33, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_60$$33 = ZEPHIR_IS_FALSE_IDENTICAL(&_61$$33);
					}
					if (_60$$33) {
						ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_62, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 574 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, SL("beforeexecuteroute") TSRMLS_CC) == SUCCESS)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_63$$36, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_64$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_63$$36);
				if (!(_64$$36)) {
					zephir_read_property(&_65$$36, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_64$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_65$$36);
				}
				if (_64$$36) {
					ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_66, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_67$$35);
				ZVAL_OBJ(&_67$$35, EG(exception));
				Z_ADDREF_P(&_67$$35);
				if (zephir_instance_of_ev(&_67$$35, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_67$$35);
					ZEPHIR_CALL_METHOD(&_68$$38, this_ptr, "_handleexception", &_69, 0, &e);
					zephir_check_call_status();
					_70$$38 = ZEPHIR_IS_FALSE_IDENTICAL(&_68$$38);
					if (!(_70$$38)) {
						zephir_read_property(&_71$$38, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_70$$38 = ZEPHIR_IS_FALSE_IDENTICAL(&_71$$38);
					}
					if (_70$$38) {
						ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_72, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 591 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&isNewHandler)) {
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
					ZEPHIR_INIT_NVAR(&_73$$41);
					ZVAL_OBJ(&_73$$41, EG(exception));
					Z_ADDREF_P(&_73$$41);
					if (zephir_instance_of_ev(&_73$$41, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&e, &_73$$41);
						if (0) {
							zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$true);
						} else {
							zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$false);
						}
						ZEPHIR_CALL_METHOD(&_74$$43, this_ptr, "_handleexception", &_75, 0, &e);
						zephir_check_call_status();
						_76$$43 = ZEPHIR_IS_FALSE_IDENTICAL(&_74$$43);
						if (!(_76$$43)) {
							zephir_read_property(&_77$$43, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
							_76$$43 = ZEPHIR_IS_FALSE_IDENTICAL(&_77$$43);
						}
						if (_76$$43) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 624 TSRMLS_CC);
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

					ZEPHIR_INIT_NVAR(&_79$$46);
					ZVAL_STRING(&_79$$46, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD(&_78$$46, &eventsManager, "fire", &_80, 0, &_79$$46, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_81$$46 = ZEPHIR_IS_FALSE_IDENTICAL(&_78$$46);
					if (!(_81$$46)) {
						zephir_read_property(&_82$$46, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_81$$46 = ZEPHIR_IS_FALSE_IDENTICAL(&_82$$46);
					}
					if (_81$$46) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_83$$45);
					ZVAL_OBJ(&_83$$45, EG(exception));
					Z_ADDREF_P(&_83$$45);
					if (zephir_instance_of_ev(&_83$$45, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&e, &_83$$45);
						ZEPHIR_CALL_METHOD(&_84$$48, this_ptr, "_handleexception", &_85, 0, &e);
						zephir_check_call_status();
						_86$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_84$$48);
						if (!(_86$$48)) {
							zephir_read_property(&_87$$48, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
							_86$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_87$$48);
						}
						if (_86$$48) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 641 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property(&_88$$10, this_ptr, SL("_modelBinding"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_88$$10)) {
			ZEPHIR_OBS_NVAR(&modelBinder);
			zephir_read_property(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			ZEPHIR_CALL_METHOD(&_89$$50, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&params, &_89$$50);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_91$$51);
			ZVAL_STRING(&_91$$51, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD(&_90$$51, &eventsManager, "fire", &_92, 0, &_91$$51, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_90$$51)) {
				continue;
			}
			zephir_read_property(&_93$$51, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_93$$51)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(&handler, SL("afterbinding") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_94$$54, &handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_94$$54)) {
				continue;
			}
			zephir_read_property(&_95$$54, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_95$$54)) {
				continue;
			}
		}
		zephir_update_property_zval(this_ptr, SL("_lastHandler"), &handler);

		/* try_start_7: */

			ZEPHIR_CALL_METHOD(&_96$$57, this_ptr, "callactionmethod", &_97, 0, &handler, &actionMethod, &params);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval(this_ptr, SL("_returnedValue"), &_96$$57);
			zephir_read_property(&_98$$57, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_98$$57)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_99$$10);
			ZVAL_OBJ(&_99$$10, EG(exception));
			Z_ADDREF_P(&_99$$10);
			if (zephir_instance_of_ev(&_99$$10, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_99$$10);
				ZEPHIR_CALL_METHOD(&_100$$59, this_ptr, "_handleexception", &_101, 0, &e);
				zephir_check_call_status();
				_102$$59 = ZEPHIR_IS_FALSE_IDENTICAL(&_100$$59);
				if (!(_102$$59)) {
					zephir_read_property(&_103$$59, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_102$$59 = ZEPHIR_IS_FALSE_IDENTICAL(&_103$$59);
				}
				if (_102$$59) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 691 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_105$$62);
				ZVAL_STRING(&_105$$62, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(&_104$$62, &eventsManager, "fire", &_106, 0, &_105$$62, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_107$$62 = ZEPHIR_IS_FALSE_IDENTICAL(&_104$$62);
				if (!(_107$$62)) {
					zephir_read_property(&_108$$62, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_107$$62 = ZEPHIR_IS_FALSE_IDENTICAL(&_108$$62);
				}
				if (_107$$62) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_109$$61);
				ZVAL_OBJ(&_109$$61, EG(exception));
				Z_ADDREF_P(&_109$$61);
				if (zephir_instance_of_ev(&_109$$61, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_109$$61);
					ZEPHIR_CALL_METHOD(&_110$$64, this_ptr, "_handleexception", &_111, 0, &e);
					zephir_check_call_status();
					_112$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_110$$64);
					if (!(_112$$64)) {
						zephir_read_property(&_113$$64, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_112$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_113$$64);
					}
					if (_112$$64) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 705 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, SL("afterexecuteroute") TSRMLS_CC) == SUCCESS)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_114$$67, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_115$$67 = ZEPHIR_IS_FALSE_IDENTICAL(&_114$$67);
				if (!(_115$$67)) {
					zephir_read_property(&_116$$67, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_115$$67 = ZEPHIR_IS_FALSE_IDENTICAL(&_116$$67);
				}
				if (_115$$67) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_117$$66);
				ZVAL_OBJ(&_117$$66, EG(exception));
				Z_ADDREF_P(&_117$$66);
				if (zephir_instance_of_ev(&_117$$66, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_117$$66);
					ZEPHIR_CALL_METHOD(&_118$$69, this_ptr, "_handleexception", &_119, 0, &e);
					zephir_check_call_status();
					_120$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_118$$69);
					if (!(_120$$69)) {
						zephir_read_property(&_121$$69, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_120$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_121$$69);
					}
					if (_120$$69) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 720 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_122$$72);
				ZVAL_STRING(&_122$$72, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_123, 0, &_122$$72, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_124$$71);
				ZVAL_OBJ(&_124$$71, EG(exception));
				Z_ADDREF_P(&_124$$71);
				if (zephir_instance_of_ev(&_124$$71, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_124$$71);
					ZEPHIR_CALL_METHOD(&_125$$73, this_ptr, "_handleexception", &_126, 0, &e);
					zephir_check_call_status();
					_127$$73 = ZEPHIR_IS_FALSE_IDENTICAL(&_125$$73);
					if (!(_127$$73)) {
						zephir_read_property(&_128$$73, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_127$$73 = ZEPHIR_IS_FALSE_IDENTICAL(&_128$$73);
					}
					if (_127$$73) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 734 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_129$$76);
			ZVAL_STRING(&_129$$76, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_129$$76, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_130$$75);
			ZVAL_OBJ(&_130$$75, EG(exception));
			Z_ADDREF_P(&_130$$75);
			if (zephir_instance_of_ev(&_130$$75, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_130$$75);
				ZEPHIR_CALL_METHOD(&_131$$77, this_ptr, "_handleexception", NULL, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_131$$77)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 751 TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Forwarding inside a controller's initialize() method is forbidden", "phalcon/dispatcher.zep", 782);
		return;
	}
	if (Z_TYPE_P(forward) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Forward parameter must be an Array", "phalcon/dispatcher.zep", 790);
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
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/dispatcher.zep", 847))) {
		ZEPHIR_CALL_METHOD(&camelizedClass, this_ptr, "tocamelcase", NULL, 0, &handlerName);
		zephir_check_call_status();
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

PHP_METHOD(Phalcon_Dispatcher, toCamelCase) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, camelCaseInput, _0, _1$$3, _2$$3, _3$$3;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&camelCaseInput);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);

	zephir_get_strval(&input, input_param);


	ZEPHIR_OBS_VAR(&camelCaseInput);
	zephir_read_property(&_0, this_ptr, SL("_camelCaseMap"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&camelCaseInput, &_0, &input, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "/[_-]+/");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_split", NULL, 57, &_1$$3, &input);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ucfirst");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_map", NULL, 58, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&camelCaseInput);
		zephir_fast_join_str(&camelCaseInput, SL(""), &_3$$3 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_camelCaseMap"), &input, &camelCaseInput);
	}
	RETURN_CCTOR(&camelCaseInput);

}

zend_object *zephir_init_properties_Phalcon_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_handlerHashes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_handlerHashes"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_camelCaseMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_camelCaseMap"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_activeMethodMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_activeMethodMap"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_params"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

