
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Db\Adapter
 *
 * Base class for Phalcon\Db adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Adapter, phalcon, db_adapter, phalcon_db_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Event Manager
	 *
	 * @var Phalcon\Events\Manager
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Descriptor used to connect to a database
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_descriptor"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Name of the dialect used
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_dialectType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Type of database system the adapter is used for
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Dialect instance
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_dialect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active connection ID
	 *
	 * @var long
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_connectionId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL Statement
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL bound parameter variables
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL Bind Types
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlBindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Current transaction level
	 */
	zend_declare_property_long(phalcon_db_adapter_ce, SL("_transactionLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Whether the database supports transactions with save points
	 */
	zend_declare_property_bool(phalcon_db_adapter_ce, SL("_transactionsWithSavepoints"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Connection ID
	 */
	zend_declare_property_long(phalcon_db_adapter_ce, SL("_connectionConsecutive"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	phalcon_db_adapter_ce->create_object = zephir_init_properties_Phalcon_Db_Adapter;

	zend_class_implements(phalcon_db_adapter_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);
	zend_class_implements(phalcon_db_adapter_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Name of the dialect used
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialectType) {

	

	RETURN_MEMBER(getThis(), "_dialectType");

}

/**
 * Type of database system the adapter is used for
 */
PHP_METHOD(Phalcon_Db_Adapter, getType) {

	

	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Active SQL bound parameter variables
 */
PHP_METHOD(Phalcon_Db_Adapter, getSqlVariables) {

	

	RETURN_MEMBER(getThis(), "_sqlVariables");

}

/**
 * Phalcon\Db\Adapter constructor
 */
PHP_METHOD(Phalcon_Db_Adapter, __construct) {

	zend_class_entry *_5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, *dialectClass = NULL, *connectionId = NULL, *_0, *_1$$3, *_2$$3, *_3$$4, *_4$$4 = NULL;
	zval *descriptor = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &descriptor_param);

	descriptor = descriptor_param;


	ZEPHIR_OBS_VAR(connectionId);
	zephir_read_static_property_ce(&connectionId, phalcon_db_adapter_ce, SL("_connectionConsecutive") TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_connectionId"), connectionId TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, (zephir_get_numberval(connectionId) + 1));
	zephir_update_static_property_ce(phalcon_db_adapter_ce, SL("_connectionConsecutive"), &_0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(dialectClass);
	if (!(zephir_array_isset_string_fetch(&dialectClass, descriptor, SS("dialectClass"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dialectType"), PH_NOISY_CC);
		zephir_ucfirst(_1$$3, _2$$3);
		ZEPHIR_INIT_NVAR(dialectClass);
		ZEPHIR_CONCAT_SV(dialectClass, "Phalcon\\Db\\Dialect\\", _1$$3);
	}
	if (Z_TYPE_P(dialectClass) == IS_STRING) {
		ZEPHIR_INIT_VAR(_3$$4);
		zephir_fetch_safe_class(_4$$4, dialectClass);
			_5$$4 = zend_fetch_class(Z_STRVAL_P(_4$$4), Z_STRLEN_P(_4$$4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_3$$4, _5$$4);
		if (zephir_has_constructor(_3$$4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(getThis(), SL("_dialect"), _3$$4 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(dialectClass) == IS_OBJECT) {
			zephir_update_property_this(getThis(), SL("_dialect"), dialectClass TSRMLS_CC);
		}
	}
	zephir_update_property_this(getThis(), SL("_descriptor"), descriptor TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the event manager
 */
PHP_METHOD(Phalcon_Db_Adapter, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(getThis(), SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Db_Adapter, getEventsManager) {

	

	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Sets the dialect used to produce the SQL
 */
PHP_METHOD(Phalcon_Db_Adapter, setDialect) {

	zval *dialect;

	zephir_fetch_params(0, 1, 0, &dialect);



	zephir_update_property_this(getThis(), SL("_dialect"), dialect TSRMLS_CC);

}

/**
 * Returns internal dialect instance
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialect) {

	

	RETURN_MEMBER(getThis(), "_dialect");

}

/**
 * Returns the first row in a SQL query result
 *
 *<code>
 * // Getting first robot
 * $robot = $connection->fetchOne("SELECT * FROM robots");
 * print_r($robot);
 *
 * // Getting first robot with associative indexes only
 * $robot = $connection->fetchOne("SELECT * FROM robots", \Phalcon\Db::FETCH_ASSOC);
 * print_r($robot);
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchOne) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *fetchMode = NULL, *bindParams = NULL, *bindTypes = NULL, *result = NULL;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &sqlQuery_param, &fetchMode, &bindParams, &bindTypes);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}
	if (!fetchMode) {
		ZEPHIR_INIT_VAR(fetchMode);
		ZVAL_LONG(fetchMode, 2);
	}
	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&result, this_ptr, "query", NULL, 0, sqlQuery, bindParams, bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(result) == IS_OBJECT) {
		if (Z_TYPE_P(fetchMode) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, 0, fetchMode);
			zephir_check_call_status();
		}
		ZEPHIR_RETURN_CALL_METHOD(result, "fetch", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Dumps the complete result of a query into an array
 *
 *<code>
 * // Getting all robots with associative indexes only
 * $robots = $connection->fetchAll(
 *     "SELECT * FROM robots",
 *     \Phalcon\Db::FETCH_ASSOC
 * );
 *
 * foreach ($robots as $robot) {
 *     print_r($robot);
 * }
 *
 *  // Getting all robots that contains word "robot" withing the name
 * $robots = $connection->fetchAll(
 *     "SELECT * FROM robots WHERE name LIKE :name",
 *     \Phalcon\Db::FETCH_ASSOC,
 *     [
 *         "name" => "%robot%",
 *     ]
 * );
 * foreach($robots as $robot) {
 *     print_r($robot);
 * }
 *</code>
 *
 * @param string sqlQuery
 * @param int fetchMode
 * @param array bindParams
 * @param array bindTypes
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchAll) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *fetchMode = NULL, *bindParams = NULL, *bindTypes = NULL, *results = NULL, *result = NULL;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &sqlQuery_param, &fetchMode, &bindParams, &bindTypes);

	zephir_get_strval(sqlQuery, sqlQuery_param);
	if (!fetchMode) {
		ZEPHIR_INIT_VAR(fetchMode);
		ZVAL_LONG(fetchMode, 2);
	}
	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(results);
	array_init(results);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "query", NULL, 0, sqlQuery, bindParams, bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(result) == IS_OBJECT) {
		if (Z_TYPE_P(fetchMode) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, 0, fetchMode);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&results, result, "fetchall", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(results);

}

/**
 * Returns the n'th field of first row in a SQL query result
 *
 *<code>
 * // Getting count of robots
 * $robotsCount = $connection->fetchColumn("SELECT count(*) FROM robots");
 * print_r($robotsCount);
 *
 * // Getting name of last edited robot
 * $robot = $connection->fetchColumn(
 *     "SELECT id, name FROM robots order by modified desc",
 *     1
 * );
 * print_r($robot);
 *</code>
 *
 * @param  string sqlQuery
 * @param  array placeholders
 * @param  int|string column
 * @return string|
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchColumn) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery, *placeholders = NULL, *column = NULL, *row = NULL, *columnValue = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlQuery, &placeholders, &column);

	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}
	if (!column) {
		ZEPHIR_INIT_VAR(column);
		ZVAL_LONG(column, 0);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_CALL_METHOD(&row, this_ptr, "fetchone", NULL, 0, sqlQuery, _0, placeholders);
	zephir_check_call_status();
	_1 = !(ZEPHIR_IS_EMPTY(row));
	if (_1) {
		_1 = zephir_array_isset_fetch(&columnValue, row, column, 1 TSRMLS_CC);
	}
	if (_1) {
		RETURN_CTOR(columnValue);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Inserts data into a table using custom RDBMS SQL syntax
 *
 * <code>
 * // Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     ["Astro Boy", 1952],
 *     ["name", "year"]
 * );
 *
 * // Next SQL sentence is sent to the database system
 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
 * </code>
 *
 * @param   string|array table
 * @param 	array values
 * @param 	array fields
 * @param 	array dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, insert) {

	zval *_6$$5 = NULL, *_7$$7 = NULL;
	zend_bool _5$$4;
	HashTable *_3, *_11$$12;
	HashPosition _2, _10$$12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *table, *values_param = NULL, *fields = NULL, *dataTypes = NULL, *placeholders = NULL, *insertValues = NULL, *bindDataTypes = NULL, *bindType = NULL, *position = NULL, *value = NULL, *escapedTable = NULL, *joinedValues = NULL, *escapedFields = NULL, *field = NULL, *insertSql = NULL, **_4, *_0$$3, *_1$$3, *_8$$8 = NULL, *_9$$9 = NULL, **_12$$12, *_14$$12, *_13$$13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &table, &values_param, &fields, &dataTypes);

	values = values_param;
	if (!fields) {
		fields = ZEPHIR_GLOBAL(global_null);
	}
	if (!dataTypes) {
		dataTypes = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_db_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVS(_1$$3, "Unable to insert into ", table, " without data");
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 9, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/db/adapter.zep", 310 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(placeholders);
	array_init(placeholders);
	ZEPHIR_INIT_VAR(insertValues);
	array_init(insertValues);
	ZEPHIR_INIT_VAR(bindDataTypes);
	array_init(bindDataTypes);
	zephir_is_iterable(values, &_3, &_2, 0, 0, "phalcon/db/adapter.zep", 344);
	for (
	  ; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(position, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		_5$$4 = Z_TYPE_P(value) == IS_OBJECT;
		if (_5$$4) {
			_5$$4 = zephir_instance_of_ev(value, phalcon_db_rawvalue_ce TSRMLS_CC);
		}
		if (_5$$4) {
			zephir_get_strval(_6$$5, value);
			zephir_array_append(&placeholders, _6$$5, PH_SEPARATE, "phalcon/db/adapter.zep", 323);
		} else {
			if (Z_TYPE_P(value) == IS_OBJECT) {
				zephir_get_strval(_7$$7, value);
				ZEPHIR_CPY_WRT(value, _7$$7);
			}
			if (Z_TYPE_P(value) == IS_NULL) {
				ZEPHIR_INIT_NVAR(_8$$8);
				ZVAL_STRING(_8$$8, "null", 1);
				zephir_array_append(&placeholders, _8$$8, PH_SEPARATE, "phalcon/db/adapter.zep", 330);
			} else {
				ZEPHIR_INIT_NVAR(_9$$9);
				ZVAL_STRING(_9$$9, "?", 1);
				zephir_array_append(&placeholders, _9$$9, PH_SEPARATE, "phalcon/db/adapter.zep", 332);
				zephir_array_append(&insertValues, value, PH_SEPARATE, "phalcon/db/adapter.zep", 333);
				if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(bindType);
					if (!(zephir_array_isset_fetch(&bindType, dataTypes, position, 0 TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Incomplete number of bind types", "phalcon/db/adapter.zep", 336);
						return;
					}
					zephir_array_append(&bindDataTypes, bindType, PH_SEPARATE, "phalcon/db/adapter.zep", 338);
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(joinedValues);
	zephir_fast_join_str(joinedValues, SL(", "), placeholders TSRMLS_CC);
	ZEPHIR_INIT_VAR(insertSql);
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(escapedFields);
		array_init(escapedFields);
		zephir_is_iterable(fields, &_11$$12, &_10$$12, 0, 0, "phalcon/db/adapter.zep", 356);
		for (
		  ; zend_hash_get_current_data_ex(_11$$12, (void**) &_12$$12, &_10$$12) == SUCCESS
		  ; zend_hash_move_forward_ex(_11$$12, &_10$$12)
		) {
			ZEPHIR_GET_HVALUE(field, _12$$12);
			ZEPHIR_CALL_METHOD(&_13$$13, this_ptr, "escapeidentifier", NULL, 0, field);
			zephir_check_call_status();
			zephir_array_append(&escapedFields, _13$$13, PH_SEPARATE, "phalcon/db/adapter.zep", 353);
		}
		ZEPHIR_INIT_VAR(_14$$12);
		zephir_fast_join_str(_14$$12, SL(", "), escapedFields TSRMLS_CC);
		ZEPHIR_CONCAT_SVSVSVS(insertSql, "INSERT INTO ", escapedTable, " (", _14$$12, ") VALUES (", joinedValues, ")");
	} else {
		ZEPHIR_CONCAT_SVSVS(insertSql, "INSERT INTO ", escapedTable, " VALUES (", joinedValues, ")");
	}
	if (!(zephir_fast_count_int(bindDataTypes TSRMLS_CC))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, insertSql, insertValues);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, insertSql, insertValues, bindDataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * <code>
 * // Inserting a new robot
 * $success = $connection->insertAsDict(
 *     "robots",
 *     [
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *
 * // Next SQL sentence is sent to the database system
 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
 * </code>
 *
 * @param 	string table
 * @param 	array data
 * @param 	array dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, insertAsDict) {

	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, *data, *dataTypes = NULL, *values = NULL, *fields = NULL, *field = NULL, *value = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table, &data, &dataTypes);

	if (!dataTypes) {
		dataTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(data);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	zephir_is_iterable(data, &_2, &_1, 0, 0, "phalcon/db/adapter.zep", 407);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(field, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/db/adapter.zep", 403);
		zephir_array_append(&values, value, PH_SEPARATE, "phalcon/db/adapter.zep", 404);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "insert", NULL, 0, table, values, fields, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * <code>
 * // Updating existing robot
 * $success = $connection->update(
 *     "robots",
 *     ["name"],
 *     ["New Astro Boy"],
 *     "id = 101"
 * );
 *
 * // Next SQL sentence is sent to the database system
 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
 *
 * // Updating existing robot with array condition and $dataTypes
 * $success = $connection->update(
 *     "robots",
 *     ["name"],
 *     ["New Astro Boy"],
 *     [
 *         "conditions" => "id = ?",
 *         "bind"       => [$some_unsafe_id],
 *         "bindTypes"  => [PDO::PARAM_INT], // use only if you use $dataTypes param
 *     ],
 *     [
 *         PDO::PARAM_STR
 *     ]
 * );
 *
 * </code>
 *
 * Warning! If $whereCondition is string it not escaped.
 *
 * @param   string|array table
 * @param 	array fields
 * @param 	array values
 * @param 	string|array whereCondition
 * @param 	array dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, update) {

	zval *_5$$5 = NULL, *_7$$7 = NULL;
	zend_bool _4$$3;
	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, *fields, *values, *whereCondition = NULL, *dataTypes = NULL, *placeholders = NULL, *updateValues = NULL, *position = NULL, *value = NULL, *field = NULL, *bindDataTypes = NULL, *escapedField = NULL, *bindType = NULL, *escapedTable = NULL, *setClause = NULL, *updateSql = NULL, *conditions = NULL, *whereBind = NULL, *whereTypes = NULL, **_2, *_6$$5 = NULL, *_8$$8 = NULL, *_9$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &table, &fields, &values, &whereCondition, &dataTypes);

	if (!whereCondition) {
		whereCondition = ZEPHIR_GLOBAL(global_null);
	}
	if (!dataTypes) {
		dataTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(placeholders);
	array_init(placeholders);
	ZEPHIR_INIT_VAR(updateValues);
	array_init(updateValues);
	ZEPHIR_INIT_VAR(bindDataTypes);
	array_init(bindDataTypes);
	zephir_is_iterable(values, &_1, &_0, 0, 0, "phalcon/db/adapter.zep", 494);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(position, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_OBS_NVAR(field);
		if (!(zephir_array_isset_fetch(&field, fields, position, 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The number of values in the update is not the same as fields", "phalcon/db/adapter.zep", 468);
			return;
		}
		ZEPHIR_CALL_METHOD(&escapedField, this_ptr, "escapeidentifier", &_3, 0, field);
		zephir_check_call_status();
		_4$$3 = Z_TYPE_P(value) == IS_OBJECT;
		if (_4$$3) {
			_4$$3 = zephir_instance_of_ev(value, phalcon_db_rawvalue_ce TSRMLS_CC);
		}
		if (_4$$3) {
			zephir_get_strval(_5$$5, value);
			ZEPHIR_INIT_LNVAR(_6$$5);
			ZEPHIR_CONCAT_VSV(_6$$5, escapedField, " = ", _5$$5);
			zephir_array_append(&placeholders, _6$$5, PH_SEPARATE, "phalcon/db/adapter.zep", 473);
		} else {
			if (Z_TYPE_P(value) == IS_OBJECT) {
				zephir_get_strval(_7$$7, value);
				ZEPHIR_CPY_WRT(value, _7$$7);
			}
			if (Z_TYPE_P(value) == IS_NULL) {
				ZEPHIR_INIT_LNVAR(_8$$8);
				ZEPHIR_CONCAT_VS(_8$$8, escapedField, " = null");
				zephir_array_append(&placeholders, _8$$8, PH_SEPARATE, "phalcon/db/adapter.zep", 480);
			} else {
				zephir_array_append(&updateValues, value, PH_SEPARATE, "phalcon/db/adapter.zep", 482);
				if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(bindType);
					if (!(zephir_array_isset_fetch(&bindType, dataTypes, position, 0 TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Incomplete number of bind types", "phalcon/db/adapter.zep", 485);
						return;
					}
					zephir_array_append(&bindDataTypes, bindType, PH_SEPARATE, "phalcon/db/adapter.zep", 487);
				}
				ZEPHIR_INIT_LNVAR(_9$$9);
				ZEPHIR_CONCAT_VS(_9$$9, escapedField, " = ?");
				zephir_array_append(&placeholders, _9$$9, PH_SEPARATE, "phalcon/db/adapter.zep", 489);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", &_3, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(setClause);
	zephir_fast_join_str(setClause, SL(", "), placeholders TSRMLS_CC);
	ZEPHIR_INIT_VAR(updateSql);
	if (Z_TYPE_P(whereCondition) != IS_NULL) {
		ZEPHIR_CONCAT_SVSVS(updateSql, "UPDATE ", escapedTable, " SET ", setClause, " WHERE ");
		if (Z_TYPE_P(whereCondition) == IS_STRING) {
			zephir_concat_self(&updateSql, whereCondition TSRMLS_CC);
		} else {
			if (Z_TYPE_P(whereCondition) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid WHERE clause conditions", "phalcon/db/adapter.zep", 513);
				return;
			}
			ZEPHIR_OBS_VAR(conditions);
			if (zephir_array_isset_string_fetch(&conditions, whereCondition, SS("conditions"), 0 TSRMLS_CC)) {
				zephir_concat_self(&updateSql, conditions TSRMLS_CC);
			}
			ZEPHIR_OBS_VAR(whereBind);
			if (zephir_array_isset_string_fetch(&whereBind, whereCondition, SS("bind"), 0 TSRMLS_CC)) {
				zephir_merge_append(updateValues, whereBind);
			}
			ZEPHIR_OBS_VAR(whereTypes);
			if (zephir_array_isset_string_fetch(&whereTypes, whereCondition, SS("bindTypes"), 0 TSRMLS_CC)) {
				zephir_merge_append(bindDataTypes, whereTypes);
			}
		}
	} else {
		ZEPHIR_CONCAT_SVSV(updateSql, "UPDATE ", escapedTable, " SET ", setClause);
	}
	if (!(zephir_fast_count_int(bindDataTypes TSRMLS_CC))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, updateSql, updateValues);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, updateSql, updateValues, bindDataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates data on a table using custom RBDM SQL syntax
 * Another, more convenient syntax
 *
 * <code>
 * // Updating existing robot
 * $success = $connection->updateAsDict(
 *     "robots",
 *     [
 *         "name" => "New Astro Boy",
 *     ],
 *     "id = 101"
 * );
 *
 * // Next SQL sentence is sent to the database system
 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
 * </code>
 *
 * @param 	string table
 * @param 	array data
 * @param 	string whereCondition
 * @param 	array dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, updateAsDict) {

	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, *data, *whereCondition = NULL, *dataTypes = NULL, *values = NULL, *fields = NULL, *field = NULL, *value = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &table, &data, &whereCondition, &dataTypes);

	if (!whereCondition) {
		whereCondition = ZEPHIR_GLOBAL(global_null);
	}
	if (!dataTypes) {
		dataTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(data);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	zephir_is_iterable(data, &_2, &_1, 0, 0, "phalcon/db/adapter.zep", 589);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(field, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/db/adapter.zep", 585);
		zephir_array_append(&values, value, PH_SEPARATE, "phalcon/db/adapter.zep", 586);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "update", NULL, 0, table, fields, values, whereCondition, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * <code>
 * // Deleting existing robot
 * $success = $connection->delete(
 *     "robots",
 *     "id = 101"
 * );
 *
 * // Next SQL sentence is generated
 * DELETE FROM `robots` WHERE `id` = 101
 * </code>
 *
 * @param  string|array table
 * @param  string whereCondition
 * @param  array placeholders
 * @param  array dataTypes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, *whereCondition = NULL, *placeholders = NULL, *dataTypes = NULL, *sql = NULL, *escapedTable = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &table, &whereCondition, &placeholders, &dataTypes);

	if (!whereCondition) {
		whereCondition = ZEPHIR_GLOBAL(global_null);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}
	if (!dataTypes) {
		dataTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	if (!(ZEPHIR_IS_EMPTY(whereCondition))) {
		ZEPHIR_CONCAT_SVSV(sql, "DELETE FROM ", escapedTable, " WHERE ", whereCondition);
	} else {
		ZEPHIR_CONCAT_SV(sql, "DELETE FROM ", escapedTable);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, sql, placeholders, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Escapes a column/table/schema name
 *
 *<code>
 * $escapedTable = $connection->escapeIdentifier(
 *     "robots"
 * );
 *
 * $escapedTable = $connection->escapeIdentifier(
 *     [
 *         "store",
 *         "robots",
 *     ]
 * );
 *</code>
 *
 * @param array|string identifier
 */
PHP_METHOD(Phalcon_Db_Adapter, escapeIdentifier) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, *_0$$3, *_1$$3 = NULL, *_2$$3, *_3$$3, *_4$$3 = NULL, *_5$$3, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
		zephir_array_fetch_long(&_2$$3, identifier, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 651 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_1$$3, _0$$3, "escape", NULL, 0, _2$$3);
		zephir_check_call_status();
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
		zephir_array_fetch_long(&_5$$3, identifier, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 651 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "escape", NULL, 0, _5$$3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, _1$$3, ".", _4$$3);
		RETURN_MM();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_6, "escape", NULL, 0, identifier);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a list of columns
 *
 * @param	array columnList
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnList) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnList, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columnList);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getcolumnlist", NULL, 0, columnList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * <code>
 * echo $connection->limit("SELECT * FROM robots", 5);
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter, limit) {

	zend_long number, ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *number_param = NULL, *_0, *_1;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}
	number = zephir_get_intval(number_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, number);
	ZEPHIR_RETURN_CALL_METHOD(_0, "limit", NULL, 0, sqlQuery, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 *<code>
 * var_dump(
 *     $connection->tableExists("blog", "posts")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, tableExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, *_4;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}


	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "tableexists", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchone", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, _0, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 691 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(_4, 0));

}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 *<code>
 * var_dump(
 *     $connection->viewExists("active_users", "posts")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, viewExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *viewName_param = NULL, *schemaName_param = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, *_4;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}


	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "viewexists", NULL, 0, viewName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchone", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, _0, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 705 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(_4, 0));

}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 */
PHP_METHOD(Phalcon_Db_Adapter, forUpdate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *_0;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "forupdate", NULL, 0, sqlQuery);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 */
PHP_METHOD(Phalcon_Db_Adapter, sharedLock) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *_0;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "sharedlock", NULL, 0, sqlQuery);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a table
 */
PHP_METHOD(Phalcon_Db_Adapter, createTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *columns = NULL, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	definition = definition_param;


	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter.zep", 732);
		return;
	}
	if (!(zephir_fast_count_int(columns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter.zep", 736);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "createtable", NULL, 0, tableName, schemaName, definition);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a table from a schema/database
 */
PHP_METHOD(Phalcon_Db_Adapter, dropTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *_0, *_1 = NULL, *_2;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		ifExists = zephir_get_boolval(ifExists_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	if (ifExists) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, _0, "droptable", NULL, 0, tableName, schemaName, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a view
 */
PHP_METHOD(Phalcon_Db_Adapter, createView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, *_0, *_1 = NULL;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	definition = definition_param;
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}


	if (!(zephir_array_isset_string(definition, SS("sql")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter.zep", 756);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "createview", NULL, 0, viewName, definition, schemaName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a view
 */
PHP_METHOD(Phalcon_Db_Adapter, dropView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *_0, *_1 = NULL, *_2;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		ifExists = zephir_get_boolval(ifExists_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	if (ifExists) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, _0, "dropview", NULL, 0, viewName, schemaName, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a column to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "addcolumn", NULL, 0, tableName, schemaName, column);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter, modifyColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (!currentColumn) {
		currentColumn = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "modifycolumn", NULL, 0, tableName, schemaName, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a column from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL, *columnName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	zephir_get_strval(columnName, columnName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "dropcolumn", NULL, 0, tableName, schemaName, columnName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds an index to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "addindex", NULL, 0, tableName, schemaName, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drop an index from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "dropindex", NULL, 0, tableName, schemaName, indexName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a primary key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "addprimarykey", NULL, 0, tableName, schemaName, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a table's primary key
 */
PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "dropprimarykey", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a foreign key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "addforeignkey", NULL, 0, tableName, schemaName, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, *_0, *_1 = NULL;
	zval *tableName = NULL, *schemaName = NULL, *referenceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(referenceName);
		ZVAL_EMPTY_STRING(referenceName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "dropforeignkey", NULL, 0, tableName, schemaName, referenceName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the SQL column definition from a column
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * List all tables on a database
 *
 *<code>
 * print_r(
 *     $connection->listTables("blog")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, listTables) {

	HashTable *_5;
	HashPosition _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schemaName_param = NULL, *table = NULL, *allTables = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, *_7$$3;
	zval *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}


	ZEPHIR_INIT_VAR(allTables);
	array_init(allTables);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "listtables", NULL, 0, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter.zep", 867);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(table, _6);
		zephir_array_fetch_long(&_7$$3, table, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 865 TSRMLS_CC);
		zephir_array_append(&allTables, _7$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 865);
	}
	RETURN_CCTOR(allTables);

}

/**
 * List all views on a database
 *
 *<code>
 * print_r(
 *     $connection->listViews("blog")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, listViews) {

	HashTable *_5;
	HashPosition _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schemaName_param = NULL, *table = NULL, *allTables = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, *_7$$3;
	zval *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}


	ZEPHIR_INIT_VAR(allTables);
	array_init(allTables);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "listviews", NULL, 0, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter.zep", 887);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(table, _6);
		zephir_array_fetch_long(&_7$$3, table, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 885 TSRMLS_CC);
		zephir_array_append(&allTables, _7$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 885);
	}
	RETURN_CCTOR(allTables);

}

/**
 * Lists table indexes
 *
 *<code>
 * print_r(
 *     $connection->describeIndexes("robots_parts")
 * );
 *</code>
 *
 * @param	string table
 * @param	string schema
 * @return	Phalcon\Db\Index[]
 */
PHP_METHOD(Phalcon_Db_Adapter, describeIndexes) {

	HashTable *_5, *_9;
	HashPosition _4, _8;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *indexes = NULL, *index = NULL, *keyName = NULL, *indexObjects = NULL, *name = NULL, *indexColumns = NULL, *columns = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, **_10, *_7$$3, *_11$$6 = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_INIT_VAR(indexes);
	array_init(indexes);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describeindexes", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter.zep", 921);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(index, _6);
		zephir_array_fetch_long(&keyName, index, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 910 TSRMLS_CC);
		if (!(zephir_array_isset(indexes, keyName))) {
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
		} else {
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch(&columns, indexes, keyName, PH_NOISY, "phalcon/db/adapter.zep", 914 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_7$$3, index, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 917 TSRMLS_CC);
		zephir_array_append(&columns, _7$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 917);
		zephir_array_update_zval(&indexes, keyName, &columns, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(indexObjects);
	array_init(indexObjects);
	zephir_is_iterable(indexes, &_9, &_8, 0, 0, "phalcon/db/adapter.zep", 930);
	for (
	  ; zend_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zend_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HMKEY(name, _9, _8);
		ZEPHIR_GET_HVALUE(indexColumns, _10);
		ZEPHIR_INIT_NVAR(_11$$6);
		object_init_ex(_11$$6, phalcon_db_index_ce);
		ZEPHIR_CALL_METHOD(NULL, _11$$6, "__construct", &_12, 24, name, indexColumns);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, name, &_11$$6, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(indexObjects);

}

/**
 * Lists table references
 *
 *<code>
 * print_r(
 *     $connection->describeReferences("robots_parts")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, describeReferences) {

	zval *_13$$3 = NULL, *_18$$6 = NULL;
	HashTable *_5, *_15;
	HashPosition _4, _14;
	zephir_fcall_cache_entry *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *references = NULL, *reference = NULL, *arrayReference = NULL, *constraintName = NULL, *referenceObjects = NULL, *name = NULL, *referencedSchema = NULL, *referencedTable = NULL, *columns = NULL, *referencedColumns = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, **_16, *_7$$5, *_8$$5, *_9$$5, *_10$$5, *_11$$3, *_12$$3, *_17$$6 = NULL, *_19$$6 = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_INIT_VAR(references);
	array_init(references);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describereferences", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter.zep", 976);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(reference, _6);
		zephir_array_fetch_long(&constraintName, reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 952 TSRMLS_CC);
		if (!(zephir_array_isset(references, constraintName))) {
			ZEPHIR_OBS_NVAR(referencedSchema);
			zephir_array_fetch_long(&referencedSchema, reference, 3, PH_NOISY, "phalcon/db/adapter.zep", 954 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_long(&referencedTable, reference, 4, PH_NOISY, "phalcon/db/adapter.zep", 955 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
			ZEPHIR_INIT_NVAR(referencedColumns);
			array_init(referencedColumns);
		} else {
			zephir_array_fetch(&_7$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 959 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedSchema);
			zephir_array_fetch_string(&referencedSchema, _7$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter.zep", 959 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 960 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_string(&referencedTable, _8$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter.zep", 960 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 961 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch_string(&columns, _9$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter.zep", 961 TSRMLS_CC);
			zephir_array_fetch(&_10$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 962 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedColumns);
			zephir_array_fetch_string(&referencedColumns, _10$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter.zep", 962 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_11$$3, reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 965 TSRMLS_CC);
		zephir_array_append(&columns, _11$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 965);
		zephir_array_fetch_long(&_12$$3, reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 966 TSRMLS_CC);
		zephir_array_append(&referencedColumns, _12$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 966);
		ZEPHIR_INIT_NVAR(_13$$3);
		zephir_create_array(_13$$3, 4, 0 TSRMLS_CC);
		zephir_array_update_string(&_13$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&references, constraintName, &_13$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(referenceObjects);
	array_init(referenceObjects);
	zephir_is_iterable(references, &_15, &_14, 0, 0, "phalcon/db/adapter.zep", 986);
	for (
	  ; zend_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
	  ; zend_hash_move_forward_ex(_15, &_14)
	) {
		ZEPHIR_GET_HMKEY(name, _15, _14);
		ZEPHIR_GET_HVALUE(arrayReference, _16);
		ZEPHIR_INIT_NVAR(_17$$6);
		object_init_ex(_17$$6, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(_18$$6);
		zephir_create_array(_18$$6, 4, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_19$$6);
		zephir_array_fetch_string(&_19$$6, arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter.zep", 979 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedSchema"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_19$$6);
		zephir_array_fetch_string(&_19$$6, arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter.zep", 980 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedTable"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_19$$6);
		zephir_array_fetch_string(&_19$$6, arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter.zep", 981 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("columns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_19$$6);
		zephir_array_fetch_string(&_19$$6, arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter.zep", 983 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedColumns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, _17$$6, "__construct", &_20, 25, name, _18$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, name, &_17$$6, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(referenceObjects);

}

/**
 * Gets creation options from a table
 *
 *<code>
 * print_r(
 *     $connection->tableOptions("robots")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, tableOptions) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *sql = NULL, *_0, *_1$$3 = NULL, *_2$$3, *_3$$3;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&sql, _0, "tableoptions", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	if (zephir_is_true(sql)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 2);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "fetchall", NULL, 0, sql, _2$$3);
		zephir_check_call_status();
		zephir_array_fetch_long(&_3$$3, _1$$3, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 1004 TSRMLS_CC);
		RETURN_CTOR(_3$$3);
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Creates a new savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, createSavepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *dialect = NULL, *_0 = NULL, *_1 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(dialect);
	zephir_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter.", "phalcon/db/adapter.zep", 1019);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, dialect, "createsavepoint", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Releases given savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, releaseSavepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *dialect = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(dialect);
	zephir_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/db/adapter.zep", 1035);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, dialect, "supportsreleasesavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_2, dialect, "releasesavepoint", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Rollbacks given savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, rollbackSavepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *dialect = NULL, *_0 = NULL, *_1 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(dialect);
	zephir_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/db/adapter.zep", 1055);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, dialect, "rollbacksavepoint", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set if nested transactions should use savepoints
 */
PHP_METHOD(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nestedTransactionsWithSavepoints_param = NULL, *_0, *_1, *_2 = NULL;
	zend_bool nestedTransactionsWithSavepoints;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &nestedTransactionsWithSavepoints_param);

	nestedTransactionsWithSavepoints = zephir_get_boolval(nestedTransactionsWithSavepoints_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_transactionLevel"), PH_NOISY_CC);
	if (ZEPHIR_GT_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Nested transaction with savepoints behavior cannot be changed while a transaction is open", "phalcon/db/adapter.zep", 1068);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/db/adapter.zep", 1072);
		return;
	}
	if (nestedTransactionsWithSavepoints) {
		zephir_update_property_this(getThis(), SL("_transactionsWithSavepoints"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_transactionsWithSavepoints"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns if nested transactions should use savepoints
 */
PHP_METHOD(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints) {

	

	RETURN_MEMBER(getThis(), "_transactionsWithSavepoints");

}

/**
 * Returns the savepoint name to use for nested transactions
 */
PHP_METHOD(Phalcon_Db_Adapter, getNestedTransactionSavepointName) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_transactionLevel"), PH_NOISY_CC);
	ZEPHIR_CONCAT_SV(return_value, "PHALCON_SAVEPOINT_", _0);
	return;

}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *<code>
 * // Inserting a new robot with a valid default value for the column 'id'
 * $success = $connection->insert(
 *     "robots",
 *     [
 *         $connection->getDefaultIdValue(),
 *         "Astro Boy",
 *         1952,
 *     ],
 *     [
 *         "id",
 *         "name",
 *         "year",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, getDefaultIdValue) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "null", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 26, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the default value to make the RBDM use the default value declared in the table definition
 *
 *<code>
 * // Inserting a new robot with a valid default value for the column 'year'
 * $success = $connection->insert(
 *     "robots",
 *     [
 *         "Astro Boy",
 *         $connection->getDefaultValue()
 *     ],
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, getDefaultValue) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DEFAULT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 26, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter, supportSequences) {

	

	RETURN_BOOL(0);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter, useExplicitIdValue) {

	

	RETURN_BOOL(0);

}

/**
 * Return descriptor used to connect to the active database
 */
PHP_METHOD(Phalcon_Db_Adapter, getDescriptor) {

	

	RETURN_MEMBER(getThis(), "_descriptor");

}

/**
 * Gets the active connection unique identifier
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getConnectionId) {

	

	RETURN_MEMBER(getThis(), "_connectionId");

}

/**
 * Active SQL statement in the object
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement) {

	

	RETURN_MEMBER(getThis(), "_sqlStatement");

}

/**
 * Active SQL statement in the object without replace bound parameters
 */
PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement) {

	

	RETURN_MEMBER(getThis(), "_sqlStatement");

}

/**
 * Active SQL statement in the object
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes) {

	

	RETURN_MEMBER(getThis(), "_sqlBindTypes");

}

zend_object_value zephir_init_properties_Phalcon_Db_Adapter(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_descriptor"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_descriptor"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

