
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Controller
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
 * Constructor for Phalcon_Controller
 *
 * @param Phalcon_Dispatcher $dispatcher
 * @param Phalcon_Request $request
 * @param Phalcon_Response $response
 * @param Phalcon_View $view
 * @param Phalcon_Model_Manager $model
 */
PHP_METHOD(Phalcon_Controller, __construct){

	zval *dispatcher = NULL, *request = NULL, *response = NULL, *view = NULL, *model = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &dispatcher, &request, &response, &view, &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!view) {
		PHALCON_ALLOC_ZVAL_MM(view);
		ZVAL_NULL(view);
	}
	
	if (!model) {
		PHALCON_ALLOC_ZVAL_MM(model);
		ZVAL_NULL(model);
	}
	
	phalcon_update_property_zval(this_ptr, SL("dispatcher"), dispatcher TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("request"), request TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("response"), response TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("view"), view TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("model"), model TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Forwards execution flow to another controller/action.
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Controller, _forward){

	zval *uri = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("dispatcher"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "forward", uri, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Returns a param from the dispatching params
 *
 * @param mixed $index
 */
PHP_METHOD(Phalcon_Controller, _getParam){

	zval *index = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("dispatcher"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "getparam", index, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Set a dispatching parameter
 *
 * @param mixed $index
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Controller, _setParam){

	zval *index = NULL, *value = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("dispatcher"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, t0, "setparam", index, value, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_Controller, __get){

	zval *property_name = NULL, *model = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL, *i1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (PHALCON_COMPARE_STRING(property_name, "view")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "_getviewcomponent", PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("view"), r0 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("view"), PH_NOISY_CC);
		
		RETURN_CCTOR(t0);
	}
	if (PHALCON_COMPARE_STRING(property_name, "filter")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_filter_ce);
		phalcon_update_property_zval(this_ptr, SL("filter"), i0 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("filter"), PH_NOISY_CC);
		
		RETURN_CCTOR(t1);
	}
	
	if (PHALCON_COMPARE_STRING(property_name, "session")) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_session_namespace_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_get_class(r1, this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r1, PH_CHECK);
		phalcon_update_property_zval(this_ptr, SL("session"), i1 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("session"), PH_NOISY_CC);
		
		RETURN_CCTOR(t2);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("model"), PH_NOISY_CC);
	if (zend_is_true(t3)) {
		PHALCON_INIT_VAR(model);
		phalcon_read_property(&model, this_ptr, SL("model"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD_PARAMS_1(r2, model, "ismodel", property_name, PH_NO_CHECK);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD_PARAMS_1(r3, model, "getmodel", property_name, PH_NO_CHECK);
			RETURN_CTOR(r3);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_SV(r4, "Access to undefined property ", property_name);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("trigger_error", r4);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

