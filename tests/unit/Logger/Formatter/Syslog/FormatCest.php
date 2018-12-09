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

namespace Phalcon\Test\Unit\Logger\Formatter\Syslog;

use Phalcon\Logger;
use Phalcon\Logger\Formatter\Syslog;
use Phalcon\Logger\Item;
use UnitTester;

/**
 * Class FormatCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class FormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Syslog :: format()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterSyslogFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Syslog - format()');
        $formatter = new Syslog();

        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = [Logger::DEBUG, 'log message'];
        $actual   = $formatter->format($item);
        $I->assertEquals($expected, $actual);
    }
}
