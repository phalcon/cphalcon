
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
#include "mvc/model/managerinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"

#include "internal/arginfo.h"

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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_setlimit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_setquerybuilder, 0, 0, 1)
	ZEND_ARG_INFO(0, queryBuilder)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_paginator_adapter_querybuilder_method_entry[] = {
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, __construct, arginfo_phalcon_paginator_adapter_querybuilder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate, arginfo_phalcon_paginator_adapterinterface_getpaginate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setLimit, arginfo_phalcon_paginator_adapter_querybuilder_setlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getLimit, arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage, arginfo_phalcon_paginator_adapterinterface_getcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder, arginfo_phalcon_paginator_adapter_querybuilder_setquerybuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder, arginfo_empty, ZEND_ACC_PUBLIC)
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
	zval *query = NULL, *items = NULL;
	zval *total_query = NULL, *result = NULL, *row = NULL, *rowcount;
	zval *dependency_injector = NULL, *service_name, *models_manager = NULL;
	zval *models = NULL, *model_name = NULL, *model = NULL, *connection = NULL;
	zval *bind_params = NULL, *bind_types = NULL, *processed = NULL;
	zval *value = NULL, *wildcard = NULL, *string_wildcard = NULL, *processed_types = NULL;
	zval *intermediate = NULL, *tables, *table, *table_name = NULL, *select_column, *dialect = NULL, *sql_select = NULL, *sql;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	long int i_limit, i_number_page, i_number, i_before, i_rowcount;
	long int i_total_pages, i_next;
	ldiv_t tp;

	PHALCON_MM_GROW();

	original_builder = phalcon_fetch_nproperty_this(this_ptr, SL("_builder"), PH_NOISY TSRMLS_CC);
	
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
	
	limit         = phalcon_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY TSRMLS_CC);
	number_page   = phalcon_fetch_nproperty_this(this_ptr, SL("_page"), PH_NOISY TSRMLS_CC);
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
		PHALCON_CALL_METHOD(NULL, builder, "limit", limit);
	} else {
		zval *number;
		PHALCON_ALLOC_GHOST_ZVAL(number);
		ZVAL_LONG(number, i_number);
		PHALCON_CALL_METHOD(NULL, builder, "limit", limit, number);
	}
	
	PHALCON_CALL_METHOD(&query, builder, "getquery");

	/* Execute the query an return the requested slice of data */
	PHALCON_CALL_METHOD(&items, query, "execute");
	
	/* Remove the 'ORDER BY' clause, PostgreSQL requires this */
	PHALCON_CALL_METHOD(NULL, total_builder, "orderby", PHALCON_GLOBAL(z_null));
	
	/* Obtain the PHQL for the total query */
	PHALCON_CALL_METHOD(&total_query, total_builder, "getquery");

	PHALCON_CALL_METHOD(&dependency_injector, total_query, "getdi");
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "A dependency injection object is required to access internal services");
		return;
	}

	/* Get the connection through the model */
	PHALCON_INIT_VAR(service_name);
	ZVAL_STRING(service_name, "modelsManager", 1);

	PHALCON_CALL_METHOD(&models_manager, dependency_injector, "getshared", service_name);
	if (Z_TYPE_P(models_manager) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "The injected service 'modelsManager' is not valid");
		return;
	}

	PHALCON_VERIFY_INTERFACE(models_manager, phalcon_mvc_model_managerinterface_ce);

	PHALCON_CALL_METHOD(&models, builder, "getfrom");

	if (Z_TYPE_P(models) == IS_ARRAY) {
		PHALCON_INIT_VAR(model_name);
		phalcon_array_get_current(model_name, models);
	} else {
		PHALCON_CPY_WRT(model_name, models);
	}

	PHALCON_CALL_METHOD(&model, models_manager, "load", model_name);

	PHALCON_CALL_METHOD(&connection, model, "getreadconnection");

	PHALCON_CALL_METHOD(&intermediate, total_query, "parse");

	PHALCON_OBS_VAR(tables);
	phalcon_array_fetch_string(&tables, intermediate, SL("tables"), PH_NOISY);
	
	PHALCON_OBS_VAR(table);
	phalcon_array_fetch_long(&table, tables, 0, PH_NOISY);

	if (Z_TYPE_P(table) == IS_ARRAY) {
		if (phalcon_array_isset_long(table, 2)) {
			PHALCON_OBS_VAR(table_name);
			phalcon_array_fetch_long(&table_name, table, 2, PH_NOISY);
		} else {
			PHALCON_OBS_VAR(table_name);
			phalcon_array_fetch_long(&table_name, table, 0, PH_NOISY);
		}
	} else {
		PHALCON_CPY_WRT(table_name, table);
	}

	PHALCON_INIT_VAR(select_column);
	PHALCON_CONCAT_VS(select_column, table_name, ".*");	

	phalcon_array_update_string(&intermediate, SL("columns"), select_column, PH_COPY | PH_SEPARATE);

	PHALCON_CALL_METHOD(&dialect, connection, "getdialect");
	PHALCON_CALL_METHOD(&sql_select, dialect, "select", intermediate);

	PHALCON_CALL_METHOD(&bind_params, total_query, "getbindparams");
	PHALCON_CALL_METHOD(&bind_types, total_query, "getbindtypes");

	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "SELECT COUNT(*) \"rowcount\" FROM (", sql_select, ") AS T");

	/** 
	 * Replace the placeholders
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(processed);
		array_init(processed);
	
		phalcon_is_iterable(bind_params, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(wildcard, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				PHALCON_INIT_NVAR(string_wildcard);
				PHALCON_CONCAT_SV(string_wildcard, ":", wildcard);
				phalcon_array_update_zval(&processed, string_wildcard, value, PH_COPY);
			} else {
				phalcon_array_update_zval(&processed, wildcard, value, PH_COPY);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		PHALCON_CPY_WRT(processed, bind_params);
	}
	
	/** 
	 * Replace the bind Types
	 */
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(processed_types);
		array_init(processed_types);
	
		phalcon_is_iterable(bind_types, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(wildcard, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				PHALCON_INIT_NVAR(string_wildcard);
				PHALCON_CONCAT_SV(string_wildcard, ":", wildcard);
				phalcon_array_update_zval(&processed_types, string_wildcard, value, PH_COPY | PH_SEPARATE);
			} else {
				phalcon_array_update_zval(&processed_types, wildcard, value, PH_COPY | PH_SEPARATE);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		PHALCON_CPY_WRT(processed_types, bind_types);
	}

	PHALCON_CALL_METHOD(&result, connection, "query", sql, processed, processed_types);
	PHALCON_CALL_METHOD(&row, result, "fetch");
	
	PHALCON_OBS_VAR(rowcount);
	phalcon_array_fetch_string(&rowcount, row, SL("rowcount"), PH_NOISY);
	
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
