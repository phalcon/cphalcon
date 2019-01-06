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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbMySql(IntegrationTester $I)
    {
        $I->wantToTest("Db - MySql");
        $this->setDiMysql();
        $connection = $this->getService('db');

        //Table exist
        $I->assertEquals($connection->tableExists('personas'), 1);
        $I->assertEquals($connection->tableExists('noexist'), 0);
        $I->assertEquals($connection->tableExists('personas', env('DATA_MYSQL_NAME')), 1);
        $I->assertEquals($connection->tableExists('personas', 'test'), 0);

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

        $options = $connection->tableOptions('personas', env('DATA_MYSQL_NAME'));
        $I->assertEquals($options, $expectedOptions);

        //Indexes
        $expectedIndexes = [
            'PRIMARY'   => Index::__set_state([
                '_name'    => 'PRIMARY',
                '_columns' => ['id'],
                '_type'    => 'PRIMARY',
            ]),
            'robots_id' => Index::__set_state([
                '_name'    => 'robots_id',
                '_columns' => ['robots_id'],
            ]),
            'parts_id'  => Index::__set_state([
                '_name'    => 'parts_id',
                '_columns' => ['parts_id'],
            ]),
        ];

        $describeIndexes = $connection->describeIndexes('robots_parts');
        $I->assertEquals($describeIndexes, $expectedIndexes);

        $describeIndexes = $connection->describeIndexes('robots_parts', env('DATA_MYSQL_NAME'));
        $I->assertEquals($describeIndexes, $expectedIndexes);

        //Indexes
        $expectedIndexes = [
            'PRIMARY'                  => Index::__set_state([
                '_name'    => 'PRIMARY',
                '_columns' => ['id'],
                '_type'    => 'PRIMARY',
            ]),
            'issue_11036_token_UNIQUE' => Index::__set_state([
                '_name'    => 'issue_11036_token_UNIQUE',
                '_columns' => ['token'],
                '_type'    => 'UNIQUE',
            ]),
        ];

        $describeIndexes = $connection->describeIndexes('issue_11036');
        $I->assertEquals($describeIndexes, $expectedIndexes);

        $describeIndexes = $connection->describeIndexes('issue_11036', env('DATA_MYSQL_NAME'));
        $I->assertEquals($describeIndexes, $expectedIndexes);

        //References
        $expectedReferences = [
            'robots_parts_ibfk_1' => Reference::__set_state(
                [
                    '_referenceName'     => 'robots_parts_ibfk_1',
                    '_referencedTable'   => 'robots',
                    '_columns'           => ['robots_id'],
                    '_referencedColumns' => ['id'],
                    '_referencedSchema'  => env('DATA_MYSQL_NAME'),
                    '_onUpdate'          => 'RESTRICT',
                    '_onDelete'          => 'RESTRICT',
                ]
            ),
            'robots_parts_ibfk_2' => Reference::__set_state(
                [
                    '_referenceName'     => 'robots_parts_ibfk_2',
                    '_referencedTable'   => 'parts',
                    '_columns'           => ['parts_id'],
                    '_referencedColumns' => ['id'],
                    '_referencedSchema'  => env('DATA_MYSQL_NAME'),
                    '_onUpdate'          => 'RESTRICT',
                    '_onDelete'          => 'RESTRICT',
                ]
            ),
        ];

        $describeReferences = $connection->describeReferences('robots_parts');
        $I->assertEquals($describeReferences, $expectedReferences);

        $describeReferences = $connection->describeReferences('robots_parts', env('DATA_MYSQL_NAME'));
        $I->assertEquals($describeReferences, $expectedReferences);
    }

    /**
     * Tests Phalcon\Db :: Postgresql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbPostgresql(IntegrationTester $I)
    {
        $I->wantToTest("Db - Postgresql");
        $this->setDiPostgresql();
        $connection = $this->getService('db');

        //Columns
        $expectedDescribe = $this->getExpectedColumnsPostgresql();

        $describe = $connection->describeColumns('personas');
        $I->assertEquals($describe, $expectedDescribe);

        $describe = $connection->describeColumns('personas', 'public');
        $I->assertEquals($describe, $expectedDescribe);

        /**
         * @todo Check the references (SQL dump file)
         */
//        //Indexes
//        $expectedIndexes = [
//            'robots_parts_parts_id'  => Index::__set_state([
//                '_name'    => 'robots_parts_parts_id',
//                '_columns' => ['parts_id'],
//            ]),
//            'robots_parts_pkey'      => Index::__set_state([
//                '_name'    => 'robots_parts_pkey',
//                '_columns' => ['id'],
//            ]),
//            'robots_parts_robots_id' => Index::__set_state([
//                '_name'    => 'robots_parts_robots_id',
//                '_columns' => ['robots_id'],
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
//                    '_referenceName'     => 'robots_parts_ibfk_1',
//                    '_referencedTable'   => 'robots',
//                    '_columns'           => ['robots_id'],
//                    '_referencedColumns' => ['id'],
//                    '_referencedSchema'  => env('DATA_POSTGRES_NAME'),
//                    '_onDelete'          => 'NO ACTION',
//                    '_onUpdate'          => 'NO ACTION',
//                ]
//            ),
//            'robots_parts_ibfk_2' => Reference::__set_state(
//                [
//                    '_referenceName'     => 'robots_parts_ibfk_2',
//                    '_referencedTable'   => 'parts',
//                    '_columns'           => ['parts_id'],
//                    '_referencedColumns' => ['id'],
//                    '_referencedSchema'  => env('DATA_POSTGRES_NAME'),
//                    '_onDelete'          => 'NO ACTION',
//                    '_onUpdate'          => 'NO ACTION',
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
                '_columnName'    => 'cedula',
                '_schemaName'    => null,
                '_type'          => 5,
                '_isNumeric'     => false,
                '_size'          => 15,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_primary'       => true,
                '_first'         => true,
                '_after'         => null,
                '_bindType'      => 2,
            ]),
            1  => Column::__set_state([
                '_columnName'    => 'tipo_documento_id',
                '_schemaName'    => null,
                '_type'          => 0,
                '_isNumeric'     => true,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'cedula',
                '_bindType'      => 1,
            ]),
            2  => Column::__set_state([
                '_columnName'    => 'nombres',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 100,
                '_scale'         => 0,
                '_default'       => '',
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'tipo_documento_id',
                '_bindType'      => 2,
            ]),
            3  => Column::__set_state([
                '_columnName'    => 'telefono',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 20,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'nombres',
            ]),
            4  => Column::__set_state([
                '_columnName'    => 'direccion',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 100,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'telefono',
                '_bindType'      => 2,
            ]),
            5  => Column::__set_state([
                '_columnName'    => 'email',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 50,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'direccion',
                '_bindType'      => 2,
            ]),
            6  => Column::__set_state([
                '_columnName'    => 'fecha_nacimiento',
                '_schemaName'    => null,
                '_type'          => 1,
                '_isNumeric'     => false,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => '1970-01-01',
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'email',
                '_bindType'      => 2,
            ]),
            7  => Column::__set_state([
                '_columnName'    => 'ciudad_id',
                '_schemaName'    => null,
                '_type'          => 0,
                '_isNumeric'     => true,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => '0',
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'fecha_nacimiento',
                '_bindType'      => 1,
            ]),
            8  => Column::__set_state([
                '_columnName'    => 'creado_at',
                '_schemaName'    => null,
                '_type'          => 1,
                '_isNumeric'     => false,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'ciudad_id',
                '_bindType'      => 2,
            ]),
            9  => Column::__set_state([
                '_columnName'    => 'cupo',
                '_schemaName'    => null,
                '_type'          => 3,
                '_isNumeric'     => true,
                '_size'          => 16,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'creado_at',
                '_bindType'      => 32,
            ]),
            10 => Column::__set_state([
                '_columnName'    => 'estado',
                '_schemaName'    => null,
                '_type'          => 5,
                '_isNumeric'     => false,
                '_size'          => 1,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'cupo',
                '_bindType'      => 2,
            ]),
        ];
    }

    /**
     * Tests Phalcon\Db :: Sqlite
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbSqlite(IntegrationTester $I)
    {
        $I->wantToTest("Db - Sqlite");
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

        $tables = $connection->listTables();

        $I->assertEquals($expectedTables, $tables);

        $tables = $connection->listTables('public');
        $I->assertEquals($tables, $expectedTables);

        //Table exist
        $I->assertEquals($connection->tableExists('personas'), 1);
        $I->assertEquals($connection->tableExists('noexist'), 0);
        $I->assertEquals($connection->tableExists('personas', 'public'), 1);
        $I->assertEquals($connection->tableExists('personas', 'test'), 1);

        //Columns
        $expectedDescribe = $this->getExpectedColumnsSqlite();
        $describe         = $connection->describeColumns('personas');
        $I->assertEquals($describe, $expectedDescribe);

        $describe = $connection->describeColumns('personas', 'main');
        $I->assertEquals($describe, $expectedDescribe);

        //Indexes
        $expectedIndexes = [
            'sqlite_autoindex_COMPANY_1' => Index::__set_state([
                '_name'    => 'sqlite_autoindex_COMPANY_1',
                '_columns' => ['ID'],
                '_type'    => 'PRIMARY',
            ]),
            'salary_index'               => Index::__set_state([
                '_name'    => 'salary_index',
                '_columns' => ['SALARY'],
            ]),
            'name_index'                 => Index::__set_state([
                '_name'    => 'name_index',
                '_columns' => ['NAME'],
                '_type'    => 'UNIQUE',
            ]),
        ];

        $describeIndexes = $connection->describeIndexes('COMPANY');
        $I->assertEquals($describeIndexes, $expectedIndexes);

        $describeIndexes = $connection->describeIndexes('company', 'main');
        $I->assertEquals($describeIndexes, $expectedIndexes);

        //References
        $expectedReferences = [
            'foreign_key_0' => Reference::__set_state(
                [
                    '_referenceName'     => 'foreign_key_0',
                    '_referencedTable'   => 'parts',
                    '_columns'           => ['parts_id'],
                    '_referencedColumns' => ['id'],
                    '_referencedSchema'  => null,
                ]
            ),
            'foreign_key_1' => Reference::__set_state(
                [
                    '_referenceName'     => 'foreign_key_1',
                    '_referencedTable'   => 'robots',
                    '_columns'           => ['robots_id'],
                    '_referencedColumns' => ['id'],
                    '_referencedSchema'  => null,
                ]
            ),
        ];

        $describeReferences = $connection->describeReferences('robots_parts');
        $I->assertEquals($describeReferences, $expectedReferences);
    }

    private function getExpectedColumnsSqlite()
    {
        return [
            0  => Column::__set_state([
                '_columnName'    => 'cedula',
                '_schemaName'    => null,
                '_type'          => 5,
                '_isNumeric'     => false,
                '_size'          => 15,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_primary'       => true,
                '_first'         => true,
                '_after'         => null,
                '_bindType'      => 2,
            ]),
            1  => Column::__set_state([
                '_columnName'    => 'tipo_documento_id',
                '_schemaName'    => null,
                '_type'          => 0,
                '_isNumeric'     => true,
                '_size'          => 3,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'cedula',
                '_bindType'      => 1,
            ]),
            2  => Column::__set_state([
                '_columnName'    => 'nombres',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 100,
                '_scale'         => 0,
                '_default'       => '',
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'tipo_documento_id',
                '_bindType'      => 2,
            ]),
            3  => Column::__set_state([
                '_columnName'    => 'telefono',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 20,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'nombres',
                '_bindType'      => 2,
            ]),
            4  => Column::__set_state([
                '_columnName'    => 'direccion',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 100,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'telefono',
                '_bindType'      => 2,
            ]),
            5  => Column::__set_state([
                '_columnName'    => 'email',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 50,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'direccion',
                '_bindType'      => 2,
            ]),
            6  => Column::__set_state([
                '_columnName'    => 'fecha_nacimiento',
                '_schemaName'    => null,
                '_type'          => 1,
                '_isNumeric'     => false,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => '1970-01-01',
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'email',
                '_bindType'      => 2,
            ]),
            7  => Column::__set_state([
                '_columnName'    => 'ciudad_id',
                '_schemaName'    => null,
                '_type'          => 0,
                '_isNumeric'     => true,
                '_size'          => 10,
                '_scale'         => 0,
                '_default'       => '0',
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'fecha_nacimiento',
                '_bindType'      => 1,
            ]),
            8  => Column::__set_state([
                '_columnName'    => 'creado_at',
                '_schemaName'    => null,
                '_type'          => 1,
                '_isNumeric'     => false,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'ciudad_id',
                '_bindType'      => 2,
            ]),
            9  => Column::__set_state([
                '_columnName'    => 'cupo',
                '_schemaName'    => null,
                '_type'          => 3,
                '_isNumeric'     => true,
                '_size'          => 16,
                '_scale'         => 2,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'creado_at',
                '_bindType'      => 32,
            ]),
            10 => Column::__set_state([
                '_columnName'    => 'estado',
                '_schemaName'    => null,
                '_type'          => 5,
                '_isNumeric'     => false,
                '_size'          => 1,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'cupo',
                '_bindType'      => 2,
            ]),
        ];
    }

    private function getExpectedColumnsMysql()
    {
        return [
            0  => Column::__set_state([
                '_columnName'    => 'cedula',
                '_schemaName'    => null,
                '_type'          => 5,
                '_isNumeric'     => false,
                '_size'          => 15,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_primary'       => true,
                '_first'         => true,
                '_after'         => null,
                '_bindType'      => 2,
            ]),
            1  => Column::__set_state([
                '_columnName'    => 'tipo_documento_id',
                '_schemaName'    => null,
                '_type'          => 0,
                '_isNumeric'     => true,
                '_size'          => 3,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => true,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'cedula',
                '_bindType'      => 1,
            ]),
            2  => Column::__set_state([
                '_columnName'    => 'nombres',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 100,
                '_scale'         => 0,
                '_default'       => '',
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'tipo_documento_id',
                '_bindType'      => 2,
            ]),
            3  => Column::__set_state([
                '_columnName'    => 'telefono',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 20,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'nombres',
                '_bindType'      => 2,
            ]),
            4  => Column::__set_state([
                '_columnName'    => 'direccion',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 100,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'telefono',
                '_bindType'      => 2,
            ]),
            5  => Column::__set_state([
                '_columnName'    => 'email',
                '_schemaName'    => null,
                '_type'          => 2,
                '_isNumeric'     => false,
                '_size'          => 50,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'direccion',
                '_bindType'      => 2,
            ]),
            6  => Column::__set_state([
                '_columnName'    => 'fecha_nacimiento',
                '_schemaName'    => null,
                '_type'          => 1,
                '_isNumeric'     => false,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => '1970-01-01',
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'email',
                '_bindType'      => 2,
            ]),
            7  => Column::__set_state([
                '_columnName'    => 'ciudad_id',
                '_schemaName'    => null,
                '_type'          => 0,
                '_isNumeric'     => true,
                '_size'          => 10,
                '_scale'         => 0,
                '_default'       => '0',
                '_unsigned'      => true,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'fecha_nacimiento',
                '_bindType'      => 1,
            ]),
            8  => Column::__set_state([
                '_columnName'    => 'creado_at',
                '_schemaName'    => null,
                '_type'          => 1,
                '_isNumeric'     => false,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'ciudad_id',
                '_bindType'      => 2,
            ]),
            9  => Column::__set_state([
                '_columnName'    => 'cupo',
                '_schemaName'    => null,
                '_type'          => 3,
                '_isNumeric'     => true,
                '_size'          => 16,
                '_scale'         => 2,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'creado_at',
                '_bindType'      => 32,
            ]),
            10 => Column::__set_state([
                '_columnName'    => 'estado',
                '_schemaName'    => null,
                '_type'          => 18,
                '_isNumeric'     => false,
                '_size'          => "'A','I','X'",
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => true,
                '_autoIncrement' => false,
                '_first'         => false,
                '_after'         => 'cupo',
                '_bindType'      => 2,
            ]),
        ];
    }
}
