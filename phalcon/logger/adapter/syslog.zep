
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
use Phalcon\Logger\Formatter\FormatterInterface;

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
     * @var bool
     */
	protected opened = false;

	/**
	 * Phalcon\Logger\Adapter\Syslog constructor
	 */
	public function __construct(string! name, array options = [])
	{
		var adapter, option, facility;

        if !fetch option, options["option"] {
            let option = LOG_ODELAY;
        }

        if !fetch facility, options["facility"] {
            let facility = LOG_USER;
        }

        let adapter = name;

        openlog(adapter, option, facility);
        let this->opened = true;
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
	public function process(<Item> item)
	{
		var formatter, formattedMessage;

		let formatter        = this->getFormatter();
		let formattedMessage = formatter->format(item);

		if typeof formattedMessage !== "array" {
			throw new Exception("The formatted message is not valid");
		}

		syslog(formattedMessage[0], formattedMessage[1]);
	}
}
