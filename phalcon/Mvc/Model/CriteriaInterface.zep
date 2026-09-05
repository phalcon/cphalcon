
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Contracts\Mvc\MvcTypes;
use Phalcon\Di\DiInterface;

/**
 * Phalcon\Mvc\Model\CriteriaInterface
 *
 * Interface for Phalcon\Mvc\Model\Criteria
 *
 * @phpstan-import-type mvc_model_bind_params from MvcTypes
 * @phpstan-import-type mvc_model_bind_types from MvcTypes
 * @phpstan-import-type mvc_model_cache_options from MvcTypes
 * @phpstan-import-type mvc_model_parameters from MvcTypes
 * @phpstan-import-type mvc_query_columns from MvcTypes
 */
interface CriteriaInterface
{
    /**
     * Appends a condition to the current conditions using an AND operator
     *
     * @param array bindParams
     * @param array bindTypes
     */
    public function andWhere(string conditions, bindParams = null, bindTypes = null) -> <CriteriaInterface>;

    /**
     * Appends a BETWEEN condition to the current conditions
     *
     *```php
     * $criteria->betweenWhere("price", 100.25, 200.50);
     *```
     *
     * @param mixed minimum
     * @param mixed maximum
     */
    public function betweenWhere(string expr, minimum, maximum) -> <CriteriaInterface>;

    /**
     * Sets the bound parameters in the criteria
     * This method replaces all previously set bound parameters
     *
     * @phpstan-param mvc_model_bind_params $bindParams
     */
    public function bind(array bindParams) -> <CriteriaInterface>;

    /**
     * Sets the bind types in the criteria
     * This method replaces all previously set bound parameters
     *
     * @phpstan-param mvc_model_bind_types $bindTypes
     */
    public function bindTypes(array bindTypes) -> <CriteriaInterface>;

    /**
     * Sets the cache options in the criteria
     * This method replaces all previously set cache options
     *
     * @phpstan-param mvc_model_cache_options $cache
     */
    public function cache(array cache) -> <CriteriaInterface>;

    /**
     * Adds the conditions parameter to the criteria
     */
    public function conditions(string conditions) -> <CriteriaInterface>;

    /**
     * Sets SELECT DISTINCT / SELECT ALL flag
     */
     public function distinct(var distinct) -> <CriteriaInterface>;

    /**
     * Executes a find using the parameters built with the criteria
     */
    public function execute() -> <ResultsetInterface>;

    /**
     * Sets the "for_update" parameter to the criteria
     */
    public function forUpdate(bool forUpdate = true) -> <CriteriaInterface>;

    /**
     * Returns the columns to be queried
     *
     * @phpstan-return mvc_query_columns|null
     */
    public function getColumns() -> string | array | null;

    /**
     * Returns the conditions parameter in the criteria
     */
    public function getConditions() -> string | null;

    /**
     * Returns the group clause in the criteria
     */
    public function getGroupBy();

    /**
     * Returns the having clause in the criteria
     */
    public function getHaving();

    /**
     * Returns the limit parameter in the criteria, which will be
     *
     * - An integer if 'limit' was set without an 'offset'
     * - An array with 'number' and 'offset' keys if an offset was set with the limit
     * - NULL if limit has not been set
     *
     * @phpstan-return array{number: int|string, offset?: int|string}|int|null
     */
    public function getLimit() -> int | array | null;

    /**
     * Returns an internal model name on which the criteria will be applied
     */
    public function getModelName() -> string;

    /**
     * Returns the order parameter in the criteria
     */
    public function getOrderBy() -> string | null;

    /**
     * Returns all the parameters defined in the criteria
     *
     * @phpstan-return mvc_model_parameters
     */
    public function getParams() -> array;

    /**
     * Returns the conditions parameter in the criteria
     */
    public function getWhere() -> string | null;

    /**
     * Adds the group-by clause to the criteria
     */
    public function groupBy(var group) -> <CriteriaInterface>;

    /**
     * Adds the having clause to the criteria
     */
    public function having(var having) -> <CriteriaInterface>;

    /**
     * Appends an IN condition to the current conditions
     *
     *```php
     * $criteria->inWhere("id", [1, 2, 3]);
     *```
     *
     * @phpstan-param array<array-key, mixed> $values
     */
    public function inWhere(string expr,  array values) -> <CriteriaInterface>;

    /**
     * Adds an INNER join to the query
     *
     *```php
     * $criteria->innerJoin(
     *     Orders::class
     * );
     *
     * $criteria->innerJoin(
     *     Orders::class,
     *     "r.ord_id = OrdersProducts.oxp_ord_id"
     * );
     *
     * $criteria->innerJoin(
     *     Orders::class,
     *     "r.ord_id = OrdersProducts.oxp_ord_id",
     *     "r"
     * );
     *```
     */
    public function innerJoin(string model, var conditions = null, var alias = null) -> <CriteriaInterface>;

    /**
     * Adds a LEFT join to the query
     *
     *```php
     * $criteria->leftJoin(
     *     Orders::class,
     *     "r.ord_id = OrdersProducts.oxp_ord_id",
     *     "r"
     * );
     *```
     */
    public function leftJoin(string model, var conditions = null, var alias = null) -> <CriteriaInterface>;

    /**
     * Sets the limit parameter to the criteria
     */
    public function limit(int limit, int offset = 0) -> <CriteriaInterface>;

    /**
     * Appends a NOT BETWEEN condition to the current conditions
     *
     *```php
     * $criteria->notBetweenWhere("price", 100.25, 200.50);
     *```
     *
     * @param mixed minimum
     * @param mixed maximum
     */
    public function notBetweenWhere(string expr, minimum, maximum) -> <CriteriaInterface>;

    /**
     * Appends a NOT IN condition to the current conditions
     *
     *```php
     * $criteria->notInWhere("id", [1, 2, 3]);
     *```
     *
     * @phpstan-param array<array-key, mixed> $values
     */
    public function notInWhere(string expr,  array values) -> <CriteriaInterface>;

    /**
     * Appends a condition to the current conditions using an OR operator
     *
     * @param array bindParams
     * @param array bindTypes
     */
    public function orWhere(string conditions, bindParams = null, bindTypes = null) -> <CriteriaInterface>;

    /**
     * Adds the order-by parameter to the criteria
     */
    public function orderBy(string orderColumns) -> <CriteriaInterface>;

    /**
     * Adds a RIGHT join to the query
     *
     *```php
     * $criteria->rightJoin(
     *     Orders::class,
     *     "r.ord_id = OrdersProducts.oxp_ord_id",
     *     "r"
     * );
     *```
     */
    public function rightJoin(string model, conditions = null, alias = null) -> <CriteriaInterface>;

    /**
     * Set a model on which the query will be executed
     */
    public function setModelName(string modelName) -> <CriteriaInterface>;

    /**
     * Sets the "shared_lock" parameter to the criteria
     */
    public function sharedLock(bool sharedLock = true) -> <CriteriaInterface>;

    /**
     * Sets the conditions parameter in the criteria
     */
    public function where(string conditions, var bindParams = null, var bindTypes = null) -> <CriteriaInterface>;
}
