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

class GetLevelCest
{
    /**
     * Tests Phalcon\Logger\Item :: getLevel()
     */
    public function loggerItemGetLevel(UnitTester $I)
    {
        $I->wantToTest('Logger\Item - getLevel()');
        $time = new DateTimeImmutable("now");
        $item = new Item('log message', 'debug', Logger::DEBUG, $time);

        $expected = Logger::DEBUG;
        $actual   = $item->getLevel();
        $I->assertEquals($expected, $actual);
    }
}
