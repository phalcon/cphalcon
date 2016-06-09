
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"


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
	 *
	 * @var \stdClass
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
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL Bind Types
	 *
	 * @var string
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

	zend_class_implements(phalcon_db_adapter_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Name of the dialect used
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialectType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_dialectType");

}

/**
 * Type of database system the adapter is used for
 */
PHP_METHOD(Phalcon_Db_Adapter, getType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Active SQL bound parameter variables
 */
PHP_METHOD(Phalcon_Db_Adapter, getSqlVariables) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_sqlVariables");

}

/**
 * Phalcon\Db\Adapter constructor
 */
PHP_METHOD(Phalcon_Db_Adapter, __construct) {

	zend_class_entry *_4$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, dialectClass, connectionId, _0, _1$$3, _2$$4, _3$$4;
	zval descriptor;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dialectClass);
	ZVAL_UNDEF(&connectionId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &descriptor_param);

	ZEPHIR_OBS_VAR_ONCE(&descriptor);
	ZVAL_COPY(&descriptor, descriptor_param);


	ZEPHIR_OBS_VAR(&connectionId);
	zephir_read_static_property_ce(&connectionId, phalcon_db_adapter_ce, SL("_connectionConsecutive"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, SL("_connectionId"), &connectionId);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(&connectionId) + 1));
	zephir_update_static_property_ce(phalcon_db_adapter_ce, SL("_connectionConsecutive"), &_0);
	ZEPHIR_OBS_VAR(&dialectClass);
	if (!(zephir_array_isset_string_fetch(&dialectClass, &descriptor, SL("dialectClass"), 0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("_dialectType"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&dialectClass);
		ZEPHIR_CONCAT_SV(&dialectClass, "phalcon\\db\\dialect\\", &_1$$3);
	}
	if (Z_TYPE_P(&dialectClass) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_fetch_safe_class(&_3$$4, &dialectClass);
		_4$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$4), Z_STRLEN_P(&_3$$4), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_2$$4, _4$$4);
		if (zephir_has_constructor(&_2$$4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("_dialect"), &_2$$4);
	} else {
		if (Z_TYPE_P(&dialectClass) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, SL("_dialect"), &dialectClass);
		}
	}
	zephir_update_property_zval(this_ptr, SL("_descriptor"), &descriptor);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the event manager
 */
PHP_METHOD(Phalcon_Db_Adapter, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Db_Adapter, getEventsManager) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets the dialect used to produce the SQL
 */
PHP_METHOD(Phalcon_Db_Adapter, setDialect) {

	zval *dialect, dialect_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dialect_sub);

	zephir_fetch_params(0, 1, 0, &dialect);



	zephir_update_property_zval(this_ptr, SL("_dialect"), dialect);

}

/**
 * Returns internal dialect instance
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialect) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_dialect");

}

/**
 * Returns the first row in a SQL query result
 *
 *<code>
 *	//Getting first robot
 *	$robot = $connection->fetchOne("SELECT * FROM robots");
 *	print_r($robot);
 *
 *	//Getting first robot with associative indexes only
 *	$robot = $connection->fetchOne("SELECT * FROM robots", Phalcon\Db::FETCH_ASSOC);
 *	print_r($robot);
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *fetchMode = NULL, fetchMode_sub, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, result;
	zval sqlQuery;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&fetchMode_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &sqlQuery_param, &fetchMode, &bindParams, &bindTypes);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}
	if (!fetchMode) {
		fetchMode = &fetchMode_sub;
		ZEPHIR_INIT_VAR(fetchMode);
		ZVAL_LONG(fetchMode, 2);
	}
	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}


	ZEPHIR_CALL_METHOD(&result, this_ptr, "query", NULL, 0, &sqlQuery, bindParams, bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) == IS_OBJECT) {
		if (Z_TYPE_P(fetchMode) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &result, "setfetchmode", NULL, 0, fetchMode);
			zephir_check_call_status();
		}
		ZEPHIR_RETURN_CALL_METHOD(&result, "fetch", NULL, 0);
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
 *	//Getting all robots with associative indexes only
 *	$robots = $connection->fetchAll("SELECT * FROM robots", Phalcon\Db::FETCH_ASSOC);
 *	foreach ($robots as $robot) {
 *		print_r($robot);
 *	}
 *
 *  //Getting all robots that contains word "robot" withing the name
 *  $robots = $connection->fetchAll("SELECT * FROM robots WHERE name LIKE :name",
 *		Phalcon\Db::FETCH_ASSOC,
 *		array('name' => '%robot%')
 *  );
 *	foreach($robots as $robot){
 *		print_r($robot);
 *	}
 *</code>
 *
 * @param string sqlQuery
 * @param int fetchMode
 * @param array bindParams
 * @param array bindTypes
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchAll) {

	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *fetchMode = NULL, fetchMode_sub, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, results, result, row;
	zval sqlQuery;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&fetchMode_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&row);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &sqlQuery_param, &fetchMode, &bindParams, &bindTypes);

	zephir_get_strval(&sqlQuery, sqlQuery_param);
	if (!fetchMode) {
		fetchMode = &fetchMode_sub;
		ZEPHIR_INIT_VAR(fetchMode);
		ZVAL_LONG(fetchMode, 2);
	}
	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}


	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "query", NULL, 0, &sqlQuery, bindParams, bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) == IS_OBJECT) {
		if (Z_TYPE_P(fetchMode) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &result, "setfetchmode", NULL, 0, fetchMode);
			zephir_check_call_status();
		}
		while (1) {
			ZEPHIR_CALL_METHOD(&row, &result, "fetch", &_0, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&row))) {
				break;
			}
			zephir_array_append(&results, &row, PH_SEPARATE, "phalcon/db/adapter.zep", 243);
		}
	}
	RETURN_CCTOR(results);

}

/**
 * Returns the n'th field of first row in a SQL query result
 *
 *<code>
 *	//Getting count of robots
 *	$robotsCount = $connection->fetchColumn("SELECT count(*) FROM robots");
 *	print_r($robotsCount);
 *
 *	//Getting name of last edited robot
 *	$robot = $connection->fetchColumn("SELECT id, name FROM robots order by modified desc", 1);
 *	print_r($robot);
 *</code>
 *
 * @param  string sqlQuery
 * @param  array placeholders
 * @param  int|string column
 * @return string|
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchColumn) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery, sqlQuery_sub, *placeholders = NULL, placeholders_sub, *column = NULL, column_sub, __$null, row, columnValue, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sqlQuery_sub);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_UNDEF(&column_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&columnValue);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlQuery, &placeholders, &column);

	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}
	if (!column) {
		column = &column_sub;
		ZEPHIR_INIT_VAR(column);
		ZVAL_LONG(column, 0);
	}


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(&row, this_ptr, "fetchone", NULL, 0, sqlQuery, &_0, placeholders);
	zephir_check_call_status();
	_1 = !(ZEPHIR_IS_EMPTY(&row));
	if (_1) {
		_1 = zephir_array_isset_fetch(&columnValue, &row, column, 1 TSRMLS_CC);
	}
	if (_1) {
		RETURN_CTOR(columnValue);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * <code>
 * // Inserting a new robot
 * $success = $connection->insert(
 *	 "robots",
 *	 array("Astro Boy", 1952),
 *	 array("name", "year")
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

	zval _5$$5;
	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *table, table_sub, *values_param = NULL, *fields = NULL, fields_sub, *dataTypes = NULL, dataTypes_sub, __$null, placeholders, insertValues, bindDataTypes, bindType, position, value, escapedTable, joinedValues, escapedFields, field, insertSql, *_2, _0$$3, _1$$3, _6$$7, _7$$8, *_8$$14, _9$$15, _11$$13;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&insertValues);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&escapedTable);
	ZVAL_UNDEF(&joinedValues);
	ZVAL_UNDEF(&escapedFields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&insertSql);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &table, &values_param, &fields, &dataTypes);

	ZEPHIR_OBS_VAR_ONCE(&values);
	ZVAL_COPY(&values, values_param);
	if (!fields) {
		fields = &fields_sub;
		fields = &__$null;
	}
	if (!dataTypes) {
		dataTypes = &dataTypes_sub;
		dataTypes = &__$null;
	}


	if (!(zephir_fast_count_int(&values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "Unable to insert into ", table, " without data");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 9, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/db/adapter.zep", 312 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&placeholders);
	array_init(&placeholders);
	ZEPHIR_INIT_VAR(&insertValues);
	array_init(&insertValues);
	ZEPHIR_INIT_VAR(&bindDataTypes);
	array_init(&bindDataTypes);
	zephir_is_iterable(&values, 0, "phalcon/db/adapter.zep", 342);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&position);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&position, _4);
		} else {
			ZVAL_LONG(&position, _3);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _2);
		if (Z_TYPE_P(&value) == IS_OBJECT) {
			zephir_get_strval(&_5$$5, &value);
			zephir_array_append(&placeholders, &_5$$5, PH_SEPARATE, "phalcon/db/adapter.zep", 325);
		} else {
			if (Z_TYPE_P(&value) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&_6$$7);
				ZVAL_STRING(&_6$$7, "null");
				zephir_array_append(&placeholders, &_6$$7, PH_SEPARATE, "phalcon/db/adapter.zep", 328);
			} else {
				ZEPHIR_INIT_NVAR(&_7$$8);
				ZVAL_STRING(&_7$$8, "?");
				zephir_array_append(&placeholders, &_7$$8, PH_SEPARATE, "phalcon/db/adapter.zep", 330);
				zephir_array_append(&insertValues, &value, PH_SEPARATE, "phalcon/db/adapter.zep", 331);
				if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (!(zephir_array_isset_fetch(&bindType, dataTypes, &position, 0 TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Incomplete number of bind types", "phalcon/db/adapter.zep", 334);
						return;
					}
					zephir_array_append(&bindDataTypes, &bindType, PH_SEPARATE, "phalcon/db/adapter.zep", 336);
				}
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&position);
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, 0, table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&escapedTable, table);
	}
	ZEPHIR_INIT_VAR(&joinedValues);
	zephir_fast_join_str(&joinedValues, SL(", "), &placeholders TSRMLS_CC);
	ZEPHIR_INIT_VAR(&insertSql);
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_INIT_VAR(&escapedFields);
			array_init(&escapedFields);
			zephir_is_iterable(fields, 0, "phalcon/db/adapter.zep", 359);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(fields), _8$$14)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _8$$14);
				ZEPHIR_CALL_METHOD(&_9$$15, this_ptr, "escapeidentifier", &_10, 0, &field);
				zephir_check_call_status();
				zephir_array_append(&escapedFields, &_9$$15, PH_SEPARATE, "phalcon/db/adapter.zep", 357);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&field);
		} else {
			ZEPHIR_CPY_WRT(&escapedFields, fields);
		}
		ZEPHIR_INIT_VAR(&_11$$13);
		zephir_fast_join_str(&_11$$13, SL(", "), &escapedFields TSRMLS_CC);
		ZEPHIR_CONCAT_SVSVSVS(&insertSql, "INSERT INTO ", &escapedTable, " (", &_11$$13, ") VALUES (", &joinedValues, ")");
	} else {
		ZEPHIR_CONCAT_SVSVS(&insertSql, "INSERT INTO ", &escapedTable, " VALUES (", &joinedValues, ")");
	}
	if (!(zephir_fast_count_int(&bindDataTypes TSRMLS_CC))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &insertSql, &insertValues);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &insertSql, &insertValues, &bindDataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * <code>
 * //Inserting a new robot
 * $success = $connection->insertAsDict(
 *	 "robots",
 *	 array(
 *		  "name" => "Astro Boy",
 *		  "year" => 1952
 *	  )
 * );
 *
 * //Next SQL sentence is sent to the database system
 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
 * </code>
 *
 * @param 	string table
 * @param 	array data
 * @param 	array dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, insertAsDict) {

	zend_string *_3;
	zend_ulong _2;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *data, data_sub, *dataTypes = NULL, dataTypes_sub, __$null, values, fields, field, value, *_1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table, &data, &dataTypes);

	if (!dataTypes) {
		dataTypes = &dataTypes_sub;
		dataTypes = &__$null;
	}


	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(data);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	zephir_is_iterable(data, 0, "phalcon/db/adapter.zep", 414);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&field);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&field, _3);
		} else {
			ZVAL_LONG(&field, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/db/adapter.zep", 410);
		zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/db/adapter.zep", 411);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "insert", NULL, 0, table, &values, &fields, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * <code>
 * //Updating existing robot
 * $success = $connection->update(
 *	 "robots",
 *	 array("name"),
 *	 array("New Astro Boy"),
 *	 "id = 101"
 * );
 *
 * //Next SQL sentence is sent to the database system
 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
 *
 * //Updating existing robot with array condition and $dataTypes
 * $success = $connection->update(
 *	 "robots",
 *	 array("name"),
 *	 array("New Astro Boy"),
 *	 array(
 *		 'conditions' => "id = ?",
 *		 'bind' => array($some_unsafe_id),
 *		 'bindTypes' => array(PDO::PARAM_INT) //use only if you use $dataTypes param
 *	 ),
 *	 array(PDO::PARAM_STR)
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

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *fields, fields_sub, *values, values_sub, *whereCondition = NULL, whereCondition_sub, *dataTypes = NULL, dataTypes_sub, __$null, placeholders, updateValues, position, value, field, bindDataTypes, escapedField, bindType, escapedTable, setClause, updateSql, conditions, whereBind, whereTypes, *_0, _4$$7, _5$$9, _6$$10;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&whereCondition_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&updateValues);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&escapedField);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&escapedTable);
	ZVAL_UNDEF(&setClause);
	ZVAL_UNDEF(&updateSql);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&whereBind);
	ZVAL_UNDEF(&whereTypes);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &table, &fields, &values, &whereCondition, &dataTypes);

	if (!whereCondition) {
		whereCondition = &whereCondition_sub;
		whereCondition = &__$null;
	}
	if (!dataTypes) {
		dataTypes = &dataTypes_sub;
		dataTypes = &__$null;
	}


	ZEPHIR_INIT_VAR(&placeholders);
	array_init(&placeholders);
	ZEPHIR_INIT_VAR(&updateValues);
	array_init(&updateValues);
	ZEPHIR_INIT_VAR(&bindDataTypes);
	array_init(&bindDataTypes);
	zephir_is_iterable(values, 0, "phalcon/db/adapter.zep", 500);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(values), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&position);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&position, _2);
		} else {
			ZVAL_LONG(&position, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_OBS_NVAR(&field);
		if (!(zephir_array_isset_fetch(&field, fields, &position, 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The number of values in the update is not the same as fields", "phalcon/db/adapter.zep", 473);
			return;
		}
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_CALL_METHOD(&escapedField, this_ptr, "escapeidentifier", &_3, 0, &field);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&escapedField, &field);
		}
		if (Z_TYPE_P(&value) == IS_OBJECT) {
			ZEPHIR_INIT_LNVAR(_4$$7);
			ZEPHIR_CONCAT_VSV(&_4$$7, &escapedField, " = ", &value);
			zephir_array_append(&placeholders, &_4$$7, PH_SEPARATE, "phalcon/db/adapter.zep", 483);
		} else {
			if (Z_TYPE_P(&value) == IS_NULL) {
				ZEPHIR_INIT_LNVAR(_5$$9);
				ZEPHIR_CONCAT_VS(&_5$$9, &escapedField, " = null");
				zephir_array_append(&placeholders, &_5$$9, PH_SEPARATE, "phalcon/db/adapter.zep", 486);
			} else {
				zephir_array_append(&updateValues, &value, PH_SEPARATE, "phalcon/db/adapter.zep", 488);
				if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (!(zephir_array_isset_fetch(&bindType, dataTypes, &position, 0 TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Incomplete number of bind types", "phalcon/db/adapter.zep", 491);
						return;
					}
					zephir_array_append(&bindDataTypes, &bindType, PH_SEPARATE, "phalcon/db/adapter.zep", 493);
				}
				ZEPHIR_INIT_LNVAR(_6$$10);
				ZEPHIR_CONCAT_VS(&_6$$10, &escapedField, " = ?");
				zephir_array_append(&placeholders, &_6$$10, PH_SEPARATE, "phalcon/db/adapter.zep", 495);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&position);
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, 0, table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&escapedTable, table);
	}
	ZEPHIR_INIT_VAR(&setClause);
	zephir_fast_join_str(&setClause, SL(", "), &placeholders TSRMLS_CC);
	ZEPHIR_INIT_VAR(&updateSql);
	if (Z_TYPE_P(whereCondition) != IS_NULL) {
		ZEPHIR_CONCAT_SVSVS(&updateSql, "UPDATE ", &escapedTable, " SET ", &setClause, " WHERE ");
		if (Z_TYPE_P(whereCondition) == IS_STRING) {
			zephir_concat_self(&updateSql, whereCondition TSRMLS_CC);
		} else {
			if (Z_TYPE_P(whereCondition) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid WHERE clause conditions", "phalcon/db/adapter.zep", 523);
				return;
			}
			ZEPHIR_OBS_VAR(&conditions);
			if (zephir_array_isset_string_fetch(&conditions, whereCondition, SL("conditions"), 0)) {
				zephir_concat_self(&updateSql, &conditions TSRMLS_CC);
			}
			ZEPHIR_OBS_VAR(&whereBind);
			if (zephir_array_isset_string_fetch(&whereBind, whereCondition, SL("bind"), 0)) {
				zephir_merge_append(&updateValues, &whereBind);
			}
			ZEPHIR_OBS_VAR(&whereTypes);
			if (zephir_array_isset_string_fetch(&whereTypes, whereCondition, SL("bindTypes"), 0)) {
				zephir_merge_append(&bindDataTypes, &whereTypes);
			}
		}
	} else {
		ZEPHIR_CONCAT_SVSV(&updateSql, "UPDATE ", &escapedTable, " SET ", &setClause);
	}
	if (!(zephir_fast_count_int(&bindDataTypes TSRMLS_CC))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &updateSql, &updateValues);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &updateSql, &updateValues, &bindDataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates data on a table using custom RBDM SQL syntax
 * Another, more convenient syntax
 *
 * <code>
 * //Updating existing robot
 * $success = $connection->updateAsDict(
 *	 "robots",
 *	 array(
 *		  "name" => "New Astro Boy"
 *	  ),
 *	 "id = 101"
 * );
 *
 * //Next SQL sentence is sent to the database system
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

	zend_string *_3;
	zend_ulong _2;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *data, data_sub, *whereCondition = NULL, whereCondition_sub, *dataTypes = NULL, dataTypes_sub, __$null, values, fields, field, value, *_1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&whereCondition_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &table, &data, &whereCondition, &dataTypes);

	if (!whereCondition) {
		whereCondition = &whereCondition_sub;
		whereCondition = &__$null;
	}
	if (!dataTypes) {
		dataTypes = &dataTypes_sub;
		dataTypes = &__$null;
	}


	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(data);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	zephir_is_iterable(data, 0, "phalcon/db/adapter.zep", 599);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&field);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&field, _3);
		} else {
			ZVAL_LONG(&field, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/db/adapter.zep", 595);
		zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/db/adapter.zep", 596);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "update", NULL, 0, table, &fields, &values, whereCondition, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * <code>
 * //Deleting existing robot
 * $success = $connection->delete(
 *	 "robots",
 *	 "id = 101"
 * );
 *
 * //Next SQL sentence is generated
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *whereCondition = NULL, whereCondition_sub, *placeholders = NULL, placeholders_sub, *dataTypes = NULL, dataTypes_sub, __$null, sql, escapedTable;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&whereCondition_sub);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&escapedTable);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &table, &whereCondition, &placeholders, &dataTypes);

	if (!whereCondition) {
		whereCondition = &whereCondition_sub;
		whereCondition = &__$null;
	}
	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}
	if (!dataTypes) {
		dataTypes = &dataTypes_sub;
		dataTypes = &__$null;
	}


	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, 0, table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&escapedTable, table);
	}
	ZEPHIR_INIT_VAR(&sql);
	if (!(ZEPHIR_IS_EMPTY(whereCondition))) {
		ZEPHIR_CONCAT_SVSV(&sql, "DELETE FROM ", &escapedTable, " WHERE ", whereCondition);
	} else {
		ZEPHIR_CONCAT_SV(&sql, "DELETE FROM ", &escapedTable);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &sql, placeholders, dataTypes);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *columnList, columnList_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&columnList_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columnList);



	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcolumnlist", NULL, 0, columnList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * <code>
 * 	echo $connection->limit("SELECT * FROM robots", 5);
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter, limit) {

	int number, ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *number_param = NULL, _0, _1;
	zval sqlQuery;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}
	number = zephir_get_intval(number_param);


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, number);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "limit", NULL, 0, &sqlQuery, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 *<code>
 * 	var_dump($connection->tableExists("blog", "posts"));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, tableExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, _0, _1, _2, _3, _4;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "tableexists", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchone", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_0, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 676 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_4, 0));

}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 *<code>
 * var_dump($connection->viewExists("active_users", "posts"));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, viewExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *viewName_param = NULL, *schemaName_param = NULL, _0, _1, _2, _3, _4;
	zval viewName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName_param);

	if (unlikely(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "viewexists", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchone", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_0, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 688 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_4, 0));

}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 */
PHP_METHOD(Phalcon_Db_Adapter, forUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, _0;
	zval sqlQuery;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "forupdate", NULL, 0, &sqlQuery);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 */
PHP_METHOD(Phalcon_Db_Adapter, sharedLock) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, _0;
	zval sqlQuery;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "sharedlock", NULL, 0, &sqlQuery);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a table
 */
PHP_METHOD(Phalcon_Db_Adapter, createTable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, columns, _0, _1;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	ZEPHIR_OBS_VAR_ONCE(&definition);
	ZVAL_COPY(&definition, definition_param);


	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter.zep", 715);
		return;
	}
	if (!(zephir_fast_count_int(&columns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter.zep", 719);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "createtable", NULL, 0, &tableName, &schemaName, &definition);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a table from a schema/database
 */
PHP_METHOD(Phalcon_Db_Adapter, dropTable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, _0, _1, _2;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		ifExists = zephir_get_boolval(ifExists_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	if (ifExists) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, &_0, "droptable", NULL, 0, &tableName, &schemaName, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a view
 */
PHP_METHOD(Phalcon_Db_Adapter, createView) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName = NULL, schemaName_sub, __$null, _0, _1;
	zval viewName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName);

	if (unlikely(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	ZEPHIR_OBS_VAR_ONCE(&definition);
	ZVAL_COPY(&definition, definition_param);
	if (!schemaName) {
		schemaName = &schemaName_sub;
		schemaName = &__$null;
	}


	if (!(zephir_array_isset_string(&definition, SL("sql")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter.zep", 739);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "createview", NULL, 0, &viewName, &definition, schemaName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a view
 */
PHP_METHOD(Phalcon_Db_Adapter, dropView) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, _0, _1, _2;
	zval viewName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);

	if (unlikely(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		ifExists = zephir_get_boolval(ifExists_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	if (ifExists) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropview", NULL, 0, &viewName, &schemaName, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a column to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, _0, _1;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addcolumn", NULL, 0, &tableName, &schemaName, column);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter, modifyColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, _0, _1;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		currentColumn = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "modifycolumn", NULL, 0, &tableName, &schemaName, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a column from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, _0, _1;
	zval tableName, schemaName, columnName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	zephir_get_strval(&columnName, columnName_param);


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropcolumn", NULL, 0, &tableName, &schemaName, &columnName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds an index to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, _0, _1;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addindex", NULL, 0, &tableName, &schemaName, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drop an index from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName, indexName_sub, _0, _1;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropindex", NULL, 0, &tableName, &schemaName, indexName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a primary key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, _0, _1;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addprimarykey", NULL, 0, &tableName, &schemaName, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a table's primary key
 */
PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, _0, _1;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropprimarykey", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a foreign key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addForeignKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, _0, _1;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addforeignkey", NULL, 0, &tableName, &schemaName, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, _0, _1;
	zval tableName, schemaName, referenceName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&referenceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (unlikely(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(&referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceName);
		ZVAL_EMPTY_STRING(&referenceName);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropforeignkey", NULL, 0, &tableName, &schemaName, &referenceName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the SQL column definition from a column
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * List all tables on a database
 *
 *<code>
 * 	print_r($connection->listTables("blog"));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, listTables) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *schemaName_param = NULL, table, allTables, _0, _1, _2, _3, *_4, _5$$3;
	zval schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&allTables);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	ZEPHIR_INIT_VAR(&allTables);
	array_init(&allTables);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "listtables", NULL, 0, &schemaName);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter.zep", 848);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&table);
		ZVAL_COPY(&table, _4);
		zephir_array_fetch_long(&_5$$3, &table, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 846 TSRMLS_CC);
		zephir_array_append(&allTables, &_5$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 846);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&table);
	RETURN_CCTOR(allTables);

}

/**
 * List all views on a database
 *
 *<code>
 *	print_r($connection->listViews("blog"));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, listViews) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *schemaName_param = NULL, table, allTables, _0, _1, _2, _3, *_4, _5$$3;
	zval schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&allTables);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	ZEPHIR_INIT_VAR(&allTables);
	array_init(&allTables);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "listviews", NULL, 0, &schemaName);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter.zep", 866);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&table);
		ZVAL_COPY(&table, _4);
		zephir_array_fetch_long(&_5$$3, &table, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 864 TSRMLS_CC);
		zephir_array_append(&allTables, &_5$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 864);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&table);
	RETURN_CCTOR(allTables);

}

/**
 * Lists table indexes
 *
 *<code>
 *	print_r($connection->describeIndexes('robots_parts'));
 *</code>
 *
 * @param	string table
 * @param	string schema
 * @return	Phalcon\Db\Index[]
 */
PHP_METHOD(Phalcon_Db_Adapter, describeIndexes) {

	zend_string *_8;
	zend_ulong _7;
	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema = NULL, schema_sub, __$null, indexes, index, keyName, indexObjects, name, indexColumns, columns, _0, _1, _2, _3, *_4, *_6, _5$$3, _9$$6;
	zval table;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&indexColumns);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema) {
		schema = &schema_sub;
		schema = &__$null;
	}


	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table, schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter.zep", 898);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _4);
		zephir_array_fetch_long(&keyName, &index, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 887 TSRMLS_CC);
		if (!(zephir_array_isset(&indexes, &keyName))) {
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
		} else {
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch(&columns, &indexes, &keyName, PH_NOISY, "phalcon/db/adapter.zep", 891 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_5$$3, &index, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 894 TSRMLS_CC);
		zephir_array_append(&columns, &_5$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 894);
		zephir_array_update_zval(&indexes, &keyName, &columns, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/db/adapter.zep", 907);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _7, _8, _6)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_8 != NULL) { 
			ZVAL_STR_COPY(&name, _8);
		} else {
			ZVAL_LONG(&name, _7);
		}
		ZEPHIR_INIT_NVAR(&indexColumns);
		ZVAL_COPY(&indexColumns, _6);
		ZEPHIR_INIT_NVAR(&_9$$6);
		object_init_ex(&_9$$6, phalcon_db_index_ce);
		ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_10, 19, &name, &indexColumns);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_9$$6, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&indexColumns);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(indexObjects);

}

/**
 * Lists table references
 *
 *<code>
 * print_r($connection->describeReferences('robots_parts'));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, describeReferences) {

	zval _11$$3, _16$$6;
	zend_string *_14;
	zend_ulong _13;
	zephir_fcall_cache_entry *_18 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, _0, _1, _2, _3, *_4, *_12, _5$$5, _6$$5, _7$$5, _8$$5, _9$$3, _10$$3, _15$$6, _17$$6;
	zval table, schema;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&arrayReference);
	ZVAL_UNDEF(&constraintName);
	ZVAL_UNDEF(&referenceObjects);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&referencedSchema);
	ZVAL_UNDEF(&referencedTable);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedColumns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_16$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
	if (unlikely(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_EMPTY_STRING(&schema);
	}
	}


	ZEPHIR_INIT_VAR(&references);
	array_init(&references);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter.zep", 951);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&reference);
		ZVAL_COPY(&reference, _4);
		zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 927 TSRMLS_CC);
		if (!(zephir_array_isset(&references, &constraintName))) {
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/db/adapter.zep", 929 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/db/adapter.zep", 930 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
			ZEPHIR_INIT_NVAR(&referencedColumns);
			array_init(&referencedColumns);
		} else {
			zephir_array_fetch(&_5$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 934 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_string(&referencedSchema, &_5$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter.zep", 934 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 935 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_string(&referencedTable, &_6$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter.zep", 935 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 936 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_7$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter.zep", 936 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 937 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedColumns);
			zephir_array_fetch_string(&referencedColumns, &_8$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter.zep", 937 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_9$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 940 TSRMLS_CC);
		zephir_array_append(&columns, &_9$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 940);
		zephir_array_fetch_long(&_10$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 941 TSRMLS_CC);
		zephir_array_append(&referencedColumns, &_10$$3, PH_SEPARATE, "phalcon/db/adapter.zep", 941);
		ZEPHIR_INIT_NVAR(&_11$$3);
		zephir_create_array(&_11$$3, 4, 0 TSRMLS_CC);
		zephir_array_update_string(&_11$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&references, &constraintName, &_11$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_is_iterable(&references, 0, "phalcon/db/adapter.zep", 961);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _13, _14, _12)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_14 != NULL) { 
			ZVAL_STR_COPY(&name, _14);
		} else {
			ZVAL_LONG(&name, _13);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _12);
		ZEPHIR_INIT_NVAR(&_15$$6);
		object_init_ex(&_15$$6, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_16$$6);
		zephir_create_array(&_16$$6, 4, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_17$$6);
		zephir_array_fetch_string(&_17$$6, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter.zep", 954 TSRMLS_CC);
		zephir_array_update_string(&_16$$6, SL("referencedSchema"), &_17$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_17$$6);
		zephir_array_fetch_string(&_17$$6, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter.zep", 955 TSRMLS_CC);
		zephir_array_update_string(&_16$$6, SL("referencedTable"), &_17$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_17$$6);
		zephir_array_fetch_string(&_17$$6, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter.zep", 956 TSRMLS_CC);
		zephir_array_update_string(&_16$$6, SL("columns"), &_17$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_17$$6);
		zephir_array_fetch_string(&_17$$6, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter.zep", 958 TSRMLS_CC);
		zephir_array_update_string(&_16$$6, SL("referencedColumns"), &_17$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_15$$6, "__construct", &_18, 20, &name, &_16$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_15$$6, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(referenceObjects);

}

/**
 * Gets creation options from a table
 *
 *<code>
 * print_r($connection->tableOptions('robots'));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, tableOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, sql, _0, _1$$3, _2$$3, _3$$3;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "tableoptions", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	if (zephir_is_true(&sql)) {
		ZVAL_LONG(&_2$$3, 2);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "fetchall", NULL, 0, &sql, &_2$$3);
		zephir_check_call_status();
		zephir_array_fetch_long(&_3$$3, &_1$$3, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter.zep", 977 TSRMLS_CC);
		RETURN_CTOR(_3$$3);
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Creates a new savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, createSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, dialect, _0, _1;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&dialect);
	zephir_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, &dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter.", "phalcon/db/adapter.zep", 992);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, &dialect, "createsavepoint", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Releases given savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, releaseSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, dialect, _0, _1, _2;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&dialect);
	zephir_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, &dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/db/adapter.zep", 1008);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, &dialect, "supportsreleasesavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_2, &dialect, "releasesavepoint", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Rollbacks given savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, rollbackSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, dialect, _0, _1;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&dialect);
	zephir_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, &dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/db/adapter.zep", 1028);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, &dialect, "rollbacksavepoint", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set if nested transactions should use savepoints
 */
PHP_METHOD(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *nestedTransactionsWithSavepoints_param = NULL, __$true, __$false, _0, _1, _2;
	zend_bool nestedTransactionsWithSavepoints;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &nestedTransactionsWithSavepoints_param);

	nestedTransactionsWithSavepoints = zephir_get_boolval(nestedTransactionsWithSavepoints_param);


	zephir_read_property(&_0, this_ptr, SL("_transactionLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Nested transaction with savepoints behavior cannot be changed while a transaction is open", "phalcon/db/adapter.zep", 1041);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/db/adapter.zep", 1045);
		return;
	}
	if (nestedTransactionsWithSavepoints) {
		zephir_update_property_zval(this_ptr, SL("_transactionsWithSavepoints"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_transactionsWithSavepoints"), &__$false);
	}
	RETURN_THIS();

}

/**
 * Returns if nested transactions should use savepoints
 */
PHP_METHOD(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_transactionsWithSavepoints");

}

/**
 * Returns the savepoint name to use for nested transactions
 */
PHP_METHOD(Phalcon_Db_Adapter, getNestedTransactionSavepointName) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_transactionLevel"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_SV(return_value, "PHALCON_SAVEPOINT_", &_0);
	return;

}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *<code>
 * //Inserting a new robot with a valid default value for the column 'id'
 * $success = $connection->insert(
 *	 "robots",
 *	 array($connection->getDefaultIdValue(), "Astro Boy", 1952),
 *	 array("id", "name", "year")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, getDefaultIdValue) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "null");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the default value to make the RBDM use the default value declared in the table definition
 *
 *<code>
 * //Inserting a new robot with a valid default value for the column 'year'
 * $success = $connection->insert(
 *	 "robots",
 *	 array("Astro Boy", $connection->getDefaultValue()),
 *	 array("name", "year")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, getDefaultValue) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DEFAULT");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter, supportSequences) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(0);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter, useExplicitIdValue) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(0);

}

/**
 * Return descriptor used to connect to the active database
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getDescriptor) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_descriptor");

}

/**
 * Gets the active connection unique identifier
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getConnectionId) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_connectionId");

}

/**
 * Active SQL statement in the object
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_sqlStatement");

}

/**
 * Active SQL statement in the object without replace bound paramters
 */
PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_sqlStatement");

}

/**
 * Active SQL statement in the object
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_sqlBindTypes");

}

