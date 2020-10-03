
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
#include "kernel/string.h"
#include "kernel/time.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Profiler, phalcon, db_profiler, phalcon_db_profiler_method_entry, 0);

	/**
	 * Active Phalcon\Db\Profiler\Item
	 *
	 * @var Phalcon\Db\Profiler\Item
	 */
	zend_declare_property_null(phalcon_db_profiler_ce, SL("activeProfile"), ZEND_ACC_PROTECTED);

	/**
	 * All the Phalcon\Db\Profiler\Item in the active profile
	 *
	 * @var \Phalcon\Db\Profiler\Item[]
	 */
	zend_declare_property_null(phalcon_db_profiler_ce, SL("allProfiles"), ZEND_ACC_PROTECTED);

	/**
	 * Total time spent by all profiles to complete
	 *
	 * @var float
	 */
	zend_declare_property_long(phalcon_db_profiler_ce, SL("totalSeconds"), 0, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Returns the last profile executed in the profiler
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeProfile");

}

/**
 * Returns the total number of SQL statements processed
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("allProfiles"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));

}

/**
 * Returns the total time in seconds spent by the profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "totalSeconds");

}

/**
 * Returns all the processed profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "allProfiles");

}

/**
 * Resets the profiler, cleaning up all the profiles
 */
PHP_METHOD(Phalcon_Db_Profiler, reset) {

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
PHP_METHOD(Phalcon_Db_Profiler, startProfile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement_param = NULL, *sqlVariables = NULL, sqlVariables_sub, *sqlBindTypes = NULL, sqlBindTypes_sub, __$true, __$null, activeProfile, version, _0$$5, _1$$6, _2$$6;
	zval sqlStatement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement);
	ZVAL_UNDEF(&sqlVariables_sub);
	ZVAL_UNDEF(&sqlBindTypes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&activeProfile);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &sqlVariables, &sqlBindTypes);

	zephir_get_strval(&sqlStatement, sqlStatement_param);
	if (!sqlVariables) {
		sqlVariables = &sqlVariables_sub;
		sqlVariables = &__$null;
	}
	if (!sqlBindTypes) {
		sqlBindTypes = &sqlBindTypes_sub;
		sqlBindTypes = &__$null;
	}


	ZEPHIR_INIT_VAR(&activeProfile);
	object_init_ex(&activeProfile, phalcon_db_profiler_item_ce);
	if (zephir_has_constructor(&activeProfile)) {
		ZEPHIR_CALL_METHOD(NULL, &activeProfile, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setsqlstatement", NULL, 216, &sqlStatement);
	zephir_check_call_status();
	if (Z_TYPE_P(sqlVariables) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setsqlvariables", NULL, 217, sqlVariables);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(sqlBindTypes) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setsqlbindtypes", NULL, 218, sqlBindTypes);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 201);
	zephir_check_call_status();
	if (zephir_start_with_str(&version, SL("7.2"))) {
		ZEPHIR_INIT_VAR(&_0$$5);
		zephir_microtime(&_0$$5, &__$true);
		ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setinitialtime", NULL, 219, &_0$$5);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_1$$6, 1);
		ZEPHIR_CALL_FUNCTION(&_2$$6, "hrtime", NULL, 0, &_1$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setinitialtime", NULL, 219, &_2$$6);
		zephir_check_call_status();
	}
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
PHP_METHOD(Phalcon_Db_Profiler, stopProfile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, activeProfile, finalTime, initialTime, version, _1, _2, _3, _0$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&activeProfile);
	ZVAL_UNDEF(&finalTime);
	ZVAL_UNDEF(&initialTime);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 201);
	zephir_check_call_status();
	if (zephir_start_with_str(&version, SL("7.2"))) {
		ZEPHIR_INIT_VAR(&finalTime);
		zephir_microtime(&finalTime, &__$true);
	} else {
		ZVAL_BOOL(&_0$$4, 1);
		ZEPHIR_CALL_FUNCTION(&finalTime, "hrtime", NULL, 0, &_0$$4);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("activeProfile"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeProfile, &_1);
	ZEPHIR_CALL_METHOD(NULL, &activeProfile, "setfinaltime", NULL, 0, &finalTime);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&initialTime, &activeProfile, "getinitialtime", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("totalSeconds"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_sub_function(&_2, &finalTime, &initialTime);
	ZEPHIR_INIT_VAR(&_3);
	zephir_add_function(&_3, &_1, &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("totalSeconds"), &_3);
	zephir_update_property_array_append(this_ptr, SL("allProfiles"), &activeProfile);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("afterendprofile")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "afterendprofile", NULL, 0, &activeProfile);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

