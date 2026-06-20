
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Beanstalk;

use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Producer as ProducerInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Queue\Exceptions\InvalidDestinationException;
use Phalcon\Queue\Exceptions\TimeToLiveNotSupportedException;

/**
 * Sends messages to a Beanstalkd tube. Delivery delay (rounded down to whole
 * seconds) and message priority are supported natively; Beanstalkd has no
 * message expiry, so time to live is not.
 */
class BeanstalkProducer implements ProducerInterface
{
    /**
     * Default Beanstalkd priority (0 = most urgent).
     *
     * @var int
     */
    const DEFAULT_PRIORITY = 100;

    /**
     * @var BeanstalkContext
     */
    protected context;

    /**
     * Delivery delay in milliseconds, or null when not set.
     *
     * @var int | null
     */
    protected deliveryDelay = null;

    /**
     * Job priority, or null when not set.
     *
     * @var int | null
     */
    protected priority = null;

    public function __construct(<BeanstalkContext> context)
    {
        let this->context = context;
    }

    public function getDeliveryDelay() -> int | null
    {
        return this->deliveryDelay;
    }

    public function getPriority() -> int | null
    {
        return this->priority;
    }

    public function getTimeToLive() -> int | null
    {
        return null;
    }

    public function send(<DestinationInterface> destination, <MessageInterface> message) -> void
    {
        var payload;
        int priority, delay;

        if unlikely !(destination instanceof QueueInterface) {
            throw new InvalidDestinationException(
                "The Beanstalk transport can only send to a Queue destination"
            );
        }

        let payload = serialize(
            [
                "body"       : message->getBody(),
                "properties" : message->getProperties(),
                "headers"    : message->getHeaders()
            ]
        );

        let priority = this->priority === null ? self::DEFAULT_PRIORITY : (int) this->priority,
            delay    = this->deliveryDelay === null ? 0 : (int) (this->deliveryDelay / 1000);

        this->context->putMessage(
            destination->getQueueName(),
            payload,
            priority,
            delay,
            this->context->getTtr()
        );
    }

    public function setDeliveryDelay(var deliveryDelay = null) -> <ProducerInterface>
    {
        let this->deliveryDelay = deliveryDelay === null ? null : (int) deliveryDelay;

        return this;
    }

    public function setPriority(var priority = null) -> <ProducerInterface>
    {
        let this->priority = priority === null ? null : (int) priority;

        return this;
    }

    public function setTimeToLive(var timeToLive = null) -> <ProducerInterface>
    {
        if unlikely timeToLive !== null {
            throw new TimeToLiveNotSupportedException(
                "The Beanstalk transport does not support a time to live"
            );
        }

        return this;
    }
}
