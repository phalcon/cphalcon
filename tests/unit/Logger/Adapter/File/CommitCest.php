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

namespace Phalcon\Test\Unit\Logger\Adapter\File;

use Phalcon\Logger\Adapter\File;
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
     * Tests Phalcon\Logger\Adapter\File :: commit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterFileCommit(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\File - commit()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = outputFolder('tests/logs/');
        $adapter    = new File($outputPath . $fileName);

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $I->assertTrue($actual);

        $adapter->commit();

        $actual = $adapter->inTransaction();
        $I->assertFalse($actual);

        $I->safeDeleteFile($outputPath . $fileName);
    }

    /**
     * Tests Phalcon\Logger\Adapter\File :: commit() - no transaction
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterFileCommitNoTransaction(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\File - commit() - no transaction');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = outputFolder('tests/logs/');

        try {
            $adapter = new File($outputPath . $fileName);

            $actual = $adapter->inTransaction();
            $I->assertFalse($actual);

            $adapter->commit();
        } catch (Exception $ex) {
            $expected = 'There is no active transaction';
            $actual   = $ex->getMessage();
            $I->assertEquals($expected, $actual);
        }

        $I->safeDeleteFile($outputPath . $fileName);
    }
}
