
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "mvc/jsonrpc.h"
#include "mvc/jsonrpc/exception.h"
#include "mvc/dispatcherinterface.h"
#include "mvc/../dispatcherinterface.h"
#include "mvc/routerinterface.h"
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
 * Phalcon\Mvc\JsonRpc
 *
 * This component encapsulates all the complex operations behind instantiating every component
 * needed and integrating it with the rest to allow the MVC pattern to operate as desired.
 *
 *<code>
 *
 *	$jsonrpc = new \Phalcon\Mvc\JsonRpc($di);
 *	echo $jsonrpc->handle()->getContent();
 *
 *</code>
 */
zend_class_entry *phalcon_mvc_jsonrpc_ce;

PHP_METHOD(Phalcon_Mvc_JsonRpc, __construct);
PHP_METHOD(Phalcon_Mvc_JsonRpc, registerModules);
PHP_METHOD(Phalcon_Mvc_JsonRpc, getModules);
PHP_METHOD(Phalcon_Mvc_JsonRpc, setDefaultModule);
PHP_METHOD(Phalcon_Mvc_JsonRpc, getDefaultModule);
PHP_METHOD(Phalcon_Mvc_JsonRpc, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_jsonrpc___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_jsonrpc_registermodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_jsonrpc_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_jsonrpc_method_entry[] = {
	PHP_ME(Phalcon_Mvc_JsonRpc, __construct, arginfo_phalcon_mvc_jsonrpc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_JsonRpc, registerModules, arginfo_phalcon_mvc_jsonrpc_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_JsonRpc, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_JsonRpc, setDefaultModule, arginfo_phalcon_mvc_jsonrpc_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_JsonRpc, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_JsonRpc, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\JsonRpc initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_JsonRpc){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, JsonRpc, mvc_jsonrpc, phalcon_di_injectable_ce, phalcon_mvc_jsonrpc_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_jsonrpc_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_jsonrpc_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_jsonrpc_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\JsonRpc
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_JsonRpc, __construct){

	zval *dependency_injector = NULL;

	phalcon_fetch_params(0, 0, 1, &dependency_injector);
	
	if (dependency_injector && Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_jsonrpc_exception_ce, 0);
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
}

/**
 * Register an array of modules present in the jsonrpc
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
 * @param Phalcon\Mvc\JsonRpc
 */
PHP_METHOD(Phalcon_Mvc_JsonRpc, registerModules){

	zval *modules, *merge = NULL, *registered_modules, *merged_modules = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &modules, &merge);
	
	if (!merge) {
		merge = PHALCON_GLOBAL(z_false);
	}
	
	if (Z_TYPE_P(modules) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_jsonrpc_exception_ce, "Modules must be an Array");
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
 * Return the modules registered in the jsonrpc
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_JsonRpc, getModules){


	RETURN_MEMBER(this_ptr, "_modules");
}

/**
 * Sets the module name to be used if the router doesn't return a valid module
 *
 * @param string $defaultModule
 * @return Phalcon\Mvc\JsonRpc
 */
PHP_METHOD(Phalcon_Mvc_JsonRpc, setDefaultModule){

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
PHP_METHOD(Phalcon_Mvc_JsonRpc, getDefaultModule){


	RETURN_MEMBER(this_ptr, "_defaultModule");
}

static int phalcon_mvc_jsonrpc_fire_event(zval *mgr, const char *event, zval *this_ptr, zval *params TSRMLS_DC)
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
PHP_METHOD(Phalcon_Mvc_JsonRpc, handle){

	zval *uri = NULL, *dependency_injector, *events_manager;
	zval *status = NULL, *service = NULL, *request = NULL, *response = NULL;
	zval *json = NULL, *data = NULL, *jsonrpc_message, *jsonrpc_error, *jsonrpc_result = NULL;
	zval *jsonrpc_method, *jsonrpc_params, *jsonrpc_id;
	zval *url = NULL, *router = NULL, *module_name = NULL;
	zval *module_object = NULL, *modules;
	zval *module, *class_name = NULL, *module_params;
	zval *namespace_name = NULL;
	zval *controller_name = NULL, *action_name = NULL, *params = NULL, *exact = NULL;
	zval *dispatcher = NULL, *controller = NULL, *returned_response = NULL;
	zval *path;

	PHALCON_MM_GROW();
	
	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_jsonrpc_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	
	events_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) != IS_OBJECT) {
		events_manager = NULL;
	}
	else {
		PHALCON_VERIFY_INTERFACE_EX(events_manager, phalcon_events_managerinterface_ce, phalcon_mvc_jsonrpc_exception_ce, 1);
	}

	/* Call boot event, this allows the developer to perform initialization actions */
	if (FAILURE == phalcon_mvc_jsonrpc_fire_event(events_manager, "jsonrpc:boot", getThis(), NULL TSRMLS_CC)) {
		RETURN_MM_FALSE;
	}

	/* Deserializer Json */

	PHALCON_INIT_NVAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_request);
	
	PHALCON_CALL_METHOD(&request, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(request, phalcon_http_requestinterface_ce);

	PHALCON_CALL_METHOD(&json, request, "getrawbody");
	PHALCON_CALL_FUNCTION(&data, "json_decode", json, PHALCON_GLOBAL(z_true));


	PHALCON_INIT_NVAR(service);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_response);

	PHALCON_CALL_METHOD(&response, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(response, phalcon_http_responseinterface_ce);

	PHALCON_INIT_VAR(jsonrpc_message);
	array_init(jsonrpc_message);
	
	PHALCON_INIT_VAR(jsonrpc_error);
	array_init(jsonrpc_error);

	if (PHALCON_IS_EMPTY(data)) {
		phalcon_array_update_string_long(&jsonrpc_error, SL("code"), __LINE__, 0);
		phalcon_array_update_string_string(&jsonrpc_error, SL("message"), SL("Parse error"), 0);
	} else if (Z_TYPE_P(data) != IS_ARRAY) {
		phalcon_array_update_string_long(&jsonrpc_error, SL("code"), __LINE__, 0);
		phalcon_array_update_string_string(&jsonrpc_error, SL("message"), SL("Parse error"), 0);
	} else if (!phalcon_array_isset_string(data, SS("jsonrpc"))) {		
			phalcon_array_update_string_long(&jsonrpc_error, SL("code"), __LINE__, 0);
			phalcon_array_update_string_string(&jsonrpc_error, SL("message"), SL("Invalid Request"), 0);
	} else if (!phalcon_array_isset_string(data, SS("method"))) {
			phalcon_array_update_string_long(&jsonrpc_error, SL("code"), __LINE__, 0);
			phalcon_array_update_string_string(&jsonrpc_error, SL("message"), SL("Invalid Request"), 0);
	} else {
		PHALCON_OBS_VAR(jsonrpc_method);
		phalcon_array_fetch_string(&jsonrpc_method, data, SL("method"), PH_NOISY);

		if (phalcon_array_isset_string(data, SS("params"))) {
			PHALCON_OBS_VAR(jsonrpc_params);
			phalcon_array_fetch_string(&jsonrpc_params, data, SL("params"), PH_NOISY);
		} else {
			PHALCON_INIT_VAR(jsonrpc_params);
			array_init(jsonrpc_params);
		}

		PHALCON_INIT_NVAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_url);
		PHALCON_CALL_METHOD(&url, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(url, phalcon_mvc_urlinterface_ce);

		PHALCON_CALL_METHOD(&uri, url, "get", jsonrpc_method);

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
			if (FAILURE == phalcon_mvc_jsonrpc_fire_event(events_manager, "jsonrpc:beforeStartModule", getThis(), module_name TSRMLS_CC)) {
				RETURN_MM_FALSE;
			}

			/** 
			 * Check if the module passed by the router is registered in the modules container
			 */
			PHALCON_OBS_VAR(modules);
			phalcon_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY TSRMLS_CC);
			if (!phalcon_array_isset_fetch(&module, modules, module_name)) {
				convert_to_string(module_name);
				zend_throw_exception_ex(phalcon_mvc_jsonrpc_exception_ce, 0 TSRMLS_CC, "Module %s is not registered in the jsonrpc container", Z_STRVAL_P(module_name));
				RETURN_MM();
			}
		
			/** 
			 * A module definition must be an array or an object
			 */
			if (Z_TYPE_P(module) != IS_ARRAY && Z_TYPE_P(module) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_jsonrpc_exception_ce, "Invalid module definition");
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
							zend_throw_exception_ex(phalcon_mvc_jsonrpc_exception_ce, 0 TSRMLS_CC, "Module definition path '%s' does not exist", Z_STRVAL_P(path));
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
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_jsonrpc_exception_ce, "Invalid module definition");
				return;
			}
		
			/* Calling afterStartModule event */
			if (events_manager) {
				if (!module_object) {
					module_object = PHALCON_GLOBAL(z_null);
				}

				phalcon_update_property_this(this_ptr, SL("_moduleObject"), module_object TSRMLS_CC);
				if (FAILURE == phalcon_mvc_jsonrpc_fire_event(events_manager, "jsonrpc:afterStartModule", getThis(), module_name TSRMLS_CC)) {
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

		PHALCON_INIT_NVAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_dispatcher);
		
		PHALCON_CALL_METHOD(&dispatcher, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(dispatcher, phalcon_dispatcherinterface_ce);
		
		/* Assign the values passed from the router */
		PHALCON_CALL_METHOD(NULL, dispatcher, "setmodulename", module_name);
		PHALCON_CALL_METHOD(NULL, dispatcher, "setnamespacename", namespace_name);
		PHALCON_CALL_METHOD(NULL, dispatcher, "setcontrollername", controller_name, exact);
		PHALCON_CALL_METHOD(NULL, dispatcher, "setactionname", action_name);
		PHALCON_CALL_METHOD(NULL, dispatcher, "setparams", jsonrpc_params);
		
		/* Calling beforeHandleRequest */
		RETURN_MM_ON_FAILURE(phalcon_mvc_jsonrpc_fire_event(events_manager, "jsonrpc:beforeHandleRequest", getThis(), dispatcher TSRMLS_CC));
		
		/* The dispatcher must return an object */
		PHALCON_CALL_METHOD(&controller, dispatcher, "dispatch");
		
		PHALCON_INIT_VAR(returned_response);
		
		/* Get the latest value returned by an action */
		PHALCON_CALL_METHOD(&jsonrpc_result, dispatcher, "getreturnedvalue");
	}
		
	/* Calling afterHandleRequest */
	if (FAILURE == phalcon_mvc_jsonrpc_fire_event(events_manager, "jsonrpc:afterHandleRequest", getThis(), controller TSRMLS_CC) && EG(exception)) {
		RETURN_MM();
	}
	
	phalcon_array_update_string_string(&jsonrpc_message, SL("jsonrpc"), SL("2.0"), 0);

	if (PHALCON_IS_NOT_EMPTY(jsonrpc_error)) {
		phalcon_array_update_string(&jsonrpc_message, SL("error"), jsonrpc_error, PH_COPY);
	}

	if (jsonrpc_result != NULL) {
		phalcon_array_update_string(&jsonrpc_message, SL("result"), jsonrpc_result, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&jsonrpc_id, data, SS("id"))) {
		phalcon_array_update_string(&jsonrpc_message, SL("id"), jsonrpc_id, PH_COPY);
	} else {
		phalcon_array_update_string(&jsonrpc_message, SL("id"), PHALCON_GLOBAL(z_null), PH_COPY);
	}

	PHALCON_CALL_METHOD(NULL, response, "setjsoncontent", jsonrpc_message);
	

	/* Calling beforeSendResponse */
	if (FAILURE == phalcon_mvc_jsonrpc_fire_event(events_manager, "jsonrpc:beforeSendResponse", getThis(), response TSRMLS_CC) && EG(exception)) {
		RETURN_MM();
	}
	
	/* Headers are automatically sent */
	PHALCON_CALL_METHOD(NULL, response, "sendheaders");
	
	/* Cookies are automatically sent */
	PHALCON_CALL_METHOD(NULL, response, "sendcookies");
	
	/* Return the response */
	RETURN_CCTOR(response);
}
