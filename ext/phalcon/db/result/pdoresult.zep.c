
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
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"

#include <ext/pdo/php_pdo_driver.h>



/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Encapsulates the resultset internals
 *
 * ```php
 * $result = $connection->query("SELECT * FROM robots ORDER BY name");
 *
 * $result->setFetchMode(
 *     \Phalcon\Db\Enum::FETCH_NUM
 * );
 *
 * while ($robot = $result->fetchArray()) {
 *     print_r($robot);
 * }
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Result_PdoResult)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db\\Result, PdoResult, phalcon, db_result_pdoresult, phalcon_db_result_pdoresult_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_result_pdoresult_ce, SL("bindParams"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_result_pdoresult_ce, SL("bindTypes"), ZEND_ACC_PROTECTED);
	/**
	 * @var AdapterInterface
	 */
	zend_declare_property_null(phalcon_db_result_pdoresult_ce, SL("connection"), ZEND_ACC_PROTECTED);
	/**
	 * Active fetch mode
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_result_pdoresult_ce, SL("fetchMode"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Internal resultset
	 *
	 * @var \PDOStatement
	 */
	zend_declare_property_null(phalcon_db_result_pdoresult_ce, SL("pdoStatement"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 * TODO: Check if this property is used
	 */
	zend_declare_property_null(phalcon_db_result_pdoresult_ce, SL("result"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_result_pdoresult_ce, SL("rowCount"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_db_result_pdoresult_ce, SL("sqlStatement"), ZEND_ACC_PROTECTED);
	phalcon_db_result_pdoresult_ce->create_object = zephir_init_properties_Phalcon_Db_Result_PdoResult;

	zend_class_implements(phalcon_db_result_pdoresult_ce, 1, phalcon_db_resultinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Db\Result\Pdo constructor
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, __construct)
{
	zval *connection, connection_sub, *result, result_sub, *sqlStatement = NULL, sqlStatement_sub, *bindParams = NULL, bindParams_sub, *bindTypes = NULL, bindTypes_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&sqlStatement_sub);
	ZVAL_UNDEF(&bindParams_sub);
	ZVAL_UNDEF(&bindTypes_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 5)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_db_adapter_adapterinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(result, zephir_get_internal_ce(SL("pdostatement")))
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(sqlStatement)
		Z_PARAM_ZVAL_OR_NULL(bindParams)
		Z_PARAM_ZVAL_OR_NULL(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 3, &connection, &result, &sqlStatement, &bindParams, &bindTypes);
	if (!sqlStatement) {
		sqlStatement = &sqlStatement_sub;
		sqlStatement = &__$null;
	}
	if (!bindParams) {
		bindParams = &bindParams_sub;
		bindParams = &__$null;
	}
	if (!bindTypes) {
		bindTypes = &bindTypes_sub;
		bindTypes = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("connection"), connection);
	zephir_update_property_zval(this_ptr, ZEND_STRL("pdoStatement"), result);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlStatement"), sqlStatement);
	zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), bindParams);
	zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), bindTypes);
}

/**
 * Moves internal resultset cursor to another position letting us to fetch a
 * certain row
 *
 *```php
 * $result = $connection->query(
 *     "SELECT * FROM robots ORDER BY name"
 * );
 *
 * // Move to third row on result
 * $result->dataSeek(2);
 *
 * // Fetch third row
 * $row = $result->fetch();
 *```
 *
 * @param int number
 *
 * @return void
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, dataSeek)
{
	long n = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *number_param = NULL, connection, pdo, sqlStatement, bindParams, statement, _0, _1$$4, _2$$4, _3$$6;
	zend_long number, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&pdo);
	ZVAL_UNDEF(&sqlStatement);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(number)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number_param);
	number = zephir_get_intval(number_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	ZEPHIR_CALL_METHOD(&pdo, &connection, "getinternalhandler", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sqlStatement"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlStatement, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&bindParams, &_0);
	if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&statement, &pdo, "prepare", NULL, 0, &sqlStatement);
		zephir_check_call_status();
		if (Z_TYPE_P(&statement) == IS_OBJECT) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_1$$4, &connection, "executeprepared", NULL, 0, &statement, &bindParams, &_2$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&statement, &_1$$4);
		}
	} else {
		ZEPHIR_CALL_METHOD(&statement, &pdo, "query", NULL, 0, &sqlStatement);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("pdoStatement"), &statement);
	n = -1;
	number--;
	while (1) {
		if (!(n != number)) {
			break;
		}
		zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("fetchMode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &statement, "fetch", &_4, 0, &_3$$6);
		zephir_check_call_status();
		n++;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Allows to execute the statement again. Some database systems don't
 * support scrollable cursors. So, as cursors are forward only, we need to
 * execute the cursor again to fetch rows from the beginning
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, execute)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdoStatement"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "execute", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetches an array/object of strings that corresponds to the fetched row,
 * or FALSE if there are no more rows. This method is affected by the active
 * fetch flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
 *
 *```php
 * $result = $connection->query("SELECT * FROM robots ORDER BY name");
 *
 * $result->setFetchMode(
 *     \Phalcon\Enum::FETCH_OBJ
 * );
 *
 * while ($robot = $result->fetch()) {
 *     echo $robot->name;
 * }
 *```
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, fetch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *fetchStyle_param = NULL, *cursorOrientation_param = NULL, *cursorOffset_param = NULL, mode, _0, _1, _2;
	zend_long fetchStyle, cursorOrientation, cursorOffset, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(fetchStyle, is_null_true)
		Z_PARAM_LONG(cursorOrientation)
		Z_PARAM_LONG(cursorOffset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &fetchStyle_param, &cursorOrientation_param, &cursorOffset_param);
	if (!fetchStyle_param) {
		fetchStyle = 0;
	} else {
		fetchStyle = zephir_get_intval(fetchStyle_param);
	}
	if (!cursorOrientation_param) {
		cursorOrientation = 0;
	} else {
		cursorOrientation = zephir_get_intval(cursorOrientation_param);
	}
	if (!cursorOffset_param) {
		cursorOffset = 0;
	} else {
		cursorOffset = zephir_get_intval(cursorOffset_param);
	}


	if (1 == 1) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_LONG(&mode, fetchStyle);
	} else {
		ZEPHIR_OBS_NVAR(&mode);
		zephir_read_property(&mode, this_ptr, ZEND_STRL("fetchMode"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdoStatement"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, cursorOrientation);
	ZVAL_LONG(&_2, cursorOffset);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "fetch", NULL, 0, &mode, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns an array of arrays containing all the records in the result
 * This method is affected by the active fetch flag set using
 * `Phalcon\Db\Result\Pdo::setFetchMode()`
 *
 *```php
 * $result = $connection->query(
 *     "SELECT * FROM robots ORDER BY name"
 * );
 *
 * $robots = $result->fetchAll();
 *```
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, fetchAll)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *fetchStyle_param = NULL, *fetchArgument_param = NULL, *ctorArgs_param = NULL, pdoStatement, mode, _0, _1$$3, _2$$3, _4$$4, _5$$4;
	zend_long fetchStyle, fetchArgument, ctorArgs, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pdoStatement);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(fetchStyle, is_null_true)
		Z_PARAM_LONG(fetchArgument)
		Z_PARAM_LONG(ctorArgs)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &fetchStyle_param, &fetchArgument_param, &ctorArgs_param);
	if (!fetchStyle_param) {
		fetchStyle = 0;
	} else {
		fetchStyle = zephir_get_intval(fetchStyle_param);
	}
	if (!fetchArgument_param) {
		fetchArgument = 0;
	} else {
		fetchArgument = zephir_get_intval(fetchArgument_param);
	}
	if (!ctorArgs_param) {
		ctorArgs = 0;
	} else {
		ctorArgs = zephir_get_intval(ctorArgs_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdoStatement"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&pdoStatement, &_0);
	if (1 == 1) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_LONG(&mode, fetchStyle);
	} else {
		ZEPHIR_OBS_NVAR(&mode);
		zephir_read_property(&mode, this_ptr, ZEND_STRL("fetchMode"), PH_NOISY_CC);
	}
	if (fetchStyle == 8) {
		ZVAL_LONG(&_1$$3, fetchArgument);
		ZVAL_LONG(&_2$$3, ctorArgs);
		ZEPHIR_RETURN_CALL_METHOD(&pdoStatement, "fetchall", NULL, 0, &mode, &_1$$3, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	_3 = fetchStyle == 7;
	if (!(_3)) {
		_3 = fetchStyle == 10;
	}
	if (_3) {
		ZVAL_LONG(&_4$$4, fetchStyle);
		ZVAL_LONG(&_5$$4, fetchArgument);
		ZEPHIR_RETURN_CALL_METHOD(&pdoStatement, "fetchall", NULL, 0, &_4$$4, &_5$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_LONG(&_0, fetchStyle);
	ZEPHIR_RETURN_CALL_METHOD(&pdoStatement, "fetchall", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE
 * if there are no more rows. This method is affected by the active fetch
 * flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
 *
 *```php
 * $result = $connection->query("SELECT * FROM robots ORDER BY name");
 *
 * $result->setFetchMode(
 *     \Phalcon\Enum::FETCH_NUM
 * );
 *
 * while ($robot = result->fetchArray()) {
 *     print_r($robot);
 * }
 *```
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, fetchArray)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdoStatement"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("fetchMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "fetch", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the internal PDO result object
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, getInternalResult)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "pdoStatement");
}

/**
 * Gets number of rows returned by a resultset
 *
 *```php
 * $result = $connection->query(
 *     "SELECT * FROM robots ORDER BY name"
 * );
 *
 * echo "There are ", $result->numRows(), " rows in the resultset";
 *```
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, numRows)
{
	zend_bool _2$$3;
	zval sqlStatement, rowCount, connection, type, pdoStatement, matches, result, row, _0, _1$$3, _3$$4, _4$$5, _5$$6, _6$$6, _7$$6, _8$$7, _9$$7, _10$$7, _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement);
	ZVAL_UNDEF(&rowCount);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&pdoStatement);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("rowCount"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rowCount, &_0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&rowCount)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&connection, &_1$$3);
		ZEPHIR_CALL_METHOD(&type, &connection, "gettype", NULL, 0);
		zephir_check_call_status();
		_2$$3 = ZEPHIR_IS_STRING(&type, "mysql");
		if (!(_2$$3)) {
			_2$$3 = ZEPHIR_IS_STRING(&type, "pgsql");
		}
		if (_2$$3) {
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("pdoStatement"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&pdoStatement, &_3$$4);
			ZEPHIR_CALL_METHOD(&rowCount, &pdoStatement, "rowcount", NULL, 0);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(&rowCount)) {
			zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("sqlStatement"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&sqlStatement, &_4$$5);
			if (!(zephir_start_with_str(&sqlStatement, SL("SELECT COUNT(*) ")))) {
				ZEPHIR_INIT_VAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_INIT_VAR(&_5$$6);
				ZVAL_STRING(&_5$$6, "/^SELECT\\s+(.*)/i");
				ZEPHIR_INIT_VAR(&_6$$6);
				ZEPHIR_INIT_VAR(&_7$$6);
				ZVAL_STRING(&_7$$6, "/^SELECT\\s+(.*)/i");
				zephir_preg_match(&_6$$6, &_7$$6, &sqlStatement, &matches, 0, 0 , 0 );
				if (zephir_is_true(&_6$$6)) {
					zephir_array_fetch_long(&_8$$7, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Result/PdoResult.zep", 311);
					ZEPHIR_INIT_VAR(&_9$$7);
					ZEPHIR_CONCAT_SVS(&_9$$7, "SELECT COUNT(*) \"numrows\" FROM (SELECT ", &_8$$7, ")");
					zephir_read_property(&_10$$7, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_11$$7, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&result, &connection, "query", NULL, 0, &_9$$7, &_10$$7, &_11$$7);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&row, &result, "fetch", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&rowCount);
					zephir_array_fetch_string(&rowCount, &row, SL("numrows"), PH_NOISY, "phalcon/Db/Result/PdoResult.zep", 317);
				}
			} else {
				ZEPHIR_INIT_NVAR(&rowCount);
				ZVAL_LONG(&rowCount, 1);
			}
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("rowCount"), &rowCount);
	}
	RETURN_CCTOR(&rowCount);
}

/**
 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
 *
 *```php
 * // Return array with integer indexes
 * $result->setFetchMode(
 *     \Phalcon\Enum::FETCH_NUM
 * );
 *
 * // Return associative array without integer indexes
 * $result->setFetchMode(
 *     \Phalcon\Enum::FETCH_ASSOC
 * );
 *
 * // Return associative array together with integer indexes
 * $result->setFetchMode(
 *     \Phalcon\Enum::FETCH_BOTH
 * );
 *
 * // Return an object
 * $result->setFetchMode(
 *     \Phalcon\Enum::FETCH_OBJ
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Result_PdoResult, setFetchMode)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *fetchMode_param = NULL, *colNoOrClassNameOrObject = NULL, colNoOrClassNameOrObject_sub, *ctorargs = NULL, ctorargs_sub, __$null, pdoStatement, _0, _2$$3, _3$$3, _4$$5, _5$$5, _6$$7, _7$$7;
	zend_long fetchMode, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&colNoOrClassNameOrObject_sub);
	ZVAL_UNDEF(&ctorargs_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&pdoStatement);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_LONG(fetchMode)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(colNoOrClassNameOrObject)
		Z_PARAM_ZVAL_OR_NULL(ctorargs)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &fetchMode_param, &colNoOrClassNameOrObject, &ctorargs);
	fetchMode = zephir_get_intval(fetchMode_param);
	if (!colNoOrClassNameOrObject) {
		colNoOrClassNameOrObject = &colNoOrClassNameOrObject_sub;
		colNoOrClassNameOrObject = &__$null;
	}
	if (!ctorargs) {
		ctorargs = &ctorargs_sub;
		ctorargs = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdoStatement"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&pdoStatement, &_0);
	_1 = fetchMode == 8;
	if (!(_1)) {
		_1 = fetchMode == 9;
	}
	if (_1) {
		ZVAL_LONG(&_3$$3, fetchMode);
		ZEPHIR_CALL_METHOD(&_2$$3, &pdoStatement, "setfetchmode", NULL, 0, &_3$$3, colNoOrClassNameOrObject, ctorargs);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2$$3))) {
			RETURN_MM_BOOL(0);
		}
	} else if (fetchMode == 7) {
		ZVAL_LONG(&_5$$5, fetchMode);
		ZEPHIR_CALL_METHOD(&_4$$5, &pdoStatement, "setfetchmode", NULL, 0, &_5$$5, colNoOrClassNameOrObject);
		zephir_check_call_status();
		if (!(zephir_is_true(&_4$$5))) {
			RETURN_MM_BOOL(0);
		}
	} else {
		ZVAL_LONG(&_7$$7, fetchMode);
		ZEPHIR_CALL_METHOD(&_6$$7, &pdoStatement, "setfetchmode", NULL, 0, &_7$$7);
		zephir_check_call_status();
		if (!(zephir_is_true(&_6$$7))) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, fetchMode);
	zephir_update_property_zval(this_ptr, ZEND_STRL("fetchMode"), &_0);
	RETURN_MM_BOOL(1);
}

zend_object *zephir_init_properties_Phalcon_Db_Result_PdoResult(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindTypes"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindParams"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

