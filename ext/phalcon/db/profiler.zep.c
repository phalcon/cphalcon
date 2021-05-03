
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Instances of Phalcon\Db can generate execution profiles
 * on SQL statements sent to the relational database. Profiled
 * information includes execution time in milliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 * ```php
 * use Phalcon\Db\Profiler;
 * use Phalcon\Events\Event;
 * use Phalcon\Events\Manager;
 *
 * $profiler = new Profiler();
 * $eventsManager = new Manager();
 *
 * $eventsManager->attach(
 *     "db",
 *     function (Event $event, $connection) use ($profiler) {
 *         if ($event->getType() === "beforeQuery") {
 *             $sql = $connection->getSQLStatement();
 *
 *             // Start a profile with the active connection
 *             $profiler->startProfile($sql);
 *         }
 *
 *         if ($event->getType() === "afterQuery") {
 *             // Stop the active profile
 *             $profiler->stopProfile();
 *         }
 *     }
 * );
 *
 * // Set the event manager on the connection
 * $connection->setEventsManager($eventsManager);
 *
 *
 * $sql = "SELECT buyer_name, quantity, product_name
 * FROM buyers LEFT JOIN products ON
 * buyers.pid=products.id";
 *
 * // Execute a SQL statement
 * $connection->query($sql);
 *
 * // Get the last profile in the profiler
 * $profile = $profiler->getLastProfile();
 *
 * echo "SQL Statement: ", $profile->getSQLStatement(), "\n";
 * echo "Start Time: ", $profile->getInitialTime(), "\n";
 * echo "Final Time: ", $profile->getFinalTime(), "\n";
 * echo "Total Elapsed Time: ", $profile->getTotalElapsedSeconds(), "\n";
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Profiler, phalcon, db_profiler, phalcon_db_profiler_method_entry, 0);

	/**
	 * Active Item
	 *
	 * @var Item
	 */
	zend_declare_property_null(phalcon_db_profiler_ce, SL("activeProfile"), ZEND_ACC_PROTECTED);
	/**
	 * All the Items in the active profile
	 *
	 * @var Item[]
	 */
	zend_declare_property_null(phalcon_db_profiler_ce, SL("allProfiles"), ZEND_ACC_PROTECTED);
	/**
	 * Total time spent by all profiles to complete in nanoseconds
	 *
	 * @var float
	 */
	zend_declare_property_long(phalcon_db_profiler_ce, SL("totalNanoseconds"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Returns the last profile executed in the profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "activeProfile");
}

/**
 * Returns the total number of SQL statements processed
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("allProfiles"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Returns the total time in nanoseconds spent by the profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedNanoseconds)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "totalNanoseconds");
}

/**
 * Returns the total time in milliseconds spent by the profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedMilliseconds)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettotalelapsednanoseconds", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_safe_div_zval_long(&_0, 1000000));
}

/**
 * Returns the total time in seconds spent by the profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettotalelapsedmilliseconds", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_safe_div_zval_long(&_0, 1000));
}

/**
 * Returns all the processed profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "allProfiles");
}

/**
 * Resets the profiler, cleaning up all the profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, reset)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("allProfiles"), &_0);
	RETURN_THIS();
}

/**
 * Starts the profile of a SQL sentence
 */
PHP_METHOD(Phalcon_Db_Profiler, startProfile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sqlVariables, sqlBindTypes;
	zval *sqlStatement_param = NULL, *sqlVariables_param = NULL, *sqlBindTypes_param = NULL, __$true, activeProfile, _0;
	zval sqlStatement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&activeProfile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&sqlVariables);
	ZVAL_UNDEF(&sqlBindTypes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(sqlStatement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(sqlVariables)
		Z_PARAM_ARRAY(sqlBindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &sqlVariables_param, &sqlBindTypes_param);
	zephir_get_strval(&sqlStatement, sqlStatement_param);
	if (!sqlVariables_param) {
		ZEPHIR_INIT_VAR(&sqlVariables);
		array_init(&sqlVariables);
	} else {
		zephir_get_arrval(&sqlVariables, sqlVariables_param);
	}
	if (!sqlBindTypes_param) {
		ZEPHIR_INIT_VAR(&sqlBindTypes);
		array_init(&sqlBindTypes);
	} else {
		zephir_get_arrval(&sqlBindTypes, sqlBindTypes_param);
	}


	ZEPHIR_INIT_VAR(&activeProfile);
	object_init_ex(&activeProfile, phalcon_db_profiler_item_ce);
	if (zephir_has_constructor(&activeProfile)) {
		ZEPHIR_CALL_METHOD(NULL, &activeProfile, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setsqlstatement", NULL, 217, &sqlStatement);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setsqlvariables", NULL, 218, &sqlVariables);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setsqlbindtypes", NULL, 219, &sqlBindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "hrtime", NULL, 202, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setinitialtime", NULL, 220, &_0);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforestartprofile")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "beforestartprofile", NULL, 0, &activeProfile);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeProfile"), &activeProfile);
	RETURN_THIS();
}

/**
 * Stops the active profile
 */
PHP_METHOD(Phalcon_Db_Profiler, stopProfile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, activeProfile, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&activeProfile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeProfile"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeProfile, &_0);
	ZEPHIR_CALL_FUNCTION(&_1, "hrtime", NULL, 202, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setfinaltime", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("totalNanoseconds"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &activeProfile, "gettotalelapsednanoseconds", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_add_function(&_3, &_0, &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("totalNanoseconds"), &_3);
	zephir_update_property_array_append(this_ptr, SL("allProfiles"), &activeProfile);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("afterendprofile")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "afterendprofile", NULL, 0, &activeProfile);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

