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

namespace Phalcon\Tests\Unit\Queue\Adapter\Memory;

use Phalcon\Contracts\Queue\Producer as ProducerInterface;
use Phalcon\Queue\Adapter\Memory\MemoryConnectionFactory;
use Phalcon\Queue\Exceptions\DeliveryDelayNotSupportedException;
use Phalcon\Queue\Exceptions\PriorityNotSupportedException;
use Phalcon\Queue\Exceptions\TimeToLiveNotSupportedException;
use Phalcon\Tests\AbstractUnitTestCase;

final class MemoryProducerNotSupportedTest extends AbstractUnitTestCase
{
    public function testNullValuesAreAcceptedAndGettersReturnNull(): void
    {
        $producer = $this->createProducer();

        $this->assertSame($producer, $producer->setDeliveryDelay(null));
        $this->assertSame($producer, $producer->setPriority(null));
        $this->assertSame($producer, $producer->setTimeToLive(null));

        $this->assertNull($producer->getDeliveryDelay());
        $this->assertNull($producer->getPriority());
        $this->assertNull($producer->getTimeToLive());
    }

    public function testSetDeliveryDelayThrows(): void
    {
        $this->expectException(DeliveryDelayNotSupportedException::class);

        $this->createProducer()->setDeliveryDelay(1000);
    }

    public function testSetPriorityThrows(): void
    {
        $this->expectException(PriorityNotSupportedException::class);

        $this->createProducer()->setPriority(5);
    }

    public function testSetTimeToLiveThrows(): void
    {
        $this->expectException(TimeToLiveNotSupportedException::class);

        $this->createProducer()->setTimeToLive(1000);
    }

    private function createProducer(): ProducerInterface
    {
        return (new MemoryConnectionFactory())
            ->createContext()
            ->createProducer();
    }
}
