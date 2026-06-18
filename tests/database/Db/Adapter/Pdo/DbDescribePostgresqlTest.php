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

final class DbDescribePostgresqlTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Db :: Postgresql - describeColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('pgsql')]
    public function testDbPostgresqlDescribeColumns(): void
    {
        $db = $this->container->get('db');

        $expected = $this->getExpectedColumnsPostgresql();

        $this->assertEquals($expected, $db->describeColumns('personas'));
        $this->assertEquals($expected, $db->describeColumns('personas', 'public'));
    }

    /**
     * Tests Phalcon\Db :: Postgresql - describeIndexes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('pgsql')]
    public function testDbPostgresqlDescribeIndexes(): void
    {
        $db = $this->container->get('db');

        $indexes = $db->describeIndexes('co_invoices');

        $this->assertArrayHasKey('co_invoices_pk', $indexes);
        $this->assertSame(['inv_id'], $indexes['co_invoices_pk']->getColumns());
    }

    /**
     * Tests Phalcon\Db :: Postgresql - describeReferences()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('pgsql')]
    public function testDbPostgresqlDescribeReferences(): void
    {
        $db = $this->container->get('db');

        $references = $db->describeReferences('foreign_key_child');

        $this->assertNotEmpty($references);
        $this->assertArrayHasKey('test_describereferences', $references);

        $ref = $references['test_describereferences'];
        $this->assertSame('foreign_key_parent', $ref->getReferencedTable());
        $this->assertSame(['child_int'], $ref->getColumns());
        $this->assertSame(['refer_int'], $ref->getReferencedColumns());
    }

    /**
     * @return array<int, Column>
     */
    private function getExpectedColumnsPostgresql(): array
    {
        return [
            0 => new Column(
                'cedula',
                [
                    'type'          => 5,
                    'isNumeric'     => false,
                    'size'          => 15,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'primary'       => true,
                    'first'         => true,
                    'after'         => null,
                    'bindType'      => 2,
                ]
            ),
            1 => new Column(
                'tipo_documento_id',
                [
                    'type'          => 22,
                    'isNumeric'     => true,
                    'size'          => 0,
                    'scale'         => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'cedula',
                    'bindType'      => 1,
                ]
            ),
            2 => new Column(
                'nombres',
                [
                    'type'          => 2,
                    'isNumeric'     => false,
                    'size'          => 100,
                    'default'       => '',
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'tipo_documento_id',
                    'bindType'      => 2,
                ]
            ),
            3 => new Column(
                'telefono',
                [
                    'type'          => 2,
                    'isNumeric'     => false,
                    'size'          => 20,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'nombres',
                    'bindType'      => 2,
                ]
            ),
            4 => new Column(
                'cupo',
                [
                    'type'          => 3,
                    'isNumeric'     => true,
                    'size'          => 16,
                    'scale'         => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'telefono',
                    'bindType'      => 32,
                ]
            ),
            5 => new Column(
                'estado',
                [
                    'type'          => 5,
                    'isNumeric'     => false,
                    'size'          => 1,
                    'default'       => 'A',
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'cupo',
                    'bindType'      => 2,
                ]
            ),
        ];
    }
}
