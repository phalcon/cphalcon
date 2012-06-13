
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
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_View_Engine
 *
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon_View component.
 */

/**
 * Phalcon_View_Engine constructor
 *
 * @param Phalcon_View $view
 * @param array $options
 * @param array $params
 */
PHP_METHOD(Phalcon_View_Engine, __construct){

	zval *view = NULL, *options = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &view, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "initialize", view, options, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Initializes the engine adapter
 *
 * @param Phalcon_View $view
 * @param array $options
 */
PHP_METHOD(Phalcon_View_Engine, initialize){

	zval *view = NULL, *options = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &view, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(view) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_view_exception_ce, "Invalid view component provided to Phalcon_View_Engine");
		return;
	}
	phalcon_update_property_zval(this_ptr, "_view", strlen("_view"), view TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_options", strlen("_options"), options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_View_Engine, getControllerName){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getcontrollername", PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_View_Engine, getActionName){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getactionname", PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns cached ouput on another view stage
 *
 * @return array
 */
PHP_METHOD(Phalcon_View_Engine, getContent){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getcontent", PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Generates a external absolute path to an application uri
 *
 * @param array|string $params
 * @return string
 */
PHP_METHOD(Phalcon_View_Engine, url){

	zval *params = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!params) {
		PHALCON_INIT_VAR(params);
		ZVAL_NULL(params);
	}
	
	if (Z_TYPE_P(params) == IS_ARRAY) { 
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_utils", "geturl", params);
		PHALCON_RETURN_DZVAL(r0);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a local path
 *
 * @param array|string $params
 * @return string
 */
PHP_METHOD(Phalcon_View_Engine, path){

	zval *params = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!params) {
		PHALCON_INIT_VAR(params);
		ZVAL_STRING(params, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_utils", "getlocalpath", params);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Renders a partial inside another view
 *
 * @param string $partialPath
 */
PHP_METHOD(Phalcon_View_Engine, partial){

	zval *partial_path = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &partial_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t0, "partial", partial_path, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

