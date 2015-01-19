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

class ModelsMassAssigmentTest extends PHPUnit_Framework_TestCase
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

	public function testModels()
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
	}

	protected function _executeTestsNormal($di)
	{
		$robot = new Robots();
		$success = $robot->save(array(
			'type' => 'mechanical',
			'year' => 2018
		));
		$this->assertEquals($success, false);
		$this->assertEquals($robot->type, 'mechanical');
		$this->assertEquals($robot->year, 2018);

		$robot = new Robots();
		$robot->assign(array(
			'type' => 'mechanical',
			'year' => 2018
		));
		$this->assertEquals($robot->type, 'mechanical');
		$this->assertEquals($robot->year, 2018);

		//not assigns nonexistent fields
		$robot = new Robots();
		$robot->assign(array(
			'field1' => 'mechanical',
			'field2' => 2018
		));
		$this->assertEquals(empty($robot->field1), true);
		$this->assertEquals(empty($robot->field2), true);

		//white list
		$robot = new Robots();
		$robot->assign(
			array(
				'type' => 'mechanical',
				'year' => 2018
			),
			null,
			array('type')
		);
		$this->assertEquals($robot->type, 'mechanical');
		$this->assertEquals(empty($robot->year), true);

		//white list
		$robot = new Robots();
		$robot->assign(
			array(
				'typeFromClient' => 'mechanical',
				'yearFromClient' => 2018
			),
			array(
				'typeFromClient' => 'type',
				'yearFromClient' => 'year',
			),
			array('type')
		);
		$this->assertEquals($robot->type, 'mechanical');
		$this->assertEquals(empty($robot->year), true);
	}

	protected function _executeTestsRenamed($di)
	{

		$robot = new Robotters();
		$success = $robot->save(array(
			'theType' => 'mechanical',
			'theYear' => 2018
		));
		$this->assertEquals($success, false);
		$this->assertEquals($robot->theType, 'mechanical');
		$this->assertEquals($robot->theYear, 2018);

		//assign uses column renaming
		$robot = new Robotters();
		$robot->assign(array(
			'theType' => 'mechanical',
			'theYear' => 2018
		));
		$this->assertEquals($robot->theType, 'mechanical');
		$this->assertEquals($robot->theYear, 2018);

		//not assigns nonexistent fields
		$robot = new Robotters();
		$robot->assign(array(
			'field1' => 'mechanical',
			'field2' => 2018
		));
		$this->assertEquals(empty($robot->field1), true);
		$this->assertEquals(empty($robot->field2), true);

		//white list
		$robot = new Robotters();
		$robot->assign(
			array(
				'theType' => 'mechanical',
				'theYear' => 2018
			),
			null,
			array('theType')
		);
		$this->assertEquals($robot->theType, 'mechanical');
		$this->assertEquals(empty($robot->theYear), true);

		//white list & custom mapping
		$robot = new Robotters();
		$robot->assign(
			array(
				'theTypeFromClient' => 'mechanical',
				'theYearFromClient' => 2018
			),
			array(
				'theTypeFromClient' => 'theType',
				'theYearFromClient' => 'theYear',
			),
			array('theType')
		);
		$this->assertEquals($robot->theType, 'mechanical');
		$this->assertEquals(empty($robot->theYear), true);
	}

}
