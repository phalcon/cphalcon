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
use Phalcon\Logger\Logger;
use Phalcon\Tests\AbstractUnitTestCase;

use function file_exists;
use function file_get_contents;
use function logsDir;
use function uniqid;

final class TransactionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testLoggerTransactionCommitFlushesQueue(): void
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

        $message = uniqid('msg-');

        $logger->begin();
        $logger->info($message);

        /**
         * Inside a transaction the message is queued, not yet written (the
         * stream is not even opened until the first real write).
         */
        $contents = file_exists($outputPath)
            ? (string) file_get_contents($outputPath)
            : '';
        $this->assertStringNotContainsString($message, $contents);

        $logger->commit();

        /**
         * commit() flushes the queued message to the stream.
         */
        $contents = file_exists($outputPath)
            ? (string) file_get_contents($outputPath)
            : '';
        $this->assertStringContainsString($message, $contents);

        $adapter->close();
        $this->safeDeleteFile($outputPath);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testLoggerTransactionRollbackDiscardsQueue(): void
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

        $message = uniqid('msg-');

        $logger->begin();
        $logger->info($message);
        $logger->rollback();

        /**
         * rollback() discards the queue and closes the transaction, so a fresh
         * begin()/commit() writes nothing and the message never reaches the
         * stream.
         */
        $logger->begin();
        $logger->commit();

        $contents = file_exists($outputPath)
            ? (string) file_get_contents($outputPath)
            : '';
        $this->assertStringNotContainsString($message, $contents);

        $adapter->close();
        $this->safeDeleteFile($outputPath);
    }
}
