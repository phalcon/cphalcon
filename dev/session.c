
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
 * Phalcon_Session
 *
 * Session client-server persistent state data management.
 */

/**
 * Starts session, optionally using an adapter
 */
PHP_METHOD(Phalcon_Session, start){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zend_bool silence;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Session", "start", 0);
	phalcon_step_over("Phalcon_Session::start (Silence) File=/Session Line=18");
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_FUNC(r0, "session_start");
	phalcon_debug_vdump("session_start > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Session::start (Method) File=/Session Line=24");
}

/**
 * Sets session options
 */
PHP_METHOD(Phalcon_Session, setOptions){

	zval *v0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Session", "setOptions", 0);
	phalcon_step_over("Phalcon_Session::setOptions (If) File=/Session Line=25");
	eval_int = phalcon_array_isset_string(v0, "uniqueId", strlen("uniqueId")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Session::setOptions (Block) File=/Session Line=25");
		phalcon_step_over("Phalcon_Session::setOptions (Assignment) File=/Session Line=26");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "uniqueId", strlen("uniqueId"), PHALCON_NOISY_FETCH TSRMLS_CC);
		zend_update_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, r0 TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Session::setOptions (Method) File=/Session Line=33");
}

/**
 * Gets a session variable from an application context
 */
PHP_METHOD(Phalcon_Session, get){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;
	zval **gv0;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Session", "get", 0);
	phalcon_step_over("Phalcon_Session::get (Assignment) File=/Session Line=34");
	t0 = zend_read_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_debug_assign("$key", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Session::get (If) File=/Session Line=35");
	phalcon_init_global("_SESSION" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SESSION", sizeof("_SESSION"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	eval_int = phalcon_array_isset(a0, v1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Session::get (Block) File=/Session Line=35");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch(r1, a0, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(r1);
	} else {
		phalcon_step_over("Phalcon_Session::get (Block) File=/Session Line=37");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Session::get (Method) File=/Session Line=45");
}

/**
 * Sets a session variable in an application context
 */
PHP_METHOD(Phalcon_Session, set){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval **gv0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Session", "set", 0);
	phalcon_step_over("Phalcon_Session::set (Assignment) File=/Session Line=46");
	phalcon_init_global("_SESSION" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SESSION", sizeof("_SESSION"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_ALLOC_ZVAL(a0);
				array_init(a0);
			}
		}
	}
	if (!a0) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
	}
	t0 = zend_read_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	PHALCON_SEPARATE(a0);
	phalcon_array_update(a0, r0, v1 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Session::set (Method) File=/Session Line=52");
}

/** 
 * Returns active session id
 */
PHP_METHOD(Phalcon_Session, getId){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Session", "getId", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_FUNC(r0, "session_id");
	phalcon_debug_vdump("session_id > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
}

