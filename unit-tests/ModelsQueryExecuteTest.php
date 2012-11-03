<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\Model\Query as Query;

class ModelsQueryExecuteTest extends PHPUnit_Framework_TestCase
{

	public function __construct()
	{
		spl_autoload_register(array($this, 'modelsAutoloader'));
	}

	public function __destruct()
	{
		spl_autoload_unregister(array($this, 'modelsAutoloader'));
	}

	public function modelsAutoloader($className)
	{
		$className = str_replace("\\", DIRECTORY_SEPARATOR, $className);
		$path = 'unit-tests/app/models/'.$className.'.php';
		if (file_exists($path)) {
			require $path;
		}
	}

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function() {
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function() {
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		return $di;
	}

	public function testExecuteMysql(){

		$di = $this->_getDI();

		$di->set('db', function() {
			require 'unit-tests/app/config/config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		$this->_testSelectExecute($di);
		$this->_testInsertExecute($di);
		$this->_testUpdateExecute($di);
		$this->_testDeleteExecute($di);

	}

	public function testExecutePostgresql(){

		$di = $this->_getDI();

		$di->set('db', function() {
			require 'unit-tests/app/config/config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		$this->_testSelectExecute($di);
		$this->_testInsertExecute($di);
		$this->_testUpdateExecute($di);
		$this->_testDeleteExecute($di);

	}

	public function _testSelectExecute($di)
	{

		$manager = $di->getShared('modelsManager');

		$robots = $manager->executeQuery('SELECT * FROM Robots');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertEquals(count($robots), 3);
		$this->assertInstanceOf('Robots', $robots[0]);

		$robots = $manager->executeQuery('SELECT * FROM Robots ORDER BY 1');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertEquals(count($robots), 3);
		$this->assertInstanceOf('Robots', $robots[0]);
		$this->assertEquals($robots[0]->id, 1);

		$robots = $manager->executeQuery('SELECT * FROM Robots ORDER BY id');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertEquals(count($robots), 3);
		$this->assertInstanceOf('Robots', $robots[0]);
		$this->assertEquals($robots[0]->id, 1);

		$robots = $manager->executeQuery('SELECT * FROM Robots ORDER BY Robots.id');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertEquals(count($robots), 3);
		$this->assertInstanceOf('Robots', $robots[0]);
		$this->assertEquals($robots[0]->id, 1);

		$robots = $manager->executeQuery('SELECT Robots.* FROM Robots');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertInstanceOf('Robots', $robots[0]);
		$this->assertEquals(count($robots), 3);

		$robots = $manager->executeQuery('SELECT r.* FROM Robots r');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertInstanceOf('Robots', $robots[0]);
		$this->assertEquals(count($robots), 3);

		$robots = $manager->executeQuery('SELECT * FROM Robots r');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertInstanceOf('Robots', $robots[0]);
		$this->assertEquals(count($robots), 3);

		$robots = $manager->executeQuery('SELECT * FROM Robots AS r');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertInstanceOf('Robots', $robots[0]);
		$this->assertEquals(count($robots), 3);

		$robots = $manager->executeQuery('SELECT * FROM Robots AS r');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robots);
		$this->assertInstanceOf('Robots', $robots[0]);
		$this->assertEquals(count($robots), 3);

		$result = $manager->executeQuery('SELECT Robots.name FROM Robots');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 3);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);

		$result = $manager->executeQuery('SELECT CONCAT(Robots.id, Robots.name) AS new_name FROM Robots');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 3);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->new_name));
		$this->assertEquals($result[0]->new_name, '1Robotina');

		$result = $manager->executeQuery('SELECT Robots.id+1 AS nextId FROM Robots WHERE id = 1');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 1);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->nextid));
		$this->assertEquals($result[0]->nextid, 2);

		$result = $manager->executeQuery('SELECT Robots.id+1 AS nextId FROM Robots WHERE id = ?0', array(0 => 1));
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 1);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->nextid));
		$this->assertEquals($result[0]->nextid, 2);

		$result = $manager->executeQuery('SELECT Robots.id+1 AS nextId FROM Robots WHERE id = :id:', array('id' => 1));
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 1);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->nextid));
		$this->assertEquals($result[0]->nextid, 2);

		$result = $manager->executeQuery('SELECT Robots.id+1 AS nextId FROM Robots WHERE id = "1"');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 1);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->nextid));
		$this->assertEquals($result[0]->nextid, 2);

		$result = $manager->executeQuery('SELECT r.year FROM Robots r WHERE TRIM(name) != "Robotina"');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 2);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);

		$result = $manager->executeQuery('SELECT Robots.id+1 AS nextId FROM Robots ORDER BY id');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertEquals(count($result), 3);
		$this->assertTrue(isset($result[0]->nextid));
		$this->assertEquals($result[0]->nextid, 2);

		$result = $manager->executeQuery('SELECT Robots.id+1 AS nextId FROM Robots ORDER BY id LIMIT 2');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertEquals(count($result), 2);
		$this->assertTrue(isset($result[0]->nextid));
		$this->assertEquals($result[0]->nextid, 2);

		$result = $manager->executeQuery('SELECT Robots.id+1 AS nextId FROM Robots ORDER BY id DESC LIMIT 2');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertEquals(count($result), 2);
		$this->assertTrue(isset($result[0]->nextid));
		$this->assertEquals($result[0]->nextid, 4);

		$result = $manager->executeQuery('SELECT r.name FROM Robots r ORDER BY r.name DESC LIMIT 2');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 2);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->name));
		$this->assertEquals($result[0]->name, 'Terminator');

		$result = $manager->executeQuery('SELECT r.name le_name FROM Robots r ORDER BY r.name ASC LIMIT 4');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 3);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->le_name));
		$this->assertEquals($result[0]->le_name, 'Astro Boy');

		$result = $manager->executeQuery('SELECT r.name le_name FROM Robots r ORDER BY r.name ASC LIMIT 1,2');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 2);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->le_name));
		$this->assertEquals($result[0]->le_name, 'Robotina');

		$result = $manager->executeQuery('SELECT r.name le_name FROM Robots r ORDER BY r.name ASC LIMIT 2 OFFSET 1');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 2);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertTrue(isset($result[0]->le_name));
		$this->assertEquals($result[0]->le_name, 'Robotina');

		$result = $manager->executeQuery('SELECT r.type, COUNT(*) number FROM Robots r GROUP BY 1 ORDER BY r.type ASC');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 2);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertEquals($result[1]->number, 2);

		$result = $manager->executeQuery('SELECT r.type, SUM(r.year-1000) age FROM Robots r GROUP BY 1 ORDER BY 2 DESC');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 2);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertEquals($result[0]->age, 1924);

		$result = $manager->executeQuery('SELECT r.type, COUNT(*) number FROM Robots r GROUP BY 1 HAVING COUNT(*) = 2');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertEquals(count($result), 1);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertEquals($result[0]->number, 2);

		$result = $manager->executeQuery('SELECT r.type, COUNT(*) number FROM Robots r GROUP BY 1 HAVING COUNT(*) < 2');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $result);
		$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $result[0]);
		$this->assertEquals(count($result), 1);
		$this->assertEquals($result[0]->number, 1);

		$result = $manager->executeQuery('SELECT r.id, r.* FROM Robots r');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Complex', $result);
		$this->assertNotEquals(gettype($result[0]->id), 'object');
		$this->assertEquals(gettype($result[0]->robots), 'object');
		$this->assertEquals(count($result), 3);
		$this->assertEquals($result[0]->id, 1);

		$result = $manager->executeQuery('SELECT Robots.*, RobotsParts.* FROM Robots JOIN RobotsParts ORDER BY Robots.id, RobotsParts.id');
		$this->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Complex', $result);
		$this->assertEquals(gettype($result[0]->robots), 'object');
		$this->assertEquals(get_class($result[0]->robots), 'Robots');
		$this->assertEquals(gettype($result[0]->robotsParts), 'object');
		$this->assertEquals(get_class($result[0]->robotsParts), 'RobotsParts');
		$this->assertEquals(count($result), 3);
		$this->assertEquals($result[0]->robots->id, 1);
		$this->assertEquals($result[0]->robotsParts->id, 1);
		$this->assertEquals($result[1]->robots->id, 1);
		$this->assertEquals($result[1]->robotsParts->id, 2);

	}

	public function _testInsertExecute($di)
	{

		$manager = $di->getShared('modelsManager');

		$di->getShared('db')->delete("subscriptores");

		$status = $manager->executeQuery('INSERT INTO Subscriptores VALUES (NULL, "marina@hotmail.com", now(), "P")');
		$this->assertFalse($status->success());
		$this->assertEquals($status->getMessages(), array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => NULL,
				'_message' => 'Sorry Marina, but your are not allowed here',
				'_field' => NULL,
			)),
		));

		$status = $manager->executeQuery('INSERT INTO Subscriptores VALUES (NULL, "dtmail.com", now(), "P")');
		$this->assertFalse($status->success());
		$this->assertEquals($status->getMessages(), array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'email',
				'_message' => "Value of field 'email' must have a valid e-mail format",
				'_field' => 'email',
			)),
		));

		$status = $manager->executeQuery('INSERT INTO Subscriptores VALUES (NULL, "le-marina@hotmail.com", now(), "P")');
		$this->assertTrue($status->success());

		$status = $manager->executeQuery('INSERT INTO Subscriptores VALUES (NULL, "sonny@hotmail.com", "2010-01-01 13:21:00", "P")');
		$this->assertTrue($status->success());

		$status = $manager->executeQuery('INSERT INTO Subscriptores (email, created_at, status) VALUES ("hideaway@hotmail.com", "2010-01-01 13:21:00", "P")');
		$this->assertTrue($status->success());

		$status = $manager->executeQuery('INSERT INTO Subscriptores (email, created_at, status) VALUES (:email:, :created_at:, :status:)', array(
			"email" => "yeahyeah@hotmail.com",
			"created_at" => "2010-02-01 13:21:00",
			"status" => "P"
		));
		$this->assertTrue($status->success());

		$this->assertTrue($status->getModel()->id > 0);

	}

	public function _testUpdateExecute($di)
	{

		$manager = $di->getShared('modelsManager');

		$di->getShared('db')->execute("UPDATE personas SET ciudad_id = NULL WHERE direccion = 'COL'");

		$status = $manager->executeQuery("UPDATE People SET direccion = 'COL' WHERE ciudad_id IS NULL LIMIT 25");
		$this->assertTrue($status->success());

		$status = $manager->executeQuery('UPDATE People SET direccion = :direccion: WHERE ciudad_id IS NULL LIMIT 25', array(
			"direccion" => "MXN"
		));
		$this->assertTrue($status->success());

		$status = $manager->executeQuery('UPDATE Subscriptores SET status = :status: WHERE email = :email:', array(
			"status" => "I",
			"email" => "le-marina@hotmail.com"
		));
		$this->assertTrue($status->success());

	}

	public function _testDeleteExecute($di)
	{

		$manager = $di->getShared('modelsManager');

		$status = $manager->executeQuery('DELETE FROM Subscriptores WHERE email = "marina@hotmail.com"');
		$this->assertTrue($status->success());

		$status = $manager->executeQuery('DELETE FROM Subscriptores WHERE status = :status: AND email <> :email:', array(
			'status' => "P",
			'email' => 'fuego@hotmail.com'
		));
		$this->assertTrue($status->success());

	}

}