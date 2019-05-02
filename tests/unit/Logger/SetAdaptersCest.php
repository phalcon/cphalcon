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
use UnitTester;

/**
 * @package Phalcon\Test\Unit\Logger
 */
class SetAdaptersCest
{
    /**
     * Tests Phalcon\Logger :: setAdapters()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerSetAdapters(UnitTester $I)
    {
        $I->wantToTest('Logger - setAdapters()');

        $fileName1 = $I->getNewFileName('log', 'log');
        $fileName2 = $I->getNewFileName('log', 'log');

        $outputPath = outputDir('tests/logs/');

        $adapter1 = new Stream(
            $outputPath . $fileName1
        );

        $adapter2 = new Stream(
            $outputPath . $fileName2
        );

        $logger = new Logger('my-logger');

        $I->assertCount(
            0,
            $logger->getAdapters()
        );

        $logger->setAdapters(
            [
                'one' => $adapter1,
                'two' => $adapter2,
            ]
        );

        $adapters = $logger->getAdapters();

        $I->assertCount(2, $adapters);

        $I->assertInstanceOf(
            Stream::class,
            $adapters['one']
        );

        $I->assertInstanceOf(
            Stream::class,
            $adapters['two']
        );

        $I->safeDeleteFile(
            $outputPath . $fileName1
        );

        $I->safeDeleteFile(
            $outputPath . $fileName2
        );
    }

    /**
     * Tests Phalcon\Logger :: setAdapters() - constructor
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerSetAdaptersConstructor(UnitTester $I)
    {
        $I->wantToTest('Logger :: setAdapters() - constructor');

        $fileName1 = $I->getNewFileName('log', 'log');
        $fileName2 = $I->getNewFileName('log', 'log');

        $outputPath = outputDir('tests/logs/');

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

        $adapters = $logger->getAdapters();

        $I->assertCount(2, $adapters);

        $I->assertInstanceOf(
            Stream::class,
            $adapters['one']
        );

        $I->assertInstanceOf(
            Stream::class,
            $adapters['two']
        );

        $I->safeDeleteFile(
            $outputPath . $fileName1
        );

        $I->safeDeleteFile(
            $outputPath . $fileName2
        );
    }
}
