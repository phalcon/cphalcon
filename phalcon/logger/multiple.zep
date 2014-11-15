
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

use Phalcon\Logger;
use Phalcon\Logger\AdapterInterface;
use Phalcon\Logger\FormatterInterface;
use Phalcon\Logger\Exception;

/**
 * Phalcon\Logger\Multiple
 *
 * Handles multiples logger handlers
 */
class Multiple
{

	protected _loggers { get };

	protected _formatter { get };

	/**
	 * Pushes a logger to the logger tail
	 *
	 * @param Phalcon\Logger\AdapterInterface logger
	 */
	public function push(<AdapterInterface> logger)
	{
		let this->_loggers[] = logger;
	}

	/**
	 * Sets a global formatter
	 *
	 * @param Phalcon\Logger\FormatterInterface formatter
	 */
	public function setFormatter(<FormatterInterface> formatter)
	{
		var loggers, logger;

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
	public function log(string message, int type = 7)
	{
		var loggers, logger;

		let loggers = this->_loggers;
		if typeof loggers == "array" {
			for logger in loggers {
				logger->log(type, message);
			}
		}
	}

	/**
 	 * Sends/Writes an emergency message to the log
 	 *
 	 * @param string message
 	 */
	public function emergency(string message)
	{
		this->log(message, Logger::EMERGENCY);
	}

	/**
 	 * Sends/Writes a debug message to the log
 	 *
 	 * @param string message
 	 * @param ing type
 	 */
	public function debug(string message)
	{
		this->log(message, Logger::DEBUG);
	}

	/**
 	 * Sends/Writes an error message to the log
 	 *
 	 * @param string message
 	 */
	public function error(string message)
	{
		this->log(message, Logger::ERROR);
	}

	/**
 	 * Sends/Writes an info message to the log
 	 *
 	 * @param string message
 	 */
	public function info(string message)
	{
		this->log(message, Logger::INFO);
	}

	/**
 	 * Sends/Writes a notice message to the log
 	 *
 	 * @param string message
 	 */
	public function notice(string message)
	{
		this->log(message, Logger::NOTICE);
	}

	/**
 	 * Sends/Writes a warning message to the log
 	 *
 	 * @param string message
 	 */
	public function warning(string message)
	{
		this->log(message, Logger::WARNING);
	}

	/**
 	 * Sends/Writes an alert message to the log
 	 *
 	 * @param string message
 	 */
	public function alert(string message)
	{
		this->log(message, Logger::ALERT);
	}
}
