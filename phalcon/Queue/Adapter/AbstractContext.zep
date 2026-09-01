
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

use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Contracts\Queue\Topic as TopicInterface;

/**
 * Shared transport-session base. Every transport builds the same destination
 * value objects (GenericQueue / GenericTopic) and the same uniquely named
 * temporary queue, so those factories live here once. Concrete contexts
 * implement the transport-specific factories (consumer, producer, message,
 * subscription consumer) and the storage operations.
 */
abstract class AbstractContext implements ContextInterface
{
    /**
     * Creates a queue destination by name.
     */
    public function createQueue(string queueName) -> <QueueInterface>
    {
        return new GenericQueue(queueName);
    }

    /**
     * Creates a uniquely named temporary queue.
     */
    public function createTemporaryQueue() -> <QueueInterface>
    {
        return new GenericQueue(uniqid("phalcon_queue_", true));
    }

    /**
     * Creates a topic destination by name.
     */
    public function createTopic(string topicName) -> <TopicInterface>
    {
        return new GenericTopic(topicName);
    }
}
