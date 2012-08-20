
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
#include "kernel/exception.h"
#include "kernel/operators.h"

/**
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using Phalcon\Model resultsets.
 *
 */

/**
 * Phalcon\Paginator\Adapter\Model constructor
 *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct){

	zval *config = NULL, *limit = NULL, *page = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_config"), config TSRMLS_CC);
	eval_int = phalcon_array_isset_string(config, SL("limit")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, config, SL("limit"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(config, SL("page")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(page);
		phalcon_array_fetch_string(&page, config, SL("page"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_page"), page TSRMLS_CC);
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

	phalcon_update_property_zval(this_ptr, SL("_page"), page TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate){

	zval *show = NULL, *config = NULL, *items = NULL, *page_number = NULL, *n = NULL, *page = NULL;
	zval *start = NULL, *total_pages = NULL, *pitems = NULL, *i = NULL, *valid = NULL, *current = NULL;
	zval *next = NULL, *before = NULL, *pages_total = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(show);
	phalcon_read_property(&show, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(config);
	phalcon_read_property(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(items);
	phalcon_array_fetch_string(&items, config, SL("data"), PH_NOISY_CC);
	
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
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	sub_function(r0, page_number, t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(start);
	mul_function(start, show, r0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	sub_function(r1, n, t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	div_function(r2, r1, show TSRMLS_CC);
	
	PHALCON_INIT_VAR(total_pages);
	PHALCON_CALL_FUNC_PARAMS_1(total_pages, "ceil", r2);
	if (Z_TYPE_P(items) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Invalid data for paginator");
		return;
	}
	
	if (Z_TYPE_P(page_number) == IS_NULL) {
		PHALCON_INIT_VAR(page_number);
		ZVAL_LONG(page_number, 0);
	}
	
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 0);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_smaller_function(r3, start, t2 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "The start page number is zero or less");
		return;
	}
	
	PHALCON_INIT_VAR(pitems);
	array_init(pitems);
	
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 0);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_smaller_function(r4, t3, n TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		is_smaller_or_equal_function(r5, start, n TSRMLS_CC);
		if (zend_is_true(r5)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(items, "seek", start, PH_NO_CHECK);
		} else {
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(items, "seek", c0, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(page_number);
			ZVAL_LONG(page_number, 1);
		}
		
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 1);
		ws_e435_0:
			
			PHALCON_INIT_VAR(r6);
			PHALCON_CALL_METHOD(r6, items, "valid", PH_NO_CHECK);
			PHALCON_CPY_WRT(valid, r6);
			if (Z_TYPE_P(valid) != IS_BOOL || (Z_TYPE_P(valid) == IS_BOOL && !Z_BVAL_P(valid))) {
				goto we_e435_0;
			}
			PHALCON_INIT_VAR(current);
			PHALCON_CALL_METHOD(current, items, "current", PH_NO_CHECK);
			phalcon_array_append(&pitems, current, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(r7);
			is_smaller_or_equal_function(r7, show, i TSRMLS_CC);
			if (zend_is_true(r7)) {
				goto we_e435_0;
			}
			
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto ws_e435_0;
		we_e435_0:
		if(0){}
	}
	
	phalcon_update_property_zval(page, SL("items"), pitems TSRMLS_CC);
	phalcon_update_property_long(page, SL("first"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	phalcon_add_function(r8, start, show TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	is_smaller_function(r9, r8, n TSRMLS_CC);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 1);
		PHALCON_INIT_VAR(next);
		phalcon_add_function(next, page_number, t4 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r10);
		phalcon_add_function(r10, start, show TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r11);
		is_equal_function(r11, r10, n TSRMLS_CC);
		if (zend_is_true(r11)) {
			PHALCON_CPY_WRT(next, n);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r12);
			div_function(r12, n, show TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r13);
			PHALCON_CALL_FUNC_PARAMS_1(r13, "intval", r12);
			PHALCON_INIT_VAR(t5);
			ZVAL_LONG(t5, 1);
			PHALCON_INIT_VAR(next);
			phalcon_add_function(next, r13, t5 TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r14);
	is_smaller_function(r14, total_pages, next TSRMLS_CC);
	if (zend_is_true(r14)) {
		PHALCON_CPY_WRT(next, total_pages);
	}
	
	phalcon_update_property_zval(page, SL("next"), next TSRMLS_CC);
	
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r15);
	is_smaller_function(r15, t6, page_number TSRMLS_CC);
	if (zend_is_true(r15)) {
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 1);
		PHALCON_INIT_VAR(before);
		sub_function(before, page_number, t7 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(before);
		ZVAL_LONG(before, 1);
	}
	
	phalcon_update_property_zval(page, SL("before"), before TSRMLS_CC);
	phalcon_update_property_zval(page, SL("current"), page_number TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r16);
	mod_function(r16, n, show TSRMLS_CC);
	if (zend_is_true(r16)) {
		PHALCON_ALLOC_ZVAL_MM(r17);
		div_function(r17, n, show TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CALL_FUNC_PARAMS_1(r18, "intval", r17);
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 1);
		PHALCON_INIT_VAR(pages_total);
		phalcon_add_function(pages_total, r18, t8 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(pages_total);
		div_function(pages_total, n, show TSRMLS_CC);
	}
	
	phalcon_update_property_zval(page, SL("last"), pages_total TSRMLS_CC);
	phalcon_update_property_zval(page, SL("total_pages"), pages_total TSRMLS_CC);
	
	RETURN_CTOR(page);
}

