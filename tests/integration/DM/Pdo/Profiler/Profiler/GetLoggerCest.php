<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\Profiler\Profiler;

use IntegrationTester;
use Phalcon\DM\Pdo\Profiler\MemoryLogger;
use Phalcon\DM\Pdo\Profiler\Profiler;

class GetLoggerCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Profiler\Profiler :: getLogger()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerProfilerGetLogger(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Profiler\Profiler - getLogger()');

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
