
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_application_ce, SL("_implicitView"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Application
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Application, __construct) {

	zval *dependencyInjector = NULL;

	zephir_fetch_params(0, 0, 1, &dependencyInjector);

	if (!dependencyInjector || Z_TYPE_P(dependencyInjector) == IS_NULL) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}

}

/**
 * By default. The view is implicitly buffering all the output
 * You can full disable the view component using this method
 *
 * @param boolean implicitView
 * @return Phalcon\Mvc\Application
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
 *
 * @param array modules
 * @param boolean merge
 * @param Phalcon\Mvc\Application
 */
PHP_METHOD(Phalcon_Mvc_Application, registerModules) {

	zend_bool merge;
	zval *modules, *merge_param = NULL, *registeredModules, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modules, &merge_param);

	if (!merge_param || Z_TYPE_P(merge_param) == IS_NULL) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if ((Z_TYPE_P(modules) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Modules must be an Array");
		return;
	}
	if ((merge == 0)) {
		zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);
	} else {
		registeredModules = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		if ((Z_TYPE_P(registeredModules) == IS_ARRAY)) {
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
 * Sets the module name to be used if the router doesn't return a valid module
 *
 * @param string defaultModule
 * @return Phalcon\Mvc\Application
 */
PHP_METHOD(Phalcon_Mvc_Application, setDefaultModule) {

	zval *defaultModule_param = NULL;
	zval *defaultModule = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultModule_param);

		if (Z_TYPE_P(defaultModule_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultModule' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		defaultModule = defaultModule_param;



	zephir_update_property_this(this_ptr, SL("_defaultModule"), defaultModule TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the default module name
 *
 * @return string
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

	zend_bool returnedResponse;
	zval *uri = NULL, *dependencyInjector, *eventsManager = NULL, *router = NULL, *dispatcher = NULL, *response = NULL, *view = NULL, *module, *modules, *moduleObject = NULL, *moduleName = NULL, *className = NULL, *path, *implicitView, *controller, *possibleResponse, *renderStatus = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri || Z_TYPE_P(uri) == IS_NULL) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "application:boot", 1);
		zephir_call_method_p2(_1, eventsManager, "fire", _2, this_ptr);
		if (ZEPHIR_IS_FALSE(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "router", 1);
	zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
	ZEPHIR_CPY_WRT(router, _1);
	zephir_call_method_p1_noret(router, "handle", uri);
	ZEPHIR_INIT_VAR(moduleName);
	zephir_call_method(moduleName, router, "getmodulename");
	if (!(zephir_is_true(moduleName))) {
		ZEPHIR_OBS_NVAR(moduleName);
		zephir_read_property_this(&moduleName, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(moduleObject);
	ZVAL_NULL(moduleObject);
	if (zephir_is_true(moduleName)) {
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "application:beforeStartModule", 1);
			zephir_call_method_p2(_1, eventsManager, "fire", _2, this_ptr);
			if (ZEPHIR_IS_FALSE(_1)) {
				RETURN_MM_BOOL(0);
			}
		}
		modules = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&module, modules, moduleName, 1 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_2);
			object_init_ex(_2, phalcon_mvc_application_exception_ce);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "Module '", moduleName, "' isn't registered in the application container");
			zephir_call_method_p1_noret(_2, "__construct", _3);
			zephir_throw_exception(_2 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if ((Z_TYPE_P(module) != IS_ARRAY)) {
			if ((Z_TYPE_P(module) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Invalid module definition");
				return;
			}
		}
		if ((Z_TYPE_P(module) == IS_ARRAY)) {
			ZEPHIR_OBS_VAR(className);
			if (!(zephir_array_isset_string_fetch(&className, module, SS("className"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(className);
				ZVAL_STRING(className, "Module", 1);
			}
			if (zephir_array_isset_string_fetch(&path, module, SS("path"), 1 TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_2);
				zephir_call_func_p2(_2, "class_exists", className, ZEPHIR_GLOBAL(global_false));
				if (!(zephir_is_true(_2))) {
					ZEPHIR_INIT_VAR(_4);
					zephir_call_func_p1(_4, "file_exists", path);
					if (zephir_is_true(_4)) {
					} else {
						ZEPHIR_INIT_VAR(_5);
						object_init_ex(_5, phalcon_mvc_application_exception_ce);
						ZEPHIR_INIT_LNVAR(_3);
						ZEPHIR_CONCAT_SVS(_3, "Module definition path '", path, "' doesn't exist");
						zephir_call_method_p1_noret(_5, "__construct", _3);
						zephir_throw_exception(_5 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method_p1(_4, dependencyInjector, "get", className);
			ZEPHIR_CPY_WRT(moduleObject, _4);
			zephir_call_method_p1_noret(moduleObject, "registerautoloaders", dependencyInjector);
			zephir_call_method_p1_noret(moduleObject, "registerservices", dependencyInjector);
		} else {
			if (zephir_is_instance_of(module, SL("Closure") TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_4);
				array_init(_4);
				zephir_array_fast_append(_4, dependencyInjector);
				ZEPHIR_INIT_BNVAR(moduleObject);
				zephir_call_func_p2(moduleObject, "call_user_func_array", module, _4);
			} else {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Invalid module definition");
				return;
			}
		}
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "application:afterStartModule", 1);
			zephir_call_method_p3_noret(eventsManager, "fire", _5, this_ptr, moduleObject);
		}
	}
	implicitView = zephir_fetch_nproperty_this(this_ptr, SL("_implicitView"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE(implicitView)) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "view", 1);
		zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
		ZEPHIR_CPY_WRT(view, _1);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "dispatcher", 1);
	zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
	ZEPHIR_CPY_WRT(dispatcher, _1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_method(_1, router, "getmodulename");
	zephir_call_method_p1_noret(dispatcher, "setmodulename", _1);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, router, "getnamespacename");
	zephir_call_method_p1_noret(dispatcher, "setnamespacename", _2);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_method(_5, router, "getcontrollername");
	zephir_call_method_p1_noret(dispatcher, "setcontrollername", _5);
	ZEPHIR_INIT_VAR(_6);
	zephir_call_method(_6, router, "getactionname");
	zephir_call_method_p1_noret(dispatcher, "setactionname", _6);
	ZEPHIR_INIT_VAR(_7);
	zephir_call_method(_7, router, "getparams");
	zephir_call_method_p1_noret(dispatcher, "setparams", _7);
	if (ZEPHIR_IS_TRUE(implicitView)) {
		zephir_call_method_noret(view, "start");
	}
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "application:beforeHandleRequest", 1);
		zephir_call_method_p3(_1, eventsManager, "fire", _2, this_ptr, dispatcher);
		if (ZEPHIR_IS_FALSE(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(controller);
	zephir_call_method(controller, dispatcher, "dispatch");
	ZEPHIR_INIT_VAR(possibleResponse);
	zephir_call_method(possibleResponse, dispatcher, "getreturnedvalue");
	if ((Z_TYPE_P(possibleResponse) == IS_OBJECT)) {
		returnedResponse = zephir_is_instance_of(possibleResponse, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC);
	} else {
		returnedResponse = 0;
	}
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "application:afterHandleRequest", 1);
		zephir_call_method_p3_noret(eventsManager, "fire", _1, this_ptr, controller);
	}
	if ((returnedResponse == 0)) {
		if (ZEPHIR_IS_TRUE(implicitView)) {
			if ((Z_TYPE_P(controller) == IS_OBJECT)) {
				ZEPHIR_INIT_VAR(renderStatus);
				ZVAL_BOOL(renderStatus, 1);
				if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_STRING(_1, "application:viewRender", 1);
					ZEPHIR_INIT_NVAR(renderStatus);
					zephir_call_method_p3(renderStatus, eventsManager, "fire", _1, this_ptr, view);
				}
				if (!ZEPHIR_IS_FALSE(renderStatus)) {
					ZEPHIR_INIT_NVAR(_1);
					zephir_call_method(_1, dispatcher, "getcontrollername");
					ZEPHIR_INIT_NVAR(_2);
					zephir_call_method(_2, dispatcher, "getactionname");
					ZEPHIR_INIT_NVAR(_4);
					zephir_call_method(_4, dispatcher, "getparams");
					zephir_call_method_p3_noret(view, "render", _1, _2, _4);
				}
			}
		}
	}
	if (ZEPHIR_IS_TRUE(implicitView)) {
		zephir_call_method_noret(view, "finish");
	}
	if ((returnedResponse == 0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "response", 1);
		zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
		ZEPHIR_CPY_WRT(response, _1);
		if (ZEPHIR_IS_TRUE(implicitView)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_method(_1, view, "getcontent");
			zephir_call_method_p1_noret(response, "setcontent", _1);
		}
	} else {
		ZEPHIR_CPY_WRT(response, possibleResponse);
	}
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "application:beforeSendResponse", 1);
		zephir_call_method_p3_noret(eventsManager, "fire", _1, this_ptr, response);
	}
	zephir_call_method_noret(response, "sendheaders");
	zephir_call_method_noret(response, "sendcookies");
	RETURN_CCTOR(response);

}

