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
		foreach ($iterator as $item) {
			if (!$item->isDir()) {
				unlink($item->getPathname());
			}
		}
	}

	private function _prepareTestMysql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			return null;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		return $di;
	}

	private function _prepareTestPostgresql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			return null;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		return $di;
	}

	private function _prepareTestSqlite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			return null;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
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
		}, true);

		$robots = Robots::find(array(
			'cache' => array('key' => 'some'),
			'order' => 'id'
		));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array(
			'cache' => array('key' => 'some'),
			'order' => 'id'
		));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	protected function _testCacheDefaultDIBindings($di)
	{

		$di->set('modelsCache', function(){
			$frontCache = new Phalcon\Cache\Frontend\Data();
			return new Phalcon\Cache\Backend\File($frontCache, array(
				'cacheDir' => 'unit-tests/cache/'
			));
		}, true);

		$robots = Robots::find(array(
			'cache' => array('key' => 'some'),
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => 0, 'id2' => 4),
			'order' => 'id'
		));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array(
			'cache' => array('key' => 'some'),
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => 0, 'id2' => 4),
			'order' => 'id'
		));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

	}

	protected function _testCacheOtherService($di)
	{

		$di->set('otherCache', function(){
			$frontCache = new Phalcon\Cache\Frontend\Data();
			return new Phalcon\Cache\Backend\File($frontCache, array(
				'cacheDir' => 'unit-tests/cache/'
			));
		}, true);

		$robots = Robots::find(array(
			'cache' => array(
				'key' => 'other-some',
				'lifetime' => 60,
				'service' => 'otherCache'
			),
			'order' => 'id'
		));
		$this->assertEquals(count($robots), 3);
		$this->assertTrue($robots->isFresh());

		$robots = Robots::find(array(
			'cache' => array(
				'key' => 'other-some',
				'lifetime' => 60,
				'service' => 'otherCache'
			),
			'order' => 'id'
		));
		$this->assertEquals(count($robots), 3);
		$this->assertFalse($robots->isFresh());

		$this->assertEquals($robots->getCache()->getLastKey(), 'other-some');

		$this->assertEquals($robots->getCache()->queryKeys(), array(
			0 => 'other-some',
		));
	}

	public function testCacheDefaultDIMysql()
	{
		$di = $this->_prepareTestMysql();
		if ($di) {
			$this->_testCacheDefaultDI($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDIPostgresql()
	{
		$di = $this->_prepareTestPostgresql();
		if ($di) {
			$this->_testCacheDefaultDI($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDISqlite()
	{
		$di = $this->_prepareTestSqlite();
		if ($di) {
			$this->_testCacheDefaultDI($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDIBindingsMysql()
	{
		$di = $this->_prepareTestMysql();
		if ($di) {
			$this->_testCacheDefaultDIBindings($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDIBindingsPostgresql()
	{
		$di = $this->_prepareTestPostgresql();
		if ($di) {
			$this->_testCacheDefaultDIBindings($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDIBindingsSqlite()
	{
		$di = $this->_prepareTestSqlite();
		if ($di) {
			$this->_testCacheDefaultDIBindings($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheOtherServiceMysql()
	{
		$di = $this->_prepareTestMysql();
		if ($di) {
			$this->_testCacheOtherService($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheOtherServicePostgresql()
	{
		$di = $this->_prepareTestPostgresql();
		if ($di) {
			$robots = $this->_testCacheOtherService($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheOtherServiceSqlite()
	{
		$di = $this->_prepareTestSqlite();
		if ($di) {
			$robots = $this->_testCacheOtherService($di);
		}
		else {
			$this->markTestSkipped("Skipped");
		}
	}

}
