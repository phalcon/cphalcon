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
 * Class ExcludeAdaptersCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class ExcludeAdaptersCest
{
    /**
     * Tests Phalcon\Logger :: excludeAdapters()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerExcludeAdapters(UnitTester $I)
    {
        $I->wantToTest('Logger - excludeAdapters()');

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
        $I->safeDeleteFile($fileName1);

        $I->amInPath($outputPath);
        $I->openFile($fileName2);
        $I->seeInThisFile('Goodbye');
        $I->safeDeleteFile($fileName2);
    }
}
