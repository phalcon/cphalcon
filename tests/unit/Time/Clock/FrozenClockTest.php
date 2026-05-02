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

namespace Phalcon\Tests\Unit\Time\Clock;

use DateTimeImmutable;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Time\Clock\Exception;
use Phalcon\Time\Clock\FrozenClock;

use function date_default_timezone_get;

final class FrozenClockTest extends AbstractUnitTestCase
{
    public function testAdjust(): void
    {
        $oldNow = new DateTimeImmutable();
        $newNow = $oldNow->modify('+1 hour');

        $clock = new FrozenClock($oldNow);

        $clock->adjust('+1 hour');

        $this->assertNotEquals($oldNow, $clock->now());
        $this->assertEquals($newNow, $clock->now());

        $clock->adjust('-1 hour');

        $this->assertEquals($oldNow, $clock->now());
        $this->assertNotEquals($newNow, $clock->now());
    }

    public function testAdjustException(): void
    {
        $this->expectExceptionMessage('Invalid modifier: "invalid"');
        $this->expectException(Exception::class);

        $clock = FrozenClock::fromUTC();
        $clock->adjust('invalid');
    }

    public function testFromSystemTimezoneNewInstanceWithSystemTimezone(): void
    {
        $clock = FrozenClock::fromSystemTimezone();
        $now   = $clock->now();

        $this->assertSame(date_default_timezone_get(), $now->getTimezone()->getName());
    }

    public function testFromUTCNewInstanceWithUTC(): void
    {
        $clock = FrozenClock::fromUTC();
        $now   = $clock->now();

        $this->assertSame('UTC', $now->getTimezone()->getName());
    }

    public function testNowReturnsSameObject(): void
    {
        $now   = new DateTimeImmutable();
        $clock = new FrozenClock($now);

        $this->assertSame($now, $clock->now());
        $this->assertSame($now, $clock->now());
    }

    public function testSet(): void
    {
        $oldNow = new DateTimeImmutable();
        $clock  = new FrozenClock($oldNow);

        $newNow = new DateTimeImmutable();
        $clock->set($newNow);

        $this->assertNotSame($oldNow, $clock->now());
        $this->assertSame($newNow, $clock->now());
    }
}
