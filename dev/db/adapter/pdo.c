
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

#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Db\Adapter\Pdo
 *
 * Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect to a database
 * 
 */

/**
 * Constructor for Phalcon\Db\Adapter\Pdo
 *
 * @param array $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, __construct){

	zval *descriptor = NULL, *dialect_class = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(descriptor) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "$descriptor must be an array");
		return;
	}
	eval_int = phalcon_array_isset_string(descriptor, SL("dialectClass")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
		PHALCON_INIT_VAR(dialect_class);
		PHALCON_CONCAT_SV(dialect_class, "phalcon\\db\\dialect\\", t0);
	} else {
		PHALCON_INIT_VAR(dialect_class);
		phalcon_array_fetch_string(&dialect_class, descriptor, SL("dialectClass"), PH_NOISY_CC);
	}
	
	ce0 = phalcon_fetch_class(dialect_class TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PH_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_dialect"), i0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "connect", descriptor, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection
 *
 * @param array $descriptor
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect){

	zval *descriptor = NULL, *username = NULL, *password = NULL, *dsn_parts = NULL;
	zval *value = NULL, *key = NULL, *dsn = NULL, *options = NULL, *persistent = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *c0 = NULL;
	zval *i0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!descriptor) {
		PHALCON_ALLOC_ZVAL_MM(descriptor);
		ZVAL_NULL(descriptor);
	} else {
		PHALCON_SEPARATE_PARAM(descriptor);
	}
	
	if (!zend_is_true(descriptor)) {
		PHALCON_INIT_VAR(descriptor);
		phalcon_read_property(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	eval_int = phalcon_array_isset_string(descriptor, SL("username")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(username);
		phalcon_array_fetch_string(&username, descriptor, SL("username"), PH_NOISY_CC);
		PHALCON_SEPARATE_PARAM(descriptor);
		phalcon_array_unset_string(descriptor, SL("username")+1);
	} else {
		PHALCON_INIT_VAR(username);
		ZVAL_NULL(username);
	}
	
	eval_int = phalcon_array_isset_string(descriptor, SL("password")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(password);
		phalcon_array_fetch_string(&password, descriptor, SL("password"), PH_NOISY_CC);
		PHALCON_SEPARATE_PARAM(descriptor);
		phalcon_array_unset_string(descriptor, SL("password")+1);
	} else {
		PHALCON_INIT_VAR(password);
		ZVAL_NULL(password);
	}
	
	PHALCON_INIT_VAR(dsn_parts);
	array_init(dsn_parts);
	if (!phalcon_valid_foreach(descriptor TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(descriptor);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_7f5d_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_7f5d_0;
		}
		
		PHALCON_INIT_VAR(key);
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CONCAT_VSV(r0, key, "=", value);
		phalcon_array_append(&dsn_parts, r0, PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_7f5d_0;
	fee_7f5d_0:
	if(0){}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_type"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ";", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_join(r1, c0, dsn_parts TSRMLS_CC);
	
	PHALCON_INIT_VAR(dsn);
	PHALCON_CONCAT_VSV(dsn, t0, ":", r1);
	
	PHALCON_INIT_VAR(options);
	array_init(options);
	add_index_long(options, 3, 0);
	add_index_long(options, 8, 2);
	add_index_long(options, 10, 1);
	eval_int = phalcon_array_isset_string(descriptor, SL("persistent")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(persistent);
		phalcon_array_fetch_string(&persistent, descriptor, SL("persistent"), PH_NOISY_CC);
		if (zend_is_true(persistent)) {
			phalcon_array_update_long_bool(&options, 12, 1, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	ce0 = zend_fetch_class(SL("PDO"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_PARAMS_4_NORETURN(i0, "__construct", dsn, username, password, options, PH_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_pdo"), i0 TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Db\\Adapter\\Pdo", "__construct", descriptor);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server return rows
 *
 * //Querying data
 * $resultset = $connection->query("SELECT * FROM robots WHERE type='mechanical'");
 * $resultset = $connection->query("SELECT * FROM robots WHERE type=?", array("mechanical"));
 *
 * @param  string $sqlStatement
 * @return Phalcon\Db\Result\Pdo
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, query){

	zval *sql_statement = NULL, *events_manager = NULL, *pdo = NULL, *result = NULL;
	zval *error_info = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (zend_is_true(events_manager)) {
		phalcon_update_property_zval(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "db:beforeQuery", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD_PARAMS_2(r0, events_manager, "fire", c0, this_ptr, PH_NO_CHECK);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_1(result, pdo, "query", sql_statement, PH_NO_CHECK);
	if (Z_TYPE_P(result) == IS_OBJECT) {
		if (zend_is_true(events_manager)) {
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "db:afterQuery", 1);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_METHOD_PARAMS_2(r1, events_manager, "fire", c1, this_ptr, PH_NO_CHECK);
			if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_result_pdo_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", result, PH_CHECK);
		
		RETURN_CTOR(i0);
	}
	
	PHALCON_INIT_VAR(error_info);
	PHALCON_CALL_METHOD(error_info, pdo, "errorinfo", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_db_exception_ce);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, error_info, 2, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_VSV(r3, r2, " when executing ", sql_statement);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, error_info, 1, PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i1, "__construct", r3, r4, PH_CHECK);
	phalcon_throw_exception(i1 TSRMLS_CC);
	return;
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server don't return any row
 *
 * //Inserting data
 * $success = $connection->execute("INSERT INTO robots VALUES (1, 'Astro Boy')");
 * $success = $connection->execute("INSERT INTO robots VALUES (?, ?)", array(1, 'Astro Boy'));
 *
 * @param  string $sqlStatement
 * @param  array $placeholders
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute){

	zval *sql_statement = NULL, *placeholders = NULL, *events_manager = NULL;
	zval *pdo = NULL, *n = NULL, *statement = NULL, *value = NULL, *success = NULL, *affected_rows = NULL;
	zval *error_info = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &sql_statement, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!placeholders) {
		PHALCON_INIT_VAR(placeholders);
		array_init(placeholders);
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (zend_is_true(events_manager)) {
		phalcon_update_property_zval(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "db:beforeQuery", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD_PARAMS_2(r0, events_manager, "fire", c0, this_ptr, PH_NO_CHECK);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_count(r1, placeholders TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(n);
		ZVAL_LONG(n, 1);
		
		PHALCON_INIT_VAR(statement);
		PHALCON_CALL_METHOD_PARAMS_1(statement, pdo, "prepare", sql_statement, PH_NO_CHECK);
		if (!phalcon_valid_foreach(placeholders TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(placeholders);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_7f5d_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_7f5d_1;
			}
			
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(statement, "bindparam", n, value, PH_NO_CHECK);
			PHALCON_SEPARATE(n);
			increment_function(n);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_7f5d_1;
		fee_7f5d_1:
		if(0){}
		
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD(success, statement, "execute", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(affected_rows);
		PHALCON_CALL_METHOD(affected_rows, statement, "rowcount", PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(success);
		ZVAL_BOOL(success, 1);
		
		PHALCON_INIT_VAR(affected_rows);
		PHALCON_CALL_METHOD_PARAMS_1(affected_rows, pdo, "exec", sql_statement, PH_NO_CHECK);
	}
	
	if (zend_is_true(success)) {
		if (Z_TYPE_P(affected_rows) == IS_LONG) {
			phalcon_update_property_zval(this_ptr, SL("_affectedRows"), affected_rows TSRMLS_CC);
			if (zend_is_true(events_manager)) {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "db:afterQuery", 1);
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_CALL_METHOD_PARAMS_2(r2, events_manager, "fire", c1, this_ptr, PH_NO_CHECK);
				if (Z_TYPE_P(r2) == IS_BOOL && !Z_BVAL_P(r2)) {
					PHALCON_MM_RESTORE();
					RETURN_FALSE;
				}
			}
			
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	
	PHALCON_INIT_VAR(error_info);
	PHALCON_CALL_METHOD(error_info, pdo, "errorinfo", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_db_exception_ce);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_long(&r3, error_info, 2, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VSV(r4, r3, " when executing ", sql_statement);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_array_fetch_long(&r5, error_info, 1, PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", r4, r5, PH_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

/**
 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE repoted by the database system
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_affectedRows"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon\Db\Pool
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, close){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (zend_is_true(t0)) {
		phalcon_update_property_null(this_ptr, SL("_pdo") TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Escapes a value to avoid SQL injections
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeString){

	zval *str = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_pdo"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "quote", str, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Bind params to SQL select
 *
 * @param string $sqlSelect
 * @param array $params
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, bindParams){

	zval *sql_select = NULL, *params = NULL, *select = NULL, *pdo = NULL, *bind_value = NULL;
	zval *index = NULL, *value = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
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
		
		PHALCON_INIT_VAR(pdo);
		phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(params TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_7f5d_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_7f5d_2;
			}
			
			PHALCON_INIT_VAR(index);
			PHALCON_GET_FOREACH_KEY(index, ah0, hp0);
			PHALCON_INIT_VAR(bind_value);
			ZVAL_ZVAL(bind_value, *hd, 1, 0);
			PHALCON_INIT_VAR(r1);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "is_numeric", bind_value);
			if (zend_is_true(r1)) {
				PHALCON_CPY_WRT(value, bind_value);
			} else {
				PHALCON_INIT_VAR(value);
				PHALCON_CALL_METHOD_PARAMS_1(value, pdo, "quote", bind_value, PH_NO_CHECK);
			}
			if (Z_TYPE_P(index) == IS_LONG) {
				PHALCON_INIT_VAR(r2);
				PHALCON_CONCAT_SV(r2, "?", index);
				PHALCON_INIT_VAR(r3);
				phalcon_fast_str_replace(r3, r2, value, select TSRMLS_CC);
				PHALCON_CPY_WRT(select, r3);
			} else {
				if (Z_TYPE_P(index) == IS_STRING) {
					PHALCON_INIT_VAR(r4);
					PHALCON_CONCAT_SVS(r4, ":", index, ":");
					PHALCON_INIT_VAR(r5);
					phalcon_fast_str_replace(r5, r4, value, select TSRMLS_CC);
					PHALCON_CPY_WRT(select, r5);
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid bind parameter");
					return;
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_7f5d_2;
		fee_7f5d_2:
		if(0){}
		
		
		RETURN_CCTOR(select);
	}
	
	RETURN_CCTOR(sql_select);
}

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string $table
 * @param string $primaryKey
 * @param string $sequenceName
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, lastInsertId){

	zval *table = NULL, *primary_key = NULL, *sequence_name = NULL, *pdo = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &table, &primary_key, &sequence_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!table) {
		PHALCON_ALLOC_ZVAL_MM(table);
		ZVAL_NULL(table);
	}
	
	if (!primary_key) {
		PHALCON_ALLOC_ZVAL_MM(primary_key);
		ZVAL_NULL(primary_key);
	}
	
	if (!sequence_name) {
		PHALCON_ALLOC_ZVAL_MM(sequence_name);
		ZVAL_NULL(sequence_name);
	}
	
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (!zend_is_true(pdo)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, pdo, "lastinsertid", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getColumnList){

	zval *column_list = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "getcolumnlist", column_list, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * @param  string $sqlQuery
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, limit){

	zval *sql_query = NULL, *number = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, t0, "limit", sql_query, number, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, tableExists){

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL, *num = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_ALLOC_ZVAL_MM(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, t0, "tableexists", table_name, schema_name, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_db_ce, SL("FETCH_NUM") TSRMLS_CC);
	
	PHALCON_INIT_VAR(num);
	PHALCON_CALL_METHOD_PARAMS_2(num, this_ptr, "fetchone", sql, t1, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, num, 0, PH_NOISY_CC);
	
	RETURN_CCTOR(r0);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, viewExists){

	zval *view_name = NULL, *schema_name = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &view_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_ALLOC_ZVAL_MM(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "tableexists", view_name, schema_name, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, forUpdate){

	zval *sql_query = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "forupdate", sql_query, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, sharedLock){

	zval *sql_query = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "sharedlock", sql_query, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Creates a table using MySQL SQL
 *
 * @param string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, createTable){

	zval *table_name = NULL, *schema_name = NULL, *definition = NULL;
	zval *sql = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL;
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
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	eval_int = phalcon_array_isset_string(definition, SL("columns")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, definition, SL("columns"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_fast_count(r2, r1 TSRMLS_CC);
	if (!zend_is_true(r2)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "createtable", table_name, schema_name, definition, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD_PARAMS_1(r3, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r3);
}

/**
 * Drops a table from a schema/database
 *
 * @param string $tableName
 * @param   string $schemaName
 * @param boolean $ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, dropTable){

	zval *table_name = NULL, *schema_name = NULL, *if_exists = NULL, *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &table_name, &schema_name, &if_exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!if_exists) {
		PHALCON_ALLOC_ZVAL_MM(if_exists);
		ZVAL_BOOL(if_exists, 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "droptable", table_name, schema_name, if_exists, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Adds a column to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon_Db_Column $column
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, addColumn){

	zval *table_name = NULL, *schema_name = NULL, *column = NULL, *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "addcolumn", table_name, schema_name, column, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Modifies a table column based on a definition
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\Column $column
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, modifyColumn){

	zval *table_name = NULL, *schema_name = NULL, *column = NULL, *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "modifycolumn", table_name, schema_name, column, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Drops a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, dropColumn){

	zval *table_name = NULL, *schema_name = NULL, *column_name = NULL;
	zval *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "dropcolumn", table_name, schema_name, column_name, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Adds an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param DbIndex $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, addIndex){

	zval *table_name = NULL, *schema_name = NULL, *index = NULL, *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "addindex", table_name, schema_name, index, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Drop an index from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $indexName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, dropIndex){

	zval *table_name = NULL, *schema_name = NULL, *index_name = NULL;
	zval *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "dropindex", table_name, schema_name, index_name, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Adds a primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\Index $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, addPrimaryKey){

	zval *table_name = NULL, *schema_name = NULL, *index = NULL, *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "addprimarykey", table_name, schema_name, index, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Drops primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, dropPrimaryKey){

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, t0, "dropprimarykey", table_name, schema_name, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Adds a foreign key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\Reference $reference
 * @return boolean true
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, addForeignKey){

	zval *table_name = NULL, *schema_name = NULL, *reference = NULL, *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "addforeignkey", table_name, schema_name, reference, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Drops a foreign key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $referenceName
 * @return boolean true
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, dropForeignKey){

	zval *table_name = NULL, *schema_name = NULL, *reference_name = NULL;
	zval *sql = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "dropforeignkey", table_name, schema_name, reference_name, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "execute", sql, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Returns the SQL column definition from a column
 *
 * @param Phalcon\Db\Column $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getColumnDefinition){

	zval *column = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "getcolumndefinition", column, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * List all tables on a database
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, listTables){

	zval *schema_name = NULL, *sql = NULL, *tables = NULL, *all_tables = NULL, *table = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_ALLOC_ZVAL_MM(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_1(sql, t0, "listtables", schema_name, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_db_ce, SL("FETCH_NUM") TSRMLS_CC);
	
	PHALCON_INIT_VAR(tables);
	PHALCON_CALL_METHOD_PARAMS_2(tables, this_ptr, "fetchall", sql, t1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(all_tables);
	array_init(all_tables);
	if (!phalcon_valid_foreach(tables TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(tables);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_7f5d_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_7f5d_3;
		}
		
		PHALCON_INIT_VAR(table);
		ZVAL_ZVAL(table, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch_long(&r0, table, 0, PH_NOISY_CC);
		phalcon_array_append(&all_tables, r0, PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_7f5d_3;
	fee_7f5d_3:
	if(0){}
	
	
	RETURN_CTOR(all_tables);
}

