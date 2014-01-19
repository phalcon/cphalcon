
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

#include "paginator/adapter/querybuilder.h"
#include "paginator/adapterinterface.h"
#include "paginator/exception.h"
#include "mvc/model/query/builderinterface.h"

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
zend_class_entry *phalcon_paginator_adapter_querybuilder_ce;

PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setLimit);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getLimit);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder);
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_setquerybuilder, 0, 0, 1)
    ZEND_ARG_INFO(0, queryBuilder)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_paginator_adapter_querybuilder_method_entry[] = {
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, __construct, arginfo_phalcon_paginator_adapterinterface___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate, arginfo_phalcon_paginator_adapterinterface_getcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder, arginfo_phalcon_paginator_adapter_querybuilder_setquerybuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Paginator\Adapter\QueryBuilder initializer
 */
PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder){

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, QueryBuilder, paginator_adapter_querybuilder, phalcon_paginator_adapter_querybuilder_method_entry, 0);

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
	long int i_limit;

	phalcon_fetch_params(0, 1, 0, &config);
	
	if (!phalcon_array_isset_string_fetch(&builder, config, SS("builder"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "Parameter 'builder' is required");
		return;
	}
	
	PHALCON_VERIFY_INTERFACE_EX(builder, phalcon_mvc_model_query_builderinterface_ce, phalcon_paginator_exception_ce, 0);

	phalcon_update_property_this(this_ptr, SL("_builder"), builder TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&limit, config, SS("limit"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "Parameter 'limit' is required");
		return;
	}

	i_limit = phalcon_get_intval(limit);
	if (i_limit < 1) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "'limit' should be positive");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	
	if (phalcon_array_isset_string_fetch(&page, config, SS("page"))) {
		phalcon_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	}
}

/**
 * Set current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setCurrentPage){

	zval **current_page;

	phalcon_fetch_params_ex(1, 0, &current_page);
	PHALCON_ENSURE_IS_LONG(current_page);
	
	phalcon_update_property_this(this_ptr, SL("_page"), *current_page TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Get current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage){

	RETURN_MEMBER(this_ptr, "_page");
}

/**
 * Set current rows limit
 *
 * @param int $limit
 *
 * @return Phalcon\Paginator\Adapter\QueryBuilder $this Fluent interface
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setLimit){

	zval **current_limit;

	phalcon_fetch_params_ex(1, 0, &current_limit);
	PHALCON_ENSURE_IS_LONG(current_limit);

	phalcon_update_property_this(this_ptr, SL("_limitRows"), *current_limit TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Get current rows limit
 *
 * @return int $limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getLimit){

	RETURN_MEMBER(this_ptr, "_limitRows");
}

/**
 * Set query builder object
 *
 * @param Phalcon\Mvc\Model\Query\BuilderInterface $builder
 *
 * @return Phalcon\Paginator\Adapter\QueryBuilder $this Fluent interface
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder){

	zval *query_builder;

	phalcon_fetch_params(0, 1, 0, &query_builder);
	PHALCON_VERIFY_INTERFACE_EX(query_builder, phalcon_mvc_model_query_builderinterface_ce, phalcon_paginator_exception_ce, 0);

	phalcon_update_property_this(this_ptr, SL("_builder"), query_builder TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Get query builder object
 *
 * @return Phalcon\Mvc\Model\Query\BuilderInterface $builder
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder){

	RETURN_MEMBER(this_ptr, "_builder");
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate){

	zval *original_builder, *builder, *total_builder;
	zval *limit, *number_page;
	zval *query, *items, *select_count;
	zval *total_query, *result, *row, *rowcount;
	long int i_limit, i_number_page, i_number, i_before, i_rowcount;
	long int i_total_pages, i_next;
	ldiv_t tp;

	PHALCON_MM_GROW();

	original_builder = phalcon_fetch_nproperty_this(this_ptr, SL("_builder"), PH_NOISY_CC);
	
	/* Make a copy of the original builder to leave it as it is */
	PHALCON_INIT_VAR(builder);
	if (phalcon_clone(builder, original_builder TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	
	/* make a copy of the original builder to count the total of records */
	PHALCON_INIT_VAR(total_builder);
	if (phalcon_clone(total_builder, builder TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	
	limit         = phalcon_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY_CC);
	number_page   = phalcon_fetch_nproperty_this(this_ptr, SL("_page"), PH_NOISY_CC);
	i_limit       = phalcon_get_intval(limit);
	i_number_page = phalcon_get_intval(number_page);

	if (i_limit < 1) {
		/* This should never happen unless someone deliberately modified the properties of the object */
		i_limit = 10;
	}

	if (!i_number_page) {
		i_number_page = 1;
	}

	i_number = (i_number_page - 1) * i_limit;
	i_before = (i_number_page == 1) ? 1 : (i_number_page - 1);

	/* Set the limit clause avoiding negative offsets */
	if (i_number < i_limit) {
		phalcon_call_method_p1_noret(builder, "limit", limit);
	} else {
		zval *number;
		PHALCON_ALLOC_GHOST_ZVAL(number);
		ZVAL_LONG(number, i_number);
		phalcon_call_method_p2_noret(builder, "limit", limit, number);
	}
	
	PHALCON_OBS_VAR(query);
	PHALCON_OBS_VAR(items);
	PHALCON_OBS_VAR(total_query);
	PHALCON_OBS_VAR(result);
	PHALCON_OBS_VAR(row);

	phalcon_call_method_p0_ex(query, &query, builder, "getquery");

	/* Execute the query an return the requested slice of data */
	phalcon_call_method_p0_ex(items, &items, query, "execute");

	PHALCON_ALLOC_GHOST_ZVAL(select_count);
	ZVAL_STRING(select_count, "COUNT(*) [rowcount]", 1);
	
	/* Change the queried columns by a COUNT(*) */
	phalcon_call_method_p1_noret(total_builder, "columns", select_count);
	
	/* Remove the 'ORDER BY' clause, PostgreSQL requires this */
	phalcon_call_method_p1_noret(total_builder, "orderby", PHALCON_GLOBAL(z_null));
	
	/* Obtain the PHQL for the total query */
	phalcon_call_method_p0_ex(total_query, &total_query, total_builder, "getquery");
	
	/* Obtain the result of the total query */
	phalcon_call_method_p0_ex(result, &result, total_query, "execute");
	phalcon_call_method_p0_ex(row, &row, result, "getfirst");
	
	PHALCON_OBS_VAR(rowcount);
	phalcon_read_property(&rowcount, row, SL("rowcount"), PH_NOISY_CC);
	
	i_rowcount    = phalcon_get_intval(rowcount);
	tp            = ldiv(i_rowcount, i_limit);
	i_total_pages = tp.quot + (tp.rem ? 1 : 0);
	i_next        = (i_number_page < i_total_pages) ? (i_number_page + 1) : i_total_pages;

	object_init(return_value);
	phalcon_update_property_zval(return_value, SL("items"),       items TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("before"),      i_before TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("first"),       1 TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("next"),        i_next TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("last"),        i_total_pages TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("current"),     i_number_page TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("total_pages"), i_total_pages TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("total_items"), i_rowcount TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}
