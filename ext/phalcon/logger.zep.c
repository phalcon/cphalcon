
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/time.h"
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
 * Phalcon\Logger
 *
 * This component offers logging capabilities for your application. The
 * component accepts multiple adapters, working also as a multiple logger.
 * Phalcon\Logger implements PSR-3.
 *
 *```php
 * use Phalcon\Logger;
 * use Phalcon\Logger\Adapter\Stream;
 *
 * $adapter1 = new Stream('/logs/first-log.log');
 * $adapter2 = new Stream('/remote/second-log.log');
 * $adapter3 = new Stream('/manager/third-log.log');
 *
 * $logger = new Logger(
 *         'messages',
 *         [
 *             'local'   => $adapter1,
 *             'remote'  => $adapter2,
 *             'manager' => $adapter3,
 *         ]
 *     );
 *
 * // Log to all adapters
 * $logger->error('Something went wrong');
 *
 * // Log to specific adapters
 * $logger
 *         ->excludeAdapters(['manager'])
 *         ->info('This does not go to the "manager" logger);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Logger, phalcon, logger, phalcon_logger_method_entry, 0);

	/**
	 * The adapter stack
	 *
	 * @var AdapterInterface[]
	 */
	zend_declare_property_null(phalcon_logger_ce, SL("adapters"), ZEND_ACC_PROTECTED);

	/**
	 * Minimum log level for the logger
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_ce, SL("logLevel"), 8, ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_ce, SL("name"), "", ZEND_ACC_PROTECTED);

	/**
	 * The excluded adapters for this log process
	 *
	 * @var AdapterInterface[]
	 */
	zend_declare_property_null(phalcon_logger_ce, SL("excluded"), ZEND_ACC_PROTECTED);

	phalcon_logger_ce->create_object = zephir_init_properties_Phalcon_Logger;
	zephir_declare_class_constant_long(phalcon_logger_ce, SL("ALERT"), 2);

	zephir_declare_class_constant_long(phalcon_logger_ce, SL("CRITICAL"), 1);

	zephir_declare_class_constant_long(phalcon_logger_ce, SL("CUSTOM"), 8);

	zephir_declare_class_constant_long(phalcon_logger_ce, SL("DEBUG"), 7);

	zephir_declare_class_constant_long(phalcon_logger_ce, SL("EMERGENCY"), 0);

	zephir_declare_class_constant_long(phalcon_logger_ce, SL("ERROR"), 3);

	zephir_declare_class_constant_long(phalcon_logger_ce, SL("INFO"), 6);

	zephir_declare_class_constant_long(phalcon_logger_ce, SL("NOTICE"), 5);

	zephir_declare_class_constant_long(phalcon_logger_ce, SL("WARNING"), 4);

	zend_class_implements(phalcon_logger_ce, 1, zephir_get_internal_ce(SL("psr\\log\\loggerinterface")));
	return SUCCESS;

}

/**
 * Minimum log level for the logger
 */
PHP_METHOD(Phalcon_Logger, getLogLevel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "logLevel");

}

/**
 * Constructor.
 *
 * @param string name     The name of the logger
 * @param array  adapters The collection of adapters to be used for logging (default [])
 */
PHP_METHOD(Phalcon_Logger, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval adapters;
	zval *name_param = NULL, *adapters_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &adapters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&adapters, adapters_param);
	}


	zephir_update_property_zval(this_ptr, SL("name"), &name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setadapters", NULL, 0, &adapters);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Add an adapter to the stack. For processing we use FIFO
 *
 * @param string           name    The name of the adapter
 * @param AdapterInterface adapter The adapter to add to the stack
 */
PHP_METHOD(Phalcon_Logger, addAdapter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *adapter, adapter_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapter_sub);

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
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, alert) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_get_strval(&_0, message);
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
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, critical) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_get_strval(&_0, message);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Detailed debug information.
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, debug) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_get_strval(&_0, message);
	ZVAL_LONG(&_1, 7);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Runtime errors that do not require immediate action but should typically
 * be logged and monitored.
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, error) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_get_strval(&_0, message);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * System is unusable.
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, emergency) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_get_strval(&_0, message);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Exclude certain adapters.
 */
PHP_METHOD(Phalcon_Logger, excludeAdapters) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *adapters_param = NULL, __$true, name, registered, *_0, _1;
	zval adapters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapters);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&registered);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &adapters_param);

	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
		zephir_get_arrval(&adapters, adapters_param);
	}


	zephir_read_property(&registered, this_ptr, SL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&adapters, 0, "phalcon/Logger.zep", 191);
	if (Z_TYPE_P(&adapters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&adapters), _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _0);
			if (zephir_array_isset(&registered, &name)) {
				zephir_update_property_array(this_ptr, SL("excluded"), &name, &__$true);
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
			ZEPHIR_CALL_METHOD(&name, &adapters, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset(&registered, &name)) {
					zephir_update_property_array(this_ptr, SL("excluded"), &name, &__$true);
				}
			ZEPHIR_CALL_METHOD(NULL, &adapters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();

}

/**
 * Returns an adapter from the stack
 *
 * @param string name The name of the adapter
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Logger, getAdapter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, adapter, adapters, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("adapters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&adapters, &_0);
	ZEPHIR_OBS_VAR(&adapter);
	if (!(zephir_array_isset_fetch(&adapter, &adapters, &name, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter does not exist for this logger", "phalcon/Logger.zep", 208);
		return;
	}
	RETURN_CCTOR(&adapter);

}

/**
 * Returns the adapter stack array
 *
 * @return AdapterInterface[]
 */
PHP_METHOD(Phalcon_Logger, getAdapters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "adapters");

}

/**
 * Returns the name of the logger
 */
PHP_METHOD(Phalcon_Logger, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Interesting events.
 *
 * Example: User logs in, SQL logs.
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, info) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_get_strval(&_0, message);
	ZVAL_LONG(&_1, 6);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Logs with an arbitrary level.
 *
 * @param mixed  level
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, log) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_CALL_METHOD(&intLevel, this_ptr, "getlevelnumber", NULL, 429, level);
	zephir_check_call_status();
	zephir_get_strval(&_0, message);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, level, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Normal but significant events.
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, notice) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_get_strval(&_0, message);
	ZVAL_LONG(&_1, 5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an adapter from the stack
 *
 * @param string name The name of the adapter
 *
 * @throws Logger\Exception
 */
PHP_METHOD(Phalcon_Logger, removeAdapter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, adapters, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("adapters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&adapters, &_0);
	if (1 != zephir_array_isset(&adapters, &name)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter does not exist for this logger", "phalcon/Logger.zep", 283);
		return;
	}
	zephir_array_unset(&adapters, &name, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("adapters"), &adapters);
	RETURN_THIS();

}

/**
 * Sets the adapters stack overriding what is already there
 *
 * @param array adapters An array of adapters
 */
PHP_METHOD(Phalcon_Logger, setAdapters) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *adapters_param = NULL;
	zval adapters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &adapters_param);

	ZEPHIR_OBS_COPY_OR_DUP(&adapters, adapters_param);


	zephir_update_property_zval(this_ptr, SL("adapters"), &adapters);
	RETURN_THIS();

}

/**
 * Sets the log level above which we can log
 */
PHP_METHOD(Phalcon_Logger, setLogLevel) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *level_param = NULL, levels, _0;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&_0);

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
	zephir_update_property_zval(this_ptr, SL("logLevel"), &_0);
	RETURN_THIS();

}

/**
 * Exceptional occurrences that are not errors.
 *
 * Example: Use of deprecated APIs, poor use of an API, undesirable things
 * that are not necessarily wrong.
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger, warning) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_get_strval(&_0, message);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmessage", NULL, 0, &_1, &_0, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a message to each handler for processing
 *
 * @param int    level
 * @param string message
 *
 * @throws Logger\Exception
 */
PHP_METHOD(Phalcon_Logger, addMessage) {

	zend_string *_6$$3;
	zend_ulong _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zval message;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, adapter, key, excluded, levelName, levels, item, registered, _0, _1$$3, _2$$3, *_3$$3, _4$$3, _9$$3, _7$$7, _8$$11;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&excluded);
	ZVAL_UNDEF(&levelName);
	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&registered);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context);

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


	zephir_read_property(&_0, this_ptr, SL("logLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GE_LONG(&_0, level)) {
		ZEPHIR_OBS_VAR(&registered);
		zephir_read_property(&registered, this_ptr, SL("adapters"), PH_NOISY_CC);
		zephir_read_property(&_1$$3, this_ptr, SL("excluded"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&excluded, &_1$$3);
		if (zephir_fast_count_int(&registered) == 0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "No adapters specified", "phalcon/Logger.zep", 352);
			return;
		}
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&levelName);
		if (!(zephir_array_isset_long_fetch(&levelName, &levels, level, 0))) {
			ZEPHIR_OBS_NVAR(&levelName);
			zephir_array_fetch_long(&levelName, &levels, 8, PH_NOISY, "phalcon/Logger.zep", 358);
		}
		ZEPHIR_INIT_VAR(&item);
		object_init_ex(&item, phalcon_logger_item_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_time(&_2$$3);
		ZVAL_LONG(&_1$$3, level);
		ZEPHIR_CALL_METHOD(NULL, &item, "__construct", NULL, 430, &message, &levelName, &_1$$3, &_2$$3, &context);
		zephir_check_call_status();
		zephir_is_iterable(&registered, 0, "phalcon/Logger.zep", 379);
		if (Z_TYPE_P(&registered) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&registered), _5$$3, _6$$3, _3$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_6$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _6$$3);
				} else {
					ZVAL_LONG(&key, _5$$3);
				}
				ZEPHIR_INIT_NVAR(&adapter);
				ZVAL_COPY(&adapter, _3$$3);
				if (!(zephir_array_isset(&excluded, &key))) {
					ZEPHIR_CALL_METHOD(&_7$$7, &adapter, "intransaction", NULL, 0);
					zephir_check_call_status();
					if (UNEXPECTED(zephir_is_true(&_7$$7))) {
						ZEPHIR_CALL_METHOD(NULL, &adapter, "add", NULL, 0, &item);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &adapter, "process", NULL, 0, &item);
						zephir_check_call_status();
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &registered, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$3, &registered, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &registered, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&adapter, &registered, "current", NULL, 0);
				zephir_check_call_status();
					if (!(zephir_array_isset(&excluded, &key))) {
						ZEPHIR_CALL_METHOD(&_8$$11, &adapter, "intransaction", NULL, 0);
						zephir_check_call_status();
						if (UNEXPECTED(zephir_is_true(&_8$$11))) {
							ZEPHIR_CALL_METHOD(NULL, &adapter, "add", NULL, 0, &item);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &adapter, "process", NULL, 0, &item);
							zephir_check_call_status();
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &registered, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&adapter);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_INIT_VAR(&_9$$3);
		array_init(&_9$$3);
		zephir_update_property_zval(this_ptr, SL("excluded"), &_9$$3);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns an array of log levels with integer to string conversion
 */
PHP_METHOD(Phalcon_Logger, getLevels) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 9, 0);
	add_index_stringl(return_value, 2, SL("alert"));
	add_index_stringl(return_value, 1, SL("critical"));
	add_index_stringl(return_value, 7, SL("debug"));
	add_index_stringl(return_value, 0, SL("emergency"));
	add_index_stringl(return_value, 3, SL("error"));
	add_index_stringl(return_value, 6, SL("info"));
	add_index_stringl(return_value, 5, SL("notice"));
	add_index_stringl(return_value, 4, SL("warning"));
	add_index_stringl(return_value, 8, SL("custom"));
	return;

}

/**
 * Converts the level from string/word to an integer
 *
 * @param string|int level
 */
PHP_METHOD(Phalcon_Logger, getLevelNumber) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *level, level_sub, levelName, numberLevel, levels, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&levelName);
	ZVAL_UNDEF(&numberLevel);
	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level);



	if (Z_TYPE_P(level) == IS_STRING) {
		ZEPHIR_INIT_VAR(&levelName);
		zephir_fast_strtolower(&levelName, level);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&levels, "array_flip", NULL, 171, &_0$$3);
		zephir_check_call_status();
		if (zephir_array_isset_fetch(&numberLevel, &levels, &levelName, 1)) {
			RETURN_CTOR(&numberLevel);
		}
	} else if (zephir_is_numeric(level)) {
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&numberLevel);
		if (zephir_array_isset_fetch(&numberLevel, &levels, level, 0)) {
			RETURN_CTOR(&numberLevel);
		}
	}
	RETURN_MM_LONG(8);

}

zend_object *zephir_init_properties_Phalcon_Logger(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property(&_0, this_ptr, SL("excluded"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("excluded"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("adapters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("adapters"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

