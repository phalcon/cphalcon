
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
use Phalcon\Logger\Enum;
use Phalcon\Logger\LoggerInterface;
use Phalcon\Support\Helper\Json\Encode;

/**
 * Sends query profiles to a logger.
 */
class Profiler implements ProfilerInterface
{
    protected bool active = false;
    protected array context = [];
    protected string logFormat = "";
    protected <LoggerInterface> logger;

    /**
     * @var int|string
     */
    protected logLevel = 0;
    private <Encode> encode;

    /**
     * Constructor.
     */
    public function __construct(<LoggerInterface> logger = null)
    {
        if logger === null {
            let logger = new MemoryLogger();
        }

        let this->logFormat = "{method} ({duration}s): {statement} {backtrace}",
            this->logLevel  = Enum::DEBUG,
            this->logger    = logger,
            this->encode    = new Encode();
    }

    /**
     * Finishes and logs a profile entry.
     */
    public function finish(string statement = null, array values = []) -> void
    {
        var ex, finish;

        if unlikely this->active {
            let ex     = new Exception(),
                finish = hrtime(true);


            let this->context["backtrace"] = ex->getTraceAsString(),
                this->context["duration"]  = finish - this->context["start"],
                this->context["finish"]    = finish,
                this->context["statement"] = statement,
                this->context["values"]    = empty(values) ? "" : this->encode->__invoke(values);

            this->logger->log(this->logLevel, this->logFormat, this->context);

            let this->context = [];
        }
    }

    /**
     * Returns the log message format string, with placeholders.
     */
    public function getLogFormat() -> string
    {
        return this->logFormat;
    }

    /**
     * Returns the underlying logger instance.
     */
    public function getLogger() -> <LoggerInterface>
    {
        return this->logger;
    }

    /**
     * Returns the level at which to log profile messages.
     */
    public function getLogLevel() -> string
    {
        return (string) this->logLevel;
    }

    /**
     * Returns true if logging is active.
     */
    public function isActive() -> bool
    {
        return this->active;
    }

    /**
     * Enable or disable profiler logging.
     */
    public function setActive(bool active) -> <ProfilerInterface>
    {
        let this->active = active;

        return this;
    }

    /**
     * Sets the log message format string, with placeholders.
     */
    public function setLogFormat(string logFormat) -> <ProfilerInterface>
    {
        let this->logFormat = logFormat;

        return this;
    }

    /**
     * Level at which to log profile messages.
     */
    public function setLogLevel(string logLevel) -> <ProfilerInterface>
    {
        let this->logLevel = logLevel;

        return this;
    }

    /**
     * Starts a profile entry.
     */
    public function start(string method) -> void
    {
        if unlikely this->active {
            let this->context = [
                "method" : method,
                "start"  : hrtime(true)
            ];
        }
    }
}
