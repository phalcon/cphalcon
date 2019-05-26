<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DbDescribeSqliteCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiSqlite();
    }

    /**
     * Tests Phalcon\Db :: Sqlite
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbSqliteListTables(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedTables = [
            'COMPANY',
            'customers',
            'm2m_parts',
            'm2m_robots',
            'm2m_robots_parts',
            'parts',
            'personas',
            'personnes',
            'ph_select',
            'prueba',
            'robots',
            'robots_parts',
            'sqlite_sequence',
            'subscriptores',
            'table_with_string_field',
            'tipo_documento',
        ];

        $I->assertEquals(
            $expectedTables,
            $connection->listTables()
        );

        $I->assertEquals(
            $expectedTables,
            $connection->listTables('public')
        );
    }

    /**
     * Tests Phalcon\Db :: Sqlite
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbSqliteTableExists(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $I->assertTrue(
            $connection->tableExists('personas')
        );

        $I->assertFalse(
            $connection->tableExists('noexist')
        );

        $I->assertTrue(
            $connection->tableExists('personas', 'public')
        );

        $I->assertTrue(
            $connection->tableExists('personas', 'test')
        );
    }

    /**
     * Tests Phalcon\Db :: Sqlite
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbSqliteDescribeColumns(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedDescribe = $this->getExpectedColumnsSqlite();

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas')
        );

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas', 'main')
        );
    }

    /**
     * Tests Phalcon\Db :: Sqlite
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbSqliteDescribeIndexes(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedIndexes = [
            'sqlite_autoindex_COMPANY_1' => Index::__set_state(
                [
                    'name'    => 'sqlite_autoindex_COMPANY_1',
                    'columns' => ['ID'],
                    'type'    => 'PRIMARY',
                ]
            ),
            'salary_index'               => Index::__set_state(
                [
                    'name'    => 'salary_index',
                    'columns' => ['SALARY'],
                ]
            ),
            'name_index'                 => Index::__set_state(
                [
                    'name'    => 'name_index',
                    'columns' => ['NAME'],
                    'type'    => 'UNIQUE',
                ]
            ),
        ];

        $I->assertEquals(
            $expectedIndexes,
            $connection->describeIndexes('COMPANY')
        );

        $I->assertEquals(
            $expectedIndexes,
            $connection->describeIndexes('company', 'main')
        );
    }

    /**
     * Tests Phalcon\Db :: Sqlite
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbSqliteDescribeReferences(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedReferences = [
            'foreign_key_0' => Reference::__set_state(
                [
                    'referenceName'     => 'foreign_key_0',
                    'referencedTable'   => 'parts',
                    'columns'           => ['parts_id'],
                    'referencedColumns' => ['id'],
                    'referencedSchema'  => null,
                ]
            ),
            'foreign_key_1' => Reference::__set_state(
                [
                    'referenceName'     => 'foreign_key_1',
                    'referencedTable'   => 'robots',
                    'columns'           => ['robots_id'],
                    'referencedColumns' => ['id'],
                    'referencedSchema'  => null,
                ]
            ),
        ];

        $I->assertEquals(
            $expectedReferences,
            $connection->describeReferences('robots_parts')
        );
    }

    private function getExpectedColumnsSqlite(): array
    {
        return [
            0  => Column::__set_state([
                'columnName'    => 'cedula',
                'schemaName'    => null,
                'type'          => 5,
                'isNumeric'     => false,
                'size'          => 15,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => true,
                'autoIncrement' => false,
                'primary'       => true,
                'first'         => true,
                'after'         => null,
                'bindType'      => 2,
            ]),
            1  => Column::__set_state([
                'columnName'    => 'tipo_documento_id',
                'schemaName'    => null,
                'type'          => 0,
                'isNumeric'     => true,
                'size'          => 3,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => true,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'cedula',
                'bindType'      => 1,
            ]),
            2  => Column::__set_state([
                'columnName'    => 'nombres',
                'schemaName'    => null,
                'type'          => 2,
                'isNumeric'     => false,
                'size'          => 100,
                'scale'         => 0,
                'default'       => '',
                'unsigned'      => false,
                'notNull'       => true,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'tipo_documento_id',
                'bindType'      => 2,
            ]),
            3  => Column::__set_state([
                'columnName'    => 'telefono',
                'schemaName'    => null,
                'type'          => 2,
                'isNumeric'     => false,
                'size'          => 20,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'nombres',
                'bindType'      => 2,
            ]),
            4  => Column::__set_state([
                'columnName'    => 'direccion',
                'schemaName'    => null,
                'type'          => 2,
                'isNumeric'     => false,
                'size'          => 100,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'telefono',
                'bindType'      => 2,
            ]),
            5  => Column::__set_state([
                'columnName'    => 'email',
                'schemaName'    => null,
                'type'          => 2,
                'isNumeric'     => false,
                'size'          => 50,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'direccion',
                'bindType'      => 2,
            ]),
            6  => Column::__set_state([
                'columnName'    => 'fecha_nacimiento',
                'schemaName'    => null,
                'type'          => 1,
                'isNumeric'     => false,
                'size'          => 0,
                'scale'         => 0,
                'default'       => '1970-01-01',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'email',
                'bindType'      => 2,
            ]),
            7  => Column::__set_state([
                'columnName'    => 'ciudad_id',
                'schemaName'    => null,
                'type'          => 0,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => '0',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'fecha_nacimiento',
                'bindType'      => 1,
            ]),
            8  => Column::__set_state([
                'columnName'    => 'creado_at',
                'schemaName'    => null,
                'type'          => 1,
                'isNumeric'     => false,
                'size'          => 0,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'ciudad_id',
                'bindType'      => 2,
            ]),
            9  => Column::__set_state([
                'columnName'    => 'cupo',
                'schemaName'    => null,
                'type'          => 3,
                'isNumeric'     => true,
                'size'          => 16,
                'scale'         => 2,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => true,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'creado_at',
                'bindType'      => 32,
            ]),
            10 => Column::__set_state([
                'columnName'    => 'estado',
                'schemaName'    => null,
                'type'          => 5,
                'isNumeric'     => false,
                'size'          => 1,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => true,
                'autoIncrement' => false,
                'first'         => false,
                'after'         => 'cupo',
                'bindType'      => 2,
            ]),
        ];
    }
}
