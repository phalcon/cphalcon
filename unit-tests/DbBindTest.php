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

use Phalcon\Db as Db;

class DbBindTest extends PHPUnit_Framework_TestCase
{

	public function testDbBindMysql()
	{

		require 'unit-tests/config.db.php';

		$connection = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);

		$this->_executeTests($connection);
		$this->_executeTestsMysql($connection);
	}

	public function testDbBindPostgresql()
	{

		require 'unit-tests/config.db.php';

		$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);

		$this->_executeTests($connection);
		$this->_executeTestsPostgresql($connection);
	}

	protected function _executeTests($connection)
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

	protected function _executeTestsMysql($connection)
	{

		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:)", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'"));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '\'hahaha\'')");

		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'", 2 => 'le-nice'));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '\'hahaha\'') AND column4 > 'le-nice'");
	}

	protected function _executeTestsPostgresql($connection)
	{
		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:)", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'"));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''')");

		$conditions = $connection->bindParams("column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2", array('val1' => 'hello', 'val2' => 100, 'val3' => "'hahaha'", 2 => 'le-nice'));
		$this->assertEquals($conditions, "column3 IN ('hello', 100, '''hahaha''') AND column4 > 'le-nice'");
	}

}
