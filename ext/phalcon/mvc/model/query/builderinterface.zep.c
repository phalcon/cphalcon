
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Query\BuilderInterface
 *
 * Interface for Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Query, BuilderInterface, phalcon, mvc_model_query_builderinterface, phalcon_mvc_model_query_builderinterface_method_entry);

	zephir_declare_class_constant_string(phalcon_mvc_model_query_builderinterface_ce, SL("OPERATOR_AND"), "and");

	zephir_declare_class_constant_string(phalcon_mvc_model_query_builderinterface_ce, SL("OPERATOR_OR"), "or");

	return SUCCESS;
}

/**
 * Add a model to take part of the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom);
/**
 * Appends a condition to the current conditions using a AND operator
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere);
/**
 * Appends a BETWEEN condition to the current conditions
 *
 * @param mixed minimum
 * @param mixed maximum
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere);
/**
 * Sets the columns to be queried. The columns can be either a `string` or
 * an `array` of strings. If the argument is a (single, non-embedded) string,
 * its content can specify one or more columns, separated by commas, the same
 * way that one uses the SQL select statement. You can use aliases, aggregate
 * functions, etc. If you need to reference other models you will need to
 * reference them with their namespaces.
 *
 * When using an array as a parameter, you will need to specify one field
 * per array element. If a non-numeric key is defined in the array, it will
 * be used as the alias in the query
 *
 *```php
 * <?php
 *
 * // String, comma separated values
 * $builder->columns("id, name");
 *
 * // Array, one column per element
 * $builder->columns(
 *     [
 *         "id",
 *         "name",
 *     ]
 * );
 *
 * // Array, named keys. The name of the key acts as an alias (`AS` clause)
 * $builder->columns(
 *     [
 *         "name",
 *         "number" => "COUNT(*)",
 *     ]
 * );
 *
 * // Different models
 * $builder->columns(
 *     [
 *         "\Phalcon\Models\Invoices.*",
 *         "\Phalcon\Models\Customers.cst_name_first",
 *         "\Phalcon\Models\Customers.cst_name_last",
 *     ]
 * );
 *```
 *
 * @param string|array $columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, columns);
/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 *
 *```php
 * $builder->distinct("status");
 * $builder->distinct(null);
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, distinct);
/**
 * Sets a FOR UPDATE clause
 *
 *```php
 * $builder->forUpdate(true);
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, forUpdate);
/**
 * Sets the models who makes part of the query
 *
 * @param string|array models
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, from);
/**
 * Returns default bind params
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getBindParams);
/**
 * Returns default bind types
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getBindTypes);
/**
 * Return the columns to be queried
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns);
/**
 * Returns SELECT DISTINCT / SELECT ALL flag
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getDistinct);
/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom);
/**
 * Returns the GROUP BY clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy);
/**
 * Returns the HAVING condition clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving);
/**
 * Return join parts of the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getJoins);
/**
 * Returns the current LIMIT clause
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit);
/**
 * Returns the current OFFSET clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getOffset);
/**
 * Return the set ORDER BY clause
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy);
/**
 * Returns a PHQL statement built based on the builder parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql);
/**
 * Returns the query built
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery);
/**
 * Return the conditions for the query
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere);
/**
 * Sets a GROUP BY clause
 *
 * @param string|array group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy);
/**
 * Sets a HAVING condition clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, having);
/**
 * Adds an INNER join to the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, innerJoin);
/**
 * Appends an IN condition to the current conditions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, inWhere);
/**
 * Adds an :type: join (by default type - INNER) to the query
 *
 * @param string model
 * @param string conditions
 * @param string alias
 * @return BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, join);
/**
 * Adds a LEFT join to the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, leftJoin);
/**
 * Sets a LIMIT clause
 *
 * @param int offset
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, limit);
/**
 * Returns the models involved in the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, getModels);
/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 * @param mixed minimum
 * @param mixed maximum
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, notBetweenWhere);
/**
 * Appends a NOT IN condition to the current conditions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, notInWhere);
/**
 * Sets an OFFSET clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, offset);
/**
 * Sets an ORDER BY condition clause
 *
 * @param array|string orderBy
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy);
/**
 * Appends a condition to the current conditions using an OR operator
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere);
/**
 * Adds a RIGHT join to the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, rightJoin);
/**
 * Set default bind parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, setBindParams);
/**
 * Set default bind types
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, setBindTypes);
/**
 * Sets conditions for the query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_BuilderInterface, where);
