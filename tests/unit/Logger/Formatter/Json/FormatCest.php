<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Formatter\Json;

use Phalcon\Logger;
use Phalcon\Logger\Formatter\Json;
use Phalcon\Logger\Item;
use UnitTester;
use const PHP_EOL;

/**
 * Class FormatCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class FormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Json :: format()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - format()');
        $formatter = new Json();

        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = sprintf(
            '{"type":"debug","message":"log message","timestamp":"%s"}%s',
            date('D, d M y H:i:s O', $time),
            PHP_EOL
        );
        $actual   = $formatter->format($item);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\Formatter\Json :: format() -custom
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonFormatCustom(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - format() - custom');
        $formatter = new Json('YmdHis');

        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = sprintf(
            '{"type":"debug","message":"log message","timestamp":"%s"}%s',
            date('YmdHis', $time),
            PHP_EOL
        );
        $actual   = $formatter->format($item);
        $I->assertEquals($expected, $actual);
    }
}
