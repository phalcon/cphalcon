
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Base class for Phalcon\Db\Adapter adapters.
 *
 * This class and its related classes provide a simple SQL database interface
 * for Phalcon Framework. The Phalcon\Db is the basic class you use to connect
 * your PHP application to an RDBMS. There is a different adapter class for each
 * brand of RDBMS.
 *
 * This component is intended to lower level database operations. If you want to
 * interact with databases using higher level of abstraction use
 * Phalcon\Mvc\Model.
 *
 * Phalcon\Db\AbstractDb is an abstract class. You only can use it with a
 * database adapter like Phalcon\Db\Adapter\Pdo
 *
 *```php
 * use Phalcon\Db;
 * use Phalcon\Db\Exception;
 * use Phalcon\Db\Adapter\Pdo\Mysql as MysqlConnection;
 *
 * try {
 *     $connection = new MysqlConnection(
 *         [
 *             "host"     => "192.168.0.11",
 *             "username" => "sigma",
 *             "password" => "secret",
 *             "dbname"   => "blog",
 *             "port"     => "3306",
 *         ]
 *     );
 *
 *     $result = $connection->query(
 *         "SELECT * FROM co_invoices LIMIT 5"
 *     );
 *
 *     $result->setFetchMode(Enum::FETCH_NUM);
 *
 *     while ($invoice = $result->fetch()) {
 *         print_r($invoice);
 *     }
 * } catch (Exception $e) {
 *     echo $e->getMessage(), PHP_EOL;
 * }
 * ```
 *
 * @phpstan-import-type db_bind_params from DbTypes
 * @phpstan-import-type db_bind_types from DbTypes
 * @phpstan-import-type db_column_names from DbTypes
 * @phpstan-import-type db_descriptor from DbTypes
 * @phpstan-import-type db_identifier from DbTypes
 * @phpstan-import-type db_indexes from DbTypes
 * @phpstan-import-type db_limit_number from DbTypes
 * @phpstan-import-type db_references from DbTypes
 * @phpstan-import-type db_row from DbTypes
 * @phpstan-import-type db_rows from DbTypes
 * @phpstan-import-type db_setup_options from DbTypes
 * @phpstan-import-type db_table_definition from DbTypes
 * @phpstan-import-type db_table_names from DbTypes
 * @phpstan-import-type db_table_options from DbTypes
 * @phpstan-import-type db_value_placeholder from DbTypes
 * @phpstan-import-type db_view_definition from DbTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db\\Adapter, AbstractAdapter, phalcon, db_adapter_abstractadapter, phalcon_db_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Connection ID
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_adapter_abstractadapter_ce, SL("connectionConsecutive"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * Active connection ID
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("connectionId"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * Descriptor used to connect to a database
	 *
	 * @phpstan-var db_descriptor
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("descriptor"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Dialect instance
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("dialect"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Db\\DialectInterface"));
	}

	/**
	 * Name of the dialect used
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("dialectType"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * Event Manager
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	/**
	 * The real SQL statement - what was executed
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("realSqlStatement"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * Active SQL Bind Types
	 *
	 * @phpstan-var db_bind_types
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("sqlBindTypes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Active SQL Statement
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("sqlStatement"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * Active SQL bound parameter variables
	 *
	 * @phpstan-var db_bind_params
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("sqlVariables"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Current transaction level
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("transactionLevel"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * Whether the database supports transactions with save points
	 */
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("transactionsWithSavepoints"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * Type of database system the adapter is used for
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_db_adapter_abstractadapter_ce, SL("type"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	zend_class_implements(phalcon_db_adapter_abstractadapter_ce, 1, phalcon_db_adapter_adapterinterface_ce);
	zend_class_implements(phalcon_db_adapter_abstractadapter_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Db\Adapter constructor
 *
 * @param array $descriptor = [
 *     'host' => 'localhost',
 *     'port' => '3306',
 *     'dbname' => 'blog',
 *     'username' => 'sigma'
 *     'password' => 'secret',
 *     'dialectClass' => null,
 *     'options' => [],
 *     'dsn' => null,
 *     'charset' => 'utf8mb4'
 * ]
 *
 * Note: the `options` key is forwarded to the static `setup()` method,
 * which writes process-global settings affecting every connection in the
 * process. See `setup()`.
 *
 * @phpstan-param db_descriptor $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, __construct)
{
	zend_bool _2, _7, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, dialectClass, connectionId, _0, _1, _9, _3$$3, _4$$4, _5$$6, _6$$6, _10$$7;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dialectClass);
	ZVAL_UNDEF(&connectionId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_10$$7);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("connectionId", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("dialectType", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("dialect", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("descriptor", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(descriptor, descriptor_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &descriptor_param);
	zephir_get_arrval(&descriptor, descriptor_param);
	zephir_memory_observe(&connectionId);
	zephir_read_static_property_ce(&connectionId, phalcon_db_adapter_abstractadapter_ce, SL("connectionConsecutive"), PH_NOISY_CC);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 76, &connectionId);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_INIT_VAR(&_1);
	zephir_add_function(&_1, &connectionId, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalcon_db_adapter_abstractadapter_ce, ZEND_STRL("connectionConsecutive"), &_1);
	zephir_memory_observe(&dialectClass);
	_2 = zephir_array_isset_string_fetch(&dialectClass, &descriptor, SL("dialectClass"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_1, 77, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&dialectClass);
		ZEPHIR_CONCAT_SV(&dialectClass, "phalcon\\db\\dialect\\", &_3$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&dialectClass) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_4$$4, &dialectClass);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 78, &_4$$4);
	} else if (Z_TYPE_P(&dialectClass) == IS_OBJECT) {
		if (UNEXPECTED(!((zephir_instance_of_ev(&dialectClass, phalcon_db_dialectinterface_ce))))) {
			ZEPHIR_INIT_VAR(&_5$$6);
			object_init_ex(&_5$$6, phalcon_db_exceptions_invaliddialectclass_ce);
			ZEPHIR_INIT_VAR(&_6$$6);
			zephir_get_class(&_6$$6, &dialectClass, 0);
			ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", NULL, 58, &_6$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$6, "phalcon/Db/Adapter/AbstractAdapter.zep", 216);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 78, &dialectClass);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 79, &descriptor);
	_7 = zephir_array_isset_value_string(&descriptor, SL("options"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_8 = _7;
	if (_8) {
		zephir_memory_observe(&_9);
		zephir_array_fetch_string(&_9, &descriptor, SL("options"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 224);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_8 = Z_TYPE_P(&_9) == IS_ARRAY;
	}
	if (_8) {
		zephir_array_fetch_string(&_10$$7, &descriptor, SL("options"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 225);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_SELF(NULL, "setup", NULL, 0, &_10$$7);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Enables/disables options in the Database component.
 *
 * The flags are stored as process-global `Phalcon\Support\Settings`
 * (`db.escape_identifiers`, `db.force_casting`) and therefore affect every
 * connection in the process at once, last-writer-wins. Call this once at
 * bootstrap; it is not per-connection configuration. Because the
 * constructor calls `setup()` whenever a descriptor carries an `options`
 * key, constructing one adapter with `options` can change the SQL another,
 * already-configured connection generates.
 *
 * @phpstan-param db_setup_options $options
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, setup)
{
	zend_bool _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, escapeIdentifiers, forceCasting, _1$$3, _3$$4;
	zval options;

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&escapeIdentifiers);
	ZVAL_UNDEF(&forceCasting);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&escapeIdentifiers);
	_0 = zephir_array_isset_string_fetch(&escapeIdentifiers, &options, SL("escapeSqlIdentifiers"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "db.escape_identifiers");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_1$$3, &escapeIdentifiers);
		zephir_check_call_status();
	}
	zephir_memory_observe(&forceCasting);
	_2 = zephir_array_isset_string_fetch(&forceCasting, &options, SL("forceCasting"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "db.force_casting");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_support_settings_ce, "set", NULL, 0, &_3$$4, &forceCasting);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a CHECK constraint to a table. MySQL 8.0.16+ and PostgreSQL
 * issue `ALTER TABLE ... ADD CONSTRAINT ... CHECK (...)`; SQLite throws.
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addCheck)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *check, check_sub, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&check_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(check, phalcon_db_checkinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	check = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addCheck", NULL, 0, &tableName_zv, &schemaName_zv, check);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a column to a table
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	column = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addColumn", NULL, 0, &tableName_zv, &schemaName_zv, column);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a foreign key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *reference, reference_sub, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(reference, phalcon_db_referenceinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	reference = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addForeignKey", NULL, 0, &tableName_zv, &schemaName_zv, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds an index to a table
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *index, index_sub, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(index, phalcon_db_indexinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	index = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addIndex", NULL, 0, &tableName_zv, &schemaName_zv, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a primary key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addPrimaryKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *index, index_sub, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(index, phalcon_db_indexinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	index = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "addPrimaryKey", NULL, 0, &tableName_zv, &schemaName_zv, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a materialized view (PostgreSQL only - MySQL and SQLite
 * throw via the dialect).
 *
 * @phpstan-param db_view_definition $definition
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, createMaterializedView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval viewName_zv, *definition_param = NULL, schemaName_zv, _0, _1;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&definition);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(viewName)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	zephir_get_arrval(&definition, definition_param);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "createMaterializedView", NULL, 0, &viewName_zv, &definition, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a new savepoint
 *
 * @throws SavepointsNotSupported
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, createSavepoint)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkSavepoints", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "createSavepoint", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a table
 *
 * @phpstan-param db_table_definition $definition
 *
 * @throws TableMustHaveColumn
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, createTable)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval tableName_zv, schemaName_zv, *definition_param = NULL, columns, _5, _6, _1$$3, _3$$4;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&definition);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_get_arrval(&definition, definition_param);
	zephir_memory_observe(&columns);
	_0 = zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_tablemusthavecolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_2, 59);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/AbstractAdapter.zep", 381);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columns))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_db_exceptions_tablemusthavecolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_4, 59);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Db/Adapter/AbstractAdapter.zep", 385);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, &_5, "createTable", NULL, 0, &tableName_zv, &schemaName_zv, &definition);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a view
 *
 * @throws TableMustHaveColumn
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, createView)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval viewName_zv, *definition_param = NULL, schemaName_zv, _2, _3, _1$$3;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&definition);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(viewName)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	zephir_get_arrval(&definition, definition_param);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	_0 = zephir_array_isset_value_string(&definition, SL("sql"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_tablemusthavecolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 59);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/AbstractAdapter.zep", 405);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "createView", NULL, 0, &viewName_zv, &definition, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * ```php
 * // Deleting existing invoice
 * $success = $connection->delete(
 *     "co_invoices",
 *     "inv_id = 101"
 * );
 *
 * // Next SQL sentence is generated
 * DELETE FROM `co_invoices` WHERE `inv_id` = 101
 * ```
 *
 * Warning! If $whereCondition is string it not escaped.
 *
 * @param array|string table
 * @param string|null whereCondition
 * @param array placeholders
 * @param array dataTypes
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, delete)
{
	zval _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders, dataTypes;
	zend_string *whereCondition = NULL;
	zval *table, table_sub, whereCondition_zv, *placeholders_param = NULL, *dataTypes_param = NULL, sql, escapedTable;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&whereCondition_zv);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&escapedTable);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&dataTypes);
	ZVAL_UNDEF(&_0$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(whereCondition)
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
		ZEPHIR_Z_PARAM_ARRAY(dataTypes, dataTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	table = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		dataTypes_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (!whereCondition) {
		ZEPHIR_INIT_VAR(&whereCondition_zv);
	} else {
		zephir_memory_observe(&whereCondition_zv);
	ZVAL_STR_COPY(&whereCondition_zv, whereCondition);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	if (!dataTypes_param) {
		ZEPHIR_INIT_VAR(&dataTypes);
		array_init(&dataTypes);
	} else {
		zephir_get_arrval(&dataTypes, dataTypes_param);
	}
	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeIdentifier", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SV(&sql, "DELETE FROM ", &escapedTable);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(&whereCondition_zv))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, " WHERE ", &whereCondition_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_0$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &sql, &placeholders, &dataTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Lists table indexes
 *
 *```php
 * print_r(
 *     $connection->describeIndexes("co_orders_x_products")
 * );
 *```
 *
 * This base implementation consumes the dialect's `describeIndexes()` SQL
 * as `FETCH_NUM` rows by position: column index 2 is the index key name and
 * column index 4 is the indexed column name. A custom dialect's
 * `describeIndexes()` SQL must emit columns in that order, or a custom
 * adapter must override this method. All bundled adapters except PostgreSQL
 * override it.
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, describeIndexes)
{
	zend_ulong _16;
	zend_bool _10, _7$$3, _11$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, indexes, index, keyName, indexObjects, name, indexColumns, columns, _0, _1, _2, _3, *_4, _5, *_6, _9, *_13, _14, *_15, _8$$3, _12$$6, _18$$9;
	zend_string *table = NULL, *schema = NULL, *_17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_18$$9);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeIndexes", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchAll", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_0);
		_4 = &_5;
	} else {
		_4 = &_0;
	}
	zephir_is_iterable(_4, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 493);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _6);
			ZEPHIR_OBS_NVAR(&keyName);
			zephir_array_fetch_long(&keyName, &index, 2, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 481);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_7$$3 = zephir_array_isset_value(&indexes, &keyName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_7$$3)) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch(&columns, &indexes, &keyName, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 486);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_8$$3);
			zephir_array_fetch_long(&_8$$3, &index, 4, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 489);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&columns, &_8$$3, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 489);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&indexes, &keyName, &columns, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&keyName);
				zephir_array_fetch_long(&keyName, &index, 2, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 481);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_11$$6 = zephir_array_isset_value(&indexes, &keyName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_11$$6)) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch(&columns, &indexes, &keyName, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 486);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_12$$6);
				zephir_array_fetch_long(&_12$$6, &index, 4, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 489);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&columns, &_12$$6, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 489);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&indexes, &keyName, &columns, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	if (Z_TYPE_P(&indexes) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_14);
		zephir_string_to_char_array(&_14, &indexes);
		_13 = &_14;
	} else {
		_13 = &indexes;
	}
	zephir_is_iterable(_13, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 502);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_13), _16, _17, _15)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_17 != NULL) { 
			ZVAL_STR_COPY(&name, _17);
		} else {
			ZVAL_LONG(&name, _16);
		}
		ZEPHIR_INIT_NVAR(&indexColumns);
		ZVAL_COPY(&indexColumns, _15);
		ZEPHIR_INIT_NVAR(&_18$$9);
		object_init_ex(&_18$$9, phalcon_db_index_ce);
		ZEPHIR_CALL_METHOD(NULL, &_18$$9, "__construct", &_19, 60, &name, &indexColumns);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_18$$9, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&indexColumns);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&indexObjects);
}

/**
 * Lists table references
 *
 *```php
 * print_r(
 *     $connection->describeReferences("co_orders_x_products")
 * );
 *```
 *
 * This base implementation consumes the dialect's `describeReferences()`
 * SQL as `FETCH_NUM` rows by position: index 1 is the local column, index 2
 * the constraint name, index 3 the referenced schema, index 4 the
 * referenced table, and index 5 the referenced column. A custom dialect's
 * `describeReferences()` SQL must emit columns in that order, or a custom
 * adapter must override this method. Every bundled adapter (MySQL,
 * PostgreSQL, SQLite) overrides it, so this base implementation has no
 * in-tree caller and effectively assumes the PostgreSQL row shape.
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, describeReferences)
{
	zval _14$$3, _24$$6, _31$$9;
	zend_ulong _28;
	zend_bool _16, _7$$3, _17$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, _0, _1, _2, _3, *_4, _5, *_6, _15, *_25, _26, *_27, _12$$3, _13$$3, _8$$5, _9$$5, _10$$5, _11$$5, _22$$6, _23$$6, _18$$8, _19$$8, _20$$8, _21$$8, _30$$9, _32$$9;
	zend_string *table = NULL, *schema = NULL, *_29;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_31$$9);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	ZEPHIR_INIT_VAR(&references);
	array_init(&references);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeReferences", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchAll", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_0);
		_4 = &_5;
	} else {
		_4 = &_0;
	}
	zephir_is_iterable(_4, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 559);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _6);
			ZEPHIR_OBS_NVAR(&constraintName);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 534);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_7$$3 = zephir_array_isset_value(&references, &constraintName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_7$$3)) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 537);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 538);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 542);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_8$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 542);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 543);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_9$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 543);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 544);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_10$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 544);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 545);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_11$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 545);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_12$$3);
			zephir_array_fetch_long(&_12$$3, &reference, 1, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 548);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 548);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_13$$3);
			zephir_array_fetch_long(&_13$$3, &reference, 5, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 549);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 549);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_create_array(&_14$$3, 4, 0);
			zephir_array_update_string(&_14$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&references, &constraintName, &_14$$3, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reference, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&constraintName);
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 534);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_17$$6 = zephir_array_isset_value(&references, &constraintName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_17$$6)) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 537);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 538);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 542);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_18$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 542);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 543);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_19$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 543);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 544);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_20$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 544);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_21$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/AbstractAdapter.zep", 545);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_21$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 545);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_22$$6);
				zephir_array_fetch_long(&_22$$6, &reference, 1, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 548);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&columns, &_22$$6, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 548);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_23$$6);
				zephir_array_fetch_long(&_23$$6, &reference, 5, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 549);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&referencedColumns, &_23$$6, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 549);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_24$$6);
				zephir_create_array(&_24$$6, 4, 0);
				zephir_array_update_string(&_24$$6, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$6, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$6, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$6, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&references, &constraintName, &_24$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	if (Z_TYPE_P(&references) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_26);
		zephir_string_to_char_array(&_26, &references);
		_25 = &_26;
	} else {
		_25 = &references;
	}
	zephir_is_iterable(_25, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 573);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_25), _28, _29, _27)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_29 != NULL) { 
			ZVAL_STR_COPY(&name, _29);
		} else {
			ZVAL_LONG(&name, _28);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _27);
		ZEPHIR_INIT_NVAR(&_30$$9);
		object_init_ex(&_30$$9, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_31$$9);
		zephir_create_array(&_31$$9, 4, 0);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 565);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_31$$9, SL("referencedSchema"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 566);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_31$$9, SL("referencedTable"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 567);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_31$$9, SL("columns"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 569);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_31$$9, SL("referencedColumns"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_30$$9, "__construct", &_33, 61, &name, &_31$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_30$$9, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);
}

/**
 * Drops a CHECK constraint from a table. SQLite throws.
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropCheck)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, checkName_zv, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL, *checkName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&checkName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(checkName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_memory_observe(&checkName_zv);
	ZVAL_STR_COPY(&checkName_zv, checkName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropCheck", NULL, 0, &tableName_zv, &schemaName_zv, &checkName_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Drops a column from a table
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, columnName_zv, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL, *columnName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&columnName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(columnName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_memory_observe(&columnName_zv);
	ZVAL_STR_COPY(&columnName_zv, columnName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropColumn", NULL, 0, &tableName_zv, &schemaName_zv, &columnName_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Drops a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, referenceName_zv, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL, *referenceName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&referenceName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(referenceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_memory_observe(&referenceName_zv);
	ZVAL_STR_COPY(&referenceName_zv, referenceName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropForeignKey", NULL, 0, &tableName_zv, &schemaName_zv, &referenceName_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Drop an index from a table
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *indexName, indexName_sub, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&indexName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_ZVAL(indexName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	indexName = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropIndex", NULL, 0, &tableName_zv, &schemaName_zv, indexName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Drops a materialized view (PostgreSQL only).
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropMaterializedView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval viewName_zv, schemaName_zv, *ifExists_param = NULL, _0, _1, _2;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(ifExists)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ifExists_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	if (ifExists) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropMaterializedView", NULL, 0, &viewName_zv, &schemaName_zv, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Drops a table's primary key
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropPrimaryKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropPrimaryKey", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Drops a table from a schema/database
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval tableName_zv, schemaName_zv, *ifExists_param = NULL, _0, _1, _2;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(ifExists)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ifExists_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	if (ifExists) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropTable", NULL, 0, &tableName_zv, &schemaName_zv, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Drops a view
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval viewName_zv, schemaName_zv, *ifExists_param = NULL, _0, _1, _2;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(ifExists)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ifExists_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	if (ifExists) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, &_0, "dropView", NULL, 0, &viewName_zv, &schemaName_zv, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escapes a column/table/schema name
 *
 *```php
 * $escapedTable = $connection->escapeIdentifier(
 *     "co_invoices"
 * );
 *
 * $escapedTable = $connection->escapeIdentifier(
 *     [
 *         "store",
 *         "co_invoices",
 *     ]
 * );
 *```
 *
 * @phpstan-param db_identifier $identifier
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, escapeIdentifier)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(identifier)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &identifier);
	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_2$$3);
		zephir_array_fetch_long(&_2$$3, identifier, 0, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 711);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "escape", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_5$$3);
		zephir_array_fetch_long(&_5$$3, identifier, 1, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 711);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "escape", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, &_1$$3, ".", &_4$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_6, "escape", NULL, 0, identifier);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Dumps the complete result of a query into an array
 *
 *```php
 * // Getting all invoices with associative indexes only
 * $invoices = $connection->fetchAll(
 *     "SELECT * FROM co_invoices",
 *     \Phalcon\Db\Enum::FETCH_ASSOC
 * );
 *
 * foreach ($invoices as $invoice) {
 *     print_r($invoice);
 * }
 *
 *  // Getting all invoices whose title contains the word "Test"
 * $invoices = $connection->fetchAll(
 *     "SELECT * FROM co_invoices WHERE inv_title LIKE :inv_title",
 *     \Phalcon\Db\Enum::FETCH_ASSOC,
 *     [
 *         "inv_title" => "%Test%",
 *     ]
 * );
 * foreach($invoices as $invoice) {
 *     print_r($invoice);
 * }
 *```
 *
 * @phpstan-param db_bind_params $bindParams
 * @phpstan-param db_bind_types  $bindTypes
 *
 * @phpstan-return db_rows
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, fetchAll)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval bindParams, bindTypes;
	zend_long fetchMode, ZEPHIR_LAST_CALL_STATUS;
	zval sqlQuery_zv, *fetchMode_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, result, _1, _0$$4;
	zend_string *sqlQuery = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(fetchMode)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		fetchMode_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		bindParams_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		bindTypes_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	if (!fetchMode_param) {
		fetchMode = 2;
	} else {
		}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}
	ZEPHIR_CALL_METHOD(&result, this_ptr, "query", NULL, 0, &sqlQuery_zv, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) != IS_OBJECT) {
		array_init(return_value);
		RETURN_MM();
	}
	if (UNEXPECTED(fetchMode == 7)) {
		ZVAL_LONG(&_0$$4, 7);
		ZEPHIR_RETURN_CALL_METHOD(&result, "fetchAll", NULL, 0, &_0$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_LONG(&_1, fetchMode);
	ZEPHIR_CALL_METHOD(NULL, &result, "setFetchMode", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&result, "fetchAll", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the n'th field of first row in a SQL query result
 *
 *```php
 * // Getting count of invoices
 * $invoicesCount = $connection->fetchColumn("SELECT count(*) FROM co_invoices");
 * print_r($invoicesCount);
 *
 * // Getting the title of the last created invoice
 * $invoice = $connection->fetchColumn(
 *     "SELECT inv_id, inv_title FROM co_invoices ORDER BY inv_created_at DESC",
 *     1
 * );
 * print_r($invoice);
 *```
 *
 * @phpstan-param int|string $column
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, fetchColumn)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval sqlQuery_zv, *placeholders_param = NULL, *column = NULL, column_sub, row, columnValue, _0;
	zend_string *sqlQuery = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&columnValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
		Z_PARAM_ZVAL(column)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		column = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
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
	ZEPHIR_CALL_METHOD(&row, this_ptr, "fetchOne", NULL, 0, &sqlQuery_zv, &_0, &placeholders);
	zephir_check_call_status();
	zephir_memory_observe(&columnValue);
	_1 = zephir_array_isset_fetch(&columnValue, &row, column, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(&columnValue);
}

/**
 * Returns the first row in a SQL query result
 *
 *```php
 * // Getting first invoice
 * $invoice = $connection->fetchOne("SELECT * FROM co_invoices");
 * print_r($invoice);
 *
 * // Getting first invoice with associative indexes only
 * $invoice = $connection->fetchOne(
 *     "SELECT * FROM co_invoices",
 *     \Phalcon\Db\Enum::FETCH_ASSOC
 * );
 * print_r($invoice);
 *```
 *
 * @todo v7 check the return type, it should be also bool
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, fetchOne)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams, bindTypes;
	zval sqlQuery_zv, *fetchMode = NULL, fetchMode_sub, *bindParams_param = NULL, *bindTypes_param = NULL, result;
	zend_string *sqlQuery = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&fetchMode_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(fetchMode)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		fetchMode = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		bindParams_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		bindTypes_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	if (!fetchMode) {
		fetchMode = &fetchMode_sub;
		ZEPHIR_INIT_VAR(fetchMode);
		ZVAL_LONG(fetchMode, 2);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}
	ZEPHIR_CALL_METHOD(&result, this_ptr, "query", NULL, 0, &sqlQuery_zv, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) != IS_OBJECT) {
		array_init(return_value);
		RETURN_MM();
	}
	if (Z_TYPE_P(fetchMode) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &result, "setFetchMode", NULL, 0, fetchMode);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(&result, "fetch", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a SQL modified with a FOR UPDATE clause. The optional
 * `modifier` is passed straight to the dialect (use `Dialect::LOCK_NOWAIT`
 * / `Dialect::LOCK_SKIP_LOCKED` / `Dialect::LOCK_NONE`).
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, forUpdate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sqlQuery_zv, modifier_zv, _0;
	zend_string *sqlQuery = NULL, *modifier = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&modifier_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(modifier)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	if (!modifier) {
		modifier = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&modifier_zv);
		ZVAL_STR(&modifier_zv, modifier);
	} else {
		zephir_memory_observe(&modifier_zv);
	ZVAL_STR_COPY(&modifier_zv, modifier);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "forUpdate", NULL, 0, &sqlQuery_zv, &modifier_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the SQL column definition from a column
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getColumnDefinition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getColumnDefinition", NULL, 0, column);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets a list of columns
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getColumnList)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnList, columnList_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnList_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(columnList)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &columnList);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getColumnList", NULL, 0, columnList);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the active connection unique identifier
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getConnectionId)
{

	RETURN_MEMBER_TYPED(getThis(), "connectionId", IS_LONG);
}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *```php
 * // Inserting a new invoice with a valid default value for the column 'inv_id'
 * $success = $connection->insert(
 *     "co_invoices",
 *     [
 *         $connection->getDefaultIdValue(),
 *         "Test Invoice",
 *         100,
 *     ],
 *     [
 *         "inv_id",
 *         "inv_title",
 *         "inv_total",
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDefaultIdValue)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "null");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the default value to make the RBDM use the default value declared
 * in the table definition
 *
 *```php
 * // Inserting a new invoice with a valid default value for the column 'inv_total'
 * $success = $connection->insert(
 *     "co_invoices",
 *     [
 *         "Test Invoice",
 *         $connection->getDefaultValue()
 *     ],
 *     [
 *         "inv_title",
 *         "inv_total",
 *     ]
 * );
 *```
 *
 * @todo Return NULL if this is not supported by the adapter
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDefaultValue)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DEFAULT");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return descriptor used to connect to the active database
 *
 * @phpstan-return db_descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDescriptor)
{

	RETURN_MEMBER_TYPED(getThis(), "descriptor", IS_ARRAY);
}

/**
 * Returns internal dialect instance
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDialect)
{

	RETURN_MEMBER(getThis(), "dialect");
}

/**
 * Name of the dialect used
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDialectType)
{

	RETURN_MEMBER_TYPED(getThis(), "dialectType", IS_STRING);
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Returns the savepoint name to use for nested transactions
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getNestedTransactionSavepointName)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transactionLevel", 16, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 80, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_SV(return_value, "PHALCON_SAVEPOINT_", &_0);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	return;
}

/**
 * Active SQL statement in the object without replace bound parameters
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getRealSQLStatement)
{

	RETURN_MEMBER_TYPED(getThis(), "realSqlStatement", IS_STRING);
}

/**
 * Active SQL statement in the object
 *
 * @phpstan-return db_bind_types
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getSQLBindTypes)
{

	RETURN_MEMBER_TYPED(getThis(), "sqlBindTypes", IS_ARRAY);
}

/**
 * Active SQL statement in the object
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getSQLStatement)
{

	RETURN_MEMBER_TYPED(getThis(), "sqlStatement", IS_STRING);
}

/**
 * Active SQL variables in the object
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getSQLVariables)
{

	RETURN_MEMBER_TYPED(getThis(), "sqlVariables", IS_ARRAY);
}

/**
 * Type of database system the adapter is used for
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_STRING);
}

/**
 * Inserts data into a table using custom RDBMS SQL syntax
 *
 * ```php
 * // Inserting a new invoice
 * $success = $connection->insert(
 *     "co_invoices",
 *     ["Test Invoice", 100],
 *     ["inv_title", "inv_total"]
 * );
 *
 * // Next SQL sentence is sent to the database system
 * INSERT INTO `co_invoices` (`inv_title`, `inv_total`) VALUES ("Test Invoice", 100);
 * ```
 *
 * @phpstan-param db_bind_params      $values
 * @phpstan-param db_column_names|null $fields
 * @phpstan-param db_bind_types       $dataTypes
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, insert)
{
	zend_bool _11, _25$$12;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval table_zv, *values_param = NULL, *fields = NULL, fields_sub, *dataTypes = NULL, dataTypes_sub, __$null, bindDataTypes, escapedTable, escapedFields, field, insertSql, insertValues, joinedValues, placeholder, placeholders, position, tableName, value, *_1, _10, _17, _18, _0$$3, _5$$4, _6$$4, _7$$5, _8$$5, _9$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, *_20$$12, _21$$12, *_22$$12, _24$$12, _27$$12, _23$$13, _26$$14;
	zend_string *table = NULL, *_3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&escapedTable);
	ZVAL_UNDEF(&escapedFields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&insertSql);
	ZVAL_UNDEF(&insertValues);
	ZVAL_UNDEF(&joinedValues);
	ZVAL_UNDEF(&placeholder);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&values);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(table)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(fields)
		Z_PARAM_ZVAL_OR_NULL(dataTypes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		fields = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		dataTypes = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	zephir_get_arrval(&values, values_param);
	if (!fields) {
		fields = &fields_sub;
		fields = &__$null;
	}
	if (!dataTypes) {
		dataTypes = &dataTypes_sub;
		dataTypes = &__$null;
	}
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&values))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exceptions_cannotinsertwithoutdata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 63, &table_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Adapter/AbstractAdapter.zep", 1032);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&placeholders);
	array_init(&placeholders);
	ZEPHIR_INIT_VAR(&insertValues);
	array_init(&insertValues);
	ZEPHIR_INIT_VAR(&bindDataTypes);
	array_init(&bindDataTypes);
	zephir_is_iterable(&values, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 1057);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&position, _3);
			} else {
				ZVAL_LONG(&position, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_CALL_METHOD(&placeholder, this_ptr, "buildValuePlaceholder", &_4, 64, &value, &position, dataTypes);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&_5$$4);
			zephir_array_fetch_string(&_5$$4, &placeholder, SL("placeholder"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1046);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&placeholders, &_5$$4, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1046);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_6$$4);
			zephir_array_fetch_string(&_6$$4, &placeholder, SL("bind"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1048);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(&_6$$4)) {
				ZEPHIR_OBS_NVAR(&_7$$5);
				zephir_array_fetch_string(&_7$$5, &placeholder, SL("value"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1049);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&insertValues, &_7$$5, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1049);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_8$$5);
				zephir_array_fetch_string(&_8$$5, &placeholder, SL("hasBindType"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1051);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_8$$5)) {
					ZEPHIR_OBS_NVAR(&_9$$6);
					zephir_array_fetch_string(&_9$$6, &placeholder, SL("bindType"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1052);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindDataTypes, &_9$$6, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1052);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&position, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&placeholder, this_ptr, "buildValuePlaceholder", &_4, 64, &value, &position, dataTypes);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_12$$7);
				zephir_array_fetch_string(&_12$$7, &placeholder, SL("placeholder"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1046);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&placeholders, &_12$$7, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1046);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_13$$7);
				zephir_array_fetch_string(&_13$$7, &placeholder, SL("bind"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1048);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_13$$7)) {
					ZEPHIR_OBS_NVAR(&_14$$8);
					zephir_array_fetch_string(&_14$$8, &placeholder, SL("value"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1049);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&insertValues, &_14$$8, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1049);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_15$$8);
					zephir_array_fetch_string(&_15$$8, &placeholder, SL("hasBindType"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1051);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&_15$$8)) {
						ZEPHIR_OBS_NVAR(&_16$$9);
						zephir_array_fetch_string(&_16$$9, &placeholder, SL("bindType"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1052);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindDataTypes, &_16$$9, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1052);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, ".");
	ZEPHIR_INIT_VAR(&_18);
	zephir_fast_strpos(&_18, &table_zv, &_17, 0 );
	if (ZEPHIR_GT_LONG(&_18, 0)) {
		ZEPHIR_INIT_VAR(&tableName);
		zephir_fast_explode_str(&tableName, SL("."), &table_zv, NULL);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(&tableName, &table_zv);
	}
	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeIdentifier", &_19, 0, &tableName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&joinedValues);
	zephir_fast_join_str(&joinedValues, SL(", "), &placeholders);
	ZEPHIR_INIT_VAR(&insertSql);
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&escapedFields);
		array_init(&escapedFields);
		if (Z_TYPE_P(fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_21$$12);
			zephir_string_to_char_array(&_21$$12, fields);
			_20$$12 = &_21$$12;
		} else {
			_20$$12 = fields;
		}
		zephir_is_iterable(_20$$12, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 1077);
		if (Z_TYPE_P(_20$$12) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_20$$12), _22$$12)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _22$$12);
				ZEPHIR_CALL_METHOD(&_23$$13, this_ptr, "escapeIdentifier", &_19, 0, &field);
				zephir_check_call_status();
				zephir_array_append(&escapedFields, &_23$$13, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1074);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _20$$12, "rewind", NULL, 0);
			zephir_check_call_status();
			_25$$12 = 1;
			while (1) {
				if (_25$$12) {
					_25$$12 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _20$$12, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_24$$12, _20$$12, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_24$$12)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _20$$12, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_26$$14, this_ptr, "escapeIdentifier", &_19, 0, &field);
					zephir_check_call_status();
					zephir_array_append(&escapedFields, &_26$$14, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1074);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_VAR(&_27$$12);
		zephir_fast_join_str(&_27$$12, SL(", "), &escapedFields);
		ZEPHIR_CONCAT_SVSVSVS(&insertSql, "INSERT INTO ", &escapedTable, " (", &_27$$12, ") VALUES (", &joinedValues, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CONCAT_SVSVS(&insertSql, "INSERT INTO ", &escapedTable, " VALUES (", &joinedValues, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_EMPTY(&bindDataTypes)) {
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
 * ```php
 * // Inserting a new invoice
 * $success = $connection->insertAsDict(
 *     "co_invoices",
 *     [
 *         "inv_title" => "Test Invoice",
 *         "inv_total" => 100,
 *     ]
 * );
 *
 * // Next SQL sentence is sent to the database system
 * INSERT INTO `co_invoices` (`inv_title`, `inv_total`) VALUES ("Test Invoice", 100);
 * ```
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, insertAsDict)
{
	zend_ulong _4;
	zend_bool _0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, *data, data_sub, *dataTypes = NULL, dataTypes_sub, __$null, values, fields, field, value, *_1, _2, *_3, _6;
	zend_string *table = NULL, *_5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(table)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(dataTypes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		dataTypes = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
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
	if (Z_TYPE_P(data) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, data);
		_1 = &_2;
	} else {
		_1 = data;
	}
	zephir_is_iterable(_1, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 1123);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&field, _5);
			} else {
				ZVAL_LONG(&field, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1119);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1120);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _1, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1119);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1120);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "insert", NULL, 0, &table_zv, &values, &fields, dataTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns if nested transactions should use savepoints
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, isNestedTransactionsWithSavepoints)
{

	RETURN_MEMBER(getThis(), "transactionsWithSavepoints");
}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * ```php
 * echo $connection->limit("SELECT * FROM co_invoices", 5);
 * ```
 *
 * @phpstan-param db_limit_number $number
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, limit)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sqlQuery_zv, *number, number_sub, _0;
	zend_string *sqlQuery = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_ZVAL(number)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	number = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "limit", NULL, 0, &sqlQuery_zv, number);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * List all tables on a database
 *
 *```php
 * print_r(
 *     $connection->listTables("blog")
 * );
 *```
 *
 * @phpstan-return db_table_names
 *
 * @todo optimize this
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, listTables)
{
	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval schemaName_zv, tables, table, allTables, _0, _1, _2, *_3, _4, *_5, _7, _6$$3, _9$$4;
	zend_string *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&allTables);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	ZEPHIR_INIT_VAR(&allTables);
	array_init(&allTables);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "listTables", NULL, 0, &schemaName_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&tables, this_ptr, "fetchAll", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&tables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &tables);
		_3 = &_4;
	} else {
		_3 = &tables;
	}
	zephir_is_iterable(_3, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 1176);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _5);
			ZEPHIR_OBS_NVAR(&_6$$3);
			zephir_array_fetch_long(&_6$$3, &table, 0, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1173);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&allTables, &_6$$3, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1173);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_9$$4);
				zephir_array_fetch_long(&_9$$4, &table, 0, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1173);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&allTables, &_9$$4, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1173);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	RETURN_CCTOR(&allTables);
}

/**
 * List all views on a database
 *
 *```php
 * print_r(
 *     $connection->listViews("blog")
 * );
 *```
 *
 * @phpstan-return db_table_names
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, listViews)
{
	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval schemaName_zv, tables, table, allTables, _0, _1, _2, *_3, _4, *_5, _7, _6$$3, _9$$4;
	zend_string *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&allTables);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	ZEPHIR_INIT_VAR(&allTables);
	array_init(&allTables);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "listViews", NULL, 0, &schemaName_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&tables, this_ptr, "fetchAll", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&tables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &tables);
		_3 = &_4;
	} else {
		_3 = &tables;
	}
	zephir_is_iterable(_3, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 1205);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _5);
			ZEPHIR_OBS_NVAR(&_6$$3);
			zephir_array_fetch_long(&_6$$3, &table, 0, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1202);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&allTables, &_6$$3, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1202);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_9$$4);
				zephir_array_fetch_long(&_9$$4, &table, 0, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1202);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&allTables, &_9$$4, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1202);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	RETURN_CCTOR(&allTables);
}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, modifyColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, _0, _1;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(currentColumn, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	column = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		currentColumn = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		currentColumn = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "modifyColumn", NULL, 0, &tableName_zv, &schemaName_zv, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends an `ON CONFLICT (...) DO UPDATE SET col = excluded.col`
 * upsert clause to the supplied INSERT statement. Supported by
 * PostgreSQL and SQLite 3.24+; MySQL throws.
 *
 * @phpstan-param db_column_names $conflictColumns
 * @phpstan-param db_column_names $updateColumns
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, onConflictUpdate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval conflictColumns, updateColumns;
	zval sqlQuery_zv, *conflictColumns_param = NULL, *updateColumns_param = NULL, _0;
	zend_string *sqlQuery = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&conflictColumns);
	ZVAL_UNDEF(&updateColumns);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(sqlQuery)
		ZEPHIR_Z_PARAM_ARRAY(conflictColumns, conflictColumns_param)
		ZEPHIR_Z_PARAM_ARRAY(updateColumns, updateColumns_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	conflictColumns_param = ZEND_CALL_ARG(execute_data, 2);
	updateColumns_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	zephir_get_arrval(&conflictColumns, conflictColumns_param);
	zephir_get_arrval(&updateColumns, updateColumns_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "onConflictUpdate", NULL, 0, &sqlQuery_zv, &conflictColumns, &updateColumns);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Refreshes a materialized view (PostgreSQL only). Pass
 * `concurrent = true` for non-blocking refresh.
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, refreshMaterializedView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool concurrent;
	zval viewName_zv, schemaName_zv, *concurrent_param = NULL, _0, _1, _2;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(concurrent)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		concurrent_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!concurrent_param) {
		concurrent = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	if (concurrent) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, &_0, "refreshMaterializedView", NULL, 0, &viewName_zv, &schemaName_zv, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Releases given savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, releaseSavepoint)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1, _2, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkSavepoints", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "supportsReleaseSavePoints", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "releaseSavepoint", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Appends a RETURNING clause to an INSERT/UPDATE/DELETE SQL statement
 * and returns the modified SQL. Supported by PostgreSQL and SQLite 3.35+;
 * MySQL throws (no RETURNING construct). Pass `["*"]` for `RETURNING *`.
 *
 * @phpstan-param db_column_names $columns
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, returning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval columns;
	zval sqlQuery_zv, *columns_param = NULL, _0;
	zend_string *sqlQuery = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&columns);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(sqlQuery)
		ZEPHIR_Z_PARAM_ARRAY(columns, columns_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	columns_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	zephir_get_arrval(&columns, columns_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "returning", NULL, 0, &sqlQuery_zv, &columns);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Rollbacks given savepoint
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, rollbackSavepoint)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkSavepoints", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "rollbackSavepoint", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the event manager
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 81, eventsManager);
}

/**
 * Sets the dialect used to produce the SQL
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, setDialect)
{
	zval *dialect, dialect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dialect_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(dialect, phalcon_db_dialectinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &dialect);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 78, dialect);
}

/**
 * Set if nested transactions should use savepoints
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, setNestedTransactionsWithSavepoints)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nestedTransactionsWithSavepoints_param = NULL, __$true, __$false, _0, _2, _3, _1$$3, _4$$4;
	zend_bool nestedTransactionsWithSavepoints;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transactionLevel", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("dialect", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("transactionsWithSavepoints", 26, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(nestedTransactionsWithSavepoints)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &nestedTransactionsWithSavepoints_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 80, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_GT_LONG(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_nestedtransactionchangeblocked_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 65);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/AbstractAdapter.zep", 1317);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "supportsSavePoints", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_db_exceptions_savepointsnotsupported_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 66);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Db/Adapter/AbstractAdapter.zep", 1321);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (nestedTransactionsWithSavepoints) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 82, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 82, &__$false);
	}
	RETURN_THIS();
}

/**
 * Returns a SQL modified with a shared-lock clause. The optional
 * `modifier` is passed straight to the dialect (use
 * `Dialect::LOCK_NOWAIT` / `Dialect::LOCK_SKIP_LOCKED` for PostgreSQL).
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, sharedLock)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sqlQuery_zv, modifier_zv, _0;
	zend_string *sqlQuery = NULL, *modifier = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&modifier_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(modifier)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	if (!modifier) {
		modifier = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&modifier_zv);
		ZVAL_STR(&modifier_zv, modifier);
	} else {
		zephir_memory_observe(&modifier_zv);
	ZVAL_STR_COPY(&modifier_zv, modifier);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "sharedLock", NULL, 0, &sqlQuery_zv, &modifier_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether the database system support the DEFAULT
 * keyword (SQLite does not support it)
 *
 * @deprecated Will be removed in a future major release.
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, supportsDefaultValue)
{

	RETURN_BOOL(1);
}

/**
 * Check whether the database system requires a sequence to produce
 * auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, supportSequences)
{

	RETURN_BOOL(0);
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 *```php
 * var_dump(
 *     $connection->tableExists("blog", "posts")
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, tableExists)
{
	zend_bool _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, result, _0, _1, _2, _5;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "tableExists", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "fetchOne", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	_3 = Z_TYPE_P(&result) != IS_ARRAY;
	if (!(_3)) {
		_4 = zephir_array_isset_value_long(&result, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = !(_4);
	}
	if (_3) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&_5);
	zephir_array_fetch_long(&_5, &result, 0, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1381);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_5, 0));
}

/**
 * Gets creation options from a table
 *
 *```php
 * print_r(
 *     $connection->tableOptions("co_invoices")
 * );
 *```
 *
 * @phpstan-return db_table_options
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, tableOptions)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, sql, options, _0, _1, _3;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "tableOptions", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&sql))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(&options, this_ptr, "fetchAll", NULL, 0, &sql, &_1);
	zephir_check_call_status();
	_2 = zephir_array_isset_value_long(&options, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_memory_observe(&_3);
	zephir_array_fetch_long(&_3, &options, 0, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1411);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_3);
}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * ```php
 * // Updating existing invoice
 * $success = $connection->update(
 *     "co_invoices",
 *     ["inv_title"],
 *     ["New Test Invoice"],
 *     "inv_id = 101"
 * );
 *
 * // Next SQL sentence is sent to the database system
 * UPDATE `co_invoices` SET `inv_title` = "New Test Invoice" WHERE inv_id = 101
 *
 * // Updating existing invoice with array condition and $dataTypes
 * $success = $connection->update(
 *     "co_invoices",
 *     ["inv_title"],
 *     ["New Test Invoice"],
 *     [
 *         "conditions" => "inv_id = ?",
 *         "bind"       => [$some_unsafe_id],
 *         "bindTypes"  => [PDO::PARAM_INT], // use only if you use $dataTypes param
 *     ],
 *     [
 *         PDO::PARAM_STR
 *     ]
 * );
 *
 * ```
 *
 * Warning! If $whereCondition is string, it is not escaped.
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, update)
{
	zend_bool _17, _5$$3, _18$$7, _30$$15, _31$$15, _32$$15;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_9 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, *fields, fields_sub, *values, values_sub, *whereCondition = NULL, whereCondition_sub, *dataTypes = NULL, dataTypes_sub, __$null, bindDataTypes, conditions, escapedField, escapedTable, field, placeholder, placeholders, position, setClause, tableName, updateSql, updateValues, value, whereBind, whereTypes, *_0, _1, *_2, _16, _27, _28, _10$$3, _11$$3, _12$$3, _6$$4, _13$$5, _14$$5, _15$$6, _21$$7, _22$$7, _23$$7, _19$$8, _24$$9, _25$$9, _26$$10, _29$$16;
	zend_string *table = NULL, *_4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&whereCondition_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&escapedField);
	ZVAL_UNDEF(&escapedTable);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&placeholder);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&setClause);
	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&updateSql);
	ZVAL_UNDEF(&updateValues);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&whereBind);
	ZVAL_UNDEF(&whereTypes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_29$$16);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_STR(table)
		Z_PARAM_ZVAL(fields)
		Z_PARAM_ZVAL(values)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(whereCondition)
		Z_PARAM_ZVAL_OR_NULL(dataTypes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	fields = ZEND_CALL_ARG(execute_data, 2);
	values = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		whereCondition = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		dataTypes = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
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
	if (Z_TYPE_P(values) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, values);
		_0 = &_1;
	} else {
		_0 = values;
	}
	zephir_is_iterable(_0, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 1486);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_0), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&position, _4);
			} else {
				ZVAL_LONG(&position, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_OBS_NVAR(&field);
			_5$$3 = zephir_array_isset_fetch(&field, fields, &position, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_5$$3))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				object_init_ex(&_6$$4, phalcon_db_exceptions_updatefieldcountmismatch_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", &_7, 67);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$4, "phalcon/Db/Adapter/AbstractAdapter.zep", 1466);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&escapedField, this_ptr, "escapeIdentifier", &_8, 0, &field);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&placeholder, this_ptr, "buildValuePlaceholder", &_9, 64, &value, &position, dataTypes);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&_10$$3);
			zephir_array_fetch_string(&_10$$3, &placeholder, SL("placeholder"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1472);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZEPHIR_CONCAT_VSV(&_11$$3, &escapedField, " = ", &_10$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&placeholders, &_11$$3, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1472);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_12$$3);
			zephir_array_fetch_string(&_12$$3, &placeholder, SL("bind"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1474);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(&_12$$3)) {
				ZEPHIR_OBS_NVAR(&_13$$5);
				zephir_array_fetch_string(&_13$$5, &placeholder, SL("value"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1475);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&updateValues, &_13$$5, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1475);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_14$$5);
				zephir_array_fetch_string(&_14$$5, &placeholder, SL("hasBindType"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1477);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_14$$5)) {
					ZEPHIR_OBS_NVAR(&_15$$6);
					zephir_array_fetch_string(&_15$$6, &placeholder, SL("bindType"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1478);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&bindDataTypes, &_15$$6, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1478);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _0, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, _0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&position, _0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&field);
				_18$$7 = zephir_array_isset_fetch(&field, fields, &position, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_18$$7))) {
					ZEPHIR_INIT_NVAR(&_19$$8);
					object_init_ex(&_19$$8, phalcon_db_exceptions_updatefieldcountmismatch_ce);
					ZEPHIR_CALL_METHOD(NULL, &_19$$8, "__construct", &_20, 67);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$8, "phalcon/Db/Adapter/AbstractAdapter.zep", 1466);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&escapedField, this_ptr, "escapeIdentifier", &_8, 0, &field);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&placeholder, this_ptr, "buildValuePlaceholder", &_9, 64, &value, &position, dataTypes);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_21$$7);
				zephir_array_fetch_string(&_21$$7, &placeholder, SL("placeholder"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1472);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_22$$7);
				ZEPHIR_CONCAT_VSV(&_22$$7, &escapedField, " = ", &_21$$7);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&placeholders, &_22$$7, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1472);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_23$$7);
				zephir_array_fetch_string(&_23$$7, &placeholder, SL("bind"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1474);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_23$$7)) {
					ZEPHIR_OBS_NVAR(&_24$$9);
					zephir_array_fetch_string(&_24$$9, &placeholder, SL("value"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1475);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&updateValues, &_24$$9, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1475);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_25$$9);
					zephir_array_fetch_string(&_25$$9, &placeholder, SL("hasBindType"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1477);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&_25$$9)) {
						ZEPHIR_OBS_NVAR(&_26$$10);
						zephir_array_fetch_string(&_26$$10, &placeholder, SL("bindType"), PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1478);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&bindDataTypes, &_26$$10, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1478);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_STRING(&_27, ".");
	ZEPHIR_INIT_VAR(&_28);
	zephir_fast_strpos(&_28, &table_zv, &_27, 0 );
	if (ZEPHIR_GT_LONG(&_28, 0)) {
		ZEPHIR_INIT_VAR(&tableName);
		zephir_fast_explode_str(&tableName, SL("."), &table_zv, NULL);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(&tableName, &table_zv);
	}
	ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeIdentifier", &_8, 0, &tableName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&setClause);
	zephir_fast_join_str(&setClause, SL(", "), &placeholders);
	ZEPHIR_INIT_VAR(&updateSql);
	if (Z_TYPE_P(whereCondition) != IS_NULL) {
		ZEPHIR_CONCAT_SVSVS(&updateSql, "UPDATE ", &escapedTable, " SET ", &setClause, " WHERE ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(whereCondition) == IS_STRING) {
			zephir_concat_self(&updateSql, whereCondition);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			if (UNEXPECTED(Z_TYPE_P(whereCondition) != IS_ARRAY)) {
				ZEPHIR_INIT_VAR(&_29$$16);
				object_init_ex(&_29$$16, phalcon_db_exceptions_invalidwhereconditions_ce);
				ZEPHIR_CALL_METHOD(NULL, &_29$$16, "__construct", NULL, 68);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_29$$16, "phalcon/Db/Adapter/AbstractAdapter.zep", 1508);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&conditions);
			_30$$15 = zephir_array_isset_string_fetch(&conditions, whereCondition, SL("conditions"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_30$$15) {
				zephir_concat_self(&updateSql, &conditions);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_memory_observe(&whereBind);
			_31$$15 = zephir_array_isset_string_fetch(&whereBind, whereCondition, SL("bind"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_31$$15) {
				zephir_merge_append(&updateValues, &whereBind);
			}
			zephir_memory_observe(&whereTypes);
			_32$$15 = zephir_array_isset_string_fetch(&whereTypes, whereCondition, SL("bindTypes"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_32$$15) {
				zephir_merge_append(&bindDataTypes, &whereTypes);
			}
		}
	} else {
		ZEPHIR_CONCAT_SVSV(&updateSql, "UPDATE ", &escapedTable, " SET ", &setClause);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_EMPTY(&bindDataTypes)) {
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
 * ```php
 * // Updating existing invoice
 * $success = $connection->updateAsDict(
 *     "co_invoices",
 *     [
 *         "inv_title" => "New Test Invoice",
 *     ],
 *     "inv_id = 101"
 * );
 *
 * // Next SQL sentence is sent to the database system
 * UPDATE `co_invoices` SET `inv_title` = "New Test Invoice" WHERE inv_id = 101
 * ```
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, updateAsDict)
{
	zend_ulong _4;
	zend_bool _0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, *data, data_sub, *whereCondition = NULL, whereCondition_sub, *dataTypes = NULL, dataTypes_sub, __$null, values, fields, field, value, *_1, _2, *_3, _6;
	zend_string *table = NULL, *_5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&whereCondition_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(table)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(whereCondition)
		Z_PARAM_ZVAL_OR_NULL(dataTypes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		whereCondition = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		dataTypes = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
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
	if (Z_TYPE_P(data) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, data);
		_1 = &_2;
	} else {
		_1 = data;
	}
	zephir_is_iterable(_1, 0, "phalcon/Db/Adapter/AbstractAdapter.zep", 1581);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&field, _5);
			} else {
				ZVAL_LONG(&field, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1577);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1578);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _1, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1577);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/Db/Adapter/AbstractAdapter.zep", 1578);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "update", NULL, 0, &table_zv, &fields, &values, whereCondition, dataTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether the database system requires an explicit value for identity
 * columns
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, useExplicitIdValue)
{

	RETURN_BOOL(0);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 *```php
 * var_dump(
 *     $connection->viewExists("active_users", "posts")
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, viewExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval viewName_zv, schemaName_zv, _0, _1, _2, _3, _4;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "viewExists", NULL, 0, &viewName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchOne", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_memory_observe(&_4);
	zephir_array_fetch_long(&_4, &_0, 0, PH_NOISY, "phalcon/Db/Adapter/AbstractAdapter.zep", 1604);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_4, 0));
}

/**
 * Check if savepoints are supported
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, checkSavepoints)
{
	zval _0, _1, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 78, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "supportsSavePoints", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_db_exceptions_savepointsnotsupported_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 66);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Db/Adapter/AbstractAdapter.zep", 1615);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds the SQL value fragment for a single INSERT/UPDATE value, shared by
 * insert() and update(). RawValue instances are inlined as raw SQL, objects
 * are cast via __toString, null becomes the literal "null", and every other
 * value becomes a "?" placeholder.
 *
 * Zephir cannot mutate caller arrays by reference, so the bound value and
 * bind type are returned for the caller to collect. The returned array has:
 *
 *  - "placeholder": string  - the SQL fragment ("null", "?", or raw SQL)
 *  - "bind":        bool    - whether "value" must be bound
 *  - "value":       mixed   - the value to bind (when "bind" is true)
 *  - "hasBindType": bool    - whether "bindType" must be collected
 *  - "bindType":    mixed   - the bind type to collect (when applicable)
 *
 * @param mixed $value
 * @param mixed $position
 * @param mixed $dataTypes
 *
 * @return array
 *
 * @phpstan-param int|string         $position
 * @phpstan-param db_bind_types|null $dataTypes
 *
 * @phpstan-return db_value_placeholder
 */
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, buildValuePlaceholder)
{
	zval _1$$3, _2$$4;
	zend_bool hasBindType = 0, _0, _3$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *position, position_sub, *dataTypes, dataTypes_sub, __$false, __$null, __$true, bindType, _5, _4$$7;

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(value)
		Z_PARAM_ZVAL(position)
		Z_PARAM_ZVAL(dataTypes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &value, &position, &dataTypes);
	ZEPHIR_SEPARATE_PARAM(value);
	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(value, phalcon_db_rawvalue_ce);
	}
	if (_0) {
		zephir_create_array(return_value, 5, 0);
		zephir_cast_to_string(&_1$$3, value);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(return_value, SL("placeholder"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("bind"), &__$false, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("value"), &__$null, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("hasBindType"), &__$false, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("bindType"), &__$null, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	if (Z_TYPE_P(value) == IS_OBJECT) {
		zephir_cast_to_string(&_2$$4, value);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(value, &_2$$4);
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		zephir_create_array(return_value, 5, 0);
		add_assoc_stringl_ex(return_value, SL("placeholder"), SL("null"));
		zephir_array_update_string(return_value, SL("bind"), &__$false, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("value"), &__$null, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("hasBindType"), &__$false, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("bindType"), &__$null, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&bindType);
	ZVAL_NULL(&bindType);
	hasBindType = (Z_TYPE_P(dataTypes) == IS_ARRAY);
	if (hasBindType) {
		ZEPHIR_OBS_NVAR(&bindType);
		_3$$6 = zephir_array_isset_fetch(&bindType, dataTypes, position, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_3$$6))) {
			ZEPHIR_INIT_VAR(&_4$$7);
			object_init_ex(&_4$$7, phalcon_db_exceptions_incompletebindtypes_ce);
			ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 69);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$7, "phalcon/Db/Adapter/AbstractAdapter.zep", 1679);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_create_array(return_value, 5, 0);
	add_assoc_stringl_ex(return_value, SL("placeholder"), SL("?"));
	zephir_array_update_string(return_value, SL("bind"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("value"), value, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_BOOL(&_5, hasBindType);
	zephir_array_update_string(return_value, SL("hasBindType"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("bindType"), &bindType, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

