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

namespace Phalcon\Tests\Unit\Logger\Adapter\Syslog;

use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Logger\Exception;
use UnitTester;

class CommitCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: commit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterSyslogCommit(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - commit()');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

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
     * Tests Phalcon\Logger\Adapter\Syslog :: commit() - no transaction
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterSyslogCommitNoTransaction(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - commit() - no transaction');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

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
