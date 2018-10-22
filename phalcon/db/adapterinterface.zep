
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

/**
 * Phalcon\Db\AdapterInterface
 *
 * Interface for Phalcon\Db adapters
 */
interface AdapterInterface
{
	/**
	 * Adds a column to a table
	 */
	public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> boolean;

	/**
	 * Adds an index to a table
	 */
	public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> boolean;

	/**
	 * Adds a foreign key to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> boolean;

	/**
	 * Adds a primary key to a table
	 */
	public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> boolean;

	/**
	 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
	 */
	public function affectedRows() -> int;

	/**
	 * Starts a transaction in the connection
	 */
	public function begin(boolean nesting = true) -> boolean;

	/**
	 * Closes active connection returning success. Phalcon automatically closes
	 * and destroys active connections within Phalcon\Db\Pool
	 */
	public function close() -> boolean;

	/**
	 * Commits the active transaction in the connection
	 */
	public function commit(boolean nesting = true) -> boolean;

	/**
	 * This method is automatically called in \Phalcon\Db\Adapter\Pdo constructor.
	 * Call it when you need to restore a database connection
	 */
	public function connect(array descriptor = null) -> boolean;

	/**
	 * Creates a new savepoint
	 */
	public function createSavepoint(string! name) -> boolean;

	/**
	 * Creates a table
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> boolean;

	/**
	 * Creates a view
	 */
	public function createView(string! viewName, array! definition, string schemaName = null) -> boolean;

	/**
	 * Deletes data from a table using custom RDBMS SQL syntax
	 *
	 * @param  string whereCondition
	 * @param  array placeholders
	 * @param  array dataTypes
	 */
	public function delete(string table, whereCondition = null, placeholders = null, dataTypes = null) -> boolean;

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
	public function dropColumn(string! tableName, string! schemaName, string columnName) -> boolean;

	/**
	 * Drops a foreign key from a table
	 */
	public function dropForeignKey(string! tableName, string! schemaName, string referenceName) -> boolean;

	/**
	 * Drop an index from a table
	 */
	public function dropIndex(string! tableName, string! schemaName, string indexName) -> boolean;

	/**
	 * Drops primary key from a table
	 */
	public function dropPrimaryKey(string! tableName, string! schemaName) -> boolean;

	/**
	 * Drops a table from a schema/database
	 */
	public function dropTable(string! tableName, string! schemaName = null, boolean ifExists = true) -> boolean;

	/**
	 * Drops a view
	 */
	public function dropView(string! viewName, string! schemaName = null, boolean ifExists = true) -> boolean;

	/**
	 * Escapes a column/table/schema name
	 *
	 * @param string identifier
	 */
	public function escapeIdentifier(identifier) -> string;

	/**
	 * Escapes a value to avoid SQL injections
	 */
	public function escapeString(string! str) -> string;

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server doesn't return any rows
	 */
	public function execute(string! sqlStatement, var placeholders = null, var dataTypes = null) -> boolean;

	/**
	 * Dumps the complete result of a query into an array
	 *
	 * @param int placeholders
	 */
	public function fetchAll(string! sqlQuery, int fetchMode = 2, placeholders = null) -> array;

	/**
	 * Returns the first row in a SQL query result
	 *
	 * @param int placeholders
	 */
	public function fetchOne(string! sqlQuery, int fetchMode = 2, placeholders = null) -> array;

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
	 *
	 * @param	array columnList
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
	 * Return internal PDO handler
	 */
	public function getInternalHandler() -> <\Pdo>;

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
	 *
	 * @param 	array fields
	 * @param 	array dataTypes
	 */
	public function insert(string table, array! values, fields = null, dataTypes = null) -> boolean;

	/**
	 * Returns if nested transactions should use savepoints
	 */
	public function isNestedTransactionsWithSavepoints() -> boolean;

	/**
	 * Checks whether connection is under database transaction
	 */
	public function isUnderTransaction() -> boolean;

	/**
	 * Returns insert id for the auto_increment column inserted in the last SQL statement
	 *
	 * @param string sequenceName
	 * @return int
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
	public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> boolean;

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server return rows
	 */
	public function query(string! sqlStatement, var placeholders = null, var dataTypes = null) -> <ResultInterface> | boolean;

	/**
	 * Releases given savepoint
	 */
	public function releaseSavepoint(string! name) -> boolean;

	/**
	 * Rollbacks the active transaction in the connection
	 */
	public function rollback(boolean nesting = true) -> boolean;

	/**
	 * Rollbacks given savepoint
	 */
	public function rollbackSavepoint(string! name) -> boolean;

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 */
	public function sharedLock(string! sqlQuery) -> string;

	/**
	 * Set if nested transactions should use savepoints
	 */
	public function setNestedTransactionsWithSavepoints(boolean nestedTransactionsWithSavepoints) -> <AdapterInterface>;

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 */
	public function supportSequences() -> boolean;

	/**
	 * Generates SQL checking for the existence of a schema.table
	 */
	public function tableExists(string! tableName, string! schemaName = null) -> boolean;

	/**
	 * Gets creation options from a table
	 */
	public function tableOptions(string! tableName, string schemaName = null) -> array;

	/**
	 * Updates data on a table using custom RDBMS SQL syntax
	 *
	 * @param 	array fields
	 * @param 	array values
	 * @param 	string whereCondition
	 * @param 	array dataTypes
	 */
	public function update(string table, fields, values, whereCondition = null, dataTypes = null) -> boolean;

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 */
	public function useExplicitIdValue() -> boolean;

	/**
	 * Generates SQL checking for the existence of a schema.view
	 */
	public function viewExists(string! viewName, string! schemaName = null) -> boolean;

}
