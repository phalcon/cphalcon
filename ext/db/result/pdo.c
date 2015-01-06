
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

#include "db/result/pdo.h"
#include "db/resultinterface.h"
#include "db/exception.h"

#include <ext/pdo/php_pdo_driver.h>

#include "kernel/main.h"
#include "kernel/memory.h"
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
zend_class_entry *phalcon_db_result_pdo_ce;

PHP_METHOD(Phalcon_Db_Result_Pdo, __construct);
PHP_METHOD(Phalcon_Db_Result_Pdo, execute);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetch);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchArray);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchAll);
PHP_METHOD(Phalcon_Db_Result_Pdo, numRows);
PHP_METHOD(Phalcon_Db_Result_Pdo, dataSeek);
PHP_METHOD(Phalcon_Db_Result_Pdo, setFetchMode);
PHP_METHOD(Phalcon_Db_Result_Pdo, getInternalResult);
PHP_METHOD(Phalcon_Db_Result_Pdo, nextRowset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_db_result_pdo_method_entry[] = {
	PHP_ME(Phalcon_Db_Result_Pdo, __construct, arginfo_phalcon_db_result___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Result_Pdo, execute, arginfo_phalcon_db_resultinterface_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetch, arginfo_phalcon_db_resultinterface_fetch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetchArray, arginfo_phalcon_db_resultinterface_fetcharray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetchAll, arginfo_phalcon_db_resultinterface_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, numRows, arginfo_phalcon_db_resultinterface_numrows, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, dataSeek, arginfo_phalcon_db_resultinterface_dataseek, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, setFetchMode, arginfo_phalcon_db_resultinterface_setfetchmode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, getInternalResult, arginfo_phalcon_db_resultinterface_getinternalresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, nextRowset, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Db\Result\Pdo initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Result_Pdo){

	PHALCON_REGISTER_CLASS(Phalcon\\Db\\Result, Pdo, db_result_pdo, phalcon_db_result_pdo_method_entry, 0);

	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_result_pdo_ce, SL("_fetchMode"), PDO_FETCH_OBJ, ZEND_ACC_PROTECTED TSRMLS_CC);
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

	phalcon_fetch_params(0, 2, 3, &connection, &result, &sql_statement, &bind_params, &bind_types);
	
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
		PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Invalid PDOStatement supplied to Phalcon\\Db\\Result\\Pdo");
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

	pdo_statement = phalcon_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(pdo_statement, "execute");
	PHALCON_MM_RESTORE();
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

	pdo_statement = phalcon_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(pdo_statement, "fetch");
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

	pdo_statement = phalcon_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(pdo_statement, "fetch");
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

	pdo_statement = phalcon_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(pdo_statement, "fetchall");
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

	zval *row_count = NULL, *connection, *type = NULL, *pdo_statement = NULL;
	zval *sql_statement, *bind_params, *bind_types;
	zval *matches, *pattern, *match, *else_clauses;
	zval *sql, *result = NULL, *row = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(row_count);
	phalcon_read_property_this(&row_count, this_ptr, SL("_rowCount"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_FALSE(row_count)) {
	
		PHALCON_OBS_VAR(connection);
		phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	
		PHALCON_CALL_METHOD(&type, connection, "gettype");
	
		/** 
		 * MySQL/PostgreSQL library property returns the number of records
		 */
		if (PHALCON_IS_STRING(type, "mysql") || PHALCON_IS_STRING(type, "pgsql")) {
			PHALCON_OBS_VAR(pdo_statement);
			phalcon_read_property_this(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY TSRMLS_CC);
	
			PHALCON_CALL_METHOD(&row_count, pdo_statement, "rowcount");
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
			phalcon_read_property_this(&sql_statement, this_ptr, SL("_sqlStatement"), PH_NOISY TSRMLS_CC);
	
			/** 
			 * If the sql_statement starts with SELECT COUNT(*) we don't make the count
			 */
			if (!phalcon_start_with_str(sql_statement, SL("SELECT COUNT(*) "))) {
	
				PHALCON_OBS_VAR(bind_params);
				phalcon_read_property_this(&bind_params, this_ptr, SL("_bindParams"), PH_NOISY TSRMLS_CC);
	
				PHALCON_OBS_VAR(bind_types);
				phalcon_read_property_this(&bind_types, this_ptr, SL("_bindTypes"), PH_NOISY TSRMLS_CC);
	
				PHALCON_INIT_VAR(matches);
	
				PHALCON_INIT_VAR(pattern);
				ZVAL_STRING(pattern, "/^SELECT\\s+(.*)$/i", 1);
	
				PHALCON_INIT_VAR(match);
				RETURN_MM_ON_FAILURE(phalcon_preg_match(match, pattern, sql_statement, matches TSRMLS_CC));
	
				if (zend_is_true(match)) {
					PHALCON_OBS_VAR(else_clauses);
					phalcon_array_fetch_long(&else_clauses, matches, 1, PH_NOISY);
	
					PHALCON_INIT_VAR(sql);
					PHALCON_CONCAT_SVS(sql, "SELECT COUNT(*) \"numrows\" FROM (SELECT ", else_clauses, ")");
	
					PHALCON_CALL_METHOD(&result, connection, "query", sql, bind_params, bind_types);
					PHALCON_CALL_METHOD(&row, result, "fetch");
	
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
	zval *connection, *pdo = NULL, *sql_statement;
	zval *bind_params, *bind_types, *statement = NULL;
	zval *temp_statement = NULL;
	pdo_stmt_t *stmt;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &number) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&pdo, connection, "getinternalhandler");

	PHALCON_OBS_VAR(sql_statement);
	phalcon_read_property(&sql_statement, this_ptr, SL("_sqlStatement"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(bind_params);
	phalcon_read_property(&bind_params, this_ptr, SL("_bindParams"), PH_NOISY TSRMLS_CC);

	/**
	 * PDO doesn't support scrollable cursors, so we need to re-execute the statement again
	 */
	if (Z_TYPE_P(bind_params) == IS_ARRAY) {

		PHALCON_OBS_VAR(bind_types);
		phalcon_read_property(&bind_types, this_ptr, SL("_bindTypes"), PH_NOISY TSRMLS_CC);

		PHALCON_CALL_METHOD(&statement, pdo, "prepare", sql_statement);
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			PHALCON_CALL_METHOD(&temp_statement, connection, "executeprepared", statement, bind_params, bind_types);
			PHALCON_CPY_WRT(statement, temp_statement);
		}

	} else {
		PHALCON_CALL_METHOD(&statement, pdo, "query", sql_statement);
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

	zval *fetch_mode, *fetch_arg1 = NULL, *fetch_arg2 = NULL;
	zval *pdo_statement;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &fetch_mode, &fetch_arg1, &fetch_arg2);

	PHALCON_SEPARATE_PARAM(fetch_mode);
	if (Z_TYPE_P(fetch_mode) != IS_LONG) {
		convert_to_long(fetch_mode);
	}

	PHALCON_OBS_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY TSRMLS_CC);

	if (Z_LVAL_P(fetch_mode) != 0) {
		if (fetch_arg1 && fetch_arg2) {
			PHALCON_CALL_METHOD(NULL, pdo_statement, "setfetchmode", fetch_mode, fetch_arg1, fetch_arg2);
		} else if (fetch_arg1) {
			PHALCON_CALL_METHOD(NULL, pdo_statement, "setfetchmode", fetch_mode, fetch_arg1);
		} else if (fetch_arg2) {
			PHALCON_CALL_METHOD(NULL, pdo_statement, "setfetchmode", fetch_mode, fetch_arg2);
		} else {
			PHALCON_CALL_METHOD(NULL, pdo_statement, "setfetchmode", fetch_mode);
		}
		
		phalcon_update_property_long(this_ptr, SL("_fetchMode"), Z_LVAL_P(fetch_mode) TSRMLS_CC);
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

/**
 * Advances to the next rowset in a multi-rowset statement handle
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, nextRowset){

	zval *pdo_statement;

	PHALCON_MM_GROW();

	pdo_statement = phalcon_fetch_nproperty_this(this_ptr, SL("_pdoStatement"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(pdo_statement, "nextrowset");

	RETURN_MM();
}
