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

class PaginatorTest extends TestCase
{

	public function setUp()
	{
		spl_autoload_register(array($this, 'modelsAutoloader'));
	}

	public function tearDown()
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
		$this->assertEquals($page->total_items, 2180);
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

	public function testQueryBuilderPaginatorGroupBy()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$di = $this->_loadDI();
		$di['db']->query("SET SESSION sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION'");

		// test paginator with group by string value
		$builder = $di['modelsManager']->createBuilder()
					->columns('cedula, nombres')
					->from('Personnes')
					->groupBy('email');

		$this->_paginatorBuilderTest($builder);

		// test paginator with group by array value
		$builder = $di['modelsManager']->createBuilder()
					->columns('cedula, nombres')
					->from('Personnes')
					->groupBy(['email']);

		$this->_paginatorBuilderTest($builder);

		// test of getter/setters of querybuilder adapter

		$paginator = new Phalcon\Paginator\Adapter\QueryBuilder(array(
			"builder" => $builder,
			"limit"=> 10,
			"page" => 1
		));

		$paginator->setCurrentPage(18);

        // -- current page --
		$currentPage = $paginator->getCurrentPage();
		$this->assertEquals($currentPage, 18);

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
			->from('Personnes')
			->groupBy(['email']);

		$setterResult = $paginator->setQueryBuilder($builder2);
		$queryBuilder = $paginator->getQueryBuilder();
		$this->assertEquals($builder2, $queryBuilder);
		$this->assertEquals($setterResult, $paginator);
	}

	private function _paginatorBuilderTest($builder)
	{
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
		$this->assertEquals($page->last, 18);
		$this->assertEquals($page->limit, 10);

		$this->assertEquals($page->current, 1);
		$this->assertEquals($page->total_items, 178);
		$this->assertEquals($page->total_pages, 18);

		$this->assertInternalType('int', $page->total_items);
		$this->assertInternalType('int', $page->total_pages);

		//Middle page
		$paginator->setCurrentPage(10);

		$page = $paginator->getPaginate();

		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 10);

		$this->assertEquals($page->before, 9);
		$this->assertEquals($page->next, 11);
		$this->assertEquals($page->last, 18);

		$this->assertEquals($page->current, 10);
		$this->assertEquals($page->total_pages, 18);

		$this->assertInternalType('int', $page->total_items);
		$this->assertInternalType('int', $page->total_pages);

		//Last page
		$paginator->setCurrentPage(18);

		$page = $paginator->getPaginate();

		$this->assertEquals(get_class($page), 'stdClass');

		$this->assertEquals(count($page->items), 9);

		$this->assertEquals($page->before, 17);
		$this->assertEquals($page->next, 18);
		$this->assertEquals($page->last, 18);

		$this->assertEquals($page->current, 18);
		$this->assertEquals($page->total_pages, 18);

		$this->assertInternalType('int', $page->total_items);
		$this->assertInternalType('int', $page->total_pages);
	}
}
