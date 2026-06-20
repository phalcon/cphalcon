
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Cli;

use Phalcon\Cli\Task;
use Phalcon\Queue\Consumer\QueueConsumer;
use Phalcon\Queue\Consumer\Worker;
use Phalcon\Queue\Consumer\WorkerOptions;

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
        var consumer, context, di, dispatcher, options, params, processor,
            queueName, worker;

        let di         = this->getDI(),
            dispatcher = di->get("dispatcher"),
            params     = dispatcher->getParams();

        let queueName = isset params[0] ? params[0] : "",
            processor = isset params[1] ? params[1] : "";

        let context = di->get("queueFactory")->load(
            di->get("config")->queue
        );

        let consumer = new QueueConsumer(context);

        consumer->bind(
            context->createQueue(queueName),
            di->get(processor)
        );

        let options = new WorkerOptions(
            (int) dispatcher->getOption("max-messages", null, 0),
            (int) dispatcher->getOption("max-time", null, 0),
            (int) dispatcher->getOption("max-memory", null, 0),
            (int) dispatcher->getOption("jitter", null, 0)
        );

        let worker = new Worker(consumer, options);

        worker->run();

        return 0;
    }
}
