
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

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Db\Profiler
 *
 * Instances of Phalcon\Db can generate execution profiles
 * on SQL statements sent to the relational database. Profiled
 * information includes execution time in miliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 *<code>
 *
 *	$profiler = new Phalcon\Db\Profiler();
 *
 *	//Set the connection profiler
 *	$connection->setProfiler($profiler);
 *
 *	$sql = "SELECT buyer_name, quantity, product_name
 *	FROM buyers LEFT JOIN products ON
 *	buyers.pid=products.id";
 *
 *	//Execute a SQL statement
 *	$connection->query($sql);
 *
 *	//Get the last profile in the profiler
 *	$profile = $profiler->getLastProfile();
 *
 *	echo "SQL Statement: ", $profile->getSQLStatement(), "\n";
 *	echo "Start Time: ", $profile->getInitialTime(), "\n";
 *	echo "Final Time: ", $profile->getFinalTime(), "\n";
 *	echo "Total Elapsed Time: ", $profile->getTotalElapsedSeconds(), "\n";
 *
 *</code>
 *
 */


/**
 * Phalcon\Db\Profiler initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Profiler){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Profiler, db_profiler, phalcon_db_profiler_method_entry, 0);

	zend_declare_property_null(phalcon_db_profiler_ce, SL("_allProfiles"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_ce, SL("_activeProfile"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_profiler_ce, SL("_totalSeconds"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Db\Profiler constructor
 */
PHP_METHOD(Phalcon_Db_Profiler, __construct){


	phalcon_update_property_empty_array(phalcon_db_profiler_ce, this_ptr, SL("_allProfiles") TSRMLS_CC);
	
}

/**
 * Starts the profile of a SQL sentence
 *
 * @param string $sqlStatement
 * @return Phalcon\Db\Profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, startProfile){

	zval *sql_statement, *active_profile, *micro;
	zval *time;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_statement) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(active_profile);
	object_init_ex(active_profile, phalcon_db_profiler_item_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(active_profile, "setsqlstatement", sql_statement);
	
	PHALCON_INIT_VAR(micro);
	ZVAL_BOOL(micro, 1);
	
	PHALCON_INIT_VAR(time);
	PHALCON_CALL_FUNC_PARAMS_1(time, "microtime", micro);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(active_profile, "setinitialtime", time);
	if (phalcon_method_exists_ex(this_ptr, SS("beforestartprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "beforestartprofile", active_profile);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_activeProfile"), active_profile TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Stops the active profile
 *
 * @return Phalcon\Db\Profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, stopProfile){

	zval *micro, *final_time, *active_profile, *initial_time;
	zval *diference, *total_seconds, *new_total_seconds;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(micro);
	ZVAL_BOOL(micro, 1);
	
	PHALCON_INIT_VAR(final_time);
	PHALCON_CALL_FUNC_PARAMS_1(final_time, "microtime", micro);
	
	PHALCON_OBS_VAR(active_profile);
	phalcon_read_property(&active_profile, this_ptr, SL("_activeProfile"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(active_profile, "setfinaltime", final_time);
	
	PHALCON_INIT_VAR(initial_time);
	PHALCON_CALL_METHOD(initial_time, active_profile, "getinitialtime");
	
	PHALCON_INIT_VAR(diference);
	sub_function(diference, final_time, initial_time TSRMLS_CC);
	
	PHALCON_OBS_VAR(total_seconds);
	phalcon_read_property(&total_seconds, this_ptr, SL("_totalSeconds"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(new_total_seconds);
	phalcon_add_function(new_total_seconds, total_seconds, diference TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_totalSeconds"), new_total_seconds TSRMLS_CC);
	phalcon_update_property_array_append(this_ptr, SL("_allProfiles"), active_profile TSRMLS_CC);
	if (phalcon_method_exists_ex(this_ptr, SS("afterendprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "afterendprofile", active_profile);
	}
	
	
	RETURN_THIS();
}

/**
 * Returns the total number of SQL statements processed
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements){

	zval *all_profiles, *number_profiles;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(all_profiles);
	phalcon_read_property(&all_profiles, this_ptr, SL("_allProfiles"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_profiles);
	phalcon_fast_count(number_profiles, all_profiles TSRMLS_CC);
	RETURN_NCTOR(number_profiles);
}

/**
 * Returns the total time in seconds spent by the profiles
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds){


	RETURN_MEMBER(this_ptr, "_totalSeconds");
}

/**
 * Returns all the processed profiles
 *
 * @return Phalcon\Db\Profiler\Item[]
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles){


	RETURN_MEMBER(this_ptr, "_allProfiles");
}

/**
 * Resets the profiler, cleaning up all the profiles
 *
 * @return Phalcon\Db\Profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, reset){

	zval *empty_arr;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	phalcon_update_property_zval(this_ptr, SL("_allProfiles"), empty_arr TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Returns the last profile executed in the profiler
 *
 * @return Phalcon\Db\Profiler\Item
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile){


	RETURN_MEMBER(this_ptr, "_activeProfile");
}

