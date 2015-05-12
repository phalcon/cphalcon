
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
	 */
	public function push(<AdapterInterface> logger)
	{
		let this->_loggers[] = logger;
	}

	/**
	 * Sets a global formatter
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
	 */
	public function log(var type, var message = null, array! context = null)
	{
		var loggers, logger;

		let loggers = this->_loggers;
		if typeof loggers == "array" {
			for logger in loggers {
				logger->log(type, message, context);
			}
		}
	}

	/**
 	 * Sends/Writes an critical message to the log
 	 */
	public function critical(string! message, array! context = null)
	{
		this->log(Logger::CRITICAL, message, context);
	}

	/**
 	 * Sends/Writes an emergency message to the log
 	 */
	public function emergency(string! message, array! context = null)
	{
		this->log(Logger::EMERGENCY, message, context);
	}

	/**
 	 * Sends/Writes a debug message to the log
 	 */
	public function debug(string! message, array! context = null)
	{
		this->log(Logger::DEBUG, message, context);
	}

	/**
 	 * Sends/Writes an error message to the log
 	 */
	public function error(string! message, array! context = null)
	{
		this->log(Logger::ERROR, message, context);
	}

	/**
 	 * Sends/Writes an info message to the log
 	 */
	public function info(string! message, array! context = null)
	{
		this->log(Logger::INFO, message, context);
	}

	/**
 	 * Sends/Writes a notice message to the log
 	 */
	public function notice(string! message, array! context = null)
	{
		this->log(Logger::NOTICE, message, context);
	}

	/**
 	 * Sends/Writes a warning message to the log
 	 */
	public function warning(string! message, array! context = null)
	{
		this->log(Logger::WARNING, message, context);
	}

	/**
 	 * Sends/Writes an alert message to the log
 	 */
	public function alert(string! message, array! context = null)
	{
		this->log(Logger::ALERT, message, context);
	}
}
