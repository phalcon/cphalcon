
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
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;


/**
 * Class Syslog
 *
 * @property string $defaultFormatter
 * @property int    $facility
 * @property string $name
 * @property bool   $opened
 * @property int    $option
 */
class Syslog extends AbstractAdapter
{
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
     * Syslog constructor.
     *
     * @param string $name
     * @param array  $options
     */
    public function __construct(string! name, array options = [])
    {
        var facility, option;

        if !fetch facility, options["facility"] {
            let facility = LOG_USER;
        }

        if !fetch option, options["option"] {
            let option = LOG_ODELAY;
        }

        let this->name     = name,
            this->option   = option,
            this->facility = facility;

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
     *
     * @param Item $item
     *
     * @throws LogicException
     */
    public function process(<Item> item) -> void
    {
        var level, message, result;

        let message = this->getFormattedItem(item),
            result  = this->openlog(this->name, this->option, this->facility);

        if (!result) {
            throw new LogicException(
                sprintf(
                    "Cannot open syslog for name [%s] and facility [%s]",
                    this->name,
                    (string) this->facility
                )
            );
        }

        let this->opened = true,
            level        = this->logLevelToSyslog(item->getLevel());

        syslog(level, message);
    }

    /**
     * Open connection to system logger
     *
     * @link https://php.net/manual/en/function.openlog.php
     *
     * @param string $ident
     * @param int    $option
     * @param int    $facility
     *
     * @return bool
     */
    protected function openlog(string ident, int option, int facility) -> bool
    {
        return openlog(ident, option, facility);
    }

    /**
     * Translates a Logger level to a Syslog level
     *
     * @param int $level
     *
     * @return int
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
