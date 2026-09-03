
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
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
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_model_query_builder_ce, SL("resultsetRowClass"), "", ZEND_ACC_PROTECTED);
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
	zend_bool _6$$7, _10$$38;
	zval mergedConditions, mergedParams, mergedTypes;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, params_sub, *container = NULL, container_sub, __$null, conditions, columns, groupClause, havingClause, limitClause, forUpdate, sharedLock, orderClause, offsetClause, joinsClause, singleConditionArray, limit, offset, fromClause, singleCondition, singleParams, singleTypes, distinct, bind, bindTypes, *_0$$7, _1$$7, *_2$$7, _5$$7, _9$$7, _3$$11, _4$$12, _7$$16, _8$$17;
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
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$12);
	ZVAL_UNDEF(&_7$$16);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&mergedConditions);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&mergedTypes);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	static zend_string *_zephir_prop_12 = NULL;
	static zend_string *_zephir_prop_13 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("conditions", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("bindParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("bindTypes", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("distinct", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("models", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("columns", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("joins", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("having", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("order", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("limit", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("offset", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("forUpdate", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_12)) {
		_zephir_prop_12 = zend_string_init("sharedLock", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_13)) {
		_zephir_prop_13 = zend_string_init("container", 9, 1);
	}

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
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1078, &conditions);
		} else {
			ZEPHIR_OBS_NVAR(&conditions);
			if (zephir_array_isset_string_fetch(&conditions, params, SL("conditions"), 0)) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1078, &conditions);
			}
		}
		if (Z_TYPE_P(&conditions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedConditions);
			array_init(&mergedConditions);
			ZEPHIR_INIT_VAR(&mergedParams);
			array_init(&mergedParams);
			ZEPHIR_INIT_VAR(&mergedTypes);
			array_init(&mergedTypes);
			if (Z_TYPE_P(&conditions) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_1$$7);
				zephir_string_to_char_array(&_1$$7, &conditions);
				_0$$7 = &_1$$7;
			} else {
				_0$$7 = &conditions;
			}
			zephir_is_iterable(_0$$7, 0, "phalcon/Mvc/Model/Query/Builder.zep", 200);
			if (Z_TYPE_P(_0$$7) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0$$7), _2$$7)
				{
					ZEPHIR_INIT_NVAR(&singleConditionArray);
					ZVAL_COPY(&singleConditionArray, _2$$7);
					if (Z_TYPE_P(&singleConditionArray) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&singleCondition);
						zephir_array_isset_long_fetch(&singleCondition, &singleConditionArray, 0, 0);
						ZEPHIR_OBS_NVAR(&singleParams);
						zephir_array_isset_long_fetch(&singleParams, &singleConditionArray, 1, 0);
						ZEPHIR_OBS_NVAR(&singleTypes);
						zephir_array_isset_long_fetch(&singleTypes, &singleConditionArray, 2, 0);
						if (Z_TYPE_P(&singleCondition) == IS_STRING) {
							zephir_array_append(&mergedConditions, &singleCondition, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 187);
						}
						if (Z_TYPE_P(&singleParams) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_3$$11);
							zephir_add_function(&_3$$11, &mergedParams, &singleParams);
							ZEPHIR_CPY_WRT(&mergedParams, &_3$$11);
						}
						if (Z_TYPE_P(&singleTypes) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_4$$12);
							zephir_add_function(&_4$$12, &mergedTypes, &singleTypes);
							ZEPHIR_CPY_WRT(&mergedTypes, &_4$$12);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _0$$7, "rewind", NULL, 0);
				zephir_check_call_status();
				_6$$7 = 1;
				while (1) {
					if (_6$$7) {
						_6$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _0$$7, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_5$$7, _0$$7, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&singleConditionArray, _0$$7, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&singleConditionArray) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&singleCondition);
							zephir_array_isset_long_fetch(&singleCondition, &singleConditionArray, 0, 0);
							ZEPHIR_OBS_NVAR(&singleParams);
							zephir_array_isset_long_fetch(&singleParams, &singleConditionArray, 1, 0);
							ZEPHIR_OBS_NVAR(&singleTypes);
							zephir_array_isset_long_fetch(&singleTypes, &singleConditionArray, 2, 0);
							if (Z_TYPE_P(&singleCondition) == IS_STRING) {
								zephir_array_append(&mergedConditions, &singleCondition, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 187);
							}
							if (Z_TYPE_P(&singleParams) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_7$$16);
								zephir_add_function(&_7$$16, &mergedParams, &singleParams);
								ZEPHIR_CPY_WRT(&mergedParams, &_7$$16);
							}
							if (Z_TYPE_P(&singleTypes) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_8$$17);
								zephir_add_function(&_8$$17, &mergedTypes, &singleTypes);
								ZEPHIR_CPY_WRT(&mergedTypes, &_8$$17);
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&singleConditionArray);
			ZEPHIR_INIT_VAR(&_9$$7);
			zephir_fast_join_str(&_9$$7, SL(" AND "), &mergedConditions);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1078, &_9$$7);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1079, &mergedParams);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1080, &mergedTypes);
		}
		zephir_memory_observe(&bind);
		if (zephir_array_isset_string_fetch(&bind, params, SL("bind"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1079, &bind);
		}
		zephir_memory_observe(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SL("bindTypes"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1080, &bindTypes);
		}
		zephir_memory_observe(&distinct);
		if (zephir_array_isset_string_fetch(&distinct, params, SL("distinct"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1081, &distinct);
		}
		zephir_memory_observe(&fromClause);
		if (zephir_array_isset_string_fetch(&fromClause, params, SL("models"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1082, &fromClause);
		}
		zephir_memory_observe(&columns);
		if (zephir_array_isset_string_fetch(&columns, params, SL("columns"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1083, &columns);
		}
		zephir_memory_observe(&joinsClause);
		if (zephir_array_isset_string_fetch(&joinsClause, params, SL("joins"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1084, &joinsClause);
		}
		zephir_memory_observe(&groupClause);
		if (zephir_array_isset_string_fetch(&groupClause, params, SL("group"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "groupby", NULL, 0, &groupClause);
			zephir_check_call_status();
		}
		zephir_memory_observe(&havingClause);
		if (zephir_array_isset_string_fetch(&havingClause, params, SL("having"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1085, &havingClause);
		}
		zephir_memory_observe(&orderClause);
		if (zephir_array_isset_string_fetch(&orderClause, params, SL("order"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 1086, &orderClause);
		}
		zephir_memory_observe(&limitClause);
		if (zephir_array_isset_string_fetch(&limitClause, params, SL("limit"), 0)) {
			if (Z_TYPE_P(&limitClause) == IS_ARRAY) {
				zephir_memory_observe(&limit);
				if (zephir_array_isset_long_fetch(&limit, &limitClause, 0, 0)) {
					if (Z_TYPE_P(&limit) == IS_LONG) {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1087, &limit);
					}
					zephir_memory_observe(&offset);
					if (zephir_array_isset_long_fetch(&offset, &limitClause, 1, 0)) {
						if (Z_TYPE_P(&offset) == IS_LONG) {
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 1088, &offset);
						}
					}
				} else {
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1087, &limitClause);
				}
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1087, &limitClause);
			}
		}
		if (zephir_array_isset_string_fetch(&offsetClause, params, SL("offset"), 1)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 1088, &offsetClause);
		}
		if (zephir_array_isset_string_fetch(&forUpdate, params, SL("for_update"), 1)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 1089, &forUpdate);
		}
		if (zephir_array_isset_string_fetch(&sharedLock, params, SL("shared_lock"), 1)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_12, 1090, &sharedLock);
		}
	} else {
		_10$$38 = Z_TYPE_P(params) == IS_STRING;
		if (_10$$38) {
			_10$$38 = !ZEPHIR_IS_STRING_IDENTICAL(params, "");
		}
		if (_10$$38) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1078, params);
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_13, 1091, container);
	ZEPHIR_MM_RESTORE();
}

/**
 * Add a model to take part of the query
 *
 *```php
 * // Load data from models Invoices
 * $builder->addFrom(
 *     Invoices::class
 * );
 *
 * // Load data from model 'Invoices' using 'r' as alias in PHQL
 * $builder->addFrom(
 *     Invoices::class,
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("models", 6, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1082, PH_NOISY_CC | PH_READONLY);
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
		zephir_array_append(&models, &model_zv, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 355);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1082, &models);
	RETURN_THIS();
}

/**
 * Appends a condition to the current HAVING conditions clause using a AND operator
 *
 *```php
 * $builder->andHaving("SUM(Invoices.inv_total) > 0");
 *
 * $builder->andHaving(
 *     "SUM(Invoices.inv_total) > :sum:",
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("having", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&currentConditions);
	zephir_read_property_cached(&currentConditions, this_ptr, _zephir_prop_0, 1085, PH_NOISY_CC);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("conditions", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&currentConditions);
	zephir_read_property_cached(&currentConditions, this_ptr, _zephir_prop_0, 1078, PH_NOISY_CC);
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
	_0 = zephir_memnstr_str(&identifier_zv, SL("["), "phalcon/Mvc/Model/Query/Builder.zep", 429);
	if (!(_0)) {
		_0 = zephir_memnstr_str(&identifier_zv, SL("."), "phalcon/Mvc/Model/Query/Builder.zep", 429);
	}
	_1 = _0;
	if (!(_1)) {
		_1 = zephir_memnstr_str(&identifier_zv, SL("("), "phalcon/Mvc/Model/Query/Builder.zep", 429);
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
 * $builder->betweenHaving("SUM(Invoices.inv_total)", 100.25, 200.50);
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
		zephir_get_strval(&operator, operator_param);
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
		zephir_get_strval(&operator, operator_param);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("columns", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(columns)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &columns);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1083, columns);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("distinct", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(distinct)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &distinct);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1081, distinct);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("forUpdate", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(forUpdate)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &forUpdate_param);
	if (forUpdate) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1089, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1089, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the models who makes part of the query
 *
 *```php
 * $builder->from(
 *     Invoices::class
 * );
 *
 * $builder->from(
 *     [
 *         Invoices::class,
 *         OrdersProducts::class,
 *     ]
 * );
 *
 * $builder->from(
 *     [
 *         "r"  => Invoices::class,
 *         "rp" => OrdersProducts::class,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from)
{
	zval *models, models_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&models_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("models", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(models)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &models);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1082, models);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("models", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1082, PH_NOISY_CC | PH_READONLY);
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
	zend_string *_16$$25, *_28$$34, *_42$$42;
	zend_ulong _15$$25, _27$$34, _41$$42;
	zval _5$$8;
	zend_bool noPrimary = 0, _20$$25, _32$$34, _46$$42, _64$$50, _78$$63, _101$$69, _95$$72, _109$$78, _123$$91;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_87 = NULL, *_94 = NULL;
	zval __$null, attributeField, column, columnAlias, columnMap, columns, conditions, container, distinct, firstPrimaryKey, forUpdate, group, groupItem, groupItems, having, join, joinAlias, joinConditions, joinModel, joinType, joins, limit, metaData, model, modelAlias, modelColumnAlias, modelInstance, models, number, order, orderItem, orderItems, phql, primaryKeys, selectedColumn, selectedColumns, selectedModel, selectedModels, offset, _0, _1$$5, _2$$7, _3$$10, _4$$8, _6$$13, _7$$13, _9$$13, _10$$13, _8$$17, _11$$19, *_12$$25, _13$$25, *_14$$25, _19$$25, _23$$25, _17$$28, _18$$28, _21$$31, _22$$31, *_24$$34, _25$$34, *_26$$34, _31$$34, _35$$34, _29$$36, _30$$37, _33$$39, _34$$40, _36$$41, _37$$41, *_38$$42, _39$$42, *_40$$42, _45$$42, _49$$42, _50$$42, _43$$44, _44$$44, _47$$47, _48$$47, _51$$49, _52$$49, *_53$$50, _54$$50, *_55$$50, _63$$50, _56$$52, _57$$52, _58$$53, _59$$53, _60$$54, _61$$54, _62$$55, _65$$57, _66$$57, _67$$58, _68$$58, _69$$59, _70$$59, _71$$60, _72$$62, *_73$$63, _74$$63, *_75$$63, _77$$63, _80$$63, _81$$63, _76$$64, _79$$65, _82$$67, *_83$$69, _84$$69, *_85$$69, _100$$69, _114$$69, _115$$69, itemTrimmed$$70, lastSpacePosition$$70, _86$$70, _99$$70, perhapsExpression$$72, perhapsDirection$$72, _88$$72, _89$$72, _90$$72, _91$$72, _92$$72, _93$$72, _96$$72, _97$$74, _98$$73, itemTrimmed$$76, lastSpacePosition$$76, _102$$76, _113$$76, perhapsExpression$$78, perhapsDirection$$78, _103$$78, _104$$78, _105$$78, _106$$78, _107$$78, _108$$78, _110$$78, _111$$80, _112$$79, _116$$82, _117$$88, _118$$91, _119$$91, _120$$91, _121$$91, _122$$91, _124$$92, _125$$92, _126$$92, _127$$92, _128$$92;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&columnAlias);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&distinct);
	ZVAL_UNDEF(&firstPrimaryKey);
	ZVAL_UNDEF(&forUpdate);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&groupItem);
	ZVAL_UNDEF(&groupItems);
	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&joinConditions);
	ZVAL_UNDEF(&joinModel);
	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&modelAlias);
	ZVAL_UNDEF(&modelColumnAlias);
	ZVAL_UNDEF(&modelInstance);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&orderItem);
	ZVAL_UNDEF(&orderItems);
	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&selectedColumn);
	ZVAL_UNDEF(&selectedColumns);
	ZVAL_UNDEF(&selectedModel);
	ZVAL_UNDEF(&selectedModels);
	ZVAL_UNDEF(&offset);
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
	ZVAL_UNDEF(&_13$$25);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_17$$28);
	ZVAL_UNDEF(&_18$$28);
	ZVAL_UNDEF(&_21$$31);
	ZVAL_UNDEF(&_22$$31);
	ZVAL_UNDEF(&_25$$34);
	ZVAL_UNDEF(&_31$$34);
	ZVAL_UNDEF(&_35$$34);
	ZVAL_UNDEF(&_29$$36);
	ZVAL_UNDEF(&_30$$37);
	ZVAL_UNDEF(&_33$$39);
	ZVAL_UNDEF(&_34$$40);
	ZVAL_UNDEF(&_36$$41);
	ZVAL_UNDEF(&_37$$41);
	ZVAL_UNDEF(&_39$$42);
	ZVAL_UNDEF(&_45$$42);
	ZVAL_UNDEF(&_49$$42);
	ZVAL_UNDEF(&_50$$42);
	ZVAL_UNDEF(&_43$$44);
	ZVAL_UNDEF(&_44$$44);
	ZVAL_UNDEF(&_47$$47);
	ZVAL_UNDEF(&_48$$47);
	ZVAL_UNDEF(&_51$$49);
	ZVAL_UNDEF(&_52$$49);
	ZVAL_UNDEF(&_54$$50);
	ZVAL_UNDEF(&_63$$50);
	ZVAL_UNDEF(&_56$$52);
	ZVAL_UNDEF(&_57$$52);
	ZVAL_UNDEF(&_58$$53);
	ZVAL_UNDEF(&_59$$53);
	ZVAL_UNDEF(&_60$$54);
	ZVAL_UNDEF(&_61$$54);
	ZVAL_UNDEF(&_62$$55);
	ZVAL_UNDEF(&_65$$57);
	ZVAL_UNDEF(&_66$$57);
	ZVAL_UNDEF(&_67$$58);
	ZVAL_UNDEF(&_68$$58);
	ZVAL_UNDEF(&_69$$59);
	ZVAL_UNDEF(&_70$$59);
	ZVAL_UNDEF(&_71$$60);
	ZVAL_UNDEF(&_72$$62);
	ZVAL_UNDEF(&_74$$63);
	ZVAL_UNDEF(&_77$$63);
	ZVAL_UNDEF(&_80$$63);
	ZVAL_UNDEF(&_81$$63);
	ZVAL_UNDEF(&_76$$64);
	ZVAL_UNDEF(&_79$$65);
	ZVAL_UNDEF(&_82$$67);
	ZVAL_UNDEF(&_84$$69);
	ZVAL_UNDEF(&_100$$69);
	ZVAL_UNDEF(&_114$$69);
	ZVAL_UNDEF(&_115$$69);
	ZVAL_UNDEF(&itemTrimmed$$70);
	ZVAL_UNDEF(&lastSpacePosition$$70);
	ZVAL_UNDEF(&_86$$70);
	ZVAL_UNDEF(&_99$$70);
	ZVAL_UNDEF(&perhapsExpression$$72);
	ZVAL_UNDEF(&perhapsDirection$$72);
	ZVAL_UNDEF(&_88$$72);
	ZVAL_UNDEF(&_89$$72);
	ZVAL_UNDEF(&_90$$72);
	ZVAL_UNDEF(&_91$$72);
	ZVAL_UNDEF(&_92$$72);
	ZVAL_UNDEF(&_93$$72);
	ZVAL_UNDEF(&_96$$72);
	ZVAL_UNDEF(&_97$$74);
	ZVAL_UNDEF(&_98$$73);
	ZVAL_UNDEF(&itemTrimmed$$76);
	ZVAL_UNDEF(&lastSpacePosition$$76);
	ZVAL_UNDEF(&_102$$76);
	ZVAL_UNDEF(&_113$$76);
	ZVAL_UNDEF(&perhapsExpression$$78);
	ZVAL_UNDEF(&perhapsDirection$$78);
	ZVAL_UNDEF(&_103$$78);
	ZVAL_UNDEF(&_104$$78);
	ZVAL_UNDEF(&_105$$78);
	ZVAL_UNDEF(&_106$$78);
	ZVAL_UNDEF(&_107$$78);
	ZVAL_UNDEF(&_108$$78);
	ZVAL_UNDEF(&_110$$78);
	ZVAL_UNDEF(&_111$$80);
	ZVAL_UNDEF(&_112$$79);
	ZVAL_UNDEF(&_116$$82);
	ZVAL_UNDEF(&_117$$88);
	ZVAL_UNDEF(&_118$$91);
	ZVAL_UNDEF(&_119$$91);
	ZVAL_UNDEF(&_120$$91);
	ZVAL_UNDEF(&_121$$91);
	ZVAL_UNDEF(&_122$$91);
	ZVAL_UNDEF(&_124$$92);
	ZVAL_UNDEF(&_125$$92);
	ZVAL_UNDEF(&_126$$92);
	ZVAL_UNDEF(&_127$$92);
	ZVAL_UNDEF(&_128$$92);
	ZVAL_UNDEF(&_5$$8);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("models", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("conditions", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("distinct", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("columns", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("joins", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("group", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("having", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("order", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("limit", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("offset", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("forUpdate", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&offset);
	ZVAL_NULL(&offset);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1091, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1091, &container);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1082, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&models))) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_mvc_model_query_exceptions_builder_modelrequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Model/Query/Builder.zep", 715);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		if (UNEXPECTED(!zephir_is_true(&models))) {
			ZEPHIR_INIT_VAR(&_2$$7);
			object_init_ex(&_2$$7, phalcon_mvc_model_query_exceptions_builder_modelrequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$7, "phalcon/Mvc/Model/Query/Builder.zep", 719);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1078, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&conditions, &_0);
	if (zephir_is_numeric(&conditions)) {
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			if (UNEXPECTED(zephir_fast_count_int(&models) > 1)) {
				ZEPHIR_INIT_VAR(&_3$$10);
				object_init_ex(&_3$$10, phalcon_mvc_model_query_exceptions_builder_builderconditioninvalid_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$10, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$10, "phalcon/Mvc/Model/Query/Builder.zep", 732);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&model);
			zephir_array_fetch_long(&model, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 735);
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
		if (!(ZEPHIR_IS_EMPTY(&primaryKeys))) {
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
						zephir_throw_exception_debug(&_8$$17, "phalcon/Mvc/Model/Query/Builder.zep", 769);
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
			zephir_throw_exception_debug(&_11$$19, "phalcon/Mvc/Model/Query/Builder.zep", 791);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1081, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columns, &_0);
	if (Z_TYPE_P(&columns) != IS_NULL) {
		if (Z_TYPE_P(&columns) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&selectedColumns);
			array_init(&selectedColumns);
			if (Z_TYPE_P(&columns) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_13$$25);
				zephir_string_to_char_array(&_13$$25, &columns);
				_12$$25 = &_13$$25;
			} else {
				_12$$25 = &columns;
			}
			zephir_is_iterable(_12$$25, 0, "phalcon/Mvc/Model/Query/Builder.zep", 824);
			if (Z_TYPE_P(_12$$25) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_12$$25), _15$$25, _16$$25, _14$$25)
				{
					ZEPHIR_INIT_NVAR(&columnAlias);
					if (_16$$25 != NULL) { 
						ZVAL_STR_COPY(&columnAlias, _16$$25);
					} else {
						ZVAL_LONG(&columnAlias, _15$$25);
					}
					ZEPHIR_INIT_NVAR(&column);
					ZVAL_COPY(&column, _14$$25);
					if (Z_TYPE_P(&columnAlias) == IS_LONG) {
						zephir_array_append(&selectedColumns, &column, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 818);
					} else {
						ZEPHIR_CALL_METHOD(&_17$$28, this_ptr, "autoescape", NULL, 0, &columnAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_18$$28);
						ZEPHIR_CONCAT_VSV(&_18$$28, &column, " AS ", &_17$$28);
						zephir_array_append(&selectedColumns, &_18$$28, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 820);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _12$$25, "rewind", NULL, 0);
				zephir_check_call_status();
				_20$$25 = 1;
				while (1) {
					if (_20$$25) {
						_20$$25 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _12$$25, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_19$$25, _12$$25, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_19$$25)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&columnAlias, _12$$25, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&column, _12$$25, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&columnAlias) == IS_LONG) {
							zephir_array_append(&selectedColumns, &column, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 818);
						} else {
							ZEPHIR_CALL_METHOD(&_21$$31, this_ptr, "autoescape", NULL, 0, &columnAlias);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_22$$31);
							ZEPHIR_CONCAT_VSV(&_22$$31, &column, " AS ", &_21$$31);
							zephir_array_append(&selectedColumns, &_22$$31, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 820);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&column);
			ZEPHIR_INIT_NVAR(&columnAlias);
			ZEPHIR_INIT_VAR(&_23$$25);
			zephir_fast_join_str(&_23$$25, SL(", "), &selectedColumns);
			zephir_concat_self(&phql, &_23$$25);
		} else {
			zephir_concat_self(&phql, &columns);
		}
	} else {
		if (Z_TYPE_P(&models) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&selectedColumns);
			array_init(&selectedColumns);
			if (Z_TYPE_P(&models) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_25$$34);
				zephir_string_to_char_array(&_25$$34, &models);
				_24$$34 = &_25$$34;
			} else {
				_24$$34 = &models;
			}
			zephir_is_iterable(_24$$34, 0, "phalcon/Mvc/Model/Query/Builder.zep", 845);
			if (Z_TYPE_P(_24$$34) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_24$$34), _27$$34, _28$$34, _26$$34)
				{
					ZEPHIR_INIT_NVAR(&modelColumnAlias);
					if (_28$$34 != NULL) { 
						ZVAL_STR_COPY(&modelColumnAlias, _28$$34);
					} else {
						ZVAL_LONG(&modelColumnAlias, _27$$34);
					}
					ZEPHIR_INIT_NVAR(&model);
					ZVAL_COPY(&model, _26$$34);
					ZEPHIR_INIT_NVAR(&selectedColumn);
					if (Z_TYPE_P(&modelColumnAlias) == IS_LONG) {
						ZEPHIR_CALL_METHOD(&_29$$36, this_ptr, "autoescape", NULL, 0, &model);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VS(&selectedColumn, &_29$$36, ".*");
					} else {
						ZEPHIR_CALL_METHOD(&_30$$37, this_ptr, "autoescape", NULL, 0, &modelColumnAlias);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VS(&selectedColumn, &_30$$37, ".*");
					}
					zephir_array_append(&selectedColumns, &selectedColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 842);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _24$$34, "rewind", NULL, 0);
				zephir_check_call_status();
				_32$$34 = 1;
				while (1) {
					if (_32$$34) {
						_32$$34 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _24$$34, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_31$$34, _24$$34, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_31$$34)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&modelColumnAlias, _24$$34, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&model, _24$$34, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&selectedColumn);
						if (Z_TYPE_P(&modelColumnAlias) == IS_LONG) {
							ZEPHIR_CALL_METHOD(&_33$$39, this_ptr, "autoescape", NULL, 0, &model);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VS(&selectedColumn, &_33$$39, ".*");
						} else {
							ZEPHIR_CALL_METHOD(&_34$$40, this_ptr, "autoescape", NULL, 0, &modelColumnAlias);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VS(&selectedColumn, &_34$$40, ".*");
						}
						zephir_array_append(&selectedColumns, &selectedColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 842);
				}
			}
			ZEPHIR_INIT_NVAR(&model);
			ZEPHIR_INIT_NVAR(&modelColumnAlias);
			ZEPHIR_INIT_VAR(&_35$$34);
			zephir_fast_join_str(&_35$$34, SL(", "), &selectedColumns);
			zephir_concat_self(&phql, &_35$$34);
		} else {
			ZEPHIR_CALL_METHOD(&_36$$41, this_ptr, "autoescape", NULL, 0, &models);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_37$$41);
			ZEPHIR_CONCAT_VS(&_37$$41, &_36$$41, ".*");
			zephir_concat_self(&phql, &_37$$41);
		}
	}
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&selectedModels);
		array_init(&selectedModels);
		if (Z_TYPE_P(&models) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_39$$42);
			zephir_string_to_char_array(&_39$$42, &models);
			_38$$42 = &_39$$42;
		} else {
			_38$$42 = &models;
		}
		zephir_is_iterable(_38$$42, 0, "phalcon/Mvc/Model/Query/Builder.zep", 867);
		if (Z_TYPE_P(_38$$42) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_38$$42), _41$$42, _42$$42, _40$$42)
			{
				ZEPHIR_INIT_NVAR(&modelAlias);
				if (_42$$42 != NULL) { 
					ZVAL_STR_COPY(&modelAlias, _42$$42);
				} else {
					ZVAL_LONG(&modelAlias, _41$$42);
				}
				ZEPHIR_INIT_NVAR(&model);
				ZVAL_COPY(&model, _40$$42);
				if (Z_TYPE_P(&modelAlias) == IS_STRING) {
					ZEPHIR_CALL_METHOD(&_43$$44, this_ptr, "autoescape", NULL, 0, &model);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_44$$44, this_ptr, "autoescape", NULL, 0, &modelAlias);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&selectedModel);
					ZEPHIR_CONCAT_VSV(&selectedModel, &_43$$44, " AS ", &_44$$44);
				} else {
					ZEPHIR_CALL_METHOD(&selectedModel, this_ptr, "autoescape", NULL, 0, &model);
					zephir_check_call_status();
				}
				zephir_array_append(&selectedModels, &selectedModel, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 864);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _38$$42, "rewind", NULL, 0);
			zephir_check_call_status();
			_46$$42 = 1;
			while (1) {
				if (_46$$42) {
					_46$$42 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _38$$42, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_45$$42, _38$$42, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_45$$42)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&modelAlias, _38$$42, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&model, _38$$42, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&modelAlias) == IS_STRING) {
						ZEPHIR_CALL_METHOD(&_47$$47, this_ptr, "autoescape", NULL, 0, &model);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_48$$47, this_ptr, "autoescape", NULL, 0, &modelAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&selectedModel);
						ZEPHIR_CONCAT_VSV(&selectedModel, &_47$$47, " AS ", &_48$$47);
					} else {
						ZEPHIR_CALL_METHOD(&selectedModel, this_ptr, "autoescape", NULL, 0, &model);
						zephir_check_call_status();
					}
					zephir_array_append(&selectedModels, &selectedModel, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 864);
			}
		}
		ZEPHIR_INIT_NVAR(&model);
		ZEPHIR_INIT_NVAR(&modelAlias);
		ZEPHIR_INIT_VAR(&_49$$42);
		zephir_fast_join_str(&_49$$42, SL(", "), &selectedModels);
		ZEPHIR_INIT_VAR(&_50$$42);
		ZEPHIR_CONCAT_SV(&_50$$42, " FROM ", &_49$$42);
		zephir_concat_self(&phql, &_50$$42);
	} else {
		ZEPHIR_CALL_METHOD(&_51$$49, this_ptr, "autoescape", NULL, 0, &models);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_52$$49);
		ZEPHIR_CONCAT_SV(&_52$$49, " FROM ", &_51$$49);
		zephir_concat_self(&phql, &_52$$49);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_5, 1084, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&joins, &_0);
	if (Z_TYPE_P(&joins) == IS_ARRAY) {
		if (Z_TYPE_P(&joins) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_54$$50);
			zephir_string_to_char_array(&_54$$50, &joins);
			_53$$50 = &_54$$50;
		} else {
			_53$$50 = &joins;
		}
		zephir_is_iterable(_53$$50, 0, "phalcon/Mvc/Model/Query/Builder.zep", 922);
		if (Z_TYPE_P(_53$$50) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_53$$50), _55$$50)
			{
				ZEPHIR_INIT_NVAR(&join);
				ZVAL_COPY(&join, _55$$50);
				ZEPHIR_OBS_NVAR(&joinModel);
				zephir_array_fetch_long(&joinModel, &join, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 882);
				ZEPHIR_OBS_NVAR(&joinConditions);
				zephir_array_fetch_long(&joinConditions, &join, 1, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 887);
				ZEPHIR_OBS_NVAR(&joinAlias);
				zephir_array_fetch_long(&joinAlias, &join, 2, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 892);
				ZEPHIR_OBS_NVAR(&joinType);
				zephir_array_fetch_long(&joinType, &join, 3, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 897);
				if (zephir_is_true(&joinType)) {
					ZEPHIR_CALL_METHOD(&_56$$52, this_ptr, "autoescape", NULL, 0, &joinModel);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_57$$52);
					ZEPHIR_CONCAT_SVSV(&_57$$52, " ", &joinType, " JOIN ", &_56$$52);
					zephir_concat_self(&phql, &_57$$52);
				} else {
					ZEPHIR_CALL_METHOD(&_58$$53, this_ptr, "autoescape", NULL, 0, &joinModel);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_59$$53);
					ZEPHIR_CONCAT_SV(&_59$$53, " JOIN ", &_58$$53);
					zephir_concat_self(&phql, &_59$$53);
				}
				if (zephir_is_true(&joinAlias)) {
					ZEPHIR_CALL_METHOD(&_60$$54, this_ptr, "autoescape", NULL, 0, &joinAlias);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_61$$54);
					ZEPHIR_CONCAT_SV(&_61$$54, " AS ", &_60$$54);
					zephir_concat_self(&phql, &_61$$54);
				}
				if (zephir_is_true(&joinConditions)) {
					ZEPHIR_INIT_NVAR(&_62$$55);
					ZEPHIR_CONCAT_SV(&_62$$55, " ON ", &joinConditions);
					zephir_concat_self(&phql, &_62$$55);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _53$$50, "rewind", NULL, 0);
			zephir_check_call_status();
			_64$$50 = 1;
			while (1) {
				if (_64$$50) {
					_64$$50 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _53$$50, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_63$$50, _53$$50, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_63$$50)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&join, _53$$50, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&joinModel);
					zephir_array_fetch_long(&joinModel, &join, 0, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 882);
					ZEPHIR_OBS_NVAR(&joinConditions);
					zephir_array_fetch_long(&joinConditions, &join, 1, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 887);
					ZEPHIR_OBS_NVAR(&joinAlias);
					zephir_array_fetch_long(&joinAlias, &join, 2, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 892);
					ZEPHIR_OBS_NVAR(&joinType);
					zephir_array_fetch_long(&joinType, &join, 3, PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 897);
					if (zephir_is_true(&joinType)) {
						ZEPHIR_CALL_METHOD(&_65$$57, this_ptr, "autoescape", NULL, 0, &joinModel);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_66$$57);
						ZEPHIR_CONCAT_SVSV(&_66$$57, " ", &joinType, " JOIN ", &_65$$57);
						zephir_concat_self(&phql, &_66$$57);
					} else {
						ZEPHIR_CALL_METHOD(&_67$$58, this_ptr, "autoescape", NULL, 0, &joinModel);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_68$$58);
						ZEPHIR_CONCAT_SV(&_68$$58, " JOIN ", &_67$$58);
						zephir_concat_self(&phql, &_68$$58);
					}
					if (zephir_is_true(&joinAlias)) {
						ZEPHIR_CALL_METHOD(&_69$$59, this_ptr, "autoescape", NULL, 0, &joinAlias);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_70$$59);
						ZEPHIR_CONCAT_SV(&_70$$59, " AS ", &_69$$59);
						zephir_concat_self(&phql, &_70$$59);
					}
					if (zephir_is_true(&joinConditions)) {
						ZEPHIR_INIT_NVAR(&_71$$60);
						ZEPHIR_CONCAT_SV(&_71$$60, " ON ", &joinConditions);
						zephir_concat_self(&phql, &_71$$60);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&join);
	}
	if (Z_TYPE_P(&conditions) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(&conditions))) {
			ZEPHIR_INIT_VAR(&_72$$62);
			ZEPHIR_CONCAT_SV(&_72$$62, " WHERE ", &conditions);
			zephir_concat_self(&phql, &_72$$62);
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_6, 1092, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&group, &_0);
	if (!(ZEPHIR_IS_EMPTY(&group))) {
		ZEPHIR_INIT_VAR(&groupItems);
		array_init(&groupItems);
		if (Z_TYPE_P(&group) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_74$$63);
			zephir_string_to_char_array(&_74$$63, &group);
			_73$$63 = &_74$$63;
		} else {
			_73$$63 = &group;
		}
		zephir_is_iterable(_73$$63, 0, "phalcon/Mvc/Model/Query/Builder.zep", 942);
		if (Z_TYPE_P(_73$$63) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_73$$63), _75$$63)
			{
				ZEPHIR_INIT_NVAR(&groupItem);
				ZVAL_COPY(&groupItem, _75$$63);
				ZEPHIR_CALL_METHOD(&_76$$64, this_ptr, "autoescape", NULL, 0, &groupItem);
				zephir_check_call_status();
				zephir_array_append(&groupItems, &_76$$64, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 939);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _73$$63, "rewind", NULL, 0);
			zephir_check_call_status();
			_78$$63 = 1;
			while (1) {
				if (_78$$63) {
					_78$$63 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _73$$63, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_77$$63, _73$$63, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_77$$63)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupItem, _73$$63, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_79$$65, this_ptr, "autoescape", NULL, 0, &groupItem);
					zephir_check_call_status();
					zephir_array_append(&groupItems, &_79$$65, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 939);
			}
		}
		ZEPHIR_INIT_NVAR(&groupItem);
		ZEPHIR_INIT_VAR(&_80$$63);
		zephir_fast_join_str(&_80$$63, SL(", "), &groupItems);
		ZEPHIR_INIT_VAR(&_81$$63);
		ZEPHIR_CONCAT_SV(&_81$$63, " GROUP BY ", &_80$$63);
		zephir_concat_self(&phql, &_81$$63);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_7, 1085, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&having, &_0);
	if (Z_TYPE_P(&having) != IS_NULL) {
		if (!(ZEPHIR_IS_EMPTY(&having))) {
			ZEPHIR_INIT_VAR(&_82$$67);
			ZEPHIR_CONCAT_SV(&_82$$67, " HAVING ", &having);
			zephir_concat_self(&phql, &_82$$67);
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_8, 1086, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&order, &_0);
	if (Z_TYPE_P(&order) != IS_NULL) {
		if (Z_TYPE_P(&order) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&orderItems);
			array_init(&orderItems);
			if (Z_TYPE_P(&order) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_84$$69);
				zephir_string_to_char_array(&_84$$69, &order);
				_83$$69 = &_84$$69;
			} else {
				_83$$69 = &order;
			}
			zephir_is_iterable(_83$$69, 0, "phalcon/Mvc/Model/Query/Builder.zep", 1007);
			if (Z_TYPE_P(_83$$69) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_83$$69), _85$$69)
				{
					ZEPHIR_INIT_NVAR(&orderItem);
					ZVAL_COPY(&orderItem, _85$$69);
					if (Z_TYPE_P(&orderItem) == IS_LONG) {
						zephir_array_append(&orderItems, &orderItem, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 969);
						continue;
					}
					ZEPHIR_INIT_NVAR(&itemTrimmed$$70);
					zephir_fast_trim(&itemTrimmed$$70, &orderItem, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_CPY_WRT(&itemTrimmed$$70, &itemTrimmed$$70);
					ZEPHIR_INIT_NVAR(&_86$$70);
					ZVAL_STRING(&_86$$70, " ");
					ZEPHIR_CALL_FUNCTION(&lastSpacePosition$$70, "strrpos", &_87, 0, &itemTrimmed$$70, &_86$$70);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&lastSpacePosition$$70, &lastSpacePosition$$70);
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&lastSpacePosition$$70)) {
						ZVAL_LONG(&_88$$72, 0);
						ZEPHIR_INIT_NVAR(&_89$$72);
						zephir_substr(&_89$$72, &itemTrimmed$$70, 0 , zephir_get_intval(&lastSpacePosition$$70), 0);
						ZEPHIR_INIT_NVAR(&perhapsExpression$$72);
						zephir_fast_trim(&perhapsExpression$$72, &_89$$72, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_CPY_WRT(&perhapsExpression$$72, &perhapsExpression$$72);
						ZVAL_LONG(&_90$$72, (zephir_get_numberval(&lastSpacePosition$$70) + 1));
						ZEPHIR_INIT_NVAR(&_91$$72);
						zephir_substr(&_91$$72, &itemTrimmed$$70, zephir_get_intval(&_90$$72), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						ZEPHIR_INIT_NVAR(&perhapsDirection$$72);
						zephir_fast_trim(&perhapsDirection$$72, &_91$$72, NULL , ZEPHIR_TRIM_RIGHT);
						ZEPHIR_CPY_WRT(&perhapsDirection$$72, &perhapsDirection$$72);
						ZEPHIR_INIT_NVAR(&_92$$72);
						ZVAL_STRING(&_92$$72, "desc");
						ZEPHIR_CALL_FUNCTION(&_93$$72, "strcasecmp", &_94, 87, &perhapsDirection$$72, &_92$$72);
						zephir_check_call_status();
						_95$$72 = ZEPHIR_IS_LONG(&_93$$72, 0);
						if (!(_95$$72)) {
							ZEPHIR_INIT_NVAR(&_92$$72);
							ZVAL_STRING(&_92$$72, "asc");
							ZEPHIR_CALL_FUNCTION(&_96$$72, "strcasecmp", &_94, 87, &perhapsDirection$$72, &_92$$72);
							zephir_check_call_status();
							_95$$72 = ZEPHIR_IS_LONG(&_96$$72, 0);
						}
						if (_95$$72) {
							if (!(zephir_memnstr_str(&perhapsExpression$$72, SL(" "), "phalcon/Mvc/Model/Query/Builder.zep", 992))) {
								ZEPHIR_CALL_METHOD(&_97$$74, this_ptr, "autoescape", NULL, 0, &perhapsExpression$$72);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&perhapsExpression$$72, &_97$$74);
							}
							ZEPHIR_INIT_NVAR(&_98$$73);
							ZEPHIR_CONCAT_VSV(&_98$$73, &perhapsExpression$$72, " ", &perhapsDirection$$72);
							zephir_array_append(&orderItems, &_98$$73, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 996);
						} else {
							zephir_array_append(&orderItems, &itemTrimmed$$70, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 998);
						}
						continue;
					}
					ZEPHIR_CALL_METHOD(&_99$$70, this_ptr, "autoescape", NULL, 0, &itemTrimmed$$70);
					zephir_check_call_status();
					zephir_array_append(&orderItems, &_99$$70, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1004);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _83$$69, "rewind", NULL, 0);
				zephir_check_call_status();
				_101$$69 = 1;
				while (1) {
					if (_101$$69) {
						_101$$69 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _83$$69, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_100$$69, _83$$69, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_100$$69)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&orderItem, _83$$69, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&orderItem) == IS_LONG) {
							zephir_array_append(&orderItems, &orderItem, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 969);
							continue;
						}
						ZEPHIR_INIT_NVAR(&itemTrimmed$$76);
						zephir_fast_trim(&itemTrimmed$$76, &orderItem, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_CPY_WRT(&itemTrimmed$$76, &itemTrimmed$$76);
						ZEPHIR_INIT_NVAR(&_102$$76);
						ZVAL_STRING(&_102$$76, " ");
						ZEPHIR_CALL_FUNCTION(&lastSpacePosition$$76, "strrpos", &_87, 0, &itemTrimmed$$76, &_102$$76);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&lastSpacePosition$$76, &lastSpacePosition$$76);
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&lastSpacePosition$$76)) {
							ZVAL_LONG(&_103$$78, 0);
							ZEPHIR_INIT_NVAR(&_104$$78);
							zephir_substr(&_104$$78, &itemTrimmed$$76, 0 , zephir_get_intval(&lastSpacePosition$$76), 0);
							ZEPHIR_INIT_NVAR(&perhapsExpression$$78);
							zephir_fast_trim(&perhapsExpression$$78, &_104$$78, NULL , ZEPHIR_TRIM_BOTH);
							ZEPHIR_CPY_WRT(&perhapsExpression$$78, &perhapsExpression$$78);
							ZVAL_LONG(&_105$$78, (zephir_get_numberval(&lastSpacePosition$$76) + 1));
							ZEPHIR_INIT_NVAR(&_106$$78);
							zephir_substr(&_106$$78, &itemTrimmed$$76, zephir_get_intval(&_105$$78), 0, ZEPHIR_SUBSTR_NO_LENGTH);
							ZEPHIR_INIT_NVAR(&perhapsDirection$$78);
							zephir_fast_trim(&perhapsDirection$$78, &_106$$78, NULL , ZEPHIR_TRIM_RIGHT);
							ZEPHIR_CPY_WRT(&perhapsDirection$$78, &perhapsDirection$$78);
							ZEPHIR_INIT_NVAR(&_107$$78);
							ZVAL_STRING(&_107$$78, "desc");
							ZEPHIR_CALL_FUNCTION(&_108$$78, "strcasecmp", &_94, 87, &perhapsDirection$$78, &_107$$78);
							zephir_check_call_status();
							_109$$78 = ZEPHIR_IS_LONG(&_108$$78, 0);
							if (!(_109$$78)) {
								ZEPHIR_INIT_NVAR(&_107$$78);
								ZVAL_STRING(&_107$$78, "asc");
								ZEPHIR_CALL_FUNCTION(&_110$$78, "strcasecmp", &_94, 87, &perhapsDirection$$78, &_107$$78);
								zephir_check_call_status();
								_109$$78 = ZEPHIR_IS_LONG(&_110$$78, 0);
							}
							if (_109$$78) {
								if (!(zephir_memnstr_str(&perhapsExpression$$78, SL(" "), "phalcon/Mvc/Model/Query/Builder.zep", 992))) {
									ZEPHIR_CALL_METHOD(&_111$$80, this_ptr, "autoescape", NULL, 0, &perhapsExpression$$78);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&perhapsExpression$$78, &_111$$80);
								}
								ZEPHIR_INIT_NVAR(&_112$$79);
								ZEPHIR_CONCAT_VSV(&_112$$79, &perhapsExpression$$78, " ", &perhapsDirection$$78);
								zephir_array_append(&orderItems, &_112$$79, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 996);
							} else {
								zephir_array_append(&orderItems, &itemTrimmed$$76, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 998);
							}
							continue;
						}
						ZEPHIR_CALL_METHOD(&_113$$76, this_ptr, "autoescape", NULL, 0, &itemTrimmed$$76);
						zephir_check_call_status();
						zephir_array_append(&orderItems, &_113$$76, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1004);
				}
			}
			ZEPHIR_INIT_NVAR(&orderItem);
			ZEPHIR_INIT_VAR(&_114$$69);
			zephir_fast_join_str(&_114$$69, SL(", "), &orderItems);
			ZEPHIR_INIT_VAR(&_115$$69);
			ZEPHIR_CONCAT_SV(&_115$$69, " ORDER BY ", &_114$$69);
			zephir_concat_self(&phql, &_115$$69);
		} else {
			ZEPHIR_INIT_VAR(&_116$$82);
			ZEPHIR_CONCAT_SV(&_116$$82, " ORDER BY ", &order);
			zephir_concat_self(&phql, &_116$$82);
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_9, 1087, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&limit, &_0);
	if (Z_TYPE_P(&limit) != IS_NULL) {
		ZEPHIR_INIT_VAR(&number);
		ZVAL_NULL(&number);
		if (Z_TYPE_P(&limit) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&number);
			zephir_array_fetch_string(&number, &limit, SL("number"), PH_NOISY, "phalcon/Mvc/Model/Query/Builder.zep", 1021);
			ZEPHIR_OBS_NVAR(&offset);
			if (zephir_array_isset_string_fetch(&offset, &limit, SL("offset"), 0)) {
				if (!(zephir_is_numeric(&offset))) {
					ZEPHIR_INIT_NVAR(&offset);
					ZVAL_LONG(&offset, 0);
				}
			}
		} else {
			if (zephir_is_numeric(&limit)) {
				ZEPHIR_CPY_WRT(&number, &limit);
				zephir_read_property_cached(&_117$$88, this_ptr, _zephir_prop_10, 1088, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&offset, &_117$$88);
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
			ZVAL_LONG(&_118$$91, 10);
			ZEPHIR_CALL_FUNCTION(&_119$$91, "intval", NULL, 96, &number, &_118$$91);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_120$$91);
			ZVAL_STRING(&_120$$91, "APL0");
			zephir_update_property_array(this_ptr, SL("bindParams"), &_120$$91, &_119$$91);
			ZEPHIR_INIT_VAR(&_121$$91);
			ZVAL_STRING(&_121$$91, "APL0");
			ZEPHIR_INIT_VAR(&_122$$91);
			ZVAL_LONG(&_122$$91, 1);
			zephir_update_property_array(this_ptr, SL("bindTypes"), &_121$$91, &_122$$91);
			_123$$91 = zephir_is_numeric(&offset);
			if (_123$$91) {
				_123$$91 = !ZEPHIR_IS_LONG_IDENTICAL(&offset, 0);
			}
			if (_123$$91) {
				zephir_concat_self_str(&phql, SL(" OFFSET :APL1:"));
				ZVAL_LONG(&_124$$92, 10);
				ZEPHIR_CALL_FUNCTION(&_125$$92, "intval", NULL, 96, &offset, &_124$$92);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_126$$92);
				ZVAL_STRING(&_126$$92, "APL1");
				zephir_update_property_array(this_ptr, SL("bindParams"), &_126$$92, &_125$$92);
				ZEPHIR_INIT_VAR(&_127$$92);
				ZVAL_STRING(&_127$$92, "APL1");
				ZEPHIR_INIT_VAR(&_128$$92);
				ZVAL_LONG(&_128$$92, 1);
				zephir_update_property_array(this_ptr, SL("bindTypes"), &_127$$92, &_128$$92);
			}
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_11, 1089, PH_NOISY_CC | PH_READONLY);
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
	zend_bool _7;
	zval _3;
	zval query, bindParams, bindTypes, phql, container, _0, _2, _4, _5, _1$$3, _6$$6, _8$$7;
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
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("bindParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("bindTypes", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("sharedLock", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("resultsetRowClass", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&phql, this_ptr, "getphql", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1091, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_managerormservicesunavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1076);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1079, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&bindParams, &_0);
	if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, &bindParams);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1080, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&bindTypes, &_0);
	if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, &bindTypes);
		zephir_check_call_status();
	}
	zephir_memory_observe(&_5);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_3, 1090, PH_NOISY_CC);
	if (((Z_TYPE_P(&_5) == IS_TRUE || Z_TYPE_P(&_5) == IS_FALSE) == 1)) {
		zephir_read_property_cached(&_6$$6, this_ptr, _zephir_prop_3, 1090, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &query, "setsharedlock", NULL, 0, &_6$$6);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1093, PH_NOISY_CC | PH_READONLY);
	_7 = !ZEPHIR_IS_STRING(&_0, "");
	if (_7) {
		_7 = (zephir_method_exists_ex(&query, ZEND_STRL("setresultsetrowclass")) == SUCCESS);
	}
	if (_7) {
		zephir_read_property_cached(&_8$$7, this_ptr, _zephir_prop_4, 1093, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &query, "setresultsetrowclass", NULL, 0, &_8$$7);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&query);
}

/**
 * Returns the class that will be used to hydrate rows that are not mapped
 * to a model (custom columns/joins). An empty string means the default
 * Phalcon\Mvc\Model\Row is used.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getResultsetRowClass)
{

	RETURN_MEMBER_TYPED(getThis(), "resultsetRowClass", IS_STRING);
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
 *         "Invoices.inv_title",
 *     ]
 * );
 *```
 *
 * Passing null (or an empty array) clears the clause; the PHQL generator
 * treats both as "no GROUP BY".
 *
 * @param array|string|null group
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("group", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(group)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group);
	ZEPHIR_SEPARATE_PARAM(group);
	if (Z_TYPE_P(group) == IS_STRING) {
		if (zephir_memnstr_str(group, SL(","), "phalcon/Mvc/Model/Query/Builder.zep", 1156)) {
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1092, group);
	RETURN_THIS();
}

/**
 * Sets the HAVING condition clause
 *
 *```php
 * $builder->having("SUM(Invoices.inv_total) > 0");
 *
 * $builder->having(
 *     "SUM(Invoices.inv_total) > :sum:",
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("having", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("bindParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("bindTypes", 9, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1085, &conditions_zv);
	zephir_memory_observe(&currentBindParams);
	zephir_read_property_cached(&currentBindParams, this_ptr, _zephir_prop_1, 1079, PH_NOISY_CC);
	if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_add_function(&_0$$3, &currentBindParams, &bindParams);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1079, &_0$$3);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1079, &bindParams);
	}
	zephir_memory_observe(&currentBindTypes);
	zephir_read_property_cached(&currentBindTypes, this_ptr, _zephir_prop_2, 1080, PH_NOISY_CC);
	if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_add_function(&_1$$5, &currentBindTypes, &bindTypes);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1080, &_1$$5);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1080, &bindTypes);
	}
	RETURN_THIS();
}

/**
 * Appends an IN condition to the current HAVING conditions clause
 *
 *```php
 * $builder->inHaving("SUM(Invoices.inv_total)", [100, 200]);
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
	zephir_get_arrval(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
		zephir_get_strval(&operator, operator_param);
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
	zephir_get_arrval(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
		zephir_get_strval(&operator, operator_param);
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
 * // Inner Join model 'Invoices' with automatic conditions and alias
 * $builder->innerJoin(
 *     Invoices::class
 * );
 *
 * // Inner Join model 'Invoices' specifying conditions
 * $builder->innerJoin(
 *     Invoices::class,
 *     "Invoices.inv_id = OrdersProducts.oxp_ord_id"
 * );
 *
 * // Inner Join model 'Invoices' specifying conditions and alias
 * $builder->innerJoin(
 *     Invoices::class,
 *     "r.inv_id = OrdersProducts.oxp_ord_id",
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
 * // Inner Join model 'Invoices' with automatic conditions and alias
 * $builder->join(
 *     Invoices::class
 * );
 *
 * // Inner Join model 'Invoices' specifying conditions
 * $builder->join(
 *     Invoices::class,
 *     "Invoices.inv_id = OrdersProducts.oxp_ord_id"
 * );
 *
 * // Inner Join model 'Invoices' specifying conditions and alias
 * $builder->join(
 *     Invoices::class,
 *     "r.inv_id = OrdersProducts.oxp_ord_id",
 *     "r"
 * );
 *
 * // Left Join model 'Invoices' specifying conditions, alias and type of join
 * $builder->join(
 *     Invoices::class,
 *     "r.inv_id = OrdersProducts.oxp_ord_id",
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
 *     Invoices::class,
 *     "r.inv_id = OrdersProducts.oxp_ord_id",
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("limit", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("offset", 6, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1087, &_0);
	if (zephir_is_numeric(offset)) {
		ZVAL_LONG(&_2$$4, zephir_get_intval(offset));
		ZEPHIR_CALL_FUNCTION(&_3$$4, "abs", NULL, 0, &_2$$4);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1088, &_3$$4);
	}
	RETURN_THIS();
}

/**
 * Appends a NOT BETWEEN condition to the current HAVING conditions clause
 *
 *```php
 * $builder->notBetweenHaving("SUM(Invoices.inv_total)", 100.25, 200.50);
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
		zephir_get_strval(&operator, operator_param);
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
		zephir_get_strval(&operator, operator_param);
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
 * $builder->notInHaving("SUM(Invoices.inv_total)", [100, 200]);
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
	zephir_get_arrval(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
		zephir_get_strval(&operator, operator_param);
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
	zephir_get_arrval(&values, values_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "and");
	} else {
		zephir_get_strval(&operator, operator_param);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("offset", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &offset_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, offset);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1088, &_0);
	RETURN_THISW();
}

/**
 * Appends a condition to the current HAVING conditions clause using an OR operator
 *
 *```php
 * $builder->orHaving("SUM(Invoices.inv_total) > 0");
 *
 * $builder->orHaving(
 *     "SUM(Invoices.inv_total) > :sum:",
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("having", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&currentConditions);
	zephir_read_property_cached(&currentConditions, this_ptr, _zephir_prop_0, 1085, PH_NOISY_CC);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("conditions", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&currentConditions);
	zephir_read_property_cached(&currentConditions, this_ptr, _zephir_prop_0, 1078, PH_NOISY_CC);
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
 * $builder->orderBy("Invoices.inv_title");
 * $builder->orderBy(["1", "Invoices.inv_title"]);
 * $builder->orderBy(["Invoices.inv_title DESC"]);
 *```
 *
 * @param array|string orderBy
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy)
{
	zval *orderBy, orderBy_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderBy_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("order", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(orderBy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &orderBy);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1086, orderBy);
	RETURN_THISW();
}

/**
 * Adds a RIGHT join to the query
 *
 *```php
 * $builder->rightJoin(
 *     Invoices::class,
 *     "r.inv_id = OrdersProducts.oxp_ord_id",
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("bindParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);
	zephir_get_arrval(&bindParams, bindParams_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (merge) {
		zephir_memory_observe(&currentBindParams);
		zephir_read_property_cached(&currentBindParams, this_ptr, _zephir_prop_0, 1079, PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindParams, &bindParams);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1079, &_0$$4);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1079, &bindParams);
		}
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1079, &bindParams);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("bindTypes", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &bindTypes_param, &merge_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (UNEXPECTED(merge)) {
		zephir_memory_observe(&currentBindTypes);
		zephir_read_property_cached(&currentBindTypes, this_ptr, _zephir_prop_0, 1080, PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindTypes, &bindTypes);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1080, &_0$$4);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1080, &bindTypes);
		}
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1080, &bindTypes);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1091, container);
}

/**
 * Sets the class used to hydrate rows that are not mapped to a model
 * (custom columns/joins). The class must be a subclass of
 * Phalcon\Mvc\Model\Row. Validation is performed by the underlying
 * Phalcon\Mvc\Model\Query when the query is built.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setResultsetRowClass)
{
	zval resultsetRowClass_zv;
	zend_string *resultsetRowClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resultsetRowClass_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("resultsetRowClass", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(resultsetRowClass)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&resultsetRowClass_zv, resultsetRowClass);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1093, &resultsetRowClass_zv);
	RETURN_THISW();
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("conditions", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("bindParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("bindTypes", 9, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1078, &conditions_zv);
	if (!(ZEPHIR_IS_EMPTY(&bindParams))) {
		zephir_memory_observe(&currentBindParams);
		zephir_read_property_cached(&currentBindParams, this_ptr, _zephir_prop_1, 1079, PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindParams, &bindParams);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1079, &_0$$4);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1079, &bindParams);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&bindTypes))) {
		zephir_memory_observe(&currentBindTypes);
		zephir_read_property_cached(&currentBindTypes, this_ptr, _zephir_prop_2, 1080, PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$7);
			zephir_add_function(&_1$$7, &currentBindTypes, &bindTypes);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1080, &_1$$7);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1080, &bindTypes);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hiddenParamNumber", 17, 1);
	}

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
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1647);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &operator_zv, &clause_zv);
	ZEPHIR_CPY_WRT(&operatorMethod, &_2);
	zephir_memory_observe(&hiddenParam);
	zephir_read_property_cached(&hiddenParam, this_ptr, _zephir_prop_0, 1094, PH_NOISY_CC);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1094, &nextHiddenParam);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hiddenParamNumber", 17, 1);
	}

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
	zephir_get_arrval(&values, values_param);
	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_builder_operatornotavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &operator_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1690);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &operator_zv, &clause_zv);
	ZEPHIR_CPY_WRT(&operatorMethod, &_2);
	if (ZEPHIR_IS_EMPTY(&values)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_VSV(&_3$$4, &expr_zv, " != ", &expr_zv);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_3$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	zephir_memory_observe(&_4);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 1094, PH_NOISY_CC);
	hiddenParam = zephir_get_intval(&_4);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Query/Builder.zep", 1721);
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
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1712);
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
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1712);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1094, &_14);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hiddenParamNumber", 17, 1);
	}

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
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1739);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &operator_zv, &clause_zv);
	ZEPHIR_CPY_WRT(&operatorMethod, &_2);
	zephir_memory_observe(&hiddenParam);
	zephir_read_property_cached(&hiddenParam, this_ptr, _zephir_prop_0, 1094, PH_NOISY_CC);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1094, &nextHiddenParam);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hiddenParamNumber", 17, 1);
	}

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
	zephir_get_arrval(&values, values_param);
	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "and");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&operator_zv, "or");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_builder_operatornotavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &operator_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query/Builder.zep", 1781);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &operator_zv, &clause_zv);
	ZEPHIR_CPY_WRT(&operatorMethod, &_2);
	if (ZEPHIR_IS_EMPTY(&values)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_VSV(&_3$$4, &expr_zv, " != ", &expr_zv);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &operatorMethod, NULL, 0, &_3$$4);
		zephir_check_call_status();
		RETURN_THIS();
	}
	zephir_memory_observe(&_4);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 1094, PH_NOISY_CC);
	hiddenParam = zephir_get_intval(&_4);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Query/Builder.zep", 1812);
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
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1803);
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
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Query/Builder.zep", 1803);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1094, &_14);
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

