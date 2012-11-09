
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
#include "kernel/exception.h"

/**
 * Phalcon\Logger
 *
 * Phalcon\Logger is a component whose purpose is to create logs using
 * different backends via adapters, generating options, formats and filters
 * also implementing transactions.
 *
 *<code>
 *$logger = new Phalcon\Logger\Adapter\File("app/logs/test.log");
 *$logger->log("This is a message");
 *$logger->log("This is an error", Phalcon\Logger::ERROR);
 *$logger->error("This is another error");
 *$logger->close();
 * </code>
 */


/**
  * Sends/Writes a debug message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, debug){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("DEBUG") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an error message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, error){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("ERROR") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an info message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, info){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("INFO") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes a notice message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, notice){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("NOTICE") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes a warning message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, warning){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("WARNING") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an alert message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, alert){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	phalcon_get_class_constant(type, phalcon_logger_ce, SS("ALERT") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "log", message, type, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Logs a message
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger, log){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &message, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "This method must be implemented by an adapter");
	return;
}

