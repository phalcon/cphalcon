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

namespace Phalcon\Test\Unit\Logger\Adapter\Stream;

use DateTimeImmutable;
use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
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
}
