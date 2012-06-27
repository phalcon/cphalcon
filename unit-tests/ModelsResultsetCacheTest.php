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

class ModelsResultsetCacheTest extends PHPUnit_Framework_TestCase {

	public function setUp(){
		$iterator = new DirectoryIterator('unit-tests/cache/');
		foreach($iterator as $item){
			if(!$item->isDir()){
				unlink($item->getPathname());
			}
		}
	}

	private function _prepareTest(){

		Phalcon_Db_Pool::reset();
		Phalcon_Model_Manager::reset();

		require 'unit-tests/config.db.php';

		Phalcon_Db_Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon_Db_Pool::hasDefaultDescriptor());

	}

	public function testCacheResultsetDirect(){

		$this->_prepareTest();

		$manager = new Phalcon_Model_Manager();
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$cache = Phalcon_Cache::factory('Data', 'File', null, array(
			'cacheDir' => 'unit-tests/cache/'
		));
		$this->assertInstanceOf('Phalcon_Cache_Backend_File', $cache);

		$manager->setCache($cache);
		$this->assertInstanceOf('Phalcon_Cache_Backend_File', $manager->getCache());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	public function testCacheResultsetConfig(){

		$this->_prepareTest();

		Phalcon_Model_Manager::reset();

		$config = new stdClass();
		$config->cache = new stdClass();
		$config->cache->adapter = 'File';
		$config->cache->cacheDir = 'unit-tests/cache/';

		$manager = new Phalcon_Model_Manager($config);
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$this->assertInstanceOf('Phalcon_Cache_Backend_File', $manager->getCache());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	public function testCacheResultsetNoLifetime(){

		$this->_prepareTest();

		Phalcon_Model_Manager::reset();

		$config = new stdClass();
		$config->cache = new stdClass();
		$config->cache->adapter = 'File';
		$config->cache->cacheDir = 'unit-tests/cache/';

		$manager = new Phalcon_Model_Manager($config);
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$this->assertInstanceOf('Phalcon_Cache_Backend_File', $manager->getCache());

		$robots = Robots::find(array('cache' => true, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => true, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	public function testCacheResultsetConfigKey(){

		$this->_prepareTest();

		Phalcon_Model_Manager::reset();

		$config = new stdClass();
		$config->cache = new stdClass();
		$config->cache->adapter = 'File';
		$config->cache->lifetime = 86400;
		$config->cache->cacheDir = 'unit-tests/cache/';

		$manager = new Phalcon_Model_Manager($config);
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$this->assertInstanceOf('Phalcon_Cache_Backend_File', $manager->getCache());

		$params = array('cache' => array('key' => 'mykey'), 'order' => 'id');

		$robots = Robots::find($params);
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find($params);
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

}
