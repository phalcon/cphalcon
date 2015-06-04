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

class CollectionsBehaviorsTest extends PHPUnit_Framework_TestCase
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

	public function testBehaviors()
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

		//Timestampable
		$subscriber = new Subs();
		$subscriber->email = 'some@some.com';
		$subscriber->status = 'I';
		$this->assertTrue($subscriber->save());
		$this->assertEquals(preg_match('/[0-9]{4}-[0-9]{2}-[0-9]{2}/', $subscriber->created_at), 1);

		//Softdelete
		$subscriber = Subs::findFirst();
		$this->assertTrue($subscriber->delete());
		$this->assertEquals($subscriber->status, 'D');
		$this->assertEquals(Subs::count(), 1);
	}
}
