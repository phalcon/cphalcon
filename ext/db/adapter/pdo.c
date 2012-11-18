
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

#include "db/adapter/pdo_constants.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/file.h"

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
 * Phalcon\Db\Adapter\Pdo initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter, Pdo, db_adapter_pdo, "phalcon\\db\\adapter", phalcon_db_adapter_pdo_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_affectedRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo
 *
 * @param array $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, __construct){

	zval *descriptor;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(descriptor) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The descriptor must be an array");
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

	zval *descriptor = NULL, *username, *password, *dsn_parts;
	zval *value = NULL, *key = NULL, *dsn_attribute = NULL, *dot_comma, *dsn_attributes;
	zval *pdo_type, *dsn, *options, *persistent, *pdo;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type, eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!descriptor) {
		PHALCON_INIT_VAR(descriptor);
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

			PHALCON_INIT_NVAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);

			PHALCON_INIT_NVAR(dsn_attribute);
			PHALCON_CONCAT_VSV(dsn_attribute, key, "=", value);
			phalcon_array_append(&dsn_parts, dsn_attribute, 0 TSRMLS_CC);

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
	add_index_long(options, PDO_ATTR_ERRMODE, PDO_ERRMODE_EXCEPTION);
	add_index_long(options, PDO_ATTR_CASE, PDO_CASE_LOWER);
	add_index_long(options, PDO_ATTR_CURSOR, PDO_CURSOR_SCROLL);

	eval_int = phalcon_array_isset_string(descriptor, SS("persistent"));
	if (eval_int) {
		PHALCON_INIT_VAR(persistent);
		phalcon_array_fetch_string(&persistent, descriptor, SL("persistent"), PH_NOISY_CC);
		if (zend_is_true(persistent)) {
			phalcon_array_update_long_bool(&options, PDO_ATTR_PERSISTENT, 1, 0 TSRMLS_CC);
		}
	}

	ce0 = zend_fetch_class(SL("PDO"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(pdo);
	object_init_ex(pdo, ce0);
	PHALCON_CALL_METHOD_PARAMS_4_NORETURN(pdo, "__construct", dsn, username, password, options, PH_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_pdo"), pdo TSRMLS_CC);

	PHALCON_MM_RESTORE();}

/**
 * Executes a prepared statement binding
 *
 * @param \PDOStatement $statement
 * @param array $placeholders
 * @param array $dataTypes
 * @return \PDOStatement
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, _executePrepared){

	zval *statement = NULL, *placeholders = NULL, *data_types = NULL;
	zval *one, *value = NULL, *wildcard = NULL, *parameter = NULL, *type = NULL, *cast_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &statement, &placeholders, &data_types) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);

	if (!phalcon_valid_foreach(placeholders TSRMLS_CC)) {
		return;
	}

	ah0 = Z_ARRVAL_P(placeholders);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);

	ph_cycle_start_0:

		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}

		PHALCON_GET_FOREACH_KEY(wildcard, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);

		if (Z_TYPE_P(wildcard) == IS_LONG) {
			PHALCON_INIT_NVAR(parameter);
			phalcon_add_function(parameter, wildcard, one TSRMLS_CC);
		} else {
			if (Z_TYPE_P(wildcard) == IS_STRING) {
				PHALCON_CPY_WRT(parameter, wildcard);
			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid bind parameter");
				return;
			}
		}
		if (Z_TYPE_P(data_types) == IS_ARRAY) {
			eval_int = phalcon_array_isset(data_types, wildcard);
			if (eval_int) {

				/**
				 * The bind type is double so we try to get the double value
				 */
				PHALCON_INIT_NVAR(type);
				phalcon_array_fetch(&type, data_types, wildcard, PH_NOISY_CC);
				if (phalcon_compare_strict_long(type, 32 TSRMLS_CC)) {

					PHALCON_INIT_NVAR(cast_value);
					PHALCON_CALL_FUNC_PARAMS_1(cast_value, "doubleval", value);

					PHALCON_INIT_NVAR(type);
					ZVAL_LONG(type, 1024);
				} else {
					PHALCON_CPY_WRT(cast_value, value);
				}

				/**
				 * 1024 is ignore the bind type
				 */
				Z_SET_ISREF_P(cast_value);
				if (phalcon_compare_strict_long(type, 1024 TSRMLS_CC)) {
					PHALCON_CALL_METHOD_PARAMS_2_NORETURN(statement, "bindparam", parameter, cast_value, PH_NO_CHECK);
				} else {
					PHALCON_CALL_METHOD_PARAMS_3_NORETURN(statement, "bindparam", parameter, cast_value, type, PH_NO_CHECK);
				}
				Z_UNSET_ISREF_P(cast_value);

			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid bind type parameter");
				return;
			}
		} else {
			Z_SET_ISREF_P(value);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(statement, "bindparam", parameter, value, PH_NO_CHECK);
			Z_UNSET_ISREF_P(value);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;

	ph_cycle_end_0:

	PHALCON_CALL_METHOD_NORETURN(statement, "execute", PH_NO_CHECK);

	RETURN_CCTOR(statement);}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server is returning rows
 *
 *<code>
 *	//Querying data
 *	$resultset = $connection->query("SELECT * FROM robots WHERE type='mechanical'");</code>
 *	$resultset = $connection->query("SELECT * FROM robots WHERE type=?", array("mechanical"));
 *</code>
 *
 * @param  string $sqlStatement
 * @param  array $bindParams
 * @param  array $bindTypes
 * @return Phalcon\Db\ResultInterface
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, query){

	zval *sql_statement, *bind_params = NULL, *bind_types = NULL;
	zval *events_manager, *event_name = NULL, *status, *pdo;
	zval *statement = NULL, *pdo_result;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &sql_statement, &bind_params, &bind_types) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!bind_params) {
		PHALCON_INIT_NVAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_NVAR(bind_types);
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "db:beforeQuery", 1);
		phalcon_update_property_zval(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_sqlVariables"), bind_params TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_sqlBindTypes"), bind_types TSRMLS_CC);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, bind_params, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
		PHALCON_INIT_VAR(statement);
		PHALCON_CALL_METHOD_PARAMS_1(statement, pdo, "prepare", sql_statement, PH_NO_CHECK);
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			PHALCON_INIT_VAR(r0);
			PHALCON_CALL_METHOD_PARAMS_3(r0, this_ptr, "_executeprepared", statement, bind_params, bind_types, PH_NO_CHECK);
			PHALCON_CPY_WRT(statement, r0);
		}
	} else {
		PHALCON_INIT_NVAR(statement);
		PHALCON_CALL_METHOD_PARAMS_1(statement, pdo, "query", sql_statement, PH_NO_CHECK);
	}
	
	if (Z_TYPE_P(statement) == IS_OBJECT) {
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "db:afterQuery", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, bind_params, PH_NO_CHECK);
		}
	
		PHALCON_INIT_VAR(pdo_result);
		object_init_ex(pdo_result, phalcon_db_result_pdo_ce);
		PHALCON_CALL_METHOD_PARAMS_5_NORETURN(pdo_result, "__construct", this_ptr, statement, sql_statement, bind_params, bind_types, PH_CHECK);
	
		RETURN_CTOR(pdo_result);
	}
	
	
	RETURN_CCTOR(statement);
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
 * @param  array $dataTypes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute){

	zval *sql_statement, *bind_params = NULL, *bind_types = NULL;
	zval *events_manager, *event_name = NULL, *status, *pdo;
	zval *statement = NULL, *affected_rows = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &sql_statement, &bind_params, &bind_types) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!bind_params) {
		PHALCON_INIT_NVAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_NVAR(bind_types);
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "db:beforeQuery", 1);
		phalcon_update_property_zval(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, bind_params, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
		PHALCON_INIT_VAR(statement);
		PHALCON_CALL_METHOD_PARAMS_1(statement, pdo, "prepare", sql_statement, PH_NO_CHECK);
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			PHALCON_INIT_VAR(r0);
			PHALCON_CALL_METHOD_PARAMS_3(r0, this_ptr, "_executeprepared", statement, bind_params, bind_types, PH_NO_CHECK);
			PHALCON_CPY_WRT(statement, r0);
	
			PHALCON_INIT_VAR(affected_rows);
			PHALCON_CALL_METHOD(affected_rows, statement, "rowcount", PH_NO_CHECK);
		}
	} else {
		PHALCON_INIT_NVAR(affected_rows);
		PHALCON_CALL_METHOD_PARAMS_1(affected_rows, pdo, "exec", sql_statement, PH_NO_CHECK);
	}
	
	if (Z_TYPE_P(affected_rows) == IS_LONG) {
		phalcon_update_property_zval(this_ptr, SL("_affectedRows"), affected_rows TSRMLS_CC);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "db:afterQuery", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "fire", event_name, this_ptr, bind_params, PH_NO_CHECK);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
 *
 *<code>
 *	$connection->query("DELETE FROM robots");
 *	echo $connection->affectedRows(), ' were deleted';
 *</code>
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows){


	RETURN_MEMBER(this_ptr, "_affectedRows");
}

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon\Db\Pool
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, close){

	zval *pdo;

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
 * Escapes a column/table/schema name
 *
 * @param string $identifier
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeIdentifier){

	zval *identifier, *domain, *name, *escaped = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &identifier) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(identifier) == IS_ARRAY) { 
		PHALCON_INIT_VAR(domain);
		phalcon_array_fetch_long(&domain, identifier, 0, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(name);
		phalcon_array_fetch_long(&name, identifier, 1, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(escaped);
		PHALCON_CONCAT_SVSVS(escaped, "\"", domain, "\".\"", name, "\"");
	
		RETURN_CTOR(escaped);
	}
	
	PHALCON_INIT_NVAR(escaped);
	PHALCON_CONCAT_SVS(escaped, "\"", identifier, "\"");
	
	RETURN_CTOR(escaped);
}

/**
 * Escapes a value to avoid SQL injections
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeString){

	zval *str, *pdo, *quoted_str;

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
 * Bind params to a SQL statement
 *
 * @param string $sql
 * @param array $params
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, bindParams){

	zval *sql_statement, *params, *sql = NULL, *pdo, *bind_value = NULL;
	zval *index = NULL, *is_numeric = NULL, *value = NULL, *place_key = NULL, *replaced_sql = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_statement, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(params) == IS_ARRAY) { 
		if (phalcon_fast_count_ev(params TSRMLS_CC)) {
			PHALCON_CPY_WRT(sql, sql_statement);
	
			PHALCON_INIT_VAR(pdo);
			phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	
			if (!phalcon_valid_foreach(params TSRMLS_CC)) {
				return;
			}
	
			ah0 = Z_ARRVAL_P(params);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
			ph_cycle_start_0:
	
				if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
					goto ph_cycle_end_0;
				}
	
				PHALCON_GET_FOREACH_KEY(index, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(bind_value);
	
				PHALCON_INIT_NVAR(is_numeric);
				PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", bind_value);
				if (PHALCON_IS_TRUE(is_numeric)) {
					PHALCON_CPY_WRT(value, bind_value);
				} else {
					PHALCON_INIT_NVAR(value);
					PHALCON_CALL_METHOD_PARAMS_1(value, pdo, "quote", bind_value, PH_NO_CHECK);
				}
	
				/** 
				 * Handle long parameters as numeric placeholders: ?0, ?1
				 */
				if (Z_TYPE_P(index) == IS_LONG) {
					PHALCON_INIT_NVAR(place_key);
					PHALCON_CONCAT_SV(place_key, "?", index);
	
					PHALCON_INIT_NVAR(replaced_sql);
					phalcon_fast_str_replace(replaced_sql, place_key, value, sql TSRMLS_CC);
					PHALCON_CPY_WRT(sql, replaced_sql);
				} else {
					/** 
					 * Handle long parameters as string placeholders: :name:, :other:
					 */
					if (Z_TYPE_P(index) == IS_STRING) {
						PHALCON_INIT_NVAR(place_key);
						PHALCON_CONCAT_SVS(place_key, ":", index, ":");
	
						PHALCON_INIT_NVAR(replaced_sql);
						phalcon_fast_str_replace(replaced_sql, place_key, value, sql TSRMLS_CC);
						PHALCON_CPY_WRT(sql, replaced_sql);
					} else {
						PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid bind parameter");
						return;
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
	
			ph_cycle_end_0:
	
	
			RETURN_CCTOR(sql);
		}
	}
	
	RETURN_CCTOR(sql_statement);
}

/**
 * Converts bound params such as :name: or ?1 into PDO bind params ?
 *
 * @param string $sql
 * @param array $params
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, convertBoundParams){

	zval *sql, *params, *query_params = NULL, *placeholders;
	zval *matches, *set_order, *bind_pattern, *status = NULL;
	zval *place_match = NULL, *numeric_place = NULL, *value = NULL, *str_place = NULL;
	zval *question, *bound_sql = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(query_params);
	array_init(query_params);
	
	PHALCON_INIT_VAR(placeholders);
	array_init(placeholders);
	
	PHALCON_INIT_VAR(matches);
	
	PHALCON_INIT_VAR(set_order);
	ZVAL_LONG(set_order, 2);
	
	PHALCON_INIT_VAR(bind_pattern);
	ZVAL_STRING(bind_pattern, "/\\?([0-9]+)|:([a-zA-Z0-9_]+):/", 1);
	p0[0] = bind_pattern;
	p0[1] = sql;
	Z_SET_ISREF_P(matches);
	p0[2] = matches;
	p0[3] = set_order;
	
	PHALCON_INIT_VAR(r0);
	PHALCON_CALL_FUNC_PARAMS(r0, "preg_match_all", 4, p0);
	Z_UNSET_ISREF_P(p0[2]);
	PHALCON_CPY_WRT(status, r0);
	if (zend_is_true(status)) {
	
		if (!phalcon_valid_foreach(matches TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(matches);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_VALUE(place_match);
	
			PHALCON_INIT_NVAR(numeric_place);
			phalcon_array_fetch_long(&numeric_place, place_match, 1, PH_NOISY_CC);
			eval_int = phalcon_array_isset(params, numeric_place);
			if (eval_int) {
				PHALCON_INIT_NVAR(value);
				phalcon_array_fetch(&value, params, numeric_place, PH_NOISY_CC);
			} else {
				eval_int = phalcon_array_isset_long(place_match, 2);
				if (eval_int) {
					PHALCON_INIT_NVAR(str_place);
					phalcon_array_fetch_long(&str_place, place_match, 2, PH_NOISY_CC);
					eval_int = phalcon_array_isset(params, str_place);
					if (eval_int) {
						PHALCON_INIT_NVAR(value);
						phalcon_array_fetch(&value, params, str_place, PH_NOISY_CC);
					} else {
						PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Matched parameter wasn't found in parameters list");
						return;
					}
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Matched parameter wasn't found in parameters list");
					return;
				}
			}
	
			phalcon_array_append(&placeholders, value, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
	
		PHALCON_INIT_VAR(question);
		ZVAL_STRING(question, "?", 1);
	
		PHALCON_INIT_VAR(bound_sql);
		PHALCON_CALL_FUNC_PARAMS_3(bound_sql, "preg_replace", bind_pattern, question, sql);
	} else {
		PHALCON_CPY_WRT(bound_sql, sql);
	}
	
	PHALCON_INIT_NVAR(query_params);
	array_init(query_params);
	phalcon_array_update_string(&query_params, SL("sql"), &bound_sql, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&query_params, SL("params"), &placeholders, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	RETURN_CTOR(query_params);
}

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string $sequenceName
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, lastInsertId){

	zval *sequence_name = NULL, *pdo, *insert_id;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &sequence_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!sequence_name) {
		PHALCON_INIT_NVAR(sequence_name);
	}
	
	PHALCON_INIT_VAR(pdo);
	phalcon_read_property(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(insert_id);
	PHALCON_CALL_METHOD_PARAMS_1(insert_id, pdo, "lastinsertid", sequence_name, PH_NO_CHECK);
	
	RETURN_CCTOR(insert_id);
}

/**
 * Starts a transaction in the connection
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, begin){

	zval *pdo, *status;

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

	zval *pdo, *status;

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

	zval *pdo, *status;

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

	zval *pdo, *status;

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
 * @return \PDO
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getInternalHandler){

	zval *pdo;

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

	zval *table, *schema = NULL, *dialect, *fetch_assoc, *sql;
	zval *describe, *indexes, *index = NULL, *key_name = NULL, *empty_arr = NULL;
	zval *column_name = NULL, *index_objects, *index_columns = NULL;
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
		PHALCON_INIT_NVAR(schema);
	}
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(fetch_assoc);
	phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SS("FETCH_ASSOC") TSRMLS_CC);
	
	/** 
	 * Get the SQL required to describe indexes from the Dialect
	 */
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
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(index);
	
		PHALCON_INIT_NVAR(key_name);
		phalcon_array_fetch_string(&key_name, index, SL("key_name"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(indexes, key_name);
		if (!eval_int) {
			PHALCON_INIT_NVAR(empty_arr);
			array_init(empty_arr);
			phalcon_array_update_zval(&indexes, key_name, &empty_arr, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_INIT_NVAR(column_name);
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
	
		if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
			goto ph_cycle_end_1;
		}
	
		PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		PHALCON_GET_FOREACH_VALUE(index_columns);
	
		PHALCON_INIT_NVAR(index);
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

	zval *table, *schema = NULL, *dialect, *sql, *empty_arr, *references;
	zval *fetch_assoc, *describe, *reference = NULL, *constraint_name = NULL;
	zval *referenced_schema = NULL, *referenced_table = NULL;
	zval *reference_array = NULL, *column_name = NULL, *referenced_columns = NULL;
	zval *reference_objects, *array_reference = NULL;
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
		PHALCON_INIT_NVAR(schema);
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
	phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SS("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_assoc, PH_NO_CHECK);
	
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(reference);
	
		PHALCON_INIT_NVAR(constraint_name);
		phalcon_array_fetch_string(&constraint_name, reference, SL("constraint_name"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(references, constraint_name);
		if (!eval_int) {
			PHALCON_INIT_NVAR(referenced_schema);
			phalcon_array_fetch_string(&referenced_schema, reference, SL("referenced_table_schema"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(referenced_table);
			phalcon_array_fetch_string(&referenced_table, reference, SL("referenced_table_name"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(reference_array);
			array_init(reference_array);
			phalcon_array_update_string(&reference_array, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&reference_array, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&reference_array, SL("columns"), &empty_arr, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&reference_array, SL("referencedColumns"), &empty_arr, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&references, constraint_name, &reference_array, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_INIT_NVAR(column_name);
		phalcon_array_fetch_string(&column_name, reference, SL("column_name"), PH_NOISY_CC);
		phalcon_array_update_zval_string_append_multi_3(&references, constraint_name, SL("columns"), &column_name, 0 TSRMLS_CC);
	
		PHALCON_INIT_NVAR(referenced_columns);
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
	
		if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
			goto ph_cycle_end_1;
		}
	
		PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		PHALCON_GET_FOREACH_VALUE(array_reference);
	
		PHALCON_INIT_NVAR(referenced_schema);
		phalcon_array_fetch_string(&referenced_schema, array_reference, SL("referencedSchema"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, array_reference, SL("referencedTable"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(columns);
		phalcon_array_fetch_string(&columns, array_reference, SL("columns"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, array_reference, SL("referencedColumns"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(definition);
		array_init(definition);
		phalcon_array_update_string(&definition, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("columns"), &columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("referencedColumns"), &referenced_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(reference);
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

	zval *table_name, *schema_name = NULL, *dialect, *sql;
	zval *fetch_assoc, *describe, *first, *empty_arr;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_NVAR(schema_name);
	}
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "tableoptions", table_name, schema_name, PH_NO_CHECK);
	if (zend_is_true(sql)) {
		PHALCON_INIT_VAR(fetch_assoc);
		phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SS("FETCH_ASSOC") TSRMLS_CC);
	
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

/**
 * Return the default identity value to insert in an identity column
 *
 * @return Phalcon\Db\RawValue
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getDefaultIdValue){

	zval *null_value, *default_value;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(null_value);
	ZVAL_STRING(null_value, "null", 1);
	
	PHALCON_INIT_VAR(default_value);
	object_init_ex(default_value, phalcon_db_rawvalue_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(default_value, "__construct", null_value, PH_CHECK);
	
	RETURN_CTOR(default_value);
}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, supportSequences){


	RETURN_FALSE;
}

