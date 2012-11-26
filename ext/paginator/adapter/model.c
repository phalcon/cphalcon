
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using Phalcon\Model resultsets.
 *
 */


/**
 * Phalcon\Paginator\Adapter\Model initializer
 */
PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_Model){

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, Model, paginator_adapter_model, phalcon_paginator_adapter_model_method_entry, 0);

	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_model_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\Model constructor
 *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct){

	zval *config, *limit, *page;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_config"), config TSRMLS_CC);
	eval_int = phalcon_array_isset_string(config, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, config, SL("limit"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(config, SS("page"));
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
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate){

	zval *show, *config, *items, *page_number = NULL, *zero, *one;
	zval *smaller, *n, *page, *last_show_page, *start;
	zval *last_page, *possible_pages = NULL, *total_pages;
	zval *compare = NULL, *page_items, *i, *valid = NULL, *current = NULL, *maximum_pages;
	zval *next = NULL, *additional_page, *before = NULL, *remainder;
	zval *pages_total = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

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
		PHALCON_INIT_NVAR(page_number);
		ZVAL_LONG(page_number, 1);
	}
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	
	PHALCON_INIT_VAR(smaller);
	is_smaller_function(smaller, show, zero TSRMLS_CC);
	if (PHALCON_IS_TRUE(smaller)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "The start page number is zero or less");
		return;
	}
	
	PHALCON_INIT_VAR(n);
	phalcon_fast_count(n, items TSRMLS_CC);
	
	PHALCON_INIT_VAR(page);
	object_init(page);
	
	PHALCON_INIT_VAR(last_show_page);
	sub_function(last_show_page, page_number, one TSRMLS_CC);
	
	PHALCON_INIT_VAR(start);
	mul_function(start, show, last_show_page TSRMLS_CC);
	
	PHALCON_INIT_VAR(last_page);
	sub_function(last_page, n, one TSRMLS_CC);
	
	PHALCON_INIT_VAR(possible_pages);
	div_function(possible_pages, last_page, show TSRMLS_CC);
	
	PHALCON_INIT_VAR(total_pages);
	PHALCON_CALL_FUNC_PARAMS_1(total_pages, "ceil", possible_pages);
	if (Z_TYPE_P(items) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Invalid data for paginator");
		return;
	}
	
	if (Z_TYPE_P(page_number) == IS_NULL) {
		PHALCON_INIT_NVAR(page_number);
		ZVAL_LONG(page_number, 0);
	}
	
	PHALCON_INIT_VAR(compare);
	is_smaller_function(compare, start, zero TSRMLS_CC);
	if (PHALCON_IS_TRUE(compare)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "The start page number is zero or less");
		return;
	}
	
	PHALCON_INIT_VAR(page_items);
	array_init(page_items);
	
	is_smaller_function(compare, zero, n TSRMLS_CC);
	if (PHALCON_IS_TRUE(compare)) {
		/** 
		 * Seek to the desired position
		 */
		is_smaller_or_equal_function(compare, start, n TSRMLS_CC);
		if (PHALCON_IS_TRUE(compare)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(items, "seek", start, PH_NO_CHECK);
		} else {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(items, "seek", one, PH_NO_CHECK);
	
			PHALCON_INIT_NVAR(page_number);
			ZVAL_LONG(page_number, 1);
		}
	
		/** 
		 * The record must be iterable
		 */
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 1);
		ph_cycle_start_0:
	
			PHALCON_INIT_NVAR(r0);
			PHALCON_CALL_METHOD(r0, items, "valid", PH_NO_CHECK);
			PHALCON_CPY_WRT(valid, r0);
			if (PHALCON_IS_NOT_TRUE(valid)) {
				goto ph_cycle_end_0;
			}
			PHALCON_INIT_NVAR(current);
			PHALCON_CALL_METHOD(current, items, "current", PH_NO_CHECK);
			phalcon_array_append(&page_items, current, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(compare);
			is_smaller_or_equal_function(compare, show, i TSRMLS_CC);
			if (PHALCON_IS_TRUE(compare)) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto ph_cycle_start_0;
		ph_cycle_end_0:
		if(0){}
	}
	
	phalcon_update_property_zval(page, SL("items"), page_items TSRMLS_CC);
	phalcon_update_property_long(page, SL("first"), 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(maximum_pages);
	phalcon_add_function(maximum_pages, start, show TSRMLS_CC);
	
	is_smaller_function(compare, maximum_pages, n TSRMLS_CC);
	if (PHALCON_IS_TRUE(compare)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 1);
		PHALCON_INIT_VAR(next);
		phalcon_add_function(next, page_number, t0 TSRMLS_CC);
	} else {
		is_equal_function(compare, maximum_pages, n TSRMLS_CC);
		if (PHALCON_IS_TRUE(compare)) {
			PHALCON_CPY_WRT(next, n);
		} else {
			div_function(possible_pages, n, show TSRMLS_CC);
	
			PHALCON_INIT_VAR(additional_page);
			phalcon_add_function(additional_page, possible_pages, one TSRMLS_CC);
	
			PHALCON_INIT_NVAR(next);
			PHALCON_CALL_FUNC_PARAMS_1(next, "intval", additional_page);
		}
	}
	
	is_smaller_function(compare, total_pages, next TSRMLS_CC);
	if (PHALCON_IS_TRUE(compare)) {
		PHALCON_CPY_WRT(next, total_pages);
	}
	
	phalcon_update_property_zval(page, SL("next"), next TSRMLS_CC);
	
	is_smaller_function(compare, one, page_number TSRMLS_CC);
	if (PHALCON_IS_TRUE(compare)) {
		PHALCON_INIT_VAR(before);
		sub_function(before, page_number, one TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(before);
		ZVAL_LONG(before, 1);
	}
	
	phalcon_update_property_zval(page, SL("before"), before TSRMLS_CC);
	phalcon_update_property_zval(page, SL("current"), page_number TSRMLS_CC);
	
	PHALCON_INIT_VAR(remainder);
	mod_function(remainder, n, show TSRMLS_CC);
	
	div_function(possible_pages, n, show TSRMLS_CC);
	if (!phalcon_compare_strict_long(remainder, 0 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(next);
		phalcon_add_function(next, possible_pages, one TSRMLS_CC);
	
		PHALCON_INIT_VAR(pages_total);
		PHALCON_CALL_FUNC_PARAMS_1(pages_total, "intval", next);
	} else {
		PHALCON_CPY_WRT(pages_total, possible_pages);
	}
	
	phalcon_update_property_zval(page, SL("last"), pages_total TSRMLS_CC);
	phalcon_update_property_zval(page, SL("total_pages"), pages_total TSRMLS_CC);
	
	RETURN_CTOR(page);
}

