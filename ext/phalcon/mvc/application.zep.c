
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"
#include "kernel/file.h"
#include "kernel/require.h"


/**
 * Phalcon\Mvc\Application
 *
 * This component encapsulates all the complex operations behind instantiating every component
 * needed and integrating it with the rest to allow the MVC pattern to operate as desired.
 *
 *<code>
 *
 * class Application extends \Phalcon\Mvc\Application
 * {
 *
 *		/**
 *		 * Register the services here to make them general or register
 *		 * in the ModuleDefinition to make them module-specific
 *		 *\/
 *		protected function _registerServices()
 *		{
 *
 *		}
 *
 *		/**
 *		 * This method registers all the modules in the application
 *		 *\/
 *		public function main()
 *		{
 *			$this->registerModules(array(
 *				'frontend' => array(
 *					'className' => 'Multiple\Frontend\Module',
 *					'path' => '../apps/frontend/Module.php'
 *				),
 *				'backend' => array(
 *					'className' => 'Multiple\Backend\Module',
 *					'path' => '../apps/backend/Module.php'
 *				)
 *			));
 *		}
 *	}
 *
 *	$application = new Application();
 *	$application->main();
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Application, phalcon, mvc_application, phalcon_di_injectable_ce, phalcon_mvc_application_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_application_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_application_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_application_ce, SL("_implicitView"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Application
 */
PHP_METHOD(Phalcon_Mvc_Application, __construct) {

	zval *dependencyInjector = NULL;

	zephir_fetch_params(0, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}

}

/**
 * By default. The view is implicitly buffering all the output
 * You can full disable the view component using this method
 */
PHP_METHOD(Phalcon_Mvc_Application, useImplicitView) {

	zval *implicitView_param = NULL;
	zend_bool implicitView;

	zephir_fetch_params(0, 1, 0, &implicitView_param);

	implicitView = zephir_get_boolval(implicitView_param);


	if (implicitView) {
		zephir_update_property_this(this_ptr, SL("_implicitView"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_implicitView"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Register an array of modules present in the application
 *
 *<code>
 *	$this->registerModules(array(
 *		'frontend' => array(
 *			'className' => 'Multiple\Frontend\Module',
 *			'path' => '../apps/frontend/Module.php'
 *		),
 *		'backend' => array(
 *			'className' => 'Multiple\Backend\Module',
 *			'path' => '../apps/backend/Module.php'
 *		)
 *	));
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Application, registerModules) {

	zend_bool merge;
	zval *modules_param = NULL, *merge_param = NULL, *registeredModules = NULL, *_0$$5;
	zval *modules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modules_param, &merge_param);

	zephir_get_arrval(modules, modules_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge == 0) {
		zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);
	} else {
		ZEPHIR_OBS_VAR(registeredModules);
		zephir_read_property_this(&registeredModules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (Z_TYPE_P(registeredModules) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$5);
			zephir_fast_array_merge(_0$$5, &(registeredModules), &(modules) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_modules"), _0$$5 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Return the modules registered in the application
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Application, getModules) {

	

	RETURN_MEMBER(this_ptr, "_modules");

}

/**
 * Gets the module definition registered in the application via module name
 *
 * @param string name
 * @return array|object
 */
PHP_METHOD(Phalcon_Mvc_Application, getModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *module = NULL, *_0, *_1$$3;
	zval *name = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(module);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&module, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_application_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Module '", name, "' isn't registered in the application container");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/application.zep", 160 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(module);

}

/**
 * Sets the module name to be used if the router doesn't return a valid module
 */
PHP_METHOD(Phalcon_Mvc_Application, setDefaultModule) {

	zval *defaultModule_param = NULL;
	zval *defaultModule = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultModule_param);

	if (unlikely(Z_TYPE_P(defaultModule_param) != IS_STRING && Z_TYPE_P(defaultModule_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultModule' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(defaultModule_param) == IS_STRING)) {
		zephir_get_strval(defaultModule, defaultModule_param);
	} else {
		ZEPHIR_INIT_VAR(defaultModule);
		ZVAL_EMPTY_STRING(defaultModule);
	}


	zephir_update_property_this(this_ptr, SL("_defaultModule"), defaultModule TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the default module name
 */
PHP_METHOD(Phalcon_Mvc_Application, getDefaultModule) {

	

	RETURN_MEMBER(this_ptr, "_defaultModule");

}

/**
 * Handles a MVC request
 *
 * @param string uri
 * @return \Phalcon\Http\ResponseInterface|boolean
 */
PHP_METHOD(Phalcon_Mvc_Application, handle) {

	zval *_16$$24;
	zend_class_entry *_6$$8;
	zend_bool returnedResponse = 0, _26, _12$$13;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *dependencyInjector = NULL, *eventsManager = NULL, *router = NULL, *dispatcher = NULL, *response = NULL, *view = NULL, *module = NULL, *moduleObject = NULL, *moduleName = NULL, *className = NULL, *path = NULL, *implicitView = NULL, *controller = NULL, *possibleResponse = NULL, *renderStatus = NULL, *matchedRoute = NULL, *match = NULL, *_0, *_3 = NULL, *_4 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_23 = NULL, *_1$$4 = NULL, *_2$$4, *_5$$8 = NULL, *_7$$7 = NULL, *_8$$9 = NULL, *_9$$9, *_10$$14 = NULL, *_11$$14, *_13$$22, *_14$$22, *_15$$17 = NULL, *_17$$26, *_18$$27 = NULL, *_19$$27, *_24$$29 = NULL, *_25$$29, *_27$$31 = NULL, *_28$$31, *_29$$33 = NULL, *_30$$33, *_31$$37, *_32$$41, *_33$$42 = NULL, *_34$$42 = NULL, *_35$$42 = NULL, *_36$$44 = NULL, *_37$$44, *_38$$45 = NULL, *_39$$47;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services", "phalcon/mvc/application.zep", 198);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "application:boot", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$4, eventsManager, "fire", NULL, 0, _2$$4, this_ptr);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "getshared", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(router, _3);
	ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, 0, uri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&matchedRoute, router, "getmatchedroute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(matchedRoute) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&match, matchedRoute, "getmatch", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(match) != IS_NULL) {
			if (zephir_instance_of_ev(match, zend_ce_closure TSRMLS_CC)) {
					_6$$8 = zend_fetch_class(SL("Closure"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				ZEPHIR_CALL_CE_STATIC(&_5$$8, _6$$8, "bind", NULL, 0, match, dependencyInjector);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(match, _5$$8);
			}
			ZEPHIR_CALL_METHOD(&_7$$7, router, "getparams", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(possibleResponse);
			ZEPHIR_CALL_USER_FUNC_ARRAY(possibleResponse, match, _7$$7);
			zephir_check_call_status();
			if (Z_TYPE_P(possibleResponse) == IS_STRING) {
				ZEPHIR_INIT_VAR(_9$$9);
				ZVAL_STRING(_9$$9, "response", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_8$$9, dependencyInjector, "getshared", NULL, 0, _9$$9);
				zephir_check_temp_parameter(_9$$9);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(response, _8$$9);
				ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, possibleResponse);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			if (Z_TYPE_P(possibleResponse) == IS_OBJECT) {
				if (zephir_instance_of_ev(possibleResponse, phalcon_http_responseinterface_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, possibleResponse, "sendheaders", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, possibleResponse, "sendcookies", NULL, 0);
					zephir_check_call_status();
					RETURN_CCTOR(possibleResponse);
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&moduleName, router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(moduleName))) {
		ZEPHIR_OBS_NVAR(moduleName);
		zephir_read_property_this(&moduleName, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(moduleObject);
	ZVAL_NULL(moduleObject);
	if (zephir_is_true(moduleName)) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_11$$14);
			ZVAL_STRING(_11$$14, "application:beforeStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_10$$14, eventsManager, "fire", NULL, 0, _11$$14, this_ptr, moduleName);
			zephir_check_temp_parameter(_11$$14);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_10$$14)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&module, this_ptr, "getmodule", NULL, 0, moduleName);
		zephir_check_call_status();
		_12$$13 = Z_TYPE_P(module) != IS_ARRAY;
		if (_12$$13) {
			_12$$13 = Z_TYPE_P(module) != IS_OBJECT;
		}
		if (_12$$13) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/mvc/application.zep", 289);
			return;
		}
		if (Z_TYPE_P(module) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(className);
			if (!(zephir_array_isset_string_fetch(&className, module, SS("className"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(className);
				ZVAL_STRING(className, "Module", 1);
			}
			ZEPHIR_OBS_VAR(path);
			if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
				if (!(zephir_class_exists(className, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC))) {
					if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
						if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
							RETURN_MM_NULL();
						}
					} else {
						ZEPHIR_INIT_VAR(_13$$22);
						object_init_ex(_13$$22, phalcon_mvc_application_exception_ce);
						ZEPHIR_INIT_VAR(_14$$22);
						ZEPHIR_CONCAT_SVS(_14$$22, "Module definition path '", path, "' doesn't exist");
						ZEPHIR_CALL_METHOD(NULL, _13$$22, "__construct", NULL, 9, _14$$22);
						zephir_check_call_status();
						zephir_throw_exception_debug(_13$$22, "phalcon/mvc/application.zep", 312 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_15$$17, dependencyInjector, "get", NULL, 0, className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(moduleObject, _15$$17);
			ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerautoloaders", NULL, 0, dependencyInjector);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerservices", NULL, 0, dependencyInjector);
			zephir_check_call_status();
		} else {
			if (zephir_instance_of_ev(module, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_16$$24);
				zephir_create_array(_16$$24, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_16$$24, dependencyInjector);
				ZEPHIR_INIT_NVAR(moduleObject);
				ZEPHIR_CALL_USER_FUNC_ARRAY(moduleObject, module, _16$$24);
				zephir_check_call_status();
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/mvc/application.zep", 333);
				return;
			}
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_17$$26);
			ZVAL_STRING(_17$$26, "application:afterStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _17$$26, this_ptr, moduleObject);
			zephir_check_temp_parameter(_17$$26);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(implicitView);
	zephir_read_property_this(&implicitView, this_ptr, SL("_implicitView"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
		ZEPHIR_INIT_VAR(_19$$27);
		ZVAL_STRING(_19$$27, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_18$$27, dependencyInjector, "getshared", NULL, 0, _19$$27);
		zephir_check_temp_parameter(_19$$27);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(view, _18$$27);
	}
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "getshared", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dispatcher, _3);
	ZEPHIR_CALL_METHOD(&_3, router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodulename", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_20, router, "getnamespacename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setnamespacename", NULL, 0, _20);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_21, router, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setcontrollername", NULL, 0, _21);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_22, router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, 0, _22);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_23, router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _23);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
		ZEPHIR_CALL_METHOD(NULL, view, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_25$$29);
		ZVAL_STRING(_25$$29, "application:beforeHandleRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_24$$29, eventsManager, "fire", NULL, 0, _25$$29, this_ptr, dispatcher);
		zephir_check_temp_parameter(_25$$29);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_24$$29)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&controller, dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&possibleResponse, dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	_26 = Z_TYPE_P(possibleResponse) == IS_BOOL;
	if (_26) {
		_26 = ZEPHIR_IS_FALSE(possibleResponse);
	}
	if (_26) {
		ZEPHIR_INIT_VAR(_28$$31);
		ZVAL_STRING(_28$$31, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_27$$31, dependencyInjector, "getshared", NULL, 0, _28$$31);
		zephir_check_temp_parameter(_28$$31);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(response, _27$$31);
	} else {
		if (Z_TYPE_P(possibleResponse) == IS_STRING) {
			ZEPHIR_INIT_VAR(_30$$33);
			ZVAL_STRING(_30$$33, "response", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_29$$33, dependencyInjector, "getshared", NULL, 0, _30$$33);
			zephir_check_temp_parameter(_30$$33);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(response, _29$$33);
			ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, possibleResponse);
			zephir_check_call_status();
		} else {
			if (Z_TYPE_P(possibleResponse) == IS_OBJECT) {
				returnedResponse = zephir_instance_of_ev(possibleResponse, phalcon_http_responseinterface_ce TSRMLS_CC);
			} else {
				returnedResponse = 0;
			}
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_31$$37);
				ZVAL_STRING(_31$$37, "application:afterHandleRequest", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _31$$37, this_ptr, controller);
				zephir_check_temp_parameter(_31$$37);
				zephir_check_call_status();
			}
			if (returnedResponse == 0) {
				if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
					if (Z_TYPE_P(controller) == IS_OBJECT) {
						ZEPHIR_INIT_VAR(renderStatus);
						ZVAL_BOOL(renderStatus, 1);
						if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
							ZEPHIR_INIT_VAR(_32$$41);
							ZVAL_STRING(_32$$41, "application:viewRender", ZEPHIR_TEMP_PARAM_COPY);
							ZEPHIR_CALL_METHOD(&renderStatus, eventsManager, "fire", NULL, 0, _32$$41, this_ptr, view);
							zephir_check_temp_parameter(_32$$41);
							zephir_check_call_status();
						}
						if (!ZEPHIR_IS_FALSE_IDENTICAL(renderStatus)) {
							ZEPHIR_CALL_METHOD(&_33$$42, dispatcher, "getcontrollername", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_34$$42, dispatcher, "getactionname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_35$$42, dispatcher, "getparams", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, view, "render", NULL, 0, _33$$42, _34$$42, _35$$42);
							zephir_check_call_status();
						}
					}
				}
			}
			if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
				ZEPHIR_CALL_METHOD(NULL, view, "finish", NULL, 0);
				zephir_check_call_status();
			}
			if (returnedResponse == 0) {
				ZEPHIR_INIT_VAR(_37$$44);
				ZVAL_STRING(_37$$44, "response", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_36$$44, dependencyInjector, "getshared", NULL, 0, _37$$44);
				zephir_check_temp_parameter(_37$$44);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(response, _36$$44);
				if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
					ZEPHIR_CALL_METHOD(&_38$$45, view, "getcontent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, _38$$45);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CPY_WRT(response, possibleResponse);
			}
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_39$$47);
		ZVAL_STRING(_39$$47, "application:beforeSendResponse", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _39$$47, this_ptr, response);
		zephir_check_temp_parameter(_39$$47);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, response, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "sendcookies", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(response);

}

