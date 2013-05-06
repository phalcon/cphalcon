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

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

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

		$robot = new Robotters();

		$robot->assign(array(
			'theType' => 'mechanical',
			'theYear' => 2018
		));

		$this->assertEquals($robot->theType, 'mechanical');
		$this->assertEquals($robot->theYear, 2018);
	}

}
