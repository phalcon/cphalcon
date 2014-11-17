
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Model\Criteria
 *
 * This class allows to build the array parameter required by Phalcon\Mvc\Model::find
 * and Phalcon\Mvc\Model::findFirst using an object-oriented interface
 *
 *<code>
 *$robots = Robots::query()
 *    ->where("type = :type:")
 *    ->andWhere("year < 2000")
 *    ->bind(array("type" => "mechanical"))
 *    ->order("name")
 *    ->execute();
 *</code>
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
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI) {

	zval *dependencyInjector, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencyInjector);



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "di", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, dependencyInjector TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI) {

	zval *dependencyInjector, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&dependencyInjector, _0, SS("di"), 1 TSRMLS_CC)) {
		RETURN_CTORW(dependencyInjector);
	}
	RETURN_NULL();

}

/**
 * Set a model on which the query will be executed
 *
 * @param string modelName
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName) {

	zval *modelName_param = NULL;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}


	zephir_update_property_this(this_ptr, SL("_model"), modelName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns an internal model name on which the criteria will be applied
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName) {


	RETURN_MEMBER(this_ptr, "_model");

}

/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 *
 * @param array bindParams
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind) {

	zval *bindParams_param = NULL, *_0;
	zval *bindParams = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bindParams_param);

	if (unlikely(Z_TYPE_P(bindParams_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'bindParams' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		bindParams = bindParams_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "bind", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, bindParams TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 *
 * @param string bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes) {

	zval *bindTypes_param = NULL, *_0;
	zval *bindTypes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bindTypes_param);

	if (unlikely(Z_TYPE_P(bindTypes_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'bindTypes' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		bindTypes = bindTypes_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "bindTypes", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, bindTypes TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the columns to be queried
 *
 *<code>
 *	$criteria->columns(array('id', 'name'));
 *</code>
 *
 * @param string|array columns
 * @return Phalcon\Mvc\Model\Criteria
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
 * Adds a INNER join to the query
 *
 *<code>
 *	$criteria->join('Robots');
 *	$criteria->join('Robots', 'r.id = RobotsParts.robots_id');
 *	$criteria->join('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *	$criteria->join('Robots', 'r.id = RobotsParts.robots_id', 'r', 'LEFT');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @param string type
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join) {

	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *type = NULL, *join, *mergedJoins = NULL, *currentJoins, *_0, *_1;
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


	ZEPHIR_INIT_VAR(join);
	array_init_size(join, 7);
	zephir_array_fast_append(join, model);
	zephir_array_fast_append(join, conditions);
	zephir_array_fast_append(join, alias);
	zephir_array_fast_append(join, type);
	ZEPHIR_OBS_VAR(currentJoins);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&currentJoins, _0, SS("joins"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(currentJoins) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedJoins);
			zephir_fast_array_merge(mergedJoins, &(currentJoins), &(join) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedJoins, join);
		}
	} else {
		ZEPHIR_INIT_NVAR(mergedJoins);
		array_init_size(mergedJoins, 2);
		zephir_array_fast_append(mergedJoins, join);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "joins", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _1, mergedJoins TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a INNER join to the query
 *
 *<code>
 *	$criteria->innerJoin('Robots');
 *	$criteria->innerJoin('Robots', 'r.id = RobotsParts.robots_id');
 *	$criteria->innerJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *	$criteria->innerJoin('Robots', 'r.id = RobotsParts.robots_id', 'r', 'LEFT');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @param string type
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin) {

	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *join, *mergedJoins = NULL, *currentJoins, *_0 = NULL, *_1;
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


	ZEPHIR_INIT_VAR(join);
	array_init_size(join, 7);
	zephir_array_fast_append(join, model);
	zephir_array_fast_append(join, conditions);
	zephir_array_fast_append(join, alias);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "INNER", 1);
	zephir_array_fast_append(join, _0);
	ZEPHIR_OBS_VAR(currentJoins);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&currentJoins, _1, SS("joins"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(currentJoins) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedJoins);
			zephir_fast_array_merge(mergedJoins, &(currentJoins), &(join) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedJoins, join);
		}
	} else {
		ZEPHIR_INIT_NVAR(mergedJoins);
		array_init_size(mergedJoins, 2);
		zephir_array_fast_append(mergedJoins, join);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "joins", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, mergedJoins TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a LEFT join to the query
 *
 *<code>
 *	$criteria->leftJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin) {

	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *join, *mergedJoins = NULL, *currentJoins, *_0 = NULL, *_1;
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


	ZEPHIR_INIT_VAR(join);
	array_init_size(join, 7);
	zephir_array_fast_append(join, model);
	zephir_array_fast_append(join, conditions);
	zephir_array_fast_append(join, alias);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "LEFT", 1);
	zephir_array_fast_append(join, _0);
	ZEPHIR_OBS_VAR(currentJoins);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&currentJoins, _1, SS("joins"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(currentJoins) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedJoins);
			zephir_fast_array_merge(mergedJoins, &(currentJoins), &(join) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedJoins, join);
		}
	} else {
		ZEPHIR_INIT_NVAR(mergedJoins);
		array_init_size(mergedJoins, 2);
		zephir_array_fast_append(mergedJoins, join);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "joins", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, mergedJoins TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a RIGHT join to the query
 *
 *<code>
 *	$criteria->rightJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *</code>
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin) {

	zval *model_param = NULL, *conditions = NULL, *alias = NULL, *join, *mergedJoins = NULL, *currentJoins, *_0 = NULL, *_1;
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


	ZEPHIR_INIT_VAR(join);
	array_init_size(join, 7);
	zephir_array_fast_append(join, model);
	zephir_array_fast_append(join, conditions);
	zephir_array_fast_append(join, alias);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "RIGHT", 1);
	zephir_array_fast_append(join, _0);
	ZEPHIR_OBS_VAR(currentJoins);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&currentJoins, _1, SS("joins"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(currentJoins) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedJoins);
			zephir_fast_array_merge(mergedJoins, &(currentJoins), &(join) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedJoins, join);
		}
	} else {
		ZEPHIR_INIT_NVAR(mergedJoins);
		array_init_size(mergedJoins, 2);
		zephir_array_fast_append(mergedJoins, join);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "joins", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, mergedJoins TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the conditions parameter in the criteria
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where) {

	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *mergedParams = NULL, *mergedParamsTypes = NULL, *currentBindTypes, *_0, *_1, *_2 = NULL;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "conditions", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, conditions TSRMLS_CC);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(currentBindParams);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&currentBindParams, _1, SS("bind"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(currentBindParams), &(bindParams) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "bind", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _2, mergedParams TSRMLS_CC);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(currentBindTypes);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&currentBindTypes, _1, SS("bindTypes"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(mergedParamsTypes);
			zephir_fast_array_merge(mergedParamsTypes, &(currentBindTypes), &(bindTypes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParamsTypes, bindTypes);
		}
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "bindTypes", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _2, mergedParamsTypes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Appends a condition to the current conditions using an AND operator (deprecated)
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, addWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *conditions, *bindParams = NULL, *bindTypes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &conditions, &bindParams, &bindTypes);

	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "andwhere", NULL, conditions, bindParams, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a condition to the current conditions using an AND operator
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere) {

	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *mergedParams = NULL, *mergedParamsTypes = NULL, *currentBindTypes, *params, *currentConditions, *_0, *_1 = NULL;
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


	ZEPHIR_OBS_VAR(params);
	zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(currentConditions);
	if (zephir_array_isset_string_fetch(&currentConditions, params, SS("conditions"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "(", currentConditions, ") AND (", conditions, ")");
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "conditions", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _1, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "conditions", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _1, conditions TSRMLS_CC);
	}
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(currentBindParams);
		if (zephir_array_isset_string_fetch(&currentBindParams, params, SS("bind"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(currentBindParams), &(bindParams) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "bind", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _1, mergedParams TSRMLS_CC);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(currentBindTypes);
		if (zephir_array_isset_string_fetch(&currentBindTypes, params, SS("bindTypes"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(mergedParamsTypes);
			zephir_fast_array_merge(mergedParamsTypes, &(currentBindTypes), &(bindTypes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParamsTypes, bindTypes);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "bindTypes", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _1, mergedParamsTypes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Appends a condition to the current conditions using an OR operator
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere) {

	zval *conditions_param = NULL, *bindParams = NULL, *bindTypes = NULL, *currentBindParams, *mergedParams = NULL, *mergedParamsTypes = NULL, *currentBindTypes, *params, *currentConditions, *_0, *_1 = NULL;
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


	ZEPHIR_OBS_VAR(params);
	zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(currentConditions);
	if (zephir_array_isset_string_fetch(&currentConditions, params, SS("conditions"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "(", currentConditions, ") OR (", conditions, ")");
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "conditions", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _1, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "conditions", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _1, conditions TSRMLS_CC);
	}
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(currentBindParams);
		if (zephir_array_isset_string_fetch(&currentBindParams, params, SS("bind"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(currentBindParams), &(bindParams) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, bindParams);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "bind", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _1, mergedParams TSRMLS_CC);
	}
	if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(currentBindTypes);
		if (zephir_array_isset_string_fetch(&currentBindTypes, params, SS("bindTypes"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(mergedParamsTypes);
			zephir_fast_array_merge(mergedParamsTypes, &(currentBindTypes), &(bindTypes) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParamsTypes, bindTypes);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "bindTypes", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _1, mergedParamsTypes TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Appends a BETWEEN condition to the current conditions
 *
 *<code>
 *	criteria->betweenWhere("price", 100.25, 200.50);
 *</code>
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *expr_param = NULL, *minimum, *maximum, *hiddenParam, *minimumKey, *nextHiddenParam, *maximumKey, *_0;
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
	ZEPHIR_CONCAT_SV(minimumKey, "phb", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "phb", nextHiddenParam);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVSVS(_0, expr, " BETWEEN :", minimumKey, ": AND :", maximumKey, ":");
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_update_zval(&_1, minimumKey, &minimum, PH_COPY);
	zephir_array_update_zval(&_1, maximumKey, &maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, _0, _1);
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
 *	criteria->notBetweenWhere("price", 100.25, 200.50);
 *</code>
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere) {

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
	ZEPHIR_CONCAT_SV(minimumKey, "phb", hiddenParam);
	ZEPHIR_INIT_VAR(maximumKey);
	ZEPHIR_CONCAT_SV(maximumKey, "phb", nextHiddenParam);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVSVS(_0, expr, " NOT BETWEEN :", minimumKey, ": AND :", maximumKey, ":");
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_update_zval(&_1, minimumKey, &minimum, PH_COPY);
	zephir_array_update_zval(&_1, maximumKey, &maximum, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, _0, _1);
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
 *	criteria->inWhere("id", [1, 2, 3]);
 *</code>
 *
 * @param string expr
 * @param array values
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *hiddenParam, *bindParams, *bindKeys, *value = NULL, *key = NULL, *queryKey = NULL, **_2, *_3, *_4;
	zval *expr = NULL;

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
	if (unlikely(Z_TYPE_P(values_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'values' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		values = values_param;



	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_1, &_0, 0, 0, "phalcon/mvc/model/criteria.zep", 554);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_NVAR(key);
		ZEPHIR_CONCAT_SV(key, "phi", hiddenParam);
		ZEPHIR_INIT_NVAR(queryKey);
		ZEPHIR_CONCAT_SVS(queryKey, ":", key, ":");
		zephir_array_append(&bindKeys, queryKey, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 545);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_SEPARATE(hiddenParam);
		zephir_increment(hiddenParam);
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_join_str(_3, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VSVS(_4, expr, " IN (", _3, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, _4, bindParams);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_hiddenParamNumber"), hiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a NOT IN condition to the current conditions
 *
 *<code>
 *	criteria->notInWhere("id", [1, 2, 3]);
 *</code>
 *
 * @param string expr
 * @param array values
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *values = NULL;
	zval *expr_param = NULL, *values_param = NULL, *hiddenParam, *bindParams, *bindKeys, *value = NULL, *key = NULL, **_2, *_3 = NULL, *_4;
	zval *expr = NULL;

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
	if (unlikely(Z_TYPE_P(values_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'values' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		values = values_param;



	ZEPHIR_OBS_VAR(hiddenParam);
	zephir_read_property_this(&hiddenParam, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	ZEPHIR_INIT_VAR(bindKeys);
	array_init(bindKeys);
	zephir_is_iterable(values, &_1, &_0, 0, 0, "phalcon/mvc/model/criteria.zep", 595);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_NVAR(key);
		ZEPHIR_CONCAT_SV(key, "phi", hiddenParam);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVS(_3, ":", key, ":");
		zephir_array_append(&bindKeys, _3, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 585);
		zephir_array_update_zval(&bindParams, key, &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_SEPARATE(hiddenParam);
		zephir_increment(hiddenParam);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), bindKeys TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_VSVS(_3, expr, " NOT IN (", _4, ")");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "andwhere", NULL, _3, bindParams);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_hiddenParamNumber"), hiddenParam TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string conditions
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions) {

	zval *conditions_param = NULL, *_0;
	zval *conditions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &conditions_param);

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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "conditions", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, conditions TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds the order-by parameter to the criteria (deprecated)
 *
 * @param string orderColumns
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, order) {

	zval *orderColumns_param = NULL, *_0;
	zval *orderColumns = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderColumns_param);

	if (unlikely(Z_TYPE_P(orderColumns_param) != IS_STRING && Z_TYPE_P(orderColumns_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'orderColumns' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(orderColumns_param) == IS_STRING)) {
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
 * Adds the order-by parameter to the criteria
 *
 * @param string orderColumns
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy) {

	zval *orderColumns_param = NULL, *_0;
	zval *orderColumns = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderColumns_param);

	if (unlikely(Z_TYPE_P(orderColumns_param) != IS_STRING && Z_TYPE_P(orderColumns_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'orderColumns' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(orderColumns_param) == IS_STRING)) {
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
 * Adds the limit parameter to the criteria
 *
 * @param int limit
 * @param int offset
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit) {

	zval *_2;
	zval *limit_param = NULL, *offset = NULL, *_0 = NULL, *_1;
	int limit;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit_param, &offset);

	limit = zephir_get_intval(limit_param);
	if (!offset) {
		offset = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(offset) == IS_NULL) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "limit", 1);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, limit);
		zephir_update_property_array(this_ptr, SL("_params"), _0, _1 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 3);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, limit);
		zephir_array_update_string(&_2, SL("number"), &_0, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2, SL("offset"), &offset, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "limit", 1);
		zephir_update_property_array(this_ptr, SL("_params"), _0, _2 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Adds the "for_update" parameter to the criteria
 *
 * @param boolean forUpdate
 * @return Phalcon\Mvc\Model\Criteria
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
 *
 * @param boolean sharedLock
 * @return Phalcon\Mvc\Model\Criteria
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
 *
 * @param array options
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache) {

	zval *cache_param = NULL, *_0;
	zval *cache = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cache_param);

	if (unlikely(Z_TYPE_P(cache_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cache' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		cache = cache_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "cache", 1);
	zephir_update_property_array(this_ptr, SL("_params"), _0, cache TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere) {

	zval *conditions, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&conditions, _0, SS("conditions"), 1 TSRMLS_CC)) {
		RETURN_CTORW(conditions);
	}
	RETURN_NULL();

}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns) {

	zval *columns, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&columns, _0, SS("columns"), 1 TSRMLS_CC)) {
		RETURN_CTORW(columns);
	}
	RETURN_NULL();

}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions) {

	zval *conditions, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&conditions, _0, SS("conditions"), 1 TSRMLS_CC)) {
		RETURN_CTORW(conditions);
	}
	RETURN_NULL();

}

/**
 * Returns the limit parameter in the criteria
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit) {

	zval *limit, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&limit, _0, SS("order"), 1 TSRMLS_CC)) {
		RETURN_CTORW(limit);
	}
	RETURN_NULL();

}

/**
 * Returns the order parameter in the criteria
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder) {

	zval *order, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&order, _0, SS("order"), 1 TSRMLS_CC)) {
		RETURN_CTORW(order);
	}
	RETURN_NULL();

}

/**
 * Returns all the parameters defined in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like _POST
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param string modelName
 * @param array data
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput) {

	zend_bool _6;
	HashTable *_4;
	HashPosition _3;
	zend_class_entry *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *modelName = NULL;
	zval *dependencyInjector, *modelName_param = NULL, *data_param = NULL, *conditions, *field = NULL, *value = NULL, *type = NULL, *metaData = NULL, *model, *dataTypes = NULL, *bind, *criteria, *_0 = NULL, *_1 = NULL, **_5, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &modelName_param, &data_param);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	if (zephir_fast_count_int(data TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(model);
		zephir_fetch_safe_class(_1, modelName);
		_2 = zend_fetch_class(Z_STRVAL_P(_1), Z_STRLEN_P(_1), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(model, _2);
		if (zephir_has_constructor(model TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, model, "__construct", NULL);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&dataTypes, metaData, "getdatatypes", NULL, model);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(bind);
		array_init(bind);
		zephir_is_iterable(data, &_4, &_3, 0, 0, "phalcon/mvc/model/criteria.zep", 814);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HMKEY(field, _4, _3);
			ZEPHIR_GET_HVALUE(value, _5);
			ZEPHIR_OBS_NVAR(type);
			if (zephir_array_isset_fetch(&type, dataTypes, field, 0 TSRMLS_CC)) {
				_6 = Z_TYPE_P(value) != IS_NULL;
				if (_6) {
					_6 = !ZEPHIR_IS_STRING_IDENTICAL(value, "");
				}
				if (_6) {
					if (ZEPHIR_IS_LONG(type, 2)) {
						ZEPHIR_INIT_LNVAR(_7);
						ZEPHIR_CONCAT_VSVS(_7, field, " LIKE :", field, ":");
						zephir_array_append(&conditions, _7, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 804);
						ZEPHIR_INIT_LNVAR(_8);
						ZEPHIR_CONCAT_SVS(_8, "%", value, "%");
						zephir_array_update_zval(&bind, field, &_8, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_LNVAR(_7);
						ZEPHIR_CONCAT_VSVS(_7, field, "=:", field, ":");
						zephir_array_append(&conditions, _7, PH_SEPARATE, "phalcon/mvc/model/criteria.zep", 809);
						zephir_array_update_zval(&bind, field, &value, PH_COPY | PH_SEPARATE);
					}
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(criteria);
	object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
	if (zephir_has_constructor(criteria TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, criteria, "__construct", NULL);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(conditions TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_join_str(_0, SL(" AND "), conditions TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, criteria, "where", NULL, _0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, criteria, "bind", NULL, bind);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, criteria, "setmodelname", NULL, modelName);
	zephir_check_call_status();
	RETURN_CCTOR(criteria);

}

/**
 * Executes a find using the parameters built with the criteria
 *
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(model);
	zephir_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (Z_TYPE_P(model) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Model name must be string", "phalcon/mvc/model/criteria.zep", 839);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparams", NULL);
	zephir_check_call_status();
	_1 = zend_fetch_class(Z_STRVAL_P(model), Z_STRLEN_P(model), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(_1, "find", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

