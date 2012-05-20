
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
 * Phalcon_Session
 *
 * Session client-server persistent state data management.
 */

/**
 * Starts session, optionally using an adapter
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, start){

	zval *options = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "session_start", 0x04A);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets session options
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, setOptions){

	zval *options = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(options, "uniqueId", strlen("uniqueId")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, options, "uniqueId", strlen("uniqueId"), PHALCON_NOISY TSRMLS_CC);
		zend_update_static_property(phalcon_session_ce, "_uniqueId", sizeof("_uniqueId")-1, r0 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets a session variable from an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, get){

	zval *index = NULL, *key = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_session_ce, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, index TSRMLS_CC);
	PHALCON_CPY_WRT(key, r0);
	phalcon_get_global(&g0, "_SESSION", sizeof("_SESSION") TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, key);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, g0, key, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a session variable in an application context
 *
 * @param string $index
 * @param string $value
 */
PHP_METHOD(Phalcon_Session, set){

	zval *index = NULL, *value = NULL;
	zval *g0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, "_SESSION", sizeof("_SESSION") TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_session_ce, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, index TSRMLS_CC);
	phalcon_array_update(&g0, r0, &value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether a session variable is set in an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, has){

	zval *index = NULL, *key = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_session_ce, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, index TSRMLS_CC);
	PHALCON_CPY_WRT(key, r0);
	phalcon_get_global(&g0, "_SESSION", sizeof("_SESSION") TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, key);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Removes a session variable from an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, remove){

	zval *index = NULL, *key = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *g0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_session_ce, "_uniqueId", sizeof("_uniqueId")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, index TSRMLS_CC);
	PHALCON_CPY_WRT(key, r0);
	phalcon_get_global(&g0, "_SESSION", sizeof("_SESSION") TSRMLS_CC);
	phalcon_array_unset(g0, key);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns active session id
 *
 * @return string
 */
PHP_METHOD(Phalcon_Session, getId){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "session_id", 0x04B);
	PHALCON_RETURN_DZVAL(r0);
}

