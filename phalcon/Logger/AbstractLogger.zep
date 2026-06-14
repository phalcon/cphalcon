
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
use Phalcon\Logger\Exceptions\AdapterNotFound;
use Phalcon\Logger\Exceptions\NoAdaptersConfigured;
use Phalcon\Time\Clock\ClockInterface;
use Phalcon\Time\Clock\SystemClock;

/**
 * Abstract Logger Class
 *
 * Abstract logger class, providing common functionality. A formatter interface
 * is available as well as an adapter one. Adapters can be created easily using
 * the built in AdapterFactory. A LoggerFactory is also available that allows
 * developers to create new instances of the Logger or load them from config
 * files (see Phalcon\Config\Config object).
 *
 * @property AdapterInterface[] $adapters
 * @property array              $excluded
 * @property int                $logLevel
 * @property string             $name
 * @property string             $timezone
 */
abstract class AbstractLogger
{
    /**
     * @var int
     */
    const ALERT     = 2;
    /**
     * @var int
     */
    const CRITICAL  = 1;
    /**
     * @var int
     */
    const CUSTOM    = 8;
    /**
     * @var int
     */
    const DEBUG     = 7;
    /**
     * @var int
     */
    const EMERGENCY = 0;
    /**
     * @var int
     */
    const ERROR     = 3;
    /**
     * @var int
     */
    const INFO      = 6;
    /**
     * @var int
     */
    const NOTICE    = 5;
    /**
     * @var int
     */
    const TRACE     = 9;
    /**
     * @var int
     */
    const WARNING   = 4;

    /**
     * The adapter stack
     *
     * @var AdapterInterface[]
     */
    protected adapters = [];

    /**
     * Clock used to timestamp log items
     *
     * @var ClockInterface
     */
    protected clock;

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
    protected logLevel = 8;

    /**
     * @var string
     */
    protected name = "";

    /**
     * @var DateTimeZone
     */
    protected timezone;

    /**
     * Constructor.
     *
     * @param string            $name     The name of the logger
     * @param array             $adapters The collection of adapters to be used
     *                                    for logging (default [])
     * @param DateTimeZone|null   $timezone Timezone. If omitted,
     *                                      date_Default_timezone_get() is used
     * @param ClockInterface|null $clock    Clock used to timestamp log items.
     *                                      Defaults to a SystemClock on the
     *                                      resolved timezone.
     */
    public function __construct(
        string name,
        array adapters = [],
        <DateTimeZone> timezone = null,
        <ClockInterface> clock = null
    ) {
        var defaultTimezone;

        if (null == timezone) {
            let defaultTimezone = date_default_timezone_get();

            if unlikely true === empty(defaultTimezone) {
                let defaultTimezone = "UTC";
            }

            let timezone = new DateTimeZone(defaultTimezone);
        }

        let this->name     = name,
            this->timezone = timezone;

        if (null === clock) {
            let clock = new SystemClock(timezone);
        }

        let this->clock = clock;

        this->setAdapters(adapters);
    }

    /**
     * Add an adapter to the stack. For processing we use FIFO
     *
     * @param string           $name    The name of the adapter
     * @param AdapterInterface $adapter The adapter to add to the stack
     *
     * @return static
     */
    public function addAdapter(string name, <AdapterInterface> adapter) -> <static>
    {
        let this->adapters[name] = adapter;

        return this;
    }

    /**
     * Exclude certain adapters.
     *
     * @param array $adapters
     *
     * @return static
     */
    public function excludeAdapters(array adapters = []) -> <static>
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
            if (true === isset(registered[adapter])) {
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
     * @throws AdapterNotFound
     */
    public function getAdapter(string name) -> <AdapterInterface>
    {
        if (true !== isset(this->adapters[name])) {
            throw new AdapterNotFound(name);
        }

        return this->adapters[name];
    }

    /**
     * Returns the adapter stack array
     *
     * @return AdapterInterface[]
     */
    public function getAdapters() -> array
    {
        return this->adapters;
    }

    /**
     * Returns the log level
     */
    public function getLogLevel() -> int
    {
        return this->logLevel;
    }

    /**
     * Returns the name of the logger
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Removes an adapter from the stack
     *
     * @param string $name The name of the adapter
     *
     * @return static
     * @throws AdapterNotFound
     */
    public function removeAdapter(string name) -> <static>
    {
        if (true !== isset(this->adapters[name])) {
            throw new AdapterNotFound(name);
        }

        unset(this->adapters[name]);

        return this;
    }

    /**
     * Sets the adapters stack overriding what is already there
     *
     * @param array $adapters An array of adapters
     *
     * @return static
     */
    public function setAdapters(array adapters) -> <static>
    {
        let this->adapters = adapters;

        return this;
    }

    /**
     * Sets the adapters stack overriding what is already there
     *
     * @param int $level
     *
     * @return static
     */
    public function setLogLevel(int level) -> <static>
    {
        var levels;

        let levels         = this->getLevels(),
            this->logLevel = true === isset(levels[level]) ? level : self::CUSTOM;

        return this;
    }


    /**
     * Adds a message to each handler for processing
     *
     * @param int    level
     * @param string $message
     * @param array  $context
     *
     * @return bool
     * @throws Exception
     * @throws NoAdaptersConfigured
     */
    protected function addMessage(
        int level,
        string message,
        array context = []
    ) -> bool {
        var adapter, collection, item, levelName, levels, method;
        if (this->logLevel >= level) {
            if (count(this->adapters) === 0) {
                throw new NoAdaptersConfigured();
            }

            let levels    = this->getLevels(),
                levelName = true === isset(levels[level]) ? levels[level] : levels[self::CUSTOM];

            let item = new Item(
                message,
                levelName,
                level,
                this->clock->now(),
                context
            );

            /**
             * Log only if the key does not exist in the excluded ones
             */
            let collection = array_diff_key(this->adapters, this->excluded);
            for adapter in collection {
                let method = "process";
                if (true === adapter->inTransaction()) {
                    let method = "add";
                }

                adapter->{method}(item);
            }

            /**
             * Clear the excluded array since we made the call now
             */
            let this->excluded = [];
        }

        return true;
    }

    /**
     * Converts the level from string/word to an integer
     *
     * @param mixed $level
     *
     * @return int
     */
    protected function getLevelNumber(var level) -> int
    {
        var levelName, levels;

        /**
         * If someone uses "critical" as the level (string)
         */
        if (typeof level === "string") {
            let levelName = strtolower(level),
                levels    = array_flip(this->getLevels());

            if (isset(levels[levelName])) {
                return levels[levelName];
            }
        } elseif (true === is_numeric(level)) {
            let levels = this->getLevels();

            if (isset(levels[level])) {
                return (int) level;
            }
        }

        return self::CUSTOM;
    }

    /**
     * Returns an array of log levels with integer to string conversion
     *
     * @return string[]
     */
    protected function getLevels() -> array
    {
        return [
            self::ALERT     : "alert",
            self::CRITICAL  : "critical",
            self::DEBUG     : "debug",
            self::EMERGENCY : "emergency",
            self::ERROR     : "error",
            self::INFO      : "info",
            self::NOTICE    : "notice",
            self::WARNING   : "warning",
            self::CUSTOM    : "custom",
            self::TRACE     : "trace"
        ];
    }
}
