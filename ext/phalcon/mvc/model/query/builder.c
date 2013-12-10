
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"


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
/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *<code>
 * $params = array(
 *    'models'     => array('Users'),
 *    'columns'    => array('id', 'name', 'status'),
 *    'conditions' => array(
 *        array(
 *            "created > :min: AND created < :max:",
 *            array("min" => '2013-01-01',   'max' => '2014-01-01'),
 *            array("min" => PDO::PARAM_STR, 'max' => PDO::PARAM_STR),
 *        ),
 *    ),
 *    // or 'conditions' => "created > '2013-01-01' AND created < '2014-01-01'",
 *    'group'      => array('id', 'name'),
 *    'having'     => "name = 'Kamil'",
 *    'order'      => array('name', 'id'),
 *    'limit'      => 20,
 *    'offset'     => 20,
 *    // or 'limit' => array(20, 20),
 *);
 *$queryBuilder = new Phalcon\Mvc\Model\Query\Builder($params);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Builder, phalcon, mvc_model_query_builder, phalcon_mvc_model_query_builder_method_entry, 0);

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
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_query_builder_ce, SL("_hiddenParamNumber"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Query\Builder constructor
 *
 * @param array params
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct) {

	HashTable *_1;
	HashPosition _0;
	zval *params = NULL, *dependencyInjector = NULL, *conditions = NULL, *columns, *groupClause, *havingClause, *limitClause, *forUpdate, *sharedLock, *orderClause, *offsetClause, *joinsClause, *singleConditionArray = NULL, *limit, *offset, *fromClause, *mergedConditions = NULL, *mergedParams = NULL, *mergedTypes = NULL, *singleCondition, *singleParams, *singleTypes, **_2, *_3 = NULL, _4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &params, &dependencyInjector);

	if (!params || Z_TYPE_P(params) == IS_NULL) {
		params = ZEPHIR_GLOBAL(global_null);
	}
	if (!dependencyInjector || Z_TYPE_P(dependencyInjector) == IS_NULL) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(params) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(conditions);
		if (zephir_array_isset_long_fetch(&conditions, params, 0, 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(conditions);
			if (zephir_array_isset_string_fetch(&conditions, params, SS("conditions"), 0 TSRMLS_CC)) {
				if ((Z_TYPE_P(conditions) == IS_ARRAY)) {
					ZEPHIR_INIT_VAR(mergedConditions);
					array_init(mergedConditions);
					ZEPHIR_INIT_VAR(mergedParams);
					array_init(mergedParams);
					ZEPHIR_INIT_VAR(mergedTypes);
					array_init(mergedTypes);
					zephir_is_iterable(conditions, &_1, &_0, 0, 0);
					for (
						; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
						; zend_hash_move_forward_ex(_1, &_0)
					) {
						ZEPHIR_GET_HVALUE(singleConditionArray, _2);
						if ((Z_TYPE_P(singleConditionArray) == IS_ARRAY)) {
							if ((Z_TYPE_P(singleCondition) == IS_STRING)) {
								Z_SET_ISREF_P(mergedConditions);
								ZEPHIR_INIT_NVAR(_3);
								zephir_call_func_p2(_3, "array_push", mergedConditions, singleCondition);
								ZEPHIR_CPY_WRT(mergedConditions, _3);
							}
							if ((Z_TYPE_P(singleParams) == IS_ARRAY)) {
								ZEPHIR_INIT_NVAR(_3);
								zephir_fast_array_merge(_3, &(mergedParams), &(singleParams) TSRMLS_CC);
								ZEPHIR_CPY_WRT(mergedParams, _3);
							}
							if ((Z_TYPE_P(singleTypes) == IS_ARRAY)) {
								ZEPHIR_INIT_NVAR(_3);
								zephir_fast_array_merge(_3, &(mergedTypes), &(singleTypes) TSRMLS_CC);
								ZEPHIR_CPY_WRT(mergedTypes, _3);
							}
						}
					}
					ZEPHIR_SINIT_VAR(_4);
					ZVAL_STRING(&_4, " AND ", 0);
					ZEPHIR_INIT_NVAR(_3);
					zephir_call_func_p2(_3, "implode", &_4, mergedConditions);
					zephir_update_property_this(this_ptr, SL("_conditions"), _3 TSRMLS_CC);
					zephir_update_property_this(this_ptr, SL("_bindParams"), mergedParams TSRMLS_CC);
					zephir_update_property_this(this_ptr, SL("_bindTypes"), mergedTypes TSRMLS_CC);
				} else {
					zephir_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
				}
			}
		}
		if (zephir_array_isset_string_fetch(&fromClause, params, SS("models"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_models"), fromClause TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&columns, params, SS("columns"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&joinsClause, params, SS("joins"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_joins"), joinsClause TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&groupClause, params, SS("group"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_group"), groupClause TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&havingClause, params, SS("having"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_having"), havingClause TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&orderClause, params, SS("order"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_order"), orderClause TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&limitClause, params, SS("limit"), 1 TSRMLS_CC)) {
			if ((Z_TYPE_P(limitClause) == IS_ARRAY)) {
				ZEPHIR_INIT_VAR(_5);
				zephir_call_func_p1(_5, "is_int", limit);
				if (zephir_is_true(_5)) {
					zephir_update_property_this(this_ptr, SL("_limit"), limit TSRMLS_CC);
				}
				ZEPHIR_INIT_VAR(_6);
				zephir_call_func_p1(_6, "is_int", offset);
				if (zephir_is_true(_6)) {
					zephir_update_property_this(this_ptr, SL("_offset"), offset TSRMLS_CC);
				}
			} else {
				zephir_update_property_this(this_ptr, SL("_limit"), limitClause TSRMLS_CC);
			}
		}
		if (zephir_array_isset_string_fetch(&offsetClause, params, SS("offset"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_offset"), offsetClause TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&forUpdate, params, SS("for_update"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_forUpdate"), forUpdate TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&sharedLock, params, SS("shared_lock"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_sharedLock"), sharedLock TSRMLS_CC);
		}
	}
	if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the columns to be queried
 *
 *<code>
 *	$builder->columns(array('id', 'name'));
 *</code>
 *
 * @param string|array columns
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns) {

	zval *columns;

	zephir_fetch_params(0, 1, 0, &columns);



	zephir_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns) {


	RETURN_MEMBER(this_ptr, "_columns");

}

/**
 * Sets the models who makes part of the query
 *
 *<code>
 *	$builder->from('Robots');
 *	$builder->from(array('Robots', 'RobotsParts'));
 *</code>
 *
 * @param string|array models
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from) {

	zval *models;

	zephir_fetch_params(0, 1, 0, &models);



	zephir_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Add a model to take part of the query
 *
 *<code>
 *	$builder->addFrom('Robots', 'r');
 *</code>
 *
 * @param string model
 * @param string alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, addFrom) {

	zval *model, *alias = NULL, *models, *currentModel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &model, &alias);

	if (!alias || Z_TYPE_P(alias) == IS_NULL) {
		alias = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(models);
	zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if ((Z_TYPE_P(models) != IS_ARRAY)) {
		ZEPHIR_INIT_BNVAR(models);
		if ((Z_TYPE_P(models) != IS_NULL)) {
			ZEPHIR_CPY_WRT(currentModel, models);
			array_init(models);
			zephir_array_fast_append(models, currentModel);
		} else {
			array_init(models);
		}
	}
	if ((Z_TYPE_P(alias) != IS_STRING)) {
		zephir_array_update_zval(&models, alias, &model, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_append(&models, model, PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_models"), models TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom) {


	RETURN_MEMBER(this_ptr, "_models");

}

/**
 * Adds a INNER join to the query
 *
 *<code>
 *	$builder->join('Robots');
 *	$builder->join('Robots', 'r.id = RobotsParts.robots_id');
 *	$builder->join('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *	$builder->join('Robots', 'r.id = RobotsParts.robots_id', 'r', 'LEFT');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @param string type
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, join) {

	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *type = NULL, *_0;
	zval *model = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model_param, &conditions, &alias, &type);

		if (Z_TYPE_P(model_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		model = model_param;

	if (!conditions || Z_TYPE_P(conditions) == IS_NULL) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!alias || Z_TYPE_P(alias) == IS_NULL) {
		alias = ZEPHIR_GLOBAL(global_null);
	}
	if (!type || Z_TYPE_P(type) == IS_NULL) {
		type = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_fast_append(_0, model);
	zephir_array_fast_append(_0, conditions);
	zephir_array_fast_append(_0, alias);
	zephir_array_fast_append(_0, type);
	zephir_update_property_array_append(this_ptr, SL("_joins"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a INNER join to the query
 *
 *<code>
 *	$builder->innerJoin('Robots');
 *	$builder->innerJoin('Robots', 'r.id = RobotsParts.robots_id');
 *	$builder->innerJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *	$builder->innerJoin('Robots', 'r.id = RobotsParts.robots_id', 'r', 'LEFT');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @param string type
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, innerJoin) {

	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *_0, *_1;
	zval *model = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);

		if (Z_TYPE_P(model_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		model = model_param;

	if (!conditions || Z_TYPE_P(conditions) == IS_NULL) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!alias || Z_TYPE_P(alias) == IS_NULL) {
		alias = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_fast_append(_0, model);
	zephir_array_fast_append(_0, conditions);
	zephir_array_fast_append(_0, alias);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "INNER", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_array_append(this_ptr, SL("_joins"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a LEFT join to the query
 *
 *<code>
 *	$builder->leftJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, leftJoin) {

	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *_0, *_1;
	zval *model = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);

		if (Z_TYPE_P(model_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		model = model_param;

	if (!conditions || Z_TYPE_P(conditions) == IS_NULL) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!alias || Z_TYPE_P(alias) == IS_NULL) {
		alias = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_fast_append(_0, model);
	zephir_array_fast_append(_0, conditions);
	zephir_array_fast_append(_0, alias);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "LEFT", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_array_append(this_ptr, SL("_joins"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a RIGHT join to the query
 *
 *<code>
 *	$builder->rightJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, rightJoin) {

	zval *model, *conditions = NULL, *alias = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model, &conditions, &alias);

	if (!conditions || Z_TYPE_P(conditions) == IS_NULL) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!alias || Z_TYPE_P(alias) == IS_NULL) {
		alias = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_fast_append(_0, model);
	zephir_array_fast_append(_0, conditions);
	zephir_array_fast_append(_0, alias);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "RIGHT", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("_joins"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the query conditions
 *
 *<code>
 *	$builder->where('name = "Peter"');
 *	$builder->where('name = :name: AND id > :id:', array('name' => 'Peter', 'id' => 100));
 *</code>
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where) {

	zval *conditions, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *currentBindTypes, *mergedParams = NULL, *mergedTypes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions, &bindParams, &bindTypes);

	if (!bindParams || Z_TYPE_P(bindParams) == IS_NULL) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes || Z_TYPE_P(bindTypes) == IS_NULL) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
	if ((Z_TYPE_P(bindParams) == IS_ARRAY)) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentBindParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(currentBindParams), &(bindParams) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		zephir_update_property_this(this_ptr, SL("_bindParams"), mergedParams TSRMLS_CC);
	}
	if ((Z_TYPE_P(bindTypes) == IS_ARRAY)) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentBindParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_fast_array_merge(mergedTypes, &(currentBindTypes), &(bindTypes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedTypes, bindTypes);
		}
		zephir_update_property_this(this_ptr, SL("_bindTypes"), mergedTypes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Appends a condition to the current conditions using a AND operator
 *
 *<code>
 *	$builder->andWhere('name = "Peter"');
 *	$builder->andWhere('name = :name: AND id > :id:', array('name' => 'Peter', 'id' => 100));
 *</code>
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andWhere) {

	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *currentBindTypes, *mergedParams = NULL, *mergedTypes = NULL, *currentConditions, *newConditions = NULL;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

		if (Z_TYPE_P(conditions_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		conditions = conditions_param;

	if (!bindParams || Z_TYPE_P(bindParams) == IS_NULL) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes || Z_TYPE_P(bindTypes) == IS_NULL) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	currentConditions = zephir_fetch_nproperty_this(this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_true(currentConditions)) {
		ZEPHIR_INIT_VAR(newConditions);
		ZEPHIR_CONCAT_SVSVS(newConditions, "(", currentConditions, ") AND (", conditions, ")");
	} else {
		ZEPHIR_CPY_WRT(newConditions, conditions);
	}
	zephir_update_property_this(this_ptr, SL("_conditions"), newConditions TSRMLS_CC);
	if ((Z_TYPE_P(bindParams) == IS_ARRAY)) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentBindParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(currentBindParams), &(bindParams) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		zephir_update_property_this(this_ptr, SL("_bindParams"), mergedParams TSRMLS_CC);
	}
	if ((Z_TYPE_P(bindTypes) == IS_ARRAY)) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentBindParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_fast_array_merge(mergedTypes, &(currentBindTypes), &(bindTypes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedTypes, bindTypes);
		}
		zephir_update_property_this(this_ptr, SL("_bindTypes"), mergedTypes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Appends a condition to the current conditions using a OR operator
 *
 *<code>
 *	$builder->orWhere('name = "Peter"');
 *	$builder->orWhere('name = :name: AND id > :id:', array('name' => 'Peter', 'id' => 100));
 *</code>
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orWhere) {

	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *currentBindTypes, *mergedParams = NULL, *mergedTypes = NULL, *currentConditions, *newConditions = NULL;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

		if (Z_TYPE_P(conditions_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		conditions = conditions_param;

	if (!bindParams || Z_TYPE_P(bindParams) == IS_NULL) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes || Z_TYPE_P(bindTypes) == IS_NULL) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	currentConditions = zephir_fetch_nproperty_this(this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_true(currentConditions)) {
		ZEPHIR_INIT_VAR(newConditions);
		ZEPHIR_CONCAT_SVSVS(newConditions, "(", currentConditions, ") OR (", conditions, ")");
	} else {
		ZEPHIR_CPY_WRT(newConditions, conditions);
	}
	zephir_update_property_this(this_ptr, SL("_conditions"), newConditions TSRMLS_CC);
	if ((Z_TYPE_P(bindParams) == IS_ARRAY)) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentBindParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(currentBindParams), &(bindParams) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		zephir_update_property_this(this_ptr, SL("_bindParams"), mergedParams TSRMLS_CC);
	}
	if ((Z_TYPE_P(bindTypes) == IS_ARRAY)) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentBindParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_fast_array_merge(mergedTypes, &(currentBindTypes), &(bindTypes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedTypes, bindTypes);
		}
		zephir_update_property_this(this_ptr, SL("_bindTypes"), mergedTypes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Appends a BETWEEN condition to the current conditions
 *
 *<code>
 *	$builder->betweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenWhere) {

	zval *expr_param = NULL, *minimum, *maximum, *hiddenParam, *nextHiddenParam, *minimumKey, *maximumKey, *_0, *_1;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

		if (Z_TYPE_P(expr_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		expr = expr_param;



	hiddenParam = zephir_fetch_nproperty_this(this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(nextHiddenParam);
	ZVAL_LONG(nextHiddenParam, (zephir_get_numberval(hiddenParam) + 1));
	ZEPHIR_INIT_VAR(minimumKey);
	ZEPHIR_CONCAT_SV(minimumKey, "phb", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "phb", nextHiddenParam);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVSVS(_0, expr, " BETWEEN :", minimumKey, ": AND :", maximumKey, ":");
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_array_update_zval(&_1, minimumKey, &minimum, PH_COPY);
	zephir_array_update_zval(&_1, maximumKey, &maximum, PH_COPY);
	zephir_call_method_p2_noret(this_ptr, "andwhere", _0, _1);
	ZEPHIR_SEPARATE(nextHiddenParam);
	zephir_increment(nextHiddenParam);
	zephir_update_property_this(this_ptr, SL("_hiddenParamNumber"), nextHiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 *<code>
 *	$builder->notBetweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenWhere) {

	zval *expr_param = NULL, *minimum, *maximum, *hiddenParam, *nextHiddenParam, *minimumKey, *maximumKey, *_0, *_1;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

		if (Z_TYPE_P(expr_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		expr = expr_param;



	hiddenParam = zephir_fetch_nproperty_this(this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(nextHiddenParam);
	ZVAL_LONG(nextHiddenParam, (zephir_get_numberval(hiddenParam) + 1));
	ZEPHIR_INIT_VAR(minimumKey);
	ZEPHIR_CONCAT_SV(minimumKey, "phb", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "phb", nextHiddenParam);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVSVS(_0, expr, " NOT BETWEEN :", minimumKey, ": AND :", maximumKey, ":");
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_array_update_zval(&_1, minimumKey, &minimum, PH_COPY);
	zephir_array_update_zval(&_1, maximumKey, &maximum, PH_COPY);
	zephir_call_method_p2_noret(this_ptr, "andwhere", _0, _1);
	ZEPHIR_SEPARATE(nextHiddenParam);
	zephir_increment(nextHiddenParam);
	zephir_update_property_this(this_ptr, SL("_hiddenParamNumber"), nextHiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends an IN condition to the current conditions
 *
 *<code>
 *	$builder->inWhere('id', [1, 2, 3]);
 *</code>
 *
 * @param string expr
 * @param array values
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inWhere) {

	HashTable *_2;
	HashPosition _1;
	int hiddenParam;
	zval *expr_param = NULL, *values, *key = NULL, *queryKey = NULL, *value = NULL, *bindKeys, *bindParams, *_0, **_3, _4 = zval_used_for_init, *_5, *_6, *_7;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values);

		if (Z_TYPE_P(expr_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		expr = expr_param;



	if ((Z_TYPE_P(values) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Values must be an array");
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(_0);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, hiddenParam);
		ZEPHIR_INIT_NVAR(key);
		ZEPHIR_CONCAT_SV(key, "phi", &_4);
		ZEPHIR_INIT_NVAR(queryKey);
		ZEPHIR_CONCAT_SVS(queryKey, ":", key, ":");
		zephir_array_append(&bindKeys, queryKey, PH_SEPARATE);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		hiddenParam++;
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VSVS(_6, expr, " IN (", _5, ")");
	zephir_call_method_p2_noret(this_ptr, "andwhere", _6, bindParams);
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, hiddenParam);
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), _7 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a NOT IN condition to the current conditions
 *
 *<code>
 *	$builder->notInWhere('id', [1, 2, 3]);
 *</code>
 *
 * @param string expr
 * @param array values
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInWhere) {

	HashTable *_2;
	HashPosition _1;
	int hiddenParam;
	zval *expr_param = NULL, *values, *key = NULL, *queryKey = NULL, *value = NULL, *bindKeys, *bindParams, *_0, **_3, _4 = zval_used_for_init, *_5, *_6, *_7;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values);

		if (Z_TYPE_P(expr_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		expr = expr_param;



	if ((Z_TYPE_P(values) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Values must be an array");
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(_0);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, hiddenParam);
		ZEPHIR_INIT_NVAR(key);
		ZEPHIR_CONCAT_SV(key, "phi", &_4);
		ZEPHIR_INIT_NVAR(queryKey);
		ZEPHIR_CONCAT_SVS(queryKey, ":", key, ":");
		zephir_array_append(&bindKeys, queryKey, PH_SEPARATE);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		hiddenParam++;
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VSVS(_6, expr, " NOT IN (", _5, ")");
	zephir_call_method_p2_noret(this_ptr, "andwhere", _6, bindParams);
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, hiddenParam);
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), _7 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return the conditions for the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getWhere) {


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
 * @param string orderBy
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy) {

	zval *orderBy;

	zephir_fetch_params(0, 1, 0, &orderBy);



	zephir_update_property_this(this_ptr, SL("_order"), orderBy TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the set ORDER BY clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy) {


	RETURN_MEMBER(this_ptr, "_order");

}

/**
 * Sets a HAVING condition clause. You need to escape PHQL reserved words using [ and ] delimiters
 *
 *<code>
 *	$builder->having('SUM(Robots.price) > 0');
 *</code>
 *
 * @param string having
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, having) {

	zval *having;

	zephir_fetch_params(0, 1, 0, &having);



	zephir_update_property_this(this_ptr, SL("_having"), having TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return the current having clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving) {


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
 * @param int limit
 * @param int offset
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit) {

	zval *limit_param = NULL, *offset_param = NULL, *_0;
	int limit, offset;

	zephir_fetch_params(0, 1, 1, &limit_param, &offset_param);

		limit = zephir_get_intval(limit_param);
	if (!offset_param || Z_TYPE_P(offset_param) == IS_NULL) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limit);
	zephir_update_property_zval(this_ptr, SL("_limit"), _0 TSRMLS_CC);
	if ((offset >= 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, offset);
		zephir_update_property_zval(this_ptr, SL("_offset"), _0 TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns the current LIMIT clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit) {


	RETURN_MEMBER(this_ptr, "_limit");

}

/**
 * Sets an OFFSET clause
 *
 *<code>
 *	$builder->offset(30);
 *</code>
 *
 * @param int limit
 * @param int offset
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, offset) {

	zval *offset;

	zephir_fetch_params(0, 1, 0, &offset);



	zephir_update_property_this(this_ptr, SL("_offset"), offset TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current OFFSET clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOffset) {


	RETURN_MEMBER(this_ptr, "_offset");

}

/**
 * Sets a GROUP BY clause
 *
 *<code>
 *	$builder->groupBy(array('Robots.name'));
 *</code>
 *
 * @param string group
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, groupBy) {

	zval *group;

	zephir_fetch_params(0, 1, 0, &group);



	zephir_update_property_this(this_ptr, SL("_group"), group TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the GROUP BY clause
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy) {


	RETURN_MEMBER(this_ptr, "_group");

}

/**
 * Returns a PHQL statement built based on the builder parameters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql) {

	HashTable *_4, *_7, *_11, *_15, *_19, *_22;
	HashPosition _3, _6, _10, _14, _18, _21;
	zend_class_entry *_1;
	zend_bool noPrimary;
	zval *dependencyInjector, *models, *conditions, *model = NULL, *metaData, *modelInstance, *primaryKeys, *firstPrimaryKey, *columnMap, *modelAlias = NULL, *attributeField = NULL, *phql, *column = NULL, *columns, *selectedColumns = NULL, *selectedColumn = NULL, *selectedModel = NULL, *selectedModels, *columnAlias = NULL, *modelColumnAlias = NULL, *joins, *join = NULL, *joinModel, *joinConditions, *joinAlias, *joinType, *group, *groupItems, *groupItem = NULL, *having, *order, *orderItems, *orderItem = NULL, *limit, *number, *offset = NULL, *_0 = NULL, *_2 = NULL, **_5, **_8, *_9 = NULL, **_12, *_13 = NULL, **_16, *_17 = NULL, **_20, **_23;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(dependencyInjector);
		zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	models = zephir_fetch_nproperty_this(this_ptr, SL("_models"), PH_NOISY_CC);
	if ((Z_TYPE_P(models) == IS_ARRAY)) {
		if (!(zephir_fast_count_int(models TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
			return;
		}
	} else {
		if (!(zephir_is_true(models))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
			return;
		}
	}
	ZEPHIR_OBS_VAR(conditions);
	zephir_read_property_this(&conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_numeric(conditions)) {
		if ((Z_TYPE_P(models) == IS_ARRAY)) {
			if ((zephir_fast_count_int(models TSRMLS_CC) > 1)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot build the query. Invalid condition");
				return;
			}
			ZEPHIR_OBS_VAR(model);
			zephir_array_fetch_long(&model, models, 0, PH_NOISY TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(model, models);
		}
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "modelsMetadata", 1);
		ZEPHIR_INIT_VAR(metaData);
		zephir_call_method_p1(metaData, dependencyInjector, "getshared", _0);
		ZEPHIR_INIT_VAR(modelInstance);
		_1 = zend_fetch_class(Z_STRVAL_P(model), Z_STRLEN_P(model), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(modelInstance, _1);
		noPrimary = 1;
		ZEPHIR_INIT_VAR(primaryKeys);
		zephir_call_method_p1(primaryKeys, metaData, "getprimarykeyattributes", modelInstance);
		if (zephir_fast_count_int(primaryKeys TSRMLS_CC)) {
			if (zephir_array_isset_long_fetch(&firstPrimaryKey, primaryKeys, 0, 1 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(columnMap);
				if (ZEPHIR_GLOBAL(orm).column_renaming) {
					zephir_call_method_p1(columnMap, metaData, "getcolumnmap", modelInstance);
				} else {
					ZVAL_NULL(columnMap);
				}
				if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
					ZEPHIR_OBS_VAR(attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, columnMap, firstPrimaryKey, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_0);
						object_init_ex(_0, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(_2);
						ZEPHIR_CONCAT_SVS(_2, "Column '", firstPrimaryKey, "' isn't part of the column map");
						zephir_call_method_p1_noret(_0, "__construct", _2);
						zephir_throw_exception(_0 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(attributeField, firstPrimaryKey);
				}
				ZEPHIR_INIT_BNVAR(conditions);
				ZEPHIR_CONCAT_SVSVSV(conditions, "[", model, "].[", attributeField, "] = ", conditions);
				noPrimary = 0;
			}
		}
		if ((noPrimary == 1)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined");
			return;
		}
	}
	ZEPHIR_INIT_VAR(phql);
	ZVAL_STRING(phql, "SELECT ", 1);
	columns = zephir_fetch_nproperty_this(this_ptr, SL("_columns"), PH_NOISY_CC);
	if ((Z_TYPE_P(columns) != IS_NULL)) {
		if ((Z_TYPE_P(columns) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(selectedColumns);
			array_init(selectedColumns);
			zephir_is_iterable(columns, &_4, &_3, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
				; zend_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HMKEY(columnAlias, _4, _3);
				ZEPHIR_GET_HVALUE(column, _5);
				if ((Z_TYPE_P(columnAlias) == IS_LONG)) {
					zephir_array_append(&selectedColumns, column, PH_SEPARATE);
				} else {
					ZEPHIR_INIT_LNVAR(_2);
					ZEPHIR_CONCAT_VSV(_2, column, " AS ", columnAlias);
					zephir_array_append(&selectedColumns, _2, PH_SEPARATE);
				}
			}
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_join_str(_0, SL(", "), selectedColumns TSRMLS_CC);
			zephir_concat_self(&phql, _0 TSRMLS_CC);
		} else {
			zephir_concat_self(&phql, columns TSRMLS_CC);
		}
	} else {
		if ((Z_TYPE_P(models) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(selectedColumns);
			array_init(selectedColumns);
			zephir_is_iterable(models, &_7, &_6, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
				; zend_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HMKEY(modelColumnAlias, _7, _6);
				ZEPHIR_GET_HVALUE(model, _8);
				ZEPHIR_INIT_NVAR(selectedColumn);
				if ((Z_TYPE_P(modelColumnAlias) == IS_LONG)) {
					ZEPHIR_CONCAT_SVS(selectedColumn, "[", model, "].*");
				} else {
					ZEPHIR_CONCAT_SVS(selectedColumn, "[", modelColumnAlias, "].*");
				}
				zephir_array_append(&selectedColumns, selectedColumn, PH_SEPARATE);
			}
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_join_str(_0, SL(", "), selectedColumns TSRMLS_CC);
			zephir_concat_self(&phql, _0 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_9);
			ZEPHIR_CONCAT_SVS(_9, "[", models, "].*");
			zephir_concat_self(&phql, _9 TSRMLS_CC);
		}
	}
	if ((Z_TYPE_P(models) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(selectedModels);
		array_init(selectedModels);
		zephir_is_iterable(models, &_11, &_10, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
			; zend_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HMKEY(modelAlias, _11, _10);
			ZEPHIR_GET_HVALUE(model, _12);
			ZEPHIR_INIT_NVAR(selectedModel);
			if ((Z_TYPE_P(modelAlias) == IS_STRING)) {
				ZEPHIR_CONCAT_SVSVS(selectedModel, "[", model, "] AS [", modelAlias, "]");
			} else {
				ZEPHIR_CONCAT_SVS(selectedModel, "[", model, "]");
			}
			zephir_array_append(&selectedModels, selectedModel, PH_SEPARATE);
		}
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_join_str(_0, SL(", "), selectedModels TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_SV(_9, " FROM ", _0);
		zephir_concat_self(&phql, _9 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_13);
		ZEPHIR_CONCAT_SVS(_13, " FROM [", models, "]");
		zephir_concat_self(&phql, _13 TSRMLS_CC);
	}
	joins = zephir_fetch_nproperty_this(this_ptr, SL("_joins"), PH_NOISY_CC);
	if ((Z_TYPE_P(joins) == IS_ARRAY)) {
		zephir_is_iterable(joins, &_15, &_14, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
			; zend_hash_move_forward_ex(_15, &_14)
		) {
			ZEPHIR_GET_HVALUE(join, _16);
			zephir_array_fetch_long(&joinModel, join, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_long(&joinConditions, join, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_long(&joinAlias, join, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_long(&joinType, join, 3, PH_NOISY | PH_READONLY TSRMLS_CC);
			if (zephir_is_true(joinType)) {
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_SVSVS(_13, " ", joinType, " JOIN [", joinModel, "]");
				zephir_concat_self(&phql, _13 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_17);
				ZEPHIR_CONCAT_SVS(_17, " JOIN [", joinModel, "]");
				zephir_concat_self(&phql, _17 TSRMLS_CC);
			}
			if (zephir_is_true(joinAlias)) {
				ZEPHIR_INIT_LNVAR(_17);
				ZEPHIR_CONCAT_SVS(_17, " AS [", joinAlias, "]");
				zephir_concat_self(&phql, _17 TSRMLS_CC);
			}
			if (zephir_is_true(joinConditions)) {
				ZEPHIR_INIT_LNVAR(_17);
				ZEPHIR_CONCAT_SV(_17, " ON ", joinConditions);
				zephir_concat_self(&phql, _17 TSRMLS_CC);
			}
		}
	}
	if ((Z_TYPE_P(conditions) == IS_STRING)) {
		if (!((0 == 0))) {
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SV(_9, " WHERE ", conditions);
			zephir_concat_self(&phql, _9 TSRMLS_CC);
		}
	}
	group = zephir_fetch_nproperty_this(this_ptr, SL("_group"), PH_NOISY_CC);
	if ((Z_TYPE_P(group) != IS_NULL)) {
		if ((Z_TYPE_P(group) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(groupItems);
			array_init(groupItems);
			zephir_is_iterable(group, &_19, &_18, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_19, (void**) &_20, &_18) == SUCCESS
				; zend_hash_move_forward_ex(_19, &_18)
			) {
				ZEPHIR_GET_HVALUE(groupItem, _20);
				if (zephir_is_numeric(groupItem)) {
					zephir_array_append(&groupItems, groupItem, PH_SEPARATE);
				} else {
					if (zephir_memnstr_str(groupItem, SL("."), "phalcon/mvc/model/query/builder.zep", 1131)) {
						zephir_array_append(&groupItems, groupItem, PH_SEPARATE);
					} else {
						ZEPHIR_INIT_LNVAR(_2);
						ZEPHIR_CONCAT_SVS(_2, "[", groupItem, "]");
						zephir_array_append(&groupItems, _2, PH_SEPARATE);
					}
				}
			}
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_join_str(_0, SL(", "), groupItems TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SV(_2, " GROUP BY ", _0);
			zephir_concat_self(&phql, _2 TSRMLS_CC);
		} else {
			if (zephir_is_numeric(group)) {
				ZEPHIR_INIT_LNVAR(_9);
				ZEPHIR_CONCAT_SV(_9, " GROUP BY ", group);
				zephir_concat_self(&phql, _9 TSRMLS_CC);
			} else {
				if (zephir_memnstr_str(group, SL("."), "phalcon/mvc/model/query/builder.zep", 1143)) {
					ZEPHIR_INIT_LNVAR(_13);
					ZEPHIR_CONCAT_SV(_13, " GROUP BY ", group);
					zephir_concat_self(&phql, _13 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_17);
					ZEPHIR_CONCAT_SVS(_17, " GROUP BY [", group, "]");
					zephir_concat_self(&phql, _17 TSRMLS_CC);
				}
			}
		}
		having = zephir_fetch_nproperty_this(this_ptr, SL("_having"), PH_NOISY_CC);
		if ((Z_TYPE_P(having) != IS_NULL)) {
			if (!((0 == 0))) {
				ZEPHIR_INIT_LNVAR(_9);
				ZEPHIR_CONCAT_SV(_9, " HAVING ", having);
				zephir_concat_self(&phql, _9 TSRMLS_CC);
			}
		}
	}
	order = zephir_fetch_nproperty_this(this_ptr, SL("_order"), PH_NOISY_CC);
	if ((Z_TYPE_P(order) != IS_NULL)) {
		if ((Z_TYPE_P(order) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(orderItems);
			array_init(orderItems);
			zephir_is_iterable(order, &_22, &_21, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_22, (void**) &_23, &_21) == SUCCESS
				; zend_hash_move_forward_ex(_22, &_21)
			) {
				ZEPHIR_GET_HVALUE(orderItem, _23);
				if (zephir_is_numeric(orderItem)) {
					zephir_array_append(&orderItems, orderItem, PH_SEPARATE);
				} else {
					if (zephir_memnstr_str(orderItem, SL("."), "phalcon/mvc/model/query/builder.zep", 1170)) {
						zephir_array_append(&orderItems, orderItem, PH_SEPARATE);
					} else {
						ZEPHIR_INIT_LNVAR(_2);
						ZEPHIR_CONCAT_SVS(_2, "[", orderItem, "]");
						zephir_array_append(&orderItems, _2, PH_SEPARATE);
					}
				}
			}
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_join_str(_0, SL(", "), orderItems TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SV(_2, " ORDER BY ", _0);
			zephir_concat_self(&phql, _2 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SV(_9, " ORDER BY ", order);
			zephir_concat_self(&phql, _9 TSRMLS_CC);
		}
	}
	limit = zephir_fetch_nproperty_this(this_ptr, SL("_limit"), PH_NOISY_CC);
	if ((Z_TYPE_P(limit) != IS_NULL)) {
		if ((Z_TYPE_P(limit) == IS_ARRAY)) {
			zephir_array_fetch_string(&number, limit, SL("number"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_OBS_VAR(offset);
			if (zephir_array_isset_string_fetch(&offset, limit, SS("offset"), 0 TSRMLS_CC)) {
				if (zephir_is_numeric(offset)) {
					ZEPHIR_INIT_LNVAR(_9);
					ZEPHIR_CONCAT_SVSV(_9, " LIMIT ", number, " OFFSET ", offset);
					zephir_concat_self(&phql, _9 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_13);
					ZEPHIR_CONCAT_SVS(_13, " LIMIT ", number, " OFFSET 0");
					zephir_concat_self(&phql, _13 TSRMLS_CC);
				}
			} else {
				ZEPHIR_INIT_LNVAR(_17);
				ZEPHIR_CONCAT_SV(_17, " LIMIT ", number);
				zephir_concat_self(&phql, _17 TSRMLS_CC);
			}
		} else {
			if (zephir_is_numeric(limit)) {
				ZEPHIR_INIT_LNVAR(_9);
				ZEPHIR_CONCAT_SV(_9, " LIMIT ", limit);
				zephir_concat_self(&phql, _9 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(offset);
				zephir_read_property_this(&offset, this_ptr, SL("_offset"), PH_NOISY_CC);
				if ((Z_TYPE_P(offset) != IS_NULL)) {
					if (zephir_is_numeric(offset)) {
						ZEPHIR_INIT_LNVAR(_17);
						ZEPHIR_CONCAT_SV(_17, " OFFSET ", offset);
						zephir_concat_self(&phql, _17 TSRMLS_CC);
					} else {
						zephir_concat_self_str(&phql, SL(" OFFSET 0") TSRMLS_CC);
					}
				}
			}
		}
	}
	RETURN_CCTOR(phql);

}

/**
 * Returns the query built
 *
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery) {

	zval *query, *bindParams, *bindTypes;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	bindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if ((Z_TYPE_P(bindParams) == IS_ARRAY)) {
		zephir_call_method_p1_noret(query, "setbindparams", bindParams);
	}
	bindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	if ((Z_TYPE_P(bindTypes) == IS_ARRAY)) {
		zephir_call_method_p1_noret(query, "setbindtypes", bindTypes);
	}
	RETURN_CCTOR(query);

}

