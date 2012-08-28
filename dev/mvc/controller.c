
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

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Controller
 *
 * Every application controller should extend this class that encapsulates all the controller functionality
 *
 * The controllers provide the “flow” between models and views. Controllers are responsible
 * for processing the incoming requests from the web browser, interrogating the models for data,
 * and passing that data on to the views for presentation.
 *
 *
 */

/**
 * Phalcon\Mvc\Controller constructor
 *
 */
PHP_METHOD(Phalcon_Mvc_Controller, __construct){


	PHALCON_MM_GROW();
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Controller, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("di"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Controller, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("di"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_Mvc_Controller, __get){

	zval *property_name = NULL, *dependency_injector = NULL;
	zval *service = NULL, *request = NULL, *response = NULL, *view = NULL, *dispatcher = NULL;
	zval *filter = NULL, *class_name = NULL, *arguments = NULL, *persistent = NULL;
	zval *error_msg = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("di"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access the controller services");
		return;
	}
	
	if (zend_is_true(dependency_injector)) {
		if (PHALCON_COMPARE_STRING(property_name, "request")) {
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "request", 1);
			
			PHALCON_INIT_VAR(request);
			PHALCON_CALL_METHOD_PARAMS_1(request, dependency_injector, "getshared", service, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("request"), request TSRMLS_CC);
			
			RETURN_CCTOR(request);
		}
		if (PHALCON_COMPARE_STRING(property_name, "response")) {
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "response", 1);
			
			PHALCON_INIT_VAR(response);
			PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "getshared", service, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("response"), response TSRMLS_CC);
			
			RETURN_CCTOR(response);
		}
		
		if (PHALCON_COMPARE_STRING(property_name, "view")) {
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "view", 1);
			
			PHALCON_INIT_VAR(view);
			PHALCON_CALL_METHOD_PARAMS_1(view, dependency_injector, "getshared", service, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("view"), view TSRMLS_CC);
			
			RETURN_CCTOR(view);
		}
		
		if (PHALCON_COMPARE_STRING(property_name, "dispatcher")) {
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "dispatcher", 1);
			
			PHALCON_INIT_VAR(dispatcher);
			PHALCON_CALL_METHOD_PARAMS_1(dispatcher, dependency_injector, "getshared", service, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("dispatcher"), dispatcher TSRMLS_CC);
			
			RETURN_CCTOR(dispatcher);
		}
		
		if (PHALCON_COMPARE_STRING(property_name, "filter")) {
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "filter", 1);
			
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("filter"), filter TSRMLS_CC);
			
			RETURN_CCTOR(filter);
		}
		
		if (PHALCON_COMPARE_STRING(property_name, "session")) {
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "session", 1);
			
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("filter"), filter TSRMLS_CC);
			
			RETURN_CCTOR(filter);
		}
		
		if (PHALCON_COMPARE_STRING(property_name, "persistent")) {
			PHALCON_INIT_VAR(class_name);
			phalcon_get_class(class_name, this_ptr TSRMLS_CC);
			
			PHALCON_INIT_VAR(arguments);
			array_init(arguments);
			phalcon_array_append(&arguments, class_name, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "sessionBag", 1);
			
			PHALCON_INIT_VAR(persistent);
			PHALCON_CALL_METHOD_PARAMS_2(persistent, dependency_injector, "get", service, arguments, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("persistent"), persistent TSRMLS_CC);
			
			RETURN_CCTOR(persistent);
		}
	}
	
	PHALCON_INIT_VAR(error_msg);
	PHALCON_CONCAT_SV(error_msg, "Access to undefined property ", property_name);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("trigger_error", error_msg);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

