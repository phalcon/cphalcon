
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

#include "cli/dispatcher.h"
#include "cli/dispatcher/exception.h"
#include "cli/../dispatcher.h"
#include "dispatcherinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

/**
 * Phalcon\CLI\Dispatcher
 *
 * Dispatching is the process of taking the command-line arguments, extracting the module name,
 * task name, action name, and optional parameters contained in it, and then
 * instantiating a task and calling an action on it.
 *
 *<code>
 *
 *	$di = new Phalcon\DI();
 *
 *	$dispatcher = new Phalcon\CLI\Dispatcher();
 *
 *  $dispatcher->setDI($di);
 *
 *	$dispatcher->setTaskName('posts');
 *	$dispatcher->setActionName('index');
 *	$dispatcher->setParams(array());
 *
 *	$handle = $dispatcher->dispatch();
 *
 *</code>
 */
zend_class_entry *phalcon_cli_dispatcher_ce;

PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskSuffix);
PHP_METHOD(Phalcon_CLI_Dispatcher, setDefaultTask);
PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskName);
PHP_METHOD(Phalcon_CLI_Dispatcher, getTaskName);
PHP_METHOD(Phalcon_CLI_Dispatcher, _throwDispatchException);
PHP_METHOD(Phalcon_CLI_Dispatcher, _handleException);
PHP_METHOD(Phalcon_CLI_Dispatcher, getTaskClass);
PHP_METHOD(Phalcon_CLI_Dispatcher, getLastTask);
PHP_METHOD(Phalcon_CLI_Dispatcher, getActiveTask);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settasksuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, taskSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settaskname, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cli_dispatcher_method_entry[] = {
	PHP_ME(Phalcon_CLI_Dispatcher, setTaskSuffix, arginfo_phalcon_cli_dispatcher_settasksuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, setDefaultTask, arginfo_phalcon_cli_dispatcher_setdefaulttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, setTaskName, arginfo_phalcon_cli_dispatcher_settaskname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, getTaskName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, _throwDispatchException, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_CLI_Dispatcher, _handleException, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_CLI_Dispatcher, getTaskClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, getLastTask, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Dispatcher, getActiveTask, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\CLI\Dispatcher initializer
 */
PHALCON_INIT_CLASS(Phalcon_CLI_Dispatcher){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\CLI, Dispatcher, cli_dispatcher, phalcon_dispatcher_ce, phalcon_cli_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_handlerSuffix"), "Task", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_defaultHandler"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_defaultAction"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cli_dispatcher_ce TSRMLS_CC, 1, phalcon_dispatcherinterface_ce);

	return SUCCESS;
}

/**
 * Sets the default task suffix
 *
 * @param string $taskSuffix
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskSuffix){

	zval *task_suffix;

	phalcon_fetch_params(0, 1, 0, &task_suffix);
	
	phalcon_update_property_this(this_ptr, SL("_handlerSuffix"), task_suffix TSRMLS_CC);
	
}

/**
 * Sets the default task name
 *
 * @param string $taskName
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setDefaultTask){

	zval *task_name;

	phalcon_fetch_params(0, 1, 0, &task_name);
	
	phalcon_update_property_this(this_ptr, SL("_defaultHandler"), task_name TSRMLS_CC);
	
}

/**
 * Sets the task name to be dispatched
 *
 * @param string $taskName
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskName){

	zval *task_name;

	phalcon_fetch_params(0, 1, 0, &task_name);
	
	phalcon_update_property_this(this_ptr, SL("_handlerName"), task_name TSRMLS_CC);
	
}

/**
 * Gets last dispatched task name
 *
 * @return string
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getTaskName){


	RETURN_MEMBER(this_ptr, "_handlerName");
}

/**
 * Throws an internal exception
 *
 * @param string $message
 * @param int $exceptionCode
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, _throwDispatchException){

	zval *message, *exception_code = NULL, *exception, *events_manager;
	zval *event_name, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &exception_code);
	
	if (!exception_code) {
		exception_code = PHALCON_GLOBAL(z_zero);
	}
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_cli_dispatcher_exception_ce);
	PHALCON_CALL_METHOD(NULL, exception, "__construct", message, exception_code);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeException", 1);
	
		PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, exception);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Throw the exception if it wasn't handled
	 */
	phalcon_throw_exception(exception TSRMLS_CC);
	RETURN_MM();
}

/**
 * Handles a user exception
 *
 * @param \Exception $exception
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, _handleException){

	zval *exception, *events_manager, *event_name;
	zval *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &exception);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeException", 1);
	
		PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, exception);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Possible task class name that will be located to dispatch the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getTaskClass){


	PHALCON_MM_GROW();

	PHALCON_RETURN_CALL_METHOD(this_ptr, "gethandlername");
	RETURN_MM();
}

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon\CLI\Task
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getLastTask){


	RETURN_MEMBER(this_ptr, "_lastHandler");
}

/**
 * Returns the active task in the dispatcher
 *
 * @return Phalcon\CLI\Task
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, getActiveTask){


	RETURN_MEMBER(this_ptr, "_activeHandler");
}

