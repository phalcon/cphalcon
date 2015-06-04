
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

namespace Phalcon\Db\Dialect;

use Phalcon\Db\Dialect;
use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\ReferenceInterface;
use Phalcon\Db\DialectInterface;

/**
 * Phalcon\Db\Dialect\Mysql
 *
 * Generates database specific SQL for the MySQL RDBMS
 */
class MySQL extends Dialect
{

	protected _escapeChar = "`";

	/**
	 * Gets the column name in MySQL
	 */
	public function getColumnDefinition(<ColumnInterface> column) -> string
	{
		var columnSql, size, scale, type, typeValues;

		let columnSql = "";

		let type = column->getType();
		if typeof type == "string" {
			let columnSql .= type;
			let type = column->getTypeReference();
		}

		switch type {

			case Column::TYPE_INTEGER:
				if empty columnSql {
					let columnSql .= "INT";
				}
				let columnSql .= "(" . column->getSize() . ")";
				if column->isUnsigned() {
					let columnSql .= " UNSIGNED";
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
					let columnSql .= "DECIMAL";
				}
				let columnSql .= "(" . column->getSize() . "," . column->getScale() . ")";
				if column->isUnsigned() {
					let columnSql .= " UNSIGNED";
				}
				break;

			case Column::TYPE_DATETIME:
				if empty columnSql {
					let columnSql .= "DATETIME";
				}
				break;

			case Column::TYPE_CHAR:
				if empty columnSql {
					let columnSql .= "CHAR";
				}
				let columnSql .= "(" . column->getSize() . ")";
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
				let size = column->getSize();
				if size {
					let scale = column->getScale(),
						columnSql .= "(" . size;
					if scale {
						let columnSql .= "," . scale . ")";
					} else {
						let columnSql .= ")";
					}
				}
				if column->isUnsigned() {
					let columnSql .= " UNSIGNED";
				}
				break;

			case Column::TYPE_BOOLEAN:
				if empty columnSql {
					let columnSql .= "TINYINT(1)";
				}
				break;

			default:
				if empty columnSql {
					throw new Exception("Unrecognized MySQL data type");
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
		var afterPosition, sql, defaultValue;

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` ADD ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` ADD ";
		}

		let sql .= "`" . column->getName() . "` " . this->getColumnDefinition(column);

		let defaultValue = column->getDefault();
		if ! empty defaultValue {
			let sql .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
		}

		if column->isNotNull() {
			let sql .= " NOT NULL";
		}

		if column->isFirst() {
			let sql .= " FIRST";
		} else {
			let afterPosition = column->getAfterPosition();
			if afterPosition {
				let sql .=  " AFTER " . afterPosition;
			}
		}
		return sql;
	}

	/**
	 * Generates SQL to modify a column in a table
	 */
	public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> string
	{
		var sql, defaultValue;

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` MODIFY ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` MODIFY ";
		}

		let sql .= "`" . column->getName() . "` " . this->getColumnDefinition(column);

		let defaultValue = column->getDefault();
		if ! empty defaultValue {
			let sql .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
		}

		if column->isNotNull() {
			let sql .= " NOT NULL";
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
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` DROP COLUMN ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` DROP COLUMN ";
		}

		let sql .= "`".columnName."`";
		return sql;
	}

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> string
	{
		var sql, indexType;

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName;
		} else {
			let sql = "ALTER TABLE `" . tableName;
		}

		let indexType = index->getType();
		if !empty indexType {
			let sql .= "` ADD " . indexType . " INDEX ";
		} else {
			let sql .= "` ADD INDEX ";
		}

		let sql .= "`" . index->getName() . "` (" . this->getColumnList(index->getColumns()) . ")";
		return sql;
	}

	/**
	 * Generates SQL to delete an index from a table
	 */
	public function dropIndex(string! tableName, string! schemaName, string! indexName) -> string
	{
		var sql;
		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` DROP INDEX ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` DROP INDEX ";
		}
		let sql .= "`" . indexName . "`";
		return sql;
	}

	/**
	 * Generates SQL to add the primary key to a table
	 */
	public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> string
	{
		var sql;

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` ADD PRIMARY KEY ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` ADD PRIMARY KEY ";
		}
		let sql .= "(" . this->getColumnList(index->getColumns()) . ")";
		return sql;
	}

	/**
	 * Generates SQL to delete primary key from a table
	 */
	public function dropPrimaryKey(string! tableName, string! schemaName) -> string
	{
		var sql;

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` DROP PRIMARY KEY";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` DROP PRIMARY KEY";
		}
		return sql;
	}

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> string
	{
		var sql, referencedSchema, onDelete, onUpdate;

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` ADD FOREIGN KEY ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` ADD FOREIGN KEY ";
		}

		let sql .= "`" . reference->getName() . "`(" . this->getColumnList(reference->getColumns()) . ") REFERENCES ";

		/**
		 * Add the schema
		 */
		let referencedSchema = reference->getReferencedSchema();
		if referencedSchema {
			let sql .= "`" . referencedSchema . "`.";
		}

		let sql .= "`" . reference->getReferencedTable() . "`(" . this->getColumnList(reference->getReferencedColumns()) . ")";

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
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` DROP FOREIGN KEY ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` DROP FOREIGN KEY ";
		}
		return sql . "`" . referenceName . "`";
	}

	/**
	 * Generates SQL to create a table
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> string
	{
		var temporary, options, table, createLines, columns,
			column, indexes, index, reference, references, indexName,
			indexSql, sql, columnLine, indexType,
			referenceSql, onDelete, onUpdate, defaultValue;

		if !fetch columns, definition["columns"] {
			throw new Exception("The index 'columns' is required in the definition array");
		}

		if schemaName {
			let table = "`" . schemaName . "`.`" . tableName . "`";
		} else {
			let table = "`" . tableName . "`";
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
		for column in columns {

			let columnLine = "`" . column->getName() . "` " . this->getColumnDefinition(column);

			/**
			 * Add a Default clause
			 */
			let defaultValue = column->getDefault();
			if ! empty defaultValue {
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
				let columnLine .= " AUTO_INCREMENT";
			}

			/**
			 * Mark the column as primary key
			 */
			if column->isPrimary() {
				let columnLine .= " PRIMARY KEY";
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
				if indexName == "PRIMARY" {
					let indexSql = "PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";
				} else {
					if !empty indexType {
						let indexSql = indexType . " KEY `" . indexName . "` (" . this->getColumnList(index->getColumns()) . ")";
					} else {
						let indexSql = "KEY `" . indexName . "` (" . this->getColumnList(index->getColumns()) . ")";
					}
				}

				let createLines[] = indexSql;
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
		if isset definition["options"] {
			let sql .= " " . this->_getTableOptions(definition);
		}

		return sql;
	}

	/**
	 * Generates SQL to drop a table
	 */
	public function dropTable(string! tableName, string schemaName = null, boolean! ifExists = true) -> string
	{
		var sql, table;

		if schemaName {
			let table = "`" . schemaName . "`.`" . tableName . "`";
		} else {
			let table = "`" . tableName . "`";
		}

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
		var view, viewSql;

		if !fetch viewSql, definition["sql"] {
			throw new Exception("The index 'sql' is required in the definition array");
		}

		if schemaName {
			let view = "`". schemaName . "`.`" . viewName . "`";
		} else {
			let view = "`". viewName . "`";
		}

		return "CREATE VIEW " . view . " AS " . viewSql;
	}

	/**
	 * Generates SQL to drop a view
	 */
	public function dropView(string! viewName, string schemaName = null, boolean! ifExists = true) -> string
	{
		var sql, view;

		if schemaName {
			let view = schemaName . "." . viewName;
		} else {
			let view = viewName;
		}

		if ifExists {
			let sql = "DROP VIEW IF EXISTS " . view;
		} else {
			let sql = "DROP VIEW " . view;
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
			return "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '" . tableName . "' AND `TABLE_SCHEMA` = '" . schemaName . "'";
		}
		return "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '" . tableName . "' AND `TABLE_SCHEMA` = DATABASE()";
	}

	/**
	 * Generates SQL checking for the existence of a schema.view
	 */
	public function viewExists(string! viewName, string schemaName = null) -> string
	{
		if schemaName {
			return "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '" . viewName . "' AND `TABLE_SCHEMA`='" . schemaName . "'";
		}
		return "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='" . viewName . "'";
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
			return "DESCRIBE `" . schema . "`.`" . table . "`";
		}
		return "DESCRIBE `" . table . "`";
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
			return "SHOW TABLES FROM `" . schemaName . "`";
		}
		return "SHOW TABLES";
	}

	/**
	 * Generates the SQL to list all views of a schema or user
	 */
	public function listViews(string! schemaName = null) -> string
	{
		if schemaName {
			return "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '" . schemaName . "' ORDER BY view_name";
		}
		return "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` ORDER BY view_name";
	}

	/**
	 * Generates SQL to query indexes on a table
	 */
	public function describeIndexes(string! table, string schema = null) -> string
	{
		if schema {
			return "SHOW INDEXES FROM `" . schema . "`.`" . table . "`";
		}
		return "SHOW INDEXES FROM `" . table . "`";
	}

	/**
	 * Generates SQL to query foreign keys on a table
	 */
	public function describeReferences(string! table, string schema = null) -> string
	{
		var sql = "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ";
		if schema {
			let sql .= "CONSTRAINT_SCHEMA = '" . schema . "' AND TABLE_NAME = '" . table . "'";
		} else {
			let sql .= "TABLE_NAME = '" . table . "'";
		}
		return sql;
	}

	/**
	 * Generates the SQL to describe the table creation options
	 */
	public function tableOptions(string! table, string schema = null) -> string
	{
		var sql = "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ";
		if schema {
			return sql . "TABLES.TABLE_SCHEMA = '" . schema . "' AND TABLES.TABLE_NAME = '" . table . "'";
		}
		return sql . "TABLES.TABLE_NAME = '" . table . "'";
	}

	/**
	 * Generates SQL to add the table creation options
	 */
	protected function _getTableOptions(array! definition) -> string
	{
		var options, engine, autoIncrement, tableCollation,
			collationParts, tableOptions;

		if fetch options, definition["options"] {

			let tableOptions = [];

			/**
			 * Check if there is an ENGINE option
			 */
			if fetch engine, options["ENGINE"] {
				if engine {
					let tableOptions[] = "ENGINE=" . engine;
				}
			}

			/**
			 * Check if there is an AUTO_INCREMENT option
			 */
			if fetch autoIncrement, options["AUTO_INCREMENT"] {
				if autoIncrement {
					let tableOptions[] = "AUTO_INCREMENT=" . autoIncrement;
				}
			}

			/**
			 * Check if there is a TABLE_COLLATION option
			 */
			if fetch tableCollation, options["TABLE_COLLATION"] {
				if tableCollation {
					let collationParts = explode("_", tableCollation),
						tableOptions[] = "DEFAULT CHARSET=" . collationParts[0],
						tableOptions[] = "COLLATE=" . tableCollation;
				}
			}

			if count(tableOptions) {
				return join(" ", tableOptions);
			}
		}

		return "";
	}
}
