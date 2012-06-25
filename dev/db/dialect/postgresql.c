
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

#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"
/**
 * Phalcon_Db_Dialect_Postgresql
 *
 * Generates database specific SQL for the PostgreSQL RBDM
 */

/**
 * Generates the SQL for a PostgreSQL LIMIT clause
 *
 * @param string $sqlQuery
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, limit){

	zval *sql_query = NULL, *number = NULL, *limit = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", number);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(limit);
		PHALCON_CALL_FUNC_PARAMS_1(limit, "intval", number);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_VSV(r1, sql_query, " LIMIT ", limit);
		
		RETURN_CTOR(r1);
	} else {
		
		RETURN_CHECK_CTOR(sql_query);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnList){

	zval *column_list = NULL, *str_list = NULL, *column = NULL;
	zval *a0 = NULL;
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

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(str_list, a0);
	if (phalcon_valid_foreach(column_list TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(column_list);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_46b6_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_46b6_0;
		}
		
		PHALCON_INIT_VAR(column);
		ZVAL_ZVAL(column, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CONCAT_SVS(r0, "\"", column, "\"");
		phalcon_array_append(&str_list, r0, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_46b6_0;
		fee_46b6_0:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ", ", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_join(r1, c0, column_list TSRMLS_CC);
	RETURN_DZVAL(r1);
}

/**
 * Gets the column name in PostgreSQL
 *
 * @param Phalcon_Db_Column $column
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition){

	zval *column = NULL, *size = NULL, *column_sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an instance of Phalcon_Db_Column");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, column, "getsize", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(size, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, column, "gettype", PHALCON_NO_CHECK);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, r1, t0 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "INT", 1);
		goto se_46b6_1;
	}
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, r1, t1 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "DATE", 1);
		goto se_46b6_1;
	}
	
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 2);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, r1, t2 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_SVS(r5, "CHARACTER VARYING(", size, ")");
		PHALCON_CPY_WRT(column_sql, r5);
		goto se_46b6_1;
	}
	
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 3);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, r1, t3 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CALL_METHOD(r8, column, "getscale", PHALCON_NO_CHECK);
		PHALCON_CONCAT_SVSVS(r7, "NUMERIC(", size, ",", r8, ")");
		PHALCON_CPY_WRT(column_sql, r7);
		goto se_46b6_1;
	}
	
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 4);
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	is_equal_function(r9, r1, t4 TSRMLS_CC);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "TIMESTAMP", 1);
		goto se_46b6_1;
	}
	
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 5);
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	is_equal_function(r10, r1, t5 TSRMLS_CC);
	if (zend_is_true(r10)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_SVS(r11, "CHARACTER(", size, ")");
		PHALCON_CPY_WRT(column_sql, r11);
		goto se_46b6_1;
	}
	
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 6);
	
	PHALCON_ALLOC_ZVAL_MM(r12);
	is_equal_function(r12, r1, t6 TSRMLS_CC);
	if (zend_is_true(r12)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "TEXT", 1);
		goto se_46b6_1;
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized PostgreSQL data type");
	return;
	se_46b6_1:
	
	RETURN_CTOR(column_sql);
}

/**
 * Generates SQL to add a column to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Column $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn){

	zval *table_name = NULL, *schema_name = NULL, *column = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column parameter must be an instance of Phalcon_Db_Column");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` ADD ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, column, "getname", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getcolumndefinition", column);
	PHALCON_CONCAT_SVSV(r2, "`", r3, "` ", r4);
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, column, "isnotnull", PHALCON_NO_CHECK);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, " NOT NULL", 1);
		phalcon_concat_self(&sql, t0 TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to modify a column in a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Column $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn){

	zval *table_name = NULL, *schema_name = NULL, *column = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column parameter must be an instance of Phalcon_Db_Column");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` MODIFY ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` MODIFY ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, column, "getname", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getcolumndefinition", column);
	PHALCON_CONCAT_SVSV(r2, "`", r3, "` ", r4);
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, column, "isnotnull", PHALCON_NO_CHECK);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, " NOT NULL", 1);
		phalcon_concat_self(&sql, t0 TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to delete a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn){

	zval *table_name = NULL, *schema_name = NULL, *column_name = NULL;
	zval *sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` DROP COLUMN ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` DROP COLUMN ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_SVS(r2, "`", column_name, "`");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Index $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex){

	zval *table_name = NULL, *schema_name = NULL, *index = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(index) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an instance of Phalcon_Db_Index");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE ", schema_name, ".", table_name, " ADD INDEX ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE ", table_name, " ADD INDEX ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, index, "getname", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, index, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getcolumnlist", r5);
	PHALCON_CONCAT_SVSVS(r2, "\"", r3, "\" (", r4, ")");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex){

	zval *table_name = NULL, *schema_name = NULL, *index_name = NULL;
	zval *sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE ", schema_name, ".", table_name, " DROP INDEX ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE ", table_name, " DROP INDEX ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_SVS(r2, "\"", index_name, "\"");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to add the primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Index $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey){

	zval *table_name = NULL, *schema_name = NULL, *index = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(index) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an instance of Phalcon_Db_Index");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE ", schema_name, ".", table_name, " ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE ", table_name, " ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, index, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r3, this_ptr, "getcolumnlist", r4);
	PHALCON_CONCAT_SVS(r2, "(", r3, ")");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey){

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE ", schema_name, ".", table_name, " DROP PRIMARY KEY");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE ", table_name, " DROP PRIMARY KEY");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Reference $reference
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey){

	zval *table_name = NULL, *schema_name = NULL, *reference = NULL, *sql = NULL;
	zval *referenced_schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(reference) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Reference parameter must be an instance of Phalcon_Db_Reference");
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE ", schema_name, ".", table_name, " ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE ", table_name, " ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, reference, "getname", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, reference, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getcolumnlist", r5);
	PHALCON_CONCAT_SVSVS(r2, "\"", r3, "\"(", r4, ") REFERENCES ");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, reference, "getreferencedschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(referenced_schema, r6);
	if (zend_is_true(referenced_schema)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_SVS(r7, "", referenced_schema, ".");
		phalcon_concat_self(&sql, r7 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, reference, "getreferencedtable", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, reference, "getreferencedcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r10, this_ptr, "getcolumnlist", r11);
	PHALCON_CONCAT_SVSVS(r8, "", r9, "(", r10, ")");
	phalcon_concat_self(&sql, r8 TSRMLS_CC);
	
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey){

	zval *table_name = NULL, *schema_name = NULL, *reference_name = NULL;
	zval *sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE ", schema_name, ".", table_name, " DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE ", table_name, " DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_SVS(r2, "\"", reference_name, "\"");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	RETURN_CTOR(sql);
}

/**
 * Generates SQL to add the table creation options
 *
 * @param array $definition
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _getTableOptions){

	zval *definition = NULL, *table_options = NULL, *engine = NULL, *auto_increment = NULL;
	zval *table_collation = NULL, *collation_parts = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(table_options, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r0, SL("ENGINE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, r1, SL("ENGINE"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(engine, r2);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, r3, SL("ENGINE"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r4)) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_SV(r5, "ENGINE=", engine);
			phalcon_array_append(&table_options, r5, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_array_fetch_string(&r6, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r6, SL("AUTO_INCREMENT")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, r7, SL("AUTO_INCREMENT"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(auto_increment, r8);
		if (zend_is_true(auto_increment)) {
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_SV(r9, "AUTO_INCREMENT=", auto_increment);
			phalcon_array_append(&table_options, r9, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	phalcon_array_fetch_string(&r10, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r10, SL("TABLE_COLLATION")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, r11, SL("TABLE_COLLATION"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(table_collation, r12);
		if (zend_is_true(table_collation)) {
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "_", 1);
			PHALCON_ALLOC_ZVAL_MM(r13);
			phalcon_fast_explode(r13, c0, table_collation TSRMLS_CC);
			PHALCON_CPY_WRT(collation_parts, r13);
			
			PHALCON_ALLOC_ZVAL_MM(r14);
			
			PHALCON_ALLOC_ZVAL_MM(r15);
			phalcon_array_fetch_long(&r15, collation_parts, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CONCAT_SV(r14, "DEFAULT CHARSET=", r15);
			phalcon_array_append(&table_options, r14, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_SV(r16, "COLLATE=", table_collation);
			phalcon_array_append(&table_options, r16, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r17);
	phalcon_fast_count(r17, table_options TSRMLS_CC);
	if (zend_is_true(r17)) {
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, " ", 1);
		PHALCON_ALLOC_ZVAL_MM(r18);
		phalcon_fast_join(r18, c1, table_options TSRMLS_CC);
		RETURN_DZVAL(r18);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Generates SQL to create a table in PostgreSQL
 *
 * @param string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable){

	zval *table_name = NULL, *schema_name = NULL, *definition = NULL;
	zval *table = NULL, *temporary = NULL, *sql = NULL, *create_lines = NULL, *column = NULL;
	zval *column_line = NULL, *index = NULL, *index_name = NULL, *column_list = NULL;
	zval *reference = NULL, *reference_sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *c0 = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VSV(r0, schema_name, ".", table_name);
		PHALCON_CPY_WRT(table, r0);
	} else {
		PHALCON_CPY_WRT(table, table_name);
	}
	
	PHALCON_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	eval_int = phalcon_array_isset_string(definition, SL("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset_string(r1, SL("temporary")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_string(&r2, definition, SL("options"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, r2, SL("temporary"), PHALCON_NOISY TSRMLS_CC);
			if (zend_is_true(r3)) {
				PHALCON_INIT_VAR(temporary);
				ZVAL_BOOL(temporary, 1);
			}
		}
	}
	
	if (zend_is_true(temporary)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_SVS(r4, "CREATE TEMPORARY TABLE ", table, " (\n\t");
		PHALCON_CPY_WRT(sql, r4);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_SVS(r5, "CREATE TABLE ", table, " (\n\t");
		PHALCON_CPY_WRT(sql, r5);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(create_lines, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_array_fetch_string(&r6, definition, SL("columns"), PHALCON_NOISY TSRMLS_CC);
	if (phalcon_valid_foreach(r6 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(r6);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_46b6_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_46b6_2;
		}
		
		PHALCON_INIT_VAR(column);
		ZVAL_ZVAL(column, *hd, 1, 0);
		PHALCON_INIT_VAR(r7);
		PHALCON_INIT_VAR(r8);
		PHALCON_CALL_METHOD(r8, column, "getname", PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(r9);
		PHALCON_CALL_SELF_PARAMS_1(r9, this_ptr, "getcolumndefinition", column);
		PHALCON_CONCAT_SVSV(r7, "`", r8, "` ", r9);
		PHALCON_CPY_WRT(column_line, r7);
		
		PHALCON_INIT_VAR(r10);
		PHALCON_CALL_METHOD(r10, column, "isnotnull", PHALCON_NO_CHECK);
		if (zend_is_true(r10)) {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, " NOT NULL", 1);
			phalcon_concat_self(&column_line, t0 TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(r11);
		PHALCON_CALL_METHOD(r11, column, "isautoincrement", PHALCON_NO_CHECK);
		if (zend_is_true(r11)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " AUTO_INCREMENT", 1);
			phalcon_concat_self(&column_line, t1 TSRMLS_CC);
		}
		
		phalcon_array_append(&create_lines, column_line, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_46b6_2;
		fee_46b6_2:
		if(0){}
	} else {
		return;
	}
	eval_int = phalcon_array_isset_string(definition, SL("indexes")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, definition, SL("indexes"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(r12 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(r12);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_46b6_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_46b6_3;
			}
			PHALCON_INIT_VAR(index);
			ZVAL_ZVAL(index, *hd, 1, 0);
			PHALCON_INIT_VAR(r13);
			PHALCON_CALL_METHOD(r13, index, "getname", PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(index_name, r13);
			
			PHALCON_INIT_VAR(r14);
			
			PHALCON_INIT_VAR(r15);
			PHALCON_CALL_METHOD(r15, index, "getcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r14, this_ptr, "getcolumnlist", r15);
			PHALCON_CPY_WRT(column_list, r14);
			if (PHALCON_COMPARE_STRING(index_name, "PRIMARY")) {
				PHALCON_INIT_VAR(r16);
				PHALCON_CONCAT_SVS(r16, "PRIMARY KEY (", column_list, ")");
				phalcon_array_append(&create_lines, r16, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r17);
				PHALCON_CONCAT_SVSVS(r17, "KEY `", index_name, "` (", column_list, ")");
				phalcon_array_append(&create_lines, r17, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_46b6_3;
			fee_46b6_3:
			if(0){}
		} else {
			return;
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("references")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		phalcon_array_fetch_string(&r18, definition, SL("references"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(r18 TSRMLS_CC)) {
			ah2 = Z_ARRVAL_P(r18);
			zend_hash_internal_pointer_reset_ex(ah2, &hp2);
			fes_46b6_4:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee_46b6_4;
			}
			PHALCON_INIT_VAR(reference);
			ZVAL_ZVAL(reference, *hd, 1, 0);
			PHALCON_INIT_VAR(r19);
			PHALCON_INIT_VAR(r20);
			PHALCON_CALL_METHOD(r20, reference, "getname", PHALCON_NO_CHECK);
			PHALCON_INIT_VAR(r21);
			PHALCON_INIT_VAR(r22);
			PHALCON_CALL_METHOD(r22, reference, "getcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r21, this_ptr, "getcolumnlist", r22);
			PHALCON_CONCAT_SVSV(r19, "CONSTRAINT `", r20, "` FOREIGN KEY (", r21);
			PHALCON_CPY_WRT(reference_sql, r19);
			
			PHALCON_INIT_VAR(r23);
			
			PHALCON_INIT_VAR(r24);
			PHALCON_CALL_METHOD(r24, reference, "getreferencedtable", PHALCON_NO_CHECK);
			
			PHALCON_INIT_VAR(r25);
			
			PHALCON_INIT_VAR(r26);
			PHALCON_CALL_METHOD(r26, reference, "getreferencedcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r25, this_ptr, "getcolumnlist", r26);
			PHALCON_CONCAT_SVSVS(r23, ") REFERENCES `", r24, "`(", r25, ")");
			phalcon_concat_self(&reference_sql, r23 TSRMLS_CC);
			phalcon_array_append(&create_lines, reference_sql, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah2, &hp2);
			goto fes_46b6_4;
			fee_46b6_4:
			if(0){}
		} else {
			return;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r27);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ",\n\t", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r28);
	phalcon_fast_join(r28, c0, create_lines TSRMLS_CC);
	PHALCON_CONCAT_VS(r27, r28, "\n)");
	phalcon_concat_self(&sql, r27 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(definition, SL("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r29);
		PHALCON_ALLOC_ZVAL_MM(r30);
		PHALCON_CALL_SELF_PARAMS_1(r30, this_ptr, "_gettableoptions", definition);
		PHALCON_CONCAT_SV(r29, " ", r30);
		phalcon_concat_self(&sql, r29 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable){

	zval *table_name = NULL, *schema_name = NULL, *if_exists = NULL, *table = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &table_name, &schema_name, &if_exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!if_exists) {
		PHALCON_INIT_VAR(if_exists);
		ZVAL_BOOL(if_exists, 1);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VSV(r0, schema_name, ".", table_name);
		PHALCON_CPY_WRT(table, r0);
	} else {
		PHALCON_CPY_WRT(table, table_name);
	}
	if (zend_is_true(if_exists)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SV(r1, "DROP TABLE IF EXISTS ", table);
		
		RETURN_CTOR(r1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SV(r2, "DROP TABLE ", table);
		
		RETURN_CTOR(r2);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * 
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists){

	zval *table_name = NULL, *schema_name = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = '", schema_name, "' AND table_name='", table_name, "'");
		
		RETURN_CTOR(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = 'public' AND table_name='", table_name, "'");
		
		RETURN_CTOR(r1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Generates a SQL describing a table
 *
 * 
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeTable){

	zval *table = NULL, *schema = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SVSVS(r0, "SELECT a.attname AS Field, format_type(a.atttypid, a.atttypmod) AS Type, CASE WHEN attnotnull=false THEN 'YES' ELSE 'NO' END AS Null, CASE WHEN (select cc.contype FROM pg_catalog.pg_constraint cc WHERE cc.conrelid = c.oid AND cc.conkey[1] = a.attnum)='p' THEN 'PRI' ELSE '' END AS Key, CASE WHEN t.typname LIKE '%int%' AND (SELECT column_default FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name = '", table, "' AND column_name = a.attname) LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra FROM pg_catalog.pg_Class c, pg_catalog.pg_attribute a, pg_catalog.pg_type t WHERE c.relname = '", table, "' AND c.oid = a.attrelid AND a.attnum > 0 AND c.relhaspkey = 't' AND t.oid = a.atttypid ORDER BY a.attnum");
	
	RETURN_CTOR(r0);
}

/**
 * List all tables on database
 *
 * 
 *
 * @param       string $schemaName
 * @return      array
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables){

	zval *schema_name = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_STRING("SELECT c.relname AS table_name FROM pg_Class c, pg_user u WHERE c.relowner = u.usesysid AND c.relkind = 'r' AND NOT EXISTS (SELECT 1 FROM pg_views WHERE viewname = c.relname) AND c.relname !~ '^(pg_|sql_)' UNION SELECT c.relname AS table_name FROM pg_Class c WHERE c.relkind = 'r' AND NOT EXISTS (SELECT 1 FROM pg_views WHERE viewname = c.relname)  AND NOT EXISTS (SELECT 1 FROM pg_user WHERE usesysid = c.relowner)  AND c.relname !~ '^pg_' ORDER BY 1", 1);
}

/**
 * Generates SQL to query indexes on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes){

	zval *table = NULL, *schema = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
		ZVAL_NULL(schema);
	}
	
	if (zend_is_true(schema)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "SHOW INDEXES FROM `", schema, "`.`", table, "`");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "SHOW INDEXES FROM `", table, "`");
		PHALCON_CPY_WRT(sql, r1);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences){

	zval *table = NULL, *schema = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME\n\t\t\tFROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);
	if (zend_is_true(schema)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "CONSTRAINT_SCHEMA = \"", schema, "\" AND TABLE_NAME = \"", table, "\"");
		phalcon_concat_self(&sql, r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "TABLE_NAME = \"", table, "\"");
		phalcon_concat_self(&sql, r1 TSRMLS_CC);
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

	zval *table = NULL, *schema = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLES.TABLE_TYPE,TABLES.AUTO_INCREMENT,TABLES.ENGINE,TABLES.TABLE_COLLATION FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);
	if (zend_is_true(schema)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "TABLES.TABLE_SCHEMA = \"", schema, "\" AND TABLES.TABLE_NAME = \"", table, "\"");
		phalcon_concat_self(&sql, r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "TABLES.TABLE_NAME = \"", table, "\"");
		phalcon_concat_self(&sql, r1 TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql);
}

