
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\Query\BuilderInterface
 *
 * Interface for Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Query, BuilderInterface, phalcon, mvc_model_query_builderinterface, phalcon_mvc_model_query_builderinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * @param array params
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, __construct);

/**
 * Sets the columns to be queried
 *
 * @param string|array columns
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, columns);

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns);

/**
 * Sets the models who makes part of the query
 *
 * @param string|array models
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, from);

/**
 * Add a model to take part of the query
 *
 * @param string model
 * @param string alias
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom);

/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom);

/**
 * Adds a INNER join to the query
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, join);

/**
 * Adds a INNER join to the query
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @param string type
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, innerJoin);

/**
 * Adds a LEFT join to the query
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, leftJoin);

/**
 * Adds a RIGHT join to the query
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, rightJoin);

/**
 * Sets conditions for the query
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, where);

/**
 * Appends a condition to the current conditions using a AND operator
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere);

/**
 * Appends a condition to the current conditions using a OR operator
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere);

/**
 * Appends a BETWEEN condition to the current conditions
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere);

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, notBetweenWhere);

/**
 * Appends an IN condition to the current conditions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, inWhere);

/**
 * Appends a NOT IN condition to the current conditions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, notInWhere);

/**
 * Return the conditions for the query
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere);

/**
 * Sets a ORDER BY condition clause
 *
 * @param string orderBy
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy);

/**
 * Return the set ORDER BY clause
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy);

/**
 * Sets a HAVING condition clause
 *
 * @param string having
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, having);

/**
 * Returns the HAVING condition clause
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving);

/**
 * Sets a LIMIT clause
 *
 * @param int limit
 * @param int offset
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, limit);

/**
 * Returns the current LIMIT clause
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit);

/**
 * Sets a LIMIT clause
 *
 * @param string group
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy);

/**
 * Returns the GROUP BY clause
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy);

/**
 * Returns a PHQL statement built based on the builder parameters
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql);

/**
 * Returns the query built
 *
 * @return Phalcon\Mvc\Model\QueryInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery);

