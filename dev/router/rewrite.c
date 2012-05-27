
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
 * Phalcon_Router_Rewrite
 *
 * Phalcon_Router_Rewrite is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request
 *
 *
 */

PHP_METHOD(Phalcon_Router_Rewrite, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_router_rewrite_ce, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Get rewrite info
 */
PHP_METHOD(Phalcon_Router_Rewrite, _getRewriteUri){

	zval *g0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, "_GET", sizeof("_GET") TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, "_url", strlen("_url")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, g0, "_url", strlen("_url"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
* Set the base of application
*
* @param string $baseUri
*/
PHP_METHOD(Phalcon_Router_Rewrite, setBaseUri){

	zval *base_uri = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), base_uri TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles routing information received from the rewrite engine
 */
PHP_METHOD(Phalcon_Router_Rewrite, handle){

	zval *uri = NULL, *parts = NULL, *params = NULL, *number_parts = NULL, *i = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getrewriteuri", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(uri, r0);
	if (zend_is_true(uri)) {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/", 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_fast_explode(r1, c0, uri TSRMLS_CC);
		PHALCON_CPY_WRT(parts, r1);
		eval_int = phalcon_array_isset_long(parts, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_long(&r2, parts, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_filter_alphanum(r3, r2);
			phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), r3 TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t0);
			phalcon_read_property(&t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY TSRMLS_CC);
			if (!zend_is_true(t0)) {
				phalcon_update_property_null(this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
			}
		} else {
			phalcon_update_property_null(this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_long(parts, 1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_long(&r4, parts, 1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_filter_alphanum(r5, r4);
			phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), r5 TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY TSRMLS_CC);
			if (!zend_is_true(t1)) {
				phalcon_update_property_null(this_ptr, "_action", strlen("_action") TSRMLS_CC);
			}
		} else {
			phalcon_update_property_null(this_ptr, "_action", strlen("_action") TSRMLS_CC);
		}
		
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(params, a0);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_fast_count(r6, parts TSRMLS_CC);
		PHALCON_CPY_WRT(number_parts, r6);
		
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 2);
		fs_ef57_0:
			
			PHALCON_INIT_VAR(r7);
			is_smaller_function(r7, i, number_parts TSRMLS_CC);
			if (!zend_is_true(r7)) {
				goto fe_ef57_0;
			}
			PHALCON_INIT_VAR(r8);
			phalcon_array_fetch(&r8, parts, i, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_append(&params, r8, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto fs_ef57_0;
		fe_ef57_0:
		if(0){}
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), params TSRMLS_CC);
	} else {
		phalcon_update_property_null(this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		phalcon_update_property_null(this_ptr, "_action", strlen("_action") TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns proccesed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Rewrite, getControllerName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns proccesed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Rewrite, getActionName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Router_Rewrite, getParams){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

