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

class ModelsResultsetCacheStaticTest extends PHPUnit_Framework_TestCase
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
		$className = str_replace('\\', '/', $className);
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
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

	public function testOverrideStaticCache()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di['db'] = function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		};

		$di['modelsManager'] = function(){
			return new Phalcon\Mvc\Model\Manager();
		};

		$di['modelsMetadata'] = function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		};

		$di['modelsCache'] = function(){
			$frontCache = new Phalcon\Cache\Frontend\Data();
			return new Phalcon\Cache\Backend\File($frontCache, array(
				'cacheDir' => 'unit-tests/cache/'
			));
		};

		$robot = Cacheable\Robots::findFirst(2);
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

		$robot = Cacheable\Robots::findFirst(2);
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

		$robot = Cacheable\Robots::findFirst(array('id = 2'));
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

		$robot = Cacheable\Robots::findFirst(array('id = 2'));
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

		$robot = Cacheable\Robots::findFirst(array('order' => 'id DESC'));
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

		$robot = Cacheable\Robots::findFirst(array('order' => 'id DESC'));
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

		$robot = Cacheable\Robots::findFirst(1);
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

		$robotParts = $robot->getRobotsParts();
		$this->assertEquals(get_class($robotParts), 'Phalcon\Mvc\Model\Resultset\Simple');

		$robotParts = $robot->getRobotsParts();
		$this->assertEquals(get_class($robotParts), 'Phalcon\Mvc\Model\Resultset\Simple');

		$part = $robotParts[0]->getParts();
		$this->assertEquals(get_class($part), 'Cacheable\Parts');

		$part = $robotParts[0]->getParts();
		$this->assertEquals(get_class($part), 'Cacheable\Parts');

		$robot = $robotParts[0]->getRobots();
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

		$robot = $robotParts[0]->getRobots();
		$this->assertEquals(get_class($robot), 'Cacheable\Robots');

	}


}
