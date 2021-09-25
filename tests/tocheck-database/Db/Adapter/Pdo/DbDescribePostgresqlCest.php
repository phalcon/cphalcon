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
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class DbDescribePostgresqlCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiPostgresql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Db :: Postgresql
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbPostgresqlDescribeColumns(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedDescribe = $this->getExpectedColumnsPostgresql();

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas')
        );

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas', 'public')
        );
    }

    /**
     * Tests Phalcon\Db :: Postgresql
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbPostgresqlDescribeIndexes(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        /**
         * @todo Check the references (SQL dump file)
         */
//        $expectedIndexes = [
//            'robots_parts_parts_id'  => Index::__set_state([
//                'name'    => 'robots_parts_parts_id',
//                'columns' => ['parts_id'],
//            ]),
//            'robots_parts_pkey'      => Index::__set_state([
//                'name'    => 'robots_parts_pkey',
//                'columns' => ['id'],
//            ]),
//            'robots_parts_robots_id' => Index::__set_state([
//                'name'    => 'robots_parts_robots_id',
//                'columns' => ['robots_id'],
//            ]),
//        ];
//
//        $describeIndexes = $connection->describeIndexes('robots_parts');
//        $I->assertEquals($describeIndexes, $expectedIndexes);
//
//        $describeIndexes = $connection->describeIndexes('robots_parts', 'public');
//        $I->assertEquals($describeIndexes, $expectedIndexes);
    }

    /**
     * Tests Phalcon\Db :: Postgresql
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbPostgresqlDescribeReferences(IntegrationTester $I)
    {
        $connection = $this->getService('db');

//        $expectedReferences = [
//            'robots_parts_ibfk_1' => Reference::__set_state(
//                [
//                    'referenceName'     => 'robots_parts_ibfk_1',
//                    'referencedTable'   => 'robots',
//                    'columns'           => ['robots_id'],
//                    'referencedColumns' => ['id'],
//                    'referencedSchema'  => env('DATA_POSTGRES_NAME'),
//                    'onDelete'          => 'NO ACTION',
//                    'onUpdate'          => 'NO ACTION',
//                ]
//            ),
//            'robots_parts_ibfk_2' => Reference::__set_state(
//                [
//                    'referenceName'     => 'robots_parts_ibfk_2',
//                    'referencedTable'   => 'parts',
//                    'columns'           => ['parts_id'],
//                    'referencedColumns' => ['id'],
//                    'referencedSchema'  => env('DATA_POSTGRES_NAME'),
//                    'onDelete'          => 'NO ACTION',
//                    'onUpdate'          => 'NO ACTION',
//                ]
//            ),
//        ];
//
//        $describeReferences = $connection->describeReferences('robots_parts');
//        $I->assertEquals($describeReferences, $expectedReferences);
//
//        $describeReferences = $connection->describeReferences('robots_parts', 'public');
//        $I->assertEquals($describeReferences, $expectedReferences);
    }

    private function getExpectedColumnsPostgresql(): array
    {
        return [
            0  => new Column(
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
            1  => new Column(
                'tipo_documento_id',
                [
                    'type'          => 0,
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
            2  => new Column(
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
            3  => new Column(
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
                ]
            ),
            4  => new Column(
                'direccion',
                [
                    'type'          => 2,
                    'isNumeric'     => false,
                    'size'          => 100,
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
                    'size'          => 0,
                    'scale'         => 0,
                    'default'       => '0',
                    'unsigned'      => false,
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
                    'scale'         => 0,
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
                    'type'          => 5,
                    'isNumeric'     => false,
                    'size'          => 1,
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
