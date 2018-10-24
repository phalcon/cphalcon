<?php

namespace Phalcon\Test\Unit\Db;

use Phalcon\Db\Column;
use Phalcon\Db\Adapter\Pdo\Mysql;

class DescribeCest
{
    /**
     * @var Mysql
     */
    protected $connection;

    public function _before(\UnitTester $I)
    {
        parent::_before();

        try {
            $this->connection = new Mysql([
                'host'     => TEST_DB_MYSQL_HOST,
                'username' => TEST_DB_MYSQL_USER,
                'password' => TEST_DB_MYSQL_PASSWD,
                'dbname'   => TEST_DB_MYSQL_NAME,
                'port'     => TEST_DB_MYSQL_PORT,
                'charset'  => TEST_DB_MYSQL_CHARSET,
            ]);
        } catch (\PDOException $e) {
            throw new SkippedTestError("Unable to connect to the database: " . $e->getMessage());
        }
    }

    public function checkColumnNames(\UnitTester $I)
    {
        $I->assertTrue($this->connection->tableExists('dialect'));
        $expected = $this->getExpectedColumns();
        $I->assertEquals($expected, $this->connection->describeColumns('dialect'));
    }

    private function getExpectedColumns(): array
    {
        return [
            0 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_primary',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => true,
                    '_autoIncrement' => false,
                    '_primary'       => true,
                    '_first'         => true,
                    '_after'         => null,
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
        ];
    }

//    public function getExpectedColumnsMysql()
//    {
//        return [
//            0 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'cedula',
//                '_schemaName' => NULL,
//                '_type' => 5,
//                '_isNumeric' => false,
//                '_size' => 15,
//                '_scale' => 0,
//                '_default' => NULL,
//                '_unsigned' => false,
//                '_notNull' => true,
//                '_autoIncrement' => false,
//                '_primary' => true,
//                '_first' => true,
//                '_after' => NULL,
//                '_bindType' => 2,
//            ]),
//            1 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'tipo_documento_id',
//                '_schemaName' => NULL,
//                '_type' => 0,
//                '_isNumeric' => true,
//                '_size' => 3,
//                '_scale' => 0,
//                '_default' => NULL,
//                '_unsigned' => true,
//                '_notNull' => true,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'cedula',
//                '_bindType' => 1,
//            ]),
//            2 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'nombres',
//                '_schemaName' => NULL,
//                '_type' => 2,
//                '_isNumeric' => false,
//                '_size' => 100,
//                '_scale' => 0,
//                '_default' => '',
//                '_unsigned' => false,
//                '_notNull' => true,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'tipo_documento_id',
//                '_bindType' => 2,
//            ]),
//            3 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'telefono',
//                '_schemaName' => NULL,
//                '_type' => 2,
//                '_isNumeric' => false,
//                '_size' => 20,
//                '_scale' => 0,
//                '_default' => NULL,
//                '_unsigned' => false,
//                '_notNull' => false,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'nombres',
//                '_bindType' => 2,
//            ]),
//            4 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'direccion',
//                '_schemaName' => NULL,
//                '_type' => 2,
//                '_isNumeric' => false,
//                '_size' => 100,
//                '_scale' => 0,
//                '_default' => NULL,
//                '_unsigned' => false,
//                '_notNull' => false,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'telefono',
//                '_bindType' => 2,
//            ]),
//            5 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'email',
//                '_schemaName' => NULL,
//                '_type' => 2,
//                '_isNumeric' => false,
//                '_size' => 50,
//                '_scale' => 0,
//                '_default' => NULL,
//                '_unsigned' => false,
//                '_notNull' => false,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'direccion',
//                '_bindType' => 2,
//            ]),
//            6 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'fecha_nacimiento',
//                '_schemaName' => NULL,
//                '_type' => 1,
//                '_isNumeric' => false,
//                '_size' => 0,
//                '_scale' => 0,
//                '_default' => '1970-01-01',
//                '_unsigned' => false,
//                '_notNull' => false,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'email',
//                '_bindType' => 2,
//            ]),
//            7 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'ciudad_id',
//                '_schemaName' => NULL,
//                '_type' => 0,
//                '_isNumeric' => true,
//                '_size' => 10,
//                '_scale' => 0,
//                '_default' => '0',
//                '_unsigned' => true,
//                '_notNull' => false,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'fecha_nacimiento',
//                '_bindType' => 1,
//            ]),
//            8 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'creado_at',
//                '_schemaName' => NULL,
//                '_type' => 1,
//                '_isNumeric' => false,
//                '_size' => 0,
//                '_scale' => 0,
//                '_default' => NULL,
//                '_unsigned' => false,
//                '_notNull' => false,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'ciudad_id',
//                '_bindType' => 2,
//            ]),
//            9 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'cupo',
//                '_schemaName' => NULL,
//                '_type' => 3,
//                '_isNumeric' => true,
//                '_size' => 16,
//                '_scale' => 2,
//                '_default' => NULL,
//                '_unsigned' => false,
//                '_notNull' => true,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'creado_at',
//                '_bindType' => 32,
//            ]),
//            10 => Phalcon\Db\Column::__set_state([
//                '_columnName' => 'estado',
//                '_schemaName' => NULL,
//                '_type' => 18,
//                '_isNumeric' => false,
//                '_size' => "'A','I','X'",
//                '_scale' => 0,
//                '_default' => NULL,
//                '_unsigned' => false,
//                '_notNull' => true,
//                '_autoIncrement' => false,
//                '_first' => false,
//                '_after' => 'cupo',
//                '_bindType' => 2,
//            ])
//        ];
//    }
//
//    public function testDbMysql()
//    {
//        //Table exist
//        $this->assertEquals($connection->tableExists('personas'), 1);
//        $this->assertEquals($connection->tableExists('noexist'), 0);
//        $this->assertEquals($connection->tableExists('personas', 'phalcon_test'), 1);
//        $this->assertEquals($connection->tableExists('personas', 'test'), 0);
//
//        $expectedDescribe = $this->getExpectedColumnsMysql();
//        $describe = $connection->describeColumns('personas');
//
//        $this->assertEquals($describe, $expectedDescribe);
//
//        $describe = $connection->describeColumns('personas', 'phalcon_test');
//        $this->assertEquals($describe, $expectedDescribe);
//
//        //Table Options
//        $expectedOptions = [
//            'table_type' => 'BASE TABLE',
//            'auto_increment' => NULL,
//            'engine' => 'InnoDB',
//            'table_collation' => 'utf8_unicode_ci',
//        ];
//
//        $options = $connection->tableOptions('personas', 'phalcon_test');
//        $this->assertEquals($options, $expectedOptions);
//
//        //Indexes
//        $expectedIndexes = [
//            'PRIMARY' => Phalcon\Db\Index::__set_state([
//                '_name' => 'PRIMARY',
//                '_columns' => ['id'],
//                '_type' => 'PRIMARY',
//            ]),
//            'robots_id' => Phalcon\Db\Index::__set_state([
//                '_name' => 'robots_id',
//                '_columns' => ['robots_id']
//            ]),
//            'parts_id' => Phalcon\Db\Index::__set_state([
//                '_name' => 'parts_id',
//                '_columns' => ['parts_id']
//            ])
//        ];
//
//        $describeIndexes = $connection->describeIndexes('robots_parts');
//        $this->assertEquals($describeIndexes, $expectedIndexes);
//
//        $describeIndexes = $connection->describeIndexes('robots_parts', 'phalcon_test');
//        $this->assertEquals($describeIndexes, $expectedIndexes);
//
//        //Indexes
//        $expectedIndexes = [
//            'PRIMARY' => Phalcon\Db\Index::__set_state([
//                '_name' => 'PRIMARY',
//                '_columns' => ['id'],
//                '_type' => 'PRIMARY',
//            ]),
//            'issue_11036_token_UNIQUE' => Phalcon\Db\Index::__set_state([
//                '_name' => 'issue_11036_token_UNIQUE',
//                '_columns' => ['token'],
//                '_type' => 'UNIQUE'
//            ])
//        ];
//
//        $describeIndexes = $connection->describeIndexes('issue_11036');
//        $this->assertEquals($describeIndexes, $expectedIndexes);
//
//        $describeIndexes = $connection->describeIndexes('issue_11036', 'phalcon_test');
//        $this->assertEquals($describeIndexes, $expectedIndexes);
//
//        //References
//        $expectedReferences = [
//            'robots_parts_ibfk_1' => Phalcon\Db\Reference::__set_state(
//                [
//                    '_referenceName' => 'robots_parts_ibfk_1',
//                    '_referencedTable' => 'robots',
//                    '_columns' => ['robots_id'],
//                    '_referencedColumns' => ['id'],
//                    '_referencedSchema' => 'phalcon_test',
//                    '_onUpdate' => 'RESTRICT',
//                    '_onDelete' => 'RESTRICT'
//                ]
//            ),
//            'robots_parts_ibfk_2' => Phalcon\Db\Reference::__set_state(
//                [
//                    '_referenceName' => 'robots_parts_ibfk_2',
//                    '_referencedTable' => 'parts',
//                    '_columns' => ['parts_id'],
//                    '_referencedColumns' => ['id'],
//                    '_referencedSchema' => 'phalcon_test',
//                    '_onUpdate' => 'RESTRICT',
//                    '_onDelete' => 'RESTRICT'
//                ]
//            ),
//        ];
//
//        $describeReferences = $connection->describeReferences('robots_parts');
//        $this->assertEquals($describeReferences, $expectedReferences);
//
//        $describeReferences = $connection->describeReferences('robots_parts', 'phalcon_test');
//        $this->assertEquals($describeReferences, $expectedReferences);
//
//    }
}
