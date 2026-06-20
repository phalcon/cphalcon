
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Redis;

use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Producer as ProducerInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Queue\Exceptions\InvalidDestinationException;
use Phalcon\Queue\Exceptions\PriorityNotSupportedException;
use Phalcon\Queue\Exceptions\TimeToLiveNotSupportedException;

/**
 * Sends messages to a Redis queue. Delivery delay is supported (via the
 * delayed sorted set); priority and time to live are not.
 */
class RedisProducer implements ProducerInterface
{
    /**
     * @var RedisContext
     */
    protected context;

    /**
     * Delivery delay in milliseconds, or null when not set.
     *
     * @var int | null
     */
    protected deliveryDelay = null;

    public function __construct(<RedisContext> context)
    {
        let this->context = context;
    }

    public function getDeliveryDelay() -> int | null
    {
        return this->deliveryDelay;
    }

    public function getPriority() -> int | null
    {
        return null;
    }

    public function getTimeToLive() -> int | null
    {
        return null;
    }

    public function send(<DestinationInterface> destination, <MessageInterface> message) -> void
    {
        int delay;

        if unlikely !(destination instanceof QueueInterface) {
            throw new InvalidDestinationException(
                "The Redis transport can only send to a Queue destination"
            );
        }

        let delay = this->deliveryDelay === null ? 0 : (int) this->deliveryDelay;

        this->context->pushMessage(destination->getQueueName(), message, delay);
    }

    public function setDeliveryDelay(var deliveryDelay = null) -> <ProducerInterface>
    {
        let this->deliveryDelay = deliveryDelay === null ? null : (int) deliveryDelay;

        return this;
    }

    public function setPriority(var priority = null) -> <ProducerInterface>
    {
        if unlikely priority !== null {
            throw new PriorityNotSupportedException(
                "The Redis transport does not support message priority"
            );
        }

        return this;
    }

    public function setTimeToLive(var timeToLive = null) -> <ProducerInterface>
    {
        if unlikely timeToLive !== null {
            throw new TimeToLiveNotSupportedException(
                "The Redis transport does not support a time to live"
            );
        }

        return this;
    }
}
