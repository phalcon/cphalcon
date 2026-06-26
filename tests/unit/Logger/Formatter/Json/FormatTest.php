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

namespace Phalcon\Tests\Unit\Logger\Formatter\Json;

use DateTimeImmutable;
use DateTimeZone;
use Exception;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Formatter\Json;
use Phalcon\Logger\Item;
use Phalcon\Tests\AbstractUnitTestCase;

use function date_default_timezone_get;

final class FormatTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterJsonFormat(): void
    {
        $formatter = new Json();

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item     = new Item(
            'log message',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $expected = sprintf(
            '{"level":"debug","message":"log message","timestamp":"%s"}',
            $datetime->format('c')
        );

        $this->assertSame(
            $expected,
            $formatter->format($item)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterJsonFormatCustom(): void
    {
        $formatter = new Json('YmdHis');

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item     = new Item(
            'log message',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $expected = sprintf(
            '{"level":"debug","message":"log message","timestamp":"%s"}',
            $datetime->format('YmdHis')
        );

        $this->assertSame(
            $expected,
            $formatter->format($item)
        );
    }
}
