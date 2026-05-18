
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
	 * Columns for count query if builder has having or group by
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, builder, columns, _0$$5;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);
	if (UNEXPECTED(!(zephir_array_isset_string(&config, SL("limit"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'limit' is required", "phalcon/Paginator/Adapter/QueryBuilder.zep", 70);
		return;
	}
	zephir_memory_observe(&builder);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&builder, &config, SL("builder"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'builder' is required", "phalcon/Paginator/Adapter/QueryBuilder.zep", 74);
		return;
	}
	if (UNEXPECTED(!((zephir_instance_of_ev(&builder, phalcon_mvc_model_query_builder_ce))))) {
		ZEPHIR_INIT_VAR(&_0$$5);
		object_init_ex(&_0$$5, phalcon_paginator_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$5);
		ZEPHIR_CONCAT_SS(&_1$$5, "Parameter 'builder' must be an instance ", "of Phalcon\\Mvc\\Model\\Query\\Builder");
		ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 49, &_1$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$5, "phalcon/Paginator/Adapter/QueryBuilder.zep", 80);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&columns);
	if (zephir_array_isset_string_fetch(&columns, &config, SL("columns"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &columns);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_paginator_adapter_querybuilder_ce, getThis(), "__construct", NULL, 0, &config);
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

	RETURN_MEMBER_TYPED(getThis(), "page", IS_LONG);
}

/**
 * Get query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder)
{

	RETURN_MEMBER(getThis(), "builder");
}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, paginate)
{
	zval _41, _13$$12, _15$$13, _20$$20, _24$$21, _26$$22;
	zend_bool hasHaving = 0, hasGroup = 0, hasMultipleGroups = 0, hasDistinct = 0, _3, _28, _4$$10;
	zval originalBuilder, builder, totalBuilder, totalPages, limit, number, query, items, totalQuery, result, row, rowcount, next, sql, columns, db, model, modelClass, dbService, groups, groupColumn, builderColumns, distinctColumn, _0, _1, _2, _42, _43, _5$$10, _6$$10, _7$$10, _8$$11, _9$$11, _10$$11, _11$$11, _12$$11, _14$$12, _16$$13, _17$$14, _18$$20, _19$$20, _21$$20, _22$$21, _23$$21, _25$$21, _27$$22, _29$$25, _30$$25, _31$$23, _32$$23, _33$$23, _34$$23, _35$$23, _36$$23, _37$$23, _38$$26, _39$$26, _40$$26;
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
	ZVAL_UNDEF(&builderColumns);
	ZVAL_UNDEF(&distinctColumn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_27$$22);
	ZVAL_UNDEF(&_29$$25);
	ZVAL_UNDEF(&_30$$25);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_40$$26);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_26$$22);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&originalBuilder);
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
	zephir_memory_observe(&limit);
	zephir_read_property(&limit, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	zephir_memory_observe(&_1);
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
		hasDistinct = 0;
		ZEPHIR_CALL_METHOD(&builderColumns, &builder, "getcolumns", NULL, 0);
		zephir_check_call_status();
		_4$$10 = Z_TYPE_P(&builderColumns) == IS_STRING;
		if (_4$$10) {
			ZEPHIR_INIT_VAR(&_5$$10);
			zephir_fast_trim(&_5$$10, &builderColumns, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_6$$10);
			ZVAL_STRING(&_6$$10, "DISTINCT ");
			ZEPHIR_CALL_FUNCTION(&_7$$10, "stripos", NULL, 389, &_5$$10, &_6$$10);
			zephir_check_call_status();
			_4$$10 = ZEPHIR_IS_LONG_IDENTICAL(&_7$$10, 0);
		}
		if (_4$$10) {
			ZEPHIR_INIT_VAR(&_8$$11);
			zephir_fast_trim(&_8$$11, &builderColumns, NULL , ZEPHIR_TRIM_BOTH);
			ZVAL_LONG(&_9$$11, 9);
			ZEPHIR_INIT_VAR(&_10$$11);
			zephir_substr(&_10$$11, &_8$$11, 9 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_VAR(&distinctColumn);
			zephir_fast_trim(&distinctColumn, &_10$$11, NULL , ZEPHIR_TRIM_BOTH);
			hasDistinct = 1;
			ZEPHIR_INIT_VAR(&_11$$11);
			ZVAL_STRING(&_11$$11, ",");
			ZEPHIR_INIT_VAR(&_12$$11);
			zephir_fast_strpos(&_12$$11, &distinctColumn, &_11$$11, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_12$$11)) {
				ZEPHIR_INIT_VAR(&_13$$12);
				zephir_create_array(&_13$$12, 1, 0);
				ZEPHIR_INIT_VAR(&_14$$12);
				ZEPHIR_CONCAT_SV(&_14$$12, "DISTINCT ", &distinctColumn);
				zephir_array_fast_append(&_13$$12, &_14$$12);
				ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_13$$12);
				zephir_check_call_status();
				hasMultipleGroups = 1;
			} else {
				ZEPHIR_INIT_VAR(&_15$$13);
				zephir_create_array(&_15$$13, 1, 0);
				ZEPHIR_INIT_VAR(&_16$$13);
				ZEPHIR_CONCAT_SVS(&_16$$13, "COUNT(DISTINCT ", &distinctColumn, ") AS [rowcount]");
				zephir_array_fast_append(&_15$$13, &_16$$13);
				ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_15$$13);
				zephir_check_call_status();
			}
		}
		if (!(hasDistinct)) {
			ZEPHIR_INIT_VAR(&_17$$14);
			ZVAL_STRING(&_17$$14, "COUNT(*) [rowcount]");
			ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_17$$14);
			zephir_check_call_status();
		}
	}
	if (hasGroup) {
		if (Z_TYPE_P(&groups) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&groupColumn);
			zephir_fast_join_str(&groupColumn, SL(", "), &groups);
			hasMultipleGroups = zephir_fast_count_int(&groups) > 1;
		} else {
			ZEPHIR_CPY_WRT(&groupColumn, &groups);
			hasMultipleGroups = 0;
		}
		if (!(hasHaving)) {
			if (!(ZEPHIR_IS_EMPTY(&columns))) {
				ZEPHIR_CPY_WRT(&groupColumn, &columns);
				hasMultipleGroups = 0;
			}
			if (hasMultipleGroups) {
				ZVAL_NULL(&_19$$20);
				ZEPHIR_CALL_METHOD(&_18$$20, &totalBuilder, "groupby", NULL, 0, &_19$$20);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_20$$20);
				zephir_create_array(&_20$$20, 1, 0);
				ZEPHIR_INIT_VAR(&_21$$20);
				ZEPHIR_CONCAT_SV(&_21$$20, "DISTINCT ", &groupColumn);
				zephir_array_fast_append(&_20$$20, &_21$$20);
				ZEPHIR_CALL_METHOD(NULL, &_18$$20, "columns", NULL, 0, &_20$$20);
				zephir_check_call_status();
			} else {
				ZVAL_NULL(&_23$$21);
				ZEPHIR_CALL_METHOD(&_22$$21, &totalBuilder, "groupby", NULL, 0, &_23$$21);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_24$$21);
				zephir_create_array(&_24$$21, 1, 0);
				ZEPHIR_INIT_VAR(&_25$$21);
				ZEPHIR_CONCAT_SVS(&_25$$21, "COUNT(DISTINCT ", &groupColumn, ") AS [rowcount]");
				zephir_array_fast_append(&_24$$21, &_25$$21);
				ZEPHIR_CALL_METHOD(NULL, &_22$$21, "columns", NULL, 0, &_24$$21);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_VAR(&_26$$22);
			zephir_create_array(&_26$$22, 1, 0);
			ZEPHIR_INIT_VAR(&_27$$22);
			ZEPHIR_CONCAT_SV(&_27$$22, "DISTINCT ", &groupColumn);
			zephir_array_fast_append(&_26$$22, &_27$$22);
			ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_26$$22);
			zephir_check_call_status();
		}
	}
	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "orderby", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&totalQuery, &totalBuilder, "getquery", NULL, 0);
	zephir_check_call_status();
	_28 = hasHaving;
	if (!(_28)) {
		_28 = hasMultipleGroups;
	}
	ZEPHIR_INIT_VAR(&rowcount);
	if (_28) {
		ZEPHIR_CALL_METHOD(&sql, &totalQuery, "getsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&modelClass, &builder, "getmodels", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&modelClass) == IS_NULL)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Model not defined in builder", "phalcon/Paginator/Adapter/QueryBuilder.zep", 268);
			return;
		}
		if (Z_TYPE_P(&modelClass) == IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&_29$$25, "array_values", NULL, 22, &modelClass);
			zephir_check_call_status();
			zephir_array_fetch_long(&_30$$25, &_29$$25, 0, PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 272);
			ZEPHIR_CPY_WRT(&modelClass, &_30$$25);
		}
		ZEPHIR_INIT_VAR(&model);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&model, &modelClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&dbService, &model, "getreadconnectionservice", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_31$$23, &totalBuilder, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&db, &_31$$23, "get", NULL, 0, &dbService);
		zephir_check_call_status();
		zephir_array_fetch_string(&_32$$23, &sql, SL("sql"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 280);
		ZEPHIR_INIT_VAR(&_33$$23);
		ZEPHIR_CONCAT_SVS(&_33$$23, "SELECT COUNT(*) as \"rowcount\" FROM (", &_32$$23, ") as T1");
		zephir_array_fetch_string(&_34$$23, &sql, SL("bind"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 283);
		ZVAL_LONG(&_35$$23, 2);
		ZEPHIR_CALL_METHOD(&row, &db, "fetchone", NULL, 0, &_33$$23, &_35$$23, &_34$$23);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_array_fetch_string(&_36$$23, &row, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 285);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_36$$23));
		} else {
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_INIT_VAR(&_37$$23);
		div_function(&_37$$23, &rowcount, &limit);
		ZVAL_DOUBLE(&_35$$23, zephir_ceil(&_37$$23));
		ZEPHIR_INIT_VAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_35$$23));
	} else {
		ZEPHIR_CALL_METHOD(&result, &totalQuery, "execute", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&row, &result, "getfirst", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_read_property(&_38$$26, &row, ZEND_STRL("rowcount"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_38$$26));
		} else {
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_INIT_VAR(&_39$$26);
		div_function(&_39$$26, &rowcount, &limit);
		ZVAL_DOUBLE(&_40$$26, zephir_ceil(&_39$$26));
		ZEPHIR_INIT_NVAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_40$$26));
	}
	if (ZEPHIR_GT_LONG(&totalPages, numberPage)) {
		ZEPHIR_INIT_VAR(&next);
		ZVAL_LONG(&next, (numberPage + 1));
	} else {
		ZEPHIR_CPY_WRT(&next, &totalPages);
	}
	ZEPHIR_INIT_VAR(&_41);
	zephir_create_array(&_41, 8, 0);
	zephir_array_update_string(&_41, SL("items"), &items, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_41, SL("total_items"), &rowcount, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_42);
	zephir_read_property(&_42, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_41, SL("limit"), &_42, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_41, SL("first"), 1);
	ZEPHIR_INIT_VAR(&_43);
	ZVAL_LONG(&_43, previous);
	zephir_array_update_string(&_41, SL("previous"), &_43, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_43);
	ZVAL_LONG(&_43, numberPage);
	zephir_array_update_string(&_41, SL("current"), &_43, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_41, SL("next"), &next, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_41, SL("last"), &totalPages, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_41);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(builder, phalcon_mvc_model_query_builder_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &builder);
	zephir_update_property_zval(this_ptr, ZEND_STRL("builder"), builder);
	RETURN_THISW();
}

