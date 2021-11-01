
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use DateTimeImmutable;
use DateTimeZone;
use Exception;
use Phalcon\Logger\Adapter\AdapterInterface;
use Phalcon\Logger\Exception as LoggerException;
use Psr\Log\InvalidArgumentException;
use Psr\Log\LoggerInterface;

/**
 * Phalcon Logger.
 *
 * A PSR compatible logger, with various adapters and formatters. A formatter
 * interface is available as well as an adapter one. Adapters can be created
 * easily using the built in AdapterFactory. A LoggerFactory is also available
 * that allows developers to create new instances of the Logger or load them
 * from config files (see Phalcon\Config\Config object).
 *
 * @package Phalcon\Logger
 *
 * @property AdapterInterface[] $adapters
 * @property array              $excluded
 * @property int                $logLevel
 * @property string             $name
 * @property string             $timezone
 */
class Logger implements LoggerInterface
{
    const ALERT     = 2;
    const CRITICAL  = 1;
    const CUSTOM    = 8;
    const DEBUG     = 7;
    const EMERGENCY = 0;
    const ERROR     = 3;
    const INFO      = 6;
    const NOTICE    = 5;
    const WARNING   = 4;

    /**
     * The adapter stack
     *
     * @var AdapterInterface[]
     */
    protected adapters = [] { get };

    /**
     * The excluded adapters for this log process
     *
     * @var array
     */
    protected excluded = [];

    /**
     * Minimum log level for the logger
     *
     * @var int
     */
    protected logLevel = 8 { get };

    /**
     * @var string
     */
    protected name = "" { get };

    /**
     * @var DateTimeZone|null
     */
    protected timezone = null;

    /**
     * Constructor.
     *
     * @param string            $name     The name of the logger
     * @param array             $adapters The collection of adapters to be used
     *                                    for logging (default [])
     * @param DateTimeZone|null $timezone Timezone. If omitted,
     *                                    date_Default_timezone_get() is used
     */
    public function __construct(
        string! name,
        array! adapters = [],
        <DateTimeZone> timezone = null
    ) {
        var localTimeZone;

        let localTimeZone = timezone;

        if empty timezone {
            let localTimeZone = date_default_timezone_get();
            if empty localTimeZone {
                let localTimeZone = "UTC";
            }
        }

        let this->name     = name,
            this->timezone = new DateTimeZone(localTimeZone);

        this->setAdapters(adapters);
    }

    /**
     * Add an adapter to the stack. For processing we use FIFO
     *
     * @param string           $name    The name of the adapter
     * @param AdapterInterface $adapter The adapter to add to the stack
     *
     * @return Logger
     */
    public function addAdapter(string name, <AdapterInterface> adapter) -> <Logger>
    {
        let this->adapters[name] = adapter;

        return this;
    }

    /**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function alert(message, array context = []) -> void
    {
        this->addMessage(self::ALERT, (string) message, context);
    }

    /**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function critical(message, array context = []) -> void
    {
        this->addMessage(self::CRITICAL, (string) message, context);
    }

    /**
     * Detailed debug information.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function debug(var message, array context = []) -> void
    {
        this->addMessage(self::DEBUG, (string) message, context);
    }

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function error(message, array context = []) -> void
    {
        this->addMessage(self::ERROR, (string) message, context);
    }

    /**
     * System is unusable.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function emergency(message, array context = []) -> void
    {
        this->addMessage(self::EMERGENCY, (string) message, context);
    }

    /**
     * Exclude certain adapters.
     *
     * @param array $adapters
     *
     * @return Logger
     */
    public function excludeAdapters(array adapters = []) -> <Logger>
    {
        var adapter, registered;

        /**
         * Loop through what has been passed. Check these names with
         * the registered adapters. If they match, add them to the
         * this->excluded array
         */
        let registered = this->adapters;

        /**
         * Loop through what has been passed. Check these names with
         * the registered adapters. If they match, add them to the
         * this->excluded array
         */
        for adapter in adapters {
            if (isset(registered[adapter])) {
                let this->excluded[adapter] = true;
            }
        }

        return this;
    }

    /**
     * Returns an adapter from the stack
     *
     * @param string $name The name of the adapter
     *
     * @return AdapterInterface
     * @throws LoggerException
     */
    public function getAdapter(string name) -> <AdapterInterface>
    {
        var adapter, adapters;

        let adapters = this->adapters;

        if !fetch adapter, adapters[name] {
            throw new LoggerException("Adapter does not exist for this logger");
        }

        return adapter;
    }

    /**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function info(message, array context = []) -> void
    {
        this->addMessage(self::INFO, (string) message, context);
    }

    /**
     * Logs with an arbitrary level.
     *
     * @param mixed $level
     * @param mixed $message
     * @param array $context
     *
     * @throws LoggerException
     */
    public function log(level, message, array context = []) -> void
    {
        var intLevel;

        let intLevel = this->getLevelNumber(level);

        this->addMessage(intLevel, (string) message, context);
    }

    /**
     * Normal but significant events.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function notice(message, array context = []) -> void
    {
        this->addMessage(self::NOTICE, (string) message, context);
    }

    /**
     * Removes an adapter from the stack
     *
     * @param string $name The name of the adapter
     *
     * @return Logger
     * @throws LoggerException
     */
    public function removeAdapter(string name) -> <Logger>
    {
        var adapters;

        let adapters = this->adapters;

        if true !== isset(adapters[name]) {
            throw new LoggerException("Adapter does not exist for this logger");
        }

        unset adapters[name];

        let this->adapters = adapters;

        return this;
    }

    /**
     * Sets the adapters stack overriding what is already there
     *
     * @param array $adapters An array of adapters
     *
     * @return Logger
     */
    public function setAdapters(array! adapters) -> <Logger>
    {
        let this->adapters = adapters;

        return this;
    }

    /**
     * Sets the adapters stack overriding what is already there
     *
     * @param int $level
     *
     * @return Logger
     */
    public function setLogLevel(int level) -> <Logger>
    {
        var levels;

        let levels = this->getLevels();
        if !isset levels[level] {
            let level = self::CUSTOM;
        }

        let this->logLevel = level;

        return this;
    }

    /**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function warning(message, array context = []) -> void
    {
        this->addMessage(self::WARNING, (string) message, context);
    }

    /**
     * Adds a message to each handler for processing
     *
     * @param int    $level
     * @param string $message
     * @param array  $context
     *
     * @return bool
     * @throws Exception
     * @throws LoggerException
     */
    protected function addMessage(
        int level,
        string message,
        array context = []
    ) -> bool {
        var adapter, adapters, excluded, item, levelName, levels, registered;

        if this->logLevel >= level {
            let registered = this->adapters,
                excluded   = this->excluded,
                levels     = this->getLevels();

            if (true === empty(registered)) {
                throw new LoggerException("No adapters specified");
            }

            if unlikely !fetch levelName, levels[level] {
                let levelName = levels[self::CUSTOM];
            }

            let item = new Item(
                message,
                levelName,
                level,
                new DateTimeImmutable("now", this->timezone),
                context
            );

            /**
             * Log only if the key does not exist in the excluded ones
             */
            let adapters = array_diff_key(registered, excluded);
            for adapter in adapters {
                if (true === adapter->inTransaction()) {
                    adapter->add(item);
                } else {
                    adapter->process(item);
                }
            }

            /**
             * Clear the excluded array since we made the call now
             */
            let this->excluded = [];
        }

        return true;
    }

    /**
     * Returns an array of log levels with integer to string conversion
     *
     * @return string[]
     */
    protected function getLevels() -> array
    {
        return [
            self::ALERT     : "ALERT",
            self::CRITICAL  : "CRITICAL",
            self::DEBUG     : "DEBUG",
            self::EMERGENCY : "EMERGENCY",
            self::ERROR     : "ERROR",
            self::INFO      : "INFO",
            self::NOTICE    : "NOTICE",
            self::WARNING   : "WARNING",
            self::CUSTOM    : "CUSTOM"
        ];
    }

    /**
     * Converts the level from string/word to an integer
     *
     * @param mixed $level
     *
     * @return int
     * @throws InvalidArgumentException
     */
    private function getLevelNumber(var level) -> int
    {
        var levelName, levels;

        /**
         * If someone uses "critical" as the level (string)
         */
        if typeof level === "string" {
            let levelName = strtoupper(level),
                levels    = array_flip(this->getLevels());

            if isset levels[levelName] {
                return levels[levelName];
            }
        /**
         * If someone uses 1 as the level ("critical")
         */
        } elseif is_numeric(level) {
            let levels = this->getLevels();

            if isset levels[level] {
                return (int) level;
            }
        }

        return self::CUSTOM;
    }
}
