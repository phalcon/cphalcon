
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

#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"

/**
 * Phalcon_Db_Result_Postgresql
 *
 * Encapsulates the resultset internals
 *
 * 
 */

/**
 * Phalcon_Db_Result_Postgresql constructor
 *
 * @param resource $result
 */
PHP_METHOD(Phalcon_Db_Result_Postgresql, __construct){

	zval *result = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &result) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_resource", result);
	if (!zend_is_true(r0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid pgsql result supplied to Phalcon_Db_Result_Postgresql");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_result"), result TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon_Db_Result_Postgresql::setFetchMode
 *
 * @param resource $resultQuery
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Result_Postgresql, fetchArray){


	
}

/**
 * Gets number of rows returned by a resulset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Result_Postgresql, numRows){


	
}

/**
 * Moves internal resulset cursor to another position letting us to fetch a certain row
 *
 * @param int $number
 * @return int
 */
PHP_METHOD(Phalcon_Db_Result_Postgresql, dataSeek){


	
}

/**
 * Changes the fetching mode affecting Phalcon_Db_Postgresql::fetchArray
 *
 * @param int $fetchMode
 */
PHP_METHOD(Phalcon_Db_Result_Postgresql, setFetchMode){


	
}

/**
 * Gets the internal MySQLi result object
 *
 * @return mysqli_result
 */
PHP_METHOD(Phalcon_Db_Result_Postgresql, getInternalResult){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_result"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

