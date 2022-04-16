
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon Logger.
 *
 * A logger, with various adapters and formatters. A formatter
 * interface is available as well as an adapter one. Adapters can be created
 * easily using the built-in AdapterFactory. A LoggerFactory is also available
 * that allows developers to create new instances of the Logger or load them
 * from config files (see Phalcon\Config\Config object).
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Logger)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger, Logger, phalcon, logger_logger, phalcon_logger_abstractlogger_ce, phalcon_logger_logger_method_entry, 0);

	zend_class_implements(phalcon_logger_logger_ce, 1, phalcon_logger_loggerinterface_ce);
	return SUCCESS;
}

/**
 * Action must be taken immediately.
 *
 * Example: Entire website down, database unavailable, etc. This should
 * trigger the SMS alerts and wake you up.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, alert)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Critical conditions.
 *
 * Example: Application component unavailable, unexpected exception.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, critical)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Detailed debug information.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, debug)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZVAL_LONG(&_0, 7);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * System is unusable.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, emergency)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Runtime errors that do not require immediate action but should typically
 * be logged and monitored.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, error)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZVAL_LONG(&_0, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Interesting events.
 *
 * Example: User logs in, SQL logs.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, info)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZVAL_LONG(&_0, 6);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Logs with an arbitrary level.
 *
 * @param mixed  $level
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, log)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval message, _0;
	zval *level, level_sub, *message_param = NULL, *context_param = NULL, intLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&intLevel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(level)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_CALL_METHOD(&intLevel, this_ptr, "getlevelnumber", NULL, 0, level);
	zephir_check_call_status();
	zephir_cast_to_string(&_0, &message);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &intLevel, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Normal but significant events.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, notice)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZVAL_LONG(&_0, 5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Exceptional occurrences that are not errors.
 *
 * Example: Use of deprecated APIs, poor use of an API, undesirable things
 * that are not necessarily wrong.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, warning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

