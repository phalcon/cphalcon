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

class ConnectDisconnectIsConnectedCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection ::
     * connect()/disconnect()/isConnected()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionConnectDisconnectIsConnected(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - connect()/disconnect()/isConnected()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();

        $I->assertFalse($connection->isConnected());
        $connection->connect();
        $I->assertTrue($connection->isConnected());
        $connection->disconnect();
        $I->assertFalse($connection->isConnected());
    }

    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: connect() - queries
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionConnectQueries(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - connect() - queries');

        if ('mysql' === $I->getDriver()) {
            /** @var Connection $connection */
            $connection = new Connection(
                $I->getDatabaseDsn(),
                $I->getDatabaseUsername(),
                $I->getDatabasePassword(),
                [],
                [
                    'set names big5',
                ]
            );

            $I->assertFalse($connection->isConnected());
            $result = $connection->fetchOne(
                'show variables like "character_set_client"'
            );

            $I->assertTrue($connection->isConnected());
            $expected = [
                'Variable_name' => 'character_set_client',
                'Value'         => 'big5',
            ];

            $I->assertEquals($expected, $result);
        }
    }
}
