
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
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

	zend_declare_property_bool(phalcon_mvc_application_ce, SL("implicitView"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_application_ce, SL("sendCookies"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_application_ce, SL("sendHeaders"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Handles a MVC request
 */
PHP_METHOD(Phalcon_Mvc_Application, handle) {

	zval _20$$22;
	zend_class_entry *_10$$8;
	zend_bool returnedResponse = 0, _30, _16$$13, _35$$32, _37$$32;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *uri_param = NULL, __$false, container, eventsManager, router, dispatcher, response, view, module, moduleObject, moduleName, className, path, implicitView, controller, possibleResponse, renderStatus, matchedRoute, match, _0, _7, _8, _24, _25, _26, _27, _45, _1$$3, _2$$3, _4$$3, _5$$4, _6$$4, _9$$8, _11$$7, _12$$9, _13$$9, _14$$14, _15$$14, _17$$21, _18$$21, _19$$17, _21$$24, _22$$25, _23$$25, _28$$27, _29$$27, _31$$29, _32$$29, _33$$31, _34$$31, _36$$33, _38$$36, _39$$37, _40$$37, _41$$40, _42$$40, _43$$41, _44$$42;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
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
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_21$$24);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_28$$27);
	ZVAL_UNDEF(&_29$$27);
	ZVAL_UNDEF(&_31$$29);
	ZVAL_UNDEF(&_32$$29);
	ZVAL_UNDEF(&_33$$31);
	ZVAL_UNDEF(&_34$$31);
	ZVAL_UNDEF(&_36$$33);
	ZVAL_UNDEF(&_38$$36);
	ZVAL_UNDEF(&_39$$37);
	ZVAL_UNDEF(&_40$$37);
	ZVAL_UNDEF(&_41$$40);
	ZVAL_UNDEF(&_42$$40);
	ZVAL_UNDEF(&_43$$41);
	ZVAL_UNDEF(&_44$$42);
	ZVAL_UNDEF(&_20$$22);

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


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_application_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "internal services");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_mvc_application_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Application.zep", 90 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "application:boot");
		ZEPHIR_CALL_METHOD(&_5$$4, &eventsManager, "fire", NULL, 0, &_6$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "router");
	ZEPHIR_CALL_METHOD(&_7, &container, "getshared", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&router, &_7);
	ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getmatchedroute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&matchedRoute) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&match, &matchedRoute, "getmatch", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&match) != IS_NULL) {
			if (zephir_instance_of_ev(&match, zend_ce_closure TSRMLS_CC)) {
				_10$$8 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_9$$8, _10$$8, "bind", NULL, 0, &match, &container);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&match, &_9$$8);
			}
			ZEPHIR_CALL_METHOD(&_11$$7, &router, "getparams", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&possibleResponse);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&possibleResponse, &match, &_11$$7);
			zephir_check_call_status();
			if (Z_TYPE_P(&possibleResponse) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_13$$9);
				ZVAL_STRING(&_13$$9, "response");
				ZEPHIR_CALL_METHOD(&_12$$9, &container, "getshared", NULL, 0, &_13$$9);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&response, &_12$$9);
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
		zephir_read_property(&moduleName, this_ptr, SL("defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&moduleObject);
	ZVAL_NULL(&moduleObject);
	if (zephir_is_true(&moduleName)) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_15$$14);
			ZVAL_STRING(&_15$$14, "application:beforeStartModule");
			ZEPHIR_CALL_METHOD(&_14$$14, &eventsManager, "fire", NULL, 0, &_15$$14, this_ptr, &moduleName);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$14)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&module, this_ptr, "getmodule", NULL, 0, &moduleName);
		zephir_check_call_status();
		_16$$13 = Z_TYPE_P(&module) != IS_ARRAY;
		if (_16$$13) {
			_16$$13 = Z_TYPE_P(&module) != IS_OBJECT;
		}
		if (_16$$13) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/Mvc/Application.zep", 181);
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
						ZEPHIR_INIT_VAR(&_17$$21);
						object_init_ex(&_17$$21, phalcon_mvc_application_exception_ce);
						ZEPHIR_INIT_VAR(&_18$$21);
						ZEPHIR_CONCAT_SVS(&_18$$21, "Module definition path '", &path, "' doesn't exist");
						ZEPHIR_CALL_METHOD(NULL, &_17$$21, "__construct", NULL, 1, &_18$$21);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$21, "phalcon/Mvc/Application.zep", 202 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_require_zval(&path TSRMLS_CC) == FAILURE) {
						RETURN_MM_NULL();
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_19$$17, &container, "get", NULL, 0, &className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&moduleObject, &_19$$17);
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerautoloaders", NULL, 0, &container);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerservices", NULL, 0, &container);
			zephir_check_call_status();
		} else {
			if (!(zephir_instance_of_ev(&module, zend_ce_closure TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/Mvc/Application.zep", 223);
				return;
			}
			ZEPHIR_INIT_VAR(&_20$$22);
			zephir_create_array(&_20$$22, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_20$$22, &container);
			ZEPHIR_INIT_NVAR(&moduleObject);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&moduleObject, &module, &_20$$22);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_21$$24);
			ZVAL_STRING(&_21$$24, "application:afterStartModule");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_21$$24, this_ptr, &moduleObject);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_0, this_ptr, SL("implicitView"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&implicitView, &_0);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
		ZEPHIR_INIT_VAR(&_23$$25);
		ZVAL_STRING(&_23$$25, "view");
		ZEPHIR_CALL_METHOD(&_22$$25, &container, "getshared", NULL, 0, &_23$$25);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&view, &_22$$25);
	}
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "dispatcher");
	ZEPHIR_CALL_METHOD(&_7, &container, "getshared", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dispatcher, &_7);
	ZEPHIR_CALL_METHOD(&_7, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodulename", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_24, &router, "getnamespacename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setnamespacename", NULL, 0, &_24);
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
		ZEPHIR_INIT_VAR(&_29$$27);
		ZVAL_STRING(&_29$$27, "application:beforeHandleRequest");
		ZEPHIR_CALL_METHOD(&_28$$27, &eventsManager, "fire", NULL, 0, &_29$$27, this_ptr, &dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_28$$27)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&controller, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&possibleResponse, &dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	_30 = ((Z_TYPE_P(&possibleResponse) == IS_TRUE || Z_TYPE_P(&possibleResponse) == IS_FALSE) == 1);
	if (_30) {
		_30 = ZEPHIR_IS_FALSE_IDENTICAL(&possibleResponse);
	}
	if (_30) {
		ZEPHIR_INIT_VAR(&_32$$29);
		ZVAL_STRING(&_32$$29, "response");
		ZEPHIR_CALL_METHOD(&_31$$29, &container, "getshared", NULL, 0, &_32$$29);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&response, &_31$$29);
	} else {
		if (Z_TYPE_P(&possibleResponse) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_34$$31);
			ZVAL_STRING(&_34$$31, "response");
			ZEPHIR_CALL_METHOD(&_33$$31, &container, "getshared", NULL, 0, &_34$$31);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_33$$31);
			ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &possibleResponse);
			zephir_check_call_status();
		} else {
			_35$$32 = (Z_TYPE_P(&possibleResponse) == IS_OBJECT);
			if (_35$$32) {
				_35$$32 = (zephir_instance_of_ev(&possibleResponse, phalcon_http_responseinterface_ce TSRMLS_CC));
			}
			returnedResponse = _35$$32;
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_36$$33);
				ZVAL_STRING(&_36$$33, "application:afterHandleRequest");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_36$$33, this_ptr, &controller);
				zephir_check_call_status();
			}
			_37$$32 = returnedResponse == 0;
			if (_37$$32) {
				_37$$32 = ZEPHIR_IS_TRUE_IDENTICAL(&implicitView);
			}
			if (_37$$32) {
				if (Z_TYPE_P(&controller) == IS_OBJECT) {
					ZEPHIR_INIT_VAR(&renderStatus);
					ZVAL_BOOL(&renderStatus, 1);
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_VAR(&_38$$36);
						ZVAL_STRING(&_38$$36, "application:viewRender");
						ZEPHIR_CALL_METHOD(&renderStatus, &eventsManager, "fire", NULL, 0, &_38$$36, this_ptr, &view);
						zephir_check_call_status();
					}
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&renderStatus)) {
						ZEPHIR_CALL_METHOD(&_39$$37, &dispatcher, "getcontrollername", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_40$$37, &dispatcher, "getactionname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &view, "render", NULL, 0, &_39$$37, &_40$$37);
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
				ZEPHIR_INIT_VAR(&_42$$40);
				ZVAL_STRING(&_42$$40, "response");
				ZEPHIR_CALL_METHOD(&_41$$40, &container, "getshared", NULL, 0, &_42$$40);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&response, &_41$$40);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&implicitView)) {
					ZEPHIR_CALL_METHOD(&_43$$41, &view, "getcontent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &_43$$41);
					zephir_check_call_status();
				}
			}
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_44$$42);
		ZVAL_STRING(&_44$$42, "application:beforeSendResponse");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_44$$42, this_ptr, &response);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, SL("sendHeaders"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &response, "sendheaders", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_45, this_ptr, SL("sendCookies"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_45)) {
		ZEPHIR_CALL_METHOD(NULL, &response, "sendcookies", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&response);

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
		zephir_update_property_zval(this_ptr, SL("sendCookies"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("sendCookies"), &__$false);
	}
	RETURN_THISW();

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
		zephir_update_property_zval(this_ptr, SL("sendHeaders"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("sendHeaders"), &__$false);
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
		zephir_update_property_zval(this_ptr, SL("implicitView"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("implicitView"), &__$false);
	}
	RETURN_THISW();

}

