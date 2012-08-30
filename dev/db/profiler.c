
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"

/**
 * Phalcon\Db\Profiler
 *
 * Instances of Phalcon\Db can generate execution profiles
 * on SQL statements sent to the relational database. Profiled
 * information includes execution time in miliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 */


PHP_METHOD(Phalcon_Db_Profiler, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_db_profiler_ce, this_ptr, SL("_allProfiles"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Starts the profile of a SQL sentence
 *
 * @param string $sqlStatement
 * @return \Phalcon\Db\Profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, startProfile){

	zval *sql_statement = NULL, *active_profile = NULL, *micro = NULL;
	zval *time = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(active_profile);
	object_init_ex(active_profile, phalcon_db_profiler_item_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(active_profile, "setsqlstatement", sql_statement, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(micro);
	ZVAL_BOOL(micro, 1);
	
	PHALCON_INIT_VAR(time);
	PHALCON_CALL_FUNC_PARAMS_1(time, "microtime", micro);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(active_profile, "setinitialtime", time, PH_NO_CHECK);
	if (phalcon_method_exists_ex(this_ptr, SL("beforestartprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "beforestartprofile", active_profile, PH_NO_CHECK);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_activeProfile"), active_profile TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Stops the active profile
 *
 * @return \Phalcon\Db\Profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, stopProfile){

	zval *micro = NULL, *final_time = NULL, *active_profile = NULL, *initial_time = NULL;
	zval *diference = NULL, *total_seconds = NULL, *new_total_seconds = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(micro);
	ZVAL_BOOL(micro, 1);
	
	PHALCON_INIT_VAR(final_time);
	PHALCON_CALL_FUNC_PARAMS_1(final_time, "microtime", micro);
	
	PHALCON_INIT_VAR(active_profile);
	phalcon_read_property(&active_profile, this_ptr, SL("_activeProfile"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(active_profile, "setfinaltime", final_time, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(initial_time);
	PHALCON_CALL_METHOD(initial_time, active_profile, "getinitialtime", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(diference);
	sub_function(diference, final_time, initial_time TSRMLS_CC);
	
	PHALCON_INIT_VAR(total_seconds);
	phalcon_read_property(&total_seconds, this_ptr, SL("_totalSeconds"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(new_total_seconds);
	phalcon_add_function(new_total_seconds, total_seconds, diference TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_totalSeconds"), new_total_seconds TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_allProfiles"), PH_NOISY_CC);
	phalcon_array_append(&t0, active_profile, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_allProfiles"), t0 TSRMLS_CC);
	if (phalcon_method_exists_ex(this_ptr, SL("afterendprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "afterendprofile", active_profile, PH_NO_CHECK);
	}
	
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Returns the total number of SQL statements processed
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements){

	zval *all_profiles = NULL, *number_profiles = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(all_profiles);
	phalcon_read_property(&all_profiles, this_ptr, SL("_allProfiles"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_profiles);
	phalcon_fast_count(number_profiles, all_profiles TSRMLS_CC);
	
	RETURN_CCTOR(number_profiles);
}

/**
 * Returns the total time in seconds spent by the profiles
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds){

	zval *total_seconds = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(total_seconds);
	phalcon_read_property(&total_seconds, this_ptr, SL("_totalSeconds"), PH_NOISY_CC);
	
	RETURN_CCTOR(total_seconds);
}

/**
 * Returns all the processed profiles
 *
 * @return Phalcon\Db\Profiler\Item[]
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles){

	zval *all_profiles = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(all_profiles);
	phalcon_read_property(&all_profiles, this_ptr, SL("_allProfiles"), PH_NOISY_CC);
	
	RETURN_CCTOR(all_profiles);
}

/**
 * Resets the profiler, cleaning up all the profiles
 *
 * @return \Phalcon\Db\Profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, reset){

	zval *empty_arr = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	phalcon_update_property_zval(this_ptr, SL("_allProfiles"), empty_arr TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Returns the last profile executed in the profiler
 *
 * @return Phalcon\Db\Profiler\Item
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile){

	zval *active_profile = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(active_profile);
	phalcon_read_property(&active_profile, this_ptr, SL("_activeProfile"), PH_NOISY_CC);
	
	RETURN_CCTOR(active_profile);
}

