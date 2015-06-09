
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/pdo/php_pdo_driver.h"


/**
 * Phalcon\Db\Adapter\Pdo
 *
 * Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect to a database
 *
 *<code>
 *	$connection = new \Phalcon\Db\Adapter\Pdo\Mysql(array(
 *		'host' => '192.168.0.11',
 *		'username' => 'sigma',
 *		'password' => 'secret',
 *		'dbname' => 'blog',
 *		'port' => '3306'
 *	));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter, Pdo, phalcon, db_adapter_pdo, phalcon_db_adapter_ce, phalcon_db_adapter_pdo_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * PDO Handler
	 */
	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Last affected rows
	 */
	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_affectedRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, __construct) {

	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL;
	zval *descriptor = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &descriptor_param);

	descriptor = descriptor_param;



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0, descriptor);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_ce, this_ptr, "__construct", &_0, 79, descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection
 *
 *<code>
 * //Make a connection
 * $connection = new \Phalcon\Db\Adapter\Pdo\Mysql(array(
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
 * @param 	array descriptor
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *descriptor = NULL, *username = NULL, *password = NULL, *dsnParts, *dsnAttributes = NULL, *persistent, *options = NULL, *key = NULL, *value = NULL, **_2, *_3 = NULL, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor);

	if (!descriptor) {
		ZEPHIR_CPY_WRT(descriptor, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(descriptor);
	}


	if (Z_TYPE_P(descriptor) == IS_NULL) {
		ZEPHIR_OBS_NVAR(descriptor);
		zephir_read_property_this(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(username);
	if (zephir_array_isset_string_fetch(&username, descriptor, SS("username"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&descriptor, SS("username"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(username);
		ZVAL_NULL(username);
	}
	ZEPHIR_OBS_VAR(password);
	if (zephir_array_isset_string_fetch(&password, descriptor, SS("password"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&descriptor, SS("password"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(password);
		ZVAL_NULL(password);
	}
	ZEPHIR_OBS_VAR(options);
	if (zephir_array_isset_string_fetch(&options, descriptor, SS("options"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&descriptor, SS("options"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	ZEPHIR_OBS_VAR(persistent);
	if (zephir_array_isset_string_fetch(&persistent, descriptor, SS("persistent"), 0 TSRMLS_CC)) {
		if (zephir_is_true(persistent)) {
			zephir_array_update_long(&options, 12, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE, "phalcon/db/adapter/pdo.zep", 127);
		}
		zephir_array_unset_string(&descriptor, SS("persistent"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(descriptor, SS("dialectClass"))) {
		zephir_array_unset_string(&descriptor, SS("dialectClass"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(dsnAttributes);
	if (!(zephir_array_isset_string_fetch(&dsnAttributes, descriptor, SS("dsn"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(dsnParts);
		array_init(dsnParts);
		zephir_is_iterable(descriptor, &_1, &_0, 0, 0, "phalcon/db/adapter/pdo.zep", 147);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_VSV(_3, key, "=", value);
			zephir_array_append(&dsnParts, _3, PH_SEPARATE, "phalcon/db/adapter/pdo.zep", 145);
		}
		ZEPHIR_INIT_NVAR(dsnAttributes);
		zephir_fast_join_str(dsnAttributes, SL(";"), dsnParts TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 2);
	zephir_array_update_long(&options, 3, &_4, PH_COPY | PH_SEPARATE, "phalcon/db/adapter/pdo.zep", 150);
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, php_pdo_get_dbh_ce());
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_VSV(_3, _6, ":", dsnAttributes);
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 0, _3, username, password, options);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_pdo"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a PDO prepared statement to be executed with 'executePrepared'
 *
 *<code>
 * $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
 * $result = $connection->executePrepared($statement, array('name' => 'Voltron'));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, prepare) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement_param = NULL, *_0;
	zval *sqlStatement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlStatement_param);

	if (unlikely(Z_TYPE_P(sqlStatement_param) != IS_STRING && Z_TYPE_P(sqlStatement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlStatement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(sqlStatement_param) == IS_STRING)) {
		zephir_get_strval(sqlStatement, sqlStatement_param);
	} else {
		ZEPHIR_INIT_VAR(sqlStatement);
		ZVAL_EMPTY_STRING(sqlStatement);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "prepare", NULL, 0, sqlStatement);
	zephir_check_call_status();
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
 * @param \PDOStatement statement
 * @param array placeholders
 * @param array dataTypes
 * @return \PDOStatement
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, executePrepared) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _3;
	HashTable *_1;
	HashPosition _0;
	zval *placeholders = NULL;
	zval *statement, *placeholders_param = NULL, *dataTypes, *wildcard = NULL, *value = NULL, *type = NULL, *castValue = NULL, *parameter = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &statement, &placeholders_param, &dataTypes);

	placeholders = placeholders_param;



	zephir_is_iterable(placeholders, &_1, &_0, 0, 0, "phalcon/db/adapter/pdo.zep", 223);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(wildcard, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(wildcard) == IS_LONG) {
			ZEPHIR_INIT_NVAR(parameter);
			ZVAL_LONG(parameter, (zephir_get_numberval(wildcard) + 1));
		} else {
			if (Z_TYPE_P(wildcard) == IS_STRING) {
				ZEPHIR_CPY_WRT(parameter, wildcard);
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid bind parameter (1)", "phalcon/db/adapter/pdo.zep", 196);
				return;
			}
		}
		_3 = Z_TYPE_P(dataTypes) == IS_ARRAY;
		if (_3) {
			ZEPHIR_OBS_NVAR(type);
			_3 = zephir_array_isset_fetch(&type, dataTypes, wildcard, 0 TSRMLS_CC);
		}
		if (_3) {
			if (ZEPHIR_IS_LONG(type, 32)) {
				ZEPHIR_INIT_NVAR(castValue);
				ZVAL_DOUBLE(castValue, zephir_get_doubleval(value));
				ZEPHIR_INIT_NVAR(type);
				ZVAL_LONG(type, 1024);
			} else {
				ZEPHIR_CPY_WRT(castValue, value);
			}
			if (ZEPHIR_IS_LONG(type, 1024)) {
				ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_4, 0, parameter, castValue);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_4, 0, parameter, castValue, type);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_4, 0, parameter, value);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, statement, "execute", NULL, 0);
	zephir_check_call_status();
	RETVAL_ZVAL(statement, 1, 0);
	RETURN_MM();

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
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement_param = NULL, *bindParams = NULL, *bindTypes = NULL, *eventsManager = NULL, *pdo = NULL, *statement = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *sqlStatement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &bindParams, &bindTypes);

	if (unlikely(Z_TYPE_P(sqlStatement_param) != IS_STRING && Z_TYPE_P(sqlStatement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlStatement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(sqlStatement_param) == IS_STRING)) {
		zephir_get_strval(sqlStatement, sqlStatement_param);
	} else {
		ZEPHIR_INIT_VAR(sqlStatement);
		ZVAL_EMPTY_STRING(sqlStatement);
	}
	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_sqlStatement"), sqlStatement TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlVariables"), bindParams TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlBindTypes"), bindTypes TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "db:beforeQuery", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, eventsManager, "fire", NULL, 0, _2, this_ptr, bindParams);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdo"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(pdo, _0);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&statement, pdo, "prepare", NULL, 0, sqlStatement);
		zephir_check_call_status();
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_1, this_ptr, "executeprepared", NULL, 0, statement, bindParams, bindTypes);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(statement, _1);
		}
	} else {
		ZEPHIR_CALL_METHOD(&statement, pdo, "query", NULL, 0, sqlStatement);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(statement) == IS_OBJECT) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "db:afterQuery", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, bindParams);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		object_init_ex(return_value, phalcon_db_result_pdo_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 80, this_ptr, statement, sqlStatement, bindParams, bindTypes);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(statement);

}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server doesn't return any rows
 *
 *<code>
 *	//Inserting data
 *	$success = $connection->execute("INSERT INTO robots VALUES (1, 'Astro Boy')");
 *	$success = $connection->execute("INSERT INTO robots VALUES (?, ?)", array(1, 'Astro Boy'));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement_param = NULL, *bindParams = NULL, *bindTypes = NULL, *eventsManager = NULL, *affectedRows = NULL, *pdo = NULL, *newStatement = NULL, *statement = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *sqlStatement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &bindParams, &bindTypes);

	if (unlikely(Z_TYPE_P(sqlStatement_param) != IS_STRING && Z_TYPE_P(sqlStatement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlStatement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(sqlStatement_param) == IS_STRING)) {
		zephir_get_strval(sqlStatement, sqlStatement_param);
	} else {
		ZEPHIR_INIT_VAR(sqlStatement);
		ZVAL_EMPTY_STRING(sqlStatement);
	}
	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_sqlStatement"), sqlStatement TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlVariables"), bindParams TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_sqlBindTypes"), bindTypes TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "db:beforeQuery", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, eventsManager, "fire", NULL, 0, _2, this_ptr, bindParams);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(affectedRows);
	ZVAL_LONG(affectedRows, 0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdo"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(pdo, _0);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&statement, pdo, "prepare", NULL, 0, sqlStatement);
		zephir_check_call_status();
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&newStatement, this_ptr, "executeprepared", NULL, 0, statement, bindParams, bindTypes);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&affectedRows, newStatement, "rowcount", NULL, 0);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CALL_METHOD(&affectedRows, pdo, "exec", NULL, 0, sqlStatement);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(affectedRows) == IS_LONG) {
		zephir_update_property_this(this_ptr, SL("_affectedRows"), affectedRows TSRMLS_CC);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "db:afterQuery", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, bindParams);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns the number of affected rows by the lastest INSERT/UPDATE/DELETE executed in the database system
 *
 *<code>
 *	$connection->execute("DELETE FROM robots");
 *	echo $connection->affectedRows(), ' were deleted';
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows) {


	RETURN_MEMBER(this_ptr, "_affectedRows");

}

/**
 * Closes the active connection returning success. Phalcon automatically closes and destroys
 * active connections when the request ends
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, close) {

	zval *pdo;


	pdo = zephir_fetch_nproperty_this(this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_pdo"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	RETURN_BOOL(1);

}

/**
 * Escapes a column/table/schema name
 *
 *<code>
 *	$escapedTable = $connection->escapeIdentifier('robots');
 *	$escapedTable = $connection->escapeIdentifier(array('store', 'robots'));
 *</code>
 *
 * @param string identifier
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeIdentifier) {

	zval *identifier, *_0, *_1;

	zephir_fetch_params(0, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		zephir_array_fetch_long(&_0, identifier, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo.zep", 375 TSRMLS_CC);
		zephir_array_fetch_long(&_1, identifier, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo.zep", 375 TSRMLS_CC);
		ZEPHIR_CONCAT_SVSVS(return_value, "\"", _0, "\".\"", _1, "\"");
		return;
	}
	ZEPHIR_CONCAT_SVS(return_value, "\"", identifier, "\"");
	return;

}

/**
 * Escapes a value to avoid SQL injections according to the active charset in the connection
 *
 *<code>
 *	$escapedStr = $connection->escapeString('some dangerous value');
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "quote", NULL, 0, str);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Converts bound parameters such as :name: or ?1 into PDO bind params ?
 *
 *<code>
 * print_r($connection->convertBoundParams('SELECT * FROM robots WHERE name = :name:', array('Bender')));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, convertBoundParams) {

	HashTable *_3;
	HashPosition _2;
	int setOrder, ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *boundSql = NULL, *placeHolders, *bindPattern, *matches, *placeMatch = NULL, *value = NULL, *_0 = NULL, *_1 = NULL, **_4, *_5, *_6;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	if (unlikely(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(sql);
		ZVAL_EMPTY_STRING(sql);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(placeHolders);
	array_init(placeHolders);
	ZEPHIR_INIT_VAR(bindPattern);
	ZVAL_STRING(bindPattern, "/\\?([0-9]+)|:([a-zA-Z0-9_]+):/", 1);
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	setOrder = 2;
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, setOrder);
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&_1, "preg_match_all", NULL, 81, bindPattern, sql, matches, _0);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		zephir_is_iterable(matches, &_3, &_2, 0, 0, "phalcon/db/adapter/pdo.zep", 424);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(placeMatch, _4);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch_long(&_5, placeMatch, 1, PH_READONLY, "phalcon/db/adapter/pdo.zep", 411 TSRMLS_CC);
			if (!(zephir_array_isset_fetch(&value, params, _5, 0 TSRMLS_CC))) {
				if (zephir_array_isset_long(placeMatch, 2)) {
					ZEPHIR_OBS_NVAR(value);
					zephir_array_fetch_long(&_6, placeMatch, 2, PH_READONLY, "phalcon/db/adapter/pdo.zep", 413 TSRMLS_CC);
					if (!(zephir_array_isset_fetch(&value, params, _6, 0 TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Matched parameter wasn't found in parameters list", "phalcon/db/adapter/pdo.zep", 414);
						return;
					}
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Matched parameter wasn't found in parameters list", "phalcon/db/adapter/pdo.zep", 417);
					return;
				}
			}
			zephir_array_append(&placeHolders, value, PH_SEPARATE, "phalcon/db/adapter/pdo.zep", 421);
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "?", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&boundSql, "preg_replace", NULL, 82, bindPattern, _0, sql);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(boundSql, sql);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("sql"), &boundSql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("params"), &placeHolders, PH_COPY | PH_SEPARATE);
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
 * @param string sequenceName
 * @return int|boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, lastInsertId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequenceName = NULL, *pdo;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sequenceName);

	if (!sequenceName) {
		sequenceName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(pdo);
	zephir_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(pdo, "lastinsertid", NULL, 0, sequenceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Starts a transaction in the connection
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, begin) {

	int transactionLevel, ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, *pdo, *eventsManager = NULL, *savepointName = NULL, *_0, *_1, *_2 = NULL, *_5 = NULL;
	zend_bool nesting, _3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);

	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	ZEPHIR_OBS_VAR(pdo);
	zephir_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_transactionLevel"), PH_NOISY_CC);
	transactionLevel = zephir_get_intval(_0);
	if (transactionLevel == 1) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(eventsManager, _1);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "db:beginTransaction", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		ZEPHIR_RETURN_CALL_METHOD(pdo, "begintransaction", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_3 = (transactionLevel) ? 1 : 0;
		if (_3) {
			_3 = nesting;
		}
		_4 = _3;
		if (_4) {
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
			zephir_check_call_status();
			_4 = zephir_is_true(_5);
		}
		if (_4) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(eventsManager, _1);
			ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "db:createSavepoint", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, savepointName);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createsavepoint", NULL, 0, savepointName);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Rollbacks the active transaction in the connection
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, rollback) {

	int transactionLevel, ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, *pdo, *eventsManager = NULL, *savepointName = NULL, *_0, *_1, *_2 = NULL, *_5 = NULL;
	zend_bool nesting, _3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);

	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	ZEPHIR_OBS_VAR(pdo);
	zephir_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_transactionLevel"), PH_NOISY_CC);
	transactionLevel = zephir_get_intval(_0);
	if (!(transactionLevel)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "There is no active transaction", "phalcon/db/adapter/pdo.zep", 538);
		return;
	}
	if (transactionLevel == 1) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(eventsManager, _1);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "db:rollbackTransaction", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
		ZEPHIR_RETURN_CALL_METHOD(pdo, "rollback", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_3 = (transactionLevel) ? 1 : 0;
		if (_3) {
			_3 = nesting;
		}
		_4 = _3;
		if (_4) {
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
			zephir_check_call_status();
			_4 = zephir_is_true(_5);
		}
		if (_4) {
			ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
			zephir_check_call_status();
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(eventsManager, _1);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "db:rollbackSavepoint", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, savepointName);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
			}
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rollbacksavepoint", NULL, 0, savepointName);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	if (transactionLevel > 0) {
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Commits the active transaction in the connection
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, commit) {

	int transactionLevel, ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, *pdo, *eventsManager = NULL, *savepointName = NULL, *_0, *_1, *_2 = NULL, *_5 = NULL;
	zend_bool nesting, _3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);

	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	ZEPHIR_OBS_VAR(pdo);
	zephir_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_transactionLevel"), PH_NOISY_CC);
	transactionLevel = zephir_get_intval(_0);
	if (!(transactionLevel)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "There is no active transaction", "phalcon/db/adapter/pdo.zep", 612);
		return;
	}
	if (transactionLevel == 1) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(eventsManager, _1);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "db:commitTransaction", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
		ZEPHIR_RETURN_CALL_METHOD(pdo, "commit", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_3 = (transactionLevel) ? 1 : 0;
		if (_3) {
			_3 = nesting;
		}
		_4 = _3;
		if (_4) {
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
			zephir_check_call_status();
			_4 = zephir_is_true(_5);
		}
		if (_4) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(eventsManager, _1);
			ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "db:releaseSavepoint", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, savepointName);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
			}
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "releasesavepoint", NULL, 0, savepointName);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	if (transactionLevel > 0) {
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns the current transaction nesting level
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getTransactionLevel) {


	RETURN_MEMBER(this_ptr, "_transactionLevel");

}

/**
 * Checks whether the connection is under a transaction
 *
 *<code>
 *	$connection->begin();
 *	var_dump($connection->isUnderTransaction()); //true
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, isUnderTransaction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pdo;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(pdo);
	zephir_read_property_this(&pdo, this_ptr, SL("_pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(pdo) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(pdo, "intransaction", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Return internal PDO handler
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getInternalHandler) {


	RETURN_MEMBER(this_ptr, "_pdo");

}

/**
 * Return the error info, if any
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getErrorInfo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "errorinfo", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

