
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Di;
use Phalcon\Db\Column;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\Query\BuilderInterface;

/**
 * Phalcon\Mvc\Model\Criteria
 *
 * This class is used to build the array parameter required by
 * Phalcon\Mvc\Model::find() and Phalcon\Mvc\Model::findFirst() using an
 * object-oriented interface.
 *
 * ```php
 * $robots = Robots::query()
 *     ->where("type = :type:")
 *     ->andWhere("year < 2000")
 *     ->bind(["type" => "mechanical"])
 *     ->limit(5, 10)
 *     ->orderBy("name")
 *     ->execute();
 * ```
 */
class Criteria implements CriteriaInterface, InjectionAwareInterface
{
    protected bindParams;

    protected bindTypes;

    protected hiddenParamNumber = 0;

    protected model;

    protected params = [];

    /**
     * Appends a condition to the current conditions using an AND operator
     */
    public function andWhere(string! conditions, var bindParams = null, var bindTypes = null) -> <CriteriaInterface>
    {
        var currentConditions;

        if fetch currentConditions, this->params["conditions"] {
            let conditions = "(" . currentConditions . ") AND (" . conditions . ")";
        }

        return this->where(conditions, bindParams, bindTypes);
    }

    /**
     * Appends a BETWEEN condition to the current conditions
     *
     *```php
     * $criteria->betweenWhere("price", 100.25, 200.50);
     *```
     */
    public function betweenWhere(string! expr, var minimum, var maximum) -> <CriteriaInterface>
    {
        var hiddenParam, minimumKey, nextHiddenParam, maximumKey;

        let hiddenParam = this->hiddenParamNumber,
            nextHiddenParam = hiddenParam + 1;

        /**
         * Minimum key with auto bind-params
         */
        let minimumKey = "ACP" . hiddenParam;

        /**
         * Maximum key with auto bind-params
         */
        let maximumKey = "ACP" . nextHiddenParam;

        /**
         * Create a standard BETWEEN condition with bind params
         * Append the BETWEEN to the current conditions using and "and"
         */
        this->andWhere(
            expr . " BETWEEN :" . minimumKey . ": AND :" . maximumKey . ":",
            [
                minimumKey: minimum,
                maximumKey: maximum
            ]
        );

        let nextHiddenParam++,
            this->hiddenParamNumber = nextHiddenParam;

        return this;
    }

    /**
     * Sets the bound parameters in the criteria
     * This method replaces all previously set bound parameters
     */
    public function bind(array! bindParams, bool merge = false) -> <CriteriaInterface>
    {
        if !isset this->params["bind"] {
            let this->params["bind"] = [];
        }

        if typeof this->params["bind"] == "array" && merge {
            let this->params["bind"] = this->params["bind"] + bindParams;
        } else {
            let this->params["bind"] = bindParams;
        }

        return this;
    }

    /**
     * Sets the bind types in the criteria
     * This method replaces all previously set bound parameters
     */
    public function bindTypes(array! bindTypes) -> <CriteriaInterface>
    {
        let this->params["bindTypes"] = bindTypes;

        return this;
    }

    /**
     * Sets the cache options in the criteria
     * This method replaces all previously set cache options
     */
    public function cache(array! cache) -> <CriteriaInterface>
    {
        let this->params["cache"] = cache;

        return this;
    }

    /**
     * Sets the columns to be queried
     *
     *```php
     * $criteria->columns(
     *     [
     *         "id",
     *         "name",
     *     ]
     * );
     *```
     *
     * @param string|array columns
     */
    public function columns(var columns) -> <CriteriaInterface>
    {
        let this->params["columns"] = columns;

        return this;
    }

    /**
     * Adds the conditions parameter to the criteria
     */
    public function conditions(string! conditions) -> <CriteriaInterface>
    {
        let this->params["conditions"] = conditions;

        return this;
    }

    /**
     * Creates a query builder from criteria.
     *
     * ```php
     * $builder = Robots::query()
     *     ->where("type = :type:")
     *     ->bind(["type" => "mechanical"])
     *     ->createBuilder();
     * ```
     */
    public function createBuilder() -> <BuilderInterface>
    {
        var container, manager, builder;

        let container = this->getDI();

        if typeof container != "object" {
            let container = Di::getDefault();

            this->setDI(container);
        }

        let manager = <ManagerInterface> container->getShared("modelsManager");

        /**
         * Builds a query with the passed parameters
         */
        let builder = manager->createBuilder(this->params);

        builder->from(this->model);

        return builder;
    }

    /**
     * Sets SELECT DISTINCT / SELECT ALL flag
     */
     public function distinct(var distinct) -> <CriteriaInterface>
     {
         let this->params["distinct"] = distinct;

         return this;
     }

    /**
     * Executes a find using the parameters built with the criteria
     */
    public function execute() -> <ResultsetInterface>
    {
        var model;

        let model = this->getModelName();

        if unlikely typeof model != "string" {
            throw new Exception("Model name must be string");
        }

        return {model}::find(
            this->getParams()
        );
    }

    /**
     * Adds the "for_update" parameter to the criteria
     */
    public function forUpdate(bool forUpdate = true) -> <CriteriaInterface>
    {
        let this->params["for_update"] = forUpdate;

        return this;
    }

    /**
     * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
     */
    public static function fromInput(
        <DiInterface> container,
        string! modelName,
        array! data,
        string! operator = "AND"
    ) -> <CriteriaInterface> {
        var attribute, field, value, type, metaData, model, dataTypes,
            criteria, columnMap;
        array conditions, bind;

        let conditions = [];

        if count(data) {
            let metaData  = container->getShared("modelsMetadata"),
                model     = create_instance_params(
                    modelName,
                    [
                        null,
                        container
                    ]
                ),
                dataTypes = metaData->getDataTypes(model),
                columnMap = metaData->getReverseColumnMap(model);

            /**
             * We look for attributes in the array passed as data
             */
            let bind = [];

            for field, value in data {
                if typeof columnMap == "array" && count(columnMap) {
                    let attribute = columnMap[field];
                } else {
                    let attribute = field;
                }

                if fetch type, dataTypes[attribute] {
                    if value !== null && value !== "" {
                        if type == Column::TYPE_VARCHAR {
                            /**
                             * For varchar types we use LIKE operator
                             */
                            let conditions[] = "[" . field . "] LIKE :" . field . ":",
                                bind[field] = "%" . value . "%";

                            continue;
                        }

                        /**
                         * For the rest of data types we use a plain = operator
                         */
                        let conditions[] = "[" . field . "] = :" . field . ":",
                            bind[field] = value;
                    }
                }
            }
        }

        /**
         * Create an object instance and pass the parameters to it
         */
        let criteria = new self();
        criteria->setDI(container);

        if count(conditions) {
            criteria->where(
                join(
                    " " . operator . " ",
                    conditions
                )
            );

            criteria->bind(bind);
        }

        criteria->setModelName(modelName);

        return criteria;
    }

    /**
     * Returns the columns to be queried
     */
    public function getColumns() -> string | array | null
    {
        var columns;

        if !fetch columns, this->params["columns"] {
            return null;
        }

        return columns;
    }

    /**
     * Returns the conditions parameter in the criteria
     */
    public function getConditions() -> string | null
    {
        var conditions;

        if !fetch conditions, this->params["conditions"] {
            return null;
        }

        return conditions;
    }

    /**
     * Returns the DependencyInjector container
     */
    public function getDI() -> <DiInterface>
    {
        return this->params["di"];
    }

    /**
     * Returns the group clause in the criteria
     */
    public function getGroupBy()
    {
        var group;

        if !fetch group, this->params["group"] {
            return null;
        }

        return group;
    }

    /**
     * Returns the having clause in the criteria
     */
    public function getHaving()
    {
        var having;

        if !fetch having, this->params["having"] {
            return null;
        }

        return having;
    }

    /**
     * Returns the limit parameter in the criteria, which will be
     *
     * - An integer if 'limit' was set without an 'offset'
     * - An array with 'number' and 'offset' keys if an offset was set with the limit
     * - NULL if limit has not been set
     */
    public function getLimit()  -> int | array | null
    {
        var limit;

        if !fetch limit, this->params["limit"] {
            return null;
        }

        return limit;
    }

    /**
     * Returns an internal model name on which the criteria will be applied
     */
    public function getModelName() -> string
    {
        return this->model;
    }

    /**
     * Returns the order clause in the criteria
     */
    public function getOrderBy() -> string | null
    {
        var order;

        if !fetch order, this->params["order"] {
            return null;
        }

        return order;
    }

    /**
     * Returns all the parameters defined in the criteria
     */
    public function getParams() -> array
    {
        return this->params;
    }

    /**
     * Returns the conditions parameter in the criteria
     */
    public function getWhere() -> string | null
    {
        var conditions;

        if !fetch conditions, this->params["conditions"] {
            return null;
        }

        return conditions;
    }

    /**
     * Adds the group-by clause to the criteria
     */
    public function groupBy(var group) -> <CriteriaInterface>
    {
        let this->params["group"] = group;

        return this;
    }

    /**
     * Adds the having clause to the criteria
     */
    public function having(var having) -> <CriteriaInterface>
    {
        let this->params["having"] = having;

        return this;
    }

    /**
     * Adds an INNER join to the query
     *
     *```php
     * $criteria->innerJoin(
     *     Robots::class
     * );
     *
     * $criteria->innerJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id"
     * );
     *
     * $criteria->innerJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *```
     */
    public function innerJoin(string! model, var conditions = null, var alias = null) -> <CriteriaInterface>
    {
        return this->join(model, conditions, alias, "INNER");
    }

    /**
     * Appends an IN condition to the current conditions
     *
     * ```php
     * $criteria->inWhere("id", [1, 2, 3]);
     * ```
     */
    public function inWhere(string! expr, array! values) -> <CriteriaInterface>
    {
        var hiddenParam, value;
        array bindParams, bindKeys;
        string key, queryKey;

        if !count(values) {
            this->andWhere(expr . " != " . expr);

            return this;
        }

        let hiddenParam = this->hiddenParamNumber;

        let bindParams = [],
            bindKeys = [];

        for value in values {
            /**
             * Key with auto bind-params
             */
            let key = "ACP" . hiddenParam;

            let queryKey = ":" . key . ":";

            let bindKeys[] = queryKey,
                bindParams[key] = value;

            let hiddenParam++;
        }

        /**
         * Create a standard IN condition with bind params
         * Append the IN to the current conditions using and "and"
         */
        this->andWhere(
            expr . " IN (" . join(", ", bindKeys) . ")",
            bindParams
        );

        let this->hiddenParamNumber = hiddenParam;

        return this;
    }

    /**
     * Adds an INNER join to the query
     *
     *```php
     * $criteria->join(
     *     Robots::class
     * );
     *
     * $criteria->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id"
     * );
     *
     * $criteria->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *
     * $criteria->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r",
     *     "LEFT"
     * );
     *```
     */
    public function join(string! model, var conditions = null, var alias = null, var type = null) -> <CriteriaInterface>
    {
        var mergedJoins, currentJoins;
        array join;

        let join = [model, conditions, alias, type];

        if fetch currentJoins, this->params["joins"] {
            if typeof currentJoins == "array" {
                let mergedJoins = array_merge(currentJoins, [join]);
            } else {
                let mergedJoins = [join];
            }
        } else {
            let mergedJoins = [join];
        }

        let this->params["joins"] = mergedJoins;

        return this;
    }

    /**
     * Adds a LEFT join to the query
     *
     *```php
     * $criteria->leftJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *```
     */
    public function leftJoin(string! model, var conditions = null, var alias = null) -> <CriteriaInterface>
    {
        return this->join(model, conditions, alias, "LEFT");
    }

    /**
     * Adds the limit parameter to the criteria.
     *
     * ```php
     * $criteria->limit(100);
     * $criteria->limit(100, 200);
     * $criteria->limit("100", "200");
     * ```
     */
    public function limit(int limit, int offset = 0) -> <CriteriaInterface>
    {
        let limit  = abs(limit);
        let offset = abs(offset);

        if unlikely limit == 0 {
            return this;
        }

        if offset == 0 {
            let this->params["limit"] = limit;
        } else {
            let this->params["limit"] = [
                "number": limit,
                "offset": offset
            ];
        }

        return this;
    }

    /**
     * Appends a NOT BETWEEN condition to the current conditions
     *
     *```php
     * $criteria->notBetweenWhere("price", 100.25, 200.50);
     *```
     */
    public function notBetweenWhere(string! expr, var minimum, var maximum) -> <CriteriaInterface>
    {
        var hiddenParam, nextHiddenParam;
        string minimumKey, maximumKey;

        let hiddenParam = this->hiddenParamNumber;

        let nextHiddenParam = hiddenParam + 1;

        /**
         * Minimum key with auto bind-params
         */
        let minimumKey = "ACP" . hiddenParam;

        /**
         * Maximum key with auto bind-params
         */
        let maximumKey = "ACP" . nextHiddenParam;

        /**
         * Create a standard BETWEEN condition with bind params
         * Append the BETWEEN to the current conditions using and "and"
         */
        this->andWhere(
            expr . " NOT BETWEEN :" . minimumKey . ": AND :"  . maximumKey . ":",
            [
                minimumKey: minimum,
                maximumKey: maximum
            ]
        );

        let nextHiddenParam++;

        let this->hiddenParamNumber = nextHiddenParam;

        return this;
    }

    /**
     * Appends a NOT IN condition to the current conditions
     *
     *```php
     * $criteria->notInWhere("id", [1, 2, 3]);
     *```
     */
    public function notInWhere(string! expr, array! values) -> <CriteriaInterface>
    {
        var hiddenParam, value;
        array bindParams, bindKeys;
        string key;

        let hiddenParam = this->hiddenParamNumber;

        let bindParams = [],
            bindKeys = [];

        for value in values {
            /**
             * Key with auto bind-params
             */
            let key = "ACP" . hiddenParam,
                bindKeys[] = ":" . key . ":",
                bindParams[key] = value;

            let hiddenParam++;
        }

        /**
         * Create a standard IN condition with bind params
         * Append the IN to the current conditions using and "and"
         */
        this->andWhere(
            expr . " NOT IN (" . join(", ", bindKeys) . ")",
            bindParams
        );

        let this->hiddenParamNumber = hiddenParam;

        return this;
    }

    /**
     * Adds the order-by clause to the criteria
     */
    public function orderBy(string! orderColumns) -> <CriteriaInterface>
    {
        let this->params["order"] = orderColumns;

        return this;
    }

    /**
     * Appends a condition to the current conditions using an OR operator
     */
    public function orWhere(string! conditions, var bindParams = null, var bindTypes = null) -> <CriteriaInterface>
    {
        var currentConditions;

        if fetch currentConditions, this->params["conditions"] {
            let conditions = "(" . currentConditions . ") OR (" . conditions . ")";
        }

        return this->where(conditions, bindParams, bindTypes);
    }

    /**
     * Adds a RIGHT join to the query
     *
     *```php
     * $criteria->rightJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *```
     */
    public function rightJoin(string! model, conditions = null, alias = null) -> <CriteriaInterface>
    {
        return this->join(model, conditions, alias, "RIGHT");
    }

    /**
     * Sets the DependencyInjector container
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->params["di"] = container;
    }

    /**
     * Set a model on which the query will be executed
     */
    public function setModelName(string! modelName) -> <CriteriaInterface>
    {
        let this->model = modelName;

        return this;
    }

    /**
     * Adds the "shared_lock" parameter to the criteria
     */
    public function sharedLock(bool sharedLock = true) -> <CriteriaInterface>
    {
        let this->params["shared_lock"] = sharedLock;

        return this;
    }

    /**
     * Sets the conditions parameter in the criteria
     */
    public function where(string! conditions, var bindParams = null, var bindTypes = null) -> <CriteriaInterface>
    {
        var currentBindParams, currentBindTypes;

        let this->params["conditions"] = conditions;

        /**
         * Update or merge existing bound parameters
         */
        if typeof bindParams == "array" {
            if fetch currentBindParams, this->params["bind"] {
                let this->params["bind"] = array_merge(
                    currentBindParams,
                    bindParams
                );
            } else {
                let this->params["bind"] = bindParams;
            }
        }

        /**
         * Update or merge existing bind types parameters
         */
        if typeof bindTypes == "array" {
            if fetch currentBindTypes, this->params["bindTypes"] {
                let this->params["bindTypes"] = array_merge(
                    currentBindTypes,
                    bindTypes
                );
            } else {
                let this->params["bindTypes"] = bindTypes;
            }
        }

        return this;
    }

}
