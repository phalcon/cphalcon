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

class ModelsResultsetCacheTest extends PHPUnit_Framework_TestCase
{

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
		if (file_exists('unit-tests/app/models/'.$className.'.php')) {
			require 'unit-tests/app/models/'.$className.'.php';
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
		$iterator = new DirectoryIterator('unit-tests/app/var/cache/');
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
			require 'unit-tests/app/var/config/config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		return $di;
	}

	private function _prepareTestPostgresql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/app/var/config/config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		return $di;
	}

	protected function _testCacheDefaultDI($di)
	{

		$di->set('modelsCache', function(){
			$frontCache = new Phalcon\Cache\Frontend\Data();
			return new Phalcon\Cache\Backend\File($frontCache, array(
				'cacheDir' => 'unit-tests/app/var/config/'
			));
		});

		$robots = Robots::find(array('cache' => array('key' => 'some'), 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => array('key' => 'some'), 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	public function testCacheDefaultDIMysql()
	{
		$di = $this->_prepareTestMysql();
		return $this->_testCacheDefaultDI($di);
	}

//	public function testCacheDefaultDIPostgresql()
//	{
//		$di = $this->_prepareTestPostgresql();
//		return $this->_testCacheDefaultDI($di);
//	}

	protected function _testCacheOtherService($di)
	{

		$di->set('otherCache', function(){
			$frontCache = new Phalcon\Cache\Frontend\Data();
			return new Phalcon\Cache\Backend\File($frontCache, array(
				'cacheDir' => 'unit-tests/app/var/cache/'
			));
		});

		$robots = Robots::find(array('cache' => array('key' => 'other-some', 'lifetime' => 60, 'service' => 'otherCache'), 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array('cache' => array('key' => 'other-some', 'lifetime' => 60, 'service' => 'otherCache'), 'order' => 'id'));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

		return $robots;
	}

	public function testCacheOtherServiceMysql()
	{

		$di = $this->_prepareTestMysql();
		$robots = $this->_testCacheOtherService($di);

		$this->assertEquals($robots->getCache()->getLastKey(), 'othersome');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'othersome',
		));
	}

	public function testCacheOtherServicePostgresql()
	{

		$di = $this->_prepareTestMysql();
		$robots = $this->_testCacheOtherService($di);

		$this->assertEquals($robots->getCache()->getLastKey(), 'othersome');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'othersome',
		));
	}

}
