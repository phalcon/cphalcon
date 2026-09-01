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

use PDOException;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class AutoReconnectTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\DataMapper\Pdo\Connection :: auto-reconnect retries once
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDMPdoConnectionAutoReconnectRetries(): void
    {
        $connection = $this->newConnection();
        $connection->setAutoReconnect(true);

        $this->killConnection($connection);

        $this->assertEquals(1, (int) $connection->fetchValue('SELECT 1'));
    }

    /**
     * Tests Phalcon\DataMapper\Pdo\Connection :: no retry inside a transaction
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDMPdoConnectionNoRetryInsideTransaction(): void
    {
        $connection = $this->newConnection();
        $connection->setAutoReconnect(true);

        $connection->beginTransaction();
        $this->killConnection($connection);

        $this->expectException(PDOException::class);

        $connection->exec('SELECT 1');
    }

    private function killConnection(Connection $connection): void
    {
        $driver = $connection->getDriverName();
        $killer = $this->newConnection();

        if ($driver === 'mysql') {
            $id = (int) $connection->fetchValue('SELECT CONNECTION_ID()');
            $killer->exec('KILL ' . $id);
        } else {
            $pid = (int) $connection->fetchValue('SELECT pg_backend_pid()');
            $killer->exec('SELECT pg_terminate_backend(' . $pid . ')');
        }

        $killer->disconnect();
    }

    private function newConnection(): Connection
    {
        return new Connection(
            self::getDatabaseDsn(),
            self::getDatabaseUsername(),
            self::getDatabasePassword()
        );
    }
}
