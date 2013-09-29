
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
#ifndef PHALCON_UTILS_DATE_H
#define PHALCON_UTILS_DATE_H

#include "php_phalcon.h"

/* Second amounts for various time increments */
#define PHALCON_DATE_YEAR          31556926
#define PHALCON_DATE_MONTH         2629744
#define PHALCON_DATE_WEEK          604800
#define PHALCON_DATE_DAY           86400
#define PHALCON_DATE_HOUR          3600
#define PHALCON_DATE_MINUTE        60

/* Available formats for Phalcon\Utils\Date::months() */
#define PHALCON_DATE_MONTHS_LONG   "%B"
#define PHALCON_DATE_MONTHS_SHORT  "%b"

extern zend_class_entry *phalcon_utils_date_ce;

PHALCON_INIT_CLASS(Phalcon_Utils_Date);

PHP_METHOD(Phalcon_Utils_Date, offset);
PHP_METHOD(Phalcon_Utils_Date, seconds);
PHP_METHOD(Phalcon_Utils_Date, minutes);
PHP_METHOD(Phalcon_Utils_Date, hours);
PHP_METHOD(Phalcon_Utils_Date, ampm);
PHP_METHOD(Phalcon_Utils_Date, adjust);
PHP_METHOD(Phalcon_Utils_Date, days);
PHP_METHOD(Phalcon_Utils_Date, months);
PHP_METHOD(Phalcon_Utils_Date, years);
PHP_METHOD(Phalcon_Utils_Date, span);
PHP_METHOD(Phalcon_Utils_Date, fuzzy_span);
PHP_METHOD(Phalcon_Utils_Date, unix2dos);
PHP_METHOD(Phalcon_Utils_Date, dos2unix);
PHP_METHOD(Phalcon_Utils_Date, formatted_time);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_offset, 0, 0, 1)
	ZEND_ARG_INFO(0, remote)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, now)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_seconds, 0, 0, 0)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_minutes, 0, 0, 0)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_hours, 0, 0, 0)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, long)
	ZEND_ARG_INFO(0, start)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_ampm, 0, 0, 1)
	ZEND_ARG_INFO(0, hour)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_adjust, 0, 0, 2)
	ZEND_ARG_INFO(0, hour)
	ZEND_ARG_INFO(0, ampm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_days, 0, 0, 1)
	ZEND_ARG_INFO(0, month)
	ZEND_ARG_INFO(0, year)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_months, 0, 0, 0)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_years, 0, 0, 0)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_span, 0, 0, 1)
	ZEND_ARG_INFO(0, remote)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_fuzzy_span, 0, 0, 1)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, local_timestamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_unix2dos, 0, 0, 0)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_dos2unix, 0, 0, 0)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_date_formatted_time, 0, 0, 0)
	ZEND_ARG_INFO(0, datetime_str)
	ZEND_ARG_INFO(0, timestamp_format)
	ZEND_ARG_INFO(0, timezone)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_utils_date_method_entry){
	PHP_ME(Phalcon_Utils_Date, offset, arginfo_phalcon_utils_date_offset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, seconds, arginfo_phalcon_utils_date_seconds, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, minutes, arginfo_phalcon_utils_date_minutes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, hours, arginfo_phalcon_utils_date_hours, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, adjust, arginfo_phalcon_utils_date_adjust, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, ampm, arginfo_phalcon_utils_date_ampm, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, days, arginfo_phalcon_utils_date_days, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, months, arginfo_phalcon_utils_date_months, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, years, arginfo_phalcon_utils_date_years, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, span, arginfo_phalcon_utils_date_span, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, fuzzy_span, arginfo_phalcon_utils_date_fuzzy_span, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, unix2dos, arginfo_phalcon_utils_date_unix2dos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, dos2unix, arginfo_phalcon_utils_date_dos2unix, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Utils_Date, formatted_time, arginfo_phalcon_utils_date_formatted_time, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};

#endif /* PHALCON_UTILS_DATE_H */