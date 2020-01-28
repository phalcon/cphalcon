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

class GetTimeCest
{
    /**
     * Tests Phalcon\Logger\Item :: getTime()
     */
    public function loggerItemGetTime(UnitTester $I)
    {
        $I->wantToTest('Logger\Item - getTime()');
        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = $time;
        $actual   = $item->getTime();
        $I->assertEquals($expected, $actual);
    }
}
