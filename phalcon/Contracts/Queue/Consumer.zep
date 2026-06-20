
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Queue;

/**
 * Receives messages from a single queue.
 */
interface Consumer
{
    /**
     * Acknowledges the message; the transport may then discard it.
     */
    public function acknowledge(<Message> message) -> void;

    /**
     * Returns the queue this consumer reads from.
     */
    public function getQueue() -> <Queue>;

    /**
     * Receives a message, blocking up to timeout milliseconds (0 = block
     * until one is available). Returns null when none arrives in time.
     */
    public function receive(int timeout = 0) -> <Message> | null;

    /**
     * Receives a message without blocking, or null when none is ready.
     */
    public function receiveNoWait() -> <Message> | null;

    /**
     * Rejects the message. When requeue is true the transport redelivers it.
     */
    public function reject(<Message> message, bool requeue = false) -> void;
}
