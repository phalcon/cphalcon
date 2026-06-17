
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
#include "ext/spl/spl_exceptions.h"
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
 * error hooks {@see throwDispatchException()} and {@see handleException()}.
 * The dispatch loop calls them on every error/exception path; a subclass that
 * omits them cannot be loaded.
 *
 * ## Hook channels
 *
 * A single lifecycle point can be intercepted through three independent
 * channels. For any given point they run in this order:
 *
 * 1. **Events-manager listener** — e.g. `dispatch:beforeExecuteRoute`. A
 *    listener returning `false` cancels; calling `forward()` re-enters the
 *    loop; throwing routes through {@see handleException()}.
 * 2. **Duck-typed handler method** — e.g. a `beforeExecuteRoute()` method on
 *    the controller/task itself (presence is cached per class). Same
 *    `false` / `forward()` cancellation semantics as the event.
 * 3. **`dispatch:beforeCallAction` observer** — fired by
 *    {@see callActionMethod()} with a `Phalcon\Support\Collection` carrying
 *    the mutable keys `handler`, `action` and `params`. Listeners may rewrite
 *    those keys to change *what* gets invoked; the substituted callable is
 *    re-validated before the call. `dispatch:afterCallAction` receives the
 *    same Collection plus a `result` key.
 */
ZEPHIR_INIT_CLASS(Phalcon_Dispatcher_AbstractDispatcher)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Dispatcher, AbstractDispatcher, phalcon, dispatcher_abstractdispatcher, phalcon_di_abstractinjectionaware_ce, phalcon_dispatcher_abstractdispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("activeHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("activeMethodMap"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("actionName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("actionSuffix"), "Action", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("camelCaseMap"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultAction"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultNamespace"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultHandler"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerHashes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerHookCache"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerSuffix"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_dispatcher_abstractdispatcher_ce, SL("finished"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_dispatcher_abstractdispatcher_ce, SL("forwarded"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_dispatcher_abstractdispatcher_ce, SL("isControllerInitialize"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("lastHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var BinderInterface|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("modelBinder"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_dispatcher_abstractdispatcher_ce, SL("modelBinding"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("moduleName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("namespaceName"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("params"), ZEND_ACC_PROTECTED);
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
	phalcon_dispatcher_abstractdispatcher_ce->create_object = zephir_init_properties_Phalcon_Dispatcher_AbstractDispatcher;

	zend_class_implements(phalcon_dispatcher_abstractdispatcher_ce, 1, phalcon_dispatcher_dispatcherinterface_ce);
	zend_class_implements(phalcon_dispatcher_abstractdispatcher_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

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
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}
	ZEPHIR_CPY_WRT(&altHandler, handler);
	ZEPHIR_CPY_WRT(&altAction, &actionMethod_zv);
	ZEPHIR_CPY_WRT(&altParams, &params);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) != IS_NULL;
	if (_1) {
		zephir_memory_observe(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
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
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "dispatch:beforeCallAction");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "fire", NULL, 0, &_5$$3, this_ptr, &observer);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "handler");
		ZEPHIR_CALL_METHOD(&altHandler, &observer, "get", NULL, 158, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "action");
		ZEPHIR_CALL_METHOD(&altAction, &observer, "get", NULL, 158, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		array_init(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "params");
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "array");
		ZEPHIR_CALL_METHOD(&altParams, &observer, "get", NULL, 158, &_6$$3, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 2, 0);
		zephir_array_fast_append(&_8$$3, &altHandler);
		zephir_array_fast_append(&_8$$3, &altAction);
		if (UNEXPECTED(!(zephir_is_callable(&_8$$3)))) {
			zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_CALL_FUNCTION(&_14, "array_values", NULL, 29, &altParams);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_13, &_14);
	zephir_check_call_status();
	zephir_read_property(&_15, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	_16 = Z_TYPE_P(&_15) != IS_NULL;
	if (_16) {
		zephir_memory_observe(&_17);
		zephir_read_property(&_17, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
		_16 = zephir_instance_of_ev(&_17, phalcon_events_managerinterface_ce);
	}
	if (_16) {
		zephir_array_update_string(&observer, SL("result"), &result, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_18$$5, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
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
	zval _42$$10, _33$$23;
	zend_bool hasService = 0, hasEventsManager = 0, isNewHandler = 0, _5$$5, _14$$13, _18$$15, _25$$18, _29$$20, _40$$24, _48$$26, _51$$32, _56$$34, _61$$37, _66$$39, _74$$41, _76$$41, _72$$44, _81$$48, _85$$50, _101$$61, _105$$64, _109$$66, _113$$69, _117$$71, _122$$75;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_20 = NULL, *_22 = NULL, *_26 = NULL, *_30 = NULL, *_41 = NULL, *_53 = NULL, *_58 = NULL, *_63 = NULL, *_68 = NULL, *_97 = NULL;
	zval __$true, __$false, value, handler, container, namespaceName, handlerName, actionName, eventsManager, handlerClass, status, actionMethod, modelBinder, bindCacheKey, handlerHash, hookCache, e, _0, _1$$3, _2$$3, _3$$5, _4$$5, _6$$5, _7$$4, _8$$7, _9$$11, _10$$11, _12$$13, _13$$13, _15$$13, _16$$12, _17$$15, _19$$15, _21$$10, _31$$10, _32$$10, _35$$10, _36$$10, _37$$10, _59$$10, _92$$10, _99$$10, _111$$10, _23$$18, _24$$18, _27$$20, _28$$20, _34$$23, _38$$24, _39$$24, _43$$27, _44$$27, _45$$27, _46$$26, _47$$26, _49$$32, _50$$32, _52$$32, _54$$31, _55$$34, _57$$34, _60$$37, _62$$37, _64$$36, _65$$39, _67$$39, _69$$41, _75$$41, _77$$41, _70$$42, _71$$44, _73$$44, _78$$46, _79$$48, _80$$48, _82$$48, _83$$47, _84$$50, _86$$50, _87$$52, _88$$52, _89$$53, _90$$53, _91$$53, _93$$56, _94$$56, _95$$59, _96$$59, _98$$59, _100$$61, _102$$61, _103$$64, _104$$64, _106$$64, _107$$63, _108$$66, _110$$66, _112$$69, _114$$69, _115$$68, _116$$71, _118$$71, _119$$74, _120$$73, _121$$75, _123$$75, _124$$78, _125$$77, _126$$79;
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
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_59$$10);
	ZVAL_UNDEF(&_92$$10);
	ZVAL_UNDEF(&_99$$10);
	ZVAL_UNDEF(&_111$$10);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_43$$27);
	ZVAL_UNDEF(&_44$$27);
	ZVAL_UNDEF(&_45$$27);
	ZVAL_UNDEF(&_46$$26);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_49$$32);
	ZVAL_UNDEF(&_50$$32);
	ZVAL_UNDEF(&_52$$32);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_55$$34);
	ZVAL_UNDEF(&_57$$34);
	ZVAL_UNDEF(&_60$$37);
	ZVAL_UNDEF(&_62$$37);
	ZVAL_UNDEF(&_64$$36);
	ZVAL_UNDEF(&_65$$39);
	ZVAL_UNDEF(&_67$$39);
	ZVAL_UNDEF(&_69$$41);
	ZVAL_UNDEF(&_75$$41);
	ZVAL_UNDEF(&_77$$41);
	ZVAL_UNDEF(&_70$$42);
	ZVAL_UNDEF(&_71$$44);
	ZVAL_UNDEF(&_73$$44);
	ZVAL_UNDEF(&_78$$46);
	ZVAL_UNDEF(&_79$$48);
	ZVAL_UNDEF(&_80$$48);
	ZVAL_UNDEF(&_82$$48);
	ZVAL_UNDEF(&_83$$47);
	ZVAL_UNDEF(&_84$$50);
	ZVAL_UNDEF(&_86$$50);
	ZVAL_UNDEF(&_87$$52);
	ZVAL_UNDEF(&_88$$52);
	ZVAL_UNDEF(&_89$$53);
	ZVAL_UNDEF(&_90$$53);
	ZVAL_UNDEF(&_91$$53);
	ZVAL_UNDEF(&_93$$56);
	ZVAL_UNDEF(&_94$$56);
	ZVAL_UNDEF(&_95$$59);
	ZVAL_UNDEF(&_96$$59);
	ZVAL_UNDEF(&_98$$59);
	ZVAL_UNDEF(&_100$$61);
	ZVAL_UNDEF(&_102$$61);
	ZVAL_UNDEF(&_103$$64);
	ZVAL_UNDEF(&_104$$64);
	ZVAL_UNDEF(&_106$$64);
	ZVAL_UNDEF(&_107$$63);
	ZVAL_UNDEF(&_108$$66);
	ZVAL_UNDEF(&_110$$66);
	ZVAL_UNDEF(&_112$$69);
	ZVAL_UNDEF(&_114$$69);
	ZVAL_UNDEF(&_115$$68);
	ZVAL_UNDEF(&_116$$71);
	ZVAL_UNDEF(&_118$$71);
	ZVAL_UNDEF(&_119$$74);
	ZVAL_UNDEF(&_120$$73);
	ZVAL_UNDEF(&_121$$75);
	ZVAL_UNDEF(&_123$$75);
	ZVAL_UNDEF(&_124$$78);
	ZVAL_UNDEF(&_125$$77);
	ZVAL_UNDEF(&_126$$79);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_33$$23);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "A dependency injection container is required to access related dispatching services");
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	hasEventsManager = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$false);
	}
	if (hasEventsManager) {

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "dispatch:beforeDispatchLoop");
			ZEPHIR_CALL_METHOD(&_3$$5, &eventsManager, "fire", NULL, 0, &_4$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			_5$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&_3$$5);
			if (_5$$5) {
				zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
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
				zephir_read_property(&_8$$7, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_8$$7)) {
					if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
						RETURN_MM_BOOL(0);
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 318);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$false);
	}
	while (1) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
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
			zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$false);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolveemptyproperties", &_11, 0);
		zephir_check_call_status();
		if (hasEventsManager) {

			/* try_start_2: */

				ZEPHIR_INIT_NVAR(&_13$$13);
				ZVAL_STRING(&_13$$13, "dispatch:beforeDispatch");
				ZEPHIR_CALL_METHOD(&_12$$13, &eventsManager, "fire", NULL, 0, &_13$$13, this_ptr);
				zephir_check_call_status_or_jump(try_end_2);
				_14$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_12$$13);
				if (!(_14$$13)) {
					zephir_read_property(&_15$$13, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_14$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_15$$13);
				}
				if (_14$$13) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_16$$12);
				ZVAL_OBJ(&_16$$12, EG(exception));
				Z_ADDREF_P(&_16$$12);
				if (zephir_is_instance_of(&_16$$12, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_16$$12);
					ZEPHIR_CALL_METHOD(&_17$$15, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_18$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_17$$15);
					if (!(_18$$15)) {
						zephir_read_property(&_19$$15, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_18$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_19$$15);
					}
					if (_18$$15) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 358);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_20, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_21$$10, &container, "has", &_22, 0, &handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(&_21$$10);
		if (!(hasService)) {
			hasService = zephir_class_exists(&handlerClass, 1);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_NVAR(&_23$$18);
			ZEPHIR_CONCAT_VS(&_23$$18, &handlerClass, " handler class cannot be loaded");
			ZVAL_LONG(&_24$$18, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", NULL, 0, &_23$$18, &_24$$18);
			zephir_check_call_status();
			_25$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_25$$18) {
				zephir_read_property(&_24$$18, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_25$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&_24$$18);
			}
			if (_25$$18) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, &container, "getshared", &_26, 0, &handlerClass);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&handler) != IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(&_27$$20);
			ZVAL_STRING(&_27$$20, "Invalid handler returned from the services container");
			ZVAL_LONG(&_28$$20, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", NULL, 0, &_27$$20, &_28$$20);
			zephir_check_call_status();
			_29$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_29$$20) {
				zephir_read_property(&_28$$20, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_29$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&_28$$20);
			}
			if (_29$$20) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_FUNCTION(&handlerHash, "spl_object_hash", &_30, 159, &handler);
		zephir_check_call_status();
		zephir_read_property(&_31$$10, this_ptr, ZEND_STRL("handlerHashes"), PH_NOISY_CC | PH_READONLY);
		isNewHandler = !((zephir_array_isset_value(&_31$$10, &handlerHash)));
		if (isNewHandler) {
			zephir_update_property_array(this_ptr, SL("handlerHashes"), &handlerHash, &__$true);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeHandler"), &handler);
		zephir_read_property(&_32$$10, this_ptr, ZEND_STRL("handlerHookCache"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_value(&_32$$10, &handlerClass))) {
			ZEPHIR_INIT_NVAR(&_33$$23);
			zephir_create_array(&_33$$23, 4, 0);
			ZEPHIR_INIT_NVAR(&_34$$23);
			ZVAL_BOOL(&_34$$23, (zephir_method_exists_ex(&handler, ZEND_STRL("beforeexecuteroute")) == SUCCESS));
			zephir_array_fast_append(&_33$$23, &_34$$23);
			ZEPHIR_INIT_NVAR(&_34$$23);
			ZVAL_BOOL(&_34$$23, (zephir_method_exists_ex(&handler, ZEND_STRL("initialize")) == SUCCESS));
			zephir_array_fast_append(&_33$$23, &_34$$23);
			ZEPHIR_INIT_NVAR(&_34$$23);
			ZVAL_BOOL(&_34$$23, (zephir_method_exists_ex(&handler, ZEND_STRL("afterbinding")) == SUCCESS));
			zephir_array_fast_append(&_33$$23, &_34$$23);
			ZEPHIR_INIT_NVAR(&_34$$23);
			ZVAL_BOOL(&_34$$23, (zephir_method_exists_ex(&handler, ZEND_STRL("afterexecuteroute")) == SUCCESS));
			zephir_array_fast_append(&_33$$23, &_34$$23);
			zephir_update_property_array(this_ptr, SL("handlerHookCache"), &handlerClass, &_33$$23);
		}
		zephir_read_property(&_35$$10, this_ptr, ZEND_STRL("handlerHookCache"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&hookCache);
		zephir_array_fetch(&hookCache, &_35$$10, &handlerClass, PH_NOISY, "phalcon/Dispatcher/AbstractDispatcher.zep", 427);
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&namespaceName, &_36$$10);
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&handlerName, &_36$$10);
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&actionName, &_36$$10);
		ZEPHIR_OBS_NVAR(&_37$$10);
		zephir_read_property(&_37$$10, this_ptr, ZEND_STRL("params"), PH_NOISY_CC);
		if (UNEXPECTED(Z_TYPE_P(&_37$$10) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&_38$$24);
			ZVAL_STRING(&_38$$24, "Action parameters must be an Array");
			ZVAL_LONG(&_39$$24, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", NULL, 0, &_38$$24, &_39$$24);
			zephir_check_call_status();
			_40$$24 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_40$$24) {
				zephir_read_property(&_39$$24, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_40$$24 = ZEPHIR_IS_FALSE_IDENTICAL(&_39$$24);
			}
			if (_40$$24) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_41, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_42$$10);
		zephir_create_array(&_42$$10, 2, 0);
		zephir_array_fast_append(&_42$$10, &handler);
		zephir_array_fast_append(&_42$$10, &actionMethod);
		if (UNEXPECTED(!(zephir_is_callable(&_42$$10)))) {
			if (hasEventsManager) {
				ZEPHIR_INIT_NVAR(&_44$$27);
				ZVAL_STRING(&_44$$27, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD(&_43$$27, &eventsManager, "fire", NULL, 0, &_44$$27, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_43$$27)) {
					continue;
				}
				zephir_read_property(&_45$$27, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_45$$27)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_46$$26);
			ZEPHIR_CONCAT_SVSVS(&_46$$26, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_47$$26, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", NULL, 0, &_46$$26, &_47$$26);
			zephir_check_call_status();
			_48$$26 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_48$$26) {
				zephir_read_property(&_47$$26, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_48$$26 = ZEPHIR_IS_FALSE_IDENTICAL(&_47$$26);
			}
			if (_48$$26) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_50$$32);
				ZVAL_STRING(&_50$$32, "dispatch:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_49$$32, &eventsManager, "fire", NULL, 0, &_50$$32, this_ptr);
				zephir_check_call_status_or_jump(try_end_3);
				_51$$32 = ZEPHIR_IS_FALSE_IDENTICAL(&_49$$32);
				if (!(_51$$32)) {
					zephir_read_property(&_52$$32, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_51$$32 = ZEPHIR_IS_FALSE_IDENTICAL(&_52$$32);
				}
				if (_51$$32) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_53, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_54$$31);
				ZVAL_OBJ(&_54$$31, EG(exception));
				Z_ADDREF_P(&_54$$31);
				if (zephir_is_instance_of(&_54$$31, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_54$$31);
					ZEPHIR_CALL_METHOD(&_55$$34, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_56$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_55$$34);
					if (!(_56$$34)) {
						zephir_read_property(&_57$$34, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_56$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_57$$34);
					}
					if (_56$$34) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_58, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 508);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		zephir_array_fetch_long(&_59$$10, &hookCache, 0, PH_NOISY | PH_READONLY, "phalcon/Dispatcher/AbstractDispatcher.zep", 512);
		if (zephir_is_true(&_59$$10)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_60$$37, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_61$$37 = ZEPHIR_IS_FALSE_IDENTICAL(&_60$$37);
				if (!(_61$$37)) {
					zephir_read_property(&_62$$37, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_61$$37 = ZEPHIR_IS_FALSE_IDENTICAL(&_62$$37);
				}
				if (_61$$37) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_63, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_64$$36);
				ZVAL_OBJ(&_64$$36, EG(exception));
				Z_ADDREF_P(&_64$$36);
				if (zephir_is_instance_of(&_64$$36, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_64$$36);
					ZEPHIR_CALL_METHOD(&_65$$39, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_66$$39 = ZEPHIR_IS_FALSE_IDENTICAL(&_65$$39);
					if (!(_66$$39)) {
						zephir_read_property(&_67$$39, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_66$$39 = ZEPHIR_IS_FALSE_IDENTICAL(&_67$$39);
					}
					if (_66$$39) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_68, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 527);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (isNewHandler) {
			zephir_array_fetch_long(&_69$$41, &hookCache, 1, PH_NOISY | PH_READONLY, "phalcon/Dispatcher/AbstractDispatcher.zep", 551);
			if (zephir_is_true(&_69$$41)) {

				/* try_start_5: */

					if (1) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$false);
					}
					ZEPHIR_CALL_METHOD(NULL, &handler, "initialize", NULL, 0);
					zephir_check_call_status_or_jump(try_end_5);

				try_end_5:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_70$$42);
					ZVAL_OBJ(&_70$$42, EG(exception));
					Z_ADDREF_P(&_70$$42);
					if (zephir_is_instance_of(&_70$$42, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_70$$42);
						if (0) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$true);
						} else {
							zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$false);
						}
						ZEPHIR_CALL_METHOD(&_71$$44, this_ptr, "handleexception", NULL, 0, &e);
						zephir_check_call_status();
						_72$$44 = ZEPHIR_IS_FALSE_IDENTICAL(&_71$$44);
						if (!(_72$$44)) {
							zephir_read_property(&_73$$44, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
							_72$$44 = ZEPHIR_IS_FALSE_IDENTICAL(&_73$$44);
						}
						if (_72$$44) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 571);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$false);
			}
			_74$$41 = !hasEventsManager;
			if (_74$$41) {
				zephir_read_property(&_75$$41, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				_74$$41 = Z_TYPE_P(&_75$$41) != IS_NULL;
			}
			_76$$41 = _74$$41;
			if (_76$$41) {
				ZEPHIR_OBS_NVAR(&_77$$41);
				zephir_read_property(&_77$$41, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
				_76$$41 = zephir_instance_of_ev(&_77$$41, phalcon_events_managerinterface_ce);
			}
			if (_76$$41) {
				zephir_read_property(&_78$$46, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&eventsManager, &_78$$46);
				hasEventsManager = 1;
			}
			if (zephir_is_true(&eventsManager)) {

				/* try_start_6: */

					ZEPHIR_INIT_NVAR(&_80$$48);
					ZVAL_STRING(&_80$$48, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD(&_79$$48, &eventsManager, "fire", NULL, 0, &_80$$48, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_81$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_79$$48);
					if (!(_81$$48)) {
						zephir_read_property(&_82$$48, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_81$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_82$$48);
					}
					if (_81$$48) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_83$$47);
					ZVAL_OBJ(&_83$$47, EG(exception));
					Z_ADDREF_P(&_83$$47);
					if (zephir_is_instance_of(&_83$$47, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_83$$47);
						ZEPHIR_CALL_METHOD(&_84$$50, this_ptr, "handleexception", NULL, 0, &e);
						zephir_check_call_status();
						_85$$50 = ZEPHIR_IS_FALSE_IDENTICAL(&_84$$50);
						if (!(_85$$50)) {
							zephir_read_property(&_86$$50, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
							_85$$50 = ZEPHIR_IS_FALSE_IDENTICAL(&_86$$50);
						}
						if (_85$$50) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 599);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("modelBinding"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_36$$10)) {
			zephir_read_property(&_87$$52, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_87$$52);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			zephir_read_property(&_87$$52, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_88$$52, &modelBinder, "bindtohandler", NULL, 0, &handler, &_87$$52, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &_88$$52);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_90$$53);
			ZVAL_STRING(&_90$$53, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD(&_89$$53, &eventsManager, "fire", NULL, 0, &_90$$53, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_89$$53)) {
				continue;
			}
			zephir_read_property(&_91$$53, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_91$$53)) {
				continue;
			}
		}
		zephir_array_fetch_long(&_92$$10, &hookCache, 2, PH_NOISY | PH_READONLY, "phalcon/Dispatcher/AbstractDispatcher.zep", 645);
		if (zephir_is_true(&_92$$10)) {
			ZEPHIR_CALL_METHOD(&_93$$56, &handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_93$$56)) {
				continue;
			}
			zephir_read_property(&_94$$56, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_94$$56)) {
				continue;
			}
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("lastHandler"), &handler);

		/* try_start_7: */

			zephir_read_property(&_96$$59, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_95$$59, this_ptr, "callactionmethod", &_97, 0, &handler, &actionMethod, &_96$$59);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval(this_ptr, ZEND_STRL("returnedValue"), &_95$$59);
			zephir_read_property(&_98$$59, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_98$$59)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_99$$10);
			ZVAL_OBJ(&_99$$10, EG(exception));
			Z_ADDREF_P(&_99$$10);
			if (zephir_is_instance_of(&_99$$10, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_99$$10);
				ZEPHIR_CALL_METHOD(&_100$$61, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				_101$$61 = ZEPHIR_IS_FALSE_IDENTICAL(&_100$$61);
				if (!(_101$$61)) {
					zephir_read_property(&_102$$61, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_101$$61 = ZEPHIR_IS_FALSE_IDENTICAL(&_102$$61);
				}
				if (_101$$61) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 681);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_104$$64);
				ZVAL_STRING(&_104$$64, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(&_103$$64, &eventsManager, "fire", NULL, 0, &_104$$64, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_105$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_103$$64);
				if (!(_105$$64)) {
					zephir_read_property(&_106$$64, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_105$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_106$$64);
				}
				if (_105$$64) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_107$$63);
				ZVAL_OBJ(&_107$$63, EG(exception));
				Z_ADDREF_P(&_107$$63);
				if (zephir_is_instance_of(&_107$$63, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_107$$63);
					ZEPHIR_CALL_METHOD(&_108$$66, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_109$$66 = ZEPHIR_IS_FALSE_IDENTICAL(&_108$$66);
					if (!(_109$$66)) {
						zephir_read_property(&_110$$66, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_109$$66 = ZEPHIR_IS_FALSE_IDENTICAL(&_110$$66);
					}
					if (_109$$66) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 697);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		zephir_array_fetch_long(&_111$$10, &hookCache, 3, PH_NOISY | PH_READONLY, "phalcon/Dispatcher/AbstractDispatcher.zep", 704);
		if (zephir_is_true(&_111$$10)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_112$$69, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_113$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_112$$69);
				if (!(_113$$69)) {
					zephir_read_property(&_114$$69, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_113$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_114$$69);
				}
				if (_113$$69) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_115$$68);
				ZVAL_OBJ(&_115$$68, EG(exception));
				Z_ADDREF_P(&_115$$68);
				if (zephir_is_instance_of(&_115$$68, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_115$$68);
					ZEPHIR_CALL_METHOD(&_116$$71, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_117$$71 = ZEPHIR_IS_FALSE_IDENTICAL(&_116$$71);
					if (!(_117$$71)) {
						zephir_read_property(&_118$$71, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_117$$71 = ZEPHIR_IS_FALSE_IDENTICAL(&_118$$71);
					}
					if (_117$$71) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 714);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_119$$74);
				ZVAL_STRING(&_119$$74, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_119$$74, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_120$$73);
				ZVAL_OBJ(&_120$$73, EG(exception));
				Z_ADDREF_P(&_120$$73);
				if (zephir_is_instance_of(&_120$$73, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_120$$73);
					ZEPHIR_CALL_METHOD(&_121$$75, this_ptr, "handleexception", NULL, 0, &e);
					zephir_check_call_status();
					_122$$75 = ZEPHIR_IS_FALSE_IDENTICAL(&_121$$75);
					if (!(_122$$75)) {
						zephir_read_property(&_123$$75, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_122$$75 = ZEPHIR_IS_FALSE_IDENTICAL(&_123$$75);
					}
					if (_122$$75) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 731);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_124$$78);
			ZVAL_STRING(&_124$$78, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_124$$78, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_125$$77);
			ZVAL_OBJ(&_125$$77, EG(exception));
			Z_ADDREF_P(&_125$$77);
			if (zephir_is_instance_of(&_125$$77, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_125$$77);
				ZEPHIR_CALL_METHOD(&_126$$79, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_126$$79)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 748);
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
 * @throws PhalconException
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(forward, forward_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &forward_param);
	zephir_get_arrval(&forward, forward_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isControllerInitialize"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_dispatcher_exceptions_forwardininitializeforbidden_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 160);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Dispatcher/AbstractDispatcher.zep", 780);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("previousNamespaceName"), &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("previousHandlerName"), &_3);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("previousActionName"), &_4);
	if (zephir_array_isset_string_fetch(&namespaceName, &forward, SL("namespace"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceName"), &namespaceName);
	}
	if (zephir_array_isset_string_fetch(&controllerName, &forward, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("handlerName"), &controllerName);
	} else {
		zephir_memory_observe(&taskName);
		if (zephir_array_isset_string_fetch(&taskName, &forward, SL("task"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("handlerName"), &taskName);
		}
	}
	if (zephir_array_isset_string_fetch(&actionName, &forward, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("actionName"), &actionName);
	}
	if (zephir_array_isset_string_fetch(&params, &forward, SL("params"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$false);
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forwarded"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forwarded"), &__$false);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&activeMethodName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeMethodMap"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&activeMethodName, &_0, &_1, 0))) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "tocamelcase", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&activeMethodName, "lcfirst", NULL, 149, &_2$$3);
		zephir_check_call_status();
		zephir_memory_observe(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC);
		zephir_update_property_array(this_ptr, SL("activeMethodMap"), &_4$$3, &activeMethodName);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("actionSuffix"), PH_NOISY_CC | PH_READONLY);
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
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getBoundModels)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
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
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
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
 * @param  mixed param
 * @param  string|array filters
 * @param  mixed defaultValue
 * @return mixed
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
 * @param  mixed param
 * @param  string|array filters
 * @param  mixed defaultValue
 * @return mixed
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&params, &_0);
	zephir_memory_observe(&paramValue);
	if (!(zephir_array_isset_fetch(&paramValue, &params, param, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) == IS_NULL) {
		RETURN_CCTOR(&paramValue);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "A dependency injection container is required to access the 'filter' service");
		ZVAL_LONG(&_2$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_1$$5, &_2$$5);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
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
 * @deprecated Use getParameters() instead
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
 * Gets action params
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParameters)
{

	RETURN_MEMBER_TYPED(getThis(), "params", IS_ARRAY);
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
 * Check if a param exists
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
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, hasParameter)
{
	zval *param, param_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionName_zv, actionName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("actionName"), &actionName_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionName_zv, actionName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &actionName_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(defaultNamespace)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&defaultNamespace_zv, defaultNamespace);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultNamespace"), &defaultNamespace_zv);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolveemptyproperties", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handlerSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlerSuffix, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlerName, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&namespaceName, &_0);
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/Dispatcher/AbstractDispatcher.zep", 1088))) {
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
 * @deprecated Use setParameters() instead
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
 * Sets action params to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParameters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &value);
	zephir_update_property_zval(this_ptr, ZEND_STRL("returnedValue"), value);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionSuffix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionSuffix_zv, actionSuffix);
	zephir_update_property_zval(this_ptr, ZEND_STRL("actionSuffix"), &actionSuffix_zv);
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setEventsManager)
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
 * Sets the default suffix for the handler
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setHandlerSuffix)
{
	zval handlerSuffix_zv;
	zend_string *handlerSuffix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerSuffix_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(handlerSuffix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&handlerSuffix_zv, handlerSuffix);
	zephir_update_property_zval(this_ptr, ZEND_STRL("handlerSuffix"), &handlerSuffix_zv);
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
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelBinding"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelBinding"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("modelBinder"), modelBinder);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("moduleName"), &moduleName_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(namespaceName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&namespaceName_zv, namespaceName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceName"), &namespaceName_zv);
}

/**
 * Returns value returned by the latest dispatched action
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getReturnedValue)
{

	RETURN_MEMBER(getThis(), "returnedValue");
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceName"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("defaultHandler"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, ZEND_STRL("handlerName"), &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_4))) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, ZEND_STRL("actionName"), &_5$$5);
	}
}

/**
 * Throws an internal dispatch exception.
 *
 * Subclasses build the namespace-specific exception and route it through
 * {@see handleException()} before throwing it when it was not handled.
 *
 * @param string message
 * @param int    exceptionCode
 *
 * @return mixed Returns `false` when {@see handleException()} swallowed the
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_memory_observe(&camelCaseInput);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("camelCaseMap"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&camelCaseInput, &_0, &input_zv, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "/[_-]+/");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_split", NULL, 135, &_1$$3, &input_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ucfirst");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_map", NULL, 21, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&camelCaseInput);
		zephir_fast_join_str(&camelCaseInput, SL(""), &_3$$3);
		zephir_update_property_array(this_ptr, SL("camelCaseMap"), &input_zv, &camelCaseInput);
	}
	RETURN_CCTOR(&camelCaseInput);
}

zend_object *zephir_init_properties_Phalcon_Dispatcher_AbstractDispatcher(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("handlerHookCache"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("handlerHookCache"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("handlerHashes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("handlerHashes"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("camelCaseMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("camelCaseMap"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("activeMethodMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("activeMethodMap"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

