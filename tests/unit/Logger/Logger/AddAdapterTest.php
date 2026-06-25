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

use function file_get_contents;

final class AddAdapterTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAddAdapter(): void
    {
        $fileName1  = $this->getNewFileName('log', 'log');
        $fileName2  = $this->getNewFileName('log', 'log');
        $outputPath1 = logsDir($fileName1);
        $outputPath2 = logsDir($fileName2);
        $adapter1   = new Stream($outputPath1);
        $adapter2   = new Stream($outputPath2);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
            ]
        );

        $expected = 1;
        $actual   = $logger->getAdapters();
        $this->assertCount($expected, $actual);

        $logger->addAdapter('two', $adapter2);
        $expected = 2;
        $actual   = $logger->getAdapters();
        $this->assertCount($expected, $actual);

        $logger->debug('Hello');

        $adapter1->close();
        $adapter2->close();

        $contents = file_get_contents($outputPath1);
        $this->assertStringContainsString('Hello', $contents);
        $this->safeDeleteFile($outputPath1);

        $contents = file_get_contents($outputPath2);
        $this->assertStringContainsString('Hello', $contents);
        $this->safeDeleteFile($outputPath2);
    }
}
