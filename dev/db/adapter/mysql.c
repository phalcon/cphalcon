
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Db_Mysql
 *
 * Phalcon_Db_Mysql is the Phalcon_Db adapter for MySQL database.
 * 
 */

/**
 * Constructor for Phalcon_Db_Adapter_Mysql. This method does not should to be called directly. Use Phalcon_Db::factory instead
 *
 * @param stdClass $descriptor
 * @param boolean $persistent
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, __construct){

	zval *descriptor = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!descriptor) {
		PHALCON_INIT_VAR(descriptor);
		ZVAL_NULL(descriptor);
	} else {
		PHALCON_SEPARATE_PARAM(descriptor);
	}
	
	if (!zend_is_true(descriptor)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(descriptor, t0);
	}
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "connect", descriptor, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * This method is automatically called in Phalcon_Db_Mysql constructor.
 * Call it when you need to restore a database connection
 *
 * @param stdClass $descriptor
 * @param boolean $persistent
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, connect){

	zval *descriptor = NULL, *host = NULL, *username = NULL, *password = NULL, *dbstring = NULL;
	zval *client_flags = NULL, *persistent = NULL, *dbname = NULL, *autocommit = NULL;
	zval *collation = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!descriptor) {
		
		PHALCON_INIT_VAR(descriptor);
		ZVAL_NULL(descriptor);
	} else {
		PHALCON_SEPARATE_PARAM(descriptor);
	}
	
	if (!zend_is_true(descriptor)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(descriptor, t0);
	}
	
	PHALCON_INIT_VAR(host);
	ZVAL_STRING(host, "", 1);
	eval_int = phalcon_isset_property(descriptor, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, descriptor, "host", sizeof("host")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(host, t1);
	}
	
	PHALCON_INIT_VAR(username);
	ZVAL_STRING(username, "", 1);
	eval_int = phalcon_isset_property(descriptor, "username", strlen("username") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, descriptor, "username", sizeof("username")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(username, t2);
	}
	
	PHALCON_INIT_VAR(password);
	ZVAL_STRING(password, "", 1);
	eval_int = phalcon_isset_property(descriptor, "password", strlen("password") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, descriptor, "password", sizeof("password")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(password, t3);
	}
	
	eval_int = phalcon_isset_property(descriptor, "port", strlen("port") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, descriptor, "port", sizeof("port")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, host, ":", t4);
		PHALCON_CPY_WRT(dbstring, r0);
	} else {
		PHALCON_CPY_WRT(dbstring, host);
	}
	
	PHALCON_INIT_VAR(client_flags);
	ZVAL_NULL(client_flags);
	eval_int = phalcon_isset_property(descriptor, "compression", strlen("compression") TSRMLS_CC);
	if (eval_int) {
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 32);
		PHALCON_CPY_WRT(client_flags, t5);
	}
	
	eval_int = phalcon_isset_property(descriptor, "ssl", strlen("ssl") TSRMLS_CC);
	if (eval_int) {
		if (!zend_is_true(client_flags)) {
			PHALCON_INIT_VAR(t6);
			ZVAL_LONG(t6, 2048);
			PHALCON_CPY_WRT(client_flags, t6);
		} else {
			PHALCON_INIT_VAR(t7);
			ZVAL_LONG(t7, 2048);
			PHALCON_ALLOC_ZVAL_MM(r1);
			bitwise_or_function(r1, client_flags, t7 TSRMLS_CC);
			PHALCON_CPY_WRT(client_flags, r1);
		}
	}
	
	eval_int = phalcon_isset_property(descriptor, "interactive", strlen("interactive") TSRMLS_CC);
	if (eval_int) {
		if (!zend_is_true(client_flags)) {
			PHALCON_INIT_VAR(t8);
			ZVAL_LONG(t8, 1024);
			PHALCON_CPY_WRT(client_flags, t8);
		} else {
			PHALCON_INIT_VAR(t9);
			ZVAL_LONG(t9, 1024);
			PHALCON_ALLOC_ZVAL_MM(r2);
			bitwise_or_function(r2, client_flags, t9 TSRMLS_CC);
			PHALCON_CPY_WRT(client_flags, r2);
		}
	}
	
	PHALCON_INIT_VAR(persistent);
	ZVAL_BOOL(persistent, 0);
	eval_int = phalcon_isset_property(descriptor, "persistent", strlen("persistent") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t10);
		phalcon_read_property(&t10, descriptor, "persistent", sizeof("persistent")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(persistent, t10);
	}
	
	if (!zend_is_true(persistent)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		p0[0] = dbstring;
		p0[1] = username;
		p0[2] = password;
		PHALCON_INIT_VAR(p0[3]);
		ZVAL_BOOL(p0[3], 1);
		p0[4] = client_flags;
		PHALCON_CALL_FUNC_PARAMS(r3, "mysql_connect", 5, p0, 0x02E);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), r3 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		p1[0] = dbstring;
		p1[1] = username;
		p1[2] = password;
		p1[3] = client_flags;
		PHALCON_CALL_FUNC_PARAMS(r4, "mysql_pconnect", 4, p1, 0x035);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), r4 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t11);
	phalcon_read_property(&t11, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t11)) {
		eval_int = phalcon_isset_property(descriptor, "name", strlen("name") TSRMLS_CC);
		PHALCON_INIT_VAR(t12);
		ZVAL_BOOL(t12, eval_int);
		if (zend_is_true(t12)) {
			PHALCON_ALLOC_ZVAL_MM(t13);
			phalcon_read_property(&t13, descriptor, "name", sizeof("name")-1, PHALCON_NOISY TSRMLS_CC);
			r5 = t13;
		} else {
			PHALCON_INIT_VAR(t14);
			ZVAL_STRING(t14, "", 1);
			r5 = t14;
		}
		PHALCON_CPY_WRT(dbname, r5);
		if (zend_is_true(dbname)) {
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_ALLOC_ZVAL_MM(t15);
			phalcon_read_property(&t15, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_2(r6, "mysql_select_db", dbname, t15, 0x02F);
			if (!zend_is_true(r6)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_db_exception_ce);
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CALL_METHOD(r7, this_ptr, "error", PHALCON_NO_CHECK);
				PHALCON_ALLOC_ZVAL_MM(r8);
				PHALCON_CALL_METHOD(r8, this_ptr, "noerror", PHALCON_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", r7, r8, PHALCON_CHECK);
				phalcon_throw_exception(i0 TSRMLS_CC);
				return;
			}
		}
		
		
		PHALCON_INIT_VAR(autocommit);
		ZVAL_BOOL(autocommit, 0);
		eval_int = phalcon_isset_property(descriptor, "autocommit", strlen("autocommit") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t16);
			phalcon_read_property(&t16, descriptor, "autocommit", sizeof("autocommit")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(autocommit, t16);
		}
		
		phalcon_update_property_zval(this_ptr, "_autoCommit", strlen("_autoCommit"), autocommit TSRMLS_CC);
		
		PHALCON_INIT_VAR(t17);
		ZVAL_LONG(t17, 3);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t17 TSRMLS_CC);
		PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon_Db_Adapter_Mysql", "__construct", descriptor);
		eval_int = phalcon_isset_property(descriptor, "charset", strlen("charset") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t18);
			phalcon_read_property(&t18, descriptor, "charset", sizeof("charset")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_LEFT(r9, "SET NAMES ", t18);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "query", r9, PHALCON_NO_CHECK);
		}
		
		eval_int = phalcon_isset_property(descriptor, "collation", strlen("collation") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t19);
			phalcon_read_property(&t19, descriptor, "collation", sizeof("collation")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(collation, t19);
			
			PHALCON_ALLOC_ZVAL_MM(r10);
			PHALCON_CONCAT_LEFT(r10, "SET collation_connection=", collation);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "query", r10, PHALCON_NO_CHECK);
			
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_CONCAT_LEFT(r11, "SET collation_database=", collation);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "query", r11, PHALCON_NO_CHECK);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_METHOD(r12, this_ptr, "error", PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CALL_METHOD(r13, this_ptr, "noerror", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i1, "__construct", r12, r13, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Sends SQL statements to the MySQL database server returning success state.
 * When the SQL sent have returned any row, the result is a PHP resource.
 *
 * 
 *
 * @param  string $sqlStatement
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, query){

	zval *sql_statement = NULL, *id_connection = NULL, *result_query = NULL;
	zval *error_message = NULL, *number_error = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *c0 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(id_connection, t0);
	if (!zend_is_true(id_connection)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "connect", PHALCON_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
		if (!zend_is_true(t1)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	phalcon_update_property_zval(this_ptr, "_lastQuery", strlen("_lastQuery"), sql_statement TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_beforequery", sql_statement, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_query", sql_statement, id_connection, 0x030);
	PHALCON_CPY_WRT(result_query, r0);
	if (zend_is_true(result_query)) {
		phalcon_update_property_zval(this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), result_query TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_afterquery", sql_statement, PHALCON_NO_CHECK);
		
		PHALCON_RETURN_CHECK_CTOR(result_query);
	} else {
		phalcon_update_property_bool(this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), 0 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, " when executing \"", sql_statement);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_METHOD_PARAMS_1(r4, this_ptr, "getconnectionid", c0, PHALCON_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, "\" on connection \"", r4);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_RIGHT(r5, r2, "\"");
		PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "error", r5, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(error_message, r1);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_METHOD(r6, this_ptr, "noerror", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(number_error, r6);
		
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CALL_METHOD(r7, this_ptr, "noerror", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", error_message, r7, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon_Db_Pool
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, close){

	zval *success = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_close", t1, 0x036);
		PHALCON_CPY_WRT(success, r0);
		phalcon_update_property_null(this_ptr, "_idConnection", strlen("_idConnection") TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(success);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon_Db_Mysql::setFetchMode
 *
 * 
 *
 * @param resource $resultQuery
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, fetchArray){

	zval *result_query = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &result_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!result_query) {
		
		PHALCON_INIT_VAR(result_query);
		ZVAL_NULL(result_query);
	} else {
		PHALCON_SEPARATE_PARAM(result_query);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (!zend_is_true(result_query)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(result_query, t1);
		if (!zend_is_true(result_query)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_fetch_array", result_query, t2, 0x031);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Gets number of rows returned by a resulset
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, numRows){

	zval *result_query = NULL, *number_rows = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval *v0 = NULL;
	zval **pv0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &result_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!result_query) {
		
		PHALCON_INIT_VAR(result_query);
		ZVAL_NULL(result_query);
	} else {
		PHALCON_SEPARATE_PARAM(result_query);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (!zend_is_true(result_query)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(result_query, t1);
		if (!zend_is_true(result_query)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_num_rows", result_query, 0x037);
	PHALCON_CPY_WRT(number_rows, r0);
	if (Z_TYPE_P(number_rows) != IS_BOOL || (Z_TYPE_P(number_rows) == IS_BOOL && Z_BVAL_P(number_rows))) {
		
		PHALCON_RETURN_CHECK_CTOR(number_rows);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v0, pv0, "php_errormsg");
		PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "error", v0, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", r1, r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Moves internal resulset cursor to another position letting us to fetch a certain row
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dataSeek){

	zval *number = NULL, *result_query = NULL, *success = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval *v0 = NULL;
	zval **pv0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &number, &result_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!result_query) {
		
		PHALCON_INIT_VAR(result_query);
		ZVAL_NULL(result_query);
	} else {
		PHALCON_SEPARATE_PARAM(result_query);
	}
	
	if (!zend_is_true(result_query)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(result_query, t0);
		if (!zend_is_true(result_query)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_data_seek", result_query, number, 0x038);
	PHALCON_CPY_WRT(success, r0);
	if (Z_TYPE_P(success) != IS_BOOL || (Z_TYPE_P(success) == IS_BOOL && Z_BVAL_P(success))) {
		
		PHALCON_RETURN_CHECK_CTOR(success);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v0, pv0, "php_errormsg");
		PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "error", v0, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", r1, r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Returns number of affected rows by the last INSERT/UPDATE/DELETE repoted by MySQL
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, affectedRows){

	zval *result_query = NULL, *number_rows = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	zval *v0 = NULL;
	zval **pv0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &result_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!result_query) {
		
		PHALCON_INIT_VAR(result_query);
		ZVAL_NULL(result_query);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_affected_rows", t0, 0x039);
	PHALCON_CPY_WRT(number_rows, r0);
	if (Z_TYPE_P(number_rows) != IS_BOOL || (Z_TYPE_P(number_rows) == IS_BOOL && Z_BVAL_P(number_rows))) {
		
		PHALCON_RETURN_CHECK_CTOR(number_rows);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v0, pv0, "php_errormsg");
		PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "error", v0, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", r1, r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Changes the fetching mode affecting Phalcon_Db_Mysql::fetchArray
 *
 * 
 *
 * @param int $fetchMode
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, setFetchMode){

	zval *fetch_mode = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &fetch_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, fetch_mode, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 2);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, fetch_mode, t2 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 3);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t3 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 3);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, fetch_mode, t4 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t5 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns last error message from MySQL
 *
 * @param string $errorString
 * @param resurce $resultQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, error){

	zval *error_string = NULL, *result_query = NULL, *error_message = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &error_string, &result_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!error_string) {
		
		PHALCON_INIT_VAR(error_string);
		ZVAL_NULL(error_string);
	}
	
	if (!result_query) {
		
		PHALCON_INIT_VAR(result_query);
		ZVAL_NULL(result_query);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "mysql_error", 0x03A);
		PHALCON_CPY_WRT(error_message, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "mysql_error", t1, 0x03A);
		PHALCON_CPY_WRT(error_message, r1);
	}
	if (zend_is_true(error_message)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, "\"", error_message);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, "\" ", error_string);
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "[Unknown MySQL error: ", error_string, "]");
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r4 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_lastError", sizeof("_lastError")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Returns last error code from MySQL
 *
 * @param string $errorString
 * @param resurce $resultQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, noError){

	zval *result_query = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &result_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!result_query) {
		
		PHALCON_INIT_VAR(result_query);
		ZVAL_NULL(result_query);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_errno", t1, 0x03B);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string $table
 * @param string $primaryKey
 * @param string $sequenceName
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, lastInsertId){

	zval *table = NULL, *primary_key = NULL, *sequence_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &table, &primary_key, &sequence_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!table) {
		
		PHALCON_INIT_VAR(table);
		ZVAL_NULL(table);
	}
	
	if (!primary_key) {
		
		PHALCON_INIT_VAR(primary_key);
		ZVAL_NULL(primary_key);
	}
	
	if (!sequence_name) {
		
		PHALCON_INIT_VAR(sequence_name);
		ZVAL_NULL(sequence_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_insert_id", t1, 0x03C);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getColumnList){

	zval *column_list = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_db_dialect_mysql", "getcolumnlist", column_list);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * 
 *
 * @param string $errorString
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, limit){

	zval *sql_query = NULL, *number = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_db_dialect_mysql", "limit", sql_query, number);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, tableExists){

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL, *fetch_mode = NULL;
	zval *num = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		
		PHALCON_INIT_VAR(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_db_dialect_mysql", "tableexists", table_name, schema_name);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(fetch_mode, t0);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "fetchone", sql, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(num, r1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), fetch_mode TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, num, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r2);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, viewExists){

	zval *view_name = NULL, *schema_name = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &view_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		
		PHALCON_INIT_VAR(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "tableexists", view_name, schema_name, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Devuelve un FOR UPDATE valido para un SELECT del RBDM
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, forUpdate){

	zval *sql_query = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_RIGHT(r0, sql_query, " FOR UPDATE");
	
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Devuelve un SHARED LOCK valido para un SELECT del RBDM
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, sharedLock){

	zval *sql_query = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_RIGHT(r0, sql_query, " LOCK IN SHARE MODE");
	
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Creates a table using MySQL SQL
 *
 * @param string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, createTable){

	zval *table_name = NULL, *schema_name = NULL, *definition = NULL;
	zval *sql = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(definition) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "Invalid definition to create the table '", table_name, "'");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	eval_int = phalcon_array_isset_string(definition, "columns", strlen("columns")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "The table must contain at least one column", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, definition, "columns", strlen("columns"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_fast_count(r2, r1 TSRMLS_CC);
	if (!zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "The table must contain at least one column", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i2 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_STATIC_PARAMS_3(r3, "phalcon_db_dialect_mysql", "createtable", table_name, schema_name, definition);
	PHALCON_CPY_WRT(sql, r3);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD_PARAMS_1(r4, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r4);
}

/**
 * Drops a table from a schema/database
 *
 * @param string $tableName
 * @param   string $schemaName
 * @param boolean $ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropTable){

	zval *table_name = NULL, *schema_name = NULL, *if_exists = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &table_name, &schema_name, &if_exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!if_exists) {
		
		PHALCON_INIT_VAR(if_exists);
		ZVAL_BOOL(if_exists, 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "droptable", table_name, schema_name, if_exists);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a column to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Column $column
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addColumn){

	zval *table_name = NULL, *schema_name = NULL, *column = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "addcolumn", table_name, schema_name, column);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Modifies a table column based on a definition
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Column $column
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, modifyColumn){

	zval *table_name = NULL, *schema_name = NULL, *column = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "modifycolumn", table_name, schema_name, column);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropColumn){

	zval *table_name = NULL, *schema_name = NULL, *column_name = NULL;
	zval *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "dropcolumn", table_name, schema_name, column_name);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param DbIndex $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addIndex){

	zval *table_name = NULL, *schema_name = NULL, *index = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "addindex", table_name, schema_name, index);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drop an index from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $indexName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropIndex){

	zval *table_name = NULL, *schema_name = NULL, *index_name = NULL;
	zval *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "dropindex", table_name, schema_name, index_name);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Index $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addPrimaryKey){

	zval *table_name = NULL, *schema_name = NULL, *index = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "addprimarykey", table_name, schema_name, index);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropPrimaryKey){

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_db_dialect_mysql", "dropprimarykey", table_name, schema_name);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a foreign key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Reference $reference
 * @return boolean true
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addForeignKey){

	zval *table_name = NULL, *schema_name = NULL, *reference = NULL, *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "addforeignkey", table_name, schema_name, reference);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops a foreign key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $referenceName
 * @return boolean true
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropForeignKey){

	zval *table_name = NULL, *schema_name = NULL, *reference_name = NULL;
	zval *sql = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db_dialect_mysql", "dropforeignkey", table_name, schema_name, reference_name);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Returns the SQL column definition from a column
 *
 * @param Phalcon_Db_Column $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getColumnDefinition){

	zval *column = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_db_dialect_mysql", "getcolumndefinition", column);
	PHALCON_RETURN_DZVAL(r0);
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
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeTable){

	zval *table = NULL, *schema = NULL, *sql = NULL, *describe = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

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
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_db_dialect_mysql", "describetable", table, schema);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "fetchall", sql, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(describe, r1);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(describe);
}

/**
 * List all tables on a database
 *
 * 
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, listTables){

	zval *schema_name = NULL, *sql = NULL, *fetch_mode = NULL, *tables = NULL, *all_tables = NULL;
	zval *table = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		
		PHALCON_INIT_VAR(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_db_dialect_mysql", "listtables", schema_name);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(fetch_mode, t0);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "fetchall", sql, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(tables, r1);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(all_tables, a0);
	if (phalcon_valid_foreach(tables TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(tables);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_0;
		}
		
		PHALCON_INIT_VAR(table);
		ZVAL_ZVAL(table, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_long(&r2, table, 0, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_append(&all_tables, r2, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_0;
		fee_321f_0:
		if(0){}
	} else {
		return;
	}
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), fetch_mode TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(all_tables);
}

/**
 * Returns a database date formatted
 *
 * 
 *
 * @param string $date
 * @param string $format
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getDateUsingFormat){

	zval *date = NULL, *format = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &date, &format) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!format) {
		
		PHALCON_INIT_VAR(format);
		ZVAL_STRING(format, "YYYY-MM-DD", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_BOTH(r0,  "'", date, "'");
	
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Lists table indexes
 *
 * @param string $table
 * @param string $schema
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeIndexes){

	zval *table = NULL, *schema = NULL, *sql = NULL, *describe = NULL, *indexes = NULL, *index = NULL;
	zval *key_name = NULL, *index_objects = NULL, *index_columns = NULL;
	zval *name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *i0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

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
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_db_dialect_mysql", "describeindexes", table, schema);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "fetchall", sql, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(describe, r1);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(indexes, a0);
	if (phalcon_valid_foreach(describe TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(describe);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_1;
		}
		
		PHALCON_INIT_VAR(index);
		ZVAL_ZVAL(index, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_string(&r2, index, "Key_name", strlen("Key_name"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(key_name, r2);
		eval_int = phalcon_array_isset(indexes, key_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			phalcon_array_update(&indexes, key_name, &a1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		
		
		PHALCON_INIT_VAR(r3);
		phalcon_array_fetch_string(&r3, index, "Column_name", strlen("Column_name"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_multi_append_2(&indexes, key_name, r3, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_1;
		fee_321f_1:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(index_objects, a2);
	if (phalcon_valid_foreach(indexes TSRMLS_CC)) {
		ah1 = Z_ARRVAL_P(indexes);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_321f_2:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_321f_2;
		} else {
			PHALCON_INIT_VAR(name);
			PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		}
		PHALCON_INIT_VAR(index_columns);
		ZVAL_ZVAL(index_columns, *hd, 1, 0);
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_db_index_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", name, index_columns, PHALCON_CHECK);
		phalcon_array_update(&index_objects, name, &i0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_321f_2;
		fee_321f_2:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(index_objects);
}

/**
 * Lists table references
 *
 * @param string $table
 * @param string $schema
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeReferences){

	zval *table = NULL, *schema = NULL, *sql = NULL, *references = NULL, *describe = NULL;
	zval *reference = NULL, *constraint_name = NULL, *reference_objects = NULL;
	zval *array_reference = NULL, *name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *i0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

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
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_db_dialect_mysql", "describereferences", table, schema);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(references, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "fetchall", sql, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(describe, r1);
	if (phalcon_valid_foreach(describe TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(describe);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_3;
		}
		
		PHALCON_INIT_VAR(reference);
		ZVAL_ZVAL(reference, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_string(&r2, reference, "CONSTRAINT_NAME", strlen("CONSTRAINT_NAME"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(constraint_name, r2);
		eval_int = phalcon_array_isset(references, constraint_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_INIT_VAR(r3);
			phalcon_array_fetch_string(&r3, reference, "REFERENCED_TABLE_SCHEMA", strlen("REFERENCED_TABLE_SCHEMA"), PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update_string(&a1, "referencedSchema", strlen("referencedSchema"), &r3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_string(&r4, reference, "REFERENCED_TABLE_NAME", strlen("REFERENCED_TABLE_NAME"), PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update_string(&a1, "referencedTable", strlen("referencedTable"), &r4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			phalcon_array_update_string(&a1, "columns", strlen("columns"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			phalcon_array_update_string(&a1, "referencedColumns", strlen("referencedColumns"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_array_update(&references, constraint_name, &a1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		
		
		PHALCON_INIT_VAR(r5);
		phalcon_array_fetch_string(&r5, reference, "COLUMN_NAME", strlen("COLUMN_NAME"), PHALCON_NOISY TSRMLS_CC);
		if (Z_TYPE_P(references) == IS_ARRAY) {
			PHALCON_INIT_VAR(t1);
			phalcon_array_fetch(&t1, references, constraint_name, PHALCON_SILENT TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t1) > 1) {
			phalcon_array_update(&references, constraint_name, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
			phalcon_array_update(&references, constraint_name, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t1) == IS_ARRAY) {
			PHALCON_INIT_VAR(t2);
			phalcon_array_fetch_string(&t2, t1, "columns", strlen("columns"), PHALCON_SILENT TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t2) > 1) {
			phalcon_array_update_string(&t1, "columns", strlen("columns"), &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
			phalcon_array_update_string(&t1, "columns", strlen("columns"), &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		phalcon_array_append(&t2, r5, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		
		PHALCON_INIT_VAR(r6);
		phalcon_array_fetch_string(&r6, reference, "REFERENCED_COLUMN_NAME", strlen("REFERENCED_COLUMN_NAME"), PHALCON_NOISY TSRMLS_CC);
		if (Z_TYPE_P(references) == IS_ARRAY) {
			PHALCON_INIT_VAR(t3);
			phalcon_array_fetch(&t3, references, constraint_name, PHALCON_SILENT TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t3) > 1) {
			phalcon_array_update(&references, constraint_name, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t3) != IS_ARRAY) {
			convert_to_array(t3);
			phalcon_array_update(&references, constraint_name, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_INIT_VAR(t4);
			phalcon_array_fetch_string(&t4, t3, "referencedColumns", strlen("referencedColumns"), PHALCON_SILENT TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t4) > 1) {
			phalcon_array_update_string(&t3, "referencedColumns", strlen("referencedColumns"), &t4, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update_string(&t3, "referencedColumns", strlen("referencedColumns"), &t4, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		phalcon_array_append(&t4, r6, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_3;
		fee_321f_3:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	PHALCON_CPY_WRT(reference_objects, a4);
	if (phalcon_valid_foreach(references TSRMLS_CC)) {
		ah1 = Z_ARRVAL_P(references);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_321f_4:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_321f_4;
		} else {
			PHALCON_INIT_VAR(name);
			PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		}
		PHALCON_INIT_VAR(array_reference);
		ZVAL_ZVAL(array_reference, *hd, 1, 0);
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_db_reference_ce);
		PHALCON_INIT_VAR(a5);
		array_init(a5);
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch_string(&r7, array_reference, "referencedSchema", strlen("referencedSchema"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_string(&a5, "referencedSchema", strlen("referencedSchema"), &r7, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_INIT_VAR(r8);
		phalcon_array_fetch_string(&r8, array_reference, "referencedTable", strlen("referencedTable"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_string(&a5, "referencedTable", strlen("referencedTable"), &r8, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_INIT_VAR(r9);
		phalcon_array_fetch_string(&r9, array_reference, "columns", strlen("columns"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_string(&a5, "columns", strlen("columns"), &r9, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_INIT_VAR(r10);
		phalcon_array_fetch_string(&r10, array_reference, "referencedColumns", strlen("referencedColumns"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_string(&a5, "referencedColumns", strlen("referencedColumns"), &r10, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", name, a5, PHALCON_CHECK);
		phalcon_array_update(&reference_objects, name, &i0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_321f_4;
		fee_321f_4:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t5 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(reference_objects);
}

/**
 * Gets creation options from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, tableOptions){

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL, *references = NULL;
	zval *describe = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		
		PHALCON_INIT_VAR(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_db_dialect_mysql", "tableoptions", table_name, schema_name);
	PHALCON_CPY_WRT(sql, r0);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(references, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "fetchall", sql, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(describe, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, describe, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r2);
}

