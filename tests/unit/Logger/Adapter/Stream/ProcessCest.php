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

use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Exception;
use Phalcon\Logger\Item;
use UnitTester;

class ProcessCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: process()
     *
     * @throws Exception
     */
    public function loggerAdapterStreamProcess(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - process()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter    = new Stream($outputPath . $fileName);

        $item = new Item('Message 1', 'debug', Logger::DEBUG);
        $adapter->process($item);

        $I->amInPath($outputPath);
        $I->seeFileFound($fileName);
        $I->openFile($fileName);
        $I->seeInThisFile('Message 1');

        $adapter->close();
        $I->safeDeleteFile($outputPath . $fileName);
    }
}
