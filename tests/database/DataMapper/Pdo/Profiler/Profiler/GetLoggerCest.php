<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\Profiler\Profiler;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Profiler\MemoryLogger;
use Phalcon\DataMapper\Pdo\Profiler\Profiler;

class GetLoggerCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Profiler\Profiler :: getLogger()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerProfilerGetLogger(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Profiler\Profiler - getLogger()');

        $profile = new Profiler();
        $logger  = $profile->getLogger();

        $I->assertInstanceOf(MemoryLogger::class, $logger);

        $newLogger = new MemoryLogger();
        $profile   = new Profiler($newLogger);

        $logger = $profile->getLogger();
        $I->assertInstanceOf(MemoryLogger::class, $logger);
        $I->assertEquals($newLogger, $logger);
    }
}
