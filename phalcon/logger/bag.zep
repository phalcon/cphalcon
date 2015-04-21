
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

use Phalcon\Logger\Adapter;
use Phalcon\Logger\AdapterInterface;
use Phalcon\Logger\Formatter;
use Phalcon\Logger\FormatterInterface;
use Phalcon\Logger\Exception;

/**
 * Phalcon\Logger\Bag
 *
 * Handles bag logger handlers
 */
class Bag extends Adapter
{
	protected _default = null;

	protected _loggers { get };

	/**
	 * Phalcon\Logger\Bag constructor
	 *
	 * @param array $logger
	 */
	public function __construct(array loggers = null)
	{
		var name, logger;

		if typeof loggers == "array" {
			for name, logger in loggers {
				if empty name || is_numeric(name) || !is_string(name) {
					throw new Exception("Invalid logger bag name");
				}

				if typeof logger == "object" && logger instanceof Adapter {
					this->push(name, logger);
				} elseif typeof logger == "array" && isset(logger["adapter"]) && isset(logger["name"]) {
					var adapterClass, options, instance, formatter;

					if class_exists(logger["adapter"]) {
						let adapterClass = logger["adapter"];
					} else {
						let adapterClass = "\\Phalcon\\Logger\\Adapter\\" . logger["adapter"];
					}

					if isset(logger["options"]) {
						let options = $logger["options"];
					} else {
						let options = null;
					}

					let instance = new {adapterClass}(logger["name"], options);

					if isset(logger["formatter"]) {

						if is_callable(logger["formatter"]) {
							let formatter = call_user_func(logger["formatter"]);
						} else {
							let formatter = logger["formatter"];
						}

						if typeof formatter == "object" && formatter instanceof Formatter {
							instance->setFormatter(formatter);
						}
					}

					if isset(logger["level"]) && is_numeric(logger["level"]) {
						instance->setLogLevel(logger["level"]);
					}
					this->push(name, instance);

				} else {
					throw new Exception("Invalid logger bag object");
				}
			}
		}
	}

	/**
	 * Pushes a logger
	 *
	 * @param name
	 * @param logger
	 */
	public function push(string! name, logger)
	{
		if empty name || is_numeric(name) || !is_string(name) {
			throw new Exception("Invalid logger bag name");
		}

		if is_callable(logger) {
			let logger = call_user_func(logger);
		}

		if typeof logger != "object" || !(logger instanceof Adapter) {
			throw new Exception("Invalid logger object");
		}

		let this->_loggers[name] = logger;

		if empty(this->_default) {
			let this->_default = name;
		}
	}

	/**
	 * Filters the logs sent to the handlers that are less or equal than a specific level
	 *
	 * @param int level
	 * @return Phalcon\Logger\AdapterInterface
	 */
	public function setLogLevel(int level)
	{
		return this->_getDefault()->setLogLevel(level);
	}

	/**
	 * Returns the current log level
	 *
	 * @return int
	 */
	public function getLogLevel()
	{
		return this->_getDefault()->getLogLevel();
	}

	/**
	 * Sets the message formatter
	 *
	 * @param Phalcon\Logger\FormatterInterface formatter
	 * @return Phalcon\Logger\AdapterInterface
	 */
	public function setFormatter(<FormatterInterface> formatter)
	{
		return this->_getDefault()->setFormatter(formatter);
	}

	/**
	 * Returns the internal formatter
	 *
	 * @return Phalcon\Logger\FormatterInterface
	 */
	public function getFormatter()
	{
		return this->_getDefault()->getFormatter();
	}

	/**
	 * Starts a transaction
	 *
	 * @return Phalcon\Logger\Adapter
	 */
	public function begin()
	{
		return this->_getDefault()->begin();
	}

	/**
	 * Commits the internal transaction
	 *
	 * @return Phalcon\Logger\Adapter
	 */
	public function commit()
	{
		return this->_getDefault()->commit();
	}

	/**
	 * Rollbacks the internal transaction
	 *
	 * @return Phalcon\Logger\Adapter
	 */
	public function rollback()
	{
		return this->_getDefault()->rollback();
	}

	/**
	 * Closes the logger
	 *
	 * @return boolean
	 */
	public function close()
	{
		return this->_getDefault()->rollback();
	}

	/**
	 * Writes the log to the file itself
	 *
	 * @param string message
	 * @param int type
	 * @param int time
	 * @param array $context
	 */
	public function logInternal(string message, int type, int time, array context)
	{
		return this->_getDefault()->log(type, message, context);
	}

	/**
	 * Set default logger
	 *
	 * @return Phalcon\Logger\Bag
	 */
	public function setDefault(string! name) -> <Bag>
	{
		if !isset(this->_loggers[name]) {
			throw new Exception("Undefined logger object: " . name);
		}
		let this->_default = name;
		return this;
	}

	/**
	 * Check whether the logger by a name
	 */
	public function has(string! name) -> boolean
	{
		return isset this->_loggers[name];
	}

	/**
	 * Get default logger
	 *
	 * @return Phalcon\Logger\AdapterInterface
	 */
	protected function _getDefault()
	{
		if empty(this->_default) || !isset(this->_loggers[this->_default]) {
			throw new Exception("Undefined logger object");
		}
		return this->_loggers[this->_default];
	}

	/**
	 * Get logger
	 *
	 * @return Phalcon\Logger\AdapterInterface
	 */
	public function __get(name)
	{
		if isset(this->_loggers[name]) {
			return this->_loggers[name];
		}
		return this->_getDefault();
	}
}
