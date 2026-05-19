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

use Phalcon\Db\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function env;

final class DropPrimaryKeyTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const TABLE = 'co_scratch_droppk';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);

        // pgsql: Phalcon's dropPrimaryKey hardcodes "<table>_PRIMARY" as the
        // constraint name; pgsql's default for inline PRIMARY KEY is
        // "<table>_pkey", so name the constraint explicitly to match.
        if (env('driver') === 'pgsql') {
            $db->execute(
                'CREATE TABLE ' . self::TABLE
                . ' (id integer NOT NULL, name varchar(50), '
                . 'CONSTRAINT "' . self::TABLE . '_PRIMARY" PRIMARY KEY (id))'
            );
        } else {
            $db->execute(
                'CREATE TABLE ' . self::TABLE
                . ' (id integer NOT NULL PRIMARY KEY, name varchar(50))'
            );
        }
    }

    public function tearDown(): void
    {
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: dropPrimaryKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     */
    public function testDbAdapterPdoDropPrimaryKey(): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->dropPrimaryKey(self::TABLE, ''));

        $primaryColumns = [];
        foreach ($db->describeColumns(self::TABLE) as $col) {
            if ($col->isPrimary()) {
                $primaryColumns[] = $col->getName();
            }
        }
        $this->assertSame([], $primaryColumns);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: dropPrimaryKey() — throws
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoDropPrimaryKeySqlite(): void
    {
        $db = $this->container->get('db');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Removing a primary key after table has been created is not supported by SQLite'
        );

        $db->dropPrimaryKey(self::TABLE, '');
    }
}
