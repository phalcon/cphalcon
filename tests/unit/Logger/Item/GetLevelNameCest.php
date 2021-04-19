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

use DateTimeImmutable;
use Phalcon\Logger;
use Phalcon\Logger\Item;
use UnitTester;

class GetLevelNameCest
{
    /**
     * Tests Phalcon\Logger\Item :: getName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerItemGetLevelName(UnitTester $I)
    {
        $I->wantToTest('Logger\Item - getLevelName()');

        $time = new DateTimeImmutable("now");
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = 'debug';
        $actual   = $item->getLevelName();
        $I->assertEquals($expected, $actual);
    }
}
