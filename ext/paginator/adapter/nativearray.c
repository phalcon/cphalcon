
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
 * Phalcon\Paginator\Adapter\NativeArray
 *
 * Component of pagination by array data
 *
 */


/**
 * Phalcon\Paginator\Adapter\NativeArray initializer
 */
PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray){

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, NativeArray, paginator_adapter_nativearray, phalcon_paginator_adapter_nativearray_method_entry, 0);

	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_nativearray_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\NativeArray constructor
  *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct){

	zval *config, *limit, *page;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &config) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_config"), config TSRMLS_CC);
	if (phalcon_array_isset_string(config, SS("limit"))) {
		PHALCON_OBS_VAR(limit);
		phalcon_array_fetch_string(&limit, config, SL("limit"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string(config, SS("page"))) {
		PHALCON_OBS_VAR(page);
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
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, setCurrentPage){

	zval *page;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &page) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_page"), page TSRMLS_CC);
	
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate){

	zval *show, *items, *page_number = NULL, *n, *page, *start, *total_pages = NULL;
	zval *next = NULL, *before = NULL, *res, *div, *t_pages = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(show);
	phalcon_read_property(&show, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_config"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(items);
	phalcon_array_fetch_string(&items, t0, SL("data"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(page_number);
	phalcon_read_property(&page_number, this_ptr, SL("_page"), PH_NOISY_CC);
	if (Z_TYPE_P(page_number) == IS_NULL) {
		PHALCON_INIT_NVAR(page_number);
		ZVAL_LONG(page_number, 1);
	}
	
	PHALCON_INIT_VAR(n);
	phalcon_fast_count(n, items TSRMLS_CC);
	
	PHALCON_INIT_VAR(page);
	object_init(page);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	
	PHALCON_INIT_VAR(r0);
	sub_function(r0, page_number, t1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(start);
	mul_function(start, show, r0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 1);
	
	PHALCON_INIT_VAR(r1);
	sub_function(r1, n, t2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(r2);
	div_function(r2, r1, show TSRMLS_CC);
	
	PHALCON_INIT_VAR(total_pages);
	PHALCON_CALL_FUNC_PARAMS_1(total_pages, "round", r2);
	if (Z_TYPE_P(items) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Invalid data for paginator");
		return;
	}
	
	PHALCON_INIT_VAR(r3);
	PHALCON_CALL_FUNC_PARAMS_3(r3, "array_slice", items, start, show);
	phalcon_update_property_zval(page, SL("items"), r3 TSRMLS_CC);
	phalcon_update_property_long(page, SL("first"), 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(r4);
	phalcon_add_function(r4, start, show TSRMLS_CC);
	
	PHALCON_INIT_VAR(r5);
	is_smaller_function(r5, r4, n TSRMLS_CC);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 1);
		PHALCON_INIT_VAR(next);
		phalcon_add_function(next, page_number, t3 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(r6);
		phalcon_add_function(r6, start, show TSRMLS_CC);
		PHALCON_INIT_VAR(r7);
		is_equal_function(r7, r6, n TSRMLS_CC);
		if (zend_is_true(r7)) {
			PHALCON_CPY_WRT(next, n);
		} else {
			PHALCON_INIT_VAR(r8);
			div_function(r8, n, show TSRMLS_CC);
			PHALCON_INIT_VAR(t4);
			ZVAL_LONG(t4, 1);
			PHALCON_INIT_NVAR(next);
			phalcon_add_function(next, r8, t4 TSRMLS_CC);
		}
	
		PHALCON_INIT_VAR(r9);
		PHALCON_CALL_FUNC_PARAMS_1(r9, "intval", next);
		PHALCON_CPY_WRT(next, r9);
	}
	
	PHALCON_INIT_VAR(r10);
	is_smaller_function(r10, total_pages, next TSRMLS_CC);
	if (zend_is_true(r10)) {
		PHALCON_CPY_WRT(next, total_pages);
	}
	
	phalcon_update_property_zval(page, SL("next"), next TSRMLS_CC);
	
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 1);
	
	PHALCON_INIT_VAR(r11);
	is_smaller_function(r11, t5, page_number TSRMLS_CC);
	if (zend_is_true(r11)) {
		PHALCON_INIT_VAR(t6);
		ZVAL_LONG(t6, 1);
		PHALCON_INIT_VAR(before);
		sub_function(before, page_number, t6 TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(before);
		ZVAL_LONG(before, 1);
	}
	
	phalcon_update_property_zval(page, SL("before"), before TSRMLS_CC);
	phalcon_update_property_zval(page, SL("current"), page_number TSRMLS_CC);
	
	PHALCON_INIT_VAR(res);
	mod_function(res, n, show TSRMLS_CC);
	
	PHALCON_INIT_VAR(div);
	div_function(div, n, show TSRMLS_CC);
	if (zend_is_true(res)) {
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 1);
		PHALCON_INIT_VAR(t_pages);
		phalcon_add_function(t_pages, div, t7 TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(t_pages, div);
	}
	
	PHALCON_INIT_NVAR(total_pages);
	PHALCON_CALL_FUNC_PARAMS_1(total_pages, "intval", t_pages);
	phalcon_update_property_zval(page, SL("last"), total_pages TSRMLS_CC);
	phalcon_update_property_zval(page, SL("total_pages"), total_pages TSRMLS_CC);
	
	RETURN_CTOR(page);
}

