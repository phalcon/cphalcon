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

class ModelsHydrationTest extends PHPUnit_Framework_TestCase
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
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
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

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
	}

	public function testModelsPostgresql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		$this->_executeTestsNormal($di);
		//$this->_executeTestsRenamed($di);
	}

	public function testModelsSQLite()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\SQLite($configSqlite);
		});

		$this->_executeTestsNormal($di);
		//$this->_executeTestsRenamed($di);
	}

	protected function _executeTestsNormal($di)
	{

		$number = 0;

		$robots = Robots::find();

		foreach ($robots as $robot) {
			$this->assertTrue(is_object($robot));
			$this->assertEquals(get_class($robot), 'Robots');
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($robots as $robot) {
			$this->assertTrue(is_object($robot));
			$this->assertEquals(get_class($robot), 'Robots');
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($robots as $robot) {
			$this->assertTrue(is_array($robot));
			$this->assertEquals(count($robot), 4);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($robots as $robot) {
			$this->assertTrue(is_object($robot));
			$this->assertEquals(get_class($robot), 'stdClass');
			$number++;
		}

		$this->assertEquals($number, 12);

		$number = 0;

		$people = People::find(array('limit' => 33));

		foreach ($people as $person) {
			$this->assertTrue(is_object($person));
			$this->assertEquals(get_class($person), 'People');
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($people as $person) {
			$this->assertTrue(is_object($person));
			$this->assertEquals(get_class($person), 'People');
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($people as $person) {
			$this->assertTrue(is_array($person));
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($people as $person) {
			$this->assertTrue(is_object($person));
			$this->assertEquals(get_class($person), 'stdClass');
			$number++;
		}

		$this->assertEquals($number, 33 * 4);

	}

	protected function _executeTestsRenamed($di)
	{

		$number = 0;

		$robots = Robotters::find();

		foreach ($robots as $robot) {
			$this->assertTrue(is_object($robot));
			$this->assertEquals(get_class($robot), 'Robotters');
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($robots as $robot) {
			$this->assertTrue(is_object($robot));
			$this->assertEquals(get_class($robot), 'Robotters');
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($robots as $robot) {
			$this->assertTrue(is_array($robot));
			$this->assertEquals(count($robot), 4);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($robots as $robot) {
			$this->assertTrue(is_object($robot));
			$this->assertEquals(get_class($robot), 'stdClass');
			$number++;
		}

		$this->assertEquals($number, 12);

		$number = 0;

		$people = Personers::find(array('limit' => 33));

		foreach ($people as $person) {
			$this->assertTrue(is_object($person));
			$this->assertEquals(get_class($person), 'Personers');
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($people as $person) {
			$this->assertTrue(is_object($person));
			$this->assertEquals(get_class($person), 'Personers');
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);

		foreach ($people as $person) {
			$this->assertTrue(is_array($person));
			$this->assertTrue(isset($person['navnes']));
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($people as $person) {
			$this->assertTrue(is_object($person));
			$this->assertEquals(get_class($person), 'stdClass');
			$this->assertTrue(isset($person->navnes));
			$number++;
		}

		$this->assertEquals($number, 33 * 4);
	}


}
