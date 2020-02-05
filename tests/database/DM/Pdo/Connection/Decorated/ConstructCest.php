<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Connection\Decorated;

use DatabaseTester;
use PDO;
use Phalcon\DM\Pdo\Connection\Decorated;
use Phalcon\DM\Pdo\Profiler\Profiler;

class ConstructCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection\Decorated :: __construct()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionDecoratedConstruct(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection\Decorated - __construct()');

        $connection = new PDO(
            $I->getDatabaseDsn(),
            $I->getDatabaseUsername(),
            $I->getDatabasePassword()
        );

        $decorated = new Decorated($connection);
        $decorated->connect();

        $I->assertTrue($decorated->isConnected());
        $I->assertInstanceOf(Profiler::class, $decorated->getProfiler());
        $I->assertSame($connection, $decorated->getAdapter());
    }
}
