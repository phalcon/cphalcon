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

class ModelsMetadataAdaptersTest extends PHPUnit_Framework_TestCase {

	private $_manager;

	private $_data = array(
		'phalcon_testrobots' => array(
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
				'id' => 'int(10) unsigned',
				'name' => 'varchar(70)',
				'type' => 'varchar(32)',
				'year' => 'int(11)',
			),
			5 => array(
				'id' => true,
				'year' => true,
			),
			8 => 'id',
		),
	);

	public function setUp(){

		require 'unit-tests/config.db.php';

		Phalcon_Db_Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon_Db_Pool::hasDefaultDescriptor());

		$this->_manager = new Phalcon_Model_Manager();
		$this->_manager->setModelsDir('unit-tests/models/');
	}

	public function testMetadataMemory(){

		$manager = $this->_manager;

		$memoryMetaData = new Phalcon_Model_Metadata('Memory');

		$manager->setMetaData($memoryMetaData);

		$metaData = $manager->getMetaData();
		$this->assertEquals(get_class($metaData), 'Phalcon_Model_MetaData');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		Robots::findFirst();

		$this->assertFalse($metaData->isEmpty());

	}

	public function testMetadataSession(){

		$manager = $this->_manager;

		@session_start();

		$config = new stdClass();
		$config->sufix = 'my-local-app';

		$sessionMetaData = new Phalcon_Model_Metadata('Session', $config);

		$manager->setMetaData($sessionMetaData);

		$metaData = $manager->getMetaData();
		$this->assertEquals(get_class($metaData), 'Phalcon_Model_MetaData');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		Robots::findFirst();

		$metaData->storeMetaData();

		$expectedSession = array(
			'$PMM$my-local-app' => $this->_data
		);

		$this->assertEquals($_SESSION, $expectedSession);

		$this->assertFalse($metaData->isEmpty());

	}

	public function testMetadataApc(){

		apc_delete('$PMM$my-local-app');

		$manager = $this->_manager;

		$config = new stdClass();
		$config->sufix = 'my-local-app';
		$config->lifetime = 60;

		$apcMetaData = new Phalcon_Model_Metadata('Apc', $config);

		$manager->setMetaData($apcMetaData);

		$metaData = $manager->getMetaData();
		$this->assertEquals(get_class($metaData), 'Phalcon_Model_MetaData');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		Robots::findFirst();

		$metaData->storeMetaData();

		$this->assertEquals(apc_fetch('$PMM$my-local-app'), $this->_data);

		$this->assertFalse($metaData->isEmpty());

	}

	public function testMetadataConfig(){

		apc_delete('$PMM$my-local-app');

		$options = new stdClass();
		$options->metadata = new stdClass();
		$options->metadata->adapter = 'Apc';
		$options->metadata->sufix = 'my-local-app';
		$options->metadata->lifetime = 60;

		$manager = new Phalcon_Model_Manager($options);

		$metaData = $manager->getMetaData();
		$this->assertEquals(get_class($metaData), 'Phalcon_Model_MetaData');

		$metaData->reset();

		$this->assertTrue($metaData->isEmpty());

		$success = $manager->load('Robots');
		$this->assertTrue($success);

		Robots::findFirst();

		$metaData->storeMetaData();

		$this->assertEquals(apc_fetch('$PMM$my-local-app'), $this->_data);

		$this->assertFalse($metaData->isEmpty());

	}

}
