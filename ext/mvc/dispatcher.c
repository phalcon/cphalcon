
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/exception.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 *<code>
 *
 *	$di = new Phalcon\DI();
 *
 *	$dispatcher = new Phalcon\Mvc\Dispatcher();
 *
 *  $dispatcher->setDI($di);
 *
 *	$dispatcher->setControllerName('posts');
 *	$dispatcher->setActionName('index');
 *	$dispatcher->setParams(array());
 *
 *	$controller = $dispatcher->dispatch();
 *
 *</code>
 */


/**
 * Sets the default controller suffix
 *
 * @param string $controllerSuffix
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix){

	zval *controller_suffix = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_suffix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_handlerSuffix"), controller_suffix TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultHandler"), controller_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the controller name to be dispatched
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &controller_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_handlerName"), controller_name TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName){

	zval *controller_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(controller_name);
	phalcon_read_property(&controller_name, this_ptr, SL("_handlerName"), PH_NOISY_CC);
	
	RETURN_CCTOR(controller_name);
}

/**
 * Throws an internal exception
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException){

	zval *message = NULL, *dependency_injector = NULL, *response = NULL;
	zval *status_code = NULL, *status_message = NULL, *exception = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_dispatcher_exception_ce, "A dependency injection container is required to access the 'response' service");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "response", 1);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(status_code);
	ZVAL_LONG(status_code, 404);
	
	PHALCON_INIT_VAR(status_message);
	ZVAL_STRING(status_message, "Not Found", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(response, "setstatuscode", status_code, status_message, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_mvc_dispatcher_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", message, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
}

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon\Mvc\Controller
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController){

	zval *last_controller = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(last_controller);
	phalcon_read_property(&last_controller, this_ptr, SL("_lastHandler"), PH_NOISY_CC);
	
	RETURN_CCTOR(last_controller);
}

/**
 * Returns the active controller in the dispatcher
 *
 * @return Phalcon\Mvc\Controller
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController){

	zval *controller = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(controller);
	phalcon_read_property(&controller, this_ptr, SL("_activeHandler"), PH_NOISY_CC);
	
	RETURN_CCTOR(controller);
}

