
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
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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

	zval *config = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_config", strlen("_config"), config TSRMLS_CC);
	eval_int = phalcon_array_isset_string(config, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, config, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_limitRows", strlen("_limitRows"), r0 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(config, "page", strlen("page")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, config, "page", strlen("page"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), r1 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setCurrentPage){

	zval *page = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &page) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_page", strlen("_page"), page TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate){

	zval *show = NULL, *items = NULL, *page_number = NULL, *n = NULL, *page = NULL, *start = NULL, *total_pages = NULL;
	zval *i = NULL, *next = NULL, *before = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_limitRows", sizeof("_limitRows")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(show, t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_config", sizeof("_config")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, t1, "data", strlen("data"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(items, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_page", sizeof("_page")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(page_number, t2);
	if (Z_TYPE_P(page_number) == IS_NULL) {
		PHALCON_INIT_VAR(page_number);
		ZVAL_LONG(page_number, 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_count(r1, items TSRMLS_CC);
	PHALCON_CPY_WRT(n, r1);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(page, i0);
	
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	sub_function(r2, page_number, t3 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	mul_function(r3, show, r2 TSRMLS_CC);
	PHALCON_CPY_WRT(start, r3);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	sub_function(r5, n, t4 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	div_function(r6, r5, show TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r4, "ceil", r6, 0x01C);
	PHALCON_CPY_WRT(total_pages, r4);
	if (Z_TYPE_P(items) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Invalid data for paginator");
		return;
	}
	
	if (Z_TYPE_P(page_number) == IS_NULL) {
		PHALCON_INIT_VAR(page_number);
		ZVAL_LONG(page_number, 0);
	}
	
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 0);
	
	PHALCON_INIT_VAR(r7);
	is_smaller_function(r7, start, t5 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "The start page number is zero or less");
		return;
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(page, "items", strlen("items"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 0);
	
	PHALCON_INIT_VAR(r8);
	is_smaller_function(r8, t6, n TSRMLS_CC);
	if (zend_is_true(r8)) {
		PHALCON_INIT_VAR(r9);
		is_smaller_or_equal_function(r9, start, n TSRMLS_CC);
		if (zend_is_true(r9)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(items, "seek", start, PHALCON_NO_CHECK);
		} else {
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(items, "seek", c0, PHALCON_NO_CHECK);
			
			PHALCON_INIT_VAR(page_number);
			ZVAL_LONG(page_number, 1);
		}
		
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 1);
		ws_e435_0:
			
			PHALCON_INIT_VAR(r10);
			PHALCON_CALL_METHOD(r10, items, "valid", PHALCON_NO_CHECK);
			if (Z_TYPE_P(r10) != IS_BOOL || (Z_TYPE_P(r10) == IS_BOOL && !Z_BVAL_P(r10))) {
				goto we_e435_0;
			}
			PHALCON_INIT_VAR(r11);
			PHALCON_CALL_METHOD(r11, items, "current", PHALCON_NO_CHECK);
			PHALCON_INIT_VAR(t7);
			phalcon_read_property(&t7, page, "items", sizeof("items")-1, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_append(&t7, r11, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
			phalcon_update_property_zval(page, "items", strlen("items"), t7 TSRMLS_CC);
			
			PHALCON_INIT_VAR(r12);
			is_smaller_or_equal_function(r12, show, i TSRMLS_CC);
			if (zend_is_true(r12)) {
				goto we_e435_0;
			}
			
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto ws_e435_0;
		we_e435_0:
		if(0){}
	}
	
	phalcon_update_property_long(page, "first", strlen("first"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r13);
	phalcon_add_function(r13, start, show TSRMLS_CC);
	
	PHALCON_INIT_VAR(r14);
	is_smaller_function(r14, r13, n TSRMLS_CC);
	if (zend_is_true(r14)) {
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 1);
		PHALCON_ALLOC_ZVAL_MM(r15);
		phalcon_add_function(r15, page_number, t8 TSRMLS_CC);
		PHALCON_CPY_WRT(next, r15);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r16);
		phalcon_add_function(r16, start, show TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r17);
		is_equal_function(r17, r16, n TSRMLS_CC);
		if (zend_is_true(r17)) {
			PHALCON_CPY_WRT(next, n);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_ALLOC_ZVAL_MM(r19);
			div_function(r19, n, show TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_1(r18, "intval", r19, 0x020);
			PHALCON_INIT_VAR(t9);
			ZVAL_LONG(t9, 1);
			PHALCON_ALLOC_ZVAL_MM(r20);
			phalcon_add_function(r20, r18, t9 TSRMLS_CC);
			PHALCON_CPY_WRT(next, r20);
		}
	}
	
	PHALCON_INIT_VAR(r21);
	is_smaller_function(r21, total_pages, next TSRMLS_CC);
	if (zend_is_true(r21)) {
		PHALCON_CPY_WRT(next, total_pages);
	}
	
	phalcon_update_property_zval(page, "next", strlen("next"), next TSRMLS_CC);
	
	PHALCON_INIT_VAR(t10);
	ZVAL_LONG(t10, 1);
	
	PHALCON_INIT_VAR(r22);
	is_smaller_function(r22, t10, page_number TSRMLS_CC);
	if (zend_is_true(r22)) {
		PHALCON_INIT_VAR(t11);
		ZVAL_LONG(t11, 1);
		PHALCON_ALLOC_ZVAL_MM(r23);
		sub_function(r23, page_number, t11 TSRMLS_CC);
		PHALCON_CPY_WRT(before, r23);
	} else {
		PHALCON_INIT_VAR(before);
		ZVAL_LONG(before, 1);
	}
	
	phalcon_update_property_zval(page, "before", strlen("before"), before TSRMLS_CC);
	phalcon_update_property_zval(page, "current", strlen("current"), page_number TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r24);
	mod_function(r24, n, show TSRMLS_CC);
	if (zend_is_true(r24)) {
		PHALCON_ALLOC_ZVAL_MM(r25);
		PHALCON_ALLOC_ZVAL_MM(r26);
		div_function(r26, n, show TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r25, "intval", r26, 0x020);
		PHALCON_INIT_VAR(t12);
		ZVAL_LONG(t12, 1);
		PHALCON_ALLOC_ZVAL_MM(r27);
		phalcon_add_function(r27, r25, t12 TSRMLS_CC);
		PHALCON_CPY_WRT(total_pages, r27);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r28);
		div_function(r28, n, show TSRMLS_CC);
		PHALCON_CPY_WRT(total_pages, r28);
	}
	
	phalcon_update_property_zval(page, "last", strlen("last"), total_pages TSRMLS_CC);
	phalcon_update_property_zval(page, "total_pages", strlen("total_pages"), total_pages TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(page);
}

