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

class ModelsBehaviorsTest extends PHPUnit_Framework_TestCase
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
		$className = str_replace('\\', '/', $className);
		if (file_exists('unit-tests/models/' . $className . '.php')) {
			require 'unit-tests/models/' . $className . '.php';
		}
	}

	protected function _prepareDI()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function() {
			return new Phalcon\Mvc\Model\Manager();
		}, true);

		$di->set('db', function() {
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

	}

	public function testBehaviorsTimestampable()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Test skipped");
			return;
		}

		$this->_prepareDI();

		$subscriber = new News\Subscribers();
		$subscriber->email = 'some@some.com';
		$subscriber->status = 'I';
		$this->assertTrue($subscriber->save());
		$this->assertEquals(preg_match('/[0-9]{4}-[0-9]{2}-[0-9]{2}/', $subscriber->created_at), 1);
	}

	public function testBehaviorsSoftDelete()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Test skipped");
			return;
		}

		$this->_prepareDI();

		$number = News\Subscribers::count();

		$subscriber = News\Subscribers::findFirst();
		$this->assertTrue($subscriber->delete());
		$this->assertEquals($subscriber->status, 'D');
		$this->assertEquals(News\Subscribers::count(), $number);
	}

	public function testBehaviorsNestedSet()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Test skipped");
			return;
		}

		$this->_prepareDI();

		$cars = new Categories();
		$cars->title='Cars';
		$this->assertTrue($cars->saveNode());

		$phones = new Categories();
		$phones->title='Mobile phones';
		$this->assertTrue($phones->saveNode());

		$ford = new Categories();
		$ford->title='Ford';
		$this->assertTrue($ford->appendTo($cars));

		$mercedes = new Categories();
		$mercedes->title='Mercedes';
		$this->assertTrue($mercedes->insertBefore($ford));

		$audi = new Categories();
		$audi->title='Audi';
		$this->assertTrue($audi->prependTo($cars));

		$samsung = new Categories();
		$samsung->title='Samsung';
		$this->assertTrue($samsung->appendTo($phones));

		$motorola = new Categories();
		$motorola->title='Motorola';
		$this->assertTrue($motorola->insertAfter($samsung));

		$iphone = new Categories();
		$iphone->title='iPhone';
		$this->assertTrue($iphone->insertBefore($samsung));

		$data = array(
			array(
				"id" => 1,
				"root" => 1,
				"lft" => 1,
				"rgt" => 8,
				"lvl" => 1,
				"title" => "Cars"
			),
			array(
				"id" => 5,
				"root" => 1,
				"lft" => 2,
				"rgt" => 3,
				"lvl" => 2,
				"title" => "Audi"
			),
			array(
				"id" => 4,
				"root" => 1,
				"lft" => 4,
				"rgt" => 5,
				"lvl" => 2,
				"title" => "Mercedes",
			),
			array(
				"id" => 3,
				"root" => 1,
				"lft" => 6,
				"rgt" => 7,
				"lvl" => 2,
				"title" => "Ford",
			),
			array(
				"id" => 2,
				"root" => 2,
				"lft" => 1,
				"rgt" => 8,
				"lvl" => 1,
				"title" => "Mobile phones",
			),
			array(
				"id" => 8,
				"root" => 2,
				"lft" => 2,
				"rgt" => 3,
				"lvl" => 2,
				"title" => "iPhone",
			),
			array(
				"id" => 6,
				"root" => 2,
				"lft" => 4,
				"rgt" => 5,
				"lvl" => 2,
				"title" => "Samsung",
			),
			array(
				"id" => 7,
				"root" => 2,
				"lft" => 6,
				"rgt" => 7,
				"lvl" => 2,
				"title" => "Motorola",
			)
		);

		$categories = Categories::find(array('order'=> 'root, lft'));
		$this->assertEquals($data, $categories->toArray());
	}

}
