<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

use Phalcon\Db\Column as DbColumn;
use Phalcon\Db as Db;

class DbBindTest extends PHPUnit_Framework_TestCase
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
		$this->_executeBindArrayTests($connection);
	}

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
		$this->_executeBindArrayTests($connection);
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
		$this->_executeBindArrayTests($connection);
	}

	/*protected function _executeRawBindTests($connection)
	{

		$conditions = $connection->bindParams("a=?0", array(0 => 100));
		$this->assertEquals($conditions, "a=100");

		$conditions = $connection->bindParams("a=?0", array(0 => 100, 1 => 50));
		$this->assertEquals($conditions, "a=100");

		$conditions = $connection->bindParams("a=?0", array(1 => 50));
		$this->assertEquals($conditions, "a=?0");

		$conditions = $connection->bindParams("a=?1 AND b = ?0", array(0 => 25, 1 => 50));
		$this->assertEquals($conditions, "a=50 AND b = 25");

		$conditions = $connection->bindParams("a=?1 AND b = ?0", array(0 => '25', 1 => '50'));
		$this->assertEquals($conditions, "a=50 AND b = 25");

		$conditions = $connection->bindParams("a=?1 AND b = ?0", array(0 => '25.10', 1 => 25.10));
		$this->assertEquals($conditions, "a=25.1 AND b = 25.10");

		$conditions = $connection->bindParams("a=?1 AND b = ?0 AND c<>?2", array(0 => 25, 1 => 50, 2 => 15));
		$this->assertEquals($conditions, "a=50 AND b = 25 AND c<>15");

		$conditions = $connection->bindParams("a=:a:", array('a' => 'no-suprises'));
		$this->assertEquals($conditions, "a='no-suprises'");

		$conditions = $connection->bindParams("column1 = :column1: AND column2=:column2:", array('column1' => 'hello', 'column2' => 'lol'));
		$this->assertEquals($conditions, "column1 = 'hello' AND column2='lol'");
	}

	protected function _executeRawBindTestsMysql($connection)
	{

		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:)", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'"));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '\'hahaha\'')");

		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'", 2 => 'le-nice'));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '\'hahaha\'') AND column4 > 'le-nice'");
	}

	protected function _executeRawBindTestsPostgresql($connection)
	{
		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:)", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'"));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''')");

		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'", 2 => 'le-nice'));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''') AND column4 > 'le-nice'");
	}

	protected function _executeRawBindTestsSqlite($connection)
	{
		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:)", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'"));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''')");

		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'", 2 => 'le-nice'));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''') AND column4 > 'le-nice'");
	}*/

	protected function _executeConvertBindTests($connection)
	{

		$params = $connection->convertBoundParams("a=?0", array(0 => 100));
		$this->assertEquals($params, array('sql' => 'a=?', 'params' => array(0 => 100)));

		$params = $connection->convertBoundParams("a=?0", array(0 => 100, 1 => 50));
		$this->assertEquals($params, array('sql' => 'a=?', 'params' => array(0 => 100)));

		$params = $connection->convertBoundParams("a=?1 AND b = ?0", array(1 => 50, 0 => 25));
		$this->assertEquals($params, array('sql' => "a=? AND b = ?", 'params' => array(0 => 50, 1 => 25)));

		$params = $connection->convertBoundParams("a=?1 AND b = ?0", array(1 => 25.10, 0 => '25.10'));
		$this->assertEquals($params, array('sql' => "a=? AND b = ?", 'params' => array(0 => '25.10', 1 => 25.10)));

		$params = $connection->convertBoundParams("a=?1 AND b = ?0 AND c > :c: AND d = ?3", array('c' => 1000, 1 => 'some-name', 0 => 15, 3 => 400));
		$this->assertEquals($params, array('sql' => "a=? AND b = ? AND c > ? AND d = ?", 'params' => array(0 => 'some-name', 1 => 15, 2 => 1000, 3 => 400)));
	}

	protected function _executeBindByTypeTests($connection)
	{

		$success = $connection->execute(
			'INSERT INTO prueba(id, nombre, estado) VALUES ('.$connection->getDefaultIdValue().', ?, ?)',
			array("LOL 1", "A"),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->execute(
			'UPDATE prueba SET nombre = ?, estado = ?',
			array("LOL 11", "R"),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->execute(
			'DELETE FROM prueba WHERE estado = ?',
			array("R"),
			array(DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->insert(
			'prueba',
			array($connection->getDefaultIdValue(), "LOL 1", "A"),
			null,
			array(DbColumn::BIND_SKIP, DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->insert(
			'prueba',
			array("LOL 2", "E"),
			array('nombre', 'estado'),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->insert(
			'prueba',
			array("LOL 3", "I"),
			array('nombre', 'estado'),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->insert(
			'prueba',
			array(new Phalcon\Db\RawValue('current_date'), "A"),
			array('nombre', 'estado'),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->update(
			'prueba',
			array("nombre", "estado"),
			array("LOL 1000", "X"),
			"estado='E'",
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->update(
			'prueba',
			array("nombre"), array("LOL 3000"),
			"estado='X'",
			array(DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->update(
			'prueba',
			array("nombre"), array(new Phalcon\Db\RawValue('current_date')),
			"estado='X'",
			array(DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

	}

	protected function _executeBindArrayTests($connection)
	{
		//with int bindings
		$robots = $connection->fetchAll(
			'select * from robots where id in (?) order by id',
			Db::FETCH_ASSOC,
			array(array(1, 2, 3)),
			array(DbColumn::BIND_PARAM_INT_ARRAY)
		);
		$this->assertEquals(3, count($robots));
		$this->assertEquals('Robotina', $robots[0]['name']);
		$this->assertEquals('Astro Boy', $robots[1]['name']);
		$this->assertEquals('Terminator', $robots[2]['name']);

		//with string bindings
		$robots = $connection->fetchAll(
			'select * from robots where name in (?) order by id',
			Db::FETCH_ASSOC,
			array(array('Robotina', 'Astro Boy', 'Terminator')),
			array(DbColumn::BIND_PARAM_STR_ARRAY)
		);
		$this->assertEquals(3, count($robots));
		$this->assertEquals(1, $robots[0]['id']);
		$this->assertEquals(2, $robots[1]['id']);
		$this->assertEquals(3, $robots[2]['id']);

		//int params without param types
		$robots = $connection->fetchAll(
			'select * from robots where id in (?) order by id',
			Db::FETCH_ASSOC,
			array(array(1, 2, 3))
		);
		$this->assertEquals(3, count($robots));
		$this->assertEquals('Robotina', $robots[0]['name']);
		$this->assertEquals('Astro Boy', $robots[1]['name']);
		$this->assertEquals('Terminator', $robots[2]['name']);

		//string params without param types
		$robots = $connection->fetchAll(
			'select * from robots where name in (?) order by id',
			Db::FETCH_ASSOC,
			array(array('Robotina', 'Astro Boy', 'Terminator'))
		);
		$this->assertEquals(3, count($robots));
		$this->assertEquals(1, $robots[0]['id']);
		$this->assertEquals(2, $robots[1]['id']);
		$this->assertEquals(3, $robots[2]['id']);

		//fetch one
		$robot = $connection->fetchOne(
			'select * from robots where id in (?) order by id limit 1',
			Db::FETCH_ASSOC,
			array(array(1, 2, 3)),
			array(DbColumn::BIND_PARAM_INT_ARRAY)
		);
		$this->assertEquals('Robotina', $robot['name']);

		$robot = $connection->fetchOne(
			'select * from robots where id in (?) order by id limit 1',
			Db::FETCH_ASSOC,
			array(array(1, 2, 3))
		);
		$this->assertEquals('Robotina', $robot['name']);

		//named param
		$robots = $connection->fetchAll(
			'select * from robots where id in (:ids) order by id',
			Db::FETCH_ASSOC,
			array('ids' => array(1, 2, 3))
		);
		$this->assertEquals(3, count($robots));
		$this->assertEquals('Robotina', $robots[0]['name']);
		$this->assertEquals('Astro Boy', $robots[1]['name']);
		$this->assertEquals('Terminator', $robots[2]['name']);

		//todo updateAsDict

		//deleting
		$connection->delete('robots', "name like 'name%'");
		$connection->insertAsDict('robots',array('id' => $connection->getDefaultIdValue(), 'year' => 1,'type' => 'mechanical','name' => 'name1'));
		$connection->insertAsDict('robots',array('id' => $connection->getDefaultIdValue(), 'year' => 2,'type' => 'mechanical','name' => 'name2'));
		$connection->insertAsDict('robots',array('id' => $connection->getDefaultIdValue(), 'year' => 3,'type' => 'mechanical','name' => 'name3'));
		$connection->insertAsDict('robots',array('id' => $connection->getDefaultIdValue(), 'year' => 4,'type' => 'mechanical','name' => 'name4'));
		$robots = $connection->fetchAll('select * from robots');
		$this->assertEquals(7, count($robots));

		$connection->delete(
			'robots',
			'name in (?)',
			array(array('name1','name2')),
			array(DbColumn::BIND_PARAM_STR_ARRAY)
		);
		$robots = $connection->fetchAll('select * from robots');
		$this->assertEquals(5, count($robots));

		$connection->delete('robots', 'name in (?)', array(array('name3','name4')));
		$robots = $connection->fetchAll('select * from robots');
		$this->assertEquals(3, count($robots));
	}

}
