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

namespace Phalcon\Test\Unit\Logger\Formatter\Line;

use Phalcon\Logger;
use Phalcon\Logger\Formatter\Line;
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
     * Tests Phalcon\Logger\Formatter\Line :: format()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterLineFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - format()');
        $formatter = new Line();

        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = sprintf('[%s][debug] log message', date('D, d M y H:i:s O', $time)) . PHP_EOL;
        $actual   = $formatter->format($item);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\Formatter\Line :: format() -custom
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterLineFormatCustom(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - format() - custom');
        $formatter = new Line('%message%-[%type%]-%date%');

        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = sprintf('log message-[debug]-%s', date('D, d M y H:i:s O', $time)) . PHP_EOL;
        $actual   = $formatter->format($item);
        $I->assertEquals($expected, $actual);
    }
}
