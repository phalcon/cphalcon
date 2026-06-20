
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
 * Filesystem transport session. Each queue is one append-only file under the
 * configured directory; cross-process safety comes from flock. One message
 * per line, stored as base64(serialize([...])) so bodies with newlines are
 * safe.
 */
class StreamContext implements ContextInterface
{
    /**
     * Milliseconds slept between poll attempts by consumers.
     *
     * @var int
     */
    protected pollInterval = 200;

    /**
     * Directory (with trailing separator) that holds the queue files.
     *
     * @var string
     */
    protected storageDir = "";

    public function __construct(string storageDir, int pollInterval = 200)
    {
        let this->storageDir   = rtrim(storageDir, "/") . "/",
            this->pollInterval = pollInterval;
    }

    public function close() -> void
    {
    }

    public function createConsumer(<DestinationInterface> destination) -> <ConsumerInterface>
    {
        if unlikely !(destination instanceof QueueInterface) {
            throw new InvalidDestinationException(
                "The Stream transport can only consume from a Queue destination"
            );
        }

        return new StreamConsumer(this, destination, this->pollInterval);
    }

    public function createMessage(string body = "", array properties = [], array headers = []) -> <MessageInterface>
    {
        return new StreamMessage(body, properties, headers);
    }

    public function createProducer() -> <ProducerInterface>
    {
        return new StreamProducer(this);
    }

    public function createQueue(string queueName) -> <QueueInterface>
    {
        return new StreamQueue(queueName);
    }

    public function createSubscriptionConsumer() -> <SubscriptionConsumerInterface>
    {
        return new StreamSubscriptionConsumer(this);
    }

    public function createTemporaryQueue() -> <QueueInterface>
    {
        return new StreamQueue(uniqid("phalcon_queue_", true));
    }

    public function createTopic(string topicName) -> <TopicInterface>
    {
        return new StreamTopic(topicName);
    }

    /**
     * Removes the front message from a queue file, or null when it is empty.
     * Internal transport API used by StreamConsumer.
     */
    public function popMessage(string queueName) -> <MessageInterface> | null
    {
        var filepath, pointer, contents, lines, line, data, remaining;

        let filepath = this->getFilepath(queueName);

        if !file_exists(filepath) {
            return null;
        }

        let pointer = fopen(filepath, "c+");

        if pointer === false {
            return null;
        }

        if !flock(pointer, LOCK_EX) {
            fclose(pointer);

            return null;
        }

        let contents = stream_get_contents(pointer),
            lines    = array_filter(explode(PHP_EOL, contents));

        if empty lines {
            flock(pointer, LOCK_UN);
            fclose(pointer);

            return null;
        }

        let line = array_shift(lines);

        if count(lines) > 0 {
            let remaining = implode(PHP_EOL, lines) . PHP_EOL;
        } else {
            let remaining = "";
        }

        ftruncate(pointer, 0);
        rewind(pointer);
        fwrite(pointer, remaining);
        flock(pointer, LOCK_UN);
        fclose(pointer);

        let data = unserialize(base64_decode(line));

        if typeof data !== "array" {
            return null;
        }

        return new StreamMessage(data["body"], data["properties"], data["headers"]);
    }

    public function purgeQueue(<QueueInterface> queue) -> void
    {
        var filepath;

        let filepath = this->getFilepath(queue->getQueueName());

        if file_exists(filepath) {
            unlink(filepath);
        }
    }

    /**
     * Appends a message to the back of a queue file.
     * Internal transport API used by StreamProducer.
     */
    public function pushMessage(string queueName, <MessageInterface> message) -> void
    {
        var filepath, data, line;

        let filepath = this->getFilepath(queueName);

        this->ensureDir();

        let data = [
            "body"       : message->getBody(),
            "properties" : message->getProperties(),
            "headers"    : message->getHeaders()
        ];

        let line = base64_encode(serialize(data)) . PHP_EOL;

        file_put_contents(filepath, line, FILE_APPEND | LOCK_EX);
    }

    private function ensureDir() -> void
    {
        if !is_dir(this->storageDir) {
            mkdir(this->storageDir, 0777, true);
        }
    }

    private function getFilepath(string queueName) -> string
    {
        return this->storageDir . preg_replace("/[^a-zA-Z0-9_-]/", "_", queueName) . ".queue";
    }
}
