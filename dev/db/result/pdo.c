
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

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
 * @param PDOStatement $result
 */
PHP_METHOD(Phalcon_Db_Result_Pdo, __construct){

	zval *result = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &result) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(result) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid PDOStatement supplied to Phalcon\\Db\\Result\\Pdo");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_pdoStatement"), result TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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

	zval *pdo_statement = NULL, *row_count = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(row_count);
	PHALCON_CALL_METHOD(row_count, pdo_statement, "rowcount", PH_NO_CHECK);
	
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

	zval *number = NULL, *n = NULL, *pdo_statement = NULL, *result = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(number);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, -1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(n, r0);
	decrement_function(number);
	
	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_NORETURN(pdo_statement, "execute", PH_NO_CHECK);
	ws_a5eb_0:
		
		PHALCON_INIT_VAR(r1);
		is_not_equal_function(r1, n, number TSRMLS_CC);
		if (!zend_is_true(r1)) {
			goto we_a5eb_0;
		}
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_METHOD(result, pdo_statement, "fetch", PH_NO_CHECK);
		if (Z_TYPE_P(result) != IS_ARRAY) { 
			PHALCON_MM_RESTORE();
			RETURN_NULL();
		}
		
		PHALCON_SEPARATE(n);
		increment_function(n);
		goto ws_a5eb_0;
	we_a5eb_0:
	if(0){}
	
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

	zval *fetch_mode = NULL, *pdo_statement = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &fetch_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(pdo_statement);
	phalcon_read_property(&pdo_statement, this_ptr, SL("_pdoStatement"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(fetch_mode, 1 TSRMLS_CC)) {
		PHALCON_INIT_VAR(c0);
		ZVAL_LONG(c0, 2);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(pdo_statement, "setfetchmode", c0, PH_NO_CHECK);
		phalcon_update_property_long(this_ptr, SL("_fetchMode"), 2 TSRMLS_CC);
	} else {
		if (phalcon_compare_strict_long(fetch_mode, 2 TSRMLS_CC)) {
			PHALCON_INIT_VAR(c1);
			ZVAL_LONG(c1, 4);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(pdo_statement, "setfetchmode", c1, PH_NO_CHECK);
			phalcon_update_property_long(this_ptr, SL("_fetchMode"), 4 TSRMLS_CC);
		} else {
			if (phalcon_compare_strict_long(fetch_mode, 3 TSRMLS_CC)) {
				PHALCON_INIT_VAR(c2);
				ZVAL_LONG(c2, 3);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(pdo_statement, "setfetchmode", c2, PH_NO_CHECK);
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

