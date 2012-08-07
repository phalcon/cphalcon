
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

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Db
 *
 * Phalcon\Db and its related classes provide a simple SQL database interface for Phalcon Framework.
 * The Phalcon\Db is the basic class you use to connect your PHP application to an RDBMS.
 * There is a different adapter class for each brand of RDBMS.
 *
 * This component is intended to lower level database operations. If you want to interact with databases using
 * high level abstraction use Phalcon\Model.
 *
 * Phalcon\Db is an abstract class. You only can use it with a database adapter like Phalcon\Db\Adapter\Pdo
 *
 * 
 */

/**
 * Phalcon\Db constructor, this method should not be called directly. Use Phalcon\Db::factory instead
 *
 * @param stdClass $descriptor
 */
PHP_METHOD(Phalcon_Db, __construct){

	zval *descriptor = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_descriptor"), descriptor TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\db"), SL("_connectionConsecutive") TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	increment_function(t0);
	phalcon_update_static_property(SL("phalcon\\db"), SL("_connectionConsecutive"), t0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_connectionId"), t1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a logger class to log all SQL operations sent to database server
 *
 * @param Phalcon\Logger $logger
 */
PHP_METHOD(Phalcon_Db, setLogger){

	zval *logger = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &logger) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(logger) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Parameter \\$logger must be an Object");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_logger"), logger TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the active logger
 *
 * @return Phalcon\Logger
 */
PHP_METHOD(Phalcon_Db, getLogger){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_logger"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Sends arbitrary text to a related logger in the instance
 *
 * @param string $sqlStatement
 * @param int $type
 */
PHP_METHOD(Phalcon_Db, log){

	zval *sql_statement = NULL, *type = NULL, *logger = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_statement, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(logger);
	phalcon_read_property(&logger, this_ptr, SL("_logger"), PH_NOISY_CC);
	if (zend_is_true(logger)) {
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(logger, "log", sql_statement, type, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a database profiler to the connection
 *
 * @param Phalcon\Db\Profiler $profiler
 */
PHP_METHOD(Phalcon_Db, setProfiler){

	zval *profiler = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &profiler) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(profiler) == IS_OBJECT) {
		phalcon_update_property_zval(this_ptr, SL("_profiler"), profiler TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Profiler must be an object");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the first row in a SQL query result
 *
 * @param string $sqlQuery
 * @param int $fetchMode
 * @return array
 */
PHP_METHOD(Phalcon_Db, fetchOne){

	zval *sql_query = NULL, *fetch_mode = NULL, *result = NULL;
	zval *r0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &sql_query, &fetch_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!fetch_mode) {
		PHALCON_ALLOC_ZVAL_MM(fetch_mode);
		ZVAL_LONG(fetch_mode, 2);
	}
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_1(result, this_ptr, "query", sql_query, PH_NO_CHECK);
	if (Z_TYPE_P(result) == IS_OBJECT) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", fetch_mode, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, result, "fetcharray", PH_NO_CHECK);
		RETURN_CTOR(r0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Dumps the complete result of a query into an array
 *
 * @param string $sqlQuery
 * @param int $fetchMode
 * @return array
 */
PHP_METHOD(Phalcon_Db, fetchAll){

	zval *sql_query = NULL, *fetch_mode = NULL, *results = NULL, *result = NULL;
	zval *row = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &sql_query, &fetch_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!fetch_mode) {
		PHALCON_ALLOC_ZVAL_MM(fetch_mode);
		ZVAL_LONG(fetch_mode, 2);
	}
	
	PHALCON_INIT_VAR(results);
	array_init(results);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_1(result, this_ptr, "query", sql_query, PH_NO_CHECK);
	if (Z_TYPE_P(result) == IS_OBJECT) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", fetch_mode, PH_NO_CHECK);
		ws_e7f0_0:
			
			PHALCON_INIT_VAR(r0);
			PHALCON_CALL_METHOD(r0, result, "fetcharray", PH_NO_CHECK);
			PHALCON_CPY_WRT(row, r0);
			if (!zend_is_true(row)) {
				goto we_e7f0_0;
			}
			phalcon_array_append(&results, row, PH_SEPARATE TSRMLS_CC);
			goto ws_e7f0_0;
		we_e7f0_0:
		if(0){}
	}
	
	
	RETURN_CTOR(results);
}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * @param string $table
 * @param array $values
 * @param array $fields
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, insert){

	zval *table = NULL, *values = NULL, *fields = NULL, *placeholders = NULL, *value = NULL;
	zval *n = NULL, *comma = NULL, *joined_values = NULL, *insert_sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &table, &values, &fields) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(values);
	
	if (!fields) {
		PHALCON_ALLOC_ZVAL_MM(fields);
		ZVAL_NULL(fields);
	}
	
	if (Z_TYPE_P(values) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_count(r0, values TSRMLS_CC);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_db_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CONCAT_SVS(r1, "Unable to insert into ", table, " without data");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r1, PH_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
		
		PHALCON_INIT_VAR(placeholders);
		array_init(placeholders);
		if (phalcon_valid_foreach(values TSRMLS_CC)) {
			ALLOC_HASHTABLE(ah0);
			zend_hash_init(ah0, 0, NULL, NULL, 0);
			zend_hash_copy(ah0, Z_ARRVAL_P(values), NULL, NULL, sizeof(zval*));
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_e7f0_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_e7f0_1;
			} else {
				PHALCON_INIT_VAR(n);
				PHALCON_GET_FOREACH_KEY(n, ah0, hp0);
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			if (Z_TYPE_P(value) == IS_OBJECT) {
				PHALCON_INIT_VAR(r2);
				PHALCON_CALL_FUNC_PARAMS_1(r2, "strval", value);
				phalcon_array_append(&placeholders, r2, PH_SEPARATE TSRMLS_CC);
				PHALCON_SEPARATE_PARAM(values);
				phalcon_array_unset(values, n);
			} else {
				PHALCON_INIT_VAR(t0);
				ZVAL_STRING(t0, "?", 1);
				phalcon_array_append(&placeholders, t0, PH_SEPARATE TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_e7f0_1;
			fee_e7f0_1:
			zend_hash_destroy(ah0);
			efree(ah0);
		} else {
			return;
		}
		
		PHALCON_INIT_VAR(comma);
		ZVAL_STRING(comma, ", ", 1);
		
		PHALCON_INIT_VAR(joined_values);
		phalcon_fast_join(joined_values, comma, placeholders TSRMLS_CC);
		if (Z_TYPE_P(fields) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_fast_join(r3, comma, fields TSRMLS_CC);
			PHALCON_INIT_VAR(insert_sql);
			PHALCON_CONCAT_SVSVSVS(insert_sql, "INSERT INTO ", table, " (", r3, ") VALUES (", joined_values, ")");
		} else {
			PHALCON_INIT_VAR(insert_sql);
			PHALCON_CONCAT_SVSVS(insert_sql, "INSERT INTO ", table, " VALUES (", joined_values, ")");
		}
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD_PARAMS_2(r4, this_ptr, "execute", insert_sql, values, PH_NO_CHECK);
		RETURN_CTOR(r4);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The second parameter for insert isn't an Array");
	return;
}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * @param string $table
 * @param array $fields
 * @param array $values
 * @param string $whereCondition
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, update){

	zval *table = NULL, *fields = NULL, *values = NULL, *where_condition = NULL;
	zval *placeholders = NULL, *value = NULL, *n = NULL, *field = NULL, *set_clause = NULL;
	zval *update_sql = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &table, &fields, &values, &where_condition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(values);
	
	if (!where_condition) {
		PHALCON_ALLOC_ZVAL_MM(where_condition);
		ZVAL_NULL(where_condition);
	}
	
	PHALCON_INIT_VAR(placeholders);
	array_init(placeholders);
	if (phalcon_valid_foreach(values TSRMLS_CC)) {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(values), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e7f0_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_e7f0_2;
		} else {
			PHALCON_INIT_VAR(n);
			PHALCON_GET_FOREACH_KEY(n, ah0, hp0);
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		eval_int = phalcon_array_isset(fields, n);
		if (eval_int) {
			PHALCON_INIT_VAR(field);
			phalcon_array_fetch(&field, fields, n, PH_NOISY_CC);
			if (Z_TYPE_P(value) == IS_OBJECT) {
				PHALCON_INIT_VAR(r0);
				PHALCON_CONCAT_VSV(r0, field, " = ", value);
				phalcon_array_append(&placeholders, r0, PH_SEPARATE TSRMLS_CC);
				PHALCON_SEPARATE_PARAM(values);
				phalcon_array_unset(values, n);
			} else {
				PHALCON_INIT_VAR(r1);
				PHALCON_CONCAT_VS(r1, field, " = ?");
				phalcon_array_append(&placeholders, r1, PH_SEPARATE TSRMLS_CC);
			}
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The number of values in the update is not the same as fields");
			return;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_e7f0_2;
		fee_e7f0_2:
		zend_hash_destroy(ah0);
		efree(ah0);
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ", ", 1);
	
	PHALCON_INIT_VAR(set_clause);
	phalcon_fast_join(set_clause, c0, placeholders TSRMLS_CC);
	if (Z_TYPE_P(where_condition) != IS_NULL) {
		PHALCON_INIT_VAR(update_sql);
		PHALCON_CONCAT_SVSVSV(update_sql, "UPDATE ", table, " SET ", set_clause, " WHERE ", where_condition);
	} else {
		PHALCON_INIT_VAR(update_sql);
		PHALCON_CONCAT_SVSV(update_sql, "UPDATE ", table, " SET ", set_clause);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_2(r2, this_ptr, "execute", update_sql, values, PH_NO_CHECK);
	RETURN_CTOR(r2);
}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * @param  string $table
 * @param  string $whereCondition
 * @param  array $placeholders
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, delete){

	zval *table = NULL, *where_condition = NULL, *placeholders = NULL;
	zval *sql = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &table, &where_condition, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!where_condition) {
		PHALCON_ALLOC_ZVAL_MM(where_condition);
		ZVAL_NULL(where_condition);
	}
	
	if (!placeholders) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_CPY_WRT(placeholders, a0);
	}
	
	if (Z_TYPE_P(where_condition) != IS_NULL) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSV(sql, "DELETE FROM ", table, " WHERE ", where_condition);
	} else {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SV(sql, "DELETE FROM ", table);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "execute", sql, placeholders, PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Starts a transaction in the connection
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, begin){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_pdo"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, t0, "begintransaction", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Rollbacks the active transaction in the connection
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, rollback){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_pdo"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, t0, "rollback", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Commits the active transaction in the connection
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, commit){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_pdo"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, t0, "commit", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Checks whether connection is under database transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, isUnderTransaction){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_pdo"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, t0, "intransaction", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Return descriptor used to connect to the active database
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getDescriptor){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets the active connection unique identifier
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getConnectionId){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_connectionId"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * This method is executed before every SQL statement sent to the database system
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db, _beforeQuery){

	zval *sql_statement = NULL, *logger = NULL, *profiler = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(logger);
	phalcon_read_property(&logger, this_ptr, SL("_logger"), PH_NOISY_CC);
	if (zend_is_true(logger)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "getconnectionid", PH_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVSV(r1, "[", r0, "] ", sql_statement);
		PHALCON_INIT_VAR(c0);
		ZVAL_LONG(c0, 7);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(logger, "log", r1, c0, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(profiler);
	phalcon_read_property(&profiler, this_ptr, SL("_profiler"), PH_NOISY_CC);
	if (zend_is_true(profiler)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(profiler, "startprofile", sql_statement, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * This method is executed after every SQL statement sent to the database system
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db, _afterQuery){

	zval *sql_statement = NULL, *profiler = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(profiler);
	phalcon_read_property(&profiler, this_ptr, SL("_profiler"), PH_NOISY_CC);
	if (zend_is_true(profiler)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(profiler, "stopprofile", sql_statement, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Return internal PDO handler
 *
 * @return PDO
 */
PHP_METHOD(Phalcon_Db, getInternalHandler){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Instantiates a Phalcon\Db adapter using given parameters
 *
 * @param string $dbType
 * @param stdClass $descriptor
 * @return Phalcon\Db\Adapter\Pdo
 */
PHP_METHOD(Phalcon_Db, factory){

	zval *db_type = NULL, *descriptor = NULL, *object_descriptor = NULL;
	zval *dialect_class = NULL, *dialect = NULL, *adapter_class = NULL;
	zval *adapter = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &db_type, &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(descriptor);
	
	if (!zend_is_true(db_type)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "A valid adapter name is required");
		return;
	}
	if (Z_TYPE_P(descriptor) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_cast(r0, descriptor, IS_OBJECT);
		PHALCON_CPY_WRT(object_descriptor, r0);
	} else {
		PHALCON_CPY_WRT(object_descriptor, descriptor);
	}
	
	PHALCON_INIT_VAR(dialect_class);
	PHALCON_CONCAT_SV(dialect_class, "Phalcon\\Db\\Dialect\\", db_type);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", dialect_class);
	if (zend_is_true(r1)) {
		ce0 = phalcon_fetch_class(dialect_class TSRMLS_CC);
		PHALCON_INIT_VAR(dialect);
		object_init_ex(dialect, ce0);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dialect, "__construct", descriptor, PH_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SVS(r2, "Database dialect ", db_type, " doesn't exists");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_INIT_VAR(adapter_class);
	PHALCON_CONCAT_SV(adapter_class, "Phalcon\\Db\\Adapter\\Pdo\\", db_type);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "class_exists", adapter_class);
	if (zend_is_true(r3)) {
		ce1 = phalcon_fetch_class(adapter_class TSRMLS_CC);
		PHALCON_INIT_VAR(adapter);
		object_init_ex(adapter, ce1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(adapter, "__construct", dialect, descriptor, PH_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_SVS(r4, "Database adapter ", db_type, " doesn't exists");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r4, PH_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	
	RETURN_CTOR(adapter);
}

