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

use DateTimeImmutable;
use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Exception;
use Phalcon\Logger\Item;
use UnitTester;

class CloseCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: close()
     */
    public function loggerAdapterStreamClose(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - close()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $time       = new DateTimeImmutable('now');
        $adapter    = new Stream($outputPath . $fileName);

        $item = new Item('Message 1', 'debug', Logger::DEBUG, $time);
        $adapter->process($item);

        $actual = $adapter->close();
        $I->assertTrue($actual);

        $I->amInPath($outputPath);
        $I->seeFileFound($fileName);
        $I->openFile($fileName);
        $I->seeInThisFile('Message 1');

        $I->safeDeleteFile($outputPath . $fileName);
    }

    /**
     * Tests Phalcon\Logger\Adapter\Stream :: close() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-09-03
     * @issue  15638
     */
    public function loggerAdapterStreamCloseException(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - close() - exception');

        $I->expectThrowable(
            new Exception('There is an active transaction'),
            function () use ($I) {
                $fileName   = $I->getNewFileName('log', 'log');
                $outputPath = logsDir();
                $adapter    = new Stream($outputPath . $fileName);

                $adapter->begin();
                $adapter->close();
            }
        );
    }
}
