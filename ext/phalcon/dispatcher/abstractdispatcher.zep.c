
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
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
	zend_bool _1, _14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _11, _5$$3, _6$$3;
	zend_string *actionMethod = NULL;
	zval *handler, handler_sub, actionMethod_zv, *params_param = NULL, result, observer, altHandler, altAction, altParams, _0, _2, _12, _13, _15, _3$$3, _4$$3, _7$$3, _8$$3, _9$$3, _10$$3, _16$$4, _17$$4;
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
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
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
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 3, 0);
		zephir_array_update_string(&_6$$3, SL("handler"), handler, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_6$$3, SL("action"), &actionMethod_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_6$$3, SL("params"), &params, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_5$$3, &_6$$3);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Phalcon\\Support\\Collection");
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "get", NULL, 0, &_7$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&observer, &_4$$3);
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "dispatch:beforeCallAction");
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "fire", NULL, 0, &_7$$3, this_ptr, &observer);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "handler");
		ZEPHIR_CALL_METHOD(&altHandler, &observer, "get", NULL, 0, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "action");
		ZEPHIR_CALL_METHOD(&altAction, &observer, "get", NULL, 0, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$3);
		array_init(&_7$$3);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "params");
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "array");
		ZEPHIR_CALL_METHOD(&altParams, &observer, "get", NULL, 0, &_9$$3, &_7$$3, &_10$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 2, 0);
	zephir_array_fast_append(&_11, &altHandler);
	zephir_array_fast_append(&_11, &altAction);
	ZEPHIR_CALL_FUNCTION(&_12, "array_values", NULL, 22, &altParams);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_11, &_12);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	_14 = Z_TYPE_P(&_13) != IS_NULL;
	if (_14) {
		zephir_memory_observe(&_15);
		zephir_read_property(&_15, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
		_14 = zephir_instance_of_ev(&_15, phalcon_events_managerinterface_ce);
	}
	if (_14) {
		zephir_array_update_string(&observer, SL("result"), &result, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_16$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_17$$4);
		ZVAL_STRING(&_17$$4, "dispatch:afterCallAction");
		ZEPHIR_CALL_METHOD(NULL, &_16$$4, "fire", NULL, 0, &_17$$4, this_ptr, &observer);
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
	zval _43$$10;
	zend_bool hasService = 0, hasEventsManager = 0, isNewHandler = 0, _5$$5, _15$$13, _20$$15, _28$$18, _33$$20, _41$$23, _50$$25, _53$$31, _59$$33, _63$$36, _69$$38, _75$$43, _77$$40, _79$$40, _84$$47, _89$$49, _105$$60, _109$$63, _114$$65, _117$$68, _122$$70, _128$$74;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_19 = NULL, *_22 = NULL, *_24 = NULL, *_27 = NULL, *_29 = NULL, *_32 = NULL, *_34 = NULL, *_40 = NULL, *_42 = NULL, *_49 = NULL, *_55 = NULL, *_58 = NULL, *_61 = NULL, *_65 = NULL, *_68 = NULL, *_71 = NULL, *_74 = NULL, *_88 = NULL, *_100 = NULL, *_104 = NULL, *_113 = NULL, *_121 = NULL, *_127 = NULL;
	zval __$true, __$false, value, handler, container, namespaceName, handlerName, actionName, eventsManager, handlerClass, status, actionMethod, modelBinder, bindCacheKey, handlerHash, e, _0, _1$$3, _2$$3, _3$$5, _4$$5, _6$$5, _7$$4, _8$$7, _9$$11, _10$$11, _13$$13, _14$$13, _16$$13, _17$$12, _18$$15, _21$$15, _23$$10, _35$$10, _36$$10, _37$$10, _102$$10, _25$$18, _26$$18, _30$$20, _31$$20, _38$$23, _39$$23, _44$$26, _45$$26, _46$$26, _47$$25, _48$$25, _51$$31, _52$$31, _54$$31, _56$$30, _57$$33, _60$$33, _62$$36, _64$$36, _66$$35, _67$$38, _70$$38, _72$$41, _73$$43, _76$$43, _78$$40, _80$$40, _81$$45, _82$$47, _83$$47, _85$$47, _86$$46, _87$$49, _90$$49, _91$$51, _92$$51, _93$$52, _94$$52, _95$$52, _96$$55, _97$$55, _98$$58, _99$$58, _101$$58, _103$$60, _106$$60, _107$$63, _108$$63, _110$$63, _111$$62, _112$$65, _115$$65, _116$$68, _118$$68, _119$$67, _120$$70, _123$$70, _124$$73, _125$$72, _126$$74, _129$$74, _130$$77, _131$$76, _132$$78;
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
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_102$$10);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_44$$26);
	ZVAL_UNDEF(&_45$$26);
	ZVAL_UNDEF(&_46$$26);
	ZVAL_UNDEF(&_47$$25);
	ZVAL_UNDEF(&_48$$25);
	ZVAL_UNDEF(&_51$$31);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_56$$30);
	ZVAL_UNDEF(&_57$$33);
	ZVAL_UNDEF(&_60$$33);
	ZVAL_UNDEF(&_62$$36);
	ZVAL_UNDEF(&_64$$36);
	ZVAL_UNDEF(&_66$$35);
	ZVAL_UNDEF(&_67$$38);
	ZVAL_UNDEF(&_70$$38);
	ZVAL_UNDEF(&_72$$41);
	ZVAL_UNDEF(&_73$$43);
	ZVAL_UNDEF(&_76$$43);
	ZVAL_UNDEF(&_78$$40);
	ZVAL_UNDEF(&_80$$40);
	ZVAL_UNDEF(&_81$$45);
	ZVAL_UNDEF(&_82$$47);
	ZVAL_UNDEF(&_83$$47);
	ZVAL_UNDEF(&_85$$47);
	ZVAL_UNDEF(&_86$$46);
	ZVAL_UNDEF(&_87$$49);
	ZVAL_UNDEF(&_90$$49);
	ZVAL_UNDEF(&_91$$51);
	ZVAL_UNDEF(&_92$$51);
	ZVAL_UNDEF(&_93$$52);
	ZVAL_UNDEF(&_94$$52);
	ZVAL_UNDEF(&_95$$52);
	ZVAL_UNDEF(&_96$$55);
	ZVAL_UNDEF(&_97$$55);
	ZVAL_UNDEF(&_98$$58);
	ZVAL_UNDEF(&_99$$58);
	ZVAL_UNDEF(&_101$$58);
	ZVAL_UNDEF(&_103$$60);
	ZVAL_UNDEF(&_106$$60);
	ZVAL_UNDEF(&_107$$63);
	ZVAL_UNDEF(&_108$$63);
	ZVAL_UNDEF(&_110$$63);
	ZVAL_UNDEF(&_111$$62);
	ZVAL_UNDEF(&_112$$65);
	ZVAL_UNDEF(&_115$$65);
	ZVAL_UNDEF(&_116$$68);
	ZVAL_UNDEF(&_118$$68);
	ZVAL_UNDEF(&_119$$67);
	ZVAL_UNDEF(&_120$$70);
	ZVAL_UNDEF(&_123$$70);
	ZVAL_UNDEF(&_124$$73);
	ZVAL_UNDEF(&_125$$72);
	ZVAL_UNDEF(&_126$$74);
	ZVAL_UNDEF(&_129$$74);
	ZVAL_UNDEF(&_130$$77);
	ZVAL_UNDEF(&_131$$76);
	ZVAL_UNDEF(&_132$$78);
	ZVAL_UNDEF(&_43$$10);
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
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 272);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", &_11, 0, &_9$$11, &_10$$11);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$false);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolveemptyproperties", &_12, 0);
		zephir_check_call_status();
		if (hasEventsManager) {

			/* try_start_2: */

				ZEPHIR_INIT_NVAR(&_14$$13);
				ZVAL_STRING(&_14$$13, "dispatch:beforeDispatch");
				ZEPHIR_CALL_METHOD(&_13$$13, &eventsManager, "fire", NULL, 0, &_14$$13, this_ptr);
				zephir_check_call_status_or_jump(try_end_2);
				_15$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_13$$13);
				if (!(_15$$13)) {
					zephir_read_property(&_16$$13, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_15$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_16$$13);
				}
				if (_15$$13) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZVAL_OBJ(&_17$$12, EG(exception));
				Z_ADDREF_P(&_17$$12);
				if (zephir_is_instance_of(&_17$$12, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_17$$12);
					ZEPHIR_CALL_METHOD(&_18$$15, this_ptr, "handleexception", &_19, 0, &e);
					zephir_check_call_status();
					_20$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_18$$15);
					if (!(_20$$15)) {
						zephir_read_property(&_21$$15, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_20$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_21$$15);
					}
					if (_20$$15) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 312);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_22, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_23$$10, &container, "has", &_24, 0, &handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(&_23$$10);
		if (!(hasService)) {
			hasService = zephir_class_exists(&handlerClass, 1);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_NVAR(&_25$$18);
			ZEPHIR_CONCAT_VS(&_25$$18, &handlerClass, " handler class cannot be loaded");
			ZVAL_LONG(&_26$$18, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_27, 0, &_25$$18, &_26$$18);
			zephir_check_call_status();
			_28$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_28$$18) {
				zephir_read_property(&_26$$18, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_28$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&_26$$18);
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
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_32, 0, &_30$$20, &_31$$20);
			zephir_check_call_status();
			_33$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_33$$20) {
				zephir_read_property(&_31$$20, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_33$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&_31$$20);
			}
			if (_33$$20) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_FUNCTION(&handlerHash, "spl_object_hash", &_34, 104, &handler);
		zephir_check_call_status();
		zephir_read_property(&_35$$10, this_ptr, ZEND_STRL("handlerHashes"), PH_NOISY_CC | PH_READONLY);
		isNewHandler = !((zephir_array_isset(&_35$$10, &handlerHash)));
		if (isNewHandler) {
			zephir_update_property_array(this_ptr, SL("handlerHashes"), &handlerHash, &__$true);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeHandler"), &handler);
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&namespaceName, &_36$$10);
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&handlerName, &_36$$10);
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&actionName, &_36$$10);
		ZEPHIR_OBS_NVAR(&_37$$10);
		zephir_read_property(&_37$$10, this_ptr, ZEND_STRL("params"), PH_NOISY_CC);
		if (UNEXPECTED(Z_TYPE_P(&_37$$10) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&_38$$23);
			ZVAL_STRING(&_38$$23, "Action parameters must be an Array");
			ZVAL_LONG(&_39$$23, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_40, 0, &_38$$23, &_39$$23);
			zephir_check_call_status();
			_41$$23 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_41$$23) {
				zephir_read_property(&_39$$23, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_41$$23 = ZEPHIR_IS_FALSE_IDENTICAL(&_39$$23);
			}
			if (_41$$23) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_42, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_43$$10);
		zephir_create_array(&_43$$10, 2, 0);
		zephir_array_fast_append(&_43$$10, &handler);
		zephir_array_fast_append(&_43$$10, &actionMethod);
		if (UNEXPECTED(!(zephir_is_callable(&_43$$10)))) {
			if (hasEventsManager) {
				ZEPHIR_INIT_NVAR(&_45$$26);
				ZVAL_STRING(&_45$$26, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD(&_44$$26, &eventsManager, "fire", NULL, 0, &_45$$26, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_44$$26)) {
					continue;
				}
				zephir_read_property(&_46$$26, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_46$$26)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_47$$25);
			ZEPHIR_CONCAT_SVSVS(&_47$$25, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_48$$25, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_49, 0, &_47$$25, &_48$$25);
			zephir_check_call_status();
			_50$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_50$$25) {
				zephir_read_property(&_48$$25, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_50$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&_48$$25);
			}
			if (_50$$25) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_52$$31);
				ZVAL_STRING(&_52$$31, "dispatch:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_51$$31, &eventsManager, "fire", NULL, 0, &_52$$31, this_ptr);
				zephir_check_call_status_or_jump(try_end_3);
				_53$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_51$$31);
				if (!(_53$$31)) {
					zephir_read_property(&_54$$31, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_53$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_54$$31);
				}
				if (_53$$31) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_55, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_56$$30);
				ZVAL_OBJ(&_56$$30, EG(exception));
				Z_ADDREF_P(&_56$$30);
				if (zephir_is_instance_of(&_56$$30, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_56$$30);
					ZEPHIR_CALL_METHOD(&_57$$33, this_ptr, "handleexception", &_58, 0, &e);
					zephir_check_call_status();
					_59$$33 = ZEPHIR_IS_FALSE_IDENTICAL(&_57$$33);
					if (!(_59$$33)) {
						zephir_read_property(&_60$$33, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_59$$33 = ZEPHIR_IS_FALSE_IDENTICAL(&_60$$33);
					}
					if (_59$$33) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_61, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 451);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("beforeexecuteroute")) == SUCCESS)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_62$$36, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_63$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_62$$36);
				if (!(_63$$36)) {
					zephir_read_property(&_64$$36, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_63$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_64$$36);
				}
				if (_63$$36) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_65, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_66$$35);
				ZVAL_OBJ(&_66$$35, EG(exception));
				Z_ADDREF_P(&_66$$35);
				if (zephir_is_instance_of(&_66$$35, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_66$$35);
					ZEPHIR_CALL_METHOD(&_67$$38, this_ptr, "handleexception", &_68, 0, &e);
					zephir_check_call_status();
					_69$$38 = ZEPHIR_IS_FALSE_IDENTICAL(&_67$$38);
					if (!(_69$$38)) {
						zephir_read_property(&_70$$38, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_69$$38 = ZEPHIR_IS_FALSE_IDENTICAL(&_70$$38);
					}
					if (_69$$38) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_71, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 470);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (isNewHandler) {
			if ((zephir_method_exists_ex(&handler, ZEND_STRL("initialize")) == SUCCESS)) {

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
					ZEPHIR_INIT_NVAR(&_72$$41);
					ZVAL_OBJ(&_72$$41, EG(exception));
					Z_ADDREF_P(&_72$$41);
					if (zephir_is_instance_of(&_72$$41, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_72$$41);
						if (0) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$true);
						} else {
							zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$false);
						}
						ZEPHIR_CALL_METHOD(&_73$$43, this_ptr, "handleexception", &_74, 0, &e);
						zephir_check_call_status();
						_75$$43 = ZEPHIR_IS_FALSE_IDENTICAL(&_73$$43);
						if (!(_75$$43)) {
							zephir_read_property(&_76$$43, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
							_75$$43 = ZEPHIR_IS_FALSE_IDENTICAL(&_76$$43);
						}
						if (_75$$43) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 512);
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
			_77$$40 = !hasEventsManager;
			if (_77$$40) {
				zephir_read_property(&_78$$40, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				_77$$40 = Z_TYPE_P(&_78$$40) != IS_NULL;
			}
			_79$$40 = _77$$40;
			if (_79$$40) {
				ZEPHIR_OBS_NVAR(&_80$$40);
				zephir_read_property(&_80$$40, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC);
				_79$$40 = zephir_instance_of_ev(&_80$$40, phalcon_events_managerinterface_ce);
			}
			if (_79$$40) {
				zephir_read_property(&_81$$45, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&eventsManager, &_81$$45);
				hasEventsManager = 1;
			}
			if (zephir_is_true(&eventsManager)) {

				/* try_start_6: */

					ZEPHIR_INIT_NVAR(&_83$$47);
					ZVAL_STRING(&_83$$47, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD(&_82$$47, &eventsManager, "fire", NULL, 0, &_83$$47, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_84$$47 = ZEPHIR_IS_FALSE_IDENTICAL(&_82$$47);
					if (!(_84$$47)) {
						zephir_read_property(&_85$$47, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_84$$47 = ZEPHIR_IS_FALSE_IDENTICAL(&_85$$47);
					}
					if (_84$$47) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_86$$46);
					ZVAL_OBJ(&_86$$46, EG(exception));
					Z_ADDREF_P(&_86$$46);
					if (zephir_is_instance_of(&_86$$46, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_86$$46);
						ZEPHIR_CALL_METHOD(&_87$$49, this_ptr, "handleexception", &_88, 0, &e);
						zephir_check_call_status();
						_89$$49 = ZEPHIR_IS_FALSE_IDENTICAL(&_87$$49);
						if (!(_89$$49)) {
							zephir_read_property(&_90$$49, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
							_89$$49 = ZEPHIR_IS_FALSE_IDENTICAL(&_90$$49);
						}
						if (_89$$49) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 540);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("modelBinding"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_36$$10)) {
			zephir_read_property(&_91$$51, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_91$$51);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			zephir_read_property(&_91$$51, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_92$$51, &modelBinder, "bindtohandler", NULL, 0, &handler, &_91$$51, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &_92$$51);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_94$$52);
			ZVAL_STRING(&_94$$52, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD(&_93$$52, &eventsManager, "fire", NULL, 0, &_94$$52, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_93$$52)) {
				continue;
			}
			zephir_read_property(&_95$$52, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_95$$52)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("afterbinding")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_96$$55, &handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_96$$55)) {
				continue;
			}
			zephir_read_property(&_97$$55, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_97$$55)) {
				continue;
			}
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("lastHandler"), &handler);

		/* try_start_7: */

			zephir_read_property(&_99$$58, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_98$$58, this_ptr, "callactionmethod", &_100, 0, &handler, &actionMethod, &_99$$58);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval(this_ptr, ZEND_STRL("returnedValue"), &_98$$58);
			zephir_read_property(&_101$$58, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_101$$58)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_102$$10);
			ZVAL_OBJ(&_102$$10, EG(exception));
			Z_ADDREF_P(&_102$$10);
			if (zephir_is_instance_of(&_102$$10, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_102$$10);
				ZEPHIR_CALL_METHOD(&_103$$60, this_ptr, "handleexception", &_104, 0, &e);
				zephir_check_call_status();
				_105$$60 = ZEPHIR_IS_FALSE_IDENTICAL(&_103$$60);
				if (!(_105$$60)) {
					zephir_read_property(&_106$$60, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_105$$60 = ZEPHIR_IS_FALSE_IDENTICAL(&_106$$60);
				}
				if (_105$$60) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 612);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_108$$63);
				ZVAL_STRING(&_108$$63, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(&_107$$63, &eventsManager, "fire", NULL, 0, &_108$$63, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_109$$63 = ZEPHIR_IS_FALSE_IDENTICAL(&_107$$63);
				if (!(_109$$63)) {
					zephir_read_property(&_110$$63, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_109$$63 = ZEPHIR_IS_FALSE_IDENTICAL(&_110$$63);
				}
				if (_109$$63) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_111$$62);
				ZVAL_OBJ(&_111$$62, EG(exception));
				Z_ADDREF_P(&_111$$62);
				if (zephir_is_instance_of(&_111$$62, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_111$$62);
					ZEPHIR_CALL_METHOD(&_112$$65, this_ptr, "handleexception", &_113, 0, &e);
					zephir_check_call_status();
					_114$$65 = ZEPHIR_IS_FALSE_IDENTICAL(&_112$$65);
					if (!(_114$$65)) {
						zephir_read_property(&_115$$65, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_114$$65 = ZEPHIR_IS_FALSE_IDENTICAL(&_115$$65);
					}
					if (_114$$65) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 628);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("afterexecuteroute")) == SUCCESS)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_116$$68, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_117$$68 = ZEPHIR_IS_FALSE_IDENTICAL(&_116$$68);
				if (!(_117$$68)) {
					zephir_read_property(&_118$$68, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_117$$68 = ZEPHIR_IS_FALSE_IDENTICAL(&_118$$68);
				}
				if (_117$$68) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_119$$67);
				ZVAL_OBJ(&_119$$67, EG(exception));
				Z_ADDREF_P(&_119$$67);
				if (zephir_is_instance_of(&_119$$67, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_119$$67);
					ZEPHIR_CALL_METHOD(&_120$$70, this_ptr, "handleexception", &_121, 0, &e);
					zephir_check_call_status();
					_122$$70 = ZEPHIR_IS_FALSE_IDENTICAL(&_120$$70);
					if (!(_122$$70)) {
						zephir_read_property(&_123$$70, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_122$$70 = ZEPHIR_IS_FALSE_IDENTICAL(&_123$$70);
					}
					if (_122$$70) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 645);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_124$$73);
				ZVAL_STRING(&_124$$73, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_124$$73, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_125$$72);
				ZVAL_OBJ(&_125$$72, EG(exception));
				Z_ADDREF_P(&_125$$72);
				if (zephir_is_instance_of(&_125$$72, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_125$$72);
					ZEPHIR_CALL_METHOD(&_126$$74, this_ptr, "handleexception", &_127, 0, &e);
					zephir_check_call_status();
					_128$$74 = ZEPHIR_IS_FALSE_IDENTICAL(&_126$$74);
					if (!(_128$$74)) {
						zephir_read_property(&_129$$74, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_128$$74 = ZEPHIR_IS_FALSE_IDENTICAL(&_129$$74);
					}
					if (_128$$74) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 662);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_130$$77);
			ZVAL_STRING(&_130$$77, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_130$$77, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_131$$76);
			ZVAL_OBJ(&_131$$76, EG(exception));
			Z_ADDREF_P(&_131$$76);
			if (zephir_is_instance_of(&_131$$76, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_131$$76);
				ZEPHIR_CALL_METHOD(&_132$$78, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_132$$78)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 679);
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
	zval *forward_param = NULL, __$true, __$false, namespaceName, controllerName, params, actionName, taskName, _0, _1, _2, _3;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(forward, forward_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &forward_param);
	zephir_get_arrval(&forward, forward_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isControllerInitialize"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_dispatcher_exception_ce, "Forwarding inside a controller's initialize() method is forbidden", "phalcon/Dispatcher/AbstractDispatcher.zep", 713);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("previousNamespaceName"), &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("previousHandlerName"), &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("previousActionName"), &_3);
	if (zephir_array_isset_string_fetch(&namespaceName, &forward, SL("namespace"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceName"), &namespaceName);
	}
	zephir_memory_observe(&taskName);
	if (zephir_array_isset_string_fetch(&controllerName, &forward, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("handlerName"), &controllerName);
	} else if (zephir_array_isset_string_fetch(&taskName, &forward, SL("task"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("handlerName"), &taskName);
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
		ZEPHIR_CALL_FUNCTION(&activeMethodName, "lcfirst", NULL, 99, &_2$$3);
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
 * @todo remove this in future versions
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
 * @todo remove this in future versions
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
 * Check if a param exists
 * @todo deprecate this in the future
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
	RETURN_BOOL(zephir_array_isset(&_0, param));
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
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/Dispatcher/AbstractDispatcher.zep", 990))) {
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
 * @todo deprecate this in the future
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
 * @todo deprecate this in the future
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
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_split", NULL, 93, &_1$$3, &input_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ucfirst");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_map", NULL, 14, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&camelCaseInput);
		zephir_fast_join_str(&camelCaseInput, SL(""), &_3$$3);
		zephir_update_property_array(this_ptr, SL("camelCaseMap"), &input_zv, &camelCaseInput);
	}
	RETURN_CCTOR(&camelCaseInput);
}

zend_object *zephir_init_properties_Phalcon_Dispatcher_AbstractDispatcher(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

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
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("handlerHashes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("handlerHashes"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("camelCaseMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("camelCaseMap"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("activeMethodMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("activeMethodMap"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

