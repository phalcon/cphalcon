
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * Pagination using a PHQL query builder as source of data
 *
 *<code>
 *  $builder = $this->modelsManager->createBuilder()
 *                   ->columns('id, name')
 *                   ->from('Robots')
 *                   ->orderBy('name');
 *
 *  $paginator = new Phalcon\Paginator\Adapter\QueryBuilder(array(
 *      "builder" => $builder,
 *      "limit"=> 20,
 *      "page" => 1
 *  ));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, QueryBuilder, phalcon, paginator_adapter_querybuilder, phalcon_paginator_adapter_querybuilder_method_entry, 0);

	/**
	 * Configuration of paginator by model
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Paginator's data
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_builder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Number of rows to be shown in the paginator. By default is null
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Current page in paginate
	 */
	zend_declare_property_long(phalcon_paginator_adapter_querybuilder_ce, SL("_page"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_querybuilder_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * @param array config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct) {

	zval *config_param = NULL, *builder, *limit, *page;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(config, config_param);


	zephir_update_property_this(this_ptr, SL("_config"), config TSRMLS_CC);
	ZEPHIR_OBS_VAR(builder);
	if (!(zephir_array_isset_string_fetch(&builder, config, SS("builder"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'builder' is required", "phalcon/paginator/adapter/querybuilder.zep", 78);
		return;
	} else {
		zephir_update_property_this(this_ptr, SL("_builder"), builder TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(limit);
	if (!(zephir_array_isset_string_fetch(&limit, config, SS("limit"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'limit' is required", "phalcon/paginator/adapter/querybuilder.zep", 84);
		return;
	} else {
		zephir_update_property_this(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&page, config, SS("page"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the current page number
 *
 * @param int page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setCurrentPage) {

	zval *currentPage_param = NULL, *_0;
	int currentPage;

	zephir_fetch_params(0, 1, 0, &currentPage_param);

	currentPage = zephir_get_intval(currentPage_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, currentPage);
	zephir_update_property_this(this_ptr, SL("_page"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get the current page number
 *
 * @return int page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage) {


	RETURN_MEMBER(this_ptr, "_page");

}

/**
 * Set current rows limit
 *
 * @param int $limit
 *
 * @return Phalcon\Paginator\Adapter\QueryBuilder $this Fluent interface
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setLimit) {

	zval *limitRows_param = NULL, *_0;
	int limitRows;

	zephir_fetch_params(0, 1, 0, &limitRows_param);

	limitRows = zephir_get_intval(limitRows_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limitRows);
	zephir_update_property_this(this_ptr, SL("_limitRows"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get current rows limit
 *
 * @return int $limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getLimit) {


	RETURN_MEMBER(this_ptr, "_limitRows");

}

/**
 * Set query builder object
 *
 * @param Phalcon\Mvc\Model\Query\BuilderInterface $builder
 *
 * @return Phalcon\Paginator\Adapter\QueryBuilder $this Fluent interface
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder) {

	zval *builder;

	zephir_fetch_params(0, 1, 0, &builder);



	if (!(zephir_instance_of_ev(builder, phalcon_mvc_model_query_builder_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'builder' must be an instance of 'Phalcon\\Mvc\\Model\\Query\\Builder'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_builder"), builder TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get query builder object
 *
 * @return Phalcon\Mvc\Model\Query\BuilderInterface $builder
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder) {


	RETURN_MEMBER(this_ptr, "_builder");

}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate) {

	int numberPage, before, ZEPHIR_LAST_CALL_STATUS;
	double totalPages;
	zval *originalBuilder, *builder, *totalBuilder, *limit, *number, *query = NULL, *page, *items = NULL, *totalQuery = NULL, *result = NULL, *row = NULL, *rowcount = NULL, *intTotalPages, *next = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, _5;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(originalBuilder);
	zephir_read_property_this(&originalBuilder, this_ptr, SL("_builder"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(builder);
	if (zephir_clone(builder, originalBuilder TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(totalBuilder);
	if (zephir_clone(totalBuilder, builder TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(limit);
	zephir_read_property_this(&limit, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_page"), PH_NOISY_CC);
	numberPage = zephir_get_intval(_0);
	if (!(numberPage)) {
		numberPage = 1;
	}
	ZEPHIR_INIT_VAR(number);
	ZVAL_LONG(number, (zephir_get_numberval(limit) * ((numberPage - 1))));
	if (ZEPHIR_LT(number, limit)) {
		ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, limit);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, limit, number);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&query, builder, "getquery", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_zval(page, SL("first"), _1 TSRMLS_CC);
	if (numberPage == 1) {
		before = 1;
	} else {
		before = (numberPage - 1);
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, before);
	zephir_update_property_zval(page, SL("before"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&items, query, "execute", NULL);
	zephir_check_call_status();
	zephir_update_property_zval(page, SL("items"), items TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "COUNT(*) [rowcount]", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, totalBuilder, "columns", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_CALL_METHOD(NULL, totalBuilder, "orderby", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&totalQuery, totalBuilder, "getquery", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, totalQuery, "execute", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&row, result, "getfirst", NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, row, SL("rowcount"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(rowcount, _3);
	ZEPHIR_INIT_VAR(_4);
	div_function(_4, rowcount, limit TSRMLS_CC);
	totalPages = zephir_get_numberval(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_DOUBLE(&_5, totalPages);
	ZEPHIR_INIT_VAR(intTotalPages);
	ZVAL_LONG(intTotalPages, zephir_get_intval(&_5));
	if (!ZEPHIR_IS_DOUBLE(intTotalPages, totalPages)) {
		totalPages = (double) ((zephir_get_numberval(intTotalPages) + 1));
	}
	if (numberPage < totalPages) {
		ZEPHIR_INIT_VAR(next);
		ZVAL_LONG(next, (numberPage + 1));
	} else {
		ZEPHIR_INIT_NVAR(next);
		ZVAL_DOUBLE(next, totalPages);
	}
	zephir_update_property_zval(page, SL("next"), next TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, totalPages);
	zephir_update_property_zval(page, SL("last"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, numberPage);
	zephir_update_property_zval(page, SL("current"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, totalPages);
	zephir_update_property_zval(page, SL("total_pages"), _1 TSRMLS_CC);
	zephir_update_property_zval(page, SL("total_items"), rowcount TSRMLS_CC);
	RETURN_CCTOR(page);

}

