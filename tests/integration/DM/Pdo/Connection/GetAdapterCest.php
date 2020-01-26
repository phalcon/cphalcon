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

class GetAdapterCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: getAdapter()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetAdapter(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - getAdapter()');

        /** @var Connection $connection */
        $connection = $I->getConnection();

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
