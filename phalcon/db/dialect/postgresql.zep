
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

use Phalcon\Db\Exception;
use Phalcon\Db\Dialect;
use Phalcon\Db\DialectInterface;

/**
 * Phalcon\Db\Dialect\Postgresql
 *
 * Generates database specific SQL for the PostgreSQL RBDM
 */
class Postgresql extends Dialect implements DialectInterface
{

	protected _escapeChar = "\"";

	/**
	 * Gets the column name in PostgreSQL
	 *
	 * @param Phalcon\Db\ColumnInterface column
	 * @return string
	 */
	public function getColumnDefinition(column) -> string
	{
 		var size, columnType, columnSql;

		if typeof column != "object" {
			throw new Exception("Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		}

		let size = column->getSize();
		let columnType = column->getType();

		switch columnType {
			case 0:
				let columnSql = "INT";
				break;
			case 1:
				let columnSql = "DATE";
				break;
			case 2:
				let columnSql = "CHARACTER VARYING(" . size . ")";
				break;
			case 3:
				let columnSql = "NUMERIC(" . size . "," . column->getScale() . ")";
				break;
			case 4:
				let columnSql = "TIMESTAMP";
				break;
			case 5:
				let columnSql = "CHARACTER(" . size . ")";
				break;
			case 6:
				let columnSql = "TEXT";
				break;
			case 7:
				let columnSql = "FLOAT";
				break;
			case 8:
				let columnSql = "SMALLINT(1)";
				break;
			default:
				throw new Exception("Unrecognized PostgreSQL data type");
		}

		return columnSql;
	}

	/**
	 * Generates SQL to add a column to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	string
	 */
	public function addColumn(tableName, schemaName, column)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to modify a column in a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ColumnInterface column
	 * @return	string
	 */
	public function modifyColumn(tableName, schemaName, column)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to delete a column from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string columnName
	 * @return 	string
	 */
	public function dropColumn(tableName, schemaName, columnName)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to add an index to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\Index index
	 * @return	string
	 */
	public function addIndex(tableName, schemaName, index)
	{
		throw new Exception("Not implemented yet");
	}

	/**
 	 * Generates SQL to delete an index from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string indexName
	 * @return	string
	 */
	public function dropIndex(tableName, schemaName, indexName)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to add the primary key to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\Index index
	 * @return	string
	 */
	public function addPrimaryKey(tableName, schemaName, index)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to delete primary key from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @return	string
	 */
	public function dropPrimaryKey(tableName, schemaName)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to add an index to a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	Phalcon\Db\ReferenceInterface reference
	 * @return	string
	 */
	public function addForeignKey(tableName, schemaName, reference)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to delete a foreign key from a table
	 *
	 * @param	string tableName
	 * @param	string schemaName
	 * @param	string referenceName
	 * @return	string
	 */
	public function dropForeignKey(tableName, schemaName, referenceName)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to add the table creation options
	 *
	 * @param	array definition
	 * @return	array
	 */
	protected function _getTableOptions(definition)
	{
		return [];
	}

	/**
	 * Generates SQL to create a table in PostgreSQL
	 *
	 * @param 	string tableName
	 * @param	string schemaName
	 * @param	array definition
	 * @return 	string
	 */
	public function createTable(tableName, schemaName, array! definition)
	{
		throw new Exception("Not implemented yet");
	}

	/**
	 * Generates SQL to drop a table
	 *
	 * @param  string tableName
	 * @param  string schemaName
	 * @param  boolean ifExists
	 * @return boolean
	 */
	public function dropTable(tableName, schemaName, ifExists=true) -> string
	{
		var table, sql;

		if schemaName {
			let table = schemaName . "." . tableName;
		} else {
			let table = tableName;
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
	public function createView(viewName, definition, schemaName) -> string
	{
		var viewSql, view;

		if !fetch viewSql, definition["sql"] {
			throw new Exception("The index 'sql' is required in the definition array");
		}

		if schemaName {
			let view = viewName . "." . schemaName;
		} else {
			let view = viewName;
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
	public function dropView(viewName, schemaName, ifExists = true) -> string
	{
 		var view, sql;

		if schemaName {
			let view = viewName . "." . schemaName;
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
	 * <code>echo dialect->tableExists("posts", "blog")</code>
	 * <code>echo dialect->tableExists("posts")</code>
	 *
	 * @param string tableName
	 * @param string schemaName
	 * @return string
	 */
	public function tableExists(tableName, schemaName = null) -> string
	{
		var sql;
		if schemaName {
			let sql = "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '" . schemaName . "' AND table_name='" . tableName . "'";
		} else {
			let sql = "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = 'public' AND table_name='" . tableName . "'";
		}
		return sql;
	}

	/**
	 * Generates SQL checking for the existence of a schema.view
	 *
	 * @param string viewName
	 * @param string schemaName
	 * @return string
	 */
	public function viewExists(viewName, schemaName = null) -> string
	{
		var sql;
		if schemaName {
			let sql = "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='" . viewName . "' AND schemaname='" . schemaName . "'";
		} else {
			let sql = "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='" . viewName . "'";
		}
		return sql;
	}

	/**
	 * Generates a SQL describing a table
	 *
	 * <code>print_r(dialect->describeColumns("posts") ?></code>
	 *
	 * @param string table
	 * @param string schema
	 * @return string
	 */
	public function describeColumns(table, schema = null) -> string
	{
		var sql;
		if schema {
			let sql = "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='" . schema . "' AND c.table_name='" . table . "' ORDER BY c.ordinal_position";
		} else {
			let sql = "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='" . table . "' ORDER BY c.ordinal_position";
		}
		return sql;
	}

	/**
	 * List all tables on database
	 *
	 *<code>
	 *	print_r(dialect->listTables("blog")) ?>
	 *</code>
	 *
	 * @param       string schemaName
	 * @return      array
	 */
	public function listTables(schemaName = null) -> string
	{
		var sql;
		if schemaName {
			let sql = "SELECT table_name FROM information_schema.tables WHERE table_schema = '" . schemaName . "' ORDER BY table_name";
		} else {
			let sql = "SELECT table_name FROM information_schema.tables WHERE table_schema = 'public' ORDER BY table_name";
		}
		return sql;
	}

	/**
	 * Generates the SQL to list all views of a schema or user
	 *
	 * @param string schemaName
	 * @return string
	 */
	public function listViews(schemaName = null) -> string
	{
		var sql;
		if schemaName {
			let sql = "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '" . schemaName . "' ORDER BY view_name";
		} else {
			let sql = "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name";
		}
		return sql;
	}


	/**
	 * Generates SQL to query indexes on a table
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	string
	 */
	public function describeIndexes(table, schema = null) -> string
	{
		return "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '" . table . "' ORDER BY t.relname, i.relname;";
	}

	/**
	 * Generates SQL to query foreign keys on a table
	 *
	 * @param	string table
	 * @param	string schema
	 * @return	string
	 */
	public function describeReferences(table, schema = null) -> string
	{
		var sql;
		let sql = "SELECT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = 'FOREIGN KEY' AND ";
		if schema {
			let sql .= "tc.table_schema = '" . schema . "' AND tc.table_name='" . table . "'";
		} else {
			let sql .= "tc.table_name='" . table . "'";
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
	public function tableOptions(table, schema = null) -> string
	{
		return "";
	}

}
