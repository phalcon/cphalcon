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

use Phalcon\Mvc\Model\Message as ModelMessage;

class CollectionsEventsTest extends PHPUnit_Framework_TestCase
{

	public function __construct()
	{
		spl_autoload_register(array($this, 'collectionsAutoloader'));
	}

	public function __destruct()
	{
		spl_autoload_unregister(array($this, 'collectionsAutoloader'));
	}

	public function collectionsAutoloader($className)
	{
		$className = str_replace('\\', '/', $className);
		if (file_exists('unit-tests/collections/' . $className . '.php')) {
			require 'unit-tests/collections/' . $className . '.php';
		}
	}

	public function testCollectionsEvents()
	{
		if (!class_exists('MongoClient')) {
			$this->markTestSkipped("MongoClient class does not exist, test skipped");
			return;
		}

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('mongo', function(){
			$mongo = new MongoClient();
			return $mongo->phalcon_test;
		});

		$di->set('collectionManager', function(){
			return new Phalcon\Mvc\Collection\Manager();
		});

		$songs = Store\Songs::find();
		$this->assertTrue(is_array($songs));

		foreach ($songs as $song){
			$this->assertTrue($song->delete());
		}

		$trace = array();

		$song = new Store\Songs();
		$song->trace = &$trace;
		$song->artist = 'Radiohead';
		$song->name = 'Lotus Flower';
		$this->assertTrue($song->save());

		$this->assertEquals($trace, array(
			'Store\\Songs::beforeValidation' => 1,
			'Store\\Songs::beforeValidationOnCreate' => 1,
			'Store\\Songs::afterValidationOnCreate' => 1,
			'Store\\Songs::afterValidation' => 1,
			'Store\\Songs::beforeSave' => 1,
			'Store\\Songs::beforeCreate' => 1,
			'Store\\Songs::afterCreate' => 1,
			'Store\\Songs::afterSave' => 1,
		));

		$this->assertTrue($song->save());

		$this->assertEquals($trace, array(
			'Store\\Songs::beforeValidation' => 2,
			'Store\\Songs::beforeValidationOnCreate' => 1,
			'Store\\Songs::afterValidationOnCreate' => 1,
			'Store\\Songs::afterValidation' => 2,
			'Store\\Songs::beforeSave' => 2,
			'Store\\Songs::beforeCreate' => 1,
			'Store\\Songs::afterCreate' => 1,
			'Store\\Songs::afterSave' => 2,
			'Store\\Songs::afterValidationOnUpdate' => 1,
			'Store\\Songs::beforeUpdate' => 1,
			'Store\\Songs::afterUpdate' => 1,
		));

	}

}