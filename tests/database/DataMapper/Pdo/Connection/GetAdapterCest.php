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

class GetAdapterCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: getAdapter()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetAdapter(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - getAdapter()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();

        $I->assertFalse($connection->isConnected());

        $connection->connect();

        $I->assertTrue($connection->isConnected());
        $I->assertNotEmpty($connection->getAdapter());

        $connection->disconnect();

        $I->assertNotEmpty(
            $connection->getAdapter(),
            'getPdo() will re-connect if disconnected'
        );
        $I->assertTrue($connection->isConnected());
    }
}
