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

}
