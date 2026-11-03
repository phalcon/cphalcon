<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Queue\Consumer;

use Phalcon\Contracts\Queue\Context;
use Phalcon\Contracts\Queue\Message;
use Phalcon\Contracts\Queue\Processor;
use Phalcon\Events\Manager;
use Phalcon\Queue\Adapter\Memory\MemoryConnectionFactory;
use Phalcon\Queue\Consumer\QueueConsumer;
use Phalcon\Queue\Consumer\Worker;
use Phalcon\Queue\Consumer\WorkerOptions;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\RequiresPhpExtension;

use function extension_loaded;
use function pcntl_async_signals;
use function pcntl_signal;
use function posix_getpid;
use function posix_kill;

final class WorkerTest extends AbstractUnitTestCase
{
    /**
     * The worker changes the signal state of the process. Restore it.
     */
    protected function tearDown(): void
    {
        if (extension_loaded('pcntl')) {
            pcntl_async_signals(false);
            pcntl_signal(SIGINT, SIG_DFL);
            pcntl_signal(SIGQUIT, SIG_DFL);
            pcntl_signal(SIGTERM, SIG_DFL);
        }
    }

    /**
     * @return array<string, array{0: int}>
     */
    public static function providerSignals(): array
    {
        return [
            'SIGINT'  => [2],
            'SIGQUIT' => [3],
            'SIGTERM' => [15],
        ];
    }

    /**
     * PHP sends null as the second argument on platforms with no signal
     * information.
     */
    public function testHandleSignalStopsConsumerWithNullSignalInfo(): void
    {
        $consumer = new QueueConsumer((new MemoryConnectionFactory())->createContext());

        (new Worker($consumer))->handleSignal(15, null);

        $this->assertTrue($consumer->isStopRequested());
    }

    /**
     * PHP sends an array as the second argument on platforms with signal
     * information.
     */
    public function testHandleSignalStopsConsumerWithSignalInfo(): void
    {
        $consumer = new QueueConsumer((new MemoryConnectionFactory())->createContext());

        (new Worker($consumer))->handleSignal(15, ['signo' => 15, 'errno' => 0, 'code' => 0]);

        $this->assertTrue($consumer->isStopRequested());
    }

    /**
     * Calls from subclasses that have only the signal number must continue
     * to operate.
     */
    public function testHandleSignalStopsConsumerWithSignalOnly(): void
    {
        $consumer = new QueueConsumer((new MemoryConnectionFactory())->createContext());

        (new Worker($consumer))->handleSignal(15);

        $this->assertTrue($consumer->isStopRequested());
    }

    /**
     * A signal during a job must not stop the job. The job finishes, and the
     * worker leaves the next message in the queue.
     */
    #[RequiresPhpExtension('pcntl')]
    #[RequiresPhpExtension('posix')]
    public function testRunFinishesCurrentMessageOnSignal(): void
    {
        $context  = (new MemoryConnectionFactory())->createContext();
        $queue    = $context->createQueue('jobs');
        $producer = $context->createProducer();

        $producer->send($queue, $context->createMessage('first'));
        $producer->send($queue, $context->createMessage('second'));

        $processor = new class () implements Processor {
            public array $seen = [];

            public function process(Message $message, Context $context): object | string
            {
                posix_kill(posix_getpid(), SIGTERM);

                $this->seen[] = $message->getBody();

                return Processor::ACK;
            }
        };

        $consumer = new QueueConsumer($context);
        $consumer->bind($queue, $processor);

        $processed = (new Worker($consumer, new WorkerOptions(maxSeconds: 2)))->run();

        $this->assertSame(1, $processed);
        $this->assertSame(['first'], $processor->seen);
        $this->assertTrue($consumer->isStopRequested());
        $this->assertSame('second', $context->createConsumer($queue)->receiveNoWait()->getBody());
    }

    /**
     * A signal with no job in progress must stop the worker with no error.
     * The poll event sends the signal, thus the test does not use a timer.
     */
    #[DataProvider('providerSignals')]
    #[RequiresPhpExtension('pcntl')]
    #[RequiresPhpExtension('posix')]
    public function testRunStopsOnSignalWhenIdle(int $signal): void
    {
        $context = (new MemoryConnectionFactory())->createContext();
        $queue   = $context->createQueue('jobs');

        $processor = new class () implements Processor {
            public function process(Message $message, Context $context): object | string
            {
                return Processor::ACK;
            }
        };

        $manager = new Manager();
        $manager->attach(
            'queue:beforeReceive',
            function () use ($signal) {
                posix_kill(posix_getpid(), $signal);
            }
        );

        $consumer = new QueueConsumer($context);
        $consumer->setEventsManager($manager);
        $consumer->bind($queue, $processor);

        $processed = (new Worker($consumer, new WorkerOptions(maxSeconds: 2)))->run();

        $this->assertSame(0, $processed);
        $this->assertTrue($consumer->isStopRequested());
    }
}
