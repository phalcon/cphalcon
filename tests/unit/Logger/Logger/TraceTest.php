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

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Logger;
use Phalcon\Tests\AbstractUnitTestCase;

use function file_get_contents;
use function logsDir;

final class TraceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-04
     */
    public function testLoggerTraceLogsWhenLevelEnabled(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir($fileName);
        $adapter    = new Stream($outputPath);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $logger->setLogLevel(Enum::TRACE);
        $logger->trace('trace message');

        $contents = file_get_contents($outputPath);
        $this->assertStringContainsString('[trace] trace message', $contents);

        $adapter->close();
        $this->safeDeleteFile($outputPath);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-04
     */
    public function testLoggerTraceSuppressedAtDefaultLevel(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir($fileName);
        $adapter    = new Stream($outputPath);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        // Default logLevel is CUSTOM (8); TRACE (9) is more verbose and opt-in.
        // The info() call (level 6) is a control that must appear; trace must not.
        $logger->info('control message');
        $logger->trace('trace message');

        $contents = file_get_contents($outputPath);
        $this->assertStringContainsString('control message', $contents);
        $this->assertStringNotContainsString('trace message', $contents);

        $adapter->close();
        $this->safeDeleteFile($outputPath);
    }
}
