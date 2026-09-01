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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Profiler\MemoryLogger;

use Phalcon\DataMapper\Pdo\Profiler\MemoryLogger;
use Phalcon\Logger\Enum;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class LogTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoProfilerMemoryLoggerLog(): void
    {
        $logger = new MemoryLogger();

        $message = "{method} ({duration} seconds): {statement} {backtrace}";
        $context = [
            "method"    => "f1",
            "duration"  => "123",
            "seconds"   => "456",
            "statement" => "select",
            "backtrace" => "backtrace",
        ];

        $logger->log(Enum::INFO, $message, $context);

        $expected = ["f1 (123 seconds): select backtrace"];
        $message  = $logger->getMessages();

        $this->assertEquals($expected, $message);
    }
}
