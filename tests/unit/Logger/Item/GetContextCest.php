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
 * Class GetContextCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetContextCest
{
    /**
     * Tests Phalcon\Logger\Item :: getContext()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerItemGetContext(UnitTester $I)
    {
        $I->wantToTest('Logger\Item - getContext()');
        $time    = time();
        $context = ['context'];
        $item    = new Item('log message', 'debug', Logger::DEBUG, $time, $context);

        $expected = $context;
        $actual   = $item->getContext();
        $I->assertEquals($expected, $actual);
    }
}
