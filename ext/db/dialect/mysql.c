
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
#include "kernel/string.h"
#include "kernel/file.h"

/**
 * Phalcon\Db\Dialect\Mysql
 *
 * Generates database specific SQL for the MySQL RBDM
 */


/**
 * Phalcon\Db\Dialect\Mysql initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Mysql){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Mysql, db_dialect_mysql, "phalcon\\db\\dialect", phalcon_db_dialect_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_mysql_ce, SL("_escapeChar"), "`", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_dialect_mysql_ce TSRMLS_CC, 1, phalcon_db_dialectinterface_ce);

	return SUCCESS;
}

/**
 * Gets the column name in MySQL
 *
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition){

	zval *column, *size, *column_type, *column_sql = NULL;
	zval *is_unsigned = NULL, *scale = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	
	PHALCON_INIT_VAR(size);
	PHALCON_CALL_METHOD(size, column, "getsize");
	
	PHALCON_INIT_VAR(column_type);
	PHALCON_CALL_METHOD(column_type, column, "gettype");
	
	switch (phalcon_get_intval(column_type)) {
	
		case 0:
			PHALCON_INIT_VAR(column_sql);
			PHALCON_CONCAT_SVS(column_sql, "INT(", size, ")");
	
			PHALCON_INIT_VAR(is_unsigned);
			PHALCON_CALL_METHOD(is_unsigned, column, "isunsigned");
			if (zend_is_true(is_unsigned)) {
				phalcon_concat_self_str(&column_sql, SL(" UNSIGNED") TSRMLS_CC);
			}
	
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
			PHALCON_CALL_METHOD(scale, column, "getscale");
	
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVSVS(column_sql, "DECIMAL(", size, ",", scale, ")");
	
			PHALCON_INIT_NVAR(is_unsigned);
			PHALCON_CALL_METHOD(is_unsigned, column, "isunsigned");
			if (zend_is_true(is_unsigned)) {
				phalcon_concat_self_str(&column_sql, SL(" UNSIGNED") TSRMLS_CC);
			}
	
			break;
	
		case 4:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "DATETIME", 1);
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
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "FLOAT", 1);
	
			PHALCON_INIT_NVAR(scale);
			PHALCON_CALL_METHOD(scale, column, "getscale");
			if (zend_is_true(size)) {
				PHALCON_SCONCAT_SV(column_sql, "(", size);
				if (zend_is_true(scale)) {
					PHALCON_SCONCAT_SVS(column_sql, ",", scale, ")");
				} else {
					phalcon_concat_self_str(&column_sql, SL(")") TSRMLS_CC);
				}
			}
	
			PHALCON_INIT_NVAR(is_unsigned);
			PHALCON_CALL_METHOD(is_unsigned, column, "isunsigned");
			if (zend_is_true(is_unsigned)) {
				phalcon_concat_self_str(&column_sql, SL(" UNSIGNED") TSRMLS_CC);
			}
	
			break;
	
		default:
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized MySQL data type");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn){

	zval *table_name, *schema_name, *column, *sql = NULL, *name;
	zval *column_definition, *is_not_null, *is_first;
	zval *after_position;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column parameter must be an instance of Phalcon\\Db\\Column");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` ADD ");
	}
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD(name, column, "getname");
	
	PHALCON_INIT_VAR(column_definition);
	PHALCON_CALL_METHOD_PARAMS_1(column_definition, this_ptr, "getcolumndefinition", column);
	PHALCON_SCONCAT_SVSV(sql, "`", name, "` ", column_definition);
	
	PHALCON_INIT_VAR(is_not_null);
	PHALCON_CALL_METHOD(is_not_null, column, "isnotnull");
	if (zend_is_true(is_not_null)) {
		phalcon_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(is_first);
	PHALCON_CALL_METHOD(is_first, column, "isfirst");
	if (zend_is_true(is_first)) {
		phalcon_concat_self_str(&sql, SL(" FIRST") TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(after_position);
		PHALCON_CALL_METHOD(after_position, column, "getafterposition");
		if (zend_is_true(after_position)) {
			PHALCON_SCONCAT_SV(sql, " AFTER ", after_position);
		}
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn){

	zval *table_name, *schema_name, *column, *sql = NULL, *name;
	zval *column_definition, *is_not_null;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column parameter must be an instance of Phalcon\\Db\\Column");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` MODIFY ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` MODIFY ");
	}
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD(name, column, "getname");
	
	PHALCON_INIT_VAR(column_definition);
	PHALCON_CALL_METHOD_PARAMS_1(column_definition, this_ptr, "getcolumndefinition", column);
	PHALCON_SCONCAT_SVSV(sql, "`", name, "` ", column_definition);
	
	PHALCON_INIT_VAR(is_not_null);
	PHALCON_CALL_METHOD(is_not_null, column, "isnotnull");
	if (zend_is_true(is_not_null)) {
		phalcon_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to delete a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropColumn){

	zval *table_name, *schema_name, *column_name;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` DROP COLUMN ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` DROP COLUMN ");
	}
	PHALCON_SCONCAT_SVS(sql, "`", column_name, "`");
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex){

	zval *table_name, *schema_name, *index, *sql = NULL, *columns;
	zval *quoted_column_list, *name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(index) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an instance of Phalcon\\Db\\Index");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD INDEX ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` ADD INDEX ");
	}
	
	PHALCON_INIT_VAR(columns);
	PHALCON_CALL_METHOD(columns, index, "getcolumns");
	
	PHALCON_INIT_VAR(quoted_column_list);
	PHALCON_CALL_METHOD_PARAMS_1(quoted_column_list, this_ptr, "getcolumnlist", columns);
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD(name, index, "getname");
	PHALCON_SCONCAT_SVSVS(sql, "`", name, "` (", quoted_column_list, ")");
	
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropIndex){

	zval *table_name, *schema_name, *index_name;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` DROP INDEX ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` DROP INDEX ");
	}
	PHALCON_SCONCAT_SVS(sql, "`", index_name, "`");
	
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey){

	zval *table_name, *schema_name, *index, *sql = NULL, *columns;
	zval *column_list;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(index) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an instance of Phalcon\\Db\\Index");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD PRIMARY KEY ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` ADD PRIMARY KEY ");
	}
	
	PHALCON_INIT_VAR(columns);
	PHALCON_CALL_METHOD(columns, index, "getcolumns");
	
	PHALCON_INIT_VAR(column_list);
	PHALCON_CALL_METHOD_PARAMS_1(column_list, this_ptr, "getcolumnlist", columns);
	PHALCON_SCONCAT_SVS(sql, "(", column_list, ")");
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey){

	zval *table_name, *schema_name, *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &table_name, &schema_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` DROP PRIMARY KEY");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` DROP PRIMARY KEY");
	}
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ReferenceInterface $reference
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey){

	zval *table_name, *schema_name, *reference, *sql = NULL;
	zval *columns, *quoted_column_list, *reference_name;
	zval *referenced_schema, *referenced_columns;
	zval *quoted_columns, *referenced_table;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(reference) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Reference parameter must be an instance of Phalcon\\Db\\Reference");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD FOREIGN KEY ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` ADD FOREIGN KEY ");
	}
	
	PHALCON_INIT_VAR(columns);
	PHALCON_CALL_METHOD(columns, reference, "getcolumns");
	
	PHALCON_INIT_VAR(quoted_column_list);
	PHALCON_CALL_METHOD_PARAMS_1(quoted_column_list, this_ptr, "getcolumnlist", columns);
	
	PHALCON_INIT_VAR(reference_name);
	PHALCON_CALL_METHOD(reference_name, reference, "getname");
	PHALCON_SCONCAT_SVSVS(sql, "`", reference_name, "`(", quoted_column_list, ") REFERENCES ");
	
	PHALCON_INIT_VAR(referenced_schema);
	PHALCON_CALL_METHOD(referenced_schema, reference, "getreferencedschema");
	if (zend_is_true(referenced_schema)) {
		PHALCON_SCONCAT_SVS(sql, "`", referenced_schema, "`.");
	}
	
	PHALCON_INIT_VAR(referenced_columns);
	PHALCON_CALL_METHOD(referenced_columns, reference, "getreferencedcolumns");
	
	PHALCON_INIT_VAR(quoted_columns);
	PHALCON_CALL_METHOD_PARAMS_1(quoted_columns, this_ptr, "getcolumnlist", referenced_columns);
	
	PHALCON_INIT_VAR(referenced_table);
	PHALCON_CALL_METHOD(referenced_table, reference, "getreferencedtable");
	PHALCON_SCONCAT_SVSVS(sql, "`", referenced_table, "`(", quoted_columns, ")");
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to delete a foreign key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $referenceName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropForeignKey){

	zval *table_name, *schema_name, *reference_name;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` DROP FOREIGN KEY ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` DROP FOREIGN KEY ");
	}
	PHALCON_SCONCAT_SVS(sql, "`", reference_name, "`");
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to add the table creation options
 *
 * @param array $definition
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, _getTableOptions){

	zval *definition, *table_options, *options, *engine;
	zval *sql_engine, *auto_increment, *sql_autoincrement;
	zval *table_collation, *under_score, *collation_parts;
	zval *first_part, *sql_charset, *sql_collate;
	zval *sql_table_options;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (phalcon_array_isset_string(definition, SS("options"))) {
	
		PHALCON_INIT_VAR(table_options);
		array_init(table_options);
	
		PHALCON_OBS_VAR(options);
		phalcon_array_fetch_string(&options, definition, SL("options"), PH_NOISY_CC);
	
		/** 
		 * Check if there is an ENGINE option
		 */
		if (phalcon_array_isset_string(options, SS("ENGINE"))) {
	
			PHALCON_OBS_VAR(engine);
			phalcon_array_fetch_string(&engine, options, SL("ENGINE"), PH_NOISY_CC);
			if (zend_is_true(engine)) {
				PHALCON_INIT_VAR(sql_engine);
				PHALCON_CONCAT_SV(sql_engine, "ENGINE=", engine);
				phalcon_array_append(&table_options, sql_engine, PH_SEPARATE TSRMLS_CC);
			}
		}
	
		/** 
		 * Check if there is an AUTO_INCREMENT option
		 */
		if (phalcon_array_isset_string(options, SS("AUTO_INCREMENT"))) {
	
			PHALCON_OBS_VAR(auto_increment);
			phalcon_array_fetch_string(&auto_increment, options, SL("AUTO_INCREMENT"), PH_NOISY_CC);
			if (zend_is_true(auto_increment)) {
				PHALCON_INIT_VAR(sql_autoincrement);
				PHALCON_CONCAT_SV(sql_autoincrement, "AUTO_INCREMENT=", auto_increment);
				phalcon_array_append(&table_options, sql_autoincrement, PH_SEPARATE TSRMLS_CC);
			}
		}
	
		/** 
		 * Check if there is a TABLE_COLLATION option
		 */
		if (phalcon_array_isset_string(options, SS("TABLE_COLLATION"))) {
	
			PHALCON_OBS_VAR(table_collation);
			phalcon_array_fetch_string(&table_collation, options, SL("TABLE_COLLATION"), PH_NOISY_CC);
			if (zend_is_true(table_collation)) {
				PHALCON_INIT_VAR(under_score);
				ZVAL_STRING(under_score, "_", 1);
	
				PHALCON_INIT_VAR(collation_parts);
				phalcon_fast_explode(collation_parts, under_score, table_collation TSRMLS_CC);
	
				PHALCON_OBS_VAR(first_part);
				phalcon_array_fetch_long(&first_part, collation_parts, 0, PH_NOISY_CC);
	
				PHALCON_INIT_VAR(sql_charset);
				PHALCON_CONCAT_SV(sql_charset, "DEFAULT CHARSET=", first_part);
				phalcon_array_append(&table_options, sql_charset, PH_SEPARATE TSRMLS_CC);
	
				PHALCON_INIT_VAR(sql_collate);
				PHALCON_CONCAT_SV(sql_collate, "COLLATE=", table_collation);
				phalcon_array_append(&table_options, sql_collate, PH_SEPARATE TSRMLS_CC);
			}
		}
	
		if (phalcon_fast_count_ev(table_options TSRMLS_CC)) {
			PHALCON_INIT_VAR(sql_table_options);
			phalcon_fast_join_str(sql_table_options, SL(" "), table_options TSRMLS_CC);
			RETURN_CTOR(sql_table_options);
		}
	}
	RETURN_MM_NULL();
}

/**
 * Generates SQL to create a table in MySQL
 *
 * @param 	string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable){

	zval *table_name, *schema_name, *definition;
	zval *table = NULL, *temporary = NULL, *options = NULL, *sql = NULL, *create_lines;
	zval *columns = NULL, *column = NULL, *column_name = NULL, *column_definition = NULL;
	zval *column_line = NULL, *attribute = NULL, *indexes, *index = NULL;
	zval *index_name = NULL, *column_list = NULL, *index_sql = NULL, *references;
	zval *reference = NULL, *name = NULL, *referenced_table = NULL, *referenced_columns = NULL;
	zval *constaint_sql = NULL, *reference_sql = NULL, *joined_lines;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &definition) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!phalcon_array_isset_string(definition, SS("columns"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_SVSVS(table, "`", schema_name, "`.`", table_name, "`");
	} else {
		PHALCON_INIT_NVAR(table);
		PHALCON_CONCAT_SVS(table, "`", table_name, "`");
	}
	
	PHALCON_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	if (phalcon_array_isset_string(definition, SS("options"))) {
	
		PHALCON_OBS_VAR(options);
		phalcon_array_fetch_string(&options, definition, SL("options"), PH_NOISY_CC);
		if (phalcon_array_isset_string(options, SS("temporary"))) {
			PHALCON_OBS_NVAR(temporary);
			phalcon_array_fetch_string(&temporary, options, SL("temporary"), PH_NOISY_CC);
		}
	}
	
	/** 
	 * Create a temporary o normal table
	 */
	if (zend_is_true(temporary)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVS(sql, "CREATE TEMPORARY TABLE ", table, " (\n\t");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "CREATE TABLE ", table, " (\n\t");
	}
	
	PHALCON_INIT_VAR(create_lines);
	array_init(create_lines);
	
	PHALCON_OBS_VAR(columns);
	phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(columns);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(column);
	
		PHALCON_INIT_NVAR(column_name);
		PHALCON_CALL_METHOD(column_name, column, "getname");
	
		PHALCON_INIT_NVAR(column_definition);
		PHALCON_CALL_METHOD_PARAMS_1(column_definition, this_ptr, "getcolumndefinition", column);
	
		PHALCON_INIT_NVAR(column_line);
		PHALCON_CONCAT_SVSV(column_line, "`", column_name, "` ", column_definition);
	
		/** 
		 * Add a NOT NULL clause
		 */
		PHALCON_INIT_NVAR(attribute);
		PHALCON_CALL_METHOD(attribute, column, "isnotnull");
		if (zend_is_true(attribute)) {
			phalcon_concat_self_str(&column_line, SL(" NOT NULL") TSRMLS_CC);
		}
	
		/** 
		 * Add an AUTO_INCREMENT clause
		 */
		PHALCON_INIT_NVAR(attribute);
		PHALCON_CALL_METHOD(attribute, column, "isautoincrement");
		if (zend_is_true(attribute)) {
			phalcon_concat_self_str(&column_line, SL(" AUTO_INCREMENT") TSRMLS_CC);
		}
	
		phalcon_array_append(&create_lines, column_line, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Create related indexes
	 */
	if (phalcon_array_isset_string(definition, SS("indexes"))) {
	
		PHALCON_OBS_VAR(indexes);
		phalcon_array_fetch_string(&indexes, definition, SL("indexes"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(indexes TSRMLS_CC)) {
			return;
		}
	
		ah1 = Z_ARRVAL_P(indexes);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(index);
	
			PHALCON_INIT_NVAR(index_name);
			PHALCON_CALL_METHOD(index_name, index, "getname");
	
			PHALCON_INIT_NVAR(columns);
			PHALCON_CALL_METHOD(columns, index, "getcolumns");
	
			PHALCON_INIT_NVAR(column_list);
			PHALCON_CALL_METHOD_PARAMS_1(column_list, this_ptr, "getcolumnlist", columns);
			if (PHALCON_COMPARE_STRING(index_name, "PRIMARY")) {
				PHALCON_INIT_NVAR(index_sql);
				PHALCON_CONCAT_SVS(index_sql, "PRIMARY KEY (", column_list, ")");
			} else {
				PHALCON_INIT_NVAR(index_sql);
				PHALCON_CONCAT_SVSVS(index_sql, "KEY `", index_name, "` (", column_list, ")");
			}
	
			phalcon_array_append(&create_lines, index_sql, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	}
	
	/** 
	 * Create related references
	 */
	if (phalcon_array_isset_string(definition, SS("references"))) {
	
		PHALCON_OBS_VAR(references);
		phalcon_array_fetch_string(&references, definition, SL("references"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(references TSRMLS_CC)) {
			return;
		}
	
		ah2 = Z_ARRVAL_P(references);
		zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(reference);
	
			PHALCON_INIT_NVAR(name);
			PHALCON_CALL_METHOD(name, reference, "getname");
	
			PHALCON_INIT_NVAR(columns);
			PHALCON_CALL_METHOD(columns, reference, "getcolumns");
	
			PHALCON_INIT_NVAR(column_list);
			PHALCON_CALL_METHOD_PARAMS_1(column_list, this_ptr, "getcolumnlist", columns);
	
			PHALCON_INIT_NVAR(referenced_table);
			PHALCON_CALL_METHOD(referenced_table, reference, "getreferencedtable");
	
			PHALCON_INIT_NVAR(referenced_columns);
			PHALCON_CALL_METHOD(referenced_columns, reference, "getreferencedcolumns");
	
			PHALCON_INIT_NVAR(column_list);
			PHALCON_CALL_METHOD_PARAMS_1(column_list, this_ptr, "getcolumnlist", referenced_columns);
	
			PHALCON_INIT_NVAR(constaint_sql);
			PHALCON_CONCAT_SVSVS(constaint_sql, "CONSTRAINT `", name, "` FOREIGN KEY (", column_list, ")");
	
			PHALCON_INIT_NVAR(reference_sql);
			PHALCON_CONCAT_VSVSVS(reference_sql, constaint_sql, " REFERENCES `", referenced_table, "`(", column_list, ")");
			phalcon_array_append(&create_lines, reference_sql, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
	}
	
	PHALCON_INIT_VAR(joined_lines);
	phalcon_fast_join_str(joined_lines, SL(",\n\t"), create_lines TSRMLS_CC);
	PHALCON_SCONCAT_VS(sql, joined_lines, "\n)");
	if (phalcon_array_isset_string(definition, SS("options"))) {
		PHALCON_INIT_NVAR(options);
		PHALCON_CALL_METHOD_PARAMS_1(options, this_ptr, "_gettableoptions", definition);
		PHALCON_SCONCAT_SV(sql, " ", options);
	}
	
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to drop a table
 *
 * @param  string $tableName
 * @param  string $schemaName
 * @param  boolean $ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropTable){

	zval *table_name, *schema_name, *if_exists = NULL, *table = NULL;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &table_name, &schema_name, &if_exists) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!if_exists) {
		PHALCON_INIT_VAR(if_exists);
		ZVAL_BOOL(if_exists, 1);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_SVSVS(table, "`", schema_name, "`.`", table_name, "`");
	} else {
		PHALCON_INIT_NVAR(table);
		PHALCON_CONCAT_SVS(table, "`", table_name, "`");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists){

	zval *table_name, *schema_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", table_name, "' AND `TABLE_SCHEMA`='", schema_name, "'");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", table_name, "'");
	}
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL describing a table
 *
 * <code>
 *	print_r($dialect->describeColumns("posts")) ?>
 *</code>
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeColumns){

	zval *table, *schema = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "DESCRIBE `", schema, "`.`", table, "`");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "DESCRIBE `", table, "`");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listTables){

	zval *schema_name = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &schema_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVS(sql, "SHOW TABLES FROM `", schema_name, "`");
	} else {
		PHALCON_INIT_NVAR(sql);
		ZVAL_STRING(sql, "SHOW TABLES", 1);
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes){

	zval *table, *schema = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "SHOW INDEXES FROM `", schema, "`.`", table, "`");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "SHOW INDEXES FROM `", table, "`");
	}
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences){

	zval *table, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);
	if (zend_is_true(schema)) {
		PHALCON_SCONCAT_SVSVS(sql, "CONSTRAINT_SCHEMA = \"", schema, "\" AND TABLE_NAME = \"", table, "\"");
	} else {
		PHALCON_SCONCAT_SVS(sql, "TABLE_NAME = \"", table, "\"");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions){

	zval *table, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLES.TABLE_TYPE,TABLES.AUTO_INCREMENT,TABLES.ENGINE,TABLES.TABLE_COLLATION FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);
	if (zend_is_true(schema)) {
		PHALCON_SCONCAT_SVSVS(sql, "TABLES.TABLE_SCHEMA = \"", schema, "\" AND TABLES.TABLE_NAME = \"", table, "\"");
	} else {
		PHALCON_SCONCAT_SVS(sql, "TABLES.TABLE_NAME = \"", table, "\"");
	}
	
	
	RETURN_CTOR(sql);
}

