
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Mvc\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 *<code>
 * $di = new \Phalcon\Di();
 *
 * $dispatcher = new \Phalcon\Mvc\Dispatcher();
 *
 * $dispatcher->setDI($di);
 *
 * $dispatcher->setControllerName("posts");
 * $dispatcher->setActionName("index");
 * $dispatcher->setParams([]);
 *
 * $controller = $dispatcher->dispatch();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Dispatcher, phalcon, mvc_dispatcher, phalcon_dispatcher_ce, phalcon_mvc_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_dispatcher_ce TSRMLS_CC, 1, phalcon_mvc_dispatcherinterface_ce);
	return SUCCESS;

}

/**
 * Sets the default controller suffix
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix) {

	zval *controllerSuffix_param = NULL;
	zval *controllerSuffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(controllerSuffix_param) != IS_STRING && Z_TYPE_P(controllerSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerSuffix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerSuffix_param) == IS_STRING)) {
		zephir_get_strval(controllerSuffix, controllerSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(controllerSuffix);
		ZVAL_EMPTY_STRING(controllerSuffix);
	}


	zephir_update_property_this(getThis(), SL("_handlerSuffix"), controllerSuffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController) {

	zval *controllerName_param = NULL;
	zval *controllerName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(controllerName);
		ZVAL_EMPTY_STRING(controllerName);
	}


	zephir_update_property_this(getThis(), SL("_defaultHandler"), controllerName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the controller name to be dispatched
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName) {

	zval *controllerName_param = NULL;
	zval *controllerName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(controllerName);
		ZVAL_EMPTY_STRING(controllerName);
	}


	zephir_update_property_this(getThis(), SL("_handlerName"), controllerName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets last dispatched controller name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName) {

	

	RETURN_MEMBER(getThis(), "_handlerName");

}

/**
 * Gets previous dispatched namespace name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousNamespaceName) {

	

	RETURN_MEMBER(getThis(), "_previousNamespaceName");

}

/**
 * Gets previous dispatched controller name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousControllerName) {

	

	RETURN_MEMBER(getThis(), "_previousHandlerName");

}

/**
 * Gets previous dispatched action name
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousActionName) {

	

	RETURN_MEMBER(getThis(), "_previousActionName");

}

/**
 * Throws an internal exception
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException) {

	zend_long exceptionCode, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *exceptionCode_param = NULL, *dependencyInjector = NULL, *response = NULL, *exception = NULL, *_3 = NULL, *_4 = NULL, *_5, *_0$$3, *_1$$3, *_2$$3;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &exceptionCode_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!exceptionCode_param) {
		exceptionCode = 0;
	} else {
		exceptionCode = zephir_get_intval(exceptionCode_param);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_mvc_dispatcher_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "A dependency injection container is required to access the 'response' service", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 9, _1$$3, _2$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/mvc/dispatcher.zep", 127 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "response", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "getshared", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(response, _3);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 404);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "Not Found", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, 0, _4, _5);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(exception);
	object_init_ex(exception, phalcon_mvc_dispatcher_exception_ce);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, exceptionCode);
	ZEPHIR_CALL_METHOD(NULL, exception, "__construct", NULL, 9, message, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_handleexception", NULL, 0, exception);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
		RETURN_MM_BOOL(0);
	}
	zephir_throw_exception_debug(exception, "phalcon/mvc/dispatcher.zep", 149 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Handles a user exception
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, _handleException) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, *eventsManager = NULL, *_0, *_1$$3 = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "dispatch:beforeException", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, eventsManager, "fire", NULL, 0, _2$$3, this_ptr, exception);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Forwards the execution flow to another controller/action.
 *
 * <code>
 * use Phalcon\Events\Event;
 * use Phalcon\Mvc\Dispatcher;
 * use App\Backend\Bootstrap as Backend;
 * use App\Frontend\Bootstrap as Frontend;
 *
 * // Registering modules
 * $modules = [
 *     "frontend" => [
 *         "className" => Frontend::class,
 *         "path"      => __DIR__ . "/app/Modules/Frontend/Bootstrap.php",
 *         "metadata"  => [
 *             "controllersNamespace" => "App\Frontend\Controllers",
 *         ],
 *     ],
 *     "backend" => [
 *         "className" => Backend::class,
 *         "path"      => __DIR__ . "/app/Modules/Backend/Bootstrap.php",
 *         "metadata"  => [
 *             "controllersNamespace" => "App\Backend\Controllers",
 *         ],
 *     ],
 * ];
 *
 * $application->registerModules($modules);
 *
 * // Setting beforeForward listener
 * $eventsManager  = $di->getShared("eventsManager");
 *
 * $eventsManager->attach(
 *     "dispatch:beforeForward",
 *     function(Event $event, Dispatcher $dispatcher, array $forward) use ($modules) {
 *         $metadata = $modules[$forward["module"]]["metadata"];
 *
 *         $dispatcher->setModuleName($forward["module"]);
 *         $dispatcher->setNamespaceName($metadata["controllersNamespace"]);
 *     }
 * );
 *
 * // Forward
 * $this->dispatcher->forward(
 *     [
 *         "module"     => "backend",
 *         "controller" => "posts",
 *         "action"     => "index",
 *     ]
 * );
 * </code>
 *
 * @param array forward
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, forward) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *forward, *eventsManager = NULL, *_0, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "dispatch:beforeForward", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _1$$3, this_ptr, forward);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_dispatcher_ce, getThis(), "forward", &_2, 324, forward);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Possible controller class name that will be located to dispatch the request
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethandlerclass", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the latest dispatched controller
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController) {

	

	RETURN_MEMBER(getThis(), "_lastHandler");

}

/**
 * Returns the active controller in the dispatcher
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController) {

	

	RETURN_MEMBER(getThis(), "_activeHandler");

}

