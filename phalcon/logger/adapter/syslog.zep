
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

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Exception;
use Phalcon\Logger\Adapter;
use Phalcon\Logger\Formatter\Syslog as SyslogFormatter;

/**
 * Phalcon\Logger\Adapter\Syslog
 *
 * Sends logs to the system logger
 *
 * <code>
 * use Phalcon\Logger;
 * use Phalcon\Logger\Adapter\Syslog;
 *
 * // LOG_USER is the only valid log type under Windows operating systems
 * $logger = new Syslog(
 *     "ident",
 *     [
 *         "option"   => LOG_CONS | LOG_NDELAY | LOG_PID,
 *         "facility" => LOG_USER,
 *     ]
 * );
 *
 * $logger->log("This is a message");
 * $logger->log(Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *</code>
 */
class Syslog extends Adapter
{

	protected _opened = false;

	/**
	 * Phalcon\Logger\Adapter\Syslog constructor
	 *
	 * @param string name
	 * @param array options
	 */
	public function __construct(name, options = null)
	{
		var option, facility;

		if name {

			if !fetch option, options["option"] {
				let option = LOG_ODELAY;
			}

			if !fetch facility, options["facility"] {
				let facility = LOG_USER;
			}

			openlog(name, option, facility);
			let this->_opened = true;
		}

	}

	/**
	 * Returns the internal formatter
	 */
	public function getFormatter() -> <\Phalcon\Logger\FormatterInterface>
	{
		if typeof this->_formatter !== "object" {
			let this->_formatter = new SyslogFormatter();
		}

		return this->_formatter;
	}

	/**
	 * Writes the log to the stream itself
	 */
	public function logInternal(string message, int type, int time, array context)
	{
		var appliedFormat;

		let appliedFormat = this->getFormatter()->format(message, type, time, context);
		if typeof appliedFormat !== "array" {
			throw new Exception("The formatted message is not valid");
		}

		syslog(appliedFormat[0], appliedFormat[1]);
	}

	/**
 	 * Closes the logger
 	 */
	public function close() -> boolean
	{
		if !this->_opened {
			return true;
		}

		return closelog();
	}

}
