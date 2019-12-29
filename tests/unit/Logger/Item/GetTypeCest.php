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

class GetTypeCest
{
    /**
     * Tests Phalcon\Logger\Item :: getType()
     */
    public function loggerItemGetType(UnitTester $I)
    {
        $I->wantToTest('Logger\Item - getType()');
        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = Logger::DEBUG;
        $actual   = $item->getType();
        $I->assertEquals($expected, $actual);
    }
}
