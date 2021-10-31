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
use Phalcon\Logger\Exception;
use UnitTester;

class CommitCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: commit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterStreamCommit(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - commit()');
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

    /**
     * Tests Phalcon\Logger\Adapter\Stream :: commit() - no transaction
     */
    public function loggerAdapterStreamCommitNoTransaction(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - commit() - no transaction');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = logsDir();

        try {
            $adapter = new Stream($outputPath . $fileName);

            $actual = $adapter->inTransaction();
            $I->assertFalse($actual);

            $adapter->commit();
            $adapter->close();
        } catch (Exception $ex) {
            $expected = 'There is no active transaction';
            $actual   = $ex->getMessage();
            $I->assertEquals($expected, $actual);
        }

        $I->safeDeleteFile($outputPath . $fileName);
    }
}
