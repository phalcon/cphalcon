
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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


/**
 * Phalcon\CLI\Dispatcher initializer
 */
PHALCON_INIT_CLASS(Phalcon_CLI_Dispatcher){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\CLI, Dispatcher, cli_dispatcher, "phalcon\\dispatcher", phalcon_cli_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_handlerSuffix"), "Task", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_defaultHandler"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_defaultAction"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Sets the default task suffix
 *
 * @param string $taskSuffix
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskSuffix){

	zval *task_suffix;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &task_suffix) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_handlerSuffix"), task_suffix TSRMLS_CC);
	
}

/**
 * Sets the default task name
 *
 * @param string $taskName
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setDefaultTask){

	zval *task_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &task_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultHandler"), task_name TSRMLS_CC);
	
}

/**
 * Sets the task name to be dispatched
 *
 * @param string $taskName
 */
PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskName){

	zval *task_name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &task_name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_handlerName"), task_name TSRMLS_CC);
	
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
	zval *event_name, *status;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &exception_code) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!exception_code) {
		PHALCON_INIT_VAR(exception_code);
		ZVAL_LONG(exception_code, 0);
	}
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_cli_dispatcher_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(exception, "__construct", message, exception_code);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeException", 1);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, exception);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
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

