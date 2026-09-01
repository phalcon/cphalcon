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
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class AddColumnTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private const TABLE = 'co_scratch_addcolumn';

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
     * Tests Phalcon\Db\Adapter\Pdo :: addColumn()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-19
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoAddColumn(): void
    {
        $db = $this->container->get('db');

        $column = new Column('extra', [
            'type' => Column::TYPE_INTEGER,
            'size' => 10,
        ]);

        $this->assertTrue($db->addColumn(self::TABLE, '', $column));

        $names = [];
        foreach ($db->describeColumns(self::TABLE) as $col) {
            $names[] = $col->getName();
        }
        $this->assertContains('extra', $names);
    }
}
