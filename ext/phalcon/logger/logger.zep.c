
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
 * (c) Phalcon Team <team@phalconphp.com>
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
 *<code>
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
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Logger) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Logger, phalcon, logger_logger, phalcon_logger_logger_method_entry, 0);

	/**
	 * The adapter stack
	 *
	 * @var AdapterInterface[]
	 */
	zend_declare_property_null(phalcon_logger_logger_ce, SL("adapters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_logger_ce, SL("name"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The excluded adapters for this log process
	 *
	 * @var AdapterInterface[]
	 */
	zend_declare_property_null(phalcon_logger_logger_ce, SL("excluded"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_class_implements(phalcon_logger_logger_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\log\\loggerinterface")));
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param string name     The name of the logger
 * @param array  adapters The collection of adapters to be used for logging (default [])
 */
PHP_METHOD(Phalcon_Logger_Logger, __construct) {

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
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
 * @param string             name    The name of the adapter
 * @param <AdapterInterface> adapter The adapter to add to the stack
 */
PHP_METHOD(Phalcon_Logger_Logger, addAdapter) {

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
PHP_METHOD(Phalcon_Logger_Logger, alert) {

	zval _0;
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
PHP_METHOD(Phalcon_Logger_Logger, critical) {

	zval _0;
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
PHP_METHOD(Phalcon_Logger_Logger, debug) {

	zval _0;
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
PHP_METHOD(Phalcon_Logger_Logger, error) {

	zval _0;
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
PHP_METHOD(Phalcon_Logger_Logger, emergency) {

	zval _0;
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
PHP_METHOD(Phalcon_Logger_Logger, excludeAdapters) {

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
	zephir_is_iterable(&adapters, 0, "phalcon/Logger/Logger.zep", 185);
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
 * @throws <Exception>
 */
PHP_METHOD(Phalcon_Logger_Logger, getAdapter) {

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
	if (!(zephir_array_isset_fetch(&adapter, &adapters, &name, 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter does not exist for this logger", "phalcon/Logger/Logger.zep", 202);
		return;
	}
	RETURN_CCTOR(&adapter);

}

/**
 * Returns the adapter stack array
 *
 * @return AdapterInterface[]
 */
PHP_METHOD(Phalcon_Logger_Logger, getAdapters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "adapters");

}

/**
 * Returns the name of the logger
 */
PHP_METHOD(Phalcon_Logger_Logger, getName) {

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
PHP_METHOD(Phalcon_Logger_Logger, info) {

	zval _0;
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
PHP_METHOD(Phalcon_Logger_Logger, log) {

	zval _0;
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


	ZEPHIR_CALL_METHOD(&intLevel, this_ptr, "getlevelnumber", NULL, 408, level);
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
PHP_METHOD(Phalcon_Logger_Logger, notice) {

	zval _0;
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
 * @throws <Logger\Exception>
 */
PHP_METHOD(Phalcon_Logger_Logger, removeAdapter) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter does not exist for this logger", "phalcon/Logger/Logger.zep", 277);
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
PHP_METHOD(Phalcon_Logger_Logger, setAdapters) {

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
 * Exceptional occurrences that are not errors.
 *
 * Example: Use of deprecated APIs, poor use of an API, undesirable things
 * that are not necessarily wrong.
 *
 * @param string message
 */
PHP_METHOD(Phalcon_Logger_Logger, warning) {

	zval _0;
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
 * @throws <Logger\Exception>
 */
PHP_METHOD(Phalcon_Logger_Logger, addMessage) {

	zend_string *_5;
	zend_ulong _4;
	zval context;
	zval message;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, adapter, key, excluded, levelName, levels, item, registered, _0, _1, *_2, _3, _6;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
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


	ZEPHIR_OBS_VAR(&registered);
	zephir_read_property(&registered, this_ptr, SL("adapters"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("excluded"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&excluded, &_0);
	if (zephir_fast_count_int(&registered TSRMLS_CC) == 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "No adapters specified", "phalcon/Logger/Logger.zep", 328);
		return;
	}
	ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&levelName);
	if (!(zephir_array_isset_long_fetch(&levelName, &levels, level, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(&levelName);
		zephir_array_fetch_long(&levelName, &levels, 8, PH_NOISY, "phalcon/Logger/Logger.zep", 334 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&item);
	object_init_ex(&item, phalcon_logger_item_ce);
	ZEPHIR_INIT_VAR(&_1);
	zephir_time(&_1);
	ZVAL_LONG(&_0, level);
	ZEPHIR_CALL_METHOD(NULL, &item, "__construct", NULL, 409, &message, &levelName, &_0, &_1, &context);
	zephir_check_call_status();
	zephir_is_iterable(&registered, 0, "phalcon/Logger/Logger.zep", 351);
	if (Z_TYPE_P(&registered) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&registered), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _2);
			if (!(zephir_array_isset(&excluded, &key))) {
				ZEPHIR_CALL_METHOD(NULL, &adapter, "process", NULL, 0, &item);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &registered, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &registered, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &registered, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&adapter, &registered, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&excluded, &key))) {
					ZEPHIR_CALL_METHOD(NULL, &adapter, "process", NULL, 0, &item);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &registered, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_6);
	array_init(&_6);
	zephir_update_property_zval(this_ptr, SL("excluded"), &_6);
	RETURN_MM_BOOL(1);

}

/**
 * Returns an array of log levels with integer to string conversion
 */
PHP_METHOD(Phalcon_Logger_Logger, getLevels) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 9, 0 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Logger_Logger, getLevelNumber) {

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
		ZEPHIR_CALL_FUNCTION(&levels, "array_flip", NULL, 155, &_0$$3);
		zephir_check_call_status();
		if (zephir_array_isset_fetch(&numberLevel, &levels, &levelName, 1 TSRMLS_CC)) {
			RETURN_CTOR(&numberLevel);
		}
	} else if (zephir_is_numeric(level)) {
		ZEPHIR_CALL_METHOD(&levels, this_ptr, "getlevels", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&numberLevel);
		if (zephir_array_isset_fetch(&numberLevel, &levels, level, 0 TSRMLS_CC)) {
			RETURN_CTOR(&numberLevel);
		}
	}
	RETURN_MM_LONG(8);

}

zend_object *zephir_init_properties_Phalcon_Logger_Logger(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
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

