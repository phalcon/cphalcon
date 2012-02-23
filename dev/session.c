
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
 * Php_Session
 *
 * Session client-server persistent state data management.
 */

/**
 * Starts session, optionally using an adapter
 */
PHP_METHOD(Phalcon_Session, start){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_CALL_FUNC_NORETURN("session_start");
	RETURN_NULL();
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

	eval_int = phalcon_array_isset_string(v0, "uniqueId", strlen("uniqueId")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "uniqueId", strlen("uniqueId"), PHALCON_NOISY_FETCH TSRMLS_CC);
		zend_update_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, r0 TSRMLS_CC);
	}
	RETURN_NULL();
}

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

	t0 = zend_read_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_init_global("_SESSION" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SESSION", sizeof("_SESSION"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_INIT_ARRAY(a0);
			}
		}
	} else {
		PHALCON_INIT_ARRAY(a0);
	}
	eval_int = phalcon_array_isset(a0, v1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch(r1, a0, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r1) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r1);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		RETURN_NULL();
	}
	RETURN_NULL();
}

/**
 * 
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

	phalcon_init_global("_SESSION" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_SESSION", sizeof("_SESSION"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_INIT_ARRAY(a0);
			}
		}
	} else {
		PHALCON_INIT_ARRAY(a0);
	}
	t0 = zend_read_static_property(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	{
		zval *orig_ptr = a0;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(a0);
			*a0 = *orig_ptr;
			zval_copy_ctor(a0);
			Z_SET_REFCOUNT_P(a0, 1);
			Z_UNSET_ISREF_P(a0);
		}
	}
	phalcon_array_update(a0, r0, v1 TSRMLS_CC);
	RETURN_NULL();
}

/** 
 * Returns active session id
 */
PHP_METHOD(Phalcon_Session, getId){

	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_FUNC(r0, "session_id");
	RETURN_ZVAL(r0, 1, 0);
}

