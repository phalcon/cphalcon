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

namespace Phalcon\Tests\Unit\Logger\Item;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

use function date_default_timezone_get;

class GetLevelNameCest
{
    /**
     * Tests Phalcon\Logger\Item :: getLevelName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerItemGetLevelName(UnitTester $I)
    {
        $I->wantToTest('Logger\Item - getLevelName()');

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item     = new Item(
            'log message',
            'debug',
            Logger::DEBUG,
            $datetime
        );

        $I->assertEquals('debug', $item->getLevelName());
    }
}
