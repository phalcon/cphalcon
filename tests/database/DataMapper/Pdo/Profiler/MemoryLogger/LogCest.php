<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Profiler\MemoryLogger;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Profiler\MemoryLogger;
use Phalcon\Logger\LogLevel;

class LogCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Profiler\MemoryLogger :: log()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerMemoryLoggerLog(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Profiler\MemoryLogger - log()');

        $logger = new MemoryLogger();

        $message = "{method} ({duration} seconds): {statement} {backtrace}";
        $context = [
            "method"    => "f1",
            "duration"  => "123",
            "seconds"   => "456",
            "statement" => "select",
            "backtrace" => "backtrace",
        ];

        $logger->log(LogLevel::INFO, $message, $context);

        $expected = ["f1 (123 seconds): select backtrace"];
        $message  = $logger->getMessages();

        $I->assertEquals($expected, $message);
    }
}
