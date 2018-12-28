
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\DiInterface;

/**
 * Phalcon\Mvc\Model\CriteriaInterface
 *
 * Interface for Phalcon\Mvc\Model\Criteria
 */
interface CriteriaInterface
{

	/**
	 * Set a model on which the query will be executed
	 */
	public function setModelName(string! modelName) -> <CriteriaInterface>;

	/**
	 * Returns an internal model name on which the criteria will be applied
	 */
	public function getModelName() -> string;

	/**
	 * Sets the bound parameters in the criteria
	 * This method replaces all previously set bound parameters
	 */
	public function bind(array! bindParams) -> <CriteriaInterface>;

	/**
	 * Sets the bind types in the criteria
	 * This method replaces all previously set bound parameters
	 */
	public function bindTypes(array! bindTypes) -> <CriteriaInterface>;

	/**
	 * Sets the conditions parameter in the criteria
	 */
	public function where(string! conditions) -> <CriteriaInterface>;

	/**
	 * Adds the conditions parameter to the criteria
	 */
	public function conditions(string! conditions) -> <CriteriaInterface>;

	/**
	 * Adds the order-by parameter to the criteria
	 */
	public function orderBy(string! orderColumns) -> <CriteriaInterface>;

	/**
	 * Sets the limit parameter to the criteria
	 *
	 * @param int offset
	 */
	public function limit(int limit, offset = null) -> <CriteriaInterface>;

	/**
	 * Sets the "for_update" parameter to the criteria
	 */
	public function forUpdate(bool forUpdate = true) -> <CriteriaInterface>;

	/**
	 * Sets the "shared_lock" parameter to the criteria
	 */
	public function sharedLock(bool sharedLock = true) -> <CriteriaInterface>;

	/**
	 * Appends a condition to the current conditions using an AND operator
	 *
	 * @param array bindParams
	 * @param array bindTypes
	 */
	public function andWhere(string! conditions, bindParams = null, bindTypes = null) -> <CriteriaInterface>;

	/**
	 * Appends a condition to the current conditions using an OR operator
	 *
	 * @param array bindParams
	 * @param array bindTypes
	 */
	public function orWhere(string! conditions, bindParams = null, bindTypes = null) -> <CriteriaInterface>;

	/**
	 * Appends a BETWEEN condition to the current conditions
	 *
	 *<code>
	 * $criteria->betweenWhere("price", 100.25, 200.50);
	 *</code>
	 *
	 * @param mixed minimum
	 * @param mixed maximum
	 */
	public function betweenWhere(string! expr, minimum, maximum) -> <CriteriaInterface>;

	/**
	 * Appends a NOT BETWEEN condition to the current conditions
	 *
	 *<code>
	 * $criteria->notBetweenWhere("price", 100.25, 200.50);
	 *</code>
	 *
	 * @param mixed minimum
	 * @param mixed maximum
	 */
	public function notBetweenWhere(string! expr, minimum, maximum) -> <CriteriaInterface>;

	/**
	 * Appends an IN condition to the current conditions
	 *
	 *<code>
	 * $criteria->inWhere("id", [1, 2, 3]);
	 *</code>
	 */
	public function inWhere(string! expr, array! values) -> <CriteriaInterface>;

	/**
	 * Appends a NOT IN condition to the current conditions
	 *
	 *<code>
	 * $criteria->notInWhere("id", [1, 2, 3]);
	 *</code>
	 */
	public function notInWhere(string! expr, array! values) -> <CriteriaInterface>;

	/**
	 * Returns the conditions parameter in the criteria
	 *
	 * @return string|null
	 */
	public function getWhere();

	/**
	 * Returns the conditions parameter in the criteria
	 *
	 * @return string|null
	 */
	public function getConditions();

	/**
	 * Returns the limit parameter in the criteria, which will be
	 * an integer if limit was set without an offset,
	 * an array with 'number' and 'offset' keys if an offset was set with the limit,
	 * or null if limit has not been set.
	 *
	 * @return int|array|null
	 */
	public function getLimit();

	/**
	 * Returns the order parameter in the criteria
	 *
	 * @return string|null
	 */
	public function getOrderBy();

	/**
	 * Returns all the parameters defined in the criteria
	 */
	public function getParams() -> array;

	/**
	 * Executes a find using the parameters built with the criteria
	 */
	public function execute() -> <ResultsetInterface>;

	/**
	 * Sets SELECT DISTINCT / SELECT ALL flag
	 */
	 public function distinct(var distinct) -> <CriteriaInterface>;

	/**
	 * Adds an INNER join to the query
	 *
	 *<code>
	 * $criteria->innerJoin("Robots");
	 * $criteria->innerJoin("Robots", "r.id = RobotsParts.robots_id");
	 * $criteria->innerJoin("Robots", "r.id = RobotsParts.robots_id", "r");
	 *</code>
	 */
	public function innerJoin(string! model, var conditions = null, var alias = null) -> <CriteriaInterface>;

	/**
	 * Adds a LEFT join to the query
	 *
	 *<code>
	 * $criteria->leftJoin("Robots", "r.id = RobotsParts.robots_id", "r");
	 *</code>
	 */
	public function leftJoin(string! model, var conditions = null, var alias = null) -> <CriteriaInterface>;

	/**
	 * Adds a RIGHT join to the query
	 *
	 *<code>
	 * $criteria->rightJoin("Robots", "r.id = RobotsParts.robots_id", "r");
	 *</code>
	 */
	public function rightJoin(string! model, conditions = null, alias = null) -> <CriteriaInterface>;

	/**
	 * Adds the group-by clause to the criteria
	 */
	public function groupBy(var group) -> <CriteriaInterface>;

	/**
	 * Adds the having clause to the criteria
	 */
	public function having(var having) -> <CriteriaInterface>;

	/**
	 * Sets the cache options in the criteria
	 * This method replaces all previously set cache options
	 */
	public function cache(array! cache) -> <CriteriaInterface>;

	/**
	 * Returns the columns to be queried
	 *
	 * @return string|array|null
	 */
	public function getColumns() -> string | null;

	/**
	 * Returns the group clause in the criteria
	 */
	public function getGroupBy();

	/**
	 * Returns the having clause in the criteria
	 */
	public function getHaving();
}
