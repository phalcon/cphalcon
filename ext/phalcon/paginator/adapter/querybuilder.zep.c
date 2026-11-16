
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
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Pagination using a PHQL query builder as source of data
 *
 * ```php
 * use Phalcon\Paginator\Adapter\QueryBuilder;
 *
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("inv_id, inv_title")
 *                 ->from(Invoices::class)
 *                 ->orderBy("inv_title");
 *
 * $paginator = new QueryBuilder(
 *     [
 *         "builder" => $builder,
 *         "limit"   => 20,
 *         "page"    => 1,
 *     ]
 * );
 *```
 *
 * @phpstan-import-type paginator_columns from PaginatorTypes
 * @phpstan-import-type paginator_config from PaginatorTypes
 * @phpstan-import-type paginator_count_object from PaginatorTypes
 * @phpstan-import-type paginator_count_row from PaginatorTypes
 * @phpstan-import-type paginator_group_by from PaginatorTypes
 * @phpstan-import-type paginator_query_sql from PaginatorTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, QueryBuilder, phalcon, paginator_adapter_querybuilder, phalcon_paginator_adapter_abstractadapter_ce, phalcon_paginator_adapter_querybuilder_method_entry, 0);

	/**
	 * Paginator's data
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_paginator_adapter_querybuilder_ce, SL("builder"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Mvc\\Model\\Query\\Builder"));
	}

	/**
	 * Column list used only for COUNT rewriting when the builder carries a
	 * HAVING or GROUP BY clause. It supplies the columns for the subquery
	 * that counts the grouped/having result set and is ignored otherwise.
	 *
	 * @var paginator_columns|null
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
 * @param paginator_config $config = [
 *     'limit' => 10,
 *     'builder' => null,
 *     'columns' => ''
 * ]
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct)
{
	zend_bool _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, builder, columns, _2$$5;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_2$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("columns", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);
	_0 = zephir_array_isset_value_string(&config, SL("limit"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "limit", "phalcon/Paginator/Adapter/QueryBuilder.zep", 86);
		return;
	}
	zephir_memory_observe(&builder);
	_1 = zephir_array_isset_string_fetch(&builder, &config, SL("builder"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "builder", "phalcon/Paginator/Adapter/QueryBuilder.zep", 90);
		return;
	}
	if (UNEXPECTED(!((zephir_instance_of_ev(&builder, phalcon_mvc_model_query_builder_ce))))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_paginator_exceptions_invalidbuilderinstance_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Paginator/Adapter/QueryBuilder.zep", 93);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&columns);
	_3 = zephir_array_isset_string_fetch(&columns, &config, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1254, &columns);
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_paginator_adapter_querybuilder_ce, getThis(), "__construct", &_zephir_call_cache[1], &config);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setQueryBuilder", &_zephir_call_cache[2], &builder);
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
	zval _45, _16$$12, _18$$13, _23$$18, _27$$19, _29$$20;
	zend_bool hasHaving = 0, hasGroup = 0, hasMultipleGroups = 0, hasDistinct = 0, _3, _5, _31, _7$$10;
	zval originalBuilder, builder, totalBuilder, totalPages, limit, number, query, items, totalQuery, result, row, rowcount, next, sql, columns, db, model, modelClass, dbService, groups, groupColumn, builderColumns, distinctColumn, _0, _1, _2, _4, _46, _47, _6$$9, _8$$10, _9$$10, _10$$10, _11$$11, _12$$11, _13$$11, _14$$11, _15$$11, _17$$12, _19$$13, _20$$14, _21$$18, _22$$18, _24$$18, _25$$19, _26$$19, _28$$19, _30$$20, _32$$22, _33$$23, _34$$23, _35$$21, _36$$21, _37$$21, _38$$21, _39$$21, _40$$21, _41$$21, _42$$24, _43$$24, _44$$24;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_39$$21);
	ZVAL_UNDEF(&_40$$21);
	ZVAL_UNDEF(&_41$$21);
	ZVAL_UNDEF(&_42$$24);
	ZVAL_UNDEF(&_43$$24);
	ZVAL_UNDEF(&_44$$24);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_29$$20);
	ZEND_TLS zephir_method_cache _zephir_call_cache[29];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("builder", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("columns", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("limitRows", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("page", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("rowcount", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&originalBuilder);
	zephir_read_property_cached(&originalBuilder, this_ptr, _zephir_prop_0, 1255, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1254, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&columns, &_0);
	hasMultipleGroups = 0;
	ZEPHIR_INIT_VAR(&builder);
	if (zephir_clone(&builder, &originalBuilder) == FAILURE) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&totalBuilder);
	if (zephir_clone(&totalBuilder, &builder) == FAILURE) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&limit);
	zephir_read_property_cached(&limit, this_ptr, _zephir_prop_2, 1256, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_3, 1257, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	numberPage = zephir_get_intval(&_1);
	if (!(numberPage)) {
		numberPage = 1;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, ((numberPage - 1)));
	ZEPHIR_INIT_VAR(&number);
	mul_function(&number, &limit, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = ZEPHIR_LT(&number, &limit);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &builder, "limit", &_zephir_call_cache[0], &limit);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &builder, "limit", &_zephir_call_cache[1], &limit, &number);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&query, &builder, "getQuery", &_zephir_call_cache[2]);
	zephir_check_call_status();
	if (numberPage == 1) {
		previous = 1;
	} else {
		previous = (numberPage - 1);
	}
	ZEPHIR_CALL_METHOD_CACHED(&items, &query, "execute", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_4, &totalBuilder, "getHaving", &_zephir_call_cache[4]);
	zephir_check_call_status();
	hasHaving = !(ZEPHIR_IS_EMPTY(&_4));
	ZEPHIR_CALL_METHOD_CACHED(&groups, &totalBuilder, "getGroupBy", &_zephir_call_cache[5]);
	zephir_check_call_status();
	hasGroup = !(ZEPHIR_IS_EMPTY(&groups));
	_5 = hasHaving;
	if (_5) {
		_5 = !hasGroup;
	}
	if (_5) {
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columns))) {
			ZEPHIR_INIT_VAR(&_6$$9);
			object_init_ex(&_6$$9, phalcon_paginator_exceptions_missingcolumnsforhaving_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$9, "__construct", &_zephir_call_cache[6]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$9, "phalcon/Paginator/Adapter/QueryBuilder.zep", 189);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &totalBuilder, "columns", &_zephir_call_cache[7], &columns);
		zephir_check_call_status();
	} else {
		hasDistinct = 0;
		ZEPHIR_CALL_METHOD_CACHED(&builderColumns, &builder, "getColumns", &_zephir_call_cache[8]);
		zephir_check_call_status();
		_7$$10 = Z_TYPE_P(&builderColumns) == IS_STRING;
		if (_7$$10) {
			ZEPHIR_INIT_VAR(&_8$$10);
			zephir_fast_trim(&_8$$10, &builderColumns, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_9$$10);
			ZVAL_STRING(&_9$$10, "DISTINCT ");
			ZEPHIR_CALL_FUNCTION(&_10$$10, "stripos", NULL, 170, &_8$$10, &_9$$10);
			zephir_check_call_status();
			_7$$10 = ZEPHIR_IS_LONG_IDENTICAL(&_10$$10, 0);
		}
		if (_7$$10) {
			ZEPHIR_INIT_VAR(&_11$$11);
			zephir_fast_trim(&_11$$11, &builderColumns, NULL , ZEPHIR_TRIM_BOTH);
			ZVAL_LONG(&_12$$11, 9);
			ZEPHIR_INIT_VAR(&_13$$11);
			zephir_substr(&_13$$11, &_11$$11, 9 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_VAR(&distinctColumn);
			zephir_fast_trim(&distinctColumn, &_13$$11, NULL , ZEPHIR_TRIM_BOTH);
			hasDistinct = 1;
			ZEPHIR_INIT_VAR(&_14$$11);
			ZVAL_STRING(&_14$$11, ",");
			ZEPHIR_INIT_VAR(&_15$$11);
			zephir_fast_strpos(&_15$$11, &distinctColumn, &_14$$11, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_15$$11)) {
				ZEPHIR_INIT_VAR(&_16$$12);
				zephir_create_array(&_16$$12, 1, 0);
				ZEPHIR_INIT_VAR(&_17$$12);
				ZEPHIR_CONCAT_SV(&_17$$12, "DISTINCT ", &distinctColumn);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fast_append(&_16$$12, &_17$$12);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &totalBuilder, "columns", &_zephir_call_cache[9], &_16$$12);
				zephir_check_call_status();
				hasMultipleGroups = 1;
			} else {
				ZEPHIR_INIT_VAR(&_18$$13);
				zephir_create_array(&_18$$13, 1, 0);
				ZEPHIR_INIT_VAR(&_19$$13);
				ZEPHIR_CONCAT_SVS(&_19$$13, "COUNT(DISTINCT ", &distinctColumn, ") AS [rowcount]");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fast_append(&_18$$13, &_19$$13);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &totalBuilder, "columns", &_zephir_call_cache[10], &_18$$13);
				zephir_check_call_status();
			}
		}
		if (!(hasDistinct)) {
			ZEPHIR_INIT_VAR(&_20$$14);
			ZVAL_STRING(&_20$$14, "COUNT(*) [rowcount]");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &totalBuilder, "columns", &_zephir_call_cache[11], &_20$$14);
			zephir_check_call_status();
		}
	}
	if (hasGroup) {
		ZEPHIR_INIT_VAR(&groupColumn);
		zephir_fast_join_str(&groupColumn, SL(", "), &groups);
		hasMultipleGroups = zephir_fast_count_int(&groups) > 1;
		if (!(hasHaving)) {
			if (!(ZEPHIR_IS_EMPTY(&columns))) {
				ZEPHIR_CPY_WRT(&groupColumn, &columns);
				hasMultipleGroups = 0;
			}
			if (hasMultipleGroups) {
				ZVAL_NULL(&_22$$18);
				ZEPHIR_CALL_METHOD_CACHED(&_21$$18, &totalBuilder, "groupBy", &_zephir_call_cache[12], &_22$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_23$$18);
				zephir_create_array(&_23$$18, 1, 0);
				ZEPHIR_INIT_VAR(&_24$$18);
				ZEPHIR_CONCAT_SV(&_24$$18, "DISTINCT ", &groupColumn);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fast_append(&_23$$18, &_24$$18);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_21$$18, "columns", &_zephir_call_cache[13], &_23$$18);
				zephir_check_call_status();
			} else {
				ZVAL_NULL(&_26$$19);
				ZEPHIR_CALL_METHOD_CACHED(&_25$$19, &totalBuilder, "groupBy", &_zephir_call_cache[14], &_26$$19);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_27$$19);
				zephir_create_array(&_27$$19, 1, 0);
				ZEPHIR_INIT_VAR(&_28$$19);
				ZEPHIR_CONCAT_SVS(&_28$$19, "COUNT(DISTINCT ", &groupColumn, ") AS [rowcount]");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fast_append(&_27$$19, &_28$$19);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_25$$19, "columns", &_zephir_call_cache[15], &_27$$19);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_VAR(&_29$$20);
			zephir_create_array(&_29$$20, 1, 0);
			ZEPHIR_INIT_VAR(&_30$$20);
			ZEPHIR_CONCAT_SV(&_30$$20, "DISTINCT ", &groupColumn);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fast_append(&_29$$20, &_30$$20);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &totalBuilder, "columns", &_zephir_call_cache[16], &_29$$20);
			zephir_check_call_status();
		}
	}
	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &totalBuilder, "orderBy", &_zephir_call_cache[17], &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&totalQuery, &totalBuilder, "getQuery", &_zephir_call_cache[18]);
	zephir_check_call_status();
	_31 = hasHaving;
	if (!(_31)) {
		_31 = hasMultipleGroups;
	}
	ZEPHIR_INIT_VAR(&rowcount);
	if (_31) {
		ZEPHIR_CALL_METHOD_CACHED(&sql, &totalQuery, "getSql", &_zephir_call_cache[19]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&modelClass, &builder, "getModels", &_zephir_call_cache[20]);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&modelClass) == IS_NULL)) {
			ZEPHIR_INIT_VAR(&_32$$22);
			object_init_ex(&_32$$22, phalcon_paginator_exceptions_buildermodelnotdefined_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_32$$22, "__construct", &_zephir_call_cache[21]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_32$$22, "phalcon/Paginator/Adapter/QueryBuilder.zep", 275);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&modelClass) == IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&_33$$23, "array_values", NULL, 18, &modelClass);
			zephir_check_call_status();
			zephir_memory_observe(&_34$$23);
			zephir_array_fetch_long(&_34$$23, &_33$$23, 0, PH_NOISY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 279);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&modelClass, &_34$$23);
		}
		ZEPHIR_INIT_VAR(&model);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&model, &modelClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&dbService, &model, "getReadConnectionService", &_zephir_call_cache[22]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_35$$21, &totalBuilder, "getDI", &_zephir_call_cache[23]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&db, &_35$$21, "get", &_zephir_call_cache[24], &dbService);
		zephir_check_call_status();
		zephir_memory_observe(&_36$$21);
		zephir_array_fetch_string(&_36$$21, &sql, SL("sql"), PH_NOISY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 287);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_37$$21);
		ZEPHIR_CONCAT_SVS(&_37$$21, "SELECT COUNT(*) as \"rowcount\" FROM (", &_36$$21, ") as T1");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_38$$21);
		zephir_array_fetch_string(&_38$$21, &sql, SL("bind"), PH_NOISY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 290);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_39$$21, 2);
		ZEPHIR_CALL_METHOD_CACHED(&row, &db, "fetchOne", &_zephir_call_cache[25], &_37$$21, &_39$$21, &_38$$21);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_memory_observe(&_40$$21);
			zephir_array_fetch_string(&_40$$21, &row, SL("rowcount"), PH_NOISY, "phalcon/Paginator/Adapter/QueryBuilder.zep", 292);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&rowcount, zephir_get_intval(&_40$$21));
		} else {
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_INIT_VAR(&_41$$21);
		div_function(&_41$$21, &rowcount, &limit);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_DOUBLE(&_39$$21, zephir_ceil(&_41$$21));
		ZEPHIR_INIT_VAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_39$$21));
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&result, &totalQuery, "execute", &_zephir_call_cache[26]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&row, &result, "getFirst", &_zephir_call_cache[27]);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_memory_observe(&_42$$24);
			zephir_read_property_cached(&_42$$24, &row, _zephir_prop_4, 0, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_42$$24));
		} else {
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_INIT_VAR(&_43$$24);
		div_function(&_43$$24, &rowcount, &limit);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_DOUBLE(&_44$$24, zephir_ceil(&_43$$24));
		ZEPHIR_INIT_NVAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_44$$24));
	}
	if (ZEPHIR_GT_LONG(&totalPages, numberPage)) {
		ZEPHIR_INIT_VAR(&next);
		ZVAL_LONG(&next, (numberPage + 1));
	} else {
		ZEPHIR_CPY_WRT(&next, &totalPages);
	}
	ZEPHIR_INIT_VAR(&_45);
	zephir_create_array(&_45, 8, 0);
	zephir_array_update_string(&_45, SL("items"), &items, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_45, SL("total_items"), &rowcount, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_46);
	zephir_read_property_cached(&_46, this_ptr, _zephir_prop_2, 1256, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_45, SL("limit"), &_46, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_45, SL("first"), 1);
	ZEPHIR_INIT_VAR(&_47);
	ZVAL_LONG(&_47, previous);
	zephir_array_update_string(&_45, SL("previous"), &_47, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_47);
	ZVAL_LONG(&_47, numberPage);
	zephir_array_update_string(&_45, SL("current"), &_47, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_45, SL("next"), &next, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_45, SL("last"), &totalPages, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getRepository", &_zephir_call_cache[28], &_45);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("builder", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(builder, phalcon_mvc_model_query_builder_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &builder);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1255, builder);
	RETURN_THISW();
}

