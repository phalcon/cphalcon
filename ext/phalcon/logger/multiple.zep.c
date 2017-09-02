
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_loggers");

}

PHP_METHOD(Phalcon_Logger_Multiple, getFormatter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_formatter");

}

PHP_METHOD(Phalcon_Logger_Multiple, getLogLevel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_logLevel");

}

/**
 * Pushes a logger to the logger tail
 */
PHP_METHOD(Phalcon_Logger_Multiple, push) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params(0, 1, 0, &logger);



	zephir_update_property_array_append(this_ptr, SL("_loggers"), logger TSRMLS_CC);

}

/**
 * Sets a global formatter
 */
PHP_METHOD(Phalcon_Logger_Multiple, setFormatter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *formatter, formatter_sub, loggers, logger, *_0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&formatter_sub);
	ZVAL_UNDEF(&loggers);
	ZVAL_UNDEF(&logger);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatter);



	ZEPHIR_OBS_VAR(&loggers);
	zephir_read_property(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(&loggers) == IS_ARRAY) {
		zephir_is_iterable(&loggers, 0, "phalcon/logger/multiple.zep", 61);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&loggers), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&logger);
			ZVAL_COPY(&logger, _0$$3);
			ZEPHIR_CALL_METHOD(NULL, &logger, "setformatter", NULL, 0, formatter);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&logger);
	}
	zephir_update_property_zval(this_ptr, SL("_formatter"), formatter);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a global level
 */
PHP_METHOD(Phalcon_Logger_Multiple, setLogLevel) {

	zval *level_param = NULL, loggers, logger, _2, *_0$$3, _1$$4;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&loggers);
	ZVAL_UNDEF(&logger);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_OBS_VAR(&loggers);
	zephir_read_property(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(&loggers) == IS_ARRAY) {
		zephir_is_iterable(&loggers, 0, "phalcon/logger/multiple.zep", 77);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&loggers), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&logger);
			ZVAL_COPY(&logger, _0$$3);
			ZVAL_LONG(&_1$$4, level);
			ZEPHIR_CALL_METHOD(NULL, &logger, "setloglevel", NULL, 0, &_1$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&logger);
	}
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, level);
	zephir_update_property_zval(this_ptr, SL("_logLevel"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends a message to each registered logger
 */
PHP_METHOD(Phalcon_Logger_Multiple, log) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *type, type_sub, *message = NULL, message_sub, *context_param = NULL, __$null, loggers, logger, *_0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&loggers);
	ZVAL_UNDEF(&logger);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &type, &message, &context_param);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZEPHIR_OBS_VAR(&loggers);
	zephir_read_property(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(&loggers) == IS_ARRAY) {
		zephir_is_iterable(&loggers, 0, "phalcon/logger/multiple.zep", 93);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&loggers), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&logger);
			ZVAL_COPY(&logger, _0$$3);
			ZEPHIR_CALL_METHOD(NULL, &logger, "log", NULL, 0, type, message, &context);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&logger);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an critical message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, critical) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an emergency message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, emergency) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a debug message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, debug) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZVAL_LONG(&_0, 7);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an error message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZVAL_LONG(&_0, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an info message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, info) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZVAL_LONG(&_0, 6);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a notice message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZVAL_LONG(&_0, 5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes a warning message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, warning) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends/Writes an alert message to the log
 */
PHP_METHOD(Phalcon_Logger_Multiple, alert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

