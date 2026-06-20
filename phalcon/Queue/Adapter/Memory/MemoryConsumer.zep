
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

namespace Phalcon\Queue\Adapter\Memory;

use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Queue\Adapter\AbstractConsumer;

/**
 * Receives messages from a single in-process queue. `receive()` is the
 * polling loop inherited from AbstractConsumer.
 */
class MemoryConsumer extends AbstractConsumer
{
    /**
     * @var MemoryContext
     */
    protected context;

    /**
     * @var QueueInterface
     */
    protected queue;

    /**
     * MemoryConsumer constructor.
     */
    public function __construct(<MemoryContext> context, <QueueInterface> queue)
    {
        let this->context = context,
            this->queue   = queue;
    }

    /**
     * No-op: a received message has already been removed from the queue.
     */
    public function acknowledge(<MessageInterface> message) -> void
    {
    }

    /**
     * Returns the queue this consumer reads from.
     */
    public function getQueue() -> <QueueInterface>
    {
        return this->queue;
    }

    /**
     * Removes and returns the next message, or null when the queue is empty.
     */
    public function receiveNoWait() -> <MessageInterface> | null
    {
        return this->context->popMessage(this->queue->getQueueName());
    }

    /**
     * Rejects the message. When requeue is true it is put back on the queue.
     */
    public function reject(<MessageInterface> message, bool requeue = false) -> void
    {
        if requeue {
            this->context->pushMessage(this->queue->getQueueName(), message);
        }
    }
}
