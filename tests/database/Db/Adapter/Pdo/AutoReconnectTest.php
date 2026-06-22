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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use PDOException;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class AutoReconnectTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: auto-reconnect retries once
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDbAdapterPdoAutoReconnectRetries(): void
    {
        $db = $this->container->get('db');
        $db->setAutoReconnect(true);

        $this->killConnection($db);

        $result = $db->query('SELECT 1 AS num');
        $row    = $result->fetch();

        $this->assertEquals(1, (int) $row['num']);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: db:connectionLost event fires
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDbAdapterPdoConnectionLostEventFires(): void
    {
        $db      = $this->container->get('db');
        $manager = new Manager();
        $fired   = false;

        $manager->attach(
            'db:connectionLost',
            function (Event $event, $connection) use (&$fired) {
                $fired = true;
            }
        );

        $db->setEventsManager($manager);
        $db->setAutoReconnect(true);

        $this->killConnection($db);
        $db->query('SELECT 1 AS num');

        $this->assertTrue($fired);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: no retry inside a transaction
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDbAdapterPdoNoRetryInsideTransaction(): void
    {
        $db = $this->container->get('db');
        $db->setAutoReconnect(true);

        $db->begin();
        $this->killConnection($db);

        $this->expectException(PDOException::class);

        $db->execute('SELECT 1');
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: auto-reconnect is a no-op on sqlite
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-20
     */
    #[Group('sqlite')]
    public function testDbAdapterPdoAutoReconnectSqliteNoop(): void
    {
        $db = $this->container->get('db');
        $db->setAutoReconnect(true);

        $result = $db->query('SELECT 1 AS num');
        $row    = $result->fetch();

        $this->assertEquals(1, (int) $row['num']);
    }

    /**
     * Kills $db's own server-side connection from a separate adapter so the
     * next query on $db hits a "gone away" condition.
     */
    private function killConnection($db): void
    {
        $driver = $db->getType();

        if ($driver === 'mysql') {
            $connectionId = (int) $db->fetchColumn('SELECT CONNECTION_ID()');
            $killer       = new Mysql($db->getDescriptor());
            $killer->execute('KILL ' . $connectionId);
            $killer->close();

            return;
        }

        $pid    = (int) $db->fetchColumn('SELECT pg_backend_pid()');
        $killer = new Postgresql($db->getDescriptor());
        $killer->execute('SELECT pg_terminate_backend(' . $pid . ')');
        $killer->close();
    }
}
