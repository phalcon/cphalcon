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

class ModelsQueryTest extends PHPUnit_Framework_TestCase {

	public function testQueryMysql(){

		Phalcon\Db\Pool::reset();

		require 'unit-tests/config.db.php';

		Phalcon\Db\Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon\Db\Pool::hasDefaultDescriptor());

		$this->_executeTests();
	}

	public function testQueryPostgresql(){

		Phalcon\Db\Pool::reset();

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

		$query = new Phalcon\Model\Query();
		$query->setManager($manager);
		$query->from('Robots');
		$query->where('id = ?0');
		$query->where('name LIKE ?1');
		$query->setParameters(array(0 => '10', 1 => '%Astro%'));

		$this->assertEquals($query->getConditions(), 'id = 10 AND name LIKE \'%Astro%\'');

		$query = Phalcon\Model\Query::fromInput('Robots', array(
			'id' => 10,
			'name' => 'Astro'
		));
		$this->assertEquals($query->getConditions(), 'id = 10 AND name LIKE \'%Astro%\'');

	}


}