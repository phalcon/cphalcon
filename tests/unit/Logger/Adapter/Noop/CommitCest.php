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

namespace Phalcon\Test\Unit\Logger\Adapter\Noop;

use Phalcon\Logger\Adapter\Noop;
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
     * Tests Phalcon\Logger\Adapter\Noop :: commit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopCommit(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - commit()');
        $adapter = new Noop();

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $I->assertTrue($actual);

        $adapter->commit();

        $actual = $adapter->inTransaction();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Logger\Adapter\Noop :: commit() - no transaction
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopCommitNoTransaction(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - commit() - no transaction');

        try {
            $adapter = new Noop();

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
