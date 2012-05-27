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

class ModelsForeignKeysTest extends PHPUnit_Framework_TestCase {

	public function testModels(){

		$config = array(
			'adapter' => 'Mysql',
			'host' => '127.0.0.1',
			'username' => 'root',
			'password' => '',
			'name' => 'phalcon_test'
		);

		Phalcon_Db_Pool::setDefaultDescriptor($config);
		$this->assertTrue(Phalcon_Db_Pool::hasDefaultDescriptor());

		$manager = new Phalcon_Model_Manager();
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('RobotsParts');
		$this->assertTrue($success);

		//Normal foreign keys
		$robotsParts = new RobotsParts();
		$robotsParts->robots_id = 1;
		$robotsParts->parts_id = 100;
		$this->assertFalse($robotsParts->save());

		$messages = array(
			0 => Phalcon_Model_Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Value of field "parts_id" does not exist on referenced table',
				'_field' => 'parts_id',
  			))
  		);

		$this->assertEquals($robotsParts->getMessages(), $messages);

		$robotsParts->robots_id = 100;
		$robotsParts->parts_id = 1;
		$this->assertFalse($robotsParts->save());

		$messages = array(
			0 => Phalcon_Model_Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'The robot code does not exist',
				'_field' => 'robots_id',
  			))
  		);

		$this->assertEquals($robotsParts->getMessages(), $messages);

		//Reverse foreign keys
		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$robot = Robots::findFirst();
		$this->assertNotEquals($robot, false);

		$this->assertFalse($robot->delete());

		$messages = array(
			0 => Phalcon_Model_Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Record is referenced by model RobotsParts',
				'_field' => 'id',
			))
		);

		$this->assertEquals($robot->getMessages(), $messages);

		$success = $manager->load('Parts');
		$this->assertTrue($success);

		$part = Parts::findFirst();
		$this->assertNotEquals($part, false);

		$this->assertFalse($part->delete());

		$messages = array(
			0 => Phalcon_Model_Message::__set_state(array(
				'_type' => 'ConstraintViolation',
				'_message' => 'Parts cannot be deleted because is referenced by a Robot',
				'_field' => 'id',
			))
		);

		$this->assertEquals($part->getMessages(), $messages);

	}

}
