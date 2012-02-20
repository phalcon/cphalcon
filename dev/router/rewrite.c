
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
 * Php_Router_Rewrite
 *
 * <p>Php_Router_Rewrite is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request</p>
 *
 *Rewrite rules using a single document root:
 *
 *
 *Rewrite rules using a hidden directory and a public/ document root:
 *
 *
 * On public/.htaccess:
 *
 *
 *
 * The component can be used as follows:
 *
 *
 */

PHP_METHOD(Phalcon_Router_Rewrite, __construct){

	zval *a0 = NULL;

	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_router_rewrite_class_entry, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
}

/**
 * Handles routing information received from the rewrite engine
 */
PHP_METHOD(Phalcon_Router_Rewrite, handle){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval **gv0;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };
	int eval_int;

	phalcon_init_global("_GET" TSRMLS_CC);
	if (&EG(symbol_table)) {
		if( zend_hash_find(&EG(symbol_table), "_GET", sizeof("_GET"), (void **) &gv0) == SUCCESS) {
			if(Z_TYPE_PP(gv0)==IS_ARRAY){
				a0 = *gv0;
			} else {
				PHALCON_INIT_ARRAY(a0);
			}
		}
	} else {
		PHALCON_INIT_ARRAY(a0);
	}
	eval_int = phalcon_array_isset_string(a0, "_url", strlen("_url")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "/", 1);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_string(r1, a0, "_url", strlen("_url"), PHALCON_NOISY_FETCH TSRMLS_CC);
		p0[1] = r1;
		PHALCON_CALL_FUNC_PARAMS(r0, "explode", 2, p0);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r0);
		v0 = r0;
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch_long(r2, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			p1[0] = r2;
			phalcon_filter_alphanum(&r3, p1[0]);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), copy TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL(t0);
			phalcon_read_property(t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t0);
			if (!zend_is_true(t0)) {
				zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
			}
		} else {
			zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		}
		eval_int = phalcon_array_isset_long(v0, 1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_array_fetch_long(r4, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			p2[0] = r4;
			phalcon_filter_alphanum(&r5, p2[0]);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r5, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), copy TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL(t1);
			phalcon_read_property(t1, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t1);
			if (!zend_is_true(t1)) {
				zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
			}
		} else {
			zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(a1);
		v1 = a1;
		PHALCON_ALLOC_ZVAL(r6);
		p3[0] = v0;
		PHALCON_CALL_FUNC_PARAMS(r6, "count", 1, p3);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r6);
		v2 = r6;
		PHALCON_ALLOC_ZVAL(v3);
		ZVAL_LONG(v3, 2);
		fs48:
		PHALCON_SMALLER_FUNCTION(r7, v3, v2);
		if (!zend_is_true(r7)) {
			goto fe48;
		}
		if (!r8) {
			PHALCON_ALLOC_ZVAL(r8);
		} else {
			if (Z_REFCOUNT_P(r8) > 1) {
				{
					zval *orig_ptr = r8;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r8);
						*r8 = *orig_ptr;
						zval_copy_ctor(r8);
						Z_SET_REFCOUNT_P(r8, 1);
						Z_UNSET_ISREF_P(r8);
					}
				}
			} else {
				FREE_ZVAL(r8);
				PHALCON_ALLOC_ZVAL(r8);
			}
		}
		phalcon_array_fetch(r8, v0, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			{
				zval *orig_ptr = v1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v1);
					*v1 = *orig_ptr;
					zval_copy_ctor(v1);
					Z_SET_REFCOUNT_P(v1, 1);
					Z_UNSET_ISREF_P(v1);
				}
			}
			phalcon_array_append(v1, copy TSRMLS_CC);
		}
		{
			zval *orig_ptr = v3;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(v3);
				*v3 = *orig_ptr;
				zval_copy_ctor(v3);
				Z_SET_REFCOUNT_P(v3, 1);
				Z_UNSET_ISREF_P(v3);
			}
		}
		increment_function(v3);
		goto fs48;
		fe48:
		r7 = NULL;
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
		}
	} else {
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Returns proccesed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Rewrite, getControllerName){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Returns proccesed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Rewrite, getActionName){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Router_Rewrite, getParams){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

