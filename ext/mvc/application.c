
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/application.h"
#include "mvc/application/exception.h"
#include "mvc/dispatcherinterface.h"
#include "mvc/../dispatcherinterface.h"
#include "mvc/routerinterface.h"
#include "mvc/viewinterface.h"
#include "mvc/view/modelinterface.h"
#include "di/injectable.h"
#include "diinterface.h"
#include "events/managerinterface.h"
#include "http/responseinterface.h"

#include <Zend/zend_closures.h>

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

#include "interned-strings.h"

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
zend_class_entry *phalcon_mvc_application_ce;

PHP_METHOD(Phalcon_Mvc_Application, __construct);
PHP_METHOD(Phalcon_Mvc_Application, useImplicitView);
PHP_METHOD(Phalcon_Mvc_Application, registerModules);
PHP_METHOD(Phalcon_Mvc_Application, getModules);
PHP_METHOD(Phalcon_Mvc_Application, setDefaultModule);
PHP_METHOD(Phalcon_Mvc_Application, getDefaultModule);
PHP_METHOD(Phalcon_Mvc_Application, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_useimplicitview, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_registermodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_application_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Application, __construct, arginfo_phalcon_mvc_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Application, useImplicitView, arginfo_phalcon_mvc_application_useimplicitview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, registerModules, arginfo_phalcon_mvc_application_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, setDefaultModule, arginfo_phalcon_mvc_application_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, handle, arginfo_phalcon_mvc_application_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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

	if (dependency_injector) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "setdi", dependency_injector);
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
		phalcon_read_property_this(&registered_modules, this_ptr, SL("_modules"), PH_NOISY TSRMLS_CC);
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

	zval *uri = NULL, *dependency_injector = NULL, *event_name = NULL;
	zval *status = NULL, *service = NULL, *router = NULL, *module_name = NULL;
	zval *module_object = NULL, *modules;
	zval *module, *class_name = NULL, *module_params;
	zval *implicit_view, *view = NULL, *namespace_name = NULL;
	zval *controller_name = NULL, *action_name = NULL, *params = NULL, *exact = NULL;
	zval *dispatcher = NULL, *controller = NULL, *returned_response = NULL;
	zval *possible_response = NULL, *response = NULL;
	zval *content = NULL, *path;
	int f_implicit_view;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_METHOD(&dependency_injector, this_ptr, "getdi");

	/* Call boot event, this allows the developer to perform initialization actions */
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "application:boot", 1);
	PHALCON_CALL_METHOD(&status, this_ptr, "fireevent", event_name);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	PHALCON_INIT_VAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_router);
	PHALCON_CALL_METHOD(&router, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(router, phalcon_mvc_routerinterface_ce);

	/* Handle the URI pattern (if any) */
	PHALCON_CALL_METHOD(NULL, router, "handle", uri);

	/* Load module config */
	PHALCON_CALL_METHOD(&module_name, router, "getmodulename");

	/* If the router doesn't return a valid module we use the default module */
	if (!zend_is_true(module_name)) {
		PHALCON_OBS_NVAR(module_name);
		phalcon_read_property_this(&module_name, this_ptr, SL("_defaultModule"), PH_NOISY TSRMLS_CC);
	}

	/** 
	 * Process the module definition
	 */
	if (zend_is_true(module_name)) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:beforeStartModule", 1);

		Z_SET_ISREF_P(module_name);
		PHALCON_CALL_METHOD(&status, this_ptr, "fireevent", event_name, module_name);
		Z_UNSET_ISREF_P(module_name);

		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}

		/** 
		 * Check if the module passed by the router is registered in the modules container
		 */
		PHALCON_OBS_VAR(modules);
		phalcon_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY TSRMLS_CC);
		if (!phalcon_array_isset_fetch(&module, modules, module_name)) {
			convert_to_string(module_name);
			zend_throw_exception_ex(phalcon_mvc_application_exception_ce, 0 TSRMLS_CC, "Module %s is not registered in the application container", Z_STRVAL_P(module_name));
			RETURN_MM();
		}

		/** 
		 * A module definition must be an array or an object
		 */
		if (Z_TYPE_P(module) != IS_ARRAY && Z_TYPE_P(module) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Invalid module definition");
			return;
		}

		/* An array module definition contains a path to a module definition class */
		if (Z_TYPE_P(module) == IS_ARRAY) { 
			/* Class name used to load the module definition */
			if (phalcon_array_isset_string(module, SS("className"))) {
				PHALCON_OBS_VAR(class_name);
				phalcon_array_fetch_string(&class_name, module, SL("className"), PH_NOISY);
			} else {
				PHALCON_INIT_NVAR(class_name);
				ZVAL_STRING(class_name, "Module", 1);
			}

			/* If the developer has specified a path, try to include the file */
			if (phalcon_array_isset_string(module, SS("path"))) {

				PHALCON_OBS_VAR(path);
				phalcon_array_fetch_string(&path, module, SL("path"), PH_NOISY);
				convert_to_string_ex(&path);
				if (Z_TYPE_P(class_name) != IS_STRING || !phalcon_class_exists(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), 0 TSRMLS_CC)) {
					if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
						RETURN_MM_ON_FAILURE(phalcon_require(Z_STRVAL_P(path) TSRMLS_CC));
					} else {
						zend_throw_exception_ex(phalcon_mvc_application_exception_ce, 0 TSRMLS_CC, "Module definition path '%s' does not exist", Z_STRVAL_P(path));
						RETURN_MM();
					}
				}
			}

			PHALCON_CALL_METHOD(&module_object, dependency_injector, "get", class_name);

			/** 
			 * 'registerAutoloaders' and 'registerServices' are automatically called
			 */
			PHALCON_CALL_METHOD(NULL, module_object, "registerautoloaders", dependency_injector);
			PHALCON_CALL_METHOD(NULL, module_object, "registerservices", dependency_injector);
		} else if (Z_TYPE_P(module) == IS_OBJECT && instanceof_function(Z_OBJCE_P(module), zend_ce_closure TSRMLS_CC)) {
			/* A module definition object, can be a Closure instance */
			PHALCON_INIT_VAR(module_params);
			array_init_size(module_params, 1);
			phalcon_array_append(&module_params, dependency_injector, PH_COPY);

			PHALCON_INIT_NVAR(status);/**/
			PHALCON_CALL_USER_FUNC_ARRAY(status, module, module_params);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Invalid module definition");
			return;
		}

		/* Calling afterStartModule event */
		if (!module_object) {
			module_object = PHALCON_GLOBAL(z_null);
		}

		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "application:afterStartModule", 1);

		Z_SET_ISREF_P(module_name);
		PHALCON_CALL_METHOD(&status, this_ptr, "fireevent", event_name, module_name);
		Z_UNSET_ISREF_P(module_name);

		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}

	/** 
	 * Check whether use implicit views or not
	 */
	implicit_view = phalcon_fetch_nproperty_this(this_ptr, SL("_implicitView"), PH_NOISY TSRMLS_CC);

	/*
	 * The safe way is to use a flag because it *might* be possible to alter the value
	 * of _implicitView later which might result in crashes because 'view'
	 * is initialized only when _implicitView evaluates to false
	 */
	f_implicit_view = PHALCON_IS_TRUE(implicit_view);

	if (f_implicit_view) {
		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "view", 1);

		PHALCON_CALL_METHOD(&view, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(view, phalcon_mvc_viewinterface_ce);
	}

	/* We get the parameters from the router and assign them to the dispatcher */
	PHALCON_CALL_METHOD(&module_name, router, "getmodulename");
	PHALCON_CALL_METHOD(&namespace_name, router, "getnamespacename");
	PHALCON_CALL_METHOD(&controller_name, router, "getcontrollername");
	PHALCON_CALL_METHOD(&action_name, router, "getactionname");
	PHALCON_CALL_METHOD(&params, router, "getparams");
	PHALCON_CALL_METHOD(&exact, router, "isexactcontrollername");

	PHALCON_INIT_NVAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_dispatcher);

	PHALCON_CALL_METHOD(&dispatcher, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(dispatcher, phalcon_dispatcherinterface_ce);

	/* Assign the values passed from the router */
	PHALCON_CALL_METHOD(NULL, dispatcher, "setmodulename", module_name);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setnamespacename", namespace_name);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setcontrollername", controller_name, exact);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setactionname", action_name);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setparams", params);

	if (f_implicit_view) {
		/** 
		 * Start the view component (start output buffering)
		 */
		PHALCON_CALL_METHOD(NULL, view, "start");
	}

	/* Calling beforeHandleRequest */
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "application:beforeHandleRequest", 1);

	Z_SET_ISREF_P(dispatcher);
	PHALCON_CALL_METHOD(&status, this_ptr, "fireevent", event_name, dispatcher);
	Z_UNSET_ISREF_P(dispatcher);

	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	/* The dispatcher must return an object */
	PHALCON_CALL_METHOD(&controller, dispatcher, "dispatch");

	/* Calling afterHandleRequest */
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "application:afterHandleRequest", 1);

	Z_SET_ISREF_P(controller);
	PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name, controller);
	Z_UNSET_ISREF_P(controller);

	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	if (f_implicit_view) {
		/* Get the latest value returned by an action */
		PHALCON_CALL_METHOD(&possible_response, dispatcher, "getreturnedvalue");

		PHALCON_INIT_VAR(returned_response);

		/* Check if the returned object is already a response */
		if (Z_TYPE_P(possible_response) == IS_OBJECT && instanceof_function_ex(Z_OBJCE_P(possible_response), phalcon_http_responseinterface_ce, 1 TSRMLS_CC)) {
			PHALCON_CPY_WRT(response, possible_response);
			ZVAL_TRUE(returned_response);
		} else {
			PHALCON_INIT_NVAR(service);
			PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_response);

			PHALCON_CALL_METHOD(&response, dependency_injector, "getshared", service);
			PHALCON_VERIFY_INTERFACE(response, phalcon_http_responseinterface_ce);

			if (Z_TYPE_P(possible_response) == IS_BOOL && !zend_is_true(possible_response)) {
				RETURN_CCTOR(response);
			}

			ZVAL_FALSE(returned_response);
		}
		
		if (PHALCON_IS_FALSE(returned_response)) {

			if (Z_TYPE_P(controller) == IS_OBJECT) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "application:beforeRenderView", 1);

				Z_SET_ISREF_P(view);
				PHALCON_CALL_METHOD(&status, this_ptr, "fireeventcancel", event_name, view);
				Z_UNSET_ISREF_P(view);

				/* Check if the view process has been treated by the developer */
				if (PHALCON_IS_NOT_FALSE(status)) {
					PHALCON_CALL_METHOD(&namespace_name, dispatcher, "getnamespacename");
					PHALCON_CALL_METHOD(&controller_name, dispatcher, "getcontrollername");
					PHALCON_CALL_METHOD(&action_name, dispatcher, "getactionname");
					PHALCON_CALL_METHOD(&params, dispatcher, "getparams");

					/* Automatic render based on the latest controller executed */
					if (Z_TYPE_P(possible_response) == IS_OBJECT && instanceof_function_ex(Z_OBJCE_P(possible_response), phalcon_mvc_view_modelinterface_ce, 1 TSRMLS_CC)) {
						PHALCON_CALL_METHOD(NULL, view, "render", controller_name, action_name, params, namespace_name, possible_response);
					} else {
						if (Z_TYPE_P(possible_response) == IS_ARRAY) {
							PHALCON_CALL_METHOD(NULL, view, "setvars", possible_response, PHALCON_GLOBAL(z_true));
						}
						/* Automatic render based on the latest controller executed */
						PHALCON_CALL_METHOD(NULL, view, "render", controller_name, action_name, params, namespace_name);
					}
				}

				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "application:afterRenderView", 1);

				Z_SET_ISREF_P(view);
				PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name, view);
				Z_UNSET_ISREF_P(view);
			}
		}
	} else {		
		PHALCON_INIT_NVAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_response);

		PHALCON_CALL_METHOD(&response, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(response, phalcon_http_responseinterface_ce);
	}

	/* Calling beforeSendResponse */
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "application:beforeSendResponse", 1);

	Z_SET_ISREF_P(response);
	PHALCON_CALL_METHOD(&status, this_ptr, "fireevent", event_name, response);
	Z_UNSET_ISREF_P(response);

	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}

	if (f_implicit_view) {
		PHALCON_CALL_METHOD(NULL, view, "finish");

		if (PHALCON_IS_FALSE(returned_response)) {
			/* The content returned by the view is passed to the response service */
			PHALCON_CALL_METHOD(&content, view, "getcontent");
			PHALCON_CALL_METHOD(NULL, response, "setcontent", content);
		}
	}

	/* Headers are automatically sent */
	PHALCON_CALL_METHOD(NULL, response, "sendheaders");

	/* Cookies are automatically sent */
	PHALCON_CALL_METHOD(NULL, response, "sendcookies");

	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "application:afterSendResponse", 1);

	Z_SET_ISREF_P(response);
	PHALCON_CALL_METHOD(NULL, this_ptr, "fireevent", event_name, response);
	Z_UNSET_ISREF_P(response);

	/* Return the response */
	RETURN_CCTOR(response);
}
