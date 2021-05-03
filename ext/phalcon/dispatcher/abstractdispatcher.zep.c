
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

	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("activeHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("activeMethodMap"), ZEND_ACC_PROTECTED);
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
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultNamespace"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("defaultHandler"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerHashes"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerName"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_dispatcher_abstractdispatcher_ce, SL("handlerSuffix"), "", ZEND_ACC_PROTECTED);
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
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("lastHandler"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("modelBinder"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_dispatcher_abstractdispatcher_ce, SL("modelBinding"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("moduleName"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("namespaceName"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("params"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("previousActionName"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("previousHandlerName"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_dispatcher_abstractdispatcher_ce, SL("previousNamespaceName"), ZEND_ACC_PROTECTED);
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
	zval _45$$10;
	zend_bool hasService = 0, hasEventsManager = 0, isNewHandler = 0, _7$$5, _18$$13, _23$$15, _31$$18, _36$$20, _43$$23, _53$$25, _57$$31, _63$$33, _67$$36, _73$$38, _79$$43, _84$$46, _89$$48, _105$$59, _110$$62, _115$$64, _118$$67, _123$$69, _130$$73;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, value, handler, container, namespaceName, handlerName, actionName, params, eventsManager, handlerClass, status, actionMethod, modelBinder, bindCacheKey, handlerHash, e, _0, _1$$3, _3$$3, _4$$3, _5$$5, _6$$5, _8$$5, _9$$4, _10$$7, _11$$11, _12$$11, _15$$13, _16$$13, _19$$13, _20$$12, _21$$15, _24$$15, _26$$10, _38$$10, _39$$10, _102$$10, _28$$18, _29$$18, _33$$20, _34$$20, _40$$23, _41$$23, _46$$26, _47$$26, _49$$26, _50$$25, _51$$25, _54$$31, _55$$31, _58$$31, _60$$30, _61$$33, _64$$33, _66$$36, _68$$36, _70$$35, _71$$38, _74$$38, _76$$41, _77$$43, _80$$43, _81$$46, _82$$46, _85$$46, _86$$45, _87$$48, _90$$48, _91$$50, _92$$50, _93$$51, _94$$51, _96$$51, _97$$54, _98$$54, _99$$57, _101$$57, _103$$59, _106$$59, _107$$62, _108$$62, _111$$62, _112$$61, _113$$64, _116$$64, _117$$67, _119$$67, _120$$66, _121$$69, _124$$69, _125$$72, _127$$71, _128$$73, _131$$73, _132$$76, _133$$75, _134$$77;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberDispatches = 0;
	zephir_fcall_cache_entry *_2 = NULL, *_13 = NULL, *_14 = NULL, *_17 = NULL, *_22 = NULL, *_25 = NULL, *_27 = NULL, *_30 = NULL, *_32 = NULL, *_35 = NULL, *_37 = NULL, *_42 = NULL, *_44 = NULL, *_48 = NULL, *_52 = NULL, *_56 = NULL, *_59 = NULL, *_62 = NULL, *_65 = NULL, *_69 = NULL, *_72 = NULL, *_75 = NULL, *_78 = NULL, *_83 = NULL, *_88 = NULL, *_95 = NULL, *_100 = NULL, *_104 = NULL, *_109 = NULL, *_114 = NULL, *_122 = NULL, *_126 = NULL, *_129 = NULL;
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
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_102$$10);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_40$$23);
	ZVAL_UNDEF(&_41$$23);
	ZVAL_UNDEF(&_46$$26);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_49$$26);
	ZVAL_UNDEF(&_50$$25);
	ZVAL_UNDEF(&_51$$25);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_58$$31);
	ZVAL_UNDEF(&_60$$30);
	ZVAL_UNDEF(&_61$$33);
	ZVAL_UNDEF(&_64$$33);
	ZVAL_UNDEF(&_66$$36);
	ZVAL_UNDEF(&_68$$36);
	ZVAL_UNDEF(&_70$$35);
	ZVAL_UNDEF(&_71$$38);
	ZVAL_UNDEF(&_74$$38);
	ZVAL_UNDEF(&_76$$41);
	ZVAL_UNDEF(&_77$$43);
	ZVAL_UNDEF(&_80$$43);
	ZVAL_UNDEF(&_81$$46);
	ZVAL_UNDEF(&_82$$46);
	ZVAL_UNDEF(&_85$$46);
	ZVAL_UNDEF(&_86$$45);
	ZVAL_UNDEF(&_87$$48);
	ZVAL_UNDEF(&_90$$48);
	ZVAL_UNDEF(&_91$$50);
	ZVAL_UNDEF(&_92$$50);
	ZVAL_UNDEF(&_93$$51);
	ZVAL_UNDEF(&_94$$51);
	ZVAL_UNDEF(&_96$$51);
	ZVAL_UNDEF(&_97$$54);
	ZVAL_UNDEF(&_98$$54);
	ZVAL_UNDEF(&_99$$57);
	ZVAL_UNDEF(&_101$$57);
	ZVAL_UNDEF(&_103$$59);
	ZVAL_UNDEF(&_106$$59);
	ZVAL_UNDEF(&_107$$62);
	ZVAL_UNDEF(&_108$$62);
	ZVAL_UNDEF(&_111$$62);
	ZVAL_UNDEF(&_112$$61);
	ZVAL_UNDEF(&_113$$64);
	ZVAL_UNDEF(&_116$$64);
	ZVAL_UNDEF(&_117$$67);
	ZVAL_UNDEF(&_119$$67);
	ZVAL_UNDEF(&_120$$66);
	ZVAL_UNDEF(&_121$$69);
	ZVAL_UNDEF(&_124$$69);
	ZVAL_UNDEF(&_125$$72);
	ZVAL_UNDEF(&_127$$71);
	ZVAL_UNDEF(&_128$$73);
	ZVAL_UNDEF(&_131$$73);
	ZVAL_UNDEF(&_132$$76);
	ZVAL_UNDEF(&_133$$75);
	ZVAL_UNDEF(&_134$$77);
	ZVAL_UNDEF(&_45$$10);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "related dispatching services");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, phalcon_dispatcher_exception_ce, "containerservicenotfound", &_2, 0, &_3$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_1$$3, &_4$$3);
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

			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "dispatch:beforeDispatchLoop");
			ZEPHIR_CALL_METHOD(&_5$$5, &eventsManager, "fire", NULL, 0, &_6$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			_7$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&_5$$5);
			if (_7$$5) {
				zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_7$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(&_8$$5);
			}
			if (_7$$5) {
				RETURN_MM_BOOL(0);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_9$$4);
			ZVAL_OBJ(&_9$$4, EG(exception));
			Z_ADDREF_P(&_9$$4);
			if (zephir_instance_of_ev(&_9$$4, zend_ce_exception)) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_9$$4);
				ZEPHIR_CALL_METHOD(&status, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				zephir_read_property(&_10$$7, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_10$$7)) {
					if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
						RETURN_MM_BOOL(0);
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 181);
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
			ZEPHIR_INIT_NVAR(&_11$$11);
			ZVAL_STRING(&_11$$11, "Dispatcher has detected a cyclic routing causing stability problems");
			ZVAL_LONG(&_12$$11, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", &_13, 0, &_11$$11, &_12$$11);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("finished"), &__$false);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolveemptyproperties", &_14, 0);
		zephir_check_call_status();
		if (hasEventsManager) {

			/* try_start_2: */

				ZEPHIR_INIT_NVAR(&_16$$13);
				ZVAL_STRING(&_16$$13, "dispatch:beforeDispatch");
				ZEPHIR_CALL_METHOD(&_15$$13, &eventsManager, "fire", &_17, 0, &_16$$13, this_ptr);
				zephir_check_call_status_or_jump(try_end_2);
				_18$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_15$$13);
				if (!(_18$$13)) {
					zephir_read_property(&_19$$13, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_18$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_19$$13);
				}
				if (_18$$13) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_20$$12);
				ZVAL_OBJ(&_20$$12, EG(exception));
				Z_ADDREF_P(&_20$$12);
				if (zephir_instance_of_ev(&_20$$12, zend_ce_exception)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_20$$12);
					ZEPHIR_CALL_METHOD(&_21$$15, this_ptr, "handleexception", &_22, 0, &e);
					zephir_check_call_status();
					_23$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_21$$15);
					if (!(_23$$15)) {
						zephir_read_property(&_24$$15, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_23$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_24$$15);
					}
					if (_23$$15) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 222);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_25, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_26$$10, &container, "has", &_27, 0, &handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(&_26$$10);
		if (!(hasService)) {
			hasService = zephir_class_exists(&handlerClass, 1);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_NVAR(&_28$$18);
			ZEPHIR_CONCAT_VS(&_28$$18, &handlerClass, " handler class cannot be loaded");
			ZVAL_LONG(&_29$$18, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_30, 0, &_28$$18, &_29$$18);
			zephir_check_call_status();
			_31$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_31$$18) {
				zephir_read_property(&_29$$18, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_31$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&_29$$18);
			}
			if (_31$$18) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, &container, "getshared", &_32, 0, &handlerClass);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&handler) != IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(&_33$$20);
			ZVAL_STRING(&_33$$20, "Invalid handler returned from the services container");
			ZVAL_LONG(&_34$$20, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_35, 0, &_33$$20, &_34$$20);
			zephir_check_call_status();
			_36$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_36$$20) {
				zephir_read_property(&_34$$20, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_36$$20 = ZEPHIR_IS_FALSE_IDENTICAL(&_34$$20);
			}
			if (_36$$20) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_FUNCTION(&handlerHash, "spl_object_hash", &_37, 100, &handler);
		zephir_check_call_status();
		zephir_read_property(&_38$$10, this_ptr, ZEND_STRL("handlerHashes"), PH_NOISY_CC | PH_READONLY);
		isNewHandler = !((zephir_array_isset(&_38$$10, &handlerHash)));
		if (isNewHandler) {
			zephir_update_property_array(this_ptr, SL("handlerHashes"), &handlerHash, &__$true);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeHandler"), &handler);
		zephir_read_property(&_39$$10, this_ptr, ZEND_STRL("namespaceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&namespaceName, &_39$$10);
		zephir_read_property(&_39$$10, this_ptr, ZEND_STRL("handlerName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&handlerName, &_39$$10);
		zephir_read_property(&_39$$10, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&actionName, &_39$$10);
		zephir_read_property(&_39$$10, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&params, &_39$$10);
		if (UNEXPECTED(Z_TYPE_P(&params) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&_40$$23);
			ZVAL_STRING(&_40$$23, "Action parameters must be an Array");
			ZVAL_LONG(&_41$$23, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_42, 0, &_40$$23, &_41$$23);
			zephir_check_call_status();
			_43$$23 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_43$$23) {
				zephir_read_property(&_41$$23, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_43$$23 = ZEPHIR_IS_FALSE_IDENTICAL(&_41$$23);
			}
			if (_43$$23) {
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
				ZEPHIR_INIT_NVAR(&_47$$26);
				ZVAL_STRING(&_47$$26, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD(&_46$$26, &eventsManager, "fire", &_48, 0, &_47$$26, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_46$$26)) {
					continue;
				}
				zephir_read_property(&_49$$26, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_49$$26)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_50$$25);
			ZEPHIR_CONCAT_SVSVS(&_50$$25, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_51$$25, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "throwdispatchexception", &_52, 0, &_50$$25, &_51$$25);
			zephir_check_call_status();
			_53$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_53$$25) {
				zephir_read_property(&_51$$25, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
				_53$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&_51$$25);
			}
			if (_53$$25) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_55$$31);
				ZVAL_STRING(&_55$$31, "dispatch:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_54$$31, &eventsManager, "fire", &_56, 0, &_55$$31, this_ptr);
				zephir_check_call_status_or_jump(try_end_3);
				_57$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_54$$31);
				if (!(_57$$31)) {
					zephir_read_property(&_58$$31, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_57$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_58$$31);
				}
				if (_57$$31) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_59, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_60$$30);
				ZVAL_OBJ(&_60$$30, EG(exception));
				Z_ADDREF_P(&_60$$30);
				if (zephir_instance_of_ev(&_60$$30, zend_ce_exception)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_60$$30);
					ZEPHIR_CALL_METHOD(&_61$$33, this_ptr, "handleexception", &_62, 0, &e);
					zephir_check_call_status();
					_63$$33 = ZEPHIR_IS_FALSE_IDENTICAL(&_61$$33);
					if (!(_63$$33)) {
						zephir_read_property(&_64$$33, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_63$$33 = ZEPHIR_IS_FALSE_IDENTICAL(&_64$$33);
					}
					if (_63$$33) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_65, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 363);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("beforeexecuteroute")) == SUCCESS)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_66$$36, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_67$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_66$$36);
				if (!(_67$$36)) {
					zephir_read_property(&_68$$36, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_67$$36 = ZEPHIR_IS_FALSE_IDENTICAL(&_68$$36);
				}
				if (_67$$36) {
					ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_69, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_70$$35);
				ZVAL_OBJ(&_70$$35, EG(exception));
				Z_ADDREF_P(&_70$$35);
				if (zephir_instance_of_ev(&_70$$35, zend_ce_exception)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_70$$35);
					ZEPHIR_CALL_METHOD(&_71$$38, this_ptr, "handleexception", &_72, 0, &e);
					zephir_check_call_status();
					_73$$38 = ZEPHIR_IS_FALSE_IDENTICAL(&_71$$38);
					if (!(_73$$38)) {
						zephir_read_property(&_74$$38, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_73$$38 = ZEPHIR_IS_FALSE_IDENTICAL(&_74$$38);
					}
					if (_73$$38) {
						ZEPHIR_CALL_METHOD(NULL, &container, "remove", &_75, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 382);
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
					ZEPHIR_INIT_NVAR(&_76$$41);
					ZVAL_OBJ(&_76$$41, EG(exception));
					Z_ADDREF_P(&_76$$41);
					if (zephir_instance_of_ev(&_76$$41, zend_ce_exception)) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_76$$41);
						if (0) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$true);
						} else {
							zephir_update_property_zval(this_ptr, ZEND_STRL("isControllerInitialize"), &__$false);
						}
						ZEPHIR_CALL_METHOD(&_77$$43, this_ptr, "handleexception", &_78, 0, &e);
						zephir_check_call_status();
						_79$$43 = ZEPHIR_IS_FALSE_IDENTICAL(&_77$$43);
						if (!(_79$$43)) {
							zephir_read_property(&_80$$43, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
							_79$$43 = ZEPHIR_IS_FALSE_IDENTICAL(&_80$$43);
						}
						if (_79$$43) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 424);
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

					ZEPHIR_INIT_NVAR(&_82$$46);
					ZVAL_STRING(&_82$$46, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD(&_81$$46, &eventsManager, "fire", &_83, 0, &_82$$46, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_84$$46 = ZEPHIR_IS_FALSE_IDENTICAL(&_81$$46);
					if (!(_84$$46)) {
						zephir_read_property(&_85$$46, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_84$$46 = ZEPHIR_IS_FALSE_IDENTICAL(&_85$$46);
					}
					if (_84$$46) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_86$$45);
					ZVAL_OBJ(&_86$$45, EG(exception));
					Z_ADDREF_P(&_86$$45);
					if (zephir_instance_of_ev(&_86$$45, zend_ce_exception)) {
						zend_clear_exception();
						ZEPHIR_CPY_WRT(&e, &_86$$45);
						ZEPHIR_CALL_METHOD(&_87$$48, this_ptr, "handleexception", &_88, 0, &e);
						zephir_check_call_status();
						_89$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_87$$48);
						if (!(_89$$48)) {
							zephir_read_property(&_90$$48, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
							_89$$48 = ZEPHIR_IS_FALSE_IDENTICAL(&_90$$48);
						}
						if (_89$$48) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 443);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property(&_39$$10, this_ptr, ZEND_STRL("modelBinding"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_39$$10)) {
			zephir_read_property(&_91$$50, this_ptr, ZEND_STRL("modelBinder"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_91$$50);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			ZEPHIR_CALL_METHOD(&_92$$50, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&params, &_92$$50);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_94$$51);
			ZVAL_STRING(&_94$$51, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD(&_93$$51, &eventsManager, "fire", &_95, 0, &_94$$51, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_93$$51)) {
				continue;
			}
			zephir_read_property(&_96$$51, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_96$$51)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("afterbinding")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_97$$54, &handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_97$$54)) {
				continue;
			}
			zephir_read_property(&_98$$54, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_98$$54)) {
				continue;
			}
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("lastHandler"), &handler);

		/* try_start_7: */

			ZEPHIR_CALL_METHOD(&_99$$57, this_ptr, "callactionmethod", &_100, 0, &handler, &actionMethod, &params);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval(this_ptr, ZEND_STRL("returnedValue"), &_99$$57);
			zephir_read_property(&_101$$57, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_101$$57)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_102$$10);
			ZVAL_OBJ(&_102$$10, EG(exception));
			Z_ADDREF_P(&_102$$10);
			if (zephir_instance_of_ev(&_102$$10, zend_ce_exception)) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_102$$10);
				ZEPHIR_CALL_METHOD(&_103$$59, this_ptr, "handleexception", &_104, 0, &e);
				zephir_check_call_status();
				_105$$59 = ZEPHIR_IS_FALSE_IDENTICAL(&_103$$59);
				if (!(_105$$59)) {
					zephir_read_property(&_106$$59, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_105$$59 = ZEPHIR_IS_FALSE_IDENTICAL(&_106$$59);
				}
				if (_105$$59) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 515);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_108$$62);
				ZVAL_STRING(&_108$$62, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(&_107$$62, &eventsManager, "fire", &_109, 0, &_108$$62, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_110$$62 = ZEPHIR_IS_FALSE_IDENTICAL(&_107$$62);
				if (!(_110$$62)) {
					zephir_read_property(&_111$$62, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_110$$62 = ZEPHIR_IS_FALSE_IDENTICAL(&_111$$62);
				}
				if (_110$$62) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_112$$61);
				ZVAL_OBJ(&_112$$61, EG(exception));
				Z_ADDREF_P(&_112$$61);
				if (zephir_instance_of_ev(&_112$$61, zend_ce_exception)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_112$$61);
					ZEPHIR_CALL_METHOD(&_113$$64, this_ptr, "handleexception", &_114, 0, &e);
					zephir_check_call_status();
					_115$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_113$$64);
					if (!(_115$$64)) {
						zephir_read_property(&_116$$64, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_115$$64 = ZEPHIR_IS_FALSE_IDENTICAL(&_116$$64);
					}
					if (_115$$64) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 531);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("afterexecuteroute")) == SUCCESS)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_117$$67, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_118$$67 = ZEPHIR_IS_FALSE_IDENTICAL(&_117$$67);
				if (!(_118$$67)) {
					zephir_read_property(&_119$$67, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
					_118$$67 = ZEPHIR_IS_FALSE_IDENTICAL(&_119$$67);
				}
				if (_118$$67) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_120$$66);
				ZVAL_OBJ(&_120$$66, EG(exception));
				Z_ADDREF_P(&_120$$66);
				if (zephir_instance_of_ev(&_120$$66, zend_ce_exception)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_120$$66);
					ZEPHIR_CALL_METHOD(&_121$$69, this_ptr, "handleexception", &_122, 0, &e);
					zephir_check_call_status();
					_123$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_121$$69);
					if (!(_123$$69)) {
						zephir_read_property(&_124$$69, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_123$$69 = ZEPHIR_IS_FALSE_IDENTICAL(&_124$$69);
					}
					if (_123$$69) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 548);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_125$$72);
				ZVAL_STRING(&_125$$72, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_126, 0, &_125$$72, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_127$$71);
				ZVAL_OBJ(&_127$$71, EG(exception));
				Z_ADDREF_P(&_127$$71);
				if (zephir_instance_of_ev(&_127$$71, zend_ce_exception)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&e, &_127$$71);
					ZEPHIR_CALL_METHOD(&_128$$73, this_ptr, "handleexception", &_129, 0, &e);
					zephir_check_call_status();
					_130$$73 = ZEPHIR_IS_FALSE_IDENTICAL(&_128$$73);
					if (!(_130$$73)) {
						zephir_read_property(&_131$$73, this_ptr, ZEND_STRL("finished"), PH_NOISY_CC | PH_READONLY);
						_130$$73 = ZEPHIR_IS_FALSE_IDENTICAL(&_131$$73);
					}
					if (_130$$73) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 565);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_132$$76);
			ZVAL_STRING(&_132$$76, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_132$$76, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_133$$75);
			ZVAL_OBJ(&_133$$75, EG(exception));
			Z_ADDREF_P(&_133$$75);
			if (zephir_instance_of_ev(&_133$$75, zend_ce_exception)) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_133$$75);
				ZEPHIR_CALL_METHOD(&_134$$77, this_ptr, "handleexception", NULL, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_134$$77)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/Dispatcher/AbstractDispatcher.zep", 582);
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
 * @throws \Phalcon\Exception
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_dispatcher_exception_ce, "Forwarding inside a controller's initialize() method is forbidden", "phalcon/Dispatcher/AbstractDispatcher.zep", 616);
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
		ZEPHIR_CALL_FUNCTION(&activeMethodName, "lcfirst", NULL, 96, &_2$$3);
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
	zephir_fcall_cache_entry *_2 = NULL;
	zval *param, param_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null, params, filter, paramValue, container, _0, _5, _6, _1$$5, _3$$5, _4$$5;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		Z_PARAM_ZVAL(defaultValue)
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
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "the 'filter' service");
		ZEPHIR_CALL_CE_STATIC(&_1$$5, phalcon_dispatcher_exception_ce, "containerservicenotfound", &_2, 0, &_3$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdispatchexception", NULL, 0, &_1$$5, &_4$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "filter");
	ZEPHIR_CALL_METHOD(&_5, &container, "getshared", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filter, &_5);
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultNamespace"), &namespaceName);
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
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/Dispatcher/AbstractDispatcher.zep", 867))) {
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
		Z_PARAM_ZVAL(cache)
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
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_split", NULL, 101, &_1$$3, &input);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ucfirst");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_map", NULL, 102, &_1$$3, &_2$$3);
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

