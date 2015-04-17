
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

#include "logger/multiple.h"
#include "logger/adapterinterface.h"
#include "logger/exception.h"
#include "logger.h"
#include "psr/log/invalidargumentexception.h"

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
zend_class_entry *phalcon_logger_multiple_ce;

PHP_METHOD(Phalcon_Logger_Multiple, push);
PHP_METHOD(Phalcon_Logger_Multiple, getLoggers);
PHP_METHOD(Phalcon_Logger_Multiple, setFormatter);
PHP_METHOD(Phalcon_Logger_Multiple, getFormatter);
PHP_METHOD(Phalcon_Logger_Multiple, log);
PHP_METHOD(Phalcon_Logger_Multiple, emergency);
PHP_METHOD(Phalcon_Logger_Multiple, debug);
PHP_METHOD(Phalcon_Logger_Multiple, error);
PHP_METHOD(Phalcon_Logger_Multiple, info);
PHP_METHOD(Phalcon_Logger_Multiple, notice);
PHP_METHOD(Phalcon_Logger_Multiple, warning);
PHP_METHOD(Phalcon_Logger_Multiple, alert);
PHP_METHOD(Phalcon_Logger_Multiple, critical); 

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_push, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_logger_multiple_method_entry[] = {
	PHP_ME(Phalcon_Logger_Multiple, push, arginfo_phalcon_logger_multiple_push, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, getLoggers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, setFormatter, arginfo_phalcon_logger_adapterinterface_setformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, log, arginfo_phalcon_logger_adapterinterface_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, emergency, arginfo_phalcon_logger_adapterinterface_emergency, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Logger_Multiple, emergence, emergency, arginfo_phalcon_logger_adapterinterface_emergency, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
	PHP_ME(Phalcon_Logger_Multiple, debug, arginfo_phalcon_logger_adapterinterface_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, error, arginfo_phalcon_logger_adapterinterface_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, info, arginfo_phalcon_logger_adapterinterface_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, notice, arginfo_phalcon_logger_adapterinterface_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, warning, arginfo_phalcon_logger_adapterinterface_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, alert, arginfo_phalcon_logger_adapterinterface_alert, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
	zend_class_entry *exception = PHALCON_GLOBAL(register_psr3_classes) ? psr_log_invalidargumentexception_ce : phalcon_logger_exception_ce;

	phalcon_fetch_params(0, 1, 0, &logger);
	
	PHALCON_VERIFY_INTERFACE_EX(logger, phalcon_logger_adapterinterface_ce, exception, 0)
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
	phalcon_read_property_this(&loggers, this_ptr, SL("_loggers"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(loggers) == IS_ARRAY) { 
	
		phalcon_is_iterable(loggers, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(logger);
	
			PHALCON_CALL_METHOD(NULL, logger, "setformatter", formatter);
	
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
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, log){

	zval *message, *type = NULL, *context = NULL, *loggers, *logger = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &message, &type, &context);
	
	if (!type) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, PHALCON_LOGGER_DEBUG);
	}

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}

	PHALCON_OBS_VAR(loggers);
	phalcon_read_property_this(&loggers, this_ptr, SL("_loggers"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(loggers) == IS_ARRAY) { 
	
		phalcon_is_iterable(loggers, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(logger);
	
			PHALCON_CALL_METHOD(NULL, logger, "log", message, type, context);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an emergency message to the log
 *
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, emergency){

	zval *message, *type, *context = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &context);

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, PHALCON_LOGGER_EMERGENCY);
	PHALCON_CALL_METHOD(NULL, this_ptr, "log", message, type, context);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes a debug message to the log
 *
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, debug){

	zval *message, *type, *context = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &context);

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, PHALCON_LOGGER_DEBUG);
	PHALCON_CALL_METHOD(NULL, this_ptr, "log", message, type, context);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an error message to the log
 *
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, error){

	zval *message, *type, *context = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &context);

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, PHALCON_LOGGER_ERROR);
	PHALCON_CALL_METHOD(NULL, this_ptr, "log", message, type, context);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an info message to the log
 *
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, info){

	zval *message, *type, *context = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &context);

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, PHALCON_LOGGER_INFO);
	PHALCON_CALL_METHOD(NULL, this_ptr, "log", message, type, context);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes a notice message to the log
 *
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, notice){

	zval *message, *type, *context = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &context);

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, PHALCON_LOGGER_NOTICE);
	PHALCON_CALL_METHOD(NULL, this_ptr, "log", message, type, context);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes a warning message to the log
 *
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, warning){

	zval *message, *type, *context = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &context);

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, PHALCON_LOGGER_WARNING);
	PHALCON_CALL_METHOD(NULL, this_ptr, "log", message, type, context);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an alert message to the log
 *
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, alert){

	zval *message, *type, *context = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &context);

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, PHALCON_LOGGER_ALERT);
	PHALCON_CALL_METHOD(NULL, this_ptr, "log", message, type, context);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sends/Writes an critical message to the log
 *
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Multiple, critical){

	zval *message, *type, *context = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &context);

	if (!context) {
		context = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, PHALCON_LOGGER_CRITICAL);
	PHALCON_CALL_METHOD(NULL, this_ptr, "log", message, type, context);
	
	PHALCON_MM_RESTORE();
}
