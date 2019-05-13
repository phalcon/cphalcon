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

namespace Phalcon\Test\Unit\Logger\Item;

use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

class GetTypeCest
{
    /**
     * Tests Phalcon\Logger\Item :: getType()
     *
     * @param UnitTester $I
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
