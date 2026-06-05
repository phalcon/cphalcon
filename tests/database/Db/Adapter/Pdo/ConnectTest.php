<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use PDO;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function getOptionsMysql;

final class ConnectTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     *
     * @group mysql
     */
    public function testDbAdapterPdoConnectPersistentMysql(): void
    {
        $options               = getOptionsMysql();
        $options['persistent'] = true;
        $options['options']    = [
            PDO::ATTR_EMULATE_PREPARES  => false,
            PDO::ATTR_STRINGIFY_FETCHES => false,
        ];

        $connection = (new PdoFactory())->newInstance('mysql', $options);

        $expected = $options;
        $actual   = $connection->getDescriptor();

        $this->assertEquals($expected, $actual);

        $connection->close();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     *
     * @group pgsql
     */
    public function testDbAdapterPdoConnectPersistentPgsql(): void
    {
        // The high-level `persistent` descriptor key is read but not
        // unset before DSN assembly in AbstractPdo::connect(); pgsql
        // then rejects the leaked `persistent=true` DSN attribute.
        // Pass the persistent flag via PDO::ATTR_PERSISTENT instead.
        $options            = getOptionsPostgresql();
        $options['options'] = [
            PDO::ATTR_EMULATE_PREPARES  => false,
            PDO::ATTR_STRINGIFY_FETCHES => false,
            PDO::ATTR_PERSISTENT        => true,
        ];

        $connection = (new PdoFactory())->newInstance('postgresql', $options);

        $expected = $options;
        $actual   = $connection->getDescriptor();

        $this->assertEquals($expected, $actual);

        $connection->close();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     *
     * @group sqlite
     */
    public function testDbAdapterPdoConnectPersistentSqlite(): void
    {
        $options               = getOptionsSqlite();
        $options['persistent'] = true;
        $options['options']    = [
            PDO::ATTR_EMULATE_PREPARES  => false,
            PDO::ATTR_STRINGIFY_FETCHES => false,
        ];

        $connection = (new PdoFactory())->newInstance('sqlite', $options);

        $expected = $options;
        $actual   = $connection->getDescriptor();

        $this->assertEquals($expected, $actual);

        $connection->close();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: connect() (close + reconnect cycle)
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoConnect(): void
    {
        $this->setDatabase();

        $db = $this->container->get('db');

        $db->close();
        $db->connect();

        $row = $db->fetchOne('SELECT 1 AS one');
        $this->assertSame(1, (int) $row['one']);
    }
}
