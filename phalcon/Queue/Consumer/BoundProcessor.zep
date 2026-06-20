
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Consumer;

use Phalcon\Contracts\Queue\Consumer as ConsumerInterface;
use Phalcon\Contracts\Queue\Processor as ProcessorInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;

/**
 * Binds a processor to a queue, together with the consumer that reads it.
 */
class BoundProcessor
{
    /**
     * @var ConsumerInterface
     */
    protected consumer;

    /**
     * @var ProcessorInterface
     */
    protected processor;

    /**
     * @var QueueInterface
     */
    protected queue;

    public function __construct(<QueueInterface> queue, <ProcessorInterface> processor, <ConsumerInterface> consumer)
    {
        let this->queue     = queue,
            this->processor = processor,
            this->consumer  = consumer;
    }

    public function getConsumer() -> <ConsumerInterface>
    {
        return this->consumer;
    }

    public function getProcessor() -> <ProcessorInterface>
    {
        return this->processor;
    }

    public function getQueue() -> <QueueInterface>
    {
        return this->queue;
    }
}
