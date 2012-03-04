
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
 * Phalcon_Router_Rewrite
 *
 * <p>Phalcon_Router_Rewrite is the standard framework router. Routing is the
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
 *
 * Settings baseUri first:
 *
 *
 */

PHP_METHOD(Phalcon_Router_Rewrite, __construct){

	zval *a0 = NULL;

	phalcon_step_over("Phalcon_Router_Rewrite::__construct (ClassVariables) File=/Router/Rewrite Line=56");
	phalcon_step_over("Phalcon_Router_Rewrite::__construct (ClassVariables) File=/Router/Rewrite Line=58");
	phalcon_step_over("Phalcon_Router_Rewrite::__construct (ClassVariables) File=/Router/Rewrite Line=60");
	phalcon_step_into_entry("Phalcon_Router_Rewrite", "::__construct", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_router_rewrite_class_entry, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
}

/**
 * Get rewrite info
 */
PHP_METHOD(Phalcon_Router_Rewrite, _getRewriteUri){

	zval *a0 = NULL;
	zval *r0 = NULL;
	zval **gv0;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Router_Rewrite", "_getRewriteUri", 0);
	phalcon_step_over("Phalcon_Router_Rewrite::_getRewriteUri (If) File=/Router/Rewrite Line=68");
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
		phalcon_step_over("Phalcon_Router_Rewrite::_getRewriteUri (Block) File=/Router/Rewrite Line=68");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, a0, "_url", strlen("_url"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Router_Rewrite::_getRewriteUri (Block) File=/Router/Rewrite Line=70");
		phalcon_step_out_entry();
		RETURN_NULL();
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Router_Rewrite::_getRewriteUri (Method) File=/Router/Rewrite Line=75");
}

PHP_METHOD(Phalcon_Router_Rewrite, setBaseUri){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Router_Rewrite", "setBaseUri", 0);
	phalcon_step_over("Phalcon_Router_Rewrite::setBaseUri (Assignment) File=/Router/Rewrite Line=76");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_baseUri", strlen("_baseUri"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Router_Rewrite::setBaseUri (Method) File=/Router/Rewrite Line=82");
}

/**
 * Handles routing information received from the rewrite engine
 */
PHP_METHOD(Phalcon_Router_Rewrite, handle){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *p1[] = { NULL, NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };
	int eval_int;

	phalcon_step_into_entry("Phalcon_Router_Rewrite", "handle", 0);
	phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=83");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Router_Rewrite" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getrewriteuri" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getrewriteuri", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Router_Rewrite" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$uri", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Router_Rewrite::handle (If) File=/Router/Rewrite Line=84");
	if (zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=84");
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=85");
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "/", 1);
		p1[1] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "explode", strlen("explode"), 2, p1);
		phalcon_debug_vdump("explode > ", r1 TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r1);
		v1 = r1;
		phalcon_debug_assign("$parts", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Router_Rewrite::handle (If) File=/Router/Rewrite Line=86");
		eval_int = phalcon_array_isset_long(v1, 0);
		if (eval_int) {
			phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=86");
			phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=87");
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch_long(r2, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			p2[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
			phalcon_filter_alphanum(&r3, p2[0]);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_controller", strlen("_controller"), copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Router_Rewrite::handle (If) File=/Router/Rewrite Line=88");
			PHALCON_ALLOC_ZVAL(t0);
			phalcon_read_property(t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!zend_is_true(t0)) {
				phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=88");
				phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=89");
				zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=91");
			phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=92");
			zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Router_Rewrite::handle (If) File=/Router/Rewrite Line=94");
		eval_int = phalcon_array_isset_long(v1, 1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=94");
			phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=95");
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_array_fetch_long(r4, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			p3[0] = r4;
			phalcon_debug_param(r4 TSRMLS_CC);
			phalcon_filter_alphanum(&r5, p3[0]);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r5, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_action", strlen("_action"), copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Router_Rewrite::handle (If) File=/Router/Rewrite Line=96");
			PHALCON_ALLOC_ZVAL(t1);
			phalcon_read_property(t1, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!zend_is_true(t1)) {
				phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=96");
				phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=97");
				zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=99");
			phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=100");
			zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=102");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(a0);
		v2 = a0;
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=103");
		PHALCON_ALLOC_ZVAL(r6);
		p4[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r6, "count", strlen("count"), 1, p4);
		phalcon_debug_vdump("count > ", r6 TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r6);
		v3 = r6;
		phalcon_debug_assign("$numberParts", r6 TSRMLS_CC);
		phalcon_step_over("Phalcon_Router_Rewrite::handle (For) File=/Router/Rewrite Line=104");
		PHALCON_ALLOC_ZVAL(v4);
		ZVAL_LONG(v4, 2);
		fs49:
		PHALCON_SMALLER_FUNCTION(r7, v4, v3);
		if (!zend_is_true(r7)) {
			goto fe49;
		}
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=104");
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=105");
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
		phalcon_array_fetch(r8, v1, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			{
				zval *orig_ptr = v2;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v2);
					*v2 = *orig_ptr;
					zval_copy_ctor(v2);
					Z_SET_REFCOUNT_P(v2, 1);
					Z_UNSET_ISREF_P(v2);
				}
			}
			phalcon_array_append(v2, copy TSRMLS_CC);
		}
		{
			zval *orig_ptr = v4;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(v4);
				*v4 = *orig_ptr;
				zval_copy_ctor(v4);
				Z_SET_REFCOUNT_P(v4, 1);
				Z_UNSET_ISREF_P(v4);
			}
		}
		increment_function(v4);
		phalcon_debug_vdump("PostIncrementing $i", v4);
		goto fs49;
		fe49:
		r7 = NULL;
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=107");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Block) File=/Router/Rewrite Line=108");
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=109");
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_controller", strlen("_controller") TSRMLS_CC);
		phalcon_step_over("Phalcon_Router_Rewrite::handle (Assignment) File=/Router/Rewrite Line=110");
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_action", strlen("_action") TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Router_Rewrite::handle (Method) File=/Router/Rewrite Line=120");
}

/**
 * Returns proccesed controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Rewrite, getControllerName){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Router_Rewrite", "getControllerName", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controller", sizeof("_controller")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Router_Rewrite::getControllerName (Method) File=/Router/Rewrite Line=129");
}

/**
 * Returns proccesed action name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Router_Rewrite, getActionName){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Router_Rewrite", "getActionName", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_action", sizeof("_action")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Router_Rewrite::getActionName (Method) File=/Router/Rewrite Line=138");
}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Router_Rewrite, getParams){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Router_Rewrite", "getParams", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
}

