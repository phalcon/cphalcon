
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Canonical contract for Phalcon\Logger\Logger.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Logger_Logger)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Logger, Logger, phalcon, contracts_logger_logger, phalcon_contracts_logger_logger_method_entry);

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
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, alert);
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
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, critical);
/**
 * Detailed debug information.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, debug);
/**
 * System is unusable.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, emergency);
/**
 * Runtime errors that do not require immediate action but should typically
 * be logged and monitored.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, error);
/**
 * Returns an adapter from the stack
 *
 * @param string $name The name of the adapter
 *
 * @return Adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, getAdapter);
/**
 * Returns the adapter stack array
 *
 * @return Adapter[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, getAdapters);
/**
 * Returns the log level
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, getLogLevel);
/**
 * Returns the name of the logger
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, getName);
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
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, info);
/**
 * Logs with an arbitrary level.
 *
 * An unknown level (a typo or an unmapped value) is not rejected; it maps
 * to the CUSTOM level and is logged, rather than raising an exception.
 *
 * @param mixed  $level
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, log);
/**
 * Normal but significant events.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, notice);
/**
 * Extra-verbose diagnostic output.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, trace);
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
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Logger, warning);
