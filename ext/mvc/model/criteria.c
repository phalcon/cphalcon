
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/hash.h"

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


/**
 * Phalcon\Mvc\Model\Criteria initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Criteria){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Criteria, mvc_model_criteria, phalcon_mvc_model_criteria_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_criteria_ce, SL("_hiddenParamNumber"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_criteria_ce TSRMLS_CC, 2, phalcon_mvc_model_criteriainterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Dependency Injector is invalid");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("di"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI){

	zval *params, *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("di"))) {
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_array_fetch_string(&dependency_injector, params, SL("di"), PH_NOISY);
		RETURN_CCTOR(dependency_injector);
	}
	
	RETURN_MM_NULL();
}

/**
 * Set a model on which the query will be executed
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName){

	zval *model_name;

	phalcon_fetch_params(0, 1, 0, &model_name);
	
	if (Z_TYPE_P(model_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Model name must be string");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_model"), model_name TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns an internal model name on which the criteria will be applied
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName){

	zval *model;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(model);
	phalcon_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	RETURN_CCTOR(model);
}

/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 *
 * @param string $bindParams
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind){

	zval *bind_params;

	phalcon_fetch_params(0, 1, 0, &bind_params);
	
	if (Z_TYPE_P(bind_params) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Bound parameters must be an Array");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bind"), bind_params TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 *
 * @param string $bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes){

	zval *bind_types;

	phalcon_fetch_params(0, 1, 0, &bind_types);
	
	if (Z_TYPE_P(bind_types) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Bind types parameters must be an Array");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bindTypes"), bind_types TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Sets the columns to be queried
 *
 *<code>
 *	$criteria->columns(array('id', 'name'));
 *</code>
 *
 * @param string|array $columns
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns){

	zval *columns;

	phalcon_fetch_params(0, 1, 0, &columns);
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("columns"), columns TSRMLS_CC);
	RETURN_THISW();
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
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @param string $type
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join){

	zval *model, *conditions = NULL, *alias = NULL, *type = NULL, *join, *params;
	zval *current_joins, *merged_joins = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &model, &conditions, &alias, &type);
	
	if (!conditions) {
		PHALCON_INIT_VAR(conditions);
	}
	
	if (!alias) {
		PHALCON_INIT_VAR(alias);
	}
	
	if (!type) {
		PHALCON_INIT_VAR(type);
	}
	
	PHALCON_INIT_VAR(join);
	array_init_size(join, 4);
	phalcon_array_append(&join, model, PH_SEPARATE);
	phalcon_array_append(&join, conditions, PH_SEPARATE);
	phalcon_array_append(&join, alias, PH_SEPARATE);
	phalcon_array_append(&join, type, PH_SEPARATE);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("joins"))) {
	
		PHALCON_OBS_VAR(current_joins);
		phalcon_array_fetch_string(&current_joins, params, SL("joins"), PH_NOISY);
		if (Z_TYPE_P(current_joins) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_joins);
			phalcon_fast_array_merge(merged_joins, &current_joins, &join TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_joins, join);
		}
	} else {
		PHALCON_INIT_NVAR(merged_joins);
		array_init_size(merged_joins, 1);
		phalcon_array_append(&merged_joins, join, PH_SEPARATE);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("joins"), merged_joins TSRMLS_CC);
	
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
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @param string $type
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin){

	zval *model, *conditions = NULL, *alias = NULL, *type, *join, *params;
	zval *current_joins, *merged_joins = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &model, &conditions, &alias);
	
	if (!conditions) {
		PHALCON_INIT_VAR(conditions);
	}
	
	if (!alias) {
		PHALCON_INIT_VAR(alias);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "INNER", 1);
	
	PHALCON_INIT_VAR(join);
	array_init_size(join, 4);
	phalcon_array_append(&join, model, PH_SEPARATE);
	phalcon_array_append(&join, conditions, PH_SEPARATE);
	phalcon_array_append(&join, alias, PH_SEPARATE);
	phalcon_array_append(&join, type, PH_SEPARATE);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("joins"))) {
	
		PHALCON_OBS_VAR(current_joins);
		phalcon_array_fetch_string(&current_joins, params, SL("joins"), PH_NOISY);
		if (Z_TYPE_P(current_joins) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_joins);
			phalcon_fast_array_merge(merged_joins, &current_joins, &join TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_joins, join);
		}
	} else {
		PHALCON_INIT_NVAR(merged_joins);
		array_init_size(merged_joins, 1);
		phalcon_array_append(&merged_joins, join, PH_SEPARATE);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("joins"), merged_joins TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Adds a LEFT join to the query
 *
 *<code>
 *	$criteria->leftJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *</code>
 *
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin){

	zval *model, *conditions = NULL, *alias = NULL, *type, *join, *params;
	zval *current_joins, *merged_joins = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &model, &conditions, &alias);
	
	if (!conditions) {
		PHALCON_INIT_VAR(conditions);
	}
	
	if (!alias) {
		PHALCON_INIT_VAR(alias);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "LEFT", 1);
	
	PHALCON_INIT_VAR(join);
	array_init_size(join, 4);
	phalcon_array_append(&join, model, PH_SEPARATE);
	phalcon_array_append(&join, conditions, PH_SEPARATE);
	phalcon_array_append(&join, alias, PH_SEPARATE);
	phalcon_array_append(&join, type, PH_SEPARATE);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("joins"))) {
	
		PHALCON_OBS_VAR(current_joins);
		phalcon_array_fetch_string(&current_joins, params, SL("joins"), PH_NOISY);
		if (Z_TYPE_P(current_joins) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_joins);
			phalcon_fast_array_merge(merged_joins, &current_joins, &join TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_joins, join);
		}
	} else {
		PHALCON_INIT_NVAR(merged_joins);
		array_init_size(merged_joins, 1);
		phalcon_array_append(&merged_joins, join, PH_SEPARATE);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("joins"), merged_joins TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Adds a RIGHT join to the query
 *
 *<code>
 *	$criteria->rightJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
 *</code>
 *
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin){

	zval *model, *conditions = NULL, *alias = NULL, *type, *join, *params;
	zval *current_joins, *merged_joins = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &model, &conditions, &alias);
	
	if (!conditions) {
		PHALCON_INIT_VAR(conditions);
	}
	
	if (!alias) {
		PHALCON_INIT_VAR(alias);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "RIGHT", 1);
	
	PHALCON_INIT_VAR(join);
	array_init_size(join, 4);
	phalcon_array_append(&join, model, PH_SEPARATE);
	phalcon_array_append(&join, conditions, PH_SEPARATE);
	phalcon_array_append(&join, alias, PH_SEPARATE);
	phalcon_array_append(&join, type, PH_SEPARATE);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("joins"))) {
	
		PHALCON_OBS_VAR(current_joins);
		phalcon_array_fetch_string(&current_joins, params, SL("joins"), PH_NOISY);
		if (Z_TYPE_P(current_joins) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_joins);
			phalcon_fast_array_merge(merged_joins, &current_joins, &join TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_joins, join);
		}
	} else {
		PHALCON_INIT_NVAR(merged_joins);
		array_init_size(merged_joins, 1);
		phalcon_array_append(&merged_joins, join, PH_SEPARATE);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("joins"), merged_joins TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Sets the conditions parameter in the criteria
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where){

	zval *conditions, *bind_params = NULL, *bind_types = NULL;
	zval *params = NULL, *current_bind_params, *merged_params = NULL;
	zval *current_bind_types, *merged_params_types = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &conditions, &bind_params, &bind_types);
	
	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("conditions"), conditions TSRMLS_CC);
	
	/** 
	 * Update or merge existing bound parameters
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_OBS_VAR(params);
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bind"))) {
			PHALCON_OBS_VAR(current_bind_params);
			phalcon_array_fetch_string(&current_bind_params, params, SL("bind"), PH_NOISY);
	
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &current_bind_params, &bind_params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, bind_params);
		}
	
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bind"), merged_params TSRMLS_CC);
	}
	
	/** 
	 * Update or merge existing bind types parameters
	 */
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(params);
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bindTypes"))) {
			PHALCON_OBS_VAR(current_bind_types);
			phalcon_array_fetch_string(&current_bind_types, params, SL("bindTypes"), PH_NOISY);
	
			PHALCON_INIT_VAR(merged_params_types);
			phalcon_fast_array_merge(merged_params_types, &current_bind_types, &bind_types TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params_types, bind_types);
		}
	
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bindTypes"), merged_params_types TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Appends a condition to the current conditions using an AND operator (deprecated)
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, addWhere){

	zval *conditions, *bind_params = NULL, *bind_types = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &conditions, &bind_params, &bind_types);
	
	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	phalcon_call_method_p3_noret(this_ptr, "andwhere", conditions, bind_params, bind_types);
	RETURN_THIS();
}

/**
 * Appends a condition to the current conditions using an AND operator
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere){

	zval *conditions, *bind_params = NULL, *bind_types = NULL;
	zval *params = NULL, *current_conditions, *new_conditions = NULL;
	zval *current_bind_params, *merged_params = NULL;
	zval *current_bind_types, *merged_params_types = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &conditions, &bind_params, &bind_types);
	
	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("conditions"))) {
		PHALCON_OBS_VAR(current_conditions);
		phalcon_array_fetch_string(&current_conditions, params, SL("conditions"), PH_NOISY);
	
		PHALCON_INIT_VAR(new_conditions);
		PHALCON_CONCAT_SVSVS(new_conditions, "(", current_conditions, ") AND (", conditions, ")");
	} else {
		PHALCON_CPY_WRT(new_conditions, conditions);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("conditions"), new_conditions TSRMLS_CC);
	
	/** 
	 * Update or merge existing bound parameters
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(params);
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bind"))) {
			PHALCON_OBS_VAR(current_bind_params);
			phalcon_array_fetch_string(&current_bind_params, params, SL("bind"), PH_NOISY);
	
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &current_bind_params, &bind_params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, bind_params);
		}
	
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bind"), merged_params TSRMLS_CC);
	}
	
	/** 
	 * Update or merge existing bind types parameters
	 */
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(params);
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bindTypes"))) {
			PHALCON_OBS_VAR(current_bind_types);
			phalcon_array_fetch_string(&current_bind_types, params, SL("bindTypes"), PH_NOISY);
	
			PHALCON_INIT_VAR(merged_params_types);
			phalcon_fast_array_merge(merged_params_types, &current_bind_types, &bind_types TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params_types, bind_types);
		}
	
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bindTypes"), merged_params_types TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Appends a condition to the current conditions using an OR operator
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere){

	zval *conditions, *bind_params = NULL, *bind_types = NULL;
	zval *params = NULL, *current_conditions, *new_conditions = NULL;
	zval *current_bind_params, *merged_params = NULL;
	zval *current_bind_types, *merged_params_types = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &conditions, &bind_params, &bind_types);
	
	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("conditions"))) {
		PHALCON_OBS_VAR(current_conditions);
		phalcon_array_fetch_string(&current_conditions, params, SL("conditions"), PH_NOISY);
	
		PHALCON_INIT_VAR(new_conditions);
		PHALCON_CONCAT_SVSVS(new_conditions, "(", current_conditions, ") OR (", conditions, ")");
	} else {
		PHALCON_CPY_WRT(new_conditions, conditions);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("conditions"), new_conditions TSRMLS_CC);
	
	/** 
	 * Update or merge existing bound parameters
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(params);
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bind"))) {
			PHALCON_OBS_VAR(current_bind_params);
			phalcon_array_fetch_string(&current_bind_params, params, SL("bind"), PH_NOISY);
	
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &current_bind_params, &bind_params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, bind_params);
		}
	
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bind"), merged_params TSRMLS_CC);
	}
	
	/** 
	 * Update or merge existing bind types parameters
	 */
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(params);
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bindTypes"))) {
			PHALCON_OBS_VAR(current_bind_types);
			phalcon_array_fetch_string(&current_bind_types, params, SL("bindTypes"), PH_NOISY);
	
			PHALCON_INIT_VAR(merged_params_types);
			phalcon_fast_array_merge(merged_params_types, &current_bind_types, &bind_types TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params_types, bind_types);
		}
	
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bindTypes"), merged_params_types TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Appends a BETWEEN condition to the current conditions
 *
 *<code>
 *	$criteria->betweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string $expr
 * @param mixed $minimum
 * @param mixed $maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere){

	zval *expr, *minimum, *maximum, *hidden_param, *one;
	zval *next_hidden_param, *minimum_key, *maximum_key;
	zval *conditions, *bind_params;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &expr, &minimum, &maximum);
	
	PHALCON_OBS_VAR(hidden_param);
	phalcon_read_property_this(&hidden_param, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	
	PHALCON_INIT_VAR(next_hidden_param);
	phalcon_add_function(next_hidden_param, hidden_param, one TSRMLS_CC);
	
	/** 
	 * Minimum key with auto bind-params
	 */
	PHALCON_INIT_VAR(minimum_key);
	PHALCON_CONCAT_SV(minimum_key, "phb", hidden_param);
	
	/** 
	 * Maximum key with auto bind-params
	 */
	PHALCON_INIT_VAR(maximum_key);
	PHALCON_CONCAT_SV(maximum_key, "phb", next_hidden_param);
	
	/** 
	 * Create a standard BETWEEN condition with bind params
	 */
	PHALCON_INIT_VAR(conditions);
	PHALCON_CONCAT_VSVSVS(conditions, expr, " BETWEEN :", minimum_key, ": AND :", maximum_key, ":");
	
	PHALCON_INIT_VAR(bind_params);
	array_init_size(bind_params, 2);
	phalcon_array_update_zval(&bind_params, minimum_key, &minimum, PH_COPY | PH_SEPARATE);
	phalcon_array_update_zval(&bind_params, maximum_key, &maximum, PH_COPY | PH_SEPARATE);
	
	/** 
	 * Append the BETWEEN to the current conditions using and 'and'
	 */
	phalcon_call_method_p2_noret(this_ptr, "andwhere", conditions, bind_params);
	PHALCON_SEPARATE(next_hidden_param);
	phalcon_increment(next_hidden_param);
	phalcon_update_property_this(this_ptr, SL("_hiddenParamNumber"), next_hidden_param TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 *<code>
 *	$criteria->notBetweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string $expr
 * @param mixed $minimum
 * @param mixed $maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere){

	zval *expr, *minimum, *maximum, *hidden_param, *one;
	zval *next_hidden_param, *minimum_key, *maximum_key;
	zval *conditions, *bind_params;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &expr, &minimum, &maximum);
	
	PHALCON_OBS_VAR(hidden_param);
	phalcon_read_property_this(&hidden_param, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	
	PHALCON_INIT_VAR(next_hidden_param);
	phalcon_add_function(next_hidden_param, hidden_param, one TSRMLS_CC);
	
	/** 
	 * Minimum key with auto bind-params
	 */
	PHALCON_INIT_VAR(minimum_key);
	PHALCON_CONCAT_SV(minimum_key, "phb", hidden_param);
	
	/** 
	 * Maximum key with auto bind-params
	 */
	PHALCON_INIT_VAR(maximum_key);
	PHALCON_CONCAT_SV(maximum_key, "phb", next_hidden_param);
	
	/** 
	 * Create a standard BETWEEN condition with bind params
	 */
	PHALCON_INIT_VAR(conditions);
	PHALCON_CONCAT_VSVSVS(conditions, expr, " NOT BETWEEN :", minimum_key, ": AND :", maximum_key, ":");
	
	PHALCON_INIT_VAR(bind_params);
	array_init_size(bind_params, 2);
	phalcon_array_update_zval(&bind_params, minimum_key, &minimum, PH_COPY | PH_SEPARATE);
	phalcon_array_update_zval(&bind_params, maximum_key, &maximum, PH_COPY | PH_SEPARATE);
	
	/** 
	 * Append the BETWEEN to the current conditions using and 'and'
	 */
	phalcon_call_method_p2_noret(this_ptr, "andwhere", conditions, bind_params);
	PHALCON_SEPARATE(next_hidden_param);
	phalcon_increment(next_hidden_param);
	phalcon_update_property_this(this_ptr, SL("_hiddenParamNumber"), next_hidden_param TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Appends an IN condition to the current conditions
 *
 *<code>
 *	$criteria->inWhere('id', [1, 2, 3]);
 *</code>
 *
 * @param string $expr
 * @param array $values
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere){

	zval *expr, *values, *hidden_param, *bind_params;
	zval *bind_keys, *value = NULL, *key = NULL, *query_key = NULL, *joined_keys;
	zval *conditions;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &expr, &values);
	
	if (Z_TYPE_P(values) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Values must be an array");
		return;
	}
	
	PHALCON_OBS_VAR(hidden_param);
	phalcon_read_property_this(&hidden_param, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(bind_params);
	array_init(bind_params);
	
	PHALCON_INIT_VAR(bind_keys);
	array_init(bind_keys);
	
	phalcon_is_iterable(values, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(value);
	
		/** 
		 * Key with auto bind-params
		 */
		PHALCON_INIT_NVAR(key);
		PHALCON_CONCAT_SV(key, "phi", hidden_param);
	
		PHALCON_INIT_NVAR(query_key);
		PHALCON_CONCAT_SVS(query_key, ":", key, ":");
		phalcon_array_append(&bind_keys, query_key, PH_SEPARATE);
		phalcon_array_update_zval(&bind_params, key, &value, PH_COPY | PH_SEPARATE);
		PHALCON_SEPARATE(hidden_param);
		phalcon_increment(hidden_param);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(joined_keys);
	phalcon_fast_join_str(joined_keys, SL(", "), bind_keys TSRMLS_CC);
	
	/** 
	 * Create a standard IN condition with bind params
	 */
	PHALCON_INIT_VAR(conditions);
	PHALCON_CONCAT_VSVS(conditions, expr, " IN (", joined_keys, ")");
	
	/** 
	 * Append the IN to the current conditions using and 'and'
	 */
	phalcon_call_method_p2_noret(this_ptr, "andwhere", conditions, bind_params);
	phalcon_update_property_this(this_ptr, SL("_hiddenParamNumber"), hidden_param TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Appends a NOT IN condition to the current conditions
 *
 *<code>
 *	$criteria->notInWhere('id', [1, 2, 3]);
 *</code>
 *
 * @param string $expr
 * @param array $values
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere){

	zval *expr, *values, *hidden_param, *bind_params;
	zval *bind_keys, *value = NULL, *key = NULL, *query_key = NULL, *joined_keys;
	zval *conditions;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &expr, &values);
	
	if (Z_TYPE_P(values) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Values must be an array");
		return;
	}
	
	PHALCON_OBS_VAR(hidden_param);
	phalcon_read_property_this(&hidden_param, this_ptr, SL("_hiddenParamNumber"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(bind_params);
	array_init(bind_params);
	
	PHALCON_INIT_VAR(bind_keys);
	array_init(bind_keys);
	
	phalcon_is_iterable(values, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(value);
	
		/** 
		 * Key with auto bind-params
		 */
		PHALCON_INIT_NVAR(key);
		PHALCON_CONCAT_SV(key, "phi", hidden_param);
	
		PHALCON_INIT_NVAR(query_key);
		PHALCON_CONCAT_SVS(query_key, ":", key, ":");
		phalcon_array_append(&bind_keys, query_key, PH_SEPARATE);
		phalcon_array_update_zval(&bind_params, key, &value, PH_COPY | PH_SEPARATE);
		PHALCON_SEPARATE(hidden_param);
		phalcon_increment(hidden_param);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(joined_keys);
	phalcon_fast_join_str(joined_keys, SL(", "), bind_keys TSRMLS_CC);
	
	/** 
	 * Create a standard IN condition with bind params
	 */
	PHALCON_INIT_VAR(conditions);
	PHALCON_CONCAT_VSVS(conditions, expr, " NOT IN (", joined_keys, ")");
	
	/** 
	 * Append the IN to the current conditions using and 'and'
	 */
	phalcon_call_method_p2_noret(this_ptr, "andwhere", conditions, bind_params);
	phalcon_update_property_this(this_ptr, SL("_hiddenParamNumber"), hidden_param TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions){

	zval *conditions;

	phalcon_fetch_params(0, 1, 0, &conditions);
	
	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("conditions"), conditions TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Adds the order-by parameter to the criteria (deprecated)
 *
 * @param string $orderColumns
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, order){

	zval *order_columns;

	phalcon_fetch_params(0, 1, 0, &order_columns);
	
	if (Z_TYPE_P(order_columns) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Order columns must be string");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("order"), order_columns TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Adds the order-by parameter to the criteria
 *
 * @param string $orderColumns
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy){

	zval *order_columns;

	phalcon_fetch_params(0, 1, 0, &order_columns);
	
	if (Z_TYPE_P(order_columns) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Order columns must be string");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("order"), order_columns TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Adds the limit parameter to the criteria
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit){

	zval *limit, *offset = NULL, *limit_clause;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &limit, &offset);
	
	if (!offset) {
		PHALCON_INIT_VAR(offset);
	}
	
	if (!phalcon_is_numeric(limit)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Rows limit parameter must be integer");
		return;
	}
	if (Z_TYPE_P(offset) == IS_NULL) {
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("limit"), limit TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(limit_clause);
		array_init_size(limit_clause, 2);
		phalcon_array_update_string(&limit_clause, SL("number"), &limit, PH_COPY | PH_SEPARATE);
		phalcon_array_update_string(&limit_clause, SL("offset"), &offset, PH_COPY | PH_SEPARATE);
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("limit"), limit_clause TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Adds the "for_update" parameter to the criteria
 *
 * @param boolean $forUpdate
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate){

	zval *for_update = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &for_update);
	
	if (!for_update) {
		PHALCON_INIT_VAR(for_update);
		ZVAL_BOOL(for_update, 1);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("for_update"), for_update TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Adds the "shared_lock" parameter to the criteria
 *
 * @param boolean $sharedLock
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock){

	zval *shared_lock = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &shared_lock);
	
	if (!shared_lock) {
		PHALCON_INIT_VAR(shared_lock);
		ZVAL_BOOL(shared_lock, 1);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("shared_lock"), shared_lock TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere){

	zval *params, *conditions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("conditions"))) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY);
		RETURN_CCTOR(conditions);
	}
	
	RETURN_MM_NULL();
}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns){

	zval *params, *columns;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("columns"))) {
		PHALCON_OBS_VAR(columns);
		phalcon_array_fetch_string(&columns, params, SL("columns"), PH_NOISY);
		RETURN_CCTOR(columns);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions){

	zval *params, *conditions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("conditions"))) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY);
		RETURN_CCTOR(conditions);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the limit parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit){

	zval *params, *conditions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("limit"))) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("limit"), PH_NOISY);
		RETURN_CCTOR(conditions);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the order parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder){

	zval *params, *conditions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("order"))) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("order"), PH_NOISY);
		RETURN_CCTOR(conditions);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns all the parameters defined in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams){


	RETURN_MEMBER(this_ptr, "_params");
}

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param string $modelName
 * @param array $data
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput){

	zval *dependency_injector, *model_name, *data;
	zval *conditions, *service, *meta_data, *model;
	zval *data_types, *bind, *value = NULL, *field = NULL, *type = NULL, *condition = NULL;
	zval *value_pattern = NULL, *join_conditions;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &dependency_injector, &model_name, &data);
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Input data must be an Array");
		return;
	}
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the ORM services");
		return;
	}
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	if (phalcon_fast_count_ev(data TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "modelsMetadata", 1);
	
		PHALCON_INIT_VAR(meta_data);
		phalcon_call_method_p1(meta_data, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(meta_data, phalcon_mvc_model_metadatainterface_ce);
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce0);
		if (phalcon_has_constructor(model TSRMLS_CC)) {
			phalcon_call_method_noret(model, "__construct");
		}
	
		PHALCON_INIT_VAR(data_types);
		phalcon_call_method_p1(data_types, meta_data, "getdatatypes", model);
	
		PHALCON_INIT_VAR(bind);
		array_init(bind);
	
		/** 
		 * We look for attributes in the array passed as data
		 */
		phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(field, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			if (phalcon_array_isset(data_types, field)) {
				if (Z_TYPE_P(value) != IS_NULL) {
					if (!PHALCON_IS_STRING(value, "")) {
	
						PHALCON_OBS_NVAR(type);
						phalcon_array_fetch(&type, data_types, field, PH_NOISY);
						if (PHALCON_IS_LONG(type, 2)) {
							/** 
							 * For varchar types we use LIKE operator
							 */
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_VSVS(condition, field, " LIKE :", field, ":");
	
							PHALCON_INIT_NVAR(value_pattern);
							PHALCON_CONCAT_SVS(value_pattern, "%", value, "%");
							phalcon_array_update_zval(&bind, field, &value_pattern, PH_COPY | PH_SEPARATE);
						} else {
							/** 
							 * For the rest of data types we use a plain = operator
							 */
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_VSVS(condition, field, "=:", field, ":");
							phalcon_array_update_zval(&bind, field, &value, PH_COPY | PH_SEPARATE);
						}
	
						phalcon_array_append(&conditions, condition, PH_SEPARATE);
					}
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * Create an object instance and pass the paramaters to it
	 */
	object_init_ex(return_value, phalcon_mvc_model_criteria_ce);
	if (phalcon_fast_count_ev(conditions TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_conditions);
		phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
		phalcon_call_method_p1_noret(return_value, "where", join_conditions);
		phalcon_call_method_p1_noret(return_value, "bind", bind);
	}
	
	phalcon_call_method_p1_noret(return_value, "setmodelname", model_name);
	RETURN_MM();
}

/**
 * Executes a find using the parameters built with the criteria
 *
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute){

	zval *model, *params, *resultset;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(model);
	phalcon_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (Z_TYPE_P(model) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model name must be string");
		return;
	}
	
	PHALCON_INIT_VAR(params);
	phalcon_call_method(params, this_ptr, "getparams");
	
	PHALCON_INIT_VAR(resultset);
	phalcon_call_zval_str_static_p1(resultset, model, "find", params);
	
	RETURN_CCTOR(resultset);
}

