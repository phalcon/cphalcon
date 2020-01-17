
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Db\Adapter\AbstractAdapter;
use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\Result\Pdo as ResultPdo;
use Phalcon\Db\ResultInterface;
use Phalcon\Events\ManagerInterface;

/**
 * Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect
 * to a database
 *
 * ```php
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 3306,
 *     "username" => "sigma",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Mysql($config);
 *```
 */
abstract class AbstractPdo extends AbstractAdapter
{
    /**
     * Last affected rows
     */
    protected affectedRows;

    /**
     * PDO Handler
     *
     * @var \PDO
     */
    protected pdo;

    /**
     * Constructor for Phalcon\Db\Adapter\Pdo
     *
     * @param array|\Phalcon\Config descriptor = [
     *     'host' => 'localhost',
     *     'port' => '3306',
     *     'dbname' => 'blog',
     *     'username' => 'sigma'
     *     'password' => 'secret'
     *     'dialectClass' => null,
     *     'options' => [],
     *     'dsn' => null,
     *     'charset' => 'utf8mb4'
     * ]
     */
    public function __construct(array! descriptor)
    {
        this->connect(descriptor);

        parent::__construct(descriptor);
    }

    /**
     * Returns the number of affected rows by the latest INSERT/UPDATE/DELETE
     * executed in the database system
     *
     *```php
     * $connection->execute(
     *     "DELETE FROM robots"
     * );
     *
     * echo $connection->affectedRows(), " were deleted";
     *```
     */
    public function affectedRows() -> int
    {
        return this->affectedRows;
    }

    /**
     * Starts a transaction in the connection
     */
    public function begin(bool nesting = true) -> bool
    {
        var pdo, transactionLevel, eventsManager, savepointName;

        let pdo = this->pdo;
        if typeof pdo != "object" {
            return false;
        }

        /**
         * Increase the transaction nesting level
         */
        let this->transactionLevel++;

        /**
         * Check the transaction nesting level
         */
        let transactionLevel = (int) this->transactionLevel;

        if transactionLevel == 1 {
            /**
             * Notify the events manager about the started transaction
             */
            let eventsManager = <ManagerInterface> this->eventsManager;
            if typeof eventsManager == "object" {
                eventsManager->fire("db:beginTransaction", this);
            }

            return pdo->beginTransaction();
        }

        /**
         * Check if the current database system supports nested transactions
         */
        if !transactionLevel || !nesting || !this->isNestedTransactionsWithSavepoints() {
            return false;
        }

        let eventsManager = <ManagerInterface> this->eventsManager,
            savepointName = this->getNestedTransactionSavepointName();

        /**
         * Notify the events manager about the created savepoint
         */
        if typeof eventsManager == "object" {
            eventsManager->fire("db:createSavepoint", this, savepointName);
        }

        return this->createSavepoint(savepointName);
    }

    /**
     * Commits the active transaction in the connection
     */
    public function commit(bool nesting = true) -> bool
    {
        var pdo, transactionLevel, eventsManager, savepointName;

        let pdo = this->pdo;
        if typeof pdo != "object" {
            return false;
        }

        /**
         * Check the transaction nesting level
         */
        let transactionLevel = (int) this->transactionLevel;
        if unlikely !transactionLevel {
            throw new Exception("There is no active transaction");
        }

        if transactionLevel == 1 {
            /**
             * Notify the events manager about the committed transaction
             */
            let eventsManager = <ManagerInterface> this->eventsManager;
            if typeof eventsManager == "object" {
                eventsManager->fire("db:commitTransaction", this);
            }

            /**
             * Reduce the transaction nesting level
             */
            let this->transactionLevel--;

            return pdo->commit();
        }

        /**
         * Check if the current database system supports nested transactions
         */
        if !transactionLevel || !nesting || !this->isNestedTransactionsWithSavepoints() {
            /**
             * Reduce the transaction nesting level
             */
            if transactionLevel > 0 {
                let this->transactionLevel--;
            }

            return false;
        }

        /**
         * Notify the events manager about the committed savepoint
         */
        let eventsManager = <ManagerInterface> this->eventsManager,
            savepointName = this->getNestedTransactionSavepointName();

        if typeof eventsManager == "object" {
            eventsManager->fire("db:releaseSavepoint", this, savepointName);
        }

        /**
         * Reduce the transaction nesting level
         */
        let this->transactionLevel--;

        return this->releaseSavepoint(savepointName);
    }

    /**
     * Closes the active connection returning success. Phalcon automatically
     * closes and destroys active connections when the request ends
     */
    public function close() -> bool
    {
        let this->pdo = null;

        return true;
    }

    /**
     * This method is automatically called in \Phalcon\Db\Adapter\Pdo
     * constructor.
     *
     * Call it when you need to restore a database connection.
     *
     *```php
     * use Phalcon\Db\Adapter\Pdo\Mysql;
     *
     * // Make a connection
     * $connection = new Mysql(
     *     [
     *         "host"     => "localhost",
     *         "username" => "sigma",
     *         "password" => "secret",
     *         "dbname"   => "blog",
     *         "port"     => 3306,
     *     ]
     * );
     *
     * // Reconnect
     * $connection->connect();
     * ```
     */
    public function connect(array descriptor = null) -> bool
    {
        var username, password, dsnParts, dsnAttributes, dsnAttributesCustomRaw,
            dsnAttributesMap, options, key, value;

        if empty descriptor {
            let descriptor = (array) this->descriptor;
        }

        // Check for a username or use null as default
        if fetch username, descriptor["username"] {
            unset descriptor["username"];
        }

        // Check for a password or use null as default
        if fetch password, descriptor["password"] {
            unset descriptor["password"];
        }

        // Remove the dialect class so that it does become a dsn setting.
        if isset descriptor["dialectClass"] {
            unset descriptor["dialectClass"];
        }

        /**
         * Check if the developer has defined custom options or create one from
         * scratch
         */
        if fetch options, descriptor["options"] {
            unset descriptor["options"];
        } else {
            let options = [];
        }

        // Set PDO to throw exceptions when an error is encountered.
        let options[\PDO::ATTR_ERRMODE] = \PDO::ERRMODE_EXCEPTION;

        let dsnParts = [];

        // Check if the user has defined a custom dsn string. It should be in
        // the form of key=value with semicolons delineating sections.
        if fetch dsnAttributesCustomRaw, descriptor["dsn"] {
            let dsnParts[] = dsnAttributesCustomRaw;

            unset descriptor["dsn"];
        }

        /**
         * Start with the dsn defaults and then write over it with the
         * descriptor. At this point the descriptor should be a valid DSN
         * key-value map due to all other values having been removed.
         */
        let dsnAttributesMap = array_merge(
            this->getDsnDefaults(),
            descriptor
        );

        for key, value in dsnAttributesMap {
            let dsnParts[] = key . "=" . value;
        }

        // Create the dsn attributes string.
        let dsnAttributes = join(";", dsnParts);

        // Create the connection using PDO
        let this->pdo = new \PDO(
            this->type . ":" . dsnAttributes,
            username,
            password,
            options
        );

        return true;
    }

    /**
     * Converts bound parameters such as :name: or ?1 into PDO bind params ?
     *
     *```php
     * print_r(
     *     $connection->convertBoundParams(
     *         "SELECT * FROM robots WHERE name = :name:",
     *         [
     *             "Bender",
     *         ]
     *     )
     * );
     *```
     */
    public function convertBoundParams(string! sql, array params = []) -> array
    {
        var boundSql, placeHolders, bindPattern, matches, setOrder, placeMatch,
            value;

        let placeHolders = [],
            bindPattern = "/\\?([0-9]+)|:([a-zA-Z0-9_]+):/",
            matches = null,
            setOrder = 2;

        if preg_match_all(bindPattern, sql, matches, setOrder) {
            for placeMatch in matches {
                if !fetch value, params[placeMatch[1]] {
                    if unlikely !isset placeMatch[2] {
                        throw new Exception(
                            "Matched parameter wasn't found in parameters list"
                        );
                    }

                    if unlikely !fetch value, params[placeMatch[2]] {
                        throw new Exception(
                            "Matched parameter wasn't found in parameters list"
                        );
                    }
                }

                let placeHolders[] = value;
            }

            let boundSql = preg_replace(bindPattern, "?", sql);
        } else {
            let boundSql = sql;
        }

        return [
            "sql"    : boundSql,
            "params" : placeHolders
        ];
    }

    /**
     * Escapes a value to avoid SQL injections according to the active charset
     * in the connection
     *
     *```php
     * $escapedStr = $connection->escapeString("some dangerous value");
     *```
     */
    public function escapeString(string str) -> string
    {
        return this->pdo->quote(str);
    }

    /**
     * Sends SQL statements to the database server returning the success state.
     * Use this method only when the SQL statement sent to the server doesn't
     * return any rows
     *
     *```php
     * // Inserting data
     * $success = $connection->execute(
     *     "INSERT INTO robots VALUES (1, 'Astro Boy')"
     * );
     *
     * $success = $connection->execute(
     *     "INSERT INTO robots VALUES (?, ?)",
     *     [
     *         1,
     *         "Astro Boy",
     *     ]
     * );
     *```
     */
    public function execute(string! sqlStatement, var bindParams = null, var bindTypes = null) -> bool
    {
        var eventsManager, affectedRows, pdo, newStatement, statement;

        /**
         * Execute the beforeQuery event if an EventsManager is available
         */
        let eventsManager = <ManagerInterface> this->eventsManager;
        if typeof eventsManager == "object" {
            let this->sqlStatement = sqlStatement,
                this->sqlVariables = bindParams,
                this->sqlBindTypes = bindTypes;

            if eventsManager->fire("db:beforeQuery", this) === false {
                return false;
            }
        }

        /**
         * Initialize affectedRows to 0
         */
        let affectedRows = 0;

        this->prepareRealSql(sqlStatement, bindParams);

        let pdo = <\PDO> this->pdo;

        if typeof bindParams == "array" {
            let statement = pdo->prepare(sqlStatement);

            if typeof statement == "object" {
                let newStatement = this->executePrepared(
                    statement,
                    bindParams,
                    bindTypes
                );

                let affectedRows = newStatement->rowCount();
            }
        } else {
            let affectedRows = pdo->exec(sqlStatement);
        }

        /**
         * Execute the afterQuery event if an EventsManager is available
         */
        if typeof affectedRows == "integer" {
            let this->affectedRows = affectedRows;

            if typeof eventsManager == "object" {
                eventsManager->fire("db:afterQuery", this);
            }
        }

        return true;
    }

    /**
     * Executes a prepared statement binding. This function uses integer indexes
     * starting from zero
     *
     *```php
     * use Phalcon\Db\Column;
     *
     * $statement = $db->prepare(
     *     "SELECT * FROM robots WHERE name = :name"
     * );
     *
     * $result = $connection->executePrepared(
     *     $statement,
     *     [
     *         "name" => "Voltron",
     *     ],
     *     [
     *         "name" => Column::BIND_PARAM_INT,
     *     ]
     * );
     *```
     */
    public function executePrepared(<\PDOStatement> statement, array! placeholders, dataTypes) -> <\PDOStatement>
    {
        var wildcard, value, type, castValue, parameter, position, itemValue;

        for wildcard, value in placeholders {
            if typeof wildcard == "integer" {
                let parameter = wildcard + 1;
            } elseif typeof wildcard == "string" {
                let parameter = wildcard;
            } else {
                throw new Exception("Invalid bind parameter (1)");
            }

            if typeof dataTypes == "array" && fetch type, dataTypes[wildcard] {
                /**
                 * The bind type needs to be string because the precision
                 * is lost if it is casted as a double
                 */
                if type == Column::BIND_PARAM_DECIMAL {
                    let castValue = (string) value,
                        type = Column::BIND_SKIP;
                } else {
                    if globals_get("db.force_casting") {
                        if typeof value != "array" {
                            switch type {

                                case Column::BIND_PARAM_INT:
                                    let castValue = intval(value, 10);
                                    break;

                                case Column::BIND_PARAM_STR:
                                    let castValue = (string) value;
                                    break;

                                case Column::BIND_PARAM_NULL:
                                    let castValue = null;
                                    break;

                                case Column::BIND_PARAM_BOOL:
                                    let castValue = (bool) value;
                                    break;

                                default:
                                    let castValue = value;
                                    break;
                            }
                        } else {
                            let castValue = value;
                        }
                    } else {
                        let castValue = value;
                    }
                }

                /**
                 * 1024 is ignore the bind type
                 */
                if typeof castValue != "array" {
                    if type == Column::BIND_SKIP {
                        statement->bindValue(parameter, castValue);
                    } else {
                        statement->bindValue(parameter, castValue, type);
                    }
                } else {
                    for position, itemValue in castValue {
                        if type == Column::BIND_SKIP {
                            statement->bindValue(
                                parameter . position,
                                itemValue
                            );
                        } else {
                            statement->bindValue(
                                parameter . position,
                                itemValue,
                                type
                            );
                        }
                    }
                }
            } else {
                if typeof value != "array" {
                    statement->bindValue(parameter, value);
                } else {
                    for position, itemValue in value {
                        statement->bindValue(parameter . position, itemValue);
                    }
                }
            }
        }

        statement->execute();
        return statement;
    }

    /**
     * Return the error info, if any
     */
    public function getErrorInfo()
    {
        return this->pdo->errorInfo();
    }

    /**
     * Return internal PDO handler
     */
    public function getInternalHandler() -> <\PDO>
    {
        return this->pdo;
    }

    /**
     * Returns the current transaction nesting level
     */
    public function getTransactionLevel() -> int
    {
        return this->transactionLevel;
    }

    /**
     * Checks whether the connection is under a transaction
     *
     *```php
     * $connection->begin();
     *
     * // true
     * var_dump(
     *     $connection->isUnderTransaction()
     * );
     *```
     */
    public function isUnderTransaction() -> bool
    {
        var pdo;

        let pdo = this->pdo;

        if typeof pdo != "object" {
            return false;
        }

        return pdo->inTransaction();
    }

    /**
     * Returns the insert id for the auto_increment/serial column inserted in
     * the latest executed SQL statement
     *
     *```php
     * // Inserting a new robot
     * $success = $connection->insert(
     *     "robots",
     *     [
     *         "Astro Boy",
     *         1952,
     *     ],
     *     [
     *         "name",
     *         "year",
     *     ]
     * );
     *
     * // Getting the generated id
     * $id = $connection->lastInsertId();
     *```
     */
    public function lastInsertId(sequenceName = null) -> int | bool
    {
        var pdo;

        let pdo = this->pdo;

        if typeof pdo != "object" {
            return false;
        }

        return pdo->lastInsertId(sequenceName);
    }

    /**
     * Returns a PDO prepared statement to be executed with 'executePrepared'
     *
     *```php
     * use Phalcon\Db\Column;
     *
     * $statement = $db->prepare(
     *     "SELECT * FROM robots WHERE name = :name"
     * );
     *
     * $result = $connection->executePrepared(
     *     $statement,
     *     [
     *         "name" => "Voltron",
     *     ],
     *     [
     *         "name" => Column::BIND_PARAM_INT,
     *     ]
     * );
     *```
     */
    public function prepare(string! sqlStatement) -> <\PDOStatement>
    {
        return this->pdo->prepare(sqlStatement);
    }

    /**
     * Sends SQL statements to the database server returning the success state.
     * Use this method only when the SQL statement sent to the server is
     * returning rows
     *
     *```php
     * // Querying data
     * $resultset = $connection->query(
     *     "SELECT * FROM robots WHERE type = 'mechanical'"
     * );
     *
     * $resultset = $connection->query(
     *     "SELECT * FROM robots WHERE type = ?",
     *     [
     *         "mechanical",
     *     ]
     * );
     *```
     */
    public function query(string! sqlStatement, var bindParams = null, var bindTypes = null) -> <ResultInterface> | bool
    {
        var eventsManager, pdo, statement, params, types;

        let eventsManager = <ManagerInterface> this->eventsManager;

        /**
         * Execute the beforeQuery event if an EventsManager is available
         */
        if typeof eventsManager == "object" {
            let this->sqlStatement = sqlStatement,
                this->sqlVariables = bindParams,
                this->sqlBindTypes = bindTypes;

            if eventsManager->fire("db:beforeQuery", this) === false {
                return false;
            }
        }

        let pdo = <\PDO> this->pdo;
        if typeof bindParams == "array" {
            let params = bindParams;
            let types = bindTypes;
        } else {
            let params = [];
            let types = [];
        }

        let statement = pdo->prepare(sqlStatement);
        if unlikely typeof statement != "object" {
            throw new Exception("Cannot prepare statement");
        }

        this->prepareRealSql(sqlStatement, bindParams);

        let statement = this->executePrepared(statement, params, types);

        /**
         * Execute the afterQuery event if an EventsManager is available
         */
        if typeof statement == "object" {
            if typeof eventsManager == "object" {
                eventsManager->fire("db:afterQuery", this);
            }

            return new ResultPdo(
                this,
                statement,
                sqlStatement,
                bindParams,
                bindTypes
            );
        }

        return statement;
    }

    /**
     * Rollbacks the active transaction in the connection
     */
    public function rollback(bool nesting = true) -> bool
    {
        var pdo, transactionLevel, eventsManager, savepointName;

        let pdo = this->pdo;
        if typeof pdo != "object" {
            return false;
        }

        /**
         * Check the transaction nesting level
         */
        let transactionLevel = (int) this->transactionLevel;
        if unlikely !transactionLevel {
            throw new Exception("There is no active transaction");
        }

        if transactionLevel == 1 {
            /**
             * Notify the events manager about the rollbacked transaction
             */
            let eventsManager = <ManagerInterface> this->eventsManager;
            if typeof eventsManager == "object" {
                eventsManager->fire("db:rollbackTransaction", this);
            }

            /**
             * Reduce the transaction nesting level
             */
            let this->transactionLevel--;

            return pdo->rollback();
        }

        /**
         * Check if the current database system supports nested transactions
         */
        if !transactionLevel || !nesting || !this->isNestedTransactionsWithSavepoints() {
            /**
             * Reduce the transaction nesting level
             */
            if transactionLevel > 0 {
                let this->transactionLevel--;
            }

            return false;
        }

        let savepointName = this->getNestedTransactionSavepointName();

        /**
         * Notify the events manager about the rolled back savepoint
         */
        let eventsManager = <ManagerInterface> this->eventsManager;
        if typeof eventsManager == "object" {
            eventsManager->fire("db:rollbackSavepoint", this, savepointName);
        }

        /**
         * Reduce the transaction nesting level
         */
        let this->transactionLevel--;

        return this->rollbackSavepoint(savepointName);
    }

    /**
     * Returns PDO adapter DSN defaults as a key-value map.
     */
    abstract protected function getDsnDefaults() -> array;

    /**
     * Constructs the SQL statement (with parameters)
     *
     * @see https://stackoverflow.com/a/8403150
     */
    protected function prepareRealSql(string statement, array parameters) -> void
    {
        var key, result, value;
        array keys, values;

        let result = statement,
            values = parameters;
        if !empty parameters {
            let keys = [];

            for key, value in parameters {
                if typeof key === "string" {
                    let keys[] = "/:" . key . "/";
                } else {
                    let keys[] = "/[?]/";
                }

                if typeof value === "string" {
                    let values[key] = "'" . value . "'";
                } elseif typeof value === "array" {
                    let values[key] = "'" . implode("','", value) . "'";
                } elseif null === value {
                    let values[key] = "NULL";
                }
            }

            let result = preg_replace(keys, values, statement, 1);
        }

        let this->realSqlStatement = result;
    }
}
