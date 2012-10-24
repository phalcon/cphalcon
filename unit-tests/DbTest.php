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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

class DbTest extends PHPUnit_Framework_TestCase
{

	public function testDbMysql()
	{

		require 'unit-tests/app/config/config.inc.php';

		$connection = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);

		$this->_executeTests($connection);

	}

	public function testDbPostgresql()
	{
		require 'unit-tests/app/config/config.inc.php';

		$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);

		$this->_executeTests($connection);
	}

	public function testDbPostgresqlSchemas()
	{
		require 'unit-tests/app/config/config.inc.php';

		$configPostgresqlDefault = array_merge(array(), $configPostgresql);
		unset($configPostgresqlDefault['schema']);

		$configPostgresqlNonExists = array_merge(array(), $configPostgresql);
		$configPostgresqlNonExists['schema'] = 'nonexists';

		try {
			$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
			$this->assertTrue(is_object($connection));
		} catch(Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresqlDefault);
			$this->assertTrue(is_object($connection));
		} catch(Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresqlNonExists);
			$this->assertFalse(is_object($connection));
		} catch(Exception $e) {
			$this->assertTrue(true);
		}

	}

	public function testDbSqlite()
	{

		require 'unit-tests/app/config/config.inc.php';

		$connection = new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);

		$this->_executeTests($connection);
	}

	protected function _executeTests($connection)
	{

		$result = $connection->query("SELECT * FROM personas LIMIT 3");
		$this->assertTrue(is_object($result));
		$this->assertEquals(get_class($result), 'Phalcon\Db\Result\Pdo');

		for ($i=0; $i<3; $i++) {
			$row = $result->fetchArray();
			$this->assertEquals(count($row), 22);
		}

		$row = $result->fetchArray();
		$this->assertEquals($row, false);
		$this->assertEquals($result->numRows(), 3);

		$number = 0;
		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$this->assertTrue(is_object($result));

		while ($row = $result->fetchArray()) {
			$number++;
		}
		$this->assertEquals($number, 5);

		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_NUM);
		$row = $result->fetchArray();
		$this->assertEquals(count($row), 11);

		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_ASSOC);
		$row = $result->fetchArray();
		$this->assertEquals(count($row), 11);

		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_BOTH);
		$result->dataSeek(4);
		$row = $result->fetchArray();
		$row = $result->fetchArray();
		$this->assertEquals($row, false);

		$result = $connection->execute("DELETE FROM prueba");
		$this->assertTrue($result);

		$success = $connection->execute('INSERT INTO prueba(id, nombre, estado) VALUES ('.$connection->getDefaultIdValue().', ?, ?)', array("LOL 1", "A"));
		$this->assertTrue($success);

		$success = $connection->execute('UPDATE prueba SET nombre = ?, estado = ?', array("LOL 11", "R"));
		$this->assertTrue($success);

		$success = $connection->execute('DELETE FROM prueba WHERE estado = ?', array("R"));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array($connection->getDefaultIdValue(), "LOL 1", "A"));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array("LOL 2", "E"), array('nombre', 'estado'));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array("LOL 3", "I"), array('nombre', 'estado'));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array(new Phalcon\Db\RawValue('current_date'), "A"), array('nombre', 'estado'));
		$this->assertTrue($success);

		for ($i=0; $i<50; $i++) {
			$success = $connection->insert('prueba', array("LOL ".$i, "F"), array('nombre', 'estado'));
			$this->assertTrue($success);
		}

		$success = $connection->update('prueba', array("nombre", "estado"), array("LOL 1000", "X"), "estado='E'");
		$this->assertTrue($success);

		$success = $connection->update('prueba', array("nombre"), array("LOL 3000"), "estado='X'");
		$this->assertTrue($success);

		$success = $connection->update('prueba', array("nombre"), array(new Phalcon\Db\RawValue('current_date')), "estado='X'");
		$this->assertTrue($success);

		$connection->delete("prueba", "estado='X'");
		$this->assertTrue($success);

		$connection->delete("prueba");
		$this->assertTrue($success);
		$this->assertEquals($connection->affectedRows(), 53);

		$row = $connection->fetchOne("SELECT * FROM personas");
		$this->assertEquals(count($row), 22);

		$row = $connection->fetchOne("SELECT * FROM personas", Phalcon\Db::FETCH_NUM);
		$this->assertEquals(count($row), 11);

		$rows = $connection->fetchAll("SELECT * FROM personas LIMIT 10");
		$this->assertEquals(count($rows), 10);

		$rows = $connection->fetchAll("SELECT * FROM personas LIMIT 10", Phalcon\Db::FETCH_NUM);
		$this->assertEquals(count($rows), 10);
		$this->assertEquals(count($rows[0]), 11);

		//Auto-Increment/Serial Columns
		$sql = 'INSERT INTO subscriptores(id, email, created_at, status) VALUES ('.$connection->getDefaultIdValue().', ?, ?, ?)';
		$success = $connection->execute($sql, array('shirley@garbage.com', "2011-01-01 12:59:13", "P"));
		$this->assertTrue($success);

		//Check for auto-increment column
		$this->assertTrue($connection->lastInsertId('subscriptores_id_seq') > 0);

	}

}
