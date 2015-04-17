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

class CacheResultsetTest extends PHPUnit_Framework_TestCase
{

	protected $di;

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

	protected function _getCache($adapter='File'){

		@unlink('unit-tests/cache/test-resultset');

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		}, true);

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		}, true);

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		$frontCache = new Phalcon\Cache\Frontend\Data(array(
			'lifetime' => 3600
		));

		switch ($adapter) {
			case 'File':
				$cache = new Phalcon\Cache\Backend\File($frontCache, array(
					'cacheDir' => 'unit-tests/cache/'
				));
				break;
			case 'Memcached':
				$cache = new Phalcon\Cache\Backend\Memcache($frontCache, array(
					"host" => "localhost",
					"port" => "11211"
				));
				break;
			case 'Libmemcached':
				$cache = new Phalcon\Cache\Backend\Libmemcached($frontCache, array(
					"servers" => array(
						array(
							"host" => "localhost",
							"port" => "11211",
							"weight" => "1",
						)
					)
				));
				break;
			default:
				throw new Exception("Unknown cache adapter");
		}

		$di->set('modelsCache', $cache);

		$this->_di = $di;

		return $cache;
	}

	public function testCacheResultsetNormal()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$cache = $this->_getCache();

		$cache->save('test-resultset', Robots::find(array('order' => 'id')));

		$this->assertTrue(file_exists('unit-tests/cache/test-resultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

	public function testCacheResultsetBinding()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$cache = $this->_getCache();

		$initialId = 0;
		$finalId = 4;

		$cache->save('test-resultset', Robots::find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		)));

		$this->assertTrue(file_exists('unit-tests/cache/test-resultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

	public function testCacheResultsetSimple()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$cache = $this->_getCache();

		$modelsManager = $this->_di->get('modelsManager');

		$robots = $modelsManager->executeQuery('SELECT * FROM Robots');

		$cache->save('test-resultset', $robots);

		$this->assertTrue(file_exists('unit-tests/cache/test-resultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

	public function testCacheResultsetSimpleNoComplete()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$cache = $this->_getCache();

		$modelsManager = $this->_di->get('modelsManager');

		$robots = $modelsManager->executeQuery('SELECT id FROM Robots');

		$cache->save('test-resultset', $robots);

		$this->assertTrue(file_exists('unit-tests/cache/test-resultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

	public function testCacheResultsetSimpleNoComplex()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$cache = $this->_getCache();

		$modelsManager = $this->_di->get('modelsManager');

		$results = $modelsManager->executeQuery('SELECT r.*, p.* FROM Robots r JOIN RobotsParts p');

		$cache->save('test-resultset', $results);

		$this->assertTrue(file_exists('unit-tests/cache/test-resultset'));

		$results = $cache->get('test-resultset');

		$this->assertEquals(get_class($results), 'Phalcon\Mvc\Model\Resultset\Complex');
		$this->assertEquals(count($results), 3);
		$this->assertEquals($results->count(), 3);

	}

	public function testCacheResultsetSimpleMemcached()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		if (!class_exists('Memcache')) {
			$this->markTestSkipped("Memcache class does not exist, test skipped");
			return;
		}

		$cache = $this->_getCache('Memcached');

		$key = 'test-resultset-'.mt_rand(0, 9999);

		//Single
		$people = People::findFirst(array(
			'cache' => array(
				'key' => $key
			)
		));

		$this->assertTrue(is_object($people));

		$people = $cache->get($key);
		$this->assertEquals(get_class($people->getFirst()), 'People');

		$people = $cache->get($key);
		$this->assertEquals(get_class($people->getFirst()), 'People');

		//Re-get from the cache
		$people = People::findFirst(array(
			'cache' => array(
				'key' => $key
			)
		));

		$this->assertTrue(is_object($people));

		$key = 'test-resultset-'.mt_rand(0, 9999);

		//Multiple
		$people = People::find(array(
			'limit' => 35,
			'cache' => array(
				'key' => $key
			)
		));

		$number = 0;
		foreach ($people as $individual) {
			$this->assertTrue(is_object($individual));
			$number++;
		}
		$this->assertEquals($number, 35);

		$people = $cache->get($key);
		$this->assertEquals(get_class($people), 'Phalcon\Mvc\Model\Resultset\Simple');

		$number = 0;
		foreach ($people as $individual) {
			$this->assertTrue(is_object($individual));
			$number++;
		}
		$this->assertEquals($number, 35);

		$people = $cache->get($key);
		$this->assertEquals(get_class($people), 'Phalcon\Mvc\Model\Resultset\Simple');

		//Re-get the data from the cache
		$people = People::find(array(
			'limit' => 35,
			'cache' => array(
				'key' => $key
			)
		));

		$number = 0;
		foreach ($people as $individual) {
			$this->assertTrue(is_object($individual));
			$number++;
		}
		$this->assertEquals($number, 35);
	}

	public function testCacheResultsetSimpleLibmemcached()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		if (!class_exists('Memcached')) {
			$this->markTestSkipped("Memcached class does not exist, test skipped");
			return;
		}

		$cache = $this->_getCache('Libmemcached');

		$key = 'test-resultset-'.mt_rand(0, 9999);

		//Single
		$people = People::findFirst(array(
			'cache' => array(
				'key' => $key
			)
		));

		$this->assertTrue(is_object($people));

		$people = $cache->get($key);
		$this->assertEquals(get_class($people->getFirst()), 'People');

		$people = $cache->get($key);
		$this->assertEquals(get_class($people->getFirst()), 'People');

		//Re-get from the cache
		$people = People::findFirst(array(
			'cache' => array(
				'key' => $key
			)
		));

		$this->assertTrue(is_object($people));

		$key = 'test-resultset-'.mt_rand(0, 9999);

		//Multiple
		$people = People::find(array(
			'limit' => 35,
			'cache' => array(
				'key' => $key
			)
		));

		$number = 0;
		foreach ($people as $individual) {
			$this->assertTrue(is_object($individual));
			$number++;
		}
		$this->assertEquals($number, 35);

		$people = $cache->get($key);
		$this->assertEquals(get_class($people), 'Phalcon\Mvc\Model\Resultset\Simple');

		$number = 0;
		foreach ($people as $individual) {
			$this->assertTrue(is_object($individual));
			$number++;
		}
		$this->assertEquals($number, 35);

		$people = $cache->get($key);
		$this->assertEquals(get_class($people), 'Phalcon\Mvc\Model\Resultset\Simple');

		//Re-get the data from the cache
		$people = People::find(array(
			'limit' => 35,
			'cache' => array(
				'key' => $key
			)
		));

		$number = 0;
		foreach ($people as $individual) {
			$this->assertTrue(is_object($individual));
			$number++;
		}
		$this->assertEquals($number, 35);

	}

}
