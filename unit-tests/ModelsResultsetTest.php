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

class ModelsResultsetTest extends PHPUnit_Framework_TestCase {

	private function _prepareTest(){

		require 'unit-tests/config.db.php';

		Phalcon_Db_Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon_Db_Pool::hasDefaultDescriptor());

		$manager = new Phalcon_Model_Manager();
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

	}

	public function testResultset(){
		$this->_prepareTest();
		$robots = Robots::find(array('order' => 'id'));
		$this->_applyTests($robots);
	}

	public function _applyTests($robots){

		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

		//Using a foreach
		$number = 0;
		foreach($robots as $robot){
			$this->assertEquals($robot->id, $number+1);
			$number++;
		}
		$this->assertEquals($number, 3);

		//Using a while
		$number = 0;
		$robots->rewind();
		while($robots->valid()){
			$robot = $robots->current();
			$this->assertEquals($robot->id, $number+1);
			$robots->next();
			$number++;
		}
		$this->assertEquals($number, 3);

		$robots->seek(1);
		$robots->valid();
		$robot = $robots->current();
		$this->assertEquals($robot->id, 2);

		$robot = $robots->getFirst();
		$this->assertEquals($robot->id, 1);

		$robot = $robots->getLast();
		$this->assertEquals($robot->id, 3);

		$robot = $robots[0];
		$this->assertEquals($robot->id, 1);

		$robot = $robots[2];
		$this->assertEquals($robot->id, 3);

		$this->assertFalse(isset($robots[4]));

	}

	public function testSerialize(){

		$this->_prepareTest();

		$data = serialize(Robots::find(array('order' => 'id')));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon_Model_Resultset');

		$this->_applyTests($robots);

	}

}