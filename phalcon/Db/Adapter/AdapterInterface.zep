
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Adapter;

use Phalcon\Db\DialectInterface;
use Phalcon\Db\ResultInterface;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\RawValue;
use Phalcon\Db\ReferenceInterface;

/**
 * Interface for Phalcon\Db adapters
 */
interface AdapterInterface
{
    /**
     * Adds a column to a table
     */
    public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> bool;

    /**
     * Adds an index to a table
     */
    public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> bool;

    /**
     * Adds a foreign key to a table
     */
    public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> bool;

    /**
     * Adds a primary key to a table
     */
    public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> bool;

    /**
     * Returns the number of affected rows by the last INSERT/UPDATE/DELETE
     * reported by the database system
     */
    public function affectedRows() -> int;

    /**
     * Starts a transaction in the connection
     */
    public function begin(bool nesting = true) -> bool;

    /**
     * Closes active connection returning success. Phalcon automatically closes
     * and destroys active connections within Phalcon\Db\Pool
     */
    public function close() -> bool;

    /**
     * Commits the active transaction in the connection
     */
    public function commit(bool nesting = true) -> bool;

    /**
     * This method is automatically called in \Phalcon\Db\Adapter\Pdo
     * constructor. Call it when you need to restore a database connection
     */
    public function connect(array descriptor = null) -> bool;

    /**
     * Creates a new savepoint
     */
    public function createSavepoint(string! name) -> bool;

    /**
     * Creates a table
     */
    public function createTable(string! tableName, string! schemaName, array! definition) -> bool;

    /**
     * Creates a view
     */
    public function createView(string! viewName, array! definition, string schemaName = null) -> bool;

    /**
     * Deletes data from a table using custom RDBMS SQL syntax
     *
     * @param array|string table
     * @param string|null whereCondition
     * @param array placeholders
     * @param array dataTypes
     *
     * @return bool
     */
    public function delete(var table, string whereCondition = null, array placeholders = [], array dataTypes = []) -> bool;

    /**
     * Returns an array of Phalcon\Db\Column objects describing a table
     */
    public function describeColumns(string! table, string schema = null) -> <ColumnInterface[]>;

    /**
     * Lists table indexes
     */
    public function describeIndexes(string! table, string schema = null) -> <IndexInterface[]>;

    /**
     * Lists table references
     */
    public function describeReferences(string! table, string schema = null) -> <ReferenceInterface[]>;

    /**
     * Drops a column from a table
     */
    public function dropColumn(string! tableName, string! schemaName, string columnName) -> bool;

    /**
     * Drops a foreign key from a table
     */
    public function dropForeignKey(string! tableName, string! schemaName, string referenceName) -> bool;

    /**
     * Drop an index from a table
     */
    public function dropIndex(string! tableName, string! schemaName, string indexName) -> bool;

    /**
     * Drops primary key from a table
     */
    public function dropPrimaryKey(string! tableName, string! schemaName) -> bool;

    /**
     * Drops a table from a schema/database
     */
    public function dropTable(string! tableName, string! schemaName = null, bool ifExists = true) -> bool;

    /**
     * Drops a view
     */
    public function dropView(string! viewName, string! schemaName = null, bool ifExists = true) -> bool;

    /**
     * Escapes a column/table/schema name
     */
    public function escapeIdentifier(identifier) -> string;

    /**
     * Escapes a value to avoid SQL injections
     */
    public function escapeString(string! str) -> string;

    /**
     * Sends SQL statements to the database server returning the success state.
     * Use this method only when the SQL statement sent to the server doesn't
     * return any rows
     */
    public function execute(string! sqlStatement, array! bindParams = [], array! bindTypes = []) -> bool;

    /**
     * Dumps the complete result of a query into an array
     */
    public function fetchAll(string! sqlQuery, int fetchMode = 2, array bindParams = [], array bindTypes = []) -> array;

    /**
     * Returns the n'th field of first row in a SQL query result
     *
     *```php
     * // Getting count of robots
     * $robotsCount = $connection->fetchColumn("SELECT COUNT(*) FROM robots");
     * print_r($robotsCount);
     *
     * // Getting name of last edited robot
     * $robot = $connection->fetchColumn(
     *     "SELECT id, name FROM robots ORDER BY modified DESC",
     *     1
     * );
     * print_r($robot);
     *```
     */
    public function fetchColumn(string sqlQuery, array placeholders = [], var column = 0) -> string | bool;

    /**
     * Returns the first row in a SQL query result
     */
    public function fetchOne(string! sqlQuery, int fetchMode = 2, array bindParams = [], array bindTypes = []) -> array;

    /**
     * Returns a SQL modified with a FOR UPDATE clause
     */
    public function forUpdate(string! sqlQuery) -> string;

    /**
     * Returns the SQL column definition from a column
     */
    public function getColumnDefinition(<ColumnInterface> column) -> string;

    /**
     * Gets a list of columns
     */
    public function getColumnList(var columnList) -> string;

    /**
     * Gets the active connection unique identifier
     */
    public function getConnectionId() -> string;

    /**
     * Return descriptor used to connect to the active database
     */
    public function getDescriptor() -> array;

    /**
     * Returns internal dialect instance
     */
    public function getDialect() -> <DialectInterface>;

    /**
     * Returns the name of the dialect used
     */
    public function getDialectType() -> string;

    /**
     * Return the default identity value to insert in an identity column
     */
    public function getDefaultIdValue() -> <RawValue>;

    /**
     * Returns the default value to make the RBDM use the default value declared
     * in the table definition
     *
     *```php
     * // Inserting a new robot with a valid default value for the column 'year'
     * $success = $connection->insert(
     *     "robots",
     *     [
     *         "Astro Boy",
     *         $connection->getDefaultValue()
     *     ],
     *     [
     *         "name",
     *         "year",
     *     ]
     * );
     *```
     *
     * @todo Return NULL if this is not supported by the adapter
     */
    public function getDefaultValue() -> <RawValue>;

    /**
     * Return internal PDO handler
     */
    public function getInternalHandler() -> <\PDO>;

    /**
     * Returns the savepoint name to use for nested transactions
     */
    public function getNestedTransactionSavepointName() -> string;

    /**
     * Active SQL statement in the object without replace bound parameters
     */
    public function getRealSQLStatement() -> string;

    /**
     * Active SQL statement in the object
     */
    public function getSQLStatement() -> string;

    /**
     * Active SQL statement in the object
     */
    public function getSQLBindTypes() -> array;

    /**
     * Active SQL statement in the object
     */
    public function getSQLVariables() -> array;

    /**
     * Returns type of database system the adapter is used for
     */
    public function getType() -> string;

    /**
     * Inserts data into a table using custom RDBMS SQL syntax
     */
    public function insert(string table, array! values, fields = null, dataTypes = null) -> bool;

    /**
     * Inserts data into a table using custom RBDM SQL syntax
     *
     * ```php
     * // Inserting a new robot
     * $success = $connection->insertAsDict(
     *     "robots",
     *     [
     *         "name" => "Astro Boy",
     *         "year" => 1952,
     *     ]
     * );
     *
     * // Next SQL sentence is sent to the database system
     * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
     * ```
     */
    public function insertAsDict(string table, data, var dataTypes = null) -> bool;

    /**
     * Returns if nested transactions should use savepoints
     */
    public function isNestedTransactionsWithSavepoints() -> bool;

    /**
     * Checks whether connection is under database transaction
     */
    public function isUnderTransaction() -> bool;

    /**
     * Returns insert id for the auto_increment column inserted in the last SQL
     * statement
     */
    public function lastInsertId(sequenceName = null);

    /**
     * Appends a LIMIT clause to sqlQuery argument
     */
    public function limit(string! sqlQuery, int number) -> string;

    /**
     * List all tables on a database
     */
    public function listTables(string! schemaName = null) -> array;

    /**
     * List all views on a database
     */
    public function listViews(string! schemaName = null) -> array;

    /**
     * Modifies a table column based on a definition
     */
    public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> bool;

    /**
     * Sends SQL statements to the database server returning the success state.
     * Use this method only when the SQL statement sent to the server returns
     * rows
     */
    public function query(string! sqlStatement, array! bindParams = [], array! bindTypes = []) -> <ResultInterface> | bool;

    /**
     * Releases given savepoint
     */
    public function releaseSavepoint(string! name) -> bool;

    /**
     * Rollbacks the active transaction in the connection
     */
    public function rollback(bool nesting = true) -> bool;

    /**
     * Rollbacks given savepoint
     */
    public function rollbackSavepoint(string! name) -> bool;

    /**
     * Returns a SQL modified with a LOCK IN SHARE MODE clause
     */
    public function sharedLock(string! sqlQuery) -> string;

    /**
     * Set if nested transactions should use savepoints
     */
    public function setNestedTransactionsWithSavepoints(bool nestedTransactionsWithSavepoints) -> <AdapterInterface>;

    /**
     * Check whether the database system requires a sequence to produce
     * auto-numeric values
     */
    public function supportSequences() -> bool;

    /**
     * Generates SQL checking for the existence of a schema.table
     */
    public function tableExists(string! tableName, string! schemaName = null) -> bool;

    /**
     * Gets creation options from a table
     */
    public function tableOptions(string! tableName, string schemaName = null) -> array;

    /**
     * Updates data on a table using custom RDBMS SQL syntax
     */
    public function update(string table, fields, values, whereCondition = null, dataTypes = null) -> bool;

    /**
     * Updates data on a table using custom RBDM SQL syntax
     * Another, more convenient syntax
     *
     * ```php
     * // Updating existing robot
     * $success = $connection->updateAsDict(
     *     "robots",
     *     [
     *         "name" => "New Astro Boy",
     *     ],
     *     "id = 101"
     * );
     *
     * // Next SQL sentence is sent to the database system
     * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
     * ```
     */
    public function updateAsDict(string table, var data, var whereCondition = null, var dataTypes = null) -> bool;

    /**
     * Check whether the database system requires an explicit value for identity
     * columns
     */
    public function useExplicitIdValue() -> bool;

    /**
     * SQLite does not support the DEFAULT keyword
     *
     * @deprecated Will re removed in the next version
     */
    public function supportsDefaultValue() -> bool;

    /**
     * Generates SQL checking for the existence of a schema.view
     */
    public function viewExists(string! viewName, string! schemaName = null) -> bool;
}
