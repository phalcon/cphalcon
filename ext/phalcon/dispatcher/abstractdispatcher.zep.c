
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\Cli\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own
 * dispatchers.
 *
 * ## Error protocol
 *
 * Subclasses (including third-party ones) MUST implement the two abstract
 * error hooks throwDispatchException() and handleException().
 * The dispatch loop calls them on every error/exception path; a subclass that
 * omits them cannot be loaded.
 *
 * ## Hook channels
 *
 * A single lifecycle point can be intercepted through three independent
 * channels. For any given point they run in this order:
 *
 * 1. **Events-manager listener** - e.g. `dispatch:beforeExecuteRoute`. A
 *    listener returning `false` cancels; calling `forward()` re-enters the
 *    loop; throwing routes through handleException().
 * 2. **Duck-typed handler method** - e.g. a `beforeExecuteRoute()` method on
 *    the controller/task itself (presence is cached per class). Same
 *    `false` / `forward()` cancellation semantics as the event.
 * 3. **`dispatch:beforeCallAction` observer** - fired by
 *    callActionMethod() with a `Phalcon\Support\Collection` carrying
 *    the mutable keys `handler`, `action` and `params`. Listeners may rewrite
 *    those keys to change *what* gets invoked; the substituted callable is
 *    re-validated before the call. `dispatch:afterCallAction` receives the
 *    same Collection plus a `result` key.
 *
 * @todo fix the returnValue type in v7
 *
 * @phpstan-import-type dispatcher_bound_models from DispatcherTypes
 * @phpstan-import-type dispatcher_forward from DispatcherTypes
 * @phpstan-import-type dispatcher_handler_hashes from DispatcherTypes
 * @phpstan-import-type dispatcher_hook_cache from DispatcherTypes
 * @phpstan-import-type dispatcher_method_map from DispatcherTypes
 * @phpstan-import-type dispatcher_params from DispatcherTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Dispatcher_AbstractDispatcher)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Dispatcher, AbstractDispatcher, phalcon, dispatcher_abstractdispatcher, phalcon_di_abstractinjectionaware_ce, phalcon_dispatcher_abstractdispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("actionName"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "Action", sizeof("Action") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("actionSuffix"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("activeHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var dispatcher_method_map
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("activeMethodMap"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var dispatcher_method_map
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("camelCaseMap"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultAction"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultHandler"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultNamespace"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("finished"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("forwarded"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @phpstan-var dispatcher_handler_hashes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerHashes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var dispatcher_hook_cache
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerHookCache"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerName"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerSuffix"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("isControllerInitialize"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("lastHandler"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("modelBinder"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Mvc\\Model\\BinderInterface"));
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("modelBinding"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("moduleName"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("namespaceName"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @phpstan-var dispatcher_params
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("params"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("previousActionName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("previousHandlerName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("previousNamespaceName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("returnedValue"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_dispatcher_abstractdispatcher_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	zend_class_implements(phalcon_dispatcher_abstractdispatcher_ce, 1, phalcon_dispatcher_dispatcherinterface_ce);
	zend_class_implements(phalcon_dispatcher_abstractdispatcher_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * @phpstan-param dispatcher_params $params
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, callActionMethod)
{
	zend_bool _1, _16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _13, _3$$3, _8$$3;
	zend_string *actionMethod = NULL;
	zval *handler, handler_sub, actionMethod_zv, *params_param = NULL, altAction, altHandler, altParams, result, observer, _0, _2, _14, _15, _17, _4$$3, _5$$3, _6$$3, _7$$3, _9$$4, _10$$4, _11$$4, _12$$4, _18$$5, _19$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&actionMethod_zv);
	ZVAL_UNDEF(&altAction);
	ZVAL_UNDEF(&altHandler);
	ZVAL_UNDEF(&altParams);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&observer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("actionName", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("handlerName", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_STR(actionMethod)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		params_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&actionMethod_zv);
	ZVAL_STR_COPY(&actionMethod_zv, actionMethod);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	ZEPHIR_INIT_VAR(&observer);
	ZVAL_NULL(&observer);
	ZEPHIR_CPY_WRT(&altHandler, handler);
	ZEPHIR_CPY_WRT(&altAction, &actionMethod_zv);
	ZEPHIR_CPY_WRT(&altParams, &params);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = Z_TYPE_P(&_0) != IS_NULL;
	if (_1) {
		zephir_memory_observe(&_2);
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_1 = zephir_instance_of_ev(&_2, phalcon_events_managerinterface_ce);
	}
	if (_1) {
		ZEPHIR_INIT_NVAR(&observer);
		object_init_ex(&observer, phalcon_support_collection_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		zephir_array_update_string(&_3$$3, SL("handler"), handler, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("action"), &actionMethod_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("params"), &params, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &observer, "__construct", &_zephir_call_cache[0], &_3$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "dispatch:beforeCallAction");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$3, "fire", &_zephir_call_cache[1], &_5$$3, this_ptr, &observer);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "handler");
		ZEPHIR_CALL_METHOD_CACHED(&altHandler, &observer, "get", &_zephir_call_cache[2], &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "action");
		ZEPHIR_CALL_METHOD_CACHED(&altAction, &observer, "get", &_zephir_call_cache[3], &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		array_init(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "params");
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "array");
		ZEPHIR_CALL_METHOD_CACHED(&altParams, &observer, "get", &_zephir_call_cache[4], &_6$$3, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 2, 0);
		zephir_array_fast_append(&_8$$3, &altHandler);
		zephir_array_fast_append(&_8$$3, &altAction);
		if (UNEXPECTED(!(zephir_is_callable(&_8$$3)))) {
			zephir_read_property_cached(&_9$$4, this_ptr, _zephir_prop_1, 180, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_10$$4, this_ptr, _zephir_prop_2, 181, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_11$$4);
			ZEPHIR_CONCAT_SVSVS(&_11$$4, "Action '", &_9$$4, "' was not found on handler '", &_10$$4, "'");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_12$$4, 5);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "throwDispatchException", &_zephir_call_cache[5], &_11$$4, &_12$$4);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 2, 0);
	zephir_array_fast_append(&_13, &altHandler);
	zephir_array_fast_append(&_13, &altAction);
	ZEPHIR_CALL_FUNCTION(&_14, "array_values", NULL, 18, &altParams);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_13, &_14);
	zephir_check_call_status();
	zephir_read_property_cached(&_15, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_16 = Z_TYPE_P(&_15) != IS_NULL;
	if (_16) {
		zephir_memory_observe(&_17);
		zephir_read_property_cached(&_17, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_16 = zephir_instance_of_ev(&_17, phalcon_events_managerinterface_ce);
	}
	if (_16) {
		zephir_array_update_string(&observer, SL("result"), &result, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_18$$5, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_19$$5);
		ZVAL_STRING(&_19$$5, "dispatch:afterCallAction");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_18$$5, "fire", &_zephir_call_cache[6], &_19$$5, this_ptr, &observer);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);
}

/**
 * Process the results of the router by calling into the appropriate
 * controller action(s) including any routing data or injected parameters.
 *
 * @return mixed Returns the dispatched handler class (the Controller for Mvc dispatching or a Task
 *               for CLI dispatching) or <tt>false</tt> if an exception occurred and the operation was
 *               stopped by returning <tt>false</tt> in the exception handler.
 *
 * @throws \Exception if any uncaught or unhandled exception occurs during the dispatcher process.
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, dispatch)
{
	zval _41$$11, _33$$25;
	zend_bool hasService = 0, hasEventsManager = 0, isNewHandler = 0, _5$$5, _16$$14, _19$$16, _30$$11, _32$$11, _24$$20, _27$$22, _40$$26, _47$$28, _53$$34, _56$$36, _60$$40, _64$$42, _71$$45, _73$$45, _69$$48, _78$$53, _82$$55, _97$$67, _101$$71, _105$$73, _109$$77, _113$$79, _118$$84;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_28 = NULL;
	zval __$true, __$false, value, handler, container, namespaceName, handlerName, actionName, eventsManager, handlerClass, status, actionMethod, modelBinder, bindCacheKey, handlerHash, hookCache, e, _0, _1$$3, _2$$3, _3$$5, _4$$5, _6$$5, _7$$4, _8$$7, _9$$12, _10$$12, _11$$14, _12$$14, _13$$14, _14$$14, _15$$14, _17$$13, _18$$16, _20$$16, _21$$11, _29$$11, _31$$11, _35$$11, _36$$11, _37$$11, _58$$11, _89$$11, _95$$11, _107$$11, _22$$20, _23$$20, _25$$22, _26$$22, _34$$25, _38$$26, _39$$26, _42$$29, _43$$29, _44$$29, _45$$28, _46$$28, _48$$34, _49$$34, _50$$34, _51$$34, _52$$34, _54$$33, _55$$36, _57$$36, _59$$40, _61$$40, _62$$39, _63$$42, _65$$42, _66$$45, _72$$45, _74$$45, _67$$46, _68$$48, _70$$48, _75$$51, _76$$53, _77$$53, _79$$53, _80$$52, _81$$55, _83$$55, _84$$58, _85$$58, _86$$59, _87$$59, _88$$59, _90$$62, _91$$62, _92$$65, _93$$65, _94$$65, _96$$67, _98$$67, _99$$71, _100$$71, _102$$71, _103$$70, _104$$73, _106$$73, _108$$77, _110$$77, _111$$76, _112$$79, _114$$79, _115$$83, _116$$82, _117$$84, _119$$84, _120$$88, _121$$87, _122$$89;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberDispatches = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&handlerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&handlerHash);
	ZVAL_UNDEF(&hookCache);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_37$$11);
	ZVAL_UNDEF(&_58$$11);
	ZVAL_UNDEF(&_89$$11);
	ZVAL_UNDEF(&_95$$11);
	ZVAL_UNDEF(&_107$$11);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_34$$25);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$28);
	ZVAL_UNDEF(&_46$$28);
	ZVAL_UNDEF(&_48$$34);
	ZVAL_UNDEF(&_49$$34);
	ZVAL_UNDEF(&_50$$34);
	ZVAL_UNDEF(&_51$$34);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_54$$33);
	ZVAL_UNDEF(&_55$$36);
	ZVAL_UNDEF(&_57$$36);
	ZVAL_UNDEF(&_59$$40);
	ZVAL_UNDEF(&_61$$40);
	ZVAL_UNDEF(&_62$$39);
	ZVAL_UNDEF(&_63$$42);
	ZVAL_UNDEF(&_65$$42);
	ZVAL_UNDEF(&_66$$45);
	ZVAL_UNDEF(&_72$$45);
	ZVAL_UNDEF(&_74$$45);
	ZVAL_UNDEF(&_67$$46);
	ZVAL_UNDEF(&_68$$48);
	ZVAL_UNDEF(&_70$$48);
	ZVAL_UNDEF(&_75$$51);
	ZVAL_UNDEF(&_76$$53);
	ZVAL_UNDEF(&_77$$53);
	ZVAL_UNDEF(&_79$$53);
	ZVAL_UNDEF(&_80$$52);
	ZVAL_UNDEF(&_81$$55);
	ZVAL_UNDEF(&_83$$55);
	ZVAL_UNDEF(&_84$$58);
	ZVAL_UNDEF(&_85$$58);
	ZVAL_UNDEF(&_86$$59);
	ZVAL_UNDEF(&_87$$59);
	ZVAL_UNDEF(&_88$$59);
	ZVAL_UNDEF(&_90$$62);
	ZVAL_UNDEF(&_91$$62);
	ZVAL_UNDEF(&_92$$65);
	ZVAL_UNDEF(&_93$$65);
	ZVAL_UNDEF(&_94$$65);
	ZVAL_UNDEF(&_96$$67);
	ZVAL_UNDEF(&_98$$67);
	ZVAL_UNDEF(&_99$$71);
	ZVAL_UNDEF(&_100$$71);
	ZVAL_UNDEF(&_102$$71);
	ZVAL_UNDEF(&_103$$70);
	ZVAL_UNDEF(&_104$$73);
	ZVAL_UNDEF(&_106$$73);
	ZVAL_UNDEF(&_108$$77);
	ZVAL_UNDEF(&_110$$77);
	ZVAL_UNDEF(&_111$$76);
	ZVAL_UNDEF(&_112$$79);
	ZVAL_UNDEF(&_114$$79);
	ZVAL_UNDEF(&_115$$83);
	ZVAL_UNDEF(&_116$$82);
	ZVAL_UNDEF(&_117$$84);
	ZVAL_UNDEF(&_119$$84);
	ZVAL_UNDEF(&_120$$88);
	ZVAL_UNDEF(&_121$$87);
	ZVAL_UNDEF(&_122$$89);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_33$$25);
	ZEND_TLS zephir_method_cache _zephir_call_cache[41];
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
	static zend_string *_zephir_prop_14 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("finished", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("handlerHashes", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("activeHandler", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("handlerHookCache", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("namespaceName", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("handlerName", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("actionName", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("params", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("isControllerInitialize", 22, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("modelBinding", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_12)) {
		_zephir_prop_12 = zend_string_init("modelBinder", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_13)) {
		_zephir_prop_13 = zend_string_init("lastHandler", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_14)) {
		_zephir_prop_14 = zend_string_init("returnedValue", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 182, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "A dependency injection container is required to access related dispatching services");
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "throwDispatchException", &_zephir_call_cache[0], &_1$$3, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 179, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	hasEventsManager = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 183, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 183, &__$false);
	}
	if (hasEventsManager) {

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "dispatch:beforeDispatchLoop");
			ZEPHIR_CALL_METHOD_CACHED(&_3$$5, &eventsManager, "fire", &_zephir_call_cache[1], &_4$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			_5$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&_3$$5);
			if (_5$$5) {
				zephir_read_property_cached(&_6$$5, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
				_5$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(&_6$$5);
			}
			if (_5$$5) {
				RETURN_MM_BOOL(0);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_OBJ(&_7$$4, EG(exception));
			Z_ADDREF_P(&_7$$4);
			if (zephir_is_instance_of(&_7$$4, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_7$$4);
				ZEPHIR_CALL_METHOD_CACHED(&status, this_ptr, "handleException", &_zephir_call_cache[2], &e);
				zephir_check_call_status();
				zephir_read_property_cached(&_8$$7, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_8$$7)) {
					if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
						RETURN_MM_BOOL(0);
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 276);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	ZEPHIR_INIT_VAR(&handler);
	ZVAL_NULL(&handler);
	numberDispatches = 0;
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 183, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 183, &__$false);
	}
	while (1) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(!(zephir_is_true(&_0)))) {
			break;
		}
		numberDispatches++;
		if (UNEXPECTED(numberDispatches == 256)) {
			ZEPHIR_INIT_NVAR(&_9$$12);
			ZVAL_STRING(&_9$$12, "Dispatcher has detected a cyclic routing causing stability problems");
			ZVAL_LONG(&_10$$12, 1);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "throwDispatchException", &_zephir_call_cache[3], &_9$$12, &_10$$12);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 183, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 183, &__$false);
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "resolveEmptyProperties", &_zephir_call_cache[4]);
		zephir_check_call_status();
		if (hasEventsManager) {

			/* try_start_2: */

				ZEPHIR_INIT_NVAR(&_12$$14);
				ZVAL_STRING(&_12$$14, "dispatch:beforeDispatch");
				ZVAL_NULL(&_13$$14);
				ZVAL_BOOL(&_14$$14, 1);
				ZVAL_BOOL(&_15$$14, 1);
				ZEPHIR_CALL_METHOD_CACHED(&_11$$14, this_ptr, "fireManagerEvent", &_zephir_call_cache[5], &_12$$14, &_13$$14, &_14$$14, &_15$$14);
				zephir_check_call_status_or_jump(try_end_2);
				_16$$14 = ZEPHIR_IS_FALSE_IDENTICAL(&_11$$14);
				if (!(_16$$14)) {
					zephir_read_property_cached(&_13$$14, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_2;
					}
					_16$$14 = ZEPHIR_IS_FALSE_IDENTICAL(&_13$$14);
				}
				if (_16$$14) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_17$$13);
				ZVAL_OBJ(&_17$$13, EG(exception));
				Z_ADDREF_P(&_17$$13);
				if (zephir_is_instance_of(&_17$$13, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_17$$13);
					ZEPHIR_CALL_METHOD_CACHED(&_18$$16, this_ptr, "handleException", &_zephir_call_cache[6], &e);
					zephir_check_call_status();
					_19$$16 = ZEPHIR_IS_FALSE_IDENTICAL(&_18$$16);
					if (!(_19$$16)) {
						zephir_read_property_cached(&_20$$16, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_19$$16 = ZEPHIR_IS_FALSE_IDENTICAL(&_20$$16);
					}
					if (_19$$16) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 322);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&handlerClass, this_ptr, "getHandlerClass", &_zephir_call_cache[7]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_21$$11, &container, "has", &_zephir_call_cache[8], &handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(&_21$$11);
		if (!(hasService)) {
			hasService = zephir_class_exists(&handlerClass, 1);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_NVAR(&_22$$20);
			ZEPHIR_CONCAT_VS(&_22$$20, &handlerClass, " handler class cannot be loaded");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_23$$20, 2);
			ZEPHIR_CALL_METHOD_CACHED(&status, this_ptr, "throwDispatchException", &_zephir_call_cache[9], &_22$$20, &_23$$20);
			zephir_check_call_status();
			_24$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_24$$20) {
				zephir_read_property_cached(&_23$$20, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_24$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&_23$$20);
			}
			if (_24$$20) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD_CACHED(&handler, &container, "getShared", &_zephir_call_cache[10], &handlerClass);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&handler) != IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(&_25$$22);
			ZVAL_STRING(&_25$$22, "Invalid handler returned from the services container");
			ZVAL_LONG(&_26$$22, 3);
			ZEPHIR_CALL_METHOD_CACHED(&status, this_ptr, "throwDispatchException", &_zephir_call_cache[11], &_25$$22, &_26$$22);
			zephir_check_call_status();
			_27$$22 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_27$$22) {
				zephir_read_property_cached(&_26$$22, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_27$$22 = ZEPHIR_IS_FALSE_IDENTICAL(&_26$$22);
			}
			if (_27$$22) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_FUNCTION(&handlerHash, "spl_object_id", &_28, 30, &handler);
		zephir_check_call_status();
		zephir_read_property_cached(&_29$$11, this_ptr, _zephir_prop_3, 184, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_30$$11 = zephir_array_isset_value(&_29$$11, &handlerHash);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		isNewHandler = !(_30$$11);
		if (isNewHandler) {
			zephir_update_property_array(this_ptr, SL("handlerHashes"), &handlerHash, &__$true);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 185, &handler);
		zephir_read_property_cached(&_31$$11, this_ptr, _zephir_prop_5, 186, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_32$$11 = zephir_array_isset_value(&_31$$11, &handlerClass);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_32$$11)) {
			ZEPHIR_INIT_NVAR(&_33$$25);
			zephir_create_array(&_33$$25, 4, 0);
			ZEPHIR_INIT_NVAR(&_34$$25);
			ZVAL_BOOL(&_34$$25, (zephir_method_exists_ex(&handler, ZEND_STRL("beforeexecuteroute")) == SUCCESS));
			zephir_array_fast_append(&_33$$25, &_34$$25);
			ZEPHIR_INIT_NVAR(&_34$$25);
			ZVAL_BOOL(&_34$$25, (zephir_method_exists_ex(&handler, ZEND_STRL("initialize")) == SUCCESS));
			zephir_array_fast_append(&_33$$25, &_34$$25);
			ZEPHIR_INIT_NVAR(&_34$$25);
			ZVAL_BOOL(&_34$$25, (zephir_method_exists_ex(&handler, ZEND_STRL("afterbinding")) == SUCCESS));
			zephir_array_fast_append(&_33$$25, &_34$$25);
			ZEPHIR_INIT_NVAR(&_34$$25);
			ZVAL_BOOL(&_34$$25, (zephir_method_exists_ex(&handler, ZEND_STRL("afterexecuteroute")) == SUCCESS));
			zephir_array_fast_append(&_33$$25, &_34$$25);
			zephir_update_property_array(this_ptr, SL("handlerHookCache"), &handlerClass, &_33$$25);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_read_property_cached(&_35$$11, this_ptr, _zephir_prop_5, 186, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&hookCache);
		zephir_array_fetch(&hookCache, &_35$$11, &handlerClass, PH_NOISY, "phalcon/Dispatcher/AbstractDispatcher.zep", 390);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_36$$11, this_ptr, _zephir_prop_6, 187, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&namespaceName, &_36$$11);
		zephir_read_property_cached(&_36$$11, this_ptr, _zephir_prop_7, 181, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&handlerName, &_36$$11);
		zephir_read_property_cached(&_36$$11, this_ptr, _zephir_prop_8, 180, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&actionName, &_36$$11);
		ZEPHIR_OBS_NVAR(&_37$$11);
		zephir_read_property_cached(&_37$$11, this_ptr, _zephir_prop_9, 188, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&_37$$11) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&_38$$26);
			ZVAL_STRING(&_38$$26, "Action parameters must be an Array");
			ZVAL_LONG(&_39$$26, 4);
			ZEPHIR_CALL_METHOD_CACHED(&status, this_ptr, "throwDispatchException", &_zephir_call_cache[12], &_38$$26, &_39$$26);
			zephir_check_call_status();
			_40$$26 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_40$$26) {
				zephir_read_property_cached(&_39$$26, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_40$$26 = ZEPHIR_IS_FALSE_IDENTICAL(&_39$$26);
			}
			if (_40$$26) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD_CACHED(&actionMethod, this_ptr, "getActiveMethod", &_zephir_call_cache[13]);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_41$$11);
		zephir_create_array(&_41$$11, 2, 0);
		zephir_array_fast_append(&_41$$11, &handler);
		zephir_array_fast_append(&_41$$11, &actionMethod);
		if (UNEXPECTED(!(zephir_is_callable(&_41$$11)))) {
			if (hasEventsManager) {
				ZEPHIR_INIT_NVAR(&_43$$29);
				ZVAL_STRING(&_43$$29, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD_CACHED(&_42$$29, &eventsManager, "fire", &_zephir_call_cache[14], &_43$$29, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_42$$29)) {
					continue;
				}
				zephir_read_property_cached(&_44$$29, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_44$$29)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_45$$28);
			ZEPHIR_CONCAT_SVSVS(&_45$$28, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_46$$28, 5);
			ZEPHIR_CALL_METHOD_CACHED(&status, this_ptr, "throwDispatchException", &_zephir_call_cache[15], &_45$$28, &_46$$28);
			zephir_check_call_status();
			_47$$28 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_47$$28) {
				zephir_read_property_cached(&_46$$28, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_47$$28 = ZEPHIR_IS_FALSE_IDENTICAL(&_46$$28);
			}
			if (_47$$28) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_49$$34);
				ZVAL_STRING(&_49$$34, "dispatch:beforeExecuteRoute");
				ZVAL_NULL(&_50$$34);
				ZVAL_BOOL(&_51$$34, 1);
				ZVAL_BOOL(&_52$$34, 1);
				ZEPHIR_CALL_METHOD_CACHED(&_48$$34, this_ptr, "fireManagerEvent", &_zephir_call_cache[16], &_49$$34, &_50$$34, &_51$$34, &_52$$34);
				zephir_check_call_status_or_jump(try_end_3);
				_53$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_48$$34);
				if (!(_53$$34)) {
					zephir_read_property_cached(&_50$$34, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_3;
					}
					_53$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_50$$34);
				}
				if (_53$$34) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &container, "remove", &_zephir_call_cache[17], &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_54$$33);
				ZVAL_OBJ(&_54$$33, EG(exception));
				Z_ADDREF_P(&_54$$33);
				if (zephir_is_instance_of(&_54$$33, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_54$$33);
					ZEPHIR_CALL_METHOD_CACHED(&_55$$36, this_ptr, "handleException", &_zephir_call_cache[18], &e);
					zephir_check_call_status();
					_56$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_55$$36);
					if (!(_56$$36)) {
						zephir_read_property_cached(&_57$$36, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_56$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_57$$36);
					}
					if (_56$$36) {
						ZEPHIR_CALL_METHOD_CACHED(NULL, &container, "remove", &_zephir_call_cache[19], &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 476);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_OBS_NVAR(&_58$$11);
		zephir_array_fetch_long(&_58$$11, &hookCache, 0, PH_NOISY, "phalcon/Dispatcher/AbstractDispatcher.zep", 480);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_is_true(&_58$$11)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD_CACHED(&_59$$40, &handler, "beforeExecuteRoute", &_zephir_call_cache[20], this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_60$$40 = ZEPHIR_IS_FALSE_IDENTICAL(&_59$$40);
				if (!(_60$$40)) {
					zephir_read_property_cached(&_61$$40, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_4;
					}
					_60$$40 = ZEPHIR_IS_FALSE_IDENTICAL(&_61$$40);
				}
				if (_60$$40) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &container, "remove", &_zephir_call_cache[21], &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_62$$39);
				ZVAL_OBJ(&_62$$39, EG(exception));
				Z_ADDREF_P(&_62$$39);
				if (zephir_is_instance_of(&_62$$39, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_62$$39);
					ZEPHIR_CALL_METHOD_CACHED(&_63$$42, this_ptr, "handleException", &_zephir_call_cache[22], &e);
					zephir_check_call_status();
					_64$$42 = ZEPHIR_IS_FALSE_IDENTICAL(&_63$$42);
					if (!(_64$$42)) {
						zephir_read_property_cached(&_65$$42, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_64$$42 = ZEPHIR_IS_FALSE_IDENTICAL(&_65$$42);
					}
					if (_64$$42) {
						ZEPHIR_CALL_METHOD_CACHED(NULL, &container, "remove", &_zephir_call_cache[23], &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 499);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (isNewHandler) {
			ZEPHIR_OBS_NVAR(&_66$$45);
			zephir_array_fetch_long(&_66$$45, &hookCache, 1, PH_NOISY, "phalcon/Dispatcher/AbstractDispatcher.zep", 523);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(&_66$$45)) {

				/* try_start_5: */

					if (1) {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 189, &__$true);
					} else {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 189, &__$false);
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &handler, "initialize", &_zephir_call_cache[24]);
					zephir_check_call_status_or_jump(try_end_5);

				try_end_5:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_67$$46);
					ZVAL_OBJ(&_67$$46, EG(exception));
					Z_ADDREF_P(&_67$$46);
					if (zephir_is_instance_of(&_67$$46, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_67$$46);
						if (0) {
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 189, &__$true);
						} else {
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 189, &__$false);
						}
						ZEPHIR_CALL_METHOD_CACHED(&_68$$48, this_ptr, "handleException", &_zephir_call_cache[25], &e);
						zephir_check_call_status();
						_69$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_68$$48);
						if (!(_69$$48)) {
							zephir_read_property_cached(&_70$$48, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_69$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_70$$48);
						}
						if (_69$$48) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 545);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 189, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 189, &__$false);
			}
			_71$$45 = !hasEventsManager;
			if (_71$$45) {
				zephir_read_property_cached(&_72$$45, this_ptr, _zephir_prop_1, 179, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_71$$45 = Z_TYPE_P(&_72$$45) != IS_NULL;
			}
			_73$$45 = _71$$45;
			if (_73$$45) {
				ZEPHIR_OBS_NVAR(&_74$$45);
				zephir_read_property_cached(&_74$$45, this_ptr, _zephir_prop_1, 179, PH_NOISY_CC);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_73$$45 = zephir_instance_of_ev(&_74$$45, phalcon_events_managerinterface_ce);
			}
			if (_73$$45) {
				zephir_read_property_cached(&_75$$51, this_ptr, _zephir_prop_1, 179, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&eventsManager, &_75$$51);
				hasEventsManager = 1;
			}
			if (zephir_is_true(&eventsManager)) {

				/* try_start_6: */

					ZEPHIR_INIT_NVAR(&_77$$53);
					ZVAL_STRING(&_77$$53, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD_CACHED(&_76$$53, &eventsManager, "fire", &_zephir_call_cache[26], &_77$$53, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_78$$53 = ZEPHIR_IS_FALSE_IDENTICAL(&_76$$53);
					if (!(_78$$53)) {
						zephir_read_property_cached(&_79$$53, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							goto try_end_6;
						}
						_78$$53 = ZEPHIR_IS_FALSE_IDENTICAL(&_79$$53);
					}
					if (_78$$53) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_80$$52);
					ZVAL_OBJ(&_80$$52, EG(exception));
					Z_ADDREF_P(&_80$$52);
					if (zephir_is_instance_of(&_80$$52, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_80$$52);
						ZEPHIR_CALL_METHOD_CACHED(&_81$$55, this_ptr, "handleException", &_zephir_call_cache[27], &e);
						zephir_check_call_status();
						_82$$55 = ZEPHIR_IS_FALSE_IDENTICAL(&_81$$55);
						if (!(_82$$55)) {
							zephir_read_property_cached(&_83$$55, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_82$$55 = ZEPHIR_IS_FALSE_IDENTICAL(&_83$$55);
						}
						if (_82$$55) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 583);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property_cached(&_36$$11, this_ptr, _zephir_prop_11, 190, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_is_true(&_36$$11)) {
			zephir_read_property_cached(&_84$$58, this_ptr, _zephir_prop_12, 191, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&modelBinder, &_84$$58);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_84$$58, this_ptr, _zephir_prop_9, 188, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_85$$58, &modelBinder, "bindToHandler", &_zephir_call_cache[28], &handler, &_84$$58, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 188, &_85$$58);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_87$$59);
			ZVAL_STRING(&_87$$59, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD_CACHED(&_86$$59, &eventsManager, "fire", &_zephir_call_cache[29], &_87$$59, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_86$$59)) {
				continue;
			}
			zephir_read_property_cached(&_88$$59, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_88$$59)) {
				continue;
			}
		}
		ZEPHIR_OBS_NVAR(&_89$$11);
		zephir_array_fetch_long(&_89$$11, &hookCache, 2, PH_NOISY, "phalcon/Dispatcher/AbstractDispatcher.zep", 629);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_is_true(&_89$$11)) {
			ZEPHIR_CALL_METHOD_CACHED(&_90$$62, &handler, "afterBinding", &_zephir_call_cache[30], this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_90$$62)) {
				continue;
			}
			zephir_read_property_cached(&_91$$62, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_91$$62)) {
				continue;
			}
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 192, &handler);

		/* try_start_7: */

			zephir_read_property_cached(&_93$$65, this_ptr, _zephir_prop_9, 188, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_7;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_92$$65, this_ptr, "callActionMethod", &_zephir_call_cache[31], &handler, &actionMethod, &_93$$65);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_14, 193, &_92$$65);
			zephir_read_property_cached(&_94$$65, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_7;
			}
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_94$$65)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_95$$11);
			ZVAL_OBJ(&_95$$11, EG(exception));
			Z_ADDREF_P(&_95$$11);
			if (zephir_is_instance_of(&_95$$11, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_95$$11);
				ZEPHIR_CALL_METHOD_CACHED(&_96$$67, this_ptr, "handleException", &_zephir_call_cache[32], &e);
				zephir_check_call_status();
				_97$$67 = ZEPHIR_IS_FALSE_IDENTICAL(&_96$$67);
				if (!(_97$$67)) {
					zephir_read_property_cached(&_98$$67, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_97$$67 = ZEPHIR_IS_FALSE_IDENTICAL(&_98$$67);
				}
				if (_97$$67) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 668);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_100$$71);
				ZVAL_STRING(&_100$$71, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD_CACHED(&_99$$71, &eventsManager, "fire", &_zephir_call_cache[33], &_100$$71, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_101$$71 = ZEPHIR_IS_FALSE_IDENTICAL(&_99$$71);
				if (!(_101$$71)) {
					zephir_read_property_cached(&_102$$71, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_8;
					}
					_101$$71 = ZEPHIR_IS_FALSE_IDENTICAL(&_102$$71);
				}
				if (_101$$71) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_103$$70);
				ZVAL_OBJ(&_103$$70, EG(exception));
				Z_ADDREF_P(&_103$$70);
				if (zephir_is_instance_of(&_103$$70, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_103$$70);
					ZEPHIR_CALL_METHOD_CACHED(&_104$$73, this_ptr, "handleException", &_zephir_call_cache[34], &e);
					zephir_check_call_status();
					_105$$73 = ZEPHIR_IS_FALSE_IDENTICAL(&_104$$73);
					if (!(_105$$73)) {
						zephir_read_property_cached(&_106$$73, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_105$$73 = ZEPHIR_IS_FALSE_IDENTICAL(&_106$$73);
					}
					if (_105$$73) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 690);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_OBS_NVAR(&_107$$11);
		zephir_array_fetch_long(&_107$$11, &hookCache, 3, PH_NOISY, "phalcon/Dispatcher/AbstractDispatcher.zep", 697);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_is_true(&_107$$11)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD_CACHED(&_108$$77, &handler, "afterExecuteRoute", &_zephir_call_cache[35], this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_109$$77 = ZEPHIR_IS_FALSE_IDENTICAL(&_108$$77);
				if (!(_109$$77)) {
					zephir_read_property_cached(&_110$$77, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_9;
					}
					_109$$77 = ZEPHIR_IS_FALSE_IDENTICAL(&_110$$77);
				}
				if (_109$$77) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_111$$76);
				ZVAL_OBJ(&_111$$76, EG(exception));
				Z_ADDREF_P(&_111$$76);
				if (zephir_is_instance_of(&_111$$76, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_111$$76);
					ZEPHIR_CALL_METHOD_CACHED(&_112$$79, this_ptr, "handleException", &_zephir_call_cache[36], &e);
					zephir_check_call_status();
					_113$$79 = ZEPHIR_IS_FALSE_IDENTICAL(&_112$$79);
					if (!(_113$$79)) {
						zephir_read_property_cached(&_114$$79, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_113$$79 = ZEPHIR_IS_FALSE_IDENTICAL(&_114$$79);
					}
					if (_113$$79) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 713);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_115$$83);
				ZVAL_STRING(&_115$$83, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[37], &_115$$83, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_116$$82);
				ZVAL_OBJ(&_116$$82, EG(exception));
				Z_ADDREF_P(&_116$$82);
				if (zephir_is_instance_of(&_116$$82, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_116$$82);
					ZEPHIR_CALL_METHOD_CACHED(&_117$$84, this_ptr, "handleException", &_zephir_call_cache[38], &e);
					zephir_check_call_status();
					_118$$84 = ZEPHIR_IS_FALSE_IDENTICAL(&_117$$84);
					if (!(_118$$84)) {
						zephir_read_property_cached(&_119$$84, this_ptr, _zephir_prop_2, 183, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_118$$84 = ZEPHIR_IS_FALSE_IDENTICAL(&_119$$84);
					}
					if (_118$$84) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 733);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_120$$88);
			ZVAL_STRING(&_120$$88, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[39], &_120$$88, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_121$$87);
			ZVAL_OBJ(&_121$$87, EG(exception));
			Z_ADDREF_P(&_121$$87);
			if (zephir_is_instance_of(&_121$$87, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_121$$87);
				ZEPHIR_CALL_METHOD_CACHED(&_122$$89, this_ptr, "handleException", &_zephir_call_cache[40], &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_122$$89)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 750);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_CCTOR(&handler);
}

/**
 * Forwards the execution flow to another controller/action.
 *
 * ```php
 * $this->dispatcher->forward(
 *     [
 *         "controller" => "posts",
 *         "action"     => "index",
 *     ]
 * );
 * ```
 *
 * @phpstan-param dispatcher_forward $forward
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, forward)
{
	zend_bool _5, _6, _7, _8, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *forward_param = NULL, __$true, __$false, namespaceName, controllerName, params, actionName, taskName, _0, _2, _3, _4, _1$$3;
	zval forward;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&forward);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&taskName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isControllerInitialize", 22, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("namespaceName", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("previousNamespaceName", 21, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("handlerName", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("previousHandlerName", 19, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("actionName", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("previousActionName", 18, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("params", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("finished", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("forwarded", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(forward, forward_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &forward_param);
	zephir_get_arrval(&forward, forward_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 189, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_dispatcher_exceptions_forwardininitializeforbidden_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Dispatcher/AbstractDispatcher.zep", 782);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 187, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 194, &_2);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_3, 181, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 195, &_3);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_5, 180, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 196, &_4);
	zephir_memory_observe(&namespaceName);
	_5 = zephir_array_isset_string_fetch(&namespaceName, &forward, SL("namespace"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 187, &namespaceName);
	}
	zephir_memory_observe(&controllerName);
	_6 = zephir_array_isset_string_fetch(&controllerName, &forward, SL("controller"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 181, &controllerName);
	} else {
		zephir_memory_observe(&taskName);
		_7 = zephir_array_isset_string_fetch(&taskName, &forward, SL("task"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_7) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 181, &taskName);
		}
	}
	zephir_memory_observe(&actionName);
	_8 = zephir_array_isset_string_fetch(&actionName, &forward, SL("action"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_8) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 180, &actionName);
	}
	zephir_memory_observe(&params);
	_9 = zephir_array_isset_string_fetch(&params, &forward, SL("params"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 188, &params);
	}
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 183, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 183, &__$false);
	}
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 197, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 197, &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Gets the latest dispatched action name
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getActionName)
{

	RETURN_MEMBER_TYPED(getThis(), "actionName", IS_STRING);
}

/**
 * Gets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getActionSuffix)
{

	RETURN_MEMBER_TYPED(getThis(), "actionSuffix", IS_STRING);
}

/**
 * Returns the current method to be/executed in the dispatcher
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getActiveMethod)
{
	zend_bool _2;
	zval activeMethodName, _0, _1, _6, _3$$3, _4$$3, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&activeMethodName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("activeMethodMap", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("actionName", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("actionSuffix", 12, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&activeMethodName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 198, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 180, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_fetch(&activeMethodName, &_0, &_1, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 180, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_3$$3, this_ptr, "toCamelCase", &_zephir_call_cache[0], &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&activeMethodName, "lcfirst", NULL, 57, &_3$$3);
		zephir_check_call_status();
		zephir_memory_observe(&_5$$3);
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 180, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array(this_ptr, SL("activeMethodMap"), &_5$$3, &activeMethodName);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 199, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CONCAT_VV(return_value, &activeMethodName, &_6);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Returns bound models from binder instance
 *
 * ```php
 * class UserController extends Controller
 * {
 *     public function showAction(User $user)
 *     {
 *         // return array with $user
 *         $boundModels = $this->dispatcher->getBoundModels();
 *     }
 * }
 * ```
 *
 * @phpstan-return dispatcher_bound_models
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getBoundModels)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelBinder", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 191, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 191, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_1, "getBoundModels", &_zephir_call_cache[0]);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getDefaultNamespace)
{

	RETURN_MEMBER_TYPED(getThis(), "defaultNamespace", IS_STRING);
}

/**
 * Possible class name that will be located to dispatch the request
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getHandlerClass)
{
	zval handlerSuffix, handlerName, namespaceName, camelizedClass, handlerClass, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerSuffix);
	ZVAL_UNDEF(&handlerName);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&camelizedClass);
	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("handlerSuffix", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("handlerName", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("namespaceName", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "resolveEmptyProperties", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 200, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&handlerSuffix, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 181, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&handlerName, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 187, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&namespaceName, &_0);
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/Dispatcher/AbstractDispatcher.zep", 903))) {
		ZEPHIR_CALL_METHOD_CACHED(&camelizedClass, this_ptr, "toCamelCase", &_zephir_call_cache[1], &handlerName);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&camelizedClass, &handlerName);
	}
	ZEPHIR_INIT_VAR(&handlerClass);
	if (zephir_is_true(&namespaceName)) {
		if (!(zephir_end_with_str(&namespaceName, SL("\\")))) {
			zephir_concat_self_str(&namespaceName, SL("\\"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CONCAT_VVV(&handlerClass, &namespaceName, &camelizedClass, &handlerSuffix);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CONCAT_VV(&handlerClass, &camelizedClass, &handlerSuffix);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&handlerClass);
}

/**
 * Gets the default handler suffix
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getHandlerSuffix)
{

	RETURN_MEMBER_TYPED(getThis(), "handlerSuffix", IS_STRING);
}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getModelBinder)
{

	RETURN_MEMBER(getThis(), "modelBinder");
}

/**
 * Gets the module where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getModuleName)
{

	RETURN_MEMBER(getThis(), "moduleName");
}

/**
 * Gets a namespace to be prepended to the current handler name
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getNamespaceName)
{

	RETURN_MEMBER_TYPED(getThis(), "namespaceName", IS_STRING);
}

/**
 * Gets a param by its name or numeric index
 *
 * @phpstan-param array-key $param
 * @phpstan-param mixed $filters
 * @param mixed             $defaultValue
 *
 * @deprecated Use getParameter() instead
 *
 * Note: The interface declares `getParam(param, filters = null)` without the
 * `defaultValue` argument, so code typed against `DispatcherInterface`
 * cannot use the default-value feature. This signature drift is intentional
 * for now; the interface and implementation will be aligned in the next
 * major version.
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &param, &filters, &defaultValue);
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getParameter", &_zephir_call_cache[0], param, filters, defaultValue);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets a param by its name or numeric index
 *
 * @phpstan-param array-key $param
 * @phpstan-param mixed $filters
 * @param mixed             $defaultValue
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParameter)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null, params, filter, paramValue, _0, _4, _5, _6, _2$$5, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("container", 9, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &param, &filters, &defaultValue);
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 188, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&params, &_0);
	zephir_memory_observe(&paramValue);
	_1 = zephir_array_isset_fetch(&paramValue, &params, param, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) == IS_NULL) {
		RETURN_CCTOR(&paramValue);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 182, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "A dependency injection container is required to access the 'filter' service");
		ZVAL_LONG(&_3$$5, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "throwDispatchException", &_zephir_call_cache[0], &_2$$5, &_3$$5);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 182, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "filter");
	ZEPHIR_CALL_METHOD_CACHED(&_5, &_4, "getShared", &_zephir_call_cache[1], &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filter, &_5);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&filter, "sanitize", &_zephir_call_cache[2], &paramValue, filters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets action params
 *
 * @phpstan-return dispatcher_params
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParameters)
{

	RETURN_MEMBER_TYPED(getThis(), "params", IS_ARRAY);
}

/**
 * Gets action params
 *
 * @deprecated Use getParameters() instead
 *
 * @phpstan-return dispatcher_params
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getParameters", &_zephir_call_cache[0]);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets previous dispatched action name
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getPreviousActionName)
{

	RETURN_MEMBER_TYPED(getThis(), "previousActionName", IS_STRING);
}

/**
 * Gets previous dispatched handler name
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getPreviousHandlerName)
{

	RETURN_MEMBER_TYPED(getThis(), "previousHandlerName", IS_STRING);
}

/**
 * Gets previous dispatched namespace name
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getPreviousNamespaceName)
{

	RETURN_MEMBER_TYPED(getThis(), "previousNamespaceName", IS_STRING);
}

/**
 * Returns value returned by the latest dispatched action
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getReturnedValue)
{

	RETURN_MEMBER(getThis(), "returnedValue");
}

/**
 * Check if a param exists
 *
 * @phpstan-param array-key $param
 *
 * @deprecated Use hasParameter() instead
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, hasParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &param);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "hasParameter", &_zephir_call_cache[0], param);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check if a param exists
 *
 * @phpstan-param array-key $param
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, hasParameter)
{
	zend_bool _1;
	zval *param, param_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 188, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, param);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
}

/**
 * Checks if the dispatch loop is finished or has more pendent
 * controllers/tasks to dispatch
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, isFinished)
{

	RETURN_MEMBER(getThis(), "finished");
}

/**
 * Sets the action name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setActionName)
{
	zval actionName_zv;
	zend_string *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionName", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionName_zv, actionName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 180, &actionName_zv);
}

/**
 * Sets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setActionSuffix)
{
	zval actionSuffix_zv;
	zend_string *actionSuffix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionSuffix", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionSuffix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionSuffix_zv, actionSuffix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 199, &actionSuffix_zv);
}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setDefaultAction)
{
	zval actionName_zv;
	zend_string *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultAction", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionName_zv, actionName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 201, &actionName_zv);
}

/**
 * Sets the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setDefaultNamespace)
{
	zval defaultNamespace_zv;
	zend_string *defaultNamespace = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultNamespace_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultNamespace", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(defaultNamespace)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&defaultNamespace_zv, defaultNamespace);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 202, &defaultNamespace_zv);
}

/**
 * Sets the default suffix for the handler
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setHandlerSuffix)
{
	zval handlerSuffix_zv;
	zend_string *handlerSuffix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerSuffix_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("handlerSuffix", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(handlerSuffix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&handlerSuffix_zv, handlerSuffix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 200, &handlerSuffix_zv);
}

/**
 * Enable model binding during dispatch
 *
 * ```php
 * $di->set(
 *     'dispatcher',
 *     function() {
 *         $dispatcher = new Dispatcher();
 *
 *         $dispatcher->setModelBinder(
 *             new Binder(),
 *             'cache'
 *         );
 *
 *         return $dispatcher;
 *     }
 * );
 * ```
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setModelBinder)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelBinder, modelBinder_sub, *cache = NULL, cache_sub, __$true, __$false, __$null, container, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelBinding", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("modelBinder", 11, 1);
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
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 182, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, &container, "get", &_zephir_call_cache[0], cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_1$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, modelBinder, "setCache", &_zephir_call_cache[1], cache);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 190, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 190, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 191, modelBinder);
	RETURN_THIS();
}

/**
 * Sets the module where the controller is (only informative)
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setModuleName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval moduleName_zv;
	zend_string *moduleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("moduleName", 10, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(moduleName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!moduleName) {
		ZEPHIR_INIT_VAR(&moduleName_zv);
	} else {
		zephir_memory_observe(&moduleName_zv);
	ZVAL_STR_COPY(&moduleName_zv, moduleName);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 203, &moduleName_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the namespace where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setNamespaceName)
{
	zval namespaceName_zv;
	zend_string *namespaceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("namespaceName", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(namespaceName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&namespaceName_zv, namespaceName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 187, &namespaceName_zv);
}

/**
 * Set a param by its name or numeric index
 *
 * @deprecated Use setParameter() instead
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(param)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &param, &value);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setParameter", &_zephir_call_cache[0], param, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Set a param by its name or numeric index
 *
 * @phpstan-param array-key $param
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParameter)
{
	zval *param, param_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(param)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &param, &value);
	zephir_update_property_array(this_ptr, SL("params"), param, value);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
}

/**
 * Sets action params to be dispatched
 *
 * @phpstan-param dispatcher_params $params
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParameters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &params_param);
	zephir_get_arrval(&params, params_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 188, &params);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets action params to be dispatched
 *
 * @deprecated Use setParameters() instead
 *
 * @phpstan-param dispatcher_params $params
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &params_param);
	zephir_get_arrval(&params, params_param);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setParameters", &_zephir_call_cache[0], &params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the latest returned value by an action manually
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setReturnedValue)
{
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("returnedValue", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &value);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 193, value);
}

/**
 * Check if the current executed action was forwarded by another one
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, wasForwarded)
{

	RETURN_MEMBER(getThis(), "forwarded");
}

/**
 * Handles a user exception triggered inside the dispatch loop.
 *
 * Subclasses implement the namespace-specific behavior (typically firing
 * the `dispatch:beforeException` event so listeners may forward or swallow
 * the exception).
 *
 * @param \Exception exception
 *
 * @return mixed Return `false` to signal that the exception was handled
 *               (swallowed) and the current loop iteration should stop.
 *               Any other return value (including null) lets the caller
 *               bubble the exception, unless a forward was requested
 *               (`finished === false`).
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, handleException)
{
}

/**
 * Set empty properties to their defaults (where defaults are available)
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, resolveEmptyProperties)
{
	zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("namespaceName", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("defaultNamespace", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("handlerName", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("defaultHandler", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("actionName", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("defaultAction", 13, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 187, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	if (!(zephir_is_true(&_0))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 202, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 187, &_1$$3);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 181, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	if (!(zephir_is_true(&_2))) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_3, 204, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 181, &_3$$4);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_4, 180, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	if (!(zephir_is_true(&_4))) {
		zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_5, 201, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 180, &_5$$5);
	}
}

/**
 * Throws an internal dispatch exception.
 *
 * Subclasses build the namespace-specific exception and route it through
 * handleException() before throwing it when it was not handled.
 *
 * @param string message
 * @param int    exceptionCode
 *
 * @return mixed Returns `false` when handleException() swallowed the
 *               exception; otherwise the method throws and does not return.
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, throwDispatchException)
{
}

PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, toCamelCase)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, camelCaseInput, _0, _2$$3, _3$$3, _4$$3;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&camelCaseInput);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("camelCaseMap", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_memory_observe(&camelCaseInput);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 205, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&camelCaseInput, &_0, &input_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/[_-]+/");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "preg_split", NULL, 58, &_2$$3, &input_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "ucfirst");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "array_map", NULL, 59, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&camelCaseInput);
		zephir_fast_join_str(&camelCaseInput, SL(""), &_4$$3);
		zephir_update_property_array(this_ptr, SL("camelCaseMap"), &input_zv, &camelCaseInput);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&camelCaseInput);
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setEventsManager)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0, _1, _3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eventsManager);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "container");
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 7, this_ptr, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		zephir_memory_observe(&_3);
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 182, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_2 = Z_TYPE_P(&_3) != IS_NULL;
	}
	if (_2) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 182, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "eventsManager");
		ZVAL_BOOL(&_6$$3, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$3, "set", &_zephir_call_cache[0], &_5$$3, eventsManager, &_6$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 179, eventsManager);
	ZEPHIR_MM_RESTORE();
}

/**
 * Helper method to fire an event
 * 
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, fireManagerEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancellable, stopOnFalse, _1$$3;
	zval eventName_zv, *data = NULL, data_sub, *cancellable_param = NULL, *stopOnFalse_param = NULL, __$null, _0, _2$$3, _6$$3, _7$$3, _3$$4, _4$$4, _5$$4;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
		Z_PARAM_BOOL(stopOnFalse)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cancellable_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		stopOnFalse_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancellable_param) {
		cancellable = 1;
	} else {
		}
	if (!stopOnFalse_param) {
		stopOnFalse = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) != IS_NULL) {
		_1$$3 = stopOnFalse;
		if (_1$$3) {
			zephir_memory_observe(&_2$$3);
			zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_1$$3 = zephir_instance_of_ev(&_2$$3, phalcon_events_manager_ce);
		}
		if (_1$$3) {
			zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (cancellable) {
				ZVAL_BOOL(&_4$$4, 1);
			} else {
				ZVAL_BOOL(&_4$$4, 0);
			}
			ZVAL_BOOL(&_5$$4, 1);
			ZEPHIR_RETURN_CALL_METHOD_CACHED(&_3$$4, "fire", &_zephir_call_cache[0], &eventName_zv, this_ptr, data, &_4$$4, &_5$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 179, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (cancellable) {
			ZVAL_BOOL(&_7$$3, 1);
		} else {
			ZVAL_BOOL(&_7$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&_6$$3, "fire", &_zephir_call_cache[1], &eventName_zv, this_ptr, data, &_7$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

