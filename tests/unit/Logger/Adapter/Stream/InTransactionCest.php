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

use Phalcon\Logger\Adapter\Stream;
use UnitTester;

class InTransactionCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: inTransaction()
     */
    public function loggerAdapterStreamInTransaction(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - inTransaction()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter    = new Stream($outputPath . $fileName);

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $I->assertTrue($actual);

        $adapter->commit();

        $actual = $adapter->inTransaction();
        $I->assertFalse($actual);

        $adapter->close();
        $I->safeDeleteFile($outputPath . $fileName);
    }
}
