
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/concat.h"

PHP_METHOD(Phalcon_Mvc_Application, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Error Processing Request");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Application, getDI){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

PHP_METHOD(Phalcon_Mvc_Application, registerModules){

	zval *modules = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &modules) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(modules) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Modules must be an Array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_modules"), modules TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles a MVC request
 *
 * @return Phalcon\Http\Response
 */
PHP_METHOD(Phalcon_Mvc_Application, handle){

	zval *dependency_injector = NULL, *router = NULL, *module_name = NULL;
	zval *modules = NULL, *module = NULL, *path = NULL, *exception_msg = NULL, *exception = NULL;
	zval *class_name = NULL, *module_object = NULL, *view = NULL, *controller_name = NULL;
	zval *action_name = NULL, *params = NULL, *dispatcher = NULL, *response = NULL;
	zval *content = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	PHALCON_CALL_METHOD(dependency_injector, this_ptr, "getdi", PH_NO_CHECK);
	if (!zend_is_true(dependency_injector)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "router", 1);
	
	PHALCON_INIT_VAR(router);
	PHALCON_CALL_METHOD_PARAMS_1(router, dependency_injector, "getshared", c0, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(router, "handle", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(module_name);
	PHALCON_CALL_METHOD(module_name, router, "getmodulename", PH_NO_CHECK);
	if (zend_is_true(module_name)) {
		PHALCON_INIT_VAR(modules);
		phalcon_read_property(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(modules, module_name);
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Module isn't registered in the application container");
			return;
		}
		
		PHALCON_INIT_VAR(module);
		phalcon_array_fetch(&module, modules, module_name, PH_NOISY_CC);
		if (Z_TYPE_P(module) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_application_exception_ce, "Invalid module definition path");
			return;
		}
		
		eval_int = phalcon_array_isset_string(module, SL("path")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(path);
			phalcon_array_fetch_string(&path, module, SL("path"), PH_NOISY_CC);
			if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
				if (phalcon_require(path TSRMLS_CC) == FAILURE) {
					return;
				}
			} else {
				PHALCON_INIT_VAR(exception_msg);
				PHALCON_CONCAT_SVS(exception_msg, "Module definition path '", path, "\" doesn't exists");
				
				PHALCON_INIT_VAR(exception);
				object_init_ex(exception, phalcon_mvc_application_exception_ce);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_msg, PH_CHECK);
				phalcon_throw_exception(exception TSRMLS_CC);
				return;
			}
		}
		
		eval_int = phalcon_array_isset_string(module, SL("className")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(class_name);
			phalcon_array_fetch_string(&class_name, module, SL("className"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_VAR(class_name);
			ZVAL_STRING(class_name, "Module", 1);
		}
		
		PHALCON_INIT_VAR(module_object);
		PHALCON_CALL_METHOD_PARAMS_1(module_object, dependency_injector, "get", class_name, PH_NO_CHECK);
		PHALCON_CALL_METHOD_NORETURN(module_object, "registerautoloaders", PH_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(module_object, "registerservices", dependency_injector, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "view", 1);
	
	PHALCON_INIT_VAR(view);
	PHALCON_CALL_METHOD_PARAMS_1(view, dependency_injector, "getshared", c1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(controller_name);
	PHALCON_CALL_METHOD(controller_name, router, "getcontrollername", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(action_name);
	PHALCON_CALL_METHOD(action_name, router, "getactionname", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(params);
	PHALCON_CALL_METHOD(params, router, "getparams", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "dispatcher", 1);
	
	PHALCON_INIT_VAR(dispatcher);
	PHALCON_CALL_METHOD_PARAMS_1(dispatcher, dependency_injector, "getshared", c2, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setcontrollername", controller_name, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setactionname", action_name, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dispatcher, "setparams", params, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(view, "start", PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(dispatcher, "dispatch", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(controller_name);
	PHALCON_CALL_METHOD(controller_name, dispatcher, "getcontrollername", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(action_name);
	PHALCON_CALL_METHOD(action_name, dispatcher, "getactionname", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(params);
	PHALCON_CALL_METHOD(params, dispatcher, "getparams", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(view, "render", controller_name, action_name, params, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(view, "finish", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, "response", 1);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "getshared", c3, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(content);
	PHALCON_CALL_METHOD(content, view, "getcontent", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(response, "setcontent", content, PH_NO_CHECK);
	PHALCON_CALL_METHOD_NORETURN(response, "sendheaders", PH_NO_CHECK);
	
	RETURN_CCTOR(response);
}

