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

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		return $di;
	}

	public function setUp()
	{
		$iterator = new DirectoryIterator('unit-tests/cache/');
		foreach($iterator as $item){
			if(!$item->isDir()){
				unlink($item->getPathname());
			}
		}
	}

	private function _prepareTestMysql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		return $di;
	}

	private function _prepareTestPostgresql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		return $di;
	}

	protected function _testCacheDefaultDI($di)
	{

		$di->set('modelsCache', function(){
			$frontCache = new Phalcon\Cache\Frontend\Data();
			return new Phalcon\Cache\Backend\File($frontCache, array(
				'cacheDir' => 'unit-tests/cache/'
			));
		});

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => 60, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	public function testCacheDefaultDIMysql()
	{
		$di = $this->_prepareTestMysql();
		return $this->_testCacheDefaultDI($di);
	}

	public function testCacheDefaultDIPostgresql()
	{
		$di = $this->_prepareTestPostgresql();
		return $this->_testCacheDefaultDI($di);
	}

	protected function _testCacheOtherService($di)
	{

		$di->set('otherCache', function(){
			$frontCache = new Phalcon\Cache\Frontend\Data();
			return new Phalcon\Cache\Backend\File($frontCache, array(
				'cacheDir' => 'unit-tests/cache/'
			));
		});

		$robots = Robots::find(array('cache' => array('lifetime' => 60, 'service' => 'otherCache'), 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => array('lifetime' => 60, 'service' => 'otherCache'), 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

		return $robots;
	}

	public function testCacheOtherServiceMysql()
	{

		$di = $this->_prepareTestMysql();
		$robots = $this->_testCacheOtherService($di);

		$this->assertEquals($robots->getCache()->getLastKey(), 'phcd2b64883305e92cdaf5078930d881382');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'phcd2b64883305e92cdaf5078930d881382',
		));
	}

	public function testCacheOtherServicePostgresql()
	{

		$di = $this->_prepareTestPostgresql();
		$robots = $this->_testCacheOtherService($di);

		$this->assertEquals($robots->getCache()->getLastKey(), 'phc7b01793487150c7241316e982a3a8b83');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'phc7b01793487150c7241316e982a3a8b83',
		));
	}

	public function _testCacheDirect()
	{

		$frontCache = new Phalcon\Cache\Frontend\Data();
		$cache = new Phalcon\Cache\Backend\File($frontCache, array(
			'cacheDir' => 'unit-tests/cache/'
		));

		$robots = Robots::find(array('cache' => $cache, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => $cache, 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

		return $robots;
	}

	public function testCacheDirectMysql()
	{

		$di = $this->_prepareTestMysql();
		$robots = $this->_testCacheDirect($di);

		$this->assertEquals($robots->getCache()->getLastKey(), 'phcd2b64883305e92cdaf5078930d881382');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'phcd2b64883305e92cdaf5078930d881382',
		));
	}

	public function testCacheDirectPostgresql()
	{

		$di = $this->_prepareTestPostgresql();
		$robots = $this->_testCacheDirect($di);

		$this->assertEquals($robots->getCache()->getLastKey(), 'phc7b01793487150c7241316e982a3a8b83');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'phc7b01793487150c7241316e982a3a8b83',
		));
	}

}
