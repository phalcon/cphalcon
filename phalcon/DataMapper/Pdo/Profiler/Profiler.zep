
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */

namespace Phalcon\DataMapper\Pdo\Profiler;

use Phalcon\DataMapper\Pdo\Exception\Exception;
use Phalcon\Helper\Json;
use Psr\Log\LoggerInterface;
use Psr\Log\LogLevel;

/**
 * Sends query profiles to a logger.
 *
 * @property bool            $active
 * @property array           $context
 * @property string          $logFormat
 * @property string          $logLevel
 * @property LoggerInterface $logger
 */
class Profiler implements ProfilerInterface
{
    /**
     * @var bool
     */
    protected active = false;

    /**
     * @var array
     */
    protected context = [];

    /**
     * @var string
     */
    protected logFormat = "";

    /**
     * @var string
     */
    protected logLevel = 0;

    /**
     * @var LoggerInterface
     */
    protected logger;

    /**
     * Constructor.
     *
     * @param LoggerInterface $logger
     */
    public function __construct(<LoggerInterface> logger = null)
    {
        if logger === null {
            let logger = new MemoryLogger();
        }

        let this->logFormat = "{method} ({duration} seconds) -> {statement} {backtrace}",
            this->logLevel  = LogLevel::DEBUG,
            this->logger    = logger;
    }

    /**
     * Finishes and logs a profile entry.
     *
     * @param string $statement
     * @param array  $values
     */
    public function finish(string statement = null, array values = []) -> void
    {
        var ex, finish, version;

        if unlikely this->active {
            let version = phpversion(),
                ex      = new Exception();

            /**
             * @todo Remove this check when we target min PHP 7.3
             */
            if starts_with(version, "7.2") {
                let finish = microtime(true);
            } else {
                let finish = hrtime(true);
            }


            let this->context["backtrace"] = ex->getTraceAsString(),
                this->context["duration"]  = finish - this->context["start"],
                this->context["finish"]    = finish,
                this->context["statement"] = statement,
                this->context["values"]    = empty(values) ? "" : Json::encode(values);

            this->logger->log(this->logLevel, this->logFormat, this->context);

            let this->context = [];
        }
    }

    /**
     * Returns the log message format string, with placeholders.
     *
     * @return string
     */
    public function getLogFormat() -> string
    {
        return this->logFormat;
    }

    /**
     * Returns the underlying logger instance.
     *
     * @return LoggerInterface
     */
    public function getLogger() -> <LoggerInterface>
    {
        return this->logger;
    }

    /**
     * Returns the level at which to log profile messages.
     *
     * @return string
     */
    public function getLogLevel() -> string
    {
        return this->logLevel;
    }

    /**
     * Returns true if logging is active.
     *
     * @return bool
     */
    public function isActive() -> bool
    {
        return this->active;
    }

    /**
     * Enable or disable profiler logging.
     *
     * @param bool $active
     *
     * @return ProfilerInterface
     */
    public function setActive(bool active) -> <ProfilerInterface>
    {
        let this->active = (bool) active;

        return this;
    }

    /**
     * Sets the log message format string, with placeholders.
     *
     * @param string $logFormat
     *
     * @return ProfilerInterface
     */
    public function setLogFormat(string logFormat) -> <ProfilerInterface>
    {
        let this->logFormat = logFormat;

        return this;
    }

    /**
     * Level at which to log profile messages.
     *
     * @param string $logLevel
     *
     * @return ProfilerInterface
     */
    public function setLogLevel(string logLevel) -> <ProfilerInterface>
    {
        let this->logLevel = logLevel;

        return this;
    }

    /**
     * Starts a profile entry.
     *
     * @param string $method
     */
    public function start(string method) -> void
    {
        var start, version;

        if unlikely this->active {
            let version = phpversion();

            /**
             * @todo Remove this check when we target min PHP 7.3
             */
            if starts_with(version, "7.2") {
                let start = microtime(true);
            } else {
                let start = hrtime(true);
            }

            let this->context = [
                "method" : method,
                "start"  : start
            ];
        }
    }
}
