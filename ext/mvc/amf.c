
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
  |          Antonio Lopez <alantonilopez@gmail.com>                       |
  +------------------------------------------------------------------------+
*/

#include "mvc/amf.h"
#include "mvc/amf/exception.h"
#include "mvc/dispatcherinterface.h"
#include "mvc/../dispatcherinterface.h"
#include "mvc/routerinterface.h"
#include "amf/deserializer.h"
#include "http/requestinterface.h"
#include "mvc/urlinterface.h"
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
 * Phalcon\Mvc\Amf
 *
 * This component encapsulates all the complex operations behind instantiating every component
 * needed and integrating it with the rest to allow the MVC pattern to operate as desired.
 *
 *<code>
 *
 * class Amf extends \Phalcon\Mvc\Amf
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
 *		 * This method registers all the modules in the amf
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
 *	$amf = new Amf();
 *	$amf->main();
 *
 *</code>
 */
zend_class_entry *phalcon_mvc_amf_ce;

PHP_METHOD(Phalcon_Mvc_Amf, __construct);
PHP_METHOD(Phalcon_Mvc_Amf, registerModules);
PHP_METHOD(Phalcon_Mvc_Amf, getModules);
PHP_METHOD(Phalcon_Mvc_Amf, setDefaultModule);
PHP_METHOD(Phalcon_Mvc_Amf, getDefaultModule);
PHP_METHOD(Phalcon_Mvc_Amf, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_amf___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_amf_registermodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_amf_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_amf_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Amf, __construct, arginfo_phalcon_mvc_amf___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Amf, registerModules, arginfo_phalcon_mvc_amf_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Amf, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Amf, setDefaultModule, arginfo_phalcon_mvc_amf_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Amf, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Amf, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Amf initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Amf){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, Amf, mvc_amf, phalcon_di_injectable_ce, phalcon_mvc_amf_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_amf_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_amf_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_amf_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Amf
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Amf, __construct){

	zval *dependency_injector = NULL;

	phalcon_fetch_params(0, 0, 1, &dependency_injector);
	
	if (dependency_injector && Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_amf_exception_ce, 0);
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
}

/**
 * Register an array of modules present in the amf
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
 * @param Phalcon\Mvc\Amf
 */
PHP_METHOD(Phalcon_Mvc_Amf, registerModules){

	zval *modules, *merge = NULL, *registered_modules, *merged_modules = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &modules, &merge);
	
	if (!merge) {
		merge = PHALCON_GLOBAL(z_false);
	}
	
	if (Z_TYPE_P(modules) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_amf_exception_ce, "Modules must be an Array");
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
 * Return the modules registered in the amf
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Amf, getModules){


	RETURN_MEMBER(this_ptr, "_modules");
}

/**
 * Sets the module name to be used if the router doesn't return a valid module
 *
 * @param string $defaultModule
 * @return Phalcon\Mvc\Amf
 */
PHP_METHOD(Phalcon_Mvc_Amf, setDefaultModule){

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
PHP_METHOD(Phalcon_Mvc_Amf, getDefaultModule){


	RETURN_MEMBER(this_ptr, "_defaultModule");
}

static int phalcon_mvc_amf_fire_event(zval *mgr, const char *event, zval *this_ptr, zval *params TSRMLS_DC)
{
	if (mgr) {
		zval *event_name;
		zval *status = NULL;
		uint params_cnt = 2 + (params != NULL ? 1 : 0);
		zval *p[3];

		PHALCON_ALLOC_GHOST_ZVAL(event_name);
		ZVAL_STRING(event_name, event, 1);

		p[0] = event_name;
		p[1] = this_ptr;
		p[2] = params;

		if (FAILURE == phalcon_call_method(&status, mgr, "fire", params_cnt, p TSRMLS_CC)) {
			return FAILURE;
		}

		return (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) ? FAILURE : SUCCESS;
	}

	return SUCCESS;
}

/**
 * Handles a MVC request
 *
 * @param string $uri
 * @return Phalcon\Http\ResponseInterface
 */
PHP_METHOD(Phalcon_Mvc_Amf, handle){

	zval *uri = NULL, *dependency_injector, *events_manager;
	zval *status = NULL, *service = NULL, *request = NULL, *amf = NULL, *deserializer, *packet = NULL, *postion, *data, *message = NULL, *target = NULL;
	zval *url = NULL, *router = NULL, *module_name = NULL;
	zval *module_object = NULL, *modules;
	zval *module, *class_name = NULL, *module_params;
	zval *namespace_name = NULL;
	zval *controller_name = NULL, *action_name = NULL, *params = NULL, *exact = NULL;
	zval *dispatcher = NULL, *controller = NULL, *returned_response = NULL;
	zval *possible_response = NULL, *response = NULL;
	zval *path;

	PHALCON_MM_GROW();
	
	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_amf_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	
	events_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) != IS_OBJECT) {
		events_manager = NULL;
	}
	else {
		PHALCON_VERIFY_INTERFACE_EX(events_manager, phalcon_events_managerinterface_ce, phalcon_mvc_amf_exception_ce, 1);
	}

	/* Call boot event, this allows the developer to perform initialization actions */
	if (FAILURE == phalcon_mvc_amf_fire_event(events_manager, "amf:boot", getThis(), NULL TSRMLS_CC)) {
		RETURN_MM_FALSE;
	}

	/* Deserializer AMF3 */

	PHALCON_INIT_NVAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_request);
	
	PHALCON_CALL_METHOD(&request, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(request, phalcon_http_requestinterface_ce);

	PHALCON_CALL_METHOD(&amf, request, "getrawbody");

	PHALCON_INIT_VAR(deserializer);
	object_init_ex(deserializer, phalcon_amf_deserializer_ce);
	PHALCON_CALL_METHOD(NULL, deserializer, "__construct", amf);

	PHALCON_INIT_VAR(postion);
	ZVAL_LONG(postion, 0);

	PHALCON_CALL_METHOD(&packet, deserializer, "getpacket");

	PHALCON_CALL_METHOD(&message, packet, "getmessage", postion);

	PHALCON_INIT_VAR(data);
	array_init(data);

	if (Z_TYPE_P(message) != IS_NULL) {
		phalcon_array_append(&data, message, 0);
		PHALCON_CALL_METHOD(&target, message, "gettarget");

		PHALCON_INIT_NVAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_url);
		PHALCON_CALL_METHOD(&url, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(url, phalcon_mvc_urlinterface_ce);

		PHALCON_CALL_METHOD(&uri, url, "get", target);
	}

	PHALCON_INIT_NVAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_router);
	PHALCON_CALL_METHOD(&router, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(router, phalcon_mvc_routerinterface_ce);
	
	/* Handle the URI pattern (if any) */
	PHALCON_CALL_METHOD(NULL, router, "handle", uri);
	
	/* Load module config */
	PHALCON_CALL_METHOD(&module_name, router, "getmodulename");

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
		if (FAILURE == phalcon_mvc_amf_fire_event(events_manager, "amf:beforeStartModule", getThis(), module_name TSRMLS_CC)) {
			RETURN_MM_FALSE;
		}

		/** 
		 * Check if the module passed by the router is registered in the modules container
		 */
		PHALCON_OBS_VAR(modules);
		phalcon_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY TSRMLS_CC);
		if (!phalcon_array_isset_fetch(&module, modules, module_name)) {
			convert_to_string(module_name);
			zend_throw_exception_ex(phalcon_mvc_amf_exception_ce, 0 TSRMLS_CC, "Module %s is not registered in the amf container", Z_STRVAL_P(module_name));
			RETURN_MM();
		}
	
		/** 
		 * A module definition must be an array or an object
		 */
		if (Z_TYPE_P(module) != IS_ARRAY && Z_TYPE_P(module) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_amf_exception_ce, "Invalid module definition");
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
						zend_throw_exception_ex(phalcon_mvc_amf_exception_ce, 0 TSRMLS_CC, "Module definition path '%s' does not exist", Z_STRVAL_P(path));
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
			phalcon_array_append(&module_params, dependency_injector, 0);

			PHALCON_INIT_NVAR(status);/**/
			PHALCON_CALL_USER_FUNC_ARRAY(status, module, module_params);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_amf_exception_ce, "Invalid module definition");
			return;
		}
	
		/* Calling afterStartModule event */
		if (events_manager) {
			if (!module_object) {
				module_object = PHALCON_GLOBAL(z_null);
			}

			phalcon_update_property_this(this_ptr, SL("_moduleObject"), module_object TSRMLS_CC);
			if (FAILURE == phalcon_mvc_amf_fire_event(events_manager, "amf:afterStartModule", getThis(), module_name TSRMLS_CC)) {
				RETURN_MM_FALSE;
			}
		}
	}
	
	/* We get the parameters from the router and assign them to the dispatcher */
	PHALCON_CALL_METHOD(&module_name, router, "getmodulename");
	PHALCON_CALL_METHOD(&namespace_name, router, "getnamespacename");
	PHALCON_CALL_METHOD(&controller_name, router, "getcontrollername");
	PHALCON_CALL_METHOD(&action_name, router, "getactionname");
	PHALCON_CALL_METHOD(&params, router, "getparams");
	PHALCON_CALL_METHOD(&exact, router, "isexactcontrollername");

	phalcon_merge_append(data, params);

	PHALCON_INIT_NVAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_dispatcher);
	
	PHALCON_CALL_METHOD(&dispatcher, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(dispatcher, phalcon_dispatcherinterface_ce);
	
	/* Assign the values passed from the router */
	PHALCON_CALL_METHOD(NULL, dispatcher, "setmodulename", module_name);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setnamespacename", namespace_name);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setcontrollername", controller_name, exact);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setactionname", action_name);
	PHALCON_CALL_METHOD(NULL, dispatcher, "setparams", data);
	
	/* Calling beforeHandleRequest */
	RETURN_MM_ON_FAILURE(phalcon_mvc_amf_fire_event(events_manager, "amf:beforeHandleRequest", getThis(), dispatcher TSRMLS_CC));
	
	/* The dispatcher must return an object */
	PHALCON_CALL_METHOD(&controller, dispatcher, "dispatch");
	
	PHALCON_INIT_VAR(returned_response);
	
	/* Get the latest value returned by an action */
	PHALCON_CALL_METHOD(&possible_response, dispatcher, "getreturnedvalue");
	if (Z_TYPE_P(possible_response) == IS_OBJECT) {
		/* Check if the returned object is already a response */
		ZVAL_BOOL(returned_response, instanceof_function_ex(Z_OBJCE_P(possible_response), phalcon_http_responseinterface_ce, 1 TSRMLS_CC));
	}
	else {
		ZVAL_FALSE(returned_response);
	}
	
	/* Calling afterHandleRequest */
	if (FAILURE == phalcon_mvc_amf_fire_event(events_manager, "amf:afterHandleRequest", getThis(), controller TSRMLS_CC) && EG(exception)) {
		RETURN_MM();
	}
	
	if (PHALCON_IS_FALSE(returned_response)) {
		PHALCON_INIT_NVAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_response);
	
		PHALCON_CALL_METHOD(&response, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(response, phalcon_http_responseinterface_ce);
	} else {
		/* We don't need to create a response because there is a one already created */
		PHALCON_CPY_WRT(response, possible_response);
	}
	

	/* Calling beforeSendResponse */
	if (FAILURE == phalcon_mvc_amf_fire_event(events_manager, "amf:beforeSendResponse", getThis(), response TSRMLS_CC) && EG(exception)) {
		RETURN_MM();
	}
	
	/* Headers are automatically sent */
	PHALCON_CALL_METHOD(NULL, response, "sendheaders");
	
	/* Cookies are automatically sent */
	PHALCON_CALL_METHOD(NULL, response, "sendcookies");
	
	/* Return the response */
	RETURN_CCTOR(response);
}
