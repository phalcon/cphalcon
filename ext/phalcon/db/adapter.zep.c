
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
#include "kernel/string.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Db\Adapter
 *
 * Base class for Phalcon\Db adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Adapter, phalcon, db_adapter, phalcon_db_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Connection ID
	 */
	zend_declare_property_long(phalcon_db_adapter_ce, SL("connectionConsecutive"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * Active connection ID
	 *
	 * @var long
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("connectionId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Descriptor used to connect to a database
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("descriptor"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Dialect instance
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("dialect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Name of the dialect used
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("dialectType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Event Manager
	 *
	 * @var Phalcon\Events\Manager
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL Bind Types
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("sqlBindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL Statement
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL bound parameter variables
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("sqlVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Current transaction level
	 */
	zend_declare_property_long(phalcon_db_adapter_ce, SL("transactionLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Whether the database supports transactions with save points
	 */
	zend_declare_property_bool(phalcon_db_adapter_ce, SL("transactionsWithSavepoints"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Type of database system the adapter is used for
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_adapter_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_db_adapter_ce->create_object = zephir_init_properties_Phalcon_Db_Adapter;

	zend_class_implements(phalcon_db_adapter_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);
	zend_class_implements(phalcon_db_adapter_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Name of the dialect used
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialectType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dialectType");

}

/**
 * Active SQL bound parameter variables
 */
PHP_METHOD(Phalcon_Db_Adapter, getSqlVariables) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sqlVariables");

}

/**
 * Type of database system the adapter is used for
 */
PHP_METHOD(Phalcon_Db_Adapter, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * Phalcon\Db\Adapter constructor
 */
PHP_METHOD(Phalcon_Db_Adapter, __construct) {

	zend_class_entry *_4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, dialectClass, connectionId, _0, _1$$3, _2$$4, _3$$4;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dialectClass);
	ZVAL_UNDEF(&connectionId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &descriptor_param);

	ZEPHIR_OBS_COPY_OR_DUP(&descriptor, descriptor_param);


	ZEPHIR_OBS_VAR(&connectionId);
	zephir_read_static_property_ce(&connectionId, phalcon_db_adapter_ce, SL("connectionConsecutive"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, SL("connectionId"), &connectionId);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(&connectionId) + 1));
	zend_update_static_property(phalcon_db_adapter_ce, ZEND_STRL("connectionConsecutive"), &_0);
	ZEPHIR_OBS_VAR(&dialectClass);
	if (!(zephir_array_isset_string_fetch(&dialectClass, &descriptor, SL("dialectClass"), 0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("dialectType"), PH_NOISY_CC | PH_READONLY);
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
		zephir_update_property_zval(this_ptr, SL("dialect"), &_2$$4);
	} else if (Z_TYPE_P(&dialectClass) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, SL("dialect"), &dialectClass);
	}
	zephir_update_property_zval(this_ptr, SL("descriptor"), &descriptor);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a column to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, _0, _1;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addcolumn", NULL, 0, &tableName, &schemaName, column);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a foreign key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, _0, _1;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addforeignkey", NULL, 0, &tableName, &schemaName, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds an index to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, _0, _1;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addindex", NULL, 0, &tableName, &schemaName, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a primary key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, _0, _1;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addprimarykey", NULL, 0, &tableName, &schemaName, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a new savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, createSavepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, dialect, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dialect, &_0);
	ZEPHIR_CALL_METHOD(&_1, &dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter.", "phalcon/Db/Adapter.zep", 197);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, &dialect, "createsavepoint", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a table
 */
PHP_METHOD(Phalcon_Db_Adapter, createTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, columns, _0, _1;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/Db/Adapter.zep", 213);
		return;
	}
	if (UNEXPECTED(!(zephir_fast_count_int(&columns TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/Db/Adapter.zep", 217);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "createtable", NULL, 0, &tableName, &schemaName, &definition);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a view
 */
PHP_METHOD(Phalcon_Db_Adapter, createView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, _0, _1;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (UNEXPECTED(!(zephir_array_isset_string(&definition, SL("sql"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/Db/Adapter.zep", 235);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "createview", NULL, 0, &viewName, &definition, &schemaName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
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
 * @param  string whereCondition
 * @param  array placeholders
 * @param  array dataTypes
 */
PHP_METHOD(Phalcon_Db_Adapter, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *whereCondition = NULL, whereCondition_sub, *placeholders = NULL, placeholders_sub, *dataTypes = NULL, dataTypes_sub, __$null, sql, escapedTable, _0$$3;
	zval table;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&whereCondition_sub);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&escapedTable);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &table_param, &whereCondition, &placeholders, &dataTypes);

	zephir_get_strval(&table, table_param);
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


	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SV(&sql, "DELETE FROM ", &escapedTable);
	if (!(ZEPHIR_IS_EMPTY(whereCondition))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, " WHERE ", whereCondition);
		zephir_concat_self(&sql, &_0$$3 TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &sql, placeholders, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Lists table indexes
 *
 *<code>
 * print_r(
 *     $connection->describeIndexes("robots_parts")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, describeIndexes) {

	zend_string *_8;
	zend_ulong _7;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, indexes, index, keyName, indexObjects, name, indexColumns, columns, _0, _1, _2, _3, *_4, *_6, _5$$3, _9$$6;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
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
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property(&_1, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter.zep", 311);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _4);
		zephir_array_fetch_long(&keyName, &index, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 299 TSRMLS_CC);
		if (!(zephir_array_isset(&indexes, &keyName))) {
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
		} else {
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch(&columns, &indexes, &keyName, PH_NOISY, "phalcon/Db/Adapter.zep", 304 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_5$$3, &index, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 307 TSRMLS_CC);
		zephir_array_append(&columns, &_5$$3, PH_SEPARATE, "phalcon/Db/Adapter.zep", 307);
		zephir_array_update_zval(&indexes, &keyName, &columns, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter.zep", 320);
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
		ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_10, 16, &name, &indexColumns);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_9$$6, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&indexColumns);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&indexObjects);

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

	zval _11$$3, _16$$6;
	zend_string *_14;
	zend_ulong _13;
	zephir_fcall_cache_entry *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, _0, _1, _2, _3, *_4, *_12, _5$$5, _6$$5, _7$$5, _8$$5, _9$$3, _10$$3, _15$$6, _17$$6;
	zval table, schema;
	zval *this_ptr = getThis();

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

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_EMPTY_STRING(&schema);
	}
	}


	ZEPHIR_INIT_VAR(&references);
	array_init(&references);
	zephir_read_property(&_1, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter.zep", 366);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&reference);
		ZVAL_COPY(&reference, _4);
		zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 341 TSRMLS_CC);
		if (!(zephir_array_isset(&references, &constraintName))) {
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter.zep", 344 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter.zep", 345 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
			ZEPHIR_INIT_NVAR(&referencedColumns);
			array_init(&referencedColumns);
		} else {
			zephir_array_fetch(&_5$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 349 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_string(&referencedSchema, &_5$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter.zep", 349 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 350 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_string(&referencedTable, &_6$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter.zep", 350 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 351 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_7$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter.zep", 351 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 352 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedColumns);
			zephir_array_fetch_string(&referencedColumns, &_8$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter.zep", 352 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_9$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 355 TSRMLS_CC);
		zephir_array_append(&columns, &_9$$3, PH_SEPARATE, "phalcon/Db/Adapter.zep", 355);
		zephir_array_fetch_long(&_10$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 356 TSRMLS_CC);
		zephir_array_append(&referencedColumns, &_10$$3, PH_SEPARATE, "phalcon/Db/Adapter.zep", 356);
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
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter.zep", 380);
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
		zephir_array_fetch_string(&_17$$6, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter.zep", 372 TSRMLS_CC);
		zephir_array_update_string(&_16$$6, SL("referencedSchema"), &_17$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_17$$6);
		zephir_array_fetch_string(&_17$$6, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter.zep", 373 TSRMLS_CC);
		zephir_array_update_string(&_16$$6, SL("referencedTable"), &_17$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_17$$6);
		zephir_array_fetch_string(&_17$$6, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter.zep", 374 TSRMLS_CC);
		zephir_array_update_string(&_16$$6, SL("columns"), &_17$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_17$$6);
		zephir_array_fetch_string(&_17$$6, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter.zep", 376 TSRMLS_CC);
		zephir_array_update_string(&_16$$6, SL("referencedColumns"), &_17$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_15$$6, "__construct", &_18, 17, &name, &_16$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_15$$6, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);

}

/**
 * Drops a column from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, _0, _1;
	zval tableName, schemaName, columnName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	zephir_get_strval(&columnName, columnName_param);


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropcolumn", NULL, 0, &tableName, &schemaName, &columnName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, _0, _1;
	zval tableName, schemaName, referenceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&referenceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(&referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceName);
		ZVAL_EMPTY_STRING(&referenceName);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropforeignkey", NULL, 0, &tableName, &schemaName, &referenceName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drop an index from a table
 */
PHP_METHOD(Phalcon_Db_Adapter, dropIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName, indexName_sub, _0, _1;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropindex", NULL, 0, &tableName, &schemaName, indexName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a table's primary key
 */
PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, _0, _1;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropprimarykey", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Drops a table from a schema/database
 */
PHP_METHOD(Phalcon_Db_Adapter, dropTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, _0, _1, _2;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
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


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
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
 * Drops a view
 */
PHP_METHOD(Phalcon_Db_Adapter, dropView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, _0, _1, _2;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
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


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
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
	zval *identifier, identifier_sub, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		zephir_read_property(&_0$$3, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_2$$3, identifier, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 487 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "escape", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_5$$3, identifier, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 487 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "escape", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, &_1$$3, ".", &_4$$3);
		RETURN_MM();
	}
	zephir_read_property(&_6, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_6, "escape", NULL, 0, identifier);
	zephir_check_call_status();
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
 * @param array bindParams
 * @param array bindTypes
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchAll) {

	zend_long fetchMode, ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *fetchMode_param = NULL, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, result, _0;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &sqlQuery_param, &fetchMode_param, &bindParams, &bindTypes);

	zephir_get_strval(&sqlQuery, sqlQuery_param);
	if (!fetchMode_param) {
		fetchMode = 2;
	} else {
		fetchMode = zephir_get_intval(fetchMode_param);
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
	if (Z_TYPE_P(&result) != IS_OBJECT) {
		array_init(return_value);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, fetchMode);
	ZEPHIR_CALL_METHOD(NULL, &result, "setfetchmode", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&result, "fetchall", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

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
 * @param  int|string column
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *sqlQuery_param = NULL, *placeholders_param = NULL, *column = NULL, column_sub, row, columnValue, _0;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&columnValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlQuery_param, &placeholders_param, &column);

	zephir_get_strval(&sqlQuery, sqlQuery_param);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	if (!column) {
		column = &column_sub;
		ZEPHIR_INIT_VAR(column);
		ZVAL_LONG(column, 0);
	}


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(&row, this_ptr, "fetchone", NULL, 0, &sqlQuery, &_0, &placeholders);
	zephir_check_call_status();
	if (!(zephir_array_isset_fetch(&columnValue, &row, column, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&columnValue);

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
 * $robot = $connection->fetchOne(
 *     "SELECT * FROM robots",
 *     \Phalcon\Db::FETCH_ASSOC
 * );
 * print_r($robot);
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchOne) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *fetchMode = NULL, fetchMode_sub, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null, result;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&fetchMode_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &sqlQuery_param, &fetchMode, &bindParams, &bindTypes);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
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
	if (Z_TYPE_P(&result) != IS_OBJECT) {
		array_init(return_value);
		RETURN_MM();
	}
	if (Z_TYPE_P(fetchMode) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &result, "setfetchmode", NULL, 0, fetchMode);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(&result, "fetch", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 */
PHP_METHOD(Phalcon_Db_Adapter, forUpdate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, _0;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "forupdate", NULL, 0, &sqlQuery);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the SQL column definition from a column
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a list of columns
 *
 * @param    array columnList
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnList) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnList, columnList_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnList_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columnList);



	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcolumnlist", NULL, 0, columnList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the active connection unique identifier
 */
PHP_METHOD(Phalcon_Db_Adapter, getConnectionId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "connectionId");

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

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "null");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the default value to make the RBDM use the default value declared
 * in the table definition
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

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DEFAULT");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return descriptor used to connect to the active database
 */
PHP_METHOD(Phalcon_Db_Adapter, getDescriptor) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "descriptor");

}

/**
 * Returns internal dialect instance
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialect) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dialect");

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Db_Adapter, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "eventsManager");

}

/**
 * Returns the savepoint name to use for nested transactions
 */
PHP_METHOD(Phalcon_Db_Adapter, getNestedTransactionSavepointName) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_SV(return_value, "PHALCON_SAVEPOINT_", &_0);
	return;

}

/**
 * Active SQL statement in the object without replace bound parameters
 */
PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sqlStatement");

}

/**
 * Active SQL statement in the object
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sqlBindTypes");

}

/**
 * Active SQL statement in the object
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sqlStatement");

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
 * @param     array fields
 * @param     array dataTypes
 */
PHP_METHOD(Phalcon_Db_Adapter, insert) {

	zend_bool _5$$4;
	zend_string *_4;
	zend_ulong _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *table_param = NULL, *values_param = NULL, *fields = NULL, fields_sub, *dataTypes = NULL, dataTypes_sub, __$null, placeholders, insertValues, bindDataTypes, bindType, position, value, escapedTable, joinedValues, escapedFields, field, insertSql, *_2, _0$$3, _8$$8, _9$$9, *_10$$12, _12$$12, _11$$13;
	zval table, _1$$3, _6$$5, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$7);
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
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &table_param, &values_param, &fields, &dataTypes);

	zephir_get_strval(&table, table_param);
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!fields) {
		fields = &fields_sub;
		fields = &__$null;
	}
	if (!dataTypes) {
		dataTypes = &dataTypes_sub;
		dataTypes = &__$null;
	}


	if (UNEXPECTED(!(zephir_fast_count_int(&values TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "Unable to insert into ", &table, " without data");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 1, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Adapter.zep", 770 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&placeholders);
	array_init(&placeholders);
	ZEPHIR_INIT_VAR(&insertValues);
	array_init(&insertValues);
	ZEPHIR_INIT_VAR(&bindDataTypes);
	array_init(&bindDataTypes);
	zephir_is_iterable(&values, 0, "phalcon/Db/Adapter.zep", 809);
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
		_5$$4 = Z_TYPE_P(&value) == IS_OBJECT;
		if (_5$$4) {
			_5$$4 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce TSRMLS_CC);
		}
		if (_5$$4) {
			zephir_get_strval(&_6$$5, &value);
			zephir_array_append(&placeholders, &_6$$5, PH_SEPARATE, "phalcon/Db/Adapter.zep", 784);
		} else {
			if (Z_TYPE_P(&value) == IS_OBJECT) {
				zephir_get_strval(&_7$$7, &value);
				ZEPHIR_CPY_WRT(&value, &_7$$7);
			}
			if (Z_TYPE_P(&value) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&_8$$8);
				ZVAL_STRING(&_8$$8, "null");
				zephir_array_append(&placeholders, &_8$$8, PH_SEPARATE, "phalcon/Db/Adapter.zep", 791);
			} else {
				ZEPHIR_INIT_NVAR(&_9$$9);
				ZVAL_STRING(&_9$$9, "?");
				zephir_array_append(&placeholders, &_9$$9, PH_SEPARATE, "phalcon/Db/Adapter.zep", 793);
				zephir_array_append(&insertValues, &value, PH_SEPARATE, "phalcon/Db/Adapter.zep", 794);
				if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, dataTypes, &position, 0 TSRMLS_CC)))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Incomplete number of bind types", "phalcon/Db/Adapter.zep", 800);
						return;
					}
					zephir_array_append(&bindDataTypes, &bindType, PH_SEPARATE, "phalcon/Db/Adapter.zep", 803);
				}
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&joinedValues);
	zephir_fast_join_str(&joinedValues, SL(", "), &placeholders TSRMLS_CC);
	ZEPHIR_INIT_VAR(&insertSql);
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&escapedFields);
		array_init(&escapedFields);
		zephir_is_iterable(fields, 0, "phalcon/Db/Adapter.zep", 823);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(fields), _10$$12)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _10$$12);
			ZEPHIR_CALL_METHOD(&_11$$13, this_ptr, "escapeidentifier", NULL, 0, &field);
			zephir_check_call_status();
			zephir_array_append(&escapedFields, &_11$$13, PH_SEPARATE, "phalcon/Db/Adapter.zep", 820);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_VAR(&_12$$12);
		zephir_fast_join_str(&_12$$12, SL(", "), &escapedFields TSRMLS_CC);
		ZEPHIR_CONCAT_SVSVSVS(&insertSql, "INSERT INTO ", &escapedTable, " (", &_12$$12, ") VALUES (", &joinedValues, ")");
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
 * @param     array data
 * @param     array dataTypes
 */
PHP_METHOD(Phalcon_Db_Adapter, insertAsDict) {

	zend_string *_3;
	zend_ulong _2;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *data, data_sub, *dataTypes = NULL, dataTypes_sub, __$null, values, fields, field, value, *_1;
	zval table;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data, &dataTypes);

	zephir_get_strval(&table, table_param);
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
	zephir_is_iterable(data, 0, "phalcon/Db/Adapter.zep", 872);
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
		zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Db/Adapter.zep", 868);
		zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Db/Adapter.zep", 869);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "insert", NULL, 0, &table, &values, &fields, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns if nested transactions should use savepoints
 */
PHP_METHOD(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "transactionsWithSavepoints");

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
	zval *sqlQuery_param = NULL, *number_param = NULL, _0, _1;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}
	number = zephir_get_intval(number_param);


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, number);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "limit", NULL, 0, &sqlQuery, &_1);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schemaName_param = NULL, tables, table, allTables, _0, _1, _2, *_3, _4$$3;
	zval schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&allTables);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	ZEPHIR_INIT_VAR(&allTables);
	array_init(&allTables);
	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "listtables", NULL, 0, &schemaName);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&tables, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&tables, 0, "phalcon/Db/Adapter.zep", 919);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tables), _3)
	{
		ZEPHIR_INIT_NVAR(&table);
		ZVAL_COPY(&table, _3);
		zephir_array_fetch_long(&_4$$3, &table, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 916 TSRMLS_CC);
		zephir_array_append(&allTables, &_4$$3, PH_SEPARATE, "phalcon/Db/Adapter.zep", 916);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&table);
	RETURN_CCTOR(&allTables);

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schemaName_param = NULL, tables, table, allTables, _0, _1, _2, *_3, _4$$3;
	zval schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&allTables);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	ZEPHIR_INIT_VAR(&allTables);
	array_init(&allTables);
	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "listviews", NULL, 0, &schemaName);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&tables, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&tables, 0, "phalcon/Db/Adapter.zep", 946);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tables), _3)
	{
		ZEPHIR_INIT_NVAR(&table);
		ZVAL_COPY(&table, _3);
		zephir_array_fetch_long(&_4$$3, &table, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 943 TSRMLS_CC);
		zephir_array_append(&allTables, &_4$$3, PH_SEPARATE, "phalcon/Db/Adapter.zep", 943);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&table);
	RETURN_CCTOR(&allTables);

}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter, modifyColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, _0, _1;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		currentColumn = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "modifycolumn", NULL, 0, &tableName, &schemaName, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Releases given savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, releaseSavepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, dialect, _0, _1, _2, _3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dialect, &_0);
	ZEPHIR_CALL_METHOD(&_1, &dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/Db/Adapter.zep", 976);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, &dialect, "supportsreleasesavepoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_3, &dialect, "releasesavepoint", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Rollbacks given savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter, rollbackSavepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, dialect, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dialect, &_0);
	ZEPHIR_CALL_METHOD(&_1, &dialect, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/Db/Adapter.zep", 1000);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, &dialect, "rollbacksavepoint", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the event manager
 */
PHP_METHOD(Phalcon_Db_Adapter, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("eventsManager"), eventsManager);

}

/**
 * Sets the dialect used to produce the SQL
 */
PHP_METHOD(Phalcon_Db_Adapter, setDialect) {

	zval *dialect, dialect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dialect_sub);

	zephir_fetch_params(0, 1, 0, &dialect);



	zephir_update_property_zval(this_ptr, SL("dialect"), dialect);

}

/**
 * Set if nested transactions should use savepoints
 */
PHP_METHOD(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nestedTransactionsWithSavepoints_param = NULL, __$true, __$false, _0, _1, _2;
	zend_bool nestedTransactionsWithSavepoints;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &nestedTransactionsWithSavepoints_param);

	nestedTransactionsWithSavepoints = zephir_get_boolval(nestedTransactionsWithSavepoints_param);


	zephir_read_property(&_0, this_ptr, SL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_GT_LONG(&_0, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Nested transaction with savepoints behavior cannot be changed while a transaction is open", "phalcon/Db/Adapter.zep", 1032);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "supportssavepoints", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Savepoints are not supported by this database adapter", "phalcon/Db/Adapter.zep", 1038);
		return;
	}
	if (nestedTransactionsWithSavepoints) {
		zephir_update_property_zval(this_ptr, SL("transactionsWithSavepoints"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("transactionsWithSavepoints"), &__$false);
	}
	RETURN_THIS();

}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 */
PHP_METHOD(Phalcon_Db_Adapter, sharedLock) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, _0;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "sharedlock", NULL, 0, &sqlQuery);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce
 * auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter, supportSequences) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

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
	zval *tableName_param = NULL, *schemaName_param = NULL, _0, _1, _2, _3, _4;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	zephir_read_property(&_1, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "tableexists", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchone", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_0, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 1074 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_4, 0));

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
	zval *tableName_param = NULL, *schemaName_param = NULL, sql, _0, _1, _2, _3;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
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


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "tableoptions", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	if (!(zephir_is_true(&sql))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "fetchall", NULL, 0, &sql, &_2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 1096 TSRMLS_CC);
	RETURN_CTOR(&_3);

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
 * @param array fields
 * @param array values
 * @param string|array whereCondition
 * @param array dataTypes
 */
PHP_METHOD(Phalcon_Db_Adapter, update) {

	zend_bool _4$$3;
	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *fields, fields_sub, *values, values_sub, *whereCondition = NULL, whereCondition_sub, *dataTypes = NULL, dataTypes_sub, __$null, placeholders, updateValues, position, value, field, bindDataTypes, escapedField, bindType, escapedTable, setClause, updateSql, conditions, whereBind, whereTypes, *_0, _6$$5, _8$$8, _9$$9;
	zval table, _5$$5, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$7);
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
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &table_param, &fields, &values, &whereCondition, &dataTypes);

	zephir_get_strval(&table, table_param);
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
	zephir_is_iterable(values, 0, "phalcon/Db/Adapter.zep", 1189);
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
		if (UNEXPECTED(!(zephir_array_isset_fetch(&field, fields, &position, 0 TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The number of values in the update is not the same as fields", "phalcon/Db/Adapter.zep", 1157);
			return;
		}
		ZEPHIR_CALL_METHOD(&escapedField, this_ptr, "escapeidentifier", &_3, 0, &field);
		zephir_check_call_status();
		_4$$3 = Z_TYPE_P(&value) == IS_OBJECT;
		if (_4$$3) {
			_4$$3 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce TSRMLS_CC);
		}
		if (_4$$3) {
			zephir_get_strval(&_5$$5, &value);
			ZEPHIR_INIT_LNVAR(_6$$5);
			ZEPHIR_CONCAT_VSV(&_6$$5, &escapedField, " = ", &_5$$5);
			zephir_array_append(&placeholders, &_6$$5, PH_SEPARATE, "phalcon/Db/Adapter.zep", 1163);
		} else {
			if (Z_TYPE_P(&value) == IS_OBJECT) {
				zephir_get_strval(&_7$$7, &value);
				ZEPHIR_CPY_WRT(&value, &_7$$7);
			}
			if (Z_TYPE_P(&value) == IS_NULL) {
				ZEPHIR_INIT_LNVAR(_8$$8);
				ZEPHIR_CONCAT_VS(&_8$$8, &escapedField, " = null");
				zephir_array_append(&placeholders, &_8$$8, PH_SEPARATE, "phalcon/Db/Adapter.zep", 1170);
			} else {
				zephir_array_append(&updateValues, &value, PH_SEPARATE, "phalcon/Db/Adapter.zep", 1172);
				if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&bindType);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bindType, dataTypes, &position, 0 TSRMLS_CC)))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Incomplete number of bind types", "phalcon/Db/Adapter.zep", 1178);
						return;
					}
					zephir_array_append(&bindDataTypes, &bindType, PH_SEPARATE, "phalcon/Db/Adapter.zep", 1181);
				}
				ZEPHIR_INIT_LNVAR(_9$$9);
				ZEPHIR_CONCAT_VS(&_9$$9, &escapedField, " = ?");
				zephir_array_append(&placeholders, &_9$$9, PH_SEPARATE, "phalcon/Db/Adapter.zep", 1184);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", &_3, 0, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&setClause);
	zephir_fast_join_str(&setClause, SL(", "), &placeholders TSRMLS_CC);
	ZEPHIR_INIT_VAR(&updateSql);
	if (Z_TYPE_P(whereCondition) != IS_NULL) {
		ZEPHIR_CONCAT_SVSVS(&updateSql, "UPDATE ", &escapedTable, " SET ", &setClause, " WHERE ");
		if (Z_TYPE_P(whereCondition) == IS_STRING) {
			zephir_concat_self(&updateSql, whereCondition TSRMLS_CC);
		} else {
			if (UNEXPECTED(Z_TYPE_P(whereCondition) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid WHERE clause conditions", "phalcon/Db/Adapter.zep", 1207);
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
 * @param array data
 * @param string whereCondition
 * @param array dataTypes
 */
PHP_METHOD(Phalcon_Db_Adapter, updateAsDict) {

	zend_string *_3;
	zend_ulong _2;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *data, data_sub, *whereCondition = NULL, whereCondition_sub, *dataTypes = NULL, dataTypes_sub, __$null, values, fields, field, value, *_1;
	zval table;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&whereCondition_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &table_param, &data, &whereCondition, &dataTypes);

	zephir_get_strval(&table, table_param);
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
	zephir_is_iterable(data, 0, "phalcon/Db/Adapter.zep", 1284);
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
		zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Db/Adapter.zep", 1280);
		zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Db/Adapter.zep", 1281);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "update", NULL, 0, &table, &fields, &values, whereCondition, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires an explicit value for identity
 * columns
 */
PHP_METHOD(Phalcon_Db_Adapter, useExplicitIdValue) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

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
	zval *viewName_param = NULL, *schemaName_param = NULL, _0, _1, _2, _3, _4;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	zephir_read_property(&_1, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "viewexists", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchone", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_0, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter.zep", 1307 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_4, 0));

}

zend_object *zephir_init_properties_Phalcon_Db_Adapter(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("descriptor"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

