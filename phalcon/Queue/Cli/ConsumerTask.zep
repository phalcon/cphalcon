
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

namespace Phalcon\Queue\Cli;

use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Task;
use Phalcon\Config\Config;
use Phalcon\Config\ConfigInterface;
use Phalcon\Contracts\Queue\Processor as ProcessorInterface;
use Phalcon\Di\DiInterface;
use Phalcon\Queue\Consumer\QueueConsumer;
use Phalcon\Queue\Consumer\Worker;
use Phalcon\Queue\Consumer\WorkerOptions;
use Phalcon\Queue\QueueFactory;

/**
 * Optional CLI runner for a queue worker - the only class coupled to
 * Phalcon\Cli. A thin adapter: it resolves the context from the `queueFactory`
 * service, binds one queue to one processor (both given as command arguments),
 * and runs a Worker whose lifetime bounds come from CLI options. Users not on
 * Phalcon\Cli use Worker directly.
 *
 * Usage:
 *     <task> <queueName> <processorServiceId> \
 *         [--max-messages=N] [--max-time=SECONDS] \
 *         [--max-memory=MB] [--jitter=SECONDS]
 *
 * Register it in your own Phalcon\Cli\Console; it is not auto-wired into
 * FactoryDefault.
 */
class ConsumerTask extends Task
{
    public function mainAction() -> int
    {
        var config, context, consumer, di, dispatcher,
            queueConfig, queueName, queueFactory, options,
            params, processor, processorService;

        /** @var DiInterface $di */
        let di = this->getDI();

        /** @var Dispatcher $dispatcher */
        let dispatcher = di->get("dispatcher");
        /** @var QueueFactory $queueFactory */
        let queueFactory = di->get("queueFactory");
        /** @var Config $config */
        let config = di->get("config");

        let params    = dispatcher->getParams();
        let queueName = this->stringParam(params, 0);
        let processor = this->stringParam(params, 1);

        /** @var array<string, mixed>|ConfigInterface $queueConfig */
        let queueConfig = config->get("queue");

        let context  = $queueFactory->load(queueConfig);
        let consumer = new QueueConsumer(context);

        /** @var ProcessorInterface $processorService */
        let processorService = di->get(processor);

        consumer->bind(
            context->createQueue(queueName),
            processorService
        );

        let options = new WorkerOptions(
            this->intOption(dispatcher, "max-messages"),
            this->intOption(dispatcher, "max-time"),
            this->intOption(dispatcher, "max-memory"),
            this->intOption(dispatcher, "jitter")
        );

        (new Worker(consumer, options))->run();

        return 0;
    }

    /**
     * Reads a CLI option as an int, defaulting to 0 when it is absent or
     * cannot be expressed as a number.
     */
    private function intOption(<Dispatcher> dispatcher, string name) -> int
    {
        var value;

        let value = dispatcher->getOption(name, null, 0);

        return is_scalar(value) ? (int) value : 0;
    }

    /**
     * Reads a positional CLI argument as a string, defaulting to an empty
     * string when it is absent or cannot be expressed as one.
     *
     * @param array<int|string, mixed> $params
     */
    private function stringParam(array params, int index) -> string
    {
        var value;

        let value = isset(params[index]) ? params[index] : "";

        return is_scalar(value) ? (string) value : "";
    }
}
