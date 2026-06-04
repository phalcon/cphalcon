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

final class DropForeignKeyTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const PARENT = 'co_scratch_dropfk_parent';
    private const CHILD  = 'co_scratch_dropfk_child';
    private const FK     = 'co_scratch_dropfk_fk';

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

        // SQLite does not support ALTER TABLE ADD CONSTRAINT, so the child
        // table is created with the FK inline. mysql/pgsql accept the same
        // inline form.
        $db->execute(
            'CREATE TABLE ' . self::CHILD
            . ' (id integer primary key, parent_id integer, '
            . 'CONSTRAINT ' . self::FK . ' FOREIGN KEY (parent_id) '
            . 'REFERENCES ' . self::PARENT . ' (id))' . $engineSuffix
        );
    }

    public function tearDown(): void
    {
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::CHILD);
        $db->execute('DROP TABLE IF EXISTS ' . self::PARENT);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: dropForeignKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     */
    public function testDbAdapterPdoDropForeignKey(): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->dropForeignKey(self::CHILD, '', self::FK));

        foreach ($db->describeReferences(self::CHILD) as $ref) {
            $this->assertNotSame(
                self::PARENT,
                $ref->getReferencedTable(),
                'Reference to parent still present after dropForeignKey'
            );
        }
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: dropForeignKey() — throws
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoDropForeignKeySqlite(): void
    {
        $db = $this->container->get('db');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Dropping a foreign key constraint is not supported by SQLite'
        );

        $db->dropForeignKey(self::CHILD, '', self::FK);
    }
}
