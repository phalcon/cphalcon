
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db;

/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Interface for Phalcon\Db adapters
 */
interface AdapterInterface
{

	/**
	 * Constructor for Phalcon\Db\Adapter
	 */
	public function __construct(array! descriptor);

	/**
	 * Returns the first row in a SQL query result
	 *
	 * @param string sqlQuery
	 * @param int fetchMode
	 * @param int placeholders
	 * @return array
	 */
	public function fetchOne(string! sqlQuery, fetchMode = 2, placeholders = null);

	/**
	 * Dumps the complete result of a query into an array
	 *
	 * @param string sqlQuery
	 * @param int fetchMode
	 * @param int placeholders
	 * @return array
	 */
	public function fetchAll(string! sqlQuery, fetchMode = 2, placeholders = null);

	/**
	 * Inserts data into a table using custom RBDM SQL syntax
	 *
	 * @param 	string table
	 * @param 	array values
	 * @param 	array fields
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function insert(var table, array! values, fields = null, dataTypes = null);

	/**
	 * Updates data on a table using custom RBDM SQL syntax
	 *
	 * @param 	string table
	 * @param 	array fields
	 * @param 	array values
	 * @param 	string whereCondition
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function update(var table, fields, values, whereCondition = null, dataTypes = null);

	/**
	 * Deletes data from a table using custom RBDM SQL syntax
	 *
	 * @param  string table
	 * @param  string whereCondition
	 * @param  array placeholders
	 * @param  array dataTypes
	 * @return boolean
	 */
	public function delete(var table, whereCondition = null, placeholders = null, dataTypes = null);

	/**
	 * Gets a list of columns
	 *
	 * @param	array columnList
	 * @return	string
	 */
	public function getColumnList(columnList);

	/**
	 * Appends a LIMIT clause to sqlQuery argument
	 *
	 * @param  	string sqlQuery
	 * @param 	int number
	 * @return 	string
	 */
	public function limit(var sqlQuery, number);

	/**
	 * Generates SQL checking for the existence of a schema.table
	 */
	public function tableExists(string! tableName, string! schemaName = null) -> boolean;

	/**
	 * Generates SQL checking for the existence of a schema.view
	 */
	public function viewExists(string! viewName, string! schemaName = null) -> boolean;

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 */
	public function forUpdate(string! sqlQuery) -> string;

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 */
	public function sharedLock(string! sqlQuery) -> string;

	/**
	 * Creates a table
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> boolean;

	/**
	 * Drops a table from a schema/database
	 */
	public function dropTable(string! tableName, string! schemaName = null, boolean ifExists = true) -> boolean;

	/**
	 * Creates a view
	 */
	public function createView(string! viewName, array! definition, string schemaName = null) -> boolean;

	/**
	 * Drops a view
	 */
	public function dropView(string! viewName, string! schemaName = null, boolean ifExists = true) -> boolean;

	/**
	 * Adds a column to a table
	 */
	public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> boolean;

	/**
	 * Modifies a table column based on a definition
	 */
	public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> boolean;

	/**
	 * Drops a column from a table
	 */
	public function dropColumn(string! tableName, string! schemaName, string columnName) -> boolean;

	/**
	 * Adds an index to a table
	 */
	public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> boolean;

	/**
	 * Drop an index from a table
	 */
	public function dropIndex(string! tableName, string! schemaName, string indexName) -> boolean;

	/**
	 * Adds a primary key to a table
	 */
	public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> boolean;

	/**
	 * Drops primary key from a table
	 */
	public function dropPrimaryKey(string! tableName, string! schemaName) -> boolean;

	/**
	 * Adds a foreign key to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> boolean;

	/**
	 * Drops a foreign key from a table
	 */
	public function dropForeignKey(string! tableName, string! schemaName, string referenceName) -> boolean;

	/**
	 * Returns the SQL column definition from a column
	 */
	public function getColumnDefinition(<ColumnInterface> column) -> string;

	 /**
	 * List all tables on a database
	 */
	public function listTables(string! schemaName = null) -> array;

	/**
	 * List all views on a database
	 */
	public function listViews(string! schemaName = null) -> array;

	/**
	 * Return descriptor used to connect to the active database
	 *
	 * @return array
	 */
	public function getDescriptor();

	/**
	 * Gets the active connection unique identifier
	 *
	 * @return string
	 */
	public function getConnectionId();

	/**
	 * Active SQL statement in the object
	 */
	public function getSQLStatement() -> string;

	/**
	 * Active SQL statement in the object without replace bound paramters
	 */
	public function getRealSQLStatement() -> string;

	/**
	 * Active SQL statement in the object
	 *
	 * @return array
	 */
	public function getSQLVariables();

	/**
	 * Active SQL statement in the object
	 *
	 * @return array
	 */
	public function getSQLBindTypes();

	/**
	 * Returns type of database system the adapter is used for
	 *
	 * @return string
	 */
	public function getType();

	/**
	 * Returns the name of the dialect used
	 *
	 * @return string
	 */
	public function getDialectType();

	/**
	 * Returns internal dialect instance
	 */
	public function getDialect() -> <DialectInterface>;

	/**
	 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
	 * Call it when you need to restore a database connection
	 *
	 * @param 	array descriptor
	 * @return 	boolean
	 */
	public function connect(descriptor = null);

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server return rows
	 */
	public function query(string! sqlStatement, var placeholders = null, var dataTypes = null) -> <ResultInterface> | boolean;

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server doesn't return any rows	 
	 */
	public function execute(string! sqlStatement, var placeholders = null, var dataTypes = null) -> boolean;

	/**
	 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
	 */
	public function affectedRows() -> int;

	/**
	 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon\Db\Pool
	 */
	public function close() -> boolean;

	/**
	 * Escapes a column/table/schema name
	 *
	 * @param string identifier
	 * @return string
	 */
	public function escapeIdentifier(identifier) -> string;

	/**
	 * Escapes a value to avoid SQL injections
	 */
	public function escapeString(string! str) -> string;

	/**
	 * Returns insert id for the auto_increment column inserted in the last SQL statement
	 *
	 * @param string sequenceName
	 * @return int
	 */
	public function lastInsertId(sequenceName = null);

	/**
	 * Starts a transaction in the connection
	 */
	public function begin(boolean nesting = true) -> boolean;

	/**
	 * Rollbacks the active transaction in the connection
	 */
	public function rollback(boolean nesting = true) -> boolean;

	/**
	 * Commits the active transaction in the connection
	 */
	public function commit(boolean nesting = true) -> boolean;

	/**
	 * Checks whether connection is under database transaction
	 */
	public function isUnderTransaction() -> boolean;

	/**
	 * Return internal PDO handler
	 */
	public function getInternalHandler() -> <\Pdo>;

	/**
	 * Lists table indexes
	 */
	public function describeIndexes(string! table, string schema = null) -> <IndexInterface[]>;

	/**
	 * Lists table references
	 */
	public function describeReferences(string! table, string schema = null) -> <ReferenceInterface[]>;

	/**
	 * Gets creation options from a table
	 */
	public function tableOptions(string! tableName, string schemaName = null) -> array;

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 */
	public function useExplicitIdValue() -> boolean;

	/**
	 * Return the default identity value to insert in an identity column
	 */
	public function getDefaultIdValue() -> <RawValue>;

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 */
	public function supportSequences() -> boolean;

	/**
	 * Creates a new savepoint
	 */
	public function createSavepoint(string! name) -> boolean;

	/**
	 * Releases given savepoint
	 */
	public function releaseSavepoint(string! name) -> boolean;

	/**
	 * Rollbacks given savepoint
	 */
	public function rollbackSavepoint(string! name) -> boolean;

	/**
	 * Set if nested transactions should use savepoints
	 */
	public function setNestedTransactionsWithSavepoints(boolean nestedTransactionsWithSavepoints) -> <AdapterInterface>;

	/**
	 * Returns if nested transactions should use savepoints
	 */
	public function isNestedTransactionsWithSavepoints() -> boolean;

	/**
	 * Returns the savepoint name to use for nested transactions
	 */
	public function getNestedTransactionSavepointName() -> string;

	/**
	 * Returns an array of Phalcon\Db\Column objects describing a table
	 */
	public function describeColumns(string! table, string schema = null) -> <ColumnInterface[]>;

}
