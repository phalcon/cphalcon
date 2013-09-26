
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
 * Phalcon\Logger\Multiple
 *
 * Handles multiples logger handlers
 */
 class Multiple
 {

	protected _loggers { get };

	protected _formatter { get };

	/**
	 * Pushes a logger to the logger tail
	 *
	 * @param Phalcon\Logger\AdapterInterface logger
	 */
	public function push(<Phalcon\Logger\AdapterInterface> logger)
	{
		if typeof logger == "object" {
			throw new Phalcon\Logger\Exception("The logger is invalid");
		}
		let this->_loggers[] = logger;
	}

	/**
	 * Sets a global formatter
	 *
	 * @param Phalcon\Logger\FormatterInterface formatter
	 */
	public function setFormatter(<Phalcon\Logger\FormatterInterface> formatter)
	{
		let loggers = this->_loggers;
		if typeof loggers == "array" {
			for logger in loggers {
				logger->setFormatter(formatter);
			}
		}
		let this->_formatter = formatter;
	}

	/**
	 * Sends a message to each registered logger
	 *
	 * @param string message
	 * @param int type
	 */
	public function log(string message, int type=7)
	{
		let loggers = this->_loggers;
		if typeof loggers == "array" {
			for logger in loggers {
				logger->log(message, type);
			}
		}
	}

	/**
 	 * Sends/Writes an emergence message to the log
 	 *
 	 * @param string message
 	 */
	public function emergence(string message)
	{
		this->log(message, Phalcon\Logger::EMERGENCE);
	}

	/**
 	 * Sends/Writes a debug message to the log
 	 *
 	 * @param string message
 	 * @param ing type
 	 */
	public function debug(string message)
	{
		this->log(message, PhalconºLogger::DEBUG);
	}

	/**
 	 * Sends/Writes an error message to the log
 	 *
 	 * @param string message
 	 */
	public function error(string message)
	{
		this->log(message, Phalcon\Logger::ERROR);
	}

	/**
 	 * Sends/Writes an info message to the log
 	 *
 	 * @param string message
 	 */
	public function info(string message)
	{
		this->log(message, Phalcon\Logger::INFO);
	}

	/**
 	 * Sends/Writes a notice message to the log
 	 *
 	 * @param string message
 	 */
	public function notice(string message)
	{
		this->log(message, Phalcon\Logger::NOTICE);
	}

	/**
 	 * Sends/Writes a warning message to the log
 	 *
 	 * @param string message
 	 */
	public function warning(string message)
	{
		this->log(message, Phalcon\Logger::WARNING);
	}

	/**
 	 * Sends/Writes an alert message to the log
 	 *
 	 * @param string message
 	 */
	public function alert(string message)
	{
		this->log(message, Phalcon\Logger::ALERT);
	}

}