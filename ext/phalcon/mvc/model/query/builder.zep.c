
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
 *
 * @param array|string|null params
 * @param DiInterface|null container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct)
{
	zend_bool _4$$7, _8$$38;
	zval mergedConditions, mergedParams, mergedTypes;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, params_sub, *container = NULL, container_sub, __$null, conditions, columns, groupClause, havingClause, limitClause, forUpdate, sharedLock, orderClause, offsetClause, joinsClause, singleConditionArray, limit, offset, fromClause, singleCondition, singleParams, singleTypes, distinct, bind, bindTypes, *_0$$7, _3$$7, _7$$7, _1$$11, _2$$12, _5$$16, _6$$17;
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
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_1$$11);
	ZVAL_UNDEF(&_2$$12);
	ZVAL_UNDEF(&_5$$16);
	ZVAL_UNDEF(&_6$$17);
	ZVAL_UNDEF(&mergedConditions);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&mergedTypes);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(params)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_memory_observe(&conditions);
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
			zephir_is_iterable(&conditions, 0, "phalcon/Mvc/Model/Query/Builder.zep", 194);
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
							zephir_array_append(&mergedConditions, &singleCondition, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 181);
						}
						if (Z_TYPE_P(&singleParams) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_1$$11);
							zephir_add_function(&_1$$11, &mergedParams, &singleParams);
							ZEPHIR_CPY_WRT(&mergedParams, &_1$$11);
						}
						if (Z_TYPE_P(&singleTypes) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_2$$12);
							zephir_add_function(&_2$$12, &mergedTypes, &singleTypes);
							ZEPHIR_CPY_WRT(&mergedTypes, &_2$$12);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &conditions, "rewind", NULL, 0);
				zephir_check_call_status();
				_4$$7 = 1;
				while (1) {
					if (_4$$7) {
						_4$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &conditions, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_3$$7, &conditions, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$7)) {
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
								zephir_array_append(&mergedConditions, &singleCondition, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 181);
							}
							if (Z_TYPE_P(&singleParams) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_5$$16);
								zephir_add_function(&_5$$16, &mergedParams, &singleParams);
								ZEPHIR_CPY_WRT(&mergedParams, &_5$$16);
							}
							if (Z_TYPE_P(&singleTypes) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_6$$17);
								zephir_add_function(&_6$$17, &mergedTypes, &singleTypes);
								ZEPHIR_CPY_WRT(&mergedTypes, &_6$$17);
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&singleConditionArray);
			ZEPHIR_INIT_VAR(&_7$$7);
			zephir_fast_join_str(&_7$$7, SL(" AND "), &mergedConditions);
			zephir_update_property_zval(this_ptr, ZEND_STRL("conditions"), &_7$$7);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &mergedParams);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &mergedTypes);
		}
		zephir_memory_observe(&bind);
		if (zephir_array_isset_string_fetch(&bind, params, SL("bind"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &bind);
		}
		zephir_memory_observe(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SL("bindTypes"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &bindTypes);
		}
		zephir_memory_observe(&distinct);
		if (zephir_array_isset_string_fetch(&distinct, params, SL("distinct"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("distinct"), &distinct);
		}
		zephir_memory_observe(&fromClause);
		if (zephir_array_isset_string_fetch(&fromClause, params, SL("models"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &fromClause);
		}
		zephir_memory_observe(&columns);
		if (zephir_array_isset_string_fetch(&columns, params, SL("columns"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &columns);
		}
		zephir_memory_observe(&joinsClause);
		if (zephir_array_isset_string_fetch(&joinsClause, params, SL("joins"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("joins"), &joinsClause);
		}
		zephir_memory_observe(&groupClause);
		if (zephir_array_isset_string_fetch(&groupClause, params, SL("group"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "groupby", NULL, 0, &groupClause);
			zephir_check_call_status();
		}
		zephir_memory_observe(&havingClause);
		if (zephir_array_isset_string_fetch(&havingClause, params, SL("having"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("having"), &havingClause);
		}
		zephir_memory_observe(&orderClause);
		if (zephir_array_isset_string_fetch(&orderClause, params, SL("order"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("order"), &orderClause);
		}
		zephir_memory_observe(&limitClause);
		if (zephir_array_isset_string_fetch(&limitClause, params, SL("limit"), 0)) {
			if (Z_TYPE_P(&limitClause) == IS_ARRAY) {
				zephir_memory_observe(&limit);
				if (zephir_array_isset_long_fetch(&limit, &limitClause, 0, 0)) {
					if (Z_TYPE_P(&limit) == IS_LONG) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("limit"), &limit);
					}
					zephir_memory_observe(&offset);
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
		_8$$38 = Z_TYPE_P(params) == IS_STRING;
		if (_8$$38) {
			_8$$38 = !ZEPHIR_IS_STRING_IDENTICAL(params, "");
		}
		if (_8$$38) {
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
	zval model_zv, alias_zv, models, currentModel, _0, _1$$4;
	zend_string *model = NULL, *alias = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&currentModel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!alias) {
		ZEPHIR_INIT_VAR(&alias_zv);
	} else {
		zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
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
		_2 = !ZEPHIR_IS_NULL(&alias_zv);
	}
	if (_2) {
		zephir_array_update_zval(&models, &alias_zv, &model_zv, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_append(&models, &model_zv, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 349);
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
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&currentConditions);
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
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&currentConditions);
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
	zend_bool _0, _1, _2;
	zval identifier_zv;
	zend_string *identifier = NULL;

	ZVAL_UNDEF(&identifier_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(identifier)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&identifier_zv, identifier);
	_0 = zephir_memnstr_str(&identifier_zv, SL("["), "phalcon/Mvc/Model/Query/Builder.zep", 423);
	if (!(_0)) {
		_0 = zephir_memnstr_str(&identifier_zv, SL("."), "phalcon/Mvc/Model/Query/Builder.zep", 423);
	}
	_1 = _0;
	if (!(_1)) {
		_1 = zephir_memnstr_str(&identifier_zv, SL("("), "phalcon/Mvc/Model/Query/Builder.zep", 423);
	}
	_2 = _1;
	if (!(_2)) {
		_2 = zephir_is_numeric(&identifier_zv);
	}
	if (_2) {
		RETURN_STR(zend_string_copy(identifier));
	}
	ZEPHIR_CONCAT_SVS(return_value, "[", &identifier_zv, "]");
	return;
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
	zval operator;
	zval expr_zv, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&operator);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(operator_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	minimum = ZEND_CALL_ARG(execute_data, 2);
	maximum = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		operator_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionbetween", NULL, 0, &_0, &operator, &expr_zv, minimum, maximum);
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
	zval operator;
	zval expr_zv, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&operator);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(operator_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	minimum = ZEND_CALL_ARG(execute_data, 2);
	maximum = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		operator_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionbetween", NULL, 0, &_0, &operator, &expr_zv, minimum, maximum);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the columns to be queried. The columns can be either a `string` or
 * an `array` of strings. If the argument is a (single, non-embedded) string,
 * its content can specify one or more columns, separated by commas, the same
 * way that one uses the SQL select statement. You can use aliases, aggregate
 * functions, etc. If you need to reference other models you will need to
 * reference them with their namespaces.
 *
 * When using an array as a parameter, you will need to specify one field
 * per array element. If a non-numeric key is defined in the array, it will
 * be used as the alias in the query
 *
 *```php
 * <?php
 *
 * // String, comma separated values
 * $builder->columns("id, category");
 *
 * // Array, one column per element
 * $builder->columns(
 *     [
 *         "inv_id",
 *         "inv_total",
 *     ]
 * );
 *
 * // Array with named key. The name of the key acts as an
 * // alias (`AS` clause)
 * $builder->columns(
 *     [
 *         "inv_cst_id",
 *         "total_invoices" => "COUNT(*)",
 *     ]
 * );
 *
 * // Different models
 * $builder->columns(
 *     [
 *         "\Phalcon\Models\Invoices.*",
 *         "\Phalcon\Models\Customers.cst_name_first",
 *         "\Phalcon\Models\Customers.cst_name_last",
 *     ]
 * );
 *```
 *
 * @param string|array $columns
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns)
{
	zval *columns, columns_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(columns)
	ZEND_PARSE_PARAMETERS_END();
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(distinct)
	ZEND_PARSE_PARAMETERS_END();
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(forUpdate)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &forUpdate_param);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(models)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &models);
	zephir_update_property_zval(this_ptr, ZEND_STRL("models"), models);
	RETURN_THISW();
}

/**
 * Returns default bind params
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getBindParams)
{

	RETURN_MEMBER_TYPED(getThis(), "bindParams", IS_ARRAY);
}

/**
 * Returns default bind types
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getBindTypes)
{

	RETURN_MEMBER_TYPED(getThis(), "bindTypes", IS_ARRAY);
}

/**
 * Return the columns to be queried
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns)
{

	RETURN_MEMBER(getThis(), "columns");
}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI)
{

	RETURN_MEMBER(getThis(), "container");
}

/**
 * Returns SELECT DISTINCT / SELECT ALL flag
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDistinct)
{

	RETURN_MEMBER(getThis(), "distinct");
}

/**
 * Return the models who makes part of the query
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom)
{

	RETURN_MEMBER(getThis(), "models");
}

/**
 * Returns the GROUP BY clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy)
{

	RETURN_MEMBER_TYPED(getThis(), "group", IS_ARRAY);
}

/**
 * Return the current having clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving)
{

	RETURN_MEMBER(getThis(), "having");
}

/**
 * Return join parts of the query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getJoins)
{

	RETURN_MEMBER_TYPED(getThis(), "joins", IS_ARRAY);
}

/**
 * Returns the current LIMIT clause
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit)
{

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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	_1 = Z_TYPE_P(&models) == IS_ARRAY;
	if (_1) {
		_1 = zephir_fast_count_int(&models) == 1;
	}
	if (_1) {
		ZEPHIR_MAKE_REF(&models);
		ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 0, &models);
		ZEPHIR_UNREF(&models);
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

	RETURN_MEMBER_TYPED(getThis(), "offset", IS_LONG);
}

/**
 * Returns the set ORDER BY clause
 *
 * @return array|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy)
{

	RETURN_MEMBER(getThis(), "order");
}

/**
 * Returns a PHQL statement built based on the builder parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql)
{
	zend_string *_14$$25, *_24$$34, *_36$$42;
	zend_ulong _13$$25, _23$$34, _35$$42;
	zval _5$$8;
	zend_bool noPrimary = 0, _18$$25, _28$$34, _40$$42, _56$$50, _68$$63, _80$$69, _95$$85;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, container, models, conditions, model, metaData, modelInstance, primaryKeys, firstPrimaryKey, columnMap, modelAlias, attributeField, phql, column, columns, selectedColumns, selectedColumn, selectedModel, selectedModels, columnAlias, modelColumnAlias, joins, join, joinModel, joinConditions, joinAlias, joinType, group, groupItems, groupItem, having, order, orderItems, orderItem, limit, number, offset, forUpdate, distinct, _0, _1$$5, _2$$7, _3$$10, _4$$8, _6$$13, _7$$13, _9$$13, _10$$13, _8$$17, _11$$19, *_12$$25, _17$$25, _21$$25, _15$$28, _16$$28, _19$$31, _20$$31, *_22$$34, _27$$34, _31$$34, _25$$36, _26$$37, _29$$39, _30$$40, _32$$41, _33$$41, *_34$$42, _39$$42, _43$$42, _44$$42, _37$$44, _38$$44, _41$$47, _42$$47, _45$$49, _46$$49, *_47$$50, _55$$50, _48$$52, _49$$52, _50$$53, _51$$53, _52$$54, _53$$54, _54$$55, _57$$57, _58$$57, _59$$58, _60$$58, _61$$59, _62$$59, _63$$60, _64$$62, *_65$$63, _67$$63, _70$$63, _71$$63, _66$$64, _69$$65, _72$$67, *_73$$69, _79$$69, _86$$69, _87$$69, itemExplode$$72, _74$$72, _75$$72, _76$$72, _77$$72, _78$$70, itemExplode$$75, _81$$75, _82$$75, _83$$75, _84$$75, _85$$73, _88$$76, _89$$82, _90$$85, _91$$85, _92$$85, _93$$85, _94$$85, _96$$86, _97$$86, _98$$86, _99$$86, _100$$86;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&_11$$19);
	ZVAL_UNDEF(&_17$$25);
	ZVAL_UNDEF(&_21$$25);
	ZVAL_UNDEF(&_15$$28);
	ZVAL_UNDEF(&_16$$28);
	ZVAL_UNDEF(&_19$$31);
	ZVAL_UNDEF(&_20$$31);
	ZVAL_UNDEF(&_27$$34);
	ZVAL_UNDEF(&_31$$34);
	ZVAL_UNDEF(&_25$$36);
	ZVAL_UNDEF(&_26$$37);
	ZVAL_UNDEF(&_29$$39);
	ZVAL_UNDEF(&_30$$40);
	ZVAL_UNDEF(&_32$$41);
	ZVAL_UNDEF(&_33$$41);
	ZVAL_UNDEF(&_39$$42);
	ZVAL_UNDEF(&_43$$42);
	ZVAL_UNDEF(&_44$$42);
	ZVAL_UNDEF(&_37$$44);
	ZVAL_UNDEF(&_38$$44);
	ZVAL_UNDEF(&_41$$47);
	ZVAL_UNDEF(&_42$$47);
	ZVAL_UNDEF(&_45$$49);
	ZVAL_UNDEF(&_46$$49);
	ZVAL_UNDEF(&_55$$50);
	ZVAL_UNDEF(&_48$$52);
	ZVAL_UNDEF(&_49$$52);
	ZVAL_UNDEF(&_50$$53);
	ZVAL_UNDEF(&_51$$53);
	ZVAL_UNDEF(&_52$$54);
	ZVAL_UNDEF(&_53$$54);
	ZVAL_UNDEF(&_54$$55);
	ZVAL_UNDEF(&_57$$57);
	ZVAL_UNDEF(&_58$$57);
	ZVAL_UNDEF(&_59$$58);
	ZVAL_UNDEF(&_60$$58);
	ZVAL_UNDEF(&_61$$59);
	ZVAL_UNDEF(&_62$$59);
	ZVAL_UNDEF(&_63$$60);
	ZVAL_UNDEF(&_64$$62);
	ZVAL_UNDEF(&_67$$63);
	ZVAL_UNDEF(&_70$$63);
	ZVAL_UNDEF(&_71$$63);
	ZVAL_UNDEF(&_66$$64);
	ZVAL_UNDEF(&_69$$65);
	ZVAL_UNDEF(&_72$$67);
	ZVAL_UNDEF(&_79$$69);
	ZVAL_UNDEF(&_86$$69);
	ZVAL_UNDEF(&_87$$69);
	ZVAL_UNDEF(&itemExplode$$72);
	ZVAL_UNDEF(&_74$$72);
	ZVAL_UNDEF(&_75$$72);
	ZVAL_UNDEF(&_76$$72);
	ZVAL_UNDEF(&_77$$72);
	ZVAL_UNDEF(&_78$$70);
	ZVAL_UNDEF(&itemExplode$$75);
	ZVAL_UNDEF(&_81$$75);
	ZVAL_UNDEF(&_82$$75);
	ZVAL_UNDEF(&_83$$75);
	ZVAL_UNDEF(&_84$$75);
	ZVAL_UNDEF(&_85$$73);
	ZVAL_UNDEF(&_88$$76);
	ZVAL_UNDEF(&_89$$82);
	ZVAL_UNDEF(&_90$$85);
	ZVAL_UNDEF(&_91$$85);
	ZVAL_UNDEF(&_92$$85);
	ZVAL_UNDEF(&_93$$85);
	ZVAL_UNDEF(&_94$$85);
	ZVAL_UNDEF(&_96$$86);
	ZVAL_UNDEF(&_97$$86);
	ZVAL_UNDEF(&_98$$86);
	ZVAL_UNDEF(&_99$$86);
	ZVAL_UNDEF(&_100$$86);
	ZVAL_UNDEF(&_5$$8);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		if (UNEXPECTED(!(zephir_fast_count_int(&models)))) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_mvc_model_query_exceptions_builder_modelrequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Model/Query/Builder.zep", 708);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		if (UNEXPECTED(!zephir_is_true(&models))) {
			ZEPHIR_INIT_VAR(&_2$$7);
			object_init_ex(&_2$$7, phalcon_mvc_model_query_exceptions_builder_modelrequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$7, "phalcon/Mvc/Model/Query/Builder.zep", 712);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("conditions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&conditions, &_0);
	if (zephir_is_numeric(&conditions)) {
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			if (UNEXPECTED(zephir_fast_count_int(&models) > 1)) {
				ZEPHIR_INIT_VAR(&_3$$10);
				object_init_ex(&_3$$10, phalcon_mvc_model_query_exceptions_builder_builderconditioninvalid_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$10, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$10, "phalcon/Mvc/Model/Query/Builder.zep", 725);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&model);
			zephir_array_fetch_long(&model, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 728);
		} else {
			ZEPHIR_CPY_WRT(&model, &models);
		}
		ZEPHIR_INIT_VAR(&_4$$8);
		ZVAL_STRING(&_4$$8, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &container, "getshared", NULL, 0, &_4$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$8);
		zephir_create_array(&_5$$8, 2, 0);
		zephir_array_fast_append(&_5$$8, &__$null);
		zephir_array_fast_append(&_5$$8, &container);
		ZEPHIR_INIT_VAR(&modelInstance);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&modelInstance, &model, &_5$$8);
		zephir_check_call_status();
		noPrimary = 1;
		ZEPHIR_CALL_METHOD(&primaryKeys, &metaData, "getprimarykeyattributes", NULL, 0, &modelInstance);
		zephir_check_call_status();
		if (zephir_fast_count_int(&primaryKeys)) {
			zephir_memory_observe(&firstPrimaryKey);
			if (zephir_array_isset_long_fetch(&firstPrimaryKey, &primaryKeys, 0, 0)) {
				ZEPHIR_INIT_VAR(&_7$$13);
				ZVAL_STRING(&_7$$13, "orm.column_renaming");
				ZEPHIR_CALL_CE_STATIC(&_6$$13, phalcon_support_settings_ce, "get", NULL, 0, &_7$$13);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$13)) {
					ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, &modelInstance);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&columnMap);
					ZVAL_NULL(&columnMap);
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					zephir_memory_observe(&attributeField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeField, &columnMap, &firstPrimaryKey, 0)))) {
						ZEPHIR_INIT_VAR(&_8$$17);
						object_init_ex(&_8$$17, phalcon_mvc_model_query_exceptions_builder_buildercolumnnotinmap_ce);
						ZEPHIR_CALL_METHOD(NULL, &_8$$17, "__construct", NULL, 0, &firstPrimaryKey);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_8$$17, "phalcon/Mvc/Model/Query/Builder.zep", 762);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &firstPrimaryKey);
				}
				ZEPHIR_INIT_NVAR(&_7$$13);
				ZVAL_STRING(&_7$$13, "APK0");
				zephir_update_property_array(this_ptr, SL("bindParams"), &_7$$13, &conditions);
				ZEPHIR_CALL_METHOD(&_9$$13, this_ptr, "autoescape", NULL, 0, &model);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_10$$13, this_ptr, "autoescape", NULL, 0, &attributeField);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&conditions);
				ZEPHIR_CONCAT_VSVS(&conditions, &_9$$13, ".", &_10$$13, " = :APK0:");
				noPrimary = 0;
			}
		}
		if (UNEXPECTED(noPrimary)) {
			ZEPHIR_INIT_VAR(&_11$$19);
			object_init_ex(&_11$$19, phalcon_mvc_model_query_exceptions_builder_noprimarykey_ce);
			ZEPHIR_CALL_METHOD(NULL, &_11$$19, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$19, "phalcon/Mvc/Model/Query/Builder.zep", 784);
			ZEPHIR_MM_RESTORE();
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
			zephir_is_iterable(&columns, 0, "phalcon/Mvc/Model/Query/Builder.zep", 817);
			if (Z_TYPE_P(&columns) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _13$$25, _14$$25, _12$$25)
				{
					ZEPHIR_INIT_NVAR(&columnAlias);
					if (_14$$25 != NULL) { 
						ZVAL_STR_COPY(&columnAlias, _14$$25);
					} else {
						ZVAL_LONG(&columnAlias, _13$$25);
					}
					ZEPHIR_INIT_NVAR(&column);
					ZVAL_COPY(&column, _12$$25);
					if (Z_TYPE_P(&columnAlias) == IS_LONG) {
						zephir_array_append(&selectedColumns, &column, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 811);
					} else {
						ZEPHIR_CALL_METHOD(&_15$$28, this_ptr, "autoescape", NULL, 0, &columnAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_16$$28);
						ZEPHIR_CONCAT_VSV(&_16$$28, &column, " AS ", &_15$$28);
						zephir_array_append(&selectedColumns, &_16$$28, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 813);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
				zephir_check_call_status();
				_18$$25 = 1;
				while (1) {
					if (_18$$25) {
						_18$$25 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_17$$25, &columns, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_17$$25)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&columnAlias, &columns, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnAlias) == IS_LONG) {
							zephir_array_append(&selectedColumns, &column, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 811);
						} else {
							ZEPHIR_CALL_METHOD(&_19$$31, this_ptr, "autoescape", NULL, 0, &columnAlias);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_20$$31);
							ZEPHIR_CONCAT_VSV(&_20$$31, &column, " AS ", &_19$$31);
							zephir_array_append(&selectedColumns, &_20$$31, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 813);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&column);
			ZEPHIR_INIT_NVAR(&columnAlias);
			ZEPHIR_INIT_VAR(&_21$$25);
			zephir_fast_join_str(&_21$$25, SL(", "), &selectedColumns);
			zephir_concat_self(&phql, &_21$$25);
		} else {
			zephir_concat_self(&phql, &columns);
		}
	} else {
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&selectedColumns);
			array_init(&selectedColumns);
			zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query/Builder.zep", 838);
			if (Z_TYPE_P(&models) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _23$$34, _24$$34, _22$$34)
				{
					ZEPHIR_INIT_NVAR(&modelColumnAlias);
					if (_24$$34 != NULL) { 
						ZVAL_STR_COPY(&modelColumnAlias, _24$$34);
					} else {
						ZVAL_LONG(&modelColumnAlias, _23$$34);
					}
					ZEPHIR_INIT_NVAR(&model);
					ZVAL_COPY(&model, _22$$34);
					ZEPHIR_INIT_NVAR(&selectedColumn);
					if (Z_TYPE_P(&modelColumnAlias) == IS_LONG) {
						ZEPHIR_CALL_METHOD(&_25$$36, this_ptr, "autoescape", NULL, 0, &model);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VS(&selectedColumn, &_25$$36, ".*");
					} else {
						ZEPHIR_CALL_METHOD(&_26$$37, this_ptr, "autoescape", NULL, 0, &modelColumnAlias);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VS(&selectedColumn, &_26$$37, ".*");
					}
					zephir_array_append(&selectedColumns, &selectedColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 835);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &models, "rewind", NULL, 0);
				zephir_check_call_status();
				_28$$34 = 1;
				while (1) {
					if (_28$$34) {
						_28$$34 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &models, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_27$$34, &models, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_27$$34)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&modelColumnAlias, &models, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&model, &models, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&selectedColumn);
						if (Z_TYPE_P(&modelColumnAlias) == IS_LONG) {
							ZEPHIR_CALL_METHOD(&_29$$39, this_ptr, "autoescape", NULL, 0, &model);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VS(&selectedColumn, &_29$$39, ".*");
						} else {
							ZEPHIR_CALL_METHOD(&_30$$40, this_ptr, "autoescape", NULL, 0, &modelColumnAlias);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VS(&selectedColumn, &_30$$40, ".*");
						}
						zephir_array_append(&selectedColumns, &selectedColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 835);
				}
			}
			ZEPHIR_INIT_NVAR(&model);
			ZEPHIR_INIT_NVAR(&modelColumnAlias);
			ZEPHIR_INIT_VAR(&_31$$34);
			zephir_fast_join_str(&_31$$34, SL(", "), &selectedColumns);
			zephir_concat_self(&phql, &_31$$34);
		} else {
			ZEPHIR_CALL_METHOD(&_32$$41, this_ptr, "autoescape", NULL, 0, &models);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_33$$41);
			ZEPHIR_CONCAT_VS(&_33$$41, &_32$$41, ".*");
			zephir_concat_self(&phql, &_33$$41);
		}
	}
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&selectedModels);
		array_init(&selectedModels);
		zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query/Builder.zep", 860);
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _35$$42, _36$$42, _34$$42)
			{
				ZEPHIR_INIT_NVAR(&modelAlias);
				if (_36$$42 != NULL) { 
					ZVAL_STR_COPY(&modelAlias, _36$$42);
				} else {
					ZVAL_LONG(&modelAlias, _35$$42);
				}
				ZEPHIR_INIT_NVAR(&model);
				ZVAL_COPY(&model, _34$$42);
				if (Z_TYPE_P(&modelAlias) == IS_STRING) {
					ZEPHIR_CALL_METHOD(&_37$$44, this_ptr, "autoescape", NULL, 0, &model);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_38$$44, this_ptr, "autoescape", NULL, 0, &modelAlias);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&selectedModel);
					ZEPHIR_CONCAT_VSV(&selectedModel, &_37$$44, " AS ", &_38$$44);
				} else {
					ZEPHIR_CALL_METHOD(&selectedModel, this_ptr, "autoescape", NULL, 0, &model);
					zephir_check_call_status();
				}
				zephir_array_append(&selectedModels, &selectedModel, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 857);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &models, "rewind", NULL, 0);
			zephir_check_call_status();
			_40$$42 = 1;
			while (1) {
				if (_40$$42) {
					_40$$42 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &models, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_39$$42, &models, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_39$$42)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&modelAlias, &models, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&model, &models, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&modelAlias) == IS_STRING) {
						ZEPHIR_CALL_METHOD(&_41$$47, this_ptr, "autoescape", NULL, 0, &model);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_42$$47, this_ptr, "autoescape", NULL, 0, &modelAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&selectedModel);
						ZEPHIR_CONCAT_VSV(&selectedModel, &_41$$47, " AS ", &_42$$47);
					} else {
						ZEPHIR_CALL_METHOD(&selectedModel, this_ptr, "autoescape", NULL, 0, &model);
						zephir_check_call_status();
					}
					zephir_array_append(&selectedModels, &selectedModel, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 857);
			}
		}
		ZEPHIR_INIT_NVAR(&model);
		ZEPHIR_INIT_NVAR(&modelAlias);
		ZEPHIR_INIT_VAR(&_43$$42);
		zephir_fast_join_str(&_43$$42, SL(", "), &selectedModels);
		ZEPHIR_INIT_VAR(&_44$$42);
		ZEPHIR_CONCAT_SV(&_44$$42, " FROM ", &_43$$42);
		zephir_concat_self(&phql, &_44$$42);
	} else {
		ZEPHIR_CALL_METHOD(&_45$$49, this_ptr, "autoescape", NULL, 0, &models);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_46$$49);
		ZEPHIR_CONCAT_SV(&_46$$49, " FROM ", &_45$$49);
		zephir_concat_self(&phql, &_46$$49);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("joins"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&joins, &_0);
	if (Z_TYPE_P(&joins) == IS_ARRAY) {
		zephir_is_iterable(&joins, 0, "phalcon/Mvc/Model/Query/Builder.zep", 915);
		if (Z_TYPE_P(&joins) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&joins), _47$$50)
			{
				ZEPHIR_INIT_NVAR(&join);
				ZVAL_COPY(&join, _47$$50);
				ZEPHIR_OBS_NVAR(&joinModel);
				zephir_array_fetch_long(&joinModel, &join, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 875);
				ZEPHIR_OBS_NVAR(&joinConditions);
				zephir_array_fetch_long(&joinConditions, &join, 1, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 880);
				ZEPHIR_OBS_NVAR(&joinAlias);
				zephir_array_fetch_long(&joinAlias, &join, 2, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 885);
				ZEPHIR_OBS_NVAR(&joinType);
				zephir_array_fetch_long(&joinType, &join, 3, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 890);
				if (zephir_is_true(&joinType)) {
					ZEPHIR_CALL_METHOD(&_48$$52, this_ptr, "autoescape", NULL, 0, &joinModel);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_49$$52);
					ZEPHIR_CONCAT_SVSV(&_49$$52, " ", &joinType, " JOIN ", &_48$$52);
					zephir_concat_self(&phql, &_49$$52);
				} else {
					ZEPHIR_CALL_METHOD(&_50$$53, this_ptr, "autoescape", NULL, 0, &joinModel);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_51$$53);
					ZEPHIR_CONCAT_SV(&_51$$53, " JOIN ", &_50$$53);
					zephir_concat_self(&phql, &_51$$53);
				}
				if (zephir_is_true(&joinAlias)) {
					ZEPHIR_CALL_METHOD(&_52$$54, this_ptr, "autoescape", NULL, 0, &joinAlias);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_53$$54);
					ZEPHIR_CONCAT_SV(&_53$$54, " AS ", &_52$$54);
					zephir_concat_self(&phql, &_53$$54);
				}
				if (zephir_is_true(&joinConditions)) {
					ZEPHIR_INIT_NVAR(&_54$$55);
					ZEPHIR_CONCAT_SV(&_54$$55, " ON ", &joinConditions);
					zephir_concat_self(&phql, &_54$$55);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &joins, "rewind", NULL, 0);
			zephir_check_call_status();
			_56$$50 = 1;
			while (1) {
				if (_56$$50) {
					_56$$50 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &joins, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_55$$50, &joins, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_55$$50)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&join, &joins, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&joinModel);
					zephir_array_fetch_long(&joinModel, &join, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 875);
					ZEPHIR_OBS_NVAR(&joinConditions);
					zephir_array_fetch_long(&joinConditions, &join, 1, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 880);
					ZEPHIR_OBS_NVAR(&joinAlias);
					zephir_array_fetch_long(&joinAlias, &join, 2, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 885);
					ZEPHIR_OBS_NVAR(&joinType);
					zephir_array_fetch_long(&joinType, &join, 3, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 890);
					if (zephir_is_true(&joinType)) {
						ZEPHIR_CALL_METHOD(&_57$$57, this_ptr, "autoescape", NULL, 0, &joinModel);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_58$$57);
						ZEPHIR_CONCAT_SVSV(&_58$$57, " ", &joinType, " JOIN ", &_57$$57);
						zephir_concat_self(&phql, &_58$$57);
					} else {
						ZEPHIR_CALL_METHOD(&_59$$58, this_ptr, "autoescape", NULL, 0, &joinModel);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_60$$58);
						ZEPHIR_CONCAT_SV(&_60$$58, " JOIN ", &_59$$58);
						zephir_concat_self(&phql, &_60$$58);
					}
					if (zephir_is_true(&joinAlias)) {
						ZEPHIR_CALL_METHOD(&_61$$59, this_ptr, "autoescape", NULL, 0, &joinAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_62$$59);
						ZEPHIR_CONCAT_SV(&_62$$59, " AS ", &_61$$59);
						zephir_concat_self(&phql, &_62$$59);
					}
					if (zephir_is_true(&joinConditions)) {
						ZEPHIR_INIT_NVAR(&_63$$60);
						ZEPHIR_CONCAT_SV(&_63$$60, " ON ", &joinConditions);
						zephir_concat_self(&phql, &_63$$60);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&join);
	}
	if (Z_TYPE_P(&conditions) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(&conditions))) {
			ZEPHIR_INIT_VAR(&_64$$62);
			ZEPHIR_CONCAT_SV(&_64$$62, " WHERE ", &conditions);
			zephir_concat_self(&phql, &_64$$62);
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&group, &_0);
	if (!(ZEPHIR_IS_EMPTY(&group))) {
		ZEPHIR_INIT_VAR(&groupItems);
		array_init(&groupItems);
		zephir_is_iterable(&group, 0, "phalcon/Mvc/Model/Query/Builder.zep", 935);
		if (Z_TYPE_P(&group) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&group), _65$$63)
			{
				ZEPHIR_INIT_NVAR(&groupItem);
				ZVAL_COPY(&groupItem, _65$$63);
				ZEPHIR_CALL_METHOD(&_66$$64, this_ptr, "autoescape", NULL, 0, &groupItem);
				zephir_check_call_status();
				zephir_array_append(&groupItems, &_66$$64, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 932);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &group, "rewind", NULL, 0);
			zephir_check_call_status();
			_68$$63 = 1;
			while (1) {
				if (_68$$63) {
					_68$$63 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &group, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_67$$63, &group, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_67$$63)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupItem, &group, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_69$$65, this_ptr, "autoescape", NULL, 0, &groupItem);
					zephir_check_call_status();
					zephir_array_append(&groupItems, &_69$$65, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 932);
			}
		}
		ZEPHIR_INIT_NVAR(&groupItem);
		ZEPHIR_INIT_VAR(&_70$$63);
		zephir_fast_join_str(&_70$$63, SL(", "), &groupItems);
		ZEPHIR_INIT_VAR(&_71$$63);
		ZEPHIR_CONCAT_SV(&_71$$63, " GROUP BY ", &_70$$63);
		zephir_concat_self(&phql, &_71$$63);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("having"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&having, &_0);
	if (Z_TYPE_P(&having) != IS_NULL) {
		if (!(ZEPHIR_IS_EMPTY(&having))) {
			ZEPHIR_INIT_VAR(&_72$$67);
			ZEPHIR_CONCAT_SV(&_72$$67, " HAVING ", &having);
			zephir_concat_self(&phql, &_72$$67);
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("order"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&order, &_0);
	if (Z_TYPE_P(&order) != IS_NULL) {
		if (Z_TYPE_P(&order) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&orderItems);
			array_init(&orderItems);
			zephir_is_iterable(&order, 0, "phalcon/Mvc/Model/Query/Builder.zep", 979);
			if (Z_TYPE_P(&order) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&order), _73$$69)
				{
					ZEPHIR_INIT_NVAR(&orderItem);
					ZVAL_COPY(&orderItem, _73$$69);
					if (Z_TYPE_P(&orderItem) == IS_LONG) {
						zephir_array_append(&orderItems, &orderItem, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 962);
						continue;
					}
					if (zephir_memnstr_str(&orderItem, SL(" "), "phalcon/Mvc/Model/Query/Builder.zep", 967) != 0) {
						ZEPHIR_INIT_NVAR(&itemExplode$$72);
						zephir_fast_explode_str(&itemExplode$$72, SL(" "), &orderItem, LONG_MAX);
						ZEPHIR_CPY_WRT(&itemExplode$$72, &itemExplode$$72);
						zephir_array_fetch_long(&_75$$72, &itemExplode$$72, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query/Builder.zep", 971);
						ZEPHIR_CALL_METHOD(&_74$$72, this_ptr, "autoescape", NULL, 0, &_75$$72);
						zephir_check_call_status();
						zephir_array_fetch_long(&_76$$72, &itemExplode$$72, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query/Builder.zep", 971);
						ZEPHIR_INIT_NVAR(&_77$$72);
						ZEPHIR_CONCAT_VSV(&_77$$72, &_74$$72, " ", &_76$$72);
						zephir_array_append(&orderItems, &_77$$72, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 971);
						continue;
					}
					ZEPHIR_CALL_METHOD(&_78$$70, this_ptr, "autoescape", NULL, 0, &orderItem);
					zephir_check_call_status();
					zephir_array_append(&orderItems, &_78$$70, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 976);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &order, "rewind", NULL, 0);
				zephir_check_call_status();
				_80$$69 = 1;
				while (1) {
					if (_80$$69) {
						_80$$69 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &order, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_79$$69, &order, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_79$$69)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&orderItem, &order, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&orderItem) == IS_LONG) {
							zephir_array_append(&orderItems, &orderItem, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 962);
							continue;
						}
						if (zephir_memnstr_str(&orderItem, SL(" "), "phalcon/Mvc/Model/Query/Builder.zep", 967) != 0) {
							ZEPHIR_INIT_NVAR(&itemExplode$$75);
							zephir_fast_explode_str(&itemExplode$$75, SL(" "), &orderItem, LONG_MAX);
							ZEPHIR_CPY_WRT(&itemExplode$$75, &itemExplode$$75);
							zephir_array_fetch_long(&_82$$75, &itemExplode$$75, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query/Builder.zep", 971);
							ZEPHIR_CALL_METHOD(&_81$$75, this_ptr, "autoescape", NULL, 0, &_82$$75);
							zephir_check_call_status();
							zephir_array_fetch_long(&_83$$75, &itemExplode$$75, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query/Builder.zep", 971);
							ZEPHIR_INIT_NVAR(&_84$$75);
							ZEPHIR_CONCAT_VSV(&_84$$75, &_81$$75, " ", &_83$$75);
							zephir_array_append(&orderItems, &_84$$75, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 971);
							continue;
						}
						ZEPHIR_CALL_METHOD(&_85$$73, this_ptr, "autoescape", NULL, 0, &orderItem);
						zephir_check_call_status();
						zephir_array_append(&orderItems, &_85$$73, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 976);
				}
			}
			ZEPHIR_INIT_NVAR(&orderItem);
			ZEPHIR_INIT_VAR(&_86$$69);
			zephir_fast_join_str(&_86$$69, SL(", "), &orderItems);
			ZEPHIR_INIT_VAR(&_87$$69);
			ZEPHIR_CONCAT_SV(&_87$$69, " ORDER BY ", &_86$$69);
			zephir_concat_self(&phql, &_87$$69);
		} else {
			ZEPHIR_INIT_VAR(&_88$$76);
			ZEPHIR_CONCAT_SV(&_88$$76, " ORDER BY ", &order);
			zephir_concat_self(&phql, &_88$$76);
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("limit"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&limit, &_0);
	if (Z_TYPE_P(&limit) != IS_NULL) {
		ZEPHIR_INIT_VAR(&number);
		ZVAL_NULL(&number);
		if (Z_TYPE_P(&limit) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&number);
			zephir_array_fetch_string(&number, &limit, SL("number"), PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 993);
			zephir_memory_observe(&offset);
			if (zephir_array_isset_string_fetch(&offset, &limit, SL("offset"), 0)) {
				if (!(zephir_is_numeric(&offset))) {
					ZEPHIR_INIT_NVAR(&offset);
					ZVAL_LONG(&offset, 0);
				}
			}
		} else {
			if (zephir_is_numeric(&limit)) {
				ZEPHIR_CPY_WRT(&number, &limit);
				zephir_read_property(&_89$$82, this_ptr, ZEND_STRL("offset"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&offset, &_89$$82);
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
			ZVAL_LONG(&_90$$85, 10);
			ZEPHIR_CALL_FUNCTION(&_91$$85, "intval", NULL, 78, &number, &_90$$85);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_92$$85);
			ZVAL_STRING(&_92$$85, "APL0");
			zephir_update_property_array(this_ptr, SL("bindParams"), &_92$$85, &_91$$85);
			ZEPHIR_INIT_VAR(&_93$$85);
			ZVAL_STRING(&_93$$85, "APL0");
			ZEPHIR_INIT_VAR(&_94$$85);
			ZVAL_LONG(&_94$$85, 1);
			zephir_update_property_array(this_ptr, SL("bindTypes"), &_93$$85, &_94$$85);
			_95$$85 = zephir_is_numeric(&offset);
			if (_95$$85) {
				_95$$85 = !ZEPHIR_IS_LONG_IDENTICAL(&offset, 0);
			}
			if (_95$$85) {
				zephir_concat_self_str(&phql, SL(" OFFSET :APL1:"));
				ZVAL_LONG(&_96$$86, 10);
				ZEPHIR_CALL_FUNCTION(&_97$$86, "intval", NULL, 78, &offset, &_96$$86);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_98$$86);
				ZVAL_STRING(&_98$$86, "APL1");
				zephir_update_property_array(this_ptr, SL("bindParams"), &_98$$86, &_97$$86);
				ZEPHIR_INIT_VAR(&_99$$86);
				ZVAL_STRING(&_99$$86, "APL1");
				ZEPHIR_INIT_VAR(&_100$$86);
				ZVAL_LONG(&_100$$86, 1);
				zephir_update_property_array(this_ptr, SL("bindTypes"), &_99$$86, &_100$$86);
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
	zval _3;
	zval query, bindParams, bindTypes, phql, container, _0, _2, _4, _5, _1$$3, _6$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&phql, this_ptr, "getphql", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_managerormservicesunavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1048);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, &phql);
	zephir_array_fast_append(&_3, &container);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Model\\Query");
	ZEPHIR_CALL_METHOD(&_2, &container, "get", NULL, 0, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&query, &_2);
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
	zephir_memory_observe(&_5);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("sharedLock"), PH_NOISY_CC);
	if (((Z_TYPE_P(&_5) == IS_TRUE || Z_TYPE_P(&_5) == IS_FALSE) == 1)) {
		zephir_read_property(&_6$$6, this_ptr, ZEND_STRL("sharedLock"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &query, "setsharedlock", NULL, 0, &_6$$6);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(group)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group);
	ZEPHIR_SEPARATE_PARAM(group);
	if (Z_TYPE_P(group) == IS_STRING) {
		if (zephir_memnstr_str(group, SL(","), "phalcon/Mvc/Model/Query/Builder.zep", 1104)) {
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
	zval conditions_zv, *bindParams_param = NULL, *bindTypes_param = NULL, currentBindParams, currentBindTypes, _0$$3, _1$$5;
	zend_string *conditions = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions_zv);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		bindParams_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		bindTypes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&conditions_zv);
	ZVAL_STR_COPY(&conditions_zv, conditions);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("having"), &conditions_zv);
	zephir_memory_observe(&currentBindParams);
	zephir_read_property(&currentBindParams, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC);
	if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_add_function(&_0$$3, &currentBindParams, &bindParams);
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &bindParams);
	}
	zephir_memory_observe(&currentBindTypes);
	zephir_read_property(&currentBindTypes, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC);
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
	zval operator;
	zval values;
	zval expr_zv, *values_param = NULL, *operator_param = NULL, _0;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&operator);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(expr)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(operator_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		operator_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionin", NULL, 0, &_0, &operator, &expr_zv, &values);
	zephir_check_call_status();
	RETURN_MM();
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
	zval operator;
	zval values;
	zval expr_zv, *values_param = NULL, *operator_param = NULL, _0;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&operator);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(expr)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(operator_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		operator_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionin", NULL, 0, &_0, &operator, &expr_zv, &values);
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
	zval model_zv, conditions_zv, alias_zv, _1;
	zend_string *model = NULL, *conditions = NULL, *alias = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_zv);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(conditions)
		Z_PARAM_STR_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		ZEPHIR_INIT_VAR(&conditions_zv);
	} else {
		zephir_memory_observe(&conditions_zv);
	ZVAL_STR_COPY(&conditions_zv, conditions);
	}
	if (!alias) {
		ZEPHIR_INIT_VAR(&alias_zv);
	} else {
		zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, &model_zv);
	zephir_array_fast_append(&_0, &conditions_zv);
	zephir_array_fast_append(&_0, &alias_zv);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "INNER");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_array_append(this_ptr, SL("joins"), &_0);
	RETURN_THIS();
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
	zval model_zv, conditions_zv, alias_zv, type_zv;
	zend_string *model = NULL, *conditions = NULL, *alias = NULL, *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_zv);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(conditions)
		Z_PARAM_STR_OR_NULL(alias)
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		ZEPHIR_INIT_VAR(&conditions_zv);
	} else {
		zephir_memory_observe(&conditions_zv);
	ZVAL_STR_COPY(&conditions_zv, conditions);
	}
	if (!alias) {
		ZEPHIR_INIT_VAR(&alias_zv);
	} else {
		zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	}
	if (!type) {
		ZEPHIR_INIT_VAR(&type_zv);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, &model_zv);
	zephir_array_fast_append(&_0, &conditions_zv);
	zephir_array_fast_append(&_0, &alias_zv);
	zephir_array_fast_append(&_0, &type_zv);
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
	zval model_zv, conditions_zv, alias_zv, _1;
	zend_string *model = NULL, *conditions = NULL, *alias = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_zv);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(conditions)
		Z_PARAM_STR_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		ZEPHIR_INIT_VAR(&conditions_zv);
	} else {
		zephir_memory_observe(&conditions_zv);
	ZVAL_STR_COPY(&conditions_zv, conditions);
	}
	if (!alias) {
		ZEPHIR_INIT_VAR(&alias_zv);
	} else {
		zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, &model_zv);
	zephir_array_fast_append(&_0, &conditions_zv);
	zephir_array_fast_append(&_0, &alias_zv);
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(limit)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &limit_param, &offset);
	if (!offset) {
		offset = &offset_sub;
		offset = &__$null;
	}
	ZVAL_LONG(&_0, limit);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 0, &_0);
	zephir_check_call_status();
	limit = zephir_get_numberval(&_1);
	if (UNEXPECTED(limit == 0)) {
		RETURN_THIS();
	}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, limit);
	zephir_update_property_zval(this_ptr, ZEND_STRL("limit"), &_0);
	if (zephir_is_numeric(offset)) {
		ZVAL_LONG(&_2$$4, zephir_get_intval(offset));
		ZEPHIR_CALL_FUNCTION(&_3$$4, "abs", NULL, 0, &_2$$4);
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
	zval operator;
	zval expr_zv, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&operator);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(operator_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	minimum = ZEND_CALL_ARG(execute_data, 2);
	maximum = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		operator_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionnotbetween", NULL, 0, &_0, &operator, &expr_zv, minimum, maximum);
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
	zval operator;
	zval expr_zv, *minimum, minimum_sub, *maximum, maximum_sub, *operator_param = NULL, _0;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&operator);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(operator_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	minimum = ZEND_CALL_ARG(execute_data, 2);
	maximum = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		operator_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionnotbetween", NULL, 0, &_0, &operator, &expr_zv, minimum, maximum);
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
	zval operator;
	zval values;
	zval expr_zv, *values_param = NULL, *operator_param = NULL, _0;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&operator);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(expr)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(operator_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		operator_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionnotin", NULL, 0, &_0, &operator, &expr_zv, &values);
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
	zval operator;
	zval values;
	zval expr_zv, *values_param = NULL, *operator_param = NULL, _0;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&operator);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(expr)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(operator_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		operator_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "conditionnotin", NULL, 0, &_0, &operator, &expr_zv, &values);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &offset_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, offset);
	zephir_update_property_zval(this_ptr, ZEND_STRL("offset"), &_0);
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
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&currentConditions);
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
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&currentConditions);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(orderBy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &orderBy);
	zephir_update_property_zval(this_ptr, ZEND_STRL("order"), orderBy);
	RETURN_THISW();
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
	zval model_zv, conditions_zv, alias_zv, _1;
	zend_string *model = NULL, *conditions = NULL, *alias = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_zv);
	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(conditions)
		Z_PARAM_STR_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		ZEPHIR_INIT_VAR(&conditions_zv);
	} else {
		zephir_memory_observe(&conditions_zv);
	ZVAL_STR_COPY(&conditions_zv, conditions);
	}
	if (!alias) {
		ZEPHIR_INIT_VAR(&alias_zv);
	} else {
		zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, &model_zv);
	zephir_array_fast_append(&_0, &conditions_zv);
	zephir_array_fast_append(&_0, &alias_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (merge) {
		zephir_memory_observe(&currentBindParams);
		zephir_read_property(&currentBindParams, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC);
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &bindTypes_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (UNEXPECTED(merge)) {
		zephir_memory_observe(&currentBindTypes);
		zephir_read_property(&currentBindTypes, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
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
	zval conditions_zv, *bindParams_param = NULL, *bindTypes_param = NULL, currentBindParams, currentBindTypes, _0$$4, _1$$7;
	zend_string *conditions = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions_zv);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		bindParams_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		bindTypes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&conditions_zv);
	ZVAL_STR_COPY(&conditions_zv, conditions);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("conditions"), &conditions_zv);
	if (zephir_fast_count_int(&bindParams) > 0) {
		zephir_memory_observe(&currentBindParams);
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
	zval _4;
	zval _2;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval clause_zv, operator_zv, expr_zv, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod, _3, _1$$3;
	zend_string *clause = NULL, *operator = NULL, *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause_zv);
	ZVAL_UNDEF(&operator_zv);
	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(clause)
		Z_PARAM_STR(operator)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	minimum = ZEND_CALL_ARG(execute_data, 4);
	maximum = ZEND_CALL_ARG(execute_data, 5);
	zephir_memory_observe(&clause_zv);
	ZVAL_STR_COPY(&clause_zv, clause);
	zephir_memory_observe(&operator_zv);
	ZVAL_STR_COPY(&operator_zv, operator);
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_builder_operatornotavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &operator_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1582);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &operator_zv, &clause_zv);
	ZEPHIR_CPY_WRT(&operatorMethod, &_2);
	zephir_memory_observe(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "AP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "AP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSVSVS(&_3, &expr_zv, " BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_update_zval(&_4, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_4, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_3, &_4);
	zephir_check_call_status();
	SEPARATE_ZVAL(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &nextHiddenParam);
	RETURN_THIS();
}

/**
 * Appends an IN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionIn)
{
	zval _2, _3$$4, _7$$5, _11$$6;
	zend_bool _0, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenParam = 0;
	zval values;
	zval clause_zv, operator_zv, expr_zv, *values_param = NULL, key, queryKey, value, bindKeys, bindParams, operatorMethod, _4, *_5, _8, _12, _13, _14, _1$$3, _6$$5, _10$$6;
	zend_string *clause = NULL, *operator = NULL, *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause_zv);
	ZVAL_UNDEF(&operator_zv);
	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$6);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(clause)
		Z_PARAM_STR(operator)
		Z_PARAM_STR(expr)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&clause_zv);
	ZVAL_STR_COPY(&clause_zv, clause);
	zephir_memory_observe(&operator_zv);
	ZVAL_STR_COPY(&operator_zv, operator);
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_builder_operatornotavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &operator_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1625);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &operator_zv, &clause_zv);
	ZEPHIR_CPY_WRT(&operatorMethod, &_2);
	if (!(zephir_fast_count_int(&values))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_VSV(&_3$$4, &expr_zv, " != ", &expr_zv);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_3$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	zephir_memory_observe(&_4);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(&_4);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Query/Builder.zep", 1656);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _5)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _5);
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_LONG(&_6$$5, hiddenParam);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZEPHIR_CONCAT_SV(&_7$$5, "AP", &_6$$5);
			ZEPHIR_CPY_WRT(&key, &_7$$5);
			ZEPHIR_INIT_NVAR(&queryKey);
			ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1647);
			zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
			hiddenParam++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_8, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZVAL_LONG(&_10$$6, hiddenParam);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZEPHIR_CONCAT_SV(&_11$$6, "AP", &_10$$6);
				ZEPHIR_CPY_WRT(&key, &_11$$6);
				ZEPHIR_INIT_NVAR(&queryKey);
				ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1647);
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				hiddenParam++;
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_join_str(&_12, SL(", "), &bindKeys);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_VSVS(&_13, &expr_zv, " IN (", &_12, ")");
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_13, &bindParams);
	zephir_check_call_status();
	ZVAL_UNDEF(&_14);
	ZVAL_LONG(&_14, hiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &_14);
	RETURN_THIS();
}

/**
 * Appends a NOT BETWEEN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionNotBetween)
{
	zval _4;
	zval _2;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval clause_zv, operator_zv, expr_zv, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod, _3, _1$$3;
	zend_string *clause = NULL, *operator = NULL, *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause_zv);
	ZVAL_UNDEF(&operator_zv);
	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(clause)
		Z_PARAM_STR(operator)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	minimum = ZEND_CALL_ARG(execute_data, 4);
	maximum = ZEND_CALL_ARG(execute_data, 5);
	zephir_memory_observe(&clause_zv);
	ZVAL_STR_COPY(&clause_zv, clause);
	zephir_memory_observe(&operator_zv);
	ZVAL_STR_COPY(&operator_zv, operator);
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_builder_operatornotavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &operator_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1674);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &operator_zv, &clause_zv);
	ZEPHIR_CPY_WRT(&operatorMethod, &_2);
	zephir_memory_observe(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "AP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "AP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSVSVS(&_3, &expr_zv, " NOT BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_update_zval(&_4, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_4, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_3, &_4);
	zephir_check_call_status();
	SEPARATE_ZVAL(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &nextHiddenParam);
	RETURN_THIS();
}

/**
 * Appends a NOT IN condition
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, conditionNotIn)
{
	zval _2, _3$$4, _7$$5, _11$$6;
	zend_bool _0, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenParam = 0;
	zval values;
	zval clause_zv, operator_zv, expr_zv, *values_param = NULL, key, queryKey, value, bindKeys, bindParams, operatorMethod, _4, *_5, _8, _12, _13, _14, _1$$3, _6$$5, _10$$6;
	zend_string *clause = NULL, *operator = NULL, *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clause_zv);
	ZVAL_UNDEF(&operator_zv);
	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&operatorMethod);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$6);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(clause)
		Z_PARAM_STR(operator)
		Z_PARAM_STR(expr)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&clause_zv);
	ZVAL_STR_COPY(&clause_zv, clause);
	zephir_memory_observe(&operator_zv);
	ZVAL_STR_COPY(&operator_zv, operator);
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_builder_operatornotavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &operator_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1716);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &operator_zv, &clause_zv);
	ZEPHIR_CPY_WRT(&operatorMethod, &_2);
	if (!(zephir_fast_count_int(&values))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_VSV(&_3$$4, &expr_zv, " != ", &expr_zv);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_3$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	zephir_memory_observe(&_4);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	hiddenParam = zephir_get_intval(&_4);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Query/Builder.zep", 1747);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _5)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _5);
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_LONG(&_6$$5, hiddenParam);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZEPHIR_CONCAT_SV(&_7$$5, "AP", &_6$$5);
			ZEPHIR_CPY_WRT(&key, &_7$$5);
			ZEPHIR_INIT_NVAR(&queryKey);
			ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1738);
			zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
			hiddenParam++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_8, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZVAL_LONG(&_10$$6, hiddenParam);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZEPHIR_CONCAT_SV(&_11$$6, "AP", &_10$$6);
				ZEPHIR_CPY_WRT(&key, &_11$$6);
				ZEPHIR_INIT_NVAR(&queryKey);
				ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1738);
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				hiddenParam++;
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_join_str(&_12, SL(", "), &bindKeys);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_VSVS(&_13, &expr_zv, " NOT IN (", &_12, ")");
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_13, &bindParams);
	zephir_check_call_status();
	ZVAL_UNDEF(&_14);
	ZVAL_LONG(&_14, hiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &_14);
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
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

