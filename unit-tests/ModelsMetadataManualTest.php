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

class ModelsMetadataManualTest extends PHPUnit_Framework_TestCase
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
		if (file_exists('unit-tests/models/' . $className . '.php')) {
			require 'unit-tests/models/' . $className . '.php';
		}
	}

	public function testMetadataManual()
	{

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$metaData = $di->getShared('modelsMetadata');

		$robotto = new Robotto($di);

		//Robots
		$pAttributes = array(
			0 => 'id',
			1 => 'name',
			2 => 'type',
			3 => 'year'
		);

		$attributes = $metaData->getAttributes($robotto);
		$this->assertEquals($attributes, $pAttributes);

		$ppkAttributes = array(
			0 => 'id'
		);

		$pkAttributes = $metaData->getPrimaryKeyAttributes($robotto);
		$this->assertEquals($ppkAttributes, $pkAttributes);

		$pnpkAttributes = array(
			0 => 'name',
			1 => 'type',
			2 => 'year'
		);

		$npkAttributes = $metaData->getNonPrimaryKeyAttributes($robotto);
		$this->assertEquals($pnpkAttributes, $npkAttributes);

		$this->assertEquals($metaData->getIdentityField($robotto), 'id');
	}
}
