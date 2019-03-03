
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zval *dependencyInjector, dependencyInjector_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "di");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, dependencyInjector);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("di"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/criteria.zep", 65 TSRMLS_CC);
	RETURN_CTORW(&_1);

}

/**
 * Set a model on which the query will be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName) {

	zval *modelName_param = NULL;
	zval modelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}


	zephir_update_property_zval(this_ptr, SL("_model"), &modelName);
	RETURN_THIS();

}

/**
 * Returns an internal model name on which the criteria will be applied
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_model");

}

/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind) {

	zend_bool merge;
	zval *bindParams_param = NULL, *merge_param = NULL, bind, _0$$3, _1$$4, _2$$6, _3$$6, _4$$7, _5$$8;
	zval bindParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		zephir_read_property(&_0$$3, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string(&_0$$3, SL("bind"))) {
			zephir_read_property(&_1$$4, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_VAR(&bind);
			zephir_array_fetch_string(&bind, &_1$$4, SL("bind"), PH_NOISY, "phalcon/mvc/model/criteria.zep", 95 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&bind);
			ZVAL_NULL(&bind);
		}
		if (Z_TYPE_P(&bind) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_2$$6);
			zephir_add_function(&_2$$6, &bind, &bindParams);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZVAL_STRING(&_3$$6, "bind");
			zephir_update_property_array(this_ptr, SL("_params"), &_3$$6, &_2$$6);
			ZEPHIR_INIT_NVAR(&_2$$6);
		} else {
			ZEPHIR_INIT_VAR(&_4$$7);
			ZVAL_STRING(&_4$$7, "bind");
			zephir_update_property_array(this_ptr, SL("_params"), &_4$$7, &bindParams);
		}
	} else {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "bind");
		zephir_update_property_array(this_ptr, SL("_params"), &_5$$8, &bindParams);
	}
	RETURN_THIS();

}

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes) {

	zval *bindTypes_param = NULL, _0;
	zval bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bindTypes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "bindTypes");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, &bindTypes);
	RETURN_THIS();

}

/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, distinct) {

	zval *distinct, distinct_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&distinct_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &distinct);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "distinct");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, distinct);
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns) {

	zval *columns, columns_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columns);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "columns");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, columns);
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

	zval _1$$4;
	zval *model_param = NULL, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, *type = NULL, type_sub, __$null, join, mergedJoins, currentJoins, _0, _4, _2$$5, _3$$6;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&mergedJoins);
	ZVAL_UNDEF(&currentJoins);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &model_param, &conditions, &alias, &type);

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
	zephir_create_array(&join, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&join, &model);
	zephir_array_fast_append(&join, conditions);
	zephir_array_fast_append(&join, alias);
	zephir_array_fast_append(&join, type);
	ZEPHIR_OBS_VAR(&currentJoins);
	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&currentJoins, &_0, SL("joins"), 0)) {
		if (Z_TYPE_P(&currentJoins) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_1$$4, &join);
			ZEPHIR_INIT_VAR(&mergedJoins);
			zephir_fast_array_merge(&mergedJoins, &currentJoins, &_1$$4 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_2$$5);
			zephir_create_array(&_2$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_2$$5, &join);
			ZEPHIR_CPY_WRT(&mergedJoins, &_2$$5);
		}
	} else {
		ZEPHIR_INIT_VAR(&_3$$6);
		zephir_create_array(&_3$$6, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$6, &join);
		ZEPHIR_CPY_WRT(&mergedJoins, &_3$$6);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "joins");
	zephir_update_property_array(this_ptr, SL("_params"), &_4, &mergedJoins);
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
	zval *model_param = NULL, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);

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
 * Adds a LEFT join to the query
 *
 *<code>
 * $criteria->leftJoin("Robots", "r.id = RobotsParts.robots_id", "r");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model_param = NULL, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);

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
 * Adds a RIGHT join to the query
 *
 *<code>
 * $criteria->rightJoin("Robots", "r.id = RobotsParts.robots_id", "r");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model_param = NULL, *conditions = NULL, conditions_sub, *alias = NULL, alias_sub, __$null, _0;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&alias_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &model_param, &conditions, &alias);

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
 * Sets the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where) {

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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "conditions");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, &conditions);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&currentBindParams);
		zephir_read_property(&_1$$3, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&currentBindParams, &_1$$3, SL("bind"), 0)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_fast_array_merge(&_2$$4, &currentBindParams, bindParams TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "bind");
			zephir_update_property_array(this_ptr, SL("_params"), &_3$$4, &_2$$4);
			ZEPHIR_INIT_NVAR(&_2$$4);
		} else {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "bind");
			zephir_update_property_array(this_ptr, SL("_params"), &_4$$5, bindParams);
		}
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&currentBindTypes);
		zephir_read_property(&_5$$6, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&currentBindTypes, &_5$$6, SL("bindTypes"), 0)) {
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_fast_array_merge(&_6$$7, &currentBindTypes, bindTypes TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_7$$7);
			ZVAL_STRING(&_7$$7, "bindTypes");
			zephir_update_property_array(this_ptr, SL("_params"), &_7$$7, &_6$$7);
			ZEPHIR_INIT_NVAR(&_6$$7);
		} else {
			ZEPHIR_INIT_VAR(&_8$$8);
			ZVAL_STRING(&_8$$8, "bindTypes");
			zephir_update_property_array(this_ptr, SL("_params"), &_8$$8, bindTypes);
		}
	}
	RETURN_THIS();

}

/**
 * Appends a condition to the current conditions using an AND operator
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere) {

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
	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
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
 * Appends a condition to the current conditions using an OR operator
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere) {

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
	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
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
 * Appends a BETWEEN condition to the current conditions
 *
 *<code>
 * $criteria->betweenWhere("price", 100.25, 200.50);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere) {

	zval _1;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

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


	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "ACP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "ACP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVSVS(&_0, &expr, " BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_update_zval(&_1, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_1, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), &nextHiddenParam);
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

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, hiddenParam, nextHiddenParam, minimumKey, maximumKey, _0;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&nextHiddenParam);
	ZVAL_UNDEF(&minimumKey);
	ZVAL_UNDEF(&maximumKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

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


	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&nextHiddenParam);
	ZVAL_LONG(&nextHiddenParam, (zephir_get_numberval(&hiddenParam) + 1));
	ZEPHIR_INIT_VAR(&minimumKey);
	ZEPHIR_CONCAT_SV(&minimumKey, "ACP", &hiddenParam);
	ZEPHIR_INIT_VAR(&maximumKey);
	ZEPHIR_CONCAT_SV(&maximumKey, "ACP", &nextHiddenParam);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVSVS(&_0, &expr, " NOT BETWEEN :", &minimumKey, ": AND :", &maximumKey, ":");
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_update_zval(&_1, &minimumKey, minimum, PH_COPY);
	zephir_array_update_zval(&_1, &maximumKey, maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SEPARATE(&nextHiddenParam);
	zephir_increment(&nextHiddenParam);
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), &nextHiddenParam);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *expr_param = NULL, *values_param = NULL, hiddenParam, bindParams, bindKeys, value, key, queryKey, *_1, _2, _3, _4;
	zval expr, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&queryKey);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values_param);

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


	if (!(zephir_fast_count_int(&values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &expr, " != ", &expr);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/mvc/model/criteria.zep", 395);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _1)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&key);
			ZEPHIR_CONCAT_SV(&key, "ACP", &hiddenParam);
			ZEPHIR_INIT_NVAR(&queryKey);
			ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
			zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 386);
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
				ZEPHIR_INIT_NVAR(&key);
				ZEPHIR_CONCAT_SV(&key, "ACP", &hiddenParam);
				ZEPHIR_INIT_NVAR(&queryKey);
				ZEPHIR_CONCAT_SVS(&queryKey, ":", &key, ":");
				zephir_array_append(&bindKeys, &queryKey, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 386);
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_SEPARATE(&hiddenParam);
				zephir_increment(&hiddenParam);
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_join_str(&_3, SL(", "), &bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VSVS(&_4, &expr, " IN (", &_3, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_4, &bindParams);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), &hiddenParam);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *expr_param = NULL, *values_param = NULL, hiddenParam, bindParams, bindKeys, value, key, *_0, _1, _4, _5, _2$$3, _3$$4;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&hiddenParam);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindKeys);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &values_param);

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


	ZEPHIR_OBS_VAR(&hiddenParam);
	zephir_read_property(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	ZEPHIR_INIT_VAR(&bindKeys);
	array_init(&bindKeys);
	zephir_is_iterable(&values, 0, "phalcon/mvc/model/criteria.zep", 432);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _0)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&key);
			ZEPHIR_CONCAT_SV(&key, "ACP", &hiddenParam);
			ZEPHIR_INIT_LNVAR(_2$$3);
			ZEPHIR_CONCAT_SVS(&_2$$3, ":", &key, ":");
			zephir_array_append(&bindKeys, &_2$$3, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 422);
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
				ZEPHIR_INIT_NVAR(&key);
				ZEPHIR_CONCAT_SV(&key, "ACP", &hiddenParam);
				ZEPHIR_INIT_LNVAR(_3$$4);
				ZEPHIR_CONCAT_SVS(&_3$$4, ":", &key, ":");
				zephir_array_append(&bindKeys, &_3$$4, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 422);
				zephir_array_update_zval(&bindParams, &key, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_SEPARATE(&hiddenParam);
				zephir_increment(&hiddenParam);
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_join_str(&_4, SL(", "), &bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSVS(&_5, &expr, " NOT IN (", &_4, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, 0, &_5, &bindParams);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_hiddenParamNumber"), &hiddenParam);
	RETURN_THIS();

}

/**
 * Adds the conditions parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions) {

	zval *conditions_param = NULL, _0;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &conditions_param);

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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "conditions");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, &conditions);
	RETURN_THIS();

}

/**
 * Adds the order-by clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy) {

	zval *orderColumns_param = NULL, _0;
	zval orderColumns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderColumns);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderColumns_param);

	if (UNEXPECTED(Z_TYPE_P(orderColumns_param) != IS_STRING && Z_TYPE_P(orderColumns_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'orderColumns' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(orderColumns_param) == IS_STRING)) {
		zephir_get_strval(&orderColumns, orderColumns_param);
	} else {
		ZEPHIR_INIT_VAR(&orderColumns);
		ZVAL_EMPTY_STRING(&orderColumns);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "order");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, &orderColumns);
	RETURN_THIS();

}

/**
 * Adds the group-by clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, groupBy) {

	zval *group, group_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "group");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, group);
	RETURN_THIS();

}

/**
 * Adds the having clause to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, having) {

	zval *having, having_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&having_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &having);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "having");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, having);
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

	zval _3$$4;
	zval *limit_param = NULL, *offset = NULL, offset_sub, __$null, _0, _1, _2$$4, _4$$4, _5$$5, _6$$5;
	zend_long limit, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit_param, &offset);

	limit = zephir_get_intval(limit_param);
	if (!offset) {
		offset = &offset_sub;
		ZEPHIR_CPY_WRT(offset, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(offset);
	}


	ZVAL_LONG(&_0, limit);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 189, &_0);
	zephir_check_call_status();
	limit = zephir_get_numberval(&_1);
	if (UNEXPECTED(limit == 0)) {
		RETURN_THIS();
	}
	if (zephir_is_numeric(offset)) {
		ZVAL_LONG(&_2$$4, zephir_get_intval(offset));
		ZEPHIR_CALL_FUNCTION(offset, "abs", NULL, 189, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_create_array(&_3$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_LONG(&_4$$4, limit);
		zephir_array_update_string(&_3$$4, SL("number"), &_4$$4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$4, SL("offset"), offset, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "limit");
		zephir_update_property_array(this_ptr, SL("_params"), &_4$$4, &_3$$4);
		ZEPHIR_INIT_NVAR(&_3$$4);
	} else {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "limit");
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_LONG(&_6$$5, limit);
		zephir_update_property_array(this_ptr, SL("_params"), &_5$$5, &_6$$5);
		ZEPHIR_INIT_NVAR(&_6$$5);
	}
	RETURN_THIS();

}

/**
 * Adds the "for_update" parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate) {

	zval *forUpdate_param = NULL, _0, _1;
	zend_bool forUpdate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
	zephir_update_property_array(this_ptr, SL("_params"), &_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	RETURN_THIS();

}

/**
 * Adds the "shared_lock" parameter to the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock) {

	zval *sharedLock_param = NULL, _0, _1;
	zend_bool sharedLock;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
	zephir_update_property_array(this_ptr, SL("_params"), &_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	RETURN_THIS();

}

/**
 * Sets the cache options in the criteria
 * This method replaces all previously set cache options
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache) {

	zval *cache_param = NULL, _0;
	zval cache;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cache_param);

	ZEPHIR_OBS_COPY_OR_DUP(&cache, cache_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cache");
	zephir_update_property_array(this_ptr, SL("_params"), &_0, &cache);
	RETURN_THIS();

}

/**
 * Returns the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere) {

	zval conditions, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&conditions, &_0, SL("conditions"), 1)) {
		RETURN_CTORW(&conditions);
	}
	RETURN_NULL();

}

/**
 * Returns the columns to be queried
 *
 * @return string|array|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns) {

	zval columns, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&columns, &_0, SL("columns"), 1)) {
		RETURN_CTORW(&columns);
	}
	RETURN_NULL();

}

/**
 * Returns the conditions parameter in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions) {

	zval conditions, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&conditions, &_0, SL("conditions"), 1)) {
		RETURN_CTORW(&conditions);
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

	zval limit, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&limit, &_0, SL("limit"), 1)) {
		RETURN_CTORW(&limit);
	}
	RETURN_NULL();

}

/**
 * Returns the order clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrderBy) {

	zval order, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&order, &_0, SL("order"), 1)) {
		RETURN_CTORW(&order);
	}
	RETURN_NULL();

}

/**
 * Returns the group clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getGroupBy) {

	zval group, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&group, &_0, SL("group"), 1)) {
		RETURN_CTORW(&group);
	}
	RETURN_NULL();

}

/**
 * Returns the having clause in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getHaving) {

	zval having, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&having, &_0, SL("having"), 1)) {
		RETURN_CTORW(&having);
	}
	RETURN_NULL();

}

/**
 * Returns all the parameters defined in the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput) {

	zend_bool _8$$4, _9$$7, _13$$10, _14$$13;
	zend_string *_7$$3;
	zend_ulong _6$$3;
	zend_class_entry *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval modelName, operator, _19$$16;
	zval *dependencyInjector, dependencyInjector_sub, *modelName_param = NULL, *data_param = NULL, *operator_param = NULL, attribute, conditions, field, value, type, metaData, model, dataTypes, bind, criteria, columnMap, _0$$3, _1$$3, _3$$3, *_4$$3, _5$$3, _10$$9, _11$$9, _12$$8, _15$$15, _16$$15, _17$$14, _18$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&dataTypes);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &dependencyInjector, &modelName_param, &data_param, &operator_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!operator_param) {
		ZEPHIR_INIT_VAR(&operator);
		ZVAL_STRING(&operator, "AND");
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


	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	if (zephir_fast_count_int(&data TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, 0, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&model);
		zephir_fetch_safe_class(&_1$$3, &modelName);
		_2$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1$$3), Z_STRLEN_P(&_1$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&model, _2$$3);
		if (zephir_has_constructor(&model TSRMLS_CC)) {
			ZVAL_NULL(&_3$$3);
			ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0, &_3$$3, dependencyInjector);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&dataTypes, &metaData, "getdatatypes", NULL, 0, &model);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, &model);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&bind);
		array_init(&bind);
		zephir_is_iterable(&data, 0, "phalcon/mvc/model/criteria.zep", 675);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _6$$3, _7$$3, _4$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				if (_7$$3 != NULL) { 
					ZVAL_STR_COPY(&field, _7$$3);
				} else {
					ZVAL_LONG(&field, _6$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _4$$3);
				_8$$4 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				if (_8$$4) {
					_8$$4 = ((zephir_fast_count_int(&columnMap TSRMLS_CC)) ? 1 : 0);
				}
				if (_8$$4) {
					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch(&attribute, &columnMap, &field, PH_NOISY, "phalcon/mvc/model/criteria.zep", 652 TSRMLS_CC);
				} else {
					ZEPHIR_CPY_WRT(&attribute, &field);
				}
				ZEPHIR_OBS_NVAR(&type);
				if (zephir_array_isset_fetch(&type, &dataTypes, &attribute, 0 TSRMLS_CC)) {
					_9$$7 = Z_TYPE_P(&value) != IS_NULL;
					if (_9$$7) {
						_9$$7 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
					}
					if (_9$$7) {
						if (ZEPHIR_IS_LONG(&type, 2)) {
							ZEPHIR_INIT_LNVAR(_10$$9);
							ZEPHIR_CONCAT_SVSVS(&_10$$9, "[", &field, "] LIKE :", &field, ":");
							zephir_array_append(&conditions, &_10$$9, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 664);
							ZEPHIR_INIT_LNVAR(_11$$9);
							ZEPHIR_CONCAT_SVS(&_11$$9, "%", &value, "%");
							zephir_array_update_zval(&bind, &field, &_11$$9, PH_COPY | PH_SEPARATE);
							continue;
						}
						ZEPHIR_INIT_LNVAR(_12$$8);
						ZEPHIR_CONCAT_SVSVS(&_12$$8, "[", &field, "] = :", &field, ":");
						zephir_array_append(&conditions, &_12$$8, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 671);
						zephir_array_update_zval(&bind, &field, &value, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$3, &data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
				zephir_check_call_status();
					_13$$10 = Z_TYPE_P(&columnMap) == IS_ARRAY;
					if (_13$$10) {
						_13$$10 = ((zephir_fast_count_int(&columnMap TSRMLS_CC)) ? 1 : 0);
					}
					if (_13$$10) {
						ZEPHIR_OBS_NVAR(&attribute);
						zephir_array_fetch(&attribute, &columnMap, &field, PH_NOISY, "phalcon/mvc/model/criteria.zep", 652 TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(&attribute, &field);
					}
					ZEPHIR_OBS_NVAR(&type);
					if (zephir_array_isset_fetch(&type, &dataTypes, &attribute, 0 TSRMLS_CC)) {
						_14$$13 = Z_TYPE_P(&value) != IS_NULL;
						if (_14$$13) {
							_14$$13 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
						}
						if (_14$$13) {
							if (ZEPHIR_IS_LONG(&type, 2)) {
								ZEPHIR_INIT_LNVAR(_15$$15);
								ZEPHIR_CONCAT_SVSVS(&_15$$15, "[", &field, "] LIKE :", &field, ":");
								zephir_array_append(&conditions, &_15$$15, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 664);
								ZEPHIR_INIT_LNVAR(_16$$15);
								ZEPHIR_CONCAT_SVS(&_16$$15, "%", &value, "%");
								zephir_array_update_zval(&bind, &field, &_16$$15, PH_COPY | PH_SEPARATE);
								continue;
							}
							ZEPHIR_INIT_LNVAR(_17$$14);
							ZEPHIR_CONCAT_SVSVS(&_17$$14, "[", &field, "] = :", &field, ":");
							zephir_array_append(&conditions, &_17$$14, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 671);
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
	if (zephir_has_constructor(&criteria TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &criteria, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(&conditions TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_18$$16);
		ZEPHIR_INIT_VAR(&_19$$16);
		ZEPHIR_CONCAT_SVS(&_19$$16, " ", &operator, " ");
		zephir_fast_join(&_18$$16, &_19$$16, &conditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &criteria, "where", NULL, 328, &_18$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &criteria, "bind", NULL, 329, &bind);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setmodelname", NULL, 322, &modelName);
	zephir_check_call_status();
	RETURN_CCTOR(&criteria);

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

	zval dependencyInjector, manager, builder, _1, _2, _3, _4;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, &dependencyInjector);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	zephir_read_property(&_3, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&builder, &manager, "createbuilder", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("_model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_CCTOR(&builder);

}

/**
 * Executes a find using the parameters built with the criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute) {

	zend_class_entry *_1;
	zval model, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&model, this_ptr, "getmodelname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&model) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Model name must be string", "phalcon/mvc/model/criteria.zep", 730);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparams", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_class(&model TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(_1, "find", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

