
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

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
 * Phalcon\Mvc\Dispatcher initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Dispatcher){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, Dispatcher, mvc_dispatcher, "phalcon\\dispatcher", phalcon_mvc_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_dispatcher_ce, SL("_isExactControllerName"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_dispatcher_ce TSRMLS_CC, 2, phalcon_dispatcherinterface_ce, phalcon_mvc_dispatcherinterface_ce);

	return SUCCESS;
}

/**
 * Sets the default controller suffix
 *
 * @param string $controllerSuffix
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix){

	zval *controller_suffix;

	phalcon_fetch_params(0, 1, 0, &controller_suffix);
	
	phalcon_update_property_this(this_ptr, SL("_handlerSuffix"), controller_suffix TSRMLS_CC);
	
}

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController){

	zval *controller_name;

	phalcon_fetch_params(0, 1, 0, &controller_name);
	
	phalcon_update_property_this(this_ptr, SL("_defaultHandler"), controller_name TSRMLS_CC);
	
}

/**
 * Sets the controller name to be dispatched
 *
 * @param string $controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName){

	zval *controller_name, *is_exact = NULL;

	phalcon_fetch_params(0, 1, 1, &controller_name, &is_exact);
	
	if (is_exact && zend_is_true(is_exact)) {
		zval *name;
		MAKE_STD_ZVAL(name);
		PHALCON_CONCAT_SV(name, "\\", controller_name);
		phalcon_update_property_this(this_ptr, SL("_handlerName"), name TSRMLS_CC);
		zval_ptr_dtor(&name);
		phalcon_update_property_bool(this_ptr, SL("_isExactControllerName"), 1 TSRMLS_CC);
	}
	else {
		phalcon_update_property_this(this_ptr, SL("_handlerName"), controller_name TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_isExactControllerName"), 0 TSRMLS_CC);
	}
}

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName){

	zval *is_exact;
	int i_exact;

	phalcon_read_property_this(&is_exact, getThis(), SL("_isExactControllerName"), PH_NOISY TSRMLS_CC);
	i_exact = zend_is_true(is_exact);
	zval_ptr_dtor(&is_exact);

	if (!i_exact) {
		RETURN_MEMBER(this_ptr, "_handlerName");
	}

	phalcon_return_property_quick(return_value, getThis(), SL("_handlerName"), zend_inline_hash_func(SS("_handlerName")) TSRMLS_CC);
	if (likely(Z_TYPE_P(return_value) == IS_STRING) && Z_STRLEN_P(return_value) > 1) {
		char *c = Z_STRVAL_P(return_value);
		int len = Z_STRLEN_P(return_value);
		memmove(c, c+1, len-1);
		c[len-1] = 0;
		c = erealloc(c, len);
		if (likely(c != NULL)) {
			RETVAL_STRINGL(c, len-1, 0);
		}
	}
}

/**
 * Throws an internal exception
 *
 * @param string $message
 * @param int $exceptionCode
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException){

	zval *message, *exception_code = NULL, *dependency_injector;
	zval *exception_message, *exception = NULL, *service;
	zval *response, *status_code, *status_message;
	zval *events_manager, *event_name, *status;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &exception_code);
	
	if (!exception_code) {
		PHALCON_INIT_VAR(exception_code);
		ZVAL_LONG(exception_code, 0);
	} else {
		PHALCON_SEPARATE_PARAM(exception_code);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(exception_code);
		ZVAL_LONG(exception_code, 0);
	
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "A dependency injection container is required to access the 'response' service", 1);
	
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_mvc_dispatcher_exception_ce);
		phalcon_call_method_p2_noret(exception, "__construct", exception_message, exception_code);
	
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "response", 1);
	
	PHALCON_INIT_VAR(response);
	phalcon_call_method_p1(response, dependency_injector, "getshared", service);
	
	/** 
	 * Dispatcher exceptions automatically sends 404 status
	 */
	PHALCON_INIT_VAR(status_code);
	ZVAL_LONG(status_code, 404);
	
	PHALCON_INIT_VAR(status_message);
	ZVAL_STRING(status_message, "Not Found", 1);
	phalcon_call_method_p2_noret(response, "setstatuscode", status_code, status_message);
	
	/** 
	 * Create the real exception
	 */
	PHALCON_INIT_NVAR(exception);
	object_init_ex(exception, phalcon_mvc_dispatcher_exception_ce);
	phalcon_call_method_p2_noret(exception, "__construct", message, exception_code);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeException", 1);
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, exception);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Throw the exception if it wasn't handled
	 */
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
}

/**
 * Handles a user exception
 *
 * @param \Exception $exception
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _handleException){

	zval *exception, *events_manager, *event_name;
	zval *status;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &exception);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeException", 1);
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, exception);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Possible controller class name that will be located to dispatch the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass){


	PHALCON_MM_GROW();

	phalcon_call_method(return_value, this_ptr, "gethandlername");
	RETURN_MM();
}

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon\Mvc\ControllerInterface
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController){


	RETURN_MEMBER(this_ptr, "_lastHandler");
}

/**
 * Returns the active controller in the dispatcher
 *
 * @return Phalcon\Mvc\ControllerInterface
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController){


	RETURN_MEMBER(this_ptr, "_activeHandler");
}

