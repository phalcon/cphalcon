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

class DbProfiler extends Phalcon_Db_Profiler {

	private $_points = 0;

	public function beforeStartProfile($profile){
		$this->_points++;
	}

	public function afterEndProfile($profile){
		$this->_points--;
	}

	public function getPoints(){
		return $this->_points;
	}

}

class DbProfilerTest extends PHPUnit_Framework_TestCase {

	public function testDb(){

		$config = new stdClass();
		$config->host = '127.0.0.1';
		$config->username = 'root';
		$config->password = '';
		$config->name = 'phalcon_test';

		$connection = Phalcon_Db::factory('Mysql', $config);
		$this->assertTrue(is_object($connection));

		$profiler = new DbProfiler();

		$connection->setProfiler($profiler);

		$connection->query("SELECT * FROM personas LIMIT 3");

		$this->assertEquals($profiler->getNumberTotalStatements(), 1);

		$profile = $profiler->getLastProfile();
		$this->assertEquals(get_class($profile), 'Phalcon_Db_Profiler_Item');

		$this->assertEquals($profile->getSQLStatement(), "SELECT * FROM personas LIMIT 3");
		$this->assertEquals(gettype($profile->getInitialTime()), "double");
		$this->assertEquals(gettype($profile->getFinalTime()), "double");
		$this->assertEquals(gettype($profile->getTotalElapsedSeconds()), "double");
		$this->assertTrue($profile->getFinalTime()>$profile->getInitialTime());

		$connection->query("SELECT * FROM personas LIMIT 100");

		$this->assertEquals($profiler->getNumberTotalStatements(), 2);

		$profile = $profiler->getLastProfile();
		$this->assertEquals(get_class($profile), 'Phalcon_Db_Profiler_Item');

		$this->assertEquals($profile->getSQLStatement(), "SELECT * FROM personas LIMIT 100");
		$this->assertTrue($profile->getFinalTime()>$profile->getInitialTime());

		$connection->query("SELECT * FROM personas LIMIT 5");
		$connection->query("SELECT * FROM personas LIMIT 10");
		$connection->query("SELECT * FROM personas LIMIT 15");

		$this->assertEquals(count($profiler->getProfiles()), 5);
		$this->assertEquals($profiler->getNumberTotalStatements(), 5);
		$this->assertEquals(gettype($profiler->getTotalElapsedSeconds()), "double");
		$this->assertEquals($profiler->getPoints(), 0);

		$profiler->reset();

		$this->assertEquals(count($profiler->getProfiles()), 0);
		$this->assertEquals($profiler->getNumberTotalStatements(), 0);

	}

}
