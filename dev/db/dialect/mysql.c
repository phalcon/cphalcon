
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Db_Dialect_Mysql
 *
 * Generates database specific SQL for the MySQL RBDM
 */

/**
 * Generates the SQL for a MySQL LIMIT clause
 *
 * @param string $errorString
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, limit){

	zval *sql_query = NULL, *number = NULL, *limit = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", number, 0x02B);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "intval", number, 0x020);
		PHALCON_CPY_WRT(limit, r1);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VSV(r2, sql_query, " LIMIT ", limit);
		
		PHALCON_RETURN_CTOR(r2);
	} else {
		
		PHALCON_RETURN_CHECK_CTOR(sql_query);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnList){

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
		fes_52be_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_52be_0;
		}
		
		PHALCON_INIT_VAR(column);
		ZVAL_ZVAL(column, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CONCAT_SVS(r0, "`", column, "`");
		phalcon_array_append(&str_list, r0, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_52be_0;
		fee_52be_0:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ", ", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_join(r1, c0, str_list TSRMLS_CC);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Gets the column name in MySQL
 *
 * @param Phalcon_Db_Column $column
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition){

	zval *column = NULL, *size = NULL, *column_sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;

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
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_SVS(r3, "INT(", size, ")");
		PHALCON_CPY_WRT(column_sql, r3);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, column, "isunsigned", PHALCON_NO_CHECK);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " UNSIGNED", 1);
			phalcon_concat_self(&column_sql, t1 TSRMLS_CC);
		}
		
		goto se_52be_1;
	}
	
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	is_equal_function(r5, r1, t2 TSRMLS_CC);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "DATE", 1);
		goto se_52be_1;
	}
	
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 2);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, r1, t3 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_SVS(r7, "VARCHAR(", size, ")");
		PHALCON_CPY_WRT(column_sql, r7);
		goto se_52be_1;
	}
	
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 3);
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	is_equal_function(r8, r1, t4 TSRMLS_CC);
	if (zend_is_true(r8)) {
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CALL_METHOD(r10, column, "getscale", PHALCON_NO_CHECK);
		PHALCON_CONCAT_SVSVS(r9, "DECIMAL(", size, ",", r10, ")");
		PHALCON_CPY_WRT(column_sql, r9);
		
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_METHOD(r11, column, "isunsigned", PHALCON_NO_CHECK);
		if (zend_is_true(r11)) {
			PHALCON_INIT_VAR(t5);
			ZVAL_STRING(t5, " UNSIGNED", 1);
			phalcon_concat_self(&column_sql, t5 TSRMLS_CC);
		}
		
		goto se_52be_1;
	}
	
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 4);
	
	PHALCON_ALLOC_ZVAL_MM(r12);
	is_equal_function(r12, r1, t6 TSRMLS_CC);
	if (zend_is_true(r12)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "DATETIME", 1);
		goto se_52be_1;
	}
	
	PHALCON_INIT_VAR(t7);
	ZVAL_LONG(t7, 5);
	
	PHALCON_ALLOC_ZVAL_MM(r13);
	is_equal_function(r13, r1, t7 TSRMLS_CC);
	if (zend_is_true(r13)) {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_SVS(r14, "CHAR(", size, ")");
		PHALCON_CPY_WRT(column_sql, r14);
		goto se_52be_1;
	}
	
	PHALCON_INIT_VAR(t8);
	ZVAL_LONG(t8, 6);
	
	PHALCON_ALLOC_ZVAL_MM(r15);
	is_equal_function(r15, r1, t8 TSRMLS_CC);
	if (zend_is_true(r15)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "TEXT", 1);
		goto se_52be_1;
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized MySQL data type");
	return;
	se_52be_1:
	
	PHALCON_RETURN_CTOR(column_sql);
}

/**
 * Generates SQL to add a column to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Column $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn){

	zval *table_name = NULL, *schema_name = NULL, *column = NULL, *sql = NULL, *after_position = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL;

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
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, column, "isfirst", PHALCON_NO_CHECK);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, " FIRST", 1);
		phalcon_concat_self(&sql, t1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CALL_METHOD(r7, column, "getafterposition", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(after_position, r7);
		if (zend_is_true(after_position)) {
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CONCAT_SV(r8, " AFTER ", after_position);
			phalcon_concat_self(&sql, r8 TSRMLS_CC);
		}
	}
	
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates SQL to modify a column in a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Column $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn){

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
	
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates SQL to delete a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropColumn){

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
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Index $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex){

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
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD INDEX ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` ADD INDEX ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, index, "getname", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, index, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getcolumnlist", r5);
	PHALCON_CONCAT_SVSVS(r2, "`", r3, "` (", r4, ")");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(sql);
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
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` DROP INDEX ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` DROP INDEX ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_SVS(r2, "`", index_name, "`");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates SQL to add the primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Index $index
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey){

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
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, index, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r3, this_ptr, "getcolumnlist", r4);
	PHALCON_CONCAT_SVS(r2, "(", r3, ")");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey){

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` DROP PRIMARY KEY");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` DROP PRIMARY KEY");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Reference $reference
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey){

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
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, reference, "getname", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, reference, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getcolumnlist", r5);
	PHALCON_CONCAT_SVSVS(r2, "`", r3, "`(", r4, ") REFERENCES ");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, reference, "getreferencedschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(referenced_schema, r6);
	if (zend_is_true(referenced_schema)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_SVS(r7, "`", referenced_schema, "`.");
		phalcon_concat_self(&sql, r7 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, reference, "getreferencedtable", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, reference, "getreferencedcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r10, this_ptr, "getcolumnlist", r11);
	PHALCON_CONCAT_SVSVS(r8, "`", r9, "`(", r10, ")");
	phalcon_concat_self(&sql, r8 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(sql);
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
		PHALCON_CONCAT_SVSVS(r0, "ALTER TABLE `", schema_name, "`.`", table_name, "` DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "ALTER TABLE `", table_name, "` DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_SVS(r2, "`", reference_name, "`");
	phalcon_concat_self(&sql, r2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(sql);
}

PHP_METHOD(Phalcon_Db_Dialect_Mysql, _getTableOptions){

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
	phalcon_array_fetch_string(&r0, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r0, "ENGINE", strlen("ENGINE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, r1, "ENGINE", strlen("ENGINE"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(engine, r2);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, r3, "ENGINE", strlen("ENGINE"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r4)) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_SV(r5, "ENGINE=", engine);
			phalcon_array_append(&table_options, r5, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_array_fetch_string(&r6, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r6, "AUTO_INCREMENT", strlen("AUTO_INCREMENT")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, r7, "AUTO_INCREMENT", strlen("AUTO_INCREMENT"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(auto_increment, r8);
		if (zend_is_true(auto_increment)) {
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_SV(r9, "AUTO_INCREMENT=", auto_increment);
			phalcon_array_append(&table_options, r9, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	phalcon_array_fetch_string(&r10, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r10, "TABLE_COLLATION", strlen("TABLE_COLLATION")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, r11, "TABLE_COLLATION", strlen("TABLE_COLLATION"), PHALCON_NOISY TSRMLS_CC);
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
		PHALCON_RETURN_DZVAL(r18);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Generates SQL to create a table in MySQL
 *
 * @param string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable){

	zval *table_name = NULL, *schema_name = NULL, *definition = NULL;
	zval *table = NULL, *temporary = NULL, *sql = NULL, *create_lines = NULL, *column = NULL;
	zval *column_line = NULL, *index = NULL, *index_name = NULL, *column_list = NULL;
	zval *reference = NULL, *reference_sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL;
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
		PHALCON_CONCAT_SVSVS(r0, "`", schema_name, "`.`", table_name, "`");
		PHALCON_CPY_WRT(table, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "`", table_name, "`");
		PHALCON_CPY_WRT(table, r1);
	}
	
	PHALCON_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	eval_int = phalcon_array_isset_string(definition, "options", strlen("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset_string(r2, "temporary", strlen("temporary")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_string(&r4, r3, "temporary", strlen("temporary"), PHALCON_NOISY TSRMLS_CC);
			if (zend_is_true(r4)) {
				PHALCON_INIT_VAR(temporary);
				ZVAL_BOOL(temporary, 1);
			}
		}
	}
	
	if (zend_is_true(temporary)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_SVS(r5, "CREATE TEMPORARY TABLE ", table, " (\n\t");
		PHALCON_CPY_WRT(sql, r5);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_SVS(r6, "CREATE TABLE ", table, " (\n\t");
		PHALCON_CPY_WRT(sql, r6);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(create_lines, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	phalcon_array_fetch_string(&r7, definition, "columns", strlen("columns"), PHALCON_NOISY TSRMLS_CC);
	if (phalcon_valid_foreach(r7 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(r7);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_52be_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_52be_2;
		}
		
		PHALCON_INIT_VAR(column);
		ZVAL_ZVAL(column, *hd, 1, 0);
		PHALCON_INIT_VAR(r8);
		PHALCON_INIT_VAR(r9);
		PHALCON_CALL_METHOD(r9, column, "getname", PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(r10);
		PHALCON_CALL_SELF_PARAMS_1(r10, this_ptr, "getcolumndefinition", column);
		PHALCON_CONCAT_SVSV(r8, "`", r9, "` ", r10);
		PHALCON_CPY_WRT(column_line, r8);
		
		PHALCON_INIT_VAR(r11);
		PHALCON_CALL_METHOD(r11, column, "isnotnull", PHALCON_NO_CHECK);
		if (zend_is_true(r11)) {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, " NOT NULL", 1);
			phalcon_concat_self(&column_line, t0 TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(r12);
		PHALCON_CALL_METHOD(r12, column, "isautoincrement", PHALCON_NO_CHECK);
		if (zend_is_true(r12)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " AUTO_INCREMENT", 1);
			phalcon_concat_self(&column_line, t1 TSRMLS_CC);
		}
		
		phalcon_array_append(&create_lines, column_line, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_52be_2;
		fee_52be_2:
		if(0){}
	} else {
		return;
	}
	eval_int = phalcon_array_isset_string(definition, "indexes", strlen("indexes")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r13);
		phalcon_array_fetch_string(&r13, definition, "indexes", strlen("indexes"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(r13 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(r13);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_52be_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_52be_3;
			}
			PHALCON_INIT_VAR(index);
			ZVAL_ZVAL(index, *hd, 1, 0);
			PHALCON_INIT_VAR(r14);
			PHALCON_CALL_METHOD(r14, index, "getname", PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(index_name, r14);
			
			PHALCON_INIT_VAR(r15);
			
			PHALCON_INIT_VAR(r16);
			PHALCON_CALL_METHOD(r16, index, "getcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r15, this_ptr, "getcolumnlist", r16);
			PHALCON_CPY_WRT(column_list, r15);
			if (PHALCON_COMPARE_STRING(index_name, "PRIMARY")) {
				PHALCON_INIT_VAR(r17);
				PHALCON_CONCAT_SVS(r17, "PRIMARY KEY (", column_list, ")");
				phalcon_array_append(&create_lines, r17, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r18);
				PHALCON_CONCAT_SVSVS(r18, "KEY `", index_name, "` (", column_list, ")");
				phalcon_array_append(&create_lines, r18, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_52be_3;
			fee_52be_3:
			if(0){}
		} else {
			return;
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, "references", strlen("references")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r19);
		phalcon_array_fetch_string(&r19, definition, "references", strlen("references"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(r19 TSRMLS_CC)) {
			ah2 = Z_ARRVAL_P(r19);
			zend_hash_internal_pointer_reset_ex(ah2, &hp2);
			fes_52be_4:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee_52be_4;
			}
			PHALCON_INIT_VAR(reference);
			ZVAL_ZVAL(reference, *hd, 1, 0);
			PHALCON_INIT_VAR(r20);
			PHALCON_INIT_VAR(r21);
			PHALCON_CALL_METHOD(r21, reference, "getname", PHALCON_NO_CHECK);
			PHALCON_INIT_VAR(r22);
			PHALCON_INIT_VAR(r23);
			PHALCON_CALL_METHOD(r23, reference, "getcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r22, this_ptr, "getcolumnlist", r23);
			PHALCON_CONCAT_SVSV(r20, "CONSTRAINT `", r21, "` FOREIGN KEY (", r22);
			PHALCON_CPY_WRT(reference_sql, r20);
			
			PHALCON_INIT_VAR(r24);
			
			PHALCON_INIT_VAR(r25);
			PHALCON_CALL_METHOD(r25, reference, "getreferencedtable", PHALCON_NO_CHECK);
			
			PHALCON_INIT_VAR(r26);
			
			PHALCON_INIT_VAR(r27);
			PHALCON_CALL_METHOD(r27, reference, "getreferencedcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r26, this_ptr, "getcolumnlist", r27);
			PHALCON_CONCAT_SVSVS(r24, ") REFERENCES `", r25, "`(", r26, ")");
			phalcon_concat_self(&reference_sql, r24 TSRMLS_CC);
			phalcon_array_append(&create_lines, reference_sql, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah2, &hp2);
			goto fes_52be_4;
			fee_52be_4:
			if(0){}
		} else {
			return;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r28);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ",\n\t", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r29);
	phalcon_fast_join(r29, c0, create_lines TSRMLS_CC);
	PHALCON_CONCAT_VS(r28, r29, "\n)");
	phalcon_concat_self(&sql, r28 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(definition, "options", strlen("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r30);
		PHALCON_ALLOC_ZVAL_MM(r31);
		PHALCON_CALL_SELF_PARAMS_1(r31, this_ptr, "_gettableoptions", definition);
		PHALCON_CONCAT_SV(r30, " ", r31);
		phalcon_concat_self(&sql, r30 TSRMLS_CC);
	}
	
	
	PHALCON_RETURN_CTOR(sql);
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

	zval *table_name = NULL, *schema_name = NULL, *if_exists = NULL, *table = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

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
		PHALCON_CONCAT_SVSVS(r0, "`", schema_name, "`.`", table_name, "`");
		PHALCON_CPY_WRT(table, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "`", table_name, "`");
		PHALCON_CPY_WRT(table, r1);
	}
	if (zend_is_true(if_exists)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SV(r2, "DROP TABLE IF EXISTS ", table);
		
		PHALCON_RETURN_CTOR(r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_SV(r3, "DROP TABLE ", table);
		
		PHALCON_RETURN_CTOR(r3);
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists){

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
		PHALCON_CONCAT_SVSVS(r0, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", table_name, "' AND `TABLE_SCHEMA`='", schema_name, "'");
		
		PHALCON_RETURN_CTOR(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", table_name, "'");
		
		PHALCON_RETURN_CTOR(r1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Generates SQL describing a table
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeTable){

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
		PHALCON_CONCAT_SVSVS(r0, "DESCRIBE `", schema, "`.`", table, "`");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "DESCRIBE `", table, "`");
		PHALCON_CPY_WRT(sql, r1);
	}
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * List all tables on database
 *
 * 
 *
 * @param       string $schemaName
 * @return      array
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listTables){

	zval *schema_name = NULL, *sql = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SVS(r0, "SHOW TABLES FROM `", schema_name, "`");
		PHALCON_CPY_WRT(sql, r0);
	} else {
		PHALCON_INIT_VAR(sql);
		ZVAL_STRING(sql, "SHOW TABLES", 1);
	}
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates SQL to query indexes on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes){

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
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences){

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
	
	
	PHALCON_RETURN_CTOR(sql);
}

/**
 * Generates the SQL to describe the table creation options
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions){

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
	
	
	PHALCON_RETURN_CTOR(sql);
}

