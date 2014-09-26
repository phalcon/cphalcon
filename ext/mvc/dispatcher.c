
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
  +------------------------------------------------------------------------+
*/

#include "mvc/dispatcher.h"
#include "mvc/dispatcherinterface.h"
#include "mvc/../dispatcher.h"
#include "mvc/../dispatcherinterface.h"
#include "mvc/dispatcher/exception.h"
#include "http/responseinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

#include "interned-strings.h"

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
zend_class_entry *phalcon_mvc_dispatcher_ce;

PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException);
PHP_METHOD(Phalcon_Mvc_Dispatcher, _handleException);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousActionName);

static const zend_function_entry phalcon_mvc_dispatcher_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerSuffix, arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setDefaultController, arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerName, arginfo_phalcon_mvc_dispatcherinterface_setcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, _throwDispatchException, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Dispatcher, _handleException, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getLastController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getActiveController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Dispatcher initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Dispatcher){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, Dispatcher, mvc_dispatcher, phalcon_dispatcher_ce, phalcon_mvc_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

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
		phalcon_update_property_this(this_ptr, SL("_isExactHandler"), PHALCON_GLOBAL(z_true) TSRMLS_CC);
	}
	else {
		phalcon_update_property_this(this_ptr, SL("_handlerName"), controller_name TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_isExactHandler"), PHALCON_GLOBAL(z_false) TSRMLS_CC);
	}
}

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName){

	zval *is_exact;

	is_exact = phalcon_fetch_nproperty_this(getThis(), SL("_isExactHandler"), PH_NOISY TSRMLS_CC);

	if (!zend_is_true(is_exact)) {
		RETURN_MEMBER(this_ptr, "_handlerName");
	}

	phalcon_return_property_quick(return_value, NULL, getThis(), SL("_handlerName"), zend_inline_hash_func(SS("_handlerName")) TSRMLS_CC);
	if (likely(Z_TYPE_P(return_value) == IS_STRING) && Z_STRLEN_P(return_value) > 1) {
		if (Z_STRVAL_P(return_value)[0] == '\\') {
			char *c = Z_STRVAL_P(return_value);
			int len = Z_STRLEN_P(return_value);
			memmove(c, c+1, len); /* This will include the trailing zero */
			RETVAL_STRINGL(c, len - 1, 0);
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
	zval *response = NULL, *status_code, *status_message;
	zval *events_manager, *event_name, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &exception_code);

	if (!exception_code) {
		PHALCON_INIT_VAR(exception_code);
		ZVAL_LONG(exception_code, 0);
	} else {
		PHALCON_SEPARATE_PARAM(exception_code);
	}

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(exception_code);
		ZVAL_LONG(exception_code, 0);

		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "A dependency injection container is required to access the 'response' service", 1);

		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_mvc_dispatcher_exception_ce);
		PHALCON_CALL_METHOD(NULL, exception, "__construct", exception_message, exception_code);

		phalcon_throw_exception(exception TSRMLS_CC);
		RETURN_MM();
	}

	PHALCON_INIT_VAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_response);

	PHALCON_CALL_METHOD(&response, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(response, phalcon_http_responseinterface_ce);

	/**
	 * Dispatcher exceptions automatically send 404 status
	 */
	PHALCON_INIT_VAR(status_code);
	ZVAL_LONG(status_code, 404);

	PHALCON_INIT_VAR(status_message);
	ZVAL_STRING(status_message, "Not Found", 1);
	PHALCON_CALL_METHOD(NULL, response, "setstatuscode", status_code, status_message);

	/**
	 * Create the real exception
	 */
	PHALCON_INIT_NVAR(exception);
	object_init_ex(exception, phalcon_mvc_dispatcher_exception_ce);
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
 *
 * @warning If any additional logic is to be implemented here, please check
 * phalcon_dispatcher_fire_event() first
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _handleException){

	zval *exception, *events_manager, *event_name;

	phalcon_fetch_params(0, 1, 0, &exception);

	events_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_ALLOC_GHOST_ZVAL(event_name);
		ZVAL_STRING(event_name, "dispatch:beforeException", 1);

		PHALCON_RETURN_CALL_METHODW(events_manager, "fire", event_name, this_ptr, exception);
	}
}

/**
 * Possible controller class name that will be located to dispatch the request
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass)
{
	PHALCON_RETURN_CALL_METHODW(this_ptr, "gethandlerclass");
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

/**
 * Returns the previous controller in the dispatcher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousControllerName){


	RETURN_MEMBER(this_ptr, "_previousHandlerName");
}

/**
 * Returns the previous action in the dispatcher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousActionName){


	RETURN_MEMBER(this_ptr, "_previousActionName");
}

