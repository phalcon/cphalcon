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

namespace Phalcon\Tests\Unit\Logger\Adapter\Stream;

use Codeception\Stub;
use DateTimeImmutable;
use DateTimeZone;
use LogicException;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

use function date_default_timezone_get;
use function logsDir;

class ProcessCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: process()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterStreamProcess(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - process()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $timezone   = date_default_timezone_get();
        $datetime   = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter    = new Stream($outputPath . $fileName);

        $item = new Item(
            'Message 1',
            'debug',
            Logger::DEBUG,
            $datetime
        );
        $adapter->process($item);

        $I->amInPath($outputPath);
        $I->seeFileFound($fileName);
        $I->openFile($fileName);
        $I->seeInThisFile('Message 1');

        $actual = $adapter->close();
        $I->assertTrue($actual);
        $I->safeDeleteFile($outputPath . $fileName);
    }

    /**
     * Tests Phalcon\Logger\Adapter\Stream :: process() - exception
     *
     * @param UnitTester $I
     */
    public function loggerAdapterStreamProcessException(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - process() - exception');

        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();

        $I->expectThrowable(
            new LogicException(
                "The file '" .
                $outputPath .
                $fileName .
                "' cannot be opened with mode 'ab'"
            ),
            function () use ($outputPath, $fileName) {
                $adapter = Stub::construct(
                    Stream::class,
                    [
                        $outputPath . $fileName,
                    ],
                    [
                        'phpFopen' => false,
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

        $I->safeDeleteFile($outputPath . $fileName);
    }
}
