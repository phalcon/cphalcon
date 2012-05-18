
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
 * Phalcon_Db
 *
 * Phalcon_Db and its related classes provide a simple SQL database interface for Phalcon Framework.
 * The Phalcon_Db is the basic class you use to connect your PHP application to a RDBMS.
 * There is a different adapter class for each brand of RDBMS.
 *
 * This component is intended to low level database operations. If you want to interact with databases using
 * high level abstraction use Phalcon_Model.
 *
 * Phalcon_Db is an abstract class. You only can use it with a database adapter like Phalcon_Db_Mysql
 *
 * 
 */

/**
 * Phalcon_Db contructor, this method should not be called directly. Use Phalcon_Db::factory instead
 *
 * @param stdClass $descriptor
 */
PHP_METHOD(Phalcon_Db, __construct){

	zval *descriptor = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_descriptor", strlen("_descriptor"), descriptor TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a logger class to log all SQL operations sended to database server
 *
 * @param Phalcon_Logger $logger
 */
PHP_METHOD(Phalcon_Db, setLogger){

	zval *logger = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &logger) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_logger", strlen("_logger"), logger TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the active logger
 *
 * @return Phalcon_Logger
 */
PHP_METHOD(Phalcon_Db, getLogger){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sends arbitrary text to a related logger in the instance
 *
 * @param string $sqlStatement
 * @param int $type
 */
PHP_METHOD(Phalcon_Db, log){

	zval *sql_statement = NULL, *type = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_statement, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t1, "log", sql_statement, type, PHALCON_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a database profiler to the connection
 *
 * @param Phalcon_Db_Profiler $profiler
 */
PHP_METHOD(Phalcon_Db, setProfiler){

	zval *profiler = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &profiler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(profiler) == IS_OBJECT) {
		phalcon_update_property_zval(this_ptr, "_profiler", strlen("_profiler"), profiler TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Profiler must be an object", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the first row in a SQL query result
 *
 * 
 *
 * @param string $sqlQuery
 * @return array
 */
PHP_METHOD(Phalcon_Db, fetchOne){

	zval *sql_query = NULL, *result_query = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "query", sql_query, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(result_query, r0);
	if (zend_is_true(result_query)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "fetcharray", result_query, PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r1);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_RETURN_CTOR(a0);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Dumps the complete result of a query into an array
 *
 * 
 *
 * @param string $sqlQuery
 * @return array
 */
PHP_METHOD(Phalcon_Db, fetchAll){

	zval *sql_query = NULL, *results = NULL, *result_query = NULL, *row = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(results, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "query", sql_query, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(result_query, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_INIT_VAR(r1);
	is_not_equal_function(r1, result_query, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		ws_e7f0_0:
			PHALCON_INIT_VAR(r2);
			PHALCON_CALL_METHOD_PARAMS_1(r2, this_ptr, "fetcharray", result_query, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(row, r2);
			if (!zend_is_true(row)) {
				goto we_e7f0_0;
			}
			phalcon_array_append(&results, row, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			goto ws_e7f0_0;
		we_e7f0_0:
		if(0) { };
	}
	PHALCON_RETURN_CTOR(results);
}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param array $values
 * @param array $fields
 * @param boolean $automaticQuotes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, insert){

	zval *table = NULL, *values = NULL, *fields = NULL, *automatic_quotes = NULL;
	zval *insert_sql = NULL, *value = NULL, *key = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &table, &values, &fields, &automatic_quotes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(values);
	
	if (!fields) {
		PHALCON_INIT_VAR(fields);
		ZVAL_NULL(fields);
	}
	
	if (!automatic_quotes) {
		PHALCON_INIT_VAR(automatic_quotes);
		ZVAL_BOOL(automatic_quotes, 0);
	}
	
	PHALCON_INIT_VAR(insert_sql);
	ZVAL_STRING(insert_sql, "", 1);
	if (Z_TYPE_P(values) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_count(r0, values TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_equal_function(r1, r0, t0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_db_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_BOTH(r2,  "Unable to insert into ", table, " without data");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		} else {
			if (zend_is_true(automatic_quotes)) {
				if (phalcon_valid_foreach(values TSRMLS_CC)) {
					ALLOC_HASHTABLE(ah0);
					zend_hash_init(ah0, 0, NULL, NULL, 0);
					zend_hash_copy(ah0, Z_ARRVAL_P(values), NULL, NULL, sizeof(zval*));
					zend_hash_internal_pointer_reset_ex(ah0, &hp0);
					fes_e7f0_1:
					if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
						goto fee_e7f0_1;
					} else {
						PHALCON_INIT_VAR(key);
						hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
						if (hash_type == HASH_KEY_IS_STRING) {
							ZVAL_STRINGL(key, hash_index, hash_index_len-1, 1);
						} else {
							if (hash_type == HASH_KEY_IS_LONG) {
								ZVAL_LONG(key, hash_num);
							}
						}
					}
					PHALCON_INIT_VAR(value);
					ZVAL_ZVAL(value, *hd, 1, 0);
					PHALCON_INIT_VAR(r3);
					phalcon_array_fetch(&r3, values, key, PHALCON_NOISY TSRMLS_CC);
					if (Z_TYPE_P(r3) == IS_OBJECT) {
						PHALCON_INIT_VAR(r4);
						phalcon_array_fetch(&r4, values, key, PHALCON_NOISY TSRMLS_CC);
						PHALCON_INIT_VAR(r5);
						phalcon_instance_of(r5, r4, phalcon_db_rawvalue_ce TSRMLS_CC);
						if (zend_is_true(r5)) {
							PHALCON_INIT_VAR(r6);
							PHALCON_INIT_VAR(r7);
							PHALCON_INIT_VAR(r8);
							phalcon_array_fetch(&r8, values, key, PHALCON_NOISY TSRMLS_CC);
							PHALCON_CALL_METHOD(r7, r8, "getvalue", PHALCON_NO_CHECK);
							Z_ADDREF_P(r7);
							PHALCON_CALL_FUNC_PARAMS_1(r6, "addslashes", r7, 0x00F);
							Z_DELREF_P(r7);
							phalcon_array_update(&values, key, r6, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
							goto fes_e7f0_1;
						} else {
							PHALCON_INIT_VAR(r9);
							PHALCON_INIT_VAR(r10);
							phalcon_array_fetch(&r10, values, key, PHALCON_NOISY TSRMLS_CC);
							Z_ADDREF_P(r10);
							PHALCON_CALL_FUNC_PARAMS_1(r9, "addslashes", r10, 0x00F);
							Z_DELREF_P(r10);
							PHALCON_INIT_VAR(r11);
							PHALCON_CONCAT_BOTH(r11,  "'", r9, "'");
							phalcon_array_update(&values, key, r11, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
						}
					} else {
						PHALCON_INIT_VAR(r12);
						PHALCON_INIT_VAR(r13);
						phalcon_array_fetch(&r13, values, key, PHALCON_NOISY TSRMLS_CC);
						Z_ADDREF_P(r13);
						PHALCON_CALL_FUNC_PARAMS_1(r12, "addslashes", r13, 0x00F);
						Z_DELREF_P(r13);
						PHALCON_INIT_VAR(r14);
						PHALCON_CONCAT_BOTH(r14,  "'", r12, "'");
						phalcon_array_update(&values, key, r14, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					}
					zend_hash_move_forward_ex(ah0, &hp0);
					goto fes_e7f0_1;
					fee_e7f0_1:
					zend_hash_destroy(ah0);
					efree(ah0);
				}
			}
		}
		if (Z_TYPE_P(fields) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r17);
			PHALCON_CONCAT_LEFT(r17, "INSERT INTO ", table);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, ", ", 1);
			PHALCON_ALLOC_ZVAL_MM(r18);
			phalcon_fast_join(r18, c0, fields TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_VBOTH(r16, r17, " (", r18);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, ", ", 1);
			PHALCON_ALLOC_ZVAL_MM(r19);
			phalcon_fast_join(r19, c1, values TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_VBOTH(r15, r16, ") VALUES (", r19);
			PHALCON_ALLOC_ZVAL_MM(r20);
			PHALCON_CONCAT_RIGHT(r20, r15, ")");
			PHALCON_CPY_WRT(insert_sql, r20);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r22);
			PHALCON_CONCAT_LEFT(r22, "INSERT INTO ", table);
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, ", ", 1);
			PHALCON_ALLOC_ZVAL_MM(r23);
			phalcon_fast_join(r23, c2, values TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_CONCAT_VBOTH(r21, r22, " VALUES (", r23);
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_CONCAT_RIGHT(r24, r21, ")");
			PHALCON_CPY_WRT(insert_sql, r24);
		}
		PHALCON_ALLOC_ZVAL_MM(r25);
		PHALCON_CALL_METHOD_PARAMS_1(r25, this_ptr, "query", insert_sql, PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r25);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, "The second parameter for insert isn't an Array", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c3, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param array $fields
 * @param array $values
 * @param string $whereCondition
 * @param boolean $automaticQuotes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, update){

	zval *table = NULL, *fields = NULL, *values = NULL, *where_condition = NULL;
	zval *automatic_quotes = NULL, *update_sql = NULL, *i = NULL, *update_values = NULL;
	zval *field = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &table, &fields, &values, &where_condition, &automatic_quotes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(values);
	
	if (!where_condition) {
		PHALCON_INIT_VAR(where_condition);
		ZVAL_NULL(where_condition);
	}
	
	if (!automatic_quotes) {
		PHALCON_INIT_VAR(automatic_quotes);
		ZVAL_BOOL(automatic_quotes, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_BOTH(r0,  "UPDATE ", table, " SET ");
	PHALCON_CPY_WRT(update_sql, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_count(r1, fields TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_fast_count(r2, values TSRMLS_CC);
	PHALCON_INIT_VAR(r3);
	is_not_equal_function(r3, r1, r2 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "The number of values to update is not the same as fields", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(update_values, a0);
	if (phalcon_valid_foreach(fields TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(fields);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e7f0_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_e7f0_2;
		}
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		if (zend_is_true(automatic_quotes)) {
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch(&r4, values, i, PHALCON_NOISY TSRMLS_CC);
			if (Z_TYPE_P(r4) == IS_OBJECT) {
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch(&r5, values, i, PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(r6);
				phalcon_instance_of(r6, r5, phalcon_db_rawvalue_ce TSRMLS_CC);
				if (zend_is_true(r6)) {
					PHALCON_INIT_VAR(r7);
					PHALCON_INIT_VAR(r8);
					PHALCON_INIT_VAR(r9);
					phalcon_array_fetch(&r9, values, i, PHALCON_NOISY TSRMLS_CC);
					PHALCON_CALL_METHOD(r8, r9, "getvalue", PHALCON_NO_CHECK);
					Z_ADDREF_P(r8);
					PHALCON_CALL_FUNC_PARAMS_1(r7, "addslashes", r8, 0x00F);
					Z_DELREF_P(r8);
					phalcon_array_update(&values, i, r7, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r10);
					PHALCON_INIT_VAR(r11);
					phalcon_array_fetch(&r11, values, i, PHALCON_NOISY TSRMLS_CC);
					Z_ADDREF_P(r11);
					PHALCON_CALL_FUNC_PARAMS_1(r10, "addslashes", r11, 0x00F);
					Z_DELREF_P(r11);
					PHALCON_INIT_VAR(r12);
					PHALCON_CONCAT_BOTH(r12,  "'", r10, "'");
					phalcon_array_update(&values, i, r12, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
			} else {
				PHALCON_INIT_VAR(r13);
				PHALCON_INIT_VAR(r14);
				phalcon_array_fetch(&r14, values, i, PHALCON_NOISY TSRMLS_CC);
				Z_ADDREF_P(r14);
				PHALCON_CALL_FUNC_PARAMS_1(r13, "addslashes", r14, 0x00F);
				Z_DELREF_P(r14);
				PHALCON_INIT_VAR(r15);
				PHALCON_CONCAT_BOTH(r15,  "'", r13, "'");
				phalcon_array_update(&values, i, r15, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
		}
		PHALCON_INIT_VAR(r17);
		phalcon_array_fetch(&r17, values, i, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(r16);
		PHALCON_CONCAT_VBOTH(r16, field, " = ", r17);
		phalcon_array_append(&update_values, r16, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_SEPARATE(i);
		increment_function(i);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_e7f0_2;
		fee_e7f0_2:
		if(0){ };
	}
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, ", ", 1);
	PHALCON_ALLOC_ZVAL_MM(r18);
	phalcon_fast_join(r18, c1, update_values TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r19);
	concat_function(r19, update_sql, r18 TSRMLS_CC);
	PHALCON_CPY_WRT(update_sql, r19);
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	PHALCON_INIT_VAR(r20);
	is_not_equal_function(r20, where_condition, t0 TSRMLS_CC);
	if (zend_is_true(r20)) {
		PHALCON_ALLOC_ZVAL_MM(r21);
		PHALCON_CONCAT_LEFT(r21, " WHERE ", where_condition);
		PHALCON_ALLOC_ZVAL_MM(r22);
		concat_function(r22, update_sql, r21 TSRMLS_CC);
		PHALCON_CPY_WRT(update_sql, r22);
	}
	PHALCON_ALLOC_ZVAL_MM(r23);
	PHALCON_CALL_METHOD_PARAMS_1(r23, this_ptr, "query", update_sql, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r23);
}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param string $whereCondition
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, delete){

	zval *table = NULL, *where_condition = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &where_condition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!where_condition) {
		PHALCON_INIT_VAR(where_condition);
		ZVAL_STRING(where_condition, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(where_condition);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "trim", where_condition, 0x011);
	Z_DELREF_P(where_condition);
	if (!PHALCON_COMPARE_STRING(r0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, "DELETE FROM ", table);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, " WHERE ", where_condition);
		PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "query", r2, PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_LEFT(r5, "DELETE FROM ", table);
		PHALCON_CALL_METHOD_PARAMS_1(r4, this_ptr, "query", r5, PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r4);
	}
	
	PHALCON_MM_RESTORE();
}

/**
     * Starts a transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, begin){

	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 0 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "BEGIN", 1);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "query", c0, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
     * Rollbacks the active transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, rollback){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "ROLLBACK", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "query", c0, PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
     * Commits the active transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, commit){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "COMMIT", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "query", c0, PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Manually sets a "under transaction" state for the connection
 *
 * @param boolean $underTransaction
 */
PHP_METHOD(Phalcon_Db, setUnderTransaction){

	zval *under_transaction = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &under_transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_underTransaction", strlen("_underTransaction"), under_transaction TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks whether connection is under database transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, isUnderTransaction){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Checks whether connection have auto commit
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, getHaveAutoCommit){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_autoCommit", sizeof("_autoCommit")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns database name in the internal connection
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getDatabaseName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "name", strlen("name") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "name", sizeof("name")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns active schema name in the internal connection
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getDefaultSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "schema", strlen("schema") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "schema", sizeof("schema")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_isset_property(t3, "name", strlen("name") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, t4, "name", sizeof("name")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(t5);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_STRING("", 1);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the username which has connected to the database
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getUsername){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "username", strlen("username") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "username", sizeof("username")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the username which has connected to the database
     *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getHostName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "host", sizeof("host")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets an active connection unique identifier
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getConnectionId){

	zval *as_string = NULL;
	zval *t0 = NULL;

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
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * This method is executed before every SQL statement sended to the database system
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db, _beforeQuery){

	zval *sql_statement = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "[", t2);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "] ", sql_statement);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_get_class_constant(t3, phalcon_logger_ce, "DEBUG", strlen("DEBUG") TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t1, "log", r0, t3, PHALCON_NO_CHECK);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t5, "startprofile", sql_statement, PHALCON_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * This method is executed after every SQL statement sended to the database system
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db, _afterQuery){

	zval *sql_statement = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t1, "stopprofile", sql_statement, PHALCON_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Instantiates Phalcon_Db adapter using given parameters
 *
 * @param string $adapterName
 * @param stdClass $options
 * @param boolean $persistent
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Db, factory){

	zval *adapter_name = NULL, *options = NULL, *persistent = NULL, *descriptor = NULL;
	zval *value = NULL, *key = NULL, *layer = NULL, *class_name = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
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
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &adapter_name, &options, &persistent) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!persistent) {
		PHALCON_INIT_VAR(persistent);
		ZVAL_BOOL(persistent, 0);
	}
	
	if (PHALCON_COMPARE_STRING(adapter_name, "")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "A valid adapter name is required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		if (Z_TYPE_P(options) != IS_OBJECT) {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_db_exception_ce);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "The parameter 'options' must be an Array or Object", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
			phalcon_throw_exception(i1 TSRMLS_CC);
			return;
		}
	}
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init(i2);
		PHALCON_CPY_WRT(descriptor, i2);
		if (phalcon_valid_foreach(options TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(options);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_e7f0_3:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_e7f0_3;
			} else {
				PHALCON_INIT_VAR(key);
				hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
				if (hash_type == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(key, hash_index, hash_index_len-1, 1);
				} else {
					if (hash_type == HASH_KEY_IS_LONG) {
						ZVAL_LONG(key, hash_num);
					}
				}
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval(descriptor, Z_STRVAL_P(key), Z_STRLEN_P(key), value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_e7f0_3;
			fee_e7f0_3:
			if(0){ };
		}
	} else {
		PHALCON_CPY_WRT(descriptor, options);
	}
	eval_int = phalcon_isset_property(descriptor, "layer", strlen("layer") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, descriptor, "layer", sizeof("layer")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(layer, t0);
	} else {
		PHALCON_INIT_VAR(layer);
		ZVAL_STRING(layer, "native", 1);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Db_Adapter_", adapter_name);
	PHALCON_CPY_WRT(class_name, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(class_name);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", class_name, 0x012);
	Z_DELREF_P(class_name);
	if (zend_is_true(r1)) {
		ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, ce0);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i3, "__construct", descriptor, persistent, PHALCON_CHECK);
		PHALCON_RETURN_CTOR(i3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i4);
		object_init_ex(i4, phalcon_db_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Database adapter class ", class_name, " was not found");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i4, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i4 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

