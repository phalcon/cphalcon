
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
 * <code>
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * $config = [
 *   'host'     => 'localhost',
 *   'dbname'   => 'blog',
 *   'port'     => 3306,
 *   'username' => 'sigma',
 *   'password' => 'secret'
 * ];
 *
 * $connection = new Mysql($config);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter, Pdo, phalcon, db_adapter_pdo, phalcon_db_adapter_ce, phalcon_db_adapter_pdo_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * PDO Handler
	 *
	 * @var \Pdo
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
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_ce, this_ptr, "__construct", &_0, 35, descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * This method is automatically called in \Phalcon\Db\Adapter\Pdo constructor.
 *
 * Call it when you need to restore a database connection.
 *
 *<code>
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * // Make a connection
 * $connection = new Mysql([
 *  'host'     => 'localhost',
 *  'username' => 'sigma',
 *  'password' => 'secret',
 *  'dbname'   => 'blog',
 *  'port'     => 3306,
 * ]);
 *
 * // Reconnect
 * $connection->connect();
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect) {

	HashTable *_3$$13;
	HashPosition _2$$13;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, *username = NULL, *password = NULL, *dsnParts = NULL, *dsnAttributes = NULL, *persistent = NULL, *options = NULL, *key = NULL, *value = NULL, *_6, *_7, *_8, *_9, *_0$$3, **_4$$13, *_5$$14 = NULL;
	zval *descriptor = NULL, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor_param);

	if (!descriptor_param) {
		ZEPHIR_INIT_VAR(descriptor);
		array_init(descriptor);
	} else {
		zephir_get_arrval(descriptor, descriptor_param);
	}


	if (ZEPHIR_IS_EMPTY(descriptor)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("_descriptor"), PH_NOISY_CC);
		zephir_get_arrval(_1$$3, _0$$3);
		ZEPHIR_CPY_WRT(descriptor, _1$$3);
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
			zephir_array_update_long(&options, 12, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
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
		zephir_is_iterable(descriptor, &_3$$13, &_2$$13, 0, 0, "phalcon/db/adapter/pdo.zep", 154);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$13, (void**) &_4$$13, &_2$$13) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$13, &_2$$13)
		) {
			ZEPHIR_GET_HMKEY(key, _3$$13, _2$$13);
			ZEPHIR_GET_HVALUE(value, _4$$13);
			ZEPHIR_INIT_LNVAR(_5$$14);
			ZEPHIR_CONCAT_VSV(_5$$14, key, "=", value);
			zephir_array_append(&dsnParts, _5$$14, PH_SEPARATE, "phalcon/db/adapter/pdo.zep", 152);
		}
		ZEPHIR_INIT_NVAR(dsnAttributes);
		zephir_fast_join_str(dsnAttributes, SL(";"), dsnParts TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 2);
	zephir_array_update_long(&options, 3, &_6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_INIT_VAR(_7);
	object_init_ex(_7, php_pdo_get_dbh_ce());
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_VSV(_9, _8, ":", dsnAttributes);
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 0, _9, username, password, options);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_pdo"), _7 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

/**
 * Returns a PDO prepared statement to be executed with 'executePrepared'
 *
 *<code>
 * use Phalcon\Db\Column;
 *
 * $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
 * $result = $connection->executePrepared($statement, ['name' => 'Voltron'], ['name' => Column::BIND_PARAM_INT]);
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
 * use Phalcon\Db\Column;
 *
 * $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
 * $result = $connection->executePrepared($statement, ['name' => 'Voltron'], ['name' => Column::BIND_PARAM_INT]);
 *</code>
 *
 * @param \PDOStatement statement
 * @param array placeholders
 * @param array dataTypes
 * @return \PDOStatement
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, executePrepared) {

	zval *_6$$13 = NULL;
	zend_bool _3$$3;
	HashTable *_1, *_9$$22, *_14$$28;
	HashPosition _0, _8$$22, _13$$28;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zval *placeholders = NULL;
	zval *statement, *placeholders_param = NULL, *dataTypes, *wildcard = NULL, *value = NULL, *type = NULL, *castValue = NULL, *parameter = NULL, *position = NULL, *itemValue = NULL, **_2, _4$$12 = zval_used_for_init, **_10$$22, *_11$$24 = NULL, *_12$$25 = NULL, **_15$$28, *_16$$29 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &statement, &placeholders_param, &dataTypes);

	placeholders = placeholders_param;


	zephir_is_iterable(placeholders, &_1, &_0, 0, 0, "phalcon/db/adapter/pdo.zep", 282);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(wildcard, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(wildcard) == IS_LONG) {
			ZEPHIR_INIT_NVAR(parameter);
			ZVAL_LONG(parameter, (zephir_get_numberval(wildcard) + 1));
		} else if (Z_TYPE_P(wildcard) == IS_STRING) {
			ZEPHIR_CPY_WRT(parameter, wildcard);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid bind parameter (1)", "phalcon/db/adapter/pdo.zep", 209);
			return;
		}
		_3$$3 = Z_TYPE_P(dataTypes) == IS_ARRAY;
		if (_3$$3) {
			ZEPHIR_OBS_NVAR(type);
			_3$$3 = zephir_array_isset_fetch(&type, dataTypes, wildcard, 0 TSRMLS_CC);
		}
		if (_3$$3) {
			if (ZEPHIR_IS_LONG(type, 32)) {
				ZEPHIR_INIT_NVAR(castValue);
				ZVAL_DOUBLE(castValue, zephir_get_doubleval(value));
				ZEPHIR_INIT_NVAR(type);
				ZVAL_LONG(type, 1024);
			} else {
				if (ZEPHIR_GLOBAL(db).force_casting) {
					if (Z_TYPE_P(value) != IS_ARRAY) {
						do {
							if (ZEPHIR_IS_LONG(type, 1)) {
								ZEPHIR_SINIT_NVAR(_4$$12);
								ZVAL_LONG(&_4$$12, 10);
								ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_5, 36, value, &_4$$12);
								zephir_check_call_status();
								break;
							}
							if (ZEPHIR_IS_LONG(type, 2)) {
								zephir_get_strval(_6$$13, value);
								ZEPHIR_CPY_WRT(castValue, _6$$13);
								break;
							}
							if (ZEPHIR_IS_LONG(type, 0)) {
								ZEPHIR_INIT_NVAR(castValue);
								ZVAL_NULL(castValue);
								break;
							}
							if (ZEPHIR_IS_LONG(type, 5)) {
								ZEPHIR_INIT_NVAR(castValue);
								ZVAL_BOOL(castValue, zephir_get_boolval(value));
								break;
							}
							ZEPHIR_CPY_WRT(castValue, value);
							break;
						} while(0);

					} else {
						ZEPHIR_CPY_WRT(castValue, value);
					}
				} else {
					ZEPHIR_CPY_WRT(castValue, value);
				}
			}
			if (Z_TYPE_P(castValue) != IS_ARRAY) {
				if (ZEPHIR_IS_LONG(type, 1024)) {
					ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_7, 0, parameter, castValue);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_7, 0, parameter, castValue, type);
					zephir_check_call_status();
				}
			} else {
				zephir_is_iterable(castValue, &_9$$22, &_8$$22, 0, 0, "phalcon/db/adapter/pdo.zep", 270);
				for (
				  ; zephir_hash_get_current_data_ex(_9$$22, (void**) &_10$$22, &_8$$22) == SUCCESS
				  ; zephir_hash_move_forward_ex(_9$$22, &_8$$22)
				) {
					ZEPHIR_GET_HMKEY(position, _9$$22, _8$$22);
					ZEPHIR_GET_HVALUE(itemValue, _10$$22);
					if (ZEPHIR_IS_LONG(type, 1024)) {
						ZEPHIR_INIT_LNVAR(_11$$24);
						ZEPHIR_CONCAT_VV(_11$$24, parameter, position);
						ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_7, 0, _11$$24, itemValue);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_LNVAR(_12$$25);
						ZEPHIR_CONCAT_VV(_12$$25, parameter, position);
						ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_7, 0, _12$$25, itemValue, type);
						zephir_check_call_status();
					}
				}
			}
		} else {
			if (Z_TYPE_P(value) != IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_7, 0, parameter, value);
				zephir_check_call_status();
			} else {
				zephir_is_iterable(value, &_14$$28, &_13$$28, 0, 0, "phalcon/db/adapter/pdo.zep", 278);
				for (
				  ; zephir_hash_get_current_data_ex(_14$$28, (void**) &_15$$28, &_13$$28) == SUCCESS
				  ; zephir_hash_move_forward_ex(_14$$28, &_13$$28)
				) {
					ZEPHIR_GET_HMKEY(position, _14$$28, _13$$28);
					ZEPHIR_GET_HVALUE(itemValue, _15$$28);
					ZEPHIR_INIT_LNVAR(_16$$29);
					ZEPHIR_CONCAT_VV(_16$$29, parameter, position);
					ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_7, 0, _16$$29, itemValue);
					zephir_check_call_status();
				}
			}
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
	zval *sqlStatement_param = NULL, *bindParams = NULL, *bindTypes = NULL, *eventsManager = NULL, *pdo = NULL, *statement = NULL, *_0, *_1$$3 = NULL, *_2$$3, *_3$$6 = NULL, *_4$$9;
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
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "db:beforeQuery", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, eventsManager, "fire", NULL, 0, _2$$3, this_ptr);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdo"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(pdo, _0);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&statement, pdo, "prepare", NULL, 0, sqlStatement);
		zephir_check_call_status();
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_3$$6, this_ptr, "executeprepared", NULL, 0, statement, bindParams, bindTypes);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(statement, _3$$6);
		}
	} else {
		ZEPHIR_CALL_METHOD(&statement, pdo, "query", NULL, 0, sqlStatement);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(statement) == IS_OBJECT) {
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_4$$9);
			ZVAL_STRING(_4$$9, "db:afterQuery", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _4$$9, this_ptr);
			zephir_check_temp_parameter(_4$$9);
			zephir_check_call_status();
		}
		object_init_ex(return_value, phalcon_db_result_pdo_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 37, this_ptr, statement, sqlStatement, bindParams, bindTypes);
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
	zval *sqlStatement_param = NULL, *bindParams = NULL, *bindTypes = NULL, *eventsManager = NULL, *affectedRows = NULL, *pdo = NULL, *newStatement = NULL, *statement = NULL, *_0, *_1$$3 = NULL, *_2$$3, *_3$$9;
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
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "db:beforeQuery", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, eventsManager, "fire", NULL, 0, _2$$3, this_ptr);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$3)) {
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
			ZEPHIR_INIT_VAR(_3$$9);
			ZVAL_STRING(_3$$9, "db:afterQuery", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _3$$9, this_ptr);
			zephir_check_temp_parameter(_3$$9);
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

	zval *pdo = NULL;


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
 *	$escapedTable = $connection->escapeIdentifier(['store', 'robots']);
 *</code>
 *
 * @param string identifier
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeIdentifier) {

	zval *identifier, *_0$$3, *_1$$3;

	zephir_fetch_params(0, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		zephir_array_fetch_long(&_0$$3, identifier, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo.zep", 434 TSRMLS_CC);
		zephir_array_fetch_long(&_1$$3, identifier, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo.zep", 434 TSRMLS_CC);
		ZEPHIR_CONCAT_SVSVS(return_value, "\"", _0$$3, "\".\"", _1$$3, "\"");
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

	HashTable *_3$$3;
	HashPosition _2$$3;
	int ZEPHIR_LAST_CALL_STATUS, setOrder = 0;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *boundSql = NULL, *placeHolders = NULL, *bindPattern = NULL, *matches = NULL, *placeMatch = NULL, *value = NULL, *_0, *_1 = NULL, **_4$$3, *_7$$3, *_5$$4, *_6$$6;
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
	ZEPHIR_MAKE_REF(matches);
	ZEPHIR_CALL_FUNCTION(&_1, "preg_match_all", NULL, 38, bindPattern, sql, matches, _0);
	ZEPHIR_UNREF(matches);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		zephir_is_iterable(matches, &_3$$3, &_2$$3, 0, 0, "phalcon/db/adapter/pdo.zep", 483);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(placeMatch, _4$$3);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch_long(&_5$$4, placeMatch, 1, PH_READONLY, "phalcon/db/adapter/pdo.zep", 470 TSRMLS_CC);
			if (!(zephir_array_isset_fetch(&value, params, _5$$4, 0 TSRMLS_CC))) {
				if (zephir_array_isset_long(placeMatch, 2)) {
					ZEPHIR_OBS_NVAR(value);
					zephir_array_fetch_long(&_6$$6, placeMatch, 2, PH_READONLY, "phalcon/db/adapter/pdo.zep", 472 TSRMLS_CC);
					if (!(zephir_array_isset_fetch(&value, params, _6$$6, 0 TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Matched parameter wasn't found in parameters list", "phalcon/db/adapter/pdo.zep", 473);
						return;
					}
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Matched parameter wasn't found in parameters list", "phalcon/db/adapter/pdo.zep", 476);
					return;
				}
			}
			zephir_array_append(&placeHolders, value, PH_SEPARATE, "phalcon/db/adapter/pdo.zep", 480);
		}
		ZEPHIR_INIT_VAR(_7$$3);
		ZVAL_STRING(_7$$3, "?", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&boundSql, "preg_replace", NULL, 39, bindPattern, _7$$3, sql);
		zephir_check_temp_parameter(_7$$3);
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
	zval *sequenceName = NULL, *pdo = NULL;

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

	int ZEPHIR_LAST_CALL_STATUS, transactionLevel = 0;
	zval *nesting_param = NULL, *pdo = NULL, *eventsManager = NULL, *savepointName = NULL, *_0, *_1$$4, *_2$$5, *_5$$6 = NULL, *_6$$7, *_7$$8;
	zend_bool nesting, _3$$6, _4$$6;

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
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(eventsManager, _1$$4);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_2$$5);
			ZVAL_STRING(_2$$5, "db:beginTransaction", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2$$5, this_ptr);
			zephir_check_temp_parameter(_2$$5);
			zephir_check_call_status();
		}
		ZEPHIR_RETURN_CALL_METHOD(pdo, "begintransaction", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_3$$6 = (transactionLevel) ? 1 : 0;
		if (_3$$6) {
			_3$$6 = nesting;
		}
		_4$$6 = _3$$6;
		if (_4$$6) {
			ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
			zephir_check_call_status();
			_4$$6 = zephir_is_true(_5$$6);
		}
		if (_4$$6) {
			_6$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(eventsManager, _6$$7);
			ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_7$$8);
				ZVAL_STRING(_7$$8, "db:createSavepoint", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _7$$8, this_ptr, savepointName);
				zephir_check_temp_parameter(_7$$8);
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

	int ZEPHIR_LAST_CALL_STATUS, transactionLevel = 0;
	zval *nesting_param = NULL, *pdo = NULL, *eventsManager = NULL, *savepointName = NULL, *_0, *_1$$5, *_2$$6, *_5$$7 = NULL, *_6$$8, *_7$$9;
	zend_bool nesting, _3$$7, _4$$7;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "There is no active transaction", "phalcon/db/adapter/pdo.zep", 597);
		return;
	}
	if (transactionLevel == 1) {
		_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(eventsManager, _1$$5);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_2$$6);
			ZVAL_STRING(_2$$6, "db:rollbackTransaction", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2$$6, this_ptr);
			zephir_check_temp_parameter(_2$$6);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
		ZEPHIR_RETURN_CALL_METHOD(pdo, "rollback", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_3$$7 = (transactionLevel) ? 1 : 0;
		if (_3$$7) {
			_3$$7 = nesting;
		}
		_4$$7 = _3$$7;
		if (_4$$7) {
			ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
			zephir_check_call_status();
			_4$$7 = zephir_is_true(_5$$7);
		}
		if (_4$$7) {
			ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
			zephir_check_call_status();
			_6$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(eventsManager, _6$$8);
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_7$$9);
				ZVAL_STRING(_7$$9, "db:rollbackSavepoint", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _7$$9, this_ptr, savepointName);
				zephir_check_temp_parameter(_7$$9);
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

	int ZEPHIR_LAST_CALL_STATUS, transactionLevel = 0;
	zval *nesting_param = NULL, *pdo = NULL, *eventsManager = NULL, *savepointName = NULL, *_0, *_1$$5, *_2$$6, *_5$$7 = NULL, *_6$$8, *_7$$9;
	zend_bool nesting, _3$$7, _4$$7;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "There is no active transaction", "phalcon/db/adapter/pdo.zep", 670);
		return;
	}
	if (transactionLevel == 1) {
		_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(eventsManager, _1$$5);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_2$$6);
			ZVAL_STRING(_2$$6, "db:commitTransaction", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2$$6, this_ptr);
			zephir_check_temp_parameter(_2$$6);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_transactionLevel") TSRMLS_CC));
		ZEPHIR_RETURN_CALL_METHOD(pdo, "commit", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_3$$7 = (transactionLevel) ? 1 : 0;
		if (_3$$7) {
			_3$$7 = nesting;
		}
		_4$$7 = _3$$7;
		if (_4$$7) {
			ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
			zephir_check_call_status();
			_4$$7 = zephir_is_true(_5$$7);
		}
		if (_4$$7) {
			_6$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(eventsManager, _6$$8);
			ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(_7$$9);
				ZVAL_STRING(_7$$9, "db:releaseSavepoint", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _7$$9, this_ptr, savepointName);
				zephir_check_temp_parameter(_7$$9);
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

	zval *pdo = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

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

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "errorinfo", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

