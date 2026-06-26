
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */

namespace Phalcon\Queue\Adapter;

use Phalcon\Contracts\Queue\Consumer as ConsumerInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;

/**
 * Shared consumer base. Implements the blocking `receive()` as a polling loop
 * on top of the abstract `receiveNoWait()`; concrete consumers provide the
 * transport-specific `receiveNoWait`, `acknowledge` and `reject`.
 *
 * Transports with a native blocking receive (Redis BRPOP, Beanstalk reserve)
 * override `receive()` instead of polling.
 */
abstract class AbstractConsumer implements ConsumerInterface
{
    /**
     * Milliseconds slept between poll attempts.
     *
     * @var int
     */
    protected pollInterval = 200;

    /**
     * The queue this consumer reads from.
     *
     * @var QueueInterface
     */
    protected queue;

    /**
     * Acknowledges the message; the transport may then discard it.
     */
    abstract public function acknowledge(<MessageInterface> message) -> void;

    /**
     * Returns the queue this consumer reads from.
     */
    public function getQueue() -> <QueueInterface>
    {
        return this->queue;
    }

    /**
     * Receives a message, blocking up to timeout milliseconds (0 = block
     * until one is available), by polling `receiveNoWait()` every
     * `pollInterval` milliseconds. Returns null when none arrives in time.
     */
    public function receive(int timeout = 0) -> <MessageInterface> | null
    {
        var message;
        int startTime, sleep;

        let sleep     = this->pollInterval * 1000,
            startTime = (int) (microtime(true) * 1000);

        loop {
            let message = this->receiveNoWait();

            if message !== null {
                return message;
            }

            if timeout > 0 && (((int) (microtime(true) * 1000)) - startTime) >= timeout {
                return null;
            }

            usleep(sleep);
        }

        return null;
    }

    /**
     * Receives a message without blocking, or null when none is ready.
     */
    abstract public function receiveNoWait() -> <MessageInterface> | null;

    /**
     * Rejects the message. When requeue is true the transport redelivers it.
     */
    abstract public function reject(<MessageInterface> message, bool requeue = false) -> void;

    /**
     * Sets the poll interval (in milliseconds) used by `receive()`.
     */
    public function setPollInterval(int pollInterval) -> void
    {
        let this->pollInterval = pollInterval;
    }
}
