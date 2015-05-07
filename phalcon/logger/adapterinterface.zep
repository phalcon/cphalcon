
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Logger;

use Phalcon\Logger\FormatterInterface;

/**
 * Phalcon\Logger\AdapterInterface
 *
 * Interface for Phalcon\Logger adapters
 */
interface AdapterInterface
{

	/**
	 * Sets the message formatter
	 *
	 * @return Phalcon\Logger\Adapter
	 */
	public function setFormatter(<FormatterInterface> formatter);

	/**
	 * Returns the internal formatter
	 *
	 * @return Phalcon\Logger\FormatterInterface
	 */
	public function getFormatter();

	/**
	 * Filters the logs sent to the handlers to be greater or equals than a specific level
	 *
	 * @param int level
	 * @return Phalcon\Logger\Adapter
	 */
	public function setLogLevel(int level);

	/**
	 * Returns the current log level
	 *
	 * @return int
	 */
	public function getLogLevel();

	/**
	 * Sends/Writes messages to the file log
	 *
	 * @return Phalcon\Logger\Adapter1
	 */
	public function log(var type, var message = null, array! context = null);

	/**
 	 * Starts a transaction
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function begin();

	/**
 	 * Commits the internal transaction
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function commit();

	/**
 	 * Rollbacks the internal transaction
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function rollback();

	/**
 	 * Closes the logger
 	 */
	public function close() -> boolean;

	/**
 	 * Sends/Writes a debug message to the log
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function debug(string! message, array! context = null);

	/**
 	 * Sends/Writes an error message to the log
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function error(string! message, array! context = null);

	/**
 	 * Sends/Writes an info message to the log
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function info(string! message, array! context = null);

	/**
 	 * Sends/Writes a notice message to the log
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function notice(string! message, array! context = null);

	/**
 	 * Sends/Writes a warning message to the log
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function warning(string! message, array! context = null);

	/**
 	 * Sends/Writes an alert message to the log
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function alert(string! message, array! context = null);

	/**
 	 * Sends/Writes an emergency message to the log
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function emergency(string! message, array! context = null);
}
