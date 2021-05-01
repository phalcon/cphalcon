
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use LogicException;
use Phalcon\Helper\Arr;
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
 * ```php
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
 *```
 */
class Syslog extends AbstractAdapter
{
    /**
     * Name of the default formatter class
     *
     * @var string
     */
    protected defaultFormatter = "Line";

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
     * @param array options = [
     *     'option' => null,
     *     'facility' => null
     * ]
     */
    public function __construct(string! name, array options = [])
    {
        let this->name     = name,
            this->facility = Arr::get(options, "facility", LOG_USER),
            this->option   = Arr::get(options, "option", LOG_ODELAY);
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
        var name, facility, level, message, option, result;

        let message   = this->getFormattedItem(item),
            name      = this->name,
            facility  = this->facility,
            option    = this->option;

        let result = openlog(name, option, facility);

        if (!result) {
            throw new LogicException(
                sprintf(
                    "Cannot open syslog for name [%s] and facility [%s]",
                    name,
                    facility
                )
            );
        }

        let this->opened = true,
            level        = this->logLevelToSyslog(item->getLevel());

        syslog(level, message);
    }

    /**
     * Translates a Logger level to a Syslog level
     */
    private function logLevelToSyslog(int level) -> int
    {
        var result;
        array levels;

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
