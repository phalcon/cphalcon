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

namespace Phalcon\Test\Unit\Logger\Formatter\Json;

use Phalcon\Logger;
use Phalcon\Logger\Formatter\Json;
use Phalcon\Logger\Item;
use UnitTester;

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

        $time = time();

        $item = new Item(
            'log message',
            'debug',
            Logger::DEBUG,
            $time
        );

        $expected = sprintf(
            '{"type":"debug","message":"log message","timestamp":"%s"}',
            date('D, d M y H:i:s O', $time)
        );

        $I->assertEquals(
            $expected,
            $formatter->format($item)
        );
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

        $time = time();

        $item = new Item(
            'log message',
            'debug',
            Logger::DEBUG,
            $time
        );

        $expected = sprintf(
            '{"type":"debug","message":"log message","timestamp":"%s"}',
            date('YmdHis', $time)
        );

        $I->assertEquals(
            $expected,
            $formatter->format($item)
        );
    }
}
