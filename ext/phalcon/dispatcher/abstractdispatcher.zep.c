
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
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
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("actionName"), ZEND_ACC_PROTECTED);
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
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultNamespace"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerHashes"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerName"), ZEND_ACC_PROTECTED);
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
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("moduleName"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("namespaceName"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("params"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("previousActionName"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("previousHandlerName"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("previousNamespaceName"), ZEND_ACC_PROTECTED);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _0;
	zval actionMethod;
	zval *handler, handler_sub, *actionMethod_param = NULL, *params_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_STR(actionMethod)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &handler, &actionMethod_param, &params_param);
	zephir_get_strval(&actionMethod, actionMethod_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, handler);
	zephir_array_fast_append(&_0, &actionMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &params);
	zephir_check_call_status();
	RETURN_MM();
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
	zend_bool hasService = 0, hasEventsManager = 0, isNewHandler = 0, _5$$5, _16$$13, _21$$15, _29$$18, _34$$20, _41$$23, _51$$25, _55$$31, _61$$33, _65$$36, _71$$38, _77$$43, _82$$46, _87$$48, _103$$59, _108$$62, _113$$64, _116$$67, _121$$69, _128$$73;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_15 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_28 = NULL, *_30 = NULL, *_33 = NULL, *_35 = NULL, *_40 = NULL, *_42 = NULL, *_46 = NULL, *_50 = NULL, *_54 = NULL, *_57 = NULL, *_60 = NULL, *_63 = NULL, *_67 = NULL, *_70 = NULL, *_73 = NULL, *_76 = NULL, *_81 = NULL, *_86 = NULL, *_93 = NULL, *_98 = NULL, *_102 = NULL, *_107 = NULL, *_112 = NULL, *_120 = NULL, *_124 = NULL, *_127 = NULL;
	zval __$true, __$false, value, handler, container, namespaceName, handlerName, actionName, params, eventsManager, handlerClass, status, actionMethod, modelBinder, bindCacheKey, handlerHash, e, _0, _1$$3, _2$$3, _3$$5, _4$$5, _6$$5, _7$$4, _8$$7, _9$$11, _10$$11, _13$$13, _14$$13, _17$$13, _18$$12, _19$$15, _22$$15, _24$$10, _36$$10, _37$$10, _100$$10, _26$$18, _27$$18, _31$$20, _32$$20, _38$$23, _39$$23, _44$$26, _45$$26, _47$$26, _48$$25, _49$$25, _52$$31, _53$$31, _56$$31, _58$$30, _59$$33, _62$$33, _64$$36, _66$$36, _68$$35, _69$$38, _72$$38, _74$$41, _75$$43, _78$$43, _79$$46, _80$$46, _83$$46, _84$$45, _85$$48, _88$$48, _89$$50, _90$$50, _91$$51, _92$$51, _94$$51, _95$$54, _96$$54, _97$$57, _99$$57, _101$$59, _104$$59, _105$$62, _106$$62, _109$$62, _110$$61, _111$$64, _114$$64, _115$$67, _117$$67, _118$$66, _119$$69, _122$$69, _123$$72, _125$$71, _126$$73, _129$$73, _130$$76, _131$$75, _132$$77;
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
	ZVAL_UNDEF(&params);
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
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_100$$10);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_44$$26);
	ZVAL_UNDEF(&_45$$26);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_48$$25);
	ZVAL_UNDEF(&_49$$25);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_53$$31);
	ZVAL_UNDEF(&_56$$31);
	ZVAL_UNDEF(&_58$$30);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_62$$33);
	ZVAL_UNDEF(&_64$$36);
	ZVAL_UNDEF(&_66$$36);
	ZVAL_UNDEF(&_68$$35);
	ZVAL_UNDEF(&_69$$38);
	ZVAL_UNDEF(&_72$$38);
	ZVAL_UNDEF(&_74$$41);
	ZVAL_UNDEF(&_75$$43);
	ZVAL_UNDEF(&_78$$43);
	ZVAL_UNDEF(&_79$$46);
	ZVAL_UNDEF(&_80$$46);
	ZVAL_UNDEF(&_83$$46);
	ZVAL_UNDEF(&_84$$45);
	ZVAL_UNDEF(&_85$$48);
	ZVAL_UNDEF(&_88$$48);
	ZVAL_UNDEF(&_89$$50);
	ZVAL_UNDEF(&_90$$50);
	ZVAL_UNDEF(&_91$$51);
	ZVAL_UNDEF(&_92$$51);
	ZVAL_UNDEF(&_94$$51);
	ZVAL_UNDEF(&_95$$54);
	ZVAL_UNDEF(&_96$$54);
	ZVAL_UNDEF(&_97$$57);
	ZVAL_UNDEF(&_99$$57);
	ZVAL_UNDEF(&_101$$59);
	ZVAL_UNDEF(&_104$$59);
	ZVAL_UNDEF(&_105$$62);
	ZVAL_UNDEF(&_106$$62);
	ZVAL_UNDEF(&_109$$62);
	ZVAL_UNDEF(&_110$$61);
	ZVAL_UNDEF(&_111$$64);
	ZVAL_UNDEF(&_114$$64);
	ZVAL_UNDEF(&_115$$67);
	ZVAL_UNDEF(&_117$$67);
	ZVAL_UNDEF(&_118$$66);
	ZVAL_UNDEF(&_119$$69);
	ZVAL_UNDEF(&_122$$69);
	ZVAL_UNDEF(&_123$$72);
	ZVAL_UNDEF(&_125$$71);
	ZVAL_UNDEF(&_126$$73);
	ZVAL_UNDEF(&_129$$73);
	ZVAL_UNDEF(&_130$$76);
	ZVAL_UNDEF(&_131$$75);
	ZVAL_UNDEF(&_132$$77);
	ZVAL_UNDEF(&_43$$10);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
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
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 229);
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
				ZEPHIR_CALL_METHOD(&_13$$13, &eventsManager, "fire", &_15, 0, &_14$$13, this_ptr);
				zephir_check_call_status_or_jump(try_end_2);
				_16$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_13$$13);
				if (!(_16$$13)) {
					zephir_read_property(&_17$$13, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_16$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_17$$13);
				}
				if (_16$$13) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_18$$12);
				ZVAL_OBJ(&_18$$12, EG(exception));
				Z_ADDREF_P(&_18$$12);
				if (zephir_is_instance_of(&_18$$12, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_18$$12);
					ZEPHIR_CALL_METHOD(&_19$$15, this_ptr, "handleexception", &_20, 0, &e);
					zephir_check_call_status();
					_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_19$$15);
					if (!(_21$$15)) {
						zephir_read_property(&_22$$15, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_22$$15);
					}
					if (_21$$15) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 269);
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
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_28, 0, &_26$$18, &_27$$18);
			zephir_check_call_status();
			_29$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_29$$18) {
				zephir_read_property(&_27$$18, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_29$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&_27$$18);
			}
			if (_29$$18) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, &container, "getshared", &_30, 0, &handlerClass);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&handler) != IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(&_31$$20);
			ZVAL_STRING(&_31$$20, "Invalid handler returned from the services container");
			ZVAL_LONG(&_32$$20, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_33, 0, &_31$$20, &_32$$20);
			zephir_check_call_status();
			_34$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_34$$20) {
				zephir_read_property(&_32$$20, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_34$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&_32$$20);
			}
			if (_34$$20) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_FUNCTION(&handlerHash, "spl_object_hash", &_35, 105, &handler);
		zephir_check_call_status();
		zephir_read_property(&_36$$10, this_ptr, ZEND_STRL("handlerHashes"), PH_NOISY_CC | PH_READONLY);
		isNewHandler = !((zephir_array_isset(&_36$$10, &handlerHash)));
		if (isNewHandler) {
			zephir_update_property_array(this_ptr, SL("handlerHashes"), &handlerHash, &__$true);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeHandler"), &handler);
		zephir_read_property(&_37$$10, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&namespaceName, &_37$$10);
		zephir_read_property(&_37$$10, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&handlerName, &_37$$10);
		zephir_read_property(&_37$$10, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&actionName, &_37$$10);
		zephir_read_property(&_37$$10, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&params, &_37$$10);
		if (UNEXPECTED(Z_TYPE_P(&params) != IS_ARRAY)) {
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
				ZEPHIR_CALL_METHOD(&_44$$26, &eventsManager, "fire", &_46, 0, &_45$$26, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_44$$26)) {
					continue;
				}
				zephir_read_property(&_47$$26, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_47$$26)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_48$$25);
			ZEPHIR_CONCAT_SVSVS(&_48$$25, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_49$$25, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_50, 0, &_48$$25, &_49$$25);
			zephir_check_call_status();
			_51$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_51$$25) {
				zephir_read_property(&_49$$25, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_51$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&_49$$25);
			}
			if (_51$$25) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_53$$31);
				ZVAL_STRING(&_53$$31, "dispatch:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_52$$31, &eventsManager, "fire", &_54, 0, &_53$$31, this_ptr);
				zephir_check_call_status_or_jump(try_end_3);
				_55$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_52$$31);
				if (!(_55$$31)) {
					zephir_read_property(&_56$$31, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_55$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_56$$31);
				}
				if (_55$$31) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_57, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_58$$30);
				ZVAL_OBJ(&_58$$30, EG(exception));
				Z_ADDREF_P(&_58$$30);
				if (zephir_is_instance_of(&_58$$30, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_58$$30);
					ZEPHIR_CALL_METHOD(&_59$$33, this_ptr, "handleexception", &_60, 0, &e);
					zephir_check_call_status();
					_61$$33 = ZEPHIR_IS_FALSE_IDENTICAL(&_59$$33);
					if (!(_61$$33)) {
						zephir_read_property(&_62$$33, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_61$$33 = ZEPHIR_IS_FALSE_IDENTICAL(&_62$$33);
					}
					if (_61$$33) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_63, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 410);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("beforeexecuteroute")) == SUCCESS)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_64$$36, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_65$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_64$$36);
				if (!(_65$$36)) {
					zephir_read_property(&_66$$36, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_65$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_66$$36);
				}
				if (_65$$36) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_67, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_68$$35);
				ZVAL_OBJ(&_68$$35, EG(exception));
				Z_ADDREF_P(&_68$$35);
				if (zephir_is_instance_of(&_68$$35, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_68$$35);
					ZEPHIR_CALL_METHOD(&_69$$38, this_ptr, "handleexception", &_70, 0, &e);
					zephir_check_call_status();
					_71$$38 = ZEPHIR_IS_FALSE_IDENTICAL(&_69$$38);
					if (!(_71$$38)) {
						zephir_read_property(&_72$$38, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_71$$38 = ZEPHIR_IS_FALSE_IDENTICAL(&_72$$38);
					}
					if (_71$$38) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_73, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 429);
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
					ZEPHIR_INIT_NVAR(&_74$$41);
					ZVAL_OBJ(&_74$$41, EG(exception));
					Z_ADDREF_P(&_74$$41);
					if (zephir_is_instance_of(&_74$$41, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_74$$41);
						if (0) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$true);
						} else {
							zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$false);
						}
						ZEPHIR_CALL_METHOD(&_75$$43, this_ptr, "handleexception", &_76, 0, &e);
						zephir_check_call_status();
						_77$$43 = ZEPHIR_IS_FALSE_IDENTICAL(&_75$$43);
						if (!(_77$$43)) {
							zephir_read_property(&_78$$43, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
							_77$$43 = ZEPHIR_IS_FALSE_IDENTICAL(&_78$$43);
						}
						if (_77$$43) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 471);
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
			if (zephir_is_true(&eventsManager)) {

				/* try_start_6: */

					ZEPHIR_INIT_NVAR(&_80$$46);
					ZVAL_STRING(&_80$$46, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD(&_79$$46, &eventsManager, "fire", &_81, 0, &_80$$46, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_82$$46 = ZEPHIR_IS_FALSE_IDENTICAL(&_79$$46);
					if (!(_82$$46)) {
						zephir_read_property(&_83$$46, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_82$$46 = ZEPHIR_IS_FALSE_IDENTICAL(&_83$$46);
					}
					if (_82$$46) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_84$$45);
					ZVAL_OBJ(&_84$$45, EG(exception));
					Z_ADDREF_P(&_84$$45);
					if (zephir_is_instance_of(&_84$$45, SL("Exception"))) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_84$$45);
						ZEPHIR_CALL_METHOD(&_85$$48, this_ptr, "handleexception", &_86, 0, &e);
						zephir_check_call_status();
						_87$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_85$$48);
						if (!(_87$$48)) {
							zephir_read_property(&_88$$48, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
							_87$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_88$$48);
						}
						if (_87$$48) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 490);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property(&_37$$10, this_ptr, ZEND_STRL("modelBinding"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_37$$10)) {
			zephir_read_property(&_89$$50, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_89$$50);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			ZEPHIR_CALL_METHOD(&_90$$50, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&params, &_90$$50);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_92$$51);
			ZVAL_STRING(&_92$$51, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD(&_91$$51, &eventsManager, "fire", &_93, 0, &_92$$51, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_91$$51)) {
				continue;
			}
			zephir_read_property(&_94$$51, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_94$$51)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("afterbinding")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_95$$54, &handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_95$$54)) {
				continue;
			}
			zephir_read_property(&_96$$54, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_96$$54)) {
				continue;
			}
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("lastHandler"), &handler);

		/* try_start_7: */

			ZEPHIR_CALL_METHOD(&_97$$57, this_ptr, "callactionmethod", &_98, 0, &handler, &actionMethod, &params);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval(this_ptr, ZEND_STRL("returnedValue"), &_97$$57);
			zephir_read_property(&_99$$57, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_99$$57)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_100$$10);
			ZVAL_OBJ(&_100$$10, EG(exception));
			Z_ADDREF_P(&_100$$10);
			if (zephir_is_instance_of(&_100$$10, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_100$$10);
				ZEPHIR_CALL_METHOD(&_101$$59, this_ptr, "handleexception", &_102, 0, &e);
				zephir_check_call_status();
				_103$$59 = ZEPHIR_IS_FALSE_IDENTICAL(&_101$$59);
				if (!(_103$$59)) {
					zephir_read_property(&_104$$59, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_103$$59 = ZEPHIR_IS_FALSE_IDENTICAL(&_104$$59);
				}
				if (_103$$59) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 562);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_106$$62);
				ZVAL_STRING(&_106$$62, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(&_105$$62, &eventsManager, "fire", &_107, 0, &_106$$62, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_108$$62 = ZEPHIR_IS_FALSE_IDENTICAL(&_105$$62);
				if (!(_108$$62)) {
					zephir_read_property(&_109$$62, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_108$$62 = ZEPHIR_IS_FALSE_IDENTICAL(&_109$$62);
				}
				if (_108$$62) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_110$$61);
				ZVAL_OBJ(&_110$$61, EG(exception));
				Z_ADDREF_P(&_110$$61);
				if (zephir_is_instance_of(&_110$$61, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_110$$61);
					ZEPHIR_CALL_METHOD(&_111$$64, this_ptr, "handleexception", &_112, 0, &e);
					zephir_check_call_status();
					_113$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_111$$64);
					if (!(_113$$64)) {
						zephir_read_property(&_114$$64, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_113$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_114$$64);
					}
					if (_113$$64) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 578);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("afterexecuteroute")) == SUCCESS)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_115$$67, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_116$$67 = ZEPHIR_IS_FALSE_IDENTICAL(&_115$$67);
				if (!(_116$$67)) {
					zephir_read_property(&_117$$67, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_116$$67 = ZEPHIR_IS_FALSE_IDENTICAL(&_117$$67);
				}
				if (_116$$67) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_118$$66);
				ZVAL_OBJ(&_118$$66, EG(exception));
				Z_ADDREF_P(&_118$$66);
				if (zephir_is_instance_of(&_118$$66, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_118$$66);
					ZEPHIR_CALL_METHOD(&_119$$69, this_ptr, "handleexception", &_120, 0, &e);
					zephir_check_call_status();
					_121$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_119$$69);
					if (!(_121$$69)) {
						zephir_read_property(&_122$$69, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_121$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_122$$69);
					}
					if (_121$$69) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 595);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_123$$72);
				ZVAL_STRING(&_123$$72, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_124, 0, &_123$$72, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_125$$71);
				ZVAL_OBJ(&_125$$71, EG(exception));
				Z_ADDREF_P(&_125$$71);
				if (zephir_is_instance_of(&_125$$71, SL("Exception"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_125$$71);
					ZEPHIR_CALL_METHOD(&_126$$73, this_ptr, "handleexception", &_127, 0, &e);
					zephir_check_call_status();
					_128$$73 = ZEPHIR_IS_FALSE_IDENTICAL(&_126$$73);
					if (!(_128$$73)) {
						zephir_read_property(&_129$$73, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_128$$73 = ZEPHIR_IS_FALSE_IDENTICAL(&_129$$73);
					}
					if (_128$$73) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 612);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_130$$76);
			ZVAL_STRING(&_130$$76, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_130$$76, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_131$$75);
			ZVAL_OBJ(&_131$$75, EG(exception));
			Z_ADDREF_P(&_131$$75);
			if (zephir_is_instance_of(&_131$$75, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_131$$75);
				ZEPHIR_CALL_METHOD(&_132$$77, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_132$$77)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 629);
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
 * @throws Phalcon\Dispatcher\Exception
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(forward)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward_param);
	zephir_get_arrval(&forward, forward_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("isControllerInitialize"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_dispatcher_exception_ce, "Forwarding inside a controller's initialize() method is forbidden", "phalcon/Dispatcher/AbstractDispatcher.zep", 663);
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
	ZEPHIR_OBS_VAR(&taskName);
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
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "actionName");
}

/**
 * Gets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getActionSuffix)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "actionSuffix");
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


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&activeMethodName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeMethodMap"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&activeMethodName, &_0, &_1, 0))) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "tocamelcase", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&activeMethodName, "lcfirst", NULL, 101, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_4$$3);
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
 * Returns the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getDefaultNamespace)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultNamespace");
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getEventsManager)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Gets the default handler suffix
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getHandlerSuffix)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "handlerSuffix");
}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getModelBinder)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "modelBinder");
}

/**
 * Gets the module where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getModuleName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "moduleName");
}

/**
 * Gets a namespace to be prepended to the current handler name
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getNamespaceName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "namespaceName");
}

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed param
 * @param  string|array filters
 * @param  mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null, params, filter, paramValue, container, _0, _3, _4, _1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
	ZEPHIR_OBS_VAR(&paramValue);
	if (!(zephir_array_isset_fetch(&paramValue, &params, param, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) == IS_NULL) {
		RETURN_CCTOR(&paramValue);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "A dependency injection container is required to access the 'filter' service");
		ZVAL_LONG(&_2$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_1$$5, &_2$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "filter");
	ZEPHIR_CALL_METHOD(&_3, &container, "getshared", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filter, &_3);
	ZEPHIR_RETURN_CALL_METHOD(&filter, "sanitize", NULL, 0, &paramValue, filters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets action params
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");
}

/**
 * Check if a param exists
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, hasParam)
{
	zval *param, param_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "finished");
}

/**
 * Sets the action name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setActionName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);
	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("actionName"), &actionName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setDefaultAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);
	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &actionName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setDefaultNamespace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaultNamespace_param = NULL;
	zval defaultNamespace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultNamespace);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(defaultNamespace)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultNamespace_param);
	zephir_get_strval(&defaultNamespace, defaultNamespace_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultNamespace"), &defaultNamespace);
	ZEPHIR_MM_RESTORE();
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


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolveemptyproperties", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handlerSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlerSuffix, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlerName, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&namespaceName, &_0);
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/Dispatcher/AbstractDispatcher.zep", 912))) {
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
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParam)
{
	zval *param, param_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(param)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &param, &value);


	zephir_update_property_array(this_ptr, SL("params"), param, value);
}

/**
 * Sets action params to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &value);


	zephir_update_property_zval(this_ptr, ZEND_STRL("returnedValue"), value);
}

/**
 * Sets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setActionSuffix)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionSuffix_param = NULL;
	zval actionSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionSuffix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);
	zephir_get_strval(&actionSuffix, actionSuffix_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("actionSuffix"), &actionSuffix);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setEventsManager)
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
 * Sets the default suffix for the handler
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setHandlerSuffix)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handlerSuffix_param = NULL;
	zval handlerSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerSuffix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(handlerSuffix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handlerSuffix_param);
	zephir_get_strval(&handlerSuffix, handlerSuffix_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("handlerSuffix"), &handlerSuffix);
	ZEPHIR_MM_RESTORE();
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
	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(moduleName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);
	zephir_get_strval(&moduleName, moduleName_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("moduleName"), &moduleName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the namespace where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, setNamespaceName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(namespaceName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);
	zephir_get_strval(&namespaceName, namespaceName_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceName"), &namespaceName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns value returned by the latest dispatched action
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, getReturnedValue)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "returnedValue");
}

/**
 * Check if the current executed action was forwarded by another one
 */
PHP_METHOD(Phalcon_Dispatcher_AbstractDispatcher, wasForwarded)
{
	zval *this_ptr = getThis();



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
	zval *input_param = NULL, camelCaseInput, _0, _1$$3, _2$$3, _3$$3;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&camelCaseInput);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	ZEPHIR_OBS_VAR(&camelCaseInput);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("camelCaseMap"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&camelCaseInput, &_0, &input, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "/[_-]+/");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_split", NULL, 106, &_1$$3, &input);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ucfirst");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_map", NULL, 107, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&camelCaseInput);
		zephir_fast_join_str(&camelCaseInput, SL(""), &_3$$3);
		zephir_update_property_array(this_ptr, SL("camelCaseMap"), &input, &camelCaseInput);
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
	

		ZEPHIR_MM_GROW();
	
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

