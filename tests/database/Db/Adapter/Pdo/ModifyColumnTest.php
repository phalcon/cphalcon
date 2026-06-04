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

use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class ModifyColumnTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const TABLE = 'co_scratch_modifycolumn';

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
        $db->execute(
            'CREATE TABLE ' . self::TABLE . ' (id integer primary key, name varchar(50))'
        );
    }

    public function tearDown(): void
    {
        $db = $this->container->get('db');
        $db->execute('DROP TABLE IF EXISTS ' . self::TABLE);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: modifyColumn()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group mysql
     * @group pgsql
     */
    public function testDbAdapterPdoModifyColumn(): void
    {
        $db = $this->container->get('db');

        $current = new Column('name', [
            'type' => Column::TYPE_VARCHAR,
            'size' => 50,
        ]);
        $newColumn = new Column('name', [
            'type' => Column::TYPE_TEXT,
        ]);

        $this->assertTrue($db->modifyColumn(self::TABLE, '', $newColumn, $current));

        foreach ($db->describeColumns(self::TABLE) as $col) {
            if ($col->getName() === 'name') {
                $this->assertSame(Column::TYPE_TEXT, $col->getType());
                return;
            }
        }
        $this->fail('Column "name" not found after modifyColumn');
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: modifyColumn() — throws
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoModifyColumnSqlite(): void
    {
        $db = $this->container->get('db');

        $newColumn = new Column('name', [
            'type' => Column::TYPE_TEXT,
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Altering a DB column is not supported by SQLite');

        $db->modifyColumn(self::TABLE, '', $newColumn);
    }
}
