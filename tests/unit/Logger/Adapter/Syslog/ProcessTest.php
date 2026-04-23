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

use DateTimeImmutable;
use DateTimeZone;
use LogicException;
use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Item;
use Phalcon\Tests\Unit\Logger\Fake\Adapter\FakeSyslogAdapter;
use Phalcon\Tests\AbstractUnitTestCase;

use function date_default_timezone_get;

final class ProcessTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterSyslogProcess(): void
    {
        $streamName = $this->getNewFileName('log', 'log');
        $timezone   = date_default_timezone_get();
        $datetime   = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter    = new Syslog($streamName);

        $item = new Item(
            'Message 1',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $adapter->process($item);

        $actual = $adapter->close();
        $this->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: process() - exception
     *
     * @throws Exception
     */
    public function testLoggerAdapterSyslogProcessException(): void
    {
        $fileName = $this->getNewFileName('log', 'log');

        $this->expectException(LogicException::class);
        $this->expectExceptionMessage(
            "Cannot open syslog for name [" . $fileName
            . "] and facility [8]"
        );

        $adapter = new FakeSyslogAdapter($fileName);

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item     = new Item(
            'Message 1',
            'debug',
            Enum::DEBUG,
            $datetime
        );
        $adapter->process($item);
    }
}
