
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
 |          Marcio Paiva <mpaivabarbosa@gmail.com>                        |
 |          Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db\Dialect;

use Phalcon\Db\Dialect;
use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\ReferenceInterface;
use Phalcon\Text;

/**
 * Phalcon\Db\Dialect\Oracle
 *
 * Generates database specific SQL for the Oracle RDBMS
 */
class Oracle extends Dialect
{
	protected _escapeChar = "";

	/**
	 * Generates the SQL for LIMIT clause
	 */
	public function limit(string! sqlQuery, var number) -> string
	{
		var limit, offset = 0;

		if typeof number == "array" {

			if isset number[1] {
				let offset = (int) trim(number[1], "'");
			}

			let limit = (int)trim(number[0], "'") + offset;
		} else {
			let limit = (int)trim(number, "'");
		}


		let sqlQuery = "SELECT * FROM (SELECT Z1.*, ROWNUM PHALCON_RN FROM (" . sqlQuery . ") Z1 WHERE ROWNUM <= " . limit . ")";

		if (offset != 0) {
			let sqlQuery .= " WHERE PHALCON_RN >= " . offset;
		}

		return sqlQuery;
	}

	/**
	 * Gets the column name in Oracle
	 */
	public function getColumnDefinition(<ColumnInterface> column) -> string
	{
		var columnSql, size, scale, type;

		let type = column->getType();
		let size = column->getSize();

		switch type {

			case Column::TYPE_INTEGER:
				let columnSql = "INTEGER";
			break;

			case Column::TYPE_DATE:
				let columnSql = "DATE";
			break;

			case Column::TYPE_VARCHAR:
				let columnSql = "VARCHAR2(" . size . ")";
			break;

			case Column::TYPE_DECIMAL:
				let scale = column->getScale();
				let columnSql = "NUMBER(" . size . "," . scale . ")";
			break;

			case Column::TYPE_DATETIME:
				let columnSql = "TIMESTAMP";
			break;

			case Column::TYPE_CHAR:
				let columnSql = "CHAR(" . size . ")";
			break;

			case Column::TYPE_TEXT:
				let columnSql = "TEXT";
			break;

			case Column::TYPE_FLOAT:
				let scale = column->getScale();
				let columnSql = "FLOAT(" . size . "," . scale .")";
			break;

			case Column::TYPE_BOOLEAN:
				let columnSql = "TINYINT(1)";
			break;

			default:
				throw new Exception("Unrecognized Oracle data type");
		}

		return columnSql;
	}

	/**
	 * Generates SQL to add a column to a table
	 */
	public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to modify a column in a table
	 */
	public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to delete a column from a table
	 */
	public function dropColumn(string! tableName, string! schemaName, string columnName) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	/**
	 * Generates SQL to delete an index from a table
	 */
	public function dropIndex(string! tableName, string! schemaName, string! indexName) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to add the primary key to a table
	 */
	public function addPrimaryKey(string tableName, string schemaName, <IndexInterface> index) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to delete primary key from a table
	 */
	public function dropPrimaryKey(string! tableName, string! schemaName) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to add an index to a table
	 */
	public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to delete a foreign key from a table
	 */
	public function dropForeignKey(string! tableName, string! schemaName, string! referenceName) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to create a table in Oracle
	 */
	public function createTable(string! tableName, string! schemaName, array! definition) -> string
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to drop a table
	 */
	public function dropTable(string! tableName, string! schemaName, boolean! ifExists = true) -> string
	{
		var table;

		if schemaName {
			let table = this->escape(Text::upper(schemaName)) . "." . this->escape(Text::upper(tableName));
		} else {
			let table = this->escape(Text::upper(tableName));
		}

		if ifExists {
			return "DROP TABLE IF EXISTS " . table;
		} else {
			return "DROP TABLE " . table;
		}
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
			let view = this->escape(Text::upper(schemaName) . "." . Text::upper(viewName));
		} else {
			let view = this->escape(Text::upper(viewName));
		}

		return "CREATE VIEW " . view . " AS " . viewSql;
	}

	/**
	 * Generates SQL to drop a view
	 */
	public function dropView(string! viewName, string schemaName = null, boolean! ifExists = true) -> string
	{
		var view;

		if schemaName {
			let view = this->escape(Text::upper(schemaName) . "." . Text::upper(viewName));
		} else {
			let view = this->escape(Text::upper(viewName));
		}

		if ifExists {
			return "DROP VIEW IF EXISTS " . view;
		} else {
			return "DROP VIEW " . view;
		}
	}

	/**
	 * Generates SQL checking for the existence of a schema.view
	 */
	public function viewExists(string! viewName, string schemaName = null) -> string
	{
		if schemaName != "" {
			return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_VIEWS WHERE VIEW_NAME='" . Text::upper(viewName) . "' AND OWNER='" . Text::upper(schemaName) . "'";
		} else {
			return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_VIEWS WHERE VIEW_NAME='" . Text::upper(viewName) . "'";
		}
	}

	/**
	 * Generates the SQL to list all views of a schema or user
	 */
	public function listViews(string schemaName = null) -> string
	{
		if schemaName != "" {
			return "SELECT VIEW_NAME FROM ALL_VIEWS WHERE OWNER='" . Text::upper(schemaName) . "' ORDER BY VIEW_NAME";
		} else {
			return "SELECT VIEW_NAME FROM ALL_VIEWS VIEW_NAME";
		}
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
		if schemaName != "" {
			return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_TABLES WHERE TABLE_NAME='" . Text::upper(tableName) . "' AND OWNER = '" . Text::upper(schemaName) . "'";
		} else {
			return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_TABLES WHERE TABLE_NAME='" . Text::upper(tableName) .  "'";
		}
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
		if schema != "" {
			return "SELECT TC.COLUMN_NAME, TC.DATA_TYPE, TC.DATA_LENGTH, TC.DATA_PRECISION, TC.DATA_SCALE, TC.NULLABLE, C.CONSTRAINT_TYPE, TC.DATA_DEFAULT, CC.POSITION FROM ALL_TAB_COLUMNS TC LEFT JOIN (ALL_CONS_COLUMNS CC JOIN ALL_CONSTRAINTS C ON (CC.CONSTRAINT_NAME = C.CONSTRAINT_NAME AND CC.TABLE_NAME = C.TABLE_NAME AND CC.OWNER = C.OWNER AND C.CONSTRAINT_TYPE = 'P')) ON TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME WHERE TC.TABLE_NAME = '" . Text::upper(table) . "' AND TC.OWNER = '" . Text::upper(schema) . "' ORDER BY TC.COLUMN_ID";
		} else {
			return "SELECT TC.COLUMN_NAME, TC.DATA_TYPE, TC.DATA_LENGTH, TC.DATA_PRECISION, TC.DATA_SCALE, TC.NULLABLE, C.CONSTRAINT_TYPE, TC.DATA_DEFAULT, CC.POSITION FROM ALL_TAB_COLUMNS TC LEFT JOIN (ALL_CONS_COLUMNS CC JOIN ALL_CONSTRAINTS C ON (CC.CONSTRAINT_NAME = C.CONSTRAINT_NAME AND CC.TABLE_NAME = C.TABLE_NAME AND CC.OWNER = C.OWNER AND C.CONSTRAINT_TYPE = 'P')) ON TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME WHERE TC.TABLE_NAME = '" . Text::upper(table) . "' ORDER BY TC.COLUMN_ID";
		}
	}

	/**
	 * List all tables in database
	 *
	 * <code>
	 *    print_r($dialect->listTables("blog"))
	 * </code>
	 */
	public function listTables(string schemaName = null) -> string
	{
		if schemaName != "" {
			return "SELECT TABLE_NAME, OWNER FROM ALL_TABLES WHERE OWNER='" . Text::upper(schemaName) . "' ORDER BY OWNER, TABLE_NAME";
		} else {
			return "SELECT TABLE_NAME, OWNER FROM ALL_TABLES ORDER BY OWNER, TABLE_NAME";
		}
	}

	/**
	 * Generates SQL to query indexes on a table
	 */
	public function describeIndexes(string! table, string schema = null) -> string
	{
		if schema != "" {
			return "SELECT I.TABLE_NAME, 0 AS C0, I.INDEX_NAME, IC.COLUMN_POSITION, IC.COLUMN_NAME FROM ALL_INDEXES I JOIN ALL_IND_COLUMNS IC ON I.INDEX_NAME = IC.INDEX_NAME WHERE  I.TABLE_NAME = '" . Text::upper(table) . "' AND IC.INDEX_OWNER = '" . Text::upper(schema) . "'";
		} else {
			return "SELECT I.TABLE_NAME, 0 AS C0, I.INDEX_NAME, IC.COLUMN_POSITION, IC.COLUMN_NAME FROM ALL_INDEXES I JOIN ALL_IND_COLUMNS IC ON I.INDEX_NAME = IC.INDEX_NAME WHERE  I.TABLE_NAME = '" . Text::upper(table) ."'";
		}
	}

	/**
	 * Generates SQL to query foreign keys on a table
	 */
	public function describeReferences(string! table, string schema = null) -> string
	{
		var sql;
		let sql = "SELECT AC.TABLE_NAME, CC.COLUMN_NAME, AC.CONSTRAINT_NAME, AC.R_OWNER, RCC.TABLE_NAME R_TABLE_NAME, RCC.COLUMN_NAME R_COLUMN_NAME FROM ALL_CONSTRAINTS AC JOIN ALL_CONS_COLUMNS CC ON AC.CONSTRAINT_NAME = CC.CONSTRAINT_NAME JOIN ALL_CONS_COLUMNS RCC ON AC.R_OWNER = RCC.OWNER AND AC.R_CONSTRAINT_NAME = RCC.CONSTRAINT_NAME WHERE AC.CONSTRAINT_TYPE='R' ";

		if schema != "" {
			let sql .= "AND AC.OWNER='" . Text::upper(schema) . "' AND AC.TABLE_NAME = '" . Text::upper(table) . "'";
		} else {
			let sql .= "AND AC.TABLE_NAME = '" . Text::upper(table) . "'";
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

	/**
	 * Checks whether the platform supports savepoints
	 */
	public function supportsSavepoints() -> boolean
	{
		return false;
	}

	/**
	 * Checks whether the platform supports releasing savepoints.
	 */
	public function supportsReleaseSavepoints() -> boolean
	{
		return false;
	}
}
