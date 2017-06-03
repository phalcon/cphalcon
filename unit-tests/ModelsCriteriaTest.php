<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

class ModelsCriteriaTest extends PHPUnit_Framework_TestCase
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
		if (file_exists('unit-tests/models/' . $className . '.php')) {
			require 'unit-tests/models/' . $className . '.php';
		}
	}

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		return $di;
	}

	public function testModelsMysql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		$this->_executeTestsRenamed($di);
	}

	public function testModelsPostgresql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		}, true);

		$this->_executeTestsRenamed($di);
	}

	public function testModelsSQLite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\SQLite($configSqlite);
		}, true);

		$this->_executeTestsRenamed($di);
	}

	protected function _executeTestsRenamed($di)
	{

		$personers = Personers::query()
			->where("status='I'")
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$personers = Personers::query()
			->conditions("status='I'")
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$personers = Personers::query()
			->where("status='A'")
			->orderBy("navnes")
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$somePersoner = $personers->getFirst();
		$this->assertTrue(is_object($somePersoner));
		$this->assertEquals(get_class($somePersoner), 'Personers');

		$personers  = Personers::query()
			->where("status='A'")
			->orderBy("navnes")
			->limit(100)
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$somePersoner = $personers->getFirst();
		$this->assertTrue(is_object($somePersoner));
		$this->assertEquals(get_class($somePersoner), 'Personers');

		$personers = Personers::query()
			->where("status=?1")
			->bind(array(1 => "A"))
			->orderBy("navnes")
			->limit(100)
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$somePersoner = $personers->getFirst();
		$this->assertTrue(is_object($somePersoner));
		$this->assertEquals(get_class($somePersoner), 'Personers');

		$personers = Personers::query()
			->where("status=:status:")
			->bind(array("status" => "A"))
			->orderBy("navnes")
			->limit(100)->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$somePersoner = $personers->getFirst();
		$this->assertTrue(is_object($somePersoner));
		$this->assertEquals(get_class($somePersoner), 'Personers');
	}
}
