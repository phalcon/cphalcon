
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

/**
 * Phalcon Logger.
 *
 * A logger, with various adapters and formatters. A formatter
 * interface is available as well as an adapter one. Adapters can be created
 * easily using the built-in AdapterFactory. A LoggerFactory is also available
 * that allows developers to create new instances of the Logger or load them
 * from config files (see Phalcon\Config\Config object).
 */
class Logger extends AbstractLogger implements LoggerInterface
{
    /**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     *
     * @throws Exception
     */
    public function alert(string message, array context = []) -> void
    {
        this->addMessage(Enum::ALERT, message, context);
    }

    /**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     *
     * @throws Exception
     */
    public function critical(string message, array context = []) -> void
    {
        this->addMessage(Enum::CRITICAL, message, context);
    }

    /**
     * Detailed debug information.
     *
     * @throws Exception
     */
    public function debug(string message, array context = []) -> void
    {
        this->addMessage(Enum::DEBUG, message, context);
    }

    /**
     * System is unusable.
     *
     * @throws Exception
     */
    public function emergency(string message, array context = []) -> void
    {
        this->addMessage(Enum::EMERGENCY, message, context);
    }

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @throws Exception
     */
    public function error(string message, array context = []) -> void
    {
        this->addMessage(Enum::ERROR, message, context);
    }

    /**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     *
     * @throws Exception
     */
    public function info(string message, array context = []) -> void
    {
        this->addMessage(Enum::INFO, message, context);
    }

    /**
     * Logs with an arbitrary level.
     *
     * An unknown level (a typo or an unmapped value) is not rejected; it maps
     * to the CUSTOM level and is logged, rather than raising an exception.
     *
     * @throws Exception
     */
    public function log(var level, string message, array context = []) -> void
    {
        var intLevel;

        let intLevel = this->getLevelNumber(level);

        this->addMessage(intLevel, (string) message, context);
    }

    /**
     * Normal but significant events.
     *
     * @throws Exception
     */
    public function notice(string message, array context = []) -> void
    {
        this->addMessage(Enum::NOTICE, message, context);
    }

    /**
     * Extra-verbose diagnostic output.
     *
     * Use for high-frequency, fine-grained events such as raw socket frames,
     * HTTP response bodies, or internal state transitions that are too noisy
     * for DEBUG.
     *
     * @throws Exception
     */
    public function trace(string message, array context = []) -> void
    {
        this->addMessage(Enum::TRACE, message, context);
    }

    /**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     *
     * @throws Exception
     */
    public function warning(string message, array context = []) -> void
    {
        this->addMessage(Enum::WARNING, message, context);
    }
}
