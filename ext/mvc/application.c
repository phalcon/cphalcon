
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
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
 *		 * Register the services here to make them general or register in the ModuleDefinition to make them module-specific
 *		 *\/
 *		protected function _registerServices()
 *		{
 *
 *		}
 *
 *		/**
 *		 * This method execute the right module
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

	zend_declare_property_null(phalcon_mvc_application_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
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
 */
PHP_METHOD(Phalcon_Mvc_Application, registerModules){

	zval *modules, *merge = NULL, *registered_modules, *merged_modules;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &modules, &merge) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!merge) {
		PHALCON_INIT_NVAR(merge);
		ZVAL_BOOL(merge, 0);
	}
	
	if (Z_TYPE_P(modules) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Modules must be an Array");
		return;
	}
	if (PHALCON_IS_FALSE(merge)) {
		phalcon_update_property_zval(this_ptr, SL("_modules"), modules TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(registered_modules);
		phalcon_read_property(&registered_modules, this_ptr, SL("_modules"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(merged_modules);
		PHALCON_CALL_FUNC_PARAMS_2(merged_modules, "array_merge", registered_modules, modules);
		phalcon_update_property_zval(this_ptr, SL("_modules"), merged_modules TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
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
 * Handles a MVC request
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Mvc_Application, handle){

	zval *dependency_injector, *events_manager;
	zval *service = NULL, *router, *module_name, *event_name = NULL;
	zval *status = NULL, *modules, *exception_msg = NULL, *module;
	zval *path, *class_name = NULL, *module_object, *module_params;
	zval *view, *namespace_name, *controller_name = NULL;
	zval *action_name = NULL, *params = NULL, *dispatcher, *controller;
	zval *response, *content;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "router", 1);
	
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD_PARAMS_1(router, dependency_injector, "getshared", service, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(router, "handle", PH_NO_CHECK);
	
	/** 
	 * Load module config
	 */
	PHALCON_INIT_VAR(module_name);
	PHALCON_CALL_METHOD(module_name, router, "getmodulename", PH_NO_CHECK);
	if (zend_is_true(module_name)) {
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "application:beforeStartModule", 1);
	
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, module_name, PH_NO_CHECK);
			if (PHALCON_IS_FALSE(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	
		/** 
		 * Check if the module passed by the router is registered in the modules container
		 */
		PHALCON_INIT_VAR(modules);
		phalcon_read_property(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(modules, module_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(exception_msg);
			PHALCON_CONCAT_SVS(exception_msg, "Module '", module_name, "' isn't registered in the application container");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_application_exception_ce, exception_msg);
			return;
		}
	
		/** 
		 * A module definition must an array or an object
		 */
		PHALCON_INIT_VAR(module);
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
			eval_int = phalcon_array_isset_string(module, SS("path"));
			if (eval_int) {
				PHALCON_INIT_VAR(path);
				phalcon_array_fetch_string(&path, module, SL("path"), PH_NOISY_CC);
				if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
					if (phalcon_require(path TSRMLS_CC) == FAILURE) {
						return;
					}
				} else {
					PHALCON_INIT_NVAR(exception_msg);
					PHALCON_CONCAT_SVS(exception_msg, "Module definition path '", path, "\" doesn't exists");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_application_exception_ce, exception_msg);
					return;
				}
			}
			eval_int = phalcon_array_isset_string(module, SS("className"));
			if (eval_int) {
				PHALCON_INIT_VAR(class_name);
				phalcon_array_fetch_string(&class_name, module, SL("className"), PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(class_name);
				ZVAL_STRING(class_name, "Module", 1);
			}
	
			PHALCON_INIT_VAR(module_object);
			PHALCON_CALL_METHOD_PARAMS_1(module_object, dependency_injector, "get", class_name, PH_NO_CHECK);
	
			/** 
			 * Register autoloaders and register services are automatically called
			 */
			PHALCON_CALL_METHOD_NORETURN(module_object, "registerautoloaders", PH_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(module_object, "registerservices", dependency_injector, PH_NO_CHECK);
		} else {
			/** 
			 * A module definition object, can be a Closure instance
			 */
			if (phalcon_is_instance_of(module, SL("Closure") TSRMLS_CC)) {
				PHALCON_INIT_VAR(module_params);
				array_init(module_params);
				phalcon_array_append(&module_params, dependency_injector, PH_SEPARATE TSRMLS_CC);
	
				PHALCON_INIT_VAR(r0);
				PHALCON_CALL_USER_FUNC_ARRAY(r0, module, module_params);
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
			PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, module_name, PH_NO_CHECK);
			if (PHALCON_IS_FALSE(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	
	PHALCON_INIT_NVAR(service);
	ZVAL_STRING(service, "view", 1);
	
	PHALCON_INIT_VAR(view);
	PHALCON_CALL_METHOD_PARAMS_1(view, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	/** 
	 * We get the parameters from the router and assign it to the dispatcher
	 */
	PHALCON_INIT_VAR(namespace_name);
	PHALCON_CALL_METHOD(namespace_name, router, "getnamespacename", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(controller_name);
	PHALCON_CALL_METHOD(controller_name, router, "getcontrollername", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(action_name);
	PHALCON_CALL_METHOD(action_name, router, "getactionname", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(params);
	PHALCON_CALL_METHOD(params, router, "getparams", PH_NO_CHECK);
	
	PHALCON_INIT_NVAR(service);
	ZVAL_STRING(service, "dispatcher", 1);
	
	PHALCON_INIT_VAR(dispatcher);
	PHALCON_CALL_METHOD_PARAMS_1(dispatcher, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	/** 
	 * Assign the values passed from the router
	 */
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setnamespacename", namespace_name, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollername", controller_name, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setactionname", action_name, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setparams", params, PH_NO_CHECK);
	
	/** 
	 * Start the view component (start output buffering)
	 */
	PHALCON_CALL_METHOD_NORETURN(view, "start", PH_NO_CHECK);
	
	/** 
	 * Calling beforeHandleRequest
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:beforeHandleRequest", 1);
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, dispatcher, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(controller);
	PHALCON_CALL_METHOD(controller, dispatcher, "dispatch", PH_NO_CHECK);
	
	/** 
	 * Calling afterHandleRequest
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:afterHandleRequest", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, controller, PH_NO_CHECK);
	}
	
	/** 
	 * If the dispatcher returns an object we try to render the view in auto-rendering
	 * mode
	 */
	if (Z_TYPE_P(controller) == IS_OBJECT) {
		PHALCON_INIT_NVAR(controller_name);
		PHALCON_CALL_METHOD(controller_name, dispatcher, "getcontrollername", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(action_name);
		PHALCON_CALL_METHOD(action_name, dispatcher, "getactionname", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(params);
		PHALCON_CALL_METHOD(params, dispatcher, "getparams", PH_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(view, "render", controller_name, action_name, params, PH_NO_CHECK);
	}
	
	/** 
	 * Finish the view component (stop output buffering)
	 */
	PHALCON_CALL_METHOD_NORETURN(view, "finish", PH_NO_CHECK);
	
	PHALCON_INIT_NVAR(service);
	ZVAL_STRING(service, "response", 1);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	/** 
	 * The content returned by the view is passed to the response service
	 */
	PHALCON_INIT_VAR(content);
	PHALCON_CALL_METHOD(content, view, "getcontent", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(response, "setcontent", content, PH_NO_CHECK);
	
	/** 
	 * Calling beforeSendResponse
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:beforeSendResponse", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, response, PH_NO_CHECK);
	}
	
	PHALCON_CALL_METHOD_NORETURN(response, "sendheaders", PH_NO_CHECK);
	
	RETURN_CCTOR(response);
}

