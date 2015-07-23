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
  | If you did not receive a copy of the licnse and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

require_once 'helpers/xcache.php';

class ModelsMetadataAdaptersTest extends PHPUnit_Framework_TestCase
{

	private $_data = array(
		'meta-robots-robots' => array(
			0 => array(
				0 => 'id',
				1 => 'name',
				2 => 'type',
				3 => 'year',
			),
			1 => array(
				0 => 'id',
			),
			2 => array(
				0 => 'name',
				1 => 'type',
				2 => 'year',
			),
			3 => array(
				0 => 'id',
				1 => 'name',
				2 => 'type',
				3 => 'year',
			),
			4 => array(
				'id' => 0,
				'name' => 2,
				'type' => 2,
				'year' => 0,
			),
			5 => array(
				'id' => true,
				'year' => true,
			),
			8 => 'id',
			9 => array(
				'id' => 1,
				'name' => 2,
				'type' => 2,
				'year' => 1,
			),
			10 => array(),
			11 => array(),
			12 => array(),
			13 => array(
				'id' => 10,
				'name' => 70,
				'type' => 32,
				'year' => 11,
			),
			14 => array(
				'id' => 0,
				'name' => 0,
				'type' => 0,
				'year' => 0,
			),
			15 => array(
				'id' => 32,
				'name' => 70,
				'type' => 32,
				'year' => 32,
			)
		),
		'map-robots-robots' => array(
			0 => null,
			1 => null,
		)
	);

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

		$di->set('modelsQuery', 'Phalcon\Mvc\Model\Query');
		$di->set('modelsQueryBuilder', 'Phalcon\Mvc\Model\Query\Builder');
		$di->set('modelsCriteria', 'Phalcon\\Mvc\\Model\\Criteria');

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		return $di;
	}

	public function testMetadataMemory()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataSession()
	{
		@session_start();

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Session(array(
				'prefix' => 'my-local-app'
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$expectedSession = array(
			'$PMM$my-local-app' => $this->_data
		);

		$this->assertEquals($_SESSION, $expectedSession);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataApc()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		if (!function_exists('apc_fetch')) {
			$this->markTestSkipped('apc extension is not loaded');
			return false;
		}

		apc_delete('$PMM$my-local-app');

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Apc(array(
				'prefix' => 'my-local-app',
				'lifetime' => 60
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals(apc_fetch('$PMM$my-local-appmeta-robots-robots'), $this->_data['meta-robots-robots']);
		$this->assertEquals(apc_fetch('$PMM$my-local-appmap-robots-robots'), $this->_data['map-robots-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataXcache()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		if (!function_exists('xcache_get')) {
			$this->markTestSkipped('xcache extension is not loaded');
			return false;
		}

		xcache_unset('$PMM$my-local-app');

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Xcache(array(
				'prefix' => 'my-local-app',
				'lifetime' => 60
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals(apc_fetch('$PMM$my-local-appmeta-robots-robots'), $this->_data['meta-robots-robots']);
		$this->assertEquals(apc_fetch('$PMM$my-local-appmap-robots-robots'), $this->_data['map-robots-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataFiles()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Files(array(
				'metaDataDir' => 'unit-tests/cache/',
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals(require 'unit-tests/cache/meta-robots-robots.php', $this->_data['meta-robots-robots']);
		$this->assertEquals(require 'unit-tests/cache/map-robots-robots.php', $this->_data['map-robots-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataMemcached()
	{
		if (!extension_loaded('memcache')) {
			$this->markTestSkipped('Warning: memcache extension is not loaded');
			return false;
		}

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memcache(array(
				'host' => 'localhost',
				'port' => 11211,
				'persistent' => TRUE,
				'prefix' => 'my-local-app',
				'lifetime' => 60
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals($metaData->read('meta-robots-robots'), $this->_data['meta-robots-robots']);
		$this->assertEquals($metaData->read('map-robots-robots'), $this->_data['map-robots-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataLibmemcached()
	{
		if (!extension_loaded('memcached')) {
			$this->markTestSkipped('Warning: memcached extension is not loaded');
			return false;
		}

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Libmemcached(array(
				'servers' => array(
					array('host' => 'localhost', 'port' => 11211, 'weight' => 1),
				),
				'prefix' => 'my-local-app',
				'lifetime' => 60
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals($metaData->read('meta-robots-robots'), $this->_data['meta-robots-robots']);
		$this->assertEquals($metaData->read('map-robots-robots'), $this->_data['map-robots-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataRedis()
	{
		if (!extension_loaded('redis')) {
			$this->markTestSkipped('Warning: redis extension is not loaded');
			return ;
		}

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Redis(array(
				'host' => 'localhost',
				'port' => 6379,
				'prefix' => 'my-local-app',
				'lifetime' => 60
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals($metaData->read('meta-robots-robots'), $this->_data['meta-robots-robots']);
		$this->assertEquals($metaData->read('map-robots-robots'), $this->_data['map-robots-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataMongo()
	{
		if (!extension_loaded('mongo')) {
			$this->markTestSkipped('Warning: mongo extension is not loaded');
			return ;
		}

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Mongo(array(
				'mongo' => new MongoClient(),
				'db' => 'phalcon_test',
				'collection' => 'caches',
				'lifetime' => 60,
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals($metaData->read('meta-robots-robots'), $this->_data['meta-robots-robots']);
		$this->assertEquals($metaData->read('map-robots-robots'), $this->_data['map-robots-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataCache()
	{
		if (!extension_loaded('mongo')) {
			$this->markTestSkipped('Warning: mongo extension is not loaded');
			return ;
		}

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('mycache', function(){
			$frontCache = new Phalcon\Cache\Frontend\Output(array(
				'lifetime' => 60
			));

			$cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
				'server' => 'mongodb://localhost',
				'db' => 'phalcon_test',
				'collection' => 'caches'
			));

			return $cache;
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Cache(array(
				'service' => 'mycache'
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals($metaData->read('meta-robots-robots'), $this->_data['meta-robots-robots']);
		$this->assertEquals($metaData->read('map-robots-robots'), $this->_data['map-robots-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}
}
