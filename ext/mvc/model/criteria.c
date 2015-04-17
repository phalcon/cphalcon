
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

#include "mvc/model/criteria.h"
#include "mvc/model/criteriainterface.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/exception.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"

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

#include "interned-strings.h"
#include "../modelinterface.h"

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
zend_class_entry *phalcon_mvc_model_criteria_ce;

PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_criteria_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Criteria, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, setModelName, arginfo_phalcon_mvc_model_criteriainterface_setmodelname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getModelName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bind, arginfo_phalcon_mvc_model_criteriainterface_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bindTypes, arginfo_phalcon_mvc_model_criteriainterface_bindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, columns, arginfo_phalcon_mvc_model_criteriainterface_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, join, arginfo_phalcon_mvc_model_criteriainterface_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, innerJoin, arginfo_phalcon_mvc_model_criteria_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, leftJoin, arginfo_phalcon_mvc_model_criteria_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, rightJoin, arginfo_phalcon_mvc_model_criteria_rightjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, where, arginfo_phalcon_mvc_model_criteriainterface_where, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Mvc_Model_Criteria, addWhere, andWhere, arginfo_phalcon_mvc_model_criteriainterface_andwhere, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
	PHP_ME(Phalcon_Mvc_Model_Criteria, andWhere, arginfo_phalcon_mvc_model_criteriainterface_andwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, orWhere, arginfo_phalcon_mvc_model_criteriainterface_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, betweenWhere, arginfo_phalcon_mvc_model_criteriainterface_betweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, notBetweenWhere, arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, inWhere, arginfo_phalcon_mvc_model_criteriainterface_inwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, notInWhere, arginfo_phalcon_mvc_model_criteriainterface_notinwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, conditions, arginfo_phalcon_mvc_model_criteriainterface_conditions, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Mvc_Model_Criteria, order, orderBy, arginfo_phalcon_mvc_model_criteriainterface_orderby, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
	PHP_ME(Phalcon_Mvc_Model_Criteria, orderBy, arginfo_phalcon_mvc_model_criteriainterface_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, limit, arginfo_phalcon_mvc_model_criteriainterface_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, forUpdate, arginfo_phalcon_mvc_model_criteriainterface_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, sharedLock, arginfo_phalcon_mvc_model_criteriainterface_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getConditions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getOrder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, fromInput, arginfo_phalcon_mvc_model_criteriainterface_frominput, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, execute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, cache, arginfo_phalcon_mvc_model_criteria_cache, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_model_exception_ce, 0);
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("di"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI){

	zval *params, *dependency_injector;

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&dependency_injector, params, SS("di"))) {
		RETURN_ZVAL(dependency_injector, 1, 0);
	}
	
	RETURN_NULL();
}

/**
 * Set a model on which the query will be executed
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\CriteriaInterface
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

	model = phalcon_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);
	RETURN_ZVAL(model, 1, 0);
}

/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 *
 * @param string $bindParams
 * @return Phalcon\Mvc\Model\CriteriaInterface
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns){

	zval *columns;

	phalcon_fetch_params(0, 1, 0, &columns);
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("columns"), columns TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Adds a join to the query
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, join){

	zval *model, *conditions = NULL, *alias = NULL, *type = NULL, *new_join, *params;
	zval *current_joins, *merged_joins = NULL, *new_join_array = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &model, &conditions, &alias, &type);
	
	if (!conditions) {
		conditions = PHALCON_GLOBAL(z_null);
	}
	
	if (!alias) {
		alias = PHALCON_GLOBAL(z_null);
	}
	
	if (!type) {
		type = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(new_join);
	array_init_size(new_join, 4);
	phalcon_array_append(&new_join, model, 0);
	phalcon_array_append(&new_join, conditions, 0);
	phalcon_array_append(&new_join, alias, 0);
	phalcon_array_append(&new_join, type, 0);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string(params, SS("joins"))) {
		
		PHALCON_INIT_VAR(new_join_array);
		array_init_size(new_join_array, 1);
		phalcon_array_append(&new_join_array, new_join, 0);

		PHALCON_OBS_VAR(current_joins);
		phalcon_array_fetch_string(&current_joins, params, SL("joins"), PH_NOISY);
		if (Z_TYPE_P(current_joins) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_joins);
			phalcon_fast_array_merge(merged_joins, &current_joins, &new_join_array TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_joins, new_join_array);
		}
	} else {
		PHALCON_INIT_NVAR(merged_joins);
		array_init_size(merged_joins, 1);
		phalcon_array_append(&merged_joins, new_join, 0);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin){

	zval *model, *conditions = NULL, *alias = NULL, *type, *new_join, *params;
	zval *current_joins, *merged_joins = NULL, *new_join_array = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &model, &conditions, &alias);
	
	if (!conditions) {
		conditions = PHALCON_GLOBAL(z_null);
	}
	
	if (!alias) {
		alias = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "INNER", 1);
	
	PHALCON_INIT_VAR(new_join);
	array_init_size(new_join, 4);
	phalcon_array_append(&new_join, model, 0);
	phalcon_array_append(&new_join, conditions, 0);
	phalcon_array_append(&new_join, alias, 0);
	phalcon_array_append(&new_join, type, 0);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string(params, SS("joins"))) {
		
		PHALCON_INIT_VAR(new_join_array);
		array_init_size(new_join_array, 1);
		phalcon_array_append(&new_join_array, new_join, 0);

		PHALCON_OBS_VAR(current_joins);
		phalcon_array_fetch_string(&current_joins, params, SL("joins"), PH_NOISY);
		if (Z_TYPE_P(current_joins) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_joins);
			phalcon_fast_array_merge(merged_joins, &current_joins, &new_join_array TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_joins, new_join_array);
		}
	} else {
		PHALCON_INIT_NVAR(merged_joins);
		array_init_size(merged_joins, 1);
		phalcon_array_append(&merged_joins, new_join, PH_SEPARATE);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin){

	zval *model, *conditions = NULL, *alias = NULL, *type, *new_join, *params;
	zval *current_joins, *merged_joins = NULL, *new_join_array = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &model, &conditions, &alias);
	
	if (!conditions) {
		conditions = PHALCON_GLOBAL(z_null);
	}
	
	if (!alias) {
		alias = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "LEFT", 1);
	
	PHALCON_INIT_VAR(new_join);
	array_init_size(new_join, 4);
	phalcon_array_append(&new_join, model, 0);
	phalcon_array_append(&new_join, conditions, 0);
	phalcon_array_append(&new_join, alias, 0);
	phalcon_array_append(&new_join, type, 0);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string(params, SS("joins"))) {

		PHALCON_INIT_VAR(new_join_array);
		array_init_size(new_join_array, 1);
		phalcon_array_append(&new_join_array, new_join, 0);

		PHALCON_OBS_VAR(current_joins);
		phalcon_array_fetch_string(&current_joins, params, SL("joins"), PH_NOISY);
		if (Z_TYPE_P(current_joins) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_joins);
			phalcon_fast_array_merge(merged_joins, &current_joins, &new_join_array TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_joins, new_join_array);
		}
	} else {
		PHALCON_INIT_NVAR(merged_joins);
		array_init_size(merged_joins, 1);
		phalcon_array_append(&merged_joins, new_join, PH_SEPARATE);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin){

	zval *model, *conditions = NULL, *alias = NULL, *type, *new_join, *params;
	zval *current_joins, *merged_joins = NULL, *new_join_array = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &model, &conditions, &alias);
	
	if (!conditions) {
		conditions = PHALCON_GLOBAL(z_null);
	}
	
	if (!alias) {
		alias = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "RIGHT", 1);
	
	PHALCON_INIT_VAR(new_join);
	array_init_size(new_join, 4);
	phalcon_array_append(&new_join, model, 0);
	phalcon_array_append(&new_join, conditions, 0);
	phalcon_array_append(&new_join, alias, 0);
	phalcon_array_append(&new_join, type, 0);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string(params, SS("joins"))) {

		PHALCON_INIT_VAR(new_join_array);
		array_init_size(new_join_array, 1);
		phalcon_array_append(&new_join_array, new_join, 0);

		PHALCON_OBS_VAR(current_joins);
		phalcon_array_fetch_string(&current_joins, params, SL("joins"), PH_NOISY);
		if (Z_TYPE_P(current_joins) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_joins);
			phalcon_fast_array_merge(merged_joins, &current_joins, &new_join_array TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_joins, new_join_array);
		}
	} else {
		PHALCON_INIT_NVAR(merged_joins);
		array_init_size(merged_joins, 1);
		phalcon_array_append(&merged_joins, new_join, PH_SEPARATE);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where){

	zval *conditions, *bind_params = NULL, *bind_types = NULL;
	zval *params = NULL, *current_bind_params, *merged_params = NULL;
	zval *current_bind_types, *merged_params_types = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &conditions, &bind_params, &bind_types);
	
	if (!bind_params) {
		bind_params = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_types) {
		bind_types = PHALCON_GLOBAL(z_null);
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
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
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
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Criteria, addWhere);

/**
 * Appends a condition to the current conditions using an AND operator
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere){

	zval *conditions, *bind_params = NULL, *bind_types = NULL;
	zval *params = NULL, *current_conditions, *new_conditions = NULL;
	zval *current_bind_params, *merged_params = NULL;
	zval *current_bind_types, *merged_params_types = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &conditions, &bind_params, &bind_types);
	
	if (!bind_params) {
		bind_params = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_types) {
		bind_types = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
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
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
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
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere){

	zval *conditions, *bind_params = NULL, *bind_types = NULL;
	zval *params = NULL, *current_conditions, *new_conditions = NULL;
	zval *current_bind_params, *merged_params = NULL;
	zval *current_bind_types, *merged_params_types = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &conditions, &bind_params, &bind_types);
	
	if (!bind_params) {
		bind_params = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_types) {
		bind_types = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
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
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
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
		phalcon_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere){

	zval *expr, *minimum, *maximum, *hidden_param;
	zval *next_hidden_param, *minimum_key, *maximum_key;
	zval *conditions, *bind_params;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &expr, &minimum, &maximum);
	
	PHALCON_OBS_VAR(hidden_param);
	phalcon_read_property_this(&hidden_param, this_ptr, SL("_hiddenParamNumber"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(next_hidden_param);
	phalcon_add_function(next_hidden_param, hidden_param, PHALCON_GLOBAL(z_one) TSRMLS_CC);
	
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
	phalcon_array_update_zval(&bind_params, minimum_key, minimum, PH_COPY);
	phalcon_array_update_zval(&bind_params, maximum_key, maximum, PH_COPY);
	
	/** 
	 * Append the BETWEEN to the current conditions using and 'and'
	 */
	PHALCON_CALL_METHOD(NULL, this_ptr, "andwhere", conditions, bind_params);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere){

	zval *expr, *minimum, *maximum, *hidden_param;
	zval *next_hidden_param, *minimum_key, *maximum_key;
	zval *conditions, *bind_params;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &expr, &minimum, &maximum);
	
	PHALCON_OBS_VAR(hidden_param);
	phalcon_read_property_this(&hidden_param, this_ptr, SL("_hiddenParamNumber"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(next_hidden_param);
	phalcon_add_function(next_hidden_param, hidden_param, PHALCON_GLOBAL(z_one) TSRMLS_CC);
	
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
	phalcon_array_update_zval(&bind_params, minimum_key, minimum, PH_COPY);
	phalcon_array_update_zval(&bind_params, maximum_key, maximum, PH_COPY);
	
	/** 
	 * Append the BETWEEN to the current conditions using and 'and'
	 */
	PHALCON_CALL_METHOD(NULL, this_ptr, "andwhere", conditions, bind_params);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
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
	phalcon_read_property_this(&hidden_param, this_ptr, SL("_hiddenParamNumber"), PH_NOISY TSRMLS_CC);
	SEPARATE_ZVAL(&hidden_param);
	
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
		phalcon_array_append(&bind_keys, query_key, 0);
		phalcon_array_update_zval(&bind_params, key, value, PH_COPY);
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
	PHALCON_CALL_METHOD(NULL, this_ptr, "andwhere", conditions, bind_params);
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
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
	phalcon_read_property_this(&hidden_param, this_ptr, SL("_hiddenParamNumber"), PH_NOISY TSRMLS_CC);
	SEPARATE_ZVAL(&hidden_param);
	
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
		phalcon_array_append(&bind_keys, query_key, 0);
		phalcon_array_update_zval(&bind_params, key, value, PH_COPY);
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
	PHALCON_CALL_METHOD(NULL, this_ptr, "andwhere", conditions, bind_params);
	phalcon_update_property_this(this_ptr, SL("_hiddenParamNumber"), hidden_param TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\CriteriaInterface
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
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Criteria, order)

/**
 * Adds the order-by parameter to the criteria
 *
 * @param string $orderColumns
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy){

	zval *order_columns;

	phalcon_fetch_params(0, 1, 0, &order_columns);
	
	if (Z_TYPE_P(order_columns) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Order columns must be string");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), ISS(order), order_columns TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Adds the limit parameter to the criteria
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit){

	zval *limit, *offset = NULL, *limit_clause;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &limit, &offset);
	
	if (!offset) {
		offset = PHALCON_GLOBAL(z_null);
	}
	
	if (!phalcon_is_numeric(limit)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Row limit parameter must be integer");
		return;
	}
	if (Z_TYPE_P(offset) == IS_NULL) {
		phalcon_update_property_array_string(this_ptr, SL("_params"), ISS(limit), limit TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(limit_clause);
		array_init_size(limit_clause, 2);
		phalcon_array_update_string(&limit_clause, ISL(number), limit, PH_COPY);
		phalcon_array_update_string(&limit_clause, ISL(offset), offset, PH_COPY);
		phalcon_update_property_array_string(this_ptr, SL("_params"), ISS(limit), limit_clause TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Adds the "for_update" parameter to the criteria
 *
 * @param boolean $forUpdate
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate){

	zval *for_update = NULL;

	phalcon_fetch_params(0, 0, 1, &for_update);
	
	if (!for_update) {
		for_update = PHALCON_GLOBAL(z_true);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("for_update"), for_update TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Adds the "shared_lock" parameter to the criteria
 *
 * @param boolean $sharedLock
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock){

	zval *shared_lock = NULL;

	phalcon_fetch_params(0, 0, 1, &shared_lock);
	
	if (!shared_lock) {
		shared_lock = PHALCON_GLOBAL(z_true);
	}
	
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("shared_lock"), shared_lock TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere){

	zval *params, *conditions;

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&conditions, params, SS("conditions"))) {
		RETURN_ZVAL(conditions, 1, 0);
	}
	
	RETURN_NULL();
}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns){

	zval *params, *columns;

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&columns, params, SS("columns"))) {
		RETURN_ZVAL(columns, 1, 0);
	}
	
	RETURN_NULL();
}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions){

	zval *params, *conditions;

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&conditions, params, SS("conditions"))) {
		RETURN_ZVAL(conditions, 1, 0);
	}
	
	RETURN_NULL();
}

/**
 * Returns the limit parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit){

	zval *params, *limit;

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&limit, params, SS("limit"))) {
		RETURN_ZVAL(limit, 1, 0);
	}
	
	RETURN_NULL();
}

/**
 * Returns the order parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder){

	zval *params, *order;

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&order, params, SS("order"))) {
		RETURN_ZVAL(order, 1, 0);
	}
	
	RETURN_NULL();
}

/**
 * Returns all the parameters defined in the criteria
 *
 * @return array
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
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput){

	zval *dependency_injector, *model_name, *data;
	zval *conditions, *service, *meta_data = NULL, *model;
	zval *data_types = NULL, *bind, *value = NULL, *field = NULL, *type, *condition = NULL;
	zval *value_pattern = NULL, *join_conditions;
	zval *column_map = NULL;
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
	
	object_init_ex(return_value, phalcon_mvc_model_criteria_ce);

	if (zend_hash_num_elements(Z_ARRVAL_P(data))) {
	
		PHALCON_INIT_VAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_modelsMetadata);
	
		PHALCON_CALL_METHOD(&meta_data, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(meta_data, phalcon_mvc_model_metadatainterface_ce);
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce0);
		if (phalcon_has_constructor(model TSRMLS_CC)) {
			PHALCON_CALL_METHOD(NULL, model, "__construct");
		}

		PHALCON_VERIFY_INTERFACE_EX(model, phalcon_mvc_modelinterface_ce, phalcon_mvc_model_exception_ce, 1);

		if (PHALCON_GLOBAL(orm).column_renaming) {
			PHALCON_CALL_METHOD(&column_map, meta_data, "getreversecolumnmap", model);
			if (Z_TYPE_P(column_map) != IS_ARRAY) {
				PHALCON_INIT_NVAR(column_map);
			}
		}
		else {
			column_map = PHALCON_GLOBAL(z_null);
		}

		PHALCON_CALL_METHOD(&data_types, meta_data, "getdatatypes", model);
	
		PHALCON_INIT_VAR(bind);
		array_init(bind);
	
		PHALCON_INIT_VAR(conditions);
		array_init(conditions);

		/** 
		 * We look for attributes in the array passed as data
		 */
		phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			zval *real_field;
	
			PHALCON_GET_HKEY(field, ah0, hp0);
			PHALCON_GET_HVALUE(value);

			if (Z_TYPE_P(column_map) != IS_ARRAY || !phalcon_array_isset_fetch(&real_field, column_map, field)) {
				real_field = field;
			}
	
			if (phalcon_array_isset_fetch(&type, data_types, real_field)) {
				if (Z_TYPE_P(value) != IS_NULL && !PHALCON_IS_STRING(value, "")) {
					if (PHALCON_IS_LONG(type, 2)) {
						/**
						 * For varchar types we use LIKE operator
						 */
						PHALCON_INIT_NVAR(condition);
						PHALCON_CONCAT_VSVS(condition, field, " LIKE :", field, ":");

						PHALCON_INIT_NVAR(value_pattern);
						PHALCON_CONCAT_SVS(value_pattern, "%", value, "%");
						phalcon_array_update_zval(&bind, field, value_pattern, PH_COPY);
					} else {
						/**
						 * For the rest of data types we use a plain = operator
						 */
						PHALCON_INIT_NVAR(condition);
						PHALCON_CONCAT_VSVS(condition, field, "=:", field, ":");
						phalcon_array_update_zval(&bind, field, value, PH_COPY);
					}

					phalcon_array_append(&conditions, condition, 0);
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		if (zend_hash_num_elements(Z_ARRVAL_P(conditions))) {
			PHALCON_INIT_VAR(join_conditions);
			phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
			PHALCON_CALL_METHOD(NULL, return_value, "where", join_conditions, bind);
		}
	}
	
	PHALCON_CALL_METHOD(NULL, return_value, "setmodelname", model_name);
	RETURN_MM();
}

/**
 * Executes a find using the parameters built with the criteria
 *
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute){

	zval *model, *params = NULL;
	zend_class_entry *ce;

	PHALCON_MM_GROW();

	model = phalcon_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(model) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model name must be string");
		return;
	}
	
	PHALCON_CALL_METHOD(&params, this_ptr, "getparams");
	
	ce = phalcon_fetch_class(model TSRMLS_CC);
	if (!ce) {
		zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "Class '%s' does not exist", Z_STRVAL_P(model));
		RETURN_MM();
	}

	PHALCON_RETURN_CALL_CE_STATIC(ce, "find", params);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the cache options in the criteria
 * This method replaces all previously set cache options
 *
 * @param array $options
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache){

	zval *options;

	phalcon_fetch_params(0, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Cache options must be an Array");
		return;
	}
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("cache"), options TSRMLS_CC);
	
	RETURN_THISW();
}

