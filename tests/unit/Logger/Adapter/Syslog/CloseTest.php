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
use Phalcon\Tests\AbstractUnitTestCase;

final class CloseTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterSyslogClose(): void
    {
        $streamName = $this->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

        $actual = $adapter->close();
        $this->assertTrue($actual);
    }

    /**
     * @issue  15638
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-09-03
     */
    public function testLoggerAdapterSyslogCloseException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('There is an active transaction');

        $streamName = $this->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

        $adapter->begin();
        $adapter->close();
    }
}
