
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zend_bool _4$$35;
	zval *params = NULL, params_sub, *dependencyInjector = NULL, dependencyInjector_sub, __$null, conditions, columns, groupClause, havingClause, limitClause, forUpdate, sharedLock, orderClause, offsetClause, joinsClause, singleConditionArray, limit, offset, fromClause, mergedConditions, mergedParams, mergedTypes, singleCondition, singleParams, singleTypes, distinct, bind, bindTypes, *_0$$7, _3$$7, _1$$11, _2$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&groupClause);
	ZVAL_UNDEF(&havingClause);
	ZVAL_UNDEF(&limitClause);
	ZVAL_UNDEF(&forUpdate);
	ZVAL_UNDEF(&sharedLock);
	ZVAL_UNDEF(&orderClause);
	ZVAL_UNDEF(&offsetClause);
	ZVAL_UNDEF(&joinsClause);
	ZVAL_UNDEF(&singleConditionArray);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&fromClause);
	ZVAL_UNDEF(&mergedConditions);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&mergedTypes);
	ZVAL_UNDEF(&singleCondition);
	ZVAL_UNDEF(&singleParams);
	ZVAL_UNDEF(&singleTypes);
	ZVAL_UNDEF(&distinct);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_1$$11);
	ZVAL_UNDEF(&_2$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &params, &dependencyInjector);

	if (!params) {
		params = &params_sub;
		params = &__$null;
	}
	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		dependencyInjector = &__$null;
	}


	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&conditions);
		if (zephir_array_isset_long_fetch(&conditions, params, 0, 0 TSRMLS_CC)) {
			zephir_update_property_zval(this_ptr, SL("_conditions"), &conditions);
		} else {
			ZEPHIR_OBS_NVAR(&conditions);
			if (zephir_array_isset_string_fetch(&conditions, params, SL("conditions"), 0)) {
				zephir_update_property_zval(this_ptr, SL("_conditions"), &conditions);
			}
		}
		if (Z_TYPE_P(&conditions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedConditions);
			array_init(&mergedConditions);
			ZEPHIR_INIT_VAR(&mergedParams);
			array_init(&mergedParams);
			ZEPHIR_INIT_VAR(&mergedTypes);
			array_init(&mergedTypes);
			zephir_is_iterable(&conditions, 0, "phalcon/mvc/model/query/builder.zep", 142);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&conditions), _0$$7)
			{
				ZEPHIR_INIT_NVAR(&singleConditionArray);
				ZVAL_COPY(&singleConditionArray, _0$$7);
				if (Z_TYPE_P(&singleConditionArray) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&singleCondition);
					zephir_array_isset_long_fetch(&singleCondition, &singleConditionArray, 0, 0 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&singleParams);
					zephir_array_isset_long_fetch(&singleParams, &singleConditionArray, 1, 0 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&singleTypes);
					zephir_array_isset_long_fetch(&singleTypes, &singleConditionArray, 2, 0 TSRMLS_CC);
					if (Z_TYPE_P(&singleCondition) == IS_STRING) {
						zephir_array_append(&mergedConditions, &singleCondition, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 129);
					}
					if (Z_TYPE_P(&singleParams) == IS_ARRAY) {
						ZEPHIR_INIT_LNVAR(_1$$11);
						zephir_add_function(&_1$$11, &mergedParams, &singleParams);
						ZEPHIR_CPY_WRT(&mergedParams, &_1$$11);
					}
					if (Z_TYPE_P(&singleTypes) == IS_ARRAY) {
						ZEPHIR_INIT_LNVAR(_2$$12);
						zephir_add_function(&_2$$12, &mergedTypes, &singleTypes);
						ZEPHIR_CPY_WRT(&mergedTypes, &_2$$12);
					}
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&singleConditionArray);
			ZEPHIR_INIT_VAR(&_3$$7);
			zephir_fast_join_str(&_3$$7, SL(" AND "), &mergedConditions TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_conditions"), &_3$$7);
			if (Z_TYPE_P(&mergedParams) == IS_ARRAY) {
				zephir_update_property_zval(this_ptr, SL("_bindParams"), &mergedParams);
			}
			if (Z_TYPE_P(&mergedTypes) == IS_ARRAY) {
				zephir_update_property_zval(this_ptr, SL("_bindTypes"), &mergedTypes);
			}
		}
		ZEPHIR_OBS_VAR(&bind);
		if (zephir_array_isset_string_fetch(&bind, params, SL("bind"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &bind);
		}
		ZEPHIR_OBS_VAR(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SL("bindTypes"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), &bindTypes);
		}
		ZEPHIR_OBS_VAR(&distinct);
		if (zephir_array_isset_string_fetch(&distinct, params, SL("distinct"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_distinct"), &distinct);
		}
		ZEPHIR_OBS_VAR(&fromClause);
		if (zephir_array_isset_string_fetch(&fromClause, params, SL("models"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_models"), &fromClause);
		}
		ZEPHIR_OBS_VAR(&columns);
		if (zephir_array_isset_string_fetch(&columns, params, SL("columns"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_columns"), &columns);
		}
		ZEPHIR_OBS_VAR(&joinsClause);
		if (zephir_array_isset_string_fetch(&joinsClause, params, SL("joins"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_joins"), &joinsClause);
		}
		ZEPHIR_OBS_VAR(&groupClause);
		if (zephir_array_isset_string_fetch(&groupClause, params, SL("group"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_group"), &groupClause);
		}
		ZEPHIR_OBS_VAR(&havingClause);
		if (zephir_array_isset_string_fetch(&havingClause, params, SL("having"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_having"), &havingClause);
		}
		ZEPHIR_OBS_VAR(&orderClause);
		if (zephir_array_isset_string_fetch(&orderClause, params, SL("order"), 0)) {
			zephir_update_property_zval(this_ptr, SL("_order"), &orderClause);
		}
		ZEPHIR_OBS_VAR(&limitClause);
		if (zephir_array_isset_string_fetch(&limitClause, params, SL("limit"), 0)) {
			if (Z_TYPE_P(&limitClause) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(&limit);
				if (zephir_array_isset_long_fetch(&limit, &limitClause, 0, 0 TSRMLS_CC)) {
					if (Z_TYPE_P(&limit) == IS_LONG) {
						zephir_update_property_zval(this_ptr, SL("_limit"), &limit);
					}
					ZEPHIR_OBS_VAR(&offset);
					if (zephir_array_isset_long_fetch(&offset, &limitClause, 1, 0 TSRMLS_CC)) {
						if (Z_TYPE_P(&offset) == IS_LONG) {
							zephir_update_property_zval(this_ptr, SL("_offset"), &offset);
						}
					}
				} else {
					zephir_update_property_zval(this_ptr, SL("_limit"), &limitClause);
				}
			} else {
				zephir_update_property_zval(this_ptr, SL("_limit"), &limitClause);
			}
		}
		if (zephir_array_isset_string_fetch(&offsetClause, params, SL("offset"), 1)) {
			zephir_update_property_zval(this_ptr, SL("_offset"), &offsetClause);
		}
		if (zephir_array_isset_string_fetch(&forUpdate, params, SL("for_update"), 1)) {
			zephir_update_property_zval(this_ptr, SL("_forUpdate"), &forUpdate);
		}
		if (zephir_array_isset_string_fetch(&sharedLock, params, SL("shared_lock"), 1)) {
			zephir_update_property_zval(this_ptr, SL("_sharedLock"), &sharedLock);
		}
	} else {
		_4$$35 = Z_TYPE_P(params) == IS_STRING;
		if (_4$$35) {
			_4$$35 = !ZEPHIR_IS_STRING_IDENTICAL(params, "");
		}
		if (_4$$35) {
			zephir_update_property_zval(this_ptr, SL("_conditions"), params);
		}
	}
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);
	RETURN_THISW();

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI) {

	zval *this_ptr = getThis();


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

	zval *distinct, distinct_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&distinct_sub);

	zephir_fetch_params(0, 1, 0, &distinct);



	zephir_update_property_zval(this_ptr, SL("_distinct"), distinct);
	RETURN_THISW();

}

/**
 * Returns SELECT DISTINCT / SELECT ALL flag
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDistinct) {

	zval *this_ptr = getThis();


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

	zval *columns, columns_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);

	zephir_fetch_params(0, 1, 0, &columns);



	zephir_update_property_zval(this_ptr, SL("_columns"), columns);
	RETURN_THISW();

}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns) {

	zval *this_ptr = getThis();


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

	zval *models, models_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&models_sub);

	zephir_fetch_params(0, 1, 0, &models);



	zephir_update_property_zval(this_ptr, SL("_models"), models);
	RETURN_THISW();

}

/**
 * Add a model to take part of the query
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

	zval *model_param = NULL, *alias_param = NULL, models, currentModel;
	zval model, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&currentModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &model_param, &alias_param);

	zephir_get_strval(&model, model_param);
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
		zephir_get_strval(&alias, alias_param);
	}


	ZEPHIR_OBS_VAR(&models);
	zephir_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if (Z_TYPE_P(&models) != IS_ARRAY) {
		if (Z_TYPE_P(&models) != IS_NULL) {
			ZEPHIR_CPY_WRT(&currentModel, &models);
			ZEPHIR_INIT_NVAR(&models);
			zephir_create_array(&models, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&models, &currentModel);
		} else {
			ZEPHIR_INIT_NVAR(&models);
			array_init(&models);
		}
	}
	if (1 == 1) {
		zephir_array_update_zval(&models, &alias, &model, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_append(&models, &model, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 400);
	}
	zephir_update_property_zval(this_ptr, SL("_models"), &models);
	RETURN_THIS();

}

/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom) {

	zval *this_ptr = getThis();


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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, join) {

	zval _0;
	zval *model_param = NULL, *conditions_param = NULL, *alias_param = NULL, *type_param = NULL;
	zval model, conditions, alias, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model_param, &conditions_param, &alias_param, &type_param);

	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
		ZVAL_EMPTY_STRING(&model);
	}
	if (!conditions_param) {
		ZEPHIR_INIT_VAR(&conditions);
		ZVAL_STRING(&conditions, "");
	} else {
		zephir_get_strval(&conditions, conditions_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
		zephir_get_strval(&alias, alias_param);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &model);
	zephir_array_fast_append(&_0, &conditions);
	zephir_array_fast_append(&_0, &alias);
	zephir_array_fast_append(&_0, &type);
	zephir_update_property_array_append(this_ptr, SL("_joins"), &_0 TSRMLS_CC);
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, innerJoin) {

	zval _0;
	zval *model_param = NULL, *conditions_param = NULL, *alias_param = NULL, _1;
	zval model, conditions, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions_param, &alias_param);

	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
		ZVAL_EMPTY_STRING(&model);
	}
	if (!conditions_param) {
		ZEPHIR_INIT_VAR(&conditions);
		ZVAL_STRING(&conditions, "");
	} else {
		zephir_get_strval(&conditions, conditions_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
		zephir_get_strval(&alias, alias_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &model);
	zephir_array_fast_append(&_0, &conditions);
	zephir_array_fast_append(&_0, &alias);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "INNER");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_array_append(this_ptr, SL("_joins"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a LEFT join to the query
 *
 *<code>
 * $builder->leftJoin("Robots", "r.id = RobotsParts.robots_id", "r");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, leftJoin) {

	zval _0;
	zval *model_param = NULL, *conditions_param = NULL, *alias_param = NULL, _1;
	zval model, conditions, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions_param, &alias_param);

	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
		ZVAL_EMPTY_STRING(&model);
	}
	if (!conditions_param) {
		ZEPHIR_INIT_VAR(&conditions);
		ZVAL_STRING(&conditions, "");
	} else {
		zephir_get_strval(&conditions, conditions_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
		zephir_get_strval(&alias, alias_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &model);
	zephir_array_fast_append(&_0, &conditions);
	zephir_array_fast_append(&_0, &alias);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "LEFT");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_array_append(this_ptr, SL("_joins"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a RIGHT join to the query
 *
 *<code>
 * $builder->rightJoin("Robots", "r.id = RobotsParts.robots_id", "r");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, rightJoin) {

	zval _0;
	zval *model_param = NULL, *conditions_param = NULL, *alias_param = NULL, _1;
	zval model, conditions, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions_param, &alias_param);

	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
		ZVAL_EMPTY_STRING(&model);
	}
	if (!conditions_param) {
		ZEPHIR_INIT_VAR(&conditions);
		ZVAL_STRING(&conditions, "");
	} else {
		zephir_get_strval(&conditions, conditions_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
		zephir_get_strval(&alias, alias_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &model);
	zephir_array_fast_append(&_0, &conditions);
	zephir_array_fast_append(&_0, &alias);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "RIGHT");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_array_append(this_ptr, SL("_joins"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return join parts of the query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getJoins) {

	zval *this_ptr = getThis();


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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where) {

	zval bindParams, bindTypes;
	zval *conditions_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, currentBindParams, currentBindTypes, _0$$4, _1$$7;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams_param, &bindTypes_param);

	zephir_get_strval(&conditions, conditions_param);
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}


	zephir_update_property_zval(this_ptr, SL("_conditions"), &conditions);
	if (zephir_fast_count_int(&bindParams TSRMLS_CC) > 0) {
		ZEPHIR_OBS_VAR(&currentBindParams);
		zephir_read_property(&currentBindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindParams, &bindParams);
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &bindParams);
		}
	}
	if (zephir_fast_count_int(&bindTypes TSRMLS_CC) > 0) {
		zephir_read_property(&currentBindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$7);
			zephir_add_function(&_1$$7, &currentBindTypes, &bindTypes);
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), &_1$$7);
		} else {
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), &bindTypes);
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams, bindTypes;
	zval *conditions_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, currentConditions, _0$$3;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&currentConditions);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams_param, &bindTypes_param);

	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
		ZVAL_EMPTY_STRING(&conditions);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}


	ZEPHIR_OBS_VAR(&currentConditions);
	zephir_read_property(&currentConditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_true(&currentConditions)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "(", &currentConditions, ") AND (", &conditions, ")");
		zephir_get_strval(&conditions, &_0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &conditions, &bindParams, &bindTypes);
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams, bindTypes;
	zval *conditions_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, currentConditions, _0$$3;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&currentConditions);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams_param, &bindTypes_param);

	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
		ZVAL_EMPTY_STRING(&conditions);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}


	ZEPHIR_OBS_VAR(&currentConditions);
	zephir_read_property(&currentConditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_true(&currentConditions)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "(", &currentConditions, ") OR (", &conditions, ")");
		zephir_get_strval(&conditions, &_0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &conditions, &bindParams, &bindTypes);
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
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Where");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionbetween", NULL, 0, &_0, &operator, &expr, minimum, maximum);
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
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Where");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionnotbetween", NULL, 0, &_0, &operator, &expr, minimum, maximum);
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
	zval values;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Where");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionin", NULL, 0, &_0, &operator, &expr, &values);
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
	zval values;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Where");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionnotin", NULL, 0, &_0, &operator, &expr, &values);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the conditions for the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getWhere) {

	zval *this_ptr = getThis();


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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy) {

	zval *orderBy, orderBy_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderBy_sub);

	zephir_fetch_params(0, 1, 0, &orderBy);



	zephir_update_property_zval(this_ptr, SL("_order"), orderBy);
	RETURN_THISW();

}

/**
 * Returns the set ORDER BY clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy) {

	zval *this_ptr = getThis();


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

	zval *conditions, conditions_sub, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentBindParams, currentBindTypes, _0$$4, _1$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_having"), conditions);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		zephir_read_property(&currentBindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindParams, bindParams);
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, SL("_bindParams"), bindParams);
		}
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		zephir_read_property(&currentBindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$7);
			zephir_add_function(&_1$$7, &currentBindTypes, bindTypes);
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), &_1$$7);
		} else {
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), bindTypes);
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
	zval *conditions_param = NULL, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentConditions, _0$$3;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentConditions);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
		ZVAL_EMPTY_STRING(&conditions);
	}
	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}


	ZEPHIR_OBS_VAR(&currentConditions);
	zephir_read_property(&currentConditions, this_ptr, SL("_having"), PH_NOISY_CC);
	if (zephir_is_true(&currentConditions)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "(", &currentConditions, ") AND (", &conditions, ")");
		zephir_get_strval(&conditions, &_0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "having", NULL, 0, &conditions, bindParams, bindTypes);
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
	zval *conditions_param = NULL, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentConditions, _0$$3;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentConditions);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);

	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
		ZVAL_EMPTY_STRING(&conditions);
	}
	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}


	ZEPHIR_OBS_VAR(&currentConditions);
	zephir_read_property(&currentConditions, this_ptr, SL("_having"), PH_NOISY_CC);
	if (zephir_is_true(&currentConditions)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "(", &currentConditions, ") OR (", &conditions, ")");
		zephir_get_strval(&conditions, &_0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "having", NULL, 0, &conditions, bindParams, bindTypes);
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
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Having");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionbetween", NULL, 0, &_0, &operator, &expr, minimum, maximum);
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
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Having");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionnotbetween", NULL, 0, &_0, &operator, &expr, minimum, maximum);
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
	zval values;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Having");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionin", NULL, 0, &_0, &operator, &expr, &values);
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
	zval values;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Having");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_conditionnotin", NULL, 0, &_0, &operator, &expr, &values);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the current having clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving) {

	zval *this_ptr = getThis();


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

	zval *forUpdate_param = NULL, __$true, __$false;
	zend_bool forUpdate;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &forUpdate_param);

	forUpdate = zephir_get_boolval(forUpdate_param);


	if (forUpdate) {
		zephir_update_property_zval(this_ptr, SL("_forUpdate"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_forUpdate"), &__$false);
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

	zval *limit_param = NULL, *offset = NULL, offset_sub, __$null, _0, _1, _2$$4, _3$$4;
	zend_long limit, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit_param, &offset);

	limit = zephir_get_intval(limit_param);
	if (!offset) {
		offset = &offset_sub;
		offset = &__$null;
	}


	ZVAL_LONG(&_0, limit);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 184, &_0);
	zephir_check_call_status();
	limit = zephir_get_numberval(&_1);
	if (UNEXPECTED(limit == 0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, limit);
	zephir_update_property_zval(this_ptr, SL("_limit"), &_0);
	if (zephir_is_numeric(offset)) {
		ZVAL_LONG(&_2$$4, zephir_get_intval(offset));
		ZEPHIR_CALL_FUNCTION(&_3$$4, "abs", NULL, 184, &_2$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_offset"), &_3$$4);
	}
	RETURN_THIS();

}

/**
 * Returns the current LIMIT clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit) {

	zval *this_ptr = getThis();


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

	zval *offset_param = NULL, _0;
	zend_long offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, offset);
	zephir_update_property_zval(this_ptr, SL("_offset"), &_0);
	RETURN_THISW();

}

/**
 * Returns the current OFFSET clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOffset) {

	zval *this_ptr = getThis();


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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, groupBy) {

	zval *group, group_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);

	zephir_fetch_params(0, 1, 0, &group);



	zephir_update_property_zval(this_ptr, SL("_group"), group);
	RETURN_THISW();

}

/**
 * Returns the GROUP BY clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_group");

}

/**
 * Returns a PHQL statement built based on the builder parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql) {

	zend_string *_13$$25, *_19$$31, *_27$$36;
	zend_ulong _12$$25, _18$$31, _26$$36;
	zend_class_entry *_3$$8;
	zend_bool noPrimary = 0, _10;
	zval dependencyInjector, models, conditions, model, metaData, modelInstance, primaryKeys, firstPrimaryKey, columnMap, modelAlias, attributeField, phql, column, columns, selectedColumns, selectedColumn, selectedModel, selectedModels, columnAlias, modelColumnAlias, joins, join, joinModel, joinConditions, joinAlias, joinType, group, groupItems, groupItem, having, order, orderItems, orderItem, limit, number, offset, forUpdate, distinct, _1$$8, _2$$8, _4$$8, _5$$17, _6$$17, _7$$13, _8$$13, _9$$13, *_11$$25, _16$$25, _14$$28, _15$$28, *_17$$31, _22$$31, _20$$33, _21$$34, _23$$35, _24$$35, *_25$$36, _30$$36, _31$$36, _28$$38, _29$$38, _32$$40, _33$$40, *_34$$41, _35$$43, _36$$43, _37$$44, _38$$44, _39$$45, _40$$45, _41$$46, _42$$48, _43$$51, _44$$51, _45$$51, _46$$50, *_47$$49, _49$$49, _50$$49, _48$$52, _51$$54, *_52$$56, _58$$56, _59$$56, itemExplode$$59, _53$$59, _54$$59, _55$$59, _56$$59, _57$$57, _60$$60, _61$$69, _62$$69, _63$$69, _64$$69, _65$$69, _66$$70, _67$$70, _68$$70, _69$$70, _70$$70;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&modelInstance);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&firstPrimaryKey);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&modelAlias);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&selectedColumns);
	ZVAL_UNDEF(&selectedColumn);
	ZVAL_UNDEF(&selectedModel);
	ZVAL_UNDEF(&selectedModels);
	ZVAL_UNDEF(&columnAlias);
	ZVAL_UNDEF(&modelColumnAlias);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&joinModel);
	ZVAL_UNDEF(&joinConditions);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&groupItems);
	ZVAL_UNDEF(&groupItem);
	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&orderItems);
	ZVAL_UNDEF(&orderItem);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&forUpdate);
	ZVAL_UNDEF(&distinct);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$17);
	ZVAL_UNDEF(&_6$$17);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_16$$25);
	ZVAL_UNDEF(&_14$$28);
	ZVAL_UNDEF(&_15$$28);
	ZVAL_UNDEF(&_22$$31);
	ZVAL_UNDEF(&_20$$33);
	ZVAL_UNDEF(&_21$$34);
	ZVAL_UNDEF(&_23$$35);
	ZVAL_UNDEF(&_24$$35);
	ZVAL_UNDEF(&_30$$36);
	ZVAL_UNDEF(&_31$$36);
	ZVAL_UNDEF(&_28$$38);
	ZVAL_UNDEF(&_29$$38);
	ZVAL_UNDEF(&_32$$40);
	ZVAL_UNDEF(&_33$$40);
	ZVAL_UNDEF(&_35$$43);
	ZVAL_UNDEF(&_36$$43);
	ZVAL_UNDEF(&_37$$44);
	ZVAL_UNDEF(&_38$$44);
	ZVAL_UNDEF(&_39$$45);
	ZVAL_UNDEF(&_40$$45);
	ZVAL_UNDEF(&_41$$46);
	ZVAL_UNDEF(&_42$$48);
	ZVAL_UNDEF(&_43$$51);
	ZVAL_UNDEF(&_44$$51);
	ZVAL_UNDEF(&_45$$51);
	ZVAL_UNDEF(&_46$$50);
	ZVAL_UNDEF(&_49$$49);
	ZVAL_UNDEF(&_50$$49);
	ZVAL_UNDEF(&_48$$52);
	ZVAL_UNDEF(&_51$$54);
	ZVAL_UNDEF(&_58$$56);
	ZVAL_UNDEF(&_59$$56);
	ZVAL_UNDEF(&itemExplode$$59);
	ZVAL_UNDEF(&_53$$59);
	ZVAL_UNDEF(&_54$$59);
	ZVAL_UNDEF(&_55$$59);
	ZVAL_UNDEF(&_56$$59);
	ZVAL_UNDEF(&_57$$57);
	ZVAL_UNDEF(&_60$$60);
	ZVAL_UNDEF(&_61$$69);
	ZVAL_UNDEF(&_62$$69);
	ZVAL_UNDEF(&_63$$69);
	ZVAL_UNDEF(&_64$$69);
	ZVAL_UNDEF(&_65$$69);
	ZVAL_UNDEF(&_66$$70);
	ZVAL_UNDEF(&_67$$70);
	ZVAL_UNDEF(&_68$$70);
	ZVAL_UNDEF(&_69$$70);
	ZVAL_UNDEF(&_70$$70);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
	}
	ZEPHIR_OBS_VAR(&models);
	zephir_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		if (!(zephir_fast_count_int(&models TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query", "phalcon/mvc/model/query/builder.zep", 989);
			return;
		}
	} else {
		if (!(zephir_is_true(&models))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query", "phalcon/mvc/model/query/builder.zep", 993);
			return;
		}
	}
	ZEPHIR_OBS_VAR(&conditions);
	zephir_read_property(&conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	if (zephir_is_numeric(&conditions)) {
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			if (zephir_fast_count_int(&models TSRMLS_CC) > 1) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot build the query. Invalid condition", "phalcon/mvc/model/query/builder.zep", 1006);
				return;
			}
			ZEPHIR_OBS_VAR(&model);
			zephir_array_fetch_long(&model, &models, 0, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1008 TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&model, &models);
		}
		ZEPHIR_INIT_VAR(&_1$$8);
		ZVAL_STRING(&_1$$8, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &dependencyInjector, "getshared", NULL, 0, &_1$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&modelInstance);
		zephir_fetch_safe_class(&_2$$8, &model);
		_3$$8 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$8), Z_STRLEN_P(&_2$$8), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&modelInstance, _3$$8);
		if (zephir_has_constructor(&modelInstance TSRMLS_CC)) {
			ZVAL_NULL(&_4$$8);
			ZEPHIR_CALL_METHOD(NULL, &modelInstance, "__construct", NULL, 0, &_4$$8, &dependencyInjector);
			zephir_check_call_status();
		}
		noPrimary = 1;
		ZEPHIR_CALL_METHOD(&primaryKeys, &metaData, "getprimarykeyattributes", NULL, 0, &modelInstance);
		zephir_check_call_status();
		if (zephir_fast_count_int(&primaryKeys TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(&firstPrimaryKey);
			if (zephir_array_isset_long_fetch(&firstPrimaryKey, &primaryKeys, 0, 0 TSRMLS_CC)) {
				if (ZEPHIR_GLOBAL(orm).column_renaming) {
					ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, &modelInstance);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&columnMap);
					ZVAL_NULL(&columnMap);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_VAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &firstPrimaryKey, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_VAR(&_5$$17);
						object_init_ex(&_5$$17, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(&_6$$17);
						ZEPHIR_CONCAT_SVS(&_6$$17, "Column '", &firstPrimaryKey, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_5$$17, "__construct", NULL, 4, &_6$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_5$$17, "phalcon/mvc/model/query/builder.zep", 1036 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &firstPrimaryKey);
				}
				ZEPHIR_CALL_METHOD(&_7$$13, this_ptr, "autoescape", NULL, 363, &model);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$13, this_ptr, "autoescape", NULL, 363, &attributeField);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_9$$13);
				ZEPHIR_CONCAT_VSVSV(&_9$$13, &_7$$13, ".", &_8$$13, " = ", &conditions);
				ZEPHIR_CPY_WRT(&conditions, &_9$$13);
				noPrimary = 0;
			}
		}
		if (noPrimary == 1) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined", "phalcon/mvc/model/query/builder.zep", 1051);
			return;
		}
	}
	ZEPHIR_OBS_VAR(&distinct);
	zephir_read_property(&distinct, this_ptr, SL("_distinct"), PH_NOISY_CC);
	_10 = Z_TYPE_P(&distinct) != IS_NULL;
	if (_10) {
		_10 = ((Z_TYPE_P(&distinct) == IS_TRUE || Z_TYPE_P(&distinct) == IS_FALSE) == 1);
	}
	if (_10) {
		ZEPHIR_INIT_VAR(&phql);
		if (zephir_is_true(&distinct)) {
			ZVAL_STRING(&phql, "SELECT DISTINCT ");
		} else {
			ZVAL_STRING(&phql, "SELECT ALL ");
		}
	} else {
		ZEPHIR_INIT_NVAR(&phql);
		ZVAL_STRING(&phql, "SELECT ");
	}
	ZEPHIR_OBS_VAR(&columns);
	zephir_read_property(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
	if (Z_TYPE_P(&columns) != IS_NULL) {
		if (Z_TYPE_P(&columns) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&selectedColumns);
			array_init(&selectedColumns);
			zephir_is_iterable(&columns, 0, "phalcon/mvc/model/query/builder.zep", 1083);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _12$$25, _13$$25, _11$$25)
			{
				ZEPHIR_INIT_NVAR(&columnAlias);
				if (_13$$25 != NULL) { 
					ZVAL_STR_COPY(&columnAlias, _13$$25);
				} else {
					ZVAL_LONG(&columnAlias, _12$$25);
				}
				ZEPHIR_INIT_NVAR(&column);
				ZVAL_COPY(&column, _11$$25);
				if (Z_TYPE_P(&columnAlias) == IS_LONG) {
					zephir_array_append(&selectedColumns, &column, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1077);
				} else {
					ZEPHIR_CALL_METHOD(&_14$$28, this_ptr, "autoescape", NULL, 363, &columnAlias);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_15$$28);
					ZEPHIR_CONCAT_VSV(&_15$$28, &column, " AS ", &_14$$28);
					zephir_array_append(&selectedColumns, &_15$$28, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1079);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&column);
			ZEPHIR_INIT_NVAR(&columnAlias);
			ZEPHIR_INIT_VAR(&_16$$25);
			zephir_fast_join_str(&_16$$25, SL(", "), &selectedColumns TSRMLS_CC);
			zephir_concat_self(&phql, &_16$$25 TSRMLS_CC);
		} else {
			zephir_concat_self(&phql, &columns TSRMLS_CC);
		}
	} else {
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&selectedColumns);
			array_init(&selectedColumns);
			zephir_is_iterable(&models, 0, "phalcon/mvc/model/query/builder.zep", 1106);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _18$$31, _19$$31, _17$$31)
			{
				ZEPHIR_INIT_NVAR(&modelColumnAlias);
				if (_19$$31 != NULL) { 
					ZVAL_STR_COPY(&modelColumnAlias, _19$$31);
				} else {
					ZVAL_LONG(&modelColumnAlias, _18$$31);
				}
				ZEPHIR_INIT_NVAR(&model);
				ZVAL_COPY(&model, _17$$31);
				ZEPHIR_INIT_NVAR(&selectedColumn);
				if (Z_TYPE_P(&modelColumnAlias) == IS_LONG) {
					ZEPHIR_CALL_METHOD(&_20$$33, this_ptr, "autoescape", NULL, 363, &model);
					zephir_check_call_status();
					ZEPHIR_CONCAT_VS(&selectedColumn, &_20$$33, ".*");
				} else {
					ZEPHIR_CALL_METHOD(&_21$$34, this_ptr, "autoescape", NULL, 363, &modelColumnAlias);
					zephir_check_call_status();
					ZEPHIR_CONCAT_VS(&selectedColumn, &_21$$34, ".*");
				}
				zephir_array_append(&selectedColumns, &selectedColumn, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1103);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&model);
			ZEPHIR_INIT_NVAR(&modelColumnAlias);
			ZEPHIR_INIT_VAR(&_22$$31);
			zephir_fast_join_str(&_22$$31, SL(", "), &selectedColumns TSRMLS_CC);
			zephir_concat_self(&phql, &_22$$31 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(&_23$$35, this_ptr, "autoescape", NULL, 363, &models);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_24$$35);
			ZEPHIR_CONCAT_VS(&_24$$35, &_23$$35, ".*");
			zephir_concat_self(&phql, &_24$$35 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&selectedModels);
		array_init(&selectedModels);
		zephir_is_iterable(&models, 0, "phalcon/mvc/model/query/builder.zep", 1129);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _26$$36, _27$$36, _25$$36)
		{
			ZEPHIR_INIT_NVAR(&modelAlias);
			if (_27$$36 != NULL) { 
				ZVAL_STR_COPY(&modelAlias, _27$$36);
			} else {
				ZVAL_LONG(&modelAlias, _26$$36);
			}
			ZEPHIR_INIT_NVAR(&model);
			ZVAL_COPY(&model, _25$$36);
			if (Z_TYPE_P(&modelAlias) == IS_STRING) {
				ZEPHIR_CALL_METHOD(&_28$$38, this_ptr, "autoescape", NULL, 363, &model);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_29$$38, this_ptr, "autoescape", NULL, 363, &modelAlias);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&selectedModel);
				ZEPHIR_CONCAT_VSV(&selectedModel, &_28$$38, " AS ", &_29$$38);
			} else {
				ZEPHIR_CALL_METHOD(&selectedModel, this_ptr, "autoescape", NULL, 363, &model);
				zephir_check_call_status();
			}
			zephir_array_append(&selectedModels, &selectedModel, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1126);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&model);
		ZEPHIR_INIT_NVAR(&modelAlias);
		ZEPHIR_INIT_VAR(&_30$$36);
		zephir_fast_join_str(&_30$$36, SL(", "), &selectedModels TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_31$$36);
		ZEPHIR_CONCAT_SV(&_31$$36, " FROM ", &_30$$36);
		zephir_concat_self(&phql, &_31$$36 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_32$$40, this_ptr, "autoescape", NULL, 363, &models);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_33$$40);
		ZEPHIR_CONCAT_SV(&_33$$40, " FROM ", &_32$$40);
		zephir_concat_self(&phql, &_33$$40 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&joins);
	zephir_read_property(&joins, this_ptr, SL("_joins"), PH_NOISY_CC);
	if (Z_TYPE_P(&joins) == IS_ARRAY) {
		zephir_is_iterable(&joins, 0, "phalcon/mvc/model/query/builder.zep", 1186);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&joins), _34$$41)
		{
			ZEPHIR_INIT_NVAR(&join);
			ZVAL_COPY(&join, _34$$41);
			ZEPHIR_OBS_NVAR(&joinModel);
			zephir_array_fetch_long(&joinModel, &join, 0, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1146 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&joinConditions);
			zephir_array_fetch_long(&joinConditions, &join, 1, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1151 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&joinAlias);
			zephir_array_fetch_long(&joinAlias, &join, 2, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1156 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&joinType);
			zephir_array_fetch_long(&joinType, &join, 3, PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1161 TSRMLS_CC);
			if (zephir_is_true(&joinType)) {
				ZEPHIR_CALL_METHOD(&_35$$43, this_ptr, "autoescape", NULL, 363, &joinModel);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_36$$43);
				ZEPHIR_CONCAT_SVSV(&_36$$43, " ", &joinType, " JOIN ", &_35$$43);
				zephir_concat_self(&phql, &_36$$43 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_37$$44, this_ptr, "autoescape", NULL, 363, &joinModel);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_38$$44);
				ZEPHIR_CONCAT_SV(&_38$$44, " JOIN ", &_37$$44);
				zephir_concat_self(&phql, &_38$$44 TSRMLS_CC);
			}
			if (zephir_is_true(&joinAlias)) {
				ZEPHIR_CALL_METHOD(&_39$$45, this_ptr, "autoescape", NULL, 363, &joinAlias);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_40$$45);
				ZEPHIR_CONCAT_SV(&_40$$45, " AS ", &_39$$45);
				zephir_concat_self(&phql, &_40$$45 TSRMLS_CC);
			}
			if (zephir_is_true(&joinConditions)) {
				ZEPHIR_INIT_LNVAR(_41$$46);
				ZEPHIR_CONCAT_SV(&_41$$46, " ON ", &joinConditions);
				zephir_concat_self(&phql, &_41$$46 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&join);
	}
	if (Z_TYPE_P(&conditions) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(&conditions))) {
			ZEPHIR_INIT_VAR(&_42$$48);
			ZEPHIR_CONCAT_SV(&_42$$48, " WHERE ", &conditions);
			zephir_concat_self(&phql, &_42$$48 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(&group);
	zephir_read_property(&group, this_ptr, SL("_group"), PH_NOISY_CC);
	if (Z_TYPE_P(&group) != IS_NULL) {
		if (Z_TYPE_P(&group) == IS_STRING) {
			if (zephir_memnstr_str(&group, SL(","), "phalcon/mvc/model/query/builder.zep", 1201)) {
				ZEPHIR_INIT_VAR(&_43$$51);
				ZEPHIR_INIT_VAR(&_44$$51);
				ZVAL_STRING(&_44$$51, " ");
				ZEPHIR_INIT_VAR(&_45$$51);
				ZVAL_STRING(&_45$$51, "");
				zephir_fast_str_replace(&_43$$51, &_44$$51, &_45$$51, &group TSRMLS_CC);
				ZEPHIR_CPY_WRT(&group, &_43$$51);
			}
			ZEPHIR_INIT_VAR(&_46$$50);
			zephir_fast_explode_str(&_46$$50, SL(","), &group, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(&group, &_46$$50);
		}
		ZEPHIR_INIT_VAR(&groupItems);
		array_init(&groupItems);
		zephir_is_iterable(&group, 0, "phalcon/mvc/model/query/builder.zep", 1213);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&group), _47$$49)
		{
			ZEPHIR_INIT_NVAR(&groupItem);
			ZVAL_COPY(&groupItem, _47$$49);
			ZEPHIR_CALL_METHOD(&_48$$52, this_ptr, "autoescape", NULL, 363, &groupItem);
			zephir_check_call_status();
			zephir_array_append(&groupItems, &_48$$52, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1210);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&groupItem);
		ZEPHIR_INIT_VAR(&_49$$49);
		zephir_fast_join_str(&_49$$49, SL(", "), &groupItems TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_50$$49);
		ZEPHIR_CONCAT_SV(&_50$$49, " GROUP BY ", &_49$$49);
		zephir_concat_self(&phql, &_50$$49 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&having);
	zephir_read_property(&having, this_ptr, SL("_having"), PH_NOISY_CC);
	if (Z_TYPE_P(&having) != IS_NULL) {
		if (!(ZEPHIR_IS_EMPTY(&having))) {
			ZEPHIR_INIT_VAR(&_51$$54);
			ZEPHIR_CONCAT_SV(&_51$$54, " HAVING ", &having);
			zephir_concat_self(&phql, &_51$$54 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(&order);
	zephir_read_property(&order, this_ptr, SL("_order"), PH_NOISY_CC);
	if (Z_TYPE_P(&order) != IS_NULL) {
		if (Z_TYPE_P(&order) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&orderItems);
			array_init(&orderItems);
			zephir_is_iterable(&order, 0, "phalcon/mvc/model/query/builder.zep", 1254);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&order), _52$$56)
			{
				ZEPHIR_INIT_NVAR(&orderItem);
				ZVAL_COPY(&orderItem, _52$$56);
				if (Z_TYPE_P(&orderItem) == IS_LONG) {
					zephir_array_append(&orderItems, &orderItem, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1238);
					continue;
				}
				if (zephir_memnstr_str(&orderItem, SL(" "), "phalcon/mvc/model/query/builder.zep", 1243) != 0) {
					ZEPHIR_INIT_NVAR(&itemExplode$$59);
					zephir_fast_explode_str(&itemExplode$$59, SL(" "), &orderItem, LONG_MAX TSRMLS_CC);
					zephir_array_fetch_long(&_54$$59, &itemExplode$$59, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query/builder.zep", 1246 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_53$$59, this_ptr, "autoescape", NULL, 363, &_54$$59);
					zephir_check_call_status();
					zephir_array_fetch_long(&_55$$59, &itemExplode$$59, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model/query/builder.zep", 1246 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_56$$59);
					ZEPHIR_CONCAT_VSV(&_56$$59, &_53$$59, " ", &_55$$59);
					zephir_array_append(&orderItems, &_56$$59, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1246);
					continue;
				}
				ZEPHIR_CALL_METHOD(&_57$$57, this_ptr, "autoescape", NULL, 363, &orderItem);
				zephir_check_call_status();
				zephir_array_append(&orderItems, &_57$$57, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1251);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&orderItem);
			ZEPHIR_INIT_VAR(&_58$$56);
			zephir_fast_join_str(&_58$$56, SL(", "), &orderItems TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_59$$56);
			ZEPHIR_CONCAT_SV(&_59$$56, " ORDER BY ", &_58$$56);
			zephir_concat_self(&phql, &_59$$56 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_60$$60);
			ZEPHIR_CONCAT_SV(&_60$$60, " ORDER BY ", &order);
			zephir_concat_self(&phql, &_60$$60 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(&limit);
	zephir_read_property(&limit, this_ptr, SL("_limit"), PH_NOISY_CC);
	if (Z_TYPE_P(&limit) != IS_NULL) {
		ZEPHIR_INIT_VAR(&number);
		ZVAL_NULL(&number);
		if (Z_TYPE_P(&limit) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&number);
			zephir_array_fetch_string(&number, &limit, SL("number"), PH_NOISY, "phalcon/mvc/model/query/builder.zep", 1269 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&offset);
			if (zephir_array_isset_string_fetch(&offset, &limit, SL("offset"), 0)) {
				if (!(zephir_is_numeric(&offset))) {
					ZEPHIR_INIT_NVAR(&offset);
					ZVAL_LONG(&offset, 0);
				}
			}
		} else {
			if (zephir_is_numeric(&limit)) {
				ZEPHIR_CPY_WRT(&number, &limit);
				ZEPHIR_OBS_NVAR(&offset);
				zephir_read_property(&offset, this_ptr, SL("_offset"), PH_NOISY_CC);
				if (Z_TYPE_P(&offset) != IS_NULL) {
					if (!(zephir_is_numeric(&offset))) {
						ZEPHIR_INIT_NVAR(&offset);
						ZVAL_LONG(&offset, 0);
					}
				}
			}
		}
		if (zephir_is_numeric(&number)) {
			zephir_concat_self_str(&phql, SL(" LIMIT :APL0:") TSRMLS_CC);
			ZVAL_LONG(&_61$$69, 10);
			ZEPHIR_CALL_FUNCTION(&_62$$69, "intval", NULL, 24, &number, &_61$$69);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_63$$69);
			ZVAL_STRING(&_63$$69, "APL0");
			zephir_update_property_array(this_ptr, SL("_bindParams"), &_63$$69, &_62$$69 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_64$$69);
			ZVAL_STRING(&_64$$69, "APL0");
			ZEPHIR_INIT_VAR(&_65$$69);
			ZVAL_LONG(&_65$$69, 1);
			zephir_update_property_array(this_ptr, SL("_bindTypes"), &_64$$69, &_65$$69 TSRMLS_CC);
			if (zephir_is_numeric(&offset)) {
				zephir_concat_self_str(&phql, SL(" OFFSET :APL1:") TSRMLS_CC);
				ZVAL_LONG(&_66$$70, 10);
				ZEPHIR_CALL_FUNCTION(&_67$$70, "intval", NULL, 24, &offset, &_66$$70);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_68$$70);
				ZVAL_STRING(&_68$$70, "APL1");
				zephir_update_property_array(this_ptr, SL("_bindParams"), &_68$$70, &_67$$70 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_69$$70);
				ZVAL_STRING(&_69$$70, "APL1");
				ZEPHIR_INIT_VAR(&_70$$70);
				ZVAL_LONG(&_70$$70, 1);
				zephir_update_property_array(this_ptr, SL("_bindTypes"), &_69$$70, &_70$$70 TSRMLS_CC);
			}
		}
	}
	zephir_read_property(&forUpdate, this_ptr, SL("_forUpdate"), PH_NOISY_CC | PH_READONLY);
	if (((Z_TYPE_P(&forUpdate) == IS_TRUE || Z_TYPE_P(&forUpdate) == IS_FALSE) == 1)) {
		if (zephir_is_true(&forUpdate)) {
			zephir_concat_self_str(&phql, SL(" FOR UPDATE") TSRMLS_CC);
		}
	}
	RETURN_CCTOR(&phql);

}

/**
 * Returns the query built
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery) {

	zval _2;
	zval query, bindParams, bindTypes, phql, dependencyInjector, _0, _1, _3, _4, _5$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&phql, this_ptr, "getphql", NULL, 364);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services", "phalcon/mvc/model/query/builder.zep", 1323);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, &phql);
	zephir_array_fast_append(&_2, &dependencyInjector);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Model\\Query");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "get", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_1);
	ZEPHIR_OBS_VAR(&bindParams);
	zephir_read_property(&bindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, &bindParams);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&bindTypes);
	zephir_read_property(&bindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, &bindTypes);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, this_ptr, SL("_sharedLock"), PH_NOISY_CC);
	if (((Z_TYPE_P(&_4) == IS_TRUE || Z_TYPE_P(&_4) == IS_FALSE) == 1)) {
		zephir_read_property(&_5$$6, this_ptr, SL("_sharedLock"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &query, "setsharedlock", NULL, 0, &_5$$6);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&query);

}

/**
 * Automatically escapes identifiers but only if they need to be escaped.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, autoescape) {

	zend_bool _0, _1;
	zval *identifier_param = NULL;
	zval identifier;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(&identifier, identifier_param);


	_0 = zephir_memnstr_str(&identifier, SL("["), "phalcon/mvc/model/query/builder.zep", 1358);
	if (!(_0)) {
		_0 = zephir_memnstr_str(&identifier, SL("."), "phalcon/mvc/model/query/builder.zep", 1358);
	}
	_1 = _0;
	if (!(_1)) {
		_1 = zephir_is_numeric(&identifier);
	}
	if (_1) {
		RETURN_CTOR(&identifier);
	}
	ZEPHIR_CONCAT_SVS(return_value, "[", &identifier, "]");
	RETURN_MM();

}

/**
 * Appends a BETWEEN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, _conditionBetween) {

	zval _6;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod, _5, _1$$3, _2$$3, _3$$3;
	zval clause, operator, expr, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &clause_param, &operator_param, &expr_param, &minimum, &maximum);

	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(&clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(&clause);
		ZVAL_EMPTY_STRING(&clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "or");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 138, &_2$$3, &operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/mvc/model/query/builder.zep", 1373 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &operator, &clause);
	ZEPHIR_CPY_WRT(&operatorMethod, &_4);
	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "AP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "AP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSVSVS(&_5, &expr, " BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	zephir_array_update_zval(&_6, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_6, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), &nextHiddenParam);
	RETURN_THIS();

}

/**
 * Appends a NOT BETWEEN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, _conditionNotBetween) {

	zval _6;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod, _5, _1$$3, _2$$3, _3$$3;
	zval clause, operator, expr, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &clause_param, &operator_param, &expr_param, &minimum, &maximum);

	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(&clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(&clause);
		ZVAL_EMPTY_STRING(&clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "or");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 138, &_2$$3, &operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/mvc/model/query/builder.zep", 1412 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &operator, &clause);
	ZEPHIR_CPY_WRT(&operatorMethod, &_4);
	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "AP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "AP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSVSVS(&_5, &expr, " NOT BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	zephir_array_update_zval(&_6, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_6, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), &nextHiddenParam);
	RETURN_THIS();

}

/**
 * Appends an IN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, _conditionIn) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenParam = 0;
	zval values;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *values_param = NULL, key, queryKey, value, bindKeys, bindParams, operatorMethod, _6, *_7, _10, _11, _12, _1$$3, _2$$3, _3$$3, _8$$5;
	zval clause, operator, expr, _4, _5$$4, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &clause_param, &operator_param, &expr_param, &values_param);

	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(&clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(&clause);
		ZVAL_EMPTY_STRING(&clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "or");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 138, &_2$$3, &operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/mvc/model/query/builder.zep", 1451 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &operator, &clause);
	ZEPHIR_CPY_WRT(&operatorMethod, &_4);
	if (!(zephir_fast_count_int(&values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VSV(&_5$$4, &expr, " != ", &expr);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_5$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(&_6);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/mvc/model/query/builder.zep", 1480);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _7)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _7);
		ZEPHIR_SINIT_NVAR(_8$$5);
		ZVAL_LONG(&_8$$5, hiddenParam);
		ZEPHIR_INIT_LNVAR(_9$$5);
		ZEPHIR_CONCAT_SV(&_9$$5, "AP", &_8$$5);
		ZEPHIR_CPY_WRT(&key, &_9$$5);
		ZEPHIR_INIT_NVAR(&queryKey);
		ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
		zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1471);
		zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
		hiddenParam++;
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_join_str(&_10, SL(", "), &bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_VSVS(&_11, &expr, " IN (", &_10, ")");
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_11, &bindParams);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_12);
	ZVAL_LONG(&_12, hiddenParam);
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), &_12);
	RETURN_THIS();

}

/**
 * Appends a NOT IN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, _conditionNotIn) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenParam = 0;
	zval values;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *values_param = NULL, key, queryKey, value, bindKeys, bindParams, operatorMethod, _6, *_7, _10, _11, _12, _1$$3, _2$$3, _3$$3, _8$$5;
	zval clause, operator, expr, _4, _5$$4, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &clause_param, &operator_param, &expr_param, &values_param);

	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(&clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(&clause);
		ZVAL_EMPTY_STRING(&clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_EMPTY_STRING(&operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
		ZVAL_EMPTY_STRING(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "or");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 138, &_2$$3, &operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/mvc/model/query/builder.zep", 1496 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &operator, &clause);
	ZEPHIR_CPY_WRT(&operatorMethod, &_4);
	if (!(zephir_fast_count_int(&values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VSV(&_5$$4, &expr, " != ", &expr);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_5$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(&_6);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/mvc/model/query/builder.zep", 1525);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _7)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _7);
		ZEPHIR_SINIT_NVAR(_8$$5);
		ZVAL_LONG(&_8$$5, hiddenParam);
		ZEPHIR_INIT_LNVAR(_9$$5);
		ZEPHIR_CONCAT_SV(&_9$$5, "AP", &_8$$5);
		ZEPHIR_CPY_WRT(&key, &_9$$5);
		ZEPHIR_INIT_NVAR(&queryKey);
		ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
		zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/mvc/model/query/builder.zep", 1516);
		zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
		hiddenParam++;
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_join_str(&_10, SL(", "), &bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_VSVS(&_11, &expr, " NOT IN (", &_10, ")");
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_11, &bindParams);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_12);
	ZVAL_LONG(&_12, hiddenParam);
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), &_12);
	RETURN_THIS();

}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setBindParams) {

	zend_bool merge;
	zval *bindParams_param = NULL, *merge_param = NULL, currentBindParams, _0$$4;
	zval bindParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		zephir_read_property(&currentBindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindParams, &bindParams);
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &bindParams);
		}
	} else {
		zephir_update_property_zval(this_ptr, SL("_bindParams"), &bindParams);
	}
	RETURN_THIS();

}

/**
 * Returns default bind params
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getBindParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_bindParams");

}

/**
 * Set default bind types
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setBindTypes) {

	zend_bool merge;
	zval *bindTypes_param = NULL, *merge_param = NULL, currentBindTypes, _0$$4;
	zval bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindTypes_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (UNEXPECTED(merge)) {
		zephir_read_property(&currentBindTypes, this_ptr, SL("_bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindTypes, &bindTypes);
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, SL("_bindTypes"), &bindTypes);
		}
	} else {
		zephir_update_property_zval(this_ptr, SL("_bindTypes"), &bindTypes);
	}
	RETURN_THIS();

}

/**
 * Returns default bind types
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getBindTypes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_bindTypes");

}

