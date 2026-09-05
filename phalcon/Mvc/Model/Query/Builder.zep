
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query;

use Phalcon\Contracts\Mvc\MvcTypes;
use Phalcon\Db\Column;
use Phalcon\Di\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Exceptions\ManagerOrmServicesUnavailable;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Query\Exceptions\Builder\BuilderColumnNotInMap;
use Phalcon\Mvc\Model\Query\Exceptions\Builder\BuilderConditionInvalid;
use Phalcon\Mvc\Model\Query\Exceptions\Builder\ModelRequired;
use Phalcon\Mvc\Model\Query\Exceptions\Builder\NoPrimaryKey;
use Phalcon\Mvc\Model\Query\Exceptions\Builder\OperatorNotAvailable;
use Phalcon\Mvc\Model\QueryInterface;
use Phalcon\Support\Settings;

/**
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
 *
 * @phpstan-import-type mvc_model_bind_params from MvcTypes
 * @phpstan-import-type mvc_model_bind_types from MvcTypes
 * @phpstan-import-type mvc_query_builder_join from MvcTypes
 * @phpstan-import-type mvc_query_builder_params from MvcTypes
 * @phpstan-import-type mvc_query_columns from MvcTypes
 * @phpstan-import-type mvc_query_order from MvcTypes
 */
class Builder implements BuilderInterface, InjectionAwareInterface
{
    /**
     * @phpstan-var mvc_model_bind_params
     */
    protected array bindParams = [];
    /**
     * @phpstan-var mvc_model_bind_types
     */
    protected array bindTypes = [];
    /**
     * @phpstan-var mvc_query_columns|null
     */
    protected columns = null;
    /**
     * @phpstan-var array<array-key, mixed>|int|string|null
     */
    protected conditions = null;

    /**
     * @var DiInterface|null
     *
     * @phpstan-var DiInterface|null
     */
    protected container;
    /**
     * @var mixed
     */
    protected distinct = null;
    protected bool forUpdate = false;
    /**
     * @phpstan-var array<array-key, string>|null
     */
    protected group = [];
    /**
     * @var string|null
     */
    protected having = null;
    protected int hiddenParamNumber = 0;
    /**
     * @phpstan-var array<array-key, mvc_query_builder_join>
     */
    protected array joins = [];
    /**
     * @var array|string
     *
     * @phpstan-var array<array-key, mixed>|int|string|null
     */
    protected limit;
    /**
     * @var array|string
     *
     * @phpstan-var mvc_query_columns|null
     */
    protected models;
    protected int offset = 0;
    /**
     * @var array|string
     *
     * @phpstan-var array<array-key, int|string>|string|null
     */
    protected order;
    protected string resultsetRowClass = "";
    protected bool sharedLock = false;

    /**
     * Phalcon\Mvc\Model\Query\Builder constructor
     *
     * @param array|string|null params
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
     * // Load data from models Invoices
     * $builder->addFrom(
     *     Invoices::class
     * );
     *
     * // Load data from model 'Invoices' using 'r' as alias in PHQL
     * $builder->addFrom(
     *     Invoices::class,
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
     * $builder->andHaving("SUM(Invoices.inv_total) > 0");
     *
     * $builder->andHaving(
     *     "SUM(Invoices.inv_total) > :sum:",
     *     [
     *         "sum" => 100,
     *     ]
     * );
     *```
     *
     * @phpstan-param mvc_model_bind_params $bindParams
     * @phpstan-param mvc_model_bind_types $bindTypes
     */
    public function andHaving(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
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
     *
     * @phpstan-param mvc_model_bind_params $bindParams
     * @phpstan-param mvc_model_bind_types $bindTypes
     */
    public function andWhere( string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
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
        if memstr(identifier, "[") || memstr(identifier, ".") || memstr(identifier, "(") || is_numeric(identifier) {
            return identifier;
        }

        return "[" . identifier . "]";
    }

    /**
     * Appends a BETWEEN condition to the current HAVING conditions clause
     *
     *```php
     * $builder->betweenHaving("SUM(Invoices.inv_total)", 100.25, 200.50);
     *```
     */
    public function betweenHaving(string expr, var minimum, var maximum,  string operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
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
    public function betweenWhere(string expr, var minimum, var maximum,  string operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionBetween("Where", operator, expr, minimum, maximum);
    }

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
     * $builder->columns("id, category");
     *
     * // Array, one column per element
     * $builder->columns(
     *     [
     *         "inv_id",
     *         "inv_total",
     *     ]
     * );
     *
     * // Array with named key. The name of the key acts as an
     * // alias (`AS` clause)
     * $builder->columns(
     *     [
     *         "inv_cst_id",
     *         "total_invoices" => "COUNT(*)",
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
     *     Invoices::class
     * );
     *
     * $builder->from(
     *     [
     *         Invoices::class,
     *         OrdersProducts::class,
     *     ]
     * );
     *
     * $builder->from(
     *     [
     *         "r"  => Invoices::class,
     *         "rp" => OrdersProducts::class,
     *     ]
     * );
     *```
     *
     * @phpstan-param mvc_query_columns $models
     */
    public function from(var models) -> <BuilderInterface>
    {
        let this->models = models;

        return this;
    }

    /**
     * Returns default bind params
     *
     * @phpstan-return mvc_model_bind_params
     */
    public function getBindParams() -> array
    {
        return this->bindParams;
    }

    /**
     * Returns default bind types
     *
     * @phpstan-return mvc_model_bind_types
     */
    public function getBindTypes() -> array
    {
        return this->bindTypes;
    }

    /**
     * Return the columns to be queried
     *
     * @return array|string
     *
     * @phpstan-return mvc_query_columns|null
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
     * @return array|string
     *
     * @phpstan-return mvc_query_columns|null
     */
    public function getFrom()
    {
        return this->models;
    }

    /**
     * Returns the GROUP BY clause
     *
     * @phpstan-return array<array-key, string>
     */
    public function getGroupBy() -> array
    {
        return this->group;
    }

    /**
     * Return the current having clause
     */
    public function getHaving() -> string | null
    {
        return this->having;
    }

    /**
     * Return join parts of the query
     *
     * @phpstan-return array<array-key, mvc_query_builder_join>
     */
    public function getJoins() -> array
    {
        return this->joins;
    }

    /**
     * Returns the current LIMIT clause
     *
     * @return array|string
     *
     * @phpstan-return array<array-key, mixed>|int|string|null
     */
    public function getLimit()
    {
        return this->limit;
    }

    /**
     * Returns the models involved in the query
     *
     * @phpstan-return mvc_query_columns|null
     */
    public function getModels() -> string | array | null
    {
        var models = this->models;

        if typeof models == "array" && count(models) == 1 {
            return reset(models);
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
     * @return array|string
     *
     * @phpstan-return array<array-key, int|string>|string|null
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
        var attributeField, column, columnAlias, columnMap, columns, conditions,
            container, distinct, firstPrimaryKey, forUpdate, group, groupItem,
            groupItems, having, join, joinAlias, joinConditions, joinModel,
            joinType, joins, limit, metaData, model, modelAlias, modelColumnAlias,
            modelInstance, models, number, order, orderItem, orderItems, phql,
            primaryKeys, selectedColumn, selectedColumns, selectedModel,
            selectedModels,
            offset = null;
        bool noPrimary;

        let container = this->container;
        if typeof container != "object" {
            let container = Di::getDefault(),
                this->container = container;
        }

        let models = this->models;
        if typeof models == "array" {
            if unlikely empty models {
                throw new ModelRequired();
            }
        } else {
            if unlikely !models {
                throw new ModelRequired();
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
                    throw new BuilderConditionInvalid();
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

            if !empty primaryKeys {
                if fetch firstPrimaryKey, primaryKeys[0] {
                    /**
                     * The PHQL contains the renamed columns if available
                     */
                    if Settings::get("orm.column_renaming") {
                        let columnMap = metaData->getColumnMap(modelInstance);
                    } else {
                        let columnMap = null;
                    }

                    if typeof columnMap == "array" {
                        if unlikely !fetch attributeField, columnMap[firstPrimaryKey] {
                            throw new BuilderColumnNotInMap(firstPrimaryKey);
                        }
                    } else {
                        let attributeField = firstPrimaryKey;
                    }

                    /**
                     * Use a named bind parameter instead of embedding the value
                     * directly in the PHQL string. Embedding produces a unique
                     * PHQL string per ID value, causing unbounded growth of the
                     * internal PHQL cache in long-running processes.
                     */
                    let this->bindParams["APK0"] = conditions,
                        conditions = this->autoescape(model) . "." . this->autoescape(attributeField) . " = :APK0:",
                        noPrimary = false;
                }
            }

            /**
             * A primary key is mandatory in these cases
             */
            if unlikely noPrimary {
                throw new NoPrimaryKey();
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
        if !empty group {
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

                    /**
                     * For cases 'ORDER BY column ASC' and complex expressions
                     */
                    var itemTrimmed, lastSpacePosition;

                    let itemTrimmed = trim(orderItem),
                        lastSpacePosition = strrpos(itemTrimmed, " ");

                    if false !== lastSpacePosition {
                        var perhapsExpression, perhapsDirection;

                        let perhapsExpression = trim(substr(itemTrimmed, 0, lastSpacePosition)),
                            perhapsDirection = rtrim(substr(itemTrimmed, lastSpacePosition + 1));

                        if (
                            strcasecmp(perhapsDirection, "desc") == 0 ||
                            strcasecmp(perhapsDirection, "asc") == 0
                        ) {
                            if !memstr(perhapsExpression, " ") {
                                let perhapsExpression = this->autoescape(perhapsExpression);
                            }

                            let orderItems[] = perhapsExpression . " " . perhapsDirection;
                        } else {
                            let orderItems[] = itemTrimmed;
                        }

                        continue;
                    }

                    let orderItems[] = this->autoescape(itemTrimmed);
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
            throw new ManagerOrmServicesUnavailable();
        }

        /**
         * Gets Query instance from DI container
         */
        let query = <QueryInterface> container->get(
            Query::class,
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

        /**
         * The accessor is not part of QueryInterface (see the interface's
         * v7 note), so a custom query service may not implement it.
         *
         * @todo v7: remove the method_exists() guard once the accessors are
         *       promoted to QueryInterface.
         */
        if this->resultsetRowClass != "" && method_exists(query, "setResultsetRowClass") {
            query->setResultsetRowClass(this->resultsetRowClass);
        }

        return query;
    }

    /**
     * Returns the class that will be used to hydrate rows that are not mapped
     * to a model (custom columns/joins). An empty string means the default
     * Phalcon\Mvc\Model\Row is used.
     */
    public function getResultsetRowClass() -> string
    {
        return this->resultsetRowClass;
    }

    /**
     * Return the conditions for the query
     *
     * @return array|string
     *
     * @phpstan-return array<array-key, mixed>|string|null
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
     *         "Invoices.inv_title",
     *     ]
     * );
     *```
     *
     * Passing null (or an empty array) clears the clause; the PHQL generator
     * treats both as "no GROUP BY".
     *
     * @param array|string|null $group
     *
     * @phpstan-param array<array-key, string>|string|null $group
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
     * $builder->having("SUM(Invoices.inv_total) > 0");
     *
     * $builder->having(
     *     "SUM(Invoices.inv_total) > :sum:",
     *     [
     *         "sum" => 100,
     *     ]
     * );
     *```
     *
     * @phpstan-param mvc_model_bind_params $bindParams
     * @phpstan-param mvc_model_bind_types $bindTypes
     */
    public function having(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
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
     * $builder->inHaving("SUM(Invoices.inv_total)", [100, 200]);
     *```
     *
     * @phpstan-param array<array-key, mixed> $values
     */
    public function inHaving(string expr,  array values,  string operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionIn("Having", operator, expr, values);
    }

    /**
     * Adds an INNER join to the query
     *
     *```php
     * // Inner Join model 'Invoices' with automatic conditions and alias
     * $builder->innerJoin(
     *     Invoices::class
     * );
     *
     * // Inner Join model 'Invoices' specifying conditions
     * $builder->innerJoin(
     *     Invoices::class,
     *     "Invoices.inv_id = OrdersProducts.oxp_ord_id"
     * );
     *
     * // Inner Join model 'Invoices' specifying conditions and alias
     * $builder->innerJoin(
     *     Invoices::class,
     *     "r.inv_id = OrdersProducts.oxp_ord_id",
     *     "r"
     * );
     *```
     */
    public function innerJoin( string model, string conditions = null, string alias = null) -> <BuilderInterface>
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
     *
     * @phpstan-param array<array-key, mixed> $values
     */
    public function inWhere(string expr,  array values,  string operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionIn("Where", operator, expr, values);
    }

    /**
     * Adds an :type: join (by default type - INNER) to the query
     *
     *```php
     * // Inner Join model 'Invoices' with automatic conditions and alias
     * $builder->join(
     *     Invoices::class
     * );
     *
     * // Inner Join model 'Invoices' specifying conditions
     * $builder->join(
     *     Invoices::class,
     *     "Invoices.inv_id = OrdersProducts.oxp_ord_id"
     * );
     *
     * // Inner Join model 'Invoices' specifying conditions and alias
     * $builder->join(
     *     Invoices::class,
     *     "r.inv_id = OrdersProducts.oxp_ord_id",
     *     "r"
     * );
     *
     * // Left Join model 'Invoices' specifying conditions, alias and type of join
     * $builder->join(
     *     Invoices::class,
     *     "r.inv_id = OrdersProducts.oxp_ord_id",
     *     "r",
     *     "LEFT"
     * );
     *```
     */
    public function join(string model, string conditions = null, string alias = null, string type = null) -> <BuilderInterface>
    {
        let this->joins[] = [model, conditions, alias, type];

        return this;
    }

    /**
     * Adds a LEFT join to the query
     *
     *```php
     * $builder->leftJoin(
     *     Invoices::class,
     *     "r.inv_id = OrdersProducts.oxp_ord_id",
     *     "r"
     * );
     *```
     */
    public function leftJoin( string model, string conditions = null, string alias = null) -> <BuilderInterface>
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
     * $builder->notBetweenHaving("SUM(Invoices.inv_total)", 100.25, 200.50);
     *```
     */
    public function notBetweenHaving(string expr, var minimum, var maximum,  string operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
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
    public function notBetweenWhere(string expr, var minimum, var maximum,  string operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
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
     * $builder->notInHaving("SUM(Invoices.inv_total)", [100, 200]);
     *```
     *
     * @phpstan-param array<array-key, mixed> $values
     */
    public function notInHaving(string expr,  array values,  string operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
    {
        return this->conditionNotIn("Having", operator, expr, values);
    }

    /**
     * Appends a NOT IN condition to the current WHERE conditions
     *
     *```php
     * $builder->notInWhere("id", [1, 2, 3]);
     *```
     *
     * @phpstan-param array<array-key, mixed> $values
     */
    public function notInWhere(string expr,  array values,  string operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
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
     * $builder->orderBy("Invoices.inv_title");
     * $builder->orderBy(["1", "Invoices.inv_title"]);
     * $builder->orderBy(["Invoices.inv_title DESC"]);
     *```
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
     * $builder->orHaving("SUM(Invoices.inv_total) > 0");
     *
     * $builder->orHaving(
     *     "SUM(Invoices.inv_total) > :sum:",
     *     [
     *         "sum" => 100,
     *     ]
     * );
     *```
     *
     * @phpstan-param mvc_model_bind_params $bindParams
     * @phpstan-param mvc_model_bind_types $bindTypes
     */
    public function orHaving(string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
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
    public function orWhere( string conditions, array bindParams = [], array bindTypes = []) -> <BuilderInterface>
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
     *     Invoices::class,
     *     "r.inv_id = OrdersProducts.oxp_ord_id",
     *     "r"
     * );
     *```
     */
    public function rightJoin(string model, string conditions = null, string alias = null) -> <BuilderInterface>
    {
        let this->joins[] = [model, conditions, alias, "RIGHT"];

        return this;
    }

    /**
     * Set default bind parameters
     *
     * @phpstan-param mvc_model_bind_params $bindParams
     */
    public function setBindParams( array bindParams, bool merge = false) -> <BuilderInterface>
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
     *
     * @phpstan-param mvc_model_bind_types $bindTypes
     */
    public function setBindTypes( array bindTypes, bool merge = false) -> <BuilderInterface>
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
     * Sets the class used to hydrate rows that are not mapped to a model
     * (custom columns/joins). The class must be a subclass of
     * Phalcon\Mvc\Model\Row. Validation is performed by the underlying
     * Phalcon\Mvc\Model\Query when the query is built.
     */
    public function setResultsetRowClass(string resultsetRowClass) -> <BuilderInterface>
    {
        let this->resultsetRowClass = resultsetRowClass;

        return this;
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
        if !empty bindParams {
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
        if !empty bindTypes {
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
    protected function conditionBetween( string clause,  string operator,  string expr, var minimum, var maximum) -> <BuilderInterface>
    {
        var hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod;

        if unlikely (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
            throw new OperatorNotAvailable(operator);
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
     *
     * @phpstan-param array<array-key, mixed> $values
     */
    protected function conditionIn( string clause,  string operator,  string expr,  array values) -> <BuilderInterface>
    {
        var key, queryKey, value, bindKeys, bindParams, operatorMethod;
        int hiddenParam;

        if unlikely (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
            throw new OperatorNotAvailable(operator);
        }

        let operatorMethod = operator . clause;

        if empty values {
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
    protected function conditionNotBetween(string clause,  string operator,  string expr, var minimum, var maximum) -> <BuilderInterface>
    {
        var hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod;

        if unlikely (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
            throw new OperatorNotAvailable(operator);
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
     *
     * @phpstan-param array<array-key, mixed> $values
     */
    protected function conditionNotIn( string clause,  string operator,  string expr,  array values) -> <BuilderInterface>
    {
        var key, queryKey, value, bindKeys, bindParams, operatorMethod;
        int hiddenParam;

        if unlikely (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
            throw new OperatorNotAvailable(operator);
        }

        let operatorMethod = operator . clause;

        if empty values {
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
