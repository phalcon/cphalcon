
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * Component of pagination by array data
 */


/**
 * Phalcon\Paginator\Adapter\QueryBuilder initializer
 */
PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder){

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, QueryBuilder, paginator_adapter_querybuilder, phalcon_paginator_adapter_querybuilder_method_entry, 0);

	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_builder"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_paginator_adapter_querybuilder_ce, SL("_page"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_querybuilder_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct){

	zval *config, *builder, *limit, *page;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &config) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_config"), config TSRMLS_CC);
	if (!phalcon_array_isset_string(config, SS("builder"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Parameter 'builder' is required");
		return;
	} else {
		PHALCON_OBS_VAR(builder);
		phalcon_array_fetch_string(&builder, config, SL("builder"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_builder"), builder TSRMLS_CC);
	}
	
	if (!phalcon_array_isset_string(config, SS("limit"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Parameter 'limit' is required");
		return;
	} else {
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
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setCurrentPage){

	zval *current_page;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &current_page) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_page"), current_page TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate){

	zval *original_builder, *builder, *total_builder;
	zval *limit, *number_page = NULL, *one, *prev_number_page;
	zval *number, *compare = NULL, *query, *page, *before = NULL, *items;
	zval *select_count, *total_query, *result, *row;
	zval *rowcount, *total_pages = NULL, *int_total_pages;
	zval *next = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(original_builder);
	phalcon_read_property_this(&original_builder, this_ptr, SL("_builder"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(builder);
	if (phalcon_clone(builder, original_builder TSRMLS_CC) == FAILURE) {
		return;
	}
	
	PHALCON_INIT_VAR(total_builder);
	if (phalcon_clone(total_builder, builder TSRMLS_CC) == FAILURE) {
		return;
	}
	
	PHALCON_OBS_VAR(limit);
	phalcon_read_property_this(&limit, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(number_page);
	phalcon_read_property_this(&number_page, this_ptr, SL("_page"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	if (!zend_is_true(number_page)) {
		PHALCON_CPY_WRT(number_page, one);
	}
	
	PHALCON_INIT_VAR(prev_number_page);
	sub_function(prev_number_page, number_page, one TSRMLS_CC);
	
	PHALCON_INIT_VAR(number);
	mul_function(number, limit, prev_number_page TSRMLS_CC);
	
	PHALCON_INIT_VAR(compare);
	is_smaller_function(compare, number, limit TSRMLS_CC);
	if (PHALCON_IS_TRUE(compare)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "limit", limit);
	} else {
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(builder, "limit", limit, number);
	}
	
	PHALCON_INIT_VAR(query);
	PHALCON_CALL_METHOD(query, builder, "getquery");
	
	PHALCON_INIT_VAR(page);
	object_init(page);
	phalcon_update_property_zval(page, SL("first"), one TSRMLS_CC);
	if (PHALCON_IS_EQUAL(number_page, one)) {
		PHALCON_CPY_WRT(before, one);
	} else {
		PHALCON_INIT_VAR(before);
		sub_function(before, number_page, one TSRMLS_CC);
	}
	
	phalcon_update_property_zval(page, SL("before"), before TSRMLS_CC);
	
	PHALCON_INIT_VAR(items);
	PHALCON_CALL_METHOD(items, query, "execute");
	phalcon_update_property_zval(page, SL("items"), items TSRMLS_CC);
	
	PHALCON_INIT_VAR(select_count);
	ZVAL_STRING(select_count, "COUNT(*) rowcount", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(total_builder, "columns", select_count);
	
	PHALCON_INIT_VAR(total_query);
	PHALCON_CALL_METHOD(total_query, total_builder, "getquery");
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD(result, total_query, "execute");
	
	PHALCON_INIT_VAR(row);
	PHALCON_CALL_METHOD(row, result, "getfirst");
	
	PHALCON_OBS_VAR(rowcount);
	phalcon_read_property(&rowcount, row, SL("rowcount"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(total_pages);
	div_function(total_pages, rowcount, limit TSRMLS_CC);
	
	PHALCON_INIT_VAR(int_total_pages);
	PHALCON_CALL_FUNC_PARAMS_1(int_total_pages, "intval", total_pages);
	if (!PHALCON_IS_EQUAL(int_total_pages, total_pages)) {
		phalcon_add_function(total_pages, int_total_pages, one TSRMLS_CC);
	}
	
	is_smaller_function(compare, number_page, total_pages TSRMLS_CC);
	if (PHALCON_IS_TRUE(compare)) {
		PHALCON_INIT_VAR(next);
		phalcon_add_function(next, number_page, one TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(next, total_pages);
	}
	
	phalcon_update_property_zval(page, SL("next"), next TSRMLS_CC);
	phalcon_update_property_zval(page, SL("last"), total_pages TSRMLS_CC);
	phalcon_update_property_zval(page, SL("current"), number_page TSRMLS_CC);
	phalcon_update_property_zval(page, SL("total_pages"), total_pages TSRMLS_CC);
	phalcon_update_property_zval(page, SL("total_items"), rowcount TSRMLS_CC);
	
	RETURN_CTOR(page);
}

