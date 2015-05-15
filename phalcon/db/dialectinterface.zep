
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


use Phalcon\Db\ColumnInterface;
use Phalcon\Db\ReferenceInterface;
use Phalcon\Db\IndexInterface;


/**
 * Phalcon\Db\DialectInterface
 *
 * Interface for Phalcon\Db dialects
 */
interface DialectInterface
{

	/**
	 * Generates the SQL for LIMIT clause
	 */
	public function limit(string! sqlQuery, var number) -> string;

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 */
	public function forUpdate(string! sqlQuery) -> string;

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 */
	public function sharedLock(string! sqlQuery) -> string;

	/**
	 * Builds a SELECT statement
	 */
	public function select(array! definition) -> string;

	/**
	 * Gets a list of columns
	 */
	public function getColumnList(array! columnList) -> string;

	/**
	 * Gets the column name in RDBMS
	 */
	public function getColumnDefinition(<ColumnInterface> column) -> string;

	/**
	 * Generates SQL to add a column to a table
	 */
	public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> string;

	/**
	 * Generates SQL to modify a column in a table
	 */
	public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> string;

	/**
	 * Generates SQL to delete a column from a table
	 */
	public function dropColumn(string! tableName, string! schemaName, string! columnName) -> string;

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> string;

	/**
 	 * Generates SQL to delete an index from a table
	 */
	public function dropIndex(string! tableName, string! schemaName, string! indexName) -> string;

	/**
	 * Generates SQL to add the primary key to a table
	 */
	public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> string;

	/**
	 * Generates SQL to delete primary key from a table
	 */
	public function dropPrimaryKey(string! tableName, string! schemaName) -> string;

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> string;

	/**
	 * Generates SQL to delete a foreign key from a table
	 */
	public function dropForeignKey(string! tableName, string! schemaName, string! referenceName) -> string;

	/**
	 * Generates SQL to create a table
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> string;

	/**
	 * Generates SQL to create a view
	 */
	public function createView(string! viewName, array! definition, string schemaName = null) -> string;

	/**
	 * Generates SQL to drop a table
	 */
	public function dropTable(string! tableName, string! schemaName) -> string;

	/**
	 * Generates SQL to drop a view
	 */
	public function dropView(string! viewName, string schemaName = null, boolean! ifExists = true) -> string;

	/**
	 * Generates SQL checking for the existence of a schema.table
	 */
	public function tableExists(string! tableName, string schemaName = null) -> string;

	/**
	 * Generates SQL checking for the existence of a schema.view
	 */
	public function viewExists(string! viewName, string schemaName = null) -> string;

	/**
	 * Generates SQL to describe a table
	 */
	public function describeColumns(string! table, string schema = null) -> string;

	/**
	 * List all tables in database
	 */
	public function listTables(string schemaName = null) -> string;

	/**
	 * Generates SQL to query indexes on a table
	 */
	public function describeIndexes(string! table, string schema = null) -> string;

	/**
	 * Generates SQL to query foreign keys on a table
	 */
	public function describeReferences(string! table, string schema = null) -> string;

	/**
	 * Generates the SQL to describe the table creation options
	 */
	public function tableOptions(string! table, string schema = null) -> string;

	/**
	 * Checks whether the platform supports savepoints
	 */
	public function supportsSavepoints() -> boolean;

	/**
	 * Checks whether the platform supports releasing savepoints.
	 */
	public function supportsReleaseSavepoints() -> boolean;

	/**
	 * Generate SQL to create a new savepoint
	 */
	public function createSavepoint(string! name) -> string;

	/**
	 * Generate SQL to release a savepoint
	 */
	public function releaseSavepoint(string! name) -> string;

	/**
	 * Generate SQL to rollback a savepoint
	 */
	public function rollbackSavepoint(string! name) -> string;

}
