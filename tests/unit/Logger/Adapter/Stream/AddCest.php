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

namespace Phalcon\Test\Unit\Logger\Adapter\Stream;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

class AddCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: add()
     */
    public function loggerAdapterStreamAdd(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - add()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter    = new Stream($outputPath . $fileName);

        $adapter->begin();
        $item1 = new Item('Message 1', 'debug', Logger::DEBUG);
        $item2 = new Item('Message 2', 'debug', Logger::DEBUG);
        $item3 = new Item('Message 3', 'debug', Logger::DEBUG);

        $adapter
            ->add($item1)
            ->add($item2)
            ->add($item3)
        ;

        $I->amInPath($outputPath);
        $I->dontSeeFileFound($fileName);

        $adapter->commit();

        $I->amInPath($outputPath);
        $I->seeFileFound($fileName);
        $I->openFile($fileName);
        $I->seeInThisFile('Message 1');
        $I->seeInThisFile('Message 2');
        $I->seeInThisFile('Message 3');

        $I->safeDeleteFile($outputPath . $fileName);
    }
}
