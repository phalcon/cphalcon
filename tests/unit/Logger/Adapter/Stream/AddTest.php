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

final class AddTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterStreamAdd(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir();
        $timezone   = date_default_timezone_get();
        $datetime   = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter    = new Stream($outputPath . $fileName);

        $adapter->begin();
        $item1 = new Item(
            'Message 1',
            'debug',
            Enum::DEBUG,
            $datetime
        );
        $item2 = new Item(
            'Message 2',
            'debug',
            Enum::DEBUG,
            $datetime
        );
        $item3 = new Item(
            'Message 3',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $adapter
            ->add($item1)
            ->add($item2)
            ->add($item3)
        ;

        $this->assertFileDoesNotExist($outputPath . $fileName);

        $adapter->commit();

        $this->assertFileExists($outputPath . $fileName);

        $content = file_get_contents($outputPath . $fileName);
        $this->assertStringContainsString('Message 1', $content);
        $this->assertStringContainsString('Message 2', $content);
        $this->assertStringContainsString('Message 3', $content);

        $adapter->close();
        $this->safeDeleteFile($outputPath . $fileName);
    }
}
