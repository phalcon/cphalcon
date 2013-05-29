
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

/**
 * Phalcon\Db\Dialect\Sqlite
 *
 * Generates database specific SQL for the Sqlite RBDM
 */


/**
 * Phalcon\Db\Dialect\Sqlite initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Sqlite){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Sqlite, db_dialect_sqlite, "phalcon\\db\\dialect", phalcon_db_dialect_sqlite_method_entry, 0);

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
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized Sqlite data type");
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

	zval *table_name, *schema_name, *column;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &column);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
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

	zval *table_name, *schema_name, *column;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &column);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
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

	zval *table_name, *schema_name, *column_name;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &column_name);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
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

	zval *table_name, *schema_name, *index;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &index);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
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

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &index_name);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
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

	zval *table_name, *schema_name, *index;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &index);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey){

	zval *table_name, *schema_name;

	phalcon_fetch_params(0, 2, 0, &table_name, &schema_name);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
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

	zval *table_name, *schema_name, *reference;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &reference);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
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

	zval *table_name, *schema_name, *reference_name;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &reference_name);
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
	return;
}

/**
 * Generates SQL to add the table creation options
 *
 * @param array $definition
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, _getTableOptions){

	zval *definition, *empty_array;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &definition);
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	RETURN_CTOR(empty_array);
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
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Not implemented yet");
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
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &table_name, &schema_name, &if_exists);
	
	if (!if_exists) {
		PHALCON_INIT_VAR(if_exists);
		ZVAL_BOOL(if_exists, 1);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_VSV(table, schema_name, ".", table_name);
	} else {
		PHALCON_CPY_WRT(table, table_name);
	}
	if (zend_is_true(if_exists)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SV(sql, "DROP TABLE IF EXISTS ", table);
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SV(sql, "DROP TABLE ", table);
	}
	
	RETURN_CTOR(sql);
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

	zval *table_name, *schema_name = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table_name, &schema_name);
	
	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='", table_name, "'");
	RETURN_CTOR(sql);
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

	zval *table, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "PRAGMA table_info('", table, "')");
	RETURN_CTOR(sql);
}

/**
 * List all tables on database
 *
 * <code>print_r($dialect->listTables("blog") ?></code>
 *
 * @param       string $schemaName
 * @return      array
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listTables){

	zval *schema_name = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &schema_name);
	
	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT tbl_name FROM sqlite_master WHERE type = 'table' ORDER BY tbl_name", 1);
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to query indexes on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes){

	zval *table, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "PRAGMA index_list('", table, "')");
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to query indexes detail on a table
 *
 * @param string $indexName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex){

	zval *index_name, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index_name);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "PRAGMA index_info('", index_name, "')");
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences){

	zval *table, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "PRAGMA foreign_key_list('", table, "')");
	RETURN_CTOR(sql);
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_EMPTY_STRING();
}

/**
 * Generates the SQL to list all views of a schema or user.
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listViews){

	zval *schema_name = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &schema_name);

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}

	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT name AS view_name FROM sqlite_master WHERE type='view' AND sql NOT NULL ORDER BY view_name", 1);
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to create a view
 *
 * @param string $viewName
 * @param string $sql
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView){

	zval *view_name, *view_sql, *definition, *schema_name = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &view_name, &definition, &schema_name);

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}

	if (!phalcon_array_isset_string(definition, SS("sql"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array");
		return;
	}

	PHALCON_OBS_VAR(view_sql);
	phalcon_array_fetch_string(&view_sql, definition, SL("sql"), PH_NOISY_CC);

	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVSV(sql, "CREATE VIEW ", view_name, " AS ", view_sql);
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

	zval *view_name, *schema_name, *if_exists = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &view_name, &schema_name, &if_exists);

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}

	if (!if_exists) {
		PHALCON_INIT_VAR(if_exists);
		ZVAL_BOOL(if_exists, 1);
	}

	if (zend_is_true(if_exists)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SV(sql, "DROP VIEW IF EXISTS ", view_name);
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SV(sql, "DROP VIEW ", view_name);
	}
	RETURN_CTOR(sql);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, viewExists){

	zval *view_name, *schema_name = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &view_name, &schema_name);

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}

	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND sql NOT NULL AND tbl_name='", view_name, "'");
	RETURN_CTOR(sql);
}
