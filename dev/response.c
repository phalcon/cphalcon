
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

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Response
 *
 * Encapsulates the HTTP response message.
 */

PHP_METHOD(Phalcon_Response, __construct){


	phalcon_step_into_entry("Phalcon_Response", "__construct", 0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Response::__construct (Method) File=/Response Line=23");
}

/**
 * Returns singleton Phalcon_Response instance
 *
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	phalcon_step_into_entry("Phalcon_Response", "getInstance", 0);
	phalcon_step_over("Phalcon_Response::getInstance (If) File=/Response Line=24");
	t0 = zend_read_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Response::getInstance (Block) File=/Response Line=24");
		phalcon_step_over("Phalcon_Response::getInstance (Assignment) File=/Response Line=25");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_response_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Response" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Response" TSRMLS_CC);
		zend_update_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Response::getInstance (Method) File=/Response Line=36");
}

/**
 * Overwrittes a header in the response
 *
 * @param string $name
 * @param string $value
 */
PHP_METHOD(Phalcon_Response, setHeader){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Response", "setHeader", 0);
	phalcon_step_over("Phalcon_Response::setHeader (FunctionCall) File=/Response Line=37");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_vboth(r0, v0, ": ", v1 TSRMLS_CC);
	Z_ADDREF_P(r0);
	p0[0] = r0;
	phalcon_debug_param(r0 TSRMLS_CC);
	PHALCON_PARAM_BOOL(p0[1], 1);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("header", 2, p0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Response::setHeader (Method) File=/Response Line=45");
}

/**
 * Sets HTTP response body
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_Response, setContent){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Response", "setContent", 0);
	phalcon_step_over("Phalcon_Response::setContent (Assignment) File=/Response Line=46");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Response::setContent (Method) File=/Response Line=54");
}

/**
 * Gets HTTP response body
 *
 * @return string 
 */
PHP_METHOD(Phalcon_Response, getContent){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Response", "getContent", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Response::getContent (Method) File=/Response Line=62");
}

/**
 * Sends HTTP response to the client
 * 
 */
PHP_METHOD(Phalcon_Response, send){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Response", "send", 0);
	phalcon_step_over("Phalcon_Response::send (Echo) File=/Response Line=63");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zend_print_zval(t0, 0);
	phalcon_step_out_entry();
	RETURN_NULL();
}

