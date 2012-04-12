
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
 * This adapter allows to paginate data using Phalcon_Model resultsets.
 *
 */

/**
 * Phalcon_Paginator_Adapter_Model constructor
 *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
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

/**
 * Set the current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setCurrentPage){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *a0 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };

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
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	PHALCON_ALLOC_ZVAL_MM(r5);
	sub_function(r5, v3, t4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r6);
	div_function(r6, r5, v0 TSRMLS_CC);
	Z_ADDREF_P(r6);
	PHALCON_CALL_FUNC_PARAMS_1(r4, "ceil", r6, 0x00D);
	Z_DELREF_P(r6);
	PHALCON_CPY_WRT(v6, r4);
	if (Z_TYPE_P(v1) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_paginator_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "Invalid data for paginator", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(v2) == IS_NULL) {
		PHALCON_INIT_VAR(v2);
		ZVAL_LONG(v2, 0);
	}
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 0);
	PHALCON_INIT_VAR(r7);
	is_smaller_function(r7, v5, t5 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_paginator_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "The start page number is zero or less", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i2 TSRMLS_CC);
		Z_ADDREF_P(i2);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(v4, "items", strlen("items"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 0);
	PHALCON_INIT_VAR(r8);
	is_smaller_function(r8, t6, v3 TSRMLS_CC);
	if (zend_is_true(r8)) {
		PHALCON_INIT_VAR(r9);
		is_smaller_or_equal_function(r9, v5, v3 TSRMLS_CC);
		if (zend_is_true(r9)) {
			Z_ADDREF_P(v5);
			p4[0] = v5;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "seek", 1, p4, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p4[0]);
		} else {
			PHALCON_INIT_VAR(p5[0]);
			ZVAL_LONG(p5[0], 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "seek", 1, p5, PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(v2);
			ZVAL_LONG(v2, 1);
		}
		PHALCON_INIT_VAR(v7);
		ZVAL_LONG(v7, 1);
		ws7:
		PHALCON_INIT_VAR(r10);
		PHALCON_CALL_METHOD(r10, v1, "valid", PHALCON_CALL_DEFAULT);
		if (!zend_is_true(r10)) {
			goto we7;
		}
		PHALCON_INIT_VAR(r11);
		PHALCON_CALL_METHOD(r11, v1, "current", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_VAR(t7);
		phalcon_read_property(&t7, v4, "items", sizeof("items")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r11);
		phalcon_array_append(t7, r11 TSRMLS_CC);
		phalcon_update_property_zval(v4, "items", strlen("items"), t7 TSRMLS_CC);
		PHALCON_INIT_VAR(r12);
		is_smaller_or_equal_function(r12, v0, v7 TSRMLS_CC);
		if (zend_is_true(r12)) {
			goto we7;
		}
		PHALCON_SEPARATE(v7);
		increment_function(v7);
		goto ws7;
		we7:
		if(0) { };
	}
	phalcon_update_property_long(v4, "first", strlen("first"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r13);
	phalcon_add_function(r13, v5, v0 TSRMLS_CC);
	PHALCON_INIT_VAR(r14);
	is_smaller_function(r14, r13, v3 TSRMLS_CC);
	if (zend_is_true(r14)) {
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 1);
		PHALCON_ALLOC_ZVAL_MM(r15);
		phalcon_add_function(r15, v2, t8 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r15);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r16);
		phalcon_add_function(r16, v5, v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r17);
		is_equal_function(r17, r16, v3 TSRMLS_CC);
		if (zend_is_true(r17)) {
			PHALCON_CPY_WRT(v8, v3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_ALLOC_ZVAL_MM(r19);
			div_function(r19, v3, v0 TSRMLS_CC);
			Z_ADDREF_P(r19);
			PHALCON_CALL_FUNC_PARAMS_1(r18, "intval", r19, 0x00E);
			Z_DELREF_P(r19);
			PHALCON_INIT_VAR(t9);
			ZVAL_LONG(t9, 1);
			PHALCON_ALLOC_ZVAL_MM(r20);
			phalcon_add_function(r20, r18, t9 TSRMLS_CC);
			PHALCON_CPY_WRT(v8, r20);
		}
	}
	PHALCON_INIT_VAR(r21);
	is_smaller_function(r21, v6, v8 TSRMLS_CC);
	if (zend_is_true(r21)) {
		PHALCON_CPY_WRT(v8, v6);
	}
	phalcon_update_property_zval(v4, "next", strlen("next"), v8 TSRMLS_CC);
	PHALCON_INIT_VAR(t10);
	ZVAL_LONG(t10, 1);
	PHALCON_INIT_VAR(r22);
	is_smaller_function(r22, t10, v2 TSRMLS_CC);
	if (zend_is_true(r22)) {
		PHALCON_INIT_VAR(t11);
		ZVAL_LONG(t11, 1);
		PHALCON_ALLOC_ZVAL_MM(r23);
		sub_function(r23, v2, t11 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r23);
	} else {
		PHALCON_INIT_VAR(v9);
		ZVAL_LONG(v9, 1);
	}
	phalcon_update_property_zval(v4, "before", strlen("before"), v9 TSRMLS_CC);
	phalcon_update_property_zval(v4, "current", strlen("current"), v2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r24);
	mod_function(r24, v3, v0 TSRMLS_CC);
	if (zend_is_true(r24)) {
		PHALCON_ALLOC_ZVAL_MM(r25);
		PHALCON_ALLOC_ZVAL_MM(r26);
		div_function(r26, v3, v0 TSRMLS_CC);
		Z_ADDREF_P(r26);
		PHALCON_CALL_FUNC_PARAMS_1(r25, "intval", r26, 0x00E);
		Z_DELREF_P(r26);
		PHALCON_INIT_VAR(t12);
		ZVAL_LONG(t12, 1);
		PHALCON_ALLOC_ZVAL_MM(r27);
		phalcon_add_function(r27, r25, t12 TSRMLS_CC);
		PHALCON_CPY_WRT(v10, r27);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r28);
		div_function(r28, v3, v0 TSRMLS_CC);
		PHALCON_CPY_WRT(v10, r28);
	}
	phalcon_update_property_zval(v4, "last", strlen("last"), v10 TSRMLS_CC);
	phalcon_update_property_zval(v4, "total_pages", strlen("total_pages"), v10 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v4);
}

