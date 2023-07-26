
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * Provides array quoting, profiling, a new `perform()` method, new `fetch*()`
 * methods
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection_AbstractConnection)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\DataMapper\\Pdo\\Connection, AbstractConnection, phalcon, datamapper_pdo_connection_abstractconnection, phalcon_datamapper_pdo_connection_abstractconnection_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var \PDO
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_connection_abstractconnection_ce, SL("pdo"), ZEND_ACC_PROTECTED);
	/**
	 * @var ProfilerInterface
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_connection_abstractconnection_ce, SL("profiler"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_datamapper_pdo_connection_abstractconnection_ce, 1, phalcon_datamapper_pdo_connection_connectioninterface_ce);
	return SUCCESS;
}

/**
 * Proxies to PDO methods created for specific drivers; in particular,
 * `sqlite` and `pgsql`.
 *
 * @param string $name
 * @param array  $arguments
 *
 * @return mixed
 * @throws BadMethodCallException
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _2;
	zval *name, name_sub, *arguments_param = NULL, className, message, _0, _3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &arguments_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	if (!((zephir_method_exists(&_0, name)  == SUCCESS))) {
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, this_ptr, 0);
		ZEPHIR_INIT_VAR(&message);
		ZEPHIR_CONCAT_SVSVS(&message, "Class '", &className, "' does not have a method '", name, "'");
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_BadMethodCallException);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 72, &message);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 59);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC);
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, name);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Begins a transaction. If the profiler is enabled, the operation will
 * be recorded.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, beginTransaction)
{
	zval result, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "beginTransaction");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_2, "begintransaction", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "finish", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Commits the existing transaction. If the profiler is enabled, the
 * operation will be recorded.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, commit)
{
	zval result, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "commit");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_2, "commit", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "finish", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Connects to the database.
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, connect)
{
}

/**
 * Disconnects from the database.
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, disconnect)
{
}

/**
 * Gets the most recent error code.
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, errorCode)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "errorcode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the most recent error info.
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, errorInfo)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "errorinfo", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes an SQL statement and returns the number of affected rows. If
 * the profiler is enabled, the operation will be recorded.
 *
 * @param string $statement
 *
 * @return int
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, exec)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, affectedRows, _0, _1, _2, _3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&affectedRows);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(statement)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_strval(&statement, statement_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "exec");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&affectedRows, &_2, "exec", NULL, 0, &statement);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "finish", NULL, 0, &statement);
	zephir_check_call_status();
	RETURN_CCTOR(&affectedRows);
}

/**
 * Performs a statement and returns the number of affected rows.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return int
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchAffected)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *statement_param = NULL, *values_param = NULL, sth;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, 0, &statement, &values);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&sth, "rowcount", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches a sequential array of rows from the database; the rows are
 * returned as associative arrays.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchAll)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, _0;
	zval *statement_param = NULL, *values_param = NULL, _1;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 2);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fetchAll");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fetchdata", NULL, 0, &_1, &_0, &statement, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches an associative array of rows from the database; the rows are
 * returned as associative arrays, and the array of rows is keyed on the
 * first column of each row.
 *
 * If multiple rows have the same first column value, the last row with
 * that value will overwrite earlier rows. This method is more resource
 * intensive and should be avoided if possible.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchAssoc)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *statement_param = NULL, *values_param = NULL, data, row, sth, _0, _1$$3, _3$$3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, 0, &statement, &values);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_METHOD(&row, &sth, "fetch", NULL, 0, &_0);
	zephir_check_call_status();
	while (1) {
		if (!(zephir_is_true(&row))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&_1$$3, "current", &_2, 4, &row);
		zephir_check_call_status();
		zephir_array_update_zval(&data, &_1$$3, &row, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_3$$3, 2);
		ZEPHIR_CALL_METHOD(&row, &sth, "fetch", NULL, 0, &_3$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&data);
}

/**
 * Fetches a column of rows as a sequential array (default first one).
 *
 * @param string $statement
 * @param array  $values
 * @param int    $column
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long column, ZEPHIR_LAST_CALL_STATUS;
	zval values, _0;
	zval *statement_param = NULL, *values_param = NULL, *column_param = NULL, _1;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
		Z_PARAM_LONG(column)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &statement_param, &values_param, &column_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	if (!column_param) {
		column = 0;
	} else {
		column = zephir_get_intval(column_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 7);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, column);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fetchAll");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fetchdata", NULL, 0, &_1, &_0, &statement, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches multiple from the database as an associative array. The first
 * column will be the index key. The default flags are
 * PDO::FETCH_ASSOC | PDO::FETCH_GROUP
 *
 * @param string $statement
 * @param array  $values
 * @param int    $flags
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchGroup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval values, _0;
	zval *statement_param = NULL, *values_param = NULL, *flags_param = NULL, _1;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &statement_param, &values_param, &flags_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	if (!flags_param) {
		flags = 2;
	} else {
		flags = zephir_get_intval(flags_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, (65536 | flags));
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fetchAll");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fetchdata", NULL, 0, &_1, &_0, &statement, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches one row from the database as an object where the column values
 * are mapped to object properties.
 *
 * Since PDO injects property values before invoking the constructor, any
 * initializations for defaults that you potentially have in your object's
 * constructor, will override the values that have been injected by
 * `fetchObject`. The default object returned is `\stdClass`
 *
 * @param string $statement
 * @param array  $values
 * @param string $class
 * @param array  $arguments
 *
 * @return object
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchObject)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, arguments;
	zval *statement_param = NULL, *values_param = NULL, *className_param = NULL, *arguments_param = NULL, sth;
	zval statement, className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&arguments);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
		Z_PARAM_STR(className)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &statement_param, &values_param, &className_param, &arguments_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	if (!className_param) {
		ZEPHIR_INIT_VAR(&className);
		ZVAL_STRING(&className, "stdClass");
	} else {
		zephir_get_strval(&className, className_param);
	}
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, 0, &statement, &values);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&sth, "fetchobject", NULL, 0, &className, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches a sequential array of rows from the database; the rows are
 * returned as objects where the column values are mapped to object
 * properties.
 *
 * Since PDO injects property values before invoking the constructor, any
 * initializations for defaults that you potentially have in your object's
 * constructor, will override the values that have been injected by
 * `fetchObject`. The default object returned is `\stdClass`
 *
 * @param string $statement
 * @param array  $values
 * @param string $class
 * @param array  $arguments
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchObjects)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, arguments;
	zval *statement_param = NULL, *values_param = NULL, *className_param = NULL, *arguments_param = NULL, sth, _0;
	zval statement, className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&arguments);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
		Z_PARAM_STR(className)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &statement_param, &values_param, &className_param, &arguments_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	if (!className_param) {
		ZEPHIR_INIT_VAR(&className);
		ZVAL_STRING(&className, "stdClass");
	} else {
		zephir_get_strval(&className, className_param);
	}
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, 0, &statement, &values);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 8);
	ZEPHIR_RETURN_CALL_METHOD(&sth, "fetchall", NULL, 0, &_0, &className, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches one row from the database as an associative array.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchOne)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, _0;
	zval *statement_param = NULL, *values_param = NULL, _1;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 2);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fetch");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fetchdata", NULL, 0, &_1, &_0, &statement, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches an associative array of rows as key-value pairs (first column is
 * the key, second column is the value).
 *
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchPairs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, _0;
	zval *statement_param = NULL, *values_param = NULL, _1;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 12);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fetchAll");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fetchdata", NULL, 0, &_1, &_0, &statement, &values);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches the very first value (i.e., first column of the first row).
 *
 * @param string $statement
 * @param array  $values
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *statement_param = NULL, *values_param = NULL, sth, _0;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, 0, &statement, &values);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(&sth, "fetchcolumn", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the inner PDO (if any)
 *
 * @return \PDO
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, getAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER(getThis(), "pdo");
}

/**
 * Retrieve a database connection attribute
 *
 * @param int $attribute
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, getAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, _0, _1;
	zend_long attribute, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(attribute)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);
	attribute = zephir_get_intval(attribute_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, attribute);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getattribute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return an array of available PDO drivers (empty array if none available)
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, getAvailableDrivers)
{
	zend_class_entry *_0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_class_str_ex(SL("PDO"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_RETURN_CALL_CE_STATIC(_0, "getavailabledrivers", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the driver name
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, getDriverName)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 16);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getattribute", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the Profiler instance.
 *
 * @return ProfilerInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, getProfiler)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "profiler");
}

/**
 * Gets the quote parameters based on the driver
 *
 * @param string $driver
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, getQuoteNames)
{
	zval quotes;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *driver_param = NULL, option, _0$$5, _1$$6;
	zval driver;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&quotes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(driver)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &driver_param);
	if (!driver_param) {
		ZEPHIR_INIT_VAR(&driver);
		ZVAL_STRING(&driver, "");
	} else {
		zephir_get_strval(&driver, driver_param);
	}


	ZEPHIR_CPY_WRT(&option, &driver);
	if (ZEPHIR_IS_EMPTY(&option)) {
		ZEPHIR_CALL_METHOD(&option, this_ptr, "getdrivername", NULL, 0);
		zephir_check_call_status();
	}
	do {
		if (ZEPHIR_IS_STRING(&option, "mysql")) {
			ZEPHIR_INIT_VAR(&quotes);
			zephir_create_array(&quotes, 4, 0);
			add_assoc_stringl_ex(&quotes, SL("prefix"), SL("`"));
			add_assoc_stringl_ex(&quotes, SL("suffix"), SL("`"));
			add_assoc_stringl_ex(&quotes, SL("find"), SL("`"));
			add_assoc_stringl_ex(&quotes, SL("replace"), SL("``"));
			break;
		}
		if (ZEPHIR_IS_STRING(&option, "sqlsrv")) {
			ZEPHIR_INIT_VAR(&_0$$5);
			zephir_create_array(&_0$$5, 4, 0);
			add_assoc_stringl_ex(&_0$$5, SL("prefix"), SL("["));
			add_assoc_stringl_ex(&_0$$5, SL("suffix"), SL("]"));
			add_assoc_stringl_ex(&_0$$5, SL("find"), SL("]"));
			add_assoc_stringl_ex(&_0$$5, SL("replace"), SL("]["));
			ZEPHIR_CPY_WRT(&quotes, &_0$$5);
			break;
		}
		ZEPHIR_INIT_VAR(&_1$$6);
		zephir_create_array(&_1$$6, 4, 0);
		add_assoc_stringl_ex(&_1$$6, SL("prefix"), SL("\""));
		add_assoc_stringl_ex(&_1$$6, SL("suffix"), SL("\""));
		add_assoc_stringl_ex(&_1$$6, SL("find"), SL("\""));
		add_assoc_stringl_ex(&_1$$6, SL("replace"), SL("\"\""));
		ZEPHIR_CPY_WRT(&quotes, &_1$$6);
		break;
	} while(0);

	RETURN_CTOR(&quotes);
}

/**
 * Is a transaction currently active? If the profiler is enabled, the
 * operation will be recorded. If the profiler is enabled, the operation
 * will be recorded.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, inTransaction)
{
	zval result, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "inTransaction");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_2, "intransaction", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "finish", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Is the PDO connection active?
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, isConnected)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_get_boolval(&_0));
}

/**
 * Returns the last inserted autoincrement sequence value. If the profiler
 * is enabled, the operation will be recorded.
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, lastInsertId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, result, _0, _1, _2, _3;
	zval name, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "lastInsertId");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_2, "lastinsertid", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "finish", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_4, &result);
	RETURN_CTOR(&_4);
}

/**
 * Performs a query with bound values and returns the resulting
 * PDOStatement; array values will be passed through `quote()` and their
 * respective placeholders will be replaced in the query string. If the
 * profiler is enabled, the operation will be recorded.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return \PDOStatement
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, perform)
{
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *statement_param = NULL, *values_param = NULL, name, sth, value, _0, _1, *_2, _3, _7;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "perform");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&sth, this_ptr, "prepare", NULL, 0, &statement);
	zephir_check_call_status();
	zephir_is_iterable(&values, 0, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 579);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "performbind", &_6, 0, &sth, &name, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "performbind", &_6, 0, &sth, &name, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_CALL_METHOD(NULL, &sth, "execute", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_7, "finish", NULL, 0, &statement, &values);
	zephir_check_call_status();
	RETURN_CCTOR(&sth);
}

/**
 * Prepares an SQL statement for execution.
 *
 * @param string $statement
 * @param array  $options
 *
 * @return \PDOStatement|false
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, prepare)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *statement_param = NULL, *options_param = NULL, sth, _0, _1, _2, _3, _4;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &options_param);
	zephir_get_strval(&statement, statement_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "prepare");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sth, &_2, "prepare", NULL, 0, &statement, &options);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, &sth, ZEND_STRL("queryString"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "finish", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_CCTOR(&sth);
}

/**
 * Queries the database and returns a PDOStatement. If the profiler is
 * enabled, the operation will be recorded.
 *
 * @param string $statement
 * @param mixed  ...$fetch
 *
 * @return \PDOStatement|false
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, query)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, sth, _0, _1, _3, _4, _5;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(statement)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_strval(&statement, statement_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "query");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "query");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_args(&_1);
	ZEPHIR_INIT_VAR(&sth);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&sth, &_2, &_1);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, &sth, ZEND_STRL("queryString"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_4, "finish", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_CCTOR(&sth);
}

/**
 * Quotes a value for use in an SQL statement. This differs from
 * `PDO::quote()` in that it will convert an array into a string of
 * comma-separated quoted values. The default type is `PDO::PARAM_STR`
 *
 * @param mixed $value
 * @param int   $type
 *
 * @return string The quoted value.
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, quote)
{
	zval _0$$3, _7$$4, _11$$5;
	zend_string *_6;
	zend_ulong _5;
	zval elements;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *type_param = NULL, element, key, quotes, *_3, _4, _1$$3, _2$$3, _8$$4, _9$$4, _10$$4, _12$$5, _13$$5, _14$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&quotes);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &type_param);
	if (!type_param) {
		type = 2;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_INIT_VAR(&elements);
	array_init(&elements);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&element, value);
	ZEPHIR_CALL_METHOD(&quotes, this_ptr, "getquotenames", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&element) != IS_ARRAY) {
		zephir_cast_to_string(&_0$$3, &element);
		ZEPHIR_CPY_WRT(&element, &_0$$3);
		zephir_array_fetch_string(&_1$$3, &quotes, SL("prefix"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 664);
		zephir_array_fetch_string(&_2$$3, &quotes, SL("suffix"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 664);
		ZEPHIR_CONCAT_VVV(return_value, &_1$$3, &element, &_2$$3);
		RETURN_MM();
	}
	zephir_is_iterable(value, 0, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 673);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&key, _6);
			} else {
				ZVAL_LONG(&key, _5);
			}
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _3);
			zephir_cast_to_string(&_7$$4, &element);
			ZEPHIR_CPY_WRT(&element, &_7$$4);
			zephir_array_fetch_string(&_8$$4, &quotes, SL("prefix"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 670);
			zephir_array_fetch_string(&_9$$4, &quotes, SL("suffix"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 670);
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZEPHIR_CONCAT_VVV(&_10$$4, &_8$$4, &element, &_9$$4);
			zephir_array_update_zval(&elements, &key, &_10$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, value, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, value, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&element, value, "current", NULL, 0);
			zephir_check_call_status();
				zephir_cast_to_string(&_11$$5, &element);
				ZEPHIR_CPY_WRT(&element, &_11$$5);
				zephir_array_fetch_string(&_12$$5, &quotes, SL("prefix"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 670);
				zephir_array_fetch_string(&_13$$5, &quotes, SL("suffix"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 670);
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZEPHIR_CONCAT_VVV(&_14$$5, &_12$$5, &element, &_13$$5);
				zephir_array_update_zval(&elements, &key, &_14$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, value, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_join_str(return_value, SL(", "), &elements);
	RETURN_MM();
}

/**
 * Rolls back the current transaction, and restores autocommit mode. If the
 * profiler is enabled, the operation will be recorded.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, rollBack)
{
	zval result, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "rollBack");
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_2, "rollback", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("profiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "finish", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * Set a database connection attribute
 *
 * @param int   $attribute
 * @param mixed $value
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, setAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *value, value_sub, _0, _1;
	zend_long attribute, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);
	attribute = zephir_get_intval(attribute_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, attribute);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setattribute", NULL, 0, &_1, value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the Profiler instance.
 *
 * @param ProfilerInterface $profiler
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, setProfiler)
{
	zval *profiler, profiler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&profiler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(profiler, phalcon_datamapper_pdo_profiler_profilerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &profiler);


	zephir_update_property_zval(this_ptr, ZEND_STRL("profiler"), profiler);
}

/**
 * Bind a value using the proper PDO::PARAM_* type.
 *
 * @param \PDOStatement $statement
 * @param mixed         $name
 * @param mixed         $arguments
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, performBind)
{
	zend_bool _1$$4;
	zval _8, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$3;
	zval *statement, statement_sub, *name, name_sub, *arguments, arguments_sub, key, parameters, type, _7, _9, _2$$4, _3$$7, _4$$7, _6$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_5$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(statement, zephir_get_internal_ce(SL("pdostatement")))
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &statement, &name, &arguments);
	ZEPHIR_SEPARATE_PARAM(arguments);


	ZEPHIR_CPY_WRT(&key, name);
	if (Z_TYPE_P(&key) == IS_LONG) {
		_0$$3 = (zephir_get_numberval(&key) + 1);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&key, _0$$3);
	}
	if (Z_TYPE_P(arguments) == IS_ARRAY) {
		if (zephir_array_isset_long(arguments, 1)) {
			ZEPHIR_OBS_VAR(&type);
			zephir_array_fetch_long(&type, arguments, 1, PH_NOISY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 743);
		} else {
			ZEPHIR_INIT_NVAR(&type);
			ZVAL_LONG(&type, 2);
		}
		_1$$4 = ZEPHIR_IS_LONG_IDENTICAL(&type, 5);
		if (_1$$4) {
			ZEPHIR_OBS_VAR(&_2$$4);
			zephir_array_fetch_long(&_2$$4, arguments, 0, PH_NOISY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 748);
			_1$$4 = ((Z_TYPE_P(&_2$$4) == IS_TRUE || Z_TYPE_P(&_2$$4) == IS_FALSE) == 1);
		}
		if (_1$$4) {
			ZEPHIR_INIT_VAR(&_3$$7);
			zephir_array_fetch_long(&_4$$7, arguments, 0, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Connection/AbstractConnection.zep", 749);
			if (zephir_is_true(&_4$$7)) {
				ZEPHIR_INIT_NVAR(&_3$$7);
				ZVAL_STRING(&_3$$7, "1");
			} else {
				ZEPHIR_INIT_NVAR(&_3$$7);
				ZVAL_STRING(&_3$$7, "0");
			}
			zephir_array_update_long(arguments, 0, &_3$$7, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_create_array(&_5$$4, 1, 0);
		zephir_array_fast_append(&_5$$4, &key);
		ZEPHIR_INIT_VAR(&parameters);
		zephir_fast_array_merge(&parameters, &_5$$4, arguments);
	} else {
		ZEPHIR_INIT_VAR(&_6$$8);
		zephir_create_array(&_6$$8, 2, 0);
		zephir_array_fast_append(&_6$$8, &key);
		zephir_array_fast_append(&_6$$8, arguments);
		ZEPHIR_CPY_WRT(&parameters, &_6$$8);
	}
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 2, 0);
	zephir_array_fast_append(&_8, statement);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "bindValue");
	zephir_array_fast_append(&_8, &_9);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_7, &_8, &parameters);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Helper method to get data from PDO based on the method passed
 *
 * @param string $method
 * @param array  $arguments
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Connection_AbstractConnection, fetchData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, values, _0;
	zval *method_param = NULL, *arguments_param = NULL, *statement_param = NULL, *values_param = NULL, result, sth;
	zval method, statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&sth);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(arguments)
		Z_PARAM_STR(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &method_param, &arguments_param, &statement_param, &values_param);
	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&arguments, arguments_param);
	zephir_get_strval(&statement, statement_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, 0, &statement, &values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &sth);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_0, &arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&result);
		array_init(&result);
	}
	RETURN_CCTOR(&result);
}

