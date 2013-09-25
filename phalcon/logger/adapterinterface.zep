
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
	 *
	 * @param Phalcon\Logger\FormatterInterface formatter
	 * @return Phalcon\Logger\Adapter
	 */
	public function setFormatter(<Phalcon\Logger\FormatterInterface> formatter);

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
	 * @param string message
	 * @param int type
	 * @return Phalcon\Logger\Adapter
	 */
	public function log(string message, int type=7);

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
 	 *
 	 * @return boolean
 	 */
	public function close();

	/**
 	 * Sends/Writes a debug message to the log
 	 *
 	 * @param string message
 	 * @param ing type
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function debug(string message);

	/**
 	 * Sends/Writes an error message to the log
 	 *
 	 * @param string message
 	 * @param ing type
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function error(string message);

	/**
 	 * Sends/Writes an info message to the log
 	 *
 	 * @param string message
 	 * @param ing type
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function info(string message);

	/**
 	 * Sends/Writes a notice message to the log
 	 *
 	 * @param string message
 	 * @param ing type
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function notice(string message);

	/**
 	 * Sends/Writes a warning message to the log
 	 *
 	 * @param string message
 	 * @param ing type
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function warning(string message);

	/**
 	 * Sends/Writes an alert message to the log
 	 *
 	 * @param string message
 	 * @param ing type
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function alert(string message);

}

