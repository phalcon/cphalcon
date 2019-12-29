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

use Phalcon\Logger\Adapter\Stream;
use UnitTester;

class BeginCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: begin()
     */
    public function loggerAdapterStreamBegin(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - begin()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter    = new Stream($outputPath . $fileName);

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $I->assertTrue($actual);

        $I->safeDeleteFile($outputPath . $fileName);
    }
}
