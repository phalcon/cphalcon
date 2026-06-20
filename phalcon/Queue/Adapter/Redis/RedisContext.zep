
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Redis;

use Phalcon\Contracts\Queue\Consumer as ConsumerInterface;
use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Producer as ProducerInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Contracts\Queue\SubscriptionConsumer as SubscriptionConsumerInterface;
use Phalcon\Contracts\Queue\Topic as TopicInterface;
use Phalcon\Queue\Exceptions\InvalidDestinationException;

/**
 * Redis transport session (ext-redis). Each queue is a Redis list; messages
 * are LPUSHed on send and RPOP/BRPOPed on receive, giving FIFO delivery.
 * Delayed messages live in a companion sorted set (`<key>:delayed`) scored by
 * their due time in milliseconds, and are promoted into the list once due.
 */
class RedisContext implements ContextInterface
{
    /**
     * Milliseconds slept between poll passes by a subscription consumer.
     *
     * @var int
     */
    protected pollInterval = 200;

    /**
     * Key prefix applied to every queue (and its delayed companion set).
     *
     * @var string
     */
    protected prefix = "phalcon_queue:";

    /**
     * The connected ext-redis client.
     *
     * @var \Redis
     */
    protected redis;

    public function __construct(var redis, string prefix = "phalcon_queue:", int pollInterval = 200)
    {
        let this->redis        = redis,
            this->prefix       = prefix,
            this->pollInterval = pollInterval;
    }

    /**
     * Blocking pop from the back of a queue list. Promotes any due delayed
     * messages first, then blocks up to timeout seconds. Internal transport
     * API used by RedisConsumer.
     */
    public function blockingPop(string queueName, int timeout) -> <MessageInterface> | null
    {
        var result;

        this->promote(queueName);

        let result = this->redis->brPop([this->listKey(queueName)], timeout);

        if typeof result == "array" && count(result) >= 2 {
            return this->unserializeMessage(result[1]);
        }

        return null;
    }

    public function close() -> void
    {
    }

    public function createConsumer(<DestinationInterface> destination) -> <ConsumerInterface>
    {
        if unlikely !(destination instanceof QueueInterface) {
            throw new InvalidDestinationException(
                "The Redis transport can only consume from a Queue destination"
            );
        }

        return new RedisConsumer(this, destination);
    }

    public function createMessage(string body = "", array properties = [], array headers = []) -> <MessageInterface>
    {
        return new RedisMessage(body, properties, headers);
    }

    public function createProducer() -> <ProducerInterface>
    {
        return new RedisProducer(this);
    }

    public function createQueue(string queueName) -> <QueueInterface>
    {
        return new RedisQueue(queueName);
    }

    public function createSubscriptionConsumer() -> <SubscriptionConsumerInterface>
    {
        return new RedisSubscriptionConsumer(this, this->pollInterval);
    }

    public function createTemporaryQueue() -> <QueueInterface>
    {
        return new RedisQueue(uniqid("phalcon_queue_", true));
    }

    public function createTopic(string topicName) -> <TopicInterface>
    {
        return new RedisTopic(topicName);
    }

    /**
     * Non-blocking pop from the back of a queue list, or null when empty.
     * Promotes any due delayed messages first. Internal transport API used
     * by RedisConsumer.
     */
    public function popMessage(string queueName) -> <MessageInterface> | null
    {
        var payload;

        this->promote(queueName);

        let payload = this->redis->rPop(this->listKey(queueName));

        if payload === false || payload === null {
            return null;
        }

        return this->unserializeMessage(payload);
    }

    public function purgeQueue(<QueueInterface> queue) -> void
    {
        var queueName;

        let queueName = queue->getQueueName();

        this->redis->del(this->listKey(queueName));
        this->redis->del(this->delayedKey(queueName));
    }

    /**
     * Sends a message to a queue. With a positive delay (milliseconds) the
     * message is parked in the delayed set; otherwise it is pushed onto the
     * front of the list. Internal transport API used by RedisProducer.
     */
    public function pushMessage(string queueName, <MessageInterface> message, int delay = 0) -> void
    {
        var payload, member;
        int score;

        let payload = this->serializeMessage(message);

        if delay > 0 {
            let score  = this->now() + delay,
                member = uniqid("", true) . "|" . payload;

            this->redis->zAdd(this->delayedKey(queueName), score, member);

            return;
        }

        this->redis->lPush(this->listKey(queueName), payload);
    }

    private function delayedKey(string queueName) -> string
    {
        return this->prefix . queueName . ":delayed";
    }

    private function listKey(string queueName) -> string
    {
        return this->prefix . queueName;
    }

    private function now() -> int
    {
        return (int) (microtime(true) * 1000);
    }

    /**
     * Moves every due message from the delayed set onto the queue list. The
     * ZREM acts as an atomic claim, so a message promoted by one process is
     * never promoted again by another.
     */
    private function promote(string queueName) -> void
    {
        var delayedKey, listKey, due, member, payload;
        int position;

        let delayedKey = this->delayedKey(queueName),
            listKey    = this->listKey(queueName),
            due        = this->redis->zRangeByScore(delayedKey, 0, this->now());

        if typeof due != "array" {
            return;
        }

        for member in due {
            if this->redis->zRem(delayedKey, member) > 0 {
                let position = strpos(member, "|"),
                    payload  = substr(member, position + 1);

                this->redis->lPush(listKey, payload);
            }
        }
    }

    private function serializeMessage(<MessageInterface> message) -> string
    {
        return serialize(
            [
                "body"       : message->getBody(),
                "properties" : message->getProperties(),
                "headers"    : message->getHeaders()
            ]
        );
    }

    private function unserializeMessage(string payload) -> <MessageInterface> | null
    {
        var data;

        let data = unserialize(payload);

        if typeof data != "array" {
            return null;
        }

        return new RedisMessage(data["body"], data["properties"], data["headers"]);
    }
}
