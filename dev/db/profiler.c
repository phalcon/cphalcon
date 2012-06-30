
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
/**
 * Phalcon_Db_Profiler
 *
 * Instances of Phalcon_Db can generate execution profiles
 * on SQL statements sent to the relational database. Profiled
 * information includes execution time in miliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 *
 *
 */

PHP_METHOD(Phalcon_Db_Profiler, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_db_profiler_ce, this_ptr, SL("_allProfiles"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Starts the profile of a SQL sentence
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db_Profiler, startProfile){

	zval *sql_statement = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_db_profiler_item_ce);
	phalcon_update_property_zval(this_ptr, SL("_activeProfile"), i0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_activeProfile"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t0, "setsqlstatement", sql_statement, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_activeProfile"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "microtime", c0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t1, "setinitialtime", r0, PHALCON_NO_CHECK);
	if (phalcon_method_exists_ex(this_ptr, SL("beforestartprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_activeProfile"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "beforestartprofile", t2, PHALCON_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Stops the active profile
 *
 * @access public
 */
PHP_METHOD(Phalcon_Db_Profiler, stopProfile){

	zval *final_time = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_INIT_VAR(final_time);
	PHALCON_CALL_FUNC_PARAMS_1(final_time, "microtime", c0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_activeProfile"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t0, "setfinaltime", final_time, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_totalSeconds"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_activeProfile"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "getinitialtime", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	sub_function(r1, final_time, r0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_add_function(r2, t1, r1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_totalSeconds"), r2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_activeProfile"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, SL("_allProfiles"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t4, t3, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_allProfiles"), t4 TSRMLS_CC);
	if (phalcon_method_exists_ex(this_ptr, SL("afterendprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, SL("_activeProfile"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "afterendprofile", t5, PHALCON_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
* Returns the total number of SQL statements processed
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_allProfiles"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, t0 TSRMLS_CC);
	RETURN_DZVAL(r0);
}

/**
 * Returns the total time in seconds spent by the profiles
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_totalSeconds"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Returns all the processed profiles
 *
 * @return Phalcon_Db_Profiler_Item[]
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_allProfiles"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Resets the profiler, cleaning up all the profiles
 *
 */
PHP_METHOD(Phalcon_Db_Profiler, reset){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_allProfiles"), a0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the last profile executed in the profiler
 *
 * @return Phalcon_Db_Profiler_Item
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_activeProfile"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

