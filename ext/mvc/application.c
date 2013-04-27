
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
  |          Antonio Lopez <alantonilopez@gmail.com>                       |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
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


/**
 * Phalcon\Mvc\Application initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Application){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, Application, mvc_application, "phalcon\\di\\injectable", phalcon_mvc_application_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_application_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Application
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Application, __construct){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!dependency_injector) {
		PHALCON_INIT_VAR(dependency_injector);
	}
	
	if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
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
 * @param array $modules
 * @param boolean $merge
 * @param Phalcon\Mvc\Application
 */
PHP_METHOD(Phalcon_Mvc_Application, registerModules){

	zval *modules, *merge = NULL, *registered_modules, *merged_modules;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &modules, &merge) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!merge) {
		PHALCON_INIT_VAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	
	if (Z_TYPE_P(modules) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Modules must be an Array");
		return;
	}
	if (PHALCON_IS_FALSE(merge)) {
		phalcon_update_property_zval(this_ptr, SL("_modules"), modules TSRMLS_CC);
	} else {
		PHALCON_OBS_VAR(registered_modules);
		phalcon_read_property_this(&registered_modules, this_ptr, SL("_modules"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(merged_modules);
		phalcon_fast_array_merge(merged_modules, registered_modules, modules TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_modules"), merged_modules TSRMLS_CC);
	}
	
	
	RETURN_THIS();
}

/**
 * Return the modules registered in the application
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Application, getModules){


	RETURN_MEMBER(this_ptr, "_modules");
}

/**
 * Sets the module name to be used if the router doesn't return a valid module
 *
 * @param string $defaultModule
 */
PHP_METHOD(Phalcon_Mvc_Application, setDefaultModule){

	zval *default_module;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &default_module) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultModule"), default_module TSRMLS_CC);
	
}

/**
 * Returns the default module name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Application, getDefaultModule){


	RETURN_MEMBER(this_ptr, "_defaultModule");
}

/**
 * Handles a MVC request
 *
 * @param string $uri
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Mvc_Application, handle){

	zval *uri = NULL, *dependency_injector, *events_manager;
	zval *service = NULL, *router, *module_name = NULL, *event_name = NULL;
	zval *status = NULL, *modules, *exception_msg = NULL, *module;
	zval *path, *class_name = NULL, *module_object, *module_params;
	zval *view, *namespace_name, *controller_name = NULL;
	zval *action_name = NULL, *params = NULL, *dispatcher, *controller;
	zval *returned_response = NULL, *possible_response;
	zval *response = NULL, *content;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!uri) {
		PHALCON_INIT_VAR(uri);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "router", 1);
	
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD_PARAMS_1(router, dependency_injector, "getshared", service);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(router, "handle", uri);
	
	/** 
	 * Load module config
	 */
	PHALCON_INIT_VAR(module_name);
	PHALCON_CALL_METHOD(module_name, router, "getmodulename");
	
	/** 
	 * If the router doesn't return a valid module we use the default module
	 */
	if (!zend_is_true(module_name)) {
		PHALCON_OBS_NVAR(module_name);
		phalcon_read_property_this(&module_name, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	
	/** 
	 * Process the module definition
	 */
	if (zend_is_true(module_name)) {
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "application:beforeStartModule", 1);
	
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, module_name);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_MM_FALSE;
			}
		}
	
		/** 
		 * Check if the module passed by the router is registered in the modules container
		 */
		PHALCON_OBS_VAR(modules);
		phalcon_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!phalcon_array_isset(modules, module_name)) {
			PHALCON_INIT_VAR(exception_msg);
			PHALCON_CONCAT_SVS(exception_msg, "Module '", module_name, "' isn't registered in the application container");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_application_exception_ce, exception_msg);
			return;
		}
	
		/** 
		 * A module definition must an array or an object
		 */
		PHALCON_OBS_VAR(module);
		phalcon_array_fetch(&module, modules, module_name, PH_NOISY_CC);
		if (Z_TYPE_P(module) != IS_ARRAY) { 
			if (Z_TYPE_P(module) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Invalid module definition");
				return;
			}
		}
	
		/** 
		 * An array module definition contains a path to a module definition class
		 */
		if (Z_TYPE_P(module) == IS_ARRAY) { 
			if (phalcon_array_isset_string(module, SS("path"))) {
	
				PHALCON_OBS_VAR(path);
				phalcon_array_fetch_string(&path, module, SL("path"), PH_NOISY_CC);
				if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
					if (phalcon_require(path TSRMLS_CC) == FAILURE) {
						return;
					}
				} else {
					PHALCON_INIT_NVAR(exception_msg);
					PHALCON_CONCAT_SVS(exception_msg, "Module definition path '", path, "' doesn't exist");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_application_exception_ce, exception_msg);
					return;
				}
			}
	
			/** 
			 * Class name used to load the module definition
			 */
			if (phalcon_array_isset_string(module, SS("className"))) {
				PHALCON_OBS_VAR(class_name);
				phalcon_array_fetch_string(&class_name, module, SL("className"), PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(class_name);
				ZVAL_STRING(class_name, "Module", 1);
			}
	
			PHALCON_INIT_VAR(module_object);
			PHALCON_CALL_METHOD_PARAMS_1(module_object, dependency_injector, "get", class_name);
	
			/** 
			 * Register autoloaders and register services are automatically called
			 */
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(module_object, "registerautoloaders", dependency_injector);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(module_object, "registerservices", dependency_injector);
		} else {
			/** 
			 * A module definition object, can be a Closure instance
			 */
			if (phalcon_is_instance_of(module, SL("Closure") TSRMLS_CC)) {
				PHALCON_INIT_VAR(module_params);
				array_init_size(module_params, 1);
				phalcon_array_append(&module_params, dependency_injector, PH_SEPARATE TSRMLS_CC);
	
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_USER_FUNC_ARRAY(status, module, module_params);
			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Invalid module definition");
				return;
			}
		}
	
		/** 
		 * Calling afterStartModule event
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			phalcon_update_property_zval(this_ptr, SL("_moduleObject"), module_object TSRMLS_CC);
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "application:afterStartModule", 1);
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, module_name);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_MM_FALSE;
			}
		}
	}
	
	PHALCON_INIT_NVAR(service);
	ZVAL_STRING(service, "view", 1);
	
	PHALCON_INIT_VAR(view);
	PHALCON_CALL_METHOD_PARAMS_1(view, dependency_injector, "getshared", service);
	
	/** 
	 * We get the parameters from the router and assign it to the dispatcher
	 */
	PHALCON_INIT_VAR(namespace_name);
	PHALCON_CALL_METHOD(namespace_name, router, "getnamespacename");
	
	PHALCON_INIT_VAR(controller_name);
	PHALCON_CALL_METHOD(controller_name, router, "getcontrollername");
	
	PHALCON_INIT_VAR(action_name);
	PHALCON_CALL_METHOD(action_name, router, "getactionname");
	
	PHALCON_INIT_VAR(params);
	PHALCON_CALL_METHOD(params, router, "getparams");
	
	PHALCON_INIT_NVAR(service);
	ZVAL_STRING(service, "dispatcher", 1);
	
	PHALCON_INIT_VAR(dispatcher);
	PHALCON_CALL_METHOD_PARAMS_1(dispatcher, dependency_injector, "getshared", service);
	
	/** 
	 * Assign the values passed from the router
	 */
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setnamespacename", namespace_name);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollername", controller_name);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setactionname", action_name);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setparams", params);
	
	/** 
	 * Start the view component (start output buffering)
	 */
	PHALCON_CALL_METHOD_NORETURN(view, "start");
	
	/** 
	 * Calling beforeHandleRequest
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:beforeHandleRequest", 1);
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, dispatcher);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * The dispatcher must return an object
	 */
	PHALCON_INIT_VAR(controller);
	PHALCON_CALL_METHOD(controller, dispatcher, "dispatch");
	
	PHALCON_INIT_VAR(returned_response);
	ZVAL_BOOL(returned_response, 0);
	
	/** 
	 * Get the latest value returned by an action
	 */
	PHALCON_INIT_VAR(possible_response);
	PHALCON_CALL_METHOD(possible_response, dispatcher, "getreturnedvalue");
	if (Z_TYPE_P(possible_response) == IS_OBJECT) {
		/** 
		 * Check if the returned object is already a response
		 */
		phalcon_instance_of(returned_response, possible_response, phalcon_http_responseinterface_ce TSRMLS_CC);
	}
	
	/** 
	 * Calling afterHandleRequest
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:afterHandleRequest", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, controller);
	}
	
	/** 
	 * If the dispatcher returns an object we try to render the view in auto-rendering
	 * mode
	 */
	if (PHALCON_IS_FALSE(returned_response)) {
		if (Z_TYPE_P(controller) == IS_OBJECT) {
			PHALCON_INIT_NVAR(controller_name);
			PHALCON_CALL_METHOD(controller_name, dispatcher, "getcontrollername");
	
			PHALCON_INIT_NVAR(action_name);
			PHALCON_CALL_METHOD(action_name, dispatcher, "getactionname");
	
			PHALCON_INIT_NVAR(params);
			PHALCON_CALL_METHOD(params, dispatcher, "getparams");
	
			/** 
			 * Automatic render based on the latest controller executed
			 */
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(view, "render", controller_name, action_name, params);
		}
	}
	
	/** 
	 * Finish the view component (stop output buffering)
	 */
	PHALCON_CALL_METHOD_NORETURN(view, "finish");
	if (PHALCON_IS_FALSE(returned_response)) {
		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "response", 1);
	
		PHALCON_INIT_VAR(response);
		PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "getshared", service);
	
		/** 
		 * The content returned by the view is passed to the response service
		 */
		PHALCON_INIT_VAR(content);
		PHALCON_CALL_METHOD(content, view, "getcontent");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(response, "setcontent", content);
	} else {
		/** 
		 * We don't need to create a response because there is an already created one
		 */
		PHALCON_CPY_WRT(response, possible_response);
	}
	
	/** 
	 * Calling beforeSendResponse
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:beforeSendResponse", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, response);
	}
	
	/** 
	 * Headers are automatically send
	 */
	PHALCON_CALL_METHOD_NORETURN(response, "sendheaders");
	
	/** 
	 * Cookies are automatically send
	 */
	PHALCON_CALL_METHOD_NORETURN(response, "sendcookies");
	
	/** 
	 * Return the response
	 */
	
	RETURN_CCTOR(response);
}

