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

use Phalcon\Logger\Enum;
use Phalcon\Logger\Logger;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetLogLevelTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerGetSetLogLevel(): void
    {
        $logger = new Logger('my-name');

        $this->assertSame(Enum::CUSTOM, $logger->getLogLevel());

        $object = $logger->setLogLevel(Enum::INFO);
        $this->assertInstanceOf(Logger::class, $object);

        $this->assertSame(Enum::INFO, $logger->getLogLevel());

        $logger->setLogLevel(99);
        $this->assertSame(Enum::CUSTOM, $logger->getLogLevel());
    }
}
