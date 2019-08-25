<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Formatter\Syslog;

use Phalcon\Logger\Formatter\Syslog;
use Phalcon\Logger\Item;
use Phalcon\Logger;
use UnitTester;

class FormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Syslog :: format()
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
