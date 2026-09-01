
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Logger;

use Phalcon\Contracts\Logger\Adapter\Adapter;

/**
 * Canonical contract for Phalcon\Logger\Logger.
 */
interface Logger
{
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
    public function alert(string message, array context = []) -> void;

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
    public function critical(string message, array context = []) -> void;

    /**
     * Detailed debug information.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function debug(string message, array context = []) -> void;

    /**
     * System is unusable.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function emergency(string message, array context = []) -> void;

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function error(string message, array context = []) -> void;

    /**
     * Returns an adapter from the stack
     *
     * @param string $name The name of the adapter
     *
     * @return Adapter
     */
    public function getAdapter(string name) -> <Adapter>;

    /**
     * Returns the adapter stack array
     *
     * @return Adapter[]
     */
    public function getAdapters() -> array;

    /**
     * Returns the log level
     */
    public function getLogLevel() -> int;

    /**
     * Returns the name of the logger
     */
    public function getName() -> string;

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
    public function info(string message, array context = []) -> void;

    /**
     * Logs with an arbitrary level.
     *
     * An unknown level (a typo or an unmapped value) is not rejected; it maps
     * to the CUSTOM level and is logged, rather than raising an exception.
     *
     * @param mixed  $level
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function log(var level, string message, array context = []) -> void;

    /**
     * Normal but significant events.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function notice(string message, array context = []) -> void;

    /**
     * Extra-verbose diagnostic output.
     *
     * @param string $message
     * @param array  $context
     *
     * @return void
     */
    public function trace(string message, array context = []) -> void;

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
    public function warning(string message, array context = []) -> void;
}
