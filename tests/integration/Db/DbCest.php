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
use PDO;
use Phalcon\Db;
use Phalcon\Db\RawValue;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DbCest
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
    public function dbMySql(IntegrationTester $I)
    {
        $I->wantToTest("Db - MySql");
        $this->setDiMysql();
        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
    }

    private function executeTests(IntegrationTester $I, $connection)
    {
        $result = $connection->query("SELECT * FROM personas LIMIT 3");
        $I->assertInternalType('object', $result);
        $I->assertInstanceOf('Phalcon\Db\Result\Pdo', $result);

        for ($i = 0; $i < 3; $i++) {
            $row = $result->fetch();
            $I->assertCount(22, $row);
        }

        $row = $result->fetch();
        $I->assertEquals($row, false);
        $I->assertEquals($result->numRows(), 3);

        $number = 0;
        $result = $connection->query("SELECT * FROM personas LIMIT 5");
        $I->assertInternalType('object', $result);

        while ($row = $result->fetch()) {
            $number++;
        }
        $I->assertEquals($number, 5);

        $result = $connection->query("SELECT * FROM personas LIMIT 5");
        $result->setFetchMode(Db::FETCH_NUM);
        $row = $result->fetch();
        $I->assertInternalType('array', $row);
        $I->assertCount(11, $row);
        $I->assertTrue(isset($row[0]));
        $I->assertFalse(isset($row['cedula']));
        $I->assertFalse(isset($row->cedula));

        $result = $connection->query("SELECT * FROM personas LIMIT 5");
        $result->setFetchMode(Db::FETCH_ASSOC);
        $row = $result->fetch();
        $I->assertInternalType('array', $row);
        $I->assertCount(11, $row);
        $I->assertFalse(isset($row[0]));
        $I->assertTrue(isset($row['cedula']));
        $I->assertFalse(isset($row->cedula));

        $result = $connection->query("SELECT * FROM personas LIMIT 5");
        $result->setFetchMode(Db::FETCH_OBJ);
        $row = $result->fetch();
        $I->assertInternalType('object', $row);
        $I->assertTrue(isset($row->cedula));

        $result = $connection->query("SELECT * FROM personas LIMIT 5");
        $result->setFetchMode(Db::FETCH_BOTH);
        $result->dataSeek(4);
        $row = $result->fetch();
        $row = $result->fetch();
        $I->assertEquals($row, false);

        $result = $connection->execute("DELETE FROM prueba");
        $I->assertTrue($result);

        $success = $connection->execute(
            'INSERT INTO prueba(id, nombre, estado) VALUES (' . $connection->getDefaultIdValue() . ', ?, ?)',
            [
                "LOL 1",
                "A",
            ]
        );
        $I->assertTrue($success);

        $success = $connection->execute('UPDATE prueba SET nombre = ?, estado = ?', ["LOL 11", "R"]);
        $I->assertTrue($success);

        $success = $connection->execute('DELETE FROM prueba WHERE estado = ?', ["R"]);
        $I->assertTrue($success);

        $success = $connection->insert('prueba', [$connection->getDefaultIdValue(), "LOL 1", "A"]);
        $I->assertTrue($success);

        $success = $connection->insert('prueba', ["LOL 2", "E"], ['nombre', 'estado']);
        $I->assertTrue($success);

        $success = $connection->insert('prueba', ["LOL 3", "I"], ['nombre', 'estado']);
        $I->assertTrue($success);

        $success = $connection->insert(
            'prueba',
            [
                new RawValue('current_date'),
                "A",
            ],
            [
                'nombre',
                'estado',
            ]
        );
        $I->assertTrue($success);

        for ($i = 0; $i < 50; $i++) {
            $success = $connection->insert('prueba', ["LOL " . $i, "F"], ['nombre', 'estado']);
            $I->assertTrue($success);
        }

        $success = $connection->update('prueba', ["nombre", "estado"], ["LOL 1000", "X"], "estado='E'");
        $I->assertTrue($success);

        $success = $connection->update('prueba', ["nombre"], ["LOL 3000"], "estado='X'");
        $I->assertTrue($success);

        $success = $connection->update(
            'prueba',
            ["nombre"],
            [
                new RawValue('current_date'),
            ],
            "estado='X'"
        );
        $I->assertTrue($success);

        //test array syntax for $whereCondition
        $success = $connection->insert('prueba', ["LOL array syntax", "E"], ['nombre', 'estado']);
        $I->assertTrue($success);
        $success = $connection->update(
            'prueba',
            ["nombre", 'estado'],
            ["LOL array syntax 2", 'X'],
            [
                'conditions' => "nombre=? and estado = ?",
                'bind'       => ["LOL array syntax", "E"],
                'bindTypes'  => [PDO::PARAM_STR, PDO::PARAM_STR],
            ],
            [PDO::PARAM_STR, PDO::PARAM_STR]
        );
        $I->assertTrue($success);
        $row = $connection->fetchOne(
            'select count(*) as cnt from prueba where nombre=? and estado=?',
            Db::FETCH_ASSOC,
            [
                "LOL array syntax 2", "X",
            ]
        );
        $I->assertEquals($row['cnt'], 1);
        $success = $connection->update('prueba', ["nombre", 'estado'], ["LOL array syntax 3", 'E'], [
            'conditions' => "nombre=? and estado = ?",
            'bind'       => ["LOL array syntax 2", "X"],
        ]);
        $I->assertTrue($success);
        $row = $connection->fetchOne(
            'select count(*) as cnt from prueba where nombre=? and estado=?',
            Db::FETCH_ASSOC,
            [
                "LOL array syntax 3", "E",
            ]
        );
        $I->assertEquals($row['cnt'], 1);

        //test insertAsDict and updateAsDict
        $success = $connection->insertAsDict('prueba', [
            'nombre' => "LOL insertAsDict",
            'estado' => "E",
        ]);

        $I->assertTrue($success);
        $row = $connection->fetchOne(
            'select count(*) as cnt from prueba where nombre=? and estado=?',
            Db::FETCH_ASSOC,
            [
                "LOL insertAsDict", "E",
            ]
        );
        $I->assertEquals($row['cnt'], 1);
        $success = $connection->updateAsDict(
            'prueba',
            [
                'nombre' => "LOL updateAsDict",
                'estado' => "X",
            ],
            "nombre='LOL insertAsDict' and estado = 'E'"
        );
        $I->assertTrue($success);
        $row = $connection->fetchOne(
            'select count(*) as cnt from prueba where nombre=? and estado=?',
            Db::FETCH_ASSOC,
            [
                "LOL updateAsDict", "X",
            ]
        );
        $I->assertEquals($row['cnt'], 1);

        $connection->delete("prueba", "estado='X'");
        $I->assertTrue($success);

        $connection->delete("prueba");
        $I->assertTrue($success);
        $I->assertEquals($connection->affectedRows(), 54);

        $row = $connection->fetchOne("SELECT * FROM personas");
        $I->assertCount(11, $row);

        $row = $connection->fetchOne("SELECT * FROM personas", Db::FETCH_NUM);
        $I->assertCount(11, $row);

        $rows = $connection->fetchAll("SELECT * FROM personas LIMIT 10");
        $I->assertCount(10, $rows);

        $rows = $connection->fetchAll("SELECT * FROM personas LIMIT 10", Db::FETCH_NUM);
        $I->assertCount(10, $rows);
        $I->assertCount(11, $rows[0]);

        $id = $connection->fetchColumn("SELECT id FROM robots ORDER BY year DESC");
        $I->assertEquals($id, 3);

        $type = $connection->fetchColumn("SELECT * FROM robots where id=?", [1], 2);
        $I->assertEquals($type, 'mechanical');

        $type = $connection->fetchColumn("SELECT * FROM robots where id=?", [1], 'type');
        $I->assertEquals($type, 'mechanical');

        //Auto-Increment/Serial Columns
        $sql     = 'INSERT INTO subscriptores(id, email, created_at, status) VALUES (' . $connection->getDefaultIdValue() . ', ?, ?, ?)';
        $success = $connection->execute($sql, ['shirley@garbage.com', "2011-01-01 12:59:13", "P"]);
        $I->assertTrue($success);

        //Check for auto-increment column
        $I->assertTrue($connection->lastInsertId('subscriptores_id_seq') > 0);

        // Create View
        $success = $connection->createView(
            'phalcon_test_view',
            [
                'sql' => 'SELECT 1 AS one, 2 AS two, 3 AS three',
            ]
        );
        $I->assertTrue($success);

        //Check view exists
        $success = $connection->viewExists('phalcon_test_view');
        $I->assertTrue((bool) $success);

        //Gets the list of all views.
        $views = $connection->listViews();
        $I->assertInternalType('array', $views);
        $I->assertContains('phalcon_test_view', $views);

        //Execute created view
        $row = $connection->fetchOne("SELECT * FROM phalcon_test_view");
        $I->assertCount(3, $row);
        $I->assertArrayHasKey('one', $row);
        $I->assertEquals($row['two'], 2);

        //Drop view
        $success = $connection->dropView('phalcon_test_view');
        $I->assertTrue($success);

        //Transactions without savepoints.
        $connection->setNestedTransactionsWithSavepoints(false);

        $success = $connection->begin(); // level 1 - real
        $I->assertTrue($success);

        $success = $connection->begin(); // level 2 - virtual
        $I->assertFalse($success);

        $success = $connection->begin(); // level 3 - virtual
        $I->assertFalse($success);

        $success = $connection->rollback(); // level 2 - virtual
        $I->assertFalse($success);

        $success = $connection->commit(); // level 1 - virtual
        $I->assertFalse($success);

        $success = $connection->commit(); // commit - real
        $I->assertTrue($success);

        $success = $connection->begin(); // level 1 - real
        $I->assertTrue($success);

        $success = $connection->begin(); // level 2 - virtual
        $I->assertFalse($success);

        $success = $connection->commit(); // level 1 - virtual
        $I->assertFalse($success);

        $success = $connection->rollback(); // rollback - real
        $I->assertTrue($success);

        //Transactions with savepoints.
        $connection->setNestedTransactionsWithSavepoints(true);

        $success = $connection->begin(); // level 1 - begin transaction
        $I->assertTrue($success);

        $success = $connection->begin(); // level 2 - uses savepoint_1
        $I->assertTrue($success);

        $success = $connection->begin(); // level 3 - uses savepoint_2
        $I->assertTrue($success);

        $success = $connection->rollback(); // level 2 - uses rollback savepoint_2
        $I->assertTrue($success);

        $success = $connection->commit(); // level 1  - uses release savepoint_1
        $I->assertTrue($success);

        $success = $connection->commit(); // commit - real commit
        $I->assertTrue($success);

        $success = $connection->begin(); // level 1 - real begin transaction
        $I->assertTrue($success);

        $success = $connection->begin(); // level 2 - uses savepoint_1
        $I->assertTrue($success);

        $success = $connection->commit(); // level 1 - uses release savepoint_1
        $I->assertTrue($success);

        $success = $connection->rollback(); // rollback - real rollback
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
    public function dbPostgresql(IntegrationTester $I)
    {
        $I->wantToTest("Db - Postgresql");
        $this->setDiPostgresql();
        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
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

        $this->executeTests($I, $connection);
    }
}
