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

class DbLoggerTest extends PHPUnit_Framework_TestCase {

	public function testDbLoggerMysql(){

		require 'unit-tests/config.db.php';

		$connection = Phalcon\Db::factory('mysql', $configMysql);
		$this->assertTrue(is_object($connection));

		$this->_executeTests($connection);
	}

	/*public function testDbLoggerPostgresql(){

		require 'unit-tests/config.db.php';

		$connection = Phalcon\Db::factory('Postgresql', $configPostgresql);
		$this->assertTrue(is_object($connection));

		$this->_executeTests($connection);
	}*/

	protected function _executeTests($connection){

		@unlink('unit-tests/logs/test-db.log');

		$logger = new Phalcon\Logger('File', 'unit-tests/logs/test-db.log');
		$connection->setLogger($logger);

		$this->assertTrue(is_object($connection->getLogger()));
		$this->assertEquals(get_class($connection->getLogger()), 'Phalcon\Logger');

		$connection->query("SELECT * FROM personas LIMIT 3");
		$connection->query("SELECT * FROM personas LIMIT 10");
		$connection->query("SELECT * FROM personas LIMIT 1");

		$this->assertTrue($connection->close());

		$logger->close();

		$lines = file('unit-tests/logs/test-db.log');
		$this->assertEquals(count($lines), 3);

		$this->assertTrue(strpos($lines[0], '[DEBUG]')!==false);
		$this->assertTrue(strpos($lines[0], 'LIMIT 3')!==false);
		$this->assertTrue(strpos($lines[1], '[DEBUG]')!==false);
		$this->assertTrue(strpos($lines[1], 'LIMIT 10')!==false);
		$this->assertTrue(strpos($lines[2], '[DEBUG]')!==false);
		$this->assertTrue(strpos($lines[2], 'LIMIT 1')!==false);
	}

}
