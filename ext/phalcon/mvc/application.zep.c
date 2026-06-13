
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
#include "kernel/file.h"
#include "kernel/require.h"


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
	zval _21$$20;
	zend_class_entry *_7$$7;
	zend_bool returnedResponse = 0, _2, _11$$6, _14$$11, _34$$30, _36$$30;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$false, container, eventsManager, router, dispatcher, response, view, module, moduleObject, moduleName, className, path, implicitView, controller, possibleResponse, renderStatus, matchedRoute, match, _0, _3, _4, _5, _25, _26, _27, _44, _1$$3, _6$$7, _8$$6, _9$$8, _10$$8, _12$$12, _13$$12, _15$$14, _16$$14, _17$$18, _18$$15, _19$$21, _20$$21, _22$$22, _23$$23, _24$$23, _28$$25, _29$$25, _30$$27, _31$$27, _32$$29, _33$$29, _35$$31, _37$$34, _38$$35, _39$$35, _40$$38, _41$$38, _42$$39, _43$$40;
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
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_22$$22);
	ZVAL_UNDEF(&_23$$23);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&_28$$25);
	ZVAL_UNDEF(&_29$$25);
	ZVAL_UNDEF(&_30$$27);
	ZVAL_UNDEF(&_31$$27);
	ZVAL_UNDEF(&_32$$29);
	ZVAL_UNDEF(&_33$$29);
	ZVAL_UNDEF(&_35$$31);
	ZVAL_UNDEF(&_37$$34);
	ZVAL_UNDEF(&_38$$35);
	ZVAL_UNDEF(&_39$$35);
	ZVAL_UNDEF(&_40$$38);
	ZVAL_UNDEF(&_41$$38);
	ZVAL_UNDEF(&_42$$39);
	ZVAL_UNDEF(&_43$$40);
	ZVAL_UNDEF(&_21$$20);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_application_exceptions_containerrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Application.zep", 101);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
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
		zephir_read_property(&moduleName, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC);
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
			zephir_throw_exception_debug(&_15$$14, "phalcon/Mvc/Application.zep", 200);
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
				if (UNEXPECTED(!((zephir_file_exists(&path) == SUCCESS)))) {
					ZEPHIR_INIT_VAR(&_17$$18);
					object_init_ex(&_17$$18, phalcon_mvc_application_exceptions_moduledefinitionpathnotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_17$$18, "__construct", NULL, 0, &path);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_17$$18, "phalcon/Mvc/Application.zep", 220);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(zephir_class_exists(&className, zephir_is_true(&__$false) ))) {
					if (zephir_require_once_zval(&path) == FAILURE) {
						RETURN_MM_NULL();
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_18$$15, &container, "get", NULL, 0, &className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&moduleObject, &_18$$15);
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerautoloaders", NULL, 0, &container);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerservices", NULL, 0, &container);
			zephir_check_call_status();
		} else {
			if (UNEXPECTED(!((zephir_is_instance_of(&module, SL("Closure")))))) {
				ZEPHIR_INIT_VAR(&_19$$21);
				object_init_ex(&_19$$21, phalcon_mvc_application_exceptions_invalidmoduledefinition_ce);
				ZEPHIR_INIT_VAR(&_20$$21);
				ZVAL_STRING(&_20$$21, "The module definition object must be a Closure");
				ZEPHIR_CALL_METHOD(NULL, &_19$$21, "__construct", NULL, 0, &moduleName, &_20$$21);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$21, "phalcon/Mvc/Application.zep", 244);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_21$$20);
			zephir_create_array(&_21$$20, 1, 0);
			zephir_array_fast_append(&_21$$20, &container);
			ZEPHIR_INIT_NVAR(&moduleObject);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&moduleObject, &module, &_21$$20);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_22$$22);
			ZVAL_STRING(&_22$$22, "application:afterStartModule");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_22$$22, this_ptr, &moduleObject);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("implicitView"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&implicitView, &_0);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
		ZEPHIR_INIT_VAR(&_24$$23);
		ZVAL_STRING(&_24$$23, "view");
		ZEPHIR_CALL_METHOD(&_23$$23, &container, "getshared", NULL, 0, &_24$$23);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&view, &_23$$23);
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
	ZEPHIR_CALL_METHOD(&_25, &router, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setcontrollername", NULL, 0, &_25);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_26, &router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setactionname", NULL, 0, &_26);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_27, &router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_27);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
		ZEPHIR_CALL_METHOD(NULL, &view, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_29$$25);
		ZVAL_STRING(&_29$$25, "application:beforeHandleRequest");
		ZEPHIR_CALL_METHOD(&_28$$25, &eventsManager, "fire", NULL, 0, &_29$$25, this_ptr, &dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_28$$25)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&controller, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&possibleResponse, &dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&possibleResponse)) {
		ZEPHIR_INIT_VAR(&_31$$27);
		ZVAL_STRING(&_31$$27, "response");
		ZEPHIR_CALL_METHOD(&_30$$27, &container, "getshared", NULL, 0, &_31$$27);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&response, &_30$$27);
	} else {
		if (Z_TYPE_P(&possibleResponse) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_33$$29);
			ZVAL_STRING(&_33$$29, "response");
			ZEPHIR_CALL_METHOD(&_32$$29, &container, "getshared", NULL, 0, &_33$$29);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_32$$29);
			ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &possibleResponse);
			zephir_check_call_status();
		} else {
			_34$$30 = (Z_TYPE_P(&possibleResponse) == IS_OBJECT);
			if (_34$$30) {
				_34$$30 = (zephir_instance_of_ev(&possibleResponse, phalcon_http_responseinterface_ce));
			}
			returnedResponse = _34$$30;
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_35$$31);
				ZVAL_STRING(&_35$$31, "application:afterHandleRequest");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_35$$31, this_ptr, &controller);
				zephir_check_call_status();
			}
			_36$$30 = returnedResponse == 0;
			if (_36$$30) {
				_36$$30 = ZEPHIR_IS_TRUE_IDENTICAL(&implicitView);
			}
			if (_36$$30) {
				if (Z_TYPE_P(&controller) == IS_OBJECT) {
					ZEPHIR_INIT_VAR(&renderStatus);
					ZVAL_BOOL(&renderStatus, 1);
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_VAR(&_37$$34);
						ZVAL_STRING(&_37$$34, "application:viewRender");
						ZEPHIR_CALL_METHOD(&renderStatus, &eventsManager, "fire", NULL, 0, &_37$$34, this_ptr, &view);
						zephir_check_call_status();
					}
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&renderStatus)) {
						ZEPHIR_CALL_METHOD(&_38$$35, &dispatcher, "getcontrollername", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_39$$35, &dispatcher, "getactionname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &view, "render", NULL, 0, &_38$$35, &_39$$35);
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
				ZEPHIR_INIT_VAR(&_41$$38);
				ZVAL_STRING(&_41$$38, "response");
				ZEPHIR_CALL_METHOD(&_40$$38, &container, "getshared", NULL, 0, &_41$$38);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&response, &_40$$38);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
					ZEPHIR_CALL_METHOD(&_42$$39, &view, "getcontent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &_42$$39);
					zephir_check_call_status();
				}
			}
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_43$$40);
		ZVAL_STRING(&_43$$40, "application:beforeSendResponse");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_43$$40, this_ptr, &response);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sendHeaders"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &response, "sendheaders", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_44, this_ptr, ZEND_STRL("sendCookies"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_44)) {
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(sendCookies)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &sendCookies_param);
	if (sendCookies) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sendCookies"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sendCookies"), &__$false);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(sendHeaders)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &sendHeaders_param);
	if (sendHeaders) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sendHeaders"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sendHeaders"), &__$false);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(implicitView)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &implicitView_param);
	if (implicitView) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("implicitView"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("implicitView"), &__$false);
	}
	RETURN_THISW();
}

