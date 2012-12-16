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

class PaginatorTest extends PHPUnit_Framework_TestCase
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

	protected function _loadDI()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});
	}

	public function testModelPaginator()
	{
		$this->_loadDI();

		$personnes = Personnes::find();

		$paginator = new Phalcon\Paginator\Adapter\Model(array(
			'data' => $personnes,
			'limit' => 10,
			'page' => 1
		));

		//First Page
		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 10);

		$this->assertEquals($page->before, 1);
		$this->assertEquals($page->next, 2);
		$this->assertEquals($page->last, 218);

		$this->assertEquals($page->current, 1);
		$this->assertEquals($page->total_pages, 218);

		//Middle Page
		$paginator->setCurrentPage(50);

		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 10);

		$this->assertEquals($page->before, 49);
		$this->assertEquals($page->next, 51);
		$this->assertEquals($page->last, 218);

		$this->assertEquals($page->current, 50);
		$this->assertEquals($page->total_pages, 218);

		//Last Page
		/*$paginator->setCurrentPage(219);

		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 1);

		$this->assertEquals($page->before, 218);
		$this->assertEquals((int) $page->next, 219);
		$this->assertEquals($page->last, 219);

		$this->assertEquals($page->current, 219);
		$this->assertEquals($page->total_pages, 219);*/

	}

	public function testModelPaginatorBind()
	{
		$this->_loadDI();

		$personnes = Personnes::find(array(
			"conditions" => "cedula >=:d1: AND cedula>=:d2: ",
			"bind" => array("d1" => '1', "d2" => "5"),
			"order" => "cedula, nombres",
			"limit" => "33"
		));

		$paginator = new Phalcon\Paginator\Adapter\Model(array(
			'data' => $personnes,
			'limit' => 10,
			'page' => 1
		));

		//First Page
		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 10);

		$this->assertEquals($page->before, 1);
		$this->assertEquals($page->next, 2);
		$this->assertEquals($page->last, 3);

		$this->assertEquals($page->current, 1);
		$this->assertEquals($page->total_pages, 3);
	}

	public function testArrayPaginator()
	{

		$personas = array(
			0 => array(
				'name' => 'PETER'
			),
			1 => array(
				'name' => 'PETER'
			),
			2 => array(
				'name' => 'PETER'
			),
			3 => array(
				'name' => 'PETER'
			),
			4 => array(
				'name' => 'PETER'
			),
			5 => array(
				'name' => 'PETER'
			),
			6 => array(
				'name' => 'PETER'
			),
			7 => array(
				'name' => 'PETER'
			),
			8 => array(
				'name' => 'PETER'
			),
			9 => array(
				'name' => 'PETER'
			),
			10 => array(
				'name' => 'PETER'
			),
			11 => array(
				'name' => 'PETER'
			),
			12 => array(
				'name' => 'PETER'
			),
			13 => array(
				'name' => 'PETER'
			),
			14 => array(
				'name' => 'PETER'
			),
			15 => array(
				'name' => 'PETER'
			),
			16 => array(
				'name' => 'PETER'
			),
			17 => array(
				'name' => 'PETER'
			)
		);

		$paginator = new Phalcon\Paginator\Adapter\NativeArray(array(
			'data' => $personas,
			'limit' => 3,
			'page' => 1
		));

		//First Page
		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 3);

		$this->assertEquals($page->before, 1);
		$this->assertEquals($page->next, 2);
		$this->assertEquals($page->last, 6);

		$this->assertEquals($page->current, 1);
		$this->assertEquals($page->total_pages, 6);

		//Middle Page
		$paginator->setCurrentPage(4);

		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 3);

		$this->assertEquals($page->before, 3);
		$this->assertEquals($page->next, 5);
		$this->assertEquals($page->last, 6);

		$this->assertEquals($page->current, 4);
		$this->assertEquals($page->total_pages, 6);

	}

}