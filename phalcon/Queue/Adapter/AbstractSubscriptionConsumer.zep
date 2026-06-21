
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

use Phalcon\Contracts\Queue\Consumer as ConsumerInterface;
use Phalcon\Contracts\Queue\SubscriptionConsumer as SubscriptionConsumerInterface;

/**
 * Shared subscription-consumer base. Implements the round-robin poll loop that
 * dispatches each subscribed consumer's messages to its callback; a callback
 * returning false stops consumption. The loop relies only on the consumer's
 * `receiveNoWait()`, so it is transport-agnostic. Concrete adapters keep just
 * the constructor that captures their context and poll interval.
 */
abstract class AbstractSubscriptionConsumer implements SubscriptionConsumerInterface
{
    /**
     * Milliseconds slept between poll passes.
     *
     * @var int
     */
    protected pollInterval = 200;

    /**
     * Subscriptions keyed by queue name: [consumer, callback].
     *
     * @var array
     */
    protected subscriptions = [];

    /**
     * Polls every subscription, dispatching each message to its callback,
     * blocking up to timeout milliseconds (0 = block until a callback
     * returns false).
     */
    public function consume(int timeout = 0) -> void
    {
        var subscription, consumer, callback, message, result;
        int startTime, sleep;

        if empty this->subscriptions {
            return;
        }

        let sleep     = this->pollInterval * 1000,
            startTime = (int) (microtime(true) * 1000);

        loop {
            for subscription in this->subscriptions {
                let consumer = subscription[0],
                    callback = subscription[1],
                    message  = consumer->receiveNoWait();

                if message !== null {
                    let result = call_user_func(callback, message, consumer);

                    if result === false {
                        return;
                    }
                }
            }

            if timeout > 0 && (((int) (microtime(true) * 1000)) - startTime) >= timeout {
                return;
            }

            usleep(sleep);
        }
    }

    /**
     * Subscribes a consumer; the callback receives each delivered message.
     */
    public function subscribe(<ConsumerInterface> consumer, callable callback) -> void
    {
        let this->subscriptions[this->resolveQueueName(consumer)] = [consumer, callback];
    }

    /**
     * Removes a previously subscribed consumer.
     */
    public function unsubscribe(<ConsumerInterface> consumer) -> void
    {
        unset(this->subscriptions[this->resolveQueueName(consumer)]);
    }

    /**
     * Removes every subscribed consumer.
     */
    public function unsubscribeAll() -> void
    {
        let this->subscriptions = [];
    }

    /**
     * Resolves a consumer's queue name. The `consumer` parameter is typed
     * `var` so the call is dynamic; this avoids Zephir resolving the
     * Consumer::getQueue() return type's short name in the wrong namespace.
     */
    private function resolveQueueName(var consumer) -> string
    {
        return consumer->getQueue()->getQueueName();
    }
}
