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
use LogicException;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Item;
use Phalcon\Tests\Unit\Logger\Fake\Adapter\FakeStreamAdapter;
use Phalcon\Tests\AbstractUnitTestCase;

use function date_default_timezone_get;
use function file_get_contents;
use function logsDir;

final class ProcessTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterStreamProcess(): void
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

        $this->assertFileExists($outputPath . $fileName);

        $content = file_get_contents($outputPath . $fileName);
        $this->assertStringContainsString('Message 1', $content);

        $actual = $adapter->close();
        $this->assertTrue($actual);
        $this->safeDeleteFile($outputPath . $fileName);
    }

    /**
     * Tests Phalcon\Logger\Adapter\Stream :: process() - exception
     *
     * @return void
     */
    public function testLoggerAdapterStreamProcessException(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();

        $this->expectException(LogicException::class);
        $this->expectExceptionMessage(
            "The file '" .
            $outputPath .
            $fileName .
            "' cannot be opened with mode 'ab'"
        );

        $adapter = new FakeStreamAdapter($outputPath . $fileName);

        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $item     = new Item(
            'Message 1',
            'debug',
            Enum::DEBUG,
            $datetime
        );
        $adapter->process($item);

        $this->safeDeleteFile($outputPath . $fileName);
    }
}
