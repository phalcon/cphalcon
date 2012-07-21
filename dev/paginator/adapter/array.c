
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Paginator\Adapter\Array
 *
 * Component of pagination by array data
 *
 */

/**
 * Phalcon\Paginator\Adapter\Array constructor
  *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Array, __construct){

	zval *config = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_config"), config TSRMLS_CC);
	eval_int = phalcon_array_isset_string(config, SL("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, config, SL("limit"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_limitRows"), r0 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(config, SL("page")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, config, SL("page"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_page"), r1 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Array, setCurrentPage){

	zval *page = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &page) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_page"), page TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Array, getPaginate){

	zval *show = NULL, *items = NULL, *page_number = NULL, *n = NULL, *page = NULL, *start = NULL, *total_pages = NULL;
	zval *next = NULL, *before = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(show);
	phalcon_read_property(&show, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_config"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(items);
	phalcon_array_fetch_string(&items, t0, SL("data"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(page_number);
	phalcon_read_property(&page_number, this_ptr, SL("_page"), PH_NOISY_CC);
	if (Z_TYPE_P(page_number) == IS_NULL) {
		PHALCON_INIT_VAR(page_number);
		ZVAL_LONG(page_number, 1);
	}
	
	PHALCON_INIT_VAR(n);
	phalcon_fast_count(n, items TSRMLS_CC);
	
	PHALCON_INIT_VAR(page);
	object_init(page);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	sub_function(r0, page_number, t1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(start);
	mul_function(start, show, r0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_count(r1, items TSRMLS_CC);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	sub_function(r2, r1, t2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	div_function(r3, r2, show TSRMLS_CC);
	
	PHALCON_INIT_VAR(total_pages);
	PHALCON_CALL_FUNC_PARAMS_1(total_pages, "round", r3);
	if (Z_TYPE_P(items) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Invalid data for paginator");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_FUNC_PARAMS_3(r4, "array_slice", items, start, show);
	phalcon_update_property_zval(page, SL("items"), r4 TSRMLS_CC);
	phalcon_update_property_long(page, SL("first"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_add_function(r5, start, show TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_smaller_function(r6, r5, n TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 1);
		PHALCON_INIT_VAR(next);
		phalcon_add_function(next, page_number, t3 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_add_function(r7, start, show TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		is_equal_function(r8, r7, n TSRMLS_CC);
		if (zend_is_true(r8)) {
			PHALCON_CPY_WRT(next, n);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_ALLOC_ZVAL_MM(r10);
			div_function(r10, n, show TSRMLS_CC);
			phalcon_cast(r9, r10, IS_LONG);
			PHALCON_INIT_VAR(t4);
			ZVAL_LONG(t4, 1);
			PHALCON_INIT_VAR(next);
			phalcon_add_function(next, r9, t4 TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r11);
	is_smaller_function(r11, total_pages, next TSRMLS_CC);
	if (zend_is_true(r11)) {
		PHALCON_CPY_WRT(next, total_pages);
	}
	
	phalcon_update_property_zval(page, SL("next"), next TSRMLS_CC);
	
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r12);
	is_smaller_function(r12, t5, page_number TSRMLS_CC);
	if (zend_is_true(r12)) {
		PHALCON_INIT_VAR(t6);
		ZVAL_LONG(t6, 1);
		PHALCON_INIT_VAR(before);
		sub_function(before, page_number, t6 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(before);
		ZVAL_LONG(before, 1);
	}
	
	phalcon_update_property_zval(page, SL("before"), before TSRMLS_CC);
	phalcon_update_property_zval(page, SL("current"), page_number TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r14);
	mod_function(r14, n, show TSRMLS_CC);
	if (zend_is_true(r14)) {
		PHALCON_ALLOC_ZVAL_MM(r15);
		
		PHALCON_ALLOC_ZVAL_MM(r16);
		div_function(r16, n, show TSRMLS_CC);
		phalcon_cast(r15, r16, IS_LONG);
		
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 1);
		
		PHALCON_ALLOC_ZVAL_MM(r17);
		phalcon_add_function(r17, r15, t7 TSRMLS_CC);
		r13 = r17;
	} else {
		
		PHALCON_ALLOC_ZVAL_MM(r18);
		div_function(r18, n, show TSRMLS_CC);
		r13 = r18;
	}
	PHALCON_CPY_WRT(total_pages, r13);
	phalcon_update_property_zval(page, SL("last"), total_pages TSRMLS_CC);
	phalcon_update_property_zval(page, SL("total_pages"), total_pages TSRMLS_CC);
	
	RETURN_CTOR(page);
}

