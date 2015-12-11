
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
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


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
 *$queryBuilder = new \Phalcon\Mvc\Model\Query\Builder($params);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Builder, phalcon, mvc_model_query_builder, phalcon_mvc_model_query_builder_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_joins"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_with"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_distinct"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_query_builder_ce, SL("_hiddenParamNumber"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_query_builder_ce TSRMLS_CC, 1, phalcon_mvc_model_query_builderinterface_ce);
	zend_class_implements(phalcon_mvc_model_query_builder_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Query\Builder constructor
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct) {

	zend_bool _5;
	HashTable *_1;
	HashPosition _0;
	zval *params = NULL, *dependencyInjector = NULL, *conditions = NULL, *columns, *groupClause, *havingClause, *limitClause, *forUpdate, *sharedLock, *orderClause, *offsetClause, *joinsClause, *singleConditionArray = NULL, *limit, *offset, *fromClause, *mergedConditions, *mergedParams = NULL, *mergedTypes = NULL, *singleCondition = NULL, *singleParams = NULL, *singleTypes = NULL, *with, *distinct, *bind, *bindTypes, **_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &params, &dependencyInjector);

	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}
	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(conditions);
		if (zephir_array_isset_long_fetch(&conditions, params, 0, 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(conditions);
			if (zephir_array_isset_string_fetch(&conditions, params, SS("conditions"), 0 TSRMLS_CC)) {
				zephir_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
			}
		}
		if (Z_TYPE_P(conditions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedConditions);
			array_init(mergedConditions);
			ZEPHIR_INIT_VAR(mergedParams);
			array_init(mergedParams);
			ZEPHIR_INIT_VAR(mergedTypes);
			array_init(mergedTypes);
			zephir_is_iterable(conditions, &_1, &_0, 0, 0, "phalcon/mvc/model/query/builder.zep", 146);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HVALUE(singleConditionArray, _2);
				if (Z_TYPE_P(singleConditionArray) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(singleCondition);
					zephir_array_isset_long_fetch(&singleCondition, singleConditionArray, 0, 0 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(singleParams);
					zephir_array_isset_long_fetch(&singleParams, singleConditionArray, 1, 0 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(singleTypes);
					zephir_array_isset_long_fetch(&singleTypes, singleConditionArray, 2, 0 TSRMLS_CC);
					if (Z_TYPE_P(singleCondition) == IS_STRING) {
						zephir_array_append(&mergedConditions, singleCondition, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 133);
					}
					if (Z_TYPE_P(singleParams) == IS_ARRAY) {
						ZEPHIR_INIT_LNVAR(_3);
						zephir_add_function(_3, mergedParams, singleParams);
						ZEPHIR_CPY_WRT(mergedParams, _3);
					}
					if (Z_TYPE_P(singleTypes) == IS_ARRAY) {
						ZEPHIR_INIT_LNVAR(_3);
						zephir_add_function(_3, mergedTypes, singleTypes);
						ZEPHIR_CPY_WRT(mergedTypes, _3);
					}
				}
			}
			ZEPHIR_INIT_VAR(_4);
			zephir_fast_join_str(_4, SL(" AND "), mergedConditions TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_conditions"), _4 TSRMLS_CC);
			if (Z_TYPE_P(mergedParams) == IS_ARRAY) {
				zephir_update_property_this(this_ptr, SL("_bindParams"), mergedParams TSRMLS_CC);
			}
			if (Z_TYPE_P(mergedTypes) == IS_ARRAY) {
				zephir_update_property_this(this_ptr, SL("_bindTypes"), mergedTypes TSRMLS_CC);
			}
		}
		ZEPHIR_OBS_VAR(bind);
		if (zephir_array_isset_string_fetch(&bind, params, SS("bind"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_bindParams"), bind TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SS("bindTypes"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_bindTypes"), bindTypes TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(distinct);
		if (zephir_array_isset_string_fetch(&distinct, params, SS("distinct"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_distinct"), distinct TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(fromClause);
		if (zephir_array_isset_string_fetch(&fromClause, params, SS("models"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_models"), fromClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(columns);
		if (zephir_array_isset_string_fetch(&columns, params, SS("columns"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(joinsClause);
		if (zephir_array_isset_string_fetch(&joinsClause, params, SS("joins"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_joins"), joinsClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(with);
		if (zephir_array_isset_string_fetch(&with, params, SS("with"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_with"), with TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(groupClause);
		if (zephir_array_isset_string_fetch(&groupClause, params, SS("group"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_group"), groupClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(havingClause);
		if (zephir_array_isset_string_fetch(&havingClause, params, SS("having"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_having"), havingClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(orderClause);
		if (zephir_array_isset_string_fetch(&orderClause, params, SS("order"), 0 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_order"), orderClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(limitClause);
		if (zephir_array_isset_string_fetch(&limitClause, params, SS("limit"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(limitClause) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(limit);
				if (zephir_array_isset_long_fetch(&limit, limitClause, 0, 0 TSRMLS_CC)) {
					if (Z_TYPE_P(limit) == IS_LONG) {
						zephir_update_property_this(this_ptr, SL("_limit"), limit TSRMLS_CC);
					}
					ZEPHIR_OBS_VAR(offset);
					if (zephir_array_isset_long_fetch(&offset, limitClause, 1, 0 TSRMLS_CC)) {
						if (Z_TYPE_P(offset) == IS_LONG) {
							zephir_update_property_this(this_ptr, SL("_offset"), offset TSRMLS_CC);
						}
					}
				} else {
					zephir_update_property_this(this_ptr, SL("_limit"), limitClause TSRMLS_CC);
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
	} else {
		_5 = Z_TYPE_P(params) == IS_STRING;
		if (_5) {
			_5 = !ZEPHIR_IS_STRING_IDENTICAL(params, "");
		}
		if (_5) {
			zephir_update_property_this(this_ptr, SL("_conditions"), params TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 *
 *<code>
 *	$builder->distinct("status");
 *	$builder->distinct(null);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, distinct) {

	zval *distinct;

	zephir_fetch_params(0, 1, 0, &distinct);



	zephir_update_property_this(this_ptr, SL("_distinct"), distinct TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns SELECT DISTINCT / SELECT ALL flag
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDistinct) {


	RETURN_MEMBER(this_ptr, "_distinct");

}

/**
 * Sets the columns to be queried
 *
 *<code>
 *	$builder->columns("id, name");
 *	$builder->columns(array('id', 'name'));
 *  $builder->columns(array('name', 'number' => 'COUNT(*)'));
 *</code>
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
 *	$builder->from(array('r' => 'Robots', 'rp' => 'RobotsParts'));
 *</code>
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
 *  // Load data from models Robots
 *	$builder->addFrom('Robots');
 *
 *  // Load data from model 'Robots' using 'r' as alias in PHQL
 *	$builder->addFrom('Robots', 'r');
 *
 *  // Load data from model 'Robots' using 'r' as alias in PHQL
 *  // and eager load model 'RobotsParts'
 *	$builder->addFrom('Robots', 'r', 'RobotsParts');
 *
 *  // Load data from model 'Robots' using 'r' as alias in PHQL
 *  // and eager load models 'RobotsParts' and 'Parts'
 *	$builder->addFrom('Robots', 'r', ['RobotsParts', 'Parts']);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, addFrom) {

	zval *model, *alias = NULL, *with = NULL, *models = NULL, *currentModel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model, &alias, &with);

	if (!alias) {
		alias = ZEPHIR_GLOBAL(global_null);
	}
	if (!with) {
		with = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(models);
	zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if (Z_TYPE_P(models) != IS_ARRAY) {
		if (Z_TYPE_P(models) != IS_NULL) {
			ZEPHIR_CPY_WRT(currentModel, models);
			ZEPHIR_INIT_NVAR(models);
			zephir_create_array(models, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(models, currentModel);
		} else {
			ZEPHIR_INIT_NVAR(models);
			array_init(models);
		}
	}
	if (Z_TYPE_P(alias) == IS_STRING) {
		zephir_array_update_zval(&models, alias, &model, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_append(&models, model, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 395);
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
 *  // Inner Join model 'Robots' with automatic conditions and alias
 *	$builder->join('Robots');
 *
 *  // Inner Join model 'Robots' specifing conditions
 *	$builder->join('Robots', 'Robots.id = RobotsParts.robots_id');
 *
 *  // Inner Join model 'Robots' specifing conditions and alias
 *	$builder->join('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *
 *  // Left Join model 'Robots' specifing conditions, alias and type of join
 *	$builder->join('Robots', 'r.id = RobotsParts.robots_id', 'r', 'LEFT');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @param string type
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, join) {

	zval *_0;
	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *type = NULL;
	zval *model = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model_param, &conditions, &alias, &type);

	if (unlikely(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(model, model_param);
	} else {
		ZEPHIR_INIT_VAR(model);
		ZVAL_EMPTY_STRING(model);
	}
	if (!conditions) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!alias) {
		alias = ZEPHIR_GLOBAL(global_null);
	}
	if (!type) {
		type = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
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
 *  // Inner Join model 'Robots' with automatic conditions and alias
 *	$builder->innerJoin('Robots');
 *
 *  // Inner Join model 'Robots' specifing conditions
 *	$builder->innerJoin('Robots', 'Robots.id = RobotsParts.robots_id');
 *
 *  // Inner Join model 'Robots' specifing conditions and alias
 *	$builder->innerJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @param string type
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, innerJoin) {

	zval *_0;
	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *_1;
	zval *model = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);

	if (unlikely(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(model, model_param);
	} else {
		ZEPHIR_INIT_VAR(model);
		ZVAL_EMPTY_STRING(model);
	}
	if (!conditions) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!alias) {
		alias = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
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
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, leftJoin) {

	zval *_0;
	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *_1;
	zval *model = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);

	if (unlikely(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(model, model_param);
	} else {
		ZEPHIR_INIT_VAR(model);
		ZVAL_EMPTY_STRING(model);
	}
	if (!conditions) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!alias) {
		alias = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
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
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, rightJoin) {

	zval *_0;
	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *_1;
	zval *model = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);

	if (unlikely(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(model, model_param);
	} else {
		ZEPHIR_INIT_VAR(model);
		ZVAL_EMPTY_STRING(model);
	}
	if (!conditions) {
		conditions = ZEPHIR_GLOBAL(global_null);
	}
	if (!alias) {
		alias = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, model);
	zephir_array_fast_append(_0, conditions);
	zephir_array_fast_append(_0, alias);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "RIGHT", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_array_append(this_ptr, SL("_joins"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the query conditions
 *
 *<code>
 *	$builder->where(100);
 *	$builder->where('name = "Peter"');
 *	$builder->where('name = :name: AND id > :id:', array('name' => 'Peter', 'id' => 100));
 *</code>
 *
 * @param mixed conditions
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where) {

	zval *conditions, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *currentBindTypes, *mergedParams = NULL, *mergedTypes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_add_function(mergedParams, currentBindParams, bindParams);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		zephir_update_property_this(this_ptr, SL("_bindParams"), mergedParams TSRMLS_CC);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_add_function(mergedTypes, currentBindTypes, bindTypes);
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
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andWhere) {

	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *currentBindTypes, *mergedParams = NULL, *mergedTypes = NULL, *currentConditions, *newConditions = NULL;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

	if (unlikely(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(conditions);
		ZVAL_EMPTY_STRING(conditions);
	}
	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
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
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_add_function(mergedParams, currentBindParams, bindParams);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		zephir_update_property_this(this_ptr, SL("_bindParams"), mergedParams TSRMLS_CC);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_add_function(mergedTypes, currentBindTypes, bindTypes);
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
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orWhere) {

	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *currentBindTypes, *mergedParams = NULL, *mergedTypes = NULL, *currentConditions, *_0;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

	if (unlikely(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(conditions);
		ZVAL_EMPTY_STRING(conditions);
	}
	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	currentConditions = zephir_fetch_nproperty_this(this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_true(currentConditions)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "(", currentConditions, ") OR (", conditions, ")");
		zephir_update_property_this(this_ptr, SL("_conditions"), _0 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
	}
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_add_function(mergedParams, currentBindParams, bindParams);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		zephir_update_property_this(this_ptr, SL("_bindParams"), mergedParams TSRMLS_CC);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedTypes);
			zephir_add_function(mergedTypes, currentBindTypes, bindTypes);
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *expr_param = NULL, *minimum, *maximum, *hiddenParam, *nextHiddenParam, *minimumKey, *maximumKey, *_0;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

	if (unlikely(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}


	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(nextHiddenParam);
	ZVAL_LONG(nextHiddenParam, (zephir_get_numberval(hiddenParam) + 1));
	ZEPHIR_INIT_VAR(minimumKey);
	ZEPHIR_CONCAT_SV(minimumKey, "AP", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "AP", nextHiddenParam);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVSVS(_0, expr, " BETWEEN :", minimumKey, ": AND :", maximumKey, ":");
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	zephir_array_update_zval(&_1, minimumKey, &minimum, PH_COPY);
	zephir_array_update_zval(&_1, maximumKey, &maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, _0, _1);
	zephir_check_call_status();
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *expr_param = NULL, *minimum, *maximum, *hiddenParam, *nextHiddenParam, *minimumKey, *maximumKey, *_0;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

	if (unlikely(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}


	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(nextHiddenParam);
	ZVAL_LONG(nextHiddenParam, (zephir_get_numberval(hiddenParam) + 1));
	ZEPHIR_INIT_VAR(minimumKey);
	ZEPHIR_CONCAT_SV(minimumKey, "AP", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "AP", nextHiddenParam);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVSVS(_0, expr, " NOT BETWEEN :", minimumKey, ": AND :", maximumKey, ":");
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	zephir_array_update_zval(&_1, minimumKey, &minimum, PH_COPY);
	zephir_array_update_zval(&_1, maximumKey, &maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, _0, _1);
	zephir_check_call_status();
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inWhere) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_1 = NULL;
	int hiddenParam, ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *key = NULL, *queryKey = NULL, *value = NULL, *bindKeys, *bindParams, *_2, **_5, _6 = zval_used_for_init, *_7, *_8, *_9;
	zval *expr = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values_param);

	if (unlikely(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	values = values_param;


	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, expr, " != ", expr);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", &_1, 0, _0);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(_2);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_4, &_3, 0, 0, "phalcon/mvc/model/query/builder.zep", 776);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(value, _5);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, hiddenParam);
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "AP", &_6);
		ZEPHIR_CPY_WRT(key, _0);
		ZEPHIR_INIT_NVAR(queryKey);
		ZEPHIR_CONCAT_SVS(queryKey, ":", key, ":");
		zephir_array_append(&bindKeys, queryKey, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 767);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		hiddenParam++;
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_fast_join_str(_7, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VSVS(_8, expr, " IN (", _7, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", &_1, 0, _8, bindParams);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_9);
	ZVAL_LONG(_9, hiddenParam);
	zephir_update_property_this(this_ptr, SL("_hiddenParamNumber"), _9 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a NOT IN condition to the current conditions
 *
 *<code>
 *	$builder->notInWhere('id', [1, 2, 3]);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInWhere) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_1 = NULL;
	int hiddenParam, ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *key = NULL, *queryKey = NULL, *value = NULL, *bindKeys, *bindParams, *_2, **_5, _6 = zval_used_for_init, *_7, *_8, *_9;
	zval *expr = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values_param);

	if (unlikely(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	values = values_param;


	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, expr, " != ", expr);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", &_1, 0, _0);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(_2);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_4, &_3, 0, 0, "phalcon/mvc/model/query/builder.zep", 819);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(value, _5);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, hiddenParam);
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "AP", &_6);
		ZEPHIR_CPY_WRT(key, _0);
		ZEPHIR_INIT_NVAR(queryKey);
		ZEPHIR_CONCAT_SVS(queryKey, ":", key, ":");
		zephir_array_append(&bindKeys, queryKey, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 810);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		hiddenParam++;
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_fast_join_str(_7, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VSVS(_8, expr, " NOT IN (", _7, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", &_1, 0, _8, bindParams);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_9);
	ZVAL_LONG(_9, hiddenParam);
	zephir_update_property_this(this_ptr, SL("_hiddenParamNumber"), _9 TSRMLS_CC);
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
 * @param string|array orderBy
 * @return \Phalcon\Mvc\Model\Query\Builder
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, having) {

	zval *having_param = NULL;
	zval *having = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &having_param);

	if (unlikely(Z_TYPE_P(having_param) != IS_STRING && Z_TYPE_P(having_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'having' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(having_param) == IS_STRING)) {
		zephir_get_strval(having, having_param);
	} else {
		ZEPHIR_INIT_VAR(having);
		ZVAL_EMPTY_STRING(having);
	}


	zephir_update_property_this(this_ptr, SL("_having"), having TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets a FOR UPDATE clause
 *
 *<code>
 *	$builder->forUpdate(true);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, forUpdate) {

	zval *forUpdate_param = NULL;
	zend_bool forUpdate;

	zephir_fetch_params(0, 1, 0, &forUpdate_param);

	forUpdate = zephir_get_boolval(forUpdate_param);


	if (forUpdate) {
		zephir_update_property_this(this_ptr, SL("_forUpdate"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_forUpdate"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit) {

	zval *limit_param = NULL, *offset_param = NULL, *_0;
	int limit, offset;

	zephir_fetch_params(0, 0, 2, &limit_param, &offset_param);

	if (!limit_param) {
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limit);
	zephir_update_property_this(this_ptr, SL("_limit"), _0 TSRMLS_CC);
	if (offset) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, offset);
		zephir_update_property_this(this_ptr, SL("_offset"), _0 TSRMLS_CC);
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, offset) {

	zval *offset_param = NULL, *_0;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, offset);
	zephir_update_property_this(this_ptr, SL("_offset"), _0 TSRMLS_CC);
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
 * @param string|array group
 * @return \Phalcon\Mvc\Model\Query\Builder
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

	HashTable *_7, *_10, *_13, *_18, *_23, *_29;
	HashPosition _6, _9, _12, _17, _22, _28;
	zend_class_entry *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_32 = NULL;
	zend_bool noPrimary, _5;
	zval *dependencyInjector = NULL, *models, *conditions = NULL, *model = NULL, *metaData = NULL, *modelInstance, *primaryKeys = NULL, *firstPrimaryKey, *columnMap = NULL, *modelAlias = NULL, *attributeField = NULL, *phql = NULL, *column = NULL, *columns, *selectedColumns = NULL, *selectedColumn = NULL, *selectedModel = NULL, *selectedModels, *columnAlias = NULL, *modelColumnAlias = NULL, *joins, *join = NULL, *joinModel = NULL, *joinConditions = NULL, *joinAlias = NULL, *joinType = NULL, *group = NULL, *groupItems = NULL, *groupItem = NULL, *having, *order, *orderItems, *orderItem = NULL, *limit, *number = NULL, *offset = NULL, *forUpdate, *distinct, *_1 = NULL, *_2 = NULL, *_4 = NULL, **_8, **_11, **_14, *_15 = NULL, *_16 = NULL, **_19, *_20 = NULL, *_21 = NULL, **_24, *_25 = NULL, _26 = zval_used_for_init, _27, **_30, *_31 = NULL, *_33, *_34, *_35, *_36;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(models);
	zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if (Z_TYPE_P(models) == IS_ARRAY) {
		if (!(zephir_fast_count_int(models TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query", "phalcon/mvc/model/query/builder.zep", 1000);
			return;
		}
	} else {
		if (!(zephir_is_true(models))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query", "phalcon/mvc/model/query/builder.zep", 1004);
			return;
		}
	}
	ZEPHIR_OBS_VAR(conditions);
	zephir_read_property_this(&conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_numeric(conditions)) {
		if (Z_TYPE_P(models) == IS_ARRAY) {
			if (zephir_fast_count_int(models TSRMLS_CC) > 1) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot build the query. Invalid condition", "phalcon/mvc/model/query/builder.zep", 1017);
				return;
			}
			ZEPHIR_OBS_VAR(model);
			zephir_array_fetch_long(&model, models, 0, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1019 TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(model, models);
		}
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(modelInstance);
		zephir_fetch_safe_class(_2, model);
			_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(modelInstance, _3);
		if (zephir_has_constructor(modelInstance TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, modelInstance, "__construct", NULL, 0, dependencyInjector);
			zephir_check_call_status();
		}
		noPrimary = 1;
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, modelInstance);
		zephir_check_call_status();
		if (zephir_fast_count_int(primaryKeys TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(firstPrimaryKey);
			if (zephir_array_isset_long_fetch(&firstPrimaryKey, primaryKeys, 0, 0 TSRMLS_CC)) {
				if (ZEPHIR_GLOBAL(orm).column_renaming) {
					ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, modelInstance);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(columnMap);
					ZVAL_NULL(columnMap);
				}
				if (Z_TYPE_P(columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_VAR(attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, columnMap, firstPrimaryKey, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_1);
						object_init_ex(_1, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(_4);
						ZEPHIR_CONCAT_SVS(_4, "Column '", firstPrimaryKey, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 9, _4);
						zephir_check_call_status();
						zephir_throw_exception_debug(_1, "phalcon/mvc/model/query/builder.zep", 1047 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(attributeField, firstPrimaryKey);
				}
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVSVSV(_4, "[", model, "].[", attributeField, "] = ", conditions);
				ZEPHIR_CPY_WRT(conditions, _4);
				noPrimary = 0;
			}
		}
		if (noPrimary == 1) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined", "phalcon/mvc/model/query/builder.zep", 1062);
			return;
		}
	}
	ZEPHIR_OBS_VAR(distinct);
	zephir_read_property_this(&distinct, this_ptr, SL("_distinct"), PH_NOISY_CC);
	_5 = Z_TYPE_P(distinct) != IS_NULL;
	if (_5) {
		_5 = Z_TYPE_P(distinct) == IS_BOOL;
	}
	if (_5) {
		ZEPHIR_INIT_VAR(phql);
		if (zephir_is_true(distinct)) {
			ZVAL_STRING(phql, "SELECT DISTINCT ", 1);
		} else {
			ZVAL_STRING(phql, "SELECT ALL ", 1);
		}
	} else {
		ZEPHIR_INIT_NVAR(phql);
		ZVAL_STRING(phql, "SELECT ", 1);
	}
	ZEPHIR_OBS_VAR(columns);
	zephir_read_property_this(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
	if (Z_TYPE_P(columns) != IS_NULL) {
		if (Z_TYPE_P(columns) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(selectedColumns);
			array_init(selectedColumns);
			zephir_is_iterable(columns, &_7, &_6, 0, 0, "phalcon/mvc/model/query/builder.zep", 1098);
			for (
			  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HMKEY(columnAlias, _7, _6);
				ZEPHIR_GET_HVALUE(column, _8);
				if (Z_TYPE_P(columnAlias) == IS_LONG) {
					zephir_array_append(&selectedColumns, column, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1088);
				} else {
					if (zephir_memnstr_str(columnAlias, SL("["), "phalcon/mvc/model/query/builder.zep", 1090)) {
						ZEPHIR_INIT_LNVAR(_4);
						ZEPHIR_CONCAT_VSV(_4, column, " AS ", columnAlias);
						zephir_array_append(&selectedColumns, _4, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1091);
					} else {
						ZEPHIR_INIT_LNVAR(_4);
						ZEPHIR_CONCAT_VSVS(_4, column, " AS [", columnAlias, "]");
						zephir_array_append(&selectedColumns, _4, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1093);
					}
				}
			}
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_join_str(_1, SL(", "), selectedColumns TSRMLS_CC);
			zephir_concat_self(&phql, _1 TSRMLS_CC);
		} else {
			zephir_concat_self(&phql, columns TSRMLS_CC);
		}
	} else {
		if (Z_TYPE_P(models) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(selectedColumns);
			array_init(selectedColumns);
			zephir_is_iterable(models, &_10, &_9, 0, 0, "phalcon/mvc/model/query/builder.zep", 1121);
			for (
			  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
			  ; zephir_hash_move_forward_ex(_10, &_9)
			) {
				ZEPHIR_GET_HMKEY(modelColumnAlias, _10, _9);
				ZEPHIR_GET_HVALUE(model, _11);
				ZEPHIR_INIT_NVAR(selectedColumn);
				if (Z_TYPE_P(modelColumnAlias) == IS_LONG) {
					ZEPHIR_CONCAT_SVS(selectedColumn, "[", model, "].*");
				} else {
					ZEPHIR_CONCAT_SVS(selectedColumn, "[", modelColumnAlias, "].*");
				}
				zephir_array_append(&selectedColumns, selectedColumn, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1118);
			}
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_join_str(_1, SL(", "), selectedColumns TSRMLS_CC);
			zephir_concat_self(&phql, _1 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVS(_4, "[", models, "].*");
			zephir_concat_self(&phql, _4 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(models) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(selectedModels);
		array_init(selectedModels);
		zephir_is_iterable(models, &_13, &_12, 0, 0, "phalcon/mvc/model/query/builder.zep", 1152);
		for (
		  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HMKEY(modelAlias, _13, _12);
			ZEPHIR_GET_HVALUE(model, _14);
			if (Z_TYPE_P(modelAlias) == IS_STRING) {
				ZEPHIR_INIT_NVAR(selectedModel);
				if (zephir_memnstr_str(model, SL("["), "phalcon/mvc/model/query/builder.zep", 1136)) {
					ZEPHIR_CONCAT_VSVS(selectedModel, model, " AS [", modelAlias, "]");
				} else {
					ZEPHIR_CONCAT_SVSVS(selectedModel, "[", model, "] AS [", modelAlias, "]");
				}
			} else {
				if (zephir_memnstr_str(model, SL("["), "phalcon/mvc/model/query/builder.zep", 1142)) {
					ZEPHIR_CPY_WRT(selectedModel, model);
				} else {
					ZEPHIR_INIT_NVAR(selectedModel);
					ZEPHIR_CONCAT_SVS(selectedModel, "[", model, "]");
				}
			}
			zephir_array_append(&selectedModels, selectedModel, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1149);
		}
		ZEPHIR_INIT_NVAR(_1);
		zephir_fast_join_str(_1, SL(", "), selectedModels TSRMLS_CC);
		ZEPHIR_INIT_VAR(_15);
		ZEPHIR_CONCAT_SV(_15, " FROM ", _1);
		zephir_concat_self(&phql, _15 TSRMLS_CC);
	} else {
		if (zephir_memnstr_str(models, SL("["), "phalcon/mvc/model/query/builder.zep", 1156)) {
			ZEPHIR_INIT_LNVAR(_15);
			ZEPHIR_CONCAT_SVS(_15, " FROM ", models, "");
			zephir_concat_self(&phql, _15 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_16);
			ZEPHIR_CONCAT_SVS(_16, " FROM [", models, "]");
			zephir_concat_self(&phql, _16 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(joins);
	zephir_read_property_this(&joins, this_ptr, SL("_joins"), PH_NOISY_CC);
	if (Z_TYPE_P(joins) == IS_ARRAY) {
		zephir_is_iterable(joins, &_18, &_17, 0, 0, "phalcon/mvc/model/query/builder.zep", 1222);
		for (
		  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
		  ; zephir_hash_move_forward_ex(_18, &_17)
		) {
			ZEPHIR_GET_HVALUE(join, _19);
			ZEPHIR_OBS_NVAR(joinModel);
			zephir_array_fetch_long(&joinModel, join, 0, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1174 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinConditions);
			zephir_array_fetch_long(&joinConditions, join, 1, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1179 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinAlias);
			zephir_array_fetch_long(&joinAlias, join, 2, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1184 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinType);
			zephir_array_fetch_long(&joinType, join, 3, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1189 TSRMLS_CC);
			if (zephir_is_true(joinType)) {
				if (zephir_memnstr_str(joinModel, SL("["), "phalcon/mvc/model/query/builder.zep", 1195)) {
					ZEPHIR_INIT_LNVAR(_15);
					ZEPHIR_CONCAT_SVSV(_15, " ", joinType, " JOIN ", joinModel);
					zephir_concat_self(&phql, _15 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_16);
					ZEPHIR_CONCAT_SVSVS(_16, " ", joinType, " JOIN [", joinModel, "]");
					zephir_concat_self(&phql, _16 TSRMLS_CC);
				}
			} else {
				if (zephir_memnstr_str(joinModel, SL("["), "phalcon/mvc/model/query/builder.zep", 1201)) {
					ZEPHIR_INIT_LNVAR(_20);
					ZEPHIR_CONCAT_SVS(_20, " JOIN ", joinModel, "");
					zephir_concat_self(&phql, _20 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_20);
					ZEPHIR_CONCAT_SVS(_20, " JOIN [", joinModel, "]");
					zephir_concat_self(&phql, _20 TSRMLS_CC);
				}
			}
			if (zephir_is_true(joinAlias)) {
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_SVS(_20, " AS [", joinAlias, "]");
				zephir_concat_self(&phql, _20 TSRMLS_CC);
			}
			if (zephir_is_true(joinConditions)) {
				ZEPHIR_INIT_LNVAR(_21);
				ZEPHIR_CONCAT_SV(_21, " ON ", joinConditions);
				zephir_concat_self(&phql, _21 TSRMLS_CC);
			}
		}
	}
	if (Z_TYPE_P(conditions) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(conditions))) {
			ZEPHIR_INIT_LNVAR(_15);
			ZEPHIR_CONCAT_SV(_15, " WHERE ", conditions);
			zephir_concat_self(&phql, _15 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(group);
	zephir_read_property_this(&group, this_ptr, SL("_group"), PH_NOISY_CC);
	if (Z_TYPE_P(group) != IS_NULL) {
		if (Z_TYPE_P(group) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(groupItems);
			array_init(groupItems);
			zephir_is_iterable(group, &_23, &_22, 0, 0, "phalcon/mvc/model/query/builder.zep", 1249);
			for (
			  ; zephir_hash_get_current_data_ex(_23, (void**) &_24, &_22) == SUCCESS
			  ; zephir_hash_move_forward_ex(_23, &_22)
			) {
				ZEPHIR_GET_HVALUE(groupItem, _24);
				if (zephir_is_numeric(groupItem)) {
					zephir_array_append(&groupItems, groupItem, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1240);
				} else {
					if (zephir_memnstr_str(groupItem, SL("."), "phalcon/mvc/model/query/builder.zep", 1242)) {
						zephir_array_append(&groupItems, groupItem, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1243);
					} else {
						ZEPHIR_INIT_LNVAR(_4);
						ZEPHIR_CONCAT_SVS(_4, "[", groupItem, "]");
						zephir_array_append(&groupItems, _4, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1245);
					}
				}
			}
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_join_str(_1, SL(", "), groupItems TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, " GROUP BY ", _1);
			zephir_concat_self(&phql, _4 TSRMLS_CC);
		} else {
			if (zephir_is_numeric(group)) {
				ZEPHIR_INIT_LNVAR(_15);
				ZEPHIR_CONCAT_SV(_15, " GROUP BY ", group);
				zephir_concat_self(&phql, _15 TSRMLS_CC);
			} else {
				if (zephir_memnstr_str(group, SL("."), "phalcon/mvc/model/query/builder.zep", 1254)) {
					ZEPHIR_INIT_LNVAR(_16);
					ZEPHIR_CONCAT_SV(_16, " GROUP BY ", group);
					zephir_concat_self(&phql, _16 TSRMLS_CC);
				} else {
					if (zephir_memnstr_str(group, SL(","), "phalcon/mvc/model/query/builder.zep", 1257)) {
						ZEPHIR_INIT_VAR(_25);
						ZEPHIR_SINIT_VAR(_26);
						ZVAL_STRING(&_26, " ", 0);
						ZEPHIR_SINIT_VAR(_27);
						ZVAL_STRING(&_27, "", 0);
						zephir_fast_str_replace(&_25, &_26, &_27, group TSRMLS_CC);
						ZEPHIR_CPY_WRT(group, _25);
						ZEPHIR_INIT_NVAR(groupItems);
						zephir_fast_explode_str(groupItems, SL(","), group, LONG_MAX TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_25);
						zephir_fast_join_str(_25, SL("], ["), groupItems TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_20);
						ZEPHIR_CONCAT_SVS(_20, " GROUP BY [", _25, "]");
						zephir_concat_self(&phql, _20 TSRMLS_CC);
					} else {
						ZEPHIR_INIT_LNVAR(_4);
						ZEPHIR_CONCAT_SVS(_4, " GROUP BY [", group, "]");
						zephir_concat_self(&phql, _4 TSRMLS_CC);
					}
				}
			}
		}
	}
	ZEPHIR_OBS_VAR(having);
	zephir_read_property_this(&having, this_ptr, SL("_having"), PH_NOISY_CC);
	if (Z_TYPE_P(having) != IS_NULL) {
		if (!(ZEPHIR_IS_EMPTY(having))) {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, " HAVING ", having);
			zephir_concat_self(&phql, _4 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(order);
	zephir_read_property_this(&order, this_ptr, SL("_order"), PH_NOISY_CC);
	if (Z_TYPE_P(order) != IS_NULL) {
		if (Z_TYPE_P(order) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(orderItems);
			array_init(orderItems);
			zephir_is_iterable(order, &_29, &_28, 0, 0, "phalcon/mvc/model/query/builder.zep", 1294);
			for (
			  ; zephir_hash_get_current_data_ex(_29, (void**) &_30, &_28) == SUCCESS
			  ; zephir_hash_move_forward_ex(_29, &_28)
			) {
				ZEPHIR_GET_HVALUE(orderItem, _30);
				if (zephir_is_numeric(orderItem)) {
					zephir_array_append(&orderItems, orderItem, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1285);
				} else {
					if (zephir_memnstr_str(orderItem, SL("."), "phalcon/mvc/model/query/builder.zep", 1287)) {
						zephir_array_append(&orderItems, orderItem, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1288);
					} else {
						ZEPHIR_INIT_LNVAR(_4);
						ZEPHIR_CONCAT_SVS(_4, "[", orderItem, "]");
						zephir_array_append(&orderItems, _4, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1290);
					}
				}
			}
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_join_str(_1, SL(", "), orderItems TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, " ORDER BY ", _1);
			zephir_concat_self(&phql, _4 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_LNVAR(_15);
			ZEPHIR_CONCAT_SV(_15, " ORDER BY ", order);
			zephir_concat_self(&phql, _15 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(limit);
	zephir_read_property_this(&limit, this_ptr, SL("_limit"), PH_NOISY_CC);
	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_INIT_VAR(number);
		ZVAL_NULL(number);
		if (Z_TYPE_P(limit) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(number);
			zephir_array_fetch_string(&number, limit, SL("number"), PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1309 TSRMLS_CC);
			ZEPHIR_OBS_VAR(offset);
			if (zephir_array_isset_string_fetch(&offset, limit, SS("offset"), 0 TSRMLS_CC)) {
				if (!(zephir_is_numeric(offset))) {
					ZEPHIR_INIT_NVAR(offset);
					ZVAL_LONG(offset, 0);
				}
			}
		} else {
			if (zephir_is_numeric(limit)) {
				ZEPHIR_CPY_WRT(number, limit);
				ZEPHIR_OBS_NVAR(offset);
				zephir_read_property_this(&offset, this_ptr, SL("_offset"), PH_NOISY_CC);
				if (Z_TYPE_P(offset) != IS_NULL) {
					if (!(zephir_is_numeric(offset))) {
						ZEPHIR_INIT_NVAR(offset);
						ZVAL_LONG(offset, 0);
					}
				}
			}
		}
		if (zephir_is_numeric(number)) {
			zephir_concat_self_str(&phql, SL(" LIMIT :APL0:") TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_26);
			ZVAL_LONG(&_26, 10);
			ZEPHIR_CALL_FUNCTION(&_31, "intval", &_32, 26, number, &_26);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "APL0", 1);
			zephir_update_property_array(this_ptr, SL("_bindParams"), _1, _31 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_25);
			ZVAL_STRING(_25, "APL0", 1);
			ZEPHIR_INIT_VAR(_33);
			ZVAL_LONG(_33, 1);
			zephir_update_property_array(this_ptr, SL("_bindTypes"), _25, _33 TSRMLS_CC);
			if (zephir_is_numeric(offset)) {
				zephir_concat_self_str(&phql, SL(" OFFSET :APL1:") TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_26);
				ZVAL_LONG(&_26, 10);
				ZEPHIR_CALL_FUNCTION(&_31, "intval", &_32, 26, offset, &_26);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_34);
				ZVAL_STRING(_34, "APL1", 1);
				zephir_update_property_array(this_ptr, SL("_bindParams"), _34, _31 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_35);
				ZVAL_STRING(_35, "APL1", 1);
				ZEPHIR_INIT_VAR(_36);
				ZVAL_LONG(_36, 1);
				zephir_update_property_array(this_ptr, SL("_bindTypes"), _35, _36 TSRMLS_CC);
			}
		}
	}
	forUpdate = zephir_fetch_nproperty_this(this_ptr, SL("_forUpdate"), PH_NOISY_CC);
	if (Z_TYPE_P(forUpdate) == IS_BOOL) {
		if (zephir_is_true(forUpdate)) {
			zephir_concat_self_str(&phql, SL(" FOR UPDATE") TSRMLS_CC);
		}
	}
	RETURN_CCTOR(phql);

}

/**
 * Returns the query built
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query, *bindParams, *bindTypes, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getphql", NULL, 348);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, query, "__construct", NULL, 339, _0, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(bindParams);
	zephir_read_property_this(&bindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, query, "setbindparams", NULL, 349, bindParams);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(bindTypes);
	zephir_read_property_this(&bindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, query, "setbindtypes", NULL, 350, bindTypes);
		zephir_check_call_status();
	}
	RETURN_CCTOR(query);

}

