
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/date/php_date.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
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
 * Abstract Logger Class
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
ZEPHIR_INIT_CLASS(Phalcon_Logger_AbstractLogger)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, AbstractLogger, phalcon, logger_abstractlogger, phalcon_logger_abstractlogger_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * The adapter stack
	 *
	 * @var AdapterInterface[]
	 */
	zend_declare_property_null(phalcon_logger_abstractlogger_ce, SL("adapters"), ZEND_ACC_PROTECTED);
	/**
	 * The excluded adapters for this log process
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_logger_abstractlogger_ce, SL("excluded"), ZEND_ACC_PROTECTED);
	/**
	 * Minimum log level for the logger
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_abstractlogger_ce, SL("logLevel"), 8, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_abstractlogger_ce, SL("name"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var DateTimeZone
	 */
	zend_declare_property_null(phalcon_logger_abstractlogger_ce, SL("timezone"), ZEND_ACC_PROTECTED);
	phalcon_logger_abstractlogger_ce->create_object = zephir_init_properties_Phalcon_Logger_AbstractLogger;
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("ALERT"), 2);

	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("CRITICAL"), 1);

	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("CUSTOM"), 8);

	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("DEBUG"), 7);

	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("EMERGENCY"), 0);

	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("ERROR"), 3);

	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("INFO"), 6);

	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("NOTICE"), 5);

	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("WARNING"), 4);

	return SUCCESS;
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
PHP_METHOD(Phalcon_Logger_AbstractLogger, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval adapters;
	zval *name_param = NULL, *adapters_param = NULL, *timezone = NULL, timezone_sub, __$null, defaultTimezone;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&timezone_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&defaultTimezone);
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
	zephir_get_strval(&name, name_param);
	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
		zephir_get_arrval(&adapters, adapters_param);
	}
	if (!timezone) {
		timezone = &timezone_sub;
		ZEPHIR_CPY_WRT(timezone, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(timezone);
	}


	if (Z_TYPE_P(timezone) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&defaultTimezone, "date_default_timezone_get", NULL, 124);
		zephir_check_call_status();
		if (UNEXPECTED(1 == ZEPHIR_IS_EMPTY(&defaultTimezone))) {
			ZEPHIR_INIT_NVAR(&defaultTimezone);
			ZVAL_STRING(&defaultTimezone, "UTC");
		}
		ZEPHIR_INIT_NVAR(timezone);
		object_init_ex(timezone, php_date_get_timezone_ce());
		ZEPHIR_CALL_METHOD(NULL, timezone, "__construct", NULL, 0, &defaultTimezone);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("timezone"), timezone);
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
 * @return AbstractLogger
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, addAdapter)
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
 * Exclude certain adapters.
 *
 * @param array $adapters
 *
 * @return AbstractLogger
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, excludeAdapters)
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
	zephir_is_iterable(&adapters, 0, "phalcon/Logger/AbstractLogger.zep", 155);
	if (Z_TYPE_P(&adapters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&adapters), _0)
		{
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _0);
			if (1 == zephir_array_isset(&registered, &adapter)) {
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
				if (1 == zephir_array_isset(&registered, &adapter)) {
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
PHP_METHOD(Phalcon_Logger_AbstractLogger, getAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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
	if (1 != zephir_array_isset(&_0, &name)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter does not exist for this logger", "phalcon/Logger/AbstractLogger.zep", 171);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &name, PH_NOISY | PH_READONLY, "phalcon/Logger/AbstractLogger.zep", 174);
	RETURN_CTOR(&_2);
}

/**
 * Returns the adapter stack array
 *
 * @return AdapterInterface[]
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getAdapters)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "adapters");
}

/**
 * Returns the log level
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getLogLevel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "logLevel");
}

/**
 * Returns the name of the logger
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Removes an adapter from the stack
 *
 * @param string $name The name of the adapter
 *
 * @return AbstractLogger
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, removeAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	if (1 != zephir_array_isset(&_0, &name)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter does not exist for this logger", "phalcon/Logger/AbstractLogger.zep", 216);
		return;
	}
	zephir_unset_property_array(this_ptr, ZEND_STRL("adapters"), &name);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_1, &name, PH_SEPARATE);
	RETURN_THIS();
}

/**
 * Sets the adapters stack overriding what is already there
 *
 * @param array $adapters An array of adapters
 *
 * @return AbstractLogger
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, setAdapters)
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
	zephir_get_arrval(&adapters, adapters_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("adapters"), &adapters);
	RETURN_THIS();
}

/**
 * Sets the adapters stack overriding what is already there
 *
 * @param int $level
 *
 * @return AbstractLogger
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, setLogLevel)
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
	ZEPHIR_INIT_VAR(&_0);
	if (1 == zephir_array_isset_long(&levels, level)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, level);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 8);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("logLevel"), &_0);
	RETURN_THIS();
}

/**
 * Adds a message to each handler for processing
 *
 * @param int    level
 * @param string $message
 * @param array  $context
 *
 * @return bool
 * @throws Exception
 * @throws LoggerException
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, addMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zval message;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, adapter, collection, item, levelName, levels, method, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, *_7$$3, _8$$3, _9$$5, _10$$7;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&levelName);
	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$7);
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
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_count_int(&_1$$3) == 0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "No adapters specified", "phalcon/Logger/AbstractLogger.zep", 275);
			return;
		}
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		if (1 == zephir_array_isset_long(&levels, level)) {
			ZEPHIR_OBS_VAR(&levelName);
			zephir_array_fetch_long(&levelName, &levels, level, PH_NOISY, "phalcon/Logger/AbstractLogger.zep", 279);
		} else {
			ZEPHIR_OBS_NVAR(&levelName);
			zephir_array_fetch_long(&levelName, &levels, 8, PH_NOISY, "phalcon/Logger/AbstractLogger.zep", 279);
		}
		ZEPHIR_INIT_VAR(&item);
		object_init_ex(&item, phalcon_logger_item_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, php_date_get_immutable_ce());
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("timezone"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "now");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, level);
		ZEPHIR_CALL_METHOD(NULL, &item, "__construct", NULL, 125, &message, &levelName, &_5$$3, &_2$$3, &context);
		zephir_check_call_status();
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("excluded"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&collection, "array_diff_key", NULL, 126, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_is_iterable(&collection, 0, "phalcon/Logger/AbstractLogger.zep", 305);
		if (Z_TYPE_P(&collection) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _7$$3)
			{
				ZEPHIR_INIT_NVAR(&adapter);
				ZVAL_COPY(&adapter, _7$$3);
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_STRING(&method, "process");
				ZEPHIR_CALL_METHOD(&_9$$5, &adapter, "intransaction", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_9$$5)) {
					ZEPHIR_INIT_NVAR(&method);
					ZVAL_STRING(&method, "add");
				}
				ZEPHIR_CALL_METHOD_ZVAL(NULL, &adapter, &method, NULL, 0, &item);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_8$$3, &collection, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&adapter, &collection, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&method);
					ZVAL_STRING(&method, "process");
					ZEPHIR_CALL_METHOD(&_10$$7, &adapter, "intransaction", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_10$$7)) {
						ZEPHIR_INIT_NVAR(&method);
						ZVAL_STRING(&method, "add");
					}
					ZEPHIR_CALL_METHOD_ZVAL(NULL, &adapter, &method, NULL, 0, &item);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&adapter);
		ZEPHIR_INIT_NVAR(&_4$$3);
		array_init(&_4$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("excluded"), &_4$$3);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Converts the level from string/word to an integer
 *
 * @param mixed $level
 *
 * @return int
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getLevelNumber)
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


	if (1 == Z_TYPE_P(level) == IS_STRING) {
		ZEPHIR_INIT_VAR(&levelName);
		zephir_fast_strtoupper(&levelName, level);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&levels, "array_flip", NULL, 127, &_0$$3);
		zephir_check_call_status();
		if (zephir_array_isset(&levels, &levelName)) {
			zephir_array_fetch(&_1$$4, &levels, &levelName, PH_NOISY | PH_READONLY, "phalcon/Logger/AbstractLogger.zep", 330);
			RETURN_CTOR(&_1$$4);
		}
	} else if (1 == zephir_is_numeric(level)) {
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		if (zephir_array_isset(&levels, level)) {
			RETURN_MM_LONG(zephir_get_intval(level));
		}
	}
	RETURN_MM_LONG(8);
}

/**
 * Returns an array of log levels with integer to string conversion
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getLevels)
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

zend_object *zephir_init_properties_Phalcon_Logger_AbstractLogger(zend_class_entry *class_type)
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

