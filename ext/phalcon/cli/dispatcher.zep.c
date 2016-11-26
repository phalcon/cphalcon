
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Cli\Dispatcher
 *
 * Dispatching is the process of taking the command-line arguments, extracting the module name,
 * task name, action name, and optional parameters contained in it, and then
 * instantiating a task and calling an action on it.
 *
 *<code>
 * $di = new \Phalcon\Di();
 *
 * $dispatcher = new \Phalcon\Cli\Dispatcher();
 *
 * $dispatcher->setDi($di);
 *
 * $dispatcher->setTaskName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $handle = $dispatcher->dispatch();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Dispatcher, phalcon, cli_dispatcher, phalcon_dispatcher_ce, phalcon_cli_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_handlerSuffix"), "Task", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_defaultHandler"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_defaultAction"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_dispatcher_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_cli_dispatcher_ce->create_object = zephir_init_properties_Phalcon_Cli_Dispatcher;

	zend_class_implements(phalcon_cli_dispatcher_ce TSRMLS_CC, 1, phalcon_cli_dispatcherinterface_ce);
	return SUCCESS;

}

/**
 * Sets the default task suffix
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskSuffix) {

	zval *taskSuffix_param = NULL;
	zval taskSuffix;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&taskSuffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskSuffix_param);

	zephir_get_strval(&taskSuffix, taskSuffix_param);


	zephir_update_property_zval(this_ptr, SL("_handlerSuffix"), &taskSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default task name
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setDefaultTask) {

	zval *taskName_param = NULL;
	zval taskName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&taskName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);

	zephir_get_strval(&taskName, taskName_param);


	zephir_update_property_zval(this_ptr, SL("_defaultHandler"), &taskName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the task name to be dispatched
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskName) {

	zval *taskName_param = NULL;
	zval taskName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&taskName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);

	zephir_get_strval(&taskName, taskName_param);


	zephir_update_property_zval(this_ptr, SL("_handlerName"), &taskName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets last dispatched task name
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getTaskName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_handlerName");

}

/**
 * Throws an internal exception
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, _throwDispatchException) {

	int exceptionCode, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *exceptionCode_param = NULL, exception, _0, _1;
	zval message;
	ZEPHIR_INIT_THIS();

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
	ZEPHIR_CALL_METHOD(NULL, &exception, "__construct", NULL, 9, &message, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_handleexception", NULL, 0, &exception);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		RETURN_MM_BOOL(0);
	}
	zephir_throw_exception_debug(&exception, "phalcon/cli/dispatcher.zep", 103 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Handles a user exception
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, _handleException) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, eventsManager, _0, _1$$3, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	zephir_read_property(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
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
 * Returns the latest dispatched controller
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getLastTask) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_lastHandler");

}

/**
 * Returns the active task in the dispatcher
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getActiveTask) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_activeHandler");

}

/**
 * Set the options to be dispatched
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setOptions) {

	zval *options_param = NULL;
	zval options;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get dispatched options
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getOptions) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_options");

}

PHP_METHOD(Phalcon_Cli_Dispatcher, callActionMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval params, _0, _1;
	zval actionMethod;
	zval *handler, handler_sub, *actionMethod_param = NULL, *params_param = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &params);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Cli_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

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
		zephir_read_property(&_2, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_options"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

