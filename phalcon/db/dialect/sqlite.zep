
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Rack Lin <racklin@gmail.com>                                  |
 |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db\Dialect;

use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\Dialect;
use Phalcon\Db\DialectInterface;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\ReferenceInterface;

/**
 * Phalcon\Db\Dialect\Sqlite
 *
 * Generates database specific SQL for the Sqlite RDBMS
 */
class Sqlite extends Dialect
{

	protected _escapeChar = "\"";

	/**
	 * Gets the column name in SQLite
	 */
	public function getColumnDefinition(<ColumnInterface> column) -> string
	{
		var columnSql, type, typeValues;

		let columnSql = "";

		let type = column->getType();
		if typeof type == "string" {
			let columnSql .= type;
			let type = column->getTypeReference();
		}

		// SQLite has dynamic column typing. The conversion below maximizes
		// compatibility with other DBMS's while following the type affinity
		// rules: http://www.sqlite.org/datatype3.html.
		switch type {

			case Column::TYPE_INTEGER:
				if empty columnSql {
					let columnSql .= "INTEGER";
				}
				break;

			case Column::TYPE_DATE:
				if empty columnSql {
					let columnSql .= "DATE";
				}
				break;

			case Column::TYPE_VARCHAR:
				if empty columnSql {
					let columnSql .= "VARCHAR";
				}
				let columnSql .= "(" . column->getSize() . ")";
				break;

			case Column::TYPE_DECIMAL:
				if empty columnSql {
					let columnSql .= "NUMERIC";
				}
				let columnSql .= "(" . column->getSize() . "," . column->getScale() . ")";
				break;

			case Column::TYPE_DATETIME:
				if empty columnSql {
					let columnSql .= "DATETIME";
				}
				break;

			case Column::TYPE_TIMESTAMP:
				if empty columnSql {
					let columnSql .= "TIMESTAMP";
				}
				break;

			case Column::TYPE_CHAR:
				if empty columnSql {
					let columnSql .= "CHARACTER";
				}
				let columnSql .= "(" . column->getSize() . ")";
				break;

			case Column::TYPE_TEXT:
				if empty columnSql {
					let columnSql .= "TEXT";
				}
				break;

			case Column::TYPE_BOOLEAN:
				if empty columnSql {
					let columnSql .= "TINYINT";
				}
				break;

			case Column::TYPE_FLOAT:
				if empty columnSql {
					let columnSql .= "FLOAT";
				}
				break;

			case Column::TYPE_DOUBLE:
				if empty columnSql {
					let columnSql .= "DOUBLE";
				}
				if column->isUnsigned() {
					let columnSql .= " UNSIGNED";
				}
				break;

			case Column::TYPE_BIGINTEGER:
				if empty columnSql {
					let columnSql .= "BIGINT";
				}
				if column->isUnsigned() {
					let columnSql .= " UNSIGNED";
				}
				break;

			case Column::TYPE_TINYBLOB:
				if empty columnSql {
					let columnSql .= "TINYBLOB";
				}
				break;

			case Column::TYPE_BLOB:
				if empty columnSql {
					let columnSql .= "BLOB";
				}
				break;

			case Column::TYPE_MEDIUMBLOB:
				if empty columnSql {
					let columnSql .= "MEDIUMBLOB";
				}
				break;

			case Column::TYPE_LONGBLOB:
				if empty columnSql {
					let columnSql .= "LONGBLOB";
				}
				break;

			default:
				if empty columnSql {
					throw new Exception("Unrecognized SQLite data type at column " . column->getName());
				}

				let typeValues = column->getTypeValues();
				if !empty typeValues {
					if typeof typeValues == "array" {
						var value, valueSql;
						let valueSql = "";
						for value in typeValues {
							let valueSql .= "\"" . addcslashes(value, "\"") . "\", ";
						}
						let columnSql .= "(" . substr(valueSql, 0, -2) . ")";
					} else {
						let columnSql .= "(\"" . addcslashes(typeValues, "\"") . "\")";
					}
				}
		}

		return columnSql;
	}

	/**
	 * Generates SQL to add a column to a table
	 */
	public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> string
	{
		var sql, defaultValue;

		let sql = "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " ADD COLUMN ";

		let sql .= "\"" . column->getName() . "\" " . this->getColumnDefinition(column);

		if column->hasDefault() {
			let defaultValue = column->getDefault();
			if memstr(strtoupper(defaultValue), "CURRENT_TIMESTAMP") {
				let sql .= " DEFAULT CURRENT_TIMESTAMP";
			} else {
				let sql .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
			}
		}

		if column->isNotNull() {
			let sql .= " NOT NULL";
		}

		if column->isAutoincrement() {
			let sql .= " PRIMARY KEY AUTOINCREMENT";
		}

		return sql;
	}

	/**
	 * Generates SQL to modify a column in a table
	 */
	public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> string
	{
		throw new Exception("Altering a DB column is not supported by SQLite");
	}

	/**
	 * Generates SQL to delete a column from a table
	 */
	public function dropColumn(string! tableName, string! schemaName, string! columnName) -> string
	{
		throw new Exception("Dropping DB column is not supported by SQLite");
	}

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> string
	{
		var sql, indexType;

		let indexType = index->getType();

		if !empty indexType {
			let sql = "CREATE " . indexType . " INDEX \"";
		} else {
			let sql = "CREATE INDEX \"";
		}

		if schemaName {
			let sql .= schemaName . "\".\"" . index->getName() . "\" ON \"" . tableName . "\" (";
		} else {
			let sql .= index->getName() . "\" ON \"" . tableName . "\" (";
		}

		let sql .= this->getColumnList(index->getColumns()) . ")";
		return sql;
	}

	/**
	 * Generates SQL to delete an index from a table
	 */
	public function dropIndex(string! tableName, string! schemaName, string! indexName) -> string
	{
		if schemaName {
			return "DROP INDEX \"" . schemaName . "\".\"" . indexName . "\"";
		}
		return "DROP INDEX \"" . indexName . "\"";
	}

	/**
	 * Generates SQL to add the primary key to a table
	 */
	public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> string
	{
		throw new Exception("Adding a primary key after table has been created is not supported by SQLite");
	}

	/**
	 * Generates SQL to delete primary key from a table
	 */
	public function dropPrimaryKey(string! tableName, string! schemaName) -> string
	{
		throw new Exception("Removing a primary key after table has been created is not supported by SQLite");
	}

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> string
	{
		throw new Exception("Adding a foreign key constraint to an existing table is not supported by SQLite");
	}

	/**
	 * Generates SQL to delete a foreign key from a table
	 */
	public function dropForeignKey(string! tableName, string! schemaName, string! referenceName) -> string
	{
		throw new Exception("Dropping a foreign key constraint is not supported by SQLite");
	}

	/**
	 * Generates SQL to create a table
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> string
	{
		var columns, table, temporary, options, createLines, columnLine, column,
			indexes, index, indexName, indexType, references, reference, defaultValue,
			referenceSql, onDelete, onUpdate, sql, hasPrimary;

		let table = this->prepareTable(tableName, schemaName);

		let temporary = false;
		if fetch options, definition["options"] {
			fetch temporary, options["temporary"];
		}

		if !fetch columns, definition["columns"] {
			throw new Exception("The index 'columns' is required in the definition array");
		}

		/**
		 * Create a temporary or normal table
		 */
		if temporary {
			let sql = "CREATE TEMPORARY TABLE " . table . " (\n\t";
		} else {
			let sql = "CREATE TABLE " . table . " (\n\t";
		}

		let hasPrimary = false;
		let createLines = [];

		for column in columns {
			let columnLine = "`" . column->getName() . "` " . this->getColumnDefinition(column);

			/**
			 * Mark the column as primary key
			 */
			if column->isPrimary() && !hasPrimary {
				let columnLine .= " PRIMARY KEY";
				let hasPrimary = true;
			}

			/**
			 * Add an AUTOINCREMENT clause
			 */
			if column->isAutoIncrement() && hasPrimary {
				let columnLine .= " AUTOINCREMENT";
			}

			/**
			 * Add a Default clause
			 */
			if column->hasDefault() {
				let defaultValue = column->getDefault();
				if memstr(strtoupper(defaultValue), "CURRENT_TIMESTAMP") {
					let columnLine .= " DEFAULT CURRENT_TIMESTAMP";
				} else {
					let columnLine .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
				}
			}

			/**
			 * Add a NOT NULL clause
			 */
			if column->isNotNull() {
				let columnLine .= " NOT NULL";
			}

			let createLines[] = columnLine;
		}

		/**
		 * Create related indexes
		 */
		if fetch indexes, definition["indexes"] {

			for index in indexes {

				let indexName = index->getName();
				let indexType = index->getType();

				/**
				 * If the index name is primary we add a primary key
				 */
				if indexName == "PRIMARY" && !hasPrimary {
					let createLines[] = "PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";
				} elseif !empty indexType && memstr(strtoupper(indexType), "UNIQUE") {
					let createLines[] = "UNIQUE (" . this->getColumnList(index->getColumns()) . ")";
				}
			}
		}

		/**
		 * Create related references
		 */
		if fetch references, definition["references"] {
			for reference in references {
				let referenceSql = "CONSTRAINT `" . reference->getName() . "` FOREIGN KEY (" . this->getColumnList(reference->getColumns()) . ")"
					. " REFERENCES `" . reference->getReferencedTable() . "`(" . this->getColumnList(reference->getReferencedColumns()) . ")";

				let onDelete = reference->getOnDelete();
				if !empty onDelete {
					let referenceSql .= " ON DELETE " . onDelete;
				}

				let onUpdate = reference->getOnUpdate();
				if !empty onUpdate {
					let referenceSql .= " ON UPDATE " . onUpdate;
				}

				let createLines[] = referenceSql;
			}
		}

		let sql .= join(",\n\t", createLines) . "\n)";

		return sql;
	}

	/**
	 * Generates SQL to truncate a table
	 */
	public function truncateTable(string! tableName, string! schemaName) -> string
	{
		var sql, table;

		if schemaName {
			let table = schemaName . "\".\"" . tableName;
		} else {
			let table = tableName;
		}

		let sql = "DELETE FROM \"" . table . "\"";

		return sql;
	}

	/**
	 * Generates SQL to drop a table
	 */
	public function dropTable(string! tableName, string schemaName = null, boolean! ifExists = true) -> string
	{
		var sql, table;

		let table = this->prepareTable(tableName, schemaName);

		if ifExists {
			let sql = "DROP TABLE IF EXISTS " . table;
		} else {
			let sql = "DROP TABLE " . table;
		}

		return sql;
	}

	/**
	 * Generates SQL to create a view
	 */
	public function createView(string! viewName, array! definition, string schemaName = null) -> string
	{
		var viewSql;

		if !fetch viewSql, definition["sql"] {
			throw new Exception("The index 'sql' is required in the definition array");
		}

		return "CREATE VIEW " . this->prepareTable(viewName, schemaName) . " AS " . viewSql;
	}

	/**
	 * Generates SQL to drop a view
	 */
	public function dropView(string! viewName, string schemaName = null, boolean! ifExists = true) -> string
	{
		var view;

		let view = this->prepareTable(viewName, schemaName);

		if ifExists {
			return "DROP VIEW IF EXISTS " . view;
		}
		return "DROP VIEW " . view;
	}

	/**
	 * Generates SQL checking for the existence of a schema.table
	 *
	 * <code>
	 * echo $dialect->tableExists("posts", "blog");
	 *
	 * echo $dialect->tableExists("posts");
	 * </code>
	 */
	public function tableExists(string! tableName, string schemaName = null) -> string
	{
		return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='" . tableName . "'";
	}

	/**
	 * Generates SQL checking for the existence of a schema.view
	 */
	public function viewExists(string! viewName, string schemaName = null) -> string
	{
		return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='" . viewName . "'";
	}

	/**
	 * Generates SQL describing a table
	 *
	 * <code>
	 * print_r(
	 *     $dialect->describeColumns("posts")
	 * );
	 * </code>
	 */
	public function describeColumns(string! table, string schema = null) -> string
	{
		return "PRAGMA table_info('" . table . "')";
	}

	/**
	 * List all tables in database
	 *
	 * <code>
	 * print_r(
	 *     $dialect->listTables("blog")
	 * );
	 * </code>
	 */
	public function listTables(string schemaName = null) -> string
	{
		return "SELECT tbl_name FROM sqlite_master WHERE type = 'table' ORDER BY tbl_name";
	}

	/**
	 * Generates the SQL to list all views of a schema or user
	 */
	public function listViews(string! schemaName = null) -> string
	{
		return "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name";
	}

	/**
	 * Generates the SQL to get query list of indexes
	 *
	 * <code>
	 * print_r(
	 *     $dialect->listIndexesSql("blog")
	 * );
	 * </code>
	 */
	public function listIndexesSql(string! table, string schema = null, string keyName = null) -> string
	{
		string sql;

		let sql = "SELECT sql FROM sqlite_master WHERE type = 'index' AND tbl_name = ". this->escape(table) ." COLLATE NOCASE";

		if keyName {
			let sql .= " AND name = ". this->escape(keyName) ." COLLATE NOCASE";
		}

		return sql;
	}

	/**
	 * Generates SQL to query indexes on a table
	 */
	public function describeIndexes(string! table, string schema = null) -> string
	{
		return "PRAGMA index_list('" . table . "')";
	}

	/**
	 * Generates SQL to query indexes detail on a table
	 */
	public function describeIndex(string! index) -> string
	{
		return "PRAGMA index_info('" . index . "')";
	}

	/**
	 * Generates SQL to query foreign keys on a table
	 */
	public function describeReferences(string! table, string schema = null) -> string
	{
		return "PRAGMA foreign_key_list('" . table . "')";
	}

	/**
	 * Generates the SQL to describe the table creation options
	 */
	public function tableOptions(string! table, string schema = null) -> string
	{
		return "";
	}

	/**
	 * Returns a SQL modified a shared lock statement. For now this method
	 * returns the original query
	 */
	public function sharedLock(string! sqlQuery) -> string
	{
		return sqlQuery;
	}
}
