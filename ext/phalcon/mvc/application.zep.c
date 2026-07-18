
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Application
 *
 * This component encapsulates all the complex operations behind instantiating
 * every component needed and integrating it with the rest to allow the MVC
 * pattern to operate as desired.
 *
 *```php
 * use Phalcon\Mvc\Application;
 *
 * class MyApp extends Application
 * {
 *     /**
 *      * Register the services here to make them general or register
 *      * in the ModuleDefinition to make them module-specific
 *      *\/
 *     protected function registerServices()
 *     {
 *
 *     }
 *
 *     /**
 *      * This method registers all the modules in the application
 *      *\/
 *     public function main()
 *     {
 *         $this->registerModules(
 *             [
 *                 "frontend" => [
 *                     "className" => "Multiple\\Frontend\\Module",
 *                     "path"      => "../apps/frontend/Module.php",
 *                 ],
 *                 "backend" => [
 *                     "className" => "Multiple\\Backend\\Module",
 *                     "path"      => "../apps/backend/Module.php",
 *                 ],
 *             ]
 *         );
 *     }
 * }
 *
 * $application = new MyApp();
 *
 * $application->main();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Application, phalcon, mvc_application, phalcon_application_abstractapplication_ce, phalcon_mvc_application_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_application_ce, SL("implicitView"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_application_ce, SL("sendCookies"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_application_ce, SL("sendHeaders"), 1, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Handles a MVC request
 */
PHP_METHOD(Phalcon_Mvc_Application, handle)
{
	zval _22$$20;
	zend_class_entry *_7$$7;
	zend_bool returnedResponse = 0, _2, _11$$6, _14$$11, _35$$30, _37$$30;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$false, container, eventsManager, router, dispatcher, response, view, module, moduleObject, moduleName, className, path, implicitView, controller, possibleResponse, renderStatus, matchedRoute, match, _0, _3, _4, _5, _26, _27, _28, _45, _1$$3, _6$$7, _8$$6, _9$$8, _10$$8, _12$$12, _13$$12, _15$$14, _16$$14, _17$$17, _18$$18, _19$$15, _20$$21, _21$$21, _23$$22, _24$$23, _25$$23, _29$$25, _30$$25, _31$$27, _32$$27, _33$$29, _34$$29, _36$$31, _38$$34, _39$$35, _40$$35, _41$$38, _42$$38, _43$$39, _44$$40;
	zend_string *uri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&moduleObject);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&implicitView);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&possibleResponse);
	ZVAL_UNDEF(&renderStatus);
	ZVAL_UNDEF(&matchedRoute);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&_23$$22);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_29$$25);
	ZVAL_UNDEF(&_30$$25);
	ZVAL_UNDEF(&_31$$27);
	ZVAL_UNDEF(&_32$$27);
	ZVAL_UNDEF(&_33$$29);
	ZVAL_UNDEF(&_34$$29);
	ZVAL_UNDEF(&_36$$31);
	ZVAL_UNDEF(&_38$$34);
	ZVAL_UNDEF(&_39$$35);
	ZVAL_UNDEF(&_40$$35);
	ZVAL_UNDEF(&_41$$38);
	ZVAL_UNDEF(&_42$$38);
	ZVAL_UNDEF(&_43$$39);
	ZVAL_UNDEF(&_44$$40);
	ZVAL_UNDEF(&_22$$20);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("implicitView", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("sendHeaders", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("sendCookies", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 933, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_application_exceptions_containerrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Application.zep", 104);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 934, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	_2 = Z_TYPE_P(&eventsManager) != IS_NULL;
	if (_2) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "application:boot");
		ZEPHIR_CALL_METHOD(&_3, &eventsManager, "fire", NULL, 0, &_4, this_ptr);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_FALSE_IDENTICAL(&_3);
	}
	if (_2) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "router");
	ZEPHIR_CALL_METHOD(&_5, &container, "getshared", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&router, &_5);
	ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getmatchedroute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&matchedRoute) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&match, &matchedRoute, "getmatch", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&match) != IS_NULL) {
			if (zephir_is_instance_of(&match, SL("Closure"))) {
				_7$$7 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_6$$7, _7$$7, "bind", NULL, 0, &match, &container);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&match, &_6$$7);
			}
			ZEPHIR_CALL_METHOD(&_8$$6, &router, "getparams", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&possibleResponse);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&possibleResponse, &match, &_8$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(&possibleResponse) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_10$$8);
				ZVAL_STRING(&_10$$8, "response");
				ZEPHIR_CALL_METHOD(&_9$$8, &container, "getshared", NULL, 0, &_10$$8);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&response, &_9$$8);
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &possibleResponse);
				zephir_check_call_status();
				RETURN_CCTOR(&response);
			}
			_11$$6 = Z_TYPE_P(&possibleResponse) == IS_OBJECT;
			if (_11$$6) {
				_11$$6 = zephir_instance_of_ev(&possibleResponse, phalcon_http_responseinterface_ce);
			}
			if (_11$$6) {
				ZEPHIR_CALL_METHOD(NULL, &possibleResponse, "sendheaders", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &possibleResponse, "sendcookies", NULL, 0);
				zephir_check_call_status();
				RETURN_CCTOR(&possibleResponse);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&moduleName, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&moduleName))) {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property_cached(&moduleName, this_ptr, _zephir_prop_2, 935, PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&moduleObject);
	ZVAL_NULL(&moduleObject);
	if (zephir_is_true(&moduleName)) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_13$$12);
			ZVAL_STRING(&_13$$12, "application:beforeStartModule");
			ZEPHIR_CALL_METHOD(&_12$$12, &eventsManager, "fire", NULL, 0, &_13$$12, this_ptr, &moduleName);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_12$$12)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&module, this_ptr, "getmodule", NULL, 0, &moduleName);
		zephir_check_call_status();
		_14$$11 = Z_TYPE_P(&module) != IS_ARRAY;
		if (_14$$11) {
			_14$$11 = Z_TYPE_P(&module) != IS_OBJECT;
		}
		if (UNEXPECTED(_14$$11)) {
			ZEPHIR_INIT_VAR(&_15$$14);
			object_init_ex(&_15$$14, phalcon_mvc_application_exceptions_invalidmoduledefinition_ce);
			ZEPHIR_INIT_VAR(&_16$$14);
			ZVAL_STRING(&_16$$14, "The module definition must be an array or an object");
			ZEPHIR_CALL_METHOD(NULL, &_15$$14, "__construct", NULL, 0, &moduleName, &_16$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_15$$14, "phalcon/Mvc/Application.zep", 203);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&module) == IS_ARRAY) {
			zephir_memory_observe(&className);
			if (!(zephir_array_isset_string_fetch(&className, &module, SL("className"), 0))) {
				ZEPHIR_INIT_NVAR(&className);
				ZVAL_STRING(&className, "Module");
			}
			zephir_memory_observe(&path);
			if (zephir_array_isset_string_fetch(&path, &module, SL("path"), 0)) {
				ZEPHIR_CALL_METHOD(&_17$$17, this_ptr, "phpfileexists", NULL, 0, &path);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_17$$17))) {
					ZEPHIR_INIT_VAR(&_18$$18);
					object_init_ex(&_18$$18, phalcon_mvc_application_exceptions_moduledefinitionpathnotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_18$$18, "__construct", NULL, 0, &path);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_18$$18, "phalcon/Mvc/Application.zep", 223);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(zephir_class_exists(&className, zephir_is_true(&__$false) ))) {
					if (zephir_require_once_zval(&path) == FAILURE) {
						RETURN_MM_NULL();
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_19$$15, &container, "get", NULL, 0, &className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&moduleObject, &_19$$15);
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerautoloaders", NULL, 0, &container);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerservices", NULL, 0, &container);
			zephir_check_call_status();
		} else {
			if (UNEXPECTED(!((zephir_is_instance_of(&module, SL("Closure")))))) {
				ZEPHIR_INIT_VAR(&_20$$21);
				object_init_ex(&_20$$21, phalcon_mvc_application_exceptions_invalidmoduledefinition_ce);
				ZEPHIR_INIT_VAR(&_21$$21);
				ZVAL_STRING(&_21$$21, "The module definition object must be a Closure");
				ZEPHIR_CALL_METHOD(NULL, &_20$$21, "__construct", NULL, 0, &moduleName, &_21$$21);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_20$$21, "phalcon/Mvc/Application.zep", 247);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_22$$20);
			zephir_create_array(&_22$$20, 1, 0);
			zephir_array_fast_append(&_22$$20, &container);
			ZEPHIR_INIT_NVAR(&moduleObject);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&moduleObject, &module, &_22$$20);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_23$$22);
			ZVAL_STRING(&_23$$22, "application:afterStartModule");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_23$$22, this_ptr, &moduleObject);
			zephir_check_call_status();
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 936, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&implicitView, &_0);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
		ZEPHIR_INIT_VAR(&_25$$23);
		ZVAL_STRING(&_25$$23, "view");
		ZEPHIR_CALL_METHOD(&_24$$23, &container, "getshared", NULL, 0, &_25$$23);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&view, &_24$$23);
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "dispatcher");
	ZEPHIR_CALL_METHOD(&_5, &container, "getshared", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dispatcher, &_5);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodulename", NULL, 0, &moduleName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &router, "getnamespacename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setnamespacename", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_26, &router, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setcontrollername", NULL, 0, &_26);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_27, &router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setactionname", NULL, 0, &_27);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_28, &router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_28);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
		ZEPHIR_CALL_METHOD(NULL, &view, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_30$$25);
		ZVAL_STRING(&_30$$25, "application:beforeHandleRequest");
		ZEPHIR_CALL_METHOD(&_29$$25, &eventsManager, "fire", NULL, 0, &_30$$25, this_ptr, &dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_29$$25)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&controller, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&possibleResponse, &dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&possibleResponse)) {
		ZEPHIR_INIT_VAR(&_32$$27);
		ZVAL_STRING(&_32$$27, "response");
		ZEPHIR_CALL_METHOD(&_31$$27, &container, "getshared", NULL, 0, &_32$$27);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&response, &_31$$27);
	} else {
		if (Z_TYPE_P(&possibleResponse) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_34$$29);
			ZVAL_STRING(&_34$$29, "response");
			ZEPHIR_CALL_METHOD(&_33$$29, &container, "getshared", NULL, 0, &_34$$29);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_33$$29);
			ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &possibleResponse);
			zephir_check_call_status();
		} else {
			_35$$30 = (Z_TYPE_P(&possibleResponse) == IS_OBJECT);
			if (_35$$30) {
				_35$$30 = (zephir_instance_of_ev(&possibleResponse, phalcon_http_responseinterface_ce));
			}
			returnedResponse = _35$$30;
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_36$$31);
				ZVAL_STRING(&_36$$31, "application:afterHandleRequest");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_36$$31, this_ptr, &controller);
				zephir_check_call_status();
			}
			_37$$30 = returnedResponse == 0;
			if (_37$$30) {
				_37$$30 = ZEPHIR_IS_TRUE_IDENTICAL(&implicitView);
			}
			if (_37$$30) {
				if (Z_TYPE_P(&controller) == IS_OBJECT) {
					ZEPHIR_INIT_VAR(&renderStatus);
					ZVAL_BOOL(&renderStatus, 1);
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_VAR(&_38$$34);
						ZVAL_STRING(&_38$$34, "application:viewRender");
						ZEPHIR_CALL_METHOD(&renderStatus, &eventsManager, "fire", NULL, 0, &_38$$34, this_ptr, &view);
						zephir_check_call_status();
					}
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&renderStatus)) {
						ZEPHIR_CALL_METHOD(&_39$$35, &dispatcher, "getcontrollername", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_40$$35, &dispatcher, "getactionname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &view, "render", NULL, 0, &_39$$35, &_40$$35);
						zephir_check_call_status();
					}
				}
			}
			if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
				ZEPHIR_CALL_METHOD(NULL, &view, "finish", NULL, 0);
				zephir_check_call_status();
			}
			if (returnedResponse == 1) {
				ZEPHIR_CPY_WRT(&response, &possibleResponse);
			} else {
				ZEPHIR_INIT_VAR(&_42$$38);
				ZVAL_STRING(&_42$$38, "response");
				ZEPHIR_CALL_METHOD(&_41$$38, &container, "getshared", NULL, 0, &_42$$38);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&response, &_41$$38);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
					ZEPHIR_CALL_METHOD(&_43$$39, &view, "getcontent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &_43$$39);
					zephir_check_call_status();
				}
			}
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_44$$40);
		ZVAL_STRING(&_44$$40, "application:beforeSendResponse");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_44$$40, this_ptr, &response);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 937, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &response, "sendheaders", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_45, this_ptr, _zephir_prop_5, 938, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_45)) {
		ZEPHIR_CALL_METHOD(NULL, &response, "sendcookies", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&response);
}

/**
 * Enables or disables sending cookies by each request handling
 */
PHP_METHOD(Phalcon_Mvc_Application, sendCookiesOnHandleRequest)
{
	zval *sendCookies_param = NULL, __$true, __$false;
	zend_bool sendCookies;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("sendCookies", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(sendCookies)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &sendCookies_param);
	if (sendCookies) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 938, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 938, &__$false);
	}
	RETURN_THISW();
}

/**
 * Enables or disables sending headers by each request handling
 */
PHP_METHOD(Phalcon_Mvc_Application, sendHeadersOnHandleRequest)
{
	zval *sendHeaders_param = NULL, __$true, __$false;
	zend_bool sendHeaders;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("sendHeaders", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(sendHeaders)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &sendHeaders_param);
	if (sendHeaders) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 937, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 937, &__$false);
	}
	RETURN_THISW();
}

/**
 * By default. The view is implicitly buffering all the output
 * You can full disable the view component using this method
 */
PHP_METHOD(Phalcon_Mvc_Application, useImplicitView)
{
	zval *implicitView_param = NULL, __$true, __$false;
	zend_bool implicitView;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("implicitView", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(implicitView)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &implicitView_param);
	if (implicitView) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 936, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 936, &__$false);
	}
	RETURN_THISW();
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Application, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Mvc_Application, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 159, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Mvc_Application, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Mvc_Application, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _2, _3, _4;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_2, context, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Mvc_Application, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 161, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Mvc_Application, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 162, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Mvc_Application, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 163, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Mvc_Application, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 164, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Mvc_Application, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 165, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

