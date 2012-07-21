
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

/**
 * Phalcon\Db\Result\Mysql
 *
 * Encapsulates the resultset internals
 *
 * 
 */

/**
 * Phalcon_Db_Result_Mysql constructor
 *
 * @param object $result
 */
PHP_METHOD(Phalcon_Db_Result_Mysql, __construct){

	zval *result = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &result) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(result) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid mysql result supplied to Phalcon_Db_Result_Mysql");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_result"), result TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon_Db_Result_Mysql::setFetchMode
 *
 * @param resource $resultQuery
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Result_Mysql, fetchArray){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_result"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_fetchMode"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysqli_fetch_array", t0, t1);
	RETURN_CTOR(r0);
}

/**
 * Gets number of rows returned by a resulset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Result_Mysql, numRows){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_result"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysqli_num_rows", t0);
	RETURN_CTOR(r0);
}

/**
 * Moves internal resulset cursor to another position letting us to fetch a certain row
 *
 * @param int $number
 * @return int
 */
PHP_METHOD(Phalcon_Db_Result_Mysql, dataSeek){

	zval *number = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_result"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysqli_data_seek", t0, number);
	RETURN_CTOR(r0);
}

/**
 * Changes the fetching mode affecting Phalcon_Db_Mysql::fetchArray
 *
 * @param int $fetchMode
 */
PHP_METHOD(Phalcon_Db_Result_Mysql, setFetchMode){

	zval *fetch_mode = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &fetch_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, fetch_mode, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		phalcon_update_property_zval(this_ptr, SL("_fetchMode"), t1 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 2);
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_equal_function(r1, fetch_mode, t2 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(t3);
			ZVAL_LONG(t3, 3);
			phalcon_update_property_zval(this_ptr, SL("_fetchMode"), t3 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t4);
			ZVAL_LONG(t4, 3);
			PHALCON_ALLOC_ZVAL_MM(r2);
			is_equal_function(r2, fetch_mode, t4 TSRMLS_CC);
			if (zend_is_true(r2)) {
				PHALCON_INIT_VAR(t5);
				ZVAL_LONG(t5, 2);
				phalcon_update_property_zval(this_ptr, SL("_fetchMode"), t5 TSRMLS_CC);
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets the internal MySQLi result object
 *
 * @return mysqli_result
 */
PHP_METHOD(Phalcon_Db_Result_Mysql, getInternalResult){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_result"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

