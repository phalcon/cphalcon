
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

#include "mvc/model/query/builderinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_model_query_builderinterface_ce;

static const zend_function_entry phalcon_mvc_model_query_builderinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, distinct, arginfo_phalcon_mvc_model_query_builderinterface_distinct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getDistinct, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, columns, arginfo_phalcon_mvc_model_query_builderinterface_columns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, from, arginfo_phalcon_mvc_model_query_builderinterface_from)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom, arginfo_phalcon_mvc_model_query_builderinterface_addfrom)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, join, arginfo_phalcon_mvc_model_query_builderinterface_join)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, innerJoin, arginfo_phalcon_mvc_model_query_builderinterface_innerjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, leftJoin, arginfo_phalcon_mvc_model_query_builderinterface_leftjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, rightJoin, arginfo_phalcon_mvc_model_query_builderinterface_rightjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, where, arginfo_phalcon_mvc_model_query_builderinterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere, arginfo_phalcon_mvc_model_query_builderinterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere, arginfo_phalcon_mvc_model_query_builderinterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, notBetweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, inWhere, arginfo_phalcon_mvc_model_query_builderinterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, notInWhere, arginfo_phalcon_mvc_model_query_builderinterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy, arginfo_phalcon_mvc_model_query_builderinterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, having, arginfo_phalcon_mvc_model_query_builderinterface_having)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, limit, arginfo_phalcon_mvc_model_query_builderinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy, arginfo_phalcon_mvc_model_query_builderinterface_groupby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Query\BuilderInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Query, BuilderInterface, mvc_model_query_builderinterface, phalcon_mvc_model_query_builderinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the columns to be queried
 *
 * @param string|array $columns
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, columns);

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns);

/**
 * Sets the models who makes part of the query
 *
 * @param string|array $models
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, from);

/**
 * Add a model to take part of the query
 *
 * @param string $model
 * @param string $alias
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom);

/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom);

/**
 * Adds a INNER join to the query
 *
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, join);

/**
 * Adds a INNER join to the query
 *
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @param string $type
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, innerJoin);

/**
 * Adds a LEFT join to the query
 *
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, leftJoin);

/**
 * Adds a RIGHT join to the query
 *
 * @param string $model
 * @param string $conditions
 * @param string $alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, rightJoin);

/**
 * Sets conditions for the query
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, where);

/**
 * Appends a condition to the current conditions using a AND operator
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere);

/**
 * Appends a condition to the current conditions using a OR operator
 *
 * @param string $conditions
 * @param array $bindParams
 * @param array $bindTypes
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere);

/**
 * Appends a BETWEEN condition to the current conditions
 *
 * @param string $expr
 * @param mixed $minimum
 * @param mixed $maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere);

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 *<code>
 *	$builder->notBetweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string $expr
 * @param mixed $minimum
 * @param mixed $maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, notBetweenWhere);

/**
 * Appends an IN condition to the current conditions
 *
 * @param string $expr
 * @param array $values
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, inWhere);

/**
 * Appends a NOT IN condition to the current conditions
 *
 * @param string $expr
 * @param array $values
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, notInWhere);

/**
 * Return the conditions for the query
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere);

/**
 * Sets a ORDER BY condition clause
 *
 * @param string $orderBy
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy);

/**
 * Return the set ORDER BY clause
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy);

/**
 * Sets a HAVING condition clause
 *
 * @param string $having
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, having);

/**
 * Returns the HAVING condition clause
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving);

/**
 * Sets a LIMIT clause
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, limit);

/**
 * Returns the current LIMIT clause
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit);

/**
 * Sets a LIMIT clause
 *
 * @param string $group
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy);

/**
 * Returns the GROUP BY clause
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy);

/**
 * Returns a PHQL statement built based on the builder parameters
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql);

/**
 * Returns the query built
 *
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery);
