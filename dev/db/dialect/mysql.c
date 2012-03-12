
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v1);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "addslashes", v1, 0x01C);
		PHALCON_CPY_WRT_PARAM(v1, r0);
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_CONCAT_LEFT(r2, "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", v0);
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CONCAT_VBOTH(r1, r2, "' AND `TABLE_SCHEMA`='", v1);
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CONCAT_RIGHT(r3, r1, "'");
		PHALCON_RETURN_CTOR(r3);
	} else {
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_CONCAT_BOTH(r4,  "SELECT COUNT(*) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`='", v0, "'");
		PHALCON_RETURN_CTOR(r4);
	}
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CONCAT_LEFT(r1, "DESCRIBE `", v1);
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "`.`", v0);
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_CONCAT_RIGHT(r2, r0, "`");
		PHALCON_CPY_WRT(v2, r2);
	} else {
		PHALCON_ALLOC_ZVAL(r3);
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CONCAT_BOTH(r0,  "SHOW TABLES FROM `", v0, "`");
		PHALCON_CPY_WRT(v1, r0);
	} else {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "SHOW TABLES", 0);
	}
	PHALCON_RETURN_CTOR(v1);
}

