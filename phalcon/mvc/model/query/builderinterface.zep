/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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
	const OPERATOR_OR = "or";

	const OPERATOR_AND = "and";

	/**
	 * Sets the columns to be queried
	 *
	 * @param string|array columns
	 */
	public function columns(columns) -> <BuilderInterface>;

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
	 */
	public function from(models) -> <BuilderInterface>;

	/**
	 * Add a model to take part of the query
	 */
	public function addFrom(string model, string alias = null) -> <BuilderInterface>;

	/**
	 * Return the models who makes part of the query
	 *
	 * @return string|array
	 */
	public function getFrom();

	/**
	 * Adds an :type: join (by default type - INNER) to the query
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @param string type
	 * @return \Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function join(string model, string conditions = null, string alias = null) -> <BuilderInterface>;

	/**
	 * Adds an INNER join to the query
	 */
	public function innerJoin(string model, string conditions = null, string alias = null) -> <BuilderInterface>;

	/**
	 * Adds a LEFT join to the query
	 */
	public function leftJoin(string model, string conditions = null, string alias = null) -> <BuilderInterface>;

	/**
	 * Adds a RIGHT join to the query
	 */
	public function rightJoin(string model, string conditions = null, string alias = null) -> <BuilderInterface>;

	/**
	 * Return join parts of the query
	 */
	public function getJoins() -> array;

	/**
	 * Sets conditions for the query
	 */
	public function where(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>;

	/**
	 * Appends a condition to the current conditions using a AND operator
	 */
	public function andWhere(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>;

	/**
	 * Appends a condition to the current conditions using an OR operator
	 */
	public function orWhere(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>;

	/**
	 * Appends a BETWEEN condition to the current conditions
	 *
	 * @param mixed minimum
	 * @param mixed maximum
	 */
	public function betweenWhere(string! expr, minimum, maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>;

	/**
	 * Appends a NOT BETWEEN condition to the current conditions
	 *
	 * @param mixed minimum
	 * @param mixed maximum
	 */
	public function notBetweenWhere(string! expr, minimum, maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>;

	/**
	 * Appends an IN condition to the current conditions
	 */
	public function inWhere(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>;

	/**
	 * Appends a NOT IN condition to the current conditions
	 */
	public function notInWhere(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>;

	/**
	 * Return the conditions for the query
	 *
	 * @return string|array
	 */
	public function getWhere();

	/**
	 * Sets an ORDER BY condition clause
	 */
	public function orderBy(string orderBy) -> <BuilderInterface>;

	/**
	 * Return the set ORDER BY clause
	 *
	 * @return string|array
	 */
	public function getOrderBy();

	/**
	 * Sets a HAVING condition clause
	 */
	public function having(string having) -> <BuilderInterface>;

	/**
	 * Returns the HAVING condition clause
	 */
	public function getHaving() -> string;

	/**
	 * Sets a LIMIT clause
	 *
	 * @param int offset
	 */
	public function limit(int limit, offset = null) -> <BuilderInterface>;

	/**
	 * Returns the current LIMIT clause
	 *
	 * @return string|array
	 */
	public function getLimit();

	/**
	 * Sets a LIMIT clause
	 */
	public function groupBy(string group) -> <BuilderInterface>;

	/**
	 * Returns the GROUP BY clause
	 */
	public function getGroupBy() -> string;

	/**
	 * Returns a PHQL statement built based on the builder parameters
	 */
	public function getPhql() -> string;

	/**
	 * Returns the query built
	 */
	public function getQuery() -> <QueryInterface>;

	/**
	 * Sets an OFFSET clause
	 */
	 public function offset(int offset) -> <BuilderInterface>;

}
