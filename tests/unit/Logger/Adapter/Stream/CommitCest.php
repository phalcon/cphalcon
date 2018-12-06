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
        $streamName   = $I->getNewFileName('log', 'log');
        $adapter    = new Stream($streamName);

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $I->assertTrue($actual);

        $adapter->commit();

        $actual = $adapter->inTransaction();
        $I->assertFalse($actual);
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
        $streamName   = $I->getNewFileName('log', 'log');

        try {
            $adapter = new Stream($streamName);

            $actual = $adapter->inTransaction();
            $I->assertFalse($actual);

            $adapter->commit();
        } catch (Exception $ex) {
            $expected = 'There is no active transaction';
            $actual   = $ex->getMessage();
            $I->assertEquals($expected, $actual);
        }
    }
}
