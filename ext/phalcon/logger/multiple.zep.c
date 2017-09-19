
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Logger\Multiple
 *
 * Handles multiples logger handlers
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Multiple) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Multiple, phalcon, logger_multiple, phalcon_logger_multiple_method_entry, 0);

	zend_declare_property_null(phalcon_logger_multiple_ce, SL("_loggers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_logger_multiple_ce, SL("_formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_logger_multiple_ce, SL("_logLevel"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Logger_Multiple, getLoggers) {

	

	RETURN_MEMBER(getThis(), "_loggers");

}

PHP_METHOD(Phalcon_Logger_Multiple, getFormatter) {

	

	RETURN_MEMBER(getThis(), "_formatter");

}

PHP_METHOD(Phalcon_Logger_Multiple, getLogLevel) {

	

	RETURN_MEMBER(getThis(), "_logLevel");

}

/**
 * Pushes a logger to the logger tail
 */
PHP_METHOD(Phalcon_Logger_Multiple, push) {

	zval *logger;

	zephir_fetch_params(0, 1, 0, &logger);



	zephir_update_property_array_append(this_ptr, SL("_loggers"), logger TSRMLS_CC);

}

/**
 * Sets a global formatter
 */
PHP_METHOD(Phalcon_Logger_Multiple, setFormatter) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *formatter, *loggers = NULL, *logger = NULL, **_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatter);



	ZEPHIR_OBS_VAR(loggers);
	zephir_read_property_this(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(loggers) == IS_ARRAY) {
		zephir_is_iterable(loggers, &_1$$3, &_0$$3, 0, 0, "phalcon/logger/multiple.zep", 61);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(logger, _2$$3);
			ZEPHIR_CALL_METHOD(NULL, logger, "setformatter", NULL, 0, formatter);
			zephir_check_call_status();
		}
	}
	zephir_update_property_this(getThis(), SL("_formatter"), formatter TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a global level
 */
PHP_METHOD(Phalcon_Logger_Multiple, setLogLevel) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zval *level_param = NULL, *loggers = NULL, *logger = NULL, *_4, **_2$$3, *_3$$4 = NULL;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_OBS_VAR(loggers);
	zephir_read_property_this(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(loggers) == IS_ARRAY) {
		zephir_is_iterable(loggers, &_1$$3, &_0$$3, 0, 0, "phalcon/logger/multiple.zep", 77);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(logger, _2$$3);
			ZEPHIR_INIT_NVAR(_3$$4);
			ZVAL_LONG(_3$$4, level);
			ZEPHIR_CALL_METHOD(NULL, logger, "setloglevel", NULL, 0, _3$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, level);
	zephir_update_property_this(getThis(), SL("_logLevel"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends a message to each registered logger
 */
PHP_METHOD(Phalcon_Logger_Multiple, log) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *type, *message = NULL, *context_param = NULL, *loggers = NULL, *logger = NULL, **_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &type, &message, &context_param);

	if (!message) {
		message = ZEPHIR_GLOBAL(global_null);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_OBS_VAR(loggers);
	zephir_read_property_this(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(loggers) == IS_ARRAY) {
		zephir_is_iterable(loggers, &_1$$3, &_0$$3, 0, 0, "phalcon/logger/multiple.zep", 93);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(logger, _2$$3);
			ZEPHIR_CALL_METHOD(NULL, logger, "log", NULL, 0, type, message, context);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an critical message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, critical) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an emergency message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, emergency) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a debug message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, debug) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 7);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an error message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an info message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, info) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 6);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a notice message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a warning message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, warning) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an alert message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, alert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
	context = context_param;
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

