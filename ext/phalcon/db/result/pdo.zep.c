
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"

#include <ext/pdo/php_pdo_driver.h>



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
	zend_declare_property_long(phalcon_db_result_pdo_ce, SL("_fetchMode"), 5, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Internal resultset
	 *
	 * @var \PDOStatement
	 */
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_pdoStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_db_result_pdo_ce, SL("_rowCount"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_result_pdo_ce TSRMLS_CC, 1, phalcon_db_resultinterface_ce);
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

	zephir_fetch_params(0, 2, 3, &connection, &result, &sqlStatement, &bindParams, &bindTypes);

	if (!sqlStatement) {
		sqlStatement = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindParams) {
		bindParams = ZEPHIR_GLOBAL(global_null);
	}
	if (!bindTypes) {
		bindTypes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_pdoStatement"), result TSRMLS_CC);
	if (Z_TYPE_P(sqlStatement) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_sqlStatement"), sqlStatement TSRMLS_CC);
	}
	if (Z_TYPE_P(bindParams) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_bindParams"), bindParams TSRMLS_CC);
	}
	if (Z_TYPE_P(bindTypes) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_bindTypes"), bindTypes TSRMLS_CC);
	}

}

/**
 * Allows to execute the statement again. Some database systems don't support scrollable cursors,
 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, execute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "execute", NULL, 0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetch", NULL, 0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetch", NULL, 0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetchall", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets number of rows returned by a resultset
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	echo 'There are ', $result->numRows(), ' rows in the resultset';
 *</code>
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, numRows) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement, *rowCount = NULL, *connection, *type = NULL, *pdoStatement, *matches, *result = NULL, *row = NULL, *_1, _2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(rowCount);
	zephir_read_property_this(&rowCount, this_ptr, SL("_rowCount"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(rowCount)) {
		ZEPHIR_OBS_VAR(connection);
		zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&type, connection, "gettype", NULL, 0);
		zephir_check_call_status();
		_0 = ZEPHIR_IS_STRING(type, "mysql");
		if (!(_0)) {
			_0 = ZEPHIR_IS_STRING(type, "pgsql");
		}
		if (_0) {
			ZEPHIR_OBS_VAR(pdoStatement);
			zephir_read_property_this(&pdoStatement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&rowCount, pdoStatement, "rowcount", NULL, 0);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(rowCount)) {
			ZEPHIR_OBS_VAR(sqlStatement);
			zephir_read_property_this(&sqlStatement, this_ptr, SL("_sqlStatement"), PH_NOISY_CC);
			if (!(zephir_start_with_str(sqlStatement, SL("SELECT COUNT(*) ")))) {
				ZEPHIR_INIT_VAR(matches);
				ZVAL_NULL(matches);
				ZEPHIR_INIT_VAR(_1);
				ZEPHIR_SINIT_VAR(_2);
				ZVAL_STRING(&_2, "/^SELECT\\s+(.*)/i", 0);
				zephir_preg_match(_1, &_2, sqlStatement, matches, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(_1)) {
					zephir_array_fetch_long(&_3, matches, 1, PH_NOISY | PH_READONLY, "phalcon/db/result/pdo.zep", 202 TSRMLS_CC);
					ZEPHIR_INIT_VAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "SELECT COUNT(*) \"numrows\" FROM (SELECT ", _3, ")");
					_5 = zephir_fetch_nproperty_this(this_ptr, SL("_bindParams"), PH_NOISY_CC);
					_6 = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&result, connection, "query", NULL, 0, _4, _5, _6);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&row, result, "fetch", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(rowCount);
					zephir_array_fetch_string(&rowCount, row, SL("numrows"), PH_NOISY, "phalcon/db/result/pdo.zep", 204 TSRMLS_CC);
				}
			} else {
				ZEPHIR_INIT_NVAR(rowCount);
				ZVAL_LONG(rowCount, 1);
			}
		}
		zephir_update_property_this(this_ptr, SL("_rowCount"), rowCount TSRMLS_CC);
	}
	RETURN_CCTOR(rowCount);

}

/**
 * Moves internal resultset cursor to another position letting us to fetch a certain row
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->dataSeek(2); // Move to third row on result
 *	$row = $result->fetch(); // Fetch third row
 *</code>
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, dataSeek) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *number_param = NULL, *connection, *pdo = NULL, *sqlStatement, *bindParams, *statement = NULL, *_0 = NULL, *_1;
	long number;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number_param);

	number = zephir_get_intval(number_param);


	 { pdo_stmt_t *stmt; long n; 
	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&pdo, connection, "getinternalhandler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(sqlStatement);
	zephir_read_property_this(&sqlStatement, this_ptr, SL("_sqlStatement"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(bindParams);
	zephir_read_property_this(&bindParams, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&statement, pdo, "prepare", NULL, 0, sqlStatement);
		zephir_check_call_status();
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_bindTypes"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_0, connection, "executeprepared", NULL, 0, statement, bindParams, _1);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(statement, _0);
		}
	} else {
		ZEPHIR_CALL_METHOD(&statement, pdo, "query", NULL, 0, sqlStatement);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_pdoStatement"), statement TSRMLS_CC);
	

		/**
		 * This a fetch scroll to reach the desired position, however with a big number of records
		 * maybe it may be very slow
		 */
		stmt = (pdo_stmt_t*) zend_object_store_get_object(statement TSRMLS_CC);
		if (!stmt->dbh) {
			ZEPHIR_MM_RESTORE();
			RETURN_FALSE;
		}

		n = -1;
		number--;
		while (n != number) {

			if (!stmt->methods->fetcher(stmt, PDO_FETCH_ORI_NEXT, 0 TSRMLS_CC)) {
				ZEPHIR_MM_RESTORE();
				RETURN_NULL();
			}

			n++;
		}

		}

		
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
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, setFetchMode) {

	zval *fetchMode_param = NULL, *pdoStatement, *_0 = NULL, *_1, *_2;
	int fetchMode, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fetchMode_param);

	fetchMode = zephir_get_intval(fetchMode_param);


	ZEPHIR_OBS_VAR(pdoStatement);
	zephir_read_property_this(&pdoStatement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, fetchMode);
	ZEPHIR_CALL_METHOD(&_0, pdoStatement, "setfetchmode", NULL, 0, _1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_ZVAL_NREF(_2);
		ZVAL_LONG(_2, fetchMode);
		zephir_update_property_this(this_ptr, SL("_fetchMode"), _2 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the internal PDO result object
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, getInternalResult) {


	RETURN_MEMBER(this_ptr, "_pdoStatement");

}

