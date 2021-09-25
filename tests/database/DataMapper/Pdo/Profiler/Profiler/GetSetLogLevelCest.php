<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Profiler\Profiler;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Profiler\Profiler;
use Psr\Log\LogLevel;

class GetSetLogLevelCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Profiler\Profiler ::
     * getLogLevel()/setLogLevel()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerProfilerGetSetLogLevel(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Profiler\Profiler - getLogLevel()/setLogLevel()');

        $profiler = new Profiler();

        $I->assertEquals(
            LogLevel::DEBUG,
            $profiler->getLogLevel()
        );

        $profiler->setLogLevel(LogLevel::INFO);
        $I->assertEquals(
            LogLevel::INFO,
            $profiler->getLogLevel()
        );
    }
}
