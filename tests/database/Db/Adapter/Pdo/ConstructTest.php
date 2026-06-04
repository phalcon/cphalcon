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

use PDO;
use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function env;
use function getOptionsMysql;
use function getOptionsPostgresql;
use function getOptionsSqlite;

final class ConstructTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoConstruct(): void
    {
        $driver = env('driver');

        $adapter = match ($driver) {
            'mysql'  => new Mysql(getOptionsMysql()),
            'pgsql'  => new Postgresql(getOptionsPostgresql()),
            'sqlite' => new Sqlite(getOptionsSqlite()),
        };

        $this->assertInstanceOf(AdapterInterface::class, $adapter);
        $this->assertInstanceOf(PDO::class, $adapter->getInternalHandler());
    }
}
