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

class ModelsMetadataStrategyTest extends TestCase
{
	protected $_expectedMeta = array(
		0 => array(
			0 => 'id',
			1 => 'name',
			2 => 'type',
			3 => 'year',
			4 => 'datetime',
			5 => 'deleted',
			6 => 'text',
		),
		1 => array(
			0 => 'id',
		),
		2 => array(
			0 => 'name',
			1 => 'type',
			2 => 'year',
			3 => 'datetime',
			4 => 'deleted',
			5 => 'text'
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
			'deleted' => 4,
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
			'deleted' => 2,
			'text' => 2
		),
		10 => array(),
		11 => array(),
		12 => array(
			'type' => 'mechanical',
			'year' => 1900,
			'deleted' => null
		),
		13 => array()
	);

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
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
	}

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di['modelsManager'] = function() {
			return new Phalcon\Mvc\Model\Manager();
		};

		$di['db'] = function() {
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		};

		$di['annotations'] = function() {
			return new Phalcon\Annotations\Adapter\Memory();
		};

		return $di;
	}

	public function testMetadataDatabaseIntrospection()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di['modelsMetadata'] = function() {
			$metaData = new Phalcon\Mvc\Model\Metadata\Memory();
			$metaData->setStrategy(new Phalcon\Mvc\Model\MetaData\Strategy\Introspection());
			return $metaData;
		};

		$metaData = $di['modelsMetadata'];

		$robots = new Robots($di);

		$meta = $metaData->readMetaData($robots);
		$this->assertEquals($meta, $this->_expectedMeta);

		$meta = $metaData->readMetaData($robots);
		$this->assertEquals($meta, $this->_expectedMeta);
	}

	public function testMetadataAnnotations()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_getDI();

		$di['modelsMetadata'] = function(){
			$metaData = new Phalcon\Mvc\Model\Metadata\Memory();
			$metaData->setStrategy(new Phalcon\Mvc\Model\MetaData\Strategy\Annotations());
			return $metaData;
		};

		$metaData = $di['modelsMetadata'];

		$robots = new Boutique\Robots();

		$meta = $metaData->readMetaData($robots);
		$this->assertEquals($meta, $this->_expectedMeta);

		$meta = $metaData->readMetaData($robots);
		$this->assertEquals($meta, $this->_expectedMeta);
	}
}
