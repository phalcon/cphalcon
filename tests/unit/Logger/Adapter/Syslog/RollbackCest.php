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

namespace Phalcon\Test\Unit\Logger\Adapter\Syslog;

use Phalcon\Logger\Adapter\Syslog;
use UnitTester;

/**
 * Class RollbackCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class RollbackCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: rollback()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterSyslogRollback(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - rollback()');
        $streamName = $I->getNewFileName('log', 'log');
        $adapter    = new Syslog($streamName);

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $I->assertTrue($actual);

        $adapter->rollback();

        $actual = $adapter->inTransaction();
        $I->assertFalse($actual);
    }
}
