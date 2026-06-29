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
use Phalcon\Contracts\Queue\Inspectable;
use Phalcon\Queue\Adapter\Beanstalk\BeanstalkConnectionFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Throwable;

use function getOptionsBeanstalk;
use function random_int;
use function uniqid;

/**
 * Beanstalkd queue introspection through the Inspectable contract: getStats()
 * reports per-tube backlog counts, returns the zeroed backlog keys for an
 * unknown tube, reads on a fresh connection that does not disturb the producer,
 * and keeps a numeric tube name as a string.
 */
final class BeanstalkStatsTest extends AbstractUnitTestCase
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

    public function testContextIsInspectable(): void
    {
        $this->assertInstanceOf(Inspectable::class, $this->createContext());
    }

    public function testGetStatsReportsReadyBacklog(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $producer = $context->createProducer();

        $producer->send($queue, $context->createMessage('one'));
        $producer->send($queue, $context->createMessage('two'));
        $producer->send($queue, $context->createMessage('three'));

        $stats = $context->getStats($queue);

        $this->assertIsInt($stats['current-jobs-ready']);
        $this->assertSame(3, $stats['current-jobs-ready']);
        $this->assertSame($this->tube, $stats['name']);
    }

    public function testGetStatsForUnknownTubeReturnsZeroedBacklog(): void
    {
        $context = $this->createContext();
        $unknown = $context->createQueue('phalcon_absent_' . uniqid('', true));

        $stats = $context->getStats($unknown);

        $this->assertSame(0, $stats['current-jobs-urgent']);
        $this->assertSame(0, $stats['current-jobs-ready']);
        $this->assertSame(0, $stats['current-jobs-reserved']);
        $this->assertSame(0, $stats['current-jobs-delayed']);
        $this->assertSame(0, $stats['current-jobs-buried']);
    }

    public function testGetStatsLeavesProducerUsable(): void
    {
        $context  = $this->createContext();
        $queue    = $context->createQueue($this->tube);
        $producer = $context->createProducer();

        $producer->send($queue, $context->createMessage('before'));

        // A stats read runs on its own connection and must not disturb the
        // shared producer connection.
        $context->getStats($queue);

        $producer->send($queue, $context->createMessage('after'));

        $consumer = $context->createConsumer($queue);

        $first = $consumer->receiveNoWait();
        $this->assertNotNull($first);
        $this->assertSame('before', $first->getBody());
        $consumer->acknowledge($first);

        $second = $consumer->receiveNoWait();
        $this->assertNotNull($second);
        $this->assertSame('after', $second->getBody());
        $consumer->acknowledge($second);
    }

    public function testGetStatsKeepsNumericTubeNameAsString(): void
    {
        $context = $this->createContext();
        $name    = (string) random_int(100000, 999999);
        $queue   = $context->createQueue($name);

        try {
            $context->createProducer()->send($queue, $context->createMessage('x'));

            $stats = $context->getStats($queue);

            $this->assertIsString($stats['name']);
            $this->assertSame($name, $stats['name']);
            $this->assertIsInt($stats['current-jobs-ready']);
            $this->assertSame(1, $stats['current-jobs-ready']);
        } finally {
            $context->purgeQueue($queue);
        }
    }

    private function createContext(): ContextInterface
    {
        return (new BeanstalkConnectionFactory($this->options))
            ->createContext();
    }
}
