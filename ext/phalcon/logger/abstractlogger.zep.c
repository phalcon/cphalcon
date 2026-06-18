
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
 * Abstract logger class, providing common functionality. A formatter interface
 * is available as well as an adapter one. Adapters can be created easily using
 * the built in AdapterFactory. A LoggerFactory is also available that allows
 * developers to create new instances of the Logger or load them from config
 * files (see Phalcon\Config\Config object).
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
	 * Clock used to timestamp log items
	 *
	 * @var ClockInterface
	 */
	zend_declare_property_null(phalcon_logger_abstractlogger_ce, SL("clock"), ZEND_ACC_PROTECTED);
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
	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("ALERT"), 2);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("CRITICAL"), 1);

	/**
	 * Default threshold and fallback sink. It sits between DEBUG (7) and
	 * TRACE (9) in the ordering, so the default log level excludes TRACE.
	 * It is also the fallback for unknown message levels and invalid
	 * setLogLevel() values.
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("CUSTOM"), 8);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("DEBUG"), 7);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("EMERGENCY"), 0);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("ERROR"), 3);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("INFO"), 6);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("NOTICE"), 5);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("TRACE"), 9);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_logger_abstractlogger_ce, SL("WARNING"), 4);

	return SUCCESS;
}

/**
 * Constructor.
 *
 * @param string            $name     The name of the logger
 * @param array             $adapters The collection of adapters to be used
 *                                    for logging (default [])
 * @param DateTimeZone|null   $timezone Timezone. If omitted,
 *                                      date_Default_timezone_get() is used
 * @param ClockInterface|null $clock    Clock used to timestamp log items.
 *                                      Defaults to a SystemClock on the
 *                                      resolved timezone.
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval adapters;
	zval name_zv, *adapters_param = NULL, *timezone = NULL, timezone_sub, *clock = NULL, clock_sub, __$null, defaultTimezone;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&timezone_sub);
	ZVAL_UNDEF(&clock_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&defaultTimezone);
	ZVAL_UNDEF(&adapters);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(adapters, adapters_param)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(timezone, php_date_get_timezone_ce())
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(clock, phalcon_time_clock_clockinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		adapters_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		timezone = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		clock = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
	if (!clock) {
		clock = &clock_sub;
		ZEPHIR_CPY_WRT(clock, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(clock);
	}
	if (Z_TYPE_P(timezone) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&defaultTimezone, "date_default_timezone_get", NULL, 190);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("timezone"), timezone);
	if (Z_TYPE_P(clock) == IS_NULL) {
		ZEPHIR_INIT_NVAR(clock);
		object_init_ex(clock, phalcon_time_clock_systemclock_ce);
		ZEPHIR_CALL_METHOD(NULL, clock, "__construct", NULL, 191, timezone);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("clock"), clock);
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
 * @return static
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, addAdapter)
{
	zval name_zv, *adapter, adapter_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&adapter_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_logger_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	adapter = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("adapters"), &name_zv, adapter);
	RETURN_THISW();
}

/**
 * Starts a transaction on every (non-excluded) adapter in the stack.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, begin)
{
	zend_bool _4;
	zval adapter, collection, _0, _1, *_2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("excluded"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&collection, "array_diff_key", NULL, 192, &_0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&collection, 0, "phalcon/Logger/AbstractLogger.zep", 194);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _2)
		{
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _2);
			ZEPHIR_CALL_METHOD(NULL, &adapter, "begin", NULL, 0);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapter, &collection, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &adapter, "begin", NULL, 0);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	RETURN_THIS();
}

/**
 * Commits the transaction on every (non-excluded) adapter in the stack.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, commit)
{
	zend_bool _4;
	zval adapter, collection, _0, _1, *_2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("excluded"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&collection, "array_diff_key", NULL, 192, &_0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&collection, 0, "phalcon/Logger/AbstractLogger.zep", 211);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _2)
		{
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _2);
			ZEPHIR_CALL_METHOD(NULL, &adapter, "commit", NULL, 0);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapter, &collection, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &adapter, "commit", NULL, 0);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	RETURN_THIS();
}

/**
 * Exclude certain adapters.
 *
 * @param array $adapters
 *
 * @return static
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, excludeAdapters)
{
	zend_bool _2;
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
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(adapters, adapters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &adapters_param);
	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
		zephir_get_arrval(&adapters, adapters_param);
	}
	zephir_memory_observe(&registered);
	zephir_read_property(&registered, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC);
	zephir_is_iterable(&adapters, 0, "phalcon/Logger/AbstractLogger.zep", 243);
	if (Z_TYPE_P(&adapters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&adapters), _0)
		{
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _0);
			if (1 == zephir_array_isset_value(&registered, &adapter)) {
				zephir_update_property_array(this_ptr, SL("excluded"), &adapter, &__$true);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &adapters, "rewind", NULL, 0);
		zephir_check_call_status();
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &adapters, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_1, &adapters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapter, &adapters, "current", NULL, 0);
			zephir_check_call_status();
				if (1 == zephir_array_isset_value(&registered, &adapter)) {
					zephir_update_property_array(this_ptr, SL("excluded"), &adapter, &__$true);
				}
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
 * @throws AdapterNotFound
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _2, _3, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset_value(&_0, &name_zv)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_logger_exceptions_adapternotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 193, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Logger/AbstractLogger.zep", 257);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Logger/AbstractLogger.zep", 260);
	RETURN_CTOR(&_3);
}

/**
 * Returns the adapter stack array
 *
 * @return AdapterInterface[]
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getAdapters)
{

	RETURN_MEMBER_TYPED(getThis(), "adapters", IS_ARRAY);
}

/**
 * Returns the log level
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getLogLevel)
{

	RETURN_MEMBER_TYPED(getThis(), "logLevel", IS_LONG);
}

/**
 * Returns the name of the logger
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

/**
 * Removes an adapter from the stack
 *
 * @param string $name The name of the adapter
 *
 * @return static
 * @throws AdapterNotFound
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, removeAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _2, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset_value(&_0, &name_zv)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_logger_exceptions_adapternotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 193, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Logger/AbstractLogger.zep", 300);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_unset_property_array(this_ptr, ZEND_STRL("adapters"), &name_zv);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_2, &name_zv, PH_SEPARATE);
	RETURN_THIS();
}

/**
 * Rolls back the transaction on every (non-excluded) adapter in the stack.
 *
 * @return static
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, rollback)
{
	zend_bool _4;
	zval adapter, collection, _0, _1, *_2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("excluded"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&collection, "array_diff_key", NULL, 192, &_0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&collection, 0, "phalcon/Logger/AbstractLogger.zep", 322);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _2)
		{
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _2);
			ZEPHIR_CALL_METHOD(NULL, &adapter, "rollback", NULL, 0);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapter, &collection, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &adapter, "rollback", NULL, 0);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	RETURN_THIS();
}

/**
 * Sets the adapters stack overriding what is already there
 *
 * @param array $adapters An array of adapters
 *
 * @return static
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, setAdapters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *adapters_param = NULL;
	zval adapters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapters);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(adapters, adapters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &adapters_param);
	zephir_get_arrval(&adapters, adapters_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapters"), &adapters);
	RETURN_THIS();
}

/**
 * Sets the minimum log level for the logger.
 *
 * An unknown level is not rejected: it is stored as CUSTOM, which sits
 * between DEBUG and TRACE in the ordering, so the threshold becomes
 * "everything except TRACE".
 *
 * @param int $level
 *
 * @return static
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, setLogLevel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *level_param = NULL, levels, _0;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &level_param);
	ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (1 == zephir_array_isset_value_long(&levels, level)) {
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
 * @throws NoAdaptersConfigured
 */
PHP_METHOD(Phalcon_Logger_AbstractLogger, addMessage)
{
	zend_bool _10$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zend_string *message = NULL;
	zval *level_param = NULL, message_zv, *context_param = NULL, adapter, collection, item, levelName, levels, _0, _12, _1$$3, _3$$3, _4$$3, _5$$3, _6$$3, *_7$$3, _9$$3, _2$$4, _8$$5, _11$$8;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&levelName);
	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&context);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_LONG(level)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	level_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		context_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
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
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_logger_exceptions_noadaptersconfigured_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 194);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Logger/AbstractLogger.zep", 380);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		if (1 == zephir_array_isset_value_long(&levels, level)) {
			zephir_memory_observe(&levelName);
			zephir_array_fetch_long(&levelName, &levels, level, PH_NOISY, "phalcon/Logger/AbstractLogger.zep", 384);
		} else {
			ZEPHIR_OBS_NVAR(&levelName);
			zephir_array_fetch_long(&levelName, &levels, 8, PH_NOISY, "phalcon/Logger/AbstractLogger.zep", 384);
		}
		ZEPHIR_INIT_VAR(&item);
		object_init_ex(&item, phalcon_logger_item_ce);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("clock"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "now", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, level);
		ZEPHIR_CALL_METHOD(NULL, &item, "__construct", NULL, 195, &message_zv, &levelName, &_5$$3, &_4$$3, &context);
		zephir_check_call_status();
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("excluded"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&collection, "array_diff_key", NULL, 192, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_is_iterable(&collection, 0, "phalcon/Logger/AbstractLogger.zep", 405);
		if (Z_TYPE_P(&collection) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _7$$3)
			{
				ZEPHIR_INIT_NVAR(&adapter);
				ZVAL_COPY(&adapter, _7$$3);
				ZEPHIR_CALL_METHOD(&_8$$5, &adapter, "intransaction", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_8$$5)) {
					ZEPHIR_CALL_METHOD(NULL, &adapter, "add", NULL, 0, &item);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &adapter, "process", NULL, 0, &item);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
			zephir_check_call_status();
			_10$$3 = 1;
			while (1) {
				if (_10$$3) {
					_10$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_9$$3, &collection, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&adapter, &collection, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_11$$8, &adapter, "intransaction", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_11$$8)) {
						ZEPHIR_CALL_METHOD(NULL, &adapter, "add", NULL, 0, &item);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &adapter, "process", NULL, 0, &item);
						zephir_check_call_status();
					}
			}
		}
		ZEPHIR_INIT_NVAR(&adapter);
	}
	ZEPHIR_INIT_VAR(&_12);
	array_init(&_12);
	zephir_update_property_zval(this_ptr, ZEND_STRL("excluded"), &_12);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(level)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &level);
	if (Z_TYPE_P(level) == IS_STRING) {
		ZEPHIR_INIT_VAR(&levelName);
		zephir_fast_strtolower(&levelName, level);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&levels, "array_flip", NULL, 196, &_0$$3);
		zephir_check_call_status();
		if (zephir_array_isset_value(&levels, &levelName)) {
			zephir_array_fetch(&_1$$4, &levels, &levelName, PH_NOISY | PH_READONLY, "phalcon/Logger/AbstractLogger.zep", 436);
			RETURN_CTOR(&_1$$4);
		}
	} else if (1 == zephir_is_numeric(level)) {
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		if (zephir_array_isset_value(&levels, level)) {
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

	zephir_create_array(return_value, 10, 0);
	add_index_stringl(return_value, 2, SL("alert"));
	add_index_stringl(return_value, 1, SL("critical"));
	add_index_stringl(return_value, 7, SL("debug"));
	add_index_stringl(return_value, 0, SL("emergency"));
	add_index_stringl(return_value, 3, SL("error"));
	add_index_stringl(return_value, 6, SL("info"));
	add_index_stringl(return_value, 5, SL("notice"));
	add_index_stringl(return_value, 4, SL("warning"));
	add_index_stringl(return_value, 8, SL("custom"));
	add_index_stringl(return_value, 9, SL("trace"));
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
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

