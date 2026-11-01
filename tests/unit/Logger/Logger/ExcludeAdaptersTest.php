<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Logger\Logger;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Logger;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

use function file_get_contents;

final class ExcludeAdaptersTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerExcludeAdapters(): void
    {
        $fileName1   = $this->getNewFileName('log', 'log');
        $fileName2   = $this->getNewFileName('log', 'log');
        $outputPath1 = Talon::settings()->outputPath('tests/logs/' . $fileName1);
        $outputPath2 = Talon::settings()->outputPath('tests/logs/' . $fileName2);
        $adapter1    = new Stream($outputPath1);
        $adapter2    = new Stream($outputPath2);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
                'two' => $adapter2,
            ]
        );

        /**
         * Log into both
         */
        $logger->debug('Hello');

        $contents = file_get_contents($outputPath1);
        $this->assertStringContainsString('Hello', $contents);

        $contents = file_get_contents($outputPath2);
        $this->assertStringContainsString('Hello', $contents);

        /**
         * Exclude a logger
         */
        $logger
            ->excludeAdapters(['two'])
            ->debug('Goodbye')
        ;

        $contents = file_get_contents($outputPath1);
        $this->assertStringContainsString('Goodbye', $contents);

        $contents = file_get_contents($outputPath2);
        $this->assertStringNotContainsString('Goodbye', $contents);

        $adapter1->close();
        $adapter2->close();

        $this->safeDeleteFile($outputPath1);
        $this->safeDeleteFile($outputPath2);
    }

    /**
     * An exclusion applies only to the call after excludeAdapters().
     *
     * @issue https://github.com/phalcon/cphalcon/issues/17713
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-31
     */
    public function testLoggerExcludeAdaptersOnlyForOneCall(): void
    {
        $fileName1   = $this->getNewFileName('log', 'log');
        $fileName2   = $this->getNewFileName('log', 'log');
        $outputPath1 = Talon::settings()->outputPath('tests/logs/' . $fileName1);
        $outputPath2 = Talon::settings()->outputPath('tests/logs/' . $fileName2);
        $adapter1    = new Stream($outputPath1);
        $adapter2    = new Stream($outputPath2);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
                'two' => $adapter2,
            ]
        );

        $logger
            ->excludeAdapters(['two'])
            ->debug('Goodbye')
        ;
        $logger->debug('Again');

        $contents = file_get_contents($outputPath2);
        $this->assertStringNotContainsString('Goodbye', $contents);
        $this->assertStringContainsString('Again', $contents);

        $adapter1->close();
        $adapter2->close();

        $this->safeDeleteFile($outputPath1);
        $this->safeDeleteFile($outputPath2);
    }

    /**
     * A message that the log level filters out also clears the exclusion.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/17713
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-31
     */
    public function testLoggerExcludeAdaptersWithFilteredMessage(): void
    {
        $fileName1   = $this->getNewFileName('log', 'log');
        $fileName2   = $this->getNewFileName('log', 'log');
        $outputPath1 = Talon::settings()->outputPath('tests/logs/' . $fileName1);
        $outputPath2 = Talon::settings()->outputPath('tests/logs/' . $fileName2);
        $adapter1    = new Stream($outputPath1);
        $adapter2    = new Stream($outputPath2);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
                'two' => $adapter2,
            ]
        );
        $logger->setLogLevel(Enum::ERROR);

        $logger
            ->excludeAdapters(['two'])
            ->debug('Skipped')
        ;
        $logger->error('After');

        $contents = file_get_contents($outputPath2);
        $this->assertStringNotContainsString('Skipped', $contents);
        $this->assertStringContainsString('After', $contents);

        $adapter1->close();
        $adapter2->close();

        $this->safeDeleteFile($outputPath1);
        $this->safeDeleteFile($outputPath2);
    }
}
