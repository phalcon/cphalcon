
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"


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
/**
 * Phalcon\Db\Result\Pdo
 *
 * Encapsulates the resultset internals
 *
 * <code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *	while ($robot = $result->fetchArray()) {
 *		print_r($robot);
 *	}
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Result_Pdo) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db\\Result, Pdo, phalcon, db_result_pdo, phalcon_db_result_pdo_method_entry, 0);

	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Active fetch mode
	 */
	zend_declare_property_long(phalcon_db_result_pdo_ce, SL("_fetchMode"), 4, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Internal resultset
	 *
	 * @var PDOStatement
	 */
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_pdoStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_result_pdo_ce, SL("_rowCount"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Db\Result\Pdo constructor
 *
 * @param Phalcon\Db\AdapterInterface connection
 * @param \PDOStatement result
 * @param string sqlStatement
 * @param array bindParams
 * @param array bindTypes
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, __construct) {

	zval *connection, *result, *sqlStatement = NULL, *bindParams = NULL, *bindTypes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &connection, &result, &sqlStatement, &bindParams, &bindTypes);

	if (!sqlStatement) {
		ZEPHIR_CPY_WRT(sqlStatement, ZEPHIR_GLOBAL(global_null));
	}
	if (!bindParams) {
		ZEPHIR_CPY_WRT(bindParams, ZEPHIR_GLOBAL(global_null));
	}
	if (!bindTypes) {
		ZEPHIR_CPY_WRT(bindTypes, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(result) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid PDOStatement supplied to Phalcon\\Db\\Result\\Pdo");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_pdoStatement"), result TSRMLS_CC);
	if ((Z_TYPE_P(sqlStatement) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_sqlStatement"), sqlStatement TSRMLS_CC);
	}
	if ((Z_TYPE_P(bindParams) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_bindParams"), bindParams TSRMLS_CC);
	}
	if ((Z_TYPE_P(bindTypes) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_bindTypes"), bindTypes TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Allows to execute the statement again. Some database systems don't support scrollable cursors,
 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, execute) {

	zval *pdoStatement;

	ZEPHIR_MM_GROW();

	pdoStatement = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	zephir_call_method(return_value, pdoStatement, "execute");
	RETURN_MM();

}

/**
 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(Phalcon\Db::FETCH_OBJ);
 *	while ($robot = $result->fetch()) {
 *		echo robot->name;
 *	}
 *</code>
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, fetch) {

	zval *pdoStatement;

	ZEPHIR_MM_GROW();

	pdoStatement = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	zephir_call_method(return_value, pdoStatement, "fetch");
	RETURN_MM();

}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *	while ($robot = result->fetchArray()) {
 *		print_r($robot);
 *	}
 *</code>
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchArray) {

	zval *pdoStatement;

	ZEPHIR_MM_GROW();

	pdoStatement = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	zephir_call_method(return_value, pdoStatement, "fetch");
	RETURN_MM();

}

/**
 * Returns an array of arrays containing all the records in the result
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$robots = $result->fetchAll();
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchAll) {

	zval *pdoStatement;

	ZEPHIR_MM_GROW();

	pdoStatement = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	zephir_call_method(return_value, pdoStatement, "fetchall");
	RETURN_MM();

}

/**
 * Gets number of rows returned by a resulset
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	echo 'There are ', $result->numRows(), ' rows in the resulset';
 *</code>
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, numRows) {

	zval *sqlStatement, *rowCount = NULL, *connection, *type, *pdoStatement, *matches, *result, *row, *_0, *_1, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(rowCount);
	zephir_read_property_this(&rowCount, this_ptr, SL("_rowCount"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(rowCount)) {
		connection = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(type);
		zephir_call_method(type, connection, "gettype");
		if ((ZEPHIR_IS_STRING(type, "pgsql") || ZEPHIR_IS_STRING(type, "mysql"))) {
			pdoStatement = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
			ZEPHIR_INIT_BNVAR(rowCount);
			zephir_call_method(rowCount, pdoStatement, "rowcount");
		}
		if (ZEPHIR_IS_FALSE(rowCount)) {
			sqlStatement = zephir_fetch_nproperty_this(this_ptr, SL("_sqlStatement"), PH_NOISY_CC);
			if (!(zephir_start_with_str(sqlStatement, SL("SELECT COUNT(*) ")))) {
				ZEPHIR_INIT_VAR(matches);
				ZVAL_NULL(matches);
				ZEPHIR_INIT_VAR(_0);
				ZVAL_STRING(_0, "/^SELECT\\s+(.*)/i", 1);
				Z_SET_ISREF_P(matches);
				ZEPHIR_INIT_VAR(_1);
				zephir_call_func_p3(_1, "preg_match", _0, sqlStatement, matches);
				if (zephir_is_true(_1)) {
					ZEPHIR_OBS_VAR(_2);
					zephir_array_fetch_long(&_2, matches, 1, PH_NOISY TSRMLS_CC);
					ZEPHIR_INIT_VAR(_3);
					ZEPHIR_CONCAT_SV(_3, "SELECT COUNT(*) \"numrows\" FROM (SELECT ", _2);
					ZEPHIR_INIT_VAR(_4);
					ZEPHIR_CONCAT_VS(_4, _3, ")");
					_5 = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
					_6 = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
					ZEPHIR_INIT_VAR(result);
					zephir_call_method_p3(result, connection, "query", _4, _5, _6);
					ZEPHIR_INIT_VAR(row);
					zephir_call_method(row, result, "fetch");
					ZEPHIR_OBS_NVAR(rowCount);
					zephir_array_fetch_string(&rowCount, row, SL("numrows"), PH_NOISY TSRMLS_CC);
				}
			} else {
				ZEPHIR_INIT_BNVAR(rowCount);
				ZVAL_LONG(rowCount, 1);
			}
		}
		zephir_update_property_this(this_ptr, SL("_rowCount"), rowCount TSRMLS_CC);
	}
	RETURN_CCTOR(rowCount);

}

/**
 * Moves internal resulset cursor to another position letting us to fetch a certain row
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->dataSeek(2); // Move to third row on result
 *	$row = $result->fetch(); // Fetch third row
 *</code>
 *
 * @param int number
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, dataSeek) {

	zval *number, *connection, *pdo, *sqlStatement, *bindParams, *statement = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	connection = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(pdo);
	zephir_call_method(pdo, connection, "getinternalhandler");
	sqlStatement = zephir_fetch_nproperty_this(this_ptr, SL("_sqlStatement"), PH_NOISY_CC);
	bindParams = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(statement);
	if ((Z_TYPE_P(bindParams) == IS_ARRAY)) {
		zephir_call_method_p1(statement, pdo, "prepare", sqlStatement);
		if ((Z_TYPE_P(statement) == IS_OBJECT)) {
			ZEPHIR_INIT_VAR(_0);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
			zephir_call_method_p3(_0, connection, "executeprepared", statement, bindParams, _1);
			ZEPHIR_CPY_WRT(statement, _0);
		}
	} else {
		zephir_call_method_p1(statement, pdo, "query", sqlStatement);
	}
	zephir_update_property_this(this_ptr, SL("_pdoStatement"), statement TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
 *
 *<code>
 *	//Return array with integer indexes
 *	$result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *
 *	//Return associative array without integer indexes
 *	$result->setFetchMode(Phalcon\Db::FETCH_ASSOC);
 *
 *	//Return associative array together with integer indexes
 *	$result->setFetchMode(Phalcon\Db::FETCH_BOTH);
 *
 *	//Return an object
 *	$result->setFetchMode(Phalcon\Db::FETCH_OBJ);
 *</code>
 *
 * @param int fetchMode
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, setFetchMode) {

	zval *fetchMode_param = NULL, *pdoStatement, *_0 = NULL, *_1;
	int fetchMode;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fetchMode_param);

		fetchMode = zephir_get_intval(fetchMode_param);


	pdoStatement = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	do {
		if ((fetchMode == 2)) {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_LONG(_0, 4);
			zephir_call_method_p1_noret(pdoStatement, "setfetchmode", _0);
			ZEPHIR_INIT_ZVAL_NREF(_1);
			ZVAL_LONG(_1, 4);
			zephir_update_property_this(this_ptr, SL("_fetchMode"), _1 TSRMLS_CC);
			break;
		}
		if ((fetchMode == 1)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 2);
			zephir_call_method_p1_noret(pdoStatement, "setfetchmode", _0);
			ZEPHIR_INIT_ZVAL_NREF(_1);
			ZVAL_LONG(_1, 2);
			zephir_update_property_this(this_ptr, SL("_fetchMode"), _1 TSRMLS_CC);
			break;
		}
		if ((fetchMode == 3)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 3);
			zephir_call_method_p1_noret(pdoStatement, "setfetchmode", _0);
			ZEPHIR_INIT_ZVAL_NREF(_1);
			ZVAL_LONG(_1, 3);
			zephir_update_property_this(this_ptr, SL("_fetchMode"), _1 TSRMLS_CC);
			break;
		}
		if ((fetchMode == 4)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 5);
			zephir_call_method_p1_noret(pdoStatement, "setfetchmode", _0);
			ZEPHIR_INIT_ZVAL_NREF(_1);
			ZVAL_LONG(_1, 5);
			zephir_update_property_this(this_ptr, SL("_fetchMode"), _1 TSRMLS_CC);
			break;
		}
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the internal PDO result object
 *
 * @return \PDOStatement
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, getInternalResult) {


	RETURN_MEMBER(this_ptr, "_pdoStatement");

}

