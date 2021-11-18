
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/math.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * Pagination using a PHQL query builder as source of data
 *
 * ```php
 * use Phalcon\Paginator\Adapter\QueryBuilder;
 *
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("id, name")
 *                 ->from(Robots::class)
 *                 ->orderBy("name");
 *
 * $paginator = new QueryBuilder(
 *     [
 *         "builder" => $builder,
 *         "limit"   => 20,
 *         "page"    => 1,
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, QueryBuilder, phalcon, paginator_adapter_querybuilder, phalcon_paginator_adapter_abstractadapter_ce, phalcon_paginator_adapter_querybuilder_method_entry, 0);

	/**
	 * Paginator's data
	 *
	 * @var Builder
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("builder"), ZEND_ACC_PROTECTED);
	/**
	 * Columns for count query if builder has having
	 *
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("columns"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * @param array config = [
 *     'limit' => 10,
 *     'builder' => null,
 *     'columns' => ''
 * ]
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct)
{
	zval _1$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, builder, columns, _0$$5;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);


	if (UNEXPECTED(!(zephir_array_isset_string(&config, SL("limit"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'limit' is required", "phalcon/Paginator/Adapter/QueryBuilder.zep", 70);
		return;
	}
	ZEPHIR_OBS_VAR(&builder);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&builder, &config, SL("builder"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'builder' is required", "phalcon/Paginator/Adapter/QueryBuilder.zep", 74);
		return;
	}
	if (UNEXPECTED(!((zephir_instance_of_ev(&builder, phalcon_mvc_model_query_builder_ce))))) {
		ZEPHIR_INIT_VAR(&_0$$5);
		object_init_ex(&_0$$5, phalcon_paginator_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$5);
		ZEPHIR_CONCAT_SS(&_1$$5, "Parameter 'builder' must be an instance ", "of Phalcon\\Mvc\\Model\\Query\\Builder");
		ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 30, &_1$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$5, "phalcon/Paginator/Adapter/QueryBuilder.zep", 80);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&columns);
	if (zephir_array_isset_string_fetch(&columns, &config, SL("columns"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &columns);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_paginator_adapter_querybuilder_ce, getThis(), "__construct", &_2, 0, &config);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setquerybuilder", NULL, 0, &builder);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Get the current page number
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "page");
}

/**
 * Get query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "builder");
}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, paginate)
{
	zval _23, _7$$14, _9$$15;
	zend_bool hasHaving = 0, hasGroup = 0, _3;
	zval originalBuilder, builder, totalBuilder, totalPages, limit, number, query, items, totalQuery, result, row, rowcount, next, sql, columns, db, model, modelClass, dbService, groups, groupColumn, _0, _1, _2, _24, _25, _4$$10, _5$$14, _6$$14, _8$$14, _10$$15, _11$$18, _12$$18, _13$$16, _14$$16, _15$$16, _16$$16, _17$$16, _18$$16, _19$$16, _20$$19, _21$$19, _22$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, previous = 0, numberPage = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&originalBuilder);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&totalBuilder);
	ZVAL_UNDEF(&totalPages);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&totalQuery);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&rowcount);
	ZVAL_UNDEF(&next);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&db);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&modelClass);
	ZVAL_UNDEF(&dbService);
	ZVAL_UNDEF(&groups);
	ZVAL_UNDEF(&groupColumn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$18);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_9$$15);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&originalBuilder);
	zephir_read_property(&originalBuilder, this_ptr, ZEND_STRL("builder"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columns"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columns, &_0);
	ZEPHIR_INIT_VAR(&builder);
	if (zephir_clone(&builder, &originalBuilder) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&totalBuilder);
	if (zephir_clone(&totalBuilder, &builder) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&limit);
	zephir_read_property(&limit, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("page"), PH_NOISY_CC);
	numberPage = zephir_get_intval(&_1);
	if (!(numberPage)) {
		numberPage = 1;
	}
	ZEPHIR_INIT_VAR(&number);
	ZVAL_LONG(&number, (zephir_get_numberval(&limit) * ((numberPage - 1))));
	if (ZEPHIR_LT(&number, &limit)) {
		ZEPHIR_CALL_METHOD(NULL, &builder, "limit", NULL, 0, &limit);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &builder, "limit", NULL, 0, &limit, &number);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&query, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	if (numberPage == 1) {
		previous = 1;
	} else {
		previous = (numberPage - 1);
	}
	ZEPHIR_CALL_METHOD(&items, &query, "execute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &totalBuilder, "gethaving", NULL, 0);
	zephir_check_call_status();
	hasHaving = !(ZEPHIR_IS_EMPTY(&_2));
	ZEPHIR_CALL_METHOD(&groups, &totalBuilder, "getgroupby", NULL, 0);
	zephir_check_call_status();
	hasGroup = !(ZEPHIR_IS_EMPTY(&groups));
	_3 = hasHaving;
	if (_3) {
		_3 = !hasGroup;
	}
	if (_3) {
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columns))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "When having is set there should be columns option provided for which calculate row count", "phalcon/Paginator/Adapter/QueryBuilder.zep", 177);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &columns);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_4$$10);
		ZVAL_STRING(&_4$$10, "COUNT(*) [rowcount]");
		ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_4$$10);
		zephir_check_call_status();
	}
	if (hasGroup) {
		if (Z_TYPE_P(&groups) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&groupColumn);
			zephir_fast_join_str(&groupColumn, SL(", "), &groups);
		} else {
			ZEPHIR_CPY_WRT(&groupColumn, &groups);
		}
		if (!(hasHaving)) {
			ZVAL_NULL(&_6$$14);
			ZEPHIR_CALL_METHOD(&_5$$14, &totalBuilder, "groupby", NULL, 0, &_6$$14);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$14);
			zephir_create_array(&_7$$14, 1, 0);
			ZEPHIR_INIT_VAR(&_8$$14);
			ZEPHIR_CONCAT_SVS(&_8$$14, "COUNT(DISTINCT ", &groupColumn, ") AS [rowcount]");
			zephir_array_fast_append(&_7$$14, &_8$$14);
			ZEPHIR_CALL_METHOD(NULL, &_5$$14, "columns", NULL, 0, &_7$$14);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_9$$15);
			zephir_create_array(&_9$$15, 1, 0);
			ZEPHIR_INIT_VAR(&_10$$15);
			ZEPHIR_CONCAT_SV(&_10$$15, "DISTINCT ", &groupColumn);
			zephir_array_fast_append(&_9$$15, &_10$$15);
			ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_9$$15);
			zephir_check_call_status();
		}
	}
	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "orderby", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&totalQuery, &totalBuilder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&rowcount);
	if (hasHaving) {
		ZEPHIR_CALL_METHOD(&sql, &totalQuery, "getsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&modelClass, &builder, "getmodels", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&modelClass) == IS_NULL)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Model not defined in builder", "phalcon/Paginator/Adapter/QueryBuilder.zep", 229);
			return;
		}
		if (Z_TYPE_P(&modelClass) == IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&_11$$18, "array_values", NULL, 13, &modelClass);
			zephir_check_call_status();
			zephir_array_fetch_long(&_12$$18, &_11$$18, 0, PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 233);
			ZEPHIR_CPY_WRT(&modelClass, &_12$$18);
		}
		ZEPHIR_INIT_VAR(&model);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&model, &modelClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&dbService, &model, "getreadconnectionservice", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13$$16, &totalBuilder, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&db, &_13$$16, "get", NULL, 0, &dbService);
		zephir_check_call_status();
		zephir_array_fetch_string(&_14$$16, &sql, SL("sql"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 241);
		ZEPHIR_INIT_VAR(&_15$$16);
		ZEPHIR_CONCAT_SVS(&_15$$16, "SELECT COUNT(*) as \"rowcount\" FROM (", &_14$$16, ") as T1");
		zephir_array_fetch_string(&_16$$16, &sql, SL("bind"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 244);
		ZVAL_LONG(&_17$$16, 2);
		ZEPHIR_CALL_METHOD(&row, &db, "fetchone", NULL, 0, &_15$$16, &_17$$16, &_16$$16);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_array_fetch_string(&_18$$16, &row, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 246);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_18$$16));
		} else {
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_INIT_VAR(&_19$$16);
		div_function(&_19$$16, &rowcount, &limit);
		ZVAL_DOUBLE(&_17$$16, zephir_ceil(&_19$$16));
		ZEPHIR_INIT_VAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_17$$16));
	} else {
		ZEPHIR_CALL_METHOD(&result, &totalQuery, "execute", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&row, &result, "getfirst", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_read_property(&_20$$19, &row, ZEND_STRL("rowcount"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_20$$19));
		} else {
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_INIT_VAR(&_21$$19);
		div_function(&_21$$19, &rowcount, &limit);
		ZVAL_DOUBLE(&_22$$19, zephir_ceil(&_21$$19));
		ZEPHIR_INIT_NVAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_22$$19));
	}
	if (ZEPHIR_GT_LONG(&totalPages, numberPage)) {
		ZEPHIR_INIT_VAR(&next);
		ZVAL_LONG(&next, (numberPage + 1));
	} else {
		ZEPHIR_CPY_WRT(&next, &totalPages);
	}
	ZEPHIR_INIT_VAR(&_23);
	zephir_create_array(&_23, 8, 0);
	zephir_array_update_string(&_23, SL("items"), &items, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_23, SL("total_items"), &rowcount, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_24);
	zephir_read_property(&_24, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_23, SL("limit"), &_24, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_23, SL("first"), 1);
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_LONG(&_25, previous);
	zephir_array_update_string(&_23, SL("previous"), &_25, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_25);
	ZVAL_LONG(&_25, numberPage);
	zephir_array_update_string(&_23, SL("current"), &_25, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_23, SL("next"), &next, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_23, SL("last"), &totalPages, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_23);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder)
{
	zval *builder, builder_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&builder_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(builder, phalcon_mvc_model_query_builder_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &builder);


	zephir_update_property_zval(this_ptr, ZEND_STRL("builder"), builder);
	RETURN_THISW();
}

