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
use Phalcon\Logger\Item;
use Phalcon\Tests\AbstractUnitTestCase;

use function date_default_timezone_get;
use function file_get_contents;

final class DestructTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17155
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-15
     */
    public function testLoggerAdapterStreamDestructCommitsOpenTransaction(): void
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

        $adapter->begin();
        $adapter->add($item);

        /**
         * Destruction with an open transaction auto-commits, flushing the
         * queued items instead of throwing.
         */
        unset($adapter);

        $this->assertFileExists($outputPath . $fileName);

        $contents = file_get_contents($outputPath . $fileName);
        $this->assertStringContainsString('Message 1', $contents);

        $this->safeDeleteFile($outputPath . $fileName);
    }
}
