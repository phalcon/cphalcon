
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "logger/adapterinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_logger_adapterinterface_ce;

static const zend_function_entry phalcon_logger_adapterinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setFormatter, arginfo_phalcon_logger_adapterinterface_setformatter)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getFormatter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setLogLevel, arginfo_phalcon_logger_adapterinterface_setloglevel)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getLogLevel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, log, arginfo_phalcon_logger_adapterinterface_log)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, debug, arginfo_phalcon_logger_adapterinterface_debug)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, info, arginfo_phalcon_logger_adapterinterface_info)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, notice, arginfo_phalcon_logger_adapterinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, warning, arginfo_phalcon_logger_adapterinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, error, arginfo_phalcon_logger_adapterinterface_error)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, critical, arginfo_phalcon_logger_adapterinterface_critical)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, alert, arginfo_phalcon_logger_adapterinterface_alert)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, emergency, arginfo_phalcon_logger_adapterinterface_emergency)
	PHP_FE_END
};

/**
 * Phalcon\Logger\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Logger, AdapterInterface, logger_adapterinterface, phalcon_logger_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the message formatter
 *
 * @param Phalcon\Logger\FormatterInterface $formatter
 * @return Phalcon\Logger\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, setFormatter);

/**
 * Returns the internal formatter
 *
 * @return Phalcon\Logger\FormatterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, getFormatter);

/**
 * Filters the logs sent to the handlers to be greater or equals than a specific level
 *
 * @param int $level
 * @return Phalcon\Logger\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, setLogLevel);

/**
 * Returns the current log level
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, getLogLevel);

/**
 * Sends/Writes messages to the file log
 *
 * @param int|string $type
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, log);

/**
 * Starts a transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, begin);

/**
 * Commits the internal transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, commit);

/**
 * Rollbacks the internal transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, rollback);

/**
 * Closes the logger
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, close);

/**
 * Sends/Writes a debug message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, debug);

/**
 * Sends/Writes an info message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, info);

/**
 * Sends/Writes a notice message to the log
 *
 * @param string $message
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, notice);

/**
 * Sends/Writes a warning message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, warning);

/**
 * Sends/Writes an error message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, error);

/**
 * Sends/Writes a critical message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, critical);

/**
 * Sends/Writes an alert message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, alert);

/**
 * Sends/Writes an emergency message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, emergency);
