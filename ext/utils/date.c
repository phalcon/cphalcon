
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
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
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"

/**
 * Phalcon\Utils\Date
 *
 * Phalcon\Utils\Date is date helper.
 * This component is an abstract class that you can extend to add more helpers.
 */


/**
 * Phalcon\Utils\Date initializer
 */
PHALCON_INIT_CLASS(Phalcon_Utils_Date){

	PHALCON_REGISTER_CLASS(Phalcon\\Utils, Date, utils_date, phalcon_utils_date_method_entry, 0);

	zend_declare_class_constant_long(phalcon_utils_date_ce, SL("YEAR"),   PHALCON_DATE_YEAR TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_utils_date_ce, SL("MONTH"),  PHALCON_DATE_MONTH TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_utils_date_ce, SL("WEEK"),   PHALCON_DATE_WEEK TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_utils_date_ce, SL("DAY"),    PHALCON_DATE_DAY TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_utils_date_ce, SL("HOUR"),   PHALCON_DATE_HOUR TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_utils_date_ce, SL("MINUTE"), PHALCON_DATE_MINUTE TSRMLS_CC);

	zend_declare_class_constant_stringl(phalcon_utils_date_ce, SL("MONTHS_LONG"),  SL(PHALCON_DATE_MONTHS_LONG) TSRMLS_CC);
	zend_declare_class_constant_stringl(phalcon_utils_date_ce, SL("MONTHS_SHORT"), SL(PHALCON_DATE_MONTHS_SHORT) TSRMLS_CC);

	zend_declare_property_string(phalcon_utils_date_ce, SL("timestamp_format"), "Y-m-d H:i:s", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_utils_date_ce, SL("timezone"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;
}

/**
 * Returns the offset (in seconds) between two time zones. Use this to
 * display dates to users in different time zones.
 *
 *     $seconds = Phalcon\Utils\Date::offset('America/Chicago', 'GMT');
 *
 * @param string $remote
 * @param string $local
 * @param mixed $now
 * @return int
 */
PHP_METHOD(Phalcon_Utils_Date, offset){

	zval *remote, *local = NULL, *now = NULL;
	zval *format, *tmp = NULL, *zone_remote, *zone_local, *time_remote, *time_local, *offset_remote, *offset_local;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &remote, &local, &now);

	ce0 = zend_fetch_class(SL("DateTime"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ce1 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	if (!local) {
		PHALCON_INIT_VAR(local);
		phalcon_call_func(local, "date_default_timezone_get");
	}

	if (!now) {
		PHALCON_INIT_VAR(now);
	} else if (Z_TYPE_P(now) == IS_LONG) {
		PHALCON_SEPARATE_PARAM(now);

		PHALCON_INIT_VAR(format);
		phalcon_get_class_constant(format, ce0, SS("RFC2822") TSRMLS_CC);

		PHALCON_INIT_NVAR(tmp);
		phalcon_call_func_p2(tmp, "date", format, now);

		PHALCON_CPY_WRT(now, tmp);
	}

	PHALCON_INIT_VAR(zone_remote);
	object_init_ex(zone_remote, ce1);
	if (phalcon_has_constructor(zone_remote TSRMLS_CC)) {
		phalcon_call_method_p1_noret(zone_remote, "__construct", remote);
	}

	PHALCON_INIT_VAR(zone_local);
	object_init_ex(zone_local, ce1);
	if (phalcon_has_constructor(zone_local TSRMLS_CC)) {
		phalcon_call_method_p1_noret(zone_local, "__construct", local);
	}

	PHALCON_INIT_VAR(time_remote);
	object_init_ex(time_remote, ce0);
	if (phalcon_has_constructor(time_remote TSRMLS_CC)) {
		phalcon_call_method_p2_noret(time_remote, "__construct", now, zone_remote);
	}

	PHALCON_INIT_VAR(time_local);
	object_init_ex(time_local, ce0);
	if (phalcon_has_constructor(time_local TSRMLS_CC)) {
		phalcon_call_method_p2_noret(time_local, "__construct", now, zone_local);
	}

	PHALCON_INIT_VAR(offset_remote);
	phalcon_call_method_p1(offset_remote, zone_remote, "getOffset", time_remote);

	PHALCON_INIT_VAR(offset_local);
	phalcon_call_method_p1(offset_local, zone_local, "getOffset", time_local);

	ZVAL_LONG(return_value, phalcon_get_intval(offset_remote)-phalcon_get_intval(offset_local));

	PHALCON_MM_RESTORE();
}

/**
 * Number of seconds in a minute, incrementing by a step. Typically used as
 * a shortcut for generating a list that can used in a form.
 *
 *     $seconds = Phalcon\Utils\Date::seconds(); // 01, 02, 03, ..., 58, 59, 60
 *
 * @param int $step
 * @param int $start
 * @param int $end
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, seconds){
}

/**
 * Number of minutes in an hour, incrementing by a step. Typically used as
 * a shortcut for generating a list that can be used in a form.
 *
 *     $minutes = Phalcon\Utils\Date::minutes(); // 05, 10, 15, ..., 50, 55, 60
 *
 * @param int $step
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, minutes){
}

/**
 * Number of hours in a day. Typically used as a shortcut for generating a
 * list that can be used in a form.
 *
 *     $hours = Phalcon\Utils\Date::hours(); // 01, 02, 03, ..., 10, 11, 12
 *
 * @param int $step
 * @param boolean $long
 * @param int $start
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, hours){
}

/**
 * Returns AM or PM, based on a given hour (in 24 hour format).
 *
 *     $type = Phalcon\Utils\Date::ampm(12); // PM
 *     $type = Phalcon\Utils\Date::ampm(1);  // AM
 *
 * @param int $hour
 * @return string
 */
PHP_METHOD(Phalcon_Utils_Date, ampm){
}

/**
 * Adjusts a non-24-hour number into a 24-hour number.
 *
 *     $hour = Phalcon\Utils\Date::adjust(3, 'pm'); // 15
 *
 * @param int $hour
 * @param string $ampm
 * @return string
 */
PHP_METHOD(Phalcon_Utils_Date, adjust){
}

/**
 * Number of days in a given month and year. Typically used as a shortcut
 * for generating a list that can be used in a form.
 *
 *     Phalcon\Utils\Date::days(4, 2010); // 1, 2, 3, ..., 28, 29, 30
 *
 * @param int $month
 * @param int $year
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, days){
}

/**
 * Number of months in a year. Typically used as a shortcut for generating
 * a list that can be used in a form.
 *
 * By default a mirrored array of $month_number => $month_number is returned
 *
 *     Phalcon\Utils\Date::months();
 *     // aray(1 => 1, 2 => 2, 3 => 3, ..., 12 => 12)
 *
 * But you can customise this by passing in either Date::MONTHS_LONG
 *
 *     Phalcon\Utils\Date::months(Date::MONTHS_LONG);
 *     // array(1 => 'January', 2 => 'February', ..., 12 => 'December')
 *
 * Or Date::MONTHS_SHORT
 *
 *     Phalcon\Utils\Date::months(Date::MONTHS_SHORT);
 *     // array(1 => 'Jan', 2 => 'Feb', ..., 12 => 'Dec')
 *
 * @uses Date::hours
 * @param string $format
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, months){
}

/**
 * Returns an array of years between a starting and ending year. By default,
 * the the current year - 5 and current year + 5 will be used. Typically used
 * as a shortcut for generating a list that can be used in a form.
 *
 *     $years = Phalcon\Utils\Date::years(2000, 2010); // 2000, 2001, ..., 2009, 2010
 *
 * @param int $start
 * @param int $end
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, years){
}

/**
 * Returns time difference between two timestamps, in human readable format.
 * If the second timestamp is not given, the current time will be used.
 * Also consider using [Date::fuzzy_span] when displaying a span.
 *
 *     $span = Phalcon\Utils\Date::span(60, 182, 'minutes,seconds'); // array('minutes' => 2, 'seconds' => 2)
 *     $span = Phalcon\Utils\Date::span(60, 182, 'minutes'); // 2
 *
 * @param int $remote
 * @param int $local
 * @param string $output
 * @return string/array
 */
PHP_METHOD(Phalcon_Utils_Date, span){
}

/**
 * Returns the difference between a time and now in a "fuzzy" way.
 * Displaying a fuzzy time instead of a date is usually faster to read and understand.
 *
 *     $span = Phalcon\Utils\Date::fuzzy_span(time() - 10); // "moments ago"
 *     $span = Phalcon\Utils\Date::fuzzy_span(time() + 20); // "in moments"
 *
 * A second parameter is available to manually set the "local" timestamp,
 * however this parameter shouldn't be needed in normal usage and is only
 * included for unit tests
 *
 * @param int $timestamp
 * @param int $local_timestamp
 * @return string
 */
PHP_METHOD(Phalcon_Utils_Date, fuzzy_span){
}

/**
 * Converts a UNIX timestamp to DOS format. There are very few cases where
 * this is needed, but some binary formats use it (eg: zip files.)
 * Converting the other direction is done using {@link Date::dos2unix}.
 *
 *     $dos = Phalcon\Utils\Date::unix2dos($unix);
 *
 * @param int $timestamp
 * @return int
 */
PHP_METHOD(Phalcon_Utils_Date, unix2dos){
}

/**
 * Converts a DOS timestamp to UNIX format.There are very few cases where
 * this is needed, but some binary formats use it (eg: zip files.)
 * Converting the other direction is done using {@link Date::unix2dos}.
 *
 *     $unix = Phalcon\Utils\Date::dos2unix($dos);
 *
 * @param int $timestamp
 * @return int
 */
PHP_METHOD(Phalcon_Utils_Date, dos2unix){
}

/**
 * Returns a date/time string with the specified timestamp format
 *
 *     $time = Phalcon\Utils\Date::formatted_time('5 minutes ago');
 *
 * @param string $datetime_str
 * @param string $timestamp_format
 * @param string $timezone
 * @return string
 */
PHP_METHOD(Phalcon_Utils_Date, formatted_time){
}
