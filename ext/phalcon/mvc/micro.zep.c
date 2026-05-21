
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
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
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
	zval routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "adddelete", NULL, 0, &routePattern_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
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
	zval routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addget", NULL, 0, &routePattern_zv);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "router");
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getsharedservice", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("router"), &_1$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "clear", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
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
	zval serviceName_zv, _0, _2, _1$$3;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "get", NULL, 0, &serviceName_zv);
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
	zval serviceName_zv, _0, _2, _1$$3;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "getshared", NULL, 0, &serviceName_zv);
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
	zval _81$$59, _86$$64, _96$$69;
	zend_class_entry *_29$$21;
	zend_bool _27$$7, _38$$7, _18$$11, _23$$16, _34$$25, _45$$31, _49$$36, _58$$42, _62$$47, _78$$57, _83$$62, _102$$79, _103$$79;
	zval bindCacheKey;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, container, status, router, matchedRoute, handler, beforeHandlers, params, returnedValue, e, afterHandlers, notFoundHandler, finishHandlers, finish, before, after, response, modelBinder, routeName, realHandler, methodName, lazyReturned, afterBindingHandlers, afterBinding, _0, _88, _1$$3, _2$$4, _6$$4, _7$$4, _72$$4, _75$$4, *_76$$4, _77$$4, _3$$5, _4$$5, _5$$5, _8$$7, _9$$7, _11$$7, _15$$7, *_16$$7, _17$$7, _42$$7, *_43$$7, _44$$7, _55$$7, *_56$$7, _57$$7, _10$$8, _12$$9, _13$$9, _14$$9, _22$$11, _19$$14, _20$$14, _26$$16, _24$$19, _25$$19, _28$$21, _30$$23, _31$$24, _32$$24, _33$$22, _35$$26, _36$$26, _37$$26, _39$$29, _40$$29, _41$$29, _48$$31, _46$$34, _47$$34, _52$$36, _50$$39, _51$$39, _53$$41, _54$$41, _61$$42, _59$$45, _60$$45, _65$$47, _63$$50, _64$$50, _66$$52, _70$$52, _67$$53, _68$$53, _69$$53, _71$$55, _73$$56, _74$$56, _82$$57, _79$$60, _80$$60, _87$$62, _84$$65, _85$$65, _89$$67, _92$$67, _90$$68, _91$$68, _93$$69, _95$$69, _94$$70, _97$$77, _99$$77, _98$$78, _100$$80, _101$$80, _104$$79;
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
	ZVAL_UNDEF(&_88);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_72$$4);
	ZVAL_UNDEF(&_75$$4);
	ZVAL_UNDEF(&_77$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_42$$7);
	ZVAL_UNDEF(&_44$$7);
	ZVAL_UNDEF(&_55$$7);
	ZVAL_UNDEF(&_57$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_32$$24);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_39$$29);
	ZVAL_UNDEF(&_40$$29);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_48$$31);
	ZVAL_UNDEF(&_46$$34);
	ZVAL_UNDEF(&_47$$34);
	ZVAL_UNDEF(&_52$$36);
	ZVAL_UNDEF(&_50$$39);
	ZVAL_UNDEF(&_51$$39);
	ZVAL_UNDEF(&_53$$41);
	ZVAL_UNDEF(&_54$$41);
	ZVAL_UNDEF(&_61$$42);
	ZVAL_UNDEF(&_59$$45);
	ZVAL_UNDEF(&_60$$45);
	ZVAL_UNDEF(&_65$$47);
	ZVAL_UNDEF(&_63$$50);
	ZVAL_UNDEF(&_64$$50);
	ZVAL_UNDEF(&_66$$52);
	ZVAL_UNDEF(&_70$$52);
	ZVAL_UNDEF(&_67$$53);
	ZVAL_UNDEF(&_68$$53);
	ZVAL_UNDEF(&_69$$53);
	ZVAL_UNDEF(&_71$$55);
	ZVAL_UNDEF(&_73$$56);
	ZVAL_UNDEF(&_74$$56);
	ZVAL_UNDEF(&_82$$57);
	ZVAL_UNDEF(&_79$$60);
	ZVAL_UNDEF(&_80$$60);
	ZVAL_UNDEF(&_87$$62);
	ZVAL_UNDEF(&_84$$65);
	ZVAL_UNDEF(&_85$$65);
	ZVAL_UNDEF(&_89$$67);
	ZVAL_UNDEF(&_92$$67);
	ZVAL_UNDEF(&_90$$68);
	ZVAL_UNDEF(&_91$$68);
	ZVAL_UNDEF(&_93$$69);
	ZVAL_UNDEF(&_95$$69);
	ZVAL_UNDEF(&_94$$70);
	ZVAL_UNDEF(&_97$$77);
	ZVAL_UNDEF(&_99$$77);
	ZVAL_UNDEF(&_98$$78);
	ZVAL_UNDEF(&_100$$80);
	ZVAL_UNDEF(&_101$$80);
	ZVAL_UNDEF(&_104$$79);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&_81$$59);
	ZVAL_UNDEF(&_86$$64);
	ZVAL_UNDEF(&_96$$69);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_micro_exceptions_containerrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Micro.zep", 405);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&returnedValue);
		ZVAL_NULL(&returnedValue);
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2$$4) != IS_NULL) {
			zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "micro:beforeHandleRoute");
			ZEPHIR_CALL_METHOD(&_4$$5, &_3$$5, "fire", NULL, 0, &_5$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$5)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "router");
		ZEPHIR_CALL_METHOD(&_6$$4, &container, "getshared", NULL, 0, &_7$$4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&router, &_6$$4);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri_zv);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getmatchedroute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&matchedRoute) != IS_NULL) {
			zephir_memory_observe(&handler);
			zephir_read_property(&_8$$7, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_9$$7, &matchedRoute, "getrouteid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&handler, &_8$$7, &_9$$7, 0)))) {
				ZEPHIR_INIT_VAR(&_10$$8);
				object_init_ex(&_10$$8, phalcon_mvc_micro_exceptions_nomatchedroutehandler_ce);
				ZEPHIR_CALL_METHOD(NULL, &_10$$8, "__construct", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_10$$8, "phalcon/Mvc/Micro.zep", 437);
				goto try_end_1;

			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("activeHandler"), &handler);
			zephir_read_property(&_11$$7, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_11$$7) != IS_NULL) {
				zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_14$$9);
				ZVAL_STRING(&_14$$9, "micro:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_13$$9, &_12$$9, "fire", NULL, 0, &_14$$9, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$9)) {
					RETURN_MM_BOOL(0);
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_read_property(&handler, this_ptr, ZEND_STRL("activeHandler"), PH_NOISY_CC);
			}
			zephir_read_property(&_15$$7, this_ptr, ZEND_STRL("beforeHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&beforeHandlers, &_15$$7);
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
			}
			zephir_is_iterable(&beforeHandlers, 0, "phalcon/Mvc/Micro.zep", 487);
			if (Z_TYPE_P(&beforeHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&beforeHandlers), _16$$7)
				{
					ZEPHIR_INIT_NVAR(&before);
					ZVAL_COPY(&before, _16$$7);
					_18$$11 = Z_TYPE_P(&before) == IS_OBJECT;
					if (_18$$11) {
						_18$$11 = zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_18$$11) {
						ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&before)))) {
							ZEPHIR_INIT_NVAR(&_19$$14);
							object_init_ex(&_19$$14, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_20$$14);
							ZVAL_STRING(&_20$$14, "before");
							ZEPHIR_CALL_METHOD(NULL, &_19$$14, "__construct", &_21, 0, &_20$$14);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_19$$14, "phalcon/Mvc/Micro.zep", 470);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &before);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property(&_22$$11, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_22$$11)) {
						RETURN_CCTOR(&status);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_17$$7, &beforeHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_17$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&before, &beforeHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_23$$16 = Z_TYPE_P(&before) == IS_OBJECT;
						if (_23$$16) {
							_23$$16 = zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_23$$16) {
							ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&before)))) {
								ZEPHIR_INIT_NVAR(&_24$$19);
								object_init_ex(&_24$$19, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_25$$19);
								ZVAL_STRING(&_25$$19, "before");
								ZEPHIR_CALL_METHOD(NULL, &_24$$19, "__construct", &_21, 0, &_25$$19);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_24$$19, "phalcon/Mvc/Micro.zep", 470);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &before);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property(&_26$$16, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_26$$16)) {
							RETURN_CCTOR(&status);
						}
					ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&before);
			ZEPHIR_CALL_METHOD(&params, &router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property(&_15$$7, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_15$$7);
			_27$$7 = Z_TYPE_P(&handler) == IS_OBJECT;
			if (_27$$7) {
				_27$$7 = zephir_is_instance_of(&handler, SL("Closure"));
			}
			if (_27$$7) {
				_29$$21 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_28$$21, _29$$21, "bind", NULL, 0, &handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&handler, &_28$$21);
				if (Z_TYPE_P(&modelBinder) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&routeName, &matchedRoute, "getname", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					if (Z_TYPE_P(&routeName) != IS_NULL) {
						ZEPHIR_INIT_VAR(&_30$$23);
						ZEPHIR_CONCAT_SV(&_30$$23, "_PHMB_", &routeName);
						zephir_get_strval(&bindCacheKey, &_30$$23);
					} else {
						ZEPHIR_CALL_METHOD(&_31$$24, &matchedRoute, "getpattern", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_INIT_VAR(&_32$$24);
						ZEPHIR_CONCAT_SV(&_32$$24, "_PHMB_", &_31$$24);
						zephir_get_strval(&bindCacheKey, &_32$$24);
					}
					ZEPHIR_CALL_METHOD(&_33$$22, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_33$$22);
				}
			}
			if (Z_TYPE_P(&handler) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&realHandler);
				zephir_array_fetch_long(&realHandler, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 518);
				_34$$25 = zephir_instance_of_ev(&realHandler, phalcon_mvc_controller_ce);
				if (_34$$25) {
					_34$$25 = Z_TYPE_P(&modelBinder) != IS_NULL;
				}
				if (_34$$25) {
					zephir_memory_observe(&methodName);
					zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 521);
					ZEPHIR_INIT_VAR(&_35$$26);
					zephir_get_class(&_35$$26, &realHandler, 0);
					ZEPHIR_INIT_VAR(&_36$$26);
					ZEPHIR_CONCAT_SVSV(&_36$$26, "_PHMB_", &_35$$26, "_", &methodName);
					zephir_get_strval(&bindCacheKey, &_36$$26);
					ZEPHIR_CALL_METHOD(&_37$$26, &modelBinder, "bindtohandler", NULL, 0, &realHandler, &params, &bindCacheKey, &methodName);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_37$$26);
				}
			}
			_38$$7 = Z_TYPE_P(&realHandler) != IS_NULL;
			if (_38$$7) {
				_38$$7 = zephir_instance_of_ev(&realHandler, phalcon_mvc_micro_lazyloader_ce);
			}
			if (_38$$7) {
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 538);
				ZEPHIR_CALL_METHOD(&lazyReturned, &realHandler, "callmethod", NULL, 0, &methodName, &params, &modelBinder);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				ZEPHIR_INIT_NVAR(&lazyReturned);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&lazyReturned, &handler, &params);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_CPY_WRT(&returnedValue, &lazyReturned);
			zephir_read_property(&_15$$7, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_15$$7) != IS_NULL) {
				zephir_read_property(&_39$$29, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_41$$29);
				ZVAL_STRING(&_41$$29, "micro:afterBinding");
				ZEPHIR_CALL_METHOD(&_40$$29, &_39$$29, "fire", NULL, 0, &_41$$29, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_40$$29)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property(&_42$$7, this_ptr, ZEND_STRL("afterBindingHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterBindingHandlers, &_42$$7);
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
			}
			zephir_is_iterable(&afterBindingHandlers, 0, "phalcon/Mvc/Micro.zep", 599);
			if (Z_TYPE_P(&afterBindingHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterBindingHandlers), _43$$7)
				{
					ZEPHIR_INIT_NVAR(&afterBinding);
					ZVAL_COPY(&afterBinding, _43$$7);
					_45$$31 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
					if (_45$$31) {
						_45$$31 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_45$$31) {
						ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&afterBinding)))) {
							ZEPHIR_INIT_NVAR(&_46$$34);
							object_init_ex(&_46$$34, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_47$$34);
							ZVAL_STRING(&_47$$34, "afterBinding");
							ZEPHIR_CALL_METHOD(NULL, &_46$$34, "__construct", &_21, 0, &_47$$34);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_46$$34, "phalcon/Mvc/Micro.zep", 579);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property(&_48$$31, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_48$$31)) {
						RETURN_CCTOR(&status);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_44$$7, &afterBindingHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_44$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&afterBinding, &afterBindingHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_49$$36 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
						if (_49$$36) {
							_49$$36 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_49$$36) {
							ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&afterBinding)))) {
								ZEPHIR_INIT_NVAR(&_50$$39);
								object_init_ex(&_50$$39, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_51$$39);
								ZVAL_STRING(&_51$$39, "afterBinding");
								ZEPHIR_CALL_METHOD(NULL, &_50$$39, "__construct", &_21, 0, &_51$$39);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_50$$39, "phalcon/Mvc/Micro.zep", 579);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property(&_52$$36, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_52$$36)) {
							RETURN_CCTOR(&status);
						}
					ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&afterBinding);
			zephir_update_property_zval(this_ptr, ZEND_STRL("returnedValue"), &returnedValue);
			zephir_read_property(&_42$$7, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_42$$7) != IS_NULL) {
				zephir_read_property(&_53$$41, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_54$$41);
				ZVAL_STRING(&_54$$41, "micro:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(NULL, &_53$$41, "fire", NULL, 0, &_54$$41, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
			}
			zephir_read_property(&_55$$7, this_ptr, ZEND_STRL("afterHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterHandlers, &_55$$7);
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
			}
			zephir_is_iterable(&afterHandlers, 0, "phalcon/Mvc/Micro.zep", 636);
			if (Z_TYPE_P(&afterHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterHandlers), _56$$7)
				{
					ZEPHIR_INIT_NVAR(&after);
					ZVAL_COPY(&after, _56$$7);
					_58$$42 = Z_TYPE_P(&after) == IS_OBJECT;
					if (_58$$42) {
						_58$$42 = zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_58$$42) {
						ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&after)))) {
							ZEPHIR_INIT_NVAR(&_59$$45);
							object_init_ex(&_59$$45, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_60$$45);
							ZVAL_STRING(&_60$$45, "after");
							ZEPHIR_CALL_METHOD(NULL, &_59$$45, "__construct", &_21, 0, &_60$$45);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_59$$45, "phalcon/Mvc/Micro.zep", 623);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &after);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property(&_61$$42, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_61$$42)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_57$$7, &afterHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_57$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&after, &afterHandlers, "current", NULL, 0);
					zephir_check_call_status();
						_62$$47 = Z_TYPE_P(&after) == IS_OBJECT;
						if (_62$$47) {
							_62$$47 = zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_62$$47) {
							ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&after)))) {
								ZEPHIR_INIT_NVAR(&_63$$50);
								object_init_ex(&_63$$50, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_64$$50);
								ZVAL_STRING(&_64$$50, "after");
								ZEPHIR_CALL_METHOD(NULL, &_63$$50, "__construct", &_21, 0, &_64$$50);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_63$$50, "phalcon/Mvc/Micro.zep", 623);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &after);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property(&_65$$47, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_65$$47)) {
							break;
						}
					ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&after);
		} else {
			zephir_read_property(&_66$$52, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_66$$52) != IS_NULL) {
				zephir_read_property(&_67$$53, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_69$$53);
				ZVAL_STRING(&_69$$53, "micro:beforeNotFound");
				ZEPHIR_CALL_METHOD(&_68$$53, &_67$$53, "fire", NULL, 0, &_69$$53, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_68$$53)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property(&_70$$52, this_ptr, ZEND_STRL("notFoundHandler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&notFoundHandler, &_70$$52);
			if (UNEXPECTED(!(zephir_is_callable(&notFoundHandler)))) {
				ZEPHIR_INIT_VAR(&_71$$55);
				object_init_ex(&_71$$55, phalcon_mvc_micro_exceptions_notfoundhandlernotcallable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_71$$55, "__construct", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_71$$55, "phalcon/Mvc/Micro.zep", 652);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(&returnedValue);
			ZEPHIR_CALL_USER_FUNC(&returnedValue, &notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property(&_72$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_72$$4) != IS_NULL) {
			zephir_read_property(&_73$$56, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_74$$56);
			ZVAL_STRING(&_74$$56, "micro:afterHandleRoute");
			ZEPHIR_CALL_METHOD(NULL, &_73$$56, "fire", NULL, 0, &_74$$56, this_ptr, &returnedValue);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property(&_75$$4, this_ptr, ZEND_STRL("finishHandlers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&finishHandlers, &_75$$4);
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
		}
		zephir_is_iterable(&finishHandlers, 0, "phalcon/Mvc/Micro.zep", 704);
		if (Z_TYPE_P(&finishHandlers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&finishHandlers), _76$$4)
			{
				ZEPHIR_INIT_NVAR(&finish);
				ZVAL_COPY(&finish, _76$$4);
				_78$$57 = Z_TYPE_P(&finish) == IS_OBJECT;
				if (_78$$57) {
					_78$$57 = zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce);
				}
				if (_78$$57) {
					ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
					zephir_check_call_status_or_jump(try_end_1);
				} else {
					if (UNEXPECTED(!(zephir_is_callable(&finish)))) {
						ZEPHIR_INIT_NVAR(&_79$$60);
						object_init_ex(&_79$$60, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
						ZEPHIR_INIT_NVAR(&_80$$60);
						ZVAL_STRING(&_80$$60, "finish");
						ZEPHIR_CALL_METHOD(NULL, &_79$$60, "__construct", &_21, 0, &_80$$60);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_79$$60, "phalcon/Mvc/Micro.zep", 685);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(&_81$$59);
					zephir_create_array(&_81$$59, 1, 0);
					zephir_array_fast_append(&_81$$59, this_ptr);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &_81$$59);
					zephir_check_call_status_or_jump(try_end_1);
				}
				zephir_read_property(&_82$$57, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_82$$57)) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_77$$4, &finishHandlers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_77$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&finish, &finishHandlers, "current", NULL, 0);
				zephir_check_call_status();
					_83$$62 = Z_TYPE_P(&finish) == IS_OBJECT;
					if (_83$$62) {
						_83$$62 = zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_83$$62) {
						ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&finish)))) {
							ZEPHIR_INIT_NVAR(&_84$$65);
							object_init_ex(&_84$$65, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_85$$65);
							ZVAL_STRING(&_85$$65, "finish");
							ZEPHIR_CALL_METHOD(NULL, &_84$$65, "__construct", &_21, 0, &_85$$65);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_84$$65, "phalcon/Mvc/Micro.zep", 685);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&_86$$64);
						zephir_create_array(&_86$$64, 1, 0);
						zephir_array_fast_append(&_86$$64, this_ptr);
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &_86$$64);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property(&_87$$62, this_ptr, ZEND_STRL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_87$$62)) {
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&finish);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_88);
		ZVAL_OBJ(&_88, EG(exception));
		Z_ADDREF_P(&_88);
		if (zephir_is_instance_of(&_88, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_88);
			zephir_read_property(&_89$$67, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_89$$67) != IS_NULL) {
				zephir_read_property(&_90$$68, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_91$$68);
				ZVAL_STRING(&_91$$68, "micro:beforeException");
				ZEPHIR_CALL_METHOD(&returnedValue, &_90$$68, "fire", NULL, 0, &_91$$68, this_ptr, &e);
				zephir_check_call_status();
			}
			zephir_read_property(&_92$$67, this_ptr, ZEND_STRL("errorHandler"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_92$$67) != IS_NULL) {
				zephir_read_property(&_93$$69, this_ptr, ZEND_STRL("errorHandler"), PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(!(zephir_is_callable(&_93$$69)))) {
					ZEPHIR_INIT_VAR(&_94$$70);
					object_init_ex(&_94$$70, phalcon_mvc_micro_exceptions_errorhandlernotcallable_ce);
					ZEPHIR_CALL_METHOD(NULL, &_94$$70, "__construct", NULL, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_94$$70, "phalcon/Mvc/Micro.zep", 721);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property(&_95$$69, this_ptr, ZEND_STRL("errorHandler"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_96$$69);
				zephir_create_array(&_96$$69, 1, 0);
				zephir_array_fast_append(&_96$$69, &e);
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &_95$$69, &_96$$69);
				zephir_check_call_status();
				if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce))) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 734);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 738);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
					zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 743);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("responseHandler"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_97$$77, this_ptr, ZEND_STRL("responseHandler"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(!(zephir_is_callable(&_97$$77)))) {
			ZEPHIR_INIT_VAR(&_98$$78);
			object_init_ex(&_98$$78, phalcon_mvc_micro_exceptions_responsehandlernotcallable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_98$$78, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_98$$78, "phalcon/Mvc/Micro.zep", 754);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_99$$77, this_ptr, ZEND_STRL("responseHandler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&returnedValue);
		ZEPHIR_CALL_USER_FUNC(&returnedValue, &_99$$77);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(&returnedValue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_101$$80);
			ZVAL_STRING(&_101$$80, "response");
			ZEPHIR_CALL_METHOD(&_100$$80, &container, "getshared", NULL, 0, &_101$$80);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_100$$80);
			ZEPHIR_CALL_METHOD(&_100$$80, &response, "issent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_100$$80))) {
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &returnedValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
		_102$$79 = Z_TYPE_P(&returnedValue) == IS_OBJECT;
		if (_102$$79) {
			_102$$79 = zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce);
		}
		_103$$79 = _102$$79;
		if (_103$$79) {
			ZEPHIR_CALL_METHOD(&_104$$79, &returnedValue, "issent", NULL, 0);
			zephir_check_call_status();
			_103$$79 = !zephir_is_true(&_104$$79);
		}
		if (_103$$79) {
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
	zval serviceName_zv, _0, _2, _1$$3;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serviceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "has", NULL, 0, &serviceName_zv);
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
	zval routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addhead", NULL, 0, &routePattern_zv);
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
	zval routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "add", NULL, 0, &routePattern_zv);
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
	zend_bool _8$$7, _9$$7, _12$$15, _13$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, mainHandler, handlers, lazyHandler, prefix, methods, pattern, subHandler, realHandler, prefixedPattern, route, handler, name, _2, *_3, _4, _0$$3, _1$$4, _5$$8, _10$$16, _11$$15;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_11$$15);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_mvc_micro_collectioninterface_ce)
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Micro.zep", 869);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "gethandlers", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&handlers)))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_micro_exceptions_nohandlerstomount_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Micro.zep", 875);
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
	zephir_is_iterable(&handlers, 0, "phalcon/Mvc/Micro.zep", 931);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _3)
		{
			ZEPHIR_INIT_NVAR(&handler);
			ZVAL_COPY(&handler, _3);
			if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_5$$8);
				object_init_ex(&_5$$8, phalcon_mvc_micro_exceptions_invalidregisteredhandler_ce);
				ZEPHIR_CALL_METHOD(NULL, &_5$$8, "__construct", &_6, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$8, "phalcon/Mvc/Micro.zep", 894);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 897);
			ZEPHIR_OBS_NVAR(&pattern);
			zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 898);
			ZEPHIR_OBS_NVAR(&subHandler);
			zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 899);
			ZEPHIR_OBS_NVAR(&name);
			zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 900);
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
			ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_7, 0, &prefixedPattern, &realHandler);
			zephir_check_call_status();
			_8$$7 = Z_TYPE_P(&methods) == IS_STRING;
			if (_8$$7) {
				_8$$7 = !ZEPHIR_IS_STRING_IDENTICAL(&methods, "");
			}
			_9$$7 = _8$$7;
			if (!(_9$$7)) {
				_9$$7 = Z_TYPE_P(&methods) == IS_ARRAY;
			}
			if (_9$$7) {
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
			ZEPHIR_CALL_METHOD(&_4, &handlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&handler, &handlers, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_10$$16);
					object_init_ex(&_10$$16, phalcon_mvc_micro_exceptions_invalidregisteredhandler_ce);
					ZEPHIR_CALL_METHOD(NULL, &_10$$16, "__construct", &_6, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$16, "phalcon/Mvc/Micro.zep", 894);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methods);
				zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 897);
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 898);
				ZEPHIR_OBS_NVAR(&subHandler);
				zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 899);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 900);
				ZEPHIR_INIT_NVAR(&_11$$15);
				zephir_create_array(&_11$$15, 2, 0);
				zephir_array_fast_append(&_11$$15, &lazyHandler);
				zephir_array_fast_append(&_11$$15, &subHandler);
				ZEPHIR_CPY_WRT(&realHandler, &_11$$15);
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
				ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_7, 0, &prefixedPattern, &realHandler);
				zephir_check_call_status();
				_12$$15 = Z_TYPE_P(&methods) == IS_STRING;
				if (_12$$15) {
					_12$$15 = !ZEPHIR_IS_STRING_IDENTICAL(&methods, "");
				}
				_13$$15 = _12$$15;
				if (!(_13$$15)) {
					_13$$15 = Z_TYPE_P(&methods) == IS_ARRAY;
				}
				if (_13$$15) {
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handler);
	zephir_update_property_zval(this_ptr, ZEND_STRL("notFoundHandler"), handler);
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
	zval offset_sub, _0, _2, _1$$3;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "remove", NULL, 0, offset);
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
	zval routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addoptions", NULL, 0, &routePattern_zv);
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
	zval routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addpatch", NULL, 0, &routePattern_zv);
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
	zval routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addpost", NULL, 0, &routePattern_zv);
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
	zval routePattern_zv, *handler, handler_sub, router, route, _0;
	zend_string *routePattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addput", NULL, 0, &routePattern_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(activeHandler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &activeHandler);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeHandler"), activeHandler);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(modelBinder, phalcon_mvc_model_binderinterface_ce)
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
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
	zval serviceName_zv, *definition, definition_sub, *shared_param = NULL, _0, _2, _3, _1$$3;
	zend_string *serviceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(serviceName)
		Z_PARAM_ZVAL(definition)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(shared)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		shared_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&serviceName_zv);
	ZVAL_STR_COPY(&serviceName_zv, serviceName);
	if (!shared_param) {
		shared = 0;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (shared) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&_2, "set", NULL, 0, &serviceName_zv, definition, &_3);
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

