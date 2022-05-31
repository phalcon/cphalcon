
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for Phalcon based logger objects.
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Logger, LoggerInterface, phalcon, logger_loggerinterface, phalcon_logger_loggerinterface_method_entry);

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
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, alert);
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
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, critical);
/**
 * Detailed debug information.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, debug);
/**
 * System is unusable.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, emergency);
/**
 * Runtime errors that do not require immediate action but should typically
 * be logged and monitored.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, error);
/**
 * Returns an adapter from the stack
 *
 * @param string $name The name of the adapter
 *
 * @return AdapterInterface
 * @throws Exception
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, getAdapter);
/**
 * Returns the adapter stack array
 *
 * @return AdapterInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, getAdapters);
/**
 * Returns the log level
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, getLogLevel);
/**
 * Returns the name of the logger
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, getName);
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
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, info);
/**
 * Logs with an arbitrary level.
 *
 * @param mixed  $level
 * @param string $message
 * @param array  $context
 *
 * @return void
 *
 * @throws Exception
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, log);
/**
 * Normal but significant events.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, notice);
/**
 * Normal but significant events.
 *
 * @param string $message
 * @param array  $context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_LoggerInterface, warning);
