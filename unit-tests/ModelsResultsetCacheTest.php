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
		if (file_exists('unit-tests/models/' . $className . '.php')) {
			require 'unit-tests/models/' . $className . '.php';
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
		}, true);

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
		}, true);

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
		}, true);

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

		//Find
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

		//TODO: I really can't understand why postgresql fails on inserting a simple record
		//The error is "Object not in prerequisite state: 7 ERROR:
		//currval of sequence "robots_id_seq" is not yet defined in this session"
		//Is the ORM working with postgresql, is the database structure incorrect or
		//I'm using the wrong code?
		//Skip this test until someone can shed some light on this
		if (!$di->get("db") instanceof Phalcon\Db\Adapter\Pdo\Postgresql) {
			//Aggregate functions like sum, count, etc
			$robotscount = Robots::count(array(
				'cache' => array('key' => 'some-count'),
			));
			$this->assertEquals($robotscount, 3);

			//Create a temporary robot to test if the count is cached or fresh
			$newrobot = new Robots();
			$newrobot->name = "Not cached robot";
			$newrobot->type = "notcached";
			$newrobot->year = 2014;
			$newrobot->datetime = '2015-03-05 04:16:17';
			$newrobot->text = 'Not cached robot';
			$newrobot->create();

			$robotscount = Robots::count(array(
				'cache' => array('key' => 'some-count'),
			));
			$this->assertEquals($robotscount, 3);

			//Delete the temp robot
			Robots::findFirst("type = 'notcached'")->delete();
		}
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
		} else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDIPostgresql()
	{
		$di = $this->_prepareTestPostgresql();
		if ($di) {
			$this->_testCacheDefaultDI($di);
		} else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDISqlite()
	{
		$di = $this->_prepareTestSqlite();
		if ($di) {
			$this->_testCacheDefaultDI($di);
		} else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDIBindingsMysql()
	{
		$di = $this->_prepareTestMysql();
		if ($di) {
			$this->_testCacheDefaultDIBindings($di);
		} else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDIBindingsPostgresql()
	{
		$di = $this->_prepareTestPostgresql();
		if ($di) {
			$this->_testCacheDefaultDIBindings($di);
		} else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheDefaultDIBindingsSqlite()
	{
		$di = $this->_prepareTestSqlite();
		if ($di) {
			$this->_testCacheDefaultDIBindings($di);
		} else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheOtherServiceMysql()
	{
		$di = $this->_prepareTestMysql();
		if ($di) {
			$this->_testCacheOtherService($di);
		} else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheOtherServicePostgresql()
	{
		$di = $this->_prepareTestPostgresql();
		if ($di) {
			$robots = $this->_testCacheOtherService($di);
		} else {
			$this->markTestSkipped("Skipped");
		}
	}

	public function testCacheOtherServiceSqlite()
	{
		$di = $this->_prepareTestSqlite();
		if ($di) {
			$robots = $this->_testCacheOtherService($di);
		} else {
			$this->markTestSkipped("Skipped");
		}
	}
}
