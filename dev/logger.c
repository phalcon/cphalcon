
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Logger
 *
 * Phalcon_Logger is a component whose purpose is to create logs using
 * different backends via adapters, generating options, formats and filters
 * also implementing transactions.
 *
 *
 */

/**
 * Phalcon_Logger constructor
 *
 * @param string $adapter
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger, __construct){

	zval *adapter = NULL, *name = NULL, *options = NULL, *class_name = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &adapter, &name, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!adapter) {
		PHALCON_INIT_VAR(adapter);
		ZVAL_STRING(adapter, "File", 1);
	}
	
	if (!name) {
		PHALCON_INIT_VAR(name);
		ZVAL_NULL(name);
	}
	
	if (!options) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Logger_Adapter_", adapter);
	PHALCON_CPY_WRT(class_name, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(class_name);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", class_name, 0x00E);
	Z_DELREF_P(class_name);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Logger adapter '", class_name, "' cannot be found");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i1, "__construct", name, options, PHALCON_CHECK);
	phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), i1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes a message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, log){

	zval *message = NULL, *type = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!type) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 7);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t0, "log", message, type, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes a debug message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, debug){

	zval *message = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_ce, "DEBUG", strlen("DEBUG") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t0, "log", message, t1, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an error message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, error){

	zval *message = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_ce, "ERROR", strlen("ERROR") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t0, "log", message, t1, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an info message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, info){

	zval *message = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_ce, "INFO", strlen("INFO") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t0, "log", message, t1, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes a notice message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, notice){

	zval *message = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_ce, "NOTICE", strlen("NOTICE") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t0, "log", message, t1, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes a warning message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, warning){

	zval *message = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_ce, "WARNING", strlen("WARNING") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t0, "log", message, t1, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
  * Sends/Writes an alert message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHP_METHOD(Phalcon_Logger, alert){

	zval *message = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_ce, "ALERT", strlen("ALERT") TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t0, "log", message, t1, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Pass any call to the internal adapter object
 *
 * @param  string $method
 * @param  array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Logger, __call){

	zval *method = NULL, *arguments = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!arguments) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(arguments, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&a1, t0, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	phalcon_array_append(&a1, method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	Z_ADDREF_P(a1);
	Z_ADDREF_P(arguments);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "call_user_func_array", a1, arguments, 0x00F);
	Z_DELREF_P(a1);
	Z_DELREF_P(arguments);
	PHALCON_RETURN_DZVAL(r0);
}

