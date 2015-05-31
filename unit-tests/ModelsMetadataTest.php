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

class ModelsMetadataTest extends PHPUnit_Framework_TestCase
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
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
	}

	protected function _getDI()
	{

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		return $di;
	}

	public function testMetadataMysql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		$this->_executeTests($di);

	}

	public function testMetadataPostgresql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		}, true);

		$this->_executeTests($di);
	}

	public function testMetadataSqlite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
		}, true);

		$this->_executeTests($di);
	}

	protected function _executeTests($di)
	{

		$metaData = $di->getShared('modelsMetadata');

		$personas = new Personas($di);

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

		$attributes = $metaData->getAttributes($personas);
		$this->assertEquals($attributes, $pAttributes);

		$ppkAttributes = array(
			0 => 'cedula'
		);

		$pkAttributes = $metaData->getPrimaryKeyAttributes($personas);
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

		$npkAttributes = $metaData->getNonPrimaryKeyAttributes($personas);
		$this->assertEquals($pnpkAttributes, $npkAttributes);

		$pnnAttributes = array(
			0 => 'cedula',
			1 => 'tipo_documento_id',
			2 => 'nombres',
			3 => 'cupo',
			4 => 'estado'
		);

		$nnAttributes = $metaData->getNotNullAttributes($personas);
		$this->assertEquals($nnAttributes, $pnnAttributes);

		$dataTypes = array(
			'cedula' => 5,
			'tipo_documento_id' => 0,
			'nombres' => 2,
			'telefono' => 2,
			'direccion' => 2,
			'email' => 2,
			'fecha_nacimiento' => 1,
			'ciudad_id' => 0,
			'creado_at' => 1,
			'cupo' => 3,
			'estado' => 5,
		);

		$dtAttributes = $metaData->getDataTypes($personas);
		$this->assertEquals($dtAttributes, $dataTypes);

		$pndAttributes = array(
			'tipo_documento_id' => true,
			'ciudad_id' => true,
			'cupo' => true,
		);
		$ndAttributes = $metaData->getDataTypesNumeric($personas);
		$this->assertEquals($ndAttributes, $pndAttributes);

		$bindTypes = array(
			'cedula' => 2,
			'tipo_documento_id' => 1,
			'nombres' => 2,
			'telefono' => 2,
			'direccion' => 2,
			'email' => 2,
			'fecha_nacimiento' => 2,
			'ciudad_id' => 1,
			'creado_at' => 2,
			'cupo' => 32,
			'estado' => 2,
		);

		$btAttributes = $metaData->getBindTypes($personas);
		$this->assertEquals($btAttributes, $bindTypes);

		$defValues = array(
			'nombres' => '',
			'telefono' => null,
			'direccion' => null,
			'email' => null,
			'fecha_nacimiento' => '1970-01-01',
			'ciudad_id' => '0',
			'creado_at' => null,
		);

		$modelDefValues = $metaData->getDefaultValues($personas);
		$this->assertEquals($defValues, $modelDefValues);

		$robots = new Robots($di);

		//Robots
		$pAttributes = array(
			0 => 'id',
			1 => 'name',
			2 => 'type',
			3 => 'year',
			4 => 'datetime',
			5 => 'text'
		);

		$attributes = $metaData->getAttributes($robots);
		$this->assertEquals($attributes, $pAttributes);

		$ppkAttributes = array(
			0 => 'id'
		);

		$pkAttributes = $metaData->getPrimaryKeyAttributes($robots);
		$this->assertEquals($ppkAttributes, $pkAttributes);

		$pnpkAttributes = array(
			0 => 'name',
			1 => 'type',
			2 => 'year',
			3 => 'datetime',
			4 => 'text'
		);

		$npkAttributes = $metaData->getNonPrimaryKeyAttributes($robots);
		$this->assertEquals($pnpkAttributes, $npkAttributes);

		$this->assertEquals($metaData->getIdentityField($robots), 'id');

		$defValues = array(
			'type' => 'mechanical',
			'year' => 1900
		);

		$modelDefValues = $metaData->getDefaultValues($robots);
		$this->assertEquals($defValues, $modelDefValues);
	}
}
