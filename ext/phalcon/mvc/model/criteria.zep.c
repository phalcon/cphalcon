
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This class is used to build the array parameter required by
 * Phalcon\Mvc\Model::find() and Phalcon\Mvc\Model::findFirst() using an
 * object-oriented interface.
 *
 * ```php
 * <?php
 *
 * $invoices = Invoices::query()
 *     ->where("inv_cst_id = :customerId:")
 *     ->andWhere("inv_created_date < '2000-01-01'")
 *     ->bind(["customerId" => 1])
 *     ->limit(5, 10)
 *     ->orderBy("inv_title")
 *     ->execute();
 * ```
 *
 * @phpstan-import-type mvc_criteria_params from MvcTypes
 * @phpstan-import-type mvc_model_bind_params from MvcTypes
 * @phpstan-import-type mvc_model_bind_types from MvcTypes
 * @phpstan-import-type mvc_model_cache_options from MvcTypes
 * @phpstan-import-type mvc_model_parameters from MvcTypes
 * @phpstan-import-type mvc_query_columns from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Criteria)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Criteria, phalcon, mvc_model_criteria, phalcon_mvc_model_criteria_method_entry, 0);

	/**
	 * @phpstan-var mvc_model_bind_params
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_criteria_ce, SL("bindParams"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var mvc_model_bind_types
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_criteria_ce, SL("bindTypes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_model_criteria_ce, SL("hiddenParamNumber"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("model"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var mvc_criteria_params
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_criteria_ce, SL("params"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_mvc_model_criteria_ce, 1, phalcon_mvc_model_criteriainterface_ce);
	zend_class_implements(phalcon_mvc_model_criteria_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;
}

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
 *
 * @phpstan-param array<string, mixed> $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput)
{
	zval _20$$16;
	zend_bool _12$$3, _5$$4, _6$$4, _7$$7, _13$$10, _14$$10, _15$$13;
	zend_ulong _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data, conditions, bind, _1$$3;
	zend_string *modelName = NULL, *operator = NULL, *_4$$3;
	zval *container, container_sub, modelName_zv, *data_param = NULL, operator_zv, __$null, attribute, field, value, type, metaData, model, dataTypes, criteria, columnMap, _0$$3, *_2$$3, _11$$3, _8$$9, _9$$9, _10$$8, _16$$15, _17$$15, _18$$14, _19$$16;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&modelName_zv);
	ZVAL_UNDEF(&operator_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&dataTypes);
	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_20$$16);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		Z_PARAM_STR(modelName)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	container = ZEND_CALL_ARG(execute_data, 1);
	data_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&modelName_zv);
	ZVAL_STR_COPY(&modelName_zv, modelName);
	zephir_get_arrval(&data, data_param);
	if (!operator) {
		operator = zend_string_init(ZEND_STRL("AND"), 0);
		zephir_memory_observe(&operator_zv);
		ZVAL_STR(&operator_zv, operator);
	} else {
		zephir_memory_observe(&operator_zv);
	ZVAL_STR_COPY(&operator_zv, operator);
	}
	ZEPHIR_INIT_VAR(&bind);
	array_init(&bind);
	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	if (!(ZEPHIR_IS_EMPTY(&data))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, container, "getShared", NULL, 0, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_fast_append(&_1$$3, &__$null);
		zephir_array_fast_append(&_1$$3, container);
		ZEPHIR_INIT_VAR(&model);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&model, &modelName_zv, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&dataTypes, &metaData, "getDataTypes", NULL, 0, &model);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getReverseColumnMap", NULL, 0, &model);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&bind);
		array_init(&bind);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model/Criteria.zep", 130);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3$$3, _4$$3, _2$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				if (_4$$3 != NULL) { 
					ZVAL_STR_COPY(&field, _4$$3);
				} else {
					ZVAL_LONG(&field, _3$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _2$$3);
				_5$$4 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				if (_5$$4) {
					_5$$4 = !(ZEPHIR_IS_EMPTY(&columnMap));
				}
				if (_5$$4) {
					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch(&attribute, &columnMap, &field, PH_NOISY, "phalcon/Mvc/Model/Criteria.zep", 105);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attribute, &field);
				}
				ZEPHIR_OBS_NVAR(&type);
				_6$$4 = zephir_array_isset_fetch(&type, &dataTypes, &attribute, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_6$$4) {
					_7$$7 = Z_TYPE_P(&value) != IS_NULL;
					if (_7$$7) {
						_7$$7 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
					}
					if (_7$$7) {
						if (ZEPHIR_IS_LONG(&type, 2)) {
							ZEPHIR_INIT_NVAR(&_8$$9);
							ZEPHIR_CONCAT_SVSVS(&_8$$9, "[", &field, "] LIKE :", &field, ":");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&conditions, &_8$$9, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 116);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_9$$9);
							ZEPHIR_CONCAT_SVS(&_9$$9, "%", &value, "%");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&bind, &field, &_9$$9, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
						ZEPHIR_INIT_NVAR(&_10$$8);
						ZEPHIR_CONCAT_SVSVS(&_10$$8, "[", &field, "] = :", &field, ":");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&conditions, &_10$$8, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 125);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&bind, &field, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			_12$$3 = 1;
			while (1) {
				if (_12$$3) {
					_12$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_11$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					_13$$10 = Z_TYPE_P(&columnMap) == IS_ARRAY;
					if (_13$$10) {
						_13$$10 = !(ZEPHIR_IS_EMPTY(&columnMap));
					}
					if (_13$$10) {
						ZEPHIR_OBS_NVAR(&attribute);
						zephir_array_fetch(&attribute, &columnMap, &field, PH_NOISY, "phalcon/Mvc/Model/Criteria.zep", 105);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attribute, &field);
					}
					ZEPHIR_OBS_NVAR(&type);
					_14$$10 = zephir_array_isset_fetch(&type, &dataTypes, &attribute, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_14$$10) {
						_15$$13 = Z_TYPE_P(&value) != IS_NULL;
						if (_15$$13) {
							_15$$13 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_15$$13) {
							if (ZEPHIR_IS_LONG(&type, 2)) {
								ZEPHIR_INIT_NVAR(&_16$$15);
								ZEPHIR_CONCAT_SVSVS(&_16$$15, "[", &field, "] LIKE :", &field, ":");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&conditions, &_16$$15, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 116);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_17$$15);
								ZEPHIR_CONCAT_SVS(&_17$$15, "%", &value, "%");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&bind, &field, &_17$$15, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								continue;
							}
							ZEPHIR_INIT_NVAR(&_18$$14);
							ZEPHIR_CONCAT_SVSVS(&_18$$14, "[", &field, "] = :", &field, ":");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&conditions, &_18$$14, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 125);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&bind, &field, &value, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&field);
	}
	ZEPHIR_INIT_VAR(&criteria);
	object_init_ex(&criteria, phalcon_mvc_model_criteria_ce);
	if (zephir_has_constructor(&criteria)) {
		ZEPHIR_CALL_METHOD(NULL, &criteria, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, &criteria, "setDI", NULL, 0, container);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&conditions))) {
		ZEPHIR_INIT_VAR(&_19$$16);
		ZEPHIR_INIT_VAR(&_20$$16);
		ZEPHIR_CONCAT_SVS(&_20$$16, " ", &operator_zv, " ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_fast_join(&_19$$16, &_20$$16, &conditions);
		ZEPHIR_CALL_METHOD(NULL, &criteria, "where", NULL, 0, &_19$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &criteria, "bind", NULL, 0, &bind);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setModelName", NULL, 0, &modelName_zv);
	zephir_check_call_status();
	RETURN_CCTOR(&criteria);
}

/**
 * Appends a condition to the current conditions using an AND operator
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentConditions, _0, _2$$3;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentConditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(bindParams)
		Z_PARAM_ZVAL_OR_NULL(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);
	zephir_get_strval(&conditions, conditions_param);
	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}
	zephir_memory_observe(&currentConditions);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&currentConditions, &_0, SL("conditions"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVSVS(&_2$$3, "(", &currentConditions, ") AND (", &conditions, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_get_strval(&conditions, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends a BETWEEN condition to the current conditions
 *
 *```php
 * $criteria->betweenWhere("price", 100.25, 200.50);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval expr_zv, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, minimumKey, nextHiddenParam, maximumKey, _0, _1;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hiddenParamNumber", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	minimum = ZEND_CALL_ARG(execute_data, 2);
	maximum = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
	zephir_memory_observe(&hiddenParam);
	zephir_read_property_cached(&hiddenParam, this_ptr, _zephir_prop_0, 1035, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	zephir_add_function(&nextHiddenParam, &hiddenParam, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "ACP", &hiddenParam);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "ACP", &nextHiddenParam);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSVSVS(&_1, &expr_zv, " BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_update_zval(&_2, &minimumKey, minimum, PH_COPY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_zval(&_2, &maximumKey, maximum, PH_COPY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andWhere", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	SEPARATE_ZVAL(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1035, &nextHiddenParam);
	RETURN_THIS();
}

/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 *
 * @phpstan-param mvc_model_bind_params $bindParams
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge, _1, _6;
	zval *bindParams_param = NULL, *merge_param = NULL, _0, _4, _5, _2$$3, _3$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$5;
	zval bindParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value_string(&_0, SL("bind"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "bind");
		zephir_update_property_array(this_ptr, SL("params"), &_3$$3, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_5);
	zephir_array_fetch_string(&_5, &_4, SL("bind"), PH_NOISY, "phalcon/Mvc/Model/Criteria.zep", 222);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = Z_TYPE_P(&_5) == IS_ARRAY;
	if (_6) {
		_6 = merge;
	}
	if (_6) {
		zephir_read_property_cached(&_7$$4, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_8$$4);
		zephir_array_fetch_string(&_8$$4, &_7$$4, SL("bind"), PH_NOISY, "phalcon/Mvc/Model/Criteria.zep", 223);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_9$$4);
		zephir_add_function(&_9$$4, &_8$$4, &bindParams);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "bind");
		zephir_update_property_array(this_ptr, SL("params"), &_10$$4, &_9$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "bind");
		zephir_update_property_array(this_ptr, SL("params"), &_11$$5, &bindParams);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_THIS();
}

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 *
 * @phpstan-param mvc_model_bind_types $bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *bindTypes_param = NULL, _0;
	zval bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &bindTypes_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "bindTypes");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &bindTypes);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Sets the cache options in the criteria
 * This method replaces all previously set cache options
 *
 * @phpstan-param mvc_model_cache_options $cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cache_param = NULL, _0;
	zval cache;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(cache, cache_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &cache_param);
	zephir_get_arrval(&cache, cache_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &cache);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
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
 * $criteria->columns("id, category");
 *
 * // Array, one column per element
 * $criteria->columns(
 *     [
 *         "inv_id",
 *         "inv_total",
 *     ]
 * );
 *
 * // Array with named key. The name of the key acts as an
 * // alias (`AS` clause)
 * $criteria->columns(
 *     [
 *         "inv_cst_id",
 *         "total_invoices" => "COUNT(*)",
 *     ]
 * );
 *
 * // Different models
 * $criteria->columns(
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
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *columns, columns_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(columns)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &columns);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "columns");
	zephir_update_property_array(this_ptr, SL("params"), &_0, columns);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Adds the conditions parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval conditions_zv, _0;
	zend_string *conditions = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(conditions)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&conditions_zv);
	ZVAL_STR_COPY(&conditions_zv, conditions);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "conditions");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &conditions_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Creates a query builder from criteria.
 *
 * ```php
 * <?php
 *
 * $invoices = Invoices::query()
 *     ->where("inv_cst_id = :customerId:")
 *     ->bind(["customerId" => 1])
 *     ->createBuilder();
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, createBuilder)
{
	zval container, manager, builder, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("model", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&container, this_ptr, "getDI", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getDefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setDI", NULL, 0, &container);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "modelsManager");
	ZEPHIR_CALL_METHOD(&_0, &container, "getShared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&builder, &manager, "createBuilder", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 1036, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_3);
	zephir_check_call_status();
	RETURN_CCTOR(&builder);
}

/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, distinct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *distinct, distinct_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&distinct_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(distinct)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &distinct);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "distinct");
	zephir_update_property_array(this_ptr, SL("params"), &_0, distinct);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Pre-loads the named relations when the criteria is executed
 *
 *```php
 * $invoices = Invoices::query()
 *     ->eager(["customer"])
 *     ->where("inv_total > 100")
 *     ->execute();
 *```
 *
 * execute() forwards the parameters to Model::find(), which owns the
 * loading, so this is a pass-through and takes the same shape: an array of
 * dot-delimited relation paths, optionally `path => options`.
 *
 * Returns the concrete criteria rather than the interface because the
 * method is deliberately not part of CriteriaInterface - adding it there
 * would break every userland implementation.
 *
 * @param array $paths relation paths
 *
 * @phpstan-param array<array-key, mixed> $paths
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, eager)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *paths_param = NULL, _0;
	zval paths;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(paths, paths_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &paths_param);
	zephir_get_arrval(&paths, paths_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "eager");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &paths);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Executes a find using the parameters built with the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute)
{
	zend_class_entry *_1;
	zval model, _2, _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&model, this_ptr, "getModelName", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&model) != IS_STRING)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidmodelname_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Criteria.zep", 406);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_fetch_class(&model);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getParams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(_1, "find", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds the "for_update" parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *forUpdate_param = NULL, _0, _1;
	zend_bool forUpdate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(forUpdate)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &forUpdate_param);
	if (!forUpdate_param) {
		forUpdate = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "for_update");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, forUpdate);
	zephir_update_property_array(this_ptr, SL("params"), &_0, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Returns the columns to be queried
 *
 * @phpstan-return mvc_query_columns|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns)
{
	zend_bool _1;
	zval columns, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&columns);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&columns, &_0, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&columns);
}

/**
 * Returns the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getWhere", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_1);
	zephir_array_fetch_string(&_1, &_0, SL("di"), PH_NOISY, "phalcon/Mvc/Model/Criteria.zep", 453);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_1);
}

/**
 * Returns the group clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getGroupBy)
{
	zend_bool _1;
	zval group, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&group);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&group, &_0, SL("group"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&group);
}

/**
 * Returns the having clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getHaving)
{
	zend_bool _1;
	zval having, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&having);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&having, &_0, SL("having"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&having);
}

/**
 * Returns the limit parameter in the criteria, which will be
 *
 * - An integer if 'limit' was set without an 'offset'
 * - An array with 'number' and 'offset' keys if an offset was set with the limit
 * - NULL if limit has not been set
 *
 * @phpstan-return array{number: int|string, offset?: int|string}|int|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit)
{
	zend_bool _1;
	zval limit, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&limit);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&limit, &_0, SL("limit"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&limit);
}

/**
 * Returns an internal model name on which the criteria will be applied
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName)
{

	RETURN_MEMBER_TYPED(getThis(), "model", IS_STRING);
}

/**
 * Returns the order clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrderBy)
{
	zend_bool _1;
	zval order, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&order);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&order, &_0, SL("order"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&order);
}

/**
 * Returns all the parameters defined in the criteria
 *
 * @phpstan-return mvc_criteria_params
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams)
{

	RETURN_MEMBER_TYPED(getThis(), "params", IS_ARRAY);
}

/**
 * Returns the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere)
{
	zend_bool _1;
	zval conditions, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&conditions);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&conditions, &_0, SL("conditions"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&conditions);
}

/**
 * Adds the group-by clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, groupBy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *group, group_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(group)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "group");
	zephir_update_property_array(this_ptr, SL("params"), &_0, group);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Adds the having clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, having)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *having, having_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&having_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(having)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &having);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "having");
	zephir_update_property_array(this_ptr, SL("params"), &_0, having);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Adds an INNER join to the query
 *
 *```php
 * <?php
 *
 * $criteria->innerJoin(
 *     Invoices::class
 * );
 *
 * $criteria->innerJoin(
 *     Invoices::class,
 *     "inv_cst_id = Customers.cst_id"
 * );
 *
 * $criteria->innerJoin(
 *     Invoices::class,
 *     "i.inv_cst_id = Customers.cst_id",
 *     "i"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval model_zv, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zend_string *model = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		conditions = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		alias = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		conditions = &conditions_sub;
		conditions = &__$null;
	}
	if (!alias) {
		alias = &alias_sub;
		alias = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "INNER");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addJoinClause", NULL, 0, &model_zv, conditions, alias, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends an IN condition to the current conditions
 *
 * ```php
 * $criteria->inWhere("id", [1, 2, 3]);
 * ```
 *
 * @phpstan-param array<array-key, mixed> $values
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere)
{
	zend_bool _5;
	zval key, queryKey, _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, bindParams, bindKeys;
	zval expr_zv, *values_param = NULL, hiddenParam, value, *_2, _4, _7, _8, _3$$4, _6$$5;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hiddenParamNumber", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(expr)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
	zephir_get_arrval(&values, values_param);
	if (ZEPHIR_IS_EMPTY(&values)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &expr_zv, " != ", &expr_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "andWhere", &_1, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_THIS();
	}
	zephir_memory_observe(&hiddenParam);
	zephir_read_property_cached(&hiddenParam, this_ptr, _zephir_prop_0, 1035, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Criteria.zep", 641);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _2)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, "ACP", &hiddenParam);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_get_strval(&key, &_3$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&queryKey);
			ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 631);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			SEPARATE_ZVAL(&hiddenParam);
			zephir_increment(&hiddenParam);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_CONCAT_SV(&_6$$5, "ACP", &hiddenParam);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_strval(&key, &_6$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&queryKey);
				ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 631);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				SEPARATE_ZVAL(&hiddenParam);
				zephir_increment(&hiddenParam);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_join_str(&_7, SL(", "), &bindKeys);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VSVS(&_8, &expr_zv, " IN (", &_7, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andWhere", &_1, 0, &_8, &bindParams);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1035, &hiddenParam);
	RETURN_THIS();
}

/**
 * Adds an INNER join to the query
 *
 *```php
 * <?php
 *
 * $criteria->join(
 *     Invoices::class
 * );
 *
 * $criteria->join(
 *     Invoices::class,
 *     "inv_cst_id = Customers.cst_id"
 * );
 *
 * $criteria->join(
 *     Invoices::class,
 *     "i.inv_cst_id = Customers.cst_id",
 *     "i"
 * );
 *
 * $criteria->join(
 *     Invoices::class,
 *     "i.inv_cst_id = Customers.cst_id",
 *     "i",
 *     "LEFT"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval model_zv, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, *type = NULL, type_sub, __$null;
	zend_string *model = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
		Z_PARAM_ZVAL_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		conditions = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		alias = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		type = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		conditions = &conditions_sub;
		conditions = &__$null;
	}
	if (!alias) {
		alias = &alias_sub;
		alias = &__$null;
	}
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addJoinClause", NULL, 0, &model_zv, conditions, alias, type);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a LEFT join to the query
 *
 *```php
 * <?php
 *
 * $criteria->leftJoin(
 *     Invoices::class,
 *     "i.inv_cst_id = Customers.cst_id",
 *     "i"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval model_zv, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zend_string *model = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		conditions = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		alias = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		conditions = &conditions_sub;
		conditions = &__$null;
	}
	if (!alias) {
		alias = &alias_sub;
		alias = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "LEFT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addJoinClause", NULL, 0, &model_zv, conditions, alias, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds the limit parameter to the criteria.
 *
 * ```php
 * $criteria->limit(100);
 * $criteria->limit(100, 200);
 * $criteria->limit("100", "200");
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit)
{
	zval _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *limit_param = NULL, *offset_param = NULL, _0, _1, _3, _4$$4, _5$$4, _7$$5;
	zend_long limit, offset, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_6$$5);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(limit)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &limit_param, &offset_param);
	if (!offset_param) {
		offset = 0;
	} else {
		}
	ZVAL_LONG(&_0, limit);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", &_2, 0, &_0);
	zephir_check_call_status();
	limit = zephir_get_intval(&_1);
	ZVAL_LONG(&_0, offset);
	ZEPHIR_CALL_FUNCTION(&_3, "abs", &_2, 0, &_0);
	zephir_check_call_status();
	offset = zephir_get_intval(&_3);
	if (UNEXPECTED(limit == 0)) {
		RETURN_THIS();
	}
	if (offset == 0) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "limit");
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_LONG(&_5$$4, limit);
		zephir_update_property_array(this_ptr, SL("params"), &_4$$4, &_5$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_create_array(&_6$$5, 2, 0);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_LONG(&_7$$5, limit);
		zephir_array_update_string(&_6$$5, SL("number"), &_7$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_7$$5);
		ZVAL_LONG(&_7$$5, offset);
		zephir_array_update_string(&_6$$5, SL("offset"), &_7$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "limit");
		zephir_update_property_array(this_ptr, SL("params"), &_7$$5, &_6$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_THIS();
}

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 *```php
 * $criteria->notBetweenWhere("price", 100.25, 200.50);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere)
{
	zval _4;
	zval minimumKey, maximumKey, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval expr_zv, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, nextHiddenParam, _0, _1, _2;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hiddenParamNumber", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	minimum = ZEND_CALL_ARG(execute_data, 2);
	maximum = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
	zephir_memory_observe(&hiddenParam);
	zephir_read_property_cached(&hiddenParam, this_ptr, _zephir_prop_0, 1035, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	zephir_add_function(&nextHiddenParam, &hiddenParam, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "ACP", &hiddenParam);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&minimumKey, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "ACP", &nextHiddenParam);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&maximumKey, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSVSVS(&_3, &expr_zv, " NOT BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_update_zval(&_4, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_4, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andWhere", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	SEPARATE_ZVAL(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1035, &nextHiddenParam);
	RETURN_THIS();
}

/**
 * Appends a NOT IN condition to the current conditions
 *
 *```php
 * $criteria->notInWhere("id", [1, 2, 3]);
 *```
 *
 * @phpstan-param array<array-key, mixed> $values
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere)
{
	zend_bool _4;
	zval key, _2$$3, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, bindParams, bindKeys;
	zval expr_zv, *values_param = NULL, hiddenParam, value, *_0, _3, _7, _8, _1$$3, _5$$4;
	zend_string *expr = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr_zv);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("hiddenParamNumber", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(expr)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&expr_zv);
	ZVAL_STR_COPY(&expr_zv, expr);
	zephir_get_arrval(&values, values_param);
	zephir_memory_observe(&hiddenParam);
	zephir_read_property_cached(&hiddenParam, this_ptr, _zephir_prop_0, 1035, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Criteria.zep", 813);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _0)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZEPHIR_CONCAT_SV(&_1$$3, "ACP", &hiddenParam);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_get_strval(&key, &_1$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZEPHIR_CONCAT_SVS(&_2$$3, ":", &key, ":");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&bindKeys, &_2$$3, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 803);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			SEPARATE_ZVAL(&hiddenParam);
			zephir_increment(&hiddenParam);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_CONCAT_SV(&_5$$4, "ACP", &hiddenParam);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_strval(&key, &_5$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZEPHIR_CONCAT_SVS(&_6$$4, ":", &key, ":");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&bindKeys, &_6$$4, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 803);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				SEPARATE_ZVAL(&hiddenParam);
				zephir_increment(&hiddenParam);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_join_str(&_7, SL(", "), &bindKeys);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VSVS(&_8, &expr_zv, " NOT IN (", &_7, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andWhere", NULL, 0, &_8, &bindParams);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1035, &hiddenParam);
	RETURN_THIS();
}

/**
 * Adds the order-by clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval orderColumns_zv, _0;
	zend_string *orderColumns = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderColumns_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(orderColumns)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&orderColumns_zv);
	ZVAL_STR_COPY(&orderColumns_zv, orderColumns);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "order");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &orderColumns_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Appends a condition to the current conditions using an OR operator
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentConditions, _0, _2$$3;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentConditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(conditions_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(bindParams)
		Z_PARAM_ZVAL_OR_NULL(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);
	zephir_get_strval(&conditions, conditions_param);
	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}
	zephir_memory_observe(&currentConditions);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&currentConditions, &_0, SL("conditions"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVSVS(&_2$$3, "(", &currentConditions, ") OR (", &conditions, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_get_strval(&conditions, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a RIGHT join to the query
 *
 *```php
 * <?php
 *
 * $criteria->rightJoin(
 *     Invoices::class,
 *     "i.inv_cst_id = Customers.cst_id",
 *     "i"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval model_zv, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zend_string *model = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		conditions = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		alias = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		conditions = &conditions_sub;
		conditions = &__$null;
	}
	if (!alias) {
		alias = &alias_sub;
		alias = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "RIGHT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addJoinClause", NULL, 0, &model_zv, conditions, alias, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *container, container_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &container);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "di");
	zephir_update_property_array(this_ptr, SL("params"), &_0, container);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Set a model on which the query will be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName)
{
	zval modelName_zv;
	zend_string *modelName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("model", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(modelName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&modelName_zv, modelName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1036, &modelName_zv);
	RETURN_THISW();
}

/**
 * Adds the "shared_lock" parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sharedLock_param = NULL, _0, _1;
	zend_bool sharedLock;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(sharedLock)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &sharedLock_param);
	if (!sharedLock_param) {
		sharedLock = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "shared_lock");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, sharedLock);
	zephir_update_property_array(this_ptr, SL("params"), &_0, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Sets the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where)
{
	zend_bool _2$$3, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval conditions_zv, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentBindParams, currentBindTypes, _0, _1$$3, _3$$4, _4$$4, _5$$5, _6$$6, _8$$7, _9$$7, _10$$8;
	zend_string *conditions = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions_zv);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(bindParams)
		Z_PARAM_ZVAL_OR_NULL(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		bindParams = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		bindTypes = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&conditions_zv);
	ZVAL_STR_COPY(&conditions_zv, conditions);
	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "conditions");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &conditions_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		zephir_memory_observe(&currentBindParams);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
		_2$$3 = zephir_array_isset_string_fetch(&currentBindParams, &_1$$3, SL("bind"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_fast_array_merge(&_3$$4, &currentBindParams, bindParams);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "bind");
			zephir_update_property_array(this_ptr, SL("params"), &_4$$4, &_3$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "bind");
			zephir_update_property_array(this_ptr, SL("params"), &_5$$5, bindParams);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		zephir_memory_observe(&currentBindTypes);
		zephir_read_property_cached(&_6$$6, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
		_7$$6 = zephir_array_isset_string_fetch(&currentBindTypes, &_6$$6, SL("bindTypes"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_7$$6) {
			ZEPHIR_INIT_VAR(&_8$$7);
			zephir_fast_array_merge(&_8$$7, &currentBindTypes, bindTypes);
			ZEPHIR_INIT_VAR(&_9$$7);
			ZVAL_STRING(&_9$$7, "bindTypes");
			zephir_update_property_array(this_ptr, SL("params"), &_9$$7, &_8$$7);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_10$$8);
			ZVAL_STRING(&_10$$8, "bindTypes");
			zephir_update_property_array(this_ptr, SL("params"), &_10$$8, bindTypes);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_THIS();
}

/**
 * Appends a JOIN clause to the criteria params under a non-conflicting
 * name. Internal wrappers (innerJoin/leftJoin/rightJoin/join) all
 * delegate here so that the call site is not subject to Zephir's
 * name collision between the public `join()` method and PHP's
 * built-in `join()` function.
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, addJoinClause)
{
	zend_bool _1;
	zval join, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval model_zv, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, *type = NULL, type_sub, __$null, mergedJoins, currentJoins, _0, _5, _3$$5, _4$$6;
	zend_string *model = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&mergedJoins);
	ZVAL_UNDEF(&currentJoins);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&_2$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("params", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
		Z_PARAM_ZVAL_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		conditions = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		alias = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		type = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!conditions) {
		conditions = &conditions_sub;
		conditions = &__$null;
	}
	if (!alias) {
		alias = &alias_sub;
		alias = &__$null;
	}
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}
	ZEPHIR_INIT_VAR(&join);
	zephir_create_array(&join, 4, 0);
	zephir_array_fast_append(&join, &model_zv);
	zephir_array_fast_append(&join, conditions);
	zephir_array_fast_append(&join, alias);
	zephir_array_fast_append(&join, type);
	zephir_memory_observe(&currentJoins);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1034, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&currentJoins, &_0, SL("joins"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		if (Z_TYPE_P(&currentJoins) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_create_array(&_2$$4, 1, 0);
			zephir_array_fast_append(&_2$$4, &join);
			ZEPHIR_INIT_VAR(&mergedJoins);
			zephir_fast_array_merge(&mergedJoins, &currentJoins, &_2$$4);
		} else {
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_create_array(&_3$$5, 1, 0);
			zephir_array_fast_append(&_3$$5, &join);
			ZEPHIR_CPY_WRT(&mergedJoins, &_3$$5);
		}
	} else {
		ZEPHIR_INIT_VAR(&_4$$6);
		zephir_create_array(&_4$$6, 1, 0);
		zephir_array_fast_append(&_4$$6, &join);
		ZEPHIR_CPY_WRT(&mergedJoins, &_4$$6);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "joins");
	zephir_update_property_array(this_ptr, SL("params"), &_5, &mergedJoins);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

