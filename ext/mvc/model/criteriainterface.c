
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

#include "mvc/model/criteriainterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_model_criteriainterface_ce;

static const zend_function_entry phalcon_mvc_model_criteriainterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, setModelName, arginfo_phalcon_mvc_model_criteriainterface_setmodelname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getModelName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bind, arginfo_phalcon_mvc_model_criteriainterface_bind)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bindTypes, arginfo_phalcon_mvc_model_criteriainterface_bindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, columns, arginfo_phalcon_mvc_model_criteriainterface_columns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, join, arginfo_phalcon_mvc_model_criteriainterface_join)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, where, arginfo_phalcon_mvc_model_criteriainterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, conditions, arginfo_phalcon_mvc_model_criteriainterface_conditions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orderBy, arginfo_phalcon_mvc_model_criteriainterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, limit, arginfo_phalcon_mvc_model_criteriainterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, forUpdate, arginfo_phalcon_mvc_model_criteriainterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, sharedLock, arginfo_phalcon_mvc_model_criteriainterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, andWhere, arginfo_phalcon_mvc_model_criteriainterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orWhere, arginfo_phalcon_mvc_model_criteriainterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere, arginfo_phalcon_mvc_model_criteriainterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere, arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, inWhere, arginfo_phalcon_mvc_model_criteriainterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notInWhere, arginfo_phalcon_mvc_model_criteriainterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getConditions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getOrder, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getParams, NULL)
	ZEND_FENTRY(fromInput, NULL, arginfo_phalcon_mvc_model_criteriainterface_frominput, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, execute, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\CriteriaInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, CriteriaInterface, mvc_model_criteriainterface, phalcon_mvc_model_criteriainterface_method_entry);

	return SUCCESS;
}

/**
 * Set a model on which the query will be executed
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, setModelName);

/**
 * Returns an internal model name on which the criteria will be applied
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getModelName);

/**
 * Adds the bind parameter to the criteria
 *
 * @param string $bindParams
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bind);

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 *
 * @param string $bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bindTypes);

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, where);

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, conditions);

/**
 * Adds the order-by parameter to the criteria
 *
 * @param string $orderColumns
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, orderBy);

/**
 * Sets the limit parameter to the criteria
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, limit);

/**
 * Sets the "for_update" parameter to the criteria
 *
 * @param boolean $forUpdate
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, forUpdate);

/**
 * Sets the "shared_lock" parameter to the criteria
 *
 * @param boolean $sharedLock
 * @return Phalcon\Mvc\Model\Criteria
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, sharedLock);

/**
 * Appends a condition to the current conditions using an AND operator
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, andWhere);

/**
 * Appends a condition to the current conditions using an OR operator
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, orWhere);

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
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere);

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
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere);

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
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, inWhere);

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
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, notInWhere);

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getWhere);

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getConditions);

/**
 * Returns the limit parameter in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getLimit);

/**
 * Returns the order parameter in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getOrder);

/**
 * Returns all the parameters defined in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getParams);

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param string $modelName
 * @param array $data
 * @return static
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, fromInput);

/**
 * Executes a find using the parameters built with the criteria
 *
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, execute);

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
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, columns);

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
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, join)
