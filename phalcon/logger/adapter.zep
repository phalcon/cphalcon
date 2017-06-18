
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

use Phalcon\Logger;
use Phalcon\Logger\Item;
use Phalcon\Logger\Exception;
use Phalcon\Logger\AdapterInterface;
use Phalcon\Logger\FormatterInterface;

/**
 * Phalcon\Logger\Adapter
 *
 * Base class for Phalcon\Logger adapters
 */
abstract class Adapter implements AdapterInterface
{

	/**
	 * Tells if there is an active transaction or not
	 *
	 * @var boolean
	 */
	protected _transaction = false;

	/**
	 * Array with messages queued in the transaction
	 *
	 * @var array
	 */
	protected _queue = [];

	/**
	 * Formatter
	 *
	 * @var object
	 */
	protected _formatter;

	/**
	 * Log level
	 *
	 * @var int
	 */
	protected _logLevel = 9;

	/**
	 * Filters the logs sent to the handlers that are less or equal than a specific level
	 */
	public function setLogLevel(int level) -> <AdapterInterface>
	{
		let this->_logLevel = level;
		return this;
	}

	/**
	 * Returns the current log level
	 */
	public function getLogLevel() -> int
	{
		return this->_logLevel;
	}

	/**
	 * Sets the message formatter
	 */
	public function setFormatter(<FormatterInterface> formatter) -> <AdapterInterface>
	{
		let this->_formatter = formatter;
		return this;
	}

	/**
 	 * Starts a transaction
 	 */
	public function begin() -> <AdapterInterface>
	{
		let this->_transaction = true;
		return this;
	}

	/**
 	 * Commits the internal transaction
 	 */
	public function commit() -> <AdapterInterface>
	{
		var message;

		if !this->_transaction {
			throw new Exception("There is no active transaction");
		}

		let this->_transaction = false;

		/**
		 * Check if the queue has something to log
		 */
		for message in this->_queue {
			this->{"logInternal"}(
				message->getMessage(),
				message->getType(),
				message->getTime(),
				message->getContext()
			);
		}

		// clear logger queue at commit
		let this->_queue = [];

		return this;
	}

	/**
 	 * Rollbacks the internal transaction
 	 */
	public function rollback() -> <AdapterInterface>
	{
		var transaction;

		let transaction = this->_transaction;
		if !transaction {
			throw new Exception("There is no active transaction");
		}

		let this->_transaction = false,
			this->_queue = [];

		return this;
	}

	/**
	 * Returns the whether the logger is currently in an active transaction or not
	 */
	public function isTransaction() -> boolean
	{
		return this->_transaction;
	}

	/**
 	 * Sends/Writes a critical message to the log
 	 */
	public function critical(string! message, array! context = null) -> <AdapterInterface>
	{
		return this->log(Logger::CRITICAL, message, context);
	}

	/**
 	 * Sends/Writes an emergency message to the log
 	 */
	public function emergency(string! message, array! context = null) -> <AdapterInterface>
	{
		return this->log(Logger::EMERGENCY, message, context);
	}

	/**
 	 * Sends/Writes a debug message to the log
 	 */
	public function debug(string! message, array! context = null) -> <AdapterInterface>
	{
		return this->log(Logger::DEBUG, message, context);
	}

	/**
 	 * Sends/Writes an error message to the log
 	 */
	public function error(string! message, array! context = null) -> <AdapterInterface>
	{
		return this->log(Logger::ERROR, message, context);
	}

	/**
 	 * Sends/Writes an info message to the log
 	 */
	public function info(string! message, array! context = null) -> <AdapterInterface>
	{
		return this->log(Logger::INFO, message, context);
	}

	/**
 	 * Sends/Writes a notice message to the log
 	 */
	public function notice(string! message, array! context = null) -> <AdapterInterface>
	{
		return this->log(Logger::NOTICE, message, context);
	}

	/**
 	 * Sends/Writes a warning message to the log
 	 */
	public function warning(string! message, array! context = null) -> <AdapterInterface>
	{
		return this->log(Logger::WARNING, message, context);
	}

	/**
 	 * Sends/Writes an alert message to the log
 	 */
	public function alert(string! message, array! context = null) -> <AdapterInterface>
	{
		return this->log(Logger::ALERT, message, context);
	}

	/**
	 * Logs messages to the internal logger. Appends logs to the logger
	 */
	public function log(var type, var message = null, array! context = null) -> <AdapterInterface>
	{
		var timestamp, toggledMessage, toggledType;

		/**
		 * PSR3 compatibility
		 */
		if typeof type == "string" && typeof message == "integer" {
			let toggledMessage = type, toggledType = message;
		} else {
			if typeof type == "string" && typeof message == "null" {
				let toggledMessage = type, toggledType = message;
			} else {
				let toggledMessage = message, toggledType = type;
			}
		}

		if typeof toggledType == "null" {
			let toggledType = Logger::DEBUG;
		}

		/**
		 * Checks if the log is valid respecting the current log level
		 */
		if this->_logLevel >= toggledType {
			let timestamp = time();
			if this->_transaction {
				let this->_queue[] = new Item(toggledMessage, toggledType, timestamp, context);
			} else {
				this->{"logInternal"}(toggledMessage, toggledType, timestamp, context);
			}
		}

		return this;
	}
}
