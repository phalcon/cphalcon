
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query;

use Phalcon\Mvc\Model\QueryInterface;

/**
 * Phalcon\Mvc\Model\Query\BuilderInterface
 *
 * Interface for Phalcon\Mvc\Model\Query\Builder
 */
interface BuilderInterface
{
    const OPERATOR_AND = "and";
    const OPERATOR_OR = "or";

    /**
     * Add a model to take part of the query
     */
    public function addFrom(string model, string alias = null) -> <BuilderInterface>;

    /**
     * Appends a condition to the current conditions using a AND operator
     */
    public function andWhere(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>;

    /**
     * Appends a BETWEEN condition to the current conditions
     *
     * @param mixed minimum
     * @param mixed maximum
     */
    public function betweenWhere(string! expr, minimum, maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>;

    /**
     * Sets the columns to be queried
     *
     * @param string|array columns
     */
    public function columns(columns) -> <BuilderInterface>;

    /**
     * Sets SELECT DISTINCT / SELECT ALL flag
     *
     *```php
     * $builder->distinct("status");
     * $builder->distinct(null);
     *```
     */
    public function distinct(var distinct) -> <BuilderInterface>;

    /**
     * Sets a FOR UPDATE clause
     *
     *```php
     * $builder->forUpdate(true);
     *```
     */
    public function forUpdate(bool forUpdate) -> <BuilderInterface>;

    /**
     * Sets the models who makes part of the query
     *
     * @param string|array models
     */
    public function from(models) -> <BuilderInterface>;

    /**
     * Returns default bind params
     */
    public function getBindParams() -> array;

    /**
     * Returns default bind types
     */
    public function getBindTypes() -> array;

    /**
     * Return the columns to be queried
     *
     * @return string|array
     */
    public function getColumns();

    /**
     * Returns SELECT DISTINCT / SELECT ALL flag
     */
    public function getDistinct() -> bool;

    /**
     * Return the models who makes part of the query
     *
     * @return string|array
     */
    public function getFrom();

    /**
     * Returns the GROUP BY clause
     */
    public function getGroupBy() -> array;

    /**
     * Returns the HAVING condition clause
     */
    public function getHaving() -> string;

    /**
     * Return join parts of the query
     */
    public function getJoins() -> array;

    /**
     * Returns the current LIMIT clause
     *
     * @return string|array
     */
    public function getLimit();

    /**
     * Returns the current OFFSET clause
     */
    public function getOffset() -> int;

    /**
     * Return the set ORDER BY clause
     *
     * @return string|array
     */
    public function getOrderBy();

    /**
     * Returns a PHQL statement built based on the builder parameters
     */
    public function getPhql() -> string;

    /**
     * Returns the query built
     */
    public function getQuery() -> <QueryInterface>;

    /**
     * Return the conditions for the query
     *
     * @return string|array
     */
    public function getWhere();

    /**
     * Sets a GROUP BY clause
     *
     * @param string|array group
     */
    public function groupBy(var group) -> <BuilderInterface>;

    /**
     * Sets a HAVING condition clause
     */
    public function having(string having) -> <BuilderInterface>;

    /**
     * Adds an INNER join to the query
     */
    public function innerJoin(string model, string conditions = null, string alias = null) -> <BuilderInterface>;

    /**
     * Appends an IN condition to the current conditions
     */
    public function inWhere(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>;

    /**
     * Adds an :type: join (by default type - INNER) to the query
     *
     * @param string model
     * @param string conditions
     * @param string alias
     * @return BuilderInterface
     */
    public function join(string model, string conditions = null, string alias = null) -> <BuilderInterface>;

    /**
     * Adds a LEFT join to the query
     */
    public function leftJoin(string model, string conditions = null, string alias = null) -> <BuilderInterface>;

    /**
     * Sets a LIMIT clause
     *
     * @param int offset
     */
    public function limit(int limit, offset = null) -> <BuilderInterface>;

    /**
     * Returns the models involved in the query
     */
    public function getModels() -> string | array | null;

    /**
     * Appends a NOT BETWEEN condition to the current conditions
     *
     * @param mixed minimum
     * @param mixed maximum
     */
    public function notBetweenWhere(string! expr, minimum, maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>;

    /**
     * Appends a NOT IN condition to the current conditions
     */
    public function notInWhere(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>;

    /**
     * Sets an OFFSET clause
     */
    public function offset(int offset) -> <BuilderInterface>;

    /**
     * Sets an ORDER BY condition clause
     */
    public function orderBy(var orderBy) -> <BuilderInterface>;

    /**
     * Appends a condition to the current conditions using an OR operator
     */
    public function orWhere(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>;

    /**
     * Adds a RIGHT join to the query
     */
    public function rightJoin(string model, string conditions = null, string alias = null) -> <BuilderInterface>;

    /**
     * Set default bind parameters
     */
    public function setBindParams(array! bindParams, bool merge = false) -> <BuilderInterface>;

    /**
     * Set default bind types
     */
    public function setBindTypes(array! bindTypes, bool merge = false) -> <BuilderInterface>;

    /**
     * Sets conditions for the query
     */
    public function where(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>;
}
