
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

use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Producer as ProducerInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Queue\Exceptions\DeliveryDelayNotSupportedException;
use Phalcon\Queue\Exceptions\InvalidDestinationException;
use Phalcon\Queue\Exceptions\PriorityNotSupportedException;
use Phalcon\Queue\Exceptions\TimeToLiveNotSupportedException;

/**
 * Sends messages into an in-process queue. The Memory transport delivers
 * immediately and in-process, so delivery delay, priority and time to live
 * are not supported.
 */
class MemoryProducer implements ProducerInterface
{
    /**
     * @var MemoryContext
     */
    protected context;

    /**
     * MemoryProducer constructor.
     */
    public function __construct(<MemoryContext> context)
    {
        let this->context = context;
    }

    /**
     * The Memory transport does not support a delivery delay.
     */
    public function getDeliveryDelay() -> int | null
    {
        return null;
    }

    /**
     * The Memory transport does not support message priority.
     */
    public function getPriority() -> int | null
    {
        return null;
    }

    /**
     * The Memory transport does not support a time to live.
     */
    public function getTimeToLive() -> int | null
    {
        return null;
    }

    /**
     * Sends a message to the given queue destination.
     */
    public function send(<DestinationInterface> destination, <MessageInterface> message) -> void
    {
        if unlikely !(destination instanceof QueueInterface) {
            throw new InvalidDestinationException(
                "The Memory transport can only send to a Queue destination"
            );
        }

        this->context->pushMessage(destination->getQueueName(), message);
    }

    /**
     * @throws DeliveryDelayNotSupportedException when a non-null delay is set.
     */
    public function setDeliveryDelay(var deliveryDelay = null) -> <ProducerInterface>
    {
        if unlikely deliveryDelay !== null {
            throw new DeliveryDelayNotSupportedException(
                "The Memory transport does not support a delivery delay"
            );
        }

        return this;
    }

    /**
     * @throws PriorityNotSupportedException when a non-null priority is set.
     */
    public function setPriority(var priority = null) -> <ProducerInterface>
    {
        if unlikely priority !== null {
            throw new PriorityNotSupportedException(
                "The Memory transport does not support message priority"
            );
        }

        return this;
    }

    /**
     * @throws TimeToLiveNotSupportedException when a non-null TTL is set.
     */
    public function setTimeToLive(var timeToLive = null) -> <ProducerInterface>
    {
        if unlikely timeToLive !== null {
            throw new TimeToLiveNotSupportedException(
                "The Memory transport does not support a time to live"
            );
        }

        return this;
    }
}
