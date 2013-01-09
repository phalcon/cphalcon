
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

/**
 * Phalcon\Logger\Adapter
 *
 * Base class for Phalcon\Logger adapters
 */


/**
 * Phalcon\Logger\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Logger, Adapter, logger_adapter, phalcon_logger_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_string(phalcon_logger_adapter_ce, SL("_dateFormat"), "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_ce, SL("_format"), "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Set the log format
 *
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Adapter, setFormat){

	zval *format;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &format) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_format"), format TSRMLS_CC);
	
}

/**
 * Returns the log format
 *
 * @return format
 */
PHP_METHOD(Phalcon_Logger_Adapter, getFormat){


	RETURN_MEMBER(this_ptr, "_format");
}

/**
 * Applies the internal format to the message
 *
 * @param  string $message
 * @param  int $type
 * @param  int $timestamp
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter, _applyFormat){

	zval *message, *type, *timestamp = NULL, *format = NULL, *date_format;
	zval *date, *date_wildcard, *new_format = NULL, *type_string;
	zval *type_wildcard, *message_wildcard;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &message, &type, &timestamp) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!timestamp) {
		PHALCON_INIT_VAR(timestamp);
		ZVAL_LONG(timestamp, 0);
	} else {
		PHALCON_SEPARATE_PARAM(timestamp);
	}
	
	if (!zend_is_true(timestamp)) {
		PHALCON_INIT_NVAR(timestamp);
		ZVAL_LONG(timestamp, (long) time(NULL));
	}
	
	PHALCON_OBS_VAR(format);
	phalcon_read_property(&format, this_ptr, SL("_format"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(date_format);
	phalcon_read_property(&date_format, this_ptr, SL("_dateFormat"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(date);
	PHALCON_CALL_FUNC_PARAMS_2(date, "date", date_format, timestamp);
	
	PHALCON_INIT_VAR(date_wildcard);
	ZVAL_STRING(date_wildcard, "%date%", 1);
	
	PHALCON_INIT_VAR(new_format);
	phalcon_fast_str_replace(new_format, date_wildcard, date, format TSRMLS_CC);
	
	PHALCON_INIT_VAR(type_string);
	PHALCON_CALL_METHOD_PARAMS_1(type_string, this_ptr, "gettypestring", type);
	
	PHALCON_INIT_VAR(type_wildcard);
	ZVAL_STRING(type_wildcard, "%type%", 1);
	
	PHALCON_INIT_NVAR(format);
	phalcon_fast_str_replace(format, type_wildcard, type_string, new_format TSRMLS_CC);
	
	PHALCON_INIT_VAR(message_wildcard);
	ZVAL_STRING(message_wildcard, "%message%", 1);
	
	PHALCON_INIT_NVAR(new_format);
	phalcon_fast_str_replace(new_format, message_wildcard, message, format TSRMLS_CC);
	
	RETURN_CTOR(new_format);
}

/**
 * Sets the internal date format
 *
 * @param string $date
 */
PHP_METHOD(Phalcon_Logger_Adapter, setDateFormat){

	zval *date;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &date) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dateFormat"), date TSRMLS_CC);
	
}

/**
 * Returns the internal date format
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter, getDateFormat){


	RETURN_MEMBER(this_ptr, "_dateFormat");
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter, getTypeString){

	zval *type, *type_str = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &type) == FAILURE) {
		RETURN_MM_NULL();
	}

	
	switch (phalcon_get_intval(type)) {
	
		case 7:
			PHALCON_INIT_VAR(type_str);
			ZVAL_STRING(type_str, "DEBUG", 1);
			break;
	
		case 3:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "ERROR", 1);
			break;
	
		case 4:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "WARNING", 1);
			break;
	
		case 1:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "CRITICAL", 1);
			break;
	
		case 8:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "CUSTOM", 1);
			break;
	
		case 2:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "ALERT", 1);
			break;
	
		case 5:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "NOTICE", 1);
			break;
	
		case 6:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "INFO", 1);
			break;
	
		case 0:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "EMERGENCE", 1);
			break;
	
		case 9:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "SPECIAL", 1);
			break;
	
		default:
			PHALCON_INIT_NVAR(type_str);
			ZVAL_STRING(type_str, "CUSTOM", 1);
	
	}
	RETURN_CTOR(type_str);
}

/**
  * Sends/Writes a debug message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger_Adapter, debug){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("DEBUG") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an error message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger_Adapter, error){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("ERROR") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an info message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger_Adapter, info){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("INFO") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes a notice message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger_Adapter, notice){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("NOTICE") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes a warning message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger_Adapter, warning){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("WARNING") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an alert message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger_Adapter, alert){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("ALERT") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
 * Logs a message
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Adapter, log){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &message, &type) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "This method must be implemented by an adapter");
	return;
}

