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

namespace Phalcon\Tests\Unit\Logger\Logger;

use DateTimeZone;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Exception;
use Phalcon\Logger\Formatter\Json;
use Phalcon\Logger\Logger;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Logger\LoggerInterface;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerConstructWithTimezone(): void
    {
        $timezone = new DateTimeZone('America/New_York');
        $logger   = new Logger('my-logger', [], $timezone);

        $this->assertInstanceOf(LoggerInterface::class, $logger);
        $this->assertSame('my-logger', $logger->getName());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerConstruct(): void
    {
        $logger = new Logger('my-logger');
        $this->assertInstanceOf(LoggerInterface::class, $logger);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerConstructConstants(): void
    {
        $this->assertSame(2, Enum::ALERT);
        $this->assertSame(1, Enum::CRITICAL);
        $this->assertSame(7, Enum::DEBUG);
        $this->assertSame(0, Enum::EMERGENCY);
        $this->assertSame(3, Enum::ERROR);
        $this->assertSame(6, Enum::INFO);
        $this->assertSame(5, Enum::NOTICE);
        $this->assertSame(4, Enum::WARNING);
        $this->assertSame(8, Enum::CUSTOM);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerConstructNoAdapterException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('No adapters specified');

        $logger = new Logger('my-logger');
        $logger->info('Some message');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerConstructStreamReadOnlyModeException(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();

        $file = $outputPath . $fileName;

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Adapter cannot be opened in read mode');

        (new Stream(
            $file,
            [
                'mode' => 'r',
            ]
        ));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerConstructStreamWithJsonConstants(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir($fileName);
        $adapter    = new Stream($outputPath);

        $adapter->setFormatter(new Json());

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $time = time();

        $logger->debug('This is a message');
        $logger->log(Enum::ERROR, 'This is an error');
        $logger->error('This is another error');

        $expected = sprintf(
            '{"level":"debug","message":"This is a message","timestamp":"%s"}' . PHP_EOL .
            '{"level":"error","message":"This is an error","timestamp":"%s"}' . PHP_EOL .
            '{"level":"error","message":"This is another error","timestamp":"%s"}',
            date('c', $time),
            date('c', $time),
            date('c', $time)
        );

        $contents = file_get_contents($outputPath);
        $this->assertStringContainsString($expected, $contents);

        $adapter->close();
        $this->safeDeleteFile($outputPath);
    }
}
