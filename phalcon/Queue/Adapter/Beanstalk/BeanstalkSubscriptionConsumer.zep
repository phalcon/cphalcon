
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Beanstalk;

use Phalcon\Contracts\Queue\Consumer as ConsumerInterface;
use Phalcon\Contracts\Queue\SubscriptionConsumer as SubscriptionConsumerInterface;

/**
 * Consumes from several Beanstalkd tubes at once, round-robin polling each
 * subscribed consumer and dispatching messages to its callback. A callback
 * returning false stops consumption.
 */
class BeanstalkSubscriptionConsumer implements SubscriptionConsumerInterface
{
    /**
     * @var BeanstalkContext
     */
    protected context;

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

    public function __construct(<BeanstalkContext> context, int pollInterval = 200)
    {
        let this->context      = context,
            this->pollInterval = pollInterval;
    }

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

    public function subscribe(<ConsumerInterface> consumer, callable callback) -> void
    {
        let this->subscriptions[this->resolveQueueName(consumer)] = [consumer, callback];
    }

    public function unsubscribe(<ConsumerInterface> consumer) -> void
    {
        unset(this->subscriptions[this->resolveQueueName(consumer)]);
    }

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
