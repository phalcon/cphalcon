
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger;
use Phalcon\Logger\Adapter;
use Phalcon\Logger\Exception;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Item;

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
class Syslog extends AbstractAdapter
{
	/**
	 * Name of the default formatter class
	 *
	 * @var string
	 */
	protected defaultFormatter = "Syslog";

	/**
	 * @var int
	 */
	protected facility = 0;

	/**
	 * @var string
	 */
	protected name = "";

	/**
	 * @var bool
	 */
	protected opened = false;

	/**
	 * @var int
	 */
	protected option = 0;

	/**
	 * Phalcon\Logger\Adapter\Syslog constructor
	 */
	public function __construct(string! name, array options = [])
	{
		var option, facility;

		if fetch option, options["option"] {
			let option = LOG_ODELAY;
		}

		if !fetch facility, options["facility"] {
			let facility = LOG_USER;
		}

		let this->name     = name,
			this->facility = facility,
			this->option   = option;
	}

	/**
 	 * Closes the logger
 	 */
	public function close() -> bool
	{
		if !this->opened {
			return true;
		}

		return closelog();
	}

	/**
	 * Processes the message i.e. writes it to the syslog
	 */
	public function process(<Item> item) -> void
	{
		var name, facility, formatter, level, message, opened, option, result;

		let formatter = this->getFormatter(),
			message   = formatter->format(item);

		if typeof message !== "array" {
			throw new Exception("The formatted message is not valid");
		}

		let name     = this->name,
			facility = this->facility,
			option   = this->option;

		let result = openlog(name, option, facility);

		if (!result) {
			throw new \LogicException(
				sprintf(
					"Cannot open syslog for name [%s] and facility [%s]",
					name,
					facility
				)
			);
		}

		let opened 		 = true,
			this->opened = opened,
			level 		 = this->logLevelToSyslog(message[1]);

		syslog(level, message[1]);
	}

	/**
	 * Translates a Logger level to a Syslog level
	 */
	private function logLevelToSyslog(string level) -> int
	{
		var levels, result;

		let levels = [
			Logger::ALERT     : LOG_ALERT,
			Logger::CRITICAL  : LOG_CRIT,
			Logger::CUSTOM    : LOG_ERR,
			Logger::DEBUG     : LOG_DEBUG,
			Logger::EMERGENCY : LOG_EMERG,
			Logger::ERROR     : LOG_ERR,
			Logger::INFO      : LOG_INFO,
			Logger::NOTICE    : LOG_NOTICE,
			Logger::WARNING   : LOG_WARNING
		];

		if !fetch result, levels[level] {
			let result = LOG_ERR;
		}

		return result;
	}
}
