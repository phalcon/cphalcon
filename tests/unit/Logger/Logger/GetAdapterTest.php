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
use Phalcon\Logger\Exception;
use Phalcon\Logger\Logger;
use Phalcon\Tests\AbstractUnitTestCase;

use function file_get_contents;
use function logsDir;

final class GetAdapterTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerGetAdapter(): void
    {
        $fileName1  = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $adapter1   = new Stream($outputPath . $fileName1);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
            ]
        );


        $class  = Stream::class;
        $actual = $logger->getAdapter('one');
        $this->assertInstanceOf($class, $actual);

        $adapter1->close();
        $this->safeDeleteFile($outputPath . $fileName1);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerGetAdapterForTransaction(): void
    {
        $fileName1  = $this->getNewFileName('log', 'log');
        $fileName2  = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();

        $adapter1 = new Stream($outputPath . $fileName1);
        $adapter2 = new Stream($outputPath . $fileName2);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
                'two' => $adapter2,
            ]
        );

        $logger->info('Logging');

        $logger->getAdapter('two')
               ->begin()
        ;

        $this->assertFalse(
            $logger->getAdapter('one')
                   ->inTransaction()
        );
        $this->assertTrue(
            $logger->getAdapter('two')
                   ->inTransaction()
        );

        $logger->info('Thanks');
        $logger->info('for');
        $logger->info('Phlying');
        $logger->info('with');
        $logger->info('Phalcon');

        $contents = file_get_contents($outputPath . $fileName1);
        $this->assertStringContainsString('Logging', $contents);
        $this->assertStringContainsString('Thanks', $contents);
        $this->assertStringContainsString('for', $contents);
        $this->assertStringContainsString('Phlying', $contents);
        $this->assertStringContainsString('with', $contents);
        $this->assertStringContainsString('Phalcon', $contents);

        $contents = file_get_contents($outputPath . $fileName2);
        $this->assertStringNotContainsString('Thanks', $contents);
        $this->assertStringNotContainsString('for', $contents);
        $this->assertStringNotContainsString('Phlying', $contents);
        $this->assertStringNotContainsString('with', $contents);
        $this->assertStringNotContainsString('Phalcon', $contents);

        $logger->getAdapter('two')
               ->commit()
        ;

        $contents = file_get_contents($outputPath . $fileName2);
        $this->assertStringContainsString('Thanks', $contents);
        $this->assertStringContainsString('for', $contents);
        $this->assertStringContainsString('Phlying', $contents);
        $this->assertStringContainsString('with', $contents);
        $this->assertStringContainsString('Phalcon', $contents);

        $adapter1->close();
        $adapter2->close();

        $this->safeDeleteFile($outputPath . $fileName1);
        $this->safeDeleteFile($outputPath . $fileName2);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerGetAdapterUnknown(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Adapter does not exist for this logger');

        $logger = new Logger('my-logger');
        $logger->getAdapter('unknown');
    }
}
