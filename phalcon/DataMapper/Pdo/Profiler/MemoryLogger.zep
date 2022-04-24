
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

use Psr\Log\AbstractLogger;

/**
 * A naive memory-based logger.
 *
 * @property array $messages
 */
class MemoryLogger extends AbstractLogger
{
    /**
     * @var array
     */
    protected messages = [];

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
     * @param string message
     * @param mixed[] context
     */
    public function emergency(var message, array context = [])
    {
        parent::emergency(message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function alert(var message, array context = [])
    {
        parent::alert(message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function critical(var message, array context = [])
    {
        parent::critical(message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function error(var message, array context = [])
    {
        parent::error(message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function warning(var message, array context = [])
    {
        parent::warning(message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function notice(var message, array context = [])
    {
        parent::notice(message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function info(var message, array context = [])
    {
        parent::info(message, context);
    }

    /**
     * @param string message
     * @param mixed[] context
     */
    public function debug(var message, array context = [])
    {
        parent::debug(message, context);
    }

    /**
     * Logs a message.
     *
     * @param mixed  $level
     * @param string $message
     * @param array  $context
     */
    public function log(var level, var message, array context = [])
    {
        var key, value;
        array replace = [];

        for key, value in context {
            let replace["{" . key . "}"] = value;
        }

        let this->messages[] = strtr(message, replace);
    }
}
