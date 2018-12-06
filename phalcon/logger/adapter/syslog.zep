
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Exception;
use Phalcon\Logger\Adapter;
use Phalcon\Logger\FormatterInterface;
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
	 */
	public function __construct(string name, array options = [])
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
	public function getFormatter() -> <FormatterInterface>
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
	public function close() -> bool
	{
		if !this->_opened {
			return true;
		}

		return closelog();
	}

}
