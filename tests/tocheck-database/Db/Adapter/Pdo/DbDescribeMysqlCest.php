<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class DbDescribeMysqlCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Db :: Mysql
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbMySqlTableExists(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $I->assertTrue(
            $connection->tableExists('personas')
        );

        $I->assertFalse(
            $connection->tableExists('noexist')
        );

        $I->assertTrue(
            $connection->tableExists('personas', env('DATA_MYSQL_NAME'))
        );

        $I->assertFalse(
            $connection->tableExists('personas', 'test')
        );
    }

    /**
     * Tests Phalcon\Db :: Mysql
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbMySqlDescribeColumns(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        /**
         * @TODO - Check this after refactoring
         */
//        $expectedDescribe = $this->getExpectedColumnsMysql();
//        $describe         = $connection->describeColumns('personas');
//        $I->assertEquals($expectedDescribe, $describe);

//        $describe = $connection->describeColumns('personas', env('DATA_MYSQL_NAME'));
//        $I->assertEquals($describe, $expectedDescribe);
    }

    /**
     * Tests Phalcon\Db :: Mysql
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbMySqlTableOptions(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedOptions = [
            'table_type'      => 'BASE TABLE',
            'auto_increment'  => null,
            'engine'          => 'InnoDB',
            'table_collation' => 'utf8_unicode_ci',
        ];

        $I->assertEquals(
            $expectedOptions,
            $connection->tableOptions('personas', env('DATA_MYSQL_NAME'))
        );
    }

    /**
     * Tests Phalcon\Db :: Mysql
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbMySqlDescribeIndexes(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedIndexes = [
            'PRIMARY'   => new Index(
                'PRIMARY',
                ['id'],
                'PRIMARY'
            ),
            'robots_id' => new Index(
                'robots_id',
                ['robots_id']
            ),
            'parts_id'  => new Index(
                'parts_id',
                ['parts_id']
            ),
        ];

        $I->assertEquals(
            $expectedIndexes,
            $connection->describeIndexes('robots_parts')
        );

        $I->assertEquals(
            $expectedIndexes,
            $connection->describeIndexes('robots_parts', env('DATA_MYSQL_NAME'))
        );


        $expectedIndexes = [
            'PRIMARY'                  => new Index(
                'PRIMARY',
                ['id'],
                'PRIMARY'
            ),
            'issue_11036_token_UNIQUE' => new Index(
                'issue_11036_token_UNIQUE',
                ['token'],
                'UNIQUE'
            ),
        ];

        $I->assertEquals(
            $expectedIndexes,
            $connection->describeIndexes('issue_11036')
        );

        $I->assertEquals(
            $expectedIndexes,
            $connection->describeIndexes('issue_11036', env('DATA_MYSQL_NAME'))
        );
    }

    /**
     * Tests Phalcon\Db :: Mysql
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbMySqlDescribeReferences(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedReferences = [
            'robots_parts_ibfk_1' => new Reference(
                'robots_parts_ibfk_1',
                [
                    'referencedTable'   => 'robots',
                    'columns'           => ['robots_id'],
                    'referencedColumns' => ['id'],
                    'referencedSchema'  => env('DATA_MYSQL_NAME'),
                    'onUpdate'          => 'RESTRICT',
                    'onDelete'          => 'RESTRICT',
                ]
            ),
            'robots_parts_ibfk_2' => new Reference(
                'robots_parts_ibfk_2',
                [
                    'referencedTable'   => 'parts',
                    'columns'           => ['parts_id'],
                    'referencedColumns' => ['id'],
                    'referencedSchema'  => env('DATA_MYSQL_NAME'),
                    'onUpdate'          => 'RESTRICT',
                    'onDelete'          => 'RESTRICT',
                ]
            ),
        ];

        $I->assertEquals(
            $expectedReferences,
            $connection->describeReferences('robots_parts')
        );

        $I->assertEquals(
            $expectedReferences,
            $connection->describeReferences('robots_parts', env('DATA_MYSQL_NAME'))
        );
    }

    private function getExpectedColumnsMysql(): array
    {
        return [
            0  => new Column(
                'cedula',
                [
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
                ]
            ),
            1  => new Column(
                'tipo_documento_id',
                [
                    'type'          => 0,
                    'isNumeric'     => true,
                    'size'          => 3,
                    'scale'         => 0,
                    'default'       => null,
                    'unsigned'      => true,
                    'notNull'       => true,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'cedula',
                    'bindType'      => 1,
                ]
            ),
            2  => new Column(
                'nombres',
                [
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
                ]
            ),
            3  => new Column(
                'telefono',
                [
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
                ]
            ),
            4  => new Column(
                'direccion',
                [
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
                ]
            ),
            5  => new Column(
                'email',
                [
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
                ]
            ),
            6  => new Column(
                'fecha_nacimiento',
                [
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
                ]
            ),
            7  => new Column(
                'ciudad_id',
                [
                    'type'          => 0,
                    'isNumeric'     => true,
                    'size'          => 10,
                    'scale'         => 0,
                    'default'       => '0',
                    'unsigned'      => true,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'fecha_nacimiento',
                    'bindType'      => 1,
                ]
            ),
            8  => new Column(
                'creado_at',
                [
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
                ]
            ),
            9  => new Column(
                'cupo',
                [
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
                ]
            ),
            10 => new Column(
                'estado',
                [
                    'type'          => 18,
                    'isNumeric'     => false,
                    'size'          => "'A','I','X'",
                    'scale'         => 0,
                    'default'       => null,
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
