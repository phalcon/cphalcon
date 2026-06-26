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

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function env;

final class SetDialectTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: setDialect()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoSetDialect(): void
    {
        $db = $this->container->get('db');

        $newDialect = match (env('driver')) {
            'mysql'  => new Mysql(),
            'pgsql'  => new Postgresql(),
            'sqlite' => new Sqlite(),
        };

        $db->setDialect($newDialect);
        $this->assertSame($newDialect, $db->getDialect());
    }
}
