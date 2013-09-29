
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
	 *
	 * @param array descriptor
	 */
	public function __construct(descriptor);

	/**
	 * Returns the first row in a SQL query result
	 *
	 * @param string sqlQuery
	 * @param int fetchMode
	 * @param int placeholders
	 * @return array
	 */
	public function fetchOne(sqlQuery, fetchMode=2, placeholders=null);

	/**
	 * Dumps the complete result of a query into an array
	 *
	 * @param string sqlQuery
	 * @param int fetchMode
	 * @param int placeholders
	 * @return array
	 */
	public function fetchAll(sqlQuery, fetchMode=2, placeholders=null);

	/**
	 * Inserts data into a table using custom RBDM SQL syntax
	 *
	 * @param 	string table
	 * @param 	array values
	 * @param 	array fields
	 * @param 	array dataTypes
	 * @return 	boolean
	 */
	public function insert(table, values, fields=null, dataTypes=null);

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
	public function update(table, fields, values, whereCondition=null, dataTypes=null);

	/**
	 * Deletes data from a table using custom RBDM SQL syntax
	 *
	 * @param  string table
	 * @param  string whereCondition
	 * @param  array placeholders
	 * @param  array dataTypes
	 * @return boolean
	 */
	public function delete(table, whereCondition=null, placeholders=null, dataTypes=null);

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
	public function limit(sqlQuery, number);

	/**
	 * Generates SQL checking for the existence of a schema.table
	 *
	 * @param string tableName
	 * @param string schemaName
	 * @return string
	 */
	public function tableExists(tableName, schemaName=null);

	/**
	 * Generates SQL checking for the existence of a schema.view
	 *
	 * @param string viewName
	 * @param string schemaName
	 * @return string
	 */
	public function viewExists(viewName, schemaName=null);

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 *
	 * @param	string sqlQuery
	 * @return	string
	 */
	public function forUpdate(sqlQuery);

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 *
	 * @param	string sqlQuery
	 * @return	string
	 */
	public function sharedLock(sqlQuery);

	/**
	 * Creates a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	array definition
	 * @return	boolean
	 */
	public function createTable(tableName, schemaName, definition);

	/**
	 * Drops a table from a schema/database
	 *
	 * @param	string tableName
	 * @param   string schemaName
	 * @param	boolean ifExists
	 * @return	boolean
	 */
	public function dropTable(tableName, schemaName=null, ifExists=true);

	/**
	 * Creates a view
	 *
	 * @param	string tableName
	 * @param	array definition
	 * @param	string schemaName
	 * @return	boolean
	 */
	public function createView(viewName, definition, schemaName=null);

	/**
	 * Drops a view
	 *
	 * @param	string viewName
	 * @param   string schemaName
	 * @param	boolean ifExists
	 * @return	boolean
	 */
	public function dropView(viewName, schemaName=null, ifExists=true);

	/**
	 * Adds a column to a table
	 *
	 * @param	string tableName
	 * @param 	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	boolean
	 */
	public function addColumn(tableName, schemaName, column);

	/**
	 * Modifies a table column based on a definition
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return 	boolean
	 */
	public function modifyColumn(tableName, schemaName, column);

	/**
	 * Drops a column from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string columnName
	 * @return 	boolean
	 */
	public function dropColumn(tableName, schemaName, columnName);

	/**
	 * Adds an index to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\IndexInterface index
	 * @return 	boolean
	 */
	public function addIndex(tableName, schemaName, index);

	/**
	 * Drop an index from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string indexName
	 * @return 	boolean
	 */
	public function dropIndex(tableName, schemaName, indexName);

	/**
	 * Adds a primary key to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\IndexInterface index
	 * @return 	boolean
	 */
	public function addPrimaryKey(tableName, schemaName, index);

	/**
	 * Drops primary key from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @return 	boolean
	 */
	public function dropPrimaryKey(tableName, schemaName);

	/**
	 * Adds a foreign key to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ReferenceInterface reference
	 * @return	boolean true
	 */
	public function addForeignKey(tableName, schemaName, reference);

	/**
	 * Drops a foreign key from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string referenceName
	 * @return	boolean true
	 */
	public function dropForeignKey(tableName, schemaName, referenceName);

	/**
	 * Returns the SQL column definition from a column
	 *
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	string
	 */
	public function getColumnDefinition(column);

	 /**
	 * List all tables on a database
	 *
	 * @param string schemaName
	 * @return array
	 */
	public function listTables(schemaName=null);

	/**
	 * List all views on a database
	 *
	 * @param string schemaName
	 * @return array
	 */
	public function listViews(schemaName=null);

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
	 *
	 * @return string
	 */
	public function getSQLStatement();

	/**
	 * Active SQL statement in the object without replace bound paramters
	 *
	 * @return string
	 */
	public function getRealSQLStatement();

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
	 *
	 * @return Phalcon\Db\DialectInterface
	 */
	public function getDialect();

	/**
	 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
	 * Call it when you need to restore a database connection
	 *
	 * @param 	array descriptor
	 * @return 	boolean
	 */
	public function connect(descriptor=null);

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server return rows
	 *
	 * @param  string sqlStatement
	 * @param  array placeholders
	 * @param  array dataTypes
	 * @return Phalcon\Db\ResultInterface
	 */
	public function query(sqlStatement, placeholders=null, dataTypes=null);

	/**
	 * Sends SQL statements to the database server returning the success state.
	 * Use this method only when the SQL statement sent to the server don't return any row
	 *
	 * @param  string sqlStatement
	 * @param  array placeholders
	 * @param  array dataTypes
	 * @return boolean
	 */
	public function execute(sqlStatement, placeholders=null, dataTypes=null);

	/**
	 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
	 *
	 * @return int
	 */
	public function affectedRows();

	/**
	 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon\Db\Pool
	 *
	 * @return boolean
	 */
	public function close();

	/**
	 * Escapes a column/table/schema name
	 *
	 * @param string identifier
	 * @return string
	 */
	public function escapeIdentifier(identifier);

	/**
	 * Escapes a value to avoid SQL injections
	 *
	 * @param string str
	 * @return string
	 */
	public function escapeString(str);

	/**
	 * Returns insert id for the auto_increment column inserted in the last SQL statement
	 *
	 * @param string sequenceName
	 * @return int
	 */
	public function lastInsertId(sequenceName=null);

	/**
     * Starts a transaction in the connection
     *
     * @return boolean
     */
	public function begin(boolean nesting=true);

    /**
     * Rollbacks the active transaction in the connection
     *
     * @return boolean
     */
	public function rollback(boolean nesting=true);

    /**
     * Commits the active transaction in the connection
     *
     * @return boolean
     */
	public function commit(boolean nesting=true);

	/**
	 * Checks whether connection is under database transaction
	 *
	 * @return boolean
	 */
	public function isUnderTransaction();

	/**
	 * Return internal PDO handler
	 *
	 * @return \PDO
	 */
	public function getInternalHandler();

	/**
	 * Lists table indexes
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	Phalcon\Db\IndexInterface[]
	 */
	public function describeIndexes(table, schema=null);

	/**
	 * Lists table references
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	Phalcon\Db\ReferenceInterface[]
	 */
	public function describeReferences(table, schema=null);

	/**
	 * Gets creation options from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @return	array
	 */
	public function tableOptions(tableName, schemaName=null);

	/**
	 * Check whether the database system requires an explicit value for identity columns
	 *
	 * @return boolean
	 */
	public function useExplicitIdValue();

	/**
	 * Return the default identity value to insert in an identity column
	 *
	 * @return Phalcon\Db\RawValue
	 */
	public function getDefaultIdValue();

	/**
	 * Check whether the database system requires a sequence to produce auto-numeric values
	 *
	 * @return boolean
	 */
	public function supportSequences();


	/**
	 * Creates a new savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function createSavepoint(name);

	/**
	 * Releases given savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function releaseSavepoint(name);

	/**
	 * Rollbacks given savepoint
	 *
	 * @param string name
	 * @return boolean
	 */
	public function rollbackSavepoint(name);

	/**
	 * Set if nested transactions should use savepoints
	 *
	 * @param boolean nestedTransactionsWithSavepoints
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function setNestedTransactionsWithSavepoints(nestedTransactionsWithSavepoints) -> <Phalcon\Db\AdapterInterface>;

	/**
	 * Returns if nested transactions should use savepoints
	 *
	 * @return boolean
	 */
	public function isNestedTransactionsWithSavepoints();

	/**
	 * Returns the savepoint name to use for nested transactions
	 *
	 * @return string
	 */
	public function getNestedTransactionSavepointName();

	/**
	 * Returns an array of Phalcon\Db\Column objects describing a table
	 *
	 * @param string table
	 * @param string schema
	 * @return Phalcon\Db\ColumnInterface[]
	 */
	public function describeColumns(table, schema=null);

}
