<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\Connection;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\DataMapper\Pdo\Profiler\Profiler;

class GetSetProfilerCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: getProfiler()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetProfiler(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - getProfiler()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();

        $I->assertInstanceOf(
            Profiler::class,
            $connection->getProfiler()
        );

        $profiler = new Profiler();
        $connection->setProfiler($profiler);

        $I->assertSame($profiler, $connection->getProfiler());
    }
}
