
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"

/**
 * Phalcon\Db\Adapter\Pdo
 *
 * Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect to a database
 *
 *<code>
 *	$connection = new Phalcon\Db\Adapter\Pdo\Mysql(array(
 *		'host' => '192.168.0.11',
 *		'username' => 'sigma',
 *		'password' => 'secret',
 *		'dbname' => 'blog',
 *		'port' => '3306'
 *	));
 *</code>
 */


/**
 * Phalcon\Db\Adapter\Pdo initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter, Pdo, db_adapter_pdo, "phalcon\\db\\adapter", phalcon_db_adapter_pdo_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_affectedRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_adapter_pdo_ce, SL("_transactionLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

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

	phalcon_fetch_params(1, 1, 0, &descriptor);
	
	if (Z_TYPE_P(descriptor) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The descriptor must be an array");
		return;
	}
	phalcon_call_method_p1_noret(this_ptr, "connect", descriptor);
	phalcon_call_parent_p1_noret(this_ptr, phalcon_db_adapter_pdo_ce, "__construct", descriptor);
	
	PHALCON_MM_RESTORE();
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection
 *
 *<code>
 * //Make a connection
 * $connection = new Phalcon\Db\Adapter\Pdo\Mysql(array(
 *  'host' => '192.168.0.11',
 *  'username' => 'sigma',
 *  'password' => 'secret',
 *  'dbname' => 'blog',
 * ));
 *
 * //Reconnect
 * $connection->connect();
 * </code>
 *
 * @param 	array $descriptor
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect){

	zval *descriptor = NULL, *username = NULL, *password = NULL, *dsn_parts;
	zval *value = NULL, *key = NULL, *dsn_attribute = NULL, *dsn_attributes = NULL;
	zval *pdo_type, *dsn, *options = NULL, *persistent, *pdo;
	zend_class_entry *ce;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &descriptor) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!descriptor) {
		PHALCON_INIT_VAR(descriptor);
	} else {
		PHALCON_SEPARATE_PARAM(descriptor);
	}

	if (Z_TYPE_P(descriptor) == IS_NULL) {
		PHALCON_OBS_NVAR(descriptor);
		phalcon_read_property(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}

	/**
	 * Check for a username or use null as default
	 */
	if (phalcon_array_isset_string(descriptor, SS("username"))) {
		PHALCON_OBS_VAR(username);
		phalcon_array_fetch_string(&username, descriptor, SL("username"), PH_NOISY);
		phalcon_array_unset_string(&descriptor, SS("username"), PH_SEPARATE);
	} else {
		PHALCON_INIT_NVAR(username);
	}

	/**
	 * Check for a password or use null as default
	 */
	if (phalcon_array_isset_string(descriptor, SS("password"))) {
		PHALCON_OBS_VAR(password);
		phalcon_array_fetch_string(&password, descriptor, SL("password"), PH_NOISY);
		phalcon_array_unset_string(&descriptor, SS("password"), PH_SEPARATE);
	} else {
		PHALCON_INIT_NVAR(password);
	}

	/**
	 * Check if the developer has defined custom options or create one from scratch
	 */
	if (phalcon_array_isset_string(descriptor, SS("options"))) {
		PHALCON_OBS_VAR(options);
		phalcon_array_fetch_string(&options, descriptor, SL("options"), PH_NOISY);
		phalcon_array_unset_string(&descriptor, SS("options"), PH_SEPARATE);
	} else {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}

	/**
	 * Check if the user has defined a custom dsn
	 */
	if (!phalcon_array_isset_string(descriptor, SS("dsn"))) {

		PHALCON_INIT_VAR(dsn_parts);
		array_init(dsn_parts);

		if (!phalcon_is_iterable_ex(descriptor, &ah0, &hp0, 0, 0)) {
			return;
		}

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);

			PHALCON_INIT_NVAR(dsn_attribute);
			PHALCON_CONCAT_VSV(dsn_attribute, key, "=", value);
			phalcon_array_append(&dsn_parts, dsn_attribute, PH_SEPARATE);

			zend_hash_move_forward_ex(ah0, &hp0);
		}

		PHALCON_INIT_VAR(dsn_attributes);
		phalcon_fast_join_str(dsn_attributes, SL(";"), dsn_parts TSRMLS_CC);
	} else {
		PHALCON_OBS_NVAR(dsn_attributes);
		phalcon_array_fetch_string(&dsn_attributes, descriptor, SL("dsn"), PH_NOISY);
	}

	PHALCON_OBS_VAR(pdo_type);
	phalcon_read_property(&pdo_type, this_ptr, SL("_type"), PH_NOISY_CC);

	PHALCON_INIT_VAR(dsn);
	PHALCON_CONCAT_VSV(dsn, pdo_type, ":", dsn_attributes);

	/**
	 * Default options
	 */
	phalcon_array_update_long_long(&options, PDO_ATTR_ERRMODE, PDO_ERRMODE_EXCEPTION, PH_SEPARATE);
	//phalcon_array_update_long_long(&options, PDO_ATTR_CASE, PDO_CASE_LOWER, PH_SEPARATE);
	//phalcon_array_update_long_long(&options, PDO_ATTR_CURSOR, PDO_CURSOR_SCROLL, PH_SEPARATE);

	/**
	 * Check if the connection must be persistent
	 */
	if (phalcon_array_isset_string(descriptor, SS("persistent"))) {

		PHALCON_OBS_VAR(persistent);
		phalcon_array_fetch_string(&persistent, descriptor, SL("persistent"), PH_NOISY);
		if (zend_is_true(persistent)) {
			phalcon_array_update_long_bool(&options, PDO_ATTR_PERSISTENT, 1, PH_SEPARATE);
		}
	}

	/**
	 * Create the connection using PDO
	 */
	ce = zend_fetch_class(SL("PDO"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	PHALCON_INIT_VAR(pdo);
	object_init_ex(pdo, ce);
	phalcon_call_method_p4_noret(pdo, "__construct", dsn, username, password, options);

	phalcon_update_property_zval(this_ptr, SL("_pdo"), pdo TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Returns a PDO prepared statement to be executed with 'executePrepared'
 *
 *<code>
 * $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
 * $result = $connection->executePrepared($statement, array('name' => 'Voltron'));
 *</code>
 *
 * @param string $sqlStatement
 * @return \PDOStatement
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, prepare){

	zval *sql_statement, *pdo;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &sql_statement);
	
	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	phalcon_call_method_p1(return_value, pdo, "prepare", sql_statement);
	RETURN_MM();
}

/**
 * Executes a prepared statement binding. This function uses integer indexes starting from zero
 *
 *<code>
 * $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
 * $result = $connection->executePrepared($statement, array('name' => 'Voltron'));
 *</code>
 *
 * @param \PDOStatement $statement
 * @param array $placeholders
 * @param array $dataTypes
 * @return \PDOStatement
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, executePrepared){

	zval *statement = NULL, *placeholders = NULL, *data_types = NULL;
	zval *one, *value = NULL, *wildcard = NULL, *parameter = NULL, *type = NULL, *cast_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &statement, &placeholders, &data_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);

	if (!phalcon_is_iterable_ex(placeholders, &ah0, &hp0, 0, 0)) {
		return;
	}

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

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

			if (likely(phalcon_array_isset(data_types, wildcard))) {

				/**
				 * The bind type is double so we try to get the double value
				 */
				PHALCON_OBS_NVAR(type);
				phalcon_array_fetch(&type, data_types, wildcard, PH_NOISY);
				if (phalcon_compare_strict_long(type, 32 TSRMLS_CC)) {

					PHALCON_INIT_NVAR(cast_value);
					phalcon_cast(cast_value, value, IS_DOUBLE);

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
					phalcon_call_method_p2_noret(statement, "bindparam", parameter, cast_value);
				} else {
					phalcon_call_method_p3_noret(statement, "bindparam", parameter, cast_value, type);
				}
				Z_UNSET_ISREF_P(cast_value);

			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid bind type parameter");
				return;
			}
		} else {
			Z_SET_ISREF_P(value);
			phalcon_call_method_p2_noret(statement, "bindparam", parameter, value);
			Z_UNSET_ISREF_P(value);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	phalcon_call_method_noret(statement, "execute");

	RETURN_CCTOR(statement);
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server is returning rows
 *
 *<code>
 *	//Querying data
 *	$resultset = $connection->query("SELECT * FROM robots WHERE type='mechanical'");
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
	zval *statement = NULL, *new_statement;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &sql_statement, &bind_params, &bind_types);
	
	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	/** 
	 * Execute the beforeQuery event if a EventsManager is available
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "db:beforeQuery", 1);
		phalcon_update_property_this(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_sqlVariables"), bind_params TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_sqlBindTypes"), bind_types TSRMLS_CC);
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, bind_params);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(statement);
		phalcon_call_method_p1(statement, pdo, "prepare", sql_statement);
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			PHALCON_INIT_VAR(new_statement);
			phalcon_call_method_p3(new_statement, this_ptr, "executeprepared", statement, bind_params, bind_types);
			PHALCON_CPY_WRT(statement, new_statement);
		}
	} else {
		PHALCON_INIT_NVAR(statement);
		phalcon_call_method_p1(statement, pdo, "query", sql_statement);
	}
	
	/** 
	 * Execute the afterQuery event if a EventsManager is available
	 */
	if (likely(Z_TYPE_P(statement) == IS_OBJECT)) {
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "db:afterQuery", 1);
			phalcon_call_method_p3_noret(events_manager, "fire", event_name, this_ptr, bind_params);
		}
		object_init_ex(return_value, phalcon_db_result_pdo_ce);
		phalcon_call_method_p5_noret(return_value, "__construct", this_ptr, statement, sql_statement, bind_params, bind_types);
	
		RETURN_MM();
	}
	
	RETURN_CCTOR(statement);
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server doesn't return any row
 *
 *<code>
 *	//Inserting data
 *	$success = $connection->execute("INSERT INTO robots VALUES (1, 'Astro Boy')");
 *	$success = $connection->execute("INSERT INTO robots VALUES (?, ?)", array(1, 'Astro Boy'));
 *</code>
 *
 * @param  string $sqlStatement
 * @param  array $bindParams
 * @param  array $bindTypes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute){

	zval *sql_statement, *bind_params = NULL, *bind_types = NULL;
	zval *events_manager, *event_name = NULL, *status, *affected_rows = NULL;
	zval *pdo, *statement, *new_statement;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &sql_statement, &bind_params, &bind_types);
	
	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	/** 
	 * Execute the beforeQuery event if a EventsManager is available
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "db:beforeQuery", 1);
		phalcon_update_property_this(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_sqlVariables"), bind_params TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_sqlBindTypes"), bind_types TSRMLS_CC);
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, bind_params);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Initialize affected_rows to 0
	 */
	PHALCON_INIT_VAR(affected_rows);
	ZVAL_LONG(affected_rows, 0);
	
	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(bind_params) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(statement);
		phalcon_call_method_p1(statement, pdo, "prepare", sql_statement);
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			PHALCON_INIT_VAR(new_statement);
			phalcon_call_method_p3(new_statement, this_ptr, "executeprepared", statement, bind_params, bind_types);
	
			phalcon_call_method(affected_rows, new_statement, "rowcount");
		}
	} else {
		PHALCON_INIT_NVAR(affected_rows);
		phalcon_call_method_p1(affected_rows, pdo, "exec", sql_statement);
	}
	
	/** 
	 * Execute the afterQuery event if a EventsManager is available
	 */
	if (Z_TYPE_P(affected_rows) == IS_LONG) {
		phalcon_update_property_this(this_ptr, SL("_affectedRows"), affected_rows TSRMLS_CC);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "db:afterQuery", 1);
			phalcon_call_method_p3_noret(events_manager, "fire", event_name, this_ptr, bind_params);
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Returns the number of affected rows by the lastest INSERT/UPDATE/DELETE executed in the database system
 *
 *<code>
 *	$connection->execute("DELETE FROM robots");
 *	echo $connection->affectedRows(), ' were deleted';
 *</code>
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows){


	RETURN_MEMBER(this_ptr, "_affectedRows");
}

/**
 * Closes the active connection returning success. Phalcon automatically closes and destroys
 * active connections when the request ends
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, close){

	zval *pdo;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (likely(Z_TYPE_P(pdo) == IS_OBJECT)) {
		phalcon_update_property_null(this_ptr, SL("_pdo") TSRMLS_CC);
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_TRUE;
}

/**
 * Escapes a column/table/schema name
 *
 *<code>
 *	$escapedTable = $connection->escapeIdentifier('robots');
 *	$escapedTable = $connection->escapeIdentifier(array('store', 'robots'));
 *</code>
 *
 * @param string $identifier
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeIdentifier){

	zval *identifier, *domain, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &identifier);
	
	if (Z_TYPE_P(identifier) == IS_ARRAY) { 
		PHALCON_OBS_VAR(domain);
		phalcon_array_fetch_long(&domain, identifier, 0, PH_NOISY);
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_long(&name, identifier, 1, PH_NOISY);
		PHALCON_CONCAT_SVSVS(return_value, "\"", domain, "\".\"", name, "\"");
		RETURN_MM();
	}
	PHALCON_CONCAT_SVS(return_value, "\"", identifier, "\"");
	
	RETURN_MM();
}

/**
 * Escapes a value to avoid SQL injections according to the active charset in the connection
 *
 *<code>
 *	$escapedStr = $connection->escapeString('some dangerous value');
 *</code>
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeString){

	zval *str, *pdo;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &str);
	
	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	phalcon_call_method_p1(return_value, pdo, "quote", str);
	RETURN_MM();
}

/**
 * Converts bound parameters such as :name: or ?1 into PDO bind params ?
 *
 *<code>
 * print_r($connection->convertBoundParams('SELECT * FROM robots WHERE name = :name:', array('Bender')));
 *</code>
 *
 * @param string $sql
 * @param array $params
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, convertBoundParams){

	zval *sql, *params, *query_params, *placeholders;
	zval *matches, *set_order, *bind_pattern, *status;
	zval *place_match = NULL, *numeric_place = NULL, *value = NULL, *str_place = NULL;
	zval *question, *bound_sql = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &sql, &params);
	
	PHALCON_INIT_VAR(query_params);
	array_init(query_params);
	
	PHALCON_INIT_VAR(placeholders);
	array_init(placeholders);
	
	PHALCON_INIT_VAR(matches);
	
	PHALCON_INIT_VAR(set_order);
	ZVAL_LONG(set_order, 2);
	
	PHALCON_INIT_VAR(bind_pattern);
	ZVAL_STRING(bind_pattern, "/\\?([0-9]+)|:([a-zA-Z0-9_]+):/", 1);
	Z_SET_ISREF_P(matches);
	
	PHALCON_INIT_VAR(status);
	phalcon_call_func_p4(status, "preg_match_all", bind_pattern, sql, matches, set_order);
	Z_UNSET_ISREF_P(matches);
	if (zend_is_true(status)) {
	
		phalcon_is_iterable(matches, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(place_match);
	
			PHALCON_OBS_NVAR(numeric_place);
			phalcon_array_fetch_long(&numeric_place, place_match, 1, PH_NOISY);
			if (phalcon_array_isset(params, numeric_place)) {
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch(&value, params, numeric_place, PH_NOISY);
			} else {
				if (phalcon_array_isset_long(place_match, 2)) {
	
					PHALCON_OBS_NVAR(str_place);
					phalcon_array_fetch_long(&str_place, place_match, 2, PH_NOISY);
					if (phalcon_array_isset(params, str_place)) {
						PHALCON_OBS_NVAR(value);
						phalcon_array_fetch(&value, params, str_place, PH_NOISY);
					} else {
						PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Matched parameter wasn't found in parameters list");
						return;
					}
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Matched parameter wasn't found in parameters list");
					return;
				}
			}
	
			phalcon_array_append(&placeholders, value, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		PHALCON_INIT_VAR(question);
		ZVAL_STRING(question, "?", 1);
	
		PHALCON_INIT_VAR(bound_sql);
		phalcon_call_func_p3(bound_sql, "preg_replace", bind_pattern, question, sql);
	} else {
		PHALCON_CPY_WRT(bound_sql, sql);
	}
	
	/** 
	 * Returns an array with the processed SQL and parameters
	 */
	array_init_size(return_value, 2);
	phalcon_array_update_string(&return_value, SL("sql"), &bound_sql, PH_COPY | PH_SEPARATE);
	phalcon_array_update_string(&return_value, SL("params"), &placeholders, PH_COPY | PH_SEPARATE);
	
	RETURN_MM();
}

/**
 * Returns the insert id for the auto_increment/serial column inserted in the lastest executed SQL statement
 *
 *<code>
 * //Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     array("Astro Boy", 1952),
 *     array("name", "year")
 * );
 *
 * //Getting the generated id
 * $id = $connection->lastInsertId();
 *</code>
 *
 * @param string $sequenceName
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, lastInsertId){

	zval *sequence_name = NULL, *pdo;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &sequence_name);
	
	if (!sequence_name) {
		PHALCON_INIT_VAR(sequence_name);
	}
	
	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		RETURN_MM_FALSE;
	}
	
	phalcon_call_method_p1(return_value, pdo, "lastinsertid", sequence_name);
	RETURN_MM();
}

/**
 * Starts a transaction in the connection
 *
 * @param boolean $nesting
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, begin){

	zval *nesting = NULL, *pdo, *transaction_level, *events_manager = NULL;
	zval *event_name = NULL, *ntw_savepoint, *savepoint_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &nesting);
	
	if (!nesting) {
		PHALCON_INIT_VAR(nesting);
		ZVAL_BOOL(nesting, 1);
	}
	
	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Increase the transaction nesting level
	 */
	phalcon_property_incr(this_ptr, SL("_transactionLevel") TSRMLS_CC);
	
	/** 
	 * Check the transaction nesting level
	 */
	PHALCON_OBS_VAR(transaction_level);
	phalcon_read_property_this(&transaction_level, this_ptr, SL("_transactionLevel"), PH_NOISY_CC);
	if (PHALCON_IS_LONG(transaction_level, 1)) {
	
		PHALCON_OBS_VAR(events_manager);
		phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
		/** 
		 * Notify the events manager about the started transaction
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "db:beginTransaction", 1);
			phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
		}
	
		phalcon_call_method(return_value, pdo, "begintransaction");
		RETURN_MM();
	} else {
		if (zend_is_true(transaction_level)) {
			if (zend_is_true(nesting)) {
	
				PHALCON_INIT_VAR(ntw_savepoint);
				phalcon_call_method(ntw_savepoint, this_ptr, "isnestedtransactionswithsavepoints");
				if (zend_is_true(ntw_savepoint)) {
	
					PHALCON_OBS_NVAR(events_manager);
					phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
					PHALCON_INIT_VAR(savepoint_name);
					phalcon_call_method(savepoint_name, this_ptr, "getnestedtransactionsavepointname");
	
					/** 
					 * Notify the events manager about the created savepoint
					 */
					if (Z_TYPE_P(events_manager) == IS_OBJECT) {
						PHALCON_INIT_NVAR(event_name);
						ZVAL_STRING(event_name, "db:createSavepoint", 1);
						phalcon_call_method_p3_noret(events_manager, "fire", event_name, this_ptr, savepoint_name);
					}
	
					phalcon_call_method_p1(return_value, this_ptr, "createsavepoint", savepoint_name);
					RETURN_MM();
				}
			}
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Rollbacks the active transaction in the connection
 *
 * @param boolean $nesting
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, rollback){

	zval *nesting = NULL, *pdo, *transaction_level, *events_manager = NULL;
	zval *event_name = NULL, *ntw_savepoint, *savepoint_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &nesting);
	
	if (!nesting) {
		PHALCON_INIT_VAR(nesting);
		ZVAL_BOOL(nesting, 1);
	}
	
	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Check the transaction nesting level
	 */
	PHALCON_OBS_VAR(transaction_level);
	phalcon_read_property_this(&transaction_level, this_ptr, SL("_transactionLevel"), PH_NOISY_CC);
	if (!zend_is_true(transaction_level)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "There is no active transaction");
		return;
	}
	
	if (PHALCON_IS_LONG(transaction_level, 1)) {
	
		PHALCON_OBS_VAR(events_manager);
		phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
		/** 
		 * Notify the events manager about the rollbacked transaction
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "db:rollbackTransaction", 1);
			phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
		}
	
		/** 
		 * Reduce the transaction nesting level
		 */
		phalcon_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC);
		phalcon_call_method(return_value, pdo, "rollback");
		RETURN_MM();
	} else {
		if (zend_is_true(transaction_level)) {
			if (zend_is_true(nesting)) {
	
				PHALCON_INIT_VAR(ntw_savepoint);
				phalcon_call_method(ntw_savepoint, this_ptr, "isnestedtransactionswithsavepoints");
				if (zend_is_true(ntw_savepoint)) {
	
					PHALCON_OBS_NVAR(events_manager);
					phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
					PHALCON_INIT_VAR(savepoint_name);
					phalcon_call_method(savepoint_name, this_ptr, "getnestedtransactionsavepointname");
	
					/** 
					 * Notify the events manager about the rollbacked savepoint
					 */
					if (Z_TYPE_P(events_manager) == IS_OBJECT) {
						PHALCON_INIT_NVAR(event_name);
						ZVAL_STRING(event_name, "db:rollbackSavepoint", 1);
						phalcon_call_method_p3_noret(events_manager, "fire", event_name, this_ptr, savepoint_name);
					}
	
					/** 
					 * Reduce the transaction nesting level
					 */
					phalcon_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC);
					phalcon_call_method_p1(return_value, this_ptr, "rollbacksavepoint", savepoint_name);
					RETURN_MM();
				}
			}
		}
	}
	
	/** 
	 * Reduce the transaction nesting level
	 */
	if (PHALCON_GT_LONG(transaction_level, 0)) {
		phalcon_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Commits the active transaction in the connection
 *
 * @param boolean $nesting
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, commit){

	zval *nesting = NULL, *pdo, *transaction_level, *events_manager = NULL;
	zval *event_name = NULL, *ntw_savepoint, *savepoint_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &nesting);
	
	if (!nesting) {
		PHALCON_INIT_VAR(nesting);
		ZVAL_BOOL(nesting, 1);
	}
	
	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Check the transaction nesting level
	 */
	PHALCON_OBS_VAR(transaction_level);
	phalcon_read_property_this(&transaction_level, this_ptr, SL("_transactionLevel"), PH_NOISY_CC);
	if (!zend_is_true(transaction_level)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "There is no active transaction");
		return;
	}
	
	if (PHALCON_IS_LONG(transaction_level, 1)) {
	
		PHALCON_OBS_VAR(events_manager);
		phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
		/** 
		 * Notify the events manager about the commited transaction
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "db:commitTransaction", 1);
			phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
		}
	
		/** 
		 * Reduce the transaction nesting level
		 */
		phalcon_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC);
		phalcon_call_method(return_value, pdo, "commit");
		RETURN_MM();
	} else {
		if (zend_is_true(transaction_level)) {
			if (zend_is_true(nesting)) {
	
				/** 
				 * Check if the current database system supports nested transactions
				 */
				PHALCON_INIT_VAR(ntw_savepoint);
				phalcon_call_method(ntw_savepoint, this_ptr, "isnestedtransactionswithsavepoints");
				if (zend_is_true(ntw_savepoint)) {
	
					PHALCON_OBS_NVAR(events_manager);
					phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
					PHALCON_INIT_VAR(savepoint_name);
					phalcon_call_method(savepoint_name, this_ptr, "getnestedtransactionsavepointname");
	
					/** 
					 * Notify the events manager about the commited savepoint
					 */
					if (Z_TYPE_P(events_manager) == IS_OBJECT) {
						PHALCON_INIT_NVAR(event_name);
						ZVAL_STRING(event_name, "db:releaseSavepoint", 1);
						phalcon_call_method_p3_noret(events_manager, "fire", event_name, this_ptr, savepoint_name);
					}
	
					/** 
					 * Reduce the transaction nesting level
					 */
					phalcon_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC);
					phalcon_call_method_p1(return_value, this_ptr, "releasesavepoint", savepoint_name);
					RETURN_MM();
				}
			}
		}
	}
	
	/** 
	 * Reduce the transaction nesting level
	 */
	if (PHALCON_GT_LONG(transaction_level, 0)) {
		phalcon_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns the current transaction nesting level
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getTransactionLevel){


	RETURN_MEMBER(this_ptr, "_transactionLevel");
}

/**
 * Checks whether the connection is under a transaction
 *
 *<code>
 *	$connection->begin();
 *	var_dump($connection->isUnderTransaction()); //true
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, isUnderTransaction){

	zval *pdo;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (likely(Z_TYPE_P(pdo) == IS_OBJECT)) {
		phalcon_call_method(return_value, pdo, "intransaction");
		RETURN_MM();
	}
	
	RETURN_MM_FALSE;
}

/**
 * Return internal PDO handler
 *
 * @return \PDO
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getInternalHandler){

	zval *pdo;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(pdo);
	phalcon_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	RETURN_CCTOR(pdo);
}

