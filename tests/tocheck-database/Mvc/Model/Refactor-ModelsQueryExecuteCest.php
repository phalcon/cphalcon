<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class ModelsQueryExecuteCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    public function testExecuteMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->testSelectExecute($I);
        $this->testSelectRenamedExecute($I);
        $this->testInsertExecute($I);
        $this->testInsertRenamedExecute($I);
        $this->testUpdateExecute($I);
        $this->testUpdateRenamedExecute($I);
        $this->testDeleteExecute($I);
        $this->testDeleteRenamedExecute($I);
    }

    public function testExecutePostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->testSelectExecute($I);
        $this->testSelectRenamedExecute($I);
        $this->testInsertExecute($I);
        $this->testInsertRenamedExecute($I);
        $this->testUpdateExecute($I);
        $this->testUpdateRenamedExecute($I);
        $this->testDeleteExecute($I);
        $this->testDeleteRenamedExecute($I);
    }

    public function testExecuteSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        /**
         * @todo Check Sqlite tests - they lock up
         */

//        $this->testSelectExecute($I);
//        $this->testSelectRenamedExecute($I);
//        $this->testInsertExecute($I);
//        $this->testInsertRenamedExecute($I);
//        $this->testUpdateExecute($I);
//        $this->testUpdateRenamedExecute($I);
//        $this->testDeleteExecute($I);
//        $this->testDeleteRenamedExecute($I);
    }

    private function testSelectExecute(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check the numbers on this test');

        $manager = $this->container->getShared('modelsManager');

        $robots = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);

        $robots = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robots ORDER BY 1'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);
        $I->assertEquals(1, $robots[0]->id);

        $robots = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robots ORDER BY id'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);
        $I->assertEquals(1, $robots[0]->id);

        $robots = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robots ORDER BY Phalcon\Test\Models\Robots.id'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);
        $I->assertEquals(1, $robots[0]->id);

        $robots = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.* FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);
        $I->assertCount(3, $robots);

        $robots = $manager->executeQuery(
            'SELECT r.* FROM Phalcon\Test\Models\Robots r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);
        $I->assertCount(3, $robots);

        $robots = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robots r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);
        $I->assertCount(3, $robots);

        $robots = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robots AS r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);
        $I->assertCount(3, $robots);

        $robots = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robots AS r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $robots[0]);
        $I->assertCount(3, $robots);

        $result = $manager->executeQuery(
            'SELECT id, name FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.name FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT LENGTH(name) AS the_length FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->the_length));
        $I->assertEquals(8, $result[0]->the_length);

        $result = $manager->executeQuery(
            'SELECT LENGTH(Phalcon\Test\Models\Robots.name) AS the_length ' .
            'FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->the_length));
        $I->assertEquals(8, $result[0]->the_length);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.id+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robots WHERE id = 1'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals(2, $result[0]->nextId);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.id+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robots WHERE id = ?0',
            [0 => 1]
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals(2, $result[0]->nextId);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.id+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robots WHERE id = :id:',
            ['id' => 1]
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals(2, $result[0]->nextId);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.id+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robots WHERE id = "1"'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals(2, $result[0]->nextId);

        $result = $manager->executeQuery(
            'SELECT r.year FROM Phalcon\Test\Models\Robots r WHERE TRIM(name) != "Robotina"'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.id+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robots ORDER BY id'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertCount(3, $result);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals(2, $result[0]->nextId);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.id+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robots ORDER BY id LIMIT 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertCount(2, $result);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals(2, $result[0]->nextId);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.id+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robots ORDER BY id DESC LIMIT 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertCount(2, $result);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals(4, $result[0]->nextId);

        $result = $manager->executeQuery(
            'SELECT r.name FROM Phalcon\Test\Models\Robots r ORDER BY r.name DESC LIMIT 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->name));
        $I->assertEquals($result[0]->name, 'Terminator');

        $result = $manager->executeQuery(
            'SELECT name le_name FROM Phalcon\Test\Models\Robots ORDER BY name ASC LIMIT 4'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->le_name));
        $I->assertEquals('Astro Boy', $result[0]->le_name);

        $result = $manager->executeQuery(
            'SELECT r.name le_name FROM Phalcon\Test\Models\Robots r ORDER BY r.name ASC LIMIT 4'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->le_name));
        $I->assertEquals('Astro Boy', $result[0]->le_name);

        $result = $manager->executeQuery(
            'SELECT r.name le_name FROM Phalcon\Test\Models\Robots r ORDER BY r.name ASC LIMIT 1,2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->le_name));
        $I->assertEquals('Robotina', $result[0]->le_name);

        $result = $manager->executeQuery(
            'SELECT r.name le_name ' .
            'FROM Phalcon\Test\Models\Robots r ORDER BY r.name ASC LIMIT 2 OFFSET 1'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->le_name));
        $I->assertEquals('Robotina', $result[0]->le_name);

        $result = $manager->executeQuery(
            'SELECT r.type, COUNT(*) number ' .
            'FROM Phalcon\Test\Models\Robots r GROUP BY 1 ORDER BY r.type ASC'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertEquals(2, $result[1]->number);

        $result = $manager->executeQuery(
            'SELECT r.type, SUM(r.year-1000) age ' .
            'FROM Phalcon\Test\Models\Robots r GROUP BY 1 ORDER BY 2 DESC'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertEquals(1924, $result[0]->age);

        $result = $manager->executeQuery(
            'SELECT r.type, COUNT(*) number ' .
            'FROM Phalcon\Test\Models\Robots r GROUP BY 1 HAVING COUNT(*) = 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertEquals(2, $result[0]->number);

        $result = $manager->executeQuery(
            'SELECT r.type, COUNT(*) number ' .
            'FROM Phalcon\Test\Models\Robots r GROUP BY 1 HAVING COUNT(*) < 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertCount(1, $result);
        $I->assertEquals(1, $result[0]->number);

        $result = $manager->executeQuery(
            'SELECT r.id, r.* FROM Phalcon\Test\Models\Robots r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        /**
         * @todo - check this
         */
        // $I->assertNotInternalType('object', $result[0]->id);
        $I->assertTrue(is_object($result[0]->r));
        $I->assertCount(3, $result);
        $I->assertEquals(1, $result[0]->id);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.*, Phalcon\Test\Models\RobotsParts.* ' .
            'FROM Phalcon\Test\Models\Robots JOIN Phalcon\Test\Models\RobotsParts ' .
            'ORDER BY Phalcon\Test\Models\Robots.id, Phalcon\Test\Models\RobotsParts.id'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertTrue(is_object($result[0]->robots));
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $result[0]->robots);
        $I->assertTrue(is_object($result[0]->robotsParts));
        $I->assertInstanceOf(\RobotsParts::class, $result[0]->robotsParts);
        $I->assertCount(3, $result);
        $I->assertEquals(1, $result[0]->robots->id);
        $I->assertEquals(1, $result[0]->robotsParts->id);
        $I->assertEquals(1, $result[1]->robots->id);
        $I->assertEquals(2, $result[1]->robotsParts->id);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robots.*, Phalcon\Test\Models\RobotsParts.* ' .
            'FROM Phalcon\Test\Models\Robots JOIN Phalcon\Test\Models\RobotsParts ' .
            'ON Phalcon\Test\Models\Robots.id = Phalcon\Test\Models\RobotsParts.robots_id ' .
            'ORDER BY Phalcon\Test\Models\Robots.id, Phalcon\Test\Models\RobotsParts.id'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertTrue(is_object($result[0]->robots));
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $result[0]->robots);
        $I->assertTrue(is_object($result[0]->robotsParts));
        $I->assertInstanceOf('RobotsParts', $result[0]->robotsParts);
        $I->assertCount(3, $result);
        $I->assertEquals($result[0]->robots->id, 1);
        $I->assertEquals($result[0]->robotsParts->id, 1);
        $I->assertEquals($result[1]->robots->id, 1);
        $I->assertEquals($result[1]->robotsParts->id, 2);

        $result = $manager->executeQuery(
            'SELECT r.*, p.* ' .
            'FROM Phalcon\Test\Models\Robots r ' .
            'JOIN Phalcon\Test\Models\RobotsParts p ON r.id = p.robots_id ORDER BY r.id, p.id'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertTrue(is_object($result[0]->r));
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots::class, $result[0]->r);
        $I->assertTrue(is_object($result[0]->p));
        $I->assertInstanceOf(\Phalcon\Test\Models\RobotsParts::class, $result[0]->p);
        $I->assertCount(3, $result);
        $I->assertEquals($result[0]->r->id, 1);
        $I->assertEquals($result[0]->p->id, 1);
        $I->assertEquals($result[1]->r->id, 1);
        $I->assertEquals($result[1]->p->id, 2);

        /** Joins with namespaces */
        /**
         * @todo - check this
         */
//        $result = $manager->executeQuery(
//            'SELECT Phalcon\Test\Models\Some\Robots.*, Phalcon\Test\Models\Some\RobotsParts.* ' .
//            'FROM Phalcon\Test\Models\Some\Robots JOIN Phalcon\Test\Models\Some\RobotsParts ' .
//            'ON Phalcon\Test\Models\Some\Robots.id = Phalcon\Test\Models\Some\RobotsParts.robots_id ' .
//            'ORDER BY Phalcon\Test\Models\Some\Robots.id, Phalcon\Test\Models\Some\RobotsParts.id'
//        );
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
//        $I->assertInternalType('object', $result[0]->{\Phalcon\Test\Models\Some\Robots::class});
//        $I->assertInstanceOf(
//          \Phalcon\Test\Models\Robots::class,
//          $result[0]->{\Phalcon\Test\Models\Some\Robots::class}
//        );
//        $I->assertInternalType('object', $result[0]->{\Phalcon\Test\Models\Some\RobotsParts::class});
//        $I->assertInstanceOf(
//          \Phalcon\Test\Models\RobotsParts::class,
//           $result[0]->{\Phalcon\Test\Models\Some\RobotsParts::class}
//        );
//        $I->assertCount(3, $result);
//        $I->assertEquals($result[0]->{'some\Robots'}->id, 1);
//        $I->assertEquals($result[0]->{'some\RobotsParts'}->id, 1);
//        $I->assertEquals($result[1]->{'some\Robots'}->id, 1);
//        $I->assertEquals($result[1]->{'some\RobotsParts'}->id, 2);

        /** Joins with namespaces and aliases */
        $result = $manager->executeQuery(
            'SELECT r.*, p.* ' .
            'FROM Phalcon\Test\Models\Some\Robots r ' .
            'JOIN Phalcon\Test\Models\Some\RobotsParts p ON r.id = p.robots_id ' .
            'ORDER BY r.id, p.id'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertTrue(is_object($result[0]->r));
        $I->assertInstanceOf(\Phalcon\Test\Models\Some\Robots::class, $result[0]->r);
        $I->assertTrue(is_object($result[0]->p));
        $I->assertInstanceOf(\Phalcon\Test\Models\Some\RobotsParts::class, $result[0]->p);
        $I->assertCount(3, $result);
        $I->assertEquals(1, $result[0]->r->id);
        $I->assertEquals(1, $result[0]->p->id);
        $I->assertEquals(1, $result[1]->r->id);
        $I->assertEquals(2, $result[1]->p->id);

        $result = $manager->executeQuery(
            'SELECT id, name FROM Phalcon\Test\Models\Some\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT id, name FROM Phalcon\Test\Models\Some\Robots ORDER BY name DESC LIMIT 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT ALL estado FROM Phalcon\Test\Models\Personas LIMIT 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT DISTINCT estado FROM Phalcon\Test\Models\Personas'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        /**
         * @todo Check this for Sqlite
         */
//        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT count(DISTINCT estado) FROM Phalcon\Test\Models\Personas'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertCount(1, $result);
        /**
         * @todo Check this for Sqlite
         */
//        $I->assertEquals(2, $result[0]->{"0"});
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT CASE 1 WHEN 1 THEN 2 END FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertEquals(2, $result[0]->{'0'});

        $result = $manager->executeQuery(
            'SELECT CASE 2 WHEN 1 THEN 2 WHEN 2 THEN 3 END FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertEquals(3, $result[0]->{'0'});

        $result = $manager->executeQuery(
            'SELECT CASE 2 WHEN 1 THEN 2 ELSE 3 END FROM Phalcon\Test\Models\Robots'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertEquals(3, $result[0]->{'0'});

        // Issue 1011
        /*$result = $manager->executeQuery('SELECT r.name le_name FROM Robots r ORDER BY r.name ASC LIMIT ?1,?2',
            array(1 => 1, 2 => 2),
            array(1 => \Phalcon\Db\Column::BIND_PARAM_INT, 2 => \Phalcon\Db\Column::BIND_PARAM_INT
        ));
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->le_name));
        $I->assertEquals($result[0]->le_name, 'Robotina');*/
    }

    private function testSelectRenamedExecute(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $robotters = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robotters'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertCount(3, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);

        $robotters = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robotters ORDER BY 1'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertCount(3, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);
        $I->assertEquals($robotters[0]->code, 1);

        $robotters = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robotters ORDER BY code'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertCount(3, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);
        $I->assertEquals($robotters[0]->code, 1);

        $robotters = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robotters ORDER BY Phalcon\Test\Models\Robotters.code'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertCount(3, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);
        $I->assertEquals($robotters[0]->code, 1);

        $robotters = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.* FROM Phalcon\Test\Models\Robotters'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);
        $I->assertCount(3, $robotters);

        $robotters = $manager->executeQuery(
            'SELECT r.* FROM Phalcon\Test\Models\Robotters r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);
        $I->assertCount(3, $robotters);

        $robotters = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robotters r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);
        $I->assertCount(3, $robotters);

        $robotters = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robotters AS r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);
        $I->assertCount(3, $robotters);

        $robotters = $manager->executeQuery(
            'SELECT * FROM Phalcon\Test\Models\Robotters AS r'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robotters);
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $robotters[0]);
        $I->assertCount(3, $robotters);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.theName FROM Phalcon\Test\Models\Robotters'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT LENGTH(Phalcon\Test\Models\Robotters.theName) AS the_length ' .
            'FROM Phalcon\Test\Models\Robotters'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->the_length));
        $I->assertEquals($result[0]->the_length, 8);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.code+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robotters WHERE code = 1'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals($result[0]->nextId, 2);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.code+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robotters WHERE code = ?0',
            [
                0 => 1,
            ]
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals($result[0]->nextId, 2);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.code+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robotters WHERE code = :code:',
            [
                'code' => 1,
            ]
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals($result[0]->nextId, 2);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.code+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robotters WHERE code = "1"'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals($result[0]->nextId, 2);

        $result = $manager->executeQuery(
            'SELECT r.theYear ' .
            'FROM Phalcon\Test\Models\Robotters r WHERE TRIM(theName) != "Robotina"'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.code+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robotters ORDER BY code'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertCount(3, $result);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals($result[0]->nextId, 2);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.code+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robotters ORDER BY code LIMIT 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertCount(2, $result);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals($result[0]->nextId, 2);

        $result = $manager->executeQuery(
            'SELECT Phalcon\Test\Models\Robotters.code+1 AS nextId ' .
            'FROM Phalcon\Test\Models\Robotters ORDER BY code DESC LIMIT 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertCount(2, $result);
        $I->assertTrue(isset($result[0]->nextId));
        $I->assertEquals($result[0]->nextId, 4);

        $result = $manager->executeQuery(
            'SELECT r.theName FROM Phalcon\Test\Models\Robotters r ORDER BY r.theName DESC LIMIT 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->theName));
        $I->assertEquals($result[0]->theName, 'Terminator');

        $result = $manager->executeQuery(
            'SELECT r.theName le_theName ' .
            'FROM Phalcon\Test\Models\Robotters r ORDER BY r.theName ASC LIMIT 4'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(3, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->le_theName));
        $I->assertEquals($result[0]->le_theName, 'Astro Boy');

        $result = $manager->executeQuery(
            'SELECT r.theName le_theName ' .
            'FROM Phalcon\Test\Models\Robotters r ORDER BY r.theName ASC LIMIT 1,2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->le_theName));
        $I->assertEquals($result[0]->le_theName, 'Robotina');

        $result = $manager->executeQuery(
            'SELECT r.theName le_theName ' .
            'FROM Phalcon\Test\Models\Robotters r ORDER BY r.theName ASC LIMIT 2 OFFSET 1'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertTrue(isset($result[0]->le_theName));
        $I->assertEquals($result[0]->le_theName, 'Robotina');

        $result = $manager->executeQuery(
            'SELECT r.theType, COUNT(*) number ' .
            'FROM Phalcon\Test\Models\Robotters r GROUP BY 1 ORDER BY r.theType ASC'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertEquals($result[1]->number, 2);

        $result = $manager->executeQuery(
            'SELECT r.theType, SUM(r.theYear-1000) age ' .
            'FROM Phalcon\Test\Models\Robotters r GROUP BY 1 ORDER BY 2 DESC'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(2, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertEquals($result[0]->age, 1924);

        $result = $manager->executeQuery(
            'SELECT r.theType, COUNT(*) number ' .
            'FROM Phalcon\Test\Models\Robotters r GROUP BY 1 HAVING COUNT(*) = 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertCount(1, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertEquals($result[0]->number, 2);

        $result = $manager->executeQuery(
            'SELECT r.theType, COUNT(*) number ' .
            'FROM Phalcon\Test\Models\Robotters r GROUP BY 1 HAVING COUNT(*) < 2'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Row::class, $result[0]);
        $I->assertCount(1, $result);
        $I->assertEquals($result[0]->number, 1);

        $result = $manager->executeQuery('SELECT r.code, r.* FROM Phalcon\Test\Models\Robotters r');
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        /**
         * @todo Check this
         */
        // $I->assertNotInternalType('object', $result[0]->code);
        /**
         * @todo Check this
         */
//        $I->assertInternalType('object', $result[0]->r);
//        $I->assertCount(3, $result);
//        $I->assertEquals($result[0]->code, 1);
//
//        $result = $manager->executeQuery(
//            'SELECT Phalcon\Test\Models\Robotters.*, Phalcon\Test\Models\RobottersDeles.* ' .
//            'FROM Phalcon\Test\Models\Robotters ' .
//            'JOIN Phalcon\Test\Models\RobottersDeles ' .
//            'ORDER BY Phalcon\Test\Models\Robotters.code, Phalcon\Test\Models\RobottersDeles.code'
//        );
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
//        $I->assertInternalType('object', $result[0]->robotters);
//        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $result[0]->robotters);
//        $I->assertInternalType('object', $result[0]->robottersDeles);
//        $I->assertInstanceOf(\Phalcon\Test\Models\RobottersDeles::class, $result[0]->robottersDeles);
//        $I->assertCount(3, $result);
//        $I->assertEquals($result[0]->robotters->code, 1);
//        $I->assertEquals($result[0]->robottersDeles->code, 1);
//        $I->assertEquals($result[1]->robotters->code, 1);
//        $I->assertEquals($result[1]->robottersDeles->code, 2);
//
//        $result = $manager->executeQuery(
//            'SELECT Phalcon\Test\Models\Robotters.*, Phalcon\Test\Models\RobottersDeles.* ' .
//            'FROM Phalcon\Test\Models\Robotters ' .
//            'JOIN Phalcon\Test\Models\RobottersDeles ' .
//            'ON Phalcon\Test\Models\Robotters.code = Phalcon\Test\Models\RobottersDeles.robottersCode ' .
//            'ORDER BY Phalcon\Test\Models\Robotters.code, Phalcon\Test\Models\RobottersDeles.code'
//        );
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
//        $I->assertInternalType('object', $result[0]->robotters);
//        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $result[0]->robotters);
//        $I->assertInternalType('object', $result[0]->robottersDeles);
//        $I->assertInstanceOf('RobottersDeles', $result[0]->robottersDeles);
//        $I->assertCount(3, $result);
//        $I->assertEquals($result[0]->robotters->code, 1);
//        $I->assertEquals($result[0]->robottersDeles->code, 1);
//        $I->assertEquals($result[1]->robotters->code, 1);
//        $I->assertEquals($result[1]->robottersDeles->code, 2);

        $result = $manager->executeQuery(
            'SELECT r.*, p.* ' .
            'FROM Phalcon\Test\Models\Robotters r ' .
            'JOIN Phalcon\Test\Models\RobottersDeles p ' .
            'ON r.code = p.robottersCode ' .
            'ORDER BY r.code, p.code'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
        $I->assertTrue(is_object($result[0]->r));
        $I->assertInstanceOf(\Phalcon\Test\Models\Robotters::class, $result[0]->r);
        $I->assertTrue(is_object($result[0]->p));
        $I->assertInstanceOf(\Phalcon\Test\Models\RobottersDeles::class, $result[0]->p);
        $I->assertCount(3, $result);
        $I->assertEquals($result[0]->r->code, 1);
        $I->assertEquals($result[0]->p->code, 1);
        $I->assertEquals($result[1]->r->code, 1);
        $I->assertEquals($result[1]->p->code, 2);

        $result = $manager->executeQuery(
            'SELECT r.* ' .
            'FROM Phalcon\Test\Models\RobotsParts rp ' .
            'LEFT JOIN Phalcon\Test\Models\Robots2 r ON rp.robots_id=r.id'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);
        $I->assertTrue(is_object($result[0]));
        $I->assertInstanceOf(\Phalcon\Test\Models\Robots2::class, $result[0]);
        $I->assertNotNull($result[0]->getName());

        $result = $manager->executeQuery(
            'SELECT r.* ' .
            'FROM Phalcon\Test\Models\Robots r ' .
            'WHERE r.id NOT IN (SELECT p.id ' .
            'FROM Phalcon\Test\Models\Parts p WHERE r.id < p.id)'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $result);

        $result = $manager->executeQuery(
            'SELECT * ' .
            'FROM Phalcon\Test\Models\Robots r ' .
            'JOIN Phalcon\Test\Models\RobotsParts rp ' .
            'WHERE rp.id IN (SELECT p.id ' .
            'FROM Phalcon\Test\Models\Parts p WHERE rp.parts_id = p.id)'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);

        $result = $manager->executeQuery(
            'SELECT * ' .
            'FROM Phalcon\Test\Models\Robots r ' .
            'JOIN Phalcon\Test\Models\RobotsParts rp ' .
            'WHERE r.id IN (SELECT p.id ' .
            'FROM Phalcon\Test\Models\Parts p)'
        );
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Complex::class, $result);
    }

    private function testInsertExecute(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $this->container->getShared('db')->delete('subscriptores');

        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Subscriptores ' .
            'VALUES (NULL, "marina@hotmail.com", "2011-01-01 09:01:01", "P")'
        );
        $I->assertFalse($status->success());
        $messages = $status->getMessages();
        $I->assertEquals(null, $messages[0]->getType());
        $I->assertEquals('Sorry Marina, but you are not allowed here', $messages[0]->getMessage());
        $I->assertEquals(null, $messages[0]->getField());
        $I->assertEquals(0, $messages[0]->getCode());
        $I->assertEquals([], $messages[0]->getMetaData());

        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Subscriptores ' .
            'VALUES (NULL, "dtmail.com", "2011-01-01 09:01:01", "P")'
        );
        $I->assertFalse($status->success());
        $messages = $status->getMessages();
        $I->assertEquals('Email', $messages[0]->getType());
        $I->assertEquals('Field email must be an email address', $messages[0]->getMessage());
        $I->assertEquals('email', $messages[0]->getField());
        $I->assertEquals(0, $messages[0]->getCode());
        $I->assertEquals([], $messages[0]->getMetaData());

        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Subscriptores ' .
            'VALUES (NULL, "le-marina@hotmail.com", "2011-01-01 09:01:01", "P")'
        );
        $I->assertTrue($status->success());

        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Subscriptores ' .
            'VALUES (NULL, "sonny@hotmail.com", "2010-01-01 13:21:00", "P")'
        );
        $I->assertTrue($status->success());

        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Subscriptores (email, created_at, status) ' .
            'VALUES ("hideaway@hotmail.com", "2010-01-01 13:21:00", "P")'
        );
        $I->assertTrue($status->success());

        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Subscriptores (email, created_at, status) ' .
            'VALUES (:email:, :created_at:, :status:)',
            [
                'email'      => 'yeahyeah@hotmail.com',
                'created_at' => '2010-02-01 13:21:00',
                'status'     => 'P',
            ]
        );
        $I->assertTrue($status->success());

        $I->assertGreaterThan(
            0,
            $status->getModel()->id
        );
    }

    private function testInsertRenamedExecute(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $this->container->getShared('db')->delete('subscriptores');

        /**
         * This test must fail because the email is not allowed as a model business rule
         */
        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Abonnes ' .
            'VALUES (NULL, "marina@hotmail.com", "2011-01-01 09:01:01", "P")'
        );
        $I->assertFalse($status->success());
        $messages = $status->getMessages();
        $I->assertEquals(null, $messages[0]->getType());
        $I->assertEquals('Désolé Marina, mais vous n\'êtes pas autorisé ici', $messages[0]->getMessage());
        $I->assertEquals(null, $messages[0]->getField());
        $I->assertEquals(0, $messages[0]->getCode());
        $I->assertEquals([], $messages[0]->getMetaData());


        /**
         * This test must fail because the email is invalid
         */
        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Abonnes ' .
            'VALUES (NULL, "dtmail.com", "2011-01-01 09:01:01", "P")'
        );
        $I->assertFalse($status->success());
        $messages = $status->getMessages();
        $I->assertEquals('Email', $messages[0]->getType());
        $I->assertEquals('Le courrier électronique est invalide', $messages[0]->getMessage());
        $I->assertEquals('courrierElectronique', $messages[0]->getField());
        $I->assertEquals(0, $messages[0]->getCode());
        $I->assertEquals([], $messages[0]->getMetaData());

        /**
         * This test must pass
         */
        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Abonnes ' .
            'VALUES (NULL, "le-marina@hotmail.com", "2011-01-01 09:01:01", "P")'
        );
        $I->assertTrue($status->success());

        /**
         * This test must pass
         */
        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Abonnes ' .
            'VALUES (NULL, "sonny@hotmail.com", "2010-01-01 13:21:00", "P")'
        );
        $I->assertTrue($status->success());

        /**
         * This test must pass
         */
        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Abonnes (courrierElectronique, creeA, statut) ' .
            'VALUES ("hideaway@hotmail.com", "2010-01-01 13:21:00", "P")'
        );
        $I->assertTrue($status->success());

        $status = $manager->executeQuery(
            'INSERT INTO Phalcon\Test\Models\Abonnes (courrierElectronique, creeA, statut) ' .
            'VALUES (:courrierElectronique:, :creeA:, :statut:)',
            [
                'courrierElectronique' => 'yeahyeah@hotmail.com',
                'creeA'                => '2010-02-01 13:21:00',
                'statut'               => 'P',
            ]
        );
        $I->assertTrue($status->success());

        $I->assertGreaterThan(
            0,
            $status->getModel()->code
        );
    }

    private function testUpdateExecute(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $this->container->getShared('db')->execute(
            "UPDATE personas SET ciudad_id = NULL WHERE direccion = 'COL'"
        )
        ;

        $status = $manager->executeQuery(
            "UPDATE Phalcon\Test\Models\People SET direccion = 'COL' ' .
            'WHERE ciudad_id IS NULL LIMIT 25"
        );
        $I->assertTrue($status->success());

        $status = $manager->executeQuery(
            'UPDATE Phalcon\Test\Models\People SET direccion = :direccion: ' .
            'WHERE ciudad_id IS NULL LIMIT 25',
            [
                'direccion' => 'MXN',
            ]
        );
        $I->assertTrue($status->success());

        $status = $manager->executeQuery(
            'UPDATE Phalcon\Test\Models\Subscriptores SET status = :status: WHERE email = :email:',
            [
                'status' => 'I',
                'email'  => 'le-marina@hotmail.com',
            ]
        );
        $I->assertTrue($status->success());

        // Issue 1011
        /*$status = $manager->executeQuery(
            'UPDATE Subscriptores SET status = :status: WHERE email = :email: LIMIT :limit:',
            array(
                "status" => "I",
                "email" => "le-marina@hotmail.com",
                "limit" => 1,
            ),
            array('email' => \Phalcon\Db\Column::BIND_PARAM_STR, //'limit' => \Phalcon\Db\Column::BIND_PARAM_INT
            )
        );
        $I->assertTrue($status->success());*/
    }

    private function testUpdateRenamedExecute(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $this->container->getShared('db')->execute(
            "UPDATE personas SET ciudad_id = NULL WHERE direccion = 'COL'"
        )
        ;

        $status = $manager->executeQuery(
            "UPDATE Phalcon\Test\Models\Personers SET adresse = 'COL' ' .
            'WHERE fodebyId IS NULL LIMIT 25"
        );
        $I->assertTrue($status->success());

        $status = $manager->executeQuery(
            'UPDATE Phalcon\Test\Models\Personers SET adresse = :adresse: ' .
            'WHERE fodebyId IS NULL LIMIT 25',
            [
                'adresse' => 'MXN',
            ]
        );
        $I->assertTrue($status->success());

        $status = $manager->executeQuery(
            'UPDATE Phalcon\Test\Models\Abonnes SET statut = :statut: ' .
            'WHERE courrierElectronique = :courrierElectronique:',
            [
                'statut'               => 'I',
                'courrierElectronique' => 'le-marina@hotmail.com',
            ]
        );
        $I->assertTrue($status->success());
    }

    private function testDeleteExecute(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $status = $manager->executeQuery(
            'DELETE FROM Phalcon\Test\Models\Subscriptores ' .
            'WHERE email = "marina@hotmail.com"'
        );

        $I->assertTrue(
            $status->success()
        );


        $status = $manager->executeQuery(
            'DELETE FROM Phalcon\Test\Models\Subscriptores ' .
            'WHERE status = :status: AND email <> :email:',
            [
                'status' => 'P',
                'email'  => 'fuego@hotmail.com',
            ]
        );

        $I->assertTrue(
            $status->success()
        );


        // Issue 1011
        /*$status = $manager->executeQuery(
            'DELETE FROM Subscriptores WHERE status = :status: AND email <> :email: LIMIT :limit:',
            array(
                "status" => "P",
                "email" => "fuego@hotmail.com",
                "limit" => 1,
            ),
            array('email' => \Phalcon\Db\Column::BIND_PARAM_STR) ///* 'limit' => \Phalcon\Db\Column::BIND_PARAM_INT
        );
        $I->assertTrue($status->success());*/
    }

    private function testDeleteRenamedExecute(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $status = $manager->executeQuery(
            'DELETE FROM Phalcon\Test\Models\Abonnes ' .
            'WHERE courrierElectronique = "marina@hotmail.com"'
        );

        $I->assertTrue(
            $status->success()
        );


        $status = $manager->executeQuery(
            'DELETE FROM Phalcon\Test\Models\Abonnes ' .
            'WHERE statut = :statut: AND courrierElectronique <> :courrierElectronique:',
            [
                'statut'               => 'P',
                'courrierElectronique' => 'fuego@hotmail.com',
            ]
        );

        $I->assertTrue(
            $status->success()
        );
    }
}
