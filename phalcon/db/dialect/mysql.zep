
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

namespace Phalcon\Db\Dialect;

/**
 * Phalcon\Db\Dialect\Mysql
 *
 * Generates database specific SQL for the MySQL RBDM
 */
class MySQL extends Phalcon\Db\Dialect //implements Phalcon\Db\DialectInterface
{

	protected _escapeChar = "`";

	/**
	 * Gets the column name in MySQL
	 *
	 * @param Phalcon\Db\ColumnInterface column
	 * @return string
	 */
	public function getColumnDefinition(<Phalcon\Db\ColumnInterface> column) -> string
	{
		var columnSql, size, scale;

		if typeof column != "object" {
			throw new Phalcon\Db\Exception("Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		}

		switch column->getType() {

			case Phalcon\Db\Column::TYPE_INTEGER:
				let columnSql = "INT(" . column->getSize() . ")";
				if column->isUnsigned() {
					let columnSql .= " UNSIGNED";
				}
				break;

			case Phalcon\Db\Column::TYPE_DATE:
				let columnSql = "DATE";
				break;

			case Phalcon\Db\Column::TYPE_VARCHAR:
				let columnSql = "VARCHAR(" . column->getSize() . ")";
				break;

			case Phalcon\Db\Column::TYPE_DECIMAL:
				let columnSql = "DECIMAL(" . column->getSize() . "," . column->getScale() . ")";
				if column->isUnsigned() {
					let columnSql .= " UNSIGNED";
				}
				break;

			case Phalcon\Db\Column::TYPE_DATETIME:
				let columnSql = "DATETIME";
				break;

			case Phalcon\Db\Column::TYPE_CHAR:
				let columnSql = "CHAR(" . column->getSize() . ")";
				break;

			case Phalcon\Db\Column::TYPE_TEXT:
				let columnSql = "TEXT";
				break;

			case Phalcon\Db\Column::TYPE_FLOAT:
				let columnSql = "FLOAT",
					size = column->getSize();
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

			default:
				throw new Phalcon\Db\Exception("Unrecognized MySQL data type");
		}

		return columnSql;
	}

	/**
	 * Generates SQL to add a column to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 */
	public function addColumn(string! tableName, string! schemaName, <Phalcon\Db\ColumnInterface> column) -> string
	{
		var afterPosition, sql;

		if typeof column != "object" {
			throw new Phalcon\Db\Exception("Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		}

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` ADD ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` ADD ";
		}

		let sql .= "`" . column->getName() . "` " . this->getColumnDefinition(column);

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
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	string
	 */
	public function modifyColumn(string! tableName, string! schemaName, <Phalcon\Db\ColumnInterface> column) -> string
	{
		var sql;

		if typeof column != "object" {
			throw new Phalcon\Db\Exception("Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		}

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` MODIFY ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` MODIFY ";
		}

		let sql .= "`" . column->getName() . "` " . this->getColumnDefinition(column);
		if column->isNotNull() {
			let sql .= " NOT NULL";
		}
		return sql;
	}

	/**
	 * Generates SQL to delete a column from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string columnName
	 * @return 	string
	 */
	public function dropColumn(string! tableName, string! schemaName, string columnName) -> string
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
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\IndexInterface index
	 * @return	string
	 */
	public function addIndex(string! tableName, string! schemaName, <Phalcon\Db\IndexInterface> index) -> string
	{
		var sql;

		if typeof index != "object" {
			throw new Phalcon\Db\Exception("Index parameter must be an object compatible with Phalcon\\Db\\IndexInterface");
		}

		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` ADD INDEX ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` ADD INDEX ";
		}

		let sql .= "`" . index->getName() . "` (" . this->getColumnList(index->getColumns()) . ")";
		return sql;
	}

	/**
	 * Generates SQL to delete an index from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string indexName
	 * @return	string
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
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\IndexInterface index
	 * @return	string
	 */
	public function addPrimaryKey(string tableName, string schemaName, <Phalcon\Db\IndexInterface> index) -> string
	{
		var sql;

		if typeof index != "object" {
			throw new Phalcon\Db\Exception("Index parameter must be an object compatible with Phalcon\\Db\\IndexInterface");
		}

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
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @return	string
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
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ReferenceInterface reference
	 * @return	string
	 */
	public function addForeignKey(string! tableName, string! schemaName, <Phalcon\Db\ReferenceInterface> reference) -> string
	{
		var sql, referencedSchema;

		if typeof reference != "object" {
			throw new Phalcon\Db\Exception("Index parameter must be an object compatible with Phalcon\\Db\\ReferenceInterface");
		}

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
		return sql;
	}

	/**
	 * Generates SQL to delete a foreign key from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string referenceName
	 * @return	string
	 */
	public function dropForeignKey(string! tableName, string! schemaName, referenceName) -> string
	{
		var sql;
		if schemaName {
			let sql = "ALTER TABLE `" . schemaName . "`.`" . tableName . "` DROP FOREIGN KEY ";
		} else {
			let sql = "ALTER TABLE `" . tableName . "` DROP FOREIGN KEY ";
		}
		let sql .= "`" . referenceName . "`";
		return sql;
	}

	/**
	 * Generates SQL to add the table creation options
	 *
	 * @param	array definition
	 * @return	array
	 */
	protected function _getTableOptions(definition) -> string
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

	/**
	 * Generates SQL to create a table in MySQL
	 *
	 * @param 	string tableName
	 * @param	string schemaName
	 * @param	array definition
	 * @return 	string
	 */
	public function createTable(string! tableName, string! schemaName, definition) -> string
	{
		var temporary, options, table, createLines, columns,
			column, indexes, index, reference, references, indexName,
			indexSql, sql, columnLine;

		if !fetch columns, definition["columns"] {
			throw new Phalcon\Db\Exception("The index 'columns' is required in the definition array");
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

				/**
				 * If the index name is primary we add a primary key
				 */
				if indexName == "PRIMARY" {
					let indexSql = "PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";
				} else {
					let indexSql = "KEY `" . indexName . "` (" . this->getColumnList(index->getColumns()) . ")";
				}

				let createLines[] = indexSql;
			}
		}

		/**
		 * Create related references
		 */
		if fetch references, definition["references"] {
			for reference in references {
				let createLines[] = "CONSTRAINT `" . reference->getName() . "` FOREIGN KEY (" . this->getColumnList(columns) . ")" .
							   " REFERENCES `" . reference->getReferencedTable() . "`(" . this->getColumnList(reference->getReferencedColumns()) . ")";
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
	 *
	 * @param  string tableName
	 * @param  string schemaName
	 * @param  boolean ifExists
	 * @return string
	 */
	public function dropTable(string! tableName, string! schemaName, ifExists=true) -> string
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
	 *
	 * @param string viewName
	 * @param array definition
	 * @param string schemaName
	 * @return string
	 */
	public function createView(string! viewName, definition, string! schemaName) -> string
	{
		var view, viewSql;

		if fetch viewSql, definition["sql"] {
			throw new Phalcon\Db\Exception("The index 'sql' is required in the definition array");
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
	 *
	 * @param string viewName
	 * @param string schemaName
	 * @param boolean ifExists
	 * @return string
	 */
	public function dropView(string! viewName, string! schemaName, boolean ifExists=true) -> string
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
	 * echo $dialect->tableExists("posts", "blog");
	 * echo $dialect->tableExists("posts");
	 * </code>
	 *
	 * @param string tableName
	 * @param string schemaName
	 * @return string
	 */
	public function tableExists(string! tableName, schemaName=null) -> string
	{
		if schemaName {
			return "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '" . tableName . "' AND `TABLE_SCHEMA` = '" . schemaName . "'";
		}
		return "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '" . tableName . "'";
	}

	/**
	 * Generates SQL checking for the existence of a schema.view
	 *
	 * @param string viewName
	 * @param string schemaName
	 * @return string
	 */
	public function viewExists(string! viewName, schemaName=null)
	{
		if schemaName {
			return "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '" . viewName . "' AND `TABLE_SCHEMA`='" . schemaName . "'";
		}
		return "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='" . viewName . "'";
	}

	/**
	 * Generates SQL describing a table
	 *
	 *<code>
	 *	print_r($dialect->describeColumns("posts"));
	 *</code>
	 *
	 * @param string table
	 * @param string schema
	 * @return string
	 */
	public function describeColumns(string! table, schema=null) -> string
	{
		if schema {
			return "DESCRIBE `" . schema . "`.`" . table . "`";
		}
		return "DESCRIBE `" . table . "`";
	}

	/**
	 * List all tables on database
	 *
	 *<code>
	 *	print_r($dialect->listTables("blog"))
	 *</code>
	 *
	 * @param       string schemaName
	 * @return      array
	 */
	public function listTables(string! schemaName=null) -> string
	{
		if schemaName {
			return "SHOW TABLES FROM `" . schemaName . "`";
		}
		return "SHOW TABLES";
	}

	/**
	 * Generates the SQL to list all views of a schema or user
	 *
	 * @param string schemaName
	 * @return array
	 */
	public function listViews(string! schemaName=null) -> string
	{
		if schemaName {
			return "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '" . schemaName . "' ORDER BY view_name";
		}
		return "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` ORDER BY view_name";
	}

	/**
	 * Generates SQL to query indexes on a table
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	string
	 */
	public function describeIndexes(string! table, schema=null) -> string
	{
		if schema {
			return "SHOW INDEXES FROM `" . schema . "`.`" . table . "`";
		}
		return "SHOW INDEXES FROM `" . table . "`";
	}

	/**
	 * Generates SQL to query foreign keys on a table
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	string
	 */
	public function describeReferences(string! table, schema=null) -> string
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
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	string
	 */
	public function tableOptions(string! table, schema=null) -> string
	{
		var sql = "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ";
		if schema {
			let sql .= "TABLES.TABLE_SCHEMA = '" . schema . "' AND TABLES.TABLE_NAME = '" . table . "'";
		} else {
			let sql .= "TABLES.TABLE_NAME = '" . table . "'";
		}
		return sql;
	}

}
