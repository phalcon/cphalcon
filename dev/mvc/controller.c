
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
 * Constructor for Phalcon\Mvc\Controller
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Controller, __construct){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!dependency_injector) {
		PHALCON_ALLOC_ZVAL_MM(dependency_injector);
		ZVAL_NULL(dependency_injector);
	}
	
	phalcon_update_property_zval(this_ptr, SL("di"), dependency_injector TSRMLS_CC);
	
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

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_Mvc_Controller, __get){

	zval *property_name = NULL, *dependency_injector = NULL;
	zval *request = NULL, *response = NULL, *view = NULL, *filter = NULL, *error_msg = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("di"), PH_NOISY_CC);
	if (zend_is_true(dependency_injector)) {
		if (PHALCON_COMPARE_STRING(property_name, "request")) {
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "request", 1);
			PHALCON_INIT_VAR(request);
			PHALCON_CALL_METHOD_PARAMS_1(request, dependency_injector, "getshared", c0, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("request"), request TSRMLS_CC);
			
			RETURN_CCTOR(request);
		}
		if (PHALCON_COMPARE_STRING(property_name, "response")) {
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "response", 1);
			PHALCON_INIT_VAR(response);
			PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "getshared", c1, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("response"), response TSRMLS_CC);
			
			RETURN_CCTOR(response);
		}
		
		if (PHALCON_COMPARE_STRING(property_name, "view")) {
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "view", 1);
			PHALCON_INIT_VAR(view);
			PHALCON_CALL_METHOD_PARAMS_1(view, dependency_injector, "getshared", c2, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("view"), view TSRMLS_CC);
			
			RETURN_CCTOR(view);
		}
		
		if (PHALCON_COMPARE_STRING(property_name, "dispatcher")) {
			PHALCON_INIT_VAR(c3);
			ZVAL_STRING(c3, "dispatcher", 1);
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_METHOD_PARAMS_1(r0, dependency_injector, "getshared", c3, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("dispatcher"), r0 TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t0);
			phalcon_read_property(&t0, this_ptr, SL("dispatcher"), PH_NOISY_CC);
			
			RETURN_CCTOR(t0);
		}
		
		if (PHALCON_COMPARE_STRING(property_name, "filter")) {
			PHALCON_INIT_VAR(c4);
			ZVAL_STRING(c4, "filter", 1);
			PHALCON_INIT_VAR(filter);
			PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", c4, PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("filter"), filter TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, SL("filter"), PH_NOISY_CC);
			
			RETURN_CCTOR(t1);
		}
	}
	
	PHALCON_INIT_VAR(error_msg);
	PHALCON_CONCAT_SV(error_msg, "Access to undefined property ", property_name);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("trigger_error", error_msg);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

