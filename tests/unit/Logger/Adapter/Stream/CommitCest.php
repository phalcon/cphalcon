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

/**
 * Class CommitCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class CommitCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: commit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterStreamCommit(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - commit()');

        $fileName   = $I->getNewFileName('log', 'log');

        $outputPath = outputFolder('tests/logs/');

        $adapter = new Stream($outputPath . $fileName);

        $adapter->begin();

        $I->assertTrue(
            $adapter->inTransaction()
        );

        $adapter->commit();

        $I->assertFalse(
            $adapter->inTransaction()
        );

        $I->safeDeleteFile(
            $outputPath . $fileName
        );
    }

    /**
     * Tests Phalcon\Logger\Adapter\Stream :: commit() - no transaction
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterStreamCommitNoTransaction(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - commit() - no transaction');

        $fileName = $I->getNewFileName('log', 'log');

        $outputPath = outputFolder('tests/logs/');

        $adapter = new Stream($outputPath . $fileName);

        $I->assertFalse(
            $adapter->inTransaction()
        );

        $I->expectThrowable(
            new Exception('There is no active transaction'),
            function () use ($adapter) {
                $adapter->commit();
            }
        );

        $I->safeDeleteFile(
            $outputPath . $fileName
        );
    }
}
