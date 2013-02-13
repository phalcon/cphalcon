
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
 * Filters the logs sent to the handlers to be less or equals than a specific level
 *
 * @param int $level
 */
PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel){

	zval *level;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &level) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(level) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "The log level is not valid");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_logLevel"), level TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the current log level
 */
PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel){


	RETURN_MEMBER(this_ptr, "_logLevel");
}

/**
 * Sets the message formatter
 *
 * @param Phalcon\Logger\FormatterInterface $formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter, setFormatter){

	zval *formatter;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &formatter) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(formatter) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "The formatter is not valid");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
  * Starts a transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter, begin){


	phalcon_update_property_bool(this_ptr, SL("_transaction"), 1 TSRMLS_CC);
	
}

/**
  * Commits the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter, commit){

	zval *transaction, *queue, *message = NULL, *message_str = NULL;
	zval *type = NULL, *time = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transaction);
	phalcon_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	/** 
	 * Check if the queue has something to log
	 */
	PHALCON_OBS_VAR(queue);
	phalcon_read_property(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	if (Z_TYPE_P(queue) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(queue, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(message);
	
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CALL_METHOD(message_str, message, "getmessage");
	
			PHALCON_INIT_NVAR(type);
			PHALCON_CALL_METHOD(type, message, "gettype");
	
			PHALCON_INIT_NVAR(time);
			PHALCON_CALL_METHOD(time, message, "gettime");
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "loginternal", message_str, type, time);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
  * Rollbacks the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter, rollback){

	zval *transaction, *queue;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transaction);
	phalcon_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(queue);
	array_init(queue);
	phalcon_update_property_zval(this_ptr, SL("_queue"), queue TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an emergence message to the log
  *
  * @param string $message
  */
PHP_METHOD(Phalcon_Logger_Adapter, emergence){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("EMERGENCE") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type);
	
	PHALCON_MM_RESTORE();
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
 * Logs messages to the internal loggger. Appends logs to the
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Adapter, log){

	zval *message, *type = NULL, *timestamp, *transaction;
	zval *queue_item, *log_level, *enter_level;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &type) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!type) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 7);
	}
	
	PHALCON_INIT_VAR(timestamp);
	ZVAL_LONG(timestamp, (long) time(NULL));
	
	PHALCON_OBS_VAR(transaction);
	phalcon_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (zend_is_true(transaction)) {
		PHALCON_INIT_VAR(queue_item);
		object_init_ex(queue_item, phalcon_logger_item_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(queue_item, "__construct", message, type, timestamp);
	
		phalcon_update_property_array_append(this_ptr, SL("_queue"), queue_item TSRMLS_CC);
		RETURN_MM_NULL();
	}
	
	PHALCON_OBS_VAR(log_level);
	phalcon_read_property(&log_level, this_ptr, SL("_logLevel"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(enter_level);
	is_smaller_or_equal_function(enter_level, type, log_level TSRMLS_CC);
	
	/** 
	 * Checks if the log is valid respecting the current log level
	 */
	if (PHALCON_IS_TRUE(enter_level)) {
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "loginternal", message, type, timestamp);
	}
	
	PHALCON_MM_RESTORE();
}

