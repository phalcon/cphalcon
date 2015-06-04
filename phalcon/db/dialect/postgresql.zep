
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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db\Dialect;

use Phalcon\Db\Dialect;
use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\ReferenceInterface;
use Phalcon\Db\DialectInterface;

/**
 * Phalcon\Db\Dialect\Postgresql
 *
 * Generates database specific SQL for the PostgreSQL RDBMS
 */
class Postgresql extends Dialect
{

	protected _escapeChar = "\"";

	/**
	 * Gets the column name in PostgreSQL
	 */
	public function getColumnDefinition(<ColumnInterface> column) -> string
	{
		var size, columnType, columnSql, typeValues;

		let size = column->getSize();
		let columnType = column->getType();
		let columnSql = "";
		if typeof columnType == "string" {
			let columnSql .= columnType;
			let columnType = column->getTypeReference();
		}

		switch columnType {

			case Column::TYPE_INTEGER:
				if empty columnSql {
					if column->isAutoIncrement() {
						let columnSql .= "SERIAL";
					} else {
						let columnSql .= "INT";
					}
				}
				break;

			case Column::TYPE_DATE:
				if empty columnSql {
					let columnSql .= "DATE";
				}
				break;

			case Column::TYPE_VARCHAR:
				if empty columnSql {
					let columnSql .= "CHARACTER VARYING";
				}
				let columnSql .= "(" . size . ")";
				break;

			case Column::TYPE_DECIMAL:
				if empty columnSql {
					let columnSql .= "NUMERIC";
				}
				let columnSql .= "(" . size . "," . column->getScale() . ")";
				break;

			case Column::TYPE_DATETIME:
				if empty columnSql {
					let columnSql .= "TIMESTAMP";
				}
				break;

			case Column::TYPE_CHAR:
				if empty columnSql {
					let columnSql .= "CHARACTER";
				}
				let columnSql .= "(" . size . ")";
				break;

			case Column::TYPE_TEXT:
				if empty columnSql {
					let columnSql .= "TEXT";
				}
				break;

			case Column::TYPE_FLOAT:
				if empty columnSql {
					let columnSql .= "FLOAT";
				}
				break;

			case Column::TYPE_BOOLEAN:
				if empty columnSql {
					let columnSql .= "SMALLINT(1)";
				}
				break;

			default:
				if empty columnSql {
					throw new Exception("Unrecognized PostgreSQL data type");
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

		if schemaName {
			let sql = "ALTER TABLE \"" . schemaName . "\".\"" . tableName . "\" ADD COLUMN ";
		} else {
			let sql = "ALTER TABLE \"" . tableName . "\" ADD COLUMN ";
		}

		let sql .= "\"" . column->getName() . "\" " . this->getColumnDefinition(column);

		let defaultValue = column->getDefault();
		if !empty defaultValue {
			let sql .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
		}

		if column->isNotNull() {
			let sql .= " NOT NULL";
		}

		return sql;
	}

	/**
	 * Generates SQL to modify a column in a table
	 */
	public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> string
	{
		var sql = "", sqlAlterTable, defaultValue;

		if schemaName {
			let sqlAlterTable = "ALTER TABLE \"" . schemaName . "\".\"" . tableName . "\"";
		} else {
			let sqlAlterTable = "ALTER TABLE \"" . tableName . "\"";
		}

		//Rename
		if column->getName() != currentColumn->getName() {
			let sql .= sqlAlterTable . " RENAME COLUMN \"" . currentColumn->getName() . "\" TO \"" . column->getName() . "\";";
		}
		//Change type
		if column->getType() != currentColumn->getType() {
			let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" TYPE " . this->getColumnDefinition(column) . ";";
		}
		//NULL
		if column->isNotNull() != currentColumn->isNotNull() {
			if column->isNotNull() {
				let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" SET NOT NULL;";
			} else {
				let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" DROP NOT NULL;";
			}
		}
		//DEFAULT
		if column->getDefault() != currentColumn->getDefault() {
			if empty column->getDefault() && !empty currentColumn->getDefault() {
				let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" DROP DEFAULT;";
			}
			let defaultValue = column->getDefault();
			if !empty defaultValue {
				let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" SET DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
			}
		}

		return sql;
	}

	/**
	 * Generates SQL to delete a column from a table
	 */
	public function dropColumn(string! tableName, string! schemaName, string! columnName) -> string
	{
		var sql;

		if schemaName {
			let sql = "ALTER TABLE \"" . schemaName . "\".\"" . tableName."\" ";
		} else {
			let sql = "ALTER TABLE \"" . tableName . "\" ";
		}

		let sql .= " DROP COLUMN \"".columnName."\"";

		return sql;
	}

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> string
	{
		var sql, indexType;

		if index->getName() === "PRIMARY" {
			return this->addPrimaryKey(tableName, schemaName, index);
		}

		let sql = "CREATE";

		let indexType = index->getType();
		if !empty indexType {
			let sql .= " " . indexType;
		}
		let sql .= " INDEX \"" . index->getName() . "\" ON";

		if schemaName {
			let sql .= " \"" . schemaName . "\".\"" . tableName."\"";
		} else {
			let sql .= " \"" . tableName . "\"";
		}

		let sql .= " (" . this->getColumnList(index->getColumns()) . ")";
		return sql;
	}

	/**
	 * Generates SQL to delete an index from a table
	 */
	public function dropIndex(string! tableName, string! schemaName, string! indexName) -> string
	{
		return "DROP INDEX \"" . indexName . "\"";
	}

	/**
	 * Generates SQL to add the primary key to a table
	 */
	public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> string
	{
		var sql;

		if schemaName {
			let sql = "ALTER TABLE \"" . schemaName . "\".\"" . tableName . "\"";
		} else {
			let sql = "ALTER TABLE \"" . tableName . "\"";
		}
		let sql .= " ADD CONSTRAINT \"PRIMARY\" PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";

		return sql;
	}

	/**
	 * Generates SQL to delete primary key from a table
	 */
	public function dropPrimaryKey(string! tableName, string! schemaName) -> string
	{
		var sql;

		if schemaName {
			let sql = "ALTER TABLE \"" . schemaName . "\".\"" . tableName . "\"";
		} else {
			let sql = "ALTER TABLE \"" . tableName . "\"";
		}
		let sql .= " DROP CONSTRAINT \"PRIMARY\"";

		return sql;
	}

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> string
	{
		var sql, onDelete, onUpdate;

		if schemaName {
			let sql = "ALTER TABLE \"" . schemaName . "\".\"" . tableName . "\" ";
		} else {
			let sql = "ALTER TABLE \"" . tableName . "\" ";
		}
		let sql .= "ADD CONSTRAINT \"" . reference->getName() . "\" FOREIGN KEY (" . this->getColumnList(reference->getColumns()) . ")"
				. " REFERENCES \"" . reference->getReferencedTable() . "\" (" . this->getColumnList(reference->getReferencedColumns()) . ")";

		let onDelete = reference->getOnDelete();
		if !empty onDelete {
			let sql .= " ON DELETE " . onDelete;
		}

		let onUpdate = reference->getOnUpdate();
		if !empty onUpdate {
			let sql .= " ON UPDATE " . onUpdate;
		}

		return sql;
	}

	/**
	 * Generates SQL to delete a foreign key from a table
	 */
	public function dropForeignKey(string! tableName, string! schemaName, string! referenceName) -> string
	{
		var sql;

		if schemaName {
			let sql = "ALTER TABLE \"" . schemaName . "\".\"" . tableName . "\"";
		} else {
			let sql = "ALTER TABLE \"" . tableName . "\"";
		}

		let sql .= " DROP CONSTRAINT \"" . referenceName . "\"" ;

		return sql;
	}

	/**
	 * Generates SQL to create a table
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> string | array
	{
		var temporary, options, table, createLines, columns,
			column, indexes, index, reference, references, indexName,
			indexSql, indexSqlAfterCreate, sql, columnLine, indexType,
			referenceSql, onDelete, onUpdate, defaultValue, primaryColumns;

		if !fetch columns, definition["columns"] {
			throw new Exception("The index 'columns' is required in the definition array");
		}

		if schemaName {
			let table = "\"" . schemaName . "\".\"" . tableName . "\"";
		} else {
			let table = "\"" . tableName . "\"";
		}

		let temporary = false;
		if fetch options, definition["options"] {
			fetch temporary, options["temporary"];
		}

		/**
		 * Create a temporary o normal table
		 */
		if temporary {
			let sql = "CREATE TEMPORARY TABLE " . table . " (\n\t";
		} else {
			let sql = "CREATE TABLE " . table . " (\n\t";
		}

		let createLines = [];
		let primaryColumns = [];
		for column in columns {

			let columnLine = "\"" . column->getName() . "\" " . this->getColumnDefinition(column);

			/**
			 * Add a Default clause
			 */
			let defaultValue = column->getDefault();
			if !empty defaultValue {
				let columnLine .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
			}

			/**
			 * Add a NOT NULL clause
			 */
			if column->isNotNull() {
				let columnLine .= " NOT NULL";
			}

			/**
			 * Add an AUTO_INCREMENT clause
			 */
			if column->isAutoIncrement() {
				//let columnLine .= " AUTO_INCREMENT";
			}

			/**
			 * Mark the column as primary key
			 */
			if column->isPrimary() {
				let primaryColumns[] = column->getName() ;
			}

			let createLines[] = columnLine;
		}
		if !empty primaryColumns {
			let createLines[] = "PRIMARY KEY (" . implode(",",primaryColumns) . ")";
		}

		/**
		 * Create related indexes
		 */
		let indexSqlAfterCreate = "";
		if fetch indexes, definition["indexes"] {

			for index in indexes {

				let indexName = index->getName();
				let indexType = index->getType();
				let indexSql = "";

				/**
				 * If the index name is primary we add a primary key
				 */
				if indexName == "PRIMARY" {
					let indexSql = "CONSTRAINT \"PRIMARY\" PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";
				} else {
					if !empty indexType {
						let indexSql = "CONSTRAINT \"" . indexName . "\" " . indexType . " (" . this->getColumnList(index->getColumns()) . ")";
					} else {

						let indexSqlAfterCreate .= "CREATE INDEX \"" . index->getName() . "\" ON ";

						if schemaName {
							let indexSqlAfterCreate .= "\"" . schemaName . "\".\"" . tableName . "\"";
						} else {
							let indexSqlAfterCreate .= "\"" . tableName . "\"";
						}

						let indexSqlAfterCreate .= " (" . this->getColumnList(index->getColumns()) . ");";
					}
				}
				if !empty indexSql {
					let createLines[] = indexSql;
				}
			}
		}
		/**
		 * Create related references
		 */
		if fetch references, definition["references"] {
			for reference in references {

				let referenceSql = "CONSTRAINT \"" . reference->getName() . "\" FOREIGN KEY (" . this->getColumnList(reference->getColumns()) . ") REFERENCES ";

				if schemaName {
					let referenceSql .= "\"" . schemaName . "\".\"" . reference->getReferencedTable() . "\" ";
				} else {
					let referenceSql .= "\"" . reference->getReferencedTable() . "\" ";
				}

				let referenceSql .= "(" . this->getColumnList(reference->getReferencedColumns()) . ")";

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
		if isset definition["options"] {
			let sql .= " " . this->_getTableOptions(definition);
		}
		let sql .= ";" . indexSqlAfterCreate;

		return sql;
	}

	/**
	 * Generates SQL to drop a view
	 */
	public function dropTable(string! tableName, string schemaName = null, boolean! ifExists = true) -> string
	{
		var table, sql;

		if schemaName {
			let table = "\"" . schemaName . "\".\"" . tableName . "\"";
		} else {
			let table = "\"" . tableName . "\"";
		}

		if ifExists {
			let sql = "DROP TABLE IF EXISTS \"" . table . "\"";
		} else {
			let sql = "DROP TABLE \"" . table . "\"";
		}

		return sql;
	}

	/**
	 * Generates SQL to create a view
	 */
	public function createView(string! viewName, array! definition, string schemaName = null) -> string
	{
		var viewSql, view;

		if !fetch viewSql, definition["sql"] {
			throw new Exception("The index 'sql' is required in the definition array");
		}

		if schemaName {
			let view = "\"" . schemaName . "\".\"" . viewName . "\"";
		} else {
			let view = "\"" . viewName . "\"";
		}

		return "CREATE VIEW " . view . " AS " . viewSql;
	}

	/**
	 * Generates SQL to drop a view
	 */
	public function dropView(string! viewName, string schemaName = null, boolean! ifExists = true) -> string
	{
		var view, sql;

		if schemaName {
			let view = "\"" . schemaName . "\".\"" . viewName . "\"";
		} else {
			let view = "\"" . viewName . "\"";
		}

		if ifExists {
			let sql = "DROP VIEW IF EXISTS " . view . "";
		} else {
			let sql = "DROP VIEW " . view . "";
		}

		return sql;
	}

	/**
	 * Generates SQL checking for the existence of a schema.table
	 *
	 * <code>
	 *    echo $dialect->tableExists("posts", "blog");
	 *    echo $dialect->tableExists("posts");
	 * </code>
	 */
	public function tableExists(string! tableName, string schemaName = null) -> string
	{
		if schemaName {
			return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '" . schemaName . "' AND table_name='" . tableName . "'";
		}
		return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = 'public' AND table_name='" . tableName . "'";
	}

	/**
	 * Generates SQL checking for the existence of a schema.view
	 */
	public function viewExists(string! viewName, string schemaName = null) -> string
	{
		if schemaName {
			return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='" . viewName . "' AND schemaname='" . schemaName . "'";
		}
		return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='" . viewName . "'";
	}

	/**
	 * Generates SQL describing a table
	 *
	 * <code>
	 *    print_r($dialect->describeColumns("posts"));
	 * </code>
	 */
	public function describeColumns(string! table, string schema = null) -> string
	{
		if schema {
			return "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='" . schema . "' AND c.table_name='" . table . "' ORDER BY c.ordinal_position";
		}
		return "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='" . table . "' ORDER BY c.ordinal_position";
	}

	/**
	 * List all tables in database
	 *
	 * <code>
	 *     print_r($dialect->listTables("blog"))
	 * </code>
	 */
	public function listTables(string schemaName = null) -> string
	{
		if schemaName {
			return "SELECT table_name FROM information_schema.tables WHERE table_schema = '" . schemaName . "' ORDER BY table_name";
		}
		return "SELECT table_name FROM information_schema.tables WHERE table_schema = 'public' ORDER BY table_name";
	}

	/**
	 * Generates the SQL to list all views of a schema or user
	 *
	 * @param string schemaName
	 * @return string
	 */
	public function listViews(schemaName = null) -> string
	{
		if schemaName {
			return "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '" . schemaName . "' ORDER BY view_name";
		}
		return "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name";
	}

	/**
	 * Generates SQL to query indexes on a table
	 */
	public function describeIndexes(string! table, string schema = null) -> string
	{
		return "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '" . table . "' ORDER BY t.relname, i.relname;";
	}

	/**
	 * Generates SQL to query foreign keys on a table
	 */
	public function describeReferences(string! table, string schema = null) -> string
	{
		var sql = "SELECT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = 'FOREIGN KEY' AND ";

		if schema {
			let sql .= "tc.table_schema = '" . schema . "' AND tc.table_name='" . table . "'";
		} else {
			let sql .= "tc.table_name='" . table . "'";
		}

		return sql;
	}

	/**
	 * Generates the SQL to describe the table creation options
	 */
	public function tableOptions(string! table, string schema = null) -> string
	{
		return "";
	}
	protected function _getTableOptions(array! definition) -> string
	{
		return "";
	}
}
