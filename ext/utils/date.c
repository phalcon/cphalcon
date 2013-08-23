
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

#include <math.h>

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

#include "utils/date.h"

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
	zend_declare_property_null(phalcon_utils_date_ce, SL("_months"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;
}

/**
 * Returns the offset (in seconds) between two time zones. Use this to
 * display dates to users in different time zones.
 *
 *     $seconds = Phalcon\Utils\PHALCON_DATE_offset('America/Chicago', 'GMT');
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
 *     $seconds = Phalcon\Utils\PHALCON_DATE_seconds(); // 01, 02, 03, ..., 58, 59, 60
 *
 * @param int $step
 * @param int $start
 * @param int $end
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, seconds){

	zval *step = NULL, *start = NULL, *end = NULL;
	char buf[2];
	int i, p, s, e;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &step, &start, &end);

	if (!step) {
		PHALCON_INIT_VAR(step);
		ZVAL_LONG(step, 1);
	} else if (Z_TYPE_P(step) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(step);
		convert_to_long(step);
	}

	if (!start) {
		PHALCON_INIT_VAR(start);
		ZVAL_LONG(start, 0);
	} else if (Z_TYPE_P(start) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(start);
		convert_to_long(start);
	}

	if (!end) {
		PHALCON_INIT_VAR(end);
		ZVAL_LONG(end, 60);
	} else if (Z_TYPE_P(end) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(end);
		convert_to_long(end);
	}

	p = Z_LVAL_P(step);
	s = Z_LVAL_P(start);
	e = Z_LVAL_P(end);

	if (p < 1) {
		p = 1;
	}

	array_init(return_value);

	for (i = s; i < e; i += p) {
		sprintf(buf, "%02d", i);
		phalcon_array_update_long_string(&return_value, i, buf, 2, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Number of minutes in an hour, incrementing by a step. Typically used as
 * a shortcut for generating a list that can be used in a form.
 *
 *     $minutes = Phalcon\Utils\PHALCON_DATE_minutes(); // 05, 10, 15, ..., 50, 55, 60
 *
 * @param int $step
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, minutes){

	zval *step = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &step);

	if (!step) {
		PHALCON_INIT_VAR(step);
		ZVAL_LONG(step, 5);
	}

	phalcon_call_self_p1(return_value, this_ptr, "seconds", step);

	PHALCON_MM_RESTORE();
}

/**
 * Number of hours in a day. Typically used as a shortcut for generating a
 * list that can be used in a form.
 *
 *     $hours = Phalcon\Utils\PHALCON_DATE_hours(); // 01, 02, 03, ..., 10, 11, 12
 *
 * @param int $step
 * @param boolean $is_long
 * @param int $start
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, hours){

	zval *step = NULL, *is_long = NULL, *start = NULL;
	int i, p, s, e;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &step, &is_long, &start);

	if (!step) {
		PHALCON_INIT_VAR(step);
		ZVAL_LONG(step, 1);
	} else if (Z_TYPE_P(step) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(step);
		convert_to_long(step);
	}

	if (!is_long) {
		PHALCON_INIT_VAR(is_long);
		ZVAL_FALSE(is_long);
	}

	if (!start) {
		PHALCON_INIT_VAR(start);
	} 

	p = Z_LVAL_P(step);
	if (p < 1) {
		p = 1;
	}

	if (Z_TYPE_P(start) == IS_NULL) {
		if (zend_is_true(is_long)) {
			s = 0;
		} else {
			s = 1;
		}
	} else {
		s = phalcon_get_intval(start);
	}

	e = zend_is_true(is_long) ? 23 : 12;

	array_init(return_value);

	for (i = s; i <= e; i += p) {
		phalcon_array_update_long_long(&return_value, i, i, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Returns AM or PM, based on a given hour (in 24 hour format).
 *
 *     $type = Phalcon\Utils\PHALCON_DATE_ampm(12); // PM
 *     $type = Phalcon\Utils\PHALCON_DATE_ampm(1);  // AM
 *
 * @param int $hour
 * @return string
 */
PHP_METHOD(Phalcon_Utils_Date, ampm){

	zval *hour;

	phalcon_fetch_params(0, 1, 0, &hour);

	if (phalcon_get_intval(hour) > 11) {
		ZVAL_STRING(return_value, "PM", 1);
	} else {
		ZVAL_STRING(return_value, "AM", 1);
	}
}

/**
 * Adjusts a non-24-hour number into a 24-hour number.
 *
 *     $hour = Phalcon\Utils\PHALCON_DATE_adjust(3, 'pm'); // 15
 *
 * @param int $hour
 * @param string $ampm
 * @return string
 */
PHP_METHOD(Phalcon_Utils_Date, adjust){	
	
	zval *hour, *ampm, *lowercased_ampm;
	char buf[2];
	int h;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &hour, &ampm);

	PHALCON_SEPARATE_PARAM(hour);
	convert_to_long(hour);

	h = Z_LVAL_P(hour);

	PHALCON_INIT_VAR(lowercased_ampm);
	phalcon_fast_strtolower(lowercased_ampm, ampm);

	if (PHALCON_IS_STRING(lowercased_ampm, "am")) {
		if (h == 12) {
			h = 0;
		}
	} else if (PHALCON_IS_STRING(lowercased_ampm, "pm")) {
		if (h < 12) {
			h += 12;
		}
	}

	sprintf(buf, "%02d", h);

	ZVAL_STRING(return_value, buf, 1);

	PHALCON_MM_RESTORE();
}

/**
 * Number of days in a given month and year. Typically used as a shortcut
 * for generating a list that can be used in a form.
 *
 *     Phalcon\Utils\PHALCON_DATE_days(4, 2010); // 1, 2, 3, ..., 28, 29, 30
 *
 * @param int $month
 * @param int $year
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, days){

	zval *month, *year, *tmp = NULL, *tmp1, *tmp2, *total;
	zval *months;
	int y, m, i, t;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &month, &year);

	PHALCON_OBS_VAR(months);
	phalcon_read_static_property_ce(&months, phalcon_utils_date_ce, SL("_months") TSRMLS_CC);

	if (!year) {
		PHALCON_INIT_VAR(year);
		ZVAL_FALSE(year);
	} else if (Z_TYPE_P(year) == IS_BOOL && !zend_is_true(year)) {
		PHALCON_SEPARATE_PARAM(year);

		PHALCON_INIT_VAR(tmp);
		ZVAL_STRING(tmp, "Y", 1);
		
		PHALCON_INIT_NVAR(year);
		phalcon_call_func_p1(year, "date", tmp);
	}

	y = phalcon_get_intval(year);
	m = phalcon_get_intval(month);

	if (phalcon_array_isset_long_fetch(&tmp, months, y)) {
		if (phalcon_array_isset_long_fetch(&return_value, tmp, m)) {
			RETURN_MM();
		}
	}

	PHALCON_INIT_VAR(tmp1);
	ZVAL_LONG(tmp1, 1);

	PHALCON_INIT_VAR(tmp2);
	ZVAL_LONG(tmp2, 0);

	PHALCON_INIT_NVAR(tmp);
	phalcon_call_func_p6(tmp, "mktime", tmp1, tmp2, tmp2, month, tmp1, year);
	
	PHALCON_INIT_VAR(tmp1);
	ZVAL_STRING(tmp1, "t", 1);

	PHALCON_INIT_VAR(total);
	phalcon_call_func_p2(total, "date", tmp1, tmp);

	t = phalcon_get_intval(total);

	PHALCON_INIT_NVAR(tmp);
	array_init(tmp);

	PHALCON_INIT_NVAR(months);
	array_init(months);

	phalcon_array_update_long(&months, y, &tmp, PH_COPY | PH_SEPARATE);

	for (i = 1; i < t; i++) {
		phalcon_array_update_long_long(&tmp, i, i, 0);
	}

	phalcon_array_update_long_long_multi_2(&months, y, m, &tmp, PH_COPY | PH_SEPARATE);

	phalcon_update_static_property_ce(phalcon_utils_date_ce, SL("_months"), months TSRMLS_CC);

	RETURN_CCTOR(tmp);
}

/**
 * Number of months in a year. Typically used as a shortcut for generating
 * a list that can be used in a form.
 *
 * By default a mirrored array of $month_number => $month_number is returned
 *
 *     Phalcon\Utils\PHALCON_DATE_months();
 *     // aray(1 => 1, 2 => 2, 3 => 3, ..., 12 => 12)
 *
 * But you can customise this by passing in either PHALCON_DATE_MONTHS_LONG
 *
 *     Phalcon\Utils\PHALCON_DATE_months(Phalcon\Utils\PHALCON_DATE_MONTHS_LONG);
 *     // array(1 => 'January', 2 => 'February', ..., 12 => 'December')
 *
 * Or PHALCON_DATE_MONTHS_SHORT
 *
 *     Phalcon\Utils\PHALCON_DATE_months(PHALCON_DATE_MONTHS_SHORT);
 *     // array(1 => 'Jan', 2 => 'Feb', ..., 12 => 'Dec')
 *
 * @uses PHALCON_DATE_hours
 * @param string $format
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, months){

	zval *format, *tmp = NULL, *tmp1, *tmp2, *tmp3 = NULL, *value = NULL;
	int i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &format);

	if (PHALCON_IS_STRING(format, PHALCON_DATE_MONTHS_LONG) || PHALCON_IS_STRING(format, PHALCON_DATE_MONTHS_SHORT)) {
		array_init(return_value);

		PHALCON_INIT_VAR(tmp1);
		ZVAL_LONG(tmp1, 0);

		PHALCON_INIT_VAR(tmp2);
		ZVAL_LONG(tmp2, 1);

		for (i = 1; i <= 12; ++i) {
			PHALCON_INIT_NVAR(tmp3);
			ZVAL_LONG(tmp3, i);

			PHALCON_INIT_NVAR(tmp);
			phalcon_call_func_p5(tmp, "mktime", tmp1, tmp1, tmp1, tmp3, tmp2);

			PHALCON_INIT_NVAR(value);
			phalcon_call_func_p2(value, "strftime", format, tmp);

			phalcon_array_update_long(&return_value, i, &value, PH_COPY | PH_SEPARATE);
		}
	} else {
		phalcon_call_self(return_value, this_ptr, "hours");
	}

	PHALCON_MM_RESTORE();
}

/**
 * Returns an array of years between a starting and ending year. By default,
 * the the current year - 5 and current year + 5 will be used. Typically used
 * as a shortcut for generating a list that can be used in a form.
 *
 *     $years = Phalcon\Utils\PHALCON_DATE_years(2000, 2010); // 2000, 2001, ..., 2009, 2010
 *
 * @param int $start
 * @param int $end
 * @return array
 */
PHP_METHOD(Phalcon_Utils_Date, years){

	zval *start = NULL, *end = NULL, *tmp;
	int i, s, e;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &start, &end);

	if (!start || (Z_TYPE_P(start) == IS_BOOL && !zend_is_true(start))) {
		if (start) {
			PHALCON_SEPARATE_PARAM(start);
		}
		PHALCON_INIT_VAR(tmp);
		ZVAL_STRING(tmp, "Y", 1);
		
		PHALCON_INIT_NVAR(start);
		phalcon_call_func_p1(start, "date", tmp);

		s = phalcon_get_intval(start) - 5;
	} else {
		s = phalcon_get_intval(start);
	}

	if (!end || (Z_TYPE_P(end) == IS_BOOL && !zend_is_true(end))) {
		if (end) {
			PHALCON_SEPARATE_PARAM(end);
		}
		PHALCON_INIT_NVAR(tmp);
		ZVAL_STRING(tmp, "Y", 1);
		
		PHALCON_INIT_NVAR(end);
		phalcon_call_func_p1(end, "date", tmp);

		e = phalcon_get_intval(end) + 5;
	} else {
		e = phalcon_get_intval(end);
	}
	
	array_init(return_value);

	for (i = s; i <= e; i++) {
		phalcon_array_update_long_long(&return_value, i, i, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Returns time difference between two timestamps, in human readable format.
 * If the second timestamp is not given, the current time will be used.
 * Also consider using [PHALCON_DATE_fuzzy_span] when displaying a span.
 *
 *     $span = Phalcon\Utils\PHALCON_DATE_span(60, 182, 'minutes,seconds'); // array('minutes' => 2, 'seconds' => 2)
 *     $span = Phalcon\Utils\PHALCON_DATE_span(60, 182, 'minutes'); // 2
 *
 * @param int $remote
 * @param int $local
 * @param string $output
 * @return string/array
 */
PHP_METHOD(Phalcon_Utils_Date, span){

	zval *remote, *local = NULL, *output = NULL;
	zval *lowercased_output, *count_output, *tmp = NULL, *tmp1, *pattern;
	long remote_time, local_time, timespan;
	int i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &remote, &local, &output);

	if (!output) {
		PHALCON_INIT_VAR(lowercased_output);
		ZVAL_STRING(lowercased_output, "years,months,weeks,days,hours,minutes,seconds", 1);
	} else {
		PHALCON_SEPARATE_PARAM(output);

		PHALCON_INIT_VAR(tmp);
		phalcon_fast_trim(tmp, output, PHALCON_TRIM_BOTH TSRMLS_CC);

		PHALCON_INIT_VAR(lowercased_output);
		phalcon_fast_strtolower(lowercased_output, tmp);

		if (PHALCON_IS_EMPTY(lowercased_output)) {
			RETURN_MM_FALSE;
		}
	}

	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/[^a-z]+/", 1);

	PHALCON_INIT_NVAR(output);
	phalcon_call_func_p2(output, "preg_split", pattern, lowercased_output);

	PHALCON_INIT_VAR(tmp1);
	ZVAL_LONG(tmp1, 0);

	PHALCON_INIT_VAR(count_output);
	phalcon_fast_count(count_output, output TSRMLS_CC);

	PHALCON_INIT_NVAR(tmp);
	phalcon_call_func_p3(tmp, "array_fill", tmp1, count_output, tmp1);

	PHALCON_CPY_WRT(tmp1, output);

	PHALCON_INIT_NVAR(output);
	phalcon_call_func_p2(output, "array_combine", tmp1, tmp);

	remote_time = phalcon_get_intval(remote);
	
	if (!local || Z_TYPE_P(local) == IS_NULL) {
		local_time = (long) time(NULL);
	} else {
		local_time = phalcon_get_intval(local);
	}

	// Calculate timespan (seconds)
	timespan = remote_time - local_time;
	if (timespan < 0) {
		timespan *= -1;
	}

	if (phalcon_array_isset_string(output, SS("years"))) {
		i = (int) floor(timespan / PHALCON_DATE_YEAR);
		phalcon_array_update_string_long(&output, SL("years"), i, 0);
		timespan -= PHALCON_DATE_YEAR * i;
	}

	if (phalcon_array_isset_string(output, SS("months"))) {
		i = (int) floor(timespan / PHALCON_DATE_MONTH);
		phalcon_array_update_string_long(&output, SL("months"), i, 0);
		timespan -= PHALCON_DATE_MONTH * i;
	}

	if (phalcon_array_isset_string(output, SS("weeks"))) {
		i = (int) floor(timespan / PHALCON_DATE_WEEK);
		phalcon_array_update_string_long(&output, SL("weeks"), i, 0);
		timespan -= PHALCON_DATE_WEEK * i;
	}

	if (phalcon_array_isset_string(output, SS("days"))) {
		i = (int) floor(timespan / PHALCON_DATE_DAY);
		phalcon_array_update_string_long(&output, SL("days"), i, 0);
		timespan -= PHALCON_DATE_DAY * i;
	}

	if (phalcon_array_isset_string(output, SS("hours"))) {
		i = (int) floor(timespan / PHALCON_DATE_HOUR);
		phalcon_array_update_string_long(&output, SL("hours"), i, 0);
		timespan -= PHALCON_DATE_HOUR * i;
	}

	if (phalcon_array_isset_string(output, SS("minutes"))) {
		i = (int) floor(timespan / PHALCON_DATE_MINUTE);
		phalcon_array_update_string_long(&output, SL("minutes"), i, 0);
		timespan -= PHALCON_DATE_MINUTE * i;
	}

	if (phalcon_array_isset_string(output, SS("seconds"))) {
		phalcon_array_update_string_long(&output, SL("seconds"), timespan, 0);
	}

	if (Z_LVAL_P(count_output) == 1) {
		Z_SET_ISREF_P(output);
		phalcon_call_func_p1(return_value, "array_pop", output);
		Z_UNSET_ISREF_P(output);
		RETURN_MM();
	}

	RETURN_CCTOR(output);
}

/**
 * Returns the difference between a time and now in a "fuzzy" way.
 * Displaying a fuzzy time instead of a date is usually faster to read and understand.
 *
 *     $span = Phalcon\Utils\PHALCON_DATE_fuzzy_span(time() - 10); // "moments ago"
 *     $span = Phalcon\Utils\PHALCON_DATE_fuzzy_span(time() + 20); // "in moments"
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
	zval *timestamp, *local_timestamp = NULL;
	zval *span;
	long now_time, local_time, offset;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &timestamp, &local_timestamp);

	now_time = phalcon_get_intval(timestamp);

	if (!local_timestamp || Z_TYPE_P(local_timestamp) == IS_NULL) {
		local_time = (long) time(NULL);
	} else {
		local_time = phalcon_get_intval(local_timestamp);
	}

	// Determine the difference in seconds
	offset = local_time - now_time;
	if (offset < 0) {
		offset *= -1;
	}

	PHALCON_INIT_VAR(span);

	if (offset <= PHALCON_DATE_MINUTE) {
		ZVAL_STRING(span, "moments", 1);
	} else if (offset < (PHALCON_DATE_MINUTE * 20)) {
		ZVAL_STRING(span, "a few minutes", 1);
	} else if (offset <  PHALCON_DATE_HOUR) {
		ZVAL_STRING(span, "less than an hour", 1);
	} else if (offset < (PHALCON_DATE_HOUR * 4)) {
		ZVAL_STRING(span, "a couple of hours", 1);
	} else if (offset < PHALCON_DATE_DAY) {
		ZVAL_STRING(span, "less than a day", 1);
	} else if (offset < (PHALCON_DATE_DAY * 2)) {
		ZVAL_STRING(span, "about a day", 1);
	} else if (offset < (PHALCON_DATE_DAY * 4)) {
		ZVAL_STRING(span, "a couple of days", 1);
	} else if (offset < PHALCON_DATE_WEEK) {
		ZVAL_STRING(span, "less than a week", 1);
	} else if (offset < (PHALCON_DATE_WEEK * 2)) {
		ZVAL_STRING(span, "about a week", 1);
	} else if (offset < PHALCON_DATE_MONTH) {
		ZVAL_STRING(span, "less than a month", 1);
	} else if (offset < (PHALCON_DATE_MONTH * 2)) {
		ZVAL_STRING(span, "about a month", 1);
	} else if (offset < (PHALCON_DATE_MONTH * 4)) {
		ZVAL_STRING(span, "a couple of months", 1);
	} else if (offset < PHALCON_DATE_YEAR) {
		ZVAL_STRING(span, "less than a year", 1);
	} else if (offset < (PHALCON_DATE_YEAR * 2)) {
		ZVAL_STRING(span, "about a year", 1);
	} else if (offset < (PHALCON_DATE_YEAR * 4)) {
		ZVAL_STRING(span, "a couple of years", 1);
	} else if (offset < (PHALCON_DATE_YEAR * 8)) {
		ZVAL_STRING(span, "a few years", 1);
	} else if (offset < (PHALCON_DATE_YEAR * 12)) {
		ZVAL_STRING(span, "about a decade", 1);
	} else if (offset < (PHALCON_DATE_YEAR * 24)) {
		ZVAL_STRING(span, "a couple of decades", 1);
	} else if (offset < (PHALCON_DATE_YEAR * 64)) {
		ZVAL_STRING(span, "several decades", 1);
	} else {
		ZVAL_STRING(span, "a long time", 1);
	}

	if (now_time <= local_time) {
		// This is in the past
		PHALCON_CONCAT_VS(return_value, span, " ago");
	} else {
		// This in the future
		PHALCON_CONCAT_SV(return_value, "in ", span);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Converts a UNIX timestamp to DOS format. There are very few cases where
 * this is needed, but some binary formats use it (eg: zip files.)
 * Converting the other direction is done using {@link PHALCON_DATE_dos2unix}.
 *
 *     $dos = Phalcon\Utils\PHALCON_DATE_unix2dos($unix);
 *
 * @param int $timestamp
 * @return int
 */
PHP_METHOD(Phalcon_Utils_Date, unix2dos){

	zval *timestamp = NULL, *day, *year, *mon, *mday, *hours, *minutes, *seconds;
	int y, m, d, h, min, sec;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &timestamp);

	PHALCON_INIT_VAR(day);
	if (!timestamp || (Z_TYPE_P(timestamp) == IS_BOOL && !zend_is_true(timestamp))) {
		phalcon_call_func(day, "getdate");
	} else {
		phalcon_call_func_p1(day, "getdate", timestamp);
	}

	PHALCON_OBS_VAR(year);
	phalcon_array_fetch_string(&year, day, SL("year"), PH_NOISY);

	PHALCON_OBS_VAR(mon);
	phalcon_array_fetch_string(&mon, day, SL("mon"), PH_NOISY);

	PHALCON_OBS_VAR(mday);
	phalcon_array_fetch_string(&mday, day, SL("mday"), PH_NOISY);
	
	PHALCON_OBS_VAR(hours);
	phalcon_array_fetch_string(&hours, day, SL("hours"), PH_NOISY);
	
	PHALCON_OBS_VAR(minutes);
	phalcon_array_fetch_string(&minutes, day, SL("minutes"), PH_NOISY);
	
	PHALCON_OBS_VAR(seconds);
	phalcon_array_fetch_string(&seconds, day, SL("seconds"), PH_NOISY);

	y = phalcon_get_intval(year);
	m = phalcon_get_intval(mon);
	d = phalcon_get_intval(mday);
	h = phalcon_get_intval(hours);
	min = phalcon_get_intval(minutes);
	sec = phalcon_get_intval(seconds);

	if (y < 1980) {
		ZVAL_LONG(return_value, (1 << 21 | 1 << 16));
	} else {
		y -= 1980;
		ZVAL_LONG(return_value, (y << 25 | m  << 21 | d  << 16 | h  << 11 | min << 5 | sec >> 1));
	}

	PHALCON_MM_RESTORE();
}

/**
 * Converts a DOS timestamp to UNIX format.There are very few cases where
 * this is needed, but some binary formats use it (eg: zip files.)
 * Converting the other direction is done using {@link PHALCON_DATE_unix2dos}.
 *
 *     $unix = Phalcon\Utils\PHALCON_DATE_dos2unix($dos);
 *
 * @param int $timestamp
 * @return int
 */
PHP_METHOD(Phalcon_Utils_Date, dos2unix){
	
	zval *timestamp = NULL;
	zval *hrs, *min, *sec, *mon, *day, *year;
	long t = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &timestamp);

	if (timestamp) {
		t = phalcon_get_intval(timestamp);
	}

	PHALCON_INIT_VAR(sec);
	ZVAL_LONG(sec, (2 * (t & 0x1f)));

	PHALCON_INIT_VAR(min);
	ZVAL_LONG(min, ((t >>  5) & 0x3f));

	PHALCON_INIT_VAR(hrs);
	ZVAL_LONG(hrs, ((t >> 11) & 0x1f));

	PHALCON_INIT_VAR(day);
	ZVAL_LONG(day, ((t >> 16) & 0x1f));

	PHALCON_INIT_VAR(mon);
	ZVAL_LONG(mon, ((t >> 21) & 0x0f));

	PHALCON_INIT_VAR(year);
	ZVAL_LONG(year, (((t >> 25) & 0x7f)+1980));

	phalcon_call_func_p6(return_value, "mktime", hrs, min, sec, mon, day, year);

	PHALCON_MM_RESTORE();
}

/**
 * Returns a date/time string with the specified timestamp format
 *
 *     $time = Phalcon\Utils\PHALCON_DATE_formatted_time('5 minutes ago');
 *
 * @param string $datetime_str
 * @param string $timestamp_format
 * @param string $timezone
 * @return string
 */
PHP_METHOD(Phalcon_Utils_Date, formatted_time){
}
