
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
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
	 * Column list used only for COUNT rewriting when the builder carries a
	 * HAVING or GROUP BY clause. It supplies the columns for the subquery
	 * that counts the grouped/having result set and is ignored otherwise.
	 *
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("columns"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * The `columns` option is not a projection for the paginated rows; it is
 * consumed solely by the total-count rewrite when the builder has a
 * HAVING or GROUP BY clause (it becomes the column list of the counting
 * subquery). It has no effect on plain queries.
 *
 * @param array config = [
 *     'limit' => 10,
 *     'builder' => null,
 *     'columns' => ''
 * ]
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, builder, columns, _0$$5;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);
	if (UNEXPECTED(!(zephir_array_isset_value_string(&config, SL("limit"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "limit", "phalcon/Paginator/Adapter/QueryBuilder.zep", 81);
		return;
	}
	zephir_memory_observe(&builder);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&builder, &config, SL("builder"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "builder", "phalcon/Paginator/Adapter/QueryBuilder.zep", 85);
		return;
	}
	if (UNEXPECTED(!((zephir_instance_of_ev(&builder, phalcon_mvc_model_query_builder_ce))))) {
		ZEPHIR_INIT_VAR(&_0$$5);
		object_init_ex(&_0$$5, phalcon_paginator_exceptions_invalidbuilderinstance_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$5, "phalcon/Paginator/Adapter/QueryBuilder.zep", 88);
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
	zval _43, _14$$12, _16$$13, _21$$20, _25$$21, _27$$22;
	zend_bool hasHaving = 0, hasGroup = 0, hasMultipleGroups = 0, hasDistinct = 0, _3, _29, _5$$10;
	zval originalBuilder, builder, totalBuilder, totalPages, limit, number, query, items, totalQuery, result, row, rowcount, next, sql, columns, db, model, modelClass, dbService, groups, groupColumn, builderColumns, distinctColumn, _0, _1, _2, _44, _45, _4$$9, _6$$10, _7$$10, _8$$10, _9$$11, _10$$11, _11$$11, _12$$11, _13$$11, _15$$12, _17$$13, _18$$14, _19$$20, _20$$20, _22$$20, _23$$21, _24$$21, _26$$21, _28$$22, _30$$24, _31$$25, _32$$25, _33$$23, _34$$23, _35$$23, _36$$23, _37$$23, _38$$23, _39$$23, _40$$26, _41$$26, _42$$26;
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
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_26$$21);
	ZVAL_UNDEF(&_28$$22);
	ZVAL_UNDEF(&_30$$24);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_40$$26);
	ZVAL_UNDEF(&_41$$26);
	ZVAL_UNDEF(&_42$$26);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_27$$22);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&originalBuilder);
	zephir_read_property(&originalBuilder, this_ptr, ZEND_STRL("builder"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columns"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columns, &_0);
	hasMultipleGroups = 0;
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
			ZEPHIR_INIT_VAR(&_4$$9);
			object_init_ex(&_4$$9, phalcon_paginator_exceptions_missingcolumnsforhaving_ce);
			ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$9, "phalcon/Paginator/Adapter/QueryBuilder.zep", 184);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &columns);
		zephir_check_call_status();
	} else {
		hasDistinct = 0;
		ZEPHIR_CALL_METHOD(&builderColumns, &builder, "getcolumns", NULL, 0);
		zephir_check_call_status();
		_5$$10 = Z_TYPE_P(&builderColumns) == IS_STRING;
		if (_5$$10) {
			ZEPHIR_INIT_VAR(&_6$$10);
			zephir_fast_trim(&_6$$10, &builderColumns, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_7$$10);
			ZVAL_STRING(&_7$$10, "DISTINCT ");
			ZEPHIR_CALL_FUNCTION(&_8$$10, "stripos", NULL, 0, &_6$$10, &_7$$10);
			zephir_check_call_status();
			_5$$10 = ZEPHIR_IS_LONG_IDENTICAL(&_8$$10, 0);
		}
		if (_5$$10) {
			ZEPHIR_INIT_VAR(&_9$$11);
			zephir_fast_trim(&_9$$11, &builderColumns, NULL , ZEPHIR_TRIM_BOTH);
			ZVAL_LONG(&_10$$11, 9);
			ZEPHIR_INIT_VAR(&_11$$11);
			zephir_substr(&_11$$11, &_9$$11, 9 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_VAR(&distinctColumn);
			zephir_fast_trim(&distinctColumn, &_11$$11, NULL , ZEPHIR_TRIM_BOTH);
			hasDistinct = 1;
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, ",");
			ZEPHIR_INIT_VAR(&_13$$11);
			zephir_fast_strpos(&_13$$11, &distinctColumn, &_12$$11, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_13$$11)) {
				ZEPHIR_INIT_VAR(&_14$$12);
				zephir_create_array(&_14$$12, 1, 0);
				ZEPHIR_INIT_VAR(&_15$$12);
				ZEPHIR_CONCAT_SV(&_15$$12, "DISTINCT ", &distinctColumn);
				zephir_array_fast_append(&_14$$12, &_15$$12);
				ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_14$$12);
				zephir_check_call_status();
				hasMultipleGroups = 1;
			} else {
				ZEPHIR_INIT_VAR(&_16$$13);
				zephir_create_array(&_16$$13, 1, 0);
				ZEPHIR_INIT_VAR(&_17$$13);
				ZEPHIR_CONCAT_SVS(&_17$$13, "COUNT(DISTINCT ", &distinctColumn, ") AS [rowcount]");
				zephir_array_fast_append(&_16$$13, &_17$$13);
				ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_16$$13);
				zephir_check_call_status();
			}
		}
		if (!(hasDistinct)) {
			ZEPHIR_INIT_VAR(&_18$$14);
			ZVAL_STRING(&_18$$14, "COUNT(*) [rowcount]");
			ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_18$$14);
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
				ZVAL_NULL(&_20$$20);
				ZEPHIR_CALL_METHOD(&_19$$20, &totalBuilder, "groupby", NULL, 0, &_20$$20);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_21$$20);
				zephir_create_array(&_21$$20, 1, 0);
				ZEPHIR_INIT_VAR(&_22$$20);
				ZEPHIR_CONCAT_SV(&_22$$20, "DISTINCT ", &groupColumn);
				zephir_array_fast_append(&_21$$20, &_22$$20);
				ZEPHIR_CALL_METHOD(NULL, &_19$$20, "columns", NULL, 0, &_21$$20);
				zephir_check_call_status();
			} else {
				ZVAL_NULL(&_24$$21);
				ZEPHIR_CALL_METHOD(&_23$$21, &totalBuilder, "groupby", NULL, 0, &_24$$21);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_25$$21);
				zephir_create_array(&_25$$21, 1, 0);
				ZEPHIR_INIT_VAR(&_26$$21);
				ZEPHIR_CONCAT_SVS(&_26$$21, "COUNT(DISTINCT ", &groupColumn, ") AS [rowcount]");
				zephir_array_fast_append(&_25$$21, &_26$$21);
				ZEPHIR_CALL_METHOD(NULL, &_23$$21, "columns", NULL, 0, &_25$$21);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_VAR(&_27$$22);
			zephir_create_array(&_27$$22, 1, 0);
			ZEPHIR_INIT_VAR(&_28$$22);
			ZEPHIR_CONCAT_SV(&_28$$22, "DISTINCT ", &groupColumn);
			zephir_array_fast_append(&_27$$22, &_28$$22);
			ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_27$$22);
			zephir_check_call_status();
		}
	}
	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "orderby", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&totalQuery, &totalBuilder, "getquery", NULL, 0);
	zephir_check_call_status();
	_29 = hasHaving;
	if (!(_29)) {
		_29 = hasMultipleGroups;
	}
	ZEPHIR_INIT_VAR(&rowcount);
	if (_29) {
		ZEPHIR_CALL_METHOD(&sql, &totalQuery, "getsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&modelClass, &builder, "getmodels", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&modelClass) == IS_NULL)) {
			ZEPHIR_INIT_VAR(&_30$$24);
			object_init_ex(&_30$$24, phalcon_paginator_exceptions_buildermodelnotdefined_ce);
			ZEPHIR_CALL_METHOD(NULL, &_30$$24, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_30$$24, "phalcon/Paginator/Adapter/QueryBuilder.zep", 275);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&modelClass) == IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&_31$$25, "array_values", NULL, 29, &modelClass);
			zephir_check_call_status();
			zephir_array_fetch_long(&_32$$25, &_31$$25, 0, PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 279);
			ZEPHIR_CPY_WRT(&modelClass, &_32$$25);
		}
		ZEPHIR_INIT_VAR(&model);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&model, &modelClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&dbService, &model, "getreadconnectionservice", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_33$$23, &totalBuilder, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&db, &_33$$23, "get", NULL, 0, &dbService);
		zephir_check_call_status();
		zephir_array_fetch_string(&_34$$23, &sql, SL("sql"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 287);
		ZEPHIR_INIT_VAR(&_35$$23);
		ZEPHIR_CONCAT_SVS(&_35$$23, "SELECT COUNT(*) as \"rowcount\" FROM (", &_34$$23, ") as T1");
		zephir_array_fetch_string(&_36$$23, &sql, SL("bind"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 290);
		ZVAL_LONG(&_37$$23, 2);
		ZEPHIR_CALL_METHOD(&row, &db, "fetchone", NULL, 0, &_35$$23, &_37$$23, &_36$$23);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_array_fetch_string(&_38$$23, &row, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 292);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_38$$23));
		} else {
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_INIT_VAR(&_39$$23);
		div_function(&_39$$23, &rowcount, &limit);
		ZVAL_DOUBLE(&_37$$23, zephir_ceil(&_39$$23));
		ZEPHIR_INIT_VAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_37$$23));
	} else {
		ZEPHIR_CALL_METHOD(&result, &totalQuery, "execute", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&row, &result, "getfirst", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_read_property(&_40$$26, &row, ZEND_STRL("rowcount"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_40$$26));
		} else {
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_INIT_VAR(&_41$$26);
		div_function(&_41$$26, &rowcount, &limit);
		ZVAL_DOUBLE(&_42$$26, zephir_ceil(&_41$$26));
		ZEPHIR_INIT_NVAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_42$$26));
	}
	if (ZEPHIR_GT_LONG(&totalPages, numberPage)) {
		ZEPHIR_INIT_VAR(&next);
		ZVAL_LONG(&next, (numberPage + 1));
	} else {
		ZEPHIR_CPY_WRT(&next, &totalPages);
	}
	ZEPHIR_INIT_VAR(&_43);
	zephir_create_array(&_43, 8, 0);
	zephir_array_update_string(&_43, SL("items"), &items, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_43, SL("total_items"), &rowcount, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_44);
	zephir_read_property(&_44, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_43, SL("limit"), &_44, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_43, SL("first"), 1);
	ZEPHIR_INIT_VAR(&_45);
	ZVAL_LONG(&_45, previous);
	zephir_array_update_string(&_43, SL("previous"), &_45, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_45);
	ZVAL_LONG(&_45, numberPage);
	zephir_array_update_string(&_43, SL("current"), &_45, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_43, SL("next"), &next, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_43, SL("last"), &totalPages, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_43);
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

