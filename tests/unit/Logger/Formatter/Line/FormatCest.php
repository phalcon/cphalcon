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
use Phalcon\Logger\Enum;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Item;
use UnitTester;

use function date_default_timezone_get;
use function uniqid;

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
            Enum::DEBUG,
            $datetime
        );

        $expected = sprintf(
            '[%s][debug] log message',
            $datetime->format('c')
        );
        $actual   = $formatter->format($item);
        $I->assertSame($expected, $actual);
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
            Enum::DEBUG,
            $datetime
        );

        $expected = sprintf(
            'log message-[debug]-%s',
            $datetime->format('c')
        );
        $actual   = $formatter->format($item);
        $I->assertSame($expected, $actual);
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
            Enum::DEBUG,
            $datetime
        );

        $result = $formatter->format($item);
        $parts  = explode('-', $result);
        $parts  = explode('.', $parts[2]);

        $expected = 2;
        $actual   = $parts;
        $I->assertCount($expected, $actual);

        $expected = 0;
        $actual   = (int)$parts[0];
        $I->assertGreaterThan($expected, $actual);

        $expected = 0;
        $actual   = (int)$parts[1];
        $I->assertGreaterThan($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\Formatter\Line :: format() - custom interpolator
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2022-09-11
     * @author Phalcon Team <team@phalcon.io>
     */
    public function loggerFormatterLineFormatCustomInterpolator(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - format() - custom - interpolator');

        $formatter = new Line(
            '%message%-[%level%]-%date%-%server%:%user%',
            'U.u'
        );

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $context  = [
            'server' => uniqid('srv-'),
            'user'   => uniqid('usr-'),
        ];
        $item     = new Item(
            'log message',
            'debug',
            Enum::DEBUG,
            $datetime,
            $context
        );

        $expected = sprintf(
            'log message-[debug]-%s-%s:%s',
            $datetime->format('U.u'),
            $context['server'],
            $context['user']
        );
        $actual   = $formatter->format($item);
        $I->assertSame($expected, $actual);
    }
}
