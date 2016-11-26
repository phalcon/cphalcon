
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
#include "kernel/hash.h"
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
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, getDI) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Dispatcher, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Dispatcher, getEventsManager) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher, setActionSuffix) {

	zval *actionSuffix_param = NULL;
	zval actionSuffix;
	ZEPHIR_INIT_THIS();

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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_actionSuffix");

}

/**
 * Sets the module where the controller is (only informative)
 */
PHP_METHOD(Phalcon_Dispatcher, setModuleName) {

	zval *moduleName_param = NULL;
	zval moduleName;
	ZEPHIR_INIT_THIS();

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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_moduleName");

}

/**
 * Sets the namespace where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName) {

	zval *namespaceName_param = NULL;
	zval namespaceName;
	ZEPHIR_INIT_THIS();

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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_namespaceName");

}

/**
 * Sets the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace) {

	zval *namespaceName_param = NULL;
	zval namespaceName;
	ZEPHIR_INIT_THIS();

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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_defaultNamespace");

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction) {

	zval *actionName_param = NULL;
	zval actionName;
	ZEPHIR_INIT_THIS();

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
	ZEPHIR_INIT_THIS();

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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_actionName");

}

/**
 * Sets action params to be dispatched
 *
 * @param array params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params, params_sub, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);



	if (Z_TYPE_P(params) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Parameters must be an Array");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, SL("_params"), params);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets action params
 */
PHP_METHOD(Phalcon_Dispatcher, getParams) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_params");

}

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed param
 * @param  mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setParam) {

	zval *param, param_sub, *value, value_sub;
	ZEPHIR_INIT_THIS();

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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null, params, filter, paramValue, dependencyInjector, _2, _3, _0$$5, _1$$5;
	ZEPHIR_INIT_THIS();

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
		RETURN_CCTOR(paramValue);
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
	ZEPHIR_INIT_THIS();

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
	ZEPHIR_INIT_THIS();

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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_finished");

}

/**
 * Sets the latest returned value by an action manually
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setReturnedValue) {

	zval *value, value_sub;
	ZEPHIR_INIT_THIS();

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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_returnedValue");

}

/**
 * Enable/Disable model binding during dispatch
 *
 * @param boolean value
 */
PHP_METHOD(Phalcon_Dispatcher, setModelBinding) {

	zval *value_param = NULL, __$true, __$false;
	zend_bool value;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &value_param);

	value = zephir_get_boolval(value_param);


	if (value) {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$false);
	}

}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch) {

	zval handler, e, _0$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&handler, this_ptr, "_dispatch", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZVAL_OBJ(&e, EG(exception));
		Z_ADDREF_P(&e);
		if (zephir_instance_of_ev(&e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "_handleexception", NULL, 0, &e);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$4)) {
				RETURN_MM_BOOL(0);
			}
			zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 348 TSRMLS_CC);
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

	zend_string *_54$$39;
	zend_ulong _53$$39;
	zval _30$$6, _60$$44, _62$$44, _63$$44, _68$$45, _70$$45;
	zend_bool hasService = 0, wasFresh;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_9 = NULL, *_12 = NULL, *_15 = NULL, *_18 = NULL, *_20 = NULL, *_21 = NULL, *_24 = NULL, *_28 = NULL, *_33 = NULL, *_37 = NULL, *_41 = NULL, *_47 = NULL, *_50 = NULL, *_51 = NULL, *_58 = NULL, *_67 = NULL, *_73 = NULL, *_75 = NULL, *_79 = NULL, *_81 = NULL;
	zval __$true, __$false, value, handler, dependencyInjector, namespaceName, handlerName, actionName, params, eventsManager, actionSuffix, handlerClass, status, actionMethod, reflectionMethod, methodParams, className, paramKey, methodParam, modelName, bindModel, e, _0, _1$$3, _2$$3, _3$$4, _4$$4, _5$$7, _6$$7, _10$$8, _11$$8, _13$$8, _14$$6, _49$$6, _16$$12, _17$$12, _19$$13, _22$$16, _23$$16, _25$$17, _26$$19, _27$$19, _29$$20, _31$$23, _32$$23, _34$$23, _35$$22, _36$$22, _38$$26, _39$$28, _40$$28, _42$$28, _43$$31, _44$$31, _45$$36, _46$$36, _48$$36, *_52$$39, _55$$40, _56$$41, _57$$43, _59$$43, _61$$44, _64$$44, _65$$42, _66$$42, _69$$45, _71$$45, _72$$46, _74$$47, _76$$48, _77$$51, _78$$51, _80$$51, _82$$54, _83$$54, _84$$57;
	int ZEPHIR_LAST_CALL_STATUS, numberDispatches = 0;
	ZEPHIR_INIT_THIS();

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
	ZVAL_UNDEF(&reflectionMethod);
	ZVAL_UNDEF(&methodParams);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&paramKey);
	ZVAL_UNDEF(&methodParam);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&bindModel);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_49$$6);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_42$$28);
	ZVAL_UNDEF(&_43$$31);
	ZVAL_UNDEF(&_44$$31);
	ZVAL_UNDEF(&_45$$36);
	ZVAL_UNDEF(&_46$$36);
	ZVAL_UNDEF(&_48$$36);
	ZVAL_UNDEF(&_55$$40);
	ZVAL_UNDEF(&_56$$41);
	ZVAL_UNDEF(&_57$$43);
	ZVAL_UNDEF(&_59$$43);
	ZVAL_UNDEF(&_61$$44);
	ZVAL_UNDEF(&_64$$44);
	ZVAL_UNDEF(&_65$$42);
	ZVAL_UNDEF(&_66$$42);
	ZVAL_UNDEF(&_69$$45);
	ZVAL_UNDEF(&_71$$45);
	ZVAL_UNDEF(&_72$$46);
	ZVAL_UNDEF(&_74$$47);
	ZVAL_UNDEF(&_76$$48);
	ZVAL_UNDEF(&_77$$51);
	ZVAL_UNDEF(&_78$$51);
	ZVAL_UNDEF(&_80$$51);
	ZVAL_UNDEF(&_82$$54);
	ZVAL_UNDEF(&_83$$54);
	ZVAL_UNDEF(&_84$$57);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_60$$44);
	ZVAL_UNDEF(&_62$$44);
	ZVAL_UNDEF(&_63$$44);
	ZVAL_UNDEF(&_68$$45);
	ZVAL_UNDEF(&_70$$45);

	ZEPHIR_MM_GROW();

	wasFresh = 0;
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
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "dispatch:beforeDispatchLoop");
		ZEPHIR_CALL_METHOD(&_3$$4, &eventsManager, "fire", NULL, 0, &_4$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$4)) {
			RETURN_MM_BOOL(0);
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
			ZEPHIR_INIT_NVAR(&_5$$7);
			ZVAL_STRING(&_5$$7, "Dispatcher has detected a cyclic routing causing stability problems");
			ZVAL_LONG(&_6$$7, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", &_7, 0, &_5$$7, &_6$$7);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", &_8, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&namespaceName);
		zephir_read_property(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&handlerName);
		zephir_read_property(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, SL("_actionName"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_9, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_11$$8);
			ZVAL_STRING(&_11$$8, "dispatch:beforeDispatch");
			ZEPHIR_CALL_METHOD(&_10$$8, &eventsManager, "fire", &_12, 0, &_11$$8, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$8)) {
				continue;
			}
			zephir_read_property(&_13$$8, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$8)) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&_14$$6, &dependencyInjector, "has", &_15, 0, &handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(&_14$$6);
		if (!(hasService)) {
			hasService = zephir_class_exists(&handlerClass, 1 TSRMLS_CC);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_LNVAR(_16$$12);
			ZEPHIR_CONCAT_VS(&_16$$12, &handlerClass, " handler class cannot be loaded");
			ZVAL_LONG(&_17$$12, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_18, 0, &_16$$12, &_17$$12);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
				zephir_read_property(&_19$$13, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_19$$13)) {
					continue;
				}
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, &dependencyInjector, "getshared", &_20, 0, &handlerClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_14$$6, &dependencyInjector, "wasfreshinstance", &_21, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_14$$6)) {
			wasFresh = 1;
		}
		if (Z_TYPE_P(&handler) != IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_22$$16);
			ZVAL_STRING(&_22$$16, "Invalid handler returned from the services container");
			ZVAL_LONG(&_23$$16, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_24, 0, &_22$$16, &_23$$16);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
				zephir_read_property(&_25$$17, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_25$$17)) {
					continue;
				}
			}
			break;
		}
		zephir_update_property_zval(this_ptr, SL("_activeHandler"), &handler);
		ZEPHIR_OBS_NVAR(&params);
		zephir_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_26$$19);
			ZVAL_STRING(&_26$$19, "Action parameters must be an Array");
			ZVAL_LONG(&_27$$19, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_28, 0, &_26$$19, &_27$$19);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
				zephir_read_property(&_29$$20, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_29$$20)) {
					continue;
				}
			}
			break;
		}
		ZEPHIR_INIT_NVAR(&actionMethod);
		ZEPHIR_CONCAT_VV(&actionMethod, &actionName, &actionSuffix);
		ZEPHIR_INIT_NVAR(&_30$$6);
		zephir_create_array(&_30$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_30$$6, &handler);
		zephir_array_fast_append(&_30$$6, &actionMethod);
		if (!(zephir_is_callable(&_30$$6 TSRMLS_CC))) {
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_32$$23);
				ZVAL_STRING(&_32$$23, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD(&_31$$23, &eventsManager, "fire", &_33, 0, &_32$$23, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_31$$23)) {
					continue;
				}
				zephir_read_property(&_34$$23, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_34$$23)) {
					continue;
				}
			}
			ZEPHIR_INIT_LNVAR(_35$$22);
			ZEPHIR_CONCAT_SVSVS(&_35$$22, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_36$$22, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_37, 0, &_35$$22, &_36$$22);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
				zephir_read_property(&_38$$26, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_38$$26)) {
					continue;
				}
			}
			break;
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_40$$28);
			ZVAL_STRING(&_40$$28, "dispatch:beforeExecuteRoute");
			ZEPHIR_CALL_METHOD(&_39$$28, &eventsManager, "fire", &_41, 0, &_40$$28, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_39$$28)) {
				continue;
			}
			zephir_read_property(&_42$$28, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_42$$28)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(&handler, SL("beforeexecuteroute") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_43$$31, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_43$$31)) {
				continue;
			}
			zephir_read_property(&_44$$31, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_44$$31)) {
				continue;
			}
		}
		if (wasFresh == 1) {
			if ((zephir_method_exists_ex(&handler, SL("initialize") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(NULL, &handler, "initialize", NULL, 0);
				zephir_check_call_status();
			}
			if (zephir_is_true(&eventsManager)) {
				ZEPHIR_INIT_NVAR(&_46$$36);
				ZVAL_STRING(&_46$$36, "dispatch:afterInitialize");
				ZEPHIR_CALL_METHOD(&_45$$36, &eventsManager, "fire", &_47, 0, &_46$$36, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_45$$36)) {
					continue;
				}
				zephir_read_property(&_48$$36, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_48$$36)) {
					continue;
				}
			}
		}
		zephir_read_property(&_49$$6, this_ptr, SL("_modelBinding"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_49$$6)) {
			ZEPHIR_INIT_NVAR(&reflectionMethod);
			object_init_ex(&reflectionMethod, zephir_get_internal_ce(SL("reflectionmethod")));
			ZEPHIR_CALL_METHOD(NULL, &reflectionMethod, "__construct", &_50, 69, &handlerClass, &actionMethod);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&methodParams, &reflectionMethod, "getparameters", &_51, 70);
			zephir_check_call_status();
			zephir_is_iterable(&methodParams, 0, "phalcon/dispatcher.zep", 582);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodParams), _53$$39, _54$$39, _52$$39)
			{
				ZEPHIR_INIT_NVAR(&paramKey);
				if (_54$$39 != NULL) { 
					ZVAL_STR_COPY(&paramKey, _54$$39);
				} else {
					ZVAL_LONG(&paramKey, _53$$39);
				}
				ZEPHIR_INIT_NVAR(&methodParam);
				ZVAL_COPY(&methodParam, _52$$39);
				ZEPHIR_CALL_METHOD(&_55$$40, &methodParam, "getclass", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_55$$40)) {
					ZEPHIR_CALL_METHOD(&_56$$41, &methodParam, "getclass", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&className, &_56$$41, "getname", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&className) == IS_STRING) {
						if (ZEPHIR_IS_STRING(&className, "Phalcon\\Mvc\\Model")) {
							ZEPHIR_CALL_FUNCTION(&_57$$43, "class_implements", &_58, 71, &handlerClass);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_59$$43);
							ZVAL_STRING(&_59$$43, "Phalcon\\Mvc\\Controller\\BindModelInterface");
							if (zephir_fast_in_array(&_59$$43, &_57$$43 TSRMLS_CC)) {
								ZEPHIR_INIT_NVAR(&_60$$44);
								zephir_create_array(&_60$$44, 2, 0 TSRMLS_CC);
								zephir_array_fast_append(&_60$$44, &handlerClass);
								ZEPHIR_INIT_NVAR(&_61$$44);
								ZVAL_STRING(&_61$$44, "getModelName");
								zephir_array_fast_append(&_60$$44, &_61$$44);
								ZEPHIR_INIT_NVAR(&modelName);
								ZEPHIR_CALL_USER_FUNC(&modelName, &_60$$44);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_62$$44);
								zephir_create_array(&_62$$44, 2, 0 TSRMLS_CC);
								zephir_array_fast_append(&_62$$44, &modelName);
								ZEPHIR_INIT_NVAR(&_61$$44);
								ZVAL_STRING(&_61$$44, "findFirst");
								zephir_array_fast_append(&_62$$44, &_61$$44);
								ZEPHIR_INIT_NVAR(&_63$$44);
								zephir_create_array(&_63$$44, 1, 0 TSRMLS_CC);
								ZEPHIR_OBS_NVAR(&_64$$44);
								zephir_array_fetch(&_64$$44, &params, &paramKey, PH_NOISY, "phalcon/dispatcher.zep", 567 TSRMLS_CC);
								zephir_array_fast_append(&_63$$44, &_64$$44);
								ZEPHIR_INIT_NVAR(&bindModel);
								ZEPHIR_CALL_USER_FUNC_ARRAY(&bindModel, &_62$$44, &_63$$44);
								zephir_check_call_status();
								zephir_array_update_zval(&params, &paramKey, &bindModel, PH_COPY | PH_SEPARATE);
								break;
							}
						}
						ZEPHIR_INIT_NVAR(&_65$$42);
						ZVAL_STRING(&_65$$42, "Phalcon\\Mvc\\Model");
						ZEPHIR_CALL_FUNCTION(&_66$$42, "is_subclass_of", &_67, 72, &className, &_65$$42);
						zephir_check_call_status();
						if (zephir_is_true(&_66$$42)) {
							ZEPHIR_INIT_NVAR(&_68$$45);
							zephir_create_array(&_68$$45, 2, 0 TSRMLS_CC);
							zephir_array_fast_append(&_68$$45, &className);
							ZEPHIR_INIT_NVAR(&_69$$45);
							ZVAL_STRING(&_69$$45, "findFirst");
							zephir_array_fast_append(&_68$$45, &_69$$45);
							ZEPHIR_INIT_NVAR(&_70$$45);
							zephir_create_array(&_70$$45, 1, 0 TSRMLS_CC);
							ZEPHIR_OBS_NVAR(&_71$$45);
							zephir_array_fetch(&_71$$45, &params, &paramKey, PH_NOISY, "phalcon/dispatcher.zep", 575 TSRMLS_CC);
							zephir_array_fast_append(&_70$$45, &_71$$45);
							ZEPHIR_INIT_NVAR(&bindModel);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&bindModel, &_68$$45, &_70$$45);
							zephir_check_call_status();
							zephir_array_update_zval(&params, &paramKey, &bindModel, PH_COPY | PH_SEPARATE);
							break;
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&methodParam);
			ZEPHIR_INIT_NVAR(&paramKey);
		}
		zephir_update_property_zval(this_ptr, SL("_lastHandler"), &handler);

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&_72$$46, this_ptr, "callactionmethod", &_73, 0, &handler, &actionMethod, &params);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_zval(this_ptr, SL("_returnedValue"), &_72$$46);

		try_end_1:

		if (EG(exception)) {
			ZVAL_OBJ(&e, EG(exception));
			Z_ADDREF_P(&e);
			if (zephir_instance_of_ev(&e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(&_74$$47, this_ptr, "_handleexception", &_75, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_74$$47)) {
					zephir_read_property(&_76$$48, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_76$$48)) {
						continue;
					}
				} else {
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 595 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_78$$51);
			ZVAL_STRING(&_78$$51, "dispatch:afterExecuteRoute");
			ZEPHIR_CALL_METHOD(&_77$$51, &eventsManager, "fire", &_79, 0, &_78$$51, this_ptr, &value);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_77$$51)) {
				continue;
			}
			zephir_read_property(&_80$$51, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_80$$51)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_78$$51);
			ZVAL_STRING(&_78$$51, "dispatch:afterDispatch");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_81, 0, &_78$$51, this_ptr);
			zephir_check_call_status();
		}
		if ((zephir_method_exists_ex(&handler, SL("afterexecuteroute") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_82$$54, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_82$$54)) {
				continue;
			}
			zephir_read_property(&_83$$54, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_83$$54)) {
				continue;
			}
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_84$$57);
		ZVAL_STRING(&_84$$57, "dispatch:afterDispatchLoop");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_84$$57, this_ptr);
		zephir_check_call_status();
	}
	RETURN_CCTOR(handler);

}

/**
 * Forwards the execution flow to another controller/action
 * Dispatchers are unique per module. Forwarding between modules is not allowed
 *
 *<code>
 * $this->dispatcher->forward(
 *     [
 *         "controller" => "posts",
 *         "action"     => "index",
 *     ]
 * );
 *</code>
 *
 * @param array forward
 */
PHP_METHOD(Phalcon_Dispatcher, forward) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *forward, forward_sub, __$true, __$false, namespaceName, controllerName, params, actionName, taskName, _0$$3, _1$$4, _2$$5, _3$$7, _4$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&forward_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&taskName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	if (Z_TYPE_P(forward) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Forward parameter must be an Array");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	if (zephir_array_isset_string_fetch(&namespaceName, forward, SL("namespace"), 1)) {
		zephir_read_property(&_1$$4, this_ptr, SL("_namespaceName"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_previousNamespaceName"), &_1$$4);
		zephir_update_property_zval(this_ptr, SL("_namespaceName"), &namespaceName);
	}
	if (zephir_array_isset_string_fetch(&controllerName, forward, SL("controller"), 1)) {
		zephir_read_property(&_2$$5, this_ptr, SL("_handlerName"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_previousHandlerName"), &_2$$5);
		zephir_update_property_zval(this_ptr, SL("_handlerName"), &controllerName);
	} else {
		if (zephir_array_isset_string_fetch(&taskName, forward, SL("task"), 1)) {
			zephir_read_property(&_3$$7, this_ptr, SL("_handlerName"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, SL("_previousHandlerName"), &_3$$7);
			zephir_update_property_zval(this_ptr, SL("_handlerName"), &taskName);
		}
	}
	if (zephir_array_isset_string_fetch(&actionName, forward, SL("action"), 1)) {
		zephir_read_property(&_4$$8, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_previousActionName"), &_4$$8);
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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_forwarded");

}

/**
 * Possible class name that will be located to dispatch the request
 */
PHP_METHOD(Phalcon_Dispatcher, getHandlerClass) {

	zval handlerSuffix, handlerName, namespaceName, camelizedClass, handlerClass;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

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
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/dispatcher.zep", 714))) {
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
	RETURN_CCTOR(handlerClass);

}

PHP_METHOD(Phalcon_Dispatcher, callActionMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval params, _0;
	zval actionMethod;
	zval *handler, handler_sub, *actionMethod_param = NULL, *params_param = NULL;
	ZEPHIR_INIT_THIS();

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
 * Set empty properties to their defaults (where defaults are available)
 */
PHP_METHOD(Phalcon_Dispatcher, _resolveEmptyProperties) {

	zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	ZEPHIR_INIT_THIS();

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

