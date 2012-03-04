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

class DbTest extends PHPUnit_Framework_TestCase {


	public function testDb(){

		$config = new stdClass();
		$config->host = '127.0.0.1';
		$config->username = 'root';
		$config->password = '';
		$config->name = 'phalcon_test';

		$connection = Phalcon_Db::factory('Mysql', $config, true);
		$this->assertTrue(is_object($connection));

		$this->assertEquals($connection->getDatabaseName(), $config->name);
		$this->assertEquals($connection->getHostname(), $config->host);
		$this->assertEquals($connection->getUsername(), $config->username);
		$this->assertEquals($connection->getDefaultSchema(), $config->name);

		$result = $connection->query("SELECT * FROM personas LIMIT 3");
		$this->assertTrue(is_resource($result));
	
		for($i=0;$i<3;$i++){
			$row = $connection->fetchArray($result);
			$this->assertEquals(count($row), 22);			
		}

		$row = $connection->fetchArray($result);
		$this->assertEquals($row, false);
		$this->assertEquals($connection->numRows($result), 3);
		
		$number = 0;
		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$this->assertTrue(is_resource($result));

		while($row = $connection->fetchArray($result)){
			$number++;
		}
		$this->assertEquals($number, 5);

		$connection->setFetchMode(Phalcon_Db::DB_NUM);
		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$row = $connection->fetchArray($result);
		$this->assertEquals(count($row), 11);

		$connection->setFetchMode(Phalcon_Db::DB_ASSOC);
		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$row = $connection->fetchArray($result);
		$this->assertEquals(count($row), 11);

		$connection->setFetchMode(Phalcon_Db::DB_BOTH);
		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$connection->dataSeek(4, $result);
		$row = $connection->fetchArray($result);
		$row = $connection->fetchArray($result);
		$this->assertEquals($row, false);

		$result = $connection->query("DELETE FROM prueba");
		$this->assertTrue($result);

		$success = $connection->insert('prueba', array('null', "'LOL 1'", "'A'"));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array("'LOL 2'", "'E'"), array('nombre', 'estado'));
		$this->assertTrue($success);	

		$success = $connection->insert('prueba', array("LOL 3", "I"), array('nombre', 'estado'), true);
		$this->assertTrue($success);	

		$success = $connection->insert('prueba', array(new Phalcon_Db_RawValue('current_date'), "'A'"), array('nombre', 'estado'));
		$this->assertTrue($success);

		for($i=0;$i<50;$i++){
			$success = $connection->insert('prueba', array("LOL ".$i, "F"), array('nombre', 'estado'), true);
			$this->assertTrue($success);
		}
			
		$success = $connection->update('prueba', array("nombre", "estado"), array("'LOL 1000'", "'X'"), "estado='E'");
		$this->assertTrue($success);	

		$success = $connection->update('prueba', array("nombre"), array("'LOL 2500'"), "estado='X'");
		$this->assertTrue($success);

		$success = $connection->update('prueba', array("nombre"), array("LOL 3000"), "estado='X'", true);
		$this->assertTrue($success);

		$success = $connection->update('prueba', array("nombre"), array(new Phalcon_Db_RawValue('current_date')), "estado='X'", false);
		$this->assertTrue($success);

		$connection->delete("prueba", "estado='X'");
		$this->assertTrue($success);

		$connection->delete("prueba");
		$this->assertTrue($success);

	}

}
