
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
#include "kernel/operators.h"

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

	zend_declare_property_bool(phalcon_logger_adapter_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_ce, SL("_queue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_ce, SL("_formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_logger_adapter_ce, SL("_logLevel"), 9, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Filters the logs sent to the handlers that are less or equal than a specific level
 *
 * @param int $level
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel){

	zval *level;

	phalcon_fetch_params(0, 1, 0, &level);
	
	if (Z_TYPE_P(level) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_logger_exception_ce, "The log level is not valid");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_logLevel"), level TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns the current log level
 *
 * @return int
 */
PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel){


	RETURN_MEMBER(this_ptr, "_logLevel");
}

/**
 * Sets the message formatter
 *
 * @param Phalcon\Logger\FormatterInterface $formatter
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, setFormatter){

	zval *formatter;

	phalcon_fetch_params(0, 1, 0, &formatter);
	
	if (Z_TYPE_P(formatter) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_logger_exception_ce, "The formatter is not valid");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns the current transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, isTransaction){

	RETURN_MEMBER(this_ptr, "_transaction");
}

/**
 * Starts a transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, begin){


	phalcon_update_property_bool(this_ptr, SL("_transaction"), 1 TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Commits the internal transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, commit){

	zval *transaction, *queue, *message = NULL, *message_str = NULL;
	zval *type = NULL, *time = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transaction);
	phalcon_read_property_this(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	/** 
	 * Check if the queue has something to log
	 */
	PHALCON_OBS_VAR(queue);
	phalcon_read_property_this(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	if (Z_TYPE_P(queue) == IS_ARRAY) { 
	
		phalcon_is_iterable(queue, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(message);
	
			PHALCON_INIT_NVAR(message_str);
			phalcon_call_method(message_str, message, "getmessage");
	
			PHALCON_INIT_NVAR(type);
			phalcon_call_method(type, message, "gettype");
	
			PHALCON_INIT_NVAR(time);
			phalcon_call_method(time, message, "gettime");
			phalcon_call_method_p3_noret(this_ptr, "loginternal", message_str, type, time);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	RETURN_THIS();
}

/**
 * Rollbacks the internal transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, rollback){

	zval *transaction, *queue;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transaction);
	phalcon_read_property_this(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(queue);
	array_init(queue);
	phalcon_update_property_this(this_ptr, SL("_queue"), queue TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Sends/Writes an emergence message to the log
 *
 * @param string $message
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, emergence){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	PHALCON_GET_CLASS_CONSTANT(type, phalcon_logger_ce, "EMERGENCE");
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	RETURN_THIS();
}

/**
 * Sends/Writes a debug message to the log
 *
 * @param string $message
 * @param ing $type
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, debug){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	PHALCON_GET_CLASS_CONSTANT(type, phalcon_logger_ce, "DEBUG");
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	RETURN_THIS();
}

/**
 * Sends/Writes an error message to the log
 *
 * @param string $message
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, error){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	PHALCON_GET_CLASS_CONSTANT(type, phalcon_logger_ce, "ERROR");
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	RETURN_THIS();
}

/**
 * Sends/Writes an info message to the log
 *
 * @param string $message
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, info){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	PHALCON_GET_CLASS_CONSTANT(type, phalcon_logger_ce, "INFO");
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	RETURN_THIS();
}

/**
 * Sends/Writes a notice message to the log
 *
 * @param string $message
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, notice){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	PHALCON_GET_CLASS_CONSTANT(type, phalcon_logger_ce, "NOTICE");
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	RETURN_THIS();
}

/**
 * Sends/Writes a warning message to the log
 *
 * @param string $message
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, warning){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	PHALCON_GET_CLASS_CONSTANT(type, phalcon_logger_ce, "WARNING");
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	RETURN_THIS();
}

/**
 * Sends/Writes an alert message to the log
 *
 * @param string $message
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, alert){

	zval *message, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_INIT_VAR(type);
	PHALCON_GET_CLASS_CONSTANT(type, phalcon_logger_ce, "ALERT");
	phalcon_call_method_p2_noret(this_ptr, "log", message, type);
	RETURN_THIS();
}

/**
 * Logs messages to the internal loggger. Appends logs to the
 *
 * @param string $message
 * @param int $type
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, log){

	zval *message, *type = NULL, *timestamp, *transaction;
	zval *queue_item, *log_level;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &message, &type);
	
	if (!type) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 7);
	}
	
	PHALCON_INIT_VAR(timestamp);
	ZVAL_LONG(timestamp, (long) time(NULL));
	
	PHALCON_OBS_VAR(transaction);
	phalcon_read_property_this(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (zend_is_true(transaction)) {
		PHALCON_INIT_VAR(queue_item);
		object_init_ex(queue_item, phalcon_logger_item_ce);
		phalcon_call_method_p3_noret(queue_item, "__construct", message, type, timestamp);
	
		phalcon_update_property_array_append(this_ptr, SL("_queue"), queue_item TSRMLS_CC);
		RETURN_THIS();
	}
	
	PHALCON_OBS_VAR(log_level);
	phalcon_read_property_this(&log_level, this_ptr, SL("_logLevel"), PH_NOISY_CC);
	
	/** 
	 * Checks if the log is valid respecting the current log level
	 */
	if (PHALCON_GE(log_level, type)) {
		phalcon_call_method_p3_noret(this_ptr, "loginternal", message, type, timestamp);
	}
	
	RETURN_THIS();
}

