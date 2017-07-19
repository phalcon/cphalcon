
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Logger;

/**
 * Phalcon\Logger\AdapterInterface
 *
 * Interface for Phalcon\Logger adapters
 */
interface AdapterInterface
{

	/**
	 * Sets the message formatter
	 */
	public function setFormatter(<FormatterInterface> formatter) -> <AdapterInterface>;

	/**
	 * Returns the internal formatter
	 */
	public function getFormatter() -> <FormatterInterface>;

	/**
	 * Filters the logs sent to the handlers to be greater or equals than a specific level
	 */
	public function setLogLevel(int level) -> <AdapterInterface>;

	/**
	 * Returns the current log level
	 */
	public function getLogLevel() -> int;

	/**
	 * Sends/Writes messages to the file log
	 */
	public function log(var type, var message = null, array! context = null) -> <AdapterInterface>;

	/**
 	 * Starts a transaction
 	 */
	public function begin() -> <AdapterInterface>;

	/**
 	 * Commits the internal transaction
 	 */
	public function commit() -> <AdapterInterface>;

	/**
 	 * Rollbacks the internal transaction
 	 */
	public function rollback() -> <AdapterInterface>;

	/**
 	 * Closes the logger
 	 */
	public function close() -> boolean;

	/**
 	 * Sends/Writes a debug message to the log
 	 */
	public function debug(string! message, array! context = null) -> <AdapterInterface>;

	/**
 	 * Sends/Writes an error message to the log
 	 */
	public function error(string! message, array! context = null) -> <AdapterInterface>;

	/**
 	 * Sends/Writes an info message to the log
 	 */
	public function info(string! message, array! context = null) -> <AdapterInterface>;

	/**
 	 * Sends/Writes a notice message to the log
 	 */
	public function notice(string! message, array! context = null) -> <AdapterInterface>;

	/**
 	 * Sends/Writes a warning message to the log
 	 */
	public function warning(string! message, array! context = null) -> <AdapterInterface>;

	/**
 	 * Sends/Writes an alert message to the log
 	 */
	public function alert(string! message, array! context = null) -> <AdapterInterface>;

	/**
 	 * Sends/Writes an emergency message to the log
 	 */
	public function emergency(string! message, array! context = null) -> <AdapterInterface>;
}
