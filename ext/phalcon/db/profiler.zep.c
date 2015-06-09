
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/object.h"
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
 *	$profiler = new \Phalcon\Db\Profiler();
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
ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Profiler, phalcon, db_profiler, phalcon_db_profiler_method_entry, 0);

	/**
	 * All the Phalcon\Db\Profiler\Item in the active profile
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_profiler_ce, SL("_allProfiles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active Phalcon\Db\Profiler\Item
	 *
	 * @var Phalcon\Db\Profiler\Item
	 */
	zend_declare_property_null(phalcon_db_profiler_ce, SL("_activeProfile"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Total time spent by all profiles to complete
	 *
	 * @var float
	 */
	zend_declare_property_long(phalcon_db_profiler_ce, SL("_totalSeconds"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Starts the profile of a SQL sentence
 *
 * @param string sqlStatement
 * @return Phalcon\Db\Profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, startProfile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement, *sqlVariables = NULL, *sqlBindTypes = NULL, *activeProfile, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement, &sqlVariables, &sqlBindTypes);

	if (!sqlVariables) {
		sqlVariables = ZEPHIR_GLOBAL(global_null);
	}
	if (!sqlBindTypes) {
		sqlBindTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(activeProfile);
	object_init_ex(activeProfile, phalcon_db_profiler_item_ce);
	if (zephir_has_constructor(activeProfile TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, activeProfile, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, activeProfile, "setsqlstatement", NULL, 111, sqlStatement);
	zephir_check_call_status();
	if (Z_TYPE_P(sqlVariables) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, activeProfile, "setsqlvariables", NULL, 112, sqlVariables);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(sqlBindTypes) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, activeProfile, "setsqlbindtypes", NULL, 113, sqlBindTypes);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, activeProfile, "setinitialtime", NULL, 114, _0);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SS("beforestartprofile") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "beforestartprofile", NULL, 0, activeProfile);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_activeProfile"), activeProfile TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Stops the active profile
 */
PHP_METHOD(Phalcon_Db_Profiler, stopProfile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *finalTime, *initialTime = NULL, *activeProfile = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(finalTime);
	zephir_microtime(finalTime, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_activeProfile"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(activeProfile, _0);
	ZEPHIR_CALL_METHOD(NULL, activeProfile, "setfinaltime", NULL, 0, finalTime);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&initialTime, activeProfile, "getinitialtime", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_totalSeconds"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	sub_function(_1, finalTime, initialTime TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_add_function_ex(_2, _0, _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_totalSeconds"), _2 TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("_allProfiles"), activeProfile TSRMLS_CC);
	if ((zephir_method_exists_ex(this_ptr, SS("afterendprofile") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "afterendprofile", NULL, 0, activeProfile);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Returns the total number of SQL statements processed
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_allProfiles"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Returns the total time in seconds spent by the profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds) {


	RETURN_MEMBER(this_ptr, "_totalSeconds");

}

/**
 * Returns all the processed profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles) {


	RETURN_MEMBER(this_ptr, "_allProfiles");

}

/**
 * Resets the profiler, cleaning up all the profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, reset) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_allProfiles"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the last profile executed in the profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile) {


	RETURN_MEMBER(this_ptr, "_activeProfile");

}

