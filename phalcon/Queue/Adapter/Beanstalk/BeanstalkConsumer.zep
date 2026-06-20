
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

use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Contracts\Queue\VisibilityAware;
use Phalcon\Queue\Adapter\AbstractConsumer;

/**
 * Receives messages from a single Beanstalkd tube over its own connection.
 * `receive()` is overridden to use the native blocking reserve. Implements
 * VisibilityAware: a reserved job has a time-to-run window that `touch()`
 * extends; acknowledging deletes the job, rejecting releases it (requeue) or
 * buries it.
 */
class BeanstalkConsumer extends AbstractConsumer implements VisibilityAware
{
    /**
     * Default Beanstalkd priority used when releasing or burying.
     *
     * @var int
     */
    const DEFAULT_PRIORITY = 100;

    /**
     * @var BeanstalkConnection
     */
    protected connection;

    /**
     * @var QueueInterface
     */
    protected queue;

    public function __construct(<BeanstalkConnection> connection, <QueueInterface> queue)
    {
        var tube;

        let this->connection = connection,
            this->queue      = queue,
            tube             = queue->getQueueName();

        connection->watchTube(tube);

        if tube != "default" {
            connection->ignoreTube("default");
        }
    }

    public function acknowledge(<MessageInterface> message) -> void
    {
        this->connection->deleteJob(this->resolveJobId(message));
    }

    public function getQueue() -> <QueueInterface>
    {
        return this->queue;
    }

    public function receive(int timeout = 0) -> <MessageInterface> | null
    {
        var seconds;

        if timeout <= 0 {
            let seconds = null;
        } else {
            let seconds = (int) ((timeout + 999) / 1000);
        }

        return this->buildMessage(this->connection->reserve(seconds));
    }

    public function receiveNoWait() -> <MessageInterface> | null
    {
        return this->buildMessage(this->connection->reserve(0));
    }

    public function reject(<MessageInterface> message, bool requeue = false) -> void
    {
        var id;

        let id = this->resolveJobId(message);

        if requeue {
            this->connection->releaseJob(id, self::DEFAULT_PRIORITY, 0);
        } else {
            this->connection->buryJob(id, self::DEFAULT_PRIORITY);
        }
    }

    /**
     * Extends the time-to-run window of a reserved job (VisibilityAware).
     */
    public function touch(<MessageInterface> message) -> bool
    {
        return this->connection->touchJob(this->resolveJobId(message));
    }

    /**
     * Builds a BeanstalkMessage from a reserved [id, body] pair, or null.
     */
    private function buildMessage(var job) -> <MessageInterface> | null
    {
        var data, message;

        if typeof job != "array" {
            return null;
        }

        let data = unserialize(job[1]);

        if typeof data != "array" {
            return null;
        }

        let message = new BeanstalkMessage(data["body"], data["properties"], data["headers"]);

        message->setJobId(job[0]);

        return message;
    }

    /**
     * Resolves a message's Beanstalkd job id. The `message` parameter is typed
     * `var` so the call is dynamic; this avoids Zephir resolving getJobId()
     * against the Message interface, which does not declare it.
     */
    private function resolveJobId(var message) -> string
    {
        return message->getJobId();
    }
}
