
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Response
 *
 * Encapsulates the HTTP response message.
 */

PHP_METHOD(Phalcon_Response, __construct){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns singleton Phalcon_Response instance
 *
 * @return Phalcon_Response
 */
PHP_METHOD(Phalcon_Response, getInstance){

	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_response_class_entry);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		zend_update_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, i0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Sets the HTTP response code
 *
 * @param int $code
 * @param strign $message
 */
PHP_METHOD(Phalcon_Response, setStatusCode){

	zval *v0 = NULL, *v1 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "SERVER_SOFTWARE", strlen("SERVER_SOFTWARE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "HTTP/1.1 ", v0);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, " ", v1);
		Z_ADDREF_P(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r0, c0, 0x004);
		Z_DELREF_P(r0);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, "Status: ", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, " ", v1);
		Z_ADDREF_P(r2);
		PHALCON_INIT_VAR(c1);
		ZVAL_BOOL(c1, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r2, c1, 0x004);
		Z_DELREF_P(r2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Overwrittes a header in the response
 *
 * @param string $name
 * @param string $value
 */
PHP_METHOD(Phalcon_Response, setHeader){

	zval *v0 = NULL, *v1 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_init_global("_SERVER" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SERVER", sizeof("_SERVER"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				g0 = *gv0;
			} else {
				PHALCON_INIT_VAR(g0);
				array_init(g0);
			}
		}
	}
	if (!g0) {
		PHALCON_INIT_VAR(g0);
		array_init(g0);
	}
	eval_int = phalcon_array_isset_string(g0, "SERVER_SOFTWARE", strlen("SERVER_SOFTWARE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, v0, ": ", v1);
		Z_ADDREF_P(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("header", r0, c0, 0x004);
		Z_DELREF_P(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets HTTP response body
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_Response, setContent){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sends HTTP response to the client
 *
 */
PHP_METHOD(Phalcon_Response, send){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zend_print_zval(t0, 0);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

