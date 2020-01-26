<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\Connection;

use IntegrationTester;
use Phalcon\DM\Pdo\Connection;
use Phalcon\DM\Pdo\Profiler\Profiler;

class GetSetProfilerCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: getProfiler()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetProfiler(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - getProfiler()');

        /** @var Connection $connection */
        $connection = $I->getConnection();

        $I->assertInstanceOf(
            Profiler::class,
            $connection->getProfiler()
        );

        $profiler = new Profiler();
        $connection->setProfiler($profiler);

        $I->assertSame($profiler, $connection->getProfiler());
    }
}
