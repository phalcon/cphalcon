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

class ModelsMetadataTest extends PHPUnit_Framework_TestCase {

	private $_pdtAttributesMysql = array(
		'cedula' => 'char(15)',
		'tipo_documento_id' => 'int(3) unsigned',
		'nombres' => 'varchar(100)',
		'telefono' => 'varchar(20)',
		'direccion' => 'varchar(100)',
		'email' => 'varchar(50)',
		'fecha_nacimiento' => 'date',
		'ciudad_id' => 'int(10) unsigned',
		'creado_at' => 'date',
		'cupo' => 'decimal(16,2)',
		'estado' => 'enum(\'A\',\'I\',\'X\')',
	);

	private $_pdtAttributesPostgresql = array(
		'cedula' => 'character(15)',
		'tipo_documento_id' => 'integer',
		'nombres' => 'character varying(100)',
		'telefono' => 'character varying(20)',
		'direccion' => 'character varying(100)',
		'email' => 'character varying(50)',
		'fecha_nacimiento' => 'date',
		'ciudad_id' => 'integer',
		'creado_at' => 'date',
		'cupo' => 'numeric(16,2)',
		'estado' => 'character(1)',
	);

	protected function _createManagerMysql(){

		require 'unit-tests/config.db.php';

		Phalcon\Db\Pool::reset();

		Phalcon\Db\Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon\Db\Pool::hasDefaultDescriptor());

		$manager = new Phalcon\Model\Manager();
		$manager->setModelsDir('unit-tests/models/');

		return $manager;
	}

	protected function _createManagerPostgresql(){

		require 'unit-tests/config.db.php';

		Phalcon\Db\Pool::reset();

		Phalcon\Db\Pool::setDefaultDescriptor($configPostgresql);
		$this->assertTrue(Phalcon\Db\Pool::hasDefaultDescriptor());

		$manager = new Phalcon\Model\Manager();
		$manager->setModelsDir('unit-tests/models/');

		return $manager;
	}

	public function testMetadataMysql(){

		$manager = $this->_createManagerMysql();

		$metaData = $manager->getMetaData();

		$this->_executeTests($manager, $metaData, $this->_pdtAttributesMysql);

	}

	public function testMetadataMysql2(){

		$manager = $this->_createManagerMysql();

		$Personas = $manager->getModel('Personas');
		$this->assertEquals(get_class($Personas), 'Personas');

		$connection = $Personas->getConnection();
		$this->assertEquals($connection, Phalcon\Db\Pool::getConnection());

		$metaData = $manager->getMetaData();

		$dtAttributes = $metaData->getDataTypes($Personas);
		$this->assertEquals($dtAttributes, $this->_pdtAttributesMysql);

	}

	public function testMetadataPostgresql(){

		$manager = $this->_createManagerPostgresql();

		$metaData = $manager->getMetaData();

		$this->_executeTests($manager, $metaData, $this->_pdtAttributesPostgresql);

	}

	protected function _executeTests($manager, $metaData, $dataTypes){

		$Personas = $manager->getModel('Personas');
		$this->assertEquals(get_class($Personas), 'Personas');

		$connection = $Personas->getConnection();
		$this->assertEquals($connection, Phalcon\Db\Pool::getConnection());

		$pAttributes = array(
			0 => 'cedula',
			1 => 'tipo_documento_id',
			2 => 'nombres',
			3 => 'telefono',
			4 => 'direccion',
			5 => 'email',
			6 => 'fecha_nacimiento',
			7 => 'ciudad_id',
			8 => 'creado_at',
			9 => 'cupo',
			10 => 'estado',
		);

		$attributes = $metaData->getAttributes($Personas);
		$this->assertEquals($attributes, $pAttributes);

		$ppkAttributes = array(
			0 => 'cedula'
		);

		$pkAttributes = $metaData->getPrimaryKeyAttributes($Personas);
		$this->assertEquals($ppkAttributes, $pkAttributes);

		$pnpkAttributes = array(
			0 => 'tipo_documento_id',
			1 => 'nombres',
			2 => 'telefono',
			3 => 'direccion',
			4 => 'email',
			5 => 'fecha_nacimiento',
			6 => 'ciudad_id',
			7 => 'creado_at',
			8 => 'cupo',
			9 => 'estado',
		);

		$npkAttributes = $metaData->getNonPrimaryKeyAttributes($Personas);
		$this->assertEquals($pnpkAttributes, $npkAttributes);

		$pnnAttributes = array(
			0 => 'cedula',
			1 => 'tipo_documento_id',
			2 => 'nombres',
			3 => 'cupo',
			4 => 'estado'
		);

		$nnAttributes = $metaData->getNotNullAttributes($Personas);
		$this->assertEquals($nnAttributes, $pnnAttributes);

		$dtAttributes = $metaData->getDataTypes($Personas);
		$this->assertEquals($dtAttributes, $dataTypes);

		$pndAttributes = array(
			'tipo_documento_id' => true,
			'ciudad_id' => true,
			'cupo' => true,
		);
		$ndAttributes = $metaData->getDataTypesNumeric($Personas);
		$this->assertEquals($ndAttributes, $pndAttributes);
	}

}
