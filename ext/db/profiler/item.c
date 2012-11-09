
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

#include "kernel/object.h"

/**
 * Phalcon\Db\Profiler\Item
 *
 * This class identifies each profile in a Phalcon\Db\Profiler
 *
 */


/**
 * Phalcon\Db\Profiler\Item initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Profiler_Item){

	PHALCON_REGISTER_CLASS(Phalcon\\Db\\Profiler, Item, db_profiler_item, phalcon_db_profiler_item_method_entry, 0);

	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_initialTime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_finalTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Sets the SQL statement related to the profile
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLStatement){

	zval *sql_statement;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_sqlStatement"), sql_statement TSRMLS_CC);
	
}

/**
 * Returns the SQL statement related to the profile
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLStatement){

	zval *sql_statement;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(sql_statement);
	phalcon_read_property(&sql_statement, this_ptr, SL("_sqlStatement"), PH_NOISY_CC);
	
	RETURN_CCTOR(sql_statement);
}

/**
 * Sets the timestamp on when the profile started
 *
 * @param int $initialTime
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime){

	zval *initial_time;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &initial_time) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_initialTime"), initial_time TSRMLS_CC);
	
}

/**
 * Sets the timestamp on when the profile ended
 *
 * @param int $finalTime
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime){

	zval *final_time;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &final_time) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_finalTime"), final_time TSRMLS_CC);
	
}

/**
 * Returns the initial time in milseconds on when the profile started
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime){

	zval *initial_time;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(initial_time);
	phalcon_read_property(&initial_time, this_ptr, SL("_initialTime"), PH_NOISY_CC);
	
	RETURN_CCTOR(initial_time);
}

/**
 * Returns the initial time in milseconds on when the profile ended
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime){

	zval *final_time;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(final_time);
	phalcon_read_property(&final_time, this_ptr, SL("_finalTime"), PH_NOISY_CC);
	
	RETURN_CCTOR(final_time);
}

/**
 * Returns the total time in seconds spent by the profile
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds){

	zval *final_time, *initial_time, *elapsed;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(final_time);
	phalcon_read_property(&final_time, this_ptr, SL("_finalTime"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(initial_time);
	phalcon_read_property(&initial_time, this_ptr, SL("_initialTime"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(elapsed);
	sub_function(elapsed, final_time, initial_time TSRMLS_CC);
	
	RETURN_CTOR(elapsed);
}

