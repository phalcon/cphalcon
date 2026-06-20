
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Consumer;

use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Contracts\Queue\Processor as ProcessorInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Events\AbstractEventsAware;
use Phalcon\Events\EventsAwareInterface;

/**
 * Lean consumption runner. Binds processors to queues, polls each bound queue
 * round-robin, and dispatches messages to their processors while firing the
 * lifecycle events on `Phalcon\Queue\Consumer\Events` through the events
 * manager. The long-running operational shell (lifetime, signals) lives in
 * `Phalcon\Queue\Consumer\Worker`, which drives `consumeOnce()` and shares the
 * stop signal through `stop()` / `isStopRequested()`.
 */
class QueueConsumer extends AbstractEventsAware implements EventsAwareInterface
{
    /**
     * Bound processors keyed by queue name.
     *
     * @var array
     */
    protected bindings = [];

    /**
     * @var ContextInterface
     */
    protected context;

    /**
     * Milliseconds slept between poll passes when nothing was received.
     *
     * @var int
     */
    protected pollInterval = 200;

    /**
     * @var bool
     */
    protected shouldStop = false;

    public function __construct(<ContextInterface> context)
    {
        let this->context = context;
    }

    /**
     * Binds a processor to a queue. Returns self for chaining.
     */
    public function bind(<QueueInterface> queue, <ProcessorInterface> processor) -> <QueueConsumer>
    {
        let this->bindings[queue->getQueueName()] = new BoundProcessor(
            queue,
            processor,
            this->context->createConsumer(queue)
        );

        return this;
    }

    /**
     * Runs the consumption loop, blocking up to timeout milliseconds (0 =
     * block until stopped). The simple loop; production setups use Worker.
     */
    public function consume(int timeout = 0) -> void
    {
        int startTime;

        if !this->start() {
            return;
        }

        let startTime = (int) (microtime(true) * 1000);

        loop {
            this->consumeOnce();

            if this->shouldStop {
                break;
            }

            if timeout > 0 && (((int) (microtime(true) * 1000)) - startTime) >= timeout {
                break;
            }
        }

        this->end();
    }

    /**
     * Polls every bound queue once, processing up to one message from each.
     * Returns true if any message was handled. Sleeps the poll interval when
     * nothing was received so callers can loop tightly.
     */
    public function consumeOnce() -> bool
    {
        var binding, consumer, message;
        bool handled;

        let handled = false;

        for binding in this->bindings {
            if this->fireManagerEvent(Events::BEFORE_RECEIVE, binding) === false {
                continue;
            }

            let consumer = binding->getConsumer(),
                message  = consumer->receiveNoWait();

            if this->fireManagerEvent(Events::AFTER_RECEIVE, message) === false {
                let this->shouldStop = true;

                return handled;
            }

            if message !== null {
                this->process(binding, message);

                let handled = true;
            }
        }

        if !handled {
            usleep(this->pollInterval * 1000);
        }

        return handled;
    }

    /**
     * Fires the `queue:afterEnd` event. Called once the loop exits.
     */
    public function end() -> void
    {
        this->fireManagerEvent(Events::AFTER_END, null, false);
    }

    /**
     * Whether a stop has been requested (by a signal, `stop()`, or an
     * `afterReceive` listener returning false).
     */
    public function isStopRequested() -> bool
    {
        return this->shouldStop;
    }

    /**
     * Sets the poll interval (in milliseconds).
     */
    public function setPollInterval(int pollInterval) -> void
    {
        let this->pollInterval = pollInterval;
    }

    /**
     * Resets the stop flag and fires `queue:beforeStart`. Returns false when a
     * listener cancels the start.
     */
    public function start() -> bool
    {
        let this->shouldStop = false;

        return this->fireManagerEvent(Events::BEFORE_START) !== false;
    }

    /**
     * Requests the consumption loop to stop after the current message.
     */
    public function stop() -> void
    {
        let this->shouldStop = true;
    }

    /**
     * Applies a processor result (ACK / REJECT / REQUEUE) to the message.
     */
    private function handleResult(var consumer, <MessageInterface> message, var result) -> void
    {
        string outcome;

        let outcome = (string) result;

        if outcome === ProcessorInterface::ACK {
            consumer->acknowledge(message);
        } elseif outcome === ProcessorInterface::REQUEUE {
            consumer->reject(message, true);
        } else {
            consumer->reject(message, false);
        }
    }

    /**
     * Runs the processor for one message, firing the process events and
     * applying the outcome. A processor exception fires
     * `queue:processorException` and rejects the message.
     */
    private function process(var binding, <MessageInterface> message) -> void
    {
        var consumer, processor, result, exception;

        let consumer  = binding->getConsumer(),
            processor = binding->getProcessor();

        if this->fireManagerEvent(Events::BEFORE_PROCESS, message) === false {
            return;
        }

        try {
            let result = processor->process(message, this->context);

            this->handleResult(consumer, message, result);

            this->fireManagerEvent(Events::AFTER_PROCESS, message, false);
        } catch \Throwable, exception {
            this->fireManagerEvent(Events::PROCESSOR_EXCEPTION, exception, false);

            consumer->reject(message, false);
        }
    }
}
