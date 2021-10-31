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

/**
 * @todo Until I figure this approach, this stays here and can be used for other
 *       tests in this namespace
 */

namespace Phalcon\Tests\Unit\Logger\Adapter\Syslog;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

use function date_default_timezone_get;

class AddCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: add()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterSyslogAdd(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - add()');

        $streamName = $I->getNewFileName('log', 'log');
        $timezone   = date_default_timezone_get();
        $datetime   = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter    = new Syslog($streamName);

        $adapter->begin();

        $item1 = new Item(
            'Message 1',
            'debug',
            Logger::DEBUG,
            $datetime
        );

        $item2 = new Item(
            'Message 2',
            'debug',
            Logger::DEBUG,
            $datetime
        );

        $item3 = new Item(
            'Message 3',
            'debug',
            Logger::DEBUG,
            $datetime
        );

        $adapter
            ->add($item1)
            ->add($item2)
            ->add($item3)
        ;

        $adapter->commit();

        $I->assertTrue(
            $adapter->close()
        );
    }
}
