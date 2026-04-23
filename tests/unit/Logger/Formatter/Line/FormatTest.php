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
use Phalcon\Tests\AbstractUnitTestCase;

use function date_default_timezone_get;
use function uniqid;

final class FormatTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterLineFormat(): void
    {
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
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterLineFormatCustom(): void
    {
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
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-09-11
     */
    public function testLoggerFormatterLineFormatCustomInterpolator(): void
    {
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
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterLineFormatCustomWithMilliseconds(): void
    {
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
        $this->assertCount($expected, $actual);

        $expected = 0;
        $actual   = (int)$parts[0];
        $this->assertGreaterThan($expected, $actual);

        $expected = 0;
        $actual   = (int)$parts[1];
        $this->assertGreaterThan($expected, $actual);
    }
}
