
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *```php
 * $params = [
 *     "models"     => [
 *         Users::class,
 *     ],
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
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Builder, phalcon, mvc_model_query_builder, phalcon_mvc_model_query_builder_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("bindParams"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("bindTypes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("columns"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("conditions"), ZEND_ACC_PROTECTED);
	/**
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("distinct"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_query_builder_ce, SL("forUpdate"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("group"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("having"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_query_builder_ce, SL("hiddenParamNumber"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("joins"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("limit"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("models"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_query_builder_ce, SL("offset"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("order"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_query_builder_ce, SL("sharedLock"), 0, ZEND_ACC_PROTECTED);
	phalcon_mvc_model_query_builder_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Query_Builder;

	zend_class_implements(phalcon_mvc_model_query_builder_ce, 1, phalcon_mvc_model_query_builderinterface_ce);
	zend_class_implements(phalcon_mvc_model_query_builder_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query\Builder constructor
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct)
{
	zend_bool _7$$38;
	zval mergedConditions, mergedParams, mergedTypes;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, params_sub, *container = NULL, container_sub, __$null, conditions, columns, groupClause, havingClause, limitClause, forUpdate, sharedLock, orderClause, offsetClause, joinsClause, singleConditionArray, limit, offset, fromClause, singleCondition, singleParams, singleTypes, distinct, bind, bindTypes, *_0$$7, _1$$7, _6$$7, _2$$11, _3$$12, _4$$16, _5$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&container_sub);
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
	ZVAL_UNDEF(&singleCondition);
	ZVAL_UNDEF(&singleParams);
	ZVAL_UNDEF(&singleTypes);
	ZVAL_UNDEF(&distinct);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_2$$11);
	ZVAL_UNDEF(&_3$$12);
	ZVAL_UNDEF(&_4$$16);
	ZVAL_UNDEF(&_5$$17);
	ZVAL_UNDEF(&mergedConditions);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&mergedTypes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(params)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &params, &container);
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}
	if (!container) {
		container = &container_sub;
		container = &__$null;
	}


	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&conditions);
		if (zephir_array_isset_long_fetch(&conditions, params, 0, 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("conditions"), &conditions);
		} else {
			ZEPHIR_OBS_NVAR(&conditions);
			if (zephir_array_isset_string_fetch(&conditions, params, SL("conditions"), 0)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("conditions"), &conditions);
			}
		}
		if (Z_TYPE_P(&conditions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedConditions);
			array_init(&mergedConditions);
			ZEPHIR_INIT_VAR(&mergedParams);
			array_init(&mergedParams);
			ZEPHIR_INIT_VAR(&mergedTypes);
			array_init(&mergedTypes);
			zephir_is_iterable(&conditions, 0, "phalcon/Mvc/Model/Query/Builder.zep", 187);
			if (Z_TYPE_P(&conditions) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&conditions), _0$$7)
				{
					ZEPHIR_INIT_NVAR(&singleConditionArray);
					ZVAL_COPY(&singleConditionArray, _0$$7);
					if (Z_TYPE_P(&singleConditionArray) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&singleCondition);
						zephir_array_isset_long_fetch(&singleCondition, &singleConditionArray, 0, 0);
						ZEPHIR_OBS_NVAR(&singleParams);
						zephir_array_isset_long_fetch(&singleParams, &singleConditionArray, 1, 0);
						ZEPHIR_OBS_NVAR(&singleTypes);
						zephir_array_isset_long_fetch(&singleTypes, &singleConditionArray, 2, 0);
						if (Z_TYPE_P(&singleCondition) == IS_STRING) {
							zephir_array_append(&mergedConditions, &singleCondition, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 174);
						}
						if (Z_TYPE_P(&singleParams) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_2$$11);
							zephir_add_function(&_2$$11, &mergedParams, &singleParams);
							ZEPHIR_CPY_WRT(&mergedParams, &_2$$11);
						}
						if (Z_TYPE_P(&singleTypes) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_3$$12);
							zephir_add_function(&_3$$12, &mergedTypes, &singleTypes);
							ZEPHIR_CPY_WRT(&mergedTypes, &_3$$12);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &conditions, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_1$$7, &conditions, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_1$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&singleConditionArray, &conditions, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&singleConditionArray) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&singleCondition);
							zephir_array_isset_long_fetch(&singleCondition, &singleConditionArray, 0, 0);
							ZEPHIR_OBS_NVAR(&singleParams);
							zephir_array_isset_long_fetch(&singleParams, &singleConditionArray, 1, 0);
							ZEPHIR_OBS_NVAR(&singleTypes);
							zephir_array_isset_long_fetch(&singleTypes, &singleConditionArray, 2, 0);
							if (Z_TYPE_P(&singleCondition) == IS_STRING) {
								zephir_array_append(&mergedConditions, &singleCondition, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 174);
							}
							if (Z_TYPE_P(&singleParams) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_4$$16);
								zephir_add_function(&_4$$16, &mergedParams, &singleParams);
								ZEPHIR_CPY_WRT(&mergedParams, &_4$$16);
							}
							if (Z_TYPE_P(&singleTypes) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_5$$17);
								zephir_add_function(&_5$$17, &mergedTypes, &singleTypes);
								ZEPHIR_CPY_WRT(&mergedTypes, &_5$$17);
							}
						}
					ZEPHIR_CALL_METHOD(NULL, &conditions, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&singleConditionArray);
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_fast_join_str(&_6$$7, SL(" AND "), &mergedConditions);
			zephir_update_property_zval(this_ptr, ZEND_STRL("conditions"), &_6$$7);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &mergedParams);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &mergedTypes);
		}
		ZEPHIR_OBS_VAR(&bind);
		if (zephir_array_isset_string_fetch(&bind, params, SL("bind"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &bind);
		}
		ZEPHIR_OBS_VAR(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SL("bindTypes"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &bindTypes);
		}
		ZEPHIR_OBS_VAR(&distinct);
		if (zephir_array_isset_string_fetch(&distinct, params, SL("distinct"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("distinct"), &distinct);
		}
		ZEPHIR_OBS_VAR(&fromClause);
		if (zephir_array_isset_string_fetch(&fromClause, params, SL("models"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &fromClause);
		}
		ZEPHIR_OBS_VAR(&columns);
		if (zephir_array_isset_string_fetch(&columns, params, SL("columns"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &columns);
		}
		ZEPHIR_OBS_VAR(&joinsClause);
		if (zephir_array_isset_string_fetch(&joinsClause, params, SL("joins"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("joins"), &joinsClause);
		}
		ZEPHIR_OBS_VAR(&groupClause);
		if (zephir_array_isset_string_fetch(&groupClause, params, SL("group"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "groupby", NULL, 0, &groupClause);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&havingClause);
		if (zephir_array_isset_string_fetch(&havingClause, params, SL("having"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("having"), &havingClause);
		}
		ZEPHIR_OBS_VAR(&orderClause);
		if (zephir_array_isset_string_fetch(&orderClause, params, SL("order"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("order"), &orderClause);
		}
		ZEPHIR_OBS_VAR(&limitClause);
		if (zephir_array_isset_string_fetch(&limitClause, params, SL("limit"), 0)) {
			if (Z_TYPE_P(&limitClause) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(&limit);
				if (zephir_array_isset_long_fetch(&limit, &limitClause, 0, 0)) {
					if (Z_TYPE_P(&limit) == IS_LONG) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("limit"), &limit);
					}
					ZEPHIR_OBS_VAR(&offset);
					if (zephir_array_isset_long_fetch(&offset, &limitClause, 1, 0)) {
						if (Z_TYPE_P(&offset) == IS_LONG) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("offset"), &offset);
						}
					}
				} else {
					zephir_update_property_zval(this_ptr, ZEND_STRL("limit"), &limitClause);
				}
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("limit"), &limitClause);
			}
		}
		if (zephir_array_isset_string_fetch(&offsetClause, params, SL("offset"), 1)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("offset"), &offsetClause);
		}
		if (zephir_array_isset_string_fetch(&forUpdate, params, SL("for_update"), 1)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("forUpdate"), &forUpdate);
		}
		if (zephir_array_isset_string_fetch(&sharedLock, params, SL("shared_lock"), 1)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("sharedLock"), &sharedLock);
		}
	} else {
		_7$$38 = Z_TYPE_P(params) == IS_STRING;
		if (_7$$38) {
			_7$$38 = !ZEPHIR_IS_STRING_IDENTICAL(params, "");
		}
		if (_7$$38) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("conditions"), params);
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	ZEPHIR_MM_RESTORE();
}

/**
 * Add a model to take part of the query
 *
 *```php
 * // Load data from models Robots
 * $builder->addFrom(
 *     Robots::class
 * );
 *
 * // Load data from model 'Robots' using 'r' as alias in PHQL
 * $builder->addFrom(
 *     Robots::class,
 *     "r"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, addFrom)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model_param = NULL, *alias_param = NULL, models, currentModel, _0, _1$$4;
	zval model, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&currentModel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &model_param, &alias_param);
	zephir_get_strval(&model, model_param);
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
	} else {
		zephir_get_strval(&alias, alias_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	if (Z_TYPE_P(&models) != IS_ARRAY) {
		if (Z_TYPE_P(&models) != IS_NULL) {
			ZEPHIR_CPY_WRT(&currentModel, &models);
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0);
			zephir_array_fast_append(&_1$$4, &currentModel);
			ZEPHIR_CPY_WRT(&models, &_1$$4);
		} else {
			ZEPHIR_INIT_NVAR(&models);
			array_init(&models);
		}
	}
	_2 = 1 == 1;
	if (_2) {
		_2 = !ZEPHIR_IS_NULL(&alias);
	}
	if (_2) {
		zephir_array_update_zval(&models, &alias, &model, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_append(&models, &model, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 342);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &models);
	RETURN_THIS();
}

/**
 * Appends a condition to the current HAVING conditions clause using a AND operator
 *
 *```php
 * $builder->andHaving("SUM(Robots.price) > 0");
 *
 * $builder->andHaving(
 *     "SUM(Robots.price) > :sum:",
 *     [
 *         "sum" => 100,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andHaving)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams_param, &bindTypes_param);
	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
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
	zephir_read_property(&currentConditions, this_ptr, ZEND_STRL("having"), PH_NOISY_CC);
	if (zephir_is_true(&currentConditions)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "(", &currentConditions, ") AND (", &conditions, ")");
		zephir_get_strval(&conditions, &_0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "having", NULL, 0, &conditions, &bindParams, &bindTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends a condition to the current WHERE conditions using a AND operator
 *
 *```php
 * $builder->andWhere("name = 'Peter'");
 *
 * $builder->andWhere(
 *     "name = :name: AND id > :id:",
 *     [
 *         "name" => "Peter",
 *         "id"   => 100,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams_param, &bindTypes_param);
	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
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
	zephir_read_property(&currentConditions, this_ptr, ZEND_STRL("conditions"), PH_NOISY_CC);
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
 * Automatically escapes identifiers but only if they need to be escaped.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, autoescape)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *identifier_param = NULL;
	zval identifier;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(identifier)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);
	zephir_get_strval(&identifier, identifier_param);


	_0 = zephir_memnstr_str(&identifier, SL("["), "phalcon/Mvc/Model/Query/Builder.zep", 416);
	if (!(_0)) {
		_0 = zephir_memnstr_str(&identifier, SL("."), "phalcon/Mvc/Model/Query/Builder.zep", 416);
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
 * Appends a BETWEEN condition to the current HAVING conditions clause
 *
 *```php
 * $builder->betweenHaving("SUM(Robots.price)", 100.25, 200.50);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenHaving)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Having");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionbetween", NULL, 0, &_0, &operator, &expr, minimum, maximum);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends a BETWEEN condition to the current WHERE conditions
 *
 *```php
 * $builder->betweenWhere("price", 100.25, 200.50);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Where");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionbetween", NULL, 0, &_0, &operator, &expr, minimum, maximum);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the columns to be queried
 *
 *```php
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
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns)
{
	zval *columns, columns_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(columns)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &columns);


	zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), columns);
	RETURN_THISW();
}

/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 *
 *```php
 * $builder->distinct("status");
 * $builder->distinct(null);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, distinct)
{
	zval *distinct, distinct_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&distinct_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(distinct)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &distinct);


	zephir_update_property_zval(this_ptr, ZEND_STRL("distinct"), distinct);
	RETURN_THISW();
}

/**
 * Sets a FOR UPDATE clause
 *
 *```php
 * $builder->forUpdate(true);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, forUpdate)
{
	zval *forUpdate_param = NULL, __$true, __$false;
	zend_bool forUpdate;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(forUpdate)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &forUpdate_param);
	forUpdate = zephir_get_boolval(forUpdate_param);


	if (forUpdate) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forUpdate"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("forUpdate"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the models who makes part of the query
 *
 *```php
 * $builder->from(
 *     Robots::class
 * );
 *
 * $builder->from(
 *     [
 *         Robots::class,
 *         RobotsParts::class,
 *     ]
 * );
 *
 * $builder->from(
 *     [
 *         "r"  => Robots::class,
 *         "rp" => RobotsParts::class,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from)
{
	zval *models, models_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&models_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(models)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &models);


	zephir_update_property_zval(this_ptr, ZEND_STRL("models"), models);
	RETURN_THISW();
}

/**
 * Returns default bind params
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getBindParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "bindParams");
}

/**
 * Returns default bind types
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getBindTypes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "bindTypes");
}

/**
 * Return the columns to be queried
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "columns");
}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "container");
}

/**
 * Returns SELECT DISTINCT / SELECT ALL flag
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDistinct)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "distinct");
}

/**
 * Return the models who makes part of the query
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "models");
}

/**
 * Returns the GROUP BY clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "group");
}

/**
 * Return the current having clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "having");
}

/**
 * Return join parts of the query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getJoins)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "joins");
}

/**
 * Returns the current LIMIT clause
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "limit");
}

/**
 * Returns the models involved in the query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getModels)
{
	zend_bool _1;
	zval models, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	_1 = Z_TYPE_P(&models) == IS_ARRAY;
	if (_1) {
		_1 = zephir_fast_count_int(&models) == 1;
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_arr_ce, "first", &_2, 264, &models);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&models);
}

/**
 * Returns the current OFFSET clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOffset)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "offset");
}

/**
 * Returns the set ORDER BY clause
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "order");
}

/**
 * Returns a PHQL statement built based on the builder parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql)
{
	zend_string *_13$$26, *_22$$35, *_33$$43;
	zend_ulong _12$$26, _21$$35, _32$$43;
	zval _3$$8;
	zend_bool noPrimary = 0, _87$$86;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, container, models, conditions, model, metaData, modelInstance, primaryKeys, firstPrimaryKey, columnMap, modelAlias, attributeField, phql, column, columns, selectedColumns, selectedColumn, selectedModel, selectedModels, columnAlias, modelColumnAlias, joins, join, joinModel, joinConditions, joinAlias, joinType, group, groupItems, groupItem, having, order, orderItems, orderItem, limit, number, offset, forUpdate, distinct, _0, _2$$8, _4$$17, _5$$17, _6$$19, _7$$13, _8$$13, _9$$13, *_10$$26, _11$$26, _18$$26, _14$$29, _15$$29, _16$$32, _17$$32, *_19$$35, _20$$35, _27$$35, _23$$37, _24$$38, _25$$40, _26$$41, _28$$42, _29$$42, *_30$$43, _31$$43, _38$$43, _39$$43, _34$$45, _35$$45, _36$$48, _37$$48, _40$$50, _41$$50, *_42$$51, _43$$51, _44$$53, _45$$53, _46$$54, _47$$54, _48$$55, _49$$55, _50$$56, _51$$58, _52$$58, _53$$59, _54$$59, _55$$60, _56$$60, _57$$61, _58$$63, *_59$$64, _60$$64, _63$$64, _64$$64, _61$$65, _62$$66, _65$$68, *_66$$70, _67$$70, _78$$70, _79$$70, itemExplode$$73, _68$$73, _69$$73, _70$$73, _71$$73, _72$$71, itemExplode$$76, _73$$76, _74$$76, _75$$76, _76$$76, _77$$74, _80$$77, _81$$83, _82$$86, _83$$86, _84$$86, _85$$86, _86$$86, _88$$87, _89$$87, _90$$87, _91$$87, _92$$87;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&container);
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_4$$17);
	ZVAL_UNDEF(&_5$$17);
	ZVAL_UNDEF(&_6$$19);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_11$$26);
	ZVAL_UNDEF(&_18$$26);
	ZVAL_UNDEF(&_14$$29);
	ZVAL_UNDEF(&_15$$29);
	ZVAL_UNDEF(&_16$$32);
	ZVAL_UNDEF(&_17$$32);
	ZVAL_UNDEF(&_20$$35);
	ZVAL_UNDEF(&_27$$35);
	ZVAL_UNDEF(&_23$$37);
	ZVAL_UNDEF(&_24$$38);
	ZVAL_UNDEF(&_25$$40);
	ZVAL_UNDEF(&_26$$41);
	ZVAL_UNDEF(&_28$$42);
	ZVAL_UNDEF(&_29$$42);
	ZVAL_UNDEF(&_31$$43);
	ZVAL_UNDEF(&_38$$43);
	ZVAL_UNDEF(&_39$$43);
	ZVAL_UNDEF(&_34$$45);
	ZVAL_UNDEF(&_35$$45);
	ZVAL_UNDEF(&_36$$48);
	ZVAL_UNDEF(&_37$$48);
	ZVAL_UNDEF(&_40$$50);
	ZVAL_UNDEF(&_41$$50);
	ZVAL_UNDEF(&_43$$51);
	ZVAL_UNDEF(&_44$$53);
	ZVAL_UNDEF(&_45$$53);
	ZVAL_UNDEF(&_46$$54);
	ZVAL_UNDEF(&_47$$54);
	ZVAL_UNDEF(&_48$$55);
	ZVAL_UNDEF(&_49$$55);
	ZVAL_UNDEF(&_50$$56);
	ZVAL_UNDEF(&_51$$58);
	ZVAL_UNDEF(&_52$$58);
	ZVAL_UNDEF(&_53$$59);
	ZVAL_UNDEF(&_54$$59);
	ZVAL_UNDEF(&_55$$60);
	ZVAL_UNDEF(&_56$$60);
	ZVAL_UNDEF(&_57$$61);
	ZVAL_UNDEF(&_58$$63);
	ZVAL_UNDEF(&_60$$64);
	ZVAL_UNDEF(&_63$$64);
	ZVAL_UNDEF(&_64$$64);
	ZVAL_UNDEF(&_61$$65);
	ZVAL_UNDEF(&_62$$66);
	ZVAL_UNDEF(&_65$$68);
	ZVAL_UNDEF(&_67$$70);
	ZVAL_UNDEF(&_78$$70);
	ZVAL_UNDEF(&_79$$70);
	ZVAL_UNDEF(&itemExplode$$73);
	ZVAL_UNDEF(&_68$$73);
	ZVAL_UNDEF(&_69$$73);
	ZVAL_UNDEF(&_70$$73);
	ZVAL_UNDEF(&_71$$73);
	ZVAL_UNDEF(&_72$$71);
	ZVAL_UNDEF(&itemExplode$$76);
	ZVAL_UNDEF(&_73$$76);
	ZVAL_UNDEF(&_74$$76);
	ZVAL_UNDEF(&_75$$76);
	ZVAL_UNDEF(&_76$$76);
	ZVAL_UNDEF(&_77$$74);
	ZVAL_UNDEF(&_80$$77);
	ZVAL_UNDEF(&_81$$83);
	ZVAL_UNDEF(&_82$$86);
	ZVAL_UNDEF(&_83$$86);
	ZVAL_UNDEF(&_84$$86);
	ZVAL_UNDEF(&_85$$86);
	ZVAL_UNDEF(&_86$$86);
	ZVAL_UNDEF(&_88$$87);
	ZVAL_UNDEF(&_89$$87);
	ZVAL_UNDEF(&_90$$87);
	ZVAL_UNDEF(&_91$$87);
	ZVAL_UNDEF(&_92$$87);
	ZVAL_UNDEF(&_3$$8);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_1, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		if (UNEXPECTED(!(zephir_fast_count_int(&models)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query", "phalcon/Mvc/Model/Query/Builder.zep", 677);
			return;
		}
	} else {
		if (UNEXPECTED(!zephir_is_true(&models))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query", "phalcon/Mvc/Model/Query/Builder.zep", 683);
			return;
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("conditions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&conditions, &_0);
	if (zephir_is_numeric(&conditions)) {
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			if (UNEXPECTED(zephir_fast_count_int(&models) > 1)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Cannot build the query. Invalid condition", "phalcon/Mvc/Model/Query/Builder.zep", 698);
				return;
			}
			ZEPHIR_OBS_VAR(&model);
			zephir_array_fetch_long(&model, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 701);
		} else {
			ZEPHIR_CPY_WRT(&model, &models);
		}
		ZEPHIR_INIT_VAR(&_2$$8);
		ZVAL_STRING(&_2$$8, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &container, "getshared", NULL, 0, &_2$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$8);
		zephir_create_array(&_3$$8, 2, 0);
		zephir_array_fast_append(&_3$$8, &__$null);
		zephir_array_fast_append(&_3$$8, &container);
		ZEPHIR_INIT_VAR(&modelInstance);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&modelInstance, &model, &_3$$8);
		zephir_check_call_status();
		noPrimary = 1;
		ZEPHIR_CALL_METHOD(&primaryKeys, &metaData, "getprimarykeyattributes", NULL, 0, &modelInstance);
		zephir_check_call_status();
		if (zephir_fast_count_int(&primaryKeys)) {
			ZEPHIR_OBS_VAR(&firstPrimaryKey);
			if (zephir_array_isset_long_fetch(&firstPrimaryKey, &primaryKeys, 0, 0)) {
				if (ZEPHIR_GLOBAL(orm).column_renaming) {
					ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, &modelInstance);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&columnMap);
					ZVAL_NULL(&columnMap);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_VAR(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &firstPrimaryKey, 0)))) {
						ZEPHIR_INIT_VAR(&_4$$17);
						object_init_ex(&_4$$17, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_VAR(&_5$$17);
						ZEPHIR_CONCAT_SVS(&_5$$17, "Column '", &firstPrimaryKey, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_4$$17, "__construct", NULL, 8, &_5$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_4$$17, "phalcon/Mvc/Model/Query/Builder.zep", 737);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &firstPrimaryKey);
				}
				if (Z_TYPE_P(&conditions) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_6$$19);
					ZEPHIR_CONCAT_SVS(&_6$$19, "'", &conditions, "'");
					ZEPHIR_CPY_WRT(&conditions, &_6$$19);
				}
				ZEPHIR_CALL_METHOD(&_7$$13, this_ptr, "autoescape", NULL, 483, &model);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$13, this_ptr, "autoescape", NULL, 483, &attributeField);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_9$$13);
				ZEPHIR_CONCAT_VSVSV(&_9$$13, &_7$$13, ".", &_8$$13, " = ", &conditions);
				ZEPHIR_CPY_WRT(&conditions, &_9$$13);
				noPrimary = 0;
			}
		}
		if (UNEXPECTED(noPrimary)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined", "phalcon/Mvc/Model/Query/Builder.zep", 764);
			return;
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("distinct"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&distinct, &_0);
	if (((Z_TYPE_P(&distinct) == IS_TRUE || Z_TYPE_P(&distinct) == IS_FALSE) == 1)) {
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columns"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columns, &_0);
	if (Z_TYPE_P(&columns) != IS_NULL) {
		if (Z_TYPE_P(&columns) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&selectedColumns);
			array_init(&selectedColumns);
			zephir_is_iterable(&columns, 0, "phalcon/Mvc/Model/Query/Builder.zep", 797);
			if (Z_TYPE_P(&columns) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _12$$26, _13$$26, _10$$26)
				{
					ZEPHIR_INIT_NVAR(&columnAlias);
					if (_13$$26 != NULL) { 
						ZVAL_STR_COPY(&columnAlias, _13$$26);
					} else {
						ZVAL_LONG(&columnAlias, _12$$26);
					}
					ZEPHIR_INIT_NVAR(&column);
					ZVAL_COPY(&column, _10$$26);
					if (Z_TYPE_P(&columnAlias) == IS_LONG) {
						zephir_array_append(&selectedColumns, &column, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 791);
					} else {
						ZEPHIR_CALL_METHOD(&_14$$29, this_ptr, "autoescape", NULL, 483, &columnAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_15$$29);
						ZEPHIR_CONCAT_VSV(&_15$$29, &column, " AS ", &_14$$29);
						zephir_array_append(&selectedColumns, &_15$$29, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 793);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_11$$26, &columns, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_11$$26)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&columnAlias, &columns, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnAlias) == IS_LONG) {
							zephir_array_append(&selectedColumns, &column, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 791);
						} else {
							ZEPHIR_CALL_METHOD(&_16$$32, this_ptr, "autoescape", NULL, 483, &columnAlias);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_17$$32);
							ZEPHIR_CONCAT_VSV(&_17$$32, &column, " AS ", &_16$$32);
							zephir_array_append(&selectedColumns, &_17$$32, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 793);
						}
					ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&column);
			ZEPHIR_INIT_NVAR(&columnAlias);
			ZEPHIR_INIT_VAR(&_18$$26);
			zephir_fast_join_str(&_18$$26, SL(", "), &selectedColumns);
			zephir_concat_self(&phql, &_18$$26);
		} else {
			zephir_concat_self(&phql, &columns);
		}
	} else {
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&selectedColumns);
			array_init(&selectedColumns);
			zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query/Builder.zep", 818);
			if (Z_TYPE_P(&models) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _21$$35, _22$$35, _19$$35)
				{
					ZEPHIR_INIT_NVAR(&modelColumnAlias);
					if (_22$$35 != NULL) { 
						ZVAL_STR_COPY(&modelColumnAlias, _22$$35);
					} else {
						ZVAL_LONG(&modelColumnAlias, _21$$35);
					}
					ZEPHIR_INIT_NVAR(&model);
					ZVAL_COPY(&model, _19$$35);
					ZEPHIR_INIT_NVAR(&selectedColumn);
					if (Z_TYPE_P(&modelColumnAlias) == IS_LONG) {
						ZEPHIR_CALL_METHOD(&_23$$37, this_ptr, "autoescape", NULL, 483, &model);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VS(&selectedColumn, &_23$$37, ".*");
					} else {
						ZEPHIR_CALL_METHOD(&_24$$38, this_ptr, "autoescape", NULL, 483, &modelColumnAlias);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VS(&selectedColumn, &_24$$38, ".*");
					}
					zephir_array_append(&selectedColumns, &selectedColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 815);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &models, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_20$$35, &models, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_20$$35)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&modelColumnAlias, &models, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&model, &models, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&selectedColumn);
						if (Z_TYPE_P(&modelColumnAlias) == IS_LONG) {
							ZEPHIR_CALL_METHOD(&_25$$40, this_ptr, "autoescape", NULL, 483, &model);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VS(&selectedColumn, &_25$$40, ".*");
						} else {
							ZEPHIR_CALL_METHOD(&_26$$41, this_ptr, "autoescape", NULL, 483, &modelColumnAlias);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VS(&selectedColumn, &_26$$41, ".*");
						}
						zephir_array_append(&selectedColumns, &selectedColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 815);
					ZEPHIR_CALL_METHOD(NULL, &models, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&model);
			ZEPHIR_INIT_NVAR(&modelColumnAlias);
			ZEPHIR_INIT_VAR(&_27$$35);
			zephir_fast_join_str(&_27$$35, SL(", "), &selectedColumns);
			zephir_concat_self(&phql, &_27$$35);
		} else {
			ZEPHIR_CALL_METHOD(&_28$$42, this_ptr, "autoescape", NULL, 483, &models);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_29$$42);
			ZEPHIR_CONCAT_VS(&_29$$42, &_28$$42, ".*");
			zephir_concat_self(&phql, &_29$$42);
		}
	}
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&selectedModels);
		array_init(&selectedModels);
		zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query/Builder.zep", 840);
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _32$$43, _33$$43, _30$$43)
			{
				ZEPHIR_INIT_NVAR(&modelAlias);
				if (_33$$43 != NULL) { 
					ZVAL_STR_COPY(&modelAlias, _33$$43);
				} else {
					ZVAL_LONG(&modelAlias, _32$$43);
				}
				ZEPHIR_INIT_NVAR(&model);
				ZVAL_COPY(&model, _30$$43);
				if (Z_TYPE_P(&modelAlias) == IS_STRING) {
					ZEPHIR_CALL_METHOD(&_34$$45, this_ptr, "autoescape", NULL, 483, &model);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_35$$45, this_ptr, "autoescape", NULL, 483, &modelAlias);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&selectedModel);
					ZEPHIR_CONCAT_VSV(&selectedModel, &_34$$45, " AS ", &_35$$45);
				} else {
					ZEPHIR_CALL_METHOD(&selectedModel, this_ptr, "autoescape", NULL, 483, &model);
					zephir_check_call_status();
				}
				zephir_array_append(&selectedModels, &selectedModel, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 837);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &models, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_31$$43, &models, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_31$$43)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&modelAlias, &models, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&model, &models, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&modelAlias) == IS_STRING) {
						ZEPHIR_CALL_METHOD(&_36$$48, this_ptr, "autoescape", NULL, 483, &model);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_37$$48, this_ptr, "autoescape", NULL, 483, &modelAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&selectedModel);
						ZEPHIR_CONCAT_VSV(&selectedModel, &_36$$48, " AS ", &_37$$48);
					} else {
						ZEPHIR_CALL_METHOD(&selectedModel, this_ptr, "autoescape", NULL, 483, &model);
						zephir_check_call_status();
					}
					zephir_array_append(&selectedModels, &selectedModel, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 837);
				ZEPHIR_CALL_METHOD(NULL, &models, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&model);
		ZEPHIR_INIT_NVAR(&modelAlias);
		ZEPHIR_INIT_VAR(&_38$$43);
		zephir_fast_join_str(&_38$$43, SL(", "), &selectedModels);
		ZEPHIR_INIT_VAR(&_39$$43);
		ZEPHIR_CONCAT_SV(&_39$$43, " FROM ", &_38$$43);
		zephir_concat_self(&phql, &_39$$43);
	} else {
		ZEPHIR_CALL_METHOD(&_40$$50, this_ptr, "autoescape", NULL, 483, &models);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_41$$50);
		ZEPHIR_CONCAT_SV(&_41$$50, " FROM ", &_40$$50);
		zephir_concat_self(&phql, &_41$$50);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("joins"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&joins, &_0);
	if (Z_TYPE_P(&joins) == IS_ARRAY) {
		zephir_is_iterable(&joins, 0, "phalcon/Mvc/Model/Query/Builder.zep", 895);
		if (Z_TYPE_P(&joins) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&joins), _42$$51)
			{
				ZEPHIR_INIT_NVAR(&join);
				ZVAL_COPY(&join, _42$$51);
				ZEPHIR_OBS_NVAR(&joinModel);
				zephir_array_fetch_long(&joinModel, &join, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 855);
				ZEPHIR_OBS_NVAR(&joinConditions);
				zephir_array_fetch_long(&joinConditions, &join, 1, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 860);
				ZEPHIR_OBS_NVAR(&joinAlias);
				zephir_array_fetch_long(&joinAlias, &join, 2, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 865);
				ZEPHIR_OBS_NVAR(&joinType);
				zephir_array_fetch_long(&joinType, &join, 3, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 870);
				if (zephir_is_true(&joinType)) {
					ZEPHIR_CALL_METHOD(&_44$$53, this_ptr, "autoescape", NULL, 483, &joinModel);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_45$$53);
					ZEPHIR_CONCAT_SVSV(&_45$$53, " ", &joinType, " JOIN ", &_44$$53);
					zephir_concat_self(&phql, &_45$$53);
				} else {
					ZEPHIR_CALL_METHOD(&_46$$54, this_ptr, "autoescape", NULL, 483, &joinModel);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_47$$54);
					ZEPHIR_CONCAT_SV(&_47$$54, " JOIN ", &_46$$54);
					zephir_concat_self(&phql, &_47$$54);
				}
				if (zephir_is_true(&joinAlias)) {
					ZEPHIR_CALL_METHOD(&_48$$55, this_ptr, "autoescape", NULL, 483, &joinAlias);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_49$$55);
					ZEPHIR_CONCAT_SV(&_49$$55, " AS ", &_48$$55);
					zephir_concat_self(&phql, &_49$$55);
				}
				if (zephir_is_true(&joinConditions)) {
					ZEPHIR_INIT_NVAR(&_50$$56);
					ZEPHIR_CONCAT_SV(&_50$$56, " ON ", &joinConditions);
					zephir_concat_self(&phql, &_50$$56);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &joins, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_43$$51, &joins, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_43$$51)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&join, &joins, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&joinModel);
					zephir_array_fetch_long(&joinModel, &join, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 855);
					ZEPHIR_OBS_NVAR(&joinConditions);
					zephir_array_fetch_long(&joinConditions, &join, 1, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 860);
					ZEPHIR_OBS_NVAR(&joinAlias);
					zephir_array_fetch_long(&joinAlias, &join, 2, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 865);
					ZEPHIR_OBS_NVAR(&joinType);
					zephir_array_fetch_long(&joinType, &join, 3, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 870);
					if (zephir_is_true(&joinType)) {
						ZEPHIR_CALL_METHOD(&_51$$58, this_ptr, "autoescape", NULL, 483, &joinModel);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_52$$58);
						ZEPHIR_CONCAT_SVSV(&_52$$58, " ", &joinType, " JOIN ", &_51$$58);
						zephir_concat_self(&phql, &_52$$58);
					} else {
						ZEPHIR_CALL_METHOD(&_53$$59, this_ptr, "autoescape", NULL, 483, &joinModel);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_54$$59);
						ZEPHIR_CONCAT_SV(&_54$$59, " JOIN ", &_53$$59);
						zephir_concat_self(&phql, &_54$$59);
					}
					if (zephir_is_true(&joinAlias)) {
						ZEPHIR_CALL_METHOD(&_55$$60, this_ptr, "autoescape", NULL, 483, &joinAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_56$$60);
						ZEPHIR_CONCAT_SV(&_56$$60, " AS ", &_55$$60);
						zephir_concat_self(&phql, &_56$$60);
					}
					if (zephir_is_true(&joinConditions)) {
						ZEPHIR_INIT_NVAR(&_57$$61);
						ZEPHIR_CONCAT_SV(&_57$$61, " ON ", &joinConditions);
						zephir_concat_self(&phql, &_57$$61);
					}
				ZEPHIR_CALL_METHOD(NULL, &joins, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&join);
	}
	if (Z_TYPE_P(&conditions) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(&conditions))) {
			ZEPHIR_INIT_VAR(&_58$$63);
			ZEPHIR_CONCAT_SV(&_58$$63, " WHERE ", &conditions);
			zephir_concat_self(&phql, &_58$$63);
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&group, &_0);
	if (!(ZEPHIR_IS_EMPTY(&group))) {
		ZEPHIR_INIT_VAR(&groupItems);
		array_init(&groupItems);
		zephir_is_iterable(&group, 0, "phalcon/Mvc/Model/Query/Builder.zep", 915);
		if (Z_TYPE_P(&group) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&group), _59$$64)
			{
				ZEPHIR_INIT_NVAR(&groupItem);
				ZVAL_COPY(&groupItem, _59$$64);
				ZEPHIR_CALL_METHOD(&_61$$65, this_ptr, "autoescape", NULL, 483, &groupItem);
				zephir_check_call_status();
				zephir_array_append(&groupItems, &_61$$65, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 912);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &group, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_60$$64, &group, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_60$$64)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupItem, &group, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_62$$66, this_ptr, "autoescape", NULL, 483, &groupItem);
					zephir_check_call_status();
					zephir_array_append(&groupItems, &_62$$66, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 912);
				ZEPHIR_CALL_METHOD(NULL, &group, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&groupItem);
		ZEPHIR_INIT_VAR(&_63$$64);
		zephir_fast_join_str(&_63$$64, SL(", "), &groupItems);
		ZEPHIR_INIT_VAR(&_64$$64);
		ZEPHIR_CONCAT_SV(&_64$$64, " GROUP BY ", &_63$$64);
		zephir_concat_self(&phql, &_64$$64);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("having"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&having, &_0);
	if (Z_TYPE_P(&having) != IS_NULL) {
		if (!(ZEPHIR_IS_EMPTY(&having))) {
			ZEPHIR_INIT_VAR(&_65$$68);
			ZEPHIR_CONCAT_SV(&_65$$68, " HAVING ", &having);
			zephir_concat_self(&phql, &_65$$68);
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("order"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&order, &_0);
	if (Z_TYPE_P(&order) != IS_NULL) {
		if (Z_TYPE_P(&order) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&orderItems);
			array_init(&orderItems);
			zephir_is_iterable(&order, 0, "phalcon/Mvc/Model/Query/Builder.zep", 959);
			if (Z_TYPE_P(&order) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&order), _66$$70)
				{
					ZEPHIR_INIT_NVAR(&orderItem);
					ZVAL_COPY(&orderItem, _66$$70);
					if (Z_TYPE_P(&orderItem) == IS_LONG) {
						zephir_array_append(&orderItems, &orderItem, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 942);
						continue;
					}
					if (zephir_memnstr_str(&orderItem, SL(" "), "phalcon/Mvc/Model/Query/Builder.zep", 947) != 0) {
						ZEPHIR_INIT_NVAR(&itemExplode$$73);
						zephir_fast_explode_str(&itemExplode$$73, SL(" "), &orderItem, LONG_MAX);
						zephir_array_fetch_long(&_69$$73, &itemExplode$$73, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query/Builder.zep", 951);
						ZEPHIR_CALL_METHOD(&_68$$73, this_ptr, "autoescape", NULL, 483, &_69$$73);
						zephir_check_call_status();
						zephir_array_fetch_long(&_70$$73, &itemExplode$$73, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query/Builder.zep", 951);
						ZEPHIR_INIT_NVAR(&_71$$73);
						ZEPHIR_CONCAT_VSV(&_71$$73, &_68$$73, " ", &_70$$73);
						zephir_array_append(&orderItems, &_71$$73, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 951);
						continue;
					}
					ZEPHIR_CALL_METHOD(&_72$$71, this_ptr, "autoescape", NULL, 483, &orderItem);
					zephir_check_call_status();
					zephir_array_append(&orderItems, &_72$$71, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 956);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &order, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_67$$70, &order, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_67$$70)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&orderItem, &order, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&orderItem) == IS_LONG) {
							zephir_array_append(&orderItems, &orderItem, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 942);
							continue;
						}
						if (zephir_memnstr_str(&orderItem, SL(" "), "phalcon/Mvc/Model/Query/Builder.zep", 947) != 0) {
							ZEPHIR_INIT_NVAR(&itemExplode$$76);
							zephir_fast_explode_str(&itemExplode$$76, SL(" "), &orderItem, LONG_MAX);
							zephir_array_fetch_long(&_74$$76, &itemExplode$$76, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query/Builder.zep", 951);
							ZEPHIR_CALL_METHOD(&_73$$76, this_ptr, "autoescape", NULL, 483, &_74$$76);
							zephir_check_call_status();
							zephir_array_fetch_long(&_75$$76, &itemExplode$$76, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query/Builder.zep", 951);
							ZEPHIR_INIT_NVAR(&_76$$76);
							ZEPHIR_CONCAT_VSV(&_76$$76, &_73$$76, " ", &_75$$76);
							zephir_array_append(&orderItems, &_76$$76, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 951);
							continue;
						}
						ZEPHIR_CALL_METHOD(&_77$$74, this_ptr, "autoescape", NULL, 483, &orderItem);
						zephir_check_call_status();
						zephir_array_append(&orderItems, &_77$$74, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 956);
					ZEPHIR_CALL_METHOD(NULL, &order, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&orderItem);
			ZEPHIR_INIT_VAR(&_78$$70);
			zephir_fast_join_str(&_78$$70, SL(", "), &orderItems);
			ZEPHIR_INIT_VAR(&_79$$70);
			ZEPHIR_CONCAT_SV(&_79$$70, " ORDER BY ", &_78$$70);
			zephir_concat_self(&phql, &_79$$70);
		} else {
			ZEPHIR_INIT_VAR(&_80$$77);
			ZEPHIR_CONCAT_SV(&_80$$77, " ORDER BY ", &order);
			zephir_concat_self(&phql, &_80$$77);
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("limit"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&limit, &_0);
	if (Z_TYPE_P(&limit) != IS_NULL) {
		ZEPHIR_INIT_VAR(&number);
		ZVAL_NULL(&number);
		if (Z_TYPE_P(&limit) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&number);
			zephir_array_fetch_string(&number, &limit, SL("number"), PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 973);
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
				zephir_read_property(&_81$$83, this_ptr, ZEND_STRL("offset"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&offset, &_81$$83);
				if (Z_TYPE_P(&offset) != IS_NULL) {
					if (!(zephir_is_numeric(&offset))) {
						ZEPHIR_INIT_NVAR(&offset);
						ZVAL_LONG(&offset, 0);
					}
				}
			}
		}
		if (zephir_is_numeric(&number)) {
			zephir_concat_self_str(&phql, SL(" LIMIT :APL0:"));
			ZVAL_LONG(&_82$$86, 10);
			ZEPHIR_CALL_FUNCTION(&_83$$86, "intval", NULL, 51, &number, &_82$$86);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_84$$86);
			ZVAL_STRING(&_84$$86, "APL0");
			zephir_update_property_array(this_ptr, SL("bindParams"), &_84$$86, &_83$$86);
			ZEPHIR_INIT_VAR(&_85$$86);
			ZVAL_STRING(&_85$$86, "APL0");
			ZEPHIR_INIT_VAR(&_86$$86);
			ZVAL_LONG(&_86$$86, 1);
			zephir_update_property_array(this_ptr, SL("bindTypes"), &_85$$86, &_86$$86);
			_87$$86 = zephir_is_numeric(&offset);
			if (_87$$86) {
				_87$$86 = !ZEPHIR_IS_LONG_IDENTICAL(&offset, 0);
			}
			if (_87$$86) {
				zephir_concat_self_str(&phql, SL(" OFFSET :APL1:"));
				ZVAL_LONG(&_88$$87, 10);
				ZEPHIR_CALL_FUNCTION(&_89$$87, "intval", NULL, 51, &offset, &_88$$87);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_90$$87);
				ZVAL_STRING(&_90$$87, "APL1");
				zephir_update_property_array(this_ptr, SL("bindParams"), &_90$$87, &_89$$87);
				ZEPHIR_INIT_VAR(&_91$$87);
				ZVAL_STRING(&_91$$87, "APL1");
				ZEPHIR_INIT_VAR(&_92$$87);
				ZVAL_LONG(&_92$$87, 1);
				zephir_update_property_array(this_ptr, SL("bindTypes"), &_91$$87, &_92$$87);
			}
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("forUpdate"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&forUpdate, &_0);
	if (((Z_TYPE_P(&forUpdate) == IS_TRUE || Z_TYPE_P(&forUpdate) == IS_FALSE) == 1)) {
		if (zephir_is_true(&forUpdate)) {
			zephir_concat_self_str(&phql, SL(" FOR UPDATE"));
		}
	}
	RETURN_CCTOR(&phql);
}

/**
 * Returns the query built
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery)
{
	zval _6;
	zval query, bindParams, bindTypes, phql, container, _0, _5, _7, _8, _1$$3, _2$$3, _4$$3, _9$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&phql, this_ptr, "getphql", NULL, 484);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "the services related to the ORM");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_mvc_model_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1032);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	zephir_array_fast_append(&_6, &phql);
	zephir_array_fast_append(&_6, &container);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "Phalcon\\Mvc\\Model\\Query");
	ZEPHIR_CALL_METHOD(&_5, &container, "get", NULL, 0, &_7, &_6);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_5);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&bindParams, &_0);
	if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, &bindParams);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&bindTypes, &_0);
	if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, &bindTypes);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("sharedLock"), PH_NOISY_CC);
	if (((Z_TYPE_P(&_8) == IS_TRUE || Z_TYPE_P(&_8) == IS_FALSE) == 1)) {
		zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("sharedLock"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &query, "setsharedlock", NULL, 0, &_9$$6);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&query);
}

/**
 * Return the conditions for the query
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getWhere)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "conditions");
}

/**
 * Sets a GROUP BY clause
 *
 *```php
 * $builder->groupBy(
 *     [
 *         "Robots.name",
 *     ]
 * );
 *```
 *
 * @param array|string group
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, groupBy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *group = NULL, group_sub, _0$$4, _1$$4, _2$$4, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(group)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);
	ZEPHIR_SEPARATE_PARAM(group);


	if (Z_TYPE_P(group) == IS_STRING) {
		if (zephir_memnstr_str(group, SL(","), "phalcon/Mvc/Model/Query/Builder.zep", 1088)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_STRING(&_1$$4, " ");
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "");
			zephir_fast_str_replace(&_0$$4, &_1$$4, &_2$$4, group);
			ZEPHIR_CPY_WRT(group, &_0$$4);
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fast_explode_str(&_3$$3, SL(","), group, LONG_MAX);
		ZEPHIR_CPY_WRT(group, &_3$$3);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("group"), group);
	RETURN_THIS();
}

/**
 * Sets the HAVING condition clause
 *
 *```php
 * $builder->having("SUM(Robots.price) > 0");
 *
 * $builder->having(
 *     "SUM(Robots.price) > :sum:",
 *     [
 *         "sum" => 100,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, having)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval bindParams, bindTypes;
	zval *conditions_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, currentBindParams, currentBindTypes, _0$$3, _1$$5;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


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


	zephir_update_property_zval(this_ptr, ZEND_STRL("having"), &conditions);
	zephir_read_property(&currentBindParams, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_add_function(&_0$$3, &currentBindParams, &bindParams);
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &bindParams);
	}
	zephir_read_property(&currentBindTypes, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_add_function(&_1$$5, &currentBindTypes, &bindTypes);
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &_1$$5);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &bindTypes);
	}
	RETURN_THIS();
}

/**
 * Appends an IN condition to the current HAVING conditions clause
 *
 *```php
 * $builder->inHaving("SUM(Robots.price)", [100, 200]);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inHaving)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(expr)
		Z_PARAM_ARRAY(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Having");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionin", NULL, 0, &_0, &operator, &expr, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds an INNER join to the query
 *
 *```php
 * // Inner Join model 'Robots' with automatic conditions and alias
 * $builder->innerJoin(
 *     Robots::class
 * );
 *
 * // Inner Join model 'Robots' specifying conditions
 * $builder->innerJoin(
 *     Robots::class,
 *     "Robots.id = RobotsParts.robots_id"
 * );
 *
 * // Inner Join model 'Robots' specifying conditions and alias
 * $builder->innerJoin(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, innerJoin)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model_param = NULL, *conditions_param = NULL, *alias_param = NULL, _1;
	zval model, conditions, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(conditions)
		Z_PARAM_STR_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions_param, &alias_param);
	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
	}
	if (!conditions_param) {
		ZEPHIR_INIT_VAR(&conditions);
	} else {
		zephir_get_strval(&conditions, conditions_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
	} else {
		zephir_get_strval(&alias, alias_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, &model);
	zephir_array_fast_append(&_0, &conditions);
	zephir_array_fast_append(&_0, &alias);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "INNER");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_array_append(this_ptr, SL("joins"), &_0);
	RETURN_THIS();
}

/**
 * Appends an IN condition to the current WHERE conditions
 *
 *```php
 * $builder->inWhere(
 *     "id",
 *     [1, 2, 3]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(expr)
		Z_PARAM_ARRAY(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Where");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionin", NULL, 0, &_0, &operator, &expr, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds an :type: join (by default type - INNER) to the query
 *
 *```php
 * // Inner Join model 'Robots' with automatic conditions and alias
 * $builder->join(
 *     Robots::class
 * );
 *
 * // Inner Join model 'Robots' specifying conditions
 * $builder->join(
 *     Robots::class,
 *     "Robots.id = RobotsParts.robots_id"
 * );
 *
 * // Inner Join model 'Robots' specifying conditions and alias
 * $builder->join(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r"
 * );
 *
 * // Left Join model 'Robots' specifying conditions, alias and type of join
 * $builder->join(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r",
 *     "LEFT"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, join)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model_param = NULL, *conditions_param = NULL, *alias_param = NULL, *type_param = NULL;
	zval model, conditions, alias, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(conditions)
		Z_PARAM_STR_OR_NULL(alias)
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model_param, &conditions_param, &alias_param, &type_param);
	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
	}
	if (!conditions_param) {
		ZEPHIR_INIT_VAR(&conditions);
	} else {
		zephir_get_strval(&conditions, conditions_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
	} else {
		zephir_get_strval(&alias, alias_param);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, &model);
	zephir_array_fast_append(&_0, &conditions);
	zephir_array_fast_append(&_0, &alias);
	zephir_array_fast_append(&_0, &type);
	zephir_update_property_array_append(this_ptr, SL("joins"), &_0);
	RETURN_THIS();
}

/**
 * Adds a LEFT join to the query
 *
 *```php
 * $builder->leftJoin(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, leftJoin)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model_param = NULL, *conditions_param = NULL, *alias_param = NULL, _1;
	zval model, conditions, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(conditions)
		Z_PARAM_STR_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions_param, &alias_param);
	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
	}
	if (!conditions_param) {
		ZEPHIR_INIT_VAR(&conditions);
	} else {
		zephir_get_strval(&conditions, conditions_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
	} else {
		zephir_get_strval(&alias, alias_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, &model);
	zephir_array_fast_append(&_0, &conditions);
	zephir_array_fast_append(&_0, &alias);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "LEFT");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_array_append(this_ptr, SL("joins"), &_0);
	RETURN_THIS();
}

/**
 * Sets a LIMIT clause, optionally an offset clause
 *
 * ```php
 * $builder->limit(100);
 * $builder->limit(100, 20);
 * $builder->limit("100", "20");
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *limit_param = NULL, *offset = NULL, offset_sub, __$null, _0, _1, _2$$4, _3$$4;
	zend_long limit, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(limit)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit_param, &offset);
	limit = zephir_get_intval(limit_param);
	if (!offset) {
		offset = &offset_sub;
		offset = &__$null;
	}


	ZVAL_LONG(&_0, limit);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 238, &_0);
	zephir_check_call_status();
	limit = zephir_get_numberval(&_1);
	if (UNEXPECTED(limit == 0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, limit);
	zephir_update_property_zval(this_ptr, ZEND_STRL("limit"), &_0);
	if (zephir_is_numeric(offset)) {
		ZVAL_LONG(&_2$$4, zephir_get_intval(offset));
		ZEPHIR_CALL_FUNCTION(&_3$$4, "abs", NULL, 238, &_2$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("offset"), &_3$$4);
	}
	RETURN_THIS();
}

/**
 * Appends a NOT BETWEEN condition to the current HAVING conditions clause
 *
 *```php
 * $builder->notBetweenHaving("SUM(Robots.price)", 100.25, 200.50);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenHaving)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Having");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionnotbetween", NULL, 0, &_0, &operator, &expr, minimum, maximum);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends a NOT BETWEEN condition to the current WHERE conditions
 *
 *```php
 * $builder->notBetweenWhere("price", 100.25, 200.50);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &expr_param, &minimum, &maximum, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Where");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionnotbetween", NULL, 0, &_0, &operator, &expr, minimum, maximum);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends a NOT IN condition to the current HAVING conditions clause
 *
 *```php
 * $builder->notInHaving("SUM(Robots.price)", [100, 200]);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInHaving)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(expr)
		Z_PARAM_ARRAY(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Having");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionnotin", NULL, 0, &_0, &operator, &expr, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends a NOT IN condition to the current WHERE conditions
 *
 *```php
 * $builder->notInWhere("id", [1, 2, 3]);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *expr_param = NULL, *values_param = NULL, *operator_param = NULL, _0;
	zval expr, operator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(expr)
		Z_PARAM_ARRAY(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expr_param, &values_param, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Where");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionnotin", NULL, 0, &_0, &operator, &expr, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets an OFFSET clause
 *
 *```php
 * $builder->offset(30);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, offset)
{
	zval *offset_param = NULL, _0;
	zend_long offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &offset_param);
	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, offset);
	zephir_update_property_zval(this_ptr, ZEND_STRL("offset"), &_0);
	RETURN_THISW();
}

/**
 * Sets an ORDER BY condition clause
 *
 *```php
 * $builder->orderBy("Robots.name");
 * $builder->orderBy(["1", "Robots.name"]);
 * $builder->orderBy(["Robots.name DESC"]);
 *```
 *
 * @param array|string orderBy
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy)
{
	zval *orderBy, orderBy_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderBy_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(orderBy)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &orderBy);


	zephir_update_property_zval(this_ptr, ZEND_STRL("order"), orderBy);
	RETURN_THISW();
}

/**
 * Appends a condition to the current HAVING conditions clause using an OR operator
 *
 *```php
 * $builder->orHaving("SUM(Robots.price) > 0");
 *
 * $builder->orHaving(
 *     "SUM(Robots.price) > :sum:",
 *     [
 *         "sum" => 100,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orHaving)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams_param, &bindTypes_param);
	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
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
	zephir_read_property(&currentConditions, this_ptr, ZEND_STRL("having"), PH_NOISY_CC);
	if (zephir_is_true(&currentConditions)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "(", &currentConditions, ") OR (", &conditions, ")");
		zephir_get_strval(&conditions, &_0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "having", NULL, 0, &conditions, &bindParams, &bindTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends a condition to the current conditions using an OR operator
 *
 *```php
 * $builder->orWhere("name = 'Peter'");
 *
 * $builder->orWhere(
 *     "name = :name: AND id > :id:",
 *     [
 *         "name" => "Peter",
 *         "id"   => 100,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams_param, &bindTypes_param);
	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
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
	zephir_read_property(&currentConditions, this_ptr, ZEND_STRL("conditions"), PH_NOISY_CC);
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
 * Adds a RIGHT join to the query
 *
 *```php
 * $builder->rightJoin(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, rightJoin)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model_param = NULL, *conditions_param = NULL, *alias_param = NULL, _1;
	zval model, conditions, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(conditions)
		Z_PARAM_STR_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions_param, &alias_param);
	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
	}
	if (!conditions_param) {
		ZEPHIR_INIT_VAR(&conditions);
	} else {
		zephir_get_strval(&conditions, conditions_param);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
	} else {
		zephir_get_strval(&alias, alias_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, &model);
	zephir_array_fast_append(&_0, &conditions);
	zephir_array_fast_append(&_0, &alias);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "RIGHT");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_array_append(this_ptr, SL("joins"), &_0);
	RETURN_THIS();
}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setBindParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *bindParams_param = NULL, *merge_param = NULL, currentBindParams, _0$$4;
	zval bindParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&_0$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		zephir_read_property(&currentBindParams, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindParams, &bindParams);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &bindParams);
		}
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &bindParams);
	}
	RETURN_THIS();
}

/**
 * Set default bind types
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setBindTypes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *bindTypes_param = NULL, *merge_param = NULL, currentBindTypes, _0$$4;
	zval bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(bindTypes)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindTypes_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (UNEXPECTED(merge)) {
		zephir_read_property(&currentBindTypes, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindTypes, &bindTypes);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &bindTypes);
		}
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &bindTypes);
	}
	RETURN_THIS();
}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI)
{
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &container);


	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
}

/**
 * Sets the query WHERE conditions
 *
 *```php
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
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


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


	zephir_update_property_zval(this_ptr, ZEND_STRL("conditions"), &conditions);
	if (zephir_fast_count_int(&bindParams) > 0) {
		ZEPHIR_OBS_VAR(&currentBindParams);
		zephir_read_property(&currentBindParams, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindParams, &bindParams);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &bindParams);
		}
	}
	if (zephir_fast_count_int(&bindTypes) > 0) {
		zephir_read_property(&currentBindTypes, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$7);
			zephir_add_function(&_1$$7, &currentBindTypes, &bindTypes);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &_1$$7);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &bindTypes);
		}
	}
	RETURN_THIS();
}

/**
 * Appends a BETWEEN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionBetween)
{
	zval _6;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(clause)
		Z_PARAM_STR(operator)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &clause_param, &operator_param, &expr_param, &minimum, &maximum);
	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(&clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(&clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 194, &_2$$3, &operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1571);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &operator, &clause);
	ZEPHIR_CPY_WRT(&operatorMethod, &_4);
	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "AP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "AP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSVSVS(&_5, &expr, " BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	zephir_array_update_zval(&_6, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_6, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &nextHiddenParam);
	RETURN_THIS();
}

/**
 * Appends an IN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionIn)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenParam = 0;
	zval values;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *values_param = NULL, key, queryKey, value, bindKeys, bindParams, operatorMethod, _6, *_7, _8, _13, _14, _15, _1$$3, _2$$3, _3$$3, _9$$5, _11$$6;
	zval clause, operator, expr, _4, _5$$4, _10$$5, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(clause)
		Z_PARAM_STR(operator)
		Z_PARAM_STR(expr)
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &clause_param, &operator_param, &expr_param, &values_param);
	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(&clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(&clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 194, &_2$$3, &operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1619);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &operator, &clause);
	ZEPHIR_CPY_WRT(&operatorMethod, &_4);
	if (!(zephir_fast_count_int(&values))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VSV(&_5$$4, &expr, " != ", &expr);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_5$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(&_6);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Query/Builder.zep", 1650);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _7)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			ZEPHIR_INIT_NVAR(&_9$$5);
			ZVAL_LONG(&_9$$5, hiddenParam);
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZEPHIR_CONCAT_SV(&_10$$5, "AP", &_9$$5);
			ZEPHIR_CPY_WRT(&key, &_10$$5);
			ZEPHIR_INIT_NVAR(&queryKey);
			ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1641);
			zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
			hiddenParam++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_LONG(&_11$$6, hiddenParam);
				ZEPHIR_INIT_NVAR(&_12$$6);
				ZEPHIR_CONCAT_SV(&_12$$6, "AP", &_11$$6);
				ZEPHIR_CPY_WRT(&key, &_12$$6);
				ZEPHIR_INIT_NVAR(&queryKey);
				ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1641);
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				hiddenParam++;
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_13);
	zephir_fast_join_str(&_13, SL(", "), &bindKeys);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_CONCAT_VSVS(&_14, &expr, " IN (", &_13, ")");
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_14, &bindParams);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_15);
	ZVAL_LONG(&_15, hiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &_15);
	RETURN_THIS();
}

/**
 * Appends a NOT BETWEEN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionNotBetween)
{
	zval _6;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(clause)
		Z_PARAM_STR(operator)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &clause_param, &operator_param, &expr_param, &minimum, &maximum);
	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(&clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(&clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 194, &_2$$3, &operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1673);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &operator, &clause);
	ZEPHIR_CPY_WRT(&operatorMethod, &_4);
	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "AP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "AP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSVSVS(&_5, &expr, " NOT BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	zephir_array_update_zval(&_6, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_6, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &nextHiddenParam);
	RETURN_THIS();
}

/**
 * Appends a NOT IN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionNotIn)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenParam = 0;
	zval values;
	zval *clause_param = NULL, *operator_param = NULL, *expr_param = NULL, *values_param = NULL, key, queryKey, value, bindKeys, bindParams, operatorMethod, _6, *_7, _8, _13, _14, _15, _1$$3, _2$$3, _3$$3, _9$$5, _11$$6;
	zval clause, operator, expr, _4, _5$$4, _10$$5, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(clause)
		Z_PARAM_STR(operator)
		Z_PARAM_STR(expr)
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &clause_param, &operator_param, &expr_param, &values_param);
	if (UNEXPECTED(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clause_param) == IS_STRING)) {
		zephir_get_strval(&clause, clause_param);
	} else {
		ZEPHIR_INIT_VAR(&clause);
	}
	if (UNEXPECTED(Z_TYPE_P(operator_param) != IS_STRING && Z_TYPE_P(operator_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'operator' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(operator_param) == IS_STRING)) {
		zephir_get_strval(&operator, operator_param);
	} else {
		ZEPHIR_INIT_VAR(&operator);
	}
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Operator % is not available.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 194, &_2$$3, &operator);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1720);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &operator, &clause);
	ZEPHIR_CPY_WRT(&operatorMethod, &_4);
	if (!(zephir_fast_count_int(&values))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VSV(&_5$$4, &expr, " != ", &expr);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_5$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(&_6);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Query/Builder.zep", 1751);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _7)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			ZEPHIR_INIT_NVAR(&_9$$5);
			ZVAL_LONG(&_9$$5, hiddenParam);
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZEPHIR_CONCAT_SV(&_10$$5, "AP", &_9$$5);
			ZEPHIR_CPY_WRT(&key, &_10$$5);
			ZEPHIR_INIT_NVAR(&queryKey);
			ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1742);
			zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
			hiddenParam++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_LONG(&_11$$6, hiddenParam);
				ZEPHIR_INIT_NVAR(&_12$$6);
				ZEPHIR_CONCAT_SV(&_12$$6, "AP", &_11$$6);
				ZEPHIR_CPY_WRT(&key, &_12$$6);
				ZEPHIR_INIT_NVAR(&queryKey);
				ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1742);
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				hiddenParam++;
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_13);
	zephir_fast_join_str(&_13, SL(", "), &bindKeys);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_CONCAT_VSVS(&_14, &expr, " NOT IN (", &_13, ")");
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_14, &bindParams);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_15);
	ZVAL_LONG(&_15, hiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &_15);
	RETURN_THIS();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Query_Builder(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("joins"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("joins"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("group"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("group"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindTypes"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindParams"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

