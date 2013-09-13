
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


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
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 *<code>
 *
 *	$di = new Phalcon\Di();
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Dispatcher, phalcon, mvc_dispatcher, phalcon_dispatcher_ce, phalcon_mvc_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the default controller suffix
 *
 * @param string controllerSuffix
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix) {

	zval *controllerSuffix;

	zephir_fetch_params(0, 1, 0, &controllerSuffix);



	zephir_update_property_this(this_ptr, SL("_handlerSuffix"), controllerSuffix TSRMLS_CC);

}

/**
 * Sets the default controller name
 *
 * @param string controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController) {

	zval *controllerName;

	zephir_fetch_params(0, 1, 0, &controllerName);



	zephir_update_property_this(this_ptr, SL("_defaultHandler"), controllerName TSRMLS_CC);

}

/**
 * Sets the controller name to be dispatched
 *
 * @param string controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName) {

	zval *controllerName;

	zephir_fetch_params(0, 1, 0, &controllerName);



	zephir_update_property_this(this_ptr, SL("_handlerName"), controllerName TSRMLS_CC);

}

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName) {


	RETURN_MEMBER(this_ptr, "_handlerName");

}

/**
 * Throws an internal exception
 *
 * @param string message
 * @param int exceptionCode
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException) {

	zval *message, *exceptionCode = NULL, *eventsManager, *dependencyInjector, *response, *exception, *_0 = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &exceptionCode);

	if (!exceptionCode) {
		ZEPHIR_INIT_VAR(exceptionCode);
		ZVAL_LONG(exceptionCode, 0);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_mvc_dispatcher_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "A dependency injection container is required to access the 'response' service", 1);
		zephir_call_method_p2_noret(_0, "__construct", _2, _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "response", 1);
	ZEPHIR_INIT_VAR(response);
	zephir_call_method_p1(response, dependencyInjector, "getshared", _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 404);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Not Found", 1);
	zephir_call_method_p2_noret(response, "setstatuscode", _0, _1);
	ZEPHIR_INIT_VAR(exception);
	object_init_ex(exception, phalcon_mvc_dispatcher_exception_ce);
	zephir_call_method_p2_noret(exception, "__construct", message, exceptionCode);
	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "dispatch:beforeException", 1);
		zephir_call_method_p3(_0, eventsManager, "fire", _1, this_ptr, exception);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_throw_exception(exception TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Handles a user exception
 *
 * @param \Exception exception
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _handleException) {

	zval *exception, *eventsManager, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "dispatch:beforeException", 1);
		zephir_call_method_p3(_0, eventsManager, "fire", _1, this_ptr, exception);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Possible controller class name that will be located to dispatch the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass) {

	ZEPHIR_MM_GROW();

	zephir_call_method(return_value, this_ptr, "gethandlername");
	RETURN_MM();

}

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon\Mvc\ControllerInterface
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController) {


	RETURN_MEMBER(this_ptr, "_lastHandler");

}

/**
 * Returns the active controller in the dispatcher
 *
 * @return Phalcon\Mvc\ControllerInterface
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController) {


	RETURN_MEMBER(this_ptr, "_activeHandler");

}

