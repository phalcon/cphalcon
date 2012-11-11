
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

#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
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

	return SUCCESS;
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (phalcon_compare_strict_long(type, 7 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type_str);
		ZVAL_STRING(type_str, "DEBUG", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 3 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "ERROR", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 4 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "WARNING", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 1 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "CRITICAL", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 8 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "CUSTOM", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 2 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "ALERT", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 5 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "NOTICE", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 6 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "INFO", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 0 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "EMERGENCE", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 9 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "SPECIAL", 1);
		goto ph_end_0;
	}
	
	PHALCON_INIT_NVAR(type_str);
	ZVAL_STRING(type_str, "CUSTOM", 1);
	
	ph_end_0:
	
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
PHP_METHOD(Phalcon_Logger_Adapter, error){

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
PHP_METHOD(Phalcon_Logger_Adapter, info){

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
PHP_METHOD(Phalcon_Logger_Adapter, notice){

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
PHP_METHOD(Phalcon_Logger_Adapter, warning){

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
PHP_METHOD(Phalcon_Logger_Adapter, alert){

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
PHP_METHOD(Phalcon_Logger_Adapter, log){

	zval *message, *type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &message, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "This method must be implemented by an adapter");
	return;
}

