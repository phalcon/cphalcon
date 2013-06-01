
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

#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"

/**
 * Phalcon\Db\Dialect\Postgresql
 *
 * Generates database specific SQL for the PostgreSQL RBDM
 */


/**
 * Phalcon\Db\Dialect\Postgresql initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Postgresql){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Postgresql, db_dialect_postgresql, "phalcon\\db\\dialect", phalcon_db_dialect_postgresql_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_postgresql_ce, SL("_escapeChar"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_dialect_postgresql_ce TSRMLS_CC, 1, phalcon_db_dialectinterface_ce);

	return SUCCESS;
}

/**
 * Gets the column name in PostgreSQL
 *
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition){

	zval *column, *size, *column_type, *column_sql = NULL;
	zval *scale;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &column);
	
	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
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
			PHALCON_CONCAT_SVS(column_sql, "CHARACTER VARYING(", size, ")");
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
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized PostgreSQL data type");
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn){

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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn){

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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn){

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
 * @param Phalcon\Db\Index $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex){

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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex){

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
 * @param Phalcon\Db\Index $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey){

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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey){

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
 * @param Phalcon\Db\ReferenceInterface $reference
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey){

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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey){

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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _getTableOptions){

	zval *definition, *empty_array;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &definition);
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	RETURN_CTOR(empty_array);
}

/**
 * Generates SQL to create a table in PostgreSQL
 *
 * @param 	string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable){

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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable){

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
 * Generates SQL to create a view
 *
 * @param string $viewName
 * @param array $definition
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView){

	zval *view_name, *definition, *schema_name, *view_sql;
	zval *view = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &view_name, &definition, &schema_name);
	
	if (!phalcon_array_isset_string(definition, SS("sql"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array");
		return;
	}
	
	PHALCON_OBS_VAR(view_sql);
	phalcon_array_fetch_string(&view_sql, definition, SL("sql"), PH_NOISY_CC);
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(view);
		PHALCON_CONCAT_VSV(view, view_name, ".", schema_name);
	} else {
		PHALCON_CPY_WRT(view, view_name);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVSV(sql, "CREATE VIEW ", view, " AS ", view_sql);
	
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView){

	zval *view_name, *schema_name, *if_exists = NULL, *view = NULL;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &view_name, &schema_name, &if_exists);
	
	if (!if_exists) {
		PHALCON_INIT_VAR(if_exists);
		ZVAL_BOOL(if_exists, 1);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(view);
		PHALCON_CONCAT_VSV(view, view_name, ".", schema_name);
	} else {
		PHALCON_CPY_WRT(view, view_name);
	}
	if (zend_is_true(if_exists)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SV(sql, "DROP VIEW IF EXISTS ", view);
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SV(sql, "DROP VIEW ", view);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists){

	zval *table_name, *schema_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table_name, &schema_name);
	
	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '", schema_name, "' AND table_name='", table_name, "'");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = 'public' AND table_name='", table_name, "'");
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, viewExists){

	zval *view_name, *schema_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &view_name, &schema_name);
	
	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", view_name, "' AND schemaname='", schema_name, "'");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", view_name, "'");
	}
	
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns){

	zval *table, *schema = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='", schema, "' AND c.table_name='", table, "' ORDER BY c.ordinal_position");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='", table, "' ORDER BY c.ordinal_position");
	}
	
	RETURN_CTOR(sql);
}

/**
 * List all tables on database
 *
 *<code>
 *	print_r($dialect->listTables("blog")) ?>
 *</code>
 *
 * @param       string $schemaName
 * @return      array
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables){

	zval *schema_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &schema_name);
	
	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVS(sql, "SELECT table_name FROM information_schema.tables WHERE table_schema = '", schema_name, "' ORDER BY table_name");
	} else {
		PHALCON_INIT_NVAR(sql);
		ZVAL_STRING(sql, "SELECT table_name FROM information_schema.tables WHERE table_schema = 'public' ORDER BY table_name", 1);
	}
	
	RETURN_CTOR(sql);
}

/**
 * Generates the SQL to list all views of a schema or user
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listViews){

	zval *schema_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &schema_name);
	
	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVS(sql, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '", schema_name, "' ORDER BY view_name");
	} else {
		PHALCON_INIT_NVAR(sql);
		ZVAL_STRING(sql, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name", 1);
	}
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to query indexes on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes){

	zval *table, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '", table, "' ORDER BY t.relname, i.relname;");
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences){

	zval *table, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = 'FOREIGN KEY' AND ", 1);
	if (zend_is_true(schema)) {
		PHALCON_SCONCAT_SVSVS(sql, "tc.table_schema = '", schema, "' AND tc.table_name='", table, "'");
	} else {
		PHALCON_SCONCAT_SVS(sql, "tc.table_name='", table, "'");
	}
	
	RETURN_CTOR(sql);
}

/**
 * Generates the SQL to describe the table creation options
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions){

	zval *table, *schema = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_EMPTY_STRING();
}

