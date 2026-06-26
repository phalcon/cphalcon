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

use function env;

final class DbDescribeMysqlTest extends AbstractDatabaseTestCase
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
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db :: Mysql - describeColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    public function testDbMySqlDescribeColumns(): void
    {
        $db = $this->container->get('db');

        $expected = $this->getExpectedColumnsMysql();

        $this->assertEquals($expected, $db->describeColumns('personas'));
        $this->assertEquals($expected, $db->describeColumns('personas', env('DATA_MYSQL_NAME')));
    }

    /**
     * Tests Phalcon\Db :: Mysql - describeIndexes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    public function testDbMySqlDescribeIndexes(): void
    {
        $db = $this->container->get('db');

        $indexes = $db->describeIndexes('co_invoices');

        $this->assertArrayHasKey('PRIMARY', $indexes);
        $this->assertSame(['inv_id'], $indexes['PRIMARY']->getColumns());
        $this->assertSame('PRIMARY', $indexes['PRIMARY']->getType());
    }

    /**
     * Tests Phalcon\Db :: Mysql - describeReferences()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    public function testDbMySqlDescribeReferences(): void
    {
        // mysql test schema does not currently define any FK constraints
        // we can exercise; assert the call returns an array shape on a
        // table that has no references.
        $db = $this->container->get('db');

        $this->assertSame([], $db->describeReferences('personas'));
    }

    /**
     * Tests Phalcon\Db :: Mysql - tableExists()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    public function testDbMySqlTableExists(): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->tableExists('co_invoices'));
        $this->assertFalse($db->tableExists('noexist'));
        $this->assertTrue($db->tableExists('co_invoices', env('DATA_MYSQL_NAME')));
        $this->assertFalse($db->tableExists('co_invoices', 'test'));
    }

    /**
     * Tests Phalcon\Db :: Mysql - tableOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('mysql')]
    public function testDbMySqlTableOptions(): void
    {
        $db = $this->container->get('db');

        $options = $db->tableOptions('personas');

        $this->assertSame('BASE TABLE', $options['table_type']);
        $this->assertSame('InnoDB', $options['engine']);
        $this->assertNotEmpty($options['table_collation']);
    }

    /**
     * @return array<int, Column>
     */
    private function getExpectedColumnsMysql(): array
    {
        return [
            0 => new Column(
                'cedula',
                [
                    'type'          => Column::TYPE_CHAR,
                    'isNumeric'     => false,
                    'size'          => 15,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'primary'       => true,
                    'first'         => true,
                    'after'         => null,
                    'bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            1 => new Column(
                'tipo_documento_id',
                [
                    'type'          => Column::TYPE_INTEGER,
                    'isNumeric'     => true,
                    'size'          => 0,
                    'scale'         => 0,
                    'default'       => null,
                    'unsigned'      => true,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'cedula',
                    'bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            2 => new Column(
                'nombres',
                [
                    'type'          => Column::TYPE_VARCHAR,
                    'isNumeric'     => false,
                    'size'          => 100,
                    'default'       => '',
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'tipo_documento_id',
                    'bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            3 => new Column(
                'telefono',
                [
                    'type'          => Column::TYPE_VARCHAR,
                    'isNumeric'     => false,
                    'size'          => 20,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'nombres',
                    'bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            4 => new Column(
                'cupo',
                [
                    'type'          => Column::TYPE_DECIMAL,
                    'isNumeric'     => true,
                    'size'          => 16,
                    'scale'         => 2,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'telefono',
                    'bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            5 => new Column(
                'estado',
                [
                    'type'          => Column::TYPE_ENUM,
                    'isNumeric'     => false,
                    'size'          => "'A','I','X'",
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'cupo',
                    'bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
        ];
    }
}
