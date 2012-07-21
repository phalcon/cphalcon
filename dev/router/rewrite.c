
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

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Router\Rewrite
 *
 * Phalcon\Router\Rewrite is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request
 *
 *
 */

PHP_METHOD(Phalcon_Router_Rewrite, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_router_rewrite_ce, this_ptr, SL("_params"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Get rewrite info
 */
PHP_METHOD(Phalcon_Router_Rewrite, _getRewriteUri){

	zval *uri = NULL, *prefix = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_GET")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(g0, SL("_url")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(uri);
		phalcon_array_fetch_string(&uri, g0, SL("_url"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(prefix);
		phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		if (zend_is_true(prefix)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CONCAT_SVS(r0, "~^", prefix, "~");
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "", 1);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_FUNC_PARAMS_3(r1, "preg_replace", r0, c0, uri);
			PHALCON_CPY_WRT(uri, r1);
		}
		
		
		RETURN_CCTOR(uri);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set a uri prefix. This will be replaced from the beginning of the uri
 */
PHP_METHOD(Phalcon_Router_Rewrite, setPrefix){

	zval *prefix = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &prefix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles routing information received from the rewrite engine
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Router_Rewrite, handle){

	zval *uri = NULL, *parts = NULL, *params = NULL, *number_parts = NULL, *i = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!uri) {
		PHALCON_ALLOC_ZVAL_MM(uri);
		ZVAL_NULL(uri);
	} else {
		PHALCON_SEPARATE_PARAM(uri);
	}
	
	if (!zend_is_true(uri)) {
		PHALCON_INIT_VAR(uri);
		PHALCON_CALL_METHOD(uri, this_ptr, "_getrewriteuri", PH_NO_CHECK);
	}
	if (zend_is_true(uri)) {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/", 1);
		PHALCON_INIT_VAR(parts);
		phalcon_fast_explode(parts, c0, uri TSRMLS_CC);
		eval_int = phalcon_array_isset_long(parts, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, parts, 0, PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_filter_alphanum(r1, r0);
			phalcon_update_property_zval(this_ptr, SL("_controller"), r1 TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t0);
			phalcon_read_property(&t0, this_ptr, SL("_controller"), PH_NOISY_CC);
			if (!zend_is_true(t0)) {
				phalcon_update_property_null(this_ptr, SL("_controller") TSRMLS_CC);
			}
		} else {
			phalcon_update_property_null(this_ptr, SL("_controller") TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_long(parts, 1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_long(&r2, parts, 1, PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_filter_alphanum(r3, r2);
			phalcon_update_property_zval(this_ptr, SL("_action"), r3 TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, this_ptr, SL("_action"), PH_NOISY_CC);
			if (!zend_is_true(t1)) {
				phalcon_update_property_null(this_ptr, SL("_action") TSRMLS_CC);
			}
		} else {
			phalcon_update_property_null(this_ptr, SL("_action") TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(params);
		array_init(params);
		
		PHALCON_INIT_VAR(number_parts);
		phalcon_fast_count(number_parts, parts TSRMLS_CC);
		
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 2);
		fs_ef57_0:
			
			PHALCON_INIT_VAR(r4);
			is_smaller_function(r4, i, number_parts TSRMLS_CC);
			if (!zend_is_true(r4)) {
				goto fe_ef57_0;
			}
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch(&r5, parts, i, PH_NOISY_CC);
			phalcon_array_append(&params, r5, PH_SEPARATE TSRMLS_CC);
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto fs_ef57_0;
		fe_ef57_0:
		phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	} else {
		phalcon_update_property_null(this_ptr, SL("_controller") TSRMLS_CC);
		phalcon_update_property_null(this_ptr, SL("_action") TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, SL("_controller"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_action"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

