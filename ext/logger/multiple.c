
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Logger\Multiple
 *
 * Handles multiples logger handlers
 */


/**
 * Phalcon\Logger\Multiple initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Multiple){

	PHALCON_REGISTER_CLASS(Phalcon\\Logger, Multiple, logger_multiple, phalcon_logger_multiple_method_entry, 0);

	zend_declare_property_null(phalcon_logger_multiple_ce, SL("_loggers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_multiple_ce, SL("_formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Pushes a logger to the logger tail
 *
 * @param Phalcon\Logger\AdapterInterface $logger
 */
PHP_METHOD(Phalcon_Logger_Multiple, push){

	zval *logger;

	phalcon_fetch_params(0, 1, 0, &logger);
	
	if (Z_TYPE_P(logger) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "The logger is invalid");
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_loggers"), logger TSRMLS_CC);
	
}

/**
 * Returns the registered loggers
 *
 * @return Phalcon\Logger\AdapterInterface[]
 */
PHP_METHOD(Phalcon_Logger_Multiple, getLoggers){


	RETURN_MEMBER(this_ptr, "_loggers");
}

/**
 * Sets a global formatter
 *
 * @param Phalcon\Logger\FormatterInterface $formatter
 */
PHP_METHOD(Phalcon_Logger_Multiple, setFormatter){

	zval *formatter, *loggers, *logger = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &formatter);
	
	PHALCON_OBS_VAR(loggers);
	phalcon_read_property_this(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(loggers) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(loggers, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(logger);
	
			phalcon_call_method_p1_noret(logger, "setformatter", formatter);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	phalcon_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a formatter
 *
 * @return Phalcon\Logger\FormatterInterface
 */
PHP_METHOD(Phalcon_Logger_Multiple, getFormatter){


	RETURN_MEMBER(this_ptr, "_formatter");
}

/**
 * Sends a message to each registered logger
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Multiple, log){

	zval *message, *type = NULL, *loggers, *logger = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &type);
	
	if (!type) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 7);
	}
	
	PHALCON_OBS_VAR(loggers);
	phalcon_read_property_this(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(loggers) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(loggers, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(logger);
	
			phalcon_call_method_p2_noret(logger, "log", message, type);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an emergence message to the log
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Logger_Multiple, emergence){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("EMERGENCE") TSRMLS_CC);
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes a debug message to the log
 *
 * @param string $message
 * @param ing $type
 */
PHP_METHOD(Phalcon_Logger_Multiple, debug){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("DEBUG") TSRMLS_CC);
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an error message to the log
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Logger_Multiple, error){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("ERROR") TSRMLS_CC);
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an info message to the log
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Logger_Multiple, info){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("INFO") TSRMLS_CC);
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes a notice message to the log
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Logger_Multiple, notice){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("NOTICE") TSRMLS_CC);
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes a warning message to the log
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Logger_Multiple, warning){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("WARNING") TSRMLS_CC);
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an alert message to the log
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Logger_Multiple, alert){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("ALERT") TSRMLS_CC);
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
}

