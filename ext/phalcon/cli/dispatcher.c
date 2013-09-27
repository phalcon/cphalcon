
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
 * Phalcon\Cli\Dispatcher
 *
 * Dispatching is the process of taking the command-line arguments, extracting the module name,
 * task name, action name, and optional parameters contained in it, and then
 * instantiating a task and calling an action on it.
 *
 *<code>
 *
 *	$di = new Phalcon\Di();
 *
 *	$dispatcher = new Phalcon\Cli\Dispatcher();
 *
 *  $dispatcher->setDi(di);
 *
 *	$dispatcher->setTaskName('posts');
 *	$dispatcher->setActionName('index');
 *	$dispatcher->setParams(array());
 *
 *	$handle = dispatcher->dispatch();
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Dispatcher, phalcon, cli_dispatcher, phalcon_dispatcher_ce, phalcon_cli_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_handlerSuffix"), "Task", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_defaultHandler"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cli_dispatcher_ce, SL("_defaultAction"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the default task suffix
 *
 * @param string taskSuffix
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskSuffix) {

	zval *taskSuffix_param = NULL;
	zval *taskSuffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskSuffix_param);

		zephir_get_strval(taskSuffix, taskSuffix_param);


	zephir_update_property_this(this_ptr, SL("_handlerSuffix"), taskSuffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default task name
 *
 * @param string taskName
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setDefaultTask) {

	zval *taskName_param = NULL;
	zval *taskName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);

		zephir_get_strval(taskName, taskName_param);


	zephir_update_property_this(this_ptr, SL("_defaultHandler"), taskName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the task name to be dispatched
 *
 * @param string taskName
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskName) {

	zval *taskName;

	zephir_fetch_params(0, 1, 0, &taskName);



	zephir_update_property_this(this_ptr, SL("_handlerName"), taskName TSRMLS_CC);

}

/**
 * Gets last dispatched task name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getTaskName) {


	RETURN_MEMBER(this_ptr, "_handlerName");

}

/**
 * Throws an internal exception
 *
 * @param string message
 * @param int exceptionCode
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, _throwDispatchException) {

	int exceptionCode;
	zval *message_param = NULL, *exceptionCode_param = NULL, *exception, *eventsManager = NULL, *_0, *_1, *_2;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &exceptionCode_param);

		zephir_get_strval(message, message_param);
	if (!exceptionCode_param) {
		exceptionCode = 0;	} else {
		exceptionCode = zephir_get_intval(exceptionCode_param);
	}


	ZEPHIR_INIT_VAR(exception);
	object_init_ex(exception, phalcon_cli_dispatcher_exception_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, exceptionCode);
	zephir_call_method_p2_noret(exception, "__construct", message, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _1);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "dispatch:beforeException", 1);
		zephir_call_method_p3(_0, eventsManager, "fire", _2, this_ptr, exception);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_throw_exception(exception TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon\CLI\Task
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getLastTask) {


	RETURN_MEMBER(this_ptr, "_lastHandler");

}

/**
 * Returns the active task in the dispatcher
 *
 * @return Phalcon\CLI\Task
 */
PHP_METHOD(Phalcon_Cli_Dispatcher, getActiveTask) {


	RETURN_MEMBER(this_ptr, "_activeHandler");

}

