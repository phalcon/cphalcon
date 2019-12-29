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

class AddAdapterCest
{
    /**
     * Tests Phalcon\Logger :: addAdapter()
     */
    public function loggerAddAdapter(UnitTester $I)
    {
        $I->wantToTest('Logger - addAdapter()');

        $fileName1  = $I->getNewFileName('log', 'log');
        $fileName2  = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter1   = new Stream($outputPath . $fileName1);
        $adapter2   = new Stream($outputPath . $fileName2);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
            ]
        );

        $expected = 1;
        $actual   = $logger->getAdapters();
        $I->assertCount($expected, $actual);

        $logger->addAdapter('two', $adapter2);
        $expected = 2;
        $actual   = $logger->getAdapters();
        $I->assertCount($expected, $actual);

        $logger->debug('Hello');

        $I->amInPath($outputPath);
        $I->openFile($fileName1);
        $I->seeInThisFile('Hello');
        $I->safeDeleteFile($fileName1);

        $I->amInPath($outputPath);
        $I->openFile($fileName2);
        $I->seeInThisFile('Hello');
        $I->safeDeleteFile($fileName2);
    }
}
