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
		}, true);

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		}, true);

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

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsNormalComplex($di);
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

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsNormalComplex($di);
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

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsNormalComplex($di);
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
			$this->assertEquals(count($robot), 6);
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
			$this->assertEquals(count($robot), 6);
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

	protected function _executeTestsNormalComplex($di)
	{
		$result = $di->get('modelsManager')->executeQuery('SELECT id FROM Robots');

		//Scalar complex query
		foreach ($result as $row) {
			$this->assertEquals(get_class($row), 'Phalcon\Mvc\Model\Row');
			$this->assertTrue(is_numeric($row->id));
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($result as $row) {
			$this->assertEquals(get_class($row), 'Phalcon\Mvc\Model\Row');
			$this->assertTrue(is_numeric($row->id));
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($result as $row) {
			$this->assertTrue(is_array($row));
			$this->assertTrue(is_numeric($row['id']));
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($result as $row) {
			$this->assertEquals(get_class($row), 'stdClass');
			$this->assertTrue(is_numeric($row->id));
		}

		//Complex resultset including scalars and complete objects
		$result = $di->get('modelsManager')->executeQuery('SELECT Robots.id, Robots.*, RobotsParts.* FROM Robots JOIN RobotsParts');
		foreach ($result as $row) {
			$this->assertEquals(get_class($row), 'Phalcon\Mvc\Model\Row');
			$this->assertTrue(is_numeric($row->id));
			$this->assertEquals(gettype($row->robots), 'object');
			$this->assertEquals(get_class($row->robots), 'Robots');
			$this->assertEquals(gettype($row->robotsParts), 'object');
			$this->assertEquals(get_class($row->robotsParts), 'RobotsParts');
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($result as $row) {
			$this->assertEquals(get_class($row), 'Phalcon\Mvc\Model\Row');
			$this->assertTrue(is_numeric($row->id));
			$this->assertEquals(gettype($row->robots), 'object');
			$this->assertEquals(get_class($row->robots), 'Robots');
			$this->assertEquals(gettype($row->robotsParts), 'object');
			$this->assertEquals(get_class($row->robotsParts), 'RobotsParts');
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($result as $row) {
			$this->assertTrue(is_array($row));
			$this->assertTrue(is_numeric($row['id']));
			$this->assertEquals(gettype($row['robots']), 'array');
			$this->assertEquals(count($row['robots']), 6);
			$this->assertEquals(gettype($row['robotsParts']), 'array');
			$this->assertEquals(count($row['robotsParts']), 3);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($result as $row) {
			$this->assertEquals(get_class($row), 'stdClass');
			$this->assertTrue(is_numeric($row->id));
			$this->assertEquals(gettype($row->robots), 'object');
			$this->assertEquals(get_class($row->robots), 'stdClass');
			$this->assertEquals(gettype($row->robotsParts), 'object');
			$this->assertEquals(get_class($row->robotsParts), 'stdClass');
		}

	}

}
