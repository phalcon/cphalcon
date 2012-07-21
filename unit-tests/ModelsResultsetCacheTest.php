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

	private function _prepareTestMysql(){

		Phalcon\Db\Pool::reset();
		Phalcon\Model\Manager::reset();

		require 'unit-tests/config.db.php';

		Phalcon\Db\Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon\Db\Pool::hasDefaultDescriptor());

	}

	private function _prepareTestPostgresql(){

		Phalcon\Db\Pool::reset();
		Phalcon\Model\Manager::reset();

		require 'unit-tests/config.db.php';

		Phalcon\Db\Pool::setDefaultDescriptor($configPostgresql);
		$this->assertTrue(Phalcon\Db\Pool::hasDefaultDescriptor());

	}

	public function testCacheResultsetDirectMysql(){
		$this->_prepareTestMysql();
		$this->_testCacheDirect();
	}

	public function testCacheResultsetDirectPostgresql(){
		$this->_prepareTestPostgresql();
		$this->_testCacheDirect();
	}

	protected function _testCacheDirect(){

		Phalcon\Model\Manager::reset();

		$manager = new Phalcon\Model\Manager();
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$cache = Phalcon\Cache::factory('Data', 'File', null, array(
			'cacheDir' => 'unit-tests/cache/'
		));
		$this->assertInstanceOf('Phalcon\Cache\Backend\File', $cache);

		$manager->setCache($cache);
		$this->assertInstanceOf('Phalcon\Cache\Backend\File', $manager->getCache());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	public function testCacheResultsetConfigMysql(){

		$this->_prepareTestMysql();
		$robots = $this->_testCacheResultsetConfig();

		$this->assertEquals($robots->getCache()->getLastKey(), 'phcd2b64883305e92cdaf5078930d881382');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'phcd2b64883305e92cdaf5078930d881382',
		));
	}

	public function testCacheResultsetConfigPostgresql(){

		$this->_prepareTestPostgresql();
		$robots = $this->_testCacheResultsetConfig();

		$this->assertEquals($robots->getCache()->getLastKey(), 'phc7b01793487150c7241316e982a3a8b83');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'phc7b01793487150c7241316e982a3a8b83',
		));
	}

	protected function _testCacheResultsetConfig(){

		$config = new stdClass();
		$config->cache = new stdClass();
		$config->cache->adapter = 'File';
		$config->cache->cacheDir = 'unit-tests/cache/';

		$manager = new Phalcon\Model\Manager($config);
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$this->assertInstanceOf('Phalcon\Cache\Backend\File', $manager->getCache());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

		return $robots;
	}

	public function testCacheResultsetNoLifetime(){

		$this->_prepareTestMysql();

		Phalcon\Model\Manager::reset();

		$config = new stdClass();
		$config->cache = new stdClass();
		$config->cache->adapter = 'File';
		$config->cache->cacheDir = 'unit-tests/cache/';

		$manager = new Phalcon\Model\Manager($config);
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$this->assertInstanceOf('Phalcon\Cache\Backend\File', $manager->getCache());

		$robots = Robots::find(array('cache' => true, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => true, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	public function testCacheResultsetConfigKey(){

		$this->_prepareTestMysql();

		Phalcon\Model\Manager::reset();

		$config = new stdClass();
		$config->cache = new stdClass();
		$config->cache->adapter = 'File';
		$config->cache->lifetime = 86400;
		$config->cache->cacheDir = 'unit-tests/cache/';

		$manager = new Phalcon\Model\Manager($config);
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		$this->assertInstanceOf('Phalcon\Cache\Backend\File', $manager->getCache());

		$params = array('cache' => array('key' => 'mykey'), 'order' => 'id');

		$robots = Robots::find($params);
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find($params);
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

}
