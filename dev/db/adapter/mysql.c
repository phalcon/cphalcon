
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
 * Phalcon_Db_Adapter_Mysql
 *
 * Phalcon_Db_Adapter_Mysql is the Phalcon_Db adapter for the MySQL database.
 * 
 */

/**
 * Constructor for Phalcon_Db_Adapter_Mysql. This method does not should to be called directly. Use Phalcon_Db::factory instead
 *
 * @param stdClass $descriptor
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
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, connect){

	zval *descriptor = NULL, *host = NULL, *username = NULL, *password = NULL, *port = NULL;
	zval *socket = NULL, *dbname = NULL, *client_flags = NULL, *persistent = NULL;
	zval *link = NULL, *autocommit = NULL, *success = NULL, *collation = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL;
	zval *p3[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
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
	eval_int = phalcon_isset_property(descriptor, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, descriptor, "host", sizeof("host")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(host, t1);
	} else {
		PHALCON_INIT_VAR(host);
		ZVAL_NULL(host);
	}
	
	eval_int = phalcon_isset_property(descriptor, "username", strlen("username") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, descriptor, "username", sizeof("username")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(username, t2);
	} else {
		PHALCON_INIT_VAR(username);
		ZVAL_NULL(username);
	}
	
	eval_int = phalcon_isset_property(descriptor, "password", strlen("password") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, descriptor, "password", sizeof("password")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(password, t3);
	} else {
		PHALCON_INIT_VAR(password);
		ZVAL_NULL(password);
	}
	
	eval_int = phalcon_isset_property(descriptor, "port", strlen("port") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, descriptor, "port", sizeof("port")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(port, t4);
	} else {
		PHALCON_INIT_VAR(port);
		ZVAL_NULL(port);
	}
	
	eval_int = phalcon_isset_property(descriptor, "socket", strlen("socket") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, descriptor, "socket", sizeof("socket")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(socket, t5);
	} else {
		PHALCON_INIT_VAR(socket);
		ZVAL_NULL(socket);
	}
	
	eval_int = phalcon_isset_property(descriptor, "name", strlen("name") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_read_property(&t6, descriptor, "name", sizeof("name")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(dbname, t6);
	} else {
		PHALCON_INIT_VAR(dbname);
		ZVAL_STRING(dbname, "", 1);
	}
	
	PHALCON_INIT_VAR(client_flags);
	ZVAL_NULL(client_flags);
	eval_int = phalcon_isset_property(descriptor, "compression", strlen("compression") TSRMLS_CC);
	if (eval_int) {
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 32);
		PHALCON_CPY_WRT(client_flags, t7);
	}
	
	eval_int = phalcon_isset_property(descriptor, "ssl", strlen("ssl") TSRMLS_CC);
	if (eval_int) {
		if (!zend_is_true(client_flags)) {
			PHALCON_INIT_VAR(t8);
			ZVAL_LONG(t8, 2048);
			PHALCON_CPY_WRT(client_flags, t8);
		} else {
			PHALCON_INIT_VAR(t9);
			ZVAL_LONG(t9, 2048);
			PHALCON_ALLOC_ZVAL_MM(r0);
			bitwise_or_function(r0, client_flags, t9 TSRMLS_CC);
			PHALCON_CPY_WRT(client_flags, r0);
		}
	}
	
	eval_int = phalcon_isset_property(descriptor, "interactive", strlen("interactive") TSRMLS_CC);
	if (eval_int) {
		if (!zend_is_true(client_flags)) {
			PHALCON_INIT_VAR(t10);
			ZVAL_LONG(t10, 1024);
			PHALCON_CPY_WRT(client_flags, t10);
		} else {
			PHALCON_INIT_VAR(t11);
			ZVAL_LONG(t11, 1024);
			PHALCON_ALLOC_ZVAL_MM(r1);
			bitwise_or_function(r1, client_flags, t11 TSRMLS_CC);
			PHALCON_CPY_WRT(client_flags, r1);
		}
	}
	
	PHALCON_INIT_VAR(persistent);
	ZVAL_BOOL(persistent, 0);
	eval_int = phalcon_isset_property(descriptor, "persistent", strlen("persistent") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t12);
		phalcon_read_property(&t12, descriptor, "persistent", sizeof("persistent")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(persistent, t12);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC(r2, "mysqli_init", 0x05F);
	PHALCON_CPY_WRT(link, r2);
	eval_int = phalcon_isset_property(descriptor, "autocommit", strlen("autocommit") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_ALLOC_ZVAL_MM(t13);
		phalcon_read_property(&t13, descriptor, "autocommit", sizeof("autocommit")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r3, "intval", t13, 0x020);
		PHALCON_CPY_WRT(autocommit, r3);
		phalcon_update_property_zval(this_ptr, "_autoCommit", strlen("_autoCommit"), autocommit TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		
		PHALCON_INIT_VAR(t14);
		ZVAL_LONG(t14, 3);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_SV(r5, "SET AUTOCOMMIT = ", autocommit);
		PHALCON_CALL_FUNC_PARAMS_3(r4, "mysqli_options", link, t14, r5, 0x060);
		if (!zend_is_true(r4)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Setting MYSQLI_INIT_COMMAND failed");
			return;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	p3[0] = link;
	p3[1] = host;
	p3[2] = username;
	p3[3] = password;
	p3[4] = dbname;
	p3[5] = port;
	p3[6] = socket;
	p3[7] = client_flags;
	PHALCON_CALL_FUNC_PARAMS(r6, "mysqli_real_connect", 8, p3, 0x061);
	PHALCON_CPY_WRT(success, r6);
	if (zend_is_true(success)) {
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), link TSRMLS_CC);
		PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon_Db_Adapter_Mysql", "__construct", descriptor);
		eval_int = phalcon_isset_property(descriptor, "charset", strlen("charset") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t15);
			phalcon_read_property(&t15, descriptor, "charset", sizeof("charset")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_2_NORETURN("mysqli_set_charset", link, t15, 0x06E);
		}
		
		eval_int = phalcon_isset_property(descriptor, "collation", strlen("collation") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t16);
			phalcon_read_property(&t16, descriptor, "collation", sizeof("collation")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(collation, t16);
			
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CONCAT_SV(r7, "SET collation_connection=", collation);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "query", r7, PHALCON_NO_CHECK);
			
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CONCAT_SV(r8, "SET collation_database=", collation);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "query", r8, PHALCON_NO_CHECK);
		}
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Connection to MySQL failed");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends SQL statements to the MySQL database server returning success state.
 * When the SQL sent have returned any row, the result is a PHP resource.
 *
 * 
 * $resultset = $connection->query("SELECT * FROM robots WHERE type=?", array("mechanical"));
 *
 * @param  string $sqlStatement
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, query){

	zval *sql_statement = NULL, *id_connection = NULL, *result = NULL;
	zval *number_error = NULL, *error_message = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL, *i1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_beforequery", sql_statement, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(id_connection, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysqli_query", id_connection, sql_statement, 0x062);
	PHALCON_CPY_WRT(result, r0);
	if (zend_is_true(result)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_afterquery", sql_statement, PHALCON_NO_CHECK);
		if (Z_TYPE_P(result) == IS_OBJECT) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_db_result_mysql_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", result, PHALCON_CHECK);
			
			PHALCON_RETURN_CTOR(i0);
		}
		
		
		PHALCON_RETURN_CHECK_CTOR(result);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "noerror", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(number_error, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_SVS(r3, " when executing \"", sql_statement, "\"");
	PHALCON_CALL_METHOD_PARAMS_1(r2, this_ptr, "error", r3, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(error_message, r2);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_db_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i1, "__construct", error_message, number_error, PHALCON_CHECK);
	phalcon_throw_exception(i1 TSRMLS_CC);
	return;
}

/**
 * Returns number of affected rows by the last INSERT/UPDATE/DELETE repoted by MySQL
 *
 * 
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, affectedRows){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysqli_affected_rows", t0, 0x069);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon_Db_Pool
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, close){

	zval *id_connection = NULL, *success = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(id_connection, t0);
	if (zend_is_true(id_connection)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "mysqli_close", id_connection, 0x06A);
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
 * Gets the active connection unique identifier. A mysqli object
 *
 * @param boolean $asString
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getConnectionId){

	zval *as_string = NULL, *id_connection = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &as_string) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!as_string) {
		PHALCON_INIT_VAR(as_string);
		ZVAL_BOOL(as_string, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(id_connection, t0);
	if (zend_is_true(as_string)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "mysqli_thread_id", id_connection, 0x06B);
		PHALCON_CONCAT_SV(r0, "Connection", r1);
		
		PHALCON_RETURN_CTOR(r0);
	} else {
		
		PHALCON_RETURN_CHECK_CTOR(id_connection);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Escapes a value to avoid SQL injections
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, escapeString){

	zval *str = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysqli_real_escape_string", t0, str, 0x06D);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Bind params to SQL select
 *
 * @param string $sqlSelect
 * @param array $params
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, bindParams){

	zval *sql_select = NULL, *params = NULL, *select = NULL, *id_connection = NULL;
	zval *bind_value = NULL, *index = NULL, *value = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_select, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, params TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_CPY_WRT(select, sql_select);
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(id_connection, t0);
		if (phalcon_valid_foreach(params TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(params);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_321f_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_321f_0;
			} else {
				PHALCON_INIT_VAR(index);
				PHALCON_GET_FOREACH_KEY(index, ah0, hp0);
			}
			PHALCON_INIT_VAR(bind_value);
			ZVAL_ZVAL(bind_value, *hd, 1, 0);
			if (Z_TYPE_P(bind_value) == IS_STRING) {
				PHALCON_INIT_VAR(r1);
				PHALCON_INIT_VAR(r2);
				PHALCON_CALL_FUNC_PARAMS_2(r2, "mysqli_real_escape_string", id_connection, bind_value, 0x06D);
				PHALCON_CONCAT_SVS(r1, "'", r2, "'");
				PHALCON_CPY_WRT(value, r1);
			} else {
				PHALCON_CPY_WRT(value, bind_value);
			}
			if (Z_TYPE_P(index) == IS_LONG) {
				PHALCON_INIT_VAR(r3);
				PHALCON_INIT_VAR(r4);
				PHALCON_CONCAT_SV(r4, "?", index);
				PHALCON_CALL_FUNC_PARAMS_3(r3, "str_replace", r4, value, select, 0x003);
				PHALCON_CPY_WRT(select, r3);
			} else {
				if (Z_TYPE_P(index) == IS_STRING) {
					PHALCON_INIT_VAR(r5);
					PHALCON_INIT_VAR(r6);
					PHALCON_CONCAT_SVS(r6, ":", index, ":");
					PHALCON_CALL_FUNC_PARAMS_3(r5, "str_replace", r6, value, select, 0x003);
					PHALCON_CPY_WRT(select, r5);
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Invalid bind parameter");
					return;
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_321f_0;
			fee_321f_0:
			if(0){}
		} else {
			return;
		}
		
		PHALCON_RETURN_CHECK_CTOR(select);
	}
	
	PHALCON_RETURN_CHECK_CTOR(sql_select);
}

/**
 * Returns last error message from MySQL
 *
 * @param string $errorString
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, error){

	zval *error_string = NULL, *id_connection = NULL, *error_message = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &error_string) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!error_string) {
		PHALCON_INIT_VAR(error_string);
		ZVAL_NULL(error_string);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(id_connection, t0);
	if (zend_is_true(id_connection)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "mysqli_error", id_connection, 0x06C);
		PHALCON_CPY_WRT(error_message, r0);
	} else {
		PHALCON_INIT_VAR(error_message);
		ZVAL_STRING(error_message, "", 1);
	}
	
	if (zend_is_true(error_message)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVSV(r1, "\"", error_message, "\" ", error_string);
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SVS(r2, "[Unknown MySQL error: ", error_string, "]");
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r2 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_lastError", sizeof("_lastError")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Returns last error code from MySQL
 *
 * @param string $errorString
 * @param resurce $resultQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, noError){

	zval *result_query = NULL, *id_connection = NULL;
	zval *t0 = NULL;
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
	PHALCON_CPY_WRT(id_connection, t0);
	if (!zend_is_true(id_connection)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysqli_errno", id_connection, 0x064);
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

	zval *table = NULL, *primary_key = NULL, *sequence_name = NULL, *id_connection = NULL;
	zval *t0 = NULL;
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
	PHALCON_CPY_WRT(id_connection, t0);
	if (!zend_is_true(id_connection)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysqli_insert_id", id_connection, 0x065);
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
 * @param string $sqlQuery
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

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL, *num = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;

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
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 2);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "fetchone", sql, t0, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(num, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, num, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r2);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * 
 *
 * @param string $viewName
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
	PHALCON_CONCAT_VS(r0, sql_query, " FOR UPDATE");
	
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
	PHALCON_CONCAT_VS(r0, sql_query, " LOCK IN SHARE MODE");
	
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
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
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
		PHALCON_CONCAT_SVS(r0, "Invalid definition to create the table '", table_name, "'");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	eval_int = phalcon_array_isset_string(definition, "columns", strlen("columns")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, definition, "columns", strlen("columns"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_fast_count(r2, r1 TSRMLS_CC);
	if (!zend_is_true(r2)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
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
 * @param string $table
 * @param string $schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeTable){

	zval *table = NULL, *schema = NULL, *sql = NULL, *describe = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;

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
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "fetchall", sql, t0, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(describe, r1);
	
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

	zval *schema_name = NULL, *sql = NULL, *tables = NULL, *all_tables = NULL, *table = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
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
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 2);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "fetchall", sql, t0, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(tables, r1);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(all_tables, a0);
	if (phalcon_valid_foreach(tables TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(tables);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_1;
		}
		
		PHALCON_INIT_VAR(table);
		ZVAL_ZVAL(table, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_long(&r2, table, 0, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_append(&all_tables, r2, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_1;
		fee_321f_1:
		if(0){}
	} else {
		return;
	}
	
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
	PHALCON_CONCAT_SVS(r0, "'", date, "'");
	
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Lists table indexes
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon_Db_Index[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeIndexes){

	zval *table = NULL, *schema = NULL, *sql = NULL, *describe = NULL, *indexes = NULL, *index = NULL;
	zval *key_name = NULL, *index_objects = NULL, *index_columns = NULL;
	zval *name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
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
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "fetchall", sql, t0, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(describe, r1);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(indexes, a0);
	if (phalcon_valid_foreach(describe TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(describe);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_2;
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
		goto fes_321f_2;
		fee_321f_2:
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
		fes_321f_3:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_321f_3;
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
		goto fes_321f_3;
		fee_321f_3:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_RETURN_CTOR(index_objects);
}

/**
 * Lists table references
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon_Db_Reference[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeReferences){

	zval *table = NULL, *schema = NULL, *sql = NULL, *references = NULL, *describe = NULL;
	zval *reference = NULL, *constraint_name = NULL, *reference_objects = NULL;
	zval *array_reference = NULL, *name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
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
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(references, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "fetchall", sql, t0, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(describe, r1);
	if (phalcon_valid_foreach(describe TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(describe);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_4;
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
		goto fes_321f_4;
		fee_321f_4:
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
		fes_321f_5:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_321f_5;
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
		goto fes_321f_5;
		fee_321f_5:
		if(0){}
	} else {
		return;
	}
	
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
	zval *a0 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;

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
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(references, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "fetchall", sql, t0, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(describe, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, describe, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r2);
}

