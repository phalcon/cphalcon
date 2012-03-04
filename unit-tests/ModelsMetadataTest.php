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

	public function testMetadata(){

		$config = array(
			'adapter' => 'Mysql',
			'host' => '127.0.0.1',
			'username' => 'root',
			'password' => '',
			'name' => 'phalcon_test'
		);

		Phalcon_Db_Pool::setDefaultDescriptor($config);
		$this->assertTrue(Phalcon_Db_Pool::hasDefaultDescriptor());
		
		$modelManager = new Phalcon_Model_Manager();
		$modelManager->setModelsDir('unit-tests/models/');

		$Personas = $modelManager->getModel('Personas');
		$this->assertEquals(get_class($Personas), 'Personas');

		$connection = $Personas->getConnection();
		$this->assertEquals($connection, Phalcon_Db_Pool::getConnection());		

		$metaData = new Phalcon_Model_MetaData('Memory');

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

		$pdtAttributes = array(
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

		$dtAttributes = $metaData->getDataTypes($Personas);
		$this->assertEquals($dtAttributes, $pdtAttributes);

		$pndAttributes = array(
			'tipo_documento_id' => true,
			'ciudad_id' => true,
			'cupo' => true,
		);
		$ndAttributes = $metaData->getDataTypesNumeric($Personas);
		$this->assertEquals($ndAttributes, $pndAttributes);

		//GC
		gc_collect_cycles();

	}

}
