<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Connection;

use DatabaseTester;
use Phalcon\DM\Pdo\Connection;
use Phalcon\DM\Pdo\Profiler\Profiler;

class GetSetProfilerCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: getProfiler()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetProfiler(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - getProfiler()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();

        $I->assertInstanceOf(
            Profiler::class,
            $connection->getProfiler()
        );

        $profiler = new Profiler();
        $connection->setProfiler($profiler);

        $I->assertSame($profiler, $connection->getProfiler());
    }
}
