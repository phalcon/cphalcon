
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/date/php_date.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"


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
 * A PSR compatible logger, with various adapters and formatters. A formatter
 * interface is available as well as an adapter one. Adapters can be created
 * easily using the built in AdapterFactory. A LoggerFactory is also available
 * that allows developers to create new instances of the Logger or load them
 * from config files (see Phalcon\Config\Config object).
 *
 * @package Phalcon\Logger
 *
 * @property AdapterInterface[] $adapters
 * @property array              $excluded
 * @property int                $logLevel
 * @property string             $name
 * @property string             $timezone
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Logger)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Logger, phalcon, logger_logger, phalcon_logger_logger_method_entry, 0);

	/**
	 * The adapter stack
	 *
	 * @var AdapterInterface[]
	 */
	zend_declare_property_null(phalcon_logger_logger_ce, SL("adapters"), ZEND_ACC_PROTECTED);
	/**
	 * The excluded adapters for this log process
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_logger_logger_ce, SL("excluded"), ZEND_ACC_PROTECTED);
	/**
	 * Minimum log level for the logger
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_logger_ce, SL("logLevel"), 8, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_logger_ce, SL("name"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var DateTimeZone
	 */
	zend_declare_property_null(phalcon_logger_logger_ce, SL("timezone"), ZEND_ACC_PROTECTED);
	phalcon_logger_logger_ce->create_object = zephir_init_properties_Phalcon_Logger_Logger;
	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("ALERT"), 2);

	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("CRITICAL"), 1);

	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("CUSTOM"), 8);

	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("DEBUG"), 7);

	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("EMERGENCY"), 0);

	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("ERROR"), 3);

	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("INFO"), 6);

	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("NOTICE"), 5);

	zephir_declare_class_constant_long(phalcon_logger_logger_ce, SL("WARNING"), 4);

	zend_class_implements(phalcon_logger_logger_ce, 1, zephir_get_internal_ce(SL("psrext\\log\\loggerinterface")));
	return SUCCESS;
}

/**
 * The adapter stack
 */
PHP_METHOD(Phalcon_Logger_Logger, getAdapters)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "adapters");
}

/**
 * Minimum log level for the logger
 */
PHP_METHOD(Phalcon_Logger_Logger, getLogLevel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "logLevel");
}

/**
 */
PHP_METHOD(Phalcon_Logger_Logger, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Constructor.
 *
 * @param string            $name     The name of the logger
 * @param array             $adapters The collection of adapters to be used
 *                                    for logging (default [])
 * @param DateTimeZone|null $timezone Timezone. If omitted,
 *                                    date_Default_timezone_get() is used
 */
PHP_METHOD(Phalcon_Logger_Logger, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval adapters;
	zval *name_param = NULL, *adapters_param = NULL, *timezone = NULL, timezone_sub, __$null, localTimeZone, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&timezone_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&localTimeZone);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&adapters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(adapters)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(timezone, php_date_get_timezone_ce())
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &adapters_param, &timezone);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&adapters, adapters_param);
	}
	if (!timezone) {
		timezone = &timezone_sub;
		timezone = &__$null;
	}


	ZEPHIR_CPY_WRT(&localTimeZone, timezone);
	if (ZEPHIR_IS_EMPTY(timezone)) {
		ZEPHIR_CALL_FUNCTION(&localTimeZone, "date_default_timezone_get", NULL, 486);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&localTimeZone)) {
			ZEPHIR_INIT_NVAR(&localTimeZone);
			ZVAL_STRING(&localTimeZone, "UTC");
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_timezone_ce());
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &localTimeZone);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("timezone"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setadapters", NULL, 0, &adapters);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Add an adapter to the stack. For processing we use FIFO
 *
 * @param string           $name    The name of the adapter
 * @param AdapterInterface $adapter The adapter to add to the stack
 *
 * @return Logger
 */
PHP_METHOD(Phalcon_Logger_Logger, addAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *adapter, adapter_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapter_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_logger_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &adapter);
	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("adapters"), &name, adapter);
	RETURN_THIS();
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
 */
PHP_METHOD(Phalcon_Logger_Logger, alert)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message, message_sub, *context_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_cast_to_string(&_0, message);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
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
 */
PHP_METHOD(Phalcon_Logger_Logger, critical)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message, message_sub, *context_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_cast_to_string(&_0, message);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
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
 */
PHP_METHOD(Phalcon_Logger_Logger, debug)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message, message_sub, *context_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_cast_to_string(&_0, message);
	ZVAL_LONG(&_1, 7);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
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
 */
PHP_METHOD(Phalcon_Logger_Logger, error)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message, message_sub, *context_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_cast_to_string(&_0, message);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
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
 */
PHP_METHOD(Phalcon_Logger_Logger, emergency)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message, message_sub, *context_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_cast_to_string(&_0, message);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Exclude certain adapters.
 *
 * @param array $adapters
 *
 * @return Logger
 */
PHP_METHOD(Phalcon_Logger_Logger, excludeAdapters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *adapters_param = NULL, __$true, adapter, registered, *_0, _1;
	zval adapters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapters);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&registered);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(adapters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &adapters_param);
	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
		zephir_get_arrval(&adapters, adapters_param);
	}


	zephir_read_property(&registered, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&adapters, 0, "phalcon/Logger/Logger.zep", 227);
	if (Z_TYPE_P(&adapters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&adapters), _0)
		{
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _0);
			if (zephir_array_isset(&registered, &adapter)) {
				zephir_update_property_array(this_ptr, SL("excluded"), &adapter, &__$true);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &adapters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &adapters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapter, &adapters, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset(&registered, &adapter)) {
					zephir_update_property_array(this_ptr, SL("excluded"), &adapter, &__$true);
				}
			ZEPHIR_CALL_METHOD(NULL, &adapters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	RETURN_THIS();
}

/**
 * Returns an adapter from the stack
 *
 * @param string $name The name of the adapter
 *
 * @return AdapterInterface
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, getAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, adapter, adapters, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&adapters, &_0);
	ZEPHIR_OBS_VAR(&adapter);
	if (!(zephir_array_isset_fetch(&adapter, &adapters, &name, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter does not exist for this logger", "phalcon/Logger/Logger.zep", 245);
		return;
	}
	RETURN_CCTOR(&adapter);
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
 */
PHP_METHOD(Phalcon_Logger_Logger, info)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message, message_sub, *context_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_cast_to_string(&_0, message);
	ZVAL_LONG(&_1, 6);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Logs with an arbitrary level.
 *
 * @param mixed $level
 * @param mixed $message
 * @param array $context
 *
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, log)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *level, level_sub, *message, message_sub, *context_param = NULL, intLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&intLevel);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(level)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_CALL_METHOD(&intLevel, this_ptr, "getlevelnumber", NULL, 487, level);
	zephir_check_call_status();
	zephir_cast_to_string(&_0, message);
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
 */
PHP_METHOD(Phalcon_Logger_Logger, notice)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message, message_sub, *context_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_cast_to_string(&_0, message);
	ZVAL_LONG(&_1, 5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes an adapter from the stack
 *
 * @param string $name The name of the adapter
 *
 * @return Logger
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, removeAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, adapters, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&adapters, &_0);
	if (1 != zephir_array_isset(&adapters, &name)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter does not exist for this logger", "phalcon/Logger/Logger.zep", 312);
		return;
	}
	zephir_array_unset(&adapters, &name, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapters"), &adapters);
	RETURN_THIS();
}

/**
 * Sets the adapters stack overriding what is already there
 *
 * @param array $adapters An array of adapters
 *
 * @return Logger
 */
PHP_METHOD(Phalcon_Logger_Logger, setAdapters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *adapters_param = NULL;
	zval adapters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(adapters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &adapters_param);
	ZEPHIR_OBS_COPY_OR_DUP(&adapters, adapters_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("adapters"), &adapters);
	RETURN_THIS();
}

/**
 * Sets the adapters stack overriding what is already there
 *
 * @param int $level
 *
 * @return Logger
 */
PHP_METHOD(Phalcon_Logger_Logger, setLogLevel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *level_param = NULL, levels, _0;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);
	level = zephir_get_intval(level_param);


	ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset_long(&levels, level))) {
		level = 8;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, level);
	zephir_update_property_zval(this_ptr, ZEND_STRL("logLevel"), &_0);
	RETURN_THIS();
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
 */
PHP_METHOD(Phalcon_Logger_Logger, warning)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message, message_sub, *context_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_cast_to_string(&_0, message);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a message to each handler for processing
 *
 * @param int    $level
 * @param string $message
 * @param array  $context
 *
 * @return bool
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_Logger, addMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zval message;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, adapter, adapters, excluded, item, levelName, levels, registered, _0, _1$$3, _2$$3, _3$$3, _4$$3, *_5$$3, _6$$3, _7$$6, _8$$9;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&excluded);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&levelName);
	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&registered);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_LONG(level)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &context_param);
	level = zephir_get_intval(level_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("logLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GE_LONG(&_0, level)) {
		ZEPHIR_OBS_VAR(&registered);
		zephir_read_property(&registered, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("excluded"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&excluded, &_1$$3);
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		if (1 == ZEPHIR_IS_EMPTY(&registered)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "No adapters specified", "phalcon/Logger/Logger.zep", 397);
			return;
		}
		ZEPHIR_OBS_VAR(&levelName);
		if (UNEXPECTED(!(zephir_array_isset_long_fetch(&levelName, &levels, level, 0)))) {
			ZEPHIR_OBS_NVAR(&levelName);
			zephir_array_fetch_long(&levelName, &levels, 8, PH_NOISY, "phalcon/Logger/Logger.zep", 401);
		}
		ZEPHIR_INIT_VAR(&item);
		object_init_ex(&item, phalcon_logger_item_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, php_date_get_immutable_ce());
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("timezone"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "now");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &_3$$3, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, level);
		ZEPHIR_CALL_METHOD(NULL, &item, "__construct", NULL, 488, &message, &levelName, &_4$$3, &_2$$3, &context);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&adapters, "array_diff_key", NULL, 489, &registered, &excluded);
		zephir_check_call_status();
		zephir_is_iterable(&adapters, 0, "phalcon/Logger/Logger.zep", 427);
		if (Z_TYPE_P(&adapters) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&adapters), _5$$3)
			{
				ZEPHIR_INIT_NVAR(&adapter);
				ZVAL_COPY(&adapter, _5$$3);
				ZEPHIR_CALL_METHOD(&_7$$6, &adapter, "intransaction", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_7$$6)) {
					ZEPHIR_CALL_METHOD(NULL, &adapter, "add", NULL, 0, &item);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &adapter, "process", NULL, 0, &item);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &adapters, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$3, &adapters, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&adapter, &adapters, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8$$9, &adapter, "intransaction", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_8$$9)) {
						ZEPHIR_CALL_METHOD(NULL, &adapter, "add", NULL, 0, &item);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &adapter, "process", NULL, 0, &item);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, &adapters, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&adapter);
		ZEPHIR_INIT_NVAR(&_3$$3);
		array_init(&_3$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("excluded"), &_3$$3);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Returns an array of log levels with integer to string conversion
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Logger_Logger, getLevels)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 9, 0);
	add_index_stringl(return_value, 2, SL("ALERT"));
	add_index_stringl(return_value, 1, SL("CRITICAL"));
	add_index_stringl(return_value, 7, SL("DEBUG"));
	add_index_stringl(return_value, 0, SL("EMERGENCY"));
	add_index_stringl(return_value, 3, SL("ERROR"));
	add_index_stringl(return_value, 6, SL("INFO"));
	add_index_stringl(return_value, 5, SL("NOTICE"));
	add_index_stringl(return_value, 4, SL("WARNING"));
	add_index_stringl(return_value, 8, SL("CUSTOM"));
	return;
}

/**
 * Converts the level from string/word to an integer
 *
 * @param mixed $level
 *
 * @return int
 * @throws InvalidArgumentException
 */
PHP_METHOD(Phalcon_Logger_Logger, getLevelNumber)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *level, level_sub, levelName, levels, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&levelName);
	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(level)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level);


	if (Z_TYPE_P(level) == IS_STRING) {
		ZEPHIR_INIT_VAR(&levelName);
		zephir_fast_strtoupper(&levelName, level);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&levels, "array_flip", NULL, 205, &_0$$3);
		zephir_check_call_status();
		if (zephir_array_isset(&levels, &levelName)) {
			zephir_array_fetch(&_1$$4, &levels, &levelName, PH_NOISY | PH_READONLY, "phalcon/Logger/Logger.zep", 473);
			RETURN_CTOR(&_1$$4);
		}
	} else if (zephir_is_numeric(level)) {
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		if (zephir_array_isset(&levels, level)) {
			RETURN_MM_LONG(zephir_get_intval(level));
		}
	}
	RETURN_MM_LONG(8);
}

zend_object *zephir_init_properties_Phalcon_Logger_Logger(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("excluded"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("excluded"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("adapters"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

