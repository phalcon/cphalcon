
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
	ZVAL_STRING(v2, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME\n\t\tFROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);
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

