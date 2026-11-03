
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * With Phalcon, you can create "Micro-Framework like" applications. By doing
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
	 *
	 * @phpstan-var array<array-key, mixed>|callable|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("activeHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var list<mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("afterBindingHandlers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var list<mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("afterHandlers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var list<mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("beforeHandlers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var callable|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_ce, SL("errorHandler"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	/**
	 * @phpstan-var list<mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("finishHandlers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, array<array-key, mixed>|callable>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("handlers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("modelBinder"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Mvc\\Model\\BinderInterface"));
	}

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
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("router"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Mvc\\RouterInterface"));
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_micro_ce, SL("stopped"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setDi", NULL, 0, container);
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addRoute", NULL, 0, &_0, &routePattern_zv, handler);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 993, handler);
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addRoute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 *
 * @phpstan-return array<array-key, mixed>|callable|null
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler)
{

	RETURN_MEMBER(getThis(), "activeHandler");
}

/**
 * Returns bound models from binder instance
 *
 * @phpstan-return array<array-key, mixed>
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 994, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&modelBinder, &_0);
	if (Z_TYPE_P(&modelBinder) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(&modelBinder, "getBoundModels", NULL, 0);
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
 * Returns the internal handlers attached to the application
 *
 * @phpstan-return array<string, array<array-key, mixed>|callable>
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
	zval _8$$4;
	zend_bool _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$false, container, _0, _1$$3, _2$$3, _3$$3, _5$$3, _6$$3, _16$$3, _7$$4, _9$$4, _10$$4, _11$$4, _12$$5, _13$$6, _14$$6, _15$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_8$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("router", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("container", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 995, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkDiContainer", NULL, 0);
		zephir_check_call_status();
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 996, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_1$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "router");
		ZEPHIR_CALL_METHOD(&_2$$3, &container, "has", NULL, 0, &_3$$3);
		zephir_check_call_status();
		_4$$3 = zephir_is_true(&_2$$3);
		if (_4$$3) {
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "router");
			ZEPHIR_CALL_METHOD(&_5$$3, &container, "getService", NULL, 0, &_3$$3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$3, &_5$$3, "getDefinition", NULL, 0);
			zephir_check_call_status();
			_4$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_6$$3, "Phalcon\\Mvc\\Router");
		}
		if (_4$$3) {
			ZEPHIR_INIT_VAR(&_8$$4);
			zephir_create_array(&_8$$4, 1, 0);
			zephir_array_fast_append(&_8$$4, &__$false);
			ZEPHIR_INIT_VAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "router");
			ZEPHIR_CALL_METHOD(&_7$$4, &container, "getShared", NULL, 0, &_9$$4, &_8$$4);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 995, &_7$$4);
			zephir_read_property_cached(&_10$$4, this_ptr, _zephir_prop_0, 995, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_11$$4, &_10$$4, "getRoutes", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&_11$$4))) {
				zephir_read_property_cached(&_12$$5, this_ptr, _zephir_prop_0, 995, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_12$$5, "clear", NULL, 0);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_VAR(&_14$$6);
			ZVAL_STRING(&_14$$6, "router");
			ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "getSharedService", NULL, 0, &_14$$6);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 995, &_13$$6);
			zephir_read_property_cached(&_15$$6, this_ptr, _zephir_prop_0, 995, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_15$$6, "clear", NULL, 0);
			zephir_check_call_status();
		}
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 995, PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_16$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "removeExtraSlashes", NULL, 0, &_16$$3);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkDiContainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkDiContainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getShared", NULL, 0, &serviceName_zv);
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
	zval _111$$63, _119$$68, _129$$73;
	zend_class_entry *_48$$25;
	zend_bool _114$$4, _17$$9, _40$$9, _46$$9, _57$$9, _71$$9, _89$$9, _34$$15, _41$$20, _53$$29, _65$$35, _72$$40, _83$$46, _90$$51, _107$$61, _115$$66, _135$$84, _136$$84;
	zval bindCacheKey;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_37 = NULL, *_44 = NULL, *_68 = NULL, *_75 = NULL, *_86 = NULL, *_93 = NULL, *_110 = NULL, *_118 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$true, __$false, after, afterBinding, afterBindingHandlers, afterHandlers, before, beforeHandlers, container, e, finish, finishHandlers, handler, lazyReturned, matchedRoute, methodName, modelBinder, notFoundHandler, params, response, routeName, router, realHandler, returnedValue, status, _0, _121, _1$$3, _2$$4, _13$$4, _14$$4, _101$$4, _104$$4, *_105$$4, *_106$$4, _113$$4, _3$$5, _4$$5, _5$$5, _6$$5, _7$$6, _8$$6, _9$$6, _10$$6, _11$$6, _12$$6, _15$$9, _16$$9, _19$$9, _30$$9, *_31$$9, _32$$9, *_33$$9, _39$$9, _61$$9, *_62$$9, _63$$9, *_64$$9, _70$$9, _79$$9, *_80$$9, _81$$9, *_82$$9, _88$$9, _18$$10, _20$$11, _21$$11, _22$$11, _23$$11, _24$$12, _25$$12, _26$$12, _27$$12, _28$$12, _29$$12, _38$$15, _35$$18, _36$$18, _45$$20, _42$$23, _43$$23, _47$$25, _49$$27, _50$$28, _51$$28, _52$$26, _54$$30, _55$$30, _56$$30, _58$$33, _59$$33, _60$$33, _69$$35, _66$$38, _67$$38, _76$$40, _73$$43, _74$$43, _77$$45, _78$$45, _87$$46, _84$$49, _85$$49, _94$$51, _91$$54, _92$$54, _95$$56, _99$$56, _96$$57, _97$$57, _98$$57, _100$$59, _102$$60, _103$$60, _112$$61, _108$$64, _109$$64, _120$$66, _116$$69, _117$$69, _122$$71, _125$$71, _123$$72, _124$$72, _126$$73, _128$$73, _127$$74, _130$$82, _132$$82, _131$$83, _133$$85, _134$$85, _137$$84;
	zend_string *uri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&after);
	ZVAL_UNDEF(&afterBinding);
	ZVAL_UNDEF(&afterBindingHandlers);
	ZVAL_UNDEF(&afterHandlers);
	ZVAL_UNDEF(&before);
	ZVAL_UNDEF(&beforeHandlers);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&finish);
	ZVAL_UNDEF(&finishHandlers);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&lazyReturned);
	ZVAL_UNDEF(&matchedRoute);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&notFoundHandler);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&realHandler);
	ZVAL_UNDEF(&returnedValue);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_121);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_101$$4);
	ZVAL_UNDEF(&_104$$4);
	ZVAL_UNDEF(&_113$$4);
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
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_61$$9);
	ZVAL_UNDEF(&_63$$9);
	ZVAL_UNDEF(&_70$$9);
	ZVAL_UNDEF(&_79$$9);
	ZVAL_UNDEF(&_81$$9);
	ZVAL_UNDEF(&_88$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_36$$18);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_42$$23);
	ZVAL_UNDEF(&_43$$23);
	ZVAL_UNDEF(&_47$$25);
	ZVAL_UNDEF(&_49$$27);
	ZVAL_UNDEF(&_50$$28);
	ZVAL_UNDEF(&_51$$28);
	ZVAL_UNDEF(&_52$$26);
	ZVAL_UNDEF(&_54$$30);
	ZVAL_UNDEF(&_55$$30);
	ZVAL_UNDEF(&_56$$30);
	ZVAL_UNDEF(&_58$$33);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_60$$33);
	ZVAL_UNDEF(&_69$$35);
	ZVAL_UNDEF(&_66$$38);
	ZVAL_UNDEF(&_67$$38);
	ZVAL_UNDEF(&_76$$40);
	ZVAL_UNDEF(&_73$$43);
	ZVAL_UNDEF(&_74$$43);
	ZVAL_UNDEF(&_77$$45);
	ZVAL_UNDEF(&_78$$45);
	ZVAL_UNDEF(&_87$$46);
	ZVAL_UNDEF(&_84$$49);
	ZVAL_UNDEF(&_85$$49);
	ZVAL_UNDEF(&_94$$51);
	ZVAL_UNDEF(&_91$$54);
	ZVAL_UNDEF(&_92$$54);
	ZVAL_UNDEF(&_95$$56);
	ZVAL_UNDEF(&_99$$56);
	ZVAL_UNDEF(&_96$$57);
	ZVAL_UNDEF(&_97$$57);
	ZVAL_UNDEF(&_98$$57);
	ZVAL_UNDEF(&_100$$59);
	ZVAL_UNDEF(&_102$$60);
	ZVAL_UNDEF(&_103$$60);
	ZVAL_UNDEF(&_112$$61);
	ZVAL_UNDEF(&_108$$64);
	ZVAL_UNDEF(&_109$$64);
	ZVAL_UNDEF(&_120$$66);
	ZVAL_UNDEF(&_116$$69);
	ZVAL_UNDEF(&_117$$69);
	ZVAL_UNDEF(&_122$$71);
	ZVAL_UNDEF(&_125$$71);
	ZVAL_UNDEF(&_123$$72);
	ZVAL_UNDEF(&_124$$72);
	ZVAL_UNDEF(&_126$$73);
	ZVAL_UNDEF(&_128$$73);
	ZVAL_UNDEF(&_127$$74);
	ZVAL_UNDEF(&_130$$82);
	ZVAL_UNDEF(&_132$$82);
	ZVAL_UNDEF(&_131$$83);
	ZVAL_UNDEF(&_133$$85);
	ZVAL_UNDEF(&_134$$85);
	ZVAL_UNDEF(&_137$$84);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&_111$$63);
	ZVAL_UNDEF(&_119$$68);
	ZVAL_UNDEF(&_129$$73);
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
	ZEPHIR_INIT_VAR(&realHandler);
	ZVAL_NULL(&realHandler);
	ZEPHIR_INIT_VAR(&returnedValue);
	ZVAL_NULL(&returnedValue);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_micro_exceptions_containerrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Micro.zep", 375);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_NVAR(&returnedValue);
		ZVAL_NULL(&returnedValue);
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2$$4) != IS_NULL) {
			zephir_memory_observe(&_3$$5);
			zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC);
			if (zephir_instance_of_ev(&_3$$5, phalcon_events_manager_ce)) {
				zephir_read_property_cached(&_7$$6, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
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
				zephir_read_property_cached(&_4$$5, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_METHOD(&_13$$4, &container, "getShared", NULL, 0, &_14$$4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&router, &_13$$4);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri_zv);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getMatchedRoute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&matchedRoute) != IS_NULL) {
			zephir_memory_observe(&handler);
			zephir_read_property_cached(&_15$$9, this_ptr, _zephir_prop_2, 998, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_16$$9, &matchedRoute, "getRouteId", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			_17$$9 = zephir_array_isset_fetch(&handler, &_15$$9, &_16$$9, 0);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			if (UNEXPECTED(!(_17$$9))) {
				ZEPHIR_INIT_VAR(&_18$$10);
				object_init_ex(&_18$$10, phalcon_mvc_micro_exceptions_nomatchedroutehandler_ce);
				ZEPHIR_CALL_METHOD(NULL, &_18$$10, "__construct", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_18$$10, "phalcon/Mvc/Micro.zep", 415);
				goto try_end_1;

			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 999, &handler);
			zephir_read_property_cached(&_19$$9, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_19$$9) != IS_NULL) {
				zephir_memory_observe(&_20$$11);
				zephir_read_property_cached(&_20$$11, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC);
				if (zephir_instance_of_ev(&_20$$11, phalcon_events_manager_ce)) {
					zephir_read_property_cached(&_24$$12, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&_26$$12);
					ZVAL_STRING(&_26$$12, "micro:beforeExecuteRoute");
					ZVAL_NULL(&_27$$12);
					ZVAL_BOOL(&_28$$12, 1);
					ZVAL_BOOL(&_29$$12, 1);
					ZEPHIR_CALL_METHOD(&_25$$12, &_24$$12, "fire", NULL, 0, &_26$$12, this_ptr, &_27$$12, &_28$$12, &_29$$12);
					zephir_check_call_status_or_jump(try_end_1);
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_25$$12)) {
						RETURN_MM_BOOL(0);
					}
				} else {
					zephir_read_property_cached(&_21$$11, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&_23$$11);
					ZVAL_STRING(&_23$$11, "micro:beforeExecuteRoute");
					ZEPHIR_CALL_METHOD(&_22$$11, &_21$$11, "fire", NULL, 0, &_23$$11, this_ptr);
					zephir_check_call_status_or_jump(try_end_1);
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_22$$11)) {
						RETURN_MM_BOOL(0);
					}
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_read_property_cached(&handler, this_ptr, _zephir_prop_3, 999, PH_NOISY_CC);
			}
			zephir_read_property_cached(&_30$$9, this_ptr, _zephir_prop_4, 1000, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&beforeHandlers, &_30$$9);
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1001, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1001, &__$false);
			}
			if (Z_TYPE_P(&beforeHandlers) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_32$$9);
				zephir_string_to_char_array(&_32$$9, &beforeHandlers);
				_31$$9 = &_32$$9;
			} else {
				_31$$9 = &beforeHandlers;
			}
			zephir_is_iterable(_31$$9, 0, "phalcon/Mvc/Micro.zep", 469);
			if (Z_TYPE_P(_31$$9) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_31$$9), _33$$9)
				{
					ZEPHIR_INIT_NVAR(&before);
					ZVAL_COPY(&before, _33$$9);
					_34$$15 = Z_TYPE_P(&before) == IS_OBJECT;
					if (_34$$15) {
						_34$$15 = zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_34$$15) {
						ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&before)))) {
							ZEPHIR_INIT_NVAR(&_35$$18);
							object_init_ex(&_35$$18, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_36$$18);
							ZVAL_STRING(&_36$$18, "before");
							ZEPHIR_CALL_METHOD(NULL, &_35$$18, "__construct", &_37, 0, &_36$$18);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_35$$18, "phalcon/Mvc/Micro.zep", 452);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &before);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property_cached(&_38$$15, this_ptr, _zephir_prop_5, 1001, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_38$$15)) {
						RETURN_CCTOR(&status);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _31$$9, "rewind", NULL, 0);
				zephir_check_call_status();
				_40$$9 = 1;
				while (1) {
					if (_40$$9) {
						_40$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _31$$9, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_39$$9, _31$$9, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_39$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&before, _31$$9, "current", NULL, 0);
					zephir_check_call_status();
						_41$$20 = Z_TYPE_P(&before) == IS_OBJECT;
						if (_41$$20) {
							_41$$20 = zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_41$$20) {
							ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&before)))) {
								ZEPHIR_INIT_NVAR(&_42$$23);
								object_init_ex(&_42$$23, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_43$$23);
								ZVAL_STRING(&_43$$23, "before");
								ZEPHIR_CALL_METHOD(NULL, &_42$$23, "__construct", &_44, 0, &_43$$23);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_42$$23, "phalcon/Mvc/Micro.zep", 452);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &before);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property_cached(&_45$$20, this_ptr, _zephir_prop_5, 1001, PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_45$$20)) {
							RETURN_CCTOR(&status);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&before);
			ZEPHIR_CALL_METHOD(&params, &router, "getParams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property_cached(&_30$$9, this_ptr, _zephir_prop_6, 994, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_30$$9);
			_46$$9 = Z_TYPE_P(&handler) == IS_OBJECT;
			if (_46$$9) {
				_46$$9 = zephir_is_instance_of(&handler, SL("Closure"));
			}
			if (_46$$9) {
				_48$$25 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_47$$25, _48$$25, "bind", NULL, 0, &handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&handler, &_47$$25);
				if (Z_TYPE_P(&modelBinder) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&routeName, &matchedRoute, "getName", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					if (Z_TYPE_P(&routeName) != IS_NULL) {
						ZEPHIR_INIT_VAR(&_49$$27);
						ZEPHIR_CONCAT_SV(&_49$$27, "_PHMB_", &routeName);
						if (UNEXPECTED(EG(exception))) {
							goto try_end_1;
						}
						zephir_get_strval(&bindCacheKey, &_49$$27);
						if (UNEXPECTED(EG(exception))) {
							goto try_end_1;
						}
					} else {
						ZEPHIR_CALL_METHOD(&_50$$28, &matchedRoute, "getPattern", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_INIT_VAR(&_51$$28);
						ZEPHIR_CONCAT_SV(&_51$$28, "_PHMB_", &_50$$28);
						if (UNEXPECTED(EG(exception))) {
							goto try_end_1;
						}
						zephir_get_strval(&bindCacheKey, &_51$$28);
						if (UNEXPECTED(EG(exception))) {
							goto try_end_1;
						}
					}
					ZEPHIR_CALL_METHOD(&_52$$26, &modelBinder, "bindToHandler", NULL, 0, &handler, &params, &bindCacheKey);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_52$$26);
				}
			}
			if (Z_TYPE_P(&handler) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&realHandler);
				zephir_array_fetch_long(&realHandler, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 500);
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
				_53$$29 = zephir_instance_of_ev(&realHandler, phalcon_mvc_controller_ce);
				if (_53$$29) {
					_53$$29 = Z_TYPE_P(&modelBinder) != IS_NULL;
				}
				if (_53$$29) {
					zephir_memory_observe(&methodName);
					zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 503);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}
					ZEPHIR_INIT_VAR(&_54$$30);
					zephir_get_class(&_54$$30, &realHandler, 0);
					ZEPHIR_INIT_VAR(&_55$$30);
					ZEPHIR_CONCAT_SVSV(&_55$$30, "_PHMB_", &_54$$30, "_", &methodName);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}
					zephir_get_strval(&bindCacheKey, &_55$$30);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}
					ZEPHIR_CALL_METHOD(&_56$$30, &modelBinder, "bindToHandler", NULL, 0, &realHandler, &params, &bindCacheKey, &methodName);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_56$$30);
				}
			}
			_57$$9 = Z_TYPE_P(&realHandler) != IS_NULL;
			if (_57$$9) {
				_57$$9 = zephir_instance_of_ev(&realHandler, phalcon_mvc_micro_lazyloader_ce);
			}
			if (_57$$9) {
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 520);
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
				ZEPHIR_CALL_METHOD(&lazyReturned, &realHandler, "callMethod", NULL, 0, &methodName, &params, &modelBinder);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				ZEPHIR_INIT_NVAR(&lazyReturned);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&lazyReturned, &handler, &params);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_CPY_WRT(&returnedValue, &lazyReturned);
			zephir_read_property_cached(&_30$$9, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_30$$9) != IS_NULL) {
				zephir_read_property_cached(&_58$$33, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_60$$33);
				ZVAL_STRING(&_60$$33, "micro:afterBinding");
				ZEPHIR_CALL_METHOD(&_59$$33, &_58$$33, "fire", NULL, 0, &_60$$33, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_59$$33)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property_cached(&_61$$9, this_ptr, _zephir_prop_7, 1002, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterBindingHandlers, &_61$$9);
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1001, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1001, &__$false);
			}
			if (Z_TYPE_P(&afterBindingHandlers) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_63$$9);
				zephir_string_to_char_array(&_63$$9, &afterBindingHandlers);
				_62$$9 = &_63$$9;
			} else {
				_62$$9 = &afterBindingHandlers;
			}
			zephir_is_iterable(_62$$9, 0, "phalcon/Mvc/Micro.zep", 581);
			if (Z_TYPE_P(_62$$9) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_62$$9), _64$$9)
				{
					ZEPHIR_INIT_NVAR(&afterBinding);
					ZVAL_COPY(&afterBinding, _64$$9);
					_65$$35 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
					if (_65$$35) {
						_65$$35 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_65$$35) {
						ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&afterBinding)))) {
							ZEPHIR_INIT_NVAR(&_66$$38);
							object_init_ex(&_66$$38, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_67$$38);
							ZVAL_STRING(&_67$$38, "afterBinding");
							ZEPHIR_CALL_METHOD(NULL, &_66$$38, "__construct", &_68, 0, &_67$$38);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_66$$38, "phalcon/Mvc/Micro.zep", 561);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property_cached(&_69$$35, this_ptr, _zephir_prop_5, 1001, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_69$$35)) {
						RETURN_CCTOR(&status);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _62$$9, "rewind", NULL, 0);
				zephir_check_call_status();
				_71$$9 = 1;
				while (1) {
					if (_71$$9) {
						_71$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _62$$9, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_70$$9, _62$$9, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_70$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&afterBinding, _62$$9, "current", NULL, 0);
					zephir_check_call_status();
						_72$$40 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
						if (_72$$40) {
							_72$$40 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_72$$40) {
							ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&afterBinding)))) {
								ZEPHIR_INIT_NVAR(&_73$$43);
								object_init_ex(&_73$$43, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_74$$43);
								ZVAL_STRING(&_74$$43, "afterBinding");
								ZEPHIR_CALL_METHOD(NULL, &_73$$43, "__construct", &_75, 0, &_74$$43);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_73$$43, "phalcon/Mvc/Micro.zep", 561);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property_cached(&_76$$40, this_ptr, _zephir_prop_5, 1001, PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_76$$40)) {
							RETURN_CCTOR(&status);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&afterBinding);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 1003, &returnedValue);
			zephir_read_property_cached(&_61$$9, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_61$$9) != IS_NULL) {
				zephir_read_property_cached(&_77$$45, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_78$$45);
				ZVAL_STRING(&_78$$45, "micro:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(NULL, &_77$$45, "fire", NULL, 0, &_78$$45, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
			}
			zephir_read_property_cached(&_79$$9, this_ptr, _zephir_prop_9, 1004, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterHandlers, &_79$$9);
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1001, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1001, &__$false);
			}
			if (Z_TYPE_P(&afterHandlers) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_81$$9);
				zephir_string_to_char_array(&_81$$9, &afterHandlers);
				_80$$9 = &_81$$9;
			} else {
				_80$$9 = &afterHandlers;
			}
			zephir_is_iterable(_80$$9, 0, "phalcon/Mvc/Micro.zep", 618);
			if (Z_TYPE_P(_80$$9) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_80$$9), _82$$9)
				{
					ZEPHIR_INIT_NVAR(&after);
					ZVAL_COPY(&after, _82$$9);
					_83$$46 = Z_TYPE_P(&after) == IS_OBJECT;
					if (_83$$46) {
						_83$$46 = zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_83$$46) {
						ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&after)))) {
							ZEPHIR_INIT_NVAR(&_84$$49);
							object_init_ex(&_84$$49, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_85$$49);
							ZVAL_STRING(&_85$$49, "after");
							ZEPHIR_CALL_METHOD(NULL, &_84$$49, "__construct", &_86, 0, &_85$$49);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_84$$49, "phalcon/Mvc/Micro.zep", 605);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &after);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property_cached(&_87$$46, this_ptr, _zephir_prop_5, 1001, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_87$$46)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _80$$9, "rewind", NULL, 0);
				zephir_check_call_status();
				_89$$9 = 1;
				while (1) {
					if (_89$$9) {
						_89$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _80$$9, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_88$$9, _80$$9, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_88$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&after, _80$$9, "current", NULL, 0);
					zephir_check_call_status();
						_90$$51 = Z_TYPE_P(&after) == IS_OBJECT;
						if (_90$$51) {
							_90$$51 = zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce);
						}
						if (_90$$51) {
							ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							if (UNEXPECTED(!(zephir_is_callable(&after)))) {
								ZEPHIR_INIT_NVAR(&_91$$54);
								object_init_ex(&_91$$54, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
								ZEPHIR_INIT_NVAR(&_92$$54);
								ZVAL_STRING(&_92$$54, "after");
								ZEPHIR_CALL_METHOD(NULL, &_91$$54, "__construct", &_93, 0, &_92$$54);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_91$$54, "phalcon/Mvc/Micro.zep", 605);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &after);
							zephir_check_call_status_or_jump(try_end_1);
						}
						zephir_read_property_cached(&_94$$51, this_ptr, _zephir_prop_5, 1001, PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_94$$51)) {
							break;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&after);
		} else {
			zephir_read_property_cached(&_95$$56, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_95$$56) != IS_NULL) {
				zephir_read_property_cached(&_96$$57, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_98$$57);
				ZVAL_STRING(&_98$$57, "micro:beforeNotFound");
				ZEPHIR_CALL_METHOD(&_97$$57, &_96$$57, "fire", NULL, 0, &_98$$57, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_97$$57)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property_cached(&_99$$56, this_ptr, _zephir_prop_10, 1005, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&notFoundHandler, &_99$$56);
			if (UNEXPECTED(!(zephir_is_callable(&notFoundHandler)))) {
				ZEPHIR_INIT_VAR(&_100$$59);
				object_init_ex(&_100$$59, phalcon_mvc_micro_exceptions_notfoundhandlernotcallable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_100$$59, "__construct", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_100$$59, "phalcon/Mvc/Micro.zep", 634);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(&returnedValue);
			ZEPHIR_CALL_USER_FUNC(&returnedValue, &notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property_cached(&_101$$4, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_101$$4) != IS_NULL) {
			zephir_read_property_cached(&_102$$60, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_103$$60);
			ZVAL_STRING(&_103$$60, "micro:afterHandleRoute");
			ZEPHIR_CALL_METHOD(NULL, &_102$$60, "fire", NULL, 0, &_103$$60, this_ptr, &returnedValue);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property_cached(&_104$$4, this_ptr, _zephir_prop_11, 1006, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&finishHandlers, &_104$$4);
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1001, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1001, &__$false);
		}
		if (Z_TYPE_P(&finishHandlers) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_14$$4);
			zephir_string_to_char_array(&_14$$4, &finishHandlers);
			_105$$4 = &_14$$4;
		} else {
			_105$$4 = &finishHandlers;
		}
		zephir_is_iterable(_105$$4, 0, "phalcon/Mvc/Micro.zep", 686);
		if (Z_TYPE_P(_105$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_105$$4), _106$$4)
			{
				ZEPHIR_INIT_NVAR(&finish);
				ZVAL_COPY(&finish, _106$$4);
				_107$$61 = Z_TYPE_P(&finish) == IS_OBJECT;
				if (_107$$61) {
					_107$$61 = zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce);
				}
				if (_107$$61) {
					ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
					zephir_check_call_status_or_jump(try_end_1);
				} else {
					if (UNEXPECTED(!(zephir_is_callable(&finish)))) {
						ZEPHIR_INIT_NVAR(&_108$$64);
						object_init_ex(&_108$$64, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
						ZEPHIR_INIT_NVAR(&_109$$64);
						ZVAL_STRING(&_109$$64, "finish");
						ZEPHIR_CALL_METHOD(NULL, &_108$$64, "__construct", &_110, 0, &_109$$64);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_108$$64, "phalcon/Mvc/Micro.zep", 667);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(&_111$$63);
					zephir_create_array(&_111$$63, 1, 0);
					zephir_array_fast_append(&_111$$63, this_ptr);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &_111$$63);
					zephir_check_call_status_or_jump(try_end_1);
				}
				zephir_read_property_cached(&_112$$61, this_ptr, _zephir_prop_5, 1001, PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_112$$61)) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _105$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_114$$4 = 1;
			while (1) {
				if (_114$$4) {
					_114$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _105$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_113$$4, _105$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_113$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&finish, _105$$4, "current", NULL, 0);
				zephir_check_call_status();
					_115$$66 = Z_TYPE_P(&finish) == IS_OBJECT;
					if (_115$$66) {
						_115$$66 = zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce);
					}
					if (_115$$66) {
						ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						if (UNEXPECTED(!(zephir_is_callable(&finish)))) {
							ZEPHIR_INIT_NVAR(&_116$$69);
							object_init_ex(&_116$$69, phalcon_mvc_micro_exceptions_handlernotcallable_ce);
							ZEPHIR_INIT_NVAR(&_117$$69);
							ZVAL_STRING(&_117$$69, "finish");
							ZEPHIR_CALL_METHOD(NULL, &_116$$69, "__construct", &_118, 0, &_117$$69);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_116$$69, "phalcon/Mvc/Micro.zep", 667);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&_119$$68);
						zephir_create_array(&_119$$68, 1, 0);
						zephir_array_fast_append(&_119$$68, this_ptr);
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &_119$$68);
						zephir_check_call_status_or_jump(try_end_1);
					}
					zephir_read_property_cached(&_120$$66, this_ptr, _zephir_prop_5, 1001, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_120$$66)) {
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&finish);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_121);
		ZVAL_OBJ(&_121, EG(exception));
		Z_ADDREF_P(&_121);
		if (zephir_is_instance_of(&_121, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_121);
			zephir_read_property_cached(&_122$$71, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_122$$71) != IS_NULL) {
				zephir_read_property_cached(&_123$$72, this_ptr, _zephir_prop_1, 997, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_124$$72);
				ZVAL_STRING(&_124$$72, "micro:beforeException");
				ZEPHIR_CALL_METHOD(NULL, &_123$$72, "fire", NULL, 0, &_124$$72, this_ptr, &e);
				zephir_check_call_status();
			}
			zephir_read_property_cached(&_125$$71, this_ptr, _zephir_prop_12, 993, PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_125$$71) != IS_NULL) {
				zephir_read_property_cached(&_126$$73, this_ptr, _zephir_prop_12, 993, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(!(zephir_is_callable(&_126$$73)))) {
					ZEPHIR_INIT_VAR(&_127$$74);
					object_init_ex(&_127$$74, phalcon_mvc_micro_exceptions_errorhandlernotcallable_ce);
					ZEPHIR_CALL_METHOD(NULL, &_127$$74, "__construct", NULL, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_127$$74, "phalcon/Mvc/Micro.zep", 703);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_128$$73, this_ptr, _zephir_prop_12, 993, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_129$$73);
				zephir_create_array(&_129$$73, 1, 0);
				zephir_array_fast_append(&_129$$73, &e);
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &_128$$73, &_129$$73);
				zephir_check_call_status();
				if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce))) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 716);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 720);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
					zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 725);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_13, 1007, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property_cached(&_130$$82, this_ptr, _zephir_prop_13, 1007, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(!(zephir_is_callable(&_130$$82)))) {
			ZEPHIR_INIT_VAR(&_131$$83);
			object_init_ex(&_131$$83, phalcon_mvc_micro_exceptions_responsehandlernotcallable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_131$$83, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_131$$83, "phalcon/Mvc/Micro.zep", 736);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_132$$82, this_ptr, _zephir_prop_13, 1007, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&returnedValue);
		ZEPHIR_CALL_USER_FUNC(&returnedValue, &_132$$82);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(&returnedValue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_134$$85);
			ZVAL_STRING(&_134$$85, "response");
			ZEPHIR_CALL_METHOD(&_133$$85, &container, "getShared", NULL, 0, &_134$$85);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_133$$85);
			ZEPHIR_CALL_METHOD(&_133$$85, &response, "isSent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_133$$85))) {
				ZEPHIR_CALL_METHOD(NULL, &response, "setContent", NULL, 0, &returnedValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
		_135$$84 = Z_TYPE_P(&returnedValue) == IS_OBJECT;
		if (_135$$84) {
			_135$$84 = zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce);
		}
		_136$$84 = _135$$84;
		if (_136$$84) {
			ZEPHIR_CALL_METHOD(&_137$$84, &returnedValue, "isSent", NULL, 0);
			zephir_check_call_status();
			_136$$84 = !zephir_is_true(&_137$$84);
		}
		if (_136$$84) {
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkDiContainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addRoute", NULL, 0, &_0, &routePattern_zv, handler);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addRoute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Mounts a collection of handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount)
{
	zend_bool _12, _9$$7, _10$$7, _16$$15, _17$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, mainHandler, handlers, lazyHandler, prefix, methods, pattern, subHandler, realHandler, prefixedPattern, route, handler, name, _2, *_3, _4, *_5, _11, _0$$3, _1$$4, _6$$8, _13$$16, _15$$15;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_15$$15);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_mvc_micro_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &collection);
	ZEPHIR_CALL_METHOD(&mainHandler, collection, "getHandler", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&mainHandler))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_micro_exceptions_missingcollectionmainhandler_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Micro.zep", 809);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "getHandlers", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&handlers))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_micro_exceptions_nohandlerstomount_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Micro.zep", 815);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, collection, "isLazy", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&lazyHandler);
		object_init_ex(&lazyHandler, phalcon_mvc_micro_lazyloader_ce);
		ZEPHIR_CALL_METHOD(NULL, &lazyHandler, "__construct", NULL, 0, &mainHandler);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&lazyHandler, &mainHandler);
	}
	ZEPHIR_CALL_METHOD(&prefix, collection, "getPrefix", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&handlers) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &handlers);
		_3 = &_4;
	} else {
		_3 = &handlers;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Micro.zep", 871);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&handler);
			ZVAL_COPY(&handler, _5);
			if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_6$$8);
				object_init_ex(&_6$$8, phalcon_mvc_micro_exceptions_invalidregisteredhandler_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", &_7, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$8, "phalcon/Mvc/Micro.zep", 834);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 837);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&pattern);
			zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 838);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&subHandler);
			zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 839);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&name);
			zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 840);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
			}
			ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_8, 0, &prefixedPattern, &realHandler);
			zephir_check_call_status();
			_9$$7 = Z_TYPE_P(&methods) == IS_STRING;
			if (_9$$7) {
				_9$$7 = !ZEPHIR_IS_STRING_IDENTICAL(&methods, "");
			}
			_10$$7 = _9$$7;
			if (!(_10$$7)) {
				_10$$7 = Z_TYPE_P(&methods) == IS_ARRAY;
			}
			if (_10$$7) {
				ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&name) == IS_STRING) {
				ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &name);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&handler, _3, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_13$$16);
					object_init_ex(&_13$$16, phalcon_mvc_micro_exceptions_invalidregisteredhandler_ce);
					ZEPHIR_CALL_METHOD(NULL, &_13$$16, "__construct", &_14, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$16, "phalcon/Mvc/Micro.zep", 834);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methods);
				zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 837);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 838);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&subHandler);
				zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 839);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 840);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_15$$15);
				zephir_create_array(&_15$$15, 2, 0);
				zephir_array_fast_append(&_15$$15, &lazyHandler);
				zephir_array_fast_append(&_15$$15, &subHandler);
				ZEPHIR_CPY_WRT(&realHandler, &_15$$15);
				if (!(ZEPHIR_IS_EMPTY(&prefix))) {
					if (ZEPHIR_IS_STRING_IDENTICAL(&pattern, "/")) {
						ZEPHIR_CPY_WRT(&prefixedPattern, &prefix);
					} else {
						ZEPHIR_INIT_NVAR(&prefixedPattern);
						ZEPHIR_CONCAT_VV(&prefixedPattern, &prefix, &pattern);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
				}
				ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_8, 0, &prefixedPattern, &realHandler);
				zephir_check_call_status();
				_16$$15 = Z_TYPE_P(&methods) == IS_STRING;
				if (_16$$15) {
					_16$$15 = !ZEPHIR_IS_STRING_IDENTICAL(&methods, "");
				}
				_17$$15 = _16$$15;
				if (!(_17$$15)) {
					_17$$15 = Z_TYPE_P(&methods) == IS_ARRAY;
				}
				if (_17$$15) {
					ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_CALL_METHOD(NULL, &route, "setName", NULL, 0, &name);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1005, handler);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasService", NULL, 0, offset);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getService", NULL, 0, offset);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setService", NULL, 0, offset, value);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkDiContainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addRoute", NULL, 0, &_0, &routePattern_zv, handler);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addRoute", NULL, 0, &_0, &routePattern_zv, handler);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addRoute", NULL, 0, &_0, &routePattern_zv, handler);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addRoute", NULL, 0, &_0, &routePattern_zv, handler);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets externally the handler that must be called by the matched route
 *
 * @param callable activeHandler
 *
 * @phpstan-return static
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 999, activeHandler);
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
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 996, container);
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
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 997, eventsManager);
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
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getService", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_0$$3);
	}
	_1 = Z_TYPE_P(cache) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(cache, phalcon_cache_adapter_adapterinterface_ce);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setCache", NULL, 0, cache);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 994, modelBinder);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1007, handler);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkDiContainer", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1001, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1001, &__$false);
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
	ZEPHIR_CALL_METHOD(&router, this_ptr, "getRouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_ZVAL(&route, &router, &method_zv, NULL, 0, &routePattern_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getRouteId", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 996, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 996, &_1$$3);
	}
	ZEPHIR_MM_RESTORE();
}

