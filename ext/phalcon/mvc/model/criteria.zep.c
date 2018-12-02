
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Mvc\Model\Criteria
 *
 * This class is used to build the array parameter required by
 * Phalcon\Mvc\Model::find() and Phalcon\Mvc\Model::findFirst()
 * using an object-oriented interface.
 *
 * <code>
 * $robots = Robots::query()
 *     ->where("type = :type:")
 *     ->andWhere("year < 2000")
 *     ->bind(["type" => "mechanical"])
 *     ->limit(5, 10)
 *     ->orderBy("name")
 *     ->execute();
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Criteria) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Criteria, phalcon, mvc_model_criteria, phalcon_mvc_model_criteria_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_criteria_ce, SL("_hiddenParamNumber"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_criteria_ce TSRMLS_CC, 1, phalcon_mvc_model_criteriainterface_ce);
	zend_class_implements(phalcon_mvc_model_criteria_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI) {

	zval *dependencyInjector, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "di", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, dependencyInjector TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI) {

	zval *dependencyInjector = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&dependencyInjector, _0, SS("di"), 1 TSRMLS_CC)) {
		RETURN_CTORW(dependencyInjector);
	}
	RETURN_NULL();

}

/**
 * Set a model on which the query will be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName) {

	zval *modelName_param = NULL;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}


	zephir_update_property_this(getThis(), SL("_model"), modelName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns an internal model name on which the criteria will be applied
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName) {

	

	RETURN_MEMBER(getThis(), "_model");

}

/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind) {

	zend_bool merge;
	zval *bindParams_param = NULL, *merge_param = NULL, *bind = NULL, *_0$$3, *_1$$4, *_2$$6, *_3$$6, *_4$$7, *_5$$8;
	zval *bindParams = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);

	bindParams = bindParams_param;
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (zephir_array_isset_string(_0$$3, SS("bind"))) {
			_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(bind);
			zephir_array_fetch_string(&bind, _1$$4, SL("bind"), PH_NOISY, "phalcon/mvc/model/criteria.zep", 108 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(bind);
			ZVAL_NULL(bind);
		}
		if (Z_TYPE_P(bind) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_2$$6);
			zephir_add_function(_2$$6, bind, bindParams);
			ZEPHIR_INIT_VAR(_3$$6);
			ZVAL_STRING(_3$$6, "bind", 1);
			zephir_update_property_array(this_ptr, SL("_params"), _3$$6, _2$$6 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_4$$7);
			ZVAL_STRING(_4$$7, "bind", 1);
			zephir_update_property_array(this_ptr, SL("_params"), _4$$7, bindParams TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(_5$$8);
		ZVAL_STRING(_5$$8, "bind", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _5$$8, bindParams TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes) {

	zval *bindTypes_param = NULL, *_0;
	zval *bindTypes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bindTypes_param);

	bindTypes = bindTypes_param;


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "bindTypes", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, bindTypes TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, distinct) {

	zval *distinct, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &distinct);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "distinct", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, distinct TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the columns to be queried
 *
 *<code>
 * $criteria->columns(
 *     [
 *         "id",
 *         "name",
 *     ]
 * );
 *</code>
 *
 * @param string|array columns
 * @return \Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns) {

	zval *columns, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columns);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "columns", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, columns TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds an INNER join to the query
 *
 *<code>
 * $criteria->join("Robots");
 * $criteria->join("Robots", "r.id = RobotsParts.robots_id");
 * $criteria->join("Robots", "r.id = RobotsParts.robots_id", "r");
 * $criteria->join("Robots", "r.id = RobotsParts.robots_id", "r", "LEFT");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join) {

	zval *_1$$4;
	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *type = NULL, *join = NULL, *mergedJoins = NULL, *currentJoins = NULL, *_0, *_2;
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


	ZEPHIR_INIT_VAR(join);
	zephir_create_array(join, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(join, model);
	zephir_array_fast_append(join, conditions);
	zephir_array_fast_append(join, alias);
	zephir_array_fast_append(join, type);
	ZEPHIR_OBS_VAR(currentJoins);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&currentJoins, _0, SS("joins"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(currentJoins) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_1$$4);
			zephir_create_array(_1$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_1$$4, join);
			ZEPHIR_INIT_VAR(mergedJoins);
			zephir_fast_array_merge(mergedJoins, &(currentJoins), &(_1$$4) TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(mergedJoins);
			zephir_create_array(mergedJoins, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(mergedJoins, join);
		}
	} else {
		ZEPHIR_INIT_NVAR(mergedJoins);
		zephir_create_array(mergedJoins, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(mergedJoins, join);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "joins", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _2, mergedJoins TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds an INNER join to the query
 *
 *<code>
 * $criteria->innerJoin("Robots");
 * $criteria->innerJoin("Robots", "r.id = RobotsParts.robots_id");
 * $criteria->innerJoin("Robots", "r.id = RobotsParts.robots_id", "r");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *_0;
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
	ZVAL_STRING(_0, "INNER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, model, conditions, alias, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a LEFT join to the query
 *
 *<code>
 * $criteria->leftJoin("Robots", "r.id = RobotsParts.robots_id", "r");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *_0;
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
	ZVAL_STRING(_0, "LEFT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, model, conditions, alias, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a RIGHT join to the query
 *
 *<code>
 * $criteria->rightJoin("Robots", "r.id = RobotsParts.robots_id", "r");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *_0;
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
	ZVAL_STRING(_0, "RIGHT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, model, conditions, alias, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where) {

	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentBindParams = NULL, *currentBindTypes = NULL, *_0, *_1$$3, *_2$$4, *_3$$4, *_4$$5, *_5$$6, *_6$$7, *_7$$7, *_8$$8;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "conditions", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, conditions TSRMLS_CC);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(currentBindParams);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&currentBindParams, _1$$3, SS("bind"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_2$$4);
			zephir_fast_array_merge(_2$$4, &(currentBindParams), &(bindParams) TSRMLS_CC);
			ZEPHIR_INIT_VAR(_3$$4);
			ZVAL_STRING(_3$$4, "bind", 1);
			zephir_update_property_array(this_ptr, SL("_params"), _3$$4, _2$$4 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_4$$5);
			ZVAL_STRING(_4$$5, "bind", 1);
			zephir_update_property_array(this_ptr, SL("_params"), _4$$5, bindParams TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(currentBindTypes);
		_5$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&currentBindTypes, _5$$6, SS("bindTypes"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_6$$7);
			zephir_fast_array_merge(_6$$7, &(currentBindTypes), &(bindTypes) TSRMLS_CC);
			ZEPHIR_INIT_VAR(_7$$7);
			ZVAL_STRING(_7$$7, "bindTypes", 1);
			zephir_update_property_array(this_ptr, SL("_params"), _7$$7, _6$$7 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_8$$8);
			ZVAL_STRING(_8$$8, "bindTypes", 1);
			zephir_update_property_array(this_ptr, SL("_params"), _8$$8, bindTypes TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Appends a condition to the current conditions using an AND operator (deprecated)
 *
 * @deprecated 1.0.0
 * @see \Phalcon\Mvc\Model\Criteria::andWhere()
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, addWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL;
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "andwhere", NULL, 0, conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a condition to the current conditions using an AND operator
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentConditions = NULL, *_0, *_1$$3;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&currentConditions, _0, SS("conditions"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVSVS(_1$$3, "(", currentConditions, ") AND (", conditions, ")");
		zephir_get_strval(conditions, _1$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a condition to the current conditions using an OR operator
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentConditions = NULL, *_0, *_1$$3;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&currentConditions, _0, SS("conditions"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVSVS(_1$$3, "(", currentConditions, ") OR (", conditions, ")");
		zephir_get_strval(conditions, _1$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a BETWEEN condition to the current conditions
 *
 *<code>
 * $criteria->betweenWhere("price", 100.25, 200.50);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere) {

	zval *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, *maximum, *hiddenParam = NULL, *minimumKey = NULL, *nextHiddenParam = NULL, *maximumKey = NULL, *_0;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

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


	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(nextHiddenParam);
	ZVAL_LONG(nextHiddenParam, (zephir_get_numberval(hiddenParam) + 1));
	ZEPHIR_INIT_VAR(minimumKey);
	ZEPHIR_CONCAT_SV(minimumKey, "ACP", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "ACP", nextHiddenParam);
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
	zephir_update_property_this(getThis(), SL("_hiddenParamNumber"), nextHiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 *<code>
 * $criteria->notBetweenWhere("price", 100.25, 200.50);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere) {

	zval *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, *maximum, *hiddenParam = NULL, *nextHiddenParam = NULL, *minimumKey = NULL, *maximumKey = NULL, *_0;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

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


	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(nextHiddenParam);
	ZVAL_LONG(nextHiddenParam, (zephir_get_numberval(hiddenParam) + 1));
	ZEPHIR_INIT_VAR(minimumKey);
	ZEPHIR_CONCAT_SV(minimumKey, "ACP", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "ACP", nextHiddenParam);
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
	zephir_update_property_this(getThis(), SL("_hiddenParamNumber"), nextHiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends an IN condition to the current conditions
 *
 * <code>
 * $criteria->inWhere("id", [1, 2, 3]);
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere) {

	HashTable *_2;
	HashPosition _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *hiddenParam = NULL, *bindParams = NULL, *bindKeys = NULL, *value = NULL, *key = NULL, *queryKey = NULL, **_3, *_4, *_5;
	zval *expr = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values_param);

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


	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_VSV(_0$$3, expr, " != ", expr);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, _0$$3);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_2, &_1, 0, 0, "phalcon/mvc/model/criteria.zep", 420);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_INIT_NVAR(key);
		ZEPHIR_CONCAT_SV(key, "ACP", hiddenParam);
		ZEPHIR_INIT_NVAR(queryKey);
		ZEPHIR_CONCAT_SVS(queryKey, ":", key, ":");
		zephir_array_append(&bindKeys, queryKey, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 411);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_SEPARATE(hiddenParam);
		zephir_increment(hiddenParam);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VSVS(_5, expr, " IN (", _4, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, _5, bindParams);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_hiddenParamNumber"), hiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a NOT IN condition to the current conditions
 *
 *<code>
 * $criteria->notInWhere("id", [1, 2, 3]);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *hiddenParam = NULL, *bindParams = NULL, *bindKeys = NULL, *value = NULL, *key = NULL, **_2, *_4, *_5, *_3$$3 = NULL;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values_param);

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


	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_1, &_0, 0, 0, "phalcon/mvc/model/criteria.zep", 457);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_NVAR(key);
		ZEPHIR_CONCAT_SV(key, "ACP", hiddenParam);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SVS(_3$$3, ":", key, ":");
		zephir_array_append(&bindKeys, _3$$3, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 447);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_SEPARATE(hiddenParam);
		zephir_increment(hiddenParam);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VSVS(_5, expr, " NOT IN (", _4, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, _5, bindParams);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_hiddenParamNumber"), hiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the conditions parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions) {

	zval *conditions_param = NULL, *_0;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &conditions_param);

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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "conditions", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, conditions TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the order-by parameter to the criteria (deprecated)
 *
 * @see \Phalcon\Mvc\Model\Criteria::orderBy()
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, order) {

	zval *orderColumns_param = NULL, *_0;
	zval *orderColumns = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderColumns_param);

	if (UNEXPECTED(Z_TYPE_P(orderColumns_param) != IS_STRING && Z_TYPE_P(orderColumns_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'orderColumns' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(orderColumns_param) == IS_STRING)) {
		zephir_get_strval(orderColumns, orderColumns_param);
	} else {
		ZEPHIR_INIT_VAR(orderColumns);
		ZVAL_EMPTY_STRING(orderColumns);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "order", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, orderColumns TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the order-by clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy) {

	zval *orderColumns_param = NULL, *_0;
	zval *orderColumns = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderColumns_param);

	if (UNEXPECTED(Z_TYPE_P(orderColumns_param) != IS_STRING && Z_TYPE_P(orderColumns_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'orderColumns' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(orderColumns_param) == IS_STRING)) {
		zephir_get_strval(orderColumns, orderColumns_param);
	} else {
		ZEPHIR_INIT_VAR(orderColumns);
		ZVAL_EMPTY_STRING(orderColumns);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "order", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, orderColumns TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the group-by clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, groupBy) {

	zval *group, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "group", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, group TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the having clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, having) {

	zval *having, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &having);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "having", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, having TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the limit parameter to the criteria.
 *
 * <code>
 * $criteria->limit(100);
 * $criteria->limit(100, 200);
 * $criteria->limit("100", "200");
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit) {

	zval *_3$$4;
	zval *limit_param = NULL, *offset = NULL, _0, *_1 = NULL, _2$$4, *_4$$4 = NULL, *_5$$5, *_6$$5;
	zend_long limit, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit_param, &offset);

	limit = zephir_get_intval(limit_param);
	if (!offset) {
		ZEPHIR_CPY_WRT(offset, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(offset);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, limit);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 213, &_0);
	zephir_check_call_status();
	limit = zephir_get_numberval(_1);
	if (UNEXPECTED(limit == 0)) {
		RETURN_THIS();
	}
	if (zephir_is_numeric(offset)) {
		ZEPHIR_SINIT_VAR(_2$$4);
		ZVAL_LONG(&_2$$4, zephir_get_intval(offset));
		ZEPHIR_CALL_FUNCTION(&offset, "abs", NULL, 213, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$4);
		zephir_create_array(_3$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_LONG(_4$$4, limit);
		zephir_array_update_string(&_3$$4, SL("number"), &_4$$4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$4, SL("offset"), &offset, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$4);
		ZVAL_STRING(_4$$4, "limit", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _4$$4, _3$$4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_5$$5);
		ZVAL_STRING(_5$$5, "limit", 1);
		ZEPHIR_INIT_VAR(_6$$5);
		ZVAL_LONG(_6$$5, limit);
		zephir_update_property_array(this_ptr, SL("_params"), _5$$5, _6$$5 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Adds the "for_update" parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate) {

	zval *forUpdate_param = NULL, *_0, *_1;
	zend_bool forUpdate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &forUpdate_param);

	if (!forUpdate_param) {
		forUpdate = 1;
	} else {
		forUpdate = zephir_get_boolval(forUpdate_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "for_update", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, forUpdate);
	zephir_update_property_array(this_ptr, SL("_params"), _0, _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the "shared_lock" parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock) {

	zval *sharedLock_param = NULL, *_0, *_1;
	zend_bool sharedLock;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sharedLock_param);

	if (!sharedLock_param) {
		sharedLock = 1;
	} else {
		sharedLock = zephir_get_boolval(sharedLock_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "shared_lock", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, sharedLock);
	zephir_update_property_array(this_ptr, SL("_params"), _0, _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the cache options in the criteria
 * This method replaces all previously set cache options
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache) {

	zval *cache_param = NULL, *_0;
	zval *cache = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cache_param);

	cache = cache_param;


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "cache", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, cache TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere) {

	zval *conditions = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&conditions, _0, SS("conditions"), 1 TSRMLS_CC)) {
		RETURN_CTORW(conditions);
	}
	RETURN_NULL();

}

/**
 * Returns the columns to be queried
 *
 * @return string|array|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns) {

	zval *columns = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&columns, _0, SS("columns"), 1 TSRMLS_CC)) {
		RETURN_CTORW(columns);
	}
	RETURN_NULL();

}

/**
 * Returns the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions) {

	zval *conditions = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&conditions, _0, SS("conditions"), 1 TSRMLS_CC)) {
		RETURN_CTORW(conditions);
	}
	RETURN_NULL();

}

/**
 * Returns the limit parameter in the criteria, which will be
 * an integer if limit was set without an offset,
 * an array with 'number' and 'offset' keys if an offset was set with the limit,
 * or null if limit has not been set.
 *
 * @return int|array|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit) {

	zval *limit = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&limit, _0, SS("limit"), 1 TSRMLS_CC)) {
		RETURN_CTORW(limit);
	}
	RETURN_NULL();

}

/**
 * Returns the order clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrderBy) {

	zval *order = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&order, _0, SS("order"), 1 TSRMLS_CC)) {
		RETURN_CTORW(order);
	}
	RETURN_NULL();

}

/**
 * Returns the group clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getGroupBy) {

	zval *group = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&group, _0, SS("group"), 1 TSRMLS_CC)) {
		RETURN_CTORW(group);
	}
	RETURN_NULL();

}

/**
 * Returns the having clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getHaving) {

	zval *having = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&having, _0, SS("having"), 1 TSRMLS_CC)) {
		RETURN_CTORW(having);
	}
	RETURN_NULL();

}

/**
 * Returns all the parameters defined in the criteria
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams) {

	

	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput) {

	zend_bool _6$$4, _7$$7;
	HashTable *_4$$3;
	HashPosition _3$$3;
	zend_class_entry *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *modelName = NULL, *operator = NULL, *_12$$10;
	zval *dependencyInjector, *modelName_param = NULL, *data_param = NULL, *operator_param = NULL, *attribute = NULL, *conditions = NULL, *field = NULL, *value = NULL, *type = NULL, *metaData = NULL, *model = NULL, *dataTypes = NULL, *bind = NULL, *criteria = NULL, *columnMap = NULL, *_0$$3 = NULL, *_1$$3 = NULL, **_5$$3, *_8$$9 = NULL, *_9$$9 = NULL, *_10$$8 = NULL, *_11$$10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &dependencyInjector, &modelName_param, &data_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	data = data_param;
	if (!operator_param) {
		ZEPHIR_INIT_VAR(operator);
		ZVAL_STRING(operator, "AND", 1);
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


	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	if (zephir_fast_count_int(data TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, _0$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(model);
		zephir_fetch_safe_class(_1$$3, modelName);
			_2$$3 = zend_fetch_class(Z_STRVAL_P(_1$$3), Z_STRLEN_P(_1$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(model, _2$$3);
		if (zephir_has_constructor(model TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_0$$3);
			ZVAL_NULL(_0$$3);
			ZEPHIR_CALL_METHOD(NULL, model, "__construct", NULL, 0, _0$$3, dependencyInjector);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&dataTypes, metaData, "getdatatypes", NULL, 0, model);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, 0, model);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(bind);
		array_init(bind);
		zephir_is_iterable(data, &_4$$3, &_3$$3, 0, 0, "phalcon/mvc/model/criteria.zep", 713);
		for (
		  ; zend_hash_get_current_data_ex(_4$$3, (void**) &_5$$3, &_3$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$3, &_3$$3)
		) {
			ZEPHIR_GET_HMKEY(field, _4$$3, _3$$3);
			ZEPHIR_GET_HVALUE(value, _5$$3);
			_6$$4 = Z_TYPE_P(columnMap) == IS_ARRAY;
			if (_6$$4) {
				_6$$4 = ((zephir_fast_count_int(columnMap TSRMLS_CC)) ? 1 : 0);
			}
			if (_6$$4) {
				ZEPHIR_OBS_NVAR(attribute);
				zephir_array_fetch(&attribute, columnMap, field, PH_NOISY, "phalcon/mvc/model/criteria.zep", 690 TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(attribute, field);
			}
			ZEPHIR_OBS_NVAR(type);
			if (zephir_array_isset_fetch(&type, dataTypes, attribute, 0 TSRMLS_CC)) {
				_7$$7 = Z_TYPE_P(value) != IS_NULL;
				if (_7$$7) {
					_7$$7 = !ZEPHIR_IS_STRING_IDENTICAL(value, "");
				}
				if (_7$$7) {
					if (ZEPHIR_IS_LONG(type, 2)) {
						ZEPHIR_INIT_LNVAR(_8$$9);
						ZEPHIR_CONCAT_SVSVS(_8$$9, "[", field, "] LIKE :", field, ":");
						zephir_array_append(&conditions, _8$$9, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 702);
						ZEPHIR_INIT_LNVAR(_9$$9);
						ZEPHIR_CONCAT_SVS(_9$$9, "%", value, "%");
						zephir_array_update_zval(&bind, field, &_9$$9, PH_COPY | PH_SEPARATE);
						continue;
					}
					ZEPHIR_INIT_LNVAR(_10$$8);
					ZEPHIR_CONCAT_SVSVS(_10$$8, "[", field, "] = :", field, ":");
					zephir_array_append(&conditions, _10$$8, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 709);
					zephir_array_update_zval(&bind, field, &value, PH_COPY | PH_SEPARATE);
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(criteria);
	object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
	if (zephir_has_constructor(criteria TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, criteria, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(conditions TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_11$$10);
		ZEPHIR_INIT_VAR(_12$$10);
		ZEPHIR_CONCAT_SVS(_12$$10, " ", operator, " ");
		zephir_fast_join(_11$$10, _12$$10, conditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, criteria, "where", NULL, 344, _11$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, criteria, "bind", NULL, 345, bind);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, criteria, "setmodelname", NULL, 333, modelName);
	zephir_check_call_status();
	RETURN_CCTOR(criteria);

}

/**
 * Creates a query builder from criteria.
 *
 * <code>
 * $builder = Robots::query()
 *     ->where("type = :type:")
 *     ->bind(["type" => "mechanical"])
 *     ->createBuilder();
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, createBuilder) {

	zval *dependencyInjector = NULL, *manager = NULL, *builder = NULL, *_1 = NULL, *_2, *_3, *_4;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, dependencyInjector);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _1);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&builder, manager, "createbuilder", NULL, 0, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, 0, _4);
	zephir_check_call_status();
	RETURN_CCTOR(builder);

}

/**
 * Executes a find using the parameters built with the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute) {

	zend_class_entry *_1;
	zval *model = NULL, *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&model, this_ptr, "getmodelname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(model) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Model name must be string", "phalcon/mvc/model/criteria.zep", 767);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparams", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_class(model TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(_1, "find", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}

