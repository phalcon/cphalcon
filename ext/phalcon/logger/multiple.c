
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


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
/**
 * Phalcon\Logger\Multiple
 *
 * Handles multiples logger handlers
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Multiple) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Multiple, phalcon, logger_multiple, phalcon_logger_multiple_method_entry, 0);

	zend_declare_property_null(phalcon_logger_multiple_ce, SL("_loggers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_multiple_ce, SL("_formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Logger_Multiple, getLoggers) {



}

PHP_METHOD(Phalcon_Logger_Multiple, getFormatter) {



}

/**
 * Pushes a logger to the logger tail
 *
 * @param Phalcon\Logger\AdapterInterface logger
 */
PHP_METHOD(Phalcon_Logger_Multiple, push) {

	zval *logger;

	zephir_fetch_params(0, 1, 0, &logger);



	if ((Z_TYPE_P(logger) == IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_logger_exception_ce, "The logger is invalid");
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("_loggers"), logger TSRMLS_CC);

}

/**
 * Sets a global formatter
 *
 * @param Phalcon\Logger\FormatterInterface formatter
 */
PHP_METHOD(Phalcon_Logger_Multiple, setFormatter) {

	zend_function *_3 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *formatter, *loggers, *logger = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatter);



	loggers = zephir_fetch_nproperty_this(this_ptr, SL("_loggers"), PH_NOISY_CC);
	if ((Z_TYPE_P(loggers) == IS_ARRAY)) {
		zephir_is_iterable(loggers, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(logger, _2);
			zephir_call_method_p1_cache_noret(logger, "setformatter", &_3, formatter);
		}
	}
	zephir_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends a message to each registered logger
 *
 * @param string message
 * @param int type
 */
PHP_METHOD(Phalcon_Logger_Multiple, log) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	int type;
	zval *message_param = NULL, *type_param = NULL, *loggers, *logger = NULL, **_2, *_3 = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &type_param);

		zephir_get_strval(message, message_param);
	if (!type_param) {
		type = 7;	} else {
		type = zephir_get_intval(type_param);
	}


	loggers = zephir_fetch_nproperty_this(this_ptr, SL("_loggers"), PH_NOISY_CC);
	if ((Z_TYPE_P(loggers) == IS_ARRAY)) {
		zephir_is_iterable(loggers, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(logger, _2);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, type);
			zephir_call_method_p2_cache_noret(logger, "log", &_4, message, _3);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an emergence message to the log
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger_Multiple, emergence) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a debug message to the log
 *
 * @param string message
 * @param ing type
 */
PHP_METHOD(Phalcon_Logger_Multiple, debug) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 7);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an error message to the log
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger_Multiple, error) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an info message to the log
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger_Multiple, info) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 6);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a notice message to the log
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger_Multiple, notice) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 5);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a warning message to the log
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger_Multiple, warning) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an alert message to the log
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger_Multiple, alert) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	ZEPHIR_MM_RESTORE();

}

