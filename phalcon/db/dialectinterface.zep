
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
 * Phalcon\Db\DialectInterface
 *
 * Interface for Phalcon\Db dialects
 */
interface DialectInterface
{

	/**
	 * Generates the SQL for LIMIT clause
	 *
	 * @param string sqlQuery
	 * @param int number
	 * @return string
	 */
	public function limit(sqlQuery, number);

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
	 * Builds a SELECT statement
	 *
	 * @param array definition
	 * @return string
	 */
	public function select(definition);

	/**
	 * Gets a list of columns
	 *
	 * @param	array columnList
	 * @return	string
	 */
	public function getColumnList(columnList);

	/**
	 * Gets the column name in MySQL
	 *
	 * @param Phalcon\Db\ColumnInterface column
	 */
	public function getColumnDefinition(column);

	/**
	 * Generates SQL to add a column to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	string
	 */
	public function addColumn(tableName, schemaName, column);

	/**
	 * Generates SQL to modify a column in a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	string
	 */
	public function modifyColumn(tableName, schemaName, column);
	/**
	 * Generates SQL to delete a column from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string columnName
	 * @return 	string
	 */
	public function dropColumn(tableName, schemaName, columnName);

	/**
	 * Generates SQL to add an index to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\IndexInterface index
	 * @return	string
	 */
	public function addIndex(tableName, schemaName, index);

	/**
 	 * Generates SQL to delete an index from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string indexName
	 * @return	string
	 */
	public function dropIndex(tableName, schemaName, indexName);

	/**
	 * Generates SQL to add the primary key to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\IndexInterface index
	 * @return	string
	 */
	public function addPrimaryKey(tableName, schemaName, index);

	/**
	 * Generates SQL to delete primary key from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @return	string
	 */
	public function dropPrimaryKey(tableName, schemaName);

	/**
	 * Generates SQL to add an index to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ReferenceInterface reference
	 * @return	string
	 */
	public function addForeignKey(tableName, schemaName, reference);

	/**
	 * Generates SQL to delete a foreign key from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string referenceName
	 * @return	string
	 */
	public function dropForeignKey(tableName, schemaName, referenceName);

	/**
	 * Generates SQL to create a table
	 *
	 * @param 	string tableName
	 * @param	string schemaName
	 * @param	array definition
	 * @return 	string
	 */
	public function createTable(tableName, schemaName, definition);

	/**
	 * Generates SQL to drop a table
	 *
	 * @param string tableName
	 * @param string schemaName
	 * @return string
	 */
	public function dropTable(tableName, schemaName);

	/**
	 * Generates SQL checking for the existence of a schema.table
	 *
	 * @param string tableName
	 * @param string schemaName
	 * @return string
	 */
	public function tableExists(tableName, schemaName=null);

	/**
	 * Generates SQL to describe a table
	 *
	 * @param string table
	 * @param string schema
	 * @return string
	 */
	public function describeColumns(table, schema=null);

	/**
	 * List all tables on database
	 *
	 * @param       string schemaName
	 * @return      array
	 */
	public function listTables(schemaName=null);

	/**
	 * Generates SQL to query indexes on a table
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	string
	 */
	public function describeIndexes(table, schema=null);

	/**
	 * Generates SQL to query foreign keys on a table
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	string
	 */
	public function describeReferences(table, schema=null);

	/**
	 * Generates the SQL to describe the table creation options
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	string
	 */
	public function tableOptions(table, schema=null);

	/**
	 * Checks whether the platform supports savepoints
	 *
	 * @return boolean
	 */
	public function supportsSavepoints();

	/**
	 * Checks whether the platform supports releasing savepoints.
	 *
	 * @return boolean
	 */
	public function supportsReleaseSavepoints();

	/**
	 * Generate SQL to create a new savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function createSavepoint(name);

	/**
	 * Generate SQL to release a savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function releaseSavepoint(name);

	/**
	 * Generate SQL to rollback a savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function rollbackSavepoint(name);

}