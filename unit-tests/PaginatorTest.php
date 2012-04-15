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

class PaginatorTest extends PHPUnit_Framework_TestCase {

	public function testModelPaginator(){

		$config = array(
			'adapter' => 'Mysql',
			'host' => '127.0.0.1',
			'username' => 'root',
			'password' => '',
			'name' => 'phalcon_test'
		);

		Phalcon_Db_Pool::setDefaultDescriptor($config);
		$this->assertTrue(Phalcon_Db_Pool::hasDefaultDescriptor());

		$modelManager = new Phalcon_Model_Manager();
		$modelManager->setModelsDir('unit-tests/models/');

		$personas = Personas::find();

		$paginator = Phalcon_Paginator::factory('Model', array(
 			'data' => $personas,
 			'limit' => 10,
 			'page' => 1
 		));
 		$this->assertEquals(get_class($paginator), 'Phalcon_Paginator_Adapter_Model');

 		//First Page
 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 10);

 		$this->assertEquals($page->before, 1);
 		$this->assertEquals($page->next, 2);
 		$this->assertEquals($page->last, 219);

 		$this->assertEquals($page->current, 1);
 		$this->assertEquals($page->total_pages, 219);

 		//Middle Page
 		$paginator->setCurrentPage(50);

 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 10);

 		$this->assertEquals($page->before, 49);
 		$this->assertEquals($page->next, 51);
 		$this->assertEquals($page->last, 219);

 		$this->assertEquals($page->current, 50);
 		$this->assertEquals($page->total_pages, 219);

 		//After Last Page
 		$paginator->setCurrentPage(250);

 		$page = $paginator->getPaginate();
 		$this->assertEquals(get_class($page), 'stdClass');

 		$this->assertEquals(count($page->items), 10);

 		$this->assertEquals($page->before, 1);
 		$this->assertEquals((int) $page->next, 219);
 		$this->assertEquals($page->last, 219);

 		$this->assertEquals($page->current, 1);
 		$this->assertEquals($page->total_pages, 219);

	}

	public function testArrayPaginator(){

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

		$paginator = Phalcon_Paginator::factory('Array', array(
 			'data' => $personas,
 			'limit' => 3,
 			'page' => 1
 		));
 		$this->assertEquals(get_class($paginator), 'Phalcon_Paginator_Adapter_Array');

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