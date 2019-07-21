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

class CommitCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: commit()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopCommit(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - commit()');

        $adapter = new Noop();

        $adapter->begin();

        $I->assertTrue(
            $adapter->inTransaction()
        );

        $adapter->commit();

        $I->assertFalse(
            $adapter->inTransaction()
        );
    }

    /**
     * Tests Phalcon\Logger\Adapter\Noop :: commit() - no transaction
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopCommitNoTransaction(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - commit() - no transaction');

        $adapter = new Noop();

        $I->assertFalse(
            $adapter->inTransaction()
        );

        $I->expectThrowable(
            new Exception('There is no active transaction'),
            function () use ($adapter) {
                $adapter->commit();
            }
        );
    }
}
