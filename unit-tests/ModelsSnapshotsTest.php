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

class ModelsSnapshotsTest extends PHPUnit_Framework_TestCase
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
		$className = str_replace('\\', '/', $className);
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
			$this->markTestSkipped('Test skipped');
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

	protected function _executeTestsNormal($di)
	{

		$snapshots = array(
			1 => array(
				'id' => '1',
				'name' => 'Robotina',
				'type' => 'mechanical',
				'year' => '1972',
				'datetime' => '1972-01-01 00:00:00',
				'text' => 'text'
			),
			2 => array(
				'id' => '2',
				'name' => 'Astro Boy',
				'type' => 'mechanical',
				'year' => '1952',
				'datetime' => '1952-01-01 00:00:00',
				'text' => 'text'
			),
			3 => array(
				'id' => '3',
				'name' => 'Terminator',
				'type' => 'cyborg',
				'year' => '2029',
				'datetime' => '2029-01-01 00:00:00',
				'text' => 'text'
			)
		);

		foreach (Snapshot\Robots::find(array('order' => 'id')) as $robot) {
			$this->assertTrue($robot->hasSnapshotData());
			$this->assertEquals($snapshots[$robot->id], $robot->getSnapshotData());
		}

		foreach (Snapshot\Robots::find(array('order' => 'id')) as $robot) {
			$robot->name = 'Some';
			$robot->year = 1999;
			$this->assertTrue($robot->hasChanged('name'));
			$this->assertTrue($robot->hasChanged('year'));
			$this->assertFalse($robot->hasChanged('type'));
			$this->assertTrue($robot->hasChanged());
		}

		foreach (Snapshot\Robots::find(array('order' => 'id')) as $robot) {
			$robot->year = $robot->year;
			$this->assertFalse($robot->hasChanged('year'));
			$this->assertFalse($robot->hasChanged());
		}

		foreach (Snapshot\Robots::find(array('order' => 'id')) as $robot) {
			$robot->name = 'Little';
			$robot->year = 2005;
			$this->assertEquals($robot->getChangedFields(), array('name', 'year'));
		}
	}

	protected function _executeTestsRenamed($di)
	{
		$snapshots = array(
			1 => array(
				'code' => '1',
				'theName' => 'Robotina',
				'theType' => 'mechanical',
				'theYear' => '1972',
				'theDatetime' => '1972-01-01 00:00:00',
				'theText' => 'text',
			),
			2 => array(
				'code' => '2',
				'theName' => 'Astro Boy',
				'theType' => 'mechanical',
				'theYear' => '1952',
				'theDatetime' => '1952-01-01 00:00:00',
				'theText' => 'text',
			),
			3 => array(
				'code' => '3',
				'theName' => 'Terminator',
				'theType' => 'cyborg',
				'theYear' => '2029',
				'theDatetime' => '2029-01-01 00:00:00',
				'theText' => 'text',
			)
		);

		foreach (Snapshot\Robotters::find(array('order' => 'code')) as $robot) {
			$this->assertTrue($robot->hasSnapshotData());
			$this->assertEquals($snapshots[$robot->code], $robot->getSnapshotData());
		}

		foreach (Snapshot\Robotters::find(array('order' => 'code')) as $robot) {
			$robot->theName = 'Some';
			$robot->theYear = 1999;
			$this->assertTrue($robot->hasChanged('theName'));
			$this->assertTrue($robot->hasChanged('theYear'));
			$this->assertFalse($robot->hasChanged('theType'));
			$this->assertTrue($robot->hasChanged());
		}

		foreach (Snapshot\Robotters::find(array('order' => 'code')) as $robot) {
			$robot->theYear = $robot->theYear;
			$this->assertFalse($robot->hasChanged('theYear'));
			$this->assertFalse($robot->hasChanged());
		}

		foreach (Snapshot\Robotters::find(array('order' => 'code')) as $robot) {
			$robot->theName = 'Little';
			$robot->theYear = 2005;
			$this->assertEquals($robot->getChangedFields(), array('theName', 'theYear'));
		}
	}

	protected function _executeTestsNormalComplex($di)
	{

		$robots = $di['modelsManager']->executeQuery('SELECT * FROM Snapshot\Robots');
		foreach ($robots as $robot) {
			$robot->name = 'Some';
			$robot->year = 1999;
			$this->assertTrue($robot->hasChanged('name'));
			$this->assertTrue($robot->hasChanged('year'));
			$this->assertFalse($robot->hasChanged('type'));
			$this->assertTrue($robot->hasChanged());
			$this->assertEquals($robot->getChangedFields(), array('name', 'year'));
		}

		$robots = $di['modelsManager']->executeQuery('SELECT robot.*, parts.* FROM Snapshot\Robots robot JOIN Snapshot\RobotsParts parts');
		foreach ($robots as $row) {

			$row->robot->name = 'Some';
			$row->robot->year = 1999;

			$this->assertTrue($row->robot->hasChanged('name'));
			$this->assertTrue($row->robot->hasChanged('year'));
			$this->assertFalse($row->robot->hasChanged('type'));
			$this->assertTrue($row->robot->hasChanged());
			$this->assertEquals($row->robot->getChangedFields(), array('name', 'year'));

			$this->assertFalse($row->parts->hasSnapshotData());
		}
	}

}
