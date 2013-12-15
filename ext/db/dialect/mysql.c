
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Mysql, db_dialect_mysql, phalcon_db_dialect_ce, phalcon_db_dialect_mysql_method_entry, 0);

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
			PHALCON_CONCAT_SVS(column_sql, "INT(", size, ")");
	
			PHALCON_INIT_VAR(is_unsigned);
			phalcon_call_method(is_unsigned, column, "isunsigned");
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
			phalcon_call_method(scale, column, "getscale");
	
			PHALCON_INIT_NVAR(column_sql);
			PHALCON_CONCAT_SVSVS(column_sql, "DECIMAL(", size, ",", scale, ")");
	
			PHALCON_INIT_NVAR(is_unsigned);
			phalcon_call_method(is_unsigned, column, "isunsigned");
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
			phalcon_call_method(scale, column, "getscale");
			if (zend_is_true(size)) {
				PHALCON_SCONCAT_SV(column_sql, "(", size);
				if (zend_is_true(scale)) {
					PHALCON_SCONCAT_SVS(column_sql, ",", scale, ")");
				} else {
					phalcon_concat_self_str(&column_sql, SL(")") TSRMLS_CC);
				}
			}
	
			PHALCON_INIT_NVAR(is_unsigned);
			phalcon_call_method(is_unsigned, column, "isunsigned");
			if (zend_is_true(is_unsigned)) {
				phalcon_concat_self_str(&column_sql, SL(" UNSIGNED") TSRMLS_CC);
			}
	
			break;
	
		case 8:
			PHALCON_INIT_NVAR(column_sql);
			ZVAL_STRING(column_sql, "TINYINT(1)", 1);
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
 * @see http://dev.mysql.com/doc/refman/5.5/en/example-auto-increment.html
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn){

	zval *table_name, *schema_name, *column, *sql = NULL, *name;
	zval *column_definition, *is_not_null, *is_autoincrement, *is_first;
	zval *after_position;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &column);
	
	PHALCON_VERIFY_INTERFACE_EX(column, phalcon_db_columninterface_ce, phalcon_db_exception_ce, 1);

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` ADD ");
	}
	
	PHALCON_INIT_VAR(name);
	phalcon_call_method(name, column, "getname");
	
	PHALCON_INIT_VAR(column_definition);
	phalcon_call_method_p1(column_definition, this_ptr, "getcolumndefinition", column);
	PHALCON_SCONCAT_SVSV(sql, "`", name, "` ", column_definition);
	
	PHALCON_INIT_VAR(is_not_null);
	phalcon_call_method(is_not_null, column, "isnotnull");
	if (zend_is_true(is_not_null)) {
		phalcon_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(is_autoincrement);
	phalcon_call_method(is_autoincrement, column, "isautoincrement");
	/*
	 * In MySQL the AUTO_INCREMENT column has to be a part of the PRIMARY KEY
	 * This is why we explicitly create PRIMARY KEY here, otherwise ALTER TABLE will fail.
	 */
	if (zend_is_true(is_autoincrement)) {
		phalcon_concat_self_str(&sql, SL(" PRIMARY KEY AUTO_INCREMENT") TSRMLS_CC);
	}

	PHALCON_INIT_VAR(is_first);
	phalcon_call_method(is_first, column, "isfirst");
	if (zend_is_true(is_first)) {
		phalcon_concat_self_str(&sql, SL(" FIRST") TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(after_position);
		phalcon_call_method(after_position, column, "getafterposition");
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
	zval *column_definition, *is_not_null, *is_autoincrement;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &column);
	
	PHALCON_VERIFY_INTERFACE_EX(column, phalcon_db_columninterface_ce, phalcon_db_exception_ce, 1);

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` MODIFY ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` MODIFY ");
	}
	
	PHALCON_INIT_VAR(name);
	phalcon_call_method(name, column, "getname");
	
	PHALCON_INIT_VAR(column_definition);
	phalcon_call_method_p1(column_definition, this_ptr, "getcolumndefinition", column);
	PHALCON_SCONCAT_SVSV(sql, "`", name, "` ", column_definition);
	
	PHALCON_INIT_VAR(is_not_null);
	phalcon_call_method(is_not_null, column, "isnotnull");
	if (zend_is_true(is_not_null)) {
		phalcon_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(is_autoincrement);
	phalcon_call_method(is_autoincrement, column, "isautoincrement");
	if (zend_is_true(is_autoincrement)) {
		phalcon_concat_self_str(&sql, SL(" AUTO_INCREMENT") TSRMLS_CC);
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

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &column_name);
	
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

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &index);
	
	PHALCON_VERIFY_INTERFACE_EX(index, phalcon_db_indexinterface_ce, phalcon_db_exception_ce, 1);

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD INDEX ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` ADD INDEX ");
	}
	
	PHALCON_INIT_VAR(columns);
	phalcon_call_method(columns, index, "getcolumns");
	
	PHALCON_INIT_VAR(quoted_column_list);
	phalcon_call_method_p1(quoted_column_list, this_ptr, "getcolumnlist", columns);
	
	PHALCON_INIT_VAR(name);
	phalcon_call_method(name, index, "getname");
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

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &index_name);
	
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

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &index);
	
	PHALCON_VERIFY_INTERFACE_EX(index, phalcon_db_indexinterface_ce, phalcon_db_exception_ce, 1);

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD PRIMARY KEY ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` ADD PRIMARY KEY ");
	}
	
	PHALCON_INIT_VAR(columns);
	phalcon_call_method(columns, index, "getcolumns");
	
	PHALCON_INIT_VAR(column_list);
	phalcon_call_method_p1(column_list, this_ptr, "getcolumnlist", columns);
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

	phalcon_fetch_params(1, 2, 0, &table_name, &schema_name);
	
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

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &reference);
	
	PHALCON_VERIFY_INTERFACE_EX(reference, phalcon_db_referenceinterface_ce, phalcon_db_exception_ce, 1);

	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSVS(sql, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD FOREIGN KEY ");
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SVS(sql, "ALTER TABLE `", table_name, "` ADD FOREIGN KEY ");
	}
	
	PHALCON_INIT_VAR(columns);
	phalcon_call_method(columns, reference, "getcolumns");
	
	PHALCON_INIT_VAR(quoted_column_list);
	phalcon_call_method_p1(quoted_column_list, this_ptr, "getcolumnlist", columns);
	
	PHALCON_INIT_VAR(reference_name);
	phalcon_call_method(reference_name, reference, "getname");
	PHALCON_SCONCAT_SVSVS(sql, "`", reference_name, "`(", quoted_column_list, ") REFERENCES ");
	
	/** 
	 * Add the schema
	 */
	PHALCON_INIT_VAR(referenced_schema);
	phalcon_call_method(referenced_schema, reference, "getreferencedschema");
	if (zend_is_true(referenced_schema)) {
		PHALCON_SCONCAT_SVS(sql, "`", referenced_schema, "`.");
	}
	
	PHALCON_INIT_VAR(referenced_columns);
	phalcon_call_method(referenced_columns, reference, "getreferencedcolumns");
	
	PHALCON_INIT_VAR(quoted_columns);
	phalcon_call_method_p1(quoted_columns, this_ptr, "getcolumnlist", referenced_columns);
	
	PHALCON_INIT_VAR(referenced_table);
	phalcon_call_method(referenced_table, reference, "getreferencedtable");
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

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &reference_name);
	
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
	zval *table_collation, *collation_parts, *first_part;
	zval *sql_charset, *sql_collate, *sql_table_options;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &definition);
	
	if (phalcon_array_isset_string(definition, SS("options"))) {
	
		PHALCON_INIT_VAR(table_options);
		array_init(table_options);
	
		PHALCON_OBS_VAR(options);
		phalcon_array_fetch_string(&options, definition, SL("options"), PH_NOISY);
	
		/** 
		 * Check if there is an ENGINE option
		 */
		if (phalcon_array_isset_string(options, SS("ENGINE"))) {
	
			PHALCON_OBS_VAR(engine);
			phalcon_array_fetch_string(&engine, options, SL("ENGINE"), PH_NOISY);
			if (zend_is_true(engine)) {
				PHALCON_INIT_VAR(sql_engine);
				PHALCON_CONCAT_SV(sql_engine, "ENGINE=", engine);
				phalcon_array_append(&table_options, sql_engine, PH_SEPARATE);
			}
		}
	
		/** 
		 * Check if there is an AUTO_INCREMENT option
		 */
		if (phalcon_array_isset_string(options, SS("AUTO_INCREMENT"))) {
	
			PHALCON_OBS_VAR(auto_increment);
			phalcon_array_fetch_string(&auto_increment, options, SL("AUTO_INCREMENT"), PH_NOISY);
			if (zend_is_true(auto_increment)) {
				PHALCON_INIT_VAR(sql_autoincrement);
				PHALCON_CONCAT_SV(sql_autoincrement, "AUTO_INCREMENT=", auto_increment);
				phalcon_array_append(&table_options, sql_autoincrement, PH_SEPARATE);
			}
		}
	
		/** 
		 * Check if there is a TABLE_COLLATION option
		 */
		if (phalcon_array_isset_string(options, SS("TABLE_COLLATION"))) {
	
			PHALCON_OBS_VAR(table_collation);
			phalcon_array_fetch_string(&table_collation, options, SL("TABLE_COLLATION"), PH_NOISY);
			if (zend_is_true(table_collation)) {
				PHALCON_INIT_VAR(collation_parts);
				phalcon_fast_explode_str(collation_parts, SL("_"), table_collation);
	
				PHALCON_OBS_VAR(first_part);
				phalcon_array_fetch_long(&first_part, collation_parts, 0, PH_NOISY);
	
				PHALCON_INIT_VAR(sql_charset);
				PHALCON_CONCAT_SV(sql_charset, "DEFAULT CHARSET=", first_part);
				phalcon_array_append(&table_options, sql_charset, PH_SEPARATE);
	
				PHALCON_INIT_VAR(sql_collate);
				PHALCON_CONCAT_SV(sql_collate, "COLLATE=", table_collation);
				phalcon_array_append(&table_options, sql_collate, PH_SEPARATE);
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

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &definition);
	
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
		phalcon_array_fetch_string(&options, definition, SL("options"), PH_NOISY);
		phalcon_array_isset_string_fetch(&temporary, options, SS("temporary"));
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
	phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY);
	
	phalcon_is_iterable(columns, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(column);
	
		PHALCON_INIT_NVAR(column_name);
		phalcon_call_method(column_name, column, "getname");
	
		PHALCON_INIT_NVAR(column_definition);
		phalcon_call_method_p1(column_definition, this_ptr, "getcolumndefinition", column);
	
		PHALCON_INIT_NVAR(column_line);
		PHALCON_CONCAT_SVSV(column_line, "`", column_name, "` ", column_definition);
	
		/** 
		 * Add a NOT NULL clause
		 */
		PHALCON_INIT_NVAR(attribute);
		phalcon_call_method(attribute, column, "isnotnull");
		if (zend_is_true(attribute)) {
			phalcon_concat_self_str(&column_line, SL(" NOT NULL") TSRMLS_CC);
		}
	
		/** 
		 * Add an AUTO_INCREMENT clause
		 */
		PHALCON_INIT_NVAR(attribute);
		phalcon_call_method(attribute, column, "isautoincrement");
		if (zend_is_true(attribute)) {
			phalcon_concat_self_str(&column_line, SL(" AUTO_INCREMENT") TSRMLS_CC);
		}
	
		/** 
		 * Mark the column as primary key
		 */
		PHALCON_INIT_NVAR(attribute);
		phalcon_call_method(attribute, column, "isprimary");
		if (zend_is_true(attribute)) {
			phalcon_concat_self_str(&column_line, SL(" PRIMARY KEY") TSRMLS_CC);
		}
	
		phalcon_array_append(&create_lines, column_line, PH_SEPARATE);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Create related indexes
	 */
	if (phalcon_array_isset_string(definition, SS("indexes"))) {
	
		PHALCON_OBS_VAR(indexes);
		phalcon_array_fetch_string(&indexes, definition, SL("indexes"), PH_NOISY);
	
		phalcon_is_iterable(indexes, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(index);
	
			PHALCON_INIT_NVAR(index_name);
			phalcon_call_method(index_name, index, "getname");
	
			PHALCON_INIT_NVAR(columns);
			phalcon_call_method(columns, index, "getcolumns");
	
			PHALCON_INIT_NVAR(column_list);
			phalcon_call_method_p1(column_list, this_ptr, "getcolumnlist", columns);
	
			/** 
			 * If the index name is primary we add a primary key
			 */
			if (PHALCON_IS_STRING(index_name, "PRIMARY")) {
				PHALCON_INIT_NVAR(index_sql);
				PHALCON_CONCAT_SVS(index_sql, "PRIMARY KEY (", column_list, ")");
			} else {
				PHALCON_INIT_NVAR(index_sql);
				PHALCON_CONCAT_SVSVS(index_sql, "KEY `", index_name, "` (", column_list, ")");
			}
	
			phalcon_array_append(&create_lines, index_sql, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	}
	
	/** 
	 * Create related references
	 */
	if (phalcon_array_isset_string(definition, SS("references"))) {
	
		PHALCON_OBS_VAR(references);
		phalcon_array_fetch_string(&references, definition, SL("references"), PH_NOISY);
	
		phalcon_is_iterable(references, &ah2, &hp2, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_HVALUE(reference);
	
			PHALCON_INIT_NVAR(name);
			phalcon_call_method(name, reference, "getname");
	
			PHALCON_INIT_NVAR(columns);
			phalcon_call_method(columns, reference, "getcolumns");
	
			PHALCON_INIT_NVAR(column_list);
			phalcon_call_method_p1(column_list, this_ptr, "getcolumnlist", columns);
	
			PHALCON_INIT_NVAR(referenced_table);
			phalcon_call_method(referenced_table, reference, "getreferencedtable");
	
			PHALCON_INIT_NVAR(referenced_columns);
			phalcon_call_method(referenced_columns, reference, "getreferencedcolumns");
	
			PHALCON_INIT_NVAR(column_list);
			phalcon_call_method_p1(column_list, this_ptr, "getcolumnlist", referenced_columns);
	
			PHALCON_INIT_NVAR(constaint_sql);
			PHALCON_CONCAT_SVSVS(constaint_sql, "CONSTRAINT `", name, "` FOREIGN KEY (", column_list, ")");
	
			PHALCON_INIT_NVAR(reference_sql);
			PHALCON_CONCAT_VSVSVS(reference_sql, constaint_sql, " REFERENCES `", referenced_table, "`(", column_list, ")");
			phalcon_array_append(&create_lines, reference_sql, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
	}
	
	PHALCON_INIT_VAR(joined_lines);
	phalcon_fast_join_str(joined_lines, SL(",\n\t"), create_lines TSRMLS_CC);
	PHALCON_SCONCAT_VS(sql, joined_lines, "\n)");
	if (phalcon_array_isset_string(definition, SS("options"))) {
		PHALCON_INIT_NVAR(options);
		phalcon_call_method_p1(options, this_ptr, "_gettableoptions", definition);
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
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropTable){

	zval *table_name, *schema_name, *if_exists = NULL, *table = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &table_name, &schema_name, &if_exists);
	
	if (!if_exists) {
		if_exists = PHALCON_GLOBAL(z_true);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_SVSVS(table, "`", schema_name, "`.`", table_name, "`");
	} else {
		PHALCON_INIT_NVAR(table);
		PHALCON_CONCAT_SVS(table, "`", table_name, "`");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createView){

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
		PHALCON_CONCAT_SVSVS(view, "`", schema_name, "`.`", view_name, "`");
	} else {
		PHALCON_INIT_NVAR(view);
		PHALCON_CONCAT_SVS(view, "`", view_name, "`");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropView){

	zval *view_name, *schema_name, *if_exists = NULL, *view = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &view_name, &schema_name, &if_exists);
	
	if (!if_exists) {
		if_exists = PHALCON_GLOBAL(z_true);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_INIT_VAR(view);
		PHALCON_CONCAT_VSV(view, schema_name, ".", view_name);
	} else {
		view = view_name;
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
 * <code>
 * echo $dialect->tableExists("posts", "blog");
 * echo $dialect->tableExists("posts");
 * </code>
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists){

	zval *table_name, *schema_name = NULL;

	phalcon_fetch_params(0, 1, 1, &table_name, &schema_name);
	
	if (schema_name && zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", table_name, "' AND `TABLE_SCHEMA`='", schema_name, "'");
	}
	else {
		PHALCON_CONCAT_SVS(return_value, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", table_name, "'");
	}
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, viewExists){

	zval *view_name, *schema_name = NULL;

	phalcon_fetch_params(0, 1, 1, &view_name, &schema_name);
	
	if (schema_name && zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '", view_name, "' AND `TABLE_SCHEMA`='", schema_name, "'");
	}
	else {
		PHALCON_CONCAT_SVS(return_value, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='", view_name, "'");
	}
}

/**
 * Generates SQL describing a table
 *
 *<code>
 *	print_r($dialect->describeColumns("posts")) ?>
 *</code>
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeColumns){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);
	
	if (schema && zend_is_true(schema)) {
		PHALCON_CONCAT_SVSVS(return_value, "DESCRIBE `", schema, "`.`", table, "`");
	}
	else {
		PHALCON_CONCAT_SVS(return_value, "DESCRIBE `", table, "`");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listTables){

	zval *schema_name = NULL;

	phalcon_fetch_params(0, 0, 1, &schema_name);
	
	if (schema_name && zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVS(return_value, "SHOW TABLES FROM `", schema_name, "`");
	}
	else {
		RETURN_STRING("SHOW TABLES", 1);
	}
}

/**
 * Generates the SQL to list all views of a schema or user
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listViews){

	zval *schema_name = NULL;

	phalcon_fetch_params(0, 0, 1, &schema_name);
	
	if (schema_name && zend_is_true(schema_name)) {
		PHALCON_CONCAT_SVS(return_value, "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '", schema_name, "' ORDER BY view_name");
	}
	else {
		RETURN_STRING("SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` ORDER BY view_name", 1);
	}
}

/**
 * Generates SQL to query indexes on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes){

	zval *table, *schema = NULL;

	phalcon_fetch_params(0, 1, 1, &table, &schema);
	
	if (schema && zend_is_true(schema)) {
		PHALCON_CONCAT_SVSVS(return_value, "SHOW INDEXES FROM `", schema, "`.`", table, "`");
	}
	else {
		PHALCON_CONCAT_SVS(return_value, "SHOW INDEXES FROM `", table, "`");
	}
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

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);
	if (schema && zend_is_true(schema)) {
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

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);
	if (schema && zend_is_true(schema)) {
		PHALCON_SCONCAT_SVSVS(sql, "TABLES.TABLE_SCHEMA = \"", schema, "\" AND TABLES.TABLE_NAME = \"", table, "\"");
	} else {
		PHALCON_SCONCAT_SVS(sql, "TABLES.TABLE_NAME = \"", table, "\"");
	}
	
	RETURN_CTOR(sql);
}

