
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
 * Phalcon_Response
 *
 * Encapsulates the HTTP response message.
 *
 *
 */

/**
 * Returns singleton Phalcon_Response instance
 *
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_response_ce, "_instance", sizeof("_instance")-1 TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_response_ce);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		zend_update_static_property(phalcon_response_ce, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	PHALCON_OBSERVE_VAR(t1);
	phalcon_read_static_property(&t1, phalcon_response_ce, "_instance", sizeof("_instance")-1 TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Sets the HTTP response code
 *
 * @param int $code
 * @param strign $message
 */
PHP_METHOD(Phalcon_Response, setStatusCode){

	zval *code = NULL, *message = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &code, &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, "_SERVER", sizeof("_SERVER") TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, "SERVER_SOFTWARE", strlen("SERVER_SOFTWARE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSV(r0, "HTTP/1.1 ", code, " ", message);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r0, c0, 0x046);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVSV(r1, "Status: ", code, " ", message);
		
		PHALCON_INIT_VAR(c1);
		ZVAL_BOOL(c1, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r1, c1, 0x046);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Overwrites a header in the response
 *
 *
 *
 * @param string $name
 * @param string $value
 */
PHP_METHOD(Phalcon_Response, setHeader){

	zval *name = NULL, *value = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, "_SERVER", sizeof("_SERVER") TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, "SERVER_SOFTWARE", strlen("SERVER_SOFTWARE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VSV(r0, name, ": ", value);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r0, c0, 0x046);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Send a raw header to the response
 *
 *
 */
PHP_METHOD(Phalcon_Response, setRawHeader){

	zval *header = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &header) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", header, c0, 0x046);
	
	PHALCON_MM_RESTORE();
}

/**
 *  Redirect by HTTP to another action or URL
 *
 *
 *
 * @param string $location
 * @param boolean $full
 */
PHP_METHOD(Phalcon_Response, redirect){

	zval *location = NULL, *full = NULL, *header = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &location, &full) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!full) {
		PHALCON_INIT_VAR(full);
		ZVAL_BOOL(full, 0);
	}
	
	if (zend_is_true(full)) {
		PHALCON_CPY_WRT(header, location);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_utils", "geturl", location);
		PHALCON_CPY_WRT(header, r0);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Location", 1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "setheader", c0, header, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets HTTP response body
     *
 *
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_Response, setContent){

	zval *content = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &content) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), content TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Appends a string to the HTTP response body
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_Response, appendContent){

	zval *content = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &content) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, content TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets HTTP response body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Response, getContent){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Prints out HTTP response to the client
 *
 */
PHP_METHOD(Phalcon_Response, send){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY TSRMLS_CC);
	zend_print_zval(t0, 1);
	
	PHALCON_MM_RESTORE();
}

/**
 * Resets the internal singleton
 */
PHP_METHOD(Phalcon_Response, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	zend_update_static_property(phalcon_response_ce, "_instance", sizeof("_instance")-1, t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

