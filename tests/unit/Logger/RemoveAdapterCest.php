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
 * Class RemoveAdapterCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class RemoveAdapterCest
{
    /**
     * Tests Phalcon\Logger :: removeAdapter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerRemoveAdapter(UnitTester $I)
    {
        $I->wantToTest('Logger - removeAdapter()');

        $fileName1  = $I->getNewFileName('log', 'log');
        $fileName2  = $I->getNewFileName('log', 'log');
        $outputPath = outputFolder('tests/logs/');
        $adapter1   = new Stream($outputPath . $fileName1);
        $adapter2   = new Stream($outputPath . $fileName2);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
                'two' => $adapter2,
            ]
        );

        $expected = 2;
        $adapters = $logger->getAdapters();
        $I->assertCount($expected, $adapters);

        $logger->removeAdapter('one');
        $expected = 1;
        $adapters = $logger->getAdapters();
        $I->assertCount($expected, $adapters);

        $I->safeDeleteFile($outputPath . $fileName1);
        $I->safeDeleteFile($outputPath . $fileName2);
    }

    /**
     * Tests Phalcon\Logger :: removeAdapter() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerRemoveAdapterUnknown(UnitTester $I)
    {
        $I->wantToTest('Logger - removeAdapter() - unknown');

        $fileName1  = $I->getNewFileName('log', 'log');
        $outputPath = outputFolder('tests/logs/');

        try {
            $adapter1 = new Stream($outputPath . $fileName1);

            $logger = new Logger(
                'my-logger',
                [
                    'one' => $adapter1,
                ]
            );

            $expected = 1;
            $adapters = $logger->getAdapters();
            $I->assertCount($expected, $adapters);

            $logger->removeAdapter('unknown');
        } catch (Exception $ex) {
            $expected = 'Adapter does not exist for this logger';
            $actual   = $ex->getMessage();
            $I->assertEquals($expected, $actual);
        }

        $I->safeDeleteFile($outputPath . $fileName1);
    }
}
