<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file LICENSE.txt.                             |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

use Phalcon\Db\Column as DbColumn;
use PHPUnit\Framework\TestCase;

class DbBindTest extends TestCase
{
    public function testDbBindMysql()
    {
        require 'unit-tests/config.db.php';
        if (empty($configMysql)) {
            $this->markTestSkipped("Skipped");
            return;
        }

        $connection = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);

        //$this->_executeRawBindTests($connection);
        //$this->_executeRawBindTestsMysql($connection);
        $this->_executeConvertBindTests($connection);
        $this->_executeBindByTypeTests($connection);
    }

    protected function _executeConvertBindTests($connection)
    {
        $params = $connection->convertBoundParams(
            "a=?0",
            [
                0 => 100,
            ]
        );

        $this->assertEquals(
            $params,
            [
                'sql'    => 'a=?',
                'params' => [
                    0 => 100,
                ],
            ]
        );


        $params = $connection->convertBoundParams(
            "a=?0",
            [
                0 => 100,
                1 => 50,
            ]
        );

        $this->assertEquals(
            $params,
            [
                'sql'    => 'a=?',
                'params' => [
                    0 => 100,
                ],
            ]
        );


        $params = $connection->convertBoundParams(
            "a=?1 AND b = ?0",
            [
                1 => 50,
                0 => 25,
            ]
        );

        $this->assertEquals(
            $params,
            [
                'sql'    => "a=? AND b = ?",
                'params' => [
                    0 => 50,
                    1 => 25,
                ],
            ]
        );


        $params = $connection->convertBoundParams(
            "a=?1 AND b = ?0",
            [
                1 => 25.10,
                0 => '25.10',
            ]
        );

        $this->assertEquals(
            $params,
            [
                'sql'    => "a=? AND b = ?",
                'params' => [
                    0 => '25.10',
                    1 => 25.10,
                ],
            ]
        );


        $params = $connection->convertBoundParams(
            "a=?1 AND b = ?0 AND c > :c: AND d = ?3",
            [
                'c' => 1000,
                1   => 'some-name',
                0   => 15,
                3   => 400,
            ]
        );

        $this->assertEquals(
            $params,
            [
                'sql'    => "a=? AND b = ? AND c > ? AND d = ?",
                'params' => [
                    0 => 'some-name',
                    1 => 15,
                    2 => 1000,
                    3 => 400,
                ],
            ]
        );
    }

    protected function _executeBindByTypeTests($connection)
    {
        $success = $connection->execute(
            'INSERT INTO prueba(id, nombre, estado) VALUES (' . $connection->getDefaultIdValue() . ', ?, ?)',
            ["LOL 1", "A"],
            [DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->execute(
            'UPDATE prueba SET nombre = ?, estado = ?',
            ["LOL 11", "R"],
            [DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->execute(
            'DELETE FROM prueba WHERE estado = ?',
            ["R"],
            [DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            [$connection->getDefaultIdValue(), "LOL 1", "A"],
            null,
            [DbColumn::BIND_SKIP, DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            ["LOL 2", "E"],
            ['nombre', 'estado'],
            [DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            ["LOL 3", "I"],
            ['nombre', 'estado'],
            [DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            [new Phalcon\Db\RawValue('current_date'), "A"],
            ['nombre', 'estado'],
            [DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->update(
            'prueba',
            ["nombre", "estado"],
            ["LOL 1000", "X"],
            "estado='E'",
            [DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->update(
            'prueba',
            ["nombre"], ["LOL 3000"],
            "estado='X'",
            [DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);

        $success = $connection->update(
            'prueba',
            ["nombre"], [new Phalcon\Db\RawValue('current_date')],
            "estado='X'",
            [DbColumn::BIND_PARAM_STR]
        );
        $this->assertTrue($success);
    }

    /*protected function _executeRawBindTests($connection)
    {
        $conditions = $connection->bindParams(
            "a=?0",
            array(
                0 => 100
            )
        );

        $this->assertEquals($conditions, "a=100");



        $conditions = $connection->bindParams(
            "a=?0",
            array(
                0 => 100,
                1 => 50
            )
        );

        $this->assertEquals($conditions, "a=100");



        $conditions = $connection->bindParams(
            "a=?0", array(
                1 => 50
            )
        );

        $this->assertEquals($conditions, "a=?0");



        $conditions = $connection->bindParams(
            "a=?1 AND b = ?0",
            array(
                0 => 25,
                1 => 50
            )
        );

        $this->assertEquals($conditions, "a=50 AND b = 25");



        $conditions = $connection->bindParams(
            "a=?1 AND b = ?0",
            array(
                0 => '25',
                1 => '50'
            )
        );

        $this->assertEquals($conditions, "a=50 AND b = 25");



        $conditions = $connection->bindParams(
            "a=?1 AND b = ?0",
            array(
                0 => '25.10',
                1 => 25.10
            )
        );

        $this->assertEquals($conditions, "a=25.1 AND b = 25.10");



        $conditions = $connection->bindParams(
            "a=?1 AND b = ?0 AND c<>?2",
            array(
                0 => 25,
                1 => 50,
                2 => 15
            )
        );

        $this->assertEquals($conditions, "a=50 AND b = 25 AND c<>15");



        $conditions = $connection->bindParams(
            "a=:a:",
            array(
                'a' => 'no-suprises'
            )
        );

        $this->assertEquals($conditions, "a='no-suprises'");



        $conditions = $connection->bindParams(
            "column1 = :column1: AND column2=:column2:",
            array(
                'column1' => 'hello',
                'column2' => 'lol'
            )
        );

        $this->assertEquals($conditions, "column1 = 'hello' AND column2='lol'");
    }

    protected function _executeRawBindTestsMysql($connection)
    {
        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:)",
            array(
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'"
            )
        );

        $this->assertEquals($conditions, "column3 IN ('hello', 100, '\'hahaha\'')");



        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2",
            array(
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
                2 => 'le-nice'
            )
        );

        $this->assertEquals($conditions, "column3 IN ('hello', 100, '\'hahaha\'') AND column4 > 'le-nice'");
    }

    protected function _executeRawBindTestsPostgresql($connection)
    {
        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:)",
            array(
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'"
            )
        );

        $this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''')");



        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2",
            array(
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
                2 => 'le-nice'
            )
        );

        $this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''') AND column4 > 'le-nice'");
    }

    protected function _executeRawBindTestsSqlite($connection)
    {
        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:)",
            array(
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'"
            )
        );

        $this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''')");



        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2",
            array(
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
                2 => 'le-nice'
            )
        );

        $this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''') AND column4 > 'le-nice'");
    }*/

    public function testDbBindPostgresql()
    {
        require 'unit-tests/config.db.php';
        if (empty($configPostgresql)) {
            $this->markTestSkipped("Skipped");
            return;
        }

        $connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);

        //$this->_executeRawBindTests($connection);
        //$this->_executeRawBindTestsPostgresql($connection);
        $this->_executeBindByTypeTests($connection);
    }

    public function testDbBindSqlite()
    {
        require 'unit-tests/config.db.php';
        if (empty($configSqlite)) {
            $this->markTestSkipped("Skipped");
            return;
        }

        $connection = new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);

        //$this->_executeRawBindTests($connection);
        //$this->_executeRawBindTestsSqlite($connection);
        $this->_executeBindByTypeTests($connection);
    }
}
