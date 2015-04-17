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

class ModelsFindersTest extends PHPUnit_Framework_TestCase
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

		$robot = Robots::findFirstById(1);
		$this->assertEquals(get_class($robot), 'Robots');
		$this->assertEquals($robot->id, 1);

		$robot = Robots::findFirstById(2);
		$this->assertEquals(get_class($robot), 'Robots');
		$this->assertEquals($robot->id, 2);

		$robots = Robots::findByType('mechanical');
		$this->assertEquals(count($robots), 2);
		$this->assertEquals($robots[0]->id, 1);

		$number = Robots::countByType('mechanical');
		$this->assertEquals($number, 2);
	}

	protected function _executeTestsRenamed($di)
	{

		$robot = Robotters::findFirstByCode(1);
		$this->assertEquals(get_class($robot), 'Robotters');
		$this->assertEquals($robot->code, 1);

		$robot = Robotters::findFirstByCode(2);
		$this->assertEquals(get_class($robot), 'Robotters');
		$this->assertEquals($robot->code, 2);

		$robots = Robotters::findByTheType('mechanical');
		$this->assertEquals(count($robots), 2);
		$this->assertEquals($robots[0]->code, 1);

		$number = Robotters::countByTheType('mechanical');
		$this->assertEquals($number, 2);
	}

}
