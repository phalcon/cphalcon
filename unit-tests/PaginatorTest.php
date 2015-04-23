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

use Phalcon\Logger\Adapter\File as FileLogger,
    Phalcon\Db\Adapter\Pdo\Mysql as DbAdapter,
    Phalcon\Events\Manager as EventsManager;

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
		if (file_exists('unit-tests/models/' . $className . '.php')) {
			require 'unit-tests/models/' . $className . '.php';
		}
	}

	protected function _loadDI()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function() {
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function() {
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$di->set('db', function() {
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		/*$di->set('db', function() {

		    $eventsManager = new EventsManager();

		    $logger = new FileLogger("debug.log");

		    //Listen all the database events
		    $eventsManager->attach('db', function($event, $connection) use ($logger) {
		        if ($event->getType() == 'beforeQuery') {
		            $logger->log($connection->getSQLStatement(), \Phalcon\Logger::INFO);
		        }
		    });

		    $connection = new DbAdapter(array(
		        "host" => "localhost",
		        "username" => "root",
		        "password" => "",
		        "dbname" => "phalcon_test"
		    ));

		    //Assign the eventsManager to the db adapter instance
		    $connection->setEventsManager($eventsManager);

		    return $connection;
		}, true);*/

		return $di;
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
		$this->assertEquals($page->limit, 3);

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

	public function testArrayPaginator_t445()
	{

		$paginator = new \Phalcon\Paginator\Adapter\NativeArray(array(
			"data" => array_fill(0, 30, 'banana'),
			"limit"=> 25,
			"page" => 1,
		));

		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 25);

		$this->assertEquals($page->before, 1);
		$this->assertEquals($page->next, 2);
		$this->assertEquals($page->last, 2);
		$this->assertEquals($page->limit, 25);

		$this->assertEquals($page->current, 1);
		$this->assertEquals($page->total_pages, 2);

		$paginator->setCurrentPage(2);

		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 5);

		$this->assertEquals($page->before, 1);
		$this->assertEquals($page->next, 2);
		$this->assertEquals($page->last, 2);

		$this->assertEquals($page->current, 2);
		$this->assertEquals($page->total_pages, 2);
	}

	public function testModelPaginator()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

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
		$this->assertEquals($page->limit, 10);

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
		$paginator->setCurrentPage(218);

		$page = $paginator->getPaginate();
		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 10);

		$this->assertEquals($page->before, 217);
		$this->assertEquals((int) $page->next, 218);
		$this->assertEquals($page->last, 218);

		$this->assertEquals($page->current, 218);
		$this->assertEquals($page->total_pages, 218);
	}

	public function testModelPaginatorBind()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

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
		$this->assertEquals($page->last, 4);
		$this->assertEquals($page->limit, 10);

		$this->assertEquals($page->current, 1);
		$this->assertEquals($page->total_pages, 4);
	}

	public function testQueryBuilderPaginator()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_loadDI();

		$builder = $di['modelsManager']->createBuilder()
					->columns('cedula, nombres')
					->from('Personnes')
					->orderBy('cedula');

		$paginator = new Phalcon\Paginator\Adapter\QueryBuilder(array(
			"builder" => $builder,
			"limit"=> 10,
			"page" => 1
		));

		$page = $paginator->getPaginate();

		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 10);

		$this->assertEquals($page->before, 1);
		$this->assertEquals($page->next, 2);
		$this->assertEquals($page->last, 218);
		$this->assertEquals($page->limit, 10);

		$this->assertEquals($page->current, 1);
		$this->assertEquals($page->total_pages, 218);

		$this->assertInternalType('int', $page->total_items);
		$this->assertInternalType('int', $page->total_pages);

		//Middle page
		$paginator->setCurrentPage(100);

		$page = $paginator->getPaginate();

		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 10);

		$this->assertEquals($page->before, 99);
		$this->assertEquals($page->next, 101);
		$this->assertEquals($page->last, 218);

		$this->assertEquals($page->current, 100);
		$this->assertEquals($page->total_pages, 218);

		$this->assertInternalType('int', $page->total_items);
		$this->assertInternalType('int', $page->total_pages);

		//Last page
		$paginator->setCurrentPage(218);

		$page = $paginator->getPaginate();

		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 10);

		$this->assertEquals($page->before, 217);
		$this->assertEquals($page->next, 218);
		$this->assertEquals($page->last, 218);

		$this->assertEquals($page->current, 218);
		$this->assertEquals($page->total_pages, 218);

		$this->assertInternalType('int', $page->total_items);
		$this->assertInternalType('int', $page->total_pages);

		// test of getter/setters of querybuilder adapter

        // -- current page --
		$currentPage = $paginator->getCurrentPage();
		$this->assertEquals($currentPage, 218);

		// -- limit --
		$rowsLimit = $paginator->getLimit();
		$this->assertEquals($rowsLimit, 10);

		$setterResult = $paginator->setLimit(25);
		$rowsLimit = $paginator->getLimit();
		$this->assertEquals($rowsLimit, 25);
		$this->assertEquals($setterResult, $paginator);

		// -- builder --
		$queryBuilder = $paginator->getQueryBuilder();
		$this->assertEquals($builder, $queryBuilder);

		$builder2 = $di['modelsManager']->createBuilder()
			->columns('cedula, nombres')
			->from('Personnes');

		$setterResult = $paginator->setQueryBuilder($builder2);
		$queryBuilder = $paginator->getQueryBuilder();
		$this->assertEquals($builder2, $queryBuilder);
		$this->assertEquals($setterResult, $paginator);
	}

}
