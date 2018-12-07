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

use Phalcon\Logger;
use Phalcon\Logger\Item;
use UnitTester;

/**
 * Class GetNameCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetNameCest
{
    /**
     * Tests Phalcon\Logger\Item :: getName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerItemGetName(UnitTester $I)
    {
        $I->wantToTest('Logger\Item - getName()');
        $time = time();
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = 'debug';
        $actual   = $item->getName();
        $I->assertEquals($expected, $actual);
    }
}
