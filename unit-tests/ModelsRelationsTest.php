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

class ModelsRelationsTest extends PHPUnit_Framework_TestCase {

	public function testModelsMysql(){

		require 'unit-tests/config.db.php';

		Phalcon\Db\Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon\Db\Pool::hasDefaultDescriptor());

		$this->_executeTests();

	}

	public function testModelsPostgresql(){

		require 'unit-tests/config.db.php';

		Phalcon\Db\Pool::setDefaultDescriptor($configPostgresql);
		$this->assertTrue(Phalcon\Db\Pool::hasDefaultDescriptor());

		$this->_executeTests();

	}

	public function _executeTests(){

		Phalcon\Model\Manager::reset();

		$manager = new Phalcon\Model\Manager();
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$success = $manager->load('Parts');
		$this->assertTrue($success);

		$success = $manager->load('RobotsParts');
		$this->assertTrue($success);

		$success = $manager->existsBelongsTo('RobotsParts', 'Robots');
		$this->assertTrue($success);

		$success = $manager->existsBelongsTo('RobotsParts', 'Parts');
		$this->assertTrue($success);

		$success = $manager->existsHasMany('Robots', 'RobotsParts');
		$this->assertTrue($success);

		$success = $manager->existsHasMany('Parts', 'RobotsParts');
		$this->assertTrue($success);

		$robot = Robots::findFirst();
		$this->assertNotEquals($robot, false);

		$robotsParts = $robot->getRobotsParts();
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Model\Resultset');
		$this->assertEquals(count($robotsParts), 3);

		$number = $robot->countRobotsParts();
		$this->assertEquals($number, 3);

		$part = Parts::findFirst();
		$this->assertNotEquals($part, false);

		$robotsParts = $part->getRobotsParts();
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Model\Resultset');
		$this->assertEquals(count($robotsParts), 1);

		$number = $part->countRobotsParts();
		$this->assertEquals($number, 1);

		$robotPart = RobotsParts::findFirst();
		$this->assertNotEquals($robotPart, false);

		$robot = $robotPart->getRobots();
		$this->assertEquals(get_class($robot), 'Robots');

		$part = $robotPart->getParts();
		$this->assertEquals(get_class($part), 'Parts');

	}

}