
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Query\BuilderInterface
 *
 * Interface for Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Query, BuilderInterface, phalcon, mvc_model_query_builderinterface, phalcon_mvc_model_query_builderinterface_method_entry);

	zephir_declare_class_constant_string(phalcon_mvc_model_query_builderinterface_ce, SL("OPERATOR_OR"), "or");

	zephir_declare_class_constant_string(phalcon_mvc_model_query_builderinterface_ce, SL("OPERATOR_AND"), "and");

	return SUCCESS;

}

/**
 * Sets the columns to be queried
 *
 * @param string|array columns
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, from);

/**
 * Add a model to take part of the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom);

/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom);

/**
 * Adds an :type: join (by default type - INNER) to the query
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @param string type
 * @return \Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, join);

/**
 * Adds an INNER join to the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, innerJoin);

/**
 * Adds a LEFT join to the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, leftJoin);

/**
 * Adds a RIGHT join to the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, rightJoin);

/**
 * Return join parts of the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getJoins);

/**
 * Sets conditions for the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, where);

/**
 * Appends a condition to the current conditions using a AND operator
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere);

/**
 * Appends a condition to the current conditions using an OR operator
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere);

/**
 * Appends a BETWEEN condition to the current conditions
 *
 * @param mixed minimum
 * @param mixed maximum
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere);

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 * @param mixed minimum
 * @param mixed maximum
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
 * Sets an ORDER BY condition clause
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, having);

/**
 * Returns the HAVING condition clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving);

/**
 * Sets a LIMIT clause
 *
 * @param int offset
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy);

/**
 * Returns the GROUP BY clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy);

/**
 * Returns a PHQL statement built based on the builder parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql);

/**
 * Returns the query built
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery);

/**
 * Sets an OFFSET clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, offset);

/**
 * Set default bind parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, setBindParams);

/**
 * Set default bind types
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, setBindTypes);

/**
 * Returns default bind params
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getBindParams);

/**
 * Returns default bind types
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getBindTypes);

/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 *
 *<code>
 * $builder->distinct("status");
 * $builder->distinct(null);
 *</code>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, distinct);

/**
 * Returns SELECT DISTINCT / SELECT ALL flag
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getDistinct);

/**
 * Sets a FOR UPDATE clause
 *
 *<code>
 * $builder->forUpdate(true);
 *</code>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, forUpdate);

/**
 * Returns the current OFFSET clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getOffset);

