
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Db\Column;
use Phalcon\Db\RawValue;
use Phalcon\Db\ResultInterface;
use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Di\DiInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Query\Exceptions\AmbiguousColumn;
use Phalcon\Mvc\Model\Query\Exceptions\AmbiguousJoinRelation;
use Phalcon\Mvc\Model\Query\Exceptions\BindParameterNotInPlaceholders;
use Phalcon\Mvc\Model\Query\Exceptions\BindTypeRequiresArray;
use Phalcon\Mvc\Model\Query\Exceptions\BindValueRequired;
use Phalcon\Mvc\Model\Query\Exceptions\ColumnNotInDomain;
use Phalcon\Mvc\Model\Query\Exceptions\ColumnNotInSelectedModels;
use Phalcon\Mvc\Model\Query\Exceptions\CorruptedAst;
use Phalcon\Mvc\Model\Query\Exceptions\CorruptedDeleteAst;
use Phalcon\Mvc\Model\Query\Exceptions\CorruptedInsertAst;
use Phalcon\Mvc\Model\Query\Exceptions\CorruptedSelectAst;
use Phalcon\Mvc\Model\Query\Exceptions\CorruptedUpdateAst;
use Phalcon\Mvc\Model\Query\Exceptions\DeleteMultipleNotSupported;
use Phalcon\Mvc\Model\Query\Exceptions\DuplicateAlias;
use Phalcon\Mvc\Model\Query\Exceptions\EmptyArrayPlaceholderValue;
use Phalcon\Mvc\Model\Query\Exceptions\InsertColumnCountMismatch;
use Phalcon\Mvc\Model\Query\Exceptions\InvalidCachedResultset;
use Phalcon\Mvc\Model\Query\Exceptions\InvalidCachingOptions;
use Phalcon\Mvc\Model\Query\Exceptions\InvalidColumnDefinition;
use Phalcon\Mvc\Model\Query\Exceptions\InvalidInjectedManager;
use Phalcon\Mvc\Model\Query\Exceptions\InvalidInjectedMetadata;
use Phalcon\Mvc\Model\Query\Exceptions\InvalidQueryCacheService;
use Phalcon\Mvc\Model\Query\Exceptions\InvalidResultsetClass;
use Phalcon\Mvc\Model\Query\Exceptions\JoinAliasAlreadyUsed;
use Phalcon\Mvc\Model\Query\Exceptions\JoinFieldCountMismatch;
use Phalcon\Mvc\Model\Query\Exceptions\MissingCacheKey;
use Phalcon\Mvc\Model\Query\Exceptions\MissingMetaData;
use Phalcon\Mvc\Model\Query\Exceptions\MissingModelAttribute;
use Phalcon\Mvc\Model\Query\Exceptions\MissingModelsManager;
use Phalcon\Mvc\Model\Query\Exceptions\MixedDatabaseSystems;
use Phalcon\Mvc\Model\Query\Exceptions\ModelsListNotLoaded;
use Phalcon\Mvc\Model\Query\Exceptions\ModelSourceNotFound;
use Phalcon\Mvc\Model\Query\Exceptions\MultipleSqlStatementsNotSupported;
use Phalcon\Mvc\Model\Query\Exceptions\NoModelForAlias;
use Phalcon\Mvc\Model\Query\Exceptions\PhqlColumnNotInMap;
use Phalcon\Mvc\Model\Query\Exceptions\ReadConnectionMissing;
use Phalcon\Mvc\Model\Query\Exceptions\RelationshipNotFound;
use Phalcon\Mvc\Model\Query\Exceptions\ResultsetClassNotFound;
use Phalcon\Mvc\Model\Query\Exceptions\ResultsetNonCacheable;
use Phalcon\Mvc\Model\Query\Exceptions\UnknownBindType;
use Phalcon\Mvc\Model\Query\Exceptions\UnknownColumnType;
use Phalcon\Mvc\Model\Query\Exceptions\UnknownJoinType;
use Phalcon\Mvc\Model\Query\Exceptions\UnknownModelOrAlias;
use Phalcon\Mvc\Model\Query\Exceptions\UnknownPhqlExpression;
use Phalcon\Mvc\Model\Query\Exceptions\UnknownPhqlExpressionType;
use Phalcon\Mvc\Model\Query\Exceptions\UnknownPhqlStatement;
use Phalcon\Mvc\Model\Query\Exceptions\UpdateMultipleNotSupported;
use Phalcon\Mvc\Model\Query\Exceptions\WriteConnectionMissing;
use Phalcon\Mvc\Model\Query\Status;
use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Query\StatusInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Db\DialectInterface;
use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Support\Settings;

/**
 * Phalcon\Mvc\Model\Query
 *
 * This class takes a PHQL intermediate representation and executes it.
 *
 *```php
 * $phql = "SELECT c.price*0.16 AS taxes, c.* FROM Cars AS c JOIN Brands AS b
 *          WHERE b.name = :name: ORDER BY c.name";
 *
 * $result = $manager->executeQuery(
 *     $phql,
 *     [
 *         "name" => "Lamborghini",
 *     ]
 * );
 *
 * foreach ($result as $row) {
 *     echo "Name: ",  $row->cars->name, "\n";
 *     echo "Price: ", $row->cars->price, "\n";
 *     echo "Taxes: ", $row->taxes, "\n";
 * }
 *
 * // with transaction
 * use Phalcon\Mvc\Model\Query;
 * use Phalcon\Mvc\Model\Transaction;
 *
 * // $di needs to have the service "db" registered for this to work
 * $di = Phalcon\Di\FactoryDefault::getDefault();
 *
 * $phql = 'SELECT * FROM robot';
 *
 * $myTransaction = new Transaction($di);
 * $myTransaction->begin();
 *
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->type = "mechanical";
 * $newRobot->name = "Astro Boy";
 * $newRobot->year = 1952;
 * $newRobot->save();
 *
 * $queryWithTransaction = new Query($phql, $di);
 * $queryWithTransaction->setTransaction($myTransaction);
 *
 * $resultWithEntries = $queryWithTransaction->execute();
 *
 * $queryWithOutTransaction = new Query($phql, $di);
 * $resultWithOutEntries = $queryWithTransaction->execute();
 *```
 */
class Query implements QueryInterface, InjectionAwareInterface
{
    /**
     * @var int
     */
    const TYPE_DELETE = 303;
    /**
     * @var int
     */
    const TYPE_INSERT = 306;
    /**
     * @var int
     */
    const TYPE_SELECT = 309;
    /**
     * @var int
     */
    const TYPE_UPDATE = 300;

    /**
     * @var array
     * TODO: Add default value, instead of null, also remove type check
     */
    protected ast;

    /**
     * @var array
     */
    protected bindParams = [];

    /**
     * @var array
     */
    protected bindTypes = [];

    /**
     * @var mixed|null
     */
    protected cache = null;

    /**
     * @var array|null
     */
    protected cacheOptions;

    /**
     * @var DiInterface|null
     */
    protected container = null;

    /**
     * @var bool
     */
    protected enableImplicitJoins;

    /**
     * @var array
     */
    protected intermediate;

    /**
     * @var array|null
     */
    protected static internalPhqlCache;

    /**
     * @var \Phalcon\Mvc\Model\ManagerInterface|null
     */
    protected manager = null;

    /**
     * @var \Phalcon\Mvc\Model\MetaDataInterface|null
     */
    protected metaData = null;

    /**
     * @var array
     */
    protected models = [];

    /**
     * @var array
     */
    protected modelsInstances = [];

    /**
     * @var int
     */
    protected nestingLevel = -1;

    /**
     * @var string|null
     */
    protected phql = null;

    /**
     * @var bool
     */
    protected sharedLock = false;

    /**
     * @var array
     */
    protected sqlAliases = [];

    /**
     * @var array
     */
    protected sqlAliasesModels = [];

    /**
     * @var array
     */
    protected sqlAliasesModelsInstances = [];

    /**
     * @var array
     */
    protected sqlColumnAliases = [];

    /**
     * @var array
     */
    protected sqlModelsAliases = [];

    /**
     * TransactionInterface so that the query can wrap a transaction
     * around batch updates and intermediate selects within the transaction.
     * however if a model got a transaction set inside it will use the local
     * transaction instead of this one
     *
     * @var TransactionInterface|null
     */
    protected transaction = null;

    /**
     * @var int|null
     */
    protected type;

    /**
     * @var bool
     */
    protected uniqueRow = false;

    /**
     * Phalcon\Mvc\Model\Query constructor
     *
     * @param string|null phql
     * @param DiInterface|null container
     * @param array options
     */
    public function __construct(string phql = null, <DiInterface> container = null, array options = [])
    {
        var enableImplicitJoins;

        let this->phql = phql;

        if typeof container == "object" {
            this->setDI(container);
        }

        if fetch enableImplicitJoins, options["enable_implicit_joins"] {
            let this->enableImplicitJoins = (enableImplicitJoins == true);
        } else {
            let this->enableImplicitJoins = Settings::get(
                "orm.enable_implicit_joins"
            );
        }

        let this->bindParams = [];
        let this->bindTypes = [];
    }

    /**
     * Sets the cache parameters of the query
     */
    public function cache(array cacheOptions) -> <QueryInterface>
    {
        let this->cacheOptions = cacheOptions;

        return this;
    }

    /**
     * Destroys the internal PHQL cache
     */
    public static function clean() -> void
    {
        let self::internalPhqlCache = [];
    }

    /**
     * Executes a parsed PHQL statement
     *
     * @return mixed
     */
    public function execute(array bindParams = [], array bindTypes = [])
    {
        var adapter, cache, cacheLifetime, cacheOptions, cacheService,
            defaultBindParams, defaultBindTypes, intermediate, key, lifetime,
            mergedParams, mergedTypes, preparedResult, result, type, uniqueRow;

        let uniqueRow    = this->uniqueRow,
            cacheOptions = this->cacheOptions;

        if cacheOptions !== null {
            if unlikely typeof cacheOptions != "array" {
                throw new InvalidCachingOptions();
            }

            /**
             * The user must set a cache key
             */
            if unlikely !fetch key, cacheOptions["key"] {
                throw new MissingCacheKey();
            }

            if !fetch cacheService, cacheOptions["service"] {
                let cacheService = "modelsCache";
            }

            let cache = this->container->getShared(cacheService);

            if unlikely (true !== is_a(cache,  "Phalcon\\Cache\\CacheInterface")) {
                throw new InvalidQueryCacheService();
            }

            /**
             * If the lifetime is different than the cache lifetime, assign
             * the cache lifetime to the current cache setting
             */
            let adapter       = cache->getAdapter();
            let cacheLifetime = adapter->getLifetime();

            if !fetch lifetime, cacheOptions["lifetime"] {
                let lifetime = cacheLifetime;
            }

            let result = false;
            if (cache->has(key)) {
                let result = cache->get(key);
            }

            if !empty result {
                if unlikely typeof result != "object" {
                    throw new InvalidCachedResultset();
                }

                result->setIsFresh(false);

                /**
                 * Check if only the first row must be returned
                 */
                if uniqueRow {
                    let preparedResult = result->getFirst();
                } else {
                    let preparedResult = result;
                }

                return preparedResult;
            }

            let this->cache = cache;
        }

        /**
         * The statement is parsed from its PHQL string or a previously
         * processed IR
         */
        let intermediate = this->parse();

        /**
         * Check for default bind parameters and merge them with the passed ones
         */
        let defaultBindParams = this->bindParams;
        let mergedParams = defaultBindParams + bindParams;

        /**
         * Check for default bind types and merge them with the passed ones
         */
        let defaultBindTypes = this->bindTypes;

        if typeof defaultBindTypes == "array" {
            let mergedTypes = defaultBindTypes + bindTypes;
        } else {
            let mergedTypes = bindTypes;
        }

        let type = this->type;

        switch type {
            case PHQL_T_SELECT:
                let result = this->executeSelect(
                    intermediate,
                    mergedParams,
                    mergedTypes
                );

                break;

            case PHQL_T_INSERT:
                let result = this->executeInsert(
                    intermediate,
                    mergedParams,
                    mergedTypes
                );

                break;

            case PHQL_T_UPDATE:
                let result = this->executeUpdate(
                    intermediate,
                    mergedParams,
                    mergedTypes
                );

                break;

            case PHQL_T_DELETE:
                let result = this->executeDelete(
                    intermediate,
                    mergedParams,
                    mergedTypes
                );

                break;

            default:
                throw new UnknownPhqlStatement(type);
        }

        /**
         * We store the resultset in the cache if any
         */
        if cacheOptions !== null {
            /**
             * Only PHQL SELECTs can be cached
             */
            if type != PHQL_T_SELECT {
                throw new ResultsetNonCacheable();
            }

            cache->set(key, result, lifetime);
        }

        /**
         * Check if only the first row must be returned
         */
        if uniqueRow {
            let preparedResult = result->getFirst();
        } else {
            let preparedResult = result;
        }

        return preparedResult;
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
     * Returns the current cache backend instance
     */
    public function getCache() -> <AdapterInterface>
    {
        return this->cache;
    }

    /**
     * Returns the current cache options
     */
    public function getCacheOptions() -> array
    {
        return this->cacheOptions;
    }

    /**
     * Returns the dependency injection container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Returns the intermediate representation of the PHQL statement
     */
    public function getIntermediate() -> array
    {
        return this->intermediate;
    }

    /**
     * Executes the query returning the first result
     */
    public function getSingleResult(array bindParams = [], array bindTypes = []) -> <ModelInterface>
    {
        /**
         * The query is already programmed to return just one row
         */
        if this->uniqueRow {
            return this->execute(bindParams, bindTypes);
        }

        return this->execute(bindParams, bindTypes)->getFirst();
    }

    /**
    * Returns an associative array with the SQL to be generated by the internal PHQL,
    * and arrays with bound parameters and their types (only works in SELECT statements).
    *
    *```php
    * [
    *     'sql' => 'SELECT * FROM parts WHERE robot = :robot',
    *     'bind' => ['robot' => 123],
    *     'bindTypes => ['robot' => 1] // 1 corresponds to int
    * ]
    *```
    */
    public function getSql() -> array
    {
        var intermediate;

        /**
         * The statement is parsed from its PHQL string or a previously
         * processed IR
         */
        let intermediate = this->parse();

        if this->type == PHQL_T_SELECT {
            return this->executeSelect(
                intermediate,
                this->bindParams,
                this->bindTypes,
                true
            );
        }

        throw new MultipleSqlStatementsNotSupported();
    }

    /**
     * @return TransactionInterface|null
     */
    public function getTransaction() -> <TransactionInterface> | null
    {
        return this->transaction;
    }

    /**
     * Gets the type of PHQL statement executed
     *
     * @return int
     */
    public function getType() -> int
    {
        return this->type;
    }

    /**
     * Check if the query is programmed to get only the first row in the
     * resultset
     *
     * @return bool
     */
    public function getUniqueRow() -> bool
    {
        return this->uniqueRow;
    }

    /**
     * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang
     * generating another intermediate representation that could be executed by
     * Phalcon\Mvc\Model\Query
     */
    public function parse() -> array
    {
        var intermediate, phql, ast, irPhql, uniqueId, type;

        let intermediate = this->intermediate;

        if typeof intermediate == "array" {
            return intermediate;
        }

        /**
         * This function parses the PHQL statement
         */
        let phql = this->phql,
            ast = Lang::parsePHQL(phql);

        let irPhql = null,
            uniqueId = null;

        if typeof ast == "array" {
            /**
             * Check if the prepared PHQL is already cached
             * Parsed ASTs have a unique id
             */
            if fetch uniqueId, ast["id"] {
                if fetch irPhql, self::internalPhqlCache[uniqueId] {
                    if typeof irPhql == "array" {
                        // Assign the type to the query
                        let this->type = ast["type"];

                        /**
                         * Refresh schema/source for every model referenced
                         * in the cached intermediate representation. The
                         * cache is keyed by the PHQL string only, so models
                         * that change their schema/source at runtime would
                         * otherwise keep producing SQL with the stale value
                         * baked in at first parse. See issue #17020.
                         */
                        return this->refreshSchemasInIntermediate(irPhql);
                    }
                }
            }

            /**
             * A valid AST must have a type
             */
            if fetch type, ast["type"] {
                let this->ast = ast,
                    this->type = type;

                switch type {
                    case PHQL_T_SELECT:
                        let irPhql = this->prepareSelect();
                        break;

                    case PHQL_T_INSERT:
                        let irPhql = this->prepareInsert();
                        break;

                    case PHQL_T_UPDATE:
                        let irPhql = this->prepareUpdate();
                        break;

                    case PHQL_T_DELETE:
                        let irPhql = this->prepareDelete();
                        break;

                    default:
                        throw new UnknownPhqlStatement(type, phql);
                }
            }
        }

        if unlikely typeof irPhql != "array" {
            throw new CorruptedAst();
        }

        /**
         * Store the prepared AST in the cache
         */
        if typeof uniqueId == "int" {
            let self::internalPhqlCache[uniqueId] = irPhql;
        }

        let this->intermediate = irPhql;

        return irPhql;
    }

    /**
     * Set default bind parameters
     */
    public function setBindParams(array! bindParams, bool merge = false) -> <QueryInterface>
    {
        var currentBindParams;

        if merge {
            let currentBindParams = this->bindParams;
            let this->bindParams = currentBindParams + bindParams;
        } else {
            let this->bindParams = bindParams;
        }

        return this;
    }

    /**
     * Set default bind parameters
     */
    public function setBindTypes(array! bindTypes, bool merge = false) -> <QueryInterface>
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
     * Sets the dependency injection container
     */
    public function setDI(<DiInterface> container) -> void
    {
        var manager, metaData;

        let manager = container->getShared("modelsManager");

        if unlikely typeof manager != "object" {
            throw new InvalidInjectedManager();
        }

        let metaData = container->getShared("modelsMetadata");

        if unlikely typeof metaData != "object" {
            throw new InvalidInjectedMetadata();
        }

        let this->manager = manager,
            this->metaData = metaData;

        let this->container = container;
    }

    /**
     * Allows to set the IR to be executed
     */
    public function setIntermediate(array! intermediate) -> <QueryInterface>
    {
        let this->intermediate = intermediate;

        return this;
    }

    /**
     * Set SHARED LOCK clause
     */
    public function setSharedLock(bool sharedLock = false) -> <QueryInterface>
    {
        let this->sharedLock = sharedLock;

        return this;
    }

    /**
     * allows to wrap a transaction around all queries
     */
    public function setTransaction(<TransactionInterface> transaction) -> <QueryInterface>
    {
        let this->transaction = transaction;

        return this;
    }

    /**
     * Sets the type of PHQL statement to be executed
     */
    public function setType(int type) -> <QueryInterface>
    {
        let this->type = type;

        return this;
    }

    /**
     * Tells to the query if only the first row in the resultset must be
     * returned
     */
    public function setUniqueRow(bool uniqueRow) -> <QueryInterface>
    {
        let this->uniqueRow = uniqueRow;

        return this;
    }

    /**
     * Executes the DELETE intermediate representation producing a
     * Phalcon\Mvc\Model\Query\Status
     */
    final protected function executeDelete(array intermediate, array bindParams, array bindTypes) -> <StatusInterface>
    {
        var models, modelName, model, records, connection, record, exception;

        let models = intermediate["models"];

        if unlikely isset models[1] {
            throw new DeleteMultipleNotSupported();
        }

        let modelName = models[0];

        /**
         * Load the model from the modelsManager or from the modelsInstances property
         */
        if !fetch model, this->modelsInstances[modelName] {
            let model = this->manager->load(modelName);
        }

        /**
         * Get the records to be deleted
         */
        let records = this->getRelatedRecords(
            model,
            intermediate,
            bindParams,
            bindTypes
        );

        /**
         * If there are no records to delete we return success
         */
        if !count(records) {
            return new Status(true);
        }

        let connection = this->getWriteConnection(
            model,
            intermediate,
            bindParams,
            bindTypes
        );

        /**
         * Create a transaction in the write connection
         */
        connection->begin();
        records->rewind();

        while records->valid() {
            try {
                let record = records->current();

                /**
                 * We delete every record found
                 */
                if !record->delete() {
                    /**
                     * Rollback the transaction
                     */
                    connection->rollback();

                    return new Status(false, record);
                }

                records->next();
            } catch \PDOException, exception {
                connection->rollback();

                throw exception;
            }
        }

        /**
         * Commit the transaction
         */
        connection->commit();

        /**
         * Create a status to report the deletion status
         */
        return new Status(true);
    }


    /**
     * Executes the INSERT intermediate representation producing a
     * Phalcon\Mvc\Model\Query\Status
     */
    final protected function executeInsert(array intermediate, array bindParams, array bindTypes) -> <StatusInterface>
    {
        var modelName, manager, connection, metaData, attributes, fields,
            columnMap, dialect, insertValues, number, value, model, values,
            exprValue, insertValue, wildcard, fieldName, attributeName,
            insertModel;
        bool automaticFields;

        let modelName = intermediate["model"];

        let manager = this->manager;

        if !fetch model, this->modelsInstances[modelName] {
            let model = manager->load(modelName);
        }

        let connection = this->getWriteConnection(
            model,
            intermediate,
            bindParams,
            bindTypes
        );

        let metaData = this->metaData,
            attributes = metaData->getAttributes(model);

        let automaticFields = false;

        /**
         * The "fields" index may already have the fields to be used in the
         * query
         */
        if !fetch fields, intermediate["fields"] {
            let automaticFields = true,
                fields = attributes;

            if Settings::get("orm.column_renaming") {
                let columnMap = metaData->getColumnMap(model);
            } else {
                let columnMap = null;
            }
        }

        let values = intermediate["values"];

        /**
         * The number of calculated values must be equal to the number of fields
         * in the model
         */
        if unlikely count(fields) != count(values) {
            throw new InsertColumnCountMismatch();
        }

        /**
         * Get the dialect to resolve the SQL expressions
         */
        let dialect = connection->getDialect();

        let insertValues = [];
        for number, value in values {
            let exprValue = value["value"];

            switch value["type"] {

                case PHQL_T_STRING:
                case PHQL_T_INTEGER:
                case PHQL_T_DOUBLE:
                    let insertValue = dialect->getSqlExpression(exprValue);
                    break;

                case PHQL_T_NULL:
                    let insertValue = null;
                    break;

                case PHQL_T_NPLACEHOLDER:
                case PHQL_T_SPLACEHOLDER:
                case PHQL_T_BPLACEHOLDER:
                    let wildcard = str_replace(
                        ":",
                        "",
                        dialect->getSqlExpression(exprValue)
                    );

                    if unlikely !fetch insertValue, bindParams[wildcard] {
                        throw new BindParameterNotInPlaceholders(wildcard);
                    }

                    break;

                default:
                    let insertValue = new RawValue(
                        dialect->getSqlExpression(exprValue)
                    );

                    break;
            }

            let fieldName = fields[number];

            /**
             * If the user didn't define a column list we assume all the model's
             * attributes as columns
             */
            if automaticFields && typeof columnMap == "array" {
                if unlikely !fetch attributeName, columnMap[fieldName] {
                    throw new PhqlColumnNotInMap(fieldName);
                }
            } else {
                let attributeName = fieldName;
            }

            let insertValues[attributeName] = insertValue;
        }

        /**
         * Get model from the Models Manager
         */
        let insertModel = manager->load(modelName);

        insertModel->assign(insertValues);

        /**
         * Call 'create' to ensure that an insert is performed
         * Return the insert status
         */
        return new Status(
            insertModel->create(),
            insertModel
        );
    }

    /**
     * Executes the SELECT intermediate representation producing a
     * Phalcon\Mvc\Model\Resultset
     */
    final protected function executeSelect(array intermediate, array bindParams, array bindTypes, bool simulate = false) -> <ResultsetInterface> | array
    {
        var manager, modelName, models, model, connection, connectionTypes,
            columns, column, selectColumns, simpleColumnMap, metaData,
            aliasCopy, sqlColumn, attributes, instance, columnMap, attribute,
            columnAlias, sqlAlias, dialect, sqlSelect, bindCounts, processed,
            wildcard, value, processedTypes, typeWildcard, result, resultData,
            cache, resultObject, columns1, typesColumnMap, wildcardValue,
            resultsetClassName;
        bool haveObjects, haveScalars, isComplex, isSimpleStd,
            isKeepingSnapshots;
        int numberObjects;

        let manager = this->manager;

        /**
         * Get a database connection
         */
        let connectionTypes = [];
        let models = intermediate["models"];

        for modelName in models {
            // Load model if it is not loaded
            if !fetch model, this->modelsInstances[modelName] {
                let model = manager->load(modelName),
                    this->modelsInstances[modelName] = model;
            }

            if isset intermediate["forUpdate"] && intermediate["forUpdate"] {
                let connection = this->getWriteConnection(
                    model,
                    intermediate,
                    bindParams,
                    bindTypes
                );
            } else {
                let connection = this->getReadConnection(
                    model,
                    intermediate,
                    bindParams,
                    bindTypes
                );
            }

            if typeof connection == "object" {
                // More than one type of connection is not allowed
                let connectionTypes[connection->getType()] = true;

                if unlikely count(connectionTypes) == 2 {
                    throw new MixedDatabaseSystems();
                }
            }
        }

        let columns = intermediate["columns"];

        let haveObjects = false,
            haveScalars = false,
            isComplex = false;

        // Check if the resultset have objects and how many of them have
        let numberObjects = 0;
        let columns1 = columns;

        for column in columns {
            if unlikely typeof column != "array" {
                throw new InvalidColumnDefinition();
            }

            if column["type"] == "scalar" {
                if !isset column["balias"] {
                    let isComplex = true;
                }

                let haveScalars = true;
            } else {
                let haveObjects = true,
                    numberObjects++;
            }
        }

        // Check if the resultset to return is complex or simple
        if !isComplex {
            if haveObjects {
                if haveScalars {
                    let isComplex = true;
                } else {
                    if numberObjects == 1 {
                        let isSimpleStd = false;
                    } else {
                        let isComplex = true;
                    }
                }
            } else {
                let isSimpleStd = true;
            }
        }

        // Processing selected columns
        let instance = null,
            selectColumns = [],
            simpleColumnMap = [],
            metaData = this->metaData;

        for aliasCopy, column in columns {
            let sqlColumn = column["column"];

            // Complete objects are treated in a different way
            if column["type"] == "object" {
                let modelName = column["model"];

                /**
                 * Base instance
                 */
                if !fetch instance, this->modelsInstances[modelName] {
                    let instance = manager->load(modelName),
                        this->modelsInstances[modelName] = instance;
                }

                let attributes = metaData->getAttributes(instance);

                if isComplex {
                    /**
                     * If the resultset is complex we open every model into
                     * their columns
                     */
                    if Settings::get("orm.column_renaming") {
                        let columnMap = metaData->getColumnMap(instance);
                    } else {
                        let columnMap = null;
                    }

                    // Add every attribute in the model to the generated select
                    for attribute in attributes {
                        let selectColumns[] = [
                            attribute,
                            sqlColumn,
                            "_" . sqlColumn . "_" . attribute
                        ];
                    }

                    /**
                     * We cache required meta-data to make its future access
                     * faster
                     */
                    let columns1[aliasCopy]["instance"]   = instance,
                        columns1[aliasCopy]["attributes"] = attributes,
                        columns1[aliasCopy]["columnMap"]  = columnMap;

                    // Check if the model keeps snapshots
                    let isKeepingSnapshots = (bool) manager->isKeepingSnapshots(instance);
                    if isKeepingSnapshots {
                        let columns1[aliasCopy]["keepSnapshots"] = isKeepingSnapshots;
                    }
                } else {
                    /**
                     * Query only the columns that are registered as attributes
                     * in the metaData
                     */
                    for attribute in attributes {
                        let selectColumns[] = [attribute, sqlColumn];
                    }
                }
            } else {
                /**
                 * Create an alias if the column does not have one
                 */
                if typeof aliasCopy == "int" {
                    let columnAlias = [sqlColumn, null];
                } else {
                    let columnAlias = [sqlColumn, null, aliasCopy];
                }

                let selectColumns[] = columnAlias;
            }

            /**
             * Simulate a column map
             */
            if !isComplex && isSimpleStd {
                if fetch sqlAlias, column["sqlAlias"] {
                    let simpleColumnMap[sqlAlias] = aliasCopy;
                } else {
                    let simpleColumnMap[aliasCopy] = aliasCopy;
                }
            }
        }

        let processed               = [],
            bindCounts              = [],
            intermediate["columns"] = selectColumns;

        /**
         * Replace the placeholders
         */
        for wildcard, value in bindParams {
            if typeof wildcard == "integer" {
                let wildcardValue = ":" . wildcard;
            } else {
                let wildcardValue = wildcard;
            }

            let processed[wildcardValue] = value;

            if typeof value == "array" {
                let bindCounts[wildcardValue] = count(value);
            }
        }

        let processedTypes = [];

        /**
         * Replace the bind Types
         */
        for typeWildcard, value in bindTypes {
            if typeof typeWildcard == "integer" {
                let processedTypes[":" . typeWildcard] = value;
            } else {
                let processedTypes[typeWildcard] = value;
            }
        }

        if count(bindCounts) {
            let intermediate["bindCounts"] = bindCounts;
        }

        /**
         * The corresponding SQL dialect generates the SQL statement based
         * accordingly with the database system
         */
        let dialect   = connection->getDialect(),
            sqlSelect = dialect->select(intermediate);

        if this->sharedLock {
            let sqlSelect = dialect->sharedLock(sqlSelect);
        }

        /**
         * Embed RawValue bind params directly in the SQL instead of passing
         * them to PDO, which would quote them as strings.
         */
        for wildcard, value in processed {
            if typeof value == "object" && value instanceof RawValue {
                if substr(wildcard, 0, 1) === ":" {
                    let sqlSelect = str_replace(wildcard, (string) value, sqlSelect);
                } else {
                    let sqlSelect = str_replace(":" . wildcard, (string) value, sqlSelect);
                }

                unset processed[wildcard];
                unset processedTypes[wildcard];
            }
        }

        /**
         * Return the SQL to be executed instead of execute it
         */
        if simulate {
            return [
                "sql"       : sqlSelect,
                "bind"      : processed,
                "bindTypes" : processedTypes
            ];
        }

        /**
         * Execute the query
         */
        let result = connection->query(sqlSelect, processed, processedTypes);

        /**
         * Check if the query has data
         *
         * Previous if [leaving here on purpose]:
         * if result instanceof ResultInterface && result->numRows() {
         */
        if result instanceof ResultInterface {
            let resultData = result;
        } else {
            let resultData = null;
        }

        /**
         * Choose a resultset type
         */
        let cache = this->cache;

        if !isComplex {
            /**
             * Select the base object
             */
            if isSimpleStd {
                /**
                 * If the result is a simple standard object use an
                 * Phalcon\Mvc\Model\Row as base
                 */
                let resultObject = new Row();

                /**
                 * Standard objects can't keep snapshots
                 */
                let isKeepingSnapshots = false;
            } else {
                if typeof instance == "object" {
                    let resultObject = instance;
                } else {
                    let resultObject = model;
                }

                /**
                 * Get the column map
                 */
                if !Settings::get("orm.cast_on_hydrate") {
                    let simpleColumnMap = metaData->getColumnMap(resultObject);
                } else {
                    let columnMap      = metaData->getColumnMap(resultObject),
                        typesColumnMap = metaData->getDataTypes(resultObject);

                    if columnMap === null {
                        let simpleColumnMap = [];

                        for attribute in metaData->getAttributes(resultObject) {
                            let simpleColumnMap[attribute] = [
                                attribute,
                                typesColumnMap[attribute]
                            ];
                        }
                    } else {
                        let simpleColumnMap = [];

                        for column, attribute in columnMap {
                            let simpleColumnMap[column] = [
                                attribute,
                                typesColumnMap[column]
                            ];
                        }
                    }
                }

                /**
                 * Check if the model keeps snapshots
                 */
                let isKeepingSnapshots = (bool) manager->isKeepingSnapshots(resultObject);
            }

            if resultObject instanceof ModelInterface && method_exists(resultObject, "getResultsetClass") {
                let resultsetClassName = (<ModelInterface> resultObject)->getResultsetClass();

                if resultsetClassName {
                    if unlikely !class_exists(resultsetClassName) {
                        throw new ResultsetClassNotFound(resultsetClassName);
                    }

                    if unlikely !is_subclass_of(resultsetClassName, "Phalcon\\Mvc\\Model\\ResultsetInterface") {
                        throw new InvalidResultsetClass(resultsetClassName);
                    }

                    return create_instance_params(
                        resultsetClassName,
                        [
                            simpleColumnMap,
                            resultObject,
                            resultData,
                            cache,
                            isKeepingSnapshots
                        ]
                    );
                }
            }

            /**
             * Simple resultsets contains only complete objects
             */
            return new Simple(
                simpleColumnMap,
                resultObject,
                resultData,
                cache,
                isKeepingSnapshots
            );
        }

        /**
         * Complex resultsets may contain complete objects and scalars
         */
        return new Complex(
            columns1,
            resultData,
            cache
        );
    }

    /**
     * Executes the UPDATE intermediate representation producing a
     * Phalcon\Mvc\Model\Query\Status
     */
    final protected function executeUpdate(array intermediate, array bindParams, array bindTypes) -> <StatusInterface>
    {
        var models, modelName, model, connection, dialect, fields, values,
            updateValues, fieldName, value, selectBindParams, selectBindTypes,
            number, field, records, exprValue, updateValue, wildcard, record,
            exception;

        let models = intermediate["models"];

        if unlikely isset models[1] {
            throw new UpdateMultipleNotSupported();
        }

        let modelName = models[0];

        /**
         * Load the model from the modelsManager or from the modelsInstances
         * property
         */
        if !fetch model, this->modelsInstances[modelName] {
            let model = this->manager->load(modelName);
        }

        let connection = this->getWriteConnection(
            model,
            intermediate,
            bindParams,
            bindTypes
        );

        let dialect = connection->getDialect();

        let fields = intermediate["fields"],
            values = intermediate["values"];

        /**
         * updateValues is applied to every record
         */
        let updateValues = [];

        /**
         * If a placeholder is unused in the update values, we assume that it's
         * used in the SELECT
         */
        let selectBindParams = bindParams,
            selectBindTypes = bindTypes;

        for number, field in fields {
            let value = values[number],
                exprValue = value["value"];

            if isset field["balias"] {
                let fieldName = field["balias"];
            } else {
                let fieldName = field["name"];
            }

            switch value["type"] {
                case PHQL_T_STRING:
                case PHQL_T_INTEGER:
                case PHQL_T_DOUBLE:
                    let updateValue = dialect->getSqlExpression(exprValue);
                    break;

                case PHQL_T_NULL:
                    let updateValue = null;
                    break;

                case PHQL_T_NPLACEHOLDER:
                case PHQL_T_SPLACEHOLDER:
                case PHQL_T_BPLACEHOLDER:
                    let wildcard = str_replace(
                        ":",
                        "",
                        dialect->getSqlExpression(exprValue)
                    );

                    if unlikely !fetch updateValue, bindParams[wildcard] {
                        throw new BindParameterNotInPlaceholders(wildcard);
                    }

                    unset selectBindParams[wildcard];
                    unset selectBindTypes[wildcard];

                    break;

                default:
                    let updateValue = new RawValue(
                        dialect->getSqlExpression(exprValue)
                    );

                    break;
            }

            let updateValues[fieldName] = updateValue;
        }

        /**
         * We need to query the records related to the update
         */
        let records = this->getRelatedRecords(
            model,
            intermediate,
            selectBindParams,
            selectBindTypes
        );

        /**
         * If there are no records to apply the update we return success
         */
        if !count(records) {
            return new Status(true);
        }

        let connection = this->getWriteConnection(
            model,
            intermediate,
            bindParams,
            bindTypes
        );

        /**
         * Create a transaction in the write connection
         */
        connection->begin();

        records->rewind();

        while records->valid() {
            try {
                let record = records->current();

                record->assign(updateValues);

                /**
                 * We apply the executed values to every record found
                 */
                if !record->update() {
                    /**
                     * Rollback the transaction on failure
                     */
                    connection->rollback();

                    return new Status(false, record);
                }

                records->next();
            } catch \PDOException, exception {
                connection->rollback();

                throw exception;
            }
        }

        /**
         * Commit transaction on success
         */
        connection->commit();

        return new Status(true);
    }

    /**
     * Resolves an expression in a single call argument
     */
    final protected function getCallArgument(array! argument) -> array
    {
        if argument["type"] == PHQL_T_STARALL {
            return [
                "type": "all"
            ];
        }

        return this->getExpression(argument);
    }

    /**
     * Resolves an expression in a single call argument
     */
    final protected function getCaseExpression(array! expr) -> array
    {
        var whenClauses, whenExpr;

        let whenClauses = [];

        for whenExpr in expr["right"] {
            if isset whenExpr["right"] {
                let whenClauses[] = [
                    "type": "when",
                    "expr": this->getExpression(whenExpr["left"]),
                    "then": this->getExpression(whenExpr["right"])
                ];
            } else {
                let whenClauses[] = [
                    "type": "else",
                    "expr": this->getExpression(whenExpr["left"])
                ];
            }
        }

        return [
            "type"        : "case",
            "expr"        : this->getExpression(expr["left"]),
            "when-clauses": whenClauses
        ];
    }

    /**
     * Resolves an expression from its intermediate code into an array
     */
    final protected function getExpression(array expr, bool quoting = true) -> array
    {
        var exprType, exprLeft, exprRight, left = null, right = null,
            listItems, exprListItem, exprReturn, value, escapedValue,
            exprValue, valueParts, name, bindType, bind;
        bool tempNotQuoting;

        if fetch exprType, expr["type"] {
            let tempNotQuoting = true;

            if exprType != PHQL_T_CASE {
                /**
                 * Resolving the left part of the expression if any
                 */
                if fetch exprLeft, expr["left"] {
                    let left = this->getExpression(exprLeft, tempNotQuoting);
                }

                /**
                 * Resolving the right part of the expression if any
                 */
                if fetch exprRight, expr["right"] {
                    let right = this->getExpression(exprRight, tempNotQuoting);
                }
            }

            /**
             * Every node in the AST has a unique integer type
             */
            switch exprType {
                case PHQL_T_LESS:
                    let exprReturn = [
                            "type":  "binary-op",
                            "op":    "<",
                            "left":  left,
                            "right": right
                        ];

                    break;

                case PHQL_T_EQUALS:
                    let exprReturn = [
                            "type":  "binary-op",
                            "op":    "=",
                            "left":  left,
                            "right": right
                        ];

                    break;

                case PHQL_T_GREATER:
                    let exprReturn = [
                            "type":  "binary-op",
                            "op":    ">",
                            "left":  left,
                            "right": right
                        ];

                    break;

                case PHQL_T_NOTEQUALS:
                    let exprReturn = [
                            "type":  "binary-op",
                            "op":    "<>",
                            "left":  left,
                            "right": right
                        ];

                    break;

                case PHQL_T_LESSEQUAL:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "<=",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_GREATEREQUAL:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    ">=",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_AND:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "AND",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OR:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "OR",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_MATCHES:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "@@",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_CONTAINS:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "@>",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_CONTAINED:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "<@",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_OVERLAPS:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "&&",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_CONCAT:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "||",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_JSON_GET:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "->",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_JSON_GET_TEXT:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "->>",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_JSON_PATH:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "#>",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_OP_JSON_PATH_TEXT:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "#>>",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_QUALIFIED:
                    let exprReturn = this->getQualified(expr);
                    break;

                case PHQL_T_ADD:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "+",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_SUB:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "-",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_MUL:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "*",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_DIV:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "/",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_MOD:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "%",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_BITWISE_AND:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "&",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_BITWISE_OR:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "|",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_ENCLOSED:
                case PHQL_T_SUBQUERY:
                    let exprReturn = [
                        "type": "parentheses",
                        "left": left
                    ];

                    break;

                case PHQL_T_MINUS:
                    let exprReturn = [
                        "type":  "unary-op",
                        "op":    "-",
                        "right": right
                    ];

                    break;

                case PHQL_T_INTEGER:
                case PHQL_T_DOUBLE:
                case PHQL_T_HINTEGER:
                    let exprReturn = [
                        "type":  "literal",
                        "value": expr["value"]
                    ];

                    break;

                case PHQL_T_TRUE:
                    let exprReturn = [
                        "type": "literal",
                        "value": "TRUE"
                    ];

                    break;

                case PHQL_T_FALSE:
                    let exprReturn = [
                        "type":  "literal",
                        "value": "FALSE"
                    ];

                    break;

                case PHQL_T_STRING:
                    let value = expr["value"];

                    if quoting {
                        /**
                         * Check if static literals have single quotes and
                         * escape them
                         */
                        if memstr(value, "'") {
                            let escapedValue = phalcon_orm_singlequotes(value);
                        } else {
                            let escapedValue = value;
                        }

                        let exprValue = "'" . escapedValue . "'";
                    } else {
                        let exprValue = value;
                    }

                    let exprReturn = [
                        "type":  "literal",
                        "value": exprValue
                    ];

                    break;

                case PHQL_T_NPLACEHOLDER:
                    let exprReturn = [
                        "type":  "placeholder",
                        "value": str_replace("?", ":", expr["value"])
                    ];

                    break;

                case PHQL_T_SPLACEHOLDER:
                    let exprReturn = [
                        "type":  "placeholder",
                        "value": ":" . expr["value"]
                    ];

                    break;

                case PHQL_T_BPLACEHOLDER:
                    let value = expr["value"];

                    if memstr(value, ":") {
                        let valueParts = explode(":", value),
                            name = valueParts[0],
                            bindType = valueParts[1];

                        switch bindType {

                            case "str":
                                let this->bindTypes[name] = Column::BIND_PARAM_STR;

                                let exprReturn = [
                                    "type":  "placeholder",
                                    "value": ":" . name
                                ];

                                break;

                            case "int":
                                let this->bindTypes[name] = Column::BIND_PARAM_INT;

                                let exprReturn = [
                                    "type":  "placeholder",
                                    "value": ":" . name
                                ];

                                break;

                            case "double":
                                let this->bindTypes[name] = Column::BIND_PARAM_DECIMAL;

                                let exprReturn = [
                                    "type":  "placeholder",
                                    "value": ":" . name
                                ];

                                break;

                            case "bool":
                                let this->bindTypes[name] = Column::BIND_PARAM_BOOL;

                                let exprReturn = [
                                    "type":  "placeholder",
                                    "value": ":" . name
                                ];

                                break;

                            case "blob":
                                let this->bindTypes[name] = Column::BIND_PARAM_BLOB;

                                let exprReturn = [
                                    "type":  "placeholder",
                                    "value": ":" . name
                                ];

                                break;

                            case "null":
                                let this->bindTypes[name] = Column::BIND_PARAM_NULL;

                                let exprReturn = [
                                    "type":  "placeholder",
                                    "value": ":" . name
                                ];

                                break;

                            case "array":
                            case "array-str":
                            case "array-int":
                                if unlikely !fetch bind, this->bindParams[name] {
                                    throw new BindValueRequired(name);
                                }

                                if unlikely typeof bind != "array" {
                                    throw new BindTypeRequiresArray(name);
                                }

                                if unlikely count(bind) < 1 {
                                    throw new EmptyArrayPlaceholderValue(name);
                                }

                                let exprReturn = [
                                    "type":     "placeholder",
                                    "value":    ":" . name,
                                    "rawValue": name,
                                    "times":    count(bind)
                                ];

                                break;

                            default:
                                throw new UnknownBindType(bindType);
                        }
                    } else {
                        let exprReturn = [
                            "type":  "placeholder",
                            "value": ":" . value
                        ];
                    }

                    break;

                case PHQL_T_NULL:
                    let exprReturn = [
                        "type":  "literal",
                        "value": "NULL"
                    ];

                    break;

                case PHQL_T_LIKE:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "LIKE",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_NLIKE:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "NOT LIKE",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_ILIKE:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "ILIKE",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_NILIKE:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "NOT ILIKE",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_NOT:
                    let exprReturn = [
                        "type":  "unary-op",
                        "op":    "NOT ",
                        "right": right
                    ];

                    break;

                case PHQL_T_ISNULL:
                    let exprReturn = [
                        "type":  "unary-op",
                        "op":    " IS NULL",
                        "left":  left
                    ];

                    break;

                case PHQL_T_ISNOTNULL:
                    let exprReturn = [
                        "type":  "unary-op",
                        "op":    " IS NOT NULL",
                        "left":  left
                    ];

                    break;

                case PHQL_T_IN:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "IN",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_NOTIN:
                    let exprReturn = [
                        "type":  "binary-op",
                        "op":    "NOT IN",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_EXISTS:
                    let exprReturn = [
                        "type":  "unary-op",
                        "op":    "EXISTS",
                        "right": right
                    ];

                    break;

                case PHQL_T_DISTINCT:
                    let exprReturn = [
                        "type": "unary-op",
                        "op":   "DISTINCT ",
                        "right": right
                    ];

                    break;

                case PHQL_T_BETWEEN_NOT:
                    let exprReturn = [
                        "type": "binary-op",
                        "op":   "NOT BETWEEN",
                        "left": left,
                        "right": right
                    ];

                    break;

                case PHQL_T_BETWEEN:
                    let exprReturn = [
                        "type": "binary-op",
                        "op":   "BETWEEN",
                        "left": left,
                        "right": right
                    ];

                    break;

                case PHQL_T_AGAINST:
                    let exprReturn = [
                        "type": "binary-op",
                        "op":   "AGAINST",
                        "left": left,
                        "right": right
                    ];

                    break;

                case PHQL_T_CAST:
                    let exprReturn = [
                        "type":  "cast",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_CONVERT:
                    let exprReturn = [
                        "type":  "convert",
                        "left":  left,
                        "right": right
                    ];

                    break;

                case PHQL_T_RAW_QUALIFIED:
                    let exprReturn = [
                        "type":  "literal",
                        "value": expr["name"]
                    ];

                    break;

                case PHQL_T_FCALL:
                    let exprReturn = this->getFunctionCall(expr);

                    break;

                case PHQL_T_CASE:
                    let exprReturn = this->getCaseExpression(expr);

                    break;

                case PHQL_T_SELECT:
                    let exprReturn = [
                        "type":  "select",
                        "value": this->prepareSelect(expr, true)
                    ];

                    break;

                default:
                    throw new UnknownPhqlExpressionType(exprType);
            }

            return exprReturn;
        }

        /**
         * It's a qualified column
         */
        if isset expr["domain"] {
            return this->getQualified(expr);
        }

        /**
         * If the expression does not have a type it's a list of nodes
         */
        if isset expr[0] {
            let listItems = [];

            for exprListItem in expr {
                let listItems[] = this->getExpression(exprListItem);
            }

            return [
                "type": "list",
                listItems
            ];
        }

        throw new UnknownPhqlExpression();
    }

    /**
     * Resolves an expression in a single call argument
     */
    final protected function getFunctionCall(array! expr) -> array
    {
        var arguments, argument;
        array functionArgs;
        int distinct;

        if fetch arguments, expr["arguments"] {
            if isset expr["distinct"] {
                let distinct = 1;
            } else {
                let distinct = 0;
            }

            if isset arguments[0] {
                // There are more than one argument
                let functionArgs = [];

                for argument in arguments {
                    let functionArgs[] = this->getCallArgument(argument);
                }
            } else {
                // There is only one argument
                let functionArgs = [
                    this->getCallArgument(arguments)
                ];
            }

            if distinct {
                return [
                    "type"     : "functionCall",
                    "name"     : expr["name"],
                    "arguments": functionArgs,
                    "distinct" : distinct
                ];
            } else {
                return [
                    "type"     : "functionCall",
                    "name"     : expr["name"],
                    "arguments": functionArgs
                ];
            }
        }

        return [
            "type": "functionCall",
            "name": expr["name"]
        ];
    }

    /**
     * Returns a processed group clause for a SELECT statement
     */
    final protected function getGroupClause(array! group) -> array
    {
        var groupItem;
        array groupParts;

        if isset group[0] {
            /**
             * The select is grouped by several columns
             */
            let groupParts = [];

            for groupItem in group {
                let groupParts[] = this->getExpression(groupItem);
            }
        } else {
            let groupParts = [
                this->getExpression(group)
            ];
        }

        return groupParts;
    }

    /**
     * Resolves a JOIN clause checking if the associated models exist
     */
    final protected function getJoin(<ManagerInterface> manager, array join) -> array
    {
        var qualified, modelName, source, model, schema;

        if fetch qualified, join["qualified"] {
            if qualified["type"] == PHQL_T_QUALIFIED {
                let modelName = qualified["name"];

                let model = manager->load(modelName),
                    source = model->getSource(),
                    schema = model->getSchema();

                return [
                    "schema"   : schema,
                    "source"   : source,
                    "modelName": modelName,
                    "model"    : model
                ];
            }
        }

        throw new CorruptedSelectAst();
    }

    /**
     * Resolves a JOIN type
     */
    final protected function getJoinType(array join) -> string
    {
        var type;

        if unlikely !fetch type, join["type"] {
            throw new CorruptedSelectAst();
        }

        switch type {
            case PHQL_T_INNERJOIN:
                return "INNER";

            case PHQL_T_LEFTJOIN:
                return "LEFT";

            case PHQL_T_RIGHTJOIN:
                return "RIGHT";

            case PHQL_T_CROSSJOIN:
                return "CROSS";

            case PHQL_T_FULLJOIN:
                return "FULL OUTER";
        }

        throw new UnknownJoinType(type, this->phql);
    }

    /**
     * Processes the JOINs in the query returning an internal representation for
     * the database dialect
     */
    final protected function getJoins(array select) -> array
    {
        var models, sqlAliases, sqlAliasesModels, sqlModelsAliases,
            sqlAliasesModelsInstances, modelsInstances, fromModels,
            manager, selectJoins, joinItem, joins, joinData, schema, source,
            model, realModelName, completeSource, joinType, aliasExpr, alias,
            joinAliasName, joinExpr, fromModelName, joinAlias, joinModel,
            joinSource, preCondition, modelNameAlias, relation, relations,
            modelAlias, sqlJoin, sqlJoinItem, selectTables, tables, tableItem;
        array sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition,
            joinPrepared;

        let models = this->models,
            sqlAliases = this->sqlAliases,
            sqlAliasesModels = this->sqlAliasesModels,
            sqlModelsAliases = this->sqlModelsAliases,
            sqlAliasesModelsInstances = this->sqlAliasesModelsInstances,
            modelsInstances = this->modelsInstances,
            fromModels = models;

        let sqlJoins = [],
            joinModels = [],
            joinSources = [],
            joinTypes = [],
            joinPreCondition = [],
            joinPrepared = [];

        let manager = this->manager;

        let tables = select["tables"];

        if !isset tables[0] {
            let selectTables = [tables];
        } else {
            let selectTables = tables;
        }

        let joins = select["joins"];

        if !isset joins[0] {
            let selectJoins = [joins];
        } else {
            let selectJoins = joins;
        }

        for joinItem in selectJoins {

            /**
             * Check join alias
             */
            let joinData = this->getJoin(manager, joinItem),
                source = joinData["source"],
                schema = joinData["schema"],
                model = joinData["model"],
                realModelName = joinData["modelName"],
                completeSource = [source, schema];

            /**
             * Check join alias
             */
            let joinType = this->getJoinType(joinItem);

            /**
             * Process join alias
             */
            if fetch aliasExpr, joinItem["alias"] {
                let alias = aliasExpr["name"];

                /**
                 * Check if alias is unique
                 */
                if unlikely isset joinModels[alias] {
                    throw new JoinAliasAlreadyUsed(alias, this->phql);
                }

                /**
                 * Add the alias to the source
                 */
                let completeSource[] = alias;

                /**
                 * Set the join type
                 */
                let joinTypes[alias] = joinType;

                /**
                 * Update alias: alias
                 */
                let sqlAliases[alias] = alias;

                /**
                 * Update model: alias
                 */
                let joinModels[alias] = realModelName;

                /**
                 * Update model: alias
                 */
                let sqlModelsAliases[realModelName] = alias;

                /**
                 * Update model: model
                 */
                let sqlAliasesModels[alias] = realModelName;

                /**
                 * Update alias: model
                 */
                let sqlAliasesModelsInstances[alias] = model;

                /**
                 * Update model: alias
                 */
                let models[realModelName] = alias;

                /**
                 * Complete source related to a model
                 */
                let joinSources[alias] = completeSource;

                /**
                 * Complete source related to a model
                 */
                let joinPrepared[alias] = joinItem;
            } else {
                /**
                 * Check if alias is unique
                 */
                if unlikely isset joinModels[realModelName] {
                    throw new JoinAliasAlreadyUsed(realModelName, this->phql);
                }

                /**
                 * Set the join type
                 */
                let joinTypes[realModelName] = joinType;

                /**
                 * Update model: source
                 */
                let sqlAliases[realModelName] = source;

                /**
                 * Update model: source
                 */
                let joinModels[realModelName] = source;

                /**
                 * Update model: model
                 */
                let sqlModelsAliases[realModelName] = realModelName;

                /**
                 * Update model: model
                 */
                let sqlAliasesModels[realModelName] = realModelName;

                /**
                 * Update model: model instance
                 */
                let sqlAliasesModelsInstances[realModelName] = model;

                /**
                 * Update model: source
                 */
                let models[realModelName] = source;

                /**
                 * Complete source related to a model
                 */
                let joinSources[realModelName] = completeSource;

                /**
                 * Complete source related to a model
                 */
                let joinPrepared[realModelName] = joinItem;
            }

            let modelsInstances[realModelName] = model;
        }

        /**
         * Update temporary properties
         */
        let this->models = models,
            this->sqlAliases = sqlAliases,
            this->sqlAliasesModels = sqlAliasesModels,
            this->sqlModelsAliases = sqlModelsAliases,
            this->sqlAliasesModelsInstances = sqlAliasesModelsInstances,
            this->modelsInstances = modelsInstances;

        for joinAliasName, joinItem in joinPrepared {

            /**
             * Check for predefined conditions
             */
            if fetch joinExpr, joinItem["conditions"] {
                let joinPreCondition[joinAliasName] = this->getExpression(joinExpr);
            }
        }

        /**
         * Skip all implicit joins if the option is not enabled
         */
        if !this->enableImplicitJoins {
            for joinAliasName, _ in joinPrepared {
                let joinType = joinTypes[joinAliasName],
                    joinSource = joinSources[joinAliasName],
                    preCondition = joinPreCondition[joinAliasName],
                    sqlJoins[] = [
                        "type":        joinType,
                        "source":     joinSource,
                        "conditions": [preCondition]
                    ];
            }

            return sqlJoins;
        }

        /**
         * Build the list of tables used in the SELECT clause
         */
        let fromModels = [];

        for tableItem in selectTables {
            let fromModels[tableItem["qualifiedName"]["name"]] = true;
        }

        /**
         * Create join relationships dynamically
         */
        for fromModelName, _ in fromModels {
            for joinAlias, joinModel in joinModels {
                /**
                 * Real source name for joined model
                 */
                let joinSource = joinSources[joinAlias];

                /**
                 * Join type is: LEFT, RIGHT, INNER, etc
                 */
                let joinType = joinTypes[joinAlias];

                /**
                 * Check if the model already have pre-defined conditions
                 */
                if !fetch preCondition, joinPreCondition[joinAlias] {
                    /**
                     * Get the model name from its source
                     */
                    let modelNameAlias = sqlAliasesModels[joinAlias];

                    /**
                     * Check if the joined model is an alias
                     */
                    let relation = manager->getRelationByAlias(
                        fromModelName,
                        modelNameAlias
                    );

                    if relation === false {
                        /**
                         * Check for relations between models
                         */
                        let relations = manager->getRelationsBetween(
                            fromModelName,
                            modelNameAlias
                        );

                        if typeof relations == "array" {
                            /**
                             * More than one relation must throw an exception
                             */
                            if unlikely count(relations) != 1 {
                                throw new AmbiguousJoinRelation(fromModelName, joinModel, this->phql);
                            }

                            /**
                             * Get the first relationship
                             */
                            let relation = relations[0];
                        }
                    }

                    /*
                     * Valid relations are objects
                     */
                    if typeof relation == "object" {
                        /**
                         * Get the related model alias of the left part
                         */
                        let modelAlias = sqlModelsAliases[fromModelName];

                        /**
                         * Generate the conditions based on the type of join
                         */
                        if !relation->isThrough() {
                            let sqlJoin = this->getSingleJoin(
                                joinType,
                                joinSource,
                                modelAlias,
                                joinAlias,
                                relation
                            );
                        } else {
                            let sqlJoin = this->getMultiJoin(
                                joinType,
                                joinSource,
                                modelAlias,
                                joinAlias,
                                relation
                            );
                        }

                        /**
                         * Append or merge joins
                         */
                        if isset sqlJoin[0] {
                            for sqlJoinItem in sqlJoin {
                                let sqlJoins[] = sqlJoinItem;
                            }
                        } else {
                            let sqlJoins[] = sqlJoin;
                        }
                    } else {
                        /**
                         * Join without conditions because no relation has been
                         * found between the models
                         */
                        let sqlJoins[] = [
                            "type":       joinType,
                            "source":     joinSource,
                            "conditions": []
                        ];
                    }
                } else {
                    /**
                     * Get the conditions established by the developer
                     * Join with conditions established by the developer
                     */
                    let sqlJoins[] = [
                        "type":       joinType,
                        "source":     joinSource,
                        "conditions": [preCondition]
                    ];
                }
            }
        }

        return sqlJoins;
    }

    /**
     * Returns a processed limit clause for a SELECT statement
     */
    final protected function getLimitClause(array! limitClause) -> array
    {
        var number, offset;
        array limit = [];

        if fetch number, limitClause["number"] {
            let limit["number"] = this->getExpression(number);
        }

        if fetch offset, limitClause["offset"] {
            let limit["offset"] = this->getExpression(offset);
        }

        return limit;
    }

    /**
     * Resolves joins involving many-to-many relations
     *
     * @param string joinSource
     */
    final protected function getMultiJoin(string! joinType, joinSource, string modelAlias, string joinAlias, <RelationInterface> relation) -> array
    {
        var fields, referencedFields, intermediateModelName,
            intermediateModel, intermediateSource, intermediateSchema,
            intermediateFields, intermediateReferencedFields,
            referencedModelName, manager, field, position, intermediateField,
            sqlEqualsJoinCondition;
        array sqlJoins;

        let sqlJoins = [];

        /**
         * Local fields in the 'from' relation
         */
        let fields = relation->getFields();

        /**
         * Referenced fields in the joined relation
         */
        let referencedFields = relation->getReferencedFields();

        /**
         * Intermediate model
         */
        let intermediateModelName = relation->getIntermediateModel();

        let manager = this->manager;

        /**
         * Get the intermediate model instance
         */
        let intermediateModel = manager->load(intermediateModelName);

        /**
         * Source of the related model
         */
        let intermediateSource = intermediateModel->getSource();

        /**
         * Schema of the related model
         */
        let intermediateSchema = intermediateModel->getSchema();

        //intermediateFullSource = [intermediateSchema, intermediateSource];

        /**
         * Update the internal sqlAliases to set up the intermediate model
         */
        let this->sqlAliases[intermediateModelName] = intermediateSource;

        /**
         * Update the internal sqlAliasesModelsInstances to rename columns if
         * necessary
         */
        let this->sqlAliasesModelsInstances[intermediateModelName] = intermediateModel;

        /**
         * Fields that join the 'from' model with the 'intermediate' model
         */
        let intermediateFields = relation->getIntermediateFields();

        /**
         * Fields that join the 'intermediate' model with the intermediate model
         */
        let intermediateReferencedFields = relation->getIntermediateReferencedFields();

        /**
         * Intermediate model
         */
        let referencedModelName = relation->getReferencedModel();

        if typeof fields == "array" {
            for field, position in fields {
                if unlikely !isset referencedFields[position] {
                    throw new JoinFieldCountMismatch(modelAlias, joinAlias, this->phql);
                }

                /**
                 * Get the referenced field in the same position
                 */
                let intermediateField = intermediateFields[position];

                /**
                 * Create a binary operation for the join conditions
                 */
                let sqlEqualsJoinCondition = [
                    "type" : "binary-op",
                    "op"   : "=",
                    "left" : this->getQualified(
                        [
                            "type"   : PHQL_T_QUALIFIED,
                            "domain" : modelAlias,
                            "name"   : field
                        ]
                    ),
                    "right" : this->getQualified(
                        [
                            "type"   : "qualified",
                            "domain" : joinAlias,
                            "name"   : referencedFields
                        ]
                    )
                ];

                //let sqlJoinPartialConditions[] = sqlEqualsJoinCondition;
            }

        } else {

            /**
             * Create the left part of the expression
             * Create the right part of the expression
             * Create a binary operation for the join conditions
             * A single join
             */
            let sqlJoins = [
                [
                    "type"       : joinType,
                    "source"     : [intermediateSource, intermediateSchema],
                    "conditions" : [
                        [
                            "type" : "binary-op",
                            "op" : "=",
                            "left" : this->getQualified(
                                [
                                    "type"   : PHQL_T_QUALIFIED,
                                    "domain" : modelAlias,
                                    "name"   : fields
                                ]
                            ),
                            "right" : this->getQualified(
                                [
                                    "type"   : "qualified",
                                    "domain" : intermediateModelName,
                                    "name"   : intermediateFields
                                ]
                            )
                        ]
                    ]
                ],

                /**
                 * Create the left part of the expression
                 * Create the right part of the expression
                 * Create a binary operation for the join conditions
                 * A single join
                 */
                [
                    "type"       : joinType,
                    "source"     : joinSource,
                    "conditions" : [
                        [
                            "type" : "binary-op",
                            "op" : "=",
                            "left" : this->getQualified(
                                [
                                    "type"   : PHQL_T_QUALIFIED,
                                    "domain" : intermediateModelName,
                                    "name"   : intermediateReferencedFields
                                ]
                            ),
                            "right" : this->getQualified(
                                [
                                    "type"   : "qualified",
                                    "domain" : referencedModelName,
                                    "name"   : referencedFields
                                ]
                            )
                        ]
                    ]
                ]
            ];
        }

        return sqlJoins;
    }

    /**
     * Returns a processed order clause for a SELECT statement
     *
     * @param array|string order
     */
    final protected function getOrderClause(order) -> array
    {
        var orderColumns, orderItem, orderPartExpr, orderSort;
        array orderParts, orderPartSort;

        if !isset order[0] {
            let orderColumns = [order];
        } else {
            let orderColumns = order;
        }

        let orderParts = [];

        for orderItem in orderColumns {
            let orderPartExpr = this->getExpression(
                orderItem["column"]
            );

            /**
             * Check if the order has a predefined ordering mode
             */
            if fetch orderSort, orderItem["sort"] {
                if orderSort == PHQL_T_ASC {
                    let orderPartSort = [orderPartExpr, "ASC"];
                } else {
                    let orderPartSort = [orderPartExpr, "DESC"];
                }
            } else {
                let orderPartSort = [orderPartExpr];
            }

            let orderParts[] = orderPartSort;
        }

        return orderParts;
    }

    /**
     * Replaces the model's name to its source name in a qualified-name
     * expression
     */
    final protected function getQualified(array! expr) -> array
    {
        var columnName, nestingLevel, sqlColumnAliases, metaData, sqlAliases,
            source, sqlAliasesModelsInstances, realColumnName, columnDomain,
            model, models, columnMap, hasModel, className;
        int number;

        let columnName = expr["name"];

        let nestingLevel = this->nestingLevel;

        /**
         * Check if the qualified name is a column alias
         */
        if isset this->sqlColumnAliases[nestingLevel] {
            let sqlColumnAliases = this->sqlColumnAliases[nestingLevel];
        } else {
            let sqlColumnAliases = [];
        }

        if isset sqlColumnAliases[columnName] && (!isset expr["domain"] || empty expr["domain"]) {
            return [
                "type": "qualified",
                "name": columnName
            ];
        }

        let metaData = this->metaData;

        /**
         * Check if the qualified name has a domain
         */
        if fetch columnDomain, expr["domain"] {
            let sqlAliases = this->sqlAliases;

            /**
             * The column has a domain, we need to check if it's an alias
             */
            if unlikely !fetch source, sqlAliases[columnDomain] {
                throw new UnknownModelOrAlias(columnDomain, "11", this->phql);
            }

            /**
             * Change the selected column by its real name on its mapped table
             */
            if Settings::get("orm.column_renaming") {
                /**
                 * Retrieve the corresponding model by its alias
                 */
                let sqlAliasesModelsInstances = this->sqlAliasesModelsInstances;

                /**
                 * We need the model instance to retrieve the reversed column
                 * map
                 */
                if unlikely !fetch model, sqlAliasesModelsInstances[columnDomain] {
                    throw new NoModelForAlias(columnDomain, this->phql);
                }

                let columnMap = metaData->getReverseColumnMap(model);
            } else {
                let columnMap = null;
            }

            if typeof columnMap == "array" {
                if unlikely !fetch realColumnName, columnMap[columnName] {
                    throw new ColumnNotInDomain(columnName, columnDomain, this->phql);
                }
            } else {
                let realColumnName = columnName;
            }
        } else {
            /**
             * If the column IR does not have a domain, we must check for
             * ambiguities
             */
            let number = 0,
                hasModel = false;

            for model in this->modelsInstances {
                /**
                 * Check if the attribute belongs to the current model
                 */
                if metaData->hasAttribute(model, columnName) {
                    let number++;

                    if unlikely number > 1 {
                        throw new AmbiguousColumn(columnName, this->phql);
                    }

                    let hasModel = model;
                }
            }

            /**
             * After check in every model, the column does not belong to any of
             * the selected models
             */
            if unlikely hasModel === false {
                throw new ColumnNotInSelectedModels(columnName, "1", this->phql);
            }

            /**
             * Check if the models property is correctly prepared
             */
            let models = this->models;

            if unlikely typeof models != "array" {
                throw new ModelsListNotLoaded();
            }

            /**
             * Obtain the model's source from the models list
             */
            let className = get_class(hasModel);

            if unlikely !fetch source, models[className] {
                throw new ModelSourceNotFound(className, this->phql);
            }

            /**
             * Rename the column
             */
            if Settings::get("orm.column_renaming") {
                let columnMap = metaData->getReverseColumnMap(hasModel);
            } else {
                let columnMap = null;
            }

            if typeof columnMap == "array" {
                /**
                 * The real column name is in the column map
                 */
                if unlikely !fetch realColumnName, columnMap[columnName] {
                    throw new ColumnNotInSelectedModels(columnName, "3", this->phql);
                }
            } else {
                let realColumnName = columnName;
            }
        }

        /**
         * Create an array with the qualified info
         */
        return [
            "type"  : "qualified",
            "domain": source,
            "name"  : realColumnName,
            "balias": columnName
        ];
    }


    /**
     * Gets the read connection from the model if there is no transaction set
     * inside the query object
     */
    protected function getReadConnection(<ModelInterface> model, array intermediate = null, array bindParams = [], array bindTypes = []) -> <AdapterInterface>
    {
        var connection = null, transaction;

        let transaction = this->transaction;

        if typeof transaction == "object" && transaction instanceof TransactionInterface {
            return transaction->getConnection();
        }

        if method_exists(model, "selectReadConnection") {
            // use selectReadConnection() if implemented in extended Model class
            let connection = model->selectReadConnection(
                intermediate,
                bindParams,
                bindTypes
            );

            if unlikely typeof connection != "object" {
                throw new ReadConnectionMissing();
            }

            return connection;
        }

        return model->getReadConnection();
    }

    /**
     * Query the records on which the UPDATE/DELETE operation will be done
     *
     * @return ResultsetInterface
     */
    final protected function getRelatedRecords(<ModelInterface> model, array intermediate, array bindParams, array bindTypes) -> <ResultsetInterface>
    {
        var selectIr, joinConditions, whereConditions, limitConditions, query;

        /**
         * Instead of create a PHQL string statement we manually create the IR
         * representation
         */
        let selectIr = [
            "columns" : [
                [
                    "type"   : "object",
                    "model"  : get_class(model),
                    "column" : model->getSource()
                ]
            ],
            "models"  : intermediate["models"],
            "tables"  : intermediate["tables"]
        ];

        /**
         * Forward the JOINs (if any) so the related records are filtered by
         * the joined models too (UPDATE/DELETE ... JOIN support)
         */
        if fetch joinConditions, intermediate["joins"] {
            let selectIr["joins"] = joinConditions;
        }

        /**
         * Check if a WHERE clause was specified
         */
        if fetch whereConditions, intermediate["where"] {
            let selectIr["where"] = whereConditions;
        }

        /**
         * Check if a LIMIT clause was specified
         */
        if fetch limitConditions, intermediate["limit"] {
            let selectIr["limit"] = limitConditions;
        }

        /**
         * We create another Phalcon\Mvc\Model\Query to get the related records
         */
        let query = new self();

        query->setDI(this->container);
        query->setType(PHQL_T_SELECT);
        query->setIntermediate(selectIr);

        return query->execute(bindParams, bindTypes);
    }

    /**
     * Resolves a column from its intermediate representation into an array
     * used to determine if the resultset produced is simple or complex
     */
    final protected function getSelectColumn(array! column) -> array
    {
        var columnType, sqlAliases, modelName, source, columnDomain,
            sqlColumnAlias, preparedAlias, sqlExprColumn, sqlAliasesModels,
            columnData, balias, eager;
        array sqlColumns, sqlColumn;

        if unlikely !fetch columnType, column["type"] {
            throw new CorruptedSelectAst();
        }

        let sqlColumns = [];

        /**
         * Check if column is eager loaded
         */
        fetch eager, column["eager"];

        /**
         * Check for select * (all)
         */
        if columnType == PHQL_T_STARALL {
            for modelName, source in this->models {
                let sqlColumn = [
                    "type"  : "object",
                    "model" : modelName,
                    "column": source,
                    "balias": (strpos(modelName, "\\") !== false) ? modelName : lcfirst(modelName)
                ];

                if eager !== null {
                    let sqlColumn["eager"] = eager,
                        sqlColumn["eagerType"] = column["eagerType"];
                }

                let sqlColumns[] = sqlColumn;
            }

            return sqlColumns;
        }

        if unlikely !isset column["column"] {
            throw new CorruptedSelectAst();
        }

        /**
         * Check if selected column is qualified.*, ex: robots.*
         */
        if columnType == PHQL_T_DOMAINALL {
            let sqlAliases = this->sqlAliases;

            /**
             * We only allow the alias.*
             */
            let columnDomain = column["column"];

            if unlikely !fetch source, sqlAliases[columnDomain] {
                throw new UnknownModelOrAlias(columnDomain, "2", this->phql);
            }

            /**
             * Get the SQL alias if any
             */
            let sqlColumnAlias = source;

            fetch preparedAlias, column["balias"];

            /**
             * Get the real source name
             */
            let sqlAliasesModels = this->sqlAliasesModels,
                modelName = sqlAliasesModels[columnDomain];

            if typeof preparedAlias != "string" {
                if columnDomain == modelName {
                    let preparedAlias = (strpos(modelName, "\\") !== false) ? modelName : lcfirst(modelName);
                } else {
                    let preparedAlias = columnDomain;
                }
            }

            /**
             * Each item is a complex type returning a complete object
             */
            let sqlColumn = [
                "type":   "object",
                "model":  modelName,
                "column": sqlColumnAlias,
                "balias": preparedAlias
            ];

            if eager !== null {
                let sqlColumn["eager"] = eager,
                    sqlColumn["eagerType"] = column["eagerType"];
            }

            let sqlColumns[] = sqlColumn;

            return sqlColumns;
        }

        /**
         * Check for columns qualified and not qualified
         */
        if columnType == PHQL_T_EXPR {

            /**
             * The sql_column is a scalar type returning a simple string
             */
            let sqlColumn = ["type": "scalar"],
                columnData = column["column"],
                sqlExprColumn = this->getExpression(columnData);

            /**
             * Create balias and sqlAlias
             */
            if fetch balias, sqlExprColumn["balias"] {
                let sqlColumn["balias"] = balias,
                    sqlColumn["sqlAlias"] = balias;
            }

            if eager !== null {
                let sqlColumn["eager"] = eager,
                    sqlColumn["eagerType"] = column["eagerType"];
            }

            let sqlColumn["column"] = sqlExprColumn,
                sqlColumns[] = sqlColumn;

            return sqlColumns;
        }

        throw new UnknownColumnType(columnType);
    }

    /**
     * Resolves joins involving has-one/belongs-to/has-many relations
     *
     * @param string joinSource
     */
    final protected function getSingleJoin(string! joinType, joinSource, string modelAlias, string joinAlias, <RelationInterface> relation) -> array
    {
        var fields, referencedFields, sqlJoinConditions = null,
            sqlJoinPartialConditions, position, field, referencedField;

        /**
         * Local fields in the 'from' relation
         */
        let fields = relation->getFields();

        /**
         * Referenced fields in the joined relation
         */
        let referencedFields = relation->getReferencedFields();

        if typeof fields != "array" {
            /**
             * Create the left part of the expression
             * Create a binary operation for the join conditions
             * Create the right part of the expression
             */
            let sqlJoinConditions = [
                [
                    "type" : "binary-op",
                    "op"   : "=",
                    "left" : this->getQualified(
                        [
                            "type"   : PHQL_T_QUALIFIED,
                            "domain" : modelAlias,
                            "name"   : fields
                        ]
                    ),
                    "right": this->getQualified(
                        [
                            "type"   : "qualified",
                            "domain" : joinAlias,
                            "name"   : referencedFields
                        ]
                    )
                ]
            ];
        } else {
            /**
             * Resolve the compound operation
             */
            let sqlJoinPartialConditions = [];

            for position, field in fields {
                /**
                 * Get the referenced field in the same position
                 */
                if unlikely !fetch referencedField, referencedFields[position] {
                    throw new JoinFieldCountMismatch(modelAlias, joinAlias, this->phql);
                }

                /**
                 * Create the left part of the expression
                 * Create the right part of the expression
                 * Create a binary operation for the join conditions
                 */
                let sqlJoinPartialConditions[] = [
                    "type" : "binary-op",
                    "op"   : "=",
                    "left" : this->getQualified(
                        [
                            "type"   : PHQL_T_QUALIFIED,
                            "domain" : modelAlias,
                            "name"   : field
                        ]
                    ),
                    "right": this->getQualified(
                        [
                            "type"   : "qualified",
                            "domain" : joinAlias,
                            "name"   : referencedField
                        ]
                    )
                ];
            }

        }

        /**
         * A single join
         */
        return [
            "type"       : joinType,
            "source"     : joinSource,
            "conditions" : sqlJoinConditions
        ];
    }

    /**
     * Resolves a table in a SELECT statement checking if the model exists
     *
     * @return string
     */
    final protected function getTable(<ManagerInterface> manager, array qualifiedName)
    {
        var modelName, model, source, schema;

        if unlikely !fetch modelName, qualifiedName["name"] {
            throw new CorruptedSelectAst();
        }

        let model = manager->load(modelName),
            source = model->getSource(),
            schema = model->getSchema();

        if schema {
            return [schema, source];
        }

        return source;
    }

    /**
     * Gets the write connection from the model if there is no transaction
     * inside the query object
     */
    protected function getWriteConnection(<ModelInterface> model, array intermediate = null, array bindParams = [], array bindTypes = []) -> <AdapterInterface>
    {
        var connection = null, transaction;

        let transaction = this->transaction;

        if typeof transaction == "object" && transaction instanceof TransactionInterface {
            return transaction->getConnection();
        }

        if method_exists(model, "selectWriteConnection") {
            let connection = model->selectWriteConnection(
                intermediate,
                bindParams,
                bindTypes
            );

            if unlikely typeof connection != "object" {
                throw new WriteConnectionMissing();
            }

            return connection;
        }
        return model->getWriteConnection();
    }

    /**
     * Analyzes a DELETE intermediate code and produces an array to be executed
     * later
     */
    final protected function prepareDelete() -> array
    {
        var ast, delete, tables, models, modelsInstances, sqlTables, sqlModels,
            sqlAliases, sqlAliasesModelsInstances, deleteTables, manager, table,
            qualifiedName, modelName, model, source, schema, completeSource,
            alias, sqlDelete, where, limit;

        let ast = this->ast;

        if unlikely !fetch delete, ast["delete"] {
            throw new CorruptedDeleteAst();
        }

        if unlikely !fetch tables, delete["tables"] {
            throw new CorruptedDeleteAst();
        }

        /**
         * We use these arrays to store info related to models, alias and its
         * sources. Thanks to them we can rename columns later
         */
        let models = [],
            modelsInstances = [];

        let sqlTables = [],
            sqlModels = [],
            sqlAliases = [],
            sqlAliasesModelsInstances = [];

        if !isset tables[0] {
            let deleteTables = [tables];
        } else {
            let deleteTables = tables;
        }

        let manager = this->manager;

        for table in deleteTables {
            let qualifiedName = table["qualifiedName"],
                modelName = qualifiedName["name"];

            /**
             * Load a model instance from the models manager
             */
            let model = manager->load(modelName),
                source = model->getSource(),
                schema = model->getSchema();

            if schema {
                let completeSource = [source, schema];
            } else {
                let completeSource = [source, null];
            }

            if fetch alias, table["alias"] {
                let sqlAliases[alias] = alias,
                    completeSource[] = alias,
                    sqlTables[] = completeSource,
                    sqlAliasesModelsInstances[alias] = model,
                    models[alias] = modelName;
            } else {
                let sqlAliases[modelName] = source,
                    sqlAliasesModelsInstances[modelName] = model,
                    sqlTables[] = source,
                    models[modelName] = source;
            }

            let sqlModels[] = modelName,
                modelsInstances[modelName] = model;
        }

        /**
         * Update the models/alias/sources in the object
         */
        let this->models = models,
            this->modelsInstances = modelsInstances,
            this->sqlAliases = sqlAliases,
            this->sqlAliasesModelsInstances = sqlAliasesModelsInstances;

        let sqlDelete = [],
            sqlDelete["tables"] = sqlTables,
            sqlDelete["models"] = sqlModels;

        if fetch where, ast["where"] {
            let sqlDelete["where"] = this->getExpression(where, true);
        }

        if fetch limit, ast["limit"] {
            let sqlDelete["limit"] = this->getLimitClause(limit);
        }

        return sqlDelete;
    }

    /**
     * Analyzes an INSERT intermediate code and produces an array to be executed
     * later
     */
    final protected function prepareInsert() -> array
    {
        var ast, qualifiedName, manager, modelName, model, source, schema,
            exprValues, exprValue, sqlInsert, metaData, fields, sqlFields,
            field, name;
        bool notQuoting;

        let ast = this->ast;

        if unlikely !isset ast["qualifiedName"] {
            throw new CorruptedInsertAst();
        }

        if unlikely !isset ast["values"] {
            throw new CorruptedInsertAst();
        }

        let qualifiedName = ast["qualifiedName"];

        // Check if the related model exists
        if unlikely !isset qualifiedName["name"] {
            throw new CorruptedInsertAst();
        }

        let manager = this->manager,
            modelName = qualifiedName["name"];

        let model = manager->load(modelName),
            source = model->getSource(),
            schema = model->getSchema();

        if schema {
            let source = [schema, source];
        }

        let notQuoting = false,
            exprValues = [];

        for exprValue in ast["values"] {
            // Resolve every expression in the "values" clause
            let exprValues[] = [
                "type" : exprValue["type"],
                "value": this->getExpression(exprValue, notQuoting)
            ];
        }

        let sqlInsert = [
            "model": modelName,
            "table": source
        ];

        let metaData = this->metaData;

        if fetch fields, ast["fields"] {
            let sqlFields = [];

            for field in fields {
                let name = field["name"];

                // Check that inserted fields are part of the model
                if unlikely !metaData->hasAttribute(model, name) {
                    throw new MissingModelAttribute(modelName, name, this->phql);
                }

                // Add the file to the insert list
                let sqlFields[] = name;
            }

            let sqlInsert["fields"] = sqlFields;
        }

        let sqlInsert["values"] = exprValues;

        return sqlInsert;
    }

    /**
     * Analyzes a SELECT intermediate code and produces an array to be executed later
     */
    final protected function prepareSelect(var ast = null, bool merge = false) -> array
    {
        int position;
        var select, tables, columns, selectedModels, manager, metaData,
            selectedModel, qualifiedName, modelName, model, schema, source,
            completeSource, alias, joins, sqlJoins, selectColumns,
            sqlColumnAliases, column, sqlColumn, sqlSelect, distinct, having,
            where, groupBy, order, limit, tempModels, tempModelsInstances,
            tempSqlAliases, tempSqlModelsAliases,
            tempSqlAliasesModelsInstances, tempSqlAliasesModels, with, withs,
            withItem, automaticJoins, number, relation, joinAlias,
            relationModel, bestAlias, eagerType, mergeKey, mergeValue;
        array sqlModels, sqlTables, sqlAliases, sqlColumns, sqlAliasesModels,
            sqlModelsAliases, sqlAliasesModelsInstances, models,
            modelsInstances;

        if empty ast {
            let ast = this->ast;
        }

        if !fetch select, ast["select"] {
            let select = ast;
        }

        if unlikely !fetch tables, select["tables"] {
            throw new CorruptedSelectAst();
        }

        if unlikely !fetch columns, select["columns"] {
            throw new CorruptedSelectAst();
        }

        let this->nestingLevel++;

        /**
         * sqlModels is an array of the models to be used in the query
         */
        let sqlModels = [];

        /**
         * sqlTables is an array of the mapped models sources to be used in the
         * query
         */
        let sqlTables = [];

        /**
         * sqlColumns is an array of every column expression
         */
        let sqlColumns = [];

        /**
         * sqlAliases is a map from aliases to mapped sources
         */
        let sqlAliases = [];

        /**
         * sqlAliasesModels is a map from aliases to model names
         */
        let sqlAliasesModels = [];

        /**
         * sqlAliasesModels is a map from model names to aliases
         */
        let sqlModelsAliases = [];

        /**
         * sqlAliasesModelsInstances is a map from aliases to model instances
         */
        let sqlAliasesModelsInstances = [];

        /**
         * Models information
         */
        let models = [],
            modelsInstances = [];

        // Convert selected models in an array
        if !isset tables[0] {
            let selectedModels = [tables];
        } else {
            let selectedModels = tables;
        }

        // Convert selected columns in an array
        if !isset columns[0] {
            let selectColumns = [columns];
        } else {
            let selectColumns = columns;
        }

        let manager = this->manager,
            metaData = this->metaData;

        if unlikely typeof manager != "object" {
            throw new MissingModelsManager();
        }

        if unlikely typeof metaData != "object" {
            throw new MissingMetaData();
        }

        // Process selected models
        let number = 0,
            automaticJoins = [];

        for selectedModel in selectedModels {
            let qualifiedName = selectedModel["qualifiedName"],
                modelName = qualifiedName["name"];

            // Load a model instance from the models manager
            let model = manager->load(modelName);

            // Define a complete schema/source
            let schema = model->getSchema(),
                source = model->getSource();

            // Obtain the real source including the schema
            if schema {
                let completeSource = [source, schema];
            } else {
                let completeSource = source;
            }

            /**
             * If an alias is defined for a model then the model cannot be
             * referenced in the column list
             */
            if fetch alias, selectedModel["alias"] {
                // Check if the alias was used before
                if unlikely isset sqlAliases[alias] {
                    throw new DuplicateAlias(alias, this->phql);
                }

                let sqlAliases[alias] = alias,
                    sqlAliasesModels[alias] = modelName,
                    sqlModelsAliases[modelName] = alias,
                    sqlAliasesModelsInstances[alias] = model;

                /**
                 * Append or convert complete source to an array
                 */
                if typeof completeSource == "array" {
                    let completeSource[] = alias;
                } else {
                    let completeSource = [source, null, alias];
                }

                let models[modelName] = alias;
            } else {
                let alias = source,
                    sqlAliases[modelName] = source,
                    sqlAliasesModels[modelName] = modelName,
                    sqlModelsAliases[modelName] = modelName,
                    sqlAliasesModelsInstances[modelName] = model,
                    models[modelName] = source;
            }

            // Eager load any specified relationship(s)
            if fetch with, selectedModel["with"] {
                if !isset with[0] {
                    let withs = [with];
                } else {
                    let withs = with;
                }

                // Simulate the definition of inner joins
                for withItem in withs {
                    let joinAlias = "AA" . number,
                        relationModel = withItem["name"];

                    let relation = manager->getRelationByAlias(
                        modelName,
                        relationModel
                    );

                    if typeof relation == "object" {
                        let bestAlias = relation->getOption("alias"),
                            relationModel = relation->getReferencedModel(),
                            eagerType = relation->getType();
                    } else {
                        let relation = manager->getRelationsBetween(
                            modelName,
                            relationModel
                        );

                        if unlikely typeof relation != "object" {
                            throw new RelationshipNotFound(modelName, relationModel, this->phql);
                        }

                        let bestAlias = relation->getOption("alias"),
                            relationModel = relation->getReferencedModel(),
                            eagerType = relation->getType();
                    }

                    let selectColumns[] = [
                        "type":      PHQL_T_DOMAINALL,
                        "column":    joinAlias,
                        "eager":     alias,
                        "eagerType": eagerType,
                        "balias":    bestAlias
                    ];

                    let automaticJoins[] = [
                        "type": PHQL_T_INNERJOIN,
                        "qualified": [
                            "type": PHQL_T_QUALIFIED,
                            "name": relationModel
                        ],
                        "alias": [
                            "type": PHQL_T_QUALIFIED,
                            "name": joinAlias
                        ]
                    ];

                    let number++;
                }
            }

            let sqlModels[] = modelName,
                sqlTables[] = completeSource,
                modelsInstances[modelName] = model;
        }

        // Assign Models/Tables information
        if !merge {
            let this->models = models,
                this->modelsInstances = modelsInstances,
                this->sqlAliases = sqlAliases,
                this->sqlAliasesModels = sqlAliasesModels,
                this->sqlModelsAliases = sqlModelsAliases,
                this->sqlAliasesModelsInstances = sqlAliasesModelsInstances;
        } else {
            let tempModels = this->models,
                tempModelsInstances = this->modelsInstances,
                tempSqlAliases = this->sqlAliases,
                tempSqlAliasesModels = this->sqlAliasesModels,
                tempSqlModelsAliases = this->sqlModelsAliases,
                tempSqlAliasesModelsInstances = this->sqlAliasesModelsInstances;

            /**
             * In-place updates instead of array_merge: preserves the
             * "right-side wins, original order kept" semantics that
             * union (+) cannot give, with no fresh array allocation.
             */
            for mergeKey, mergeValue in models {
                let this->models[mergeKey] = mergeValue;
            }

            for mergeKey, mergeValue in modelsInstances {
                let this->modelsInstances[mergeKey] = mergeValue;
            }

            for mergeKey, mergeValue in sqlAliases {
                let this->sqlAliases[mergeKey] = mergeValue;
            }

            for mergeKey, mergeValue in sqlAliasesModels {
                let this->sqlAliasesModels[mergeKey] = mergeValue;
            }

            for mergeKey, mergeValue in sqlModelsAliases {
                let this->sqlModelsAliases[mergeKey] = mergeValue;
            }

            for mergeKey, mergeValue in sqlAliasesModelsInstances {
                let this->sqlAliasesModelsInstances[mergeKey] = mergeValue;
            }
        }

        fetch joins, select["joins"];

        // Join existing JOINS with automatic Joins
        if count(joins) {
            if count(automaticJoins) {
                if isset joins[0] {
                    let select["joins"] = array_merge(joins, automaticJoins);
                } else {
                    let automaticJoins[] = joins,
                        select["joins"] = automaticJoins;
                }
            }

            let sqlJoins = this->getJoins(select);
        } else {
            if count(automaticJoins) {
                let select["joins"] = automaticJoins,
                    sqlJoins = this->getJoins(select);
            } else {
                let sqlJoins = [];
            }
        }

        // Resolve selected columns
        let position = 0,
            sqlColumnAliases = [];

        for column in selectColumns {
            for sqlColumn in this->getSelectColumn(column) {
                /**
                 * If "alias" is set, the user defined an alias for the column
                 */
                if fetch alias, column["alias"] {
                    /**
                     * The best alias is the one provided by the user
                     */
                    let sqlColumn["balias"] = alias,
                        sqlColumn["sqlAlias"] = alias,
                        sqlColumns[alias] = sqlColumn,
                        sqlColumnAliases[alias] = true;
                } else {
                    /**
                     * "balias" is the best alias chosen for the column
                     */
                    if fetch alias, sqlColumn["balias"] {
                        let sqlColumns[alias] = sqlColumn;
                    } else {
                        if sqlColumn["type"] == "scalar" {
                            let sqlColumns["_" . position] = sqlColumn;
                        } else {
                            let sqlColumns[] = sqlColumn;
                        }
                    }
                }

                let position++;
            }
        }

        let this->sqlColumnAliases[this->nestingLevel] = sqlColumnAliases;

        // sqlSelect is the final prepared SELECT
        let sqlSelect = [
            "models" : sqlModels,
            "tables" : sqlTables,
            "columns": sqlColumns
        ];

        if fetch distinct, select["distinct"] {
            let sqlSelect["distinct"] = distinct;
        }

        if count(sqlJoins) {
            let sqlSelect["joins"] = sqlJoins;
        }

        // Process "WHERE" clause if set
        if fetch where, ast["where"] {
            let sqlSelect["where"] = this->getExpression(where);
        }

        // Process "GROUP BY" clause if set
        if fetch groupBy, ast["groupBy"] {
            let sqlSelect["group"] = this->getGroupClause(groupBy);
        }

        // Process "HAVING" clause if set
        if fetch having , ast["having"] {
            let sqlSelect["having"] = this->getExpression(having);
        }

        // Process "ORDER BY" clause if set
        if fetch order, ast["orderBy"] {
            let sqlSelect["order"] = this->getOrderClause(order);
        }

        // Process "LIMIT" clause if set
        if fetch limit, ast["limit"] {
            let sqlSelect["limit"] = this->getLimitClause(limit);
        }

        // Process "FOR UPDATE" clause if set
        if isset ast["forUpdate"] {
            let sqlSelect["forUpdate"] = true;
        }

        if merge {
            let this->models = tempModels,
                this->modelsInstances = tempModelsInstances,
                this->sqlAliases = tempSqlAliases,
                this->sqlAliasesModels = tempSqlAliasesModels,
                this->sqlModelsAliases = tempSqlModelsAliases,
                this->sqlAliasesModelsInstances = tempSqlAliasesModelsInstances;
        }

        let this->nestingLevel--;

        return sqlSelect;
    }

    /**
     * Analyzes an UPDATE intermediate code and produces an array to be executed
     * later
     */
    final protected function prepareUpdate() -> array
    {
        var ast, update, tables, values, modelsInstances, models, sqlTables,
            sqlAliases, sqlAliasesModels, sqlModelsAliases,
            sqlAliasesModelsInstances, updateTables, completeSource,
            sqlModels, manager, table, qualifiedName, modelName, model, source,
            schema, alias, joins, sqlJoins, sqlFields, sqlValues, updateValues,
            updateValue, exprColumn, sqlUpdate, where, limit;
        bool notQuoting;

        let ast = this->ast;

        if unlikely !fetch update, ast["update"] {
            throw new CorruptedUpdateAst();
        }

        if unlikely !fetch tables, update["tables"] {
            throw new CorruptedUpdateAst();
        }

        if unlikely !fetch values, update["values"] {
            throw new CorruptedUpdateAst();
        }

        /**
         * We use these arrays to store info related to models, alias and its
         * sources. With them we can rename columns later
         */
        let models = [],
            modelsInstances = [];

        let sqlTables = [],
            sqlModels = [],
            sqlAliases = [],
            sqlAliasesModels = [],
            sqlModelsAliases = [],
            sqlAliasesModelsInstances = [];

        if !isset tables[0] {
            let updateTables = [tables];
        } else {
            let updateTables = tables;
        }

        let manager = this->manager;

        for table in updateTables {
            let qualifiedName = table["qualifiedName"],
                modelName = qualifiedName["name"];

            /**
             * Load a model instance from the models manager
             */
            let model = manager->load(modelName),
                source = model->getSource(),
                schema = model->getSchema();

            /**
             * Create a full source representation including schema
             */
            if schema {
                let completeSource = [source, schema];
            } else {
                let completeSource = [source, null];
            }

            /**
             * Check if the table is aliased
             */
            if fetch alias, table["alias"] {
                let sqlAliases[alias] = alias,
                    sqlAliasesModels[alias] = modelName,
                    sqlModelsAliases[modelName] = alias,
                    completeSource[] = alias,
                    sqlTables[] = completeSource,
                    sqlAliasesModelsInstances[alias] = model,
                    models[alias] = modelName;
            } else {
                let sqlAliases[modelName] = source,
                    sqlAliasesModels[modelName] = modelName,
                    sqlModelsAliases[modelName] = modelName,
                    sqlAliasesModelsInstances[modelName] = model,
                    sqlTables[] = source,
                    models[modelName] = source;
            }

            let sqlModels[] = modelName,
                modelsInstances[modelName] = model;
        }

        /**
         * Update the models/alias/sources in the object
         */
        let this->models = models,
            this->modelsInstances = modelsInstances,
            this->sqlAliases = sqlAliases,
            this->sqlAliasesModels = sqlAliasesModels,
            this->sqlModelsAliases = sqlModelsAliases,
            this->sqlAliasesModelsInstances = sqlAliasesModelsInstances;

        /**
         * Process the JOINs (if any) before resolving the SET and WHERE
         * expressions so that columns belonging to the joined models can be
         * resolved. The joined models are registered as aliases/sources but
         * are never added to "models", so the update still targets a single
         * model.
         */
        let sqlJoins = [];

        if fetch joins, update["joins"] {
            let sqlJoins = this->getJoins(update);
        }

        let sqlFields = [], sqlValues = [];

        if !isset values[0] {
            let updateValues = [values];
        } else {
            let updateValues = values;
        }

        let notQuoting = false;

        for updateValue in updateValues {
            let sqlFields[] = this->getExpression(updateValue["column"], notQuoting),
                exprColumn = updateValue["expr"],
                sqlValues[] = [
                    "type" : exprColumn["type"],
                    "value": this->getExpression(exprColumn, notQuoting)
                ];
        }

        let sqlUpdate = [
            "tables": sqlTables,
            "models": sqlModels,
            "fields": sqlFields,
            "values": sqlValues
        ];

        if count(sqlJoins) {
            let sqlUpdate["joins"] = sqlJoins;
        }

        if fetch where, ast["where"] {
            let sqlUpdate["where"] = this->getExpression(where, true);
        }

        if fetch limit, ast["limit"] {
            let sqlUpdate["limit"] = this->getLimitClause(limit);
        }

        return sqlUpdate;
    }

    /**
     * Refreshes the schema/source of every model referenced in a cached
     * intermediate representation. The PHQL cache is keyed by the PHQL
     * string only, so a model that switches its schema or source at
     * runtime (for instance via setSchema()/setSource() in initialize())
     * would otherwise see the value frozen at first parse. See #17020.
     */
    final protected function refreshSchemasInIntermediate(array irPhql) -> array
    {
        var manager, models, tables, modelName, model, schema, source,
            currentTable, alias, index;

        let manager = this->manager;

        if typeof manager != "object" {
            return irPhql;
        }

        if !fetch models, irPhql["models"] {
            return irPhql;
        }

        if !fetch tables, irPhql["tables"] {
            return irPhql;
        }

        for index, modelName in models {
            if !isset tables[index] {
                continue;
            }

            let model = manager->load(modelName),
                schema = model->getSchema(),
                source = model->getSource(),
                currentTable = tables[index],
                alias = null;

            /**
             * Extract the alias from the cached entry (when present) so it
             * survives the rebuild. The cached shape is either a plain
             * source string, [source, schema], [source, null, alias] or
             * [source, schema, alias].
             */
            if typeof currentTable == "array" && isset currentTable[2] {
                let alias = currentTable[2];
            }

            if schema {
                if alias !== null {
                    let tables[index] = [source, schema, alias];
                } else {
                    let tables[index] = [source, schema];
                }
            } else {
                if alias !== null {
                    let tables[index] = [source, null, alias];
                } else {
                    let tables[index] = source;
                }
            }
        }

        let irPhql["tables"] = tables;

        return irPhql;
    }
}
