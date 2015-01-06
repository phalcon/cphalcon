
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
  |          Marcio Paiva <mpaivabarbosa@gmail.com>                        |
  +------------------------------------------------------------------------+
*/

#include "db/dialect/oracle.h"
#include "db/dialect.h"
#include "db/dialectinterface.h"
#include "db/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Db\Dialect\Oracle
 *
 * Generates database specific SQL for the Oracle RBDMS
 */
zend_class_entry *phalcon_db_dialect_oracle_ce;

PHP_METHOD(Phalcon_Db_Dialect_Oracle, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, _getTableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, createTable);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, createView);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropView);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, viewExists);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, listTables);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, listViews);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, getSqlTable);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, limit);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, select);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsSavepoints);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsReleaseSavepoints);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_getsqltable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_db_dialect_oracle_method_entry[] = {
	PHP_ME(Phalcon_Db_Dialect_Oracle, getColumnDefinition, arginfo_phalcon_db_dialectinterface_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addColumn, arginfo_phalcon_db_dialectinterface_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, modifyColumn, arginfo_phalcon_db_dialectinterface_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropColumn, arginfo_phalcon_db_dialectinterface_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addIndex, arginfo_phalcon_db_dialectinterface_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropIndex, arginfo_phalcon_db_dialectinterface_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addPrimaryKey, arginfo_phalcon_db_dialectinterface_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropPrimaryKey, arginfo_phalcon_db_dialectinterface_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addForeignKey, arginfo_phalcon_db_dialectinterface_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropForeignKey, arginfo_phalcon_db_dialectinterface_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, _getTableOptions, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Dialect_Oracle, createTable, arginfo_phalcon_db_dialectinterface_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropTable, arginfo_phalcon_db_dialectinterface_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, createView, arginfo_phalcon_db_dialectinterface_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropView, arginfo_phalcon_db_dialectinterface_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, tableExists, arginfo_phalcon_db_dialectinterface_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, viewExists, arginfo_phalcon_db_dialectinterface_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeColumns, arginfo_phalcon_db_dialectinterface_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, listTables, arginfo_phalcon_db_dialectinterface_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, listViews, arginfo_phalcon_db_dialectinterface_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeIndexes, arginfo_phalcon_db_dialectinterface_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeReferences, arginfo_phalcon_db_dialectinterface_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, tableOptions, arginfo_phalcon_db_dialectinterface_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, getSqlTable, arginfo_phalcon_db_dialect_oracle_getsqltable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, limit, arginfo_phalcon_db_dialectinterface_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, select, arginfo_phalcon_db_dialectinterface_select, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, supportsSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, supportsReleaseSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Db\Dialect\Oracle initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Oracle){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Oracle, db_dialect_oracle, phalcon_db_dialect_ce, phalcon_db_dialect_oracle_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_oracle_ce, SL("_escapeChar"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_dialect_oracle_ce TSRMLS_CC, 1, phalcon_db_dialectinterface_ce);

	return SUCCESS;
}

/**
 * Gets the column name in Oracle
 *
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, getColumnDefinition){

	zval *column, *size = NULL, *column_type = NULL, *column_sql = NULL;
	zval *scale = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &column);
	
	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	
	PHALCON_CALL_METHOD(&size, column, "getsize");
	PHALCON_CALL_METHOD(&column_type, column, "gettype");
	
	switch (phalcon_get_intval(column_type)) {
	
		case 0:
			PHALCON_INIT_VAR(column_sql);
			ZVAL_STRING(column_sql, "INTEGER", 1);
			break;
	
		case 1:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "DATE", 1);
			break;
	
		case 2:
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVS(column_sql, "VARCHAR2(", size, ")");
			break;
	
		case 3:
			PHALCON_CALL_METHOD(&scale, column, "getscale");
	
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVSVS(column_sql, "NUMBER(", size, ",", scale, ")");
			break;
	
		case 4:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "TIMESTAMP", 1);
			break;
	
		case 5:
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVS(column_sql, "CHAR(", size, ")");
			break;
	
		case 6:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "TEXT", 1);
			break;
	
		case 7:
			PHALCON_CALL_METHOD(&scale, column, "getscale");
	
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVSVS(column_sql, "FLOAT(", size, ",", scale, ")");
			break;
	
		case 8:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "TINYINT(1)", 1);
			break;
	
		default:
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized Oracle data type");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addColumn){

	zval *table_name, *schema_name, *column;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &column);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, modifyColumn){

	zval *table_name, *schema_name, *column;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &column);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropColumn){

	zval *table_name, *schema_name, *column_name;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &column_name);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addIndex){

	zval *table_name, *schema_name, *index;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &index);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropIndex){

	zval *table_name, *schema_name, *index_name;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &index_name);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addPrimaryKey){

	zval *table_name, *schema_name, *index;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &index);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
	return;
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropPrimaryKey){

	zval *table_name, *schema_name;

	phalcon_fetch_params(0, 2, 0, &table_name, &schema_name);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addForeignKey){

	zval *table_name, *schema_name, *reference;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &reference);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropForeignKey){

	zval *table_name, *schema_name, *reference_name;

	phalcon_fetch_params(0, 3, 0, &table_name, &schema_name, &reference_name);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Not implemented yet");
	return;
}

/**
 * Generates SQL to add the table creation options
 *
 * @param array $definition
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, _getTableOptions){

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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, createTable){

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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropTable){

	zval *table_name, *schema_name, *if_exists = NULL, *table = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &table_name, &schema_name, &if_exists);
	
	if (!if_exists) {
		if_exists = PHALCON_GLOBAL(z_true);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_VSV(table, schema_name, ".", table_name);
	} else {
		PHALCON_CPY_WRT(table, table_name);
	}
	if (zend_is_true(if_exists)) {
		PHALCON_CONCAT_SV(return_value, "DROP TABLE IF EXISTS ", table);
	} else {
		PHALCON_CONCAT_SV(return_value, "DROP TABLE ", table);
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, createView){

	zval *view_name, *definition, *schema_name, *view_sql;
	zval *view = NULL;

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
		PHALCON_CONCAT_VSV(view, view_name, ".", schema_name);
	} else {
		PHALCON_CPY_WRT(view, view_name);
	}
	
	PHALCON_CONCAT_SVSV(return_value, "CREATE VIEW ", view, " AS ", view_sql);
	
	PHALCON_MM_RESTORE();
}

/**
 * Generates SQL to drop a view
 *
 * @param string $viewName
 * @param string $schemaName
 * @param boolean $ifExists
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropView){

	zval *view_name, *schema_name, *if_exists = NULL, *view = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &view_name, &schema_name, &if_exists);
	
	if (!if_exists) {
		if_exists = PHALCON_GLOBAL(z_true);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(view);
		PHALCON_CONCAT_SVSVS(view, "`", schema_name, "`.`", view_name, "`");
	} else {
		PHALCON_INIT_NVAR(view);
		PHALCON_CONCAT_SVS(view, "`", view_name, "`");
	}
	if (zend_is_true(if_exists)) {
		PHALCON_CONCAT_SV(return_value, "DROP VIEW IF EXISTS ", view);
	} else {
		PHALCON_CONCAT_SV(return_value, "DROP VIEW ", view);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 *<code>
 *	var_dump($dialect->tableExists("posts", "blog"));
 *	var_dump($dialect->tableExists("posts"));
 *</code>
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableExists){

	zval *table_name, *schema_name = NULL;

	phalcon_fetch_params(0, 1, 1, &table_name, &schema_name);
	
	if (schema_name && zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_TABLES WHERE TABLE_NAME='", table_name, "' AND OWNER = '", schema_name, "'");
	} else {
		PHALCON_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_TABLES WHERE TABLE_NAME='", table_name, "'");
	}
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, viewExists){

	zval *view_name, *schema_name = NULL;

	phalcon_fetch_params(0, 1, 1, &view_name, &schema_name);
	
	if (schema_name && zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_VIEWS WHERE VIEW_NAME='", view_name, "' AND OWNER='", schema_name, "'");
	} else {
		PHALCON_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_VIEWS WHERE VIEW_NAME='", view_name, "'");
	}
}

/**
 * Generates a SQL describing a table
 *
 *<code>
 *	print_r($dialect->describeColumns("posts")); ?>
 *</code>
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeColumns){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);
	
	if (schema && zend_is_true(schema)) {
		PHALCON_CONCAT_SVSVS(return_value, "SELECT TC.COLUMN_NAME, TC.DATA_TYPE, TC.DATA_LENGTH, TC.DATA_PRECISION, TC.DATA_SCALE, TC.NULLABLE, C.CONSTRAINT_TYPE, TC.DATA_DEFAULT, CC.POSITION FROM ALL_TAB_COLUMNS TC LEFT JOIN (ALL_CONS_COLUMNS CC JOIN ALL_CONSTRAINTS C ON (CC.CONSTRAINT_NAME = C.CONSTRAINT_NAME AND CC.TABLE_NAME = C.TABLE_NAME AND CC.OWNER = C.OWNER AND C.CONSTRAINT_TYPE = 'P')) ON TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME WHERE TC.TABLE_NAME = '", table, "' AND TC.OWNER = '", schema, "' ORDER BY TC.COLUMN_ID");
	} else {
		PHALCON_CONCAT_SVS(return_value, "SELECT TC.COLUMN_NAME, TC.DATA_TYPE, TC.DATA_LENGTH, TC.DATA_PRECISION, TC.DATA_SCALE, TC.NULLABLE, C.CONSTRAINT_TYPE, TC.DATA_DEFAULT, CC.POSITION FROM ALL_TAB_COLUMNS TC LEFT JOIN (ALL_CONS_COLUMNS CC JOIN ALL_CONSTRAINTS C ON (CC.CONSTRAINT_NAME = C.CONSTRAINT_NAME AND CC.TABLE_NAME = C.TABLE_NAME AND CC.OWNER = C.OWNER AND C.CONSTRAINT_TYPE = 'P')) ON TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME WHERE TC.TABLE_NAME = '", table, "' ORDER BY TC.COLUMN_ID");
	}
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, listTables){

	zval *schema_name = NULL;

	phalcon_fetch_params(0, 0, 1, &schema_name);
	
	if (schema_name && zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVS(return_value, "SELECT TABLE_NAME, OWNER FROM ALL_TABLES WHERE OWNER='", schema_name, "' ORDER BY OWNER, TABLE_NAME");
	} else {
		RETURN_STRING("SELECT TABLE_NAME, OWNER FROM ALL_TABLES ORDER BY OWNER, TABLE_NAME ", 1);
	}
}

/**
 * Generates the SQL to list all views of a schema or user
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, listViews){

	zval *schema_name = NULL;

	phalcon_fetch_params(0, 0, 1, &schema_name);
	
	if (schema_name && zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVS(return_value, "SELECT VIEW_NAME FROM ALL_VIEWS WHERE OWNER='", schema_name, "' ORDER BY VIEW_NAME");
	} else {
		RETURN_STRING("SELECT VIEW_NAME FROM ALL_VIEWS VIEW_NAME", 1);
	}
}

/**
 * Generates SQL to query indexes on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeIndexes){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);
	
	if (schema && zend_is_true(schema)) {
		PHALCON_CONCAT_SVSVS(return_value, "SELECT I.TABLE_NAME, 0 AS C0, I.INDEX_NAME, IC.COLUMN_POSITION, IC.COLUMN_NAME FROM ALL_INDEXES I JOIN ALL_IND_COLUMNS IC ON I.INDEX_NAME = IC.INDEX_NAME WHERE  I.TABLE_NAME = '", table, "' AND IC.INDEX_OWNER = '", schema, "'");
	} else {
		PHALCON_CONCAT_SVS(return_value, "SELECT I.TABLE_NAME, 0 AS C0, I.INDEX_NAME, IC.COLUMN_POSITION, IC.COLUMN_NAME FROM ALL_INDEXES I JOIN ALL_IND_COLUMNS IC ON I.INDEX_NAME = IC.INDEX_NAME WHERE  I.TABLE_NAME = '", table, "'");
	}
}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeReferences){

	zval *table, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT AC.TABLE_NAME, CC.COLUMN_NAME, AC.CONSTRAINT_NAME, AC.R_OWNER, RCC.TABLE_NAME R_TABLE_NAME, RCC.COLUMN_NAME R_COLUMN_NAME FROM ALL_CONSTRAINTS AC JOIN ALL_CONS_COLUMNS CC ON AC.CONSTRAINT_NAME = CC.CONSTRAINT_NAME JOIN ALL_CONS_COLUMNS RCC ON AC.R_OWNER = RCC.OWNER AND AC.R_CONSTRAINT_NAME = RCC.CONSTRAINT_NAME WHERE AC.CONSTRAINT_TYPE='R' ", 1);
	if (schema && zend_is_true(schema)) {
		PHALCON_SCONCAT_SVSVS(sql, "AND AC.OWNER='", schema, "' AND AC.TABLE_NAME = '", table, "'");
	} else {
		PHALCON_SCONCAT_SVS(sql, "AND AC.TABLE_NAME = '", table, "'");
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
PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableOptions){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);
	
	RETURN_EMPTY_STRING();
}

/**
 * Transform an intermediate representation for a schema/table into a database system valid expression
 *
 * @param array $table
 * @param string $escapeChar
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, getSqlTable){

	zval *table, *escape_char = NULL, *table_name, *sql_table = NULL;
	zval *schema_name, *sql_schema = NULL, *alias_name;
	zval *sql_table_alias = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &escape_char);
	
	if (!escape_char) {
		PHALCON_INIT_VAR(escape_char);
	} else {
		PHALCON_SEPARATE_PARAM(escape_char);
	}
	
	if (Z_TYPE_P(escape_char) == IS_NULL) {
		PHALCON_OBS_NVAR(escape_char);
		phalcon_read_property_this(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY TSRMLS_CC);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) { 
	
		/** 
		 * The index '0' is the table name
		 */
		PHALCON_OBS_VAR(table_name);
		phalcon_array_fetch_long(&table_name, table, 0, PH_NOISY);
		if (PHALCON_GLOBAL(db).escape_identifiers) {
			PHALCON_INIT_VAR(sql_table);
			PHALCON_CONCAT_VVV(sql_table, escape_char, table_name, escape_char);
		} else {
			PHALCON_CPY_WRT(sql_table, table_name);
		}
	
		/** 
		 * The index '1' is the schema name
		 */
		PHALCON_OBS_VAR(schema_name);
		phalcon_array_fetch_long(&schema_name, table, 1, PH_NOISY);
		if (Z_TYPE_P(schema_name) != IS_NULL) {
			if (PHALCON_GLOBAL(db).escape_identifiers) {
				PHALCON_INIT_VAR(sql_schema);
				PHALCON_CONCAT_VVVSV(sql_schema, escape_char, schema_name, escape_char, ".", sql_table);
			} else {
				PHALCON_INIT_NVAR(sql_schema);
				PHALCON_CONCAT_VSV(sql_schema, schema_name, ".", sql_table);
			}
		} else {
			PHALCON_CPY_WRT(sql_schema, sql_table);
		}
	
		/** 
		 * The index '2' is the table alias
		 */
		if (phalcon_array_isset_long(table, 2)) {
	
			PHALCON_OBS_VAR(alias_name);
			phalcon_array_fetch_long(&alias_name, table, 2, PH_NOISY);
			if (PHALCON_GLOBAL(db).escape_identifiers) {
				PHALCON_INIT_VAR(sql_table_alias);
				PHALCON_CONCAT_VSVVV(sql_table_alias, sql_schema, " ", escape_char, alias_name, escape_char);
			} else {
				PHALCON_INIT_NVAR(sql_table_alias);
				PHALCON_CONCAT_VSV(sql_table_alias, sql_schema, " ", alias_name);
			}
		} else {
			PHALCON_CPY_WRT(sql_table_alias, sql_schema);
		}
	
		RETURN_CTOR(sql_table_alias);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_INIT_NVAR(sql_table);
		PHALCON_CONCAT_VVV(sql_table, escape_char, table, escape_char);
		RETURN_CTOR(sql_table);
	}
	
	RETURN_CTOR(table);
}

/**
 * Generates the SQL for LIMIT clause
 *
 *<code>
 * $sql = $dialect->limit('SELECT * FROM robots', 10);
 * echo $sql; // SELECT * FROM robots LIMIT 10
 *</code>
 *
 * @param string $sqlQuery
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, limit){

	zval *sql_query, *number, *limit, *sql_limit;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (phalcon_is_numeric(number)) {

		PHALCON_INIT_VAR(limit);
		ZVAL_LONG(limit, phalcon_get_intval(number));

		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CONCAT_VSV(sql_limit, sql_query, " LIMIT ", limit);
		RETURN_CTOR(sql_limit);
	}

	RETURN_CTOR(sql_query);
}

/**
 * Builds a SELECT statement
 *
 * @param array $definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, select){

	zval *definition, *escape_char = NULL, *columns, *selected_columns, *distinct;
	zval *column = NULL, *column_item = NULL, *column_sql = NULL, *columns_sql = NULL;
	zval *column_domain = NULL, *column_domain_sql = NULL, *column_alias = NULL;
	zval *column_alias_sql = NULL, *tables, *selected_tables;
	zval *table = NULL, *sql_table = NULL, *tables_sql = NULL, *sql, *joins;
	zval *join = NULL, *type = NULL, *sql_join = NULL, *join_conditions_array = NULL;
	zval *join_expressions = NULL, *join_condition = NULL, *join_expression = NULL;
	zval *join_conditions = NULL, *where_conditions;
	zval *where_expression = NULL, *group_items, *group_fields;
	zval *group_field = NULL, *group_expression = NULL, *group_sql;
	zval *group_clause, *having_conditions, *having_expression = NULL;
	zval *order_fields, *order_items, *order_item = NULL;
	zval *order_expression = NULL, *order_sql_item = NULL, *sql_order_type = NULL;
	zval *order_sql_item_type = NULL, *order_sql, *limit_value;
	zval *number, *offset, *tmp1 = NULL, *tmp2 = NULL;
	zval *z_one, *ini_range, *end_range = NULL, *sql_limit;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4, *ah5;
	HashPosition hp0, hp1, hp2, hp3, hp4, hp5;
	zval **hd;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(definition) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Invalid SELECT definition");
		return;
	}
	if (!phalcon_array_isset_string(definition, SS("tables"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "The index 'tables' is required in the definition array");
		return;
	}

	if (!phalcon_array_isset_string(definition, SS("columns"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}

	PHALCON_MM_GROW();

	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_OBS_VAR(escape_char);
		phalcon_read_property_this(&escape_char, this_ptr, SL("_escapeChar"), PH_NOISY TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(escape_char);
	}

	PHALCON_OBS_VAR(columns);
	phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY);
	if (Z_TYPE_P(columns) == IS_ARRAY) {

		PHALCON_INIT_VAR(selected_columns);
		array_init(selected_columns);

		phalcon_is_iterable(columns, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_HVALUE(column);

			/**
			 * Escape column name
			 */
			PHALCON_OBS_NVAR(column_item);
			phalcon_array_fetch_long(&column_item, column, 0, PH_NOISY);
			if (Z_TYPE_P(column_item) == IS_ARRAY) {
				PHALCON_CALL_METHOD(&column_sql, this_ptr, "getsqlexpression", column_item, escape_char);
			} else if (PHALCON_IS_STRING(column_item, "*")) {
				PHALCON_CPY_WRT(column_sql, column_item);
			} else if (PHALCON_GLOBAL(db).escape_identifiers) {
				PHALCON_INIT_NVAR(column_sql);
				PHALCON_CONCAT_VVV(column_sql, escape_char, column_item, escape_char);
			} else {
				PHALCON_CPY_WRT(columns_sql, column_item);
			}

			/**
			 * Escape column domain
			 */
			if (phalcon_array_isset_long(column, 1)) {

				PHALCON_OBS_NVAR(column_domain);
				phalcon_array_fetch_long(&column_domain, column, 1, PH_NOISY);
				if (zend_is_true(column_domain)) {
					if (PHALCON_GLOBAL(db).escape_identifiers) {
						PHALCON_INIT_NVAR(column_domain_sql);
						PHALCON_CONCAT_VVVSV(column_domain_sql, escape_char, column_domain, escape_char, ".", column_sql);
					} else {
						PHALCON_INIT_NVAR(column_domain_sql);
						PHALCON_CONCAT_VSV(column_domain_sql, column_domain, ".", column_sql);
					}
				} else {
					PHALCON_CPY_WRT(column_domain_sql, column_sql);
				}
			} else {
				PHALCON_CPY_WRT(column_domain_sql, column_sql);
			}

			/**
			 * Escape column alias
			 */
			if (phalcon_array_isset_long(column, 2)) {

				PHALCON_OBS_NVAR(column_alias);
				phalcon_array_fetch_long(&column_alias, column, 2, PH_NOISY);
				if (zend_is_true(column_alias)) {
					if (PHALCON_GLOBAL(db).escape_identifiers) {
						PHALCON_INIT_NVAR(column_alias_sql);
						PHALCON_CONCAT_VSVVV(column_alias_sql, column_domain_sql, " ", escape_char, column_alias, escape_char);
					} else {
						PHALCON_INIT_NVAR(column_alias_sql);
						PHALCON_CONCAT_VSV(column_alias_sql, column_domain_sql, " ", column_alias);
					}
				} else {
					PHALCON_CPY_WRT(column_alias_sql, column_domain_sql);
				}
			} else {
				PHALCON_CPY_WRT(column_alias_sql, column_domain_sql);
			}

			phalcon_array_append(&selected_columns, column_alias_sql, PH_SEPARATE);

			zend_hash_move_forward_ex(ah0, &hp0);
		}

		PHALCON_INIT_VAR(columns_sql);
		phalcon_fast_join_str(columns_sql, SL(", "), selected_columns TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(columns_sql, columns);
	}

	/**
	 * Check and escape tables
	 */
	PHALCON_OBS_VAR(tables);
	phalcon_array_fetch_string(&tables, definition, SL("tables"), PH_NOISY);
	if (Z_TYPE_P(tables) == IS_ARRAY) {

		PHALCON_INIT_VAR(selected_tables);
		array_init(selected_tables);

		phalcon_is_iterable(tables, &ah1, &hp1, 0, 0);

		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {

			PHALCON_GET_HVALUE(table);

			PHALCON_CALL_METHOD(&sql_table, this_ptr, "getsqltable", table, escape_char);
			phalcon_array_append(&selected_tables, sql_table, PH_SEPARATE);

			zend_hash_move_forward_ex(ah1, &hp1);
		}

		PHALCON_INIT_VAR(tables_sql);
		phalcon_fast_join_str(tables_sql, SL(", "), selected_tables TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(tables_sql, tables);
	}

	PHALCON_INIT_VAR(sql);
	if (phalcon_array_isset_string_fetch(&distinct, definition, SS("distinct"))) {
		assert(Z_TYPE_P(distinct) == IS_LONG);
		if (Z_LVAL_P(distinct) == 0) {
			ZVAL_STRING(sql, "SELECT ALL ", 1);
		}
		else if (Z_LVAL_P(distinct) == 1) {
			ZVAL_STRING(sql, "SELECT DISTINCT ", 1);
		}
		else {
			ZVAL_STRING(sql, "SELECT ", 1);
		}
	}
	else {
		ZVAL_STRING(sql, "SELECT ", 1);
	}

	PHALCON_SCONCAT_VSV(sql, columns_sql, " FROM ", tables_sql);

	/**
	 * Check for joins
	 */
	if (phalcon_array_isset_string(definition, SS("joins"))) {

		PHALCON_OBS_VAR(joins);
		phalcon_array_fetch_string(&joins, definition, SL("joins"), PH_NOISY);

		phalcon_is_iterable(joins, &ah2, &hp2, 0, 0);

		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {

			PHALCON_GET_HVALUE(join);

			PHALCON_OBS_NVAR(type);
			phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY);

			PHALCON_OBS_NVAR(table);
			phalcon_array_fetch_string(&table, join, SL("source"), PH_NOISY);

			PHALCON_CALL_METHOD(&sql_table, this_ptr, "getsqltable", table, escape_char);
			phalcon_array_append(&selected_tables, sql_table, PH_SEPARATE);

			PHALCON_INIT_NVAR(sql_join);
			PHALCON_CONCAT_SVSV(sql_join, " ", type, " JOIN ", sql_table);

			/**
			 * Check if the join has conditions
			 */
			if (phalcon_array_isset_string(join, SS("conditions"))) {

				PHALCON_OBS_NVAR(join_conditions_array);
				phalcon_array_fetch_string(&join_conditions_array, join, SL("conditions"), PH_NOISY);
				if (phalcon_fast_count_ev(join_conditions_array TSRMLS_CC)) {

					PHALCON_INIT_NVAR(join_expressions);
					array_init(join_expressions);

					phalcon_is_iterable(join_conditions_array, &ah3, &hp3, 0, 0);

					while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {

						PHALCON_GET_HVALUE(join_condition);

						PHALCON_CALL_METHOD(&join_expression, this_ptr, "getsqlexpression", join_condition, escape_char);
						phalcon_array_append(&join_expressions, join_expression, PH_SEPARATE);

						zend_hash_move_forward_ex(ah3, &hp3);
					}

					PHALCON_INIT_NVAR(join_conditions);
					phalcon_fast_join_str(join_conditions, SL(" AND "), join_expressions TSRMLS_CC);
					PHALCON_SCONCAT_SV(sql_join, " ON ", join_conditions);
				}
			}

			phalcon_concat_self(&sql, sql_join TSRMLS_CC);

			zend_hash_move_forward_ex(ah2, &hp2);
		}

	}

	/**
	 * Check for a WHERE clause
	 */
	if (phalcon_array_isset_string(definition, SS("where"))) {

		PHALCON_OBS_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, definition, SL("where"), PH_NOISY);
		if (Z_TYPE_P(where_conditions) == IS_ARRAY) {
			PHALCON_CALL_METHOD(&where_expression, this_ptr, "getsqlexpression", where_conditions, escape_char);
			PHALCON_SCONCAT_SV(sql, " WHERE ", where_expression);
		} else {
			PHALCON_SCONCAT_SV(sql, " WHERE ", where_conditions);
		}
	}

	/**
	 * Check for a GROUP clause
	 */
	if (phalcon_array_isset_string(definition, SS("group"))) {

		PHALCON_INIT_VAR(group_items);
		array_init(group_items);

		PHALCON_OBS_VAR(group_fields);
		phalcon_array_fetch_string(&group_fields, definition, SL("group"), PH_NOISY);

		phalcon_is_iterable(group_fields, &ah4, &hp4, 0, 0);

		while (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) == SUCCESS) {

			PHALCON_GET_HVALUE(group_field);

			PHALCON_CALL_METHOD(&group_expression, this_ptr, "getsqlexpression", group_field, escape_char);
			phalcon_array_append(&group_items, group_expression, PH_SEPARATE);

			zend_hash_move_forward_ex(ah4, &hp4);
		}

		PHALCON_INIT_VAR(group_sql);
		phalcon_fast_join_str(group_sql, SL(", "), group_items TSRMLS_CC);

		PHALCON_INIT_VAR(group_clause);
		PHALCON_CONCAT_SV(group_clause, " GROUP BY ", group_sql);
		phalcon_concat_self(&sql, group_clause TSRMLS_CC);
	}

	/**
	 * Check for a HAVING clause
	 */
	if (phalcon_array_isset_string(definition, SS("having"))) {
		PHALCON_OBS_VAR(having_conditions);
		phalcon_array_fetch_string(&having_conditions, definition, SL("having"), PH_NOISY);

		PHALCON_CALL_METHOD(&having_expression, this_ptr, "getsqlexpression", having_conditions, escape_char);
		PHALCON_SCONCAT_SV(sql, " HAVING ", having_expression);
	}

	/**
	 * Check for a ORDER clause
	 */
	if (phalcon_array_isset_string(definition, SS("order"))) {

		PHALCON_OBS_VAR(order_fields);
		phalcon_array_fetch_string(&order_fields, definition, SL("order"), PH_NOISY);

		PHALCON_INIT_VAR(order_items);
		array_init(order_items);

		phalcon_is_iterable(order_fields, &ah5, &hp5, 0, 0);

		while (zend_hash_get_current_data_ex(ah5, (void**) &hd, &hp5) == SUCCESS) {

			PHALCON_GET_HVALUE(order_item);

			PHALCON_OBS_NVAR(order_expression);
			phalcon_array_fetch_long(&order_expression, order_item, 0, PH_NOISY);

			PHALCON_CALL_METHOD(&order_sql_item, this_ptr, "getsqlexpression", order_expression, escape_char);

			/**
			 * In the numeric 1 position could be a ASC/DESC clause
			 */
			if (phalcon_array_isset_long(order_item, 1)) {
				PHALCON_OBS_NVAR(sql_order_type);
				phalcon_array_fetch_long(&sql_order_type, order_item, 1, PH_NOISY);

				PHALCON_INIT_NVAR(order_sql_item_type);
				PHALCON_CONCAT_VSV(order_sql_item_type, order_sql_item, " ", sql_order_type);
			} else {
				PHALCON_CPY_WRT(order_sql_item_type, order_sql_item);
			}

			phalcon_array_append(&order_items, order_sql_item_type, PH_SEPARATE);

			zend_hash_move_forward_ex(ah5, &hp5);
		}

		PHALCON_INIT_VAR(order_sql);
		phalcon_fast_join_str(order_sql, SL(", "), order_items TSRMLS_CC);
		PHALCON_SCONCAT_SV(sql, " ORDER BY ", order_sql);
	}

    /**
	 * Oracle does not implement the LIMIT clause as some RDBMS do.
	 * We have to simulate it with subqueries and ROWNUM.
	 * Unfortunately because we use the column wildcard "*",
	 * this puts an extra column into the query result set.
	 */
	if (phalcon_array_isset_string_fetch(&limit_value, definition, SS("limit"))) {
		if (likely(Z_TYPE_P(limit_value) == IS_ARRAY)) {
			if (likely(phalcon_array_isset_string_fetch(&number, limit_value, SS("number")))) {
				PHALCON_OBS_NVAR(tmp1);
				phalcon_array_fetch_string(&tmp1, number, SL("value"), PH_NOISY);

				if (phalcon_array_isset_string_fetch(&offset, limit_value, SS("offset"))) {
					PHALCON_OBS_NVAR(tmp2);
					phalcon_array_fetch_string(&tmp2, offset, SL("value"), PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(tmp2);
					ZVAL_LONG(tmp2, 0);
				}

				z_one = PHALCON_GLOBAL(z_one);

				PHALCON_INIT_VAR(ini_range);
				phalcon_add_function(ini_range, tmp2, z_one TSRMLS_CC);

				PHALCON_INIT_VAR(end_range);
				phalcon_add_function(end_range, tmp2, tmp1 TSRMLS_CC);

				PHALCON_INIT_VAR(sql_limit);
				PHALCON_SCONCAT_SVSVSV(sql_limit,"SELECT Z2.* FROM (SELECT Z1.*, ROWNUM DB_ROWNUM FROM ( ", sql, " ) Z1 ) Z2 WHERE Z2.DB_ROWNUM BETWEEN ", ini_range , " AND ",  end_range );
				PHALCON_CPY_WRT(sql, sql_limit);
			}
		} else {

			PHALCON_INIT_VAR(ini_range);
			ZVAL_LONG(ini_range, 1);

			PHALCON_CPY_WRT(end_range, limit_value);

			PHALCON_INIT_VAR(sql_limit);
			PHALCON_SCONCAT_SVSVSV(sql_limit,"SELECT Z2.* FROM (SELECT Z1.*, ROWNUM DB_ROWNUM FROM ( ", sql, " ) Z1 ) Z2 WHERE Z2.DB_ROWNUM BETWEEN ", ini_range , " AND ",  end_range );
			PHALCON_CPY_WRT(sql, sql_limit);
		}
	}

	RETURN_CTOR(sql);
}

/**
 * Checks whether the platform supports savepoints
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsSavepoints){


	RETURN_FALSE;
}

/**
 * Checks whether the platform supports releasing savepoints.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsReleaseSavepoints){


	RETURN_FALSE;
}

