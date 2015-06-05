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
				4 => 'datetime',
				5 => 'text'
			),
			1 => array(
				0 => 'id',
			),
			2 => array(
				0 => 'name',
				1 => 'type',
				2 => 'year',
				3 => 'datetime',
				4 => 'text'
			),
			3 => array(
				0 => 'id',
				1 => 'name',
				2 => 'type',
				3 => 'year',
				4 => 'datetime',
				5 => 'text'
			),
			4 => array(
				'id' => 0,
				'name' => 2,
				'type' => 2,
				'year' => 0,
				'datetime' => 4,
				'text' => 6
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
				'datetime' => 2,
				'text' => 2
			),
			10 => array(),
			11 => array(),
			12 => array(
				'type' => 'mechanical',
				'year' => 1900
			),
			13 => array(),
		),
		'map-robots' => array(
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
			require __DIR__ . '/models/' . $className . '.php';
		}
	}

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('db', function(){
			require __DIR__ . '/config.db.php';
			/** @var string $configMysql */
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		return $di;
	}

	public function testMetadataMemory()
	{
		require __DIR__ . '/config.db.php';
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

		require __DIR__ . '/config.db.php';
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
		require __DIR__ . '/config.db.php';
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
		$this->assertEquals(apc_fetch('$PMM$my-local-appmap-robots'), $this->_data['map-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataXcache()
	{
		require __DIR__ . '/config.db.php';
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
		$this->assertEquals(apc_fetch('$PMM$my-local-appmap-robots'), $this->_data['map-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}

	public function testMetadataFiles()
	{
		require __DIR__ . '/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Files(array(
				'metaDataDir' => __DIR__ . '/cache/',
			));
		});

		$metaData = $di->getShared('modelsMetadata');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();

		$this->assertEquals(require __DIR__ . '/cache/meta-robots-robots.php', $this->_data['meta-robots-robots']);
		$this->assertEquals(require __DIR__ . '/cache/map-robots.php', $this->_data['map-robots']);

		$this->assertFalse($metaData->isEmpty());

		$metaData->reset();
		$this->assertTrue($metaData->isEmpty());

		Robots::findFirst();
	}
}
