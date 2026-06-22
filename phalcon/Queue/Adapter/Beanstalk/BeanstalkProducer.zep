
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

namespace Phalcon\Queue\Adapter\Beanstalk;

use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Producer as ProducerInterface;
use Phalcon\Queue\Adapter\AbstractProducer;
use Phalcon\Queue\Adapter\MessageEnvelope;
use Phalcon\Queue\Adapter\QueueDestinationGuard;

/**
 * Sends messages to a Beanstalkd tube. Delivery delay (rounded down to whole
 * seconds) and message priority are supported natively; Beanstalkd has no
 * message expiry, so time to live is not (the default from AbstractProducer
 * rejects it).
 */
class BeanstalkProducer extends AbstractProducer
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

    public function send(<DestinationInterface> destination, <MessageInterface> message) -> void
    {
        var payload;
        int priority, delay;

        QueueDestinationGuard::assertQueue(destination, "send to");

        let payload  = MessageEnvelope::encode(message),
            priority = this->priority === null ? self::DEFAULT_PRIORITY : (int) this->priority,
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
}
