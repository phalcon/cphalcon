
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
	phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (If) File=Library/Phalcon/Db/Dialect/Mysql.php Line=6");
	//$schemaName
	if (phalcon_compare_strict_string(v1, "")) {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (Block) File=Library/Phalcon/Db/Dialect/Mysql.php Line=6");
		//$tableName
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_concat_both(r0,  "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", v0, "'" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (Block) File=Library/Phalcon/Db/Dialect/Mysql.php Line=8");
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (Assignment) File=Library/Phalcon/Db/Dialect/Mysql.php Line=9");
		//$schemaName
		PHALCON_ALLOC_ZVAL(r1);
		//$schemaName
		Z_ADDREF_P(v1);
		p0[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "addslashes", 1, p0);
		phalcon_debug_vdump("addslashes > ", r1 TSRMLS_CC);
		if (v1) {
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r1);
		v1 = r1;
		phalcon_debug_assign("$schemaName", r1 TSRMLS_CC);
		//$tableName
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_left(r3, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", v0 TSRMLS_CC);
		//$schemaName
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, r3, "' AND `TABLE_SCHEMA`='", v1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_concat_right(r4, r2, "'" TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Db_Dialect_Mysql::tableExists (Method) File=Library/Phalcon/Db/Dialect/Mysql.php Line=14");
}

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
	phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (If) File=Library/Phalcon/Db/Dialect/Mysql.php Line=15");
	//$schema
	if (phalcon_compare_strict_string(v1, "")) {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Block) File=Library/Phalcon/Db/Dialect/Mysql.php Line=15");
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Assignment) File=Library/Phalcon/Db/Dialect/Mysql.php Line=16");
		//$sql
		//$table
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_concat_both(r0,  "DESCRIBE `", v0, "`" TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r0);
		v2 = r0;
		phalcon_debug_assign("$sql", r0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Block) File=Library/Phalcon/Db/Dialect/Mysql.php Line=17");
		phalcon_step_over("Phalcon_Db_Dialect_Mysql::describeTable (Assignment) File=Library/Phalcon/Db/Dialect/Mysql.php Line=18");
		//$sql
		//$schema
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_left(r2, "DESCRIBE `", v1 TSRMLS_CC);
		//$table
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_concat_vboth(r1, r2, "`.`", v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_right(r3, r1, "`" TSRMLS_CC);
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
	//$sql
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
}

