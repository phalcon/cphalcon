
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

use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Queue\Adapter\AbstractProducer;
use Phalcon\Queue\Adapter\QueueDestinationGuard;

/**
 * Appends messages to a filesystem queue. The Stream transport delivers in
 * insertion order with no scheduling, so delivery delay, priority and time to
 * live are not supported (the defaults from AbstractProducer reject them).
 */
class StreamProducer extends AbstractProducer
{
    /**
     * @var StreamContext
     */
    protected context;

    public function __construct(<StreamContext> context)
    {
        let this->context = context;
    }

    public function send(<DestinationInterface> destination, <MessageInterface> message) -> void
    {
        QueueDestinationGuard::assertQueue(destination, "send to");

        this->context->pushMessage(destination->getQueueName(), message);
    }
}
