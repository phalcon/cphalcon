
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

use Phalcon\Contracts\DataMapper\DataMapperTypes;
use Phalcon\Logger\LoggerInterface;

/**
 * Interface to send query profiles to a logger.
 *
 * @phpstan-import-type datamapper_values from DataMapperTypes
 */
interface ProfilerInterface
{
    /**
     * Finishes and logs a profile entry.
     *
     * @phpstan-param datamapper_values $values
     */
    public function finish(string statement = null, array values = []) -> void;

    /**
     * Returns the log message format string, with placeholders.
     */
    public function getLogFormat() -> string;

    /**
     * Returns the underlying logger instance.
     */
    public function getLogger() -> <LoggerInterface>;

    /**
     * Returns the level at which to log profile messages.
     */
    public function getLogLevel() -> string;

    /**
     * Returns true if logging is active.
     */
    public function isActive() -> bool;

    /**
     * Enable or disable profiler logging.
     */
    public function setActive(bool active) -> <ProfilerInterface>;

    /**
     * Sets the log message format string, with placeholders.
     */
    public function setLogFormat(string logFormat) -> <ProfilerInterface>;

    /**
     * Level at which to log profile messages.
     */
    public function setLogLevel(string logLevel) -> <ProfilerInterface>;

    /**
     * Starts a profile entry.
     */
    public function start(string method) -> void;
}
