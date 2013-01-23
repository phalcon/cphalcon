
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

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/string.h"

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *<code>
 *$resultset = $this->modelsManager->createBuilder()
 *   ->from('Robots')
 *   ->join('RobotsParts')
 *   ->limit(20)
 *   ->orderBy('Robots.name')
 *   ->getQuery()
 *   ->execute();
 *</code>
 */


/**
 * Phalcon\Mvc\Model\Query\Builder initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Builder, mvc_model_query_builder, phalcon_mvc_model_query_builder_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_joins"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_conditions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_group"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_having"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_order"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_limit"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_offset"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_forUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_sharedLock"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_query_builder_ce TSRMLS_CC, 2, phalcon_mvc_model_query_builderinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query\Builder constructor
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct){

	zval *params = NULL, *conditions = NULL, *columns, *group_clause;
	zval *having_clause, *order_clause, *limit_clause;
	zval *for_update, *shared_lock;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!params) {
		PHALCON_INIT_VAR(params);
	}
	
	if (Z_TYPE_P(params) == IS_ARRAY) { 
	
		/** 
		 * Process conditions
		 */
		if (phalcon_array_isset_long(params, 0)) {
			PHALCON_OBS_VAR(conditions);
			phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
		} else {
			if (phalcon_array_isset_string(params, SS("conditions"))) {
				PHALCON_OBS_NVAR(conditions);
				phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
				phalcon_update_property_zval(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
			}
		}
	
		/** 
		 * Assign COLUMNS clause
		 */
		if (phalcon_array_isset_string(params, SS("columns"))) {
			PHALCON_OBS_VAR(columns);
			phalcon_array_fetch_string(&columns, params, SL("columns"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_columns"), columns TSRMLS_CC);
		}
	
		/** 
		 * Assign GROUP clause
		 */
		if (phalcon_array_isset_string(params, SS("group"))) {
			PHALCON_OBS_VAR(group_clause);
			phalcon_array_fetch_string(&group_clause, params, SL("group"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_group"), group_clause TSRMLS_CC);
		}
	
		/** 
		 * Assign HAVING clause
		 */
		if (phalcon_array_isset_string(params, SS("having"))) {
			PHALCON_OBS_VAR(having_clause);
			phalcon_array_fetch_string(&having_clause, params, SL("having"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_group"), having_clause TSRMLS_CC);
		}
	
		/** 
		 * Assign ORDER clause
		 */
		if (phalcon_array_isset_string(params, SS("order"))) {
			PHALCON_OBS_VAR(order_clause);
			phalcon_array_fetch_string(&order_clause, params, SL("order"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_order"), order_clause TSRMLS_CC);
		}
	
		/** 
		 * Assign LIMIT clause
		 */
		if (phalcon_array_isset_string(params, SS("limit"))) {
			PHALCON_OBS_VAR(limit_clause);
			phalcon_array_fetch_string(&limit_clause, params, SL("limit"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_limit"), limit_clause TSRMLS_CC);
		}
	
		/** 
		 * Assign FOR UPDATE clause
		 */
		if (phalcon_array_isset_string(params, SS("for_update"))) {
	
			PHALCON_OBS_VAR(for_update);
			phalcon_array_fetch_string(&for_update, params, SL("for_update"), PH_NOISY_CC);
			if (zend_is_true(for_update)) {
				phalcon_update_property_bool(this_ptr, SL("_forUpdate"), 1 TSRMLS_CC);
			}
		}
	
		/** 
		 * Assign SHARED LOCK clause
		 */
		if (phalcon_array_isset_string(params, SS("shared_lock"))) {
	
			PHALCON_OBS_VAR(shared_lock);
			phalcon_array_fetch_string(&shared_lock, params, SL("shared_lock"), PH_NOISY_CC);
			if (zend_is_true(shared_lock)) {
				phalcon_update_property_bool(this_ptr, SL("_sharedLock"), 1 TSRMLS_CC);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The dependency injector must be an Object");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the columns to be queried
 *
 *<code>
 *$builder->columns(array('id', 'name'));
 *</code>
 *
 * @param string|array $columns
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns){

	zval *columns;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &columns) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_columns"), columns TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns){


	RETURN_MEMBER(this_ptr, "_columns");
}

/**
 * Sets the models who makes part of the query
 *
 *<code>
 *$builder->from(array('Robots', 'RobotsParts'));
 *</code>
 *
 * @param string|array $models
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from){

	zval *models;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &models) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_models"), models TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Add a model to take part of the query
 *
 *<code>
 *$builder->addFrom('Robots', 'r');
 *</code>
 *
 * @param string $model
 * @param string $alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, addFrom){

	zval *model, *alias = NULL, *models = NULL, *current_model = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &model, &alias) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!alias) {
		PHALCON_INIT_VAR(alias);
	}
	
	PHALCON_OBS_VAR(models);
	phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if (Z_TYPE_P(models) != IS_ARRAY) { 
		if (Z_TYPE_P(models) != IS_NULL) {
			PHALCON_CPY_WRT(current_model, models);
	
			PHALCON_INIT_NVAR(models);
			array_init(models);
			phalcon_array_append(&models, current_model, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(models);
			array_init(models);
		}
	}
	
	if (Z_TYPE_P(alias) == IS_STRING) {
		phalcon_array_update_zval(&models, alias, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		phalcon_array_append(&models, model, PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_models"), models TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom){


	RETURN_MEMBER(this_ptr, "_models");
}

/**
 * Adds a join to the query
 *
 *<code>
 *$builder->join('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *</code>
 *
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, join){

	zval *model, *conditions = NULL, *alias = NULL, *join, *joins = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &model, &conditions, &alias) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!conditions) {
		PHALCON_INIT_VAR(conditions);
	}
	
	if (!alias) {
		PHALCON_INIT_VAR(alias);
	}
	
	PHALCON_INIT_VAR(join);
	array_init_size(join, 3);
	phalcon_array_append(&join, model, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&join, conditions, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&join, alias, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_OBS_VAR(joins);
	phalcon_read_property(&joins, this_ptr, SL("_joins"), PH_NOISY_CC);
	if (Z_TYPE_P(joins) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(joins);
		array_init(joins);
	}
	
	phalcon_array_append(&joins, join, PH_SEPARATE TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_joins"), joins TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Sets the query conditions
 *
 *<code>
 *	$builder->where('name = :name: AND id > :id:');
 *</code>
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where){

	zval *conditions;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &conditions) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Appends a condition to the current conditions using a AND operator
 *
 *<code>
 *	$builder->andWhere('name = :name: AND id > :id:');
 *</code>
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andWhere){

	zval *conditions, *current_conditions, *new_conditions = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &conditions) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(current_conditions);
	phalcon_read_property(&current_conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zend_is_true(current_conditions)) {
		PHALCON_INIT_VAR(new_conditions);
		PHALCON_CONCAT_SVSVS(new_conditions, "(", current_conditions, ") AND (", conditions, ")");
	} else {
		PHALCON_CPY_WRT(new_conditions, current_conditions);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_conditions"), new_conditions TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Appends a condition to the current conditions using a OR operator
 *
 *<code>
 *	$builder->orWhere('name = :name: AND id > :id:');
 *</code>
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orWhere){

	zval *conditions, *current_conditions, *new_conditions = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &conditions) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(current_conditions);
	phalcon_read_property(&current_conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zend_is_true(current_conditions)) {
		PHALCON_INIT_VAR(new_conditions);
		PHALCON_CONCAT_SVSVS(new_conditions, "(", current_conditions, ") OR (", conditions, ")");
	} else {
		PHALCON_CPY_WRT(new_conditions, current_conditions);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_conditions"), new_conditions TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Return the conditions for the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getWhere){


	RETURN_MEMBER(this_ptr, "_conditions");
}

/**
 * Sets a ORDER BY condition clause
 *
 *<code>
 *	$builder->orderBy('Robots.name');
 *	$builder->orderBy(array('1', 'Robots.name'));
 *</code>
 *
 * @param string $orderBy
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy){

	zval *order_by;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &order_by) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_order"), order_by TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the set ORDER BY clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy){


	RETURN_MEMBER(this_ptr, "_order");
}

/**
 * Sets a HAVING condition clause. You need to escape PHQL reserved words using [ and ] delimiters
 *
 *<code>
 *$builder->having('SUM(Robots.price) > 0');
 *</code>
 *
 * @param string $having
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, having){

	zval *having;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &having) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_having"), having TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Return the current having clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving){


	RETURN_MEMBER(this_ptr, "_having");
}

/**
 * Sets a LIMIT clause, optionally a offset clause
 *
 *<code>
 *	$builder->limit(100);
 *	$builder->limit(100, 20);
 *</code>
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit){

	zval *limit, *offset = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &limit, &offset) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!offset) {
		PHALCON_INIT_VAR(offset);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_limit"), limit TSRMLS_CC);
	if (Z_TYPE_P(offset) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_offset"), offset TSRMLS_CC);
	}
	
	
	RETURN_THIS();
}

/**
 * Returns the current LIMIT clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit){


	RETURN_MEMBER(this_ptr, "_limit");
}

/**
 * Sets an OFFSET clause
 *
 *<code>
 *	$builder->offset(30);
 *</code>
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, offset){

	zval *offset;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &offset) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_offset"), offset TSRMLS_CC);
	
}

/**
 * Returns the current OFFSET clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOffset){


	RETURN_MEMBER(this_ptr, "_offset");
}

/**
 * Sets a GROUP BY clause
 *
 *<code>
 *$builder->groupBy(array('Robots.name'));
 *</code>
 *
 * @param string $group
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, groupBy){

	zval *group;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &group) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_group"), group TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the GROUP BY clause
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy){


	RETURN_MEMBER(this_ptr, "_group");
}

/**
 * Returns a PHQL statement built based on the builder parameters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql){

	zval *dependency_injector = NULL, *models, *conditions = NULL;
	zval *is_numeric, *one, *number_models, *invalid_condition;
	zval *model = NULL, *service_name, *meta_data, *model_instance;
	zval *no_primary = NULL, *primary_keys, *connection;
	zval *first_primary_key, *column_map = NULL, *attribute_field = NULL;
	zval *exception_message, *primary_key_condition;
	zval *phql, *columns, *selected_columns = NULL, *column = NULL;
	zval *alias = NULL, *aliased_column = NULL, *joined_columns = NULL;
	zval *selected_column = NULL, *selected_models, *selected_model = NULL;
	zval *joined_models, *joins, *join = NULL, *join_model = NULL;
	zval *join_conditions = NULL, *join_alias = NULL, *group, *group_items;
	zval *group_item = NULL, *escaped_item = NULL, *joined_items = NULL;
	zval *having, *order, *order_items, *order_item = NULL;
	zval *limit, *number, *offset = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4, *ah5;
	HashPosition hp0, hp1, hp2, hp3, hp4, hp5;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
		phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(models);
	phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if (Z_TYPE_P(models) == IS_ARRAY) { 
		if (!phalcon_fast_count_ev(models TSRMLS_CC)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
			return;
		}
	} else {
		if (!zend_is_true(models)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
			return;
		}
	}
	
	PHALCON_OBS_VAR(conditions);
	phalcon_read_property(&conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(is_numeric);
	PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", conditions);
	if (zend_is_true(is_numeric)) {
	
		/** 
		 * If the conditions is a single numeric field. We internally create a condition
		 * using the related primary key
		 */
		if (Z_TYPE_P(models) == IS_ARRAY) { 
	
			PHALCON_INIT_VAR(one);
			ZVAL_LONG(one, 1);
	
			PHALCON_INIT_VAR(number_models);
			phalcon_fast_count(number_models, models TSRMLS_CC);
	
			PHALCON_INIT_VAR(invalid_condition);
			is_smaller_function(invalid_condition, one, number_models TSRMLS_CC);
			if (PHALCON_IS_TRUE(invalid_condition)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot build the query. Invalid condition");
				return;
			}
	
			PHALCON_OBS_VAR(model);
			phalcon_array_fetch_long(&model, models, 0, PH_NOISY_CC);
		} else {
			PHALCON_CPY_WRT(model, models);
		}
	
		PHALCON_INIT_VAR(service_name);
		ZVAL_STRING(service_name, "modelsMetadata", 1);
	
		/** 
		 * Get the models metadata service to obtain the column names, column map and
		 * primary key
		 */
		PHALCON_INIT_VAR(meta_data);
		PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service_name);
		ce0 = phalcon_fetch_class(model TSRMLS_CC);
	
		PHALCON_INIT_VAR(model_instance);
		object_init_ex(model_instance, ce0);
		if (phalcon_has_constructor(model_instance TSRMLS_CC)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model_instance, "__construct", dependency_injector);
		}
	
		PHALCON_INIT_VAR(no_primary);
		ZVAL_BOOL(no_primary, 1);
	
		PHALCON_INIT_VAR(primary_keys);
		PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", model_instance);
		if (phalcon_fast_count_ev(primary_keys TSRMLS_CC)) {
			if (phalcon_array_isset_long(primary_keys, 0)) {
	
				PHALCON_INIT_VAR(connection);
				PHALCON_CALL_METHOD(connection, model_instance, "getconnection");
	
				PHALCON_OBS_VAR(first_primary_key);
				phalcon_array_fetch_long(&first_primary_key, primary_keys, 0, PH_NOISY_CC);
	
				/** 
				 * The PHQL contains the renamed columns if available
				 */
				if (PHALCON_GLOBAL(orm).column_renaming) {
					PHALCON_INIT_VAR(column_map);
					PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", model_instance);
				} else {
					PHALCON_INIT_NVAR(column_map);
				}
	
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
					if (phalcon_array_isset(column_map, first_primary_key)) {
						PHALCON_OBS_VAR(attribute_field);
						phalcon_array_fetch(&attribute_field, column_map, first_primary_key, PH_NOISY_CC);
					} else {
						PHALCON_INIT_VAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", first_primary_key, "\" isn't part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_CPY_WRT(attribute_field, first_primary_key);
				}
	
				PHALCON_INIT_VAR(primary_key_condition);
				PHALCON_CONCAT_SVSVSV(primary_key_condition, "[", model, "].[", attribute_field, "] = ", conditions);
				PHALCON_CPY_WRT(conditions, primary_key_condition);
	
				ZVAL_BOOL(no_primary, 0);
			}
		}
	
		/** 
		 * A primary key is mandatory in these cases
		 */
		if (PHALCON_IS_TRUE(no_primary)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined");
			return;
		}
	}
	
	PHALCON_INIT_VAR(phql);
	ZVAL_STRING(phql, "SELECT ", 1);
	
	PHALCON_OBS_VAR(columns);
	phalcon_read_property(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
	if (Z_TYPE_P(columns) != IS_NULL) {
		if (Z_TYPE_P(columns) == IS_ARRAY) { 
	
			PHALCON_INIT_VAR(selected_columns);
			array_init(selected_columns);
	
			if (!phalcon_is_iterable(columns, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(alias, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(column);
	
				if (Z_TYPE_P(alias) == IS_LONG) {
					phalcon_array_append(&selected_columns, column, PH_SEPARATE TSRMLS_CC);
				} else {
					PHALCON_INIT_NVAR(aliased_column);
					PHALCON_CONCAT_VSV(aliased_column, column, " AS ", alias);
					phalcon_array_append(&selected_columns, aliased_column, PH_SEPARATE TSRMLS_CC);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			PHALCON_INIT_VAR(joined_columns);
			phalcon_fast_join_str(joined_columns, SL(", "), selected_columns TSRMLS_CC);
			phalcon_concat_self(&phql, joined_columns TSRMLS_CC);
		} else {
			phalcon_concat_self(&phql, columns TSRMLS_CC);
		}
	} else {
		if (Z_TYPE_P(models) == IS_ARRAY) { 
	
			PHALCON_INIT_NVAR(selected_columns);
			array_init(selected_columns);
	
			if (!phalcon_is_iterable(models, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(alias, ah1, hp1);
				PHALCON_GET_FOREACH_VALUE(model);
	
				if (Z_TYPE_P(alias) == IS_LONG) {
					PHALCON_INIT_NVAR(selected_column);
					PHALCON_CONCAT_SVS(selected_column, "[", model, "].*");
				} else {
					PHALCON_INIT_NVAR(selected_column);
					PHALCON_CONCAT_SVS(selected_column, "[", alias, "].*");
				}
				phalcon_array_append(&selected_columns, selected_column, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
			PHALCON_INIT_NVAR(joined_columns);
			phalcon_fast_join_str(joined_columns, SL(", "), selected_columns TSRMLS_CC);
			phalcon_concat_self(&phql, joined_columns TSRMLS_CC);
		} else {
			PHALCON_SCONCAT_SVS(phql, "[", models, "].*");
		}
	}
	
	/** 
	 * Join multiple models or use a single one if it is a string
	 */
	if (Z_TYPE_P(models) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(selected_models);
		array_init(selected_models);
	
		if (!phalcon_is_iterable(models, &ah2, &hp2, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(alias, ah2, hp2);
			PHALCON_GET_FOREACH_VALUE(model);
	
			if (Z_TYPE_P(alias) == IS_STRING) {
				PHALCON_INIT_NVAR(selected_model);
				PHALCON_CONCAT_SVSVS(selected_model, "[", model, "] AS [", alias, "]");
			} else {
				PHALCON_INIT_NVAR(selected_model);
				PHALCON_CONCAT_SVS(selected_model, "[", model, "]");
			}
			phalcon_array_append(&selected_models, selected_model, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
		PHALCON_INIT_VAR(joined_models);
		phalcon_fast_join_str(joined_models, SL(", "), selected_models TSRMLS_CC);
		PHALCON_SCONCAT_SV(phql, " FROM ", joined_models);
	} else {
		PHALCON_SCONCAT_SVS(phql, " FROM [", models, "]");
	}
	
	/** 
	 * Check if joins were passed to the builders
	 */
	PHALCON_OBS_VAR(joins);
	phalcon_read_property(&joins, this_ptr, SL("_joins"), PH_NOISY_CC);
	if (Z_TYPE_P(joins) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(joins, &ah3, &hp3, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(join);
	
			/** 
			 * The joined table is in the first place of the array
			 */
			PHALCON_OBS_NVAR(join_model);
			phalcon_array_fetch_long(&join_model, join, 0, PH_NOISY_CC);
	
			/** 
			 * The join conditions are in the second place of the array
			 */
			PHALCON_OBS_NVAR(join_conditions);
			phalcon_array_fetch_long(&join_conditions, join, 1, PH_NOISY_CC);
	
			/** 
			 * The join alias is in the second place of the array
			 */
			PHALCON_OBS_NVAR(join_alias);
			phalcon_array_fetch_long(&join_alias, join, 2, PH_NOISY_CC);
			PHALCON_SCONCAT_SVS(phql, " JOIN [", join_model, "]");
			if (zend_is_true(join_conditions)) {
				PHALCON_SCONCAT_SV(phql, " ON ", join_conditions);
			}
	
			if (zend_is_true(join_alias)) {
				PHALCON_SCONCAT_SVS(phql, " AS [", join_alias, "]");
			}
	
			zend_hash_move_forward_ex(ah3, &hp3);
		}
	
	}
	
	if (Z_TYPE_P(conditions) == IS_STRING) {
		PHALCON_SCONCAT_SV(phql, " WHERE ", conditions);
	}
	
	/** 
	 * Process group parameters
	 */
	PHALCON_OBS_VAR(group);
	phalcon_read_property(&group, this_ptr, SL("_group"), PH_NOISY_CC);
	if (Z_TYPE_P(group) != IS_NULL) {
		if (Z_TYPE_P(group) == IS_ARRAY) { 
	
			PHALCON_INIT_VAR(group_items);
			array_init(group_items);
	
			if (!phalcon_is_iterable(group, &ah4, &hp4, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(group_item);
	
				if (phalcon_is_numeric(group_item)) {
					phalcon_array_append(&group_items, group_item, PH_SEPARATE TSRMLS_CC);
				} else {
					if (phalcon_memnstr_str(group_item, SL(".") TSRMLS_CC)) {
						phalcon_array_append(&group_items, group_item, PH_SEPARATE TSRMLS_CC);
					} else {
						PHALCON_INIT_NVAR(escaped_item);
						PHALCON_CONCAT_SVS(escaped_item, "[", group_item, "]");
						phalcon_array_append(&group_items, escaped_item, PH_SEPARATE TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah4, &hp4);
			}
	
			PHALCON_INIT_VAR(joined_items);
			phalcon_fast_join_str(joined_items, SL(", "), group_items TSRMLS_CC);
			PHALCON_SCONCAT_SV(phql, " GROUP BY ", joined_items);
		} else {
			if (phalcon_is_numeric(group)) {
				PHALCON_SCONCAT_SV(phql, " GROUP BY ", group);
			} else {
				if (phalcon_memnstr_str(group, SL(".") TSRMLS_CC)) {
					PHALCON_SCONCAT_SV(phql, " GROUP BY ", group);
				} else {
					PHALCON_SCONCAT_SVS(phql, " GROUP BY [", group, "]");
				}
			}
		}
	
		PHALCON_OBS_VAR(having);
		phalcon_read_property(&having, this_ptr, SL("_having"), PH_NOISY_CC);
		if (Z_TYPE_P(having) != IS_NULL) {
			PHALCON_SCONCAT_SV(phql, " HAVING ", having);
		}
	}
	
	/** 
	 * Process order clause
	 */
	PHALCON_OBS_VAR(order);
	phalcon_read_property(&order, this_ptr, SL("_order"), PH_NOISY_CC);
	if (Z_TYPE_P(order) != IS_NULL) {
		if (Z_TYPE_P(order) == IS_ARRAY) { 
	
			PHALCON_INIT_VAR(order_items);
			array_init(order_items);
	
			if (!phalcon_is_iterable(order, &ah5, &hp5, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(order_item);
	
				if (phalcon_is_numeric(order_item)) {
					phalcon_array_append(&order_items, order_item, PH_SEPARATE TSRMLS_CC);
				} else {
					if (phalcon_memnstr_str(order_item, SL(".") TSRMLS_CC)) {
						phalcon_array_append(&order_items, order_item, PH_SEPARATE TSRMLS_CC);
					} else {
						PHALCON_INIT_NVAR(escaped_item);
						PHALCON_CONCAT_SVS(escaped_item, "[", order_item, "]");
						phalcon_array_append(&order_items, escaped_item, PH_SEPARATE TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah5, &hp5);
			}
	
			PHALCON_INIT_NVAR(joined_items);
			phalcon_fast_join_str(joined_items, SL(", "), order_items TSRMLS_CC);
			PHALCON_SCONCAT_SV(phql, " ORDER BY ", joined_items);
		} else {
			PHALCON_SCONCAT_SV(phql, " ORDER BY ", order);
		}
	}
	
	/** 
	 * Process limit parameters
	 */
	PHALCON_OBS_VAR(limit);
	phalcon_read_property(&limit, this_ptr, SL("_limit"), PH_NOISY_CC);
	if (Z_TYPE_P(limit) != IS_NULL) {
		if (Z_TYPE_P(limit) == IS_ARRAY) { 
	
			PHALCON_OBS_VAR(number);
			phalcon_array_fetch_string(&number, limit, SL("number"), PH_NOISY_CC);
			if (phalcon_array_isset_string(limit, SS("offset"))) {
				PHALCON_OBS_VAR(offset);
				phalcon_array_fetch_string(&offset, limit, SL("offset"), PH_NOISY_CC);
				PHALCON_SCONCAT_SVSV(phql, " LIMIT ", number, " OFFSET ", offset);
			} else {
				PHALCON_SCONCAT_SV(phql, " LIMIT ", number);
			}
		} else {
			PHALCON_SCONCAT_SV(phql, " LIMIT ", limit);
	
			PHALCON_OBS_NVAR(offset);
			phalcon_read_property(&offset, this_ptr, SL("_offset"), PH_NOISY_CC);
			if (Z_TYPE_P(offset) != IS_NULL) {
				PHALCON_SCONCAT_SV(phql, " OFFSET ", offset);
			}
		}
	}
	
	
	RETURN_CTOR(phql);
}

/**
 * Returns the query built
 *
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery){

	zval *phql, *query, *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(phql);
	PHALCON_CALL_METHOD(phql, this_ptr, "getphql");
	
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", phql);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector);
	RETURN_CTOR(query);
}

