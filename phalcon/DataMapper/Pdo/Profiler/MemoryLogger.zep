
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

use Phalcon\Logger\Enum;
use Phalcon\Logger\Adapter\AdapterInterface;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\LoggerInterface;

/**
 * A memory-based logger.
 *
 * @property array $messages
 */
class MemoryLogger implements LoggerInterface
{
    /**
     * @var array
     */
    protected messages = [];

    /**
     * @param string message
     * @param mixed[] context
     */
    public function alert(string message, array context = []) -> void
    {
        this->log(Enum::ALERT, message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function critical(string message, array context = []) -> void
    {
        this->log(Enum::CRITICAL, message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function debug(string message, array context = []) -> void
    {
        this->log(Enum::DEBUG, message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function emergency(string message, array context = []) -> void
    {
        this->log(Enum::EMERGENCY, message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function error(string message, array context = []) -> void
    {
        this->log(Enum::ERROR, message, context);
    }

    /**
     * Returns an adapter from the stack
     *
     * @param string $name The name of the adapter
     *
     * @return AdapterInterface
     */
    public function getAdapter(string name) -> <AdapterInterface>
    {
        return new Noop();
    }

    /**
     * Returns the adapter stack array
     *
     * @return AdapterInterface[]
     */
    public function getAdapters() -> array
    {
        return [];
    }

    /**
     * Returns the log level
     */
    public function getLogLevel() -> int
    {
        return Enum::CUSTOM;
    }

    /**
     * Returns the logged messages.
     *
     * @return array
     */
    public function getMessages() -> array
    {
        return this->messages;
    }

    /**
     * Returns the name of the logger
     */
    public function getName() -> string
    {
        return "memory logger";
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function info(string message, array context = []) -> void
    {
        this->log(Enum::INFO, message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function notice(string message, array context = []) -> void
    {
        this->log(Enum::NOTICE, message, context);
    }


    /**
     * @param string message
     * @param mixed[] context
     */
    public function warning(string message, array context = []) -> void
    {
        this->log(Enum::WARNING, message, context);
    }

    /**
     * Logs a message.
     *
     * @param mixed  $level
     * @param string $message
     * @param array  $context
     */
    public function log(var level, string message, array context = []) -> void
    {
        var key, value;
        array replace = [];

        for key, value in context {
            let replace["{" . key . "}"] = value;
        }

        let this->messages[] = strtr(message, replace);
    }
}
