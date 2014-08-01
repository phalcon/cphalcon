
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

namespace Phalcon\Logger;

/**
 * Phalcon\Logger\Adapter
 *
 * Base class for Phalcon\Logger adapters
 */
abstract class Adapter
{

	/**
	 * Tells if there is an active transaction or not
	 *
	 * @var boolean
	 */
	protected _transaction = false;

	/**
	 * Array with messages queued in the transacction
	 *
	 * @var array
	 */
	protected _queue;

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
	 *
	 * @param int level
	 * @return Phalcon\Logger\AdapterInterface
	 */
	public function setLogLevel(int level) -> <\Phalcon\Logger\AdapterInterface>
	{
		let this->_logLevel = level;
		return this;
	}

	/**
	 * Returns the current log level
	 *
	 * @return int
	 */
	public function getLogLevel() -> int
	{
		return this->_logLevel;
	}

	/**
	 * Sets the message formatter
	 *
	 * @param Phalcon\Logger\FormatterInterface formatter
	 * @return Phalcon\Logger\AdapterInterface
	 */
	public function setFormatter(<\Phalcon\Logger\FormatterInterface> formatter) -> <\Phalcon\Logger\AdapterInterface>
	{
		let this->_formatter = formatter;
		return this;
	}

	/**
 	 * Starts a transaction
 	 *
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function begin() -> <\Phalcon\Logger\AdapterInterface>
	{
		let this->_transaction = true;
		return this;
	}

	/**
 	 * Commits the internal transaction
 	 *
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function commit() -> <\Phalcon\Logger\AdapterInterface>
	{
		var queue, message;

		if !this->_transaction {
			throw new \Phalcon\Logger\Exception("There is no active transaction");
		}

		let this->_transaction = false;

		/**
		 * Check if the queue has something to log
		 */
		let queue = this->_queue;
		if typeof queue == "array" {
			for message in queue {
				this->{"logInternal"}(message->getMessage(), message->getType(), message->getTime(), message->getContext());
			}
		}

		return this;
	}

	/**
 	 * Rollbacks the internal transaction
 	 *
 	 * @return Phalcon\Logger\Adapter
 	 */
	public function rollback() -> <\Phalcon\Logger\Adapter>
	{
		var transaction;

		let transaction = this->_transaction;
		if !transaction {
			throw new \Phalcon\Logger\Exception("There is no active transaction");
		}

		let this->_transaction = false,
			this->_queue = [];

		return this;
	}

	/**
 	 * Sends/Writes an emergency message to the log
 	 *
 	 * @param string message
 	 * @param array $context
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function emergency(string! message, array context=null) -> <\Phalcon\Logger\AdapterInterface>
	{
		this->log(\Phalcon\Logger::EMERGENCY, message, context);
		return this;
	}

	/**
 	 * Sends/Writes a debug message to the log
 	 *
 	 * @param string message
 	 * @param array $context
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function debug(string! message, array context=null) -> <\Phalcon\Logger\AdapterInterface>
	{
		this->log(\Phalcon\Logger::DEBUG, message, context);
		return this;
	}

	/**
 	 * Sends/Writes an error message to the log
 	 *
 	 * @param string message
 	 * @param array $context
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function error(string! message, array context=null) -> <\Phalcon\Logger\AdapterInterface>
	{
		this->log(\Phalcon\Logger::ERROR, message, context);
		return this;
	}

	/**
 	 * Sends/Writes an info message to the log
 	 *
 	 * @param string message
 	 * @param array $context
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function info(string! message, array context=null) -> <\Phalcon\Logger\AdapterInterface>
	{
		this->log(\Phalcon\Logger::INFO, message, context);
		return this;
	}

	/**
 	 * Sends/Writes a notice message to the log
 	 *
 	 * @param string message
 	 * @param array $context
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function notice(string! message, array context=null) -> <\Phalcon\Logger\AdapterInterface>
	{
		this->log(\Phalcon\Logger::NOTICE, message, context);
		return this;
	}

	/**
 	 * Sends/Writes a warning message to the log
 	 *
 	 * @param string message
 	 * @param array $context
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function warning(string! message, array context=null) -> <\Phalcon\Logger\AdapterInterface>
	{
		this->log(\Phalcon\Logger::WARNING, message, context);
		return this;
	}

	/**
 	 * Sends/Writes an alert message to the log
 	 *
 	 * @param string message
 	 * @param array $context
 	 * @return Phalcon\Logger\AdapterInterface
 	 */
	public function alert(string! message, array context = null) -> <\Phalcon\Logger\AdapterInterface>
	{
		this->log(\Phalcon\Logger::ALERT, message, context);
		return this;
	}

	/**
	 * Logs messages to the internal loggger. Appends logs to the
	 *
	 * @param mixed type
	 * @param string message
	 * @param array $context
	 * @return Phalcon\Logger\AdapterInterface
	 */
	public function log(type, string message = null, array context = null) -> <\Phalcon\Logger\AdapterInterface>
	{
		var timestamp, transaction, tmp;

		/*
		 * Backwards compatibility.
		 *
		 * PSR-3 says:
		 *
		 * public function log($level, $message, array $context = array());
		 *
		 * Our old definition:
		 *
		 * public function log($message, $level = null)
		 *
		 * Now we want to implement PSR-3
		 * Thus:
		 *   - when $message === null, $level is $message and $level is DEBUG
		 *   - when typeof($message) == 'int' && typeof($level) == 'string', then
		 *     $message is $level and $level is $message.
		 */

		if message === null {
			let message = type,
				type = \Phalcon\Logger::DEBUG;
		} else {
			if typeof message == "int" && typeof type == "string" {
				let tmp = message,
					message = type,
					type = (int) tmp;
			}
		}

		/**
		 * Checks if the log is valid respecting the current log level
		 */
		if this->_logLevel >= type {
			let timestamp = time();

			let transaction = this->_transaction;
			if transaction {
				let this->_queue[] = new \Phalcon\Logger\Item(message, type, timestamp, context);
			} else {
				this->{"logInternal"}(message, type, timestamp, context);
			}
		}

		return this;
	}

}
