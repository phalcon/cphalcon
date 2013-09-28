
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
 *		/\**
 *		 * Register the services here to make them general or register
 *		 * in the ModuleDefinition to make them module-specific
 *		 *\/
 *		protected function _registerServices()
 *		{
 *
 *		}
 *
 *		/\**
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, Application, mvc_application, phalcon_di_injectable_ce, phalcon_mvc_application_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_application_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_application_ce, SL("_implicitView"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Application
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Application, __construct){

	zval *dependency_injector = NULL;

	phalcon_fetch_params(0, 0, 1, &dependency_injector);
	
	if (!dependency_injector) {
		dependency_injector = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
}

/**
 * By default. The view is implicitly buffering all the output
 * You can full disable the view component using this method
 *
 * @param boolean $implicitView
 * @return Phalcon\Mvc\Application
 */
PHP_METHOD(Phalcon_Mvc_Application, useImplicitView){

	zval *implicit_view;

	phalcon_fetch_params(0, 1, 0, &implicit_view);
	
	phalcon_update_property_this(this_ptr, SL("_implicitView"), implicit_view TSRMLS_CC);
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
 * @param array $modules
 * @param boolean $merge
 * @param Phalcon\Mvc\Application
 */
PHP_METHOD(Phalcon_Mvc_Application, registerModules){

	zval *modules, *merge = NULL, *registered_modules, *merged_modules = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &modules, &merge);
	
	if (!merge) {
		merge = PHALCON_GLOBAL(z_false);
	}
	
	if (Z_TYPE_P(modules) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Modules must be an Array");
		return;
	}
	if (PHALCON_IS_FALSE(merge)) {
		phalcon_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);
	} else {
		PHALCON_OBS_VAR(registered_modules);
		phalcon_read_property_this(&registered_modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (Z_TYPE_P(registered_modules) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_modules);
			phalcon_fast_array_merge(merged_modules, &registered_modules, &modules TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_modules, modules);
		}
	
		phalcon_update_property_this(this_ptr, SL("_modules"), merged_modules TSRMLS_CC);
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
 * @return Phalcon\Mvc\Application
 */
PHP_METHOD(Phalcon_Mvc_Application, setDefaultModule){

	zval *default_module;

	phalcon_fetch_params(0, 1, 0, &default_module);
	
	phalcon_update_property_this(this_ptr, SL("_defaultModule"), default_module TSRMLS_CC);
	RETURN_THISW();
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
	zval *event_name = NULL, *status = NULL, *service = NULL, *router, *module_name = NULL;
	zval *module_object = NULL, *modules, *exception_msg = NULL;
	zval *module, *class_name = NULL, *path, *module_params;
	zval *implicit_view, *view, *namespace_name;
	zval *controller_name = NULL, *action_name = NULL, *params = NULL;
	zval *dispatcher, *controller, *returned_response = NULL;
	zval *possible_response, *render_status = NULL, *response = NULL;
	zval *content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);
	
	if (!uri) {
		uri = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	/** 
	 * Call boot event, this allow the developer to perform initialization actions
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "application:boot", 1);
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p2(status, events_manager, "fire", event_name, this_ptr);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "router", 1);
	
	PHALCON_INIT_VAR(router);
	phalcon_call_method_p1(router, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(router, phalcon_mvc_routerinterface_ce);
	
	/** 
	 * Handle the URI pattern (if any)
	 */
	phalcon_call_method_p1_noret(router, "handle", uri);
	
	/** 
	 * Load module config
	 */
	PHALCON_INIT_VAR(module_name);
	phalcon_call_method(module_name, router, "getmodulename");
	
	/** 
	 * If the router doesn't return a valid module we use the default module
	 */
	if (!zend_is_true(module_name)) {
		PHALCON_OBS_NVAR(module_name);
		phalcon_read_property_this(&module_name, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(module_object);
	
	/** 
	 * Process the module definition
	 */
	if (zend_is_true(module_name)) {
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "application:beforeStartModule", 1);
	
			PHALCON_INIT_NVAR(status);
			phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, module_name);
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
		 * A module definition must ne an array or an object
		 */
		PHALCON_OBS_VAR(module);
		phalcon_array_fetch(&module, modules, module_name, PH_NOISY);
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
	
			/** 
			 * Class name used to load the module definition
			 */
			if (phalcon_array_isset_string(module, SS("className"))) {
				PHALCON_OBS_VAR(class_name);
				phalcon_array_fetch_string(&class_name, module, SL("className"), PH_NOISY);
			} else {
				PHALCON_INIT_NVAR(class_name);
				ZVAL_STRING(class_name, "Module", 1);
			}
	
			/** 
			 * If developer specify a path try to include the file
			 */
			if (phalcon_array_isset_string(module, SS("path"))) {
	
				PHALCON_OBS_VAR(path);
				phalcon_array_fetch_string(&path, module, SL("path"), PH_NOISY);
				if (!phalcon_class_exists(class_name, 0 TSRMLS_CC)) {
					if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
						if (phalcon_require(path TSRMLS_CC) == FAILURE) {
							RETURN_MM();
						}
					} else {
						PHALCON_INIT_NVAR(exception_msg);
						PHALCON_CONCAT_SVS(exception_msg, "Module definition path '", path, "' doesn't exist");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_application_exception_ce, exception_msg);
						return;
					}
				}
			}
	
			phalcon_call_method_p1(module_object, dependency_injector, "get", class_name);
	
			/** 
			 * 'registerAutoloaders' and 'registerServices' are automatically called
			 */
			phalcon_call_method_p1_noret(module_object, "registerautoloaders", dependency_injector);
			phalcon_call_method_p1_noret(module_object, "registerservices", dependency_injector);
		} else {
			/** 
			 * A module definition object, can be a Closure instance
			 */
			if (phalcon_is_instance_of(module, SL("Closure") TSRMLS_CC)) {
				PHALCON_INIT_VAR(module_params);
				array_init_size(module_params, 1);
				phalcon_array_append(&module_params, dependency_injector, PH_SEPARATE);
	
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
			phalcon_update_property_this(this_ptr, SL("_moduleObject"), module_object TSRMLS_CC);
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "application:afterStartModule", 1);
	
			PHALCON_INIT_NVAR(status);
			phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, module_name);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_MM_FALSE;
			}
		}
	}
	
	/** 
	 * Check whether use implicit views or not
	 */
	PHALCON_OBS_VAR(implicit_view);
	phalcon_read_property_this(&implicit_view, this_ptr, SL("_implicitView"), PH_NOISY_CC);
	if (PHALCON_IS_TRUE(implicit_view)) {
		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "view", 1);
	
		PHALCON_INIT_VAR(view);
		phalcon_call_method_p1(view, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(view, phalcon_mvc_viewinterface_ce);
	}
	
	/** 
	 * We get the parameters from the router and assign them to the dispatcher
	 */
	PHALCON_INIT_NVAR(module_name);
	phalcon_call_method(module_name, router, "getmodulename");
	
	PHALCON_INIT_VAR(namespace_name);
	phalcon_call_method(namespace_name, router, "getnamespacename");
	
	PHALCON_INIT_VAR(controller_name);
	phalcon_call_method(controller_name, router, "getcontrollername");
	
	PHALCON_INIT_VAR(action_name);
	phalcon_call_method(action_name, router, "getactionname");
	
	PHALCON_INIT_VAR(params);
	phalcon_call_method(params, router, "getparams");
	
	PHALCON_INIT_NVAR(service);
	ZVAL_STRING(service, "dispatcher", 1);
	
	PHALCON_INIT_VAR(dispatcher);
	phalcon_call_method_p1(dispatcher, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(dispatcher, phalcon_dispatcherinterface_ce);
	
	/** 
	 * Assign the values passed from the router
	 */
	phalcon_call_method_p1_noret(dispatcher, "setmodulename", module_name);
	phalcon_call_method_p1_noret(dispatcher, "setnamespacename", namespace_name);
	phalcon_call_method_p1_noret(dispatcher, "setcontrollername", controller_name);
	phalcon_call_method_p1_noret(dispatcher, "setactionname", action_name);
	phalcon_call_method_p1_noret(dispatcher, "setparams", params);
	
	/** 
	 * Start the view component (start output buffering)
	 */
	if (PHALCON_IS_TRUE(implicit_view)) {
		phalcon_call_method_noret(view, "start");
	}
	
	/** 
	 * Calling beforeHandleRequest
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:beforeHandleRequest", 1);
	
		PHALCON_INIT_NVAR(status);
		phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, dispatcher);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * The dispatcher must return an object
	 */
	PHALCON_INIT_VAR(controller);
	phalcon_call_method(controller, dispatcher, "dispatch");
	
	PHALCON_INIT_VAR(returned_response);
	
	/** 
	 * Get the latest value returned by an action
	 */
	PHALCON_INIT_VAR(possible_response);
	phalcon_call_method(possible_response, dispatcher, "getreturnedvalue");
	if (Z_TYPE_P(possible_response) == IS_OBJECT) {
		/** 
		 * Check if the returned object is already a response
		 */
		phalcon_instance_of(returned_response, possible_response, phalcon_http_responseinterface_ce TSRMLS_CC);
	}
	else {
		ZVAL_FALSE(returned_response);
	}
	
	/** 
	 * Calling afterHandleRequest
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:afterHandleRequest", 1);
		phalcon_call_method_p3_noret(events_manager, "fire", event_name, this_ptr, controller);
	}
	
	/** 
	 * If the dispatcher returns an object we try to render the view in auto-rendering
	 * mode
	 */
	if (PHALCON_IS_FALSE(returned_response)) {
		if (PHALCON_IS_TRUE(implicit_view)) {
	
			if (Z_TYPE_P(controller) == IS_OBJECT) {
	
				PHALCON_INIT_VAR(render_status);
	
				/** 
				 * This allows to make a custom view render
				 */
				if (Z_TYPE_P(events_manager) == IS_OBJECT) {
					PHALCON_INIT_NVAR(event_name);
					ZVAL_STRING(event_name, "application:viewRender", 1);
	
					phalcon_call_method_p3(render_status, events_manager, "fire", event_name, this_ptr, view);
				}
				else {
					ZVAL_TRUE(render_status);
				}
	
				/** 
				 * Check if the view process has been treated by the developer
				 */
				if (PHALCON_IS_NOT_FALSE(render_status)) {
					PHALCON_INIT_NVAR(controller_name);
					phalcon_call_method(controller_name, dispatcher, "getcontrollername");
	
					PHALCON_INIT_NVAR(action_name);
					phalcon_call_method(action_name, dispatcher, "getactionname");
	
					PHALCON_INIT_NVAR(params);
					phalcon_call_method(params, dispatcher, "getparams");
	
					/** 
					 * Automatic render based on the latest controller executed
					 */
					phalcon_call_method_p3_noret(view, "render", controller_name, action_name, params);
				}
			}
		}
	}
	
	/** 
	 * Finish the view component (stop output buffering)
	 */
	if (PHALCON_IS_TRUE(implicit_view)) {
		phalcon_call_method_noret(view, "finish");
	}
	
	if (PHALCON_IS_FALSE(returned_response)) {
	
		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "response", 1);
	
		PHALCON_INIT_VAR(response);
		phalcon_call_method_p1(response, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(response, phalcon_http_responseinterface_ce);
		if (PHALCON_IS_TRUE(implicit_view)) {
			/** 
			 * The content returned by the view is passed to the response service
			 */
			PHALCON_INIT_VAR(content);
			phalcon_call_method(content, view, "getcontent");
			phalcon_call_method_p1_noret(response, "setcontent", content);
		}
	} else {
		/** 
		 * We don't need to create a response because there is a one already created
		 */
		PHALCON_CPY_WRT(response, possible_response);
	}
	
	/** 
	 * Calling beforeSendResponse
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:beforeSendResponse", 1);
		phalcon_call_method_p3_noret(events_manager, "fire", event_name, this_ptr, response);
	}
	
	/** 
	 * Headers are automatically send
	 */
	phalcon_call_method_noret(response, "sendheaders");
	
	/** 
	 * Cookies are automatically send
	 */
	phalcon_call_method_noret(response, "sendcookies");
	
	/** 
	 * Return the response
	 */
	
	RETURN_CCTOR(response);
}

