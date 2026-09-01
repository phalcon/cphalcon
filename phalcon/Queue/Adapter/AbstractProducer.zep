
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

use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Producer as ProducerInterface;
use Phalcon\Queue\Exceptions\DeliveryDelayNotSupportedException;
use Phalcon\Queue\Exceptions\PriorityNotSupportedException;
use Phalcon\Queue\Exceptions\TimeToLiveNotSupportedException;

/**
 * Shared producer base. Defaults every optional capability (delivery delay,
 * priority, time to live) to "unsupported": the getter returns null and the
 * setter throws the matching exception for any non-null value. A concrete
 * producer overrides only the capabilities its transport actually supports,
 * and implements `send()`.
 */
abstract class AbstractProducer implements ProducerInterface
{
    public function getDeliveryDelay() -> int | null
    {
        return null;
    }

    public function getPriority() -> int | null
    {
        return null;
    }

    public function getTimeToLive() -> int | null
    {
        return null;
    }

    abstract public function send(<DestinationInterface> destination, <MessageInterface> message) -> void;

    public function setDeliveryDelay(var deliveryDelay = null) -> <ProducerInterface>
    {
        if unlikely deliveryDelay !== null {
            throw new DeliveryDelayNotSupportedException();
        }

        return this;
    }

    public function setPriority(var priority = null) -> <ProducerInterface>
    {
        if unlikely priority !== null {
            throw new PriorityNotSupportedException();
        }

        return this;
    }

    public function setTimeToLive(var timeToLive = null) -> <ProducerInterface>
    {
        if unlikely timeToLive !== null {
            throw new TimeToLiveNotSupportedException();
        }

        return this;
    }
}
