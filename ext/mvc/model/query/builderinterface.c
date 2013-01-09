
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/main.h"

/**
 * Phalcon\Mvc\Model\Query\BuilderInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Query, BuilderInterface, mvc_model_query_builderinterface, phalcon_mvc_model_query_builderinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * @param array $params
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, __construct);

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
 * Sets conditions for the query
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, where);

/**
 * Appends a condition to the current conditions using a AND operator
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere);

/**
 * Appends a condition to the current conditions using a OR operator
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere);

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

