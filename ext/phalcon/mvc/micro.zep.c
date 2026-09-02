
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, zephir_get_internal_ce(SL("phalcon\\di\\diinterface")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
 * @param callable|MiddlewareInterface handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, after)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handler);
	zephir_update_property_array_append(this_ptr, SL("afterBindingHandlers"), handler);
	RETURN_THISW();
}

/**
 * Appends a before middleware to be called before execute the route
 *
 * @param callable|MiddlewareInterface handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, before)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
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
	zval routePattern_zv, *handler, handler_sub, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "addDelete");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("errorHandler", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handler);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 976, handler);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
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
	zval routePattern_zv, *handler, handler_sub, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "addGet");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler)
{

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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelBinder", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 977, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, zephir_get_internal_ce(SL("phalcon\\events\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 978, eventsManager);
}

/**
 * Returns the internal handlers attached to the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getHandlers)
{

	RETURN_MEMBER_TYPED(getThis(), "handlers", IS_ARRAY);
}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Mvc_Micro, getModelBinder)
{

	RETURN_MEMBER(getThis(), "modelBinder");
}

/**
 * Returns the value returned by the executed handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue)
{

	RETURN_MEMBER(getThis(), "returnedValue");
}

/**
 * Returns the internal router used by the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter)
{
	zval _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("router", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 979, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "router");
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getsharedservice", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 979, &_1$$3);
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 979, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "clear", NULL, 0);
		zephir_check_call_status();
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 979, PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_5$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "removeextraslashes", NULL, 0, &_5$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "router");
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
	zval serviceName_zv, _0;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkdicontainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 980, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &serviceName_zv);
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
	zval serviceName_zv, _0;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkdicontainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 980, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getshared", NULL, 0, &serviceName_zv);
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
	zval _97$$63, _104$$68, _114$$73;
	zend_class_entry *_44$$25;
	zend_bool _100$$4, _37$$9, _42$$9, _53$$9, _64$$9, _78$$9, _31$$15, _38$$20, _49$$29, _59$$35, _65$$40, _73$$46, _79$$51, _94$$61, _101$$66, _120$$83, _121$$83;
	zval bindCacheKey;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, container, status, router, matchedRoute, handler, beforeHandlers, params, returnedValue, e, afterHandlers, notFoundHandler, finishHandlers, finish, before, after, response, modelBinder, routeName, realHandler, methodName, lazyReturned, afterBindingHandlers, afterBinding, _0, _106, _1$$3, _2$$4, _13$$4, _14$$4, _89$$4, _92$$4, *_93$$4, _99$$4, _3$$5, _4$$5, _5$$5, _6$$5, _7$$6, _8$$6, _9$$6, _10$$6, _11$$6, _12$$6, _15$$9, _16$$9, _18$$9, _29$$9, *_30$$9, _36$$9, _57$$9, *_58$$9, _63$$9, _71$$9, *_72$$9, _77$$9, _17$$10, _19$$11, _20$$11, _21$$11, _22$$11, _23$$12, _24$$12, _25$$12, _26$$12, _27$$12, _28$$12, _35$$15, _32$$18, _33$$18, _41$$20, _39$$23, _40$$23, _43$$25, _45$$27, _46$$28, _47$$28, _48$$26, _50$$30, _51$$30, _52$$30, _54$$33, _55$$33, _56$$33, _62$$35, _60$$38, _61$$38, _68$$40, _66$$43, _67$$43, _69$$45, _70$$45, _76$$46, _74$$49, _75$$49, _82$$51, _80$$54, _81$$54, _83$$56, _87$$56, _84$$57, _85$$57, _86$$57, _88$$59, _90$$60, _91$$60, _98$$61, _95$$64, _96$$64, _105$$66, _102$$69, _103$$69, _107$$71, _110$$71, _108$$72, _109$$72, _111$$73, _113$$73, _112$$74, _115$$81, _117$$81, _116$$82, _118$$84, _119$$84, _122$$83;
	zend_string *uri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&matchedRoute);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&beforeHandlers);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&returnedValue);
	ZVAL_UNDEF(&e);
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
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_89$$4);
	ZVAL_UNDEF(&_92$$4);
	ZVAL_UNDEF(&_99$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_57$$9);
	ZVAL_UNDEF(&_63$$9);
	ZVAL_UNDEF(&_71$$9);
	ZVAL_UNDEF(&_77$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_41$$20);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_40$$23);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_45$$27);
	ZVAL_UNDEF(&_46$$28);
	ZVAL_UNDEF(&_47$$28);
	ZVAL_UNDEF(&_48$$26);
	ZVAL_UNDEF(&_50$$30);
	ZVAL_UNDEF(&_51$$30);
	ZVAL_UNDEF(&_52$$30);
	ZVAL_UNDEF(&_54$$33);
	ZVAL_UNDEF(&_55$$33);
	ZVAL_UNDEF(&_56$$33);
	ZVAL_UNDEF(&_62$$35);
	ZVAL_UNDEF(&_60$$38);
	ZVAL_UNDEF(&_61$$38);
	ZVAL_UNDEF(&_68$$40);
	ZVAL_UNDEF(&_66$$43);
	ZVAL_UNDEF(&_67$$43);
	ZVAL_UNDEF(&_69$$45);
	ZVAL_UNDEF(&_70$$45);
	ZVAL_UNDEF(&_76$$46);
	ZVAL_UNDEF(&_74$$49);
	ZVAL_UNDEF(&_75$$49);
	ZVAL_UNDEF(&_82$$51);
	ZVAL_UNDEF(&_80$$54);
	ZVAL_UNDEF(&_81$$54);
	ZVAL_UNDEF(&_83$$56);
	ZVAL_UNDEF(&_87$$56);
	ZVAL_UNDEF(&_84$$57);
	ZVAL_UNDEF(&_85$$57);
	ZVAL_UNDEF(&_86$$57);
	ZVAL_UNDEF(&_88$$59);
	ZVAL_UNDEF(&_90$$60);
	ZVAL_UNDEF(&_91$$60);
	ZVAL_UNDEF(&_98$$61);
	ZVAL_UNDEF(&_95$$64);
	ZVAL_UNDEF(&_96$$64);
	ZVAL_UNDEF(&_105$$66);
	ZVAL_UNDEF(&_102$$69);
	ZVAL_UNDEF(&_103$$69);
	ZVAL_UNDEF(&_107$$71);
	ZVAL_UNDEF(&_110$$71);
	ZVAL_UNDEF(&_108$$72);
	ZVAL_UNDEF(&_109$$72);
	ZVAL_UNDEF(&_111$$73);
	ZVAL_UNDEF(&_113$$73);
	ZVAL_UNDEF(&_112$$74);
	ZVAL_UNDEF(&_115$$81);
	ZVAL_UNDEF(&_117$$81);
	ZVAL_UNDEF(&_116$$82);
	ZVAL_UNDEF(&_118$$84);
	ZVAL_UNDEF(&_119$$84);
	ZVAL_UNDEF(&_122$$83);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&_97$$63);
	ZVAL_UNDEF(&_104$$68);
	ZVAL_UNDEF(&_114$$73);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	static zend_string *_zephir_prop_12 = NULL;
	static zend_string *_zephir_prop_13 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("handlers", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("activeHandler", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("beforeHandlers", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("stopped", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("modelBinder", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("afterBindingHandlers", 20, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("returnedValue", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("afterHandlers", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("notFoundHandler", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("finishHandlers", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_12)) {
		_zephir_prop_12 = zend_string_init("errorHandler", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_13)) {
		_zephir_prop_13 = zend_string_init("responseHandler", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_INIT_VAR(&realHandler);
	ZVAL_NULL(&realHandler);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 980, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_micro_exceptions_containerrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Micro.zep", 363);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&returnedValue);
		ZVAL_NULL(&returnedValue);
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2$$4) != IS_NULL) {
			zephir_memory_observe(&_3$$5);
			zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC);
			if (zephir_instance_of_ev(&_3$$5, phalcon_events_manager_ce)) {
				zephir_read_property_cached(&_7$$6, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_9$$6);
				ZVAL_STRING(&_9$$6, "micro:beforeHandleRoute");
				ZVAL_NULL(&_10$$6);
				ZVAL_BOOL(&_11$$6, 1);
				ZVAL_BOOL(&_12$$6, 1);
				ZEPHIR_CALL_METHOD(&_8$$6, &_7$$6, "fire", NULL, 0, &_9$$6, this_ptr, &_10$$6, &_11$$6, &_12$$6);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$6)) {
					RETURN_MM_BOOL(0);
				}
			} else {
				zephir_read_property_cached(&_4$$5, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "micro:beforeHandleRoute");
				ZEPHIR_CALL_METHOD(&_5$$5, &_4$$5, "fire", NULL, 0, &_6$$5, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$5)) {
					RETURN_MM_BOOL(0);
				}
			}
		}
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "router");
		ZEPHIR_CALL_METHOD(&_13$$4, &container, "getshared", NULL, 0, &_14$$4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&router, &_13$$4);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri_zv);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getmatchedroute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&matchedRoute) != IS_NULL) {
			zephir_memory_observe(&handler);
			zephir_read_property_cached(&_15$$9, this_ptr, _zephir_prop_2, 981, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_16$$9, &matchedRoute, "getrouteid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&handler, &_15$$9, &_16$$9, 0)))) {
				ZEPHIR_INIT_VAR(&_17$$10);
				object_init_ex(&_17$$10, phalcon_mvc_micro_exceptions_nomatchedroutehandler_ce);
				ZEPHIR_CALL_METHOD(NULL, &_17$$10, "__construct", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_17$$10, "phalcon/Mvc/Micro.zep", 403);
				goto try_end_1;

			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 982, &handler);
			zephir_read_property_cached(&_18$$9, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_18$$9) != IS_NULL) {
				zephir_memory_observe(&_19$$11);
				zephir_read_property_cached(&_19$$11, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC);
				if (zephir_instance_of_ev(&_19$$11, phalcon_events_manager_ce)) {
					zephir_read_property_cached(&_23$$12, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&_25$$12);
					ZVAL_STRING(&_25$$12, "micro:beforeExecuteRoute");
					ZVAL_NULL(&_26$$12);
					ZVAL_BOOL(&_27$$12, 1);
					ZVAL_BOOL(&_28$$12, 1);
					ZEPHIR_CALL_METHOD(&_24$$12, &_23$$12, "fire", NULL, 0, &_25$$12, this_ptr, &_26$$12, &_27$$12, &_28$$12);
					zephir_check_call_status_or_jump(try_end_1);
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_24$$12)) {
						RETURN_MM_BOOL(0);
					}
				} else {
					zephir_read_property_cached(&_20$$11, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&_22$$11);
					ZVAL_STRING(&_22$$11, "micro:beforeExecuteRoute");
					ZEPHIR_CALL_METHOD(&_21$$11, &_20$$11, "fire", NULL, 0, &_22$$11, this_ptr);
					zephir_check_call_status_or_jump(try_end_1);
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_21$$11)) {
						RETURN_MM_BOOL(0);
					}
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_read_property_cached(&handler, this_ptr, _zephir_prop_3, 982, PH_NOISY_CC);
			}
			zephir_read_property_cached(&_29$$9, this_ptr, _zephir_prop_4, 983, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&beforeHandlers, &_29$$9);
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 984, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 984, &__$false);
			}
			zephir_is_iterable(&beforeHandlers, 0, "phalcon/Mvc/Micro.zep", 457);
			if (Z_TYPE_P(&beforeHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&beforeHandlers), _30$$9)
				{
					ZEPHIR_INIT_NVAR(&before);
					ZVAL_COPY(&before, _30$$9);
					_31$$15 = Z_TYPE_P(&before) == IS_OBJECT;
					if (_31$$15) {
						_31$$15 = zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_31$$15) {
						ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&before)))) {
							ZEPHIR_INIT_NVAR(&_32$$18);
							object_init_ex(&_32$$18, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_33$$18);
							ZVAL_STRING(&_33$$18, "before");
							ZEPHIR_CALL_METHOD(NULL, &_32$$18, "__construct", &_34, 0, &_33$$18);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_32$$18, "phalcon/Mvc/Micro.zep", 440);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &before);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property_cached(&_35$$15, this_ptr, _zephir_prop_5, 984, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_35$$15)) {
						RETURN_CCTOR(&status);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				_37$$9 = 1;
				while (1) {
					if (_37$$9) {
						_37$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_36$$9, &beforeHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_36$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&before, &beforeHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_38$$20 = Z_TYPE_P(&before) == IS_OBJECT;
						if (_38$$20) {
							_38$$20 = zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_38$$20) {
							ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&before)))) {
								ZEPHIR_INIT_NVAR(&_39$$23);
								object_init_ex(&_39$$23, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_40$$23);
								ZVAL_STRING(&_40$$23, "before");
								ZEPHIR_CALL_METHOD(NULL, &_39$$23, "__construct", &_34, 0, &_40$$23);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_39$$23, "phalcon/Mvc/Micro.zep", 440);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &before);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property_cached(&_41$$20, this_ptr, _zephir_prop_5, 984, PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_41$$20)) {
							RETURN_CCTOR(&status);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&before);
			ZEPHIR_CALL_METHOD(&params, &router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property_cached(&_29$$9, this_ptr, _zephir_prop_6, 977, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_29$$9);
			_42$$9 = Z_TYPE_P(&handler) == IS_OBJECT;
			if (_42$$9) {
				_42$$9 = zephir_is_instance_of(&handler, SL("Closure"));
			}
			if (_42$$9) {
				_44$$25 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_43$$25, _44$$25, "bind", NULL, 0, &handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&handler, &_43$$25);
				if (Z_TYPE_P(&modelBinder) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&routeName, &matchedRoute, "getname", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					if (Z_TYPE_P(&routeName) != IS_NULL) {
						ZEPHIR_INIT_VAR(&_45$$27);
						ZEPHIR_CONCAT_SV(&_45$$27, "_PHMB_", &routeName);
						zephir_get_strval(&bindCacheKey, &_45$$27);
					} else {
						ZEPHIR_CALL_METHOD(&_46$$28, &matchedRoute, "getpattern", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_INIT_VAR(&_47$$28);
						ZEPHIR_CONCAT_SV(&_47$$28, "_PHMB_", &_46$$28);
						zephir_get_strval(&bindCacheKey, &_47$$28);
					}
					ZEPHIR_CALL_METHOD(&_48$$26, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_48$$26);
				}
			}
			if (Z_TYPE_P(&handler) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&realHandler);
				zephir_array_fetch_long(&realHandler, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 488);
				_49$$29 = zephir_instance_of_ev(&realHandler, phalcon_mvc_controller_ce);
				if (_49$$29) {
					_49$$29 = Z_TYPE_P(&modelBinder) != IS_NULL;
				}
				if (_49$$29) {
					zephir_memory_observe(&methodName);
					zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 491);
					ZEPHIR_INIT_VAR(&_50$$30);
					zephir_get_class(&_50$$30, &realHandler, 0);
					ZEPHIR_INIT_VAR(&_51$$30);
					ZEPHIR_CONCAT_SVSV(&_51$$30, "_PHMB_", &_50$$30, "_", &methodName);
					zephir_get_strval(&bindCacheKey, &_51$$30);
					ZEPHIR_CALL_METHOD(&_52$$30, &modelBinder, "bindtohandler", NULL, 0, &realHandler, &params, &bindCacheKey, &methodName);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_52$$30);
				}
			}
			_53$$9 = Z_TYPE_P(&realHandler) != IS_NULL;
			if (_53$$9) {
				_53$$9 = zephir_instance_of_ev(&realHandler, phalcon_mvc_micro_lazyloader_ce);
			}
			if (_53$$9) {
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 508);
				ZEPHIR_CALL_METHOD(&lazyReturned, &realHandler, "callmethod", NULL, 0, &methodName, &params, &modelBinder);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				ZEPHIR_INIT_NVAR(&lazyReturned);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&lazyReturned, &handler, &params);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_CPY_WRT(&returnedValue, &lazyReturned);
			zephir_read_property_cached(&_29$$9, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_29$$9) != IS_NULL) {
				zephir_read_property_cached(&_54$$33, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_56$$33);
				ZVAL_STRING(&_56$$33, "micro:afterBinding");
				ZEPHIR_CALL_METHOD(&_55$$33, &_54$$33, "fire", NULL, 0, &_56$$33, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_55$$33)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property_cached(&_57$$9, this_ptr, _zephir_prop_7, 985, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterBindingHandlers, &_57$$9);
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 984, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 984, &__$false);
			}
			zephir_is_iterable(&afterBindingHandlers, 0, "phalcon/Mvc/Micro.zep", 569);
			if (Z_TYPE_P(&afterBindingHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterBindingHandlers), _58$$9)
				{
					ZEPHIR_INIT_NVAR(&afterBinding);
					ZVAL_COPY(&afterBinding, _58$$9);
					_59$$35 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
					if (_59$$35) {
						_59$$35 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_59$$35) {
						ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&afterBinding)))) {
							ZEPHIR_INIT_NVAR(&_60$$38);
							object_init_ex(&_60$$38, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_61$$38);
							ZVAL_STRING(&_61$$38, "afterBinding");
							ZEPHIR_CALL_METHOD(NULL, &_60$$38, "__construct", &_34, 0, &_61$$38);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_60$$38, "phalcon/Mvc/Micro.zep", 549);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property_cached(&_62$$35, this_ptr, _zephir_prop_5, 984, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_62$$35)) {
						RETURN_CCTOR(&status);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				_64$$9 = 1;
				while (1) {
					if (_64$$9) {
						_64$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_63$$9, &afterBindingHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_63$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&afterBinding, &afterBindingHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_65$$40 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
						if (_65$$40) {
							_65$$40 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_65$$40) {
							ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&afterBinding)))) {
								ZEPHIR_INIT_NVAR(&_66$$43);
								object_init_ex(&_66$$43, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_67$$43);
								ZVAL_STRING(&_67$$43, "afterBinding");
								ZEPHIR_CALL_METHOD(NULL, &_66$$43, "__construct", &_34, 0, &_67$$43);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_66$$43, "phalcon/Mvc/Micro.zep", 549);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property_cached(&_68$$40, this_ptr, _zephir_prop_5, 984, PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_68$$40)) {
							RETURN_CCTOR(&status);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&afterBinding);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 986, &returnedValue);
			zephir_read_property_cached(&_57$$9, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_57$$9) != IS_NULL) {
				zephir_read_property_cached(&_69$$45, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_70$$45);
				ZVAL_STRING(&_70$$45, "micro:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(NULL, &_69$$45, "fire", NULL, 0, &_70$$45, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
			}
			zephir_read_property_cached(&_71$$9, this_ptr, _zephir_prop_9, 987, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterHandlers, &_71$$9);
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 984, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 984, &__$false);
			}
			zephir_is_iterable(&afterHandlers, 0, "phalcon/Mvc/Micro.zep", 606);
			if (Z_TYPE_P(&afterHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterHandlers), _72$$9)
				{
					ZEPHIR_INIT_NVAR(&after);
					ZVAL_COPY(&after, _72$$9);
					_73$$46 = Z_TYPE_P(&after) == IS_OBJECT;
					if (_73$$46) {
						_73$$46 = zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_73$$46) {
						ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&after)))) {
							ZEPHIR_INIT_NVAR(&_74$$49);
							object_init_ex(&_74$$49, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_75$$49);
							ZVAL_STRING(&_75$$49, "after");
							ZEPHIR_CALL_METHOD(NULL, &_74$$49, "__construct", &_34, 0, &_75$$49);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_74$$49, "phalcon/Mvc/Micro.zep", 593);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &after);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property_cached(&_76$$46, this_ptr, _zephir_prop_5, 984, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_76$$46)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				_78$$9 = 1;
				while (1) {
					if (_78$$9) {
						_78$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_77$$9, &afterHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_77$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&after, &afterHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_79$$51 = Z_TYPE_P(&after) == IS_OBJECT;
						if (_79$$51) {
							_79$$51 = zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_79$$51) {
							ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&after)))) {
								ZEPHIR_INIT_NVAR(&_80$$54);
								object_init_ex(&_80$$54, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_81$$54);
								ZVAL_STRING(&_81$$54, "after");
								ZEPHIR_CALL_METHOD(NULL, &_80$$54, "__construct", &_34, 0, &_81$$54);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_80$$54, "phalcon/Mvc/Micro.zep", 593);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &after);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property_cached(&_82$$51, this_ptr, _zephir_prop_5, 984, PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_82$$51)) {
							break;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&after);
		} else {
			zephir_read_property_cached(&_83$$56, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_83$$56) != IS_NULL) {
				zephir_read_property_cached(&_84$$57, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_86$$57);
				ZVAL_STRING(&_86$$57, "micro:beforeNotFound");
				ZEPHIR_CALL_METHOD(&_85$$57, &_84$$57, "fire", NULL, 0, &_86$$57, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_85$$57)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property_cached(&_87$$56, this_ptr, _zephir_prop_10, 988, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&notFoundHandler, &_87$$56);
			if (UNEXPECTED(!(zephir_is_callable(&notFoundHandler)))) {
				ZEPHIR_INIT_VAR(&_88$$59);
				object_init_ex(&_88$$59, phalcon_mvc_micro_exceptions_notfoundhandlernotcallable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_88$$59, "__construct", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_88$$59, "phalcon/Mvc/Micro.zep", 622);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(&returnedValue);
			ZEPHIR_CALL_USER_FUNC(&returnedValue, &notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property_cached(&_89$$4, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_89$$4) != IS_NULL) {
			zephir_read_property_cached(&_90$$60, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_91$$60);
			ZVAL_STRING(&_91$$60, "micro:afterHandleRoute");
			ZEPHIR_CALL_METHOD(NULL, &_90$$60, "fire", NULL, 0, &_91$$60, this_ptr, &returnedValue);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property_cached(&_92$$4, this_ptr, _zephir_prop_11, 989, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&finishHandlers, &_92$$4);
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 984, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 984, &__$false);
		}
		zephir_is_iterable(&finishHandlers, 0, "phalcon/Mvc/Micro.zep", 674);
		if (Z_TYPE_P(&finishHandlers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&finishHandlers), _93$$4)
			{
				ZEPHIR_INIT_NVAR(&finish);
				ZVAL_COPY(&finish, _93$$4);
				_94$$61 = Z_TYPE_P(&finish) == IS_OBJECT;
				if (_94$$61) {
					_94$$61 = zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce);
				}
				if (_94$$61) {
					ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
					zephir_check_call_status_or_jump(try_end_1);
				} else {
					if (UNEXPECTED(!(zephir_is_callable(&finish)))) {
						ZEPHIR_INIT_NVAR(&_95$$64);
						object_init_ex(&_95$$64, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
						ZEPHIR_INIT_NVAR(&_96$$64);
						ZVAL_STRING(&_96$$64, "finish");
						ZEPHIR_CALL_METHOD(NULL, &_95$$64, "__construct", &_34, 0, &_96$$64);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_95$$64, "phalcon/Mvc/Micro.zep", 655);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(&_97$$63);
					zephir_create_array(&_97$$63, 1, 0);
					zephir_array_fast_append(&_97$$63, this_ptr);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &_97$$63);
					zephir_check_call_status_or_jump(try_end_1);
				}
				zephir_read_property_cached(&_98$$61, this_ptr, _zephir_prop_5, 984, PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_98$$61)) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "rewind", NULL, 0);
			zephir_check_call_status();
			_100$$4 = 1;
			while (1) {
				if (_100$$4) {
					_100$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_99$$4, &finishHandlers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_99$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&finish, &finishHandlers, "current", NULL, 0);
				zephir_check_call_status();
					_101$$66 = Z_TYPE_P(&finish) == IS_OBJECT;
					if (_101$$66) {
						_101$$66 = zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_101$$66) {
						ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&finish)))) {
							ZEPHIR_INIT_NVAR(&_102$$69);
							object_init_ex(&_102$$69, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_103$$69);
							ZVAL_STRING(&_103$$69, "finish");
							ZEPHIR_CALL_METHOD(NULL, &_102$$69, "__construct", &_34, 0, &_103$$69);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_102$$69, "phalcon/Mvc/Micro.zep", 655);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&_104$$68);
						zephir_create_array(&_104$$68, 1, 0);
						zephir_array_fast_append(&_104$$68, this_ptr);
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &_104$$68);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property_cached(&_105$$66, this_ptr, _zephir_prop_5, 984, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_105$$66)) {
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&finish);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_106);
		ZVAL_OBJ(&_106, EG(exception));
		Z_ADDREF_P(&_106);
		if (zephir_is_instance_of(&_106, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_106);
			zephir_read_property_cached(&_107$$71, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_107$$71) != IS_NULL) {
				zephir_read_property_cached(&_108$$72, this_ptr, _zephir_prop_1, 978, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_109$$72);
				ZVAL_STRING(&_109$$72, "micro:beforeException");
				ZEPHIR_CALL_METHOD(NULL, &_108$$72, "fire", NULL, 0, &_109$$72, this_ptr, &e);
				zephir_check_call_status();
			}
			zephir_read_property_cached(&_110$$71, this_ptr, _zephir_prop_12, 976, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_110$$71) != IS_NULL) {
				zephir_read_property_cached(&_111$$73, this_ptr, _zephir_prop_12, 976, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(!(zephir_is_callable(&_111$$73)))) {
					ZEPHIR_INIT_VAR(&_112$$74);
					object_init_ex(&_112$$74, phalcon_mvc_micro_exceptions_errorhandlernotcallable_ce);
					ZEPHIR_CALL_METHOD(NULL, &_112$$74, "__construct", NULL, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_112$$74, "phalcon/Mvc/Micro.zep", 691);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_113$$73, this_ptr, _zephir_prop_12, 976, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_114$$73);
				zephir_create_array(&_114$$73, 1, 0);
				zephir_array_fast_append(&_114$$73, &e);
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &_113$$73, &_114$$73);
				zephir_check_call_status();
				if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce))) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 704);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 708);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
					zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 713);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_13, 990, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property_cached(&_115$$81, this_ptr, _zephir_prop_13, 990, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(!(zephir_is_callable(&_115$$81)))) {
			ZEPHIR_INIT_VAR(&_116$$82);
			object_init_ex(&_116$$82, phalcon_mvc_micro_exceptions_responsehandlernotcallable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_116$$82, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_116$$82, "phalcon/Mvc/Micro.zep", 724);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_117$$81, this_ptr, _zephir_prop_13, 990, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&returnedValue);
		ZEPHIR_CALL_USER_FUNC(&returnedValue, &_117$$81);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(&returnedValue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_119$$84);
			ZVAL_STRING(&_119$$84, "response");
			ZEPHIR_CALL_METHOD(&_118$$84, &container, "getshared", NULL, 0, &_119$$84);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_118$$84);
			ZEPHIR_CALL_METHOD(&_118$$84, &response, "issent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_118$$84))) {
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &returnedValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
		_120$$83 = Z_TYPE_P(&returnedValue) == IS_OBJECT;
		if (_120$$83) {
			_120$$83 = zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce);
		}
		_121$$83 = _120$$83;
		if (_121$$83) {
			ZEPHIR_CALL_METHOD(&_122$$83, &returnedValue, "issent", NULL, 0);
			zephir_check_call_status();
			_121$$83 = !zephir_is_true(&_122$$83);
		}
		if (_121$$83) {
			ZEPHIR_CALL_METHOD(NULL, &returnedValue, "send", NULL, 0);
			zephir_check_call_status();
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
	zval serviceName_zv, _0;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkdicontainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 980, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &serviceName_zv);
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
	zval routePattern_zv, *handler, handler_sub, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "addHead");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
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
	zval routePattern_zv, *handler, handler_sub, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "add");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Mounts a collection of handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount)
{
	zend_bool _10, _7$$7, _8$$7, _13$$15, _14$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, mainHandler, handlers, lazyHandler, prefix, methods, pattern, subHandler, realHandler, prefixedPattern, route, handler, name, _2, *_3, _9, _0$$3, _1$$4, _4$$8, _11$$16, _12$$15;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_11$$16);
	ZVAL_UNDEF(&_12$$15);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(collection, zephir_get_internal_ce(SL("phalcon\\mvc\\micro\\collectioninterface")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &collection);
	ZEPHIR_CALL_METHOD(&mainHandler, collection, "gethandler", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&mainHandler))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_micro_exceptions_missingcollectionmainhandler_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Micro.zep", 797);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "gethandlers", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&handlers))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_micro_exceptions_nohandlerstomount_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Micro.zep", 803);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, collection, "islazy", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&lazyHandler);
		object_init_ex(&lazyHandler, phalcon_mvc_micro_lazyloader_ce);
		ZEPHIR_CALL_METHOD(NULL, &lazyHandler, "__construct", NULL, 0, &mainHandler);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&lazyHandler, &mainHandler);
	}
	ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&handlers, 0, "phalcon/Mvc/Micro.zep", 859);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _3)
		{
			ZEPHIR_INIT_NVAR(&handler);
			ZVAL_COPY(&handler, _3);
			if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_4$$8);
				object_init_ex(&_4$$8, phalcon_mvc_micro_exceptions_invalidregisteredhandler_ce);
				ZEPHIR_CALL_METHOD(NULL, &_4$$8, "__construct", &_5, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$8, "phalcon/Mvc/Micro.zep", 822);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 825);
			ZEPHIR_OBS_NVAR(&pattern);
			zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 826);
			ZEPHIR_OBS_NVAR(&subHandler);
			zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 827);
			ZEPHIR_OBS_NVAR(&name);
			zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 828);
			ZEPHIR_INIT_NVAR(&realHandler);
			zephir_create_array(&realHandler, 2, 0);
			zephir_array_fast_append(&realHandler, &lazyHandler);
			zephir_array_fast_append(&realHandler, &subHandler);
			if (!(ZEPHIR_IS_EMPTY(&prefix))) {
				if (ZEPHIR_IS_STRING_IDENTICAL(&pattern, "/")) {
					ZEPHIR_CPY_WRT(&prefixedPattern, &prefix);
				} else {
					ZEPHIR_INIT_NVAR(&prefixedPattern);
					ZEPHIR_CONCAT_VV(&prefixedPattern, &prefix, &pattern);
				}
			} else {
				ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
			}
			ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_6, 0, &prefixedPattern, &realHandler);
			zephir_check_call_status();
			_7$$7 = Z_TYPE_P(&methods) == IS_STRING;
			if (_7$$7) {
				_7$$7 = !ZEPHIR_IS_STRING_IDENTICAL(&methods, "");
			}
			_8$$7 = _7$$7;
			if (!(_8$$7)) {
				_8$$7 = Z_TYPE_P(&methods) == IS_ARRAY;
			}
			if (_8$$7) {
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
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &handlers, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &handlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&handler, &handlers, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_11$$16);
					object_init_ex(&_11$$16, phalcon_mvc_micro_exceptions_invalidregisteredhandler_ce);
					ZEPHIR_CALL_METHOD(NULL, &_11$$16, "__construct", &_5, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$16, "phalcon/Mvc/Micro.zep", 822);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methods);
				zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 825);
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 826);
				ZEPHIR_OBS_NVAR(&subHandler);
				zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 827);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 828);
				ZEPHIR_INIT_NVAR(&_12$$15);
				zephir_create_array(&_12$$15, 2, 0);
				zephir_array_fast_append(&_12$$15, &lazyHandler);
				zephir_array_fast_append(&_12$$15, &subHandler);
				ZEPHIR_CPY_WRT(&realHandler, &_12$$15);
				if (!(ZEPHIR_IS_EMPTY(&prefix))) {
					if (ZEPHIR_IS_STRING_IDENTICAL(&pattern, "/")) {
						ZEPHIR_CPY_WRT(&prefixedPattern, &prefix);
					} else {
						ZEPHIR_INIT_NVAR(&prefixedPattern);
						ZEPHIR_CONCAT_VV(&prefixedPattern, &prefix, &pattern);
					}
				} else {
					ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
				}
				ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_6, 0, &prefixedPattern, &realHandler);
				zephir_check_call_status();
				_13$$15 = Z_TYPE_P(&methods) == IS_STRING;
				if (_13$$15) {
					_13$$15 = !ZEPHIR_IS_STRING_IDENTICAL(&methods, "");
				}
				_14$$15 = _13$$15;
				if (!(_14$$15)) {
					_14$$15 = Z_TYPE_P(&methods) == IS_ARRAY;
				}
				if (_14$$15) {
					ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &name);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&handler);
	RETURN_THIS();
}

/**
 * Sets a handler that will be called when the router does not match any of
 * the defined routes
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, notFound)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("notFoundHandler", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handler);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 988, handler);
	RETURN_THISW();
}

/**
 * Check if a service is registered in the internal services container using
 * the array syntax
 *
 * @param mixed offset
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasservice", NULL, 0, offset);
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
 *
 * @param mixed offset
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getservice", NULL, 0, offset);
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
	zval offset_sub, value_sub;
	zval *offset, *value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &offset, &value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setservice", NULL, 0, offset, value);
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
	zval offset_sub, _0;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkdicontainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 980, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, offset);
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
	zval routePattern_zv, *handler, handler_sub, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "addOptions");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
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
	zval routePattern_zv, *handler, handler_sub, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "addPatch");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
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
	zval routePattern_zv, *handler, handler_sub, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "addPost");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
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
	zval routePattern_zv, *handler, handler_sub, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "addPut");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addroute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("activeHandler", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(activeHandler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &activeHandler);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 982, activeHandler);
	RETURN_THISW();
}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Micro, setDI)
{
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, zephir_get_internal_ce(SL("phalcon\\di\\diinterface")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 980, container);
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
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelBinder, modelBinder_sub, *cache = NULL, cache_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelBinder", 11, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(modelBinder, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\binderinterface")))
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(cache)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	_1 = Z_TYPE_P(cache) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(cache, phalcon_cache_adapter_adapterinterface_ce);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 977, modelBinder);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("responseHandler", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handler);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 990, handler);
	RETURN_THISW();
}

/**
 * Sets a service from the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, setService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isShared;
	zval serviceName_zv, *definition, definition_sub, *isShared_param = NULL, _0, _1;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(serviceName)
		Z_PARAM_ZVAL(definition)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isShared)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		isShared_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	if (!isShared_param) {
		isShared = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkdicontainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 980, PH_NOISY_CC | PH_READONLY);
	if (isShared) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&_0, "set", NULL, 0, &serviceName_zv, definition, &_1);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("stopped", 7, 1);
	}
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 984, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 984, &__$false);
	}
}

/**
 * Helper method to route an action
 *
 * @param string         method
 * @param string         routePattern
 * @param array|callable handler
 *
 * @return RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro, addRoute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *method = NULL, *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(method)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_ZVAL(&route, &router, &method_zv, NULL, 0, &routePattern_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);
}

/**
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_Micro, checkDiContainer)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 980, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 980, &_1$$3);
	}
	ZEPHIR_MM_RESTORE();
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
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

