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

	protected function _getCache(){

		@unlink('unit-tests/cache/testresultset');

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

		$cache = new Phalcon\Cache\Backend\File($frontCache, array(
			'cacheDir' => 'unit-tests/cache/'
		));

		$this->_di = $di;

		return $cache;
	}

	public function testCacheResultsetNormal()
	{

		$cache = $this->_getCache();

		$cache->save('test-resultset', Robots::find(array('order' => 'id')));

		$this->assertTrue(file_exists('unit-tests/cache/testresultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

	public function testCacheResultsetBinding()
	{

		$cache = $this->_getCache();

		$initialId = 0;
		$finalId = 4;

		$cache->save('test-resultset', Robots::find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		)));

		$this->assertTrue(file_exists('unit-tests/cache/testresultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

	public function testCacheResultsetSimple()
	{

		$cache = $this->_getCache();

		$modelsManager = $this->_di->get('modelsManager');

		$robots = $modelsManager->executeQuery('SELECT * FROM Robots');

		$cache->save('test-resultset', $robots);

		$this->assertTrue(file_exists('unit-tests/cache/testresultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

	public function testCacheResultsetSimpleNoComplete()
	{

		$cache = $this->_getCache();

		$modelsManager = $this->_di->get('modelsManager');

		$robots = $modelsManager->executeQuery('SELECT id FROM Robots');

		$cache->save('test-resultset', $robots);

		$this->assertTrue(file_exists('unit-tests/cache/testresultset'));

		$robots = $cache->get('test-resultset');

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

	}

	public function testCacheResultsetSimpleNoComplex()
	{

		$cache = $this->_getCache();

		$modelsManager = $this->_di->get('modelsManager');

		$results = $modelsManager->executeQuery('SELECT r.*, p.* FROM Robots r JOIN RobotsParts p');

		$cache->save('test-resultset', $results);

		$this->assertTrue(file_exists('unit-tests/cache/testresultset'));

		$results = $cache->get('test-resultset');

		$this->assertEquals(get_class($results), 'Phalcon\Mvc\Model\Resultset\Complex');
		$this->assertEquals(count($results), 3);
		$this->assertEquals($results->count(), 3);

	}

}
