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

namespace Phalcon\Tests\Unit\Logger\Formatter\Line;

use DateTimeImmutable;
use DateTimeZone;
use Exception;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

use function date_default_timezone_get;

class FormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: format()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2020-09-09
     * @author Phalcon Team <team@phalcon.io>
     */
    public function loggerFormatterLineFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - format()');

        $timezone  = date_default_timezone_get();
        $datetime  = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $formatter = new Line();
        $item      = new Item(
            'log message',
            'debug',
            Logger::DEBUG,
            $datetime
        );

        $expected = sprintf(
            '[%s][debug] log message',
            $datetime->format('c')
        );

        $I->assertEquals(
            $expected,
            $formatter->format($item)
        );
    }

    /**
     * Tests Phalcon\Logger\Formatter\Line :: format() -custom
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2020-09-09
     * @author Phalcon Team <team@phalcon.io>
     */
    public function loggerFormatterLineFormatCustom(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - format() - custom');

        $formatter = new Line('%message%-[%level%]-%date%');
        $timezone  = date_default_timezone_get();
        $datetime  = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item      = new Item(
            'log message',
            'debug',
            Logger::DEBUG,
            $datetime
        );

        $expected = sprintf(
            'log message-[debug]-%s',
            $datetime->format('c')
        );

        $I->assertEquals(
            $expected,
            $formatter->format($item)
        );
    }

    /**
     * Tests Phalcon\Logger\Formatter\Line :: format() -custom with milliseconds
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2020-09-09
     * @author Phalcon Team <team@phalcon.io>
     */
    public function loggerFormatterLineFormatCustomWithMilliseconds(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - format() - custom - with milliseconds');

        $formatter = new Line(
            '%message%-[%level%]-%date%',
            'U.u'
        );

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item     = new Item(
            'log message',
            'debug',
            Logger::DEBUG,
            $datetime
        );

        $result = $formatter->format($item);
        $parts  = explode('-', $result);
        $parts  = explode('.', $parts[2]);
        $I->assertCount(2, $parts);
        $I->assertGreaterThan(0, (int) $parts[0]);
        $I->assertGreaterThan(0, (int) $parts[1]);
    }
}
