
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Logger\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Logger, AdapterInterface, logger_adapterinterface, phalcon_logger_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Set the log format
 *
 * @param string $format
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, setFormat);

/**
 * Returns the log format
 *
 * @return format
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, getFormat);

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, getTypeString);

/**
 * Sets the internal date format
 *
 * @param string $date
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, setDateFormat);

/**
 * Returns the internal date format
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, getDateFormat);

/**
 * Sends/Writes messages to the file log
 *
 * @param string $message
 * @param int $type
 */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, log);

/**
  * Starts a transaction
  *
  */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, begin);

/**
  * Commits the internal transaction
  *
  */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, commit);

/**
  * Rollbacks the internal transaction
  *
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
  * @param ing $type
  */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, debug);

/**
  * Sends/Writes an error message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, error);

/**
  * Sends/Writes an info message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, info);

/**
  * Sends/Writes a notice message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, notice);

/**
  * Sends/Writes a warning message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, warning);

/**
  * Sends/Writes an alert message to the log
  *
  * @param string $message
  * @param ing $type
  */
PHALCON_DOC_METHOD(Phalcon_Logger_AdapterInterface, alert);

