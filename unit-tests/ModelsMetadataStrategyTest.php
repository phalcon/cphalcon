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

class ModelsMetadataStrategyTest extends PHPUnit_Framework_TestCase
{

	protected $_expectedMeta = array(
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
		),
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

		$di->set('modelsQuery', 'Phalcon\Mvc\Model\Query');
		$di->set('modelsQueryBuilder', 'Phalcon\Mvc\Model\Query\Builder');
		$di->set('modelsCriteria', 'Phalcon\\Mvc\\Model\\Criteria');

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

		// Issue 2954
		$robot = Boutique\Robotters::findFirst();
		$code = $robot->code;
		$serialized = serialize($robot);
		$unserialized = unserialize($serialized);
		$this->assertEquals($code, $unserialized->code);
	}

}
