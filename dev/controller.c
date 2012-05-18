
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Controller
 *
 * Every application controller should extends this class that encapsulates all the controller functionality
 *
 * Controllers provide the “flow” between models and views. Controllers are responsible
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
		PHALCON_INIT_VAR(view);
		ZVAL_NULL(view);
	}
	
	if (!model) {
		PHALCON_INIT_VAR(model);
		ZVAL_NULL(model);
	}
	
	phalcon_update_property_zval(this_ptr, "_dispatcher", strlen("_dispatcher"), dispatcher TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "request", strlen("request"), request TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "response", strlen("response"), response TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "view", strlen("view"), view TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), model TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Forwards execution flow to another controller/action.
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Controller, _forward){

	zval *uri = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dispatcher", sizeof("_dispatcher")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "forward", uri, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_Controller, __get){

	zval *property_name = NULL, *model = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL, *i1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (PHALCON_COMPARE_STRING(property_name, "view")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "_getviewcomponent", PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "view", strlen("view"), r0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "view", sizeof("view")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t0);
	}
	if (PHALCON_COMPARE_STRING(property_name, "filter")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_filter_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		phalcon_update_property_zval(this_ptr, "filter", strlen("filter"), i0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "filter", sizeof("filter")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t1);
	}
	if (PHALCON_COMPARE_STRING(property_name, "session")) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_session_namespace_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_get_class(r1, this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r1, PHALCON_CHECK);
		phalcon_update_property_zval(this_ptr, "session", strlen("session"), i1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "session", sizeof("session")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t3)) {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(model, t4);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD_PARAMS_1(r2, model, "ismodel", property_name, PHALCON_NO_CHECK);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD_PARAMS_1(r3, model, "getmodel", property_name, PHALCON_NO_CHECK);
			PHALCON_RETURN_DZVAL(r3);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_LEFT(r4, "Access to undefined property ", property_name);
	Z_ADDREF_P(r4);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("trigger_error", r4, 0x033);
	Z_DELREF_P(r4);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

