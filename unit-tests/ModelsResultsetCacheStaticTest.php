<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use PHPUnit\Framework\TestCase;

class ModelsResultsetCacheStaticTest extends TestCase
{
	public function setUp()
	{
		spl_autoload_register(array($this, 'modelsAutoloader'));

        $iterator = new DirectoryIterator('unit-tests/cache/');
        foreach ($iterator as $item) {
            if (!$item->isDir()) {
                unlink($item->getPathname());
            }
        }
	}

	public function tearDown()
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
