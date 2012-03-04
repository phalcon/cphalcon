
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

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Db_Dialect_Mysql
 *
 * Generates database specific SQL for the MySQL RBDM
 */

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Dialect_Mysql", "tableExists", 0);
	phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (If) File=/Db/Dialect/Mysql Line=20");
	if (zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (Block) File=/Db/Dialect/Mysql Line=20");
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (Assignment) File=/Db/Dialect/Mysql Line=21");
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v1);
		p0[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r0, "addslashes", strlen("addslashes"), 1, p0);
		phalcon_debug_vdump("addslashes > ", r0 TSRMLS_CC);
		if (v1) {
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r0);
		v1 = r0;
		phalcon_debug_assign("$schemaName", r0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_left(r2, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_concat_vboth(r1, r2, "' AND `TABLE_SCHEMA`='", v1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_right(r3, r1, "'" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (Block) File=/Db/Dialect/Mysql Line=23");
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_concat_both(r4,  "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", v0, "'" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r4 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r4);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (Method) File=/Db/Dialect/Mysql Line=37");
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Dialect_Mysql", "describeTable", 0);
	phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (If) File=/Db/Dialect/Mysql Line=38");
	if (zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Block) File=/Db/Dialect/Mysql Line=38");
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Assignment) File=/Db/Dialect/Mysql Line=39");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_concat_left(r1, "DESCRIBE `", v1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_concat_vboth(r0, r1, "`.`", v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_right(r2, r0, "`" TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r2);
		v2 = r2;
		phalcon_debug_assign("$sql", r2 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Block) File=/Db/Dialect/Mysql Line=40");
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Assignment) File=/Db/Dialect/Mysql Line=41");
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_both(r3,  "DESCRIBE `", v0, "`" TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r3);
		v2 = r3;
		phalcon_debug_assign("$sql", r3 TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Method) File=/Db/Dialect/Mysql Line=54");
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Dialect_Mysql", "listTables", 0);
	phalcon_step_over("Phalcon_Db_Dialect_Mysql::listTables (If) File=/Db/Dialect/Mysql Line=55");
	if (zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::listTables (Block) File=/Db/Dialect/Mysql Line=55");
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::listTables (Assignment) File=/Db/Dialect/Mysql Line=56");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_concat_both(r0,  "SHOW TABLES FROM `", v0, "`" TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r0);
		v1 = r0;
		phalcon_debug_assign("$sql", r0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::listTables (Block) File=/Db/Dialect/Mysql Line=57");
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::listTables (Assignment) File=/Db/Dialect/Mysql Line=58");
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "SHOW TABLES", 0);
	}
	phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
}

