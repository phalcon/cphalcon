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

class CacheResultsetTest extends PHPUnit_Framework_TestCase {

	public function testCacheResultset(){

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

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$backendOptions = array(
			'cacheDir' => 'unit-tests/cache/'
		);

		@unlink('unit-tests/cache/testresultset');

		$cache = Phalcon_Cache::factory('Data', 'File', null, $backendOptions);
		$this->assertInstanceOf('Phalcon_Cache_Backend_File', $cache);

		$cache->save('test-resultset', Robots::find(array('order' => 'id')));

		$this->assertTrue(file_exists('unit-tests/cache/testresultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon_Model_Resultset');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

}