
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Criteria
 *
 * This class is used to build the array parameter required by
 * Phalcon\Mvc\Model::find() and Phalcon\Mvc\Model::findFirst() using an
 * object-oriented interface.
 *
 * ```php
 * $robots = Robots::query()
 *     ->where("type = :type:")
 *     ->andWhere("year < 2000")
 *     ->bind(["type" => "mechanical"])
 *     ->limit(5, 10)
 *     ->orderBy("name")
 *     ->execute();
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Criteria)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Criteria, phalcon, mvc_model_criteria, phalcon_mvc_model_criteria_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("bindParams"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("bindTypes"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_criteria_ce, SL("hiddenParamNumber"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("model"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("params"), ZEND_ACC_PROTECTED);
	phalcon_mvc_model_criteria_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Criteria;

	zend_class_implements(phalcon_mvc_model_criteria_ce, 1, phalcon_mvc_model_criteriainterface_ce);
	zend_class_implements(phalcon_mvc_model_criteria_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;
}

/**
 * Appends a condition to the current conditions using an AND operator
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentConditions, _0, _1$$3;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentConditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(bindParams)
		Z_PARAM_ZVAL_OR_NULL(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);
	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&currentConditions, &_0, SL("conditions"), 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVSVS(&_1$$3, "(", &currentConditions, ") AND (", &conditions, ")");
		zephir_get_strval(&conditions, &_1$$3);
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
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, minimumKey, nextHiddenParam, maximumKey, _0;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}


	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "ACP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "ACP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVSVS(&_0, &expr, " BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_update_zval(&_1, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_1, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &nextHiddenParam);
	RETURN_THIS();
}

/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge, _5;
	zval *bindParams_param = NULL, *merge_param = NULL, _0, _3, _4, _1$$3, _2$$3, _6$$4, _7$$4, _8$$4, _9$$4, _10$$5;
	zval bindParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string(&_0, SL("bind")))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "bind");
		zephir_update_property_array(this_ptr, SL("params"), &_2$$3, &_1$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_4);
	zephir_array_fetch_string(&_4, &_3, SL("bind"), PH_NOISY, "phalcon/Mvc/Model/Criteria.zep", 129);
	_5 = Z_TYPE_P(&_4) == IS_ARRAY;
	if (_5) {
		_5 = merge;
	}
	if (_5) {
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_7$$4, &_6$$4, SL("bind"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Criteria.zep", 130);
		ZEPHIR_INIT_VAR(&_8$$4);
		zephir_add_function(&_8$$4, &_7$$4, &bindParams);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "bind");
		zephir_update_property_array(this_ptr, SL("params"), &_9$$4, &_8$$4);
	} else {
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "bind");
		zephir_update_property_array(this_ptr, SL("params"), &_10$$5, &bindParams);
	}
	RETURN_THIS();
}

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *bindTypes_param = NULL, _0;
	zval bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bindTypes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "bindTypes");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &bindTypes);
	RETURN_THIS();
}

/**
 * Sets the cache options in the criteria
 * This method replaces all previously set cache options
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cache_param = NULL, _0;
	zval cache;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(cache)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cache_param);
	ZEPHIR_OBS_COPY_OR_DUP(&cache, cache_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &cache);
	RETURN_THIS();
}

/**
 * Sets the columns to be queried
 *
 *```php
 * $criteria->columns(
 *     [
 *         "id",
 *         "name",
 *     ]
 * );
 *```
 *
 * @param string|array columns
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *columns, columns_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(columns)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columns);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "columns");
	zephir_update_property_array(this_ptr, SL("params"), &_0, columns);
	RETURN_THIS();
}

/**
 * Adds the conditions parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *conditions_param = NULL, _0;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(conditions)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &conditions_param);
	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "conditions");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &conditions);
	RETURN_THIS();
}

/**
 * Creates a query builder from criteria.
 *
 * ```php
 * $builder = Robots::query()
 *     ->where("type = :type:")
 *     ->bind(["type" => "mechanical"])
 *     ->createBuilder();
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, createBuilder)
{
	zval container, manager, builder, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, &container);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &container, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&builder, &manager, "createbuilder", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_4);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(distinct)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &distinct);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "distinct");
	zephir_update_property_array(this_ptr, SL("params"), &_0, distinct);
	RETURN_THIS();
}

/**
 * Executes a find using the parameters built with the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute)
{
	zend_class_entry *_1;
	zval model, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&model, this_ptr, "getmodelname", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&model) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Model name must be string", "phalcon/Mvc/Model/Criteria.zep", 245);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparams", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_class(&model);
	ZEPHIR_RETURN_CALL_CE_STATIC(_1, "find", NULL, 0, &_0);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(forUpdate)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &forUpdate_param);
	if (!forUpdate_param) {
		forUpdate = 1;
	} else {
		forUpdate = zephir_get_boolval(forUpdate_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "for_update");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, forUpdate);
	zephir_update_property_array(this_ptr, SL("params"), &_0, &_1);
	RETURN_THIS();
}

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput)
{
	zend_bool _6$$4, _7$$7, _11$$10, _12$$13;
	zend_string *_5$$3;
	zend_ulong _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data, conditions, bind, _1$$3;
	zval modelName, operator, _17$$16;
	zval *container, container_sub, *modelName_param = NULL, *data_param = NULL, *operator_param = NULL, __$null, attribute, field, value, type, metaData, model, dataTypes, criteria, columnMap, _0$$3, *_2$$3, _3$$3, _8$$9, _9$$9, _10$$8, _13$$15, _14$$15, _15$$14, _16$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
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
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		Z_PARAM_STR(modelName)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(operator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &container, &modelName_param, &data_param, &operator_param);
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "AND");
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


	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	if (zephir_fast_count_int(&data)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, container, "getshared", NULL, 0, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_fast_append(&_1$$3, &__$null);
		zephir_array_fast_append(&_1$$3, container);
		ZEPHIR_INIT_VAR(&model);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&model, &modelName, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&dataTypes, &metaData, "getdatatypes", NULL, 0, &model);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, &model);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&bind);
		array_init(&bind);
		zephir_is_iterable(&data, 0, "phalcon/Mvc/Model/Criteria.zep", 322);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _4$$3, _5$$3, _2$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				if (_5$$3 != NULL) { 
					ZVAL_STR_COPY(&field, _5$$3);
				} else {
					ZVAL_LONG(&field, _4$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _2$$3);
				_6$$4 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				if (_6$$4) {
					_6$$4 = ((zephir_fast_count_int(&columnMap)) ? 1 : 0);
				}
				if (_6$$4) {
					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch(&attribute, &columnMap, &field, PH_NOISY, "phalcon/Mvc/Model/Criteria.zep", 297);
				} else {
					ZEPHIR_CPY_WRT(&attribute, &field);
				}
				ZEPHIR_OBS_NVAR(&type);
				if (zephir_array_isset_fetch(&type, &dataTypes, &attribute, 0)) {
					_7$$7 = Z_TYPE_P(&value) != IS_NULL;
					if (_7$$7) {
						_7$$7 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
					}
					if (_7$$7) {
						if (ZEPHIR_IS_LONG(&type, 2)) {
							ZEPHIR_INIT_NVAR(&_8$$9);
							ZEPHIR_CONCAT_SVSVS(&_8$$9, "[", &field, "] LIKE :", &field, ":");
							zephir_array_append(&conditions, &_8$$9, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 308);
							ZEPHIR_INIT_NVAR(&_9$$9);
							ZEPHIR_CONCAT_SVS(&_9$$9, "%", &value, "%");
							zephir_array_update_zval(&bind, &field, &_9$$9, PH_COPY | PH_SEPARATE);
							continue;
						}
						ZEPHIR_INIT_NVAR(&_10$$8);
						ZEPHIR_CONCAT_SVSVS(&_10$$8, "[", &field, "] = :", &field, ":");
						zephir_array_append(&conditions, &_10$$8, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 317);
						zephir_array_update_zval(&bind, &field, &value, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					_11$$10 = Z_TYPE_P(&columnMap) == IS_ARRAY;
					if (_11$$10) {
						_11$$10 = ((zephir_fast_count_int(&columnMap)) ? 1 : 0);
					}
					if (_11$$10) {
						ZEPHIR_OBS_NVAR(&attribute);
						zephir_array_fetch(&attribute, &columnMap, &field, PH_NOISY, "phalcon/Mvc/Model/Criteria.zep", 297);
					} else {
						ZEPHIR_CPY_WRT(&attribute, &field);
					}
					ZEPHIR_OBS_NVAR(&type);
					if (zephir_array_isset_fetch(&type, &dataTypes, &attribute, 0)) {
						_12$$13 = Z_TYPE_P(&value) != IS_NULL;
						if (_12$$13) {
							_12$$13 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_12$$13) {
							if (ZEPHIR_IS_LONG(&type, 2)) {
								ZEPHIR_INIT_NVAR(&_13$$15);
								ZEPHIR_CONCAT_SVSVS(&_13$$15, "[", &field, "] LIKE :", &field, ":");
								zephir_array_append(&conditions, &_13$$15, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 308);
								ZEPHIR_INIT_NVAR(&_14$$15);
								ZEPHIR_CONCAT_SVS(&_14$$15, "%", &value, "%");
								zephir_array_update_zval(&bind, &field, &_14$$15, PH_COPY | PH_SEPARATE);
								continue;
							}
							ZEPHIR_INIT_NVAR(&_15$$14);
							ZEPHIR_CONCAT_SVSVS(&_15$$14, "[", &field, "] = :", &field, ":");
							zephir_array_append(&conditions, &_15$$14, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 317);
							zephir_array_update_zval(&bind, &field, &value, PH_COPY | PH_SEPARATE);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
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

	ZEPHIR_CALL_METHOD(NULL, &criteria, "setdi", NULL, 481, container);
	zephir_check_call_status();
	if (zephir_fast_count_int(&conditions)) {
		ZEPHIR_INIT_VAR(&_16$$16);
		ZEPHIR_INIT_VAR(&_17$$16);
		ZEPHIR_CONCAT_SVS(&_17$$16, " ", &operator, " ");
		zephir_fast_join(&_16$$16, &_17$$16, &conditions);
		ZEPHIR_CALL_METHOD(NULL, &criteria, "where", NULL, 490, &_16$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &criteria, "bind", NULL, 491, &bind);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setmodelname", NULL, 482, &modelName);
	zephir_check_call_status();
	RETURN_CCTOR(&criteria);
}

/**
 * Returns the columns to be queried
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns)
{
	zval columns, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&columns, &_0, SL("columns"), 1))) {
		RETURN_NULL();
	}
	RETURN_CTORW(&columns);
}

/**
 * Returns the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions)
{
	zval conditions, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&conditions, &_0, SL("conditions"), 1))) {
		RETURN_NULL();
	}
	RETURN_CTORW(&conditions);
}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("di"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Criteria.zep", 379);
	RETURN_CTORW(&_1);
}

/**
 * Returns the group clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getGroupBy)
{
	zval group, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&group, &_0, SL("group"), 1))) {
		RETURN_NULL();
	}
	RETURN_CTORW(&group);
}

/**
 * Returns the having clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getHaving)
{
	zval having, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&having, &_0, SL("having"), 1))) {
		RETURN_NULL();
	}
	RETURN_CTORW(&having);
}

/**
 * Returns the limit parameter in the criteria, which will be
 *
 * - An integer if 'limit' was set without an 'offset'
 * - An array with 'number' and 'offset' keys if an offset was set with the limit
 * - NULL if limit has not been set
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit)
{
	zval limit, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&limit, &_0, SL("limit"), 1))) {
		RETURN_NULL();
	}
	RETURN_CTORW(&limit);
}

/**
 * Returns an internal model name on which the criteria will be applied
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "model");
}

/**
 * Returns the order clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrderBy)
{
	zval order, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&order, &_0, SL("order"), 1))) {
		RETURN_NULL();
	}
	RETURN_CTORW(&order);
}

/**
 * Returns all the parameters defined in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");
}

/**
 * Returns the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere)
{
	zval conditions, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&conditions, &_0, SL("conditions"), 1))) {
		RETURN_NULL();
	}
	RETURN_CTORW(&conditions);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(group)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "group");
	zephir_update_property_array(this_ptr, SL("params"), &_0, group);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(having)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &having);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "having");
	zephir_update_property_array(this_ptr, SL("params"), &_0, having);
	RETURN_THIS();
}

/**
 * Adds an INNER join to the query
 *
 *```php
 * $criteria->innerJoin(
 *     Robots::class
 * );
 *
 * $criteria->innerJoin(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id"
 * );
 *
 * $criteria->innerJoin(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model_param = NULL, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);
	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
	}
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, &model, conditions, alias, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends an IN condition to the current conditions
 *
 * ```php
 * $criteria->inWhere("id", [1, 2, 3]);
 * ```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, bindParams, bindKeys;
	zval *expr_param = NULL, *values_param = NULL, hiddenParam, value, *_1, _2, _5, _6, _3$$4, _4$$5;
	zval expr, key, queryKey, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindKeys);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(expr)
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values_param);
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


	if (!(zephir_fast_count_int(&values))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &expr, " != ", &expr);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Criteria.zep", 559);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _1)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, "ACP", &hiddenParam);
			zephir_get_strval(&key, &_3$$4);
			ZEPHIR_INIT_NVAR(&queryKey);
			ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 549);
			zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_SEPARATE(&hiddenParam);
			zephir_increment(&hiddenParam);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_4$$5);
				ZEPHIR_CONCAT_SV(&_4$$5, "ACP", &hiddenParam);
				zephir_get_strval(&key, &_4$$5);
				ZEPHIR_INIT_NVAR(&queryKey);
				ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 549);
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_SEPARATE(&hiddenParam);
				zephir_increment(&hiddenParam);
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_join_str(&_5, SL(", "), &bindKeys);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_VSVS(&_6, &expr, " IN (", &_5, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_6, &bindParams);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &hiddenParam);
	RETURN_THIS();
}

/**
 * Adds an INNER join to the query
 *
 *```php
 * $criteria->join(
 *     Robots::class
 * );
 *
 * $criteria->join(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id"
 * );
 *
 * $criteria->join(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r"
 * );
 *
 * $criteria->join(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r",
 *     "LEFT"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join)
{
	zval join, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model_param = NULL, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, *type = NULL, type_sub, __$null, mergedJoins, currentJoins, _0, _4, _2$$5, _3$$6;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&mergedJoins);
	ZVAL_UNDEF(&currentJoins);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
		Z_PARAM_ZVAL_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model_param, &conditions, &alias, &type);
	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
	}
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
	zephir_array_fast_append(&join, &model);
	zephir_array_fast_append(&join, conditions);
	zephir_array_fast_append(&join, alias);
	zephir_array_fast_append(&join, type);
	ZEPHIR_OBS_VAR(&currentJoins);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&currentJoins, &_0, SL("joins"), 0)) {
		if (Z_TYPE_P(&currentJoins) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0);
			zephir_array_fast_append(&_1$$4, &join);
			ZEPHIR_INIT_VAR(&mergedJoins);
			zephir_fast_array_merge(&mergedJoins, &currentJoins, &_1$$4);
		} else {
			ZEPHIR_INIT_VAR(&_2$$5);
			zephir_create_array(&_2$$5, 1, 0);
			zephir_array_fast_append(&_2$$5, &join);
			ZEPHIR_CPY_WRT(&mergedJoins, &_2$$5);
		}
	} else {
		ZEPHIR_INIT_VAR(&_3$$6);
		zephir_create_array(&_3$$6, 1, 0);
		zephir_array_fast_append(&_3$$6, &join);
		ZEPHIR_CPY_WRT(&mergedJoins, &_3$$6);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "joins");
	zephir_update_property_array(this_ptr, SL("params"), &_4, &mergedJoins);
	RETURN_THIS();
}

/**
 * Adds a LEFT join to the query
 *
 *```php
 * $criteria->leftJoin(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model_param = NULL, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);
	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
	}
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, &model, conditions, alias, &_0);
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
	zval _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *limit_param = NULL, *offset_param = NULL, _0, _1, _2, _3$$4, _4$$4, _6$$5;
	zend_long limit, offset, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_5$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(limit)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit_param, &offset_param);
	limit = zephir_get_intval(limit_param);
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	ZVAL_LONG(&_0, limit);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 292, &_0);
	zephir_check_call_status();
	limit = zephir_get_numberval(&_1);
	ZVAL_LONG(&_0, offset);
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 292, &_0);
	zephir_check_call_status();
	offset = zephir_get_numberval(&_2);
	if (UNEXPECTED(limit == 0)) {
		RETURN_THIS();
	}
	if (offset == 0) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "limit");
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_LONG(&_4$$4, limit);
		zephir_update_property_array(this_ptr, SL("params"), &_3$$4, &_4$$4);
	} else {
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_create_array(&_5$$5, 2, 0);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_LONG(&_6$$5, limit);
		zephir_array_update_string(&_5$$5, SL("number"), &_6$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_6$$5);
		ZVAL_LONG(&_6$$5, offset);
		zephir_array_update_string(&_5$$5, SL("offset"), &_6$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "limit");
		zephir_update_property_array(this_ptr, SL("params"), &_6$$5, &_5$$5);
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
	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, nextHiddenParam, _0, _1;
	zval expr, minimumKey, maximumKey, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(expr)
		Z_PARAM_ZVAL(minimum)
		Z_PARAM_ZVAL(maximum)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);
	if (UNEXPECTED(Z_TYPE_P(expr_param) != IS_STRING && Z_TYPE_P(expr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expr' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(expr_param) == IS_STRING)) {
		zephir_get_strval(&expr, expr_param);
	} else {
		ZEPHIR_INIT_VAR(&expr);
	}


	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "ACP", &hiddenParam);
	zephir_get_strval(&minimumKey, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "ACP", &nextHiddenParam);
	zephir_get_strval(&maximumKey, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSVSVS(&_2, &expr, " NOT BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_update_zval(&_3, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_3, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &nextHiddenParam);
	RETURN_THIS();
}

/**
 * Appends a NOT IN condition to the current conditions
 *
 *```php
 * $criteria->notInWhere("id", [1, 2, 3]);
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, bindParams, bindKeys;
	zval *expr_param = NULL, *values_param = NULL, hiddenParam, value, *_0, _1, _6, _7, _2$$3, _4$$4;
	zval expr, key, _3$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindKeys);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(expr)
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values_param);
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


	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, ZEND_STRL("hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Criteria.zep", 742);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _0)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZEPHIR_CONCAT_SV(&_2$$3, "ACP", &hiddenParam);
			zephir_get_strval(&key, &_2$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SVS(&_3$$3, ":", &key, ":");
			zephir_array_append(&bindKeys, &_3$$3, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 732);
			zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_SEPARATE(&hiddenParam);
			zephir_increment(&hiddenParam);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_4$$4);
				ZEPHIR_CONCAT_SV(&_4$$4, "ACP", &hiddenParam);
				zephir_get_strval(&key, &_4$$4);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_CONCAT_SVS(&_5$$4, ":", &key, ":");
				zephir_array_append(&bindKeys, &_5$$4, PH_SEPARATE, "phalcon/Mvc/Model/Criteria.zep", 732);
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_SEPARATE(&hiddenParam);
				zephir_increment(&hiddenParam);
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_join_str(&_6, SL(", "), &bindKeys);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VSVS(&_7, &expr, " NOT IN (", &_6, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_7, &bindParams);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("hiddenParamNumber"), &hiddenParam);
	RETURN_THIS();
}

/**
 * Adds the order-by clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *orderColumns_param = NULL, _0;
	zval orderColumns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderColumns);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(orderColumns)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderColumns_param);
	if (UNEXPECTED(Z_TYPE_P(orderColumns_param) != IS_STRING && Z_TYPE_P(orderColumns_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'orderColumns' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(orderColumns_param) == IS_STRING)) {
		zephir_get_strval(&orderColumns, orderColumns_param);
	} else {
		ZEPHIR_INIT_VAR(&orderColumns);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "order");
	zephir_update_property_array(this_ptr, SL("params"), &_0, &orderColumns);
	RETURN_THIS();
}

/**
 * Appends a condition to the current conditions using an OR operator
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentConditions, _0, _1$$3;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentConditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(bindParams)
		Z_PARAM_ZVAL_OR_NULL(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);
	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&currentConditions, &_0, SL("conditions"), 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVSVS(&_1$$3, "(", &currentConditions, ") OR (", &conditions, ")");
		zephir_get_strval(&conditions, &_1$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a RIGHT join to the query
 *
 *```php
 * $criteria->rightJoin(
 *     Robots::class,
 *     "r.id = RobotsParts.robots_id",
 *     "r"
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model_param = NULL, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(conditions)
		Z_PARAM_ZVAL_OR_NULL(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);
	if (UNEXPECTED(Z_TYPE_P(model_param) != IS_STRING && Z_TYPE_P(model_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'model' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(model_param) == IS_STRING)) {
		zephir_get_strval(&model, model_param);
	} else {
		ZEPHIR_INIT_VAR(&model);
	}
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, &model, conditions, alias, &_0);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "di");
	zephir_update_property_array(this_ptr, SL("params"), &_0, container);
	ZEPHIR_MM_RESTORE();
}

/**
 * Set a model on which the query will be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *modelName_param = NULL;
	zval modelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(modelName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);
	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), &modelName);
	RETURN_THIS();
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(sharedLock)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sharedLock_param);
	if (!sharedLock_param) {
		sharedLock = 1;
	} else {
		sharedLock = zephir_get_boolval(sharedLock_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "shared_lock");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, sharedLock);
	zephir_update_property_array(this_ptr, SL("params"), &_0, &_1);
	RETURN_THIS();
}

/**
 * Sets the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *conditions_param = NULL, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, currentBindParams, currentBindTypes, _0, _1$$3, _2$$4, _3$$4, _4$$5, _5$$6, _6$$7, _7$$7, _8$$8;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(conditions)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(bindParams)
		Z_PARAM_ZVAL_OR_NULL(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions_param, &bindParams, &bindTypes);
	if (UNEXPECTED(Z_TYPE_P(conditions_param) != IS_STRING && Z_TYPE_P(conditions_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'conditions' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(conditions_param) == IS_STRING)) {
		zephir_get_strval(&conditions, conditions_param);
	} else {
		ZEPHIR_INIT_VAR(&conditions);
	}
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
	zephir_update_property_array(this_ptr, SL("params"), &_0, &conditions);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&currentBindParams);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&currentBindParams, &_1$$3, SL("bind"), 0)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_fast_array_merge(&_2$$4, &currentBindParams, bindParams);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "bind");
			zephir_update_property_array(this_ptr, SL("params"), &_3$$4, &_2$$4);
		} else {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "bind");
			zephir_update_property_array(this_ptr, SL("params"), &_4$$5, bindParams);
		}
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&currentBindTypes);
		zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&currentBindTypes, &_5$$6, SL("bindTypes"), 0)) {
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_fast_array_merge(&_6$$7, &currentBindTypes, bindTypes);
			ZEPHIR_INIT_VAR(&_7$$7);
			ZVAL_STRING(&_7$$7, "bindTypes");
			zephir_update_property_array(this_ptr, SL("params"), &_7$$7, &_6$$7);
		} else {
			ZEPHIR_INIT_VAR(&_8$$8);
			ZVAL_STRING(&_8$$8, "bindTypes");
			zephir_update_property_array(this_ptr, SL("params"), &_8$$8, bindTypes);
		}
	}
	RETURN_THIS();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Criteria(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

