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
use Phalcon\Logger\Exceptions\TransactionAlreadyActive;
use Phalcon\Tests\AbstractUnitTestCase;

final class BeginTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterSyslogBegin(): void
    {
        $streamName = $this->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

        $adapter->begin();

        $actual = $adapter->inTransaction();
        $this->assertTrue($actual);

        $adapter->rollback();
        $adapter->close();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-15
     */
    public function testLoggerAdapterSyslogBeginTransactionAlreadyActive(): void
    {
        $this->expectException(TransactionAlreadyActive::class);
        $this->expectExceptionMessage('There is an active transaction');

        $streamName = $this->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

        $adapter->begin();
        $adapter->begin();
    }
}
