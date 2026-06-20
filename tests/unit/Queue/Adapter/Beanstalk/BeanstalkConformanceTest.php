<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Queue\Adapter\Beanstalk;

use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Queue\Adapter\Beanstalk\BeanstalkConnectionFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

use function getOptionsBeanstalk;
use function uniqid;

/**
 * Contract checks for the Beanstalkd adapter. Each test uses a unique tube so
 * runs never interfere, and acknowledges what it consumes (a reserved job is
 * not removed until it is deleted, unlike the destructive-read adapters).
 */
final class BeanstalkConformanceTest extends AbstractUnitTestCase
{
    private array $options = [];
    private string $tube   = '';

    protected function setUp(): void
    {
        parent::setUp();

        $this->options = getOptionsBeanstalk();
        $this->tube    = 'phalcon_test_' . uniqid('', true);

        try {
            $context = $this->createContext();
            $context->createConsumer($context->createQueue($this->tube));
        } catch (Throwable $exception) {
            $this->markTestSkipped('Beanstalkd server is not available: ' . $exception->getMessage());
        }
    }

    protected function tearDown(): void
    {
        try {
            $context = $this->createContext();
            $context->purgeQueue($context->createQueue($this->tube));
        } catch (Throwable) {
            // Nothing to clean up when the server is unavailable.
        }

        parent::tearDown();
    }

    public function testAcknowledgeRemovesTheMessage(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $consumer = $context->createConsumer($queue);

        $context->createProducer()->send($queue, $context->createMessage('done'));

        $message = $consumer->receiveNoWait();

        $this->assertNotNull($message);

        $consumer->acknowledge($message);

        $this->assertNull($consumer->receiveNoWait());
    }

    public function testMessagesAreDeliveredInFifoOrder(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $producer = $context->createProducer();

        $producer->send($queue, $context->createMessage('one'));
        $producer->send($queue, $context->createMessage('two'));
        $producer->send($queue, $context->createMessage('three'));

        $consumer = $context->createConsumer($queue);

        foreach (['one', 'two', 'three'] as $expected) {
            $message = $consumer->receiveNoWait();

            $this->assertNotNull($message);
            $this->assertSame($expected, $message->getBody());

            $consumer->acknowledge($message);
        }

        $this->assertNull($consumer->receiveNoWait());
    }

    public function testReceiveNoWaitReturnsNullWhenEmpty(): void
    {
        $context  = $this->createContext();
        $consumer = $context->createConsumer($context->createQueue($this->tube));

        $this->assertNull($consumer->receiveNoWait());
    }

    public function testRejectWithoutRequeueBuriesTheMessage(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $consumer = $context->createConsumer($queue);

        $context->createProducer()->send($queue, $context->createMessage('bad'));

        $message = $consumer->receiveNoWait();

        $this->assertNotNull($message);

        $consumer->reject($message);

        $this->assertNull($consumer->receiveNoWait());
    }

    public function testRejectWithRequeuePutsMessageBack(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $consumer = $context->createConsumer($queue);

        $context->createProducer()->send($queue, $context->createMessage('again'));

        $message = $consumer->receiveNoWait();

        $this->assertNotNull($message);

        $consumer->reject($message, true);

        $requeued = $consumer->receiveNoWait();

        $this->assertNotNull($requeued);
        $this->assertSame('again', $requeued->getBody());

        $consumer->acknowledge($requeued);
    }

    public function testSendThenReceiveReturnsTheMessage(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $consumer = $context->createConsumer($queue);

        $context->createProducer()->send($queue, $context->createMessage('payload'));

        $message = $consumer->receiveNoWait();

        $this->assertNotNull($message);
        $this->assertSame('payload', $message->getBody());

        $consumer->acknowledge($message);
    }

    private function createContext(): ContextInterface
    {
        return (new BeanstalkConnectionFactory($this->options))
            ->createContext();
    }
}
