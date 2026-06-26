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

namespace Phalcon\Tests\Unit\Queue\Adapter\Redis;

use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Queue\Adapter\Redis\RedisConnectionFactory;
use Phalcon\Queue\Exceptions\PriorityNotSupportedException;
use Phalcon\Queue\Exceptions\TimeToLiveNotSupportedException;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

use function array_merge;
use function extension_loaded;
use function getOptionsRedis;
use function uniqid;
use function usleep;

final class RedisDelayedTest extends AbstractUnitTestCase
{
    private array $options = [];

    protected function setUp(): void
    {
        parent::setUp();

        if (!extension_loaded('redis')) {
            $this->markTestSkipped('The redis extension is not loaded');
        }

        $this->options = array_merge(
            getOptionsRedis(),
            ['prefix' => 'phalcon_queue_test_' . uniqid('', true) . ':']
        );

        try {
            $this->createContext();
        } catch (Throwable $exception) {
            $this->markTestSkipped('Redis server is not available: ' . $exception->getMessage());
        }
    }

    public function testDelayedMessageIsReleasedOnlyWhenDue(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue('delayed');
        $consumer = $context->createConsumer($queue);

        $context->createProducer()
            ->setDeliveryDelay(300)
            ->send($queue, $context->createMessage('later'));

        // Still parked in the delayed set.
        $this->assertNull($consumer->receiveNoWait());

        // Wait past the delay; the message must now be promoted to the list.
        usleep(450000);

        $message = $consumer->receiveNoWait();

        $this->assertNotNull($message);
        $this->assertSame('later', $message->getBody());
    }

    public function testDeliveryDelayIsAcceptedAndReported(): void
    {
        $producer = $this->createContext()->createProducer();

        $this->assertSame($producer, $producer->setDeliveryDelay(500));
        $this->assertSame(500, $producer->getDeliveryDelay());
    }

    public function testSetPriorityThrows(): void
    {
        $this->expectException(PriorityNotSupportedException::class);

        $this->createContext()->createProducer()->setPriority(5);
    }

    public function testSetTimeToLiveThrows(): void
    {
        $this->expectException(TimeToLiveNotSupportedException::class);

        $this->createContext()->createProducer()->setTimeToLive(1000);
    }

    private function createContext(): ContextInterface
    {
        return (new RedisConnectionFactory($this->options))
            ->createContext();
    }
}
