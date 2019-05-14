<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DbDescribeCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
    }

    /**
     * Tests Phalcon\Db :: Mysql
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbMySql(IntegrationTester $I)
    {
        $I->wantToTest('Db - MySql');

        $this->setDiMysql();

        $connection = $this->getService('db');



        // Table exist
        $I->assertEquals(
            1,
            $connection->tableExists('personas')
        );

        $I->assertEquals(
            0,
            $connection->tableExists('noexist')
        );

        $I->assertEquals(
            1,
            $connection->tableExists('personas', env('DATA_MYSQL_NAME'))
        );

        $I->assertEquals(
            0,
            $connection->tableExists('personas', 'test')
        );

        /**
         * @TODO - Check this after refactoring
         */
//        $expectedDescribe = $this->getExpectedColumnsMysql();
//        $describe         = $connection->describeColumns('personas');
//        $I->assertEquals($expectedDescribe, $describe);

//        $describe = $connection->describeColumns('personas', env('DATA_MYSQL_NAME'));
//        $I->assertEquals($describe, $expectedDescribe);

        //Table Options
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

        //Indexes
        $expectedIndexes = [
            'PRIMARY'   => Index::__set_state(
                [
                    'name'    => 'PRIMARY',
                    'columns' => ['id'],
                    'type'    => 'PRIMARY',
                ]
            ),
            'robots_id' => Index::__set_state(
                [
                    'name'    => 'robots_id',
                    'columns' => ['robots_id'],
                ]
            ),
            'parts_id'  => Index::__set_state(
                [
                    'name'    => 'parts_id',
                    'columns' => ['parts_id'],
                ]
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

        //Indexes
        $expectedIndexes = [
            'PRIMARY'                  => Index::__set_state(
                [
                    'name'    => 'PRIMARY',
                    'columns' => ['id'],
                    'type'    => 'PRIMARY',
                ]
            ),
            'issue_11036_token_UNIQUE' => Index::__set_state(
                [
                    'name'    => 'issue_11036_token_UNIQUE',
                    'columns' => ['token'],
                    'type'    => 'UNIQUE',
                ]
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

        //References
        $expectedReferences = [
            'robots_parts_ibfk_1' => Reference::__set_state(
                [
                    'referenceName'     => 'robots_parts_ibfk_1',
                    'referencedTable'   => 'robots',
                    'columns'           => ['robots_id'],
                    'referencedColumns' => ['id'],
                    'referencedSchema'  => env('DATA_MYSQL_NAME'),
                    'onUpdate'          => 'RESTRICT',
                    'onDelete'          => 'RESTRICT',
                ]
            ),
            'robots_parts_ibfk_2' => Reference::__set_state(
                [
                    'referenceName'     => 'robots_parts_ibfk_2',
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

    /**
     * Tests Phalcon\Db :: Postgresql
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbPostgresql(IntegrationTester $I)
    {
        $I->wantToTest('Db - Postgresql');

        $this->setDiPostgresql();

        $connection = $this->getService('db');

        // Columns
        $expectedDescribe = $this->getExpectedColumnsPostgresql();

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas')
        );

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas', 'public')
        );

        /**
         * @todo Check the references (SQL dump file)
         */
//        // Indexes
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
//
//        //References
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

    private function getExpectedColumnsPostgresql()
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
                'size'          => 0,
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
                'size'          => 0,
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
                'scale'         => 0,
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

    /**
     * Tests Phalcon\Db :: Sqlite
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbSqlite(IntegrationTester $I)
    {
        $I->wantToTest('Db - Sqlite');

        $this->setDiSqlite();

        $connection = $this->getService('db');

        //List tables
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



        //Table exist
        $I->assertEquals(
            1,
            $connection->tableExists('personas')
        );

        $I->assertEquals(
            0,
            $connection->tableExists('noexist')
        );

        $I->assertEquals(
            1,
            $connection->tableExists('personas', 'public')
        );

        $I->assertEquals(
            1,
            $connection->tableExists('personas', 'test')
        );



        // Columns
        $expectedDescribe = $this->getExpectedColumnsSqlite();

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas')
        );

        $I->assertEquals(
            $expectedDescribe,
            $connection->describeColumns('personas', 'main')
        );



        // Indexes
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



        // References
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

    private function getExpectedColumnsSqlite()
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

    private function getExpectedColumnsMysql()
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
                'unsigned'      => true,
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
                'unsigned'      => true,
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
            ]),
        ];
    }
}
