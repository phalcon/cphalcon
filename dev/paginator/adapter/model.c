
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
 * Phalcon_Paginator_Adapter_Model
 *
 * Component of pagination by models
 *
 */

/**
 * Set the current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setCurrentPageNumber){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	convert_to_long(v0);
	phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the slice to show in pagination
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_limitRows", sizeof("_limitRows")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v0, t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_config", sizeof("_config")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, t1, "data", strlen("data"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_page", sizeof("_page")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t2);
	if (Z_TYPE_P(v2) == IS_NULL) {
		PHALCON_INIT_VAR(v2);
		ZVAL_LONG(v2, 1);
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "count", v1, 0x008);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v4, i0);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	sub_function(r2, v2, t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	mul_function(r3, v0, r2 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_FUNC_PARAMS_1(r5, "count", v1, 0x008);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	sub_function(r6, r5, t4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r7);
	div_function(r7, r6, v0 TSRMLS_CC);
	Z_ADDREF_P(r7);
	PHALCON_CALL_FUNC_PARAMS_1(r4, "round", r7, 0x00B);
	Z_DELREF_P(r7);
	PHALCON_CPY_WRT(v6, r4);
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v2) == IS_NULL) {
			PHALCON_INIT_VAR(v2);
			ZVAL_LONG(v2, 1);
		}
		PHALCON_ALLOC_ZVAL_MM(r8);
		p3[0] = v1;
		p3[1] = v5;
		p3[2] = v0;
		PHALCON_CALL_FUNC_PARAMS(r8, "array_slice", 3, p3, 0x00C);
		phalcon_update_property_zval(v4, "items", strlen("items"), r8 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(v2) == IS_NULL) {
			PHALCON_INIT_VAR(v2);
			ZVAL_LONG(v2, 0);
		}
		if (Z_TYPE_P(v1) == IS_OBJECT) {
			PHALCON_INIT_VAR(r9);
			phalcon_instance_of(r9, v1, phalcon_model_resultset_class_entry TSRMLS_CC);
			if (zend_is_true(r9)) {
				PHALCON_INIT_VAR(t5);
				ZVAL_LONG(t5, 0);
				PHALCON_INIT_VAR(r10);
				is_smaller_function(r10, v5, t5 TSRMLS_CC);
				if (zend_is_true(r10)) {
					PHALCON_ALLOC_ZVAL_MM(i1);
					object_init_ex(i1, phalcon_paginator_exception_class_entry);
					PHALCON_ALLOC_ZVAL_MM(r11);
					PHALCON_CONCAT_BOTH(r11,  "The page number zero or less (", v5, ")");
					Z_ADDREF_P(r11);
					p4[0] = r11;
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
					Z_DELREF_P(p4[0]);
					zend_throw_exception_object(i1 TSRMLS_CC);
					Z_ADDREF_P(i1);
					PHALCON_MM_RESTORE();
					return;
				}
				PHALCON_INIT_VAR(a0);
				array_init(a0);
				phalcon_update_property_zval(v4, "items", strlen("items"), a0 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r12);
				PHALCON_CALL_FUNC_PARAMS_1(r12, "count", v1, 0x008);
				PHALCON_CPY_WRT(v7, r12);
				PHALCON_INIT_VAR(t6);
				ZVAL_LONG(t6, 0);
				PHALCON_INIT_VAR(r13);
				is_smaller_function(r13, t6, v7 TSRMLS_CC);
				if (zend_is_true(r13)) {
					PHALCON_INIT_VAR(r14);
					is_smaller_or_equal_function(r14, v5, v7 TSRMLS_CC);
					if (zend_is_true(r14)) {
						Z_ADDREF_P(v5);
						p6[0] = v5;
						PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "seek", 1, p6, PHALCON_CALL_DEFAULT);
						Z_DELREF_P(p6[0]);
					} else {
						PHALCON_INIT_VAR(p7[0]);
						ZVAL_LONG(p7[0], 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "seek", 1, p7, PHALCON_CALL_DEFAULT);
						PHALCON_INIT_VAR(v2);
						ZVAL_LONG(v2, 1);
					}
					PHALCON_INIT_VAR(v8);
					ZVAL_LONG(v8, 1);
					ws7:
					PHALCON_INIT_VAR(r15);
					PHALCON_CALL_METHOD(r15, v1, "valid", PHALCON_CALL_DEFAULT);
					PHALCON_INIT_VAR(t7);
					ZVAL_BOOL(t7, 1);
					PHALCON_INIT_VAR(r16);
					is_equal_function(r16, r15, t7 TSRMLS_CC);
					if (!zend_is_true(r16)) {
						goto we7;
					}
					PHALCON_INIT_VAR(r17);
					PHALCON_CALL_METHOD(r17, v1, "current", PHALCON_CALL_DEFAULT);
					PHALCON_INIT_VAR(t8);
					phalcon_read_property(&t8, v4, "items", sizeof("items")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r17);
					phalcon_array_append(t8, r17 TSRMLS_CC);
					phalcon_update_property_zval(v4, "items", strlen("items"), t8 TSRMLS_CC);
					PHALCON_INIT_VAR(r18);
					is_smaller_or_equal_function(r18, v0, v8 TSRMLS_CC);
					if (zend_is_true(r18)) {
						goto we7;
					}
					PHALCON_SEPARATE(v8);
					increment_function(v8);
					goto ws7;
					we7:
					if(0) { };
				}
			}
		}
	}
	phalcon_update_property_long(v4, "first", strlen("first"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r20);
	phalcon_add_function(r20, v5, v0 TSRMLS_CC);
	PHALCON_INIT_VAR(r21);
	is_smaller_function(r21, r20, v3 TSRMLS_CC);
	if (zend_is_true(r21)) {
		PHALCON_INIT_VAR(t9);
		ZVAL_LONG(t9, 1);
		PHALCON_ALLOC_ZVAL_MM(r22);
		phalcon_add_function(r22, v2, t9 TSRMLS_CC);
		r19 = r22;
	} else {
		PHALCON_ALLOC_ZVAL_MM(r24);
		phalcon_add_function(r24, v5, v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r25);
		is_equal_function(r25, r24, v3 TSRMLS_CC);
		if (zend_is_true(r25)) {
			r23 = v3;
		} else {
			PHALCON_ALLOC_ZVAL_MM(r26);
			div_function(r26, v3, v0 TSRMLS_CC);
			convert_to_long(r26);
			PHALCON_INIT_VAR(t10);
			ZVAL_LONG(t10, 1);
			PHALCON_ALLOC_ZVAL_MM(r27);
			phalcon_add_function(r27, r26, t10 TSRMLS_CC);
			r23 = r27;
		}
		r19 = r23;
	}
	phalcon_update_property_zval(v4, "next", strlen("next"), r19 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t11);
	phalcon_read_property(&t11, v4, "next", sizeof("next")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(r28);
	is_smaller_function(r28, v6, t11 TSRMLS_CC);
	if (zend_is_true(r28)) {
		phalcon_update_property_zval(v4, "next", strlen("next"), v6 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(t12);
	ZVAL_LONG(t12, 1);
	PHALCON_INIT_VAR(r30);
	is_smaller_function(r30, t12, v2 TSRMLS_CC);
	if (zend_is_true(r30)) {
		PHALCON_INIT_VAR(t13);
		ZVAL_LONG(t13, 1);
		PHALCON_ALLOC_ZVAL_MM(r31);
		sub_function(r31, v2, t13 TSRMLS_CC);
		r29 = r31;
	} else {
		PHALCON_INIT_VAR(t14);
		ZVAL_LONG(t14, 1);
		r29 = t14;
	}
	phalcon_update_property_zval(v4, "before", strlen("before"), r29 TSRMLS_CC);
	phalcon_update_property_zval(v4, "current", strlen("current"), v2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r33);
	mod_function(r33, v3, v0 TSRMLS_CC);
	if (zend_is_true(r33)) {
		PHALCON_ALLOC_ZVAL_MM(r34);
		div_function(r34, v3, v0 TSRMLS_CC);
		convert_to_long(r34);
		PHALCON_INIT_VAR(t15);
		ZVAL_LONG(t15, 1);
		PHALCON_ALLOC_ZVAL_MM(r35);
		phalcon_add_function(r35, r34, t15 TSRMLS_CC);
		r32 = r35;
	} else {
		PHALCON_ALLOC_ZVAL_MM(r36);
		div_function(r36, v3, v0 TSRMLS_CC);
		r32 = r36;
	}
	phalcon_update_property_zval(v4, "total_pages", strlen("total_pages"), r32 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t16);
	phalcon_read_property(&t16, v4, "total_pages", sizeof("total_pages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_zval(v4, "last", strlen("last"), t16 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v4);
}

PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_config", strlen("_config"), v0 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_limitRows", strlen("_limitRows"), r0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "page", strlen("page")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v0, "page", strlen("page"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), r1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

