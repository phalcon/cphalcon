<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class ConnectDisconnectIsConnectedTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDMPdoConnectionConnectDisconnectIsConnected(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();

        $this->assertFalse($connection->isConnected());
        $connection->connect();
        $this->assertTrue($connection->isConnected());
        $connection->disconnect();
        $this->assertFalse($connection->isConnected());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    #[Group('mysql')]
    public function testDMPdoConnectionConnectQueries(): void
    {
        if ('mysql' === self::getDriver()) {
            /** @var Connection $connection */
            $connection = new Connection(
                self::getDatabaseDsn(),
                self::getDatabaseUsername(),
                self::getDatabasePassword(),
                [],
                [
                    'set names big5',
                ]
            );

            $this->assertFalse($connection->isConnected());
            $result = $connection->fetchOne(
                'show variables like "character_set_client"'
            );

            $this->assertTrue($connection->isConnected());
            $expected = [
                'Variable_name' => 'character_set_client',
                'Value'         => 'big5',
            ];

            $this->assertSame($expected, $result);
        }
    }
}
