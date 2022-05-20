
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Micro
 *
 * With Phalcon you can create "Micro-Framework like" applications. By doing
 * this, you only need to write a minimal amount of code to create a PHP
 * application. Micro applications are suitable to small applications, APIs and
 * prototypes in a practical way.
 *
 *```php
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $app->get(
 *     "/say/welcome/{name}",
 *     function ($name) {
 *         echo "<h1>Welcome $name!</h1>";
 *     }
 * );
 *
 * $app->handle("/say/welcome/Phalcon");
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Micro, phalcon, mvc_micro, phalcon_di_injectable_ce, phalcon_mvc_micro_method_entry, 0);

	/**
	 * @var callable|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("activeHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("afterBindingHandlers"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("afterHandlers"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("beforeHandlers"), ZEND_ACC_PROTECTED);
	/**
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var callable|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("errorHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("finishHandlers"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("handlers"), ZEND_ACC_PROTECTED);
	/**
	 * @var BinderInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("modelBinder"), ZEND_ACC_PROTECTED);
	/**
	 * @var callable|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("notFoundHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var callable|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("responseHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("returnedValue"), ZEND_ACC_PROTECTED);
	/**
	 * @var RouterInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("router"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_micro_ce, SL("stopped"), 0, ZEND_ACC_PROTECTED);
	phalcon_mvc_micro_ce->create_object = zephir_init_properties_Phalcon_Mvc_Micro;

	zend_class_implements(phalcon_mvc_micro_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_mvc_micro_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Micro constructor
 */
PHP_METHOD(Phalcon_Mvc_Micro, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container = NULL, container_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &container);
	if (!container) {
		container = &container_sub;
		container = &__$null;
	}


	if (Z_TYPE_P(container) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, container);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Appends an 'after' middleware to be called after execute the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, after)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_array_append(this_ptr, SL("afterHandlers"), handler);
	RETURN_THISW();
}

/**
 * Appends a afterBinding middleware to be called after model binding
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, afterBinding)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_array_append(this_ptr, SL("afterBindingHandlers"), handler);
	RETURN_THISW();
}

/**
 * Appends a before middleware to be called before execute the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, before)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_array_append(this_ptr, SL("beforeHandlers"), handler);
	RETURN_THISW();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);
	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "adddelete", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * Sets a handler that will be called when an exception is thrown handling
 * the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, error)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_zval(this_ptr, ZEND_STRL("errorHandler"), handler);
	RETURN_THISW();
}

/**
 * Appends a 'finish' middleware to be called when the request is finished
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, finish)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_array_append(this_ptr, SL("finishHandlers"), handler);
	RETURN_THISW();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);
	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addget", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "activeHandler");
}

/**
 * Returns bound models from binder instance
 */
PHP_METHOD(Phalcon_Mvc_Micro, getBoundModels)
{
	zval modelBinder, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&modelBinder, &_0);
	if (Z_TYPE_P(&modelBinder) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(&modelBinder, "getboundmodels", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Micro, getEventsManager)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Mvc_Micro, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);


	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

/**
 * Returns the internal handlers attached to the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getHandlers)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "handlers");
}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Mvc_Micro, getModelBinder)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "modelBinder");
}

/**
 * Returns the value returned by the executed handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "returnedValue");
}

/**
 * Returns the internal router used by the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter)
{
	zval router, _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&router, &_0);
	if (Z_TYPE_P(&router) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "router");
		ZEPHIR_CALL_METHOD(&router, this_ptr, "getsharedservice", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &router, "clear", NULL, 0);
		zephir_check_call_status();
		ZVAL_BOOL(&_2$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &router, "removeextraslashes", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("router"), &router);
	}
	RETURN_CCTOR(&router);
}

/**
 * Obtains a service from the DI
 *
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Micro, getService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, container, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);
	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 408);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "get", NULL, 409, &serviceName);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Obtains a shared service from the DI
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, container, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);
	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 408);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "getshared", NULL, 410, &serviceName);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Handle the whole request
 *
 * @param string uri
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, handle)
{
	zval _69$$59, _74$$64, _79$$69;
	zend_class_entry *_25$$21;
	zend_bool _23$$7, _34$$7, _15$$11, _19$$16, _30$$25, _39$$31, _43$$36, _50$$42, _54$$47, _66$$57, _71$$62, _84$$79;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$true, __$false, container, eventsManager, status, router, matchedRoute, handler, beforeHandlers, params, returnedValue, e, errorHandler, afterHandlers, notFoundHandler, finishHandlers, finish, before, after, response, modelBinder, routeName, realHandler, methodName, lazyReturned, afterBindingHandlers, afterBinding, _0, _76, _1$$4, _4$$4, _5$$4, *_64$$4, _65$$4, _2$$5, _3$$5, _6$$7, _7$$7, _12$$7, *_13$$7, _14$$7, *_37$$7, _38$$7, *_48$$7, _49$$7, _8$$8, _9$$8, _10$$9, _11$$9, _18$$11, _16$$14, _17$$14, _22$$16, _20$$19, _21$$19, _24$$21, _26$$23, _27$$24, _28$$24, _29$$22, _31$$26, _32$$26, _33$$26, _35$$29, _36$$29, _42$$31, _40$$34, _41$$34, _46$$36, _44$$39, _45$$39, _47$$41, _53$$42, _51$$45, _52$$45, _57$$47, _55$$50, _56$$50, _58$$52, _59$$53, _60$$53, _61$$55, _62$$55, _63$$56, _70$$57, _67$$60, _68$$60, _75$$62, _72$$65, _73$$65, _77$$67, _78$$68, _80$$77, _81$$77, _82$$80, _83$$80, _85$$82;
	zval uri, bindCacheKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&matchedRoute);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&beforeHandlers);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&returnedValue);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&errorHandler);
	ZVAL_UNDEF(&afterHandlers);
	ZVAL_UNDEF(&notFoundHandler);
	ZVAL_UNDEF(&finishHandlers);
	ZVAL_UNDEF(&finish);
	ZVAL_UNDEF(&before);
	ZVAL_UNDEF(&after);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&realHandler);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&lazyReturned);
	ZVAL_UNDEF(&afterBindingHandlers);
	ZVAL_UNDEF(&afterBinding);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_76);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_65$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_38$$7);
	ZVAL_UNDEF(&_49$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_27$$24);
	ZVAL_UNDEF(&_28$$24);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_33$$26);
	ZVAL_UNDEF(&_35$$29);
	ZVAL_UNDEF(&_36$$29);
	ZVAL_UNDEF(&_42$$31);
	ZVAL_UNDEF(&_40$$34);
	ZVAL_UNDEF(&_41$$34);
	ZVAL_UNDEF(&_46$$36);
	ZVAL_UNDEF(&_44$$39);
	ZVAL_UNDEF(&_45$$39);
	ZVAL_UNDEF(&_47$$41);
	ZVAL_UNDEF(&_53$$42);
	ZVAL_UNDEF(&_51$$45);
	ZVAL_UNDEF(&_52$$45);
	ZVAL_UNDEF(&_57$$47);
	ZVAL_UNDEF(&_55$$50);
	ZVAL_UNDEF(&_56$$50);
	ZVAL_UNDEF(&_58$$52);
	ZVAL_UNDEF(&_59$$53);
	ZVAL_UNDEF(&_60$$53);
	ZVAL_UNDEF(&_61$$55);
	ZVAL_UNDEF(&_62$$55);
	ZVAL_UNDEF(&_63$$56);
	ZVAL_UNDEF(&_70$$57);
	ZVAL_UNDEF(&_67$$60);
	ZVAL_UNDEF(&_68$$60);
	ZVAL_UNDEF(&_75$$62);
	ZVAL_UNDEF(&_72$$65);
	ZVAL_UNDEF(&_73$$65);
	ZVAL_UNDEF(&_77$$67);
	ZVAL_UNDEF(&_78$$68);
	ZVAL_UNDEF(&_80$$77);
	ZVAL_UNDEF(&_81$$77);
	ZVAL_UNDEF(&_82$$80);
	ZVAL_UNDEF(&_83$$80);
	ZVAL_UNDEF(&_85$$82);
	ZVAL_UNDEF(&_69$$59);
	ZVAL_UNDEF(&_74$$64);
	ZVAL_UNDEF(&_79$$69);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);
	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
	}


	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_INIT_VAR(&realHandler);
	ZVAL_NULL(&realHandler);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "A dependency injection container is required to access micro services", "phalcon/Mvc/Micro.zep", 419);
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&returnedValue);
		ZVAL_NULL(&returnedValue);
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&eventsManager, &_1$$4);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "micro:beforeHandleRoute");
			ZEPHIR_CALL_METHOD(&_2$$5, &eventsManager, "fire", NULL, 0, &_3$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$5)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "router");
		ZEPHIR_CALL_METHOD(&_4$$4, &container, "getshared", NULL, 0, &_5$$4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&router, &_4$$4);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getmatchedroute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&matchedRoute) == IS_OBJECT) {
			ZEPHIR_OBS_VAR(&handler);
			zephir_read_property(&_6$$7, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_7$$7, &matchedRoute, "getrouteid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&handler, &_6$$7, &_7$$7, 0)))) {
				ZEPHIR_INIT_VAR(&_8$$8);
				object_init_ex(&_8$$8, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(&_9$$8);
				ZVAL_STRING(&_9$$8, "Matched route doesn't have an associated handler");
				ZEPHIR_CALL_METHOD(NULL, &_8$$8, "__construct", NULL, 29, &_9$$8);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_8$$8, "phalcon/Mvc/Micro.zep", 455);
				goto try_end_1;

			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("activeHandler"), &handler);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_11$$9);
				ZVAL_STRING(&_11$$9, "micro:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_10$$9, &eventsManager, "fire", NULL, 0, &_11$$9, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$9)) {
					RETURN_MM_BOOL(0);
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_read_property(&handler, this_ptr, ZEND_STRL("activeHandler"), PH_NOISY_CC);
			}
			zephir_read_property(&_12$$7, this_ptr, ZEND_STRL("beforeHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&beforeHandlers, &_12$$7);
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
			}
			zephir_is_iterable(&beforeHandlers, 0, "phalcon/Mvc/Micro.zep", 508);
			if (Z_TYPE_P(&beforeHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&beforeHandlers), _13$$7)
				{
					ZEPHIR_INIT_NVAR(&before);
					ZVAL_COPY(&before, _13$$7);
					_15$$11 = Z_TYPE_P(&before) == IS_OBJECT;
					if (_15$$11) {
						_15$$11 = zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_15$$11) {
						ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&before)))) {
							ZEPHIR_INIT_NVAR(&_16$$14);
							object_init_ex(&_16$$14, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_17$$14);
							ZVAL_STRING(&_17$$14, "'before' handler is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_16$$14, "__construct", NULL, 29, &_17$$14);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_16$$14, "phalcon/Mvc/Micro.zep", 491);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &before);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property(&_18$$11, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_18$$11)) {
						RETURN_CCTOR(&status);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_14$$7, &beforeHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&before, &beforeHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_19$$16 = Z_TYPE_P(&before) == IS_OBJECT;
						if (_19$$16) {
							_19$$16 = zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_19$$16) {
							ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&before)))) {
								ZEPHIR_INIT_NVAR(&_20$$19);
								object_init_ex(&_20$$19, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_21$$19);
								ZVAL_STRING(&_21$$19, "'before' handler is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_20$$19, "__construct", NULL, 29, &_21$$19);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_20$$19, "phalcon/Mvc/Micro.zep", 491);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &before);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property(&_22$$16, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_22$$16)) {
							RETURN_CCTOR(&status);
						}
					ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&before);
			ZEPHIR_CALL_METHOD(&params, &router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property(&_12$$7, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_12$$7);
			_23$$7 = Z_TYPE_P(&handler) == IS_OBJECT;
			if (_23$$7) {
				_23$$7 = zephir_is_instance_of(&handler, SL("Closure"));
			}
			if (_23$$7) {
				_25$$21 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_24$$21, _25$$21, "bind", NULL, 0, &handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&handler, &_24$$21);
				if (Z_TYPE_P(&modelBinder) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&routeName, &matchedRoute, "getname", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					if (Z_TYPE_P(&routeName) != IS_NULL) {
						ZEPHIR_INIT_VAR(&_26$$23);
						ZEPHIR_CONCAT_SV(&_26$$23, "_PHMB_", &routeName);
						zephir_get_strval(&bindCacheKey, &_26$$23);
					} else {
						ZEPHIR_CALL_METHOD(&_27$$24, &matchedRoute, "getpattern", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_INIT_VAR(&_28$$24);
						ZEPHIR_CONCAT_SV(&_28$$24, "_PHMB_", &_27$$24);
						zephir_get_strval(&bindCacheKey, &_28$$24);
					}
					ZEPHIR_CALL_METHOD(&_29$$22, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_29$$22);
				}
			}
			if (Z_TYPE_P(&handler) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&realHandler);
				zephir_array_fetch_long(&realHandler, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 539);
				_30$$25 = zephir_instance_of_ev(&realHandler, phalcon_mvc_controller_ce);
				if (_30$$25) {
					_30$$25 = Z_TYPE_P(&modelBinder) != IS_NULL;
				}
				if (_30$$25) {
					ZEPHIR_OBS_VAR(&methodName);
					zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 542);
					ZEPHIR_INIT_VAR(&_31$$26);
					zephir_get_class(&_31$$26, &realHandler, 0);
					ZEPHIR_INIT_VAR(&_32$$26);
					ZEPHIR_CONCAT_SVSV(&_32$$26, "_PHMB_", &_31$$26, "_", &methodName);
					zephir_get_strval(&bindCacheKey, &_32$$26);
					ZEPHIR_CALL_METHOD(&_33$$26, &modelBinder, "bindtohandler", NULL, 0, &realHandler, &params, &bindCacheKey, &methodName);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_33$$26);
				}
			}
			_34$$7 = Z_TYPE_P(&realHandler) != IS_NULL;
			if (_34$$7) {
				_34$$7 = zephir_instance_of_ev(&realHandler, phalcon_mvc_micro_lazyloader_ce);
			}
			if (_34$$7) {
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 559);
				ZEPHIR_CALL_METHOD(&lazyReturned, &realHandler, "callmethod", NULL, 0, &methodName, &params, &modelBinder);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				ZEPHIR_INIT_NVAR(&lazyReturned);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&lazyReturned, &handler, &params);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_CPY_WRT(&returnedValue, &lazyReturned);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_36$$29);
				ZVAL_STRING(&_36$$29, "micro:afterBinding");
				ZEPHIR_CALL_METHOD(&_35$$29, &eventsManager, "fire", NULL, 0, &_36$$29, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_35$$29)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property(&_12$$7, this_ptr, ZEND_STRL("afterBindingHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterBindingHandlers, &_12$$7);
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
			}
			zephir_is_iterable(&afterBindingHandlers, 0, "phalcon/Mvc/Micro.zep", 622);
			if (Z_TYPE_P(&afterBindingHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterBindingHandlers), _37$$7)
				{
					ZEPHIR_INIT_NVAR(&afterBinding);
					ZVAL_COPY(&afterBinding, _37$$7);
					_39$$31 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
					if (_39$$31) {
						_39$$31 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_39$$31) {
						ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&afterBinding)))) {
							ZEPHIR_INIT_NVAR(&_40$$34);
							object_init_ex(&_40$$34, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_41$$34);
							ZVAL_STRING(&_41$$34, "'afterBinding' handler is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_40$$34, "__construct", NULL, 29, &_41$$34);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_40$$34, "phalcon/Mvc/Micro.zep", 602);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property(&_42$$31, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_42$$31)) {
						RETURN_CCTOR(&status);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_38$$7, &afterBindingHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_38$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&afterBinding, &afterBindingHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_43$$36 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
						if (_43$$36) {
							_43$$36 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_43$$36) {
							ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&afterBinding)))) {
								ZEPHIR_INIT_NVAR(&_44$$39);
								object_init_ex(&_44$$39, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_45$$39);
								ZVAL_STRING(&_45$$39, "'afterBinding' handler is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_44$$39, "__construct", NULL, 29, &_45$$39);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_44$$39, "phalcon/Mvc/Micro.zep", 602);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property(&_46$$36, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_46$$36)) {
							RETURN_CCTOR(&status);
						}
					ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&afterBinding);
			zephir_update_property_zval(this_ptr, ZEND_STRL("returnedValue"), &returnedValue);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_47$$41);
				ZVAL_STRING(&_47$$41, "micro:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_47$$41, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
			}
			zephir_read_property(&_12$$7, this_ptr, ZEND_STRL("afterHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterHandlers, &_12$$7);
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
			}
			zephir_is_iterable(&afterHandlers, 0, "phalcon/Mvc/Micro.zep", 661);
			if (Z_TYPE_P(&afterHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterHandlers), _48$$7)
				{
					ZEPHIR_INIT_NVAR(&after);
					ZVAL_COPY(&after, _48$$7);
					_50$$42 = Z_TYPE_P(&after) == IS_OBJECT;
					if (_50$$42) {
						_50$$42 = zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_50$$42) {
						ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&after)))) {
							ZEPHIR_INIT_NVAR(&_51$$45);
							object_init_ex(&_51$$45, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_52$$45);
							ZVAL_STRING(&_52$$45, "One of the 'after' handlers is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_51$$45, "__construct", NULL, 29, &_52$$45);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_51$$45, "phalcon/Mvc/Micro.zep", 648);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &after);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property(&_53$$42, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_53$$42)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_49$$7, &afterHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_49$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&after, &afterHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_54$$47 = Z_TYPE_P(&after) == IS_OBJECT;
						if (_54$$47) {
							_54$$47 = zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_54$$47) {
							ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&after)))) {
								ZEPHIR_INIT_NVAR(&_55$$50);
								object_init_ex(&_55$$50, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_56$$50);
								ZVAL_STRING(&_56$$50, "One of the 'after' handlers is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_55$$50, "__construct", NULL, 29, &_56$$50);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_55$$50, "phalcon/Mvc/Micro.zep", 648);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &after);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property(&_57$$47, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_57$$47)) {
							break;
						}
					ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&after);
		} else {
			zephir_read_property(&_58$$52, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&eventsManager, &_58$$52);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_60$$53);
				ZVAL_STRING(&_60$$53, "micro:beforeNotFound");
				ZEPHIR_CALL_METHOD(&_59$$53, &eventsManager, "fire", NULL, 0, &_60$$53, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_59$$53)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property(&_58$$52, this_ptr, ZEND_STRL("notFoundHandler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&notFoundHandler, &_58$$52);
			if (UNEXPECTED(!(zephir_is_callable(&notFoundHandler)))) {
				ZEPHIR_INIT_VAR(&_61$$55);
				object_init_ex(&_61$$55, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(&_62$$55);
				ZVAL_STRING(&_62$$55, "Not-Found handler is not callable or is not defined");
				ZEPHIR_CALL_METHOD(NULL, &_61$$55, "__construct", NULL, 29, &_62$$55);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_61$$55, "phalcon/Mvc/Micro.zep", 681);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(&returnedValue);
			ZEPHIR_CALL_USER_FUNC(&returnedValue, &notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_63$$56);
			ZVAL_STRING(&_63$$56, "micro:afterHandleRoute");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_63$$56, this_ptr, &returnedValue);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("finishHandlers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&finishHandlers, &_1$$4);
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
		}
		zephir_is_iterable(&finishHandlers, 0, "phalcon/Mvc/Micro.zep", 736);
		if (Z_TYPE_P(&finishHandlers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&finishHandlers), _64$$4)
			{
				ZEPHIR_INIT_NVAR(&finish);
				ZVAL_COPY(&finish, _64$$4);
				_66$$57 = Z_TYPE_P(&finish) == IS_OBJECT;
				if (_66$$57) {
					_66$$57 = zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce);
				}
				if (_66$$57) {
					ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
					zephir_check_call_status_or_jump(try_end_1);
				} else {
					if (UNEXPECTED(!(zephir_is_callable(&finish)))) {
						ZEPHIR_INIT_NVAR(&_67$$60);
						object_init_ex(&_67$$60, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(&_68$$60);
						ZVAL_STRING(&_68$$60, "One of the 'finish' handlers is not callable");
						ZEPHIR_CALL_METHOD(NULL, &_67$$60, "__construct", NULL, 29, &_68$$60);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_67$$60, "phalcon/Mvc/Micro.zep", 717);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(&_69$$59);
					zephir_create_array(&_69$$59, 1, 0);
					zephir_array_fast_append(&_69$$59, this_ptr);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &_69$$59);
					zephir_check_call_status_or_jump(try_end_1);
				}
				zephir_read_property(&_70$$57, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_70$$57)) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_65$$4, &finishHandlers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_65$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&finish, &finishHandlers, "current", NULL, 0);
				zephir_check_call_status();
					_71$$62 = Z_TYPE_P(&finish) == IS_OBJECT;
					if (_71$$62) {
						_71$$62 = zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_71$$62) {
						ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&finish)))) {
							ZEPHIR_INIT_NVAR(&_72$$65);
							object_init_ex(&_72$$65, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_73$$65);
							ZVAL_STRING(&_73$$65, "One of the 'finish' handlers is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_72$$65, "__construct", NULL, 29, &_73$$65);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_72$$65, "phalcon/Mvc/Micro.zep", 717);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&_74$$64);
						zephir_create_array(&_74$$64, 1, 0);
						zephir_array_fast_append(&_74$$64, this_ptr);
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &_74$$64);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property(&_75$$62, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_75$$62)) {
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&finish);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_76);
		ZVAL_OBJ(&_76, EG(exception));
		Z_ADDREF_P(&_76);
		if (zephir_is_instance_of(&_76, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_76);
			zephir_read_property(&_77$$67, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&eventsManager, &_77$$67);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_78$$68);
				ZVAL_STRING(&_78$$68, "micro:beforeException");
				ZEPHIR_CALL_METHOD(&returnedValue, &eventsManager, "fire", NULL, 0, &_78$$68, this_ptr, &e);
				zephir_check_call_status();
			}
			zephir_read_property(&_77$$67, this_ptr, ZEND_STRL("errorHandler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&errorHandler, &_77$$67);
			if (zephir_is_true(&errorHandler)) {
				if (UNEXPECTED(!(zephir_is_callable(&errorHandler)))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Error handler is not callable", "phalcon/Mvc/Micro.zep", 757);
					return;
				}
				ZEPHIR_INIT_VAR(&_79$$69);
				zephir_create_array(&_79$$69, 1, 0);
				zephir_array_fast_append(&_79$$69, &e);
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &errorHandler, &_79$$69);
				zephir_check_call_status();
				if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce))) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 770);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 774);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
					zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 779);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("responseHandler"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_80$$77, this_ptr, ZEND_STRL("responseHandler"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(!(zephir_is_callable(&_80$$77)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Response handler is not callable or is not defined", "phalcon/Mvc/Micro.zep", 792);
			return;
		}
		zephir_read_property(&_81$$77, this_ptr, ZEND_STRL("responseHandler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&returnedValue);
		ZEPHIR_CALL_USER_FUNC(&returnedValue, &_81$$77);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(&returnedValue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_83$$80);
			ZVAL_STRING(&_83$$80, "response");
			ZEPHIR_CALL_METHOD(&_82$$80, &container, "getshared", NULL, 0, &_83$$80);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_82$$80);
			ZEPHIR_CALL_METHOD(&_82$$80, &response, "issent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_82$$80))) {
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &returnedValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
		_84$$79 = Z_TYPE_P(&returnedValue) == IS_OBJECT;
		if (_84$$79) {
			_84$$79 = zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce);
		}
		if (_84$$79) {
			ZEPHIR_CALL_METHOD(&_85$$82, &returnedValue, "issent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_85$$82))) {
				ZEPHIR_CALL_METHOD(NULL, &returnedValue, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
	}
	RETURN_CCTOR(&returnedValue);
}

/**
 * Checks if a service is registered in the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, hasService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, container, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);
	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 408);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "has", NULL, 411, &serviceName);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, head)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);
	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addhead", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * Maps a route to a handler without any HTTP method constraint
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, map)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);
	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "add", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * Mounts a collection of handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount)
{
	zend_bool _4$$7, _5$$7, _7$$15, _8$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, mainHandler, handlers, lazyHandler, prefix, methods, pattern, subHandler, realHandler, prefixedPattern, route, handler, name, _0, *_1, _2, _6$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&mainHandler);
	ZVAL_UNDEF(&handlers);
	ZVAL_UNDEF(&lazyHandler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&subHandler);
	ZVAL_UNDEF(&realHandler);
	ZVAL_UNDEF(&prefixedPattern);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_mvc_micro_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);


	ZEPHIR_CALL_METHOD(&mainHandler, collection, "gethandler", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&mainHandler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Collection requires a main handler", "phalcon/Mvc/Micro.zep", 915);
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "gethandlers", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&handlers)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "There are no handlers to mount", "phalcon/Mvc/Micro.zep", 921);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, collection, "islazy", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&lazyHandler);
		object_init_ex(&lazyHandler, phalcon_mvc_micro_lazyloader_ce);
		ZEPHIR_CALL_METHOD(NULL, &lazyHandler, "__construct", NULL, 412, &mainHandler);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&lazyHandler, &mainHandler);
	}
	ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&handlers, 0, "phalcon/Mvc/Micro.zep", 979);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _1)
		{
			ZEPHIR_INIT_NVAR(&handler);
			ZVAL_COPY(&handler, _1);
			if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/Mvc/Micro.zep", 942);
				return;
			}
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 945);
			ZEPHIR_OBS_NVAR(&pattern);
			zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 946);
			ZEPHIR_OBS_NVAR(&subHandler);
			zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 947);
			ZEPHIR_OBS_NVAR(&name);
			zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 948);
			ZEPHIR_INIT_NVAR(&realHandler);
			zephir_create_array(&realHandler, 2, 0);
			zephir_array_fast_append(&realHandler, &lazyHandler);
			zephir_array_fast_append(&realHandler, &subHandler);
			if (!(ZEPHIR_IS_EMPTY(&prefix))) {
				if (ZEPHIR_IS_STRING(&pattern, "/")) {
					ZEPHIR_CPY_WRT(&prefixedPattern, &prefix);
				} else {
					ZEPHIR_INIT_NVAR(&prefixedPattern);
					ZEPHIR_CONCAT_VV(&prefixedPattern, &prefix, &pattern);
				}
			} else {
				ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
			}
			ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_3, 0, &prefixedPattern, &realHandler);
			zephir_check_call_status();
			_4$$7 = Z_TYPE_P(&methods) == IS_STRING;
			if (_4$$7) {
				_4$$7 = !ZEPHIR_IS_STRING(&methods, "");
			}
			_5$$7 = _4$$7;
			if (!(_5$$7)) {
				_5$$7 = Z_TYPE_P(&methods) == IS_ARRAY;
			}
			if (_5$$7) {
				ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&name) == IS_STRING) {
				ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &name);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &handlers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &handlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&handler, &handlers, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/Mvc/Micro.zep", 942);
					return;
				}
				ZEPHIR_OBS_NVAR(&methods);
				zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 945);
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 946);
				ZEPHIR_OBS_NVAR(&subHandler);
				zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 947);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 948);
				ZEPHIR_INIT_NVAR(&_6$$15);
				zephir_create_array(&_6$$15, 2, 0);
				zephir_array_fast_append(&_6$$15, &lazyHandler);
				zephir_array_fast_append(&_6$$15, &subHandler);
				ZEPHIR_CPY_WRT(&realHandler, &_6$$15);
				if (!(ZEPHIR_IS_EMPTY(&prefix))) {
					if (ZEPHIR_IS_STRING(&pattern, "/")) {
						ZEPHIR_CPY_WRT(&prefixedPattern, &prefix);
					} else {
						ZEPHIR_INIT_NVAR(&prefixedPattern);
						ZEPHIR_CONCAT_VV(&prefixedPattern, &prefix, &pattern);
					}
				} else {
					ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
				}
				ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_3, 0, &prefixedPattern, &realHandler);
				zephir_check_call_status();
				_7$$15 = Z_TYPE_P(&methods) == IS_STRING;
				if (_7$$15) {
					_7$$15 = !ZEPHIR_IS_STRING(&methods, "");
				}
				_8$$15 = _7$$15;
				if (!(_8$$15)) {
					_8$$15 = Z_TYPE_P(&methods) == IS_ARRAY;
				}
				if (_8$$15) {
					ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &name);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &handlers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&handler);
	RETURN_THIS();
}

/**
 * Sets a handler that will be called when the router doesn't match any of
 * the defined routes
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, notFound)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_zval(this_ptr, ZEND_STRL("notFoundHandler"), handler);
	RETURN_THISW();
}

/**
 * Check if a service is registered in the internal services container using
 * the array syntax
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasservice", NULL, 0, alias);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Allows to obtain a shared service in the internal services container
 * using the array syntax
 *
 *```php
 * var_dump(
 *     $app["request"]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getservice", NULL, 0, alias);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Allows to register a shared service in the internal services container
 * using the array syntax
 *
 *```php
 *    $app["request"] = new \Phalcon\Http\Request();
 *```
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, *definition, definition_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&definition_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(alias)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias, &definition);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setservice", NULL, 0, alias, definition);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes a service from the internal services container using the array
 * syntax
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetUnset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, container, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 408);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	}
	ZEPHIR_CALL_METHOD(NULL, &container, "remove", NULL, 413, alias);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, options)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);
	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addoptions", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, patch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);
	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addpatch", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, post)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);
	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addpost", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, put)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);
	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addput", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * Sets externally the handler that must be called by the matched route
 *
 * @param callable activeHandler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler)
{
	zval *activeHandler, activeHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&activeHandler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(activeHandler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &activeHandler);


	zephir_update_property_zval(this_ptr, ZEND_STRL("activeHandler"), activeHandler);
}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Micro, setDI)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "application");
	ZEPHIR_CALL_METHOD(&_0, container, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "application");
		ZEPHIR_CALL_METHOD(NULL, container, "set", NULL, 0, &_2$$3, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets model binder
 *
 * ```php
 * $micro = new Micro($di);
 *
 * $micro->setModelBinder(
 *     new Binder(),
 *     'cache'
 * );
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Micro, setModelBinder)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelBinder, modelBinder_sub, *cache = NULL, cache_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(modelBinder, phalcon_mvc_model_binderinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(cache)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelBinder, &cache);
	if (!cache) {
		cache = &cache_sub;
		ZEPHIR_CPY_WRT(cache, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getservice", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_0$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("modelBinder"), modelBinder);
	RETURN_THIS();
}

/**
 * Appends a custom 'response' handler to be called instead of the default
 * response handler
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setResponseHandler)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_zval(this_ptr, ZEND_STRL("responseHandler"), handler);
	RETURN_THISW();
}

/**
 * Sets a service from the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, setService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *serviceName_param = NULL, *definition, definition_sub, *shared_param = NULL, container, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(serviceName)
		Z_PARAM_ZVAL(definition)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(shared)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &serviceName_param, &definition, &shared_param);
	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 408);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	}
	if (shared) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "set", NULL, 414, &serviceName, definition, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Stops the middleware execution avoiding than other middlewares be
 * executed
 */
PHP_METHOD(Phalcon_Mvc_Micro, stop)
{
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);



	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
	}
}

zend_object *zephir_init_properties_Phalcon_Mvc_Micro(zend_class_entry *class_type)
{
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("handlers"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("finishHandlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("finishHandlers"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("beforeHandlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("beforeHandlers"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("afterHandlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("afterHandlers"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("afterBindingHandlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("afterBindingHandlers"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

