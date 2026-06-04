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
use Phalcon\Db\Reference;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function env;

final class AddForeignKeyTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const PARENT = 'co_scratch_addfk_parent';
    private const CHILD  = 'co_scratch_addfk_child';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $db = $this->container->get('db');

        $db->execute('DROP TABLE IF EXISTS ' . self::CHILD);
        $db->execute('DROP TABLE IF EXISTS ' . self::PARENT);

        $engineSuffix = env('driver') === 'mysql' ? ' ENGINE=InnoDB' : '';
        $db->execute(
            'CREATE TABLE ' . self::PARENT
            . ' (id integer primary key, name varchar(50))' . $engineSuffix
        );
        $db->execute(
            'CREATE TABLE ' . self::CHILD
            . ' (id integer primary key, parent_id integer)' . $engineSuffix
        );
    }

    public function tearDown(): void
    {
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::CHILD);
        $db->execute('DROP TABLE IF EXISTS ' . self::PARENT);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: addForeignKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     */
    public function testDbAdapterPdoAddForeignKey(): void
    {
        $db = $this->container->get('db');

        $reference = new Reference('co_scratch_addfk_fk', [
            'referencedTable'   => self::PARENT,
            'columns'           => ['parent_id'],
            'referencedColumns' => ['id'],
        ]);

        $this->assertTrue($db->addForeignKey(self::CHILD, '', $reference));

        $found = false;
        foreach ($db->describeReferences(self::CHILD) as $ref) {
            if ($ref->getReferencedTable() === self::PARENT) {
                $this->assertSame(['parent_id'], $ref->getColumns());
                $this->assertSame(['id'], $ref->getReferencedColumns());
                $found = true;
            }
        }
        $this->assertTrue($found, 'No reference from child to parent reported');
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: addForeignKey() — throws
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoAddForeignKeySqlite(): void
    {
        $db = $this->container->get('db');

        $reference = new Reference('co_scratch_addfk_fk', [
            'referencedTable'   => self::PARENT,
            'columns'           => ['parent_id'],
            'referencedColumns' => ['id'],
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Adding a foreign key constraint to an existing table is not supported by SQLite'
        );

        $db->addForeignKey(self::CHILD, '', $reference);
    }
}
