
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/math.h"


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
	 * Configuration of paginator by model
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuilder_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	zval *config_param = NULL, *builder = NULL, *limit = NULL, *page = NULL, *columns = NULL;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(config, config_param);


	zephir_update_property_this(getThis(), SL("_config"), config TSRMLS_CC);
	ZEPHIR_OBS_VAR(builder);
	if (!(zephir_array_isset_string_fetch(&builder, config, SS("builder"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'builder' is required", "phalcon/paginator/adapter/querybuilder.zep", 76);
		return;
	}
	ZEPHIR_OBS_VAR(limit);
	if (!(zephir_array_isset_string_fetch(&limit, config, SS("limit"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Parameter 'limit' is required", "phalcon/paginator/adapter/querybuilder.zep", 80);
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (zephir_array_isset_string_fetch(&columns, config, SS("columns"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_columns"), columns TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setquerybuilder", NULL, 0, builder);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlimit", NULL, 0, limit);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(page);
	if (zephir_array_isset_string_fetch(&page, config, SS("page"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcurrentpage", NULL, 0, page);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the current page number
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage) {

	

	RETURN_MEMBER(getThis(), "_page");

}

/**
 * Set query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder) {

	zval *builder;

	zephir_fetch_params(0, 1, 0, &builder);



	zephir_update_property_this(getThis(), SL("_builder"), builder TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder) {

	

	RETURN_MEMBER(getThis(), "_builder");

}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @deprecated `will be removed after 4.0
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "paginate", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, paginate) {

	zend_class_entry *_14$$16;
	zval *_6$$14, *_8$$15;
	zend_bool hasHaving = 0, hasGroup = 0, _2;
	zval *originalBuilder = NULL, *builder = NULL, *totalBuilder = NULL, *totalPages = NULL, *limit = NULL, *number = NULL, *query = NULL, *page = NULL, *items = NULL, *totalQuery = NULL, *result = NULL, *row = NULL, *rowcount = NULL, *next = NULL, *sql = NULL, *columns = NULL, *db = NULL, *model = NULL, *modelClass = NULL, *dbService = NULL, *_0, *_1 = NULL, *groups = NULL, *_10, *_26, *_3$$10, *groupColumn$$11 = NULL, *_4$$14 = NULL, *_5$$14, *_7$$14, *_9$$15, *_11$$17 = NULL, *_12$$17, *_13$$16 = NULL, *_15$$16 = NULL, *_16$$16, *_17$$16, *_18$$16, *_19$$16, *_20$$16, _21$$16, _22$$16, *_23$$18, _24$$18, _25$$18;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberPage = 0, previous = 0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(originalBuilder);
	zephir_read_property_this(&originalBuilder, this_ptr, SL("_builder"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(columns);
	zephir_read_property_this(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
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
		ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, 0, limit);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, 0, limit, number);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&query, builder, "getquery", NULL, 0);
	zephir_check_call_status();
	if (numberPage == 1) {
		previous = 1;
	} else {
		previous = (numberPage - 1);
	}
	ZEPHIR_CALL_METHOD(&items, query, "execute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, totalBuilder, "gethaving", NULL, 0);
	zephir_check_call_status();
	hasHaving = !(ZEPHIR_IS_EMPTY(_1));
	ZEPHIR_CALL_METHOD(&groups, totalBuilder, "getgroupby", NULL, 0);
	zephir_check_call_status();
	hasGroup = !(ZEPHIR_IS_EMPTY(groups));
	_2 = hasHaving;
	if (_2) {
		_2 = !hasGroup;
	}
	if (_2) {
		if (ZEPHIR_IS_EMPTY(columns)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "When having is set there should be columns option provided for which calculate row count", "phalcon/paginator/adapter/querybuilder.zep", 197);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, totalBuilder, "columns", NULL, 0, columns);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_3$$10);
		ZVAL_STRING(_3$$10, "COUNT(*) [rowcount]", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, totalBuilder, "columns", NULL, 0, _3$$10);
		zephir_check_temp_parameter(_3$$10);
		zephir_check_call_status();
	}
	if (hasGroup) {
		if (Z_TYPE_P(groups) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(groupColumn$$11);
			zephir_fast_join_str(groupColumn$$11, SL(", "), groups TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(groupColumn$$11, groups);
		}
		if (!(hasHaving)) {
			ZEPHIR_INIT_VAR(_5$$14);
			ZVAL_NULL(_5$$14);
			ZEPHIR_CALL_METHOD(&_4$$14, totalBuilder, "groupby", NULL, 0, _5$$14);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_6$$14);
			zephir_create_array(_6$$14, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_7$$14);
			ZEPHIR_CONCAT_SVS(_7$$14, "COUNT(DISTINCT ", groupColumn$$11, ") AS [rowcount]");
			zephir_array_fast_append(_6$$14, _7$$14);
			ZEPHIR_CALL_METHOD(NULL, _4$$14, "columns", NULL, 0, _6$$14);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_8$$15);
			zephir_create_array(_8$$15, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_9$$15);
			ZEPHIR_CONCAT_SV(_9$$15, "DISTINCT ", groupColumn$$11);
			zephir_array_fast_append(_8$$15, _9$$15);
			ZEPHIR_CALL_METHOD(NULL, totalBuilder, "columns", NULL, 0, _8$$15);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(_10);
	ZVAL_NULL(_10);
	ZEPHIR_CALL_METHOD(NULL, totalBuilder, "orderby", NULL, 0, _10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&totalQuery, totalBuilder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(rowcount);
	if (hasHaving) {
		ZEPHIR_CALL_METHOD(&sql, totalQuery, "getsql", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(modelClass);
		zephir_read_property(&modelClass, builder, SL("_models"), PH_NOISY_CC);
		if (Z_TYPE_P(modelClass) == IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&_11$$17, "array_values", NULL, 235, modelClass);
			zephir_check_call_status();
			zephir_array_fetch_long(&_12$$17, _11$$17, 0, PH_NOISY | PH_READONLY, "phalcon/paginator/adapter/querybuilder.zep", 241 TSRMLS_CC);
			ZEPHIR_CPY_WRT(modelClass, _12$$17);
		}
		ZEPHIR_INIT_VAR(model);
		zephir_fetch_safe_class(_13$$16, modelClass);
			_14$$16 = zend_fetch_class(Z_STRVAL_P(_13$$16), Z_STRLEN_P(_13$$16), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(model, _14$$16);
		if (zephir_has_constructor(model TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, model, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&dbService, model, "getreadconnectionservice", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$16, totalBuilder, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&db, _15$$16, "get", NULL, 0, dbService);
		zephir_check_call_status();
		zephir_array_fetch_string(&_16$$16, sql, SL("sql"), PH_NOISY | PH_READONLY, "phalcon/paginator/adapter/querybuilder.zep", 247 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_17$$16);
		ZEPHIR_CONCAT_SVS(_17$$16, "SELECT COUNT(*) as \"rowcount\" FROM (", _16$$16, ") as T1");
		zephir_array_fetch_string(&_18$$16, sql, SL("bind"), PH_NOISY | PH_READONLY, "phalcon/paginator/adapter/querybuilder.zep", 247 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_19$$16);
		ZVAL_LONG(_19$$16, 2);
		ZEPHIR_CALL_METHOD(&row, db, "fetchone", NULL, 0, _17$$16, _19$$16, _18$$16);
		zephir_check_call_status();
		if (zephir_is_true(row)) {
			zephir_array_fetch_string(&_20$$16, row, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/paginator/adapter/querybuilder.zep", 248 TSRMLS_CC);
			ZVAL_LONG(rowcount, zephir_get_intval(_20$$16));
		} else {
			ZVAL_LONG(rowcount, 0);
		}
		ZEPHIR_SINIT_VAR(_21$$16);
		div_function(&_21$$16, rowcount, limit TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_22$$16);
		ZVAL_DOUBLE(&_22$$16, zephir_ceil(&_21$$16 TSRMLS_CC));
		ZEPHIR_INIT_VAR(totalPages);
		ZVAL_LONG(totalPages, zephir_get_intval(&_22$$16));
	} else {
		ZEPHIR_CALL_METHOD(&result, totalQuery, "execute", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&row, result, "getfirst", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(row)) {
			ZEPHIR_OBS_VAR(_23$$18);
			zephir_read_property(&_23$$18, row, SL("rowcount"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(rowcount);
			ZVAL_LONG(rowcount, zephir_get_intval(_23$$18));
		} else {
			ZEPHIR_INIT_NVAR(rowcount);
			ZVAL_LONG(rowcount, 0);
		}
		ZEPHIR_SINIT_VAR(_24$$18);
		div_function(&_24$$18, rowcount, limit TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_25$$18);
		ZVAL_DOUBLE(&_25$$18, zephir_ceil(&_24$$18 TSRMLS_CC));
		ZEPHIR_INIT_NVAR(totalPages);
		ZVAL_LONG(totalPages, zephir_get_intval(&_25$$18));
	}
	if (ZEPHIR_GT_LONG(totalPages, numberPage)) {
		ZEPHIR_INIT_VAR(next);
		ZVAL_LONG(next, (numberPage + 1));
	} else {
		ZEPHIR_CPY_WRT(next, totalPages);
	}
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	zephir_update_property_zval(page, SL("items"), items TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_26);
	ZVAL_LONG(_26, 1);
	zephir_update_property_zval(page, SL("first"), _26 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_26);
	ZVAL_LONG(_26, previous);
	zephir_update_property_zval(page, SL("before"), _26 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_26);
	ZVAL_LONG(_26, previous);
	zephir_update_property_zval(page, SL("previous"), _26 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_26);
	ZVAL_LONG(_26, numberPage);
	zephir_update_property_zval(page, SL("current"), _26 TSRMLS_CC);
	zephir_update_property_zval(page, SL("last"), totalPages TSRMLS_CC);
	zephir_update_property_zval(page, SL("next"), next TSRMLS_CC);
	zephir_update_property_zval(page, SL("total_pages"), totalPages TSRMLS_CC);
	zephir_update_property_zval(page, SL("total_items"), rowcount TSRMLS_CC);
	_26 = zephir_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY_CC);
	zephir_update_property_zval(page, SL("limit"), _26 TSRMLS_CC);
	RETURN_CCTOR(page);

}

