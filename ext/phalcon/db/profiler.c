
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
#include "kernel/object.h"
#include "kernel/operators.h"


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

	zval *sqlStatement, *activeProfile, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlStatement);



	ZEPHIR_INIT_VAR(activeProfile);
	object_init_ex(activeProfile, phalcon_db_profiler_item_ce);
	zephir_call_method_p1_noret(activeProfile, "setsqlstatement", sqlStatement);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "microtime", ZEPHIR_GLOBAL(global_true));
	zephir_call_method_p1_noret(activeProfile, "setinitialtime", _0);
	if ((zephir_method_exists_str(this_ptr, SS("beforestartprofile") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_p1_noret(this_ptr, "beforestartprofile", activeProfile);
	}
	zephir_update_property_this(this_ptr, SL("_activeProfile"), activeProfile TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Stops the active profile
 *
 * @return Phalcon\Db\Profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, stopProfile) {

	zval *finalTime, *initialTime, *activeProfile = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(finalTime);
	zephir_call_func_p1(finalTime, "microtime", ZEPHIR_GLOBAL(global_true));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_activeProfile"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(activeProfile, _0);
	zephir_call_method_p1_noret(activeProfile, "setfinaltime", finalTime);
	ZEPHIR_INIT_VAR(initialTime);
	zephir_call_method(initialTime, activeProfile, "getinitialtime");
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_totalSeconds"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	sub_function(_1, finalTime, initialTime TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_add_function(_2, _0, _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_totalSeconds"), _2 TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("_allProfiles"), activeProfile TSRMLS_CC);
	if ((zephir_method_exists_str(this_ptr, SS("afterendprofile") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_p1_noret(this_ptr, "afterendprofile", activeProfile);
	}
	RETURN_THIS();

}

/**
 * Returns the total number of SQL statements processed
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_allProfiles"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Returns the total time in seconds spent by the profiles
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds) {


	RETURN_MEMBER(this_ptr, "_totalSeconds");

}

/**
 * Returns all the processed profiles
 *
 * @return Phalcon\Db\Profiler\Item[]
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles) {


	RETURN_MEMBER(this_ptr, "_allProfiles");

}

/**
 * Resets the profiler, cleaning up all the profiles
 *
 * @return Phalcon\Db\Profiler
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
 *
 * @return	Phalcon\Db\Profiler\Item
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile) {


	RETURN_MEMBER(this_ptr, "_activeProfile");

}

