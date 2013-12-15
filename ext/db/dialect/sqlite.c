
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
  |          Rack Lin <racklin@gmail.com>                                  |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"

/**
 * Phalcon\Db\Dialect\Sqlite
 *
 * Generates database specific SQL for the Sqlite RBDM
 */


/**
 * Phalcon\Db\Dialect\Sqlite initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Sqlite){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Sqlite, db_dialect_sqlite, phalcon_db_dialect_ce, phalcon_db_dialect_sqlite_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_sqlite_ce, SL("_escapeChar"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_dialect_sqlite_ce TSRMLS_CC, 1, phalcon_db_dialectinterface_ce);

	return SUCCESS;
}

/**
 * Gets the column name in Sqlite
 *
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnDefinition){

	zval *column, *size, *column_type, *column_sql = NULL;
	zval *scale;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &column);
	
	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an instance of Phalcon\\Db\\Column");
		return;
	}
	
	PHALCON_INIT_VAR(size);
	phalcon_call_method(size, column, "getsize");
	
	PHALCON_INIT_VAR(column_type);
	phalcon_call_method(column_type, column, "gettype");
	
	switch (phalcon_get_intval(column_type)) {
	
		case 0:
			PHALCON_INIT_VAR(column_sql);
			ZVAL_STRING(column_sql, "INT", 1);
			break;
	
		case 1:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "DATE", 1);
			break;
	
		case 2:
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVS(column_sql, "VARCHAR(", size, ")");
			break;
	
		case 3:
			PHALCON_INIT_VAR(scale);
			phalcon_call_method(scale, column, "getscale");
	
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVSVS(column_sql, "NUMERIC(", size, ",", scale, ")");
			break;
	
		case 4:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "TIMESTAMP", 1);
			break;
	
		case 5:
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVS(column_sql, "CHARACTER(", size, ")");
			break;
	
		case 6:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "TEXT", 1);
			break;
	
		case 7:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "FLOAT", 1);
			break;
	
		default:
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized SQLite data type");
			return;
	
	}
	
	RETURN_CTOR(column_sql);
}

/**
 * Generates SQL to add a column to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn){

	zval *table_name, *schema_name, *column, *sql = NULL, *name;
	zval *column_definition, *is_not_null, *is_autoincrement;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &column);

	PHALCON_VERIFY_INTERFACE_EX(column, phalcon_db_columninterface_ce, phalcon_db_exception_ce, 1);

	PHALCON_INIT_VAR(sql);
	if (zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE \"", schema_name, "\".\"", table_name, "\" ADD COLUMN ");
	}
	else {
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE \"", table_name, "\" ADD COLUMN ");
	}

	PHALCON_INIT_VAR(name);
	phalcon_call_method(name, column, "getname");

	PHALCON_INIT_VAR(column_definition);
	phalcon_call_method_p1(column_definition, this_ptr, "getcolumndefinition", column);
	PHALCON_SCONCAT_SVSV(sql, "\"", name, "\" ", column_definition);

	PHALCON_INIT_VAR(is_not_null);
	phalcon_call_method(is_not_null, column, "isnotnull");
	if (zend_is_true(is_not_null)) {
		phalcon_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}

	PHALCON_INIT_VAR(is_autoincrement);
	phalcon_call_method(is_autoincrement, column, "isautoincrement");
	/*
	 * See http://www.sqlite.org/syntaxdiagrams.html#column-constraint
	 */
	if (zend_is_true(is_autoincrement)) {
		phalcon_concat_self_str(&sql, SL(" PRIMARY KEY AUTOINCREMENT") TSRMLS_CC);
	}

	RETURN_CTOR(sql);
}

/**
 * Generates SQL to modify a column in a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, modifyColumn){

	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Altering a DB column is not supported by SQLite");
}

/**
 * Generates SQL to delete a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropColumn){

	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Dropping DB column is not supported by SQLite");
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex){

	zval *table_name, *schema_name, *index, *sql = NULL, *columns;
	zval *quoted_column_list, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &index);
	
	PHALCON_VERIFY_INTERFACE_EX(index, phalcon_db_indexinterface_ce, phalcon_db_exception_ce, 1);

	PHALCON_INIT_VAR(name);
	phalcon_call_method(name, index, "getname");

	PHALCON_INIT_VAR(sql);
	if (zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVSVSVS(sql, "CREATE INDEX \"", schema_name, "\".\"", name, "\" ON \"", table_name, "\" (");
	}
	else {
		PHALCON_CONCAT_SVSVS(sql, "CREATE INDEX \"", name, "\" ON \"", table_name, "\" (");
	}

	PHALCON_INIT_VAR(columns);
	phalcon_call_method(columns, index, "getcolumns");

	PHALCON_INIT_VAR(quoted_column_list);
	phalcon_call_method_p1(quoted_column_list, this_ptr, "getcolumnlist", columns);

	PHALCON_SCONCAT_VS(sql, quoted_column_list, ")");
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to delete an index from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $indexName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropIndex){

	zval *table_name, *schema_name, *index_name;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &index_name);

	PHALCON_INIT_VAR(sql);
	if (zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVSVS(sql, "DROP INDEX \"", schema_name, "\".\"", index_name, "\"");
	}
	else {
		PHALCON_CONCAT_SVS(sql, "DROP INDEX \"", index_name, "\"");
	}

	RETURN_CTOR(sql);
}

/**
 * Generates SQL to add the primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey){

	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Adding a primary key after table has been created is not supported by SQLite");
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey){

	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Removing a primary key after table has been created is not supported by SQLite");
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\Reference $reference
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addForeignKey){

	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Adding a foreign key constraint to an existing table is not supported by SQLite");
}

/**
 * Generates SQL to delete a foreign key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $referenceName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropForeignKey){

	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Dropping a foreign key constraint is not supported by SQLite");
}

/**
 * Generates SQL to add the table creation options
 *
 * @param array $definition
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, _getTableOptions){

	zval *definition;

	phalcon_fetch_params(0, 1, 0, &definition);

	array_init(return_value);
}

/**
 * Generates SQL to create a table in Sqlite
 *
 * @param 	string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable){

	zval *table_name, *schema_name, *definition;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &definition);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
	return;
}

/**
 * Generates SQL to drop a table
 *
 * @param  string $tableName
 * @param  string $schemaName
 * @param  boolean $ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropTable){

	zval *table_name, *schema_name, *if_exists = NULL, *table = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &table_name, &schema_name, &if_exists);
	
	if (!if_exists) {
		if_exists = PHALCON_GLOBAL(z_true);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_VSV(table, schema_name, "\".\"", table_name);
	} else {
		table = table_name;
	}

	if (zend_is_true(if_exists)) {
		PHALCON_CONCAT_SVS(return_value, "DROP TABLE IF EXISTS \"", table, "\"");
	} else {
		PHALCON_CONCAT_SVS(return_value, "DROP TABLE \"", table, "\"");
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Generates SQL to create a view
 *
 * @param string $viewName
 * @param array $definition
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView){

	zval *view_name, *definition, *schema_name, *view_sql;
	zval *view = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &view_name, &definition, &schema_name);
	
	if (!phalcon_array_isset_string(definition, SS("sql"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array");
		return;
	}
	
	PHALCON_OBS_VAR(view_sql);
	phalcon_array_fetch_string(&view_sql, definition, SL("sql"), PH_NOISY);
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(view);
		PHALCON_CONCAT_VSV(view, schema_name, "\".\"", view_name);
	} else {
		PHALCON_CPY_WRT(view, view_name);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVSV(sql, "CREATE VIEW \"", view, "\" AS ", view_sql);
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to drop a view
 *
 * @param string $viewName
 * @param string $schemaName
 * @param boolean $ifExists
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropView){

	zval *view_name, *schema_name, *if_exists = NULL, *view = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &view_name, &schema_name, &if_exists);
	
	if (!if_exists) {
		if_exists = PHALCON_GLOBAL(z_true);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(view);
		PHALCON_CONCAT_VSV(view, schema_name, "\".\"", view_name);
	} else {
		PHALCON_CPY_WRT(view, view_name);
	}
	if (zend_is_true(if_exists)) {
		PHALCON_CONCAT_SVS(return_value, "DROP VIEW IF EXISTS \"", view, "\"");
	} else {
		PHALCON_CONCAT_SVS(return_value, "DROP VIEW \"", view, "\"");
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>echo $dialect->tableExists("posts", "blog")</code>
 * <code>echo $dialect->tableExists("posts")</code>
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableExists){

	zval *table_name, *schema_name = NULL;

	phalcon_fetch_params(0, 1, 1, &table_name, &schema_name);
	
	PHALCON_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='", table_name, "'");
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, viewExists){

	zval *view_name, *schema_name = NULL;

	phalcon_fetch_params(0, 1, 1, &view_name, &schema_name);
	
	PHALCON_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='", view_name, "'");
}

/**
 * Generates a SQL describing a table
 *
 * <code>print_r($dialect->describeColumns("posts") ?></code>
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeColumns){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);
	
	PHALCON_CONCAT_SVS(return_value, "PRAGMA table_info('", table, "')");
}

/**
 * List all tables on database
 *
 * <code>print_r($dialect->listTables("blog")) ?></code>
 *
 * @param       string $schemaName
 * @return      array
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listTables){

	zval *schema_name = NULL;

	phalcon_fetch_params(0, 0, 1, &schema_name);
	
	RETURN_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'table' ORDER BY tbl_name", 1);
}

/**
 * Generates the SQL to list all views of a schema or user
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listViews){

	zval *schema_name = NULL;

	phalcon_fetch_params(0, 0, 1, &schema_name);

	RETURN_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name", 1);
}

/**
 * Generates SQL to query indexes on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);
	
	PHALCON_CONCAT_SVS(return_value, "PRAGMA index_list('", table, "')");
}

/**
 * Generates SQL to query indexes detail on a table
 *
 * @param string $indexName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex){

	zval *index_name;

	phalcon_fetch_params(0, 1, 0, &index_name);
	
	PHALCON_CONCAT_SVS(return_value, "PRAGMA index_info('", index_name, "')");
}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);
	
	PHALCON_CONCAT_SVS(return_value, "PRAGMA foreign_key_list('", table, "')");
}

/**
 * Generates the SQL to describe the table creation options
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableOptions){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);

	RETURN_EMPTY_STRING();
}
