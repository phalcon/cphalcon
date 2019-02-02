
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Application
 *
 * This component encapsulates all the complex operations behind instantiating every component
 * needed and integrating it with the rest to allow the MVC pattern to operate as desired.
 *
 *<code>
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
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Application, phalcon, mvc_application, phalcon_application_ce, phalcon_mvc_application_method_entry, 0);

	zend_declare_property_bool(phalcon_mvc_application_ce, SL("_implicitView"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_application_ce, SL("_sendHeaders"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_application_ce, SL("_sendCookies"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Enables or disables sending headers by each request handling
 */
PHP_METHOD(Phalcon_Mvc_Application, sendHeadersOnHandleRequest) {

	zval *sendHeaders_param = NULL, __$true, __$false;
	zend_bool sendHeaders;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &sendHeaders_param);

	sendHeaders = zephir_get_boolval(sendHeaders_param);


	if (sendHeaders) {
		zephir_update_property_zval(this_ptr, SL("_sendHeaders"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_sendHeaders"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Enables or disables sending cookies by each request handling
 */
PHP_METHOD(Phalcon_Mvc_Application, sendCookiesOnHandleRequest) {

	zval *sendCookies_param = NULL, __$true, __$false;
	zend_bool sendCookies;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &sendCookies_param);

	sendCookies = zephir_get_boolval(sendCookies_param);


	if (sendCookies) {
		zephir_update_property_zval(this_ptr, SL("_sendCookies"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_sendCookies"), &__$false);
	}
	RETURN_THISW();

}

/**
 * By default. The view is implicitly buffering all the output
 * You can full disable the view component using this method
 */
PHP_METHOD(Phalcon_Mvc_Application, useImplicitView) {

	zval *implicitView_param = NULL, __$true, __$false;
	zend_bool implicitView;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &implicitView_param);

	implicitView = zephir_get_boolval(implicitView_param);


	if (implicitView) {
		zephir_update_property_zval(this_ptr, SL("_implicitView"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_implicitView"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Handles a MVC request
 */
PHP_METHOD(Phalcon_Mvc_Application, handle) {

	zval _16$$22;
	zend_class_entry *_6$$8;
	zend_bool returnedResponse = 0, _26, _12$$13, _31$$32, _33$$32;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$false, dependencyInjector, eventsManager, router, dispatcher, response, view, module, moduleObject, moduleName, className, path, implicitView, controller, possibleResponse, renderStatus, matchedRoute, match, _0, _3, _4, _20, _21, _22, _23, _41, _1$$4, _2$$4, _5$$8, _7$$7, _8$$9, _9$$9, _10$$14, _11$$14, _13$$21, _14$$21, _15$$17, _17$$24, _18$$25, _19$$25, _24$$27, _25$$27, _27$$29, _28$$29, _29$$31, _30$$31, _32$$33, _34$$36, _35$$37, _36$$37, _37$$40, _38$$40, _39$$41, _40$$42;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&dependencyInjector);
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
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_13$$21);
	ZVAL_UNDEF(&_14$$21);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_18$$25);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_24$$27);
	ZVAL_UNDEF(&_25$$27);
	ZVAL_UNDEF(&_27$$29);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&_29$$31);
	ZVAL_UNDEF(&_30$$31);
	ZVAL_UNDEF(&_32$$33);
	ZVAL_UNDEF(&_34$$36);
	ZVAL_UNDEF(&_35$$37);
	ZVAL_UNDEF(&_36$$37);
	ZVAL_UNDEF(&_37$$40);
	ZVAL_UNDEF(&_38$$40);
	ZVAL_UNDEF(&_39$$41);
	ZVAL_UNDEF(&_40$$42);
	ZVAL_UNDEF(&_16$$22);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services", "phalcon/mvc/application.zep", 118);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "application:boot");
		ZEPHIR_CALL_METHOD(&_1$$4, &eventsManager, "fire", NULL, 0, &_2$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "router");
	ZEPHIR_CALL_METHOD(&_3, &dependencyInjector, "getshared", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&router, &_3);
	ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getmatchedroute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&matchedRoute) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&match, &matchedRoute, "getmatch", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&match) != IS_NULL) {
			if (zephir_instance_of_ev(&match, zend_ce_closure TSRMLS_CC)) {
				_6$$8 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_5$$8, _6$$8, "bind", NULL, 0, &match, &dependencyInjector);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&match, &_5$$8);
			}
			ZEPHIR_CALL_METHOD(&_7$$7, &router, "getparams", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&possibleResponse);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&possibleResponse, &match, &_7$$7);
			zephir_check_call_status();
			if (Z_TYPE_P(&possibleResponse) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_9$$9);
				ZVAL_STRING(&_9$$9, "response");
				ZEPHIR_CALL_METHOD(&_8$$9, &dependencyInjector, "getshared", NULL, 0, &_9$$9);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&response, &_8$$9);
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &possibleResponse);
				zephir_check_call_status();
				RETURN_CCTOR(&response);
			}
			if (Z_TYPE_P(&possibleResponse) == IS_OBJECT) {
				if (zephir_instance_of_ev(&possibleResponse, phalcon_http_responseinterface_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, &possibleResponse, "sendheaders", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &possibleResponse, "sendcookies", NULL, 0);
					zephir_check_call_status();
					RETURN_CCTOR(&possibleResponse);
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&moduleName, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&moduleName))) {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property(&moduleName, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&moduleObject);
	ZVAL_NULL(&moduleObject);
	if (zephir_is_true(&moduleName)) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_11$$14);
			ZVAL_STRING(&_11$$14, "application:beforeStartModule");
			ZEPHIR_CALL_METHOD(&_10$$14, &eventsManager, "fire", NULL, 0, &_11$$14, this_ptr, &moduleName);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$14)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&module, this_ptr, "getmodule", NULL, 0, &moduleName);
		zephir_check_call_status();
		_12$$13 = Z_TYPE_P(&module) != IS_ARRAY;
		if (_12$$13) {
			_12$$13 = Z_TYPE_P(&module) != IS_OBJECT;
		}
		if (_12$$13) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/mvc/application.zep", 209);
			return;
		}
		if (Z_TYPE_P(&module) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(&className);
			if (!(zephir_array_isset_string_fetch(&className, &module, SL("className"), 0))) {
				ZEPHIR_INIT_NVAR(&className);
				ZVAL_STRING(&className, "Module");
			}
			ZEPHIR_OBS_VAR(&path);
			if (zephir_array_isset_string_fetch(&path, &module, SL("path"), 0)) {
				if (!(zephir_class_exists(&className, zephir_is_true(&__$false)  TSRMLS_CC))) {
					if (!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS))) {
						ZEPHIR_INIT_VAR(&_13$$21);
						object_init_ex(&_13$$21, phalcon_mvc_application_exception_ce);
						ZEPHIR_INIT_VAR(&_14$$21);
						ZEPHIR_CONCAT_SVS(&_14$$21, "Module definition path '", &path, "' doesn't exist");
						ZEPHIR_CALL_METHOD(NULL, &_13$$21, "__construct", NULL, 4, &_14$$21);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_13$$21, "phalcon/mvc/application.zep", 230 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_require_zval(&path TSRMLS_CC) == FAILURE) {
						RETURN_MM_NULL();
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_15$$17, &dependencyInjector, "get", NULL, 0, &className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&moduleObject, &_15$$17);
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerautoloaders", NULL, 0, &dependencyInjector);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerservices", NULL, 0, &dependencyInjector);
			zephir_check_call_status();
		} else {
			if (!(zephir_instance_of_ev(&module, zend_ce_closure TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/mvc/application.zep", 251);
				return;
			}
			ZEPHIR_INIT_VAR(&_16$$22);
			zephir_create_array(&_16$$22, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_16$$22, &dependencyInjector);
			ZEPHIR_INIT_NVAR(&moduleObject);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&moduleObject, &module, &_16$$22);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_17$$24);
			ZVAL_STRING(&_17$$24, "application:afterStartModule");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_17$$24, this_ptr, &moduleObject);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(&implicitView);
	zephir_read_property(&implicitView, this_ptr, SL("_implicitView"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
		ZEPHIR_INIT_VAR(&_19$$25);
		ZVAL_STRING(&_19$$25, "view");
		ZEPHIR_CALL_METHOD(&_18$$25, &dependencyInjector, "getshared", NULL, 0, &_19$$25);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&view, &_18$$25);
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "dispatcher");
	ZEPHIR_CALL_METHOD(&_3, &dependencyInjector, "getshared", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dispatcher, &_3);
	ZEPHIR_CALL_METHOD(&_3, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodulename", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_20, &router, "getnamespacename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setnamespacename", NULL, 0, &_20);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_21, &router, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setcontrollername", NULL, 0, &_21);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_22, &router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setactionname", NULL, 0, &_22);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_23, &router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_23);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
		ZEPHIR_CALL_METHOD(NULL, &view, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_25$$27);
		ZVAL_STRING(&_25$$27, "application:beforeHandleRequest");
		ZEPHIR_CALL_METHOD(&_24$$27, &eventsManager, "fire", NULL, 0, &_25$$27, this_ptr, &dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_24$$27)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&controller, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&possibleResponse, &dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	_26 = ((Z_TYPE_P(&possibleResponse) == IS_TRUE || Z_TYPE_P(&possibleResponse) == IS_FALSE) == 1);
	if (_26) {
		_26 = ZEPHIR_IS_FALSE_IDENTICAL(&possibleResponse);
	}
	if (_26) {
		ZEPHIR_INIT_VAR(&_28$$29);
		ZVAL_STRING(&_28$$29, "response");
		ZEPHIR_CALL_METHOD(&_27$$29, &dependencyInjector, "getshared", NULL, 0, &_28$$29);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&response, &_27$$29);
	} else {
		if (Z_TYPE_P(&possibleResponse) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_30$$31);
			ZVAL_STRING(&_30$$31, "response");
			ZEPHIR_CALL_METHOD(&_29$$31, &dependencyInjector, "getshared", NULL, 0, &_30$$31);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_29$$31);
			ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &possibleResponse);
			zephir_check_call_status();
		} else {
			_31$$32 = (Z_TYPE_P(&possibleResponse) == IS_OBJECT);
			if (_31$$32) {
				_31$$32 = (zephir_instance_of_ev(&possibleResponse, phalcon_http_responseinterface_ce TSRMLS_CC));
			}
			returnedResponse = _31$$32;
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_32$$33);
				ZVAL_STRING(&_32$$33, "application:afterHandleRequest");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_32$$33, this_ptr, &controller);
				zephir_check_call_status();
			}
			_33$$32 = returnedResponse == 0;
			if (_33$$32) {
				_33$$32 = ZEPHIR_IS_TRUE_IDENTICAL(&implicitView);
			}
			if (_33$$32) {
				if (Z_TYPE_P(&controller) == IS_OBJECT) {
					ZEPHIR_INIT_VAR(&renderStatus);
					ZVAL_BOOL(&renderStatus, 1);
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_VAR(&_34$$36);
						ZVAL_STRING(&_34$$36, "application:viewRender");
						ZEPHIR_CALL_METHOD(&renderStatus, &eventsManager, "fire", NULL, 0, &_34$$36, this_ptr, &view);
						zephir_check_call_status();
					}
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&renderStatus)) {
						ZEPHIR_CALL_METHOD(&_35$$37, &dispatcher, "getcontrollername", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_36$$37, &dispatcher, "getactionname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &view, "render", NULL, 0, &_35$$37, &_36$$37);
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
				ZEPHIR_INIT_VAR(&_38$$40);
				ZVAL_STRING(&_38$$40, "response");
				ZEPHIR_CALL_METHOD(&_37$$40, &dependencyInjector, "getshared", NULL, 0, &_38$$40);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&response, &_37$$40);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
					ZEPHIR_CALL_METHOD(&_39$$41, &view, "getcontent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &_39$$41);
					zephir_check_call_status();
				}
			}
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_40$$42);
		ZVAL_STRING(&_40$$42, "application:beforeSendResponse");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_40$$42, this_ptr, &response);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, SL("_sendHeaders"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &response, "sendheaders", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_41, this_ptr, SL("_sendCookies"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_41)) {
		ZEPHIR_CALL_METHOD(NULL, &response, "sendcookies", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&response);

}

