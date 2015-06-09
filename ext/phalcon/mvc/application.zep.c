
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
#include "kernel/file.h"
#include "kernel/require.h"
#include "Zend/zend_closures.h"


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


	zephir_update_property_this(this_ptr, SL("_implicitView"), implicitView ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
	zval *modules_param = NULL, *merge_param = NULL, *registeredModules, *_0;
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
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_array_merge(_0, &(registeredModules), &(modules) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_modules"), _0 TSRMLS_CC);
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
	zval *name_param = NULL, *module, *_0, *_1;
	zval *name = NULL, *_2;

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
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_application_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Module '", name, "' isn't registered in the application container");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/application.zep", 159 TSRMLS_CC);
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
 * @return Phalcon\Http\ResponseInterface|boolean
 */
PHP_METHOD(Phalcon_Mvc_Application, handle) {

	zval *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool returnedResponse, _3;
	zval *uri = NULL, *dependencyInjector, *eventsManager = NULL, *router = NULL, *dispatcher = NULL, *response = NULL, *view = NULL, *module = NULL, *moduleObject = NULL, *moduleName = NULL, *className = NULL, *path, *implicitView, *controller = NULL, *possibleResponse = NULL, *renderStatus = NULL, *_0, *_1 = NULL, *_2 = NULL, *_4, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services", "phalcon/mvc/application.zep", 197);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "application:boot", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, eventsManager, "fire", NULL, 0, _2, this_ptr);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(router, _1);
	ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, 0, uri);
	zephir_check_call_status();
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
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "application:beforeStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_1, eventsManager, "fire", NULL, 0, _2, this_ptr, moduleName);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&module, this_ptr, "getmodule", NULL, 0, moduleName);
		zephir_check_call_status();
		_3 = Z_TYPE_P(module) != IS_ARRAY;
		if (_3) {
			_3 = Z_TYPE_P(module) != IS_OBJECT;
		}
		if (_3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/mvc/application.zep", 248);
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
						ZEPHIR_INIT_NVAR(_2);
						object_init_ex(_2, phalcon_mvc_application_exception_ce);
						ZEPHIR_INIT_VAR(_4);
						ZEPHIR_CONCAT_SVS(_4, "Module definition path '", path, "' doesn't exist");
						ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 2, _4);
						zephir_check_call_status();
						zephir_throw_exception_debug(_2, "phalcon/mvc/application.zep", 271 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_5, dependencyInjector, "get", NULL, 0, className);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(moduleObject, _5);
			ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerautoloaders", NULL, 0, dependencyInjector);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, moduleObject, "registerservices", NULL, 0, dependencyInjector);
			zephir_check_call_status();
		} else {
			if (zephir_instance_of_ev(module, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_6);
				zephir_create_array(_6, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_6, dependencyInjector);
				ZEPHIR_INIT_NVAR(moduleObject);
				ZEPHIR_CALL_USER_FUNC_ARRAY(moduleObject, module, _6);
				zephir_check_call_status();
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_application_exception_ce, "Invalid module definition", "phalcon/mvc/application.zep", 292);
				return;
			}
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "application:afterStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, moduleObject);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(implicitView);
	zephir_read_property_this(&implicitView, this_ptr, SL("_implicitView"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(view, _1);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dispatcher, _1);
	ZEPHIR_CALL_METHOD(&_1, router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodulename", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, router, "getnamespacename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setnamespacename", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, router, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setcontrollername", NULL, 0, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, 0, _8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _9);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
		ZEPHIR_CALL_METHOD(NULL, view, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "application:beforeHandleRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, eventsManager, "fire", NULL, 0, _2, this_ptr, dispatcher);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&controller, dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&possibleResponse, dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	_3 = Z_TYPE_P(possibleResponse) == IS_BOOL;
	if (_3) {
		_3 = ZEPHIR_IS_FALSE(possibleResponse);
	}
	if (_3) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(response, _1);
	} else {
		if (Z_TYPE_P(possibleResponse) == IS_OBJECT) {
			returnedResponse = zephir_instance_of_ev(possibleResponse, phalcon_http_responseinterface_ce TSRMLS_CC);
		} else {
			returnedResponse = 0;
		}
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "application:afterHandleRequest", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, controller);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		if (returnedResponse == 0) {
			if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
				if (Z_TYPE_P(controller) == IS_OBJECT) {
					ZEPHIR_INIT_VAR(renderStatus);
					ZVAL_BOOL(renderStatus, 1);
					if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(_2);
						ZVAL_STRING(_2, "application:viewRender", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&renderStatus, eventsManager, "fire", NULL, 0, _2, this_ptr, view);
						zephir_check_temp_parameter(_2);
						zephir_check_call_status();
					}
					if (!ZEPHIR_IS_FALSE_IDENTICAL(renderStatus)) {
						ZEPHIR_CALL_METHOD(&_1, dispatcher, "getcontrollername", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_5, dispatcher, "getactionname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_10, dispatcher, "getparams", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, view, "render", NULL, 0, _1, _5, _10);
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
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "response", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_5, dependencyInjector, "getshared", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(response, _5);
			if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
				ZEPHIR_CALL_METHOD(&_5, view, "getcontent", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, _5);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(response, possibleResponse);
		}
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "application:beforeSendResponse", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, response);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, response, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "sendcookies", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(response);

}

