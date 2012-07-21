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

use Phalcon\Db\Pool as DbPool;

class DbPoolTest extends PHPUnit_Framework_TestCase {

	public function testPoolMysql(){

		DbPool::reset();

		require 'unit-tests/config.db.php';

		DbPool::setDefaultDescriptor($configMysql);
		$this->assertTrue(DbPool::hasDefaultDescriptor());

		$this->_executeTests();
	}

	public function testPoolPostgresql(){

		DbPool::reset();

		require 'unit-tests/config.db.php';

		DbPool::setDefaultDescriptor($configPostgresql);
		$this->assertTrue(DbPool::hasDefaultDescriptor());

		$this->_executeTests();
	}

	protected function _executeTests(){

		$connection = DbPool::getConnection();
		$this->assertTrue(is_object($connection));

		$connection2 = DbPool::getConnection(true);
		$this->assertNotEquals($connection->getConnectionId(true), $connection2->getConnectionId(true));

	}

}



