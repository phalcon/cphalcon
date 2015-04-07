
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Mvc\Model\Query;

/**
 * Phalcon\Mvc\Model\Query\BuilderInterface
 *
 * Interface for Phalcon\Mvc\Model\Query\Builder
 */
interface BuilderInterface
{

	/**
	 * Phalcon\Mvc\Model\Query\Builder
	 *
	 * @param array params
	 */
	public function __construct(params = null);

	/**
	 * Sets the columns to be queried
	 *
	 * @param string|array columns
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function columns(columns);

	/**
	 * Return the columns to be queried
	 *
	 * @return string|array
	 */
	public function getColumns();

	/**
	 * Sets the models who makes part of the query
	 *
	 * @param string|array models
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function from(models);

	/**
	 * Add a model to take part of the query
	 *
	 * @param string model
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function addFrom(model, alias = null);

	/**
	 * Return the models who makes part of the query
	 *
	 * @return string|array
	 */
	public function getFrom();

	/**
	 * Adds a INNER join to the query
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function join(model, conditions = null, alias = null);

	/**
	 * Adds a INNER join to the query
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @param string type
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function innerJoin(model, conditions = null, alias = null);

	/**
	 * Adds a LEFT join to the query
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function leftJoin(model, conditions = null, alias = null);

	/**
	 * Adds a RIGHT join to the query
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function rightJoin(model, conditions = null, alias = null);

	/**
	 * Sets conditions for the query
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function where(conditions, bindParams = null, bindTypes = null);

	/**
	 * Appends a condition to the current conditions using a AND operator
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function andWhere(conditions, bindParams = null, bindTypes = null);

	/**
	 * Appends a condition to the current conditions using a OR operator
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function orWhere(conditions, bindParams = null, bindTypes = null);

	/**
	 * Appends a BETWEEN condition to the current conditions
	 *
	 * @param string expr
	 * @param mixed minimum
	 * @param mixed maximum
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function betweenWhere(expr, minimum, maximum);

	/**
	 * Appends a NOT BETWEEN condition to the current conditions
	 *
	 * @param string expr
	 * @param mixed minimum
	 * @param mixed maximum
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function notBetweenWhere(expr, minimum, maximum);

	/**
	 * Appends an IN condition to the current conditions
	 */
	public function inWhere(string! expr, array! values) -> <BuilderInterface>;

	/**
	 * Appends a NOT IN condition to the current conditions
	 */
	public function notInWhere(string! expr, array! values) -> <BuilderInterface>;

	/**
	 * Return the conditions for the query
	 *
	 * @return string|array
	 */
	public function getWhere();

	/**
	 * Sets a ORDER BY condition clause
	 *
	 * @param string orderBy
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function orderBy(orderBy);

	/**
	 * Return the set ORDER BY clause
	 *
	 * @return string|array
	 */
	public function getOrderBy();

	/**
	 * Sets a HAVING condition clause
	 *
	 * @param string having
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function having(having);

	/**
	 * Returns the HAVING condition clause
	 *
	 * @return string|array
	 */
	public function getHaving();

	/**
	 * Sets a LIMIT clause
	 *
	 * @param int limit
	 * @param int offset
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function limit(limit, offset = null);

	/**
	 * Returns the current LIMIT clause
	 *
	 * @return string|array
	 */
	public function getLimit();

	/**
	 * Sets a LIMIT clause
	 *
	 * @param string group
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function groupBy(group);

	/**
	 * Returns the GROUP BY clause
	 *
	 * @return string
	 */
	public function getGroupBy();

	/**
	 * Returns a PHQL statement built based on the builder parameters
	 *
	 * @return string
	 */
	public function getPhql();

	/**
	 * Returns the query built
	 *
	 * @return Phalcon\Mvc\Model\QueryInterface
	 */
	public function getQuery();

}
