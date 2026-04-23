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

namespace Phalcon\Tests\Unit\Logger\Adapter\Stream;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Exception;
use Phalcon\Logger\Item;
use Phalcon\Tests\AbstractUnitTestCase;

use function date_default_timezone_get;
use function file_get_contents;

final class CloseTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterStreamClose(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $timezone   = date_default_timezone_get();
        $datetime   = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter    = new Stream($outputPath . $fileName);

        $item = new Item(
            'Message 1',
            'debug',
            Enum::DEBUG,
            $datetime
        );
        $adapter->process($item);

        $actual = $adapter->close();
        $this->assertTrue($actual);

        $this->assertFileExists($outputPath . $fileName);

        $contents = file_get_contents($outputPath . $fileName);
        $this->assertStringContainsString('Message 1', $contents);

        $this->safeDeleteFile($outputPath . $fileName);
    }

    /**
     * @issue  15638
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-09-03
     */
    public function testLoggerAdapterStreamCloseException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('There is an active transaction');

        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter    = new Stream($outputPath . $fileName);

        $adapter->begin();
        $adapter->close();
    }
}
