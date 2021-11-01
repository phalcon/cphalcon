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

namespace Phalcon\Tests\Unit\Logger\Adapter\Syslog;

use Codeception\Stub;
use DateTimeImmutable;
use DateTimeZone;
use LogicException;
use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

use function date_default_timezone_get;

class ProcessCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: process()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterSyslogProcess(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - process()');

        $streamName = $I->getNewFileName('log', 'log');
        $timezone   = date_default_timezone_get();
        $datetime   = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter    = new Syslog($streamName);

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

    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: process() - exception
     *
     * @throws Exception
     */
    public function loggerAdapterSyslogProcessException(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - process() - exception');

        $fileName = $I->getNewFileName('log', 'log');

        $I->expectThrowable(
            new LogicException(
                "Cannot open syslog for name [" . $fileName
                . "] and facility [8]"
            ),
            function () use ($fileName) {
                $adapter = Stub::construct(
                    Syslog::class,
                    [
                        $fileName,
                    ],
                    [
                        'openlog' => false,
                    ]
                );

                $timezone = date_default_timezone_get();
                $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
                $item     = new Item(
                    'Message 1',
                    'debug',
                    Logger::DEBUG,
                    $datetime
                );
                $adapter->process($item);
            }
        );
    }
}
