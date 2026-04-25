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

namespace Phalcon\Tests\Database\Db\Adapter\PdoFactory;

use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;

use function getOptionsMysql;
use function getOptionsPostgresql;
use function getOptionsSqlite;

final class NewInstanceTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group mysql
     */
    public function testDbAdapterPdoFactoryNewInstanceMysql(): void
    {
        $factory = new PdoFactory();
        $adapter = $factory->newInstance('mysql', getOptionsMysql());

        $this->assertInstanceOf(Mysql::class, $adapter);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group pgsql
     */
    public function testDbAdapterPdoFactoryNewInstancePgsql(): void
    {
        $factory = new PdoFactory();
        $adapter = $factory->newInstance('postgresql', getOptionsPostgresql());

        $this->assertInstanceOf(Postgresql::class, $adapter);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoFactoryNewInstanceSqlite(): void
    {
        $factory = new PdoFactory();
        $adapter = $factory->newInstance('sqlite', getOptionsSqlite());

        $this->assertInstanceOf(Sqlite::class, $adapter);
    }
}
