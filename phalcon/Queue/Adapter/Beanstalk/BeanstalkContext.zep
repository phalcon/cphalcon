
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

use Phalcon\Contracts\Queue\Consumer as ConsumerInterface;
use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Inspectable;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Producer as ProducerInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Contracts\Queue\SubscriptionConsumer as SubscriptionConsumerInterface;
use Phalcon\Queue\Adapter\AbstractContext;
use Phalcon\Queue\Adapter\QueueDestinationGuard;

/**
 * Beanstalkd transport session. A queue maps to a Beanstalkd tube. Producers
 * share the context connection (`use` + `put`); each consumer owns its own
 * connection, because Beanstalkd only lets the reserving connection delete,
 * release, bury or touch a job. The destination factories come from
 * AbstractContext.
 */
class BeanstalkContext extends AbstractContext implements Inspectable
{
    /**
     * Shared connection used by producers and purges.
     *
     * @var BeanstalkConnection | null
     */
    protected connection = null;

    /**
     * @var string
     */
    protected host = "127.0.0.1";

    /**
     * @var bool
     */
    protected persistent = false;

    /**
     * Milliseconds slept between poll passes by a subscription consumer.
     *
     * @var int
     */
    protected pollInterval = 200;

    /**
     * @var int
     */
    protected port = 11300;

    /**
     * Default time-to-run (seconds) applied to every put.
     *
     * @var int
     */
    protected ttr = 86400;

    public function __construct(
        string host,
        int port,
        bool persistent = false,
        int ttr = 86400,
        int pollInterval = 200
    ) {
        let this->host         = host,
            this->port         = port,
            this->persistent   = persistent,
            this->ttr          = ttr,
            this->pollInterval = pollInterval;
    }

    public function close() -> void
    {
        if this->connection !== null {
            this->connection->disconnect();

            let this->connection = null;
        }
    }

    public function createConsumer(<DestinationInterface> destination) -> <ConsumerInterface>
    {
        QueueDestinationGuard::assertQueue(destination, "consume from");

        return new BeanstalkConsumer(this->newConnection(), destination);
    }

    public function createMessage(string body = "", array properties = [], array headers = []) -> <MessageInterface>
    {
        return new BeanstalkMessage(body, properties, headers);
    }

    public function createProducer() -> <ProducerInterface>
    {
        return new BeanstalkProducer(this);
    }

    public function createSubscriptionConsumer() -> <SubscriptionConsumerInterface>
    {
        return new BeanstalkSubscriptionConsumer(this, this->pollInterval);
    }

    /**
     * Returns the Beanstalkd `stats-tube` fields for the queue's tube as an
     * associative array, with numeric values cast to int (the `name` field is
     * kept as a string). When the tube exists the result is the full Beanstalkd
     * stats-tube field set (current-jobs-*, total-jobs, the `cmd-*` counters and
     * tube-configuration fields).
     *
     * The `current-jobs-*` backlog keys are always present: an unknown tube
     * (no jobs, not used or watched) has zero backlog, so those keys are
     * returned at zero. This keeps the backlog shape independent of transient
     * watcher state. Runs on a fresh short-lived connection (like purgeQueue)
     * so the read never shares the producer's socket.
     */
    public function getStats(<QueueInterface> queue) -> array
    {
        var connection, stats;

        let connection = this->newConnection();
        let stats      = connection->statsTube(queue->getQueueName());

        connection->disconnect();

        if stats === false {
            return [
                "current-jobs-urgent"   : 0,
                "current-jobs-ready"    : 0,
                "current-jobs-reserved" : 0,
                "current-jobs-delayed"  : 0,
                "current-jobs-buried"   : 0
            ];
        }

        return stats;
    }

    /**
     * Default time-to-run (seconds) for new jobs. Used by BeanstalkProducer.
     */
    public function getTtr() -> int
    {
        return this->ttr;
    }

    public function purgeQueue(<QueueInterface> queue) -> void
    {
        var connection, tube, job;

        let tube       = queue->getQueueName(),
            connection = this->newConnection();

        connection->watchTube(tube);

        if tube != "default" {
            connection->ignoreTube("default");
        }

        loop {
            let job = connection->reserve(0);

            if job === null {
                break;
            }

            connection->deleteJob(job[0]);
        }

        connection->disconnect();
    }

    /**
     * Puts a serialized payload on a tube via the shared connection.
     * Internal transport API used by BeanstalkProducer.
     */
    public function putMessage(string tube, string payload, int priority, int delay, int ttr) -> void
    {
        var connection;

        let connection = this->getConnection();

        connection->useTube(tube);
        connection->put(payload, priority, delay, ttr);
    }

    /**
     * Returns the shared producer/purge connection, connecting on first use.
     */
    private function getConnection() -> <BeanstalkConnection>
    {
        if this->connection === null {
            let this->connection = this->newConnection();
        }

        return this->connection;
    }

    /**
     * Builds and connects a fresh Beanstalkd connection.
     */
    private function newConnection() -> <BeanstalkConnection>
    {
        var connection;

        let connection = new BeanstalkConnection(this->host, this->port, this->persistent);

        connection->connect();

        return connection;
    }
}
