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

class CollectionsSerializeTest extends PHPUnit_Framework_TestCase
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
		if (file_exists('unit-tests/collections/'.$className.'.php')) {
			require 'unit-tests/collections/'.$className.'.php';
		}
	}

	public function testCollectionsEvents()
	{
		if (!class_exists('Mongo')) {
			$this->markTestSkipped("Mongo class does not exist, test skipped");
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

		foreach($songs as $song){
			$this->assertTrue($song->delete());
		}

		$trace = array();

		$song = new Songs();
		$song->artist = 'Radiohead';
		$song->name = 'Lotus Flower';
		$this->assertTrue($song->save());

		$serialized = serialize($song);
		$song = unserialize($serialized);

		$this->assertEquals($song->artist, 'Radiohead');
		$this->assertEquals($song->name, 'Lotus Flower');
		$this->assertTrue($song->save());

		$song = Songs::findFirst();

		$serialized = serialize($song);
		$song = unserialize($serialized);

		$this->assertEquals($song->artist, 'Radiohead');
		$this->assertEquals($song->name, 'Lotus Flower');
		$this->assertTrue($song->save());

		$song = new Songs();
		$song->artist = 'Massive Attack';
		$song->name = 'Paradise Circus';
		$this->assertTrue($song->save());

		$songs = Songs::find();
		$this->assertEquals(count($songs), 2);

		$serialized = serialize($songs);
		$songs = unserialize($serialized);

		$this->assertEquals(count($songs), 2);
	}

}