
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

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Exception;
use Phalcon\Logger\Adapter;
use Phalcon\Logger\AdapterInterface;
use Phalcon\Logger\Formatter\Syslog as SyslogFormatter;

/**
 * Phalcon\Logger\Adapter\Syslog
 *
 * Sends logs to the system logger
 *
 *<code>
 *	$logger = new \Phalcon\Logger\Adapter\Syslog("ident", array(
 *		'option' => LOG_NDELAY,
 *		'facility' => LOG_MAIL
 *	));
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", \Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *</code>
 */
class Syslog extends Adapter implements AdapterInterface
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
	public function getFormatter() -> <SyslogFormatter>
	{
		if typeof this->_formatter !== "object" {
			let this->_formatter = new SyslogFormatter();
		}

		return this->_formatter;
	}

	/**
	 * Writes the log to the stream itself
	 *
	 * @param string message
	 * @param int type
	 * @param int time
	 * @param array $context
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
 	 *
 	 * @return boolean
 	 */
	public function close()
	{
		if this->_opened {
			closelog();
		}
	}

}
