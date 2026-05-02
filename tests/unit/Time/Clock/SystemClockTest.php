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
use DateTimeZone;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Time\Clock\SystemClock;

use function date_default_timezone_get;

final class SystemClockTest extends AbstractUnitTestCase
{
    public function testFromSystemTimezoneNewInstanceWithSystemTimezone(): void
    {
        $clock = SystemClock::fromSystemTimezone();
        $now   = $clock->now();

        $this->assertSame(date_default_timezone_get(), $now->getTimezone()->getName());
    }

    public function testFromUTCNewInstanceWithUTC(): void
    {
        $clock = SystemClock::fromUTC();
        $now   = $clock->now();

        $this->assertSame('UTC', $now->getTimezone()->getName());
    }

    public function testNowKeepsProvidedTimezone(): void
    {
        $timezone = new DateTimeZone('Europe/Paris');
        $clock    = new SystemClock($timezone);

        $lower = new DateTimeImmutable('now', $timezone);
        $now   = $clock->now();
        $upper = new DateTimeImmutable('now', $timezone);

        $this->assertEquals($timezone, $now->getTimezone());
        $this->assertGreaterThanOrEqual($lower, $now);
        $this->assertLessThanOrEqual($upper, $now);
    }
}