
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
#include "mvc/model/query.h"
#include "di.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "mvc/model/query/scanner.h"

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
PHP_METHOD(Phalcon_Mvc_Model_Criteria, groupBy);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, having);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, insert);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, update);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, delete);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getPhql);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, _generateSelect);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, _generateInsert);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, _generateUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, _generateDelete);


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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_having, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_criteria_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Criteria, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, setModelName, arginfo_phalcon_mvc_model_criteriainterface_setmodelname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getModelName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bind, arginfo_phalcon_mvc_model_criteriainterface_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bindTypes, arginfo_phalcon_mvc_model_criteriainterface_bindtypes, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Mvc_Model_Criteria, select, columns, arginfo_phalcon_mvc_model_criteriainterface_columns, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
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
	PHP_ME(Phalcon_Mvc_Model_Criteria, groupBy, arginfo_phalcon_mvc_model_criteria_groupby, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, having, arginfo_phalcon_mvc_model_criteria_having, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, execute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, cache, arginfo_phalcon_mvc_model_criteria_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, insert, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, update, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getPhql, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, _generateSelect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, _generateInsert, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, _generateUpdate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, _generateDelete, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Criteria initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Criteria){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Criteria, mvc_model_criteria, phalcon_mvc_model_criteria_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_values"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_joins"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_conditions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_order"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_limit"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_offset"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_forUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_sharedLock"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_criteria_ce, SL("_hiddenParamNumber"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_group"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_having"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("di"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI){

	RETURN_MEMBER(this_ptr, "_dependencyInjector");
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

	RETURN_MEMBER(this_ptr, "_model");
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
	phalcon_update_property_this(this_ptr, SL("_bindParams"), bind_params TSRMLS_CC);
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
	phalcon_update_property_this(this_ptr, SS("_bindTypes"), bind_types TSRMLS_CC);
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

	zval *columns, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &columns);

	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, PHQL_T_SELECT);

	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("columns"), columns TSRMLS_CC);
	RETURN_THIS();
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

	zval *model, *conditions = NULL, *alias = NULL, *type = NULL, *new_join;
	zval *joins;

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

	phalcon_array_append(&new_join, model, PH_COPY);
	phalcon_array_append(&new_join, conditions, PH_COPY);
	phalcon_array_append(&new_join, alias, PH_COPY);
	phalcon_array_append(&new_join, type, PH_COPY);
	
	PHALCON_OBS_VAR(joins);
	phalcon_read_property_this(&joins, this_ptr, SL("_joins"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(joins) != IS_ARRAY) {
		PHALCON_INIT_NVAR(joins);
		array_init_size(joins, 1);
	}

	phalcon_array_append(&joins, new_join, PH_COPY);

	phalcon_update_property_this(this_ptr, SL("_joins"), joins TSRMLS_CC);
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("joins"), joins TSRMLS_CC);

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

	zval *model, *conditions = NULL, *alias = NULL, *type;

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
	
	PHALCON_CALL_SELF(NULL, "join", model, conditions, alias, type);

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

	zval *model, *conditions = NULL, *alias = NULL, *type;

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
	
	PHALCON_CALL_SELF(NULL, "join", model, conditions, alias, type);
	
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

	zval *model, *conditions = NULL, *alias = NULL, *type;

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
	
	PHALCON_CALL_SELF(NULL, "join", model, conditions, alias, type);
	
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
	phalcon_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("conditions"), conditions TSRMLS_CC);
	
	/** 
	 * Update or merge existing bound parameters
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_OBS_VAR(current_bind_params);
		phalcon_read_property_this(&current_bind_params, this_ptr, SL("_bindParams"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(current_bind_params) == IS_ARRAY) {
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &current_bind_params, &bind_params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, bind_params);
		}
	
		phalcon_update_property_this(this_ptr, SL("_bindParams"), merged_params TSRMLS_CC);
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bind"), merged_params TSRMLS_CC);
	}
	
	/** 
	 * Update or merge existing bind types parameters
	 */
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(current_bind_types);
		phalcon_read_property_this(&current_bind_types, this_ptr, SL("_bindTypes"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(current_bind_types) == IS_ARRAY) {	
			PHALCON_INIT_VAR(merged_params_types);
			phalcon_fast_array_merge(merged_params_types, &current_bind_types, &bind_types TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params_types, bind_types);
		}
	
		phalcon_update_property_this(this_ptr, SL("_bindTypes"), merged_params_types TSRMLS_CC);
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
	zval *current_conditions, *new_conditions = NULL;
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
	
	PHALCON_OBS_VAR(current_conditions);
	phalcon_read_property_this(&current_conditions, this_ptr, SL("_conditions"), PH_NOISY TSRMLS_CC);
	if (!PHALCON_IS_EMPTY(current_conditions)) {
		PHALCON_INIT_VAR(new_conditions);
		PHALCON_CONCAT_SVSVS(new_conditions, "(", current_conditions, ") AND (", conditions, ")");
	} else {
		PHALCON_CPY_WRT(new_conditions, conditions);
	}
	
	phalcon_update_property_this(this_ptr, SL("_conditions"), new_conditions TSRMLS_CC);
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("conditions"), new_conditions TSRMLS_CC);
	
	/** 
	 * Update or merge existing bound parameters
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(current_bind_params);
		phalcon_read_property_this(&current_bind_params, this_ptr, SL("_bindParams"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(current_bind_params) == IS_ARRAY) {	
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &current_bind_params, &bind_params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, bind_params);
		}
	
		phalcon_update_property_this(this_ptr, SL("_bindParams"), merged_params TSRMLS_CC);
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bind"), merged_params TSRMLS_CC);
	}
	
	/** 
	 * Update or merge existing bind types parameters
	 */
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(current_bind_types);
		phalcon_read_property_this(&current_bind_types, this_ptr, SL("_bindTypes"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(current_bind_types) == IS_ARRAY) {
			PHALCON_INIT_VAR(merged_params_types);
			phalcon_fast_array_merge(merged_params_types, &current_bind_types, &bind_types TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params_types, bind_types);
		}
	
		phalcon_update_property_this(this_ptr, SL("_bindTypes"), merged_params_types TSRMLS_CC);
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
	zval *current_conditions, *new_conditions = NULL;
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
	
	PHALCON_OBS_VAR(current_conditions);
	phalcon_read_property_this(&current_conditions, this_ptr, SL("_conditions"), PH_NOISY TSRMLS_CC);
	if (!PHALCON_IS_EMPTY(current_conditions)) {	
		PHALCON_INIT_VAR(new_conditions);
		PHALCON_CONCAT_SVSVS(new_conditions, "(", current_conditions, ") OR (", conditions, ")");
	} else {
		PHALCON_CPY_WRT(new_conditions, conditions);
	}
	
	phalcon_update_property_this(this_ptr, SL("_conditions"), new_conditions TSRMLS_CC);
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("conditions"), new_conditions TSRMLS_CC);
	
	/** 
	 * Update or merge existing bound parameters
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(current_bind_params);
		phalcon_read_property_this(&current_bind_params, this_ptr, SL("_bindParams"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(current_bind_params) == IS_ARRAY) {	
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &current_bind_params, &bind_params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, bind_params);
		}
	
		phalcon_update_property_this(this_ptr, SL("_bindParams"), merged_params TSRMLS_CC);
		phalcon_update_property_array_string(this_ptr, SL("_params"), SS("bind"), merged_params TSRMLS_CC);
	}
	
	/** 
	 * Update or merge existing bind types parameters
	 */
	if (Z_TYPE_P(bind_types) == IS_ARRAY) { 
	
		PHALCON_OBS_NVAR(current_bind_types);
		phalcon_read_property_this(&current_bind_types, this_ptr, SL("_bindTypes"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(current_bind_types) == IS_ARRAY) {
			PHALCON_INIT_VAR(merged_params_types);
			phalcon_fast_array_merge(merged_params_types, &current_bind_types, &bind_types TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params_types, bind_types);
		}
	
		phalcon_update_property_this(this_ptr, SL("_bindTypes"), merged_params_types TSRMLS_CC);
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
 * @return Phalcon\Mvc\Model\CriteriaIntreface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions){

	zval *conditions;

	phalcon_fetch_params(0, 1, 0, &conditions);
	
	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
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
	phalcon_update_property_this(this_ptr, SL("_order"), order_columns TSRMLS_CC);
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

	phalcon_update_property_this(this_ptr, SL("_limit"), limit TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_offset"), offset TSRMLS_CC);

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
	
	phalcon_update_property_this(this_ptr, SL("_forUpdate"), for_update TSRMLS_CC);
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
	
	phalcon_update_property_this(this_ptr, SL("_sharedLock"), shared_lock TSRMLS_CC);
	phalcon_update_property_array_string(this_ptr, SL("_params"), SS("shared_lock"), shared_lock TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere){


	RETURN_MEMBER(this_ptr, "_conditions");
}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns){


	RETURN_MEMBER(this_ptr, "_columns");
}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions){


	RETURN_MEMBER(this_ptr, "_conditions");
}

/**
 * Returns the limit parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit){


	RETURN_MEMBER(this_ptr, "_limit");
}

/**
 * Returns the order parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder){

	RETURN_MEMBER(this_ptr, "_order");
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
			PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", model);
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
 * Sets a GROUP BY clause
 *
 * @param string $group
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, groupBy){

	zval *group;

	phalcon_fetch_params(0, 1, 0, &group);
	
	phalcon_update_property_this(this_ptr, SL("_group"), group TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets a HAVING condition clause. You need to escape PHQL reserved words using [ and ] delimiters
 *
 * @param string $having
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, having){

	zval *having;

	phalcon_fetch_params(0, 1, 0, &having);
	
	phalcon_update_property_this(this_ptr, SL("_having"), having TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Executes a find using the parameters built with the criteria
 *
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute){

	zval *model, *type, *phql = NULL, *dependency_injector, *query;
	zval *bind_params, *bind_types, *params = NULL;
	zend_class_entry *ce;

	PHALCON_MM_GROW();

	model = phalcon_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(model) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model name must be string");
		return;
	}

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY TSRMLS_CC);
	
	switch (phalcon_get_intval(type)) {
		case PHQL_T_INSERT:	
		case PHQL_T_UPDATE:
		case PHQL_T_DELETE:
		{
			PHALCON_CALL_SELF(&phql, "getphql");

			dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);

			PHALCON_INIT_VAR(query);
			object_init_ex(query, phalcon_mvc_model_query_ce);
			PHALCON_CALL_METHOD(NULL, query, "__construct", phql, dependency_injector);

			bind_params = phalcon_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY TSRMLS_CC);
			bind_types = phalcon_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY TSRMLS_CC);

			if (Z_TYPE_P(bind_params) == IS_ARRAY && Z_TYPE_P(bind_types) == IS_ARRAY) { 
				PHALCON_CALL_METHOD(NULL, query, "execute", bind_params, bind_types);
			} else if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
				PHALCON_RETURN_CALL_METHOD(query, "execute", bind_params);
			} else {
				PHALCON_RETURN_CALL_METHOD(query, "execute");
			}
			
			break;
		}
		default:
		{
			PHALCON_CALL_METHOD(&params, this_ptr, "getparams");
			
			ce = phalcon_fetch_class(model TSRMLS_CC);
			if (!ce) {
				zend_throw_exception_ex(phalcon_mvc_model_exception_ce, 0 TSRMLS_CC, "Class '%s' does not exist", Z_STRVAL_P(model));
				RETURN_MM();
			}

			PHALCON_RETURN_CALL_CE_STATIC(ce, "find", params);
			break;	
		}
	}
	
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

/**
 * Sets insert type of PHQL statement to be executed
 *
 * @param array $columns
 * @param array $values
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, insert){

	zval *columns, *values, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &columns, &values);

	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, PHQL_T_INSERT);

	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	
	if (Z_TYPE_P(columns) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Columns must be an array");
		return;
	}
	
	if (Z_TYPE_P(values) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Values must be an array");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_values"), values TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Sets update type of PHQL statement to be executed
 *
 * @param array $columns
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, update){

	zval *columns, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &columns);

	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, PHQL_T_UPDATE);

	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	
	if (columns && Z_TYPE_P(columns) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Columns must be an array");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Sets update type of PHQL statement to be executed
 *
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, delete){

	zval *type;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, PHQL_T_DELETE);

	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns a PHQL statement built with the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getPhql){

	zval *type;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY TSRMLS_CC);
	
	switch (phalcon_get_intval(type)) {
		case PHQL_T_INSERT:
			PHALCON_RETURN_CALL_METHOD(this_ptr, "_generateinsert");
			break;
	
		case PHQL_T_UPDATE:
			PHALCON_RETURN_CALL_METHOD(this_ptr, "_generateupdate");
			break;
	
		case PHQL_T_DELETE:
			PHALCON_RETURN_CALL_METHOD(this_ptr, "_generatedelete");
			break;
	
		default:
			PHALCON_RETURN_CALL_METHOD(this_ptr, "_generateselect");
			break;
	
	}

	PHALCON_MM_RESTORE();
}

/**
 * Returns a PHQL statement built with the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, _generateSelect){

	zval *dependency_injector = NULL, *model, *conditions = NULL;
	zval *service_name, *meta_data = NULL, *model_instance;
	zval *no_primary = NULL, *primary_keys = NULL, *first_primary_key;
	zval *column_map = NULL, *attribute_field = NULL, *exception_message;
	zval *primary_key_condition, *phql, *columns;
	zval *selected_columns = NULL, *column = NULL, *column_alias = NULL;
	zval *aliased_column = NULL, *joined_columns = NULL;
	zval *joins, *join = NULL, *join_model = NULL, *join_conditions = NULL, *join_alias = NULL;
	zval *join_type = NULL, *group, *group_items, *group_item = NULL;
	zval *escaped_item = NULL, *joined_items = NULL, *having, *order;
	zval *order_items, *order_item = NULL, *limit, *number, *for_update;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		dependency_injector = NULL;
		PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	model = phalcon_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(model)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
		return;
	}
	
	PHALCON_OBS_VAR(conditions);
	phalcon_read_property_this(&conditions, this_ptr, SL("_conditions"), PH_NOISY TSRMLS_CC);
	if (phalcon_is_numeric(conditions)) {
	
		/** 
		 * If the conditions is a single numeric field. We internally create a condition
		 * using the related primary key
		 */
		PHALCON_INIT_VAR(service_name);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service_name, phalcon_interned_modelsMetadata);
	
		/** 
		 * Get the models metadata service to obtain the column names, column map and
		 * primary key
		 */
		PHALCON_CALL_METHOD(&meta_data, dependency_injector, "getshared", service_name);
		PHALCON_VERIFY_INTERFACE(meta_data, phalcon_mvc_model_metadatainterface_ce);
		ce0 = phalcon_fetch_class(model TSRMLS_CC);
	
		PHALCON_INIT_VAR(model_instance);
		object_init_ex(model_instance, ce0);
		if (phalcon_has_constructor(model_instance TSRMLS_CC)) {
			PHALCON_CALL_METHOD(NULL, model_instance, "__construct", dependency_injector);
		}
	
		PHALCON_INIT_VAR(no_primary);
		ZVAL_TRUE(no_primary);
	
		PHALCON_CALL_METHOD(&primary_keys, meta_data, "getprimarykeyattributes", model_instance);
		if (phalcon_fast_count_ev(primary_keys TSRMLS_CC)) {
			if (phalcon_array_isset_long(primary_keys, 0)) {
	
				PHALCON_OBS_VAR(first_primary_key);
				phalcon_array_fetch_long(&first_primary_key, primary_keys, 0, PH_NOISY);
	
				/** 
				 * The PHQL contains the renamed columns if available
				 */
				if (PHALCON_GLOBAL(orm).column_renaming) {
					PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", model_instance);
				} else {
					PHALCON_INIT_VAR(column_map);
				}
	
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
					if (phalcon_array_isset(column_map, first_primary_key)) {
						PHALCON_OBS_VAR(attribute_field);
						phalcon_array_fetch(&attribute_field, column_map, first_primary_key, PH_NOISY);
					} else {
						PHALCON_INIT_VAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", first_primary_key, "\" isn't part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_CPY_WRT(attribute_field, first_primary_key);
				}
	
				PHALCON_INIT_VAR(primary_key_condition);
				PHALCON_CONCAT_SVSVSV(primary_key_condition, "[", model, "].[", attribute_field, "] = ", conditions);
				PHALCON_CPY_WRT(conditions, primary_key_condition);
	
				ZVAL_FALSE(no_primary);
			}
		}
	
		/** 
		 * A primary key is mandatory in these cases
		 */
		if (PHALCON_IS_TRUE(no_primary)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined");
			return;
		}
	}
	
	PHALCON_INIT_VAR(phql);
	ZVAL_STRING(phql, "SELECT ", 1);
	
	PHALCON_OBS_VAR(columns);
	phalcon_read_property_this(&columns, this_ptr, SL("_columns"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(columns) != IS_NULL) {
	
		/** 
		 * Generate PHQL for columns
		 */
		if (Z_TYPE_P(columns) == IS_ARRAY) { 
	
			PHALCON_INIT_VAR(selected_columns);
			array_init(selected_columns);
	
			phalcon_is_iterable(columns, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(column_alias, ah0, hp0);
				PHALCON_GET_HVALUE(column);
	
				if (Z_TYPE_P(column_alias) == IS_LONG) {
					phalcon_array_append(&selected_columns, column, PH_COPY);
				} else {
					PHALCON_INIT_NVAR(aliased_column);
					PHALCON_CONCAT_VSV(aliased_column, column, " AS ", column_alias);
					phalcon_array_append(&selected_columns, aliased_column, PH_COPY);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			PHALCON_INIT_VAR(joined_columns);
			phalcon_fast_join_str(joined_columns, SL(", "), selected_columns TSRMLS_CC);
			phalcon_concat_self(&phql, joined_columns TSRMLS_CC);
		} else {
			phalcon_concat_self(&phql, columns TSRMLS_CC);
		}
	} else {
		/** 
		 * Automatically generate an array of model
		 */
		PHALCON_SCONCAT_SVS(phql, "[", model, "].*");
	}

	PHALCON_SCONCAT_SVS(phql, " FROM [", model, "]");
	
	/** 
	 * Check if joins were passed to the builders
	 */
	PHALCON_OBS_VAR(joins);
	phalcon_read_property_this(&joins, this_ptr, SL("_joins"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(joins) == IS_ARRAY) { 
	
		phalcon_is_iterable(joins, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(join);
	
			/** 
			 * The joined table is in the first place of the array
			 */
			PHALCON_OBS_NVAR(join_model);
			phalcon_array_fetch_long(&join_model, join, 0, PH_NOISY);
	
			/** 
			 * The join conditions are in the second place of the array
			 */
			PHALCON_OBS_NVAR(join_conditions);
			phalcon_array_fetch_long(&join_conditions, join, 1, PH_NOISY);
	
			/** 
			 * The join alias is in the second place of the array
			 */
			PHALCON_OBS_NVAR(join_alias);
			phalcon_array_fetch_long(&join_alias, join, 2, PH_NOISY);
	
			/** 
			 * Join type
			 */
			PHALCON_OBS_NVAR(join_type);
			phalcon_array_fetch_long(&join_type, join, 3, PH_NOISY);
	
			/** 
			 * Create the join according to the type
			 */
			if (zend_is_true(join_type)) {
				PHALCON_SCONCAT_SVSVS(phql, " ", join_type, " JOIN [", join_model, "]");
			} else {
				PHALCON_SCONCAT_SVS(phql, " JOIN [", join_model, "]");
			}
	
			/** 
			 * Alias comes first
			 */
			if (zend_is_true(join_alias)) {
				PHALCON_SCONCAT_SVS(phql, " AS [", join_alias, "]");
			}
	
			/** 
			 * Conditions then
			 */
			if (zend_is_true(join_conditions)) {
				PHALCON_SCONCAT_SV(phql, " ON ", join_conditions);
			}
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	}
	
	/** 
	 * Only append conditions if it's string
	 */
	if (Z_TYPE_P(conditions) == IS_STRING) {
		if (PHALCON_IS_NOT_EMPTY(conditions)) {
			PHALCON_SCONCAT_SV(phql, " WHERE ", conditions);
		}
	}

	/** 
	 * Process group parameters
	 */
	PHALCON_OBS_VAR(group);
	phalcon_read_property_this(&group, this_ptr, SL("_group"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(group) != IS_NULL) {
		if (Z_TYPE_P(group) == IS_ARRAY) { 
	
			PHALCON_INIT_VAR(group_items);
			array_init(group_items);
	
			phalcon_is_iterable(group, &ah2, &hp2, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
				PHALCON_GET_HVALUE(group_item);
	
				if (phalcon_is_numeric(group_item)) {
					phalcon_array_append(&group_items, group_item, PH_SEPARATE);
				} else {
					if (phalcon_memnstr_str(group_item, SL("."))) {
						phalcon_array_append(&group_items, group_item, PH_SEPARATE);
					} else {
						PHALCON_INIT_NVAR(escaped_item);
						PHALCON_CONCAT_SVS(escaped_item, "[", group_item, "]");
						phalcon_array_append(&group_items, escaped_item, PH_SEPARATE);
					}
				}
	
				zend_hash_move_forward_ex(ah2, &hp2);
			}
	
			PHALCON_INIT_VAR(joined_items);
			phalcon_fast_join_str(joined_items, SL(", "), group_items TSRMLS_CC);
			PHALCON_SCONCAT_SV(phql, " GROUP BY ", joined_items);
		} else {
			if (phalcon_is_numeric(group)) {
				PHALCON_SCONCAT_SV(phql, " GROUP BY ", group);
			} else {
				if (phalcon_memnstr_str(group, SL("."))) {
					PHALCON_SCONCAT_SV(phql, " GROUP BY ", group);
				} else if (phalcon_memnstr_str(group, SL(","))) {
					PHALCON_INIT_VAR(group_items);
					phalcon_fast_explode_str(group_items, SL(", "), group);

					PHALCON_INIT_VAR(joined_items);
					phalcon_fast_join_str(joined_items, SL("], ["), group_items TSRMLS_CC);

					PHALCON_SCONCAT_SVS(phql, " GROUP BY [", joined_items, "]");
				} else {
					PHALCON_SCONCAT_SVS(phql, " GROUP BY [", group, "]");
				}
			}
		}
	}
	
	/* Process HAVING clause */
	PHALCON_OBS_VAR(having);
	phalcon_read_property_this(&having, this_ptr, SL("_having"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(having) != IS_NULL) {
		if (PHALCON_IS_NOT_EMPTY(having)) {
			PHALCON_SCONCAT_SV(phql, " HAVING ", having);
		}
	}

	/** 
	 * Process order clause
	 */
	PHALCON_OBS_VAR(order);
	phalcon_read_property_this(&order, this_ptr, SL("_order"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_NOT_EMPTY(order)) {
		if (Z_TYPE_P(order) == IS_ARRAY) { 
	
			PHALCON_INIT_VAR(order_items);
			array_init(order_items);
	
			phalcon_is_iterable(order, &ah3, &hp3, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
				PHALCON_GET_HVALUE(order_item);
	
				if (phalcon_is_numeric(order_item)) {
					phalcon_array_append(&order_items, order_item, PH_COPY);
				} else {
					if (phalcon_memnstr_str(order_item, SL("."))) {
						phalcon_array_append(&order_items, order_item, PH_COPY);
					} else {
						PHALCON_INIT_NVAR(escaped_item);
						PHALCON_CONCAT_SVS(escaped_item, "[", order_item, "]");
						phalcon_array_append(&order_items, escaped_item, PH_COPY);
					}
				}
	
				zend_hash_move_forward_ex(ah3, &hp3);
			}
	
			PHALCON_INIT_NVAR(joined_items);
			phalcon_fast_join_str(joined_items, SL(", "), order_items TSRMLS_CC);
			PHALCON_SCONCAT_SV(phql, " ORDER BY ", joined_items);
		} else {
			PHALCON_SCONCAT_SV(phql, " ORDER BY ", order);
		}
	}
	
	/** 
	 * Process limit parameters
	 */
	limit = phalcon_fetch_nproperty_this(this_ptr, SL("_limit"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(limit) != IS_NULL) {
		if (Z_TYPE_P(limit) == IS_ARRAY) { 
			zval *offset;
	
			PHALCON_OBS_VAR(number);
			phalcon_array_fetch_string(&number, limit, SL("number"), PH_NOISY);
			if (phalcon_array_isset_string_fetch(&offset, limit, SS("offset")) && Z_TYPE_P(offset) != IS_NULL) {
				PHALCON_SCONCAT_SVSV(phql, " LIMIT ", number, " OFFSET ", offset);
			} else {
				PHALCON_SCONCAT_SV(phql, " LIMIT ", number);
			}
		} else {
			zval *offset;

			PHALCON_SCONCAT_SV(phql, " LIMIT ", limit);

			offset = phalcon_fetch_nproperty_this(this_ptr, SL("_offset"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(offset) != IS_NULL) {
				PHALCON_SCONCAT_SV(phql, " OFFSET ", offset);
			}
		}
	}
	
	/** 
	 * Process FOR UPDATE clause
	 */
	for_update = phalcon_fetch_nproperty_this(this_ptr, SL("_forUpdate"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(for_update)) {
		phalcon_concat_self_str(&phql, SL(" FOR UPDATE") TSRMLS_CC);
	}
	
	RETURN_CTOR(phql);
}

/**
 * Returns a PHQL statement built with the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, _generateInsert){

	zval *model, *exception_message;
	zval *phql, *columns, *selected_columns, *joined_columns, *column = NULL;
	zval *rows, *index = NULL, *index2 = NULL, *insert_sqls, *bind_params, *keys = NULL, *key = NULL, *row = NULL, *value = NULL;
	zval *joined_keys = NULL, *insert_sql = NULL, *joined_insert_sqls;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();
	
	model = phalcon_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(model)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
		return;
	}

	PHALCON_INIT_VAR(phql);
	ZVAL_STRING(phql, "INSERT INTO ", 1);

	PHALCON_SCONCAT_SVS(phql, "[", model, "] ");
	
	PHALCON_OBS_VAR(columns);
	phalcon_read_property_this(&columns, this_ptr, SL("_columns"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(selected_columns);
	array_init(selected_columns);

	phalcon_is_iterable(columns, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		PHALCON_GET_HVALUE(column);

		phalcon_array_append(&selected_columns, column, PH_COPY);

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_INIT_VAR(joined_columns);
	phalcon_fast_join_str(joined_columns, SL(", "), selected_columns TSRMLS_CC);

	PHALCON_SCONCAT_SVS(phql, "(", joined_columns, ")");

	PHALCON_OBS_VAR(rows);
	phalcon_read_property_this(&rows, this_ptr, SL("_values"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(insert_sqls);
	array_init(insert_sqls);

	PHALCON_INIT_VAR(bind_params);
	array_init(bind_params);

	phalcon_is_iterable(rows, &ah1, &hp1, 0, 0);

	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
		PHALCON_GET_HKEY(index, ah1, hp1);
		PHALCON_GET_HVALUE(row);

		PHALCON_INIT_NVAR(keys);
		array_init(keys);		

		phalcon_is_iterable(columns, &ah2, &hp2, 0, 0);

		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
			PHALCON_GET_HKEY(index2, ah2, hp2);
			PHALCON_GET_HVALUE(column);

			if (phalcon_array_isset(row, column)) {
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch(&value, row, column, PH_NOISY);
			} else if (phalcon_array_isset(row, index2)) {
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch(&value, row, index2, PH_NOISY);
			} else {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Values can't find column '", column, "' value");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}

			PHALCON_INIT_NVAR(key);
			PHALCON_CONCAT_VV(key, column, index);
			phalcon_array_update_zval(&bind_params, key, value, PH_COPY);

			PHALCON_CONCAT_SVVS(key, ":", column, index, ":");
			phalcon_array_append(&keys, key, PH_COPY);

			zend_hash_move_forward_ex(ah2, &hp2);
		}

		PHALCON_INIT_NVAR(joined_keys);
		phalcon_fast_join_str(joined_keys, SL(", "), keys TSRMLS_CC);

		PHALCON_INIT_NVAR(insert_sql);
		PHALCON_SCONCAT_SVS(insert_sql, "(", joined_keys, ")");

		phalcon_array_append(&insert_sqls, insert_sql, PH_COPY);

		zend_hash_move_forward_ex(ah1, &hp1);
	}

	PHALCON_CALL_SELF(NULL, "bind", bind_params);

	PHALCON_INIT_VAR(joined_insert_sqls);
	phalcon_fast_join_str(joined_insert_sqls, SL(", "), insert_sqls TSRMLS_CC);

	PHALCON_SCONCAT_SV(phql, " VALUES ", joined_insert_sqls);

	RETURN_CTOR(phql);
}

/**
 * Returns a PHQL statement built with the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, _generateUpdate){

	zval *dependency_injector = NULL, *model, *conditions = NULL;
	zval *service_name, *meta_data = NULL, *model_instance;
	zval *no_primary = NULL, *primary_keys = NULL, *first_primary_key;
	zval *column_map = NULL, *attribute_field = NULL, *exception_message;
	zval *primary_key_condition, *phql, *columns;
	zval *updated_columns, *bind_params, *column = NULL, *value = NULL, *updated_column = NULL, *joined_columns = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		dependency_injector = NULL;
		PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	model = phalcon_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(model)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
		return;
	}
	
	PHALCON_OBS_VAR(conditions);
	phalcon_read_property_this(&conditions, this_ptr, SL("_conditions"), PH_NOISY TSRMLS_CC);
	if (phalcon_is_numeric(conditions)) {
	
		/** 
		 * If the conditions is a single numeric field. We internally create a condition
		 * using the related primary key
		 */
		PHALCON_INIT_VAR(service_name);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service_name, phalcon_interned_modelsMetadata);
	
		/** 
		 * Get the models metadata service to obtain the column names, column map and
		 * primary key
		 */
		PHALCON_CALL_METHOD(&meta_data, dependency_injector, "getshared", service_name);
		PHALCON_VERIFY_INTERFACE(meta_data, phalcon_mvc_model_metadatainterface_ce);
		ce0 = phalcon_fetch_class(model TSRMLS_CC);
	
		PHALCON_INIT_VAR(model_instance);
		object_init_ex(model_instance, ce0);
		if (phalcon_has_constructor(model_instance TSRMLS_CC)) {
			PHALCON_CALL_METHOD(NULL, model_instance, "__construct", dependency_injector);
		}
	
		PHALCON_INIT_VAR(no_primary);
		ZVAL_TRUE(no_primary);
	
		PHALCON_CALL_METHOD(&primary_keys, meta_data, "getprimarykeyattributes", model_instance);
		if (phalcon_fast_count_ev(primary_keys TSRMLS_CC)) {
			if (phalcon_array_isset_long(primary_keys, 0)) {
	
				PHALCON_OBS_VAR(first_primary_key);
				phalcon_array_fetch_long(&first_primary_key, primary_keys, 0, PH_NOISY);
	
				/** 
				 * The PHQL contains the renamed columns if available
				 */
				if (PHALCON_GLOBAL(orm).column_renaming) {
					PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", model_instance);
				} else {
					PHALCON_INIT_VAR(column_map);
				}
	
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
					if (phalcon_array_isset(column_map, first_primary_key)) {
						PHALCON_OBS_VAR(attribute_field);
						phalcon_array_fetch(&attribute_field, column_map, first_primary_key, PH_NOISY);
					} else {
						PHALCON_INIT_VAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", first_primary_key, "\" isn't part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_CPY_WRT(attribute_field, first_primary_key);
				}
	
				PHALCON_INIT_VAR(primary_key_condition);
				PHALCON_CONCAT_SVSVSV(primary_key_condition, "[", model, "].[", attribute_field, "] = ", conditions);
				PHALCON_CPY_WRT(conditions, primary_key_condition);
	
				ZVAL_FALSE(no_primary);
			}
		}
	
		/** 
		 * A primary key is mandatory in these cases
		 */
		if (PHALCON_IS_TRUE(no_primary)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined");
			return;
		}
	}
	
	PHALCON_INIT_VAR(phql);
	PHALCON_CONCAT_SVS(phql, "UPDATE [", model, "] SET ");
	
	PHALCON_OBS_VAR(columns);
	phalcon_read_property_this(&columns, this_ptr, SL("_columns"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(updated_columns);
	array_init(updated_columns);

	PHALCON_INIT_VAR(bind_params);
	array_init(bind_params);

	phalcon_is_iterable(columns, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		PHALCON_GET_HKEY(column, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		PHALCON_INIT_NVAR(updated_column);
		PHALCON_CONCAT_VSVS(updated_column, column, "=:", column, ":");
		phalcon_array_append(&updated_columns, updated_column, PH_COPY);

		phalcon_array_update_zval(&bind_params, column, value, PH_COPY);

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_CALL_SELF(NULL, "bind", bind_params);

	PHALCON_INIT_VAR(joined_columns);
	phalcon_fast_join_str(joined_columns, SL(", "), updated_columns TSRMLS_CC);
	phalcon_concat_self(&phql, joined_columns TSRMLS_CC);
	
	/** 
	 * Only append conditions if it's string
	 */
	if (Z_TYPE_P(conditions) == IS_STRING) {
		if (PHALCON_IS_NOT_EMPTY(conditions)) {
			PHALCON_SCONCAT_SV(phql, " WHERE ", conditions);
		}
	}
	
	RETURN_CTOR(phql);
}

/**
 * Returns a PHQL statement built with the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, _generateDelete){

	zval *dependency_injector = NULL, *model, *conditions = NULL;
	zval *service_name, *meta_data = NULL, *model_instance;
	zval *no_primary = NULL, *primary_keys = NULL, *first_primary_key;
	zval *column_map = NULL, *attribute_field = NULL, *exception_message;
	zval *primary_key_condition, *phql;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		dependency_injector = NULL;
		PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
		phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	
	model = phalcon_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(model)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
		return;
	}
	
	PHALCON_OBS_VAR(conditions);
	phalcon_read_property_this(&conditions, this_ptr, SL("_conditions"), PH_NOISY TSRMLS_CC);
	if (phalcon_is_numeric(conditions)) {
	
		/** 
		 * If the conditions is a single numeric field. We internally create a condition
		 * using the related primary key
		 */
		PHALCON_INIT_VAR(service_name);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service_name, phalcon_interned_modelsMetadata);
	
		/** 
		 * Get the models metadata service to obtain the column names, column map and
		 * primary key
		 */
		PHALCON_CALL_METHOD(&meta_data, dependency_injector, "getshared", service_name);
		PHALCON_VERIFY_INTERFACE(meta_data, phalcon_mvc_model_metadatainterface_ce);
		ce0 = phalcon_fetch_class(model TSRMLS_CC);
	
		PHALCON_INIT_VAR(model_instance);
		object_init_ex(model_instance, ce0);
		if (phalcon_has_constructor(model_instance TSRMLS_CC)) {
			PHALCON_CALL_METHOD(NULL, model_instance, "__construct", dependency_injector);
		}
	
		PHALCON_INIT_VAR(no_primary);
		ZVAL_TRUE(no_primary);
	
		PHALCON_CALL_METHOD(&primary_keys, meta_data, "getprimarykeyattributes", model_instance);
		if (phalcon_fast_count_ev(primary_keys TSRMLS_CC)) {
			if (phalcon_array_isset_long(primary_keys, 0)) {
	
				PHALCON_OBS_VAR(first_primary_key);
				phalcon_array_fetch_long(&first_primary_key, primary_keys, 0, PH_NOISY);
	
				/** 
				 * The PHQL contains the renamed columns if available
				 */
				if (PHALCON_GLOBAL(orm).column_renaming) {
					PHALCON_CALL_METHOD(&column_map, meta_data, "getcolumnmap", model_instance);
				} else {
					PHALCON_INIT_VAR(column_map);
				}
	
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
					if (phalcon_array_isset(column_map, first_primary_key)) {
						PHALCON_OBS_VAR(attribute_field);
						phalcon_array_fetch(&attribute_field, column_map, first_primary_key, PH_NOISY);
					} else {
						PHALCON_INIT_VAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", first_primary_key, "\" isn't part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_CPY_WRT(attribute_field, first_primary_key);
				}
	
				PHALCON_INIT_VAR(primary_key_condition);
				PHALCON_CONCAT_SVSVSV(primary_key_condition, "[", model, "].[", attribute_field, "] = ", conditions);
				PHALCON_CPY_WRT(conditions, primary_key_condition);
	
				ZVAL_FALSE(no_primary);
			}
		}
	
		/** 
		 * A primary key is mandatory in these cases
		 */
		if (PHALCON_IS_TRUE(no_primary)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined");
			return;
		}
	}
	
	PHALCON_INIT_VAR(phql);
	PHALCON_CONCAT_SVS(phql, " DELETE FROM [", model, "]");
	
	/** 
	 * Only append conditions if it's string
	 */
	if (Z_TYPE_P(conditions) == IS_STRING) {
		if (PHALCON_IS_NOT_EMPTY(conditions)) {
			PHALCON_SCONCAT_SV(phql, " WHERE ", conditions);
		}
	}
	
	RETURN_CTOR(phql);
}
