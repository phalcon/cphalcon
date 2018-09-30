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

class ModelsMultipleSourcesTest extends TestCase
{
	public function setUp()
	{
		spl_autoload_register(array($this, 'modelsAutoloader'));
	}

	public function tearDown()
	{
		spl_autoload_unregister(array($this, 'modelsAutoloader'));
	}

	public function modelsAutoloader($className)
	{
		$className = str_replace('\\', '/', $className);
		if (file_exists('unit-tests/models/' . $className . '.php')) {
			require 'unit-tests/models/' . $className . '.php';
		}
	}

	protected function _prepareDI()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function() {
			return new Phalcon\Mvc\Model\Manager();
		}, true);

		$di->set('modelsMetadata', function() {
			return new Phalcon\Mvc\Model\Metadata\Memory();
		}, true);

		$di->set('db', function() {
			throw new Exception('Using default database source');
		}, true);

		$di->set('dbOne', function() {
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		$di->set('dbTwo', function() {
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);
	}

	public function testSourcesStatic()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->marktestSkipped('Test skipped');
			return;
		}

		$this->_prepareDI();

		$robot = Store\Robots::findFirst();
		$this->assertTrue(is_object($robot));
		$this->assertTrue($robot->save());

		$robotParts = $robot->getRobotParts();
		$this->assertTrue(is_object($robotParts));

		foreach ($robotParts as $robotPart) {
			$this->assertTrue(is_object($robotPart->getRobot()));
			$this->assertTrue(is_object($robotPart->getPart()));
		}
	}

	public function ytestSourcesInstance()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->marktestSkipped('Test skipped');
			return;
		}

		$this->_prepareDI();

		$robot = new Store\Robots();
		$this->assertFalse($robot->save());
	}

}
