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

class CollectionsTest extends PHPUnit_Framework_TestCase
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
		if (file_exists('unit-tests/collections/' . $className . '.php')) {
			require 'unit-tests/collections/' . $className . '.php';
		}
	}

	public function testCollections()
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

		$songs = Songs::find();
		$this->assertTrue(is_array($songs));

		foreach($songs as $song){
			$this->assertTrue($song->delete());
		}

		$song = new Songs();
		$song->artist = 'Radiohead';
		$song->name = 'Lotus Flower';
		$success = $song->save();
		$this->assertTrue($success);
		$this->assertInstanceOf('MongoId', $song->_id);
		$firstSongId = $song->_id;

		$songs = Songs::find();
		$this->assertTrue(is_array($songs));
		$this->assertEquals(count($songs), 1);
		$this->assertEquals($songs[0]->name, 'Lotus Flower');
		$this->assertEquals($songs[0]->artist, 'Radiohead');

		$song = new Songs();
		$song->artist = 'Massive Attack';
		$song->name = 'Teardrop';
		$success = $song->save();
		$this->assertTrue($success);
		$this->assertInstanceOf('MongoId', $song->_id);
		$this->assertNotEquals((string) $firstSongId->{'$id'}, (string) $song->_id->{'$id'});
		$secondSongId = $song->_id;

		$songs = Songs::find();
		$this->assertTrue(is_array($songs));
		$this->assertEquals(count($songs), 2);
		$this->assertEquals($songs[0]->name, 'Lotus Flower');
		$this->assertEquals($songs[0]->artist, 'Radiohead');
		$this->assertEquals($songs[1]->name, 'Teardrop');
		$this->assertEquals($songs[1]->artist, 'Massive Attack');

		$song = new Songs();
		$song->artist = 'Massive Attack';
		$song->name = 'Paradise Circus';
		$success = $song->save();
		$this->assertTrue($success);
		$this->assertInstanceOf('MongoId', $song->_id);
		$this->assertNotEquals((string) $firstSongId->{'$id'}, (string) $song->_id->{'$id'});
		$this->assertNotEquals((string) $secondSongId->{'$id'}, (string) $song->_id->{'$id'});

		$songs = Songs::find();
		$this->assertTrue(is_array($songs));
		$this->assertEquals(count($songs), 3);

		$song = Songs::findFirst();
		$this->assertInstanceOf('Songs', $song);
		$this->assertEquals($song->name, 'Lotus Flower');
		$this->assertEquals($song->artist, 'Radiohead');

		$song = Songs::findFirst(array(array('artist' => 'Massive Attack')));
		$this->assertInstanceOf('Songs', $song);
		$this->assertEquals($song->artist, 'Massive Attack');

		$song = Songs::findFirst(array('conditions' => array('artist' => 'Massive Attack')));
		$this->assertInstanceOf('Songs', $song);
		$this->assertEquals($song->artist, 'Massive Attack');

		$song = Songs::findFirst(array('conditions' => array('name' => 'Paradise Circus')));
		$this->assertInstanceOf('Songs', $song);
		$this->assertEquals($song->name, 'Paradise Circus');

		//No results
		$song = Songs::findFirst(array(array('artist' => 'Lana')));
		$this->assertFalse($song);

		$song = Songs::findFirst(array('conditions' => array('artist' => 'Lana')));
		$this->assertFalse($song);

		$song = Songs::findFirst(array(array('artist' => 'Lana')));
		$this->assertFalse($song);

		//Passing parameters to find
		$songs = Songs::find(array(
			array('artist' => 'Massive Attack')
		));
		$this->assertTrue(is_array($songs));
		$this->assertEquals(count($songs), 2);
		$this->assertEquals($songs[0]->name, 'Teardrop');
		$this->assertEquals($songs[1]->name, 'Paradise Circus');

		$songs = Songs::find(array(
			'conditions' => array('artist' => 'Massive Attack')
		));
		$this->assertTrue(is_array($songs));
		$this->assertEquals(count($songs), 2);
		$this->assertEquals($songs[0]->name, 'Teardrop');
		$this->assertEquals($songs[1]->name, 'Paradise Circus');

		$songs = Songs::find(array(
			'conditions' => array('artist' => 'Massive Attack'),
			'sort' => array('name' => 1)
		));
		$this->assertTrue(is_array($songs));
		$this->assertEquals(count($songs), 2);
		$this->assertEquals($songs[0]->name, 'Paradise Circus');
		$this->assertEquals($songs[1]->name, 'Teardrop');

		$songs = Songs::find(array(
			'conditions' => array('artist' => 'Massive Attack'),
			'sort' => array('name' => 1),
			'limit' => 1
		));
		$this->assertTrue(is_array($songs));
		$this->assertEquals(count($songs), 1);
		$this->assertEquals($songs[0]->name, 'Paradise Circus');

		$songs = Songs::find(array(
			'conditions' => array('artist' => 'Massive Attack'),
			'limit' => 1
		));
		$this->assertTrue(is_array($songs));
		$this->assertEquals(count($songs), 1);
		$this->assertEquals($songs[0]->name, 'Teardrop');

		//Find first
		$song = Songs::findFirst(array(
			array('artist' => 'Massive Attack'),
		));
		$this->assertInstanceOf('Songs', $song);
		$this->assertEquals($song->name, 'Teardrop');

		$song = Songs::findFirst(array(
			'conditions' => array('artist' => 'Massive Attack'),
		));
		$this->assertInstanceOf('Songs', $song);
		$this->assertEquals($song->name, 'Teardrop');

		//Count
		$this->assertEquals(Songs::count(), 3);
		$this->assertEquals(Songs::count(array(
			array('artist' => 'Massive Attack')
		)), 2);

	}
}
