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

namespace Phalcon\Test\Unit\Logger\Logger;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
use UnitTester;

class SetAdaptersCest
{
    /**
     * Tests Phalcon\Logger :: setAdapters()
     */
    public function loggerSetAdapters(UnitTester $I)
    {
        $I->wantToTest('Logger - setAdapters()');
        $fileName1  = $I->getNewFileName('log', 'log');
        $fileName2  = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter1   = new Stream($outputPath . $fileName1);
        $adapter2   = new Stream($outputPath . $fileName2);

        $logger = new Logger('my-logger');

        $expected = 0;
        $adapters = $logger->getAdapters();
        $I->assertCount($expected, $adapters);

        $logger->setAdapters(
            [
                'one' => $adapter1,
                'two' => $adapter2,
            ]
        );

        $expected = 2;
        $adapters = $logger->getAdapters();
        $I->assertCount($expected, $adapters);

        $class = Stream::class;
        $I->assertInstanceOf($class, $adapters['one']);
        $I->assertInstanceOf($class, $adapters['two']);

        $I->safeDeleteFile($outputPath . $fileName1);
        $I->safeDeleteFile($outputPath . $fileName2);
    }

    /**
     * Tests Phalcon\Logger :: setAdapters() - constructor
     */
    public function loggerSetAdaptersConstructor(UnitTester $I)
    {
        $I->wantToTest('Logger :: setAdapters() - constructor');
        $fileName1  = $I->getNewFileName('log', 'log');
        $fileName2  = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
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

        $class = Stream::class;
        $I->assertInstanceOf($class, $adapters['one']);
        $I->assertInstanceOf($class, $adapters['two']);

        $I->safeDeleteFile($outputPath . $fileName1);
        $I->safeDeleteFile($outputPath . $fileName2);
    }
}
