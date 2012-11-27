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

	public function _loadDI()
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

	}

	public function testModelBindPaginator()
	{

		$this->_loadDI();

		$personnes = Personnes::find(array(
			"conditions" => "cedula>=:c1: AND cedula>=:c2:",
			"bind" => array("c1" => '1', "c2" => "5"),
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
 		$this->assertEquals($page->last, 4);

 		$this->assertEquals($page->current, 1);
 		$this->assertEquals($page->total_pages, 4);

 		//Middle Page
 		$paginator->setCurrentPage(2);

 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 10);

 		$this->assertEquals($page->before, 1);
 		$this->assertEquals($page->next, 3);
 		$this->assertEquals($page->last, 4);

 		$this->assertEquals($page->current, 2);
 		$this->assertEquals($page->total_pages, 4);

 	}

	public function testModelPaginator8()
	{

		$this->_loadDI();

		$personnes = Personnes::find(array(
			"limit" => "8"
        ));

		$paginator = new Phalcon\Paginator\Adapter\Model(array(
 			'data' => $personnes,
 			'limit' => 5,
 			'page' => 1
 		));

 		//First Page
 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 5);

 		$this->assertEquals($page->before, 1);
 		$this->assertEquals($page->next, 2);
 		$this->assertEquals($page->last, 2);

 		$this->assertEquals($page->current, 1);
 		$this->assertEquals($page->total_pages, 2);

 		//Middle Page
 		$paginator->setCurrentPage(2);

 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 3);

 		$this->assertEquals($page->before, 1);
 		$this->assertEquals($page->next, 2);
 		$this->assertEquals($page->last, 2);

 		$this->assertEquals($page->current, 2);
 		$this->assertEquals($page->total_pages, 2);

 	}

 	public function testModelPaginator9()
	{

		$this->_loadDI();

		$personnes = Personnes::find(array(
			"limit" => "9"
        ));

		$paginator = new Phalcon\Paginator\Adapter\Model(array(
 			'data' => $personnes,
 			'limit' => 5,
 			'page' => 1
 		));

 		//First Page
 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 5);

 		$this->assertEquals($page->before, 1);
 		$this->assertEquals($page->next, 2);
 		$this->assertEquals($page->last, 2);

 		$this->assertEquals($page->current, 1);
 		$this->assertEquals($page->total_pages, 2);

 		//Middle Page
 		$paginator->setCurrentPage(2);

 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 4);

 		$this->assertEquals($page->before, 1);
 		$this->assertEquals($page->next, 2);
 		$this->assertEquals($page->last, 2);

 		$this->assertEquals($page->current, 2);
 		$this->assertEquals($page->total_pages, 2);

 	}

 	public function testModelPaginator123()
	{

		$this->_loadDI();

		$personnes = Personnes::find(array(
			"limit" => "123"
        ));

		$paginator = new Phalcon\Paginator\Adapter\Model(array(
 			'data' => $personnes,
 			'limit' => 9,
 			'page' => 1
 		));

 		//First Page
 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 9);

 		$this->assertEquals($page->before, 1);
 		$this->assertEquals($page->next, 2);
 		$this->assertEquals($page->last, 14);

 		$this->assertEquals($page->current, 1);
 		$this->assertEquals($page->total_pages, 14);

 		//Middle Page
 		$paginator->setCurrentPage(7);

 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 9);

 		$this->assertEquals($page->before, 6);
 		$this->assertEquals($page->next, 8);
 		$this->assertEquals($page->last, 14);

 		$this->assertEquals($page->current, 7);
 		$this->assertEquals($page->total_pages, 14);

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