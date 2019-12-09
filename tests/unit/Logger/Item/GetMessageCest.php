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

namespace Phalcon\Test\Unit\Logger\Item;

use Phalcon\Logger;
use Phalcon\Logger\Item;
use UnitTester;

class GetMessageCest
{
    /**
     * Tests Phalcon\Logger\Item :: getMessage()
     */
    public function loggerItemGetMessage(UnitTester $I)
    {
        $I->wantToTest('Logger\Item - getMessage()');
        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = 'log message';
        $actual   = $item->getMessage();
        $I->assertEquals($expected, $actual);
    }
}
