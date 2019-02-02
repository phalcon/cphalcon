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
use Phalcon\Db\RawValue;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DbBindCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
    }

    /**
     * Tests Phalcon\Db :: Mysql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbBindMySql(IntegrationTester $I)
    {
        $I->wantToTest("Db - Bind - MySql");
        $this->setDiMysql();
        $connection = $this->getService('db');

        $this->executeConvertBindTests($I, $connection);
        $this->executeBindByTypeTests($I, $connection);
    }

    protected function executeConvertBindTests(IntegrationTester $I, $connection)
    {
        $params = $connection->convertBoundParams(
            "a=?0",
            [
                0 => 100,
            ]
        );

        $I->assertEquals(
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

        $I->assertEquals(
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

        $I->assertEquals(
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

        $I->assertEquals(
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

        $I->assertEquals(
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

    protected function executeBindByTypeTests(IntegrationTester $I, $connection)
    {
        $success = $connection->execute(
            'INSERT INTO prueba(id, nombre, estado) VALUES (' . $connection->getDefaultIdValue() . ', ?, ?)',
            ["LOL 1", "A"],
            [Column::BIND_PARAM_STR, Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->execute(
            'UPDATE prueba SET nombre = ?, estado = ?',
            ["LOL 11", "R"],
            [Column::BIND_PARAM_STR, Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->execute(
            'DELETE FROM prueba WHERE estado = ?',
            ["R"],
            [Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            [$connection->getDefaultIdValue(), "LOL 1", "A"],
            null,
            [Column::BIND_SKIP, Column::BIND_PARAM_STR, Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            ["LOL 2", "E"],
            ['nombre', 'estado'],
            [Column::BIND_PARAM_STR, Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            ["LOL 3", "I"],
            ['nombre', 'estado'],
            [Column::BIND_PARAM_STR, Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            [new RawValue('current_date'), "A"],
            ['nombre', 'estado'],
            [Column::BIND_PARAM_STR, Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->update(
            'prueba',
            ["nombre", "estado"],
            ["LOL 1000", "X"],
            "estado='E'",
            [Column::BIND_PARAM_STR, Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->update(
            'prueba',
            ["nombre"],
            ["LOL 3000"],
            "estado='X'",
            [Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);

        $success = $connection->update(
            'prueba',
            ["nombre"],
            [new RawValue('current_date')],
            "estado='X'",
            [Column::BIND_PARAM_STR]
        );
        $I->assertTrue($success);
    }

    /**
     * Tests Phalcon\Db :: Postgresql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbBindPostgresql(IntegrationTester $I)
    {
        $I->wantToTest("Db - Bind - Postgresql");
        $this->setDiMysql();
        $connection = $this->getService('db');

        //$this->executeRawBindTests($I, $connection);
        //$this->executeRawBindTestsPostgresql($I, $connection);
        $this->executeBindByTypeTests($I, $connection);
    }

    /**
     * Tests Phalcon\Db :: Sqlite
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbBindSqlite(IntegrationTester $I)
    {
        $I->wantToTest("Db - Bind - Sqlite");
        $this->setDiSqlite();
        $connection = $this->getService('db');

        //$this->_executeRawBindTests($connection);
        //$this->_executeRawBindTestsSqlite($connection);
        $this->executeBindByTypeTests($I, $connection);
    }

    protected function executeRawBindTests(IntegrationTester $I, $connection)
    {
        $conditions = $connection->bindParams(
            "a=?0",
            [
                0 => 100,
            ]
        );

        $I->assertEquals($conditions, "a=100");


        $conditions = $connection->bindParams(
            "a=?0",
            [
                0 => 100,
                1 => 50,
            ]
        );

        $I->assertEquals($conditions, "a=100");


        $conditions = $connection->bindParams(
            "a=?0",
            [
                1 => 50,
            ]
        );

        $I->assertEquals($conditions, "a=?0");


        $conditions = $connection->bindParams(
            "a=?1 AND b = ?0",
            [
                0 => 25,
                1 => 50,
            ]
        );

        $I->assertEquals($conditions, "a=50 AND b = 25");


        $conditions = $connection->bindParams(
            "a=?1 AND b = ?0",
            [
                0 => '25',
                1 => '50',
            ]
        );

        $I->assertEquals($conditions, "a=50 AND b = 25");


        $conditions = $connection->bindParams(
            "a=?1 AND b = ?0",
            [
                0 => '25.10',
                1 => 25.10,
            ]
        );

        $I->assertEquals($conditions, "a=25.1 AND b = 25.10");


        $conditions = $connection->bindParams(
            "a=?1 AND b = ?0 AND c<>?2",
            [
                0 => 25,
                1 => 50,
                2 => 15,
            ]
        );

        $I->assertEquals($conditions, "a=50 AND b = 25 AND c<>15");


        $conditions = $connection->bindParams(
            "a=:a:",
            [
                'a' => 'no-suprises',
            ]
        );

        $I->assertEquals($conditions, "a='no-suprises'");


        $conditions = $connection->bindParams(
            "column1 = :column1: AND column2=:column2:",
            [
                'column1' => 'hello',
                'column2' => 'lol',
            ]
        );

        $I->assertEquals($conditions, "column1 = 'hello' AND column2='lol'");
    }

    protected function executeRawBindTestsMysql(IntegrationTester $I, $connection)
    {
        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:)",
            [
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
            ]
        );

        $I->assertEquals($conditions, "column3 IN ('hello', 100, '\'hahaha\'')");


        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2",
            [
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
                2      => 'le-nice',
            ]
        );

        $I->assertEquals($conditions, "column3 IN ('hello', 100, '\'hahaha\'') AND column4 > 'le-nice'");
    }

    protected function executeRawBindTestsPostgresql(IntegrationTester $I, $connection)
    {
        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:)",
            [
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
            ]
        );

        $I->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''')");


        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2",
            [
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
                2      => 'le-nice',
            ]
        );

        $I->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''') AND column4 > 'le-nice'");
    }

    protected function executeRawBindTestsSqlite(IntegrationTester $I, $connection)
    {
        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:)",
            [
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
            ]
        );

        $I->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''')");


        $conditions = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2",
            [
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
                2      => 'le-nice',
            ]
        );

        $I->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''') AND column4 > 'le-nice'");
    }
}
