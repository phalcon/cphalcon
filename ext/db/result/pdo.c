
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
#include "kernel/string.h"
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
 *	while ($robot = $result->fetchArray()) {
 *		print_r($robot);
 *	}
 * </code>
 */


/**
 * Phalcon\Db\Result\Pdo initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Result_Pdo){

	PHALCON_REGISTER_CLASS(Phalcon\\Db\\Result, Pdo, db_result_pdo, phalcon_db_result_pdo_method_entry, 0);

	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_result_pdo_ce, SL("_fetchMode"), 4, ZEND_ACC_PROTECTED TSRMLS_CC);
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
 * @param Phalcon\Db\AdapterInterface $connection
 * @param string $sqlStatement
 * @param array $bindParams
 * @param array $bindTypes
 * @param \PDOStatement $result
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, __construct){

	zval *connection, *result, *sql_statement = NULL, *bind_params = NULL;
	zval *bind_types = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 3, &connection, &result, &sql_statement, &bind_params, &bind_types);
	
	if (!sql_statement) {
		sql_statement = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_params) {
		bind_params = PHALCON_GLOBAL(z_null);
	}
	
	if (!bind_types) {
		bind_types = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(result) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid PDOStatement supplied to Phalcon\\Db\\Result\\Pdo");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_pdoStatement"), result TSRMLS_CC);
	if (Z_TYPE_P(sql_statement) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
	}
	
	if (Z_TYPE_P(bind_params) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_bindParams"), bind_params TSRMLS_CC);
	}
	
	if (Z_TYPE_P(bind_types) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_bindTypes"), bind_types TSRMLS_CC);
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

	zval *pdo_statement;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(pdo_statement);
	phalcon_read_property_this(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	phalcon_call_method(return_value, pdo_statement, "execute");
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
 *		echo $robot->name;
 *	}
 *</code>
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, fetch){

	zval *pdo_statement;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(pdo_statement);
	phalcon_read_property_this(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	phalcon_call_method(return_value, pdo_statement, "fetch");
	RETURN_MM();
}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 *<code>
 *	$result = $connection->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *	while ($robot = $result->fetchArray()) {
 *		print_r($robot);
 *	}
 *</code>
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchArray){

	zval *pdo_statement;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(pdo_statement);
	phalcon_read_property_this(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	phalcon_call_method(return_value, pdo_statement, "fetch");
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
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchAll){

	zval *pdo_statement;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(pdo_statement);
	phalcon_read_property_this(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	phalcon_call_method(return_value, pdo_statement, "fetchall");
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
PHP_METHOD(Phalcon_Db_Result_Pdo, numRows){

	zval *row_count = NULL, *connection, *type, *pdo_statement = NULL;
	zval *sql_statement, *bind_params, *bind_types;
	zval *matches, *pattern, *match, *else_clauses;
	zval *sql, *result, *row;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(row_count);
	phalcon_read_property_this(&row_count, this_ptr, SL("_rowCount"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(row_count)) {
	
		PHALCON_OBS_VAR(connection);
		phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(type);
		phalcon_call_method(type, connection, "gettype");
	
		/** 
		 * MySQL library property returns the number of records
		 */
		if (PHALCON_IS_STRING(type, "mysql")) {
			PHALCON_OBS_VAR(pdo_statement);
			phalcon_read_property_this(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(row_count);
			phalcon_call_method(row_count, pdo_statement, "rowcount");
		}
	
		/** 
		 * PostgreSQL too
		 */
		if (PHALCON_IS_STRING(type, "pgsql")) {
			PHALCON_OBS_NVAR(pdo_statement);
			phalcon_read_property_this(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(row_count);
			phalcon_call_method(row_count, pdo_statement, "rowcount");
		}
	
		/** 
		 * We should get the count using a new statement :(
		 */
		if (PHALCON_IS_FALSE(row_count)) {
	
			/** 
			 * SQLite/Oracle/SQLServer returns resultsets that to the client eyes (PDO) has an
			 * arbitrary number of rows, so we need to perform an extra count to know that
			 */
			PHALCON_OBS_VAR(sql_statement);
			phalcon_read_property_this(&sql_statement, this_ptr, SL("_sqlStatement"), PH_NOISY_CC);
	
			/** 
			 * If the sql_statement starts with SELECT COUNT(*) we don't make the count
			 */
			if (!phalcon_start_with_str(sql_statement, SL("SELECT COUNT(*) "))) {
	
				PHALCON_OBS_VAR(bind_params);
				phalcon_read_property_this(&bind_params, this_ptr, SL("_bindParams"), PH_NOISY_CC);
	
				PHALCON_OBS_VAR(bind_types);
				phalcon_read_property_this(&bind_types, this_ptr, SL("_bindTypes"), PH_NOISY_CC);
	
				PHALCON_INIT_VAR(matches);
	
				PHALCON_INIT_VAR(pattern);
				ZVAL_STRING(pattern, "/^SELECT\\s+(.*)$/i", 1);
	
				PHALCON_INIT_VAR(match);
				phalcon_preg_match(match, NULL, pattern, sql_statement, matches TSRMLS_CC);
	
				if (zend_is_true(match)) {
					PHALCON_OBS_VAR(else_clauses);
					phalcon_array_fetch_long(&else_clauses, matches, 1, PH_NOISY);
	
					PHALCON_INIT_VAR(sql);
					PHALCON_CONCAT_SVS(sql, "SELECT COUNT(*) \"numrows\" FROM (SELECT ", else_clauses, ")");
	
					PHALCON_INIT_VAR(result);
					phalcon_call_method_p3(result, connection, "query", sql, bind_params, bind_types);
	
					PHALCON_INIT_VAR(row);
					phalcon_call_method(row, result, "fetch");
	
					PHALCON_OBS_NVAR(row_count);
					phalcon_array_fetch_string(&row_count, row, SL("numrows"), PH_NOISY);
				}
			} else {
				PHALCON_INIT_NVAR(row_count);
				ZVAL_LONG(row_count, 1);
			}
		}
	
		/** 
		 * Update the value to avoid further calculations
		 */
		phalcon_update_property_this(this_ptr, SL("_rowCount"), row_count TSRMLS_CC);
	}
	
	RETURN_CCTOR(row_count);
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
 * @param int $number
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, dataSeek){

	long number = 0, n;
	zval *connection, *pdo, *sql_statement;
	zval *bind_params, *bind_types, *statement = NULL;
	zval *temp_statement = NULL;
	pdo_stmt_t *stmt;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &number) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);

	PHALCON_INIT_VAR(pdo);
	phalcon_call_method(pdo, connection, "getinternalhandler");

	PHALCON_OBS_VAR(sql_statement);
	phalcon_read_property(&sql_statement, this_ptr, SL("_sqlStatement"), PH_NOISY_CC);

	PHALCON_OBS_VAR(bind_params);
	phalcon_read_property(&bind_params, this_ptr, SL("_bindParams"), PH_NOISY_CC);

	/**
	 * PDO doesn't support scrollable cursors, so we need to re-execute the statement again
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) {

		PHALCON_OBS_VAR(bind_types);
		phalcon_read_property(&bind_types, this_ptr, SL("_bindTypes"), PH_NOISY_CC);

		PHALCON_INIT_VAR(statement);
		phalcon_call_method_p1(statement, pdo, "prepare", sql_statement);
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			PHALCON_INIT_VAR(temp_statement);
			phalcon_call_method_p3(temp_statement, connection, "executeprepared", statement, bind_params, bind_types);
			PHALCON_CPY_WRT(statement, temp_statement);
		}

	} else {
		PHALCON_INIT_NVAR(statement);
		phalcon_call_method_p1(statement, pdo, "query", sql_statement);
	}

	phalcon_update_property_zval(this_ptr, SL("_pdoStatement"), statement TSRMLS_CC);

	/**
	 * This a fetch scroll to reach the desired position, however with a big number of records
	 * maybe it may be very slow
	 */

	stmt = (pdo_stmt_t*) zend_object_store_get_object(statement TSRMLS_CC);
	if (!stmt->dbh) {
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
 * @param int $fetchMode
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, setFetchMode){


	long fetch_mode;
	zval *pdo_statement, *fetch_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &fetch_mode) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(fetch_type);

	PHALCON_OBS_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	if (fetch_mode == 1) {
		ZVAL_LONG(fetch_type, 2);
	} else if (fetch_mode == 2) {
		ZVAL_LONG(fetch_type, 4);
	} else if (fetch_mode == 3) {
		ZVAL_LONG(fetch_type, 3);
	} else if (fetch_mode == 4) {
		ZVAL_LONG(fetch_type, 5);
	} else {
		ZVAL_LONG(fetch_type, 0);
	}

	if (Z_LVAL_P(fetch_type) != 0) {
		phalcon_call_method_p1_noret(pdo_statement, "setfetchmode", fetch_type);
		phalcon_update_property_long(this_ptr, SL("_fetchMode"), Z_LVAL_P(fetch_type) TSRMLS_CC);
	}

	RETURN_MM_NULL();
}

/**
 * Gets the internal PDO result object
 *
 * @return \PDOStatement
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, getInternalResult){


	RETURN_MEMBER(this_ptr, "_pdoStatement");
}

