
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "ext/pdo/php_pdo_driver.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\Db\Result\Pdo
 *
 * Encapsulates the resultset internals
 *
 * <code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *	while($robot = $result->fetchArray()){
 *		print_r($robot);
 *	}
 * </code>
 */


/**
 * Phalcon\Db\Result\Pdo constructor
 *
 * @param Phalcon\Db\Adapter\Pdo $connection
 * @param string $sqlStatement
 * @param array $bindParams
 * @param array $bindTypes
 * @param PDOStatement $result
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, __construct){

	zval *connection = NULL, *result = NULL, *sql_statement = NULL, *bind_params = NULL;
	zval *bind_types = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zzz", &connection, &result, &sql_statement, &bind_params, &bind_types) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!sql_statement) {
		PHALCON_ALLOC_ZVAL_MM(sql_statement);
		ZVAL_NULL(sql_statement);
	}
	
	if (!bind_params) {
		PHALCON_ALLOC_ZVAL_MM(bind_params);
		ZVAL_NULL(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_ALLOC_ZVAL_MM(bind_types);
		ZVAL_NULL(bind_types);
	}
	
	if (Z_TYPE_P(result) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid PDOStatement supplied to Phalcon\\Db\\Result\\Pdo");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_pdoStatement"), result TSRMLS_CC);
	if (Z_TYPE_P(sql_statement) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
	}
	
	if (Z_TYPE_P(bind_params) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_bindParams"), bind_params TSRMLS_CC);
	}
	
	if (Z_TYPE_P(bind_types) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_bindTypes"), bind_types TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Allows to executes the statement again. Some database systems don't support scrollable cursors,
 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, execute){

	zval *pdo_statement = NULL, *status = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD(status, pdo_statement, "execute", PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *	while($robot = $result->fetchArray()){
 *		print_r($robot);
 *	}
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchArray){

	zval *pdo_statement = NULL, *row = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(row);
	PHALCON_CALL_METHOD(row, pdo_statement, "fetch", PH_NO_CHECK);
	
	RETURN_CCTOR(row);
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
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchAll){

	zval *pdo_statement = NULL, *rows = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(rows);
	PHALCON_CALL_METHOD(rows, pdo_statement, "fetchall", PH_NO_CHECK);
	
	RETURN_CCTOR(rows);
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
PHP_METHOD(Phalcon_Db_Result_Pdo, numRows){

	zval *row_count = NULL, *connection = NULL, *type = NULL, *sql_statement = NULL;
	zval *bind_params = NULL, *bind_types = NULL, *matches = NULL, *pattern = NULL;
	zval *match = NULL, *else_clauses = NULL, *sql = NULL, *fetch_num = NULL, *result = NULL;
	zval *row = NULL, *pdo_statement = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(row_count);
	phalcon_read_property(&row_count, this_ptr, SL("_rowCount"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(row_count)) {
		PHALCON_INIT_VAR(connection);
		phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(type);
		PHALCON_CALL_METHOD(type, connection, "gettype", PH_NO_CHECK);
		if (PHALCON_COMPARE_STRING(type, "sqlite")) {
			PHALCON_INIT_VAR(sql_statement);
			phalcon_read_property(&sql_statement, this_ptr, SL("_sqlStatement"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(bind_params);
			phalcon_read_property(&bind_params, this_ptr, SL("_bindParams"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(bind_types);
			phalcon_read_property(&bind_types, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(matches);
			ZVAL_NULL(matches);
			
			PHALCON_INIT_VAR(pattern);
			ZVAL_STRING(pattern, "/^SELECT\\s+(.*)$/i", 1);
			Z_SET_ISREF_P(matches);
			
			PHALCON_INIT_VAR(match);
			PHALCON_CALL_FUNC_PARAMS_3(match, "preg_match", pattern, sql_statement, matches);
			Z_UNSET_ISREF_P(matches);
			if (zend_is_true(match)) {
				PHALCON_INIT_VAR(else_clauses);
				phalcon_array_fetch_long(&else_clauses, matches, 1, PH_NOISY_CC);
				
				PHALCON_INIT_VAR(sql);
				PHALCON_CONCAT_SVS(sql, "SELECT COUNT(*) FROM (SELECT ", else_clauses, ")");
				
				PHALCON_INIT_VAR(fetch_num);
				ZVAL_LONG(fetch_num, 3);
				
				PHALCON_INIT_VAR(result);
				PHALCON_CALL_METHOD_PARAMS_3(result, connection, "query", sql, bind_params, bind_types, PH_NO_CHECK);
				
				PHALCON_INIT_VAR(row);
				PHALCON_CALL_METHOD(row, result, "fetcharray", PH_NO_CHECK);
				
				PHALCON_INIT_VAR(row_count);
				phalcon_array_fetch_long(&row_count, row, 0, PH_NOISY_CC);
			}
		} else {
			PHALCON_INIT_VAR(pdo_statement);
			phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(row_count);
			PHALCON_CALL_METHOD(row_count, pdo_statement, "rowcount", PH_NO_CHECK);
		}
		
		phalcon_update_property_zval(this_ptr, SL("_rowCount"), row_count TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(row_count);
}

/**
 * Moves internal resulset cursor to another position letting us to fetch a certain row
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->dataSeek(2); // Move to third row on result
 *	$row = $result->fetchArray(); // Fetch third row
 *</code>
 *
 * @param int $number
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, dataSeek){

	long number = 0, n;
	zval *pdo_statement = NULL;
	pdo_stmt_t *stmt;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);

	stmt = (pdo_stmt_t*) zend_object_store_get_object(pdo_statement TSRMLS_CC);
	if (!stmt->dbh) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}

	if (!stmt->methods->executer(stmt TSRMLS_CC)) {
		stmt->executed = 1;
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}

	n = -1;
	number--;
	while (n != number) {

		if(!stmt->methods->fetcher(stmt, PDO_FETCH_ORI_NEXT, 0 TSRMLS_CC)) {
			PHALCON_MM_RESTORE();
			RETURN_NULL();
		}

		n++;
	}

	PHALCON_MM_RESTORE();
}

/**
 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetchArray
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
 *</code>
 *
 * @param int $fetchMode
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, setFetchMode){

	long fetch_mode;
	zval *pdo_statement = NULL, *fetch_type = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &fetch_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(fetch_type);

	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	if (fetch_mode == 1) {
		ZVAL_LONG(fetch_type, 2);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(pdo_statement, "setfetchmode", fetch_type, PH_NO_CHECK);
		phalcon_update_property_long(this_ptr, SL("_fetchMode"), 2 TSRMLS_CC);
	} else {
		if (fetch_mode == 2) {
			ZVAL_LONG(fetch_type, 4);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(pdo_statement, "setfetchmode", fetch_type, PH_NO_CHECK);
			phalcon_update_property_long(this_ptr, SL("_fetchMode"), 4 TSRMLS_CC);
		} else {
			if (fetch_mode == 3) {
				ZVAL_LONG(fetch_type, 3);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(pdo_statement, "setfetchmode", fetch_type, PH_NO_CHECK);
				phalcon_update_property_long(this_ptr, SL("_fetchMode"), 3 TSRMLS_CC);
			}
		}
	}

	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets the internal PDO result object
 *
 * @return PDOStatement
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, getInternalResult){

	zval *pdo_statement = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	
	RETURN_CCTOR(pdo_statement);
}

