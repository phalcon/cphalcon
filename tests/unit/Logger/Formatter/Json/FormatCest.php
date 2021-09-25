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
use Phalcon\Logger;
use Phalcon\Logger\Formatter\Json;
use Phalcon\Logger\Item;
use UnitTester;

use function sprintf;

class FormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Json :: format()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - format()');

        $formatter = new Json();
        $time      = new DateTimeImmutable("now");
        $item      = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = sprintf(
            '{"level":"debug","message":"log message","timestamp":"%s"}',
            $time->format('c')
        );

        $actual = $formatter->format($item);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\Formatter\Json :: format() -custom
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonFormatCustom(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - format() - custom');

        $formatter = new Json('YmdHis');
        $time      = new DateTimeImmutable("now");
        $item      = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = sprintf(
            '{"level":"debug","message":"log message","timestamp":"%s"}',
            $time->format('YmdHis')
        );

        $actual = $formatter->format($item);

        $I->assertEquals($expected, $actual);
    }
}
