
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

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
		PHALCON_CONCAT_VBOTH(r2, sql_query, " LIMIT ", limit);
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
		PHALCON_CONCAT_BOTH(r0,  "`", column, "`");
		phalcon_array_append(&str_list, r0, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_52be_0;
		fee_52be_0:
		if(0){ };
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
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Column definition must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
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
		PHALCON_CONCAT_BOTH(r3,  "INT(", size, ")");
		PHALCON_CPY_WRT(column_sql, r3);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, column, "isunsigned", PHALCON_NO_CHECK);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " UNSIGNED", 1);
			PHALCON_ALLOC_ZVAL_MM(r5);
			concat_function(r5, column_sql, t1 TSRMLS_CC);
			PHALCON_CPY_WRT(column_sql, r5);
		}
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, r1, t2 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "DATE", 1);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 2);
	PHALCON_ALLOC_ZVAL_MM(r7);
	is_equal_function(r7, r1, t3 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_BOTH(r8,  "VARCHAR(", size, ")");
		PHALCON_CPY_WRT(column_sql, r8);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 3);
	PHALCON_ALLOC_ZVAL_MM(r9);
	is_equal_function(r9, r1, t4 TSRMLS_CC);
	if (zend_is_true(r9)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_LEFT(r11, "DECIMAL(", size);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_METHOD(r12, column, "getscale", PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CONCAT_VBOTH(r10, r11, ",", r12);
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CONCAT_RIGHT(r13, r10, ")");
		PHALCON_CPY_WRT(column_sql, r13);
		
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CALL_METHOD(r14, column, "isunsigned", PHALCON_NO_CHECK);
		if (zend_is_true(r14)) {
			PHALCON_INIT_VAR(t5);
			ZVAL_STRING(t5, " UNSIGNED", 1);
			PHALCON_ALLOC_ZVAL_MM(r15);
			concat_function(r15, column_sql, t5 TSRMLS_CC);
			PHALCON_CPY_WRT(column_sql, r15);
		}
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 4);
	PHALCON_ALLOC_ZVAL_MM(r16);
	is_equal_function(r16, r1, t6 TSRMLS_CC);
	if (zend_is_true(r16)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "DATETIME", 1);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t7);
	ZVAL_LONG(t7, 5);
	PHALCON_ALLOC_ZVAL_MM(r17);
	is_equal_function(r17, r1, t7 TSRMLS_CC);
	if (zend_is_true(r17)) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CONCAT_BOTH(r18,  "CHAR(", size, ")");
		PHALCON_CPY_WRT(column_sql, r18);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t8);
	ZVAL_LONG(t8, 6);
	PHALCON_ALLOC_ZVAL_MM(r19);
	is_equal_function(r19, r1, t8 TSRMLS_CC);
	if (zend_is_true(r19)) {
		PHALCON_INIT_VAR(column_sql);
		ZVAL_STRING(column_sql, "TEXT", 1);
		goto se_52be_1;
	}
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_db_exception_ce);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "Unrecognized MySQL data type", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
	phalcon_throw_exception(i1 TSRMLS_CC);
	return;
	se_52be_1:
	if(0) { };
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
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Column parameter must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD ");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` ADD ");
		PHALCON_CPY_WRT(sql, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, column, "getname", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_SELF_PARAMS_1(r7, this_ptr, "getcolumndefinition", column);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` ", r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	concat_function(r8, sql, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r8);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, column, "isnotnull", PHALCON_NO_CHECK);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, " NOT NULL", 1);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, sql, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r10);
	}
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, column, "isfirst", PHALCON_NO_CHECK);
	if (zend_is_true(r11)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, " FIRST", 1);
		PHALCON_ALLOC_ZVAL_MM(r12);
		concat_function(r12, sql, t1 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r12);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CALL_METHOD(r13, column, "getafterposition", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(after_position, r13);
		if (zend_is_true(after_position)) {
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_LEFT(r14, " AFTER ", after_position);
			PHALCON_ALLOC_ZVAL_MM(r15);
			concat_function(r15, sql, r14 TSRMLS_CC);
			PHALCON_CPY_WRT(sql, r15);
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
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(column) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Column parameter must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` MODIFY ");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` MODIFY ");
		PHALCON_CPY_WRT(sql, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, column, "getname", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_SELF_PARAMS_1(r7, this_ptr, "getcolumndefinition", column);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` ", r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	concat_function(r8, sql, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r8);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, column, "isnotnull", PHALCON_NO_CHECK);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, " NOT NULL", 1);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, sql, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r10);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP COLUMN ");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` DROP COLUMN ");
		PHALCON_CPY_WRT(sql, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", column_name, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, sql, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r5);
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
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(index) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Index parameter must be an instance of Phalcon_Db_Index", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD INDEX ");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` ADD INDEX ");
		PHALCON_CPY_WRT(sql, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, index, "getname", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, index, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r7, this_ptr, "getcolumnlist", r8);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` (", r7);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_RIGHT(r9, r4, ")");
	PHALCON_ALLOC_ZVAL_MM(r10);
	concat_function(r10, sql, r9 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r10);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP INDEX ");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` DROP INDEX ");
		PHALCON_CPY_WRT(sql, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", index_name, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, sql, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r5);
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
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(index) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Index parameter must be an instance of Phalcon_Db_Index", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(sql, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, index, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getcolumnlist", r5);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_BOTH(r6,  "(", r4, ")");
	PHALCON_ALLOC_ZVAL_MM(r7);
	concat_function(r7, sql, r6 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r7);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP PRIMARY KEY");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` DROP PRIMARY KEY");
		PHALCON_CPY_WRT(sql, r3);
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
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(reference) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Reference parameter must be an instance of Phalcon_Db_Reference", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, reference, "getname", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, reference, "getcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r7, this_ptr, "getcolumnlist", r8);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "`(", r7);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_RIGHT(r9, r4, ") REFERENCES ");
	PHALCON_ALLOC_ZVAL_MM(r10);
	concat_function(r10, sql, r9 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r10);
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, reference, "getreferencedschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(referenced_schema, r11);
	if (zend_is_true(referenced_schema)) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_BOTH(r12,  "`", referenced_schema, "`.");
		PHALCON_ALLOC_ZVAL_MM(r13);
		concat_function(r13, sql, r12 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r13);
	}
	PHALCON_ALLOC_ZVAL_MM(r15);
	PHALCON_CALL_METHOD(r15, reference, "getreferencedtable", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r16);
	PHALCON_CONCAT_LEFT(r16, "`", r15);
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_ALLOC_ZVAL_MM(r18);
	PHALCON_CALL_METHOD(r18, reference, "getreferencedcolumns", PHALCON_NO_CHECK);
	PHALCON_CALL_SELF_PARAMS_1(r17, this_ptr, "getcolumnlist", r18);
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CONCAT_VBOTH(r14, r16, "`(", r17);
	PHALCON_ALLOC_ZVAL_MM(r19);
	PHALCON_CONCAT_RIGHT(r19, r14, ")");
	PHALCON_ALLOC_ZVAL_MM(r20);
	concat_function(r20, sql, r19 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r20);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(schema_name)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", table_name, "` DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(sql, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", reference_name, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, sql, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r5);
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
			PHALCON_CONCAT_LEFT(r5, "ENGINE=", engine);
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
			PHALCON_CONCAT_LEFT(r9, "AUTO_INCREMENT=", auto_increment);
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
			PHALCON_ALLOC_ZVAL_MM(r13);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "_", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r13, "explode", c0, table_collation, 0x009);
			PHALCON_CPY_WRT(collation_parts, r13);
			
			PHALCON_ALLOC_ZVAL_MM(r14);
			phalcon_array_fetch_long(&r14, collation_parts, 0, PHALCON_NOISY TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_LEFT(r15, "DEFAULT CHARSET=", r14);
			phalcon_array_append(&table_options, r15, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_LEFT(r16, "COLLATE=", table_collation);
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
	zval *reference = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "`", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(table, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "`", table_name, "`");
		PHALCON_CPY_WRT(table, r3);
	}
	PHALCON_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	eval_int = phalcon_array_isset_string(definition, "options", strlen("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset_string(r4, "temporary", strlen("temporary")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_array_fetch_string(&r5, definition, "options", strlen("options"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r6);
			phalcon_array_fetch_string(&r6, r5, "temporary", strlen("temporary"), PHALCON_NOISY TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_INIT_VAR(temporary);
				ZVAL_BOOL(temporary, 1);
			}
		}
	}
	if (zend_is_true(temporary)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_BOTH(r7,  "CREATE TEMPORARY TABLE ", table, " (\n\t");
		PHALCON_CPY_WRT(sql, r7);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_BOTH(r8,  "CREATE TABLE ", table, " (\n\t");
		PHALCON_CPY_WRT(sql, r8);
	}
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(create_lines, a0);
	PHALCON_ALLOC_ZVAL_MM(r9);
	phalcon_array_fetch_string(&r9, definition, "columns", strlen("columns"), PHALCON_NOISY TSRMLS_CC);
	if (phalcon_valid_foreach(r9 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(r9);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_52be_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_52be_2;
		}
		PHALCON_INIT_VAR(column);
		ZVAL_ZVAL(column, *hd, 1, 0);
		PHALCON_INIT_VAR(r11);
		PHALCON_CALL_METHOD(r11, column, "getname", PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(r12);
		PHALCON_CONCAT_LEFT(r12, "`", r11);
		PHALCON_INIT_VAR(r13);
		PHALCON_CALL_SELF_PARAMS_1(r13, this_ptr, "getcolumndefinition", column);
		PHALCON_INIT_VAR(r10);
		PHALCON_CONCAT_VBOTH(r10, r12, "` ", r13);
		PHALCON_CPY_WRT(column_line, r10);
		
		PHALCON_INIT_VAR(r14);
		PHALCON_CALL_METHOD(r14, column, "isnotnull", PHALCON_NO_CHECK);
		if (zend_is_true(r14)) {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, " NOT NULL", 1);
			PHALCON_INIT_VAR(r15);
			concat_function(r15, column_line, t0 TSRMLS_CC);
			PHALCON_CPY_WRT(column_line, r15);
		}
		PHALCON_INIT_VAR(r16);
		PHALCON_CALL_METHOD(r16, column, "isautoincrement", PHALCON_NO_CHECK);
		if (zend_is_true(r16)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " AUTO_INCREMENT", 1);
			PHALCON_INIT_VAR(r17);
			concat_function(r17, column_line, t1 TSRMLS_CC);
			PHALCON_CPY_WRT(column_line, r17);
		}
		phalcon_array_append(&create_lines, column_line, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_52be_2;
		fee_52be_2:
		if(0){ };
	}
	eval_int = phalcon_array_isset_string(definition, "indexes", strlen("indexes")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		phalcon_array_fetch_string(&r18, definition, "indexes", strlen("indexes"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(r18 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(r18);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_52be_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_52be_3;
			}
			PHALCON_INIT_VAR(index);
			ZVAL_ZVAL(index, *hd, 1, 0);
			PHALCON_INIT_VAR(r19);
			PHALCON_CALL_METHOD(r19, index, "getname", PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(index_name, r19);
			
			PHALCON_INIT_VAR(r20);
			
			PHALCON_INIT_VAR(r21);
			PHALCON_CALL_METHOD(r21, index, "getcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r20, this_ptr, "getcolumnlist", r21);
			PHALCON_CPY_WRT(column_list, r20);
			if (PHALCON_COMPARE_STRING(index_name, "PRIMARY")) {
				PHALCON_INIT_VAR(r22);
				PHALCON_CONCAT_BOTH(r22,  "PRIMARY KEY (", column_list, ")");
				phalcon_array_append(&create_lines, r22, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r24);
				PHALCON_CONCAT_LEFT(r24, "KEY `", index_name);
				PHALCON_INIT_VAR(r23);
				PHALCON_CONCAT_VBOTH(r23, r24, "` (", column_list);
				PHALCON_INIT_VAR(r25);
				PHALCON_CONCAT_RIGHT(r25, r23, ")");
				phalcon_array_append(&create_lines, r25, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_52be_3;
			fee_52be_3:
			if(0){ };
		}
	}
	eval_int = phalcon_array_isset_string(definition, "references", strlen("references")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r26);
		phalcon_array_fetch_string(&r26, definition, "references", strlen("references"), PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(r26 TSRMLS_CC)) {
			ah2 = Z_ARRVAL_P(r26);
			zend_hash_internal_pointer_reset_ex(ah2, &hp2);
			fes_52be_4:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee_52be_4;
			}
			PHALCON_INIT_VAR(reference);
			ZVAL_ZVAL(reference, *hd, 1, 0);
			PHALCON_INIT_VAR(r30);
			PHALCON_CALL_METHOD(r30, reference, "getname", PHALCON_NO_CHECK);
			PHALCON_INIT_VAR(r31);
			PHALCON_CONCAT_LEFT(r31, "CONSTRAINT `", r30);
			PHALCON_INIT_VAR(r32);
			PHALCON_INIT_VAR(r33);
			PHALCON_CALL_METHOD(r33, reference, "getcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r32, this_ptr, "getcolumnlist", r33);
			PHALCON_INIT_VAR(r29);
			PHALCON_CONCAT_VBOTH(r29, r31, "` FOREIGN KEY (", r32);
			PHALCON_INIT_VAR(r34);
			PHALCON_CALL_METHOD(r34, reference, "getreferencedtable", PHALCON_NO_CHECK);
			PHALCON_INIT_VAR(r28);
			PHALCON_CONCAT_VBOTH(r28, r29, ") REFERENCES `", r34);
			PHALCON_INIT_VAR(r35);
			PHALCON_INIT_VAR(r36);
			PHALCON_CALL_METHOD(r36, reference, "getreferencedcolumns", PHALCON_NO_CHECK);
			PHALCON_CALL_SELF_PARAMS_1(r35, this_ptr, "getcolumnlist", r36);
			PHALCON_INIT_VAR(r27);
			PHALCON_CONCAT_VBOTH(r27, r28, "`(", r35);
			PHALCON_INIT_VAR(r37);
			PHALCON_CONCAT_RIGHT(r37, r27, ")");
			phalcon_array_append(&create_lines, r37, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah2, &hp2);
			goto fes_52be_4;
			fee_52be_4:
			if(0){ };
		}
	}
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ",\n\t", 1);
	PHALCON_ALLOC_ZVAL_MM(r38);
	phalcon_fast_join(r38, c0, create_lines TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r39);
	PHALCON_CONCAT_RIGHT(r39, r38, "\n)");
	PHALCON_ALLOC_ZVAL_MM(r40);
	concat_function(r40, sql, r39 TSRMLS_CC);
	PHALCON_CPY_WRT(sql, r40);
	eval_int = phalcon_array_isset_string(definition, "options", strlen("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r41);
		PHALCON_CALL_SELF_PARAMS_1(r41, this_ptr, "_gettableoptions", definition);
		PHALCON_ALLOC_ZVAL_MM(r42);
		PHALCON_CONCAT_LEFT(r42, " ", r41);
		PHALCON_ALLOC_ZVAL_MM(r43);
		concat_function(r43, sql, r42 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r43);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

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
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "`", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(table, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "`", table_name, "`");
		PHALCON_CPY_WRT(table, r3);
	}
	if (zend_is_true(if_exists)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_LEFT(r4, "DROP TABLE IF EXISTS ", table);
		PHALCON_RETURN_CTOR(r4);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_LEFT(r5, "DROP TABLE ", table);
		PHALCON_RETURN_CTOR(r5);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

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
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", table_name);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "' AND `TABLE_SCHEMA`='", schema_name);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "'");
		PHALCON_RETURN_CTOR(r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", table_name, "'");
		PHALCON_RETURN_CTOR(r3);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

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
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "DESCRIBE `", schema);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "DESCRIBE `", table, "`");
		PHALCON_CPY_WRT(sql, r3);
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
		PHALCON_CONCAT_BOTH(r0,  "SHOW TABLES FROM `", schema_name, "`");
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

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
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "SHOW INDEXES FROM `", schema);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", table);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(sql, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "SHOW INDEXES FROM `", table, "`");
		PHALCON_CPY_WRT(sql, r3);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

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
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "CONSTRAINT_SCHEMA = \"", schema);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "\" AND TABLE_NAME = \"", table);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r3);
		concat_function(r3, sql, r2 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "TABLE_NAME = \"", table, "\"");
		PHALCON_ALLOC_ZVAL_MM(r5);
		concat_function(r5, sql, r4 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r5);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

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
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "TABLES.TABLE_SCHEMA = \"", schema);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "\" AND TABLES.TABLE_NAME = \"", table);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r3);
		concat_function(r3, sql, r2 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "TABLES.TABLE_NAME = \"", table, "\"");
		PHALCON_ALLOC_ZVAL_MM(r5);
		concat_function(r5, sql, r4 TSRMLS_CC);
		PHALCON_CPY_WRT(sql, r5);
	}
	PHALCON_RETURN_CTOR(sql);
}

