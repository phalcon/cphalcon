
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
 * Consumes from several queues at once, dispatching each message to the
 * callback registered for its consumer.
 */
interface SubscriptionConsumer
{
    /**
     * Starts consuming, blocking up to timeout milliseconds (0 = block
     * until a message is available).
     */
    public function consume(int timeout = 0) -> void;

    /**
     * Subscribes a consumer; the callback receives each delivered message.
     */
    public function subscribe(<Consumer> consumer, callable callback) -> void;

    /**
     * Removes a previously subscribed consumer.
     */
    public function unsubscribe(<Consumer> consumer) -> void;

    /**
     * Removes every subscribed consumer.
     */
    public function unsubscribeAll() -> void;
}
