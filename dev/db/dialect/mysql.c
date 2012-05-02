
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", v1, 0x00B);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "intval", v1, 0x01E);
		PHALCON_CPY_WRT(v2, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, v0, " LIMIT ", v2);
		PHALCON_RETURN_CTOR(r2);
	} else {
		PHALCON_RETURN_CHECK_CTOR(v0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets a list of columns
 *
 * @paramarray $columnList
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnList){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_52be_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_52be_0;
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CONCAT_BOTH(r0,  "`", v2, "`");
		Z_ADDREF_P(r0);
		PHALCON_SEPARATE_ARRAY(v1);
		phalcon_array_append(v1, r0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_52be_0;
		fee_52be_0:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ", ", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "join", c0, v1, 0x00D);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Gets the column name in MySQL
 *
 * @param Phalcon_Db_Column $column
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *p0[] = { NULL }, *p6[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Column definition must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsize", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "gettype", PHALCON_CALL_DEFAULT);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, r1, t0 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "INT(", v1, ")");
		PHALCON_CPY_WRT(v2, r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, v0, "isunsigned", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " UNSIGNED", 1);
			PHALCON_ALLOC_ZVAL_MM(r5);
			concat_function(r5, v2, t1 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r5);
		}
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, r1, t2 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "DATE", 1);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 2);
	PHALCON_ALLOC_ZVAL_MM(r7);
	is_equal_function(r7, r1, t3 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_BOTH(r8,  "VARCHAR(", v1, ")");
		PHALCON_CPY_WRT(v2, r8);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 3);
	PHALCON_ALLOC_ZVAL_MM(r9);
	is_equal_function(r9, r1, t4 TSRMLS_CC);
	if (zend_is_true(r9)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_LEFT(r11, "DECIMAL(", v1);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_METHOD(r12, v0, "getscale", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CONCAT_VBOTH(r10, r11, ",", r12);
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CONCAT_RIGHT(r13, r10, ")");
		PHALCON_CPY_WRT(v2, r13);
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CALL_METHOD(r14, v0, "isunsigned", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r14)) {
			PHALCON_INIT_VAR(t5);
			ZVAL_STRING(t5, " UNSIGNED", 1);
			PHALCON_ALLOC_ZVAL_MM(r15);
			concat_function(r15, v2, t5 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r15);
		}
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 4);
	PHALCON_ALLOC_ZVAL_MM(r16);
	is_equal_function(r16, r1, t6 TSRMLS_CC);
	if (zend_is_true(r16)) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "DATETIME", 1);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t7);
	ZVAL_LONG(t7, 5);
	PHALCON_ALLOC_ZVAL_MM(r17);
	is_equal_function(r17, r1, t7 TSRMLS_CC);
	if (zend_is_true(r17)) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CONCAT_BOTH(r18,  "CHAR(", v1, ")");
		PHALCON_CPY_WRT(v2, r18);
		goto se_52be_1;
	}
	PHALCON_INIT_VAR(t8);
	ZVAL_LONG(t8, 6);
	PHALCON_ALLOC_ZVAL_MM(r19);
	is_equal_function(r19, r1, t8 TSRMLS_CC);
	if (zend_is_true(r19)) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "TEXT", 1);
		goto se_52be_1;
	}
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_db_exception_class_entry);
	PHALCON_INIT_VAR(p6[0]);
	ZVAL_STRING(p6[0], "Unrecognized MySQL data type", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p6, PHALCON_CALL_CHECK);
	return phalcon_throw_exception(i1 TSRMLS_CC);
	se_52be_1:
	if(0) { };
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Generates SQL to add a column to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Column $column
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Column parameter must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` ADD ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getname", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	Z_ADDREF_P(v2);
	p2[0] = v2;
	PHALCON_CALL_SELF_PARAMS(r7, this_ptr, "getcolumndefinition", 1, p2);
	Z_DELREF_P(p2[0]);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` ", r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	concat_function(r8, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r8);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, v2, "isnotnull", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, " NOT NULL", 1);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, v3, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r10);
	}
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, v2, "isfirst", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r11)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, " FIRST", 1);
		PHALCON_ALLOC_ZVAL_MM(r12);
		concat_function(r12, v3, t1 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r12);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CALL_METHOD(r13, v2, "getafterposition", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r13);
		if (zend_is_true(v4)) {
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_LEFT(r14, " AFTER ", v4);
			PHALCON_ALLOC_ZVAL_MM(r15);
			concat_function(r15, v3, r14 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r15);
		}
	}
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to modify a column in a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Column $column
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Column parameter must be an instance of Phalcon_Db_Column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` MODIFY ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` MODIFY ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getname", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	Z_ADDREF_P(v2);
	p2[0] = v2;
	PHALCON_CALL_SELF_PARAMS(r7, this_ptr, "getcolumndefinition", 1, p2);
	Z_DELREF_P(p2[0]);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` ", r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	concat_function(r8, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r8);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, v2, "isnotnull", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, " NOT NULL", 1);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, v3, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r10);
	}
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to delete a column from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP COLUMN ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` DROP COLUMN ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", v2, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r5);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to add an index to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Index $index
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Index parameter must be an instance of Phalcon_Db_Index", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD INDEX ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` ADD INDEX ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getname", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, v2, "getcolumns", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r8);
	p2[0] = r8;
	PHALCON_CALL_SELF_PARAMS(r7, this_ptr, "getcolumnlist", 1, p2);
	Z_DELREF_P(p2[0]);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "` (", r7);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_RIGHT(r9, r4, ")");
	PHALCON_ALLOC_ZVAL_MM(r10);
	concat_function(r10, v3, r9 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r10);
	PHALCON_RETURN_CTOR(v3);
}

/**
  * Generates SQL to delete an index from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $indexName
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropIndex){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP INDEX ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` DROP INDEX ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", v2, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r5);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to add the primary key to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Index $index
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Index parameter must be an instance of Phalcon_Db_Index", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` ADD PRIMARY KEY ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getcolumns", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r5);
	p1[0] = r5;
	PHALCON_CALL_SELF_PARAMS(r4, this_ptr, "getcolumnlist", 1, p1);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_BOTH(r6,  "(", r4, ")");
	PHALCON_ALLOC_ZVAL_MM(r7);
	concat_function(r7, v3, r6 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r7);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to delete primary key from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP PRIMARY KEY");
		PHALCON_CPY_WRT(v2, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` DROP PRIMARY KEY");
		PHALCON_CPY_WRT(v2, r3);
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Generates SQL to add an index to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Reference $reference
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Reference parameter must be an instance of Phalcon_Db_Reference", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` ADD FOREIGN KEY ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, v2, "getname", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "`", r5);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, v2, "getcolumns", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r8);
	p2[0] = r8;
	PHALCON_CALL_SELF_PARAMS(r7, this_ptr, "getcolumnlist", 1, p2);
	Z_DELREF_P(p2[0]);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VBOTH(r4, r6, "`(", r7);
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_RIGHT(r9, r4, ") REFERENCES ");
	PHALCON_ALLOC_ZVAL_MM(r10);
	concat_function(r10, v3, r9 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r10);
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, v2, "getreferencedschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r11);
	if (zend_is_true(v4)) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_BOTH(r12,  "`", v4, "`.");
		PHALCON_ALLOC_ZVAL_MM(r13);
		concat_function(r13, v3, r12 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r13);
	}
	PHALCON_ALLOC_ZVAL_MM(r15);
	PHALCON_CALL_METHOD(r15, v2, "getreferencedtable", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r16);
	PHALCON_CONCAT_LEFT(r16, "`", r15);
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_ALLOC_ZVAL_MM(r18);
	PHALCON_CALL_METHOD(r18, v2, "getreferencedcolumns", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r18);
	p6[0] = r18;
	PHALCON_CALL_SELF_PARAMS(r17, this_ptr, "getcolumnlist", 1, p6);
	Z_DELREF_P(p6[0]);
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CONCAT_VBOTH(r14, r16, "`(", r17);
	PHALCON_ALLOC_ZVAL_MM(r19);
	PHALCON_CONCAT_RIGHT(r19, r14, ")");
	PHALCON_ALLOC_ZVAL_MM(r20);
	concat_function(r20, v3, r19 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r20);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Generates SQL to delete a foreign key from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $referenceName
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropForeignKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "ALTER TABLE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "` DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "ALTER TABLE `", v0, "` DROP FOREIGN KEY ");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_BOTH(r4,  "`", v2, "`");
	PHALCON_ALLOC_ZVAL_MM(r5);
	concat_function(r5, v3, r4 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r5);
	PHALCON_RETURN_CTOR(v3);
}

PHP_METHOD(Phalcon_Db_Dialect_Mysql, _getTableOptions){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r0, "ENGINE", strlen("ENGINE")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, r1, "ENGINE", strlen("ENGINE"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, r3, "ENGINE", strlen("ENGINE"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r4)) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_LEFT(r5, "ENGINE=", v2);
			Z_ADDREF_P(r5);
			PHALCON_SEPARATE_ARRAY(v1);
			phalcon_array_append(v1, r5 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_array_fetch_string(&r6, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r6, "AUTO_INCREMENT", strlen("AUTO_INCREMENT")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, r7, "AUTO_INCREMENT", strlen("AUTO_INCREMENT"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r8);
		if (zend_is_true(v3)) {
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_LEFT(r9, "AUTO_INCREMENT=", v3);
			Z_ADDREF_P(r9);
			PHALCON_SEPARATE_ARRAY(v1);
			phalcon_array_append(v1, r9 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r10);
	phalcon_array_fetch_string(&r10, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_string(r10, "TABLE_COLLATION", strlen("TABLE_COLLATION")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, v0, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, r11, "TABLE_COLLATION", strlen("TABLE_COLLATION"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r12);
		if (zend_is_true(v4)) {
			PHALCON_ALLOC_ZVAL_MM(r13);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "_", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r13, "explode", c0, v4, 0x005);
			PHALCON_CPY_WRT(v5, r13);
			PHALCON_ALLOC_ZVAL_MM(r14);
			phalcon_array_fetch_long(&r14, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_LEFT(r15, "DEFAULT CHARSET=", r14);
			Z_ADDREF_P(r15);
			PHALCON_SEPARATE_ARRAY(v1);
			phalcon_array_append(v1, r15 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_LEFT(r16, "COLLATE=", v4);
			Z_ADDREF_P(r16);
			PHALCON_SEPARATE_ARRAY(v1);
			phalcon_array_append(v1, r16 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_CALL_FUNC_PARAMS_1(r17, "count", v1, 0x007);
	if (zend_is_true(r17)) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, " ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r18, "join", c1, v1, 0x00D);
		PHALCON_RETURN_DZVAL(r18);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Generates SQL to create a table in MySQL
 *
 * @param string $tableName
 * @paramstring $schemaName
 * @paramarray $definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL;
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
	zval *p1[] = { NULL }, *p5[] = { NULL }, *p8[] = { NULL }, *p11[] = { NULL }, *p14[] = { NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "`", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "`", v0, "`");
		PHALCON_CPY_WRT(v3, r3);
	}
	PHALCON_INIT_VAR(v4);
	ZVAL_BOOL(v4, 0);
	eval_int = phalcon_array_isset_string(v2, "options", strlen("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v2, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset_string(r4, "temporary", strlen("temporary")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_array_fetch_string(&r5, v2, "options", strlen("options"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r6);
			phalcon_array_fetch_string(&r6, r5, "temporary", strlen("temporary"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_INIT_VAR(v4);
				ZVAL_BOOL(v4, 1);
			}
		}
	}
	if (zend_is_true(v4)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_BOTH(r7,  "CREATE TEMPORARY TABLE ", v3, " (\n\t");
		PHALCON_CPY_WRT(v5, r7);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_BOTH(r8,  "CREATE TABLE ", v3, " (\n\t");
		PHALCON_CPY_WRT(v5, r8);
	}
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v6, a0);
	PHALCON_ALLOC_ZVAL_MM(r9);
	phalcon_array_fetch_string(&r9, v2, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(r9) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(r9);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_52be_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_52be_2;
		}
		PHALCON_INIT_VAR(v7);
		ZVAL_ZVAL(v7, *hd, 1, 0);
		PHALCON_INIT_VAR(r11);
		PHALCON_CALL_METHOD(r11, v7, "getname", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_VAR(r12);
		PHALCON_CONCAT_LEFT(r12, "`", r11);
		PHALCON_INIT_VAR(r13);
		Z_ADDREF_P(v7);
		p1[0] = v7;
		PHALCON_CALL_SELF_PARAMS(r13, this_ptr, "getcolumndefinition", 1, p1);
		Z_DELREF_P(p1[0]);
		PHALCON_INIT_VAR(r10);
		PHALCON_CONCAT_VBOTH(r10, r12, "` ", r13);
		PHALCON_CPY_WRT(v8, r10);
		PHALCON_INIT_VAR(r14);
		PHALCON_CALL_METHOD(r14, v7, "isnotnull", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r14)) {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, " NOT NULL", 1);
			PHALCON_INIT_VAR(r15);
			concat_function(r15, v8, t0 TSRMLS_CC);
			PHALCON_CPY_WRT(v8, r15);
		}
		PHALCON_INIT_VAR(r16);
		PHALCON_CALL_METHOD(r16, v7, "isautoincrement", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r16)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, " AUTO_INCREMENT", 1);
			PHALCON_INIT_VAR(r17);
			concat_function(r17, v8, t1 TSRMLS_CC);
			PHALCON_CPY_WRT(v8, r17);
		}
		Z_ADDREF_P(v8);
		PHALCON_SEPARATE_ARRAY(v6);
		phalcon_array_append(v6, v8 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_52be_2;
		fee_52be_2:
		if(0){ };
	}
	eval_int = phalcon_array_isset_string(v2, "indexes", strlen("indexes")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		phalcon_array_fetch_string(&r18, v2, "indexes", strlen("indexes"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r18) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(r18);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_52be_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_52be_3;
			}
			PHALCON_INIT_VAR(v9);
			ZVAL_ZVAL(v9, *hd, 1, 0);
			PHALCON_INIT_VAR(r19);
			PHALCON_CALL_METHOD(r19, v9, "getname", PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v10, r19);
			PHALCON_INIT_VAR(r20);
			PHALCON_INIT_VAR(r21);
			PHALCON_CALL_METHOD(r21, v9, "getcolumns", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r21);
			p5[0] = r21;
			PHALCON_CALL_SELF_PARAMS(r20, this_ptr, "getcolumnlist", 1, p5);
			Z_DELREF_P(p5[0]);
			PHALCON_CPY_WRT(v11, r20);
			if (PHALCON_COMPARE_STRING(v10, "PRIMARY")) {
				PHALCON_INIT_VAR(r22);
				PHALCON_CONCAT_BOTH(r22,  "PRIMARY KEY (", v11, ")");
				Z_ADDREF_P(r22);
				PHALCON_SEPARATE_ARRAY(v6);
				phalcon_array_append(v6, r22 TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r24);
				PHALCON_CONCAT_LEFT(r24, "KEY `", v10);
				PHALCON_INIT_VAR(r23);
				PHALCON_CONCAT_VBOTH(r23, r24, "` (", v11);
				PHALCON_INIT_VAR(r25);
				PHALCON_CONCAT_RIGHT(r25, r23, ")");
				Z_ADDREF_P(r25);
				PHALCON_SEPARATE_ARRAY(v6);
				phalcon_array_append(v6, r25 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_52be_3;
			fee_52be_3:
			if(0){ };
		}
	}
	eval_int = phalcon_array_isset_string(v2, "references", strlen("references")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r26);
		phalcon_array_fetch_string(&r26, v2, "references", strlen("references"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r26) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah2 = Z_ARRVAL_P(r26);
			zend_hash_internal_pointer_reset_ex(ah2, &hp2);
			fes_52be_4:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee_52be_4;
			}
			PHALCON_INIT_VAR(v12);
			ZVAL_ZVAL(v12, *hd, 1, 0);
			PHALCON_INIT_VAR(r30);
			PHALCON_CALL_METHOD(r30, v12, "getname", PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(r31);
			PHALCON_CONCAT_LEFT(r31, "CONSTRAINT `", r30);
			PHALCON_INIT_VAR(r32);
			PHALCON_INIT_VAR(r33);
			PHALCON_CALL_METHOD(r33, v12, "getcolumns", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r33);
			p8[0] = r33;
			PHALCON_CALL_SELF_PARAMS(r32, this_ptr, "getcolumnlist", 1, p8);
			Z_DELREF_P(p8[0]);
			PHALCON_INIT_VAR(r29);
			PHALCON_CONCAT_VBOTH(r29, r31, "` FOREIGN KEY (", r32);
			PHALCON_INIT_VAR(r34);
			PHALCON_CALL_METHOD(r34, v12, "getreferencedtable", PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(r28);
			PHALCON_CONCAT_VBOTH(r28, r29, ") REFERENCES `", r34);
			PHALCON_INIT_VAR(r35);
			PHALCON_INIT_VAR(r36);
			PHALCON_CALL_METHOD(r36, v12, "getreferencedcolumns", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r36);
			p11[0] = r36;
			PHALCON_CALL_SELF_PARAMS(r35, this_ptr, "getcolumnlist", 1, p11);
			Z_DELREF_P(p11[0]);
			PHALCON_INIT_VAR(r27);
			PHALCON_CONCAT_VBOTH(r27, r28, "`(", r35);
			PHALCON_INIT_VAR(r37);
			PHALCON_CONCAT_RIGHT(r37, r27, ")");
			Z_ADDREF_P(r37);
			PHALCON_SEPARATE_ARRAY(v6);
			phalcon_array_append(v6, r37 TSRMLS_CC);
			zend_hash_move_forward_ex(ah2, &hp2);
			goto fes_52be_4;
			fee_52be_4:
			if(0){ };
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r38);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ",\n\t", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r38, "join", c0, v6, 0x00D);
	PHALCON_ALLOC_ZVAL_MM(r39);
	PHALCON_CONCAT_RIGHT(r39, r38, "\n)");
	PHALCON_ALLOC_ZVAL_MM(r40);
	concat_function(r40, v5, r39 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r40);
	eval_int = phalcon_array_isset_string(v2, "options", strlen("options")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r41);
		Z_ADDREF_P(v2);
		p14[0] = v2;
		PHALCON_CALL_SELF_PARAMS(r41, this_ptr, "_gettableoptions", 1, p14);
		Z_DELREF_P(p14[0]);
		PHALCON_ALLOC_ZVAL_MM(r42);
		PHALCON_CONCAT_LEFT(r42, " ", r41);
		PHALCON_ALLOC_ZVAL_MM(r43);
		concat_function(r43, v5, r42 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r43);
	}
	PHALCON_RETURN_CTOR(v5);
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 1);
	}
	
	if (!PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "`", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(v3, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "`", v0, "`");
		PHALCON_CPY_WRT(v3, r3);
	}
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_LEFT(r4, "DROP TABLE IF EXISTS ", v3);
		PHALCON_RETURN_CTOR(r4);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_LEFT(r5, "DROP TABLE ", v3);
		PHALCON_RETURN_CTOR(r5);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", v0);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "' AND `TABLE_SCHEMA`='", v1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "'");
		PHALCON_RETURN_CTOR(r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", v0, "'");
		PHALCON_RETURN_CTOR(r3);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "DESCRIBE `", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(v2, r2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "DESCRIBE `", v0, "`");
		PHALCON_CPY_WRT(v2, r3);
	}
	PHALCON_RETURN_CTOR(v2);
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

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "SHOW TABLES FROM `", v0, "`");
		PHALCON_CPY_WRT(v1, r0);
	} else {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "SHOW TABLES", 1);
	}
	PHALCON_RETURN_CTOR(v1);
}

/**
 * Generates SQL to query indexes on a table
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "SHOW INDEXES FROM `", v0, "`");
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_LEFT(r2, "SHOW INDEXES FROM `", v1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_VBOTH(r1, r2, "`.`", v0);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_RIGHT(r3, r1, "`");
		PHALCON_CPY_WRT(v2, r3);
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME\n\t\t\tFROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);
	if (!PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "CONSTRAINT_SCHEMA = \"", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "\" AND TABLE_NAME = \"", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r3);
		concat_function(r3, v2, r2 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "TABLE_NAME = \"", v0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r5);
		concat_function(r5, v2, r4 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r5);
	}
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Generates the SQL to describe the table creation options
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "SELECT TABLES.TABLE_TYPE,TABLES.AUTO_INCREMENT,TABLES.ENGINE,TABLES.TABLE_COLLATION FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);
	if (!PHALCON_COMPARE_STRING(v1, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "TABLES.TABLE_SCHEMA = \"", v1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "\" AND TABLES.TABLE_NAME = \"", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r3);
		concat_function(r3, v2, r2 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "TABLES.TABLE_NAME = \"", v0, "\"");
		PHALCON_ALLOC_ZVAL_MM(r5);
		concat_function(r5, v2, r4 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r5);
	}
	PHALCON_RETURN_CTOR(v2);
}

