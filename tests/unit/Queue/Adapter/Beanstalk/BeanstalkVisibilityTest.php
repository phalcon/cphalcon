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
use Phalcon\Contracts\Queue\VisibilityAware;
use Phalcon\Queue\Adapter\Beanstalk\BeanstalkConnectionFactory;
use Phalcon\Queue\Adapter\Beanstalk\BeanstalkConsumer;
use Phalcon\Queue\Exceptions\TimeToLiveNotSupportedException;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

use function getOptionsBeanstalk;
use function uniqid;
use function usleep;

/**
 * Beanstalkd-specific behavior: native delivery delay and priority, the
 * unsupported time to live, and the VisibilityAware `touch()` that extends a
 * reserved job's time-to-run window.
 */
final class BeanstalkVisibilityTest extends AbstractUnitTestCase
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

    public function testDelayedMessageIsReleasedOnlyWhenDue(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $consumer = $context->createConsumer($queue);

        $context->createProducer()
            ->setDeliveryDelay(1000)
            ->send($queue, $context->createMessage('later'));

        // Still delayed (Beanstalkd delay granularity is one second).
        $this->assertNull($consumer->receiveNoWait());

        usleep(1300000);

        $message = $consumer->receiveNoWait();

        $this->assertNotNull($message);
        $this->assertSame('later', $message->getBody());

        $consumer->acknowledge($message);
    }

    public function testDeliveryDelayAndPriorityAreReported(): void
    {
        $producer = $this->createContext()->createProducer();

        $this->assertSame($producer, $producer->setDeliveryDelay(2000));
        $this->assertSame(2000, $producer->getDeliveryDelay());

        $this->assertSame($producer, $producer->setPriority(5));
        $this->assertSame(5, $producer->getPriority());
    }

    public function testSetTimeToLiveThrows(): void
    {
        $this->expectException(TimeToLiveNotSupportedException::class);

        $this->createContext()->createProducer()->setTimeToLive(1000);
    }

    public function testTouchExtendsAReservedJob(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $consumer = $context->createConsumer($queue);

        $this->assertInstanceOf(VisibilityAware::class, $consumer);
        $this->assertInstanceOf(BeanstalkConsumer::class, $consumer);

        $context->createProducer()->send($queue, $context->createMessage('work'));

        $message = $consumer->receiveNoWait();

        $this->assertNotNull($message);
        $this->assertTrue($consumer->touch($message));

        $consumer->acknowledge($message);
    }

    private function createContext(): ContextInterface
    {
        return (new BeanstalkConnectionFactory($this->options))
            ->createContext();
    }
}
