
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Dispatching is the process of taking the command-line arguments, extracting
 * the module name, task name, action name, and optional parameters contained in
 * it, and then instantiating a task and calling an action on it.
 *
 * ```php
 * use Phalcon\Di;
 * use Phalcon\Cli\Dispatcher;
 *
 * $di = new Di();
 *
 * $dispatcher = new Dispatcher();
 *
 * $dispatcher->setDi($di);
 *
 * $dispatcher->setTaskName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $handle = $dispatcher->dispatch();
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Dispatcher, phalcon, cli_dispatcher, phalcon_dispatcher_abstractdispatcher_ce, phalcon_cli_dispatcher_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("defaultHandler"), "main", ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("defaultAction"), "main", ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("handlerSuffix"), "Task", ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_dispatcher_ce, SL("options"), ZEND_ACC_PROTECTED);

	phalcon_cli_dispatcher_ce->create_object = zephir_init_properties_Phalcon_Cli_Dispatcher;

	zend_class_implements(phalcon_cli_dispatcher_ce, 1, phalcon_cli_dispatcherinterface_ce);
	return SUCCESS;

}

/**
 * Calls the action method.
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, callActionMethod) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval actionMethod;
	zval *handler, handler_sub, *actionMethod_param = NULL, params, *params_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &handler, &actionMethod_param, &params_param);

	zephir_get_strval(&actionMethod, actionMethod_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "array_values", NULL, 11, &params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&params, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_1, &params, &_2);
	ZEPHIR_CPY_WRT(&params, &_1);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, handler);
	zephir_array_fast_append(&_3, &actionMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_3, &params);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the active task in the dispatcher
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getActiveTask) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeHandler");

}

/**
 * Returns the latest dispatched controller
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getLastTask) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "lastHandler");

}

/**
 * Gets an option by its name or numeric index
 *
 * @param  mixed $option
 * @param  string|array $filters
 * @param  mixed $defaultValue
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getOption) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *option, option_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null, options, filter, optionValue, container, _0, _5, _6, _1$$5, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &option, &filters, &defaultValue);

	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_OBS_VAR(&optionValue);
	if (!(zephir_array_isset_fetch(&optionValue, &options, option, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) == IS_NULL) {
		RETURN_CCTOR(&optionValue);
	}
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "the 'filter' service");
		ZEPHIR_CALL_CE_STATIC(&_1$$5, phalcon_cli_dispatcher_exception_ce, "containerservicenotfound", &_2, 0, &_3$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_1$$5, &_4$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "filter");
	ZEPHIR_CALL_METHOD(&_5, &container, "getshared", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filter, &_5);
	ZEPHIR_RETURN_CALL_METHOD(&filter, "sanitize", NULL, 0, &optionValue, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get dispatched options
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

}

/**
 * Gets last dispatched task name
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getTaskName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handlerName");

}

/**
 * Gets the default task suffix
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getTaskSuffix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handlerSuffix");

}

/**
 * Check if an option exists
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, hasOption) {

	zval *option, option_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &option);



	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, option));

}

/**
 * Sets the default task name
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setDefaultTask) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *taskName_param = NULL;
	zval taskName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&taskName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);

	zephir_get_strval(&taskName, taskName_param);


	zephir_update_property_zval(this_ptr, SL("defaultHandler"), &taskName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the options to be dispatched
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the task name to be dispatched
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *taskName_param = NULL;
	zval taskName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&taskName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);

	zephir_get_strval(&taskName, taskName_param);


	zephir_update_property_zval(this_ptr, SL("handlerName"), &taskName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default task suffix
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskSuffix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *taskSuffix_param = NULL;
	zval taskSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&taskSuffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskSuffix_param);

	zephir_get_strval(&taskSuffix, taskSuffix_param);


	zephir_update_property_zval(this_ptr, SL("handlerSuffix"), &taskSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles a user exception
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, handleException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, eventsManager, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "dispatch:beforeException");
		ZEPHIR_CALL_METHOD(&_1$$3, &eventsManager, "fire", NULL, 0, &_2$$3, this_ptr, exception);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Throws an internal exception
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, throwDispatchException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long exceptionCode, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *exceptionCode_param = NULL, exception, _0, _1;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &exceptionCode_param);

	zephir_get_strval(&message, message_param);
	if (!exceptionCode_param) {
		exceptionCode = 0;
	} else {
		exceptionCode = zephir_get_intval(exceptionCode_param);
	}


	ZEPHIR_INIT_VAR(&exception);
	object_init_ex(&exception, phalcon_cli_dispatcher_exception_ce);
	ZVAL_LONG(&_0, exceptionCode);
	ZEPHIR_CALL_METHOD(NULL, &exception, "__construct", NULL, 6, &message, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "handleexception", NULL, 0, &exception);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		RETURN_MM_BOOL(0);
	}
	zephir_throw_exception_debug(&exception, "/home/nikos/Work/niden/cphalcon/phalcon/Cli/Dispatcher.zep", 224);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object *zephir_init_properties_Phalcon_Cli_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("params"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("handlerHashes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("handlerHashes"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("camelCaseMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("camelCaseMap"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("activeMethodMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("activeMethodMap"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("options"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

