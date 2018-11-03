<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file LICENSE.txt.                             |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use PHPUnit\Framework\TestCase;

class ModelsHydrationTest extends TestCase
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
		$this->_executeTestsNormalCastHydrate($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsRenamedCastHydrate($di);
		$this->_executeTestsNormalComplex($di);
		$this->_executeTestsNormalComplexCastHydrate($di);
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
		$this->_executeTestsNormalCastHydrate($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsRenamedCastHydrate($di);
		$this->_executeTestsNormalComplex($di);
		$this->_executeTestsNormalComplexCastHydrate($di);
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
		$this->_executeTestsNormalCastHydrate($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsRenamedCastHydrate($di);
		$this->_executeTestsNormalComplex($di);
		$this->_executeTestsNormalComplexCastHydrate($di);
	}

	protected function _executeTestsNormal($di)
	{

		$number = 0;

		$robots = Robots::find();

		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('Robots', $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('Robots', $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($robots as $robot) {
			$this->assertInternalType('array', $robot);
			$this->assertCount(7, $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('stdClass', $robot);
			$number++;
		}

		$this->assertEquals($number, 12);

		$number = 0;

		$people = People::find(array('limit' => 33));

		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('People', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('People', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($people as $person) {
			$this->assertInternalType('array', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('stdClass', $person);
			$number++;
		}

		$this->assertEquals($number, 33 * 4);

	}

	protected function _executeTestsRenamed($di)
	{

		$number = 0;

		$robots = Robotters::find();

		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('Robotters', $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('Robotters', $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($robots as $robot) {
			$this->assertInternalType('array', $robot);
			$this->assertCount(7, $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('stdClass', $robot);
			$number++;
		}

		$this->assertEquals($number, 12);

		$number = 0;

		$people = Personers::find(array('limit' => 33));

		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('Personers', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('Personers', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);

		foreach ($people as $person) {
			$this->assertInternalType('array', $person);
			$this->assertTrue(isset($person['navnes']));
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('stdClass', $person);
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
			$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
			$this->assertInternalType('numeric', $row->id);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($result as $row) {
			$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
			$this->assertInternalType('numeric', $row->id);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($result as $row) {
			$this->assertInternalType('array', $row);
			$this->assertInternalType('numeric', $row['id']);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($result as $row) {
			$this->assertInstanceOf('stdClass', $row);
			$this->assertInternalType('numeric', $row->id);
		}

		//Complex resultset including scalars and complete objects
		$result = $di->get('modelsManager')->executeQuery(
			'SELECT Robots.id, Robots.*, RobotsParts.* FROM Robots JOIN RobotsParts'
		);
		foreach ($result as $row) {
			$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
			$this->assertInternalType('numeric', $row->id);
			$this->assertInternalType('object', $row->robots);
			$this->assertInstanceOf('Robots', $row->robots);
			$this->assertInternalType('object', $row->robotsParts);
			$this->assertInstanceOf('RobotsParts', $row->robotsParts);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($result as $row) {
			$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
			$this->assertInternalType('numeric', $row->id);
			$this->assertInternalType('object', $row->robots);
			$this->assertInstanceOf('Robots', $row->robots);
			$this->assertInternalType('object', $row->robotsParts);
			$this->assertInstanceOf('RobotsParts', $row->robotsParts);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($result as $row) {
			$this->assertInternalType('array', $row);
			$this->assertInternalType('numeric', $row['id']);
			$this->assertInternalType('array', $row['robots']);
			$this->assertCount(7, $row['robots']);
			$this->assertInternalType('array', $row['robotsParts']);
			$this->assertCount(3, $row['robotsParts']);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($result as $row) {
			$this->assertInstanceOf('stdClass', $row);
			$this->assertInternalType('numeric', $row->id);
			$this->assertInternalType('object', $row->robots);
			$this->assertInstanceOf('stdClass', $row->robots);
			$this->assertInternalType('object', $row->robotsParts);
			$this->assertInstanceOf('stdClass', $row->robotsParts);
		}

	}

	protected function _executeTestsNormalCastHydrate($di)
	{
		Phalcon\Mvc\Model::setup(['castOnHydrate' => true]);

		$number = 0;

		$robots = Robots::find();

		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('Robots', $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('Robots', $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($robots as $robot) {
			$this->assertInternalType('array', $robot);
			$this->assertCount(7, $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('stdClass', $robot);
			$number++;
		}

		$this->assertEquals($number, 12);

		$number = 0;

		$people = People::find(array('limit' => 33));

		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('People', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('People', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($people as $person) {
			$this->assertInternalType('array', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('stdClass', $person);
			$number++;
		}

		$this->assertEquals($number, 33 * 4);

		Phalcon\Mvc\Model::setup(['castOnHydrate' => false]);
	}

	protected function _executeTestsRenamedCastHydrate($di)
	{
		Phalcon\Mvc\Model::setup(['castOnHydrate' => true]);

		$number = 0;

		$robots = Robotters::find();

		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('Robotters', $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('Robotters', $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($robots as $robot) {
			$this->assertInternalType('array', $robot);
			$this->assertCount(7, $robot);
			$number++;
		}

		$robots->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($robots as $robot) {
			$this->assertInternalType('object', $robot);
			$this->assertInstanceOf('stdClass', $robot);
			$number++;
		}

		$this->assertEquals($number, 12);

		$number = 0;

		$people = Personers::find(array('limit' => 33));

		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('Personers', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('Personers', $person);
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);

		foreach ($people as $person) {
			$this->assertInternalType('array', $person);
			$this->assertTrue(isset($person['navnes']));
			$number++;
		}

		$people->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($people as $person) {
			$this->assertInternalType('object', $person);
			$this->assertInstanceOf('stdClass', $person);
			$this->assertTrue(isset($person->navnes));
			$number++;
		}

		$this->assertEquals($number, 33 * 4);

		Phalcon\Mvc\Model::setup(['castOnHydrate' => false]);
	}

	protected function _executeTestsNormalComplexCastHydrate($di)
	{
		Phalcon\Mvc\Model::setup(['castOnHydrate' => true]);

		$result = $di->get('modelsManager')->executeQuery('SELECT id FROM Robots');

		//Scalar complex query
		foreach ($result as $row) {
			$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
			$this->assertInternalType('numeric', $row->id);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($result as $row) {
			$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
			$this->assertInternalType('numeric', $row->id);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($result as $row) {
			$this->assertInternalType('array', $row);
			$this->assertInternalType('numeric', $row['id']);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($result as $row) {
			$this->assertInstanceOf('stdClass', $row);
			$this->assertInternalType('numeric', $row->id);
		}

		//Complex resultset including scalars and complete objects
		$result = $di->get('modelsManager')->executeQuery(
			'SELECT Robots.id, Robots.*, RobotsParts.* FROM Robots JOIN RobotsParts'
		);
		foreach ($result as $row) {
			$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
			$this->assertInternalType('numeric', $row->id);
			$this->assertInternalType('object', $row->robots);
			$this->assertInstanceOf('Robots', $row->robots);
			$this->assertInternalType('object', $row->robotsParts);
			$this->assertInstanceOf('RobotsParts', $row->robotsParts);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_RECORDS);
		foreach ($result as $row) {
			$this->assertInstanceOf('Phalcon\Mvc\Model\Row', $row);
			$this->assertInternalType('numeric', $row->id);
			$this->assertInternalType('object', $row->robots);
			$this->assertInstanceOf('Robots', $row->robots);
			$this->assertInternalType('object', $row->robotsParts);
			$this->assertInstanceOf('RobotsParts', $row->robotsParts);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS);
		foreach ($result as $row) {
			$this->assertInternalType('array', $row);
			$this->assertInternalType('numeric', $row['id']);
			$this->assertInternalType('array', $row['robots']);
			$this->assertCount(7, $row['robots']);
			$this->assertInternalType('array', $row['robotsParts']);
			$this->assertCount(3, $row['robotsParts']);
		}

		$result->setHydrateMode(Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS);
		foreach ($result as $row) {
			$this->assertInstanceOf('stdClass', $row);
			$this->assertInternalType('numeric', $row->id);
			$this->assertInternalType('object', $row->robots);
			$this->assertInstanceOf('stdClass', $row->robots);
			$this->assertInternalType('object', $row->robotsParts);
			$this->assertInstanceOf('stdClass', $row->robotsParts);
		}

		Phalcon\Mvc\Model::setup(['castOnHydrate' => false]);
	}

}
