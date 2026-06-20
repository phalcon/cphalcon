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

namespace Phalcon\Tests\Unit\Queue;

use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Cross-adapter conformance suite. Every adapter that ships a Context must
 * pass these contract tests; concrete subclasses only supply `createContext()`.
 */
abstract class AbstractContextConformanceTestCase extends AbstractUnitTestCase
{
    /**
     * Returns a fresh Context for the adapter under test.
     */
    abstract protected function createContext(): ContextInterface;

    public function testMessagesAreDeliveredInFifoOrder(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue('fifo');
        $producer = $context->createProducer();

        $producer->send($queue, $context->createMessage('one'));
        $producer->send($queue, $context->createMessage('two'));
        $producer->send($queue, $context->createMessage('three'));

        $consumer = $context->createConsumer($queue);

        $this->assertSame('one', $consumer->receiveNoWait()->getBody());
        $this->assertSame('two', $consumer->receiveNoWait()->getBody());
        $this->assertSame('three', $consumer->receiveNoWait()->getBody());
        $this->assertNull($consumer->receiveNoWait());
    }

    public function testPropertiesAndHeadersRoundTrip(): void
    {
        $context = $this->createContext();
        $message = $context->createMessage(
            'body',
            ['attempt' => 3],
            ['x-trace' => 'abc']
        );

        $this->assertSame('body', $message->getBody());
        $this->assertSame(3, $message->getProperty('attempt'));
        $this->assertSame('abc', $message->getHeader('x-trace'));
        $this->assertSame('fallback', $message->getProperty('missing', 'fallback'));
        $this->assertNull($message->getHeader('missing'));
    }

    public function testPurgeQueueRemovesMessages(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue('purge');

        $context->createProducer()->send($queue, $context->createMessage('gone'));
        $context->purgeQueue($queue);

        $this->assertNull($context->createConsumer($queue)->receiveNoWait());
    }

    public function testReceiveNoWaitReturnsNullWhenEmpty(): void
    {
        $context  = $this->createContext();
        $consumer = $context->createConsumer($context->createQueue('empty'));

        $this->assertNull($consumer->receiveNoWait());
    }

    public function testRejectWithRequeuePutsMessageBack(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue('requeue');

        $context->createProducer()->send($queue, $context->createMessage('again'));

        $consumer = $context->createConsumer($queue);
        $message  = $consumer->receiveNoWait();

        $this->assertNotNull($message);

        $consumer->reject($message, true);

        $this->assertSame('again', $consumer->receiveNoWait()->getBody());
    }

    public function testSendThenReceiveReturnsTheMessage(): void
    {
        $context = $this->createContext();
        $queue   = $context->createQueue('basic');

        $context->createProducer()->send($queue, $context->createMessage('payload'));

        $message = $context->createConsumer($queue)->receiveNoWait();

        $this->assertNotNull($message);
        $this->assertSame('payload', $message->getBody());
    }
}
