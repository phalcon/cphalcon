
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

/**
 * Phalcon\Db\Dialect\Sqlite
 *
 * Generates database specific SQL for the Sqlite RBDM
 */


/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnList){

	zval *column_list = NULL, *str_list = NULL, *column = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(str_list);
	array_init(str_list);
	
	if (!phalcon_valid_foreach(column_list TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(column_list);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(column);
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CONCAT_SVS(r0, "\"", column, "\"");
		phalcon_array_append(&str_list, r0, PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ", ", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_join(r1, c0, column_list TSRMLS_CC);
	RETURN_CTOR(r1);
}

/**
 * Gets the column name in Sqlite
 *
 * @param Phalcon\Db\Column $column
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnDefinition){

	zval *column = NULL, *size = NULL, *column_type = NULL, *column_sql = NULL;
	zval *scale = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an instance of Phalcon\\Db\\Column");
		return;
	}
	
	PHALCON_INIT_VAR(size);
	PHALCON_CALL_METHOD(size, column, "getsize", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(column_type);
	PHALCON_CALL_METHOD(column_type, column, "gettype", PH_NO_CHECK);
	
	if (phalcon_compare_strict_long(column_type, 0 TSRMLS_CC)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "INT", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(column_type, 1 TSRMLS_CC)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "DATE", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(column_type, 2 TSRMLS_CC)) {
		PHALCON_INIT_VAR(column_sql);
		PHALCON_CONCAT_SVS(column_sql, "VARCHAR(", size, ")");
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(column_type, 3 TSRMLS_CC)) {
		PHALCON_INIT_VAR(scale);
		PHALCON_CALL_METHOD(scale, column, "getscale", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(column_sql);
		PHALCON_CONCAT_SVSVS(column_sql, "NUMERIC(", size, ",", scale, ")");
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(column_type, 4 TSRMLS_CC)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "TIMESTAMP", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(column_type, 5 TSRMLS_CC)) {
		PHALCON_INIT_VAR(column_sql);
		PHALCON_CONCAT_SVS(column_sql, "CHARACTER(", size, ")");
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(column_type, 6 TSRMLS_CC)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "TEXT", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(column_type, 7 TSRMLS_CC)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "FLOAT", 1);
		goto ph_end_0;
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized Sqlite data type");
	return;
	
	ph_end_0:
	
	RETURN_CTOR(column_sql);
}

/**
 * Generates SQL to add a column to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\Column $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn){


	
}

/**
 * Generates SQL to modify a column in a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\Column $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, modifyColumn){


	
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


	
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\Index $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex){


	
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


	
}

/**
 * Generates SQL to add the primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\Index $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey){


	
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey){


	
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


	
}

/**
 * Generates SQL to add the table creation options
 *
 * @param array $definition
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, _getTableOptions){

	zval *definition = NULL, *empty_array = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

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
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable){


	
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

	zval *table_name = NULL, *schema_name = NULL, *if_exists = NULL, *table = NULL;
	zval *sql = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &table_name, &schema_name, &if_exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!if_exists) {
		PHALCON_ALLOC_ZVAL_MM(if_exists);
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
		PHALCON_INIT_VAR(sql);
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

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_ALLOC_ZVAL_MM(schema_name);
		ZVAL_NULL(schema_name);
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

	zval *table = NULL, *schema = NULL, *sql = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
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

	zval *schema_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_ALLOC_ZVAL_MM(schema_name);
		ZVAL_NULL(schema_name);
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

	zval *table = NULL, *schema = NULL, *sql = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
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

	zval *index_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

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

	zval *table = NULL, *schema = NULL, *sql = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
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

	zval *table = NULL, *schema = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_STRING("", 1);
}

