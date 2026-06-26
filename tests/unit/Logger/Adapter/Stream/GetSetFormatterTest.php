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

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetFormatterTest extends AbstractUnitTestCase
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: getFormatter()/setFormatter()
     */
    public function testLoggerAdapterStreamGetSetFormatter(): void
    {
        $fileName = $this->getNewFileName('log', 'log');
        $fileName = logsDir($fileName);

        $adapter = new Stream($fileName);

        $adapter->setFormatter(new Line());
        $actual = $adapter->getFormatter();

        $this->assertInstanceOf(FormatterInterface::class, $actual);

        $adapter->close();
        $this->safeDeleteFile($fileName);
    }
}
