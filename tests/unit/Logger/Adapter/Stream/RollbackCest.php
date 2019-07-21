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
use Phalcon\Logger\Exception;
use UnitTester;

class RollbackCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: rollback()
     *
     * @throws Exception
     */
    public function loggerAdapterStreamRollback(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - rollback()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter    = new Stream($outputPath . $fileName);

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $I->assertTrue($actual);

        $adapter->rollback();

        $actual = $adapter->inTransaction();
        $I->assertFalse($actual);

        $I->safeDeleteFile($outputPath . $fileName);
    }

    /**
     * Tests Phalcon\Logger\Adapter\Stream :: rollback() - exception
     */
    public function loggerAdapterStreamRollbackException(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - rollback() - exception');
        $I->expectThrowable(
            new Exception('There is no active transaction'),
            function () use ($I) {
                $fileName   = $I->getNewFileName('log', 'log');
                $outputPath = logsDir();
                $adapter    = new Stream($outputPath . $fileName);

                $adapter->rollback();
            }
        );
    }
}
