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
use Phalcon\Db\Index;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class AddPrimaryKeyTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const TABLE = 'co_scratch_addpk';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
        // No PRIMARY KEY on the scratch table - addPrimaryKey will add one.
        $db->execute(
            'CREATE TABLE ' . self::TABLE . ' (id integer NOT NULL, name varchar(50))'
        );
    }

    public function tearDown(): void
    {
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: addPrimaryKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     */
    public function testDbAdapterPdoAddPrimaryKey(): void
    {
        $db = $this->container->get('db');

        $index = new Index('PRIMARY', ['id']);

        $this->assertTrue($db->addPrimaryKey(self::TABLE, '', $index));

        $hasPrimary = false;
        foreach ($db->describeColumns(self::TABLE) as $col) {
            if ($col->getName() === 'id' && $col->isPrimary()) {
                $hasPrimary = true;
            }
        }
        $this->assertTrue($hasPrimary, 'Column "id" not marked primary after addPrimaryKey');
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: addPrimaryKey() - throws
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoAddPrimaryKeySqlite(): void
    {
        $db = $this->container->get('db');

        $index = new Index('PRIMARY', ['id']);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Adding a primary key after table has been created is not supported by SQLite'
        );

        $db->addPrimaryKey(self::TABLE, '', $index);
    }
}
