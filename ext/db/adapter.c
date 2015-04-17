/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "db/adapter.h"
#include "db/adapterinterface.h"
#include "db/dialectinterface.h"
#include "db/exception.h"
#include "db/index.h"
#include "db/rawvalue.h"
#include "db/reference.h"
#include "events/eventsawareinterface.h"

#include "ext/pdo/php_pdo_driver.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/hash.h"
#include "kernel/string.h"

/**
 * Phalcon\Db\Adapter
 *
 * Base class for Phalcon\Db adapters
 */
zend_class_entry *phalcon_db_adapter_ce;

PHP_METHOD(Phalcon_Db_Adapter, __construct);
PHP_METHOD(Phalcon_Db_Adapter, setEventsManager);
PHP_METHOD(Phalcon_Db_Adapter, getEventsManager);
PHP_METHOD(Phalcon_Db_Adapter, setDialect);
PHP_METHOD(Phalcon_Db_Adapter, getDialect);
PHP_METHOD(Phalcon_Db_Adapter, fetchOne);
PHP_METHOD(Phalcon_Db_Adapter, fetchAll);
PHP_METHOD(Phalcon_Db_Adapter, insert);
PHP_METHOD(Phalcon_Db_Adapter, update);
PHP_METHOD(Phalcon_Db_Adapter, delete);
PHP_METHOD(Phalcon_Db_Adapter, getColumnList);
PHP_METHOD(Phalcon_Db_Adapter, limit);
PHP_METHOD(Phalcon_Db_Adapter, tableExists);
PHP_METHOD(Phalcon_Db_Adapter, viewExists);
PHP_METHOD(Phalcon_Db_Adapter, forUpdate);
PHP_METHOD(Phalcon_Db_Adapter, sharedLock);
PHP_METHOD(Phalcon_Db_Adapter, createTable);
PHP_METHOD(Phalcon_Db_Adapter, dropTable);
PHP_METHOD(Phalcon_Db_Adapter, createView);
PHP_METHOD(Phalcon_Db_Adapter, dropView);
PHP_METHOD(Phalcon_Db_Adapter, addColumn);
PHP_METHOD(Phalcon_Db_Adapter, modifyColumn);
PHP_METHOD(Phalcon_Db_Adapter, dropColumn);
PHP_METHOD(Phalcon_Db_Adapter, addIndex);
PHP_METHOD(Phalcon_Db_Adapter, dropIndex);
PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Adapter, addForeignKey);
PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey);
PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Adapter, listTables);
PHP_METHOD(Phalcon_Db_Adapter, listViews);
PHP_METHOD(Phalcon_Db_Adapter, describeIndexes);
PHP_METHOD(Phalcon_Db_Adapter, describeReferences);
PHP_METHOD(Phalcon_Db_Adapter, tableOptions);
PHP_METHOD(Phalcon_Db_Adapter, createSavepoint);
PHP_METHOD(Phalcon_Db_Adapter, releaseSavepoint);
PHP_METHOD(Phalcon_Db_Adapter, rollbackSavepoint);
PHP_METHOD(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints);
PHP_METHOD(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints);
PHP_METHOD(Phalcon_Db_Adapter, getNestedTransactionSavepointName);
PHP_METHOD(Phalcon_Db_Adapter, getDefaultIdValue);
PHP_METHOD(Phalcon_Db_Adapter, supportSequences);
PHP_METHOD(Phalcon_Db_Adapter, useExplicitIdValue);
PHP_METHOD(Phalcon_Db_Adapter, getDescriptor);
PHP_METHOD(Phalcon_Db_Adapter, getConnectionId);
PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement);
PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement);
PHP_METHOD(Phalcon_Db_Adapter, getSQLVariables);
PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes);
PHP_METHOD(Phalcon_Db_Adapter, getType);
PHP_METHOD(Phalcon_Db_Adapter, getDialectType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_setdialect, 0, 0, 1)
	ZEND_ARG_INFO(0, dialect)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_db_adapter_method_entry[] = {
	PHP_ME(Phalcon_Db_Adapter, __construct, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter, setEventsManager, arginfo_phalcon_db_adapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, setDialect, arginfo_phalcon_db_adapter_setdialect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getDialect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, fetchOne, arginfo_phalcon_db_adapterinterface_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, fetchAll, arginfo_phalcon_db_adapterinterface_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, insert, arginfo_phalcon_db_adapterinterface_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, update, arginfo_phalcon_db_adapterinterface_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, delete, arginfo_phalcon_db_adapterinterface_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getColumnList, arginfo_phalcon_db_adapterinterface_getcolumnlist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, limit, arginfo_phalcon_db_adapterinterface_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, tableExists, arginfo_phalcon_db_adapterinterface_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, viewExists, arginfo_phalcon_db_adapterinterface_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, forUpdate, arginfo_phalcon_db_adapterinterface_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, sharedLock, arginfo_phalcon_db_adapterinterface_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, createTable, arginfo_phalcon_db_adapterinterface_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropTable, arginfo_phalcon_db_adapterinterface_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, createView, arginfo_phalcon_db_adapterinterface_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropView, arginfo_phalcon_db_adapterinterface_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, addColumn, arginfo_phalcon_db_adapterinterface_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, modifyColumn, arginfo_phalcon_db_adapterinterface_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropColumn, arginfo_phalcon_db_adapterinterface_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, addIndex, arginfo_phalcon_db_adapterinterface_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropIndex, arginfo_phalcon_db_adapterinterface_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, addPrimaryKey, arginfo_phalcon_db_adapterinterface_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropPrimaryKey, arginfo_phalcon_db_adapterinterface_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, addForeignKey, arginfo_phalcon_db_adapterinterface_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropForeignKey, arginfo_phalcon_db_adapterinterface_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getColumnDefinition, arginfo_phalcon_db_adapterinterface_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, listTables, arginfo_phalcon_db_adapterinterface_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, listViews, arginfo_phalcon_db_adapterinterface_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, describeIndexes, arginfo_phalcon_db_adapterinterface_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, describeReferences, arginfo_phalcon_db_adapterinterface_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, tableOptions, arginfo_phalcon_db_adapterinterface_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, createSavepoint, arginfo_phalcon_db_adapterinterface_createsavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, releaseSavepoint, arginfo_phalcon_db_adapterinterface_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, rollbackSavepoint, arginfo_phalcon_db_adapterinterface_rollbacksavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapterinterface_setnestedtransactionswithsavepoints, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getNestedTransactionSavepointName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, supportSequences, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, useExplicitIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getDescriptor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getConnectionId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getSQLStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getRealSQLStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getSQLVariables, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getSQLBindTypes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getDialectType, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Db\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Adapter, db_adapter, phalcon_db_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_db_adapter_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_descriptor"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_dialectType"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_dialect"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_connectionId"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlBindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_adapter_ce, SL("_transactionLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_adapter_ce, SL("_transactionsWithSavepoints"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_adapter_ce, SL("_connectionConsecutive"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_ce TSRMLS_CC, 2, phalcon_events_eventsawareinterface_ce, phalcon_db_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Db\Adapter constructor
 *
 * @param array $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter, __construct){

	zval *descriptor, *connection_consecutive;
	zval *next_consecutive, *dialect_type, *dialect_class = NULL;
	zval *dialect_object;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &descriptor);
	
	/** 
	 * Every new connection created obtain a consecutive number from the static
	 * property self::$_connectionConsecutive
	 */
	connection_consecutive = phalcon_fetch_static_property_ce(phalcon_db_adapter_ce, SL("_connectionConsecutive") TSRMLS_CC);
	
	PHALCON_INIT_VAR(next_consecutive);
	phalcon_add_function(next_consecutive, connection_consecutive, PHALCON_GLOBAL(z_one) TSRMLS_CC);
	phalcon_update_static_property_ce(phalcon_db_adapter_ce, SL("_connectionConsecutive"), next_consecutive TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_connectionId"), connection_consecutive TSRMLS_CC);
	
	/** 
	 * Dialect class can override the default dialect
	 */
	if (!phalcon_array_isset_string_fetch(&dialect_class, descriptor, SS("dialectClass"))) {
		dialect_type = phalcon_fetch_nproperty_this(this_ptr, SL("_dialectType"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_VAR(dialect_class);
		PHALCON_CONCAT_SV(dialect_class, "phalcon\\db\\dialect\\", dialect_type);
	}
	
	/** 
	 * Create the instance only if the dialect is a string
	 */
	if (likely(Z_TYPE_P(dialect_class) == IS_STRING)) {
		ce0 = phalcon_fetch_class(dialect_class TSRMLS_CC);
		PHALCON_INIT_VAR(dialect_object);
		object_init_ex(dialect_object, ce0);
		if (phalcon_has_constructor(dialect_object TSRMLS_CC)) {
			PHALCON_CALL_METHOD(NULL, dialect_object, "__construct");
		}
		phalcon_update_property_this(this_ptr, SL("_dialect"), dialect_object TSRMLS_CC);
	}
	
	phalcon_update_property_this(this_ptr, SL("_descriptor"), descriptor TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Db_Adapter, setEventsManager){

	zval *events_manager;

	phalcon_fetch_params(0, 1, 0, &events_manager);
	
	phalcon_update_property_this(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Db_Adapter, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Sets the dialect used to produce the SQL
 *
 * @param Phalcon\Db\DialectInterface
 */
PHP_METHOD(Phalcon_Db_Adapter, setDialect){

	zval *dialect;

	phalcon_fetch_params(0, 1, 0, &dialect);
	PHALCON_VERIFY_INTERFACE_EX(dialect, phalcon_db_dialectinterface_ce, phalcon_db_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dialect"), dialect TSRMLS_CC);
}

/**
 * Returns internal dialect instance
 *
 * @return Phalcon\Db\DialectInterface
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialect){


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
 *
 * @param string $sqlQuery
 * @param int $fetchMode
 * @param array $bindParams
 * @param array $bindTypes
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchOne){

	zval *sql_query, *fetch_mode = NULL, *bind_params = NULL, *bind_types = NULL;
	zval *result = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &sql_query, &fetch_mode, &bind_params, &bind_types);
	
	if (!fetch_mode) {
		PHALCON_INIT_VAR(fetch_mode);
		ZVAL_LONG(fetch_mode, PDO_FETCH_BOTH);
	}
	
	if (!bind_params) {
		bind_params = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_types) {
		bind_types = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_CALL_METHOD(&result, this_ptr, "query", sql_query, bind_params, bind_types);
	if (Z_TYPE_P(result) == IS_OBJECT) {
		if (Z_TYPE_P(fetch_mode) != IS_NULL) {
			PHALCON_CALL_METHOD(NULL, result, "setfetchmode", fetch_mode);
		}
		PHALCON_RETURN_CALL_METHOD(result, "fetch");
		RETURN_MM();
	}
	
	RETURN_MM_EMPTY_ARRAY();
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
 * @param string $sqlQuery
 * @param int $fetchMode
 * @param array $bindParams
 * @param array $bindTypes
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchAll){

	zval *sql_query, *fetch_mode = NULL, *bind_params = NULL, *bind_types = NULL;
	zval *result = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &sql_query, &fetch_mode, &bind_params, &bind_types);
	
	if (!fetch_mode) {
		PHALCON_INIT_VAR(fetch_mode);
		ZVAL_LONG(fetch_mode, PDO_FETCH_BOTH);
	}
	
	if (!bind_params) {
		bind_params = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_types) {
		bind_types = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_CALL_METHOD(&result, this_ptr, "query", sql_query, bind_params, bind_types);
	if (likely(Z_TYPE_P(result) == IS_OBJECT)) {
		if (Z_TYPE_P(fetch_mode) != IS_NULL) {
			PHALCON_CALL_METHOD(NULL, result, "setfetchmode", fetch_mode);
		}

		PHALCON_RETURN_CALL_METHOD(result, "fetchall");
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * <code>
 * //Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     array("Astro Boy", 1952),
 *     array("name", "year")
 * );
 *
 * //Next SQL sentence is sent to the database system
 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
 * </code>
 *
 * @param 	string $table
 * @param 	array $values
 * @param 	array $fields
 * @param 	array $dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, insert){

	zval *table, *values, *fields = NULL, *data_types = NULL, *exception_message;
	zval *placeholders, *insert_values, *bind_data_types = NULL;
	zval *value = NULL, *position = NULL, *str_value = NULL, *bind_type = NULL;
	zval *escaped_table = NULL, *joined_values, *escaped_fields = NULL;
	zval *field = NULL, *escaped_field = NULL, *joined_fields;
	zval *insert_sql = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 2, &table, &values, &fields, &data_types);
	
	if (!fields) {
		fields = PHALCON_GLOBAL(z_null);
	}
	
	if (!data_types) {
		data_types = PHALCON_GLOBAL(z_null);
	}
	
	if (unlikely(Z_TYPE_P(values) != IS_ARRAY)) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The second parameter for insert isn't an Array");
		return;
	}
	
	/** 
	 * A valid array with more than one element is required
	 */
	if (!phalcon_fast_count_ev(values TSRMLS_CC)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Unable to insert into ", table, " without data");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_db_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(placeholders);
	array_init(placeholders);
	
	PHALCON_INIT_VAR(insert_values);
	array_init(insert_values);
	if (Z_TYPE_P(data_types) == IS_ARRAY) { 
		PHALCON_INIT_VAR(bind_data_types);
		array_init(bind_data_types);
	} else {
		PHALCON_CPY_WRT(bind_data_types, data_types);
	}
	
	/** 
	 * Objects are casted using __toString, null values are converted to string 'null',
	 * everything else is passed as '?'
	 */
	phalcon_is_iterable(values, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(position, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (Z_TYPE_P(value) == IS_OBJECT) {
			PHALCON_INIT_NVAR(str_value);
			phalcon_strval(str_value, value);
			phalcon_array_append(&placeholders, str_value, 0);
		} else {
			if (Z_TYPE_P(value) == IS_NULL) {
				phalcon_array_append_string(&placeholders, SL("null"), 0);
			} else {
				phalcon_array_append_string(&placeholders, SL("?"), 0);
				phalcon_array_append(&insert_values, value, 0);
				if (Z_TYPE_P(data_types) == IS_ARRAY) { 
					if (!phalcon_array_isset(data_types, position)) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Incomplete number of bind types");
						return;
					}
	
					PHALCON_OBS_NVAR(bind_type);
					phalcon_array_fetch(&bind_type, data_types, position, PH_NOISY);
					phalcon_array_append(&bind_data_types, bind_type, PH_SEPARATE);
				}
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_CALL_METHOD(&escaped_table, this_ptr, "escapeidentifier", table);
	} else {
		PHALCON_CPY_WRT(escaped_table, table);
	}
	
	/** 
	 * Build the final SQL INSERT statement
	 */
	PHALCON_INIT_VAR(joined_values);
	phalcon_fast_join_str(joined_values, SL(", "), placeholders TSRMLS_CC);
	if (Z_TYPE_P(fields) == IS_ARRAY) { 
		if (PHALCON_GLOBAL(db).escape_identifiers) {
	
			PHALCON_INIT_VAR(escaped_fields);
			array_init(escaped_fields);
	
			phalcon_is_iterable(fields, &ah1, &hp1, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_HVALUE(field);
	
				PHALCON_CALL_METHOD(&escaped_field, this_ptr, "escapeidentifier", field);
				phalcon_array_append(&escaped_fields, escaped_field, 0);
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		} else {
			PHALCON_CPY_WRT(escaped_fields, fields);
		}
	
		PHALCON_INIT_VAR(joined_fields);
		phalcon_fast_join_str(joined_fields, SL(", "), escaped_fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(insert_sql);
		PHALCON_CONCAT_SVSVSVS(insert_sql, "INSERT INTO ", escaped_table, " (", joined_fields, ") VALUES (", joined_values, ")");
	} else {
		PHALCON_INIT_VAR(insert_sql);
		PHALCON_CONCAT_SVSVS(insert_sql, "INSERT INTO ", escaped_table, " VALUES (", joined_values, ")");
	}
	
	/** 
	 * Perform the execution via execute
	 */
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", insert_sql, insert_values, bind_data_types);
	RETURN_MM();
}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * <code>
 * //Updating existing robot
 * $success = $connection->update(
 *     "robots",
 *     array("name"),
 *     array("New Astro Boy"),
 *     "id = 101"
 * );
 *
 * //Next SQL sentence is sent to the database system
 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
 * </code>
 *
 * @param 	string $table
 * @param 	array $fields
 * @param 	array $values
 * @param 	string $whereCondition
 * @param 	array $dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, update){

	zval *table, *fields, *values, *where_condition = NULL;
	zval *data_types = NULL, *placeholders, *update_values;
	zval *bind_data_types = NULL, *value = NULL, *position = NULL, *field = NULL;
	zval *escaped_field = NULL, *set_clause_part = NULL, *bind_type = NULL;
	zval *escaped_table = NULL, *set_clause, *update_sql = NULL;
	zval *conditions, *where_bind, *where_types;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 2, &table, &fields, &values, &where_condition, &data_types);
	
	if (!where_condition) {
		where_condition = PHALCON_GLOBAL(z_null);
	}
	
	if (!data_types) {
		data_types = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(placeholders);
	array_init(placeholders);
	
	PHALCON_INIT_VAR(update_values);
	array_init(update_values);
	if (Z_TYPE_P(data_types) == IS_ARRAY) { 
		PHALCON_INIT_VAR(bind_data_types);
		array_init(bind_data_types);
	} else {
		PHALCON_CPY_WRT(bind_data_types, data_types);
	}
	
	/** 
	 * Objects are casted using __toString, null values are converted to string 'null',
	 * everything else is passed as '?'
	 */
	phalcon_is_iterable(values, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(position, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (!phalcon_array_isset(fields, position)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The number of values in the update is not the same as fields");
			return;
		}
	
		PHALCON_OBS_NVAR(field);
		phalcon_array_fetch(&field, fields, position, PH_NOISY);
		if (PHALCON_GLOBAL(db).escape_identifiers) {
			PHALCON_CALL_METHOD(&escaped_field, this_ptr, "escapeidentifier", field);
		} else {
			PHALCON_CPY_WRT(escaped_field, field);
		}
	
		if (Z_TYPE_P(value) == IS_OBJECT) {
			PHALCON_INIT_NVAR(set_clause_part);
			PHALCON_CONCAT_VSV(set_clause_part, escaped_field, " = ", value);
			phalcon_array_append(&placeholders, set_clause_part, 0);
		} else {
			if (Z_TYPE_P(value) == IS_NULL) {
				PHALCON_INIT_NVAR(set_clause_part);
				PHALCON_CONCAT_VS(set_clause_part, escaped_field, " = null");
			} else {
				PHALCON_INIT_NVAR(set_clause_part);
				PHALCON_CONCAT_VS(set_clause_part, escaped_field, " = ?");
				phalcon_array_append(&update_values, value, PH_SEPARATE);
				if (Z_TYPE_P(data_types) == IS_ARRAY) { 
					if (!phalcon_array_isset(data_types, position)) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Incomplete number of bind types");
						return;
					}
	
					PHALCON_OBS_NVAR(bind_type);
					phalcon_array_fetch(&bind_type, data_types, position, PH_NOISY);
					phalcon_array_append(&bind_data_types, bind_type, PH_SEPARATE);
				}
			}
			phalcon_array_append(&placeholders, set_clause_part, PH_SEPARATE);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_CALL_METHOD(&escaped_table, this_ptr, "escapeidentifier", table);
	} else {
		PHALCON_CPY_WRT(escaped_table, table);
	}
	
	PHALCON_INIT_VAR(set_clause);
	phalcon_fast_join_str(set_clause, SL(", "), placeholders TSRMLS_CC);
	if (Z_TYPE_P(where_condition) != IS_NULL) {
	
		PHALCON_INIT_VAR(update_sql);
		PHALCON_CONCAT_SVSVS(update_sql, "UPDATE ", escaped_table, " SET ", set_clause, " WHERE ");
	
		/** 
		 * String conditions are simply appended to the SQL
		 */
		if (Z_TYPE_P(where_condition) == IS_STRING) {
			phalcon_concat_self(&update_sql, where_condition TSRMLS_CC);
		} else {
			/** 
			 * Array conditions may have bound params and bound types
			 */
			if (unlikely(Z_TYPE_P(where_condition) != IS_ARRAY)) { 
				PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid WHERE clause conditions");
				return;
			}
	
			/** 
			 * If an index 'conditions' is present it contains string where conditions that are
			 * appended to the UPDATE sql
			 */
			if (phalcon_array_isset_string(where_condition, SS("conditions"))) {
				PHALCON_OBS_VAR(conditions);
				phalcon_array_fetch_string(&conditions, where_condition, SL("conditions"), PH_NOISY);
				phalcon_concat_self(&update_sql, conditions TSRMLS_CC);
			}
	
			/** 
			 * Bound parameters are arbitrary values that are passed by separate
			 */
			if (phalcon_array_isset_string(where_condition, SS("bind"))) {
				PHALCON_OBS_VAR(where_bind);
				phalcon_array_fetch_string(&where_bind, where_condition, SL("bind"), PH_NOISY);
				phalcon_merge_append(update_values, where_bind);
			}
	
			/** 
			 * Bind types is how the bound parameters must be casted before be sent to the
			 * database system
			 */
			if (phalcon_array_isset_string(where_condition, SS("bindTypes"))) {
				PHALCON_OBS_VAR(where_types);
				phalcon_array_fetch_string(&where_types, where_condition, SL("bindTypes"), PH_NOISY);
				phalcon_merge_append(bind_data_types, where_types);
			}
		}
	} else {
		PHALCON_INIT_NVAR(update_sql);
		PHALCON_CONCAT_SVSV(update_sql, "UPDATE ", escaped_table, " SET ", set_clause);
	}
	
	/** 
	 * Perform the update via execute
	 */
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", update_sql, update_values, bind_data_types);
	RETURN_MM();
}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * <code>
 * //Deleting existing robot
 * $success = $connection->delete(
 *     "robots",
 *     "id = 101"
 * );
 *
 * //Next SQL sentence is generated
 * DELETE FROM `robots` WHERE `id` = 101
 * </code>
 *
 * @param  string $table
 * @param  string $whereCondition
 * @param  array $placeholders
 * @param  array $dataTypes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, delete){

	zval *table, *where_condition = NULL, *placeholders = NULL;
	zval *data_types = NULL, *escaped_table = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &table, &where_condition, &placeholders, &data_types);
	
	if (!where_condition) {
		where_condition = PHALCON_GLOBAL(z_null);
	}
	
	if (!placeholders) {
		placeholders = PHALCON_GLOBAL(z_null);
	}
	
	if (!data_types) {
		data_types = PHALCON_GLOBAL(z_null);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_CALL_METHOD(&escaped_table, this_ptr, "escapeidentifier", table);
	} else {
		PHALCON_CPY_WRT(escaped_table, table);
	}

	PHALCON_INIT_VAR(sql);
	if (PHALCON_IS_NOT_EMPTY(where_condition)) {
		PHALCON_CONCAT_SVSV(sql, "DELETE FROM ", escaped_table, " WHERE ", where_condition);
	} else {
		PHALCON_CONCAT_SV(sql, "DELETE FROM ", escaped_table);
	}
	
	/** 
	 * Perform the update via execute
	 */
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql, placeholders, data_types);
	RETURN_MM();
}

/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnList){

	zval *column_list, *dialect;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &column_list);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(dialect, "getcolumnlist", column_list);
	RETURN_MM();
}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * <code>
 * 	echo $connection->limit("SELECT * FROM robots", 5);
 * </code>
 *
 * @param  	string $sqlQuery
 * @param 	int $number
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Adapter, limit){

	zval *sql_query, *number, *dialect;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &sql_query, &number);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(dialect, "limit", sql_query, number);
	RETURN_MM();
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>
 * 	var_dump($connection->tableExists("blog", "posts"));
 * </code>
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, tableExists){

	zval *table_name, *schema_name = NULL, *dialect, *sql = NULL;
	zval *fetch_num, *num = NULL, *first;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table_name, &schema_name);
	
	if (!schema_name) {
		schema_name = PHALCON_GLOBAL(z_null);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "tableexists", table_name, schema_name);
	
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, PDO_FETCH_NUM);
	
	PHALCON_CALL_METHOD(&num, this_ptr, "fetchone", sql, fetch_num);
	
	PHALCON_OBS_VAR(first);
	phalcon_array_fetch_long(&first, num, 0, PH_NOISY);
	RETURN_CCTOR(first);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 *<code>
 * var_dump($connection->viewExists("active_users", "posts"));
 *</code>
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, viewExists){

	zval *view_name, *schema_name = NULL, *dialect, *sql = NULL, *fetch_num;
	zval *num = NULL, *first;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &view_name, &schema_name);
	
	if (!schema_name) {
		schema_name = PHALCON_GLOBAL(z_null);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "viewexists", view_name, schema_name);
	
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, PDO_FETCH_NUM);
	
	PHALCON_CALL_METHOD(&num, this_ptr, "fetchone", sql, fetch_num);
	
	PHALCON_OBS_VAR(first);
	phalcon_array_fetch_long(&first, num, 0, PH_NOISY);
	RETURN_CCTOR(first);
}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, forUpdate){

	zval *sql_query, *dialect;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &sql_query);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(dialect, "forupdate", sql_query);
	RETURN_MM();
}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, sharedLock){

	zval *sql_query, *dialect;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &sql_query);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(dialect, "sharedlock", sql_query);
	RETURN_MM();
}

/**
 * Creates a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, createTable){

	zval *table_name, *schema_name, *definition;
	zval *exception_message, *columns, *dialect;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &definition);
	
	if (Z_TYPE_P(definition) != IS_ARRAY) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid definition to create the table '", table_name, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_db_exception_ce, exception_message);
		return;
	}

	if (!phalcon_array_isset_string_fetch(&columns, definition, SS("columns"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
		return;
	}
	
	if (!phalcon_fast_count_ev(columns TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
		return;
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "createtable", table_name, schema_name, definition);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Drops a table from a schema/database
 *
 * @param string $tableName
 * @param   string $schemaName
 * @param boolean $ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropTable){

	zval *table_name, *schema_name = NULL, *if_exists = NULL, *dialect;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &table_name, &schema_name, &if_exists);
	
	if (!schema_name) {
		schema_name = PHALCON_GLOBAL(z_null);
	}
	
	if (!if_exists) {
		if_exists = PHALCON_GLOBAL(z_true);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "droptable", table_name, schema_name, if_exists);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Creates a view
 *
 * @param string $tableName
 * @param array $definition
 * @param string $schemaName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, createView){

	zval *view_name, *definition, *schema_name = NULL, *exception_message;
	zval *dialect, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &view_name, &definition, &schema_name);
	
	if (!schema_name) {
		schema_name = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(definition) != IS_ARRAY) { 
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid definition to create the view '", view_name, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_db_exception_ce, exception_message);
		return;
	}

	if (!phalcon_array_isset_string(definition, SS("sql"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
		return;
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "createview", view_name, definition, schema_name);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Drops a view
 *
 * @param string $viewName
 * @param   string $schemaName
 * @param boolean $ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropView){

	zval *view_name, *schema_name = NULL, *if_exists = NULL, *dialect;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &view_name, &schema_name, &if_exists);
	
	if (!schema_name) {
		schema_name = PHALCON_GLOBAL(z_null);
	}
	
	if (!if_exists) {
		if_exists = PHALCON_GLOBAL(z_true);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "dropview", view_name, schema_name, if_exists);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Adds a column to a table
 *
 * @param string $tableName
 * @param 	string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, addColumn){

	zval *table_name, *schema_name, *column, *dialect;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &column);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "addcolumn", table_name, schema_name, column);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Modifies a table column based on a definition
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, modifyColumn){

	zval *table_name, *schema_name, *column, *dialect;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &column);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "modifycolumn", table_name, schema_name, column);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Drops a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropColumn){

	zval *table_name, *schema_name, *column_name;
	zval *dialect, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &column_name);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "dropcolumn", table_name, schema_name, column_name);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Adds an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, addIndex){

	zval *table_name, *schema_name, *index, *dialect;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &index);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "addindex", table_name, schema_name, index);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Drop an index from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $indexName
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropIndex){

	zval *table_name, *schema_name, *index_name;
	zval *dialect, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &index_name);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "dropindex", table_name, schema_name, index_name);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Adds a primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey){

	zval *table_name, *schema_name, *index, *dialect;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &index);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "addprimarykey", table_name, schema_name, index);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Drops a table's primary key
 *
 * @param string $tableName
 * @param string $schemaName
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey){

	zval *table_name, *schema_name, *dialect, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &table_name, &schema_name);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "dropprimarykey", table_name, schema_name);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Adds a foreign key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ReferenceInterface $reference
 * @return boolean true
 */
PHP_METHOD(Phalcon_Db_Adapter, addForeignKey){

	zval *table_name, *schema_name, *reference, *dialect;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &reference);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "addforeignkey", table_name, schema_name, reference);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Drops a foreign key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $referenceName
 * @return boolean true
 */
PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey){

	zval *table_name, *schema_name, *reference_name;
	zval *dialect, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &table_name, &schema_name, &reference_name);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "dropforeignkey", table_name, schema_name, reference_name);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Returns the SQL column definition from a column
 *
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition){

	zval *column, *dialect;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &column);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(dialect, "getcolumndefinition", column);
	RETURN_MM();
}

/**
 * List all tables on a database
 *
 *<code>
 * 	print_r($connection->listTables("blog"));
 *</code>
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, listTables){

	zval *schema_name = NULL, *dialect, *sql = NULL, *fetch_num, *tables = NULL;
	zval **table, *table_name;
	HashPosition hp0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &schema_name);
	
	if (!schema_name) {
		schema_name = PHALCON_GLOBAL(z_null);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Get the SQL to list the tables
	 */
	PHALCON_CALL_METHOD(&sql, dialect, "listtables", schema_name);
	
	/** 
	 * Use fetch Num
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, PDO_FETCH_NUM);
	
	/** 
	 * Execute the SQL returning the tables
	 */
	PHALCON_CALL_METHOD(&tables, this_ptr, "fetchall", sql, fetch_num);
	
	if (Z_TYPE_P(tables) == IS_ARRAY) {
		array_init_size(return_value, zend_hash_num_elements(Z_ARRVAL_P(tables)));

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(tables), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(tables), (void**)&table, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(tables), &hp0)
		) {
			if (phalcon_array_isset_long_fetch(&table_name, *table, 0)) {
				phalcon_array_append(&return_value, table_name, 0);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * List all views on a database
 *
 *<code>
 *	print_r($connection->listViews("blog")); ?>
 *</code>
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, listViews){

	zval *schema_name = NULL, *dialect, *sql = NULL, *fetch_num, *tables = NULL;
	zval **table, *table_name;
	HashPosition hp0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &schema_name);
	
	if (!schema_name) {
		schema_name = PHALCON_GLOBAL(z_null);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Get the SQL to list the tables
	 */
	PHALCON_CALL_METHOD(&sql, dialect, "listviews", schema_name);
	
	/** 
	 * Use fetch Num
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, PDO_FETCH_NUM);
	
	/** 
	 * Execute the SQL returning the tables
	 */
	PHALCON_CALL_METHOD(&tables, this_ptr, "fetchall", sql, fetch_num);
	
	if (Z_TYPE_P(tables) == IS_ARRAY) {
		array_init_size(return_value, zend_hash_num_elements(Z_ARRVAL_P(tables)));

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(tables), &hp0);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(tables), (void**)&table, &hp0) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(tables), &hp0)
		) {
			if (phalcon_array_isset_long_fetch(&table_name, *table, 0)) {
				phalcon_array_append(&return_value, table_name, 0);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Lists table indexes
 *
 *<code>
 *	print_r($connection->describeIndexes('robots_parts'));
 *</code>
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Index[]
 */
PHP_METHOD(Phalcon_Db_Adapter, describeIndexes){

	zval *table, *schema = NULL, *dialect, *fetch_num, *sql = NULL, *describe = NULL;
	zval *indexes, *index = NULL, *key_name = NULL, *column_name = NULL;
	zval *index_columns = NULL, *name = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		schema = PHALCON_GLOBAL(z_null);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * We're using FETCH_NUM to fetch the columns
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, PDO_FETCH_NUM);
	
	/** 
	 * Get the SQL required to describe indexes from the Dialect
	 */
	PHALCON_CALL_METHOD(&sql, dialect, "describeindexes", table, schema);
	
	/** 
	 * Cryptic Guide: 2: table, 3: from, 4: to
	 */
	PHALCON_CALL_METHOD(&describe, this_ptr, "fetchall", sql, fetch_num);
	
	PHALCON_INIT_VAR(indexes);
	array_init(indexes);
	
	phalcon_is_iterable(describe, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(index);

		PHALCON_OBS_NVAR(key_name);
		phalcon_array_fetch_long(&key_name, index, 2, PH_NOISY);
	
		PHALCON_OBS_NVAR(column_name);
		phalcon_array_fetch_long(&column_name, index, 4, PH_NOISY);
		phalcon_array_append_multi_2(&indexes, key_name, column_name, 0);

		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	array_init(return_value);
	
	phalcon_is_iterable(indexes, &ah1, &hp1, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_HKEY(name, ah1, hp1);
		PHALCON_GET_HVALUE(index_columns);
	
		/** 
		 * Every index is abstracted using a Phalcon\Db\Index instance
		 */
		PHALCON_INIT_NVAR(index);
		object_init_ex(index, phalcon_db_index_ce);
		PHALCON_CALL_METHOD(NULL, index, "__construct", name, index_columns);
	
		phalcon_array_update_zval(&return_value, name, index, PH_COPY);
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Lists table references
 *
 *<code>
 * print_r($connection->describeReferences('robots_parts'));
 *</code>
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Reference[]
 */
PHP_METHOD(Phalcon_Db_Adapter, describeReferences){

	zval *table, *schema = NULL, *dialect, *fetch_num, *sql = NULL, *empty_arr;
	zval *references, *describe = NULL, *reference = NULL, *constraint_name = NULL;
	zval *referenced_schema = NULL, *referenced_table = NULL;
	zval *reference_array = NULL, *column_name = NULL, *referenced_columns = NULL;
	zval *array_reference = NULL;
	zval *name = NULL, *columns = NULL, *definition = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		schema = PHALCON_GLOBAL(z_null);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * We're using FETCH_NUM to fetch the columns
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, PDO_FETCH_NUM);
	
	/** 
	 * Get the SQL required to describe the references from the Dialect
	 */
	PHALCON_CALL_METHOD(&sql, dialect, "describereferences", table, schema);
	
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);

	PHALCON_INIT_VAR(references);
	array_init(references);
	
	/** 
	 * Execute the SQL returning the 
	 */
	PHALCON_CALL_METHOD(&describe, this_ptr, "fetchall", sql, fetch_num);
	
	phalcon_is_iterable(describe, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(reference);
	
		PHALCON_OBS_NVAR(constraint_name);
		phalcon_array_fetch_long(&constraint_name, reference, 2, PH_NOISY);
		if (!phalcon_array_isset(references, constraint_name)) {
			PHALCON_OBS_NVAR(referenced_schema);
			phalcon_array_fetch_long(&referenced_schema, reference, 3, PH_NOISY);
	
			PHALCON_OBS_NVAR(referenced_table);
			phalcon_array_fetch_long(&referenced_table, reference, 4, PH_NOISY);
	
			PHALCON_INIT_NVAR(reference_array);
			array_init_size(reference_array, 4);
			phalcon_array_update_string(&reference_array, SL("referencedSchema"), referenced_schema, PH_COPY);
			phalcon_array_update_string(&reference_array, SL("referencedTable"), referenced_table, PH_COPY);
			phalcon_array_update_string(&reference_array, SL("columns"), empty_arr, PH_COPY);
			phalcon_array_update_string(&reference_array, SL("referencedColumns"), empty_arr, PH_COPY);
			phalcon_array_update_zval(&references, constraint_name, reference_array, PH_COPY);
		}
	
		PHALCON_OBS_NVAR(column_name);
		phalcon_array_fetch_long(&column_name, reference, 1, PH_NOISY);
		phalcon_array_update_zval_string_append_multi_3(&references, constraint_name, SL("columns"), column_name, 0);
	
		PHALCON_OBS_NVAR(referenced_columns);
		phalcon_array_fetch_long(&referenced_columns, reference, 5, PH_NOISY);
		phalcon_array_update_zval_string_append_multi_3(&references, constraint_name, SL("referencedColumns"), referenced_columns, 0);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	array_init(return_value);
	
	phalcon_is_iterable(references, &ah1, &hp1, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
		PHALCON_GET_HKEY(name, ah1, hp1);
		PHALCON_GET_HVALUE(array_reference);
	
		PHALCON_OBS_NVAR(referenced_schema);

		phalcon_array_fetch_string(&referenced_schema, array_reference, SL("referencedSchema"), PH_NOISY);
	
		PHALCON_OBS_NVAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, array_reference, SL("referencedTable"), PH_NOISY);
	
		PHALCON_OBS_NVAR(columns);
		phalcon_array_fetch_string(&columns, array_reference, SL("columns"), PH_NOISY);
	
		PHALCON_OBS_NVAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, array_reference, SL("referencedColumns"), PH_NOISY);
	
		PHALCON_INIT_NVAR(definition);
		array_init_size(definition, 4);
		phalcon_array_update_string(&definition, SL("referencedSchema"), referenced_schema, PH_COPY);
		phalcon_array_update_string(&definition, SL("referencedTable"), referenced_table, PH_COPY);
		phalcon_array_update_string(&definition, SL("columns"), columns, PH_COPY );
		phalcon_array_update_string(&definition, SL("referencedColumns"), referenced_columns, PH_COPY);
	
		PHALCON_INIT_NVAR(reference);
		object_init_ex(reference, phalcon_db_reference_ce);
		PHALCON_CALL_METHOD(NULL, reference, "__construct", name, definition);
	
		phalcon_array_update_zval(&return_value, name, reference, PH_COPY);
	
		zend_hash_move_forward_ex(ah1, &hp1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets creation options from a table
 *
 *<code>
 * print_r($connection->tableOptions('robots'));
 *</code>
 *
 * @param string $tableName
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, tableOptions){

	zval *table_name, *schema_name = NULL, *dialect, *sql = NULL;
	zval *fetch_assoc, *describe = NULL, *first;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table_name, &schema_name);
	
	if (!schema_name) {
		schema_name = PHALCON_GLOBAL(z_null);
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&sql, dialect, "tableoptions", table_name, schema_name);
	if (zend_is_true(sql)) {
		PHALCON_INIT_VAR(fetch_assoc);
		ZVAL_LONG(fetch_assoc, PDO_FETCH_ASSOC);
	
		PHALCON_CALL_METHOD(&describe, this_ptr, "fetchall", sql, fetch_assoc);
	
		PHALCON_OBS_VAR(first);
		phalcon_array_fetch_long(&first, describe, 0, PH_NOISY);
		RETURN_CCTOR(first);
	}
	
	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Creates a new savepoint
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, createSavepoint){

	zval *name, *dialect, *supports_sp = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&supports_sp, dialect, "supportssavepoints");
	if (!zend_is_true(supports_sp)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter.");
		return;
	}
	
	PHALCON_CALL_METHOD(&sql, dialect, "createsavepoint", name);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Releases given savepoint
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, releaseSavepoint){

	zval *name, *dialect, *supports_sp = NULL, *supports_rsp = NULL;
	zval *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&supports_sp, dialect, "supportssavepoints");
	if (!zend_is_true(supports_sp)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter");
		return;
	}
	
	PHALCON_CALL_METHOD(&supports_rsp, dialect, "supportsreleasesavepoints");
	if (!zend_is_true(supports_rsp)) {
		RETURN_MM_FALSE;
	}
	
	PHALCON_CALL_METHOD(&sql, dialect, "releasesavepoint", name);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Rollbacks given savepoint
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, rollbackSavepoint){

	zval *name, *dialect, *supports_sp = NULL, *sql = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&supports_sp, dialect, "supportssavepoints");
	if (!zend_is_true(supports_sp)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter");
		return;
	}
	
	PHALCON_CALL_METHOD(&sql, dialect, "rollbacksavepoint", name);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "execute", sql);
	RETURN_MM();
}

/**
 * Set if nested transactions should use savepoints
 *
 * @param boolean $nestedTransactionsWithSavepoints
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints){

	zval *nested_transactions_with_savepoints;
	zval *transaction_level, *dialect, *supports_sp = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &nested_transactions_with_savepoints);
	
	transaction_level = phalcon_fetch_nproperty_this(this_ptr, SL("_transactionLevel"), PH_NOISY TSRMLS_CC);
	if (PHALCON_GT_LONG(transaction_level, 0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Nested transaction with savepoints behavior cannot be changed while a transaction is open");
		return;
	}
	
	dialect = phalcon_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&supports_sp, dialect, "supportssavepoints");
	if (!zend_is_true(supports_sp)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_transactionsWithSavepoints"), nested_transactions_with_savepoints TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns if nested transactions should use savepoints
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints){


	RETURN_MEMBER(this_ptr, "_transactionsWithSavepoints");
}

/**
 * Returns the savepoint name to use for nested transactions
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getNestedTransactionSavepointName){

	zval *transaction_level;

	transaction_level = phalcon_fetch_nproperty_this(this_ptr, SL("_transactionLevel"), PH_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SV(return_value, "PHALCON_SAVEPOINT_", transaction_level);
}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *<code>
 * //Inserting a new robot with a valid default value for the column 'id'
 * $success = $connection->insert(
 *     "robots",
 *     array($connection->getDefaultIdValue(), "Astro Boy", 1952),
 *     array("id", "name", "year")
 * );
 *</code>
 *
 * @return Phalcon\Db\RawValue
 */
PHP_METHOD(Phalcon_Db_Adapter, getDefaultIdValue){

	zval *null_value;

	PHALCON_MM_GROW();

	PHALCON_ALLOC_GHOST_ZVAL(null_value);
	ZVAL_STRING(null_value, "null", 1);
	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", null_value);
	
	RETURN_MM();
}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, supportSequences){


	RETURN_FALSE;
}

/**
 * Check whether the database system requires an explicit value for identity columns
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, useExplicitIdValue){


	RETURN_FALSE;
}

/**
 * Return descriptor used to connect to the active database
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getDescriptor){


	RETURN_MEMBER(this_ptr, "_descriptor");
}

/**
 * Gets the active connection unique identifier
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getConnectionId){


	RETURN_MEMBER(this_ptr, "_connectionId");
}

/**
 * Active SQL statement in the object
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement){


	RETURN_MEMBER(this_ptr, "_sqlStatement");
}

/**
 * Active SQL statement in the object without replace bound paramters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement){


	RETURN_MEMBER(this_ptr, "_sqlStatement");
}

/**
 * Active SQL statement in the object
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLVariables){


	RETURN_MEMBER(this_ptr, "_sqlVariables");
}

/**
 * Active SQL statement in the object
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes){


	RETURN_MEMBER(this_ptr, "_sqlBindTypes");
}

/**
 * Returns type of database system the adapter is used for
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Returns the name of the dialect used
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialectType){


	RETURN_MEMBER(this_ptr, "_dialectType");
}
