
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

namespace Phalcon\Queue\Adapter\Stream;

use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Queue\Adapter\AbstractConsumer;

/**
 * Receives messages from a single filesystem queue. `receive()` is the
 * polling loop inherited from AbstractConsumer.
 */
class StreamConsumer extends AbstractConsumer
{
    /**
     * @var StreamContext
     */
    protected context;

    public function __construct(<StreamContext> context, <QueueInterface> queue, int pollInterval = 200)
    {
        let this->context      = context,
            this->queue        = queue,
            this->pollInterval = pollInterval;
    }

    /**
     * No-op: a received message has already been removed from the queue file.
     */
    public function acknowledge(<MessageInterface> message) -> void
    {
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
