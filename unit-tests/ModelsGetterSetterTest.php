<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Nochum Sossonko                                               |
  +------------------------------------------------------------------------+
*/

class ModelsGetterSetterTest extends PHPUnit_Framework_TestCase
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
		$className = str_replace('\\', DIRECTORY_SEPARATOR, $className);
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

		$di = $this->_getDI();

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$connection = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);

		$di->set('db', $connection, true);

		$this->_executeSetGet();
	}

	/*public function testModelsPostgresql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		}, true);

		$this->_executeSetGet();
	}

	public function testModelsSqlite()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
		}, true);

		$this->_executeSetGet();
	}*/

	public function _executeSetGet()
	{
		$robot = Boutique\Robots::findFirst();
		$testText = 'executeSetGet Test';
		$robot->assign(array('text' => $testText));
		$this->assertEquals($robot->text, $testText . $robot::setterEpilogue);
		$this->assertEquals($robot->text, $robot->getText());

		$testText = 'executeSetGet Test 2';
		$robot->text = $testText;
		$this->assertEquals($robot->text, $testText . $robot::setterEpilogue);
		$this->assertEquals($robot->text, $robot->getText());

		$testText = 'executeSetGet Test 3';
		$robot = new Boutique\Robots();
		try {
			$exception_thrown = false;
			$robot->serial = '1234';
		} catch (Exception $e) {
			$exception_thrown = true;
			$this->assertEquals($e->getMessage(), "Property 'serial' does not have a setter.");
		}
		$this->assertEquals($exception_thrown, true);
	}
}
