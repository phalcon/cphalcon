
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

namespace Phalcon\Contracts\Queue;

/**
 * A session with the transport. Factory for messages, destinations,
 * producers and consumers.
 */
interface Context
{
    /**
     * Closes the context and releases its resources.
     */
    public function close() -> void;

    /**
     * Creates a consumer for the given destination.
     */
    public function createConsumer(<Destination> destination) -> <Consumer>;

    /**
     * Creates a message with an optional body, properties and headers.
     */
    public function createMessage(string body = "", array properties = [], array headers = []) -> <Message>;

    /**
     * Creates a producer.
     */
    public function createProducer() -> <Producer>;

    /**
     * Creates a queue destination by name.
     */
    public function createQueue(string queueName) -> <Queue>;

    /**
     * Creates a subscription consumer for consuming from several queues.
     */
    public function createSubscriptionConsumer() -> <SubscriptionConsumer>;

    /**
     * Creates a temporary queue tied to the lifetime of the context.
     */
    public function createTemporaryQueue() -> <Queue>;

    /**
     * Creates a topic destination by name.
     */
    public function createTopic(string topicName) -> <Topic>;

    /**
     * Removes all messages from the given queue.
     */
    public function purgeQueue(<Queue> queue) -> void;
}
