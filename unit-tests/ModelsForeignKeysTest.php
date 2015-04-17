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

class ModelsForeignKeysTest extends PHPUnit_Framework_TestCase
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

	public function testForeignKeysMysql()
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
	}

	public function testForeignKeysPostgresql()
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
	}

	public function testForeignKeysSqlite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
		}, true);

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
	}

	public function _executeTestsNormal($di)
	{

		//Normal foreign keys
		$robotsParts = new RobotsParts();
		$robotsParts->robots_id = 1;
		$robotsParts->parts_id = 100;

		$this->assertFalse($robotsParts->save());

		$messages = array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Value of field "parts_id" does not exist on referenced table',
				'_field' => 'parts_id',
				'_code' => 0,
  			))
  		);

		$this->assertEquals($robotsParts->getMessages(), $messages);

		$robotsParts->robots_id = 100;
		$robotsParts->parts_id = 1;
		$this->assertFalse($robotsParts->save());

		$messages = array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'The robot code does not exist',
				'_field' => 'robots_id',
				'_code' => 0,
  			))
  		);

		$this->assertEquals($robotsParts->getMessages(), $messages);

		//Reverse foreign keys

		$robot = Robots::findFirst();
		$this->assertNotEquals($robot, false);

		$this->assertFalse($robot->delete());

		$messages = array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Record is referenced by model RobotsParts',
				'_field' => 'id',
				'_code' => 0,
			))
		);

		$this->assertEquals($robot->getMessages(), $messages);

		$part = Parts::findFirst();
		$this->assertNotEquals($part, false);

		$this->assertFalse($part->delete());

		$messages = array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Parts cannot be deleted because is referenced by a Robot',
				'_field' => 'id',
				'_code' => 0,
			))
		);

		$this->assertEquals($part->getMessages(), $messages);

	}

	public function _executeTestsRenamed($di)
	{

		//Normal foreign keys with column renaming
		$robottersDeles = new RobottersDeles();
		$robottersDeles->robottersCode = 1;
		$robottersDeles->delesCode = 100;
		$this->assertFalse($robottersDeles->save());

		$messages = array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Value of field "delesCode" does not exist on referenced table',
				'_field' => 'delesCode',
				'_code' => 0,
  			))
  		);

		$this->assertEquals($robottersDeles->getMessages(), $messages);

		$robottersDeles->robottersCode = 100;
		$robottersDeles->delesCode = 1;
		$this->assertFalse($robottersDeles->save());

		$messages = array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'The robotters code does not exist',
				'_field' => 'robottersCode',
				'_code' => 0,
  			))
  		);

		$this->assertEquals($robottersDeles->getMessages(), $messages);

		//Reverse foreign keys with renaming
		$robotter = Robotters::findFirst();
		$this->assertNotEquals($robotter, false);

		$this->assertFalse($robotter->delete());

		$messages = array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Record is referenced by model RobottersDeles',
				'_field' => 'code',
				'_code' => 0,
			))
		);

		$this->assertEquals($robotter->getMessages(), $messages);

		$dele = Deles::findFirst();
		$this->assertNotEquals($dele, false);

		$this->assertFalse($dele->delete());

		$messages = array(
			0 => Phalcon\Mvc\Model\Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Deles cannot be deleted because is referenced by a Robotter',
				'_field' => 'code',
				'_code' => 0,
			))
		);

		$this->assertEquals($dele->getMessages(), $messages);

	}

}
