
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
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
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
	zval *handler, handler_sub, actionMethod_zv, *params_param = NULL, result, observer, altHandler, altAction, altParams, _0, _2, _14, _15, _17, _4$$3, _5$$3, _6$$3, _7$$3, _9$$4, _10$$4, _11$$4, _12$$4, _18$$5, _19$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&actionMethod_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&observer);
	ZVAL_UNDEF(&altHandler);
	ZVAL_UNDEF(&altAction);
	ZVAL_UNDEF(&altParams);
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
	ZEPHIR_CPY_WRT(&altHandler, handler);
	ZEPHIR_CPY_WRT(&altAction, &actionMethod_zv);
	ZEPHIR_CPY_WRT(&altParams, &params);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) != IS_NULL;
	if (_1) {
		zephir_memory_observe(&_2);
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC);
		_1 = zephir_instance_of_ev(&_2, phalcon_events_managerinterface_ce);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&observer);
		object_init_ex(&observer, phalcon_support_collection_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		zephir_array_update_string(&_3$$3, SL("handler"), handler, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("action"), &actionMethod_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("params"), &params, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &observer, "__construct", NULL, 42, &_3$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "dispatch:beforeCallAction");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "fire", NULL, 0, &_5$$3, this_ptr, &observer);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "handler");
		ZEPHIR_CALL_METHOD(&altHandler, &observer, "get", NULL, 187, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "action");
		ZEPHIR_CALL_METHOD(&altAction, &observer, "get", NULL, 187, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		array_init(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "params");
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "array");
		ZEPHIR_CALL_METHOD(&altParams, &observer, "get", NULL, 187, &_6$$3, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 2, 0);
		zephir_array_fast_append(&_8$$3, &altHandler);
		zephir_array_fast_append(&_8$$3, &altAction);
		if (UNEXPECTED(!(zephir_is_callable(&_8$$3)))) {
			zephir_read_property_cached(&_9$$4, this_ptr, _zephir_prop_1, 174, PH_NOISY_CC | PH_READONLY);
			zephir_read_property_cached(&_10$$4, this_ptr, _zephir_prop_2, 175, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_11$$4);
			ZEPHIR_CONCAT_SVSVS(&_11$$4, "Action '", &_9$$4, "' was not found on handler '", &_10$$4, "'");
			ZVAL_LONG(&_12$$4, 5);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_11$$4, &_12$$4);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 2, 0);
	zephir_array_fast_append(&_13, &altHandler);
	zephir_array_fast_append(&_13, &altAction);
	ZEPHIR_CALL_FUNCTION(&_14, "array_values", NULL, 28, &altParams);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_13, &_14);
	zephir_check_call_status();
	zephir_read_property_cached(&_15, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC | PH_READONLY);
	_16 = Z_TYPE_P(&_15) != IS_NULL;
	if (_16) {
		zephir_memory_observe(&_17);
		zephir_read_property_cached(&_17, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC);
		_16 = zephir_instance_of_ev(&_17, phalcon_events_managerinterface_ce);
	}
	if (_16) {
		zephir_array_update_string(&observer, SL("result"), &result, PH_COPY | PH_SEPARATE);
		zephir_read_property_cached(&_18$$5, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_19$$5);
		ZVAL_STRING(&_19$$5, "dispatch:afterCallAction");
		ZEPHIR_CALL_METHOD(NULL, &_18$$5, "fire", NULL, 0, &_19$$5, this_ptr, &observer);
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
	zval _45$$10, _36$$23;
	zend_bool hasService = 0, hasEventsManager = 0, isNewHandler = 0, _5$$5, _18$$13, _21$$15, _28$$18, _32$$20, _43$$24, _51$$26, _57$$32, _61$$34, _66$$37, _71$$39, _79$$41, _81$$41, _77$$44, _86$$48, _90$$50, _106$$61, _110$$64, _114$$66, _118$$69, _122$$71, _127$$75;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_17 = NULL, *_23 = NULL, *_25 = NULL, *_29 = NULL, *_33 = NULL, *_44 = NULL, *_58 = NULL, *_63 = NULL, *_68 = NULL, *_73 = NULL, *_102 = NULL;
	zval __$true, __$false, value, handler, container, namespaceName, handlerName, actionName, eventsManager, handlerClass, status, actionMethod, modelBinder, bindCacheKey, handlerHash, hookCache, e, _0, _1$$3, _2$$3, _3$$5, _4$$5, _6$$5, _7$$4, _8$$7, _9$$11, _10$$11, _12$$13, _13$$13, _14$$13, _15$$13, _16$$13, _19$$12, _20$$15, _22$$15, _24$$10, _34$$10, _35$$10, _38$$10, _39$$10, _40$$10, _64$$10, _97$$10, _104$$10, _116$$10, _26$$18, _27$$18, _30$$20, _31$$20, _37$$23, _41$$24, _42$$24, _46$$27, _47$$27, _48$$27, _49$$26, _50$$26, _52$$32, _53$$32, _54$$32, _55$$32, _56$$32, _59$$31, _60$$34, _62$$34, _65$$37, _67$$37, _69$$36, _70$$39, _72$$39, _74$$41, _80$$41, _82$$41, _75$$42, _76$$44, _78$$44, _83$$46, _84$$48, _85$$48, _87$$48, _88$$47, _89$$50, _91$$50, _92$$52, _93$$52, _94$$53, _95$$53, _96$$53, _98$$56, _99$$56, _100$$59, _101$$59, _103$$59, _105$$61, _107$$61, _108$$64, _109$$64, _111$$64, _112$$63, _113$$66, _115$$66, _117$$69, _119$$69, _120$$68, _121$$71, _123$$71, _124$$74, _125$$73, _126$$75, _128$$75, _129$$78, _130$$77, _131$$79;
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
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_64$$10);
	ZVAL_UNDEF(&_97$$10);
	ZVAL_UNDEF(&_104$$10);
	ZVAL_UNDEF(&_116$$10);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_42$$24);
	ZVAL_UNDEF(&_46$$27);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_49$$26);
	ZVAL_UNDEF(&_50$$26);
	ZVAL_UNDEF(&_52$$32);
	ZVAL_UNDEF(&_53$$32);
	ZVAL_UNDEF(&_54$$32);
	ZVAL_UNDEF(&_55$$32);
	ZVAL_UNDEF(&_56$$32);
	ZVAL_UNDEF(&_59$$31);
	ZVAL_UNDEF(&_60$$34);
	ZVAL_UNDEF(&_62$$34);
	ZVAL_UNDEF(&_65$$37);
	ZVAL_UNDEF(&_67$$37);
	ZVAL_UNDEF(&_69$$36);
	ZVAL_UNDEF(&_70$$39);
	ZVAL_UNDEF(&_72$$39);
	ZVAL_UNDEF(&_74$$41);
	ZVAL_UNDEF(&_80$$41);
	ZVAL_UNDEF(&_82$$41);
	ZVAL_UNDEF(&_75$$42);
	ZVAL_UNDEF(&_76$$44);
	ZVAL_UNDEF(&_78$$44);
	ZVAL_UNDEF(&_83$$46);
	ZVAL_UNDEF(&_84$$48);
	ZVAL_UNDEF(&_85$$48);
	ZVAL_UNDEF(&_87$$48);
	ZVAL_UNDEF(&_88$$47);
	ZVAL_UNDEF(&_89$$50);
	ZVAL_UNDEF(&_91$$50);
	ZVAL_UNDEF(&_92$$52);
	ZVAL_UNDEF(&_93$$52);
	ZVAL_UNDEF(&_94$$53);
	ZVAL_UNDEF(&_95$$53);
	ZVAL_UNDEF(&_96$$53);
	ZVAL_UNDEF(&_98$$56);
	ZVAL_UNDEF(&_99$$56);
	ZVAL_UNDEF(&_100$$59);
	ZVAL_UNDEF(&_101$$59);
	ZVAL_UNDEF(&_103$$59);
	ZVAL_UNDEF(&_105$$61);
	ZVAL_UNDEF(&_107$$61);
	ZVAL_UNDEF(&_108$$64);
	ZVAL_UNDEF(&_109$$64);
	ZVAL_UNDEF(&_111$$64);
	ZVAL_UNDEF(&_112$$63);
	ZVAL_UNDEF(&_113$$66);
	ZVAL_UNDEF(&_115$$66);
	ZVAL_UNDEF(&_117$$69);
	ZVAL_UNDEF(&_119$$69);
	ZVAL_UNDEF(&_120$$68);
	ZVAL_UNDEF(&_121$$71);
	ZVAL_UNDEF(&_123$$71);
	ZVAL_UNDEF(&_124$$74);
	ZVAL_UNDEF(&_125$$73);
	ZVAL_UNDEF(&_126$$75);
	ZVAL_UNDEF(&_128$$75);
	ZVAL_UNDEF(&_129$$78);
	ZVAL_UNDEF(&_130$$77);
	ZVAL_UNDEF(&_131$$79);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_36$$23);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "A dependency injection container is required to access related dispatching services");
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 173, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	hasEventsManager = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 177, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 177, &__$false);
	}
	if (hasEventsManager) {

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "dispatch:beforeDispatchLoop");
			ZEPHIR_CALL_METHOD(&_3$$5, &eventsManager, "fire", NULL, 0, &_4$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			_5$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&_3$$5);
			if (_5$$5) {
				zephir_read_property_cached(&_6$$5, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_METHOD(&status, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				zephir_read_property_cached(&_8$$7, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_8$$7)) {
					if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
						RETURN_MM_BOOL(0);
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 275);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	ZEPHIR_INIT_VAR(&handler);
	ZVAL_NULL(&handler);
	numberDispatches = 0;
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 177, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 177, &__$false);
	}
	while (1) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
		if (!(!(zephir_is_true(&_0)))) {
			break;
		}
		numberDispatches++;
		if (UNEXPECTED(numberDispatches == 256)) {
			ZEPHIR_INIT_NVAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "Dispatcher has detected a cyclic routing causing stability problems");
			ZVAL_LONG(&_10$$11, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_9$$11, &_10$$11);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 177, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 177, &__$false);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolveemptyproperties", &_11, 0);
		zephir_check_call_status();
		if (hasEventsManager) {

			/* try_start_2: */

				ZEPHIR_INIT_NVAR(&_13$$13);
				ZVAL_STRING(&_13$$13, "dispatch:beforeDispatch");
				ZVAL_NULL(&_14$$13);
				ZVAL_BOOL(&_15$$13, 1);
				ZVAL_BOOL(&_16$$13, 1);
				ZEPHIR_CALL_METHOD(&_12$$13, this_ptr, "firemanagerevent", &_17, 0, &_13$$13, &_14$$13, &_15$$13, &_16$$13);
				zephir_check_call_status_or_jump(try_end_2);
				_18$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_12$$13);
				if (!(_18$$13)) {
					zephir_read_property_cached(&_14$$13, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
					_18$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_14$$13);
				}
				if (_18$$13) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_19$$12);
				ZVAL_OBJ(&_19$$12, EG(exception));
				Z_ADDREF_P(&_19$$12);
				if (zephir_is_instance_of(&_19$$12, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_19$$12);
					ZEPHIR_CALL_METHOD(&_20$$15, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_20$$15);
					if (!(_21$$15)) {
						zephir_read_property_cached(&_22$$15, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
						_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_22$$15);
					}
					if (_21$$15) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 321);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_23, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_24$$10, &container, "has", &_25, 0, &handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(&_24$$10);
		if (!(hasService)) {
			hasService = zephir_class_exists(&handlerClass, 1);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_NVAR(&_26$$18);
			ZEPHIR_CONCAT_VS(&_26$$18, &handlerClass, " handler class cannot be loaded");
			ZVAL_LONG(&_27$$18, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", NULL, 0, &_26$$18, &_27$$18);
			zephir_check_call_status();
			_28$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_28$$18) {
				zephir_read_property_cached(&_27$$18, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
				_28$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&_27$$18);
			}
			if (_28$$18) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, &container, "getshared", &_29, 0, &handlerClass);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&handler) != IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(&_30$$20);
			ZVAL_STRING(&_30$$20, "Invalid handler returned from the services container");
			ZVAL_LONG(&_31$$20, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", NULL, 0, &_30$$20, &_31$$20);
			zephir_check_call_status();
			_32$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_32$$20) {
				zephir_read_property_cached(&_31$$20, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
				_32$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&_31$$20);
			}
			if (_32$$20) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_FUNCTION(&handlerHash, "spl_object_hash", &_33, 188, &handler);
		zephir_check_call_status();
		zephir_read_property_cached(&_34$$10, this_ptr, _zephir_prop_3, 178, PH_NOISY_CC | PH_READONLY);
		isNewHandler = !((zephir_array_isset_value(&_34$$10, &handlerHash)));
		if (isNewHandler) {
			zephir_update_property_array(this_ptr, SL("handlerHashes"), &handlerHash, &__$true);
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 179, &handler);
		zephir_read_property_cached(&_35$$10, this_ptr, _zephir_prop_5, 180, PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_value(&_35$$10, &handlerClass))) {
			ZEPHIR_INIT_NVAR(&_36$$23);
			zephir_create_array(&_36$$23, 4, 0);
			ZEPHIR_INIT_NVAR(&_37$$23);
			ZVAL_BOOL(&_37$$23, (zephir_method_exists_ex(&handler, ZEND_STRL("beforeexecuteroute")) == SUCCESS));
			zephir_array_fast_append(&_36$$23, &_37$$23);
			ZEPHIR_INIT_NVAR(&_37$$23);
			ZVAL_BOOL(&_37$$23, (zephir_method_exists_ex(&handler, ZEND_STRL("initialize")) == SUCCESS));
			zephir_array_fast_append(&_36$$23, &_37$$23);
			ZEPHIR_INIT_NVAR(&_37$$23);
			ZVAL_BOOL(&_37$$23, (zephir_method_exists_ex(&handler, ZEND_STRL("afterbinding")) == SUCCESS));
			zephir_array_fast_append(&_36$$23, &_37$$23);
			ZEPHIR_INIT_NVAR(&_37$$23);
			ZVAL_BOOL(&_37$$23, (zephir_method_exists_ex(&handler, ZEND_STRL("afterexecuteroute")) == SUCCESS));
			zephir_array_fast_append(&_36$$23, &_37$$23);
			zephir_update_property_array(this_ptr, SL("handlerHookCache"), &handlerClass, &_36$$23);
		}
		zephir_read_property_cached(&_38$$10, this_ptr, _zephir_prop_5, 180, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&hookCache);
		zephir_array_fetch(&hookCache, &_38$$10, &handlerClass, PH_NOISY, "phalcon/Dispatcher/AbstractDispatcher.zep", 389);
		zephir_read_property_cached(&_39$$10, this_ptr, _zephir_prop_6, 181, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&namespaceName, &_39$$10);
		zephir_read_property_cached(&_39$$10, this_ptr, _zephir_prop_7, 175, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&handlerName, &_39$$10);
		zephir_read_property_cached(&_39$$10, this_ptr, _zephir_prop_8, 174, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&actionName, &_39$$10);
		ZEPHIR_OBS_NVAR(&_40$$10);
		zephir_read_property_cached(&_40$$10, this_ptr, _zephir_prop_9, 182, PH_NOISY_CC);
		if (UNEXPECTED(Z_TYPE_P(&_40$$10) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&_41$$24);
			ZVAL_STRING(&_41$$24, "Action parameters must be an Array");
			ZVAL_LONG(&_42$$24, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", NULL, 0, &_41$$24, &_42$$24);
			zephir_check_call_status();
			_43$$24 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_43$$24) {
				zephir_read_property_cached(&_42$$24, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
				_43$$24 = ZEPHIR_IS_FALSE_IDENTICAL(&_42$$24);
			}
			if (_43$$24) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_44, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_45$$10);
		zephir_create_array(&_45$$10, 2, 0);
		zephir_array_fast_append(&_45$$10, &handler);
		zephir_array_fast_append(&_45$$10, &actionMethod);
		if (UNEXPECTED(!(zephir_is_callable(&_45$$10)))) {
			if (hasEventsManager) {
				ZEPHIR_INIT_NVAR(&_47$$27);
				ZVAL_STRING(&_47$$27, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD(&_46$$27, &eventsManager, "fire", NULL, 0, &_47$$27, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_46$$27)) {
					continue;
				}
				zephir_read_property_cached(&_48$$27, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_48$$27)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_49$$26);
			ZEPHIR_CONCAT_SVSVS(&_49$$26, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_50$$26, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", NULL, 0, &_49$$26, &_50$$26);
			zephir_check_call_status();
			_51$$26 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_51$$26) {
				zephir_read_property_cached(&_50$$26, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
				_51$$26 = ZEPHIR_IS_FALSE_IDENTICAL(&_50$$26);
			}
			if (_51$$26) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_53$$32);
				ZVAL_STRING(&_53$$32, "dispatch:beforeExecuteRoute");
				ZVAL_NULL(&_54$$32);
				ZVAL_BOOL(&_55$$32, 1);
				ZVAL_BOOL(&_56$$32, 1);
				ZEPHIR_CALL_METHOD(&_52$$32, this_ptr, "firemanagerevent", &_17, 0, &_53$$32, &_54$$32, &_55$$32, &_56$$32);
				zephir_check_call_status_or_jump(try_end_3);
				_57$$32 = ZEPHIR_IS_FALSE_IDENTICAL(&_52$$32);
				if (!(_57$$32)) {
					zephir_read_property_cached(&_54$$32, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
					_57$$32 = ZEPHIR_IS_FALSE_IDENTICAL(&_54$$32);
				}
				if (_57$$32) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_58, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_59$$31);
				ZVAL_OBJ(&_59$$31, EG(exception));
				Z_ADDREF_P(&_59$$31);
				if (zephir_is_instance_of(&_59$$31, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_59$$31);
					ZEPHIR_CALL_METHOD(&_60$$34, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_61$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_60$$34);
					if (!(_61$$34)) {
						zephir_read_property_cached(&_62$$34, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
						_61$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_62$$34);
					}
					if (_61$$34) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_63, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 475);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		zephir_array_fetch_long(&_64$$10, &hookCache, 0, PH_NOISY | PH_READONLY, "phalcon/Dispatcher/AbstractDispatcher.zep", 479);
		if (zephir_is_true(&_64$$10)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_65$$37, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_66$$37 = ZEPHIR_IS_FALSE_IDENTICAL(&_65$$37);
				if (!(_66$$37)) {
					zephir_read_property_cached(&_67$$37, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
					_66$$37 = ZEPHIR_IS_FALSE_IDENTICAL(&_67$$37);
				}
				if (_66$$37) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_68, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_69$$36);
				ZVAL_OBJ(&_69$$36, EG(exception));
				Z_ADDREF_P(&_69$$36);
				if (zephir_is_instance_of(&_69$$36, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_69$$36);
					ZEPHIR_CALL_METHOD(&_70$$39, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_71$$39 = ZEPHIR_IS_FALSE_IDENTICAL(&_70$$39);
					if (!(_71$$39)) {
						zephir_read_property_cached(&_72$$39, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
						_71$$39 = ZEPHIR_IS_FALSE_IDENTICAL(&_72$$39);
					}
					if (_71$$39) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_73, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 498);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (isNewHandler) {
			zephir_array_fetch_long(&_74$$41, &hookCache, 1, PH_NOISY | PH_READONLY, "phalcon/Dispatcher/AbstractDispatcher.zep", 522);
			if (zephir_is_true(&_74$$41)) {

				/* try_start_5: */

					if (1) {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 183, &__$true);
					} else {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 183, &__$false);
					}
					ZEPHIR_CALL_METHOD(NULL, &handler, "initialize", NULL, 0);
					zephir_check_call_status_or_jump(try_end_5);

				try_end_5:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_75$$42);
					ZVAL_OBJ(&_75$$42, EG(exception));
					Z_ADDREF_P(&_75$$42);
					if (zephir_is_instance_of(&_75$$42, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_75$$42);
						if (0) {
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 183, &__$true);
						} else {
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 183, &__$false);
						}
						ZEPHIR_CALL_METHOD(&_76$$44, this_ptr, "handleexception", NULL, 0, &e);
						zephir_check_call_status();
						_77$$44 = ZEPHIR_IS_FALSE_IDENTICAL(&_76$$44);
						if (!(_77$$44)) {
							zephir_read_property_cached(&_78$$44, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
							_77$$44 = ZEPHIR_IS_FALSE_IDENTICAL(&_78$$44);
						}
						if (_77$$44) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 544);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 183, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 183, &__$false);
			}
			_79$$41 = !hasEventsManager;
			if (_79$$41) {
				zephir_read_property_cached(&_80$$41, this_ptr, _zephir_prop_1, 173, PH_NOISY_CC | PH_READONLY);
				_79$$41 = Z_TYPE_P(&_80$$41) != IS_NULL;
			}
			_81$$41 = _79$$41;
			if (_81$$41) {
				ZEPHIR_OBS_NVAR(&_82$$41);
				zephir_read_property_cached(&_82$$41, this_ptr, _zephir_prop_1, 173, PH_NOISY_CC);
				_81$$41 = zephir_instance_of_ev(&_82$$41, phalcon_events_managerinterface_ce);
			}
			if (_81$$41) {
				zephir_read_property_cached(&_83$$46, this_ptr, _zephir_prop_1, 173, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&eventsManager, &_83$$46);
				hasEventsManager = 1;
			}
			if (zephir_is_true(&eventsManager)) {

				/* try_start_6: */

					ZEPHIR_INIT_NVAR(&_85$$48);
					ZVAL_STRING(&_85$$48, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD(&_84$$48, &eventsManager, "fire", NULL, 0, &_85$$48, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_86$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_84$$48);
					if (!(_86$$48)) {
						zephir_read_property_cached(&_87$$48, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
						_86$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_87$$48);
					}
					if (_86$$48) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_88$$47);
					ZVAL_OBJ(&_88$$47, EG(exception));
					Z_ADDREF_P(&_88$$47);
					if (zephir_is_instance_of(&_88$$47, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_88$$47);
						ZEPHIR_CALL_METHOD(&_89$$50, this_ptr, "handleexception", NULL, 0, &e);
						zephir_check_call_status();
						_90$$50 = ZEPHIR_IS_FALSE_IDENTICAL(&_89$$50);
						if (!(_90$$50)) {
							zephir_read_property_cached(&_91$$50, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
							_90$$50 = ZEPHIR_IS_FALSE_IDENTICAL(&_91$$50);
						}
						if (_90$$50) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 582);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property_cached(&_39$$10, this_ptr, _zephir_prop_11, 184, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_39$$10)) {
			zephir_read_property_cached(&_92$$52, this_ptr, _zephir_prop_12, 185, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_92$$52);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			zephir_read_property_cached(&_92$$52, this_ptr, _zephir_prop_9, 182, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_93$$52, &modelBinder, "bindtohandler", NULL, 0, &handler, &_92$$52, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 182, &_93$$52);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_95$$53);
			ZVAL_STRING(&_95$$53, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD(&_94$$53, &eventsManager, "fire", NULL, 0, &_95$$53, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_94$$53)) {
				continue;
			}
			zephir_read_property_cached(&_96$$53, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_96$$53)) {
				continue;
			}
		}
		zephir_array_fetch_long(&_97$$10, &hookCache, 2, PH_NOISY | PH_READONLY, "phalcon/Dispatcher/AbstractDispatcher.zep", 628);
		if (zephir_is_true(&_97$$10)) {
			ZEPHIR_CALL_METHOD(&_98$$56, &handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_98$$56)) {
				continue;
			}
			zephir_read_property_cached(&_99$$56, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_99$$56)) {
				continue;
			}
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 186, &handler);

		/* try_start_7: */

			zephir_read_property_cached(&_101$$59, this_ptr, _zephir_prop_9, 182, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_100$$59, this_ptr, "callactionmethod", &_102, 0, &handler, &actionMethod, &_101$$59);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_14, 187, &_100$$59);
			zephir_read_property_cached(&_103$$59, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_103$$59)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_104$$10);
			ZVAL_OBJ(&_104$$10, EG(exception));
			Z_ADDREF_P(&_104$$10);
			if (zephir_is_instance_of(&_104$$10, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_104$$10);
				ZEPHIR_CALL_METHOD(&_105$$61, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				_106$$61 = ZEPHIR_IS_FALSE_IDENTICAL(&_105$$61);
				if (!(_106$$61)) {
					zephir_read_property_cached(&_107$$61, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
					_106$$61 = ZEPHIR_IS_FALSE_IDENTICAL(&_107$$61);
				}
				if (_106$$61) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 667);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_109$$64);
				ZVAL_STRING(&_109$$64, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(&_108$$64, &eventsManager, "fire", NULL, 0, &_109$$64, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_110$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_108$$64);
				if (!(_110$$64)) {
					zephir_read_property_cached(&_111$$64, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
					_110$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_111$$64);
				}
				if (_110$$64) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_112$$63);
				ZVAL_OBJ(&_112$$63, EG(exception));
				Z_ADDREF_P(&_112$$63);
				if (zephir_is_instance_of(&_112$$63, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_112$$63);
					ZEPHIR_CALL_METHOD(&_113$$66, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_114$$66 = ZEPHIR_IS_FALSE_IDENTICAL(&_113$$66);
					if (!(_114$$66)) {
						zephir_read_property_cached(&_115$$66, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
						_114$$66 = ZEPHIR_IS_FALSE_IDENTICAL(&_115$$66);
					}
					if (_114$$66) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 689);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		zephir_array_fetch_long(&_116$$10, &hookCache, 3, PH_NOISY | PH_READONLY, "phalcon/Dispatcher/AbstractDispatcher.zep", 696);
		if (zephir_is_true(&_116$$10)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_117$$69, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_118$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_117$$69);
				if (!(_118$$69)) {
					zephir_read_property_cached(&_119$$69, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
					_118$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_119$$69);
				}
				if (_118$$69) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_120$$68);
				ZVAL_OBJ(&_120$$68, EG(exception));
				Z_ADDREF_P(&_120$$68);
				if (zephir_is_instance_of(&_120$$68, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_120$$68);
					ZEPHIR_CALL_METHOD(&_121$$71, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_122$$71 = ZEPHIR_IS_FALSE_IDENTICAL(&_121$$71);
					if (!(_122$$71)) {
						zephir_read_property_cached(&_123$$71, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
						_122$$71 = ZEPHIR_IS_FALSE_IDENTICAL(&_123$$71);
					}
					if (_122$$71) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 712);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_124$$74);
				ZVAL_STRING(&_124$$74, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_124$$74, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_125$$73);
				ZVAL_OBJ(&_125$$73, EG(exception));
				Z_ADDREF_P(&_125$$73);
				if (zephir_is_instance_of(&_125$$73, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_125$$73);
					ZEPHIR_CALL_METHOD(&_126$$75, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_127$$75 = ZEPHIR_IS_FALSE_IDENTICAL(&_126$$75);
					if (!(_127$$75)) {
						zephir_read_property_cached(&_128$$75, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
						_127$$75 = ZEPHIR_IS_FALSE_IDENTICAL(&_128$$75);
					}
					if (_127$$75) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 732);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_129$$78);
			ZVAL_STRING(&_129$$78, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_129$$78, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_130$$77);
			ZVAL_OBJ(&_130$$77, EG(exception));
			Z_ADDREF_P(&_130$$77);
			if (zephir_is_instance_of(&_130$$77, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_130$$77);
				ZEPHIR_CALL_METHOD(&_131$$79, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_131$$79)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 749);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 183, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_dispatcher_exceptions_forwardininitializeforbidden_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 189);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Dispatcher/AbstractDispatcher.zep", 781);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 181, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 188, &_2);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_3, 175, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 189, &_3);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_5, 174, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 190, &_4);
	if (zephir_array_isset_string_fetch(&namespaceName, &forward, SL("namespace"), 1)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 181, &namespaceName);
	}
	if (zephir_array_isset_string_fetch(&controllerName, &forward, SL("controller"), 1)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 175, &controllerName);
	} else {
		zephir_memory_observe(&taskName);
		if (zephir_array_isset_string_fetch(&taskName, &forward, SL("task"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 175, &taskName);
		}
	}
	if (zephir_array_isset_string_fetch(&actionName, &forward, SL("action"), 1)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 174, &actionName);
	}
	if (zephir_array_isset_string_fetch(&params, &forward, SL("params"), 1)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 182, &params);
	}
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 177, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 177, &__$false);
	}
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 191, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 191, &__$false);
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
	zval activeMethodName, _0, _1, _5, _2$$3, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&activeMethodName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 192, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 174, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&activeMethodName, &_0, &_1, 0))) {
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_1, 174, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "tocamelcase", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&activeMethodName, "lcfirst", NULL, 178, &_2$$3);
		zephir_check_call_status();
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 174, PH_NOISY_CC);
		zephir_update_property_array(this_ptr, SL("activeMethodMap"), &_4$$3, &activeMethodName);
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_2, 193, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &activeMethodName, &_5);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelBinder", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 185, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 185, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getboundmodels", NULL, 0);
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

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolveemptyproperties", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 194, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlerSuffix, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 175, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlerName, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 181, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&namespaceName, &_0);
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/Dispatcher/AbstractDispatcher.zep", 902))) {
		ZEPHIR_CALL_METHOD(&camelizedClass, this_ptr, "tocamelcase", NULL, 0, &handlerName);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&camelizedClass, &handlerName);
	}
	ZEPHIR_INIT_VAR(&handlerClass);
	if (zephir_is_true(&namespaceName)) {
		if (!(zephir_end_with_str(&namespaceName, SL("\\")))) {
			zephir_concat_self_str(&namespaceName, SL("\\"));
		}
		ZEPHIR_CONCAT_VVV(&handlerClass, &namespaceName, &camelizedClass, &handlerSuffix);
	} else {
		ZEPHIR_CONCAT_VV(&handlerClass, &camelizedClass, &handlerSuffix);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getparameter", NULL, 0, param, filters, defaultValue);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null, params, filter, paramValue, _0, _3, _4, _5, _1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 182, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&params, &_0);
	zephir_memory_observe(&paramValue);
	if (!(zephir_array_isset_fetch(&paramValue, &params, param, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) == IS_NULL) {
		RETURN_CCTOR(&paramValue);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 176, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "A dependency injection container is required to access the 'filter' service");
		ZVAL_LONG(&_2$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_1$$5, &_2$$5);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 176, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "filter");
	ZEPHIR_CALL_METHOD(&_4, &_3, "getshared", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filter, &_4);
	ZEPHIR_RETURN_CALL_METHOD(&filter, "sanitize", NULL, 0, &paramValue, filters);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getparameters", NULL, 0);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &param);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasparameter", NULL, 0, param);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 182, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, param));
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 174, &actionName_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 193, &actionSuffix_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 195, &actionName_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 196, &defaultNamespace_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 194, &handlerSuffix_zv);
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
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_1$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 184, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 184, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 185, modelBinder);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 197, &moduleName_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 181, &namespaceName_zv);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(param)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &param, &value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparameter", NULL, 0, param, value);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 182, &params);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &params_param);
	zephir_get_arrval(&params, params_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparameters", NULL, 0, &params);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 187, value);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 181, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 196, PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 181, &_1$$3);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 175, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_3, 198, PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 175, &_3$$4);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_4, 174, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_4))) {
		zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_5, 195, PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 174, &_5$$5);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, camelCaseInput, _0, _1$$3, _2$$3, _3$$3;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&camelCaseInput);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 199, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&camelCaseInput, &_0, &input_zv, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "/[_-]+/");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_split", NULL, 190, &_1$$3, &input_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ucfirst");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_map", NULL, 20, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&camelCaseInput);
		zephir_fast_join_str(&camelCaseInput, SL(""), &_3$$3);
		zephir_update_property_array(this_ptr, SL("camelCaseMap"), &input_zv, &camelCaseInput);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, zephir_get_internal_ce(SL("phalcon\\events\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eventsManager);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "container");
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 10, this_ptr, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		zephir_memory_observe(&_3);
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC);
		_2 = Z_TYPE_P(&_3) != IS_NULL;
	}
	if (_2) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "eventsManager");
		ZVAL_BOOL(&_6$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "set", NULL, 0, &_5$$3, eventsManager, &_6$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 173, eventsManager);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		_1$$3 = stopOnFalse;
		if (_1$$3) {
			zephir_memory_observe(&_2$$3);
			zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC);
			_1$$3 = zephir_instance_of_ev(&_2$$3, phalcon_events_manager_ce);
		}
		if (_1$$3) {
			zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC | PH_READONLY);
			if (cancellable) {
				ZVAL_BOOL(&_4$$4, 1);
			} else {
				ZVAL_BOOL(&_4$$4, 0);
			}
			ZVAL_BOOL(&_5$$4, 1);
			ZEPHIR_RETURN_CALL_METHOD(&_3$$4, "fire", NULL, 0, &eventName_zv, this_ptr, data, &_4$$4, &_5$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 173, PH_NOISY_CC | PH_READONLY);
		if (cancellable) {
			ZVAL_BOOL(&_7$$3, 1);
		} else {
			ZVAL_BOOL(&_7$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_6$$3, "fire", NULL, 0, &eventName_zv, this_ptr, data, &_7$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

