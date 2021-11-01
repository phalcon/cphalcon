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

namespace Phalcon\Tests\Unit\Logger\Adapter\Noop;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

use function date_default_timezone_get;

class ProcessCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: process()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterNoopProcess(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - process()');

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter  = new Noop();

        $item = new Item(
            'Message 1',
            'debug',
            Logger::DEBUG,
            $datetime
        );

        $adapter->process($item);

        $actual = $adapter->close();
        $I->assertTrue($actual);
    }
}
