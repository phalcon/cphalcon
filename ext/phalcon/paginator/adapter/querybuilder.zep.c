
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 *
 * Pagination using a PHQL query builder as source of data
 *
 * <code>
 * use Phalcon\Paginator\Adapter\QueryBuilder;
 *
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("id, name")
 *                 ->from("Robots")
 *                 ->orderBy("name");
 *
 * $paginator = new QueryBuilder(
 *     [
 *         "builder" => $builder,
 *         "limit"   => 20,
 *         "page"    => 1,
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, QueryBuilder, phalcon, paginator_adapter_querybuilder, phalcon_paginator_adapter_ce, phalcon_paginator_adapter_querybuilder_method_entry, 0);

	/**
	 * Paginator's data
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_builder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Columns for count query if builder has having
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\QueryBuilder
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *config_param = NULL, builder, columns;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&columns);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(&config, config_param);


	if (!(zephir_array_isset_string(&config, SL("limit")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'limit' is required", "phalcon/paginator/adapter/querybuilder.zep", 61);
		return;
	}
	ZEPHIR_OBS_VAR(&builder);
	if (!(zephir_array_isset_string_fetch(&builder, &config, SL("builder"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'builder' is required", "phalcon/paginator/adapter/querybuilder.zep", 65);
		return;
	}
	ZEPHIR_OBS_VAR(&columns);
	if (zephir_array_isset_string_fetch(&columns, &config, SL("columns"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_columns"), &columns);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_paginator_adapter_querybuilder_ce, getThis(), "__construct", &_0, 0, &config);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setquerybuilder", NULL, 0, &builder);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the current page number
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_page");

}

/**
 * Set query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder) {

	zval *builder, builder_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&builder_sub);

	zephir_fetch_params(0, 1, 0, &builder);



	zephir_update_property_zval(this_ptr, SL("_builder"), builder);
	RETURN_THISW();

}

/**
 * Get query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_builder");

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, paginate) {

	zend_class_entry *_14$$16;
	zval _25, _6$$14, _8$$15;
	zend_bool hasHaving = 0, hasGroup = 0, _2;
	zval originalBuilder, builder, totalBuilder, totalPages, limit, number, query, items, totalQuery, result, row, rowcount, next, sql, columns, db, model, modelClass, dbService, groups, groupColumn, _0, _1, _10, _26, _27, _3$$10, _4$$14, _5$$14, _7$$14, _9$$15, _11$$17, _12$$17, _13$$16, _15$$16, _16$$16, _17$$16, _18$$16, _19$$16, _20$$16, _21$$16, _22$$18, _23$$18, _24$$18;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberPage = 0, previous = 0;
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
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$14);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_8$$15);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&originalBuilder);
	zephir_read_property(&originalBuilder, this_ptr, SL("_builder"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&columns);
	zephir_read_property(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&builder);
	if (zephir_clone(&builder, &originalBuilder TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&totalBuilder);
	if (zephir_clone(&totalBuilder, &builder TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&limit);
	zephir_read_property(&limit, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_page"), PH_NOISY_CC);
	numberPage = zephir_get_intval(&_0);
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
	ZEPHIR_CALL_METHOD(&_1, &totalBuilder, "gethaving", NULL, 0);
	zephir_check_call_status();
	hasHaving = !(ZEPHIR_IS_EMPTY(&_1));
	ZEPHIR_CALL_METHOD(&groups, &totalBuilder, "getgroupby", NULL, 0);
	zephir_check_call_status();
	hasGroup = !(ZEPHIR_IS_EMPTY(&groups));
	_2 = hasHaving;
	if (_2) {
		_2 = !hasGroup;
	}
	if (_2) {
		if (ZEPHIR_IS_EMPTY(&columns)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "When having is set there should be columns option provided for which calculate row count", "phalcon/paginator/adapter/querybuilder.zep", 168);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &columns);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "COUNT(*) [rowcount]");
		ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_3$$10);
		zephir_check_call_status();
	}
	if (hasGroup) {
		if (Z_TYPE_P(&groups) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&groupColumn);
			zephir_fast_join_str(&groupColumn, SL(", "), &groups TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&groupColumn, &groups);
		}
		if (!(hasHaving)) {
			ZVAL_NULL(&_5$$14);
			ZEPHIR_CALL_METHOD(&_4$$14, &totalBuilder, "groupby", NULL, 0, &_5$$14);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_6$$14);
			zephir_create_array(&_6$$14, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_7$$14);
			ZEPHIR_CONCAT_SVS(&_7$$14, "COUNT(DISTINCT ", &groupColumn, ") AS [rowcount]");
			zephir_array_fast_append(&_6$$14, &_7$$14);
			ZEPHIR_CALL_METHOD(NULL, &_4$$14, "columns", NULL, 0, &_6$$14);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_8$$15);
			zephir_create_array(&_8$$15, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_9$$15);
			ZEPHIR_CONCAT_SV(&_9$$15, "DISTINCT ", &groupColumn);
			zephir_array_fast_append(&_8$$15, &_9$$15);
			ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "columns", NULL, 0, &_8$$15);
			zephir_check_call_status();
		}
	}
	ZVAL_NULL(&_10);
	ZEPHIR_CALL_METHOD(NULL, &totalBuilder, "orderby", NULL, 0, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&totalQuery, &totalBuilder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&rowcount);
	if (hasHaving) {
		ZEPHIR_CALL_METHOD(&sql, &totalQuery, "getsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&modelClass);
		zephir_read_property(&modelClass, &builder, SL("_models"), PH_NOISY_CC);
		if (Z_TYPE_P(&modelClass) == IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&_11$$17, "array_values", NULL, 118, &modelClass);
			zephir_check_call_status();
			zephir_array_fetch_long(&_12$$17, &_11$$17, 0, PH_NOISY | PH_READONLY, "phalcon/paginator/adapter/querybuilder.zep", 211 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&modelClass, &_12$$17);
		}
		ZEPHIR_INIT_VAR(&model);
		zephir_fetch_safe_class(&_13$$16, &modelClass);
		_14$$16 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_13$$16), Z_STRLEN_P(&_13$$16), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&model, _14$$16);
		if (zephir_has_constructor(&model TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&dbService, &model, "getreadconnectionservice", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$16, &totalBuilder, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&db, &_15$$16, "get", NULL, 0, &dbService);
		zephir_check_call_status();
		zephir_array_fetch_string(&_16$$16, &sql, SL("sql"), PH_NOISY | PH_READONLY, "phalcon/paginator/adapter/querybuilder.zep", 217 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_17$$16);
		ZEPHIR_CONCAT_SVS(&_17$$16, "SELECT COUNT(*) as \"rowcount\" FROM (", &_16$$16, ") as T1");
		zephir_array_fetch_string(&_18$$16, &sql, SL("bind"), PH_NOISY | PH_READONLY, "phalcon/paginator/adapter/querybuilder.zep", 217 TSRMLS_CC);
		ZVAL_LONG(&_19$$16, 2);
		ZEPHIR_CALL_METHOD(&row, &db, "fetchone", NULL, 0, &_17$$16, &_19$$16, &_18$$16);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_array_fetch_string(&_20$$16, &row, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/paginator/adapter/querybuilder.zep", 218 TSRMLS_CC);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_20$$16));
		} else {
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_SINIT_VAR(_21$$16);
		div_function(&_21$$16, &rowcount, &limit TSRMLS_CC);
		ZVAL_DOUBLE(&_19$$16, zephir_ceil(&_21$$16 TSRMLS_CC));
		ZEPHIR_INIT_VAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_19$$16));
	} else {
		ZEPHIR_CALL_METHOD(&result, &totalQuery, "execute", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&row, &result, "getfirst", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&row)) {
			zephir_read_property(&_22$$18, &row, SL("rowcount"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, zephir_get_intval(&_22$$18));
		} else {
			ZEPHIR_INIT_NVAR(&rowcount);
			ZVAL_LONG(&rowcount, 0);
		}
		ZEPHIR_SINIT_VAR(_23$$18);
		div_function(&_23$$18, &rowcount, &limit TSRMLS_CC);
		ZVAL_DOUBLE(&_24$$18, zephir_ceil(&_23$$18 TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&totalPages);
		ZVAL_LONG(&totalPages, zephir_get_intval(&_24$$18));
	}
	if (ZEPHIR_GT_LONG(&totalPages, numberPage)) {
		ZEPHIR_INIT_VAR(&next);
		ZVAL_LONG(&next, (numberPage + 1));
	} else {
		ZEPHIR_CPY_WRT(&next, &totalPages);
	}
	ZEPHIR_INIT_VAR(&_25);
	zephir_create_array(&_25, 8, 0 TSRMLS_CC);
	zephir_array_update_string(&_25, SL("items"), &items, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_25, SL("total_items"), &rowcount, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_26);
	zephir_read_property(&_26, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_25, SL("limit"), &_26, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_25, SL("first"), 1);
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_LONG(&_27, previous);
	zephir_array_update_string(&_25, SL("previous"), &_27, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_27);
	ZVAL_LONG(&_27, numberPage);
	zephir_array_update_string(&_25, SL("current"), &_27, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_25, SL("next"), &next, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_25, SL("last"), &totalPages, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_25);
	zephir_check_call_status();
	RETURN_MM();

}

