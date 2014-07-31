
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "date.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Date
 *
 * Provides utilities to work with dates
 */
zend_class_entry *phalcon_date_ce;

PHP_METHOD(Phalcon_Date, offset);
PHP_METHOD(Phalcon_Date, seconds);
PHP_METHOD(Phalcon_Date, minutes);
PHP_METHOD(Phalcon_Date, hours);
PHP_METHOD(Phalcon_Date, ampm);
PHP_METHOD(Phalcon_Date, adjust);
PHP_METHOD(Phalcon_Date, days);
PHP_METHOD(Phalcon_Date, months);
PHP_METHOD(Phalcon_Date, years);
PHP_METHOD(Phalcon_Date, span);
PHP_METHOD(Phalcon_Date, span2);
PHP_METHOD(Phalcon_Date, fuzzy_span);
PHP_METHOD(Phalcon_Date, fuzzy_span2);
PHP_METHOD(Phalcon_Date, unix2dos);
PHP_METHOD(Phalcon_Date, dos2unix);
PHP_METHOD(Phalcon_Date, formatted_time);
PHP_METHOD(Phalcon_Date, valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_offset, 0, 0, 1)
	ZEND_ARG_INFO(0, remote)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, now)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_seconds, 0, 0, 0)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_minutes, 0, 0, 0)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_hours, 0, 0, 0)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, long)
	ZEND_ARG_INFO(0, start)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_ampm, 0, 0, 1)
	ZEND_ARG_INFO(0, hour)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_adjust, 0, 0, 2)
	ZEND_ARG_INFO(0, hour)
	ZEND_ARG_INFO(0, ampm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_days, 0, 0, 1)
	ZEND_ARG_INFO(0, month)
	ZEND_ARG_INFO(0, year)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_months, 0, 0, 0)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_years, 0, 0, 0)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_span, 0, 0, 1)
	ZEND_ARG_INFO(0, remote)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_span2, 0, 0, 1)
	ZEND_ARG_INFO(0, remote)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_fuzzy_span, 0, 0, 1)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, local_timestamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_fuzzy_span2, 0, 0, 1)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_unix2dos, 0, 0, 0)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_dos2unix, 0, 0, 0)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_formatted_time, 0, 0, 0)
	ZEND_ARG_INFO(0, datetime_str)
	ZEND_ARG_INFO(0, timestamp_format)
	ZEND_ARG_INFO(0, timezone)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_date_valid, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_date_method_entry[] = {
	PHP_ME(Phalcon_Date, offset, arginfo_phalcon_date_offset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, seconds, arginfo_phalcon_date_seconds, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, minutes, arginfo_phalcon_date_minutes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, hours, arginfo_phalcon_date_hours, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, adjust, arginfo_phalcon_date_adjust, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, ampm, arginfo_phalcon_date_ampm, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, days, arginfo_phalcon_date_days, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, months, arginfo_phalcon_date_months, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, years, arginfo_phalcon_date_years, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, span, arginfo_phalcon_date_span, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, span2, arginfo_phalcon_date_span2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, fuzzy_span, arginfo_phalcon_date_fuzzy_span, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, fuzzy_span2, arginfo_phalcon_date_fuzzy_span2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, unix2dos, arginfo_phalcon_date_unix2dos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, dos2unix, arginfo_phalcon_date_dos2unix, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, formatted_time, arginfo_phalcon_date_formatted_time, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Date, valid, arginfo_phalcon_date_valid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Date initializer
 */
PHALCON_INIT_CLASS(Phalcon_Date){

	PHALCON_REGISTER_CLASS(Phalcon, Date, date, phalcon_date_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_date_ce, SL("YEAR"),   PHALCON_DATE_YEAR TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_date_ce, SL("MONTH"),  PHALCON_DATE_MONTH TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_date_ce, SL("WEEK"),   PHALCON_DATE_WEEK TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_date_ce, SL("DAY"),    PHALCON_DATE_DAY TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_date_ce, SL("HOUR"),   PHALCON_DATE_HOUR TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_date_ce, SL("MINUTE"), PHALCON_DATE_MINUTE TSRMLS_CC);

	zend_declare_class_constant_stringl(phalcon_date_ce, SL("MONTHS_LONG"),  SL(PHALCON_DATE_MONTHS_LONG) TSRMLS_CC);
	zend_declare_class_constant_stringl(phalcon_date_ce, SL("MONTHS_SHORT"), SL(PHALCON_DATE_MONTHS_SHORT) TSRMLS_CC);

	zend_declare_property_string(phalcon_date_ce, SL("timestamp_format"), "Y-m-d H:i:s", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_date_ce, SL("timezone"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_date_ce, SL("_months"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;
}

/**
 * Returns the offset (in seconds) between two time zones. Use this to
 * display dates to users in different time zones.
 *
 *     $seconds = Phalcon\Date::offset('America/Chicago', 'GMT');
 *
 * @param string $remote
 * @param string $local
 * @param mixed $now
 * @return int
 */
PHP_METHOD(Phalcon_Date, offset){

	zval *remote, *local = NULL, *now = NULL;
	zval *format, *tmp = NULL, *zone_remote, *zone_local, *time_remote, *time_local, *offset_remote = NULL, *offset_local = NULL;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &remote, &local, &now);

	ce0 = zend_fetch_class(SL("DateTime"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ce1 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	if (!local) {
		PHALCON_CALL_FUNCTION(&local, "date_default_timezone_get");
	}

	if (!now) {
		PHALCON_INIT_VAR(now);
	} else if (Z_TYPE_P(now) == IS_LONG) {
		PHALCON_SEPARATE_PARAM(now);

		PHALCON_INIT_VAR(format);
		phalcon_get_class_constant(format, ce0, SS("RFC2822") TSRMLS_CC);

		PHALCON_CALL_FUNCTION(&tmp, "date", format, now);

		PHALCON_CPY_WRT(now, tmp);
	}

	PHALCON_INIT_VAR(zone_remote);
	object_init_ex(zone_remote, ce1);
	if (phalcon_has_constructor(zone_remote TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, zone_remote, "__construct", remote);
	}

	PHALCON_INIT_VAR(zone_local);
	object_init_ex(zone_local, ce1);
	if (phalcon_has_constructor(zone_local TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, zone_local, "__construct", local);
	}

	PHALCON_INIT_VAR(time_remote);
	object_init_ex(time_remote, ce0);
	if (phalcon_has_constructor(time_remote TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, time_remote, "__construct", now, zone_remote);
	}

	PHALCON_INIT_VAR(time_local);
	object_init_ex(time_local, ce0);
	if (phalcon_has_constructor(time_local TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, time_local, "__construct", now, zone_local);
	}

	PHALCON_CALL_METHOD(&offset_remote, zone_remote, "getOffset", time_remote);

	PHALCON_CALL_METHOD(&offset_local, zone_local, "getOffset", time_local);

	ZVAL_LONG(return_value, phalcon_get_intval(offset_remote)-phalcon_get_intval(offset_local));

	PHALCON_MM_RESTORE();
}

/**
 * Number of seconds in a minute, incrementing by a step. Typically used as
 * a shortcut for generating a list that can used in a form.
 *
 *     $seconds = Phalcon\Date::seconds(); // 00, 01, 02, 03, ..., 58, 59
 *
 * @param int $step
 * @param int $start
 * @param int $end
 * @return array
 */
PHP_METHOD(Phalcon_Date, seconds){

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
 *     $minutes = Phalcon\Date::minutes(); // 00, 05, 10, 15, ..., 50, 55
 *
 * @param int $step
 * @return array
 */
PHP_METHOD(Phalcon_Date, minutes){

	zval *step = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &step);

	if (!step) {
		PHALCON_INIT_VAR(step);
		ZVAL_LONG(step, 5);
	}

	PHALCON_RETURN_CALL_SELF("seconds", step);

	RETURN_MM();
}

/**
 * Number of hours in a day. Typically used as a shortcut for generating a
 * list that can be used in a form.
 *
 *     $hours = Phalcon\Date::hours(); // 01, 02, 03, ..., 10, 11, 12
 *
 * @param int $step
 * @param boolean $is_long
 * @param int $start
 * @return array
 */
PHP_METHOD(Phalcon_Date, hours){

	zval *step = NULL, *is_long = NULL, *start = NULL;
	char buf[2];
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
		sprintf(buf, "%02d", i);
		phalcon_array_update_long_string(&return_value, i, buf, 2, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Returns AM or PM, based on a given hour (in 24 hour format).
 *
 *     $type = Phalcon\Date::ampm(12); // PM
 *     $type = Phalcon\Date::ampm(1);  // AM
 *
 * @param int $hour
 * @return string
 */
PHP_METHOD(Phalcon_Date, ampm){

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
 *     $hour = Phalcon\Date::adjust(3, 'pm'); // 15
 *
 * @param int $hour
 * @param string $ampm
 * @return string
 */
PHP_METHOD(Phalcon_Date, adjust){	
	
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
 *     Phalcon\Date::days(4, 2010); // 1, 2, 3, ..., 28, 29, 30
 *
 * @param int $month
 * @param int $year
 * @return array
 */
PHP_METHOD(Phalcon_Date, days){

	zval *month, *year = NULL, *tmp = NULL, *tmp1, *tmp2, *total = NULL;
	zval *months;
	char buf[2];
	int y, m, i, t;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &month, &year);

	PHALCON_OBS_VAR(months);
	phalcon_read_static_property_ce(&months, phalcon_date_ce, SL("_months") TSRMLS_CC);

	if (!year) {
		PHALCON_INIT_VAR(year);
		ZVAL_FALSE(year);
	} else if (Z_TYPE_P(year) == IS_BOOL && !zend_is_true(year)) {
		PHALCON_SEPARATE_PARAM(year);

		PHALCON_INIT_VAR(tmp);
		ZVAL_STRING(tmp, "Y", 1);
		
		PHALCON_OBS_NVAR(year);
		PHALCON_CALL_FUNCTION(&year, "date", tmp);
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

	PHALCON_CALL_FUNCTION(&tmp, "mktime", tmp1, tmp2, tmp2, month, tmp1, year);	
	
	PHALCON_INIT_NVAR(tmp1);
	ZVAL_STRING(tmp1, "t", 1);

	PHALCON_CALL_FUNCTION(&total, "date", tmp1, tmp);

	t = phalcon_get_intval(total) + 1;

	PHALCON_INIT_NVAR(tmp);
	array_init(tmp);

	PHALCON_INIT_NVAR(months);
	array_init(months);

	phalcon_array_update_long(&months, y, tmp, PH_COPY | PH_SEPARATE);

	for (i = 1; i < t; i++) {
		sprintf(buf, "%02d", i);
		phalcon_array_update_long_string(&tmp, i, buf, 2, 0);
	}

	phalcon_array_update_long_long_multi_2(&months, y, m, tmp, PH_COPY | PH_SEPARATE);

	phalcon_update_static_property_ce(phalcon_date_ce, SL("_months"), months TSRMLS_CC);

	RETURN_CCTOR(tmp);
}

/**
 * Number of months in a year. Typically used as a shortcut for generating
 * a list that can be used in a form.
 *
 * By default a mirrored array of $month_number => $month_number is returned
 *
 *     Phalcon\Date::months();
 *     // aray(1 => 1, 2 => 2, 3 => 3, ..., 12 => 12)
 *
 * But you can customise this by passing in either PHALCON_DATE_MONTHS_LONG
 *
 *     Phalcon\Date::months(Phalcon\Utils\PHALCON_DATE_MONTHS_LONG);
 *     // array(1 => 'January', 2 => 'February', ..., 12 => 'December')
 *
 * Or PHALCON_DATE_MONTHS_SHORT
 *
 *     Phalcon\Date::months(Phalcon\Date::PHALCON_DATE_MONTHS_SHORT);
 *     // array(1 => 'Jan', 2 => 'Feb', ..., 12 => 'Dec')
 *
 * @uses PHALCON_DATE_hours
 * @param string $format
 * @return array
 */
PHP_METHOD(Phalcon_Date, months){

	zval *format = NULL, *tmp = NULL, *tmp1, *tmp2, *tmp3 = NULL, *value = NULL;
	int i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &format);

	if (format && (PHALCON_IS_STRING(format, PHALCON_DATE_MONTHS_LONG) || PHALCON_IS_STRING(format, PHALCON_DATE_MONTHS_SHORT))) {
		array_init(return_value);

		PHALCON_INIT_VAR(tmp1);
		ZVAL_LONG(tmp1, 0);

		PHALCON_INIT_VAR(tmp2);
		ZVAL_LONG(tmp2, 1);

		for (i = 1; i <= 12; ++i) {
			PHALCON_INIT_NVAR(tmp3);
			ZVAL_LONG(tmp3, i);

			PHALCON_CALL_FUNCTION(&tmp, "mktime", tmp1, tmp1, tmp1, tmp3, tmp2);
			PHALCON_CALL_FUNCTION(&value, "strftime", format, tmp);

			phalcon_array_update_long(&return_value, i, value, PH_COPY | PH_SEPARATE);
		}
	} else {
		PHALCON_RETURN_CALL_SELF("hours");
	}

	RETURN_MM();
}

/**
 * Returns an array of years between a starting and ending year. By default,
 * the the current year - 5 and current year + 5 will be used. Typically used
 * as a shortcut for generating a list that can be used in a form.
 *
 *     $years = Phalcon\Date::years(2000, 2010); // 2000, 2001, ..., 2009, 2010
 *
 * @param int $start
 * @param int $end
 * @return array
 */
PHP_METHOD(Phalcon_Date, years){

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
		
		PHALCON_OBS_NVAR(start);
		PHALCON_CALL_FUNCTION(&start, "date", tmp);

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
		
		PHALCON_OBS_NVAR(end);
		PHALCON_CALL_FUNCTION(&end, "date", tmp);

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
 * Also consider using [Phalcon\Date::fuzzy_span] when displaying a span.
 *
 *     $span = Phalcon\Date::span(60, 182, 'minutes,seconds'); // array('minutes' => 2, 'seconds' => 2)
 *     $span = Phalcon\Date::span(60, 182, 'minutes'); // 2
 *
 * @param int $remote
 * @param int $local
 * @param string $output
 * @return string/array
 */
PHP_METHOD(Phalcon_Date, span){

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

	PHALCON_CALL_FUNCTION(&output, "preg_split", pattern, lowercased_output);

	PHALCON_INIT_VAR(tmp1);
	ZVAL_LONG(tmp1, 0);

	PHALCON_INIT_VAR(count_output);
	phalcon_fast_count(count_output, output TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&tmp, "array_fill", tmp1, count_output, tmp1);

	PHALCON_CPY_WRT(tmp1, output);

	PHALCON_CALL_FUNCTION(&output, "array_combine", tmp1, tmp);

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
		PHALCON_RETURN_CALL_FUNCTION("array_pop", output);
		RETURN_MM();
	}

	RETURN_CCTOR(output);
}

/**
 * Returns time, in human readable format.
 * Also consider using [Phalcon\Date::fuzzy_span2] when displaying a span.
 *
 *     $span = Phalcon\Date::span(182, 'minutes,seconds'); // array('minutes' => 3, 'seconds' => 2)
 *     $span = Phalcon\Date::span(182, 'minutes'); // 3
 *
 * @param int $time
 * @param string $output
 * @return string/array
 */
PHP_METHOD(Phalcon_Date, span2){

	zval *time, *output = NULL;
	zval *lowercased_output, *count_output, *tmp = NULL, *tmp1, *pattern;
	long timespan;
	int i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &time, &output);

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

	PHALCON_OBS_NVAR(output);
	PHALCON_CALL_FUNCTION(&output, "preg_split", pattern, lowercased_output);

	PHALCON_INIT_VAR(tmp1);
	ZVAL_LONG(tmp1, 0);

	PHALCON_INIT_VAR(count_output);
	phalcon_fast_count(count_output, output TSRMLS_CC);

	PHALCON_OBS_NVAR(tmp);
	PHALCON_CALL_FUNCTION(&tmp, "array_fill", tmp1, count_output, tmp1);

	PHALCON_CPY_WRT(tmp1, output);

	PHALCON_OBS_NVAR(output);
	PHALCON_CALL_FUNCTION(&output, "array_combine", tmp1, tmp);

	timespan = phalcon_get_intval(time);

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
		PHALCON_CALL_FUNCTION(return_value_ptr, "array_pop", output);
		Z_UNSET_ISREF_P(output);
		RETURN_MM();
	}

	RETURN_CCTOR(output);
}

/**
 * Returns the difference between a time and now in a "fuzzy" way.
 * Displaying a fuzzy time instead of a date is usually faster to read and understand.
 *
 *     $span = Phalcon\Date::fuzzy_span(time() - 10); // "moments ago"
 *     $span = Phalcon\Date::fuzzy_span(time() + 20); // "in moments"
 *
 * A second parameter is available to manually set the "local" timestamp,
 * however this parameter shouldn't be needed in normal usage and is only
 * included for unit tests
 *
 * @param int $timestamp
 * @param int $local_timestamp
 * @return string
 */
PHP_METHOD(Phalcon_Date, fuzzy_span){
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
 * Returns the time in a "fuzzy" way.
 * Displaying a fuzzy time instead of a date is usually faster to read and understand.
 *
 *     $span = Phalcon\Date::fuzzy_span2(60); // "1 minutes"
 *     $span = Phalcon\Date::fuzzy_span2(10); // "10 seconds"
 *
 * A second parameter is available to manually set the "local" timestamp,
 * however this parameter shouldn't be needed in normal usage and is only
 * included for unit tests
 *
 * @param int $timestamp
 * @param string $output
 * @return string
 */
PHP_METHOD(Phalcon_Date, fuzzy_span2){
	zval *timestamp, *output = NULL;
	zval *span, *label = NULL;
	long offset, hours, minutes, seconds;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &timestamp, &output);

	offset = phalcon_get_intval(timestamp);
	if (offset < 0) {
		offset *= -1;
	}

	if (!output) {
		PHALCON_INIT_NVAR(output);
		array_init_size(output, 7);
		phalcon_array_append_string(&output, SL(" years"), 0);
		phalcon_array_append_string(&output, SL(" months"), 0);
		phalcon_array_append_string(&output, SL(" weeks"), 0);
		phalcon_array_append_string(&output, SL(" days"), 0);
		phalcon_array_append_string(&output, SL(" hours"), 0);
		phalcon_array_append_string(&output, SL(" minutes"), 0);
		phalcon_array_append_string(&output, SL(" seconds"), 0);
	}

	hours = offset / PHALCON_DATE_HOUR;
	minutes = (offset % PHALCON_DATE_HOUR) / PHALCON_DATE_MINUTE;
	seconds = offset % PHALCON_DATE_MINUTE;

	PHALCON_INIT_VAR(span);
	if (hours > 0 && phalcon_array_isset_long(output, 4)) {
		ZVAL_LONG(span, hours);

		PHALCON_INIT_NVAR(label);
		phalcon_array_fetch_long(&label, output, 4, PH_NOISY);

		PHALCON_SCONCAT_VV(return_value, span, label);
	}
	if (minutes > 0) {
		ZVAL_LONG(span, minutes);

		PHALCON_INIT_NVAR(label);
		phalcon_array_fetch_long(&label, output, 5, PH_NOISY);

		PHALCON_SCONCAT_VV(return_value, span, label);
	}
	if (seconds > 0) {
		ZVAL_LONG(span, seconds);

		PHALCON_INIT_NVAR(label);
		phalcon_array_fetch_long(&label, output, 6, PH_NOISY);

		PHALCON_SCONCAT_VV(return_value, span, label);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Converts a UNIX timestamp to DOS format. There are very few cases where
 * this is needed, but some binary formats use it (eg: zip files.)
 * Converting the other direction is done using {@link PHALCON_DATE_dos2unix}.
 *
 *     $dos = Phalcon\Date::unix2dos($unix);
 *
 * @param int $timestamp
 * @return int
 */
PHP_METHOD(Phalcon_Date, unix2dos){

	zval *timestamp = NULL, *day = NULL, *year, *mon, *mday, *hours, *minutes, *seconds;
	int y, m, d, h, min, sec;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &timestamp);

	
	if (!timestamp || (Z_TYPE_P(timestamp) == IS_BOOL && !zend_is_true(timestamp))) {
		PHALCON_CALL_FUNCTION(&day, "getdate");
	} else {
		PHALCON_CALL_FUNCTION(&day, "getdate", timestamp);
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
 *
 *     $unix = Phalcon\Date::dos2unix($dos);
 *
 * @param int $timestamp
 * @return int
 */
PHP_METHOD(Phalcon_Date, dos2unix){
	
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

	PHALCON_RETURN_CALL_FUNCTION("mktime", hrs, min, sec, mon, day, year);

	PHALCON_MM_RESTORE();
}

/**
 * Returns a date/time string with the specified timestamp format
 *
 *     $time = Phalcon\Date::formatted_time('5 minutes ago');
 *
 * @param string $datetime_str
 * @param string $timestamp_format
 * @param string $timezone
 * @return string
 */
PHP_METHOD(Phalcon_Date, formatted_time){
	
	zval *datetime_str = NULL, *timestamp_format = NULL, *timezone = NULL, *tz, *dt, *tmp = NULL, *tmp1 = NULL;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &datetime_str, &timestamp_format, &timezone);

	ce0 = zend_fetch_class(SL("DateTimeZone"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ce1 = zend_fetch_class(SL("DateTime"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

	if (!datetime_str) {
		PHALCON_INIT_VAR(datetime_str);
		ZVAL_STRING(datetime_str, "now", 1);
	}

	if (!timestamp_format) {
		PHALCON_OBS_VAR(timestamp_format);
		phalcon_read_static_property_ce(&timestamp_format, phalcon_date_ce, SL("timestamp_format") TSRMLS_CC);
	} else if (Z_TYPE_P(timestamp_format) == IS_NULL) {
		PHALCON_SEPARATE_PARAM(timestamp_format);

		PHALCON_OBS_NVAR(timestamp_format);
		phalcon_read_static_property_ce(&timestamp_format, phalcon_date_ce, SL("timestamp_format") TSRMLS_CC);
	}

	if (!timezone) {
		PHALCON_OBS_VAR(timezone);
		phalcon_read_static_property_ce(&timezone, phalcon_date_ce, SL("timezone") TSRMLS_CC);
	} else if (Z_TYPE_P(timezone) == IS_NULL) {
		PHALCON_SEPARATE_PARAM(timezone);

		PHALCON_OBS_NVAR(timezone);
		phalcon_read_static_property_ce(&timezone, phalcon_date_ce, SL("timezone") TSRMLS_CC);
	} else {
		PHALCON_SEPARATE_PARAM(timezone);
	}
	
	if (!zend_is_true(timezone)) {
		PHALCON_CALL_FUNCTION(&timezone, "date_default_timezone_get");
	}

	PHALCON_INIT_VAR(tz);
	object_init_ex(tz, ce0);
	if (phalcon_has_constructor(tz TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, tz, "__construct", timezone);
	}

	PHALCON_INIT_VAR(dt);
	object_init_ex(dt, ce1);
	if (phalcon_has_constructor(dt TSRMLS_CC)) {
		PHALCON_CALL_METHOD(NULL, dt, "__construct", datetime_str, tz);
	}

	PHALCON_CALL_METHOD(&tmp, dt, "getTimeZone");
	PHALCON_CALL_METHOD(&tmp1, tmp, "getName");
	PHALCON_CALL_METHOD(&tmp, tz, "getName");

	if (PHALCON_IS_EQUAL(tmp1, tmp)) {
		PHALCON_CALL_METHOD(NULL, dt, "setTimeZone", tz);
	}

	PHALCON_RETURN_CALL_METHOD(dt, "format", timestamp_format);

	PHALCON_MM_RESTORE();
}

/**
 * Returns a date/time string with the specified timestamp format
 *
 *     $ret = Phalcon\Date::valid('2012-01-22');
 *     $ret = Phalcon\Date::valid('2012-01-22 11:00:00', 'Y-m-d H:i:s');
 *
 * @param string $date_str
 * @param string $date_format
 * @return string
 */
PHP_METHOD(Phalcon_Date, valid){
	
	zval *date = NULL, *format = NULL, *time = NULL, *format_date = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &date, &format);

	if (!format) {
		PHALCON_INIT_VAR(format);
		ZVAL_STRING(format, "Y-m-d", 1);
	}

	
	PHALCON_CALL_FUNCTION(&time, "strtotime", date);
	PHALCON_CALL_FUNCTION(&format_date, "date", format, time);

	if (phalcon_is_equal(date, format_date TSRMLS_CC)) {
		RETURN_MM_TRUE;
	} else {
		RETURN_MM_FALSE;
	}
}
