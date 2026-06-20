
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Redis;

use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Queue\Adapter\AbstractConsumer;

/**
 * Receives messages from a single Redis queue. `receive()` is overridden to
 * use the native blocking BRPOP (in one-second chunks, so due delayed
 * messages keep getting promoted) instead of the inherited polling loop.
 */
class RedisConsumer extends AbstractConsumer
{
    /**
     * @var RedisContext
     */
    protected context;

    /**
     * @var QueueInterface
     */
    protected queue;

    public function __construct(<RedisContext> context, <QueueInterface> queue)
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

    public function getQueue() -> <QueueInterface>
    {
        return this->queue;
    }

    public function receive(int timeout = 0) -> <MessageInterface> | null
    {
        var message, queueName;
        int deadline;

        let queueName = this->queue->getQueueName(),
            deadline  = 0;

        if timeout > 0 {
            let deadline = ((int) (microtime(true) * 1000)) + timeout;
        }

        loop {
            let message = this->context->blockingPop(queueName, 1);

            if message !== null {
                return message;
            }

            if deadline > 0 && ((int) (microtime(true) * 1000)) >= deadline {
                return null;
            }
        }

        return null;
    }

    public function receiveNoWait() -> <MessageInterface> | null
    {
        return this->context->popMessage(this->queue->getQueueName());
    }

    public function reject(<MessageInterface> message, bool requeue = false) -> void
    {
        if requeue {
            this->context->pushMessage(this->queue->getQueueName(), message);
        }
    }
}
