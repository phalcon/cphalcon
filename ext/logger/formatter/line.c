
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Logger\Formatter\Line
 *
 * Formats messages using an one-line string
 */


/**
 * Phalcon\Logger\Formatter\Line initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Line){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Line, logger_formatter_line, "phalcon\\logger\\formatter", phalcon_logger_formatter_line_method_entry, 0);

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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &format, &date_format);
	
	if (!format) {
		PHALCON_INIT_VAR(format);
	}
	
	if (!date_format) {
		PHALCON_INIT_VAR(date_format);
	}
	
	if (Z_TYPE_P(format) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_format"), format TSRMLS_CC);
	}
	if (Z_TYPE_P(date_format) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_dateFormat"), date_format TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
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
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Line, format){

	zval *message, *type, *timestamp, *format = NULL, *date_format;
	zval *date, *date_wildcard, *new_format = NULL, *type_string;
	zval *type_wildcard, *message_wildcard, *eol;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &message, &type, &timestamp);
	
	PHALCON_OBS_VAR(format);
	phalcon_read_property_this(&format, this_ptr, SL("_format"), PH_NOISY_CC);
	
	/** 
	 * Check if the format has the %date% placeholder
	 */
	if (phalcon_memnstr_str(format, SL("%date%") TSRMLS_CC)) {
		PHALCON_OBS_VAR(date_format);
		phalcon_read_property_this(&date_format, this_ptr, SL("_dateFormat"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(date);
		phalcon_call_func_p2(date, "date", date_format, timestamp);
	
		PHALCON_INIT_VAR(date_wildcard);
		ZVAL_STRING(date_wildcard, "%date%", 1);
	
		PHALCON_INIT_VAR(new_format);
		phalcon_fast_str_replace(new_format, date_wildcard, date, format TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(new_format, format);
	}
	
	/** 
	 * Check if the format has the %type% placeholder
	 */
	if (phalcon_memnstr_str(format, SL("%type%") TSRMLS_CC)) {
		PHALCON_INIT_VAR(type_string);
		phalcon_call_method_p1(type_string, this_ptr, "gettypestring", type);
	
		PHALCON_INIT_VAR(type_wildcard);
		ZVAL_STRING(type_wildcard, "%type%", 1);
	
		PHALCON_INIT_NVAR(format);
		phalcon_fast_str_replace(format, type_wildcard, type_string, new_format TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(format, new_format);
	}
	
	PHALCON_INIT_VAR(message_wildcard);
	ZVAL_STRING(message_wildcard, "%message%", 1);
	
	PHALCON_INIT_NVAR(new_format);
	phalcon_fast_str_replace(new_format, message_wildcard, message, format TSRMLS_CC);
	
	PHALCON_INIT_VAR(eol);
	ZVAL_STRING(eol, PHP_EOL, 1);
	
	PHALCON_INIT_NVAR(format);
	PHALCON_CONCAT_VV(format, new_format, eol);
	
	RETURN_CCTOR(format);
}

