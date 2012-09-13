
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

#include "db/adapter/pdo.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Db\Adapter\Pdo
 *
 * Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect to a database
 *
 * <code>
 * $connection = new Phalcon\Db\Adapter\Pdo\Mysql(array(
 *  'host' => '192.168.0.11',
 *  'username' => 'sigma',
 *  'password' => 'secret',
 *  'dbname' => 'blog',
 *  'port' => '3306',
 * ));
 * </code>
 */


/**
 * Constructor for Phalcon\Db\Adapter\Pdo
 *
 * @param array $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, __construct){

	zval *descriptor = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(descriptor) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "$descriptor must be an array");
		return;
	}
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "connect", descriptor, PH_NO_CHECK);
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Db\\Adapter\\Pdo", "__construct", descriptor);
	
	PHALCON_MM_RESTORE();
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection
 *
 * @param 	array $descriptor
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect){

zval *descriptor = NULL, *username = NULL, *password = NULL, *dsn_parts = NULL;
	zval *value = NULL, *key = NULL, *dsn_attribute = NULL, *dot_comma = NULL, *dsn_attributes = NULL;
	zval *pdo_type = NULL, *dsn = NULL, *options = NULL, *persistent = NULL, *pdo = NULL;
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

	if (Z_TYPE_P(descriptor) == IS_NULL) {
		PHALCON_INIT_VAR(descriptor);
		phalcon_read_property(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	eval_int = phalcon_array_isset_string(descriptor, SS("username"));
	if (eval_int) {
		PHALCON_INIT_VAR(username);
		phalcon_array_fetch_string(&username, descriptor, SL("username"), PH_NOISY_CC);
		PHALCON_SEPARATE_PARAM(descriptor);
		phalcon_array_unset_string(descriptor, SS("username"));
	} else {
		PHALCON_INIT_VAR(username);
		ZVAL_NULL(username);
	}

	eval_int = phalcon_array_isset_string(descriptor, SS("password"));
	if (eval_int) {
		PHALCON_INIT_VAR(password);
		phalcon_array_fetch_string(&password, descriptor, SL("password"), PH_NOISY_CC);
		PHALCON_SEPARATE_PARAM(descriptor);
		phalcon_array_unset_string(descriptor, SS("password"));
	} else {
		PHALCON_INIT_VAR(password);
		ZVAL_NULL(password);
	}

	eval_int = phalcon_array_isset_string(descriptor, SS("dsn"));
	if (!eval_int) {
		PHALCON_INIT_VAR(dsn_parts);
		array_init(dsn_parts);

		if (!phalcon_valid_foreach(descriptor TSRMLS_CC)) {
			return;
		}

		ah0 = Z_ARRVAL_P(descriptor);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);

		ph_cycle_start_0:

			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}

			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);

			PHALCON_INIT_VAR(dsn_attribute);
			PHALCON_CONCAT_VSV(dsn_attribute, key, "=", value);
			phalcon_array_append(&dsn_parts, dsn_attribute, PH_SEPARATE TSRMLS_CC);

			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;

		ph_cycle_end_0:

		PHALCON_INIT_VAR(dot_comma);
		ZVAL_STRING(dot_comma, ";", 1);

		PHALCON_INIT_VAR(dsn_attributes);
		phalcon_fast_join(dsn_attributes, dot_comma, dsn_parts TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(dsn_attributes);
		phalcon_array_fetch_string(&dsn_attributes, descriptor, SL("dsn"), PH_NOISY_CC);
	}

	PHALCON_INIT_VAR(pdo_type);
	phalcon_read_property(&pdo_type, this_ptr, SL("_type"), PH_NOISY_CC);

	PHALCON_INIT_VAR(dsn);
	PHALCON_CONCAT_VSV(dsn, pdo_type, ":", dsn_attributes);

	PHALCON_INIT_VAR(options);
	array_init(options);
	add_index_long(options, PDO_ATTR_ERRMODE, PDO_ERRMODE_SILENT);
	add_index_long(options, PDO_ATTR_CASE, PDO_CASE_LOWER);
	add_index_long(options, PDO_ATTR_CURSOR, PDO_CURSOR_SCROLL);
	eval_int = phalcon_array_isset_string(descriptor, SS("persistent"));
	if (eval_int) {
		PHALCON_INIT_VAR(persistent);
		phalcon_array_fetch_string(&persistent, descriptor, SL("persistent"), PH_NOISY_CC);
		if (zend_is_true(persistent)) {
			phalcon_array_update_long_bool(&options, PDO_ATTR_PERSISTENT, 1, PH_SEPARATE TSRMLS_CC);
		}
	}

	ce0 = zend_fetch_class(SL("PDO"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(pdo);
	object_init_ex(pdo, ce0);
	PHALCON_CALL_METHOD_PARAMS_4_NORETURN(pdo, "__construct", dsn, username, password, options, PH_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_pdo"), pdo TSRMLS_CC);

	PHALCON_MM_RESTORE();}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server return rows
 *
 *<code>
 *	//Querying data
 *	$resultset = $connection->query("SELECT * FROM robots WHERE type='mechanical'");</code>
 *	$resultset = $connection->query("SELECT * FROM robots WHERE type=?", array("mechanical"));
 *</code>
 *
 * @param  string $sqlStatement
 * @param  array $placeholders
 * @return Phalcon\Db\Result\Pdo
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, query){

	zval *sql_statement = NULL, *placeholders = NULL, *events_manager = NULL;
	zval *event_name = NULL, *status = NULL, *pdo = NULL, *statement = NULL, *value = NULL;
	zval *wildcard = NULL, *success = NULL, *pdo_result = NULL, *error_info = NULL;
	zval *error_message = NULL, *exception_message = NULL, *error_code = NULL;
	zval *exception = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &sql_statement, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!placeholders) {
		PHALCON_ALLOC_ZVAL_MM(placeholders);
		ZVAL_NULL(placeholders);
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "db:beforeQuery", 1);
		phalcon_update_property_zval(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(placeholders) == IS_ARRAY) { 
		PHALCON_INIT_VAR(statement);
		PHALCON_CALL_METHOD_PARAMS_1(statement, pdo, "prepare", sql_statement, PH_NO_CHECK);
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			
			if (!phalcon_valid_foreach(placeholders TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(placeholders);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			
			ph_cycle_start_0:
			
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto ph_cycle_end_0;
				}
				
				PHALCON_INIT_VAR(wildcard);
				PHALCON_GET_FOREACH_KEY(wildcard, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(value);
				
				if (Z_TYPE_P(wildcard) == IS_STRING) {
					PHALCON_CALL_METHOD_PARAMS_2_NORETURN(statement, "bindparam", wildcard, value, PH_NO_CHECK);
				} else {
					if (Z_TYPE_P(wildcard) == IS_LONG) {
						PHALCON_SEPARATE(wildcard);
						increment_function(wildcard);
						PHALCON_CALL_METHOD_PARAMS_2_NORETURN(statement, "bindparam", wildcard, value, PH_NO_CHECK);
					} else {
						PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid bind parameter");
						return;
					}
				}
				
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
			
			ph_cycle_end_0:
			
			PHALCON_INIT_VAR(success);
			PHALCON_CALL_METHOD(success, statement, "execute", PH_NO_CHECK);
		} else {
			PHALCON_INIT_VAR(success);
			ZVAL_BOOL(success, 0);
		}
	} else {
		PHALCON_INIT_VAR(success);
		ZVAL_BOOL(success, 1);
		
		PHALCON_INIT_VAR(statement);
		PHALCON_CALL_METHOD_PARAMS_1(statement, pdo, "query", sql_statement, PH_NO_CHECK);
	}
	
	if (PHALCON_IS_TRUE(success)) {
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "db:afterQuery", 1);
				
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
					PHALCON_MM_RESTORE();
					RETURN_FALSE;
				}
			}
			
			PHALCON_INIT_VAR(pdo_result);
			object_init_ex(pdo_result, phalcon_db_result_pdo_ce);
			PHALCON_CALL_METHOD_PARAMS_4_NORETURN(pdo_result, "__construct", this_ptr, statement, sql_statement, placeholders, PH_CHECK);
			
			RETURN_CTOR(pdo_result);
		}
	}
	
	PHALCON_INIT_VAR(error_info);
	PHALCON_CALL_METHOD(error_info, pdo, "errorinfo", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(error_message);
	phalcon_array_fetch_long(&error_message, error_info, 2, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_VSV(exception_message, error_message, " when executing ", sql_statement);
	
	PHALCON_INIT_VAR(error_code);
	phalcon_array_fetch_long(&error_code, error_info, 1, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_db_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(exception, "__construct", exception_message, error_code, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server don't return any row
 *
 *<code>
 *	//Inserting data
 *	$success = $connection->execute("INSERT INTO robots VALUES (1, 'Astro Boy')");
 *	$success = $connection->execute("INSERT INTO robots VALUES (?, ?)", array(1, 'Astro Boy'));
 *</code>
 *
 * @param  string $sqlStatement
 * @param  array $placeholders
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute){

	zval *sql_statement = NULL, *placeholders = NULL, *events_manager = NULL;
	zval *event_name = NULL, *status = NULL, *pdo = NULL, *statement = NULL, *value = NULL;
	zval *wildcard = NULL, *success = NULL, *affected_rows = NULL, *error_info = NULL;
	zval *error_message = NULL, *exception_message = NULL, *error_code = NULL;
	zval *exception = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &sql_statement, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!placeholders) {
		PHALCON_ALLOC_ZVAL_MM(placeholders);
		ZVAL_NULL(placeholders);
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "db:beforeQuery", 1);
		phalcon_update_property_zval(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(placeholders) == IS_ARRAY) { 
		PHALCON_INIT_VAR(statement);
		PHALCON_CALL_METHOD_PARAMS_1(statement, pdo, "prepare", sql_statement, PH_NO_CHECK);
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			
			if (!phalcon_valid_foreach(placeholders TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(placeholders);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			
			ph_cycle_start_0:
			
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto ph_cycle_end_0;
				}
				
				PHALCON_INIT_VAR(wildcard);
				PHALCON_GET_FOREACH_KEY(wildcard, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(value);
				
				if (Z_TYPE_P(wildcard) == IS_LONG) {
					PHALCON_SEPARATE(wildcard);
					increment_function(wildcard);
					PHALCON_CALL_METHOD_PARAMS_2_NORETURN(statement, "bindparam", wildcard, value, PH_NO_CHECK);
				} else {
					if (Z_TYPE_P(wildcard) == IS_STRING) {
						PHALCON_CALL_METHOD_PARAMS_2_NORETURN(statement, "bindparam", wildcard, value, PH_NO_CHECK);
					} else {
						PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid bind parameter");
						return;
					}
				}
				
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
			
			ph_cycle_end_0:
			
			PHALCON_INIT_VAR(success);
			PHALCON_CALL_METHOD(success, statement, "execute", PH_NO_CHECK);
			
			PHALCON_INIT_VAR(affected_rows);
			PHALCON_CALL_METHOD(affected_rows, statement, "rowcount", PH_NO_CHECK);
		} else {
			PHALCON_INIT_VAR(success);
			ZVAL_BOOL(success, 0);
		}
	} else {
		PHALCON_INIT_VAR(success);
		ZVAL_BOOL(success, 1);
		
		PHALCON_INIT_VAR(affected_rows);
		PHALCON_CALL_METHOD_PARAMS_1(affected_rows, pdo, "exec", sql_statement, PH_NO_CHECK);
	}
	
	if (zend_is_true(success)) {
		if (Z_TYPE_P(affected_rows) == IS_LONG) {
			phalcon_update_property_zval(this_ptr, SL("_affectedRows"), affected_rows TSRMLS_CC);
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "db:afterQuery", 1);
				
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
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
	
	PHALCON_INIT_VAR(error_message);
	phalcon_array_fetch_long(&error_message, error_info, 2, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_VSV(exception_message, error_message, " when executing ", sql_statement);
	
	PHALCON_INIT_VAR(error_code);
	phalcon_array_fetch_long(&error_code, error_info, 1, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_db_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(exception, "__construct", exception_message, error_code, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
}

/**
 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE repoted by the database system
 *
 *<code>
 *	$connection->query("DELETE FROM robots");
 *	echo $connection->affectedRows(), ' were deleted';
 *</code>
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows){

	zval *affected_rows = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(affected_rows);
	phalcon_read_property(&affected_rows, this_ptr, SL("_affectedRows"), PH_NOISY_CC);
	
	RETURN_CCTOR(affected_rows);
}

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon\Db\Pool
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, close){

	zval *pdo = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) == IS_OBJECT) {
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

	zval *str = NULL, *pdo = NULL, *quoted_str = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(quoted_str);
	PHALCON_CALL_METHOD_PARAMS_1(quoted_str, pdo, "quote", str, PH_NO_CHECK);
	
	RETURN_CCTOR(quoted_str);
}

/**
 * Bind params to SQL select
 *
 * @param string $sqlSelect
 * @param array $params
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, bindParams){

	zval *sql_select = NULL, *params = NULL, *number_params = NULL, *select = NULL;
	zval *pdo = NULL, *bind_value = NULL, *index = NULL, *is_numeric = NULL, *value = NULL;
	zval *place_key = NULL, *replaced_select = NULL;
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

	PHALCON_INIT_VAR(number_params);
	phalcon_fast_count(number_params, params TSRMLS_CC);
	if (zend_is_true(number_params)) {
		PHALCON_CPY_WRT(select, sql_select);
		
		PHALCON_INIT_VAR(pdo);
		phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
		
		if (!phalcon_valid_foreach(params TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_INIT_VAR(index);
			PHALCON_GET_FOREACH_KEY(index, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(bind_value);
			
			PHALCON_INIT_VAR(is_numeric);
			PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", bind_value);
			if (PHALCON_IS_TRUE(is_numeric)) {
				PHALCON_CPY_WRT(value, bind_value);
			} else {
				PHALCON_INIT_VAR(value);
				PHALCON_CALL_METHOD_PARAMS_1(value, pdo, "quote", bind_value, PH_NO_CHECK);
			}
			
			if (Z_TYPE_P(index) == IS_LONG) {
				PHALCON_INIT_VAR(place_key);
				PHALCON_CONCAT_SV(place_key, "?", index);
				
				PHALCON_INIT_VAR(replaced_select);
				phalcon_fast_str_replace(replaced_select, place_key, value, select TSRMLS_CC);
				PHALCON_CPY_WRT(select, replaced_select);
			} else {
				if (Z_TYPE_P(index) == IS_STRING) {
					PHALCON_INIT_VAR(place_key);
					PHALCON_CONCAT_SVS(place_key, ":", index, ":");
					
					PHALCON_INIT_VAR(replaced_select);
					phalcon_fast_str_replace(replaced_select, place_key, value, select TSRMLS_CC);
					PHALCON_CPY_WRT(select, replaced_select);
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid bind parameter");
					return;
				}
			}
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
		
		ph_cycle_end_0:
		
		
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
	zval *insert_id = NULL;

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
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(insert_id);
	PHALCON_CALL_METHOD(insert_id, pdo, "lastinsertid", PH_NO_CHECK);
	
	RETURN_CCTOR(insert_id);
}

/**
 * Starts a transaction in the connection
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, begin){

	zval *pdo = NULL, *status = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD(status, pdo, "begintransaction", PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Rollbacks the active transaction in the connection
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, rollback){

	zval *pdo = NULL, *status = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD(status, pdo, "rollback", PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Commits the active transaction in the connection
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, commit){

	zval *pdo = NULL, *status = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD(status, pdo, "commit", PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Checks whether connection is under database transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, isUnderTransaction){

	zval *pdo = NULL, *status = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD(status, pdo, "intransaction", PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Return internal PDO handler
 *
 * @return PDO
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getInternalHandler){

	zval *pdo = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
	RETURN_CCTOR(pdo);
}

/**
 * Lists table indexes
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Index[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, describeIndexes){

	zval *table = NULL, *schema = NULL, *dialect = NULL, *fetch_assoc = NULL, *sql = NULL;
	zval *describe = NULL, *indexes = NULL, *index = NULL, *key_name = NULL, *empty_arr = NULL;
	zval *column_name = NULL, *index_objects = NULL, *index_columns = NULL;
	zval *name = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(fetch_assoc);
	phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describeindexes", table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_assoc, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(indexes);
	array_init(indexes);
	
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(index);
		
		PHALCON_INIT_VAR(key_name);
		phalcon_array_fetch_string(&key_name, index, SL("key_name"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(indexes, key_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(empty_arr);
			array_init(empty_arr);
			phalcon_array_update_zval(&indexes, key_name, &empty_arr, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(column_name);
		phalcon_array_fetch_string(&column_name, index, SL("column_name"), PH_NOISY_CC);
		phalcon_array_update_append_multi_2(&indexes, key_name, column_name, 0 TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(index_objects);
	array_init(index_objects);
	
	if (!phalcon_valid_foreach(indexes TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(indexes);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_1:
	
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto ph_cycle_end_1;
		}
		
		PHALCON_INIT_VAR(name);
		PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		PHALCON_GET_FOREACH_VALUE(index_columns);
		
		PHALCON_INIT_VAR(index);
		object_init_ex(index, phalcon_db_index_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(index, "__construct", name, index_columns, PH_CHECK);
		phalcon_array_update_zval(&index_objects, name, &index, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	
	RETURN_CTOR(index_objects);
}

/**
 * Lists table references
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Reference[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, describeReferences){

	zval *table = NULL, *schema = NULL, *dialect = NULL, *sql = NULL, *empty_arr = NULL, *references = NULL;
	zval *fetch_assoc = NULL, *describe = NULL, *reference = NULL, *constraint_name = NULL;
	zval *referenced_schema = NULL, *referenced_table = NULL;
	zval *reference_array = NULL, *column_name = NULL, *referenced_columns = NULL;
	zval *reference_objects = NULL, *array_reference = NULL;
	zval *name = NULL, *columns = NULL, *definition = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describereferences", table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	
	PHALCON_INIT_VAR(references);
	array_init(references);
	
	PHALCON_INIT_VAR(fetch_assoc);
	phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_assoc, PH_NO_CHECK);
	
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(reference);
		
		PHALCON_INIT_VAR(constraint_name);
		phalcon_array_fetch_string(&constraint_name, reference, SL("constraint_name"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(references, constraint_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(referenced_schema);
			phalcon_array_fetch_string(&referenced_schema, reference, SL("referenced_table_schema"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(referenced_table);
			phalcon_array_fetch_string(&referenced_table, reference, SL("referenced_table_name"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(reference_array);
			array_init(reference_array);
			phalcon_array_update_string(&reference_array, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&reference_array, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&reference_array, SL("columns"), &empty_arr, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&reference_array, SL("referencedColumns"), &empty_arr, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&references, constraint_name, &reference_array, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(column_name);
		phalcon_array_fetch_string(&column_name, reference, SL("column_name"), PH_NOISY_CC);
		phalcon_array_update_zval_string_append_multi_3(&references, constraint_name, SL("columns"), &column_name, 0 TSRMLS_CC);
		
		PHALCON_INIT_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, reference, SL("referenced_column_name"), PH_NOISY_CC);
		phalcon_array_update_zval_string_append_multi_3(&references, constraint_name, SL("referencedColumns"), &referenced_columns, 0 TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(reference_objects);
	array_init(reference_objects);
	
	if (!phalcon_valid_foreach(references TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(references);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_1:
	
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto ph_cycle_end_1;
		}
		
		PHALCON_INIT_VAR(name);
		PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		PHALCON_GET_FOREACH_VALUE(array_reference);
		
		PHALCON_INIT_VAR(referenced_schema);
		phalcon_array_fetch_string(&referenced_schema, array_reference, SL("referencedSchema"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, array_reference, SL("referencedTable"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(columns);
		phalcon_array_fetch_string(&columns, array_reference, SL("columns"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, array_reference, SL("referencedColumns"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(definition);
		array_init(definition);
		phalcon_array_update_string(&definition, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("columns"), &columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("referencedColumns"), &referenced_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(reference);
		object_init_ex(reference, phalcon_db_reference_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(reference, "__construct", name, definition, PH_CHECK);
		phalcon_array_update_zval(&reference_objects, name, &reference, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	
	RETURN_CTOR(reference_objects);
}

/**
 * Gets creation options from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, tableOptions){

	zval *table_name = NULL, *schema_name = NULL, *dialect = NULL, *sql = NULL;
	zval *fetch_assoc = NULL, *describe = NULL, *first = NULL, *empty_arr = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_ALLOC_ZVAL_MM(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "tableoptions", table_name, schema_name, PH_NO_CHECK);
	if (zend_is_true(sql)) {
		PHALCON_INIT_VAR(fetch_assoc);
		phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
		
		PHALCON_INIT_VAR(describe);
		PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_assoc, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(first);
		phalcon_array_fetch_long(&first, describe, 0, PH_NOISY_CC);
		
		RETURN_CCTOR(first);
	}
	
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	
	RETURN_CTOR(empty_arr);
}

