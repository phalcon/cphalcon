
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Consumer;

/**
 * Long-running operational shell around a QueueConsumer. Owns the outer loop,
 * the bounded lifetime (max messages / seconds / memory, plus jitter) and -
 * when ext-pcntl is available - graceful shutdown on SIGTERM/SIGINT/SIGQUIT.
 * The current message always finishes before the loop stops (drain, not
 * guillotine), because the stop flag is only checked between iterations.
 */
class Worker
{
    /**
     * @var QueueConsumer
     */
    protected consumer;

    /**
     * @var WorkerOptions
     */
    protected options;

    public function __construct(<QueueConsumer> consumer, <WorkerOptions> options = null)
    {
        if options === null {
            let options = new WorkerOptions();
        }

        let this->consumer = consumer,
            this->options  = options;
    }

    /**
     * Signal handler: requests a graceful stop.
     */
    public function handleSignal(int signal) -> void
    {
        this->consumer->stop();
    }

    /**
     * Runs the worker until a lifetime bound trips or a stop is requested.
     * Returns the number of messages processed.
     */
    public function run() -> int
    {
        var options;
        int deadline, jitter, maxMemory, maxMessages, maxSeconds, processed;

        let options     = this->options,
            processed   = 0,
            maxMessages = (int) options->getMaxMessages(),
            maxSeconds  = (int) options->getMaxSeconds(),
            maxMemory   = (int) options->getMaxMemory(),
            jitter      = (int) options->getJitter();

        if !this->consumer->start() {
            return 0;
        }

        let deadline = 0;

        if maxSeconds > 0 {
            let deadline = time() + maxSeconds;

            if jitter > 0 {
                let deadline = deadline + random_int(0, jitter);
            }
        }

        this->installSignalHandlers();

        loop {
            if this->consumer->isStopRequested() {
                break;
            }

            if this->consumer->consumeOnce() {
                let processed++;

                if maxMessages > 0 && processed >= maxMessages {
                    break;
                }
            }

            if deadline > 0 && time() >= deadline {
                break;
            }

            if maxMemory > 0 && memory_get_usage(true) >= maxMemory * 1048576 {
                break;
            }
        }

        this->consumer->end();

        return processed;
    }

    /**
     * Installs graceful-shutdown signal handlers when ext-pcntl is available;
     * a no-op otherwise (the lifetime bounds still apply).
     */
    private function installSignalHandlers() -> void
    {
        if !function_exists("pcntl_async_signals") {
            return;
        }

        pcntl_async_signals(true);
        pcntl_signal(SIGTERM, [this, "handleSignal"]);
        pcntl_signal(SIGINT, [this, "handleSignal"]);
        pcntl_signal(SIGQUIT, [this, "handleSignal"]);
    }
}
