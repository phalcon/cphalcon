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

namespace Phalcon\Tests\Unit\Logger\Logger;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Logger;
use UnitTester;

class ExcludeAdaptersCest
{
    /**
     * Tests Phalcon\Logger :: excludeAdapters()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerExcludeAdapters(UnitTester $I)
    {
        $I->wantToTest('Logger - excludeAdapters()');

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

        /**
         * Log into both
         */
        $logger->debug('Hello');

        $I->amInPath($outputPath);
        $I->openFile($fileName1);
        $I->seeInThisFile('Hello');

        $I->amInPath($outputPath);
        $I->openFile($fileName2);
        $I->seeInThisFile('Hello');

        /**
         * Exclude a logger
         */
        $logger
            ->excludeAdapters(['two'])
            ->debug('Goodbye')
        ;

        $I->amInPath($outputPath);
        $I->openFile($fileName1);
        $I->seeInThisFile('Goodbye');

        $I->amInPath($outputPath);
        $I->openFile($fileName2);
        $I->dontSeeInThisFile('Goodbye');

        $adapter1->close();
        $adapter2->close();

        $I->safeDeleteFile($fileName1);
        $I->safeDeleteFile($fileName2);
    }
}
