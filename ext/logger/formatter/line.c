
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

#include "logger/formatter/line.h"
#include "logger/formatter.h"
#include "logger/formatterinterface.h"

#include <ext/date/php_date.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Logger\Formatter\Line
 *
 * Formats messages using an one-line string
 */
zend_class_entry *phalcon_logger_formatter_line_ce;

PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct);
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, setDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, getDateFormat);
PHP_METHOD(Phalcon_Logger_Formatter_Line, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, dateFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_setdateformat, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_logger_formatter_line_method_entry[] = {
	PHP_ME(Phalcon_Logger_Formatter_Line, __construct, arginfo_phalcon_logger_formatter_line___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Formatter_Line, setFormat, arginfo_phalcon_logger_formatter_line_setformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, getFormat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, setDateFormat, arginfo_phalcon_logger_formatter_line_setdateformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, getDateFormat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, format, arginfo_phalcon_logger_formatterinterface_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Logger\Formatter\Line initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Line){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Line, logger_formatter_line, phalcon_logger_formatter_ce, phalcon_logger_formatter_line_method_entry, 0);

	zend_declare_property_string(phalcon_logger_formatter_line_ce, SL("_dateFormat"), "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_formatter_line_ce, SL("_format"), "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_formatter_line_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Logger\Formatter\Line construct
 *
 * @param string $format
 * @param string $dateFormat
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct){

	zval *format = NULL, *date_format = NULL;

	phalcon_fetch_params(0, 0, 2, &format, &date_format);
	
	if (format && Z_TYPE_P(format) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_format"), format TSRMLS_CC);
	}

	if (date_format && Z_TYPE_P(date_format) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_dateFormat"), date_format TSRMLS_CC);
	}
}

/**
 * Set the log format
 *
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat){

	zval *format;

	phalcon_fetch_params(0, 1, 0, &format);
	
	phalcon_update_property_this(this_ptr, SL("_format"), format TSRMLS_CC);
	
}

/**
 * Returns the log format
 *
 * @return format
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat){


	RETURN_MEMBER(this_ptr, "_format");
}

/**
 * Sets the internal date format
 *
 * @param string $date
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, setDateFormat){

	zval *date;

	phalcon_fetch_params(0, 1, 0, &date);
	
	phalcon_update_property_this(this_ptr, SL("_dateFormat"), date TSRMLS_CC);
	
}

/**
 * Returns the internal date format
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, getDateFormat){


	RETURN_MEMBER(this_ptr, "_dateFormat");
}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @param array $context
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, format){

	zval *message, *type, *timestamp, *context, *format = NULL, *date_format;
	zval *date, *date_wildcard, *new_format = NULL, *type_string = NULL;
	zval *type_wildcard, *message_wildcard;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &message, &type, &timestamp, &context);
	
	PHALCON_OBS_VAR(format);
	phalcon_read_property_this(&format, this_ptr, SL("_format"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Check if the format has the %date% placeholder
	 */
	if (phalcon_memnstr_str(format, SL("%date%"))) {
		date_format = phalcon_fetch_nproperty_this(this_ptr, SL("_dateFormat"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_VAR(date);
		phalcon_date(date, date_format, timestamp TSRMLS_CC);
	
		PHALCON_INIT_VAR(date_wildcard);
		ZVAL_STRING(date_wildcard, "%date%", 1);
	
		PHALCON_INIT_VAR(new_format);
		phalcon_fast_str_replace(new_format, date_wildcard, date, format);
	} else {
		PHALCON_CPY_WRT(new_format, format);
	}
	
	/** 
	 * Check if the format has the %type% placeholder
	 */
	if (phalcon_memnstr_str(format, SL("%type%"))) {
		PHALCON_CALL_METHOD(&type_string, this_ptr, "gettypestring", type);
	
		PHALCON_INIT_VAR(type_wildcard);
		ZVAL_STRING(type_wildcard, "%type%", 1);
	
		PHALCON_INIT_NVAR(format);
		phalcon_fast_str_replace(format, type_wildcard, type_string, new_format);
	} else {
		PHALCON_CPY_WRT(format, new_format);
	}
	
	PHALCON_INIT_VAR(message_wildcard);
	ZVAL_STRING(message_wildcard, "%message%", 1);
	
	PHALCON_INIT_NVAR(new_format);
	phalcon_fast_str_replace(new_format, message_wildcard, message, format);
	
	if (Z_TYPE_P(context) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_P(context)) > 0) {
		PHALCON_CALL_METHOD(&format, this_ptr, "interpolate", new_format, context);
	}
	else {
		PHALCON_CPY_WRT(format, new_format);
	}

	PHALCON_CONCAT_VS(return_value, format, PHP_EOL);
	RETURN_MM();
}
