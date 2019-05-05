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

namespace Phalcon\Test\Unit\Logger;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Exception;
use UnitTester;

/**
 * @package Phalcon\Test\Unit\Logger
 */
class RemoveAdapterCest
{
    /**
     * Tests Phalcon\Logger :: removeAdapter()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerRemoveAdapter(UnitTester $I)
    {
        $I->wantToTest('Logger - removeAdapter()');

        $fileName1 = $I->getNewFileName('log', 'log');
        $fileName2 = $I->getNewFileName('log', 'log');

        $outputPath = outputFolder('tests/logs/');

        $adapter1 = new Stream(
            $outputPath . $fileName1
        );

        $adapter2 = new Stream(
            $outputPath . $fileName2
        );

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
                'two' => $adapter2,
            ]
        );

        $I->assertCount(
            2,
            $logger->getAdapters()
        );

        $logger->removeAdapter('one');

        $I->assertCount(
            1,
            $logger->getAdapters()
        );

        $I->safeDeleteFile(
            $outputPath . $fileName1
        );

        $I->safeDeleteFile(
            $outputPath . $fileName2
        );
    }

    /**
     * Tests Phalcon\Logger :: removeAdapter() - unknown
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerRemoveAdapterUnknown(UnitTester $I)
    {
        $I->wantToTest('Logger - removeAdapter() - unknown');

        $fileName1 = $I->getNewFileName('log', 'log');

        $outputPath = outputFolder('tests/logs/');

        $adapter1 = new Stream(
            $outputPath . $fileName1
        );

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
            ]
        );

        $I->expectThrowable(
            new Exception('Adapter does not exist for this logger'),
            function () use ($logger) {
                $logger->removeAdapter('unknown');
            }
        );

        $I->safeDeleteFile(
            $outputPath . $fileName1
        );
    }
}
