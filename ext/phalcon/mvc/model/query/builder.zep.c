
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *<code>
 * $params = [
 *     "models"     => ["Users"],
 *     "columns"    => ["id", "name", "status"],
 *     "conditions" => [
 *         [
 *             "created > :min: AND created < :max:",
 *             [
 *                 "min" => "2013-01-01",
 *                 "max" => "2014-01-01",
 *             ],
 *             [
 *                 "min" => PDO::PARAM_STR,
 *                 "max" => PDO::PARAM_STR,
 *             ],
 *         ],
 *     ],
 *     // or "conditions" => "created > '2013-01-01' AND created < '2014-01-01'",
 *     "group"      => ["id", "name"],
 *     "having"     => "name = 'Kamil'",
 *     "order"      => ["name", "id"],
 *     "limit"      => 20,
 *     "offset"     => 20,
 *     // or "limit" => [20, 20],
 * ];
 *
 * $queryBuilder = new \Phalcon\Mvc\Model\Query\Builder($params);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Builder, phalcon, mvc_model_query_builder, phalcon_mvc_model_query_builder_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_joins"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @deprecated Will be removed in version 4.0.0
	 */
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

	zend_bool _6$$35;
	HashTable *_1$$7;
	HashPosition _0$$7;
	zval *params = NULL, *dependencyInjector = NULL, *conditions = NULL, *columns = NULL, *groupClause = NULL, *havingClause = NULL, *limitClause = NULL, *forUpdate = NULL, *sharedLock = NULL, *orderClause = NULL, *offsetClause = NULL, *joinsClause = NULL, *singleConditionArray = NULL, *limit = NULL, *offset = NULL, *fromClause = NULL, *mergedConditions = NULL, *mergedParams = NULL, *mergedTypes = NULL, *singleCondition = NULL, *singleParams = NULL, *singleTypes = NULL, *distinct = NULL, *bind = NULL, *bindTypes = NULL, **_2$$7, *_5$$7, *_3$$11 = NULL, *_4$$12 = NULL;

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
			zephir_update_property_this(getThis(), SL("_conditions"), conditions TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(conditions);
			if (zephir_array_isset_string_fetch(&conditions, params, SS("conditions"), 0 TSRMLS_CC)) {
				zephir_update_property_this(getThis(), SL("_conditions"), conditions TSRMLS_CC);
			}
		}
		if (Z_TYPE_P(conditions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedConditions);
			array_init(mergedConditions);
			ZEPHIR_INIT_VAR(mergedParams);
			array_init(mergedParams);
			ZEPHIR_INIT_VAR(mergedTypes);
			array_init(mergedTypes);
			zephir_is_iterable(conditions, &_1$$7, &_0$$7, 0, 0, "phalcon/mvc/model/query/builder.zep", 155);
			for (
			  ; zend_hash_get_current_data_ex(_1$$7, (void**) &_2$$7, &_0$$7) == SUCCESS
			  ; zend_hash_move_forward_ex(_1$$7, &_0$$7)
			) {
				ZEPHIR_GET_HVALUE(singleConditionArray, _2$$7);
				if (Z_TYPE_P(singleConditionArray) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(singleCondition);
					zephir_array_isset_long_fetch(&singleCondition, singleConditionArray, 0, 0 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(singleParams);
					zephir_array_isset_long_fetch(&singleParams, singleConditionArray, 1, 0 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(singleTypes);
					zephir_array_isset_long_fetch(&singleTypes, singleConditionArray, 2, 0 TSRMLS_CC);
					if (Z_TYPE_P(singleCondition) == IS_STRING) {
						zephir_array_append(&mergedConditions, singleCondition, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 142);
					}
					if (Z_TYPE_P(singleParams) == IS_ARRAY) {
						ZEPHIR_INIT_LNVAR(_3$$11);
						zephir_add_function(_3$$11, mergedParams, singleParams);
						ZEPHIR_CPY_WRT(mergedParams, _3$$11);
					}
					if (Z_TYPE_P(singleTypes) == IS_ARRAY) {
						ZEPHIR_INIT_LNVAR(_4$$12);
						zephir_add_function(_4$$12, mergedTypes, singleTypes);
						ZEPHIR_CPY_WRT(mergedTypes, _4$$12);
					}
				}
			}
			ZEPHIR_INIT_VAR(_5$$7);
			zephir_fast_join_str(_5$$7, SL(" AND "), mergedConditions TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_conditions"), _5$$7 TSRMLS_CC);
			if (Z_TYPE_P(mergedParams) == IS_ARRAY) {
				zephir_update_property_this(getThis(), SL("_bindParams"), mergedParams TSRMLS_CC);
			}
			if (Z_TYPE_P(mergedTypes) == IS_ARRAY) {
				zephir_update_property_this(getThis(), SL("_bindTypes"), mergedTypes TSRMLS_CC);
			}
		}
		ZEPHIR_OBS_VAR(bind);
		if (zephir_array_isset_string_fetch(&bind, params, SS("bind"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_bindParams"), bind TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SS("bindTypes"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_bindTypes"), bindTypes TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(distinct);
		if (zephir_array_isset_string_fetch(&distinct, params, SS("distinct"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_distinct"), distinct TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(fromClause);
		if (zephir_array_isset_string_fetch(&fromClause, params, SS("models"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_models"), fromClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(columns);
		if (zephir_array_isset_string_fetch(&columns, params, SS("columns"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_columns"), columns TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(joinsClause);
		if (zephir_array_isset_string_fetch(&joinsClause, params, SS("joins"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_joins"), joinsClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(groupClause);
		if (zephir_array_isset_string_fetch(&groupClause, params, SS("group"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_group"), groupClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(havingClause);
		if (zephir_array_isset_string_fetch(&havingClause, params, SS("having"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_having"), havingClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(orderClause);
		if (zephir_array_isset_string_fetch(&orderClause, params, SS("order"), 0 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_order"), orderClause TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(limitClause);
		if (zephir_array_isset_string_fetch(&limitClause, params, SS("limit"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(limitClause) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(limit);
				if (zephir_array_isset_long_fetch(&limit, limitClause, 0, 0 TSRMLS_CC)) {
					if (Z_TYPE_P(limit) == IS_LONG) {
						zephir_update_property_this(getThis(), SL("_limit"), limit TSRMLS_CC);
					}
					ZEPHIR_OBS_VAR(offset);
					if (zephir_array_isset_long_fetch(&offset, limitClause, 1, 0 TSRMLS_CC)) {
						if (Z_TYPE_P(offset) == IS_LONG) {
							zephir_update_property_this(getThis(), SL("_offset"), offset TSRMLS_CC);
						}
					}
				} else {
					zephir_update_property_this(getThis(), SL("_limit"), limitClause TSRMLS_CC);
				}
			} else {
				zephir_update_property_this(getThis(), SL("_limit"), limitClause TSRMLS_CC);
			}
		}
		if (zephir_array_isset_string_fetch(&offsetClause, params, SS("offset"), 1 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_offset"), offsetClause TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&forUpdate, params, SS("for_update"), 1 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_forUpdate"), forUpdate TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&sharedLock, params, SS("shared_lock"), 1 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_sharedLock"), sharedLock TSRMLS_CC);
		}
	} else {
		_6$$35 = Z_TYPE_P(params) == IS_STRING;
		if (_6$$35) {
			_6$$35 = !ZEPHIR_IS_STRING_IDENTICAL(params, "");
		}
		if (_6$$35) {
			zephir_update_property_this(getThis(), SL("_conditions"), params TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 *
 *<code>
 * $builder->distinct("status");
 * $builder->distinct(null);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, distinct) {

	zval *distinct;

	zephir_fetch_params(0, 1, 0, &distinct);



	zephir_update_property_this(getThis(), SL("_distinct"), distinct TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns SELECT DISTINCT / SELECT ALL flag
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDistinct) {

	

	RETURN_MEMBER(getThis(), "_distinct");

}

/**
 * Sets the columns to be queried
 *
 *<code>
 * $builder->columns("id, name");
 *
 * $builder->columns(
 *     [
 *         "id",
 *         "name",
 *     ]
 * );
 *
 * $builder->columns(
 *     [
 *         "name",
 *         "number" => "COUNT(*)",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns) {

	zval *columns;

	zephir_fetch_params(0, 1, 0, &columns);



	zephir_update_property_this(getThis(), SL("_columns"), columns TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns) {

	

	RETURN_MEMBER(getThis(), "_columns");

}

/**
 * Sets the models who makes part of the query
 *
 *<code>
 * $builder->from("Robots");
 *
 * $builder->from(
 *     [
 *         "Robots",
 *         "RobotsParts",
 *     ]
 * );
 *
 * $builder->from(
 *     [
 *         "r"  => "Robots",
 *         "rp" => "RobotsParts",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from) {

	zval *models;

	zephir_fetch_params(0, 1, 0, &models);



	zephir_update_property_this(getThis(), SL("_models"), models TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Add a model to take part of the query
 *
 * NOTE: The third parameter $with is deprecated and will be removed in future releases.
 *
 *<code>
 * // Load data from models Robots
 * $builder->addFrom("Robots");
 *
 * // Load data from model 'Robots' using 'r' as alias in PHQL
 * $builder->addFrom("Robots", "r");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, addFrom) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *alias = NULL, *with = NULL, *models = NULL, *currentModel = NULL, _0$$3, _1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model, &alias, &with);

	if (!alias) {
		alias = ZEPHIR_GLOBAL(global_null);
	}
	if (!with) {
		with = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(with) != IS_NULL) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "The third parameter 'with' is deprecated and will be removed in future releases.", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, 8192);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_0$$3, &_1$$3);
		zephir_check_call_status();
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
		zephir_array_append(&models, model, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 422);
	}
	zephir_update_property_this(getThis(), SL("_models"), models TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom) {

	

	RETURN_MEMBER(getThis(), "_models");

}

/**
 * Adds an :type: join (by default type - INNER) to the query
 *
 *<code>
 * // Inner Join model 'Robots' with automatic conditions and alias
 * $builder->join("Robots");
 *
 * // Inner Join model 'Robots' specifying conditions
 * $builder->join("Robots", "Robots.id = RobotsParts.robots_id");
 *
 * // Inner Join model 'Robots' specifying conditions and alias
 * $builder->join("Robots", "r.id = RobotsParts.robots_id", "r");
 *
 * // Left Join model 'Robots' specifying conditions, alias and type of join
 * $builder->join("Robots", "r.id = RobotsParts.robots_id", "r", "LEFT");
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

	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
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
 * Adds an INNER join to the query
 *
 *<code>
 * // Inner Join model 'Robots' with automatic conditions and alias
 * $builder->innerJoin("Robots");
 *
 * // Inner Join model 'Robots' specifying conditions
 * $builder->innerJoin("Robots", "Robots.id = RobotsParts.robots_id");
 *
 * // Inner Join model 'Robots' specifying conditions and alias
 * $builder->innerJoin("Robots", "r.id = RobotsParts.robots_id", "r");
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

	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
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
 * $builder->leftJoin("Robots", "r.id = RobotsParts.robots_id", "r");
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

	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
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
 * $builder->rightJoin("Robots", "r.id = RobotsParts.robots_id", "r");
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

	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
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
 * Return join parts of the query
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getJoins) {

	

	RETURN_MEMBER(getThis(), "_joins");

}

/**
 * Sets the query WHERE conditions
 *
 *<code>
 * $builder->where(100);
 *
 * $builder->where("name = 'Peter'");
 *
 * $builder->where(
 *     "name = :name: AND id > :id:",
 *     [
 *         "name" => "Peter",
 *         "id"   => 100,
 *     ]
 * );
 *</code>
 *
 * @param mixed conditions
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where) {

	zval *conditions, *bindParams = NULL, *bindTypes = NULL, *currentBindParams = NULL, *currentBindTypes = NULL, *_0$$4, *_1$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("_conditions"), conditions TSRMLS_CC);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$4);
			zephir_add_function(_0$$4, currentBindParams, bindParams);
			zephir_update_property_this(getThis(), SL("_bindParams"), _0$$4 TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_bindParams"), bindParams TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_1$$7);
			zephir_add_function(_1$$7, currentBindTypes, bindTypes);
			zephir_update_property_this(getThis(), SL("_bindTypes"), _1$$7 TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_bindTypes"), bindTypes TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Appends a condition to the current WHERE conditions using a AND operator
 *
 *<code>
 * $builder->andWhere("name = 'Peter'");
 *
 * $builder->andWhere(
 *     "name = :name: AND id > :id:",
 *     [
 *         "name" => "Peter",
 *         "id"   => 100,
 *     ]
 * );
 *</code>
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentConditions = NULL, *_0$$3;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
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


	ZEPHIR_OBS_VAR(currentConditions);
	zephir_read_property_this(&currentConditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_true(currentConditions)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SVSVS(_0$$3, "(", currentConditions, ") AND (", conditions, ")");
		zephir_get_strval(conditions, _0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a condition to the current conditions using an OR operator
 *
 *<code>
 * $builder->orWhere("name = 'Peter'");
 *
 * $builder->orWhere(
 *     "name = :name: AND id > :id:",
 *     [
 *         "name" => "Peter",
 *         "id"   => 100,
 *     ]
 * );
 *</code>
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentConditions = NULL, *_0$$3;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
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


	ZEPHIR_OBS_VAR(currentConditions);
	zephir_read_property_this(&currentConditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_true(currentConditions)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SVSVS(_0$$3, "(", currentConditions, ") OR (", conditions, ")");
		zephir_get_strval(conditions, _0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a BETWEEN condition to the current WHERE conditions
 *
 *<code>
 * $builder->betweenWhere("price", 100.25, 200.50);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, *maximum, *operator_param = NULL, *_0;
	zval *expr = NULL, *operator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "and", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionbetween", NULL, 0, _0, operator, expr, minimum, maximum);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a NOT BETWEEN condition to the current WHERE conditions
 *
 *<code>
 * $builder->notBetweenWhere("price", 100.25, 200.50);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, *maximum, *operator_param = NULL, *_0;
	zval *expr = NULL, *operator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "and", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionnotbetween", NULL, 0, _0, operator, expr, minimum, maximum);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends an IN condition to the current WHERE conditions
 *
 *<code>
 * $builder->inWhere("id", [1, 2, 3]);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, *_0;
	zval *expr = NULL, *operator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	values = values_param;
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "and", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionin", NULL, 0, _0, operator, expr, values);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a NOT IN condition to the current WHERE conditions
 *
 *<code>
 * $builder->notInWhere("id", [1, 2, 3]);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, *_0;
	zval *expr = NULL, *operator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	values = values_param;
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "and", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionnotin", NULL, 0, _0, operator, expr, values);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the conditions for the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getWhere) {

	

	RETURN_MEMBER(getThis(), "_conditions");

}

/**
 * Sets an ORDER BY condition clause
 *
 *<code>
 * $builder->orderBy("Robots.name");
 * $builder->orderBy(["1", "Robots.name"]);
 * $builder->orderBy(["Robots.name DESC"]);
 *</code>
 *
 * @param string|array orderBy
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy) {

	zval *orderBy;

	zephir_fetch_params(0, 1, 0, &orderBy);



	zephir_update_property_this(getThis(), SL("_order"), orderBy TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the set ORDER BY clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy) {

	

	RETURN_MEMBER(getThis(), "_order");

}

/**
 * Sets the HAVING condition clause
 *
 *<code>
 * $builder->having("SUM(Robots.price) > 0");
 *
 * $builder->having(
 *     "SUM(Robots.price) > :sum:",
 *     [
 *         "sum" => 100,
 *     ]
 * );
 *</code>
 *
 * @param mixed conditions
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, having) {

	zval *conditions, *bindParams = NULL, *bindTypes = NULL, *currentBindParams = NULL, *currentBindTypes = NULL, *_0$$4, *_1$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("_having"), conditions TSRMLS_CC);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		currentBindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$4);
			zephir_add_function(_0$$4, currentBindParams, bindParams);
			zephir_update_property_this(getThis(), SL("_bindParams"), _0$$4 TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_bindParams"), bindParams TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		currentBindTypes = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
		if (Z_TYPE_P(currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_1$$7);
			zephir_add_function(_1$$7, currentBindTypes, bindTypes);
			zephir_update_property_this(getThis(), SL("_bindTypes"), _1$$7 TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_bindTypes"), bindTypes TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Appends a condition to the current HAVING conditions clause using a AND operator
 *
 *<code>
 * $builder->andHaving("SUM(Robots.price) > 0");
 *
 * $builder->andHaving(
 *     "SUM(Robots.price) > :sum:",
 *     [
 *         "sum" => 100,
 *     ]
 * );
 *</code>
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andHaving) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentConditions = NULL, *_0$$3;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
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


	ZEPHIR_OBS_VAR(currentConditions);
	zephir_read_property_this(&currentConditions, this_ptr, SL("_having"), PH_NOISY_CC);
	if (zephir_is_true(currentConditions)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SVSVS(_0$$3, "(", currentConditions, ") AND (", conditions, ")");
		zephir_get_strval(conditions, _0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "having", NULL, 0, conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a condition to the current HAVING conditions clause using an OR operator
 *
 *<code>
 * $builder->orHaving("SUM(Robots.price) > 0");
 *
 * $builder->orHaving(
 *     "SUM(Robots.price) > :sum:",
 *     [
 *         "sum" => 100,
 *     ]
 * );
 *</code>
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orHaving) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentConditions = NULL, *_0$$3;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
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


	ZEPHIR_OBS_VAR(currentConditions);
	zephir_read_property_this(&currentConditions, this_ptr, SL("_having"), PH_NOISY_CC);
	if (zephir_is_true(currentConditions)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SVSVS(_0$$3, "(", currentConditions, ") OR (", conditions, ")");
		zephir_get_strval(conditions, _0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "having", NULL, 0, conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a BETWEEN condition to the current HAVING conditions clause
 *
 *<code>
 * $builder->betweenHaving("SUM(Robots.price)", 100.25, 200.50);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenHaving) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, *maximum, *operator_param = NULL, *_0;
	zval *expr = NULL, *operator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "and", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Having", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionbetween", NULL, 0, _0, operator, expr, minimum, maximum);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a NOT BETWEEN condition to the current HAVING conditions clause
 *
 *<code>
 * $builder->notBetweenHaving("SUM(Robots.price)", 100.25, 200.50);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenHaving) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, *maximum, *operator_param = NULL, *_0;
	zval *expr = NULL, *operator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "and", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Having", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionnotbetween", NULL, 0, _0, operator, expr, minimum, maximum);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends an IN condition to the current HAVING conditions clause
 *
 *<code>
 * $builder->inHaving("SUM(Robots.price)", [100, 200]);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inHaving) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, *_0;
	zval *expr = NULL, *operator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	values = values_param;
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "and", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Having", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionin", NULL, 0, _0, operator, expr, values);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a NOT IN condition to the current HAVING conditions clause
 *
 *<code>
 * $builder->notInHaving("SUM(Robots.price)", [100, 200]);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInHaving) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, *_0;
	zval *expr = NULL, *operator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	values = values_param;
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "and", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Having", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionnotin", NULL, 0, _0, operator, expr, values);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the current having clause
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving) {

	

	RETURN_MEMBER(getThis(), "_having");

}

/**
 * Sets a FOR UPDATE clause
 *
 *<code>
 * $builder->forUpdate(true);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, forUpdate) {

	zval *forUpdate_param = NULL;
	zend_bool forUpdate;

	zephir_fetch_params(0, 1, 0, &forUpdate_param);

	forUpdate = zephir_get_boolval(forUpdate_param);


	if (forUpdate) {
		zephir_update_property_this(getThis(), SL("_forUpdate"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_forUpdate"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Sets a LIMIT clause, optionally an offset clause
 *
 * <code>
 * $builder->limit(100);
 * $builder->limit(100, 20);
 * $builder->limit("100", "20");
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit) {

	zval *limit_param = NULL, *offset = NULL, _0, *_1 = NULL, *_2, _3$$4, *_4$$4 = NULL;
	zend_long limit, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit_param, &offset);

	limit = zephir_get_intval(limit_param);
	if (!offset) {
		offset = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, limit);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 213, &_0);
	zephir_check_call_status();
	limit = zephir_get_numberval(_1);
	if (UNEXPECTED(limit == 0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(_2, limit);
	zephir_update_property_this(getThis(), SL("_limit"), _2 TSRMLS_CC);
	if (zephir_is_numeric(offset)) {
		ZEPHIR_SINIT_VAR(_3$$4);
		ZVAL_LONG(&_3$$4, zephir_get_intval(offset));
		ZEPHIR_CALL_FUNCTION(&_4$$4, "abs", NULL, 213, &_3$$4);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_offset"), _4$$4 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the current LIMIT clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit) {

	

	RETURN_MEMBER(getThis(), "_limit");

}

/**
 * Sets an OFFSET clause
 *
 *<code>
 * $builder->offset(30);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, offset) {

	zval *offset_param = NULL, *_0;
	zend_long offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, offset);
	zephir_update_property_this(getThis(), SL("_offset"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current OFFSET clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOffset) {

	

	RETURN_MEMBER(getThis(), "_offset");

}

/**
 * Sets a GROUP BY clause
 *
 *<code>
 * $builder->groupBy(
 *     [
 *         "Robots.name",
 *     ]
 * );
 *</code>
 *
 * @param string|array group
 * @return \Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, groupBy) {

	zval *group;

	zephir_fetch_params(0, 1, 0, &group);



	zephir_update_property_this(getThis(), SL("_group"), group TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the GROUP BY clause
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy) {

	

	RETURN_MEMBER(getThis(), "_group");

}

/**
 * Returns a PHQL statement built based on the builder parameters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql) {

	HashTable *_11$$25, *_17$$31, *_25$$36, *_34$$41, *_49$$49, *_56$$56;
	HashPosition _10$$25, _16$$31, _24$$36, _33$$41, _48$$49, _55$$56;
	zend_class_entry *_3$$8;
	zend_bool noPrimary = 0, _9;
	zval *dependencyInjector = NULL, *models = NULL, *conditions = NULL, *model = NULL, *metaData = NULL, *modelInstance = NULL, *primaryKeys = NULL, *firstPrimaryKey = NULL, *columnMap = NULL, *modelAlias = NULL, *attributeField = NULL, *phql = NULL, *column = NULL, *columns = NULL, *selectedColumns = NULL, *selectedColumn = NULL, *selectedModel = NULL, *selectedModels = NULL, *columnAlias = NULL, *modelColumnAlias = NULL, *joins = NULL, *join = NULL, *joinModel = NULL, *joinConditions = NULL, *joinAlias = NULL, *joinType = NULL, *group = NULL, *groupItems = NULL, *groupItem = NULL, *having = NULL, *order = NULL, *orderItems = NULL, *orderItem = NULL, *limit = NULL, *number = NULL, *offset = NULL, *forUpdate = NULL, *distinct = NULL, *_1$$8 = NULL, *_2$$8 = NULL, *_4$$17, *_5$$17, *_6$$13 = NULL, *_7$$13 = NULL, *_8$$13, **_12$$25, *_15$$25, *_13$$28 = NULL, *_14$$28 = NULL, **_18$$31, *_21$$31, *_19$$33 = NULL, *_20$$34 = NULL, *_22$$35 = NULL, *_23$$35, **_26$$36, *_29$$36, *_30$$36, *_27$$38 = NULL, *_28$$38 = NULL, *_31$$40 = NULL, *_32$$40, **_35$$41, *_36$$43 = NULL, *_37$$43 = NULL, *_38$$44 = NULL, *_39$$44 = NULL, *_40$$45 = NULL, *_41$$45 = NULL, *_42$$46 = NULL, *_43$$48, *_44$$51, _45$$51, _46$$51, *_47$$50, **_50$$49, *_52$$49, *_53$$49, *_51$$52 = NULL, *_54$$54, **_57$$56, *_63$$56, *_64$$56, *itemExplode$$59 = NULL, *_58$$59 = NULL, *_59$$59, *_60$$59, *_61$$59 = NULL, *_62$$57 = NULL, *_65$$60, _66$$69, *_67$$69 = NULL, *_68$$69, *_69$$69, *_70$$69, _71$$70, *_72$$70 = NULL, *_73$$70, *_74$$70, *_75$$70;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(models);
	zephir_read_property_this(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if (Z_TYPE_P(models) == IS_ARRAY) {
		if (!(zephir_fast_count_int(models TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query", "phalcon/mvc/model/query/builder.zep", 1060);
			return;
		}
	} else {
		if (!(zephir_is_true(models))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query", "phalcon/mvc/model/query/builder.zep", 1064);
			return;
		}
	}
	ZEPHIR_OBS_VAR(conditions);
	zephir_read_property_this(&conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_numeric(conditions)) {
		if (Z_TYPE_P(models) == IS_ARRAY) {
			if (zephir_fast_count_int(models TSRMLS_CC) > 1) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot build the query. Invalid condition", "phalcon/mvc/model/query/builder.zep", 1077);
				return;
			}
			ZEPHIR_OBS_VAR(model);
			zephir_array_fetch_long(&model, models, 0, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1079 TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(model, models);
		}
		ZEPHIR_INIT_VAR(_1$$8);
		ZVAL_STRING(_1$$8, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, _1$$8);
		zephir_check_temp_parameter(_1$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(modelInstance);
		zephir_fetch_safe_class(_2$$8, model);
			_3$$8 = zend_fetch_class(Z_STRVAL_P(_2$$8), Z_STRLEN_P(_2$$8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(modelInstance, _3$$8);
		if (zephir_has_constructor(modelInstance TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_1$$8);
			ZVAL_NULL(_1$$8);
			ZEPHIR_CALL_METHOD(NULL, modelInstance, "__construct", NULL, 0, _1$$8, dependencyInjector);
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
						ZEPHIR_INIT_VAR(_4$$17);
						object_init_ex(_4$$17, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(_5$$17);
						ZEPHIR_CONCAT_SVS(_5$$17, "Column '", firstPrimaryKey, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, _4$$17, "__construct", NULL, 9, _5$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(_4$$17, "phalcon/mvc/model/query/builder.zep", 1107 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(attributeField, firstPrimaryKey);
				}
				ZEPHIR_CALL_METHOD(&_6$$13, this_ptr, "autoescape", NULL, 386, model);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$13, this_ptr, "autoescape", NULL, 386, attributeField);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_8$$13);
				ZEPHIR_CONCAT_VSVSV(_8$$13, _6$$13, ".", _7$$13, " = ", conditions);
				ZEPHIR_CPY_WRT(conditions, _8$$13);
				noPrimary = 0;
			}
		}
		if (noPrimary == 1) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined", "phalcon/mvc/model/query/builder.zep", 1122);
			return;
		}
	}
	ZEPHIR_OBS_VAR(distinct);
	zephir_read_property_this(&distinct, this_ptr, SL("_distinct"), PH_NOISY_CC);
	_9 = Z_TYPE_P(distinct) != IS_NULL;
	if (_9) {
		_9 = Z_TYPE_P(distinct) == IS_BOOL;
	}
	if (_9) {
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
			zephir_is_iterable(columns, &_11$$25, &_10$$25, 0, 0, "phalcon/mvc/model/query/builder.zep", 1154);
			for (
			  ; zend_hash_get_current_data_ex(_11$$25, (void**) &_12$$25, &_10$$25) == SUCCESS
			  ; zend_hash_move_forward_ex(_11$$25, &_10$$25)
			) {
				ZEPHIR_GET_HMKEY(columnAlias, _11$$25, _10$$25);
				ZEPHIR_GET_HVALUE(column, _12$$25);
				if (Z_TYPE_P(columnAlias) == IS_LONG) {
					zephir_array_append(&selectedColumns, column, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1148);
				} else {
					ZEPHIR_CALL_METHOD(&_13$$28, this_ptr, "autoescape", NULL, 386, columnAlias);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_14$$28);
					ZEPHIR_CONCAT_VSV(_14$$28, column, " AS ", _13$$28);
					zephir_array_append(&selectedColumns, _14$$28, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1150);
				}
			}
			ZEPHIR_INIT_VAR(_15$$25);
			zephir_fast_join_str(_15$$25, SL(", "), selectedColumns TSRMLS_CC);
			zephir_concat_self(&phql, _15$$25 TSRMLS_CC);
		} else {
			zephir_concat_self(&phql, columns TSRMLS_CC);
		}
	} else {
		if (Z_TYPE_P(models) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(selectedColumns);
			array_init(selectedColumns);
			zephir_is_iterable(models, &_17$$31, &_16$$31, 0, 0, "phalcon/mvc/model/query/builder.zep", 1177);
			for (
			  ; zend_hash_get_current_data_ex(_17$$31, (void**) &_18$$31, &_16$$31) == SUCCESS
			  ; zend_hash_move_forward_ex(_17$$31, &_16$$31)
			) {
				ZEPHIR_GET_HMKEY(modelColumnAlias, _17$$31, _16$$31);
				ZEPHIR_GET_HVALUE(model, _18$$31);
				ZEPHIR_INIT_NVAR(selectedColumn);
				if (Z_TYPE_P(modelColumnAlias) == IS_LONG) {
					ZEPHIR_CALL_METHOD(&_19$$33, this_ptr, "autoescape", NULL, 386, model);
					zephir_check_call_status();
					ZEPHIR_CONCAT_VS(selectedColumn, _19$$33, ".*");
				} else {
					ZEPHIR_CALL_METHOD(&_20$$34, this_ptr, "autoescape", NULL, 386, modelColumnAlias);
					zephir_check_call_status();
					ZEPHIR_CONCAT_VS(selectedColumn, _20$$34, ".*");
				}
				zephir_array_append(&selectedColumns, selectedColumn, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1174);
			}
			ZEPHIR_INIT_VAR(_21$$31);
			zephir_fast_join_str(_21$$31, SL(", "), selectedColumns TSRMLS_CC);
			zephir_concat_self(&phql, _21$$31 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(&_22$$35, this_ptr, "autoescape", NULL, 386, models);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_23$$35);
			ZEPHIR_CONCAT_VS(_23$$35, _22$$35, ".*");
			zephir_concat_self(&phql, _23$$35 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(models) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(selectedModels);
		array_init(selectedModels);
		zephir_is_iterable(models, &_25$$36, &_24$$36, 0, 0, "phalcon/mvc/model/query/builder.zep", 1200);
		for (
		  ; zend_hash_get_current_data_ex(_25$$36, (void**) &_26$$36, &_24$$36) == SUCCESS
		  ; zend_hash_move_forward_ex(_25$$36, &_24$$36)
		) {
			ZEPHIR_GET_HMKEY(modelAlias, _25$$36, _24$$36);
			ZEPHIR_GET_HVALUE(model, _26$$36);
			if (Z_TYPE_P(modelAlias) == IS_STRING) {
				ZEPHIR_CALL_METHOD(&_27$$38, this_ptr, "autoescape", NULL, 386, model);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_28$$38, this_ptr, "autoescape", NULL, 386, modelAlias);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(selectedModel);
				ZEPHIR_CONCAT_VSV(selectedModel, _27$$38, " AS ", _28$$38);
			} else {
				ZEPHIR_CALL_METHOD(&selectedModel, this_ptr, "autoescape", NULL, 386, model);
				zephir_check_call_status();
			}
			zephir_array_append(&selectedModels, selectedModel, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1197);
		}
		ZEPHIR_INIT_VAR(_29$$36);
		zephir_fast_join_str(_29$$36, SL(", "), selectedModels TSRMLS_CC);
		ZEPHIR_INIT_VAR(_30$$36);
		ZEPHIR_CONCAT_SV(_30$$36, " FROM ", _29$$36);
		zephir_concat_self(&phql, _30$$36 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_31$$40, this_ptr, "autoescape", NULL, 386, models);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_32$$40);
		ZEPHIR_CONCAT_SV(_32$$40, " FROM ", _31$$40);
		zephir_concat_self(&phql, _32$$40 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(joins);
	zephir_read_property_this(&joins, this_ptr, SL("_joins"), PH_NOISY_CC);
	if (Z_TYPE_P(joins) == IS_ARRAY) {
		zephir_is_iterable(joins, &_34$$41, &_33$$41, 0, 0, "phalcon/mvc/model/query/builder.zep", 1257);
		for (
		  ; zend_hash_get_current_data_ex(_34$$41, (void**) &_35$$41, &_33$$41) == SUCCESS
		  ; zend_hash_move_forward_ex(_34$$41, &_33$$41)
		) {
			ZEPHIR_GET_HVALUE(join, _35$$41);
			ZEPHIR_OBS_NVAR(joinModel);
			zephir_array_fetch_long(&joinModel, join, 0, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1217 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinConditions);
			zephir_array_fetch_long(&joinConditions, join, 1, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1222 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinAlias);
			zephir_array_fetch_long(&joinAlias, join, 2, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1227 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(joinType);
			zephir_array_fetch_long(&joinType, join, 3, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1232 TSRMLS_CC);
			if (zephir_is_true(joinType)) {
				ZEPHIR_CALL_METHOD(&_36$$43, this_ptr, "autoescape", NULL, 386, joinModel);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_37$$43);
				ZEPHIR_CONCAT_SVSV(_37$$43, " ", joinType, " JOIN ", _36$$43);
				zephir_concat_self(&phql, _37$$43 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_38$$44, this_ptr, "autoescape", NULL, 386, joinModel);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_39$$44);
				ZEPHIR_CONCAT_SV(_39$$44, " JOIN ", _38$$44);
				zephir_concat_self(&phql, _39$$44 TSRMLS_CC);
			}
			if (zephir_is_true(joinAlias)) {
				ZEPHIR_CALL_METHOD(&_40$$45, this_ptr, "autoescape", NULL, 386, joinAlias);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_41$$45);
				ZEPHIR_CONCAT_SV(_41$$45, " AS ", _40$$45);
				zephir_concat_self(&phql, _41$$45 TSRMLS_CC);
			}
			if (zephir_is_true(joinConditions)) {
				ZEPHIR_INIT_LNVAR(_42$$46);
				ZEPHIR_CONCAT_SV(_42$$46, " ON ", joinConditions);
				zephir_concat_self(&phql, _42$$46 TSRMLS_CC);
			}
		}
	}
	if (Z_TYPE_P(conditions) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(conditions))) {
			ZEPHIR_INIT_VAR(_43$$48);
			ZEPHIR_CONCAT_SV(_43$$48, " WHERE ", conditions);
			zephir_concat_self(&phql, _43$$48 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(group);
	zephir_read_property_this(&group, this_ptr, SL("_group"), PH_NOISY_CC);
	if (Z_TYPE_P(group) != IS_NULL) {
		if (Z_TYPE_P(group) == IS_STRING) {
			if (zephir_memnstr_str(group, SL(","), "phalcon/mvc/model/query/builder.zep", 1272)) {
				ZEPHIR_INIT_VAR(_44$$51);
				ZEPHIR_SINIT_VAR(_45$$51);
				ZVAL_STRING(&_45$$51, " ", 0);
				ZEPHIR_SINIT_VAR(_46$$51);
				ZVAL_STRING(&_46$$51, "", 0);
				zephir_fast_str_replace(&_44$$51, &_45$$51, &_46$$51, group TSRMLS_CC);
				ZEPHIR_CPY_WRT(group, _44$$51);
			}
			ZEPHIR_INIT_VAR(_47$$50);
			zephir_fast_explode_str(_47$$50, SL(","), group, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(group, _47$$50);
		}
		ZEPHIR_INIT_VAR(groupItems);
		array_init(groupItems);
		zephir_is_iterable(group, &_49$$49, &_48$$49, 0, 0, "phalcon/mvc/model/query/builder.zep", 1284);
		for (
		  ; zend_hash_get_current_data_ex(_49$$49, (void**) &_50$$49, &_48$$49) == SUCCESS
		  ; zend_hash_move_forward_ex(_49$$49, &_48$$49)
		) {
			ZEPHIR_GET_HVALUE(groupItem, _50$$49);
			ZEPHIR_CALL_METHOD(&_51$$52, this_ptr, "autoescape", NULL, 386, groupItem);
			zephir_check_call_status();
			zephir_array_append(&groupItems, _51$$52, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1281);
		}
		ZEPHIR_INIT_VAR(_52$$49);
		zephir_fast_join_str(_52$$49, SL(", "), groupItems TSRMLS_CC);
		ZEPHIR_INIT_VAR(_53$$49);
		ZEPHIR_CONCAT_SV(_53$$49, " GROUP BY ", _52$$49);
		zephir_concat_self(&phql, _53$$49 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(having);
	zephir_read_property_this(&having, this_ptr, SL("_having"), PH_NOISY_CC);
	if (Z_TYPE_P(having) != IS_NULL) {
		if (!(ZEPHIR_IS_EMPTY(having))) {
			ZEPHIR_INIT_VAR(_54$$54);
			ZEPHIR_CONCAT_SV(_54$$54, " HAVING ", having);
			zephir_concat_self(&phql, _54$$54 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(order);
	zephir_read_property_this(&order, this_ptr, SL("_order"), PH_NOISY_CC);
	if (Z_TYPE_P(order) != IS_NULL) {
		if (Z_TYPE_P(order) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(orderItems);
			array_init(orderItems);
			zephir_is_iterable(order, &_56$$56, &_55$$56, 0, 0, "phalcon/mvc/model/query/builder.zep", 1325);
			for (
			  ; zend_hash_get_current_data_ex(_56$$56, (void**) &_57$$56, &_55$$56) == SUCCESS
			  ; zend_hash_move_forward_ex(_56$$56, &_55$$56)
			) {
				ZEPHIR_GET_HVALUE(orderItem, _57$$56);
				if (Z_TYPE_P(orderItem) == IS_LONG) {
					zephir_array_append(&orderItems, orderItem, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1309);
					continue;
				}
				if (zephir_memnstr_str(orderItem, SL(" "), "phalcon/mvc/model/query/builder.zep", 1314) != 0) {
					ZEPHIR_INIT_NVAR(itemExplode$$59);
					zephir_fast_explode_str(itemExplode$$59, SL(" "), orderItem, LONG_MAX TSRMLS_CC);
					zephir_array_fetch_long(&_59$$59, itemExplode$$59, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query/builder.zep", 1317 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_58$$59, this_ptr, "autoescape", NULL, 386, _59$$59);
					zephir_check_call_status();
					zephir_array_fetch_long(&_60$$59, itemExplode$$59, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query/builder.zep", 1317 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_61$$59);
					ZEPHIR_CONCAT_VSV(_61$$59, _58$$59, " ", _60$$59);
					zephir_array_append(&orderItems, _61$$59, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1317);
					continue;
				}
				ZEPHIR_CALL_METHOD(&_62$$57, this_ptr, "autoescape", NULL, 386, orderItem);
				zephir_check_call_status();
				zephir_array_append(&orderItems, _62$$57, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1322);
			}
			ZEPHIR_INIT_VAR(_63$$56);
			zephir_fast_join_str(_63$$56, SL(", "), orderItems TSRMLS_CC);
			ZEPHIR_INIT_VAR(_64$$56);
			ZEPHIR_CONCAT_SV(_64$$56, " ORDER BY ", _63$$56);
			zephir_concat_self(&phql, _64$$56 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_65$$60);
			ZEPHIR_CONCAT_SV(_65$$60, " ORDER BY ", order);
			zephir_concat_self(&phql, _65$$60 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(limit);
	zephir_read_property_this(&limit, this_ptr, SL("_limit"), PH_NOISY_CC);
	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_INIT_VAR(number);
		ZVAL_NULL(number);
		if (Z_TYPE_P(limit) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(number);
			zephir_array_fetch_string(&number, limit, SL("number"), PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1340 TSRMLS_CC);
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
			ZEPHIR_SINIT_VAR(_66$$69);
			ZVAL_LONG(&_66$$69, 10);
			ZEPHIR_CALL_FUNCTION(&_67$$69, "intval", NULL, 39, number, &_66$$69);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_68$$69);
			ZVAL_STRING(_68$$69, "APL0", 1);
			zephir_update_property_array(this_ptr, SL("_bindParams"), _68$$69, _67$$69 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_69$$69);
			ZVAL_STRING(_69$$69, "APL0", 1);
			ZEPHIR_INIT_VAR(_70$$69);
			ZVAL_LONG(_70$$69, 1);
			zephir_update_property_array(this_ptr, SL("_bindTypes"), _69$$69, _70$$69 TSRMLS_CC);
			if (zephir_is_numeric(offset)) {
				zephir_concat_self_str(&phql, SL(" OFFSET :APL1:") TSRMLS_CC);
				ZEPHIR_SINIT_VAR(_71$$70);
				ZVAL_LONG(&_71$$70, 10);
				ZEPHIR_CALL_FUNCTION(&_72$$70, "intval", NULL, 39, offset, &_71$$70);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_73$$70);
				ZVAL_STRING(_73$$70, "APL1", 1);
				zephir_update_property_array(this_ptr, SL("_bindParams"), _73$$70, _72$$70 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_74$$70);
				ZVAL_STRING(_74$$70, "APL1", 1);
				ZEPHIR_INIT_VAR(_75$$70);
				ZVAL_LONG(_75$$70, 1);
				zephir_update_property_array(this_ptr, SL("_bindTypes"), _74$$70, _75$$70 TSRMLS_CC);
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

	zval *_2;
	zval *query = NULL, *bindParams = NULL, *bindTypes = NULL, *phql = NULL, *dependencyInjector = NULL, *_0, *_1 = NULL, *_3, *_4, *_5$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&phql, this_ptr, "getphql", NULL, 387);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/query/builder.zep", 1394);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, phql);
	zephir_array_fast_append(_2, dependencyInjector);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\Query", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "get", NULL, 0, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, _1);
	ZEPHIR_OBS_VAR(bindParams);
	zephir_read_property_this(&bindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, query, "setbindparams", NULL, 0, bindParams);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(bindTypes);
	zephir_read_property_this(&bindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, query, "setbindtypes", NULL, 0, bindTypes);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("_sharedLock"), PH_NOISY_CC);
	if (Z_TYPE_P(_4) == IS_BOOL) {
		_5$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_sharedLock"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, query, "setsharedlock", NULL, 0, _5$$6);
		zephir_check_call_status();
	}
	RETURN_CCTOR(query);

}

/**
 * Automatically escapes identifiers but only if they need to be escaped.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, autoescape) {

	zend_bool _0, _1;
	zval *identifier_param = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_memnstr_str(identifier, SL("["), "phalcon/mvc/model/query/builder.zep", 1429);
	if (!(_0)) {
		_0 = zephir_memnstr_str(identifier, SL("."), "phalcon/mvc/model/query/builder.zep", 1429);
	}
	_1 = _0;
	if (!(_1)) {
		_1 = zephir_is_numeric(identifier);
	}
	if (_1) {
		RETURN_CTOR(identifier);
	}
	ZEPHIR_CONCAT_SVS(return_value, "[", identifier, "]");
	RETURN_MM();

}

/**
 * Appends a BETWEEN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, _conditionBetween) {

	zval *_6;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *minimum, *maximum, *hiddenParam = NULL, *nextHiddenParam = NULL, *minimumKey = NULL, *maximumKey = NULL, *operatorMethod = NULL, *_5, *_1$$3, _2$$3, *_3$$3 = NULL;
	zval *clause = NULL, *operator = NULL, *expr = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &clause_param, &operator_param, &expr_param, &minimum, &maximum);

	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(clause);
		ZVAL_EMPTY_STRING(clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(operator, "or");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 164, &_2$$3, operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/model/query/builder.zep", 1444 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, operator, clause);
	ZEPHIR_CPY_WRT(operatorMethod, _4);
	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(nextHiddenParam);
	ZVAL_LONG(nextHiddenParam, (zephir_get_numberval(hiddenParam) + 1));
	ZEPHIR_INIT_VAR(minimumKey);
	ZEPHIR_CONCAT_SV(minimumKey, "AP", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "AP", nextHiddenParam);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VSVSVS(_5, expr, " BETWEEN :", minimumKey, ": AND :", maximumKey, ":");
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 2, 0 TSRMLS_CC);
	zephir_array_update_zval(&_6, minimumKey, &minimum, PH_COPY);
	zephir_array_update_zval(&_6, maximumKey, &maximum, PH_COPY);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, operatorMethod, NULL, 0, _5, _6);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(nextHiddenParam);
	zephir_increment(nextHiddenParam);
	zephir_update_property_this(getThis(), SL("_hiddenParamNumber"), nextHiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a NOT BETWEEN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, _conditionNotBetween) {

	zval *_6;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *minimum, *maximum, *hiddenParam = NULL, *nextHiddenParam = NULL, *minimumKey = NULL, *maximumKey = NULL, *operatorMethod = NULL, *_5, *_1$$3, _2$$3, *_3$$3 = NULL;
	zval *clause = NULL, *operator = NULL, *expr = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &clause_param, &operator_param, &expr_param, &minimum, &maximum);

	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(clause);
		ZVAL_EMPTY_STRING(clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(operator, "or");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 164, &_2$$3, operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/model/query/builder.zep", 1483 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, operator, clause);
	ZEPHIR_CPY_WRT(operatorMethod, _4);
	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(nextHiddenParam);
	ZVAL_LONG(nextHiddenParam, (zephir_get_numberval(hiddenParam) + 1));
	ZEPHIR_INIT_VAR(minimumKey);
	ZEPHIR_CONCAT_SV(minimumKey, "AP", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "AP", nextHiddenParam);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VSVSVS(_5, expr, " NOT BETWEEN :", minimumKey, ": AND :", maximumKey, ":");
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 2, 0 TSRMLS_CC);
	zephir_array_update_zval(&_6, minimumKey, &minimum, PH_COPY);
	zephir_array_update_zval(&_6, maximumKey, &maximum, PH_COPY);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, operatorMethod, NULL, 0, _5, _6);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(nextHiddenParam);
	zephir_increment(nextHiddenParam);
	zephir_update_property_this(getThis(), SL("_hiddenParamNumber"), nextHiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends an IN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, _conditionIn) {

	HashTable *_8;
	HashPosition _7;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenParam = 0;
	zval *values = NULL;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *values_param = NULL, *key = NULL, *queryKey = NULL, *value = NULL, *bindKeys = NULL, *bindParams = NULL, *operatorMethod = NULL, *_6, **_9, *_12, *_13, *_14, *_1$$3, _2$$3, *_3$$3 = NULL, _10$$5 = zval_used_for_init;
	zval *clause = NULL, *operator = NULL, *expr = NULL, *_4, *_5$$4, *_11$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &clause_param, &operator_param, &expr_param, &values_param);

	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(clause);
		ZVAL_EMPTY_STRING(clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	values = values_param;


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(operator, "or");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 164, &_2$$3, operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/model/query/builder.zep", 1522 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, operator, clause);
	ZEPHIR_CPY_WRT(operatorMethod, _4);
	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_VSV(_5$$4, expr, " != ", expr);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, operatorMethod, NULL, 0, _5$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(_6);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_8, &_7, 0, 0, "phalcon/mvc/model/query/builder.zep", 1551);
	for (
	  ; zend_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zend_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(value, _9);
		ZEPHIR_SINIT_NVAR(_10$$5);
		ZVAL_LONG(&_10$$5, hiddenParam);
		ZEPHIR_INIT_LNVAR(_11$$5);
		ZEPHIR_CONCAT_SV(_11$$5, "AP", &_10$$5);
		ZEPHIR_CPY_WRT(key, _11$$5);
		ZEPHIR_INIT_NVAR(queryKey);
		ZEPHIR_CONCAT_SVS(queryKey, ":", key, ":");
		zephir_array_append(&bindKeys, queryKey, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1542);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		hiddenParam++;
	}
	ZEPHIR_INIT_VAR(_12);
	zephir_fast_join_str(_12, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_VSVS(_13, expr, " IN (", _12, ")");
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, operatorMethod, NULL, 0, _13, bindParams);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_14);
	ZVAL_LONG(_14, hiddenParam);
	zephir_update_property_this(getThis(), SL("_hiddenParamNumber"), _14 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a NOT IN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, _conditionNotIn) {

	HashTable *_8;
	HashPosition _7;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenParam = 0;
	zval *values = NULL;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *values_param = NULL, *key = NULL, *queryKey = NULL, *value = NULL, *bindKeys = NULL, *bindParams = NULL, *operatorMethod = NULL, *_6, **_9, *_12, *_13, *_14, *_1$$3, _2$$3, *_3$$3 = NULL, _10$$5 = zval_used_for_init;
	zval *clause = NULL, *operator = NULL, *expr = NULL, *_4, *_5$$4, *_11$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &clause_param, &operator_param, &expr_param, &values_param);

	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(clause);
		ZVAL_EMPTY_STRING(clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_EMPTY_STRING(operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(expr);
		ZVAL_EMPTY_STRING(expr);
	}
	values = values_param;


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(operator, "or");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 164, &_2$$3, operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/model/query/builder.zep", 1567 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, operator, clause);
	ZEPHIR_CPY_WRT(operatorMethod, _4);
	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_VSV(_5$$4, expr, " != ", expr);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, operatorMethod, NULL, 0, _5$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(_6);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_8, &_7, 0, 0, "phalcon/mvc/model/query/builder.zep", 1596);
	for (
	  ; zend_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zend_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(value, _9);
		ZEPHIR_SINIT_NVAR(_10$$5);
		ZVAL_LONG(&_10$$5, hiddenParam);
		ZEPHIR_INIT_LNVAR(_11$$5);
		ZEPHIR_CONCAT_SV(_11$$5, "AP", &_10$$5);
		ZEPHIR_CPY_WRT(key, _11$$5);
		ZEPHIR_INIT_NVAR(queryKey);
		ZEPHIR_CONCAT_SVS(queryKey, ":", key, ":");
		zephir_array_append(&bindKeys, queryKey, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1587);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		hiddenParam++;
	}
	ZEPHIR_INIT_VAR(_12);
	zephir_fast_join_str(_12, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_VSVS(_13, expr, " NOT IN (", _12, ")");
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, operatorMethod, NULL, 0, _13, bindParams);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_14);
	ZVAL_LONG(_14, hiddenParam);
	zephir_update_property_this(getThis(), SL("_hiddenParamNumber"), _14 TSRMLS_CC);
	RETURN_THIS();

}

