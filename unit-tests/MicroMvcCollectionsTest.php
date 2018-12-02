<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use PHPUnit\Framework\TestCase;

class PersonasController
{
	protected $_entered = 0;

	public function index()
	{
		$this->_entered++;
	}

	public function edit($number)
	{
		$this->_entered+=$number;
	}

	public function getEntered()
	{
		return $this->_entered;
	}
}

class PersonasLazyController
{
	static protected $_entered = 0;

	public function index()
	{
		self::$_entered++;
	}

	public function edit($number)
	{
		self::$_entered+=$number;
	}

	public static function getEntered()
	{
		return self::$_entered;
	}
}

class MicroMvcCollectionsTest extends TestCase
{
	public function testMicroCollections()
	{

		$app = new Phalcon\Mvc\Micro();

		$collection = new Phalcon\Mvc\Micro\Collection();

		$controller = new PersonasController();

		$collection->setHandler($controller);

		$collection->map('/', 'index', 'index_route');

		$collection->map('/edit/{number}', 'edit', 'edit_route');

		$app->mount($collection);

		$app->handle('/');
		$this->assertEquals(1, $controller->getEntered());
		$this->assertEquals('index_route', $app->getRouter()->getMatchedRoute()->getName());

		$app->handle('/edit/100');
		$this->assertEquals(101, $controller->getEntered());
		$this->assertEquals('edit_route', $app->getRouter()->getMatchedRoute()->getName());
	}

	public function testMicroCollectionsPrefixed()
	{

		$app = new Phalcon\Mvc\Micro();

		$collection = new Phalcon\Mvc\Micro\Collection();

		$collection->setPrefix('/personas');

		$controller = new PersonasController();

		$collection->setHandler($controller);

		$collection->map('/', 'index');

		$collection->map('/edit/{number}', 'edit');

		$app->mount($collection);

		$app->handle('/personas');
		$this->assertEquals($controller->getEntered(), 1);

		$app->handle('/personas/edit/100');
		$this->assertEquals($controller->getEntered(), 101);

	}

	public function testMicroCollectionsLazy()
	{

		$app = new Phalcon\Mvc\Micro();

		$collection = new Phalcon\Mvc\Micro\Collection();

		$collection->setHandler('PersonasLazyController', true);

		$collection->map('/', 'index');

		$collection->map('/edit/{number}', 'edit');

		$app->mount($collection);

		$app->handle('/');
		$this->assertEquals(PersonasLazyController::getEntered(), 1);

		$app->handle('/edit/100');
		$this->assertEquals(PersonasLazyController::getEntered(), 101);

	}

}
