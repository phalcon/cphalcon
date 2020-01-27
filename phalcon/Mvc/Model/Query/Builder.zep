
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query;

use Phalcon\Di;
use Phalcon\Db\Column;
use Phalcon\Di\DiInterface;
use Phalcon\Helper\Arr;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\QueryInterface;

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *```php
 * $params = [
 *     "models"     => [
 *         Users::class,
 *     ],
 *     "columns"    => ["id", "name", "status"],
 *     "conditions" => [
 *         [
 *             "created > :min: AND created < :max:",
 *             [
 *                 "min" => "2013-01-01",
 *                 "max" => "2014-01-01",
 *             ],
 *             [
 *                 "min" => PDO::PARAM_STR,
 *                 "max" => PDO::PARAM_STR,
 *             ],
 *         ],
 *     ],
 *     // or "conditions" => "created > '2013-01-01' AND created < '2014-01-01'",
 *     "group"      => ["id", "name"],
 *     "having"     => "name = 'Kamil'",
 *     "order"      => ["name", "id"],
 *     "limit"      => 20,
 *     "offset"     => 20,
 *     // or "limit" => [20, 20],
 * ];
 *
 * $queryBuilder = new \Phalcon\Mvc\Model\Query\Builder($params);
 *```
 */
class Builder implements BuilderInterface, InjectionAwareInterface
{
    protected bindParams;
    protected bindTypes;
    protected columns;
    protected conditions;
    protected container;
    protected distinct;
    protected forUpdate;

    /**
     * @var array
     */
    protected group;

    protected having;
    protected hiddenParamNumber = 0;
    protected joins;
    protected limit;

    /**
     * @var array|string
     */
    protected models;

    protected offset;
    protected order;
    protected sharedLock;

    /**
     * Phalcon\Mvc\Model\Query\Builder constructor
     */
    public function __construct(var params = null, <DiInterface> container = null)
    {
        var conditions, columns, groupClause, havingClause, limitClause,
            forUpdate, sharedLock, orderClause, offsetClause, joinsClause,
            singleConditionArray, limit, offset, fromClause, singleCondition,
            singleParams, singleTypes, distinct, bind, bindTypes;
        array mergedConditions, mergedParams, mergedTypes;

        if typeof params == "array" {
            /**
             * Process conditions
             */
            if fetch conditions, params[0] {
                let this->conditions = conditions;
            } else {
                if fetch conditions, params["conditions"] {
                    let this->conditions = conditions;
                }
            }

            if typeof conditions == "array" {
                let mergedConditions = [];
                let mergedParams     = [];
                let mergedTypes      = [];

                for singleConditionArray in conditions {
                    if typeof singleConditionArray == "array" {
                        fetch singleCondition, singleConditionArray[0];
                        fetch singleParams, singleConditionArray[1];
                        fetch singleTypes, singleConditionArray[2];

                        if typeof singleCondition == "string" {
                            let mergedConditions[] = singleCondition;
                        }

                        if typeof singleParams == "array" {
                            let mergedParams = mergedParams + singleParams;
                        }

                        if typeof singleTypes == "array" {
                            let mergedTypes = mergedTypes + singleTypes;
                        }
                    }
                }

                let this->conditions = implode(" AND ", mergedConditions);

                let this->bindParams = mergedParams;
                let this->bindTypes  = mergedTypes;
            }

            /**
             * Assign bind types
             */
            if fetch bind, params["bind"] {
                let this->bindParams = bind;
            }

            if fetch bindTypes, params["bindTypes"] {
                let this->bindTypes = bindTypes;
            }

            /**
             * Assign SELECT DISTINCT / SELECT ALL clause
             */
            if fetch distinct, params["distinct"] {
                let this->distinct = distinct;
            }

            /**
             * Assign FROM clause
             */
            if fetch fromClause, params["models"] {
                let this->models = fromClause;
            }

            /**
             * Assign COLUMNS clause
             */
            if fetch columns, params["columns"] {
                let this->columns = columns;
            }

            /**
             * Assign JOIN clause
             */
            if fetch joinsClause, params["joins"] {
                let this->joins = joinsClause;
            }

            /**
             * Assign GROUP clause
             */
            if fetch groupClause, params["group"] {
                this->groupBy(groupClause);
            }

            /**
             * Assign HAVING clause
             */
            if fetch havingClause, params["having"] {
                let this->having = havingClause;
            }

            /**
             * Assign ORDER clause
             */
            if fetch orderClause, params["order"] {
                let this->order = orderClause;
            }

            /**
             * Assign LIMIT clause
             */
            if fetch limitClause, params["limit"] {
                if typeof limitClause == "array" {
                    if fetch limit, limitClause[0] {
                        if is_int(limit) {
                            let this->limit = limit;
                        }

                        if fetch offset, limitClause[1] {
                            if is_int(offset) {
                                let this->offset = offset;
                            }
                        }
                    } else {
                        let this->limit = limitClause;
                    }
                } else {
                    let this->limit = limitClause;
                }
            }

            /**
             * Assign OFFSET clause
             */
            if fetch offsetClause, params["offset"] {
                let this->offset = offsetClause;
            }

            /**
             * Assign FOR UPDATE clause
             */
            if fetch forUpdate, params["for_update"] {
                let this->forUpdate = forUpdate;
            }

            /**
             * Assign SHARED LOCK clause
             */
            if fetch sharedLock, params["shared_lock"] {
                let this->sharedLock = sharedLock;
            }
        } else {
            if typeof params == "string" && params !== "" {
                let this->conditions = params;
            }
        }

        /**
         * Update the dependency injector if any
         */
        let this->container = container;
    }

    /**
     * Add a model to take part of the query
     *
     *```php
     * // Load data from models Robots
     * $builder->addFrom(
     *     Robots::class
     * );
     *
     * // Load data from model 'Robots' using 'r' as alias in PHQL
     * $builder->addFrom(
     *     Robots::class,
     *     "r"
     * );
     *```
     */
    public function addFrom(string model, string alias = null) -> <BuilderInterface>
    {
        var models, currentModel;

        let models = this->models;

        if typeof models != "array" {
            if models !== null {
                let currentModel = models,
                    models = [currentModel];
            } else {
                let models = [];
            }
        }

        if typeof alias == "string" && alias !== null {
            let models[alias] = model;
        } else {
            let models[] = model;
        }

        let this->models = models;

        return this;
    }

    /**
     * Appends a condition to the current HAVING conditions clause using a AND operator
     *
     *```php
     * $builder->andHaving("SUM(Robots.price) > 0");
     *
     * $builder->andHaving(
     *     "SUM(Robots.price) > :sum:",
     *     [
     *         "sum" => 100,
     *     ]
     * );
     *```
     */
    public function andHaving(string! conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
    {
        var currentConditions;

        let currentConditions = this->having;

        /**
         * Nest the condition to current ones or set as unique
         */
        if currentConditions {
            let conditions = "(" . currentConditions . ") AND (" . conditions . ")";
        }

        return this->having(conditions, bindParams, bindTypes);
    }

    /**
     * Appends a condition to the current WHERE conditions using a AND operator
     *
     *```php
     * $builder->andWhere("name = 'Peter'");
     *
     * $builder->andWhere(
     *     "name = :name: AND id > :id:",
     *     [
     *         "name" => "Peter",
     *         "id"   => 100,
     *     ]
     * );
     *```
     */
    public function andWhere(string! conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
    {
        var currentConditions;

        let currentConditions = this->conditions;

        /**
         * Nest the condition to current ones or set as unique
         */
        if currentConditions {
            let conditions = "(" . currentConditions . ") AND (" . conditions . ")";
        }

        return this->where(conditions, bindParams, bindTypes);
    }

    /**
     * Automatically escapes identifiers but only if they need to be escaped.
     */
    final public function autoescape(string identifier) -> string
    {
        if memstr(identifier, "[") || memstr(identifier, ".") || is_numeric(identifier) {
            return identifier;
        }

        return "[" . identifier . "]";
    }

    /**
     * Appends a BETWEEN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->betweenHaving("SUM(Robots.price)", 100.25, 200.50);
     *```
     */
    public function betweenHaving(string! expr, var minimum, var maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionBetween("Having", operator, expr, minimum, maximum);
    }

    /**
     * Appends a BETWEEN condition to the current WHERE conditions
     *
     *```php
     * $builder->betweenWhere("price", 100.25, 200.50);
     *```
     */
    public function betweenWhere(string! expr, var minimum, var maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionBetween("Where", operator, expr, minimum, maximum);
    }

    /**
     * Sets the columns to be queried
     *
     *```php
     * $builder->columns("id, name");
     *
     * $builder->columns(
     *     [
     *         "id",
     *         "name",
     *     ]
     * );
     *
     * $builder->columns(
     *     [
     *         "name",
     *         "number" => "COUNT(*)",
     *     ]
     * );
     *```
     */
    public function columns(var columns) -> <BuilderInterface>
    {
        let this->columns = columns;

        return this;
    }

    /**
     * Sets SELECT DISTINCT / SELECT ALL flag
     *
     *```php
     * $builder->distinct("status");
     * $builder->distinct(null);
     *```
     */
    public function distinct(var distinct) -> <BuilderInterface>
    {
        let this->distinct = distinct;

        return this;
    }

    /**
     * Sets a FOR UPDATE clause
     *
     *```php
     * $builder->forUpdate(true);
     *```
     */
    public function forUpdate(bool forUpdate) -> <BuilderInterface>
    {
        let this->forUpdate = forUpdate;

        return this;
    }

    /**
     * Sets the models who makes part of the query
     *
     *```php
     * $builder->from(
     *     Robots::class
     * );
     *
     * $builder->from(
     *     [
     *         Robots::class,
     *         RobotsParts::class,
     *     ]
     * );
     *
     * $builder->from(
     *     [
     *         "r"  => Robots::class,
     *         "rp" => RobotsParts::class,
     *     ]
     * );
     *```
     */
    public function from(var models) -> <BuilderInterface>
    {
        let this->models = models;

        return this;
    }

    /**
     * Returns default bind params
     */
    public function getBindParams() -> array
    {
        return this->bindParams;
    }

    /**
     * Returns default bind types
     */
    public function getBindTypes() -> array
    {
        return this->bindTypes;
    }

    /**
     * Return the columns to be queried
     *
     * @return string|array
     */
    public function getColumns()
    {
        return this->columns;
    }

    /**
     * Returns the DependencyInjector container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Returns SELECT DISTINCT / SELECT ALL flag
     */
    public function getDistinct() -> bool
    {
        return this->distinct;
    }

    /**
     * Return the models who makes part of the query
     *
     * @return string|array
     */
    public function getFrom()
    {
        return this->models;
    }

    /**
     * Returns the GROUP BY clause
     */
    public function getGroupBy() -> array
    {
        return this->group;
    }

    /**
     * Return the current having clause
     */
    public function getHaving() -> string
    {
        return this->having;
    }

    /**
     * Return join parts of the query
     */
    public function getJoins() -> array
    {
        return this->joins;
    }

    /**
     * Returns the current LIMIT clause
     *
     * @return string|array
     */
    public function getLimit()
    {
        return this->limit;
    }

    /**
     * Returns the models involved in the query
     */
    public function getModels() -> string | array | null
    {
        var models = this->models;

        if typeof models == "array" && count(models) == 1 {
            return Arr::first(models);
        }

        return models;
    }

    /**
     * Returns the current OFFSET clause
     */
    public function getOffset() -> int
    {
        return this->offset;
    }

    /**
     * Returns the set ORDER BY clause
     *
     * @return string|array
     */
    public function getOrderBy()
    {
        return this->order;
    }

    /**
     * Returns a PHQL statement built based on the builder parameters
     */
    final public function getPhql() -> string
    {
        var container, models, conditions, model, metaData, modelInstance,
            primaryKeys, firstPrimaryKey, columnMap, modelAlias,
            attributeField, phql, column, columns, selectedColumns,
            selectedColumn, selectedModel, selectedModels, columnAlias,
            modelColumnAlias, joins, join, joinModel, joinConditions,
            joinAlias, joinType, group, groupItems, groupItem, having, order,
            orderItems, orderItem, limit, number, offset, forUpdate, distinct;
        bool noPrimary;

        let container = this->container;
        if typeof container != "object" {
            let container = Di::getDefault(),
                this->container = container;
        }

        let models = this->models;
        if typeof models == "array" {
            if unlikely !count(models) {
                throw new Exception(
                    "At least one model is required to build the query"
                );
            }
        } else {
            if unlikely !models {
                throw new Exception(
                    "At least one model is required to build the query"
                );
            }
        }

        let conditions = this->conditions;

        if is_numeric(conditions) {
            /**
             * If the conditions is a single numeric field. We internally create
             * a condition using the related primary key
             */
            if typeof models == "array" {
                if unlikely count(models) > 1 {
                    throw new Exception(
                        "Cannot build the query. Invalid condition"
                    );
                }

                let model = models[0];
            } else {
                let model = models;
            }

            /**
             * Get the models metadata service to obtain the column names,
             * column map and primary key
             */
            let metaData      = container->getShared("modelsMetadata"),
                modelInstance = create_instance_params(
                    model,
                    [
                        null,
                        container
                    ]
                );

            let noPrimary = true,
                primaryKeys = metaData->getPrimaryKeyAttributes(modelInstance);

            if count(primaryKeys) {
                if fetch firstPrimaryKey, primaryKeys[0] {
                    /**
                     * The PHQL contains the renamed columns if available
                     */
                    if globals_get("orm.column_renaming") {
                        let columnMap = metaData->getColumnMap(modelInstance);
                    } else {
                        let columnMap = null;
                    }

                    if typeof columnMap == "array" {
                        if unlikely !fetch attributeField, columnMap[firstPrimaryKey] {
                            throw new Exception(
                                "Column '" . firstPrimaryKey . "' isn't part of the column map"
                            );
                        }
                    } else {
                        let attributeField = firstPrimaryKey;
                    }

                    let conditions = this->autoescape(model) . "." . this->autoescape(attributeField) . " = " . conditions,
                        noPrimary = false;
                }
            }

            /**
             * A primary key is mandatory in these cases
             */
            if unlikely noPrimary {
                throw new Exception(
                    "Source related to this model does not have a primary key defined"
                );
            }
        }

        let distinct = this->distinct;

        if typeof distinct == "boolean" {
            if distinct {
                let phql = "SELECT DISTINCT ";
            } else {
                let phql = "SELECT ALL ";
            }
        } else {
            let phql = "SELECT ";
        }

        let columns = this->columns;

        if columns !== null {
            /**
             * Generate PHQL for columns
             */
            if typeof columns == "array" {
                let selectedColumns = [];

                for columnAlias, column in columns {
                    if typeof columnAlias == "integer" {
                        let selectedColumns[] = column;
                    } else {
                        let selectedColumns[] = column . " AS " . this->autoescape(columnAlias);
                    }
                }

                let phql .= join(", ", selectedColumns);
            } else {
                let phql .= columns;
            }
        } else {
            /**
             * Automatically generate an array of models
             */
            if typeof models == "array" {
                let selectedColumns = [];

                for modelColumnAlias, model in models {
                    if typeof modelColumnAlias == "integer" {
                        let selectedColumn = this->autoescape(model) . ".*";
                    } else {
                        let selectedColumn = this->autoescape(modelColumnAlias) . ".*";
                    }

                    let selectedColumns[] = selectedColumn;
                }

                let phql .= join(", ", selectedColumns);
            } else {
                let phql .= this->autoescape(models) . ".*";
            }
        }

        /**
         * Join multiple models or use a single one if it is a string
         */
        if typeof models == "array" {
            let selectedModels = [];

            for modelAlias, model in models {
                if typeof modelAlias == "string" {
                    let selectedModel = this->autoescape(model) . " AS " . this->autoescape(modelAlias);
                } else {
                    let selectedModel = this->autoescape(model);
                }

                let selectedModels[] = selectedModel;
            }

            let phql .= " FROM " . join(", ", selectedModels);
        } else {
            let phql .= " FROM " . this->autoescape(models);
        }

        /**
         * Check if joins were passed to the builders
         */
        let joins = this->joins;

        if typeof joins == "array" {
            for join in joins {
                /**
                 * The joined table is in the first place of the array
                 */
                let joinModel = join[0];

                /**
                 * The join conditions are in the second place of the array
                 */
                let joinConditions = join[1];

                /**
                 * The join alias is in the second place of the array
                 */
                let joinAlias = join[2];

                /**
                 * Join type
                 */
                let joinType = join[3];

                /**
                 * Create the join according to the type
                 */
                if joinType {
                    let phql .= " " . joinType . " JOIN " . this->autoescape(joinModel);
                } else {
                    let phql .= " JOIN " . this->autoescape(joinModel);
                }

                /**
                 * Alias comes first
                 */
                if joinAlias {
                    let phql .= " AS " . this->autoescape(joinAlias);
                }

                /**
                 * Conditions then
                 */
                if joinConditions {
                    let phql .= " ON " . joinConditions;
                }
            }
        }

        // Only append where conditions if it's string
        if typeof conditions == "string" {
            if !empty conditions {
                let phql .= " WHERE " . conditions;
            }
        }

        /**
         * Process group parameters
         */
        let group = this->group;
        if group !== null {
            let groupItems = [];

            for groupItem in group {
                let groupItems[] = this->autoescape(groupItem);
            }

            let phql .= " GROUP BY " . join(", ", groupItems);
        }

        /**
         * Process having clause
         */
        let having = this->having;
        if having !== null {
            if !empty having {
                let phql .= " HAVING " . having;
            }
        }

        /**
         * Process order clause
         */
        let order = this->order;

        if order !== null {
            if typeof order == "array" {
                let orderItems = [];

                for orderItem in order {
                    /**
                     * For case 'ORDER BY 1'
                     */
                    if typeof orderItem == "integer" {
                        let orderItems[] = orderItem;

                        continue;
                    }

                    if memstr(orderItem, " ") !== 0 {
                        var itemExplode;

                        let itemExplode = explode(" ", orderItem);
                        let orderItems[] = this->autoescape(itemExplode[0]) . " " . itemExplode[1];

                        continue;
                    }

                    let orderItems[] = this->autoescape(orderItem);
                }

                let phql .= " ORDER BY " . join(", ", orderItems);
            } else {
                let phql .= " ORDER BY " . order;
            }
        }

        /**
         * Process limit parameters
         */
        let limit = this->limit;
        if limit !== null {
            let number = null;

            if typeof limit == "array" {
                let number = limit["number"];

                if fetch offset, limit["offset"] {
                    if !is_numeric(offset) {
                        let offset = 0;
                    }
                }
            } else {
                if is_numeric(limit) {
                    let number = limit,
                        offset = this->offset;
                    if offset !== null {
                        if !is_numeric(offset) {
                            let offset = 0;
                        }
                    }
                }
            }

            if is_numeric(number) {
                let phql .= " LIMIT :APL0:",
                    this->bindParams["APL0"] = intval(number, 10),
                    this->bindTypes["APL0"] = Column::BIND_PARAM_INT;

                if is_numeric(offset) && offset !== 0 {
                    let phql .= " OFFSET :APL1:",
                        this->bindParams["APL1"] = intval(offset, 10),
                        this->bindTypes["APL1"] = Column::BIND_PARAM_INT;
                }
            }
        }

        let forUpdate = this->forUpdate;

        if typeof forUpdate === "boolean" {
            if forUpdate {
                let phql .= " FOR UPDATE";
            }
        }

        return phql;
    }

    /**
     * Returns the query built
     */
    public function getQuery() -> <QueryInterface>
    {
        var query, bindParams, bindTypes, phql, container;

        let phql = this->getPhql();

        let container = <DiInterface> this->container;

        if unlikely typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound(
                    "the services related to the ORM"
                )
            );
        }

        /**
         * Gets Query instance from DI container
         */
        let query = <QueryInterface> container->get(
            "Phalcon\\Mvc\\Model\\Query",
            [phql, container]
        );

        // Set default bind params
        let bindParams = this->bindParams;
        if typeof bindParams == "array" {
            query->setBindParams(bindParams);
        }

        // Set default bind types
        let bindTypes = this->bindTypes;
        if typeof bindTypes == "array" {
            query->setBindTypes(bindTypes);
        }

        if typeof this->sharedLock === "boolean" {
            query->setSharedLock(this->sharedLock);
        }

        return query;
    }

    /**
     * Return the conditions for the query
     *
     * @return string|array
     */
    public function getWhere()
    {
        return this->conditions;
    }

    /**
     * Sets a GROUP BY clause
     *
     *```php
     * $builder->groupBy(
     *     [
     *         "Robots.name",
     *     ]
     * );
     *```
     *
     * @param string|array group
     */
    public function groupBy(var group) -> <BuilderInterface>
    {
        if typeof group == "string" {
            if memstr(group, ",") {
                let group = str_replace(" ", "", group);
            }

            let group = explode(",", group);
        }

        let this->group = group;

        return this;
    }

    /**
     * Sets the HAVING condition clause
     *
     *```php
     * $builder->having("SUM(Robots.price) > 0");
     *
     * $builder->having(
     *     "SUM(Robots.price) > :sum:",
     *     [
     *         "sum" => 100,
     *     ]
     * );
     *```
     */
    public function having(var conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
    {
        var currentBindParams, currentBindTypes;

        let this->having = conditions;

        let currentBindParams = this->bindParams;

        /**
         * Merge the bind params to the current ones
         */
        if typeof currentBindParams == "array" {
            let this->bindParams = currentBindParams + bindParams;
        } else {
            let this->bindParams = bindParams;
        }

        let currentBindTypes = this->bindTypes;

        /**
         * Merge the bind types to the current ones
         */
        if typeof currentBindTypes == "array" {
            let this->bindTypes = currentBindTypes + bindTypes;
        } else {
            let this->bindTypes = bindTypes;
        }

        return this;
    }

    /**
     * Appends an IN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->inHaving("SUM(Robots.price)", [100, 200]);
     *```
     */
    public function inHaving(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionIn("Having", operator, expr, values);
    }

    /**
     * Adds an INNER join to the query
     *
     *```php
     * // Inner Join model 'Robots' with automatic conditions and alias
     * $builder->innerJoin(
     *     Robots::class
     * );
     *
     * // Inner Join model 'Robots' specifying conditions
     * $builder->innerJoin(
     *     Robots::class,
     *     "Robots.id = RobotsParts.robots_id"
     * );
     *
     * // Inner Join model 'Robots' specifying conditions and alias
     * $builder->innerJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *```
     */
    public function innerJoin(string! model, string conditions = null, string alias = null) -> <BuilderInterface>
    {
        let this->joins[] = [model, conditions, alias, "INNER"];

        return this;
    }

    /**
     * Appends an IN condition to the current WHERE conditions
     *
     *```php
     * $builder->inWhere(
     *     "id",
     *     [1, 2, 3]
     * );
     *```
     */
    public function inWhere(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionIn("Where", operator, expr, values);
    }

    /**
     * Adds an :type: join (by default type - INNER) to the query
     *
     *```php
     * // Inner Join model 'Robots' with automatic conditions and alias
     * $builder->join(
     *     Robots::class
     * );
     *
     * // Inner Join model 'Robots' specifying conditions
     * $builder->join(
     *     Robots::class,
     *     "Robots.id = RobotsParts.robots_id"
     * );
     *
     * // Inner Join model 'Robots' specifying conditions and alias
     * $builder->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *
     * // Left Join model 'Robots' specifying conditions, alias and type of join
     * $builder->join(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r",
     *     "LEFT"
     * );
     *```
     */
    public function join(string! model, string conditions = null, string alias = null, string type = null) -> <BuilderInterface>
    {
        let this->joins[] = [model, conditions, alias, type];

        return this;
    }

    /**
     * Adds a LEFT join to the query
     *
     *```php
     * $builder->leftJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *```
     */
    public function leftJoin(string! model, string conditions = null, string alias = null) -> <BuilderInterface>
    {
        let this->joins[] = [model, conditions, alias, "LEFT"];

        return this;
    }

    /**
     * Sets a LIMIT clause, optionally an offset clause
     *
     * ```php
     * $builder->limit(100);
     * $builder->limit(100, 20);
     * $builder->limit("100", "20");
     * ```
     */
    public function limit(int limit, var offset = null) -> <BuilderInterface>
    {
        let limit = abs(limit);

        if unlikely limit == 0 {
            return this;
        }

        let this->limit = limit;

        if is_numeric(offset) {
            let this->offset = abs((int) offset);
        }

        return this;
    }

    /**
     * Appends a NOT BETWEEN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->notBetweenHaving("SUM(Robots.price)", 100.25, 200.50);
     *```
     */
    public function notBetweenHaving(string! expr, var minimum, var maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionNotBetween(
            "Having",
            operator,
            expr,
            minimum,
            maximum
        );
    }

    /**
     * Appends a NOT BETWEEN condition to the current WHERE conditions
     *
     *```php
     * $builder->notBetweenWhere("price", 100.25, 200.50);
     *```
     */
    public function notBetweenWhere(string! expr, var minimum, var maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionNotBetween(
            "Where",
            operator,
            expr,
            minimum,
            maximum
        );
    }

    /**
     * Appends a NOT IN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->notInHaving("SUM(Robots.price)", [100, 200]);
     *```
     */
    public function notInHaving(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionNotIn("Having", operator, expr, values);
    }

    /**
     * Appends a NOT IN condition to the current WHERE conditions
     *
     *```php
     * $builder->notInWhere("id", [1, 2, 3]);
     *```
     */
    public function notInWhere(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionNotIn("Where", operator, expr, values);
    }

    /**
     * Sets an OFFSET clause
     *
     *```php
     * $builder->offset(30);
     *```
     */
    public function offset(int offset) -> <BuilderInterface>
    {
        let this->offset = offset;

        return this;
    }

    /**
     * Sets an ORDER BY condition clause
     *
     *```php
     * $builder->orderBy("Robots.name");
     * $builder->orderBy(["1", "Robots.name"]);
     * $builder->orderBy(["Robots.name DESC"]);
     *```
     *
     * @param string|array orderBy
     */
    public function orderBy(var orderBy) -> <BuilderInterface>
    {
        let this->order = orderBy;

        return this;
    }

    /**
     * Appends a condition to the current HAVING conditions clause using an OR operator
     *
     *```php
     * $builder->orHaving("SUM(Robots.price) > 0");
     *
     * $builder->orHaving(
     *     "SUM(Robots.price) > :sum:",
     *     [
     *         "sum" => 100,
     *     ]
     * );
     *```
     */
    public function orHaving(string! conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
    {
        var currentConditions;

        let currentConditions = this->having;

        /**
         * Nest the condition to current ones or set as unique
         */
        if currentConditions {
            let conditions = "(" . currentConditions . ") OR (" . conditions . ")";
        }

        return this->having(conditions, bindParams, bindTypes);
    }

    /**
     * Appends a condition to the current conditions using an OR operator
     *
     *```php
     * $builder->orWhere("name = 'Peter'");
     *
     * $builder->orWhere(
     *     "name = :name: AND id > :id:",
     *     [
     *         "name" => "Peter",
     *         "id"   => 100,
     *     ]
     * );
     *```
     */
    public function orWhere(string! conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
    {
        var currentConditions;

        let currentConditions = this->conditions;

        /**
         * Nest the condition to current ones or set as unique
         */
        if currentConditions {
            let conditions = "(" . currentConditions . ") OR (" . conditions . ")";
        }

        return this->where(conditions, bindParams, bindTypes);
    }

    /**
     * Adds a RIGHT join to the query
     *
     *```php
     * $builder->rightJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
     * );
     *```
     */
    public function rightJoin(string! model, string conditions = null, string alias = null) -> <BuilderInterface>
    {
        let this->joins[] = [model, conditions, alias, "RIGHT"];

        return this;
    }

    /**
     * Set default bind parameters
     */
    public function setBindParams(array! bindParams, bool merge = false) -> <BuilderInterface>
    {
        var currentBindParams;

        if merge {
            let currentBindParams = this->bindParams;
            if typeof currentBindParams == "array" {
                let this->bindParams = currentBindParams + bindParams;
            } else {
                let this->bindParams = bindParams;
            }
        } else {
            let this->bindParams = bindParams;
        }

        return this;
    }

    /**
     * Set default bind types
     */
    public function setBindTypes(array! bindTypes, bool merge = false) -> <BuilderInterface>
    {
        var currentBindTypes;

        if unlikely merge {
            let currentBindTypes = this->bindTypes;

            if typeof currentBindTypes == "array" {
                let this->bindTypes = currentBindTypes + bindTypes;
            } else {
                let this->bindTypes = bindTypes;
            }
        } else {
            let this->bindTypes = bindTypes;
        }

        return this;
    }

    /**
     * Sets the DependencyInjector container
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Sets the query WHERE conditions
     *
     *```php
     * $builder->where(100);
     *
     * $builder->where("name = 'Peter'");
     *
     * $builder->where(
     *     "name = :name: AND id > :id:",
     *     [
     *         "name" => "Peter",
     *         "id"   => 100,
     *     ]
     * );
     *```
     */
    public function where(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
    {
        var currentBindParams, currentBindTypes;

        let this->conditions = conditions;

        /**
         * Merge the bind params to the current ones
         */
        if count(bindParams) > 0 {
            let currentBindParams = this->bindParams;

            if typeof currentBindParams == "array" {
                let this->bindParams = currentBindParams + bindParams;
            } else {
                let this->bindParams = bindParams;
            }
        }

        /**
         * Merge the bind types to the current ones
         */
        if count(bindTypes) > 0 {
            let currentBindTypes = this->bindTypes;

            if typeof currentBindTypes == "array" {
                let this->bindTypes = currentBindTypes + bindTypes;
            } else {
                let this->bindTypes = bindTypes;
            }
        }

        return this;
    }

    /**
     * Appends a BETWEEN condition
     */
    protected function conditionBetween(string! clause, string! operator, string! expr, var minimum, var maximum) -> <BuilderInterface>
    {
        var hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod;

        if unlikely (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
            throw new Exception(
                sprintf(
                    "Operator % is not available.",
                    operator
                )
            );
        }

        let operatorMethod = operator . clause;

        let hiddenParam = this->hiddenParamNumber,
            nextHiddenParam = hiddenParam + 1;

        /**
         * Minimum key with auto bind-params and
         * Maximum key with auto bind-params
         */
        let minimumKey = "AP" . hiddenParam,
            maximumKey = "AP" . nextHiddenParam;

        /**
         * Create a standard BETWEEN condition with bind params
         * Append the BETWEEN to the current conditions using and "and"
         */

        this->{operatorMethod}(
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
     * Appends an IN condition
     */
    protected function conditionIn(string! clause, string! operator, string! expr, array! values) -> <BuilderInterface>
    {
        var key, queryKey, value, bindKeys, bindParams, operatorMethod;
        int hiddenParam;

        if unlikely (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
            throw new Exception(
                sprintf(
                    "Operator % is not available.",
                    operator
                )
            );
        }

        let operatorMethod = operator . clause;

        if !count(values) {
            this->{operatorMethod}(expr . " != " . expr);

            return this;
        }

        let hiddenParam = (int) this->hiddenParamNumber;

        let bindParams = [],
            bindKeys = [];

        for value in values {
            /**
             * Key with auto bind-params
             */
            let key = "AP" . hiddenParam,
                queryKey = ":" . key . ":",
                bindKeys[] = queryKey,
                bindParams[key] = value,
                hiddenParam++;
        }

        /**
         * Create a standard IN condition with bind params
         * Append the IN to the current conditions using and "and"
         */
        this->{operatorMethod}(
            expr . " IN (" . join(", ", bindKeys) . ")",
            bindParams
        );

        let this->hiddenParamNumber = hiddenParam;

        return this;
    }

    /**
     * Appends a NOT BETWEEN condition
     */
    protected function conditionNotBetween(string! clause, string! operator, string! expr, var minimum, var maximum) -> <BuilderInterface>
    {
        var hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod;

        if unlikely (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
            throw new Exception(
                sprintf(
                    "Operator % is not available.",
                    operator
                )
            );
        }

        let operatorMethod = operator . clause;

        let hiddenParam = this->hiddenParamNumber,
            nextHiddenParam = hiddenParam + 1;

        /**
         * Minimum key with auto bind-params and
         * Maximum key with auto bind-params
         */
        let minimumKey = "AP" . hiddenParam,
            maximumKey = "AP" . nextHiddenParam;

        /**
         * Create a standard BETWEEN condition with bind params
         * Append the NOT BETWEEN to the current conditions using and "and"
         */
        this->{operatorMethod}(
            expr . " NOT BETWEEN :" . minimumKey . ": AND :" . maximumKey . ":",
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
     * Appends a NOT IN condition
     */
    protected function conditionNotIn(string! clause, string! operator, string! expr, array! values) -> <BuilderInterface>
    {
        var key, queryKey, value, bindKeys, bindParams, operatorMethod;
        int hiddenParam;

        if unlikely (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
            throw new Exception(
                sprintf(
                    "Operator % is not available.",
                    operator
                )
            );
        }

        let operatorMethod = operator . clause;

        if !count(values) {
            this->{operatorMethod}(expr . " != " . expr);

            return this;
        }

        let hiddenParam = (int) this->hiddenParamNumber;

        let bindParams = [],
            bindKeys = [];

        for value in values {
            /**
             * Key with auto bind-params
             */
            let key = "AP" . hiddenParam,
                queryKey = ":" . key . ":",
                bindKeys[] = queryKey,
                bindParams[key] = value,
                hiddenParam++;
        }

        /**
         * Create a standard NOT IN condition with bind params
         * Append the NOT IN to the current conditions using and "and"
         */
        this->{operatorMethod}(expr . " NOT IN (" . join(", ", bindKeys) . ")", bindParams);

        let this->hiddenParamNumber = hiddenParam;

        return this;
    }
}
